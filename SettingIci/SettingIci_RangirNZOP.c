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
#include "NZOP1Component.c"

void SettingIci_RangirNZOPToDV(int nDV)
{
  int numDV = nDV - DV1_SM;//нормировка
      //Блокировка ЗОП1
  if(isActivCmdDV(BLOCK_ZOP1_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(NZOP_COMP1,  1, IOCMD1_NZOP1to2, nDV);//отранж на ДВ
      //Блокировка ЗОП2
  if(isActivCmdDV(BLOCK_ZOP2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(NZOP_COMP1,  2, IOCMD1_NZOP1to2, nDV);//отранж на ДВ
}//SettingIci_RangirPRM2DV(int nDV)

void SettingIci_RangirNZOPToRele(int nRele)
{
//отранж PRM1 на Реле
int numRele = nRele - RELE1_SM;//нормировка
//Блокировка ЗОП1
 if(isActivCmdRele(BLOCK_ZOP1_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(NZOP_COMP1,  1, IOCMD1_NZOP1to2, nRele);//отранж 
 //Сектор НЗОП1Впер 
 if(isActivCmdRele(STPDEV_SECTOR_ZOP1_STAIGHT_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(NZOP_COMP1,  1, IOCMD6_NZOP1to2, nRele);//отранж 
 //Сектор НЗОП1назад
 if(isActivCmdRele(STPDEV_SECTOR_ZOP1_BACK_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(NZOP_COMP1,  1, IOCMD7_NZOP1to2, nRele);//отранж 
 //ПО ЗОП1
 if(isActivCmdRele(STPDEV_ZOP1_BORING_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(NZOP_COMP1,  1, IOCMD2_NZOP1to2, nRele);//отранж 
 //ПО НЗОП1Впер
 if(isActivCmdRele(STPDEV_ZOP1_STAIGHT_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(NZOP_COMP1,  1, IOCMD3_NZOP1to2, nRele);//отранж 
 //ПО НЗОП1ННазад
 if(isActivCmdRele(STPDEV_ZOP1_BACK_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(NZOP_COMP1,  1, IOCMD4_NZOP1to2, nRele);//отранж 
 //Сраб НЗОП1
 if(isActivCmdRele(ZOP1_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(NZOP_COMP1,  1, IOCMD5_NZOP1to2, nRele);//отранж 

//Блокировка ЗОП2
 if(isActivCmdRele(BLOCK_ZOP2_DI_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(NZOP_COMP1,  2, IOCMD1_NZOP1to2, nRele);//отранж 
 //Сектор НЗОП2Впер 
 if(isActivCmdRele(STPDEV_SECTOR_ZOP2_STAIGHT_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(NZOP_COMP1,  2, IOCMD6_NZOP1to2, nRele);//отранж 
 //Сектор НЗОП2назад
 if(isActivCmdRele(STPDEV_SECTOR_ZOP2_BACK_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(NZOP_COMP1,  2, IOCMD7_NZOP1to2, nRele);//отранж 
 //ПО ЗОП2
 if(isActivCmdRele(STPDEV_ZOP2_BORING_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(NZOP_COMP1,  2, IOCMD2_NZOP1to2, nRele);//отранж 
 //ПО НЗОП2Впер
 if(isActivCmdRele(STPDEV_ZOP2_STAIGHT_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(NZOP_COMP1,  2, IOCMD3_NZOP1to2, nRele);//отранж 
 //ПО НЗОП2ННазад
 if(isActivCmdRele(STPDEV_ZOP2_BACK_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(NZOP_COMP1,  2, IOCMD4_NZOP1to2, nRele);//отранж 
 //Сраб НЗОП2
 if(isActivCmdRele(ZOP2_OEPRF_ONB, numRele))//проверка активности команды на Rele
      SetCmdToUVV(NZOP_COMP1,  2, IOCMD5_NZOP1to2, nRele);//отранж 
}// SettingIci_RangirNZOPToRele(int nRele)

void SettingIci_RangirNZOPToLed(int nLed)
{
//отранж DZ1 на СДИ
int numLed = nLed - CDI1_SM;//нормировка
// Блокировка UMin1
// if(isActivCmdLed(BLOCK_UMIN1_DI_OEPRF_ONB, numLed))//проверка активности команды на Реле
  //    SetCmdToUVV(UMM_COMP1,  1, IOCMD3_UMM, nLed);//отранж 

}// SettingIci_RangirPRM1ToRele(int nLed)
