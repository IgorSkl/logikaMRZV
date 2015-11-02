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

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

void SettingIci_OFPRM1(int typFUNC, int FlagMaska, int numOF)
{
//отранж OF на Реле
//int numRele = nRele - RELE1_SM;//нормировка
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

//----------------------------PRM1------------------------------
//  lSt1 = pntPuskOF(HVSW_ON_DI_OEPRF_ONB );// Вкл. ВВ от ДВ 
  //if(lSt1) SetCmdToUVV(PRM1_COMP1,  1, IOCMD6_MTZ1, typRang);//PUSK1OF_SM);//запуск OF+
//  lSt1 = pntPuskOF(EDF01_OEPRF_ONB, numOF);
//  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF1, typRang);//работа с OF OT

      // Положение ВВ (выключателя)
  lSt1 = pntPuskOF(SWITCH_STATE_DI_OEPRF_ONB,  numOF);
  if(lSt1)    SetCmdToUVV(PRM1_COMP1,  1, IOCMD1_PRM1, typRang);//работа с OF OT

// Откл. ВВ 
  lSt1 = pntPuskOF(HVSW_OFF_DI_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(PRM1_COMP1,  1, IOCMD3_PRM1, typRang);//работа с OF OT

//вкл ВВ
  lSt1 = pntPuskOF(HVSW_ON_DI_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(PRM1_COMP1,  1, IOCMD7_PRM1, typRang);//работа с OF OT

//Контроль Вкл
  lSt1 = pntPuskOF(CTRL_VKL_DI_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(PRM1_COMP1,  1, IOCMD8_PRM1, typRang);//работа с OF OT
//Контроль Откл
  lSt1 = pntPuskOF(CTRL_OTKL_DI_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(PRM1_COMP1,  1, IOCMD9_PRM1, typRang);//работа с OF OT

// Сброс Реле	
  lSt1 = pntPuskOF(RESET_SIGOUT_DI_OEPRF_ONB,  numOF);
  if(lSt1)    SetCmdToUVV(PRM1_COMP1,  1, IOCMD10_PRM1, typRang);//работа с OF OT
// Сброс индикаци
  lSt1 = pntPuskOF(RESET_LED_DI_OEPRF_ONB,  numOF);
  if(lSt1)    SetCmdToUVV(PRM1_COMP1,  1, IOCMD11_PRM1, typRang);//работа с OF OT

// Блокировка включения ВВ
  lSt1 = pntPuskOF(BLOCK_SWITCHOVER_DI_OEPRF_ONB,  numOF);
  if(lSt1)    SetCmdToUVV(PRM1_COMP1,  1, IOCMD12_PRM1, typRang);//работа с OF OT
// Разблокировка включения ВВ
  lSt1 = pntPuskOF(PERMIT_BLK_SW_MCP_DI_OEPRF_ONB,  numOF);
  if(lSt1)    SetCmdToUVV(PRM1_COMP1,  1, IOCMD13_PRM1, typRang);//работа с OF OT

//Привод ВВ
  lSt1 = pntPuskOF(DRIVER_SW_DI_OEPRF_ONB,  numOF);
  if(lSt1)    SetCmdToUVV(PRM1_COMP1,  1, IOCMD14_PRM1, typRang);//работа с OF OT



}

