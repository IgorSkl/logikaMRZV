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
#include "OFComponent.c"

void SettingIci_RangirOTToDV(int nDV)
{
//������ Set OT �� ��
int numDV = nDV - DV1_SM;//����������
/*
SET_OT1_DI_IEPRF_ONB                 ,//�� ���   ��1 
RESET_OT1_DI_IEPRF_ONB               ,//�� ����� ��1 
*/

// Set OT 01  
 if(isActivCmdDV(SET_OT1_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(OF_COMP1,  1, IOCMD_BKL_OT1, nDV);//������ 
// Rst OT 01  
 if(isActivCmdDV(RESET_OT1_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(OF_COMP1,  1, IOCMD_OTKL_OT1, nDV);//������ 

// Set OT 02  
 if(isActivCmdDV(SET_OT2_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(OF_COMP1,  1, IOCMD_BKL_OT2, nDV);//������ 
// Rst OT 02  
 if(isActivCmdDV(RESET_OT2_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(OF_COMP1,  1, IOCMD_OTKL_OT2, nDV);//������ 

// Set OT 03  
 if(isActivCmdDV(SET_OT3_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(OF_COMP1,  1, IOCMD_BKL_OT3, nDV);//������ 
// Rst OT 03  
 if(isActivCmdDV(RESET_OT3_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(OF_COMP1,  1, IOCMD_OTKL_OT3, nDV);//������ 

// Set OT 04  
 if(isActivCmdDV(SET_OT4_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(OF_COMP1,  1, IOCMD_BKL_OT4, nDV);//������ 
// Rst OT 04  
 if(isActivCmdDV(RESET_OT4_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(OF_COMP1,  1, IOCMD_OTKL_OT4, nDV);//������ 

// Set OT 05  
 if(isActivCmdDV(SET_OT5_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(OF_COMP1,  1, IOCMD_BKL_OT5, nDV);//������ 
// Rst OT 05  
 if(isActivCmdDV(RESET_OT5_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(OF_COMP1,  1, IOCMD_OTKL_OT5, nDV);//������ 

// Set OT 06  
 if(isActivCmdDV(SET_OT6_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(OF_COMP1,  1, IOCMD_BKL_OT6, nDV);//������ 
// Rst OT 06  
 if(isActivCmdDV(RESET_OT6_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(OF_COMP1,  1, IOCMD_OTKL_OT6, nDV);//������ 

// Set OT 07  
 if(isActivCmdDV(SET_OT7_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(OF_COMP1,  1, IOCMD_BKL_OT7, nDV);//������ 
// Rst OT 07  
 if(isActivCmdDV(RESET_OT7_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(OF_COMP1,  1, IOCMD_OTKL_OT7, nDV);//������ 

// Set OT 08  
 if(isActivCmdDV(SET_OT8_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(OF_COMP1,  1, IOCMD_BKL_OT8, nDV);//������ 
// Rst OT 08  
 if(isActivCmdDV(RESET_OT8_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
      SetCmdToUVV(OF_COMP1,  1, IOCMD_OTKL_OT8, nDV);//������ 

}//SettingIci_RangirOTToDV(int nDV)
/*
OUT_OT1_OEPRF_ONB                    ,//����� ��1
OUT_OT2_OEPRF_ONB                    ,//����� ��2
OUT_OT3_OEPRF_ONB                    ,//����� ��3
OUT_OT4_OEPRF_ONB                    ,//����� ��4
OUT_OT5_OEPRF_ONB                    ,//����� ��5
OUT_OT6_OEPRF_ONB                    ,//����� ��6
OUT_OT7_OEPRF_ONB                    ,//����� ��7
OUT_OT8_OEPRF_ONB                    ,//����� ��8 
*/

void SettingIci_RangirOutOTToRele(int nRele)
{
//������ OT �� ����
int numRele = nRele - RELE1_SM;//����������
//����� OT_01  
 if(isActivCmdRele(OUT_OT1_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT1, nRele);//������ 
//����� OT_02
 if(isActivCmdRele(OUT_OT2_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT2, nRele);//������ 
//����� OT_03  
 if(isActivCmdRele(OUT_OT3_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT3, nRele);//������ 
//����� OT_04  
 if(isActivCmdRele(OUT_OT4_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT4, nRele);//������ 
//����� OT_05  
 if(isActivCmdRele(OUT_OT5_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT5, nRele);//������ 
//����� OT_06  
 if(isActivCmdRele(OUT_OT6_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT6, nRele);//������ 
//����� OT_07  
 if(isActivCmdRele(OUT_OT7_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT7, nRele);//������ 
//����� OT_08  
 if(isActivCmdRele(OUT_OT8_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT8, nRele);//������ 
}//SettingIci_RangirOTToRele(int nRele)
