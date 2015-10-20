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

void PereinitUstListCompTZNP4(short flg);
void UstListCompTZNP4();
void ustRedactorCompTZNP4();
void UstCompTZNP4();

void PereinitVidListCompTZNP4(short flg);
void VidListCompTZNP4();
void vidRedactorCompTZNP4();
void VidCompTZNP4();

void PereinitUprListCompTZNP4(short flg);
void UprListCompTZNP4();
void uprRedactorCompTZNP4();
void UprCompTZNP4();
short  KadrMenuFormat_upr_compTZNP4(void *workCntr);
int  initUstTZNP4(char init);
void  prepareUstTZNP4(short idxC);
void  prepareUstTZNP1(short idxC);

//int ViewerEditUstTZNP4();
//int ViewerEditVidTZNP4();
void EditUstTZNP4();
void EditVidTZNP4();
void EditUprTZNP4();
int codecUstTZNP4(char codec, short offset, int ust);
int codecUstTZNP1(char codec, short offset, int ust);
int initUstTZNP1(char init);

char *selectorUprStrTZNP2(short iBit, UNS_32 ustUpr);
short  KadrMenuFormat_ustvidTZNP(void *workCntr);
void diffTZNP4ToRepozitar();

char TZNP4_TITLE[] = "ТЗНП4";

IONAMESTATUS_COMPONENT ionsTZNP4[IOCMD_TZNP1to5_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок ТЗНП4"
  },
  {
    1,//статус iocmd2
    "Блок уск ТЗНП4"
  },
  {
    1,//статус iocmd3
    "Опер уск ТЗНП4"
  },
  {
    1,//статус iocmd4
    "Сраб ПО ТЗНП4"
  },
  {
    1,//статус iocmd5
    "Сраб ТЗНП4"
  },
  {
    1,//статус iocmd6
    "Сраб ПО ТЗНП4 3I0"
  },
  {
    1,//статус iocmd7
    "Сраб ТЗНП4 3I0"
  },
  {
    1,//статус iocmd8
    "Сраб ПО ТЗНП4 3U0"
  },
  {
    1,//статус iocmd9
    "Сраб ТЗНП4 3U0"
  },
  {
    1,//статус iocmd10
    "Теле уск ТЗНП4"
  },
  {
    1,//статус iocmd11
    "Сектор ТЗНП4"
  }
};

LineMenuItem sub_menu_comp_TZNP4[8] =
{
  { TZNP4_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_TZNP, typeMenuSub},//control_item, parent
  { "Уставки ТЗНП4",    (void*)&UstListCompTZNP4, typeMenuProg},
  { "Выдержки ТЗНП4",   (void*)&VidListCompTZNP4, typeMenuProg},
  { "Управление ТЗНП4", (void*)&UprListCompTZNP4, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compTZNP4[] =
{
  { "Уставки ТЗНП4", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP4, typeMenuList},//control_item, parent
  { "Уст ТЗНП4 3I0", (void*)&UstCompTZNP4, typeMenuProg},
  { "Уст ТЗНП4 3U0", (void*)&UstCompTZNP4, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compTZNP4[] =
{
  { "Выдержки ТЗНП4", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP4, typeMenuList},//control_item, parent
/*
  { "Выдержка ТЗНП4",         (void*)&VidCompTZNP4, typeMenuProg},
  { "Выдержка ТЗНП4 3I0",     (void*)&VidCompTZNP4, typeMenuProg},
  { "Выдержка ТЗНП4 3U0",     (void*)&VidCompTZNP4, typeMenuProg},
  { "Ввод ускор ТЗНП4",       (void*)&VidCompTZNP4, typeMenuProg},

  { "Ускор ТЗНП4 ВВ",         (void*)&VidCompTZNP4, typeMenuProg},
  { "Ускор ТЗНП4 ОУ",         (void*)&VidCompTZNP4, typeMenuProg},
  { "Ускор ТЗНП4 ТУ",         (void*)&VidCompTZNP4, typeMenuProg},

  { "Ускор ТЗНП4 3I0 ВВ",     (void*)&VidCompTZNP4, typeMenuProg},
  { "Ускор ТЗНП4 3I0 ОУ",     (void*)&VidCompTZNP4, typeMenuProg},
  { "Ускор ТЗНП4 3I0 ТУ",     (void*)&VidCompTZNP4, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compTZNP4[] =
{
  { "Управл ТЗНП4", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP4, typeMenuList},//control_item, parent
  { "Управл ТЗНП4",        (void*)&UprCompTZNP4, typeMenuProg},
  { "Управл ТЗНП4 3I0",    (void*)&UprCompTZNP4, typeMenuProg},
  { "Управл ТЗНП4 3U0",    (void*)&UprCompTZNP4, typeMenuProg},
  { "Направл ТЗНП4",       (void*)&UprCompTZNP4, typeMenuProg},
  { "Ускор ВВ ТЗНП4",      (void*)&UprCompTZNP4, typeMenuProg},
  { "Автомат уск ТЗНП4",   (void*)&UprCompTZNP4, typeMenuProg},
  { "Телеускор ТЗНП4",     (void*)&UprCompTZNP4, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompTZNP4(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_ust_compTZNP4);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp3()

void UstListCompTZNP4()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compTZNP4);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompTZNP4);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompTZNP4()

void UstCompTZNP4()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compTZNP4);
  PassWord(EditUstTZNP4);
}//VidCompTZNP4()

void EditUstTZNP4()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compTZNP4);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompTZNP4()

//--------------------------------------------------

void PereinitVidListCompTZNP4(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_vid_compTZNP4);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitVidListCompTZNP4(short flg)

void VidListCompTZNP4()
{
  SelectorMNGBAZA(MNGVID_TZNP1to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compTZNP4);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompTZNP4);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompTZNP4()

void VidCompTZNP4()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compTZNP4);
//  PassWord(EditVidAPV);
  EditVidTZNP4();
}//VidCompTZNP4()

void EditVidTZNP4()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compTZNP4);
}//

//--------------------------------------------------

void PereinitUprListCompTZNP4(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compTZNP4, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UprListCompTZNP4()
{
  SelectorMNGBAZA(MNGUPR_TZNP1to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compTZNP4);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompTZNP4);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompNZOP4()

void UprCompTZNP4()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compTZNP4);
  PassWord(EditUprTZNP4);

}//UprCompTZNP4()

void EditUprTZNP4()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compTZNP4[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrTZNP2);//редактировать уставку управления
}//EditUprTZNP4()

short  KadrMenuFormat_upr_compTZNP4(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compTZNP4[i+1+SUBDATA].Line1;
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
}//KadrMenuFormat_upr_compTZNP4(WorkControl *workCntr)

int initUstTZNP4(char init)
{
 return initUstTZNP1(init);
}//initUstTZNP4(short mngUst, char init)

void  prepareUstTZNP4(short idxC)
{
  prepareUstTZNP1(idxC);
}//prepareUstTZNP4(short idxC)

int codecUstTZNP4(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
 return codecUstTZNP1(codec, offset, ust);
}//codecUstTZNP4(char *buf, short offset, int ust)


void diffTZNP4ToRepozitar()
{
//копировать изменения компонента в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  TZNP4_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_TZNP4;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_TZNP;   //к-во клонов
  rpzcomponent_obj.numClon     = 4;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstTZNP4;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstTZNP4;//подготовка уставок

  rpzcomponent_obj.nameStatusIO = ionsTZNP4;          //имена и статус команд IO

  rpzcomponent_obj.codecUst = codecUstTZNP4;   //кодировать-раскодировать уставку

}//

#endif // _HIDE_COMPONENT

