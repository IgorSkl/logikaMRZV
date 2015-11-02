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

//��� �����������
#define KOD_COMPONENT  DZ_COMP1
//�-�� ��������
#define CNT_STUPEN_DZ  5

#endif // _HIDE_COMPONENT

//������������� �������  � ��������� �������
//������� OF
#define MNGUST_DZ1_OX1  0
#define MNGUST_DZ1_OY1  1
#define MNGUST_DZ1_OX2  2
#define MNGUST_DZ1_OY2  3
#define MNGUST_DZ1_OX3  4
#define MNGUST_DZ1_OY3  5
#define MNGUST_DZ1_OX4  6
#define MNGUST_DZ1_OY4  7

//������� MF
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

//������� ��������
#define MNGVID_DZ1MF   17
#define MNGVID_MDZ1MF  18
#define MNGVID_DZ1OF   19

//������� ����������
#define MNGUPR_DZ1     20
//�-�� ������� � ��������� �������
#define MNGUST_DZ1_TOTAL  21
//#define MNGUST_BOBV_DZ1  MNGUST_DZ1_TOTAL

//������������� �������  ����������
//ENA_DZ1
#define ENA_DZ1_1  0
//ENA_MDZ1MF
#define ENA_DZ1_2  1
//�-�� ENA ������
#define ENACMD_DZ1_TOTAL 2

//������������� ������� � �����������
//������� ��������
#define SPVSRAB_DZ1_MTZ    0
//������� ��������
#define SPVVOZV_DZ1_MTZ    1

//������� SPV �����
#define SPV_OUTA_DZ1_MTZ   2          
#define SPV_OUTB_DZ1_MTZ   3
#define SPV_OUTC_DZ1_MTZ   4
//�-�� ������� � �����������
#define SPVUST_DZ1_TOTAL   5

//---------------IO COMMAND------------------
//������������� IO ������ ��� DZ1
//���� ���� ��1
#define IOCMD1_DZ1 0
//���� �� ��1��
#define IOCMD2_DZ1 1
//���� ��1��
#define IOCMD3_DZ1 2
//���� �� ��� ��1��
#define IOCMD4_DZ1 3
//���� ��� ��1��
#define IOCMD5_DZ1 4
//���� �� ��1��
#define IOCMD6_DZ1 5
//���� ��1��
#define IOCMD7_DZ1 6
//�-�� IO ������
#define IOCMD_DZ1_TOTAL   7

//---------------TL COMMAND------------------
//������������� TL ������ ��� DZ1
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

//�-�� TL ������
#define TLCMD_DZ1_TOTAL    8

//--------------- TIMERS ------------------
//������������� �������� ��� DZ1
//������ DZ1_TIM1
#define TIMER1_DZ1   0
//������ BO DZ1_TIM1
#define TIMER1_BODZ1 1
//������ DZ1_TIM2
#define TIMER2_DZ1   2
//������ BO DZ1_TIM2
#define TIMER2_BODZ1 3
//������ DZ1_TIM3
#define TIMER3_DZ1   4
//������ BO DZ1_TIM3
#define TIMER3_BODZ1 5
//�-�� ��������
#define TIMERS_DZ1_TOTAL   6

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "PRM1Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_DZ[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//������ ������� � �����������
extern int  IndexIO;//������ IO

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//������� ������� �����������
extern char *bitStringUNI[];
extern int offsetUstMngPRM1;//�������� �� ������� PRM1
extern int isTriangleZonaBD[];//���� �� �����������-���������������

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

int  offsetIOCmdDZ1;//�������� ��� IO DZ1
int isValidZonaDZ1OF;//���� ���������� ����
int isValidZonaDZ1MF;//���� ���������� ����

char DZ1_TITLE[] = "��1";

IONAMESTATUS_COMPONENT ionsDZ1[IOCMD_DZ1_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� ���� ��1"
  },
  {
    1,//������ iocmd2
    "���� �� ��1��"
  },
  {
    1,//������ iocmd3
    "���� ��1��"
  },
  {
    1,//������ iocmd4
    "���� �� ��� ��1��"
  },
  {
    1,//������ iocmd5
    "���� ��� ��1��"
  },
  {
    1,//������ iocmd6
    "���� �� ��1��"
  },
  {
    1,//������ iocmd7
    "���� ��1��"
  }
};

LineMenuItem sub_menu_comp_DZ1[8] =
{
  { DZ1_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_DZ, typeMenuSub},//control_item, parent
  { "������� ��1",    (void *)&UstListCompDZ1, typeMenuProg},
  { "�������� ��1",   (void *)&VidListCompDZ1, typeMenuProg},
  { "���������� ��1", (void *)&UprListCompDZ1, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compDZ1[] =
{
  { "������� ��1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_DZ1, typeMenuList},//control_item, parent
//  { "��� ��1",        (void *)&UstCompDZ1, typeMenuProg},
//  { "��� ��1 ������", (void *)&UstCompDZ1, typeMenuProg},
 // { "��� ��1 �����",  (void *)&UstCompDZ1, typeMenuProg},
//  { "��� ��1 ��",     (void *)&UstCompDZ1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compDZ1[] =
{
  { "�������� ��1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_DZ1, typeMenuList},//control_item, parent
//  { "�������� ��1��",     (void *)&VidCompDZ1, typeMenuProg},
//  { "�������� ��� ��1��", (void *)&VidCompDZ1, typeMenuProg},
//  { "�������� ��1��",     (void *)&VidCompDZ1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compDZ1[] =
{
  { "������ ��1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_DZ1, typeMenuList},//control_item, parent
//  { "������ ��1",        (void *)&UprCompDZ1, typeMenuProg},
//  { "������ ��� ��1",    (void *)&UprCompDZ1, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompDZ1(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidDZ, sub_menu_ust_compDZ1);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UstListCompDZ1()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compDZ1);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompDZ1);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompDZ1()

void UstCompDZ1()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compDZ1);
  PassWord(EditUstDZ1);
}//VidCompDZ1()

void EditUstDZ1()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compDZ1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompDZ1()

short  KadrMenuFormat_ustvidDZ(void *pstr)
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

void PereinitVidListCompDZ1(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidDZ, sub_menu_vid_compDZ1);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void VidListCompDZ1()
{
  SelectorMNGBAZA(MNGVID_DZ1MF);//��������� ���� �������

  SelectorSUBMENU(sub_menu_vid_compDZ1);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitVidListCompDZ1);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompDZ1()

void VidCompDZ1()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_vid_compDZ1);
//  PassWord(EditVidAPV);
  EditVidDZ1();
}//VidCompDZ1()

void EditVidDZ1()
{
//������������� �������
  SystemEditUst(sub_menu_vid_compDZ1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompDZ1(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compDZ1, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstList

void UprListCompDZ1()
{
  SelectorMNGBAZA(MNGUPR_DZ1);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compDZ1);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUprListCompDZ1);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompDZ1()

void UprCompDZ1()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compDZ1);
  PassWord(EditUprDZ1);

}//UprCompMTZ1()

void EditUprDZ1()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compDZ1[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrDZ1);//������������� ������� ����������
}//EditUprDZ1()

short  KadrMenuFormat_upr_compDZ1(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    char *nameUpr = (char *)sub_menu_upr_compDZ1[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      //���������� ������� ���������� � �����
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrDZ1(i, getCurrentMngUSTAVKI()));

      return 1;//�������� �������� ������
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
  //������� �������
  if (init)
  {
//������� ��������
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
//������� ��������
    tmpUSTAVKI[MNGVID_DZ1MF]  = 50;
    tmpUSTAVKI[MNGVID_MDZ1MF] = 60;
    tmpUSTAVKI[MNGVID_DZ1OF]  = 70;
//������� ����������
    tmpUSTAVKI[MNGUPR_DZ1] = 0;

  }//if

  IndexUstSPV += SPVUST_DZ1_TOTAL;//������ ������� � �����������
  return MNGUST_DZ1_TOTAL;//�-�� ������� � ��������� �������
}//initUstMTZ1(short mngUst, char init)

//���������� ������ ���� ��������
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
  //���������� ���� � �������� �� ����������
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
 //�������� ����������� ��� ���������������
 isTriangleZonaBD[0] = 0;//���� �� ���������������
 if(ustx3==ustx4 && usty3==usty4) isTriangleZonaBD[0] = 1;//���� �� �����������
 if(isTriangleZonaBD[0]) isValidZonaDZ1OF = isZonaTrianMethodVRT( 0);//���� ���������� ����
 else isValidZonaDZ1OF = isNewZonaMethodVRT( 0);//���� ���������� ����
 
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

 isTriangleZonaBD[1] = 0;//���� �� ���������������
 if(ustx3==ustx4 && usty3==usty4) isTriangleZonaBD[1] = 1;//���� �� �����������
 if(isTriangleZonaBD[1]) isValidZonaDZ1MF = isZonaTrianMethodVRT( 1);//���� ���������� ����
 else isValidZonaDZ1MF = isNewZonaMethodVRT( 1);//���� ���������� ����
 
  //���������� ENA ������ ��� �����
  //���������� ENA �� WideENA � ENAcmd
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_DZ1), ENACMD_DZ1_TOTAL);

  //���������� �������
    int tmpOffsetUSpv =
                cnfCOMPONENT[idxC].offsetUstSpv;    //������� SPV
    //������� SPV ��������
    int tmp1 = 
    SPV_UST(SPVSRAB_DZ1_MTZ) = codecUstDZ1(1, MNGUST_DZ1_MTZ, getNativUstMngUSTAVKI(idxC, MNGUST_DZ1_MTZ));
    //������� SPV ��������
    SPV_UST(SPVVOZV_DZ1_MTZ) = tmp1 - tmp1/20;//5%


  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //��������� � ������������

         //������ 1
   setTimerPorog(tmpOffsetT+ TIMER1_DZ1, 
          codecUstDZ1(1, MNGVID_DZ1MF, getNativUstMngUSTAVKI(idxC, MNGVID_DZ1MF)));

         //������ 2 BO
  setTimerPorog(tmpOffsetT+ TIMER1_BODZ1, 10);

        //������ 3
  setTimerPorog(tmpOffsetT+ TIMER2_DZ1, 
          codecUstDZ1(1, MNGVID_MDZ1MF, getNativUstMngUSTAVKI(idxC, MNGVID_MDZ1MF)));

        //������ 4 BO
  setTimerPorog(tmpOffsetT+ TIMER2_BODZ1, 10);

       //������ 5
  setTimerPorog(tmpOffsetT+ TIMER3_DZ1, 
          codecUstDZ1(1, MNGVID_DZ1OF, getNativUstMngUSTAVKI(idxC, MNGVID_DZ1OF)));

      //������ 6 BO
  setTimerPorog(tmpOffsetT+ TIMER3_BODZ1, 10);

}//prepareUstMTZ1(short idxC)

int initIOCmd_DZ1()
{
  //������� IO ������
  offsetIOCmdDZ1 = IndexIO;//�������� ��� IO DZ1
  return commonInitIOCmd(IOCMD_DZ1_TOTAL);
}

int initTLCmd_DZ1()
{
  //������� TL ������
  return commonInitTLCmd(TLCMD_DZ1_TOTAL);
}//initTLCmd_DZ1()

int initENACmd_DZ1()
{
  //������� ENA ������
  return commonInitENACmd(ENACMD_DZ1_TOTAL);
}//initENACmd_DZ1()

void initTimersDZ1(short idxC)
{
  //������ � ������� ��������
  commonInitTimers(TIMERS_DZ1_TOTAL);//������ ���� ������!

}//initTimersDZ1()

int codecUstDZ1(char codec, short offset, int ust)
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
   case MNGUST_DZ1_MTZ:
       grzHI = 1000000;//���� �������
       grzLOW= 0;//��� �������
       step  = 1;//���
   break;

   case MNGUST_DZ1_OX1:   case MNGUST_DZ1_OY1:
   case MNGUST_DZ1_OX2:   case MNGUST_DZ1_OY2:
   case MNGUST_DZ1_OX3:   case MNGUST_DZ1_OY3:
   case MNGUST_DZ1_OX4:   case MNGUST_DZ1_OY4:

   case MNGUST_DZ1_MX1:   case MNGUST_DZ1_MY1:
   case MNGUST_DZ1_MX2:   case MNGUST_DZ1_MY2:
   case MNGUST_DZ1_MX3:   case MNGUST_DZ1_MY3:
   case MNGUST_DZ1_MX4:   case MNGUST_DZ1_MY4:
       grzHI = 1000000;//���� �������
       grzLOW= -1000000;//��� �������
       step  = 1;//���
   break;

  //��������
   case MNGVID_DZ1MF:
   case MNGVID_MDZ1MF:
   case MNGVID_DZ1OF:
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
}//codecUstDZ1(char *buf, short offset, int ust)

int isDISactiv_DZ1(int idxC)
{
 //���������� ������������ ���
  return 0;//��� ����������
}//isDISactiv_DZ1(int idxC)

char copyDZ1ToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//������� ������
//���������� ��������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.packet = 0;    //����� ��������� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  DZ1_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_DZ1;//���� ����������

  rpzcomponent_obj.cntClon     = CNT_STUPEN_DZ;   //max �-�� ������
  rpzcomponent_obj.numClon     = 1;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstDZ1;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstDZ1;//���������� �������
  rpzcomponent_obj.initIOCmd      = initIOCmd_DZ1;      //������� IO ������
  rpzcomponent_obj.initTLCmd      = initTLCmd_DZ1;      //������� TL ������
  rpzcomponent_obj.initENACmd     = initENACmd_DZ1;     //������� ENA ������
  rpzcomponent_obj.bo_bvCmd       = NULL; //��������� �� �� ������
  rpzcomponent_obj.isDISactiv     = isDISactiv_DZ1; //���������� ������������ ���
  rpzcomponent_obj.setBOBVtimer   = NULL; //������� �������� �� ��

  rpzcomponent_obj.nameStatusIO = ionsDZ1;          //����� � ������ ������ IO
  rpzcomponent_obj.initTimers   = initTimersDZ1;    //������ � ������� ��������
  rpzcomponent_obj.logic        = logicDZ1;         //������ ����������

  rpzcomponent_obj.codecUst = codecUstDZ1;   //����������-������������� �������

  return 0;//�� �������� �����������
}//

#endif // _HIDE_COMPONENT

