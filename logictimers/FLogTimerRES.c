
#include "bazisdef.h"
#include "logictimersdef.h"
#include "logictimersfnc.h"

//������ EL ��������� ��� ��� ��������
extern int  elTrgOldTimer[];
extern int  elTrgOutTimer[];
//��� ������ ������� ��������
extern int  logMassTimer[];
//������� ������ ��� ��������
extern BAZIS_TIMER_MEM  bazisTimerMem[];
//���������� ����� ���� ��������
extern int  globalTimerReset;

/**********************************************
������ �������������
tNumber - ����� �������
RES - ����� �������
����� - ���� ������
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
    elTrgOutTimer[tNumber] = 0;//����� ���� ����� ��������
    bazisTimerMem[tNumber].RESET = 1;
//}//if

//#ifndef  _ILOGTIMER_
//������� �����
    if ((tmp^elTrgOldTimer[tNumber])&tmp)  elTrgOutTimer[tNumber] = 1;
    /*
    #else
    //������� �����
    if ((tmp^elTrgOldTimer[tNumber])&(tmp^1))  elTrgOutTimer[tNumber] = 1;

    #endif // _ILOGTIMER_
    */

    elTrgOldTimer[tNumber] = tmp;

//���� ������ ��������
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
    elTrgOutTimer[tNumber] = 0;//����� ���� ����� ��������
    bazisTimerMem[tNumber].RESET = 1;
  }//if

//#ifndef  _ILOGTIMER_
//������� �����
  if ((tmp^elTrgOldTimer[tNumber])&tmp)  elTrgOutTimer[tNumber] = 1;
  /*
  #else
  //������� �����
  if ((tmp^elTrgOldTimer[tNumber])&(tmp^1))  elTrgOutTimer[tNumber] = 1;

  #endif // _ILOGTIMER_
  */

  elTrgOldTimer[tNumber] = tmp;

//���� ������ ��������
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

