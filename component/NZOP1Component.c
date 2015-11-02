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
#define KOD_COMPONENT  NZOP_COMP1
//к-во ступеней
#define CNT_STUPEN_NZOP  2

#endif // _HIDE_COMPONENT

//РАСПРЕДЕЛЕНИЕ УСТАВОК  в менеджере уставок
//уставка сработки
#define MNGUST_UCM_NZOP1to2    0
#define MNGUST_UCM_NZOP1to2_V  1
#define MNGUST_UCM_NZOP1to2_N  2
#define MNGUST_ICM_NZOP1to2    3
#define MNGUST_ICM_NZOP1to2_V  4
#define MNGUST_ICM_NZOP1to2_N  5

//уставка выдержки
#define MNGVID_NZOP1to2    6
#define MNGVID_NZOP1to2_V  7
#define MNGVID_NZOP1to2_N  8

//уставка управления
#define MNGUPR_NZOP1to2    9
//к-во уставок в менеджере уставок
#define MNGUST_NZOP1to2_TOTAL  10
//#define MNGUST_BOBV_NZOP1to2  MNGUST_NZOP1to2_TOTAL

//РАСПРЕДЕЛЕНИЕ ENA команд
//Простая\Направл
#define ENA_NZOP1to2_1  0
//Вкл\Откл
#define ENA_NZOP1to2_2  1
//Вперед\Назад
#define ENA_NZOP1to2_3  2
//к-во ENA команд
#define ENACMD_NZOP1to2_TOTAL 3

//РАСПРЕДЕЛЕНИЕ УСТАВОК в супервизоре
//уставка SPV сработки
#define SPVSRABUST_UCM_NZOP1to2    0
#define SPVSRABUST_UCM_NZOP1to2_V  1
#define SPVSRABUST_UCM_NZOP1to2_N  2
#define SPVSRABUST_ICM_NZOP1to2    3
#define SPVSRABUST_ICM_NZOP1to2_V  4
#define SPVSRABUST_ICM_NZOP1to2_N  5
//уставка SPV возврата
#define SPVVOZVUST_UCM_NZOP1to2    6
#define SPVVOZVUST_UCM_NZOP1to2_V  7
#define SPVVOZVUST_UCM_NZOP1to2_N  8
#define SPVVOZVUST_ICM_NZOP1to2    9
#define SPVVOZVUST_ICM_NZOP1to2_V  10
#define SPVVOZVUST_ICM_NZOP1to2_N  11
//уставка SPV выход
#define SPV_OUT_UCM_NZOP1to2       12
#define SPV_OUT_ICM_NZOP1to2       13
#define SPV_OUT_UCM_NZOP1to2_V     14
#define SPV_OUT_ICM_NZOP1to2_V     15
#define SPV_OUT_UCM_NZOP1to2_N     16
#define SPV_OUT_ICM_NZOP1to2_N     17
//к-во уставок в супервизоре
#define SPVUST_NZOP1to2_TOTAL  18

//---------------IO COMMAND------------------
//РАСПРЕДЕЛЕНИЕ IO КОМАНД ДЛЯ NZOP1to2
//Стат блок НЗОП1
#define IOCMD1_NZOP1to2 0
//Сраб ПО НЗОП1
#define IOCMD2_NZOP1to2 1
//Сраб ПО НЗОП1 ВПД
#define IOCMD3_NZOP1to2 2
//Сраб ПО НЗОП1 НЗД
#define IOCMD4_NZOP1to2 3
//Сраб НЗОП1
#define IOCMD5_NZOP1to2 4
//Сектор НЗОП1 ВПД
#define IOCMD6_NZOP1to2 5
//Сектор НЗОП1 НЗД
#define IOCMD7_NZOP1to2 6
//к-во IO команд
#define IOCMD_NZOP1to2_TOTAL    7

//---------------TL COMMAND------------------
//РАСПРЕДЕЛЕНИЕ TL КОМАНД ДЛЯ NZOP1to2
//isFAILU_INVERT
//#define TLCMD1_NZOP1to2   0
//NZOP1to2_PO2
//#define TLCMD2_NZOP1to2   1
//NZOP1to2_PO3
//#define TLCMD3_NZOP1to2   2
//isFAILUCM005_INVERT
//#define TLCMD4_NZOP1to2   3
//isFAILICM005_INVERT
//#define TLCMD5_NZOP1to2   4
//к-во TL команд
#define TLCMD_NZOP1to2_TOTAL    0

//--------------- TIMERS ------------------
//РАСПРЕДЕЛЕНИЕ ТАЙМЕРОВ ДЛЯ NZOP1to2
//таймер 0
#define TIMER1_NZOP1to2  0
//таймер 1
#define TIMER2_NZOP1to2  1
//таймер 2
#define TIMER3_NZOP1to2  2
//таймер 3 BO
#define TIMER_BO_NZOP1to2 3
//к-во таймеров
#define TIMERS_NZOP1to2_TOTAL   4

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "PRM1Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_NZOP[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//индекс уставок в супервизоре
extern int  IndexIO;//индекс IO

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern char *bitStringUNI[];
extern int offsetUstMngPRM1;//смещение на уставки PRM1

void PereinitUstListCompNZOP1(short flg);
void UstListCompNZOP1();
void ustRedactorCompNZOP1();
void UstCompNZOP1();

void PereinitVidListCompNZOP1(short flg);
void VidListCompNZOP1();
void vidRedactorCompNZOP1();
void VidCompNZOP1();

void PereinitUprListCompNZOP1(short flg);
void UprListCompNZOP1();
void uprRedactorCompNZOP1();
void UprCompNZOP1();
short  KadrMenuFormat_upr_compNZOP1(void *workCntr);
int  initUstNZOP1(char init);
void  prepareUstNZOP1(short idxC);

void EditUstNZOP1();
void EditVidNZOP1();
void EditUprNZOP1();
int codecUstNZOP1(char codec, short offset, int ust);

short  KadrMenuFormat_ustvidNZOP(void *workCntr);
char *selectorUprStrNZOP1(short iBit, UNS_32 ustUpr);
void diffNZOP2ToRepozitar();
void  logicNZOP1to2(int idxC);
int   isDISactiv_NZOP1to2(int idxC);

TWIN_DIFFERENT twinNZOP1[1];//массив контроля близнецов

int  offsetIOCmdNZOP2;//смещение для IO NZOP2

char NZOP1_TITLE[] = "НЗОП1";

IONAMESTATUS_COMPONENT ionsNZOP1[IOCMD_NZOP1to2_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок НЗОП1"
  },
  {
    1,//статус iocmd2
    "Сраб ПО НЗОП1"
  },
  {
    1,//статус iocmd3
    "Сраб ПО НЗОП1 ВПД"
  },
  {
    1,//статус iocmd4
    "Сраб ПО НЗОП1 НЗД"
  },
  {
    1,//статус iocmd5
    "Сраб НЗОП1"
  },
  {
    1,//статус iocmd6
    "Сектор НЗОП1 ВПД"
  },
  {
    1,//статус iocmd7
    "Сектор НЗОП1 НЗД"
  }
};

LineMenuItem sub_menu_comp_NZOP1[8] =
{
  { NZOP1_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_NZOP, typeMenuSub},//control_item, parent
  { "Уставки НЗОП1",    (void *)&UstListCompNZOP1, typeMenuProg},
  { "Выдержки НЗОП1",   (void *)&VidListCompNZOP1, typeMenuProg},
  { "Управление НЗОП1", (void *)&UprListCompNZOP1, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compNZOP1[] =
{
  { "Уставки НЗОП1", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_NZOP1, typeMenuList},//control_item, parent
  { "Уст НЗОП1 U2",        (void *)&UstCompNZOP1, typeMenuProg},
  { "Уст НЗОП1 U2 вперед", (void *)&UstCompNZOP1, typeMenuProg},
  { "Уст НЗОП1 U2 назад",  (void *)&UstCompNZOP1, typeMenuProg},
  { "Уст НЗОП1 I2",        (void *)&UstCompNZOP1, typeMenuProg},
  { "Уст НЗОП1 I2 вперед", (void *)&UstCompNZOP1, typeMenuProg},
  { "Уст НЗОП1 I2 назад",  (void *)&UstCompNZOP1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compNZOP1[] =
{
  { "Выдержки НЗОП1", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_NZOP1, typeMenuList},//control_item, parent
  { "Выдержка НЗОП1",        (void *)&VidCompNZOP1, typeMenuProg},
  { "Выдержка НЗОП1 вперед", (void *)&VidCompNZOP1, typeMenuProg},
  { "Выдержка НЗОП1 назад",  (void *)&VidCompNZOP1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compNZOP1[] =
{
  { "Управл НЗОП1", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_NZOP1, typeMenuList},//control_item, parent
  { "Вид НЗОП1",           (void *)&UprCompNZOP1, typeMenuProg},
  { "Управл НЗОП1",        (void *)&UprCompNZOP1, typeMenuProg},
  { "Направл НЗОП1",       (void *)&UprCompNZOP1, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompNZOP1(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidNZOP, sub_menu_ust_compNZOP1);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UstListCompNZOP1()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compNZOP1);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompNZOP1);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompNZOP1()

void UstCompNZOP1()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compNZOP1);
  PassWord(EditUstNZOP1);
}//VidCompNZOP1()

void EditUstNZOP1()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compNZOP1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompNZOP1()

short  KadrMenuFormat_ustvidNZOP(void *pstr)
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

void PereinitVidListCompNZOP1(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidNZOP, sub_menu_vid_compNZOP1);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void VidListCompNZOP1()
{
  SelectorMNGBAZA(MNGVID_NZOP1to2);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compNZOP1);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompNZOP1);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompNZOP1()

void VidCompNZOP1()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compNZOP1);
//  PassWord(EditVidAPV);
  EditVidNZOP1();
}//VidCompNZOP1()

void EditVidNZOP1()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compNZOP1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompNZOP1(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compNZOP1, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UprListCompNZOP1()
{
  SelectorMNGBAZA(MNGUPR_NZOP1to2);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compNZOP1);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompNZOP1);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompNZOP1()

void UprCompNZOP1()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compNZOP1);
  PassWord(EditUprNZOP1);

}//UprCompNZOP1()

void EditUprNZOP1()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compNZOP1[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrNZOP1);//редактировать уставку управления
}//EditUprNZOP1()

short  KadrMenuFormat_upr_compNZOP1(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compNZOP1[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      //отобразить уставку управления в кадре
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrNZOP1(i, getCurrentMngUSTAVKI()));

      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compNZOP1(WorkControl *workCntr)

char *selectorUprStrNZOP1(short iBit, UNS_32 ustUpr)
{
  switch(iBit)
  {
  case 0:
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_NAPRAVL];
    return bitStringUNI[UNIUPR_PROSTAJA];

  case 2:
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_NAZAD];
    return bitStringUNI[UNIUPR_WPERED];

  default:;
  }//switch
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_WKL];
    return bitStringUNI[UNIUPR_OTKL];
}//selectorUprStrNZOP1(short ibit, UNS_32 ustUpr)

int initUstNZOP1(char init)
{
  //инициал уставок
  if (init)
  {
//уставка сработки
    tmpUSTAVKI[MNGUST_UCM_NZOP1to2]   = 221;
    tmpUSTAVKI[MNGUST_UCM_NZOP1to2_V] = 222;
    tmpUSTAVKI[MNGUST_UCM_NZOP1to2_N] = 223;
    tmpUSTAVKI[MNGUST_ICM_NZOP1to2]   = 224;
    tmpUSTAVKI[MNGUST_ICM_NZOP1to2_V] = 225;
    tmpUSTAVKI[MNGUST_ICM_NZOP1to2_N] = 226;
//уставка выдержки
    tmpUSTAVKI[MNGVID_NZOP1to2]   = 230;
    tmpUSTAVKI[MNGVID_NZOP1to2_V] = 231;
    tmpUSTAVKI[MNGVID_NZOP1to2_N] = 232;
//уставка управления
    tmpUSTAVKI[MNGUPR_NZOP1to2] = 0;

  }//if

  IndexUstSPV += SPVUST_NZOP1to2_TOTAL;//индекс уставок в супервизоре
  return MNGUST_NZOP1to2_TOTAL;//к-во уставок в менеджере уставок
}//initUstNZOP1(short mngUst, char init)

void  prepareUstNZOP1(short idxC)
{
  //подготовка ENA команд для клона
  //копировать ENA из WideENA в ENAcmd
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_NZOP1to2), ENACMD_NZOP1to2_TOTAL);
  //подготовка уставок
  int tmpOffsetUSpv = getOffsetSPVUstCnf(idxC);//смещение уставок внутри супервизора

  //уставка SPV сработки
  int tmp1 =
    SPV_UST(SPVSRABUST_UCM_NZOP1to2) = codecUstNZOP1(1, MNGUST_UCM_NZOP1to2, getNativUstMngUSTAVKI(idxC, MNGUST_UCM_NZOP1to2));
  //уставка SPV возврата
  SPV_UST(SPVVOZVUST_UCM_NZOP1to2) = tmp1 - tmp1/20;//5%

  //уставка SPV сработки
  tmp1 =
    SPV_UST(SPVSRABUST_UCM_NZOP1to2_V) = codecUstNZOP1(1, MNGUST_UCM_NZOP1to2_V, getNativUstMngUSTAVKI(idxC, MNGUST_UCM_NZOP1to2_V));
  //уставка SPV возврата
  SPV_UST(SPVVOZVUST_UCM_NZOP1to2_V) = tmp1 - tmp1/20;//5%

  //уставка SPV сработки
  tmp1 =
    SPV_UST(SPVSRABUST_UCM_NZOP1to2_N) = codecUstNZOP1(1, MNGUST_UCM_NZOP1to2_N, getNativUstMngUSTAVKI(idxC, MNGUST_UCM_NZOP1to2_N));
  //уставка SPV возврата
  SPV_UST(SPVVOZVUST_UCM_NZOP1to2_N) = tmp1 - tmp1/20;//5%

//------------------NZD---------------------------------------------------------
  //уставка SPV сработки
  tmp1 =
    SPV_UST(SPVSRABUST_ICM_NZOP1to2) = codecUstNZOP1(1, MNGUST_ICM_NZOP1to2, getNativUstMngUSTAVKI(idxC, MNGUST_ICM_NZOP1to2));
  //уставка SPV возврата
  SPV_UST(SPVVOZVUST_ICM_NZOP1to2) = tmp1 - tmp1/20;//5%

  //уставка SPV сработки
  tmp1 =
    SPV_UST(SPVSRABUST_ICM_NZOP1to2_V) = codecUstNZOP1(1, MNGUST_ICM_NZOP1to2_V, getNativUstMngUSTAVKI(idxC, MNGUST_ICM_NZOP1to2_V));
  //уставка SPV возврата
  SPV_UST(SPVVOZVUST_ICM_NZOP1to2_V) = tmp1 - tmp1/20;//5%

  //уставка SPV сработки
  tmp1 =
    SPV_UST(SPVSRABUST_ICM_NZOP1to2_N) = codecUstNZOP1(1, MNGUST_ICM_NZOP1to2_N, getNativUstMngUSTAVKI(idxC, MNGUST_ICM_NZOP1to2_N));
  //уставка SPV возврата
  SPV_UST(SPVVOZVUST_ICM_NZOP1to2_N) = tmp1 - tmp1/20;//5%

  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //компонент в конфигурации

         //таймер 1
  setTimerPorog(tmpOffsetT+ TIMER1_NZOP1to2, 
    codecUstNZOP1(1, MNGVID_NZOP1to2, getNativUstMngUSTAVKI(idxC, MNGVID_NZOP1to2)));

          //таймер 2
  setTimerPorog(tmpOffsetT+ TIMER2_NZOP1to2, 
    codecUstNZOP1(1, MNGVID_NZOP1to2_V, getNativUstMngUSTAVKI(idxC, MNGVID_NZOP1to2_V)));

          //таймер 3
  setTimerPorog(tmpOffsetT+ TIMER3_NZOP1to2, 
    codecUstNZOP1(1, MNGVID_NZOP1to2_N, getNativUstMngUSTAVKI(idxC, MNGVID_NZOP1to2_N)));

         //таймер 4 BO
  setTimerPorog(tmpOffsetT+ TIMER_BO_NZOP1to2, 10);


}//prepareUstNZOP1(short idxC)

int initIOCmd_NZOP1()
{
  //инициал IO команд
  offsetIOCmdNZOP2 = IndexIO;//смещение для IO NZOP2
  return commonInitIOCmd(IOCMD_NZOP1to2_TOTAL);
}

int initTLCmd_NZOP1()
{
  //инициал TL команд
  return commonInitTLCmd(TLCMD_NZOP1to2_TOTAL);
}//initTLCmd_NZOP1()

int initENACmd_NZOP1()
{
  //инициал ENA команд
  return commonInitENACmd(ENACMD_NZOP1to2_TOTAL);
}//initENACmd_NZOP1()

void initTimersNZOP1(short idxC)
{
  //запрос и инициал таймеров
  commonInitTimers(TIMERS_NZOP1to2_TOTAL);
}//initTimersNZOP1()

int codecUstNZOP1(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
  //кодировать-раскодировать уставку
  int grzHI = 0;//верх граница
  int grzLOW= 0;//низ граница
  int step  = 1;//шаг
  switch(offset)
  {
    //уставки
  case MNGUST_UCM_NZOP1to2:
  case MNGUST_UCM_NZOP1to2_V:
  case MNGUST_UCM_NZOP1to2_N:
  case MNGUST_ICM_NZOP1to2:
  case MNGUST_ICM_NZOP1to2_V:
  case MNGUST_ICM_NZOP1to2_N:
    grzHI = 1000000;//верх граница
    grzLOW= 0;//низ граница
    step  = 1;//шаг
    break;

    //выдержки
//  case MNGUST_BOBV_NZOP1to2://уставка БО БВ
  case MNGVID_NZOP1to2:
  case MNGVID_NZOP1to2_V:
  case MNGVID_NZOP1to2_N:
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
}//codecUstNZOP1(char *buf, short offset, int ust)

int isDISactiv_NZOP1to2(int idxC)
{
//активность Регистратора ДИС
  return 0;//нет активности
}//isDISactiv_NZOP1to2(int idxC)

char copyNZOP1ToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//стереть старое
//копировать компонент 1 в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  NZOP1_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_NZOP1;//sub_menu_component;

  rpzcomponent_obj.twinControl = &(twinNZOP1[0]);//массив контроля близнецов
  twinNZOP1[0].twin_different = diffNZOP2ToRepozitar;//ф-ция контроля близнецов

  rpzcomponent_obj.cntClon     = CNT_STUPEN_NZOP;   //max к-во клонов
  rpzcomponent_obj.numClon     = 1;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstNZOP1;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstNZOP1;//подготовка уставок
  rpzcomponent_obj.initIOCmd      = initIOCmd_NZOP1;      //инициал IO команд
  rpzcomponent_obj.initTLCmd      = initTLCmd_NZOP1;      //инициал TL команд
  rpzcomponent_obj.initENACmd     = initENACmd_NZOP1;     //инициал ENA команд
  rpzcomponent_obj.bo_bvCmd       = NULL; //настройка БО БВ команд
  rpzcomponent_obj.isDISactiv     = isDISactiv_NZOP1to2; //активность Регистратора ДИС
  rpzcomponent_obj.setBOBVtimer   = NULL; //инициал таймеров БО БВ

  rpzcomponent_obj.nameStatusIO = ionsNZOP1;          //имена и статус команд IO
  rpzcomponent_obj.initTimers   = initTimersNZOP1;    //запрос и инициал таймеров
  rpzcomponent_obj.logic        = logicNZOP1to2;         //логика компонента

  rpzcomponent_obj.codecUst = codecUstNZOP1;   //кодировать-раскодировать уставку

  return 0;//не пакетная регистрация
}//

#endif // _HIDE_COMPONENT

