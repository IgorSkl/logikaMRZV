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
#include "APVComponent.c"

void SettingIci_RangirAPVToDV(int nDV)
{
//������ APV �� ��
int numDV = nDV - DV1_SM;//����������
//���� ��� �� �� 
 if(isActivCmdDV(START_AFU_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(APV_COMP1,  1, IOCMD2_APV, nDV);//������ 
//���������� ��� �� ��
 if(isActivCmdDV(BLOCK_AFU_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(APV_COMP1,  1, IOCMD1_APV, nDV);//������ 

}// SettingIci_RangirAPVToDV(int nDV)

void SettingIci_RangirAPVToRele(int nRele)
{
//������ APV �� ����
int numRele = nRele - RELE1_SM;//����������
//���� ��� �� �� 
 if(isActivCmdRele(START_AFU_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
      SetCmdToUVV(APV_COMP1,  1, IOCMD2_APV, nRele);//������ 
        //���������� ��� �� ��
 if(isActivCmdRele(BLOCK_AFU_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
      SetCmdToUVV(APV_COMP1,  1, IOCMD1_APV, nRele);//������ 

//APV1
 if(isActivCmdRele(ARCL1_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
      SetCmdToUVV(APV_COMP1,  1, IOCMD4_APV, nRele);//������ 
//APV2
 if(isActivCmdRele(ARCL2_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
      SetCmdToUVV(APV_COMP1,  1, IOCMD5_APV, nRele);//������ 
}// SettingIci_RangirAPVToRele(int nRele)

void SettingIci_RangirAPVToLed(int nLed)
{
//������ UMM �� ���
int numLed = nLed - CDI1_SM;//����������
// ���������� UMin1
// if(isActivCmdLed(BLOCK_UMIN1_DI_OEPRF_ONB, numLed))//�������� ���������� ������� �� ����
  //    SetCmdToUVV(APV_COMP1,  1, IOCMD3_UMM, nLed);//������ 
}// SettingIci_RangirAPVToLed(int nLed)
