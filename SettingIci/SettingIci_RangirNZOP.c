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
#include "NZOP1Component.c"

void SettingIci_RangirNZOPToDV(int nDV)
{
  int numDV = nDV - DV1_SM;//����������
      //���������� ���1
  if(isActivCmdDV(BLOCK_ZOP1_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(NZOP_COMP1,  1, IOCMD1_NZOP1to2, nDV);//������ �� ��
      //���������� ���2
  if(isActivCmdDV(BLOCK_ZOP2_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(NZOP_COMP1,  2, IOCMD1_NZOP1to2, nDV);//������ �� ��
}//SettingIci_RangirPRM2DV(int nDV)

void SettingIci_RangirNZOPToRele(int nRele)
{
//������ PRM1 �� ����
int numRele = nRele - RELE1_SM;//����������
//���������� ���1
 if(isActivCmdRele(BLOCK_ZOP1_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(NZOP_COMP1,  1, IOCMD1_NZOP1to2, nRele);//������ 
 //������ ����1���� 
 if(isActivCmdRele(STPDEV_SECTOR_ZOP1_STAIGHT_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(NZOP_COMP1,  1, IOCMD6_NZOP1to2, nRele);//������ 
 //������ ����1�����
 if(isActivCmdRele(STPDEV_SECTOR_ZOP1_BACK_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(NZOP_COMP1,  1, IOCMD7_NZOP1to2, nRele);//������ 
 //�� ���1
 if(isActivCmdRele(STPDEV_ZOP1_BORING_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(NZOP_COMP1,  1, IOCMD2_NZOP1to2, nRele);//������ 
 //�� ����1����
 if(isActivCmdRele(STPDEV_ZOP1_STAIGHT_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(NZOP_COMP1,  1, IOCMD3_NZOP1to2, nRele);//������ 
 //�� ����1������
 if(isActivCmdRele(STPDEV_ZOP1_BACK_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(NZOP_COMP1,  1, IOCMD4_NZOP1to2, nRele);//������ 
 //���� ����1
 if(isActivCmdRele(ZOP1_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(NZOP_COMP1,  1, IOCMD5_NZOP1to2, nRele);//������ 

//���������� ���2
 if(isActivCmdRele(BLOCK_ZOP2_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(NZOP_COMP1,  2, IOCMD1_NZOP1to2, nRele);//������ 
 //������ ����2���� 
 if(isActivCmdRele(STPDEV_SECTOR_ZOP2_STAIGHT_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(NZOP_COMP1,  2, IOCMD6_NZOP1to2, nRele);//������ 
 //������ ����2�����
 if(isActivCmdRele(STPDEV_SECTOR_ZOP2_BACK_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(NZOP_COMP1,  2, IOCMD7_NZOP1to2, nRele);//������ 
 //�� ���2
 if(isActivCmdRele(STPDEV_ZOP2_BORING_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(NZOP_COMP1,  2, IOCMD2_NZOP1to2, nRele);//������ 
 //�� ����2����
 if(isActivCmdRele(STPDEV_ZOP2_STAIGHT_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(NZOP_COMP1,  2, IOCMD3_NZOP1to2, nRele);//������ 
 //�� ����2������
 if(isActivCmdRele(STPDEV_ZOP2_BACK_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(NZOP_COMP1,  2, IOCMD4_NZOP1to2, nRele);//������ 
 //���� ����2
 if(isActivCmdRele(ZOP2_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(NZOP_COMP1,  2, IOCMD5_NZOP1to2, nRele);//������ 
}// SettingIci_RangirNZOPToRele(int nRele)

void SettingIci_RangirNZOPToLed(int nLed)
{
//������ DZ1 �� ���
int numLed = nLed - CDI1_SM;//����������
// ���������� UMin1
// if(isActivCmdLed(BLOCK_UMIN1_DI_OEPRF_ONB, numLed))//�������� ���������� ������� �� ����
  //    SetCmdToUVV(UMM_COMP1,  1, IOCMD3_UMM, nLed);//������ 

}// SettingIci_RangirPRM1ToRele(int nLed)
