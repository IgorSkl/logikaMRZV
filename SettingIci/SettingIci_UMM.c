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

#include "toSpeedOptim.h"
#include "toSpeedDIS.h"

#include "header.h"
#include "ici_r_ef.h"

#define _HIDE_COMPONENT
#include "UMMComponent.c"

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;
//extern int logicFlagUMM;

int ustavkiZN=0;

void  SettingIci_UMM()
{
//установки ICI UMM
//-------------UMIN1-----------------------    
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1UminPickup.ov_range_Umin;
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1UminStageParam.time_stage_Umin;

  SetUstToClon(UMM_COMP1,  1, MNGUST_UMIN1_UMM, lMtz1);//уставка UMIN1 U

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1UminPickup.ov_range_IblkUmin;
  SetUstToClon(UMM_COMP1,  1, MNGUST_IMIN1_UMM, lMtz1);//уставка UMIN1 IBLOK
  
  SetUstToClon(UMM_COMP1,  1, MNGVID3_UMM, lMtz1Tmr*10);//выдержка UMIN1 
  int uprUMM=0;
//unsigned char state_Umin;       //Меню Состояние Umin
//unsigned char state_SDEV_Umin;  //Меню Состояние ПО Umin И\ИЛИ 
//unsigned char state_Umin_Ublk;  //Состояние ПО блокировки по напряжению
//unsigned char state_Umin_Iblk;  //Состояние ПО блокировки по току
  //меню  Состояние UMIN1
//.	Состояние
//.	1 -вкл
//.	0 - выкл
ustavkiZN =
    lSt1 = brCfgTbl.ownrStg1UminMng.state_Umin;
  //logicFlagUMM = lSt1;
  if(lSt1>0) uprUMM |= 64; //UMIN1  WKL
  else  uprUMM &= ~64; //UMIN1  OTKL 
  
  //меню  блок по току UMIN1
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg1UminMng.state_Umin_Iblk;
  if(lSt1>0) uprUMM |= 512; //UMIN1 IBLOK WKL
  else  uprUMM &= ~512; //UMIN1 IBLOK OTKL 

  //меню  логика UMIN1
//.	Состояние
//.	1 -ILI
//.	0 - I
     lSt1 = brCfgTbl.ownrStg1UminMng.state_SDEV_Umin;
  if(lSt1>0) uprUMM |= 128; //UMIN1  ILI
  else  uprUMM &= ~128; //UMIN1  I

  //меню  логика UMIN2
  //Состояние ПО блокировки по напряжению
     lSt1 = brCfgTbl.ownrStg1UminMng.state_Umin_Ublk;
  if(lSt1>0) uprUMM |= 16384; //UMIN1  UBLOK
  else  uprUMM &= ~16384; //UMIN1  UBLOK
  
//-------------UMIN2-----------------------    
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2UminPickup.ov_range_Umin;
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2UminStageParam.time_stage_Umin;

  SetUstToClon(UMM_COMP1,  1, MNGUST_UMIN2_UMM, lMtz1);//уставка UMIN2 U

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2UminPickup.ov_range_IblkUmin;
  SetUstToClon(UMM_COMP1,  1, MNGUST_IMIN2_UMM, lMtz1);//уставка UMIN2 IBLOK
  
  SetUstToClon(UMM_COMP1,  1, MNGVID4_UMM, lMtz1Tmr*10);//выдержка UMIN2
  
//unsigned char state_Umin;       //Меню Состояние Umin
//unsigned char state_SDEV_Umin;  //Меню Состояние ПО Umin И\ИЛИ 
//unsigned char state_Umin_Ublk;  //Состояние ПО блокировки по напряжению
//unsigned char state_Umin_Iblk;  //Состояние ПО блокировки по току
  //меню  Состояние UMIN2
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg2UminMng.state_Umin;
  if(lSt1>0) uprUMM |= 1024; //UMIN2  WKL
  else  uprUMM &= ~1024; //UMIN2  OTKL 
  
  //меню  фазы UMIN1_2
//.	Состояние
//.	1 -лин
//.	0 - фазн
     lSt1 = brCfgTbl.state_SDEV_Phase_Umin;
  if(lSt1>0) uprUMM |= 256; //UMIN1_2  LIN
  else  uprUMM &= ~256; //UMIN1_2  FAZ
  if(lSt1>0) uprUMM |= 4096; //UMIN1_2  LIN
  else  uprUMM &= ~4096; //UMIN1_2  FAZ
  
  //меню  блок по току UMIN2
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg2UminMng.state_Umin_Iblk;
  if(lSt1>0) uprUMM |= 8192; //UMIN2 IBLOK WKL
  else  uprUMM &= ~8192; //UMIN2 IBLOK OTKL 

  //меню  логика UMIN2
//.	Состояние
//.	1 -ILI
//.	0 - I
     lSt1 = brCfgTbl.ownrStg2UminMng.state_SDEV_Umin;
  if(lSt1>0) uprUMM |= 2048; //UMIN2  ILI
  else  uprUMM &= ~2048; //UMIN2  I

  //меню  логика UMIN2
  //Состояние ПО блокировки по напряжению
     lSt1 = brCfgTbl.ownrStg2UminMng.state_Umin_Ublk;
  if(lSt1>0) uprUMM |= 32768; //UMIN2  UBLOK
  else  uprUMM &= ~32768; //UMIN2  UBLOK

//-------------UMAX1-----------------------    
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1UmaxPickup.ov_range_Umax;
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1UmaxStageParam.time_stage_Umax;
    
  SetUstToClon(UMM_COMP1,  1, MNGUST_UMAX1_UMM, lMtz1);//уставка UMAX1 U
  SetUstToClon(UMM_COMP1,  1, MNGVID1_UMM, lMtz1Tmr*10);//выдержка UMAX1
  
//unsigned char state_Umax;     //Меню Состояние Umax1
//unsigned char state_SDEV_Umax;//Меню Состояние ПО Umax1 И\ИЛИ 
  //меню  Состояние UMAX1
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg1UmaxMng.state_Umax;
  if(lSt1>0) uprUMM |= 1; //UMAX1  WKL
  else  uprUMM &= ~1; //UMAX1  OTKL 

  //меню  логика UMAX1
//.	Состояние
//.	1 -ILI
//.	0 - I
     lSt1 = brCfgTbl.ownrStg1UmaxMng.state_SDEV_Umax;
  if(lSt1>0) uprUMM |= 2; //UMAX1  ILI
  else  uprUMM &= ~2; //UMAX1  I

//-------------UMAX2-----------------------    
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2UmaxPickup.ov_range_Umax;
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2UmaxStageParam.time_stage_Umax;
    
  SetUstToClon(UMM_COMP1,  1, MNGUST_UMAX2_UMM, lMtz1);//уставка UMAX2 U
  SetUstToClon(UMM_COMP1,  1, MNGVID2_UMM, lMtz1Tmr*10);//выдержка UMAX2
  
//unsigned char state_Umax;     //Меню Состояние Umax1
//unsigned char state_SDEV_Umax;//Меню Состояние ПО Umax1 И\ИЛИ 
  //меню  Состояние UMAX2
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStgU2maxMng.state_Umax;
  if(lSt1>0) uprUMM |= 8; //UMAX2  WKL
  else  uprUMM &= ~8; //UMAX2  OTKL 

  //меню  логика UMAX2
//.	Состояние
//.	1 -ILI
//.	0 - I
     lSt1 = brCfgTbl.ownrStgU2maxMng.state_SDEV_Umax;
  if(lSt1>0) uprUMM |= 16; //UMAX2  ILI
  else  uprUMM &= ~16; //UMAX2  I
  
  //меню  фазы UMAX1_2
//.	Состояние
//.	1 -лин
//.	0 - фазн
     lSt1 = brCfgTbl.state_SDEV_Phase_Umax;
  if(lSt1>0) uprUMM |= 4; //UMAX1_2  LIN
  else  uprUMM &= ~4; //UMAX1_2  FAZ
  if(lSt1>0) uprUMM |= 32; //UMAX1_2  LIN
  else  uprUMM &= ~32; //UMAX1_2  FAZ
  
  SetUstToClon(UMM_COMP1,  1, MNGUPR_UMM, uprUMM);//управление UMM
  
}//

