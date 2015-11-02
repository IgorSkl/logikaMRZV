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
#define KOD_COMPONENT  MTZ_COMP1
//к-во ступеней
#define CNT_STUPEN_MTZ  5

//массив клонов - конфигураци€
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента дл€ репозитари€
extern LineMenuItem sub_menu_cnf[];
extern char deleteComp[];

extern char MTZ1_TITLE[];
extern char MTZ2_TITLE[];
extern char MTZ3_TITLE[];
extern char MTZ4_TITLE[];
extern char MTZ5_TITLE[];

StreamControl controlStruct_MTZ;//управл структура

void MakePacketMTZ();
char copyMTZ1ToRepozitar(char packet);
char copyMTZ2ToRepozitar(char packet);

char  *nameStupenMTZ[CNT_STUPEN_MTZ] = {MTZ1_TITLE,
                                        MTZ2_TITLE,
                                        MTZ3_TITLE,
                                        MTZ4_TITLE,
                                        MTZ5_TITLE
                                       };//указатели на имена ступеней

//меню MTZ
LineMenuItem sub_menu_MTZ[CNT_STUPEN_MTZ+4] =
{
  { "ћ“«", NULL},//title
  { &controlStruct_MTZ, sub_menu_cnf},//control_item, parent
  { deleteComp, (void *)&DeleteComponent1, typeMenuProg},
  { NULL, NULL}
};

char copyMTZpacketToRepozitar(char packet)
{
  rpzcomponent_obj.kodC    = KOD_COMPONENT; //код компонента
  rpzcomponent_obj.cntClon = CNT_STUPEN_MTZ;//к-во клонов

  if(packet)  return 1;//пакетна€ регистраци€
//найти в конфиг такой же пакет
  short dx=0;
  while(cnfCOMPONENT[dx].componentEnable)
  {
    //номер пакетного компонента
    if(cnfCOMPONENT[dx].packet==MTZ_PACKET) return 1;//пакетна€ регистраци€
    dx++;
  }//while

  MakeEmptyTopSub_menu(&(sub_menu_cnf[0]),
                       MAX_CNFCOMPONENT*sizeof(LineMenuItem));//добавить пустую запись в top sub_menu
//новый клон в список
  sub_menu_cnf[1+SUBDATA].Line2 = sub_menu_MTZ; //меню компонента
  sub_menu_cnf[1+SUBDATA].TypesWin = typeMenuSub;

  TxtStreamInit(&CONTROL_CNF,   &KadrMenuFormat_sub, sub_menu_cnf);//инит control и формир кадра

//---------MTZ5------------------------------
  copyMTZ2ToRepozitar(0);//зарегистрировать в репозитарии
  rpzcomponent_obj.twinControl[2].twin_different();//diff to MTZ5
  rpzcomponent_obj.packet = MTZ_PACKET;    //номер пакетного компонента

  MakePacketMTZ();//создать пакет MTZ
//---------------------------------------------

//---------MTZ4------------------------------
  copyMTZ2ToRepozitar(0);//зарегистрировать в репозитарии
  rpzcomponent_obj.twinControl[1].twin_different();//diff to MTZ4
  rpzcomponent_obj.packet = MTZ_PACKET;    //номер пакетного компонента

  MakePacketMTZ();//создать пакет MTZ
//---------------------------------------------

//---------MTZ3------------------------------
  copyMTZ2ToRepozitar(0);//зарегистрировать в репозитарии
  rpzcomponent_obj.twinControl[0].twin_different();//diff to MTZ3
  rpzcomponent_obj.packet = MTZ_PACKET;    //номер пакетного компонента

  MakePacketMTZ();//создать пакет MTZ
//---------------------------------------------

//---------MTZ2------------------------------
  copyMTZ2ToRepozitar(0);//зарегистрировать в репозитарии MTZ2
  rpzcomponent_obj.packet = MTZ_PACKET;    //номер пакетного компонента
  MakePacketMTZ();//создать пакет MTZ
//---------------------------------------------


//---------MTZ1------------------------------
  copyMTZ1ToRepozitar(0);//зарегистрировать в репозитарии MTZ1

  rpzcomponent_obj.packet = -CNT_STUPEN_MTZ;    //к-во клонов в пакете
  //добавить им€ пакета
  strcat(rpzcomponent_obj.nameComponent, " ћ“«");
  short ii=0;
  while(rpzcomponent_obj.nameComponent[ii]!=' ')
  {
    ii++;
  }
  rpzcomponent_obj.nameComponent[ii] = 0;

  MakePacketMTZ();//создать пакет MTZ

  //имена ступеней ћ“«
  sub_menu_MTZ[1+SUBDATA].Line1         = nameStupenMTZ[0];
  sub_menu_MTZ[1+1+SUBDATA].Line1       = nameStupenMTZ[1];
  sub_menu_MTZ[1+1+1+SUBDATA].Line1     = nameStupenMTZ[2];
  sub_menu_MTZ[1+1+1+1+SUBDATA].Line1   = nameStupenMTZ[3];
  sub_menu_MTZ[1+1+1+1+1+SUBDATA].Line1 = nameStupenMTZ[4];

//---------------------------------------------
  return 1;//пакетна€ регистраци€
}//copyMTZpacketToRepozitar()

void MakePacketMTZ()
{
//создать пакет
//копировать в тень
  memcpy((void*)getShadowBuf(), cnfCOMPONENT, sizeof(COMPONENT_OBJ)*MAX_CNFCOMPONENT);

  memcpy(&(cnfCOMPONENT[0]), &rpzcomponent_obj, sizeof(COMPONENT_OBJ));

//копировать из тени
  memcpy(&(cnfCOMPONENT[1]), (void*)getShadowBuf(), sizeof(COMPONENT_OBJ)*(MAX_CNFCOMPONENT-1));


  MakeEmptyTopSub_menu(&(sub_menu_MTZ[0]), sizeof(sub_menu_MTZ));//добавить пустую запись в top sub_menu
//новый клон в список
  sub_menu_MTZ[1+SUBDATA].Line2 = (void *)&OpenMenuComponent; //меню компонента
  sub_menu_MTZ[1+SUBDATA].TypesWin = typeMenuProg;

  TxtStreamInit(&controlStruct_MTZ, &KadrMenuFormat_sub, sub_menu_MTZ);//инит control и формир кадра
//инициализировать обекты в конфигурации
  initCOMPONENT(INITUST_TOPCOMP);

}//MakePacket()


