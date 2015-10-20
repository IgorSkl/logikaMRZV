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
* File Name       : Apcs.h
* Description     : support for the Apcs.c
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  11/03/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#ifndef Apcs_H
#define Apcs_H

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~                          ~~~~~
//~~~                            ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
/*#define NUM_IN  32
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````
#define NUM_OUT 16
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````
#define NUM_LED 16
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````


#define AMOUNT_BYTE_FOR_IN            (((NUM_IN)>>3) ) //+1) 

#define AMOUNT_BYTE_FOR_OUT           (((NUM_OUT)>>3)) // +1) 

#define AMOUNT_BYTE_FOR_OUT_TRG       (((NUM_OUT)>>3)  ) //+1)
                                                        //
#define AMOUNT_BYTE_FOR_LED           (((NUM_LED)>>3) ) //+1)
                                                        //
#define AMOUNT_BYTE_FOR_LED_TRG       (((NUM_LED)>>3) ) //+1)
*/
                                      
//#define __TYPE_DEFINITION_APCS_BR_TO_BS__ 1
									  
#ifndef __TYPE_DEFINITION_APCS_BR_TO_BS__
#define SIZE_APCS 20
#define SIZE_WRP 1
#else

//#define SIZE_TELE_INFO (AMOUNT_BYTE_FOR_IN+ AMOUNT_BYTE_FOR_OUT \
//+AMOUNT_BYTE_FOR_OUT_TRG + AMOUNT_BYTE_FOR_LED + AMOUNT_BYTE_FOR_LED_TRG)
#define SIZE_WRP 1
#endif 

typedef struct tag_ApcsHldDsc
{
	union 
	{
#ifndef __TYPE_DEFINITION_APCS_BR_TO_BS__	    	
			char   chArApcs [SIZE_APCS];
	    	long   lArApcs  [SIZE_APCS>>2];
#else
			//char   chArApcs [SIZE_TELE_INFO];
	    	//long   lArApcs  [SIZE_TELE_INFO>>2];
#endif 			
#ifdef __TYPE_DEFINITION_APCS_BR_TO_BS__
			//Obj xxx_Apcs;
			struct
			{
				//char  chArIn    [AMOUNT_BYTE_FOR_IN ];
				//char  chArOut   [AMOUNT_BYTE_FOR_OUT];
				//char  chArOutTrg[AMOUNT_BYTE_FOR_OUT_TRG];
				//char  chArLed   [AMOUNT_BYTE_FOR_LED];
				//char  chArLedTrg[AMOUNT_BYTE_FOR_LED_TRG ];
				
				char  chArWrp[SIZE_WRP];//
				//char  chDiag[SIZE_DIAGNOSTIC_DATA];
				//ApcsMiscDataDsc hldApcsMiscData;
			}sBrApcsTeleInfoWrp;
#else			
			struct
			{
	
				char  chArWrp[SIZE_WRP];//
				//ApcsMiscDataDsc hldApcsMiscData;
			}sBrApcsTeleInfoWrp;
			
#endif
            
	}UNApcs;
	struct
	{
		long lErrors;
		long lTotalBadChange;
		long lTotalGoodChange;
		long lTotalChange;
	}statistics;
}ApcsHldDsc;
#ifdef __TYPE_DEFINITION_APCS_BR_TO_BS__
//#define SIZE_APCS ( ((sizeof( __MEASUREMENT_TO_PROTECTION )>>2)<<2) + 4*(1&&(sizeof(__MEASUREMENT_TO_PROTECTION ))&3) )

#define SIZE_APCS (sizeof( UNApcs ))
#endif

//extern __TOTAL_MEASUREMENT total_measurement;

typedef struct tag_ApcsWrpDsc//Wrapper 
{

long size_Apcs;      //
void *p_Apcs;        //

	struct
	{
		long lErrors;
		long lTotalBadChange;
		long lTotalGoodChange;
		long lTotalChange;
	}statistics;
}ApcsWrpDsc;

extern int AppReqTransmitApcs;
extern int AppReqReceiveApcs ;

extern ApcsHldDsc holderApcs;
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
extern void ActivateServTrApCnApcsCTpuUnitSpi(void);
extern  void TerminateServiceApCnApcs(void);






#endif //Apcs_h