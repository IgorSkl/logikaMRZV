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
//#include "PRM1Component.c"

#include "DZ2Component.cpp"

//extern char chProtectTableComeIn;
//extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
//extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
//extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

void  GettingIci_DZ2to5()
{
//��������� ICI DZ2to5
 int numBlok=0;
//-----------DZ2------------------------------------  
//��� ��� ��2��
    int tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUST_DZ2to5_MTZ);//������� MTZ
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2Pickup.Dstp2_Iovp_ov_range;
//-----------OF
//Re1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUST_DZ2to5_OX1);//������� X1OF_DZ2
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P1_R;
//Im1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUST_DZ2to5_OY1);//������� Y1OF_DZ2
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P1_X;

//Re2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUST_DZ2to5_OX2);//������� X2OF_DZ2
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P2_R;
//Im2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUST_DZ2to5_OY2);//������� Y2OF_DZ2
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P2_X;

//Re3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUST_DZ2to5_OX3);//������� X3OF_DZ2
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P3_R;
//Im3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUST_DZ2to5_OY3);//������� Y3OF_DZ2
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P3_X;

//Re4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUST_DZ2to5_OX4);//������� X4OF_DZ2
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P4_R;
//Im4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUST_DZ2to5_OY4);//������� Y4OF_DZ2
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P4_X;

//-----------MF
//Re1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUST_DZ2to5_MX1);//������� X1MF_DZ2
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P1_R;
//Im1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUST_DZ2to5_MY1);//������� Y1MF_DZ2
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P1_X;

//Re2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUST_DZ2to5_MX2);//������� X2MF_DZ2
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P2_R;
//Im2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUST_DZ2to5_MY2);//������� Y2MF_DZ2
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P2_X;

//Re3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUST_DZ2to5_MX3);//������� X3MF_DZ2
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P3_R;
//Im3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUST_DZ2to5_MY3);//������� Y3MF_DZ2
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P3_X;

//Re4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUST_DZ2to5_MX4);//������� X4MF_DZ2
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P4_R;
//Im4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUST_DZ2to5_MY4);//������� Y4MF_DZ2
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P4_X;
    
//DZ2MF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGVID_DZ2to5MF);//������� �������� DZ2MF
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2StageParam.Dstp2_MF_T;

  
//MTZ DZ2MF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGVID_MDZ2to5MF);//������� �������� MTZ DZ2MF
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2StageParam.Dstp2_Ocp_T;


//DZ2OF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGVID_DZ2to5OF);//������� �������� MTZ DZ2OF
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2StageParam.Dstp2_OF_T;

  
//���������  
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGVUSK_DZ2to5MF);//������� ���� ����� ��2 ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2StageParam.Dstp2_HWS_Tau_Aclt;

  
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGVUSK_MDZ2to5MF);//������� ���� ����� MTZ ��2 ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;


   //DZ2MF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUSK_DZ2to5MF_VV);//������� ����� ��2 �� BB
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2StageParam.Dstp2_MF_T_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUSK_DZ2to5MF_OU);//������� ����� ��2 �� OU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2StageParam.Dstp2_MF_T_op_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUSK_DZ2to5MF_TU);//������� ����� ��2 �� TU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2StageParam.Dstp2_MF_T_tele_aclt;


   //MTZ DZ2MF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUSK_MDZ2to5MF_VV);//������� ����� MTZ ��2 �� BB
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2StageParam.Dstp2_Ocp_T_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUSK_MDZ2to5MF_OU);//������� ����� MTZ ��2 �� OU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2StageParam.Dstp2_Ocp_T_op_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUSK_MDZ2to5MF_TU);//������� ����� MTZ ��2 �� TU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;


   //DZ2OF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUSK_DZ2to5OF_VV);//������� ����� ��2 O� BB
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2StageParam.Dstp2_OF_T_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUSK_DZ2to5OF_OU);//������� ����� ��2 O� OU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2StageParam.Dstp2_OF_T_op_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUSK_DZ2to5OF_TU);//������� ����� ��2 O� TU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2Dstp2StageParam.Dstp2_OF_T_tele_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  2, MNGUPR_DZ2to5);//���������� DZ2
/*
//  int uprDZ2=0;
  //����  ��������� DZ2    
//.	���������
//.	1 -���
//.	0 - ����
  int tmp = 0;
  if(tmpUst&1) tmp = 1;
  brCfgTbl.ownrStg1Dstp2Mng.state_dstp2 = tmp;
//    lSt1 = brCfgTbl.ownrStg2Dstp2Mng.state_dstp2;
//  if(lSt1>0) uprDZ2 |= 1; //DZ2 WKL
//  else  uprDZ2 &= ~1; //DZ2 OTKL 
  //����   MTZ DZ2
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&2) tmp = 1;
  brCfgTbl.ownrStg2Dstp2Mng.state_ocp_dstp2 = tmp;
//    lSt1 = brCfgTbl.ownrStg2Dstp2Mng.state_ocp_dstp2;
//  if(lSt1>0) uprDZ2 |= 2; //MTZ DZ2 WKL
//  else  uprDZ2 &= ~2; //MTZ DZ2 OTKL 
  //����   ����� �� DZ2
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&4) tmp = 1;
  brCfgTbl.ownrStg2Dstp2Mng.state_aclt_dstp2_hws = tmp;
//    lSt1 = brCfgTbl.ownrStg2Dstp2Mng.state_aclt_dstp2_hws;
//  if(lSt1>0) uprDZ2 |= 4; //����� BB DZ2 WKL
//  else  uprDZ2 &= ~4; //����� BB DZ2 OTKL 
  //����   ����� AU DZ2
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&8) tmp = 1;
  brCfgTbl.ownrStg2Dstp2Mng.state_Auto_aclt_dstp2 = tmp;
//    lSt1 = brCfgTbl.ownrStg2Dstp2Mng.state_Auto_aclt_dstp2;
//  if(lSt1>0) uprDZ2 |= 8; //����� AU DZ2 WKL
//  else  uprDZ2 &= ~8; //����� AU DZ2 OTKL 
  //����   ����� TU DZ2
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&16) tmp = 1;
  brCfgTbl.ownrStg2Dstp2Mng.state_Tele_aclt_dstp2 = tmp;
//    lSt1 = brCfgTbl.ownrStg2Dstp2Mng.state_Tele_aclt_dstp2;
//  if(lSt1>0) uprDZ2 |= 16; //����� TU DZ2 WKL
//  else  uprDZ2 &= ~16; //����� TU DZ2 OTKL 
  
//  SetUstToClon(DZ_COMP1,  2, MNGUPR_DZ2to5, uprDZ2);//���������� DZ2
*/
//-----------DZ3------------------------------------  
//��� ��� ��3��
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUST_DZ2to5_MTZ);//������� MTZ
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2Pickup.Dstp2_Iovp_ov_range;
//-----------OF
//Re1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUST_DZ2to5_OX1);//������� X1OF_DZ3
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P1_R;
//Im1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUST_DZ2to5_OY1);//������� Y1OF_DZ3
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P1_X;

//Re2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUST_DZ2to5_OX2);//������� X2OF_DZ3
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P2_R;
//Im2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUST_DZ2to5_OY2);//������� Y2OF_DZ3
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P2_X;

//Re3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUST_DZ2to5_OX3);//������� X3OF_DZ3
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P3_R;
//Im3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUST_DZ2to5_OY3);//������� Y3OF_DZ3
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P3_X;

//Re4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUST_DZ2to5_OX4);//������� X4OF_DZ3
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P4_R;
//Im4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUST_DZ2to5_OY4);//������� Y4OF_DZ3
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P4_X;

    //-----------MF
//Re1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUST_DZ2to5_MX1);//������� X1MF_DZ3
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P1_R;
//Im1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUST_DZ2to5_MY1);//������� Y1MF_DZ3
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P1_X;

//Re2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUST_DZ2to5_MX2);//������� X2MF_DZ3
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P2_R;
//Im2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUST_DZ2to5_MY2);//������� Y2MF_DZ3
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P2_X;

//Re3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUST_DZ2to5_MX3);//������� X3MF_DZ3
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P3_R;
//Im3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUST_DZ2to5_MY3);//������� Y3MF_DZ3
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P3_X;

//Re4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUST_DZ2to5_MX4);//������� X4MF_DZ3
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P4_R;
//Im4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUST_DZ2to5_MY4);//������� Y4MF_DZ3
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P4_X;

//DZ3MF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGVID_DZ2to5MF);//������� �������� DZ3MF
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2StageParam.Dstp2_MF_T;

  
//MTZ DZ3MF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGVID_MDZ2to5MF);//������� �������� MTZ DZ3MF
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2StageParam.Dstp2_Ocp_T;


//DZ3OF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGVID_DZ2to5OF);//������� �������� MTZ DZ3OF
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2StageParam.Dstp2_OF_T;

  
//���������  
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGVUSK_DZ2to5MF);//������� ���� ����� ��3 ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2StageParam.Dstp2_HWS_Tau_Aclt;

  
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGVUSK_MDZ2to5MF);//������� ���� ����� MTZ ��3 ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;


   //DZ3MF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUSK_DZ2to5MF_VV);//������� ����� ��3 �� BB
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2StageParam.Dstp2_MF_T_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUSK_DZ2to5MF_OU);//������� ����� ��3 �� OU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2StageParam.Dstp2_MF_T_op_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUSK_DZ2to5MF_TU);//������� ����� ��3 �� TU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2StageParam.Dstp2_MF_T_tele_aclt;


  //MTZ DZ3MF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUSK_MDZ2to5MF_VV);//������� ����� MTZ ��3 �� BB
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2StageParam.Dstp2_Ocp_T_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUSK_MDZ2to5MF_OU);//������� ����� MTZ ��3 �� OU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2StageParam.Dstp2_Ocp_T_op_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUSK_MDZ2to5MF_TU);//������� ����� MTZ ��3 �� TU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;


   //DZ3OF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUSK_DZ2to5OF_VV);//������� ����� ��3 O� BB
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2StageParam.Dstp2_OF_T_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUSK_DZ2to5OF_OU);//������� ����� ��3 O� OU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2StageParam.Dstp2_OF_T_op_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUSK_DZ2to5OF_TU);//������� ����� ��3 O� TU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage3Dstp2StageParam.Dstp2_OF_T_tele_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  3, MNGUPR_DZ2to5);//���������� DZ3
/*
//  int uprDZ3=0;
  //����  ��������� DZ3
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&1) tmp = 1;
  brCfgTbl.ownrStg3Dstp2Mng.state_dstp2 = tmp;
//    lSt1 = brCfgTbl.ownrStg3Dstp2Mng.state_dstp2;
//  if(lSt1>0) uprDZ3 |= 1; //DZ3 WKL
//  else  uprDZ3 &= ~1; //DZ3 OTKL 
  //����   MTZ DZ3
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&2) tmp = 1;
  brCfgTbl.ownrStg3Dstp2Mng.state_ocp_dstp2 = tmp;
//    lSt1 = brCfgTbl.ownrStg3Dstp2Mng.state_ocp_dstp2;
//  if(lSt1>0) uprDZ3 |= 2; //MTZ DZ3 WKL
//  else  uprDZ3 &= ~2; //MTZ DZ3 OTKL 
  //����   ����� �� DZ3
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&4) tmp = 1;
  brCfgTbl.ownrStg3Dstp2Mng.state_aclt_dstp2_hws = tmp;
//    lSt1 = brCfgTbl.ownrStg3Dstp2Mng.state_aclt_dstp2_hws;
//  if(lSt1>0) uprDZ3 |= 4; //����� BB DZ3 WKL
//  else  uprDZ3 &= ~4; //����� BB DZ3 OTKL 
  //����   ����� AU DZ3
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&8) tmp = 1;
  brCfgTbl.ownrStg3Dstp2Mng.state_Auto_aclt_dstp2 = tmp;
//    lSt1 = brCfgTbl.ownrStg3Dstp2Mng.state_Auto_aclt_dstp2;
//  if(lSt1>0) uprDZ3 |= 8; //����� AU DZ3 WKL
//  else  uprDZ3 &= ~8; //����� AU DZ3 OTKL 
  //����   ����� TU DZ3
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&16) tmp = 1;
  brCfgTbl.ownrStg3Dstp2Mng.state_Tele_aclt_dstp2 = tmp;
//    lSt1 = brCfgTbl.ownrStg3Dstp2Mng.state_Tele_aclt_dstp2;
//  if(lSt1>0) uprDZ3 |= 16; //����� TU DZ3 WKL
//  else  uprDZ3 &= ~16; //����� TU DZ3 OTKL 
  
//  SetUstToClon(DZ_COMP1,  3, MNGUPR_DZ2to5, uprDZ3);//���������� DZ3
*/
//-----------DZ4------------------------------------  
//��� ��� ��4��
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUST_DZ2to5_MTZ);//������� MTZ
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2Pickup.Dstp2_Iovp_ov_range;
//-----------OF
//Re1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUST_DZ2to5_OX1);//������� X1OF_DZ4
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P1_R;
//Im1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUST_DZ2to5_OY1);//������� Y1OF_DZ4
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P1_X;

//Re2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUST_DZ2to5_OX2);//������� X2OF_DZ4
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P2_R;
//Im2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUST_DZ2to5_OY2);//������� Y2OF_DZ4
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P2_X;

//Re3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUST_DZ2to5_OX3);//������� X3OF_DZ4
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P3_R;
//Im3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUST_DZ2to5_OY3);//������� Y3OF_DZ4
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P3_X;

//Re4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUST_DZ2to5_OX4);//������� X4OF_DZ4
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P4_R;
//Im4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUST_DZ2to5_OY4);//������� Y4OF_DZ4
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P4_X;

//-----------MF
//Re1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUST_DZ2to5_MX1);//������� X1MF_DZ4
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P1_R;
//Im1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUST_DZ2to5_MY1);//������� Y1MF_DZ4
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P1_X;

//Re2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUST_DZ2to5_MX2);//������� X2MF_DZ4
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P2_R;
//Im2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUST_DZ2to5_MY2);//������� Y2MF_DZ4
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P2_X;

//Re3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUST_DZ2to5_MX3);//������� X3MF_DZ4
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P3_R;
//Im3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUST_DZ2to5_MY3);//������� Y3MF_DZ4
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P3_X;

//Re4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUST_DZ2to5_MX4);//������� X4MF_DZ4
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P4_R;
//Im4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUST_DZ2to5_MY4);//������� Y4MF_DZ4
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P4_X;
    
//DZ4MF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGVID_DZ2to5MF);//������� �������� DZ4MF
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2StageParam.Dstp2_MF_T;

  
//MTZ DZ4MF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGVID_MDZ2to5MF);//������� �������� MTZ DZ4MF
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2StageParam.Dstp2_Ocp_T;


//DZ4OF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGVID_DZ2to5OF);//������� �������� MTZ DZ4OF
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2StageParam.Dstp2_OF_T;

  
//���������  
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGVUSK_DZ2to5MF);//������� ���� ����� ��4 ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2StageParam.Dstp2_HWS_Tau_Aclt;

  
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGVUSK_MDZ2to5MF);//������� ���� ����� MTZ ��4 ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;


   //DZ4MF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUSK_DZ2to5MF_VV);//������� ����� ��4 �� BB
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2StageParam.Dstp2_MF_T_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUSK_DZ2to5MF_OU);//������� ����� ��4 �� OU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2StageParam.Dstp2_MF_T_op_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUSK_DZ2to5MF_TU);//������� ����� ��4 �� TU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2StageParam.Dstp2_MF_T_tele_aclt;


   //MTZ DZ4MF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUSK_MDZ2to5MF_VV);//������� ����� MTZ ��4 �� BB
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2StageParam.Dstp2_Ocp_T_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUSK_MDZ2to5MF_OU);//������� ����� MTZ ��4 �� OU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2StageParam.Dstp2_Ocp_T_op_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUSK_MDZ2to5MF_TU);//������� ����� MTZ ��4 �� TU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;


   //DZ4OF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUSK_DZ2to5OF_VV);//������� ����� ��4 O� BB
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2StageParam.Dstp2_OF_T_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUSK_DZ2to5OF_OU);//������� ����� ��4 O� OU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2StageParam.Dstp2_OF_T_op_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUSK_DZ2to5OF_TU);//������� ����� ��4 O� TU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage4Dstp2StageParam.Dstp2_OF_T_tele_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  4, MNGUPR_DZ2to5);//���������� DZ4
/*
//  int uprDZ4=0;
  //����  ��������� DZ4
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&1) tmp = 1;
  brCfgTbl.ownrStg4Dstp2Mng.state_dstp2 = tmp;
//    lSt1 = brCfgTbl.ownrStg4Dstp2Mng.state_dstp2;
//  if(lSt1>0) uprDZ4 |= 1; //DZ4 WKL
//  else  uprDZ4 &= ~1; //DZ4 OTKL 
  //����   MTZ DZ4
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&2) tmp = 1;
  brCfgTbl.ownrStg4Dstp2Mng.state_ocp_dstp2 = tmp;
//    lSt1 = brCfgTbl.ownrStg4Dstp2Mng.state_ocp_dstp2;
//  if(lSt1>0) uprDZ4 |= 2; //MTZ DZ4 WKL
//  else  uprDZ4 &= ~2; //MTZ DZ4 OTKL 
  //����   ����� �� DZ4
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&4) tmp = 1;
  brCfgTbl.ownrStg4Dstp2Mng.state_aclt_dstp2_hws = tmp;
//    lSt1 = brCfgTbl.ownrStg4Dstp2Mng.state_aclt_dstp2_hws;
//  if(lSt1>0) uprDZ4 |= 4; //����� BB DZ4 WKL
//  else  uprDZ4 &= ~4; //����� BB DZ4 OTKL 
  //����   ����� AU DZ4
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&8) tmp = 1;
  brCfgTbl.ownrStg4Dstp2Mng.state_Auto_aclt_dstp2 = tmp;
//    lSt1 = brCfgTbl.ownrStg4Dstp2Mng.state_Auto_aclt_dstp2;
//  if(lSt1>0) uprDZ4 |= 8; //����� AU DZ4 WKL
//  else  uprDZ4 &= ~8; //����� AU DZ4 OTKL 
  //����   ����� TU DZ4
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&16) tmp = 1;
  brCfgTbl.ownrStg4Dstp2Mng.state_Tele_aclt_dstp2 = tmp;
//    lSt1 = brCfgTbl.ownrStg4Dstp2Mng.state_Tele_aclt_dstp2;
//  if(lSt1>0) uprDZ4 |= 16; //����� TU DZ4 WKL
//  else  uprDZ4 &= ~16; //����� TU DZ4 OTKL 
  
//  SetUstToClon(DZ_COMP1,  4, MNGUPR_DZ2to5, uprDZ4);//���������� DZ4
*/  
//-----------DZ5------------------------------------  
//��� ��� ��5��
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUST_DZ2to5_MTZ);//������� MTZ
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2Pickup.Dstp2_Iovp_ov_range;
//-----------OF
//Re1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUST_DZ2to5_OX1);//������� X1OF_DZ5
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P1_R;
//Im1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUST_DZ2to5_OY1);//������� Y1OF_DZ5
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P1_X;

//Re2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUST_DZ2to5_OX2);//������� X2OF_DZ5
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P2_R;
//Im2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUST_DZ2to5_OY2);//������� Y2OF_DZ5
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P2_X;

//Re3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUST_DZ2to5_OX3);//������� X3OF_DZ5
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P3_R;
//Im3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUST_DZ2to5_OY3);//������� Y3OF_DZ5
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P3_X;

//Re4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUST_DZ2to5_OX4);//������� X4OF_DZ5
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P4_R;
//Im4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUST_DZ2to5_OY4);//������� Y4OF_DZ5
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P4_X;

    //-----------MF
//Re1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUST_DZ2to5_MX1);//������� X1MF_DZ5
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P1_R;
//Im1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUST_DZ2to5_MY1);//������� Y1MF_DZ5
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P1_X;

//Re2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUST_DZ2to5_MX2);//������� X2MF_DZ5
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P2_R;
//Im2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUST_DZ2to5_MY2);//������� Y2MF_DZ5
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P2_X;

//Re3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUST_DZ2to5_MX3);//������� X3MF_DZ5
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P3_R;
//Im3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUST_DZ2to5_MY3);//������� Y3MF_DZ5
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P3_X;

//Re4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUST_DZ2to5_MX4);//������� X4MF_DZ5
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P4_R;
//Im4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUST_DZ2to5_MY4);//������� Y4MF_DZ5
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P4_X;

//DZ5MF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGVID_DZ2to5MF);//������� �������� DZ5MF
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2StageParam.Dstp2_MF_T;

  
//MTZ DZ5MF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGVID_MDZ2to5MF);//������� �������� MTZ DZ5MF
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2StageParam.Dstp2_Ocp_T;


//DZ5OF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGVID_DZ2to5OF);//������� �������� MTZ DZ5OF
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2StageParam.Dstp2_OF_T;

  
//���������  
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGVUSK_DZ2to5MF);//������� ���� ����� ��5 ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2StageParam.Dstp2_HWS_Tau_Aclt;

  
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGVUSK_MDZ2to5MF);//������� ���� ����� MTZ ��5 ��
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;


   //DZ5MF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUSK_DZ2to5MF_VV);//������� ����� ��5 �� BB
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2StageParam.Dstp2_MF_T_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUSK_DZ2to5MF_OU);//������� ����� ��5 �� OU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2StageParam.Dstp2_MF_T_op_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUSK_DZ2to5MF_TU);//������� ����� ��5 �� TU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2StageParam.Dstp2_MF_T_tele_aclt;


   //MTZ DZ5MF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUSK_MDZ2to5MF_VV);//������� ����� MTZ ��5 �� BB
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2StageParam.Dstp2_Ocp_T_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUSK_MDZ2to5MF_OU);//������� ����� MTZ ��5 �� OU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2StageParam.Dstp2_Ocp_T_op_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUSK_MDZ2to5MF_TU);//������� ����� MTZ ��5 �� TU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;


   //DZ5OF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUSK_DZ2to5OF_VV);//������� ����� ��5 O� BB
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2StageParam.Dstp2_OF_T_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUSK_DZ2to5OF_OU);//������� ����� ��5 O� OU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2StageParam.Dstp2_OF_T_op_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUSK_DZ2to5OF_TU);//������� ����� ��5 O� TU
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage5Dstp2StageParam.Dstp2_OF_T_tele_aclt;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  5, MNGUPR_DZ2to5);//���������� DZ5
/*
//  int uprDZ5=0;
  //����  ��������� DZ5
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&1) tmp = 1;
  brCfgTbl.ownrStg5Dstp2Mng.state_dstp2 = tmp;
//    lSt1 = brCfgTbl.ownrStg5Dstp2Mng.state_dstp2;
//  if(lSt1>0) uprDZ5 |= 1; //DZ5 WKL
//  else  uprDZ5 &= ~1; //DZ5 OTKL 
  //����   MTZ DZ5
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&2) tmp = 1;
  brCfgTbl.ownrStg5Dstp2Mng.state_ocp_dstp2 = tmp;
//    lSt1 = brCfgTbl.ownrStg5Dstp2Mng.state_ocp_dstp2;
//  if(lSt1>0) uprDZ5 |= 2; //MTZ DZ5 WKL
//  else  uprDZ5 &= ~2; //MTZ DZ5 OTKL 
  //����   ����� �� DZ5
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&4) tmp = 1;
  brCfgTbl.ownrStg5Dstp2Mng.state_aclt_dstp2_hws = tmp;
//    lSt1 = brCfgTbl.ownrStg5Dstp2Mng.state_aclt_dstp2_hws;
//  if(lSt1>0) uprDZ5 |= 4; //����� BB DZ5 WKL
//  else  uprDZ5 &= ~4; //����� BB DZ5 OTKL 
  //����   ����� AU DZ5
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&8) tmp = 1;
  brCfgTbl.ownrStg5Dstp2Mng.state_Auto_aclt_dstp2 = tmp;
//    lSt1 = brCfgTbl.ownrStg5Dstp2Mng.state_Auto_aclt_dstp2;
//  if(lSt1>0) uprDZ5 |= 8; //����� AU DZ5 WKL
//  else  uprDZ5 &= ~8; //����� AU DZ5 OTKL 
  //����   ����� TU DZ5
//.	���������
//.	1 -���
//.	0 - ����
  tmp = 0;
  if(tmpUst&16) tmp = 1;
  brCfgTbl.ownrStg5Dstp2Mng.state_Tele_aclt_dstp2 = tmp;
//    lSt1 = brCfgTbl.ownrStg5Dstp2Mng.state_Tele_aclt_dstp2;
//  if(lSt1>0) uprDZ5 |= 16; //����� TU DZ5 WKL
//  else  uprDZ5 &= ~16; //����� TU DZ5 OTKL 
  
//  SetUstToClon(DZ_COMP1,  5, MNGUPR_DZ2to5, uprDZ5);//���������� DZ5
*/  
}//SettingIci_DZ2to5()

