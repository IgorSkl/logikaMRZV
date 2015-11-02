#include "../LIB/CDL_AV0/lpc/include/lpc_types.h"
#include "../LIB/CDL_AV0/lpc/include/lpc_irq_fiq.h"
#include "../LIB/CDL_AV0/lpc/include/lpc_arm922t_cp15_driver.h"
//#include "ea3250_board.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_hsuart_driver.h"

#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_intc_driver.h"

#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_timer_driver.h"
long lTmrDisableHSU2 = 0;
long lDelta = 50;
long lDeltaTmrHSU2 = 500;
long lTmrHSU2Val = 0;
char chEndTransmitHSU2 = 0;
extern  INT_32 hsuartdev, hs2uartdev;
extern  UNS_8 hs2_txbuff [512], hs2_rxbuff [512];
extern int hs2_txsize, hs2_rxsize;
extern int hs2_txfill, hs2_rxget, hs2_txget, hs2_rxfill;
extern void hs2_recv_cb(void);
extern void hs2_send_cb(void);
extern void hs2_eof_cb(void);
extern void hs2_rxerr_cb(void);

void hs2_uart_hdw_init(void)
{
//register long i;


HSUART_CBS_T cbs;
HSUART_CONTROL_T hsucntl[3];
//. UNS_8 ch[16];

hsucntl[0].baud_rate = 921600;//115200;
hsucntl[0].cts_en	 = FALSE;
hsucntl[0].rts_en	 = FALSE;
disable_irq();
  /* Set UART3 to not use modem control pins */
  //.UARTCNTL->ctrl &= ~UART_U3_MD_CTRL_EN;

  hsuartdev = hs_uart_open((void *) UART2, (INT_32) & hsucntl[0]);
  if (hsuartdev != 0)
  {
    /* Setup RX and TX callbacks */
    cbs.rxcb    = hs2_recv_cb;//term_dat_recv_cb;
    cbs.txcb    = hs2_send_cb;//term_dat_send_cb;
    cbs.rxerrcb = hs2_rxerr_cb;
    cbs.eofcb   = hs2_eof_cb; 
    hs_uart_ioctl(hsuartdev, HSUART_INSTALL_CBS, (INT_32) &cbs);
	hs_uart_ioctl(hsuartdev, HSUART_CLEAR_FIFOS, 0);

    //..!! int_enable(IRQ_UART_IIR7);

    /* Initialize TX and RX ring buffers */
    hs2_txfill = hs2_txget = hs2_rxfill = 
    hs2_rxget = hs2_txsize = hs2_rxsize = 0;
	
	hs2uartdev = hsuartdev;

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
	int_clear(IRQ_UART_IIR2);
	//int_enable(IRQ_UART_IIR7);
  }




}