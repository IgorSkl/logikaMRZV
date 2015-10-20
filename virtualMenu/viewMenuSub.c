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

#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\systemmenufnc.h"

#include "virtualMenu\viewMenuTip.h"

#include "..\bazis.h"

short  KadrMenuFormat_sub(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//������������� �����
  void *tmpP = NULL;
  RESET_COUNTER;//����� ���������
  for(int i=0;; i++)
  {
//�������� �����������
    tmpP = ((LineMenuItem *)workCntr->userPoint)[i+1+SUBDATA].Line1;
    if(tmpP==NULL)break;
    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, (char *)tmpP);
      return 1;//�������� �������� ������
    }//COMPARE_COUNTER
  }//for

  return 1;
}//KadrMenuFormat_sub(WorkControl *workCntr)

void ViewDiskrMenuSub()
{
  /*
//������� ��������
  WorkVariantChar workVariantCharLoc;//����� �����

  int tmp = TxtStreamIteratorBegin((void *)&workVariantCharLoc, CRR_TEXTSTREAM);//�������� ����

  if(tmp==-1) //����� ��� ��� ������
  {
    FvmenuDis->Str1Label->Caption = "�����";
    return ;
  }//if

  if(tmp==0) //��������� ����� �����
  {
    return ;
  }//if
  //�������� ���������
  FvmenuDis->Str1Label->Caption = workVariantCharLoc.TwoString[0];

  if(TxtStreamIteratorMidle(CRR_TEXTSTREAM)==0) //�������� ����
  {
    //��������� ����� �����
    PNTCRR_TEXTSTREAM->StpStringViewer = 0;//stp �������� ������
    FvmenuDis->Str2Label->Caption = "";
    FvmenuDis->Str3Label->Caption = "";
    FvmenuDis->Str4Label->Caption = "";
    return ;
  }//if
  //�������� ���������
  FvmenuDis->Str2Label->Caption = workVariantCharLoc.TwoString[0];

  if(TxtStreamIteratorMidle(CRR_TEXTSTREAM)==0) //�������� ����
  {
    //��������� ����� �����
    PNTCRR_TEXTSTREAM->StpStringViewer = 1;//stp �������� ������
    FvmenuDis->Str3Label->Caption = "";
    FvmenuDis->Str4Label->Caption = "";
    return ;
  }//if
  //�������� ���������
  FvmenuDis->Str3Label->Caption = workVariantCharLoc.TwoString[0];

  if(TxtStreamIteratorMidle(CRR_TEXTSTREAM)==0)
  {
    //��������� ����� �����
    PNTCRR_TEXTSTREAM->StpStringViewer = 2;//stp �������� ������
    FvmenuDis->Str4Label->Caption = "";
    return ;
  }//if
  //�������� ���������
  FvmenuDis->Str4Label->Caption = workVariantCharLoc.TwoString[0];

  TxtStreamIteratorEnd(CRR_TEXTSTREAM);//����� ��������

  PNTCRR_TEXTSTREAM->StpStringViewer = 3;//stp �������� ������
*/
}//ViewDiskrMenuSub()

void SetPgUpButton(short flg)
{
  /*
//�������� �����
//������
  short typeWin = PNTCRR_SUBMENU(SUBDATA).TypesWin;
  PNTCRR_TEXTSTREAM->topStrPnt = TxtStreamPgUpButtonPrepare(CRR_TEXTSTREAM);//����������
  switch(typeWin)
  {
  case typeMenuReg:
  case typeMenuList:
  case typeMenuEditRang:
  case typeMenuEditWL:
  case typeMenuViewActual:
  case typeMenuViewRDISMaska:
  case typeMenuViewActualDV:
  case typeMenuViewActualRele:
    ViewDiskrMenu(typeWin);//������� ���� �����������
    if(typeWin==typeMenuReg || typeWin==typeMenuViewActual) break;
    else ListPStr();//������ � ��������
    break;

  case typeMenuCnfWL:
  case typeMenuCnf:
  case typeMenuSub:
  case typeMenuViewRangDV:
  case typeMenuViewRangRele:
  case typeMenuViewRangCDI:
  case typeMenuViewLE:
  {
    if(PNTCRR_TEXTSTREAM->PntStringViewer!=-10 &&
        PNTCRR_TEXTSTREAM->topStrPnt<0
      ) PNTCRR_TEXTSTREAM->PntStringViewer = 0;
    else
    {
      PNTCRR_TEXTSTREAM->PntStringViewer = SIZE_PAGE_VIEW-1;
    }//else

    if(flg==0) PNTCRR_TEXTSTREAM->PntStringViewer = 0;

    ViewDiskrMenu(typeWin);//������� ���� �����������
    LanderPStr();//���������� ��������� ������
  }
  break;

  }//switch

  if(FvmenuDis->TipPanel->Visible) PgUpTipPanel();
  */
}//SetPgUpButton(short flg)

void PereinitSub(short flg)
{
  //�-��� �������� Sub
  TxtStreamReset(CRR_TEXTSTREAM);//����� ���������

  PNTCRR_TEXTSTREAM->PntStringViewer = 0;
  if(flg==0)//END
  {
    TxtStreamSetEnd(CRR_TEXTSTREAM, SIZE_PAGE_VIEW);//������� �� END
  }//if
  ViewDiskrMenu(typeMenuSub);//������� ���� �����������
  LanderPStr();//���������� ��������� ������
}//PereinitSub()

void OpenMenuSub()
{
//������� ���� view
  TxtStreamCorrect(CRR_TEXTSTREAM);//��������� ������� control
//  CRR_TEXTSTREAM = PNTCRR_SUBMENU(SUBDATA).Line1;//����� ������� control
  SelectorTEXTCONTROL(PNTCRR_SUBMENU(SUBDATA).Line1);//���������� ������� ������ �� ��������� �����
  TxtStreamCorrect(CRR_TEXTSTREAM);//��������� ������� control

  ViewDiskrMenu(typeMenuSub);//������� ���� �����������
//  CRR_FHOME = &PereinitSub;//��������� �� �-��� HOME
  SelectorFHOME(&PereinitSub);//��������� �� �-��� HOME

  LanderPStr();//���������� ��������� ������
}//OpenMenuView()


