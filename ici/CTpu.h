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
* File Name       : CTpu.h
* Description     :  support for the CTpu.c
                    BO BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  10/09/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef CTpu_h
#define CTpu_h
#include    "ApCn.h"
// Connection transport Unit
#define SIZE_HEADER_CTPU 
#define SIZE_STARTUP_CI 2//
#define SIZE_TOTAL_LDC    1

#define START_EXEC        1 
#define STATE_EXEC        2
#define SUCCESS_EXEC      3
#define ERROR_EXEC        4

#define MODE_LDC          (1<<4) 
#define START_SES         (1<<5)
#define FLD_TR_C          (1<<6)
#define FLD_NUM_COM_SES   (1<<7)


#define SIZE_WLDC_FLD     1
#define SIZE_ID_COM_SES   2
#define SIZE_NUM_COM_SES  1
#define SIZE_TR_C         1


#define HDR_IDX_SIZE_LDC        0
#define HDR_IDX_ID_COM_SES      HDR_IDX_SIZE_LDC    + SIZE_WLDC_FLD
#define HDR_IDX_NUM_COM_SES     HDR_IDX_ID_COM_SES  + SIZE_ID_COM_SES
#define HDR_IDX_TR_C            HDR_IDX_NUM_COM_SES + SIZE_NUM_COM_SES





#define START_SES_FLD_ONB   0
#define FLD1_ONB            START_SES_FLD_ONB
#define FLD2_ONB            FLD1_ONB
#define FLD3_ONB            FLD2_ONB

#define FLD0_MSK    (1<< START_SES_FLD_ONB)
#define FLD1_MSK    (1<< FLD1_ONB         )
#define FLD2_MSK    (1<< FLD2_ONB         )
#define FLD3_MSK    (1<< FLD3_ONB         )



//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define  Digital samples Con trp unit ~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_TRSrcSamplesCTpuUnitDsc1
{

	unsigned char      arUchTR[sizeof(SrcSamplesUnitDsc)];//0   Data  field
	//unsigned char      arUchRV[sizeof(SrcSamplesUnitDsc)];//0   Data  field
	unsigned short ConState;//12 bit Id Conection 
	
	unsigned long ulTrCount;

} TRSrcSamplesCTpuUnitDsc1;
typedef struct tag_RVSrcSamplesCTpuUnitDsc1
{

	unsigned char      arUchRV[sizeof(SrcSamplesUnitDsc)];//0   Data  field
	//unsigned char      arUchRV[sizeof(SrcSamplesUnitDsc)];//0   Data  field
	unsigned short ConState;//12 bit Id Conection 
	unsigned long ulRvCount;
	

} RVSrcSamplesCTpuUnitDsc1;

typedef struct tag_TRBaseCTpuUnitDsc
{
	unsigned char  uchBaseTransport;
	unsigned char  uchUsedTransport;//Id Used Phis channel
	unsigned char  NumComSes;
	unsigned char  ConState;//Contain state + state Transmition
	unsigned char  uchSizeCTpuBuf;
	unsigned short SizeAppObj;
	unsigned short IdConObj;//12 bit Id Conection 
	unsigned long  ulTrCount;
	unsigned char      *pUchTR;//0   Data  field

} TRBaseCTpuUnitDsc;
typedef struct tag_RVBaseCTpuUnitDsc
{
    unsigned char  uchUsedTransport;
	unsigned char  NumComSes;
	unsigned char  uchSizeCTpuBuf;
	unsigned short ConState;//12 bit Id Conection 
	unsigned long ulRvCount;
	unsigned char      *pUchRV;//0   Data  field
	

} RVBaseCTpuUnitDsc;
typedef struct tag_BaseCTpuUnitDsc
{

	unsigned char      *pUchRV;//0   Data  field
	unsigned char      *pUchTR;
	unsigned short ConState;//12 bit Id Conection 
	unsigned long ulRvCount;
	unsigned long ulTrCount;
	

} BaseCTpuUnitDsc;

typedef struct tag_TRSrcSamplesCTpuUnitDsc
{

	unsigned char      arUchTR[sizeof(SrcSamplesUnitDsc)];//0   Data  field
	//unsigned char      arUchRV[sizeof(SrcSamplesUnitDsc)];//0   Data  field
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TRSrcSamplesCTpuUnitDsc;
typedef struct tag_RVSrcSamplesCTpuUnitDsc
{

	unsigned char      arUchRV[sizeof(SrcSamplesUnitDsc)];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RVSrcSamplesCTpuUnitDsc;


extern TRSrcSamplesCTpuUnitDsc holderTRSrcSamplesCTpuUnit;

extern RVSrcSamplesCTpuUnitDsc  holderRVSrcSamplesCTpuUnit;

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SIZE_TPDU_10PER_CNL_HSU2 56//4//44//48
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_TR10PeriodCTpuUnitDsc
{

	unsigned char      arUchTR[SIZE_TPDU_10PER_CNL_HSU2];//0   Data  field
	//
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TR10PeriodCTpuUnitDsc;
typedef struct tag_RV10PeriodCTpuUnitDsc
{

	unsigned char      arUchRV[SIZE_TPDU_10PER_CNL_HSU2];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RV10PeriodCTpuUnitDsc;


extern TR10PeriodCTpuUnitDsc holderTR10PeriodCTpuUnit;

extern RV10PeriodCTpuUnitDsc  holderRV10PeriodCTpuUnit;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SIZE_TPDU_TOT_MEAS_CNL_HSU2 48
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_TRTotMeasCTpuUnitDsc
{

	unsigned char      arUchTR[SIZE_TPDU_TOT_MEAS_CNL_HSU2];//0   Data  field
	//
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TRTotMeasCTpuUnitDsc;
typedef struct tag_RVTotMeasCTpuUnitDsc
{

	unsigned char      arUchRV[SIZE_TPDU_TOT_MEAS_CNL_HSU2];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RVTotMeasCTpuUnitDsc;


extern TRTotMeasCTpuUnitDsc holderTRTotMeasCTpuUnit;

extern RVTotMeasCTpuUnitDsc  holderRVTotMeasCTpuUnit;


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SIZE_TPDU_TOT_MEASR_CNL_HSU2 116
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ TotMeas SO Single Object G- general then P-prorect T1,T2-etc
typedef struct tag_TRTotMeasRSOCTpuUnitDsc
{

	unsigned char      arUchTR[SIZE_TPDU_TOT_MEASR_CNL_HSU2];//0   Data  field
	//
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TRTotMeasRSOCTpuUnitDsc;
typedef struct tag_RVTotMeasRSOCTpuUnitDsc
{

	unsigned char      arUchRV[SIZE_TPDU_TOT_MEASR_CNL_HSU2];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RVTotMeasRSOCTpuUnitDsc;


extern TRTotMeasRSOCTpuUnitDsc holderTRTotMeasRSOCTpuUnit;

extern RVTotMeasRSOCTpuUnitDsc  holderRVTotMeasRSOCTpuUnit;	
	
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SIZE_TPDU_APCS_CNL_SPI 216
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ TotMeas SO Single Object G- general then P-prorect T1,T2-etc
typedef struct tag_TRApcsSOCTpuUnitDsc
{

	unsigned char      arUchTR[SIZE_TPDU_APCS_CNL_SPI];//0   Data  field
	//
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TRApcsSOCTpuUnitDsc;
typedef struct tag_RVApcsSOCTpuUnitDsc
{

	unsigned char      arUchRV[SIZE_TPDU_APCS_CNL_SPI];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RVApcsSOCTpuUnitDsc;


extern TRApcsSOCTpuUnitDsc  holderTRApcsSOCTpuUnit;

extern RVApcsSOCTpuUnitDsc  holderRVApcsSOCTpuUnit;	

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SIZE_TPDU_TELE_MECHS_CNL_SPI 20
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ TotMeas SO Single Object G- general then P-prorect T1,T2-etc
typedef struct tag_TRTeleMechsSOCTpuUnitDsc
{

	unsigned char      arUchTR[SIZE_TPDU_TELE_MECHS_CNL_SPI];//0   Data  field
	//
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TRTeleMechsSOCTpuUnitDsc;
typedef struct tag_RVTeleMechsSOCTpuUnitDsc
{

	unsigned char      arUchRV[SIZE_TPDU_TELE_MECHS_CNL_SPI];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RVTeleMechsSOCTpuUnitDsc;


extern TRTeleMechsSOCTpuUnitDsc  holderTRTeleMechsSOCTpuUnit;

//extern RVTeleMechsSOCTpuUnitDsc  holderRVTeleMechsSOCTpuUnit;	
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

	
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SIZE_TPDU_PRT_CNL_SPI 240
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_TRPrtTblCTpuUnitDsc
{

	unsigned char      arUchTR[SIZE_TPDU_PRT_CNL_SPI];//0   Data  field
	//
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TRPrtTblCTpuUnitDsc;
typedef struct tag_RVPrtTblCTpuUnitDsc
{

	unsigned char      arUchRV[SIZE_TPDU_PRT_CNL_SPI];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RVPrtTblCTpuUnitDsc;

extern TRPrtTblCTpuUnitDsc holderTRPrtTblCTpuUnit;
extern RVPrtTblCTpuUnitDsc holderRVPrtTblCTpuUnit;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SIZE_TPDU_PRT_PR_MNG_CNL_SPI 8
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_TRPrtTblPrMngCTpuUnitDsc
{

	unsigned char      arUchTR[SIZE_TPDU_PRT_PR_MNG_CNL_SPI];//0   Data  field
	//
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TRPrtTblPrMngCTpuUnitDsc;
typedef struct tag_RVPrtTblPrMngCTpuUnitDsc
{

	unsigned char      arUchRV[SIZE_TPDU_PRT_PR_MNG_CNL_SPI];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RVPrtTblPrMngCTpuUnitDsc;

extern TRPrtTblPrMngCTpuUnitDsc hldrTRPrtTblPrMngCTpuUnit;
extern RVPrtTblPrMngCTpuUnitDsc hldrRVPrtTblPrMngCTpuUnit;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""



//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

#define SIZE_TPDU_TRANSPORT_PRT_CNL_SPI 240
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_TRPrtTblTransportCTpuUnitDsc
{

	unsigned char      arUchTR[SIZE_TPDU_TRANSPORT_PRT_CNL_SPI];//0   Data  field
	//
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TRPrtTblTransportCTpuUnitDsc;
typedef struct tag_RVPrtTblTransportCTpuUnitDsc
{

	unsigned char      arUchRV[SIZE_TPDU_TRANSPORT_PRT_CNL_SPI];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RVPrtTblTransportCTpuUnitDsc;

extern TRPrtTblTransportCTpuUnitDsc hldrTRPrtTblTransportCTpuUnit;
extern RVPrtTblTransportCTpuUnitDsc hldrRVPrtTblTransportCTpuUnit;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SIZE_TPDU_FCOIL_CNL_SPI 20
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ TotMeas SO Single Object G- general then P-prorect T1,T2-etc
typedef struct tag_TRFCoilSOCTpuUnitDsc
{

	unsigned char      arUchTR[SIZE_TPDU_FCOIL_CNL_SPI];//0   Data  field
	//
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TRFCoilSOCTpuUnitDsc;
typedef struct tag_RVFCoilSOCTpuUnitDsc
{

	unsigned char      arUchRV[SIZE_TPDU_FCOIL_CNL_SPI];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RVFCoilSOCTpuUnitDsc;


//extern TRFCoilSOCTpuUnitDsc  holderTRFCoilSOCTpuUnit;

extern RVFCoilSOCTpuUnitDsc  holderRVFCoilSOCTpuUnit;	
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SIZE_TPDU_DATE_TIME_CNL_SPI 20
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ TotMeas SO Single Object G- general then P-prorect T1,T2-etc
typedef struct tag_TRDateTimeSOCTpuUnitDsc
{

	unsigned char      arUchTR[SIZE_TPDU_DATE_TIME_CNL_SPI];//0   Data  field
	//
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TRDateTimeSOCTpuUnitDsc;
typedef struct tag_RVDateTimeSOCTpuUnitDsc
{

	unsigned char      arUchRV[SIZE_TPDU_DATE_TIME_CNL_SPI];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RVDateTimeSOCTpuUnitDsc;


//extern TRDateTimeSOCTpuUnitDsc  holderTRDateTimeSOCTpuUnit;

extern RVDateTimeSOCTpuUnitDsc  holderRVDateTimeSOCTpuUnit;	
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

#define SIZE_TPDU_ATR_CMD_CNL_SPI 36
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ TotMeas SO Single Object G- general then P-prorect T1,T2-etc
typedef struct tag_TRAtrCmdSOCTpuUnitDsc
{

	unsigned char      arUchTR[SIZE_TPDU_ATR_CMD_CNL_SPI];//0   Data  field
	//
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TRAtrCmdSOCTpuUnitDsc;
typedef struct tag_RVAtrCmdSOCTpuUnitDsc
{

	unsigned char      arUchRV[SIZE_TPDU_ATR_CMD_CNL_SPI];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RVAtrCmdSOCTpuUnitDsc;



//extern TRAtrCmdSOCTpuUnitDsc  holderTRAtrCmdSOCTpuUnit;

extern RVAtrCmdSOCTpuUnitDsc  holderRVAtrCmdSOCTpuUnit;	
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SIZE_TPDU_DIAGN_BR_CNL_SPI 16
#define SIZE_TPDU_DIAGN_BR_CNL_HSU2 16
#define SIZE_TPDU_DIAGN_BR_CNL_M2M 16
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ TotMeas SO Single Object G- general then P-prorect T1,T2-etc
typedef struct tag_TRDiagnBrBmSOCTpuUnitDsc
{

	unsigned char      arUchTR[SIZE_TPDU_DIAGN_BR_CNL_M2M];//0   Data  field
	//
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TRDiagnBrBmSOCTpuUnitDsc;
typedef struct tag_RVDiagnBrBmSOCTpuUnitDsc
{

	unsigned char      arUchRV[SIZE_TPDU_DIAGN_BR_CNL_M2M];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RVDiagnBrBmSOCTpuUnitDsc;


extern TRDiagnBrBmSOCTpuUnitDsc  holderTRDiagnBrBmSOCTpuUnit;
extern RVDiagnBrBmSOCTpuUnitDsc  holderRVDiagnBrBmSOCTpuUnit;

typedef struct tag_TRDiagnBsBrSOCTpuUnitDsc
{

	unsigned char      arUchTR[SIZE_TPDU_DIAGN_BR_CNL_SPI];//0   Data  field
	//
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TRDiagnBrBsSOCTpuUnitDsc;
typedef struct tag_RVDiagnBsBrSOCTpuUnitDsc
{

	unsigned char      arUchRV[SIZE_TPDU_DIAGN_BR_CNL_SPI];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RVDiagnBrBsSOCTpuUnitDsc;


extern TRDiagnBrBsSOCTpuUnitDsc  holderTRDiagnBrBsSOCTpuUnit;
extern RVDiagnBrBsSOCTpuUnitDsc  holderRVDiagnBrBsSOCTpuUnit;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

#define SIZE_TPDU_VER_INFO_BR_CNL_SPI 0x64
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ TotMeas SO Single Object G- general then P-prorect T1,T2-etc
typedef struct tag_TRTotVerInfoBrBsSOCTpuUnitDsc
{

	unsigned char      arUchTR[SIZE_TPDU_VER_INFO_BR_CNL_SPI];//0   Data  field
	//
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TRTotVerInfoBrBsSOCTpuUnitDsc;
typedef struct tag_RVTotVerInfoBrBsSOCTpuUnitDsc
{

	unsigned char      arUchRV[SIZE_TPDU_VER_INFO_BR_CNL_SPI];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RVTotVerInfoBrBsSOCTpuUnitDsc;


extern TRTotVerInfoBrBsSOCTpuUnitDsc  holderTRTotVerInfoBrBsSOCTpuUnit;

//extern RVTotVerInfoBmSOCTpuUnitDsc  holderRVTotVerInfoBmSOCTpuUnit;



//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SIZE_TPDU_AUX_STNG_BR_CNL_M2M 0x8
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ TotMeas SO Single Object G- general then P-prorect T1,T2-etc
typedef struct tag_TRAuxStngSOCTpuUnitDsc
{

	unsigned char      arUchTR[SIZE_TPDU_AUX_STNG_BR_CNL_M2M];//0   Data  field
	//
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TRAuxStngSOCTpuUnitDsc;
typedef struct tag_RVAuxStngSOCTpuUnitDsc
{

	unsigned char      arUchRV[SIZE_TPDU_AUX_STNG_BR_CNL_M2M];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RVAuxStngSOCTpuUnitDsc;


extern TRAuxStngSOCTpuUnitDsc  holderTRAuxStngSOCTpuUnit;

//extern 
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SIZE_TPDU_UNN_ABS_NUMERTRS_BR_CNL_SPI 9
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ TotMeas SO Single Object G- general then P-prorect T1,T2-etc
typedef struct tag_TRAbsNumeratorUnnSOCTpuUnitDsc
{

	unsigned char      arUchTR[SIZE_TPDU_UNN_ABS_NUMERTRS_BR_CNL_SPI];//0   Data  field
	//
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TRAbsNumeratorUnnSOCTpuUnitDsc;
typedef struct tag_RVAbsNumeratorUnnSOCTpuUnitDsc
{

	unsigned char      arUchRV[SIZE_TPDU_UNN_ABS_NUMERTRS_BR_CNL_SPI];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RVAbsNumeratorUnnSOCTpuUnitDsc;


//extern TRAuxStngSOCTpuUnitDsc  holderTRAuxStngSOCTpuUnit;

extern RVAbsNumeratorUnnSOCTpuUnitDsc holderTRAbsNumeratorUnnSOCTpuUnit;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SIZE_TPDU_ANL_RECORD_BR_CNL_SPI 0x80
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ TotMeas SO Single Object G- general then P-prorect T1,T2-etc
typedef struct tag_TRUN_ArecSOCTpuUnitDsc
{

	unsigned char      arUchTR[SIZE_TPDU_ANL_RECORD_BR_CNL_SPI];//0   Data  field
	//
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TRUN_ArecSOCTpuUnitDsc;
typedef struct tag_RVUN_ArecSOCTpuUnitDsc
{

	unsigned char      arUchRV[SIZE_TPDU_ANL_RECORD_BR_CNL_SPI];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RVUN_ArecSOCTpuUnitDsc;


extern TRUN_ArecSOCTpuUnitDsc  holderTRUN_ArecSOCTpuUnit;

//extern 



//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SIZE_TPDU_GOOS_A_CNL_SPI 216
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ TotMeas SO Single Object G- general then P-prorect T1,T2-etc
typedef struct tag_TRGoosASOCTpuUnitDsc
{

	unsigned char      arUchTR[SIZE_TPDU_GOOS_A_CNL_SPI];//0   Data  field
	//
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TRGoosASOCTpuUnitDsc;
typedef struct tag_RVGoosASOCTpuUnitDsc
{

	unsigned char      arUchRV[SIZE_TPDU_GOOS_A_CNL_SPI];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RVGoosASOCTpuUnitDsc;


extern TRGoosASOCTpuUnitDsc  holderTRGoosASOCTpuUnit;
extern RVGoosASOCTpuUnitDsc  holderRVGoosASOCTpuUnit;	
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SIZE_TPDU_GOOS_B_CNL_SPI 216
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ TotMeas SO Single Object G- general then P-prorect T1,T2-etc
typedef struct tag_TRGoosBSOCTpuUnitDsc
{

	unsigned char      arUchTR[SIZE_TPDU_GOOS_B_CNL_SPI];//0   Data  field
	//
	TRBaseCTpuUnitDsc  TrCnHldr;
	
	

} TRGoosBSOCTpuUnitDsc;
typedef struct tag_RVGoosBSOCTpuUnitDsc
{

	unsigned char      arUchRV[SIZE_TPDU_GOOS_B_CNL_SPI];//0   Data  field
	RVBaseCTpuUnitDsc  RvCnHldr;

} RVGoosBSOCTpuUnitDsc;


extern TRGoosBSOCTpuUnitDsc  holderTRGoosBSOCTpuUnit;
extern RVGoosBSOCTpuUnitDsc  holderRVGoosBSOCTpuUnit;				
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
typedef struct tag_LDCIDsc
{
	unsigned char  uchConMode;
	unsigned char  uchStartSesion;
	unsigned char  uchTR_C;//Size Transmit Data
	unsigned char  NumComSes;
	unsigned short IdConObj;
	char *pSrc,*pDst;

} LDCIDsc;


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define ID_CNL_TEST1 0x1
#define ID_CNL_HSU7  2
#define ID_CNL_HSU2  3
#define ID_CNL_HSU1  4
#define ID_CNL_M2M   5
#define ID_CNL_SPI   6


//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct StateTpCnDsc
{
	unsigned char  uchTpState_CNL_1;
	short PayloadLPDU_CNL_1;//

	long lCapicity_CNL_1;//Current Capicity Payload for Transport
	//unsigned char      *pUchRV;//0   Data  field
	unsigned char      *pUchLpuTR_CNL_1;
	
	unsigned char  uchTpState_CNL_HSU7;
	char  chTotalLDC_CNL_HSU7;
	short PayloadLPDU_HSU7;
	long lCapicity_CNL_HSU7;
	//unsigned char      *pUchRV;//0   Data  field
	unsigned char      *pUchLpuTR_CNL_HSU7;
	unsigned char  uchTpState_CNL_HSU2;
	char  chTotalLDC_CNL_HSU2;
	short PayloadLPDU_HSU2;
	long lCapicity_CNL_HSU2;
	//unsigned char      *pUchRV;//0   Data  field
	unsigned char      *pUchLpuTR_CNL_HSU2;
	unsigned char  uchTpState_CNL_HSU1;
	char  chTotalLDC_CNL_HSU1;
	short PayloadLPDU_HSU1;
	long lCapicity_CNL_HSU1;
	//unsigned char      *pUchRV;//0   Data  field
	unsigned char      *pUchLpuTR_CNL_HSU1;
	unsigned char  uchTpState_CNL_M2m;
	char  chTotalLDC_CNL_M2m;
	short PayloadLPDU_M2m;
	long lCapicity_CNL_M2m;
	unsigned char      *pUchLpuTR_CNL_M2m;
		unsigned char  uchTpState_CNL_Spi;
	char  chTotalLDC_CNL_Spi;
	short PayloadLPDU_Spi;
	long lCapicity_CNL_Spi;
	unsigned char      *pUchLpuTR_CNL_Spi;
	unsigned char  uchhTpState_CNL_3;
	long lCapicity_CNL_3;
	//unsigned char      *pUchRV;//0   Data  field
	unsigned char      *pUchLpuTR_CNL_3;
	
	unsigned char  uchhTpState_CNL_4;
	long lCapicity_CNL_4;
	//unsigned char      *pUchRV;//0   Data  field
	unsigned char      *pUchLpuTR_CNL_4;
	
}StateTpCnDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
typedef struct StateCnlTpCnDsc_tag
{
	unsigned char  uchTpState_CNL;
	char           chTotalLDC_CNL;
	short          shPayloadLPDU;
	long           lCapicity_CNL;
	//unsigned char      *pUchRV;//0   Data  field
	unsigned char      *pUchLpuTR_CNL;

}StateCnlTRTpCnDsc;


extern  StateTpCnDsc hldrTpCnState;
extern  SrcSamplesUnitDsc  holderSrcSamplesUnit;



extern void ActivateServTrApCnSamplesCTpuUnit(void);
extern void ActivateServTrApCnSamplesCTpuUnitHSU2(void);

extern int ScanCn1(void *pLpuCn1 );
extern int ScanCnl(long lIDr);

extern void ActivateTrServiceApCn(void* pvD,long IdObj);
extern void ActivateServiceTrApCn(void* pvD,long IdObj);
extern void ServiceApCn(void* pvD,long IdObj);

extern void ExtractLdc(void *pLDC);


extern void TerminateTrServiceApCn(void* pvD,long IdObj);

extern int ServiceTRApCn2(void* pvCTpuTR,void* pvStateTpCnDsc );

//.extern void ActivateServiceApCn(void* pvD,long IdObj);
//.extern void ServiceApCn(void* pvD,long IdObj);
//.extern void TerminateServiceApCn(void* pvD,long IdObj);
extern int AsemblyLDC(void *pvLDCInfo);
extern void* GetAddrObj(long IdObj);
extern void* GetAddrPFL_VL(long IdObj);
#endif /* Tpu_h */
