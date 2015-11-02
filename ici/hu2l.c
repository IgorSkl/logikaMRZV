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

long lMaxTimeTransmit = 0;extern unsigned long lTmrHSU2Val;
/* Prototype for external IRQ handler */
void lpc32xx_irq_handler(void);
extern unsigned char chEntry_Hs2;extern unsigned char chEOI_Hs2;
extern unsigned char chHdwErorHSU2;
/* HSUART device handles */
 INT_32 hs2uartdev = 0;
// INT_32 hsuartdev = 0;
static UNS_8 hs2_txbuff [512], hs2_rxbuff [512];
volatile  int hs2_txsize = 0, hs2_rxsize = 0;

 int hs2_txfill  = 0;
 int hs2_rxget   = 0; 
 int hs2_txget   = 0;
 int hs2_rxfill  = 0;

void foo2(void)
{
	hs2_txfill = hs2_txget = hs2_rxfill = 
	hs2_rxget = hs2_txsize = hs2_rxsize = 0;

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
void hs2_recv_cb(void)  @ "Fast_function";
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
void hs2_recv_cb(void)  @ "Fast_function"
{
  INT_32 bread, toreadmax = 512 - hs2_rxfill;

  /* Read data */
  //bread = uart_read(uartdev, &rxbuff[rxfill], toreadmax);
  bread = hs_uart_read( hs2uartdev, &hs2_rxbuff[hs2_rxfill], toreadmax);
  
  hs2_rxsize = hs2_rxsize + bread;
  hs2_rxfill = hs2_rxfill + bread;
  if (hs2_rxfill >= 512)
  {
    hs2_rxfill = 0;
  }
}

//---------------------------------------------------------------------------------
static long lLast_Copy_tosend;
static long lInhs2_send_cb = 0;
 char chHSU2SendHdwEror = 0;
extern char chEndTransmitHSU2; 
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void hs2_send_cb(void)  @ "Fast_function";
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

void hs2_send_cb(void)  @ "Fast_function"
{
  lInhs2_send_cb++;
  INT_32 bwrite, tosend = 512 - hs2_txget;
  HSUART_CFG_T *phsuart = (HSUART_CFG_T *)  hs2uartdev;//hsuartdev;
  if(lInhs2_send_cb>1)
  chHSU2SendHdwEror++;//Debug Code
  lLast_Copy_tosend = hs2_txsize;
  if (tosend > hs2_txsize)
  {
    tosend = hs2_txsize;
  }
  else         //Debug Code
    tosend = 0;//Debug Code
  if (tosend == 0)
  {
    phsuart->regptr->ctrl &= ~HSU_TX_INT_EN;
	chEOI_Hs2++;
	//Look Fifo Lever

	//.tosend = (INT_32) TIMER_CNTR0;
	//.bwrite =  ((TIMER_CNTR_REGS_T*) tosend)->tc;//chEndTransmitHSU2--;
	//.bwrite -= lMaxTimeTransmit;
	//.tosend = 0;
	//.if(bwrite>1000)
	//.lMaxTimeTransmit = bwrite;
	//.tosend = 0;
  }
  else
  {
    phsuart->regptr->ctrl |= HSU_TX_INT_EN;
	
  }
   if(tosend > hs2_txsize)//Debug Code
   chHSU2SendHdwEror++;//tosend = 0;//Debug Code
  /* Write data */
  bwrite = hs_uart_write1( hs2uartdev, &hs2_txbuff[hs2_txget], tosend);//hsuartdev
  if(bwrite <= hs2_txsize)//Debug Code
  hs2_txsize = hs2_txsize - bwrite;
  else          //Debug code
  {
  hs2_txsize= 0;//Debug code
  chHSU2SendHdwEror++;
  }
  //if(hs2_txsize<0)
  //hs2_txsize= 0;
  hs2_txget  = hs2_txget + bwrite;
  if (hs2_txget >= 512)
  {
    hs2_txget = 0;
  }
lInhs2_send_cb--;
}
//---------------------------------------------------------------------------------
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void hs2_rxerr_cb(void)  @ "Fast_function";
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
void hs2_rxerr_cb(void)  @ "Fast_function"
{
  //.INT_32 bread, toreadmax = 512 - hs2_rxfill;
HSUART_CFG_T* pHs_uart_dat = (HSUART_CFG_T* )hs2uartdev;//hs_uart_dat[2];
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
  
  //.bread = hs_uart_read(hsuartdev, &hs2_rxbuff[hs2_rxfill], toreadmax);
  //.hs2_rxsize = hs2_rxsize + bread;
  //.hs2_rxfill = hs2_rxfill + bread;
  //.if (hs2_rxfill >= 512)
  //.{
  //.  hs2_rxfill = 0;
  //.}
  
  hs2_txfill = hs2_txget = hs2_rxfill = 
  hs2_rxget = hs2_txsize = hs2_rxsize = 0;
}

//---------------------------------------------------------------------------------
//Transmit 60 Byte
//Receve 60 Biytea
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long outU2(UNS_8 *dat, int bytes)  @ "Fast_function";
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

long outU2(UNS_8 *dat, int bytes)  @ "Fast_function"
{
  if (hs2_txsize>bytes)
  {
	return 0;//Stop Do Something
  }
  disable_irq();//int_disable(IRQ_UART_IIR2);
  if ((hs2_txfill == hs2_txget)&&(hs2_txsize==0))
  hs2_txget = hs2_txfill = 0;//.!!!
   enable_irq();//int_enable(IRQ_UART_IIR2);
   if(hs2_txsize!=0)//Debug Code
   {
        hs2_txsize++;    //Debug Code
		while(1);
	} 
  while (bytes > 0)
  {
    while ((bytes > 0) && (hs2_txsize < 512))
    {
      hs2_txbuff[hs2_txfill] = *dat;
      hs2_txfill++;
      if (hs2_txfill >= 512)
      {
        hs2_txfill = 0;
      }
      dat++;
      bytes--;
      disable_irq();//int_disable(IRQ_UART_IIR2);
      hs2_txsize++;
       enable_irq();//int_enable(IRQ_UART_IIR2);
    }

     disable_irq();//int_disable(IRQ_UART_IIR2);
    //.term_dat_send_cb();
	 chEndTransmitHSU2++;lMaxTimeTransmit = 1;
	 //.dat = (UNS_8 *) TIMER_CNTR0;
	 //.lMaxTimeTransmit =  ((TIMER_CNTR_REGS_T*) dat)->tc;//chEndTransmitHSU2--;
	hs2_send_cb();
    enable_irq();//int_enable(IRQ_UART_IIR2);
  }
  return  bytes;
}
//---------------------------------------------------------------------------------
extern INT_32 hs2uartdev;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long inU2(UNS_8 *buff, int bytes)  @ "Fast_function";
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
long inU2(UNS_8 *buff, int bytes)  @ "Fast_function"
{

int bread = 0;

  while ((bytes > 0) && (hs2_rxsize > 0))
  {
    *buff = hs2_rxbuff[hs2_rxget];
    buff++;
    hs2_rxget++;
    if (hs2_rxget >= 512)
    {
      hs2_rxget = 0;
    }
    bytes--;
    bread++;
    disable_irq();//int_disable(IRQ_UART_IIR2);
    hs2_rxsize--;
    enable_irq();//int_enable(IRQ_UART_IIR2);
  }
  if (hs2_rxfill == hs2_rxget)
  {
	disable_irq();//int_disable(IRQ_UART_IIR2);
	hs2_rxfill = hs2_rxget = 0;
	enable_irq();//int_enable(IRQ_UART_IIR2);
  }
  if(chHdwErorHSU2)
  {
    Int_disableGen(IRQ_UART_IIR2);//int_disable(IRQ_UART_IIR2);
    int_clear(IRQ_UART_IIR2);
	chHdwErorHSU2 = 0;
    bytes = hs_uart_recover(hs2uartdev);
  }
//MIC-> er |= 1<<IRQ_UART_IIR7;
Int_enableGen(IRQ_UART_IIR2);// int_enable(IRQ_UART_IIR2);
  return bread;
	
	
}
//---------------------------------------------------------------------------------

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void hs2_eof_cb(void)  @ "Fast_function";
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
void hs2_eof_cb(void) @ "Fast_function"
{

//HSUART_CFG_T *phsuart = (HSUART_CFG_T *) hs2uartdev;

//if need Start Process of Analises

//hs2_rxfill = hs2_rxget = hs2_rxsize = 0;
	chEntry_Hs2++;
	//MIC-> er &= ~tmp;
}
//---------------------------------------------------------------------------------

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void RecoverHSU2(void)  @ "Fast_function";
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
void RecoverHSU2(void) @ "Fast_function"
{
int bytes ;
chHSU2SendHdwEror = 0;
 //if(chHdwErorHSU2)
  {
    Int_disableGen(IRQ_UART_IIR2);//int_disable(IRQ_UART_IIR2);
    int_clear(IRQ_UART_IIR2);
	chHSU2SendHdwEror = 0;
    bytes = hs_uart_recover(hs2uartdev);
	hs2_txfill = hs2_txget = hs2_rxfill = 
  hs2_rxget = hs2_txsize = hs2_rxsize = 0;
  }
//MIC-> er |= 1<<IRQ_UART_IIR7;
Int_enableGen(IRQ_UART_IIR2);// int_enable(IRQ_UART_IIR2);

	

}
//---------------------------------------------------------------------------------
void RstTmr0(void)
{
void *pv;
pv = (void*)TIMER_CNTR0;
if( (( ((TIMER_CNTR_REGS_T *)pv)->ir & TIMER_CNTR_MTCH_BIT(0)) != 0 ))
{
	//if (hs2_txsize==0)//You can insert in this place additonal vars for ctrl end Transmit 
	{
		//-hldrHSU2LpduTRUnit.uchLpuHSU2State = 0;lMaxTimeTransmit = 0;
		((TIMER_CNTR_REGS_T *)pv)->tcr = TIMER_CNTR_TCR_RESET;
		//Clear timer
		//-* Stop timer *-/
		((TIMER_CNTR_REGS_T *)pv)->tcr = 0;
		((TIMER_CNTR_REGS_T *)pv)->tc  = 0;
		//-* Clear and enable match function *-/
		((TIMER_CNTR_REGS_T *)pv)->ir = TIMER_CNTR_MTCH_BIT(0);
		((TIMER_CNTR_REGS_T *)pv)->tcr = TIMER_CNTR_TCR_RESET;
	}
}
			


}

long IsEOI_HS2(void)
{
register long i;
 HSUART_CFG_T *phsuart = (HSUART_CFG_T *)  hs2uartdev;//hsuartdev;
	//do
	{
		i = HSU_TX_LEV(phsuart->regptr->level);
		//if (i>1)
		//while(1);
	}
	//while(bwrite);
	if(i==0)
	{
		//Clear IIR
		phsuart->regptr->iir |= HSU_TX_INT;
		//-only for alwayes work Timer! lTmrHSU2Val = ((TIMER_CNTR_REGS_T *)TIMER_CNTR0)-> tc;
		((TIMER_CNTR_REGS_T *)TIMER_CNTR0)-> tc = 0;
		((TIMER_CNTR_REGS_T *)TIMER_CNTR0)-> tcr = TIMER_CNTR_TCR_EN;
	
		return 1;
	}
	else
	return 0;

}


/* EOF */
