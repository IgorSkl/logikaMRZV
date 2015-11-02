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

//#include "component\componentdef.h"
//#include "virtualMenu\systemmenudef.h"
//#include "virtualMenu\ustmanagerdef.h"

#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"
#include "logictimers\logictimersfnc.h"

#include "virtualMenu\viewMenuList.h"

#include "psupervisor\psupervisor.h"

#include "toSpeedOptim.h"

#include "..\bazis.h"

//��� �����������
#define KOD_COMPONENT  UMM_COMP1
//�-�� ��������
#define CNT_STUPEN_UMM  1

#endif // _HIDE_COMPONENT

//������������� �������  � ��������� �������
//������� �������� UMAX1
#define MNGUST_UMAX1_UMM    0
//������� �������� UMAX2
#define MNGUST_UMAX2_UMM    1
//������� �������� UMIN1
#define MNGUST_UMIN1_UMM    2
//������� I ���� IMIN1
#define MNGUST_IMIN1_UMM    3
//������� �������� UMIN2
#define MNGUST_UMIN2_UMM    4
//������� I ���� IMIN2
#define MNGUST_IMIN2_UMM    5

//������� ��������
//����� UMAX1
#define MNGVID1_UMM    6
//����� UMAX2
#define MNGVID2_UMM    7
//����� UMIN1
#define MNGVID3_UMM    8
//����� UMIN2
#define MNGVID4_UMM    9

//������� ����������
#define MNGUPR_UMM    10
//�-�� ������� � ��������� �������
#define MNGUST_UMM_TOTAL  11
#define MNGUST_BOBV_UMM  MNGUST_UMM_TOTAL

//������������� ENA ������
//������ UMAX1
#define ENA_UMAX1_1      0
// UMAX1 � ���
#define ENA_UMAX1_2      1
// UMAX1 ��� ���
#define ENA_UMAX1_3      2

//������ UMAX2
#define ENA_UMAX2_1      3
// UMAX2 � ���
#define ENA_UMAX2_2      4
// UMAX2 ��� ���
#define ENA_UMAX2_3      5

//������ UMIN1
#define ENA_UMIN1_1      6
// UMINX1 � ���
#define ENA_UMIN1_2      7
// UMIN1 ��� ���
#define ENA_UMIN1_3      8
// UMIN1 ���� I
#define ENA_UMIN1_4      9

//������ UMIN2
#define ENA_UMIN2_1      10
// UMINX2 � ���
#define ENA_UMIN2_2      11
// UMIN2 ��� ���
#define ENA_UMIN2_3      12
// UMIN2 ���� I
#define ENA_UMIN2_4      13

// UMIN1 ���� U
#define ENA_UMIN1_5      14
// UMIN2 ���� U
#define ENA_UMIN2_5      15

//�-�� ENA ������ UMM
#define ENACMD_UMM_TOTAL 16

//������������� ������� � �����������
//������� �������� U
#define SPVSRABUST_UMAX1_UMM    0
#define SPVSRABUST_UMAX2_UMM    1
#define SPVSRABUST_UMIN1_UMM    2
#define SPVSRABUST_IMIN1_UMM    3
#define SPVSRABUST_UMIN2_UMM    4
#define SPVSRABUST_IMIN2_UMM    5
//������� �������� U
#define SPVVOZVUST_UMAX1_UMM    6
#define SPVVOZVUST_UMAX2_UMM    7
#define SPVVOZVUST_UMIN1_UMM    8
#define SPVVOZVUST_IMIN1_UMM    9
#define SPVVOZVUST_UMIN2_UMM    10
#define SPVVOZVUST_IMIN2_UMM    11
//������� �������� I BLOK
#define SPVSRABUST_IBLOK1_UMM   12
#define SPVSRABUST_IBLOK2_UMM   13
//������� �������� I BLOK
#define SPVVOZVUST_IBLOK1_UMM   14
#define SPVVOZVUST_IBLOK2_UMM   15
//������� SPV ����� UMAX1
#define SPV_OUTAL_UMAX1         16
#define SPV_OUTBL_UMAX1         17
#define SPV_OUTCL_UMAX1         18
#define SPV_OUTAF_UMAX1         19
#define SPV_OUTBF_UMAX1         20
#define SPV_OUTCF_UMAX1         21
//������� SPV ����� UMAX2
#define SPV_OUTAL_UMAX2         22
#define SPV_OUTBL_UMAX2         23
#define SPV_OUTCL_UMAX2         24
#define SPV_OUTAF_UMAX2         25
#define SPV_OUTBF_UMAX2         26
#define SPV_OUTCF_UMAX2         27
//������� SPV ����� UMIN1
#define SPV_OUTAL_UMIN1         28
#define SPV_OUTBL_UMIN1         29
#define SPV_OUTCL_UMIN1         30
#define SPV_OUTAF_UMIN1         31
#define SPV_OUTBF_UMIN1         32
#define SPV_OUTCF_UMIN1         33
//������� SPV ����� UMIN2
#define SPV_OUTAL_UMIN2         34
#define SPV_OUTBL_UMIN2         35
#define SPV_OUTCL_UMIN2         36
#define SPV_OUTAF_UMIN2         37
#define SPV_OUTBF_UMIN2         38
#define SPV_OUTCF_UMIN2         39
//������� SPV ����� IBLOK1
#define SPV_OUTIA_UMIN1         40
#define SPV_OUTIB_UMIN1         41
#define SPV_OUTIC_UMIN1         42
//������� SPV ����� IBLOK2
#define SPV_OUTIA_UMIN2         43
#define SPV_OUTIB_UMIN2         44
#define SPV_OUTIC_UMIN2         45
//�-�� ������� � �����������
#define SPVUST_UMM_TOTAL  46

//---------------IO COMMAND------------------
//������������� IO ������ ��� APV
//���� ���� UMAX1
#define IOCMD1_UMM 0
//���� ���� UMAX2
#define IOCMD2_UMM 1
//���� ���� UMIN1
#define IOCMD3_UMM 2
//���� ���� UMIN2
#define IOCMD4_UMM 3
//�� UMAX1
#define IOCMD5_UMM 4
//���� UMAX1
#define IOCMD6_UMM 5
//�� UMAX2
#define IOCMD7_UMM 6
//���� UMAX2
#define IOCMD8_UMM 7
//�� UMIN1
#define IOCMD9_UMM 8
//���� UMIN1
#define IOCMD10_UMM 9
//�� UMIN2
#define IOCMD11_UMM 10
//���� UMIN2
#define IOCMD12_UMM 11
//���� UMIN1
#define IOCMDPUSK1_UMM 12
//���� UMIN2
#define IOCMDPUSK2_UMM 13
//�-�� IO ������
#define IOCMD_UMM_TOTAL    14

//---------------TL COMMAND------------------
//������������� TL ������ ��� UMM
//�-�� TL ������
#define TLCMD_UMM_TOTAL    0

//--------------- TIMERS ------------------
//������������� �������� ��� UMM
//������ UMIN1_TIM1
#define TIMER1_UMM     0
//������ UMIN2_TIM1
#define TIMER2_UMM     1
//������ BO UMIN1
#define TIMER_BOUMIN1  2
//������ BO UMIN2
#define TIMER_BOUMIN2  3
//������ UMAX1_TIM1
#define TIMER3_UMM     4
//������ UMAX2_TIM1
#define TIMER4_UMM     5
//������ BO UMAX1
#define TIMER_BOUMAX1  6
//������ BO UMAX2
#define TIMER_BOUMAX2  7
//�-�� ��������
#define TIMERS_UMM_TOTAL   8

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
#include "PRM1Component.c"

extern COMPONENT_OBJ  cnfCOMPONENT[];//������������
extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������
extern int  tmpUSTAVKI[];
extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexIO;//������ IO
extern int  IndexUstSPV;//������ ������� � �����������
extern int  spvUSTAVKI[];//������� ������� �����������
extern char *bitStringUNI[];
extern int offsetUstMngPRM1;//�������� �� ������� PRM1

void UstListCompUMM();
void ustRedactorCompUMM();
void UstCompUMM();
void  logicUMM(int idxC);

void PereinitVidListCompUMM(short flg);
void VidListCompUMM();
void vidRedactorCompUMM();
void VidCompUMM();

void PereinitUprListCompUMM(short flg);
void UprListCompUMM();
void uprRedactorCompUMM();
void UprCompUMM();
short  KadrMenuFormat_upr_compUMM(void *workCntr);
short  KadrMenuFormat_ustvidUMM(void *workCntr);
int   initUstUMM(char init);
void  prepareUstUMM(short idxC);
char *selectorUprStrUMM(short iBit, UNS_32 ustUpr);

void EditUstUMM();
void EditVidUMM();
void EditUprUMM();
int codecUstUMM(char codec, short offset, int ust);

int   isDISactiv_UMM(int idxC);

int  offsetIOCmdUMM;//�������� ��� IO UMM

char UMM_TITLE[] = "��";

IONAMESTATUS_COMPONENT ionsUMM[IOCMD_UMM_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� ���� UMAX1"
  },
  {
    1,//������ iocmd2
    "���� ���� UMAX2"
  },
  {
    1,//������ iocmd3
    "���� ���� UMIN1"
  },
  {
    1,//������ iocmd4
    "���� ���� UMIN2"
  },
  {
    1,//������ iocmd5
    "���� �� UMAX1"
  },
  {
    1,//������ iocmd6
    "���� UMAX1"
  },
  {
    1,//������ iocmd7
    "���� �� UMAX2"
  },
  {
    1,//������ iocmd8
    "���� UMAX2"
  },
  {
    1,//������ iocmd9
    "���� �� UMIN1"
  },
  {
    1,//������ iocmd10
    "���� UMIN1"
  },
  {
    1,//������ iocmd11
    "���� �� UMIN2"
  },
  {
    1,//������ iocmd12
    "���� UMIN2"
  },
  {
    1,//������ iocmd13
    "���� UMIN1"
  },
  {
    1,//������ iocmd14
    "���� UMIN2"
  }
};

LineMenuItem sub_menu_comp_UMM[8] =
{
  { UMM_TITLE, NULL},//title
  { &CONTROL1_COMP,   &sub_menu_cnf,   typeMenuSub},//control_item, parent
  { "������� ��",     (void *)&UstListCompUMM, typeMenuProg},
  { "�������� ��",    (void *)&VidListCompUMM, typeMenuProg},
  { "���������� ��",  (void *)&UprListCompUMM, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compUMM[] =
{
  { "������� ��", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_UMM, typeMenuList},//control_item, parent
  { "���� UMAX1",        (void *)&UstCompUMM, typeMenuProg},
  { "���� UMAX2",        (void *)&UstCompUMM, typeMenuProg},
  { "���� UMIN1",        (void *)&UstCompUMM, typeMenuProg},
  { "��� ���� UMIN1",    (void *)&UstCompUMM, typeMenuProg},
  { "���� UMIN2",        (void *)&UstCompUMM, typeMenuProg},
  { "��� ���� UMIN2",    (void *)&UstCompUMM, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compUMM[] =
{
  { "�������� ��", NULL},//title
  { &CONTROL2_COMP,     &sub_menu_comp_UMM, typeMenuList},//control_item, parent
  { "����� UMAX1",      (void *)&VidCompUMM, typeMenuProg},
  { "����� UMAX2",      (void *)&VidCompUMM, typeMenuProg},
  { "����� UMIN1",      (void *)&VidCompUMM, typeMenuProg},
  { "����� UMIN2",      (void *)&VidCompUMM, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compUMM[] =
{
  { "������ ��", NULL},//title
  { &CONTROL2_COMP,   &sub_menu_comp_UMM, typeMenuList},//control_item, parent
/*
  { "������ UMAX1",   (void *)&UprCompUMM, typeMenuProg},
  { "������ UMAX1",   (void *)&UprCompUMM, typeMenuProg},
  { "����� UMAX1",    (void *)&UprCompUMM, typeMenuProg},
  { "������ UMAX2",   (void *)&UprCompUMM, typeMenuProg},
  { "������ UMAX2",   (void *)&UprCompUMM, typeMenuProg},
  { "����� UMAX2",    (void *)&UprCompUMM, typeMenuProg},
  { "������ UMIN1",   (void *)&UprCompUMM, typeMenuProg},
  { "������ UMIN1",   (void *)&UprCompUMM, typeMenuProg},
  { "����� UMIN1",    (void *)&UprCompUMM, typeMenuProg},
  { "��� ���� UMIN1", (void *)&UprCompUMM, typeMenuProg},
  { "������ UMIN2",   (void *)&UprCompUMM, typeMenuProg},
  { "������ UMIN2",   (void *)&UprCompUMM, typeMenuProg},
  { "����� UMIN2",    (void *)&UprCompUMM, typeMenuProg},
  { "��� ���� UMIN2", (void *)&UprCompUMM, typeMenuProg},
  { "���� ���� UMIN1",(void *)&UprCompUMM, typeMenuProg},
  { "���� ���� UMIN2",(void *)&UprCompUMM, typeMenuProg},
*/
  { NULL, NULL}

};

void PereinitUstListCompUMM(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidUMM, sub_menu_ust_compUMM);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void UstListCompUMM()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compUMM);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompUMM);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompUMM()

void UstCompUMM()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compUMM);
  PassWord(EditUstUMM);
}//VidCompUMM()

void EditUstUMM()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compUMM);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompUMM()

short  KadrMenuFormat_ustvidUMM(void *pstr)
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
      strcpy((char *)workCntr->twoString, (char *) ((LineMenuItem *)workCntr->userPoint) [i+1+SUBDATA].Line1);
      sprintf(locTxt, "   %d", getUstOffsetMngUSTAVKI(i));
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, locTxt);
      return 1;//�������� �������� ������
    }
  }//for

  return 1;
}//KadrMenuFormat_ust_1(WorkControl *workCntr)

//--------------------------------------------------

void PereinitVidListCompUMM(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ustvidUMM, sub_menu_vid_compUMM);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

void VidListCompUMM()
{
  SelectorMNGBAZA(MNGVID1_UMM);//��������� ���� �������

  SelectorSUBMENU(sub_menu_vid_compUMM);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitVidListCompUMM);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompUMM()

void VidCompUMM()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_vid_compUMM);
//  PassWord(EditVidAPV);
  EditVidUMM();
}//VidCompUMM()

void EditVidUMM()
{
//������������� �������
  SystemEditUst(sub_menu_vid_compUMM);
}//

//--------------------------------------------------

void PereinitUprListCompUMM(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compUMM, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstList

void UprListCompUMM()
{
  SelectorMNGBAZA(MNGUPR_UMM);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compUMM);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUprListCompUMM);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompUMM()

void UprCompUMM()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compUMM);
  PassWord(EditUprUMM);

}//UprCompUMM()

void EditUprUMM()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compUMM[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrUMM);//������������� ������� ����������
}//EditUprUMM()

short  KadrMenuFormat_upr_compUMM(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    char *nameUpr = (char *)sub_menu_upr_compUMM[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrUMM(i, getCurrentMngUSTAVKI()));

      return 1;//�������� �������� ������
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compUMM(WorkControl *workCntr)

char *selectorUprStrUMM(short iBit, UNS_32 ustUpr)
{
  switch(iBit)
  {
  case 1:
  case 4:
  case 7:
  case 11:
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_ILI];
    return bitStringUNI[UNIUPR_I];

  case 2:
  case 5:
  case 8:
  case 12:
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_LIN];
    return bitStringUNI[UNIUPR_FAZ];

  default:;
  }//switch
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_WKL];
    return bitStringUNI[UNIUPR_OTKL];
}//selectorUprStrUMM(short ibit, UNS_32 ustUpr)

int initUstUMM(char init)
{
  //������� �������
  if (init)
  {
//������� ��������
	//������� �������� UMAX1
    tmpUSTAVKI[MNGUST_UMAX1_UMM] = 10;
	//������� �������� UMAX2
    tmpUSTAVKI[MNGUST_UMAX2_UMM] = 11;
	//������� �������� UMIN1
    tmpUSTAVKI[MNGUST_UMIN1_UMM] = 12;
	//������� ���� IMIN1
    tmpUSTAVKI[MNGUST_IMIN1_UMM] = 13;
	//������� �������� UMIN2
    tmpUSTAVKI[MNGUST_UMIN2_UMM] = 14;
	//������� ���� IMIN2
    tmpUSTAVKI[MNGUST_IMIN2_UMM] = 15;
//������� ��������
	//����� UMAX1
    tmpUSTAVKI[MNGVID1_UMM] = 20;
	//����� UMAX2
    tmpUSTAVKI[MNGVID2_UMM] = 21;
	//����� UMIN1
    tmpUSTAVKI[MNGVID3_UMM] = 22;
	//����� UMIN2
    tmpUSTAVKI[MNGVID4_UMM] = 23;
//������� ����������
    tmpUSTAVKI[MNGUPR_UMM]  = 0;

  }//if

  IndexUstSPV += SPVUST_UMM_TOTAL;//������ ������� � �����������
  return MNGUST_UMM_TOTAL;//�-�� ������� � ��������� �������
}//initUstUMM(short mngUst, char init)

void  prepareUstUMM(short idxC)
{
  //���������� ENA ������ ��� �����
  //���������� ENA �� WideENA � ENAcmd
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_UMM), ENACMD_UMM_TOTAL);
  //���������� �������
  int tmpOffsetUSpv = getOffsetSPVUstCnf(idxC);//�������� ������� ������ �����������

    //UMAX
    //������� SPV ��������
    int tmp1 = 
    SPV_UST(SPVSRABUST_UMAX1_UMM) = codecUstUMM(1, MNGUST_UMAX1_UMM, getNativUstMngUSTAVKI(idxC, MNGUST_UMAX1_UMM));
    //������� SPV ��������
    SPV_UST(SPVVOZVUST_UMAX1_UMM) = tmp1 - tmp1/20;//5%
    //������� SPV ��������
    tmp1 = 
    SPV_UST(SPVSRABUST_UMAX2_UMM) = codecUstUMM(1, MNGUST_UMAX2_UMM, getNativUstMngUSTAVKI(idxC, MNGUST_UMAX2_UMM));
    //������� SPV ��������
    SPV_UST(SPVVOZVUST_UMAX2_UMM) = tmp1 - tmp1/20;//5%

    //UMIN
    //������� SPV ��������
    tmp1 = 
    SPV_UST(SPVSRABUST_UMIN1_UMM) = codecUstUMM(1, MNGUST_UMIN1_UMM, getNativUstMngUSTAVKI(idxC, MNGUST_UMIN1_UMM));
    //������� SPV ��������
    SPV_UST(SPVVOZVUST_UMIN1_UMM) = tmp1 + tmp1/20;//5%
    //������� SPV ��������
    tmp1 =
    SPV_UST(SPVSRABUST_UMIN2_UMM) = codecUstUMM(1, MNGUST_UMIN2_UMM, getNativUstMngUSTAVKI(idxC, MNGUST_UMIN2_UMM));
    //������� SPV ��������
    SPV_UST(SPVVOZVUST_UMIN2_UMM) = tmp1 + tmp1/20;//5%

        //I ������ UMM1
    tmp1 =
    SPV_UST(SPVSRABUST_IBLOK1_UMM) = codecUstUMM(1, MNGUST_IMIN1_UMM, getNativUstMngUSTAVKI(idxC, MNGUST_IMIN1_UMM));
    //������� SPV ��������
    SPV_UST(SPVVOZVUST_IBLOK1_UMM) = tmp1 - tmp1/20;//5%
    //I ������ UMM2
    tmp1 =
    SPV_UST(SPVSRABUST_IBLOK2_UMM) = codecUstUMM(1, MNGUST_IMIN2_UMM, getNativUstMngUSTAVKI(idxC, MNGUST_IMIN2_UMM));
    //������� SPV ��������
    SPV_UST(SPVVOZVUST_IBLOK2_UMM) = tmp1 - tmp1/20;//5%

  //���������� ��������
  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //��������� � ������������

	//������ UMIN1_TIM1
   setTimerPorog(tmpOffsetT+ TIMER1_UMM,
          codecUstUMM(1, MNGVID3_UMM, getNativUstMngUSTAVKI(idxC, MNGVID3_UMM)));
	//������ UMIN2_TIM1
   setTimerPorog(tmpOffsetT+ TIMER2_UMM,
          codecUstUMM(1, MNGVID4_UMM, getNativUstMngUSTAVKI(idxC, MNGVID4_UMM)));
	//������ BO UMIN1
   setTimerPorog(tmpOffsetT+ TIMER_BOUMIN1, 9);
	//������ BO UMIN2
   setTimerPorog(tmpOffsetT+ TIMER_BOUMIN2, 9);
	//������ UMAX1_TIM1
   setTimerPorog(tmpOffsetT+ TIMER3_UMM,
          codecUstUMM(1, MNGVID1_UMM, getNativUstMngUSTAVKI(idxC, MNGVID1_UMM)));
	//������ UMAX2_TIM1
   setTimerPorog(tmpOffsetT+ TIMER4_UMM,
          codecUstUMM(1, MNGVID2_UMM, getNativUstMngUSTAVKI(idxC, MNGVID2_UMM)));
	//������ BO UMAX1
   setTimerPorog(tmpOffsetT+ TIMER_BOUMAX1, 9);
	//������ BO UMAX2
   setTimerPorog(tmpOffsetT+ TIMER_BOUMAX2, 9);

}//prepareUstUMM(short idxC)

int initIOCmd_UMM()
{
  //������� IO ������
  offsetIOCmdUMM = IndexIO;//�������� ��� IO UMM
  return commonInitIOCmd(IOCMD_UMM_TOTAL);
}//initIOCmd_APV()

int initTLCmd_UMM()
{
  //������� TL ������
  return commonInitTLCmd(TLCMD_UMM_TOTAL);
}//initTLCmd_UMM()

int initENACmd_UMM()
{
  //������� ENA ������
  return commonInitENACmd(ENACMD_UMM_TOTAL);
}//initENACmd_UMM()

void initTimersUMM(short idxC)
{
  //������ � ������� ��������
  commonInitTimers(TIMERS_UMM_TOTAL);
}//initTimersUMM()

int codecUstUMM(char codec, short offset, int ust)
//codec=0-����������
//codec=1-�������������
{
  //����������-������������� �������
  if(codec) return ust*1;
  return ust/1;
}//codecUstUMM(char *buf, short offset, int ust)

int isDISactiv_UMM(int idxC)
{
 //���������� ������������ ���
//    int tmpOffsetT    =
  //              cnfCOMPONENT[idxC].offsetTimers;   //������� ���������� � ������������
  return 0;//��� ����������
}//isDISactiv_UMM(int idxC)

char copyUMMToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//������� ������

//���������� ��������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.packet = 0;    //����� ��������� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  UMM_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_UMM;//���� ����������

  rpzcomponent_obj.cntClon      = CNT_STUPEN_UMM;   //max �-�� ������
  rpzcomponent_obj.numClon      = 1;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstUMM;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstUMM;//���������� �������
  rpzcomponent_obj.initIOCmd      = initIOCmd_UMM;      //������� IO ������
  rpzcomponent_obj.initTLCmd      = initTLCmd_UMM;      //������� TL ������
  rpzcomponent_obj.initENACmd     = initENACmd_UMM;     //������� ENA ������
  rpzcomponent_obj.bo_bvCmd       = NULL; //��������� �� �� ������
  rpzcomponent_obj.isDISactiv     = isDISactiv_UMM; //���������� ������������ ���
  rpzcomponent_obj.setBOBVtimer   = NULL; //������� �������� �� ��

  rpzcomponent_obj.nameStatusIO = ionsUMM;          //����� � ������ ������ IO
  rpzcomponent_obj.initTimers   = initTimersUMM;    //������ � ������� ��������
  rpzcomponent_obj.logic        = logicUMM;         //������ ����������

  rpzcomponent_obj.codecUst = codecUstUMM;   //����������-������������� �������

  return 0;//�� �������� �����������
}//

#endif // _HIDE_COMPONENT

