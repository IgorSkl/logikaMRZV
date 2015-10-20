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

void SettingIci_RangirPRM1ToDV(int nDV)
{
  int numDV = nDV - DV1_SM;//����������
      // ��������� �� (�����������)
  if(isActivCmdDV(SWITCH_STATE_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD1_PRM1, nDV);//������ CMD_POL_VV �� ��
      //������ ���� ��
//HVSW_OFF_DI_IEPRF_ONB                ,// ����. �� 
  if(isActivCmdDV(HVSW_OFF_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD3_PRM1, nDV);//������ CMD_HANDOTKL_VV �� ��
//IOCMD3_PRM1
}//SettingIci_RangirPRM2DV(int nDV)

void SettingIci_RangirPRM1ToRele(int nRele)
{
//������ PRM1 �� ����
int numRele = nRele - RELE1_SM;//����������
// ������������� ����� ���� �����
 if(isActivCmdRele(FLT_U_DSTP_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD2_PRM1, nRele);//������ 
}// SettingIci_RangirUMM2Rele(int nRele)

void SettingIci_RangirPRM1ToLed(int nLed)
{
//������ DZ1 �� ���
int numLed = nLed - CDI1_SM;//����������
// ���������� UMin1
// if(isActivCmdLed(BLOCK_UMIN1_DI_OEPRF_ONB, numLed))//�������� ���������� ������� �� ����
  //    SetCmdToUVV(UMM_COMP1,  1, IOCMD3_UMM, nLed);//������ 

}// SettingIci_RangirPRM1ToRele(int nLed)
