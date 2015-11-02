/*------------------------------------------------------------------------------
* Created (c) 2013 - Factory “KyivPrylad”
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
* File Name       : cy7.c
* Description     : Functions and Data for Low Level Communication,
                    BO BR on CY7C024BV-20AXI

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  04/03/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/


//.#include "lpc32xx_chip.h"
//.#include "phy3250_board.h"
//.#include "lpc32xx_timer_driver.h"
//.#include "lpc32xx_intc_driver.h"
//.#include "lpc32xx_gpio_driver.h"
//.#include "lpc32xx_clkpwr_driver.h"
//.#include "lpc32xx_hsuart_driver.h"
//.#include "lpc32xx_uart.h"

#include <intrinsics.h>
#include <string.h>
#include    "lpu.h"

#include "cy7.h"

#include "../LIB/CDL_AV0/lpc/include/lpc_types.h"
#include "../LIB/CDL_AV0/lpc/include/lpc_irq_fiq.h"
#include "../LIB/CDL_AV0/lpc/include/lpc_arm922t_cp15_driver.h"
//
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_hsuart_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_intc_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_timer_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_dma_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_gpio_driver.h"


extern unsigned char chMemCY7;

#pragma data_alignment=4
static UNS_8 Cy7_txbuff [SIZE_LPDU_CNL_CY7+4];//,
#pragma data_alignment=4
static UNS_8  Cy7_rxbuff [SIZE_LPDU_CNL_CY7+4];//  @ "ICI_NC_BUFFERS";
volatile  int Cy7_txsize = 0, Cy7_rxsize = 0;

 int Cy7_txfill  = 0;
 int Cy7_rxget   = 0; 
 int Cy7_txget   = 0;
 int Cy7_rxfill  = 0;

long ram_semafor_br_1 = 0;
long ram_semafor_br_2 = 0;
long cy7_semafor_bm_1 = 0;
long cy7_semafor_bm_2 = 0;




//  Cy7_rxfill = hs1_txget = hs1_rxfill = 
//  Cy7_rxget = Cy7_txsize = Cy7_rxsize = 0;







//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long outCY7(UNS_8 *dat, int bytes)  @ "Fast_function";
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

long outCY7(UNS_8 *dat, int bytes)  @ "Fast_function"
{
    if (Cy7_txsize>bytes)
  {
	return 0;//Stop Do Something
  }
//  disable_irq();
  if ((Cy7_txfill == Cy7_txget)&&(Cy7_txsize==0))
  Cy7_txget = Cy7_txfill = 0;//.!!!
//  enable_irq();
  
  while (bytes > 0)
  {
    while ((bytes > 0) && (Cy7_txsize < SIZE_LPDU_CNL_CY7+1))
    {
       Cy7_txbuff [Cy7_txfill] = *dat;
      Cy7_txfill++;
      if (Cy7_rxfill >= SIZE_LPDU_CNL_CY7+1)
      {
        Cy7_txfill = 0;
      }
      dat++;
      bytes--;
       //disable_irq();//
      Cy7_txsize++;
      //enable_irq();//
    }

    //disable_irq();//
  
	//hs1_send_cb();Activate Remover
    //enable_irq();//
	CY7_send_cb();
  }
  return 0;
}
//---------------------------------------------------------------------------------
//extern INT_32 hs1uartdev;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long inCY7(UNS_8 *buff, int bytes)  @ "Fast_function";
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
long inCY7 (UNS_8 *buff, int bytes)  @ "Fast_function"
{

int bread = 0;
//char *pChCY7InBuf = (char*) ADR_AR_BR
  while ((bytes > 0) && (Cy7_rxsize > 0))
  {
     *buff =Cy7_rxbuff[Cy7_rxget];
    //*buff =  pChCY7InBuf[Cy7_rxget];
    buff++;
    Cy7_rxget++;
    if (Cy7_rxget >= SIZE_LPDU_CNL_CY7)
    {
      Cy7_rxfill -= Cy7_rxget;
	  Cy7_rxget = 0;
	  
    }
    bytes--;
    bread++;
     //disable_irq();//
    Cy7_rxsize--;
     //enable_irq();//
  }
  if (Cy7_rxfill == Cy7_rxget)
  {
	//disable_irq();//
	Cy7_rxfill = Cy7_rxget = 0;
	//enable_irq();//
  }

  return bread;
	
	
}
//---------------------------------------------------------------------------------

long LookReadMem(void)  @ "Fast_function"
{
register long i;
register long *pl;
register unsigned char *pCh;
struct 
	{
		unsigned char uchVl;//,uchRetVl;//,
		short shErrorRead,shUnEquSem;//chTotErr
		unsigned long cy7_semafor_bm_1;
		unsigned long cy7_semafor_bm_2;
		unsigned long cy7_ctrl_semafor_bm_1;
		unsigned long cy7_ctrl_semafor_bm_2;
		
} sLV;

sLV.shErrorRead = 0; sLV.shUnEquSem = 0;
//Block of Exchange Need Rewriting Later
	pl = (long*)ADR_FULLWORD_SEMAFOR_BM_1;
	sLV.cy7_semafor_bm_1 = pl[0];
	pl = (long*)ADR_FULLWORD_SEMAFOR_BM_2;
	sLV.cy7_semafor_bm_2 = pl[0];
	if(sLV.cy7_semafor_bm_1 == sLV.cy7_semafor_bm_2 )
	{
		//Set Busy Mem Info For Another Proc For Reding Operation
		if (sLV.cy7_semafor_bm_1==0 || sLV.cy7_semafor_bm_2==0)
		goto ExitLookReadMem;
		i = sLV.cy7_semafor_bm_1 - cy7_semafor_bm_1;
		if(i<0) i *= (-1);// !!!!!!!!!!!!!!! Is Allright ???
		//Now Detect Writing Exist
		if(i>=1)
		{
			pCh = (unsigned char*)ADR_AR_BM;
			//Copy Operation
			for (i = 0; i < (SIZE_LPDU_CNL_CY7) ;i++)
			{
				//Control State
				
				//Cy7_rxbuff[i] = pCh[i];
				sLV.uchVl =  pCh[i];
				pl = (long*)ADR_FULLWORD_SEMAFOR_BM_1;
				sLV.cy7_ctrl_semafor_bm_1 = pl[0];
				pl = (long*)ADR_FULLWORD_SEMAFOR_BM_2;
				sLV.cy7_ctrl_semafor_bm_2 = pl[0];
				//Compare Self
				if(sLV.cy7_ctrl_semafor_bm_1 != sLV.cy7_ctrl_semafor_bm_2)
				{
					sLV.shUnEquSem++;
					goto ExitLookReadMem;
				}
				//Compare Previous
				if(sLV.cy7_ctrl_semafor_bm_1 != sLV.cy7_semafor_bm_1)
				{
					sLV.shUnEquSem++;
					goto ExitLookReadMem;
				}
				if( sLV.uchVl== pCh[i] && sLV.shUnEquSem ==0)
				Cy7_rxbuff[i] = sLV.uchVl;
				else 
				{
					//Have Conflict!!!
					sLV. shErrorRead++;
					goto ExitLookReadMem;
				}
			}	
			
			//On Moment End Of Read another Proc can change Data Detect It
			pl = (long*)ADR_FULLWORD_SEMAFOR_BM_1;
			sLV.cy7_ctrl_semafor_bm_1 = pl[0];
			pl = (long*)ADR_FULLWORD_SEMAFOR_BM_2;
			sLV.cy7_ctrl_semafor_bm_2 = pl[0];
	
			if( 
			(sLV.cy7_ctrl_semafor_bm_2 != sLV.cy7_ctrl_semafor_bm_1)
			||( sLV.cy7_ctrl_semafor_bm_2 != sLV.cy7_semafor_bm_1 )
			
			)
				goto ExitLookReadMem;//Data In Buf Incorrect
			else
				{
				
				chMemCY7++;
				Cy7_rxfill  = Cy7_rxsize = i;
				//Save Semaphors
				cy7_semafor_bm_1 = sLV.cy7_semafor_bm_1;
				cy7_semafor_bm_2 = sLV.cy7_semafor_bm_2;
				return (-1);
				}
		
		}
		
	}


ExitLookReadMem:
return (sLV. shErrorRead + sLV.shUnEquSem);//0 - Nothing change (-1) -New Data else Errors

}
long DetectorActivity(void)  @ "Fast_function"
{ 
register long i;
register long *pl;
//register unsigned char *pCh;
struct 
	{
		unsigned char uchVl;//,uchRetVl;//,
		short shErrorRead,shUnEquSem;//chTotErr
		unsigned long cy7_semafor_bm_1;
		unsigned long cy7_semafor_bm_2;
//		unsigned long cy7_ctrl_semafor_bm_1;
//		unsigned long cy7_ctrl_semafor_bm_2;
		
} sLV;

sLV.shErrorRead = 0; sLV.shUnEquSem = 0;
	pl = (long*)ADR_FULLWORD_SEMAFOR_BM_1;
	sLV.cy7_semafor_bm_1 = pl[0];
	pl = (long*)ADR_FULLWORD_SEMAFOR_BM_2;
	sLV.cy7_semafor_bm_2 = pl[0];
	if(sLV.cy7_semafor_bm_1 == sLV.cy7_semafor_bm_2 )
	{
		//Set Busy Mem Info For Another Proc For Reding Operation
		if (sLV.cy7_semafor_bm_1==0 || sLV.cy7_semafor_bm_2==0)
		goto ExitDetectorActivity;
		i = sLV.cy7_semafor_bm_1 - cy7_semafor_bm_1;
		
		if(i)
		{
			sLV.uchVl = i;
			i = LookReadMem();
			//if ( i==(-1))
			
			if (i == 0 || i==(-1))
			return i;
			else
			{
				sLV.shUnEquSem = i;
				goto ExitDetectorActivity;
			}	
		
		}
		else
		{
			//Return 0;No Change
			goto ExitDetectorActivity;
		}
		
	
	}
	else
	{
		sLV. shErrorRead++;
		goto ExitDetectorActivity;
	}

	
	



ExitDetectorActivity:
return (sLV. shErrorRead + sLV.shUnEquSem);//0 - Nothing change (-1) -New Data else Errors
}

//. long ram_semafor_br_1 = 0;
//. long ram_semafor_br_2 = 0;
//. long cy7_semafor_bm_1 = 0;
//. long cy7_semafor_bm_2 = 0;



void CY7_send_cb(void)  @ "Fast_function"
{
INT_32 bwrite, tosend = SIZE_LPDU_CNL_CY7 - Cy7_txget;
register long i;
register long *pl;
register unsigned char *pCh;
struct 
	{
		unsigned char uchVl;//,uchRetVl;//,
		short shErrorWrite;//,
		short shCtr;

		unsigned long cy7_semafor_br_1;
		unsigned long cy7_semafor_br_2;
		//.unsigned long cy7_ctrl_semafor_bm_1;
		//.unsigned long cy7_ctrl_semafor_bm_2;
} sLV;		

sLV.uchVl = sLV.shCtr = sLV.shErrorWrite = 0;


  //if (tosend >Cy7_txsize)
  //{
  //  //tosend = Cy7_txsize;
  //}
//  if (tosend == 0)
//  {
//    phsuart->regptr->ctrl &= ~HSU_TX_INT_EN;
//  }
//  else
//  {
//    phsuart->regptr->ctrl |= HSU_TX_INT_EN;
//  }

  /* Write data */
  //bwrite = hs_uart_write( hs1uartdev, &hs1_txbuff[hs1_txget], tosend);//hsuartdev
	ram_semafor_br_2++;
	if (ram_semafor_br_2 == 0) ram_semafor_br_2++;
  
	//pl = (long*)ADR_FULLWORD_SEMAFOR_BR_1;
	//sLV.cy7_semafor_br_1 = pl[0];
	pl = (long*)ADR_FULLWORD_SEMAFOR_BR_2;
	pl[0] = ram_semafor_br_2;
	sLV.cy7_semafor_br_2 = pl[0];
	if(ram_semafor_br_2 != sLV.cy7_semafor_br_2 )
	{
		//Conflict Wait
		sLV.shCtr = 0x20;
		while(sLV.shCtr)
		sLV.shCtr--;
		pl[0] = ram_semafor_br_2;
		pl[0] = ram_semafor_br_2;
	}
	pCh = (unsigned char*)ADR_AR_BR;
	//Copy Operation
	for (i = 0; i < (SIZE_LPDU_CNL_CY7) ;i++)
	{
		
		pCh[i] = Cy7_txbuff[i];
		sLV.uchVl = pCh[i];
		if(sLV.uchVl != Cy7_txbuff[i])
		{
			//Conflict
			sLV.shCtr = 0x20;
			while(sLV.shCtr)
			sLV.shCtr--;
			sLV.uchVl = Cy7_txbuff[i];
			pCh[i] = sLV.uchVl;
			pCh[i] = sLV.uchVl;//For Ctrl
			
	
		}
		
	}
	ram_semafor_br_1++;
	if (ram_semafor_br_1 != ram_semafor_br_2) ram_semafor_br_1 = ram_semafor_br_2;
  
	
	pl = (long*)ADR_FULLWORD_SEMAFOR_BR_1;
	pl[0] = ram_semafor_br_1;
	sLV.cy7_semafor_br_1 = pl[0];
	if(ram_semafor_br_1 != sLV.cy7_semafor_br_1 )
	{
		//Conflict Wait
		sLV.shCtr = 0x20;
		while(sLV.shCtr)
		sLV.shCtr--;
		pl[0] = ram_semafor_br_1;
		pl[0] = ram_semafor_br_1;
	}


	bwrite = i;
  
  
  
  Cy7_txsize = Cy7_txsize - bwrite;
  Cy7_txget  = Cy7_txget + bwrite;
  if (Cy7_txget >= SIZE_LPDU_CNL_CY7+1)
  {
    Cy7_txget = 0;
  }


}

//Current  Alg
//One process Set firs 2 sem
//Start Write
//Set second Sem at the End
//
//Reader first control state two semaphors
//if Equ Start Read
//At the end of Read 
//
//


/*
Very Desirable use 4 pins for 2 Area Memory
2 pins for 1 Area
1 - Input Control   | // For current Area
1 - Output Control  | //

1 - Input Control   | // For current Area
1 - Output Control  | //




*/
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long outCY7Br(char *dat, int bytes)  @ "Fast_function";
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

long outCY7Br(char *dat, int bytes)  @ "Fast_function"
{
//register long bsend;
//Insert Control Collision 
long i = 0;
i = GPIO->p0_inp_state;
	if(i&0xf)
	{
		bytes = 0;//cOLLIZION
	}
	else
	{
	
GPIO->p0_outp_clr  = 0x30;//0xC
	GPIO->p0_outp_set = 0x10;
  memcpy((void*)ADR_AR_BR,(const void*)dat,bytes);
 // i = DmaMemCopy((long)Cy7_txbuff,(long)dat,(long )SIZE_LPDU_CNL_CY7);//ADR_AR_BM Cy7_txbuff
  
  do
  {
  i = DMAC->dma_chan[7].config_ch;
  }
  while (i&DMAC_CHAN_ACTIVE);
  //i = DMAC_CHAN_TRANSFER_SIZE();
  //DMAC->dma_chan[7].config_ch &= 0xfff80000; 
  GPIO->p0_outp_set = 0x20;
  GPIO->p0_outp_clr  = 0x30; 
  }
  return bytes;
}
//---------------------------------------------------------------------------------




long lP0In = 0;
long DetectorActivityV1(void)  @ "Fast_function"
{ 
long i = 0;

	i = GPIO->p0_inp_state;
	if(i&0xf)
	{
		;//cOLLIZION
	}
	else
	{
		 GPIO->p0_outp_set = 0x10;
		i = GPIO->p0_inp_state;
		if(i&0xf)
		{
			GPIO->p0_outp_clr  = 0x30;//Collision
		}
		else
		{
			GPIO->p0_outp_set = 0x20;
			 memcpy((void*)&hldrM2mLpduUnit.arUch[0],(const void*)ADR_AR_BM,SIZE_LPDU_CNL_CY7 );//ReadData	
			GPIO->p0_outp_clr  = 0x30;//
			chMemCY7++;
		}
	}
	

}

void CY7_send_cb1(void)  @ "Fast_function"
{



}
extern long timerWaitReqM2m;
void CY7_rv_cb(void)  @ "Fast_function"
{
register long i;
register void* pv;
pv  = (void*)&hldrM2mLpduTRUnit;
	
	if(chMemCY7 == 0)// !!!! Control protocol Leyer Collision
	{
	
	GPIO->p0_outp_set = 0x30;
	 memcpy((void*)&hldrM2mLpduUnit.arUch[0],(const void*)ADR_AR_BM,SIZE_LPDU_CNL_CY7 );//ReadData	
	// DmaMemCopy( (long)Cy7_rxbuff,ADR_AR_BM,SIZE_LPDU_CNL_CY7);
	i = ((TRStateLpuM2mDsc*)pv)->lCapicity;
	i+=2;
	if (i> SIZE_LPDU_CNL_CY7)
	i = SIZE_LPDU_CNL_CY7;
	//Write Data to Bm
	 memcpy((void*)ADR_AR_BR,(const void*)&(((TRStateLpuM2mDsc*)pv)->arUch[0]),i);
	i = 0;
	((TRStateLpuM2mDsc*)pv)->lCapicity = i;
	((TRStateLpuM2mDsc*)pv)->uchLpuM2mState = i;
	((TRStateLpuM2mDsc*)pv)->arUch[0] = i;((TRStateLpuM2mDsc*)pv)->arUch[1] = i;
	timerWaitReqM2m  = 2;
	GPIO->p0_outp_clr  = 0xf0;//
	chMemCY7++;
	}


}



DMAC_REGS_T *Dma_get_base(void);

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long DmaMemCopy(long lDst, long lSrc,long lAmt )   @ "Fast_function_no_cache";
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

long DmaMemCopy(long lDst, long lSrc,long lAmt )   @ "Fast_function_no_cache"
{
//register long i;
register long IdxChnl;
register void *pv;lAmt >>=2;
//Detect Source
pv = (void*)Dma_get_base();
IdxChnl = 7;
//IdxChnl = lAmt & 0xff; lAmt >>= 8;//Exclude Idx
//Clear any pending Interrupts on the channel
((DMAC_REGS_T*)pv)->int_tc_clear  = (1<<IdxChnl);//Must Later Selector allocate channel
((DMAC_REGS_T*)pv)->int_err_clear = (1<<IdxChnl);

((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].src_addr  = lSrc;
//((DMAC_CHAN_T*)pInitData)-> src_addr;
((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].dest_addr = lDst;//ADR_AR_BR;//
//((DMAC_CHAN_T*)pInitData)-> dest_addr;
//((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].lli       = 0;
//((DMAC_CHAN_T*)pInitData)-> lli;
((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].control   = 
( DMAC_CHAN_DEST_AUTOINC |//DMAC_CHAN_INT_TC_EN |
         DMAC_CHAN_SRC_AUTOINC |  //| DMAC_CHAN_DEST_AHB1 | DMAC_CHAN_SRC_AHB1 |
        DMAC_CHAN_DEST_WIDTH_32 |  //DMAC_CHAN_DEST_WIDTH_16 | //
         DMAC_CHAN_SRC_WIDTH_32 | DMAC_CHAN_DEST_BURST_4 |
         DMAC_CHAN_SRC_BURST_4 |
         DMAC_CHAN_TRANSFER_SIZE(lAmt));
//((DMAC_CHAN_T*)pInitData)-> control;
((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].config_ch = 
//((DMAC_CHAN_T*)pInitData)-> config_ch;
 (DMAC_CHAN_FLOW_D_M2M | DMAC_CHAN_ENABLE// |//.. DMAC_CHAN_ITC |DMAC_CHAN_IE
      );
	// lAmt = (long) 
//((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].config_ch

lAmt = ((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].control;
	  
return DMAC_CHAN_TRANSFER_SIZE(lAmt) ;
}
//,,	  while(
//,,(((DMAC_REGS_T*)pv)->dma_chan[IdxChnl].dest_addr) != (((long)pDst) +  lAmt)
//,,	  );

//---------------------------------------------------------------------------------

