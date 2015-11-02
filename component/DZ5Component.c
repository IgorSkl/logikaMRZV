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

void PereinitUstListCompDZ5(short flg);
void UstListCompDZ5();
void ustRedactorCompDZ5();
void UstCompDZ5();

void PereinitVidListCompDZ5(short flg);
void VidListCompDZ5();
void vidRedactorCompDZ5();
void VidCompDZ5();

void PereinitUprListCompDZ5(short flg);
void UprListCompDZ5();
void uprRedactorCompDZ5();
void UprCompDZ5();
short  KadrMenuFormat_upr_compDZ5(void *workCntr);
int  initUstDZ5(char init);
void  prepareUstDZ2(short idxC);
void  prepareUstDZ5(short idxC);
short  KadrMenuFormat_ustvidDZ(void *workCntr);
char *selectorUprStrDZ2(short iBit, UNS_32 ustUpr);

//int ViewerEditUstDZ5();
//int ViewerEditVidDZ5();
void EditUprDZ5();
void EditVidDZ5();
void EditUstDZ5();
int codecUstDZ5(char codec, short offset, int ust);
int codecUstDZ2(char codec, short offset, int ust);
int initUstDZ2(char init);

char DZ5_TITLE[] = "ДЗ5";

IONAMESTATUS_COMPONENT ionsDZ5[IOCMD_DZ2to5_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок ДЗ5"
  },
  {
    1,//статус iocmd2
    "Блок уск ДЗ5"
  },
  {
    1,//статус iocmd3
    "Операт уск ДЗ5"
  },
  {
    1,//статус iocmd4
    "Сраб ПО ДЗ5МФ"
  },
  {
    1,//статус iocmd5
    "Сраб ДЗ5МФ"
  },
  {
    1,//статус iocmd6
    "Сраб ПО МТЗ ДЗ5МФ"
  },
  {
    1,//статус iocmd7
    "Сраб МТЗ ДЗ5МФ"
  },
  {
    1,//статус iocmd8
    "Сраб ПО ДЗ5ОФ"
  },
  {
    1,//статус iocmd9
    "Сраб ДЗ5ОФ"
  },
  {
    1,//статус iocmd10
    "Теле уск ДЗ5"
  }
};

LineMenuItem sub_menu_comp_DZ5[8] =
{
  { DZ5_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_DZ, typeMenuSub},//control_item, parent
  { "Уставки ДЗ5",     (void *)&UstListCompDZ5, typeMenuProg},
  { "Выдержки ДЗ5",    (void *)&VidListCompDZ5, typeMenuProg},
  { "Управление ДЗ5",  (void *)&UprListCompDZ5, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compDZ5[] =
{
  { "Уставки ДЗ5", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ5, typeMenuList},//control_item, parent
  { "Уст ДЗ5",        (void *)&UstCompDZ5, typeMenuProg},
  { "Уст ДЗ5 вперед", (void *)&UstCompDZ5, typeMenuProg},
  { "Уст ДЗ5 назад",  (void *)&UstCompDZ5, typeMenuProg},
  { "Уст ДЗ5 ПМ",     (void *)&UstCompDZ5, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compDZ5[] =
{
  { "Выдержки ДЗ5", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ5, typeMenuList},//control_item, parent
/*
  { "Выдержка ДЗ5МФ",       (void*)&VidCompDZ5, typeMenuProg},
  { "Выдержка МТЗ ДЗ5МФ",   (void*)&VidCompDZ5, typeMenuProg},
  { "Выдержка ДЗ5ОФ",       (void*)&VidCompDZ5, typeMenuProg},
  { "Ввод ускор ДЗ5МФ",     (void*)&VidCompDZ5, typeMenuProg},
  { "Ввод ускор МТЗ ДЗ5МФ", (void*)&VidCompDZ5, typeMenuProg},

  { "Ускор ДЗ5МФ ВВ",       (void*)&VidCompDZ5, typeMenuProg},
  { "Ускор ДЗ5МФ ОУ",       (void*)&VidCompDZ5, typeMenuProg},
  { "Ускор ДЗ5МФ ТУ",       (void*)&VidCompDZ5, typeMenuProg},

  { "Ускор МТЗ ДЗ5МФ ВВ",   (void*)&VidCompDZ5, typeMenuProg},
  { "Ускор МТЗ ДЗ5МФ ОУ",   (void*)&VidCompDZ5, typeMenuProg},
  { "Ускор МТЗ ДЗ5МФ ТУ",   (void*)&VidCompDZ5, typeMenuProg},

  { "Ускор ДЗ5ОФ ВВ",       (void*)&VidCompDZ5, typeMenuProg},
  { "Ускор ДЗ5ОФ ОУ",       (void*)&VidCompDZ5, typeMenuProg},
  { "Ускор ДЗ5ОФ ТУ",       (void*)&VidCompDZ5, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compDZ5[] =
{
  { "Управл ДЗ5", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ5, typeMenuList},//control_item, parent
  { "Управл ДЗ5",        (void *)&UprCompDZ5, typeMenuProg},
  { "Управл МТЗ ДЗ5",    (void *)&UprCompDZ5, typeMenuProg},
  { "Ускор ВВ ДЗ5",      (void *)&UprCompDZ5, typeMenuProg},
  { "Автомат уск ДЗ5",   (void *)&UprCompDZ5, typeMenuProg},
  { "Телеускор ДЗ5",     (void *)&UprCompDZ5, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompDZ5(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidDZ, sub_menu_ust_compDZ5);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp3()

void UstListCompDZ5()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compDZ5);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompDZ5);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompDZ5()

void UstCompDZ5()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compDZ5);
  PassWord(EditUstDZ5);
}//VidCompDZ5()

void EditUstDZ5()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compDZ5);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompDZ5()

//--------------------------------------------------

void PereinitVidListCompDZ5(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidDZ, sub_menu_vid_compDZ5);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitVidListCompDZ5(short flg)

void VidListCompDZ5()
{
  SelectorMNGBAZA(MNGVID_DZ2to5MF);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compDZ5);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompDZ5);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompDZ5()

void VidCompDZ5()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compDZ5);
//  PassWord(EditVidAPV);
  EditVidDZ5();
}//VidCompDZ5()

void EditVidDZ5()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compDZ5);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompDZ5(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compDZ5, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UprListCompDZ5()
{
  LIGHTMNGUBAZA = MNGUPR_DZ2to5;

  CRR_SUBMENU = sub_menu_upr_compDZ5;//текущее субменю

  CRR_TEXTSTREAM = &CONTROL2_COMP;//текущий control
  CRR_FHOME = &PereinitUprListCompDZ5;//указатель на ф-цию HOME

  CRR_FHOME(1);//переиниц
  LanderUpDown();//wkl Up Down
}//VidListCompDZ5()

void UprCompDZ5()
{
  LIGHTLINEMENU = TxtStreamIdxKadr(CRR_TEXTSTREAM);
//редактировать уставку управления
  sub_menu_tmp[SUBDATA].Line2 = &sub_menu_upr_compDZ5;// parent
  char *nameUpr = (char *)sub_menu_upr_compDZ5[LIGHTLINEMENU +1+SUBDATA].Line1;

  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrDZ2);//редактировать уставку управления

}//UprCompDZ5()

short  KadrMenuFormat_upr_compDZ5(void *pstr)//(WorkControl *workCntr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compDZ5[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      //отобразить уставку управления в кадре
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrDZ2(i, getCurrentMngUSTAVKI()));

      return 1;//сравнить счетчики кадров
    }//COMPARE_COUNTER
  }//for

  return 1;
}//KadrMenuFormat_upr_compDZ5(WorkControl *workCntr)

int initUstDZ5(char init)
{
 return initUstDZ2(init);
}//initUstDZ2to5(short mngUst, char init)

void  prepareUstDZ5(short idxC)
{
  prepareUstDZ2(idxC);
}//prepareUstDZ3(short idxC)

int codecUstDZ5(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
  return codecUstDZ2(codec, offset, ust);
}//codecUstDZ5(char *buf, short offset, int ust)

void diffDZ5ToRepozitar()
{
//копировать изменения компонента в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  DZ5_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_DZ5;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_DZ;   //к-во клонов
  rpzcomponent_obj.numClon     = 5;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstDZ5;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstDZ5;//подготовка уставок

  rpzcomponent_obj.nameStatusIO = ionsDZ5;          //имена и статус команд IO

  rpzcomponent_obj.codecUst = codecUstDZ5;   //кодировать-раскодировать уставку
}//

#endif // _HIDE_COMPONENT

