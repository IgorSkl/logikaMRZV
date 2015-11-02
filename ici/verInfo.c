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
* File Name       : verInfo.c
* Description     : Functions and Data for Low Level Program description,
                    BO BR on 

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  17/06/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/


#include <intrinsics.h>
#include <string.h>
#include <time.h>
#include "hr_ver.h"
#include "DiagnG.h"
#include    "dgn_vr.h"


#define VERSION         1

#define SUB_VERSION     0
#define AUX_NUM         0
//Description
//A string that identifies the date of compilation, which is returned in the form "Mmm dd yyyy", for example "Oct 30 2014"
//This symbol is required by Standard C.

__root const char arDateCompilation [] = {
__DATE__


};
//A string that identifies the time of compilation in the form "hh:mm:ss".

__root const char arTimeCompilation [] = {
__TIME__


};
//An integer that identifies the version number of the IAR compiler in use. For example, version 5.11.3 is returned as 5011003.

__root const long long llIarVersion = {
__VER__


};
//A string that identifies the name of the base source file (that is, not the header file), being compiled. 

__root const char arBaseFile [] = {
__BASE_FILE__


};
//A unique integer that identifies the build number of the compiler currently in use. 

__root  const long long llBuidNumber = {
__BUILD_NUMBER__


};
//[Major].[Minor].[Patch].[Build]
typedef struct tag_version{
char ver;//Main Number
char sub_ver;//Describe functionality change  z TU abo bez TU
char corr_num;//Nomer correkcii Vupravlennya pomulok
long Bield_num;//Compile Counter
}VerInfo ;
__root const VerInfo hlVerInfo = {
VERSION,
AUX_NUM,
SUB_VERSION,
BIELD_NUMBER 

};


RamErrEvtDsc hldrErrEvt;


//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void ProcessProgramEvt(void) @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:                          ~~~
//~~~ Processing:                       ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                                             ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
void ProcessProgramEvt(void) @ "Fast_function"
{
  register long j;
  register long k1;// i,
  register void *pv;
	//Check Time Corectness
	
	//PutExecpt((void*)&SResTestHldr,(void*)&EepromErrRecDesc); <-Insert Data In Logger
	k1 = 0;//Fix Fatal Error
	pv = (void*)&hldrErrEvt;
	//Check each bit in Test Conf
	
//	j = *((U8*)i+SETNGS_ERR_START_VIA_I2C_CHK_IDX_U8);
//       if(j& SETNGS_ERR_START_VIA_I2C_CHK_U8_MSK)
//	k++;
// ERROR_BM_VREF_ADC1_TEST_BIT                      
	// 
//	j = *( (char*)pv + ( TO_IDX_U8(ERROR_BM_VREF_ADC1_TEST_BIT) )   );
//	if (j& ( TO_U8_MSK(ERROR_BM_VREF_ADC1_TEST_BIT)) )
//	k++;//Fix Fatal Error
//	
//	// ERROR_BM_VDD_ADC1_TEST_BIT  
//	j = *((char*)pv+(TO_IDX_U8(ERROR_BM_VDD_ADC1_TEST_BIT)));
//	if (j& ( TO_U8_MSK(ERROR_BM_VDD_ADC1_TEST_BIT)) )
//	k++;//Fix Fatal Error
//	// ERROR_BM_VREF_ADC1_TEST_COARSE_BIT               
//	j = *((char*)pv+(TO_IDX_U8(ERROR_BM_VREF_ADC1_TEST_COARSE_BIT)));
//	if (j& ( TO_U8_MSK(ERROR_BM_VREF_ADC1_TEST_COARSE_BIT)) )
//	k++;//Fix Fatal Error
//	// ERROR_BM_VDD_ADC1_TEST_COARSE_BIT                
//	j = *((char*)pv+(TO_IDX_U8(ERROR_BM_VDD_ADC1_TEST_COARSE_BIT)));
//	if (j& ( TO_U8_MSK(ERROR_BM_VDD_ADC1_TEST_COARSE_BIT)) )
//	k++;//Fix Fatal Error
	//                                                  
	// ERROR_BM_VREF_ADC2_TEST_BIT                      
	// ERROR_BM_VDD_ADC2_TEST_BIT                       
	// ERROR_BM_VREF_ADC2_TEST_COARSE_BIT               
	// ERROR_BM_VDD_ADC2_TEST_COARSE_BIT                
	//                                                  
	// ERROR_BM_VREF_ADC3_TEST_BIT                      
	// ERROR_BM_VDD_ADC3_TEST_BIT                       
	// ERROR_BM_VREF_ADC3_TEST_COARSE_BIT               
	// ERROR_BM_VDD_ADC3_TEST_COARSE_BIT                
	//                                                  
	// ERROR_BM_EXTERNAL_SRAM_BIT                       
	// ERROR_BM_EXTERNAL_FLASH_MEMORY_BIT               
	//                                                  
	// ERROR_BM_START_VIA_I2C_BIT                       
	// ERROR_BM_START_READING_I2C_BIT                   
	// ERROR_BM_SETTINGS_EEPROM_BIT                     
	// ERROR_BM_SETTINGS_EEPROM_EMPTY_BIT               
	// ERROR_BM_SETTINGS_EEPROM_COMPARISON_BIT          
	// ERROR_BM_SETTINGS_EEPROM_CONTROL_BIT             
	// ERROR_BM_SETTINGS_EEPROM_DEVICE_ID_FAIL_BIT      
	// ERROR_BM_USTUVANNJA_EEPROM_BIT                   
	// ERROR_BM_USTUVANNJA_EEPROM_EMPTY_BIT             
	// ERROR_BM_USTUVANNJA_EEPROM_COMPARISON_BIT        
	// ERROR_BM_USTUVANNJA_EEPROM_CONTROL_BIT           
	// ERROR_BM_USTUVANNJA_EEPROM_ADJUSTMENT_ID_FAIL_BIT
	// ERROR_BM_POWER_EEPROM_BIT                        
	// ERROR_BM_POWER_EEPROM_EMPTY_BIT                  
	// ERROR_BM_POWER_EEPROM_COMPARISON_BIT             
	// ERROR_BM_POWER_EEPROM_CONTROL_BIT 
	if(k1) 
	{
		//---*((U8*)pvCMD32+FAULT_TEST_CMDF_IDX_U8)  |= (FAULT_TEST_CMDF_U8_MSK);
		((RamErrEvtDsc*)pv)->UNNStateSDFE.uchStateSDFE |= 1;//Fix Fatal Error
	}
	else
	{
		((RamErrEvtDsc*)pv)->UNNStateSDFE.uchStateSDFE &= ~1;////Fix Fatal Error
	}
	k1 = 0;
	j = ((RamErrEvtDsc*)pv)->ulCheck_0_FEBF;
		if(j) k1++;
		j=  ((RamErrEvtDsc*)pv)->ulCheck_1_FEBF;
		if(j) k1++;
	if(k1) 
		{
			//---
			((RamErrEvtDsc*)pv)->UNNStateSDFE.uchStateSDFE |= 2;//Fix Diagnostic Error
		}
		else
		{
			((RamErrEvtDsc*)pv)->UNNStateSDFE.uchStateSDFE &= ~2;////Fix Diagnostic Error
		}	
	
}
//---------------------------------------------------------------------------------


 int AppReqTransmitDiagnBrBs;
 int AppReqTransmitDiagnBrBM;
 int AppReqReceiveDiagnBmBr ;
 int AppReqReceiveDiagnBsBr ;

 DiadnHldDsc holderDiagnBrBs = {
{0,0,0}

};
 DiadnHldDsc holderDiagnBrBm = {
{0,0,0}

};





 DiadnHldDsc holderDiagnBsBr = {
{0,0,0}

};
 DiadnHldDsc holderDiagnBmBr = {
{0,0,0}

};

void ActivateServTrApCnDiagnCTpuUnitSPI(void)
{

register void* pv;

holderDiagnBrBs.UNN_Sdfe.mRamErrEvt = hldrErrEvt;
  //Reset Connect State
   pv  = (void*)& (holderTRDiagnBrBsSOCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_SPI;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_SPI;// Logic can ctrl
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf    = SIZE_TPDU_DIAGN_BR_CNL_SPI;
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = SIZE_DIAGN;
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_DIAGN_BR_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)& holderDiagnBrBs.UNN_Sdfe.chArSDFE[0]; //
   
}

void TerminateServiceApCnDiagn(void)
{

   
}
//Pr
void PrepDecompouseDiagnUnitSPI(void)
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
	if(AppReqTransmitDiagnBrBs)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_Spi;j = 4+SIZE_DIAGN;//
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (AppReqTransmitDiagnBrBs==START)
			{
				ActivateServTrApCnDiagnCTpuUnitSPI();
				AppReqTransmitDiagnBrBs = EXEC;
			}
			//ProcessTransmit Obj
			if(AppReqTransmitDiagnBrBs==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRDiagnBrBsSOCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					AppReqTransmitDiagnBrBs = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<5))//channel Full
				{
					
				}

				if (AppReqTransmitDiagnBrBs==TERM)
				{
					TerminateServiceApCnDiagn();
					AppReqTransmitDiagnBrBs = 0;
				}
			}
		}
		//Try another???
		
	}
	

}


long UpdateRVDiagnBrBmTpuUnit(void* pvLDC, long lID)
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
pv  = (void*)&holderRVDiagnBrBmSOCTpuUnit.RvCnHldr;
if (unnV1.uchAr[0]== 0)
{
	//pv  = (void*)&holderRVTotMeasCTpuUnit.arUchRV;
	pv  = (void*)	&holderDiagnBrBm.UNN_Sdfe.chArSDFE[0];
	
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	pvLDC = (void*)i;
	
	//MoveData: 
	for (i = 0; i < lID; i++)
	{
	  ((char*)pv)[i] = ((char*)pvLDC)[i];
	}
//	 pvLDC = &hldTeleMechsWrp;
//Inform about Succes statistics
//	i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
//	((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
//	i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
//	((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
	AppReqReceiveDiagnBmBr++; 
	//holderDiagnBmBr.UNN_Sdfe.mRamErrEvt = *((RamErrEvtDsc*)holderRVDiagnBmBrSOCTpuUnit..RvCnHldr.pUchRV);
}


return lID;//unnV1.uchAr[3];
}

long UpdateRVDiagnBrBsTpuUnit(void* pvLDC, long lID)
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
pv  = (void*)&holderRVDiagnBrBsSOCTpuUnit.RvCnHldr;
if (unnV1.uchAr[0]== 0)
{
	//pv  = (void*)&holderRVTotMeasCTpuUnit.arUchRV;
	pv  = (void*)	&holderDiagnBsBr.UNN_Sdfe.chArSDFE[0];
	
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	pvLDC = (void*)i;
	
	//MoveData: 
	for (i = 0; i < lID; i++)
	{
	  ((char*)pv)[i] = ((char*)pvLDC)[i];
	}
//	 pvLDC = &hldTeleMechsWrp;
//Inform about Succes statistics
//	i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
//	((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
//	i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
//	((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
	AppReqReceiveDiagnBsBr++; 
}








return lID;//unnV1.uchAr[3];
}



//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   TotVerInfo  ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
TotVerInfoHldDsc hldTotVerInfoBr;
 int AppReqTransmitTotVerInfoBrBs;
 
void ActivateServTrApCnTotVerInfoCTpuUnitSPI(void)
{
//register long i;
register void* pv;
   
   hldTotVerInfoBr.UNN_TotVerInfo.mTotVerInfo.chSizeDateStr = strlen(arDateCompilation);
   //((TotVerInfo*)pv)->chSizeDateStr = strlen(arDateCompilation);
   strncpy(hldTotVerInfoBr.UNN_TotVerInfo.mTotVerInfo.ArDateStr, arDateCompilation,16);
   
   hldTotVerInfoBr.UNN_TotVerInfo.mTotVerInfo.chSizeTimeStr = strlen(arTimeCompilation );
   
   strncpy(hldTotVerInfoBr.UNN_TotVerInfo.mTotVerInfo.ArTimeStr,arTimeCompilation,16);
   
   hldTotVerInfoBr.UNN_TotVerInfo.mTotVerInfo.llIarVersion = llIarVersion;
   //
   pv  = (void*)&hlVerInfo; //hldTotVerInfoBm.UNN_TotVerInfo.mTotVerInfo;
   hldTotVerInfoBr.UNN_TotVerInfo.mTotVerInfo.mVerInfo = *((NumVerInfo*)pv);



  //Reset Connect State
   pv  = (void*)& (holderTRTotVerInfoBrBsSOCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_SPI;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_SPI;// Logic can ctrl
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf    = 12;//Try Split Obj //SIZE_TPDU_VER_INFO_BM_CNL_HSU2;
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = SIZE_TOT_VER_INFO;// SIZE_VER_INFO;
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_VER_INFO_BR_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)& hldTotVerInfoBr.UNN_TotVerInfo.chArVerI[0]; //
   
}

void TerminateServiceApCnTotVerInfo(void)
{

   
}
 
void PrepDecompouseTotVerInfoUnitHSU2(void)
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
	if(AppReqTransmitTotVerInfoBrBs)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_Spi;j = 4+4;//
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (AppReqTransmitTotVerInfoBrBs==START)
			{
				ActivateServTrApCnTotVerInfoCTpuUnitSPI();
				AppReqTransmitTotVerInfoBrBs = EXEC;
			}
			//ProcessTransmit Obj
			if(AppReqTransmitTotVerInfoBrBs==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRTotVerInfoBrBsSOCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					AppReqTransmitTotVerInfoBrBs = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<5))//channel Full
				{
					
				}

				if (AppReqTransmitTotVerInfoBrBs==TERM)
				{
					TerminateServiceApCnTotVerInfo();
					AppReqTransmitTotVerInfoBrBs = 0;
				}
			}
		}
		//Try another???
		
	}
	

}
 
 
 

/* EOF */
