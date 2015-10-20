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
  int numDV = nDV - DV1_SM;//нормировка
      // Положение ВВ (выключателя)
  if(isActivCmdDV(SWITCH_STATE_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD1_PRM1, nDV);//отранж CMD_POL_VV на ДВ
      //Ручное откл ВВ
//HVSW_OFF_DI_IEPRF_ONB                ,// Откл. ВВ 
  if(isActivCmdDV(HVSW_OFF_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD3_PRM1, nDV);//отранж CMD_HANDOTKL_VV на ДВ
//IOCMD3_PRM1
}//SettingIci_RangirPRM2DV(int nDV)

void SettingIci_RangirPRM1ToRele(int nRele)
{
//отранж PRM1 на Реле
int numRele = nRele - RELE1_SM;//нормировка
// Неисправность цепйй напр ДистЗ
 if(isActivCmdRele(FLT_U_DSTP_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD2_PRM1, nRele);//отранж 
}// SettingIci_RangirUMM2Rele(int nRele)

void SettingIci_RangirPRM1ToLed(int nLed)
{
//отранж DZ1 на СДИ
int numLed = nLed - CDI1_SM;//нормировка
// Блокировка UMin1
// if(isActivCmdLed(BLOCK_UMIN1_DI_OEPRF_ONB, numLed))//проверка активности команды на Реле
  //    SetCmdToUVV(UMM_COMP1,  1, IOCMD3_UMM, nLed);//отранж 

}// SettingIci_RangirPRM1ToRele(int nLed)
