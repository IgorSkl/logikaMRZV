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
* File Name       : fcoil.c
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

#include    "fcoil.h"


FCoilHldDsc holderFCoil = {

{0,0,0,0}
};
// This Obj Use for Transmittion
FCoilHldDsc holderFCoilIciCopy = {

{0,0,0,0}
};

FCoilWrpDsc  hldFCoilWrp = {

#ifdef __TYPE_DEFINITION_FCOIL_BR_TO_BS__
(SIZE_FCOIL ),	(void*)	&holderFCoil.UNFCoil.lArFCoil[0],		
#endif
#ifndef __TYPE_DEFINITION_FCOIL_BR_TO_BS__
0,	(void*)	0,
#endif
{0,0,0,0}

};


//int AppReqTransmitFCoil;
int AppReqReceiveFCoil ; //int AppReqReceiveTotMeasG;


long UpdateRVTotFCoilTpuUnit(void* pvLDC, long lID)
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
pv  = (void*)&holderRVFCoilSOCTpuUnit.RvCnHldr;
if (unnV1.uchAr[0]== 0)
{
	//pv  = (void*)&holderRVTotMeasCTpuUnit.arUchRV;
	pv  = (void*)	&holderFCoil.UNFCoil.lArFCoil[0];
	
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	pvLDC = (void*)i;
	
	//MoveData: 
	for (i = 0; i < lID; i++)
	{
	  ((char*)pv)[i] = ((char*)pvLDC)[i];
	}
	pvLDC = (void*)&hldFCoilWrp;
//Inform about Succes statistics
	i = ((FCoilWrpDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
	((FCoilWrpDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
	i = ((FCoilWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
	((FCoilWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
	AppReqReceiveFCoil++; 
}
else
{
	//-Analize Sesion state Etc.
	pv  = (void*)&holderRVFCoilSOCTpuUnit.RvCnHldr;
	if ( ((LDCIDsc*)pvLDC)-> uchStartSesion == 1)
	{
		((RVBaseCTpuUnitDsc*)pv)->NumComSes = (unnV1.uchAr[2])>>4;//<<= 4
		//Select Active Buf
		((RVBaseCTpuUnitDsc*)pv)->pUchRV = //holderRVTotMeasGSOCTpuUnit
		(unsigned char*)&holderRVFCoilSOCTpuUnit.arUchRV; 
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = 0;
	}
	
	i = (((LDCIDsc*)pvLDC)->NumComSes)>>4;
		if (i== (((RVBaseCTpuUnitDsc*)pv)->NumComSes) )
		{
			i = (((LDCIDsc*)pvLDC)->uchTR_C)+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
			if( i<= (long)(SIZE_FCOIL))
			lID = ((LDCIDsc*)pvLDC)->uchTR_C;
			else
			lID = (SIZE_FCOIL) - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
			unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
			i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
			
			pvLDC = (void*)i;
			i = (long)holderRVFCoilSOCTpuUnit.RvCnHldr.pUchRV;
			i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
			pv  = (void*)i;
			for (i = 0; i < lID; i++)
			{
			((char*)pv)[i] = ((char*)pvLDC)[i];
			}
			//Update Rv
			pv  = (void*)&holderRVFCoilSOCTpuUnit.RvCnHldr;
			lID = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount+unnV1.uchAr[3];
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount = lID;
			if (lID >= (long)(SIZE_FCOIL))
			{
				 pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
				 i = ((FCoilWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
				((FCoilWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
				//Sucess Terminate Session
				if (lID == (long)(SIZE_FCOIL))
				{
					//Activate App Func
					AppReqReceiveFCoil++;
					i = ((FCoilWrpDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
					((FCoilWrpDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
					
					//hldFCoilWrp.size_total_measurement = 0;//AppReqReceiveTotMeasG = 0;
					// hldFCoilWrp.p_total_measurement =
					//  (void*)&(holderFCoil.UNTotMeas.total_measurement);
					  
				}
				else{
						 //pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
						i = ((FCoilWrpDsc*)pvLDC)-> statistics.lErrors;i++;
						((FCoilWrpDsc*)pvLDC)-> statistics.lErrors = i;
						i = ((FCoilWrpDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
						((FCoilWrpDsc*)pvLDC)-> statistics.lTotalBadChange = i;
						
				}
				 sLV.chNeedClrSesData++;
			}
			
		}
		else
		{
			;//Error Sesion
			
			 pvLDC = &hldFCoilWrp;//((RVBaseCTpuUnitDsc*)pv)->pUchRV;
			i = ((FCoilWrpDsc*)pvLDC)-> statistics.lErrors;i++;
			((FCoilWrpDsc*)pvLDC)-> statistics.lErrors = i;
			i = ((FCoilWrpDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
			((FCoilWrpDsc*)pvLDC)-> statistics.lTotalBadChange = i;
			i = ((FCoilWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
			((FCoilWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
			 sLV.chNeedClrSesData++;
			
			
			
		}
		if(sLV.chNeedClrSesData)
		{
			pv  = (void*)&holderRVFCoilSOCTpuUnit.RvCnHldr;
			((RVBaseCTpuUnitDsc*)pv)->uchUsedTransport = 0;
			((RVBaseCTpuUnitDsc*)pv)->NumComSes        = 0;
			((RVBaseCTpuUnitDsc*)pv)->ConState         = 0;
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount        = 0;
			
		}
}

return lID;//unnV1.uchAr[3];
}


void FCoilRvServCTpuApCnUnit(void)
{
hldFCoilWrp.size_FCoil = 0;
AppReqReceiveFCoil = 0;
 hldFCoilWrp.p_FCoil =
 (void*)&holderFCoil.UNFCoil.chArFCoil[0];
//Req Copy Operation
holderFCoilIciCopy.UNFCoil.sBrFCoilInfoWrp
= holderFCoil.UNFCoil.sBrFCoilInfoWrp;
hldFCoilWrp.p_FCoil = (void*)	&holderFCoil.UNFCoil.chArFCoil[0];
hldFCoilWrp.size_FCoil =  sizeof(   SIZE_FCOIL );

}







/* EOF */

