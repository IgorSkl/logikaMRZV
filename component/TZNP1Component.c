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
#define KOD_COMPONENT  TZNP_COMP1
//�-�� ��������
#define CNT_STUPEN_TZNP  5

#endif // _HIDE_COMPONENT

//������������� �������  � ��������� �������
//������� ��������
#define MNGUST_TZNP1to5_3I0  0
#define MNGUST_TZNP1to5_3U0  1

//������� ��������
#define MNGVID_TZNP1to5         2
#define MNGVID_TZNP1to5_3I0     3
#define MNGVID_TZNP1to5_3U0     4
//���������
//���� ����� ����1
#define MNGVUSK_TZNP1to5        5

//����� ����1 ��
#define MNGUSK_TZNP1to5         6
//����� ����1 ��
#define MNGUSK_TZNP1to5_OU      7
//����� ����1 ��
#define MNGUSK_TZNP1to5_TU      8

//����� ����1 3I0 ��
#define MNGUSK_TZNP1to5_3I0     9
//����� ����1 3I0 ��
#define MNGUSK_TZNP1to5_3I0_OU  10
//����� ����1 3I0 ��
#define MNGUSK_TZNP1to5_3I0_TU  11

//������� ����������
#define MNGUPR_TZNP1to5      12
//�-�� ������� � ��������� �������
#define MNGUST_TZNP1to5_TOTAL  13
//#define MNGUST_BOBV_TZNP1to5  MNGUST_TZNP1to5_TOTAL

//������������� ENA ������
//������ ����1
#define ENA1_TZNP1to5       0
//������ ����1 3I0
#define ENA2_TZNP1to5       1
//������ ����1 3U0
#define ENA3_TZNP1to5       2
//������� ����1
#define ENA4_TZNP1to5       3
//����� �� ����1
#define ENA5_TZNP1to5       4
//������� ��� ����1
#define ENA6_TZNP1to5       5
//��������� ����1
#define ENA7_TZNP1to5       6
//�-�� ENA ������
#define ENACMD_TZNP1to5_TOTAL 7

//������������� ������� � �����������
//������� ��������
#define SPVSRABUST_TZNP1to5_3I0  0
#define SPVSRABUST_TZNP1to5_3U0  1
//������� ��������
#define SPVVOZVUST_TZNP1to5_3I0  2
#define SPVVOZVUST_TZNP1to5_3U0  3
//������� SPV �����
#define SPV_OUT3I0_TZNP1to5      4
#define SPV_OUT3U0_TZNP1to5      5
//�-�� ������� � �����������
#define SPVUST_TZNP1to5_TOTAL  6

//---------------IO COMMAND------------------
//������������� IO ������ ��� TZNP1to5
//���� ���� ����1
//CMD_TZNP1to5
#define IOCMD1_TZNP1to5 0
//���� ��� ����1
//CMD_BLOK_USK_TZNP1to5
#define IOCMD2_TZNP1to5 1
//���� ��� ����1
//CMD_OPER_USK_TZNP1to5
#define IOCMD3_TZNP1to5 2
//���� �� ����1
//CMD_TZNP1to5_PO1
#define IOCMD4_TZNP1to5 3
//���� ����1
//CMD_TZNP1to5
#define IOCMD5_TZNP1to5 4
//���� �� ����1 3I0
//CMD_TZNP1to5_PO2
#define IOCMD6_TZNP1to5 5
//���� ����1 3I0
//CMD_TZNP1to5_3I0
#define IOCMD7_TZNP1to5 6
//���� �� ����1 3U0
//CMD_TZNP1to5_PO3
#define IOCMD8_TZNP1to5 7
//���� ����1 3U0
//CMD_TZNP1to5_3U0
#define IOCMD9_TZNP1to5 8
//���� ��� TZNP1to5
#define IOCMD10_TZNP1to5  9
//������ TZNP1to5 
#define IOCMD11_TZNP1to5  10
//�-�� IO ������
#define IOCMD_TZNP1to5_TOTAL    11

//---------------TL COMMAND------------------
//������������� TL ������ ��� TZNP1
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

//�-�� TL ������
#define TLCMD_TZNP1to5_TOTAL     31

//--------------- TIMERS ------------------
//������������� �������� ��� TZNP1
//������ TZNP1to5_TIM1
#define TIMER1_TZNP1to5        0
//������ TZNP1to5_TIM2
#define TIMER2_TZNP1to5        1
//������ TZNP1to5_TIM3
#define TIMER3_TZNP1to5        2

//���� ����� ����1
#define TIMER_VUSK_TZNP1to5    3

//����� ����1 ��
#define TIMER4_TZNP1to5         4
//����� ����1 ��
#define TIMER4_TZNP1to5_OU      5
//����� ����1 ��
#define TIMER4_TZNP1to5_TU      6

//����� ����1 3I0 ��
#define TIMER4_TZNP1to5_3I0     7
//����� ����1 3I0 ��
#define TIMER4_TZNP1to5_3I0_OU  8
//����� ����1 3I0 ��
#define TIMER4_TZNP1to5_3I0_TU  9

//������ BO_TZNP1to5_TIM
#define TIMER_BO_TZNP1to5       10
//������ BO_TZNP1to5_3I0_TIM
#define TIMER_BO_TZNP1to5_3I0   11
//������ BO_TZNP1to5_3U0_TIM
#define TIMER_BO_TZNP1to5_3U0   12
//�-�� ��������
#define TIMERS_TZNP1to5_TOTAL   13

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "PRM1Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_TZNP[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//������ ������� � �����������
extern int  IndexIO;//������ IO

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//������� ������� �����������
extern char *bitStringUNI[];
extern int offsetUstMngPRM1;//�������� �� ������� PRM1

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
TWIN_DIFFERENT twinTZNP1[4];//������ �������� ���������

int  offsetIOCmdTZNP5;//�������� ��� IO TZNP5

char TZNP1_TITLE[] = "����1";

IONAMESTATUS_COMPONENT ionsTZNP1[IOCMD_TZNP1to5_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� ���� ����1"
  },
  {
    1,//������ iocmd2
    "���� ��� ����1"
  },
  {
    1,//������ iocmd3
    "���� ��� ����1"
  },
  {
    1,//������ iocmd4
    "���� �� ����1"
  },
  {
    1,//������ iocmd5
    "���� ����1"
  },
  {
    1,//������ iocmd6
    "���� �� ����1 3I0"
  },
  {
    1,//������ iocmd7
    "���� ����1 3I0"
  },
  {
    1,//������ iocmd8
    "���� �� ����1 3U0"
  },
  {
    1,//������ iocmd9
    "���� ����1 3U0"
  },
  {
    1,//������ iocmd10
    "���� ��� ����1"
  },
  {
    1,//������ iocmd11
    "������ ����1"
  }
};

LineMenuItem sub_menu_comp_TZNP1[8] =
{
  { TZNP1_TITLE, NULL},//title
  { &CONTROL1_COMP,  &sub_menu_TZNP, typeMenuSub},//control_item, parent
  { "������� ����1",    (void*)&UstListCompTZNP1, typeMenuProg},
  { "�������� ����1",   (void*)&VidListCompTZNP1, typeMenuProg},
  { "���������� ����1", (void*)&UprListCompTZNP1, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compTZNP1[] =
{
  { "������� ����1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_TZNP1, typeMenuList},//control_item, parent
  { "��� ����1 3I0",    (void*)&UstCompTZNP1, typeMenuProg},
  { "��� ����1 3U0",    (void*)&UstCompTZNP1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compTZNP1[] =
{
  { "�������� ����1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_TZNP1, typeMenuList},//control_item, parent
/*
  { "�������� ����1",         (void*)&VidCompTZNP1, typeMenuProg},
  { "�������� ����1 3I0",     (void*)&VidCompTZNP1, typeMenuProg},
  { "�������� ����1 3U0",     (void*)&VidCompTZNP1, typeMenuProg},
  { "���� ����� ����1",       (void*)&VidCompTZNP1, typeMenuProg},

  { "����� ����1 ��",         (void*)&VidCompTZNP1, typeMenuProg},
  { "����� ����1 ��",         (void*)&VidCompTZNP1, typeMenuProg},
  { "����� ����1 ��",         (void*)&VidCompTZNP1, typeMenuProg},

  { "����� ����1 3I0 ��",     (void*)&VidCompTZNP1, typeMenuProg},
  { "����� ����1 3I0 ��",     (void*)&VidCompTZNP1, typeMenuProg},
  { "����� ����1 3I0 ��",     (void*)&VidCompTZNP1, typeMenuProg},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compTZNP1[] =
{
  { "������ ����1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_TZNP1, typeMenuList},//control_item, parent
  { "������ ����1",        (void*)&UprCompTZNP1, typeMenuProg},
  { "������ ����1 3I0",    (void*)&UprCompTZNP1, typeMenuProg},
  { "������ ����1 3U0",    (void*)&UprCompTZNP1, typeMenuProg},
  { "������� ����1",       (void*)&UprCompTZNP1, typeMenuProg},
  { "����� �� ����1",      (void*)&UprCompTZNP1, typeMenuProg},
  { "������� ��� ����1",   (void*)&UprCompTZNP1, typeMenuProg},
  { "��������� ����1",     (void*)&UprCompTZNP1, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompTZNP1(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_ust_compTZNP1);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UstListCompTZNP1()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compTZNP1);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompTZNP1);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompTZNP1()

void UstCompTZNP1()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compTZNP1);
  PassWord(EditUstTZNP1);
}//VidCompTZNP1()

void EditUstTZNP1()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compTZNP1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompTZNP1()

short  KadrMenuFormat_ustvidTZNP(void *pstr)
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

void PereinitVidListCompTZNP1(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidTZNP, sub_menu_vid_compTZNP1);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void VidListCompTZNP1()
{
  SelectorMNGBAZA(MNGVID_TZNP1to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_vid_compTZNP1);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitVidListCompTZNP1);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompTZNP1()

void VidCompTZNP1()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_vid_compTZNP1);
//  PassWord(EditVidAPV);
  EditVidTZNP1();
}//VidCompTZNP1()

void EditVidTZNP1()
{
//������������� �������
  SystemEditUst(sub_menu_vid_compTZNP1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompTZNP1(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compTZNP1, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstList

void UprListCompTZNP1()
{
  SelectorMNGBAZA(MNGUPR_TZNP1to5);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compTZNP1);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUprListCompTZNP1);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompNZOP1()

void UprCompTZNP1()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compTZNP1);
  PassWord(EditUprTZNP1);

}//UprCompTZNP1()

void EditUprTZNP1()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compTZNP1[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrTZNP1);//������������� ������� ����������
}//EditUprTZNP1()

short  KadrMenuFormat_upr_compTZNP1(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    char *nameUpr = (char *)sub_menu_upr_compTZNP1[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      //���������� ������� ���������� � �����
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrTZNP1(i, getCurrentMngUSTAVKI()));

      return 1;//�������� �������� ������
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
  //������� �������
  if (init)
  {
//������� ��������
    tmpUSTAVKI[MNGUST_TZNP1to5_3I0]   = 10;
    tmpUSTAVKI[MNGUST_TZNP1to5_3U0]   = 20;
//������� ��������
    tmpUSTAVKI[MNGVID_TZNP1to5]        = 40;
    tmpUSTAVKI[MNGVID_TZNP1to5_3I0]    = 41;
    tmpUSTAVKI[MNGVID_TZNP1to5_3U0]    = 42;
//���������
	//���� ����� ����1
    tmpUSTAVKI[MNGVUSK_TZNP1to5]       = 43;

	//����� ����1 ��
    tmpUSTAVKI[MNGUSK_TZNP1to5]        = 44;
	//����� ����1 ��
    tmpUSTAVKI[MNGUSK_TZNP1to5_OU]     = 45;
	//����� ����1 ��
    tmpUSTAVKI[MNGUSK_TZNP1to5_TU]     = 46;

	//����� ����1 3I0 ��
    tmpUSTAVKI[MNGUSK_TZNP1to5_3I0]    = 47;
	//����� ����1 3I0 ��
    tmpUSTAVKI[MNGUSK_TZNP1to5_3I0_OU] = 48;
	//����� ����1 3I0 ��
    tmpUSTAVKI[MNGUSK_TZNP1to5_3I0_TU] = 49;
//������� ����������
    tmpUSTAVKI[MNGUPR_TZNP1to5] = 0;

  }//if

  IndexUstSPV += SPVUST_TZNP1to5_TOTAL;//������ ������� � �����������
  return MNGUST_TZNP1to5_TOTAL;//�-�� ������� � ��������� �������
}//initUstMTZ1(short mngUst, char init)

void  prepareUstTZNP1(short idxC)
{
  //���������� ENA ������ ��� �����
  //���������� ENA �� WideENA � ENAcmd
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_TZNP1to5), ENACMD_TZNP1to5_TOTAL);
  //���������� �������
  int tmpOffsetUSpv = getOffsetSPVUstCnf(idxC);//�������� ������� ������ �����������

    //������� SPV �������� 3I0
    int tmp1 = 
    SPV_UST(SPVSRABUST_TZNP1to5_3I0) = codecUstTZNP1(1, MNGUST_TZNP1to5_3I0, getNativUstMngUSTAVKI(idxC, MNGUST_TZNP1to5_3I0));
    //������� SPV �������� 3I0
    SPV_UST(SPVVOZVUST_TZNP1to5_3I0) = tmp1 - tmp1/20;//5%

    //������� SPV �������� 3U0
    tmp1 = 
    SPV_UST(SPVSRABUST_TZNP1to5_3U0) = codecUstTZNP1(1, MNGUST_TZNP1to5_3U0, getNativUstMngUSTAVKI(idxC, MNGUST_TZNP1to5_3U0));
    //������� SPV �������� 3U0
    SPV_UST(SPVVOZVUST_TZNP1to5_3U0) = tmp1 - tmp1/20;//5%

  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //��������� � ������������

        //������ TZNP1to5_TIM1
  setTimerPorog(tmpOffsetT+ TIMER1_TZNP1to5, 
          codecUstTZNP1(1, MNGVID_TZNP1to5, getNativUstMngUSTAVKI(idxC, MNGVID_TZNP1to5)));
        //������ TZNP1to5_TIM2
  setTimerPorog(tmpOffsetT+ TIMER2_TZNP1to5,
          codecUstTZNP1(1, MNGVID_TZNP1to5_3I0, getNativUstMngUSTAVKI(idxC, MNGVID_TZNP1to5_3I0)));
         //������ TZNP1to5_TIM3
  setTimerPorog(tmpOffsetT+ TIMER3_TZNP1to5,
          codecUstTZNP1(1, MNGVID_TZNP1to5_3U0, getNativUstMngUSTAVKI(idxC, MNGVID_TZNP1to5_3U0)));

//���� ����� ����1
  setTimerPorog(tmpOffsetT+ TIMER_VUSK_TZNP1to5,
          codecUstTZNP1(1, MNGVUSK_TZNP1to5, getNativUstMngUSTAVKI(idxC, MNGVUSK_TZNP1to5)));

//����� ����1 ��
  int tmp =        codecUstTZNP1(1, MNGUSK_TZNP1to5, getNativUstMngUSTAVKI(idxC, MNGUSK_TZNP1to5));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER4_TZNP1to5, tmp);
//����� ����1 ��
  tmp =        codecUstTZNP1(1, MNGUSK_TZNP1to5_OU, getNativUstMngUSTAVKI(idxC, MNGUSK_TZNP1to5_OU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER4_TZNP1to5_OU, tmp);
//����� ����1 ��
  tmp =        codecUstTZNP1(1, MNGUSK_TZNP1to5_TU, getNativUstMngUSTAVKI(idxC, MNGUSK_TZNP1to5_TU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER4_TZNP1to5_TU, tmp);

//����� ����1 3I0 ��
  tmp =        codecUstTZNP1(1, MNGUSK_TZNP1to5_3I0, getNativUstMngUSTAVKI(idxC, MNGUSK_TZNP1to5_3I0));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER4_TZNP1to5_3I0, tmp);
//����� ����1 3I0 ��
  tmp =        codecUstTZNP1(1, MNGUSK_TZNP1to5_3I0_OU, getNativUstMngUSTAVKI(idxC, MNGUSK_TZNP1to5_3I0_OU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER4_TZNP1to5_3I0_OU, tmp);
//����� ����1 3I0 ��
  tmp =        codecUstTZNP1(1, MNGUSK_TZNP1to5_3I0_TU, getNativUstMngUSTAVKI(idxC, MNGUSK_TZNP1to5_3I0_TU));
  if(tmp==0) tmp=10;
  setTimerPorog(tmpOffsetT+ TIMER4_TZNP1to5_3I0_TU, tmp);

         //������ BO_TZNP1to5_TIM
  setTimerPorog(tmpOffsetT+ TIMER_BO_TZNP1to5, 10);
      //������ BO_TZNP1to5_3I0_TIM
  setTimerPorog(tmpOffsetT+ TIMER_BO_TZNP1to5_3I0, 10);
       //������ BO_TZNP1to5_3U0_TIM
  setTimerPorog(tmpOffsetT+ TIMER_BO_TZNP1to5_3U0, 10);
}//prepareUstTZNP1(short idxC)

int initIOCmd_TZNP1()
{
  //������� IO ������
  offsetIOCmdTZNP5 = IndexIO;//�������� ��� IO TZNP5
  return commonInitIOCmd(IOCMD_TZNP1to5_TOTAL);
}

int initTLCmd_TZNP1()
{
  //������� TL ������
  return commonInitTLCmd(TLCMD_TZNP1to5_TOTAL);
}//initTLCmd_TZNP1()

int initENACmd_TZNP1()
{
  //������� ENA ������
  return commonInitENACmd(ENACMD_TZNP1to5_TOTAL);
}//initENACmd_TZNP1()

void initTimersTZNP1(short idxC)
{
  //������ � ������� ��������
  commonInitTimers(TIMERS_TZNP1to5_TOTAL);
}//initTimersTZNP1()

int codecUstTZNP1(char codec, short offset, int ust)
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
   case MNGUST_TZNP1to5_3I0:
   case MNGUST_TZNP1to5_3U0:
       grzHI = 1000000;//���� �������
       grzLOW= 0;//��� �������
       step  = 1;//���
   break;

  //��������
//   case MNGUST_BOBV_TZNP1to5://������� �� ��
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
}//codecUstTZNP1(char *buf, short offset, int ust)

int isDISactiv_TZNP1to5(int idxC)
{
 //���������� ������������ ���
  return 0;//��� ����������
}//isDISactiv_TZNP1to5(int idxC)

char copyTZNP1ToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//������� ������
//���������� ��������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.packet = 0;    //����� ��������� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  TZNP1_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_TZNP1;//���� ����������

  rpzcomponent_obj.cntClon     = CNT_STUPEN_TZNP;   //max �-�� ������
  rpzcomponent_obj.numClon     = 1;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.twinControl = &(twinTZNP1[0]);//������ �������� ���������
  twinTZNP1[0].twin_different = diffTZNP2ToRepozitar;//�-��� �������� ���������
  twinTZNP1[1].twin_different = diffTZNP3ToRepozitar;//�-��� �������� ���������
  twinTZNP1[2].twin_different = diffTZNP4ToRepozitar;//�-��� �������� ���������
  twinTZNP1[3].twin_different = diffTZNP5ToRepozitar;//�-��� �������� ���������

  rpzcomponent_obj.initUstMng     = initUstTZNP1;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstTZNP1;//���������� �������
  rpzcomponent_obj.initIOCmd      = initIOCmd_TZNP1;      //������� IO ������
  rpzcomponent_obj.initTLCmd      = initTLCmd_TZNP1;      //������� TL ������
  rpzcomponent_obj.initENACmd     = initENACmd_TZNP1;     //������� ENA ������
  rpzcomponent_obj.bo_bvCmd       = NULL; //��������� �� �� ������
  rpzcomponent_obj.isDISactiv     = isDISactiv_TZNP1to5; //���������� ������������ ���
  rpzcomponent_obj.setBOBVtimer   = NULL; //������� �������� �� ��

  rpzcomponent_obj.nameStatusIO = ionsTZNP1;          //����� � ������ ������ IO
  rpzcomponent_obj.initTimers   = initTimersTZNP1;    //������ � ������� ��������
  rpzcomponent_obj.logic        = logicTZNP1to5;         //������ ����������

  rpzcomponent_obj.codecUst = codecUstTZNP1;   //����������-������������� �������

  return 0;//�� �������� �����������
}//

#endif // _HIDE_COMPONENT

