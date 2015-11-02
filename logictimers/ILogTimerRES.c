
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

//#define _ILOGTIMER_
/**********************************************
�������� �������������
tNumber - ����� �������
RES - ����� �������
����� - ���� ������
**********************************************/
int ILogTimerRES(int tNumber, int RES) @ "Fast_function"
{
  if (globalTimerReset)
  {
// return LogTimerRES(tNumber, 1, 1);
//#include "logTimerRES.ci"
    int tmp = *bazisTimerMem[tNumber].pntInputSignal;
//if (RES)
//{
    elTrgOldTimer[tNumber] = tmp;
    elTrgOutTimer[tNumber] = 0;//����� ���� ����� ��������
    bazisTimerMem[tNumber].RESET = 1;
//}//if

//������� �����
    if ((tmp^elTrgOldTimer[tNumber])&(tmp^1))  elTrgOutTimer[tNumber] = 1;

//#endif // _ILOGTIMER_

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

//  return LogTimerRES(tNumber, 1, RES);
//#define _IS_RES_
//#include "logTimerRES.ci"
  int tmp = *bazisTimerMem[tNumber].pntInputSignal;
  if (RES)
  {
    elTrgOldTimer[tNumber] = tmp;
    elTrgOutTimer[tNumber] = 0;//����� ���� ����� ��������
    bazisTimerMem[tNumber].RESET = 1;
  }//if

//������� �����
  if ((tmp^elTrgOldTimer[tNumber])&(tmp^1))  elTrgOutTimer[tNumber] = 1;

//#endif // _ILOGTIMER_

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
}//ILogTimerRES(char tNumber, char RES)


