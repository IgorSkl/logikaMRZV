/*------------------------------------------------------------------------------
* Created (c) 2014 - Factory “KyivPrylad”
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
* File Name       : Apcs.c
* Description     : Functions and Data for Extract from Transport to Applicayion
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  11/03/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#include "constants.h"
#include "type_definition.h"

#include    "Apcs.h"
ApcsHldDsc holderApcs = {

{0,0,0,0}
};

ApcsHldDsc holderApcsIciCopy = {

{0,0,0,0}
};

#include "constants.h"
#include "type_definition.h"
//extern __TOTAL_MEASUREMENT total_measurement; 

//.-````TotMeasRWrpDsc hldTotMeasRWrp = {
//.-````
//.-````#ifdef __TYPE_DEFINITION__
//.-````sizeof(__MEASUREMENT_TO_PROTECTION ),	(void*)	&meas_protection,		
//.-````#endif
//.-````#ifndef __TYPE_DEFINITION__
//.-````0,	(void*)	0,
//.-````#endif
//.-````{0,0,0,0}
//.-````
//.-````};

ApcsWrpDsc hldApcsWrp = {

#ifdef __TYPE_DEFINITION_APCS_BR_TO_BS__
sizeof(SIZE_TELE_INFO ),	(void*)	&holderApcs.UNApcs.lArApcs[0],		
#endif
#ifndef __TYPE_DEFINITION_APCS_BR_TO_BS__
0,	(void*)	0,
#endif
{0,0,0,0}

};

int AppReqTransmitApcs;
int AppReqReceiveApcs ; //int AppReqReceiveTotMeasG;

void ActivateServTrApCnApcsCTpuUnitSpi(void)
{
//register long i,j;
//register char *pch;
register void* pv;
pv = hldApcsWrp.p_Apcs;
	if(AppReqTransmitApcs==EXEC)
	{
		
		//((Dsc*)(hldApcsWrp.p_Apcs))->statistics.lErrors++;
		//((Dsc*)(hldApcsWrp.p_Apcs))->statistics.lTotalBadChange++;//In This ver try to start work with Wrapers Obj 
		hldApcsWrp.statistics.lErrors++;
		hldApcsWrp.statistics.lTotalBadChange++;
		
		//,!! Reinit Transmittion???
	}
	hldApcsWrp.size_Apcs = 0;
//Copy
//hldApcsWrp.UNApcs.lArApcs[0] = 0;//meas_protection;
holderApcsIciCopy.UNApcs = holderApcs.UNApcs;
hldApcsWrp.size_Apcs = SIZE_APCS;
  //pch = (char *)&(holderTRSrcSamplesCTpuUnit.arUchTR);
  //pv  = (void*)& holderSrcSamplesUnit;
  //j = sizeof(SrcSamplesUnitDsc);
  //for (i = 0; i < j; i++)
  //{
  //  pch[i] = ((char*)pv)[i];
  //}
  //Reset Connect State
   pv  = (void*)& (holderTRApcsSOCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_SPI;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_SPI;// Logic can ctrl
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf    = SIZE_TPDU_APCS_CNL_SPI;
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = hldApcsWrp.size_Apcs;//sizeof(SrcSamplesUnitDsc);
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_APCS_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)& holderApcsIciCopy.UNApcs.lArApcs[0]; //holderTRSrcSamplesCTpuUnit.arUchTR;
   
}

void TerminateServiceApCnApcs(void)
{
//register void *pv;
//register long i;
   //(( Dsc*)(hldApcsWrp.p_Apcs))->statistics.lTotalGoodChange++;
   //(( Dsc*)(hldApcsWrp.p_Apcs))->statistics.lTotalChange++;
   hldApcsWrp.statistics.lTotalGoodChange++;
   hldApcsWrp.statistics.lTotalChange++;
   
}
//PrepDecompouseTotMeasGUnitHSU2();

void PrepDecompouseApcsUnitSpi(void)
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
	if(AppReqTransmitApcs)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_Spi;j = 4;//SIZE_TPDU_TOT_MEASG_CNL_HSU2;
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (AppReqTransmitApcs==START)
			{
				ActivateServTrApCnApcsCTpuUnitSpi();
				AppReqTransmitApcs = EXEC;
			}
			//ProcessTransmit Obj
			if(AppReqTransmitApcs==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRApcsSOCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					AppReqTransmitApcs = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<5))//channel Full
				{
					
				}

				if (AppReqTransmitApcs==TERM)
				{
					TerminateServiceApCnApcs();
					AppReqTransmitApcs = 0;
				}
			}
		}
		//Try another???
		
	}
	

}




/* EOF */


