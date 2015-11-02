
#include <stdio.h>
#include <string.h>

#include "psuperVisor\supermanager.h"

#include "bazisdef.h"
#include "component\componentdef.h"
#include "psuperVisor\psvisor_helpdef.h"

#include "logictimers\logictimersmac.h"

#include "logictimers\logictimersfnc.h"

#include "..\bazis.h"

#include "toSpeedOptim.h"

#define _HIDE_COMPONENT
#include "WLComponent.c"

extern int GlobalPO1;
extern int GlobalPO2;
extern int GlobalPO3;
extern int GlobalPO4;
extern int GlobalLevelI_ABC[];

extern COMPONENT_OBJ  cnfCOMPONENT[];//������������
extern int  logMassTimer[];
extern int  ENAcmd[];
extern int  spvUSTAVKI[];//������� ������� �����������
extern int   WideCmdRTBuffer[];
extern int   tempLog[];
extern int offsetIOCmdPRM1;//�������� ��� IO PRM1
//������������� ����� ����
//extern int  isFAILU_COMMON;
//���������� ����� ���� ��������
extern int  globalTimerReset;
extern int  isRunWL;//���������� ��
extern UNS_32 pActualCMD[];//�������

void WideLogLogic() @ "Fast_function"
{
//��������� ������ ��
 if(isRunWL) return;
 isRunWL=1;//���������� ��
/*
  for (int lgm=0; lgm<8; lgm++) //��������� ��� ��� ��������
  {
    executeLgm(lgm);//��������� �����
  }//for
*/

}//WideLogLogic()

void logicWL(int idxC) @ "Fast_function"
{
//������ ����������
 isRunWL=0;//���������� ��
}//logicWL(int idxC)
