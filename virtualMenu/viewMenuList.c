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

void ViewDiskrMenuList()
{
//������� �������� List
/*
  WorkVariantChar workVariantCharLoc;//����� �����

  int tmp = TxtStreamIteratorBegin((void *)&workVariantCharLoc, CRR_TEXTSTREAM);//�������� ����

  if(tmp==-1) //����� ��� ��� ������
  {
    FvmenuDis->Str1Label->Caption = "�����";
    FvmenuDis->Str2Label->Caption = "";
    FvmenuDis->Str3Label->Caption = "";
    FvmenuDis->Str4Label->Caption = "";
    return ;
  }//if

  if(tmp==0) //��������� ����� �����
  {
    return ;
  }//if

  //�������� ���������
  FvmenuDis->Str1Label->Caption = workVariantCharLoc.TwoString[0];
  FvmenuDis->Str2Label->Caption = workVariantCharLoc.TwoString[1];

  if(TxtStreamIteratorMidle(CRR_TEXTSTREAM)==0) //�������� ����
  {
    //��������� ����� �����
    PNTCRR_TEXTSTREAM->StpStringViewer = 0;//stp �������� ������
    FvmenuDis->Str3Label->Caption = "";
    FvmenuDis->Str4Label->Caption = "";
    return ;
  }//if
  //�������� ���������
  FvmenuDis->Str3Label->Caption = workVariantCharLoc.TwoString[0];
  FvmenuDis->Str4Label->Caption = workVariantCharLoc.TwoString[1];

  PNTCRR_TEXTSTREAM->StpStringViewer = 1;//stp �������� ������

  TxtStreamIteratorEnd(CRR_TEXTSTREAM);//����� ��������
*/
}//ViewDiskrMenuList()


