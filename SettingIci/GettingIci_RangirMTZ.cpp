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
#include "MTZ1Component.cpp"
#include "MTZ2Component.cpp"

void GettingIci_RangirMTZFromDV(int nDV)
{
//������ ��� �� ��
int numDV = nDV - DV1_SM;//����������
// ���������� ���1
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD1_MTZ1, nDV));//��������� �������
//      setActivCmdDV(BLOCK_MCP1_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
// ���������� ���2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD1_MTZ2to5, nDV));//��������� �������
//      setActivCmdDV(BLOCK_MCP2_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
// ���������� ���3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD1_MTZ2to5, nDV));//��������� �������
//      setActivCmdDV(BLOCK_MCP3_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
// ���������� ���4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD1_MTZ2to5, nDV));//��������� �������
//      setActivCmdDV(BLOCK_MCP4_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
// ���������� ���5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD1_MTZ2to5, nDV));//��������� �������
//      setActivCmdDV(BLOCK_MCP5_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��

//����������� ��������� ���2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD3_MTZ2to5, nDV));//��������� �������
//      setActivCmdDV(ACCLT_MCP2_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
//����������� ��������� ���3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD3_MTZ2to5, nDV));//��������� �������
//      setActivCmdDV(ACCLT_MCP3_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
//����������� ��������� ���4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD3_MTZ2to5, nDV));//��������� �������
//      setActivCmdDV(ACCLT_MCP4_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��
//����������� ��������� ���5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD3_MTZ2to5, nDV));//��������� �������
//      setActivCmdDV(ACCLT_MCP5_DI_IEPRF_ONB, numDV))//�������� ���������� ������� �� ��

}//GettingIci_RangirMTZFromDV()

void GettingIci_RangirMTZFromRele(int nRele)
{
//������ ��� �� ����
int numRele = nRele - RELE1_SM;//����������
// ���������� ���1
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD1_MTZ1, nRele));//��������� �������
//    setActivCmdRele(BLOCK_MCP1_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����

// ���������� ���2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD1_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(BLOCK_MCP2_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// ���������� ���3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD1_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(BLOCK_MCP3_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// ���������� ���4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD1_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(BLOCK_MCP4_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// ���������� ���5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD1_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(BLOCK_MCP5_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����

//����������� ��������� ���2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD3_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(ACCLT_MCP2_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
//����������� ��������� ���3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD3_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(ACCLT_MCP3_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
//����������� ��������� ���4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD3_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(ACCLT_MCP4_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
//����������� ��������� ���5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD3_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(ACCLT_MCP5_DI_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����

// �� ���1
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD2_MTZ1, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP1_BORING_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// �� ���1 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD3_MTZ1, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP1_STAIGHT_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// �� ���1 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD4_MTZ1, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP1_BACK_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// �� ���1 ��
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD5_MTZ1, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP1_VLT_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// ���� ���1
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD6_MTZ1, nRele));//��������� �������
//    setActivCmdRele(MCP1_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����

// �� ���2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD4_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP2_BORING_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// �� ���2 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD5_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP2_STAIGHT_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// �� ���2 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD6_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP2_BACK_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// �� ���2 ��
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD7_MTZ2to5, nRele));//������ 
//    setActivCmdRele(STPDEV_MCP2_VLT_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// ���� ���2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD8_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(MCP2_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����

// �� ���3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD4_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP3_BORING_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// �� ���3 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD5_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP3_STAIGHT_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// �� ���3 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD6_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP3_BACK_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// �� ���3 ��
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD7_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP3_VLT_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// ���� ���3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD8_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(MCP3_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����

// �� ���4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD4_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP4_BORING_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// �� ���4 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD5_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP4_STAIGHT_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// �� ���4 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD6_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP4_BACK_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// �� ���4 ��
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD7_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP4_VLT_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// ���� ���4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD8_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(MCP4_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����

// �� ���5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD4_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP5_BORING_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// �� ���5 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD5_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP5_STAIGHT_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// �� ���5 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD6_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP5_BACK_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// �� ���5 ��
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD7_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(STPDEV_MCP5_VLT_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
// ���� ���5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD8_MTZ2to5, nRele));//��������� �������
//    setActivCmdRele(MCP5_OEPRF_ONB, numRele))//�������� ���������� ������� �� ����
}//GettingIci_RangirMTZFromRele(int nRele)

void GettingIci_RangirMTZFromLed(int nLed)
{
//������ ��� �� ���
int numLed = nLed - CDI1_SM;//����������
// ���������� ���1
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD1_MTZ1, nLed));//��������� �������
//   setActivCmdLed(BLOCK_MCP1_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���������� ���2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD1_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(BLOCK_MCP2_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���������� ���3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD1_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(BLOCK_MCP3_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���������� ���4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD1_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(BLOCK_MCP4_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���������� ���5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD1_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(BLOCK_MCP5_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���

//����������� ��������� ���2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD3_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(ACCLT_MCP2_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
//����������� ��������� ���3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD3_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(ACCLT_MCP3_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
//����������� ��������� ���4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD3_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(ACCLT_MCP4_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
//����������� ��������� ���5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD3_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(ACCLT_MCP5_DI_OEPRF_ONB, numLed))//��������� �������� ������� �� ���

// �� ���1
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD2_MTZ1, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP1_BORING_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ���1 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD3_MTZ1, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP1_STAIGHT_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ���1 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD4_MTZ1, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP1_BACK_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ���1 ��
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD5_MTZ1, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP1_VLT_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���� ���1
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD6_MTZ1, nLed));//��������� �������
//   setActivCmdLed(MCP1_OEPRF_ONB, numLed))//��������� �������� ������� �� ���

// �� ���2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD4_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP2_BORING_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ���2 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD5_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP2_STAIGHT_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ���2 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD6_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP2_BACK_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ���2 ��
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD7_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP2_VLT_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���� ���2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD8_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(MCP2_OEPRF_ONB, numLed))//��������� �������� ������� �� ���

// �� ���3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD4_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP3_BORING_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ���3 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD5_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP3_STAIGHT_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ���3 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD6_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP3_BACK_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ���3 ��
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD7_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP3_VLT_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���� ���3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD8_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(MCP3_OEPRF_ONB, numLed))//��������� �������� ������� �� ���

// �� ���4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD4_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP4_BORING_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ���4 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD5_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP4_STAIGHT_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ���4 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD6_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP4_BACK_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ���4 ��
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD7_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP4_VLT_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���� ���4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD8_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(MCP4_OEPRF_ONB, numLed))//��������� �������� ������� �� ���

// �� ���5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD4_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP5_BORING_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ���5 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD5_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP5_STAIGHT_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ���5 ���
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD6_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP5_BACK_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// �� ���5 ��
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD7_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(STPDEV_MCP5_VLT_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
// ���� ���5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD8_MTZ2to5, nLed));//��������� �������
//   setActivCmdLed(MCP5_OEPRF_ONB, numLed))//��������� �������� ������� �� ���
}//GettingIci_RangirMTZFromLed(int nRele)
