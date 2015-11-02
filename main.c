#include "libraries.h"
#include "constants.h"
#include "type_definition.h"
#include "macroses_privat.h"
#include "variables_global.h"
#include "functions_global.h"

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

#include "psuperVisor\supermanager.h"

#include "callbackelement\callbackelementdef.h"

#include "logictimers\logictimersfnc.h"
#include "callbackelement\callbackelementfnc.h"

extern UNS_32 *WideLogActual;//командный массив расшир логики
extern UNS_32 pActualCMD[];//текущие плюс расшир логика

void start_settings(void);
void  InitializeInterruptSystem();
void hstimer_user_interrupt(void);

// Prototype for external IRQ handler
void lpc32xx_irq_handler(void);

HSTIMER_REGS_T *hst_regptr;  // Pointer to HSTIMER registers
SSP_REGS_T     *ssp1_regptr; // Pointer to SSP1 registers
GPIO_REGS_T    *gpio_regptr; // Pointer to GPIO registers

int timing = 0;  
int timingLoad = 0;  
int cicling = 0;  

int GlobalPO1  = 0;
int GlobalPO2  = 0;
int GlobalPO3  = 0;
int GlobalPO4 = 0;

int trigReg  = 0;//заполнить рег

int GlobalLevel[3] = {0, 0, 0};
int GlobalLevelI_ABC[3]  = {70, 70, 70};
int GlobalLevelUL_ABC[3] = {70, 70, 70};
int GlobalLevelUF_ABC[3] = {70, 70, 70};
int GlobalLevel_UCM;
int GlobalLevel_ICM;
int GlobalLevel_ULAPV;
int GlobalLevel_3I0;
int GlobalLevel_3U0;

UNS_32 rawDVLow;//сырые ДВ
UNS_32 rawDVMidd;//сырые ДВ
UNS_32 rawDVHi;//сырые ДВ
UNS_32 oldDV1,  oldDV2,  oldDV3,  oldDV4,  oldDV5,  oldDV6;
UNS_32 oldDV7,  oldDV8,  oldDV9,  oldDV10, oldDV11, oldDV12;//сырые ДВ
UNS_32 oldDV13, oldDV14, oldDV15, oldDV16;

UNS_32 oldDV17,  oldDV18,  oldDV19,  oldDV20,  oldDV21,  oldDV22;
UNS_32 oldDV23,  oldDV24,  oldDV25,  oldDV26,  oldDV27,  oldDV28;//сырые ДВ
UNS_32 oldDV29,  oldDV30,  oldDV31,  oldDV32;

UNS_32 oldDV33,  oldDV34,  oldDV35,  oldDV36;
int acdcDV;//флаг пост перем для ДВ

char stringList[48][32];//массив строк для просмотра

void ici_hdw_init(void);

/*************************************************************************
 * Function Name: main
 * Parameters: none
 *
 * Return: none
 *
 * Description: main
 *
 *************************************************************************/
int main(void)
{
  //total_data_send.diagnostyka = 0;
 // long lResDiag;
#ifdef _STATIC_MEMORY_BOOT
  /************************************************************/
  //Перевірка контрольної суми програми
  /************************************************************/
  {
    unsigned short sum = 0;
    unsigned char *point = ((unsigned char *)&__checksum_begin);
    for (unsigned int i = ((unsigned int)&__checksum_end -(unsigned int)&__checksum_begin +1); i > 0; i--)
      sum += *point++;
    if (sum != (unsigned short)__checksum)
    {
      if (sum != (unsigned short)__checksum) _SET_STATE(resurs_diagnostica, ERROR_EXTERNAL_FLASH_MEMORY_BIT);
      while(1);
    }
  }
  /************************************************************/
#endif
 // if (external_SRAM_OK != EXTERNAL_SRAM_OK)
//    _SET_STATE(total_data_send.diagnostyka, ERROR_EXTERNAL_SRAM_BIT);

  start_settings();

  ici_hdw_init();//инит межпроцессорного обмена

  while(1)
  {
#ifdef _STATIC_MEMORY_BOOT

    /*if ((periodical_tasks & TASK_TEST_FLASH_MEMORY) != 0)*/
    {
      /************************************************************/
      //Перевірка контрольної суми програми
      /************************************************************/
      unsigned short sum = 0;
      unsigned char *point = ((unsigned char *)&__checksum_begin);
      for (unsigned int i = ((unsigned int)&__checksum_end -(unsigned int)&__checksum_begin +1); i > 0; i--)
      {
        sum += *point++;
        periodical_operations();
      }
      if (sum != (unsigned short)__checksum) _SET_STATE(resurs_diagnostica, ERROR_EXTERNAL_FLASH_MEMORY_BIT);
      else _CLEAR_STATE(resurs_diagnostica, ERROR_EXTERNAL_FLASH_MEMORY_BIT);
      /************************************************************/

//      periodical_tasks &= (unsigned int)(~TASK_TEST_FLASH_MEMORY);
    }
    /*else*/ periodical_operations();
#else
    periodical_operations();
#endif
  }

  //c_entry();
//  return 0;

//  start_settings();

//  hsuart_send_data();

  // main loop
//  restart_resurs_count = 0xff;
} // main(void)

void start_settings(void)
{
  // Init MMU
  CP15_Mmu(FALSE);            // Disable MMU
  // Privileged permissions  User permissions AP
  // Read-only               Read-only        0
  CP15_SysProt(FALSE);
  CP15_RomProt(TRUE);
  CP15_InitMmuTtb(TtSB,TtTB); // Build L1 and L2 Translation tables
  CP15_SetTtb(L1Table);       // Set base address of the L1 Translation table
  CP15_SetDomain( (DomainManager << 2*1) | (DomainClient << 0)); // Set domains
  CP15_Mmu(TRUE);             // Enable MMU
  CP15_Cache(TRUE);           // Enable ICache,DCache

  /* Disable interrupts in ARM core */
  disable_irq_fiq();

  InitializeInterruptSystem();

  // Enable IRQ interrupts in the ARM core
  enable_irq_fiq();

  initCallBackElement();//инит callBackElement
  initTimers();//инит таймеров
  initTimers_WL();//TIMERS INIT РЛ

  WideLogActual = &(pActualCMD[DQUADRO]);//командный массив расшир логики(вторая половина)

  ResetSystemMenu();//сбросить сист меню
   
  timing = 0;  

}//start_settings(void)

/**********************************************
ИНИЦИАЛИЗАЦИЯ СИСТЕМЫ ПРЕРЫВАНИЙ
**********************************************/
void  InitializeInterruptSystem()
{
  /* Initialize interrupt system */
  int_initialize(0xFFFFFFFF);

  /* Install standard IRQ dispatcher at ARM IRQ vector */
  int_install_arm_vec_handler(IRQ_VEC, (PFV) lpc32xx_irq_handler);
  /* Install standard FIQ dispatcher at ARM IRQ vector */
  int_install_arm_vec_handler(FIQ_VEC, (PFV) lpc32xx_fiq_handler);

//---------------------HSTIMER------------------------------------
  /* Install HSTIMER interrupt handler as a IRQ interrupts */
  int_install_irq_handler(IRQ_HSTIMER,
                          (PFV) hstimer_user_interrupt);


  // Save address of register block
  hst_regptr  = HSTIMER;
  gpio_regptr = GPIO;

  // LEDs off
  //gpio_regptr->p3_outp_clr = LED1 | LED2;
  //gpio_regptr->p1_dir_set = LED3;

  // Enable timer system clock
  clkpwr_clk_en_dis(CLKPWR_HSTIMER_CLK, 1);

  // Disable high speed timer and match timers
  hst_regptr->hstim_ctrl = HSTIM_CTRL_RESET_COUNT;
  hst_regptr->hstim_mctrl = 0;
  hst_regptr->hstim_ctrl = 0;

  // Clear pending interrupts
  hst_regptr->hstim_int = (HSTIM_MATCH0_INT |
                           HSTIM_MATCH1_INT | HSTIM_MATCH2_INT |
                           HSTIM_GPI_06_INT | HSTIM_RTC_TICK_INT);

  hst_regptr->hstim_mctrl = HSTIM_CNTR_MCR_MTCH(0) | HSTIM_CNTR_MCR_RESET(0);
  hst_regptr->hstim_pmatch = 13-1;
  hst_regptr->hstim_match[0] = 1000;//1ms 000;

  hst_regptr->hstim_ctrl = HSTIM_CTRL_COUNT_ENAB;//start hstimer

  // Enable interrupt in the interrupt controller
  int_enable(IRQ_HSTIMER);

//---------------------SSP1------------------------------------
  ssp1_regptr = SSP1; // Pointer to SSP1 registers
  // Enable ssp1 system clock
  clkpwr_clk_en_dis(CLKPWR_SSP1_CLK, 1);
  //конфигурация IO
  gpio_regptr->p2_mux_clr = P2_GPIO04_SSEL1;
  gpio_regptr->p2_dir_set = P2_DIR_GPIO(4);
  gpio_regptr->p3_outp_set = P3_STATE_GPIO(4);

  /* The MISO, MOSI, and SCK signals are controlled by the SSP1 */
  gpio_regptr->p_mux_set = (P_SPI2DATAIO_MOSI1 |
                            P_SPI2DATAIN_MISO1 | P_SPI2CLK_SCK1);

  ssp1_regptr->cpsr = SSP_CPSR_CPDVSR(16);//8);//4);//4);//prescale
  //ssp_clk / ((cr0_div + 1) * prescale);
  //prescale = 16; SCR = 4 - 1.25MGz
  ssp1_regptr->cr0 = SSP_CR0_DSS(8) |//data size 8 bit
                     SSP_CR0_FRF_SPI |//Motorola SPI mode
                     SSP_CR0_SCR(4);//serial clock rate

  // Default Master mode
  // Disable SSP1
  ssp1_regptr->cr1 &= ~SSP_CR1_SSP_ENABLE;

  // interr handler SSP1 IRQ
  //int_install_irq_handler(IRQ_SSP1, (PFV) ssp1_user_interrupt);

  // Enable interrupt in the interrupt controller
  //int_enable(IRQ_SSP1);
  // Clear interrupt in the interrupt controller
  //int_clear(IRQ_SSP1);

  // Enable SSP1
  ssp1_regptr->cr1 |= SSP_CR1_SSP_ENABLE;

}//InitializeInterruptSystem()

void  LanderPStr(){}
void ResetPStr(){}
void ResetUpDown(){}
void LanderUpDown(){}
void  ResetAllButton(){}
void ListPStr(){}




