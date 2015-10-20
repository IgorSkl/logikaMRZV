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
#include "NZOP1Component.c"

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

void  SettingIci_NZOP()
{
/*
unsigned int ov_range_Zop_s_I2;
//. ������� �� ���� �� ���� ����
//. 1 �� = 1 �A
unsigned int ov_range_Zop_s_U2;
//. ������� �� ���������� �� ����  ����
//. 1 �� = 1 �A

unsigned int ov_range_Zop_b_I2;
//. ������� �� ���� �� ���� ���
//. 1 �� = 1 �A
unsigned int ov_range_Zop_b_U2;
*/

//��������� ICI NZOP
//-------------NZOP1-----------------------    
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1NspPickupStoreDsc.ov_range_Zop_s_I2;
    SetUstToClon(NZOP_COMP1,  1, MNGUST_ICM_NZOP1to2_V, lMtz1);//������� �� ICM ����1 ���

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1NspPickupStoreDsc.ov_range_Zop_b_I2;
    SetUstToClon(NZOP_COMP1,  1, MNGUST_ICM_NZOP1to2_N, lMtz1);//������� �� ICM ���� ���

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1NspPickupStoreDsc.ov_range_Zop_s_U2;
    SetUstToClon(NZOP_COMP1,  1, MNGUST_UCM_NZOP1to2_V, lMtz1);//������� �� UCM ����1 ���

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1NspPickupStoreDsc.ov_range_Zop_b_U2;
    SetUstToClon(NZOP_COMP1,  1, MNGUST_UCM_NZOP1to2_N, lMtz1);//������� �� UCM ���� ���

/*
unsigned short time_stage_Zop;   //- �������� ���
unsigned short time_stage_Zop_s;    //- �������� T ������ �O� 
unsigned short time_stage_Zop_b;    //- �������� T ����� �O� 
*/
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1NspStageParamStoreDsc.time_stage_Zop;
  SetUstToClon(NZOP_COMP1,  1, MNGVID_NZOP1to2, lMtz1Tmr*10);//�������� ����1 
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1NspStageParamStoreDsc.time_stage_Zop_s;
  SetUstToClon(NZOP_COMP1,  1, MNGVID_NZOP1to2_V, lMtz1Tmr*10);//�������� ����1 ���
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1NspStageParamStoreDsc.time_stage_Zop_b;
  SetUstToClon(NZOP_COMP1,  1, MNGVID_NZOP1to2_N, lMtz1Tmr*10);//�������� ����1 ���

/*
unsigned char select_prt_zop;//�������� ���
//����  ����� ����� ������ ��� ����(������) 
//�� �������������� ����(������) �� ����������
//.	���������
//.	0 - �������
//.	1 - ���� �� ��������������

unsigned char state_dir_zop;
//.	���������
//.	1 -���
//.	0 - ����
unsigned char select_dir_zop;
//.	���������
//.	1 - ������
//.	0 - ��������
*/

  int uprNZOP1=0;
  //���� ��� NZOP1
//.	���������
//.	0 - �������
//.	1 - ���� �� ��������������
    lSt1 = brCfgTbl.ownrStg1NspMng.select_prt_zop;
  if(lSt1>0) uprNZOP1 |= 1; //NZOP1  WKL
  else  uprNZOP1 &= ~1; //NZOP1  OTKL 
  //����  ��������� NZOP1
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg1NspMng.state_dir_zop;
  if(lSt1>0) uprNZOP1 |= 2; //NZOP1 
  else  uprNZOP1 &= ~2; //NZOP1  

  //���� ����������� NZOP1
//.	���������
//.	1 - ������
//.	0 - ��������
    lSt1 = brCfgTbl.ownrStg1NspMng.select_dir_zop;
  if(lSt1>0) uprNZOP1 |= 4; //NZOP1  
  else  uprNZOP1 &= ~4; 

  SetUstToClon(NZOP_COMP1,  1, MNGUPR_NZOP1to2, uprNZOP1);//���������� NZOP1

//-------------NZOP2-----------------------    
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2NspPickupStoreDsc.ov_range_Zop_s_I2;
    SetUstToClon(NZOP_COMP1,  2, MNGUST_ICM_NZOP1to2_V, lMtz1);//������� �� ICM ����1 ���

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2NspPickupStoreDsc.ov_range_Zop_b_I2;
    SetUstToClon(NZOP_COMP1,  2, MNGUST_ICM_NZOP1to2_N, lMtz1);//������� �� ICM ���� ���

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2NspPickupStoreDsc.ov_range_Zop_s_U2;
    SetUstToClon(NZOP_COMP1,  2, MNGUST_UCM_NZOP1to2_V, lMtz1);//������� �� UCM ����1 ���

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2NspPickupStoreDsc.ov_range_Zop_b_U2;
    SetUstToClon(NZOP_COMP1,  2, MNGUST_UCM_NZOP1to2_N, lMtz1);//������� �� UCM ���� ���
/*
unsigned short time_stage_Zop;   //- �������� ���
unsigned short time_stage_Zop_s;    //- �������� T ������ �O� 
unsigned short time_stage_Zop_b;    //- �������� T ����� �O� 
*/
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2NspStageParamStoreDsc.time_stage_Zop;
  SetUstToClon(NZOP_COMP1,  2, MNGVID_NZOP1to2, lMtz1Tmr*10);//�������� ����2 
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2NspStageParamStoreDsc.time_stage_Zop_s;
  SetUstToClon(NZOP_COMP1,  2, MNGVID_NZOP1to2_V, lMtz1Tmr*10);//�������� ����2 ���
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2NspStageParamStoreDsc.time_stage_Zop_b;
  SetUstToClon(NZOP_COMP1,  2, MNGVID_NZOP1to2_N, lMtz1Tmr*10);//�������� ����2 ���

/*
unsigned char select_prt_zop;//�������� ���
//����  ����� ����� ������ ��� ����(������) 
//�� �������������� ����(������) �� ����������
//.	���������
//.	0 - �������
//.	1 - ���� �� ��������������

unsigned char state_dir_zop;
//.	���������
//.	1 -���
//.	0 - ����
unsigned char select_dir_zop;
//.	���������
//.	1 - ������
//.	0 - ��������
*/

  int uprNZOP2=0;
  //���� ��� NZOP2
//.	���������
//.	0 - �������
//.	1 - ���� �� ��������������
    lSt1 = brCfgTbl.ownrStg2NspMng.select_prt_zop;
  if(lSt1>0) uprNZOP2 |= 1; //NZOP2  WKL
  else  uprNZOP2 &= ~1; //NZOP2  OTKL 
  //����  ��������� NZOP2
//.	���������
//.	1 -���
//.	0 - ����
    lSt1 = brCfgTbl.ownrStg2NspMng.state_dir_zop;
  if(lSt1>0) uprNZOP2 |= 2; //NZOP2 
  else  uprNZOP2 &= ~2; //NZOP2

  //���� ����������� NZOP2
//.	���������
//.	1 - ������
//.	0 - ��������
    lSt1 = brCfgTbl.ownrStg2NspMng.select_dir_zop;
  if(lSt1>0) uprNZOP2 |= 4; //NZOP2
  else  uprNZOP2 &= ~4; 

  SetUstToClon(NZOP_COMP1,  2, MNGUPR_NZOP1to2, uprNZOP2);//���������� NZOP

}//

