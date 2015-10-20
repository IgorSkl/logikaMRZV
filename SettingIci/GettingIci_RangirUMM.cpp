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
#include "UMMComponent.cpp"

void GettingIci_RangirUMMFromDV(int nDV)
{
//отранж UMM на ДВ
int numDV = nDV - DV1_SM;//нормировка

// Блокировка UMin1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD3_UMM, nDV))//Проверить команду
      setActivCmdDV(0, 0);//BLOCK_UMIN1_DI_IEPRF_ONB, numDV);//установка активной команды на ДВ
// Блокировка UMin2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD4_UMM, nDV))//отранж
      setActivCmdDV(0, 0);//BLOCK_UMIN2_DI_IEPRF_ONB, numDV))//установка активной команды на ДВ

// Блокировка UMax1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD1_UMM, nDV))//Проверить команду
            setActivCmdDV(0, 0);//, numDV))//установка активной команды на ДВ
// Блокировка UMax2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD2_UMM, nDV))//Проверить команду
           setActivCmdDV(0, 0);//, numDV))//установка активной команды на ДВ

}//GettingIci_RangirUMMFromDV(int nDV)

void GettingIci_RangirUMMFromRele(int nRele)
{
//отранж UMM на Реле
int numRele = nRele - RELE1_SM;//нормировка
// Блокировка UMin1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD3_UMM, nRele))//Проверить команду
    setActivCmdRele(0, 0);//BLOCK_UMIN1_DI_OEPRF_ONB, numRele))//установка активной команды на реле
// Блокировка UMin2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD4_UMM, nRele))//Проверить команду
    setActivCmdRele(0, 0);//BLOCK_UMIN2_DI_OEPRF_ONB, numRele))//установка активной команды на Реле
// ПО UMin1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD9_UMM, nRele))//Проверить команду
    setActivCmdRele(0, 0);//STPDEV_UMIN1_OEPRF_ONB, numRele))//установка активной команды на Реле
// UMin1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD10_UMM, nRele))//Проверить команду
   setActivCmdRele(0, 0);//UMIN1_OEPRF_ONB, numRele))//установка активной на Реле

// ПО UMin2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD11_UMM, nRele))//Проверить команду
    setActivCmdRele(0, 0);//STPDEV_UMIN2_OEPRF_ONB, numRele))//установка активной команды на Реле
// UMin2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD12_UMM, nRele))//Проверить команду
     setActivCmdRele(0, 0);//STPDEV_UMIN2_OEPRF_ONB, numRele))//установка активной команды на Реле

// Блокировка UMax1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD1_UMM, nRele))//Проверить команду
    setActivCmdRele(0, 0);//, numRele))//установка активной команды на Реле
// Блокировка UMax2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD2_UMM, nRele))//Проверить команду
    setActivCmdRele(0, 0);//, numRele))//установка активной команды на Реле

// ПО UMax1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD5_UMM, nRele))//Проверить команду
   setActivCmdRele(0, 0);//STPDEV_UMAX1_OEPRF_ONB, numRele))//установка активной команды на Реле
// UMax1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD6_UMM, nRele))//Проверить команду
    setActivCmdRele(0, 0);//UMAX1_OEPRF_ONB, numRele))//установка активной команды на Реле
// ПО UMax2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD7_UMM, nRele))//Проверить команду
     setActivCmdRele(0, 0);//STPDEV_UMAX2_OEPRF_ONB, numRele))//проверка активности команды на Реле
// UMax2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD8_UMM, nRele))//Проверить команду
   setActivCmdRele(0, 0);//UMAX2_OEPRF_ONB, numRele))//установка активной команды на Реле
}// GettingIci_RangirUMMFromRele(int nRele)

void GettingIci_RangirUMMFromLed(int nLed)
{
//отранж UMM на СДИ
int numLed = nLed - CDI1_SM;//нормировка
// Блокировка UMin1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD3_UMM, nLed));//Проверить команду
//   setActivCmdLed(BLOCK_UMIN1_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
// Блокировка UMin2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD4_UMM, nLed));//Проверить команду
//    setActivCmdLed(BLOCK_UMIN2_DI_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО UMin1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD9_UMM, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_UMIN1_OEPRF_ONB, numLed))//установка активной команды на СДИ
// UMin1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD10_UMM, nLed));//Проверить команду
//   setActivCmdLed(UMIN1_OEPRF_ONB, numLed))//установка активной команды на СДИ

// ПО UMin2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD11_UMM, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_UMIN2_OEPRF_ONB, numLed))//установка активной команды на СДИ
// UMin2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD12_UMM, nLed));//Проверить команду
//    setActivCmdLed(STPDEV_UMIN2_OEPRF_ONB, numLed))//установка активной команды на СДИ

// Блокировка UMax1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD1_UMM, nLed));//Проверить команду
// setActivCmdLed(, numLed))//установка активной команды на СДИ
// Блокировка UMax2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD2_UMM, nLed));//Проверить команду
// setActivCmdLed(, numLed))//установка активной команды на СДИ
  
// ПО UMax1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD5_UMM, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_UMAX1_OEPRF_ONB, numLed))//установка активной команды на СДИ
// UMax1
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD6_UMM, nLed));//Проверить команду
//   setActivCmdLed(UMAX1_OEPRF_ONB, numLed))//установка активной команды на СДИ
// ПО UMax2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD7_UMM, nLed));//Проверить команду
//   setActivCmdLed(STPDEV_UMAX2_OEPRF_ONB, numLed))//установка активной команды на СДИ
// UMax2
 if(GetCmdUVVFromClon(UMM_COMP1,  1, IOCMD8_UMM, nLed));//Проверить команду
//   setActivCmdLed(UMAX2_OEPRF_ONB, numLed))//установка активной на СДИ
}// GettingIci_RangirUMMGromLed(int nLed)
