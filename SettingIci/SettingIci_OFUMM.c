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

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

void  SettingIci_OFUMM(int typFUNC, int FlagMaska, int numOF)
{
//������ ��� �� ����
//int numRele = nRele - RELE1_SM;//����������
//  int typRang
puskOFfunction *pntPuskOF;

  int typRang = PUSK1OF_SM;
  if(typFUNC==0){//OF
  typRang = typRang - numOF*3 - FlagMaska;

  switch(FlagMaska){
   case 0://PLUS
    pntPuskOF = &puskOFotZPLUS;
   break;
   case 1://MINUS
    pntPuskOF = &puskOFotZMINUS;
   break;
   case 2://BLK
    pntPuskOF = &puskOFotZBLK;
   break;
  }//switch
  }//if(typFUNC==0)
  if(typFUNC==1){//OT
  typRang = PUSK1OT1_SM;
  typRang = typRang - numOF*4 - FlagMaska;

  switch(FlagMaska){
   case 0://PLUS Set
    pntPuskOF = &puskSetOTotZPLUS;
   break;
   case 1://PLUS Rst
    pntPuskOF = &puskRstOTotZPLUS;
   break;
   case 2://MINUS Set
    pntPuskOF = &puskSetOTotZMINUS;
   break;
   case 3://MINUS Rst
    pntPuskOF = &puskRstOTotZMINUS;
   break;
  }//switch
  }//if(typFUNC==0)

//������ UMM �� ����
//int numRele = nRele - RELE1_SM;//����������
// ���������� UMin1
  lSt1 = pntPuskOF(BLOCK_UMIN1_DI_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(UMM_COMP1,  1, IOCMD3_UMM, typRang);//������ � OF OT
// ���������� UMin2
  lSt1 = pntPuskOF(BLOCK_UMIN2_DI_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(UMM_COMP1,  1, IOCMD4_UMM, typRang);//������ � OF OT

//���� Umin1
  lSt1 = pntPuskOF(START_UMIN1_DI_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(UMM_COMP1,  1, IOCMDPUSK1_UMM, typRang);//������ � OF OT
//���� Umin2
  lSt1 = pntPuskOF(START_UMIN2_DI_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(UMM_COMP1,  1, IOCMDPUSK2_UMM, typRang);//������ � OF OT

// �� UMin1
  lSt1 = pntPuskOF(STPDEV_UMIN1_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(UMM_COMP1,  1, IOCMD9_UMM, typRang);//������ � OF OT
// UMin1
  lSt1 = pntPuskOF(UMIN1_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(UMM_COMP1,  1, IOCMD10_UMM, typRang);//������ � OF OT

// �� UMin2
  lSt1 = pntPuskOF(STPDEV_UMIN2_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(UMM_COMP1,  1, IOCMD11_UMM, typRang);//������ � OF OT
// UMin2
  lSt1 = pntPuskOF(UMIN2_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(UMM_COMP1,  1, IOCMD12_UMM, typRang);//������ � OF OT

// ���������� UMax1
// if(isActivCmdRele(, numRele))//�������� ���������� ������� �� ����
//      SetCmdToUVV(UMM_COMP1,  1, IOCMD1_UMM, nRele);//������ 
// ���������� UMax2
// if(isActivCmdRele(, numRele))//�������� ���������� ������� �� ����
  //    SetCmdToUVV(UMM_COMP1,  1, IOCMD2_UMM, nRele);//������ 
  
// �� UMax1
  lSt1 = pntPuskOF(STPDEV_UMAX1_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(UMM_COMP1,  1, IOCMD5_UMM, typRang);//������ � OF OT
// UMax1
  lSt1 = pntPuskOF(UMAX1_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(UMM_COMP1,  1, IOCMD6_UMM, typRang);//������ � OF OT
// �� UMax2
  lSt1 = pntPuskOF(STPDEV_UMAX2_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(UMM_COMP1,  1, IOCMD7_UMM, typRang);//������ � OF OT
// UMax2
  lSt1 = pntPuskOF(UMAX2_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(UMM_COMP1,  1, IOCMD8_UMM, typRang);//������ � OF OT


}//SettingIci_OFUMM(int FlagMaska, int numOF)

