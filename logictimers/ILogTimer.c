
#include "bazisdef.h"
#include "logictimersdef.h"
#include "logictimersfnc.h"

//массив EL триггеров дл€ лог таймеров
extern int  elTrgOldTimer[];
extern int  elTrgOutTimer[];
//лог массив запуска таймеров
extern int  logMassTimer[];
//главный массив лог таймеров
extern BAZIS_TIMER_MEM  bazisTimerMem[];

extern int  elTrgOldTimer_WL[];
extern int  elTrgOutTimer_WL[];
//лог массив запуска таймеров
extern int  logMassTimer_WL[];
//главный массив лог таймеров
extern BAZIS_TIMER_MEM  bazisTimerMem_WL[];

//глобальный сброс всех таймеров
extern int  globalTimerReset;

//#define _ILOGTIMER_
/**********************************************
ќЅ–ј“Ќџ… ‘ќ–ћ»–ќ¬ј“≈Ћ№
tNumber - номер таймера
¬ыход - флаг работы
**********************************************/
int ILogTimer(int tNumber) @ "Fast_function"
{
  if (globalTimerReset)
  {
//   return LogTimerRES(tNumber, 1, 1);
//#include "logTimerRES.ci"
    int tmp = *bazisTimerMem[tNumber].pntInputSignal;
//if (RES)
//{
    elTrgOldTimer[tNumber] = tmp;
    elTrgOutTimer[tNumber] = 0;//выход триг ускор переноса
    bazisTimerMem[tNumber].RESET = 1;
//}//if

//поймать фронт
    if ((tmp^elTrgOldTimer[tNumber])&(tmp^1))  elTrgOutTimer[tNumber] = 1;


    elTrgOldTimer[tNumber] = tmp;

//если таймер досчитал
    if (bazisTimerMem[tNumber].FINISCH)
    {
      bazisTimerMem[tNumber].RESET = 1;
      elTrgOutTimer[tNumber] = 0;
    }//if
    /*
    else
    {
      if (!RES)
        bazisTimerMem[tNumber].RESET = 0;
    }
    */
    return elTrgOutTimer[tNumber];
  }//if (globalTimerReset)

//  return LogTimer(tNumber, 1);
//#include "logTimer.ci"
  int tmp = *bazisTimerMem[tNumber].pntInputSignal;
//поймать фронт
  if ((tmp^elTrgOldTimer[tNumber])&
      (tmp^1)
     )  elTrgOutTimer[tNumber] = 1;

  elTrgOldTimer[tNumber] = tmp;

//если таймер досчитал
  if (bazisTimerMem[tNumber].FINISCH)
  {
    bazisTimerMem[tNumber].RESET = 1;
    elTrgOutTimer[tNumber] = 0;
  }//if
  else
  {
    bazisTimerMem[tNumber].RESET = 0;
  }
  return elTrgOutTimer[tNumber];

}

int ILogTimer_WL(int tNumber) @ "Fast_function"
{
  if (globalTimerReset)
  {
//   return LogTimerRES(tNumber, 1, 1);
//#include "logTimerRES.ci"
    int tmp = *bazisTimerMem_WL[tNumber].pntInputSignal;
//if (RES)
//{
    elTrgOldTimer_WL[tNumber] = tmp;
    elTrgOutTimer_WL[tNumber] = 0;//выход триг ускор переноса
    bazisTimerMem_WL[tNumber].RESET = 1;
//}//if

//поймать фронт
    if ((tmp^elTrgOldTimer_WL[tNumber])&(tmp^1))  elTrgOutTimer_WL[tNumber] = 1;


    elTrgOldTimer_WL[tNumber] = tmp;

//если таймер досчитал
    if (bazisTimerMem_WL[tNumber].FINISCH)
    {
      bazisTimerMem_WL[tNumber].RESET = 1;
      elTrgOutTimer_WL[tNumber] = 0;
    }//if
    /*
    else
    {
      if (!RES)
        bazisTimerMem[tNumber].RESET = 0;
    }
    */
    return elTrgOutTimer_WL[tNumber];
  }//if (globalTimerReset)

//  return LogTimer(tNumber, 1);
//#include "logTimer.ci"
  int tmp = *bazisTimerMem_WL[tNumber].pntInputSignal;
//поймать фронт
  if ((tmp^elTrgOldTimer_WL[tNumber])&
      (tmp^1)
     )  elTrgOutTimer_WL[tNumber] = 1;

  elTrgOldTimer_WL[tNumber] = tmp;

//если таймер досчитал
  if (bazisTimerMem_WL[tNumber].FINISCH)
  {
    bazisTimerMem_WL[tNumber].RESET = 1;
    elTrgOutTimer_WL[tNumber] = 0;
  }//if
  else
  {
    bazisTimerMem_WL[tNumber].RESET = 0;
  }
  return elTrgOutTimer_WL[tNumber];

}//ILogTimer_WL(int tNumber)
