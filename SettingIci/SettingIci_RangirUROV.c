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
#include "UROVComponent.c"

void SettingIci_RangirUROVToDV(int nDV)
{
//������ UROV �� ��
int numDV = nDV - DV1_SM;//����������
//���� UROV �� �� 
 if(isActivCmdDV(START_UROV_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(UROV_COMP1,  1, IOCMD2_UROV, nDV);//������ 
//���������� UROV �� ��
 //if(isActivCmdDV(BLOCK_AFU_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
//      SetCmdToUVV(UROV_COMP1,  1, IOCMD1_UROV, nDV);//������ 

}// SettingIci_RangirUROVToDV(int nDV)

void SettingIci_RangirUROVToRele(int nRele)
{
//������ UROV �� ����
int numRele = nRele - RELE1_SM;//����������
//���� UROV �� �� 
 if(isActivCmdRele(START_UROV_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
      SetCmdToUVV(UROV_COMP1,  1, IOCMD2_UROV, nRele);//������ 

//UROV1
 if(isActivCmdRele(UROV1_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
      SetCmdToUVV(UROV_COMP1,  1, IOCMD3_UROV, nRele);//������ 
//UROV2
 if(isActivCmdRele(UROV2_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
      SetCmdToUVV(UROV_COMP1,  1, IOCMD4_UROV, nRele);//������ 
}// SettingIci_RangirAPVToRele(int nRele)

void SettingIci_RangirUROVToLed(int nLed)
{
//������ UROV �� ���
int numLed = nLed - CDI1_SM;//����������
// ���������� UMin1
// if(isActivCmdLed(BLOCK_UMIN1_DI_OEPRF_ONB, numLed))//�������� ���������� ������� �� ����
  //    SetCmdToUVV(APV_COMP1,  1, IOCMD3_UMM, nLed);//������ 
}// SettingIci_RangirAPVToLed(int nLed)
