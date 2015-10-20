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

#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "virtualMenu\rangmanagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"

#include "virtualMenu\viewMenuSub.h"
#include "virtualMenu\viewMenuRang.h"
#include "virtualMenu\viewMenuReg.h"
#include "virtualMenu\viewMenuWideLog.h"
#include "virtualMenu\viewMenuTip.h"

#include "..\bazis.h"

#include "toSpeedOptim.h"
#include "toSpeedDIS.h"

extern REGISTRATOR_DIS registrator_dis;//������ ���
//������ ���� � ������� ������������ ���� ����� ����������� ������
extern IONAMESTATUS_RANGIR  nameStatusRANGIR[];

void PereinitReg(short flg);

short  KadrMenuFormat_reg(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  ELEMENT_DIS tmpDStr;

  UNS_32 tmpTmp[DQUADRO];//�������������
  UNS_32 cmdTmpOld[DQUADRO];//������� old

  UNS_32 IntElement[DQUADRO];

  RESET_COUNTER;//����� ���������
  //������������ old
  memcpy(cmdTmpOld, registrator_dis.title_dis.oldDIS, 4*DQUADRO);

  int len_dis = registrator_dis.title_dis.len_dis;//����� ���� ���
  if(len_dis==0)//����� ���� ���
                 return -1;
  for(int i=0; i<len_dis; i++){
    memcpy((char*)&tmpDStr, (char*)&(registrator_dis.bodyDIS[i]), sizeof(ELEMENT_DIS));//��������� ������
    memcpy(IntElement, tmpDStr.pActualCMD, 4*DQUADRO);//����������� �������

    CNTRLOC_USER1 = tmpDStr.reltime;//�����
    for(int i=0; i<DQUADRO; i++) tmpTmp[i] = IntElement[i]^cmdTmpOld[i];//������������ �������������

    if(KadrFinder(tmpTmp, &KadrMaker,
                  workCntr,
                  IntElement
                 )) break;//���� �����������

    memcpy(cmdTmpOld, tmpDStr.pActualCMD, 4*DQUADRO);//����������� �������

  }//for

  return 1;
}//KadrFormat(WorkControl *workCntr)

/**********************************************
�������-�������� ��� ���������
����������� ����� ������� �� ������
idx - ������ ��������� ����
����� - 0-�� �������� ���������
**********************************************/
void KadrMaker(short idx, void *pstr, UNS_32 *integE)
{
  char locTxt[100];

 WorkControl *workCntr = (WorkControl *)pstr;
  sprintf(locTxt, "// %d�� ", CNTRLOC_USER1);//�����
  char tmpOst = idx%32;//������� ������ ���� � �����
  if((  integE[(idx - tmpOst)/32] & (1<<tmpOst))!=0)
  {
    strcat(locTxt, "+++������");//������ ������
    strcpy((char *)workCntr->twoString, locTxt);
  }//if
  else
  {
    strcat(locTxt, "---����");//������ ������
    strcpy((char *)workCntr->twoString, locTxt);
  }

  strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, 
         "\\\\");//������ ������
  strcat((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, 
//locTxt
         nameStatusRANGIR[idx].nameIORang
        );

  return ;//�������� ��������

}//KadrMaker()

/**********************************************
������� �������� ��� ����� ������������
pQuadro - ��������� �� ������ INTU[4]
pfW - ��������� �� �������-���������
�������-�������� �������� ������ � ���������� �������
���� �������-�������� ��������� 1 �� MultiBitWorker �����������
**********************************************/
char KadrFinder(UNS_32 *pQuadro,
                void (*pKadrMaker)(short , void *, UNS_32 *),
                void *pstr,
                UNS_32 *integerE
               )
{
  short cntBit=0;//������� ���
 WorkControl *workCntr = (WorkControl *)pstr;
  for (char i=0; i<DQUADRO; i++)
  {
    if (pQuadro[i]==0)
    {
      cntBit+=32;
      continue;
    }//if (pQuadro[i]==0)
    else
    {
      for (char b=0; b<32; b++)
      {
        if (pQuadro[i]&(1<<b))
        {
          //���� �������
          COMPARE_COUNTER //�������� �������� ������
          { (*pKadrMaker)(cntBit, workCntr, integerE); return 1; }//�������� ��������
        }//if (pQuadro[i]&(1<<b))
        cntBit++;
      }//for
    }
  }//for
  return 0;
}//KadrFinder()

void OpenMenuReg()
{
//������� ���� reg
  TxtStreamCorrect(CRR_TEXTSTREAM);//��������� ������� control
//  CRR_TEXTSTREAM = &CONTROL_DIS;//������� control
  SelectorTEXTCONTROL(&CONTROL_DIS);//���������� ������� ������ �� ��������� �����
  PereinitReg(1);//�-��� �������� reg

//  CRR_FHOME = &PereinitReg;//��������� �� �-��� HOME
  SelectorFHOME(&PereinitReg);//��������� �� �-��� HOME
}//OpenMenuReg()

void PereinitReg(short flg)
{
//�-��� �������� reg
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_reg, NULL);//���� ������ ������ � ������ �����
  if(flg==1)
    ViewDiskrMenu(typeMenuReg);//������� ���� �����������
}//PereinitReg()

