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

void PereinitUstListCompDZ4(short flg);
void UstListCompDZ4();
void ustRedactorCompDZ4();
void UstCompDZ4();

void PereinitVidListCompDZ4(short flg);
void VidListCompDZ4();
void vidRedactorCompDZ4();
void VidCompDZ4();

void PereinitUprListCompDZ4(short flg);
void UprListCompDZ4();
void uprRedactorCompDZ4();
void UprCompDZ4();
short  KadrMenuFormat_upr_compDZ4(void *workCntr);
int   initUstDZ4(char init);
void  prepareUstDZ2(short idxC);
void  prepareUstDZ4(short idxC);

//int ViewerEditUstDZ4();
//int ViewerEditVidDZ4();
void EditUprDZ4();
void EditVidDZ4();
void EditUstDZ4();
int codecUstDZ4(char codec, short offset, int ust);
int codecUstDZ2(char codec, short offset, int ust);
int initUstDZ2(char init);

short  KadrMenuFormat_ustvidDZ(void *workCntr);
char *selectorUprStrDZ2(short iBit, UNS_32 ustUpr);

char DZ4_TITLE[] = "ДЗ4";

IONAMESTATUS_COMPONENT ionsDZ4[IOCMD_DZ2to5_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок ДЗ4"
  },
  {
    1,//статус iocmd2
    "Блок уск ДЗ4"
  },
  {
    1,//статус iocmd3
    "Операт уск ДЗ4"
  },
  {
    1,//статус iocmd4
    "Сраб ПО ДЗ4МФ"
  },
  {
    1,//статус iocmd5
    "Сраб ДЗ4МФ"
  },
  {
    1,//статус iocmd6
    "Сраб ПО МТЗ ДЗ4МФ"
  },
  {
    1,//статус iocmd7
    "Сраб МТЗ ДЗ4МФ"
  },
  {
    1,//статус iocmd8
    "Сраб ПО ДЗ4ОФ"
  },
  {
    1,//статус iocmd9
    "Сраб ДЗ4ОФ"
  },
  {
    1,//статус iocmd10
    "Теле уск ДЗ4"
  }
};

LineMenuItem sub_menu_comp_DZ4[8] =
{
  { DZ4_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_DZ, typeMenuSub},//control_item, parent
  { "Уставки ДЗ4",     (void *)&UstListCompDZ4, typeMenuProg},
  { "Выдержки ДЗ4",    (void *)&VidListCompDZ4, typeMenuProg},
  { "Управление ДЗ4",  (void *)&UprListCompDZ4, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compDZ4[] =
{
  { "Уставки ДЗ4", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ4, typeMenuList},//control_item, parent
  { "Уст ДЗ4",        (void *)&UstCompDZ4, typeMenuProg},
  { "Уст ДЗ4 вперед", (void *)&UstCompDZ4, typeMenuProg},
  { "Уст ДЗ4 назад",  (void *)&UstCompDZ4, typeMenuProg},
  { "Уст ДЗ4 ПМ",     (void *)&UstCompDZ4, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compDZ4[] =
{
  { "Выдержки ДЗ4", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ4, typeMenuList},//control_item, parent
/*
  { "Выдержка ДЗ4МФ",       (void*)&VidCompDZ4, typeMenuProg},
  { "Выдержка МТЗ ДЗ4МФ",   (void*)&VidCompDZ4, typeMenuProg},
  { "Выдержка ДЗ4ОФ",       (void*)&VidCompDZ4, typeMenuProg},
  { "Ввод ускор ДЗ4МФ",     (void*)&VidCompDZ4, typeMenuProg},
  { "Ввод ускор МТЗ ДЗ4МФ", (void*)&VidCompDZ4, typeMenuProg},

  { "Ускор ДЗ4МФ ВВ",       (void*)&VidCompDZ4, typeMenuProg},
  { "Ускор ДЗ4МФ ОУ",       (void*)&VidCompDZ4, typeMenuProg},
  { "Ускор ДЗ4МФ ТУ",       (void*)&VidCompDZ4, typeMenuProg},

  { "Ускор МТЗ ДЗ4МФ ВВ",   (void*)&VidCompDZ4, typeMenuProg},
  { "Ускор МТЗ ДЗ4МФ ОУ",   (void*)&VidCompDZ4, typeMenuProg},
  { "Ускор МТЗ ДЗ4МФ ТУ",   (void*)&VidCompDZ4, typeMenuProg},

  { "Ускор ДЗ4ОФ ВВ",       (void*)&VidCompDZ4, typeMenuProg},
  { "Ускор ДЗ4ОФ ОУ",       (void*)&VidCompDZ4, typeMenuProg},
  { "Ускор ДЗ4ОФ ТУ",       (void*)&VidCompDZ4, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compDZ4[] =
{
  { "Управл ДЗ4", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ4, typeMenuList},//control_item, parent
  { "Управл ДЗ4",        (void *)&UprCompDZ4, typeMenuProg},
  { "Управл МТЗ ДЗ4",    (void *)&UprCompDZ4, typeMenuProg},
  { "Ускор ВВ ДЗ4",      (void *)&UprCompDZ4, typeMenuProg},
  { "Автомат уск ДЗ4",   (void *)&UprCompDZ4, typeMenuProg},
  { "Телеускор ДЗ4",     (void *)&UprCompDZ4, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompDZ4(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidDZ, sub_menu_ust_compDZ4);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp3()

void UstListCompDZ4()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compDZ4);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompDZ4);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompDZ4()

void UstCompDZ4()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compDZ4);
  PassWord(EditUstDZ4);
}//VidCompDZ4()

void EditUstDZ4()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compDZ4);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompDZ4()

//--------------------------------------------------

void PereinitVidListCompDZ4(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidDZ, sub_menu_vid_compDZ4);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitVidListCompDZ4(short flg)

void VidListCompDZ4()
{
  SelectorMNGBAZA(MNGVID_DZ2to5MF);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compDZ4);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompDZ4);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompDZ4()

void VidCompDZ4()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compDZ4);
//  PassWord(EditVidAPV);
  EditVidDZ4();
}//VidCompDZ4()

void EditVidDZ4()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compDZ4);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompDZ4(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compDZ4, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UprListCompDZ4()
{
  SelectorMNGBAZA(MNGUPR_DZ2to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compDZ4);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompDZ4);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompDZ4()

void UprCompDZ4()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compDZ4);
  PassWord(EditUprDZ4);

}//UprCompMTZ4()

void EditUprDZ4()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compDZ4[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrDZ2);//редактировать уставку управления
}//EditUprDZ4()

short  KadrMenuFormat_upr_compDZ4(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compDZ4[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      //UpravlViewerInKadr(nameUpr, i, workCntr);//отобразить уставку управления в кадре
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrDZ2(i, getCurrentMngUSTAVKI()));

      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compDZ4(WorkControl *workCntr)

int initUstDZ4(char init)
{
 return initUstDZ2(init);
}//initUstDZ4(short mngUst, char init)

void  prepareUstDZ4(short idxC)
{
  prepareUstDZ2(idxC);
}//prepareUstDZ3(short idxC)

int codecUstDZ4(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  return codecUstDZ2(codec, offset, ust);
}//codecUstDZ4(char *buf, short offset, int ust)

void diffDZ4ToRepozitar()
{
//копировать изменения компонента в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  DZ4_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_DZ4;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_DZ;   //к-во клонов
  rpzcomponent_obj.numClon     = 4;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstDZ4;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstDZ4;//подготовка уставок

  rpzcomponent_obj.nameStatusIO = ionsDZ4;          //имена и статус команд IO

  rpzcomponent_obj.codecUst = codecUstDZ4;   //кодировать-раскодировать уставку
}//

#endif // _HIDE_COMPONENT

