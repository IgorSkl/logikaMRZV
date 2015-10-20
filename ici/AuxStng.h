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
* File Name       : AuxStng.h
* Description     : support for the AuxStng.c
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  11/08/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef AuxStngParam
#define AuxStngParam
   
typedef struct AuxStng_TAG 
{
	//unsigned long ulCheck_0_FEBF;//0  Fix Error Bit Field
	//unsigned long ulCheck_1_FEBF;//01 
	long lStorageStngSelector;//Cur Gr Ust
	//union 
	//    {
	//    	unsigned char uchStateSDFE;//1<<0 -BIT-Fault Error 1<<1-Diagnostic Error
	//		unsigned char   uchAr [4];
	//    	unsigned short  ushAr [2];
    //        unsigned long   ulVal;//Bound Word
	//    }UNNStateSDFE;
	//

	
}AuxStngDsc;   
                                        
#define __TYPE_DEFINITION_AUX_STNG_VALUES_BR 1
									  
#ifndef __TYPE_DEFINITION_AUX_STNG_VALUES_BR
#define SIZE_AUX_STNG  8
#else


#define SIZE_AUX_STNG ( sizeof(4 ))

#endif 


 
typedef struct tag_AuxStngHldDsc
{
	union 
	{
#ifndef __TYPE_DEFINITION_AUX_STNG_VALUES_BR	    	
			char   chArAuxStng [SIZE_AUX_STNG];
	    	long   l1ArAuxStng [SIZE_AUX_STNG>>2];
#else
			char   chArAuxStng [SIZE_AUX_STNG];
	    	long   l1ArAuxStng [SIZE_AUX_STNG>>2];
#endif 			
#ifdef __TYPE_DEFINITION_AUX_STNG_VALUES_BR
			//Obj xxx_FCoil;
			AuxStngDsc mAuxStng;
#else			
			;
			
#endif
            
	}UNN_AuxStng;
//	struct
//	{
//		long lErrors;
//		long lTotalBadChange;
//		long lTotalGoodChange;
//		long lTotalChange;
//	}statistics;
}AuxStngHldDsc;
#ifdef __TYPE_DEFINITION_AUX_STNG_VALUES_BR
#ifndef SIZE_AUX_STNG
//#define SIZE_APCS ( ((sizeof( __MEASUREMENT_TO_PROTECTION )>>2)<<2) + 4*(1&&(sizeof(__MEASUREMENT_TO_PROTECTION ))&3) )
// .RamErrEvtDsc

#define SIZE_AUX_STNG  (sizeof( holderAuxStng.UNN_AuxStng.mAuxStng))
#endif
#endif

//extern __TOTAL_MEASUREMENT total_measurement;

typedef struct tag_ObjWrpDsc//Wrapper 
{

long size_Obj;      //
void *p_Obj;        //

	struct
	{
		long lErrors;
		long lTotalBadChange;
		long lTotalGoodChange;
		long lTotalChange;
	}statistics;
}ObjWrpDsc;

extern int AppReqTransmitAuxStng;
extern int AppReqReceiveAuxStng ;

extern AuxStngHldDsc holderAuxStng;
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
extern void ActivateServTrApCnAuxStngCTpuUnit(void);
extern  void TerminateServiceApCnAuxStng(void);






#endif /* AuxStng.h */

	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	