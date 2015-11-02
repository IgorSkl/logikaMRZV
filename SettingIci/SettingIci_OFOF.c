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

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

void SettingIci_OFOF(int typFUNC, int FlagMaska, int numOF)
{
//отранж OF на Реле
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

//Выход Оф_01  
  lSt1 = pntPuskOF(EDF01_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF1, typRang);//работа с OF OT
//Выход Оф_02
  lSt1 = pntPuskOF(EDF02_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF2, typRang);//работа с OF OT
//Выход Оф_03  
  lSt1 = pntPuskOF(EDF03_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF3, typRang);//работа с OF OT
//Выход Оф_04  
  lSt1 = pntPuskOF(EDF04_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF4, typRang);//работа с OF OT
//Выход Оф_05  
  lSt1 = pntPuskOF(EDF05_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF5, typRang);//работа с OF OT

//Выход Оф_06
  lSt1 = pntPuskOF(EDF06_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF6, typRang);//работа с OF OT
//Выход Оф_07  
  lSt1 = pntPuskOF(EDF07_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF7, typRang);//работа с OF OT
//Выход Оф_08  
  lSt1 = pntPuskOF(EDF08_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF8, typRang);//работа с OF OT
//Выход Оф_09  
  lSt1 = pntPuskOF(EDF09_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF9, typRang);//работа с OF OT
//Выход Оф_10  
  lSt1 = pntPuskOF(EDF10_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF10, typRang);//работа с OF OT
//Выход Оф_11  
  lSt1 = pntPuskOF(EDF11_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF11, typRang);//работа с OF OT
//Выход Оф_12  
  lSt1 = pntPuskOF(EDF12_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF12, typRang);//работа с OF OT
//Выход Оф_13  
  lSt1 = pntPuskOF(EDF13_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF13, typRang);//работа с OF OT
//Выход Оф_14  
  lSt1 = pntPuskOF(EDF14_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF14, typRang);//работа с OF OT
//Выход Оф_15  
  lSt1 = pntPuskOF(EDF15_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF15, typRang);//работа с OF OT
//Выход Оф_16  
  lSt1 = pntPuskOF(EDF16_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF16, typRang);//работа с OF OT
//------------OT-------------------

//Выход OT1
  lSt1 = pntPuskOF(OUT_OT1_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT1, typRang);//работа с OF OT
//Выход OT2
  lSt1 = pntPuskOF(OUT_OT2_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT2, typRang);//работа с OF OT
//Выход OT3
  lSt1 = pntPuskOF(OUT_OT3_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT3, typRang);//работа с OF OT
//Выход OT4
  lSt1 = pntPuskOF(OUT_OT4_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT4, typRang);//работа с OF OT
//Выход OT5
  lSt1 = pntPuskOF(OUT_OT5_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT5, typRang);//работа с OF OT
//Выход OT6
  lSt1 = pntPuskOF(OUT_OT6_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT6, typRang);//работа с OF OT
//Выход OT7
  lSt1 = pntPuskOF(OUT_OT7_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT7, typRang);//работа с OF OT
//Выход OT8
  lSt1 = pntPuskOF(OUT_OT8_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT8, typRang);//работа с OF OT

}//SettingIci_OFOF(int typFUNC, int FlagMaska, int numOF)

/*
EDF01_OEPRF_ONB                      ,//Выход Оф_01  
EDF02_OEPRF_ONB                      ,//Выход Оф_02
EDF03_OEPRF_ONB                      ,//Выход Оф_03
EDF04_OEPRF_ONB                      ,//Выход Оф_04
EDF05_OEPRF_ONB                      ,//Выход Оф_05
EDF06_OEPRF_ONB                      ,//Выход Оф_06
EDF07_OEPRF_ONB                      ,//Выход Оф_07
EDF08_OEPRF_ONB                      ,//Выход Оф_08
EDF09_OEPRF_ONB                      ,//Выход Оф_09
EDF10_OEPRF_ONB                      ,//Выход Оф_10  
EDF11_OEPRF_ONB                      ,//Выход Оф_11
EDF12_OEPRF_ONB                      ,//Выход Оф_12
EDF13_OEPRF_ONB                      ,//Выход Оф_13
EDF14_OEPRF_ONB                      ,//Выход Оф_14
EDF15_OEPRF_ONB                      ,//Выход Оф_15
EDF16_OEPRF_ONB                      ,//Выход Оф_16


OUT_OT1_OEPRF_ONB                    ,//Выход ОТ1
OUT_OT2_OEPRF_ONB                    ,//Выход ОТ2
OUT_OT3_OEPRF_ONB                    ,//Выход ОТ3
OUT_OT4_OEPRF_ONB                    ,//Выход ОТ4
OUT_OT5_OEPRF_ONB                    ,//Выход ОТ5
OUT_OT6_OEPRF_ONB                    ,//Выход ОТ6
OUT_OT7_OEPRF_ONB                    ,//Выход ОТ7
OUT_OT8_OEPRF_ONB                    ,//Выход ОТ8 
*/

