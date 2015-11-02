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
#include "PRM1Component.c"

extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;

void  SettingIci_PRM1()
{
//выдержки PRM1
     lMtz1Tmr = brCfgTbl.Dstp_T_UI_NCN;//выдежка UI НЦН
  SetUstToClon(PRM1_COMP1,  1, MNGVID_PRM1_UINCNDZ, lMtz1Tmr*10);//выдержкa UI НЦН ДЗ
     lMtz1Tmr = brCfgTbl.Dstp_T_NonSymMode_NCN;//выдержка обрат последоват CM НЦН ДЗ
  SetUstToClon(PRM1_COMP1,  1, MNGVID_PRM1_CMNCNDZ, lMtz1Tmr*10);//выдержка обрат последоват CM НЦН ДЗ

 //T привод ВВ
     lMtz1Tmr = brCfgTbl.ownrBru.time_ActuatorHVS;  
  SetUstToClon(PRM1_COMP1,  1, MNGVID_PRM1_PRIVODVV, lMtz1Tmr*10);

//выдержка формирователя Блока отключения
     lMtz1Tmr = brCfgTbl.ownrBru.time_stageOFFUnit;   
  SetUstToClon(PRM1_COMP1,  1, MNGUST_PRM1_BO, lMtz1Tmr*10);

//выдержка формирователя Блока включения
     lMtz1Tmr = brCfgTbl.ownrBru.time_stageONUnit;   
  SetUstToClon(PRM1_COMP1,  1, MNGUST_PRM1_BV, lMtz1Tmr*10);

//выдержка формирователя блокировки Блока включения
     lMtz1Tmr = brCfgTbl.ownrBru.time_stageONCtrl;   
  SetUstToClon(PRM1_COMP1,  1, MNGVID_PRM1_BLOKIRBLOKVKL, lMtz1Tmr*10);

//выдержка формирователя удлинения блокировки Блока включения
     lMtz1Tmr = brCfgTbl.ownrBru.time_stageONUnitBlk;   
  SetUstToClon(PRM1_COMP1,  1, MNGVID_PRM1_DELAYBLOKIRBLOKVKL, lMtz1Tmr*10);


//установки ICI PRM1
  int uprPRM1 = 0;
    long lSt1 = brCfgTbl.state_FaultU_Ocp;//Неиспр цепей напр MTZ
  if(lSt1>0) uprPRM1 |= 1; // WKL
  else  uprPRM1 &= ~1; // OTKL 
  
//state_FaultU_Dstp
    lSt1 = brCfgTbl.state_FaultU_Dstp;//Неиспр цепей напр DZ
  if(lSt1>0) uprPRM1 |= 2; // WKL
  else  uprPRM1 &= ~2; // OTKL 

//задержка включения ВВ
    lSt1 = brCfgTbl.ownrBruMngStore.state_Delay_ON_Unit;
  if(lSt1>0) uprPRM1 |= 4; // WKL
  else  uprPRM1 &= ~4; // OTKL 

//блокировка Вкл ВВ общ
    lSt1 = brCfgTbl.ownrBruMngStore.state_Blk_SetON;
  if(lSt1>0) uprPRM1 |= 8; // WKL
  else  uprPRM1 &= ~8; // OTKL 

//Контроль ВВ
    lSt1 = brCfgTbl.ownrBruMngStore.state_CheckHVS;
  if(lSt1>0) uprPRM1 |= 16; // WKL
  else  uprPRM1 &= ~16; // OTKL 

//Ресурс ВВ
    lSt1 = brCfgTbl.ownrBruMngStore.state_ResourceHVS;
  if(lSt1>0) uprPRM1 |= 32; // WKL
  else  uprPRM1 &= ~32; // OTKL 

/*
//задержка включения ВВ
#define ENA_PRM1_ZADWKLVV   2
//блокировка Вкл ВВ общ
#define ENA_PRM1_BLOKWKLVV  3
//Контроль ВВ
#define ENA_PRM1_KONTROLVV  4
//Ресурс ВВ
#define ENA_PRM1_RESURSVV   5
//Очистить Ресурс ВВ
#define ENA_PRM1_RESETRESURSVV  6

*/
  SetUstToClon(PRM1_COMP1,  1, MNGUPR_PRM1, uprPRM1);//управление PRM1

}//SettingIci_PRM1()

/*
typedef struct BruDsc_TagIn
{

unsigned short time_stageOFFUnit;  //выдержка формирователя Блока отключения
unsigned short time_stageONUnit;   //выдержка формирователя Блока включения
unsigned short time_stageONCtrl;   //выдержка формирователя блокировки Блока включения
unsigned short time_stageONUnitBlk;//выдержка формирователя удлинения блокировки Блока включения
unsigned short time_ActuatorHVS;   //T привод ВВ
//////////////////////////////////////////////////////////////////////////////////////////
unsigned char state_Delay_ON_Unit;//Задержка вкл.
unsigned char state_Blk_SetON;    //Блокировка вкл ВВ общ   

}BruDsc;

typedef struct BruMngStoreDsc_TagIn
{

//////////////////////////////////////////////////////////////////////////////////////////
unsigned char state_Delay_ON_Unit;//Задержка вкл.
unsigned char state_Blk_SetON;    //Блокировка вкл ВВ общ   

unsigned char state_CheckHVS;     //Контроль ВВ
unsigned char state_ResourceHVS; //Ресурс   ВВ
}BruMngStoreDsc;

BruMngStoreDsc ownrBruMngStore;

RclrMngStoreDsc   ownrRclrMng;//АПВ
BrfMngStoreDsc    ownrBrfMng; //УРОВ
BruDsc    ownrBru; //

*/
