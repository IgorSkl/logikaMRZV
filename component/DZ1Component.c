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

#include "zonaVRT\zonaVRTdef.h"
#include "zonaVRT\zonaVRTfnc.h"

//код компонентов
#define KOD_COMPONENT  DZ_COMP1
//к-во ступеней
#define CNT_STUPEN_DZ  5

#endif // _HIDE_COMPONENT

//РАСПРЕДЕЛЕНИЕ УСТАВОК  в менеджере уставок
//уставка OF
#define MNGUST_DZ1_OX1  0
#define MNGUST_DZ1_OY1  1
#define MNGUST_DZ1_OX2  2
#define MNGUST_DZ1_OY2  3
#define MNGUST_DZ1_OX3  4
#define MNGUST_DZ1_OY3  5
#define MNGUST_DZ1_OX4  6
#define MNGUST_DZ1_OY4  7

//уставка MF
#define MNGUST_DZ1_MX1  8
#define MNGUST_DZ1_MY1  9
#define MNGUST_DZ1_MX2  10
#define MNGUST_DZ1_MY2  11
#define MNGUST_DZ1_MX3  12
#define MNGUST_DZ1_MY3  13
#define MNGUST_DZ1_MX4  14
#define MNGUST_DZ1_MY4  15

//MTZ DZ1
#define MNGUST_DZ1_MTZ  16

//уставка выдержки
#define MNGVID_DZ1MF   17
#define MNGVID_MDZ1MF  18
#define MNGVID_DZ1OF   19

//уставка управления
#define MNGUPR_DZ1     20
//к-во уставок в менеджере уставок
#define MNGUST_DZ1_TOTAL  21
//#define MNGUST_BOBV_DZ1  MNGUST_DZ1_TOTAL

//РАСПРЕДЕЛЕНИЕ УСТАВОК  УПРАВЛЕНИЯ
//ENA_DZ1
#define ENA_DZ1_1  0
//ENA_MDZ1MF
#define ENA_DZ1_2  1
//к-во ENA команд
#define ENACMD_DZ1_TOTAL 2

//РАСПРЕДЕЛЕНИЕ УСТАВОК в супервизоре
//уставка сработки
#define SPVSRAB_DZ1_MTZ    0
//уставка возврата
#define SPVVOZV_DZ1_MTZ    1

//уставка SPV выход
#define SPV_OUTA_DZ1_MTZ   2          
#define SPV_OUTB_DZ1_MTZ   3
#define SPV_OUTC_DZ1_MTZ   4
//к-во уставок в супервизоре
#define SPVUST_DZ1_TOTAL   5

//---------------IO COMMAND------------------
//РАСПРЕДЕЛЕНИЕ IO КОМАНД ДЛЯ DZ1
//Стат блок ДЗ1
#define IOCMD1_DZ1 0
//Сраб ПО ДЗ1МФ
#define IOCMD2_DZ1 1
//Сраб ДЗ1МФ
#define IOCMD3_DZ1 2
//Сраб ПО МТЗ ДЗ1МФ
#define IOCMD4_DZ1 3
//Сраб МТЗ ДЗ1МФ
#define IOCMD5_DZ1 4
//Сраб ПО ДЗ1ОФ
#define IOCMD6_DZ1 5
//Сраб ДЗ1ОФ
#define IOCMD7_DZ1 6
//к-во IO команд
#define IOCMD_DZ1_TOTAL   7

//---------------TL COMMAND------------------
//РАСПРЕДЕЛЕНИЕ TL КОМАНД ДЛЯ DZ1
//ELOLDTRG_NCN_DZ1MF
#define TLCMDOLDNCN_DZ1MF  0
//ELOUTTRG_NCN_DZ1MF
#define TLCMDOUTNCN_DZ1MF  1
//ELOLDTRG_NCN_DZ1OF
#define TLCMDOLDNCN_DZ1OF  2
//ELOUTTRG_NCN_DZ1OF
#define TLCMDOUTNCN_DZ1OF  3
//ELOLDTRG_NCN_MDZ1MF
#define TLCMDOLDNCN_MDZ1MF 4
//ELOUTTRG_NCN_MDZ1MF
#define TLCMDOUTNCN_MDZ1MF 5

//DZ1_PO1
#define TLCMD30_DZ1MF      6
//DZ1_PO3
#define TLCMD30_DZ1OF      7

//к-во TL команд
#define TLCMD_DZ1_TOTAL    8

//--------------- TIMERS ------------------
//РАСПРЕДЕЛЕНИЕ ТАЙМЕРОВ ДЛЯ DZ1
//таймер DZ1_TIM1
#define TIMER1_DZ1   0
//таймер BO DZ1_TIM1
#define TIMER1_BODZ1 1
//таймер DZ1_TIM2
#define TIMER2_DZ1   2
//таймер BO DZ1_TIM2
#define TIMER2_BODZ1 3
//таймер DZ1_TIM3
#define TIMER3_DZ1   4
//таймер BO DZ1_TIM3
#define TIMER3_BODZ1 5
//к-во таймеров
#define TIMERS_DZ1_TOTAL   6

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "PRM1Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_DZ[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//индекс уставок в супервизоре
extern int  IndexIO;//индекс IO

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern char *bitStringUNI[];
extern int offsetUstMngPRM1;//смещение на уставки PRM1
extern int isTriangleZonaBD[];//зона ДЗ треугольник-четырехугольник

void PereinitUstListCompMTZ1(short flg);
void UstListCompDZ1();
void ustRedactorCompDZ1();
void UstCompDZ1();

void PereinitVidListCompDZ1(short flg);
void VidListCompDZ1();
void vidRedactorCompDZ1();
void VidCompDZ1();

void PereinitUprListCompDZ1(short flg);
void UprListCompDZ1();
void uprRedactorCompDZ1();
void UprCompDZ1();
short  KadrMenuFormat_upr_compDZ1(void *workCntr);
int  initUstDZ1(char init);
void  prepareUstDZ1(short idxC);
char *selectorUprStrDZ1(short iBit, UNS_32 ustUpr);

short  KadrMenuFormat_DZ1(void *workCntr);
short  KadrMenuFormat_ustvidDZ(void *workCntr);

void EditUprDZ1();
void EditVidDZ1();
void EditUstDZ1();
int codecUstDZ1(char codec, short offset, int ust);
void  logicDZ1(int idxC);
int   isDISactiv_DZ1(int idxC);

int  offsetIOCmdDZ1;//смещение для IO DZ1
int isValidZonaDZ1OF;//флаг валидности зоны
int isValidZonaDZ1MF;//флаг валидности зоны

char DZ1_TITLE[] = "ДЗ1";

IONAMESTATUS_COMPONENT ionsDZ1[IOCMD_DZ1_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок ДЗ1"
  },
  {
    1,//статус iocmd2
    "Сраб ПО ДЗ1МФ"
  },
  {
    1,//статус iocmd3
    "Сраб ДЗ1МФ"
  },
  {
    1,//статус iocmd4
    "Сраб ПО МТЗ ДЗ1МФ"
  },
  {
    1,//статус iocmd5
    "Сраб МТЗ ДЗ1МФ"
  },
  {
    1,//статус iocmd6
    "Сраб ПО ДЗ1ОФ"
  },
  {
    1,//статус iocmd7
    "Сраб ДЗ1ОФ"
  }
};

LineMenuItem sub_menu_comp_DZ1[8] =
{
  { DZ1_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_DZ, typeMenuSub},//control_item, parent
  { "Уставки ДЗ1",    (void *)&UstListCompDZ1, typeMenuProg},
  { "Выдержки ДЗ1",   (void *)&VidListCompDZ1, typeMenuProg},
  { "Управление ДЗ1", (void *)&UprListCompDZ1, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compDZ1[] =
{
  { "Уставки ДЗ1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_DZ1, typeMenuList},//control_item, parent
//  { "Уст ДЗ1",        (void *)&UstCompDZ1, typeMenuProg},
//  { "Уст ДЗ1 вперед", (void *)&UstCompDZ1, typeMenuProg},
 // { "Уст ДЗ1 назад",  (void *)&UstCompDZ1, typeMenuProg},
//  { "Уст ДЗ1 ПМ",     (void *)&UstCompDZ1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compDZ1[] =
{
  { "Выдержки ДЗ1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_DZ1, typeMenuList},//control_item, parent
//  { "Выдержка ДЗ1МФ",     (void *)&VidCompDZ1, typeMenuProg},
//  { "Выдержка МТЗ ДЗ1МФ", (void *)&VidCompDZ1, typeMenuProg},
//  { "Выдержка ДЗ1ОФ",     (void *)&VidCompDZ1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compDZ1[] =
{
  { "Управл ДЗ1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_DZ1, typeMenuList},//control_item, parent
//  { "Управл ДЗ1",        (void *)&UprCompDZ1, typeMenuProg},
//  { "Управл МТЗ ДЗ1",    (void *)&UprCompDZ1, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompDZ1(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidDZ, sub_menu_ust_compDZ1);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UstListCompDZ1()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compDZ1);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompDZ1);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompDZ1()

void UstCompDZ1()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compDZ1);
  PassWord(EditUstDZ1);
}//VidCompDZ1()

void EditUstDZ1()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compDZ1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompDZ1()

short  KadrMenuFormat_ustvidDZ(void *pstr)
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

void PereinitVidListCompDZ1(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidDZ, sub_menu_vid_compDZ1);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void VidListCompDZ1()
{
  SelectorMNGBAZA(MNGVID_DZ1MF);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compDZ1);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompDZ1);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompDZ1()

void VidCompDZ1()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compDZ1);
//  PassWord(EditVidAPV);
  EditVidDZ1();
}//VidCompDZ1()

void EditVidDZ1()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compDZ1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompDZ1(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compDZ1, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstList

void UprListCompDZ1()
{
  SelectorMNGBAZA(MNGUPR_DZ1);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compDZ1);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompDZ1);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompDZ1()

void UprCompDZ1()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compDZ1);
  PassWord(EditUprDZ1);

}//UprCompMTZ1()

void EditUprDZ1()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compDZ1[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrDZ1);//редактировать уставку управления
}//EditUprDZ1()

short  KadrMenuFormat_upr_compDZ1(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compDZ1[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      //отобразить уставку управления в кадре
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrDZ1(i, getCurrentMngUSTAVKI()));

      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compDZ1(WorkControl *workCntr)

char *selectorUprStrDZ1(short iBit, UNS_32 ustUpr)
{
  switch(iBit)
  {

  default:;
  }//switch
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_WKL];
    return bitStringUNI[UNIUPR_OTKL];
}//selectorUprStrDZ1(short ibit, UNS_32 ustUpr)

int initUstDZ1(char init)
{
  //инициал уставок
  if (init)
  {
//уставка сработки
    tmpUSTAVKI[MNGUST_DZ1_OX1] = 100;
    tmpUSTAVKI[MNGUST_DZ1_OY1] = 101;
    tmpUSTAVKI[MNGUST_DZ1_OX2] = 102;
    tmpUSTAVKI[MNGUST_DZ1_OY2] = 103;
    tmpUSTAVKI[MNGUST_DZ1_OX3] = 104;
    tmpUSTAVKI[MNGUST_DZ1_OY3] = 105;
    tmpUSTAVKI[MNGUST_DZ1_OX4] = 106;
    tmpUSTAVKI[MNGUST_DZ1_OY4] = 107;

    tmpUSTAVKI[MNGUST_DZ1_MX1] = 110;
    tmpUSTAVKI[MNGUST_DZ1_MY1] = 111;
    tmpUSTAVKI[MNGUST_DZ1_MX2] = 112;
    tmpUSTAVKI[MNGUST_DZ1_MY2] = 113;
    tmpUSTAVKI[MNGUST_DZ1_MX3] = 114;
    tmpUSTAVKI[MNGUST_DZ1_MY3] = 115;
    tmpUSTAVKI[MNGUST_DZ1_MX4] = 116;
    tmpUSTAVKI[MNGUST_DZ1_MY4] = 117;

    tmpUSTAVKI[MNGUST_DZ1_MTZ] = 118;
//уставка выдержки
    tmpUSTAVKI[MNGVID_DZ1MF]  = 50;
    tmpUSTAVKI[MNGVID_MDZ1MF] = 60;
    tmpUSTAVKI[MNGVID_DZ1OF]  = 70;
//уставка управления
    tmpUSTAVKI[MNGUPR_DZ1] = 0;

  }//if

  IndexUstSPV += SPVUST_DZ1_TOTAL;//индекс уставок в супервизоре
  return MNGUST_DZ1_TOTAL;//к-во уставок в менеджере уставок
}//initUstMTZ1(short mngUst, char init)

//координаты вершин зоны сработки
extern float X1, Y1, X2, Y2;
extern float X3, Y3, X4, Y4;
/*
extern float X1OF_DZ1, Y1OF_DZ1, X2OF_DZ1, Y2OF_DZ1;
extern float X3OF_DZ1, Y3OF_DZ1, X4OF_DZ1, Y4OF_DZ1;

extern float X1MF_DZ1, Y1MF_DZ1, X2MF_DZ1, Y2MF_DZ1;
extern float X3MF_DZ1, Y3MF_DZ1, X4MF_DZ1, Y4MF_DZ1;
*/

void  prepareUstDZ1(short idxC)
{
float diskr = 0.001;
  //подготовка зоны и проверка на валидность
 int ust = codecUstDZ1(1, MNGUST_DZ1_OX1, getNativUstMngUSTAVKI(idxC, MNGUST_DZ1_OX1));
 X1 = ((float)ust)*diskr;
 ust = codecUstDZ1(1, MNGUST_DZ1_OY1, getNativUstMngUSTAVKI(idxC, MNGUST_DZ1_OY1));
 Y1 = ((float)ust)*diskr;

 ust = codecUstDZ1(1, MNGUST_DZ1_OX2, getNativUstMngUSTAVKI(idxC, MNGUST_DZ1_OX2));
 X2 = ((float)ust)*diskr;
 ust = codecUstDZ1(1, MNGUST_DZ1_OY2, getNativUstMngUSTAVKI(idxC, MNGUST_DZ1_OY2));
 Y2 = ((float)ust)*diskr;

int ustx3 =
 ust = codecUstDZ1(1, MNGUST_DZ1_OX3, getNativUstMngUSTAVKI(idxC, MNGUST_DZ1_OX3));
 X3 = ((float)ust)*diskr;
int usty3 =
 ust = codecUstDZ1(1, MNGUST_DZ1_OY3, getNativUstMngUSTAVKI(idxC, MNGUST_DZ1_OY3));
 Y3 = ((float)ust)*diskr;

int ustx4 =
 ust = codecUstDZ1(1, MNGUST_DZ1_OX4, getNativUstMngUSTAVKI(idxC, MNGUST_DZ1_OX4));
 X4 = ((float)ust)*diskr;
int usty4 =
 ust = codecUstDZ1(1, MNGUST_DZ1_OY4, getNativUstMngUSTAVKI(idxC, MNGUST_DZ1_OY4));
 Y4 = ((float)ust)*diskr;
 //проверка треугольник или четырехугольник
 isTriangleZonaBD[0] = 0;//зона ДЗ четырехугольник
 if(ustx3==ustx4 && usty3==usty4) isTriangleZonaBD[0] = 1;//зона ДЗ треугольник
 if(isTriangleZonaBD[0]) isValidZonaDZ1OF = isZonaTrianMethodVRT( 0);//флаг валидности зоны
 else isValidZonaDZ1OF = isNewZonaMethodVRT( 0);//флаг валидности зоны
 
// X1=X1MF_DZ1; Y1=Y1MF_DZ1; X2=X2MF_DZ1; Y2=Y2MF_DZ1;
// X3=X3MF_DZ1; Y3=Y3MF_DZ1; X4=X4MF_DZ1; Y4=Y4MF_DZ1;
 ust = codecUstDZ1(1, MNGUST_DZ1_MX1, getNativUstMngUSTAVKI(idxC, MNGUST_DZ1_MX1));
 X1 = ((float)ust)*diskr;
 ust = codecUstDZ1(1, MNGUST_DZ1_MY1, getNativUstMngUSTAVKI(idxC, MNGUST_DZ1_MY1));
 Y1 = ((float)ust)*diskr;

 ust = codecUstDZ1(1, MNGUST_DZ1_MX2, getNativUstMngUSTAVKI(idxC, MNGUST_DZ1_MX2));
 X2 = ((float)ust)*diskr;
 ust = codecUstDZ1(1, MNGUST_DZ1_MY2, getNativUstMngUSTAVKI(idxC, MNGUST_DZ1_MY2));
 Y2 = ((float)ust)*diskr;

 ustx3 =
 ust = codecUstDZ1(1, MNGUST_DZ1_MX3, getNativUstMngUSTAVKI(idxC, MNGUST_DZ1_MX3));
 X3 = ((float)ust)*diskr;
 usty3 =
 ust = codecUstDZ1(1, MNGUST_DZ1_MY3, getNativUstMngUSTAVKI(idxC, MNGUST_DZ1_MY3));
 Y3 = ((float)ust)*diskr;

 ustx4 =
 ust = codecUstDZ1(1, MNGUST_DZ1_MX4, getNativUstMngUSTAVKI(idxC, MNGUST_DZ1_MX4));
 X4 = ((float)ust)*diskr;
 usty4 =
 ust = codecUstDZ1(1, MNGUST_DZ1_MY4, getNativUstMngUSTAVKI(idxC, MNGUST_DZ1_MY4));
 Y4 = ((float)ust)*diskr;

 isTriangleZonaBD[1] = 0;//зона ДЗ четырехугольник
 if(ustx3==ustx4 && usty3==usty4) isTriangleZonaBD[1] = 1;//зона ДЗ треугольник
 if(isTriangleZonaBD[1]) isValidZonaDZ1MF = isZonaTrianMethodVRT( 1);//флаг валидности зоны
 else isValidZonaDZ1MF = isNewZonaMethodVRT( 1);//флаг валидности зоны
 
  //подготовка ENA команд для клона
  //копировать ENA из WideENA в ENAcmd
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_DZ1), ENACMD_DZ1_TOTAL);

  //подготовка уставок
    int tmpOffsetUSpv =
                cnfCOMPONENT[idxC].offsetUstSpv;    //уставки SPV
    //уставка SPV сработки
    int tmp1 = 
    SPV_UST(SPVSRAB_DZ1_MTZ) = codecUstDZ1(1, MNGUST_DZ1_MTZ, getNativUstMngUSTAVKI(idxC, MNGUST_DZ1_MTZ));
    //уставка SPV возврата
    SPV_UST(SPVVOZV_DZ1_MTZ) = tmp1 - tmp1/20;//5%


  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //компонент в конфигурации

         //таймер 1
   setTimerPorog(tmpOffsetT+ TIMER1_DZ1, 
          codecUstDZ1(1, MNGVID_DZ1MF, getNativUstMngUSTAVKI(idxC, MNGVID_DZ1MF)));

         //таймер 2 BO
  setTimerPorog(tmpOffsetT+ TIMER1_BODZ1, 10);

        //таймер 3
  setTimerPorog(tmpOffsetT+ TIMER2_DZ1, 
          codecUstDZ1(1, MNGVID_MDZ1MF, getNativUstMngUSTAVKI(idxC, MNGVID_MDZ1MF)));

        //таймер 4 BO
  setTimerPorog(tmpOffsetT+ TIMER2_BODZ1, 10);

       //таймер 5
  setTimerPorog(tmpOffsetT+ TIMER3_DZ1, 
          codecUstDZ1(1, MNGVID_DZ1OF, getNativUstMngUSTAVKI(idxC, MNGVID_DZ1OF)));

      //таймер 6 BO
  setTimerPorog(tmpOffsetT+ TIMER3_BODZ1, 10);

}//prepareUstMTZ1(short idxC)

int initIOCmd_DZ1()
{
  //инициал IO команд
  offsetIOCmdDZ1 = IndexIO;//смещение для IO DZ1
  return commonInitIOCmd(IOCMD_DZ1_TOTAL);
}

int initTLCmd_DZ1()
{
  //инициал TL команд
  return commonInitTLCmd(TLCMD_DZ1_TOTAL);
}//initTLCmd_DZ1()

int initENACmd_DZ1()
{
  //инициал ENA команд
  return commonInitENACmd(ENACMD_DZ1_TOTAL);
}//initENACmd_DZ1()

void initTimersDZ1(short idxC)
{
  //запрос и инициал таймеров
  commonInitTimers(TIMERS_DZ1_TOTAL);//должен быть первым!

}//initTimersDZ1()

int codecUstDZ1(char codec, short offset, int ust)
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
   case MNGUST_DZ1_MTZ:
       grzHI = 1000000;//верх граница
       grzLOW= 0;//низ граница
       step  = 1;//шаг
   break;

   case MNGUST_DZ1_OX1:   case MNGUST_DZ1_OY1:
   case MNGUST_DZ1_OX2:   case MNGUST_DZ1_OY2:
   case MNGUST_DZ1_OX3:   case MNGUST_DZ1_OY3:
   case MNGUST_DZ1_OX4:   case MNGUST_DZ1_OY4:

   case MNGUST_DZ1_MX1:   case MNGUST_DZ1_MY1:
   case MNGUST_DZ1_MX2:   case MNGUST_DZ1_MY2:
   case MNGUST_DZ1_MX3:   case MNGUST_DZ1_MY3:
   case MNGUST_DZ1_MX4:   case MNGUST_DZ1_MY4:
       grzHI = 1000000;//верх граница
       grzLOW= -1000000;//низ граница
       step  = 1;//шаг
   break;

  //выдержки
   case MNGVID_DZ1MF:
   case MNGVID_MDZ1MF:
   case MNGVID_DZ1OF:
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
}//codecUstDZ1(char *buf, short offset, int ust)

int isDISactiv_DZ1(int idxC)
{
 //активность Регистратора ДИС
  return 0;//нет активности
}//isDISactiv_DZ1(int idxC)

char copyDZ1ToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//стереть старое
//копировать компонент в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.packet = 0;    //номер пакетного компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  DZ1_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_DZ1;//меню компонента

  rpzcomponent_obj.cntClon     = CNT_STUPEN_DZ;   //max к-во клонов
  rpzcomponent_obj.numClon     = 1;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstDZ1;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstDZ1;//подготовка уставок
  rpzcomponent_obj.initIOCmd      = initIOCmd_DZ1;      //инициал IO команд
  rpzcomponent_obj.initTLCmd      = initTLCmd_DZ1;      //инициал TL команд
  rpzcomponent_obj.initENACmd     = initENACmd_DZ1;     //инициал ENA команд
  rpzcomponent_obj.bo_bvCmd       = NULL; //настройка БО БВ команд
  rpzcomponent_obj.isDISactiv     = isDISactiv_DZ1; //активность Регистратора ДИС
  rpzcomponent_obj.setBOBVtimer   = NULL; //инициал таймеров БО БВ

  rpzcomponent_obj.nameStatusIO = ionsDZ1;          //имена и статус команд IO
  rpzcomponent_obj.initTimers   = initTimersDZ1;    //запрос и инициал таймеров
  rpzcomponent_obj.logic        = logicDZ1;         //логика компонента

  rpzcomponent_obj.codecUst = codecUstDZ1;   //кодировать-раскодировать уставку

  return 0;//не пакетная регистрация
}//

#endif // _HIDE_COMPONENT

