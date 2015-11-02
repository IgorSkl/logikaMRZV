#ifndef DIAGNOSTICS_h
#define DIAGNOSTICS_h
#include "../inc/diagBsEn.h"
#include "../inc/diagBmEn.h"
#include "../inc/diagBrEn.h"
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//==================================================================================
//--- 			 INTERNAL  diagnostik  CONSTANT BIT     -----------
//==================================================================================
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~   diagBmEn En -enumms not English        ~~
//~~~           ~~ 
//~~~           ~~
//~~~           ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
typedef struct RamErrRec_TAG 
{
	unsigned long ulCheck_0_FEBF;//0  Fix Error Bit Field
	unsigned long ulCheck_1_FEBF;//01 
	//unsigned long ul__2_FEBF;//02 
	//unsigned long ulRes___3_FEBF;//03 
	union 
	    {
	    	unsigned char uchStateSDFE;//1<<0 -BIT-Fault Error 1<<1-Diagnostic Error
			unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;//Bound Word
	    }UNNStateSDFE;
	//

	
}RamErrEvtDsc;

extern RamErrEvtDsc hldrErrEvt;


#endif 
         