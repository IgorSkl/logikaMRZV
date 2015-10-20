#include "../LIB/CDL_AV0/lpc/include/lpc_types.h"
#include "../LIB/CDL_AV0/lpc/include/lpc_irq_fiq.h"
#include "../LIB/CDL_AV0/lpc/include/lpc_arm922t_cp15_driver.h"
//#include "ea3250_board.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_uart_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_intc_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_timer_driver.h"


extern void recv_cb(void);
extern void send_cb(void);
extern long uartdev;
extern UNS_8 txbuff [512], rxbuff [512];
extern int txsize, rxsize;
extern int txfill, rxget, txget, rxfill;

//static INT_32 uartdev;
//static UNS_8 txbuff [512], rxbuff [512];
//volatile static int txsize, rxsize;
//static int txfill, rxget, txget, rxfill;

#ifdef  COMMENT

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





  ucntl.baud_rate = 115200;
  ucntl.parity = UART_PAR_NONE;
  ucntl.databits = 8;
  ucntl.stopbits = 1;
  uartdev = Uart_open((void *) UART3, (INT_32) & ucntl);
  if (uartdev != 0)
  {
    /* Setup RX and TX callbacks */
    cbs.rxcb = recv_cb;
    cbs.txcb = send_cb;
    cbs.rxerrcb = NULL;
    Uart_ioctl(uartdev, UART_INSTALL_CBS, (INT_32) &cbs);
    int_enable(IRQ_UART_IIR3);
  }

  /* Initialize TX and RX ring buffers */
  //txfill = txget = rxfill = rxget = txsize = rxsize = 0;

  /* Enable interrupts */
  int_enable(IRQ_UART_IIR3);

  enable_irq();


}
#endif
