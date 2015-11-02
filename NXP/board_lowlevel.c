/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2006
 *
 *    File name   : iram_init.c
 *    Description : Low level init device code
 *
 *    History :
 *    1. Date        : December, 15 2006
 *       Author      : Stanimir Bonev
 *       Description : Create
 *
 *    $Revision: 30926 $
 **************************************************************************/
#include <intrinsics.h>
#include <NXP/iolpc3240.h>

extern void test_external_SRAM(void);

/*************************************************************************
 * Function Name: LowLevelInit
 * Parameters: none
 *
 * Return: none
 *
 * Description: This function is used for low level initialization
 *
 *************************************************************************/
void LowLevelInit(void)
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
  EMCStaticWaitRd0  = 7;       // EMCStaticWaitRd0
  EMCStaticWaitWr0  = 6;       // EMCStaticWaitWr0
  EMCStaticConfig0  = 0x82;     // EMCStaticConfig0
  EMCStaticWaitTurn0 = 4;

  EMCStaticWaitWen1 = 0;        // EMCStaticWaitWen1
  EMCStaticWaitOen1 = 0;        // EMCStaticWaitOen1
  EMCStaticWaitRd1  = 1;       // EMCStaticWaitRd1
  EMCStaticWaitWr1  = 1;       // EMCStaticWaitWr1
  EMCStaticConfig1  = 0x82;     // EMCStaticConfig1
  EMCStaticWaitTurn1 = 0;
  
  EMCStaticWaitWen2 = 0;   // EMCStaticWaitWen1
  EMCStaticWaitOen2 = 0;   // EMCStaticWaitOen1
  EMCStaticWaitRd2  = 3;   // EMCStaticWaitRd1
  EMCStaticWaitWr2  = 3;   // EMCStaticWaitWr1
  EMCStaticConfig2  = 0x81;// EMCStaticConfig1
  EMCStaticWaitTurn2 = 1;

  EMCStaticWaitWen3 = 4;        // EMCStaticWaitWen3
  EMCStaticWaitOen3 = 0;        // EMCStaticWaitOen3
  EMCStaticWaitRd3  = 0xf;      // EMCStaticWaitRd3
  EMCStaticWaitWr3  = 0xf;       // EMCStaticWaitWr3
  EMCStaticConfig3  = 0x80;//x82;     // EMCStaticConfig3
  EMCStaticWaitTurn3 = 10;
  
  BOOT_MAP_bit.MAP = 1;             // iRAM 0x00000000

  /**********************/
  //Тестуємо зовнішню SRAM
  /**********************/
  test_external_SRAM();
  /**********************/
  
  return;
}
