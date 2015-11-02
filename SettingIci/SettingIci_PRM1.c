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
#include "SettingIci\SettingIci.h"
#include "virtualmenu\systemmenufnc.h"

#include "toSpeedOptim.h"
#include "toSpeedDIS.h"

#include "header.h"
#include "ici_r_ef.h"

#define _HIDE_COMPONENT
#include "PRM1Component.c"

extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;

void  SettingIci_PRM1()
{
//�������� PRM1
     lMtz1Tmr = brCfgTbl.Dstp_T_UI_NCN;//������� UI ���
  SetUstToClon(PRM1_COMP1,  1, MNGVID_PRM1_UINCNDZ, lMtz1Tmr*10);//�������a UI ��� ��
     lMtz1Tmr = brCfgTbl.Dstp_T_NonSymMode_NCN;//�������� ����� ���������� CM ��� ��
  SetUstToClon(PRM1_COMP1,  1, MNGVID_PRM1_CMNCNDZ, lMtz1Tmr*10);//�������� ����� ���������� CM ��� ��

 //T ������ ��
     lMtz1Tmr = brCfgTbl.ownrBru.time_ActuatorHVS;  
  SetUstToClon(PRM1_COMP1,  1, MNGVID_PRM1_PRIVODVV, lMtz1Tmr*10);

//�������� ������������� ����� ����������
     lMtz1Tmr = brCfgTbl.ownrBru.time_stageOFFUnit;   
  SetUstToClon(PRM1_COMP1,  1, MNGUST_PRM1_BO, lMtz1Tmr*10);

//�������� ������������� ����� ���������
     lMtz1Tmr = brCfgTbl.ownrBru.time_stageONUnit;   
  SetUstToClon(PRM1_COMP1,  1, MNGUST_PRM1_BV, lMtz1Tmr*10);

//�������� ������������� ���������� ����� ���������
     lMtz1Tmr = brCfgTbl.ownrBru.time_stageONCtrl;   
  SetUstToClon(PRM1_COMP1,  1, MNGVID_PRM1_BLOKIRBLOKVKL, lMtz1Tmr*10);

//�������� ������������� ��������� ���������� ����� ���������
     lMtz1Tmr = brCfgTbl.ownrBru.time_stageONUnitBlk;   
  SetUstToClon(PRM1_COMP1,  1, MNGVID_PRM1_DELAYBLOKIRBLOKVKL, lMtz1Tmr*10);


//��������� ICI PRM1
  int uprPRM1 = 0;
    long lSt1 = brCfgTbl.state_FaultU_Ocp;//������ ����� ���� MTZ
  if(lSt1>0) uprPRM1 |= 1; // WKL
  else  uprPRM1 &= ~1; // OTKL 
  
//state_FaultU_Dstp
    lSt1 = brCfgTbl.state_FaultU_Dstp;//������ ����� ���� DZ
  if(lSt1>0) uprPRM1 |= 2; // WKL
  else  uprPRM1 &= ~2; // OTKL 

//�������� ��������� ��
    lSt1 = brCfgTbl.ownrBruMngStore.state_Delay_ON_Unit;
  if(lSt1>0) uprPRM1 |= 4; // WKL
  else  uprPRM1 &= ~4; // OTKL 

//���������� ��� �� ���
    lSt1 = brCfgTbl.ownrBruMngStore.state_Blk_SetON;
  if(lSt1>0) uprPRM1 |= 8; // WKL
  else  uprPRM1 &= ~8; // OTKL 

//�������� ��
    lSt1 = brCfgTbl.ownrBruMngStore.state_CheckHVS;
  if(lSt1>0) uprPRM1 |= 16; // WKL
  else  uprPRM1 &= ~16; // OTKL 

//������ ��
    lSt1 = brCfgTbl.ownrBruMngStore.state_ResourceHVS;
  if(lSt1>0) uprPRM1 |= 32; // WKL
  else  uprPRM1 &= ~32; // OTKL 

/*
//�������� ��������� ��
#define ENA_PRM1_ZADWKLVV   2
//���������� ��� �� ���
#define ENA_PRM1_BLOKWKLVV  3
//�������� ��
#define ENA_PRM1_KONTROLVV  4
//������ ��
#define ENA_PRM1_RESURSVV   5
//�������� ������ ��
#define ENA_PRM1_RESETRESURSVV  6

*/
  SetUstToClon(PRM1_COMP1,  1, MNGUPR_PRM1, uprPRM1);//���������� PRM1

}//SettingIci_PRM1()

/*
typedef struct BruDsc_TagIn
{

unsigned short time_stageOFFUnit;  //�������� ������������� ����� ����������
unsigned short time_stageONUnit;   //�������� ������������� ����� ���������
unsigned short time_stageONCtrl;   //�������� ������������� ���������� ����� ���������
unsigned short time_stageONUnitBlk;//�������� ������������� ��������� ���������� ����� ���������
unsigned short time_ActuatorHVS;   //T ������ ��
//////////////////////////////////////////////////////////////////////////////////////////
unsigned char state_Delay_ON_Unit;//�������� ���.
unsigned char state_Blk_SetON;    //���������� ��� �� ���   

}BruDsc;

typedef struct BruMngStoreDsc_TagIn
{

//////////////////////////////////////////////////////////////////////////////////////////
unsigned char state_Delay_ON_Unit;//�������� ���.
unsigned char state_Blk_SetON;    //���������� ��� �� ���   

unsigned char state_CheckHVS;     //�������� ��
unsigned char state_ResourceHVS; //������   ��
}BruMngStoreDsc;

BruMngStoreDsc ownrBruMngStore;

RclrMngStoreDsc   ownrRclrMng;//���
BrfMngStoreDsc    ownrBrfMng; //����
BruDsc    ownrBru; //

*/
