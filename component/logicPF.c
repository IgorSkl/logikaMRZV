
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
#include "PFComponent.c"

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

void  logicPF(int idxC) @ "Fast_function"
{
//������ ����������
/*
    int tmpOffsetT    =
                cnfCOMPONENT[idxC].offsetTimers;   //������� ���������� � ������������
    int tmpOffsetIO   =
                cnfCOMPONENT[idxC].offsetIOCmd;    //IO �������
    int tmpOffsetENA  =
                cnfCOMPONENT[idxC].offsetENACmd;    //ENA �������
*/
}//logicPF(short idxC)
