
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
#include "MTZ1Component.c"
#include "PRM1Component.c"

extern int GlobalPO1;
extern int GlobalPO2;
extern int GlobalPO3;
extern int GlobalPO4;
extern int GlobalLevelI_ABC[];
extern int GlobalLevelUL_ABC[];
//������� ������� ���
extern int sectorMTZ_IA_V, sectorMTZ_IA_N;
extern int sectorMTZ_IB_V, sectorMTZ_IB_N;
extern int sectorMTZ_IC_V, sectorMTZ_IC_N;

extern COMPONENT_OBJ  cnfCOMPONENT[];//������������
extern int  logMassTimer[];
extern int  ENAcmd[];
extern int  spvUSTAVKI[];//������� ������� �����������
extern int   WideCmdRTBuffer[];
extern int   tempLog[];
//������������� ����� ����
extern int  isFAILU_COMMON_MTZ;
extern int offsetSPVCmdPRM1;//�������� ��� SPV PRM1

//extern int timing;

void  logicMTZ1(int idxC) @ "Fast_function"
{
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

//������������� ����� ���� MTZ
//isFAILU_INVERT
//���� � ������ ����������� �� ��� ������� ��� �� ����, �� ����� ����������� ��
//������ ��� ��� �� �����������

// TL_LOGIC(TLCMDFU_MTZ1) =
        //ELOUTTRG_NCN_MTZ1
  //      TL_LOGIC(TLCMDOUTNCN_MTZ1)^1;

    //SPV_UST(

  int tt1 = SPV_UST(SPVSRABUST_MTZ1);
  int tt2 = SPV_UST(SPVVOZVUST_MTZ1);

  detectorLevelUP3F(GlobalLevelI_ABC,
                                     tmpOffsetUSpv+SPVSRABUST_MTZ1,
                                     tmpOffsetUSpv+SPVVOZVUST_MTZ1,
                                     tmpOffsetUSpv+SPV_OUTA_MTZ1);

 int LocalPO_MTZ1 = SPV_UST(SPV_OUTA_MTZ1) |
                    SPV_UST(SPV_OUTB_MTZ1) |
                    SPV_UST(SPV_OUTC_MTZ1);

  detectorLevelUP3F(GlobalLevelI_ABC, 
                                     tmpOffsetUSpv+SPVSRABUST_MTZ1_V,
                                     tmpOffsetUSpv+SPVVOZVUST_MTZ1_V,
                                     tmpOffsetUSpv+SPV_OUTA_MTZ1_V);

 int LocalPO_MTZ1_V =    (
	                 (sectorMTZ_IA_V & 
                          SPV_UST(SPV_OUTA_MTZ1_V) &
                          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTA_U005)^1)
                          ) |
	                 (sectorMTZ_IB_V &
                          SPV_UST(SPV_OUTB_MTZ1_V) &
                          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTB_U005)^1)
                          )|
	                 (sectorMTZ_IC_V &
                          SPV_UST(SPV_OUTC_MTZ1_V) &
                          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTC_U005)^1)
                          )
                          );
                    //isFAILU_INVERT
//                    TL_LOGIC(TLCMDFU_MTZ1);


  detectorLevelUP3F(GlobalLevelI_ABC,
                                     tmpOffsetUSpv+SPVSRABUST_MTZ1_N,
                                     tmpOffsetUSpv+SPVVOZVUST_MTZ1_N,
                                     tmpOffsetUSpv+SPV_OUTA_MTZ1_N);

 int LocalPO_MTZ1_N =    (
	                 (sectorMTZ_IA_N & 
                          SPV_UST(SPV_OUTA_MTZ1_N) &
                          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTA_U005)^1)
                          ) |
	                 (sectorMTZ_IB_N &
                          SPV_UST(SPV_OUTB_MTZ1_N) &
                          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTB_U005)^1)
                          )|
	                 (sectorMTZ_IC_N &
                          SPV_UST(SPV_OUTC_MTZ1_N) &
                          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTC_U005)^1)
                          )
                          );
                    //isFAILU_INVERT
//                    TL_LOGIC(TLCMDFU_MTZ1);


//MTZ1_PN
//����
  detectorLevelUP3F(GlobalLevelI_ABC,
                                     tmpOffsetUSpv+SPVSRABUST_MTZ1_PN,
                                     tmpOffsetUSpv+SPVVOZVUST_MTZ1_PN,
                                     tmpOffsetUSpv+SPV_OUTA_MTZ1_PN);

//������
  detectorLevelDOWN3F(GlobalLevelUL_ABC,
                                     tmpOffsetUSpv+SPVSRABUST_MTZ1_UPN,
                                     tmpOffsetUSpv+SPVVOZVUST_MTZ1_UPN,
                                     tmpOffsetUSpv+SPV_OUTA_MTZ1_UPN);

//���� ���� �� ���������� UA UB UC ������ ������� �� MTZ1_PN �����������
 int LocalPO_MTZ1_PN =   (
                         (SPV_UST(SPV_OUTA_MTZ1_PN) &
                          SPV_UST(SPV_OUTA_MTZ1_UPN)) |
                          (SPV_UST(SPV_OUTB_MTZ1_PN) &
                           SPV_UST(SPV_OUTB_MTZ1_UPN)) |
                          (SPV_UST(SPV_OUTC_MTZ1_PN) &
                           SPV_UST(SPV_OUTC_MTZ1_UPN))
                          );
                    //isFAILU_INVERT
//                    TL_LOGIC(TLCMDFU_MTZ1);

    //*******MTZ1********
    int commonMTZ1 =
                     //CMD1_MTZ1
                     (IO_LOGIC(IOCMD1_MTZ1)^1) &
                     ENA_LOGIC(ENA_MTZ1_1);// ENA_MTZ1;

   int locPO_MTZ1 = 
                 commonMTZ1 &
                 //�� ���1
                 (GlobalPO1 | LocalPO_MTZ1) &
                 //MTZ1_PROSTAJA
                 (((ENA_LOGIC(ENA_MTZ1_HALF1) |
                   ENA_LOGIC(ENA_MTZ1_HALF2))^1) |
                 //��������� ���� ��� UL ������ 005
                  (
                     SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTA_U005) &
                     SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTB_U005) &
                     SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTC_U005)
                   ) |
                 //��������� ���� ���
        //ELOUTTRG_NCN_MTZ1
        TL_LOGIC(TLCMDOUTNCN_MTZ1)
//                   (
                    //isFAILU_INVERT
  //                  TL_LOGIC(TLCMDFU_MTZ1)^1
    //               )
                  );

   int locPO_MTZ1_V = 
                 commonMTZ1 &
                 //�� ���2 ���
                 (GlobalPO2 | LocalPO_MTZ1_V)&
                 //MTZ1_NAPRAVL
                 ENA_LOGIC(ENA_MTZ1_HALF1) &
                 //MTZ1 WPERED
                 ENA_LOGIC(ENA_MTZ1_2) &
        //ELOUTTRG_NCN_MTZ1
        (TL_LOGIC(TLCMDOUTNCN_MTZ1)^1);

   int locPO_MTZ1_N = 
                 commonMTZ1 &
                 //�� ���2 ���
                 (GlobalPO3 | LocalPO_MTZ1_N)&
                 //MTZ1_NAPRAVL
                 ENA_LOGIC(ENA_MTZ1_HALF1) &
                 //MTZ1 NAZAD
                 ENA_LOGIC(ENA_MTZ1_3) &
        //ELOUTTRG_NCN_MTZ1
        (TL_LOGIC(TLCMDOUTNCN_MTZ1)^1);

   int locPO_MTZ1_PN = 
                 commonMTZ1 &
                 //�� ���2 ��
                 (GlobalPO4 | LocalPO_MTZ1_PN)&
                 //MTZ1_PUSKN
                 ENA_LOGIC(ENA_MTZ1_HALF2) &
        //ELOUTTRG_NCN_MTZ1
        (TL_LOGIC(TLCMDOUTNCN_MTZ1)^1);

 int tmp1 =
    locPO_MTZ1_V | 
    locPO_MTZ1_N | 
    locPO_MTZ1_PN;
     //MTZ1_PO2
    // TL_LOGIC(TLCMD1_MTZ1) |
     //MTZ1_PO3
    // TL_LOGIC(TLCMD2_MTZ1) |
     //MTZ1_PO4
    // TL_LOGIC(TLCMD3_MTZ1);

// int tmp2 =
  //  isFAILU_COMMON_MTZ;

//���� �� ���� ������
//TRG_FRONT(set, clr, old, out)
//                                    ELOLDTRG_NCN_MTZ1  ELOUTTRG_NCN_MTZ1
  TRG_FRONT(tmp1, isFAILU_COMMON_MTZ, TLCMDOLDNCN_MTZ1, TLCMDOUTNCN_MTZ1)

  locPO_MTZ1_V &=
        //ELOUTTRG_NCN_MTZ1
        (TL_LOGIC(TLCMDOUTNCN_MTZ1)^1);

  locPO_MTZ1_N &=
        //ELOUTTRG_NCN_MTZ1
        (TL_LOGIC(TLCMDOUTNCN_MTZ1)^1);

  locPO_MTZ1_PN &=
        //ELOUTTRG_NCN_MTZ1
        (TL_LOGIC(TLCMDOUTNCN_MTZ1)^1);

    int max_tmp =
    //L1 MTZ1
    LSIGNAL_TIMER(TIMER1_MTZ1)  = //MTZ1_TIM1
    //���� �� ���1
    IO_LOGIC(IOCMD2_MTZ1) =
    locPO_MTZ1;

   // if(max_tmp) flag_max_monitoring |= MAXMONITORING_COLLECT;//���� ��������� ��������

    max_tmp =
    //L2 MTZ1_V
    LSIGNAL_TIMER(TIMER2_MTZ1)  = //MTZ1_TIM2
    //MTZ1_PO2
    TL_LOGIC(TLCMD1_MTZ1) =
    //���� �� ���1 ���
    IO_LOGIC(IOCMD3_MTZ1) =
    locPO_MTZ1_V;

    //if(max_tmp) flag_max_monitoring |= MAXMONITORING_COLLECT;//���� ��������� ��������

    max_tmp =
    //L3 MTZ1_N
    LSIGNAL_TIMER(TIMER3_MTZ1)  = //MTZ1_TIM3
    //MTZ1_PO3
    TL_LOGIC(TLCMD2_MTZ1) = 
    //���� �� ���1 ���
    IO_LOGIC(IOCMD4_MTZ1) =
    locPO_MTZ1_N;

    //if(max_tmp) flag_max_monitoring |= MAXMONITORING_COLLECT;//���� ��������� ��������

    max_tmp =
    //L4 MTZ1_PN
    LSIGNAL_TIMER(TIMER4_MTZ1)  = //MTZ1_TIM4
    //MTZ1_PO4
    TL_LOGIC(TLCMD3_MTZ1) = 
    //���� �� ���1 ��
    IO_LOGIC(IOCMD5_MTZ1) =
    locPO_MTZ1_PN;

//    if(max_tmp) flag_max_monitoring |= MAXMONITORING_COLLECT;//���� ��������� ��������

 int tmp = //L5
    LSIGNAL_TIMER(TIMER_BO_MTZ1)  =
        PLOG_TIMER(TIMER1_MTZ1)| //MTZ1_TIM1
        PLOG_TIMER(TIMER2_MTZ1)| //MTZ1_TIM2
        PLOG_TIMER(TIMER3_MTZ1)| //MTZ1_TIM3
        PLOG_TIMER(TIMER4_MTZ1); //MTZ1_TIM4

    max_tmp =
    //���� ���1
    IO_LOGIC(IOCMD6_MTZ1) =
          ILOG_TIMER(TIMER_BO_MTZ1)|tmp;

  //  if(max_tmp) flag_max_monitoring |= MAXMONITORING_FIX;//���� ��������� ��������

}//logicMTZ1(short idxC)


