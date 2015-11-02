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
#define KOD_COMPONENT  MTZ_COMP1
//к-во ступеней
#define CNT_STUPEN_MTZ  5

#endif // _HIDE_COMPONENT

//РАСПРЕДЕЛЕНИЕ УСТАВОК  в менеджере уставок
//уставка сработки
#define MNGUST_MTZ2to5     0
#define MNGUST_MTZ2to5_V   1
#define MNGUST_MTZ2to5_N   2
#define MNGUST_MTZ2to5_PN  3
#define MNGUST_MTZ2to5_UPN 4

//уставка выдержки
#define MNGVID_MTZ2to5    5
#define MNGVID_MTZ2to5_V  6
#define MNGVID_MTZ2to5_N  7
#define MNGVID_MTZ2to5_PN 8
#define MNGVUSK_MTZ2to5   9
//ускорение
//Ускор МТЗ2 
#define MNGUSK_MTZ2to5      10
//Ускор МТЗ2 ОУ
#define MNGUSK_MTZ2to5_OU   11
//Ускор МТЗ2 ТУ
#define MNGUSK_MTZ2to5_TU   12

//Ускор МТЗ2 ВПД
#define MNGUSK_MTZ2to5_V    13
//Ускор МТЗ2 ОУ ВПД
#define MNGUSK_MTZ2to5_V_OU 14
//Ускор МТЗ2 ТУ ВПД
#define MNGUSK_MTZ2to5_V_TU 15

//Ускор МТЗ2 НЗД
#define MNGUSK_MTZ2to5_N    16
//Ускор МТЗ2 ОУ НЗД
#define MNGUSK_MTZ2to5_N_OU 17
//Ускор МТЗ2 ТУ НЗД
#define MNGUSK_MTZ2to5_N_TU 18

//Ускор МТЗ2 ПН
#define MNGUSK_MTZ2to5_PN    19
//Ускор МТЗ2 ОУ ПН
#define MNGUSK_MTZ2to5_PN_OU 20
//Ускор МТЗ2 ТУ НП
#define MNGUSK_MTZ2to5_PN_TU 21


//уставка управления
#define MNGUPR_MTZ2to5        22
//к-во уставок в менеджере уставок
#define MNGUST_MTZ2to5_TOTAL  23
//#define MNGUST_BOBV_MTZ2to5  MNGUST_MTZ2to5_TOTAL

//РАСПРЕДЕЛЕНИЕ ENA команд
#define ENA_MTZ2to5_HALF1  0
#define ENA_MTZ2to5_HALF2  1
//ENA_MTZ2
#define ENA1_MTZ2to5       2
//ENA_MTZ2_VPD
#define ENA2_MTZ2to5       3
//ENA_MTZ2_NZD
#define ENA3_MTZ2to5       4
//ENA_USK_MTZ2
#define ENA4_MTZ2to5       5
//ENA_AUSK_MTZ2to5
#define ENA5_MTZ2to5       6
//ENA_TUSK_MTZ2to5
#define ENA6_MTZ2to5       7
//к-во ENA команд
#define ENACMD_MTZ2to5_TOTAL 8

//РАСПРЕДЕЛЕНИЕ УСТАВОК в супервизоре
//уставка сработки
#define SPVSRABUST_MTZ2to5     0
#define SPVSRABUST_MTZ2to5_V   1
#define SPVSRABUST_MTZ2to5_N   2
#define SPVSRABUST_MTZ2to5_PN  3
#define SPVSRABUST_MTZ2to5_UPN 4
//уставка возврата
#define SPVVOZVUST_MTZ2to5     5
#define SPVVOZVUST_MTZ2to5_V   6
#define SPVVOZVUST_MTZ2to5_N   7
#define SPVVOZVUST_MTZ2to5_PN  8
#define SPVVOZVUST_MTZ2to5_UPN 9

//уставка SPV выход
#define SPV_OUTA_MTZ2to5      10
#define SPV_OUTB_MTZ2to5      11
#define SPV_OUTC_MTZ2to5      12

#define SPV_OUTA_MTZ2to5_V    13
#define SPV_OUTB_MTZ2to5_V    14
#define SPV_OUTC_MTZ2to5_V    15

#define SPV_OUTA_MTZ2to5_N    16
#define SPV_OUTB_MTZ2to5_N    17
#define SPV_OUTC_MTZ2to5_N    18

#define SPV_OUTA_MTZ2to5_PN   19
#define SPV_OUTB_MTZ2to5_PN   20
#define SPV_OUTC_MTZ2to5_PN   21

#define SPV_OUTA_MTZ2to5_UPN  22
#define SPV_OUTB_MTZ2to5_UPN  23
#define SPV_OUTC_MTZ2to5_UPN  24
//к-во уставок в супервизоре
#define SPVUST_MTZ2to5_TOTAL  25

//---------------IO COMMAND------------------
//РАСПРЕДЕЛЕНИЕ IO КОМАНД ДЛЯ MTZ2to5
//Стат блок МТЗ2
//CMD_MTZ2to5
#define IOCMD1_MTZ2to5 0
//Блок уск МТЗ2
//CMD_BLOK_USK_MTZ2to5
#define IOCMD2_MTZ2to5 1
//Операт уск МТЗ2
//CMD_OPERAT_USK_MTZ2to5
#define IOCMD3_MTZ2to5 2
//Сраб ПО МТЗ2
//CMD_MTZ2to5_PO1
#define IOCMD4_MTZ2to5 3
//Сраб ПО МТЗ2 ВПД
//CMD_MTZ2to5_PO2
#define IOCMD5_MTZ2to5 4
//Сраб ПО МТЗ2 НЗД
//CMD_MTZ2to5_PO3
#define IOCMD6_MTZ2to5 5
//Сраб ПО МТЗ2 ПН
//CMD_MTZ2to5_PO4
#define IOCMD7_MTZ2to5 6
//Сраб МТЗ2
//CMD_MTZ2to5
#define IOCMD8_MTZ2to5 7
//Теле уск MTZ2to5
#define IOCMD9_MTZ2to5 8
//Сектор МТЗ2to5 ВПД
#define IOCMD10_MTZ2to5 9
//Сектор МТЗ2to5 НЗД
#define IOCMD11_MTZ2to5 10
//к-во IO команд
#define IOCMD_MTZ2to5_TOTAL    11

//---------------TL COMMAND------------------
//РАСПРЕДЕЛЕНИЕ TL КОМАНД ДЛЯ MTZ2to5
//RES_MTZ2to5
#define TLCMD1_MTZ2to5  0
//RES_MTZ2to5_V
#define TLCMD2_MTZ2to5  1
//RES_MTZ2to5_N
#define TLCMD3_MTZ2to5  2
//RES_MTZ2to5_PN
#define TLCMD4_MTZ2to5  3
//MTZ2to5_PO1
#define TLCMD5_MTZ2to5  4
//MTZ2to5_PO2
#define TLCMD6_MTZ2to5  5
//MTZ2to5_PO3
#define TLCMD7_MTZ2to5  6
//MTZ2to5_PO4
#define TLCMD8_MTZ2to5  7

//------------------------
//ELOLDTRG_OUSKOR_MTZ2to5
#define TLCMD9_MTZ2to5  8
//ELOUTTRG_OUSKOR_MTZ2to5
#define TLCMD10_MTZ2to5 9

//ELOLDTRG_AUSKOR_MTZ2to5
#define TLCMD11_MTZ2to5 10
//ELOUTTRG_AUSKOR_MTZ2to5
#define TLCMD12_MTZ2to5 11

//ELOLDTRG_TUSKOR_MTZ2to5
#define TLCMD13_MTZ2to5 12
//ELOUTTRG_TUSKOR_MTZ2to5
#define TLCMD14_MTZ2to5 13

//MTZ2to5_USKOR
#define TLCMD15_MTZ2to5 14

#define TL7_MTZ2TO5     15
#define TL8_MTZ2TO5     16
#define TL9_MTZ2TO5     17
#define TL10_MTZ2TO5    18
//------------------------

//ELOLDTRG_OUSKOR_MTZ2to5_V
#define TLCMD9_MTZ2to5_V  19
//ELOUTTRG_OUSKOR_MTZ2to5_V
#define TLCMD10_MTZ2to5_V 20

//ELOLDTRG_AUSKOR_MTZ2to5_V
#define TLCMD11_MTZ2to5_V 21
//ELOUTTRG_AUSKOR_MTZ2to5_V
#define TLCMD12_MTZ2to5_V 22

//ELOLDTRG_TUSKOR_MTZ2to5_V
#define TLCMD13_MTZ2to5_V 23
//ELOUTTRG_TUSKOR_MTZ2to5_V
#define TLCMD14_MTZ2to5_V 24

//MTZ2to5_USKOR_v
#define TLCMD15_MTZ2to5_V 25

#define TL7_MTZ2TO5_V     26
#define TL8_MTZ2TO5_V     27
#define TL9_MTZ2TO5_V     28
#define TL10_MTZ2TO5_V    29
//------------------------

//ELOLDTRG_OUSKOR_MTZ2to5_N
#define TLCMD9_MTZ2to5_N  30
//ELOUTTRG_OUSKOR_MTZ2to5_N
#define TLCMD10_MTZ2to5_N 31

//ELOLDTRG_AUSKOR_MTZ2to5_N
#define TLCMD11_MTZ2to5_N 32
//ELOUTTRG_AUSKOR_MTZ2to5_N
#define TLCMD12_MTZ2to5_N 33

//ELOLDTRG_TUSKOR_MTZ2to5_N
#define TLCMD13_MTZ2to5_N 34
//ELOUTTRG_TUSKOR_MTZ2to5_N
#define TLCMD14_MTZ2to5_N 35

//MTZ2to5_USKOR_N
#define TLCMD15_MTZ2to5_N 36

#define TL7_MTZ2TO5_N     37
#define TL8_MTZ2TO5_N     38
#define TL9_MTZ2TO5_N     39
#define TL10_MTZ2TO5_N    40
//------------------------

//ELOLDTRG_OUSKOR_MTZ2to5_PN
#define TLCMD9_MTZ2to5_PN  41
//ELOUTTRG_OUSKOR_MTZ2to5_PN
#define TLCMD10_MTZ2to5_PN 42

//ELOLDTRG_AUSKOR_MTZ2to5_PN
#define TLCMD11_MTZ2to5_PN 43
//ELOUTTRG_AUSKOR_MTZ2to5_PN
#define TLCMD12_MTZ2to5_PN 44

//ELOLDTRG_TUSKOR_MTZ2to5_PN
#define TLCMD13_MTZ2to5_PN 45
//ELOUTTRG_TUSKOR_MTZ2to5_PN
#define TLCMD14_MTZ2to5_PN 46

//MTZ2to5_USKOR_v
#define TLCMD15_MTZ2to5_PN 47

#define TL7_MTZ2TO5_PN     48
#define TL8_MTZ2TO5_PN     49
#define TL9_MTZ2TO5_PN     50
#define TL10_MTZ2TO5_PN    51
//------------------------

//AU_MTZ2to5
#define TLCMD16_MTZ2to5    52
//TU_MTZ2to5
#define TLCMD17_MTZ2to5    53
//VU_TU_MTZ2to5
#define TLCMD18_MTZ2to5    54
//OU_MTZ2to5
#define TLCMD19_MTZ2to5    55

#define TLTMP_MTZ2to5      56

//isFAILU_INVERT MTZ2to5
//#define TLCMDFU_MTZ2to5    57

//ELOLDTRG_NCN_MTZ2to5
#define TLCMDOLDNCN_MTZ2to5 58
//ELOUTTRG_NCN_MTZ2to5
#define TLCMDOUTNCN_MTZ2to5 59

//к-во TL команд
#define TLCMD_MTZ2to5_TOTAL    60

//--------------- TIMERS ------------------
//РАСПРЕДЕЛЕНИЕ ТАЙМЕРОВ ДЛЯ MTZ2to5
//таймер MTZ2to5_TIM
#define TIMER1_MTZ2to5     0
//таймер MTZ2to5_V_TIM
#define TIMER2_MTZ2to5     1
//таймер MTZ2to5_N_TIM
#define TIMER3_MTZ2to5     2
//таймер MTZ2to5_PN_TIM
#define TIMER4_MTZ2to5     3

//таймер VUSKOR_MTZ2to5_TIM
#define TIMER_VUSK_MTZ2to5 4

//------------------------
//USKOR_MTZ2to5_TIM
#define TIMER5_MTZ2to5     5
//USKOR_MTZ2to5_OU_TIM
#define TIMER5_MTZ2to5_OU  6
//USKOR_MTZ2to5_TU_TIM
#define TIMER5_MTZ2to5_TU  7
//------------------------

//USKOR_MTZ2to5_V_TIM
#define TIMER5_MTZ2to5_V     8
//USKOR_MTZ2to5_V_OU_TIM
#define TIMER5_MTZ2to5_V_OU  9
//USKOR_MTZ2to5_V_TU_TIM
#define TIMER5_MTZ2to5_V_TU  10
//------------------------

//USKOR_MTZ2to5_N_TIM
#define TIMER5_MTZ2to5_N     11
//USKOR_MTZ2to5_N_OU_TIM
#define TIMER5_MTZ2to5_N_OU  12
//USKOR_MTZ2to5_N_TU_TIM
#define TIMER5_MTZ2to5_N_TU  13
//------------------------

//USKOR_MTZ2to5_PN_TIM
#define TIMER5_MTZ2to5_PN     14
//USKOR_MTZ2to5_PN_OU_TIM
#define TIMER5_MTZ2to5_PN_OU  15
//USKOR_MTZ2to5_PN_TU_TIM
#define TIMER5_MTZ2to5_PN_TU  16
//------------------------

//таймер BO_MTZ2to5_TIM
#define TIMER_BO_MTZ2to5       17
//к-во таймеров
#define TIMERS_MTZ2to5_TOTAL   18

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "PRM1Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_MTZ[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//индекс уставок в супервизоре
extern int  IndexIO;//индекс IO

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern char *bitStringUNI[];
extern int offsetUstMngPRM1;//смещение на уставки PRM1

void PereinitUstListCompMTZ2(short flg);
void UstListCompMTZ2();
void ustRedactorCompMTZ2();
void UstCompMTZ2();
short  KadrMenuFormat_ust_compMTZ2(WorkControl *workCntr);

void PereinitVidListCompMTZ2(short flg);
void VidListCompMTZ2();
void vidRedactorCompMTZ2();
void VidCompMTZ2();
short  KadrMenuFormat_vid_compMTZ2(void *workCntr);

void PereinitUprListCompMTZ2(short flg);
void UprListCompMTZ2();
void uprRedactorCompMTZ2();
void UprCompMTZ2();
short  KadrMenuFormat_upr_compMTZ2(void *workCntr);
int   initUstMTZ2(char init);
void  prepareUstMTZ2(short idxC);
 
void EditUstMTZ2();
void EditVidMTZ2();
void EditUprMTZ2();
int codecUstMTZ2(char codec, short offset, int ust);

short  KadrMenuFormat_ustvidMTZ(void *workCntr);
short chooseTxtMTZ(char *locTxt, short ibit, UNS_32 ust);
char *selectorUprStrMTZ2(short iBit, UNS_32 ustUpr);
void UpravlChooserMTZInKadr(char *nameUpr, short ibit, void *workCntr);//(char *nameUpr, short ibit, WorkControl *workCntr);
void UpravlRedactorChooseMTZ(char *nameUpr, short ibit);
void diffMTZ3ToRepozitar();
void diffMTZ4ToRepozitar();
void diffMTZ5ToRepozitar();
void  logicMTZ2to5(int idxC);
int   isDISactiv_MTZ2to5(int idxC);

TWIN_DIFFERENT twinMTZ2[3];//массив контроля близнецов

int  offsetIOCmdMTZ5;//смещение для IO MTZ5

char MTZ2_TITLE[] = "МТЗ2";

IONAMESTATUS_COMPONENT ionsMTZ2[IOCMD_MTZ2to5_TOTAL] =
{
  {
    1,//статус iocmd1
    "Стат блок МТЗ2"
  },
  {
    1,//статус iocmd2
    "Блок уск МТЗ2"
  },
  {
    1,//статус iocmd3
    "Операт уск МТЗ2"
  },
  {
    1,//статус iocmd4
    "Сраб ПО МТЗ2"
  },
  {
    1,//статус iocmd5
    "Сраб ПО МТЗ2 ВПД"
  },
  {
    1,//статус iocmd6
    "Сраб ПО МТЗ2 НЗД"
  },
  {
    1,//статус iocmd7
    "Сраб ПО МТЗ2 ПН"
  },
  {
    1,//статус iocmd8
    "Сраб МТЗ2"
  },
  {
    1,//статус iocmd9
    "Теле уск МТЗ2"
  },
  {
    1,//статус iocmd10
    "Сектор МТЗ2 ВПД"
  },
  {
    1,//статус iocmd11
    "Сектор МТЗ2 НЗД"
  }
};

LineMenuItem sub_menu_comp_MTZ2[8] =
{
  { MTZ2_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_MTZ, typeMenuSub},//control_item, parent
  { "Уставки МТЗ2",    (void*)&UstListCompMTZ2, typeMenuProg},
  { "Выдержки МТЗ2",   (void*)&VidListCompMTZ2, typeMenuProg},
  { "Управление МТЗ2", (void*)&UprListCompMTZ2, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compMTZ2[] =
{
  { "Уставки МТЗ2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ2, typeMenuList},//control_item, parent
  { "Уст МТЗ2",         (void*)&UstCompMTZ2, typeMenuProg},
  { "Уст МТЗ2 вперед",  (void*)&UstCompMTZ2, typeMenuProg},
  { "Уст МТЗ2 назад",   (void*)&UstCompMTZ2, typeMenuProg},
  { "Уст МТЗ2 ПМ",      (void*)&UstCompMTZ2, typeMenuProg},
  { "Уст напр МТЗ2 ПH", (void*)&UstCompMTZ2, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compMTZ2[] =
{
  { "Выдержки МТЗ2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ2, typeMenuList},//control_item, parent
/*
  { "Выдержка МТЗ2",         (void*)&VidCompMTZ2, typeMenuProg},
  { "Выдержка МТЗ2 вперед",  (void*)&VidCompMTZ2, typeMenuProg},
  { "Выдержка МТЗ2 назад",   (void*)&VidCompMTZ2, typeMenuProg},
  { "Выдержка МТЗ2 ПМ",      (void*)&VidCompMTZ2, typeMenuProg},
  { "Ввод ускор МТЗ2",       (void*)&VidCompMTZ2, typeMenuProg},

  { "Ускор МТЗ2 ВВ",         (void*)&VidCompMTZ2, typeMenuProg},
  { "Ускор МТЗ2 ОУ",         (void*)&VidCompMTZ2, typeMenuProg},
  { "Ускор МТЗ2 ТУ",         (void*)&VidCompMTZ2, typeMenuProg},

  { "Ускор МТЗ2 ВВ ВПД",     (void*)&VidCompMTZ2, typeMenuProg},
  { "Ускор МТЗ2 ОУ ВПД",     (void*)&VidCompMTZ2, typeMenuProg},
  { "Ускор МТЗ2 ТУ ВПД",     (void*)&VidCompMTZ2, typeMenuProg},

  { "Ускор МТЗ2 ВВ НЗД",     (void*)&VidCompMTZ2, typeMenuProg},
  { "Ускор МТЗ2 ОУ НЗД",     (void*)&VidCompMTZ2, typeMenuProg},
  { "Ускор МТЗ2 ТУ НЗД",     (void*)&VidCompMTZ2, typeMenuProg},

  { "Ускор МТЗ2 ВВ ПН",      (void*)&VidCompMTZ2, typeMenuProg},
  { "Ускор МТЗ2 ОУ ПН",      (void*)&VidCompMTZ2, typeMenuProg},
  { "Ускор МТЗ2 ТУ ПН",      (void*)&VidCompMTZ2, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compMTZ2[] =
{
  { "Управл МТЗ2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ2, typeMenuList},//control_item, parent
  { "Вид МТЗ2",           (void*)&UprCompMTZ2, typeMenuProg},
  { "Управл МТЗ2",        (void*)&UprCompMTZ2, typeMenuProg},
  { "МТЗ2 ВПД",           (void*)&UprCompMTZ2, typeMenuProg},
  { "МТЗ2 НЗД",           (void*)&UprCompMTZ2, typeMenuProg},
  { "Ускорение ВВ МТЗ2",  (void*)&UprCompMTZ2, typeMenuProg},
  { "Автомат уск МТЗ2",   (void*)&UprCompMTZ2, typeMenuProg},
  { "Телеускор МТЗ2",     (void*)&UprCompMTZ2, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompMTZ2(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_ust_compMTZ2);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UstListCompMTZ2()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compMTZ2);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompMTZ2);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompMTZ2()

void UstCompMTZ2()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compMTZ2);
  PassWord(EditUstMTZ2);
}//VidCompMTZ2()

void EditUstMTZ2()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compMTZ2);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompMTZ2()

//--------------------------------------------------

void PereinitVidListCompMTZ2(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_vid_compMTZ2);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void VidListCompMTZ2()
{
  SelectorMNGBAZA(MNGVID_MTZ2to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compMTZ2);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompMTZ2);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ2()

void VidCompMTZ2()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compMTZ2);
//  PassWord(EditVidAPV);
  EditVidMTZ2();
}//VidCompMTZ2()

void EditVidMTZ2()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compMTZ2);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompMTZ2(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compMTZ2, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UprListCompMTZ2()
{
  SelectorMNGBAZA(MNGUPR_MTZ2to5);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compMTZ2);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompMTZ2);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ2()

void UprCompMTZ2()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compMTZ2);
  PassWord(EditUprMTZ2);
}//VidCompMTZ2()

void EditUprMTZ2()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compMTZ2[LIGHTLINEMENU +1+SUBDATA].Line1;

  switch(LIGHTLINEMENU)
  {
    case 0: UpravlRedactorChooseMTZ(nameUpr, LIGHTLINEMENU);//редактировать уставку управления
    break;
    default:UpravlRedactor(nameUpr, LIGHTLINEMENU+1, &selectorUprStrMTZ2);//редактировать уставку управления
  }//switch

}//EditVidMTZ2()

short  KadrMenuFormat_upr_compMTZ2(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  short chooseBit = 2;//к-во бит в choose
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compMTZ2[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      if(i<(chooseBit-1))
        UpravlChooserMTZInKadr(nameUpr, i, workCntr);
      else
        strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
        selectorUprStrMTZ2(i+(chooseBit-1), getCurrentMngUSTAVKI()));

      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compMTZ2(WorkControl *workCntr)

char *selectorUprStrMTZ2(short iBit, UNS_32 ustUpr)
{
  switch(iBit)
  {

  default:;
  }//switch
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_WKL];
    return bitStringUNI[UNIUPR_OTKL];
}//selectorUprStrMTZ2(short ibit, UNS_32 ustUpr)

int initUstMTZ2(char init)
{
  //инициал уставок
  if (init)
  {
//уставка сработки
    tmpUSTAVKI[MNGUST_MTZ2to5]     = 100;
    tmpUSTAVKI[MNGUST_MTZ2to5_V]   = 110;
    tmpUSTAVKI[MNGUST_MTZ2to5_N]   = 120;
    tmpUSTAVKI[MNGUST_MTZ2to5_PN]  = 130;
    tmpUSTAVKI[MNGUST_MTZ2to5_UPN] = 131;
//уставка выдержки
    tmpUSTAVKI[MNGVID_MTZ2to5]    = 25;
    tmpUSTAVKI[MNGVID_MTZ2to5_V]  = 26;
    tmpUSTAVKI[MNGVID_MTZ2to5_N]  = 27;
    tmpUSTAVKI[MNGVID_MTZ2to5_PN] = 28;
    tmpUSTAVKI[MNGVUSK_MTZ2to5]   = 29;
//ускорение
//Ускор МТЗ2 
    tmpUSTAVKI[MNGUSK_MTZ2to5]      = 30;
    tmpUSTAVKI[MNGUSK_MTZ2to5_OU]   = 31;
//Ускор МТЗ2 ТУ
    tmpUSTAVKI[MNGUSK_MTZ2to5_TU]   = 32;

//Ускор МТЗ2 ВПД
    tmpUSTAVKI[MNGUSK_MTZ2to5_V]      = 33;
//Ускор МТЗ2 ОУ ВПД
    tmpUSTAVKI[MNGUSK_MTZ2to5_V_OU]   = 34;
//Ускор МТЗ2 ТУ ВПД
    tmpUSTAVKI[MNGUSK_MTZ2to5_V_TU]   = 35;

//Ускор МТЗ2 НЗД
    tmpUSTAVKI[MNGUSK_MTZ2to5_N]      = 36;
//Ускор МТЗ2 ОУ НЗД
    tmpUSTAVKI[MNGUSK_MTZ2to5_N_OU]   = 37;
//Ускор МТЗ2 ТУ НЗД
    tmpUSTAVKI[MNGUSK_MTZ2to5_N_TU]   = 38;

//Ускор МТЗ2 ПН
    tmpUSTAVKI[MNGUSK_MTZ2to5_PN]      = 39;
//Ускор МТЗ2 ОУ ПН
    tmpUSTAVKI[MNGUSK_MTZ2to5_PN_OU]   = 40;
//Ускор МТЗ2 ТУ ПН
    tmpUSTAVKI[MNGUSK_MTZ2to5_PN_TU]   = 41;
//уставка управления
    tmpUSTAVKI[MNGUPR_MTZ2to5] = 0;

  }//if

  IndexUstSPV += SPVUST_MTZ2to5_TOTAL;//индекс уставок в супервизоре
  return MNGUST_MTZ2to5_TOTAL;//к-во уставок в менеджере уставок
}//initUstMTZ2(short mngUst, char init)

void  prepareUstMTZ2(short idxC)
{
  //подготовка ENA команд для клона
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_MTZ2to5), ENACMD_MTZ2to5_TOTAL);
  //подготовка уставок
  int tmpOffsetUSpv = getOffsetSPVUstCnf(idxC);//смещение уставок внутри супервизора

    //уставка SPV сработки
    int tmp1 = 
    SPV_UST(SPVSRABUST_MTZ2to5) = codecUstMTZ2(1, MNGUST_MTZ2to5, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ2to5));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_MTZ2to5) = tmp1 - tmp1/20;//5%

    //уставка SPV сработки
        tmp1 =
    SPV_UST(SPVSRABUST_MTZ2to5_V) = codecUstMTZ2(1, MNGUST_MTZ2to5_V, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ2to5_V));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_MTZ2to5_V) = tmp1 - tmp1/20;//5%

    //уставка SPV сработки
        tmp1 =
    SPV_UST(SPVSRABUST_MTZ2to5_N) = codecUstMTZ2(1, MNGUST_MTZ2to5_N, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ2to5_N));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_MTZ2to5_N) = tmp1 - tmp1/20;//5%

    //уставка SPV сработки
        tmp1 =
    SPV_UST(SPVSRABUST_MTZ2to5_PN) = codecUstMTZ2(1, MNGUST_MTZ2to5_PN, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ2to5_PN));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_MTZ2to5_PN) = tmp1 - tmp1/20;//5%

    //уставка SPV сработки DOWN
        tmp1 =
    SPV_UST(SPVSRABUST_MTZ2to5_UPN) = codecUstMTZ2(1, MNGUST_MTZ2to5_UPN, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ2to5_UPN));
    //уставка SPV возврата
    SPV_UST(SPVVOZVUST_MTZ2to5_UPN) = tmp1 + tmp1/20;//5% DOWN

  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //компонент в конфигурации

            //таймер MTZ2_TIM
  setTimerPorog(tmpOffsetT+ TIMER1_MTZ2to5,
          codecUstMTZ2(1, MNGVID_MTZ2to5, getNativUstMngUSTAVKI(idxC, MNGVID_MTZ2to5)));

          //таймер MTZ2_V_TIM
  setTimerPorog(tmpOffsetT+ TIMER2_MTZ2to5,
          codecUstMTZ2(1, MNGVID_MTZ2to5_V, getNativUstMngUSTAVKI(idxC, MNGVID_MTZ2to5_V)));

          //таймер MTZ2_N_TIM
  setTimerPorog(tmpOffsetT+ TIMER3_MTZ2to5,
          codecUstMTZ2(1, MNGVID_MTZ2to5_N, getNativUstMngUSTAVKI(idxC, MNGVID_MTZ2to5_N)));

           //таймер MTZ2_PN_TIM
  setTimerPorog(tmpOffsetT+ TIMER4_MTZ2to5,
          codecUstMTZ2(1, MNGVID_MTZ2to5_PN, getNativUstMngUSTAVKI(idxC, MNGVID_MTZ2to5_PN)));

           //таймер VUSKOR_MTZ2_TIM
  setTimerPorog(tmpOffsetT+ TIMER_VUSK_MTZ2to5,
          codecUstMTZ2(1, MNGVUSK_MTZ2to5, getNativUstMngUSTAVKI(idxC, MNGVUSK_MTZ2to5)));

  int  tmp =    codecUstMTZ2(1, MNGUSK_MTZ2to5_OU, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_OU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_OU, tmp);

//Ускор МТЗ2 
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5, tmp);
//Ускор МТЗ2 ТУ
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_TU, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_TU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_TU, tmp);

//Ускор МТЗ2 ОУ ВПД
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_V_OU, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_V_OU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_V_OU, tmp);
//Ускор МТЗ2 ВПД
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_V, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_V));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_V, tmp);
//Ускор МТЗ2 ТУ ВПД
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_V_TU, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_V_TU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_V_TU, tmp);

//Ускор МТЗ2 ОУ НЗД
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_N_OU, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_N_OU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_N_OU, tmp);
//Ускор МТЗ2 НЗД
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_N, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_N));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_N, tmp);
//Ускор МТЗ2 ТУ НЗД
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_N_TU, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_N_TU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_N_TU, tmp);

//Ускор МТЗ2 ОУ ПН
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_PN_OU, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_PN_OU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_PN_OU, tmp);
//Ускор МТЗ2 ПН
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_PN, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_PN));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_PN, tmp);
//Ускор МТЗ2 ТУ ПН
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_PN_TU, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_PN_TU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_PN_TU, tmp);

        //таймер  BO
  setTimerPorog(tmpOffsetT+ TIMER_BO_MTZ2to5, 10);


}//prepareUstMTZ2(short idxC)

int initIOCmd_MTZ2()
{
  //инициал IO команд
  offsetIOCmdMTZ5 = IndexIO;//смещение для IO MTZ5
  return commonInitIOCmd(IOCMD_MTZ2to5_TOTAL);
}

int initTLCmd_MTZ2()
{
  //инициал TL команд
  return commonInitTLCmd(TLCMD_MTZ2to5_TOTAL);
}//initTLCmd_MTZ2()

int initENACmd_MTZ2()
{
  //инициал ENA команд
  return commonInitENACmd(ENACMD_MTZ2to5_TOTAL);
}//initENACmd_MTZ2()

void initTimersMTZ2(short idxC)
{
  //запрос и инициал таймеров
  commonInitTimers(TIMERS_MTZ2to5_TOTAL);

}//initTimersMTZ2()

int codecUstMTZ2(char codec, short offset, int ust)
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
   case MNGUST_MTZ2to5:
   case MNGUST_MTZ2to5_V:
   case MNGUST_MTZ2to5_N:
   case MNGUST_MTZ2to5_PN:
   case MNGUST_MTZ2to5_UPN:
       grzHI = 1000000;//верх граница
       grzLOW= 0;//низ граница
       step  = 1;//шаг
   break;

  //выдержки
//   case MNGUST_BOBV_MTZ2to5://уставка БО БВ
   case MNGVID_MTZ2to5:
   case MNGVID_MTZ2to5_V:
   case MNGVID_MTZ2to5_N:
   case MNGVID_MTZ2to5_PN:
   case MNGVUSK_MTZ2to5:

   case MNGUSK_MTZ2to5_OU:
//Ускор МТЗ2 АУ
   case MNGUSK_MTZ2to5:
//Ускор МТЗ2 ТУ
   case MNGUSK_MTZ2to5_TU:

//Ускор МТЗ2 ОУ ВПД
   case MNGUSK_MTZ2to5_V_OU:
//Ускор МТЗ2 АУ ВПД
   case MNGUSK_MTZ2to5_V:
//Ускор МТЗ2 ТУ ВПД
   case MNGUSK_MTZ2to5_V_TU:

//Ускор МТЗ2 ОУ НЗД
   case MNGUSK_MTZ2to5_N_OU:
//Ускор МТЗ2 АУ НЗД
   case MNGUSK_MTZ2to5_N:
//Ускор МТЗ2 ТУ НЗД
   case MNGUSK_MTZ2to5_N_TU:

//Ускор МТЗ2 ОУ ПН
   case MNGUSK_MTZ2to5_PN_OU:
//Ускор МТЗ2 АУ ПН
   case MNGUSK_MTZ2to5_PN:
//Ускор МТЗ2 ТУ ПН
   case MNGUSK_MTZ2to5_PN_TU:

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
}//codecUstMTZ2(char *buf, short offset, int ust)

int isDISactiv_MTZ2to5(int idxC)
{
 //активность Регистратора ДИС
  return 0;//нет активности
}//isDISactiv_MTZ2to5(int idxC)

char copyMTZ2ToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//стереть старое
//копировать компонент в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.permanent = 0; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  MTZ2_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_MTZ2;//sub_menu_component;

  rpzcomponent_obj.twinControl = &(twinMTZ2[0]);//массив контроля близнецов
  twinMTZ2[0].twin_different = diffMTZ3ToRepozitar;//ф-ция контроля близнецов
  twinMTZ2[1].twin_different = diffMTZ4ToRepozitar;//ф-ция контроля близнецов
  twinMTZ2[2].twin_different = diffMTZ5ToRepozitar;//ф-ция контроля близнецов

  rpzcomponent_obj.cntClon     = CNT_STUPEN_MTZ;   //к-во клонов
  rpzcomponent_obj.numClon     = 2;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstMTZ2;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstMTZ2;//подготовка уставок
  rpzcomponent_obj.initIOCmd      = initIOCmd_MTZ2;      //инициал IO команд
  rpzcomponent_obj.initTLCmd      = initTLCmd_MTZ2;      //инициал TL команд
  rpzcomponent_obj.initENACmd     = initENACmd_MTZ2;     //инициал ENA команд
  rpzcomponent_obj.bo_bvCmd       = NULL; //настройка БО БВ команд
  rpzcomponent_obj.isDISactiv     = isDISactiv_MTZ2to5; //активность Регистратора ДИС
  rpzcomponent_obj.setBOBVtimer   = NULL; //инициал таймеров БО БВ

  rpzcomponent_obj.nameStatusIO = ionsMTZ2;          //имена и статус команд IO
  rpzcomponent_obj.initTimers   = initTimersMTZ2;    //запрос и инициал таймеров
  rpzcomponent_obj.logic        = logicMTZ2to5;         //логика компонента

  rpzcomponent_obj.codecUst = codecUstMTZ2;   //кодировать-раскодировать уставку

  return 0;//не пакетная регистрация
}//

#endif // _HIDE_COMPONENT

