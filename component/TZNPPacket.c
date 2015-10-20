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

#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\systemmenufnc.h"

#include "virtualMenu\viewMenuList.h"
#include "virtualMenu\viewmenusub.h"
#include "psuperVisor\psupervisor.h"

//код компонентов
#define KOD_COMPONENT  TZNP_COMP1
//к-во ступеней
#define CNT_STUPEN_TZNP  5

//массив клонов - конфигураци€
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента дл€ репозитари€
extern LineMenuItem sub_menu_cnf[];
extern char deleteComp[];

extern char TZNP1_TITLE[];
extern char TZNP2_TITLE[];
extern char TZNP3_TITLE[];
extern char TZNP4_TITLE[];
extern char TZNP5_TITLE[];

StreamControl controlStruct_TZNP;//управл структура

void MakePacketTZNP();
char copyTZNP1ToRepozitar(char packet);

char  *nameStupenTZNP[CNT_STUPEN_TZNP] = {TZNP1_TITLE,
                                          TZNP2_TITLE,
                                          TZNP3_TITLE,
                                          TZNP4_TITLE,
                                          TZNP5_TITLE
                                         };//указатели на имена ступеней

//меню
LineMenuItem sub_menu_TZNP[CNT_STUPEN_TZNP+4] =
{
  { "“«Ќѕ", NULL},//title
  { &controlStruct_TZNP, sub_menu_cnf},//control_item, parent
  { deleteComp, (void *)&DeleteComponent1, typeMenuProg},
  { NULL, NULL}
};

char copyTZNPpacketToRepozitar(char packet)
{
  rpzcomponent_obj.kodC    = KOD_COMPONENT; //код компонента
  rpzcomponent_obj.cntClon = CNT_STUPEN_TZNP;//к-во клонов

  if(packet)  return 1;//пакетна€ регистраци€
//найти в конфиг такой же пакет
  short dx=0;
  while(cnfCOMPONENT[dx].componentEnable)
  {
    //номер пакетного компонента
    if(cnfCOMPONENT[dx].packet==TZNP_PACKET) return 1;//пакетна€ регистраци€
    dx++;
  }//while

  MakeEmptyTopSub_menu(&(sub_menu_cnf[0]),
                       MAX_CNFCOMPONENT*sizeof(LineMenuItem));//добавить пустую запись в top sub_menu
//новый клон в список
  sub_menu_cnf[1+SUBDATA].Line2 = sub_menu_TZNP; //меню компонента
  sub_menu_cnf[1+SUBDATA].TypesWin = typeMenuSub;

  TxtStreamInit(&CONTROL_CNF, &KadrMenuFormat_sub, sub_menu_cnf);//инит control и формир кадра

//---------TZNP5------------------------------
  copyTZNP1ToRepozitar(0);//зарегистрировать в репозитарии
  rpzcomponent_obj.twinControl[3].twin_different();//diff to TZNP5
  rpzcomponent_obj.packet = TZNP_PACKET;    //номер пакетного компонента

  MakePacketTZNP();//создать пакет TZNP
//---------------------------------------------

//---------TZNP4------------------------------
  copyTZNP1ToRepozitar(0);//зарегистрировать в репозитарии
  rpzcomponent_obj.twinControl[2].twin_different();//diff to TZNP4
  rpzcomponent_obj.packet = TZNP_PACKET;    //номер пакетного компонента

  MakePacketTZNP();//создать пакет TZNP
//---------------------------------------------

//---------TZNP3------------------------------
  copyTZNP1ToRepozitar(0);//зарегистрировать в репозитарии
  rpzcomponent_obj.twinControl[1].twin_different();//diff to TZNP3
  rpzcomponent_obj.packet = TZNP_PACKET;    //номер пакетного компонента

  MakePacketTZNP();//создать пакет TZNP
//---------------------------------------------

//---------TZNP2------------------------------
  copyTZNP1ToRepozitar(0);//зарегистрировать в репозитарии TZNP2
  rpzcomponent_obj.twinControl[0].twin_different();//diff to TZNP2
  rpzcomponent_obj.packet = TZNP_PACKET;    //номер пакетного компонента
  MakePacketTZNP();//создать пакет TZNP
//---------------------------------------------


//---------TZNP1------------------------------
  copyTZNP1ToRepozitar(0);//зарегистрировать в репозитарии TZNP1

  rpzcomponent_obj.packet = -CNT_STUPEN_TZNP;    //к-во клонов в пакете
  //добавить им€ пакета
  strcat(rpzcomponent_obj.nameComponent, " “«Ќѕ");
  short ii=0;
  while(rpzcomponent_obj.nameComponent[ii]!=' ')
  {
    ii++;
  }
  rpzcomponent_obj.nameComponent[ii] = 0;

  MakePacketTZNP();//создать пакет

  //имена ступеней TZNP
  sub_menu_TZNP[1+SUBDATA].Line1         = nameStupenTZNP[0];//cnfCOMPONENT[dx-2].nameComponent;
  sub_menu_TZNP[1+1+SUBDATA].Line1       = nameStupenTZNP[1];//cnfCOMPONENT[dx-1].nameComponent;
  sub_menu_TZNP[1+1+1+SUBDATA].Line1     = nameStupenTZNP[2];//cnfCOMPONENT[dx].nameComponent;
  sub_menu_TZNP[1+1+1+1+SUBDATA].Line1   = nameStupenTZNP[3];//cnfCOMPONENT[dx].nameComponent;
  sub_menu_TZNP[1+1+1+1+1+SUBDATA].Line1 = nameStupenTZNP[4];//cnfCOMPONENT[dx].nameComponent;

//---------------------------------------------
  return 1;//пакетна€ регистраци€
}//copyTZNPpacketToRepozitar()

void MakePacketTZNP()
{
//создать пакет
//копировать в тень
  memcpy((void*)getShadowBuf(), cnfCOMPONENT, sizeof(COMPONENT_OBJ)*MAX_CNFCOMPONENT);

  memcpy(&(cnfCOMPONENT[0]), &rpzcomponent_obj, sizeof(COMPONENT_OBJ));

//копировать из тени
  memcpy(&(cnfCOMPONENT[1]), (void*)getShadowBuf(), sizeof(COMPONENT_OBJ)*(MAX_CNFCOMPONENT-1));

  MakeEmptyTopSub_menu(&(sub_menu_TZNP[0]), sizeof(sub_menu_TZNP));//добавить пустую запись в top sub_menu
//новый клон в список
  sub_menu_TZNP[1+SUBDATA].Line2 = (void *)&OpenMenuComponent; //меню компонента
  sub_menu_TZNP[1+SUBDATA].TypesWin = typeMenuProg;

  TxtStreamInit(&controlStruct_TZNP, &KadrMenuFormat_sub, sub_menu_TZNP);//инит control и формир кадра
//инициализировать обекты в конфигурации
  initCOMPONENT(INITUST_TOPCOMP);
}//MakePacket()


