
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

extern int  elTrgOldTimer_WL[];
extern int  elTrgOutTimer_WL[];
//��� ������ ������� ��������
extern int  logMassTimer_WL[];
//������� ������ ��� ��������
extern BAZIS_TIMER_MEM  bazisTimerMem_WL[];

//���������� ����� ���� ��������
extern int  globalTimerReset;

//#define _ILOGTIMER_
/**********************************************
�������� �������������
tNumber - ����� �������
����� - ���� ������
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
    elTrgOutTimer[tNumber] = 0;//����� ���� ����� ��������
    bazisTimerMem[tNumber].RESET = 1;
//}//if

//������� �����
    if ((tmp^elTrgOldTimer[tNumber])&(tmp^1))  elTrgOutTimer[tNumber] = 1;


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

//  return LogTimer(tNumber, 1);
//#include "logTimer.ci"
  int tmp = *bazisTimerMem[tNumber].pntInputSignal;
//������� �����
  if ((tmp^elTrgOldTimer[tNumber])&
      (tmp^1)
     )  elTrgOutTimer[tNumber] = 1;

  elTrgOldTimer[tNumber] = tmp;

//���� ������ ��������
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
    elTrgOutTimer_WL[tNumber] = 0;//����� ���� ����� ��������
    bazisTimerMem_WL[tNumber].RESET = 1;
//}//if

//������� �����
    if ((tmp^elTrgOldTimer_WL[tNumber])&(tmp^1))  elTrgOutTimer_WL[tNumber] = 1;


    elTrgOldTimer_WL[tNumber] = tmp;

//���� ������ ��������
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
//������� �����
  if ((tmp^elTrgOldTimer_WL[tNumber])&
      (tmp^1)
     )  elTrgOutTimer_WL[tNumber] = 1;

  elTrgOldTimer_WL[tNumber] = tmp;

//���� ������ ��������
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
