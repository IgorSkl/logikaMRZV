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
* File Name       : ici_api.h
* Description     : Functions and Data for API,
                    interprocessor communication

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  31/08/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#ifndef	ICI_API_H
#define	ICI_API_H

//#include "./lpc_types.h"
#define BM_TMR_ACTIVITY_RV_CY7_VAL   0x119
#define BM_TMR_ACTIVITY_TR_CY7_VAL   0x119

#define BR_TMR_ACTIVITY_RV_CY7_VAL   0x151
#define BR_TMR_ACTIVITY_TR_CY7_VAL   0x151





#if defined (__cplusplus)
extern "C"
{
#endif

extern int AppReqTransmitApcs;
extern int AppReqTransmitGoosA ;


extern  long lSsp0HdwState ;
extern  long Ssp_Syncro1(void);
extern  long Ssp_Syncro4(void);

extern unsigned char chEntry_Hs7;
extern unsigned char chEntry_Hs2;
extern unsigned char chEntry_Hs1;

extern void ProcessReceiveLpduHSU7(void);
extern void ProcessReceiveLpduHSU2(void);
extern void ProcessReceiveLpduHSU1(void);

extern  char chHSU2SendHdwEror;
extern void RecoverHSU2(void);
extern long IsEOI_HS2(void);

extern unsigned long samples_data_rdy;

extern unsigned char meas_data_rdy;

extern long Samples_Ready_Handler(void* pv);
extern long Meas_Ready_Handler   (void* pv);

extern void ScanAppReq(void);


extern void ici_hdw_init(void);

extern void ProcessTransmitEvt(void);
extern void ProcessReceiveEvt(void);

extern void Scan_Ici_Event_Req(void);
extern void Scan_Ici_Entry_Data(void);

extern void PrepDecompouseSrcSamplesUnit(void);
extern void TestSetup_SrcSamples_ForTransmit(void);

extern void TestSetup_LpduHSU7_ForTransmit(void);
extern void ProcessTransmitLpduHSU7(void);

extern void ExecProxy(void);
extern void ActivateProxyTenPerSamples(void);
extern long PassPrtTblPrMngRvMsgOrigin(void);

extern void UpdateAppData(void);


extern void StubForSpiChanel(void);
extern void StubForSpiChanel1(void);


extern  long DetectorActivity(void);
extern void CY7_send_cb(void);




#endif
