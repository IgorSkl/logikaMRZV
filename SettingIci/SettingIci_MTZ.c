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
#include "MTZ1Component.c"
#include "MTZ2Component.c"

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

void  SettingIci_MTZ()
{
//��������� ICI ��� 
//-------------MTZ1-----------------------    
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrOcp1Pickup.mcp1_I_ov_range;
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrOcp1StageParam.mcp1_time_stage;
    
  SetUstToClon(MTZ_COMP1,  1, MNGUST_MTZ1, lMtz1);//������� ���1 �������
  SetUstToClon(MTZ_COMP1,  1, MNGVID_MTZ1, lMtz1Tmr*10);//�������� ���1 �������

//.�� �����1
//.	 ������� �� ����
//.	 1 �� = 1 �A
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrOcp1Pickup.mcp1_IstpU_ov_range;
  SetUstToClon(MTZ_COMP1,  1, MNGUST_MTZ1_PN, lMtz1);//������� ���1 �� 
//.�� U �����1
//.	 ������� �� ����� �� ����������
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrOcp1Pickup.mcp1_Ustp_ov_range;
  SetUstToClon(MTZ_COMP1,  1, MNGUST_MTZ1_UPN, lMtz1);//������� ���1 �� 
//.T �����1
//.	�������� 1- ������� ���
//.	1 �� =10���
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrOcp1StageParam.mcp1_Ustp_time_stage;
  SetUstToClon(MTZ_COMP1,  1, MNGVID_MTZ1_PN, lMtz1Tmr*10);//�������� ���1 ��

//.�� ���1 �������
//.	 ������� �� ����
//.	 1 �� = 1 �A
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrOcp1Pickup.mcp1_s1_Ias_ov_range;
  SetUstToClon(MTZ_COMP1,  1, MNGUST_MTZ1_V, lMtz1);//������� ����1 ������

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrOcp1Pickup.mcp1_s2_Iabk_ov_range;
  SetUstToClon(MTZ_COMP1,  1, MNGUST_MTZ1_N, lMtz1);//������� ����1 �����
//.	�������� ���1 ������
//.	1 �� =10���
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrOcp1StageParam.mcp1_s1_time_stage;
  SetUstToClon(MTZ_COMP1,  1, MNGVID_MTZ1_V, lMtz1Tmr*10);//�������� ���1 ������
//.	�������� ���1 �����
//.	1 �� =10���
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrOcp1StageParam.mcp1_s2_time_stage;
  SetUstToClon(MTZ_COMP1,  1, MNGVID_MTZ1_N, lMtz1Tmr*10);//�������� ���1 ������

  int uprMTZ1=0;
  //����  ��������� ���1    
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg1DrOcp1Mng.state_mcp1;
  if(lSt1>0) uprMTZ1 |= 4; //���1 ������� WKL
  else  uprMTZ1 &= ~4; //���1 ������� OTKL 
    //�������� ���1
//.	���������
//.	0 - �������
//.	1 - ���� �� ��������������
//.	2 - ���� �� ����������
    lSt2 = brCfgTbl.ownrStg1DrOcp1Mng.select_prt_mcp1;  
  if(lSt2==2) uprMTZ1 |= 2; //���1 �� WKL
  else  uprMTZ1 &= ~2; //���1 �� OTKL 
  if(lSt2==1) uprMTZ1 |= 1; //���1 ������� WKL
  else  uprMTZ1 &= ~1; //���1 ������� OTKL 
    
    //����  ���1 ���������� ������ ��������� 
//.	���������
//.	1 -���
//.	0 - ����
    lst3 = brCfgTbl.ownrStg1DrOcp1Mng.DirectionStraight_mcp1;
  if(lst3>0) uprMTZ1 |= 8; //���1 ������ WKL
  else  uprMTZ1 &= ~8; //���1 ������ OTKL 

    //����  ���1 ���������� ����� ��������� 
//.	���������
//.	1 -���
//.	0 - ����
    lst4 = brCfgTbl.ownrStg1DrOcp1Mng.DirectionBack_mcp1;
  if(lst4>0) uprMTZ1 |= 16; //���1 ����� WKL
  else  uprMTZ1 &= ~16; //���1 ����� OTKL 


  SetUstToClon(MTZ_COMP1,  1, MNGUPR_MTZ1, uprMTZ1);//���������� ���1
//    lst2 = brCfgTbl.ownrStg1DrOcp1Mng.select_prt_mcp1;  
  
//-------------MTZ2-----------------------    
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2Pickup.mcp_I_ov_range;
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_time_stage;
  SetUstToClon(MTZ_COMP1,  2, MNGUST_MTZ2to5, lMtz1);//������� ���2 �������
  SetUstToClon(MTZ_COMP1,  2, MNGVID_MTZ2to5, lMtz1Tmr*10);//�������� ���2 �������
  
//.�� �����
//.	 ������� �� ����
//.	 1 �� = 1 �A
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2Pickup.mcp_IstpU_ov_range;
  SetUstToClon(MTZ_COMP1,  2, MNGUST_MTZ2to5_PN, lMtz1);//������� ���2 ��
//.�� U �����
//.	 ������� �� ����� �� ����������
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2Pickup.mcp_Ustp_ov_range;
  SetUstToClon(MTZ_COMP1,  2, MNGUST_MTZ2to5_UPN, lMtz1);//������� ���2 ��

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_Ustp_time_stage;
  SetUstToClon(MTZ_COMP1,  2, MNGVID_MTZ2to5_PN, lMtz1Tmr*10);//�������� ���2 ��

//.�� ���2 �������
//.	 ������� �� ����
//.	 1 �� = 1 �A
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2Pickup.mcp_s1_Ias_ov_range;
  SetUstToClon(MTZ_COMP1,  2, MNGUST_MTZ2to5_V, lMtz1);//������� ����2 ������

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2Pickup.mcp_s2_Iabk_ov_range;
  SetUstToClon(MTZ_COMP1,  2, MNGUST_MTZ2to5_N, lMtz1);//������� ����2 �����
  
//.	�������� ���2 ������
//.	1 �� =10���
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_s1_time_stage;
  SetUstToClon(MTZ_COMP1,  2, MNGVID_MTZ2to5_V, lMtz1Tmr*10);//�������� ���2 ������
//.	�������� ���2 �����
//.	1 �� =10���
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_s2_time_stage;
  SetUstToClon(MTZ_COMP1,  2, MNGVID_MTZ2to5_N, lMtz1Tmr*10);//�������� ���2 �����
  
//���������
  //- �������� ��������� ���2 BB
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_time_stage_Aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5, lMtz1Tmr*10);//��������� ���2 BB
  //- �������� ��������� ���2 ��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_OU, lMtz1Tmr*10);//��������� ���2 ��
  //- �������� ��������� ���2 T�
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_TU, lMtz1Tmr*10);//��������� ���2 T�
  
//- �������� ��������� ������� ����2 ������  
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_s1_T_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_V, lMtz1Tmr*10);//��������� ����2 ������
  //- �������� ��������� ���H2 ������ ��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_s1_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_V_OU, lMtz1Tmr*10);//��������� ���H2 ������ ��
  //- �������� ��������� ���H2 ������ T�
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_s1_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_V_TU, lMtz1Tmr*10);//��������� ���H2 ������ T�
  
//- �������� ��������� ������� ����2 �����
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_s2_T_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_N, lMtz1Tmr*10);//��������� ����2 �����
  //- �������� ��������� ���H2 ����� ��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_s2_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_N_OU, lMtz1Tmr*10);//��������� ���H2 ����� ��
  //- �������� ��������� ���H2 ����� T�
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_s2_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_N_TU, lMtz1Tmr*10);//��������� ���H2 ����� T�
  
//- �������� ��������� ������� ���2��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_Ustp_T_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_PN, lMtz1Tmr*10);//��������� ���2��
  //- �������� ��������� ���2�� ��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_Ustp_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_PN_OU, lMtz1Tmr*10);//��������� ���2��  ��
  //- �������� ��������� ���2�� T�
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_Ustp_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_PN_TU, lMtz1Tmr*10);//��������� ���2��  T�
  
//- �������� ���� ��������� ���2
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_Tau_AcltImp;
  SetUstToClon(MTZ_COMP1,  2, MNGVUSK_MTZ2to5, lMtz1Tmr*10);//���� ��������� ���2
  
    int uprMTZ2=0;
  //����  ��������� ���2    
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg2DrOcp2Mng.state_mcp;
  if(lSt1>0) uprMTZ2 |= 4; //���1  WKL
  else  uprMTZ2 &= ~4; //���1  OTKL 
    //�������� ���2
//.	���������
//.	0 - �������
//.	1 - ���� �� ��������������
//.	2 - ���� �� ����������
    lSt2 = brCfgTbl.ownrStg2DrOcp2Mng.select_prt_mcp;  
  if(lSt2==2) uprMTZ2 |= 2; //���2 �� WKL
  else  uprMTZ2 &= ~2; //���2 �� OTKL 
  if(lSt2==1) uprMTZ2 |= 1; //���2 ������� WKL
  else  uprMTZ2 &= ~1; //���2 ������� OTKL 
    
    //����  ���2 ���������� ������ ��������� 
//.	���������
//.	1 -���
//.	0 - ����
    lst3 = brCfgTbl.ownrStg2DrOcp2Mng.DirectionStraight_mcp;
  if(lst3>0) uprMTZ2 |= 8; //���2 ������ WKL
  else  uprMTZ2 &= ~8; //���2 ������ OTKL 

    //����  ���2 ���������� ����� ��������� 
//.	���������
//.	1 -���
//.	0 - ����
    lst4 = brCfgTbl.ownrStg2DrOcp2Mng.DirectionBack_mcp;
  if(lst4>0) uprMTZ2 |= 16; //���2 ����� WKL
  else  uprMTZ2 &= ~16; //���2 ����� OTKL 

//��������� ���2 BB
    lSt1 = brCfgTbl.ownrStg2DrOcp2Mng.aclt_mcp_sw;  
  if(lSt1>0) uprMTZ2 |= 32; //��� ���2 BB WKL
  else  uprMTZ2 &= ~32; //��� ���2 BB OTKL 

//��������� ���2 AU
    lSt1 = brCfgTbl.ownrStg2DrOcp2Mng.state_Auto_aclt_mcp;  
  if(lSt1>0) uprMTZ2 |= 64; //��� ���2 AU WKL
  else  uprMTZ2 &= ~64; //��� ���2 AU OTKL 

//��������� ���2 TU
    lSt1 = brCfgTbl.ownrStg2DrOcp2Mng.state_Tele_aclt_mcp;  
  if(lSt1>0) uprMTZ2 |= 128; //��� ���2 TU WKL
  else  uprMTZ2 &= ~128; //��� ���2 TU OTKL 
  
  SetUstToClon(MTZ_COMP1,  2, MNGUPR_MTZ2to5, uprMTZ2);//���������� ���2 
  
//-------------MTZ3-----------------------    
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2Pickup.mcp_I_ov_range;
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_time_stage;
  SetUstToClon(MTZ_COMP1,  3, MNGUST_MTZ2to5, lMtz1);//������� ���3 �������
  SetUstToClon(MTZ_COMP1,  3, MNGVID_MTZ2to5, lMtz1Tmr*10);//�������� ���3 �������
  
//.�� �����
//.	 ������� �� ����
//.	 1 �� = 1 �A
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2Pickup.mcp_IstpU_ov_range;
  SetUstToClon(MTZ_COMP1,  3, MNGUST_MTZ2to5_PN, lMtz1);//������� ���3 ��
//.�� U �����
//.	 ������� �� ����� �� ����������
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2Pickup.mcp_Ustp_ov_range;
  SetUstToClon(MTZ_COMP1,  3, MNGUST_MTZ2to5_UPN, lMtz1);//������� ���3 ��

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_Ustp_time_stage;
  SetUstToClon(MTZ_COMP1,  3, MNGVID_MTZ2to5_PN, lMtz1Tmr*10);//�������� ���3 ��

//.�� ���3 �������
//.	 ������� �� ����
//.	 1 �� = 1 �A
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2Pickup.mcp_s1_Ias_ov_range;
  SetUstToClon(MTZ_COMP1,  3, MNGUST_MTZ2to5_V, lMtz1);//������� ����3 ������

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2Pickup.mcp_s2_Iabk_ov_range;
  SetUstToClon(MTZ_COMP1,  3, MNGUST_MTZ2to5_N, lMtz1);//������� ����3 �����
  
//.	�������� ���3 ������
//.	1 �� =10���
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_s1_time_stage;
  SetUstToClon(MTZ_COMP1,  3, MNGVID_MTZ2to5_V, lMtz1Tmr*10);//�������� ���3 ������
//.	�������� ���3 �����
//.	1 �� =10���
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_s2_time_stage;
  SetUstToClon(MTZ_COMP1,  3, MNGVID_MTZ2to5_N, lMtz1Tmr*10);//�������� ���3 �����
  
//���������
  //- �������� ��������� ���3 BB
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_time_stage_Aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5, lMtz1Tmr*10);//��������� ���3 BB
  //- �������� ��������� ���3 ��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_OU, lMtz1Tmr*10);//��������� ���3 ��
  //- �������� ��������� ���3 T�
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_TU, lMtz1Tmr*10);//��������� ���3 T�
  
//- �������� ��������� ������� ����3 ������  
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_s1_T_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_V, lMtz1Tmr*10);//��������� ����3 ������
  //- �������� ��������� ���H3 ������ ��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_s1_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_V_OU, lMtz1Tmr*10);//��������� ���H3 ������ ��
  //- �������� ��������� ���H3 ������ T�
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_s1_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_V_TU, lMtz1Tmr*10);//��������� ���H3 ������ T�
  
//- �������� ��������� ������� ����3 �����
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_s2_T_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_N, lMtz1Tmr*10);//��������� ����3 �����
  //- �������� ��������� ���H3 ����� ��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_s2_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_N_OU, lMtz1Tmr*10);//��������� ���H3 ����� ��
  //- �������� ��������� ���H3 ����� T�
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_s2_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_N_TU, lMtz1Tmr*10);//��������� ���H3 ����� T�
  
//- �������� ��������� ������� ���3��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_Ustp_T_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_PN, lMtz1Tmr*10);//��������� ���3��
  //- �������� ��������� ���3�� ��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_Ustp_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_PN_OU, lMtz1Tmr*10);//��������� ���3��  ��
  //- �������� ��������� ���3�� T�
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_Ustp_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_PN_TU, lMtz1Tmr*10);//��������� ���3��  T�
  
//- �������� ���� ��������� ���3
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_Tau_AcltImp;
  SetUstToClon(MTZ_COMP1,  3, MNGVUSK_MTZ2to5, lMtz1Tmr*10);//���� ��������� ���3
  
    int uprMTZ3=0;
  //����  ��������� ���3
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg3DrOcp2Mng.state_mcp;
  if(lSt1>0) uprMTZ3 |= 4; //���3  WKL
  else  uprMTZ3 &= ~4; //���3  OTKL 
    //�������� ���3
//.	���������
//.	0 - �������
//.	1 - ���� �� ��������������
//.	2 - ���� �� ����������
    lSt2 = brCfgTbl.ownrStg3DrOcp2Mng.select_prt_mcp;  
  if(lSt2==2) uprMTZ3 |= 2; //���3 �� WKL
  else  uprMTZ3 &= ~2; //���3 �� OTKL 
  if(lSt2==1) uprMTZ3 |= 1; //���3 ������� WKL
  else  uprMTZ3 &= ~1; //���3 ������� OTKL 
    
    //����  ���3 ���������� ������ ��������� 
//.	���������
//.	1 -���
//.	0 - ����
    lst3 = brCfgTbl.ownrStg3DrOcp2Mng.DirectionStraight_mcp;
  if(lst3>0) uprMTZ3 |= 8; //���3 ������ WKL
  else  uprMTZ3 &= ~8; //���3 ������ OTKL 

    //����  ���3 ���������� ����� ��������� 
//.	���������
//.	1 -���
//.	0 - ����
    lst4 = brCfgTbl.ownrStg3DrOcp2Mng.DirectionBack_mcp;
  if(lst4>0) uprMTZ3 |= 16; //���3 ����� WKL
  else  uprMTZ3 &= ~16; //���3 ����� OTKL 

//��������� ���3 BB
    lSt1 = brCfgTbl.ownrStg3DrOcp2Mng.aclt_mcp_sw;  
  if(lSt1>0) uprMTZ3 |= 32; //��� ���3 BB WKL
  else  uprMTZ3 &= ~32; //��� ���3 BB OTKL 

//��������� ���3 AU
    lSt1 = brCfgTbl.ownrStg3DrOcp2Mng.state_Auto_aclt_mcp;  
  if(lSt1>0) uprMTZ3 |= 64; //��� ���3 AU WKL
  else  uprMTZ3 &= ~64; //��� ���3 AU OTKL 

//��������� ���3 TU
    lSt1 = brCfgTbl.ownrStg3DrOcp2Mng.state_Tele_aclt_mcp;  
  if(lSt1>0) uprMTZ3 |= 128; //��� ���3 TU WKL
  else  uprMTZ3 &= ~128; //��� ���3 TU OTKL 
  
  SetUstToClon(MTZ_COMP1,  3, MNGUPR_MTZ2to5, uprMTZ3);//���������� ���3

//-------------MTZ4-----------------------    
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2Pickup.mcp_I_ov_range;
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_time_stage;
  SetUstToClon(MTZ_COMP1,  4, MNGUST_MTZ2to5, lMtz1);//������� ���4 �������
  SetUstToClon(MTZ_COMP1,  4, MNGVID_MTZ2to5, lMtz1Tmr*10);//�������� ���4 �������
  
//.�� �����
//.	 ������� �� ����
//.	 1 �� = 1 �A
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2Pickup.mcp_IstpU_ov_range;
  SetUstToClon(MTZ_COMP1,  4, MNGUST_MTZ2to5_PN, lMtz1);//������� ���4 ��
//.�� U �����
//.	 ������� �� ����� �� ����������
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2Pickup.mcp_Ustp_ov_range;
  SetUstToClon(MTZ_COMP1,  4, MNGUST_MTZ2to5_UPN, lMtz1);//������� ���4 ��

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_Ustp_time_stage;
  SetUstToClon(MTZ_COMP1,  4, MNGVID_MTZ2to5_PN, lMtz1Tmr*10);//�������� ���4 ��

//.�� ���3 �������
//.	 ������� �� ����
//.	 1 �� = 1 �A
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2Pickup.mcp_s1_Ias_ov_range;
  SetUstToClon(MTZ_COMP1,  4, MNGUST_MTZ2to5_V, lMtz1);//������� ����4 ������

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2Pickup.mcp_s2_Iabk_ov_range;
  SetUstToClon(MTZ_COMP1,  4, MNGUST_MTZ2to5_N, lMtz1);//������� ����4 �����
  
//.	�������� ���4 ������
//.	1 �� =10���
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_s1_time_stage;
  SetUstToClon(MTZ_COMP1,  4, MNGVID_MTZ2to5_V, lMtz1Tmr*10);//�������� ���4 ������
//.	�������� ���4 �����
//.	1 �� =10���
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_s2_time_stage;
  SetUstToClon(MTZ_COMP1,  4, MNGVID_MTZ2to5_N, lMtz1Tmr*10);//�������� ���4 �����
  
//���������
  //- �������� ��������� ���4 BB
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_time_stage_Aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5, lMtz1Tmr*10);//��������� ���4 BB
  //- �������� ��������� ���4 ��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_OU, lMtz1Tmr*10);//��������� ���4 ��
  //- �������� ��������� ���4 T�
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_TU, lMtz1Tmr*10);//��������� ���4 T�
  
//- �������� ��������� ������� ����4 ������  
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_s1_T_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_V, lMtz1Tmr*10);//��������� ����4 ������
  //- �������� ��������� ���H4 ������ ��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_s1_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_V_OU, lMtz1Tmr*10);//��������� ���H4 ������ ��
  //- �������� ��������� ���H4 ������ T�
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_s1_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_V_TU, lMtz1Tmr*10);//��������� ���H4 ������ T�
  
//- �������� ��������� ������� ����4 �����
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_s2_T_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_N, lMtz1Tmr*10);//��������� ����4 �����
  //- �������� ��������� ���H4 ����� ��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_s2_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_N_OU, lMtz1Tmr*10);//��������� ���H4 ����� ��
  //- �������� ��������� ���H4 ����� T�
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_s2_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_N_TU, lMtz1Tmr*10);//��������� ���H4 ����� T�
  
//- �������� ��������� ������� ���4��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_Ustp_T_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_PN, lMtz1Tmr*10);//��������� ���4��
  //- �������� ��������� ���4�� ��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_Ustp_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_PN_OU, lMtz1Tmr*10);//��������� ���4��  ��
  //- �������� ��������� ���4�� T�
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_Ustp_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_PN_TU, lMtz1Tmr*10);//��������� ���4��  T�
  
//- �������� ���� ��������� ���4
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_Tau_AcltImp;
  SetUstToClon(MTZ_COMP1,  4, MNGVUSK_MTZ2to5, lMtz1Tmr*10);//���� ��������� ���4
  
    int uprMTZ4=0;
  //����  ��������� ���4
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg4DrOcp2Mng.state_mcp;
  if(lSt1>0) uprMTZ4 |= 4; //���4  WKL
  else  uprMTZ4 &= ~4; //���4  OTKL 
    //�������� ���4
//.	���������
//.	0 - �������
//.	1 - ���� �� ��������������
//.	2 - ���� �� ����������
    lSt2 = brCfgTbl.ownrStg4DrOcp2Mng.select_prt_mcp;  
  if(lSt2==2) uprMTZ4 |= 2; //���4 �� WKL
  else  uprMTZ4 &= ~2; //���4 �� OTKL 
  if(lSt2==1) uprMTZ4 |= 1; //���4 ������� WKL
  else  uprMTZ4 &= ~1; //���4 ������� OTKL 
    
    //����  ���4 ���������� ������ ��������� 
//.	���������
//.	1 -���
//.	0 - ����
    lst3 = brCfgTbl.ownrStg4DrOcp2Mng.DirectionStraight_mcp;
  if(lst3>0) uprMTZ4 |= 8; //���4 ������ WKL
  else  uprMTZ4 &= ~8; //���4 ������ OTKL 

    //����  ���4 ���������� ����� ��������� 
//.	���������
//.	1 -���
//.	0 - ����
    lst4 = brCfgTbl.ownrStg4DrOcp2Mng.DirectionBack_mcp;
  if(lst4>0) uprMTZ4 |= 16; //���3 ����� WKL
  else  uprMTZ4 &= ~16; //���3 ����� OTKL 

//��������� ���4 BB
    lSt1 = brCfgTbl.ownrStg4DrOcp2Mng.aclt_mcp_sw;  
  if(lSt1>0) uprMTZ4 |= 32; //��� ���4 BB WKL
  else  uprMTZ4 &= ~32; //��� ���4 BB OTKL 

//��������� ���4 AU
    lSt1 = brCfgTbl.ownrStg4DrOcp2Mng.state_Auto_aclt_mcp;  
  if(lSt1>0) uprMTZ4 |= 64; //��� ���4 AU WKL
  else  uprMTZ4 &= ~64; //��� ���4 AU OTKL 

//��������� ���4 TU
    lSt1 = brCfgTbl.ownrStg4DrOcp2Mng.state_Tele_aclt_mcp;  
  if(lSt1>0) uprMTZ4 |= 128; //��� ���4 TU WKL
  else  uprMTZ4 &= ~128; //��� ���4 TU OTKL 
  
  SetUstToClon(MTZ_COMP1,  4, MNGUPR_MTZ2to5, uprMTZ4);//���������� ���4

//-------------MTZ5-----------------------    
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2Pickup.mcp_I_ov_range;
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_time_stage;
  SetUstToClon(MTZ_COMP1,  5, MNGUST_MTZ2to5, lMtz1);//������� ���5 �������
  SetUstToClon(MTZ_COMP1,  5, MNGVID_MTZ2to5, lMtz1Tmr*10);//�������� ���5 �������
  
//.�� �����
//.	 ������� �� ����
//.	 1 �� = 1 �A
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2Pickup.mcp_IstpU_ov_range;
  SetUstToClon(MTZ_COMP1,  5, MNGUST_MTZ2to5_PN, lMtz1);//������� ���5 ��
//.�� U �����
//.	 ������� �� ����� �� ����������
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2Pickup.mcp_Ustp_ov_range;
  SetUstToClon(MTZ_COMP1,  5, MNGUST_MTZ2to5_UPN, lMtz1);//������� ���5 ��

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_Ustp_time_stage;
  SetUstToClon(MTZ_COMP1,  5, MNGVID_MTZ2to5_PN, lMtz1Tmr*10);//�������� ���5 ��

//.�� ���5 �������
//.	 ������� �� ����
//.	 1 �� = 1 �A
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2Pickup.mcp_s1_Ias_ov_range;
  SetUstToClon(MTZ_COMP1,  5, MNGUST_MTZ2to5_V, lMtz1);//������� ����5 ������

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2Pickup.mcp_s2_Iabk_ov_range;
  SetUstToClon(MTZ_COMP1,  5, MNGUST_MTZ2to5_N, lMtz1);//������� ����5 �����
  
//.	�������� ���5 ������
//.	1 �� =10���
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_s1_time_stage;
  SetUstToClon(MTZ_COMP1,  5, MNGVID_MTZ2to5_V, lMtz1Tmr*10);//�������� ���5 ������
//.	�������� ���5 �����
//.	1 �� =10���
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_s2_time_stage;
  SetUstToClon(MTZ_COMP1,  5, MNGVID_MTZ2to5_N, lMtz1Tmr*10);//�������� ���5 �����
  
//���������
  //- �������� ��������� ���5 BB
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_time_stage_Aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5, lMtz1Tmr*10);//��������� ���5 BB
  //- �������� ��������� ���4 ��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_OU, lMtz1Tmr*10);//��������� ���5 ��
  //- �������� ��������� ���5 T�
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_TU, lMtz1Tmr*10);//��������� ���5 T�
  
//- �������� ��������� ������� ����5 ������  
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_s1_T_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_V, lMtz1Tmr*10);//��������� ����5 ������
  //- �������� ��������� ���H5 ������ ��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_s1_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_V_OU, lMtz1Tmr*10);//��������� ���H5 ������ ��
  //- �������� ��������� ���H5 ������ T�
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_s1_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_V_TU, lMtz1Tmr*10);//��������� ���H5 ������ T�
  
//- �������� ��������� ������� ����5 �����
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_s2_T_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_N, lMtz1Tmr*10);//��������� ����5 �����
  //- �������� ��������� ���H5 ����� ��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_s2_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_N_OU, lMtz1Tmr*10);//��������� ���H5 ����� ��
  //- �������� ��������� ���H5 ����� T�
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_s2_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_N_TU, lMtz1Tmr*10);//��������� ���H5 ����� T�
  
//- �������� ��������� ������� ���5��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_Ustp_T_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_PN, lMtz1Tmr*10);//��������� ���5��
  //- �������� ��������� ���5�� ��
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_Ustp_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_PN_OU, lMtz1Tmr*10);//��������� ���5��  ��
  //- �������� ��������� ���5�� T�
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_Ustp_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_PN_TU, lMtz1Tmr*10);//��������� ���5��  T�
  
//- �������� ���� ��������� ���5
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_Tau_AcltImp;
  SetUstToClon(MTZ_COMP1,  5, MNGVUSK_MTZ2to5, lMtz1Tmr*10);//���� ��������� ���5
  
    int uprMTZ5=0;
  //����  ��������� ���5
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg5DrOcp2Mng.state_mcp;
  if(lSt1>0) uprMTZ5 |= 4; //���5  WKL
  else  uprMTZ5 &= ~4; //���5  OTKL 
    //�������� ���5
//.	���������
//.	0 - �������
//.	1 - ���� �� ��������������
//.	2 - ���� �� ����������
    lSt2 = brCfgTbl.ownrStg5DrOcp2Mng.select_prt_mcp;  
  if(lSt2==2) uprMTZ5 |= 2; //���5 �� WKL
  else  uprMTZ5 &= ~2; //���5 �� OTKL 
  if(lSt2==1) uprMTZ5 |= 1; //���5 ������� WKL
  else  uprMTZ5 &= ~1; //���5 ������� OTKL 
    
    //����  ���5 ���������� ������ ��������� 
//.	���������
//.	1 -���
//.	0 - ����
    lst3 = brCfgTbl.ownrStg5DrOcp2Mng.DirectionStraight_mcp;
  if(lst3>0) uprMTZ5 |= 8; //���5 ������ WKL
  else  uprMTZ5 &= ~8; //���5 ������ OTKL 

    //����  ���5 ���������� ����� ��������� 
//.	���������
//.	1 -���
//.	0 - ����
    lst4 = brCfgTbl.ownrStg5DrOcp2Mng.DirectionBack_mcp;
  if(lst4>0) uprMTZ5 |= 16; //���5 ����� WKL
  else  uprMTZ5 &= ~16; //���5 ����� OTKL 

//��������� ���5 BB
    lSt1 = brCfgTbl.ownrStg5DrOcp2Mng.aclt_mcp_sw;  
  if(lSt1>0) uprMTZ5 |= 32; //��� ���5 BB WKL
  else  uprMTZ5 &= ~32; //��� ���5 BB OTKL 

//��������� ���5 AU
    lSt1 = brCfgTbl.ownrStg5DrOcp2Mng.state_Auto_aclt_mcp;  
  if(lSt1>0) uprMTZ5 |= 64; //��� ���5 AU WKL
  else  uprMTZ5 &= ~64; //��� ���5 AU OTKL 

//��������� ���5 TU
    lSt1 = brCfgTbl.ownrStg5DrOcp2Mng.state_Tele_aclt_mcp;  
  if(lSt1>0) uprMTZ5 |= 128; //��� ���5 TU WKL
  else  uprMTZ5 &= ~128; //��� ���5 TU OTKL 
  
  SetUstToClon(MTZ_COMP1,  5, MNGUPR_MTZ2to5, uprMTZ5);//���������� ���5
/*  
  int uprPRM1 = 0;
    lSt1 = brCfgTbl.state_FaultU_Ocp;//������ ����� ����
  if(lSt1>0) uprPRM1 |= 1; // WKL
  else  uprPRM1 &= ~1; // OTKL 
  
  SetUstToClon(PRM1_COMP1,  1, MNGUPR_PRM1, uprPRM1);//���������� PRM1
*/
}//SettingIci_MTZ()
