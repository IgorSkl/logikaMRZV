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

//��� �����������
#define KOD_COMPONENT  PRM1_COMP1
//�-�� ��������
#define CNT_STUPEN_PRM1  1

#endif // _HIDE_COMPONENT

//������������� �������  � ��������� �������
//������� ������ ��
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

//������� ��������
#define MNGVID_PRM1     36
#define MNGVID_PRM1_V   37
#define MNGVID_PRM1_DIS 38
//�������a UI ��� ��
#define MNGVID_PRM1_UINCNDZ 39
//�������� ����� ���������� CM ��� ��
#define MNGVID_PRM1_CMNCNDZ 40

//������� ���������� PRM1
#define MNGUPR_PRM1    41
//������� ���������� DV
#define MNGUPR_DVLOW   42
#define MNGUPR_DVMIDD  43
#define MNGUPR_DVHI    44
//������� ���������� RELE
#define MNGUPR_RELE    45
//������� ���������� CDI
#define MNGUPR_CDI     46

//������� PRM1 ���� ����
#define MNGUST_PRM1_BO  47
//������� PRM1 ���� ���
#define MNGUST_PRM1_BV  48
//�-�� ������� � ��������� �������
#define MNGUST_PRM1_TOTAL  49

//������������� ENA ������
//������������� ����� ���� ���
#define ENA_PRM1_FAILU_MTZ  0
//������������� ����� ���� ��
#define ENA_PRM1_FAILU_DZ   1
//�-�� ENA ������
#define ENACMD_PRM1_TOTAL   2

//������������� ������� � �����������
//������� ������ ��
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

//������� ��������
#define SPVSRAB_02UH       36
#define SPVSRAB_12IH       37
#define SPVSRAB_U005       38
#define SPVSRAB_UCM005     39
#define SPVSRAB_ICM005     40
#define SPVSRAB_U025       41
//������� ��������
#define SPVVOZV_02UH       42
#define SPVVOZV_12IH       43
#define SPVVOZV_U005       44
#define SPVVOZV_UCM005     45
#define SPVVOZV_ICM005     46
#define SPVVOZV_U025       47

//������� SPV �����
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

//������� �� -���������������
#define SPV_UPR_DVLOW      65
#define SPV_UPR_DVMIDD     66
#define SPV_UPR_DVHI       67
//������� ���� -��������������������
#define SPV_UPR_RELE       68
//������� ��� -��������������������
#define SPV_UPR_CDI        69
//��� ��
#define SPVSRAB_DZ_02UH    70
#define SPVVOZV_DZ_02UH    71
#define SPV_OUT_DZ_02UH    72
#define SPV_OUT_DZ_UCMICM  73          
#define SPV_DZ_UCMICM      74

//�-�� ������� � �����������
#define SPVUST_PRM1_TOTAL  75

//---------------IO COMMAND------------------
//������������� IO ������ ��� PRM1
//��������� ��
//CMD_POL_VV
#define IOCMD1_PRM1 0
//������ ����� ���������� ��
//CMD_FAILU_COMMON
#define IOCMD2_PRM1 1
//��� ���� ��
//CMD_HANDOTKL_VV
#define IOCMD3_PRM1 2
//CMD_BO
//������ ��
#define IOCMD4_PRM1 3
//CMD_BV
//������ �B
#define IOCMD5_PRM1 4
//TEST
#define IOCMD6_PRM1 5
//�-�� IO ������
#define IOCMD_PRM1_TOTAL    6

//---------------TL COMMAND------------------
//������������� TL ������ ��� PRM1
//�-�� TL ������
#define TLCMD_PRM1_TOTAL    0

//--------------- TIMERS ------------------
//������������� �������� ��� PRM1
//������ 0
#define TIMER1_PRM1        0
//������ 1
#define TIMER2_PRM1        1
//������ SEAM
#define TIMER_SEAM_PRM1    2
//������ DIS
#define TIMERDIS_PRM1      3
//����� ������ DIS
#define TIMER_MINDIS_PRM1  4
//������ ��
#define TIMER_RELEBO       5
//������ �B
#define TIMER_RELEBV       6
//UI ��� ��
#define TIMER_UINCNDZ_PRM1  7
//UCM ��� ��
#define TIMER_CMNCNDZ_PRM1  8
//05 ��� ��
#define TIMER_05NCNDZ_PRM1  9
//�-�� ��������
#define TIMERS_PRM1_TOTAL   10

#ifndef _HIDE_COMPONENT

extern LineMenuItem sub_menu_ust_compUVV[];
extern LineMenuItem sub_menu_upr_compUVV[];

extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_tmp[];

extern int  IndexUstSPV;//������ ������� � �����������

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//������� ������� �����������
extern char *bitStringUNI[];
extern int  IndexIO;//������ IO
extern int  IndexENA;//������ ENA ������
extern int  IndexTIMERS;//��������� ������

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

int offsetIOCmdPRM1;//�������� ��� IO PRM1
int offsetENACmdPRM1;//�������� ��� ENA PRM1
int offsetSPVCmdPRM1;//�������� ��� SPV PRM1
int offsetTimersPRM1;//�������� �� ��������� ������ PRM1
int offsetUstMngPRM1;//�������� �� ������� PRM1

int ReleTrigger = 0;//����� ����
int CDITrigger = 0;//����� ���
UNS_32 GruppaUst;//������ �������

char PRM1_TITLE[] = "PRM1";

IONAMESTATUS_COMPONENT ionsPRM1[IOCMD_PRM1_TOTAL] =
{
  {
    //CMD_POL_VV
    1,//������ iocmd1
    "��������� ��"
  },
  {
    //CMD_FAILU_COMMON
    1,//������ iocmd2
    "������ ����� ���������� ��"
  },
  {
    //CMD_HANDOTKL_VV
    1,//������ iocmd3
    "��� ���� ��"
  },
  {
    //CMD_BO
    1,//������ iocmd4
    "������ ��"
  },
  {
    //CMD_BV
    1,//������ iocmd5
    "������ �B"
  },
  {
    //TEST
    1,//������ iocmd
    "TEST"
  }
};

LineMenuItem sub_menu_comp_PRM1[8] =
{
  { PRM1_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_cnf,   typeMenuSub},//control_item, parent
  { "������� PRM1",     (void *)&UstListCompPRM1, typeMenuProg},
  { "������� ���",      (void *)&UstListCompUVV,  typeMenuProg},
  { "�������� PRM1",    (void *)&VidListCompPRM1, typeMenuProg},
  { "���������� PRM1",  (void *)&UprListCompPRM1, typeMenuProg},
  { "���������� ���",   (void *)&UprListCompUVV,  typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compPRM1[] =
{
  { "������� PRM1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_PRM1, typeMenuList},//control_item, parent
  { "���� ����",  (void *)&UstCompPRM1, typeMenuProg},
  { "���� ���",   (void *)&UstCompPRM1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_ust_compUVV[] =
{
  { "������� ���", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_PRM1, typeMenuList},//control_item, parent
/*
  { "��� ��1",  (void *)&UstCompUVV, typeMenuProg},
  { "��� ��2",  (void *)&UstCompUVV, typeMenuProg},
  { "��� ��3",  (void *)&UstCompUVV, typeMenuProg},
  { "��� ��4",  (void *)&UstCompUVV, typeMenuProg},
  { "��� ��5",  (void *)&UstCompUVV, typeMenuProg},
  { "��� ��6",  (void *)&UstCompUVV, typeMenuProg},
  { "��� ��7",  (void *)&UstCompUVV, typeMenuProg},
  { "��� ��8",  (void *)&UstCompUVV, typeMenuProg},
  { "��� ��9",  (void *)&UstCompUVV, typeMenuProg},
  { "��� ��10", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��11", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��12", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��13", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��14", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��15", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��16", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��17", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��18", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��19", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��20", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��21", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��22", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��23", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��24", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��25", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��26", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��27", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��28", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��29", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��30", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��31", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��32", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��33", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��34", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��35", (void *)&UstCompUVV, typeMenuProg},
  { "��� ��36", (void *)&UstCompUVV, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compPRM1[] =
{
  { "�������� PRM1", NULL},//title
  { &CONTROL2_COMP,     &sub_menu_comp_PRM1, typeMenuList},//control_item, parent
  { "�������� PRM1",        (void *)&VidCompPRM1, typeMenuProg},
  { "�������� PRM1 ������", (void *)&VidCompPRM1, typeMenuProg},
  { "�������� PRM1 ���",    (void *)&VidCompPRM1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compPRM1[] =
{
  { "������ PRM1", NULL},//title
  { &CONTROL2_COMP,   &sub_menu_comp_PRM1, typeMenuList},//control_item, parent
  { "������ ����� ���� ���", (void *)&UprCompPRM1, typeMenuProg},
  { "������ ����� ���� ��",  (void *)&UprCompPRM1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compUVV[] =
{
  { "������ ���", NULL},//title
  { &CONTROL_UVV,   &sub_menu_comp_PRM1, typeMenuSub},//control_item, parent
  { "������ ��",         (void *)&UprListCompDV, typeMenuProg},
  { "������ ����",       (void *)&UprListCompRELE, typeMenuProg},
  { "������ ���",        (void *)&UprListCompCDI,  typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compDV[] =
{
  { "������ ��", NULL},//title
  { &CONTROL_UDV,   &sub_menu_upr_compUVV, typeMenuList},//control_item, parent
/*
  { "���� ��1",  (void *)&UprCompDVLow, typeMenuProg},
  { "���� ��2",  (void *)&UprCompDVLow, typeMenuProg},
  { "���� ��3",  (void *)&UprCompDVLow, typeMenuProg},
  { "���� ��4",  (void *)&UprCompDVLow, typeMenuProg},
  { "���� ��5",  (void *)&UprCompDVLow, typeMenuProg},
  { "���� ��6",  (void *)&UprCompDVLow, typeMenuProg},
  { "���� ��7",  (void *)&UprCompDVLow, typeMenuProg},
  { "���� ��8",  (void *)&UprCompDVLow, typeMenuProg},
  { "���� ��9",  (void *)&UprCompDVLow, typeMenuProg},
  { "���� ��10", (void *)&UprCompDVLow, typeMenuProg},
  { "���� ��11", (void *)&UprCompDVLow, typeMenuProg},
  { "���� ��12", (void *)&UprCompDVLow, typeMenuProg},
  { "���� ��13", (void *)&UprCompDVLow, typeMenuProg},
  { "���� ��14", (void *)&UprCompDVLow, typeMenuProg},
  { "���� ��15", (void *)&UprCompDVLow, typeMenuProg},
  { "���� ��16", (void *)&UprCompDVLow, typeMenuProg},
  { "���� ��17", (void *)&UprCompDVMidd, typeMenuProg},
  { "���� ��18", (void *)&UprCompDVMidd, typeMenuProg},
  { "���� ��19", (void *)&UprCompDVMidd, typeMenuProg},
  { "���� ��20", (void *)&UprCompDVMidd, typeMenuProg},
  { "���� ��21", (void *)&UprCompDVMidd, typeMenuProg},
  { "���� ��22", (void *)&UprCompDVMidd, typeMenuProg},
  { "���� ��23", (void *)&UprCompDVMidd, typeMenuProg},
  { "���� ��24", (void *)&UprCompDVMidd, typeMenuProg},
  { "���� ��25", (void *)&UprCompDVMidd, typeMenuProg},
  { "���� ��26", (void *)&UprCompDVMidd, typeMenuProg},
  { "���� ��27", (void *)&UprCompDVMidd, typeMenuProg},
  { "���� ��28", (void *)&UprCompDVMidd, typeMenuProg},
  { "���� ��29", (void *)&UprCompDVMidd, typeMenuProg},
  { "���� ��30", (void *)&UprCompDVMidd, typeMenuProg},
  { "���� ��31", (void *)&UprCompDVMidd, typeMenuProg},
  { "���� ��32", (void *)&UprCompDVMidd, typeMenuProg},
  { "���� ��33", (void *)&UprCompDVHi, typeMenuProg},
  { "���� ��34", (void *)&UprCompDVHi, typeMenuProg},
  { "���� ��35", (void *)&UprCompDVHi, typeMenuProg},
  { "���� ��36", (void *)&UprCompDVHi, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compRELE[] =
{
  { "������ ����", NULL},//title
  { &CONTROL_URELE,   &sub_menu_upr_compUVV, typeMenuList},//control_item, parent
/*
  { "����� ���� �01",      (void *)&UprCompRELE, typeMenuProg},
  { "����� ���� �02",      (void *)&UprCompRELE, typeMenuProg},
  { "����� ���� �03",      (void *)&UprCompRELE, typeMenuProg},
  { "����� ���� �04",      (void *)&UprCompRELE, typeMenuProg},
  { "����� ���� �05",      (void *)&UprCompRELE, typeMenuProg},
  { "����� ���� �06",      (void *)&UprCompRELE, typeMenuProg},
  { "����� ���� �07",      (void *)&UprCompRELE, typeMenuProg},
  { "����� ���� �08",      (void *)&UprCompRELE, typeMenuProg},
  { "����� ���� �09",      (void *)&UprCompRELE, typeMenuProg},
  { "����� ���� �010",     (void *)&UprCompRELE, typeMenuProg},
  { "����� ���� �011",     (void *)&UprCompRELE, typeMenuProg},
  { "����� ���� �012",     (void *)&UprCompRELE, typeMenuProg},
  { "����� ���� �013",     (void *)&UprCompRELE, typeMenuProg},
  { "����� ���� �014",     (void *)&UprCompRELE, typeMenuProg},
  { "����� ���� �015",     (void *)&UprCompRELE, typeMenuProg},
  { "����� ���� �016",     (void *)&UprCompRELE, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compCDI[] =
{
  { "������ ���", NULL},//title
  { &CONTROL_UCDI,   &sub_menu_upr_compUVV, typeMenuList},//control_item, parent
/*
  { "����� ���01",      (void *)&UprCompCDI, typeMenuProg},
  { "����� ���02",      (void *)&UprCompCDI, typeMenuProg},
  { "����� ���03",      (void *)&UprCompCDI, typeMenuProg},
  { "����� ���04",      (void *)&UprCompCDI, typeMenuProg},
  { "����� ���05",      (void *)&UprCompCDI, typeMenuProg},
  { "����� ���06",      (void *)&UprCompCDI, typeMenuProg},
  { "����� ���07",      (void *)&UprCompCDI, typeMenuProg},
  { "����� ���08",      (void *)&UprCompCDI, typeMenuProg},
  { "����� ���09",      (void *)&UprCompCDI, typeMenuProg},
  { "����� ���010",     (void *)&UprCompCDI, typeMenuProg},
  { "����� ���011",     (void *)&UprCompCDI, typeMenuProg},
  { "����� ���012",     (void *)&UprCompCDI, typeMenuProg},
*/
  { NULL, NULL}

};

void PereinitUstListCompPRM1(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidPRM1, sub_menu_ust_compPRM1);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void PereinitUstListCompUVV(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidPRM1, sub_menu_ust_compUVV);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UstListCompPRM1()
{
  SelectorMNGBAZA(MNGUST_PRM1_BO);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compPRM1);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompPRM1);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompPRM1()

void UstCompPRM1()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compPRM1);
  PassWord(EditUstPRM1);
}//VidCompPRM1()

void EditUstPRM1()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compPRM1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompPRM1()

void UstListCompUVV()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compUVV);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompUVV);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompUVV()

void UstCompUVV()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compUVV);
  PassWord(EditUstUVV);
}//VidCompUVV()

void EditUstUVV()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compUVV);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompUVV()

short  KadrMenuFormat_ustvidPRM1(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  char locTxt[50];
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    if(((LineMenuItem *)workCntr->userPoint)[i+1+SUBDATA].Line1==NULL)break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, (char *)( ((LineMenuItem *)workCntr->userPoint) )[i+1+SUBDATA].Line1);
      sprintf(locTxt, "   %d", getUstOffsetMngUSTAVKI(i));
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, locTxt);
      return 1;//�������� �������� ������
    }
  }//for

  return 1;
}//KadrMenuFormat_ust_1(WorkControl *workCntr)

//--------------------------------------------------

void PereinitVidListCompPRM1(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidPRM1, sub_menu_vid_compPRM1);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void VidListCompPRM1()
{
  SelectorMNGBAZA(MNGVID_PRM1);//��������� ���� �������

  SelectorSUBMENU(sub_menu_vid_compPRM1);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitVidListCompPRM1);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompPRM1()

void UprListCompUVV()
{
//  CRR_SUBMENU = sub_menu_upr_compUVV;//������� �������
  SelectorSUBMENU(sub_menu_upr_compUVV);//��������� ������� �������

//  CRR_TEXTSTREAM = &CONTROL_UVV;//������� control
  SelectorTEXTCONTROL(&CONTROL_UVV);//������� control
//  CRR_FHOME = &PereinitUprListCompUVV;//��������� �� �-��� HOME

//  CRR_FHOME(1);//��������
  SelectorFHOME(&PereinitUprListCompUVV);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UprListCompUVV()

void VidCompPRM1()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_vid_compPRM1);
//  PassWord(EditVidAPV);
  EditVidPRM1();
}//VidCompPRM1()

void EditVidPRM1()
{
//������������� �������
  SystemEditUst(sub_menu_vid_compPRM1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompPRM1(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compPRM1, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstList

void PereinitUprListCompUVV(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL_UVV, &KadrMenuFormat_sub, sub_menu_upr_compUVV);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL_UVV, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuSub();//������� ���� �����������
  LanderPStr();//���������� ��������� ������
//  ListPStr();//������ � ��������
}//PereinitUprListCompUVV(short flg)

void UprListCompPRM1()
{
  SelectorMNGBAZA(MNGUPR_PRM1);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compPRM1);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUprListCompPRM1);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompPRM1()

void UprCompPRM1()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compPRM1);
  PassWord(EditUprPRM1);

}//UprCompPRM1()

void EditUprPRM1()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compPRM1[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrPRM1);//������������� ������� ����������
}//EditUprPRM1()

void UprListCompDV()
{
  SelectorMNGBAZA(MNGUPR_DVLOW);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compDV);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL_UDV);//������� control

  SelectorFHOME(&PereinitUprListCompDV);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompDV()

void UprCompDVLow()
{
  SelectorMNGBAZA(MNGUPR_DVLOW);//��������� ���� �������
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compDV);
  PassWord(EditUprDV);

}//UprCompDVLow()
void UprCompDVMidd()
{
  SelectorMNGBAZA(MNGUPR_DVMIDD);//��������� ���� �������
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compDV);
  PassWord(EditUprDV);

}//UprCompDVMidd()
void UprCompDVHi()
{
  SelectorMNGBAZA(MNGUPR_DVHI);//��������� ���� �������
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compDV);
  PassWord(EditUprDV);

}//UprCompDVHi()

void EditUprDV()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compDV[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrDV);//������������� ������� ����������
}//EditUprDV()

void PereinitUprListCompDV(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL_UDV, &KadrMenuFormat_upr_compDV, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL_UDV, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUprListCompDV(short flg)

void UprListCompRELE()
{
  SelectorMNGBAZA(MNGUPR_RELE);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compRELE);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL_URELE);//������� control

  SelectorFHOME(&PereinitUprListCompRELE);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompRELE()

void UprCompRELE()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compRELE);
  PassWord(EditUprRELE);

}//UprCompRELE()

void EditUprRELE()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compRELE[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrRELE);//������������� ������� ����������
}//EditUprRELE()

void PereinitUprListCompRELE(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL_URELE, &KadrMenuFormat_upr_compRELE, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL_URELE, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUprListCompRELE(short flg)

void UprListCompCDI()
{
  SelectorMNGBAZA(MNGUPR_CDI);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compCDI);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL_UCDI);//������� control

  SelectorFHOME(&PereinitUprListCompCDI);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompCDI()

void UprCompCDI()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compCDI);
  PassWord(EditUprCDI);

}//UprCompCDI()

void EditUprCDI()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compCDI[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrRELE);//������������� ������� ����������
}//EditUprCDI()

void PereinitUprListCompCDI(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL_UCDI, &KadrMenuFormat_upr_compCDI, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL_UCDI, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUprListCompCDI(short flg)

short  KadrMenuFormat_upr_compPRM1(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    char *nameUpr = (char *)sub_menu_upr_compPRM1[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrPRM1(i, getCurrentMngUSTAVKI()));

      return 1;//�������� �������� ������
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compPRM1(WorkControl *workCntr)

short  KadrMenuFormat_upr_compDV(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
 short offset=0;
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    char *nameUpr = (char *)sub_menu_upr_compDV[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      LIGHTMNGUBAZA = MNGUPR_DVLOW;//�������� �� 16 ��
      offset=i;
      if(i>15){
            offset=i-16;
            LIGHTMNGUBAZA = MNGUPR_DVMIDD;//�������� cp 16 ��
            }
      if(i>31){
            LIGHTMNGUBAZA = MNGUPR_DVHI;//�������� ct 16 ��
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
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
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
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
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
  //������� �������
  if (init)
  {
//������� ��������
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
//������� ��������
    tmpUSTAVKI[MNGVID_PRM1]     = 3000;
    tmpUSTAVKI[MNGVID_PRM1_V]   = 600;
    tmpUSTAVKI[MNGVID_PRM1_DIS] = 60000;//������ ��� ���
//������� ����������
    tmpUSTAVKI[MNGUPR_PRM1] = 0;
//������� ����������
    tmpUSTAVKI[MNGUPR_DVLOW] = 0;
    tmpUSTAVKI[MNGUPR_DVMIDD] = 0;
    tmpUSTAVKI[MNGUPR_DVHI] = 0;
//������� ����������
    tmpUSTAVKI[MNGUPR_RELE] = 0;
//������� ����������
    tmpUSTAVKI[MNGUPR_CDI] = 0;
//���� ����
    tmpUSTAVKI[MNGUST_PRM1_BO] = 122;
//���� ���
    tmpUSTAVKI[MNGUST_PRM1_BV] = 123;

  }//if

  offsetSPVCmdPRM1 = IndexUstSPV;//�������� ��� SPV PRM1
  IndexUstSPV += SPVUST_PRM1_TOTAL;//������ ������� � �����������
  return MNGUST_PRM1_TOTAL;//�-�� ������� � ��������� �������
}//initUstPRM1(char init)

void  prepareUstPRM1(short idxC)
{
//�������� �� ������� PRM1
  offsetUstMngPRM1 = getClonOffsetMngUSTAVKI(idxC, 0);//��������� �������� ������� ����� idxC
  //���������� ENA ������ ��� �����
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_PRM1), ENACMD_PRM1_TOTAL);
  //���������� �������
  int tmpOffsetUSpv = getOffsetSPVUstCnf(idxC);//�������� ������� ������ �����������
  //������ ��
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

//������� �� -���������������
  SPV_UST(SPV_UPR_DVLOW) =
    getNativUstMngUSTAVKI(idxC, MNGUPR_DVLOW);
  SPV_UST(SPV_UPR_DVMIDD) =
    getNativUstMngUSTAVKI(idxC, MNGUPR_DVMIDD);
  SPV_UST(SPV_UPR_DVHI) =
    getNativUstMngUSTAVKI(idxC, MNGUPR_DVHI);

//������� ���� -��������������������
  int spvupr_rele =
  SPV_UST(SPV_UPR_RELE) =
    getNativUstMngUSTAVKI(idxC, MNGUPR_RELE);

//������� ��� -��������������������
  int spvupr_cdi =
  SPV_UST(SPV_UPR_CDI) =
    getNativUstMngUSTAVKI(idxC, MNGUPR_CDI);
//�������� �������� � ���� ����
  ReleTrigger &= spvupr_rele;//����� ����
//�������� �������� � ���� ���
  CDITrigger  &= spvupr_cdi;//����� ���

  //������� SPV �������� 20V
  SPV_UST(SPVSRAB_02UH) = 20000;
  //������� SPV �������� DOWN
  SPV_UST(SPVVOZV_02UH) = 21000;

  //������� SPV �������� 6A
  SPV_UST(SPVSRAB_12IH) = 6000;
  //������� SPV �������� DOWN
  SPV_UST(SPVVOZV_12IH) = 6300;

  //������� SPV ��������
  SPV_UST(SPVSRAB_U005) = 5000;
  //������� SPV ��������
  SPV_UST(SPVVOZV_U005) = 5250;

  //������� SPV �������� 0.25B
  SPV_UST(SPVSRAB_U025) = 250;
  //������� SPV ��������
  SPV_UST(SPVVOZV_U025) = 262;

  //������� SPV �������� 0.05A
//  SPV_UST(SPVSRAB_I005) = 50;
  //������� SPV ��������
  //SPV_UST(SPVVOZV_I005) = 53;

  //������� SPV ��������
  SPV_UST(SPVSRAB_ICM005) = 50;
  //������� SPV ��������
  SPV_UST(SPVVOZV_ICM005) = 53;
  //������� SPV ��������
  SPV_UST(SPVSRAB_UCM005) = 50;
  //������� SPV ��������
  SPV_UST(SPVVOZV_UCM005) = 53;
  //������� SPV �������� 20V
  SPV_UST(SPVSRAB_DZ_02UH) = 11540;//20000;
  //������� SPV �������� UP
  SPV_UST(SPVVOZV_DZ_02UH) = 10963;//19000;

  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //��������� � ������������

         //������ 1
  setTimerPorog(tmpOffsetT+ TIMER1_PRM1,
    getNativUstMngUSTAVKI(idxC, MNGVID_PRM1));

         //������ 2
  setTimerPorog(tmpOffsetT+ TIMER2_PRM1,
    getNativUstMngUSTAVKI(idxC, MNGVID_PRM1_V));

     //������ ������ SEAM
  setTimerPorog(tmpOffsetT+ TIMER_SEAM_PRM1, 5);

    //������ DIS
  setTimerPorog(tmpOffsetT+ TIMERDIS_PRM1, 60000);

   //����� ������ DIS
  setTimerPorog(tmpOffsetT+ TIMER_MINDIS_PRM1, 20);
   //������ ��
  setTimerPorog(tmpOffsetT+ TIMER_RELEBO, 22);
   //������ �B
  setTimerPorog(tmpOffsetT+ TIMER_RELEBV, 33);

  //�������a UI ��� ��
  setTimerPorog(tmpOffsetT+ TIMER_UINCNDZ_PRM1, 
    getNativUstMngUSTAVKI(idxC, MNGVID_PRM1_UINCNDZ));
  //�������� ����� ���������� CM ��� ��
  setTimerPorog(tmpOffsetT+ TIMER_CMNCNDZ_PRM1, 
    getNativUstMngUSTAVKI(idxC, MNGVID_PRM1_CMNCNDZ));
  //05 ��� ��
  setTimerPorog(tmpOffsetT+ TIMER_05NCNDZ_PRM1, 500);

}//prepareUstMTZ1(short idxC)

int initIOCmd_PRM1()
{
  //������� IO ������
  offsetIOCmdPRM1 = IndexIO;//�������� ��� IO PRM1
  return commonInitIOCmd(IOCMD_PRM1_TOTAL);
}//initIOCmd_PRM1()

int initTLCmd_PRM1()
{
  //������� TL ������
  return commonInitTLCmd(TLCMD_PRM1_TOTAL);
}//initTLCmd_PRM1()

int initENACmd_PRM1()
{
  //������� ENA ������
  offsetENACmdPRM1 = IndexENA;//�������� ��� ENA PRM1
  return commonInitENACmd(ENACMD_PRM1_TOTAL);
}//initENACmd_PRM1()

void initTimersPRM1(short idxC)
{
  //������ � ������� ��������
  offsetTimersPRM1 = IndexTIMERS;//�������� �� ��������� ������
  commonInitTimers(TIMERS_PRM1_TOTAL);

}//initTimersPRM1()

int codecUstPRM1(char codec, short offset, int ust)
//codec=0-����������
//codec=1-�������������
{
  //����������-������������� �������
  if(codec) return ust*1;
  return ust/1;
}//codecUstPRM1(char *buf, short offset, int ust)

int isDISactiv_PRM1(int idxC)
{
//��������� ���������� ������������ ���
    int tmpOffsetT    =
                cnfCOMPONENT[idxC].offsetTimers;   //������� ���������� � ������������
  if( getTimerBUSY(tmpOffsetT+TIMER_MINDIS_PRM1) |
      getTimerFINISH(tmpOffsetT+TIMER_MINDIS_PRM1)
    ) return 1;//����� ������ DIS
  return 0;//��� ����������
}//isDISactiv_PRM1(int idxC)

void SaveUprPRM1(short numBit)
{
  /*
//������������ ���� upr ��� PRM1
  UNS_32 tmpU = getCurrentMngUSTAVKI();//������� ��� ���
  short ibit = numBit;
  if(numBit>15) ibit = numBit-16;
  if(numBit>31) ibit = numBit-32;
    if(FvmenuDis->UprCheck->Checked)
    {
      NumBitSettingWord(ibit, &tmpU);//��������� ���� �� ��� �������
    }//if(FvmenuDis->UprCheck->Checked)
    else
    {
      NumBitClearingWord(ibit, &tmpU);//����� ���� �� ��� �������
    }
  setCurrentMngUSTAVKI(tmpU);//����� ��� ���
  */
}//SaveUprPRM1()

char copyPRM1ToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//������� ������
//���������� ��������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.packet = 0;    //����� ��������� ����������
  rpzcomponent_obj.permanent = 1; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  PRM1_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_PRM1;//���� ����������

  rpzcomponent_obj.cntClon     = CNT_STUPEN_PRM1;   //max �-�� ������
  rpzcomponent_obj.numClon     = 1;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstPRM1;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstPRM1;//���������� �������
  rpzcomponent_obj.initIOCmd      = initIOCmd_PRM1;      //������� IO ������
  rpzcomponent_obj.initTLCmd      = initTLCmd_PRM1;      //������� TL ������
  rpzcomponent_obj.initENACmd     = initENACmd_PRM1;     //������� ENA ������
  rpzcomponent_obj.bo_bvCmd       = NULL; //��������� �� �� ������
  rpzcomponent_obj.isDISactiv     = isDISactiv_PRM1; //���������� ������������ ���
  rpzcomponent_obj.setBOBVtimer   = NULL; //������� �������� �� ��

  rpzcomponent_obj.nameStatusIO = ionsPRM1;          //����� � ������ ������ IO
  rpzcomponent_obj.initTimers   = initTimersPRM1;    //������ � ������� ��������
  rpzcomponent_obj.logic        = logicPRM1;         //������ ����������

  rpzcomponent_obj.codecUst = codecUstPRM1;   //����������-������������� �������

  return 0;//�� �������� �����������
}//

#endif // _HIDE_COMPONENT

