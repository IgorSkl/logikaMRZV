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

void PereinitUstListCompTZNP3(short flg);
void UstListCompTZNP3();
void ustRedactorCompTZNP3();
void UstCompTZNP3();

void PereinitVidListCompTZNP3(short flg);
void VidListCompTZNP3();
void vidRedactorCompTZNP3();
void VidCompTZNP3();

void PereinitUprListCompTZNP3(short flg);
void UprListCompTZNP3();
void uprRedactorCompTZNP3();
void UprCompTZNP3();
short  KadrMenuFormat_upr_compTZNP3(void *workCntr);
int  initUstTZNP3(char init);
void  prepareUstTZNP3(short idxC);
void  prepareUstTZNP1(short idxC);

//int ViewerEditUstTZNP3();
//int ViewerEditVidTZNP3();
void EditUstTZNP3();
void EditVidTZNP3();
void EditUprTZNP3();
int codecUstTZNP3(char codec, short offset, int ust);
int codecUstTZNP1(char codec, short offset, int ust);
int initUstTZNP1(char init);

char *selectorUprStrTZNP2(short iBit, UNS_32 ustUpr);
short  KadrMenuFormat_ustvidTZNP(void *workCntr);
void diffTZNP3ToRepozitar();

char TZNP3_TITLE[] = "ТЗНП3";

IONAMESTATUS_COMPONENT ionsTZNP3[IOCMD_TZNP1to5_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок ТЗНП3"
  },
  {
    1,//статус iocmd2
    "Блок уск ТЗНП3"
  },
  {
    1,//статус iocmd3
    "Опер уск ТЗНП3"
  },
  {
    1,//статус iocmd4
    "Сраб ПО ТЗНП3"
  },
  {
    1,//статус iocmd5
    "Сраб ТЗНП3"
  },
  {
    1,//статус iocmd6
    "Сраб ПО ТЗНП3 3I0"
  },
  {
    1,//статус iocmd7
    "Сраб ТЗНП3 3I0"
  },
  {
    1,//статус iocmd8
    "Сраб ПО ТЗНП3 3U0"
  },
  {
    1,//статус iocmd9
    "Сраб ТЗНП3 3U0"
  },
  {
    1,//статус iocmd10
    "Теле уск ТЗНП3"
  },
  {
    1,//статус iocmd11
    "Сектор ТЗНП3"
  }
};

LineMenuItem sub_menu_comp_TZNP3[8] =
{
  { TZNP3_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_TZNP, typeMenuSub},//control_item, parent
  { "Уставки ТЗНП3",    (void*)&UstListCompTZNP3, typeMenuProg},
  { "Выдержки ТЗНП3",   (void*)&VidListCompTZNP3, typeMenuProg},
  { "Управление ТЗНП3", (void*)&UprListCompTZNP3, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compTZNP3[] =
{
  { "Уставки ТЗНП3", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP3, typeMenuList},//control_item, parent
  { "Уст ТЗНП3 3I0", (void*)&UstCompTZNP3, typeMenuProg},
  { "Уст ТЗНП3 3U0", (void*)&UstCompTZNP3, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compTZNP3[] =
{
  { "Выдержки ТЗНП3", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP3, typeMenuList},//control_item, parent
/*
  { "Выдержка ТЗНП3",         (void*)&VidCompTZNP3, typeMenuProg},
  { "Выдержка ТЗНП3 3I0",     (void*)&VidCompTZNP3, typeMenuProg},
  { "Выдержка ТЗНП3 3U0",     (void*)&VidCompTZNP3, typeMenuProg},
  { "Ввод ускор ТЗНП3",       (void*)&VidCompTZNP3, typeMenuProg},

  { "Ускор ТЗНП3 ВВ",         (void*)&VidCompTZNP3, typeMenuProg},
  { "Ускор ТЗНП3 ОУ",         (void*)&VidCompTZNP3, typeMenuProg},
  { "Ускор ТЗНП3 ТУ",         (void*)&VidCompTZNP3, typeMenuProg},

  { "Ускор ТЗНП3 3I0 ВВ",     (void*)&VidCompTZNP3, typeMenuProg},
  { "Ускор ТЗНП3 3I0 ОУ",     (void*)&VidCompTZNP3, typeMenuProg},
  { "Ускор ТЗНП3 3I0 ТУ",     (void*)&VidCompTZNP3, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compTZNP3[] =
{
  { "Управл ТЗНП3", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP3, typeMenuList},//control_item, parent
  { "Управл ТЗНП3",        (void*)&UprCompTZNP3, typeMenuProg},
  { "Управл ТЗНП3 3I0",    (void*)&UprCompTZNP3, typeMenuProg},
  { "Управл ТЗНП3 3U0",    (void*)&UprCompTZNP3, typeMenuProg},
  { "Направл ТЗНП3",       (void*)&UprCompTZNP3, typeMenuProg},
  { "Ускор ВВ ТЗНП3",      (void*)&UprCompTZNP3, typeMenuProg},
  { "Автомат уск ТЗНП3",   (void*)&UprCompTZNP3, typeMenuProg},
  { "Телеускор ТЗНП3",     (void*)&UprCompTZNP3, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompTZNP3(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_ust_compTZNP3);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp3()

void UstListCompTZNP3()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compTZNP3);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompTZNP3);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompTZNP3()

void UstCompTZNP3()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compTZNP3);
  PassWord(EditUstTZNP3);
}//VidCompTZNP3()

void EditUstTZNP3()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compTZNP3);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompTZNP3()

//--------------------------------------------------

void PereinitVidListCompTZNP3(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_vid_compTZNP3);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitVidListCompTZNP3(short flg)

void VidListCompTZNP3()
{
  SelectorMNGBAZA(MNGVID_TZNP1to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compTZNP3);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompTZNP3);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompTZNP3()

void VidCompTZNP3()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compTZNP3);
//  PassWord(EditVidAPV);
  EditVidTZNP3();
}//VidCompTZNP3()

void EditVidTZNP3()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compTZNP3);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompTZNP3(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compTZNP3, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UprListCompTZNP3()
{
  SelectorMNGBAZA(MNGUPR_TZNP1to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compTZNP3);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompTZNP3);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompNZOP3()

void UprCompTZNP3()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compTZNP3);
  PassWord(EditUprTZNP3);

}//UprCompTZNP3()

void EditUprTZNP3()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compTZNP3[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrTZNP2);//редактировать уставку управления
}//EditUprTZNP2()

short  KadrMenuFormat_upr_compTZNP3(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compTZNP3[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      //    UpravlViewerInKadr(nameUpr, i, workCntr);//отобразить уставку управления в кадре
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrTZNP2(i, getCurrentMngUSTAVKI()));

      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compTZNP3(WorkControl *workCntr)

int initUstTZNP3(char init)
{
 return initUstTZNP1(init);
}//initUstTZNP3(short mngUst, char init)

void  prepareUstTZNP3(short idxC)
{
  prepareUstTZNP1(idxC);
}//prepareUstTZNP3(short idxC)

int codecUstTZNP3(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
 return codecUstTZNP1(codec, offset, ust);
}//codecUstTZNP3(char *buf, short offset, int ust)

void diffTZNP3ToRepozitar()
{
//копировать изменения компонента в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  TZNP3_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_TZNP3;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_TZNP;   //к-во клонов
  rpzcomponent_obj.numClon     = 3;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstTZNP3;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstTZNP3;//подготовка уставок

  rpzcomponent_obj.nameStatusIO = ionsTZNP3;          //имена и статус команд IO

  rpzcomponent_obj.codecUst = codecUstTZNP3;   //кодировать-раскодировать уставку

}//

#endif // _HIDE_COMPONENT

