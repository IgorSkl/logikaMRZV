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
#include "MTZ1Component.c"
#include "MTZ2Component.c"

void SettingIci_RangirMTZ2DV(int nDV)
{
//отранж МТЗ на ДВ
int numDV = nDV - DV1_SM;//нормировка
// Блокировка МТЗ1
 if(isActivCmdDV(BLOCK_MCP1_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(MTZ_COMP1,  1, IOCMD1_MTZ1, nDV);//отранж 
// Блокировка МТЗ2
 if(isActivCmdDV(BLOCK_MCP2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(MTZ_COMP1,  2, IOCMD1_MTZ2to5, nDV);//отранж  
// Блокировка МТЗ3
 if(isActivCmdDV(BLOCK_MCP3_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(MTZ_COMP1,  3, IOCMD1_MTZ2to5, nDV);//отранж  
// Блокировка МТЗ4
 if(isActivCmdDV(BLOCK_MCP4_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(MTZ_COMP1,  4, IOCMD1_MTZ2to5, nDV);//отранж 
// Блокировка МТЗ5
 if(isActivCmdDV(BLOCK_MCP5_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(MTZ_COMP1,  5, IOCMD1_MTZ2to5, nDV);//отранж 

//Оперативное ускорение МТЗ2
 if(isActivCmdDV(ACCLT_MCP2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(MTZ_COMP1,  2, IOCMD3_MTZ2to5, nDV);//отранж 
//Оперативное ускорение МТЗ3
 if(isActivCmdDV(ACCLT_MCP3_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(MTZ_COMP1,  3, IOCMD3_MTZ2to5, nDV);//отранж 
//Оперативное ускорение МТЗ4
 if(isActivCmdDV(ACCLT_MCP4_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(MTZ_COMP1,  4, IOCMD3_MTZ2to5, nDV);//отранж 
//Оперативное ускорение МТЗ5
 if(isActivCmdDV(ACCLT_MCP5_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(MTZ_COMP1,  5, IOCMD3_MTZ2to5, nDV);//отранж 

}//SettingIci_RangirMTZ2DV()

void SettingIci_RangirMTZ2Rele(int nRele)
{
//отранж МТЗ на Реле
int numRele = nRele - RELE1_SM;//нормировка
// Блокировка МТЗ1
 if(isActivCmdRele(BLOCK_MCP1_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  1, IOCMD1_MTZ1, nRele);//отранж 
// Блокировка МТЗ2
 if(isActivCmdRele(BLOCK_MCP2_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  2, IOCMD1_MTZ2to5, nRele);//отранж  
// Блокировка МТЗ3
 if(isActivCmdRele(BLOCK_MCP3_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  3, IOCMD1_MTZ2to5, nRele);//отранж  
// Блокировка МТЗ4
 if(isActivCmdRele(BLOCK_MCP4_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  4, IOCMD1_MTZ2to5, nRele);//отранж 
// Блокировка МТЗ5
 if(isActivCmdRele(BLOCK_MCP5_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  5, IOCMD1_MTZ2to5, nRele);//отранж 

//Оперативное ускорение МТЗ2
 if(isActivCmdRele(ACCLT_MCP2_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  2, IOCMD3_MTZ2to5, nRele);//отранж 
//Оперативное ускорение МТЗ3
 if(isActivCmdRele(ACCLT_MCP3_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  3, IOCMD3_MTZ2to5, nRele);//отранж 
//Оперативное ускорение МТЗ4
 if(isActivCmdRele(ACCLT_MCP4_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  4, IOCMD3_MTZ2to5, nRele);//отранж 
//Оперативное ускорение МТЗ5
 if(isActivCmdRele(ACCLT_MCP5_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  5, IOCMD3_MTZ2to5, nRele);//отранж 

// ПО МТЗ1
 if(isActivCmdRele(STPDEV_MCP1_BORING_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  1, IOCMD2_MTZ1, nRele);//отранж 
// ПО МТЗ1 ВПД
 if(isActivCmdRele(STPDEV_MCP1_STAIGHT_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  1, IOCMD3_MTZ1, nRele);//отранж 
// ПО МТЗ1 НЗД
 if(isActivCmdRele(STPDEV_MCP1_BACK_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  1, IOCMD4_MTZ1, nRele);//отранж 
// ПО МТЗ1 ПН
 if(isActivCmdRele(STPDEV_MCP1_VLT_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  1, IOCMD5_MTZ1, nRele);//отранж 
// сраб МТЗ1
 if(isActivCmdRele(MCP1_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  1, IOCMD6_MTZ1, nRele);//отранж 

// ПО МТЗ2
 if(isActivCmdRele(STPDEV_MCP2_BORING_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  2, IOCMD4_MTZ2to5, nRele);//отранж 
// ПО МТЗ2 ВПД
 if(isActivCmdRele(STPDEV_MCP2_STAIGHT_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  2, IOCMD5_MTZ2to5, nRele);//отранж 
// ПО МТЗ2 НЗД
 if(isActivCmdRele(STPDEV_MCP2_BACK_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  2, IOCMD6_MTZ2to5, nRele);//отранж 
// ПО МТЗ2 ПН
 if(isActivCmdRele(STPDEV_MCP2_VLT_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  2, IOCMD7_MTZ2to5, nRele);//отранж 
// сраб МТЗ2
 if(isActivCmdRele(MCP2_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  2, IOCMD8_MTZ2to5, nRele);//отранж 

// ПО МТЗ3
 if(isActivCmdRele(STPDEV_MCP3_BORING_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  3, IOCMD4_MTZ2to5, nRele);//отранж 
// ПО МТЗ3 ВПД
 if(isActivCmdRele(STPDEV_MCP3_STAIGHT_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  3, IOCMD5_MTZ2to5, nRele);//отранж 
// ПО МТЗ3 НЗД
 if(isActivCmdRele(STPDEV_MCP3_BACK_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  3, IOCMD6_MTZ2to5, nRele);//отранж 
// ПО МТЗ3 ПН
 if(isActivCmdRele(STPDEV_MCP3_VLT_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  3, IOCMD7_MTZ2to5, nRele);//отранж 
// сраб МТЗ3
 if(isActivCmdRele(MCP3_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  3, IOCMD8_MTZ2to5, nRele);//отранж 

// ПО МТЗ4
 if(isActivCmdRele(STPDEV_MCP4_BORING_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  4, IOCMD4_MTZ2to5, nRele);//отранж 
// ПО МТЗ4 ВПД
 if(isActivCmdRele(STPDEV_MCP4_STAIGHT_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  4, IOCMD5_MTZ2to5, nRele);//отранж 
// ПО МТЗ4 НЗД
 if(isActivCmdRele(STPDEV_MCP4_BACK_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  4, IOCMD6_MTZ2to5, nRele);//отранж 
// ПО МТЗ4 ПН
 if(isActivCmdRele(STPDEV_MCP4_VLT_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  4, IOCMD7_MTZ2to5, nRele);//отранж 
// сраб МТЗ4
 if(isActivCmdRele(MCP4_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  4, IOCMD8_MTZ2to5, nRele);//отранж 

// ПО МТЗ5
 if(isActivCmdRele(STPDEV_MCP5_BORING_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  5, IOCMD4_MTZ2to5, nRele);//отранж 
// ПО МТЗ5 ВПД
 if(isActivCmdRele(STPDEV_MCP5_STAIGHT_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  5, IOCMD5_MTZ2to5, nRele);//отранж 
// ПО МТЗ5 НЗД
 if(isActivCmdRele(STPDEV_MCP5_BACK_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  5, IOCMD6_MTZ2to5, nRele);//отранж 
// ПО МТЗ5 ПН
 if(isActivCmdRele(STPDEV_MCP5_VLT_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  5, IOCMD7_MTZ2to5, nRele);//отранж 
// сраб МТЗ5
 if(isActivCmdRele(MCP5_OEPRF_ONB, numRele))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  5, IOCMD8_MTZ2to5, nRele);//отранж 
}//SettingIci_RangirMTZ2Rele(int nRele)

void SettingIci_RangirMTZ2Led(int nLed)
{
//отранж МТЗ на СДИ
int numLed = nLed - CDI1_SM;//нормировка
// Блокировка МТЗ1
 if(isActivCmdLed(BLOCK_MCP1_DI_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  1, IOCMD1_MTZ1, nLed);//отранж 
// Блокировка МТЗ2
 if(isActivCmdLed(BLOCK_MCP2_DI_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  2, IOCMD1_MTZ2to5, nLed);//отранж  
// Блокировка МТЗ3
 if(isActivCmdLed(BLOCK_MCP3_DI_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  3, IOCMD1_MTZ2to5, nLed);//отранж  
// Блокировка МТЗ4
 if(isActivCmdLed(BLOCK_MCP4_DI_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  4, IOCMD1_MTZ2to5, nLed);//отранж 
// Блокировка МТЗ5
 if(isActivCmdLed(BLOCK_MCP5_DI_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  5, IOCMD1_MTZ2to5, nLed);//отранж 

//Оперативное ускорение МТЗ2
 if(isActivCmdLed(ACCLT_MCP2_DI_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  2, IOCMD3_MTZ2to5, nLed);//отранж 
//Оперативное ускорение МТЗ3
 if(isActivCmdLed(ACCLT_MCP3_DI_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  3, IOCMD3_MTZ2to5, nLed);//отранж 
//Оперативное ускорение МТЗ4
 if(isActivCmdLed(ACCLT_MCP4_DI_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  4, IOCMD3_MTZ2to5, nLed);//отранж 
//Оперативное ускорение МТЗ5
 if(isActivCmdLed(ACCLT_MCP5_DI_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  5, IOCMD3_MTZ2to5, nLed);//отранж 

// ПО МТЗ1
 if(isActivCmdLed(STPDEV_MCP1_BORING_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  1, IOCMD2_MTZ1, nLed);//отранж 
// ПО МТЗ1 ВПД
 if(isActivCmdLed(STPDEV_MCP1_STAIGHT_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  1, IOCMD3_MTZ1, nLed);//отранж 
// ПО МТЗ1 НЗД
 if(isActivCmdLed(STPDEV_MCP1_BACK_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  1, IOCMD4_MTZ1, nLed);//отранж 
// ПО МТЗ1 ПН
 if(isActivCmdLed(STPDEV_MCP1_VLT_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  1, IOCMD5_MTZ1, nLed);//отранж 
// сраб МТЗ1
 if(isActivCmdLed(MCP1_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  1, IOCMD6_MTZ1, nLed);//отранж 

// ПО МТЗ2
 if(isActivCmdLed(STPDEV_MCP2_BORING_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  2, IOCMD4_MTZ2to5, nLed);//отранж 
// ПО МТЗ2 ВПД
 if(isActivCmdLed(STPDEV_MCP2_STAIGHT_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  2, IOCMD5_MTZ2to5, nLed);//отранж 
// ПО МТЗ2 НЗД
 if(isActivCmdLed(STPDEV_MCP2_BACK_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  2, IOCMD6_MTZ2to5, nLed);//отранж 
// ПО МТЗ2 ПН
 if(isActivCmdLed(STPDEV_MCP2_VLT_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  2, IOCMD7_MTZ2to5, nLed);//отранж 
// сраб МТЗ2
 if(isActivCmdLed(MCP2_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  2, IOCMD8_MTZ2to5, nLed);//отранж 

// ПО МТЗ3
 if(isActivCmdLed(STPDEV_MCP3_BORING_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  3, IOCMD4_MTZ2to5, nLed);//отранж 
// ПО МТЗ3 ВПД
 if(isActivCmdLed(STPDEV_MCP3_STAIGHT_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  3, IOCMD5_MTZ2to5, nLed);//отранж 
// ПО МТЗ3 НЗД
 if(isActivCmdLed(STPDEV_MCP3_BACK_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  3, IOCMD6_MTZ2to5, nLed);//отранж 
// ПО МТЗ3 ПН
 if(isActivCmdLed(STPDEV_MCP3_VLT_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  3, IOCMD7_MTZ2to5, nLed);//отранж 
// сраб МТЗ3
 if(isActivCmdLed(MCP3_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  3, IOCMD8_MTZ2to5, nLed);//отранж 

// ПО МТЗ4
 if(isActivCmdLed(STPDEV_MCP4_BORING_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  4, IOCMD4_MTZ2to5, nLed);//отранж 
// ПО МТЗ4 ВПД
 if(isActivCmdLed(STPDEV_MCP4_STAIGHT_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  4, IOCMD5_MTZ2to5, nLed);//отранж 
// ПО МТЗ4 НЗД
 if(isActivCmdLed(STPDEV_MCP4_BACK_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  4, IOCMD6_MTZ2to5, nLed);//отранж 
// ПО МТЗ4 ПН
 if(isActivCmdLed(STPDEV_MCP4_VLT_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  4, IOCMD7_MTZ2to5, nLed);//отранж 
// сраб МТЗ4
 if(isActivCmdLed(MCP4_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  4, IOCMD8_MTZ2to5, nLed);//отранж 

// ПО МТЗ5
 if(isActivCmdLed(STPDEV_MCP5_BORING_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  5, IOCMD4_MTZ2to5, nLed);//отранж 
// ПО МТЗ5 ВПД
 if(isActivCmdLed(STPDEV_MCP5_STAIGHT_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  5, IOCMD5_MTZ2to5, nLed);//отранж 
// ПО МТЗ5 НЗД
 if(isActivCmdLed(STPDEV_MCP5_BACK_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  5, IOCMD6_MTZ2to5, nLed);//отранж 
// ПО МТЗ5 ПН
 if(isActivCmdLed(STPDEV_MCP5_VLT_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  5, IOCMD7_MTZ2to5, nLed);//отранж 
// сраб МТЗ5
 if(isActivCmdLed(MCP5_OEPRF_ONB, numLed))//проверка активности команды на Реле
      SetCmdToUVV(MTZ_COMP1,  5, IOCMD8_MTZ2to5, nLed);//отранж 
}//SettingIci_RangirMTZ2Led(int nRele)
