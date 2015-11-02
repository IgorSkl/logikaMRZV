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
* File Name       : Tlmc.c
* Description     : Functions and Data for Extract from Transport to Applicayion
                    BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  11/03/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#include    "Tlmc.h"
// this  Obj for Primary hold data
TeleMechsHldDsc holderTeleMechs = {

{0,0,0,0}
};
// This Obj Use for Transmittion
TeleMechsHldDsc holderTeleMechsIciCopy = {

{0,0,0,0}
};

TeleMechsWrpDsc  hldTeleMechsWrp = {

#ifdef __TYPE_DEFINITION_TELE_BR_TO_BS__
sizeof(SIZE_TELE_INFO ),	(void*)	&holderTeleMechs.UNTeleMechs.lArTeleMechs[0],		
#endif
#ifndef __TYPE_DEFINITION_TELE_BR_TO_BS__
0,	(void*)	0,
#endif
{0,0,0,0}

};


int AppReqTransmitTeleMechs;
int AppReqReceiveTeleMechs ; //int AppReqReceiveTotMeasG;

void ActivateServTrApCnTeleMechsCTpuUnitSpi(void)
{
//register long i,j;
//register char *pch;
register void* pv;
pv = hldTeleMechsWrp.p_TeleMechs;
	if(AppReqTransmitTeleMechs==EXEC)
	{
		
		//((Dsc*)(hldApcsWrp.p_Apcs))->statistics.lErrors++;
		//((Dsc*)(hldApcsWrp.p_Apcs))->statistics.lTotalBadChange++;//In This ver try to start work with Wrapers Obj 
		hldTeleMechsWrp.statistics.lErrors++;
		hldTeleMechsWrp.statistics.lTotalBadChange++;
		
		//,!! Reinit Transmittion???
	}
	hldTeleMechsWrp.size_TeleMechs = 0;
//Copy
//hldApcsWrp.UNApcs.lArApcs[0] = 0;//meas_protection;
holderTeleMechsIciCopy.UNTeleMechs = holderTeleMechs.UNTeleMechs;
hldTeleMechsWrp.size_TeleMechs     = SIZE_TELE_INFO;

  //pch = (char *)&(holderTRSrcSamplesCTpuUnit.arUchTR);
  //pv  = (void*)& holderSrcSamplesUnit;
  //j = sizeof(SrcSamplesUnitDsc);
  //for (i = 0; i < j; i++)
  //{
  //  pch[i] = ((char*)pv)[i];
  //}
  //Reset Connect State
   pv  = (void*)& (holderTRTeleMechsSOCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_SPI;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_SPI;// Logic can ctrl
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf    = SIZE_TPDU_TELE_MECHS_CNL_SPI;
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = hldTeleMechsWrp.size_TeleMechs;//sizeof(SrcSamplesUnitDsc);
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_TELE_MECHS_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)& holderTeleMechsIciCopy.UNTeleMechs.chArTeleMechs[0]; //holderTRSrcSamplesCTpuUnit.arUchTR;
   
}

void TerminateServiceApCnTeleMechs(void)
{
//register void *pv;
//register long i;
   //(( Dsc*)(hldApcsWrp.p_Apcs))->statistics.lTotalGoodChange++;
   //(( Dsc*)(hldApcsWrp.p_Apcs))->statistics.lTotalChange++;
   hldTeleMechsWrp.statistics.lTotalGoodChange++;
   hldTeleMechsWrp.statistics.lTotalChange++;
   
}
//PrepDecompouseTotMeasGUnitHSU2();

void PrepDecompouseTeleMechsUnitSpi(void)
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
	if(AppReqTransmitTeleMechs)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_Spi;j = 4;//SIZE_TPDU_TOT_MEASG_CNL_HSU2;
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (AppReqTransmitTeleMechs==START)
			{
				ActivateServTrApCnTeleMechsCTpuUnitSpi();
				AppReqTransmitTeleMechs = EXEC;
			}
			//ProcessTransmit Obj
			if(AppReqTransmitTeleMechs==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRTeleMechsSOCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					AppReqTransmitTeleMechs = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<5))//channel Full
				{
					
				}

				if (AppReqTransmitTeleMechs==TERM)
				{
					TerminateServiceApCnTeleMechs();
					AppReqTransmitTeleMechs = 0;
				}
			}
		}
		//Try another???
		
	}
	

}

//holderTeleMechs
void HoldTeleMechs(void)
{
register long i,j;
register void *pv;
struct 
	{
		//char chRetCode;//,
				
		unsigned char uChIdxByte ;
		unsigned char uChIdxBit ;
		//short         shCountCmd;  
	} sLV;
union 
	{
		unsigned char   uchAr [4];//Bit Field
		unsigned short  ushAr [2];//Task & Phase
		unsigned long   ulVal;
	}UNNlV;
	
//sLV.chRetCode  = 0;//= sLV.uChIdxByte= sLV.uChIdxBit
//GetCmdState
//GetTrgCmdState
	i = GetInState      ( (void*)&(holderTeleMechs.UNTeleMechs.sBrTeleMechsTeleInfoWrp.chArIn     [0]) );
	i = GetOutState     ( (void*)&(holderTeleMechs.UNTeleMechs.sBrTeleMechsTeleInfoWrp.chArOut    [0]) );
	i = GetTrgOutState  ( (void*)&(holderTeleMechs.UNTeleMechs.sBrTeleMechsTeleInfoWrp.chArOutTrg [0]) );
	i = GetLedState     ( (void*)&(holderTeleMechs.UNTeleMechs.sBrTeleMechsTeleInfoWrp.chArLed    [0]) );
	i = GetTrgLedState  ( (void*)&(holderTeleMechs.UNTeleMechs.sBrTeleMechsTeleInfoWrp.chArLedTrg [0]) );
}



/* EOF */

