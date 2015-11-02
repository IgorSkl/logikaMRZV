
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

/**********************************************
ѕ–яћќ… ‘ќ–ћ»–ќ¬ј“≈Ћ№
tNumber - номер таймера
¬ыход - флаг работы
**********************************************/
int FLogTimer(int tNumber) @ "Fast_function"
{
//  bazisTimerMem[tNumber].TYP = 0;//по фронту
  if (globalTimerReset)
  {
//    return LogTimerRES(tNumber,);//, 0, 1);
    int tmp = *bazisTimerMem[tNumber].pntInputSignal;
//if (RES)
//{
    elTrgOldTimer[tNumber] = tmp;
    elTrgOutTimer[tNumber] = 0;//выход триг ускор переноса
    bazisTimerMem[tNumber].RESET = 1;
//}//if

//#ifndef  _ILOGTIMER_
//поймать фронт
    if ((tmp^elTrgOldTimer[tNumber])&tmp)  elTrgOutTimer[tNumber] = 1;
    /*
    #else
    //поймать фронт
    if ((tmp^elTrgOldTimer[tNumber])&(tmp^1))  elTrgOutTimer[tNumber] = 1;

    #endif // _ILOGTIMER_
    */

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

//#include "logTimerRES.ci"
  }//if (globalTimerReset)

//  return LogTimer(tNumber, 0);
//#include "logTimer.ci"
  int tmp = *bazisTimerMem[tNumber].pntInputSignal;
//поймать фронт
  if ((tmp^elTrgOldTimer[tNumber])&
      tmp
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

}//char FLogTimer(char tNumber)

/**********************************************
ѕ–яћќ… ‘ќ–ћ»–ќ¬ј“≈Ћ№ –Ћ
tNumber - номер таймера
¬ыход - флаг работы
**********************************************/
int FLogTimer_WL(int tNumber) @ "Fast_function"
{
  if (globalTimerReset)
  {
//    return LogTimerRES(tNumber,);//, 0, 1);
    int tmp = *bazisTimerMem_WL[tNumber].pntInputSignal;
//if (RES)
//{
    elTrgOldTimer_WL[tNumber] = tmp;
    elTrgOutTimer_WL[tNumber] = 0;//выход триг ускор переноса
    bazisTimerMem_WL[tNumber].RESET = 1;
//}//if

//#ifndef  _ILOGTIMER_
//поймать фронт
    if ((tmp^elTrgOldTimer_WL[tNumber])&tmp)  elTrgOutTimer_WL[tNumber] = 1;
    /*
    #else
    //поймать фронт
    if ((tmp^elTrgOldTimer[tNumber])&(tmp^1))  elTrgOutTimer[tNumber] = 1;

    #endif // _ILOGTIMER_
    */

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

//#include "logTimerRES.ci"
  }//if (globalTimerReset)

//  return LogTimer(tNumber, 0);
//#include "logTimer.ci"
  int tmp = *bazisTimerMem_WL[tNumber].pntInputSignal;
//поймать фронт
  if ((tmp^elTrgOldTimer_WL[tNumber])&
      tmp
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

}//FLogTimer_WL(char tNumber)

