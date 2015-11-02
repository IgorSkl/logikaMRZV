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
/*
//CMD_POL_VV
#define IOCMD1_PRM1 0
//Неиспр цепей напряжения ДЗ
//CMD_FAILU_COMMON
#define IOCMD2_PRM1 1
//откл ВВ
//CMD_OTKL_VV
#define IOCMD3_PRM1 2
//CMD_BO
//Работа БО
#define IOCMD4_PRM1 3
//CMD_BV
//Работа БB
#define IOCMD5_PRM1 4
//TEST
#define IOCMD6_PRM1 5
//вкл ВВ
//CMD_VKL_VV
#define IOCMD7_PRM1 6

//Контроль Вкл
#define IOCMD8_PRM1 7
//Контроль Откл
#define IOCMD9_PRM1 8

//Сбос реле
#define IOCMD10_PRM1 9
//Сброс индикации
#define IOCMD11_PRM1 10

//Блокировка включения ВВ
#define IOCMD12_PRM1  11
//РазБлокировка включения ВВ
#define IOCMD13_PRM1  12

*/

void SettingIci_RangirPRM1ToDV(int nDV)
{
  int numDV = nDV - DV1_SM;//нормировка
      // Положение ВВ (выключателя)
  if(isActivCmdDV(SWITCH_STATE_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD1_PRM1, nDV);//отранж CMD_POL_VV на ДВ

// Откл. ВВ 
  if(isActivCmdDV(HVSW_OFF_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD3_PRM1, nDV);//отранж CMD_OTKL_VV на ДВ

//вкл ВВ
  if(isActivCmdDV(HVSW_ON_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD7_PRM1, nDV);//отранж  на ДВ

//Контроль Вкл
  if(isActivCmdDV(CTRL_VKL_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD8_PRM1, nDV);//отранж  на ДВ
//Контроль Откл
  if(isActivCmdDV(CTRL_OTKL_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD9_PRM1, nDV);//отранж  на ДВ

// Сброс Реле	
  if(isActivCmdDV(RESET_SIGOUT_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD10_PRM1, nDV);//отранж  на ДВ
// Сброс индикаци
  if(isActivCmdDV(RESET_LED_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD11_PRM1, nDV);//отранж  на ДВ

// Блокировка включения ВВ
  if(isActivCmdDV(BLOCK_SWITCHOVER_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD12_PRM1, nDV);//отранж  на ДВ

// Разблокировка включения ВВ
  if(isActivCmdDV(PERMIT_BLK_SW_MCP_DI_IEPRF_ONB, numDV))
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD13_PRM1, nDV);//отранж  на ДВ

}//SettingIci_RangirPRM2DV(int nDV)
//CTRL_VKL_DI_IEPRF_ONB                ,// Контроль Вкл
//CTRL_OTKL_DI_IEPRF_ONB               ,// Контроль Откл

//RESET_SIGOUT_DI_IEPRF_ONB            ,// Сброс Реле	
//RESET_LED_DI_IEPRF_ONB               ,// Сброс индикаци
//BLOCK_SWITCHOVER_DI_IEPRF_ONB        ,// Блокировка включения ВВ
//SWITCH_STATE_DI_IEPRF_ONB            ,// Положение ВВ (выключателя)
//PERMIT_BLK_SW_MCP_DI_IEPRF_ONB       ,// Разблокировка включения ВВ

void SettingIci_RangirPRM1ToRele(int nRele)
{
//отранж PRM1 на Реле
int numRele = nRele - RELE1_SM;//нормировка

// Положение ВВ (выключателя)
  if(isActivCmdDV(SWITCH_STATE_DI_OEPRF_ONB, numRele))
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD1_PRM1, nRele);//отранж  на ДВ
// Неисправность цепйй напр ДистЗ
 if(isActivCmdRele(FLT_U_DSTP_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD2_PRM1, nRele);//отранж 

//вкл ВВ
  if(isActivCmdRele(HVSW_ON_DI_OEPRF_ONB, numRele))//проверка активности команды на 
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD7_PRM1, nRele);//отранж  на 
// Откл. ВВ 
  if(isActivCmdRele(HVSW_OFF_DI_OEPRF_ONB, numRele))//проверка активности команды на 
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD3_PRM1, nRele);//отранж CMD_OTKL_VV на 

//Работа БО
  if(isActivCmdRele(SW_OFF_CMDF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD4_PRM1, nRele);//отранж  на Rele
//Работа БB
  if(isActivCmdRele(SW_ON_CMDF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD5_PRM1, nRele);//отранж  на Rele

//Контроль Вкл
  if(isActivCmdRele(CTRL_VKL_DI_OEPRF_ONB, numRele))//проверка активности команды на 
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD8_PRM1, nRele);//отранж  на 
//Контроль Откл
  if(isActivCmdRele(CTRL_OTKL_DI_OEPRF_ONB, numRele))//проверка активности команды на 
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD9_PRM1, nRele);//отранж  на 

// Сброс Реле	
  if(isActivCmdRele(RESET_SIGOUT_DI_OEPRF_ONB, numRele))//проверка активности команды на 
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD10_PRM1, nRele);//отранж  на 
// Сброс индикаци
  if(isActivCmdDV(RESET_LED_DI_OEPRF_ONB, numRele))//проверка активности команды на 
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD11_PRM1, nRele);//отранж  на 

// Блокировка включения ВВ
  if(isActivCmdRele(BLOCK_SWITCHOVER_DI_OEPRF_ONB, numRele))//проверка активности команды на 
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD12_PRM1, nRele);//отранж  на 
// Разблокировка включения ВВ
  if(isActivCmdRele(PERMIT_BLK_SW_MCP_DI_OEPRF_ONB, numRele))
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD13_PRM1, nRele);//отранж  на 

//Привод ВВ
  if(isActivCmdRele(DRIVER_SW_DI_OEPRF_ONB, numRele))
      SetCmdToUVV(PRM1_COMP1,  1, IOCMD14_PRM1, nRele);//отранж  на 

}// SettingIci_RangirUMM2Rele(int nRele)

void SettingIci_RangirPRM1ToLed(int nLed)
{
//отранж DZ1 на СДИ
int numLed = nLed - CDI1_SM;//нормировка
// Блокировка UMin1
// if(isActivCmdLed(BLOCK_UMIN1_DI_OEPRF_ONB, numLed))//проверка активности команды на Реле
  //    SetCmdToUVV(UMM_COMP1,  1, IOCMD3_UMM, nLed);//отранж 

}// SettingIci_RangirPRM1ToRele(int nLed)
