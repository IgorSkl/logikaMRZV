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
extern char *bitStringUNI[];

void PereinitUstListCompTZNP2(short flg);
void UstListCompTZNP2();
void ustRedactorCompTZNP2();
void UstCompTZNP2();

void PereinitVidListCompTZNP2(short flg);
void VidListCompTZNP2();
void vidRedactorCompTZNP2();
void VidCompTZNP2();

void PereinitUprListCompTZNP2(short flg);
void UprListCompTZNP2();
void uprRedactorCompTZNP2();
void UprCompTZNP2();
short  KadrMenuFormat_upr_compTZNP2(void *workCntr);//(WorkControl *workCntr);
int  initUstTZNP2(char init);
void  prepareUstTZNP2(short idxC);
void  prepareUstTZNP1(short idxC);

//int ViewerEditUstTZNP2();
//int ViewerEditVidTZNP2();
void EditUstTZNP2();
void EditVidTZNP2();
void EditUprTZNP2();
int codecUstTZNP2(char codec, short offset, int ust);
int codecUstTZNP1(char codec, short offset, int ust);
int initUstTZNP1(char init);

char *selectorUprStrTZNP2(short iBit, UNS_32 ustUpr);
short  KadrMenuFormat_ustvidTZNP(void *workCntr);//(WorkControl *workCntr);

char TZNP2_TITLE[] = "ТЗНП2";

IONAMESTATUS_COMPONENT ionsTZNP2[IOCMD_TZNP1to5_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок ТЗНП2"
  },
  {
    1,//статус iocmd2
    "Блок уск ТЗНП2"
  },
  {
    1,//статус iocmd3
    "Опер уск ТЗНП2"
  },
  {
    1,//статус iocmd4
    "Сраб ПО ТЗНП2"
  },
  {
    1,//статус iocmd5
    "Сраб ТЗНП2"
  },
  {
    1,//статус iocmd6
    "Сраб ПО ТЗНП2 3I0"
  },
  {
    1,//статус iocmd7
    "Сраб ТЗНП2 3I0"
  },
  {
    1,//статус iocmd8
    "Сраб ПО ТЗНП2 3U0"
  },
  {
    1,//статус iocmd9
    "Сраб ТЗНП2 3U0"
  },
  {
    1,//статус iocmd10
    "Теле уск ТЗНП2"
  },
  {
    1,//статус iocmd11
    "Сектор ТЗНП2"
  }
};

LineMenuItem sub_menu_comp_TZNP2[8] =
{
  { TZNP2_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_TZNP, typeMenuSub},//control_item, parent
  { "Уставки ТЗНП2",     (void*)&UstListCompTZNP2, typeMenuProg},
  { "Выдержки ТЗНП2",    (void*)&VidListCompTZNP2, typeMenuProg},
  { "Управление ТЗНП2",  (void*)&UprListCompTZNP2, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compTZNP2[] =
{
  { "Уставки ТЗНП2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP2, typeMenuList},//control_item, parent
  { "Уст ТЗНП2 3I0",        (void*)&UstCompTZNP2, typeMenuProg},
  { "Уст ТЗНП2 3U0",        (void*)&UstCompTZNP2, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compTZNP2[] =
{
  { "Выдержки ТЗНП2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP2, typeMenuList},//control_item, parent
/*
  { "Выдержка ТЗНП2",         (void*)&VidCompTZNP2, typeMenuProg},
  { "Выдержка ТЗНП2 3I0",     (void*)&VidCompTZNP2, typeMenuProg},
  { "Выдержка ТЗНП2 3U0",     (void*)&VidCompTZNP2, typeMenuProg},
  { "Ввод ускор ТЗНП2",       (void*)&VidCompTZNP2, typeMenuProg},

  { "Ускор ТЗНП2 ВВ",         (void*)&VidCompTZNP2, typeMenuProg},
  { "Ускор ТЗНП2 ОУ",         (void*)&VidCompTZNP2, typeMenuProg},
  { "Ускор ТЗНП2 ТУ",         (void*)&VidCompTZNP2, typeMenuProg},

  { "Ускор ТЗНП2 3I0 ВВ",     (void*)&VidCompTZNP2, typeMenuProg},
  { "Ускор ТЗНП2 3I0 ОУ",     (void*)&VidCompTZNP2, typeMenuProg},
  { "Ускор ТЗНП2 3I0 ТУ",     (void*)&VidCompTZNP2, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compTZNP2[] =
{
  { "Управл ТЗНП2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_TZNP2, typeMenuList},//control_item, parent
  { "Управл ТЗНП2",        (void*)&UprCompTZNP2, typeMenuProg},
  { "Управл ТЗНП2 3I0",    (void*)&UprCompTZNP2, typeMenuProg},
  { "Управл ТЗНП2 3U0",    (void*)&UprCompTZNP2, typeMenuProg},
  { "Направл ТЗНП2",       (void*)&UprCompTZNP2, typeMenuProg},
  { "Ускор ВВ ТЗНП2",      (void*)&UprCompTZNP2, typeMenuProg},
  { "Автомат уск ТЗНП2",   (void*)&UprCompTZNP2, typeMenuProg},
  { "Телеускор ТЗНП2",     (void*)&UprCompTZNP2, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompTZNP2(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_ust_compTZNP2);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UstListCompTZNP2()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compTZNP2);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompTZNP2);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompTZNP2()

void UstCompTZNP2()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compTZNP2);
  PassWord(EditUstTZNP2);
}//VidCompTZNP2()

void EditUstTZNP2()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compTZNP2);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompTZNP2()

//--------------------------------------------------

void PereinitVidListCompTZNP2(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_vid_compTZNP2);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void VidListCompTZNP2()
{
  SelectorMNGBAZA(MNGVID_TZNP1to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compTZNP2);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompTZNP2);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompTZNP2()

void VidCompTZNP2()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compTZNP2);
//  PassWord(EditVidAPV);
  EditVidTZNP2();
}//VidCompTZNP2()

void EditVidTZNP2()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compTZNP2);
}//

//--------------------------------------------------

void PereinitUprListCompTZNP2(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compTZNP2, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UprListCompTZNP2()
{
  SelectorMNGBAZA(MNGUPR_TZNP1to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compTZNP2);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompTZNP2);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompNZOP2()

void UprCompTZNP2()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compTZNP2);
  PassWord(EditUprTZNP2);

}//UprCompTZNP2()

void EditUprTZNP2()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compTZNP2[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrTZNP2);//редактировать уставку управления
}//EditUprTZNP2()

short  KadrMenuFormat_upr_compTZNP2(void *pstr)//(WorkControl *workCntr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compTZNP2[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrTZNP2(i, getCurrentMngUSTAVKI()));

      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compTZNP2(WorkControl *workCntr)

char *selectorUprStrTZNP2(short iBit, UNS_32 ustUpr)
{
  switch(iBit)
  {

  default:
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_WKL];
    return bitStringUNI[UNIUPR_OTKL];
  }//switch
}//selectorUprStrTZNP2(short ibit, UNS_32 ustUpr)

int initUstTZNP2(char init)
{
 return initUstTZNP1(init);
}//initUstTZNP2(short mngUst, char init)

void  prepareUstTZNP2(short idxC)
{
  prepareUstTZNP1(idxC);
}//prepareUstTZNP2(short idxC)

int codecUstTZNP2(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
 return codecUstTZNP1(codec, offset, ust);
}//codecUstTZNP2(char *buf, short offset, int ust)

char diffTZNP2ToRepozitar()
{
//зарегистрировать компонент в репозитарии
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  TZNP2_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_TZNP2;//sub_menu_component;

  rpzcomponent_obj.cntClon     = CNT_STUPEN_TZNP;   //к-во клонов
  rpzcomponent_obj.numClon     = 2;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstTZNP2;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstTZNP2;//подготовка уставок

  rpzcomponent_obj.nameStatusIO = ionsTZNP2;          //имена и статус команд IO

  rpzcomponent_obj.codecUst = codecUstTZNP2;   //кодировать-раскодировать уставку

  return 0;//не пакетная регистрация
}//

#endif // _HIDE_COMPONENT

