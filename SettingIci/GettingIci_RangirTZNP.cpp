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
#include "TZNP1Component.cpp"

void GettingIci_RangirTZNPFromDV(int nDV)
{
//отранж TZNP на ДВ
  int numDV = nDV - DV1_SM;//нормировка
//Стат блок ТЗНП1
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD1_TZNP1to5, nDV));//отранж
//      setActivCmdDV(BLOCK_TZNP1_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Блок уск ТЗНП1
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD2_TZNP1to5, nDV));//отранж
//      setActivCmdDV(BLOCK_ACCLT_TZNP1_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Опер уск ТЗНП1
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD3_TZNP1to5, nDV));//отранж
//      setActivCmdDV(ACCLT_TZNP1_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ

//Стат блок ТЗНП2
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD1_TZNP1to5, nDV));//отранж
//      setActivCmdDV(BLOCK_TZNP2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Блок уск ТЗНП2
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD2_TZNP1to5, nDV));//отранж
//      setActivCmdDV(BLOCK_ACCLT_TZNP2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Опер уск ТЗНП2
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD3_TZNP1to5, nDV));//отранж
//      setActivCmdDV(ACCLT_TZNP2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ

//Стат блок ТЗНП3
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD1_TZNP1to5, nDV));//отранж
//      setActivCmdDV(BLOCK_TZNP3_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Блок уск ТЗНП3
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD2_TZNP1to5, nDV));//отранж
//      setActivCmdDV(BLOCK_ACCLT_TZNP3_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Опер уск ТЗНП3
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD3_TZNP1to5, nDV));//отранж
//      setActivCmdDV(ACCLT_TZNP3_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ

//Стат блок ТЗНП4
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD1_TZNP1to5, nDV));//отранж
//      setActivCmdDV(BLOCK_TZNP4_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Блок уск ТЗНП4
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD2_TZNP1to5, nDV));//отранж
//      setActivCmdDV(BLOCK_ACCLT_TZNP4_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Опер уск ТЗНП4
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD3_TZNP1to5, nDV));//отранж
//      setActivCmdDV(ACCLT_TZNP4_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ

//Стат блок ТЗНП5
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD1_TZNP1to5, nDV));//отранж
//      setActivCmdDV(BLOCK_TZNP5_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Блок уск ТЗНП5
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD2_TZNP1to5, nDV));//отранж
//      setActivCmdDV(BLOCK_ACCLT_TZNP5_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
//Опер уск ТЗНП5
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD3_TZNP1to5, nDV));//отранж
//      setActivCmdDV(ACCLT_TZNP5_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
}// SettingIci_RangirTZNP2DV(int nDV)

void GettingIci_RangirTZNPFromRele(int nRele)
{
//отранж TZNP на Реле
  int numRele = nRele - RELE1_SM;//нормировка
//Стат блок ТЗНП1
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD1_TZNP1to5, nRele));//отранж
//    setActivCmdRele(BLOCK_TZNP1_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
//Блок уск ТЗНП1
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD2_TZNP1to5, nRele));//отранж
//    setActivCmdRele(, numRele))//проверка активности команды на ДВ
//Опер уск ТЗНП1
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD3_TZNP1to5, nRele));//отранж
//    setActivCmdRele(ACCLT_TZNP1_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
//Сраб ПО ТЗНП1
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD4_TZNP1to5, nRele));//отранж
//    setActivCmdRele(STPDEV_TZNP1_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ТЗНП1
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD5_TZNP1to5, nRele));//отранж
//    setActivCmdRele(TZNP1_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ПО ТЗНП1 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD6_TZNP1to5, nRele));//отранж
//    setActivCmdRele(STPDEV_TZNP1_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ТЗНП1 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD7_TZNP1to5, nRele));//отранж
//    setActivCmdRele(TZNP1_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ПО ТЗНП1 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD8_TZNP1to5, nRele));//отранж
//    setActivCmdRele(STPDEV_TZNP1_3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ТЗНП1 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD9_TZNP1to5, nRele));//отранж
//    setActivCmdRele(TZNP1__3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле

//Стат блок ТЗНП2
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD1_TZNP1to5, nRele));//отранж
//    setActivCmdRele(BLOCK_TZNP1_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
//Блок уск ТЗНП2
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD2_TZNP1to5, nRele));//отранж
//    setActivCmdRele(, numRele))//проверка активности команды на ДВ
//Опер уск ТЗНП2
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD3_TZNP1to5, nRele));//отранж
//    setActivCmdRele(ACCLT_TZNP2_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
//Сраб ПО ТЗНП2
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD4_TZNP1to5, nRele));//отранж
//    setActivCmdRele(STPDEV_TZNP2_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ТЗНП2
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD5_TZNP1to5, nRele));//отранж
//    setActivCmdRele(TZNP2_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ПО ТЗНП2 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD6_TZNP1to5, nRele));//отранж
//    setActivCmdRele(STPDEV_TZNP2_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ТЗНП2 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD7_TZNP1to5, nRele));//отранж
//    setActivCmdRele(TZNP2_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ПО ТЗНП2 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD8_TZNP1to5, nRele));//отранж
//    setActivCmdRele(STPDEV_TZNP2_3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ТЗНП2 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD9_TZNP1to5, nRele));//отранж
//    setActivCmdRele(TZNP2_3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле

//Стат блок ТЗНП3
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD1_TZNP1to5, nRele));//отранж
//    setActivCmdRele(BLOCK_TZNP3_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
//Блок уск ТЗНП3
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD2_TZNP1to5, nRele));//отранж
//    setActivCmdRele(, numRele))//проверка активности команды на ДВ
//Опер уск ТЗНП3
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD3_TZNP1to5, nRele));//отранж
//    setActivCmdRele(ACCLT_TZNP3_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
//Сраб ПО ТЗНП3
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD4_TZNP1to5, nRele));//отранж
//    setActivCmdRele(STPDEV_TZNP3_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ТЗНП3
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD5_TZNP1to5, nRele));//отранж
//    setActivCmdRele(TZNP3_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ПО ТЗНП3 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD6_TZNP1to5, nRele));//отранж
//    setActivCmdRele(STPDEV_TZNP3_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ТЗНП3 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD7_TZNP1to5, nRele));//отранж
//    setActivCmdRele(TZNP3_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ПО ТЗНП3 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD8_TZNP1to5, nRele));//отранж
//    setActivCmdRele(STPDEV_TZNP3_3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ТЗНП3 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD9_TZNP1to5, nRele));//отранж
//    setActivCmdRele(TZNP3_3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле

//Стат блок ТЗНП4
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD1_TZNP1to5, nRele));//отранж
//    setActivCmdRele(BLOCK_TZNP4_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
//Блок уск ТЗНП4
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD2_TZNP1to5, nRele));//отранж
//    setActivCmdRele(, numRele))//проверка активности команды на ДВ
//Опер уск ТЗНП4
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD3_TZNP1to5, nRele));//отранж
//    setActivCmdRele(ACCLT_TZNP4_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
//Сраб ПО ТЗНП4
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD4_TZNP1to5, nRele));//отранж
//    setActivCmdRele(STPDEV_TZNP4_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ТЗНП4
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD5_TZNP1to5, nRele));//отранж
//    setActivCmdRele(TZNP4_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ПО ТЗНП4 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD6_TZNP1to5, nRele));//отранж
//    setActivCmdRele(STPDEV_TZNP4_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ТЗНП4 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD7_TZNP1to5, nRele));//отранж
//    setActivCmdRele(TZNP4_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ПО ТЗНП4 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD8_TZNP1to5, nRele));//отранж
//    setActivCmdRele(STPDEV_TZNP4_3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ТЗНП4 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD9_TZNP1to5, nRele));//отранж
//    setActivCmdRele(TZNP4_3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле

//Стат блок ТЗНП5
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD1_TZNP1to5, nRele));//отранж
//    setActivCmdRele(BLOCK_TZNP5_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
//Блок уск ТЗНП5
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD2_TZNP1to5, nRele));//отранж
//    setActivCmdRele(, numRele))//проверка активности команды на ДВ
//Опер уск ТЗНП5
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD3_TZNP1to5, nRele));//отранж
//    setActivCmdRele(ACCLT_TZNP5_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
//Сраб ПО ТЗНП5
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD4_TZNP1to5, nRele));//отранж
//    setActivCmdRele(STPDEV_TZNP5_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ТЗНП5
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD5_TZNP1to5, nRele));//отранж
//    setActivCmdRele(TZNP5_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ПО ТЗНП5 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD6_TZNP1to5, nRele));//отранж
//    setActivCmdRele(STPDEV_TZNP5_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ТЗНП5 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD7_TZNP1to5, nRele));//отранж
//    setActivCmdRele(TZNP5_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ПО ТЗНП5 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD8_TZNP1to5, nRele));//отранж
//    setActivCmdRele(STPDEV_TZNP5_3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле
//Сраб ТЗНП5 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD8_TZNP1to5, nRele));//отранж
//    setActivCmdRele(TZNP5_3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле
}//void GettingIci_RangirTZNPFromRele(int nRele)

void GettingIci_RangirTZNPFromLed(int nLed)
{
//отранж TZNP на СДИ
  int numLed = nLed - CDI1_SM;//нормировка
//Стат блок ТЗНП1
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD1_TZNP1to5, nLed));//отранж
//   setActivCmdLed(BLOCK_TZNP1_DI_OEPRF_ONB, numLed))//проверка активности команды на 
//Блок уск ТЗНП1
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD2_TZNP1to5, nLed));//отранж
//   setActivCmdLed(, numLed))//проверка активности команды на ДВ
//Опер уск ТЗНП1
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD3_TZNP1to5, nLed));//отранж
//   setActivCmdLed(ACCLT_TZNP1_DI_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ПО ТЗНП1
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD4_TZNP1to5, nLed));//отранж
//   setActivCmdLed(STPDEV_TZNP1_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ТЗНП1
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD5_TZNP1to5, nLed));//отранж
//   setActivCmdLed(TZNP1_OEPRF_ONB, numLed))//проверка активности команды на Реле
//Сраб ПО ТЗНП1 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD6_TZNP1to5, nLed));//отранж
//   setActivCmdLed(STPDEV_TZNP1_3I0_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ТЗНП1 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD7_TZNP1to5, nLed));//отранж
//   setActivCmdLed(TZNP1_3I0_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ПО ТЗНП1 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD8_TZNP1to5, nLed));//отранж
//   setActivCmdLed(STPDEV_TZNP1_3U0_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ТЗНП1 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  1, IOCMD9_TZNP1to5, nLed));//отранж
//   setActivCmdLed(TZNP1__3U0_OEPRF_ONB, numLed))//проверка активности команды на 

//Стат блок ТЗНП2
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD1_TZNP1to5, nLed));//отранж
//   setActivCmdLed(BLOCK_TZNP1_DI_OEPRF_ONB, numLed))//проверка активности команды на 
//Блок уск ТЗНП2
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD2_TZNP1to5, nLed));//отранж
//   setActivCmdLed(, numLed))//проверка активности команды на ДВ
//Опер уск ТЗНП2
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD3_TZNP1to5, nLed));//отранж
//   setActivCmdLed(ACCLT_TZNP2_DI_OEPRF_ONB, numLed))//проверка активности команды на
//Сраб ПО ТЗНП2
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD4_TZNP1to5, nLed));//отранж
//   setActivCmdLed(STPDEV_TZNP2_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ТЗНП2
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD5_TZNP1to5, nLed));//отранж
//   setActivCmdLed(TZNP2_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ПО ТЗНП2 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD6_TZNP1to5, nLed));//отранж
//   setActivCmdLed(STPDEV_TZNP2_3I0_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ТЗНП2 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD7_TZNP1to5, nLed));//отранж
//   setActivCmdLed(TZNP2_3I0_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ПО ТЗНП2 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD8_TZNP1to5, nLed));//отранж
//   setActivCmdLed(STPDEV_TZNP2_3U0_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ТЗНП2 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  2, IOCMD9_TZNP1to5, nLed));//отранж
//   setActivCmdLed(TZNP2_3U0_OEPRF_ONB, numLed))//проверка активности команды на 

//Стат блок ТЗНП3
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD1_TZNP1to5, nLed));//отранж
//   setActivCmdLed(BLOCK_TZNP3_DI_OEPRF_ONB, numLed))//проверка активности команды на
//Блок уск ТЗНП3
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD2_TZNP1to5, nLed));//отранж
//   setActivCmdLed(, numLed))//проверка активности команды на ДВ
//Опер уск ТЗНП3
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD3_TZNP1to5, nLed));//отранж
//   setActivCmdLed(ACCLT_TZNP3_DI_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ПО ТЗНП3
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD4_TZNP1to5, nLed));//отранж
//   setActivCmdLed(STPDEV_TZNP3_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ТЗНП3
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD5_TZNP1to5, nLed));//отранж
//   setActivCmdLed(TZNP3_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ПО ТЗНП3 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD6_TZNP1to5, nLed));//отранж
//   setActivCmdLed(STPDEV_TZNP3_3I0_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ТЗНП3 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD7_TZNP1to5, nLed));//отранж
//   setActivCmdLed(TZNP3_3I0_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ПО ТЗНП3 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD8_TZNP1to5, nLed));//отранж
//   setActivCmdLed(STPDEV_TZNP3_3U0_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ТЗНП3 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  3, IOCMD9_TZNP1to5, nLed));//отранж
//   setActivCmdLed(TZNP3_3U0_OEPRF_ONB, numLed))//проверка активности команды на Реле

//Стат блок ТЗНП4
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD1_TZNP1to5, nLed));//отранж
//   setActivCmdLed(BLOCK_TZNP4_DI_OEPRF_ONB, numLed))//проверка активности команды на 
//Блок уск ТЗНП4
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD2_TZNP1to5, nLed));//отранж
//   setActivCmdLed(, numLed))//проверка активности команды на 
//Опер уск ТЗНП4
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD3_TZNP1to5, nLed));//отранж
//   setActivCmdLed(ACCLT_TZNP4_DI_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ПО ТЗНП4
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD4_TZNP1to5, nLed));//отранж
//   setActivCmdLed(STPDEV_TZNP4_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ТЗНП4
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD5_TZNP1to5, nLed));//отранж
//   setActivCmdLed(TZNP4_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ПО ТЗНП4 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD6_TZNP1to5, nLed));//отранж
//   setActivCmdLed(STPDEV_TZNP4_3I0_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ТЗНП4 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD7_TZNP1to5, nLed));//отранж
//   setActivCmdLed(TZNP4_3I0_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ПО ТЗНП4 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD8_TZNP1to5, nLed));//отранж
//   setActivCmdLed(STPDEV_TZNP4_3U0_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ТЗНП4 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  4, IOCMD9_TZNP1to5, nLed));//отранж
//   setActivCmdLed(TZNP4_3U0_OEPRF_ONB, numLed))//проверка активности команды на 

//Стат блок ТЗНП5
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD1_TZNP1to5, nLed));//отранж
//   setActivCmdLed(BLOCK_TZNP5_DI_OEPRF_ONB, numLed))//проверка активности команды на 
//Блок уск ТЗНП5
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD2_TZNP1to5, nLed));//отранж
//   setActivCmdLed(, numLed))//проверка активности команды на ДВ
//Опер уск ТЗНП5
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD3_TZNP1to5, nLed));//отранж
//   setActivCmdLed(ACCLT_TZNP5_DI_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ПО ТЗНП5
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD4_TZNP1to5, nLed));//отранж
//   setActivCmdLed(STPDEV_TZNP5_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ТЗНП5
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD5_TZNP1to5, nLed));//отранж
//   setActivCmdLed(TZNP5_OEPRF_ONB, numLed))//проверка активности команды на
//Сраб ПО ТЗНП5 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD6_TZNP1to5, nLed));//отранж
//   setActivCmdLed(STPDEV_TZNP5_3I0_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ТЗНП5 3I0
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD7_TZNP1to5, nLed));//отранж
//   setActivCmdLed(TZNP5_3I0_OEPRF_ONB, numLed))//проверка активности команды на Реле
//Сраб ПО ТЗНП5 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD8_TZNP1to5, nLed));//отранж
//   setActivCmdLed(STPDEV_TZNP5_3U0_OEPRF_ONB, numLed))//проверка активности команды на 
//Сраб ТЗНП5 3U0
 if(GetCmdUVVFromClon(TZNP_COMP1,  5, IOCMD9_TZNP1to5, nLed));//отранж
//   setActivCmdLed(TZNP5_3U0_OEPRF_ONB, numLed))//проверка активности команды на 
}// SettingIci_RangirTZNP2Led(int nLed)
