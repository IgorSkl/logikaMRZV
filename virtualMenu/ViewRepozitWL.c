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

#include "bazisdef.h"
#include "psuperVisor\supermanager.h"
#include "virtualMenu\systemmenudef.h"
#include "component\componentdef.h"
#include "virtualMenu\repozitdef.h"

#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\repozitfnc.h"

#include "virtualMenu\viewMenuCnf.h"
#include "virtualMenu\viewMenuSub.h"
#include "virtualMenu\viewMenuWideLog.h"

#include "..\bazis.h"

extern LineMenuItem sub_menu_cnfwl[];

extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария

char copyOFToRepozitar(char packet);
char copyPFToRepozitar(char packet);

//доступные компоненты
LineMenuItem sub_menu_rpzWL[MAX_WLCOMPONENT+3] =
{
  { "Репозитарий РЛ", NULL},//title
  { NULL, NULL}
};


//репозитарий компонентов РЛ
ELEMENT_RPZ  rpzCOMPONENT_WL[] =
{

  {
    //OF
    1,
    &copyOFToRepozitar,
    {OF_COMP1}
  },

  {
    //PF
    1,
    &copyPFToRepozitar,
    {PF_COMP1}
  },

  {
    //NULL
    0
  }
};

void  RpzComponentWL()
{
//доступные компоненты
//допустить все компоненты
  short i=0;
  while(rpzCOMPONENT_WL[i].componentEnable)
  {
    rpzCOMPONENT_WL[i].componentPermission = 1;//компонент допущен
    i++;
  }//while

//допуск по к-ву клонов
  i=0;
  short kC;         //код компонента
  short cntC;//к-во клонов компонента
  while(rpzCOMPONENT_WL[i].componentEnable)
  {
    rpzCOMPONENT_WL[i].load2RPZ(1);//заглянуть в репозитарий
    kC = rpzcomponent_obj.kodC;         //код компонента
//искать в cnf к-во клонов данного компонента
    cntC = SearchCnfClonComponent(kC);
    if(cntC>=rpzcomponent_obj.cntClon)
      rpzCOMPONENT_WL[i].componentPermission = 0;//нет допуска
    i++;
  }//while

//отобразить только допущенные компоненты
//обзор репозитария
  short rpzI=0;
  short mnI=0;
  while(rpzCOMPONENT_WL[rpzI].componentEnable)
  {
    if(rpzCOMPONENT_WL[rpzI].load2RPZ(1));//заглянуть в репозитарий
    else strcpy(rpzCOMPONENT_WL[rpzI].rpzKodName.rpzNameComponent, rpzcomponent_obj.nameComponent);

      sub_menu_rpzWL[mnI+1+SUBDATA].Line1 = rpzCOMPONENT_WL[rpzI].rpzKodName.rpzNameComponent;//name
      sub_menu_rpzWL[mnI+1+SUBDATA].Line2 = (void *)&ConfigMakerWL;//добавить в конфиг РЛ
      sub_menu_rpzWL[mnI+1+SUBDATA].TypesWin = typeMenuProg;
      mnI++;

    rpzI++;
  }//while

  sub_menu_rpzWL[mnI+1+SUBDATA].Line1 = NULL;
  sub_menu_rpzWL[mnI+1+SUBDATA].Line2 = NULL;

  sub_menu_rpzWL[SUBDATA].Line1 = &CONTROL_RPZ;//control
  sub_menu_rpzWL[SUBDATA].Line2 = sub_menu_cnfwl;//parent
  sub_menu_rpzWL[SUBDATA].TypesWin = typeMenuSub;

//  CRR_SUBMENU = sub_menu_rpzWL;//текущее субменю
  SelectorSUBMENU(sub_menu_rpzWL);//уcтановить текущее субменю

//  CRR_TEXTSTREAM = &CONTROL_RPZ;//текущий control
  SelectorTEXTCONTROL(&CONTROL_RPZ);//установить текущую ссылку на текстовый поток

  PereinitRpzWL(1);//переиниц
//  CRR_FHOME = &PereinitRpzWL;//указатель на ф-цию HOME
  SelectorFHOME(&PereinitRpzWL);//указатель на ф-цию HOME

}//RpzComponentWL()

void PereinitRpzWL(short flg)
{
//переиниц
  TxtStreamInit(&CONTROL_RPZ, &KadrMenuFormat_sub, sub_menu_rpzWL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL_RPZ, SIZE_PAGE_VIEW);//перейти на END
  }//if
  ViewDiskrMenu(typeMenuSub);//вывести окно отображения
  LanderPStr();//размещение указателя строки
}//PereinitRpzWL()

short GetOffsetClonRpzWL(short numK)
{
//получить смещение репозитария по коду компонента
  short i=0;
  while(rpzCOMPONENT_WL[i].componentEnable)
  {
    if(rpzCOMPONENT_WL[i].rpzKodName.kodC==numK)
      return i;
    i++;
  }//while
  return 0;
}//GetOffsetClonRpzWL(short numK)



