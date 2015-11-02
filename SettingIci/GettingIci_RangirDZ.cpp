/*
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
*/

#include "bazisdef.h"
#include "psuperVisor\supermanager.h"

#include "component\componentdef.h"
#include "psuperVisor\psvisor_helpdef.h"

#include "psuperVisor\psvisor_helpfnc.h"
#include "virtualMenu\rangmanagerfnc.h"
#include "virtualmenu\systemmenufnc.h"
#include "SettingIci\SettingIci.h"

//#include "toSpeedOptim.h"
//#include "toSpeedDIS.h"

//#include "header.h"
//#include "ici_r_ef.h"

#define _HIDE_COMPONENT
#include "DZ1Component.cpp"
#include "DZ2Component.cpp"

void GettingIci_RangirDZFromDV(int nDV)
{
//отранж DZ1 на ДВ
int numDV = nDV - DV1_SM;//нормировка
// Блокировка DZ1
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD1_DZ1, nDV));//Проверить команду
//      setActivCmdDV(BLOCK_DSTP1_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ

// Блокировка DZ2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD1_DZ2to5, nDV));//Проверить команду
//      setActivCmdDV(BLOCK_DSTP2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Блокировка ускор Дист З2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD2_DZ2to5, nDV));//Проверить команду
//      setActivCmdDV(BLOCK_ACCLT_DSTP2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Оперативное ускорение Дист З2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD3_DZ2to5, nDV));//Проверить команду
//      setActivCmdDV(ACCLT_DSTP2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ

// Блокировка DZ3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD1_DZ2to5, nDV));//Проверить команду
//      setActivCmdDV(BLOCK_DSTP3_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Блокировка ускор Дист З3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD2_DZ2to5, nDV));//Проверить команду
//      setActivCmdDV(BLOCK_ACCLT_DSTP3_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Оперативное ускорение Дист З3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD3_DZ2to5, nDV));//Проверить команду
//      setActivCmdDV(ACCLT_DSTP3_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ

// Блокировка DZ4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD1_DZ2to5, nDV));//Проверить команду
//      setActivCmdDV(BLOCK_DSTP4_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Блокировка ускор Дист З4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD2_DZ2to5, nDV));//Проверить команду
//      setActivCmdDV(BLOCK_ACCLT_DSTP4_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Оперативное ускорение Дист З4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD3_DZ2to5, nDV));//Проверить команду
//      setActivCmdDV(ACCLT_DSTP4_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ

// Блокировка DZ5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD1_DZ2to5, nDV));//Проверить команду
//      setActivCmdDV(BLOCK_DSTP5_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Блокировка ускор Дист З5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD2_DZ2to5, nDV));//Проверить команду
//      setActivCmdDV(BLOCK_ACCLT_DSTP5_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Оперативное ускорение Дист З5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD3_DZ2to5, nDV));//Проверить команду
//      setActivCmdDV(ACCLT_DSTP5_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ

}//GettingIci_RangirDZFromDV(int nDV)

void GettingIci_RangirDZFromRele(int nRele)
{
//отранж DZ1 на Реле
int numRele = nRele - RELE1_SM;//нормировка
// Блокировка DZ1
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD1_DZ1, nRele));//Проверить команду
//    setActivCmdRele(BLOCK_DSTP1_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
// ПО ДЗ1 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD2_DZ1, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_DSTP1_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
// Cраб ДЗ1 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD3_DZ1, nRele));//Проверить команду
//    setActivCmdRele(DSTP1_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
// ПО МТЗ ДЗ1
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD4_DZ1, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP_DSTP1_OEPRF_ONB, numRele))//проверка активности команды на Rele
// Сраб МТЗ ДЗ1
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD5_DZ1, nRele));//Проверить команду
//    setActivCmdRele(MCP_DSTP1_OEPRF_ONB, numRele))//проверка активности команды на Rele
// ПО ДЗ1 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD6_DZ1, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_DSTP1_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele
// сраб ДЗ1 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD7_DZ1, nRele));//Проверить команду
//    setActivCmdRele(DSTP1_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele

// Блокировка DZ2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD1_DZ2to5, nRele));//Проверить команду
//    setActivCmdRele(BLOCK_DSTP2_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
//Блокировка ускор Дист З2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD2_DZ2to5, nRele));//Проверить команду
//    setActivCmdRele(BLOCK_ACCLT_DSTP2_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
//Оперативное ускорение Дист З2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD3_DZ2to5, nRele));//Проверить команду
//    setActivCmdRele(ACCLT_DSTP2_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
// ПО ДЗ2 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD4_DZ2to5MF, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_DSTP2_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
// Cраб ДЗ2 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD5_DZ2to5MF, nRele));//Проверить команду
//    setActivCmdRele(DSTP2_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
// ПО МТЗ ДЗ2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD4_MDZ2to5MF, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP_DSTP2_OEPRF_ONB, numRele))//проверка активности команды на Rele
// Сраб МТЗ ДЗ2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD5_MDZ2to5MF, nRele));//Проверить команду
//    setActivCmdRele(MCP_DSTP2_OEPRF_ONB, numRele))//проверка активности команды на Rele
// ПО ДЗ2 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD4_DZ2to5OF, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_DSTP2_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele
// сраб ДЗ2 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD5_DZ2to5OF, nRele));//Проверить команду
//    setActivCmdRele(DSTP2_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele


// Блокировка DZ3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD1_DZ2to5, nRele));//Проверить команду
//    setActivCmdRele(BLOCK_DSTP3_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
//Блокировка ускор Дист З3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD2_DZ2to5, nRele));//Проверить команду
//    setActivCmdRele(BLOCK_ACCLT_DSTP3_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
//Оперативное ускорение Дист З3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD3_DZ2to5, nRele));//Проверить команду
//    setActivCmdRele(ACCLT_DSTP3_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
// ПО ДЗ3 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD4_DZ2to5MF, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_DSTP3_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
// Cраб ДЗ3 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD5_DZ2to5MF, nRele));//Проверить команду
//    setActivCmdRele(DSTP3_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
// ПО МТЗ ДЗ3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD4_MDZ2to5MF, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP_DSTP3_OEPRF_ONB, numRele))//проверка активности команды на Rele
// Сраб МТЗ ДЗ3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD5_MDZ2to5MF, nRele));//Проверить команду
//    setActivCmdRele(MCP_DSTP3_OEPRF_ONB, numRele))//проверка активности команды на Rele
// ПО ДЗ3 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD4_DZ2to5OF, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_DSTP3_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele
// сраб ДЗ3 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD5_DZ2to5OF, nRele));//Проверить команду
//    setActivCmdRele(DSTP3_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele

// Блокировка DZ4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD1_DZ2to5, nRele));//Проверить команду
//    setActivCmdRele(BLOCK_DSTP4_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
//Блокировка ускор Дист З4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD2_DZ2to5, nRele));//Проверить команду
//    setActivCmdRele(BLOCK_ACCLT_DSTP4_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
//Оперативное ускорение Дист З4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD3_DZ2to5, nRele));//Проверить команду
//    setActivCmdRele(ACCLT_DSTP4_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
// ПО ДЗ4 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD4_DZ2to5MF, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_DSTP4_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
// Cраб ДЗ4 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD5_DZ2to5MF, nRele));//Проверить команду
//    setActivCmdRele(DSTP4_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
// ПО МТЗ ДЗ4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD4_MDZ2to5MF, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP_DSTP4_OEPRF_ONB, numRele))//проверка активности команды на Rele
// Сраб МТЗ ДЗ4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD5_MDZ2to5MF, nRele));//Проверить команду
//    setActivCmdRele(MCP_DSTP4_OEPRF_ONB, numRele))//проверка активности команды на Rele
// ПО ДЗ4 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD4_DZ2to5OF, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_DSTP4_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele
// сраб ДЗ4 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD5_DZ2to5OF, nRele));//Проверить команду
//    setActivCmdRele(DSTP4_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele

// Блокировка DZ5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD1_DZ2to5, nRele));//Проверить команду
//    setActivCmdRele(BLOCK_DSTP5_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
//Блокировка ускор Дист З5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD2_DZ2to5, nRele));//Проверить команду
//    setActivCmdRele(BLOCK_ACCLT_DSTP5_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
//Оперативное ускорение Дист З5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD3_DZ2to5, nRele));//Проверить команду
//    setActivCmdRele(ACCLT_DSTP5_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
// ПО ДЗ5 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD4_DZ2to5MF, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_DSTP5_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
// Cраб ДЗ5 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD5_DZ2to5MF, nRele));//Проверить команду
//    setActivCmdRele(DSTP5_MF_OEPRF_ONB, numRele))//проверка активности команды на Rele
// ПО МТЗ ДЗ5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD4_MDZ2to5MF, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP_DSTP5_OEPRF_ONB, numRele))//проверка активности команды на Rele
// Сраб МТЗ ДЗ5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD5_MDZ2to5MF, nRele));//Проверить команду
//    setActivCmdRele(MCP_DSTP5_OEPRF_ONB, numRele))//проверка активности команды на Rele
// ПО ДЗ5 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD4_DZ2to5OF, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_DSTP5_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele
// сраб ДЗ5 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD5_DZ2to5OF, nRele));//Проверить команду
//    setActivCmdRele(DSTP5_OF_OEPRF_ONB, numRele))//проверка активности команды на Rele

}//GettingIci_RangirDZFromRele(int nRele)

void GettingIci_RangirDZFromLed(int nLed)
{
//отранж DZ1 на СДИ
int numLed = nLed - CDI1_SM;//нормировка

// Блокировка DZ1
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD1_DZ1, nLed));//Проверить команду
//    setActivCmdLed(BLOCK_DSTP1_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО ДЗ1 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD2_DZ1, nLed));//Проверить команду
//    setActivCmdLed(STPDEV_DSTP1_MF_OEPRF_ONB, numLed))//установка активной команды на СДИ
// Cраб ДЗ1 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD3_DZ1, nLed));//Проверить команду
//    setActivCmdLed(DSTP1_MF_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ ДЗ1
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD4_DZ1, nLed));//Проверить команду
//    setActivCmdLed(STPDEV_MCP_DSTP1_OEPRF_ONB, numLed))//установка активной команды на СДИ
// Сраб МТЗ ДЗ1
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD5_DZ1, nLed));//Проверить команду
//    setActivCmdLed(MCP_DSTP1_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО ДЗ1 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD6_DZ1, nLed));//Проверить команду
//    setActivCmdLed(STPDEV_DSTP1_OF_OEPRF_ONB, numLed))//установка активной команды на СДИ
// сраб ДЗ1 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  1, IOCMD7_DZ1, nLed));//Проверить команду
//    setActivCmdLed(DSTP1_OF_OEPRF_ONB, numLed))//установка активной команды на СДИ

// Блокировка DZ2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD1_DZ2to5, nLed));//Проверить команду
//    setActivCmdLed(BLOCK_DSTP2_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
//Блокировка ускор Дист З2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD2_DZ2to5, nLed));//Проверить команду
//    setActivCmdLed(BLOCK_ACCLT_DSTP2_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
//Оперативное ускорение Дист З2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD3_DZ2to5, nLed));//Проверить команду
//    setActivCmdLed(ACCLT_DSTP2_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО ДЗ2 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD4_DZ2to5MF, nLed));//Проверить команду
//    setActivCmdLed(STPDEV_DSTP2_MF_OEPRF_ONB, numLed))//установка активной команды на СДИ
// Cраб ДЗ2 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD5_DZ2to5MF, nLed));//Проверить команду
//    setActivCmdLed(DSTP2_MF_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ ДЗ2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD4_MDZ2to5MF, nLed));//Проверить команду
//    setActivCmdLed(STPDEV_MCP_DSTP2_OEPRF_ONB, numLed))//установка активной команды на СДИ
// Сраб МТЗ ДЗ2
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD5_MDZ2to5MF, nLed));//Проверить команду
//    setActivCmdLed(MCP_DSTP2_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО ДЗ2 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD4_DZ2to5OF, nLed));//Проверить команду
//    setActivCmdLed(STPDEV_DSTP2_OF_OEPRF_ONB, numLed))//установка активной команды на СДИ
// сраб ДЗ2 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  2, IOCMD5_DZ2to5OF, nLed));//Проверить команду
//    setActivCmdLed(DSTP2_OF_OEPRF_ONB, numLed))//установка активной команды на СДИ


// Блокировка DZ3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD1_DZ2to5, nLed));//Проверить команду
//    setActivCmdLed(BLOCK_DSTP3_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
//Блокировка ускор Дист З3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD2_DZ2to5, nLed));//Проверить команду
//    setActivCmdLed(BLOCK_ACCLT_DSTP3_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
//Оперативное ускорение Дист З3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD3_DZ2to5, nLed));//Проверить команду
//    setActivCmdLed(ACCLT_DSTP3_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО ДЗ3 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD4_DZ2to5MF, nLed));//Проверить команду
//    setActivCmdLed(STPDEV_DSTP3_MF_OEPRF_ONB, numLed))//установка активной команды на СДИ
// Cраб ДЗ3 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD5_DZ2to5MF, nLed));//Проверить команду
//    setActivCmdLed(DSTP3_MF_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ ДЗ3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD4_MDZ2to5MF, nLed));//Проверить команду
//    setActivCmdLed(STPDEV_MCP_DSTP3_OEPRF_ONB, numLed))//установка активной команды на СДИ
// Сраб МТЗ ДЗ3
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD5_MDZ2to5MF, nLed));//Проверить команду
//    setActivCmdLed(MCP_DSTP3_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО ДЗ3 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD4_DZ2to5OF, nLed));//Проверить команду
//    setActivCmdLed(STPDEV_DSTP3_OF_OEPRF_ONB, numLed))//установка активной команды на СДИ
// сраб ДЗ3 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  3, IOCMD5_DZ2to5OF, nLed));//Проверить команду
//    setActivCmdLed(DSTP3_OF_OEPRF_ONB, numLed))//установка активной команды на СДИ

// Блокировка DZ4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD1_DZ2to5, nLed));//Проверить команду
//    setActivCmdLed(BLOCK_DSTP4_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
//Блокировка ускор Дист З4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD2_DZ2to5, nLed));//Проверить команду
//    setActivCmdLed(BLOCK_ACCLT_DSTP4_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
//Оперативное ускорение Дист З4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD3_DZ2to5, nLed));//Проверить команду
//    setActivCmdLed(ACCLT_DSTP4_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО ДЗ4 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD4_DZ2to5MF, nLed));//Проверить команду
//    setActivCmdLed(STPDEV_DSTP4_MF_OEPRF_ONB, numLed))//установка активной команды на СДИ
// Cраб ДЗ4 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD5_DZ2to5MF, nLed));//Проверить команду
//    setActivCmdLed(DSTP4_MF_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ ДЗ4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD4_MDZ2to5MF, nLed));//Проверить команду
//    setActivCmdLed(STPDEV_MCP_DSTP4_OEPRF_ONB, numLed))//установка активной команды на СДИ
// Сраб МТЗ ДЗ4
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD5_MDZ2to5MF, nLed));//Проверить команду
//    setActivCmdLed(MCP_DSTP4_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО ДЗ4 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD4_DZ2to5OF, nLed));//Проверить команду
//    setActivCmdLed(STPDEV_DSTP4_OF_OEPRF_ONB, numLed))//установка активной команды на СДИ
// сраб ДЗ4 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  4, IOCMD5_DZ2to5OF, nLed));//Проверить команду
//    setActivCmdLed(DSTP4_OF_OEPRF_ONB, numLed))//установка активной команды на СДИ

// Блокировка DZ5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD1_DZ2to5, nLed));//Проверить команду
//    setActivCmdLed(BLOCK_DSTP5_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
//Блокировка ускор Дист З5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD2_DZ2to5, nLed));//Проверить команду
//    setActivCmdLed(BLOCK_ACCLT_DSTP5_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
//Оперативное ускорение Дист З5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD3_DZ2to5, nLed));//Проверить команду
//    setActivCmdLed(ACCLT_DSTP5_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО ДЗ5 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD4_DZ2to5MF, nLed));//Проверить команду
//    setActivCmdLed(STPDEV_DSTP5_MF_OEPRF_ONB, numLed))//установка активной команды на СДИ
// Cраб ДЗ5 МФ
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD5_DZ2to5MF, nLed));//Проверить команду
//    setActivCmdLed(DSTP5_MF_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ ДЗ5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD4_MDZ2to5MF, nLed));//Проверить команду
//    setActivCmdLed(STPDEV_MCP_DSTP5_OEPRF_ONB, numLed))//установка активной команды на СДИ
// Сраб МТЗ ДЗ5
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD5_MDZ2to5MF, nLed));//Проверить команду
//    setActivCmdLed(MCP_DSTP5_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО ДЗ5 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD4_DZ2to5OF, nLed));//Проверить команду
//    setActivCmdLed(STPDEV_DSTP5_OF_OEPRF_ONB, numLed))//установка активной команды на СДИ
// сраб ДЗ5 ОФ
 if(GetCmdUVVFromClon(DZ_COMP1,  5, IOCMD5_DZ2to5OF, nLed));//Проверить команду
//    setActivCmdLed(DSTP5_OF_OEPRF_ONB, numLed))//установка активной команды на СДИ

}// SettingIci_RangirDZFromLed(int nLed)
