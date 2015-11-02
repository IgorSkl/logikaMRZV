/*------------------------------------------------------------------------------
* Copyright (c) 2015 - Factory “KyivPrylad”
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
* File Name       : AuxStng.c
* Description     : Functions and Data for Extract from Transport to Applicayion
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  12/08/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#include    "AuxStng.h"


AuxStngHldDsc  holderAuxStng = {
{0}
};
//ObjWrpDsc


 int AppReqTransmitAuxStng;
// int AppReqReceiveAuxStng;
 

void ActivateServTrApCnAuxStngCTpuUnit(void)
{ 
register void* pv;

pv  = (void*)& (holderTRAuxStngSOCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_M2M;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_M2M;// Logic can ctrl
   
   
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = sizeof(AuxStngHldDsc);//
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_AUX_STNG_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)& holderAuxStng.UNN_AuxStng.mAuxStng; //
   


 
}

void TerminateServiceApCnAuxStng(void)
{

}

void PrepDecompouseAuxStngUnitM2m(void)
{
register long i,j;
register void *pv;
	pv = (void*)&hldrTpCnState;
//Process
	if(AppReqTransmitAuxStng)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_M2m;j = 4;//SIZE_TPDU_TOT_MEASG_CNL_HSU2;
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (AppReqTransmitAuxStng==START)
			{
				ActivateServTrApCnAuxStngCTpuUnit();
				AppReqTransmitAuxStng = EXEC;
			}
			//ProcessTransmit Obj
			if(AppReqTransmitAuxStng==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRAuxStngSOCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					AppReqTransmitAuxStng = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<5))//channel Full
				{
					
				}

				if (AppReqTransmitAuxStng==TERM)
				{
					TerminateServiceApCnAuxStng();
					AppReqTransmitAuxStng = 0;
				}
			}
		}
		//Try another???
		
	}
	
}

 
 



/* EOF */
 