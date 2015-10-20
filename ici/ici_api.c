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
* File Name       : ici_api.c
* Description     : Functions and Data for API,
                    interprocessor communication

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  13/08/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#include "ici_api.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_timer_driver.h"
#include    "lpu.h"
#include    "./inc/header.h"
extern long outU3(unsigned char*dat, int bytes);
extern long outU7(unsigned char*dat, int bytes);

extern int txfill, txsize, txget;
extern int rxsize, rxget,  rxfill;
extern int hs2_txsize, hs2_rxsize;


unsigned char chEntry_Ssp0 = 0;
unsigned char chNeedLookStatusSsp0 = 0;

unsigned char chEntry_Hs7 = 0;
unsigned char chHdwErorHSU7 = 0;
unsigned char chEntry_Hs1 = 0;
unsigned char chHdwErorHSU1 = 0;
unsigned char chEntry_Hs2 = 0;
unsigned char chHdwErorHSU2 = 0;
unsigned char chEOI_Hs2 = 0;
unsigned char chMemCY7  = 0;

unsigned long lTmrActivityRvCY7 = BR_TMR_ACTIVITY_RV_CY7_VAL;
unsigned long lTmrActivityTrCY7 = BR_TMR_ACTIVITY_TR_CY7_VAL;
unsigned long lTmrActivitySpi = 0x10000;


extern int hs7_txsize,hs7_txfill,hs7_txget;
extern int hs7_rxsize,hs7_rxget, hs7_rxfill;

extern long lTmrDisableHSU2, lTmrHSU2Val;
extern  long lDeltaTmrHSU2;

extern long timer0dev;



//...long outU7(UNS_8 *dat, int bytes);
char testbuff [512];
char *DemoStr =  "Hello world";
__TOTAL_MEASUREMENT total_measurement;
unsigned int volatile command_to_receive_current_data = 0;
int current_data_transmit[NUMBER_CANALS*NUMBER_POINT*NUMBER_PERIOD_TRANSMIT]; 
int current_data[(NUMBER_CANALS + 1)*NUMBER_POINT*NUMBER_PERIOD];


void Scan_Ici_Event_Req(void);
void Scan_Ici_Entry_Data(void);

unsigned long samples_data_rdy;

unsigned char meas_data_rdy;

long Samples_Ready_Handler(void* pv);


long Meas_Ready_Handler   (void* pv);
extern long lMaxTimeTransmit ;
static long IciCopy_samples_data_rdy;
long Samples_Ready_Handler(void* pv)  @ "Fast_function"
{
register long i=0;unsigned long uVl;
register long j;
	if (samples_data_rdy & 0x20000)
	{
		samples_data_rdy = 0;
		//i = outU3((unsigned char*)DemoStr, 11);
		//i = outU7((unsigned char*)DemoStr, 2);
		//---ActivateProxyTotMeas();
		//TestSetup_SrcSamples_ForTransmit();//
		j = PassPrtTblPrMngRvMsgOrigin();
		//..TestSetup_LpduHSU7_ForTransmit();
		//..ProcessTransmitLpduHSU7();
		//~.AppReqTransmitApcs++;
	}	
	//PrepDecompouseSrcSamplesUnit();- Move to Another function
	if( IciCopy_samples_data_rdy!=samples_data_rdy )
	{
		lTmrDisableHSU2 ++;
		IciCopy_samples_data_rdy = samples_data_rdy;
		if (hldrHSU2LpduTRUnit.uchLpuHSU2State)
		{
			//Timer Halt - Need Reinit Timer System
			if(lTmrDisableHSU2 >= 4)//if(lTmrDisableHSU2>lDelta)
			{
				hldrHSU2LpduTRUnit.uchLpuHSU2State = 0;lMaxTimeTransmit = 0;//goto TstLab;
				RstTmr0();
				lTmrDisableHSU2 = 0;		
			}
			
		}
		else lTmrDisableHSU2--;
		//TestSetup_SrcSamples_ForTransmit();//Activate Transmit Samples
		//.uVl = ((TIMER_CNTR_REGS_T *)TIMER_CNTR0)-> tc;
		//.if (uVl>=lMaxTimeTransmit)
		//.{
		//.i = uVl- (unsigned long)lMaxTimeTransmit;
		//.	if (i<0x10000)
		//.	i++;
		//.}
		//.else
		//.{
		//.	i = (-1) - (unsigned long)lMaxTimeTransmit; <- THIS IS FOR TEST ONLY TOO BUT IS WORKED
		//.	i += uVl;
		//.	i = ~i;
		//.}
		//.lMaxTimeTransmit = (long) uVl;
		//.	
		
	}
	//.uVl = ((TIMER_CNTR_REGS_T *)TIMER_CNTR0)-> tc;
	//.
	//.	if (uVl>=lMaxTimeTransmit)
	//.	{
	//.	i = uVl- (unsigned long)lMaxTimeTransmit;
	//.		if (i<0x10000)
	//.		i++;
	//.	}
	//.	else
	//.	{
	//.		i = (-1) - (unsigned long)lMaxTimeTransmit; <- THIS IS FOR TEST ONLY 
	//.		i += uVl;
	//.		i = ~i;
	//.	}
	//.	lMaxTimeTransmit = (long) uVl;
	//.	//Timer_delay_cmn(TIMER_CNTR0,10)	;
	
	//TimeOut for HSU2
	/*
	j = lTmrHSU2Val;//for Exlude die in interrupt
	uVl = ((TIMER_CNTR_REGS_T *)TIMER_CNTR0)-> tc;
	if (uVl>= j)//lTmrHSU2Val
	i = uVl- (unsigned long)j;//lTmrHSU2Val;
	else
	{
		if(((long)uVl)>0)//Move from Zero
		{
			if (j<0)//lTmrHSU2Val
			{
				i = (-1)*j;//lTmrHSU2Val;
				i +=uVl;
			}
			else goto Err;
		}
		else
		{
Err:			i = 0;//error Variables

		}
		//i = (-1) - (unsigned long)lTmrHSU2Val;
		//i += uVl;
		//i = ~i;
		
	}
	
	if (hldrHSU2LpduTRUnit.uchLpuHSU2State)//&&(hs2_txsize==0)
	{
		
		if(hs2_txsize)
		lTmrHSU2Val = uVl;//Reset counter
		else
		{
			if (i>lDeltaTmrHSU2*3)
			i++;//Detect distance
			if( (i>lDeltaTmrHSU2)&&lMaxTimeTransmit)
			{
				if (hs2_txsize==0)//You can insert in this place additonal vars for ctrl end Transmit 
				{
				hldrHSU2LpduTRUnit.uchLpuHSU2State = 0;lMaxTimeTransmit = 0;
				}
			}
		}
	
	}
	else
	{
		;//Always hold distance
		
		//if (i>=1000)//Time out more 1Ms
		{
			lTmrHSU2Val = uVl;
		}
	}
	*/
	if (hldrHSU2LpduTRUnit.uchLpuHSU2State)//&&(hs2_txsize==0)
	{
TstLab:		
		if(hs2_txsize)
		;//Reset counter
		else
		{
			//Control State HSU2
			if( chEOI_Hs2)
			{
				if(IsEOI_HS2())
				chEOI_Hs2 = 0;
			}
			pv = (void*)TIMER_CNTR0;j = ((TIMER_CNTR_REGS_T *)pv)->ir;j&= TIMER_CNTR_MTCH_BIT(0);//(( ((TIMER_CNTR_REGS_T *)pv)->ir & TIMER_CNTR_MTCH_BIT(0)) != 0 )
			if(j==0)
			{
				 uVl = ((TIMER_CNTR_REGS_T *)pv)->tc;
				 if (uVl >= 0x1f4)
				 while(1);
			
			}
			if(  j &&lMaxTimeTransmit)
			{
				if (hs2_txsize==0)//You can insert in this place additonal vars for ctrl end Transmit 
				{
					hldrHSU2LpduTRUnit.uchLpuHSU2State = 0;lMaxTimeTransmit = 0;((TIMER_CNTR_REGS_T *)pv)->tcr = TIMER_CNTR_TCR_RESET;
					//Clear timer
					//-* Stop timer *-/
					((TIMER_CNTR_REGS_T *)pv)->tcr = 0;
					((TIMER_CNTR_REGS_T *)pv)->tc  = 0;
					//-* Clear and enable match function *-/
					((TIMER_CNTR_REGS_T *)pv)->ir = TIMER_CNTR_MTCH_BIT(0);((TIMER_CNTR_REGS_T *)pv)->tcr = TIMER_CNTR_TCR_RESET;
					//TIMER_CNTR_TCR_RESET;
				}
			}
		}
	
	}
return 0;
}


long Meas_Ready_Handler   (void* pv)
{

return 0;
}

void Scan_Ici_Entry_Data(void)  @ "Fast_function"
{
register long i;
//Detect Input Data on HSUART7
	if (chEntry_Hs7)
	{
		//i = inU7(testbuff,11);
		chEntry_Hs7 = 0;
		ProcessReceiveLpduHSU7();
		
	}
//Detect Input Data on HSUART2
	if (chEntry_Hs2)
	{
		//i = inU7(testbuff,11);
		chEntry_Hs2 = 0;
		
		ProcessReceiveLpduHSU2();
		
	}
	if(chHSU2SendHdwEror)
	{
		RecoverHSU2();
	}
//Detect Input Data on HSUART1

//Detect Input Data on UART3

//Detect Input Data on SPI
	if(chEntry_Ssp0 >=2)
	{
		//if(ch)
		//ProcessReceiveLpduSsp0();
		//....StubForSpiChanel1();
		ProcessReceiveLpduSpi();if(chEntry_Ssp0!=2) for(;;);
		chEntry_Ssp0 -=2;
		hldrSpiLpduTRUnit.uchLpuSpiState = 0;//Clear Blocking Write to Spi Queue
		
	}

//Detect Input Data on Mem
	//Look change Mem
	//~~~DetectorActivityV1();
	/*
	if(lTmrActivityRvCY7)
	lTmrActivityRvCY7--;
	else
	{
		i = DetectorActivity();
		if(i )	//collission Detected
		{
			if(i==(-1))//Read OK
			lTmrActivityRvCY7 =  BR_TMR_ACTIVITY_RV_CY7_VAL;
			else
			lTmrActivityRvCY7 =  BR_TMR_ACTIVITY_RV_CY7_VAL + 37;
		}
		else 
		lTmrActivityRvCY7 =  BR_TMR_ACTIVITY_RV_CY7_VAL;//Not posibility to change interval
	}*/
	
	if(lTmrActivitySpi)
	lTmrActivitySpi--;
	else
	{
		lTmrActivitySpi = 0x10000;
		if (AppReqTransmitApcs > 3 || AppReqTransmitApcs == 0)//TERM)
		{
			AppReqTransmitApcs = 1;//START;//Fatal Error Situation
			AppReqTransmitGoosA = 1;
		}	
		//else AppReqTransmitApcs = 1;//START;//AppReqTransmitApcs++;//Activate Transmittion
	}
	if(chMemCY7)
	{
		//ProcessReceiveLpduCY7();chMemCY7 = 0;
		ProcessReceiveLpduCY7V1();chMemCY7 = 0;
	}

	ProcessReceiveEvt();
	UpdateAppData();

}
void Scan_Ici_Event_Req(void)  @ "Fast_function"
{
	if(samples_data_rdy)
    {
      //Handle  instant samplas values Ready 
      Samples_Ready_Handler((void*)0);
    }
    if(meas_data_rdy)
    {
      //Handle Measuring system data Ready
      Meas_Ready_Handler((void*)0);
    }
	ScanAppReq();
	//Transmit Data
	ProcessTransmitEvt();
//.	if(lTmrActivityTrCY7)//Test only
//.	lTmrActivityTrCY7--; //Test only
//.	else                 //Test only
//.	{ 
//.		CY7_send_cb();       //Test only
//.		lTmrActivityTrCY7 = 12;
//.	}
	ExecProxy();
//Activate Hdw connect SPI	
	if((lSsp0HdwState&4) == 0)
	{
		Ssp_Syncro4();//Ssp_Syncro3();//Ssp_Syncro1();
		//StubForSpiChanel();
	}

//Fix Result Hdw Test SPI
	if((lSsp0HdwState&0x4) == 4)
	{
		StubForSpiChanel();	
	}	
}


void ScanAppReq(void)
{


}











extern int spi1_rxsize;
void StubForSpiChanel(void)
{
register long i;

char ArTstData[600];
for( i = 0; i<560; i++)
ArTstData[i] = i+1;
//return; if i comment numbers change to ???
if (lSsp0HdwState & 4) 
{
return;
}
else
{
	//while(1)
	{
		OutSPIDma(ArTstData,512);
		return;
	}
}
//while(1)
i=  outSPI1(ArTstData, 512);//300

ArTstData[550] = 20;
i = 0;
while (spi1_rxsize <= 511)
i++;i*=10;
while(i--);
i = inSPI1(ArTstData, 512);
ArTstData[550] = 30;
}
void StubForSpiChanel1(void)
{
register long i;
/*
static char arCh[200] = {
0x41,0x42,0x42,0x43,0x44,0x45,0x42,0x42,0x43,0x43,//0x45,0x45,0x45,0x45,
0x41,0x42,0x42,0x43,0x44,0x45,0x42,0x42,0x43,0x43, //0x45,0x45,0x45,0x45,
0x41,0x42,0x42,0x43,0x44,0x45,0x42,0x42,0x43,0x43,//0x45,0x45,0x45,0x45,
0x41,0x42,0x42,0x43,0x44,0x45,0x42,0x42,0x43,0x43, //0x45,0x45,0x45,0x45,
0x41,0x42,0x42,0x43,0x44,0x45,0x42,0x42,0x43,0x43,//0x45,0x45,0x45,0x45,
0x41,0x42,0x42,0x43,0x44,0x45,0x42,0x42,0x43,0x43, //0x45,0x45,0x45,0x45,
0x41,0x42,0x42,0x43,0x44,0x45,0x42,0x42,0x43,0x43,//0x45,0x45,0x45,0x45,
0x41,0x42,0x42,0x43,0x44,0x45,0x42,0x42,0x43,0x43, //0x45,0x45,0x45,0x45,
0x41,0x42,0x42,0x43,0x44,0x45,0x42,0x42,0x43,0x43,//0x45,0x45,0x45,0x45,
0x41,0x42,0x42,0x43,0x44,0x45,0x42,0x42,0x43,0x43, //0x45,0x45,0x45,0x45,

0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,//0x45,0x45,0x45,0x45,
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45, //0x45,0x45,0x45,0x45,
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,//0x45,0x45,0x45,0x45,
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45, //0x45,0x45,0x45,0x45,
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,//0x45,0x45,0x45,0x45,
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45, //0x45,0x45,0x45,0x45,
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,//0x45,0x45,0x45,0x45,
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45, //0x45,0x45,0x45,0x45,
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,//0x45,0x45,0x45,0x45,
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45 //0x45,0x45,0x45,0x45,

};*/

char ArTstData[600];
i = inSPI1(ArTstData, 512);
ArTstData[550] = 30;


for( i = 0; i<560; i++)
ArTstData[i] = i+1;

i=  outSPI1(ArTstData, 512);//300

ArTstData[550] = 20;
i = 0;
while (spi1_rxsize <= 511)
i++;i*=10;
while(i--);

}





/* EOF */
