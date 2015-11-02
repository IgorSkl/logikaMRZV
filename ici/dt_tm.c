/*------------------------------------------------------------------------------
* Created (c) 2015 - Factory “KyivPrylad”
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
* File Name       : dt_tm.c
* Description     : Functions and Data for Extract from Transport to Applicayion
                    BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  20/06/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#include    "dt_tm.h"


DateTimeHldDsc holderDateTime = {

{0,0,0,0}
};
// This Obj Use for Transmittion
DateTimeHldDsc holderDateTimeIciCopy = {

{0,0,0,0}
};

DateTimeWrpDsc  hldDateTimeWrp = {

#ifdef __TYPE_DEFINITION_DATE_TIME_BR_TO_BS__
(SIZE_DATE_TIME ),	(void*)	&holderDateTime.UNDateTime.lArDateTime[0],		
#endif
#ifndef __TYPE_DEFINITION_DATE_TIME_BR_TO_BS__
0,	(void*)	0,
#endif
{0,0,0,0}

};


//int AppReqTransmitDateTime;
int AppReqReceiveDateTime ; //int AppReqReceiveTotMeasG;


long UpdateRVTotDateTimeTpuUnit(void* pvLDC, long lID)
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
pv  = (void*)&holderRVDateTimeSOCTpuUnit.RvCnHldr;
if (unnV1.uchAr[0]== 0)
{
	//pv  = (void*)&holderRVTotMeasCTpuUnit.arUchRV;
	pv  = (void*)	&holderDateTime.UNDateTime.lArDateTime[0];
	
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	pvLDC = (void*)i;
	
	//MoveData: 
	for (i = 0; i < lID; i++)
	{
	  ((char*)pv)[i] = ((char*)pvLDC)[i];
	}
	pvLDC = (void*)&hldDateTimeWrp;
//Inform about Succes statistics
	i = ((DateTimeWrpDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
	((DateTimeWrpDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
	i = ((DateTimeWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
	((DateTimeWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
	AppReqReceiveDateTime++; 
}
else
{
	//-Analize Sesion state Etc.
	pv  = (void*)&holderRVDateTimeSOCTpuUnit.RvCnHldr;
	if ( ((LDCIDsc*)pvLDC)-> uchStartSesion == 1)
	{
		((RVBaseCTpuUnitDsc*)pv)->NumComSes = (unnV1.uchAr[2])>>4;//<<= 4
		//Select Active Buf
		((RVBaseCTpuUnitDsc*)pv)->pUchRV = //holderRVTotMeasGSOCTpuUnit
		(unsigned char*)&holderRVDateTimeSOCTpuUnit.arUchRV; 
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = 0;
	}
	
	i = (((LDCIDsc*)pvLDC)->NumComSes)>>4;
		if (i== (((RVBaseCTpuUnitDsc*)pv)->NumComSes) )
		{
			i = (((LDCIDsc*)pvLDC)->uchTR_C)+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
			if( i<= (long)(SIZE_DATE_TIME))
			lID = ((LDCIDsc*)pvLDC)->uchTR_C;
			else
			lID = (SIZE_DATE_TIME) - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
			unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
			i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
			
			pvLDC = (void*)i;
			i = (long)holderRVDateTimeSOCTpuUnit.RvCnHldr.pUchRV;
			i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
			pv  = (void*)i;
			for (i = 0; i < lID; i++)
			{
			((char*)pv)[i] = ((char*)pvLDC)[i];
			}
			//Update Rv
			pv  = (void*)&holderRVDateTimeSOCTpuUnit.RvCnHldr;
			lID = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount+unnV1.uchAr[3];
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount = lID;
			if (lID >= (long)(SIZE_DATE_TIME))
			{
				 pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
				 i = ((DateTimeWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
				((DateTimeWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
				//Sucess Terminate Session
				if (lID == (long)(SIZE_DATE_TIME))
				{
					//Activate App Func
					AppReqReceiveDateTime++;
					i = ((DateTimeWrpDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
					((DateTimeWrpDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
					
					//hldDateTimeWrp.size_total_measurement = 0;//AppReqReceiveTotMeasG = 0;
					// hldDateTimeWrp.p_total_measurement =
					//  (void*)&(holderDateTime.UNTotMeas.total_measurement);
					  
				}
				else{
						 //pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
						i = ((DateTimeWrpDsc*)pvLDC)-> statistics.lErrors;i++;
						((DateTimeWrpDsc*)pvLDC)-> statistics.lErrors = i;
						i = ((DateTimeWrpDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
						((DateTimeWrpDsc*)pvLDC)-> statistics.lTotalBadChange = i;
						
				}
				 sLV.chNeedClrSesData++;
			}
			
		}
		else
		{
			;//Error Sesion
			
			 pvLDC = &hldDateTimeWrp;//((RVBaseCTpuUnitDsc*)pv)->pUchRV;
			i = ((DateTimeWrpDsc*)pvLDC)-> statistics.lErrors;i++;
			((DateTimeWrpDsc*)pvLDC)-> statistics.lErrors = i;
			i = ((DateTimeWrpDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
			((DateTimeWrpDsc*)pvLDC)-> statistics.lTotalBadChange = i;
			i = ((DateTimeWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
			((DateTimeWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
			 sLV.chNeedClrSesData++;
			
			
			
		}
		if(sLV.chNeedClrSesData)
		{
			pv  = (void*)&holderRVDateTimeSOCTpuUnit.RvCnHldr;
			((RVBaseCTpuUnitDsc*)pv)->uchUsedTransport = 0;
			((RVBaseCTpuUnitDsc*)pv)->NumComSes        = 0;
			((RVBaseCTpuUnitDsc*)pv)->ConState         = 0;
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount        = 0;
			
		}
}

return lID;//unnV1.uchAr[3];
}


void DateTimeRvServCTpuApCnUnit(void)
{
hldDateTimeWrp.size_DateTime = 0;
AppReqReceiveDateTime = 0;
 hldDateTimeWrp.p_DateTime =
 (void*)&holderDateTime.UNDateTime.chArDateTime[0];
//Req Copy Operation
holderDateTimeIciCopy.UNDateTime.sBrDateTimeInfoWrp
= holderDateTime.UNDateTime.sBrDateTimeInfoWrp;
hldDateTimeWrp.p_DateTime = (void*)	&holderDateTime.UNDateTime.chArDateTime[0];
hldDateTimeWrp.size_DateTime =  sizeof(   SIZE_DATE_TIME );

}







/* EOF */

