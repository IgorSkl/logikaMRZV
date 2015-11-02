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

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

void  SettingIci_OFMTZ(int typFUNC, int FlagMaska, int numOF)
{
//отранж МТЗ на Реле
//int numRele = nRele - RELE1_SM;//нормировка
//  int typRang
puskOFfunction *pntPuskOF;

  int typRang = PUSK1OF_SM;
  if(typFUNC==0){//OF
  typRang = typRang - numOF*3 - FlagMaska;

  switch(FlagMaska){
   case 0://PLUS
    pntPuskOF = &puskOFotZPLUS;
   break;
   case 1://MINUS
    pntPuskOF = &puskOFotZMINUS;
   break;
   case 2://BLK
    pntPuskOF = &puskOFotZBLK;
   break;
  }//switch
  }//if(typFUNC==0)
  if(typFUNC==1){//OT
  typRang = PUSK1OT1_SM;
  typRang = typRang - numOF*4 - FlagMaska;

  switch(FlagMaska){
   case 0://PLUS Set
    pntPuskOF = &puskSetOTotZPLUS;
   break;
   case 1://PLUS Rst
    pntPuskOF = &puskRstOTotZPLUS;
   break;
   case 2://MINUS Set
    pntPuskOF = &puskSetOTotZMINUS;
   break;
   case 3://MINUS Rst
    pntPuskOF = &puskRstOTotZMINUS;
   break;
  }//switch
  }//if(typFUNC==0)

// Блокировка МТЗ1
  lSt1 = pntPuskOF(BLOCK_MCP1_DI_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  1, IOCMD1_MTZ1, typRang);//работа с OF OT
// Блокировка МТЗ2
  lSt1 = pntPuskOF(BLOCK_MCP2_DI_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(MTZ_COMP1,  2, IOCMD1_MTZ2to5, typRang);//работа с OF OT
// Блокировка МТЗ3
  lSt1 = pntPuskOF(BLOCK_MCP3_DI_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(MTZ_COMP1,  3, IOCMD1_MTZ2to5, typRang);//работа с OF OT
// Блокировка МТЗ4
  lSt1 = pntPuskOF(BLOCK_MCP4_DI_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(MTZ_COMP1,  4, IOCMD1_MTZ2to5, typRang);//работа с OF OT
// Блокировка МТЗ5
  lSt1 = pntPuskOF(BLOCK_MCP5_DI_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(MTZ_COMP1,  5, IOCMD1_MTZ2to5, typRang);//работа с OF OT

//Оперативное ускорение МТЗ2
  lSt1 = pntPuskOF(ACCLT_MCP2_DI_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  2, IOCMD3_MTZ2to5, typRang);//работа с OF OT
//Оперативное ускорение МТЗ3
  lSt1 = pntPuskOF(ACCLT_MCP3_DI_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  3, IOCMD3_MTZ2to5, typRang);//работа с OF OT
//Оперативное ускорение МТЗ4
  lSt1 = pntPuskOF(ACCLT_MCP4_DI_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  4, IOCMD3_MTZ2to5, typRang);//работа с OF OT
//Оперативное ускорение МТЗ5
  lSt1 = pntPuskOF(ACCLT_MCP5_DI_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  5, IOCMD3_MTZ2to5, typRang);//работа с OF OT

// ПО МТЗ1
  lSt1 = pntPuskOF(STPDEV_MCP1_BORING_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  1, IOCMD2_MTZ1, typRang);//работа с OF OT
// ПО МТЗ1 ВПД
  lSt1 = pntPuskOF(STPDEV_MCP1_STAIGHT_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  1, IOCMD3_MTZ1, typRang);//работа с OF OT
// ПО МТЗ1 НЗД
  lSt1 = pntPuskOF(STPDEV_MCP1_BACK_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  1, IOCMD4_MTZ1, typRang);//работа с OF OT
// ПО МТЗ1 ПН
  lSt1 = pntPuskOF(STPDEV_MCP1_VLT_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  1, IOCMD5_MTZ1, typRang);//работа с OF OT
// сраб МТЗ1
  lSt1 = pntPuskOF(MCP1_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  1, IOCMD6_MTZ1, typRang);//работа с OF OT

// ПО МТЗ2
  lSt1 = pntPuskOF(STPDEV_MCP2_BORING_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  2, IOCMD4_MTZ2to5, typRang);//работа с OF OT
// ПО МТЗ2 ВПД
  lSt1 = pntPuskOF(STPDEV_MCP2_STAIGHT_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  2, IOCMD5_MTZ2to5, typRang);//работа с OF OT
// ПО МТЗ2 НЗД
  lSt1 = pntPuskOF(STPDEV_MCP2_BACK_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  2, IOCMD6_MTZ2to5, typRang);//работа с OF OT
// ПО МТЗ2 ПН
  lSt1 = pntPuskOF(STPDEV_MCP2_VLT_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  2, IOCMD7_MTZ2to5, typRang);//работа с OF OT
// сраб МТЗ2
  lSt1 = pntPuskOF(MCP2_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(MTZ_COMP1,  2, IOCMD8_MTZ2to5, typRang);//работа с OF OT

// ПО МТЗ3
  lSt1 = pntPuskOF(STPDEV_MCP3_BORING_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(MTZ_COMP1,  3, IOCMD4_MTZ2to5, typRang);//работа с OF OT
// ПО МТЗ3 ВПД
  lSt1 = pntPuskOF(STPDEV_MCP3_STAIGHT_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(MTZ_COMP1,  3, IOCMD5_MTZ2to5, typRang);//работа с OF OT
// ПО МТЗ3 НЗД
  lSt1 = pntPuskOF(STPDEV_MCP3_BACK_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  3, IOCMD6_MTZ2to5, typRang);//работа с OF OT
// ПО МТЗ3 ПН
  lSt1 = pntPuskOF(STPDEV_MCP3_VLT_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(MTZ_COMP1,  3, IOCMD7_MTZ2to5, typRang);//работа с OF OT
// сраб МТЗ3
  lSt1 = pntPuskOF(MCP3_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  3, IOCMD8_MTZ2to5, typRang);//работа с OF OT

// ПО МТЗ4
  lSt1 = pntPuskOF(STPDEV_MCP4_BORING_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  4, IOCMD4_MTZ2to5, typRang);//работа с OF OT
// ПО МТЗ4 ВПД
  lSt1 = pntPuskOF(STPDEV_MCP4_STAIGHT_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  4, IOCMD5_MTZ2to5, typRang);//работа с OF OT
// ПО МТЗ4 НЗД
  lSt1 = pntPuskOF(STPDEV_MCP4_BACK_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  4, IOCMD6_MTZ2to5, typRang);//работа с OF OT
// ПО МТЗ4 ПН
  lSt1 = pntPuskOF(STPDEV_MCP4_VLT_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(MTZ_COMP1,  4, IOCMD7_MTZ2to5, typRang);//работа с OF OT
// сраб МТЗ4
  lSt1 = pntPuskOF(MCP4_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(MTZ_COMP1,  4, IOCMD8_MTZ2to5, typRang);//работа с OF OT

// ПО МТЗ5
  lSt1 = pntPuskOF(STPDEV_MCP5_BORING_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  5, IOCMD4_MTZ2to5, typRang);//работа с OF OT
// ПО МТЗ5 ВПД
  lSt1 = pntPuskOF(STPDEV_MCP5_STAIGHT_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(MTZ_COMP1,  5, IOCMD5_MTZ2to5, typRang);//работа с OF OT
// ПО МТЗ5 НЗД
  lSt1 = pntPuskOF(STPDEV_MCP5_BACK_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(MTZ_COMP1,  5, IOCMD6_MTZ2to5, typRang);//работа с OF OT
// ПО МТЗ5 ПН
  lSt1 = pntPuskOF(STPDEV_MCP5_VLT_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  5, IOCMD7_MTZ2to5, typRang);//работа с OF OT
// сраб МТЗ5
  lSt1 = pntPuskOF(MCP5_OEPRF_ONB, numOF);
   if(lSt1)   SetCmdToUVV(MTZ_COMP1,  5, IOCMD8_MTZ2to5, typRang);//работа с OF OT
}//SettingIci_RangirMTZ2Rele(int nRele)

