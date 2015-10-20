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
#include "UROVComponent.c"

void SettingIci_RangirUROVToDV(int nDV)
{
//отранж UROV на ДВ
int numDV = nDV - DV1_SM;//нормировка
//Пуск UROV от ДВ 
 if(isActivCmdDV(START_UROV_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(UROV_COMP1,  1, IOCMD2_UROV, nDV);//отранж 
//Блокировка UROV ОТ ДВ
 //if(isActivCmdDV(BLOCK_AFU_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//      SetCmdToUVV(UROV_COMP1,  1, IOCMD1_UROV, nDV);//отранж 

}// SettingIci_RangirUROVToDV(int nDV)

void SettingIci_RangirUROVToRele(int nRele)
{
//отранж UROV на Реле
int numRele = nRele - RELE1_SM;//нормировка
//Пуск UROV от ДВ 
 if(isActivCmdRele(START_UROV_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(UROV_COMP1,  1, IOCMD2_UROV, nRele);//отранж 

//UROV1
 if(isActivCmdRele(UROV1_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(UROV_COMP1,  1, IOCMD3_UROV, nRele);//отранж 
//UROV2
 if(isActivCmdRele(UROV2_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(UROV_COMP1,  1, IOCMD4_UROV, nRele);//отранж 
}// SettingIci_RangirAPVToRele(int nRele)

void SettingIci_RangirUROVToLed(int nLed)
{
//отранж UROV на СДИ
int numLed = nLed - CDI1_SM;//нормировка
// Блокировка UMin1
// if(isActivCmdLed(BLOCK_UMIN1_DI_OEPRF_ONB, numLed))//проверка активности команды на Реле
  //    SetCmdToUVV(APV_COMP1,  1, IOCMD3_UMM, nLed);//отранж 
}// SettingIci_RangirAPVToLed(int nLed)
