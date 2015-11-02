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

void SettingIci_RangirOTToDV(int nDV)
{
//отранж Set OT на ДВ
int numDV = nDV - DV1_SM;//нормировка
/*
SET_OT1_DI_IEPRF_ONB                 ,//Вх Уст   От1 
RESET_OT1_DI_IEPRF_ONB               ,//Вх Сброс От1 
*/

// Set OT 01  
 if(isActivCmdDV(SET_OT1_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_BKL_OT1, nDV);//отранж 
// Rst OT 01  
 if(isActivCmdDV(RESET_OT1_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_OTKL_OT1, nDV);//отранж 

// Set OT 02  
 if(isActivCmdDV(SET_OT2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_BKL_OT2, nDV);//отранж 
// Rst OT 02  
 if(isActivCmdDV(RESET_OT2_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_OTKL_OT2, nDV);//отранж 

// Set OT 03  
 if(isActivCmdDV(SET_OT3_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_BKL_OT3, nDV);//отранж 
// Rst OT 03  
 if(isActivCmdDV(RESET_OT3_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_OTKL_OT3, nDV);//отранж 

// Set OT 04  
 if(isActivCmdDV(SET_OT4_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_BKL_OT4, nDV);//отранж 
// Rst OT 04  
 if(isActivCmdDV(RESET_OT4_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_OTKL_OT4, nDV);//отранж 

// Set OT 05  
 if(isActivCmdDV(SET_OT5_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_BKL_OT5, nDV);//отранж 
// Rst OT 05  
 if(isActivCmdDV(RESET_OT5_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_OTKL_OT5, nDV);//отранж 

// Set OT 06  
 if(isActivCmdDV(SET_OT6_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_BKL_OT6, nDV);//отранж 
// Rst OT 06  
 if(isActivCmdDV(RESET_OT6_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_OTKL_OT6, nDV);//отранж 

// Set OT 07  
 if(isActivCmdDV(SET_OT7_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_BKL_OT7, nDV);//отранж 
// Rst OT 07  
 if(isActivCmdDV(RESET_OT7_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_OTKL_OT7, nDV);//отранж 

// Set OT 08  
 if(isActivCmdDV(SET_OT8_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_BKL_OT8, nDV);//отранж 
// Rst OT 08  
 if(isActivCmdDV(RESET_OT8_DI_IEPRF_ONB, numDV))//проверка активности команды на ДВ
      SetCmdToUVV(OF_COMP1,  1, IOCMD_OTKL_OT8, nDV);//отранж 

}//SettingIci_RangirOTToDV(int nDV)
/*
OUT_OT1_OEPRF_ONB                    ,//Выход ОТ1
OUT_OT2_OEPRF_ONB                    ,//Выход ОТ2
OUT_OT3_OEPRF_ONB                    ,//Выход ОТ3
OUT_OT4_OEPRF_ONB                    ,//Выход ОТ4
OUT_OT5_OEPRF_ONB                    ,//Выход ОТ5
OUT_OT6_OEPRF_ONB                    ,//Выход ОТ6
OUT_OT7_OEPRF_ONB                    ,//Выход ОТ7
OUT_OT8_OEPRF_ONB                    ,//Выход ОТ8 
*/

void SettingIci_RangirOutOTToRele(int nRele)
{
//отранж OT на Реле
int numRele = nRele - RELE1_SM;//нормировка
//Выход OT_01  
 if(isActivCmdRele(OUT_OT1_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT1, nRele);//отранж 
//Выход OT_02
 if(isActivCmdRele(OUT_OT2_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT2, nRele);//отранж 
//Выход OT_03  
 if(isActivCmdRele(OUT_OT3_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT3, nRele);//отранж 
//Выход OT_04  
 if(isActivCmdRele(OUT_OT4_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT4, nRele);//отранж 
//Выход OT_05  
 if(isActivCmdRele(OUT_OT5_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT5, nRele);//отранж 
//Выход OT_06  
 if(isActivCmdRele(OUT_OT6_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT6, nRele);//отранж 
//Выход OT_07  
 if(isActivCmdRele(OUT_OT7_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT7, nRele);//отранж 
//Выход OT_08  
 if(isActivCmdRele(OUT_OT8_OEPRF_ONB, numRele))//проверка активности команды на Реле
     SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT8, nRele);//отранж 
}//SettingIci_RangirOTToRele(int nRele)
