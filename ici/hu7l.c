/*------------------------------------------------------------------------------
* Copyright (c) 2013 - Factory “KyivPrylad”
* 
* Permission to use, copy, modify, and distribute this software for any
* purpose with or without fee is hereby granted, provided that the above
* copyright notice and this permission notice appear in all copies.
* 
* THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
* WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
* ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
* WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
* ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
* 
*------------------------------------------------------------------------------
*
* Processor       : Lpc_3240
* File Name       : u7l.c
* Description     : Functions and Data for Low Level Communication,
                    BO BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  02/09/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/


//.#include "lpc32xx_chip.h"
//.#include "phy3250_board.h"
//.#include "lpc32xx_timer_driver.h"
//.#include "lpc32xx_intc_driver.h"
//.#include "lpc32xx_gpio_driver.h"
//.#include "lpc32xx_clkpwr_driver.h"
//.#include "lpc32xx_hsuart_driver.h"
//.#include "lpc32xx_uart.h"


#include "../LIB/CDL_AV0/lpc/include/lpc_types.h"
#include "../LIB/CDL_AV0/lpc/include/lpc_irq_fiq.h"
#include "../LIB/CDL_AV0/lpc/include/lpc_arm922t_cp15_driver.h"
//
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_hsuart_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_intc_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_timer_driver.h"


/* Prototype for external IRQ handler */
void lpc32xx_irq_handler(void);
extern unsigned char chEntry_Hs7;
extern unsigned char chHdwErorHSU7;
/* HSUART device handles */
 INT_32 hs7uartdev = 0;
 INT_32 hsuartdev = 0;
static UNS_8 hs7_txbuff [512], hs7_rxbuff [512];
volatile  int hs7_txsize = 0, hs7_rxsize = 0;

 int hs7_txfill  = 0;
 int hs7_rxget   = 0; 
 int hs7_txget   = 0;
 int hs7_rxfill  = 0;

void foo7(void)
{
	hs7_txfill = hs7_txget = hs7_rxfill = 
	hs7_rxget = hs7_txsize = hs7_rxsize = 0;

}
/***********************************************************************
 *
 * Function: term_dat_send_cb
 *
 * Purpose: HS UART transmit data callback
 *
 * Processing:
 *     Move data from the ring buffer to the driver.
 *
 * Parameters: None
 *
 * Outputs: None
 *
 * Returns: Nothing
 *
 * Notes: This function is called in interrupt context.
 *
 **********************************************************************/
//.void term_dat_send_cb(void)
//.{
//.  INT_32 bwrite, tosend = 512 - txget;
//.  HSUART_CFG_T *phsuart = (HSUART_CFG_T *) hsuartdev;
//.
//.  if (tosend > txsize)
//.  {
//.    tosend = txsize;
//.  }
//.
//.  if (tosend == 0)
//.  {
//.    phsuart->regptr->ctrl &= ~HSU_TX_INT_EN;
//.  }
//.  else
//.  {
//.    phsuart->regptr->ctrl |= HSU_TX_INT_EN;
//.  }
//.
//.  /* Write data */
//.  bwrite = hsuart_write(hsuartdev, &txbuff[txget], tosend);
//.  txsize = txsize - bwrite;
//.  txget = txget + bwrite;
//.  if (txget >= 512)
//.  {
//.    txget = 0;
//.  }
//.
//.}

/***********************************************************************
 *
 * Function: term_dat_recv_cb
 *
 * Purpose: HS UART receive data callback
 *
 * Processing:
 *     Read data from the driver into the RX ring buffer.
 *
 * Parameters: None
 *
 * Outputs: None
 *
 * Returns: Nothing
 *
 * Notes:
 *     Ring buffer overflow is not accounted for in this application.
 *     This function is called in interrupt context.
 *
 **********************************************************************/
 
//.void term_dat_recv_cb(void)
//.{
//.  INT_32 bread, toreadmax = 512 - rxfill;
//.
//.  /* Read data */
//.  bread = hsuart_read(hsuartdev, &rxbuff[rxfill], toreadmax);
//.  rxsize = rxsize + bread;
//.  rxfill = rxfill + bread;
//.  if (rxfill >= 512)
//.  {
//.    rxfill = 0;
//.  }
//.}

/***********************************************************************
 *
 * Function: term_dat_out
 *
 * Purpose: Send some data on the terminal interface
 *
 * Processing:
 *     Place data into the TX ring buffer and start HS UART transmission.
 *
 * Parameters:
 *     dat   : Data to send
 *     bytes : Number of bytes to send
 *
 * Outputs: None
 *
 * Returns: Nothing
 *
 * Notes: Will block until all bytes are sent.
 *
 **********************************************************************/
//.void term_dat_out(UNS_8 *dat, int bytes)
//.{
//.  while (bytes > 0)
//.  {
//.    while ((bytes > 0) && (txsize < 512))
//.    {
//.      txbuff[txfill] = *dat;
//.      txfill++;
//.      if (txfill >= 512)
//.      {
//.        txfill = 0;
//.      }
//.      dat++;
//.      bytes--;
//.      int_disable(IRQ_UART_IIR2);
//.      txsize++;
//.      int_enable(IRQ_UART_IIR2);
//.    }
//.
//.    int_disable(IRQ_UART_IIR2);
//.    term_dat_send_cb();
//.    int_enable(IRQ_UART_IIR2);
//.  }
//.}

/***********************************************************************
 *
 * Function: term_dat_in
 *
 * Purpose: Read some data from the terminal interface
 *
 * Processing:
 *     Move data from the ring buffer to the passed buffer.
 *
 * Parameters:
 *     buff  : Where to place the data
 *     bytes : Number of bytes to read
 *
 * Outputs: None
 *
 * Returns: Number of bytes actually read
 *
 * Notes: None
 *
 **********************************************************************/
//.int term_dat_in(UNS_8 *buff, int bytes)
//.{
//.  int bread = 0;
//.
//.  while ((bytes > 0) && (rxsize > 0))
//.  {
//.    *buff = rxbuff[rxget];
//.    buff++;
//.    rxget++;
//.    if (rxget >= 512)
//.    {
//.      rxget = 0;
//.    }
//.    bytes--;
//.    bread++;
//.    int_disable(IRQ_UART_IIR2);
//.    rxsize--;
//.    int_enable(IRQ_UART_IIR2);
//.  }
//.
//.  return bread;
//.}

/*

char chI; 

 INT_32 uartdev = 0;
static UNS_8 txbuff [512], rxbuff [512];
volatile static int txsize, rxsize;
static int txfill = 0;
static int rxget  = 0;
static int txget  = 0;
static int rxfill = 0;
void foo(void)
{
	txfill = txget = rxfill = rxget = txsize = rxsize = 0;

}*/
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void hs7_recv_cb(void)  @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose: Read some data from the terminal interface                        ~~~
//~~~ Processing: Move data from the ring buffer to the passed buffer            ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Returns: Number of bytes actually read                                      ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
void hs7_recv_cb(void)  @ "Fast_function"
{
  INT_32 bread, toreadmax = 512 - hs7_rxfill;

  /* Read data */
  //bread = uart_read(uartdev, &rxbuff[rxfill], toreadmax);
  bread = hs_uart_read( hs7uartdev, &hs7_rxbuff[hs7_rxfill], toreadmax);
  
  hs7_rxsize = hs7_rxsize + bread;
  hs7_rxfill = hs7_rxfill + bread;
  if (hs7_rxfill >= 512)
  {
    hs7_rxfill = 0;
  }
}

//---------------------------------------------------------------------------------
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void hs7_send_cb(void)  @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose: Read some data from the terminal interface                        ~~~
//~~~ Processing: Move data from the ring buffer to the passed buffer            ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Returns: Number of bytes actually read                                      ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================

void hs7_send_cb(void)  @ "Fast_function"
{
  INT_32 bwrite, tosend = 512 - hs7_txget;
  HSUART_CFG_T *phsuart = (HSUART_CFG_T *)  hs7uartdev;//hsuartdev;
  if (tosend > hs7_txsize)
  {
    tosend = hs7_txsize;
  }
  if (tosend == 0)
  {
    phsuart->regptr->ctrl &= ~HSU_TX_INT_EN;
  }
  else
  {
    phsuart->regptr->ctrl |= HSU_TX_INT_EN;
  }

  /* Write data */
  bwrite = hs_uart_write( hs7uartdev, &hs7_txbuff[hs7_txget], tosend);//hsuartdev
  hs7_txsize = hs7_txsize - bwrite;
  hs7_txget  = hs7_txget + bwrite;
  if (hs7_txget >= 512)
  {
    hs7_txget = 0;
  }

}
//---------------------------------------------------------------------------------
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void hs7_rxerr_cb(void)  @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose: Read some data from the terminal interface                        ~~~
//~~~ Processing: Move data from the ring buffer to the passed buffer            ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Returns: Number of bytes actually read                                      ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
void hs7_rxerr_cb(void)  @ "Fast_function"
{
  //.INT_32 bread, toreadmax = 512 - hs7_rxfill;
HSUART_CFG_T* pHs_uart_dat = (HSUART_CFG_T* )hs7uartdev;//hs_uart_dat[2];
register unsigned long i;
  /* Read data */
  i = pHs_uart_dat->regptr->iir;
  if (i|(HSU_RX_OE_INT))
  {
     pHs_uart_dat->regptr->iir = HSU_RX_OE_INT;
  }
  if (i|(HSU_BRK_INT))
  {
     pHs_uart_dat->regptr->iir = HSU_BRK_INT;
  }
  if (i|(HSU_FE_INT))
  {
     pHs_uart_dat->regptr->iir = HSU_FE_INT;
  }
  
  while ((pHs_uart_dat->regptr->level & 0xFF) != 0)
  {
    //i =	pregs->txrx_fifo;
	i =	pHs_uart_dat->regptr->txrx_fifo;
  }
  //bread = uart_read(uartdev, &rxbuff[rxfill], toreadmax);
  
  //.bread = hs_uart_read(hsuartdev, &hs7_rxbuff[hs7_rxfill], toreadmax);
  //.hs7_rxsize = hs7_rxsize + bread;
  //.hs7_rxfill = hs7_rxfill + bread;
  //.if (hs7_rxfill >= 512)
  //.{
  //.  hs7_rxfill = 0;
  //.}
  
  hs7_txfill = hs7_txget = hs7_rxfill = 
  hs7_rxget = hs7_txsize = hs7_rxsize = 0;
}

//---------------------------------------------------------------------------------
//Transmit 60 Byte
//Receve 60 Biytea
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long outU7(UNS_8 *dat, int bytes)  @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:  Send some data on the terminal interface                         ~~~
//~~~ Processing: Place data into the TX ring buffer and start UART transmission ~~~
//~~~        ~~~
//~~~  dat   : Data to send                                                      ~~~
//~~~  bytes : Number of bytes to send                                           ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Notes: Will block until all bytes are sent                                  ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================

long outU7(UNS_8 *dat, int bytes)  @ "Fast_function"
{
    if (hs7_txsize>bytes)
  {
	return 0;//Stop Do Something
  }
  disable_irq();
  if ((hs7_txfill == hs7_txget)&&(hs7_txsize==0))
  hs7_txget = hs7_txfill = 0;//.!!!
  enable_irq();
  
  while (bytes > 0)
  {
    while ((bytes > 0) && (hs7_txsize < 512))
    {
      hs7_txbuff[hs7_txfill] = *dat;
      hs7_txfill++;
      if (hs7_txfill >= 512)
      {
        hs7_txfill = 0;
      }
      dat++;
      bytes--;
      disable_irq();//int_disable(IRQ_UART_IIR7);
      hs7_txsize++;
      enable_irq();//int_enable(IRQ_UART_IIR7);
    }

     disable_irq();//int_disable(IRQ_UART_IIR7);
    //.term_dat_send_cb();
	hs7_send_cb();
    enable_irq();//int_enable(IRQ_UART_IIR7);
  }
  return 0;
}
//---------------------------------------------------------------------------------
extern INT_32 hs7uartdev;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long inU7(UNS_8 *buff, int bytes)  @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose: Read some data from the terminal interface                        ~~~
//~~~ Processing: Move data from the ring buffer to the passed buffer            ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Returns: Number of bytes actually read                                      ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
long inU7(UNS_8 *buff, int bytes)  @ "Fast_function"
{

int bread = 0;

  while ((bytes > 0) && (hs7_rxsize > 0))
  {
    *buff = hs7_rxbuff[hs7_rxget];
    buff++;
    hs7_rxget++;
    if (hs7_rxget >= 512)
    {
      hs7_rxget = 0;
    }
    bytes--;
    bread++;
    disable_irq();//int_disable(IRQ_UART_IIR7);
    hs7_rxsize--;
    enable_irq();//int_enable(IRQ_UART_IIR7);
  }
  if (hs7_rxfill == hs7_rxget)
  {
	disable_irq();//int_disable(IRQ_UART_IIR7);
	hs7_rxfill = hs7_rxget = 0;
	enable_irq();//int_enable(IRQ_UART_IIR7);
  }
  if(chHdwErorHSU7)
  {
    Int_disableGen(IRQ_UART_IIR7);//int_disable(IRQ_UART_IIR7);
    int_clear(IRQ_UART_IIR7);
	chHdwErorHSU7 = 0;
    bytes = hs_uart_recover(hs7uartdev);
  }
//MIC-> er |= 1<<IRQ_UART_IIR7;
Int_enableGen(IRQ_UART_IIR7);//int_enable(IRQ_UART_IIR7);
  return bread;
	
	
}
//---------------------------------------------------------------------------------

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void hs7_eof_cb(void)  @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:                          ~~~
//~~~ Processing:                       ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                                             ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
void hs7_eof_cb(void) @ "Fast_function"
{

//HSUART_CFG_T *phsuart = (HSUART_CFG_T *) hs7uartdev;

//if need Start Process of Analises

//hs7_rxfill = hs7_rxget = hs7_rxsize = 0;
	chEntry_Hs7++;
	//MIC-> er &= ~tmp;
}
//---------------------------------------------------------------------------------
__root __ramfunc int foo_wef(void)
{
  static int x = 0;
  return x++;
}



/* EOF */
