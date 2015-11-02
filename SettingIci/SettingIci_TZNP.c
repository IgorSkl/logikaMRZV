#include "lpc_types.h"
#include "lpc_irq_fiq.h"
#include "lpc_arm922t_cp15_driver.h"

#include "lpc32xx_hstimer.h"
#include "lpc32xx_ssp.h"
#include "lpc32xx_gpio.h"

#include "lpc32xx_intc_driver.h"
#include "lpc32xx_clkpwr_driver.h"

#include "arm926ej_cp15_drv.h"
#include "ttbl.h"

#include <stdio.h>
#include <string.h>

#include "psuperVisor\supermanager.h"

#include "component\componentdef.h"
#include "psuperVisor\psvisor_helpdef.h"

#include "psuperVisor\psvisor_helpfnc.h"
#include "SettingIci\SettingIci.h"
#include "virtualmenu\systemmenufnc.h"

#include "toSpeedOptim.h"
#include "toSpeedDIS.h"

#include "header.h"
#include "ici_r_ef.h"

#define _HIDE_COMPONENT
#include "TZNP1Component.c"

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

void  SettingIci_TZNP()
{
//��������� ICI TZNP
//---------------TZNP1--------------------
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrErthPickup.ov_range_3Io_Tznp;
    
  SetUstToClon(TZNP_COMP1,  1, MNGUST_TZNP1to5_3I0, lMtz1);//������� TZNP1 3I0 
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrErthPickup.ov_range_3Uo_Tznp;
    
  SetUstToClon(TZNP_COMP1,  1, MNGUST_TZNP1to5_3U0, lMtz1);//������� TZNP1 3U0 

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrErthStageParam.time_Tznp;

  SetUstToClon(TZNP_COMP1,  1, MNGVID_TZNP1to5, lMtz1Tmr*10);//������� �������� TZNP1

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrErthStageParam.Tznp_time_stage_3I0;

  SetUstToClon(TZNP_COMP1,  1, MNGVID_TZNP1to5_3I0, lMtz1Tmr*10);//������� �������� 3I0 TZNP1

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrErthStageParam.Tznp_time_stage_3U0;

  SetUstToClon(TZNP_COMP1,  1, MNGVID_TZNP1to5_3U0, lMtz1Tmr*10);//������� �������� 3U0 TZNP1

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrErthStageParam.Tznp_Tau_AcltImp;

  SetUstToClon(TZNP_COMP1,  1, MNGVUSK_TZNP1to5, lMtz1Tmr*10);//������� ���� ����� TZNP1

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrErthStageParam.Tznp_time_stage_Aclt;

  SetUstToClon(TZNP_COMP1,  1, MNGUSK_TZNP1to5, lMtz1Tmr*10);//������� ����� TZNP1 BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrErthStageParam.Tznp_T_op_aclt;

  SetUstToClon(TZNP_COMP1,  1, MNGUSK_TZNP1to5_OU, lMtz1Tmr*10);//������� ����� TZNP1 OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrErthStageParam.Tznp_T_tele_aclt;

  SetUstToClon(TZNP_COMP1,  1, MNGUSK_TZNP1to5_TU, lMtz1Tmr*10);//������� ����� TZNP1 TU


    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrErthStageParam.Tznp3I0_time_stage_Aclt;

  SetUstToClon(TZNP_COMP1,  1, MNGUSK_TZNP1to5_3I0, lMtz1Tmr*10);//������� ����� TZNP1 3I0 BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrErthStageParam.Tznp3I0_T_op_aclt;

  SetUstToClon(TZNP_COMP1,  1, MNGUSK_TZNP1to5_3I0_OU, lMtz1Tmr*10);//������� ����� TZNP1 3I0 OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrErthStageParam.Tznp3I0_T_tele_aclt;

  SetUstToClon(TZNP_COMP1,  1, MNGUSK_TZNP1to5_3I0_TU, lMtz1Tmr*10);//������� ����� TZNP1 3I0 TU

//---------------TZNP2--------------------
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrErthPickup.ov_range_3Io_Tznp;
    
  SetUstToClon(TZNP_COMP1,  2, MNGUST_TZNP1to5_3I0, lMtz1);//������� TZNP2 3I0 
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrErthPickup.ov_range_3Uo_Tznp;
    
  SetUstToClon(TZNP_COMP1,  2, MNGUST_TZNP1to5_3U0, lMtz1);//������� TZNP2 3U0 

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrErthStageParam.time_Tznp;

  SetUstToClon(TZNP_COMP1,  2, MNGVID_TZNP1to5, lMtz1Tmr*10);//������� �������� TZNP2

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrErthStageParam.Tznp_time_stage_3I0;

  SetUstToClon(TZNP_COMP1,  2, MNGVID_TZNP1to5_3I0, lMtz1Tmr*10);//������� �������� 3I0 TZNP2

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrErthStageParam.Tznp_time_stage_3U0;

  SetUstToClon(TZNP_COMP1,  2, MNGVID_TZNP1to5_3U0, lMtz1Tmr*10);//������� �������� 3U0 TZNP2

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrErthStageParam.Tznp_Tau_AcltImp;

  SetUstToClon(TZNP_COMP1,  2, MNGVUSK_TZNP1to5, lMtz1Tmr*10);//������� ���� ����� TZNP2

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrErthStageParam.Tznp_time_stage_Aclt;

  SetUstToClon(TZNP_COMP1,  2, MNGUSK_TZNP1to5, lMtz1Tmr*10);//������� ����� TZNP2 BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrErthStageParam.Tznp_T_op_aclt;

  SetUstToClon(TZNP_COMP1,  2, MNGUSK_TZNP1to5_OU, lMtz1Tmr*10);//������� ����� TZNP2 OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrErthStageParam.Tznp_T_tele_aclt;

  SetUstToClon(TZNP_COMP1,  2, MNGUSK_TZNP1to5_TU, lMtz1Tmr*10);//������� ����� TZNP2 TU


    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrErthStageParam.Tznp3I0_time_stage_Aclt;

  SetUstToClon(TZNP_COMP1,  2, MNGUSK_TZNP1to5_3I0, lMtz1Tmr*10);//������� ����� TZNP2 3I0 BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrErthStageParam.Tznp3I0_T_op_aclt;

  SetUstToClon(TZNP_COMP1,  2, MNGUSK_TZNP1to5_3I0_OU, lMtz1Tmr*10);//������� ����� TZNP2 3I0 OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrErthStageParam.Tznp3I0_T_tele_aclt;

  SetUstToClon(TZNP_COMP1,  2, MNGUSK_TZNP1to5_3I0_TU, lMtz1Tmr*10);//������� ����� TZNP2 3I0 TU

//---------------TZNP3--------------------
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrErthPickup.ov_range_3Io_Tznp;
    
  SetUstToClon(TZNP_COMP1,  3, MNGUST_TZNP1to5_3I0, lMtz1);//������� TZNP3 3I0 
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrErthPickup.ov_range_3Uo_Tznp;
    
  SetUstToClon(TZNP_COMP1,  3, MNGUST_TZNP1to5_3U0, lMtz1);//������� TZNP3 3U0 

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrErthStageParam.time_Tznp;

  SetUstToClon(TZNP_COMP1,  3, MNGVID_TZNP1to5, lMtz1Tmr*10);//������� �������� TZNP3

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrErthStageParam.Tznp_time_stage_3I0;

  SetUstToClon(TZNP_COMP1,  3, MNGVID_TZNP1to5_3I0, lMtz1Tmr*10);//������� �������� 3I0 TZNP3

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrErthStageParam.Tznp_time_stage_3U0;

  SetUstToClon(TZNP_COMP1,  3, MNGVID_TZNP1to5_3U0, lMtz1Tmr*10);//������� �������� 3U0 TZNP3

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrErthStageParam.Tznp_Tau_AcltImp;

  SetUstToClon(TZNP_COMP1,  3, MNGVUSK_TZNP1to5, lMtz1Tmr*10);//������� ���� ����� TZNP3

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrErthStageParam.Tznp_time_stage_Aclt;

  SetUstToClon(TZNP_COMP1,  3, MNGUSK_TZNP1to5, lMtz1Tmr*10);//������� ����� TZNP3 BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrErthStageParam.Tznp_T_op_aclt;

  SetUstToClon(TZNP_COMP1,  3, MNGUSK_TZNP1to5_OU, lMtz1Tmr*10);//������� ����� TZNP3 OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrErthStageParam.Tznp_T_tele_aclt;

  SetUstToClon(TZNP_COMP1,  3, MNGUSK_TZNP1to5_TU, lMtz1Tmr*10);//������� ����� TZNP3 TU


    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrErthStageParam.Tznp3I0_time_stage_Aclt;

  SetUstToClon(TZNP_COMP1,  3, MNGUSK_TZNP1to5_3I0, lMtz1Tmr*10);//������� ����� TZNP3 3I0 BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrErthStageParam.Tznp3I0_T_op_aclt;

  SetUstToClon(TZNP_COMP1,  3, MNGUSK_TZNP1to5_3I0_OU, lMtz1Tmr*10);//������� ����� TZNP3 3I0 OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrErthStageParam.Tznp3I0_T_tele_aclt;

  SetUstToClon(TZNP_COMP1,  3, MNGUSK_TZNP1to5_3I0_TU, lMtz1Tmr*10);//������� ����� TZNP3 3I0 TU
  
//---------------TZNP4--------------------
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrErthPickup.ov_range_3Io_Tznp;
    
  SetUstToClon(TZNP_COMP1,  4, MNGUST_TZNP1to5_3I0, lMtz1);//������� TZNP4 3I0 
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrErthPickup.ov_range_3Uo_Tznp;
    
  SetUstToClon(TZNP_COMP1,  4, MNGUST_TZNP1to5_3U0, lMtz1);//������� TZNP4 3U0 

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrErthStageParam.time_Tznp;

  SetUstToClon(TZNP_COMP1,  4, MNGVID_TZNP1to5, lMtz1Tmr*10);//������� �������� TZNP4

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrErthStageParam.Tznp_time_stage_3I0;

  SetUstToClon(TZNP_COMP1,  4, MNGVID_TZNP1to5_3I0, lMtz1Tmr*10);//������� �������� 3I0 TZNP4

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrErthStageParam.Tznp_time_stage_3U0;

  SetUstToClon(TZNP_COMP1,  4, MNGVID_TZNP1to5_3U0, lMtz1Tmr*10);//������� �������� 3U0 TZNP4

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrErthStageParam.Tznp_Tau_AcltImp;

  SetUstToClon(TZNP_COMP1,  4, MNGVUSK_TZNP1to5, lMtz1Tmr*10);//������� ���� ����� TZNP4

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrErthStageParam.Tznp_time_stage_Aclt;

  SetUstToClon(TZNP_COMP1,  4, MNGUSK_TZNP1to5, lMtz1Tmr*10);//������� ����� TZNP4 BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrErthStageParam.Tznp_T_op_aclt;

  SetUstToClon(TZNP_COMP1,  4, MNGUSK_TZNP1to5_OU, lMtz1Tmr*10);//������� ����� TZNP4 OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrErthStageParam.Tznp_T_tele_aclt;

  SetUstToClon(TZNP_COMP1,  4, MNGUSK_TZNP1to5_TU, lMtz1Tmr*10);//������� ����� TZNP4 TU


    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrErthStageParam.Tznp3I0_time_stage_Aclt;

  SetUstToClon(TZNP_COMP1,  4, MNGUSK_TZNP1to5_3I0, lMtz1Tmr*10);//������� ����� TZNP4 3I0 BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrErthStageParam.Tznp3I0_T_op_aclt;

  SetUstToClon(TZNP_COMP1,  4, MNGUSK_TZNP1to5_3I0_OU, lMtz1Tmr*10);//������� ����� TZNP4 3I0 OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrErthStageParam.Tznp3I0_T_tele_aclt;

  SetUstToClon(TZNP_COMP1,  4, MNGUSK_TZNP1to5_3I0_TU, lMtz1Tmr*10);//������� ����� TZNP4 3I0 TU

//---------------TZNP5--------------------
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrErthPickup.ov_range_3Io_Tznp;
    
  SetUstToClon(TZNP_COMP1,  5, MNGUST_TZNP1to5_3I0, lMtz1);//������� TZNP5 3I0 
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrErthPickup.ov_range_3Uo_Tznp;
    
  SetUstToClon(TZNP_COMP1,  5, MNGUST_TZNP1to5_3U0, lMtz1);//������� TZNP5 3U0 

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrErthStageParam.time_Tznp;

  SetUstToClon(TZNP_COMP1,  5, MNGVID_TZNP1to5, lMtz1Tmr*10);//������� �������� TZNP5

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrErthStageParam.Tznp_time_stage_3I0;

  SetUstToClon(TZNP_COMP1,  5, MNGVID_TZNP1to5_3I0, lMtz1Tmr*10);//������� �������� 3I0 TZNP5

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrErthStageParam.Tznp_time_stage_3U0;

  SetUstToClon(TZNP_COMP1,  5, MNGVID_TZNP1to5_3U0, lMtz1Tmr*10);//������� �������� 3U0 TZNP5

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrErthStageParam.Tznp_Tau_AcltImp;

  SetUstToClon(TZNP_COMP1,  5, MNGVUSK_TZNP1to5, lMtz1Tmr*10);//������� ���� ����� TZNP5

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrErthStageParam.Tznp_time_stage_Aclt;

  SetUstToClon(TZNP_COMP1,  5, MNGUSK_TZNP1to5, lMtz1Tmr*10);//������� ����� TZNP5 BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrErthStageParam.Tznp_T_op_aclt;

  SetUstToClon(TZNP_COMP1,  5, MNGUSK_TZNP1to5_OU, lMtz1Tmr*10);//������� ����� TZNP5 OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrErthStageParam.Tznp_T_tele_aclt;

  SetUstToClon(TZNP_COMP1,  5, MNGUSK_TZNP1to5_TU, lMtz1Tmr*10);//������� ����� TZNP5 TU


    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrErthStageParam.Tznp3I0_time_stage_Aclt;

  SetUstToClon(TZNP_COMP1,  5, MNGUSK_TZNP1to5_3I0, lMtz1Tmr*10);//������� ����� TZNP5 3I0 BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrErthStageParam.Tznp3I0_T_op_aclt;

  SetUstToClon(TZNP_COMP1,  5, MNGUSK_TZNP1to5_3I0_OU, lMtz1Tmr*10);//������� ����� TZNP5 3I0 OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrErthStageParam.Tznp3I0_T_tele_aclt;

  SetUstToClon(TZNP_COMP1,  5, MNGUSK_TZNP1to5_3I0_TU, lMtz1Tmr*10);//������� ����� TZNP5 3I0 TU

/*
unsigned char  state_Tznp;
//.   ���������
//.   1 -���
//.   0 - ����
unsigned char  direction_Tznp1;
//.���������
//.1 -�����
//.0 - �����
unsigned char  state_Tznp_3U0;
//.   ���������
//.   1 -���
//.   0 - ����
unsigned char  state_Tznp_3I0;
//.   ���������
//.   1 -���
//.   0 - ����
unsigned char  state_Tele_aclt_Tznp;//���� �������������
//unsigned char  state_aclt_Tznp;//��������� ����� ��H ����������
//.	1 -���
//.	0 - ����
unsigned char  state_Auto_aclt_Tznp;//�������������� ��������� 
//unsigned char  state_over_wk_aclt_Tznp;//����������� ��������� ����
//.	1 -���
//.	0 - ����
unsigned char   aclt_Tznp_sw;//��������� ���� ��� ���. �� 
*/

//---------------TZNP1--------------------
  int uprTZNP1=0;
  //����  ��������� TZNP1    
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg1DrErthMng.state_Tznp;
  if(lSt1>0) uprTZNP1 |= 1; //TZNP1 WKL
  else  uprTZNP1 &= ~1; //TZNP1 OTKL 
  //����  ��������� TZNP1 3I0
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg1DrErthMng.state_Tznp_3I0;
  if(lSt1>0) uprTZNP1 |= 2; //TZNP1 3I0 WKL
  else  uprTZNP1 &= ~2; //TZNP1 3I0 OTKL 
  //����  ��������� TZNP1 3U0
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg1DrErthMng.state_Tznp_3U0;
  if(lSt1>0) uprTZNP1 |= 4; //TZNP1 3U0 WKL
  else  uprTZNP1 &= ~4; //TZNP1 3U0 OTKL 
  //����  ��������� TZNP1 �������
//.	���������
//.	1 - ������
//.	0 - �����
    lSt1 = brCfgTbl.ownrStg1DrErthMng.direction_Tznp1;
  if(lSt1>0) uprTZNP1 |= 8; //TZNP1 ������
  else  uprTZNP1 &= ~8; //TZNP1 �����
  //����  ��������� �� TZNP1 
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg1DrErthMng.aclt_Tznp_sw;
  if(lSt1>0) uprTZNP1 |= 16; //USK TZNP1 BB WKL
  else  uprTZNP1 &= ~16; //USK TZNP1 BB OTKL 
  //����  ��������� AU TZNP1 
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg1DrErthMng.state_Auto_aclt_Tznp;
  if(lSt1>0) uprTZNP1 |= 32; //USK TZNP1 AU WKL
  else  uprTZNP1 &= ~32; //USK TZNP1 AU OTKL 
  //����  ��������� OU TZNP1 
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg1DrErthMng.state_Tele_aclt_Tznp;
  if(lSt1>0) uprTZNP1 |= 64; //USK TZNP1 TU WKL
  else  uprTZNP1 &= ~64; //USK TZNP1 TU OTKL 

  
  SetUstToClon(TZNP_COMP1,  1, MNGUPR_TZNP1to5, uprTZNP1);//���������� TZNP1

//---------------TZNP2--------------------
  int uprTZNP2=0;
  //����  ��������� TZNP2    
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg2DrErthMng.state_Tznp;
  if(lSt1>0) uprTZNP2 |= 1; //TZNP2 WKL
  else  uprTZNP2 &= ~1; //TZNP2 OTKL 
  //����  ��������� TZNP2 3I0
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg2DrErthMng.state_Tznp_3I0;
  if(lSt1>0) uprTZNP2 |= 2; //TZNP2 3I0 WKL
  else  uprTZNP2 &= ~2; //TZNP2 3I0 OTKL 
  //����  ��������� TZNP2 3U0
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg2DrErthMng.state_Tznp_3U0;
  if(lSt1>0) uprTZNP2 |= 4; //TZNP2 3U0 WKL
  else  uprTZNP2 &= ~4; //TZNP2 3U0 OTKL 
  //����  ��������� TZNP2 �������
//.	���������
//.	1 - ������
//.	0 - �����
    lSt1 = brCfgTbl.ownrStg2DrErthMng.direction_Tznp1;
  if(lSt1>0) uprTZNP2 |= 8; //TZNP2 ������
  else  uprTZNP2 &= ~8; //TZNP2 �����
  //����  ��������� �� TZNP2 
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg2DrErthMng.aclt_Tznp_sw;
  if(lSt1>0) uprTZNP2 |= 16; //USK TZNP2 BB WKL
  else  uprTZNP2 &= ~16; //USK TZNP2 BB OTKL 
  //����  ��������� AU TZNP2 
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg2DrErthMng.state_Auto_aclt_Tznp;
  if(lSt1>0) uprTZNP2 |= 32; //USK TZNP2 AU WKL
  else  uprTZNP2 &= ~32; //USK TZNP2 AU OTKL 
  //����  ��������� OU TZNP2 
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg2DrErthMng.state_Tele_aclt_Tznp;
  if(lSt1>0) uprTZNP2 |= 64; //USK TZNP2 TU WKL
  else  uprTZNP2 &= ~64; //USK TZNP2 TU OTKL 

  
  SetUstToClon(TZNP_COMP1,  2, MNGUPR_TZNP1to5, uprTZNP2);//���������� TZNP2

//---------------TZNP3--------------------
  int uprTZNP3=0;
  //����  ��������� TZNP3    
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg3DrErthMng.state_Tznp;
  if(lSt1>0) uprTZNP3 |= 1; //TZNP3 WKL
  else  uprTZNP3 &= ~1; //TZNP3 OTKL 
  //����  ��������� TZNP3 3I0
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg3DrErthMng.state_Tznp_3I0;
  if(lSt1>0) uprTZNP3 |= 2; //TZNP3 3I0 WKL
  else  uprTZNP3 &= ~2; //TZNP3 3I0 OTKL 
  //����  ��������� TZNP3 3U0
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg3DrErthMng.state_Tznp_3U0;
  if(lSt1>0) uprTZNP3 |= 4; //TZNP3 3U0 WKL
  else  uprTZNP3 &= ~4; //TZNP3 3U0 OTKL 
  //����  ��������� TZNP3 �������
//.	���������
//.	1 - ������
//.	0 - �����
    lSt1 = brCfgTbl.ownrStg3DrErthMng.direction_Tznp1;
  if(lSt1>0) uprTZNP3 |= 8; //TZNP3 ������
  else  uprTZNP3 &= ~8; //TZNP3 �����
  //����  ��������� �� TZNP3 
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg3DrErthMng.aclt_Tznp_sw;
  if(lSt1>0) uprTZNP3 |= 16; //USK TZNP3 BB WKL
  else  uprTZNP3 &= ~16; //USK TZNP3 BB OTKL 
  //����  ��������� AU TZNP3 
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg3DrErthMng.state_Auto_aclt_Tznp;
  if(lSt1>0) uprTZNP3 |= 32; //USK TZNP3 AU WKL
  else  uprTZNP3 &= ~32; //USK TZNP3 AU OTKL 
  //����  ��������� OU TZNP3 
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg3DrErthMng.state_Tele_aclt_Tznp;
  if(lSt1>0) uprTZNP3 |= 64; //USK TZNP3 TU WKL
  else  uprTZNP3 &= ~64; //USK TZNP3 TU OTKL 

  
  SetUstToClon(TZNP_COMP1,  3, MNGUPR_TZNP1to5, uprTZNP3);//���������� TZNP3
  
//---------------TZNP4--------------------
  int uprTZNP4=0;
  //����  ��������� TZNP4    
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg4DrErthMng.state_Tznp;
  if(lSt1>0) uprTZNP4 |= 1; //TZNP4 WKL
  else  uprTZNP4 &= ~1; //TZNP4 OTKL 
  //����  ��������� TZNP4 3I0
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg4DrErthMng.state_Tznp_3I0;
  if(lSt1>0) uprTZNP4 |= 2; //TZNP4 3I0 WKL
  else  uprTZNP4 &= ~2; //TZNP4 3I0 OTKL 
  //����  ��������� TZNP4 3U0
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg4DrErthMng.state_Tznp_3U0;
  if(lSt1>0) uprTZNP4 |= 4; //TZNP4 3U0 WKL
  else  uprTZNP4 &= ~4; //TZNP4 3U0 OTKL 
  //����  ��������� TZNP4 �������
//.	���������
//.	1 - ������
//.	0 - �����
    lSt1 = brCfgTbl.ownrStg4DrErthMng.direction_Tznp1;
  if(lSt1>0) uprTZNP4 |= 8; //TZNP4 ������
  else  uprTZNP4 &= ~8; //TZNP4 �����
  //����  ��������� �� TZNP4 
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg4DrErthMng.aclt_Tznp_sw;
  if(lSt1>0) uprTZNP4 |= 16; //USK TZNP4 BB WKL
  else  uprTZNP4 &= ~16; //USK TZNP4 BB OTKL 
  //����  ��������� AU TZNP4 
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg4DrErthMng.state_Auto_aclt_Tznp;
  if(lSt1>0) uprTZNP4 |= 32; //USK TZNP4 AU WKL
  else  uprTZNP4 &= ~32; //USK TZNP4 AU OTKL 
  //����  ��������� OU TZNP4
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg4DrErthMng.state_Tele_aclt_Tznp;
  if(lSt1>0) uprTZNP4 |= 64; //USK TZNP4 TU WKL
  else  uprTZNP4 &= ~64; //USK TZNP4 TU OTKL 

  
  SetUstToClon(TZNP_COMP1,  4, MNGUPR_TZNP1to5, uprTZNP4);//���������� TZNP4

//---------------TZNP5--------------------
  int uprTZNP5=0;
  //����  ��������� TZNP5    
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg5DrErthMng.state_Tznp;
  if(lSt1>0) uprTZNP5 |= 1; //TZNP5 WKL
  else  uprTZNP5 &= ~1; //TZNP5 OTKL 
  //����  ��������� TZNP5 3I0
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg5DrErthMng.state_Tznp_3I0;
  if(lSt1>0) uprTZNP5 |= 2; //TZNP5 3I0 WKL
  else  uprTZNP5 &= ~2; //TZNP5 3I0 OTKL 
  //����  ��������� TZNP5 3U0
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg5DrErthMng.state_Tznp_3U0;
  if(lSt1>0) uprTZNP5 |= 4; //TZNP5 3U0 WKL
  else  uprTZNP5 &= ~4; //TZNP5 3U0 OTKL 
  //����  ��������� TZNP5 �������
//.	���������
//.	1 - ������
//.	0 - �����
    lSt1 = brCfgTbl.ownrStg5DrErthMng.direction_Tznp1;
  if(lSt1>0) uprTZNP5 |= 8; //TZNP5 ������
  else  uprTZNP5 &= ~8; //TZNP5 �����
  //����  ��������� �� TZNP5 
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg5DrErthMng.aclt_Tznp_sw;
  if(lSt1>0) uprTZNP5 |= 16; //USK TZNP5 BB WKL
  else  uprTZNP5 &= ~16; //USK TZNP5 BB OTKL 
  //����  ��������� AU TZNP5 
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg5DrErthMng.state_Auto_aclt_Tznp;
  if(lSt1>0) uprTZNP5 |= 32; //USK TZNP5 AU WKL
  else  uprTZNP5 &= ~32; //USK TZNP5 AU OTKL 
  //����  ��������� OU TZNP5 
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg5DrErthMng.state_Tele_aclt_Tznp;
  if(lSt1>0) uprTZNP5 |= 64; //USK TZNP5 TU WKL
  else  uprTZNP5 &= ~64; //USK TZNP5 TU OTKL 

  
  SetUstToClon(TZNP_COMP1,  5, MNGUPR_TZNP1to5, uprTZNP5);//���������� TZNP5

}//SettingIci_TZNP()

