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
#define KOD_COMPONENT  NZOP_COMP1
//�-�� ��������
#define CNT_STUPEN_NZOP  2

#endif // _HIDE_COMPONENT

//������������� �������  � ��������� �������
//������� ��������
#define MNGUST_UCM_NZOP1to2    0
#define MNGUST_UCM_NZOP1to2_V  1
#define MNGUST_UCM_NZOP1to2_N  2
#define MNGUST_ICM_NZOP1to2    3
#define MNGUST_ICM_NZOP1to2_V  4
#define MNGUST_ICM_NZOP1to2_N  5

//������� ��������
#define MNGVID_NZOP1to2    6
#define MNGVID_NZOP1to2_V  7
#define MNGVID_NZOP1to2_N  8

//������� ����������
#define MNGUPR_NZOP1to2    9
//�-�� ������� � ��������� �������
#define MNGUST_NZOP1to2_TOTAL  10
//#define MNGUST_BOBV_NZOP1to2  MNGUST_NZOP1to2_TOTAL

//������������� ENA ������
//�������\�������
#define ENA_NZOP1to2_1  0
//���\����
#define ENA_NZOP1to2_2  1
//������\�����
#define ENA_NZOP1to2_3  2
//�-�� ENA ������
#define ENACMD_NZOP1to2_TOTAL 3

//������������� ������� � �����������
//������� SPV ��������
#define SPVSRABUST_UCM_NZOP1to2    0
#define SPVSRABUST_UCM_NZOP1to2_V  1
#define SPVSRABUST_UCM_NZOP1to2_N  2
#define SPVSRABUST_ICM_NZOP1to2    3
#define SPVSRABUST_ICM_NZOP1to2_V  4
#define SPVSRABUST_ICM_NZOP1to2_N  5
//������� SPV ��������
#define SPVVOZVUST_UCM_NZOP1to2    6
#define SPVVOZVUST_UCM_NZOP1to2_V  7
#define SPVVOZVUST_UCM_NZOP1to2_N  8
#define SPVVOZVUST_ICM_NZOP1to2    9
#define SPVVOZVUST_ICM_NZOP1to2_V  10
#define SPVVOZVUST_ICM_NZOP1to2_N  11
//������� SPV �����
#define SPV_OUT_UCM_NZOP1to2       12
#define SPV_OUT_ICM_NZOP1to2       13
#define SPV_OUT_UCM_NZOP1to2_V     14
#define SPV_OUT_ICM_NZOP1to2_V     15
#define SPV_OUT_UCM_NZOP1to2_N     16
#define SPV_OUT_ICM_NZOP1to2_N     17
//�-�� ������� � �����������
#define SPVUST_NZOP1to2_TOTAL  18

//---------------IO COMMAND------------------
//������������� IO ������ ��� NZOP1to2
//���� ���� ����1
#define IOCMD1_NZOP1to2 0
//���� �� ����1
#define IOCMD2_NZOP1to2 1
//���� �� ����1 ���
#define IOCMD3_NZOP1to2 2
//���� �� ����1 ���
#define IOCMD4_NZOP1to2 3
//���� ����1
#define IOCMD5_NZOP1to2 4
//������ ����1 ���
#define IOCMD6_NZOP1to2 5
//������ ����1 ���
#define IOCMD7_NZOP1to2 6
//�-�� IO ������
#define IOCMD_NZOP1to2_TOTAL    7

//---------------TL COMMAND------------------
//������������� TL ������ ��� NZOP1to2
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
//�-�� TL ������
#define TLCMD_NZOP1to2_TOTAL    0

//--------------- TIMERS ------------------
//������������� �������� ��� NZOP1to2
//������ 0
#define TIMER1_NZOP1to2  0
//������ 1
#define TIMER2_NZOP1to2  1
//������ 2
#define TIMER3_NZOP1to2  2
//������ 3 BO
#define TIMER_BO_NZOP1to2 3
//�-�� ��������
#define TIMERS_NZOP1to2_TOTAL   4

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "PRM1Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_NZOP[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//������ ������� � �����������
extern int  IndexIO;//������ IO

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//������� ������� �����������
extern char *bitStringUNI[];
extern int offsetUstMngPRM1;//�������� �� ������� PRM1

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

TWIN_DIFFERENT twinNZOP1[1];//������ �������� ���������

int  offsetIOCmdNZOP2;//�������� ��� IO NZOP2

char NZOP1_TITLE[] = "����1";

IONAMESTATUS_COMPONENT ionsNZOP1[IOCMD_NZOP1to2_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� ���� ����1"
  },
  {
    1,//������ iocmd2
    "���� �� ����1"
  },
  {
    1,//������ iocmd3
    "���� �� ����1 ���"
  },
  {
    1,//������ iocmd4
    "���� �� ����1 ���"
  },
  {
    1,//������ iocmd5
    "���� ����1"
  },
  {
    1,//������ iocmd6
    "������ ����1 ���"
  },
  {
    1,//������ iocmd7
    "������ ����1 ���"
  }
};

LineMenuItem sub_menu_comp_NZOP1[8] =
{
  { NZOP1_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_NZOP, typeMenuSub},//control_item, parent
  { "������� ����1",    (void *)&UstListCompNZOP1, typeMenuProg},
  { "�������� ����1",   (void *)&VidListCompNZOP1, typeMenuProg},
  { "���������� ����1", (void *)&UprListCompNZOP1, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compNZOP1[] =
{
  { "������� ����1", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_NZOP1, typeMenuList},//control_item, parent
  { "��� ����1 U2",        (void *)&UstCompNZOP1, typeMenuProg},
  { "��� ����1 U2 ������", (void *)&UstCompNZOP1, typeMenuProg},
  { "��� ����1 U2 �����",  (void *)&UstCompNZOP1, typeMenuProg},
  { "��� ����1 I2",        (void *)&UstCompNZOP1, typeMenuProg},
  { "��� ����1 I2 ������", (void *)&UstCompNZOP1, typeMenuProg},
  { "��� ����1 I2 �����",  (void *)&UstCompNZOP1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compNZOP1[] =
{
  { "�������� ����1", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_NZOP1, typeMenuList},//control_item, parent
  { "�������� ����1",        (void *)&VidCompNZOP1, typeMenuProg},
  { "�������� ����1 ������", (void *)&VidCompNZOP1, typeMenuProg},
  { "�������� ����1 �����",  (void *)&VidCompNZOP1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compNZOP1[] =
{
  { "������ ����1", NULL},//title
  { &CONTROL2_COMP, sub_menu_comp_NZOP1, typeMenuList},//control_item, parent
  { "��� ����1",           (void *)&UprCompNZOP1, typeMenuProg},
  { "������ ����1",        (void *)&UprCompNZOP1, typeMenuProg},
  { "������� ����1",       (void *)&UprCompNZOP1, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompNZOP1(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidNZOP, sub_menu_ust_compNZOP1);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UstListCompNZOP1()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compNZOP1);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompNZOP1);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompNZOP1()

void UstCompNZOP1()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compNZOP1);
  PassWord(EditUstNZOP1);
}//VidCompNZOP1()

void EditUstNZOP1()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compNZOP1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompNZOP1()

short  KadrMenuFormat_ustvidNZOP(void *pstr)
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

void PereinitVidListCompNZOP1(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidNZOP, sub_menu_vid_compNZOP1);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void VidListCompNZOP1()
{
  SelectorMNGBAZA(MNGVID_NZOP1to2);//��������� ���� �������

  SelectorSUBMENU(sub_menu_vid_compNZOP1);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitVidListCompNZOP1);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompNZOP1()

void VidCompNZOP1()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_vid_compNZOP1);
//  PassWord(EditVidAPV);
  EditVidNZOP1();
}//VidCompNZOP1()

void EditVidNZOP1()
{
//������������� �������
  SystemEditUst(sub_menu_vid_compNZOP1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompNZOP1(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compNZOP1, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UprListCompNZOP1()
{
  SelectorMNGBAZA(MNGUPR_NZOP1to2);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compNZOP1);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUprListCompNZOP1);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompNZOP1()

void UprCompNZOP1()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compNZOP1);
  PassWord(EditUprNZOP1);

}//UprCompNZOP1()

void EditUprNZOP1()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compNZOP1[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrNZOP1);//������������� ������� ����������
}//EditUprNZOP1()

short  KadrMenuFormat_upr_compNZOP1(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    char *nameUpr = (char *)sub_menu_upr_compNZOP1[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      //���������� ������� ���������� � �����
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrNZOP1(i, getCurrentMngUSTAVKI()));

      return 1;//�������� �������� ������
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
  //������� �������
  if (init)
  {
//������� ��������
    tmpUSTAVKI[MNGUST_UCM_NZOP1to2]   = 221;
    tmpUSTAVKI[MNGUST_UCM_NZOP1to2_V] = 222;
    tmpUSTAVKI[MNGUST_UCM_NZOP1to2_N] = 223;
    tmpUSTAVKI[MNGUST_ICM_NZOP1to2]   = 224;
    tmpUSTAVKI[MNGUST_ICM_NZOP1to2_V] = 225;
    tmpUSTAVKI[MNGUST_ICM_NZOP1to2_N] = 226;
//������� ��������
    tmpUSTAVKI[MNGVID_NZOP1to2]   = 230;
    tmpUSTAVKI[MNGVID_NZOP1to2_V] = 231;
    tmpUSTAVKI[MNGVID_NZOP1to2_N] = 232;
//������� ����������
    tmpUSTAVKI[MNGUPR_NZOP1to2] = 0;

  }//if

  IndexUstSPV += SPVUST_NZOP1to2_TOTAL;//������ ������� � �����������
  return MNGUST_NZOP1to2_TOTAL;//�-�� ������� � ��������� �������
}//initUstNZOP1(short mngUst, char init)

void  prepareUstNZOP1(short idxC)
{
  //���������� ENA ������ ��� �����
  //���������� ENA �� WideENA � ENAcmd
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_NZOP1to2), ENACMD_NZOP1to2_TOTAL);
  //���������� �������
  int tmpOffsetUSpv = getOffsetSPVUstCnf(idxC);//�������� ������� ������ �����������

  //������� SPV ��������
  int tmp1 =
    SPV_UST(SPVSRABUST_UCM_NZOP1to2) = codecUstNZOP1(1, MNGUST_UCM_NZOP1to2, getNativUstMngUSTAVKI(idxC, MNGUST_UCM_NZOP1to2));
  //������� SPV ��������
  SPV_UST(SPVVOZVUST_UCM_NZOP1to2) = tmp1 - tmp1/20;//5%

  //������� SPV ��������
  tmp1 =
    SPV_UST(SPVSRABUST_UCM_NZOP1to2_V) = codecUstNZOP1(1, MNGUST_UCM_NZOP1to2_V, getNativUstMngUSTAVKI(idxC, MNGUST_UCM_NZOP1to2_V));
  //������� SPV ��������
  SPV_UST(SPVVOZVUST_UCM_NZOP1to2_V) = tmp1 - tmp1/20;//5%

  //������� SPV ��������
  tmp1 =
    SPV_UST(SPVSRABUST_UCM_NZOP1to2_N) = codecUstNZOP1(1, MNGUST_UCM_NZOP1to2_N, getNativUstMngUSTAVKI(idxC, MNGUST_UCM_NZOP1to2_N));
  //������� SPV ��������
  SPV_UST(SPVVOZVUST_UCM_NZOP1to2_N) = tmp1 - tmp1/20;//5%

//------------------NZD---------------------------------------------------------
  //������� SPV ��������
  tmp1 =
    SPV_UST(SPVSRABUST_ICM_NZOP1to2) = codecUstNZOP1(1, MNGUST_ICM_NZOP1to2, getNativUstMngUSTAVKI(idxC, MNGUST_ICM_NZOP1to2));
  //������� SPV ��������
  SPV_UST(SPVVOZVUST_ICM_NZOP1to2) = tmp1 - tmp1/20;//5%

  //������� SPV ��������
  tmp1 =
    SPV_UST(SPVSRABUST_ICM_NZOP1to2_V) = codecUstNZOP1(1, MNGUST_ICM_NZOP1to2_V, getNativUstMngUSTAVKI(idxC, MNGUST_ICM_NZOP1to2_V));
  //������� SPV ��������
  SPV_UST(SPVVOZVUST_ICM_NZOP1to2_V) = tmp1 - tmp1/20;//5%

  //������� SPV ��������
  tmp1 =
    SPV_UST(SPVSRABUST_ICM_NZOP1to2_N) = codecUstNZOP1(1, MNGUST_ICM_NZOP1to2_N, getNativUstMngUSTAVKI(idxC, MNGUST_ICM_NZOP1to2_N));
  //������� SPV ��������
  SPV_UST(SPVVOZVUST_ICM_NZOP1to2_N) = tmp1 - tmp1/20;//5%

  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //��������� � ������������

         //������ 1
  setTimerPorog(tmpOffsetT+ TIMER1_NZOP1to2, 
    codecUstNZOP1(1, MNGVID_NZOP1to2, getNativUstMngUSTAVKI(idxC, MNGVID_NZOP1to2)));

          //������ 2
  setTimerPorog(tmpOffsetT+ TIMER2_NZOP1to2, 
    codecUstNZOP1(1, MNGVID_NZOP1to2_V, getNativUstMngUSTAVKI(idxC, MNGVID_NZOP1to2_V)));

          //������ 3
  setTimerPorog(tmpOffsetT+ TIMER3_NZOP1to2, 
    codecUstNZOP1(1, MNGVID_NZOP1to2_N, getNativUstMngUSTAVKI(idxC, MNGVID_NZOP1to2_N)));

         //������ 4 BO
  setTimerPorog(tmpOffsetT+ TIMER_BO_NZOP1to2, 10);


}//prepareUstNZOP1(short idxC)

int initIOCmd_NZOP1()
{
  //������� IO ������
  offsetIOCmdNZOP2 = IndexIO;//�������� ��� IO NZOP2
  return commonInitIOCmd(IOCMD_NZOP1to2_TOTAL);
}

int initTLCmd_NZOP1()
{
  //������� TL ������
  return commonInitTLCmd(TLCMD_NZOP1to2_TOTAL);
}//initTLCmd_NZOP1()

int initENACmd_NZOP1()
{
  //������� ENA ������
  return commonInitENACmd(ENACMD_NZOP1to2_TOTAL);
}//initENACmd_NZOP1()

void initTimersNZOP1(short idxC)
{
  //������ � ������� ��������
  commonInitTimers(TIMERS_NZOP1to2_TOTAL);
}//initTimersNZOP1()

int codecUstNZOP1(char codec, short offset, int ust)
//codec=0-����������
//codec=1-�������������
{
  //����������-������������� �������
  //����������-������������� �������
  int grzHI = 0;//���� �������
  int grzLOW= 0;//��� �������
  int step  = 1;//���
  switch(offset)
  {
    //�������
  case MNGUST_UCM_NZOP1to2:
  case MNGUST_UCM_NZOP1to2_V:
  case MNGUST_UCM_NZOP1to2_N:
  case MNGUST_ICM_NZOP1to2:
  case MNGUST_ICM_NZOP1to2_V:
  case MNGUST_ICM_NZOP1to2_N:
    grzHI = 1000000;//���� �������
    grzLOW= 0;//��� �������
    step  = 1;//���
    break;

    //��������
//  case MNGUST_BOBV_NZOP1to2://������� �� ��
  case MNGVID_NZOP1to2:
  case MNGVID_NZOP1to2_V:
  case MNGVID_NZOP1to2_N:
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
}//codecUstNZOP1(char *buf, short offset, int ust)

int isDISactiv_NZOP1to2(int idxC)
{
//���������� ������������ ���
  return 0;//��� ����������
}//isDISactiv_NZOP1to2(int idxC)

char copyNZOP1ToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//������� ������
//���������� ��������� 1 � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  NZOP1_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_NZOP1;//sub_menu_component;

  rpzcomponent_obj.twinControl = &(twinNZOP1[0]);//������ �������� ���������
  twinNZOP1[0].twin_different = diffNZOP2ToRepozitar;//�-��� �������� ���������

  rpzcomponent_obj.cntClon     = CNT_STUPEN_NZOP;   //max �-�� ������
  rpzcomponent_obj.numClon     = 1;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstNZOP1;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstNZOP1;//���������� �������
  rpzcomponent_obj.initIOCmd      = initIOCmd_NZOP1;      //������� IO ������
  rpzcomponent_obj.initTLCmd      = initTLCmd_NZOP1;      //������� TL ������
  rpzcomponent_obj.initENACmd     = initENACmd_NZOP1;     //������� ENA ������
  rpzcomponent_obj.bo_bvCmd       = NULL; //��������� �� �� ������
  rpzcomponent_obj.isDISactiv     = isDISactiv_NZOP1to2; //���������� ������������ ���
  rpzcomponent_obj.setBOBVtimer   = NULL; //������� �������� �� ��

  rpzcomponent_obj.nameStatusIO = ionsNZOP1;          //����� � ������ ������ IO
  rpzcomponent_obj.initTimers   = initTimersNZOP1;    //������ � ������� ��������
  rpzcomponent_obj.logic        = logicNZOP1to2;         //������ ����������

  rpzcomponent_obj.codecUst = codecUstNZOP1;   //����������-������������� �������

  return 0;//�� �������� �����������
}//

#endif // _HIDE_COMPONENT

