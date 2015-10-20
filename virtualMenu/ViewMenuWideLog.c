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

#include "psuperVisor\supermanager.h"

#include "bazisdef.h"
#include "component\componentdef.h"
#include "virtualMenu\systemmenudef.h"
#include "virtualMenu\rangmanagerdef.h"
#include "virtualMenu\wideLogManagerdef.h"

#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\rangmanagerfnc.h"
#include "virtualMenu\wideLogManagerfnc.h"
#include "psuperVisor\psupervisor.h"
#include "psuperVisor\psvisor_helpfnc.h"

#include "virtualMenu\viewMenuTip.h"
#include "virtualMenu\viewMenuWideLog.h"
#include "virtualMenu\viewMenuSub.h"
#include "virtualMenu\viewMenuCnf.h"

#include "..\bazis.h"

#include "toSpeedOptim.h"


//����� ���� ��� ��������������
#define RANG_BIT        LIGHTMNGUOFFSET
//�-�� �������� ������
#define RANG_CNTOPEN_CMD LIGHTMNGUBAZA
//������ ����� ��
#define MARKCLON_WL 1000

extern LineMenuItem sub_menu_editwl[];
extern LineMenuItem sub_menu_cntr[];
extern LineMenuItem sub_menu_cnfwl[];
extern LineMenuItem sub_menu_tmp[];
extern LineMenuItem sub_menu_rpzWL[];

extern LineMenuItem sub_menu_viewWL[];
extern LineMenuItem sub_menu_logw[];
extern int workerUniversal1;//������ ��� ���������
extern int workerUniversal2;//������ ��� ���������
extern IONAMESTATUS_RANGIR  nameStatusRANGIR[];
extern UNS_32 ArrayWIDELOG[];
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern COMPONENT_OBJ  cnfCOMPONENT_WL[];
extern char isRangRedactor;//���� �� ������������� ������
extern int  TypLE[];
extern char titleWideLog[];

void SetTitleLE(int le, char *title)
{
//��������� ��
  switch(TypLE[le])
  {
  case typeLE_DIS:
    strcat(title, "-����");
    break;
  case typeLE_OR:
    strcat(title, "-������� ���");
    break;
  case typeLE_AND:
    strcat(title, "-������� �");
    break;
  case typeLE_XOR:
    strcat(title, "-������� ���� ���");
    break;
  default:
    ;
  }//switch
}//SetTitleLE(int le, char *title)

void OpenViewLE()
{
//�������  ��� ������� LE �� ��������
  MngWideLogPrepareArrayWIDELOGtoEdit();//����������� ArrayWIDELOG � ��������������

//  CRR_TEXTSTREAM = &CONTROL_EWL;//������� control
  SelectorTEXTCONTROL(&CONTROL_EWL);//���������� ������� ������ �� ��������� �����
//  CRR_FHOME = &PereinitViewLE;//��������� �� �-��� HOME
  SelectorFHOME(&PereinitViewLE);//��������� �� �-��� HOME

//  CRR_FHOME(1);
  InitFHOME(1);//��������
}//OpenViewLE()

void PereinitViewLE(short flg)
{
//�-��� �������� LE
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewLE, NULL);//���� ������ ������ � ������ �����
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//������� ���� �����������

}//PereinitViewLE(short flg)

short  KadrMenuFormat_viewLE(void *pstr)
{
  WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  short cntKadr = 0;//�-�� ������
  short isEmpty = 0;

  UNS_32 cmnDQuadro[2*DQUADRO];//����� dquadro

  setComonDQuadro(cmnDQuadro);//��������� ����� dquadro

  workerUniversal1 = 0;//������ ��� ���������
  MultiBitWorkerHostQuadroWL(
    cmnDQuadro, &pfWorker1);
  cntKadr = workerUniversal1;//�-�� ������ ��� ����� dquadro

  if(cntKadr==0)
  {
    isEmpty = 1;
    cntKadr=1;
  }//if


  for(int i=0;; i++)
  {
//�������� �����������
    if(i==cntKadr) break;

    COMPARE_COUNTER
    {
      if(isEmpty)
      {
        strcpy((char *)workCntr->twoString, "�����");
        return 1;
      }//if

      //��� � ���� ������� WL
      //����� ������ i-� �������� �������
      workerUniversal2 = i;//������ ��� ���������
      workerUniversal1 = 0;
      MultiBitWorkerHostQuadroWL(
        cmnDQuadro, &pfWorker2);
      //��� � ���� ������� WL
      setNameIOWL(workerUniversal2, (char *)workCntr->twoString);

      return 1;
    }//COMPARE_COUNTER
  }//for


  return 1;

}//KadrMenuFormat_viewLE(WorkControl *workCntr)

void ClickOpenEditWL(UNS_32 *cmdLE)
{
  /*
//�������� ��� ArrayWIDELOG ����� LE ��� ��������������
  short  findClon = -1; //����� ���� ��� ����������������
  //������ � cnf
  UNS_32 tmp=0;
  for(int i=0; i<3* 2*DQUADRO; i++) tmp|=cmdLE[i];
  UNS_32 cmdUnion[DQUADRO];
  memset(cmdUnion, 0, 4*DQUADRO);
  //��������� PRM
  for(int i=0; i<DQUADRO; i++) cmdUnion[i] |= cmdLE[i];
  //��������� MINUS
  for(int i=0; i<DQUADRO; i++) cmdUnion[i] |= cmdLE[i +2*DQUADRO];
  //��������� PLUS
  for(int i=0; i<DQUADRO; i++) cmdUnion[i] |= cmdLE[i +2*DQUADRO+2*DQUADRO];

  //��������� �-�� ���
  workerUniversal1 = 0;//������ ��� ���������
  MultiBitWorkerHostQuadro(cmdUnion, &pfWorker1);
  short cntBitCnf = workerUniversal1;//�-�� �������� ��� cnf
//����� �-�� ������ � cnf
  short cntClonCnf = 0;
  while (cnfCOMPONENT[cntClonCnf].componentEnable)   //��� ���������� � ������������ cnf
  {
    cntClonCnf++;
  }//while

  workerUniversal2 = TxtStreamIdxKadr(CRR_TEXTSTREAM);
  if(workerUniversal2<cntBitCnf)
  {
    //����� ������ i-� �������� ������� cnf
    workerUniversal1 = 0;
    MultiBitWorkerHostQuadro(cmdUnion, &pfWorker2);

//����� ���� ��� ���������������� cnf
    short next = 0;
    while (cnfCOMPONENT[next].componentEnable)   //��� ���������� � ������������ cnf
    {
      if(getOffsetIOCmdCnf(next)>workerUniversal2) break;
      next++;
    }//while
    findClon = next-1;
  }//if
  else
  {
    //������ � ��
    memset(cmdUnion, 0, 4*DQUADRO);
    //��������� PRM
    for(int i=0; i<DQUADRO; i++) cmdUnion[i] |= cmdLE[i +DQUADRO];
    //��������� MINUS
    for(int i=0; i<DQUADRO; i++) cmdUnion[i] |= cmdLE[i +2*DQUADRO +DQUADRO];
    //��������� PLUS
    for(int i=0; i<DQUADRO; i++) cmdUnion[i] |= cmdLE[i +2*DQUADRO+2*DQUADRO +DQUADRO];

    //��������� �-�� ���
    workerUniversal1 = 0;//������ ��� ���������
    MultiBitWorkerHostQuadro(cmdUnion, &pfWorker1);
    //short cntBitWL = workerUniversal1;//�-�� �������� ��� WL
    if(workerUniversal1)//�-�� �������� ��� WL
    {
      workerUniversal2 -= cntBitCnf;//������ ���� cnf
      //����� ������ i-� �������� ������� WL
      workerUniversal1 = 0;
      MultiBitWorkerHostQuadro(cmdUnion, &pfWorker2);

      //����� ���� ��� ���������������� WL
      short next = 0;
      while (cnfCOMPONENT_WL[next].componentEnable)   //��� ���������� � ������������ cnf
      {
        if(getOffsetIOCmdCnf_WL(next)>workerUniversal2) break;
        next++;
      }//while
      findClon = next-1;
      findClon += cntClonCnf;
    }//if(cntBitWL)
  }//else

//������� �������������� ������
  LIGHTCLON = -1;//������ ���� ����������

//�-��� ��������
//  CRR_TEXTSTREAM = &CONTROL_ERNG;
  SelectorTEXTCONTROL(&CONTROL_ERNG);//���������� ������� ������ �� ��������� �����

//������� sub_menu � ����� ��� parent
  sub_menu_editwl[SUBDATA].Line2 = CRR_SUBMENU;

//  CRR_SUBMENU = sub_menu_editwl;//����� ������� submenu
   SelectorSUBMENU(sub_menu_editwl);//�c�������� ������� �������

  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_openEditWL, NULL);//���� ������ ������ � ������ �����
  if(findClon>0)
    TxtStreamSetIdxKadr(CRR_TEXTSTREAM, findClon);//��������� ������ �������� �����

  ViewDiskrMenu(typeMenuEditWL);//������� ���� �����������
  ListPStr();//���������� ��������� ������

  FvmenuDis->TipPanel->Visible = true;
  ViewTipPanel(1);//������ ��������� TipPanel
  */
}//ClickOpenEditWL(UNS_32 *cmdLE)

short  KadrMenuFormat_openEditWL(void *pstr)
{
  WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    short next = 0;
    short nextWL = 0;
    while (cnfCOMPONENT[next].componentEnable)   //��� ���������� � ������������
    {
      next++;
    }//while

    while (cnfCOMPONENT_WL[nextWL].componentEnable)   //��� ���������� � ������������ ��
    {
      nextWL++;
    }//while

    if(next==0)
    {
      strcpy((char *)workCntr->twoString, "������������");
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "������");
      if(i==1)break;
    }//if
    else
    {
      if(i==(next+ nextWL)) break;
    }//else

    COMPARE_COUNTER
    {
      if(i<next)//(next!=0)&&)
      {
        strcpy((char *)workCntr->twoString, cnfCOMPONENT[i].nameComponent);
        strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "    ������");
      }//if
      else
      {
        //�������� ������� ��
        strcpy((char *)workCntr->twoString, cnfCOMPONENT_WL[i-next].nameComponent);
        strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "  ������ ��");
      }
      return 1;//�������� �������� ������
    }//COMPARE_COUNTER
  }//for

  return 1;
}//KadrMenuFormat_openEditWL(WorkControl *workCntr)

void WLRedactor(short cmdPosition)
{
  /*
//������������� ������������
  char txtName[50];
  FvmenuDis->EditWLPanel->Visible = true;
  FvmenuDis->ConfirmRangPanel->Visible = false;
  //��� ���� � ��������� ������� LE
  short znak = setNameIOWL(cmdPosition, txtName);//��� � ���� ������� WL
  switch(znak)
  {
  case 0:
    //�����
    FvmenuDis->PRMRadio->Checked = false;
    FvmenuDis->MINUSRadio->Checked = false;
    FvmenuDis->PLUSRadio->Checked = false;
    FvmenuDis->OTKLRadio->Checked = true;
    break;
  case 1:
    //������ ����
    FvmenuDis->PRMRadio->Checked = true;
    FvmenuDis->MINUSRadio->Checked = false;
    FvmenuDis->PLUSRadio->Checked = false;
    FvmenuDis->OTKLRadio->Checked = false;
    break;
  case 2:
    //��� ����
    FvmenuDis->PRMRadio->Checked = false;
    FvmenuDis->MINUSRadio->Checked = true;
    FvmenuDis->PLUSRadio->Checked = false;
    FvmenuDis->OTKLRadio->Checked = false;
    break;
  case 3:
    //�����
    FvmenuDis->PRMRadio->Checked = false;
    FvmenuDis->MINUSRadio->Checked = false;
    FvmenuDis->PLUSRadio->Checked = true;
    FvmenuDis->OTKLRadio->Checked = false;
    break;
  default:
    ;
  }//switch

  FvmenuDis->EditWLLabel->Caption = txtName;
  */
}//WLRedactor()

void ClickProcessEditWL()
{
//������ �������������� ��
  int isCLONWL = 0;//���� ����� ��
//  LIGHTLINEMENU = TxtStreamIdxKadr(CRR_TEXTSTREAM);//������� ����
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������

  if( LIGHTCLON >= MARKCLON_WL)
  {
    LIGHTCLON -= MARKCLON_WL;
    isCLONWL = 1;//���� ����� ��
  }//if

  short next = 0;
  while (cnfCOMPONENT[next].componentEnable)   //��� ���������� � ������������
  {
    next++;
  }//while

  short cmdPosition =0;
  for(short i=0; i<1; i++)
  {

    if(isCLONWL)
    {
      //���� ��
      LIGHTCLON = LIGHTCLON + next;
    }//if

    if(LIGHTCLON<0)//������ ���� ����������
    {
      //������ ����� �����
      LIGHTCLON = LIGHTLINEMENU;//������ ���� ����������
      break;
    }//if

    if(
      LIGHTLINEMENU <  LIGHTCLON)
    {
      //����� �� ���� �����
      LIGHTCLON = LIGHTLINEMENU;//������ ���� ����������
      break;
    }//if

    if(
      LIGHTLINEMENU >( LIGHTCLON+ RANG_CNTOPEN_CMD-1))
    {
      //����� ����� ���� �����
      LIGHTCLON = LIGHTLINEMENU - RANG_CNTOPEN_CMD+1;
      break;
    }//if

    if(isCLONWL)//���� ����� ��
    {
      cmdPosition = //������� ��������� ������� � ���� ����
        getOffsetIOCmdCnf_WL(LIGHTCLON-next) +
        LIGHTLINEMENU - LIGHTCLON +SIZE_RANGIRCMD;
      LIGHTCLON = LIGHTCLON + MARKCLON_WL - next;//������ ����� ��
    }//if(isCLONWL)//���� ����� ��
    else
    {
      cmdPosition = //������� ��������� ������� � ���� ����
        getOffsetIOCmdCnf(LIGHTCLON) +
        LIGHTLINEMENU - LIGHTCLON;
    }//else
    RANG_BIT =  cmdPosition ;//������� ��������� ������� � ���� ����
    WLRedactor(cmdPosition);//������������� ��
    return;
  }//for

  int numClon = LIGHTCLON;
  if(LIGHTCLON>=next)
  {
    //����� ��
    RANG_CNTOPEN_CMD = cnfCOMPONENT_WL[numClon-next].cntIOCmd;//�-�� �������� ����� IO ������
    //������ ����� ��
    LIGHTCLON = MARKCLON_WL +LIGHTCLON-next;
  }//if
  else
    RANG_CNTOPEN_CMD = cnfCOMPONENT[LIGHTCLON].cntIOCmd;//�-�� �������� ����� IO ������

  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_prc_editWL, NULL);//���� ������ ������ � ������ �����
  TxtStreamSetIdxKadr(CRR_TEXTSTREAM, numClon);//��������� ������ �������� �����

  ViewDiskrMenu(typeMenuEditRang);//������� ���� �����������
  ListPStr();//���������� ��������� ������

}//ClickProcessEditWL()

short  KadrMenuFormat_prc_editWL(void *pstr)
{
  WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
//������� �������������� ������� ���� ������
  //char  locTxt[20];
  short next = 0;
  short nextWL = 0;
  short cntKadr = 0;//�-�� ������

  short numCloseComp = 0;//���� ����������
  while (cnfCOMPONENT[next].componentEnable)   //��� ���������� � ������������
  {
    next++;
  }//while

  while (cnfCOMPONENT_WL[nextWL].componentEnable)   //��� ���������� � ������������ ��
  {
    nextWL++;
  }//while

  cntKadr = nextWL+ next+ RANG_CNTOPEN_CMD-1;//�-�� ������

  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    if(i==cntKadr) break;

    int numClon = 0;//LIGHTCLON;
    if(LIGHTCLON<MARKCLON_WL) numClon = LIGHTCLON;
    else numClon = LIGHTCLON -MARKCLON_WL +next;

    COMPARE_COUNTER
    {
      if(i<  numClon)
        numCloseComp = i;
      if(i>( numClon   + RANG_CNTOPEN_CMD -1))
        numCloseComp = i- RANG_CNTOPEN_CMD+1;
      if(i<  numClon || i>( numClon + RANG_CNTOPEN_CMD-1))
      {
        if(numCloseComp>=next)
        {
          //������� ��
          strcpy((char *)workCntr->twoString, cnfCOMPONENT_WL[numCloseComp-next].nameComponent);
          strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "  ������ ��");
        }
        else
        {
          strcpy((char *)workCntr->twoString, cnfCOMPONENT[numCloseComp].nameComponent);
          strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "    ������");
        }
      }//if(i<  LIGHTCLON || i>(LIGHTCLON + RANG_CNTOPEN_CMD-1))
      else{
        short cmdPosition  = 0;//������� ��������� ������� � ���� ����
        if(LIGHTCLON<MARKCLON_WL)
        {
          //������� ����� �� ������
          cmdPosition  = i- LIGHTCLON + getOffsetIOCmdCnf(numClon);
        }//if(LIGHTCLON<MARKCLON_WL)
        else{
          //������� ����� �� ��
          cmdPosition  = i+ SIZE_RANGIRCMD -numClon + getOffsetIOCmdCnf_WL(numClon-next);
        }//else

        if(setNameIOWL(cmdPosition, (char *)workCntr->twoString))//��� � ���� ������� WL
        {
          strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "    ���");
        }//if
        else
        {
          strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "    ����");
        }

      }//else

      return 1;
    }//COMPARE_COUNTER


  }//for

  return 1;
}//KadrMenuFormat_prc_editWL(WorkControl *workCntr)

void setComonDQuadro(UNS_32* cmnDQuadro)
{
//��������� ����� dquadro
  UNS_32 *tmp1 = MngWLGetLEWLtoEdit_PRM(LIGHTRANGUVV);
  memset(cmnDQuadro, 0, DQUADRO*4*2);//��������
  //����� dquadro ��� ������ ������ � ��������
  for(int i=0; i<2*DQUADRO; i++) cmnDQuadro[i] |= (tmp1[i]|tmp1[i+DQUADRO*2]|tmp1[i+DQUADRO*2+DQUADRO*2]);
}//setComonDQuadro(UNS_32* cmnDQuadro)

short setNameIOWL(int cmdPosition, char *strIO)
{
//��� � ���� ������� WL
  //��� �������
  char tmpName[50];
  strcpy(tmpName,
         nameStatusRANGIR[
           cmdPosition
         ].nameIORang
        );

  strcpy(strIO, "");
  //���� ������� LE
  short znak=SetConditionCmdPositionLE(cmdPosition);
  if(znak==2)strcpy(strIO, "- ");
  if(znak==3)strcpy(strIO, "+ ");
  strcat(strIO, tmpName);//��������� ���� ������
  return znak;
}//setNameIOWL(int cmdPosition, char *strIO)

short SetConditionCmdPositionLE(short cmdPosition)
{
  //���� ������� LE
  UNS_32*tmp1 =  MngWLGetLEWLtoEdit_PRM(LIGHTRANGUVV);//������ LE
  short znak=0;
  //����� ���� �������
  //����� ����
  if(NumBitCheckWL(cmdPosition, &(tmp1[DQUADRO*2+DQUADRO*2])))
  {
    //���� ����
    znak = 3;//���� �������
  }//if

  //����� �����
  if(NumBitCheckWL(cmdPosition, &(tmp1[DQUADRO*2])))
  {
    //���� �����
    znak = 2;//���� �������
  }//if

  if(NumBitCheckWL(cmdPosition, tmp1))
  {
    //���� prm
    znak = 1;//���� �������
  }//if

  return znak;//���� �������
}//SetConditionCmdPositionLE(cmdPosition)

void  ClickEditWLOKButton()
{
  /*
//������������� ��
//���������� ������� �� LE
//  UNS_32 *prm =  MngWLGetLEWLtoEdit_PRM(LIGHTRANGUVV);//������ LE
//MngWLGetPointerLEWLtoEdit_PRM(LIGHTRANGUVV);//������ LE
  if(FvmenuDis->PRMRadio->Checked)
    SetLEToClon(RANG_BIT, LIGHTRANGUVV, typeCmd_PRM);
  if(FvmenuDis->PLUSRadio->Checked)
    SetLEToClon(RANG_BIT, LIGHTRANGUVV, typeCmd_PLUS);
  if(FvmenuDis->MINUSRadio->Checked)
    SetLEToClon(RANG_BIT, LIGHTRANGUVV, typeCmd_MINUS);
  if(FvmenuDis->OTKLRadio->Checked)
    SetLEToClon(RANG_BIT, LIGHTRANGUVV, typeCmd_DIS);

  isRangRedactor = 2;//���� �� ������������� ��

  ViewTipPanel(1);
  */
}//ClickEditRangOKButton()

void  FinishEditWL(int isOK)
{
//��������� � ��������� �������� ��
  isRangRedactor = 0;//���� �� ������������� ������
  if(isOK)
    MngWLEndingEditArrayWIDELOG();//���� ��������� � ������� ������
  MngWideLogPrepareArrayWIDELOGtoEdit();//����������� ArrayWIDELOG � ��������������
  TxtStreamInit(&CONTROL_EWL, &KadrMenuFormat_viewLE, NULL);//����� �-�� ������ �� LE
}//FinishEditRang()

void PereinitCnfWL(short flg)
{
//�������� ������������ ��
  TxtStreamInit(&CONTROL_CNFWL,
                &KadrMenuFormat_sub, sub_menu_cnfwl);//���� control � ������ �����

  PNTCRR_TEXTSTREAM->PntStringViewer = 0;
  if(flg==0)//END
  {
    TxtStreamSetEnd(&CONTROL_CNFWL, SIZE_PAGE_VIEW);//������� �� END
  }//if
  ViewDiskrMenu(typeMenuSub);//������� ���� �����������
  LanderPStr();//���������� ��������� ������
}//PereinitCnfWL()

void OpenMenuCnfWL()
{
//������� ���� cnf ��
  TxtStreamCorrect(CRR_TEXTSTREAM);//��������� ������� control

//  CRR_TEXTSTREAM = &CONTROL_CNFWL;//����� ������� control
  SelectorTEXTCONTROL(&CONTROL_CNFWL);//���������� ������� ������ �� ��������� �����
  PereinitCnfWL(1);//�-��� �������� ������������
//  CRR_FHOME = &PereinitCnfWL;//��������� �� �-��� HOME
  SelectorFHOME(&PereinitCnfWL);//��������� �� �-��� HOME
}//OpenMenuCnf()

void  ConfigMakerWL()
{
  /*
//��������� ������������
//  LIGHTLINEMENU = TxtStreamIdxKadr(CRR_TEXTSTREAM);//������ ��� �����
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������
  short numK = GetKodCompRpzWL(LIGHTLINEMENU);//�������� �� ������ ������ ����������� �� ��� ����������

  sub_menu_tmp[SUBDATA].Line2 = &sub_menu_cnfwl;// parent
//  CRR_SUBMENU = sub_menu_tmp;//������� �������
  SelectorSUBMENU(sub_menu_tmp);//�c�������� ������� �������

  AddCompIzRpz_WL(numK);//�������� ��������� �� ����������� � ��

  FvmenuDis->Str1Label->Caption = "���������";
  FvmenuDis->Str2Label->Caption = (char *)sub_menu_cnfwl[1+SUBDATA].Line1;
  FvmenuDis->Str3Label->Caption = "��������";
  FvmenuDis->Str4Label->Caption = "";

  ResetAllButton();//�������� ��� �������
*/
}//ConfigMaker()

short GetKodCompRpzWL(short numL)
{
//�������� �� ������ ������ ����������� ��� ����������
  char ltxt[50];
  strcpy(ltxt, (char *)sub_menu_rpzWL[numL+1+SUBDATA].Line1);
  //�� � �� ����� ���� ����������
  char lowK = ((char *)(sub_menu_rpzWL[numL+1+SUBDATA].Line1))[-2];
  char hiK = ((char *)(sub_menu_rpzWL[numL+1+SUBDATA].Line1))[-1];
  return lowK + 256*hiK;
}//GetKodCompRpzWL(short numL)

void  AddCompIzRpz_WL(short numK)
{
//�������� ��������� �� ����������� � ��
  addCOMPONENT_WL(numK);//�������� ��������� � ����� numK � ������������ ��

  if( LIGHTISDENIE ||//���������
      LIGHTISPACKET);//��� �����
  else
  {
//���������������� ���� ���������� ��
//���� �� �����
    initCOMPONENT_WL(INITUST_TOPCOMP);
    MakeEmptyTopSub_menu(sub_menu_cnfwl,
                         MAX_WLCOMPONENT*sizeof(LineMenuItem));//�������� ������ ������ � top sub_menu
//����� ���� � ������
    sub_menu_cnfwl[1+SUBDATA].Line2 = (void *)&OpenMenuComponent_WL; //���� ����������
    sub_menu_cnfwl[1+SUBDATA].TypesWin = typeMenuProg;
  }//else

  PrepareAllCnfComponent_WL();//����������� ��� ���������� � ������������ ��
}//AddCompIzRpz_WL()

