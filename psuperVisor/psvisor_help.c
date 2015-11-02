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

#include "logictimersfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"
#include "virtualMenu\ustmanagerfnc.h"

#include "psupervisor\psupervisor.h"

#include "toSpeedOptim.h"

extern int  IndexIO;//������ IO

extern int  IndexTLog;//������ ��������� ������
extern int  IndexENA;//������ ENA
extern int  IndexTIMERS;
extern int    WideCmdBuffer[];//������� ��� ������
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int   ENAcmd[];
extern int   ENAcmd_WL[];
//������� ��� ������ RT ���� ����������� ������ RT
extern int   WideCmdRTBuffer[];

int   WideENABuffer[32+3];//������� ENA ������

int workerUniversal1;//������ ��� ���������
int workerUniversal2;//������ ��� ���������

/**********************************************
����������� ������������� IO ������
cntIO - ����������
**********************************************/
short commonInitIOCmd(short cntIO)
{
  //������� IO ������
  IndexIO += cntIO;//������ IO
  return cntIO;
}//commonInitIOCmd(short cntIO)

/**********************************************
����������� ������������� TL ������
cntTL - ����������
**********************************************/
short commonInitTLCmd(short cntTL)
{
  //������� TL ������
  IndexTLog += cntTL;//������ TL
  return cntTL;
}//commonInitTLCmd(short cntTL)

/**********************************************
����������� ������������� ��������
cntT - ���������� ��������
**********************************************/
void commonInitTimers(short cntT)
{
  //������ � ������� ��������
  for (short i=0; i<cntT; i++)
  {
    initLogTimer(IndexTIMERS +i);
    if ((IndexTIMERS +i)==0) continue;//������ �� ���������
    //bazisTimerMem[IndexTIMERS +i].ENABLE = 1;//���� ��� �������
    setTimerENABLE(IndexTIMERS +i, 1);
  }//for
  IndexTIMERS += cntT;//��������� ������
}//commonInitTimers(short cntT)

/**********************************************
����������� ������������� ��������
cntT - ���������� ��������
**********************************************/
void commonInitTimers_WL(short cntT)
{
  //������ � ������� ��������
  for (short i=0; i<cntT; i++)
  {
    initLogTimer_WL(IndexTIMERS +i);
    if ((IndexTIMERS +i)==0) continue;//������ �� ���������
    //bazisTimerMem[IndexTIMERS +i].ENABLE = 1;//���� ��� �������
    setTimerENABLE_WL(IndexTIMERS +i, 1);
  }//for
  IndexTIMERS += cntT;//��������� ������
}//commonInitTimers_WL(short cntT)

/**********************************************
����������� ������������� ENA ������
cntTL - ����������
**********************************************/
short commonInitENACmd(short cntENA)
{
  //������� ENA ������
  IndexENA += cntENA;//������ ENA
  return cntENA;
}//commonInitENACmd(short cntENA)

void TranslateWordToWideENA(UNS_32 word)
{
//���������� Word � ������� ENA ������
  //�������� ������� ENA �����
  memset(WideENABuffer, 0, sizeof(WideENABuffer));
  MultiBitWorkerHostWord(&word, &pfWorker4);
}//TranslateWordToWideENA(UNS_32 *pWord)

void TranslateQuadroToWideCmd(UNS_32 *pQuadro)
{
//���������� Quadro � ������� ��� ������
  //�������� ������� ��� �����
  memset(WideCmdBuffer, 0, 4*SIZE_RANGIRCMD);
  MultiBitWorkerHostQuadro(pQuadro, &pfWorker3);
}//TranslateQuadroToWideCmd(UNS_32 *pQuadro)

void NumBitSettingWord(short nBit, UNS_32 *word)
{
//��������� ���� �� ��� �������
  int tmpOst = nBit%32;//������� ������ ���� � �����
  (*word) |= 1<<tmpOst;
}//

void NumBitClearingWord(short nBit, UNS_32 *word)
{
//����� ���� �� ��� �������
  int tmpOst = nBit%32;//������� ������ ���� � �����
  (*word) &= ~(1<<tmpOst);
}//NumBitClearing(short nBit, UNS_32 *pQuadro)

char NumBitCheckWord(short nBit, UNS_32 *word)
{
//�������� ���� �� ��� �������
  UNS_32 tmp=0;
  NumBitSettingWord(nBit, &tmp);
  if((tmp&(*word))==0) return 0;
  return 1;
}//NumBitCheck(short nBit, UNS_32 *pQuadro)

void NumBitSettingQuadro(short nBit, UNS_32 *pQuadro)
{
//��������� ���� �� ��� �������
  int tmpOst = nBit%32;//������� ������ ���� � �����
  pQuadro[(nBit - tmpOst)/32] |= 1<<tmpOst;
}//

void NumBitClearingQuadro(short nBit, UNS_32 *pQuadro)
{
//����� ���� �� ��� �������
  int tmpOst = nBit%32;//������� ������ ���� � �����
  pQuadro[(nBit - tmpOst)/32] &= ~(1<<tmpOst);
}//NumBitClearing(short nBit, UNS_32 *pQuadro)

char NumBitCheckQuadro(short nBit, UNS_32 *pQuadro)
{
//�������� ���� �� ��� �������
  UNS_32 tmpQuadro[DQUADRO];
  memset(tmpQuadro, 0, 4* DQUADRO);
  NumBitSettingQuadro(nBit, tmpQuadro);
  return CheckedQuadro(tmpQuadro, pQuadro);//�������� �� � ��� Quadro
}//NumBitCheck(short nBit, UNS_32 *pQuadro)

char CheckedQuadro(UNS_32 *pQuadro1, UNS_32 *pQuadro2)
{
//�������� �� � ��� Quadro
  for (short i=0; i<DQUADRO; i++)
  {
    if (pQuadro1[i]&pQuadro2[i]) return 1;
  }//for
  return 0;
}//

char NumBitCheckWL(short nBit, UNS_32 *pQuadro)
{
//�������� ���� �� ��� �������
  UNS_32 tmpQuadro[2*DQUADRO];
  memset(tmpQuadro, 0, 4* 2*DQUADRO);
  NumBitSettingQuadro(nBit, tmpQuadro);
  return CheckedWL(tmpQuadro, pQuadro);//�������� �� � ��� Quadro
}//NumBitCheckWL(short nBit, UNS_32 *pQuadro)

char CheckedWL(UNS_32 *pQuadro1, UNS_32 *pQuadro2)
{
//�������� �� � ��� Quadro
  for (short i=0; i<2*DQUADRO; i++)
  {
    if (pQuadro1[i]&pQuadro2[i]) return 1;
  }//for
  return 0;
}//

/**********************************************
������� ��������
pWord - ��������� ��  UNS_32
pfW - ��������� �� �������-���������
�������-�������� �������� ������ � ���������� �������
���� �������-�������� ��������� 1 �� MultiBitWorker �����������
**********************************************/
short MultiBitWorkerHostWord(UNS_32 *pWord, int (*pfW)(short idx))
{
  int cntBit=0;//������� ���

  
  if (*pWord==0)
  {
    //cntBit+=32;
    //continue;
    return 0;
  }
  else
  {
    for (int b=0; b<32; b++)
    {
      if ((*pWord)&(1<<b))
      {

        if ((*pfW)(cntBit)) return 1;
      }
      cntBit++;
    }//for
  }
 return 0;
}//MultiBitWorkerHostWord(UNS_32 *pWord, char (*pfW)(short idx))

/**********************************************
�������-�������� ��� ���������
������ �-�� �������� �����
idx - ������ ��������� ����
����� - 0-�� �������� ���������
**********************************************/
int pfWorker1(short idx)
{
  workerUniversal1++;
  return 0;
}//pfWorker1(short idx)

/**********************************************
�������-�������� ��� ���������
������ i-� �������� �������
idx - ������ ��������� ����
����� - 0-�� �������� ���������
**********************************************/
int pfWorker2(short idx)
{
  if(workerUniversal2==workerUniversal1)
  {
    workerUniversal2=idx;
    return 1;
  }
  workerUniversal1++;//������� ������ �����
  return 0;
}//pfWorker1(short idx)

/**********************************************
�������-�������� ��� ���������
���������� Quadro � ������� ��� ������
idx - ������ ��������� ����
����� - 0-�� �������� ���������
**********************************************/
int pfWorker3(short idx)
{
  WideCmdBuffer[idx] = 1;//������� ��� ������
  return 0;
}//pfWorker3(short idx)

/**********************************************
�������-�������� ��� ���������
���������� Word � ������� ENA ������
idx - ������ ��������� ����
����� - 0-�� �������� ���������
**********************************************/
int pfWorker4(short idx)
{
  WideENABuffer[idx] = 1;//������� ENA ������
  return 0;
}//pfWorker4(short idx)

short PrepareENACmd(short idxC, short offsetUpr)
{
  //���������� ENA ������ ��� �����
//��������� ������� �� ������� ����� � ��������
  TranslateWordToWideENA( getNativUstMngUSTAVKI(idxC, offsetUpr) );//���������� Word � ������� ENA ������
  //��������� �������� ENA ������ �� ������� �����
  return  getOffsetENACmdCnf(idxC);
}//PrepareENACmd(short idxC, short offsetUpr)

void CopyWideENAToENAcmd(short offset, short cnt)
{
  //���������� ENA �� WideENA � ENAcmd
  for(short i=0; i<cnt; i++)
  {
    //ENA �������
    ENAcmd[offset + i] = WideENABuffer[i];
  }//for
}//CopyWideENAToENAcmd(short offset, short cnt);

void CopyWideENAToENAcmd_WL(short offset, short cnt)
{
  //���������� ENA �� WideENA � ENAcmd ��
  for(short i=0; i<cnt; i++)
  {
    //ENA �������
    ENAcmd_WL[offset + i] = WideENABuffer[i];
  }//for
}//CopyWideENAToENAcmd_WL(short offset, short cnt);

int setCRCMassiv(int *ustmass, int cnt)
{
//CRC ��� �������
  int crc=0;
  for(int i=0; i<cnt; i++)
     crc += ustmass[i];
  crc++;
  crc++;
  return crc;
}//setCRCMassiv(int *ustmass, int cnt)

