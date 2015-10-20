/*------------------------------------------------------------------------------
* Copyright (c) 2013 - Factory “KyivPrylad”
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
* File Name       : lpu.h
* Description     : support for the lpu.c
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  02/09/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef Lpu_h
#define Lpu_h

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SIZE_LPDU_CNL_1 200

#define SIZE_LPDU_CNL_DOUBLE_ACCESS_MEMORY  640
#define SIZE_LPDU_CNL_M2M  640

#define SIZE_LPDU_CNL_HSU7 64

#define SIZE_LPDU_CNL_U3   60

#define SIZE_LPDU_CNL_HSU1 64
#define SIZE_LPDU_CNL_HSU2 64

#define SIZE_LPDU_CNL_SPI  512

//#define SIZE_LPDU_CNL_HSU2 80//USART


#define SIZE_LPCI_FLD_CNL_1    1
#define SIZE_LDC_FLD_CNL_1     1
#define SIZE_CS_FLD_CNL_1      1

#define SIZE_LPCI_FLD_CNL_HSU7    1
#define SIZE_LDC_FLD_CNL_HSU7     1
#define SIZE_CS_FLD_CNL_HSU7      1

#define SIZE_LPCI_FLD_CNL_HSU2    1
#define SIZE_LDC_FLD_CNL_HSU2     1
#define SIZE_CS_FLD_CNL_HSU2      1

#define SIZE_LPCI_FLD_CNL_HSU1    1
#define SIZE_LDC_FLD_CNL_HSU1     1
#define SIZE_CS_FLD_CNL_HSU1      1
#define HDR_MODE_CNL_1      ((1<<7)|(1<<1))
#define HDR_MODE_CNL_2      ((1<<7)|(1<<2))
#define HDR_MODE_CNL_M2M    ((1<<7) |(1<<2))
#define HDR_MODE_CNL_SPI    ((1<<7) |(1<<2))



#define SIZE_LPCI_FLD_CNL_M2M    1
#define SIZE_LDC_FLD_CNL_M2M     2
#define SIZE_CS_FLD_CNL_M2M      1	

#define SIZE_LPCI_FLD_CNL_SPI    1
#define SIZE_LDC_FLD_CNL_SPI     2
#define SIZE_CS_FLD_CNL_SPI      1	





//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
extern long l_Abs_Numerator_Br;
extern long l_time_lable;
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    fffff         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_ApcsMiscData
{
	//char           chGrpUst;
	char chIdx_AnallogWthCmdBuf_L;//Pologennya v buferi mittev
	
}ApcsMiscDataDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#include "epr_f.h" //Config function
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~       Dsc Const for Urg Data                       ~~~~~
//~~~                             ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define __TYPE_DEFINITION_URG_BR_TO_BS__ 1//
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
#ifndef __TYPE_DEFINITION_URG_BR_TO_BS__
#define SIZE_URGENT_DATA_BR 0X100
#endif 
#ifdef __TYPE_DEFINITION_URG_BR_TO_BS__
//#define SIZE_MEASUREMENT_TO_PROTECTION ( ((sizeof( __MEASUREMENT_TO_PROTECTION )>>2)<<2) + 4*(1&&(sizeof(__MEASUREMENT_TO_PROTECTION ))&3) )

//#define SIZE_OBJ1 ( ((sizeof( __Obj1 )>>2)<<2) + 4*(1&&(sizeof(__Obj1 ))&3) )
//#define SIZE_OBJ2 ( ((sizeof( __Obj2 )>>2)<<2) + 4*(1&&(sizeof(__Obj2 ))&3) )
//#define SIZE_URGENT_DATA (SIZE_OBJ1 + SIZE_OBJ2)
//U vipadky propusku paketa ya z ostanniogo otrimanogo
// virahovuyu riznitcy last receive  - Last in BS buf fixed i vidpravl nomeri vidsutnich
//zriziv na BS
  
#define SIZE_ANALOG_DATA  ( 64 ) //Arr of Char
#define SIZE_COMMAND_DATA ( (((RESERV_MAX_OEPRF_ONB)>>3) +1)  ) //Arr of Char ~26bytes
#define SIZE_WRP_LOG_DATA ( sizeof( long) )
#define SIZE_ABN_NUMERATOR ( sizeof( long) )
#define SIZE_AWC_LOG_DATA ( SIZE_ANALOG_DATA + SIZE_COMMAND_DATA + SIZE_WRP_LOG_DATA+SIZE_ABN_NUMERATOR)


//#define SIZE_DIAGNOSTIC_DATA (4)//32-bita
#define SIZE_APCS_AUX_DATA   ( sizeof( ApcsMiscDataDsc) ) //STATE Gr Ust, DIn, DOut  

#define SIZE_URGENT_DATA_BR_TO_BS (SIZE_AWC_LOG_DATA )


#endif
//``````````````````````````````````````````````````````````````````````````````````
//~~~   SIZE_OBJ1 as Analog Data
//~~~   SIZE_OBJ2 as Digital Data
//~~~   Gr Ust
//~~~   Diagnostic Data
//..................................................................................
typedef struct UrgentDataBr_TagOut
{
	union 
	{
	    	char   chArUrgData [SIZE_URGENT_DATA_BR_TO_BS];
	    	long   lArUrgData  [SIZE_URGENT_DATA_BR_TO_BS>>2];
#ifdef __TYPE_DEFINITION_URG_BR_TO_BS__
			// __MEASUREMENT_TO_PROTECTION measurement_to_protection;
			struct
			{
				char  chArCtrLinkTr[4];//ID LinK Layer Transmittion
				char  chArAnlg[SIZE_ANALOG_DATA];
				char  chArCmd[SIZE_COMMAND_DATA];
				char  chArWrp[SIZE_WRP_LOG_DATA];//Current TimeLab
				char  chAbnNum[SIZE_ABN_NUMERATOR];
				//ApcsMiscDataDsc hldApcsMiscData;
			}sBrWrp;
#endif
            
	}UN_UrgentDataBR;
//	struct
//	{
//		long lErrors;
//		long lTotalBadChange;
//		long lTotalGoodChange;
//		long lTotalChange;
//	}statistics;

				
}UrgentDataBrDsc;
//~~~   
#define SIZE_UN_URGENT_DATA_BR_TO_BS (sizeof(UN_UrgentDataBR))
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

#define __TYPE_DEFINITION_URG_BS_TO_BR__ 0//
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
#ifndef __TYPE_DEFINITION_URG_BS_TO_BR__
#define SIZE_URGENT_DATA_BS 8
#endif 
#ifdef __TYPE_DEFINITION_URG_BS_TO_BR__

#define SIZE_URGENT_DATA_BS 4
#define SIZE_URGENT_DATA_BS_TO_BR 0
#endif

//``````````````````````````````````````````````````````````````````````````````````
//~~~   SIZE_OBJ1 
//~~~   SIZE_OBJ2 
//~~~   Gr Ust
//~~~   Diagnostic Data
//..................................................................................
typedef struct UrgentDataBs_TagOut
{
	union 
	{
#if SIZE_URGENT_DATA_BS_TO_BR == 0	
	    	char   chArUrgData [SIZE_URGENT_DATA_BS];
	    	long   lArUrgData  [SIZE_URGENT_DATA_BS>>2];
#else			
			char   chArUrgData [SIZE_URGENT_DATA_BS_TO_BR];
			long   lArUrgData  [SIZE_URGENT_DATA_BS_TO_BR>>2];

#endif
#if SIZE_URGENT_DATA_BS_TO_BR > 0	//#ifdef __TYPE_DEFINITION_URG_BS_TO_BR__
			// __MEASUREMENT_TO_PROTECTION measurement_to_protection;
			struct
			{
				//Current TimeLab
				//char  chDiag[SIZE_DIAGNOSTIC_DATA];
				//ApcsMiscDataDsc hldApcsMiscData;
			}sBsWrp;
#endif
            
	}UN_UrgentDataBR;
//	struct
//	{
//		long lErrors;
//		long lTotalBadChange;
//		long lTotalGoodChange;
//		long lTotalChange;
//	}statistics;

				
}UrgentDataBsDsc;
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""












//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//#define ID_CNL_TEST1 0x1
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct StateTpLpuDsc_tag
{
	unsigned char  uchTpState_CNL_1;
	short PayloadLPDU_CNL_1;//Total Payload LPDU_CNL_1 for current Link Frame
	//If on app take command change param phis Frame then change PayloadLPDU_CNL_1
	long lCapicity_CNL_1;//Current Capicity Payload for Transport
	//unsigned char      *pUchRV;//0   Data  field
	unsigned char      *pUchLpuTR_CNL_1;
	
	//--unsigned char  uchhTpState_CNL_2;
	//--long lCapicity_CNL_2;
	//--//unsigned char      *pUchRV;//0   Data  field
	//--unsigned char      *pUchLpuTR_CNL_2;
	unsigned char  uchTpState_CNL_HSU7;
	short PayloadLPDU_HSU7;
	long lCapicity_CNL_HSU7;
	//unsigned char      *pUchRV;//0   Data  field
	unsigned char      *pUchLpuTR_CNL_HSU7;
	
	
	unsigned char  uchhTpState_CNL_3;
	long lCapicity_CNL_3;
	//unsigned char      *pUchRV;//0   Data  field
	unsigned char      *pUchLpuTR_CNL_3;
	
	unsigned char  uchhTpState_CNL_4;
	long lCapicity_CNL_4;
	//unsigned char      *pUchRV;//0   Data  field
	unsigned char      *pUchLpuTR_CNL_4;
	
}StateTpLpuDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//#define 
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_TRStateLpuCn1Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_1];//0   Data  field

	
	unsigned char  uchLpuCn1State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}TRStateLpuCn1Dsc;
typedef struct tag_TRStateLpuHSU7Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_HSU7];//0   Data  field

	
	unsigned char  uchLpuHSU7State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}TRStateLpuHSU7Dsc;
typedef struct tag_TRStateLpuHSU2Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_HSU2];//0   Data  field

	
	unsigned char  uchLpuHSU2State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}TRStateLpuHSU2Dsc;
typedef struct tag_TRStateLpuHSU1Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_HSU1];//0   Data  field

	
	unsigned char  uchLpuHSU1State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}TRStateLpuHSU1Dsc;
typedef struct tag_TRStateLpuM2mDsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_M2M];//0   Data  field

	
	unsigned char  uchLpuM2mState;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}TRStateLpuM2mDsc;

typedef struct tag_TRStateLpuSpiDsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_SPI+4];//0   Data  field

	
	unsigned char  uchLpuSpiState;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}TRStateLpuSpiDsc;

typedef struct tag_RVStateLpuCnlDsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      *pUch;//0   Data  field

	
	unsigned char  uchLpuCn1State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;

	
}RVStateLpuCnlDsc;
typedef struct tag_RVStateLpuCn1Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_1];//0   Data  field

	
	unsigned char  uchLpuCn1State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;

	
}RVStateLpuCn1Dsc;

typedef struct tag_RVStateLpuU3Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_U3];//0   Data  field

	
	unsigned char  uchLpuU3State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}RVStateLpuU3Dsc;

typedef struct tag_RVStateLpuHSU7Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_HSU7];//0   Data  field

	
	unsigned char  uchLpuHSU7State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}RVStateLpuHSU7Dsc;

typedef struct tag_RVStateLpuHSU1Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_HSU1];//0   Data  field

	
	unsigned char  uchLpuHSU1State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}RVStateLpuHSU1Dsc;
typedef struct tag_RVStateLpuHSU2Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_HSU2];//0   Data  field

	
	unsigned char  uchLpuHSU2State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}RVStateLpuHSU2Dsc;
typedef struct tag_RVStateLpuM2mDsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_M2M];//0   Data  field

	
	unsigned char  uchLpuM2mState;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}RVStateLpuM2mDsc;

typedef struct tag_RVStateLpuSpiDsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_SPI+4];//0   Data  field

	
	unsigned char  uchLpuSpiState;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}RVStateLpuSpiDsc;
	

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SIZE_LPDU_CNL_2 248
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_LpuState
{
	unsigned char  uchLpuCn2State;
	unsigned short ushSizeLDC;
	
	long lCap;
	
}StateLpuCn2Dsc;




//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

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

extern TRStateLpuCn1Dsc holderCn1LpduUnit;
extern RVStateLpuCn1Dsc hldrCn1LpduUnit;

extern TRStateLpuHSU7Dsc hldrHSU7LpduTRUnit;
extern TRStateLpuHSU1Dsc hldrHSU1LpduTRUnit;
extern TRStateLpuHSU2Dsc hldrHSU2LpduTRUnit;
extern TRStateLpuM2mDsc  hldrM2mLpduTRUnit;
extern TRStateLpuSpiDsc  hldrSpiLpduTRUnit;


extern RVStateLpuU3Dsc   hldrU3LpduUnit;
extern RVStateLpuHSU7Dsc hldrHSU7LpduUnit;
extern RVStateLpuHSU1Dsc hldrHSU1LpduUnit;
extern RVStateLpuHSU2Dsc hldrHSU2LpduUnit;
extern RVStateLpuM2mDsc  hldrM2mLpduUnit;
extern RVStateLpuSpiDsc  hldrSpiLpduUnit;



extern void ProcessReceiveLpdu(void);
extern void ProcessTransmitLpdu(void);

extern void ProcessTransmitLpduHSU7(void);
extern void ProcessTransmitLpduHSU2(void);
extern void ProcessTransmitLpduHSU1(void);

extern void ProcessTransmitLpduM2m(void);
extern void ProcessTransmitLpduSpi(void);

extern void ProcessReceiveLpduHSU2(void);
extern void ProcessReceiveLpduHSU1(void);
extern void ProcessReceiveLpduM2m(void);
extern void ProcessReceiveLpduSpi(void);

extern void Rst_LpduHSU7_TpCnState(void);
extern void Rst_LpduHSU1_TpCnState(void);
extern void Rst_LpduHSU2_TpCnState(void);
extern void Rst_LpduM2m_TpCnState(void);
extern void RstTmr0(void);

extern void ProcessReceiveLpduCY7(void);
extern void ProcessReceiveLpduCY7V1(void);  


extern long inSPI1 (unsigned char *buff, int bytes);
extern long outSPI1(unsigned char *dat, int bytes);
extern void Spi0_Rst(void);
extern void ProcessTransmitStubSeqSpi();

void InsertUrgBr2Bs(void* pv);


extern unsigned long ulCtrTrLpduSpi ;
extern void ProcessLLEvt (void);

extern  long Eval_CS(char* pCh, long iLength );




#endif /* Lpu_h */