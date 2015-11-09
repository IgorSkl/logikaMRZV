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

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

void SettingIci_OFAPV(int typFUNC, int FlagMaska, int numOF)
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

//----------------------------APV------------------------------
//Пуск АПВ от ДВ 
  lSt1 = pntPuskOF(START_AFU_DI_OEPRF_ONB,  numOF);
  if(lSt1)    SetCmdToUVV(APV_COMP1,  1, IOCMD2_APV,  typRang);//работа с OF OT
//Блокировка АПВ ОТ ДВ
  lSt1 = pntPuskOF(BLOCK_AFU_DI_OEPRF_ONB,  numOF);
  if(lSt1)    SetCmdToUVV(APV_COMP1,  1, IOCMD1_APV,  typRang);//работа с OF OT

//APV1
  lSt1 = pntPuskOF(ARCL1_OEPRF_ONB,  numOF);
  if(lSt1)    SetCmdToUVV(APV_COMP1,  1, IOCMD4_APV, typRang);//работа с OF OT
//APV2
  lSt1 = pntPuskOF(ARCL2_OEPRF_ONB,  numOF);
  if(lSt1)    SetCmdToUVV(APV_COMP1,  1, IOCMD5_APV, typRang);//работа с OF OT
}

