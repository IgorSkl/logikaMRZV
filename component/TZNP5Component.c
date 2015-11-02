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

#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"
#include "virtualMenu\rangmanagerfnc.h"

#include "virtualMenu\viewMenuList.h"

#include "..\bazis.h"

//код компонентов
#define KOD_COMPONENT  TZNP_COMP1
//к-во ступеней
#define CNT_STUPEN_TZNP  5

#endif // _HIDE_COMPONENT

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "TZNP1Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_TZNP[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//индекс уставок в супервизоре

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//текущие уставки супервизора

void PereinitUstListCompTZNP5(short flg);
void UstListCompTZNP5();
void ustRedactorCompTZNP5();
void UstCompTZNP5();

void PereinitVidListCompTZNP5(short flg);
void VidListCompTZNP5();
void vidRedactorCompTZNP5();
void VidCompTZNP5();

void PereinitUprListCompTZNP5(short flg);
void UprListCompTZNP5();
void uprRedactorCompTZNP5();
void UprCompTZNP5();
short  KadrMenuFormat_upr_compTZNP5(void *workCntr);//(WorkControl *workCntr);
int   initUstTZNP5(char init);
void  prepareUstTZNP5(short idxC);
void  prepareUstTZNP1(short idxC);

//int ViewerEditUstTZNP5();
//int ViewerEditVidTZNP5();
void EditUstTZNP5();
void EditVidTZNP5();
void EditUprTZNP5();
int codecUstTZNP5(char codec, short offset, int ust);
int codecUstTZNP1(char codec, short offset, int ust);
int initUstTZNP1(char init);

char *selectorUprStrTZNP2(short iBit, UNS_32 ustUpr);
short  KadrMenuFormat_ustvidTZNP(void *workCntr);
void diffTZNP5ToRepozitar();

char TZNP5_TITLE[] = "ТЗНП5";

IONAMESTATUS_COMPONENT ionsTZNP5[IOCMD_TZNP1to5_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок ТЗНП5"
  },
  {
    1,//статус iocmd2
    "Блок уск ТЗНП5"
  },
  {
    1,//статус iocmd3
    "Опер уск ТЗНП5"
  },
  {
    1,//статус iocmd4
    "Сраб ПО ТЗНП5"
  },
  {
    1,//статус iocmd5
    "Сраб ТЗНП5"
  },
  {
    1,//статус iocmd6
    "Сраб ПО ТЗНП5 3I0"
  },
  {
    1,//статус iocmd7
    "Сраб ТЗНП5 3I0"
  },
  {
    1,//статус iocmd8
    "Сраб ПО ТЗНП5 3U0"
  },
  {
    1,//статус iocmd9
    "Сраб ТЗНП5 3U0"
  },
  {
    1,//статус iocmd10
    "Теле уск ТЗНП5"
  },
  {
    1,//статус iocmd11
    "Сектор ТЗНП5"
  }
};

LineMenuItem sub_menu_comp_TZNP5[8] =
{
  { TZNP5_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_TZNP, typeMenuSub},//control_item, parent
  { "Уставки ТЗНП5",    (void*)&UstListCompTZNP5, typeMenuProg},
  { "Выдержки ТЗНП5",   (void*)&VidListCompTZNP5, typeMenuProg},
  { "Управление ТЗНП5", (void*)&UprListCompTZNP5, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compTZNP5[] =
{
  { "Уставки ТЗНП5", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP5, typeMenuList},//control_item, parent
  { "Уст ТЗНП5 3I0", (void*)&UstCompTZNP5, typeMenuProg},
  { "Уст ТЗНП5 3U0", (void*)&UstCompTZNP5, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compTZNP5[] =
{
  { "Выдержки ТЗНП5", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP5, typeMenuList},//control_item, parent
/*
  { "Выдержка ТЗНП5",         (void*)&VidCompTZNP5, typeMenuProg},
  { "Выдержка ТЗНП5 3I0",     (void*)&VidCompTZNP5, typeMenuProg},
  { "Выдержка ТЗНП5 3U0",     (void*)&VidCompTZNP5, typeMenuProg},
  { "Ввод ускор ТЗНП5",       (void*)&VidCompTZNP5, typeMenuProg},

  { "Ускор ТЗНП5 ВВ",         (void*)&VidCompTZNP5, typeMenuProg},
  { "Ускор ТЗНП5 ОУ",         (void*)&VidCompTZNP5, typeMenuProg},
  { "Ускор ТЗНП5 ТУ",         (void*)&VidCompTZNP5, typeMenuProg},

  { "Ускор ТЗНП5 3I0 ВВ",     (void*)&VidCompTZNP5, typeMenuProg},
  { "Ускор ТЗНП5 3I0 ОУ",     (void*)&VidCompTZNP5, typeMenuProg},
  { "Ускор ТЗНП5 3I0 ТУ",     (void*)&VidCompTZNP5, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compTZNP5[] =
{
  { "Управл ТЗНП5", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP5, typeMenuList},//control_item, parent
  { "Управл ТЗНП5",        (void*)&UprCompTZNP5, typeMenuProg},
  { "Управл ТЗНП5 3I0",    (void*)&UprCompTZNP5, typeMenuProg},
  { "Управл ТЗНП5 3U0",    (void*)&UprCompTZNP5, typeMenuProg},
  { "Направл ТЗНП5",       (void*)&UprCompTZNP5, typeMenuProg},
  { "Ускор ВВ ТЗНП5",      (void*)&UprCompTZNP5, typeMenuProg},
  { "Автомат уск ТЗНП5",   (void*)&UprCompTZNP5, typeMenuProg},
  { "Телеускор ТЗНП5",     (void*)&UprCompTZNP5, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompTZNP5(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_ust_compTZNP5);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp3()

void UstListCompTZNP5()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compTZNP5);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompTZNP5);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompTZNP5()

void UstCompTZNP5()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compTZNP5);
  PassWord(EditUstTZNP5);
}//VidCompTZNP4()

void EditUstTZNP5()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compTZNP5);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompTZNP5()

//--------------------------------------------------

void PereinitVidListCompTZNP5(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_vid_compTZNP5);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitVidListCompTZNP5(short flg)

void VidListCompTZNP5()
{
  SelectorMNGBAZA(MNGVID_TZNP1to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compTZNP5);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompTZNP5);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompTZNP5()

void VidCompTZNP5()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compTZNP5);
//  PassWord(EditVidAPV);
  EditVidTZNP5();
}//VidCompTZNP5()

void EditVidTZNP5()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compTZNP5);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompTZNP5(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compTZNP5, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UprListCompTZNP5()
{
  SelectorMNGBAZA(MNGUPR_TZNP1to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compTZNP5);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompTZNP5);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompNZOP5()

void UprCompTZNP5()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compTZNP5);
  PassWord(EditUprTZNP5);

}//UprCompTZNP5()

void EditUprTZNP5()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compTZNP5[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrTZNP2);//редактировать уставку управления
}//EditUprTZNP5()

short  KadrMenuFormat_upr_compTZNP5(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compTZNP5[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      //отобразить уставку управления в кадре
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrTZNP2(i, getCurrentMngUSTAVKI()));

      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compTZNP5(WorkControl *workCntr)

int initUstTZNP5(char init)
{
 return initUstTZNP1(init);
}//initUstTZNP5(short mngUst, char init)

void  prepareUstTZNP5(short idxC)
{
  prepareUstTZNP1(idxC);
}//prepareUstTZNP5(short idxC)

int codecUstTZNP5(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
 return codecUstTZNP1(codec, offset, ust);
}//codecUstTZNP5(char *buf, short offset, int ust)

void diffTZNP5ToRepozitar()
{
//копировать изменения компонента в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  TZNP5_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_TZNP5;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_TZNP;   //к-во клонов
  rpzcomponent_obj.numClon     = 5;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstTZNP5;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstTZNP5;//подготовка уставок

  rpzcomponent_obj.nameStatusIO = ionsTZNP5;          //имена и статус команд IO

  rpzcomponent_obj.codecUst = codecUstTZNP5;   //кодировать-раскодировать уставку

}//

#endif // _HIDE_COMPONENT

