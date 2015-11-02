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
#include "DZ1Component.c"
#include "DZ2Component.c"

void SettingIci_RangirDZToDV(int nDV)
{
//������ DZ1 �� ��
int numDV = nDV - DV1_SM;//����������
// ���������� DZ1
 if(isActivCmdDV(BLOCK_DSTP1_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(DZ_COMP1,  1, IOCMD1_DZ1, nDV);//������ 

// ���������� DZ2
 if(isActivCmdDV(BLOCK_DSTP2_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(DZ_COMP1,  2, IOCMD1_DZ2to5, nDV);//������ 
//���������� ����� ���� �2
 if(isActivCmdDV(BLOCK_ACCLT_DSTP2_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(DZ_COMP1,  2, IOCMD2_DZ2to5, nDV);//������ 
//����������� ��������� ���� �2
 if(isActivCmdDV(ACCLT_DSTP2_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(DZ_COMP1,  2, IOCMD3_DZ2to5, nDV);//������ 

// ���������� DZ3
 if(isActivCmdDV(BLOCK_DSTP3_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(DZ_COMP1,  3, IOCMD1_DZ2to5, nDV);//������ 
//���������� ����� ���� �3
 if(isActivCmdDV(BLOCK_ACCLT_DSTP3_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(DZ_COMP1,  3, IOCMD2_DZ2to5, nDV);//������ 
//����������� ��������� ���� �3
 if(isActivCmdDV(ACCLT_DSTP3_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(DZ_COMP1,  3, IOCMD3_DZ2to5, nDV);//������ 

// ���������� DZ4
 if(isActivCmdDV(BLOCK_DSTP4_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(DZ_COMP1,  4, IOCMD1_DZ2to5, nDV);//������ 
//���������� ����� ���� �4
 if(isActivCmdDV(BLOCK_ACCLT_DSTP4_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(DZ_COMP1,  4, IOCMD2_DZ2to5, nDV);//������ 
//����������� ��������� ���� �4
 if(isActivCmdDV(ACCLT_DSTP4_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(DZ_COMP1,  4, IOCMD3_DZ2to5, nDV);//������ 

// ���������� DZ5
 if(isActivCmdDV(BLOCK_DSTP5_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(DZ_COMP1,  5, IOCMD1_DZ2to5, nDV);//������ 
//���������� ����� ���� �5
 if(isActivCmdDV(BLOCK_ACCLT_DSTP5_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(DZ_COMP1,  5, IOCMD2_DZ2to5, nDV);//������ 
//����������� ��������� ���� �5
 if(isActivCmdDV(ACCLT_DSTP5_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(DZ_COMP1,  5, IOCMD3_DZ2to5, nDV);//������ 

}// SettingIci_RangirDZ1ToDV(int nDV)

void SettingIci_RangirDZToRele(int nRele)
{
//������ DZ1 �� ����
int numRele = nRele - RELE1_SM;//����������
// ���������� DZ1
 if(isActivCmdRele(BLOCK_DSTP1_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  1, IOCMD1_DZ1, nRele);//������ 
// �� ��1 ��
 if(isActivCmdRele(STPDEV_DSTP1_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  1, IOCMD2_DZ1, nRele);//������ 
// C��� ��1 ��
 if(isActivCmdRele(DSTP1_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  1, IOCMD3_DZ1, nRele);//������ 
// �� ��� ��1
 if(isActivCmdRele(STPDEV_MCP_DSTP1_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  1, IOCMD4_DZ1, nRele);//������ 
// ���� ��� ��1
 if(isActivCmdRele(MCP_DSTP1_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  1, IOCMD5_DZ1, nRele);//������ 
// �� ��1 ��
 if(isActivCmdRele(STPDEV_DSTP1_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  1, IOCMD6_DZ1, nRele);//������ 
// ���� ��1 ��
 if(isActivCmdRele(DSTP1_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  1, IOCMD7_DZ1, nRele);//������ 

// ���������� DZ2
 if(isActivCmdRele(BLOCK_DSTP2_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  2, IOCMD1_DZ2to5, nRele);//������ 
//���������� ����� ���� �2
 if(isActivCmdRele(BLOCK_ACCLT_DSTP2_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  2, IOCMD2_DZ2to5, nRele);//������ 
//����������� ��������� ���� �2
 if(isActivCmdRele(ACCLT_DSTP2_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  2, IOCMD3_DZ2to5, nRele);//������ 
// �� ��2 ��
 if(isActivCmdRele(STPDEV_DSTP2_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  2, IOCMD4_DZ2to5MF, nRele);//������ 
// C��� ��2 ��
 if(isActivCmdRele(DSTP2_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  2, IOCMD5_DZ2to5MF, nRele);//������ 
// �� ��� ��2
 if(isActivCmdRele(STPDEV_MCP_DSTP2_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  2, IOCMD4_MDZ2to5MF, nRele);//������ 
// ���� ��� ��2
 if(isActivCmdRele(MCP_DSTP2_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  2, IOCMD5_MDZ2to5MF, nRele);//������ 
// �� ��2 ��
 if(isActivCmdRele(STPDEV_DSTP2_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  2, IOCMD4_DZ2to5OF, nRele);//������ 
// ���� ��2 ��
 if(isActivCmdRele(DSTP2_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  2, IOCMD5_DZ2to5OF, nRele);//������ 


// ���������� DZ3
 if(isActivCmdRele(BLOCK_DSTP3_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  3, IOCMD1_DZ2to5, nRele);//������ 
//���������� ����� ���� �3
 if(isActivCmdRele(BLOCK_ACCLT_DSTP3_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  3, IOCMD2_DZ2to5, nRele);//������ 
//����������� ��������� ���� �3
 if(isActivCmdRele(ACCLT_DSTP3_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  3, IOCMD3_DZ2to5, nRele);//������ 
// �� ��3 ��
 if(isActivCmdRele(STPDEV_DSTP3_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  3, IOCMD4_DZ2to5MF, nRele);//������ 
// C��� ��3 ��
 if(isActivCmdRele(DSTP3_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  3, IOCMD5_DZ2to5MF, nRele);//������ 
// �� ��� ��3
 if(isActivCmdRele(STPDEV_MCP_DSTP3_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  3, IOCMD4_MDZ2to5MF, nRele);//������ 
// ���� ��� ��3
 if(isActivCmdRele(MCP_DSTP3_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  3, IOCMD5_MDZ2to5MF, nRele);//������ 
// �� ��3 ��
 if(isActivCmdRele(STPDEV_DSTP3_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  3, IOCMD4_DZ2to5OF, nRele);//������ 
// ���� ��3 ��
 if(isActivCmdRele(DSTP3_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  3, IOCMD5_DZ2to5OF, nRele);//������ 

// ���������� DZ4
 if(isActivCmdRele(BLOCK_DSTP4_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  4, IOCMD1_DZ2to5, nRele);//������ 
//���������� ����� ���� �4
 if(isActivCmdRele(BLOCK_ACCLT_DSTP4_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  4, IOCMD2_DZ2to5, nRele);//������ 
//����������� ��������� ���� �4
 if(isActivCmdRele(ACCLT_DSTP4_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  4, IOCMD3_DZ2to5, nRele);//������ 
// �� ��4 ��
 if(isActivCmdRele(STPDEV_DSTP4_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  4, IOCMD4_DZ2to5MF, nRele);//������ 
// C��� ��4 ��
 if(isActivCmdRele(DSTP4_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  4, IOCMD5_DZ2to5MF, nRele);//������ 
// �� ��� ��4
 if(isActivCmdRele(STPDEV_MCP_DSTP4_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  4, IOCMD4_MDZ2to5MF, nRele);//������ 
// ���� ��� ��4
 if(isActivCmdRele(MCP_DSTP4_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  4, IOCMD5_MDZ2to5MF, nRele);//������ 
// �� ��4 ��
 if(isActivCmdRele(STPDEV_DSTP4_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  4, IOCMD4_DZ2to5OF, nRele);//������ 
// ���� ��4 ��
 if(isActivCmdRele(DSTP4_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  4, IOCMD5_DZ2to5OF, nRele);//������ 

// ���������� DZ5
 if(isActivCmdRele(BLOCK_DSTP5_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  5, IOCMD1_DZ2to5, nRele);//������ 
//���������� ����� ���� �5
 if(isActivCmdRele(BLOCK_ACCLT_DSTP5_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  5, IOCMD2_DZ2to5, nRele);//������ 
//����������� ��������� ���� �5
 if(isActivCmdRele(ACCLT_DSTP5_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  5, IOCMD3_DZ2to5, nRele);//������ 
// �� ��5 ��
 if(isActivCmdRele(STPDEV_DSTP5_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  5, IOCMD4_DZ2to5MF, nRele);//������ 
// C��� ��5 ��
 if(isActivCmdRele(DSTP5_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  5, IOCMD5_DZ2to5MF, nRele);//������ 
// �� ��� ��5
 if(isActivCmdRele(STPDEV_MCP_DSTP5_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  5, IOCMD4_MDZ2to5MF, nRele);//������ 
// ���� ��� ��5
 if(isActivCmdRele(MCP_DSTP5_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  5, IOCMD5_MDZ2to5MF, nRele);//������ 
// �� ��5 ��
 if(isActivCmdRele(STPDEV_DSTP5_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  5, IOCMD4_DZ2to5OF, nRele);//������ 
// ���� ��5 ��
 if(isActivCmdRele(DSTP5_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(DZ_COMP1,  5, IOCMD5_DZ2to5OF, nRele);//������ 

}// SettingIci_RangirUMM2Rele(int nRele)

void SettingIci_RangirDZToLed(int nLed)
{
//������ DZ1 �� ���
int numLed = nLed - CDI1_SM;//����������
// ���������� UMin1
// if(isActivCmdLed(BLOCK_UMIN1_DI_OEPRF_ONB, numLed))//�������� ���������� ������� �� ����
  //    SetCmdToUVV(UMM_COMP1,  1, IOCMD3_UMM, nLed);//������ 

}// SettingIci_RangirUMM2Led(int nLed)
