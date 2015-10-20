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
#include "UMMComponent.c"

void SettingIci_RangirUMM2DV(int nDV)
{
//������ UMM �� ��
int numDV = nDV - DV1_SM;//����������
// ���������� UMin1
 if(isActivCmdDV(BLOCK_UMIN1_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(UMM_COMP1,  1, IOCMD3_UMM, nDV);//������ 
// ���������� UMin2
 if(isActivCmdDV(BLOCK_UMIN2_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(UMM_COMP1,  1, IOCMD4_UMM, nDV);//������ 

// ���������� UMax1
// if(isActivCmdDV(, numDV))//�������� ���������� ������� �� ��
//      SetCmdToUVV(UMM_COMP1,  1, IOCMD1_UMM, nDV);//������ 
// ���������� UMax2
// if(isActivCmdDV(, numDV))//�������� ���������� ������� �� ��
//      SetCmdToUVV(UMM_COMP1,  1, IOCMD2_UMM, nDV);//������ 
}// SettingIci_RangirUMM2DV(int nDV)

void SettingIci_RangirUMM2Rele(int nRele)
{
//������ UMM �� ����
int numRele = nRele - RELE1_SM;//����������
// ���������� UMin1
 if(isActivCmdRele(BLOCK_UMIN1_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD3_UMM, nRele);//������ 
// ���������� UMin2
 if(isActivCmdRele(BLOCK_UMIN2_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD4_UMM, nRele);//������ 
// �� UMin1
 if(isActivCmdRele(STPDEV_UMIN1_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD9_UMM, nRele);//������ 
// UMin1
 if(isActivCmdRele(UMIN1_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD10_UMM, nRele);//������ 

// �� UMin2
 if(isActivCmdRele(STPDEV_UMIN2_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD11_UMM, nRele);//������ 
// UMin2
 if(isActivCmdRele(UMIN2_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD12_UMM, nRele);//������ 

// ���������� UMax1
// if(isActivCmdRele(, numRele))//�������� ���������� ������� �� ����
//      SetCmdToUVV(UMM_COMP1,  1, IOCMD1_UMM, nRele);//������ 
// ���������� UMax2
// if(isActivCmdRele(, numRele))//�������� ���������� ������� �� ����
  //    SetCmdToUVV(UMM_COMP1,  1, IOCMD2_UMM, nRele);//������ 
  
// �� UMax1
 if(isActivCmdRele(STPDEV_UMAX1_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD5_UMM, nRele);//������ 
// UMax1
 if(isActivCmdRele(UMAX1_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD6_UMM, nRele);//������ 
// �� UMax2
 if(isActivCmdRele(STPDEV_UMAX2_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD7_UMM, nRele);//������ 
// UMax2
 if(isActivCmdRele(UMAX2_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD8_UMM, nRele);//������ 


}// SettingIci_RangirUMM2Rele(int nRele)

void SettingIci_RangirUMM2Led(int nLed)
{
//������ UMM �� ���
int numLed = nLed - CDI1_SM;//����������
// ���������� UMin1
 if(isActivCmdLed(BLOCK_UMIN1_DI_OEPRF_ONB, numLed))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD3_UMM, nLed);//������ 
// ���������� UMin2
 if(isActivCmdLed(BLOCK_UMIN2_DI_OEPRF_ONB, numLed))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD4_UMM, nLed);//������ 
// �� UMin1
 if(isActivCmdLed(STPDEV_UMIN1_OEPRF_ONB, numLed))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD9_UMM, nLed);//������ 
// UMin1
 if(isActivCmdLed(UMIN1_OEPRF_ONB, numLed))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD10_UMM, nLed);//������ 

// �� UMin2
 if(isActivCmdLed(STPDEV_UMIN2_OEPRF_ONB, numLed))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD11_UMM, nLed);//������ 
// UMin2
 if(isActivCmdLed(STPDEV_UMIN2_OEPRF_ONB, numLed))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD12_UMM, nLed);//������ 

// ���������� UMax1
// if(isActivCmdLed(, numLed))//�������� ���������� ������� �� ����
//      SetCmdToUVV(UMM_COMP1,  1, IOCMD1_UMM, nLed);//������ 
// ���������� UMax2
// if(isActivCmdLed(, numLed))//�������� ���������� ������� �� ����
  //    SetCmdToUVV(UMM_COMP1,  1, IOCMD2_UMM, nLed);//������ 
  
// �� UMax1
 if(isActivCmdLed(STPDEV_UMAX1_OEPRF_ONB, numLed))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD5_UMM, nLed);//������ 
// UMax1
 if(isActivCmdLed(UMAX1_OEPRF_ONB, numLed))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD6_UMM, nLed);//������ 
// �� UMax2
 if(isActivCmdLed(STPDEV_UMAX2_OEPRF_ONB, numLed))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD7_UMM, nLed);//������ 
// UMax2
 if(isActivCmdLed(UMAX2_OEPRF_ONB, numLed))//�������� ���������� ������� �� ����
      SetCmdToUVV(UMM_COMP1,  1, IOCMD8_UMM, nLed);//������ 


}// SettingIci_RangirUMM2Led(int nLed)
