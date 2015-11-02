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

#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\rangmanagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"

#include "virtualMenu\viewMenuTip.h"
#include "virtualMenu\viewMenuRang.h"
#include "virtualMenu\viewMenuWideLog.h"

#include "toSpeedOptim.h"

extern IONAMESTATUS_RANGIR  nameStatusRANGIR[];
extern int workerUniversal1;//������ ��� ���������
extern int workerUniversal2;//������ ��� ���������

StreamControl controlStruct_tip;//������ ���������

void PgUpTipPanel()
{
//������ ��������� TipPanel
  controlStruct_tip.topStrPnt = TxtStreamPgUpButtonPrepare(&controlStruct_tip);//����������
  ViewDiskrTip();//������� ���� TipPanel
}//PgUpTipPanel()

void PgDownTipPanel()
{
//������ ��������� TipPanel
  controlStruct_tip.topStrPnt = TxtStreamPgDownButtonPrepare(&controlStruct_tip);//����������
  ViewDiskrTip();//������� ���� TipPanel
}//PgDownTipPanel()

void ViewTipPanel(int isRangORwl)
{
//������ ��������� TipPanel
 if(isRangORwl)
  TxtStreamInit(&controlStruct_tip, &KadrMenuFormat_viewLE, NULL);//���� ������ ������ � ������ �����
 else
  TxtStreamInit(&controlStruct_tip, &KadrMenuFormat_viewRang, NULL);//���� ������ ������ � ������ �����
  ViewDiskrTip();//������� ���� TipPanel
}//ViewTipPanel()

void ViewDiskrTip()
{
/*
//������� ���� TipPanel
//������� ��������
  WorkVariantChar workVariantCharLoc;//����� �����

  int tmp = TxtStreamIteratorBegin((void *)&workVariantCharLoc, &controlStruct_tip);//�������� ����

  if(tmp==-1) //����� ��� ��� ������
  {
    FvmenuDis->Str1PnlLabel->Caption = "�����";
    return ;
  }//if

  if(tmp==0) //��������� ����� �����
  {
    return ;
  }//if
  //�������� ���������
  FvmenuDis->Str1PnlLabel->Caption = workVariantCharLoc.TwoString[0];

  if(TxtStreamIteratorMidle(&controlStruct_tip)==0) //�������� ����
  {
    //��������� ����� �����
    controlStruct_tip.StpStringViewer = 0;//stp �������� ������
    FvmenuDis->Str2PnlLabel->Caption = "";
    return ;
  }//if
  //�������� ���������
  FvmenuDis->Str2PnlLabel->Caption = workVariantCharLoc.TwoString[0];

  TxtStreamIteratorEnd(&controlStruct_tip);//����� ��������

  controlStruct_tip.StpStringViewer = 1;//stp �������� ������
*/

}//ViewDiskrTip()

