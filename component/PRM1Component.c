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
#include "virtualMenu\viewMenuSub.h"

#include "psupervisor\psupervisor.h"

#include "toSpeedOptim.h"

#include "..\bazis.h"

//код компонентов
#define KOD_COMPONENT  PRM1_COMP1
//к-во ступеней
#define CNT_STUPEN_PRM1  1

#endif // _HIDE_COMPONENT

//РАСПРЕДЕЛЕНИЕ УСТАВОК  в менеджере уставок
//уставка Допуск ДВ
#define MNGUST_PRM1_DDV1   0
#define MNGUST_PRM1_DDV2   1
#define MNGUST_PRM1_DDV3   2
#define MNGUST_PRM1_DDV4   3
#define MNGUST_PRM1_DDV5   4
#define MNGUST_PRM1_DDV6   5
#define MNGUST_PRM1_DDV7   6
#define MNGUST_PRM1_DDV8   7
#define MNGUST_PRM1_DDV9   8
#define MNGUST_PRM1_DDV10  9
#define MNGUST_PRM1_DDV11  10
#define MNGUST_PRM1_DDV12  11
#define MNGUST_PRM1_DDV13  12
#define MNGUST_PRM1_DDV14  13
#define MNGUST_PRM1_DDV15  14
#define MNGUST_PRM1_DDV16  15
#define MNGUST_PRM1_DDV17  16
#define MNGUST_PRM1_DDV18  17
#define MNGUST_PRM1_DDV19  18
#define MNGUST_PRM1_DDV20  19
#define MNGUST_PRM1_DDV21  20
#define MNGUST_PRM1_DDV22  21
#define MNGUST_PRM1_DDV23  22
#define MNGUST_PRM1_DDV24  23
#define MNGUST_PRM1_DDV25  24
#define MNGUST_PRM1_DDV26  25
#define MNGUST_PRM1_DDV27  26
#define MNGUST_PRM1_DDV28  27
#define MNGUST_PRM1_DDV29  28
#define MNGUST_PRM1_DDV30  29
#define MNGUST_PRM1_DDV31  30
#define MNGUST_PRM1_DDV32  31
#define MNGUST_PRM1_DDV33  32
#define MNGUST_PRM1_DDV34  33
#define MNGUST_PRM1_DDV35  34
#define MNGUST_PRM1_DDV36  35

//уставка выдержки
#define MNGVID_PRM1     36
#define MNGVID_PRM1_V   37
#define MNGVID_PRM1_DIS 38
//выдержкa UI НЦН ДЗ
#define MNGVID_PRM1_UINCNDZ 39
//выдержка обрат последоват CM НЦН ДЗ
#define MNGVID_PRM1_CMNCNDZ 40

//уставка управления PRM1
#define MNGUPR_PRM1    41
//уставка управления DV
#define MNGUPR_DVLOW   42
#define MNGUPR_DVMIDD  43
#define MNGUPR_DVHI    44
//уставка управления RELE
#define MNGUPR_RELE    45
//уставка управления CDI
#define MNGUPR_CDI     46

//уставки PRM1 блок откл
#define MNGUST_PRM1_BO  47
//уставки PRM1 блок вкл
#define MNGUST_PRM1_BV  48
//к-во уставок в менеджере уставок
#define MNGUST_PRM1_TOTAL  49

//РАСПРЕДЕЛЕНИЕ ENA КОМАНД
//неисправность цепей напр МТЗ
#define ENA_PRM1_FAILU_MTZ  0
//неисправность цепей напр ДЗ
#define ENA_PRM1_FAILU_DZ   1
//к-во ENA команд
#define ENACMD_PRM1_TOTAL   2

//РАСПРЕДЕЛЕНИЕ УСТАВОК в супервизоре
//уставка Допуск ДВ
#define SPV_DDV1_UST       0
#define SPV_DDV2_UST       1
#define SPV_DDV3_UST       2
#define SPV_DDV4_UST       3
#define SPV_DDV5_UST       4
#define SPV_DDV6_UST       5
#define SPV_DDV7_UST       6
#define SPV_DDV8_UST       7
#define SPV_DDV9_UST       8
#define SPV_DDV10_UST      9
#define SPV_DDV11_UST      10
#define SPV_DDV12_UST      11
#define SPV_DDV13_UST      12
#define SPV_DDV14_UST      13
#define SPV_DDV15_UST      14
#define SPV_DDV16_UST      15
#define SPV_DDV17_UST      16
#define SPV_DDV18_UST      17
#define SPV_DDV19_UST      18
#define SPV_DDV20_UST      19
#define SPV_DDV21_UST      20
#define SPV_DDV22_UST      21
#define SPV_DDV23_UST      22
#define SPV_DDV24_UST      23
#define SPV_DDV25_UST      24
#define SPV_DDV26_UST      25
#define SPV_DDV27_UST      26
#define SPV_DDV28_UST      27
#define SPV_DDV29_UST      28
#define SPV_DDV30_UST      29
#define SPV_DDV31_UST      30
#define SPV_DDV32_UST      31
#define SPV_DDV33_UST      32
#define SPV_DDV34_UST      33
#define SPV_DDV35_UST      34
#define SPV_DDV36_UST      35

//уставка сработки
#define SPVSRAB_02UH       36
#define SPVSRAB_12IH       37
#define SPVSRAB_U005       38
#define SPVSRAB_UCM005     39
#define SPVSRAB_ICM005     40
#define SPVSRAB_U025       41
//уставка возврата
#define SPVVOZV_02UH       42
#define SPVVOZV_12IH       43
#define SPVVOZV_U005       44
#define SPVVOZV_UCM005     45
#define SPVVOZV_ICM005     46
#define SPVVOZV_U025       47

//уставка SPV выход
#define SPV_OUTA_02UH      48
#define SPV_OUTB_02UH      49
#define SPV_OUTC_02UH      50

#define SPV_OUTA_12IH      51
#define SPV_OUTB_12IH      52
#define SPV_OUTC_12IH      53

#define SPV_OUTA_U005      54
#define SPV_OUTB_U005      55
#define SPV_OUTC_U005      56

#define SPV_OUTAL_U025     57
#define SPV_OUTBL_U025     58
#define SPV_OUTCL_U025     59

#define SPV_OUTAF_U025     60
#define SPV_OUTBF_U025     61
#define SPV_OUTCF_U025     62

#define SPV_OUT_UCM005     63

#define SPV_OUT_ICM005     64

//уставка ДВ -ПрямойИнверсный
#define SPV_UPR_DVLOW      65
#define SPV_UPR_DVMIDD     66
#define SPV_UPR_DVHI       67
//уставка Реле -НормальныйТриггерный
#define SPV_UPR_RELE       68
//уставка СДИ -НормальныйТриггерный
#define SPV_UPR_CDI        69
//НЦН ДЗ
#define SPVSRAB_DZ_02UH    70
#define SPVVOZV_DZ_02UH    71
#define SPV_OUT_DZ_02UH    72
#define SPV_OUT_DZ_UCMICM  73          
#define SPV_DZ_UCMICM      74

//к-во уставок в супервизоре
#define SPVUST_PRM1_TOTAL  75

//---------------IO COMMAND------------------
//РАСПРЕДЕЛЕНИЕ IO КОМАНД ДЛЯ PRM1
//Положение ВВ
//CMD_POL_VV
#define IOCMD1_PRM1 0
//Неиспр цепей напряжения ДЗ
//CMD_FAILU_COMMON
#define IOCMD2_PRM1 1
//Руч откл ВВ
//CMD_HANDOTKL_VV
#define IOCMD3_PRM1 2
//CMD_BO
//Работа БО
#define IOCMD4_PRM1 3
//CMD_BV
//Работа БB
#define IOCMD5_PRM1 4
//TEST
#define IOCMD6_PRM1 5
//к-во IO команд
#define IOCMD_PRM1_TOTAL    6

//---------------TL COMMAND------------------
//РАСПРЕДЕЛЕНИЕ TL КОМАНД ДЛЯ PRM1
//к-во TL команд
#define TLCMD_PRM1_TOTAL    0

//--------------- TIMERS ------------------
//РАСПРЕДЕЛЕНИЕ ТАЙМЕРОВ ДЛЯ PRM1
//таймер 0
#define TIMER1_PRM1        0
//таймер 1
#define TIMER2_PRM1        1
//таймер SEAM
#define TIMER_SEAM_PRM1    2
//таймер DIS
#define TIMERDIS_PRM1      3
//миним таймер DIS
#define TIMER_MINDIS_PRM1  4
//таймер БО
#define TIMER_RELEBO       5
//таймер БB
#define TIMER_RELEBV       6
//UI НЦН ДЗ
#define TIMER_UINCNDZ_PRM1  7
//UCM НЦН ДЗ
#define TIMER_CMNCNDZ_PRM1  8
//05 НЦН ДЗ
#define TIMER_05NCNDZ_PRM1  9
//к-во таймеров
#define TIMERS_PRM1_TOTAL   10

#ifndef _HIDE_COMPONENT

extern LineMenuItem sub_menu_ust_compUVV[];
extern LineMenuItem sub_menu_upr_compUVV[];

extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_tmp[];

extern int  IndexUstSPV;//индекс уставок в супервизоре

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern char *bitStringUNI[];
extern int  IndexIO;//индекс IO
extern int  IndexENA;//индекс ENA команд
extern int  IndexTIMERS;//таймерный индекс

void UstListCompPRM1();
void UstListCompUVV();
void ustRedactorCompPRM1();
void UstCompPRM1();
void UstCompUVV();

void PereinitVidListCompPRM1(short flg);
void VidListCompPRM1();
void vidRedactorCompPRM1();
void VidCompPRM1();

void PereinitUprListCompPRM1(short flg);
void UprListCompPRM1();
void uprRedactorCompPRM1();
void UprCompPRM1();
short  KadrMenuFormat_upr_compPRM1(void *workCntr);//(WorkControl *workCntr);
int   initUstPRM1(char init);
void  prepareUstPRM1(short idxC);
void  logicPRM1(int idxC);
int   isDISactiv_PRM1(int idxC);

short  KadrMenuFormat_PRM1(WorkControl *workCntr);

void EditUstPRM1();
void EditVidPRM1();
void EditUprPRM1();
void EditUstUVV();
void EditUprDV();
void EditUprCDI();
void EditUprRELE();
int codecUstPRM1(char codec, short offset, int ust);
void PereinitUprListCompUVV(short flg);

void UprListCompUVV();
void UprListCompDV();
void PereinitUprListCompDV(short flg);
short  KadrMenuFormat_upr_compDV(void *workCntr);
char *selectorUprStrDV(short iBit, UNS_32 ustUpr);
void UprCompDVLow();
void UprCompDVMidd();
void UprListCompRELE();
void UprCompDVHi();
void UprListCompCDI();
void UprCompRELE();
void UprCompCDI();
void PereinitUprListCompRELE(short flg);
short  KadrMenuFormat_upr_compRELE(void *workCntr);
char *selectorUprStrRELE(short iBit, UNS_32 ustUpr);

void PereinitUprListCompCDI(short flg);
short  KadrMenuFormat_upr_compCDI(void *workCntr);

short  KadrMenuFormat_ustvidPRM1(void *workCntr);
char *selectorUprStrPRM1(short iBit, UNS_32 ustUpr);

int offsetIOCmdPRM1;//смещение для IO PRM1
int offsetENACmdPRM1;//смещение для ENA PRM1
int offsetSPVCmdPRM1;//смещение для SPV PRM1
int offsetTimersPRM1;//смещение на таймерный индекс PRM1
int offsetUstMngPRM1;//смещение на уставки PRM1

int ReleTrigger = 0;//тригг реле
int CDITrigger = 0;//тригг СДИ
UNS_32 GruppaUst;//группа уставок

char PRM1_TITLE[] = "PRM1";

IONAMESTATUS_COMPONENT ionsPRM1[IOCMD_PRM1_TOTAL] =
{
  {
    //CMD_POL_VV
    1,//статус iocmd1
    "Положение ВВ"
  },
  {
    //CMD_FAILU_COMMON
    1,//статус iocmd2
    "Неиспр цепей напряжения ДЗ"
  },
  {
    //CMD_HANDOTKL_VV
    1,//статус iocmd3
    "Руч откл ВВ"
  },
  {
    //CMD_BO
    1,//статус iocmd4
    "Работа БО"
  },
  {
    //CMD_BV
    1,//статус iocmd5
    "Работа БB"
  },
  {
    //TEST
    1,//статус iocmd
    "TEST"
  }
};

LineMenuItem sub_menu_comp_PRM1[8] =
{
  { PRM1_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_cnf,   typeMenuSub},//control_item, parent
  { "Уставки PRM1",     (void *)&UstListCompPRM1, typeMenuProg},
  { "Уставки УВВ",      (void *)&UstListCompUVV,  typeMenuProg},
  { "Выдержки PRM1",    (void *)&VidListCompPRM1, typeMenuProg},
  { "Управление PRM1",  (void *)&UprListCompPRM1, typeMenuProg},
  { "Управление УВВ",   (void *)&UprListCompUVV,  typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compPRM1[] =
{
  { "Уставки PRM1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_PRM1, typeMenuList},//control_item, parent
  { "Блок откл",  (void *)&UstCompPRM1, typeMenuProg},
  { "Блок вкл",   (void *)&UstCompPRM1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_ust_compUVV[] =
{
  { "Уставки УВВ", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_PRM1, typeMenuList},//control_item, parent
/*
  { "Дпс ДВ1",  (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ2",  (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ3",  (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ4",  (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ5",  (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ6",  (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ7",  (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ8",  (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ9",  (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ10", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ11", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ12", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ13", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ14", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ15", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ16", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ17", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ18", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ19", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ20", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ21", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ22", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ23", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ24", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ25", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ26", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ27", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ28", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ29", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ30", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ31", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ32", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ33", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ34", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ35", (void *)&UstCompUVV, typeMenuProg},
  { "Дпс ДВ36", (void *)&UstCompUVV, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compPRM1[] =
{
  { "Выдержки PRM1", NULL},//title
  { &CONTROL2_COMP,     &sub_menu_comp_PRM1, typeMenuList},//control_item, parent
  { "Выдержка PRM1",        (void *)&VidCompPRM1, typeMenuProg},
  { "Выдержка PRM1 вперед", (void *)&VidCompPRM1, typeMenuProg},
  { "Выдержка PRM1 ДИС",    (void *)&VidCompPRM1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compPRM1[] =
{
  { "Управл PRM1", NULL},//title
  { &CONTROL2_COMP,   &sub_menu_comp_PRM1, typeMenuList},//control_item, parent
  { "Неиспр цепей напр МТЗ", (void *)&UprCompPRM1, typeMenuProg},
  { "Неиспр цепей напр ДЗ",  (void *)&UprCompPRM1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compUVV[] =
{
  { "Управл УВВ", NULL},//title
  { &CONTROL_UVV,   &sub_menu_comp_PRM1, typeMenuSub},//control_item, parent
  { "Управл ДВ",         (void *)&UprListCompDV, typeMenuProg},
  { "Управл реле",       (void *)&UprListCompRELE, typeMenuProg},
  { "Управл СДИ",        (void *)&UprListCompCDI,  typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compDV[] =
{
  { "Управл ДВ", NULL},//title
  { &CONTROL_UDV,   &sub_menu_upr_compUVV, typeMenuList},//control_item, parent
/*
  { "Вход ДВ1",  (void *)&UprCompDVLow, typeMenuProg},
  { "Вход ДВ2",  (void *)&UprCompDVLow, typeMenuProg},
  { "Вход ДВ3",  (void *)&UprCompDVLow, typeMenuProg},
  { "Вход ДВ4",  (void *)&UprCompDVLow, typeMenuProg},
  { "Вход ДВ5",  (void *)&UprCompDVLow, typeMenuProg},
  { "Вход ДВ6",  (void *)&UprCompDVLow, typeMenuProg},
  { "Вход ДВ7",  (void *)&UprCompDVLow, typeMenuProg},
  { "Вход ДВ8",  (void *)&UprCompDVLow, typeMenuProg},
  { "Вход ДВ9",  (void *)&UprCompDVLow, typeMenuProg},
  { "Вход ДВ10", (void *)&UprCompDVLow, typeMenuProg},
  { "Вход ДВ11", (void *)&UprCompDVLow, typeMenuProg},
  { "Вход ДВ12", (void *)&UprCompDVLow, typeMenuProg},
  { "Вход ДВ13", (void *)&UprCompDVLow, typeMenuProg},
  { "Вход ДВ14", (void *)&UprCompDVLow, typeMenuProg},
  { "Вход ДВ15", (void *)&UprCompDVLow, typeMenuProg},
  { "Вход ДВ16", (void *)&UprCompDVLow, typeMenuProg},
  { "Вход ДВ17", (void *)&UprCompDVMidd, typeMenuProg},
  { "Вход ДВ18", (void *)&UprCompDVMidd, typeMenuProg},
  { "Вход ДВ19", (void *)&UprCompDVMidd, typeMenuProg},
  { "Вход ДВ20", (void *)&UprCompDVMidd, typeMenuProg},
  { "Вход ДВ21", (void *)&UprCompDVMidd, typeMenuProg},
  { "Вход ДВ22", (void *)&UprCompDVMidd, typeMenuProg},
  { "Вход ДВ23", (void *)&UprCompDVMidd, typeMenuProg},
  { "Вход ДВ24", (void *)&UprCompDVMidd, typeMenuProg},
  { "Вход ДВ25", (void *)&UprCompDVMidd, typeMenuProg},
  { "Вход ДВ26", (void *)&UprCompDVMidd, typeMenuProg},
  { "Вход ДВ27", (void *)&UprCompDVMidd, typeMenuProg},
  { "Вход ДВ28", (void *)&UprCompDVMidd, typeMenuProg},
  { "Вход ДВ29", (void *)&UprCompDVMidd, typeMenuProg},
  { "Вход ДВ30", (void *)&UprCompDVMidd, typeMenuProg},
  { "Вход ДВ31", (void *)&UprCompDVMidd, typeMenuProg},
  { "Вход ДВ32", (void *)&UprCompDVMidd, typeMenuProg},
  { "Вход ДВ33", (void *)&UprCompDVHi, typeMenuProg},
  { "Вход ДВ34", (void *)&UprCompDVHi, typeMenuProg},
  { "Вход ДВ35", (void *)&UprCompDVHi, typeMenuProg},
  { "Вход ДВ36", (void *)&UprCompDVHi, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compRELE[] =
{
  { "Управл Реле", NULL},//title
  { &CONTROL_URELE,   &sub_menu_upr_compUVV, typeMenuList},//control_item, parent
/*
  { "Выход реле Р01",      (void *)&UprCompRELE, typeMenuProg},
  { "Выход реле Р02",      (void *)&UprCompRELE, typeMenuProg},
  { "Выход реле Р03",      (void *)&UprCompRELE, typeMenuProg},
  { "Выход реле Р04",      (void *)&UprCompRELE, typeMenuProg},
  { "Выход реле Р05",      (void *)&UprCompRELE, typeMenuProg},
  { "Выход реле Р06",      (void *)&UprCompRELE, typeMenuProg},
  { "Выход реле Р07",      (void *)&UprCompRELE, typeMenuProg},
  { "Выход реле Р08",      (void *)&UprCompRELE, typeMenuProg},
  { "Выход реле Р09",      (void *)&UprCompRELE, typeMenuProg},
  { "Выход реле Р010",     (void *)&UprCompRELE, typeMenuProg},
  { "Выход реле Р011",     (void *)&UprCompRELE, typeMenuProg},
  { "Выход реле Р012",     (void *)&UprCompRELE, typeMenuProg},
  { "Выход реле Р013",     (void *)&UprCompRELE, typeMenuProg},
  { "Выход реле Р014",     (void *)&UprCompRELE, typeMenuProg},
  { "Выход реле Р015",     (void *)&UprCompRELE, typeMenuProg},
  { "Выход реле Р016",     (void *)&UprCompRELE, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compCDI[] =
{
  { "Управл СДИ", NULL},//title
  { &CONTROL_UCDI,   &sub_menu_upr_compUVV, typeMenuList},//control_item, parent
/*
  { "Выход СДИ01",      (void *)&UprCompCDI, typeMenuProg},
  { "Выход СДИ02",      (void *)&UprCompCDI, typeMenuProg},
  { "Выход СДИ03",      (void *)&UprCompCDI, typeMenuProg},
  { "Выход СДИ04",      (void *)&UprCompCDI, typeMenuProg},
  { "Выход СДИ05",      (void *)&UprCompCDI, typeMenuProg},
  { "Выход СДИ06",      (void *)&UprCompCDI, typeMenuProg},
  { "Выход СДИ07",      (void *)&UprCompCDI, typeMenuProg},
  { "Выход СДИ08",      (void *)&UprCompCDI, typeMenuProg},
  { "Выход СДИ09",      (void *)&UprCompCDI, typeMenuProg},
  { "Выход СДИ010",     (void *)&UprCompCDI, typeMenuProg},
  { "Выход СДИ011",     (void *)&UprCompCDI, typeMenuProg},
  { "Выход СДИ012",     (void *)&UprCompCDI, typeMenuProg},
*/
  { NULL, NULL}

};

void PereinitUstListCompPRM1(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidPRM1, sub_menu_ust_compPRM1);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void PereinitUstListCompUVV(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidPRM1, sub_menu_ust_compUVV);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void UstListCompPRM1()
{
  SelectorMNGBAZA(MNGUST_PRM1_BO);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compPRM1);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompPRM1);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompPRM1()

void UstCompPRM1()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compPRM1);
  PassWord(EditUstPRM1);
}//VidCompPRM1()

void EditUstPRM1()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compPRM1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompPRM1()

void UstListCompUVV()
{
  SelectorMNGBAZA(0);//установка базу уставок

  SelectorSUBMENU(sub_menu_ust_compUVV);//уcтановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUstListCompUVV);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UstListCompUVV()

void UstCompUVV()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_ust_compUVV);
  PassWord(EditUstUVV);
}//VidCompUVV()

void EditUstUVV()
{
//редактировать уставку
  SystemEditUst(sub_menu_ust_compUVV);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompUVV()

short  KadrMenuFormat_ustvidPRM1(void *pstr)
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

void PereinitVidListCompPRM1(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidPRM1, sub_menu_vid_compPRM1);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstListComp2()

void VidListCompPRM1()
{
  SelectorMNGBAZA(MNGVID_PRM1);//установка базы уставок

  SelectorSUBMENU(sub_menu_vid_compPRM1);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitVidListCompPRM1);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompPRM1()

void UprListCompUVV()
{
//  CRR_SUBMENU = sub_menu_upr_compUVV;//текущее субменю
  SelectorSUBMENU(sub_menu_upr_compUVV);//утановить текущее субменю

//  CRR_TEXTSTREAM = &CONTROL_UVV;//текущий control
  SelectorTEXTCONTROL(&CONTROL_UVV);//текущий control
//  CRR_FHOME = &PereinitUprListCompUVV;//указатель на ф-цию HOME

//  CRR_FHOME(1);//переиниц
  SelectorFHOME(&PereinitUprListCompUVV);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//UprListCompUVV()

void VidCompPRM1()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_vid_compPRM1);
//  PassWord(EditVidAPV);
  EditVidPRM1();
}//VidCompPRM1()

void EditVidPRM1()
{
//редактировать уставку
  SystemEditUst(sub_menu_vid_compPRM1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompPRM1(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compPRM1, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUstList

void PereinitUprListCompUVV(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL_UVV, &KadrMenuFormat_sub, sub_menu_upr_compUVV);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL_UVV, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuSub();//вывести окно отображения
  LanderPStr();//размещение указателя строки
//  ListPStr();//доступ к уставкам
}//PereinitUprListCompUVV(short flg)

void UprListCompPRM1()
{
  SelectorMNGBAZA(MNGUPR_PRM1);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compPRM1);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL2_COMP);//текущий control

  SelectorFHOME(&PereinitUprListCompPRM1);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompPRM1()

void UprCompPRM1()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compPRM1);
  PassWord(EditUprPRM1);

}//UprCompPRM1()

void EditUprPRM1()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compPRM1[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrPRM1);//редактировать уставку управления
}//EditUprPRM1()

void UprListCompDV()
{
  SelectorMNGBAZA(MNGUPR_DVLOW);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compDV);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL_UDV);//текущий control

  SelectorFHOME(&PereinitUprListCompDV);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompDV()

void UprCompDVLow()
{
  SelectorMNGBAZA(MNGUPR_DVLOW);//установка базы уставок
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compDV);
  PassWord(EditUprDV);

}//UprCompDVLow()
void UprCompDVMidd()
{
  SelectorMNGBAZA(MNGUPR_DVMIDD);//установка базы уставок
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compDV);
  PassWord(EditUprDV);

}//UprCompDVMidd()
void UprCompDVHi()
{
  SelectorMNGBAZA(MNGUPR_DVHI);//установка базы уставок
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compDV);
  PassWord(EditUprDV);

}//UprCompDVHi()

void EditUprDV()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compDV[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrDV);//редактировать уставку управления
}//EditUprDV()

void PereinitUprListCompDV(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL_UDV, &KadrMenuFormat_upr_compDV, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL_UDV, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUprListCompDV(short flg)

void UprListCompRELE()
{
  SelectorMNGBAZA(MNGUPR_RELE);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compRELE);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL_URELE);//текущий control

  SelectorFHOME(&PereinitUprListCompRELE);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompRELE()

void UprCompRELE()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compRELE);
  PassWord(EditUprRELE);

}//UprCompRELE()

void EditUprRELE()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compRELE[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrRELE);//редактировать уставку управления
}//EditUprRELE()

void PereinitUprListCompRELE(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL_URELE, &KadrMenuFormat_upr_compRELE, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL_URELE, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUprListCompRELE(short flg)

void UprListCompCDI()
{
  SelectorMNGBAZA(MNGUPR_CDI);//установка базы уставок

  SelectorSUBMENU(sub_menu_upr_compCDI);//утановить текущее субменю

  SelectorTEXTCONTROL(&CONTROL_UCDI);//текущий control

  SelectorFHOME(&PereinitUprListCompCDI);//указатель на ф-цию HOME
  InitFHOME(1);//exe ф-цию HOME

  LanderUpDown();//wkl Up Down
}//VidListCompCDI()

void UprCompCDI()
{
  SelectorCRRLIGHTLINE();//найти подсвеченную строку текущего текст потока
  PrepareEditMenu(sub_menu_upr_compCDI);
  PassWord(EditUprCDI);

}//UprCompCDI()

void EditUprCDI()
{
//редактировать уставку упр
  char *nameUpr = (char *)sub_menu_upr_compCDI[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrRELE);//редактировать уставку управления
}//EditUprCDI()

void PereinitUprListCompCDI(short flg)
{
//переиниц
  //инит компонентного контроля
  TxtStreamInit(&CONTROL_UCDI, &KadrMenuFormat_upr_compCDI, NULL);//инит control и формир кадра
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL_UCDI, SIZE_PAGE_VIEW/2);//перейти на END
  }//if

  ViewDiskrMenuList();//вывести окно отображения
  ListPStr();//доступ к уставкам
}//PereinitUprListCompCDI(short flg)

short  KadrMenuFormat_upr_compPRM1(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compPRM1[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrPRM1(i, getCurrentMngUSTAVKI()));

      return 1;//сравнить счетчики кадров
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compPRM1(WorkControl *workCntr)

short  KadrMenuFormat_upr_compDV(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
 short offset=0;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compDV[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      LIGHTMNGUBAZA = MNGUPR_DVLOW;//смотреть мл 16 ДВ
      offset=i;
      if(i>15){
            offset=i-16;
            LIGHTMNGUBAZA = MNGUPR_DVMIDD;//смотреть cp 16 ДВ
            }
      if(i>31){
            LIGHTMNGUBAZA = MNGUPR_DVHI;//смотреть ct 16 ДВ
            offset=i-32;
            }//if
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrDV(offset, getCurrentMngUSTAVKI()));

      return 1;
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compDV(WorkControl *workCntr)

short  KadrMenuFormat_upr_compRELE(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compRELE[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrRELE(i, getCurrentMngUSTAVKI()));

      return 1;
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compRELE(WorkControl *workCntr)

short  KadrMenuFormat_upr_compCDI(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    char *nameUpr = (char *)sub_menu_upr_compCDI[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrRELE(i, getCurrentMngUSTAVKI()));

      return 1;
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compCDI(void *pstr)

char *selectorUprStrPRM1(short iBit, UNS_32 ustUpr)
{
  switch(iBit)
  {

  default:
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_WKL];
    return bitStringUNI[UNIUPR_OTKL];
  }//switch
}//selectorUprStrPRM1(short ibit, UNS_32 ustUpr)

char *selectorUprStrDV(short iBit, UNS_32 ustUpr)
{
  switch(iBit)
  {

  default:
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_INVERS];
    return bitStringUNI[UNIUPR_PRM];
  }//switch
}//selectorUprStrDV(short ibit, UNS_32 ustUpr)

char *selectorUprStrRELE(short iBit, UNS_32 ustUpr)
{
  switch(iBit)
  {

  default:;
  }//switch
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_TRIG];
    return bitStringUNI[UNIUPR_NORM];
}//selectorUprStrRELE(short ibit, UNS_32 ustUpr)

int initUstPRM1(char init)
{
  //инициал уставок
  if (init)
  {
//уставка сработки
    tmpUSTAVKI[MNGUST_PRM1_DDV1] = 10;
    tmpUSTAVKI[MNGUST_PRM1_DDV2] = 15;
    tmpUSTAVKI[MNGUST_PRM1_DDV3] = 20;
    tmpUSTAVKI[MNGUST_PRM1_DDV4] = 25;
    tmpUSTAVKI[MNGUST_PRM1_DDV5] = 10;
    tmpUSTAVKI[MNGUST_PRM1_DDV6] = 15;
    tmpUSTAVKI[MNGUST_PRM1_DDV7] = 20;
    tmpUSTAVKI[MNGUST_PRM1_DDV8] = 25;
    tmpUSTAVKI[MNGUST_PRM1_DDV9] = 10;
    tmpUSTAVKI[MNGUST_PRM1_DDV10] = 15;
    tmpUSTAVKI[MNGUST_PRM1_DDV11] = 20;
    tmpUSTAVKI[MNGUST_PRM1_DDV12] = 25;
    tmpUSTAVKI[MNGUST_PRM1_DDV13] = 26;
    tmpUSTAVKI[MNGUST_PRM1_DDV14] = 27;
    tmpUSTAVKI[MNGUST_PRM1_DDV15] = 28;
    tmpUSTAVKI[MNGUST_PRM1_DDV16] = 29;
    tmpUSTAVKI[MNGUST_PRM1_DDV17] = 30;
    tmpUSTAVKI[MNGUST_PRM1_DDV18] = 31;
    tmpUSTAVKI[MNGUST_PRM1_DDV19] = 32;
    tmpUSTAVKI[MNGUST_PRM1_DDV20] = 33;
    tmpUSTAVKI[MNGUST_PRM1_DDV21] = 34;
    tmpUSTAVKI[MNGUST_PRM1_DDV22] = 35;
    tmpUSTAVKI[MNGUST_PRM1_DDV23] = 36;
    tmpUSTAVKI[MNGUST_PRM1_DDV24] = 37;
    tmpUSTAVKI[MNGUST_PRM1_DDV25] = 38;
    tmpUSTAVKI[MNGUST_PRM1_DDV26] = 39;
    tmpUSTAVKI[MNGUST_PRM1_DDV27] = 40;
    tmpUSTAVKI[MNGUST_PRM1_DDV28] = 41;
    tmpUSTAVKI[MNGUST_PRM1_DDV29] = 42;
    tmpUSTAVKI[MNGUST_PRM1_DDV30] = 43;
    tmpUSTAVKI[MNGUST_PRM1_DDV31] = 44;
    tmpUSTAVKI[MNGUST_PRM1_DDV32] = 45;
    tmpUSTAVKI[MNGUST_PRM1_DDV33] = 46;
    tmpUSTAVKI[MNGUST_PRM1_DDV34] = 47;
    tmpUSTAVKI[MNGUST_PRM1_DDV35] = 48;
    tmpUSTAVKI[MNGUST_PRM1_DDV36] = 49;
//уставка выдержки
    tmpUSTAVKI[MNGVID_PRM1]     = 3000;
    tmpUSTAVKI[MNGVID_PRM1_V]   = 600;
    tmpUSTAVKI[MNGVID_PRM1_DIS] = 60000;//работа рег ДИС
//уставка управления
    tmpUSTAVKI[MNGUPR_PRM1] = 0;
//уставка управления
    tmpUSTAVKI[MNGUPR_DVLOW] = 0;
    tmpUSTAVKI[MNGUPR_DVMIDD] = 0;
    tmpUSTAVKI[MNGUPR_DVHI] = 0;
//уставка управления
    tmpUSTAVKI[MNGUPR_RELE] = 0;
//уставка управления
    tmpUSTAVKI[MNGUPR_CDI] = 0;
//блок откл
    tmpUSTAVKI[MNGUST_PRM1_BO] = 122;
//блок вкл
    tmpUSTAVKI[MNGUST_PRM1_BV] = 123;

  }//if

  offsetSPVCmdPRM1 = IndexUstSPV;//смещение для SPV PRM1
  IndexUstSPV += SPVUST_PRM1_TOTAL;//индекс уставок в супервизоре
  return MNGUST_PRM1_TOTAL;//к-во уставок в менеджере уставок
}//initUstPRM1(char init)

void  prepareUstPRM1(short idxC)
{
//смещение на уставки PRM1
  offsetUstMngPRM1 = getClonOffsetMngUSTAVKI(idxC, 0);//прочитать смещение уставки клона idxC
  //подготовка ENA команд для клона
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_PRM1), ENACMD_PRM1_TOTAL);
  //подготовка уставок
  int tmpOffsetUSpv = getOffsetSPVUstCnf(idxC);//смещение уставок внутри супервизора
  //Допуск ДВ
  SPV_UST(SPV_DDV1_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV1);
  SPV_UST(SPV_DDV2_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV2);
  SPV_UST(SPV_DDV3_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV3);
  SPV_UST(SPV_DDV4_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV4);
  SPV_UST(SPV_DDV5_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV5);
  SPV_UST(SPV_DDV6_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV6);
  SPV_UST(SPV_DDV7_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV7);
  SPV_UST(SPV_DDV8_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV8);
  SPV_UST(SPV_DDV9_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV9);
  SPV_UST(SPV_DDV10_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV10);
  SPV_UST(SPV_DDV11_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV11);
  SPV_UST(SPV_DDV12_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV12);
  SPV_UST(SPV_DDV13_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV13);
  SPV_UST(SPV_DDV14_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV14);
  SPV_UST(SPV_DDV15_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV15);
  SPV_UST(SPV_DDV16_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV16);
  SPV_UST(SPV_DDV17_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV17);
  SPV_UST(SPV_DDV18_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV18);
  SPV_UST(SPV_DDV19_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV19);
  SPV_UST(SPV_DDV20_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV20);
  SPV_UST(SPV_DDV21_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV21);
  SPV_UST(SPV_DDV22_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV22);
  SPV_UST(SPV_DDV23_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV23);
  SPV_UST(SPV_DDV24_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV24);
  SPV_UST(SPV_DDV25_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV25);
  SPV_UST(SPV_DDV26_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV26);
  SPV_UST(SPV_DDV27_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV27);
  SPV_UST(SPV_DDV28_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV28);
  SPV_UST(SPV_DDV29_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV29);
  SPV_UST(SPV_DDV30_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV30);
  SPV_UST(SPV_DDV31_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV31);
  SPV_UST(SPV_DDV32_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV32);
  SPV_UST(SPV_DDV33_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV33);
  SPV_UST(SPV_DDV34_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV34);
  SPV_UST(SPV_DDV35_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV35);
  SPV_UST(SPV_DDV36_UST) =
    getNativUstMngUSTAVKI(idxC, MNGUST_PRM1_DDV36);

//уставка ДВ -ПрямойИнверсный
  SPV_UST(SPV_UPR_DVLOW) =
    getNativUstMngUSTAVKI(idxC, MNGUPR_DVLOW);
  SPV_UST(SPV_UPR_DVMIDD) =
    getNativUstMngUSTAVKI(idxC, MNGUPR_DVMIDD);
  SPV_UST(SPV_UPR_DVHI) =
    getNativUstMngUSTAVKI(idxC, MNGUPR_DVHI);

//уставка Реле -НормальныйТриггерный
  int spvupr_rele =
  SPV_UST(SPV_UPR_RELE) =
    getNativUstMngUSTAVKI(idxC, MNGUPR_RELE);

//уставка СДИ -НормальныйТриггерный
  int spvupr_cdi =
  SPV_UST(SPV_UPR_CDI) =
    getNativUstMngUSTAVKI(idxC, MNGUPR_CDI);
//обнулить триггеры у норм реле
  ReleTrigger &= spvupr_rele;//тригг реле
//обнулить триггеры у норм СДИ
  CDITrigger  &= spvupr_cdi;//тригг СДИ

  //уставка SPV сработки 20V
  SPV_UST(SPVSRAB_02UH) = 20000;
  //уставка SPV возврата DOWN
  SPV_UST(SPVVOZV_02UH) = 21000;

  //уставка SPV сработки 6A
  SPV_UST(SPVSRAB_12IH) = 6000;
  //уставка SPV возврата DOWN
  SPV_UST(SPVVOZV_12IH) = 6300;

  //уставка SPV сработки
  SPV_UST(SPVSRAB_U005) = 5000;
  //уставка SPV возврата
  SPV_UST(SPVVOZV_U005) = 5250;

  //уставка SPV сработки 0.25B
  SPV_UST(SPVSRAB_U025) = 250;
  //уставка SPV возврата
  SPV_UST(SPVVOZV_U025) = 262;

  //уставка SPV сработки 0.05A
//  SPV_UST(SPVSRAB_I005) = 50;
  //уставка SPV возврата
  //SPV_UST(SPVVOZV_I005) = 53;

  //уставка SPV сработки
  SPV_UST(SPVSRAB_ICM005) = 50;
  //уставка SPV возврата
  SPV_UST(SPVVOZV_ICM005) = 53;
  //уставка SPV сработки
  SPV_UST(SPVSRAB_UCM005) = 50;
  //уставка SPV возврата
  SPV_UST(SPVVOZV_UCM005) = 53;
  //уставка SPV сработки 20V
  SPV_UST(SPVSRAB_DZ_02UH) = 11540;//20000;
  //уставка SPV возврата UP
  SPV_UST(SPVVOZV_DZ_02UH) = 10963;//19000;

  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //компонент в конфигурации

         //таймер 1
  setTimerPorog(tmpOffsetT+ TIMER1_PRM1,
    getNativUstMngUSTAVKI(idxC, MNGVID_PRM1));

         //таймер 2
  setTimerPorog(tmpOffsetT+ TIMER2_PRM1,
    getNativUstMngUSTAVKI(idxC, MNGVID_PRM1_V));

     //таймер сшивки SEAM
  setTimerPorog(tmpOffsetT+ TIMER_SEAM_PRM1, 5);

    //таймер DIS
  setTimerPorog(tmpOffsetT+ TIMERDIS_PRM1, 60000);

   //миним таймер DIS
  setTimerPorog(tmpOffsetT+ TIMER_MINDIS_PRM1, 20);
   //таймер БО
  setTimerPorog(tmpOffsetT+ TIMER_RELEBO, 22);
   //таймер БB
  setTimerPorog(tmpOffsetT+ TIMER_RELEBV, 33);

  //выдержкa UI НЦН ДЗ
  setTimerPorog(tmpOffsetT+ TIMER_UINCNDZ_PRM1, 
    getNativUstMngUSTAVKI(idxC, MNGVID_PRM1_UINCNDZ));
  //выдержка обрат последоват CM НЦН ДЗ
  setTimerPorog(tmpOffsetT+ TIMER_CMNCNDZ_PRM1, 
    getNativUstMngUSTAVKI(idxC, MNGVID_PRM1_CMNCNDZ));
  //05 НЦН ДЗ
  setTimerPorog(tmpOffsetT+ TIMER_05NCNDZ_PRM1, 500);

}//prepareUstMTZ1(short idxC)

int initIOCmd_PRM1()
{
  //инициал IO команд
  offsetIOCmdPRM1 = IndexIO;//смещение для IO PRM1
  return commonInitIOCmd(IOCMD_PRM1_TOTAL);
}//initIOCmd_PRM1()

int initTLCmd_PRM1()
{
  //инициал TL команд
  return commonInitTLCmd(TLCMD_PRM1_TOTAL);
}//initTLCmd_PRM1()

int initENACmd_PRM1()
{
  //инициал ENA команд
  offsetENACmdPRM1 = IndexENA;//смещение для ENA PRM1
  return commonInitENACmd(ENACMD_PRM1_TOTAL);
}//initENACmd_PRM1()

void initTimersPRM1(short idxC)
{
  //запрос и инициал таймеров
  offsetTimersPRM1 = IndexTIMERS;//смещение на таймерный индекс
  commonInitTimers(TIMERS_PRM1_TOTAL);

}//initTimersPRM1()

int codecUstPRM1(char codec, short offset, int ust)
//codec=0-кодировать
//codec=1-раскодировать
{
  //кодировать-раскодировать уставку
  if(codec) return ust*1;
  return ust/1;
}//codecUstPRM1(char *buf, short offset, int ust)

int isDISactiv_PRM1(int idxC)
{
//таймерная активность Регистратора ДИС
    int tmpOffsetT    =
                cnfCOMPONENT[idxC].offsetTimers;   //таймера компонента в конфигурации
  if( getTimerBUSY(tmpOffsetT+TIMER_MINDIS_PRM1) |
      getTimerFINISH(tmpOffsetT+TIMER_MINDIS_PRM1)
    ) return 1;//миним таймер DIS
  return 0;//нет активности
}//isDISactiv_PRM1(int idxC)

void SaveUprPRM1(short numBit)
{
  /*
//персональное сохр upr для PRM1
  UNS_32 tmpU = getCurrentMngUSTAVKI();//текущая уст упр
  short ibit = numBit;
  if(numBit>15) ibit = numBit-16;
  if(numBit>31) ibit = numBit-32;
    if(FvmenuDis->UprCheck->Checked)
    {
      NumBitSettingWord(ibit, &tmpU);//установка бита по его индексу
    }//if(FvmenuDis->UprCheck->Checked)
    else
    {
      NumBitClearingWord(ibit, &tmpU);//сброс бита по его индексу
    }
  setCurrentMngUSTAVKI(tmpU);//новая уст упр
  */
}//SaveUprPRM1()

char copyPRM1ToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//стереть старое
//копировать компонент в репозитарий
  rpzcomponent_obj.componentEnable = 1;//разрешение компонента
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //код компонента
  rpzcomponent_obj.packet = 0;    //номер пакетного компонента
  rpzcomponent_obj.permanent = 1; //перманентный компонент

  strcpy(rpzcomponent_obj.nameComponent,  PRM1_TITLE);       //имя компонента
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_PRM1;//меню компонента

  rpzcomponent_obj.cntClon     = CNT_STUPEN_PRM1;   //max к-во клонов
  rpzcomponent_obj.numClon     = 1;//номер клона
  rpzcomponent_obj.workToSignal = 0; //Работа на сигнал

  rpzcomponent_obj.initUstMng     = initUstPRM1;    //инициал уставок
  rpzcomponent_obj.prepareUstSpv  = prepareUstPRM1;//подготовка уставок
  rpzcomponent_obj.initIOCmd      = initIOCmd_PRM1;      //инициал IO команд
  rpzcomponent_obj.initTLCmd      = initTLCmd_PRM1;      //инициал TL команд
  rpzcomponent_obj.initENACmd     = initENACmd_PRM1;     //инициал ENA команд
  rpzcomponent_obj.bo_bvCmd       = NULL; //настройка БО БВ команд
  rpzcomponent_obj.isDISactiv     = isDISactiv_PRM1; //активность Регистратора ДИС
  rpzcomponent_obj.setBOBVtimer   = NULL; //инициал таймеров БО БВ

  rpzcomponent_obj.nameStatusIO = ionsPRM1;          //имена и статус команд IO
  rpzcomponent_obj.initTimers   = initTimersPRM1;    //запрос и инициал таймеров
  rpzcomponent_obj.logic        = logicPRM1;         //логика компонента

  rpzcomponent_obj.codecUst = codecUstPRM1;   //кодировать-раскодировать уставку

  return 0;//не пакетная регистрация
}//

#endif // _HIDE_COMPONENT

