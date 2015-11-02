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
* File Name       : ssp1L.c
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


#include <string.h>
#include <intrinsics.h>
#include "../LIB/CDL_AV0/lpc/include/lpc_types.h"
#include "../LIB/CDL_AV0/lpc/include/lpc_irq_fiq.h"
#include "../LIB/CDL_AV0/lpc/include/lpc_arm922t_cp15_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_dma_driver.h"
//#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_uart_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_ssp_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_intc_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_timer_driver.h"
#define SIZE_SPI_BUF 800
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_clkpwr_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_gpio_driver.h"

static long lS = 0; 
 INT_32 sspdev0 = 0;
static UNS_8 spi1_txbuff [SIZE_SPI_BUF]  @ "DMA_BUFFERS", spi1_rxbuff [SIZE_SPI_BUF] @ "DMA_BUFFERS";
volatile  int spi1_txsize, spi1_rxsize;
int spi1_txfill = 0;
int spi1_rxget  = 0;
int spi1_txget  = 0;
int spi1_rxfill = 0;
//.void foo(void)
//.{
//.	txfill = txget = rxfill = rxget = txsize = rxsize = 0;
//.
//.}
extern unsigned char chEntry_Ssp0,chNeedLookStatusSsp0;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void recv_cb_spi1(void)   @ "Fast_function";
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
void recv_cb_spi1(void)   @ "Fast_function"
{
INT_32 bread, toreadmax = SIZE_SPI_BUF - spi1_rxfill;
  SSP_REGS_T *psspregs = (SSP_REGS_T *) SSP0;
  //-* Read data *-/
  if ((psspregs->mis & SSP_MIS_RORMIS)!= 0) 
  {
	toreadmax++;
  }
  //bread = Uart_read(uartdev, &rxbuff[rxfill], toreadmax);
  bread = Ssp_read(sspdev0,&spi1_rxbuff[spi1_rxfill], toreadmax);
  bread <<= 1;
  spi1_rxsize = spi1_rxsize + bread;
  spi1_rxfill = spi1_rxfill + bread;
  if (spi1_rxfill >= SIZE_SPI_BUF)
  {
    spi1_rxfill = 0;
  }
  
   if ((spi1_rxsize == 512) &&(spi1_rxfill==spi1_rxsize) )//SIZE_LPDU_CNL_SPI
   chEntry_Ssp0++;
  if(lS)lS--;
  else lS = 0;
  
}

//---------------------------------------------------------------------------------
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void send_cb_spi1(void)   @ "Fast_function";
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

void send_cb_spi1(void)   @ "Fast_function"
{
  INT_32 bwrite, tosend = SIZE_SPI_BUF - spi1_txget;
  //SSP_DRVDAT_T *psspdrvdat = sspdev0;
  SSP_REGS_T *psspregs = (SSP_REGS_T *) SSP0;
  if (tosend > spi1_txsize)
  {
    tosend = spi1_txsize;
  }
  else         //Debug Code
   tosend = 0;
  if (spi1_txsize == 0)//(tosend == 0)
  {
	psspregs->imsc &= ~SSP_IMSC_TXIM;//regptr->ctrl &= ~ _TX_INT_EN;
	chEntry_Ssp0++;//chNeedLookStatusSsp0++;
  }
  else
  {
	//regptr->ctrl |= _TX_INT_EN;
  }
  if(lS==0)lS++;
  else
  {
    //lS = 0;
    return;
	}

  //-* Write data *-/
  //bwrite = Uart_write(uartdev, &txbuff[txget], tosend);
  bwrite = Ssp_write(sspdev0, &spi1_txbuff[spi1_txget], tosend);
  bwrite <<= 1;
  spi1_txsize = spi1_txsize - bwrite;
  
  spi1_txget = spi1_txget + bwrite;
  
  if (spi1_txget >= SIZE_SPI_BUF)
  {
    spi1_txget = 0;
  }
  
}
//---------------------------------------------------------------------------------

//Transmit 60 Byte
//Receve 60 Biytea
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long outSPI1(UNS_8 *dat, int bytes)   @ "Fast_function";
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

long outSPI1(UNS_8 *dat, int bytes)   @ "Fast_function"
{
 
  disable_irq();//int_disable(IRQ_UART_IIR2);
  if ((spi1_txfill == spi1_txget)&&(spi1_txsize==0))
  spi1_txget = spi1_txfill = 0;//.!!!
   enable_irq();//int_enable(IRQ_UART_IIR2);
   
 while (bytes > 0)
  {
    while ((bytes > 0) && (spi1_txsize < SIZE_SPI_BUF))
    {
      spi1_txbuff[spi1_txfill] = *dat;
      spi1_txfill++;
      if (spi1_txfill >= SIZE_SPI_BUF)
      {
        spi1_txfill = 0;
      }
      dat++;
      bytes--;
      disable_irq();//.int_disable(IRQ_UART_IIR3);
      spi1_txsize++;
      enable_irq();//.int_enable(IRQ_UART_IIR3);
    }

    disable_irq();//.int_disable(IRQ_UART_IIR3);
    //.
	send_cb_spi1();
    enable_irq();//.int_enable(IRQ_UART_IIR3);
  }
  
  return 0;
}
//---------------------------------------------------------------------------------
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long inSPI1(UNS_8 *buff, int bytes)   @ "Fast_function";
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
long inSPI1(UNS_8 *buff, int bytes)   @ "Fast_function"
{

int bread = 0;

  while ((bytes > 0) && (spi1_rxsize > 0))
  {
    *buff = spi1_rxbuff[spi1_rxget+2];
    buff++;
    spi1_rxget++;
    if (spi1_rxget >= SIZE_SPI_BUF)
    {
      spi1_rxget = 0;
    }
    bytes--;
    bread++;
    disable_irq();//.int_disable(IRQ_UART_IIR3);
    spi1_rxsize--;
    enable_irq();//.int_enable(IRQ_UART_IIR3);
  }
  if (spi1_rxfill == spi1_rxget)
  {
	disable_irq();//int_disable(IRQ_UART_IIR2);
	spi1_rxfill = spi1_rxget = 0;
	enable_irq();//int_enable(IRQ_UART_IIR2);
  }

  return bread;
	
	
}
//---------------------------------------------------------------------------------
long Ssp_Syncro(void)
{
long count = 0;
SSP_REGS_T *psspregs = (SSP_REGS_T *) SSP0;

 volatile unsigned short connect_RV = 0;// 0x9483;
 volatile unsigned short connect_TR = 0x2875;
   volatile unsigned short tmp1 = 0;
   
while ((connect_RV != 0x9483) )//&&
           //((sspcfgptr->regptr->sr & SSP_SR_RNE) != 0))
    {
		if ((psspregs->sr & SSP_SR_TFE) != 0)
		{
			psspregs->data =(UNS_32) connect_TR;
		}
		
		if (((psspregs->sr & SSP_SR_RNE) != 0))
		{
			tmp1 = psspregs->data;
			connect_RV = (UNS_16) tmp1;
		}
	}
}
long lSsp0HdwState = 0;
long Ssp_Syncro1(void)
{
register long i;
long count = 3;
SSP_REGS_T *psspregs = (SSP_REGS_T *) SSP0;
i = 0;
 volatile unsigned short connect_RV = 0;// 0x9483;
 volatile unsigned short connect_TR = 0x2875;
 volatile unsigned short tmp1 = 0;
 volatile unsigned short ushSucses = 0;
while ( count--)//&&(connect_RV != 0x9483)&&
           //((sspcfgptr->regptr->sr & SSP_SR_RNE) != 0))
    {
		while ( ((psspregs->sr & SSP_SR_BSY) != 0) )
					{
						;
					}
		if ((psspregs->sr & SSP_SR_TFE) != 0)
		{
			psspregs->data =(UNS_32) (connect_TR+i);
		}
		while ( ((psspregs->sr & SSP_SR_BSY) != 0) )
					{
						;
					}
		//while(((psspregs->sr & SSP_SR_RNE) != 0));//
		if (((psspregs->sr & SSP_SR_RNE) != 0))
		{
			
			tmp1 = psspregs->data;
			if(tmp1==(0x9483+i))
			{
				connect_RV = (UNS_16) tmp1;
				ushSucses++;
				if((ushSucses==2))
				{
					if(i != 1)return 1;
				}
				if(ushSucses==3)
				{
					
					if ((psspregs->sr & SSP_SR_TFE) != 0)
					{
						psspregs->data =(UNS_32) (connect_TR+i);
					}
					while ( ((psspregs->sr & SSP_SR_RNE) != 0) )
					{
						tmp1 = psspregs->data;
						connect_RV = (UNS_16) tmp1;;
					}
					while ( ((psspregs->sr & SSP_SR_BSY) != 0) )
					{
						;
					}
					 tmp1 = 0xf000;

					while(tmp1)
					tmp1--;
					while ( ((psspregs->sr & SSP_SR_RNE) != 0) )
					{
						tmp1 = psspregs->data;
						connect_RV = (UNS_16) tmp1;;
					}
					lSsp0HdwState |= 4;//Spi Ready for Packet Exchange
					//Init Hdr + Buff
					Int_enable1(IRQ_SSP0);
				}	
			}
			else
			{
				return 1;
			}
			
		}
		i++;
	}
	return 0;
}
static long  lInitStateCnl = 0;
long Ssp_Syncro2(void)
{
register long i;
long count = 3;
    union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;
struct 
	{
		unsigned char uchError;
		unsigned char uchHdwrError;
		//unsigned char uChIdxByte ;
		unsigned short ushReceiveCmd;
		unsigned short ushSendAnswerCmd;
		//unsigned char *pUchRV;
		
		
	} sLV;
SSP_REGS_T *psspregs = (SSP_REGS_T *) SSP0;
i = 0;
 volatile unsigned short connect_RV = 0;// 0x9483;
 volatile unsigned short connect_TR = 0x2875;
 volatile unsigned short tmp1 = 0;
 volatile unsigned short ushSucses = 0;
 
i = 0;sLV.uchHdwrError =  sLV.uchError = sLV.ushReceiveCmd = sLV.ushSendAnswerCmd =0;
switch (lInitStateCnl )
	{
		case 0:
			sLV.ushSendAnswerCmd = 0x2875;
		break;
		case 1:
			sLV.ushSendAnswerCmd = 0x2875;
		break;
		case 2://
			sLV.ushSendAnswerCmd = 0x2876;
		break;
		case 4: case 3://
			sLV.ushSendAnswerCmd = 0x2877;
		break;
		//case 4://
		//	sLV.ushSendAnswerCmd = 0x2877;
		//break;
		
	 default:
		sLV.ushSendAnswerCmd = 0x2875;
	}

//Write Cmd 
while ( ((psspregs->sr & SSP_SR_BSY) != 0) )
{
	;
}
if ((psspregs->sr & SSP_SR_TFE) != 0)
{
	psspregs->data =(UNS_32) sLV.ushSendAnswerCmd;//(connect_TR+i);
}
while ( ((psspregs->sr & SSP_SR_BSY) != 0) )
{
	;
}	
	if (((psspregs->sr & SSP_SR_RNE) != 0))//Answer Present
	{
		
		tmp1 = psspregs->data;
		if((tmp1>>4)!= 0x948)
		{
			//Error Syncro
			lInitStateCnl = 0;
			return 1;
		}
		else
		{
			//Decode Answer
			sLV.ushReceiveCmd = tmp1;
			switch(sLV.ushReceiveCmd )
			{
				case 0x9483:
				//Look Curr state
				if (lInitStateCnl <= 2)
				{
					sLV.ushSendAnswerCmd = 0x2876;//0x9483;//State 2
					lInitStateCnl = 2;
				}
				else 
				{
					//~if(lInitStateCnl == 3)
					//~sLV.ushSendAnswerCmd = //0x9484;//Send Current State
					//~if(lInitStateCnl == 4)
					//~sLV.ushSendAnswerCmd = //0x9485;//Send Current State
					
				}
				//unnV1. uchAr [3] = lInitStateCnl;
				break;
				case 0x9484:
				if ((lInitStateCnl <= 3)&&(lInitStateCnl>0))
				{
					sLV.ushSendAnswerCmd = 0x2877;//0x9484;//State 2
					lInitStateCnl = 3;
				}
				else 
				{
					//May Be Reset syncro?
					//~if(lInitStateCnl == 2)
					//~sLV.ushSendAnswerCmd = //0x9484;//Send Current State
					//~if(lInitStateCnl == 4)
					//~sLV.ushSendAnswerCmd = //0x9485;//Send Current State
					//~if (lInitStateCnl <= 1)
					//~sLV.ushSendAnswerCmd = //0x9483;
				}
				//unnV1. uchAr [3] = lInitStateCnl;
				break;
				case 0x9485:
				if ((lInitStateCnl <= 4)&&(lInitStateCnl>1))
				{
					if(lInitStateCnl == 4)
					{
						//unnV1.ushAr [0] = SPI_Read(AT91C_BASE_SPI0);
						//End  of Syncro
						lSsp0HdwState |= 4;
						//Init Hdr + Buff
						Int_enable1(IRQ_SSP0);
						//ReInit for Use PDC
						//StartSetPDC();
						return 0;
					}	
					//sLV.ushSendAnswerCmd = //0x9485;//State 2
					lInitStateCnl = 4;
					lSsp0HdwState |= 4;
					Int_enable1(IRQ_SSP0);
				}
				else
				{
					//sLV.uchError++;//Not Adecvate Sequence Cmd
					//~if (lInitStateCnl <= 1)
					//~sLV.ushSendAnswerCmd = //0x9483;
					//~if(lInitStateCnl == 2)
					//~sLV.ushSendAnswerCmd = //0x9484;//Send Current State
				
				}
				//unnV1. uchAr [3] = lInitStateCnl;
				break;
				
				default: 
				//~sLV.ushSendAnswerCmd = 0x2875;//0x9484;//Reset State
				//unnV1. uchAr [3] = 1;//Error state start Init
			}	
		}
		
	}
	
	
	
	
	return 0;
}
char chCounterCurState2 = 0; 
char chCounterCurState3 = 0; 
char chCounterCurState4 = 0; 
long lSpiAccessCtrl = 1;//Ogranichitel dostupa
long Ssp_Syncro3(void) @ "Fast_function_no_cache"
{
register long i;
long count = 3;
    union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;
struct 
	{
		unsigned char uchError;
		unsigned char uchHdwrError;
		//unsigned char uChIdxByte ;
		unsigned short ushReceiveCmd;
		unsigned short ushSendAnswerCmd;
		//unsigned char *pUchRV;
		
		
	} sLV;
SSP_REGS_T *psspregs = (SSP_REGS_T *) SSP0;
i = 0;
 volatile unsigned short connect_RV = 0;// 0x9483;
 volatile unsigned short connect_TR = 0x2875;
 volatile unsigned short tmp1 = 0;
 volatile unsigned short ushSucses = 0;
 
i = 0;sLV.uchHdwrError =  sLV.uchError = sLV.ushReceiveCmd = sLV.ushSendAnswerCmd =0;
switch (lInitStateCnl )
	{
		case 0:
			sLV.ushSendAnswerCmd = 0x2875;
		break;
		case 1:
			sLV.ushSendAnswerCmd = 0x2875;
		break;
		case 2://
			sLV.ushSendAnswerCmd = 0x2876;
		break;
		case 3:case 4://
			sLV.ushSendAnswerCmd = 0x2877;
		break;
		//case 4://
		//	sLV.ushSendAnswerCmd = 0x2877;
		//break;
		
	 default:
		sLV.ushSendAnswerCmd = 0x2875;
	}
if (lSpiAccessCtrl>0 && (lSpiAccessCtrl<0x40000000)) {lSpiAccessCtrl--;return 0; }
//Write Cmd 
while ( ((psspregs->sr & SSP_SR_BSY) != 0) )
{
	;
}
if ((psspregs->sr & SSP_SR_TFE) != 0)
{
	psspregs->data =(UNS_32) sLV.ushSendAnswerCmd;//(connect_TR+i);
}
while ( ((psspregs->sr & SSP_SR_BSY) != 0) )
{
	;
}	
	if (((psspregs->sr & SSP_SR_RNE) != 0))//Answer Present
	{
		
		tmp1 = psspregs->data;
		if((tmp1>>4)!= 0x948)
		{
			//Error Syncro
			lInitStateCnl = 0;
			return 1;
		}
		else
		{
			//Decode Answer
			sLV.ushReceiveCmd = tmp1;
			switch(sLV.ushReceiveCmd )
			{
				case 0x9483:
				//Look Curr state
				if (lInitStateCnl <= 2)
				{
					sLV.ushSendAnswerCmd = 0x2876;//0x9483;//State 2
					lInitStateCnl = 2;
					chCounterCurState2++;lSpiAccessCtrl = 100;
					if(chCounterCurState2>5)
					{
					chCounterCurState2 = 0;
					lInitStateCnl = 1;
					}
				}
				else 
				{
					//~if(lInitStateCnl == 3)
					//~sLV.ushSendAnswerCmd = //0x9484;//Send Current State
					//~if(lInitStateCnl == 4)
					//~sLV.ushSendAnswerCmd = //0x9485;//Send Current State
					
				}
				//unnV1. uchAr [3] = lInitStateCnl;
				break;
				case 0x9484:
				if ((lInitStateCnl <= 3)&&(lInitStateCnl>1))
				{
					sLV.ushSendAnswerCmd = 0x2877;//0x9484;//State 2
					lInitStateCnl = 3;lSpiAccessCtrl = 9500;
				}
				else 
				{
					//May Be Reset syncro?
					 sLV.uchError++; if(lInitStateCnl>0) lInitStateCnl--;//~if(lInitStateCnl == 2)
					for(;;);//~sLV.ushSendAnswerCmd = //0x9484;//Send Current State
					//~if(lInitStateCnl == 4)
					//~sLV.ushSendAnswerCmd = //0x9485;//Send Current State
					//~if (lInitStateCnl <= 1)
					//~sLV.ushSendAnswerCmd = //0x9483;
				}
				//unnV1. uchAr [3] = lInitStateCnl;
				break;
				case 0x9485:case 0x9486:
				if ((lInitStateCnl <= 4)&&(lInitStateCnl>2))
				{
					if((lInitStateCnl == 4)&&(sLV.ushReceiveCmd==0x9486))
					{
						//unnV1.ushAr [0] = SPI_Read(AT91C_BASE_SPI0);
						//End  of Syncro
						lSsp0HdwState |= 4;
						//Init Hdr + Buff
						Int_enable1(IRQ_SSP0);//for(;;);
						//ReInit for Use PDC
						//StartSetPDC();
						return 0;
					}	
					//sLV.ushSendAnswerCmd = //0x9485;//State 2
					lInitStateCnl = 4;//psspregs->data =(UNS_32) 0x2877;
					lSpiAccessCtrl = 4;//lSsp0HdwState |= 4;
					//for(;;);//Int_enable1(IRQ_SSP0);
				}
				else
				{
					//sLV.uchError++;//Not Adecvate Sequence Cmd
					//~if (lInitStateCnl <= 1)
					//~sLV.ushSendAnswerCmd = //0x9483;
					//~if(lInitStateCnl == 2)
					//~sLV.ushSendAnswerCmd = //0x9484;//Send Current State
				sLV.uchError++; if(lInitStateCnl>0) lInitStateCnl = 0;for(;;);
				}
				//unnV1. uchAr [3] = lInitStateCnl;
				break;
				case 0x9487:case 0x9489:sLV.ushSendAnswerCmd = 0x2877;lInitStateCnl = 3;break;
				default: 
				//~sLV.ushSendAnswerCmd = 0x2875;//0x9484;//Reset State
				//unnV1. uchAr [3] = 1;//Error state start Init
			}	
		}
		
	}
	
	
	
	
	return 0;
}
void Spi0_Rst(void) @ "Fast_function"
{
lInitStateCnl = 0;
lSsp0HdwState = 0;
Int_disable1(IRQ_SSP0);//Int_enable1(IRQ_SSP0);

}
long outSPIDma(UNS_8 *dat, int bytes)   @ "Fast_function"
{
register long i;
register void *pv;
register long IdxChnl;
unsigned short usTransferSize = 0x100;//256;
  disable_irq();//int_disable(IRQ_UART_IIR2);
  if ((spi1_txfill == spi1_txget)&&(spi1_txsize==0))
  spi1_txget = spi1_txfill = 0;//.!!!
   enable_irq();//int_enable(IRQ_UART_IIR2);
   pv = (void*)Dma_get_base();
   IdxChnl = 7;
   i= *((long*)0x20084008);
   //Clear any pending Interrupts on the channel
   ((DMAC_REGS_T*)pv)->int_tc_clear  = (1<<IdxChnl);//Must Later Selector allocate channel
   ((DMAC_REGS_T*)pv)->int_err_clear = (1<<IdxChnl);
   ((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].src_addr  = 0x20084008;//Now SSP Reg for Down Load Data
   ((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].dest_addr = (unsigned long)&spi1_rxbuff[0];
   ((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].lli       = 0;
   
	i = (DMAC_CHAN_INT_TC_EN 
	| DMAC_CHAN_DEST_AUTOINC //|
      | DMAC_CHAN_DEST_AHB1  // | DMAC_CHAN_SRC_AUTOINC 
        | DMAC_CHAN_SRC_AHB1 |DMAC_CHAN_DEST_WIDTH_16 //DMAC_CHAN_DEST_WIDTH_32 |
        | DMAC_CHAN_SRC_WIDTH_16 | DMAC_CHAN_DEST_BURST_4 //|DMAC_CHAN_SRC_WIDTH_32  
        | DMAC_CHAN_SRC_BURST_4 //|
        | (DMAC_CHAN_TRANSFER_SIZE(usTransferSize)));   
   
   ((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].control   = i;
   i = (
   DMAC_CHAN_FLOW_P_P2M //DMAC_CHAN_FLOW_D_P2M//DMAC_CHAN_FLOW_D_M2P //DMAC_CHAN_FLOW_D_M2M 
   | (DMAC_DEST_PERIP (0))|(DMAC_SRC_PERIP(DMA_PERID_SSP0_RX))//Memory
   | DMAC_CHAN_ENABLE 
   //| DMAC_CHAN_ITC | DMAC_CHAN_IE
     );
   
   
   ((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].config_ch = i;
   ((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].dest_addr = (unsigned long)&spi1_rxbuff[0];
   
   IdxChnl = 6;
   //Clear any pending Interrupts on the channel
   ((DMAC_REGS_T*)pv)->int_tc_clear  = (1<<IdxChnl);//Must Later Selector allocate channel
   ((DMAC_REGS_T*)pv)->int_err_clear = (1<<IdxChnl);
   ((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].src_addr  = (unsigned long)&spi1_txbuff[0];
   ((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].dest_addr = 0x20084008;//Now SSP Reg for Down Load Data
   ((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].lli       = 0;
   
	i = (DMAC_CHAN_INT_TC_EN 
	//| DMAC_CHAN_DEST_AUTOINC |
        | DMAC_CHAN_SRC_AUTOINC | DMAC_CHAN_DEST_AHB1 
        | DMAC_CHAN_SRC_AHB1 |DMAC_CHAN_DEST_WIDTH_16 //DMAC_CHAN_DEST_WIDTH_32 |
        | DMAC_CHAN_SRC_WIDTH_16 | DMAC_CHAN_DEST_BURST_4 //|DMAC_CHAN_SRC_WIDTH_32  
        | DMAC_CHAN_SRC_BURST_4 //|
        | (DMAC_CHAN_TRANSFER_SIZE(usTransferSize)));   
   
   ((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].control   = i;
   i = (
   DMAC_CHAN_FLOW_D_M2P //DMAC_CHAN_FLOW_D_M2M 
   | (DMAC_DEST_PERIP (DMA_PERID_SSP0_TX))|(DMAC_SRC_PERIP(0))//Memory
   | DMAC_CHAN_ENABLE 
   //| DMAC_CHAN_ITC | DMAC_CHAN_IE
     );
   
   
   ((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].config_ch = i;
   
   
   //((DMAC_REGS_T*)pv)->dma_chan[6].
   
   //DMAC_CHAN_T*
 //Activate Dma
//Init Transmit Point


	return 0;

}
#define IDX_DMA_SSP0_MOSI 1
#define IDX_DMA_SSP0_MISO 0


DMAC_CHAN_T dma_mosi = {
(unsigned long)&spi1_txbuff[0],//src_addr;
0x20084008                    ,//dest_addr;
                             0,//lli;
(DMAC_CHAN_INT_TC_EN)            //control;
|( DMAC_CHAN_SRC_AUTOINC) //| DMAC_CHAN_DEST_AHB1 
 |(DMAC_CHAN_DEST_WIDTH_16)//| DMAC_CHAN_SRC_AHB1
| (DMAC_CHAN_SRC_WIDTH_16) | (DMAC_CHAN_DEST_BURST_1)		
| (DMAC_CHAN_SRC_BURST_1)	
| (DMAC_CHAN_TRANSFER_SIZE(0x20)),//usTransferSize

DMAC_CHAN_ITC				   
|DMAC_CHAN_FLOW_D_M2P               //config_ch;
| (DMAC_DEST_PERIP (DMA_PERID_SSP0_TX))
|(DMAC_SRC_PERIP(0))//Memory							   
| DMAC_CHAN_ENABLE	,						   
0,0,0 //reserved [3];
};

DMAC_CHAN_T dma_miso = {
0x20084008                    ,//src_addr;
(unsigned long)&spi1_rxbuff[0],//dest_addr;
                             0,//lli;
							 
DMAC_CHAN_INT_TC_EN            //control;
| (DMAC_CHAN_DEST_AUTOINC)
// | DMAC_CHAN_DEST_AHB1
 |(DMAC_CHAN_DEST_WIDTH_16)//| DMAC_CHAN_SRC_AHB1
| (DMAC_CHAN_SRC_WIDTH_16) | (DMAC_CHAN_DEST_BURST_1)
| (DMAC_CHAN_SRC_BURST_1)
| (DMAC_CHAN_TRANSFER_SIZE(0x20)), //usTransferSize

DMAC_CHAN_ITC | DMAC_CHAN_FLOW_D_P2M//DMAC_CHAN_FLOW_P_P2M 
| (DMAC_DEST_PERIP (0))|(DMAC_SRC_PERIP(DMA_PERID_SSP0_RX))//Memory
//|DMAC_CHAN_HALT//| DMAC_CHAN_ENABLE
//|DMAC_CHAN_LOCK 
//0,0,0 //reserved [3];
};
DMAC_CHAN_T dma_clr = {
0,
0,
0,
0,
0


};
/*
DMAC_CHAN_T dma_mosi = {
(unsigned long)&spi1_txbuff[0],//src_addr;
0x20084008                    ,//dest_addr;
                             0,//lli;
//DMAC_CHAN_INT_TC_EN            //control;
| DMAC_CHAN_SRC_AUTOINC //| DMAC_CHAN_DEST_AHB1 
 |DMAC_CHAN_DEST_WIDTH_16//| DMAC_CHAN_SRC_AHB1
| DMAC_CHAN_SRC_WIDTH_16 | DMAC_CHAN_DEST_BURST_1		
| DMAC_CHAN_SRC_BURST_1	
| (DMAC_CHAN_TRANSFER_SIZE(0x100)),//usTransferSize

				   
DMAC_CHAN_FLOW_D_M2P               //config_ch;
| (DMAC_DEST_PERIP (DMA_PERID_SSP0_TX))
|(DMAC_SRC_PERIP(0))//Memory							   
| DMAC_CHAN_ENABLE	,						   
0,0,0 //reserved [3];
};

DMAC_CHAN_T dma_miso = {
0x20084008                    ,//src_addr;
(unsigned long)&spi1_rxbuff[0],//dest_addr;
                             0,//lli;
							 
0//DMAC_CHAN_INT_TC_EN            //control;
| DMAC_CHAN_DEST_AUTOINC
// | DMAC_CHAN_DEST_AHB1
 |DMAC_CHAN_DEST_WIDTH_16//| DMAC_CHAN_SRC_AHB1
| DMAC_CHAN_SRC_WIDTH_16 | DMAC_CHAN_DEST_BURST_1
| DMAC_CHAN_SRC_BURST_1
| (DMAC_CHAN_TRANSFER_SIZE(0x100)), //usTransferSize

 DMAC_CHAN_FLOW_D_P2M//DMAC_CHAN_FLOW_P_P2M 
| (DMAC_DEST_PERIP (0))|(DMAC_SRC_PERIP(DMA_PERID_SSP0_RX))//Memory
|DMAC_CHAN_HALT//| DMAC_CHAN_ENABLE
|DMAC_CHAN_LOCK 
};
*/
//@ "Fast_function_no_cache"
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long SetUp_Dma_Chanel(long IdxChnl,void *pInitData )   @ "Fast_function_no_cache";
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

long SetUp_Dma_Chanel(long IdxChnl, void *pInitData )   @ "Fast_function_no_cache"
{
//register long i;
register void *pv;
//Detect Source
pv = (void*)Dma_get_base();
//Clear any pending Interrupts on the channel
((DMAC_REGS_T*)pv)->int_tc_clear  = (1<<IdxChnl);//Must Later Selector allocate channel
((DMAC_REGS_T*)pv)->int_err_clear = (1<<IdxChnl);

((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].src_addr  =
((DMAC_CHAN_T*)pInitData)-> src_addr;
((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].dest_addr =
((DMAC_CHAN_T*)pInitData)-> dest_addr;
((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].lli       =
((DMAC_CHAN_T*)pInitData)-> lli;
((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].control   = 
((DMAC_CHAN_T*)pInitData)-> control;
((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].config_ch = 
((DMAC_CHAN_T*)pInitData)-> config_ch;

return ((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].config_ch;
}
//---------------------------------------------------------------------------------
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void Dma_Int_cb_ssp0(void)   @ "Fast_function";
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

void Dma_Int_cb_ssp0(void)   @ "Fast_function"
{
//Detect Source


}
//---------------------------------------------------------------------------------



//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void Tci_recv_cb_ssp0(void)   @ "Fast_function_no_cache";
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

void Tci_recv_cb_ssp0(void)   @ "Fast_function_no_cache"
{
long bread;
register void *pv;

   pv = (void*)Dma_get_base();
if( (((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].dest_addr == 0)
&& (((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].src_addr == 0)
  )
  return;
  bread = ((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].dest_addr
  - dma_miso.dest_addr;
   bread += 2;
  if (bread>= 0x200)
 {
	 bread = 0x200;//?? Error control
	 //chEntry_Ssp0++;
 }
  spi1_rxsize = spi1_rxsize + bread;
  spi1_rxfill = spi1_rxfill + bread;
  if (spi1_rxfill >= SIZE_SPI_BUF)
  {
    //spi1_rxfill = 0;//Error ??? <- This code won`t be properly worked 
	//as we don`t control Each word for reception
	spi1_rxfill -= SIZE_SPI_BUF;//Only for general methodics/.
  }
  
   if ((spi1_rxsize == 512) &&(spi1_rxfill==spi1_rxsize) )//SIZE_LPDU_CNL_SPI
   {
	chEntry_Ssp0++;if(chEntry_Ssp0>2) for(;;);
	//Try Reinit Dma chanell?
	
	}
	SetUp_Dma_Chanel(IDX_DMA_SSP0_MISO,(void*)&dma_clr);
  //Disable Channel
  //(((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].config_ch) = 0;//???
  *((long*)0x20084024)  &= 2;
  GPIO->p3_outp_clr = (1<<23);// GPIO->p3_outp_set  = (1<<23);
  GPIO->p3_outp_set = ((1<<7));
}
//---------------------------------------------------------------------------------

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void Tci_send_cb_ssp0(void)   @ "Fast_function_no_cache";
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

void Tci_send_cb_ssp0(void)   @ "Fast_function_no_cache"
{
 register long bwrite; 
 register void *pv;
//Detect Source
pv = (void*)Dma_get_base();
 bwrite = (((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MOSI].src_addr);
 if ((bwrite==0)&&((((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MOSI].dest_addr)==0) )
 return;
 bwrite -= dma_mosi.src_addr;
 bwrite += 2;//Additiona Stop addr
 if (bwrite>= 0x200)
 {
	 bwrite = 0x200;//?? Error control
	 chEntry_Ssp0++;if(chEntry_Ssp0>2) for(;;);
 }
  //Data already moved
  spi1_txsize = spi1_txsize - bwrite;
  
  spi1_txget = spi1_txget + bwrite;
  
  if (spi1_txget >= SIZE_SPI_BUF)
  {
    spi1_txget = 0;
  }
  SetUp_Dma_Chanel(IDX_DMA_SSP0_MOSI,(void*)&dma_clr);
  //Disable Channel
  //(((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MOSI].config_ch) = 0;
  ////Clear Int
  //((DMAC_REGS_T*)pv)->int_tc_clear  = (1<<IDX_DMA_SSP0_MOSI);
  //((DMAC_REGS_T*)pv)->int_err_clear = (1<<IDX_DMA_SSP0_MOSI);
//  chEntry_Ssp0++;
  *((long*)0x20084024)  &= 1;
}
//---------------------------------------------------------------------------------
extern unsigned long ulCtrTrLpduSpi ;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
__arm long OutSPIDma(UNS_8 *dat, int bytes)   @ "Fast_function_no_cache";
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
#include    "lpu.h"
__arm long OutSPIDma(UNS_8 *dat, int bytes)   @ "Fast_function_no_cache"
{

register long bsend; 
register void *pv;

//Detect If Bs Rdy
	if( (GPIO->p3_inp_state) & (1<<16)) 
	;
	else
#ifdef _STATIC_MEMORY_BOOT 	
	;//
#else
	//return 0;//<-Debug Code for control busy state If Pio Hdw Interface Worked
#endif
	 GPIO->p3_outp_set  = (1<<23);

ProcessLLEvt();//Process Urgent Data
//Detect Source
pv = (void*)Dma_get_base();if(chEntry_Ssp0>0) for(;;);
  disable_irq();
  if ((spi1_txfill == spi1_txget)&&(spi1_txsize == 0))
  spi1_txget = spi1_txfill = 0;//.!!!
  if (bytes>SIZE_SPI_BUF)
  bytes = SIZE_SPI_BUF;//correctness Control
//__disable_interrupt();
ulCtrTrLpduSpi++;
	 


	if (bytes+spi1_txfill>SIZE_SPI_BUF)
	bytes = SIZE_SPI_BUF- spi1_txfill;
	else
	bsend = bytes;
	
	//i = spi0_txsize + bytes;
	//if (i>= (SIZE_SPI_BUF))
	if ((spi1_txsize + bytes)>= (SIZE_SPI_BUF))
	bsend = SIZE_SPI_BUF - spi1_txsize;
	else
	bsend = bytes;
	
	memcpy(spi1_txbuff+spi1_txfill,dat,bsend);
//Data In Buf	

	spi1_txsize += bsend; 
	//if (bsend)

	spi1_txfill+= bsend;
    if (spi1_txfill >= (SIZE_SPI_BUF))
    {
      spi1_txfill -= SIZE_SPI_BUF;
    }
	//Detect If BS Ready Else Out
	
	
//	__enable_interrupt();
//clkpwr_clk_en_dis(CLKPWR_DMA_CLK, 1);
   enable_irq();//int_enable(IRQ_UART_IIR2);
   bsend >>= 1;//((DMAC_REGS_T*)pv)->config = 1;
   	;//Set MISO dma chanell
	if( (((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].config_ch)&( DMAC_CHAN_ENABLE))
	{
		;//additional SetUP
	}	
	else
		bytes = SetUp_Dma_Chanel(IDX_DMA_SSP0_MISO,(void*)&dma_miso);//Initial PreInit
		
	(((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].config_ch) &= ~( DMAC_CHAN_ENABLE);
	((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].control &= ~0xfff;
	((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].control   |= 
	DMAC_CHAN_DEST_AHB1 |	DMAC_CHAN_TRANSFER_SIZE(bsend);
	
	(((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].config_ch) |= ( DMAC_CHAN_ENABLE);
	//((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].dest_addr = dma_miso.dest_addr;//Additional Change Pointer
	 
	;//Set MOSI dma chanell
	bytes = DMAC_CHAN_TRANSFER_SIZE(dma_mosi.control);
	dma_mosi.control  &= ~0xfff;
	dma_mosi.control |=  DMAC_CHAN_TRANSFER_SIZE(bsend);
	bsend = SetUp_Dma_Chanel(IDX_DMA_SSP0_MOSI,(void*)&dma_mosi); //Wait Interrupt 
	// GPIO->p3_outp_set  = (1<<23);// GPIO->p3_outp_clr = (1<<23);
	//GPIO->p3_outp_set  = ((1<<7));
	//Check If Message Receive
	//if( (GPIO->p3_inp_state) & (1<<16)  == 0) 
	//;//Ok State
	//else//Fix Error Syncro
	
	*((long*)0x20084024)  = 3;
	dma_mosi.control  &= ~0xfff;
	dma_mosi.control |=  DMAC_CHAN_TRANSFER_SIZE(bytes);
	
 
 
 
 
 
 
 
 
 
return 	bsend;
 
 
 
 
 
 
 
 
 
 
 
//,*((long*)0x20084024)  = 0;
//.(((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].config_ch) &= ~( DMAC_CHAN_ENABLE);
//,Tci_send_cb_ssp0();
//,Tci_recv_cb_ssp0();
//((DMAC_REGS_T*)pv)->config = 0; // clkpwr_clk_en_dis(CLKPWR_DMA_CLK, 0);
 
 
 
 
 
  
}
//---------------------------------------------------------------------------------


__arm long InSPIDma(UNS_8 *dat, int bytes)   @ "Fast_function"
{
int bread = 0;
register long i;
register void *pv;
   
   pv = (void*)Dma_get_base();
   
   if (bytes>spi1_rxsize)
	   bread = spi1_rxsize;
	else 
	bread = bytes;
	//spi1_rxget += 2;//For skip 1-st word in bug only
  disable_irq();//	
  memcpy(dat,spi1_rxbuff+spi1_rxget+0,bread);
  	spi1_rxget += bytes;
	if (spi1_rxget >= (SIZE_SPI_BUF))
    {
      spi1_rxget -= SIZE_SPI_BUF;
    }
	spi1_rxsize -= bread; 
   enable_irq();//
 if (spi1_rxfill == spi1_rxget)
  {

	 disable_irq();//__disable_interrupt();//..
	spi1_rxfill = spi1_rxget = 0;

	enable_irq();//__enable_interrupt();
  }

	return 0;

}
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
long DetectEndOfTransmitDmaSsp0(void)   @ "Fast_function";
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

long DetectEndOfTransmitDmaSsp0(void)   @ "Fast_function"
{
 register long i;
 register long IdxChnl;
 register void *pv;
 register long AmtSucces;   
    IdxChnl = 6;AmtSucces = 0;
 pv = (void*)Dma_get_base();
 //Detect State Transmit Channel 
 i = ((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].config_ch;
 if (i&DMAC_CHAN_ACTIVE )
 {
 	i = 0;
 	return i ;
 }
 //Detect Size of Transmittion
 i = ((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].src_addr;
 i -=(unsigned long)&spi1_txbuff[0];
 //Detect Amount transfer Byte
 if (i>= 0x1fe)
 {
 	AmtSucces++;
	//Stop Channel
	((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].config_ch = 0;
 }
 IdxChnl = 7;
 //Detect State Receive Channel
 i = ((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].config_ch;
 
 //Detect Amount Recive Byte
 i = ((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].dest_addr;
 i -=(unsigned long)&spi1_rxbuff[0];
 //Detect Amount transfer Byte
 if (i>= 0x1fe)
 {
    AmtSucces++;
	//Stop Channel
	((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].config_ch = 0;
 }
 	if(AmtSucces>=2)
 	{
 		chEntry_Ssp0 = 2;//++;
 		return AmtSucces;
 	}
 return AmtSucces;
}
//---------------------------------------------------------------------------------

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void Dma_recv_stub_ssp0(void)   @ "Fast_function";
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

void Dma_recv_stub_ssp0(void)   @ "Fast_function"
{
long bread;
register void *pv;
  //SSP_REGS_T *psspregs = (SSP_REGS_T *) SSP0;
   pv = (void*)Dma_get_base();
  //.bread = Ssp_read(sspdev0,&spi1_rxbuff[spi1_rxfill], toreadmax);
  //.bread <<= 1;
  
  bread = ((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].dest_addr
  - dma_miso.dest_addr;
   bread += 2;
  if (bread>= 0x200)
 {
	 bread = 0x200;//?? Error control
	 //chEntry_Ssp0++;
 }
  spi1_rxsize = spi1_rxsize + bread;
  spi1_rxfill = spi1_rxfill + bread;
  if (spi1_rxfill >= SIZE_SPI_BUF)
  {
    //spi1_rxfill = 0;//Error ??? <- This code won`t be properly worked 
	//as we don`t control Each word for reception
	spi1_rxfill -= SIZE_SPI_BUF;//Only for general methodics/.
  }
  
   if ((spi1_rxsize == 512) &&(spi1_rxfill==spi1_rxsize) )//SIZE_LPDU_CNL_SPI
   {
	chEntry_Ssp0++;
	//Try Reinit Dma chanell?
	
	}
	SetUp_Dma_Chanel(IDX_DMA_SSP0_MISO,(void*)&dma_clr);
  //Disable Channel
  //(((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].config_ch) = 0;//???

}
//---------------------------------------------------------------------------------

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void Dma_send_stub_ssp0(void)   @ "Fast_function";
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

void Dma_send_stub_ssp0(void)   @ "Fast_function"
{
 register long bwrite; 
 register void *pv;
//Detect Source
pv = (void*)Dma_get_base();
 bwrite = (((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MOSI].src_addr);
 bwrite -= dma_mosi.src_addr;
 bwrite += 2;//Additiona Stop addr
 if (bwrite>= 0x200)
 {
	 bwrite = 0x200;//?? Error control
	 chEntry_Ssp0++;
 }
  //Data already moved
  spi1_txsize = spi1_txsize - bwrite;
  
  spi1_txget = spi1_txget + bwrite;
  
  if (spi1_txget >= SIZE_SPI_BUF)
  {
    spi1_txget = 0;
  }
  SetUp_Dma_Chanel(IDX_DMA_SSP0_MOSI,(void*)&dma_clr);
  //Disable Channel
  //(((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MOSI].config_ch) = 0;
  ////Clear Int
  //((DMAC_REGS_T*)pv)->int_tc_clear  = (1<<IDX_DMA_SSP0_MOSI);
  //((DMAC_REGS_T*)pv)->int_err_clear = (1<<IDX_DMA_SSP0_MOSI);
//  chEntry_Ssp0++;
  
}
//---------------------------------------------------------------------------------
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
__arm long OutSPIDmaDbg(UNS_8 *dat, int bytes)   @ "Fast_function";
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
#include    "lpu.h"
__arm long OutSPIDmaDbg(UNS_8 *dat, int bytes)   @ "Fast_function"
{

register long bsend; 
register void *pv;
//Detect Source
pv = (void*)Dma_get_base();
  disable_irq();
  if ((spi1_txfill == spi1_txget)&&(spi1_txsize == 0))
  spi1_txget = spi1_txfill = 0;//.!!!
  if (bytes>SIZE_SPI_BUF)
  bytes = SIZE_SPI_BUF;//correctness Control
//__disable_interrupt();

	if (bytes+spi1_txfill>SIZE_SPI_BUF)
	bytes = SIZE_SPI_BUF- spi1_txfill;
	else
	bsend = bytes;
	
	//i = spi0_txsize + bytes;
	//if (i>= (SIZE_SPI_BUF))
	if ((spi1_txsize + bytes)>= (SIZE_SPI_BUF))
	bsend = SIZE_SPI_BUF - spi1_txsize;
	else
	bsend = bytes;
	
	memcpy(spi1_txbuff+spi1_txfill,dat,bsend);
//Data In Buf	

	spi1_txsize += bsend; 
	//if (bsend)

	spi1_txfill+= bsend;
    if (spi1_txfill >= (SIZE_SPI_BUF))
    {
      spi1_txfill -= SIZE_SPI_BUF;
    }
//	__enable_interrupt();
clkpwr_clk_en_dis(CLKPWR_DMA_CLK, 1);
   enable_irq();//int_enable(IRQ_UART_IIR2);
   bsend >>= 1;((DMAC_REGS_T*)pv)->config = 1;
   	;//Set MISO dma chanell
	if( (((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].config_ch)&( DMAC_CHAN_ENABLE))
	{
		;//additional SetUP
	}	
	else
		bytes = SetUp_Dma_Chanel(IDX_DMA_SSP0_MISO,(void*)&dma_miso);//Initial PreInit
		
	(((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].config_ch) &= ~( DMAC_CHAN_ENABLE);
	((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].control &= ~0xfff;
	((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].control   |= 
	DMAC_CHAN_DEST_AHB1 |	DMAC_CHAN_TRANSFER_SIZE(bsend);
	
	(((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].config_ch) |= ( DMAC_CHAN_ENABLE);
	//((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].dest_addr = dma_miso.dest_addr;//Additional Change Pointer
	 
	;//Set MOSI dma chanell
	bytes = DMAC_CHAN_TRANSFER_SIZE(dma_mosi.control);
	dma_mosi.control  &= ~0xfff;
	dma_mosi.control |=  DMAC_CHAN_TRANSFER_SIZE(bsend);
	bsend = SetUp_Dma_Chanel(IDX_DMA_SSP0_MOSI,(void*)&dma_mosi); //Wait Interrupt 
	*((long*)0x20084024)  = 3;
	dma_mosi.control  &= ~0xfff;
	dma_mosi.control |=  DMAC_CHAN_TRANSFER_SIZE(bytes);
//	while(
//	(((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].config_ch)&(DMAC_CHAN_ACTIVE)
//	);
	/*
	bytes = SetUp_Dma_Chanel(IDX_DMA_SSP0_MOSI,(void*)&dma_mosi); //Wait Interrupt  
	((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].dest_addr = dma_miso.dest_addr;
	bytes = SetUp_Dma_Chanel(IDX_DMA_SSP0_MOSI,(void*)&dma_mosi); //Wait Interrupt 
((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].dest_addr = dma_miso.dest_addr;	
	bytes = SetUp_Dma_Chanel(IDX_DMA_SSP0_MOSI,(void*)&dma_mosi); //Wait Interrupt  
	((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].dest_addr = dma_miso.dest_addr;
	bytes = SetUp_Dma_Chanel(IDX_DMA_SSP0_MOSI,(void*)&dma_mosi); //Wait Interrupt  
	((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].dest_addr = dma_miso.dest_addr;
	*/
	//Wait&Clear Bits
	//(((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].config_ch) &= ~( DMAC_CHAN_ENABLE);
//    spi1_txsize -= bsend;//spi0_txsize = spi0_txsize - bwrite;
//    spi1_txget  +=  bsend;//spi0_txget  =  spi0_txget + bwrite;
//  if ( spi1_txget >= (SIZE_SPI_BUF)) DMA
//  {
//     spi1_txget = 0;
//  }
*((long*)0x20084024)  = 0;
(((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].config_ch) &= ~( DMAC_CHAN_ENABLE);
Dma_send_stub_ssp0();
Dma_recv_stub_ssp0();
((DMAC_REGS_T*)pv)->config = 0;  clkpwr_clk_en_dis(CLKPWR_DMA_CLK, 0);
//(((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].config_ch) = 0;
//((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MISO].control     = 0;
//(((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MOSI].config_ch) = 0;
//((DMAC_REGS_T*)pv)->dma_chan[IDX_DMA_SSP0_MOSI].control     = 0;
//inSPI1((unsigned char*)&hldrSpiLpduUnit.arUch[0],1);
  
}
//---------------------------------------------------------------------------------
long Ssp_Syncro4(void) @ "Fast_function_no_cache"
{
	lInitStateCnl = 4;//
	lSpiAccessCtrl = 4;
	lSsp0HdwState |= 4;
	
	Int_enable1(IRQ_SSP0);//for(;;);
	
	return 0;

}
/*
1 ,51 ,101,151 ,201 ,251,301 ,351 ,401 ,451 501
2 ,52 ,102,152 ,202 ,252,302 ,352 ,402 ,452 502
3 ,53 ,103,153 ,203 ,253,303 ,353 ,403 ,453 503
4 ,54 ,104,154 ,204 ,254,304 ,354 ,404 ,454 504
5 ,55 ,105,155 ,205 ,255,305 ,355 ,405 ,455 505
6 ,56 ,106,156 ,206 ,256,306 ,356 ,406 ,456 506
7 ,57 ,107,157 ,207 ,257,307 ,357 ,407 ,457 507
8 ,58 ,108,158 ,208 ,258,308 ,358 ,408 ,458 508
9 ,59 ,109,159 ,209 ,259,309 ,359 ,409 ,459 509
10,60 ,110,160 ,210 ,260,310 ,360 ,410 ,460 510
11,61 ,111,161 ,211 ,261,311 ,361 ,411 ,461 511
12,62 ,112,162 ,212 ,262,312 ,362 ,412 ,462 512
13,63 ,113,163 ,213 ,263,313 ,363 ,413 ,463 513
14,64 ,114,164 ,214 ,264,314 ,364 ,414 ,464 514
15,65 ,115,165 ,215 ,265,315 ,365 ,415 ,465 515
16,66 ,116,166 ,216 ,266,316 ,366 ,416 ,466 516
17,67 ,117,167 ,217 ,267,317 ,367 ,417 ,467 517
18,68 ,118,168 ,218 ,268,318 ,368 ,418 ,468 518
19,69 ,119,169 ,219 ,269,319 ,369 ,419 ,469 519
20,70 ,120,170 ,220 ,270,320 ,370 ,420 ,470 520
21,71 ,121,171 ,221 ,271,321 ,371 ,421 ,471 521
22,72 ,122,172 ,222 ,272,322 ,372 ,422 ,472 522
23,73 ,123,173 ,223 ,273,323 ,373 ,423 ,473 523
24,74 ,124,174 ,224 ,274,324 ,374 ,424 ,474 524
25,75 ,125,175 ,225 ,275,325 ,375 ,425 ,475 525
26,76 ,126,176 ,226 ,276,326 ,376 ,426 ,476 526
27,77 ,127,177 ,227 ,277,327 ,377 ,427 ,477 527
28,78 ,128,178 ,228 ,278,328 ,378 ,428 ,478 528
29,79 ,129,179 ,229 ,279,329 ,379 ,429 ,479 529
30,80 ,130,180 ,230 ,280,330 ,380 ,430 ,480 530
31,81 ,131,181 ,231 ,281,331 ,381 ,431 ,481 531
32,82 ,132,182 ,232 ,282,332 ,382 ,432 ,482 532
33,83 ,133,183 ,233 ,283,333 ,383 ,433 ,483 533
34,84 ,134,184 ,234 ,284,334 ,384 ,434 ,484 534
35,85 ,135,185 ,235 ,285,335 ,385 ,435 ,485 535
36,86 ,136,186 ,236 ,286,336 ,386 ,436 ,486 536
37,87 ,137,187 ,237 ,287,337 ,387 ,437 ,487 537
38,88 ,138,188 ,238 ,288,338 ,388 ,438 ,488 538
39,89 ,139,189 ,239 ,289,339 ,389 ,439 ,489 539
40,90 ,140,190 ,240 ,290,340 ,390 ,440 ,490 540
41,91 ,141,191 ,241 ,291,341 ,391 ,441 ,491 541
42,92 ,142,192 ,242 ,292,342 ,392 ,442 ,492 542
43,93 ,143,193 ,243 ,293,343 ,393 ,443 ,493 543
44,94 ,144,194 ,244 ,294,344 ,394 ,444 ,494 544
45,95 ,145,195 ,245 ,295,345 ,395 ,445 ,495 545
46,96 ,146,196 ,246 ,296,346 ,396 ,446 ,496 546
47,97 ,147,197 ,247 ,297,347 ,397 ,447 ,497 547
48,98 ,148,198 ,248 ,298,348 ,398 ,448 ,498 548
49,99 ,149,199 ,249 ,299,349 ,399 ,449 ,499 549
50,100,150,200 ,250 ,300,350 ,400 ,450 ,500 550
								  

*/



/* EOF */
