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
//выдержки PRM1
     lMtz1Tmr = brCfgTbl.Dstp_T_UI_NCN;//выдежка UI НЦН
  SetUstToClon(PRM1_COMP1,  1, MNGVID_PRM1_UINCNDZ, lMtz1Tmr*10);//выдержкa UI НЦН ДЗ
     lMtz1Tmr = brCfgTbl.Dstp_T_NonSymMode_NCN;//выдержка обрат последоват CM НЦН ДЗ
  SetUstToClon(PRM1_COMP1,  1, MNGVID_PRM1_CMNCNDZ, lMtz1Tmr*10);//выдержка обрат последоват CM НЦН ДЗ

//установки ICI PRM1
  int uprPRM1 = 0;
    long lSt1 = brCfgTbl.state_FaultU_Ocp;//Неиспр цепей напр MTZ
  if(lSt1>0) uprPRM1 |= 1; // WKL
  else  uprPRM1 &= ~1; // OTKL 
  
//state_FaultU_Dstp
    lSt1 = brCfgTbl.state_FaultU_Dstp;//Неиспр цепей напр DZ
  if(lSt1>0) uprPRM1 |= 2; // WKL
  else  uprPRM1 &= ~2; // OTKL 

  SetUstToClon(PRM1_COMP1,  1, MNGUPR_PRM1, uprPRM1);//управление PRM1
}//SettingIci_PRM1()
