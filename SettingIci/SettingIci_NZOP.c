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
#include "NZOP1Component.c"

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

void  SettingIci_NZOP()
{
/*
unsigned int ov_range_Zop_s_I2;
//. уставка по току ПО НЗОП прям
//. 1 ед = 1 мA
unsigned int ov_range_Zop_s_U2;
//. уставка по напряжению ПО НЗОП  прям
//. 1 ед = 1 мA

unsigned int ov_range_Zop_b_I2;
//. уставка по току ПО НЗОП обр
//. 1 ед = 1 мA
unsigned int ov_range_Zop_b_U2;
*/

//установки ICI NZOP
//-------------NZOP1-----------------------    
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1NspPickupStoreDsc.ov_range_Zop_s_I2;
    SetUstToClon(NZOP_COMP1,  1, MNGUST_ICM_NZOP1to2_V, lMtz1);//уставка по ICM НЗОП1 ВПД

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1NspPickupStoreDsc.ov_range_Zop_b_I2;
    SetUstToClon(NZOP_COMP1,  1, MNGUST_ICM_NZOP1to2_N, lMtz1);//уставка по ICM НЗОП НЗД

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1NspPickupStoreDsc.ov_range_Zop_s_U2;
    SetUstToClon(NZOP_COMP1,  1, MNGUST_UCM_NZOP1to2_V, lMtz1);//уставка по UCM НЗОП1 ВПД

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1NspPickupStoreDsc.ov_range_Zop_b_U2;
    SetUstToClon(NZOP_COMP1,  1, MNGUST_UCM_NZOP1to2_N, lMtz1);//уставка по UCM НЗОП НЗД

/*
unsigned short time_stage_Zop;   //- выдержка ЗОП
unsigned short time_stage_Zop_s;    //- выдержка T вперед ЗOП 
unsigned short time_stage_Zop_b;    //- выдержка T назад ЗOП 
*/
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1NspStageParamStoreDsc.time_stage_Zop;
  SetUstToClon(NZOP_COMP1,  1, MNGVID_NZOP1to2, lMtz1Tmr*10);//выдержка НЗОП1 
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1NspStageParamStoreDsc.time_stage_Zop_s;
  SetUstToClon(NZOP_COMP1,  1, MNGVID_NZOP1to2_V, lMtz1Tmr*10);//выдержка НЗОП1 ВПД
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1NspStageParamStoreDsc.time_stage_Zop_b;
  SetUstToClon(NZOP_COMP1,  1, MNGVID_NZOP1to2_N, lMtz1Tmr*10);//выдержка НЗОП1 НЗД

/*
unsigned char select_prt_zop;//Селектор зоп
//меню  выбор рабоы защиты ЗОП Пуск(Работа) 
//по направленности Пуск(Работа) по напряжению
//.	Состояние
//.	0 - Простая
//.	1 - Пуск по направленности

unsigned char state_dir_zop;
//.	Состояние
//.	1 -вкл
//.	0 - выкл
unsigned char select_dir_zop;
//.	Состояние
//.	1 - прямая
//.	0 - обратная
*/

  int uprNZOP1=0;
  //меню Вид NZOP1
//.	Состояние
//.	0 - Простая
//.	1 - Пуск по направленности
    lSt1 = brCfgTbl.ownrStg1NspMng.select_prt_zop;
  if(lSt1>0) uprNZOP1 |= 1; //NZOP1  WKL
  else  uprNZOP1 &= ~1; //NZOP1  OTKL 
  //меню  Состояние NZOP1
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg1NspMng.state_dir_zop;
  if(lSt1>0) uprNZOP1 |= 2; //NZOP1 
  else  uprNZOP1 &= ~2; //NZOP1  

  //меню Направление NZOP1
//.	Состояние
//.	1 - прямая
//.	0 - обратная
    lSt1 = brCfgTbl.ownrStg1NspMng.select_dir_zop;
  if(lSt1>0) uprNZOP1 |= 4; //NZOP1  
  else  uprNZOP1 &= ~4; 

  SetUstToClon(NZOP_COMP1,  1, MNGUPR_NZOP1to2, uprNZOP1);//управление NZOP1

//-------------NZOP2-----------------------    
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2NspPickupStoreDsc.ov_range_Zop_s_I2;
    SetUstToClon(NZOP_COMP1,  2, MNGUST_ICM_NZOP1to2_V, lMtz1);//уставка по ICM НЗОП1 ВПД

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2NspPickupStoreDsc.ov_range_Zop_b_I2;
    SetUstToClon(NZOP_COMP1,  2, MNGUST_ICM_NZOP1to2_N, lMtz1);//уставка по ICM НЗОП НЗД

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2NspPickupStoreDsc.ov_range_Zop_s_U2;
    SetUstToClon(NZOP_COMP1,  2, MNGUST_UCM_NZOP1to2_V, lMtz1);//уставка по UCM НЗОП1 ВПД

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2NspPickupStoreDsc.ov_range_Zop_b_U2;
    SetUstToClon(NZOP_COMP1,  2, MNGUST_UCM_NZOP1to2_N, lMtz1);//уставка по UCM НЗОП НЗД
/*
unsigned short time_stage_Zop;   //- выдержка ЗОП
unsigned short time_stage_Zop_s;    //- выдержка T вперед ЗOП 
unsigned short time_stage_Zop_b;    //- выдержка T назад ЗOП 
*/
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2NspStageParamStoreDsc.time_stage_Zop;
  SetUstToClon(NZOP_COMP1,  2, MNGVID_NZOP1to2, lMtz1Tmr*10);//выдержка НЗОП2 
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2NspStageParamStoreDsc.time_stage_Zop_s;
  SetUstToClon(NZOP_COMP1,  2, MNGVID_NZOP1to2_V, lMtz1Tmr*10);//выдержка НЗОП2 ВПД
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2NspStageParamStoreDsc.time_stage_Zop_b;
  SetUstToClon(NZOP_COMP1,  2, MNGVID_NZOP1to2_N, lMtz1Tmr*10);//выдержка НЗОП2 НЗД

/*
unsigned char select_prt_zop;//Селектор зоп
//меню  выбор рабоы защиты ЗОП Пуск(Работа) 
//по направленности Пуск(Работа) по напряжению
//.	Состояние
//.	0 - Простая
//.	1 - Пуск по направленности

unsigned char state_dir_zop;
//.	Состояние
//.	1 -вкл
//.	0 - выкл
unsigned char select_dir_zop;
//.	Состояние
//.	1 - прямая
//.	0 - обратная
*/

  int uprNZOP2=0;
  //меню Вид NZOP2
//.	Состояние
//.	0 - Простая
//.	1 - Пуск по направленности
    lSt1 = brCfgTbl.ownrStg2NspMng.select_prt_zop;
  if(lSt1>0) uprNZOP2 |= 1; //NZOP2  WKL
  else  uprNZOP2 &= ~1; //NZOP2  OTKL 
  //меню  Состояние NZOP2
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg2NspMng.state_dir_zop;
  if(lSt1>0) uprNZOP2 |= 2; //NZOP2 
  else  uprNZOP2 &= ~2; //NZOP2

  //меню Направление NZOP2
//.	Состояние
//.	1 - прямая
//.	0 - обратная
    lSt1 = brCfgTbl.ownrStg2NspMng.select_dir_zop;
  if(lSt1>0) uprNZOP2 |= 4; //NZOP2
  else  uprNZOP2 &= ~4; 

  SetUstToClon(NZOP_COMP1,  2, MNGUPR_NZOP1to2, uprNZOP2);//управление NZOP

}//

