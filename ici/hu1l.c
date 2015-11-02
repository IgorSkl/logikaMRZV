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
* File Name       : u3l.c
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
extern unsigned char chEntry_Hs1;
extern unsigned char chHdwErorHSU1;
/* HSUART device handles */
 INT_32 hs1uartdev = 0;
 //INT_32 hsuartdev = 0;
static UNS_8 hs1_txbuff [512], hs1_rxbuff [512];
volatile  int hs1_txsize = 0, hs1_rxsize = 0;

 int hs1_txfill  = 0;
 int hs1_rxget   = 0; 
 int hs1_txget   = 0;
 int hs1_rxfill  = 0;

void foo1(void)
{
	hs1_txfill = hs1_txget = hs1_rxfill = 
	hs1_rxget = hs1_txsize = hs1_rxsize = 0;

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
void hs1_recv_cb(void)  @ "Fast_function";
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
void hs1_recv_cb(void)  @ "Fast_function"
{
  INT_32 bread, toreadmax = 512 - hs1_rxfill;

  /* Read data */
  //bread = uart_read(uartdev, &rxbuff[rxfill], toreadmax);
  bread = hs_uart_read( hs1uartdev, &hs1_rxbuff[hs1_rxfill], toreadmax);
  
  hs1_rxsize = hs1_rxsize + bread;
  hs1_rxfill = hs1_rxfill + bread;
  if (hs1_rxfill >= 512)
  {
    hs1_rxfill = 0;
  }
}

//---------------------------------------------------------------------------------
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void hs1_send_cb(void)  @ "Fast_function";
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

void hs1_send_cb(void)  @ "Fast_function"
{
  INT_32 bwrite, tosend = 512 - hs1_txget;
  HSUART_CFG_T *phsuart = (HSUART_CFG_T *)  hs1uartdev;//hsuartdev;
  if (tosend > hs1_txsize)
  {
    tosend = hs1_txsize;
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
  bwrite = hs_uart_write( hs1uartdev, &hs1_txbuff[hs1_txget], tosend);//hsuartdev
  hs1_txsize = hs1_txsize - bwrite;
  hs1_txget  = hs1_txget + bwrite;
  if (hs1_txget >= 512)
  {
    hs1_txget = 0;
  }

}
//---------------------------------------------------------------------------------
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void hs1_rxerr_cb(void)  @ "Fast_function";
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
void hs1_rxerr_cb(void)  @ "Fast_function"
{
  //.INT_32 bread, toreadmax = 512 - hs1_rxfill;
HSUART_CFG_T* pHs_uart_dat = (HSUART_CFG_T* )hs1uartdev;//hs_uart_dat[2];
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
  
  //.bread = hs_uart_read(hsuartdev, &hs1_rxbuff[hs1_rxfill], toreadmax);
  //.hs1_rxsize = hs1_rxsize + bread;
  //.hs1_rxfill = hs1_rxfill + bread;
  //.if (hs1_rxfill >= 512)
  //.{
  //.  hs1_rxfill = 0;
  //.}
  
  hs1_txfill = hs1_txget = hs1_rxfill = 
  hs1_rxget = hs1_txsize = hs1_rxsize = 0;
}

//---------------------------------------------------------------------------------
//Transmit 60 Byte
//Receve 60 Biytea
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long outU1(UNS_8 *dat, int bytes)  @ "Fast_function";
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

long outU1(UNS_8 *dat, int bytes)  @ "Fast_function"
{
    if (hs1_txsize>bytes)
  {
	return 0;//Stop Do Something
  }
  disable_irq();
  if ((hs1_txfill == hs1_txget)&&(hs1_txsize==0))
  hs1_txget = hs1_txfill = 0;//.!!!
  enable_irq();
  
  while (bytes > 0)
  {
    while ((bytes > 0) && (hs1_txsize < 512))
    {
      hs1_txbuff[hs1_txfill] = *dat;
      hs1_txfill++;
      if (hs1_txfill >= 512)
      {
        hs1_txfill = 0;
      }
      dat++;
      bytes--;
       disable_irq();//int_disable(IRQ_UART_IIR1);
      hs1_txsize++;
      enable_irq();//int_enable(IRQ_UART_IIR1);
    }

    disable_irq();//int_disable(IRQ_UART_IIR1);
    //.term_dat_send_cb();
	hs1_send_cb();
    enable_irq();//int_enable(IRQ_UART_IIR1);
  }
  return 0;
}
//---------------------------------------------------------------------------------
extern INT_32 hs1uartdev;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long inU1(UNS_8 *buff, int bytes)  @ "Fast_function";
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
long inU1(UNS_8 *buff, int bytes)  @ "Fast_function"
{

int bread = 0;

  while ((bytes > 0) && (hs1_rxsize > 0))
  {
    *buff = hs1_rxbuff[hs1_rxget];
    buff++;
    hs1_rxget++;
    if (hs1_rxget >= 512)
    {
      hs1_rxget = 0;
    }
    bytes--;
    bread++;
     disable_irq();//int_disable(IRQ_UART_IIR1);
    hs1_rxsize--;
     enable_irq();//int_enable(IRQ_UART_IIR1);
  }
  if (hs1_rxfill == hs1_rxget)
  {
	disable_irq();//int_disable(IRQ_UART_IIR1);
	hs1_rxfill = hs1_rxget = 0;
	enable_irq();//int_enable(IRQ_UART_IIR1);
  }
  if(chHdwErorHSU1)
  {
    Int_disableGen(IRQ_UART_IIR1);//int_disable(IRQ_UART_IIR1);
    int_clear(IRQ_UART_IIR1);
	chHdwErorHSU1 = 0;
    bytes = hs_uart_recover(hs1uartdev);
  }
//MIC-> er |= 1<<IRQ_UART_IIR7;
Int_enableGen(IRQ_UART_IIR1);//int_enable(IRQ_UART_IIR1);
  return bread;
	
	
}
//---------------------------------------------------------------------------------

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void hs1_eof_cb(void)  @ "Fast_function";
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
void hs1_eof_cb(void) @ "Fast_function"
{

//HSUART_CFG_T *phsuart = (HSUART_CFG_T *) hs1uartdev;

//if need Start Process of Analises

//hs1_rxfill = hs1_rxget = hs1_rxsize = 0;
	chEntry_Hs1++;
	//MIC-> er &= ~tmp;
}
//---------------------------------------------------------------------------------



/* EOF */
