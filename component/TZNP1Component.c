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
#include "logictimers\logictimersfnc.h"

#include "virtualMenu\viewMenuList.h"

#include "psupervisor\psupervisor.h"

#include "toSpeedOptim.h"

#include "..\bazis.h"

//код компонентов
#define KOD_COMPONENT  TZNP_COMP1
//к-во ступеней
#define CNT_STUPEN_TZNP  5

#endif // _HIDE_COMPONENT

//РАСПРЕДЕЛЕНИЕ УСТАВОК  в менеджере уставок
//уставка сработки
#define MNGUST_TZNP1to5_3I0  0
#define MNGUST_TZNP1to5_3U0  1

//уставка выдержки
#define MNGVID_TZNP1to5         2
#define MNGVID_TZNP1to5_3I0     3
#define MNGVID_TZNP1to5_3U0     4
//ускорение
//Ввод ускор ТЗНП1
#define MNGVUSK_TZNP1to5        5

//Ускор ТЗНП1 ВВ
#define MNGUSK_TZNP1to5         6
//Ускор ТЗНП1 ОУ
#define MNGUSK_TZNP1to5_OU      7
//Ускор ТЗНП1 ТУ
#define MNGUSK_TZNP1to5_TU      8

//Ускор ТЗНП1 3I0 ВВ
#define MNGUSK_TZNP1to5_3I0     9
//Ускор ТЗНП1 3I0 ОУ
#define MNGUSK_TZNP1to5_3I0_OU  10
//Ускор ТЗНП1 3I0 ТУ
#define MNGUSK_TZNP1to5_3I0_TU  11

//уставка управления
#define MNGUPR_TZNP1to5      12
//к-во уставок в менеджере уставок
#define MNGUST_TZNP1to5_TOTAL  13
//#define MNGUST_BOBV_TZNP1to5  MNGUST_TZNP1to5_TOTAL

//РАСПРЕДЕЛЕНИЕ ENA команд
//Управл ТЗНП1
#define ENA1_TZNP1to5       0
//Управл ТЗНП1 3I0
#define ENA2_TZNP1to5       1
//Управл ТЗНП1 3U0
#define ENA3_TZNP1to5       2
//Направл ТЗНП1
#define ENA4_TZNP1to5       3
//Ускор ВВ ТЗНП1
#define ENA5_TZNP1to5       4
//Автомат уск ТЗНП1
#define ENA6_TZNP1to5       5
//Телеускор ТЗНП1
#define ENA7_TZNP1to5       6
//к-во ENA команд
#define ENACMD_TZNP1to5_TOTAL 7

//РАСПРЕДЕЛЕНИЕ УСТАВОК в супервизоре
//уставка сработки
#define SPVSRABUST_TZNP1to5_3I0  0
#define SPVSRABUST_TZNP1to5_3U0  1
//уставка возврата
#define SPVVOZVUST_TZNP1to5_3I0  2
#define SPVVOZVUST_TZNP1to5_3U0  3
//уставка SPV выход
#define SPV_OUT3I0_TZNP1to5      4
#define SPV_OUT3U0_TZNP1to5      5
//к-во уставок в супервизоре
#define SPVUST_TZNP1to5_TOTAL  6

//---------------IO COMMAND------------------
//РАСПРЕДЕЛЕНИЕ IO КОМАНД ДЛЯ TZNP1to5
//Стат блок ТЗНП1
//CMD_TZNP1to5
#define IOCMD1_TZNP1to5 0
//Блок уск ТЗНП1
//CMD_BLOK_USK_TZNP1to5
#define IOCMD2_TZNP1to5 1
//Опер уск ТЗНП1
//CMD_OPER_USK_TZNP1to5
#define IOCMD3_TZNP1to5 2
//Сраб ПО ТЗНП1
//CMD_TZNP1to5_PO1
#define IOCMD4_TZNP1to5 3
//Сраб ТЗНП1
//CMD_TZNP1to5
#define IOCMD5_TZNP1to5 4
//Сраб ПО ТЗНП1 3I0
//CMD_TZNP1to5_PO2
#define IOCMD6_TZNP1to5 5
//Сраб ТЗНП1 3I0
//CMD_TZNP1to5_3I0
#define IOCMD7_TZNP1to5 6
//Сраб ПО ТЗНП1 3U0
//CMD_TZNP1to5_PO3
#define IOCMD8_TZNP1to5 7
//Сраб ТЗНП1 3U0
//CMD_TZNP1to5_3U0
#define IOCMD9_TZNP1to5 8
//Теле уск TZNP1to5
#define IOCMD10_TZNP1to5  9
//Сектор TZNP1to5 
#define IOCMD11_TZNP1to5  10
//к-во IO команд
#define IOCMD_TZNP1to5_TOTAL    11

//---------------TL COMMAND------------------
//РАСПРЕДЕЛЕНИЕ TL КОМАНД ДЛЯ TZNP1
//TZNP1to5_PO1
#define TLCMD1_TZNP1to5      0
//TZNP1to5_PO2
#define TLCMD2_TZNP1to5      1
//TZNP1to5_PO3
#define TLCMD3_TZNP1to5      2
//TZNP1to5_USKOR
#define TLCMD4_TZNP1to5      3
//TZNP1to5_3I0_USKOR
#define TLCMD4_TZNP1to5_3I0  4
//RES_TZNP1to5
#define TLCMD6_TZNP1to5      5
//RES_TZNP1to5_3I0
#define TLCMD6_TZNP1to5_3I0  6

//ELOLDTRG_USKOR_TZNP1to5_OU
#define TLCMD7_TZNP1to5      7
//ELOUTTRG_USKOR_TZNP1to5_OU
#define TLCMD8_TZNP1to5      8

//ELOLDTRG_USKOR_TZNP1to5_AU
#define TLCMD9_TZNP1to5      9
//ELOUTTRG_USKOR_TZNP1to5_AU
#define TLCMD10_TZNP1to5     10

//ELOLDTRG_USKOR_TZNP1to5_TU
#define TLCMD11_TZNP1to5     11
//ELOUTTRG_USKOR_TZNP1to5_TU
#define TLCMD12_TZNP1to5     12

//ELOLDTRG_USKOR_TZNP1to5_I30_OU
#define TLCMD7_TZNP1to5_3I0  13
//ELOUTTRG_USKOR_TZNP1to5_I30_OU
#define TLCMD8_TZNP1to5_3I0  14

//ELOLDTRG_USKOR_TZNP1to5_I30_AU
#define TLCMD9_TZNP1to5_3I0  15
//ELOUTTRG_USKOR_TZNP1to5_I30_AU
#define TLCMD10_TZNP1to5_3I0 16

//ELOLDTRG_USKOR_TZNP1to5_I30_TU
#define TLCMD11_TZNP1to5_3I0 17
//ELOUTTRG_USKOR_TZNP1to5_I30_TU
#define TLCMD12_TZNP1to5_3I0 18
                         
#define TL10_TZNP1TO5        19
#define TL10_TZNP1TO5_3I0    20

#define TL7_TZNP1TO5         21
#define TL8_TZNP1TO5         22
#define TL9_TZNP1TO5         23

#define TL7_TZNP1TO5_3I0     24
#define TL8_TZNP1TO5_3I0     25
#define TL9_TZNP1TO5_3I0     26

//AU_MTZ2to5
#define TLCMD16_TZNP1to5     27
//TU_MTZ2to5               
#define TLCMD17_TZNP1to5     28
//VU_TU_MTZ2to5
#define TLCMD18_TZNP1to5     29

//OU_TZNP1to5               
#define TLCMD19_TZNP1to5     30

//к-во TL команд
#define TLCMD_TZNP1to5_TOTAL     31

//--------------- TIMERS ------------------
//РАСПРЕДЕЛЕНИЕ ТАЙМЕРОВ ДЛЯ TZNP1
//таймер TZNP1to5_TIM1
#define TIMER1_TZNP1to5        0
//таймер TZNP1to5_TIM2
#define TIMER2_TZNP1to5        1
//таймер TZNP1to5_TIM3
#define TIMER3_TZNP1to5        2

//Ввод ускор ТЗНП1
#define TIMER_VUSK_TZNP1to5    3

//Ускор ТЗНП1 ВВ
#define TIMER4_TZNP1to5         4
//Ускор ТЗНП1 ОУ
#define TIMER4_TZNP1to5_OU      5
//Ускор ТЗНП1 ТУ
#define TIMER4_TZNP1to5_TU      6

//Ускор ТЗНП1 3I0 ВВ
#define TIMER4_TZNP1to5_3I0     7
//Ускор ТЗНП1 3I0 ОУ
#define TIMER4_TZNP1to5_3I0_OU  8
//Ускор ТЗНП1 3I0 ТУ
#define TIMER4_TZNP1to5_3I0_TU  9

//таймер BO_TZNP1to5_TIM
#define TIMER_BO_TZNP1to5       10
//таймер BO_TZNP1to5_3I0_TIM
#define TIMER_BO_TZNP1to5_3I0   11
//таймер BO_TZNP1to5_3U0_TIM
#define TIMER_BO_TZNP1to5_3U0   12
//к-во таймеров
#define TIMERS_TZNP1to5_TOTAL   13

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "PRM1Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_TZNP[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//индекс уставок в супервизоре
extern int  IndexIO;//индекс IO

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern char *bitStringUNI[];
extern int offsetUstMngPRM1;//смещение на уставки PRM1

void UstListCompTZNP1();
void ustRedactorCompTZNP1();
void UstCompTZNP1();

void PereinitVidListCompTZNP1(short flg);
void VidListCompTZNP1();
void vidRedactorCompTZNP1();
void VidCompTZNP1();

void PereinitUprListCompTZNP1(short flg);
void UprListCompTZNP1();
void uprRedactorCompTZNP1();
void UprCompTZNP1();
short  KadrMenuFormat_upr_compTZNP1(void *workCntr);
int  initUstTZNP1(char init);
void  prepareUstTZNP1(short idxC);

short  KadrMenuFormat_TZNP1(void *workCntr);

void EditUstTZNP1();
void EditVidTZNP1();
void EditUprTZNP1();
int codecUstTZNP1(char codec, short offset, int ust);
char *selectorUprStrTZNP1(short iBit, UNS_32 ustUpr);

short  KadrMenuFormat_ustvidTZNP(void *workCntr);
void  logicTZNP1to5(int idxC);
int   isDISactiv_TZNP1to5(int idxC);

void diffTZNP2ToRepozitar();
void diffTZNP3ToRepozitar();
void diffTZNP4ToRepozitar();
void diffTZNP5ToRepozitar();
TWIN_DIFFERENT twinTZNP1[4];//массив контроля близнецов

int  offsetIOCmdTZNP5;//смещение для IO TZNP5

char TZNP1_TITLE[] = "ТЗНП1";

IONAMESTATUS_COMPONENT ionsTZNP1[IOCMD_TZNP1to5_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок ТЗНП1"
  },
  {
    1,//статус iocmd2
    "Блок уск ТЗНП1"
  },
  {
    1,//статус iocmd3
    "Опер уск ТЗНП1"
  },
  {
    1,//статус iocmd4
    "Сраб ПО ТЗНП1"
  },
  {
    1,//статус iocmd5
    "Сраб ТЗНП1"
  },
  {
    1,//статус iocmd6
    "Сраб ПО ТЗНП1 3I0"
  },
  {
    1,//статус iocmd7
    "Сраб ТЗНП1 3I0"
  },
  {
    1,//статус iocmd8
    "Сраб ПО ТЗНП1 3U0"
  },
  {
    1,//статус iocmd9
    "Сраб ТЗНП1 3U0"
  },
  {
    1,//статус iocmd10
    "Теле уск ТЗНП1"
  },
  {
    1,//статус iocmd11
    "Сектор ТЗНП1"
  }
};

LineMenuItem sub_menu_comp_TZNP1[8] =
{
  { TZNP1_TITLE, NULL},//title
  { &CONTROL1_COMP,  &sub_menu_TZNP, typeMenuSub},//control_item, parent
  { "Уставки ТЗНП1",    (void*)&UstListCompTZNP1, typeMenuProg},
  { "Выдержки ТЗНП1",   (void*)&VidListCompTZNP1, typeMenuProg},
  { "Управление ТЗНП1", (void*)&UprListCompTZNP1, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compTZNP1[] =
{
  { "Уставки ТЗНП1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_TZNP1, typeMenuList},//control_item, parent
  { "Уст ТЗНП1 3I0",    (void*)&UstCompTZNP1, typeMenuProg},
  { "Уст ТЗНП1 3U0",    (void*)&UstCompTZNP1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compTZNP1[] =
{
  { "Выдержки ТЗНП1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_TZNP1, typeMenuList},//control_item, parent
/*
  { "Выдержка ТЗНП1",         (void*)&VidCompTZNP1, typeMenuProg},
  { "Выдержка ТЗНП1 3I0",     (void*)&VidCompTZNP1, typeMenuProg},
  { "Выдержка ТЗНП1 3U0",     (void*)&VidCompTZNP1, typeMenuProg},
  { "Ввод ускор ТЗНП1",       (void*)&VidCompTZNP1, typeMenuProg},

  { "Ускор ТЗНП1 ВВ",         (void*)&VidCompTZNP1, typeMenuProg},
  { "Ускор ТЗНП1 ОУ",         (void*)&VidCompTZNP1, typeMenuProg},
  { "Ускор ТЗНП1 ТУ",         (void*)&VidCompTZNP1, typeMenuProg},

  { "Ускор ТЗНП1 3I0 ВВ",     (void*)&VidCompTZNP1, typeMenuProg},
  { "Ускор ТЗНП1 3I0 ОУ",     (void*)&VidCompTZNP1, typeMenuProg},
  { "Ускор ТЗНП1 3I0 ТУ",     (void*)&VidCompTZNP1, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compTZNP1[] =
{
  { "Управл ТЗНП1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_TZNP1, typeMenuList},//control_item, parent
  { "Управл ТЗНП1",        (void*)&UprCompTZNP1, typeMenuProg},
  { "Управл ТЗНП1 3I0",    (void*)&UprCompTZNP1, typeMenuProg},
  { "Управл ТЗНП1 3U0",    (void*)&UprCompTZNP1, typeMenuProg},
  { "Направл ТЗНП1",       (void*)&UprCompTZNP1, typeMenuProg},
  { "Ускор ВВ ТЗНП1",      (void*)&UprCompTZNP1, typeMenuProg},
  { "Автомат уск ТЗНП1",   (void*)&UprCompTZNP1, typeMenuProg},
  { "Телеускор ТЗНП1",     (void*)&UprCompTZNP1, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompTZNP1(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_ust_compTZNP1);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UstListCompTZNP1()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compTZNP1);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompTZNP1);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompTZNP1()

void UstCompTZNP1()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compTZNP1);
  PassWord(EditUstTZNP1);
}//VidCompTZNP1()

void EditUstTZNP1()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compTZNP1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompTZNP1()

short  KadrMenuFormat_ustvidTZNP(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  char locTxt[50];
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    if(((LineMenuItem *)workCntr->userPoint)[i+1+SUBDATA].Line1==NULL)break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, (char *)( ((LineMenuItem *)workCntr->userPoint) )[i+1+SUBDATA].Line1);
      sprintf(locTxt, "   %d", getUstOffsetMngUSTAVKI(i));
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, locTxt);
      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_ust_1(WorkControl *workCntr)

//--------------------------------------------------

void PereinitVidListCompTZNP1(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_vid_compTZNP1);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void VidListCompTZNP1()
{
  SelectorMNGBAZA(MNGVID_TZNP1to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compTZNP1);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompTZNP1);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompTZNP1()

void VidCompTZNP1()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compTZNP1);
//  PassWord(EditVidAPV);
  EditVidTZNP1();
}//VidCompTZNP1()

void EditVidTZNP1()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compTZNP1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompTZNP1(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compTZNP1, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstList

void UprListCompTZNP1()
{
  SelectorMNGBAZA(MNGUPR_TZNP1to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compTZNP1);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompTZNP1);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompNZOP1()

void UprCompTZNP1()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compTZNP1);
  PassWord(EditUprTZNP1);

}//UprCompTZNP1()

void EditUprTZNP1()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compTZNP1[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrTZNP1);//редактировать уставку управления
}//EditUprTZNP1()

short  KadrMenuFormat_upr_compTZNP1(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compTZNP1[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      //отобразить уставку управления в кадре
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrTZNP1(i, getCurrentMngUSTAVKI()));

      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compTZNP1(WorkControl *workCntr)

char *selectorUprStrTZNP1(short iBit, UNS_32 ustUpr)
{
  switch(iBit)
  {

  default:;
  }//switch
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_WKL];
    return bitStringUNI[UNIUPR_OTKL];
}//selectorUprStrTZNP1(short ibit, UNS_32 ustUpr)

int initUstTZNP1(char init)
{
  //инициал уставок
  if (init)
  {
//уставка сработки
    tmpUSTAVKI[MNGUST_TZNP1to5_3I0]   = 10;
    tmpUSTAVKI[MNGUST_TZNP1to5_3U0]   = 20;
//уставка выдержки
    tmpUSTAVKI[MNGVID_TZNP1to5]        = 40;
    tmpUSTAVKI[MNGVID_TZNP1to5_3I0]    = 41;
    tmpUSTAVKI[MNGVID_TZNP1to5_3U0]    = 42;
//ускорение
	//Ввод ускор ТЗНП1
    tmpUSTAVKI[MNGVUSK_TZNP1to5]       = 43;

	//Ускор ТЗНП1 ВВ
    tmpUSTAVKI[MNGUSK_TZNP1to5]        = 44;
	//Ускор ТЗНП1 ОУ
    tmpUSTAVKI[MNGUSK_TZNP1to5_OU]     = 45;
	//Ускор ТЗНП1 ТУ
    tmpUSTAVKI[MNGUSK_TZNP1to5_TU]     = 46;

	//Ускор ТЗНП1 3I0 ВВ
    tmpUSTAVKI[MNGUSK_TZNP1to5_3I0]    = 47;
	//Ускор ТЗНП1 3I0 ОУ
    tmpUSTAVKI[MNGUSK_TZNP1to5_3I0_OU] = 48;
	//Ускор ТЗНП1 3I0 ТУ
    tmpUSTAVKI[MNGUSK_TZNP1to5_3I0_TU] = 49;
//уставка управления
    tmpUSTAVKI[MNGUPR_TZNP1to5] = 0;

  }//if

  IndexUstSPV += SPVUST_TZNP1to5_TOTAL;//индекс уставок в супервизоре
  return MNGUST_TZNP1to5_TOTAL;//к-во уставок в менеджере уставок
}//initUstMTZ1(short mngUst, char init)

void  prepareUstTZNP1(short idxC)
{
  //подготовка ENA команд для клона
  //копировать ENA из WideENA в ENAcmd
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_TZNP1to5), ENACMD_TZNP1to5_TOTAL);
  //подготовка уставок
  int tmpOffsetUSpv = getOffsetSPVUstCnf(idxC);//смещение уставок внутри супервизора

    //уставка SPV сработки 3I0
    int tmp1 = 
    SPV_UST(SPVSRABUST_TZNP1to5_3I0) = codecUstTZNP1(1, MNGUST_TZNP1to5_3I0, getNativUstMngUSTAVKI(idxC, MNGUST_TZNP1to5_3I0));
    //уставка SPV возврата 3I0
    SPV_UST(SPVVOZVUST_TZNP1to5_3I0) = tmp1 - tmp1/20;//5%

    //уставка SPV сработки 3U0
    tmp1 = 
    SPV_UST(SPVSRABUST_TZNP1to5_3U0) = codecUstTZNP1(1, MNGUST_TZNP1to5_3U0, getNativUstMngUSTAVKI(idxC, MNGUST_TZNP1to5_3U0));
    //уставка SPV возврата 3U0
    SPV_UST(SPVVOZVUST_TZNP1to5_3U0) = tmp1 - tmp1/20;//5%

  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //компонент в конфигурации

        //таймер TZNP1to5_TIM1
  setTimerPorog(tmpOffsetT+ TIMER1_TZNP1to5, 
          codecUstTZNP1(1, MNGVID_TZNP1to5, getNativUstMngUSTAVKI(idxC, MNGVID_TZNP1to5)));
        //таймер TZNP1to5_TIM2
  setTimerPorog(tmpOffsetT+ TIMER2_TZNP1to5,
          codecUstTZNP1(1, MNGVID_TZNP1to5_3I0, getNativUstMngUSTAVKI(idxC, MNGVID_TZNP1to5_3I0)));
         //таймер TZNP1to5_TIM3
  setTimerPorog(tmpOffsetT+ TIMER3_TZNP1to5,
          codecUstTZNP1(1, MNGVID_TZNP1to5_3U0, getNativUstMngUSTAVKI(idxC, MNGVID_TZNP1to5_3U0)));

//Ввод ускор ТЗНП1
  setTimerPorog(tmpOffsetT+ TIMER_VUSK_TZNP1to5,
          codecUstTZNP1(1, MNGVUSK_TZNP1to5, getNativUstMngUSTAVKI(idxC, MNGVUSK_TZNP1to5)));

//Ускор ТЗНП1 ВВ
  int tmp =        codecUstTZNP1(1, MNGUSK_TZNP1to5, getNativUstMngUSTAVKI(idxC, MNGUSK_TZNP1to5));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER4_TZNP1to5, tmp);
//Ускор ТЗНП1 ОУ
  tmp =        codecUstTZNP1(1, MNGUSK_TZNP1to5_OU, getNativUstMngUSTAVKI(idxC, MNGUSK_TZNP1to5_OU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER4_TZNP1to5_OU, tmp);
//Ускор ТЗНП1 ТУ
  tmp =        codecUstTZNP1(1, MNGUSK_TZNP1to5_TU, getNativUstMngUSTAVKI(idxC, MNGUSK_TZNP1to5_TU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER4_TZNP1to5_TU, tmp);

//Ускор ТЗНП1 3I0 ВВ
  tmp =        codecUstTZNP1(1, MNGUSK_TZNP1to5_3I0, getNativUstMngUSTAVKI(idxC, MNGUSK_TZNP1to5_3I0));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER4_TZNP1to5_3I0, tmp);
//Ускор ТЗНП1 3I0 ОУ
  tmp =        codecUstTZNP1(1, MNGUSK_TZNP1to5_3I0_OU, getNativUstMngUSTAVKI(idxC, MNGUSK_TZNP1to5_3I0_OU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER4_TZNP1to5_3I0_OU, tmp);
//Ускор ТЗНП1 3I0 ТУ
  tmp =        codecUstTZNP1(1, MNGUSK_TZNP1to5_3I0_TU, getNativUstMngUSTAVKI(idxC, MNGUSK_TZNP1to5_3I0_TU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER4_TZNP1to5_3I0_TU, tmp);

         //таймер BO_TZNP1to5_TIM
  setTimerPorog(tmpOffsetT+ TIMER_BO_TZNP1to5, 10);
      //таймер BO_TZNP1to5_3I0_TIM
  setTimerPorog(tmpOffsetT+ TIMER_BO_TZNP1to5_3I0, 10);
       //таймер BO_TZNP1to5_3U0_TIM
  setTimerPorog(tmpOffsetT+ TIMER_BO_TZNP1to5_3U0, 10);
}//prepareUstTZNP1(short idxC)

int initIOCmd_TZNP1()
{
  //инициал IO команд
  offsetIOCmdTZNP5 = IndexIO;//смещение для IO TZNP5
  return commonInitIOCmd(IOCMD_TZNP1to5_TOTAL);
}

int initTLCmd_TZNP1()
{
  //инициал TL команд
  return commonInitTLCmd(TLCMD_TZNP1to5_TOTAL);
}//initTLCmd_TZNP1()

int initENACmd_TZNP1()
{
  //инициал ENA команд
  return commonInitENACmd(ENACMD_TZNP1to5_TOTAL);
}//initENACmd_TZNP1()

void initTimersTZNP1(short idxC)
{
  //запрос и инициал таймеров
  commonInitTimers(TIMERS_TZNP1to5_TOTAL);
}//initTimersTZNP1()

int codecUstTZNP1(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
int grzHI = 0;//верх граница
int grzLOW= 0;//низ граница
int step  = 1;//шаг
  switch(offset)
  {
   //уставки
   case MNGUST_TZNP1to5_3I0:
   case MNGUST_TZNP1to5_3U0:
       grzHI = 1000000;//верх граница
       grzLOW= 0;//низ граница
       step  = 1;//шаг
   break;

  //выдержки
//   case MNGUST_BOBV_TZNP1to5://уставка БО БВ
   case MNGVID_TZNP1to5:
   case MNGVID_TZNP1to5_3I0:
   case MNGVID_TZNP1to5_3U0:
   case MNGVUSK_TZNP1to5:
   case MNGUSK_TZNP1to5:
   case MNGUSK_TZNP1to5_OU:
   case MNGUSK_TZNP1to5_TU:
   case MNGUSK_TZNP1to5_3I0:
   case MNGUSK_TZNP1to5_3I0_OU:
   case MNGUSK_TZNP1to5_3I0_TU:
       grzHI = 2000000;//верх граница
       grzLOW= 0;//низ граница
       step  = 1;//шаг
   break;

   default:return ust;//уставка управления
  }//switch

  if(codec) return ust*step;
//раскодировать уставку
  if(ust<grzLOW) return ERROR_UST;//-ust;
  if(ust>grzHI)  return ERROR_UST;//-ust;
  return ust/step;
}//codecUstTZNP1(char *buf, short offset, int ust)

int isDISactiv_TZNP1to5(int idxC)
{
 //активность Регистратора ДИС
  return 0;//нет активности
}//isDISactiv_TZNP1to5(int idxC)

char copyTZNP1ToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//стереть старое
//копировать компонент в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.packet = 0;    //номер пакетного компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  TZNP1_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_TZNP1;//меню компонента

  rpzcomponent_obj.cntClon     = CNT_STUPEN_TZNP;   //max к-во клонов
  rpzcomponent_obj.numClon     = 1;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.twinControl = &(twinTZNP1[0]);//массив контроля близнецов
  twinTZNP1[0].twin_different = diffTZNP2ToRepozitar;//ф-ция контроля близнецов
  twinTZNP1[1].twin_different = diffTZNP3ToRepozitar;//ф-ция контроля близнецов
  twinTZNP1[2].twin_different = diffTZNP4ToRepozitar;//ф-ция контроля близнецов
  twinTZNP1[3].twin_different = diffTZNP5ToRepozitar;//ф-ция контроля близнецов

  rpzcomponent_obj.initUstMng     = initUstTZNP1;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstTZNP1;//подготовка уставок
  rpzcomponent_obj.initIOCmd      = initIOCmd_TZNP1;      //инициал IO команд
  rpzcomponent_obj.initTLCmd      = initTLCmd_TZNP1;      //инициал TL команд
  rpzcomponent_obj.initENACmd     = initENACmd_TZNP1;     //инициал ENA команд
  rpzcomponent_obj.bo_bvCmd       = NULL; //настройка БО БВ команд
  rpzcomponent_obj.isDISactiv     = isDISactiv_TZNP1to5; //активность Регистратора ДИС
  rpzcomponent_obj.setBOBVtimer   = NULL; //инициал таймеров БО БВ

  rpzcomponent_obj.nameStatusIO = ionsTZNP1;          //имена и статус команд IO
  rpzcomponent_obj.initTimers   = initTimersTZNP1;    //запрос и инициал таймеров
  rpzcomponent_obj.logic        = logicTZNP1to5;         //логика компонента

  rpzcomponent_obj.codecUst = codecUstTZNP1;   //кодировать-раскодировать уставку

  return 0;//не пакетная регистрация
}//

#endif // _HIDE_COMPONENT

