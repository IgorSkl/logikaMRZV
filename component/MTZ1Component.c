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

//��� ���������a
#define KOD_COMPONENT  MTZ_COMP1
//�-�� ��������
#define CNT_STUPEN_MTZ  5

#endif // _HIDE_COMPONENT

//---------------MANAGER UST------------------
//������������� �������  � ��������� �������
//������� ��������
#define MNGUST_MTZ1     0
#define MNGUST_MTZ1_V   1
#define MNGUST_MTZ1_N   2
#define MNGUST_MTZ1_PN  3
#define MNGUST_MTZ1_UPN 4

//������� ��������
#define MNGVID_MTZ1    5
#define MNGVID_MTZ1_V  6
#define MNGVID_MTZ1_N  7
#define MNGVID_MTZ1_PN 8

//������� ����������
#define MNGUPR_MTZ1    9
//�-�� ������� � ��������� �������
#define MNGUST_MTZ1_TOTAL  10
//#define MNGUST_BOBV_MTZ1  MNGUST_MTZ1_TOTAL

//������������� ENA ������
#define ENA_MTZ1_HALF1  0
#define ENA_MTZ1_HALF2  1
#define ENA_MTZ1_1      2
#define ENA_MTZ1_2      3
#define ENA_MTZ1_3      4
//�-�� ENA ������
#define ENACMD_MTZ1_TOTAL 5

//������������� ������� � �����������
//������� SPV ��������
#define SPVSRABUST_MTZ1     0
#define SPVSRABUST_MTZ1_V   1
#define SPVSRABUST_MTZ1_N   2
#define SPVSRABUST_MTZ1_PN  3
#define SPVSRABUST_MTZ1_UPN 4
//������� SPV ��������
#define SPVVOZVUST_MTZ1     5
#define SPVVOZVUST_MTZ1_V   6
#define SPVVOZVUST_MTZ1_N   7
#define SPVVOZVUST_MTZ1_PN  8
#define SPVVOZVUST_MTZ1_UPN 9
//������� SPV �����
#define SPV_OUTA_MTZ1      10
#define SPV_OUTB_MTZ1      11
#define SPV_OUTC_MTZ1      12

#define SPV_OUTA_MTZ1_V    13
#define SPV_OUTB_MTZ1_V    14
#define SPV_OUTC_MTZ1_V    15

#define SPV_OUTA_MTZ1_N    16
#define SPV_OUTB_MTZ1_N    17
#define SPV_OUTC_MTZ1_N    18

#define SPV_OUTA_MTZ1_PN   19
#define SPV_OUTB_MTZ1_PN   20
#define SPV_OUTC_MTZ1_PN   21

#define SPV_OUTA_MTZ1_UPN  22
#define SPV_OUTB_MTZ1_UPN  23
#define SPV_OUTC_MTZ1_UPN  24
//�-�� ������� SPV � �����������
#define SPVUST_MTZ1_TOTAL  25

//---------------IO COMMAND------------------
//������������� IO ������ ��� MTZ1
//���� ���� ���1
#define IOCMD1_MTZ1 0
//���� �� ���1
#define IOCMD2_MTZ1 1
//���� �� ���1 ���
#define IOCMD3_MTZ1 2
//���� �� ���1 ���
#define IOCMD4_MTZ1 3
//���� �� ���1 ��
#define IOCMD5_MTZ1 4
//���� ���1
#define IOCMD6_MTZ1 5
//������ ���1 ���
#define IOCMD7_MTZ1 6
//������ ���1 ���
#define IOCMD8_MTZ1 7
//�-�� IO ������
#define IOCMD_MTZ1_TOTAL    8

//---------------TL COMMAND------------------
//������������� TL ������ ��� MTZ1
//MTZ1_PO2
#define TLCMD1_MTZ1  0
//MTZ1_PO3
#define TLCMD2_MTZ1  1
//MTZ1_PO4
#define TLCMD3_MTZ1  2
//isFAILU_INVERT
//#define TLCMDFU_MTZ1  3
//ELOLDTRG_NCN_MTZ1
#define TLCMDOLDNCN_MTZ1 4
//ELOUTTRG_NCN_MTZ1
#define TLCMDOUTNCN_MTZ1 5
//�-�� TL ������
#define TLCMD_MTZ1_TOTAL 6

//--------------- TIMERS ------------------
//������������� �������� ��� MTZ1
//������ 0
#define TIMER1_MTZ1   0
//������ 1
#define TIMER2_MTZ1   1
//������ 2
#define TIMER3_MTZ1   2
//������ 3
#define TIMER4_MTZ1   3
//������ 4 BO
#define TIMER_BO_MTZ1 4
//�-�� ��������
#define TIMERS_MTZ1_TOTAL   5

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "PRM1Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������
extern int  tmpUSTAVKI[];
extern int  spvUSTAVKI[];//������� ������� �����������

extern LineMenuItem sub_menu_MTZ[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//������ ������� � �����������
extern int  IndexIO;//������ IO

extern COMPONENT_OBJ  cnfCOMPONENT[];//������������
extern char *bitStringUNI[];
extern int offsetUstMngPRM1;//�������� �� ������� PRM1

void PereinitUstListCompMTZ1(short flg);
void UstListCompMTZ1();
void ustRedactorCompMTZ1();
void UstCompMTZ1();

void PereinitVidListCompMTZ1(short flg);
void VidListCompMTZ1();
void vidRedactorCompMTZ1();
void VidCompMTZ1();

void PereinitUprListCompMTZ1(short flg);
void UprListCompMTZ1();
void uprRedactorCompMTZ1();
void UprCompMTZ1();
short  KadrMenuFormat_upr_compMTZ1(void *workCntr);
int  initUstMTZ1(char init);
void  prepareUstMTZ1(short idxC);
void UpravlRedactorChooseMTZ(char *nameUpr, short ibit);

short  KadrMenuFormat_MTZ1(void *workCntr);

void EditUstMTZ1();
void EditVidMTZ1();
void EditUprMTZ1();
int codecUstMTZ1(char codec, short offset, int ust);
short  KadrMenuFormat_ustvidMTZ(void *workCntr);
short chooseTxtMTZ(char *locTxt, short ibit, UNS_32 ust);
char *selectorUprStrMTZ1(short iBit, UNS_32 ustUpr);
void UpravlChooserMTZInKadr(char *nameUpr, short ibit, void *workCntr);
void  logicMTZ1(int idxC);
int   isDISactiv_MTZ1(int idxC);

int  offsetIOCmdMTZ1;//�������� ��� IO MTZ1

char MTZ1_TITLE[] = "���1";

IONAMESTATUS_COMPONENT ionsMTZ1[IOCMD_MTZ1_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� ���� ���1"
  },
  {
    1,//������ iocmd2
    "���� �� ���1"
  },
  {
    1,//������ iocmd3
    "���� �� ���1 ���"
  },
  {
    1,//������ iocmd4
    "���� �� ���1 ���"
  },
  {
    1,//������ iocmd5
    "���� �� ���1 ��"
  },
  {
    1,//������ iocmd6
    "���� ���1"
  },
  {
    1,//������ iocmd7
    "������ ���1 ���"
  },
  {
    1,//������ iocmd8
    "������ ���1 ���"
  }
};

LineMenuItem sub_menu_comp_MTZ1[8] =
{
  { MTZ1_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_MTZ, typeMenuSub},//control_item, parent
  { "������� ���1",    (void *)&UstListCompMTZ1, typeMenuProg},
  { "�������� ���1",   (void *)&VidListCompMTZ1, typeMenuProg},
  { "���������� ���1", (void *)&UprListCompMTZ1, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compMTZ1[] =
{
  { "������� ���1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_MTZ1, typeMenuList},//control_item, parent
  { "��� ���1",         (void *)&UstCompMTZ1, typeMenuProg},
  { "��� ���1 ������",  (void *)&UstCompMTZ1, typeMenuProg},
  { "��� ���1 �����",   (void *)&UstCompMTZ1, typeMenuProg},
  { "��� ���1 �H",      (void *)&UstCompMTZ1, typeMenuProg},
  { "��� ���� ���1 �H", (void *)&UstCompMTZ1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compMTZ1[] =
{
  { "�������� ���1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_MTZ1, typeMenuList},//control_item, parent
  { "�������� ���1",        (void *)&VidCompMTZ1, typeMenuProg},
  { "�������� ���1 ������", (void *)&VidCompMTZ1, typeMenuProg},
  { "�������� ���1 �����",  (void *)&VidCompMTZ1, typeMenuProg},
  { "�������� ���1 �H",     (void *)&VidCompMTZ1, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compMTZ1[] =
{
  { "������ ���1", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_MTZ1, typeMenuList},//control_item, parent
  { "��� ���1",           (void *)&UprCompMTZ1, typeMenuProg},
  { "������ ���1",        (void *)&UprCompMTZ1, typeMenuProg},
  { "���1 ������",        (void *)&UprCompMTZ1, typeMenuProg},
  { "���1 �����",         (void *)&UprCompMTZ1, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompMTZ1(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_ust_compMTZ1);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UstListCompMTZ1()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compMTZ1);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompMTZ1);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompMTZ1()

void UstCompMTZ1()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compMTZ1);
  PassWord(EditUstMTZ1);
}//VidCompMTZ1()

void EditUstMTZ1()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compMTZ1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompMTZ1()

short  KadrMenuFormat_ustvidMTZ(void *pstr)
{
  WorkControl *workCntr  = (WorkControl *)pstr;
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

void PereinitVidListCompMTZ1(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidMTZ, sub_menu_vid_compMTZ1);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void VidListCompMTZ1()
{
  SelectorMNGBAZA(MNGVID_MTZ1);//��������� ���� �������

  SelectorSUBMENU(sub_menu_vid_compMTZ1);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitVidListCompMTZ1);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ1()

void VidCompMTZ1()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_vid_compMTZ1);
//  PassWord(EditVidAPV);
  EditVidMTZ1();
}//VidCompMTZ1()

void EditVidMTZ1()
{
//������������� �������
  SystemEditUst(sub_menu_vid_compMTZ1);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

//--------------------------------------------------

void PereinitUprListCompMTZ1(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compMTZ1, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UprListCompMTZ1()
{
  SelectorMNGBAZA(MNGUPR_MTZ1);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compMTZ1);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUprListCompMTZ1);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompMTZ1()

void UprCompMTZ1()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compMTZ1);
  PassWord(EditUprMTZ1);
}//VidCompMTZ1()

void EditUprMTZ1()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compMTZ1[LIGHTLINEMENU +1+SUBDATA].Line1;

  switch(LIGHTLINEMENU)
  {
    case 0: UpravlRedactorChooseMTZ(nameUpr, LIGHTLINEMENU);//������������� ������� ����������
    break;
    default:UpravlRedactor(nameUpr, LIGHTLINEMENU+1, &selectorUprStrMTZ1);//������������� ������� ����������
  }//switch

}//EditVidMTZ1()

void UpravlRedactorChooseMTZ(char *nameUpr, short ibit)
{
//������������� ������� ����������
//  CRR_SUBMENU = sub_menu_tmp;//������� �������
//  ResetAllButton();//�������� ��� �������
/*
  FvmenuDis->EditChooseMTZPanel->Visible = true;

  char locTxt[50];
  switch(chooseTxtMTZ(locTxt, ibit, getCurrentMngUSTAVKI()))
  {
  case 0:
    FvmenuDis->Choose1MTZButton->Checked = true;
    FvmenuDis->Choose2MTZButton->Checked = false;
    FvmenuDis->Choose3MTZButton->Checked = false;
    FvmenuDis->Choose4MTZButton->Checked = false;
    break;
  case 1:
    FvmenuDis->Choose1MTZButton->Checked = false;
    FvmenuDis->Choose2MTZButton->Checked = true;
    FvmenuDis->Choose3MTZButton->Checked = false;
    FvmenuDis->Choose4MTZButton->Checked = false;
    break;
  case 2:
    FvmenuDis->Choose1MTZButton->Checked = false;
    FvmenuDis->Choose2MTZButton->Checked = false;
    FvmenuDis->Choose3MTZButton->Checked = true;
    FvmenuDis->Choose4MTZButton->Checked = false;
    break;
  case 3:
    FvmenuDis->Choose1MTZButton->Checked = false;
    FvmenuDis->Choose2MTZButton->Checked = false;
    FvmenuDis->Choose3MTZButton->Checked = false;
    FvmenuDis->Choose4MTZButton->Checked = true;
    break;
  }//switch

  FvmenuDis->Str1Label->Caption = nameUpr;
  FvmenuDis->Str2Label->Caption = locTxt;
  FvmenuDis->Str3Label->Caption = "";
  FvmenuDis->Str4Label->Caption = "";
  */
}//UpravlRedactorMTZ(char *nameUpr)

short  KadrMenuFormat_upr_compMTZ1(void *pstr)
{
  WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  short chooseBit = 2;//�-�� ��� � choose
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    char *nameUpr = (char *)sub_menu_upr_compMTZ1[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      if(i<(chooseBit-1))
        UpravlChooserMTZInKadr(nameUpr, i, workCntr);
      else
        //���������� ������� ���������� � �����
        strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
        selectorUprStrMTZ1(i+(chooseBit-1), getCurrentMngUSTAVKI()));

      return 1;//�������� �������� ������
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compMTZ1(WorkControl *workCntr)

char *selectorUprStrMTZ1(short iBit, UNS_32 ustUpr)
{
  switch(iBit)
  {

  default:;
  }//switch
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_WKL];
    return bitStringUNI[UNIUPR_OTKL];
}//selectorUprStrMTZ1(short ibit, UNS_32 ustUpr)

short chooseTxtMTZ(char *locTxt, short ibit, UNS_32 ust)
{
//���������� ������� ������-���������� � �����
  switch(NumBitCheckWord(ibit, &ust) + NumBitCheckWord(ibit+1, &ust)*2)
  {
  case 0:
    strcpy(locTxt, "�������");
    return 0;
  case 1:
    strcpy(locTxt, "������������");
    return 1;
  case 2:
    strcpy(locTxt, "���� �� ����");
    return 2;
  case 3:
    strcpy(locTxt, "Choose 3");
    return 3;
  }//switch
  return -1;
}//

//choose
void UpravlChooserMTZInKadr(char *nameUpr, short ibit, void *pstr)
{
  WorkControl *workCntr = (WorkControl *)pstr;
//���������� ������� ������-���������� � �����
  char locTxt[50];
  chooseTxtMTZ(locTxt, ibit, getCurrentMngUSTAVKI());//���������� ������� ������-���������� � �����
  strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, locTxt);
}//UpravlViewerInKadr(char *nameUpr, WorkControl *workCntr)

int initUstMTZ1(char init)
{
  //������� �������
  if (init)
  {
//������� ��������
    tmpUSTAVKI[MNGUST_MTZ1]     = 100;
    tmpUSTAVKI[MNGUST_MTZ1_V]   = 110;
    tmpUSTAVKI[MNGUST_MTZ1_N]   = 120;
    tmpUSTAVKI[MNGUST_MTZ1_PN]  = 130;
    tmpUSTAVKI[MNGUST_MTZ1_UPN] = 131;
//������� ��������
    tmpUSTAVKI[MNGVID_MTZ1]    = 15;
    tmpUSTAVKI[MNGVID_MTZ1_V]  = 16;
    tmpUSTAVKI[MNGVID_MTZ1_N]  = 17;
    tmpUSTAVKI[MNGVID_MTZ1_PN] = 18;
//������� ����������
    tmpUSTAVKI[MNGUPR_MTZ1] = 0;

  }//if

  IndexUstSPV += SPVUST_MTZ1_TOTAL;//������ ������� � �����������
  return MNGUST_MTZ1_TOTAL;//�-�� ������� � ��������� �������
}//initUstMTZ1(short mngUst, char init)

void  prepareUstMTZ1(short idxC)
{
  //���������� ENA ������ ��� ����� idxC
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_MTZ1), ENACMD_MTZ1_TOTAL);
  //���������� �������
  int tmpOffsetUSpv = getOffsetSPVUstCnf(idxC);//�������� ������� ������ �����������

    //������� SPV ��������
    int tmp1 = 
    SPV_UST(SPVSRABUST_MTZ1) = codecUstMTZ1(1, MNGUST_MTZ1, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ1));
    //������� SPV ��������
    SPV_UST(SPVVOZVUST_MTZ1) = tmp1 - tmp1/20;//5%

    //������� SPV ��������
        tmp1 = 
    SPV_UST(SPVSRABUST_MTZ1_V) = codecUstMTZ1(1, MNGUST_MTZ1_V, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ1_V));
    //������� SPV ��������
    SPV_UST(SPVVOZVUST_MTZ1_V) = tmp1 - tmp1/20;//5%

    //������� SPV ��������
        tmp1 = 
    SPV_UST(SPVSRABUST_MTZ1_N) = codecUstMTZ1(1, MNGUST_MTZ1_N, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ1_N));
    //������� SPV ��������
    SPV_UST(SPVVOZVUST_MTZ1_N) = tmp1 - tmp1/20;//5%

    //������� SPV ��������
        tmp1 =
    SPV_UST(SPVSRABUST_MTZ1_PN) = codecUstMTZ1(1, MNGUST_MTZ1_PN, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ1_PN));
    //������� SPV ��������
    SPV_UST(SPVVOZVUST_MTZ1_PN) = tmp1 - tmp1/20;//5%

    //������� SPV �������� DOWN
        tmp1 =
    SPV_UST(SPVSRABUST_MTZ1_UPN) = codecUstMTZ1(1, MNGUST_MTZ1_UPN, getNativUstMngUSTAVKI(idxC, MNGUST_MTZ1_UPN));
    //������� SPV ��������
    SPV_UST(SPVVOZVUST_MTZ1_UPN) = tmp1 + tmp1/20;//DOWN 5%

  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //��������� � ������������

          //������ 1
   setTimerPorog(tmpOffsetT+ TIMER1_MTZ1, 
          codecUstMTZ1(1, MNGVID_MTZ1, getNativUstMngUSTAVKI(idxC, MNGVID_MTZ1)));

          //������ 2
   setTimerPorog(tmpOffsetT+ TIMER2_MTZ1,
          codecUstMTZ1(1, MNGVID_MTZ1_V, getNativUstMngUSTAVKI(idxC, MNGVID_MTZ1_V)));

          //������ 3
   setTimerPorog(tmpOffsetT+ TIMER3_MTZ1, 
          codecUstMTZ1(1, MNGVID_MTZ1_N, getNativUstMngUSTAVKI(idxC, MNGVID_MTZ1_N)));

          //������ 4
   setTimerPorog(tmpOffsetT+ TIMER4_MTZ1, 
          codecUstMTZ1(1, MNGVID_MTZ1_PN, getNativUstMngUSTAVKI(idxC, MNGVID_MTZ1_PN)));

         //������ 5 BO
   setTimerPorog(tmpOffsetT+ TIMER_BO_MTZ1, 10);

}//prepareUstMTZ1(short idxC)

int initIOCmd_MTZ1()
{
  //������� IO ������
  offsetIOCmdMTZ1 = IndexIO;//�������� ��� IO MTZ1
  return commonInitIOCmd(IOCMD_MTZ1_TOTAL);
}

int initTLCmd_MTZ1()
{
  //������� TL ������
  return commonInitTLCmd(TLCMD_MTZ1_TOTAL);
}//initTLCmd_MTZ1()

int initENACmd_MTZ1()
{
  //������� ENA ������
  return commonInitENACmd(ENACMD_MTZ1_TOTAL);
}//initENACmd_MTZ1()

void initTimersMTZ1(short idxC)
{
  //������ � ������� ��������
  commonInitTimers(TIMERS_MTZ1_TOTAL);//������ ���� ������!
}//initTimersMTZ1()

int codecUstMTZ1(char codec, short offset, int ust)
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
   case MNGUST_MTZ1:
   case MNGUST_MTZ1_V:
   case MNGUST_MTZ1_N:
   case MNGUST_MTZ1_PN:
   case MNGUST_MTZ1_UPN:
       grzHI = 1000000;//���� �������
       grzLOW= 0;//��� �������
       step  = 1;//���
   break;

  //��������
//   case MNGUST_BOBV_MTZ1://������� �� ��
   case MNGVID_MTZ1:
   case MNGVID_MTZ1_V:
   case MNGVID_MTZ1_N:
   case MNGVID_MTZ1_PN:
       grzHI = 2000000;//���� �������
       grzLOW= 0;//��� �������
       step  = 1;//���
   break;

   default:return ust;//������� ����������
  }//switch

//  if((MNGUPR_MTZ1)==offset)
//    return ust;//������� ����������
  if(codec) return ust*step;
//������������� �������
  if(ust<grzLOW) return ERROR_UST;//-ust;
  if(ust>grzHI)  return ERROR_UST;//-ust;
  return ust/step;
}//codecUstMTZ1(char *buf, short offset, int ust)

int isDISactiv_MTZ1(int idxC)
{
 //��������� ���������� ������������ ���
    int tmpOffsetT    =
                cnfCOMPONENT[idxC].offsetTimers;   //������� ���������� � ������������
    for(int i=0; i<TIMERS_MTZ1_TOTAL; i++)
    {
      if(getTimerBUSY(tmpOffsetT+i) |
         getTimerFINISH(tmpOffsetT+i)
         )
         return 1;//���� ����������
    }//
  return 0;//��� ����������
}//isDISactiv_MTZ1(int idxC)

void SaveUprMTZ(short ibit)
{
  /*
//������������ ���� upr ��� MTZ
  UNS_32 tmpU = getCurrentMngUSTAVKI();//������� ��� ���
    //���������� ���
    if(ibit<1)
    {
      if(FvmenuDis->Choose1MTZButton->Checked)
      {
        NumBitClearingWord(ibit,   &tmpU);//����� ���� �� ��� �������
        NumBitClearingWord(ibit+1, &tmpU);//����� ���� �� ��� �������
      }//if
      if(FvmenuDis->Choose2MTZButton->Checked)
      {
        NumBitSettingWord(ibit,    &tmpU);//����� ���� �� ��� �������
        NumBitClearingWord(ibit+1, &tmpU);//����� ���� �� ��� �������
      }//if
      if(FvmenuDis->Choose3MTZButton->Checked)
      {
        NumBitClearingWord(ibit, &tmpU);//����� ���� �� ��� �������
        NumBitSettingWord(ibit+1,    &tmpU);//����� ���� �� ��� �������
      }//if
      if(FvmenuDis->Choose4MTZButton->Checked)
      {
        NumBitSettingWord(ibit, &tmpU);//����� ���� �� ��� �������
        NumBitSettingWord(ibit+1,    &tmpU);//����� ���� �� ��� �������
      }//if
    }//
    else
    {
      if(FvmenuDis->UprCheck->Checked)
      {
        NumBitSettingWord(ibit+1, &tmpU);//��������� ���� �� ��� �������
      }//if(FvmenuDis->UprCheck->Checked)
      else
      {
        NumBitClearingWord(ibit+1, &tmpU);//����� ���� �� ��� �������
      }
    }
  setCurrentMngUSTAVKI(tmpU);//����� ��� ���
  */
}//SaveUprMTZ()

char copyMTZ1ToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//������� ������
//���������� ��������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.packet = 0;    //����� ��������� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  MTZ1_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_MTZ1;//���� ����������

  rpzcomponent_obj.cntClon     = CNT_STUPEN_MTZ;   //max �-�� ������
  rpzcomponent_obj.numClon     = 1;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstMTZ1;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstMTZ1;//���������� �������
  rpzcomponent_obj.initIOCmd      = initIOCmd_MTZ1;      //������� IO ������
  rpzcomponent_obj.initTLCmd      = initTLCmd_MTZ1;      //������� TL ������
  rpzcomponent_obj.initENACmd     = initENACmd_MTZ1;     //������� ENA ������
  rpzcomponent_obj.bo_bvCmd       = NULL; //��������� �� �� ������
  rpzcomponent_obj.isDISactiv     = isDISactiv_MTZ1; //���������� ������������ ���
  rpzcomponent_obj.setBOBVtimer   = NULL; //������� �������� �� ��

  rpzcomponent_obj.nameStatusIO = ionsMTZ1;          //����� � ������ ������ IO
  rpzcomponent_obj.initTimers   = initTimersMTZ1;    //������ � ������� ��������
  rpzcomponent_obj.logic        = logicMTZ1;         //������ ����������

  rpzcomponent_obj.codecUst = codecUstMTZ1;   //����������-������������� �������

  return 0;//�� �������� �����������
}//

#endif // _HIDE_COMPONENT

