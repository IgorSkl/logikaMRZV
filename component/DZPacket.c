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
#include "virtualMenu\textstreamdef.h"
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
#define KOD_COMPONENT  DZ_COMP1
//к-во ступеней
#define CNT_STUPEN_DZ  5

//массив клонов - конфигурация
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern LineMenuItem sub_menu_cnf[];
extern char deleteComp[];

extern char DZ1_TITLE[];
extern char DZ2_TITLE[];
extern char DZ3_TITLE[];
extern char DZ4_TITLE[];
extern char DZ5_TITLE[];

StreamControl controlStruct_DZ;//управл структура

void MakePacketDZ();
char copyDZ1ToRepozitar(char packet);
char copyDZ2ToRepozitar(char packet);

char  *nameStupenDZ[CNT_STUPEN_DZ] = {DZ1_TITLE,
                                      DZ2_TITLE,
                                      DZ3_TITLE,
                                      DZ4_TITLE,
                                      DZ5_TITLE
                                     };//указатели на имена ступеней
//меню DZ
LineMenuItem sub_menu_DZ[CNT_STUPEN_DZ+4] =
{
  { "ДЗ", NULL},//title
  { &controlStruct_DZ, sub_menu_cnf},//control_item, parent
  { deleteComp, (void *)&DeleteComponent1, typeMenuProg},
  { NULL, NULL}
};

char copyDZpacketToRepozitar(char packet)
{
  rpzcomponent_obj.kodC    = KOD_COMPONENT; //код компонента
  rpzcomponent_obj.cntClon = CNT_STUPEN_DZ;//к-во клонов

  if(packet)  return 1;//пакетная регистрация
//найти в конфиг такой же пакет
  short dx=0;
  while(cnfCOMPONENT[dx].componentEnable)
  {
    //номер пакетного компонента
    if(cnfCOMPONENT[dx].packet==DZ_PACKET) return 1;//пакетная регистрация
    dx++;
  }//while

  MakeEmptyTopSub_menu(&(sub_menu_cnf[0]),
                       MAX_CNFCOMPONENT*sizeof(LineMenuItem));//добавить пустую запись в top sub_menu
//новый клон в список
  sub_menu_cnf[1+SUBDATA].Line2 = sub_menu_DZ; //меню компонента
  sub_menu_cnf[1+SUBDATA].TypesWin = typeMenuSub;

  TxtStreamInit(&CONTROL_CNF, &KadrMenuFormat_sub, sub_menu_cnf);//инит control и формир кадра

//---------DZ5------------------------------
  copyDZ2ToRepozitar(0);//зарегистрировать в репозитарии
  rpzcomponent_obj.twinControl[2].twin_different();//diff to DZ4
  rpzcomponent_obj.packet = DZ_PACKET;    //номер пакетного компонента

  MakePacketDZ();//создать DZ5
//---------------------------------------------

//---------DZ4------------------------------
  copyDZ2ToRepozitar(0);//зарегистрировать в репозитарии
  rpzcomponent_obj.twinControl[1].twin_different();//diff to DZ4
  rpzcomponent_obj.packet = DZ_PACKET;    //номер пакетного компонента

  MakePacketDZ();//создать DZ4
//---------------------------------------------

//---------DZ3------------------------------
  copyDZ2ToRepozitar(0);//зарегистрировать в репозитарии
  rpzcomponent_obj.twinControl[0].twin_different();//diff to DZ3
  rpzcomponent_obj.packet = DZ_PACKET;    //номер пакетного компонента

  MakePacketDZ();//создать DZ3
//---------------------------------------------

//---------DZ2------------------------------
  copyDZ2ToRepozitar(0);//зарегистрировать в репозитарии DZ2
  rpzcomponent_obj.packet = DZ_PACKET;    //номер пакетного компонента
  MakePacketDZ();//создать DZ2
//---------------------------------------------


//---------DZ1------------------------------
  copyDZ1ToRepozitar(0);//зарегистрировать в репозитарии DZ1

  rpzcomponent_obj.packet = -CNT_STUPEN_DZ;    //к-во клонов в пакете
  //добавить имя пакета
  strcat(rpzcomponent_obj.nameComponent, " ДЗ");
  short ii=0;
  while(rpzcomponent_obj.nameComponent[ii]!=' ')
  {
    ii++;
  }
  rpzcomponent_obj.nameComponent[ii] = 0;

  MakePacketDZ();//создать DZ1


  //имена ступеней DZ
  sub_menu_DZ[1+SUBDATA].Line1         = nameStupenDZ[0];
  sub_menu_DZ[1+1+SUBDATA].Line1       = nameStupenDZ[1];
  sub_menu_DZ[1+1+1+SUBDATA].Line1     = nameStupenDZ[2];
  sub_menu_DZ[1+1+1+1+SUBDATA].Line1   = nameStupenDZ[3];
  sub_menu_DZ[1+1+1+1+1+SUBDATA].Line1 = nameStupenDZ[4];

//---------------------------------------------
  return 1;//пакетная регистрация
}//copyDZpacketToRepozitar()

void MakePacketDZ()
{
//создать пакет
//копировать в тень
  memcpy((void*)getShadowBuf(), cnfCOMPONENT, sizeof(COMPONENT_OBJ)*MAX_CNFCOMPONENT);

  memcpy(&(cnfCOMPONENT[0]), &rpzcomponent_obj, sizeof(COMPONENT_OBJ));

//копировать из тени
  memcpy(&(cnfCOMPONENT[1]), (void*)getShadowBuf(), sizeof(COMPONENT_OBJ)*(MAX_CNFCOMPONENT-1));

  MakeEmptyTopSub_menu(&(sub_menu_DZ[0]), sizeof(sub_menu_DZ));//добавить пустую запись в top sub_menu
//новый клон в список
  sub_menu_DZ[1+SUBDATA].Line2 = (void *)&OpenMenuComponent; //меню компонента
  sub_menu_DZ[1+SUBDATA].TypesWin = typeMenuProg;

  TxtStreamInit(&controlStruct_DZ, &KadrMenuFormat_sub, sub_menu_DZ);//инит control и формир кадра
//инициализировать обекты в конфигурации
  initCOMPONENT(INITUST_TOPCOMP);
}//MakePacket()


