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
extern int workerUniversal1;//данные для работника
extern int workerUniversal2;//данные для работника

StreamControl controlStruct_tip;//управл структура

void PgUpTipPanel()
{
//панель подсказки TipPanel
  controlStruct_tip.topStrPnt = TxtStreamPgUpButtonPrepare(&controlStruct_tip);//подготовка
  ViewDiskrTip();//вывести окно TipPanel
}//PgUpTipPanel()

void PgDownTipPanel()
{
//панель подсказки TipPanel
  controlStruct_tip.topStrPnt = TxtStreamPgDownButtonPrepare(&controlStruct_tip);//подготовка
  ViewDiskrTip();//вывести окно TipPanel
}//PgDownTipPanel()

void ViewTipPanel(int isRangORwl)
{
//панель подсказки TipPanel
 if(isRangORwl)
  TxtStreamInit(&controlStruct_tip, &KadrMenuFormat_viewLE, NULL);//инит управл структ и формир кадра
 else
  TxtStreamInit(&controlStruct_tip, &KadrMenuFormat_viewRang, NULL);//инит управл структ и формир кадра
  ViewDiskrTip();//вывести окно TipPanel
}//ViewTipPanel()

void ViewDiskrTip()
{
/*
//вывести окно TipPanel
//вывести страницу
  WorkVariantChar workVariantCharLoc;//буфер кадра

  int tmp = TxtStreamIteratorBegin((void *)&workVariantCharLoc, &controlStruct_tip);//движение вниз

  if(tmp==-1) //файла нет или пустой
  {
    FvmenuDis->Str1PnlLabel->Caption = "ПУСТО";
    return ;
  }//if

  if(tmp==0) //достигнут конец файла
  {
    return ;
  }//if
  //показать результат
  FvmenuDis->Str1PnlLabel->Caption = workVariantCharLoc.TwoString[0];

  if(TxtStreamIteratorMidle(&controlStruct_tip)==0) //движение вниз
  {
    //достигнут конец файла
    controlStruct_tip.StpStringViewer = 0;//stp указател строки
    FvmenuDis->Str2PnlLabel->Caption = "";
    return ;
  }//if
  //показать результат
  FvmenuDis->Str2PnlLabel->Caption = workVariantCharLoc.TwoString[0];

  TxtStreamIteratorEnd(&controlStruct_tip);//конец страницы

  controlStruct_tip.StpStringViewer = 1;//stp указател строки
*/

}//ViewDiskrTip()

