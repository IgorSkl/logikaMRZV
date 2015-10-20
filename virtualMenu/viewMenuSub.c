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
//формирователь кадра
  void *tmpP = NULL;
  RESET_COUNTER;//сброс счетчиков
  for(int i=0;; i++)
  {
//критерий терминатора
    tmpP = ((LineMenuItem *)workCntr->userPoint)[i+1+SUBDATA].Line1;
    if(tmpP==NULL)break;
    COMPARE_COUNTER
    {
      strcpy((char *)workCntr->twoString, (char *)tmpP);
      return 1;//сравнить счетчики кадров
    }//COMPARE_COUNTER
  }//for

  return 1;
}//KadrMenuFormat_sub(WorkControl *workCntr)

void ViewDiskrMenuSub()
{
  /*
//вывести страницу
  WorkVariantChar workVariantCharLoc;//буфер кадра

  int tmp = TxtStreamIteratorBegin((void *)&workVariantCharLoc, CRR_TEXTSTREAM);//движение вниз

  if(tmp==-1) //файла нет или пустой
  {
    FvmenuDis->Str1Label->Caption = "ПУСТО";
    return ;
  }//if

  if(tmp==0) //достигнут конец файла
  {
    return ;
  }//if
  //показать результат
  FvmenuDis->Str1Label->Caption = workVariantCharLoc.TwoString[0];

  if(TxtStreamIteratorMidle(CRR_TEXTSTREAM)==0) //движение вниз
  {
    //достигнут конец файла
    PNTCRR_TEXTSTREAM->StpStringViewer = 0;//stp указател строки
    FvmenuDis->Str2Label->Caption = "";
    FvmenuDis->Str3Label->Caption = "";
    FvmenuDis->Str4Label->Caption = "";
    return ;
  }//if
  //показать результат
  FvmenuDis->Str2Label->Caption = workVariantCharLoc.TwoString[0];

  if(TxtStreamIteratorMidle(CRR_TEXTSTREAM)==0) //движение вниз
  {
    //достигнут конец файла
    PNTCRR_TEXTSTREAM->StpStringViewer = 1;//stp указател строки
    FvmenuDis->Str3Label->Caption = "";
    FvmenuDis->Str4Label->Caption = "";
    return ;
  }//if
  //показать результат
  FvmenuDis->Str3Label->Caption = workVariantCharLoc.TwoString[0];

  if(TxtStreamIteratorMidle(CRR_TEXTSTREAM)==0)
  {
    //достигнут конец файла
    PNTCRR_TEXTSTREAM->StpStringViewer = 2;//stp указател строки
    FvmenuDis->Str4Label->Caption = "";
    return ;
  }//if
  //показать результат
  FvmenuDis->Str4Label->Caption = workVariantCharLoc.TwoString[0];

  TxtStreamIteratorEnd(CRR_TEXTSTREAM);//конец страницы

  PNTCRR_TEXTSTREAM->StpStringViewer = 3;//stp указател строки
*/
}//ViewDiskrMenuSub()

void SetPgUpButton(short flg)
{
  /*
//страница вверх
//типажи
  short typeWin = PNTCRR_SUBMENU(SUBDATA).TypesWin;
  PNTCRR_TEXTSTREAM->topStrPnt = TxtStreamPgUpButtonPrepare(CRR_TEXTSTREAM);//подготовка
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
    ViewDiskrMenu(typeWin);//вывести окно отображения
    if(typeWin==typeMenuReg || typeWin==typeMenuViewActual) break;
    else ListPStr();//доступ к уставкам
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

    ViewDiskrMenu(typeWin);//вывести окно отображения
    LanderPStr();//размещение указателя строки
  }
  break;

  }//switch

  if(FvmenuDis->TipPanel->Visible) PgUpTipPanel();
  */
}//SetPgUpButton(short flg)

void PereinitSub(short flg)
{
  //ф-ция переинит Sub
  TxtStreamReset(CRR_TEXTSTREAM);//сброс счетчиков

  PNTCRR_TEXTSTREAM->PntStringViewer = 0;
  if(flg==0)//END
  {
    TxtStreamSetEnd(CRR_TEXTSTREAM, SIZE_PAGE_VIEW);//перейти на END
  }//if
  ViewDiskrMenu(typeMenuSub);//вывести окно отображения
  LanderPStr();//размещение указателя строки
}//PereinitSub()

void OpenMenuSub()
{
//открыть меню view
  TxtStreamCorrect(CRR_TEXTSTREAM);//коррекция текущий control
//  CRR_TEXTSTREAM = PNTCRR_SUBMENU(SUBDATA).Line1;//новый текущий control
  SelectorTEXTCONTROL(PNTCRR_SUBMENU(SUBDATA).Line1);//установить текущую ссылку на текстовый поток
  TxtStreamCorrect(CRR_TEXTSTREAM);//коррекция текущий control

  ViewDiskrMenu(typeMenuSub);//вывести окно отображения
//  CRR_FHOME = &PereinitSub;//указатель на ф-цию HOME
  SelectorFHOME(&PereinitSub);//указатель на ф-цию HOME

  LanderPStr();//размещение указателя строки
}//OpenMenuView()


