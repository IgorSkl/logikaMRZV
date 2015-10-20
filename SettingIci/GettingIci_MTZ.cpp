/*
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
*/

#include "bazisdef.h"

#include "psuperVisor\supermanager.h"

#include "component\componentdef.h"
#include "psuperVisor\psvisor_helpdef.h"

#include "psuperVisor\psvisor_helpfnc.h"
#include "SettingIci\SettingIci.h"
#include "virtualmenu\systemmenufnc.h"

//#include "toSpeedOptim.h"
//#include "toSpeedDIS.h"

//#include "header.h"
//#include "ici_r_ef.h"

#define _HIDE_COMPONENT
#include "MTZ1Component.cpp"
#include "MTZ2Component.cpp"

//extern char chProtectTableComeIn;
//extern char chResultCallGetMeasPrt;
//extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
//extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

void  GettingIci_MTZ()
{
//�������� ��������� ICI ��� 
 int numBlok=0;
//-------------MTZ1-----------------------
int tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  1, MNGUST_MTZ1);//������� ���1 �������
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1DrOcp1Pickup.mcp1_I_ov_range;

    tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  1, MNGVID_MTZ1);//�������� ���1 �������
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1DrOcp1StageParam.mcp1_time_stage;

//.�� �����1
//.	 ������� �� ����
//.	 1 �� = 1 �A
    tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  1, MNGUST_MTZ1_PN);//������� ���1 ��
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1DrOcp1Pickup.mcp1_IstpU_ov_range;

//.�� U �����1
//.	 ������� �� ����� �� ����������
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  1, MNGUST_MTZ1_UPN);//������� ���1 �� 
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1DrOcp1Pickup.mcp1_Ustp_ov_range;
//.T �����1
//.	�������� 1- ������� ���
//.	1 �� =10���
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  1, MNGVID_MTZ1_PN);//�������� ���1 ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1DrOcp1StageParam.mcp1_Ustp_time_stage;

//.�� ���1 �������
//.	 ������� �� ����
//.	 1 �� = 1 �A
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  1, MNGUST_MTZ1_V);//������� ����1 ������
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1DrOcp1Pickup.mcp1_s1_Ias_ov_range;

   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  1, MNGUST_MTZ1_N);//������� ����1 �����
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1DrOcp1Pickup.mcp1_s2_Iabk_ov_range;
//.	�������� ���1 ������
//.	1 �� =10���
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  1, MNGVID_MTZ1_V);//�������� ���1 ������
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1DrOcp1StageParam.mcp1_s1_time_stage;
//.	�������� ���1 �����
//.	1 �� =10���
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  1, MNGVID_MTZ1_N);//�������� ���1 ������
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1DrOcp1StageParam.mcp1_s2_time_stage;

    tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  1, MNGUPR_MTZ1);//���������� ���1
/*
//  int uprMTZ1=0;
  //����  ��������� ���1    
//.	���������
//.	1 -���
//.	0 - ����
  int tmp = 0;
  if(tmpUst&4) tmp = 1;
  brCfgTbl.ownrStg1DrOcp1Mng.state_mcp1 = tmp;
//    lSt1 = brCfgTbl.ownrStg1DrOcp1Mng.state_mcp1;
  //if(lSt1>0) uprMTZ1 |= 4; //���1 ������� WKL
//  else  uprMTZ1 &= ~4; //���1 ������� OTKL 
    //�������� ���1
//.	���������
//.	0 - �������
//.	1 - ���� �� ��������������
//.	2 - ���� �� ����������
  tmp = 0;
  if(tmpUst&1) tmp = 1;
  if(tmpUst&2) tmp = 2;
  ownrStg1DrOcp1Mng.select_prt_mcp1 = tmp;
//    lSt2 = brCfgTbl.ownrStg1DrOcp1Mng.select_prt_mcp1;  
//  if(lSt2==2) uprMTZ1 |= 2; //���1 �� WKL
//  else  uprMTZ1 &= ~2; //���1 �� OTKL 
//  if(lSt2==1) uprMTZ1 |= 1; //���1 ������� WKL
//  else  uprMTZ1 &= ~1; //���1 ������� OTKL 
    
    //����  ���1 ���������� ������ ��������� 
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&8) tmp = 1;
  brCfgTbl.ownrStg1DrOcp1Mng.DirectionStraight_mcp1 = tmp;
//    lst3 = brCfgTbl.ownrStg1DrOcp1Mng.DirectionStraight_mcp1;
//  if(lst3>0) uprMTZ1 |= 8; //���1 ������ WKL
//  else  uprMTZ1 &= ~8; //���1 ������ OTKL 

    //����  ���1 ���������� ����� ��������� 
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&16) tmp = 1;
  brCfgTbl.ownrStg1DrOcp1Mng.DirectionBack_mcp1 = tmp;
//    lst4 = brCfgTbl.ownrStg1DrOcp1Mng.DirectionBack_mcp1;
//  if(lst4>0) uprMTZ1 |= 16; //���1 ����� WKL
//  else  uprMTZ1 &= ~16; //���1 ����� OTKL 

//  SetUstToClon(MTZ_COMP1,  1, MNGUPR_MTZ1, uprMTZ1);//���������� ���1
*/
  
//-------------MTZ2-----------------------    
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGUST_MTZ2to5);//������� ���2 �������
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2Pickup.mcp_I_ov_range;

   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGVID_MTZ2to5);//�������� ���2 �������
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2StageParam.mcp_time_stage;
  
//.�� �����
//.	 ������� �� ����
//.	 1 �� = 1 �A
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGUST_MTZ2to5_PN);//������� ���2 ��
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2Pickup.mcp_IstpU_ov_range;
//.�� U �����
//.	 ������� �� ����� �� ����������
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGUST_MTZ2to5_UPN);//������� ���2 ��
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2Pickup.mcp_Ustp_ov_range;

   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGVID_MTZ2to5_PN);//�������� ���2 ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2StageParam.mcp_Ustp_time_stage;

//.�� ���2 �������
//.	 ������� �� ����
//.	 1 �� = 1 �A
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGUST_MTZ2to5_V);//������� ����2 ������
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2Pickup.mcp_s1_Ias_ov_range;

   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGUST_MTZ2to5_N);//������� ����2 �����
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2Pickup.mcp_s2_Iabk_ov_range;
  
//.	�������� ���2 ������
//.	1 �� =10���
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGVID_MTZ2to5_V);//�������� ���2 ������
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2StageParam.mcp_s1_time_stage;
//.	�������� ���2 �����
//.	1 �� =10���
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGVID_MTZ2to5_N);//�������� ���2 �����
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2StageParam.mcp_s2_time_stage;
  
//���������
  //- �������� ��������� ���2 BB
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGUSK_MTZ2to5);//��������� ���2 BB
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2StageParam.mcp_time_stage_Aclt;
  //- �������� ��������� ���2 ��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGUSK_MTZ2to5_OU);//��������� ���2 ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2StageParam.mcp_T_op_aclt;
  //- �������� ��������� ���2 T�
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGUSK_MTZ2to5_TU);//��������� ���2 T�
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2StageParam.mcp_T_tele_aclt;
  
//- �������� ��������� ������� ����2 ������  
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGUSK_MTZ2to5_V);//��������� ����2 ������
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2StageParam.mcp_s1_T_aclt;
  //- �������� ��������� ���H2 ������ ��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGUSK_MTZ2to5_V_OU);//��������� ���H2 ������ ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2StageParam.mcp_s1_T_op_aclt;
  //- �������� ��������� ���H2 ������ T�
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGUSK_MTZ2to5_V_TU);//��������� ���H2 ������ T�
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2StageParam.mcp_s1_T_tele_aclt;
  
//- �������� ��������� ������� ����2 �����
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGUSK_MTZ2to5_N);//��������� ����2 �����
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2StageParam.mcp_s2_T_aclt;
  //- �������� ��������� ���H2 ����� ��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGUSK_MTZ2to5_N_OU);//��������� ���H2 ����� ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2StageParam.mcp_s2_T_op_aclt;
  //- �������� ��������� ���H2 ����� T�
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGUSK_MTZ2to5_N_TU);//��������� ���H2 ����� T�
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2StageParam.mcp_s2_T_tele_aclt;
  
//- �������� ��������� ������� ���2��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGUSK_MTZ2to5_PN);//��������� ���2��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2StageParam.mcp_Ustp_T_aclt;
  //- �������� ��������� ���2�� ��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGUSK_MTZ2to5_PN_OU);//��������� ���2��  ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2StageParam.mcp_Ustp_T_op_aclt;
  //- �������� ��������� ���2�� T�
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGUSK_MTZ2to5_PN_TU);//��������� ���2��  T�
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2StageParam.mcp_Ustp_T_tele_aclt;
  
//- �������� ���� ��������� ���2
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGVUSK_MTZ2to5);//���� ��������� ���2
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2DrOcp2StageParam.mcp_Tau_AcltImp;
  
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  2, MNGUPR_MTZ2to5);//���������� ���2 
/*
//    int uprMTZ2=0;
  //����  ��������� ���2    
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&4) tmp = 1;
  brCfgTbl.ownrStg2DrOcp2Mng.state_mcp = tmp;
//    lSt1 = brCfgTbl.ownrStg2DrOcp2Mng.state_mcp;
//  if(lSt1>0) uprMTZ2 |= 4; //���1  WKL
//  else  uprMTZ2 &= ~4; //���1  OTKL 
    //�������� ���2
//.	���������
//.	0 - �������
//.	1 - ���� �� ��������������
//.	2 - ���� �� ����������
  tmp = 0;
  if(tmpUst&1) tmp = 1;
  if(tmpUst&2) tmp = 2;
  brCfgTbl.ownrStg2DrOcp2Mng.select_prt_mcp = tmp;
//    lSt2 = brCfgTbl.ownrStg2DrOcp2Mng.select_prt_mcp;  
//  if(lSt2==2) uprMTZ2 |= 2; //���2 �� WKL
//  else  uprMTZ2 &= ~2; //���2 �� OTKL 
//  if(lSt2==1) uprMTZ2 |= 1; //���2 ������� WKL
//  else  uprMTZ2 &= ~1; //���2 ������� OTKL 
    
    //����  ���2 ���������� ������ ��������� 
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&8) tmp = 1;
  brCfgTbl.ownrStg2DrOcp2Mng.DirectionStraight_mcp = tmp;
//    lst3 = brCfgTbl.ownrStg2DrOcp2Mng.DirectionStraight_mcp;
//  if(lst3>0) uprMTZ2 |= 8; //���2 ������ WKL
//  else  uprMTZ2 &= ~8; //���2 ������ OTKL

    //����  ���2 ���������� ����� ��������� 
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&16) tmp = 1;
  brCfgTbl.ownrStg2DrOcp2Mng.DirectionBack_mcp = tmp;
//    lst4 = brCfgTbl.ownrStg2DrOcp2Mng.DirectionBack_mcp;
//  if(lst4>0) uprMTZ2 |= 16; //���2 ����� WKL
//  else  uprMTZ2 &= ~16; //���2 ����� OTKL 

//��������� ���2 BB
  tmp = 0;
  if(tmpUst&32) tmp = 1;
  brCfgTbl.ownrStg2DrOcp2Mng.aclt_mcp_sw = tmp;
//    lSt1 = brCfgTbl.ownrStg2DrOcp2Mng.aclt_mcp_sw;  
//  if(lSt1>0) uprMTZ2 |= 32; //��� ���2 BB WKL
//  else  uprMTZ2 &= ~32; //��� ���2 BB OTKL 

//��������� ���2 AU
  tmp = 0;
  if(tmpUst&64) tmp = 1;
  brCfgTbl.ownrStg2DrOcp2Mng.state_Auto_aclt_mcp = tmp;
//    lSt1 = brCfgTbl.ownrStg2DrOcp2Mng.state_Auto_aclt_mcp;  
//  if(lSt1>0) uprMTZ2 |= 64; //��� ���2 AU WKL
//  else  uprMTZ2 &= ~64; //��� ���2 AU OTKL 

//��������� ���2 TU
  tmp = 0;
  if(tmpUst&128) tmp = 1;
  brCfgTbl.ownrStg2DrOcp2Mng.state_Tele_aclt_mcp = tmp;
//    lSt1 = brCfgTbl.ownrStg2DrOcp2Mng.state_Tele_aclt_mcp;  
//  if(lSt1>0) uprMTZ2 |= 128; //��� ���2 TU WKL
//  else  uprMTZ2 &= ~128; //��� ���2 TU OTKL 
  
//  SetUstToClon(MTZ_COMP1,  2, MNGUPR_MTZ2to5, uprMTZ2);//���������� ���2 
//*/  
//-------------MTZ3-----------------------    
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGVID_MTZ2to5);//�������� ���3 �������
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2Pickup.mcp_I_ov_range;
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGUST_MTZ2to5);//������� ���3 �������
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2StageParam.mcp_time_stage;
  
//.�� �����
//.	 ������� �� ����
//.	 1 �� = 1 �A
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGUST_MTZ2to5_PN);//������� ���3 ��
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2Pickup.mcp_IstpU_ov_range;
//.�� U �����
//.	 ������� �� ����� �� ����������
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGUST_MTZ2to5_UPN);//������� ���3 ��
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2Pickup.mcp_Ustp_ov_range;

   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGVID_MTZ2to5_PN);//�������� ���3 ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2StageParam.mcp_Ustp_time_stage;

//.�� ���3 �������
//.	 ������� �� ����
//.	 1 �� = 1 �A
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGUST_MTZ2to5_V);//������� ����3 ������
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2Pickup.mcp_s1_Ias_ov_range;

   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGUST_MTZ2to5_N);//������� ����3 �����
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2Pickup.mcp_s2_Iabk_ov_range;
  
//.	�������� ���3 ������
//.	1 �� =10���
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGVID_MTZ2to5_V);//�������� ���3 ������
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2StageParam.mcp_s1_time_stage;
//.	�������� ���3 �����
//.	1 �� =10���
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGVID_MTZ2to5_N);//�������� ���3 �����
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2StageParam.mcp_s2_time_stage;
  
//���������
  //- �������� ��������� ���3 BB
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGUSK_MTZ2to5);//��������� ���3 BB
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2StageParam.mcp_time_stage_Aclt;
  //- �������� ��������� ���3 ��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGUSK_MTZ2to5_OU);//��������� ���3 ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2StageParam.mcp_T_op_aclt;
  //- �������� ��������� ���3 T�
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGUSK_MTZ2to5_TU);//��������� ���3 T�
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2StageParam.mcp_T_tele_aclt;
  
//- �������� ��������� ������� ����3 ������  
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGUSK_MTZ2to5_V);//��������� ����3 ������
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2StageParam.mcp_s1_T_aclt;
  //- �������� ��������� ���H3 ������ ��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGUSK_MTZ2to5_V_OU);//��������� ���H3 ������ ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2StageParam.mcp_s1_T_op_aclt;
  //- �������� ��������� ���H3 ������ T�
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGUSK_MTZ2to5_V_TU);//��������� ���H3 ������ T�
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2StageParam.mcp_s1_T_tele_aclt;
  
//- �������� ��������� ������� ����3 �����
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGUSK_MTZ2to5_N);//��������� ����3 �����
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2StageParam.mcp_s2_T_aclt;
  //- �������� ��������� ���H3 ����� ��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGUSK_MTZ2to5_N_OU);//��������� ���H3 ����� ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2StageParam.mcp_s2_T_op_aclt;
  //- �������� ��������� ���H3 ����� T�
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGUSK_MTZ2to5_N_TU);//��������� ���H3 ����� T�
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2StageParam.mcp_s2_T_tele_aclt;
  
//- �������� ��������� ������� ���3��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGUSK_MTZ2to5_PN);//��������� ���3��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2StageParam.mcp_Ustp_T_aclt;
  //- �������� ��������� ���3�� ��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGUSK_MTZ2to5_PN_OU);//��������� ���3��  ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2StageParam.mcp_Ustp_T_op_aclt;
  //- �������� ��������� ���3�� T�
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGUSK_MTZ2to5_PN_TU);//��������� ���3��  T�
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2StageParam.mcp_Ustp_T_tele_aclt;
  
//- �������� ���� ��������� ���3
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGVUSK_MTZ2to5);//���� ��������� ���3
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3DrOcp2StageParam.mcp_Tau_AcltImp;
  
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  3, MNGUPR_MTZ2to5);//���������� ���3
/*
//    int uprMTZ3=0;
  //����  ��������� ���3
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&4) tmp = 1;
  brCfgTbl.ownrStg3DrOcp2Mng.state_mcp = tmp;
//    lSt1 = brCfgTbl.ownrStg3DrOcp2Mng.state_mcp;
//  if(lSt1>0) uprMTZ3 |= 4; //���3  WKL
//  else  uprMTZ3 &= ~4; //���3  OTKL 
    //�������� ���3
//.	���������
//.	0 - �������
//.	1 - ���� �� ��������������
//.	2 - ���� �� ����������
  tmp = 0;
  if(tmpUst&1) tmp = 1;
  if(tmpUst&2) tmp = 2;
  brCfgTbl.ownrStg3DrOcp2Mng.select_prt_mcp = tmp;
//    lSt2 = brCfgTbl.ownrStg3DrOcp2Mng.select_prt_mcp;  
//  if(lSt2==2) uprMTZ3 |= 2; //���3 �� WKL
//  else  uprMTZ3 &= ~2; //���3 �� OTKL 
//  if(lSt2==1) uprMTZ3 |= 1; //���3 ������� WKL
//  else  uprMTZ3 &= ~1; //���3 ������� OTKL 
    
    //����  ���3 ���������� ������ ��������� 
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&8) tmp = 1;
  brCfgTbl.ownrStg3DrOcp2Mng.DirectionStraight_mcp = tmp;
//    lst3 = brCfgTbl.ownrStg3DrOcp2Mng.DirectionStraight_mcp;
//  if(lst3>0) uprMTZ3 |= 8; //���3 ������ WKL
//  else  uprMTZ3 &= ~8; //���3 ������ OTKL 

    //����  ���3 ���������� ����� ��������� 
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&16) tmp = 1;
  brCfgTbl.ownrStg3DrOcp2Mng.DirectionBack_mcp = tmp;
//    lst4 = brCfgTbl.ownrStg3DrOcp2Mng.DirectionBack_mcp;
//  if(lst4>0) uprMTZ3 |= 16; //���3 ����� WKL
//  else  uprMTZ3 &= ~16; //���3 ����� OTKL 

//��������� ���3 BB
  tmp = 0;
  if(tmpUst&32) tmp = 1;
  brCfgTbl.ownrStg3DrOcp2Mng.aclt_mcp_sw = tmp;
//    lSt1 = brCfgTbl.ownrStg3DrOcp2Mng.aclt_mcp_sw;  
//  if(lSt1>0) uprMTZ3 |= 32; //��� ���3 BB WKL
//  else  uprMTZ3 &= ~32; //��� ���3 BB OTKL 

//��������� ���3 AU
  tmp = 0;
  if(tmpUst&64) tmp = 1;
  brCfgTbl.ownrStg3DrOcp2Mng.state_Auto_aclt_mcp = tmp;
//    lSt1 = brCfgTbl.ownrStg3DrOcp2Mng.state_Auto_aclt_mcp;  
//  if(lSt1>0) uprMTZ3 |= 64; //��� ���3 AU WKL
//  else  uprMTZ3 &= ~64; //��� ���3 AU OTKL 

//��������� ���3 TU
  tmp = 0;
  if(tmpUst&128) tmp = 1;
  brCfgTbl.ownrStg3DrOcp2Mng.state_Tele_aclt_mcp = tmp;
//    lSt1 = brCfgTbl.ownrStg3DrOcp2Mng.state_Tele_aclt_mcp;  
//  if(lSt1>0) uprMTZ3 |= 128; //��� ���3 TU WKL
//  else  uprMTZ3 &= ~128; //��� ���3 TU OTKL 
  
//  SetUstToClon(MTZ_COMP1,  3, MNGUPR_MTZ2to5, uprMTZ3);//���������� ���3
*/
//-------------MTZ4-----------------------    
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGUST_MTZ2to5);//������� ���4 �������
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2Pickup.mcp_I_ov_range;
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGVID_MTZ2to5);//�������� ���4 �������
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2StageParam.mcp_time_stage;
  
//.�� �����
//.	 ������� �� ����
//.	 1 �� = 1 �A
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGUST_MTZ2to5_PN);//������� ���4 ��
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2Pickup.mcp_IstpU_ov_range;
//.�� U �����
//.	 ������� �� ����� �� ����������
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGUST_MTZ2to5_UPN);//������� ���4 ��
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2Pickup.mcp_Ustp_ov_range;

   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGVID_MTZ2to5_PN);//�������� ���4 ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2StageParam.mcp_Ustp_time_stage;

//.�� ���3 �������
//.	 ������� �� ����
//.	 1 �� = 1 �A
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGUST_MTZ2to5_V);//������� ����4 ������
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2Pickup.mcp_s1_Ias_ov_range;

   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGUST_MTZ2to5_N);//������� ����4 �����
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2Pickup.mcp_s2_Iabk_ov_range;
  
//.	�������� ���4 ������
//.	1 �� =10���
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGVID_MTZ2to5_V);//�������� ���4 ������
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2StageParam.mcp_s1_time_stage;
//.	�������� ���4 �����
//.	1 �� =10���
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGVID_MTZ2to5_N);//�������� ���4 �����
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2StageParam.mcp_s2_time_stage;
  
//���������
  //- �������� ��������� ���4 BB
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGUSK_MTZ2to5);//��������� ���4 BB
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2StageParam.mcp_time_stage_Aclt;
  //- �������� ��������� ���4 ��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGUSK_MTZ2to5_OU);//��������� ���4 ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2StageParam.mcp_T_op_aclt;
  //- �������� ��������� ���4 T�
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGUSK_MTZ2to5_TU);//��������� ���4 T�
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2StageParam.mcp_T_tele_aclt;
  
//- �������� ��������� ������� ����4 ������  
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGUSK_MTZ2to5_V);//��������� ����4 ������
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2StageParam.mcp_s1_T_aclt;
  //- �������� ��������� ���H4 ������ ��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGUSK_MTZ2to5_V_OU);//��������� ���H4 ������ ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2StageParam.mcp_s1_T_op_aclt;
  //- �������� ��������� ���H4 ������ T�
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGUSK_MTZ2to5_V_TU);//��������� ���H4 ������ T�
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2StageParam.mcp_s1_T_tele_aclt;
  
//- �������� ��������� ������� ����4 �����
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGUSK_MTZ2to5_N);//��������� ����4 �����
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2StageParam.mcp_s2_T_aclt;
  //- �������� ��������� ���H4 ����� ��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGUSK_MTZ2to5_N_OU);//��������� ���H4 ����� ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2StageParam.mcp_s2_T_op_aclt;
  //- �������� ��������� ���H4 ����� T�
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGUSK_MTZ2to5_N_TU);//��������� ���H4 ����� T�
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2StageParam.mcp_s2_T_tele_aclt;
  
//- �������� ��������� ������� ���4��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGUSK_MTZ2to5_PN);//��������� ���4��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2StageParam.mcp_Ustp_T_aclt;
  //- �������� ��������� ���4�� ��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGUSK_MTZ2to5_PN_OU);//��������� ���4��  ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2StageParam.mcp_Ustp_T_op_aclt;
  //- �������� ��������� ���4�� T�
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGUSK_MTZ2to5_PN_TU);//��������� ���4��  T�
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2StageParam.mcp_Ustp_T_tele_aclt;
  
//- �������� ���� ��������� ���4
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGVUSK_MTZ2to5);//���� ��������� ���4
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4DrOcp2StageParam.mcp_Tau_AcltImp;
  
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  4, MNGUPR_MTZ2to5);//���������� ���4
/*
//    int uprMTZ4=0;
  //����  ��������� ���4
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&4) tmp = 1;
  brCfgTbl.ownrStg4DrOcp2Mng.state_mcp = tmp;
//    lSt1 = brCfgTbl.ownrStg4DrOcp2Mng.state_mcp;
//  if(lSt1>0) uprMTZ4 |= 4; //���4  WKL
//  else  uprMTZ4 &= ~4; //���4  OTKL 
    //�������� ���4
//.	���������
//.	0 - �������
//.	1 - ���� �� ��������������
//.	2 - ���� �� ����������
  tmp = 0;
  if(tmpUst&1) tmp = 1;
  if(tmpUst&2) tmp = 2;
  brCfgTbl.ownrStg4DrOcp2Mng.select_prt_mcp = tmp;
//    lSt2 = brCfgTbl.ownrStg4DrOcp2Mng.select_prt_mcp;  
//  if(lSt2==2) uprMTZ4 |= 2; //���4 �� WKL
//  else  uprMTZ4 &= ~2; //���4 �� OTKL 
//  if(lSt2==1) uprMTZ4 |= 1; //���4 ������� WKL
//  else  uprMTZ4 &= ~1; //���4 ������� OTKL 
    
    //����  ���4 ���������� ������ ��������� 
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&8) tmp = 1;
  brCfgTbl.ownrStg4DrOcp2Mng.DirectionStraight_mcp = tmp;
//    lst3 = brCfgTbl.ownrStg4DrOcp2Mng.DirectionStraight_mcp;
//  if(lst3>0) uprMTZ4 |= 8; //���4 ������ WKL
//  else  uprMTZ4 &= ~8; //���4 ������ OTKL 

    //����  ���4 ���������� ����� ��������� 
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&16) tmp = 1;
  brCfgTbl.ownrStg4DrOcp2Mng.DirectionBack_mcp = tmp;
//    lst4 = brCfgTbl.ownrStg4DrOcp2Mng.DirectionBack_mcp;
//  if(lst4>0) uprMTZ4 |= 16; //���3 ����� WKL
//  else  uprMTZ4 &= ~16; //���3 ����� OTKL 

//��������� ���4 BB
  tmp = 0;
  if(tmpUst&32) tmp = 1;
  brCfgTbl.ownrStg4DrOcp2Mng.aclt_mcp_sw = tmp;
//    lSt1 = brCfgTbl.ownrStg4DrOcp2Mng.aclt_mcp_sw;  
//  if(lSt1>0) uprMTZ4 |= 32; //��� ���4 BB WKL
//  else  uprMTZ4 &= ~32; //��� ���4 BB OTKL 

//��������� ���4 AU
  tmp = 0;
  if(tmpUst&64) tmp = 1;
  brCfgTbl.ownrStg4DrOcp2Mng.state_Auto_aclt_mcp = tmp;
//    lSt1 = brCfgTbl.ownrStg4DrOcp2Mng.state_Auto_aclt_mcp;  
//  if(lSt1>0) uprMTZ4 |= 64; //��� ���4 AU WKL
//  else  uprMTZ4 &= ~64; //��� ���4 AU OTKL 

//��������� ���4 TU
  tmp = 0;
  if(tmpUst&128) tmp = 1;
  brCfgTbl.ownrStg4DrOcp2Mng.state_Tele_aclt_mcp = tmp;
//    lSt1 = brCfgTbl.ownrStg4DrOcp2Mng.state_Tele_aclt_mcp;  
//  if(lSt1>0) uprMTZ4 |= 128; //��� ���4 TU WKL
//  else  uprMTZ4 &= ~128; //��� ���4 TU OTKL 
  
//  SetUstToClon(MTZ_COMP1,  4, MNGUPR_MTZ2to5, uprMTZ4);//���������� ���4
*/
//-------------MTZ5-----------------------    
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGUST_MTZ2to5);//������� ���5 �������
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2Pickup.mcp_I_ov_range;
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGVID_MTZ2to5);//�������� ���5 �������
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2StageParam.mcp_time_stage;
  
//.�� �����
//.	 ������� �� ����
//.	 1 �� = 1 �A
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGUST_MTZ2to5_PN);//������� ���5 ��
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2Pickup.mcp_IstpU_ov_range;
//.�� U �����
//.	 ������� �� ����� �� ����������
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGUST_MTZ2to5_UPN);//������� ���5 ��
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2Pickup.mcp_Ustp_ov_range;

   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGVID_MTZ2to5_PN);//�������� ���5 ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2StageParam.mcp_Ustp_time_stage;

//.�� ���5 �������
//.	 ������� �� ����
//.	 1 �� = 1 �A
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGUST_MTZ2to5_V);//������� ����5 ������
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2Pickup.mcp_s1_Ias_ov_range;

   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGUST_MTZ2to5_N);//������� ����5 �����
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2Pickup.mcp_s2_Iabk_ov_range;
  
//.	�������� ���5 ������
//.	1 �� =10���
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGVID_MTZ2to5_V);//�������� ���5 ������
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2StageParam.mcp_s1_time_stage;
//.	�������� ���5 �����
//.	1 �� =10���
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGVID_MTZ2to5_N);//�������� ���5 �����
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2StageParam.mcp_s2_time_stage;
  
//���������
  //- �������� ��������� ���5 BB
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGUSK_MTZ2to5);//��������� ���5 BB
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2StageParam.mcp_time_stage_Aclt;
  //- �������� ��������� ���4 ��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGUSK_MTZ2to5_OU);//��������� ���5 ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2StageParam.mcp_T_op_aclt;
  //- �������� ��������� ���5 T�
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGUSK_MTZ2to5_TU);//��������� ���5 T�
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2StageParam.mcp_T_tele_aclt;
  
//- �������� ��������� ������� ����5 ������  
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGUSK_MTZ2to5_V);//��������� ����5 ������
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2StageParam.mcp_s1_T_aclt;
  //- �������� ��������� ���H5 ������ ��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGUSK_MTZ2to5_V_OU);//��������� ���H5 ������ ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2StageParam.mcp_s1_T_op_aclt;
  //- �������� ��������� ���H5 ������ T�
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGUSK_MTZ2to5_V_TU);//��������� ���H5 ������ T�
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2StageParam.mcp_s1_T_tele_aclt;
  
//- �������� ��������� ������� ����5 �����
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGUSK_MTZ2to5_N);//��������� ����5 �����
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2StageParam.mcp_s2_T_aclt;
  //- �������� ��������� ���H5 ����� ��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGUSK_MTZ2to5_N_OU);//��������� ���H5 ����� ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2StageParam.mcp_s2_T_op_aclt;
  //- �������� ��������� ���H5 ����� T�
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGUSK_MTZ2to5_N_TU);//��������� ���H5 ����� T�
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2StageParam.mcp_s2_T_tele_aclt;
  
//- �������� ��������� ������� ���5��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGUSK_MTZ2to5_PN);//��������� ���5��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2StageParam.mcp_Ustp_T_aclt;
  //- �������� ��������� ���5�� ��
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGUSK_MTZ2to5_PN_OU);//��������� ���5��  ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2StageParam.mcp_Ustp_T_op_aclt;
  //- �������� ��������� ���5�� T�
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGUSK_MTZ2to5_PN_TU);//��������� ���5��  T�
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2StageParam.mcp_Ustp_T_tele_aclt;
  
//- �������� ���� ��������� ���5
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGVUSK_MTZ2to5);//���� ��������� ���5
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5DrOcp2StageParam.mcp_Tau_AcltImp;
  
   tmpUst = GetUstFromImageClon(numBlok, MTZ_COMP1,  5, MNGUPR_MTZ2to5);//���������� ���5
/*
//    int uprMTZ5=0;
  //����  ��������� ���5
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&4) tmp = 1;
  brCfgTbl.ownrStg5DrOcp2Mng.state_mcp = tmp;
//    lSt1 = brCfgTbl.ownrStg5DrOcp2Mng.state_mcp;
//  if(lSt1>0) uprMTZ5 |= 4; //���5  WKL
//  else  uprMTZ5 &= ~4; //���5  OTKL 
    //�������� ���5
//.	���������
//.	0 - �������
//.	1 - ���� �� ��������������
//.	2 - ���� �� ����������
  tmp = 0;
  if(tmpUst&1) tmp = 1;
  if(tmpUst&2) tmp = 2;
  brCfgTbl.ownrStg5DrOcp2Mng.select_prt_mcp = tmp;
//    lSt2 = brCfgTbl.ownrStg5DrOcp2Mng.select_prt_mcp;  
//  if(lSt2==2) uprMTZ5 |= 2; //���5 �� WKL
//  else  uprMTZ5 &= ~2; //���5 �� OTKL 
//  if(lSt2==1) uprMTZ5 |= 1; //���5 ������� WKL
//  else  uprMTZ5 &= ~1; //���5 ������� OTKL 
    
    //����  ���5 ���������� ������ ��������� 
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&8) tmp = 1;
  brCfgTbl.ownrStg5DrOcp2Mng.DirectionStraight_mcp = tmp;
//    lst3 = brCfgTbl.ownrStg5DrOcp2Mng.DirectionStraight_mcp;
//  if(lst3>0) uprMTZ5 |= 8; //���5 ������ WKL
//  else  uprMTZ5 &= ~8; //���5 ������ OTKL 

    //����  ���5 ���������� ����� ��������� 
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&16) tmp = 1;
  brCfgTbl.ownrStg5DrOcp2Mng.DirectionBack_mcp = tmp;
//    lst4 = brCfgTbl.ownrStg5DrOcp2Mng.DirectionBack_mcp;
//  if(lst4>0) uprMTZ5 |= 16; //���5 ����� WKL
//  else  uprMTZ5 &= ~16; //���5 ����� OTKL 

//��������� ���5 BB
  tmp = 0;
  if(tmpUst&32) tmp = 1;
  brCfgTbl.ownrStg5DrOcp2Mng.aclt_mcp_sw = tmp;
//    lSt1 = brCfgTbl.ownrStg5DrOcp2Mng.aclt_mcp_sw;  
  //if(lSt1>0) uprMTZ5 |= 32; //��� ���5 BB WKL
//  else  uprMTZ5 &= ~32; //��� ���5 BB OTKL 

//��������� ���5 AU
  tmp = 0;
  if(tmpUst&64) tmp = 1;
  brCfgTbl.ownrStg5DrOcp2Mng.state_Auto_aclt_mcp = tmp;
//    lSt1 = brCfgTbl.ownrStg5DrOcp2Mng.state_Auto_aclt_mcp;  
//  if(lSt1>0) uprMTZ5 |= 64; //��� ���5 AU WKL
//  else  uprMTZ5 &= ~64; //��� ���5 AU OTKL 

//��������� ���5 TU
  tmp = 0;
  if(tmpUst&128) tmp = 1;
  brCfgTbl.ownrStg5DrOcp2Mng.state_Tele_aclt_mcp = tmp;
//    lSt1 = brCfgTbl.ownrStg5DrOcp2Mng.state_Tele_aclt_mcp;  
//  if(lSt1>0) uprMTZ5 |= 128; //��� ���5 TU WKL
//  else  uprMTZ5 &= ~128; //��� ���5 TU OTKL 
  
//  SetUstToClon(MTZ_COMP1,  5, MNGUPR_MTZ2to5, uprMTZ5);//���������� ���5
*/
}//SettingIci_MTZ()
