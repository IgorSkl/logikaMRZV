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
#include "OFComponent.c"

void SettingIci_RangirOFToDV(int nDV)
{
//отранж UROV на ДВ
int numDV = nDV - DV1_SM;//нормировка
// Вх Оф 01  
 if(isActivCmdDV(EDF01_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_IN_OF1, nDV);//отранж 
 if(isActivCmdDV(EDF02_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_IN_OF2, nDV);//отранж 
 if(isActivCmdDV(EDF03_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_IN_OF3, nDV);//отранж 
 if(isActivCmdDV(EDF04_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_IN_OF4, nDV);//отранж 
 if(isActivCmdDV(EDF05_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_IN_OF5, nDV);//отранж 
 if(isActivCmdDV(EDF06_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_IN_OF6, nDV);//отранж 
 if(isActivCmdDV(EDF07_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_IN_OF7, nDV);//отранж 
 if(isActivCmdDV(EDF08_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_IN_OF8, nDV);//отранж 
 if(isActivCmdDV(EDF09_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_IN_OF9, nDV);//отранж 
 if(isActivCmdDV(EDF10_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_IN_OF10, nDV);//отранж 
 if(isActivCmdDV(EDF11_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_IN_OF11, nDV);//отранж 
 if(isActivCmdDV(EDF12_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_IN_OF12, nDV);//отранж 
 if(isActivCmdDV(EDF13_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_IN_OF13, nDV);//отранж 
 if(isActivCmdDV(EDF14_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_IN_OF14, nDV);//отранж 
 if(isActivCmdDV(EDF15_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_IN_OF15, nDV);//отранж 
 if(isActivCmdDV(EDF16_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_IN_OF16, nDV);//отранж 

}// SettingIci_RangirUROVToDV(int nDV)

void SettingIci_RangirOFToRele(int nRele)
{
//отранж UROV на Реле
int numRele = nRele - RELE1_SM;//нормировка
//Выход Оф_01  
 if(isActivCmdRele(EDF01_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF1, nRele);//отранж 
 if(isActivCmdRele(EDF02_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF2, nRele);//отранж 
 if(isActivCmdRele(EDF03_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF3, nRele);//отранж 

 if(isActivCmdRele(EDF04_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF4, nRele);//отранж 
 if(isActivCmdRele(EDF05_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF5, nRele);//отранж 
 if(isActivCmdRele(EDF06_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF6, nRele);//отранж 
 if(isActivCmdRele(EDF07_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF7, nRele);//отранж 
 if(isActivCmdRele(EDF08_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF8, nRele);//отранж 
 if(isActivCmdRele(EDF09_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF9, nRele);//отранж 
 if(isActivCmdRele(EDF10_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF10, nRele);//отранж 
 if(isActivCmdRele(EDF11_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF11, nRele);//отранж 
 if(isActivCmdRele(EDF12_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF12, nRele);//отранж 
 if(isActivCmdRele(EDF13_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF13, nRele);//отранж 
 if(isActivCmdRele(EDF14_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF14, nRele);//отранж 
 if(isActivCmdRele(EDF15_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF15, nRele);//отранж 
 if(isActivCmdRele(EDF16_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF16, nRele);//отранж 
   
}// SettingIci_RangirAPVToRele(int nRele)

void SettingIci_RangirOFToLed(int nLed)
{
//отранж UROV на СДИ
int numLed = nLed - CDI1_SM;//нормировка
// Блокировка UMin1
// if(isActivCmdLed(BLOCK_UMIN1_DI_OEPRF_ONB, numLed))//проверка активности команды на Реле
  //    SetCmdToUVV(APV_COMP1,  1, IOCMD3_UMM, nLed);//отранж 
}// SettingIci_RangirAPVToLed(int nLed)
