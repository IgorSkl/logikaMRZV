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

#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"
#include "logictimers\logictimersfnc.h"
#include "psuperVisor\psvisor_helpdef.h"

#include "virtualMenu\viewMenuList.h"

#include "psupervisor\psupervisor.h"

#include "toSpeedOptim.h"

#include "..\bazis.h"


//��� �����������
#define KOD_COMPONENT  UROV_COMP1
//�-�� ��������
#define CNT_STUPEN_UROV  1

#endif // _HIDE_COMPONENT

//������������� �������  � ��������� �������
//������� ��������
#define MNGUST_UROV    0

//������� ��������
//1 ������� ����
#define MNGVID_UROV1   1
//2 ������� ����
#define MNGVID_UROV2   2

//������� ����������
#define MNGUPR_UROV    3
//�-�� ������� � ��������� �������
#define MNGUST_UROV_TOTAL  4

//������������� ENA ������
//������ ����
#define ENA_UROV_1  0
//�-�� ENA ������
#define ENACMD_UROV_TOTAL 1

//������������� ������� � �����������
//������� ��������
#define SPVSRABUST_UROV    0
//������� ��������
#define SPVVOZVUST_UROV    1
//������� SPV ����� ROV
#define SPV_OUTA_UROV      2
#define SPV_OUTB_UROV      3
#define SPV_OUTC_UROV      4
//�-�� ������� � �����������
#define SPVUST_UROV_TOTAL  5

//---------------IO COMMAND------------------
//������������� IO ������ ��� UROV
//���� ���� ����
#define IOCMD1_UROV 0
//���� ����
#define IOCMD2_UROV 1
//���� ����1
#define IOCMD3_UROV 2
//���� ����2
#define IOCMD4_UROV 3
//�-�� IO ������
#define IOCMD_UROV_TOTAL    4

//---------------TL COMMAND------------------
//������������� TL ������ ��� UROV
//PO_UROV
#define TLCMD2_UROV 0
//ELOLDTRG_UROV
#define TLCMD3_UROV 1
//ELOUTTRG_UROV
#define TLCMD4_UROV 2
//�-�� TL ������
#define TLCMD_UROV_TOTAL    3

//--------------- TIMERS ------------------
//������������� �������� ��� UROV
//������ UROV_TIM1
#define TIMER1_UROV    0
//������ BO UROV_TIM1
#define TIMER1_BOUROV1 1
//������ UROV_TIM2
#define TIMER2_UROV    2
//������ BO UROV_TIM2
#define TIMER2_BOUROV2 3
//�-�� ��������
#define TIMERS_UROV_TOTAL   4

#ifndef _HIDE_COMPONENT

#define _HIDE_COMPONENT
//#include "PRM1Component.c"

extern COMPONENT_OBJ rpzcomponent_obj;//����� ���������� ��� �����������
extern int  tmpUSTAVKI[];

extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_tmp[];
extern int  IndexUstSPV;//������ ������� � �����������
extern int  IndexIO;//������ IO

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern char *bitStringUNI[];
extern int offsetUstMngPRM1;//�������� �� ������� PRM1
extern int  spvUSTAVKI[];//������� ������� �����������

void UstListCompUROV();
void ustRedactorCompUROV();
void UstCompUROV();
short  KadrMenuFormat_ust_compUROV(void *workCntr);//(WorkControl *workCntr);

void PereinitVidListCompUROV(short flg);
void VidListCompUROV();
void vidRedactorCompUROV();
void VidCompUROV();
short  KadrMenuFormat_vid_compUROV(void *workCntr);//(WorkControl *workCntr);

void PereinitUprListCompUROV(short flg);
void UprListCompUROV();
void uprRedactorCompUROV();
void UprCompUROV();
short  KadrMenuFormat_upr_compUROV(void *workCntr);//(WorkControl *workCntr);
int  initUstUROV(char init);
void  prepareUstUROV(short idxC);
char *selectorUprStrUROV(short iBit, UNS_32 ustUpr);

short  KadrMenuFormat_UROV(void *workCntr);//(WorkControl *workCntr);

void EditUstUROV();
void EditVidUROV();
void EditUprUROV();
int codecUstUROV(char codec, short offset, int ust);
void  logicUROV(int idxC);
int isDISactiv_UROV(int idxC);

int  offsetIOCmdUROV;//�������� ��� IO UROV

char UROV_TITLE[] = "����";

IONAMESTATUS_COMPONENT ionsUROV[IOCMD_UROV_TOTAL] =
{
  {
    1,//������ iocmd1
    "���� ���� ����"
  },
  {
    1,//������ iocmd2
    "���� ����"
  },
  {
    1,//������ iocmd3
    "���� ����1"
  },
  {
    1,//������ iocmd4
    "���� ����2"
  }
};

LineMenuItem sub_menu_comp_UROV[8] =
{
  { UROV_TITLE, NULL},//title
  { &CONTROL1_COMP, &sub_menu_cnf, typeMenuSub},//control_item, parent
  { "������� ����",    (void*)&UstListCompUROV, typeMenuProg},
  { "�������� ����",   (void*)&VidListCompUROV, typeMenuProg},
  { "���������� ����", (void*)&UprListCompUROV, typeMenuProg},
  { NULL, NULL}
};

LineMenuItem sub_menu_ust_compUROV[] =
{
  { "������� ����", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_UROV, typeMenuList},//control_item, parent
  { "��� ���� ����",        (void*)&UstCompUROV, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_vid_compUROV[] =
{
  { "�������� ����", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_UROV, typeMenuList},//control_item, parent
  { "�������� ����1",  (void*)&VidCompUROV, typeMenuProg},
  { "�������� ����2",  (void*)&VidCompUROV, typeMenuProg},
  { NULL, NULL}

};

LineMenuItem sub_menu_upr_compUROV[] =
{
  { "������ ����", NULL},//title
  { &CONTROL2_COMP, &sub_menu_comp_UROV, typeMenuList},//control_item, parent
  { "������ ����",      (void*)&UprCompUROV, typeMenuProg},
  { NULL, NULL}

};

void PereinitUstListCompUROV(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_ust_compUROV, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()
/*
void UstListCompUROV()
{
  LIGHTMNGUBAZA = 0;

  CRR_SUBMENU = sub_menu_ust_compUROV;//������� �������

  CRR_TEXTSTREAM = &CONTROL2_COMP;//������� control
  CRR_FHOME = &PereinitUstListCompUROV;//��������� �� �-��� HOME

  CRR_FHOME(1);//��������
  LanderUpDown();//wkl Up Down
}//UstListCompUROV()

void UstCompUROV()
{
  ViewToEditUst(ViewerEditUstUROV);
}//VidCompUROV()

int ViewerEditUstUROV()
{
//������������� �������
  LIGHTLINEMENU = TxtStreamIdxKadr(CRR_TEXTSTREAM);

  sub_menu_tmp[SUBDATA].Line2 = &sub_menu_ust_compUROV;// parent

  ViewerEditorUst(sub_menu_ust_compUROV[LIGHTLINEMENU +1+SUBDATA].Line1);//������������� �������

  return getCurrentMngUSTAVKI();
}//UstCompUROV()
*/
void UstListCompUROV()
{
  SelectorMNGBAZA(0);//��������� ���� �������

  SelectorSUBMENU(sub_menu_ust_compUROV);//�c�������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUstListCompUROV);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//UstListCompUROV()

void UstCompUROV()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_ust_compUROV);
  PassWord(EditUstUROV);
}//VidCompUROV()

void EditUstUROV()
{
//������������� �������
  SystemEditUst(sub_menu_ust_compUROV);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//UstCompUROV()

short  KadrMenuFormat_ust_compUROV(void *pstr)//(WorkControl *workCntr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  char locTxt[50];
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
    if(sub_menu_ust_compUROV[i+1+SUBDATA].Line1==NULL)break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, (char *)sub_menu_ust_compUROV[i+1+SUBDATA].Line1);
      sprintf(locTxt, "   %d", getUstOffsetMngUSTAVKI(i));
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, locTxt);
      return 1;
    }//COMPARE_COUNTER
  }//for

  return 1;
}//KadrMenuFormat

//--------------------------------------------------

void PereinitVidListCompUROV(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_vid_compUROV, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstListComp2()

/*
void VidListCompUROV()
{
  LIGHTMNGUBAZA = MNGVID_UROV1;

  CRR_SUBMENU = sub_menu_vid_compUROV;//������� �������

  CRR_TEXTSTREAM = &CONTROL2_COMP;//������� control
  CRR_FHOME = &PereinitVidListCompUROV;//��������� �� �-��� HOME

  CRR_FHOME(1);//��������
  LanderUpDown();//wkl Up Down
}//VidListCompUROV()

void VidCompUROV()
{
  ViewToEditUst(ViewerEditVidUROV);
}//VidCompUROV()

int ViewerEditVidUROV()
{
//������������� �������
  LIGHTLINEMENU = TxtStreamIdxKadr(CRR_TEXTSTREAM);

  sub_menu_tmp[SUBDATA].Line2 = &sub_menu_vid_compUROV;// parent

  ViewerEditorUst(sub_menu_vid_compUROV[LIGHTLINEMENU +1+SUBDATA].Line1);//������������� �������

  return getCurrentMngUSTAVKI();
}//
*/
void VidListCompUROV()
{
  SelectorMNGBAZA(MNGVID_UROV1);//��������� ���� �������

  SelectorSUBMENU(sub_menu_vid_compUROV);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitVidListCompUROV);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompUROV()

void VidCompUROV()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_vid_compUROV);
//  PassWord(EditVidAPV);
  EditVidUROV();
}//VidCompUROV()

void EditVidUROV()
{
//������������� �������
  SystemEditUst(sub_menu_vid_compUROV);//[LIGHTLINEMENU +1+SUBDATA].Line1, LIGHTLINEMENU);
}//

short  KadrMenuFormat_vid_compUROV(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  char locTxt[50];
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
    if(sub_menu_vid_compUROV[i+1+SUBDATA].Line1==NULL)break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, (char *)sub_menu_vid_compUROV[i+1+SUBDATA].Line1);
      sprintf(locTxt, "   %d", getUstOffsetMngUSTAVKI(i));
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, locTxt);
      return 1;
    }//COMPARE_COUNTER
  }//for

  return 1;
}//KadrMenuFormat_vid_compUROV(WorkControl *workCntr)

//--------------------------------------------------

void PereinitUprListCompUROV(short flg)
{
//��������
  //���� ������������� ��������
  TxtStreamInit(&CONTROL2_COMP, &KadrMenuFormat_upr_compUROV, NULL);//���� control � ������ �����
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL2_COMP, SIZE_PAGE_VIEW/2);//������� �� END
  }//if

  ViewDiskrMenuList();//������� ���� �����������
  ListPStr();//������ � ��������
}//PereinitUstList
/*
void UprListCompUROV()
{
  LIGHTMNGUBAZA = MNGUPR_UROV;

  CRR_SUBMENU = sub_menu_upr_compUROV;//������� �������

  CRR_TEXTSTREAM = &CONTROL2_COMP;//������� control
  CRR_FHOME = &PereinitUprListCompUROV;//��������� �� �-��� HOME

  CRR_FHOME(1);//��������
  LanderUpDown();//wkl Up Down
}//VidListCompUROV()

void UprCompUROV()
{
  LIGHTLINEMENU = TxtStreamIdxKadr(CRR_TEXTSTREAM);
//������������� ������� ����������
  sub_menu_tmp[SUBDATA].Line2 = &sub_menu_upr_compUROV;// parent
  char *nameUpr = (char *)sub_menu_upr_compUROV[LIGHTLINEMENU +1+SUBDATA].Line1;

  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrUROV);//������������� ������� ����������

}//UprCompMTZ1()
*/
void UprListCompUROV()
{
  SelectorMNGBAZA(MNGUPR_UROV);//��������� ���� �������

  SelectorSUBMENU(sub_menu_upr_compUROV);//��������� ������� �������

  SelectorTEXTCONTROL(&CONTROL2_COMP);//������� control

  SelectorFHOME(&PereinitUprListCompUROV);//��������� �� �-��� HOME
  InitFHOME(1);//exe �-��� HOME

  LanderUpDown();//wkl Up Down
}//VidListCompUROV()

void UprCompUROV()
{
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  PrepareEditMenu(sub_menu_upr_compUROV);
  PassWord(EditUprUROV);

}//UprCompUROV()

void EditUprUROV()
{
//������������� ������� ���
  char *nameUpr = (char *)sub_menu_upr_compUROV[LIGHTLINEMENU +1+SUBDATA].Line1;
  UpravlRedactor(nameUpr, LIGHTLINEMENU, &selectorUprStrUROV);//������������� ������� ����������
}//EditUprUROV()

short  KadrMenuFormat_upr_compUROV(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
    char *nameUpr = (char *)sub_menu_upr_compUROV[i+1+SUBDATA].Line1;
    if(nameUpr==NULL) break;

    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, nameUpr);

      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2,
      selectorUprStrUROV(i, getCurrentMngUSTAVKI()));

      return 1;//�������� �������� ������
    }
  }//for

  return 1;
}//KadrMenuFormat_upr_compUROV(WorkControl *workCntr)

char *selectorUprStrUROV(short iBit, UNS_32 ustUpr)
{
  switch(iBit)
  {

  default:;
  }//switch
    if(NumBitCheckWord(iBit, &ustUpr)) return bitStringUNI[UNIUPR_WKL];
    return bitStringUNI[UNIUPR_OTKL];
}//selectorUprStrUROV(short ibit, UNS_32 ustUpr)

int initUstUROV(char init)
{
  //������� �������
  if (init)
  {
//������� ��������
    tmpUSTAVKI[MNGUST_UROV] = 10;
//������� ��������
    tmpUSTAVKI[MNGVID_UROV1] = 50;
    tmpUSTAVKI[MNGVID_UROV2] = 60;
//������� ����������
    tmpUSTAVKI[MNGUPR_UROV] = 0;

  }//if

  IndexUstSPV += SPVUST_UROV_TOTAL;//������ ������� � �����������
  return MNGUST_UROV_TOTAL;//�-�� ������� � ��������� �������
}//initUstMTZ1(short mngUst, char init)

void  prepareUstUROV(short idxC)
{
  //���������� ENA ������ ��� �����
  //���������� ENA �� WideENA � ENAcmd
  CopyWideENAToENAcmd(PrepareENACmd(idxC, MNGUPR_UROV), ENACMD_UROV_TOTAL);
  //���������� �������
    int tmpOffsetUSpv = getOffsetSPVUstCnf(idxC);//�������� ������� ������ �����������

    //������� SPV ��������
  int tmp1 = 
  SPV_UST(SPVSRABUST_UROV) = codecUstUROV(1, MNGUST_UROV, getNativUstMngUSTAVKI(idxC, MNGUST_UROV));
  //������� SPV ��������
  SPV_UST(SPVVOZVUST_UROV) = tmp1 - tmp1/20;//5%

  short tmpOffsetT    =
    getOffsetTimersCnf(idxC);   //��������� � ������������
      //1 ������� ����
  setTimerPorog(tmpOffsetT+ TIMER1_UROV,
          codecUstUROV(1, MNGVID_UROV1, getNativUstMngUSTAVKI(idxC, MNGVID_UROV1)));
//������ BO UROV_TIM1
  setTimerPorog(tmpOffsetT+ TIMER1_BOUROV1, 10);

     //2 ������� ����
  setTimerPorog(tmpOffsetT+ TIMER2_UROV,
          codecUstUROV(1, MNGVID_UROV2, getNativUstMngUSTAVKI(idxC, MNGVID_UROV2)));
//������ BO UROV_TIM1
  setTimerPorog(tmpOffsetT+ TIMER2_BOUROV2 ,10);
}//prepareUstMTZ1(short idxC)

int initIOCmd_UROV()
{
  //������� IO ������
  offsetIOCmdUROV = IndexIO;//�������� ��� IO UROV
  return commonInitIOCmd(IOCMD_UROV_TOTAL);
}//initIOCmd_UROV()

int initTLCmd_UROV()
{
  //������� TL ������
  return commonInitTLCmd(TLCMD_UROV_TOTAL);
}//initTLCmd_UROV()

int initENACmd_UROV()
{
  //������� ENA ������
  return commonInitENACmd(ENACMD_UROV_TOTAL);
}//initENACmd_UROV()

void initTimersUROV(short idxC)
{
  //������ � ������� ��������
  commonInitTimers(TIMERS_UROV_TOTAL);
}//initTimersUROV()

int codecUstUROV(char codec, short offset, int ust)
//codec=0-����������
//codec=1-�������������
{
  //����������-������������� �������
  if(codec) return ust*1;
  return ust/1;
}//codecUstUROV(char *buf, short offset, int ust)

int isDISactiv_UROV(int idxC)
{
 //���������� ������������ ���
  return 0;//��� ����������
}//isDISactiv_UROV(int idxC)

char copyUROVToRepozitar(char packet)
{
  memset(&rpzcomponent_obj, 0, sizeof(COMPONENT_OBJ));//������� ������
//���������� ��������� � �����������
  rpzcomponent_obj.componentEnable = 1;//���������� ����������
  rpzcomponent_obj.kodC   = KOD_COMPONENT;         //��� ����������
  rpzcomponent_obj.packet = 0;    //����� ��������� ����������
  rpzcomponent_obj.permanent = 0; //������������ ���������

  strcpy(rpzcomponent_obj.nameComponent,  UROV_TITLE);       //��� ����������
  rpzcomponent_obj.sub_menu_component =  sub_menu_comp_UROV;//���� ����������

  rpzcomponent_obj.cntClon     = CNT_STUPEN_UROV;   //max �-�� ������
  rpzcomponent_obj.numClon     = 1;//����� �����
  rpzcomponent_obj.workToSignal = 0; //������ �� ������

  rpzcomponent_obj.initUstMng     = initUstUROV;    //������� �������
  rpzcomponent_obj.prepareUstSpv  = prepareUstUROV;//���������� �������
  rpzcomponent_obj.initIOCmd      = initIOCmd_UROV;      //������� IO ������
  rpzcomponent_obj.initTLCmd      = initTLCmd_UROV;      //������� TL ������
  rpzcomponent_obj.initENACmd     = initENACmd_UROV;     //������� ENA ������
  rpzcomponent_obj.bo_bvCmd       = NULL; //��������� �� �� ������
  rpzcomponent_obj.isDISactiv     = isDISactiv_UROV; //���������� ������������ ���
  rpzcomponent_obj.setBOBVtimer   = NULL; //������� �������� �� ��

  rpzcomponent_obj.nameStatusIO = ionsUROV;          //����� � ������ ������ IO
  rpzcomponent_obj.initTimers   = initTimersUROV;    //������ � ������� ��������
  rpzcomponent_obj.logic        = logicUROV;         //������ ����������

  rpzcomponent_obj.codecUst = codecUstUROV;   //����������-������������� �������

  return 0;//�� �������� �����������
}//

#endif // _HIDE_COMPONENT

