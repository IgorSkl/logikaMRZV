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
* File Name       : AppCn.c
* Description     : Functions and Data application Layer
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  10/09/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#include    "./inc/header.h"
#include "./inc/type_definition_BL.h"
#include    "ApCn.h"
#include    "CTpu.h"
#include    "lpu.h"
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_timer_driver.h"
#include    "PrCmn.h"
#include    "MnPrPrt.h"
#include <intrinsics.h>



long lActualPrTrObj;
long timerWaitReqHSU2 = (0);
long timerWaitReqHSU1 = (0);
long timerWaitReqHSU7 = (0);
long timerWaitReqM2m = (0);
long timerWaitReqSpi = (0);
int TestReqTransmitT1;
int TestReqReceiveT1;

SrcSamplesUnitDsc  holderSrcSamplesUnit = {
{
0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
23, 24, 25, 26, 27, 28, 29, 30, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45,
 46, 47, 48

}
};

//long(*PFL_VL)(void* pv, long lV);
long InitProxyTenPerSamples (void* pv, long lV);
long WorkProxyTenPerSamples (void* pv, long lV);
long ResetProxyTenPerSamples (void* pv, long lV);
long ExecCmdProxyTenPerSamples (void* pv, long lV);
ProxyTenPerSamplesUnitDsc  holderProxyTenPerSamplesUnit = {
{
ID_TEN_PERIOD_SAMPLES_UNIT,
0,0,0,0,0,
(unsigned char*)0,(unsigned char*)0,
//(PFL_VL)0,(PFL_VL)0,(PFL_VL)0,(PFL_VL)0
InitProxyTenPerSamples,ResetProxyTenPerSamples,WorkProxyTenPerSamples,ExecCmdProxyTenPerSamples
},

// arUchExecCmd[4] = {
                   {0,0,0,0},
///arUchRvParamCmd[32] = {
{0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0 } 
};
int TestReqTransmitTenPerSamples;
int TestReqReceiveTenPerSamples;

ProxyTotMeasUnitDsc  holderProxyTotMeasUnit = {
{
ID_TOTAL_MEAS_UNIT,
0,0,0,0,0,
(unsigned char*)0,(unsigned char*)0,
//(PFL_VL)0,(PFL_VL)0,(PFL_VL)0,(PFL_VL)0
InitProxyTotMeas,ResetProxyTotMeas,WorkProxyTotMeas,ExecCmdProxyTotMeas
},

// arUchExecCmd[4] = {
                   {0,0,0,0},
///arUchRvParamCmd[32] = {
{0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0 } 
};
int TestReqTransmitTotMeas;
int TestReqReceiveTotMeas;


int TestReqTransmitT2;
int TestReqReceiveT2;
SrcAPCSUnitDsc   holderSrcAPCSUnit;


int TestReqTransmitT3;
int TestReqReceiveT3;

SrcTest1UnitDsc holderSrcTest1Unit;
static long lMaxTimeOut = 0;
extern long lTmrDisableHSU2;extern unsigned long lTmrHSU2Val;
extern long lDelta ;extern  long lDeltaTmrHSU2;extern  char chEndTransmitHSU2;















void ProcessTransmitEvt(void)   @ "Fast_function"
{
register long i;
unsigned long uVl;
register void *pv;
struct 
	{

		//char chFld1,chFld2,chFld3,chFld4;
		char chTrCnl1,chTrHSU1,chTrHSU2,chTrHSU7;//chFld2,chFld3,chFld4;
		char chTrM2m,chTrSpi;
		char chRetCode,chBusyChnl;
		unsigned short ushIdObj;
	    //.unsigned char *pUchTR;//
		//void  *pOriginTR, *pOriginTpCn;
		
	} sLV;
sLV.chBusyChnl = 0;sLV.chTrHSU7 = 0;sLV.chTrHSU1 = 0;sLV.chTrHSU2 = 0;uVl = 0;
	pv = (void*)&hldrTpCnState; sLV.chTrM2m = 0;sLV.chTrSpi = 0;
	i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_1;
	//Control then All Channels Full
	if(i<4)
	{
		sLV.chBusyChnl |= 1; 
	}
	//Insert HSU7
	//.i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_2;
	//.if(i<4)
	//.{
	//.	sLV.chBusyChnl |= 2; 
	//.}
	//Add here additional Logic for control another Layer state
	if((sLV.chBusyChnl&3) == 3 )
	goto DecomposeDataCnl2;//return;
	//Transmit on Phys Leyer
	
	
DecomposeDataCnl2:
 
    //if(lTmrDisableHSU2>lDelta)
	
	if( hldrHSU2LpduTRUnit.uchLpuHSU2State==0)// &&(lTmrAcivatorRawSamples ==0))
	{
		PrepDecompouseSrcSamplesUnitHSU2();
		//PrepDecompouseTotMeasGUnitHSU2();
		PrepDecompouse10PeriodUnitHSU2();
		PrepDecompouseTotMeasUnitHSU2();
		//PrepDecompouseSettingsPrMngHSU2();
		//PrepDecompouseStngTptUnitHSU2();
		//PrepDecompouseYustTptUnitHSU2();
		//PrepDecompouse Xxx Test1Unit
		
		i = ((StateTpCnDsc*)pv)-> uchTpState_CNL_HSU2;
		if (i)
		{
			if (i&(1<<7))//Channel Full
			{
				sLV.chTrHSU2 = 2;//Transmition should start
				
			}
			else
			{
				if(i>=1)//Any Obj Full his data. And you should control TimeOut Wait for Req
				{
					if(timerWaitReqHSU2&0xfffffff8) timerWaitReqHSU2  = 5;//This Temporary Code for Permit Usual Tranmitting
					
					if(timerWaitReqHSU2>0)//timerWaitReq
					timerWaitReqHSU2--;
					if(timerWaitReqHSU2==0)//timerWaitReq==0|| timerWaitReq>= 2000<-Max time waiting Req )
					{
						sLV.chTrHSU2 = 1;//Transmition should start
					}	
				}
			}
			
		
		}
		else
		goto temp_lab;//DecomposeDataCnl1;//return;
		// Transmition data on HSU7
		if(sLV.chTrHSU2)
		{
			//StartTrasmit:
			//if(lTmrDisableHSU2>lDelta)
			ProcessTransmitLpduHSU2();lTmrDisableHSU2 = 0;//lTmrHSU2Val = ((TIMER_CNTR_REGS_T *)TIMER_CNTR0)-> tc;	
			timerWaitReqHSU2 = (-1);//This do for permit start after Curr Samples Ready Now Reset this Timer after first Req RDY
			
		}
temp_lab:		
		//-test  code.if((chEndTransmitHSU2<250)&&(chEndTransmitHSU2>0))
		//-test  code.{if( hldrHSU2LpduTRUnit.uchLpuHSU2State==0) outU2((unsigned char *)&hldrHSU2LpduTRUnit.arUch[0],0x00000043);hldrHSU2LpduTRUnit.uchLpuHSU2State = 1;//.((StateTpCnDsc*)pv)-> uchTpState_CNL_HSU2 += 1;  outU2((unsigned char *)&hldrHSU2LpduTRUnit.arUch[0],0x00000043);//ProcessTransmitLpduHSU2();
		;//-test  code.}
	}
DecomposeDataCnl1:
;
	if( (hldrHSU1LpduTRUnit.uchLpuHSU1State==0))//&&(lTmrAcivatorRawSamples ==0))
	{
		//PrepDecompouseRawSamplUnitHSU1();//,ProcessTransmitLpduHSU1();
		i = ((StateTpCnDsc*)pv)-> uchTpState_CNL_HSU1;
		if (i)
		{
			if (i&(1<<7))//Channel Full
			{
				sLV.chTrHSU1 = 2;//Transmition should start
				
			}
			else
			{
				if(i>=1)//Any Obj Full his data. And you should control TimeOut Wait for Req
				{
					if(timerWaitReqHSU1>0)//timerWaitReq
					timerWaitReqHSU1--;
					if(timerWaitReqHSU1==0)//timerWaitReq==0|| timerWaitReq>= 2000<-Max time waiting Req )
					{
						sLV.chTrHSU1 = 1;//Transmition should start
					}	
				}
			}
			
		
		}
		else 
		goto DecomposeDataCnl7;
		if(sLV.chTrHSU1)
		{
			//StartTrasmit:
			//if(lTmrDisableHSU2>lDelta)
			//ProcessTransmitLpduHSU1();
			//lTmrDisableHSU1 = 0;//lTmrHSU2Val = ((TIMER_CNTR_REGS_T *)TIMER_CNTR0)-> tc;	
			timerWaitReqHSU1 = (-1);
		}
		
	
	}

DecomposeDataCnl7:	
;
/*	PrepDecompouseSrcSamplesUnit();
	
	
	//PrepDecompouse Xxx Test1Unit
	i = ((StateTpCnDsc*)pv)-> uchTpState_CNL_HSU7;
	if (i)
	{
	    if (i&(1<<7))//Channel Full
	    {
		    sLV.chTrHSU7 = 1;//Transmition should start 
		}
		else
		{
		    if(i>1)//Any Obj Full his data
			{
			    sLV.chTrHSU7 = 1;//Transmition should start
			}
		}
		
	
	}
	else
	return;
	// Transmition data on HSU7
	if(sLV.chTrHSU7)
	{
	    ProcessTransmitLpduHSU7();
	
	}
	*/
	
	
	if( hldrM2mLpduTRUnit.uchLpuM2mState==0)
	{
		//PrepDecompouseTotMeasRUnitM2m();
		//PrepDecompouseDiagnostic
		PrepDecompouseAuxStngUnitM2m();
		
		i = ((StateTpCnDsc*)pv)-> uchTpState_CNL_M2m;
		if (i)
		{
			if (i&(1<<7))//Channel Full
			{
				sLV.chTrM2m = 2;//Transmition should start
				
			}
			else
			{
				if(i>=1)//Any Obj Full his data. And you should control TimeOut Wait for Req
				{
					if(timerWaitReqM2m&0xfffffff8) timerWaitReqM2m  = 2;//This Temporary Code for Permit Usual Tranmitting
					
					if(timerWaitReqM2m>0)//timerWaitReq
					timerWaitReqM2m--;
					if(timerWaitReqM2m==0)//timerWaitReq==0|| timerWaitReq>= 2000<-Max time waiting Req )
					{
						sLV.chTrM2m = 1;//Transmition should start
					}	
				}
			}
			
		
		}
		else
		goto EndBlockM2mState;//DecomposeDataCnl1;//return;
		// Transmition data on HSU7
		if(sLV.chTrM2m)
		{
			//StartTrasmit:
			//if(lTmrDisableM2m>lDelta)
			ProcessTransmitLpduM2m();
			//lTmrDisableM2m = 0;//lTmrM2mVal = ((TIMER_CNTR_REGS_T *)TIMER_CNTR0)-> tc;	
			timerWaitReqM2m = (-1);//This do for permit start after Curr Samples Ready Now Reset this Timer after first Req RDY
			
		}
EndBlockM2mState:		
    ; 
	}
	;
	
	if( hldrSpiLpduTRUnit.uchLpuSpiState==0)//For Hardware Reason SPI can come to state blocked very long Time control this and try Reset 
	{
		PrepDecompouseTeleMechsUnitSpi();
//		PrepDecompouseApcsUnitSpi();
//		PrepDecompouseGoosAUnitSpi();
		PrepDecompousePrtTblTptUnitSpi();//..PrepDecompousePrtTblTptUnitHSU2();
		PrepDecompouseDiagnUnitSPI();
		PrepDecompouseTotVerInfoUnitHSU2();
		
//		PrepDecompouseGoosAUnitSpi();//Next Iteration
		i = ((StateTpCnDsc*)pv)-> uchTpState_CNL_Spi;
		if (i)
		{
			if (i&(1<<7))//Channel Full
			{
				sLV.chTrSpi = 2;//Transmition should start
				
			}
			else
			{
				if(i>=1)//Any Obj Full his data. And you should control TimeOut Wait for Req
				{
					if(timerWaitReqSpi&0xfffffff8) timerWaitReqSpi  = 5;//This Temporary Code for Permit Usual Tranmitting
					
					if(timerWaitReqSpi>0)//timerWaitReq
					timerWaitReqSpi--;
					if(timerWaitReqSpi==0)//timerWaitReq==0|| timerWaitReq>= 2000<-Max time waiting Req )
					{
						sLV.chTrSpi = 1;//Transmition should start
					}	
				}
			}
			
		
		}
		else
		goto EndBlockSpiState;//DecomposeDataCnl1;//return;
		// Transmition data on HSU7
		if(sLV.chTrSpi)
		{
			//StartTrasmit:
			//if(lTmrDisableSpi>lDelta)
			ProcessTransmitLpduSpi();//<--  ProcessTransmitStubSeqSpi();
			//lTmrDisableSpi = 0;//lTmrSpiVal = ((TIMER_CNTR_REGS_T *)TIMER_CNTR0)-> tc;	
			timerWaitReqSpi = (-1);//This do for permit start after Curr Samples Ready Now Reset this Timer after first Req RDY
			
		}
EndBlockSpiState:
		if(timerWaitReqSpi == 0 || timerWaitReqSpi == (-1)) ProcessTransmitStubSeqSpi();
;	
	}
	else
	{
		if(lBlockSpiCtr != 0)
		//Decrease Timer SPI Block
		lBlockSpiCtr--;
		else//
		{
			//Call Handler ReInit SPI State
			SpiStallHundler();
		}
	
	}
	
ExitProcessTransmitEvt:	
;
return;
}
//void ProcessTransmitEvt1(void)
//{
//register long i;
//	//Control then All Channels Full
//	if()
//	{
//	
//	}
//	//Control State Obj if Need Transmit
//	//Process
//	if()
//	{
//		//Control State Channel
//		//If busy - Try another
//		if()
//		{
//			//ProcessTransmit Obj
//			if()
//			{
//				
//			}
//		}
//		//Try another
//		
//	}
//	
//
//}
void PrepDecompouseSrcSamplesUnit(void)
{
register long i,j;
register void *pv;
	pv = (void*)&hldrTpCnState;
	//Control then All Channels Full
	//.if()
	//.{
	//.
	//.}
	//Control State Obj if Need Transmit
	//Process
	if(TestReqTransmitT1)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_HSU7;j = sizeof(SrcSamplesUnitDsc)>>2;
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (TestReqTransmitT1==START)
			{
				ActivateServTrApCnSamplesCTpuUnit();
				TestReqTransmitT1 = EXEC;
			}
			//ProcessTransmit Obj
			if(TestReqTransmitT1==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRSrcSamplesCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					TestReqTransmitT1 = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<7))//channel Full
				{
					TestReqTransmitT1 = EXEC;//Activate Channel transmition and Set Zapret vizova ses poka ne otrabotaet chanel transmit LPU
					
					//((StateTpCnDsc*)pv)-> 
				}

				if (TestReqTransmitT1==TERM)
				{
					//.TerminateServiceApCn((void*)& holderSrcSamplesUnit,ID_SRC_SAMPLES_UNIT);
					TestReqTransmitT1 = 0;
				}
			}
		}
		//Try another???
		
	}
	

}
void PrepDecompouseSrcSamplesUnitHSU2(void)
{
register long i,j;
register void *pv;
	pv = (void*)&hldrTpCnState;
	//Control then All Channels Full
	//.if()
	//.{
	//.

	//.}
	//Control State Obj if Need Transmit
	//Process
	if(TestReqTransmitT1)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_HSU2;j = sizeof(SrcSamplesUnitDsc)>>2;
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (TestReqTransmitT1==START)
			{
				ActivateServTrApCnSamplesCTpuUnitHSU2();
				TestReqTransmitT1 = EXEC;
			}
			//ProcessTransmit Obj
			if(TestReqTransmitT1==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRSrcSamplesCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					TestReqTransmitT1 = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<7))//channel Full
				TestReqTransmitT1 = EXEC;//Activate Channel transmition and Set Zapret vizova ses poka ne otrabotaet chanel transmit LPU

				if (TestReqTransmitT1==TERM)
				{
					//.TerminateServiceApCn((void*)& holderSrcSamplesUnit,ID_SRC_SAMPLES_UNIT);
					TestReqTransmitT1 = 0;
				}
			}
		}
		//Try another???
		
	}
	

}


/*
void ProcessTransmitEvt1(void)
{
register long i;
	
	//	//Control then All Channels Full
 	if()
 	{
		return;
 	}
	//Select Obj
	i = SelectObj();
	//Handle Selected Obj
	HBgnTrSrcSamplesUnit();
	
}

long SelectObj(void)
{
register long i,j;
register void *pv;
struct 
	{

		//char chFld1,chFld2,chFld3,chFld4;
		char chRetCode;
		unsigned short ushIdObj;
	    //.unsigned char *pUchTR;//
		//void  *pOriginTR, *pOriginTpCn;
		
	} sLV;
union 
    {
    	unsigned char   uchAr [4];
    	unsigned short  ushAr [2];
        unsigned long   ulVal;
    }unnV1;
//Look Param SrcSamplesUnit
	sLV.ushIdObj = 0;
//Look Param SrcTest1Unit
	
	return sLV.ushIdObj;
}
long PrepareDecompouseTrEvt(long lIdObj)
{

	return 0;//Return Handle Data 
}

*/
long lAmtScanChnlSpiErrors = 0;
long lAmtScanChnlM2mErrors = 0;

void ProcessReceiveEvt(void)   @ "Fast_function"
{
register long i;
register void *pv;
struct 
	{

		//char chFld1,chFld2,chFld3,chFld4;
		char chRetCode,chBusyChnl;
		unsigned short ushIdObj;
	    //.unsigned char *pUchTR;//
		//void  *pOriginTR, *pOriginTpCn;
		
	} sLV;
sLV.chBusyChnl = 0;i = 0;
	pv = (void*)&hldrHSU7LpduUnit;
	if( ((RVStateLpuHSU7Dsc*)pv)->uchLpuHSU7State == 1 )
	i = ScanCnl(ID_CNL_HSU7);
	if (i==0 || i==0xff )
	((RVStateLpuHSU7Dsc*)pv)->uchLpuHSU7State = 0;
	else
	{
		;//Handle Error !!!!!!!!!
	}
	pv = (void*)&hldrHSU2LpduUnit;
	if( ((RVStateLpuHSU2Dsc*)pv)->uchLpuHSU2State == 1 )
	i = ScanCnl(ID_CNL_HSU2);
	if (i==0 || i==0xff )
	((RVStateLpuHSU2Dsc*)pv)->uchLpuHSU2State = 0;
	else
	{
		;//Handle Error !!!!!!!!!
	}
	pv = (void*)&hldrM2mLpduUnit;
	if( ((RVStateLpuM2mDsc*)pv)->uchLpuM2mState == 1 )
	i = ScanCnl(ID_CNL_M2M);
	if (i==0 || i==0xff )
	((RVStateLpuM2mDsc*)pv)->uchLpuM2mState = 0;
	else
	{
		lAmtScanChnlM2mErrors++;//Handle Error !!!!!!!!!
		((RVStateLpuM2mDsc*)pv)->uchLpuM2mState = 0;
	}
	pv = (void*)&hldrSpiLpduUnit;
	if( ((RVStateLpuSpiDsc*)pv)->uchLpuSpiState == 1 )
	i = ScanCnlSpi(ID_CNL_SPI);//i = ScanCnl(ID_CNL_SPI);
	if (i==0 || i==0xff )
	((RVStateLpuSpiDsc*)pv)->uchLpuSpiState = 0;
	else
	{
		 lAmtScanChnlSpiErrors++;//Handle Error !!!!!!!!!
		((RVStateLpuSpiDsc*)pv)->uchLpuSpiState = 0;
	}
	
	
	//.if( ((RVStateLpuCn1Dsc*)pv)->uchLpuCn1State )
	//.//ExtractLdcCnl1
	//.ScanCnl1Data();
	
	//Control Process Receive Object Verification



}

void SamplesRvServCTpuApCnUnit(void);

void UpdateAppData(void)   @ "Fast_function"
{
//Hundle here All Ses Fix Msg 
	if (TestReqReceiveT1)
	{
		SamplesRvServCTpuApCnUnit();
		
	}
	if(AppReqReceiveTotMeasR)
	{
		TotMeasRRvServCTpuApCnUnit();
	}
}

void SamplesRvServCTpuApCnUnit(void)
{
register long i,j;
register char *pch;
register void* pv;
//Detect if Data Not Used Update


//Copy
  pch = (char *)&( holderRVSrcSamplesCTpuUnit.arUchRV);
  pv  = (void*)& holderSrcSamplesUnit;
  j = sizeof(SrcSamplesUnitDsc);
  for (i = 0; i < j; i++)
  {
     ((char*)pv)[i] = pch[i];
  }
  //Reset Connect State
//   pv  = (void*)& (holderTRSrcSamplesCTpuUnit.TrCnHldr);
   
//.   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_HSU7;// If need change
//.   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_HSU7;// Logic can ctrl
//.   
//.  
//.   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
//.   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = sizeof(SrcSamplesUnitDsc);
//.   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_SRC_SAMPLES_UNIT;
//.   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
//.   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)& holderTRSrcSamplesCTpuUnit.arUchTR;
   TestReqReceiveT1 = 0;
   //Set Addition data for Use Data
   
}



void TestSetup_SrcSamples_ForTransmit(void)
{
 TestReqTransmitT1 = START;
hldrTpCnState.uchTpState_CNL_HSU2  += 0;

/*
hldrTpCnState.uchTpState_CNL_HSU2  = 1;
hldrTpCnState.PayloadLPDU_HSU2     = //SIZE_LPDU_CNL_HSU7
0;//(SIZE_LPCI_FLD_CNL_HSU7+SIZE_LDC_FLD_CNL_HSU7);
hldrTpCnState.lCapicity_CNL_HSU2   = SIZE_LPDU_CNL_HSU2
-(SIZE_LPCI_FLD_CNL_HSU2+SIZE_LDC_FLD_CNL_HSU2+SIZE_CS_FLD_CNL_HSU2+SIZE_TOTAL_LDC );
hldrTpCnState.pUchLpuTR_CNL_HSU2   = (unsigned char*)&hldrHSU2LpduTRUnit.arUch[SIZE_LPCI_FLD_CNL_HSU2+SIZE_LDC_FLD_CNL_HSU2+SIZE_TOTAL_LDC];//DemoStr;




hldrHSU2LpduTRUnit.uchLpuHSU2State = 0;
//	unsigned char      arUch[SIZE_LPDU_CNL_HSU7];//0   Data  field

	
hldrHSU2LpduTRUnit.lCapicity  = 0;//
hldrHSU2LpduTRUnit.uchCI      = 0;
hldrHSU2LpduTRUnit.ushSizeLDC = 0;
hldrHSU2LpduTRUnit.lCs        = 0;
*/


}

void ExecExistProxyManager(void* pvPrMng)   @ "Fast_function"
{
    //register void* pv;
	register long i,j;
	struct 
	{
		unsigned char uChIdxBit ;
		//short shErr;
		//unsigned short ushSizeLDC;
		//unsigned short IdConObj;
		//void *pOriginLDC;
		PFL_VL pfl_vl;
	} sLV;
	//PFL_VL pfl_vl;
	sLV.uChIdxBit = 0;
	
	
	//pv = (void*)&holderProxyTenPerSamplesUnit;
	i = ((ProxyMangerStateDsc*)pvPrMng)-> shPrMngConState;
	
	j = (i&(PM_STT_USING_OCS_MSK)); 
	if (j==0) return;
	
	j = ((i&PM_STT_WORK_OCS_MSK)== 0 )&& (i&(PM_STT_START_OCS_MSK));
	j = (i&(PM_STT_WORK_OCS_MSK));
	j = (i&(PM_STT_START_OCS_MSK));
	if (j)
	sLV.uChIdxBit =  PM_STT_START_OCS_ONB;
	j =  (i&(PM_STT_WORK_OCS_MSK)) && ((i&( PM_STT_STOP_OCS_MSK ))==0);
	if (j)
	sLV.uChIdxBit =  PM_STT_WORK_OCS_ONB;
	j = (i&(PM_STT_STOP_OCS_MSK));
	if (j)
	sLV.uChIdxBit =  PM_STT_STOP_OCS_ONB;
	 
	if(sLV.uChIdxBit)
	{
	    i = (long)((ProxyMangerStateDsc*)pvPrMng)-> pf_Work;
		if(i)
		{
			sLV.pfl_vl = (PFL_VL)i;
			i = sLV.pfl_vl(pvPrMng,sLV.uChIdxBit);//sLV.IdConObj);Mow Only One Cmd
		}	
	}
	



}
void ExecExistProxy(void* pvProxy)   @ "Fast_function"
{
    //register void* pv;
	register long i,j;
	struct 
	{
		unsigned char uChIdxBit ;
		//short shErr;
		//unsigned short ushSizeLDC;
		//unsigned short IdConObj;
		//void *pOriginLDC;
		PFL_VL pfl_vl;
	} sLV;
	//PFL_VL pfl_vl;
	sLV.uChIdxBit = 0;
	
	
	//pv = (void*)&holderProxyTenPerSamplesUnit;
	i = ((BaseAcpuCMUnitDsc*)pvProxy)-> AppObjConState;
	
	j = (i&(USING_OCS_MSK)); 
	if (j==0) return;
	
	j = ((i&STT_WORK_OCS_MSK)== 0 )&& (i&(STT_START_OCS_MSK));
	j = (i&(STT_WORK_OCS_MSK));
	j = (i&(STT_START_OCS_MSK));
	if (j)
	sLV.uChIdxBit =  STT_START_OCS_ONB;
	j =  (i&(STT_WORK_OCS_MSK)) && ((i&( STT_STOP_OCS_MSK ))==0);
	if (j)
	sLV.uChIdxBit =  STT_WORK_OCS_ONB;
	j = (i&(STT_STOP_OCS_MSK));
	if (j)
	sLV.uChIdxBit =  STT_STOP_OCS_ONB;
	 
	if(sLV.uChIdxBit)
	{
	    i = (long)((BaseAcpuCMUnitDsc*)pvProxy)-> pf_Work;
		if(i)
		{
			sLV.pfl_vl = (PFL_VL)i;
			i = sLV.pfl_vl(pvProxy,sLV.uChIdxBit);//sLV.IdConObj);Mow Only One Cmd
		}	
	}
	



}
void ExecProxy(void)   @ "Fast_function"
{
    register void* pv;
	register long i,j;
	struct 
	{
		unsigned char uChIdxBit ;
		//short shErr;
		//unsigned short ushSizeLDC;
		//unsigned short IdConObj;
		//void *pOriginLDC;
		PFL_VL pfl_vl;
	} sLV;
	//PFL_VL pfl_vl;
	sLV.uChIdxBit = 0;
	
	
	pv = (void*)&holderProxyTenPerSamplesUnit;
	ExecExistProxy(pv);
	pv = (void*)&holderProxyTotMeasUnit;
	ExecExistProxy(pv);
	pv = (void*)&hldPrMngPrtTbl;//`hldPrMngYust;
	ExecExistProxyManager(pv);
	
	pv = (void*)&hldPrTrptPrtTbl; //` hldPrTrptYust;
	ExecExistProxy(pv);
	

}

#include    "proxy4.c"
#include    "mTotprx.c"
#include    "mTotR.c"
#include    "Apcs.c"
#include    "MnPrPrt.c"
#include    "GoosA.c"
#include    "GoosB.c"
#include    "Tlmc.c"
#include    "verInfo.c"
#include    "fcoil.c"
#include    "atrcmd.c"

#include    "dt_tm.c"
#include    "AuxStng.c"
#include    "AbnD.c"




/* EOF */
