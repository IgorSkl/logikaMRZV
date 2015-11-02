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
#include "../LIB/CDL_AV0/lpc/include/lpc_types.h"
#include "../LIB/CDL_AV0/lpc/include/lpc_irq_fiq.h"
#include "../LIB/CDL_AV0/lpc/include/lpc_arm922t_cp15_driver.h"
//#include "ea3250_board.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_ssp_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_intc_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_timer_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_clkpwr_driver.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_dma_driver.h"

#include "lpc32xx_gpio_driver.h"
extern void send_cb_spi1(void);
extern void recv_cb_spi1(void);
extern  INT_32 sspdev0;


extern void Tci_recv_cb_ssp0(void)   @ "Fast_function";
extern void Tci_send_cb_ssp0(void)   @ "Fast_function";

extern void send_cb_ssp_Dma(void);
extern void recv_cb_ssp_Dma(void);

#define IDX_DMA_SSP0_MOSI 1
#define IDX_DMA_SSP0_MISO 0

long ssp1_hdr_init(void)
{
  SSP_CONFIG_T sspcfg;
   SSP_CBS_T loc_ssp_cb;
  UNS_8 data;
  UNS_16 addr;
  int bytes;
 disable_irq_fiq();
  /* Disable interrupts in ARM core */
  
   /* The SSP can control the SSEL signal, but will assert the signal
     at the start of a single FIFO entry's transfer and de-assert it
     after the FIFO entry is sent. Some blocks need the chip select to
     remain asserted for the entire cycle (such as this serial EEPROM)
     so a GPIO will be used instead. */
  //GPIO->p2_mux_clr = P2_GPIO05_SSEL0;
  //GPIO->p2_dir_set = P2_DIR_GPIO(5);//30-bit
  //GPIO->p3_outp_set = P3_STATE_GPIO(5);//30-bit
  //GPIO->p3_outp_clr = P3_STATE_GPIO(5);//30-bit
  //bytes = GPIO->p3_outp_state;
  //data = bytes);

  GPIO->p2_mux_set = P2_GPIO05_SSEL0;
  /* The MISO, MOSI, and SCK signals are controlled by the SSP */
  GPIO->p_mux_set = (P_SPI1DATAIO_SSP0_MOSI |
                        P_SPI1DATAIN_SSP0_MISO | P_SPI1CLK_SCK0);
//CLKPWR->clkpwr_spi_clk_ctrl |= CLKPWR_SPICLK_USE_SPI1;/??
  /* Open SSP */
  sspcfg.databits = 16;
  sspcfg.mode = SSP_CR0_FRF_SPI;
  sspcfg.highclk_spi_frames = FALSE;
  sspcfg.usesecond_clk_spi = FALSE;
  sspcfg.ssp_clk = 12000000;//
  sspcfg.master_mode = TRUE;
  sspdev0 = Ssp_open(SSP0, (INT_32) & sspcfg);
  loc_ssp_cb.txcb = send_cb_spi1;
  loc_ssp_cb.rxcb = recv_cb_spi1;
  Ssp_ioctl(sspdev0, SSP_SET_CALLBACKS,(INT_32)&loc_ssp_cb);

   if (sspdev0 == 0)
  {
    /* Error */
    return -1;
  }
  
  //bytes = Ssp_ioctl(sspdev0, SSP_ENABLE_LOOPB, 1);//0-disable
  Int_disable1(IRQ_SSP0);
  int_install_irq_handler(IRQ_SSP0,Ssp0_int);

  bytes = Ssp_ioctl(sspdev0, SSP_ENABLE, 1);
  //  Ssp_Syncro();
  //Int_enable1(IRQ_SSP0);
  //bytes = Ssp_ioctl(sspdev0, SSP_ENABLE, 1);
    
  //Init SSP_Control
   *((long*)0x40004078) |= 3<<2;//Connect Spi to Dma
   *((long*)0x20084024)  = 0;//Disable chanels
   *((long*)0x20084014)  = 0;//Disable Spi Interrupt
   //allc Dma chanel
   
  //Init Dma Controller
  bytes = Dma_init();
  bytes = Dma_alloc_channel(IDX_DMA_SSP0_MOSI,send_cb_ssp_Dma);
  bytes = Dma_alloc_channel(IDX_DMA_SSP0_MISO,recv_cb_ssp_Dma);
  //Dma channel
  enable_irq_fiq();
return  bytes;
}


static char chInSend_cb_ssp = 0;
void send_cb_ssp_Dma(void)
{
long lV;
register void *pv;

  pv = (void*)Dma_get_base();
	lV = ((DMAC_REGS_T*)pv)->int_stat;
	if(lV&(DMAC_GET_CHAN_POS(IDX_DMA_SSP0_MOSI)))
	{
		chInSend_cb_ssp++;
		//Detect Type Int
		lV = ((DMAC_REGS_T*)pv)->int_tc_stat;
		if(lV&(DMAC_GET_CHAN_POS(IDX_DMA_SSP0_MOSI)))
		Tci_send_cb_ssp0();//Hundle Terminal Interrupt
		lV = ((DMAC_REGS_T*)pv)->int_err_stat;
		if(lV&(DMAC_GET_CHAN_POS(IDX_DMA_SSP0_MOSI)))
		{
			//Now simply Clear Req
			((DMAC_REGS_T*)pv)->int_err_clear = DMAC_GET_CHAN_POS(IDX_DMA_SSP0_MOSI);
		}
	}
  
chInSend_cb_ssp++;

}


static char chInRecv_cb_ssp = 0;
void recv_cb_ssp_Dma(void)
{
  long lV;
  register void *pv;

   pv = (void*)Dma_get_base();
	lV = ((DMAC_REGS_T*)pv)->int_stat;
	if(lV&(DMAC_GET_CHAN_POS(IDX_DMA_SSP0_MISO)))
	{
		chInRecv_cb_ssp++;
		//Detect Type Int
		lV = ((DMAC_REGS_T*)pv)->int_tc_stat;
		if(lV&(DMAC_GET_CHAN_POS(IDX_DMA_SSP0_MISO)))
		Tci_recv_cb_ssp0();//Hundle Terminal Interrupt
		lV = ((DMAC_REGS_T*)pv)->int_err_stat;
		if(lV&(DMAC_GET_CHAN_POS(IDX_DMA_SSP0_MISO)))
		{
			//Now simply Clear Req
			((DMAC_REGS_T*)pv)->int_err_clear = DMAC_GET_CHAN_POS(IDX_DMA_SSP0_MISO);
		}
	}
	
	
}

long lBlockSpiCtr = 100000;
void SpiStallHundler(void)
{
//Fix Error Crash SPI channel
  #ifdef _STATIC_MEMORY_BOOT 
  lBlockSpiCtr = 1000000;return;
	//Flash
	 for(;;)
  __asm volatile("BKPT 4");//Wait Very Long Time
  #else
lBlockSpiCtr = 100000;
  #endif



}




