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
#include "virtualmenu\systemmenufnc.h"
#include "SettingIci\SettingIci.h"

//#include "toSpeedOptim.h"
//#include "toSpeedDIS.h"

//#include "header.h"//G:\HVP_pj\Hvps\hvps29_07_14\HR1_0100_00_I670\inc\type_definition"
//#include "ici_r_ef.h"

#define _HIDE_COMPONENT
#include "UMMComponent.cpp"

//extern char chProtectTableComeIn;
//extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
//extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
//extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;
//extern int logicFlagUMM;

//int ustavkiZN=0;

void  GettingIci_UMM()
{
//установки ICI UMM
 int numBlok=0;
//-------------UMIN1-----------------------    
   int tmpUst = GetUstFromImageClon(numBlok, UMM_COMP1,  1, MNGUST_UMIN1_UMM);//уставка UMIN1 U
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1UminPickup.ov_range_Umin;

    tmpUst = GetUstFromImageClon(numBlok, UMM_COMP1,  1, MNGVID3_UMM);//выдержка UMIN1 
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1UminStageParam.time_stage_Umin;


    tmpUst = GetUstFromImageClon(numBlok, UMM_COMP1,  1, MNGUST_IMIN1_UMM);//уставка UMIN1 IBLOK
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1UminPickup.ov_range_IblkUmin;
  
    tmpUst = GetUstFromImageClon(numBlok, UMM_COMP1,  1, MNGUPR_UMM);//управление UMM
/*
//  int uprUMM=0;
  //меню  Состояние UMIN1
//.	Состояние
//.	1 -вкл
//.	0 - выкл
  int tmp = 0;
  if(tmpUst&64) tmp = 1;
  brCfgTbl.ownrStg1UminMng.state_Umin = tmp;
//ustavkiZN =
//    lSt1 = brCfgTbl.ownrStg1UminMng.state_Umin;
  //logicFlagUMM = lSt1;
//  if(lSt1>0) uprUMM |= 64; //UMIN1  WKL
//  else  uprUMM &= ~64; //UMIN1  OTKL 
  
  //меню  блок по току UMIN1
//.	Состояние
//.	1 -вкл
//.	0 - выкл
  tmp = 0;
  if(tmpUst&512) tmp = 1;
  brCfgTbl.ownrStg1UminMng.state_Umin_Iblk = tmp;
//    lSt1 = brCfgTbl.ownrStg1UminMng.state_Umin_Iblk;
//  if(lSt1>0) uprUMM |= 512; //UMIN1 IBLOK WKL
//  else  uprUMM &= ~512; //UMIN1 IBLOK OTKL 

  //меню  логика UMIN1
//.	Состояние
//.	1 -ILI
//.	0 - I
  tmp = 0;
  if(tmpUst&128) tmp = 1;
  brCfgTbl.ownrStg1UminMng.state_SDEV_Umin = tmp;
//     lSt1 = brCfgTbl.ownrStg1UminMng.state_SDEV_Umin;
//  if(lSt1>0) uprUMM |= 128; //UMIN1  ILI
//  else  uprUMM &= ~128; //UMIN1  I

  //меню  логика UMIN2
  //Состояние ПО блокировки по напряжению
  tmp = 0;
  if(tmpUst&16384) tmp = 1;
  brCfgTbl.ownrStg1UminMng.state_Umin_Ublk = tmp;
//     lSt1 = brCfgTbl.ownrStg1UminMng.state_Umin_Ublk;
//  if(lSt1>0) uprUMM |= 16384; //UMIN1  UBLOK
//  else  uprUMM &= ~16384; //UMIN1  UBLOK
*/  
//-------------UMIN2-----------------------    
    tmpUst = GetUstFromImageClon(numBlok, UMM_COMP1,  1, MNGUST_UMIN2_UMM);//уставка UMIN2 U
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2UminPickup.ov_range_Umin;

    tmpUst = GetUstFromImageClon(numBlok, UMM_COMP1,  1, MNGVID4_UMM);//выдержка UMIN2
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2UminStageParam.time_stage_Umin;


    tmpUst = GetUstFromImageClon(numBlok, UMM_COMP1,  1, MNGUST_IMIN2_UMM);//уставка UMIN2 IBLOK
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage2UminPickup.ov_range_IblkUmin;
/*  
//unsigned char state_Umin;       //Меню Состояние Umin
//unsigned char state_SDEV_Umin;  //Меню Состояние ПО Umin И\ИЛИ 
//unsigned char state_Umin_Ublk;  //Состояние ПО блокировки по напряжению
//unsigned char state_Umin_Iblk;  //Состояние ПО блокировки по току
  //меню  Состояние UMIN2
//.	Состояние
//.	1 -вкл
//.	0 - выкл
  tmp = 0;
  if(tmpUst&1024) tmp = 1;
  brCfgTbl.ownrStg2UminMng.state_Umin = tmp;
//    lSt1 = brCfgTbl.ownrStg2UminMng.state_Umin;
//  if(lSt1>0) uprUMM |= 1024; //UMIN2  WKL
//  else  uprUMM &= ~1024; //UMIN2  OTKL 
  
  //меню  фазы UMIN1_2
//.	Состояние
//.	1 -лин
//.	0 - фазн
  tmp = 0;
  if(tmpUst&256) tmp = 1;
  if(tmpUst&4096) tmp = 1;
  brCfgTbl.state_SDEV_Phase_Umin = tmp;
//     lSt1 = brCfgTbl.state_SDEV_Phase_Umin;
//  if(lSt1>0) uprUMM |= 256; //UMIN1_2  LIN
//  else  uprUMM &= ~256; //UMIN1_2  FAZ
//  if(lSt1>0) uprUMM |= 4096; //UMIN1_2  LIN
//  else  uprUMM &= ~4096; //UMIN1_2  FAZ
  
  //меню  блок по току UMIN2
//.	Состояние
//.	1 -вкл
//.	0 - выкл
  tmp = 0;
  if(tmpUst&8192) tmp = 1;
  brCfgTbl.ownrStg2UminMng.state_Umin_Iblk = tmp;
//    lSt1 = brCfgTbl.ownrStg2UminMng.state_Umin_Iblk;
//  if(lSt1>0) uprUMM |= 8192; //UMIN2 IBLOK WKL
//  else  uprUMM &= ~8192; //UMIN2 IBLOK OTKL 

  //меню  логика UMIN2
//.	Состояние
//.	1 -ILI
//.	0 - I
  tmp = 0;
  if(tmpUst&2048) tmp = 1;
  brCfgTbl.ownrStg2UminMng.state_SDEV_Umin = tmp;
//     lSt1 = brCfgTbl.ownrStg2UminMng.state_SDEV_Umin;
//  if(lSt1>0) uprUMM |= 2048; //UMIN2  ILI
//  else  uprUMM &= ~2048; //UMIN2  I

  //меню  логика UMIN2
  //Состояние ПО блокировки по напряжению
  tmp = 0;
  if(tmpUst&32768) tmp = 1;
  brCfgTbl.ownrStg2UminMng.state_Umin_Ublk = tmp;
//     lSt1 = brCfgTbl.ownrStg2UminMng.state_Umin_Ublk;
//  if(lSt1>0) uprUMM |= 32768; //UMIN2  UBLOK
//  else  uprUMM &= ~32768; //UMIN2  UBLOK
*/
//-------------UMAX1-----------------------    
    tmpUst = GetUstFromImageClon(numBlok, UMM_COMP1,  1, MNGUST_UMAX1_UMM);//уставка UMAX1 U
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1UmaxPickup.ov_range_Umax;

    tmpUst = GetUstFromImageClon(numBlok, UMM_COMP1,  1, MNGVID1_UMM);//выдержка UMAX1
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1UmaxStageParam.time_stage_Umax;
    
/*  
//unsigned char state_Umax;     //Меню Состояние Umax1
//unsigned char state_SDEV_Umax;//Меню Состояние ПО Umax1 И\ИЛИ 
  //меню  Состояние UMAX1
//.	Состояние
//.	1 -вкл
//.	0 - выкл
  tmp = 0;
  if(tmpUst&1) tmp = 1;
  brCfgTbl.ownrStg1UmaxMng.state_Umax = tmp;
//    lSt1 = brCfgTbl.ownrStg1UmaxMng.state_Umax;
//  if(lSt1>0) uprUMM |= 1; //UMAX1  WKL
//  else  uprUMM &= ~1; //UMAX1  OTKL 

  //меню  логика UMAX1
//.	Состояние
//.	1 -ILI
//.	0 - I
  tmp = 0;
  if(tmpUst&2) tmp = 1;
  brCfgTbl.ownrStg1UmaxMng.state_SDEV_Umax = tmp;
//     lSt1 = brCfgTbl.ownrStg1UmaxMng.state_SDEV_Umax;
//  if(lSt1>0) uprUMM |= 2; //UMAX1  ILI
//  else  uprUMM &= ~2; //UMAX1  I
*/
//-------------UMAX2-----------------------    
    tmpUst = GetUstFromImageClon(numBlok, UMM_COMP1,  1, MNGUST_UMAX2_UMM);//уставка UMAX2 U
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2UmaxPickup.ov_range_Umax;
    tmpUst = GetUstFromImageClon(numBlok, UMM_COMP1,  1, MNGVID2_UMM);//выдержка UMAX2
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2UmaxStageParam.time_stage_Umax;
    
/*  
//unsigned char state_Umax;     //Меню Состояние Umax1
//unsigned char state_SDEV_Umax;//Меню Состояние ПО Umax1 И\ИЛИ 
  //меню  Состояние UMAX2
//.	Состояние
//.	1 -вкл
//.	0 - выкл
  tmp = 0;
  if(tmpUst&8) tmp = 1;
  brCfgTbl.ownrStgU2maxMng.state_Umax = tmp;
//    lSt1 = brCfgTbl.ownrStgU2maxMng.state_Umax;
//  if(lSt1>0) uprUMM |= 8; //UMAX2  WKL
//  else  uprUMM &= ~8; //UMAX2  OTKL 

  //меню  логика UMAX2
//.	Состояние
//.	1 -ILI
//.	0 - I
  tmp = 0;
  if(tmpUst&16) tmp = 1;
  brCfgTbl.ownrStgU2maxMng.state_SDEV_Umax = tmp;
//     lSt1 = brCfgTbl.ownrStgU2maxMng.state_SDEV_Umax;
//  if(lSt1>0) uprUMM |= 16; //UMAX2  ILI
//  else  uprUMM &= ~16; //UMAX2  I
  
  //меню  фазы UMAX1_2
//.	Состояние
//.	1 -лин
//.	0 - фазн
  tmp = 0;
  if(tmpUst&4) tmp = 1;
  if(tmpUst&32) tmp = 1;
  brCfgTbl.state_SDEV_Phase_Umax = tmp;
//     lSt1 = brCfgTbl.state_SDEV_Phase_Umax;
//  if(lSt1>0) uprUMM |= 4; //UMAX1_2  LIN
//  else  uprUMM &= ~4; //UMAX1_2  FAZ
//  if(lSt1>0) uprUMM |= 32; //UMAX1_2  LIN
//  else  uprUMM &= ~32; //UMAX1_2  FAZ
  
//  SetUstToClon(UMM_COMP1,  1, MNGUPR_UMM, uprUMM);//управление UMM
*/  
}//

