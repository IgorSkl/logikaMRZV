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

#include "logictimers\logictimersfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\ustmanagerfnc.h"

#include "virtualMenu\viewMenuCnf.h"

#include "..\bazis.h"

extern LineMenuItem sub_menu_cnf[];

COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария

char copyMTZpacketToRepozitar(char packet);
char copyDZpacketToRepozitar(char packet);
char copyTZNPpacketToRepozitar(char packet);
char copyNZOPpacketToRepozitar(char packet);
char copyUROVToRepozitar(char packet);
char copyUMMToRepozitar(char packet);
char copyAPVToRepozitar(char packet);
char copyOFToRepozitar(char packet);
char copyPRM1ToRepozitar(char packet);
char copyWLToRepozitar(char packet);
char copyPFToRepozitar(char packet);

//доступные компоненты
LineMenuItem sub_menu_rpz[MAX_CNFCOMPONENT+3] =
{
  { "Репозитарий", NULL},//title
  { NULL, NULL}
};


//репозитарий компонентов
ELEMENT_RPZ  rpzCOMPONENT[] =
{
  {
    //MTZ packet
    1,
    &copyMTZpacketToRepozitar,
    {MTZ_COMP1, "МТЗ"}
  },

  {
    //DZ packet
    1,
    &copyDZpacketToRepozitar,
    {DZ_COMP1, "ДЗ"}
  },

  {
    //TZNP packet
    1,
    &copyTZNPpacketToRepozitar,
    {TZNP_COMP1, "ТЗНП"}
  },

  {
    //NZOP packet
    1,
    &copyNZOPpacketToRepozitar,
    {NZOP_COMP1, "НЗОП"}
  },

  {
    //UMM
    1,
    &copyUMMToRepozitar,
    {UMM_COMP1}
  },

  {
    //UROV
    1,
    &copyUROVToRepozitar,
    {UROV_COMP1}
  },

  {
    //APV
    1,
    &copyAPVToRepozitar,
    {APV_COMP1}
  },

  {
    //OF
    1,
    &copyOFToRepozitar,
    {OF_COMP1}
  },

  {
    //PRM1
    1,
    &copyPRM1ToRepozitar,
    {PRM1_COMP1}
  },

  {
    //WL
    1,
    &copyWLToRepozitar,
    {WL_COMP1}
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

void  RpzComponent()
{
//доступные компоненты
//допустить все компоненты
  short i=0;
  while(rpzCOMPONENT[i].componentEnable)
  {
    rpzCOMPONENT[i].componentPermission = 1;//компонент допущен
    i++;
  }//while
//допуск по к-ву клонов
  i=0;
  short kC;         //код компонента
  short cntC;//к-во клонов компонента
  while(rpzCOMPONENT[i].componentEnable)
  {
    rpzCOMPONENT[i].load2RPZ(1);//заглянуть в репозитарий
    kC = rpzcomponent_obj.kodC;         //код компонента
//искать в cnf к-во клонов данного компонента
    cntC = SearchCnfClonComponent(kC);
    if(cntC>=rpzcomponent_obj.cntClon)
      rpzCOMPONENT[i].componentPermission = 0;//нет допуска
    i++;
  }//while

//отобразить только допущенные компоненты
//обзор репозитария
  short rpzI=0;
  short mnI=0;
  while(rpzCOMPONENT[rpzI].componentEnable)
  {
    if(rpzCOMPONENT[rpzI].load2RPZ(1));//заглянуть в репозитарий
    else strcpy(rpzCOMPONENT[rpzI].rpzKodName.rpzNameComponent, rpzcomponent_obj.nameComponent);

    if(rpzCOMPONENT[rpzI].componentPermission)//есть допуск
    {
      sub_menu_rpz[mnI+1+SUBDATA].Line1 = rpzCOMPONENT[rpzI].rpzKodName.rpzNameComponent;//name
      sub_menu_rpz[mnI+1+SUBDATA].Line2 = (void *)&ConfigMaker;
      sub_menu_rpz[mnI+1+SUBDATA].TypesWin = typeMenuProg;
      mnI++;
    }//if
    rpzI++;
  }//while

  sub_menu_rpz[mnI+1+SUBDATA].Line1 = NULL;
  sub_menu_rpz[mnI+1+SUBDATA].Line2 = NULL;

  sub_menu_rpz[SUBDATA].Line1 = &CONTROL_RPZ;//control
  sub_menu_rpz[SUBDATA].Line2 = sub_menu_cnf;//parent
  sub_menu_rpz[SUBDATA].TypesWin = typeMenuSub;

//  CRR_SUBMENU = sub_menu_rpz;//текущее субменю
  SelectorSUBMENU(sub_menu_rpz);//уcтановить текущее субменю

//  CRR_TEXTSTREAM = &CONTROL_RPZ;//текущий control
  SelectorTEXTCONTROL(&CONTROL_RPZ);//установить текущую ссылку на текстовый поток

  PereinitAvaitCnf(1);//переиниц
//  CRR_FHOME = &PereinitAvaitCnf;//указатель на ф-цию HOME
  SelectorFHOME(&PereinitAvaitCnf);//указатель на ф-цию HOME

}//RpzComponent()

short GetKodCompRpz(short numL)
{
//получить из номера строки репозитария код компонента
  char ltxt[50];
  strcpy(ltxt, (char *)sub_menu_rpz[numL+1+SUBDATA].Line1);
  //мл и ст части кода компонента
  char lowK = ((char *)(sub_menu_rpz[numL+1+SUBDATA].Line1))[-2];
  char hiK = ((char *)(sub_menu_rpz[numL+1+SUBDATA].Line1))[-1];
  return lowK + 256*hiK;
}//GetKodCompRpz(short numL)

short GetOffsetClonRpz(short numK)
{
//получить смещение репозитария по коду компонента
  short i=0;
  while(rpzCOMPONENT[i].componentEnable)
  {
    if(rpzCOMPONENT[i].rpzKodName.kodC==numK)
      return i;
    i++;
  }//while
  return 0;
}//GetOffsetClonRpz(short numK)



