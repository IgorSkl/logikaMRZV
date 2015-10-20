
#include <stdio.h>
#include <string.h>

#include "bazisdef.h"
#include "component\componentdef.h"
#include "psuperVisor\psvisor_helpdef.h"

#include "logictimers\logictimersmac.h"

#include "logictimers\logictimersfnc.h"

#include "..\bazis.h"

#include "toSpeedOptim.h"

#define _HIDE_COMPONENT
#include "UROVComponent.c"

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
extern int puskUROV;//���� ����

void  logicUROV(int idxC) @ "Fast_function"
{
   //return;//123456
//������ ����������
    int tmpOffsetT    =
                cnfCOMPONENT[idxC].offsetTimers;   //������� ���������� � ������������
    int tmpOffsetIO   =
                cnfCOMPONENT[idxC].offsetIOCmd;    //IO �������
    int tmpOffsetENA  =
                cnfCOMPONENT[idxC].offsetENACmd;    //ENA �������
    int tmpOffsetUSpv =
                cnfCOMPONENT[idxC].offsetUstSpv;    //������� SPV
    int tmpOffsetTL   =
                cnfCOMPONENT[idxC].offsetTLCmd;    //TL �������

  detectorLevelUP3F(GlobalLevelI_ABC,
                                     tmpOffsetUSpv+SPVSRABUST_UROV,
                                     tmpOffsetUSpv+SPVVOZVUST_UROV,
                                     tmpOffsetUSpv+SPV_OUTA_UROV);

 int LocalPO_UROV = SPV_UST(SPV_OUTA_UROV) |
                    SPV_UST(SPV_OUTB_UROV) |
                    SPV_UST(SPV_OUTC_UROV);

    //PUSK_UROV
//    TL_LOGIC(TLCMD1_UROV) =
             //���� ����
    int tmp1 = 
             IO_LOGIC(IOCMD2_UROV) |
             puskUROV;

    int tmp2 = 
    //PO_UROV
    TL_LOGIC(TLCMD2_UROV) = 
       //PO1_UROV
       (GlobalPO1 | LocalPO_UROV);

//���� �� ���� ������
//TRG_FRONT(set, clr, old, out)
//ELOLDTRG_UROV  ELOUTTRG_UROV
//  TRG_FRONT(tmp1, tmp2, TLCMD3_UROV, TLCMD4_UROV)

    //L1
  LSIGNAL_TIMER(TIMER1_UROV) =
  LSIGNAL_TIMER(TIMER2_UROV) =
             //���� ���� ����
             (IO_LOGIC(IOCMD1_UROV)^1) &
             //PO_UROV
             tmp2 &
             //ELOUTTRG_UROV
//             TL_LOGIC(TLCMD4_UROV) &
             //���� ����
             tmp1 &
             //������ ����
             ENA_LOGIC(ENA_UROV_1);

  tmp1 =
  LSIGNAL_TIMER(TIMER1_BOUROV1) =
      PLOG_TIMER(TIMER1_UROV) ; //UROV1_TIM1

  tmp2 =
  LSIGNAL_TIMER(TIMER2_BOUROV2) =
      PLOG_TIMER(TIMER2_UROV) ; //UROV2_TIM2

  //1�� ����
  IO_LOGIC(IOCMD3_UROV) =
    ILOG_TIMER(TIMER1_BOUROV1)|tmp1;

  //2�� ����
  IO_LOGIC(IOCMD4_UROV) =
    ILOG_TIMER(TIMER2_BOUROV2)|tmp2;

}//logicUROV(short idxC)

