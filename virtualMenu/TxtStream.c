/*
#include <vcl.h>
#include <strstrea.h>
#include <math.h>
#include <mem.h>
#include <fstream.h>
#include <strstrea.h>
#include <iomanip.h>
#pragma hdrstop
*/

#include <stdio.h>
#include <string.h>

#include "virtualMenu\textstreamdef.h"
#include "virtualMenu\textstreamfnc.h"

void TxtStreamInit(void *pstr, 
                   short  (*pKadrFormat)(void *),
                   void *userPoint)
{
//предустановка текстового потока
  //найти макс к-во кадров в файле
  StreamControl *streamCntr = (StreamControl *)pstr;
  WorkVariantChar workVariantCharLoc;//локальный строчный буфер
  streamCntr->workCntr.twoString = &workVariantCharLoc;//строчный буфер
  streamCntr->workCntr.userPoint = userPoint;
  streamCntr->pKadrFormat = pKadrFormat;//формирователь кадра запомнить

  WORKGLOB_CNTR1 = -1;//глобальный счетчик кадров
  (*pKadrFormat)(&(streamCntr->workCntr));//формирователь кадра вызвать
  WORKGLOB_MAX1 = WORKLOC_CNTR1;//макс к-во кадров в файле

  WORKKADR_EKR1 = 1;//к-во кадров на экране
  TxtStreamReset(streamCntr);//сброс счетчиков

}//TxtStreamInit()

void TxtStreamReset(void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//сброс счетчиков
  WORKGLOB_CNTR1 = -1;//глобальный счетчик кадров
  WORKGLOB_OLD1 = -1;

  streamCntr->PntStringViewer = 0;//указател строки
  streamCntr->topStrPnt = -1;//индекс верх элем
  streamCntr->StpStringViewer = -1;//stp указател строки
}//TxtStreamReset(StreamControl *streamCntr)

short TxtStreamDownButtonPrepare(void *pstr)
{
//подготовка DownButton
  StreamControl *streamCntr = (StreamControl *)pstr;
  WORKGLOB_OLD1++;
  if (WORKGLOB_OLD1 > WORKGLOB_MAX1-2)
    WORKGLOB_OLD1 = WORKGLOB_MAX1-2;
  WORKGLOB_CNTR1 = WORKGLOB_OLD1;//глобальный счетчик кадров
  return WORKGLOB_CNTR1;//глобальный счетчик кадров
}//TxtStreamDownButtonPrepare()

short TxtStreamPgDownButtonPrepare(void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//подготовка PgDownButton
  if (WORKMAKER_VBR1>0 || WORKGLOB_MAX1-1==WORKGLOB_CNTR1)
    WORKGLOB_CNTR1 = WORKGLOB_OLD1;

  WORKGLOB_OLD1 = WORKGLOB_CNTR1;
  return WORKGLOB_CNTR1;//глобальный счетчик кадров
}//TxtStreamPgDownButtonPrepare()

short TxtStreamUpButtonPrepare(void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//подготовка UpButton
  WORKGLOB_OLD1--;
  if (WORKGLOB_OLD1<0) WORKGLOB_OLD1=-1;

  WORKGLOB_CNTR1 = WORKGLOB_OLD1;
  return WORKGLOB_CNTR1;//глобальный счетчик кадров
}//TxtStreamUpButtonPrepare()

short TxtStreamPgUpButtonPrepare(void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//подготовка PgUpButton
  WORKGLOB_OLD1-=WORKKADR_EKR1;

  if (WORKGLOB_OLD1<0) WORKGLOB_OLD1=-1;

  WORKGLOB_CNTR1 = WORKGLOB_OLD1;
  return WORKGLOB_CNTR1;//глобальный счетчик кадров
}//TxtStreamPgUpButtonPrepare()

short TxtStreamIteratorBegin(void *twoString, void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//первый итератор движение вниз
  streamCntr->workCntr.twoString = twoString;//строчный буфер
  short tmp = TxtStreamIteratorMidle(streamCntr);
  WORKCNTR_KADR1 = 1;//счетчик кадров на экране
  WORKMAKER_VBR1 = 1;//маркер выбора

  return tmp;
}//TxtStreamIteratorBegin(void *twoString, StreamControl *streamCntr)

void TxtStreamIteratorEnd(void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//конец страницы
  WORKMAKER_VBR1 =0;//маркер выбора
  WORKKADR_EKR1 = WORKCNTR_KADR1;//к-во кадров на экране
}//TxtStreamIteratorEnd(StreamControl *streamCntr)

short TxtStreamIteratorMidle(void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//не первый итератор движение вниз
  WORKCNTR_KADR1 ++;//счетчик кадров на экране

  WORKGLOB_CNTR1 ++;
  WORKMAKER_VBR1 =1;//++;//маркер выбора
  if (
    (*streamCntr->pKadrFormat)(&(streamCntr->workCntr))//формирователь кадра вызвать
    <0)
  {
    //файла нет или пустой
    WORKMAKER_VBR1 = -1;//маркер выбора
    return -1;
  }//if

  else
  {
    if (WORKGLOB_CNTR1 < WORKGLOB_MAX1)  return 1;
    else
    {
      WORKGLOB_CNTR1 = WORKGLOB_MAX1-1;

      return 0;//достикнут конец файла
    }
  }//else

}//TxtStreamIteratorMidle(StreamControl *streamCntr)

void TxtStreamCorrect(void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//коррекция текущий control
  WORKGLOB_CNTR1 -=
    streamCntr->StpStringViewer+1;//коррекция текущий control
}//CorrectControlStruct()

short TxtStreamMaxKadr(void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//макс к-во кадров
  return WORKGLOB_MAX1;//макс к-во кадров в файле
}//TxtStreamMaxKadr(StreamControl *streamCntr)

short TxtStreamIdxKadr(void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//индекс тек кадра
  return streamCntr->topStrPnt + streamCntr->PntStringViewer+1;
}//TxtStreamIdxKadr(StreamControl *streamCntr)

void TxtStreamSetEnd(void *pstr, short size_page)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//перейти на END
  short tmp = WORKGLOB_CNTR1;

  while((tmp+size_page)<WORKGLOB_MAX1)
  {
    tmp = WORKGLOB_CNTR1;
    WORKGLOB_CNTR1 += size_page;//глобальный счетчик кадров
  }//while

  if((tmp+1)==WORKGLOB_MAX1)
                 tmp -= size_page;//глобальный счетчик кадров
  if(tmp<0) tmp = 0;

  WORKGLOB_CNTR1 = tmp;
  streamCntr->topStrPnt = tmp;
  WORKGLOB_OLD1 = WORKGLOB_CNTR1;
}//TxtStreamSetEnd(StreamControl *streamCntr)

void TxtStreamSetIdxKadr(void *pstr, short kadr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//Установка нового счетчика кадров
  WORKGLOB_CNTR1  = -1;//глобальный счетчик кадров
  streamCntr->PntStringViewer = 0;//указател строки
  for(short i=0; i<kadr; i++){
      streamCntr->topStrPnt = TxtStreamDownButtonPrepare(streamCntr);
      }//for
}//TxtStreamSetIdxKadr(short kadr)

