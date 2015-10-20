#ifndef _HIDE_COMPONENT
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
#include "component\componentdef.h"
#include "virtualMenu\systemmenudef.h"
#include "virtualMenu\ustmanagerdef.h"
#include "psuperVisor\psvisor_helpdef.h"

#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"
#include "virtualMenu\rangmanagerfnc.h"

#include "virtualMenu\viewMenuList.h"

#include "..\bazis.h"

#include "zonaVRT\zonaVRTdef.h"
#include "zonaVRT\zonaVRTfnc.h"


//код компонентов
#define KOD_COMPONENT  DZ_COMP1
//к-во ступеней
#define CNT_STUPEN_DZ  5

#endif // _HIDE_COMPONENT

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "DZ2Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_DZ[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//индекс уставок в супервизоре

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//текущие уставки супервизора

void PereinitUstListCompDZ3(short flg);
void UstListCompDZ3();
void ustRedactorCompDZ3();
void UstCompDZ3();

void PereinitVidListCompDZ3(short flg);
void VidListCompDZ3();
void vidRedactorCompDZ3();
void VidCompDZ3();

void PereinitUprListCompDZ3(short flg);
void UprListCompDZ3();
void uprRedactorCompDZ3();
void UprCompDZ3();
short  KadrMenuFormat_upr_compDZ3(void *workCntr);
int  initUstDZ3(char init);
void  prepareUstDZ2(short idxC);
void  prepareUstDZ3(short idxC);
short  KadrMenuFormat_ustvidDZ(void *workCntr);
char *selectorUprStrDZ2(short iBit, UNS_32 ustUpr);

//int ViewerEditUstDZ3();
//int ViewerEditVidDZ3();
void EditUprDZ3();
void EditVidDZ3();
void EditUstDZ3();
int codecUstDZ3(char codec, short offset, int ust);
int codecUstDZ2(char codec, short offset, int ust);
int initUstDZ2(char init);

char DZ3_TITLE[] = "ДЗ3";

IONAMESTATUS_COMPONENT ionsDZ3[IOCMD_DZ2to5_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок ДЗ3"
  },
  {
    1,//статус iocmd2
    "Блок уск ДЗ3"
  },
  {
    1,//статус iocmd3
    "Операт уск ДЗ3"
  },
  {
    1,//статус iocmd4
    "Сраб ПО ДЗ3МФ"
  },
  {
    1,//статус iocmd5
    "Сраб ДЗ3МФ"
  },
  {
    1,//статус iocmd6
    "Сраб ПО МТЗ ДЗ3МФ"
  },
  {
    1,//статус iocmd7
    "Сраб МТЗ ДЗ3МФ"
  },
  {
    1,//статус iocmd8
    "Сраб ПО ДЗ3ОФ"
  },
  {
    1,//статус iocmd9
    "Сраб ДЗ3ОФ"
  },
  {
    1,//статус iocmd10
    "Теле уск ДЗ3"
  }
};

LineMenuItem sub_menu_comp_DZ3[8] =
{
  { DZ3_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_DZ, typeMenuSub},//control_item, parent
  { "Уставки ДЗ3",     (void *)&UstListCompDZ3, typeMenuProg},
  { "Выдержки ДЗ3",    (void *)&VidListCompDZ3, typeMenuProg},
  { "Управление ДЗ3",  (void *)&UprListCompDZ3, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compDZ3[] =
{
  { "Уставки ДЗ3", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ3, typeMenuList},//control_item, parent
  { "Уст ДЗ3",        (void *)&UstCompDZ3, typeMenuProg},
  { "Уст ДЗ3 вперед", (void *)&UstCompDZ3, typeMenuProg},
  { "Уст ДЗ3 назад",  (void *)&UstCompDZ3, typeMenuProg},
  { "Уст ДЗ3 ПМ",     (void *)&UstCompDZ3, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compDZ3[] =
{
  { "Выдержки ДЗ3", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ3, typeMenuList},//control_item, parent
/*
  { "Выдержка ДЗ3МФ",       (void*)&VidCompDZ3, typeMenuProg},
  { "Выдержка МТЗ ДЗ3МФ",   (void*)&VidCompDZ3, typeMenuProg},
  { "Выдержка ДЗ3ОФ",       (void*)&VidCompDZ3, typeMenuProg},
  { "Ввод ускор ДЗ3МФ",     (void*)&VidCompDZ3, typeMenuProg},
  { "Ввод ускор МТЗ ДЗ3МФ", (void*)&VidCompDZ3, typeMenuProg},

  { "Ускор ДЗ3МФ ВВ",       (void*)&VidCompDZ3, typeMenuProg},
  { "Ускор ДЗ3МФ ОУ",       (void*)&VidCompDZ3, typeMenuProg},
  { "Ускор ДЗ3МФ ТУ",       (void*)&VidCompDZ3, typeMenuProg},

  { "Ускор МТЗ ДЗ3МФ ВВ",   (void*)&VidCompDZ3, typeMenuProg},
  { "Ускор МТЗ ДЗ3МФ ОУ",   (void*)&VidCompDZ3, typeMenuProg},
  { "Ускор МТЗ ДЗ3МФ ТУ",   (void*)&VidCompDZ3, typeMenuProg},

  { "Ускор ДЗ3ОФ ВВ",       (void*)&VidCompDZ3, typeMenuProg},
  { "Ускор ДЗ3ОФ ОУ",       (void*)&VidCompDZ3, typeMenuProg},
  { "Ускор ДЗ3ОФ ТУ",       (void*)&VidCompDZ3, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compDZ3[] =
{
  { "Управл ДЗ3", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ3, typeMenuList},//control_item, parent
/*  
  { "Управл ДЗ3",        (void *)&UprCompDZ3, typeMenuProg},
  { "Управл МТЗ ДЗ3",    (void *)&UprCompDZ3, typeMenuProg},
  { "Ускор ВВ ДЗ3",      (void *)&UprCompDZ3, typeMenuProg},
  { "Автомат уск ДЗ3",   (void *)&UprCompDZ3, typeMenuProg},
  { "Телеускор ДЗ3",     (void *)&UprCompDZ3, typeMenuProg},
*/  
  { NULL, NULL}

};

void PereinitUstListCompDZ3(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidDZ, sub_menu_ust_compDZ3);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp3()

void UstListCompDZ3()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compDZ3);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompDZ3);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompDZ3()

void UstCompDZ3()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compDZ3);
  PassWord(EditUstDZ3);
}//VidCompDZ3()

void EditUstDZ3()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compDZ3);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompDZ3()

//--------------------------------------------------

void PereinitVidListCompDZ3(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidDZ, sub_menu_vid_compDZ3);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitVidListCompDZ3(short flg)

void VidListCompDZ3()
{
  SelectorMNGBAZA(MNGVID_DZ2to5MF);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compDZ3);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompDZ3);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompDZ3()

void VidCompDZ3()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compDZ3);
//  PassWord(EditVidAPV);
  EditVidDZ3();
}//VidCompDZ3()

void EditVidDZ3()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compDZ3);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompDZ3(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compDZ3, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UprListCompDZ3()
{
  SelectorMNGBAZA(MNGUPR_DZ2to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compDZ3);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompDZ3);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompDZ3()

void UprCompDZ3()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compDZ3);
  PassWord(EditUprDZ3);

}//UprCompMTZ3()

void EditUprDZ3()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compDZ3[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrDZ2);//редактировать уставку управления
}//EditUprDZ3()

short  KadrMenuFormat_upr_compDZ3(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compDZ3[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrDZ2(i, getCurrentMngUSTAVKI()));

      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compDZ3(WorkControl *workCntr)

int initUstDZ3(char init)
{
 return initUstDZ2(init);
}//initUstDZ3(short mngUst, char init)

void  prepareUstDZ3(short idxC)
{
  prepareUstDZ2(idxC);
}//prepareUstDZ3(short idxC)

int codecUstDZ3(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
  return codecUstDZ2(codec, offset, ust);
}//codecUstDZ3(char *buf, short offset, int ust)

void diffDZ3ToRepozitar()
{
//копировать изменения компонента в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  DZ3_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_DZ3;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_DZ;   //к-во клонов
  rpzcomponent_obj.numClon     = 3;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstDZ3;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstDZ3;//подготовка уставок

  rpzcomponent_obj.nameStatusIO = ionsDZ3;          //имена и статус команд IO

  rpzcomponent_obj.codecUst = codecUstDZ3;   //кодировать-раскодировать уставку

}//

#endif // _HIDE_COMPONENT

