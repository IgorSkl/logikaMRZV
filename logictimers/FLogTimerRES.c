
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
//глобальный сброс всех таймеров
extern int  globalTimerReset;

/**********************************************
ѕ–яћќ… ‘ќ–ћ»–ќ¬ј“≈Ћ№
tNumber - номер таймера
RES - сброс таймера
¬ыход - флаг работы
**********************************************/
int FLogTimerRES(int tNumber, int RES) @ "Fast_function"
{
  if (globalTimerReset)
  {
//   return LogTimerRES(tNumber, 0, 1);
//#include "logTimerRES.ci"
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
  }//if (globalTimerReset)

//  return LogTimerRES(tNumber, 0, RES);
//#define _IS_RES_
//#include "logTimerRES.ci"
  int tmp = *bazisTimerMem[tNumber].pntInputSignal;
  if (RES)
  {
    elTrgOldTimer[tNumber] = tmp;
    elTrgOutTimer[tNumber] = 0;//выход триг ускор переноса
    bazisTimerMem[tNumber].RESET = 1;
  }//if

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
  else
  {
    if (!RES)
      bazisTimerMem[tNumber].RESET = 0;
  }
  return elTrgOutTimer[tNumber];

}//FLogTimerRES(char tNumber, char RES)

