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
#include "SettingIci\SettingIci.h"
#include "virtualmenu\systemmenufnc.h"
#include "virtualMenu\rangmanagerfnc.h"

#include "toSpeedOptim.h"
#include "toSpeedDIS.h"

#include "header.h"
#include "ici_r_ef.h"

#define _HIDE_COMPONENT
#include "DZ1Component.c"
#include "DZ2Component.c"

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

//extern  puskOFfunction *pntPuskOF;//указатель на ф-цию

void  SettingIci_OFDZ(int typFUNC, int FlagMaska, int numOF)//puskOFfunction *pntPuskOF, int typRang)
{

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

//----------------------------DZ------------------------------
//  lSt1 = pntPuskOF(HVSW_ON_DI_OEPRF_ONB );// Вкл. ВВ от ДВ 
  //if(lSt1) SetCmdToUVV(PRM1_COMP1,  1, IOCMD6_MTZ1, typRang);//работа с OF OT
// Блокировка DZ1
  lSt1 = pntPuskOF(BLOCK_DSTP1_DI_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  1, IOCMD1_DZ1, typRang);//работа с OF OT
// ПО ДЗ1 МФ
  lSt1 = pntPuskOF(STPDEV_DSTP1_MF_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  1, IOCMD2_DZ1, typRang);//работа с OF OT
// Cраб ДЗ1 МФ
  lSt1 = pntPuskOF(DSTP1_MF_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  1, IOCMD3_DZ1, typRang);//работа с OF OT
// ПО МТЗ ДЗ1
  lSt1 = pntPuskOF(STPDEV_MCP_DSTP1_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  1, IOCMD4_DZ1, typRang);//работа с OF OT
// Сраб МТЗ ДЗ1
  lSt1 = pntPuskOF(MCP_DSTP1_OEPRF_ONB, numOF);
     if(lSt1) SetCmdToUVV(DZ_COMP1,  1, IOCMD5_DZ1, typRang);//работа с OF OT
// ПО ДЗ1 ОФ
  lSt1 = pntPuskOF(STPDEV_DSTP1_OF_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  1, IOCMD6_DZ1, typRang);//работа с OF OT
// сраб ДЗ1 ОФ
  lSt1 = pntPuskOF(DSTP1_OF_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  1, IOCMD7_DZ1, typRang);//работа с OF OT

// Блокировка DZ2
  lSt1 = pntPuskOF(BLOCK_DSTP2_DI_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  2, IOCMD1_DZ2to5, typRang);//работа с OF OT
//Блокировка ускор Дист З2
  lSt1 = pntPuskOF(BLOCK_ACCLT_DSTP2_DI_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  2, IOCMD2_DZ2to5, typRang);//работа с OF OT
//Оперативное ускорение Дист З2
  lSt1 = pntPuskOF(ACCLT_DSTP2_DI_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  2, IOCMD3_DZ2to5, typRang);//работа с OF OT
// ПО ДЗ2 МФ
  lSt1 = pntPuskOF(STPDEV_DSTP2_MF_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  2, IOCMD4_DZ2to5MF, typRang);//работа с OF OT
// Cраб ДЗ2 МФ
  lSt1 = pntPuskOF(DSTP2_MF_OEPRF_ONB, numOF);
     if(lSt1) SetCmdToUVV(DZ_COMP1,  2, IOCMD5_DZ2to5MF, typRang);//работа с OF OT
// ПО МТЗ ДЗ2
  lSt1 = pntPuskOF(STPDEV_MCP_DSTP2_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  2, IOCMD4_MDZ2to5MF, typRang);//работа с OF OT
// Сраб МТЗ ДЗ2
  lSt1 = pntPuskOF(MCP_DSTP2_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  2, IOCMD5_MDZ2to5MF, typRang);//работа с OF OT
// ПО ДЗ2 ОФ
  lSt1 = pntPuskOF(STPDEV_DSTP2_OF_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  2, IOCMD4_DZ2to5OF, typRang);//работа с OF OT
// сраб ДЗ2 ОФ
  lSt1 = pntPuskOF(DSTP2_OF_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  2, IOCMD5_DZ2to5OF, typRang);//работа с OF OT


// Блокировка DZ3
  lSt1 = pntPuskOF(BLOCK_DSTP3_DI_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  3, IOCMD1_DZ2to5, typRang);//работа с OF OT
//Блокировка ускор Дист З3
  lSt1 = pntPuskOF(BLOCK_ACCLT_DSTP3_DI_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  3, IOCMD2_DZ2to5, typRang);//работа с OF OT
//Оперативное ускорение Дист З3
  lSt1 = pntPuskOF(ACCLT_DSTP3_DI_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  3, IOCMD3_DZ2to5, typRang);//работа с OF OT
// ПО ДЗ3 МФ
  lSt1 = pntPuskOF(STPDEV_DSTP3_MF_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  3, IOCMD4_DZ2to5MF, typRang);//работа с OF OT
// Cраб ДЗ3 МФ
  lSt1 = pntPuskOF(DSTP3_MF_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  3, IOCMD5_DZ2to5MF, typRang);//работа с OF OT
// ПО МТЗ ДЗ3
  lSt1 = pntPuskOF(STPDEV_MCP_DSTP3_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  3, IOCMD4_MDZ2to5MF, typRang);//работа с OF OT
// Сраб МТЗ ДЗ3
  lSt1 = pntPuskOF(MCP_DSTP3_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  3, IOCMD5_MDZ2to5MF, typRang);//работа с OF OT
// ПО ДЗ3 ОФ
  lSt1 = pntPuskOF(STPDEV_DSTP3_OF_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  3, IOCMD4_DZ2to5OF, typRang);//работа с OF OT
// сраб ДЗ3 ОФ
  lSt1 = pntPuskOF(DSTP3_OF_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  3, IOCMD5_DZ2to5OF, typRang);//работа с OF OT

// Блокировка DZ4
  lSt1 = pntPuskOF(BLOCK_DSTP4_DI_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  4, IOCMD1_DZ2to5, typRang);//работа с OF OT
//Блокировка ускор Дист З4
  lSt1 = pntPuskOF(BLOCK_ACCLT_DSTP4_DI_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  4, IOCMD2_DZ2to5, typRang);//работа с OF OT
//Оперативное ускорение Дист З4
  lSt1 = pntPuskOF(ACCLT_DSTP4_DI_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  4, IOCMD3_DZ2to5, typRang);//работа с OF OT
// ПО ДЗ4 МФ
  lSt1 = pntPuskOF(STPDEV_DSTP4_MF_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  4, IOCMD4_DZ2to5MF, typRang);//работа с OF OT
// Cраб ДЗ4 МФ
  lSt1 = pntPuskOF(DSTP4_MF_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  4, IOCMD5_DZ2to5MF, typRang);//работа с OF OT
// ПО МТЗ ДЗ4
  lSt1 = pntPuskOF(STPDEV_MCP_DSTP4_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  4, IOCMD4_MDZ2to5MF, typRang);//работа с OF OT
// Сраб МТЗ ДЗ4
  lSt1 = pntPuskOF(MCP_DSTP4_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  4, IOCMD5_MDZ2to5MF, typRang);//работа с OF OT
// ПО ДЗ4 ОФ
  lSt1 = pntPuskOF(STPDEV_DSTP4_OF_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  4, IOCMD4_DZ2to5OF, typRang);//работа с OF OT
// сраб ДЗ4 ОФ
  lSt1 = pntPuskOF(DSTP4_OF_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  4, IOCMD5_DZ2to5OF, typRang);//работа с OF OT

// Блокировка DZ5
  lSt1 = pntPuskOF(BLOCK_DSTP5_DI_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  5, IOCMD1_DZ2to5, typRang);//работа с OF OT
//Блокировка ускор Дист З5
  lSt1 = pntPuskOF(BLOCK_ACCLT_DSTP5_DI_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  5, IOCMD2_DZ2to5, typRang);//работа с OF OT
//Оперативное ускорение Дист З5
  lSt1 = pntPuskOF(ACCLT_DSTP5_DI_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  5, IOCMD3_DZ2to5, typRang);//работа с OF OT
// ПО ДЗ5 МФ
  lSt1 = pntPuskOF(STPDEV_DSTP5_MF_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  5, IOCMD4_DZ2to5MF, typRang);//работа с OF OT
// Cраб ДЗ5 МФ
  lSt1 = pntPuskOF(DSTP5_MF_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  5, IOCMD5_DZ2to5MF, typRang);//работа с OF OT
// ПО МТЗ ДЗ5
  lSt1 = pntPuskOF(STPDEV_MCP_DSTP5_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  5, IOCMD4_MDZ2to5MF, typRang);//работа с OF OT
// Сраб МТЗ ДЗ5
  lSt1 = pntPuskOF(MCP_DSTP5_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  5, IOCMD5_MDZ2to5MF, typRang);//работа с OF OT
// ПО ДЗ5 ОФ
  lSt1 = pntPuskOF(STPDEV_DSTP5_OF_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  5, IOCMD4_DZ2to5OF, typRang);//работа с OF OT
// сраб ДЗ5 ОФ
  lSt1 = pntPuskOF(DSTP5_OF_OEPRF_ONB, numOF);
    if(lSt1)  SetCmdToUVV(DZ_COMP1,  5, IOCMD5_DZ2to5OF, typRang);//работа с OF OT


}

