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
#include "virtualMenu\rangmanagerfnc.h"
#include "virtualmenu\systemmenufnc.h"
#include "SettingIci\SettingIci.h"

#include "toSpeedOptim.h"
#include "toSpeedDIS.h"

#include "header.h"
#include "ici_r_ef.h"

#define _HIDE_COMPONENT
#include "PRM1Component.c"
/*
//CMD_POL_VV
#define IOCMD1_PRM1 0
//������ ����� ���������� ��
//CMD_FAILU_COMMON
#define IOCMD2_PRM1 1
//���� ��
//CMD_OTKL_VV
#define IOCMD3_PRM1 2
//CMD_BO
//������ ��
#define IOCMD4_PRM1 3
//CMD_BV
//������ �B
#define IOCMD5_PRM1 4
//TEST
#define IOCMD6_PRM1 5
//��� ��
//CMD_VKL_VV
#define IOCMD7_PRM1 6

//�������� ���
#define IOCMD8_PRM1 7
//�������� ����
#define IOCMD9_PRM1 8

//���� ����
#define IOCMD10_PRM1 9
//����� ���������
#define IOCMD11_PRM1 10

//���������� ��������� ��
#define IOCMD12_PRM1  11
//������������� ��������� ��
#define IOCMD13_PRM1  12

*/

void SettingIci_RangirPRM1ToDV(int nDV)
{
  int numDV = nDV - DV1_SM;//����������
      // ��������� �� (�����������)
  if(isActivCmdDV(SWITCH_STATE_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD1_PRM1, nDV);//������ CMD_POL_VV �� ��

// ����. �� 
  if(isActivCmdDV(HVSW_OFF_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD3_PRM1, nDV);//������ CMD_OTKL_VV �� ��

//��� ��
  if(isActivCmdDV(HVSW_ON_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD7_PRM1, nDV);//������  �� ��

//�������� ���
  if(isActivCmdDV(CTRL_VKL_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD8_PRM1, nDV);//������  �� ��
//�������� ����
  if(isActivCmdDV(CTRL_OTKL_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD9_PRM1, nDV);//������  �� ��

// ����� ����	
  if(isActivCmdDV(RESET_SIGOUT_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD10_PRM1, nDV);//������  �� ��
// ����� ��������
  if(isActivCmdDV(RESET_LED_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD11_PRM1, nDV);//������  �� ��

// ���������� ��������� ��
  if(isActivCmdDV(BLOCK_SWITCHOVER_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD12_PRM1, nDV);//������  �� ��

// ������������� ��������� ��
  if(isActivCmdDV(PERMIT_BLK_SW_MCP_DI_IEPRF_ONB, numDV))
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD13_PRM1, nDV);//������  �� ��

}//SettingIci_RangirPRM2DV(int nDV)
//CTRL_VKL_DI_IEPRF_ONB                ,// �������� ���
//CTRL_OTKL_DI_IEPRF_ONB               ,// �������� ����

//RESET_SIGOUT_DI_IEPRF_ONB            ,// ����� ����	
//RESET_LED_DI_IEPRF_ONB               ,// ����� ��������
//BLOCK_SWITCHOVER_DI_IEPRF_ONB        ,// ���������� ��������� ��
//SWITCH_STATE_DI_IEPRF_ONB            ,// ��������� �� (�����������)
//PERMIT_BLK_SW_MCP_DI_IEPRF_ONB       ,// ������������� ��������� ��

void SettingIci_RangirPRM1ToRele(int nRele)
{
//������ PRM1 �� ����
int numRele = nRele - RELE1_SM;//����������

// ��������� �� (�����������)
  if(isActivCmdDV(SWITCH_STATE_DI_OEPRF_ONB, numRele))
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD1_PRM1, nRele);//������  �� ��
// ������������� ����� ���� �����
 if(isActivCmdRele(FLT_U_DSTP_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD2_PRM1, nRele);//������ 

//��� ��
  if(isActivCmdRele(HVSW_ON_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� 
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD7_PRM1, nRele);//������  �� 
// ����. �� 
  if(isActivCmdRele(HVSW_OFF_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� 
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD3_PRM1, nRele);//������ CMD_OTKL_VV �� 

//������ ��
  if(isActivCmdRele(SW_OFF_CMDF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD4_PRM1, nRele);//������  �� Rele
//������ �B
  if(isActivCmdRele(SW_ON_CMDF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD5_PRM1, nRele);//������  �� Rele

//�������� ���
  if(isActivCmdRele(CTRL_VKL_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� 
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD8_PRM1, nRele);//������  �� 
//�������� ����
  if(isActivCmdRele(CTRL_OTKL_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� 
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD9_PRM1, nRele);//������  �� 

// ����� ����	
  if(isActivCmdRele(RESET_SIGOUT_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� 
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD10_PRM1, nRele);//������  �� 
// ����� ��������
  if(isActivCmdDV(RESET_LED_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� 
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD11_PRM1, nRele);//������  �� 

// ���������� ��������� ��
  if(isActivCmdRele(BLOCK_SWITCHOVER_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� 
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD12_PRM1, nRele);//������  �� 
// ������������� ��������� ��
  if(isActivCmdRele(PERMIT_BLK_SW_MCP_DI_OEPRF_ONB, numRele))
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD13_PRM1, nRele);//������  �� 

//������ ��
  if(isActivCmdRele(DRIVER_SW_DI_OEPRF_ONB, numRele))
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD14_PRM1, nRele);//������  �� 

}// SettingIci_RangirUMM2Rele(int nRele)

void SettingIci_RangirPRM1ToLed(int nLed)
{
//������ DZ1 �� ���
int numLed = nLed - CDI1_SM;//����������
// ���������� UMin1
// if(isActivCmdLed(BLOCK_UMIN1_DI_OEPRF_ONB, numLed))//�������� ���������� ������� �� ����
  //    SetCmdToUVV(UMM_COMP1,  1, IOCMD3_UMM, nLed);//������ 

}// SettingIci_RangirPRM1ToRele(int nLed)
