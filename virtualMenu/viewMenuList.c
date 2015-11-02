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
//вывести страницу List
/*
  WorkVariantChar workVariantCharLoc;//буфер кадра

  int tmp = TxtStreamIteratorBegin((void *)&workVariantCharLoc, CRR_TEXTSTREAM);//движение вниз

  if(tmp==-1) //файла нет или пустой
  {
    FvmenuDis->Str1Label->Caption = "ПУСТО";
    FvmenuDis->Str2Label->Caption = "";
    FvmenuDis->Str3Label->Caption = "";
    FvmenuDis->Str4Label->Caption = "";
    return ;
  }//if

  if(tmp==0) //достигнут конец файла
  {
    return ;
  }//if

  //показать результат
  FvmenuDis->Str1Label->Caption = workVariantCharLoc.TwoString[0];
  FvmenuDis->Str2Label->Caption = workVariantCharLoc.TwoString[1];

  if(TxtStreamIteratorMidle(CRR_TEXTSTREAM)==0) //движение вниз
  {
    //достигнут конец файла
    PNTCRR_TEXTSTREAM->StpStringViewer = 0;//stp указател строки
    FvmenuDis->Str3Label->Caption = "";
    FvmenuDis->Str4Label->Caption = "";
    return ;
  }//if
  //показать результат
  FvmenuDis->Str3Label->Caption = workVariantCharLoc.TwoString[0];
  FvmenuDis->Str4Label->Caption = workVariantCharLoc.TwoString[1];

  PNTCRR_TEXTSTREAM->StpStringViewer = 1;//stp указател строки

  TxtStreamIteratorEnd(CRR_TEXTSTREAM);//конец страницы
*/
}//ViewDiskrMenuList()


