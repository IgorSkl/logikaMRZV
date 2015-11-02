
#include <stdio.h>
#include <string.h>

#include "lpc_types.h"
#include "lpc_irq_fiq.h"
#include "lpc_arm922t_cp15_driver.h"

#include "lpc32xx_hstimer.h"

#include "bazisdef.h"

#include "psuperVisor\supermanager.h"
#include "logictimers\logictimersdef.h"
#include "logictimers\logictimersfnc.h"

extern HSTIMER_REGS_T *hst_regptr;  // Pointer to HSTIMER registers

extern int timing;  
extern int timingLoad;  

//������ EL ��������� ��� ��� ��������
int  elTrgOldTimer[MAX_LOGTIMER];
int  elTrgOutTimer[MAX_LOGTIMER];
//��� ������ ������� ��������
int  logMassTimer[MAX_LOGTIMER];
//������� ������ ��� ��������
BAZIS_TIMER_MEM  bazisTimerMem[MAX_LOGTIMER];

//������ EL ��������� ��� ��� �������� ��
int  elTrgOldTimer_WL[MAX_LOGTIMER_WL];
int  elTrgOutTimer_WL[MAX_LOGTIMER_WL];
//��� ������ ������� ��������
int  logMassTimer_WL[MAX_LOGTIMER_WL];
//������� ������ ��� ��������
BAZIS_TIMER_MEM  bazisTimerMem_WL[MAX_LOGTIMER_WL];

//���������� ����� ���� ��������
int  globalTimerReset = 1;
int  ddvIncrementor;//������� ������� ��� ������ ��
int  timerEnableWL = 0;//���������� ������ �������� ��

/***********************************************************************
 *
 * Function: hstimer_user_interrupt
 *
 * Purpose: HSTIMER interrupt handler
 *
 **********************************************************************/

void hstimer_user_interrupt(void) @ "Fast_function"
{
  ddvIncrementor++;//������� ������� ��� ������ ��
  if(ddvIncrementor>DDV_MAX) ddvIncrementor=0;
  
  for (int i=0; ; i++) //��������� ��� �������
  {
    if (!bazisTimerMem[i].ENABLE) break;//���� ���� ������ ��� ��������
    if (bazisTimerMem[i].RESET) //���� ������ �������
    {
      //������� ��������
      bazisTimerMem[i].crrCNT = bazisTimerMem[i].BUSY = bazisTimerMem[i].FINISCH = 0;
      continue;//���� ������
    }//if RESET

    if (bazisTimerMem[i].BUSY)
    {
      bazisTimerMem[i].crrCNT ++;         //������� ��������
      if (bazisTimerMem[i].crrCNT >= bazisTimerMem[i].porogCNT)
      {
        bazisTimerMem[i].BUSY = 0;
        bazisTimerMem[i].FINISCH = 1;//���� ��������� �����
      }//if
      continue;//����
    }//if

    if (bazisTimerMem[i].FINISCH) continue;//�������� � ���� ������

    if(elTrgOutTimer[i])
    {
      bazisTimerMem[i].BUSY = 1;
      bazisTimerMem[i].crrCNT = 0;         //������� ��������
      continue;//����������
    }//if
  }//for

//������� ��
  for (int i=0; ; i++) //��������� ��� ������� ��
  {
    if (!bazisTimerMem_WL[i].ENABLE) break;//���� ���� ������ ��� ��������
    if (bazisTimerMem_WL[i].RESET) //���� ������ �������
    {
      //������� ��������
      bazisTimerMem_WL[i].crrCNT = bazisTimerMem_WL[i].BUSY = bazisTimerMem_WL[i].FINISCH = 0;
      continue;//���� ������
    }//if RESET

    if (bazisTimerMem_WL[i].BUSY)
    {
      bazisTimerMem_WL[i].crrCNT ++;         //������� ��������
      if (bazisTimerMem_WL[i].crrCNT >= bazisTimerMem_WL[i].porogCNT)
      {
        bazisTimerMem_WL[i].BUSY = 0;
        bazisTimerMem_WL[i].FINISCH = 1;//���� ��������� �����
      }//if
      continue;//����
    }//if

    if (bazisTimerMem_WL[i].FINISCH) continue;//�������� � ���� ������

    if(elTrgOutTimer_WL[i])
    {
      bazisTimerMem_WL[i].BUSY = 1;
      bazisTimerMem_WL[i].crrCNT = 0;         //������� ��������
      continue;//����������
    }//if
  }//for

  timing ++;  
  timingLoad ++;  

  // Clear latched matcg interrupt
  hst_regptr->hstim_int = HSTIM_MATCH0_INT;
}//hstimer_user_interrupt(void)

/**********************************************
������ �����
tNumber - ����� �������
RES - ����� �������
����� - ���� ������
**********************************************/
int PLogTimerRES(int tNumber, int RES) @ "Fast_function"
{
  int tmp = *bazisTimerMem[tNumber].pntInputSignal;

  elTrgOutTimer[tNumber] = tmp;

  if(!tmp)//�� ������ �� ��������
  {
    //������� ��������
    bazisTimerMem[tNumber].crrCNT = bazisTimerMem[tNumber].BUSY = bazisTimerMem[tNumber].FINISCH = 0;
    return 0;
  }//if(!tmp)//�� ������ �� ��������

  if (RES)
  {
    bazisTimerMem[tNumber].RESET = 1;
    return 0;
  }//if

  if (bazisTimerMem[tNumber].FINISCH)
  {
    //���� ������ ��������
    if (tmp) return 1;
    bazisTimerMem[tNumber].RESET = 1;
  }//if
  else
  {
//    if (!RES)
    bazisTimerMem[tNumber].RESET = 0;
  }
  if (bazisTimerMem[tNumber].porogCNT==0)return 1;//��� ������� ������ ����� ����������
  return 0;
}

/**********************************************
������ �����
tNumber - ����� �������
RES - ����� �������
����� - ���� ������
**********************************************/
int PLogTimer(int tNumber) @ "Fast_function"
{
  int tmp = *bazisTimerMem[tNumber].pntInputSignal;

  elTrgOutTimer[tNumber] = tmp;
  if(!tmp)//�� ������ �� ��������
  {
    //������� ��������
    bazisTimerMem[tNumber].crrCNT = bazisTimerMem[tNumber].BUSY = bazisTimerMem[tNumber].FINISCH = 0;
    return 0;
  }//if(!tmp)//�� ������ �� ��������

  if (bazisTimerMem[tNumber].FINISCH)
  {
    //���� ������ ��������
    if (tmp) return 1;
    bazisTimerMem[tNumber].RESET = 1;
    //  bazisTimerMem[tNumber].RESET = 1;
  }//if
  else
  {
    bazisTimerMem[tNumber].RESET = 0;
  }
  if (bazisTimerMem[tNumber].porogCNT==0) return 1;//��� ������� ������ ����� ����������
  return 0;
}//PLogTimer(char tNumber)

/**********************************************
������ ����� ��
tNumber - ����� �������
RES - ����� �������
����� - ���� ������
**********************************************/
int PLogTimer_WL(int tNumber) @ "Fast_function"
{
  int tmp = *bazisTimerMem_WL[tNumber].pntInputSignal;

  elTrgOutTimer_WL[tNumber] = tmp;
  if(!tmp)//�� ������ �� ��������
  {
    //������� ��������
    bazisTimerMem_WL[tNumber].crrCNT = bazisTimerMem_WL[tNumber].BUSY = bazisTimerMem_WL[tNumber].FINISCH = 0;
    return 0;
  }//if(!tmp)//�� ������ �� ��������

  if (bazisTimerMem_WL[tNumber].FINISCH)
  {
    //���� ������ ��������
    if (tmp) return 1;
    bazisTimerMem_WL[tNumber].RESET = 1;
  }//if
  else
  {
    bazisTimerMem_WL[tNumber].RESET = 0;
  }
  if (bazisTimerMem_WL[tNumber].porogCNT==0) return 1;//��� ������� ������ ����� ����������
  return 0;
}//PLogTimer_WL(char tNumber)

void initLogTimer(int tNumber)
{
  elTrgOutTimer[tNumber] = 0;//����� ���� ����� ��������
  elTrgOldTimer[tNumber] = *(bazisTimerMem[tNumber].pntInputSignal);
}//initLogTimer(int tNumber)

void initLogTimer_WL(int tNumber)
{
  elTrgOutTimer_WL[tNumber] = 0;//����� ���� ����� ��������
  elTrgOldTimer_WL[tNumber] = *(bazisTimerMem_WL[tNumber].pntInputSignal);
}//initLogTimer(int tNumber)

/**********************************************
�-�������
tNumber - ����� ������� �����
cnf - ������������ 0-������ 1-��������
RES - ����� �������
����� - ���� ������
**********************************************/
/*
char OFunctionRES(char tNumber, char cnf, char RES)
{
  char tmp = logMassTimer[tNumber+1] = PLogTimerRES(tNumber, RES);
  if (cnf) return ILogTimerRES(tNumber+1, RES)|tmp;
  return FLogTimerRES(tNumber+1, RES);
}
*/
/**********************************************
�-�������
tNumber - ����� ������� �����
cnf - ������������ 0-������ 1-��������
����� - ���� ������
**********************************************/
int OFunction(int tNumber, int cnf) @ "Fast_function"
{
  int tmp = logMassTimer[tNumber+1] = PLogTimer(tNumber);
  if (cnf) return ILogTimer(tNumber+1)|tmp;
  return FLogTimer(tNumber+1);
}

/**********************************************
�-������� ��
tNumber - ����� ������� �����
cnf - ������������ 0-������ 1-��������
����� - ���� ������
**********************************************/
int OFunction_WL(int tNumber, int cnf) @ "Fast_function"
{
  int tmp = logMassTimer_WL[tNumber+1] = PLogTimer_WL(tNumber);
  if (cnf) return ILogTimer_WL(tNumber+1)|tmp;
  return FLogTimer_WL(tNumber+1);
}//OFunction_WL(int tNumber, int cnf)

void initTimers() @ "Fast_function"
{
//���� ��������
  //TIMERS INIT
  memset(bazisTimerMem, 0, sizeof(BAZIS_TIMER_MEM)*MAX_LOGTIMER);//��� ������ ��������
  //������� ��� ������� � ��� �������
  for (short i=0; i<MAX_LOGTIMER; i++)
    bazisTimerMem[i].pntInputSignal = &(logMassTimer[i]);
}//initTimers()

void initTimers_WL() @ "Fast_function"
{
//���� ��������
  //TIMERS INIT
  memset(bazisTimerMem_WL, 0, sizeof(BAZIS_TIMER_MEM)*MAX_LOGTIMER_WL);//��� ������ ��������
  //������� ��� ������� � ��� �������
  for (short i=0; i<MAX_LOGTIMER_WL; i++)
    bazisTimerMem_WL[i].pntInputSignal = &(logMassTimer_WL[i]);
}//initTimers_WL()

int getTimerCrr(int numTim) @ "Fast_function"
{
  //������� ���� �������
   return bazisTimerMem[numTim].crrCNT;
}//getTimerCrr(int numTim)

int getTimerPorog(int numTim) @ "Fast_function"
{
  //������� ����� �������
   return bazisTimerMem[numTim].porogCNT;
}//getTimerPorog(int numTim)

int getTimerBUSY(int numTim) @ "Fast_function"
{
  //��������� �������
   return bazisTimerMem[numTim].BUSY;
}//getTimerBUSY(int numTim)

int getTimerFINISH(int numTim) @ "Fast_function"
{
  //������� �������
   return bazisTimerMem[numTim].FINISCH;
}//getTimerFINISH(int numTim)

int getTimerENABLE(int numTim) @ "Fast_function"
{
  //������ �������
   return bazisTimerMem[numTim].ENABLE;
}//getTimerENABLE(int numTim)

void setTimerENABLE(int numTim, int ena) @ "Fast_function"
{
  //��� ������ �������
   bazisTimerMem[numTim].ENABLE = ena;
}//getTimerENABLE(int numTim)

void setTimerPorog(int numTim, int porog) @ "Fast_function"
{
  bazisTimerMem[numTim].porogCNT = porog;
}//setTimerPorog(int numTim, int porog)

void setTimerENABLE_WL(int numTim, int ena) @ "Fast_function"
{
  //��� ������ ������� ��
   bazisTimerMem_WL[numTim].ENABLE = ena;
}//setTimerENABLE_WL(int numTim, int ena)

void setTimerPorog_WL(int numTim, int porog) @ "Fast_function"
{
  bazisTimerMem_WL[numTim].porogCNT = porog;
}//setTimerPorog_WL(int numTim, int porog)

int isTimerDelta(int numTim, int delta) @ "Fast_function"
{
  //�������� ���� �������
   if(bazisTimerMem[numTim].crrCNT>delta) return 1;
   return 0;
}//getTimerDelta(int numTim, int delta)
