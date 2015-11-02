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
#include "DZ1Component.c"
#include "DZ2Component.c"

void SettingIci_RangirDZToDV(int nDV)
{
//отранж DZ1 на ДВ
int numDV = nDV - DV1_SM;//нормировка
// Блокировка DZ1
 if(isActivCmdDV(BLOCK_DSTP1_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(DZ_COMP1,  1, IOCMD1_DZ1, nDV);//отранж 

// Блокировка DZ2
 if(isActivCmdDV(BLOCK_DSTP2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(DZ_COMP1,  2, IOCMD1_DZ2to5, nDV);//отранж 
//Блокировка ускор Дист З2
 if(isActivCmdDV(BLOCK_ACCLT_DSTP2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(DZ_COMP1,  2, IOCMD2_DZ2to5, nDV);//отранж 
//Оперативное ускорение Дист З2
 if(isActivCmdDV(ACCLT_DSTP2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(DZ_COMP1,  2, IOCMD3_DZ2to5, nDV);//отранж 

// Блокировка DZ3
 if(isActivCmdDV(BLOCK_DSTP3_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(DZ_COMP1,  3, IOCMD1_DZ2to5, nDV);//отранж 
//Блокировка ускор Дист З3
 if(isActivCmdDV(BLOCK_ACCLT_DSTP3_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(DZ_COMP1,  3, IOCMD2_DZ2to5, nDV);//отранж 
//Оперативное ускорение Дист З3
 if(isActivCmdDV(ACCLT_DSTP3_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(DZ_COMP1,  3, IOCMD3_DZ2to5, nDV);//отранж 

// Блокировка DZ4
 if(isActivCmdDV(BLOCK_DSTP4_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(DZ_COMP1,  4, IOCMD1_DZ2to5, nDV);//отранж 
//Блокировка ускор Дист З4
 if(isActivCmdDV(BLOCK_ACCLT_DSTP4_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(DZ_COMP1,  4, IOCMD2_DZ2to5, nDV);//отранж 
//Оперативное ускорение Дист З4
 if(isActivCmdDV(ACCLT_DSTP4_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(DZ_COMP1,  4, IOCMD3_DZ2to5, nDV);//отранж 

// Блокировка DZ5
 if(isActivCmdDV(BLOCK_DSTP5_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(DZ_COMP1,  5, IOCMD1_DZ2to5, nDV);//отранж 
//Блокировка ускор Дист З5
 if(isActivCmdDV(BLOCK_ACCLT_DSTP5_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(DZ_COMP1,  5, IOCMD2_DZ2to5, nDV);//отранж 
//Оперативное ускорение Дист З5
 if(isActivCmdDV(ACCLT_DSTP5_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(DZ_COMP1,  5, IOCMD3_DZ2to5, nDV);//отранж 

}// SettingIci_RangirDZ1ToDV(int nDV)

void SettingIci_RangirDZToRele(int nRele)
{
//отранж DZ1 на Реле
int numRele = nRele - RELE1_SM;//нормировка
// Блокировка DZ1
 if(isActivCmdRele(BLOCK_DSTP1_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  1, IOCMD1_DZ1, nRele);//отранж 
// ПО ДЗ1 МФ
 if(isActivCmdRele(STPDEV_DSTP1_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  1, IOCMD2_DZ1, nRele);//отранж 
// Cраб ДЗ1 МФ
 if(isActivCmdRele(DSTP1_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  1, IOCMD3_DZ1, nRele);//отранж 
// ПО МТЗ ДЗ1
 if(isActivCmdRele(STPDEV_MCP_DSTP1_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  1, IOCMD4_DZ1, nRele);//отранж 
// Сраб МТЗ ДЗ1
 if(isActivCmdRele(MCP_DSTP1_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  1, IOCMD5_DZ1, nRele);//отранж 
// ПО ДЗ1 ОФ
 if(isActivCmdRele(STPDEV_DSTP1_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  1, IOCMD6_DZ1, nRele);//отранж 
// сраб ДЗ1 ОФ
 if(isActivCmdRele(DSTP1_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  1, IOCMD7_DZ1, nRele);//отранж 

// Блокировка DZ2
 if(isActivCmdRele(BLOCK_DSTP2_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  2, IOCMD1_DZ2to5, nRele);//отранж 
//Блокировка ускор Дист З2
 if(isActivCmdRele(BLOCK_ACCLT_DSTP2_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  2, IOCMD2_DZ2to5, nRele);//отранж 
//Оперативное ускорение Дист З2
 if(isActivCmdRele(ACCLT_DSTP2_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  2, IOCMD3_DZ2to5, nRele);//отранж 
// ПО ДЗ2 МФ
 if(isActivCmdRele(STPDEV_DSTP2_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  2, IOCMD4_DZ2to5MF, nRele);//отранж 
// Cраб ДЗ2 МФ
 if(isActivCmdRele(DSTP2_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  2, IOCMD5_DZ2to5MF, nRele);//отранж 
// ПО МТЗ ДЗ2
 if(isActivCmdRele(STPDEV_MCP_DSTP2_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  2, IOCMD4_MDZ2to5MF, nRele);//отранж 
// Сраб МТЗ ДЗ2
 if(isActivCmdRele(MCP_DSTP2_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  2, IOCMD5_MDZ2to5MF, nRele);//отранж 
// ПО ДЗ2 ОФ
 if(isActivCmdRele(STPDEV_DSTP2_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  2, IOCMD4_DZ2to5OF, nRele);//отранж 
// сраб ДЗ2 ОФ
 if(isActivCmdRele(DSTP2_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  2, IOCMD5_DZ2to5OF, nRele);//отранж 


// Блокировка DZ3
 if(isActivCmdRele(BLOCK_DSTP3_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  3, IOCMD1_DZ2to5, nRele);//отранж 
//Блокировка ускор Дист З3
 if(isActivCmdRele(BLOCK_ACCLT_DSTP3_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  3, IOCMD2_DZ2to5, nRele);//отранж 
//Оперативное ускорение Дист З3
 if(isActivCmdRele(ACCLT_DSTP3_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  3, IOCMD3_DZ2to5, nRele);//отранж 
// ПО ДЗ3 МФ
 if(isActivCmdRele(STPDEV_DSTP3_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  3, IOCMD4_DZ2to5MF, nRele);//отранж 
// Cраб ДЗ3 МФ
 if(isActivCmdRele(DSTP3_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  3, IOCMD5_DZ2to5MF, nRele);//отранж 
// ПО МТЗ ДЗ3
 if(isActivCmdRele(STPDEV_MCP_DSTP3_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  3, IOCMD4_MDZ2to5MF, nRele);//отранж 
// Сраб МТЗ ДЗ3
 if(isActivCmdRele(MCP_DSTP3_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  3, IOCMD5_MDZ2to5MF, nRele);//отранж 
// ПО ДЗ3 ОФ
 if(isActivCmdRele(STPDEV_DSTP3_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  3, IOCMD4_DZ2to5OF, nRele);//отранж 
// сраб ДЗ3 ОФ
 if(isActivCmdRele(DSTP3_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  3, IOCMD5_DZ2to5OF, nRele);//отранж 

// Блокировка DZ4
 if(isActivCmdRele(BLOCK_DSTP4_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  4, IOCMD1_DZ2to5, nRele);//отранж 
//Блокировка ускор Дист З4
 if(isActivCmdRele(BLOCK_ACCLT_DSTP4_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  4, IOCMD2_DZ2to5, nRele);//отранж 
//Оперативное ускорение Дист З4
 if(isActivCmdRele(ACCLT_DSTP4_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  4, IOCMD3_DZ2to5, nRele);//отранж 
// ПО ДЗ4 МФ
 if(isActivCmdRele(STPDEV_DSTP4_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  4, IOCMD4_DZ2to5MF, nRele);//отранж 
// Cраб ДЗ4 МФ
 if(isActivCmdRele(DSTP4_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  4, IOCMD5_DZ2to5MF, nRele);//отранж 
// ПО МТЗ ДЗ4
 if(isActivCmdRele(STPDEV_MCP_DSTP4_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  4, IOCMD4_MDZ2to5MF, nRele);//отранж 
// Сраб МТЗ ДЗ4
 if(isActivCmdRele(MCP_DSTP4_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  4, IOCMD5_MDZ2to5MF, nRele);//отранж 
// ПО ДЗ4 ОФ
 if(isActivCmdRele(STPDEV_DSTP4_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  4, IOCMD4_DZ2to5OF, nRele);//отранж 
// сраб ДЗ4 ОФ
 if(isActivCmdRele(DSTP4_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  4, IOCMD5_DZ2to5OF, nRele);//отранж 

// Блокировка DZ5
 if(isActivCmdRele(BLOCK_DSTP5_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  5, IOCMD1_DZ2to5, nRele);//отранж 
//Блокировка ускор Дист З5
 if(isActivCmdRele(BLOCK_ACCLT_DSTP5_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  5, IOCMD2_DZ2to5, nRele);//отранж 
//Оперативное ускорение Дист З5
 if(isActivCmdRele(ACCLT_DSTP5_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  5, IOCMD3_DZ2to5, nRele);//отранж 
// ПО ДЗ5 МФ
 if(isActivCmdRele(STPDEV_DSTP5_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  5, IOCMD4_DZ2to5MF, nRele);//отранж 
// Cраб ДЗ5 МФ
 if(isActivCmdRele(DSTP5_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  5, IOCMD5_DZ2to5MF, nRele);//отранж 
// ПО МТЗ ДЗ5
 if(isActivCmdRele(STPDEV_MCP_DSTP5_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  5, IOCMD4_MDZ2to5MF, nRele);//отранж 
// Сраб МТЗ ДЗ5
 if(isActivCmdRele(MCP_DSTP5_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  5, IOCMD5_MDZ2to5MF, nRele);//отранж 
// ПО ДЗ5 ОФ
 if(isActivCmdRele(STPDEV_DSTP5_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  5, IOCMD4_DZ2to5OF, nRele);//отранж 
// сраб ДЗ5 ОФ
 if(isActivCmdRele(DSTP5_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(DZ_COMP1,  5, IOCMD5_DZ2to5OF, nRele);//отранж 

}// SettingIci_RangirUMM2Rele(int nRele)

void SettingIci_RangirDZToLed(int nLed)
{
//отранж DZ1 на СДИ
int numLed = nLed - CDI1_SM;//нормировка
// Блокировка UMin1
// if(isActivCmdLed(BLOCK_UMIN1_DI_OEPRF_ONB, numLed))//проверка активности команды на Реле
  //    SetCmdToUVV(UMM_COMP1,  1, IOCMD3_UMM, nLed);//отранж 

}// SettingIci_RangirUMM2Led(int nLed)
