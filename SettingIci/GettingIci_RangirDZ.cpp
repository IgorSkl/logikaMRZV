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
#include "DZ1Component.cpp"
#include "DZ2Component.cpp"

void GettingIci_RangirDZFromDV(int nDV)
{
//������ DZ1 �� ��
int numDV = nDV - DV1_SM;//����������
// ���������� DZ1
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD1_DZ1, nDV));//��������� �������
//      setActivCmdDV(BLOCK_DSTP1_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��

// ���������� DZ2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD1_DZ2to5, nDV));//��������� �������
//      setActivCmdDV(BLOCK_DSTP2_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
//���������� ����� ���� �2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD2_DZ2to5, nDV));//��������� �������
//      setActivCmdDV(BLOCK_ACCLT_DSTP2_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
//����������� ��������� ���� �2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD3_DZ2to5, nDV));//��������� �������
//      setActivCmdDV(ACCLT_DSTP2_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��

// ���������� DZ3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD1_DZ2to5, nDV));//��������� �������
//      setActivCmdDV(BLOCK_DSTP3_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
//���������� ����� ���� �3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD2_DZ2to5, nDV));//��������� �������
//      setActivCmdDV(BLOCK_ACCLT_DSTP3_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
//����������� ��������� ���� �3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD3_DZ2to5, nDV));//��������� �������
//      setActivCmdDV(ACCLT_DSTP3_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��

// ���������� DZ4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD1_DZ2to5, nDV));//��������� �������
//      setActivCmdDV(BLOCK_DSTP4_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
//���������� ����� ���� �4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD2_DZ2to5, nDV));//��������� �������
//      setActivCmdDV(BLOCK_ACCLT_DSTP4_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
//����������� ��������� ���� �4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD3_DZ2to5, nDV));//��������� �������
//      setActivCmdDV(ACCLT_DSTP4_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��

// ���������� DZ5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD1_DZ2to5, nDV));//��������� �������
//      setActivCmdDV(BLOCK_DSTP5_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
//���������� ����� ���� �5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD2_DZ2to5, nDV));//��������� �������
//      setActivCmdDV(BLOCK_ACCLT_DSTP5_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
//����������� ��������� ���� �5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD3_DZ2to5, nDV));//��������� �������
//      setActivCmdDV(ACCLT_DSTP5_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��

}//GettingIci_RangirDZFromDV(int nDV)

void GettingIci_RangirDZFromRele(int nRele)
{
//������ DZ1 �� ����
int numRele = nRele - RELE1_SM;//����������
// ���������� DZ1
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD1_DZ1, nRele));//��������� �������
//    setActivCmdRele(BLOCK_DSTP1_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// �� ��1 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD2_DZ1, nRele));//��������� �������
//    setActivCmdRele(STPDEV_DSTP1_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// C��� ��1 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD3_DZ1, nRele));//��������� �������
//    setActivCmdRele(DSTP1_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// �� ��� ��1
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD4_DZ1, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP_DSTP1_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// ���� ��� ��1
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD5_DZ1, nRele));//��������� �������
//    setActivCmdRele(MCP_DSTP1_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// �� ��1 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD6_DZ1, nRele));//��������� �������
//    setActivCmdRele(STPDEV_DSTP1_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// ���� ��1 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD7_DZ1, nRele));//��������� �������
//    setActivCmdRele(DSTP1_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele

// ���������� DZ2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD1_DZ2to5, nRele));//��������� �������
//    setActivCmdRele(BLOCK_DSTP2_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
//���������� ����� ���� �2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD2_DZ2to5, nRele));//��������� �������
//    setActivCmdRele(BLOCK_ACCLT_DSTP2_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
//����������� ��������� ���� �2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD3_DZ2to5, nRele));//��������� �������
//    setActivCmdRele(ACCLT_DSTP2_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// �� ��2 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD4_DZ2to5MF, nRele));//��������� �������
//    setActivCmdRele(STPDEV_DSTP2_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// C��� ��2 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD5_DZ2to5MF, nRele));//��������� �������
//    setActivCmdRele(DSTP2_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// �� ��� ��2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD4_MDZ2to5MF, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP_DSTP2_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// ���� ��� ��2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD5_MDZ2to5MF, nRele));//��������� �������
//    setActivCmdRele(MCP_DSTP2_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// �� ��2 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD4_DZ2to5OF, nRele));//��������� �������
//    setActivCmdRele(STPDEV_DSTP2_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// ���� ��2 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD5_DZ2to5OF, nRele));//��������� �������
//    setActivCmdRele(DSTP2_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele


// ���������� DZ3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD1_DZ2to5, nRele));//��������� �������
//    setActivCmdRele(BLOCK_DSTP3_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
//���������� ����� ���� �3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD2_DZ2to5, nRele));//��������� �������
//    setActivCmdRele(BLOCK_ACCLT_DSTP3_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
//����������� ��������� ���� �3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD3_DZ2to5, nRele));//��������� �������
//    setActivCmdRele(ACCLT_DSTP3_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// �� ��3 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD4_DZ2to5MF, nRele));//��������� �������
//    setActivCmdRele(STPDEV_DSTP3_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// C��� ��3 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD5_DZ2to5MF, nRele));//��������� �������
//    setActivCmdRele(DSTP3_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// �� ��� ��3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD4_MDZ2to5MF, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP_DSTP3_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// ���� ��� ��3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD5_MDZ2to5MF, nRele));//��������� �������
//    setActivCmdRele(MCP_DSTP3_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// �� ��3 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD4_DZ2to5OF, nRele));//��������� �������
//    setActivCmdRele(STPDEV_DSTP3_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// ���� ��3 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD5_DZ2to5OF, nRele));//��������� �������
//    setActivCmdRele(DSTP3_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele

// ���������� DZ4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD1_DZ2to5, nRele));//��������� �������
//    setActivCmdRele(BLOCK_DSTP4_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
//���������� ����� ���� �4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD2_DZ2to5, nRele));//��������� �������
//    setActivCmdRele(BLOCK_ACCLT_DSTP4_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
//����������� ��������� ���� �4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD3_DZ2to5, nRele));//��������� �������
//    setActivCmdRele(ACCLT_DSTP4_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// �� ��4 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD4_DZ2to5MF, nRele));//��������� �������
//    setActivCmdRele(STPDEV_DSTP4_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// C��� ��4 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD5_DZ2to5MF, nRele));//��������� �������
//    setActivCmdRele(DSTP4_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// �� ��� ��4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD4_MDZ2to5MF, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP_DSTP4_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// ���� ��� ��4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD5_MDZ2to5MF, nRele));//��������� �������
//    setActivCmdRele(MCP_DSTP4_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// �� ��4 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD4_DZ2to5OF, nRele));//��������� �������
//    setActivCmdRele(STPDEV_DSTP4_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// ���� ��4 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD5_DZ2to5OF, nRele));//��������� �������
//    setActivCmdRele(DSTP4_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele

// ���������� DZ5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD1_DZ2to5, nRele));//��������� �������
//    setActivCmdRele(BLOCK_DSTP5_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
//���������� ����� ���� �5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD2_DZ2to5, nRele));//��������� �������
//    setActivCmdRele(BLOCK_ACCLT_DSTP5_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
//����������� ��������� ���� �5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD3_DZ2to5, nRele));//��������� �������
//    setActivCmdRele(ACCLT_DSTP5_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// �� ��5 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD4_DZ2to5MF, nRele));//��������� �������
//    setActivCmdRele(STPDEV_DSTP5_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// C��� ��5 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD5_DZ2to5MF, nRele));//��������� �������
//    setActivCmdRele(DSTP5_MF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// �� ��� ��5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD4_MDZ2to5MF, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP_DSTP5_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// ���� ��� ��5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD5_MDZ2to5MF, nRele));//��������� �������
//    setActivCmdRele(MCP_DSTP5_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// �� ��5 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD4_DZ2to5OF, nRele));//��������� �������
//    setActivCmdRele(STPDEV_DSTP5_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele
// ���� ��5 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD5_DZ2to5OF, nRele));//��������� �������
//    setActivCmdRele(DSTP5_OF_OEPRF_ONB, numRele))//�������� ���������� ������� �� Rele

}//GettingIci_RangirDZFromRele(int nRele)

void GettingIci_RangirDZFromLed(int nLed)
{
//������ DZ1 �� ���
int numLed = nLed - CDI1_SM;//����������

// ���������� DZ1
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD1_DZ1, nLed));//��������� �������
//    setActivCmdLed(BLOCK_DSTP1_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ��1 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD2_DZ1, nLed));//��������� �������
//    setActivCmdLed(STPDEV_DSTP1_MF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// C��� ��1 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD3_DZ1, nLed));//��������� �������
//    setActivCmdLed(DSTP1_MF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ��� ��1
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD4_DZ1, nLed));//��������� �������
//    setActivCmdLed(STPDEV_MCP_DSTP1_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���� ��� ��1
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD5_DZ1, nLed));//��������� �������
//    setActivCmdLed(MCP_DSTP1_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ��1 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD6_DZ1, nLed));//��������� �������
//    setActivCmdLed(STPDEV_DSTP1_OF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���� ��1 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD7_DZ1, nLed));//��������� �������
//    setActivCmdLed(DSTP1_OF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���

// ���������� DZ2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD1_DZ2to5, nLed));//��������� �������
//    setActivCmdLed(BLOCK_DSTP2_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
//���������� ����� ���� �2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD2_DZ2to5, nLed));//��������� �������
//    setActivCmdLed(BLOCK_ACCLT_DSTP2_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
//����������� ��������� ���� �2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD3_DZ2to5, nLed));//��������� �������
//    setActivCmdLed(ACCLT_DSTP2_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ��2 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD4_DZ2to5MF, nLed));//��������� �������
//    setActivCmdLed(STPDEV_DSTP2_MF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// C��� ��2 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD5_DZ2to5MF, nLed));//��������� �������
//    setActivCmdLed(DSTP2_MF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ��� ��2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD4_MDZ2to5MF, nLed));//��������� �������
//    setActivCmdLed(STPDEV_MCP_DSTP2_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���� ��� ��2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD5_MDZ2to5MF, nLed));//��������� �������
//    setActivCmdLed(MCP_DSTP2_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ��2 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD4_DZ2to5OF, nLed));//��������� �������
//    setActivCmdLed(STPDEV_DSTP2_OF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���� ��2 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD5_DZ2to5OF, nLed));//��������� �������
//    setActivCmdLed(DSTP2_OF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���


// ���������� DZ3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD1_DZ2to5, nLed));//��������� �������
//    setActivCmdLed(BLOCK_DSTP3_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
//���������� ����� ���� �3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD2_DZ2to5, nLed));//��������� �������
//    setActivCmdLed(BLOCK_ACCLT_DSTP3_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
//����������� ��������� ���� �3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD3_DZ2to5, nLed));//��������� �������
//    setActivCmdLed(ACCLT_DSTP3_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ��3 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD4_DZ2to5MF, nLed));//��������� �������
//    setActivCmdLed(STPDEV_DSTP3_MF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// C��� ��3 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD5_DZ2to5MF, nLed));//��������� �������
//    setActivCmdLed(DSTP3_MF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ��� ��3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD4_MDZ2to5MF, nLed));//��������� �������
//    setActivCmdLed(STPDEV_MCP_DSTP3_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���� ��� ��3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD5_MDZ2to5MF, nLed));//��������� �������
//    setActivCmdLed(MCP_DSTP3_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ��3 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD4_DZ2to5OF, nLed));//��������� �������
//    setActivCmdLed(STPDEV_DSTP3_OF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���� ��3 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD5_DZ2to5OF, nLed));//��������� �������
//    setActivCmdLed(DSTP3_OF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���

// ���������� DZ4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD1_DZ2to5, nLed));//��������� �������
//    setActivCmdLed(BLOCK_DSTP4_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
//���������� ����� ���� �4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD2_DZ2to5, nLed));//��������� �������
//    setActivCmdLed(BLOCK_ACCLT_DSTP4_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
//����������� ��������� ���� �4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD3_DZ2to5, nLed));//��������� �������
//    setActivCmdLed(ACCLT_DSTP4_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ��4 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD4_DZ2to5MF, nLed));//��������� �������
//    setActivCmdLed(STPDEV_DSTP4_MF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// C��� ��4 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD5_DZ2to5MF, nLed));//��������� �������
//    setActivCmdLed(DSTP4_MF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ��� ��4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD4_MDZ2to5MF, nLed));//��������� �������
//    setActivCmdLed(STPDEV_MCP_DSTP4_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���� ��� ��4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD5_MDZ2to5MF, nLed));//��������� �������
//    setActivCmdLed(MCP_DSTP4_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ��4 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD4_DZ2to5OF, nLed));//��������� �������
//    setActivCmdLed(STPDEV_DSTP4_OF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���� ��4 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD5_DZ2to5OF, nLed));//��������� �������
//    setActivCmdLed(DSTP4_OF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���

// ���������� DZ5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD1_DZ2to5, nLed));//��������� �������
//    setActivCmdLed(BLOCK_DSTP5_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
//���������� ����� ���� �5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD2_DZ2to5, nLed));//��������� �������
//    setActivCmdLed(BLOCK_ACCLT_DSTP5_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
//����������� ��������� ���� �5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD3_DZ2to5, nLed));//��������� �������
//    setActivCmdLed(ACCLT_DSTP5_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ��5 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD4_DZ2to5MF, nLed));//��������� �������
//    setActivCmdLed(STPDEV_DSTP5_MF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// C��� ��5 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD5_DZ2to5MF, nLed));//��������� �������
//    setActivCmdLed(DSTP5_MF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ��� ��5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD4_MDZ2to5MF, nLed));//��������� �������
//    setActivCmdLed(STPDEV_MCP_DSTP5_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���� ��� ��5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD5_MDZ2to5MF, nLed));//��������� �������
//    setActivCmdLed(MCP_DSTP5_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ��5 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD4_DZ2to5OF, nLed));//��������� �������
//    setActivCmdLed(STPDEV_DSTP5_OF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���� ��5 ��
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD5_DZ2to5OF, nLed));//��������� �������
//    setActivCmdLed(DSTP5_OF_OEPRF_ONB, numLed))//��������� �������� ������� �� ���

}// SettingIci_RangirDZFromLed(int nLed)
