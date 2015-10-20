/*------------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*------------------------------------------------------------------------------
*
* Processor       : LPC3240
* File Name       : Hr1_lowlevel.c
* Description     : Functions Low level init device code
                     for MrzV - Hr1_0100_00_i660 startup 

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  02/08/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#include <intrinsics.h>
#include <NXP/iolpc3240.h>

#include "lpc_arm922t_cp15_driver.h"
#include "arm926ej_cp15_drv.h"
#include "lpc32xx_emc.h"
#include "lpc32xx_clkpwr_driver.h"
#include "lpc32xx_timer_driver.h"

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---
extern long __low_level_init(void);//
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~  Function Name: __low_level_init       ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//==================================================================================
//Body func                                                
//==================================================================================
long __low_level_init(void)
{
  // init clock
  SYSCLK_CTRL = 0x50<<2;
  // Set PER_CLK and HCLK dividers
  HCLKDIV_CTRL = 0x0000003D;
  // init H PLL
  HCLKPLL_CTRL = 0x0001601E;
  // Wait until PLL lock
  while(!HCLKPLL_CTRL_bit.PLL_LOCK);
  // Switch to PLL output and out form the self-refresh of the SDRAM
  __REG32 Reg  = PWR_CTRL;
  Reg &= ~((1 << 9) | (1 << 8));
  Reg |=   (1 << 2);
  PWR_CTRL = Reg;
  
  // Disable 397 PLL
  PLL397_CTRL_bit.PLL397_STATUS = 1;
  
  // Init EMC Controller
  EMCControl_bit.E = 1; // EMCControl - EMC Enable
  EMCConfig_bit.N = 0;  // EMCConfig - liitle endian
  SDRAMCLK_CTRL = 0;    // SDRAMCLK_CTRL
  
  EMCAHBControl0 = 0;   // EMCAHBControl0   
  EMCAHBControl2 = 0;   // EMCAHBControl2   
  EMCAHBControl3 = 0;   // EMCAHBControl3   
  EMCAHBControl4 = 0;   // EMCAHBControl4   
  
  EMCStaticExtendedWait = 0;    // EXTENDEDWAIT - 16 clock cycles (POR reset value)

  EMCStaticWaitWen0 = 0;        // EMCStaticWaitWen0
  EMCStaticWaitOen0 = 0;        // EMCStaticWaitOen0
  EMCStaticWaitRd0  = 19;       // EMCStaticWaitRd0
  EMCStaticWaitWr0  = 19;       // EMCStaticWaitWr0
  EMCStaticConfig0  = 0x81;     // EMCStaticConfig0

  EMCStaticWaitWen1 = 0;        // EMCStaticWaitWen1
  EMCStaticWaitOen1 = 0;        // EMCStaticWaitOen1
  EMCStaticWaitRd1  = 4;       // EMCStaticWaitRd1
  EMCStaticWaitWr1  = 4;       // EMCStaticWaitWr1
  EMCStaticConfig1  = 0x82;     // EMCStaticConfig1

  BOOT_MAP_bit.MAP = 1;             // iRAM 0x00000000
  
  return(1);
}


