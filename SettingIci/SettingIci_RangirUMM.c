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

void SettingIci_RangirUMM2DV(int nDV)
{
//отранж UMM на ДВ
int numDV = nDV - DV1_SM;//нормировка
// Блокировка UMin1
 if(isActivCmdDV(BLOCK_UMIN1_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(UMM_COMP1,  1, IOCMD3_UMM, nDV);//отранж 
// Блокировка UMin2
 if(isActivCmdDV(BLOCK_UMIN2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(UMM_COMP1,  1, IOCMD4_UMM, nDV);//отранж 

// Блокировка UMax1
// if(isActivCmdDV(, numDV))//проверка активности команды на ДВ
//      SetCmdToUVV(UMM_COMP1,  1, IOCMD1_UMM, nDV);//отранж 
// Блокировка UMax2
// if(isActivCmdDV(, numDV))//проверка активности команды на ДВ
//      SetCmdToUVV(UMM_COMP1,  1, IOCMD2_UMM, nDV);//отранж 
}// SettingIci_RangirUMM2DV(int nDV)

void SettingIci_RangirUMM2Rele(int nRele)
{
//отранж UMM на Реле
int numRele = nRele - RELE1_SM;//нормировка
// Блокировка UMin1
 if(isActivCmdRele(BLOCK_UMIN1_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD3_UMM, nRele);//отранж 
// Блокировка UMin2
 if(isActivCmdRele(BLOCK_UMIN2_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD4_UMM, nRele);//отранж 
// ПО UMin1
 if(isActivCmdRele(STPDEV_UMIN1_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD9_UMM, nRele);//отранж 
// UMin1
 if(isActivCmdRele(UMIN1_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD10_UMM, nRele);//отранж 

// ПО UMin2
 if(isActivCmdRele(STPDEV_UMIN2_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD11_UMM, nRele);//отранж 
// UMin2
 if(isActivCmdRele(UMIN2_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD12_UMM, nRele);//отранж 

// Блокировка UMax1
// if(isActivCmdRele(, numRele))//проверка активности команды на Реле
//      SetCmdToUVV(UMM_COMP1,  1, IOCMD1_UMM, nRele);//отранж 
// Блокировка UMax2
// if(isActivCmdRele(, numRele))//проверка активности команды на Реле
  //    SetCmdToUVV(UMM_COMP1,  1, IOCMD2_UMM, nRele);//отранж 
  
// ПО UMax1
 if(isActivCmdRele(STPDEV_UMAX1_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD5_UMM, nRele);//отранж 
// UMax1
 if(isActivCmdRele(UMAX1_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD6_UMM, nRele);//отранж 
// ПО UMax2
 if(isActivCmdRele(STPDEV_UMAX2_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD7_UMM, nRele);//отранж 
// UMax2
 if(isActivCmdRele(UMAX2_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD8_UMM, nRele);//отранж 


}// SettingIci_RangirUMM2Rele(int nRele)

void SettingIci_RangirUMM2Led(int nLed)
{
//отранж UMM на СДИ
int numLed = nLed - CDI1_SM;//нормировка
// Блокировка UMin1
 if(isActivCmdLed(BLOCK_UMIN1_DI_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD3_UMM, nLed);//отранж 
// Блокировка UMin2
 if(isActivCmdLed(BLOCK_UMIN2_DI_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD4_UMM, nLed);//отранж 
// ПО UMin1
 if(isActivCmdLed(STPDEV_UMIN1_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD9_UMM, nLed);//отранж 
// UMin1
 if(isActivCmdLed(UMIN1_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD10_UMM, nLed);//отранж 

// ПО UMin2
 if(isActivCmdLed(STPDEV_UMIN2_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD11_UMM, nLed);//отранж 
// UMin2
 if(isActivCmdLed(STPDEV_UMIN2_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD12_UMM, nLed);//отранж 

// Блокировка UMax1
// if(isActivCmdLed(, numLed))//проверка активности команды на Реле
//      SetCmdToUVV(UMM_COMP1,  1, IOCMD1_UMM, nLed);//отранж 
// Блокировка UMax2
// if(isActivCmdLed(, numLed))//проверка активности команды на Реле
  //    SetCmdToUVV(UMM_COMP1,  1, IOCMD2_UMM, nLed);//отранж 
  
// ПО UMax1
 if(isActivCmdLed(STPDEV_UMAX1_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD5_UMM, nLed);//отранж 
// UMax1
 if(isActivCmdLed(UMAX1_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD6_UMM, nLed);//отранж 
// ПО UMax2
 if(isActivCmdLed(STPDEV_UMAX2_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD7_UMM, nLed);//отранж 
// UMax2
 if(isActivCmdLed(UMAX2_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(UMM_COMP1,  1, IOCMD8_UMM, nLed);//отранж 


}// SettingIci_RangirUMM2Led(int nLed)
