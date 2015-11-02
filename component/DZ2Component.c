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
#define MNGUST_DZ2to5_OX1  0
#define MNGUST_DZ2to5_OY1  1
#define MNGUST_DZ2to5_OX2  2
#define MNGUST_DZ2to5_OY2  3
#define MNGUST_DZ2to5_OX3  4
#define MNGUST_DZ2to5_OY3  5
#define MNGUST_DZ2to5_OX4  6
#define MNGUST_DZ2to5_OY4  7

//уставка MF
#define MNGUST_DZ2to5_MX1  8
#define MNGUST_DZ2to5_MY1  9
#define MNGUST_DZ2to5_MX2  10
#define MNGUST_DZ2to5_MY2  11
#define MNGUST_DZ2to5_MX3  12
#define MNGUST_DZ2to5_MY3  13
#define MNGUST_DZ2to5_MX4  14
#define MNGUST_DZ2to5_MY4  15

//MTZ DZ2to5
#define MNGUST_DZ2to5_MTZ  16

//уставка выдержки
//Выдержка ДЗ2МФ
#define MNGVID_DZ2to5MF   17
//Выдержка МТЗ ДЗ2МФ
#define MNGVID_MDZ2to5MF  18
//Выдержка ДЗ2ОФ
#define MNGVID_DZ2to5OF   19
//Ввод ускор ДЗ2МФ
#define MNGVUSK_DZ2to5MF  20
//Ввод ускор МТЗ ДЗ2МФ    
#define MNGVUSK_MDZ2to5MF 21

//Ускор ДЗ2МФ ВВ
#define MNGUSK_DZ2to5MF_VV  22
//Ускор ДЗ2МФ ОУ
#define MNGUSK_DZ2to5MF_OU  23
//Ускор ДЗ2МФ ТУ
#define MNGUSK_DZ2to5MF_TU  24

//Ускор МТЗ ДЗ2МФ ВВ
#define MNGUSK_MDZ2to5MF_VV  25
//Ускор МТЗ ДЗ2МФ ОУ
#define MNGUSK_MDZ2to5MF_OU  26
//Ускор МТЗ ДЗ2МФ ТУ
#define MNGUSK_MDZ2to5MF_TU  27

//Ускор ДЗ2ОФ ВВ
#define MNGUSK_DZ2to5OF_VV  28
//Ускор ДЗ2ОФ ОУ
#define MNGUSK_DZ2to5OF_OU  29
//Ускор ДЗ2ОФ ТУ
#define MNGUSK_DZ2to5OF_TU  30

//уставка управления
#define MNGUPR_DZ2to5       31
//к-во уставок в менеджере уставок
#define MNGUST_DZ2to5_TOTAL  32
//#define MNGUST_BOBV_DZ2to5  MNGUST_DZ2to5_TOTAL

//РАСПРЕДЕЛЕНИЕ УСТАВОК  УПРАВЛЕНИЯ
//ENA_DZ2to5MF
#define ENA_DZ2to5_1  0
//ENA_MDZ2to5MF
#define ENA_DZ2to5_2  1
//ENA_USK_DZ2to5_VV
#define ENA_DZ2to5_3  2
//ENA_AUSK_DZ2to5
#define ENA_DZ2to5_4  3
//ENA_TUSK_DZ2to5
#define ENA_DZ2to5_5  4
//к-во ENA команд
#define ENACMD_DZ2to5_TOTAL 5

//РАСПРЕДЕЛЕНИЕ УСТАВОК в супервизоре
//уставка сработки
#define SPVSRAB_DZ2to5_MTZ    0
//уставка возврата
#define SPVVOZV_DZ2to5_MTZ    1

//уставка SPV выход
#define SPV_OUTA_DZ2to5_MTZ   2          
#define SPV_OUTB_DZ2to5_MTZ   3          
#define SPV_OUTC_DZ2to5_MTZ   4          
//к-во уставок в супервизоре
#define SPVUST_DZ2to5_TOTAL  5

//---------------IO COMMAND------------------
//РАСПРЕДЕЛЕНИЕ IO КОМАНД ДЛЯ DZ2to5
//Стат блок ДЗ2
#define IOCMD1_DZ2to5     0
//Блок уск ДЗ2
//CMD_BLOK_USK_DZ2to5
#define IOCMD2_DZ2to5     1
//Операт уск ДЗ2
//CMD_OPERAT_USK_DZ2to5
#define IOCMD3_DZ2to5     2
//Сраб ПО ДЗ2МФ
#define IOCMD4_DZ2to5MF   3
//Сраб ДЗ2МФ
#define IOCMD5_DZ2to5MF   4
//Сраб ПО МТЗ ДЗ2МФ
#define IOCMD4_MDZ2to5MF  5
//Сраб МТЗ ДЗ2МФ
#define IOCMD5_MDZ2to5MF  6
//Сраб ПО ДЗ2ОФ
#define IOCMD4_DZ2to5OF   7
//Сраб ДЗ2ОФ
#define IOCMD5_DZ2to5OF   8
//Теле уск ДЗ2
//CMD_TELE_USK_DZ2to5
#define IOCMD6_DZ2to5     9
//к-во IO команд
#define IOCMD_DZ2to5_TOTAL    10

//---------------TL COMMAND------------------
//РАСПРЕДЕЛЕНИЕ TL КОМАНД ДЛЯ DZ2to5
//RES_DZ2to5MF
#define TLCMD1_DZ2to5MF  0
//RES_MDZ2to5MF
#define TLCMD1_MDZ2to5MF 1
//RES_DZ2to5OF
#define TLCMD1_DZ2to5OF  2
//TU_DZ2to5MF
#define TLCMD4_DZ2to5    3
//AU_DZ2to5MF
#define TLCMD5_DZ2to5    4
//POL_VV_DZ2to5
#define TLCMD6_DZ2to5    5
//VUSKOR_DZ2to5MF
#define TLCMD7_DZ2to5MF  6
//VUSKOR_MDZ2to5MF
#define TLCMD7_MDZ2to5MF 7

//ELOLDTRG_USKOR_DZ2to5MF_OU
#define TLCMD9_DZ2to5MF  8
//ELOUTTRG_USKOR_DZ2to5MF_OU
#define TLCMD10_DZ2to5MF 9

//ELOLDTRG_USKOR_DZ2to5MF_AU
#define TLCMD11_DZ2to5MF 10
//ELOUTTRG_USKOR_DZ2to5MF_AU
#define TLCMD12_DZ2to5MF 11

//ELOLDTRG_USKOR_DZ2to5MF_TU
#define TLCMD13_DZ2to5MF 12
//ELOUTTRG_USKOR_DZ2to5MF_TU
#define TLCMD14_DZ2to5MF 13

//ELOLDTRG_USKOR_MDZ2to5MF_OU
#define TLCMD9_MDZ2to5MF  14
//ELOUTTRG_USKOR_MDZ2to5MF_OU
#define TLCMD10_MDZ2to5MF 15

//ELOLDTRG_USKOR_MDZ2to5MF_AU
#define TLCMD11_MDZ2to5MF 16
//ELOUTTRG_USKOR_MDZ2to5MF_AU
#define TLCMD12_MDZ2to5MF 17

//ELOLDTRG_USKOR_MDZ2to5MF_TU
#define TLCMD13_MDZ2to5MF 18
//ELOUTTRG_USKOR_MDZ2to5MF_TU
#define TLCMD14_MDZ2to5MF 19

//ELOLDTRG_USKOR_DZ2to5OF_OU
#define TLCMD9_DZ2to5OF  20
//ELOUTTRG_USKOR_DZ2to5OF_OU
#define TLCMD10_DZ2to5OF 21

//ELOLDTRG_USKOR_DZ2to5OF_AU
#define TLCMD11_DZ2to5OF 22
//ELOUTTRG_USKOR_DZ2to5OF_AU
#define TLCMD12_DZ2to5OF 23

//ELOLDTRG_USKOR_DZ2to5OF_TU
#define TLCMD13_DZ2to5OF 24
//ELOUTTRG_USKOR_DZ2to5OF_TU
#define TLCMD14_DZ2to5OF 25

//DZ2to5MF_USKOR
#define TLCMD27_DZ2to5MF  26
//MDZ2to5MF_USKOR
#define TLCMD27_MDZ2to5MF 27
//DZ2to5OF_USKOR
#define TLCMD27_DZ2to5OF  28

//ELOLDTRG_NCN_DZ2to5MF
#define TLCMDOLDNCN_DZ2to5MF  29
//ELOUTTRG_NCN_DZ2to5MF
#define TLCMDOUTNCN_DZ2to5MF  30
//ELOLDTRG_NCN_DZ2to5OF
#define TLCMDOLDNCN_DZ2to5OF  31
//ELOUTTRG_NCN_DZ2to5OF
#define TLCMDOUTNCN_DZ2to5OF  32
//ELOLDTRG_NCN_MDZ2to5MF
#define TLCMDOLDNCN_MDZ2to5MF 33
//ELOUTTRG_NCN_MDZ2to5MF
#define TLCMDOUTNCN_MDZ2to5MF 34

//DZ2to5_PO1
#define TLCMD30_DZ2to5MF  35
//DZ2to5_PO2
#define TLCMD30_MDZ2to5MF 36
//DZ2to5_PO3
#define TLCMD30_DZ2to5OF  37

#define TL10_DZ2TO5MF    38
#define TL10_MDZ2TO5MF   39
#define TL10_DZ2TO5OF    40

#define TL7_DZ2TO5MF     41
#define TL8_DZ2TO5MF     42
#define TL9_DZ2TO5MF     43

#define TL7_MDZ2TO5MF    44
#define TL8_MDZ2TO5MF    45
#define TL9_MDZ2TO5MF    46

#define TL7_DZ2TO5OF     47
#define TL8_DZ2TO5OF     48
#define TL9_DZ2TO5OF     49

//OU_DZ2to5MF
#define TLCMDOU_DZ2to5   50

//к-во TL команд
#define TLCMD_DZ2to5_TOTAL   51

//--------------- TIMERS ------------------
//РАСПРЕДЕЛЕНИЕ ТАЙМЕРОВ ДЛЯ DZ2to5
//Выдержка ДЗ2МФ
#define TIMER1_DZ2to5    0
//Выдержка МТЗ ДЗ2МФ
#define TIMER2_DZ2to5    1
//Выдержка ДЗ2ОФ
#define TIMER3_DZ2to5    2
//Ввод ускор ДЗ2МФ
#define TIMER4_DZ2to5MF  3
//Ввод ускор МТЗ ДЗ2МФ
#define TIMER4_MDZ2to5MF 4

//Ускор ДЗ2МФ ВВ
#define TIMER6_DZ2to5MF   5
//Ускор ДЗ2МФ ОУ
#define TIMER7_DZ2to5MF   6
//Ускор ДЗ2МФ ТУ
#define TIMER8_DZ2to5MF   7

//Ускор МТЗ ДЗ2МФ ВВ
#define TIMER6_MDZ2to5MF  8
//Ускор МТЗ ДЗ2МФ ОУ
#define TIMER7_MDZ2to5MF  9
//Ускор МТЗ ДЗ2МФ ТУ
#define TIMER8_MDZ2to5MF  10

//Ускор ДЗ2ОФ ВВ
#define TIMER6_DZ2to5OF   11
//Ускор ДЗ2ОФ ОУ
#define TIMER7_DZ2to5OF   12
//Ускор ДЗ2ОФ ТУ
#define TIMER8_DZ2to5OF   13

//таймер BO DZ2to5MF
#define TIMER_BODZ2to5MF  14
//таймер BO MDZ2to5MF
#define TIMER_BOMDZ2to5MF 15
//таймер BO DZ2to5OF      
#define TIMER_BODZ2to5OF  16

//к-во таймеров
#define TIMERS_DZ2to5_TOTAL 17

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "PRM1Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_DZ[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//индекс уставок в супервизоре
extern int  IndexIO;//индекс IO

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern char *bitStringUNI[];
extern int offsetUstMngPRM1;//смещение на уставки PRM1
extern int isTriangleZonaBD[];//зона ДЗ треугольник-четырехугольник

void PereinitUstListCompDZ2(short flg);
void UstListCompDZ2();
void ustRedactorCompDZ2();
void UstCompDZ2();

void PereinitVidListCompDZ2(short flg);
void VidListCompDZ2();
void vidRedactorCompDZ2();
void VidCompDZ2();

void PereinitUprListCompDZ2(short flg);
void UprListCompDZ2();
void uprRedactorCompDZ2();
void UprCompDZ2();
short  KadrMenuFormat_upr_compDZ2(void *workCntr);
short  KadrMenuFormat_ustvidDZ(void *workCntr);
int  initUstDZ2(char init);
void  prepareUstDZ2(short idxC);
char *selectorUprStrDZ2(short iBit, UNS_32 ustUpr);
void diffDZ3ToRepozitar();
void diffDZ4ToRepozitar();
void diffDZ5ToRepozitar();

void EditUprDZ2();
void EditVidDZ2();
void EditUstDZ2();
int codecUstDZ2(char codec, short offset, int ust);
void  logicDZ2to5(int idxC);
int   isDISactiv_DZ2to5(int idxC);

TWIN_DIFFERENT twinDZ2[3];//массив контроля близнецов

int  offsetIOCmdDZ5;//смещение для IO DZ5
int isValidZonaDZ2OF;//флаг валидности зоны
int isValidZonaDZ2MF;//флаг валидности зоны
int isValidZonaDZ3OF;//флаг валидности зоны
int isValidZonaDZ3MF;//флаг валидности зоны
int isValidZonaDZ4OF;//флаг валидности зоны
int isValidZonaDZ4MF;//флаг валидности зоны
int isValidZonaDZ5OF;//флаг валидности зоны
int isValidZonaDZ5MF;//флаг валидности зоны
/*
int locPO_DZ2MF;
int locPO_DZ2OF;
int locPO_DZ3MF;
int locPO_DZ3OF;
int locPO_DZ4MF;
int locPO_DZ4OF;
int locPO_DZ5MF;
int locPO_DZ5OF;
*/
char DZ2_TITLE[] = "ДЗ2";

IONAMESTATUS_COMPONENT ionsDZ2[IOCMD_DZ2to5_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок ДЗ2"
  },
  {
    1,//статус iocmd2
    "Блок уск ДЗ2"
  },
  {
    1,//статус iocmd3
    "Операт уск ДЗ2"
  },
  {
    1,//статус iocmd4
    "Сраб ПО ДЗ2МФ"
  },
  {
    1,//статус iocmd5
    "Сраб ДЗ2МФ"
  },
  {
    1,//статус iocmd6
    "Сраб ПО МТЗ ДЗ2МФ"
  },
  {
    1,//статус iocmd7
    "Сраб МТЗ ДЗ2МФ"
  },
  {
    1,//статус iocmd8
    "Сраб ПО ДЗ2ОФ"
  },
  {
    1,//статус iocmd9
    "Сраб ДЗ2ОФ"
  },
  {
    1,//статус iocmd10
    "Теле уск ДЗ2"
  }
};

LineMenuItem sub_menu_comp_DZ2[8] =
{
  { DZ2_TITLE, NULL},//title
//  { &CONTROL1_COMP, &sub_menu_DZ, typeMenuSub},//control_item, parent
//  { "Уставки ДЗ2",     (void *)&UstListCompDZ2, typeMenuProg},
//  { "Выдержки ДЗ2",    (void *)&VidListCompDZ2, typeMenuProg},
//  { "Управление ДЗ2",  (void *)&UprListCompDZ2, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compDZ2[] =
{
  { "Уставки ДЗ2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ2, typeMenuList},//control_item, parent
//  { "Уст ДЗ2",        (void *)&UstCompDZ2, typeMenuProg},
//  { "Уст ДЗ2 вперед", (void *)&UstCompDZ2, typeMenuProg},
//  { "Уст ДЗ2 назад",  (void *)&UstCompDZ2, typeMenuProg},
//  { "Уст ДЗ2 ПМ",     (void *)&UstCompDZ2, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compDZ2[] =
{
  { "Выдержки ДЗ2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ2, typeMenuList},//control_item, parent
/*
  { "Выдержка ДЗ2МФ",       (void*)&VidCompDZ2, typeMenuProg},
  { "Выдержка МТЗ ДЗ2МФ",   (void*)&VidCompDZ2, typeMenuProg},
  { "Выдержка ДЗ2ОФ",       (void*)&VidCompDZ2, typeMenuProg},
  { "Ввод ускор ДЗ2МФ",     (void*)&VidCompDZ2, typeMenuProg},
  { "Ввод ускор МТЗ ДЗ2МФ", (void*)&VidCompDZ2, typeMenuProg},

  { "Ускор ДЗ2МФ ВВ",       (void*)&VidCompDZ2, typeMenuProg},
  { "Ускор ДЗ2МФ ОУ",       (void*)&VidCompDZ2, typeMenuProg},
  { "Ускор ДЗ2МФ ТУ",       (void*)&VidCompDZ2, typeMenuProg},

  { "Ускор МТЗ ДЗ2МФ ВВ",   (void*)&VidCompDZ2, typeMenuProg},
  { "Ускор МТЗ ДЗ2МФ ОУ",   (void*)&VidCompDZ2, typeMenuProg},
  { "Ускор МТЗ ДЗ2МФ ТУ",   (void*)&VidCompDZ2, typeMenuProg},

  { "Ускор ДЗ2ОФ ВВ",       (void*)&VidCompDZ2, typeMenuProg},
  { "Ускор ДЗ2ОФ ОУ",       (void*)&VidCompDZ2, typeMenuProg},
  { "Ускор ДЗ2ОФ ТУ",       (void*)&VidCompDZ2, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compDZ2[] =
{
  { "Управл ДЗ2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_DZ2, typeMenuList},//control_item, parent
//  { "Управл ДЗ2",        (void *)&UprCompDZ2, typeMenuProg},
//  { "Управл МТЗ ДЗ2",    (void *)&UprCompDZ2, typeMenuProg},
//  { "Ускор ВВ ДЗ2",      (void *)&UprCompDZ2, typeMenuProg},
//  { "Автомат уск ДЗ2",   (void *)&UprCompDZ2, typeMenuProg},
//  { "Телеускор ДЗ2",     (void *)&UprCompDZ2, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompDZ2(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidDZ, sub_menu_ust_compDZ2);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UstListCompDZ2()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compDZ2);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompDZ2);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompDZ2()

void UstCompDZ2()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compDZ2);
  PassWord(EditUstDZ2);
}//VidCompDZ1()

void EditUstDZ2()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compDZ2);
}//UstCompDZ2()

//--------------------------------------------------

void PereinitVidListCompDZ2(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidDZ, sub_menu_vid_compDZ2);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void VidListCompDZ2()
{
  SelectorMNGBAZA(MNGVID_DZ2to5MF);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compDZ2);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompDZ2);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompDZ2()

void VidCompDZ2()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compDZ2);
//  PassWord(EditVidAPV);
  EditVidDZ2();
}//VidCompDZ2()

void EditVidDZ2()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compDZ2);
}//

//--------------------------------------------------

void PereinitUprListCompDZ2(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compDZ2, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UprListCompDZ2()
{
  SelectorMNGBAZA(MNGUPR_DZ2to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compDZ2);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompDZ2);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompDZ1()

void UprCompDZ2()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compDZ2);
  PassWord(EditUprDZ2);

}//UprCompMTZ2()

void EditUprDZ2()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compDZ2[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrDZ2);//редактировать уставку управления
}//EditUprDZ2()

short  KadrMenuFormat_upr_compDZ2(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compDZ2[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      //отобразить уставку управления в кадре
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrDZ2(i, getCurrentMngUSTAVKI()));

      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compDZ2(WorkControl *workCntr)

char *selectorUprStrDZ2(short iBit, UNS_32 ustUpr)
{
  switch(iBit)
  {

  default:;
  }//switch
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_WKL];
    return bitStringUNI[UNIUPR_OTKL];
}//selectorUprStrDZ2(short ibit, UNS_32 ustUpr)

int initUstDZ2(char init)
{
  //инициал уставок
  if (init)
  {
//уставка сработки
    tmpUSTAVKI[MNGUST_DZ2to5_OX1] = 100;
    tmpUSTAVKI[MNGUST_DZ2to5_OY1] = 101;
    tmpUSTAVKI[MNGUST_DZ2to5_OX2] = 102;
    tmpUSTAVKI[MNGUST_DZ2to5_OY2] = 103;
    tmpUSTAVKI[MNGUST_DZ2to5_OX3] = 104;
    tmpUSTAVKI[MNGUST_DZ2to5_OY3] = 105;
    tmpUSTAVKI[MNGUST_DZ2to5_OX4] = 106;
    tmpUSTAVKI[MNGUST_DZ2to5_OY4] = 107;

    tmpUSTAVKI[MNGUST_DZ2to5_MX1] = 110;
    tmpUSTAVKI[MNGUST_DZ2to5_MY1] = 111;
    tmpUSTAVKI[MNGUST_DZ2to5_MX2] = 112;
    tmpUSTAVKI[MNGUST_DZ2to5_MY2] = 113;
    tmpUSTAVKI[MNGUST_DZ2to5_MX3] = 114;
    tmpUSTAVKI[MNGUST_DZ2to5_MY3] = 115;
    tmpUSTAVKI[MNGUST_DZ2to5_MX4] = 116;
    tmpUSTAVKI[MNGUST_DZ2to5_MY4] = 117;

    tmpUSTAVKI[MNGUST_DZ2to5_MTZ] = 118;
//уставка выдержки
    tmpUSTAVKI[MNGVID_DZ2to5MF]   = 25;
//Выдержка МТЗ ДЗ2МФ
    tmpUSTAVKI[MNGVID_MDZ2to5MF]  = 26;
//Выдержка ДЗ2ОФ
    tmpUSTAVKI[MNGVID_DZ2to5OF]   = 27;
//Ввод ускор ДЗ2МФ
    tmpUSTAVKI[MNGVUSK_DZ2to5MF]  = 28;
//Ввод ускор МТЗ ДЗ2МФ    
    tmpUSTAVKI[MNGVUSK_MDZ2to5MF] = 29;

//ускорение
//Ускор ДЗ2МФ ВВ
    tmpUSTAVKI[MNGUSK_DZ2to5MF_VV] = 30;
//Ускор ДЗ2МФ ОУ
    tmpUSTAVKI[MNGUSK_DZ2to5MF_OU] = 31;
//Ускор ДЗ2МФ ТУ
    tmpUSTAVKI[MNGUSK_DZ2to5MF_TU] = 32;

//Ускор МТЗ ДЗ2МФ ВВ
    tmpUSTAVKI[MNGUSK_MDZ2to5MF_VV] = 33;
//Ускор МТЗ ДЗ2МФ ОУ
    tmpUSTAVKI[MNGUSK_MDZ2to5MF_OU] = 34;
//Ускор МТЗ ДЗ2МФ ТУ
    tmpUSTAVKI[MNGUSK_MDZ2to5MF_TU] = 35;

//Ускор ДЗ2ОФ ВВ
    tmpUSTAVKI[MNGUSK_DZ2to5OF_VV]  = 36;
//Ускор ДЗ2ОФ ОУ
    tmpUSTAVKI[MNGUSK_DZ2to5OF_OU]  = 37;
//Ускор ДЗ2ОФ ТУ
    tmpUSTAVKI[MNGUSK_DZ2to5OF_TU]  = 38;

//уставка управления
    tmpUSTAVKI[MNGUPR_DZ2to5] = 0;

  }//if

//  offsetSPVCmdDZ2 = IndexUstSPV;//смещение для SPV DZ2
  IndexUstSPV += SPVUST_DZ2to5_TOTAL;//индекс уставок в супервизоре
  return MNGUST_DZ2to5_TOTAL;//к-во уставок в менеджере уставок
}//initUstDZ2to5(short mngUst, char init)
                    
//координаты вершин зоны сработки
extern float X1, Y1, X2, Y2;
extern float X3, Y3, X4, Y4;

int SetOFZonaVertex2to5(int idxC);
int SetMFZonaVertex2to5(int idxC);

int global_enaDZ3=0;

void  prepareUstDZ2(short idxC)
{
  int numClon =    //номер клона
                cnfCOMPONENT[idxC].numClon;  
//int tt3 = -1;
if(numClon==3){
     global_enaDZ3 = PrepareENACmd(idxC, MNGUPR_DZ2to5);

    int  test_global_enaDZ3 = PrepareENACmd(8, 31);//(8, MNGUPR_DZ2to5);

  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_DZ2to5), ENACMD_DZ2to5_TOTAL);


//void CopyWideENAToENAcmd(short offset, short cnt)
//{
  //копировать ENA из WideENA в ENAcmd
/*
  for(short i=0; i<cnt; i++)
  {
    //ENA команды
    ENAcmd[offset + i] = WideENABuffer[i];
  }//for
*/
//}//CopyWideENAToENAcmd(short offset, short cnt);

}//if(numClon==3)

  
  //подготовка зоны
  switch(numClon){
  case 2:{
//    X1=X1OF_DZ2; Y1=Y1OF_DZ2; X2=X2OF_DZ2; Y2=Y2OF_DZ2;
//    X3=X3OF_DZ2; Y3=Y3OF_DZ2; X4=X4OF_DZ2; Y4=Y4OF_DZ2;
 //зона ДЗ треугольник-четырехугольник
// int ttt1 =   
 isTriangleZonaBD[(numClon-1)*2] = SetOFZonaVertex2to5(idxC);//Формирование вершин зоны OF  
 if(isTriangleZonaBD[(numClon-1)*2])
      isValidZonaDZ2OF = isZonaTrianMethodVRT( (numClon-1)*2);//флаг валидности зоны
 else isValidZonaDZ2OF = isNewZonaMethodVRT((numClon-1)*2);//флаг валидности зоны
  }
    break;
    
  case 3:
    {
//    X1=X1OF_DZ3; Y1=Y1OF_DZ3; X2=X2OF_DZ3; Y2=Y2OF_DZ3;
  //  X3=X3OF_DZ3; Y3=Y3OF_DZ3; X4=X4OF_DZ3; Y4=Y4OF_DZ3;
 //зона ДЗ треугольник-четырехугольник
 isTriangleZonaBD[(numClon-1)*2] = SetOFZonaVertex2to5(idxC);//Формирование вершин зоны OF  
 if(isTriangleZonaBD[(numClon-1)*2])
      isValidZonaDZ3OF = isZonaTrianMethodVRT( (numClon-1)*2);//флаг валидности зоны
 else isValidZonaDZ3OF = isNewZonaMethodVRT((numClon-1)*2);//флаг валидности зоны
    }
    break;
    
  case 4:
    {
//    X1=X1OF_DZ4; Y1=Y1OF_DZ4; X2=X2OF_DZ4; Y2=Y2OF_DZ4;
    //X3=X3OF_DZ4; Y3=Y3OF_DZ4; X4=X4OF_DZ4; Y4=Y4OF_DZ4;
      
 //зона ДЗ треугольник-четырехугольник
 isTriangleZonaBD[(numClon-1)*2] = SetOFZonaVertex2to5(idxC);//Формирование вершин зоны OF  
 if(isTriangleZonaBD[(numClon-1)*2])
      isValidZonaDZ4OF = isZonaTrianMethodVRT( (numClon-1)*2);//флаг валидности зоны
 else isValidZonaDZ4OF = isNewZonaMethodVRT((numClon-1)*2);//флаг валидности зоны
    }
    break;
    
  case 5:
    {
//    X1=X1OF_DZ5; Y1=Y1OF_DZ5; X2=X2OF_DZ5; Y2=Y2OF_DZ5;
//    X3=X3OF_DZ5; Y3=Y3OF_DZ5; X4=X4OF_DZ5; Y4=Y4OF_DZ5;
      
 //зона ДЗ треугольник-четырехугольник
 isTriangleZonaBD[(numClon-1)*2] = SetOFZonaVertex2to5(idxC);//Формирование вершин зоны OF  
 if(isTriangleZonaBD[(numClon-1)*2])
      isValidZonaDZ5OF = isZonaTrianMethodVRT( (numClon-1)*2);//флаг валидности зоны
 else isValidZonaDZ5OF = isNewZonaMethodVRT((numClon-1)*2);//флаг валидности зоны
    }
    break;
    
  default:;
  }//switch
  
//--------------MF  
  switch(numClon){
  case 2:
    {
//    X1=X1MF_DZ2; Y1=Y1MF_DZ2; X2=X2MF_DZ2; Y2=Y2MF_DZ2;
  //  X3=X3MF_DZ2; Y3=Y3MF_DZ2; X4=X4MF_DZ2; Y4=Y4MF_DZ2;
 //зона ДЗ треугольник-четырехугольник
 isTriangleZonaBD[(numClon-1)*2 +1] = SetMFZonaVertex2to5(idxC);//Формирование вершин зоны MF  

 if(isTriangleZonaBD[(numClon-1)*2 +1])
       isValidZonaDZ2MF = isZonaTrianMethodVRT(1+ (numClon-1)*2);//флаг валидности зоны
 else  isValidZonaDZ2MF = isNewZonaMethodVRT(1+ (numClon-1)*2);//флаг валидности зоны
    }
    break;
    
  case 3:
    {
//    X1=X1MF_DZ3; Y1=Y1MF_DZ3; X2=X2MF_DZ3; Y2=Y2MF_DZ3;
    //X3=X3MF_DZ3; Y3=Y3MF_DZ3; X4=X4MF_DZ3; Y4=Y4MF_DZ3;
 //зона ДЗ треугольник-четырехугольник
 isTriangleZonaBD[(numClon-1)*2 +1] = SetMFZonaVertex2to5(idxC);//Формирование вершин зоны MF  
      
 if(isTriangleZonaBD[(numClon-1)*2 +1])
       isValidZonaDZ3MF = isZonaTrianMethodVRT(1+ (numClon-1)*2);//флаг валидности зоны
 else   isValidZonaDZ3MF = isNewZonaMethodVRT(1+ (numClon-1)*2);//флаг валидности зоны
    }
    break;
    
  case 4:
    {
//    X1=X1MF_DZ4; Y1=Y1MF_DZ4; X2=X2MF_DZ4; Y2=Y2MF_DZ4;
//    X3=X3MF_DZ4; Y3=Y3MF_DZ4; X4=X4MF_DZ4; Y4=Y4MF_DZ4;
 //зона ДЗ треугольник-четырехугольник
 isTriangleZonaBD[(numClon-1)*2 +1] = SetMFZonaVertex2to5(idxC);//Формирование вершин зоны MF  
 if(isTriangleZonaBD[(numClon-1)*2 +1])
       isValidZonaDZ4MF = isZonaTrianMethodVRT(1+ (numClon-1)*2);//флаг валидности зоны
 else  isValidZonaDZ4MF = isNewZonaMethodVRT(1+ (numClon-1)*2);//флаг валидности зоны
    }
    break;
    
  case 5:
    {
//    X1=X1MF_DZ5; Y1=Y1MF_DZ5; X2=X2MF_DZ5; Y2=Y2MF_DZ5;
//    X3=X3MF_DZ5; Y3=Y3MF_DZ5; X4=X4MF_DZ5; Y4=Y4MF_DZ5;
 //зона ДЗ треугольник-четырехугольник
 isTriangleZonaBD[(numClon-1)*2 +1] = SetMFZonaVertex2to5(idxC);//Формирование вершин зоны MF  
 if(isTriangleZonaBD[(numClon-1)*2 +1])
       isValidZonaDZ5MF = isZonaTrianMethodVRT(1+ (numClon-1)*2);//флаг валидности зоны
 else  isValidZonaDZ5MF = isNewZonaMethodVRT(1+ (numClon-1)*2);//флаг валидности зоны
    }
    break;
    
  default:;
  }//switch
  

  //подготовка ENA команд для клона
  //копировать ENA из WideENA в ENAcmd
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_DZ2to5), ENACMD_DZ2to5_TOTAL);

  //подготовка уставок
    int tmpOffsetUSpv =
                cnfCOMPONENT[idxC].offsetUstSpv;    //уставки SPV
    //уставка SPV сработки
    int tmp1 = 
    SPV_UST(SPVSRAB_DZ2to5_MTZ) = codecUstDZ2(1, MNGUST_DZ2to5_MTZ, getNativUstMngUSTAVKI(idxC, MNGUST_DZ2to5_MTZ));
    //уставка SPV возврата
    SPV_UST(SPVVOZV_DZ2to5_MTZ) = tmp1 - tmp1/20;//5%

  
  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //компонент в конфигурации

//Выдержка ДЗ2МФ
  setTimerPorog(tmpOffsetT+ TIMER1_DZ2to5,
          codecUstDZ2(1, MNGVID_DZ2to5MF, getNativUstMngUSTAVKI(idxC, MNGVID_DZ2to5MF)));

//Выдержка МТЗ ДЗ2МФ
  setTimerPorog(tmpOffsetT+ TIMER2_DZ2to5, 
          codecUstDZ2(1, MNGVID_MDZ2to5MF, getNativUstMngUSTAVKI(idxC, MNGVID_MDZ2to5MF)));

//Выдержка ДЗ2ОФ
  setTimerPorog(tmpOffsetT+ TIMER3_DZ2to5,
          codecUstDZ2(1, MNGVID_DZ2to5OF, getNativUstMngUSTAVKI(idxC, MNGVID_DZ2to5OF)));

//Ввод ускор ДЗ2МФ
  setTimerPorog(tmpOffsetT+ TIMER4_DZ2to5MF,
          codecUstDZ2(1, MNGVUSK_DZ2to5MF, getNativUstMngUSTAVKI(idxC, MNGVUSK_DZ2to5MF)));

//Ввод ускор МТЗ ДЗ2МФ
  setTimerPorog(tmpOffsetT+ TIMER4_MDZ2to5MF,
          codecUstDZ2(1, MNGVUSK_MDZ2to5MF, getNativUstMngUSTAVKI(idxC, MNGVUSK_MDZ2to5MF)));


//Ускор ДЗ2МФ ВВ
  int tmp =     codecUstDZ2(1, MNGUSK_DZ2to5MF_VV, getNativUstMngUSTAVKI(idxC, MNGUSK_DZ2to5MF_VV));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER6_DZ2to5MF, tmp);

//Ускор ДЗ2МФ ОУ
  tmp =        codecUstDZ2(1, MNGUSK_DZ2to5MF_OU, getNativUstMngUSTAVKI(idxC, MNGUSK_DZ2to5MF_OU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER7_DZ2to5MF, tmp);

//Ускор ДЗ2МФ ТУ
  tmp =        codecUstDZ2(1, MNGUSK_DZ2to5MF_TU, getNativUstMngUSTAVKI(idxC, MNGUSK_DZ2to5MF_TU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER8_DZ2to5MF, tmp);


//Ускор МТЗ ДЗ2МФ ВВ
  tmp =        codecUstDZ2(1, MNGUSK_MDZ2to5MF_VV, getNativUstMngUSTAVKI(idxC, MNGUSK_MDZ2to5MF_VV));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER6_MDZ2to5MF, tmp);

//Ускор МТЗ ДЗ2МФ ОУ
  tmp =        codecUstDZ2(1, MNGUSK_MDZ2to5MF_OU, getNativUstMngUSTAVKI(idxC, MNGUSK_MDZ2to5MF_OU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER7_MDZ2to5MF, tmp);

//Ускор МТЗ ДЗ2МФ ТУ
  tmp =        codecUstDZ2(1, MNGUSK_MDZ2to5MF_TU, getNativUstMngUSTAVKI(idxC, MNGUSK_MDZ2to5MF_TU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER8_MDZ2to5MF, tmp);

//Ускор ДЗ2ОФ ВВ
  tmp =        codecUstDZ2(1, MNGUSK_DZ2to5OF_VV, getNativUstMngUSTAVKI(idxC, MNGUSK_DZ2to5OF_VV));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER6_DZ2to5OF, tmp);

//Ускор ДЗ2ОФ ОУ
  tmp =        codecUstDZ2(1, MNGUSK_DZ2to5OF_OU, getNativUstMngUSTAVKI(idxC, MNGUSK_DZ2to5OF_OU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER7_DZ2to5OF, tmp);

//Ускор ДЗ2ОФ ТУ
  tmp =        codecUstDZ2(1, MNGUSK_DZ2to5OF_TU, getNativUstMngUSTAVKI(idxC, MNGUSK_DZ2to5OF_TU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER8_DZ2to5OF, tmp);

//таймер BO DZ2to5MF
  setTimerPorog(tmpOffsetT+ TIMER_BODZ2to5MF, 10);
//таймер BO MDZ2to5MF
  setTimerPorog(tmpOffsetT+ TIMER_BOMDZ2to5MF, 10);
//таймер BO DZ2to5OF      
  setTimerPorog(tmpOffsetT+ TIMER_BODZ2to5OF, 10);

}//prepareUstDZ2to5(short idxC)

int SetOFZonaVertex2to5(int idxC)
{
//Формирование вершин зоны OF  
float diskr = 0.001;
 int ust = codecUstDZ2(1, MNGUST_DZ2to5_OX1, getNativUstMngUSTAVKI(idxC, MNGUST_DZ2to5_OX1));
 X1 = ((float)ust)*diskr;
 ust = codecUstDZ2(1, MNGUST_DZ2to5_OY1, getNativUstMngUSTAVKI(idxC, MNGUST_DZ2to5_OY1));
 Y1 = ((float)ust)*diskr;

 ust = codecUstDZ2(1, MNGUST_DZ2to5_OX2, getNativUstMngUSTAVKI(idxC, MNGUST_DZ2to5_OX2));
 X2 = ((float)ust)*diskr;
 ust = codecUstDZ2(1, MNGUST_DZ2to5_OY2, getNativUstMngUSTAVKI(idxC, MNGUST_DZ2to5_OY2));
 Y2 = ((float)ust)*diskr;

int ustx3 =
 ust = codecUstDZ2(1, MNGUST_DZ2to5_OX3, getNativUstMngUSTAVKI(idxC, MNGUST_DZ2to5_OX3));
 X3 = ((float)ust)*diskr;
int usty3 =
 ust = codecUstDZ2(1, MNGUST_DZ2to5_OY3, getNativUstMngUSTAVKI(idxC, MNGUST_DZ2to5_OY3));
 Y3 = ((float)ust)*diskr;

int ustx4 =
 ust = codecUstDZ2(1, MNGUST_DZ2to5_OX4, getNativUstMngUSTAVKI(idxC, MNGUST_DZ2to5_OX4));
 X4 = ((float)ust)*diskr;
int usty4 =
 ust = codecUstDZ2(1, MNGUST_DZ2to5_OY4, getNativUstMngUSTAVKI(idxC, MNGUST_DZ2to5_OY4));
 Y4 = ((float)ust)*diskr;
 if(ustx3==ustx4 && usty3==usty4) return  1;//зона ДЗ треугольник
 return 0;//зона ДЗ четырехугольник
}//SetOFZonaVertex2to5()

int SetMFZonaVertex2to5(int idxC)
{
//Формирование вершин зоны MF  
float diskr = 0.001;
 int ust = codecUstDZ2(1, MNGUST_DZ2to5_MX1, getNativUstMngUSTAVKI(idxC, MNGUST_DZ2to5_MX1));
 X1 = ((float)ust)*diskr;
 ust = codecUstDZ2(1, MNGUST_DZ2to5_MY1, getNativUstMngUSTAVKI(idxC, MNGUST_DZ2to5_MY1));
 Y1 = ((float)ust)*diskr;

 ust = codecUstDZ2(1, MNGUST_DZ2to5_MX2, getNativUstMngUSTAVKI(idxC, MNGUST_DZ2to5_MX2));
 X2 = ((float)ust)*diskr;
 ust = codecUstDZ2(1, MNGUST_DZ2to5_MY2, getNativUstMngUSTAVKI(idxC, MNGUST_DZ2to5_MY2));
 Y2 = ((float)ust)*diskr;

int ustx3 =
 ust = codecUstDZ2(1, MNGUST_DZ2to5_MX3, getNativUstMngUSTAVKI(idxC, MNGUST_DZ2to5_MX3));
 X3 = ((float)ust)*diskr;
int usty3 =
 ust = codecUstDZ2(1, MNGUST_DZ2to5_MY3, getNativUstMngUSTAVKI(idxC, MNGUST_DZ2to5_MY3));
 Y3 = ((float)ust)*diskr;

int ustx4 =
 ust = codecUstDZ2(1, MNGUST_DZ2to5_MX4, getNativUstMngUSTAVKI(idxC, MNGUST_DZ2to5_MX4));
 X4 = ((float)ust)*diskr;
int usty4 =
 ust = codecUstDZ2(1, MNGUST_DZ2to5_MY4, getNativUstMngUSTAVKI(idxC, MNGUST_DZ2to5_MY4));
 Y4 = ((float)ust)*diskr;
 if(ustx3==ustx4 && usty3==usty4) return  1;//зона ДЗ треугольник
 return 0;//зона ДЗ четырехугольник
}//SetMFZonaVertex2to5(int idxC)

int initIOCmd_DZ2()
{
  //инициал IO команд
  offsetIOCmdDZ5 = IndexIO;//смещение для IO DZ5
  return commonInitIOCmd(IOCMD_DZ2to5_TOTAL);
}//initIOCmd_DZ2()

int initTLCmd_DZ2()
{
  //инициал TL команд
  return commonInitTLCmd(TLCMD_DZ2to5_TOTAL);
}//initTLCmd_DZ2()

int initENACmd_DZ2()
{
  //инициал ENA команд
  return commonInitENACmd(ENACMD_DZ2to5_TOTAL);
}//initENACmd_DZ2()

void initTimersDZ2(short idxC)
{
  //запрос и инициал таймеров
  commonInitTimers(TIMERS_DZ2to5_TOTAL);//должен быть первым!
}//initTimersDZ2()

int codecUstDZ2(char codec, short offset, int ust)
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
   case MNGUST_DZ2to5_MTZ:
       grzHI = 1000000;//верх граница
       grzLOW= 0;//низ граница
       step  = 1;//шаг
   break;

   case MNGUST_DZ2to5_OX1:   case MNGUST_DZ2to5_OY1:
   case MNGUST_DZ2to5_OX2:   case MNGUST_DZ2to5_OY2:
   case MNGUST_DZ2to5_OX3:   case MNGUST_DZ2to5_OY3:
   case MNGUST_DZ2to5_OX4:   case MNGUST_DZ2to5_OY4:

   case MNGUST_DZ2to5_MX1:   case MNGUST_DZ2to5_MY1:
   case MNGUST_DZ2to5_MX2:   case MNGUST_DZ2to5_MY2:
   case MNGUST_DZ2to5_MX3:   case MNGUST_DZ2to5_MY3:
   case MNGUST_DZ2to5_MX4:   case MNGUST_DZ2to5_MY4:
       grzHI = 1000000;//верх граница
       grzLOW= -1000000;//низ граница
       step  = 1;//шаг
   break;

  //выдержки
   case MNGVID_DZ2to5MF:
   case MNGVID_MDZ2to5MF:
   case MNGVID_DZ2to5OF:
   case MNGVUSK_DZ2to5MF:
   case MNGVUSK_MDZ2to5MF:

   case MNGUSK_DZ2to5MF_VV:
   case MNGUSK_DZ2to5MF_OU:
   case MNGUSK_DZ2to5MF_TU:

   case MNGUSK_MDZ2to5MF_VV:
   case MNGUSK_MDZ2to5MF_OU:
   case MNGUSK_MDZ2to5MF_TU:

   case MNGUSK_DZ2to5OF_VV:
   case MNGUSK_DZ2to5OF_OU:
   case MNGUSK_DZ2to5OF_TU:

       grzHI = 2000000;//верх граница
       grzLOW= 0;//низ граница
       step  = 1;//шаг
   break;

   default:return ust;//уставка управления
  }//switch

  if(codec) return ust*step;
//раскодировать уставку
  if(ust<grzLOW) return ERROR_UST;
  if(ust>grzHI)  return ERROR_UST;
  return ust/step;
}//codecUstDZ2to5(char *buf, short offset, int ust)

int isDISactiv_DZ2to5(int idxC)
{
 //активность Регистратора ДИС
  return 0;//нет активности
}//isDISactiv_DZ2to5(int idxC)

char copyDZ2ToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//стереть старое
//зарегистрировать компонент в репозитарии
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  DZ2_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_DZ2;//sub_menu_component;

  rpzcomponent_obj.twinControl = &(twinDZ2[0]);//массив контроля близнецов
  twinDZ2[0].twin_different = diffDZ3ToRepozitar;//ф-ция контроля близнецов
  twinDZ2[1].twin_different = diffDZ4ToRepozitar;//ф-ция контроля близнецов
  twinDZ2[2].twin_different = diffDZ5ToRepozitar;//ф-ция контроля близнецов

  rpzcomponent_obj.cntClon     = CNT_STUPEN_DZ;   //к-во клонов
  rpzcomponent_obj.numClon     = 2;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstDZ2;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstDZ2;//подготовка уставок
  rpzcomponent_obj.initIOCmd      = initIOCmd_DZ2;      //инициал IO команд
  rpzcomponent_obj.initTLCmd      = initTLCmd_DZ2;      //инициал TL команд
  rpzcomponent_obj.initENACmd     = initENACmd_DZ2;     //инициал ENA команд
  rpzcomponent_obj.bo_bvCmd       = NULL; //настройка БО БВ команд
  rpzcomponent_obj.isDISactiv     = isDISactiv_DZ2to5; //активность Регистратора ДИС
  rpzcomponent_obj.setBOBVtimer   = NULL; //инициал таймеров БО БВ

  rpzcomponent_obj.nameStatusIO = ionsDZ2;          //имена и статус команд IO
  rpzcomponent_obj.initTimers   = initTimersDZ2;    //запрос и инициал таймеров
  rpzcomponent_obj.logic        = logicDZ2to5;         //логика компонента

  rpzcomponent_obj.codecUst = codecUstDZ2;   //кодировать-раскодировать уставку

  return 0;//не пакетная регистрация
}//

#endif // _HIDE_COMPONENT

