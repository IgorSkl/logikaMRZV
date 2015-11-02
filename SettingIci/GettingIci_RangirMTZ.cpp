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
#include "MTZ1Component.cpp"
#include "MTZ2Component.cpp"

void GettingIci_RangirMTZFromDV(int nDV)
{
//отранж МТЗ на ДВ
int numDV = nDV - DV1_SM;//нормировка
// Блокировка МТЗ1
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD1_MTZ1, nDV));//Проверить команду
//      setActivCmdDV(BLOCK_MCP1_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
// Блокировка МТЗ2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD1_MTZ2to5, nDV));//Проверить команду
//      setActivCmdDV(BLOCK_MCP2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
// Блокировка МТЗ3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD1_MTZ2to5, nDV));//Проверить команду
//      setActivCmdDV(BLOCK_MCP3_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
// Блокировка МТЗ4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD1_MTZ2to5, nDV));//Проверить команду
//      setActivCmdDV(BLOCK_MCP4_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
// Блокировка МТЗ5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD1_MTZ2to5, nDV));//Проверить команду
//      setActivCmdDV(BLOCK_MCP5_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ

//Оперативное ускорение МТЗ2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD3_MTZ2to5, nDV));//Проверить команду
//      setActivCmdDV(ACCLT_MCP2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Оперативное ускорение МТЗ3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD3_MTZ2to5, nDV));//Проверить команду
//      setActivCmdDV(ACCLT_MCP3_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Оперативное ускорение МТЗ4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD3_MTZ2to5, nDV));//Проверить команду
//      setActivCmdDV(ACCLT_MCP4_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Оперативное ускорение МТЗ5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD3_MTZ2to5, nDV));//Проверить команду
//      setActivCmdDV(ACCLT_MCP5_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ

}//GettingIci_RangirMTZFromDV()

void GettingIci_RangirMTZFromRele(int nRele)
{
//отранж МТЗ на Реле
int numRele = nRele - RELE1_SM;//нормировка
// Блокировка МТЗ1
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD1_MTZ1, nRele));//Проверить команду
//    setActivCmdRele(BLOCK_MCP1_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле

// Блокировка МТЗ2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD1_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(BLOCK_MCP2_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле
// Блокировка МТЗ3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD1_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(BLOCK_MCP3_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле
// Блокировка МТЗ4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD1_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(BLOCK_MCP4_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле
// Блокировка МТЗ5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD1_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(BLOCK_MCP5_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле

//Оперативное ускорение МТЗ2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD3_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(ACCLT_MCP2_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Оперативное ускорение МТЗ3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD3_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(ACCLT_MCP3_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Оперативное ускорение МТЗ4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD3_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(ACCLT_MCP4_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Оперативное ускорение МТЗ5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD3_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(ACCLT_MCP5_DI_OEPRF_ONB, numRele))//проверка активности команды на Реле

// ПО МТЗ1
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD2_MTZ1, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP1_BORING_OEPRF_ONB, numRele))//проверка активности команды на Реле
// ПО МТЗ1 ВПД
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD3_MTZ1, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP1_STAIGHT_OEPRF_ONB, numRele))//проверка активности команды на Реле
// ПО МТЗ1 НЗД
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD4_MTZ1, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP1_BACK_OEPRF_ONB, numRele))//проверка активности команды на Реле
// ПО МТЗ1 ПН
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD5_MTZ1, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP1_VLT_OEPRF_ONB, numRele))//проверка активности команды на Реле
// сраб МТЗ1
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD6_MTZ1, nRele));//Проверить команду
//    setActivCmdRele(MCP1_OEPRF_ONB, numRele))//проверка активности команды на Реле

// ПО МТЗ2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD4_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP2_BORING_OEPRF_ONB, numRele))//проверка активности команды на Реле
// ПО МТЗ2 ВПД
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD5_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP2_STAIGHT_OEPRF_ONB, numRele))//проверка активности команды на Реле
// ПО МТЗ2 НЗД
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD6_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP2_BACK_OEPRF_ONB, numRele))//проверка активности команды на Реле
// ПО МТЗ2 ПН
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD7_MTZ2to5, nRele));//отранж 
//    setActivCmdRele(STPDEV_MCP2_VLT_OEPRF_ONB, numRele))//проверка активности команды на Реле
// сраб МТЗ2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD8_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(MCP2_OEPRF_ONB, numRele))//проверка активности команды на Реле

// ПО МТЗ3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD4_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP3_BORING_OEPRF_ONB, numRele))//проверка активности команды на Реле
// ПО МТЗ3 ВПД
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD5_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP3_STAIGHT_OEPRF_ONB, numRele))//проверка активности команды на Реле
// ПО МТЗ3 НЗД
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD6_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP3_BACK_OEPRF_ONB, numRele))//проверка активности команды на Реле
// ПО МТЗ3 ПН
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD7_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP3_VLT_OEPRF_ONB, numRele))//проверка активности команды на Реле
// сраб МТЗ3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD8_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(MCP3_OEPRF_ONB, numRele))//проверка активности команды на Реле

// ПО МТЗ4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD4_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP4_BORING_OEPRF_ONB, numRele))//проверка активности команды на Реле
// ПО МТЗ4 ВПД
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD5_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP4_STAIGHT_OEPRF_ONB, numRele))//проверка активности команды на Реле
// ПО МТЗ4 НЗД
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD6_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP4_BACK_OEPRF_ONB, numRele))//проверка активности команды на Реле
// ПО МТЗ4 ПН
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD7_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP4_VLT_OEPRF_ONB, numRele))//проверка активности команды на Реле
// сраб МТЗ4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD8_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(MCP4_OEPRF_ONB, numRele))//проверка активности команды на Реле

// ПО МТЗ5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD4_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP5_BORING_OEPRF_ONB, numRele))//проверка активности команды на Реле
// ПО МТЗ5 ВПД
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD5_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP5_STAIGHT_OEPRF_ONB, numRele))//проверка активности команды на Реле
// ПО МТЗ5 НЗД
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD6_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP5_BACK_OEPRF_ONB, numRele))//проверка активности команды на Реле
// ПО МТЗ5 ПН
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD7_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(STPDEV_MCP5_VLT_OEPRF_ONB, numRele))//проверка активности команды на Реле
// сраб МТЗ5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD8_MTZ2to5, nRele));//Проверить команду
//    setActivCmdRele(MCP5_OEPRF_ONB, numRele))//проверка активности команды на Реле
}//GettingIci_RangirMTZFromRele(int nRele)

void GettingIci_RangirMTZFromLed(int nLed)
{
//отранж МТЗ на СДИ
int numLed = nLed - CDI1_SM;//нормировка
// Блокировка МТЗ1
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD1_MTZ1, nLed));//Проверить команду
//   setActivCmdLed(BLOCK_MCP1_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
// Блокировка МТЗ2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD1_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(BLOCK_MCP2_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
// Блокировка МТЗ3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD1_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(BLOCK_MCP3_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
// Блокировка МТЗ4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD1_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(BLOCK_MCP4_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
// Блокировка МТЗ5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD1_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(BLOCK_MCP5_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ

//Оперативное ускорение МТЗ2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD3_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(ACCLT_MCP2_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
//Оперативное ускорение МТЗ3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD3_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(ACCLT_MCP3_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
//Оперативное ускорение МТЗ4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD3_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(ACCLT_MCP4_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
//Оперативное ускорение МТЗ5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD3_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(ACCLT_MCP5_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ

// ПО МТЗ1
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD2_MTZ1, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP1_BORING_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ1 ВПД
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD3_MTZ1, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP1_STAIGHT_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ1 НЗД
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD4_MTZ1, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP1_BACK_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ1 ПН
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD5_MTZ1, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP1_VLT_OEPRF_ONB, numLed))//установка активной команды на СДИ
// сраб МТЗ1
 if(GetCmdUVVFromClon(MTZ_COMP1,  1, IOCMD6_MTZ1, nLed));//Проверить команду
//   setActivCmdLed(MCP1_OEPRF_ONB, numLed))//установка активной команды на СДИ

// ПО МТЗ2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD4_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP2_BORING_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ2 ВПД
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD5_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP2_STAIGHT_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ2 НЗД
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD6_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP2_BACK_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ2 ПН
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD7_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP2_VLT_OEPRF_ONB, numLed))//установка активной команды на СДИ
// сраб МТЗ2
 if(GetCmdUVVFromClon(MTZ_COMP1,  2, IOCMD8_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(MCP2_OEPRF_ONB, numLed))//установка активной команды на СДИ

// ПО МТЗ3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD4_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP3_BORING_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ3 ВПД
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD5_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP3_STAIGHT_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ3 НЗД
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD6_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP3_BACK_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ3 ПН
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD7_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP3_VLT_OEPRF_ONB, numLed))//установка активной команды на СДИ
// сраб МТЗ3
 if(GetCmdUVVFromClon(MTZ_COMP1,  3, IOCMD8_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(MCP3_OEPRF_ONB, numLed))//установка активной команды на СДИ

// ПО МТЗ4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD4_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP4_BORING_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ4 ВПД
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD5_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP4_STAIGHT_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ4 НЗД
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD6_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP4_BACK_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ4 ПН
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD7_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP4_VLT_OEPRF_ONB, numLed))//установка активной команды на СДИ
// сраб МТЗ4
 if(GetCmdUVVFromClon(MTZ_COMP1,  4, IOCMD8_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(MCP4_OEPRF_ONB, numLed))//установка активной команды на СДИ

// ПО МТЗ5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD4_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP5_BORING_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ5 ВПД
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD5_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP5_STAIGHT_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ5 НЗД
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD6_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP5_BACK_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО МТЗ5 ПН
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD7_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_MCP5_VLT_OEPRF_ONB, numLed))//установка активной команды на СДИ
// сраб МТЗ5
 if(GetCmdUVVFromClon(MTZ_COMP1,  5, IOCMD8_MTZ2to5, nLed));//Проверить команду
//   setActivCmdLed(MCP5_OEPRF_ONB, numLed))//установка активной команды на СДИ
}//GettingIci_RangirMTZFromLed(int nRele)
