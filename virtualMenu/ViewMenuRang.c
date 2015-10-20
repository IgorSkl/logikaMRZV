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
#include "virtualMenu\systemmenudef.h"
#include "component\componentdef.h"
#include "virtualMenu\rangmanagerdef.h"
#include "virtualMenu\ustmanagerdef.h"

#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "virtualMenu\rangmanagerfnc.h"
#include "virtualMenu\wideLogManagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"

#include "virtualMenu\viewMenuSub.h"
#include "virtualMenu\viewMenuRang.h"
#include "virtualMenu\viewMenuWideLog.h"
#include "virtualMenu\viewMenuTip.h"

#include "psupervisor\psupervisor.h"

#include "..\bazis.h"

#include "toSpeedOptim.h"

//����� ���� ��� ��������������
#define RANG_BIT         LIGHTMNGUOFFSET
//�-�� �������� ������
#define RANG_CNTOPEN_CMD LIGHTMNGUBAZA

extern IONAMESTATUS_RANGIR  nameStatusRANGIR[];
extern LineMenuItem sub_menu_editrng[];//�������� ������

extern char titleRang[];
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern StreamControl controlStruct_tip;//������ ���������

extern int workerUniversal1;//������ ��� ���������
extern int workerUniversal2;//������ ��� ���������
extern UNS_32 pActualCMD[];//�������
extern UNS_32 pRDIScmdMaska[];//��������������
extern UNS_32 pAPVcmdMaska[];//APV
extern UNS_32 pUROVcmdMaska[];//UROV
//extern UNS_32 pP1OFcmdMaska[];//P1OF
//extern UNS_32 pP2OFcmdMaska[];//P2OF
//extern UNS_32 pP3OFcmdMaska[];//P3OF

extern UNS_32 selectorDVLow;//�������� �� ��������-���������� ��� �� 16 DV
extern UNS_32 selectorDVMidd;//�������� �� ��������-���������� ��� cp 16 DV
extern UNS_32 selectorDVHi;//�������� �� ��������-���������� ��� ct 16 DV
extern UNS_32 rele_bdvv1;//�������� ����

UNS_32 selectorUVVLow;//�������� UVV ��������-���������� ��� �� 16 UVV
UNS_32 selectorUVVMidd;//�������� UVV ��������-���������� ��� cp 16 UVV
UNS_32 selectorUVVHi;//�������� UVV ��������-���������� ��� ct 16 UVV

char isRangRedactor = 0;//���� �� ������������� ������

short  KadrMenuFormat_viewRang(void *pstr)//(WorkControl *workCntr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  //������������� �������� ������
  Universal_viewRang(workCntr, MngRangGetPointerUVVRANGIRtoEdit(LIGHTRANGUVV));

  return 1;

}//KadrMenuFormat_viewRang(WorkControl *workCntr)

short  KadrMenuFormat_viewActual(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  //������������� �������� ������
  Universal_viewRang(workCntr, pActualCMD);

  return 1;

}//KadrMenuFormat_viewActual(WorkControl *workCntr)

short  KadrMenuFormat_viewActualDV(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  //������������� �������� UVV
  Universal_viewUVV(pstr, "��", 1);
  return 1;
}//KadrMenuFormat_viewActualDV(WorkControl *workCntr)
short  KadrMenuFormat_viewActualRele(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  //������������� �������� UVV
  Universal_viewUVV(pstr, "����", 1);
  return 1;
}//KadrMenuFormat_viewActualRele(WorkControl *workCntr)

void  Universal_viewUVV(void *pstr, char *inStr, short offset)
{
 WorkControl *workCntr = (WorkControl *)pstr;
  //������������� �������� UVV
  short cntKadr = 0;//�-�� ������
  short cntKadrLow = 0;//�-�� ������ Low
  short cntKadrMidd = 0;//�-�� ������ Midd
  short cntKadrHi = 0;//�-�� ������ Hi
  short isEmpty = 0;
//unsigned int testDV = 255-1;
 char nameUpr[30];
 char locTxt[30];
//��������� �-�� ������
  workerUniversal1 = 0;//������ ��� ���������
  MultiBitWorkerHostWord( &selectorUVVLow, &pfWorker1);
  cntKadrLow = workerUniversal1;//�-�� ������
  workerUniversal1 = 0;//������ ��� ���������
  MultiBitWorkerHostWord( &selectorUVVMidd, &pfWorker1);
  cntKadrMidd = workerUniversal1;//�-�� ������
  workerUniversal1 = 0;//������ ��� ���������
  MultiBitWorkerHostWord( &selectorUVVHi, &pfWorker1);
  cntKadrHi = workerUniversal1;//�-�� ������
  cntKadr = cntKadrLow + cntKadrMidd + cntKadrHi;
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
        return;
      }//if

//      int tt1 = selectorUVVLow;
//      int tt2 = selectorUVVMidd;
//      int tt3 = selectorUVVHi;
      strcpy(nameUpr, inStr);
      //����� ������ i-� �������� �������
      workerUniversal2 = i;//������ ��� ���������
      workerUniversal1 = 0;
      if(MultiBitWorkerHostWord(&selectorUVVLow, &pfWorker2)){
         //����� ��� �������
         sprintf(locTxt, "%d", workerUniversal2+offset);
         strcat(nameUpr, locTxt);
         strcpy((char *)workCntr->twoString, nameUpr);
      }//if
      else{
      workerUniversal2 = i-cntKadrLow;//������ ��� ���������
      workerUniversal1 = 0;
      if(MultiBitWorkerHostWord(&selectorUVVMidd, &pfWorker2)){
         //����� ��� �������
         sprintf(locTxt, "%d", workerUniversal2+16+offset);
         strcat(nameUpr, locTxt);
         strcpy((char *)workCntr->twoString, nameUpr);
      }//if
      else{
      workerUniversal2 = i-cntKadrLow-cntKadrMidd;//������ ��� ���������
      workerUniversal1 = 0;
      MultiBitWorkerHostWord(&selectorUVVHi, &pfWorker2);
         //����� ��� �������
         sprintf(locTxt, "%d", workerUniversal2+16+16+offset);
         strcat(nameUpr, locTxt);
         strcpy((char *)workCntr->twoString, nameUpr);
      }//else
      }//else
      return;
    }//COMPARE_COUNTER
  }//for

  return;
}//Universal_viewUVV(char *inStr, short offset)

short  KadrMenuFormat_viewRDIS(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� ����� ��������������
  RESET_COUNTER;//����� ���������
  //������������� �������� ������
  Universal_viewRang(workCntr, pRDIScmdMaska);

  return 1;

}//KadrMenuFormat_viewRDIS(void *pstr)

short  KadrMenuFormat_viewAPV(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� ����� 
  RESET_COUNTER;//����� ���������
  //������������� �������� ������
  Universal_viewRang(workCntr, pAPVcmdMaska);

  return 1;

}//KadrMenuFormat_viewAPV(void *pstr)

short  KadrMenuFormat_viewUROV(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� ����� 
  RESET_COUNTER;//����� ���������
  //������������� �������� ������
  Universal_viewRang(workCntr, pUROVcmdMaska);

  return 1;

}//KadrMenuFormat_viewUROV(void *pstr)

short  KadrMenuFormat_viewP1OF(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� ����� 
  RESET_COUNTER;//����� ���������
  //������������� �������� ������
//  Universal_viewRang(workCntr, pP1OFcmdMaska);

  return 1;

}//KadrMenuFormat_viewP1OF(void *pstr)

short  KadrMenuFormat_viewP2OF(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� ����� 
  RESET_COUNTER;//����� ���������
  //������������� �������� ������
//  Universal_viewRang(workCntr, pP2OFcmdMaska);

  return 1;

}//KadrMenuFormat_viewP2OF(void *pstr)

short  KadrMenuFormat_viewP3OF(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� ����� 
  RESET_COUNTER;//����� ���������
  //������������� �������� ������
//  Universal_viewRang(workCntr, pP3OFcmdMaska);

  return 1;

}//KadrMenuFormat_viewP3OF(void *pstr)

void  Universal_viewRang(void *pstr, UNS_32 *pDQuadro)
{
 WorkControl *workCntr = (WorkControl *)pstr;
  //������������� �������� ������
  short cntKadr = 0;//�-�� ������
  short isEmpty = 0;
//��������� �-�� ������
  workerUniversal1 = 0;//������ ��� ���������
  MultiBitWorkerHostQuadro(
    pDQuadro, &pfWorker1);
  cntKadr = workerUniversal1;//�-�� ������
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
        return;
      }//if

      //����� ������ i-� �������� �������
      workerUniversal2 = i;//������ ��� ���������
      workerUniversal1 = 0;
      MultiBitWorkerHostQuadro(
        pDQuadro, &pfWorker2);
      //����� ��� �������
      strcpy((char *)workCntr->twoString, nameStatusRANGIR[workerUniversal2].nameIORang);
      return;
    }//COMPARE_COUNTER
  }//for
}//Universal_viewRang(WorkControl *workCntr, UNS_32 *pDQuadro)

void OpenMenuViewRangDV()
{
//������� ���� rang DV
  LIGHTRANGUVV = LIGHTLINEMENU;//����� ��� ������
  sprintf(titleRang, "��%d", LIGHTLINEMENU +1);//������� ����

  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);//����������� ArrayRANGIR � ��������������

  TxtStreamCorrect(CRR_TEXTSTREAM);//��������� ������� control
  SelectorTEXTCONTROL(&CONTROL_VRNG);//���������� ������� ������ �� ��������� �����

  SelectorFHOME(&PereinitViewRang);//��������� �� �-��� HOME

  InitFHOME(1);//��������

}//OpenMenuViewRangDV()

void OpenMenuViewRangRele()
{
//������� ���� rang Rele
  LIGHTRANGUVV = LIGHTLINEMENU + DV_TOTAL;//����� ��� ������
  sprintf(titleRang, "�%d", LIGHTLINEMENU +1);//������� ����

  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);//����������� ArrayRANGIR � ��������������

  TxtStreamCorrect(CRR_TEXTSTREAM);//��������� ������� control
  SelectorTEXTCONTROL(&CONTROL_VRNG);//���������� ������� ������ �� ��������� �����
  SelectorFHOME(&PereinitViewRang);//��������� �� �-��� HOME

  InitFHOME(1);//��������

}//OpenMenuViewRangRele()

void OpenMenuViewRangCDI()
{
//������� ���� rang CDI
  LIGHTRANGUVV = LIGHTLINEMENU + DV_TOTAL + RELE_TOTAL;//����� ��� ������
  sprintf(titleRang, "���%d", LIGHTLINEMENU +1);//������� ����

  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);//����������� ArrayRANGIR � ��������������

  TxtStreamCorrect(CRR_TEXTSTREAM);//��������� ������� control
  SelectorTEXTCONTROL(&CONTROL_VRNG);//���������� ������� ������ �� ��������� �����
  SelectorFHOME(&PereinitViewRang);//��������� �� �-��� HOME

  InitFHOME(1);//��������

}//OpenMenuViewRangCDI()

void OpenMenuViewActual()
{
//������� ���� �������
  TxtStreamCorrect(CRR_TEXTSTREAM);//��������� ������� control
  SelectorTEXTCONTROL(&CONTROL_ACT);//���������� ������� ������ �� ��������� �����
  SelectorFHOME(&PereinitViewActual);//��������� �� �-��� HOME

  InitFHOME(1);//��������
}//OpenMenuViewActual()

void OpenMenuViewActualDV()
{
//������� ���� ������� DV
 selectorUVVLow  = selectorDVLow;//�������� UVV ��������-���������� ��� �� 16 UVV
 selectorUVVMidd = selectorDVMidd;//�������� UVV ��������-���������� ��� cp 16 UVV
 selectorUVVHi   = selectorDVHi;//�������� UVV ��������-���������� ��� ct 16 UVV
  TxtStreamCorrect(CRR_TEXTSTREAM);//��������� ������� control
  SelectorTEXTCONTROL(&CONTROL_ACT);//���������� ������� ������ �� ��������� �����
  SelectorFHOME(&PereinitViewActualDV);//��������� �� �-��� HOME

  InitFHOME(1);//��������
}//OpenMenuViewActualDV()

void OpenMenuViewActualRele()
{
//������� ���� ������� DV
 selectorUVVLow  = rele_bdvv1;//�������� UVV ��������-���������� ��� �� 16 UVV
 selectorUVVMidd = 0;//�������� UVV ��������-���������� ��� cp 16 UVV
 selectorUVVHi   = 0;//�������� UVV ��������-���������� ��� ct 16 UVV
  TxtStreamCorrect(CRR_TEXTSTREAM);//��������� ������� control
  SelectorTEXTCONTROL(&CONTROL_ACT);//���������� ������� ������ �� ��������� �����
  SelectorFHOME(&PereinitViewActualRele);//��������� �� �-��� HOME

  InitFHOME(1);//��������
}//OpenMenuViewActualRele()

void PereinitViewActual(short flg)
{
//�-��� �������� �������
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewActual, NULL);//���� ������ ������ � ������ �����
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//������� ���� �����������
}//PereinitViewActual(short flg)
void PereinitViewActualDV(short flg)
{
//�-��� �������� ������� DV
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewActualDV, NULL);//���� ������ ������ � ������ �����
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//������� ���� �����������
}//PereinitViewActualDV(short flg)
void PereinitViewActualRele(short flg)
{
//�-��� �������� ������� DV
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewActualRele, NULL);//���� ������ ������ � ������ �����
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//������� ���� �����������
}//PereinitViewActualRele(short flg)

void OpenMenuViewRDIS()
{
//������� ���� ��������������
  LIGHTRANGUVV = REGDIS_SM;//����� ��� ������
  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);//����������� pRDIScmdMaska � ��������������

  TxtStreamCorrect(CRR_TEXTSTREAM);//��������� ������� control
  SelectorTEXTCONTROL(&CONTROL_RDIS);//���������� ������� ������ �� ��������� �����
  SelectorFHOME(&PereinitViewRDIS);//��������� �� �-��� HOME

  InitFHOME(1);//��������
}//OpenMenuViewRDIS()

void PereinitViewRDIS(short flg)
{
//�-��� �������� ��������������
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewRDIS, NULL);//���� ������ ������ � ������ �����
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//������� ���� �����������
}//PereinitViewRDIS(short flg)

void OpenMenuViewAPV()
{
//������� ���� ��������������
  LIGHTRANGUVV = PUSKAPV_SM;//����� ��� ������
  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);//����������� � ��������������

  TxtStreamCorrect(CRR_TEXTSTREAM);//��������� ������� control
  SelectorTEXTCONTROL(&CONTROL_APV);//���������� ������� ������ �� ��������� �����
  SelectorFHOME(&PereinitViewAPV);//��������� �� �-��� HOME

  InitFHOME(1);//��������
}//OpenMenuViewAPV()

void PereinitViewAPV(short flg)
{
//�-��� �������� APV
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewAPV, NULL);//���� ������ ������ � ������ �����
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//������� ���� �����������
}//PereinitViewAPV(short flg)

void OpenMenuViewUROV()
{
//������� ���� ��������������
  LIGHTRANGUVV = PUSKUROV_SM;//����� ��� ������
  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);//����������� � ��������������

  TxtStreamCorrect(CRR_TEXTSTREAM);//��������� ������� control
  SelectorTEXTCONTROL(&CONTROL_UROV);//���������� ������� ������ �� ��������� �����
  SelectorFHOME(&PereinitViewUROV);//��������� �� �-��� HOME

  InitFHOME(1);//��������
}//OpenMenuViewAPV()

void PereinitViewUROV(short flg)
{
//�-��� �������� APV
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewUROV, NULL);//���� ������ ������ � ������ �����
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//������� ���� �����������
}//PereinitViewUROV(short flg)

void OpenMenuViewP1OF()
{
//������� ���� ��������������
  LIGHTRANGUVV = PUSK1OF_SM;//����� ��� ������
  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);//����������� � ��������������

  TxtStreamCorrect(CRR_TEXTSTREAM);//��������� ������� control
  SelectorTEXTCONTROL(&CONTROL_P1OF);//���������� ������� ������ �� ��������� �����
  SelectorFHOME(&PereinitViewP1OF);//��������� �� �-��� HOME

  InitFHOME(1);//��������
}//OpenMenuViewP1OF()

void PereinitViewP1OF(short flg)
{
//�-��� �������� APV
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewP1OF, NULL);//���� ������ ������ � ������ �����
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//������� ���� �����������
}//PereinitViewP1OF(short flg)

void OpenMenuViewP2OF()
{
//������� ���� ��������������
  LIGHTRANGUVV = PUSK2OF_SM;//����� ��� ������
  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);//����������� � ��������������

  TxtStreamCorrect(CRR_TEXTSTREAM);//��������� ������� control
  SelectorTEXTCONTROL(&CONTROL_P2OF);//���������� ������� ������ �� ��������� �����
  SelectorFHOME(&PereinitViewP2OF);//��������� �� �-��� HOME

  InitFHOME(1);//��������
}//OpenMenuViewP1OF()

void PereinitViewP2OF(short flg)
{
//�-��� �������� APV
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewP2OF, NULL);//���� ������ ������ � ������ �����
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//������� ���� �����������
}//PereinitViewP2OF(short flg)

void OpenMenuViewP3OF()
{
//������� ���� ��������������
  LIGHTRANGUVV = PUSK3OF_SM;//����� ��� ������
  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);//����������� � ��������������

  TxtStreamCorrect(CRR_TEXTSTREAM);//��������� ������� control
  SelectorTEXTCONTROL(&CONTROL_P3OF);//���������� ������� ������ �� ��������� �����
  SelectorFHOME(&PereinitViewP3OF);//��������� �� �-��� HOME

  InitFHOME(1);//��������
}//OpenMenuViewP3OF()

void PereinitViewP3OF(short flg)
{
//�-��� �������� APV
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewP3OF, NULL);//���� ������ ������ � ������ �����
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//������� ���� �����������
}//PereinitViewP3OF(short flg)

void PereinitViewRang(short flg)
{
//�-��� �������� rang
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_viewRang, NULL);//���� ������ ������ � ������ �����
  //if(flg==1)
  ViewDiskrMenu(typeMenuSub);//������� ���� �����������
}//PereinitReg()

short  KadrMenuFormat_prc_editrang(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
//������� ��������������
  short next = 0;
  short cntKadr = 0;//�-�� ������

  short numCloseComp = 0;//���� ����������
  while (cnfCOMPONENT[next].componentEnable)   //��� ���������� � ������������
  {
    next++;
  }//while

  cntKadr = next+ RANG_CNTOPEN_CMD-1;//�-�� ������

  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    if(i==cntKadr) break;
    COMPARE_COUNTER
    {
      if(i<  LIGHTCLON)numCloseComp = i;
      if(i>( LIGHTCLON   + RANG_CNTOPEN_CMD -1)) numCloseComp = i- RANG_CNTOPEN_CMD+1;
      if(i<  LIGHTCLON || i>(LIGHTCLON + RANG_CNTOPEN_CMD-1))
      {
        strcpy((char *)workCntr->twoString, cnfCOMPONENT[numCloseComp].nameComponent);
        strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "    ������");
      }
      else{
        short cmdPosition  = //������� ��������� ������� � ���� ����
        i-LIGHTCLON + getOffsetIOCmdCnf(LIGHTCLON);

        strcpy((char *)workCntr->twoString,
        nameStatusRANGIR[
          cmdPosition
        ].nameIORang
              );
//�������� ���� ������������
        if(NumBitCheckQuadro(cmdPosition,
        MngRangGetPointerUVVRANGIRtoEdit(LIGHTRANGUVV)
                            )) //�������� ���� �� ��� �������
        {
          strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "    ���");
        }//if
        else{
          strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "    ����");
        }

      }//else


      return 1;
    }//COMPARE_COUNTER
  }//for

  return 1;
}//KadrMenuFormat_prc_editrang(WorkControl *workCntr)

short  KadrMenuFormat_openEditRang(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    short next = 0;
    while (cnfCOMPONENT[next].componentEnable)   //��� ���������� � ������������
    {
      next++;
    }//while
    if(next==0)
    {
      strcpy((char *)workCntr->twoString, "������������");
      strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "������");
      if(i==1)break;
    }//if
    else
    {
      if(i==next) break;
    }//else

    COMPARE_COUNTER
    {
      if(next!=0)
      {
        strcpy((char *)workCntr->twoString, cnfCOMPONENT[i].nameComponent);
        strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, "    ������");
      }//if
      return 1;//�������� �������� ������
    }//COMPARE_COUNTER
  }//for

  return 1;
}//KadrMenuFormat_openEditRang(WorkControl *workCntr)

extern LineMenuItem sub_menu_viewDV[];

void ClickOpenEditRang(UNS_32 *cmdUVV)
{
  /*
//�������� ��� ArrayRANGIR ����� ��� ��� ��������������
  short  findClon = -1; //����� ���� ��� ����������������
  UNS_32 tmp=0;
  for(int i=0; i<DQUADRO; i++) tmp|=cmdUVV[i];

  if(tmp)
  {
    //����� ������ i-� �������� �������
    workerUniversal2 = TxtStreamIdxKadr(CRR_TEXTSTREAM);
    workerUniversal1 = 0;
    MultiBitWorkerHostQuadro(cmdUVV, &pfWorker2);

//����� ���� ��� ����������������
    short next = 0;
    while (cnfCOMPONENT[next].componentEnable)   //��� ���������� � ������������
    {
      if(getOffsetIOCmdCnf(next)>workerUniversal2) break;
      next++;
    }//while
    findClon = next-1;
  }//if

//������� �������������� ������
  LIGHTCLON = -1;//������ ���� ����������

//�-��� �������� rang
  SelectorTEXTCONTROL(&CONTROL_ERNG);//���������� ������� ������ �� ��������� �����

//������� sub_menu � ����� ��� parent
  sub_menu_editrng[SUBDATA].Line2 = CRR_SUBMENU;

   SelectorSUBMENU(sub_menu_editrng);//�c�������� ������� �������

  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_openEditRang, NULL);//���� ������ ������ � ������ �����
  if(findClon>0)
    TxtStreamSetIdxKadr(CRR_TEXTSTREAM, findClon);//��������� ������ �������� �����

  ViewDiskrMenu(typeMenuEditRang);//������� ���� �����������
  ListPStr();//���������� ��������� ������

  FvmenuDis->TipPanel->Visible = true;
  ViewTipPanel(0);//������ ��������� TipPanel
  */
}//ClickOpenEditRang(UNS_32 *cmdUVV)

void ClickProcessEditRang()
{
//������ �������������� ������
  SelectorCRRLIGHTLINE();//����� ������������ ������ �������� ����� ������

  if(LIGHTCLON<0)//������ ���� ����������
  {
    LIGHTCLON = LIGHTLINEMENU;//������ ���� ����������
  }//if
  else
  {
    for(short i=0; i<1; i++)
    {
      if(
        LIGHTLINEMENU<  LIGHTCLON)
      {
        LIGHTCLON = LIGHTLINEMENU;//������ ���� ����������
        break;
      }
      if(
        LIGHTLINEMENU >( LIGHTCLON+ RANG_CNTOPEN_CMD-1))
      {
        LIGHTCLON = LIGHTLINEMENU - RANG_CNTOPEN_CMD+1;
        break;
      }
      short cmdPosition = RANG_BIT=//������� ��������� ������� � ���� ����
                            getOffsetIOCmdCnf(LIGHTCLON) +
                            LIGHTLINEMENU - LIGHTCLON;
      RangRedactor(cmdPosition);//������������� ������������
      return;
    }//for
  }//else

  RANG_CNTOPEN_CMD = cnfCOMPONENT[LIGHTCLON].cntIOCmd;//�-�� �������� �����

  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_prc_editrang, NULL);//���� ������ ������ � ������ �����
  TxtStreamSetIdxKadr(PNTCRR_TEXTSTREAM, LIGHTCLON);//��������� ������ �������� �����

  ViewDiskrMenu(typeMenuEditRang);//������� ���� �����������
  ListPStr();//���������� ��������� ������

  ViewTipPanel(0);//������ ��������� TipPanel
}//ClickProcessEditRang()

void RangRedactor(short cmdPosition)
{
  /*
//������������� ������������
  FvmenuDis->EditRangPanel->Visible = true;
  FvmenuDis->ConfirmRangPanel->Visible = false;
  FvmenuDis->EditRangLabel->Caption =
    nameStatusRANGIR[
      cmdPosition
    ].nameIORang;
  if(NumBitCheckQuadro(cmdPosition,
                       MngRangGetPointerUVVRANGIRtoEdit(LIGHTRANGUVV)
                      )) //�������� ���� �� ��� �������
  {
    FvmenuDis->RangCheck->Checked = true;
    FvmenuDis->RangCheck->Caption = "���";
  }//if
  else
  {
    FvmenuDis->RangCheck->Checked = false;
    FvmenuDis->RangCheck->Caption = "����";
  }
*/
}//RangRedactor()

void  ClickEditRangOKButton()
{
  /*
//������������� ������������
//������ ��������� ������� ������������
  if(FvmenuDis->RangCheck->Checked)
  {
    NumBitSettingQuadro(RANG_BIT,
                        MngRangGetPointerUVVRANGIRtoEdit(LIGHTRANGUVV)
                       ); //��������� ���� �� ��� �������
  }
  else
    NumBitClearingQuadro(RANG_BIT,
                         MngRangGetPointerUVVRANGIRtoEdit(LIGHTRANGUVV)
                        ); //����� ���� �� ��� �������

  ApplyDVMask(LIGHTRANGUVV);//�������� ����� �� DV

  RangRedactor(RANG_BIT);//���������� ������������

  isRangRedactor = 1;//���� �� ������������� ������

  ViewTipPanel(0);
*/
}//ClickEditRangOKButton()

void  FinishEditRang(int isOK)
{
//��������� � ��������� �������� ������
  isRangRedactor = 0;//���� �� ������������� ������
  if(isOK){
     MngRangEndingEditArrayRANGIR(LIGHTRANGUVV);//���� ��������� � ������� ������
     SaveCRCrang();//��������� CRC ������
     PrepareBOBV();//����������� ���� ����, ���� ���
          }//if
  MngRangPrepareArrayRANGIRtoEdit(LIGHTRANGUVV);
  TxtStreamInit(&CONTROL_VRNG, &KadrMenuFormat_viewRang, NULL);//����� �-�� ������ �� ���
}//FinishEditRang()

