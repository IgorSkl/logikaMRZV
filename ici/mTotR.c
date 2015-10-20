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
* File Name       : mTotR.c
* Description     : Functions and Data for Extract from Transport to Applicayion
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  03/10/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/


//#include "constants.h"
//extern unsigned int volatile command_to_receive_current_data;
//extern int current_data_transmit[NUMBER_CANALS*NUMBER_POINT*NUMBER_PERIOD_TRANSMIT]; 
//#include "libraries.h"
#include "constants.h"
#include "type_definition.h"

#include    "ApMeasR.h"
extern __MEASUREMENT_TO_PROTECTION meas_protection; 
extern  __MEASUREMENT_TO_PROTECTION  Proxy_meas_protection; 
/* */
TotMeasRHldDsc holderTotMeasR = {

{0,0,0,0}
};

#include "constants.h"
#include "type_definition.h"
//extern __TOTAL_MEASUREMENT total_measurement; 

TotMeasRWrpDsc hldTotMeasRWrp = {

#ifdef __TYPE_DEFINITION__
sizeof(__MEASUREMENT_TO_PROTECTION ),	(void*)	&meas_protection,		
#endif
#ifndef __TYPE_DEFINITION__
0,	(void*)	0,
#endif
{0,0,0,0}

};

int AppReqTransmitTotMeasR;
int AppReqReceiveTotMeasR ; //int AppReqReceiveTotMeasG;

void ActivateServTrApCnTotMeasRCTpuUnitM2m(void)
{
//register long i,j;
//register char *pch;
register void* pv;
	if(AppReqTransmitTotMeasR==EXEC)
	{
		holderTotMeasR.statistics.lErrors++;
		holderTotMeasR.statistics.lTotalBadChange++;
		//,!! Reinit Transmittion???
	}
//Copy
holderTotMeasR.UNTotMeas.measurement_to_protection = meas_protection;

  //pch = (char *)&(holderTRSrcSamplesCTpuUnit.arUchTR);
  //pv  = (void*)& holderSrcSamplesUnit;
  //j = sizeof(SrcSamplesUnitDsc);
  //for (i = 0; i < j; i++)
  //{
  //  pch[i] = ((char*)pv)[i];
  //}
  //Reset Connect State
   pv  = (void*)& (holderTRTotMeasRSOCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_M2M;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_M2M;// Logic can ctrl
   
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = hldTotMeasRWrp.size_measurement_to_protection;//sizeof(SrcSamplesUnitDsc);
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_TOTAL_MEASR_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)& holderTotMeasR.UNTotMeas.measurement_to_protection; //holderTRSrcSamplesCTpuUnit.arUchTR;
   
}

void TerminateServiceApCnTotMeasR(void)
{
//register void *pv;
//register long i;
  holderTotMeasR.statistics.lTotalGoodChange++;
   holderTotMeasR.statistics.lTotalChange++;
   
}
//PrepDecompouseTotMeasGUnitHSU2();

void PrepDecompouseTotMeasRUnitM2m(void)
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
	if(AppReqTransmitTotMeasR)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_M2m;j = 4;//SIZE_TPDU_TOT_MEASG_CNL_HSU2;
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (AppReqTransmitTotMeasR==START)
			{
				ActivateServTrApCnTotMeasRCTpuUnitM2m();
				AppReqTransmitTotMeasR = EXEC;
			}
			//ProcessTransmit Obj
			if(AppReqTransmitTotMeasR==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRTotMeasRSOCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					AppReqTransmitTotMeasR = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<5))//channel Full
				{
					
				}

				if (AppReqTransmitTotMeasR==TERM)
				{
					TerminateServiceApCnTotMeasR();
					AppReqTransmitTotMeasR = 0;
				}
			}
		}
		//Try another???
		
	}
	

}





 __MEASUREMENT_TO_PROTECTION meas_protection;//Copy

long UpdateRVTotMeasRCTpuUnit(void* pvLDC, long lID)
{
register long i;//,j;
//register char *pSrc;//,*pDst;
void* pv;
struct 
	{
		char chNeedClrSesData;
		void *pOriginLDC;
	} sLV;
union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;	

sLV.pOriginLDC = pvLDC;
//RVSrcSamplesCTpuUnitDsc  holderRVSrcSamplesCTpuUnit
 sLV.chNeedClrSesData = 0;
unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
unnV1.uchAr[3] = 0;
pv  = (void*)&holderRVTotMeasRSOCTpuUnit.RvCnHldr;
if (unnV1.uchAr[0]== 0)
{
	i = (((LDCIDsc*)pvLDC)->uchTR_C);//+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
	if( i<= (long)(SIZE_MEASUREMENT_TO_PROTECTION))
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	else
	lID = (SIZE_MEASUREMENT_TO_PROTECTION);// - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
	unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	
	pvLDC = (void*)i;
	i = (long)holderRVTotMeasRSOCTpuUnit.RvCnHldr.pUchRV;
	//i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
	pv  = (void*)i;
	for (i = 0; i < lID; i++)
	{
	((char*)pv)[i] = ((char*)pvLDC)[i];
	}

  //Activate App For
    //..  TestReqReceiveT1++;
  //Clear All Ses Data
       i = 0;
	AppReqReceiveTotMeasR++;
	
	
	//Clear All Ses Data
	/*
	pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
	i = ((TotMeasRHldDsc*)pvLDC)-> statistics.lErrors;i++;
	((TotMeasRHldDsc*)pvLDC)-> statistics.lErrors = i;
	//((LDCIDsc*)pvLDC)-> statistics.
	i = ((TotMeasRHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
	((TotMeasRHldDsc*)pvLDC)-> statistics.lTotalChange = i;
	holderRVTotMeasRSOCTpuUnit.RvCnHldr.uchUsedTransport = 0;
	holderRVTotMeasRSOCTpuUnit.RvCnHldr.NumComSes        = 0;
	holderRVTotMeasRSOCTpuUnit.RvCnHldr.ConState         = 0;
	holderRVTotMeasRSOCTpuUnit.RvCnHldr.ulRvCount        = lID;
	 sLV.chNeedClrSesData++;
	*/ 
	 
	 
}
else
{
	//-Analize Sesion state Etc.
	pv  = (void*)&holderRVTotMeasRSOCTpuUnit.RvCnHldr;
	if ( ((LDCIDsc*)pvLDC)-> uchStartSesion == 1)
	{
		((RVBaseCTpuUnitDsc*)pv)->NumComSes = (unnV1.uchAr[2])>>4;//<<= 4
		//Select Active Buf
		//((RVBaseCTpuUnitDsc*)pv)->pUchRV = //holderRVTotMeasRSOCTpuUnit
		//(unsigned char*)&holderRVTotMeasCTpuUnit.arUchRV; 
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = 0;
	}
	
	i = (((LDCIDsc*)pvLDC)->NumComSes)>>4;
		if (i== (((RVBaseCTpuUnitDsc*)pv)->NumComSes) )
		{
			i = (((LDCIDsc*)pvLDC)->uchTR_C)+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
			if( i<= (long)(SIZE_MEASUREMENT_TO_PROTECTION))
			lID = ((LDCIDsc*)pvLDC)->uchTR_C;
			else
			lID = (SIZE_MEASUREMENT_TO_PROTECTION) - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
			unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
			i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
			
			pvLDC = (void*)i;
			i = (long)holderRVTotMeasRSOCTpuUnit.RvCnHldr.pUchRV;
			i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
			pv  = (void*)i;
			for (i = 0; i < lID; i++)
			{
			((char*)pv)[i] = ((char*)pvLDC)[i];
			}
			//Update Rv
			pv  = (void*)&holderRVTotMeasRSOCTpuUnit.RvCnHldr;
			lID = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount+unnV1.uchAr[3];
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount = lID;
			if (lID >= (long)(SIZE_MEASUREMENT_TO_PROTECTION))
			{
				 pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
				 i = ((TotMeasRHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
				((TotMeasRHldDsc*)pvLDC)-> statistics.lTotalChange = i;
				//Sucess Terminate Session
				if (lID == (long)(SIZE_MEASUREMENT_TO_PROTECTION))
				{
					//Activate App Func
					AppReqReceiveTotMeasR++;
					i = ((TotMeasRHldDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
					((TotMeasRHldDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
				}
				else{
						 //pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
						i = ((TotMeasRHldDsc*)pvLDC)-> statistics.lErrors;i++;
						((TotMeasRHldDsc*)pvLDC)-> statistics.lErrors = i;
						i = ((TotMeasRHldDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
						((TotMeasRHldDsc*)pvLDC)-> statistics.lTotalBadChange = i;
						
				}
				 sLV.chNeedClrSesData++;
			}
			
		}
		else
		{
			;//Error Sesion
			
			 pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
			i = ((TotMeasRHldDsc*)pvLDC)-> statistics.lErrors;i++;
			((TotMeasRHldDsc*)pvLDC)-> statistics.lErrors = i;
			i = ((TotMeasRHldDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
			((TotMeasRHldDsc*)pvLDC)-> statistics.lTotalBadChange = i;
			i = ((TotMeasRHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
			((TotMeasRHldDsc*)pvLDC)-> statistics.lTotalChange = i;
			 sLV.chNeedClrSesData++;
			
			
			
		}
		if(sLV.chNeedClrSesData)
		{
			pv  = (void*)&holderRVTotMeasRSOCTpuUnit.RvCnHldr;
			((RVBaseCTpuUnitDsc*)pv)->uchUsedTransport = 0;
			((RVBaseCTpuUnitDsc*)pv)->NumComSes        = 0;
			((RVBaseCTpuUnitDsc*)pv)->ConState         = 0;
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount        = 0;
			
		}
}

return lID;//unnV1.uchAr[3];
}


void TotMeasRRvServCTpuApCnUnit(void)
{

//AppReqReceiveTotMeasR = 0;
hldTotMeasRWrp.size_measurement_to_protection = 0;
AppReqReceiveTotMeasR = 0;
hldTotMeasRWrp.p_measurement_to_protection = (void*)	&holderTotMeasR.UNTotMeas. lArTotMeas[0];
//hldTotMeasRWrp.size_measurement_to_protection = sizeof( __MEASUREMENT_TO_PROTECTION );

 meas_protection = holderTotMeasR.UNTotMeas.measurement_to_protection;
//hldTotMeasRWrp.size_measurement_to_protection = 0;
hldTotMeasRWrp.p_measurement_to_protection = (void*)	&meas_protection;
hldTotMeasRWrp.size_measurement_to_protection = sizeof( __MEASUREMENT_TO_PROTECTION );

}
//static chActiveMeasPrt = 0;
void* GetMeasPrt_(void)
{

	if( hldTotMeasRWrp.size_measurement_to_protection 
		== 0//sizeof( __MEASUREMENT_TO_PROTECTION )
	)	
	return (void*)	&holderTotMeasR.UNTotMeas. lArTotMeas[0];
	
	return (void*)	&meas_protection;
}

#define ERROR 4
#define OK    3

long GetMeasPrt(void *pvMeasAddr)
{
register  __MEASUREMENT_TO_PROTECTION *pMPrtData;
register long lR = 0;	
	if (pvMeasAddr == 0)
	{	
		lR = ERROR;
		goto ExitGetMeasPrt;
	}
	
	//..Control correctness Pointers
	pMPrtData =  (__MEASUREMENT_TO_PROTECTION *)pvMeasAddr;
	//
	if( (hldTotMeasRWrp.size_measurement_to_protection == 0)
	//|| (hldTotMeasRWrp.p_measurement_to_protection == (&holderTotMeasR.UNTotMeas. lArTotMeas[0]))
	)
	{
		*pMPrtData = holderTotMeasR.UNTotMeas.measurement_to_protection;
		lR = OK;
	}
	else
	{
		*pMPrtData =  meas_protection;
		lR = OK;
	}
	
ExitGetMeasPrt:

	return lR;
}







/*
void ActivateServTrApCnSamplesCTpuUnitHSU2(void)
{
register long i,j;
register char *pch;
register void* pv;
//Copy
  pch = (char *)&(holderTRSrcSamplesCTpuUnit.arUchTR);
  pv  = (void*)& holderSrcSamplesUnit;
  j = sizeof(SrcSamplesUnitDsc);
  for (i = 0; i < j; i++)
  {
    pch[i] = ((char*)pv)[i];
  }
  //Reset Connect State
   pv  = (void*)& (holderTRSrcSamplesCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_HSU2;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_HSU2;// Logic can ctrl
   
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = sizeof(SrcSamplesUnitDsc);
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_SRC_SAMPLES_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)& holderTRSrcSamplesCTpuUnit.arUchTR;
   
}


*/



