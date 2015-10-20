#include "../LIB/CDL_AV0/lpc/include/lpc_types.h"
#include "../LIB/CDL_AV0/lpc/include/lpc_irq_fiq.h"
#include "../LIB/CDL_AV0/lpc/include/lpc_arm922t_cp15_driver.h"
//#include "ea3250_board.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_uart_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_intc_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_timer_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_clkpwr_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_ssp_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_gpio_driver.h"

extern void Rst_LpduHSU2_TpCnState(void);
extern long ssp1_hdr_init(void);
void M16_J18_K18_A15_PioInit(void);

extern void recv_cb(void);
extern void send_cb(void);
extern long uartdev;
extern UNS_8 txbuff [512], rxbuff [512];
extern int txsize, rxsize;
extern int txfill, rxget, txget, rxfill;

extern  int AppReqTransmitTotVerInfoBrBs;



INT_32 timer0dev = 0;

//static INT_32 uartdev;
//static UNS_8 txbuff [512], rxbuff [512];
//volatile static int txsize, rxsize;
//static int txfill, rxget, txget, rxfill;
extern void hs7_uart_hdw_init(void);
extern void hs1_uart_hdw_init(void);
extern void hs2_uart_hdw_init(void);
void P02Int(void);
extern UNS_32 Timer_usec_to_val(CLKPWR_CLK_T clknum, UNS_32 usec);
BOOL_32 Int_install_ext_irq_handler(INTERRUPT_SOURCE_T source,
                                    PFV func_ptr,
                                    INTERRUPT_TYPE_T type,
                                    int high);
STATUS Timer_ioctl(INT_32 devid,
                   INT_32 cmd,
                   INT_32 arg);									
									
BOOL_32 Int_clear(INTERRUPT_SOURCE_T source);


void timer0_user_interrupt(void);





void ici_hdw_init(void)
{
//register long i;

UART_CBS_T cbs;
UART_CONTROL_T ucntl;

//- typedef enum
//- {
//-   UART_PAR_NONE,
//-   UART_PAR_EVEN,
//-   UART_PAR_ODD
//- } UART_PAR_T;
//- 
//- /* UART control */
//- typedef struct
//- {
//-   UNS_32 baud_rate;     /* Device baud rate */
//-   UART_PAR_T parity;    /* Parity selection */
//-   UNS_32 databits;      /* Number of data bits */
//-   UNS_32 stopbits;      /* Number of stop bits */
//- } UART_CONTROL_T;

timer0dev = Timer_open(TIMER_CNTR0, 0);
TIMER_CNTR_REGS_T *pTimer = TIMER_CNTR0;
/*
 //-* Reset timer *-/
  pTimer->tcr = TIMER_CNTR_TCR_RESET;
  pTimer->tcr = 0;
  
   //-* Count mode is PCLK edge *-/
  pTimer->ctcr = TIMER_CNTR_SET_MODE(TIMER_CNTR_CTCR_TIMER_MODE);

  //-* Set prescale counter value for a 1uS tick *-/
  pTimer->pr = (UNS_32) Timer_usec_to_val(
                 CLKPWR_TIMER0_CLK, 1);
				 
	//case TMR_VALUE_ST:
    //          status = pTimer->tc;
    //          break;			 
  //-* Enable the timer *-/
  pTimer->tcr = TIMER_CNTR_TCR_EN;

  //-* Stop timer *-/
  //pTimer->tcr = 0;
*/
//Init Module New

 //-* Enable timer system clock *-/
  //.clkpwr_clk_en_dis(timer_num_to_clk_enum[timernum], 1);

  //-* Reset timer *-/
  pTimer->tcr = TIMER_CNTR_TCR_RESET;
  pTimer->tcr = 0;pTimer->tc  = 0;

  //-* Clear and enable match function *-/
  pTimer->ir = TIMER_CNTR_MTCH_BIT(0);

  //-* Count mode is PCLK edge *-/
  pTimer->ctcr = TIMER_CNTR_SET_MODE(TIMER_CNTR_CTCR_TIMER_MODE);

  //-* Set prescale counter value for a 1uS tick *-/
  pTimer->pr = (UNS_32) Timer_usec_to_val(
                 CLKPWR_TIMER0_CLK, 1);

  //-* Set match for number of usecs *-/
  pTimer->mr[0] = 20000;//-usec;

  //-* Interrupt on match 0 *-/
  pTimer->mcr = TIMER_CNTR_MCR_MTCH(0)|TIMER_CNTR_MCR_RESET(0);	

   //-* Install timer interrupts handlers as a IRQ interrupts *-/
  int_install_irq_handler(IRQ_TIMER0, (PFV) timer0_user_interrupt);








//~  ucntl.baud_rate = 115200;
//~  ucntl.parity = UART_PAR_NONE;
//~  ucntl.databits = 8;
//~  ucntl.stopbits = 1;
//~  uartdev = Uart_open((void *) UART3, (INT_32) & ucntl);
//~  if (uartdev != 0)
//~  {
//~    /* Setup RX and TX callbacks */
//~    cbs.rxcb = recv_cb;
//~    cbs.txcb = send_cb;
//~    cbs.rxerrcb = NULL;
//~    Uart_ioctl(uartdev, UART_INSTALL_CBS, (INT_32) &cbs);
//~    //.int_enable(IRQ_UART_IIR3);
//~  }
//~
//~  /* Initialize TX and RX ring buffers */
//~  //txfill = txget = rxfill = rxget = txsize = rxsize = 0;
//~  Rst_LpduHSU2_TpCnState();
//~  /* Enable interrupts */
//~  int_enable(IRQ_UART_IIR3);
//~  hs7_uart_hdw_init();
//~  hs1_uart_hdw_init();
//~  hs2_uart_hdw_init();
//~  
//~  enable_irq();
//~  //int_enable(IRQ_UART_IIR7);
//~  int_enable(IRQ_UART_IIR1);
//~  int_enable(IRQ_UART_IIR2);
   ssp1_hdr_init();
Rst_LpduM2m_TpCnState();
Rst_LpduSpi_TpCnState();
   GPIO->p0_mux_clr = 0xff;
  GPIO->p0_dir_clr = 0xff;   
  GPIO->p0_dir_set = 0xf0;   
  GPIO->p0_outp_clr =0xf0;
  M16_J18_K18_A15_PioInit();

  //p3_outp_state
 
AppReqTransmitTotVerInfoBrBs = 1;
  
  Int_install_ext_irq_handler(IRQ_GPIO_01,P02Int,FALLING_EDGE,0);//Interrupt in this place never can be workd look p606 datasheet - Only pin sic[8] activated
  Int_install_ext_irq_handler(IRQ_P0_P1_IRQ,P02Int,FALLING_EDGE,0);
  
  CLKPWR ->clkpwr_p01_er = CLKPWR_INTSRC_GPIO_01_BIT;// *((long*)0x40004018) |= 2;
  
	  Int_enable(IRQ_GPIO_01);
	  Int_enable(IRQ_P0_P1_IRQ);
  MIC->er |= (1<<(IRQ_SUB2IRQ));
  
 //~^  pTimer->tcr = TIMER_CNTR_TCR_EN;//timer_ioctl(timer0dev, TMR_ENABLE, 1);
 //~^ int_enable(IRQ_TIMER0);
  
  
}
//extern unsigned char chMemCY7;
extern void CY7_rv_cb(void);



void P02Int(void)
{
//SIC2->rsr |= (1<<(8)); //Clear Sic2 RSR IRQ_P0_P1_IRQ ||Bit->.8.<  <-Pn_GPIO ALL Port 0 and Port 1 GPIO pins OR’ed.
Int_clear(IRQ_P0_P1_IRQ);
CY7_rv_cb();//chMemCY7++;
return;
}
void M16_J18_K18_A15_PioInit(void)
{
//Init GPO23 - M16
   UARTCNTL->ctrl &= ~(UART_U3_MD_CTRL_EN);//0x40054000
  GPIO->p3_outp_clr = (1<<23); 
  //Init GPI16 - J18
  
  //Init GPI17 - K18
  
 //Init GPO7 - A15
  GPIO->p3_outp_clr = (1<<7);

}





/*

speculative

: based on guesses or ideas about what might happen or be true rather than on facts

: tending to think about what might happen or be true : tending to speculate

: showing curiosity or uncertainty

Speculative - Merriam-Webster.com


*/

void timer0_user_interrupt(void)
{
  //--* Clear latched timer interrupt *--/
  //-* Reset timer *-/
  TIMER_CNTR_REGS_T *pTimer = TIMER_CNTR0;
  pTimer->tcr = TIMER_CNTR_TCR_RESET;
  Int_clear(IRQ_TIMER0);
 // Timer_ioctl(timer0dev, TMR_CLEAR_INTS, TIMER_CNTR_MTCH_BIT(0));
  

}









