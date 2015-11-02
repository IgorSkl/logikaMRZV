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

extern int  IndexIO;//индекс IO

extern int  IndexTLog;//индекс локальной логики
extern int  IndexENA;//индекс ENA
extern int  IndexTIMERS;
extern int    WideCmdBuffer[];//широкий ком массив
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int   ENAcmd[];
extern int   ENAcmd_WL[];
//широкий ком массив RT плюс расширенная логика RT
extern int   WideCmdRTBuffer[];

int   WideENABuffer[32+3];//широкий ENA массив

int workerUniversal1;//данные для работника
int workerUniversal2;//данные для работника

/**********************************************
СТАНДАРТНЫЙ ИНИЦИАЛИЗАТОР IO КОМАНД
cntIO - количество
**********************************************/
short commonInitIOCmd(short cntIO)
{
  //инициал IO команд
  IndexIO += cntIO;//индекс IO
  return cntIO;
}//commonInitIOCmd(short cntIO)

/**********************************************
СТАНДАРТНЫЙ ИНИЦИАЛИЗАТОР TL КОМАНД
cntTL - количество
**********************************************/
short commonInitTLCmd(short cntTL)
{
  //инициал TL команд
  IndexTLog += cntTL;//индекс TL
  return cntTL;
}//commonInitTLCmd(short cntTL)

/**********************************************
СТАНДАРТНЫЙ ИНИЦИАЛИЗАТОР ТАЙМЕРОВ
cntT - количество таймеров
**********************************************/
void commonInitTimers(short cntT)
{
  //запрос и инициал таймеров
  for (short i=0; i<cntT; i++)
  {
    initLogTimer(IndexTIMERS +i);
    if ((IndexTIMERS +i)==0) continue;//первый не разрешать
    //bazisTimerMem[IndexTIMERS +i].ENABLE = 1;//разр лог таймера
    setTimerENABLE(IndexTIMERS +i, 1);
  }//for
  IndexTIMERS += cntT;//таймерный индекс
}//commonInitTimers(short cntT)

/**********************************************
СТАНДАРТНЫЙ ИНИЦИАЛИЗАТОР ТАЙМЕРОВ
cntT - количество таймеров
**********************************************/
void commonInitTimers_WL(short cntT)
{
  //запрос и инициал таймеров
  for (short i=0; i<cntT; i++)
  {
    initLogTimer_WL(IndexTIMERS +i);
    if ((IndexTIMERS +i)==0) continue;//первый не разрешать
    //bazisTimerMem[IndexTIMERS +i].ENABLE = 1;//разр лог таймера
    setTimerENABLE_WL(IndexTIMERS +i, 1);
  }//for
  IndexTIMERS += cntT;//таймерный индекс
}//commonInitTimers_WL(short cntT)

/**********************************************
СТАНДАРТНЫЙ ИНИЦИАЛИЗАТОР ENA КОМАНД
cntTL - количество
**********************************************/
short commonInitENACmd(short cntENA)
{
  //инициал ENA команд
  IndexENA += cntENA;//индекс ENA
  return cntENA;
}//commonInitENACmd(short cntENA)

void TranslateWordToWideENA(UNS_32 word)
{
//Превратить Word в широкий ENA массив
  //обнулить широкий ENA буфер
  memset(WideENABuffer, 0, sizeof(WideENABuffer));
  MultiBitWorkerHostWord(&word, &pfWorker4);
}//TranslateWordToWideENA(UNS_32 *pWord)

void TranslateQuadroToWideCmd(UNS_32 *pQuadro)
{
//Превратить Quadro в широкий ком массив
  //обнулить широкий ком буфер
  memset(WideCmdBuffer, 0, 4*SIZE_RANGIRCMD);
  MultiBitWorkerHostQuadro(pQuadro, &pfWorker3);
}//TranslateQuadroToWideCmd(UNS_32 *pQuadro)

void NumBitSettingWord(short nBit, UNS_32 *word)
{
//установка бита по его индексу
  int tmpOst = nBit%32;//остаток индекс бита в слове
  (*word) |= 1<<tmpOst;
}//

void NumBitClearingWord(short nBit, UNS_32 *word)
{
//сброс бита по его индексу
  int tmpOst = nBit%32;//остаток индекс бита в слове
  (*word) &= ~(1<<tmpOst);
}//NumBitClearing(short nBit, UNS_32 *pQuadro)

char NumBitCheckWord(short nBit, UNS_32 *word)
{
//проверка бита по его индексу
  UNS_32 tmp=0;
  NumBitSettingWord(nBit, &tmp);
  if((tmp&(*word))==0) return 0;
  return 1;
}//NumBitCheck(short nBit, UNS_32 *pQuadro)

void NumBitSettingQuadro(short nBit, UNS_32 *pQuadro)
{
//установка бита по его индексу
  int tmpOst = nBit%32;//остаток индекс бита в слове
  pQuadro[(nBit - tmpOst)/32] |= 1<<tmpOst;
}//

void NumBitClearingQuadro(short nBit, UNS_32 *pQuadro)
{
//сброс бита по его индексу
  int tmpOst = nBit%32;//остаток индекс бита в слове
  pQuadro[(nBit - tmpOst)/32] &= ~(1<<tmpOst);
}//NumBitClearing(short nBit, UNS_32 *pQuadro)

char NumBitCheckQuadro(short nBit, UNS_32 *pQuadro)
{
//проверка бита по его индексу
  UNS_32 tmpQuadro[DQUADRO];
  memset(tmpQuadro, 0, 4* DQUADRO);
  NumBitSettingQuadro(nBit, tmpQuadro);
  return CheckedQuadro(tmpQuadro, pQuadro);//сравнить по И два Quadro
}//NumBitCheck(short nBit, UNS_32 *pQuadro)

char CheckedQuadro(UNS_32 *pQuadro1, UNS_32 *pQuadro2)
{
//сравнить по И два Quadro
  for (short i=0; i<DQUADRO; i++)
  {
    if (pQuadro1[i]&pQuadro2[i]) return 1;
  }//for
  return 0;
}//

char NumBitCheckWL(short nBit, UNS_32 *pQuadro)
{
//проверка бита по его индексу
  UNS_32 tmpQuadro[2*DQUADRO];
  memset(tmpQuadro, 0, 4* 2*DQUADRO);
  NumBitSettingQuadro(nBit, tmpQuadro);
  return CheckedWL(tmpQuadro, pQuadro);//сравнить по И два Quadro
}//NumBitCheckWL(short nBit, UNS_32 *pQuadro)

char CheckedWL(UNS_32 *pQuadro1, UNS_32 *pQuadro2)
{
//сравнить по И два Quadro
  for (short i=0; i<2*DQUADRO; i++)
  {
    if (pQuadro1[i]&pQuadro2[i]) return 1;
  }//for
  return 0;
}//

/**********************************************
БИТОВЫЙ БРИГАДИР
pWord - указатель на  UNS_32
pfW - указатель на функцию-работника
функция-работник работает только с глобальной памятью
если функция-работник возвратит 1 то MultiBitWorker завершается
**********************************************/
short MultiBitWorkerHostWord(UNS_32 *pWord, int (*pfW)(short idx))
{
  int cntBit=0;//счетчик бит

  
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
ФУНКЦИЯ-РАБОТНИК ДЛЯ БРИГАДИРА
Посчет к-ва активных битов
idx - индекс активного бита
Выход - 0-не покидать бригадира
**********************************************/
int pfWorker1(short idx)
{
  workerUniversal1++;
  return 0;
}//pfWorker1(short idx)

/**********************************************
ФУНКЦИЯ-РАБОТНИК ДЛЯ БРИГАДИРА
Индекс i-й активной команды
idx - индекс активного бита
Выход - 0-не покидать бригадира
**********************************************/
int pfWorker2(short idx)
{
  if(workerUniversal2==workerUniversal1)
  {
    workerUniversal2=idx;
    return 1;
  }
  workerUniversal1++;//счетчик активн битов
  return 0;
}//pfWorker1(short idx)

/**********************************************
ФУНКЦИЯ-РАБОТНИК ДЛЯ БРИГАДИРА
Превратить Quadro в широкий ком массив
idx - индекс активного бита
Выход - 0-не покидать бригадира
**********************************************/
int pfWorker3(short idx)
{
  WideCmdBuffer[idx] = 1;//широкий ком массив
  return 0;
}//pfWorker3(short idx)

/**********************************************
ФУНКЦИЯ-РАБОТНИК ДЛЯ БРИГАДИРА
Превратить Word в широкий ENA массив
idx - индекс активного бита
Выход - 0-не покидать бригадира
**********************************************/
int pfWorker4(short idx)
{
  WideENABuffer[idx] = 1;//широкий ENA массив
  return 0;
}//pfWorker4(short idx)

short PrepareENACmd(short idxC, short offsetUpr)
{
  //подготовка ENA команд для клона
//прочитать уставку по индексу клона и смещению
  TranslateWordToWideENA( getNativUstMngUSTAVKI(idxC, offsetUpr) );//Превратить Word в широкий ENA массив
  //прочитать смещение ENA команд по индексу клона
  return  getOffsetENACmdCnf(idxC);
}//PrepareENACmd(short idxC, short offsetUpr)

void CopyWideENAToENAcmd(short offset, short cnt)
{
  //копировать ENA из WideENA в ENAcmd
  for(short i=0; i<cnt; i++)
  {
    //ENA команды
    ENAcmd[offset + i] = WideENABuffer[i];
  }//for
}//CopyWideENAToENAcmd(short offset, short cnt);

void CopyWideENAToENAcmd_WL(short offset, short cnt)
{
  //копировать ENA из WideENA в ENAcmd РЛ
  for(short i=0; i<cnt; i++)
  {
    //ENA команды
    ENAcmd_WL[offset + i] = WideENABuffer[i];
  }//for
}//CopyWideENAToENAcmd_WL(short offset, short cnt);

int setCRCMassiv(int *ustmass, int cnt)
{
//CRC для массива
  int crc=0;
  for(int i=0; i<cnt; i++)
     crc += ustmass[i];
  crc++;
  crc++;
  return crc;
}//setCRCMassiv(int *ustmass, int cnt)

