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
* File Name       : AbnD.h
* Description     : support for the AbnD.c
                    BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  31/08/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef ABS_NUMERATOR_h
#define ABS_NUMERATOR_h

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~                          ~~~~~
//~~~                            ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
#define AMOUNT_BYTE_FOR_NUMERATOR  4
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````
                                      
#define __TYPE_DEFINITION_ABS_NUMERATOR_BR_TO_BS__ 1
									  
#ifndef __TYPE_DEFINITION_ABS_NUMERATOR_BR_TO_BS__

#define SIZE_ABS_NUMERATOR_N 12
#else

#define SIZE_ABS_NUMERATOR (sizeof(char)+sizeof(long)+sizeof(long))

#endif 

#define REQ_ACK_SELECTOR_BIT 0
//0 BIT0 Means ACK chArNum1
//1 BIT0  Means REQ chArNum1 contain Req bit3-1-Contain
//#define 
 
 


typedef struct tag_AbsNumeratorUnnDsc
{
	union 
	{
#ifndef __TYPE_DEFINITION_ABS_NUMERATOR_BR_TO_BS__	    	
			char   chArNums [SIZE_ABS_NUMERATOR_N];
	    	long    lArNums [SIZE_ABS_NUMERATOR_N>>2];
#else
			char   chArNums [SIZE_ABS_NUMERATOR];
	    	long    lArNums [SIZE_ABS_NUMERATOR>>2];
#endif 		
#ifdef __TYPE_DEFINITION_ABS_NUMERATOR_BR_TO_BS__		
				//Obj xxx_TeleMechs;
			struct
			{
				char  chBitFld;
				char  chArNum1[AMOUNT_BYTE_FOR_NUMERATOR];
				char  chArNum2[AMOUNT_BYTE_FOR_NUMERATOR];
				
				//char  chArWrp[SIZE_WRP_];//
				//char  chDiag[SIZE_DIAGNOSTIC_DATA];
				//ApcsMiscDataDsc hldApcsMiscData;
			}sBrAbsNumeratorWrp;
#else			
			struct
			{
	

				//ApcsMiscDataDsc hldApcsMiscData;
			}sBrAbsNumeratorWrp;
			
#endif
            
	
	}UNNAbsNumtrs;
	
}AbsNumeratorUnnDsc;

#define __TYPE_DEFINITION_AREC_BR_TO_BS__ 1//
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
#ifndef __TYPE_DEFINITION_AREC_BR_TO_BS__
#define SIZE_AREC_DATA_BR 0X100
#endif 
//#ifdef __TYPE_DEFINITION_AREC_BR_TO_BS__
//  
//#define SIZE_ANALOG_DATA  ( 64 ) //Arr of Char
//#define SIZE_COMMAND_DATA ( (((RESERV_MAX_OEPRF_ONB)>>3) +1)  ) //Arr of Char ~26bytes
//#define SIZE_WRP_LOG_DATA ( sizeof( long) )
//#define SIZE_ABN_NUMERATOR ( sizeof( long) )
//#define SIZE_AWC_LOG_DATA ( SIZE_ANALOG_DATA + SIZE_COMMAND_DATA + SIZE_WRP_LOG_DATA +  SIZE_ABN_NUMERATOR)
//
//
//
//#endif
#define SIZE_AREC_DATA_BR_TO_BS (SIZE_AWC_LOG_DATA )
//``````````````````````````````````````````````````````````````````````````````````
//~~~    
//~~~    
//~~~    
//~~~    
//..................................................................................


typedef struct ARecDataBr_TagOut
{
	union 
	{
	    	char   chArArecData [SIZE_AREC_DATA_BR_TO_BS];
	    	long    lArArecData [SIZE_AREC_DATA_BR_TO_BS>>2];
#ifdef __TYPE_DEFINITION_AREC_BR_TO_BS__
			//
			struct
			{
				
				char  chArAnlg[SIZE_ANALOG_DATA];
				char  chArCmd[SIZE_COMMAND_DATA];
				char  chArWrp[SIZE_WRP_LOG_DATA];//Current TimeLab
				char  chAbnNum[SIZE_ABN_NUMERATOR];
				//ApcsMiscDataDsc hldApcsMiscData;
			}sArecBrWrp;
#endif
            
	}UN_ArecDataBR;



}ARecDataDsc;
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
//extern void ActivateServTrApCn TeleMechs CTpuUnitSpi(void);
//extern  void TerminateServiceApCn TeleMechs(void);






#endif //AbsNumerator_h