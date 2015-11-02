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
#include "UMMComponent.cpp"

void GettingIci_RangirUMMFromDV(int nDV)
{
//������ UMM �� ��
int numDV = nDV - DV1_SM;//����������

// ���������� UMin1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD3_UMM, nDV))//��������� �������
      setActivCmdDV(0, 0);//BLOCK_UMIN1_DI_IEPRF_ONB, numDV);//��������� �������� ������� �� ��
// ���������� UMin2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD4_UMM, nDV))//������
      setActivCmdDV(0, 0);//BLOCK_UMIN2_DI_IEPRF_ONB, numDV))//��������� �������� ������� �� ��

// ���������� UMax1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD1_UMM, nDV))//��������� �������
            setActivCmdDV(0, 0);//, numDV))//��������� �������� ������� �� ��
// ���������� UMax2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD2_UMM, nDV))//��������� �������
           setActivCmdDV(0, 0);//, numDV))//��������� �������� ������� �� ��

}//GettingIci_RangirUMMFromDV(int nDV)

void GettingIci_RangirUMMFromRele(int nRele)
{
//������ UMM �� ����
int numRele = nRele - RELE1_SM;//����������
// ���������� UMin1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD3_UMM, nRele))//��������� �������
    setActivCmdRele(0, 0);//BLOCK_UMIN1_DI_OEPRF_ONB, numRele))//��������� �������� ������� �� ����
// ���������� UMin2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD4_UMM, nRele))//��������� �������
    setActivCmdRele(0, 0);//BLOCK_UMIN2_DI_OEPRF_ONB, numRele))//��������� �������� ������� �� ����
// �� UMin1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD9_UMM, nRele))//��������� �������
    setActivCmdRele(0, 0);//STPDEV_UMIN1_OEPRF_ONB, numRele))//��������� �������� ������� �� ����
// UMin1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD10_UMM, nRele))//��������� �������
   setActivCmdRele(0, 0);//UMIN1_OEPRF_ONB, numRele))//��������� �������� �� ����

// �� UMin2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD11_UMM, nRele))//��������� �������
    setActivCmdRele(0, 0);//STPDEV_UMIN2_OEPRF_ONB, numRele))//��������� �������� ������� �� ����
// UMin2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD12_UMM, nRele))//��������� �������
     setActivCmdRele(0, 0);//STPDEV_UMIN2_OEPRF_ONB, numRele))//��������� �������� ������� �� ����

// ���������� UMax1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD1_UMM, nRele))//��������� �������
    setActivCmdRele(0, 0);//, numRele))//��������� �������� ������� �� ����
// ���������� UMax2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD2_UMM, nRele))//��������� �������
    setActivCmdRele(0, 0);//, numRele))//��������� �������� ������� �� ����

// �� UMax1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD5_UMM, nRele))//��������� �������
   setActivCmdRele(0, 0);//STPDEV_UMAX1_OEPRF_ONB, numRele))//��������� �������� ������� �� ����
// UMax1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD6_UMM, nRele))//��������� �������
    setActivCmdRele(0, 0);//UMAX1_OEPRF_ONB, numRele))//��������� �������� ������� �� ����
// �� UMax2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD7_UMM, nRele))//��������� �������
     setActivCmdRele(0, 0);//STPDEV_UMAX2_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// UMax2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD8_UMM, nRele))//��������� �������
   setActivCmdRele(0, 0);//UMAX2_OEPRF_ONB, numRele))//��������� �������� ������� �� ����
}// GettingIci_RangirUMMFromRele(int nRele)

void GettingIci_RangirUMMFromLed(int nLed)
{
//������ UMM �� ���
int numLed = nLed - CDI1_SM;//����������
// ���������� UMin1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD3_UMM, nLed));//��������� �������
//   setActivCmdLed(BLOCK_UMIN1_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���������� UMin2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD4_UMM, nLed));//��������� �������
//    setActivCmdLed(BLOCK_UMIN2_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� UMin1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD9_UMM, nLed));//��������� �������
//   setActivCmdLed(STPDEV_UMIN1_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// UMin1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD10_UMM, nLed));//��������� �������
//   setActivCmdLed(UMIN1_OEPRF_ONB, numLed))//��������� �������� ������� �� ���

// �� UMin2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD11_UMM, nLed));//��������� �������
//   setActivCmdLed(STPDEV_UMIN2_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// UMin2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD12_UMM, nLed));//��������� �������
//    setActivCmdLed(STPDEV_UMIN2_OEPRF_ONB, numLed))//��������� �������� ������� �� ���

// ���������� UMax1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD1_UMM, nLed));//��������� �������
// setActivCmdLed(, numLed))//��������� �������� ������� �� ���
// ���������� UMax2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD2_UMM, nLed));//��������� �������
// setActivCmdLed(, numLed))//��������� �������� ������� �� ���
  
// �� UMax1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD5_UMM, nLed));//��������� �������
//   setActivCmdLed(STPDEV_UMAX1_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// UMax1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD6_UMM, nLed));//��������� �������
//   setActivCmdLed(UMAX1_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� UMax2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD7_UMM, nLed));//��������� �������
//   setActivCmdLed(STPDEV_UMAX2_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// UMax2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD8_UMM, nLed));//��������� �������
//   setActivCmdLed(UMAX2_OEPRF_ONB, numLed))//��������� �������� �� ���
}// GettingIci_RangirUMMGromLed(int nLed)
