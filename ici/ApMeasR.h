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
* File Name       : ApMeasR.h
* Description     : support for the AppCn.c
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  11/03/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef ApMeasR
#define ApMeasR

//#include "type_definition_BL.h"
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#ifndef __TYPE_DEFINITION__
#define SIZE_MEASUREMENT_TO_PROTECTION 0X1000
#endif 
#ifdef __TYPE_DEFINITION__
#define SIZE_MEASUREMENT_TO_PROTECTION ( ((sizeof( __MEASUREMENT_TO_PROTECTION )>>2)<<2) + 4*(1&&(sizeof(__MEASUREMENT_TO_PROTECTION ))&3) )
#endif
typedef struct tag_TotMeasRHldDsc
{
	union 
	{
	    	char   chArTotMeas [SIZE_MEASUREMENT_TO_PROTECTION];
	    	long   lArTotMeas  [SIZE_MEASUREMENT_TO_PROTECTION>>2];
#ifdef __TYPE_DEFINITION__
			 __MEASUREMENT_TO_PROTECTION measurement_to_protection;
#endif
            
	}UNTotMeas;
	struct
	{
		long lErrors;
		long lTotalBadChange;
		long lTotalGoodChange;
		long lTotalChange;
	}statistics;
}TotMeasRHldDsc;


//extern __TOTAL_MEASUREMENT total_measurement;

typedef struct tag_TotMeasRWrpDsc//Wrapper 
{

long size_measurement_to_protection;      //
void *p_measurement_to_protection;        //

	struct
	{
		long lErrors;
		long lTotalBadChange;
		long lTotalGoodChange;
		long lTotalChange;
	}statistics;
}TotMeasRWrpDsc;
extern int AppReqTransmitTotMeasR;
extern int AppReqReceiveTotMeasR ;

extern TotMeasRHldDsc holderTotMeasR;
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
extern void ActivateServTrApCnTotMeasRCTpuUnitHSU2(void);
extern  void TerminateServiceApCnTotMeasR(void);






#endif /* ApMeasR.h */

	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	