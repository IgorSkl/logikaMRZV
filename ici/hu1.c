#include "../LIB/CDL_AV0/lpc/include/lpc_types.h"
#include "../LIB/CDL_AV0/lpc/include/lpc_irq_fiq.h"
#include "../LIB/CDL_AV0/lpc/include/lpc_arm922t_cp15_driver.h"
//#include "ea3250_board.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_hsuart_driver.h"

#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_intc_driver.h"

#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_timer_driver.h"


extern INT_32 hsuartdev, hs1uartdev;
extern  UNS_8 hs1_txbuff [512], hs1_rxbuff [512];
extern int hs1_txsize, hs1_rxsize;
extern int hs1_txfill, hs1_rxget, hs1_txget, hs1_rxfill;
extern void hs1_recv_cb(void);
extern void hs1_send_cb(void);
extern void hs1_eof_cb(void);
extern void hs1_rxerr_cb(void);

void hs1_uart_hdw_init(void)
{
//register long i;


HSUART_CBS_T cbs;
HSUART_CONTROL_T hsucntl[3];
//. UNS_8 ch[16];

hsucntl[0].baud_rate = 115200;
hsucntl[0].cts_en	 = FALSE;
hsucntl[0].rts_en	 = FALSE;
disable_irq();
  /* Set UART3 to not use modem control pins */
  //.UARTCNTL->ctrl &= ~UART_U3_MD_CTRL_EN;

  hsuartdev = hs_uart_open((void *) UART1, (INT_32) & hsucntl[0]);
  if (hsuartdev != 0)
  {
    /* Setup RX and TX callbacks */
    cbs.rxcb    = hs1_recv_cb;//term_dat_recv_cb;
    cbs.txcb    = hs1_send_cb;//term_dat_send_cb;
    cbs.rxerrcb = hs1_rxerr_cb;
    cbs.eofcb   = hs1_eof_cb; 
    hs_uart_ioctl(hsuartdev, HSUART_INSTALL_CBS, (INT_32) &cbs);
	hs_uart_ioctl(hsuartdev, HSUART_CLEAR_FIFOS, 0);

    //..!! int_enable(IRQ_UART_IIR7);

    /* Initialize TX and RX ring buffers */
    hs1_txfill = hs1_txget = hs1_rxfill = 
    hs1_rxget = hs1_txsize = hs1_rxsize = 0;
	
	hs1uartdev = hsuartdev;

    /* Loop returning the data from the terminal */
    //.term_dat_out(sendstr, sizeof(sendstr));
    //.ch[0] = 0;
    //.while (ch[0] != 27)
    //.{
    //.  if (term_dat_in(&ch[0], 16) > 0)
    //.  {
    //.    term_dat_out(&ch[0], 1);
    //.  }
    //.}
	int_clear(IRQ_UART_IIR1);
	//int_enable(IRQ_UART_IIR7);
  }




}