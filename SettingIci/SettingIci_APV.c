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
#include "virtualMenu\rangmanagerfnc.h"

#include "toSpeedOptim.h"
#include "toSpeedDIS.h"

#include "header.h"
#include "ici_r_ef.h"

#define _HIDE_COMPONENT
#include "APVComponent.c"
#include "MTZ1Component.c"
#include "MTZ2Component.c"
#include "TZNP1Component.c"
#include "DZ1Component.c"
#include "DZ2Component.c"

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

/*
unsigned int   Rclr_U_ov_range1;
//.�� ��� 1 �������� �������� ������� �� �� ���������� U� ��� 40 140 � ��� 0.01
//.	 ������� �� �� ����������
//.	 1 �� = 1 �B
unsigned int   Rclr_U_ov_range2;
//.�� ��� 2 �������� ���������
//.	 ������� �� �� ���������� 1  - 20 � 
//.	 1 �� = 1 �B
unsigned int   Rclr_U_ov_range3;
//.�� ��� 3 ������� �� �� ���������� U� ��� 40 140 � ��� 0.01
//.	 ������� �� �� ����������
//.	 1 �� = 1 �B
unsigned int   Rclr_U_ov_range4;
//.�� ��� 4 1  - 20 � 
//.	 
//.	 1 �� = 1 �B

//syncro1
unsigned long Rclr_DeltaU;
//������� ���������� ��� 0.01
//1  - 20 � 
//syncro2
unsigned long Rclr_DeltaPhi;
//���� ���������������
//5 �� (+-)50 ���� ��� 1 ����

//Syncro3
unsigned long Rclr_DeltaPhi_Dt;
//�������� ����������
//5 - 30 ����\� ��� 0.01
*/

void  SettingIci_APV()
{
//PO1 APV
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrRclrPickup.Rclr_U_ov_range1;
  SetUstToClon(APV_COMP1,  1, MNGUST_PO1_APV, lMtz1);//�������
//PO2 APV
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrRclrPickup.Rclr_U_ov_range2;
  SetUstToClon(APV_COMP1,  1, MNGUST_PO2_APV, lMtz1);//�������
//PO3 APV
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrRclrPickup.Rclr_U_ov_range3;
  SetUstToClon(APV_COMP1,  1, MNGUST_PO3_APV, lMtz1);//�������
//PO4 APV
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrRclrPickup.Rclr_U_ov_range4;
  SetUstToClon(APV_COMP1,  1, MNGUST_PO4_APV, lMtz1);//�������

//voltage_different APV
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrRclrPickup.Rclr_DeltaU;
  SetUstToClon(APV_COMP1,  1, MNGUST_POVD_APV, lMtz1);//�������
//angle_unbalance APV
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrRclrPickup.Rclr_DeltaPhi;
  SetUstToClon(APV_COMP1,  1, MNGUST_POAU_APV, lMtz1);//�������
//speed_angle APV
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrRclrPickup.Rclr_DeltaPhi_Dt;
  SetUstToClon(APV_COMP1,  1, MNGUST_POSA_APV, lMtz1);//�������

//����� 1 ���� ��� tim2
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr1_T;
  SetUstToClon(APV_COMP1,  1, MNGVID1_APV, lMtz1Tmr*10);//������� �������� 

//����� 2 ���� ��� tim3
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr2_T;
  SetUstToClon(APV_COMP1,  1, MNGVID2_APV, lMtz1Tmr*10);//������� �������� 

//����� ������ ��� tim8
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr2_T_blk;
  SetUstToClon(APV_COMP1,  1, MNGVID3_APV, lMtz1Tmr*10);//������� �������� 

//����� ������ ���1 tim7
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr1_T_blk;
  SetUstToClon(APV_COMP1,  1, MNGVID4_APV, lMtz1Tmr*10);//������� �������� 

//����� ������ ��� �� �� tim1
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr_T_blk_HSW;
  SetUstToClon(APV_COMP1,  1, MNGVID5_APV, lMtz1Tmr*10);//������� �������� 

//����� ���� ������� ��� tim6
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr_T_forbid;
  SetUstToClon(APV_COMP1,  1, MNGVID6_APV, lMtz1Tmr*10);//������� �������� 

//����� �� ���� ���1 tim9
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr1_T_wait_U;
  SetUstToClon(APV_COMP1,  1, MNGVID7_APV, lMtz1Tmr*10);//������� �������� 

//����� �� ���  ���1 tim10
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr1_T_wait_sycro;
  SetUstToClon(APV_COMP1,  1, MNGVID8_APV, lMtz1Tmr*10);//������� �������� 

//����� �� ���� ���2 tim11
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr2_T_wait_U;
  SetUstToClon(APV_COMP1,  1, MNGVID9_APV, lMtz1Tmr*10);//������� �������� 

//����� �� ���  ���2 tim12
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr2_T_wait_syncro;
  SetUstToClon(APV_COMP1,  1, MNGVID10_APV, lMtz1Tmr*10);//������� �������� 

  int uprAPV=0;
  //����  ��������� APV
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrRclrMng.state_Rclr;
  if(lSt1>0) uprAPV |= 32; //APV WKL
  else  uprAPV &= ~32; //APV OTKL 

  //����  ��������� APV2
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrRclrMng.state_Rclr2;
  if(lSt1>0) uprAPV |= 64; //APV WKL
  else  uprAPV &= ~64; //APV OTKL 

//��� ��������
    lSt1 = brCfgTbl.ownrRclrMng.select_Mode_Rclr;//�������� ���
  if(lSt1==0) {uprAPV &= ~7;} //uprAPV &= ~2; uprAPV &= ~4;} //APV WKL
//��� ����� ���� ����
  if(lSt1==1) {uprAPV |= 1; uprAPV &= ~6;}// uprAPV &= ~4;} //APV WKL
//���� ����� ��� ����
  if(lSt1==2) {uprAPV |= 2; uprAPV &= ~5;}// uprAPV &= ~4;} //APV WKL
//���� ����� ���� ���� ��� �����
  if(lSt1==3) {uprAPV |= 3; uprAPV &= ~4;} //APV WKL
//���� ����� ���� ���� ���� �����
  if(lSt1==4) {uprAPV |= 4; uprAPV &= ~3;}// uprAPV &= ~2;} //APV WKL

//Faza A
    lSt1 = brCfgTbl.ownrRclrMng.selectPhase;//�������� ����
  if(lSt1==0) {uprAPV &= ~(8+16);} //APV WKL
//Faza B
    lSt1 = brCfgTbl.ownrRclrMng.selectPhase;//�������� ����
  if(lSt1==1) {uprAPV |= 8; uprAPV &= ~(16);} //APV WKL
//Faza C
    lSt1 = brCfgTbl.ownrRclrMng.selectPhase;//�������� ����
  if(lSt1==2) {uprAPV |= 16; uprAPV &= ~(8);} //APV WKL
  
  SetUstToClon(APV_COMP1,  1, MNGUPR_APV, uprAPV);//���������� APV

 extern UNS_32 pAPVcmdMaska[];//����������� ���������

//���� APV �� �����
  for(int i=0; i<DQUADRO; i++) pAPVcmdMaska[i]=0;//��������
//----------------------------MTZ------------------------------
    lSt1 = puskAPVotZ(MCP1_STP_RCLR_ONB);//���� �� ���1
  if(lSt1) SetCmdToUVV(MTZ_COMP1,  1, IOCMD6_MTZ1, PUSKAPV_SM);//������ MTZ1 �� APV
    lSt1 = puskAPVotZ(MCP2_STP_RCLR_ONB);//���� �� ���2
  if(lSt1) SetCmdToUVV(MTZ_COMP1,  2, IOCMD8_MTZ2to5, PUSKAPV_SM);//������ MTZ2 �� APV
    lSt1 = puskAPVotZ(MCP3_STP_RCLR_ONB);//���� �� ���3
  if(lSt1) SetCmdToUVV(MTZ_COMP1,  3, IOCMD8_MTZ2to5, PUSKAPV_SM);//������ MTZ3 �� APV
    lSt1 = puskAPVotZ(MCP4_STP_RCLR_ONB);//���� �� ���4
  if(lSt1) SetCmdToUVV(MTZ_COMP1,  4, IOCMD8_MTZ2to5, PUSKAPV_SM);//������ MTZ4 �� APV
    lSt1 = puskAPVotZ(MCP5_STP_RCLR_ONB);//���� �� ���5
  if(lSt1) SetCmdToUVV(MTZ_COMP1,  5, IOCMD8_MTZ2to5, PUSKAPV_SM);//������ MTZ5 �� APV

//----------------------------TZNP------------------------------
    lSt1 = puskAPVotZ(TZNP1_STP_RCLR_ONB);//���� ����1
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  1, IOCMD5_TZNP1to5, PUSKAPV_SM);//������ �� APV
    lSt1 = puskAPVotZ(TZNP1_3U0_STP_RCLR_ONB);//���� ���1(3U0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  1, IOCMD9_TZNP1to5, PUSKAPV_SM);//������ �� APV
    lSt1 = puskAPVotZ(TZNP1_3I0_STP_RCLR_ONB);//���� ���1(3I0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  1, IOCMD7_TZNP1to5, PUSKAPV_SM);//������ �� APV
    lSt1 = puskAPVotZ(TZNP2_STP_RCLR_ONB);//���� ����2
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  2, IOCMD5_TZNP1to5, PUSKAPV_SM);//������ �� APV
    lSt1 = puskAPVotZ(TZNP2_3U0_STP_RCLR_ONB);//���� ���2(3U0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  2, IOCMD9_TZNP1to5, PUSKAPV_SM);//������ �� APV
    lSt1 = puskAPVotZ(TZNP2_3I0_STP_RCLR_ONB);//���� ���2(3I0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  2, IOCMD7_TZNP1to5, PUSKAPV_SM);//������ �� APV
    lSt1 = puskAPVotZ(TZNP3_STP_RCLR_ONB);//���� ����3
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  3, IOCMD5_TZNP1to5, PUSKAPV_SM);//������ �� APV
    lSt1 = puskAPVotZ(TZNP3_3U0_STP_RCLR_ONB);//���� ���3(3U0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  3, IOCMD9_TZNP1to5, PUSKAPV_SM);//������ �� APV
    lSt1 = puskAPVotZ(TZNP3_3I0_STP_RCLR_ONB);//���� ���3(3I0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  3, IOCMD7_TZNP1to5, PUSKAPV_SM);//������ �� APV
    lSt1 = puskAPVotZ(TZNP4_STP_RCLR_ONB);//���� ����4
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  4, IOCMD5_TZNP1to5, PUSKAPV_SM);//������ �� APV
    lSt1 = puskAPVotZ(TZNP4_3U0_STP_RCLR_ONB);//���� ���4(3U0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  4, IOCMD9_TZNP1to5, PUSKAPV_SM);//������ �� APV
    lSt1 = puskAPVotZ(TZNP4_3I0_STP_RCLR_ONB);//���� ���4(3I0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  4, IOCMD7_TZNP1to5, PUSKAPV_SM);//������ �� APV
    lSt1 = puskAPVotZ(TZNP5_STP_RCLR_ONB);//���� ����5
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  5, IOCMD5_TZNP1to5, PUSKAPV_SM);//������ �� APV
    lSt1 = puskAPVotZ(TZNP5_3U0_STP_RCLR_ONB);//���� ���5(3U0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  5, IOCMD9_TZNP1to5, PUSKAPV_SM);//������ �� APV
    lSt1 = puskAPVotZ(TZNP5_3I0_STP_RCLR_ONB);//���� ���5(3I0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  5, IOCMD7_TZNP1to5, PUSKAPV_SM);//������ �� APV

//----------------------------DZ------------------------------
    lSt1 = puskAPVotZ(DSTP1_STP_RCLR_ONB);//���� ���1
  if(lSt1) {
             SetCmdToUVV(DZ_COMP1,  1, IOCMD3_DZ1, PUSKAPV_SM);//������ �� APV
             SetCmdToUVV(DZ_COMP1,  1, IOCMD7_DZ1, PUSKAPV_SM);//������ �� APV
           }//if  
    lSt1 = puskAPVotZ(DSTP2_STP_RCLR_ONB);//���� ���2
  if(lSt1) {
             SetCmdToUVV(DZ_COMP1,  2, IOCMD5_DZ2to5MF, PUSKAPV_SM);//������ �� APV
             SetCmdToUVV(DZ_COMP1,  2, IOCMD5_DZ2to5OF, PUSKAPV_SM);//������ �� APV
           }//if  
    lSt1 = puskAPVotZ(DSTP3_STP_RCLR_ONB);//���� ���3
  if(lSt1) {
             SetCmdToUVV(DZ_COMP1,  3, IOCMD5_DZ2to5MF, PUSKAPV_SM);//������ �� APV
             SetCmdToUVV(DZ_COMP1,  3, IOCMD5_DZ2to5OF, PUSKAPV_SM);//������ �� APV
           }//if  
    lSt1 = puskAPVotZ(DSTP4_STP_RCLR_ONB);//���� ���4
  if(lSt1) {
             SetCmdToUVV(DZ_COMP1,  4, IOCMD5_DZ2to5MF, PUSKAPV_SM);//������ �� APV
             SetCmdToUVV(DZ_COMP1,  4, IOCMD5_DZ2to5OF, PUSKAPV_SM);//������ �� APV
           }//if  
    lSt1 = puskAPVotZ(DSTP5_STP_RCLR_ONB);//���� ���5
  if(lSt1) {
             SetCmdToUVV(DZ_COMP1,  5, IOCMD5_DZ2to5MF, PUSKAPV_SM);//������ �� APV
             SetCmdToUVV(DZ_COMP1,  5, IOCMD5_DZ2to5OF, PUSKAPV_SM);//������ �� APV
           }//if  

    lSt1 = puskAPVotZ(MCP1_DSTP1_STP_RCLR_ONB);//���� ���1 ���1
  if(lSt1) SetCmdToUVV(DZ_COMP1,  1, IOCMD5_DZ1, PUSKAPV_SM);//������ �� APV
    lSt1 = puskAPVotZ(MCP2_DSTP2_STP_RCLR_ONB);//���� ���2 ���2
  if(lSt1) SetCmdToUVV(DZ_COMP1,  2, IOCMD5_MDZ2to5MF, PUSKAPV_SM);//������ �� APV
    lSt1 = puskAPVotZ(MCP3_DSTP3_STP_RCLR_ONB);//���� ���3 ���3
  if(lSt1) SetCmdToUVV(DZ_COMP1,  3, IOCMD5_MDZ2to5MF, PUSKAPV_SM);//������ �� APV
    lSt1 = puskAPVotZ(MCP4_DSTP4_STP_RCLR_ONB);//���� ���4 ���4
  if(lSt1) SetCmdToUVV(DZ_COMP1,  4, IOCMD5_MDZ2to5MF, PUSKAPV_SM);//������ �� APV
    lSt1 = puskAPVotZ(MCP5_DSTP5_STP_RCLR_ONB);//���� ���5 ���5
  if(lSt1) SetCmdToUVV(DZ_COMP1,  5, IOCMD5_MDZ2to5MF, PUSKAPV_SM);//������ �� APV

}//SettingIci_APV()

int puskAPVotZ(int num)
{
//���� �� �����
  int rez=0;
    if(brCfgTbl.ownrRclrMng.ar_Rclr_Stp_Cmd_state[num/8]&(1<<(num%8))) rez=1;
  return rez;
}//puskAPVotZ(int num)

/*
DSTP1_STP_RCLR_ONB                       ,//���� ���1
DSTP2_STP_RCLR_ONB                       ,//���� ���2
DSTP3_STP_RCLR_ONB                       ,//���� ���3
DSTP4_STP_RCLR_ONB                       ,//���� ���4
DSTP5_STP_RCLR_ONB                       ,//���� ���5

MCP1_DSTP1_STP_RCLR_ONB                  ,//���� ���1 ���1
MCP2_DSTP2_STP_RCLR_ONB                  ,//���� ���2 ���2
MCP3_DSTP3_STP_RCLR_ONB                  ,//���� ���3 ���3
MCP4_DSTP4_STP_RCLR_ONB                  ,//���� ���4 ���4
MCP5_DSTP5_STP_RCLR_ONB                  ,//���� ���5 ���5

*/