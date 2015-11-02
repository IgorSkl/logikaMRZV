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
#include "NZOP2Component.c"

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

void  SettingIci_OFNZOP(int typFUNC, int FlagMaska, int numOF)
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

//отранж UMM на Реле
//int numRele = nRele - RELE1_SM;//нормировка
//Сектор НЗОП1Впер  
  lSt1 = pntPuskOF(STPDEV_SECTOR_ZOP1_STAIGHT_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(NZOP_COMP1,  1, IOCMD6_NZOP1to2, typRang);//работа с OF OT
//Сектор НЗОП1Назад
  lSt1 = pntPuskOF(STPDEV_SECTOR_ZOP1_BACK_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(NZOP_COMP1,  1, IOCMD7_NZOP1to2, typRang);//работа с OF OT
//ПО ЗОП1
  lSt1 = pntPuskOF(STPDEV_ZOP1_BORING_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(NZOP_COMP1,  1, IOCMD2_NZOP1to2, typRang);//работа с OF OT
//ПО НЗОП1Впер
  lSt1 = pntPuskOF(STPDEV_ZOP1_STAIGHT_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(NZOP_COMP1,  1, IOCMD3_NZOP1to2, typRang);//работа с OF OT
//ПО НЗОП1ННазад
  lSt1 = pntPuskOF(STPDEV_ZOP1_BACK_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(NZOP_COMP1,  1, IOCMD4_NZOP1to2, typRang);//работа с OF OT
//Сраб НЗОП1 
  lSt1 = pntPuskOF(ZOP1_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(NZOP_COMP1,  1, IOCMD5_NZOP1to2, typRang);//работа с OF OT
//Стат блок НЗОП1
  lSt1 = pntPuskOF(BLOCK_ZOP1_DI_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(NZOP_COMP1,  1, IOCMD1_NZOP1to2, typRang);//работа с OF OT

//Стат блок НЗОП2
  lSt1 = pntPuskOF(BLOCK_ZOP2_DI_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(NZOP_COMP1,  2, IOCMD1_NZOP1to2, typRang);//работа с OF OT
//Сектор НЗОП2Впер  
  lSt1 = pntPuskOF(STPDEV_SECTOR_ZOP2_STAIGHT_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(NZOP_COMP1,  2, IOCMD6_NZOP1to2, typRang);//работа с OF OT
//Сектор НЗОП2Назад
  lSt1 = pntPuskOF(STPDEV_SECTOR_ZOP2_BACK_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(NZOP_COMP1,  2, IOCMD7_NZOP1to2, typRang);//работа с OF OT
//ПО ЗОП2
  lSt1 = pntPuskOF(STPDEV_ZOP2_BORING_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(NZOP_COMP1,  2, IOCMD2_NZOP1to2, typRang);//работа с OF OT
//ПО НЗОП2Впер
  lSt1 = pntPuskOF(STPDEV_ZOP2_STAIGHT_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(NZOP_COMP1,  2, IOCMD3_NZOP1to2, typRang);//работа с OF OT
//ПО НЗОП2ННазад
  lSt1 = pntPuskOF(STPDEV_ZOP2_BACK_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(NZOP_COMP1,  2, IOCMD4_NZOP1to2, typRang);//работа с OF OT
//Сраб НЗОП2
  lSt1 = pntPuskOF(ZOP2_OEPRF_ONB, numOF);
  if(lSt1)    SetCmdToUVV(NZOP_COMP1,  2, IOCMD5_NZOP1to2, typRang);//работа с OF OT
}//SettingIci_OFNZOP(int typFUNC, int FlagMaska, int numOF)
/*
STPDEV_SECTOR_ZOP1_STAIGHT_OEPRF_ONB ,// //Сектор НЗОП1Впер  
STPDEV_SECTOR_ZOP1_BACK_OEPRF_ONB    ,//   Сектор НЗОП1Назад
STPDEV_ZOP1_BORING_OEPRF_ONB         ,//    ПО ЗОП1
STPDEV_ZOP1_STAIGHT_OEPRF_ONB        ,//    ПО НЗОП1Впер
STPDEV_ZOP1_BACK_OEPRF_ONB           ,//    ПО НЗОП1ННазад
ZOP1_OEPRF_ONB                       ,//   Сраб НЗОП1 
 
STPDEV_SECTOR_ZOP2_STAIGHT_OEPRF_ONB ,// //Сектор НЗОП2Впер  
STPDEV_SECTOR_ZOP2_BACK_OEPRF_ONB    ,//   Сектор НЗОП2Назад
STPDEV_ZOP2_BORING_OEPRF_ONB         ,//    ПО ЗОП2
STPDEV_ZOP2_STAIGHT_OEPRF_ONB        ,//    ПО НЗОП2Впер
STPDEV_ZOP2_BACK_OEPRF_ONB           ,//    ПО НЗОП2ННазад
ZOP2_OEPRF_ONB                       ,//   Сраб НЗОП2 

BLOCK_ZOP1_DI_OEPRF_ONB              ,//Блокировка ЗОП1
BLOCK_ZOP2_DI_OEPRF_ONB              ,//Блокировка ЗОП2

*/

