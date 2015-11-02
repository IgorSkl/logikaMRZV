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
* File Name       : AppCn.h
* Description     : support for the AppCn.c
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  10/09/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef ApCn_h
#define ApCn_h

#define START 1
#define EXEC  2
#define TERM  3
//Pointer function return long param void and long
typedef long(*PFL_VL)(void* pv, long lV);

//.#define KEY_MASK ((unsigned long long)0xFFFFFFFFF) //
//Aplication Connect Def Module CPU_CM CPU connect Module
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
//...typedef struct tag_KbdU32
//...{
//...	union {
//...
//...			unsigned char      arUch[8];//0  input Data  field
//...			unsigned short     arUsh[4 ];//01 Key1 field
//...			unsigned long int  arUl [2 ];//02 Key2 field 
//...	}UNFKeyField;//UNF-Union Field Bit - Total 64 bit
//...
//...	union {
//...			unsigned long ulReserv;  //0x Reserv fiel for future
//...			
//...	}UNFReserv;//
//...	
//...}KbdUNFldHolderDsc; OCS -Obj Connection State
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define USING_OCS_ONB      0
#define TR_MODE_OCS_ONB    1
#define RV_MODE_OCS_ONB    2
#define RST_OCS_ONB        3

#define STT_START_OCS_ONB  5
#define STT_WORK_OCS_ONB   6
#define STT_STOP_OCS_ONB   7
#define AUX_OCS_ONB        8

#define USING_OCS_MSK      (1<< USING_OCS_ONB    )
#define TR_MODE_OCS_MSK    (1<< TR_MODE_OCS_ONB  )
#define RV_MODE_OCS_MSK    (1<< RV_MODE_OCS_ONB  )
#define STT_START_OCS_MSK  (1<< STT_START_OCS_ONB)
#define STT_WORK_OCS_MSK   (1<< STT_WORK_OCS_ONB )
#define STT_STOP_OCS_MSK   (1<< STT_STOP_OCS_ONB )
#define RST_OCS_MSK        (1<< RST_OCS_ONB      )


#define AUX_OCS_MSK        (1<< AUX_OCS_ONB      )


//Aplication Connect Def Module CPU_CM CPU connect Module
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~   ACPU_CM for BigObject Exeception   ~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_BaseAcpuCMUnitDsc
{


	short shIDObj;
	unsigned short AppObjConState;//12 bit Id Conection 
	//Bits
	//0 - Obj Active
	//1 - 1 - Transmit Mode
	//2 - 1 - Recieve  Mode
	//3 - 1 - Reserv1 Field 
	//4 - 1 - Reserv Field
	//5 - 1 - State Start
	//6 - 1 - State Work
	//7 - 1 - State Stop 
	unsigned long ulRvCount;
	unsigned long ulTrCount;
	unsigned long ulRvTotal;
	unsigned long ulTrTotal;
	unsigned char      *pUchRV;//Base
	unsigned char      *pUchTR;//Base
	////////////////////////////////
	//void* pvQ;//Activator Req
	//void* pvQ;//Activator ExecReq
	//void* pvQ;//Activator answerReq
	//void* pvQ;//Activator changeState
	PFL_VL pf_Init;
	PFL_VL pf_Rst;
	PFL_VL pf_Work;
	PFL_VL pf_ExecCmd;
	
} BaseAcpuCMUnitDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//Aplication Connect Def Module CPU_CM CPU connect Module
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~   ACPU_CM for BigObject  ~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ who must have oun Copy 
typedef struct tag_BigObjCMUnitDsc
{


//	short shIDObj;
	unsigned short AppObjConState;//12 bit Id Conection 
	//Bits
	//0 - Obj Active
	//1 - 1 - Transmit Mode
	//2 - 1 - Recieve  Mode
	//3 - 1 - Reserv1 Field 
	//4 - 1 - Reserv Field
	//5 - 1 - State Start
	//6 - 1 - State Work
	//7 - 1 - State Stop 
//	unsigned long ulRvCount;
//	unsigned long ulTrCount;
//	unsigned long ulRvTotal;
//	unsigned long ulTrTotal;
//	unsigned char      *pUchRV;//Base
//	unsigned char      *pUchTR;//Base
	long lCsAppObj;
	////////////////////////////////
	//void* pvQ;//Activator Req
	//void* pvQ;//Activator ExecReq
	//void* pvQ;//Activator answerReq
	//void* pvQ;//Activator changeState
	//PFL_VL pf_Init;
	//PFL_VL pf_Duplicate;//CopyOriginalObj;
	//PFL_VL pf_DeCompose;//Cut into chunk OriginalObj;
	//PFL_VL pf_Replicate;//Restore chunk of OriginalObj
	//PFL_VL pf_Update;//Final Control and Inform System then Obj Update
	
} BigObjCMUnitDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Digital samples Unit    ~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_SrcSamplesUnitDsc
{

	unsigned char      arUch[48];//0   Data  field

} SrcSamplesUnitDsc;
extern int TestReqTransmitT1;
extern int TestReqReceiveT1;
#define ID_SRC_SAMPLES_UNIT 0x1
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_SrcAPCSUnitDsc
{
	unsigned char      arUch[80];//0   Data  field

}SrcAPCSUnitDsc;
#define ID_SRC_APCS_UNIT 0x2
extern int TestReqTransmitT2;
extern int TestReqReceiveT2;

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define ACTIVATE_FILL_DATA       1
#define RECIVE_FILL_DATA         2
#define ACTIVATE_TRANSMIT_DATA   3
#define TRANSMIT_FILL_DATA       4
#define FREE_FILL_DATA           5
#define TOTAL_CMD                (FREE_FILL_DATA+1)

#define CTR_WAITING_DATA_SAMPLES   1
#define CTR_TRANSMITTING           2
#define CTR_AAA   3
#define VAL_WAITING_DATA_SAMPLES   0x100000
#define VAL_TRANSMITTING           0x100000
#define VAL_AAA                    0x100000

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

typedef struct tag_TenPerSamplesUnitDsc
{
    
	
	BaseAcpuCMUnitDsc hldrAcpuCMUnitState;
	//long current_data_transmit[NUMBER_CANALS*NUMBER_POINT*NUMBER_PERIOD_TRANSMIT];
	unsigned char arUchExecCmd[8]; //
	unsigned char arUchRvParamCmd[32]; //Additional Input Param If Need
	unsigned long arU32LifeCtr[4];    //Activity Counters

} ProxyTenPerSamplesUnitDsc;
extern int TestReqTransmitTenPerSamples;
extern int TestReqReceiveTenPerSamples;
#define ID_TEN_PERIOD_SAMPLES_UNIT 0x4
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

typedef struct tag_TotMeasUnitDsc
{
    
	
	BaseAcpuCMUnitDsc hldrAcpuCMUnitState;
	//,,extern __TOTAL_MEASUREMENT total_measurement;
	unsigned char arUchExecCmd[8]; //
	unsigned char arUchRvParamCmd[32]; //Additional Input Param If Need
	unsigned long arU32LifeCtr[4];    //Activity Counters

} ProxyTotMeasUnitDsc;
extern int TestReqTransmitTotMeas;
extern int TestReqReceiveTotMeas;
#define ID_TOTAL_MEAS_UNIT 0x5
extern ProxyTotMeasUnitDsc  holderProxyTotMeasUnit;

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_SrcTest1UnitDsc
{
	unsigned char      arUch[800];//0   Data  field

}SrcTest1UnitDsc;
#define ID_SRC_TEST1_UNIT 0x3
extern int TestReqTransmitT3;
extern int TestReqReceiveT3;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_PrepDecompouseTrEvtDsc
{

	unsigned short IdSelObj;
	//char *pSrc,*pDst;

} PrepDcpTrEvtDsc;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                 ~~~    HEADER  Data  REQUEST STATE STRUCTS  ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
typedef struct ObjParamDsc_TagIn
{
long size_Obj ;      //Размер считанного массива
void *p_ObjEntity ;//Указатель на начало данных

}ObjParamDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define ID_TOTAL_MEASG_UNIT 0x6
#define ID_TOTAL_MEASR_UNIT 0x8
extern int AppReqTransmitTotMeasR;
extern int AppReqReceiveTotMeasR ;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
extern long timerWaitReqHSU2;
extern long timerWaitReqHSU1;
extern long timerWaitReqHSU7;
extern long timerWaitReqM2m;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_SETTING_PR_MNG 0X10
#define ID_SETTING_PR_TRANSPORT 0X11
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_YUST_PR_MNG 0X12
#define ID_YUST_PR_TRANSPORT 0X13
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_APCS_UNIT  0x14
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_PRT_PR_MNG 0X15
#define ID_PRT_PR_TRANSPORT 0X16

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_GOOS_A_UNIT  0x17
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_GOOS_B_UNIT  0x18
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_TELE_MECHS_UNIT  0x19
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_FCOIL_UNIT  0x1A
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_DATE_TIME_UNIT  0x1B
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_ATR_CMD_UNIT  0x1C
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_DIAGN_BM_UNIT  0x1D
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_DIAGN_BR_UNIT  0x1E
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_DIAGN_BS_UNIT  0x1F
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_VER_INFO_BM_UNIT  0x20
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_VER_INFO_BR_UNIT  0x21
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_VER_INFO_BS_UNIT  0x22
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_AUX_STNG_UNIT  0x23
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_UNN_ABS_NUMERTRS_UNIT  0x24
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
#define ID_ANL_RECORD_UNIT  0x25
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


extern void ProcessTransmitEvt(void);
extern void ProcessReceiveEvt(void);
extern void UpdateAppData(void);


extern long SelectObj(void);
extern long PrepareDecompouseTrEvt(long lIdObj);

void PrepDecompouseSrcSamplesUnit(void);
void PrepDecompouseSrcSamplesUnitHSU2(void);
void PrepDecompouse10PeriodUnitHSU2(void);
void PrepDecompouseTotMeasUnitHSU2(void);
void PrepDecompouseTotMeasRUnitM2m(void);
void PrepDecompouseApcsUnitSpi(void);
void PrepDecompouseGoosAUnitSpi(void);
void PrepDecompouseGoosBUnitSpi(void);
void PrepDecompousePrtTblTptUnitSpi(void);
void PrepDecompouseTeleMechsUnitSpi(void);

void PrepDecompouseTotVerInfoUnitHSU2(void);
void PrepDecompouseDiagnUnitSPI(void);
void PrepDecompouseAuxStngUnitM2m(void);


void PrepDecompouseSrcTest1Unit(void);
//void PrepDecompouse Unit(void)
extern long ActivateRVProxyTenPerSamplesCTpuUnit(void* pvLDC, long lID);
extern long ActivateRVProxyTotMeasCTpuUnit(void* pvLDC, long lID);

extern void ExecProxy(void);
extern void UpdateAppData(void);
extern long InitProxyTenPerSamples (void* pv, long lV);
extern long WorkProxyTenPerSamples (void* pv, long lV);
extern long ResetProxyTenPerSamples (void* pv, long lV);
extern long ExecCmdProxyTenPerSamples (void* pv, long lV);

extern long InitProxyTotMeas (void* pv, long lV);
extern long WorkProxyTotMeas (void* pv, long lV);
extern long ResetProxyTotMeas (void* pv, long lV);
extern long ExecCmdProxyTotMeas (void* pv, long lV);

extern void DbgModifyPrMng(void* pv, long lV);

extern void TotMeasRRvServCTpuApCnUnit(void);

extern long lBlockSpiCtr;
extern void SpiStallHundler(void);

/*
//Aplication Connect Def Module CPU_CM CPU connect Module
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~   ACPU_CM for BigObject  ~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ who must have oun Copy 
typedef struct tag_BigObjCMUnitDsc
{


	short shIDObj;
	unsigned short AppObjConState;//12 bit Id Conection 
	//Bits
	//0 - Obj Active
	//1 - 1 - Transmit Mode
	//2 - 1 - Recieve  Mode
	//3 - 1 - Reserv1 Field 
	//4 - 1 - Reserv Field
	//5 - 1 - State Start
	//6 - 1 - State Work
	//7 - 1 - State Stop 
	unsigned long ulRvCount;
	unsigned long ulTrCount;
	unsigned long ulRvTotal;
	unsigned long ulTrTotal;
	unsigned char      *pUchRV;//Base
	unsigned char      *pUchTR;//Base
	long lCsAppObj;
	////////////////////////////////
	//void* pvQ;//Activator Req
	//void* pvQ;//Activator ExecReq
	//void* pvQ;//Activator answerReq
	//void* pvQ;//Activator changeState
	PFL_VL pf_Init;
	PFL_VL pf_Duplicate;//CopyOriginalObj;
	PFL_VL pf_DeCompose;//Cut into chunk OriginalObj;
	PFL_VL pf_Replicate;//Restore chunk of OriginalObj
	PFL_VL pf_Update;//Final Control and Inform System then Obj Update
	
} BigObjCMUnitDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""



*/
#endif /* ApCn_h */
