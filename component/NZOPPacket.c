/*
#include <vcl.h>
#include <strstrea.h>
#include <math.h>
#include <mem.h>
#include <fstream.h>
#include <strstrea.h>
#include <iomanip.h>
#pragma hdrstop

#include "vmenuDis.h"
*/

#include <stdio.h>
#include <string.h>

#include "psuperVisor\supermanager.h"

#include "bazisdef.h"
#include "component\componentdef.h"
#include "virtualMenu\systemmenudef.h"
#include "virtualMenu\ustmanagerdef.h"
#include "psuperVisor\psvisor_helpdef.h"

#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\systemmenufnc.h"

#include "virtualMenu\viewMenuList.h"
#include "virtualMenu\viewmenusub.h"
#include "psuperVisor\psupervisor.h"


//код компонентов
#define KOD_COMPONENT  NZOP_COMP1
//к-во ступеней
#define CNT_STUPEN_NZOP  2

//массив клонов - конфигурация
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern LineMenuItem sub_menu_cnf[];
extern char deleteComp[];

extern char NZOP1_TITLE[];
extern char NZOP2_TITLE[];

StreamControl controlStruct_NZOP;//управл структура

void MakePacketNZOP();
char copyNZOP1ToRepozitar(char packet);
char copyNZOP2ToRepozitar(char packet);

char  *nameStupenNZOP[CNT_STUPEN_NZOP] = {NZOP1_TITLE,
                                          NZOP2_TITLE
                                         };//указатели на имена ступеней

//меню NZOP
LineMenuItem sub_menu_NZOP[CNT_STUPEN_NZOP+4] =
{
  { "НЗОП", NULL},//title
  { &controlStruct_NZOP, sub_menu_cnf},//control_item, parent
  { deleteComp, (void *)&DeleteComponent1, typeMenuProg},
  { NULL, NULL}
};

char copyNZOPpacketToRepozitar(char packet)
{
  rpzcomponent_obj.kodC   = KOD_COMPONENT; //код компонента
  rpzcomponent_obj.cntClon = CNT_STUPEN_NZOP;//к-во клонов

  if(packet)  return 1;//пакетная регистрация
//найти в конфиг такой же пакет
  short dx=0;
  while(cnfCOMPONENT[dx].componentEnable)
  {
    //номер пакетного компонента
    if(cnfCOMPONENT[dx].packet==NZOP_PACKET) return 1;//пакетная регистрация
    dx++;
  }//while

  MakeEmptyTopSub_menu(&(sub_menu_cnf[0]),
                       MAX_CNFCOMPONENT*sizeof(LineMenuItem));//добавить пустую запись в top sub_menu
//новый клон в список
  sub_menu_cnf[1+SUBDATA].Line2 = sub_menu_NZOP; //меню компонента
  sub_menu_cnf[1+SUBDATA].TypesWin = typeMenuSub;

  TxtStreamInit(&CONTROL_CNF,   &KadrMenuFormat_sub, sub_menu_cnf);//инит control и формир кадра

//---------NZOP2------------------------------
  copyNZOP1ToRepozitar(0);//зарегистрировать в репозитарии
  rpzcomponent_obj.twinControl[0].twin_different();//diff to NZOP2
  rpzcomponent_obj.packet = NZOP_PACKET;    //номер пакетного компонента

  MakePacketNZOP();//создать пакет NZOP

//---------NZOP1------------------------------
  copyNZOP1ToRepozitar(0);//зарегистрировать в репозитарии NZOP1
  rpzcomponent_obj.packet = -CNT_STUPEN_NZOP;    //к-во клонов в пакете
  //добавить имя пакета
  strcat(rpzcomponent_obj.nameComponent, " НЗОП");
  short ii=0;
  while(rpzcomponent_obj.nameComponent[ii]!=' ')
  {
    ii++;
  }
  rpzcomponent_obj.nameComponent[ii] = 0;

  MakePacketNZOP();//создать пакет NZOP

  //имена ступеней NZOP
  sub_menu_NZOP[1+SUBDATA].Line1     = nameStupenNZOP[0];
  sub_menu_NZOP[1+1+SUBDATA].Line1   = nameStupenNZOP[1];

  return 1;//пакетная регистрация
}//copyNZOPpacketToRepozitar()

void MakePacketNZOP()
{
//создать пакет
//копировать в тень
  memcpy((void*)getShadowBuf(), cnfCOMPONENT, sizeof(COMPONENT_OBJ)*MAX_CNFCOMPONENT);

  memcpy(&(cnfCOMPONENT[0]), &rpzcomponent_obj, sizeof(COMPONENT_OBJ));

//копировать из тени
  memcpy(&(cnfCOMPONENT[1]), (void*)getShadowBuf(), sizeof(COMPONENT_OBJ)*(MAX_CNFCOMPONENT-1));

  MakeEmptyTopSub_menu(&(sub_menu_NZOP[0]), sizeof(sub_menu_NZOP));//добавить пустую запись в top sub_menu
//новый клон в список
  sub_menu_NZOP[1+SUBDATA].Line2 = (void *)&OpenMenuComponent; //меню компонента
  sub_menu_NZOP[1+SUBDATA].TypesWin = typeMenuProg;

  TxtStreamInit(&controlStruct_NZOP, &KadrMenuFormat_sub, sub_menu_NZOP);//инит control и формир кадра
//инициализировать обекты в конфигурации
  initCOMPONENT(INITUST_TOPCOMP);
}//MakePacket()


