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
//������������� ���������� ������
  //����� ���� �-�� ������ � �����
  StreamControl *streamCntr = (StreamControl *)pstr;
  WorkVariantChar workVariantCharLoc;//��������� �������� �����
  streamCntr->workCntr.twoString = &workVariantCharLoc;//�������� �����
  streamCntr->workCntr.userPoint = userPoint;
  streamCntr->pKadrFormat = pKadrFormat;//������������� ����� ���������

  WORKGLOB_CNTR1 = -1;//���������� ������� ������
  (*pKadrFormat)(&(streamCntr->workCntr));//������������� ����� �������
  WORKGLOB_MAX1 = WORKLOC_CNTR1;//���� �-�� ������ � �����

  WORKKADR_EKR1 = 1;//�-�� ������ �� ������
  TxtStreamReset(streamCntr);//����� ���������

}//TxtStreamInit()

void TxtStreamReset(void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//����� ���������
  WORKGLOB_CNTR1 = -1;//���������� ������� ������
  WORKGLOB_OLD1 = -1;

  streamCntr->PntStringViewer = 0;//�������� ������
  streamCntr->topStrPnt = -1;//������ ���� ����
  streamCntr->StpStringViewer = -1;//stp �������� ������
}//TxtStreamReset(StreamControl *streamCntr)

short TxtStreamDownButtonPrepare(void *pstr)
{
//���������� DownButton
  StreamControl *streamCntr = (StreamControl *)pstr;
  WORKGLOB_OLD1++;
  if (WORKGLOB_OLD1 > WORKGLOB_MAX1-2)
    WORKGLOB_OLD1 = WORKGLOB_MAX1-2;
  WORKGLOB_CNTR1 = WORKGLOB_OLD1;//���������� ������� ������
  return WORKGLOB_CNTR1;//���������� ������� ������
}//TxtStreamDownButtonPrepare()

short TxtStreamPgDownButtonPrepare(void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//���������� PgDownButton
  if (WORKMAKER_VBR1>0 || WORKGLOB_MAX1-1==WORKGLOB_CNTR1)
    WORKGLOB_CNTR1 = WORKGLOB_OLD1;

  WORKGLOB_OLD1 = WORKGLOB_CNTR1;
  return WORKGLOB_CNTR1;//���������� ������� ������
}//TxtStreamPgDownButtonPrepare()

short TxtStreamUpButtonPrepare(void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//���������� UpButton
  WORKGLOB_OLD1--;
  if (WORKGLOB_OLD1<0) WORKGLOB_OLD1=-1;

  WORKGLOB_CNTR1 = WORKGLOB_OLD1;
  return WORKGLOB_CNTR1;//���������� ������� ������
}//TxtStreamUpButtonPrepare()

short TxtStreamPgUpButtonPrepare(void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//���������� PgUpButton
  WORKGLOB_OLD1-=WORKKADR_EKR1;

  if (WORKGLOB_OLD1<0) WORKGLOB_OLD1=-1;

  WORKGLOB_CNTR1 = WORKGLOB_OLD1;
  return WORKGLOB_CNTR1;//���������� ������� ������
}//TxtStreamPgUpButtonPrepare()

short TxtStreamIteratorBegin(void *twoString, void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//������ �������� �������� ����
  streamCntr->workCntr.twoString = twoString;//�������� �����
  short tmp = TxtStreamIteratorMidle(streamCntr);
  WORKCNTR_KADR1 = 1;//������� ������ �� ������
  WORKMAKER_VBR1 = 1;//������ ������

  return tmp;
}//TxtStreamIteratorBegin(void *twoString, StreamControl *streamCntr)

void TxtStreamIteratorEnd(void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//����� ��������
  WORKMAKER_VBR1 =0;//������ ������
  WORKKADR_EKR1 = WORKCNTR_KADR1;//�-�� ������ �� ������
}//TxtStreamIteratorEnd(StreamControl *streamCntr)

short TxtStreamIteratorMidle(void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//�� ������ �������� �������� ����
  WORKCNTR_KADR1 ++;//������� ������ �� ������

  WORKGLOB_CNTR1 ++;
  WORKMAKER_VBR1 =1;//++;//������ ������
  if (
    (*streamCntr->pKadrFormat)(&(streamCntr->workCntr))//������������� ����� �������
    <0)
  {
    //����� ��� ��� ������
    WORKMAKER_VBR1 = -1;//������ ������
    return -1;
  }//if

  else
  {
    if (WORKGLOB_CNTR1 < WORKGLOB_MAX1)  return 1;
    else
    {
      WORKGLOB_CNTR1 = WORKGLOB_MAX1-1;

      return 0;//��������� ����� �����
    }
  }//else

}//TxtStreamIteratorMidle(StreamControl *streamCntr)

void TxtStreamCorrect(void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//��������� ������� control
  WORKGLOB_CNTR1 -=
    streamCntr->StpStringViewer+1;//��������� ������� control
}//CorrectControlStruct()

short TxtStreamMaxKadr(void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//���� �-�� ������
  return WORKGLOB_MAX1;//���� �-�� ������ � �����
}//TxtStreamMaxKadr(StreamControl *streamCntr)

short TxtStreamIdxKadr(void *pstr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//������ ��� �����
  return streamCntr->topStrPnt + streamCntr->PntStringViewer+1;
}//TxtStreamIdxKadr(StreamControl *streamCntr)

void TxtStreamSetEnd(void *pstr, short size_page)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//������� �� END
  short tmp = WORKGLOB_CNTR1;

  while((tmp+size_page)<WORKGLOB_MAX1)
  {
    tmp = WORKGLOB_CNTR1;
    WORKGLOB_CNTR1 += size_page;//���������� ������� ������
  }//while

  if((tmp+1)==WORKGLOB_MAX1)
                 tmp -= size_page;//���������� ������� ������
  if(tmp<0) tmp = 0;

  WORKGLOB_CNTR1 = tmp;
  streamCntr->topStrPnt = tmp;
  WORKGLOB_OLD1 = WORKGLOB_CNTR1;
}//TxtStreamSetEnd(StreamControl *streamCntr)

void TxtStreamSetIdxKadr(void *pstr, short kadr)
{
  StreamControl *streamCntr = (StreamControl *)pstr;
//��������� ������ �������� ������
  WORKGLOB_CNTR1  = -1;//���������� ������� ������
  streamCntr->PntStringViewer = 0;//�������� ������
  for(short i=0; i<kadr; i++){
      streamCntr->topStrPnt = TxtStreamDownButtonPrepare(streamCntr);
      }//for
}//TxtStreamSetIdxKadr(short kadr)

