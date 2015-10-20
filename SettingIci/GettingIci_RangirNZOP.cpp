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
#include "virtualMenu\rangmanagerfnc.h"
#include "virtualmenu\systemmenufnc.h"
#include "SettingIci\SettingIci.h"

//#include "toSpeedOptim.h"
//#include "toSpeedDIS.h"

//#include "header.h"
//#include "ici_r_ef.h"

#define _HIDE_COMPONENT
#include "NZOP1Component.cpp"

void GettingIci_RangirNZOPFromDV(int nDV)
{
  int numDV = nDV - DV1_SM;//����������
      //���������� ���1
 if(GetCmdUVVFromClon(NZOP_COMP1,  1, IOCMD1_NZOP1to2, nDV));//��������� �������
//      setActivCmdDV(BLOCK_ZOP1_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      //���������� ���2
 if(GetCmdUVVFromClon(NZOP_COMP1,  2, IOCMD1_NZOP1to2, nDV));//��������� �������
//      setActivCmdDV(BLOCK_ZOP2_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
}//GettingIci_RangirNZOPFromDV(int nDV)

void GettingIci_RangirNZOPFromRele(int nRele)
{
//������ NZOP �� ����
int numRele = nRele - RELE1_SM;//����������
//���������� ���1
 if(GetCmdUVVFromClon(NZOP_COMP1,  1, IOCMD1_NZOP1to2, nRele));//��������� �������
//    setActivCmdRele(BLOCK_ZOP1_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
 //������ ����1���� 
 if(GetCmdUVVFromClon(NZOP_COMP1,  1, IOCMD6_NZOP1to2, nRele));//��������� �������
//    setActivCmdRele(STPDEV_SECTOR_ZOP1_STAIGHT_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
 //������ ����1�����
 if(GetCmdUVVFromClon(NZOP_COMP1,  1, IOCMD7_NZOP1to2, nRele));//��������� �������
//    setActivCmdRele(STPDEV_SECTOR_ZOP1_BACK_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
 //�� ���1
 if(GetCmdUVVFromClon(NZOP_COMP1,  1, IOCMD2_NZOP1to2, nRele));//��������� �������
//    setActivCmdRele(STPDEV_ZOP1_BORING_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
 //�� ����1����
 if(GetCmdUVVFromClon(NZOP_COMP1,  1, IOCMD3_NZOP1to2, nRele));//��������� �������
//    setActivCmdRele(STPDEV_ZOP1_STAIGHT_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
 //�� ����1������
 if(GetCmdUVVFromClon(NZOP_COMP1,  1, IOCMD4_NZOP1to2, nRele));//��������� �������
//    setActivCmdRele(STPDEV_ZOP1_BACK_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
 //���� ����1
 if(GetCmdUVVFromClon(NZOP_COMP1,  1, IOCMD5_NZOP1to2, nRele));//��������� �������
//    setActivCmdRele(ZOP1_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele

//���������� ���2
 if(GetCmdUVVFromClon(NZOP_COMP1,  2, IOCMD1_NZOP1to2, nRele));//��������� �������
//    setActivCmdRele(BLOCK_ZOP2_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
 //������ ����2���� 
 if(GetCmdUVVFromClon(NZOP_COMP1,  2, IOCMD6_NZOP1to2, nRele));//��������� �������
//    setActivCmdRele(STPDEV_SECTOR_ZOP2_STAIGHT_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
 //������ ����2�����
 if(GetCmdUVVFromClon(NZOP_COMP1,  2, IOCMD7_NZOP1to2, nRele));//��������� �������
//    setActivCmdRele(STPDEV_SECTOR_ZOP2_BACK_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
 //�� ���2
 if(GetCmdUVVFromClon(NZOP_COMP1,  2, IOCMD2_NZOP1to2, nRele));//��������� �������
//    setActivCmdRele(STPDEV_ZOP2_BORING_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
 //�� ����2����
 if(GetCmdUVVFromClon(NZOP_COMP1,  2, IOCMD3_NZOP1to2, nRele));//��������� �������
//    setActivCmdRele(STPDEV_ZOP2_STAIGHT_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
 //�� ����2������
 if(GetCmdUVVFromClon(NZOP_COMP1,  2, IOCMD4_NZOP1to2, nRele));//��������� �������
//    setActivCmdRele(STPDEV_ZOP2_BACK_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
 //���� ����2
 if(GetCmdUVVFromClon(NZOP_COMP1,  2, IOCMD5_NZOP1to2, nRele));//��������� �������
//    setActivCmdRele(ZOP2_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
}// SettingIci_RangirNZOPToRele(int nRele)

void GettingIci_RangirNZOPFromLed(int nLed)
{
//������ NZOP �� ���
int numLed = nLed - CDI1_SM;//����������

//���������� ���1
 if(GetCmdUVVFromClon(NZOP_COMP1,  1, IOCMD1_NZOP1to2, nLed));//��������� �������
//    setActivCmdLed(BLOCK_ZOP1_DI_OEPRF_ONB, numLed))//�������� ���������� ������� �� Led
 //������ ����1���� 
 if(GetCmdUVVFromClon(NZOP_COMP1,  1, IOCMD6_NZOP1to2, nLed));//��������� �������
//    setActivCmdLed(STPDEV_SECTOR_ZOP1_STAIGHT_OEPRF_ONB, numLed))//�������� ���������� ������� �� Led
 //������ ����1�����
 if(GetCmdUVVFromClon(NZOP_COMP1,  1, IOCMD7_NZOP1to2, nLed));//��������� �������
//    setActivCmdLed(STPDEV_SECTOR_ZOP1_BACK_OEPRF_ONB, numLed))//�������� ���������� ������� �� Led
 //�� ���1
 if(GetCmdUVVFromClon(NZOP_COMP1,  1, IOCMD2_NZOP1to2, nLed));//��������� �������
//    setActivCmdLed(STPDEV_ZOP1_BORING_OEPRF_ONB, numLed))//�������� ���������� ������� �� Led
 //�� ����1����
 if(GetCmdUVVFromClon(NZOP_COMP1,  1, IOCMD3_NZOP1to2, nLed));//��������� �������
//    setActivCmdLed(STPDEV_ZOP1_STAIGHT_OEPRF_ONB, numLed))//�������� ���������� ������� �� Led
 //�� ����1������
 if(GetCmdUVVFromClon(NZOP_COMP1,  1, IOCMD4_NZOP1to2, nLed));//��������� �������
//    setActivCmdLed(STPDEV_ZOP1_BACK_OEPRF_ONB, numLed))//�������� ���������� ������� �� Led
 //���� ����1
 if(GetCmdUVVFromClon(NZOP_COMP1,  1, IOCMD5_NZOP1to2, nLed));//��������� �������
//    setActivCmdLed(ZOP1_OEPRF_ONB, numLed))//�������� ���������� ������� �� Led

//���������� ���2
 if(GetCmdUVVFromClon(NZOP_COMP1,  2, IOCMD1_NZOP1to2, nLed));//��������� �������
//    setActivCmdLed(BLOCK_ZOP2_DI_OEPRF_ONB, numLed))//�������� ���������� ������� �� Led
 //������ ����2���� 
 if(GetCmdUVVFromClon(NZOP_COMP1,  2, IOCMD6_NZOP1to2, nLed));//��������� �������
//    setActivCmdLed(STPDEV_SECTOR_ZOP2_STAIGHT_OEPRF_ONB, numLed))//�������� ���������� ������� �� Led
 //������ ����2�����
 if(GetCmdUVVFromClon(NZOP_COMP1,  2, IOCMD7_NZOP1to2, nLed));//��������� �������
//    setActivCmdLed(STPDEV_SECTOR_ZOP2_BACK_OEPRF_ONB, numLed))//�������� ���������� ������� �� Led
 //�� ���2
 if(GetCmdUVVFromClon(NZOP_COMP1,  2, IOCMD2_NZOP1to2, nLed));//��������� �������
//    setActivCmdLed(STPDEV_ZOP2_BORING_OEPRF_ONB, numLed))//�������� ���������� ������� �� Led
 //�� ����2����
 if(GetCmdUVVFromClon(NZOP_COMP1,  2, IOCMD3_NZOP1to2, nLed));//��������� �������
//    setActivCmdLed(STPDEV_ZOP2_STAIGHT_OEPRF_ONB, numLed))//�������� ���������� ������� �� Led
 //�� ����2������
 if(GetCmdUVVFromClon(NZOP_COMP1,  2, IOCMD4_NZOP1to2, nLed));//��������� �������
//    setActivCmdLed(STPDEV_ZOP2_BACK_OEPRF_ONB, numLed))//�������� ���������� ������� �� Led
 //���� ����2
 if(GetCmdUVVFromClon(NZOP_COMP1,  2, IOCMD5_NZOP1to2, nLed));//��������� �������
//    setActivCmdLed(ZOP2_OEPRF_ONB, numLed))//�������� ���������� ������� �� Led

}//GettingIci_RangirNZOPFromLed(int nLed)
