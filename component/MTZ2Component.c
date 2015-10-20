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

//��� �����������
#define KOD_COMPONENT  MTZ_COMP1
//�-�� ��������
#define CNT_STUPEN_MTZ  5

#endif // _HIDE_COMPONENT

//������������� �������  � ��������� �������
//������� ��������
#define MNGUST_MTZ2to5     0
#define MNGUST_MTZ2to5_V   1
#define MNGUST_MTZ2to5_N   2
#define MNGUST_MTZ2to5_PN  3
#define MNGUST_MTZ2to5_UPN 4

//������� ��������
#define MNGVID_MTZ2to5    5
#define MNGVID_MTZ2to5_V  6
#define MNGVID_MTZ2to5_N  7
#define MNGVID_MTZ2to5_PN 8
#define MNGVUSK_MTZ2to5   9
//���������
//����� ���2 
#define MNGUSK_MTZ2to5      10
//����� ���2 ��
#define MNGUSK_MTZ2to5_OU   11
//����� ���2 ��
#define MNGUSK_MTZ2to5_TU   12

//����� ���2 ���
#define MNGUSK_MTZ2to5_V    13
//����� ���2 �� ���
#define MNGUSK_MTZ2to5_V_OU 14
//����� ���2 �� ���
#define MNGUSK_MTZ2to5_V_TU 15

//����� ���2 ���
#define MNGUSK_MTZ2to5_N    16
//����� ���2 �� ���
#define MNGUSK_MTZ2to5_N_OU 17
//����� ���2 �� ���
#define MNGUSK_MTZ2to5_N_TU 18

//����� ���2 ��
#define MNGUSK_MTZ2to5_PN    19
//����� ���2 �� ��
#define MNGUSK_MTZ2to5_PN_OU 20
//����� ���2 �� ��
#define MNGUSK_MTZ2to5_PN_TU 21


//������� ����������
#define MNGUPR_MTZ2to5        22
//�-�� ������� � ��������� �������
#define MNGUST_MTZ2to5_TOTAL  23
//#define MNGUST_BOBV_MTZ2to5  MNGUST_MTZ2to5_TOTAL

//������������� ENA ������
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
//�-�� ENA ������
#define ENACMD_MTZ2to5_TOTAL 8

//������������� ������� � �����������
//������� ��������
#define SPVSRABUST_MTZ2to5     0
#define SPVSRABUST_MTZ2to5_V   1
#define SPVSRABUST_MTZ2to5_N   2
#define SPVSRABUST_MTZ2to5_PN  3
#define SPVSRABUST_MTZ2to5_UPN 4
//������� ��������
#define SPVVOZVUST_MTZ2to5     5
#define SPVVOZVUST_MTZ2to5_V   6
#define SPVVOZVUST_MTZ2to5_N   7
#define SPVVOZVUST_MTZ2to5_PN  8
#define SPVVOZVUST_MTZ2to5_UPN 9

//������� SPV �����
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
//�-�� ������� � �����������
#define SPVUST_MTZ2to5_TOTAL  25

//---------------IO COMMAND------------------
//������������� IO ������ ��� MTZ2to5
//���� ���� ���2
//CMD_MTZ2to5
#define IOCMD1_MTZ2to5 0
//���� ��� ���2
//CMD_BLOK_USK_MTZ2to5
#define IOCMD2_MTZ2to5 1
//������ ��� ���2
//CMD_OPERAT_USK_MTZ2to5
#define IOCMD3_MTZ2to5 2
//���� �� ���2
//CMD_MTZ2to5_PO1
#define IOCMD4_MTZ2to5 3
//���� �� ���2 ���
//CMD_MTZ2to5_PO2
#define IOCMD5_MTZ2to5 4
//���� �� ���2 ���
//CMD_MTZ2to5_PO3
#define IOCMD6_MTZ2to5 5
//���� �� ���2 ��
//CMD_MTZ2to5_PO4
#define IOCMD7_MTZ2to5 6
//���� ���2
//CMD_MTZ2to5
#define IOCMD8_MTZ2to5 7
//���� ��� MTZ2to5
#define IOCMD9_MTZ2to5 8
//������ ���2to5 ���
#define IOCMD10_MTZ2to5 9
//������ ���2to5 ���
#define IOCMD11_MTZ2to5 10
//�-�� IO ������
#define IOCMD_MTZ2to5_TOTAL    11

//---------------TL COMMAND------------------
//������������� TL ������ ��� MTZ2to5
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

//�-�� TL ������
#define TLCMD_MTZ2to5_TOTAL    60

//--------------- TIMERS ------------------
//������������� �������� ��� MTZ2to5
//������ MTZ2to5_TIM
#define TIMER1_MTZ2to5     0
//������ MTZ2to5_V_TIM
#define TIMER2_MTZ2to5     1
//������ MTZ2to5_N_TIM
#define TIMER3_MTZ2to5     2
//������ MTZ2to5_PN_TIM
#define TIMER4_MTZ2to5     3

//������ VUSKOR_MTZ2to5_TIM
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

//������ BO_MTZ2to5_TIM
#define TIMER_BO_MTZ2to5       17
//�-�� ��������
#define TIMERS_MTZ2to5_TOTAL   18

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "PRM1Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_MTZ[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//������ ������� � �����������
extern int  IndexIO;//������ IO

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//������� ������� �����������
extern char *bitStringUNI[];
extern int offsetUstMngPRM1;//�������� �� ������� PRM1

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

TWIN_DIFFERENT twinMTZ2[3];//������ �������� ���������

int  offsetIOCmdMTZ5;//�������� ��� IO MTZ5

char MTZ2_TITLE[] = "���2";

IONAMESTATUS_COMPONENT ionsMTZ2[IOCMD_MTZ2to5_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� ���� ���2"
  },
  {
    1,//������ iocmd2
    "���� ��� ���2"
  },
  {
    1,//������ iocmd3
    "������ ��� ���2"
  },
  {
    1,//������ iocmd4
    "���� �� ���2"
  },
  {
    1,//������ iocmd5
    "���� �� ���2 ���"
  },
  {
    1,//������ iocmd6
    "���� �� ���2 ���"
  },
  {
    1,//������ iocmd7
    "���� �� ���2 ��"
  },
  {
    1,//������ iocmd8
    "���� ���2"
  },
  {
    1,//������ iocmd9
    "���� ��� ���2"
  },
  {
    1,//������ iocmd10
    "������ ���2 ���"
  },
  {
    1,//������ iocmd11
    "������ ���2 ���"
  }
};

LineMenuItem sub_menu_comp_MTZ2[8] =
{
  { MTZ2_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_MTZ, typeMenuSub},//control_item, parent
  { "������� ���2",    (void*)&UstListCompMTZ2, typeMenuProg},
  { "�������� ���2",   (void*)&VidListCompMTZ2, typeMenuProg},
  { "���������� ���2", (void*)&UprListCompMTZ2, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compMTZ2[] =
{
  { "������� ���2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ2, typeMenuList},//control_item, parent
  { "��� ���2",         (void*)&UstCompMTZ2, typeMenuProg},
  { "��� ���2 ������",  (void*)&UstCompMTZ2, typeMenuProg},
  { "��� ���2 �����",   (void*)&UstCompMTZ2, typeMenuProg},
  { "��� ���2 ��",      (void*)&UstCompMTZ2, typeMenuProg},
  { "��� ���� ���2 �H", (void*)&UstCompMTZ2, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compMTZ2[] =
{
  { "�������� ���2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ2, typeMenuList},//control_item, parent
/*
  { "�������� ���2",         (void*)&VidCompMTZ2, typeMenuProg},
  { "�������� ���2 ������",  (void*)&VidCompMTZ2, typeMenuProg},
  { "�������� ���2 �����",   (void*)&VidCompMTZ2, typeMenuProg},
  { "�������� ���2 ��",      (void*)&VidCompMTZ2, typeMenuProg},
  { "���� ����� ���2",       (void*)&VidCompMTZ2, typeMenuProg},

  { "����� ���2 ��",         (void*)&VidCompMTZ2, typeMenuProg},
  { "����� ���2 ��",         (void*)&VidCompMTZ2, typeMenuProg},
  { "����� ���2 ��",         (void*)&VidCompMTZ2, typeMenuProg},

  { "����� ���2 �� ���",     (void*)&VidCompMTZ2, typeMenuProg},
  { "����� ���2 �� ���",     (void*)&VidCompMTZ2, typeMenuProg},
  { "����� ���2 �� ���",     (void*)&VidCompMTZ2, typeMenuProg},

  { "����� ���2 �� ���",     (void*)&VidCompMTZ2, typeMenuProg},
  { "����� ���2 �� ���",     (void*)&VidCompMTZ2, typeMenuProg},
  { "����� ���2 �� ���",     (void*)&VidCompMTZ2, typeMenuProg},

  { "����� ���2 �� ��",      (void*)&VidCompMTZ2, typeMenuProg},
  { "����� ���2 �� ��",      (void*)&VidCompMTZ2, typeMenuProg},
  { "����� ���2 �� ��",      (void*)&VidCompMTZ2, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compMTZ2[] =
{
  { "������ ���2", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_MTZ2, typeMenuList},//control_item, parent
  { "��� ���2",           (void*)&UprCompMTZ2, typeMenuProg},
  { "������ ���2",        (void*)&UprCompMTZ2, typeMenuProg},
  { "���2 ���",           (void*)&UprCompMTZ2, typeMenuProg},
  { "���2 ���",           (void*)&UprCompMTZ2, typeMenuProg},
  { "��������� �� ���2",  (void*)&UprCompMTZ2, typeMenuProg},
  { "������� ��� ���2",   (void*)&UprCompMTZ2, typeMenuProg},
  { "��������� ���2",     (void*)&UprCompMTZ2, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompMTZ2(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_ust_compMTZ2);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UstListCompMTZ2()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compMTZ2);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompMTZ2);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompMTZ2()

void UstCompMTZ2()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compMTZ2);
  PassWord(EditUstMTZ2);
}//VidCompMTZ2()

void EditUstMTZ2()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compMTZ2);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompMTZ2()

//--------------------------------------------------

void PereinitVidListCompMTZ2(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_vid_compMTZ2);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void VidListCompMTZ2()
{
  SelectorMNGBAZA(MNGVID_MTZ2to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_vid_compMTZ2);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitVidListCompMTZ2);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ2()

void VidCompMTZ2()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_vid_compMTZ2);
//  PassWord(EditVidAPV);
  EditVidMTZ2();
}//VidCompMTZ2()

void EditVidMTZ2()
{
//������������� �������
  SystemEditUst(sub_menu_vid_compMTZ2);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompMTZ2(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compMTZ2, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UprListCompMTZ2()
{
  SelectorMNGBAZA(MNGUPR_MTZ2to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compMTZ2);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUprListCompMTZ2);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ2()

void UprCompMTZ2()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compMTZ2);
  PassWord(EditUprMTZ2);
}//VidCompMTZ2()

void EditUprMTZ2()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compMTZ2[LIGHTLINEMENU +1+SUBDATA].Line1;

  switch(LIGHTLINEMENU)
  {
    case 0: UpravlRedactorChooseMTZ(nameUpr, LIGHTLINEMENU);//������������� ������� ����������
    break;
    default:UpravlRedactor(nameUpr, LIGHTLINEMENU+1, &selectorUprStrMTZ2);//������������� ������� ����������
  }//switch

}//EditVidMTZ2()

short  KadrMenuFormat_upr_compMTZ2(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  short chooseBit = 2;//�-�� ��� � choose
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
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

      return 1;//�������� �������� ������
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
  //������� �������
  if (init)
  {
//������� ��������
    tmpUSTAVKI[MNGUST_MTZ2to5]     = 100;
    tmpUSTAVKI[MNGUST_MTZ2to5_V]   = 110;
    tmpUSTAVKI[MNGUST_MTZ2to5_N]   = 120;
    tmpUSTAVKI[MNGUST_MTZ2to5_PN]  = 130;
    tmpUSTAVKI[MNGUST_MTZ2to5_UPN] = 131;
//������� ��������
    tmpUSTAVKI[MNGVID_MTZ2to5]    = 25;
    tmpUSTAVKI[MNGVID_MTZ2to5_V]  = 26;
    tmpUSTAVKI[MNGVID_MTZ2to5_N]  = 27;
    tmpUSTAVKI[MNGVID_MTZ2to5_PN] = 28;
    tmpUSTAVKI[MNGVUSK_MTZ2to5]   = 29;
//���������
//����� ���2 
    tmpUSTAVKI[MNGUSK_MTZ2to5]      = 30;
    tmpUSTAVKI[MNGUSK_MTZ2to5_OU]   = 31;
//����� ���2 ��
    tmpUSTAVKI[MNGUSK_MTZ2to5_TU]   = 32;

//����� ���2 ���
    tmpUSTAVKI[MNGUSK_MTZ2to5_V]      = 33;
//����� ���2 �� ���
    tmpUSTAVKI[MNGUSK_MTZ2to5_V_OU]   = 34;
//����� ���2 �� ���
    tmpUSTAVKI[MNGUSK_MTZ2to5_V_TU]   = 35;

//����� ���2 ���
    tmpUSTAVKI[MNGUSK_MTZ2to5_N]      = 36;
//����� ���2 �� ���
    tmpUSTAVKI[MNGUSK_MTZ2to5_N_OU]   = 37;
//����� ���2 �� ���
    tmpUSTAVKI[MNGUSK_MTZ2to5_N_TU]   = 38;

//����� ���2 ��
    tmpUSTAVKI[MNGUSK_MTZ2to5_PN]      = 39;
//����� ���2 �� ��
    tmpUSTAVKI[MNGUSK_MTZ2to5_PN_OU]   = 40;
//����� ���2 �� ��
    tmpUSTAVKI[MNGUSK_MTZ2to5_PN_TU]   = 41;
//������� ����������
    tmpUSTAVKI[MNGUPR_MTZ2to5] = 0;

  }//if

  IndexUstSPV += SPVUST_MTZ2to5_TOTAL;//������ ������� � �����������
  return MNGUST_MTZ2to5_TOTAL;//�-�� ������� � ��������� �������
}//initUstMTZ2(short mngUst, char init)

void  prepareUstMTZ2(short idxC)
{
  //���������� ENA ������ ��� �����
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_MTZ2to5), ENACMD_MTZ2to5_TOTAL);
  //���������� �������
  int tmpOffsetUSpv = getOffsetSPVUstCnf(idxC);//�������� ������� ������ �����������

    //������� SPV ��������
    int tmp1 = 
    SPV_UST(SPVSRABUST_MTZ2to5) = codecUstMTZ2(1, MNGUST_MTZ2to5, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ2to5));
    //������� SPV ��������
    SPV_UST(SPVVOZVUST_MTZ2to5) = tmp1 - tmp1/20;//5%

    //������� SPV ��������
        tmp1 =
    SPV_UST(SPVSRABUST_MTZ2to5_V) = codecUstMTZ2(1, MNGUST_MTZ2to5_V, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ2to5_V));
    //������� SPV ��������
    SPV_UST(SPVVOZVUST_MTZ2to5_V) = tmp1 - tmp1/20;//5%

    //������� SPV ��������
        tmp1 =
    SPV_UST(SPVSRABUST_MTZ2to5_N) = codecUstMTZ2(1, MNGUST_MTZ2to5_N, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ2to5_N));
    //������� SPV ��������
    SPV_UST(SPVVOZVUST_MTZ2to5_N) = tmp1 - tmp1/20;//5%

    //������� SPV ��������
        tmp1 =
    SPV_UST(SPVSRABUST_MTZ2to5_PN) = codecUstMTZ2(1, MNGUST_MTZ2to5_PN, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ2to5_PN));
    //������� SPV ��������
    SPV_UST(SPVVOZVUST_MTZ2to5_PN) = tmp1 - tmp1/20;//5%

    //������� SPV �������� DOWN
        tmp1 =
    SPV_UST(SPVSRABUST_MTZ2to5_UPN) = codecUstMTZ2(1, MNGUST_MTZ2to5_UPN, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ2to5_UPN));
    //������� SPV ��������
    SPV_UST(SPVVOZVUST_MTZ2to5_UPN) = tmp1 + tmp1/20;//5% DOWN

  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //��������� � ������������

            //������ MTZ2_TIM
  setTimerPorog(tmpOffsetT+ TIMER1_MTZ2to5,
          codecUstMTZ2(1, MNGVID_MTZ2to5, getNativUstMngUSTAVKI(idxC, MNGVID_MTZ2to5)));

          //������ MTZ2_V_TIM
  setTimerPorog(tmpOffsetT+ TIMER2_MTZ2to5,
          codecUstMTZ2(1, MNGVID_MTZ2to5_V, getNativUstMngUSTAVKI(idxC, MNGVID_MTZ2to5_V)));

          //������ MTZ2_N_TIM
  setTimerPorog(tmpOffsetT+ TIMER3_MTZ2to5,
          codecUstMTZ2(1, MNGVID_MTZ2to5_N, getNativUstMngUSTAVKI(idxC, MNGVID_MTZ2to5_N)));

           //������ MTZ2_PN_TIM
  setTimerPorog(tmpOffsetT+ TIMER4_MTZ2to5,
          codecUstMTZ2(1, MNGVID_MTZ2to5_PN, getNativUstMngUSTAVKI(idxC, MNGVID_MTZ2to5_PN)));

           //������ VUSKOR_MTZ2_TIM
  setTimerPorog(tmpOffsetT+ TIMER_VUSK_MTZ2to5,
          codecUstMTZ2(1, MNGVUSK_MTZ2to5, getNativUstMngUSTAVKI(idxC, MNGVUSK_MTZ2to5)));

  int  tmp =    codecUstMTZ2(1, MNGUSK_MTZ2to5_OU, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_OU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_OU, tmp);

//����� ���2 
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5, tmp);
//����� ���2 ��
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_TU, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_TU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_TU, tmp);

//����� ���2 �� ���
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_V_OU, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_V_OU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_V_OU, tmp);
//����� ���2 ���
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_V, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_V));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_V, tmp);
//����� ���2 �� ���
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_V_TU, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_V_TU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_V_TU, tmp);

//����� ���2 �� ���
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_N_OU, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_N_OU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_N_OU, tmp);
//����� ���2 ���
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_N, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_N));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_N, tmp);
//����� ���2 �� ���
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_N_TU, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_N_TU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_N_TU, tmp);

//����� ���2 �� ��
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_PN_OU, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_PN_OU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_PN_OU, tmp);
//����� ���2 ��
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_PN, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_PN));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_PN, tmp);
//����� ���2 �� ��
  tmp =        codecUstMTZ2(1, MNGUSK_MTZ2to5_PN_TU, getNativUstMngUSTAVKI(idxC, MNGUSK_MTZ2to5_PN_TU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER5_MTZ2to5_PN_TU, tmp);

        //������  BO
  setTimerPorog(tmpOffsetT+ TIMER_BO_MTZ2to5, 10);


}//prepareUstMTZ2(short idxC)

int initIOCmd_MTZ2()
{
  //������� IO ������
  offsetIOCmdMTZ5 = IndexIO;//�������� ��� IO MTZ5
  return commonInitIOCmd(IOCMD_MTZ2to5_TOTAL);
}

int initTLCmd_MTZ2()
{
  //������� TL ������
  return commonInitTLCmd(TLCMD_MTZ2to5_TOTAL);
}//initTLCmd_MTZ2()

int initENACmd_MTZ2()
{
  //������� ENA ������
  return commonInitENACmd(ENACMD_MTZ2to5_TOTAL);
}//initENACmd_MTZ2()

void initTimersMTZ2(short idxC)
{
  //������ � ������� ��������
  commonInitTimers(TIMERS_MTZ2to5_TOTAL);

}//initTimersMTZ2()

int codecUstMTZ2(char codec, short offset, int ust)
//codec=0-����������
//codec=1-�������������
{
  //����������-������������� �������
int grzHI = 0;//���� �������
int grzLOW= 0;//��� �������
int step  = 1;//���
  switch(offset)
  {
   //�������
   case MNGUST_MTZ2to5:
   case MNGUST_MTZ2to5_V:
   case MNGUST_MTZ2to5_N:
   case MNGUST_MTZ2to5_PN:
   case MNGUST_MTZ2to5_UPN:
       grzHI = 1000000;//���� �������
       grzLOW= 0;//��� �������
       step  = 1;//���
   break;

  //��������
//   case MNGUST_BOBV_MTZ2to5://������� �� ��
   case MNGVID_MTZ2to5:
   case MNGVID_MTZ2to5_V:
   case MNGVID_MTZ2to5_N:
   case MNGVID_MTZ2to5_PN:
   case MNGVUSK_MTZ2to5:

   case MNGUSK_MTZ2to5_OU:
//����� ���2 ��
   case MNGUSK_MTZ2to5:
//����� ���2 ��
   case MNGUSK_MTZ2to5_TU:

//����� ���2 �� ���
   case MNGUSK_MTZ2to5_V_OU:
//����� ���2 �� ���
   case MNGUSK_MTZ2to5_V:
//����� ���2 �� ���
   case MNGUSK_MTZ2to5_V_TU:

//����� ���2 �� ���
   case MNGUSK_MTZ2to5_N_OU:
//����� ���2 �� ���
   case MNGUSK_MTZ2to5_N:
//����� ���2 �� ���
   case MNGUSK_MTZ2to5_N_TU:

//����� ���2 �� ��
   case MNGUSK_MTZ2to5_PN_OU:
//����� ���2 �� ��
   case MNGUSK_MTZ2to5_PN:
//����� ���2 �� ��
   case MNGUSK_MTZ2to5_PN_TU:

       grzHI = 2000000;//���� �������
       grzLOW= 0;//��� �������
       step  = 1;//���
   break;

   default:return ust;//������� ����������
  }//switch

  if(codec) return ust*step;
//������������� �������
  if(ust<grzLOW) return ERROR_UST;//-ust;
  if(ust>grzHI)  return ERROR_UST;//-ust;
  return ust/step;
}//codecUstMTZ2(char *buf, short offset, int ust)

int isDISactiv_MTZ2to5(int idxC)
{
 //���������� ������������ ���
  return 0;//��� ����������
}//isDISactiv_MTZ2to5(int idxC)

char copyMTZ2ToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//������� ������
//���������� ��������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  MTZ2_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_MTZ2;//sub_menu_component;

  rpzcomponent_obj.twinControl = &(twinMTZ2[0]);//������ �������� ���������
  twinMTZ2[0].twin_different = diffMTZ3ToRepozitar;//�-��� �������� ���������
  twinMTZ2[1].twin_different = diffMTZ4ToRepozitar;//�-��� �������� ���������
  twinMTZ2[2].twin_different = diffMTZ5ToRepozitar;//�-��� �������� ���������

  rpzcomponent_obj.cntClon     = CNT_STUPEN_MTZ;   //�-�� ������
  rpzcomponent_obj.numClon     = 2;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstMTZ2;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstMTZ2;//���������� �������
  rpzcomponent_obj.initIOCmd      = initIOCmd_MTZ2;      //������� IO ������
  rpzcomponent_obj.initTLCmd      = initTLCmd_MTZ2;      //������� TL ������
  rpzcomponent_obj.initENACmd     = initENACmd_MTZ2;     //������� ENA ������
  rpzcomponent_obj.bo_bvCmd       = NULL; //��������� �� �� ������
  rpzcomponent_obj.isDISactiv     = isDISactiv_MTZ2to5; //���������� ������������ ���
  rpzcomponent_obj.setBOBVtimer   = NULL; //������� �������� �� ��

  rpzcomponent_obj.nameStatusIO = ionsMTZ2;          //����� � ������ ������ IO
  rpzcomponent_obj.initTimers   = initTimersMTZ2;    //������ � ������� ��������
  rpzcomponent_obj.logic        = logicMTZ2to5;         //������ ����������

  rpzcomponent_obj.codecUst = codecUstMTZ2;   //����������-������������� �������

  return 0;//�� �������� �����������
}//

#endif // _HIDE_COMPONENT

