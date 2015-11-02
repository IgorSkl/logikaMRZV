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
#include "TZNP1Component.c"

void SettingIci_RangirTZNP2DV(int nDV)
{
//отранж TZNP на ДВ
  int numDV = nDV - DV1_SM;//нормировка
//Стат блок ТЗНП1
  if(isActivCmdDV(BLOCK_TZNP1_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD1_TZNP1to5, nDV);//отранж
//Блок уск ТЗНП1
 if(isActivCmdDV(BLOCK_ACCLT_TZNP1_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(TZNP_COMP1,  1, IOCMD2_TZNP1to5, nDV);//отранж
//Опер уск ТЗНП1
  if(isActivCmdDV(ACCLT_TZNP1_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD3_TZNP1to5, nDV);//отранж

//Стат блок ТЗНП2
  if(isActivCmdDV(BLOCK_TZNP2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD1_TZNP1to5, nDV);//отранж
//Блок уск ТЗНП2
 if(isActivCmdDV(BLOCK_ACCLT_TZNP2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(TZNP_COMP1,  2, IOCMD2_TZNP1to5, nDV);//отранж
//Опер уск ТЗНП2
  if(isActivCmdDV(ACCLT_TZNP2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD3_TZNP1to5, nDV);//отранж

//Стат блок ТЗНП3
  if(isActivCmdDV(BLOCK_TZNP3_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD1_TZNP1to5, nDV);//отранж
//Блок уск ТЗНП3
 if(isActivCmdDV(BLOCK_ACCLT_TZNP3_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(TZNP_COMP1,  3, IOCMD2_TZNP1to5, nDV);//отранж
//Опер уск ТЗНП3
  if(isActivCmdDV(ACCLT_TZNP3_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD3_TZNP1to5, nDV);//отранж

//Стат блок ТЗНП4
  if(isActivCmdDV(BLOCK_TZNP4_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD1_TZNP1to5, nDV);//отранж
//Блок уск ТЗНП4
 if(isActivCmdDV(BLOCK_ACCLT_TZNP4_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(TZNP_COMP1,  4, IOCMD2_TZNP1to5, nDV);//отранж
//Опер уск ТЗНП4
  if(isActivCmdDV(ACCLT_TZNP4_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD3_TZNP1to5, nDV);//отранж

//Стат блок ТЗНП5
  if(isActivCmdDV(BLOCK_TZNP5_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD1_TZNP1to5, nDV);//отранж
//Блок уск ТЗНП5
 if(isActivCmdDV(BLOCK_ACCLT_TZNP5_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(TZNP_COMP1,  5, IOCMD2_TZNP1to5, nDV);//отранж
//Опер уск ТЗНП5
  if(isActivCmdDV(ACCLT_TZNP5_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD3_TZNP1to5, nDV);//отранж
}// SettingIci_RangirTZNP2DV(int nDV)

void SettingIci_RangirTZNP2Rele(int nRele)
{
//отранж TZNP на Реле
  int numRele = nRele - RELE1_SM;//нормировка
//Стат блок ТЗНП1
  if(isActivCmdRele(BLOCK_TZNP1_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD1_TZNP1to5, nRele);//отранж
//Блок уск ТЗНП1
// if(isActivCmdDV(, numRele))//проверка активности команды на ДВ
//      SetCmdToUVV(TZNP_COMP1,  1, IOCMD2_TZNP1to5, nRele);//отранж
//Опер уск ТЗНП1
  if(isActivCmdRele(ACCLT_TZNP1_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD3_TZNP1to5, nRele);//отранж
//Сраб ПО ТЗНП1
  if(isActivCmdRele(STPDEV_TZNP1_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD4_TZNP1to5, nRele);//отранж
//Сраб ТЗНП1
  if(isActivCmdRele(TZNP1_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD5_TZNP1to5, nRele);//отранж
//Сраб ПО ТЗНП1 3I0
  if(isActivCmdRele(STPDEV_TZNP1_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD6_TZNP1to5, nRele);//отранж
//Сраб ТЗНП1 3I0
  if(isActivCmdRele(TZNP1_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD7_TZNP1to5, nRele);//отранж
//Сраб ПО ТЗНП1 3U0
  if(isActivCmdRele(STPDEV_TZNP1_3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD8_TZNP1to5, nRele);//отранж
//Сраб ТЗНП1 3U0
  if(isActivCmdRele(TZNP1__3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD9_TZNP1to5, nRele);//отранж

//Стат блок ТЗНП2
  if(isActivCmdRele(BLOCK_TZNP1_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD1_TZNP1to5, nRele);//отранж
//Блок уск ТЗНП2
// if(isActivCmdDV(, numRele))//проверка активности команды на ДВ
//      SetCmdToUVV(TZNP_COMP1,  2, IOCMD2_TZNP1to5, nRele);//отранж
//Опер уск ТЗНП2
  if(isActivCmdRele(ACCLT_TZNP2_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD3_TZNP1to5, nRele);//отранж
//Сраб ПО ТЗНП2
  if(isActivCmdRele(STPDEV_TZNP2_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD4_TZNP1to5, nRele);//отранж
//Сраб ТЗНП2
  if(isActivCmdRele(TZNP2_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD5_TZNP1to5, nRele);//отранж
//Сраб ПО ТЗНП2 3I0
  if(isActivCmdRele(STPDEV_TZNP2_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD6_TZNP1to5, nRele);//отранж
//Сраб ТЗНП2 3I0
  if(isActivCmdRele(TZNP2_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD7_TZNP1to5, nRele);//отранж
//Сраб ПО ТЗНП2 3U0
  if(isActivCmdRele(STPDEV_TZNP2_3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD8_TZNP1to5, nRele);//отранж
//Сраб ТЗНП2 3U0
  if(isActivCmdRele(TZNP2_3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD9_TZNP1to5, nRele);//отранж

//Стат блок ТЗНП3
  if(isActivCmdRele(BLOCK_TZNP3_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD1_TZNP1to5, nRele);//отранж
//Блок уск ТЗНП3
// if(isActivCmdDV(, numRele))//проверка активности команды на ДВ
//      SetCmdToUVV(TZNP_COMP1,  3, IOCMD2_TZNP1to5, nRele);//отранж
//Опер уск ТЗНП3
  if(isActivCmdRele(ACCLT_TZNP3_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD3_TZNP1to5, nRele);//отранж
//Сраб ПО ТЗНП3
  if(isActivCmdRele(STPDEV_TZNP3_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD4_TZNP1to5, nRele);//отранж
//Сраб ТЗНП3
  if(isActivCmdRele(TZNP3_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD5_TZNP1to5, nRele);//отранж
//Сраб ПО ТЗНП3 3I0
  if(isActivCmdRele(STPDEV_TZNP3_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD6_TZNP1to5, nRele);//отранж
//Сраб ТЗНП3 3I0
  if(isActivCmdRele(TZNP3_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD7_TZNP1to5, nRele);//отранж
//Сраб ПО ТЗНП3 3U0
  if(isActivCmdRele(STPDEV_TZNP3_3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD8_TZNP1to5, nRele);//отранж
//Сраб ТЗНП3 3U0
  if(isActivCmdRele(TZNP3_3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD9_TZNP1to5, nRele);//отранж

//Стат блок ТЗНП4
  if(isActivCmdRele(BLOCK_TZNP4_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD1_TZNP1to5, nRele);//отранж
//Блок уск ТЗНП4
// if(isActivCmdDV(, numRele))//проверка активности команды на ДВ
//      SetCmdToUVV(TZNP_COMP1,  4, IOCMD2_TZNP1to5, nRele);//отранж
//Опер уск ТЗНП4
  if(isActivCmdRele(ACCLT_TZNP4_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD3_TZNP1to5, nRele);//отранж
//Сраб ПО ТЗНП4
  if(isActivCmdRele(STPDEV_TZNP4_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD4_TZNP1to5, nRele);//отранж
//Сраб ТЗНП4
  if(isActivCmdRele(TZNP4_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD5_TZNP1to5, nRele);//отранж
//Сраб ПО ТЗНП4 3I0
  if(isActivCmdRele(STPDEV_TZNP4_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD6_TZNP1to5, nRele);//отранж
//Сраб ТЗНП4 3I0
  if(isActivCmdRele(TZNP4_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD7_TZNP1to5, nRele);//отранж
//Сраб ПО ТЗНП4 3U0
  if(isActivCmdRele(STPDEV_TZNP4_3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD8_TZNP1to5, nRele);//отранж
//Сраб ТЗНП4 3U0
  if(isActivCmdRele(TZNP4_3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD9_TZNP1to5, nRele);//отранж

//Стат блок ТЗНП5
  if(isActivCmdRele(BLOCK_TZNP5_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD1_TZNP1to5, nRele);//отранж
//Блок уск ТЗНП5
// if(isActivCmdDV(, numRele))//проверка активности команды на ДВ
//      SetCmdToUVV(TZNP_COMP1,  5, IOCMD2_TZNP1to5, nRele);//отранж
//Опер уск ТЗНП5
  if(isActivCmdRele(ACCLT_TZNP5_DI_OEPRF_ONB, numRele))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD3_TZNP1to5, nRele);//отранж
//Сраб ПО ТЗНП5
  if(isActivCmdRele(STPDEV_TZNP5_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD4_TZNP1to5, nRele);//отранж
//Сраб ТЗНП5
  if(isActivCmdRele(TZNP5_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD5_TZNP1to5, nRele);//отранж
//Сраб ПО ТЗНП5 3I0
  if(isActivCmdRele(STPDEV_TZNP5_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD6_TZNP1to5, nRele);//отранж
//Сраб ТЗНП5 3I0
  if(isActivCmdRele(TZNP5_3I0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD7_TZNP1to5, nRele);//отранж
//Сраб ПО ТЗНП5 3U0
  if(isActivCmdRele(STPDEV_TZNP5_3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD8_TZNP1to5, nRele);//отранж
//Сраб ТЗНП5 3U0
  if(isActivCmdRele(TZNP5_3U0_OEPRF_ONB, numRele))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD9_TZNP1to5, nRele);//отранж
}// SettingIci_RangirTZNP2Rele(int nRele)

void SettingIci_RangirTZNP2Led(int nLed)
{
//отранж TZNP на СДИ
  int numLed = nLed - CDI1_SM;//нормировка
//Стат блок ТЗНП1
  if(isActivCmdLed(BLOCK_TZNP1_DI_OEPRF_ONB, numLed))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD1_TZNP1to5, nLed);//отранж
//Блок уск ТЗНП1
// if(isActivCmdDV(, numLed))//проверка активности команды на ДВ
//      SetCmdToUVV(TZNP_COMP1,  1, IOCMD2_TZNP1to5, nLed);//отранж
//Опер уск ТЗНП1
  if(isActivCmdLed(ACCLT_TZNP1_DI_OEPRF_ONB, numLed))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD3_TZNP1to5, nLed);//отранж
//Сраб ПО ТЗНП1
  if(isActivCmdLed(STPDEV_TZNP1_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD4_TZNP1to5, nLed);//отранж
//Сраб ТЗНП1
  if(isActivCmdLed(TZNP1_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD5_TZNP1to5, nLed);//отранж
//Сраб ПО ТЗНП1 3I0
  if(isActivCmdLed(STPDEV_TZNP1_3I0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD6_TZNP1to5, nLed);//отранж
//Сраб ТЗНП1 3I0
  if(isActivCmdLed(TZNP1_3I0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD7_TZNP1to5, nLed);//отранж
//Сраб ПО ТЗНП1 3U0
  if(isActivCmdLed(STPDEV_TZNP1_3U0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD8_TZNP1to5, nLed);//отранж
//Сраб ТЗНП1 3U0
  if(isActivCmdLed(TZNP1__3U0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD9_TZNP1to5, nLed);//отранж

//Стат блок ТЗНП2
  if(isActivCmdLed(BLOCK_TZNP1_DI_OEPRF_ONB, numLed))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD1_TZNP1to5, nLed);//отранж
//Блок уск ТЗНП2
// if(isActivCmdDV(, numLed))//проверка активности команды на ДВ
//      SetCmdToUVV(TZNP_COMP1,  2, IOCMD2_TZNP1to5, nLed);//отранж
//Опер уск ТЗНП2
  if(isActivCmdLed(ACCLT_TZNP2_DI_OEPRF_ONB, numLed))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD3_TZNP1to5, nLed);//отранж
//Сраб ПО ТЗНП2
  if(isActivCmdLed(STPDEV_TZNP2_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD4_TZNP1to5, nLed);//отранж
//Сраб ТЗНП2
  if(isActivCmdLed(TZNP2_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD5_TZNP1to5, nLed);//отранж
//Сраб ПО ТЗНП2 3I0
  if(isActivCmdLed(STPDEV_TZNP2_3I0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD6_TZNP1to5, nLed);//отранж
//Сраб ТЗНП2 3I0
  if(isActivCmdLed(TZNP2_3I0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD7_TZNP1to5, nLed);//отранж
//Сраб ПО ТЗНП2 3U0
  if(isActivCmdLed(STPDEV_TZNP2_3U0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD8_TZNP1to5, nLed);//отранж
//Сраб ТЗНП2 3U0
  if(isActivCmdLed(TZNP2_3U0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD9_TZNP1to5, nLed);//отранж

//Стат блок ТЗНП3
  if(isActivCmdLed(BLOCK_TZNP3_DI_OEPRF_ONB, numLed))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD1_TZNP1to5, nLed);//отранж
//Блок уск ТЗНП3
// if(isActivCmdDV(, numLed))//проверка активности команды на ДВ
//      SetCmdToUVV(TZNP_COMP1,  3, IOCMD2_TZNP1to5, nLed);//отранж
//Опер уск ТЗНП3
  if(isActivCmdLed(ACCLT_TZNP3_DI_OEPRF_ONB, numLed))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD3_TZNP1to5, nLed);//отранж
//Сраб ПО ТЗНП3
  if(isActivCmdLed(STPDEV_TZNP3_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD4_TZNP1to5, nLed);//отранж
//Сраб ТЗНП3
  if(isActivCmdLed(TZNP3_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD5_TZNP1to5, nLed);//отранж
//Сраб ПО ТЗНП3 3I0
  if(isActivCmdLed(STPDEV_TZNP3_3I0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD6_TZNP1to5, nLed);//отранж
//Сраб ТЗНП3 3I0
  if(isActivCmdLed(TZNP3_3I0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD7_TZNP1to5, nLed);//отранж
//Сраб ПО ТЗНП3 3U0
  if(isActivCmdLed(STPDEV_TZNP3_3U0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD8_TZNP1to5, nLed);//отранж
//Сраб ТЗНП3 3U0
  if(isActivCmdLed(TZNP3_3U0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD9_TZNP1to5, nLed);//отранж

//Стат блок ТЗНП4
  if(isActivCmdLed(BLOCK_TZNP4_DI_OEPRF_ONB, numLed))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD1_TZNP1to5, nLed);//отранж
//Блок уск ТЗНП4
// if(isActivCmdDV(, numLed))//проверка активности команды на ДВ
//      SetCmdToUVV(TZNP_COMP1,  4, IOCMD2_TZNP1to5, nLed);//отранж
//Опер уск ТЗНП4
  if(isActivCmdLed(ACCLT_TZNP4_DI_OEPRF_ONB, numLed))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD3_TZNP1to5, nLed);//отранж
//Сраб ПО ТЗНП4
  if(isActivCmdLed(STPDEV_TZNP4_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD4_TZNP1to5, nLed);//отранж
//Сраб ТЗНП4
  if(isActivCmdLed(TZNP4_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD5_TZNP1to5, nLed);//отранж
//Сраб ПО ТЗНП4 3I0
  if(isActivCmdLed(STPDEV_TZNP4_3I0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD6_TZNP1to5, nLed);//отранж
//Сраб ТЗНП4 3I0
  if(isActivCmdLed(TZNP4_3I0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD7_TZNP1to5, nLed);//отранж
//Сраб ПО ТЗНП4 3U0
  if(isActivCmdLed(STPDEV_TZNP4_3U0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD8_TZNP1to5, nLed);//отранж
//Сраб ТЗНП4 3U0
  if(isActivCmdLed(TZNP4_3U0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD9_TZNP1to5, nLed);//отранж

//Стат блок ТЗНП5
  if(isActivCmdLed(BLOCK_TZNP5_DI_OEPRF_ONB, numLed))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD1_TZNP1to5, nLed);//отранж
//Блок уск ТЗНП5
// if(isActivCmdDV(, numLed))//проверка активности команды на ДВ
//      SetCmdToUVV(TZNP_COMP1,  5, IOCMD2_TZNP1to5, nLed);//отранж
//Опер уск ТЗНП5
  if(isActivCmdLed(ACCLT_TZNP5_DI_OEPRF_ONB, numLed))//проверка активности команды на ДВ
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD3_TZNP1to5, nLed);//отранж
//Сраб ПО ТЗНП5
  if(isActivCmdLed(STPDEV_TZNP5_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD4_TZNP1to5, nLed);//отранж
//Сраб ТЗНП5
  if(isActivCmdLed(TZNP5_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD5_TZNP1to5, nLed);//отранж
//Сраб ПО ТЗНП5 3I0
  if(isActivCmdLed(STPDEV_TZNP5_3I0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD6_TZNP1to5, nLed);//отранж
//Сраб ТЗНП5 3I0
  if(isActivCmdLed(TZNP5_3I0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD7_TZNP1to5, nLed);//отранж
//Сраб ПО ТЗНП5 3U0
  if(isActivCmdLed(STPDEV_TZNP5_3U0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD8_TZNP1to5, nLed);//отранж
//Сраб ТЗНП5 3U0
  if(isActivCmdLed(TZNP5_3U0_OEPRF_ONB, numLed))//проверка активности команды на Реле
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD9_TZNP1to5, nLed);//отранж
}// SettingIci_RangirTZNP2Led(int nLed)
