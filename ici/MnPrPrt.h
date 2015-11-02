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
* Processor       : at91sam9g45
* File Name       : MnPrPrt.h
* Description     :  support for the MnPrPrt.c
                    BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  04/01/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/


#ifndef MNR_PR_PRTTBL_h
#define MNR_PR_PRTTBL_h

//#include    "./inc/hv_df.h"
#include    "./inc/ici_r_ef.h"


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


#ifndef HV_DF_h
#define SIZE_PRT 0X1035
#endif 
#ifdef HV_DF_h
#define SIZE_PRT (  ((sizeof(CfgTblDsc )>>2)<<2) + (4*(1&&(sizeof(CfgTblDsc ))&3))    )
//( ((sizeof(__YUST )>>2)<<2) + 4*(1&&(sizeof(__YUST ))&3) )
#endif


typedef struct tag_PrtTblHldDsc
{
	union 
	{

#ifdef 	HV_DF_h	
			char   chArPrt  [ sizeof(CfgTblDsc )];
#else					
	    	char   chArPrt  [ SIZE_PRT];
#endif			
	    	long    lArPrt  [ (SIZE_PRT>>2)+1];//One additional Word

#ifdef 	HV_DF_h
			CfgTblDsc CfgPrtTbl;
#else			
			unsigned int PrtTbl[SIZE_PRT>>2];
#endif  
	}UNPrtTbl;
	long lCheckSum;
}PrtTblHldDsc;
extern long lSizeOf_PrtTbl;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

extern long lSizeOf_PrtTbl ;
extern PrtTblHldDsc holderPrtTbl;


extern unsigned int PrtTbl[];//
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                 ~~~    HEADER  Ar_protection tbl  REQUEST STATE STRUCTS  ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
typedef struct PrtTblStateDsc_TagIn
{
long size_PrtTbl ;      //Размер считанного массива 
void *p_PrtTbl ;//Указатель на начало данных

}PrtTblStateDsc;
//~~~   
//``````````````````````````````````````````````````````````````````````````````````
//~~~  p_PrtTbl  будет  конвертироваться к типу PrtTbl                         ~~~~~
//~~~  Массив PrtTbl должна, где-то объявить система                           ~~~~~
//~~~  параметрирования после получения ответа 1 - команда начала выполняться  ~~~~~
//~~~  содержимое заносится во внутренний буфер системы межпроцессорного       ~~~~~
//~~~  обмена и возвращается результат для контроля с BM                       ~~~~~
//~~~                                                                          ~~~~~
//``````````````````````````````````````````````````````````````````````````````````
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


typedef struct tag_AlgPrtTblWrEctDsc
{
	char chIdxCmd;
	char chLastCmd;
	unsigned char arUchExecCmd[2];
	//unsigned long arU32LifeCtr[4];
	unsigned char arUchResultExecCmd[2];//Hold result exec command
} AlgPrtTblWrEctDsc;

AlgPrtTblWrEctDsc hldrAlgPrtTblWrEct;



extern int  ReqTransmitPrtTblPrMng;
extern int  ReqReceivePrtTblPrMng;


extern ProxyTransportStateDsc hldPrTrptPrtTbl;
extern ProxyMangerStateDsc  hldPrMngPrtTbl;
extern int  ReqTransmitPrtTblPrTpt;
extern int  ReqReceivePrtTblPrTpt;

extern long WorkProxyManager (void* pv, long lV);
extern long ExecTargetProxyManager (void* pv, long lV);

long ExecCmdPrtTblPrTpt (void* pv, long lV);
long ResetPrtTblPrTpt (void* pv, long lV);
long ActivatePrtTblTrPrTpt(void* pObjParam, long lV);
long ActivatePrtTblRvPrTpt(void* pObjParam, long lV);
extern long SelectorCmd(void* pv);


extern long ActivatePrtTblPrMng(void);

//extern long ActivateTRStngPrTpt(void* pObjParam, long lID);

//extern long ActivateTransmitStngObj(void);
extern long ActivatePrtTblTransmitObj(void);
//extern long ActivateReceiveStngObj(void);
extern long ActivatePrtTblReceiveObj(void);

extern PrtTblStateDsc testPrtTblState;


long TryPrtTblSetSendEct   (void* pv, long lV);
long DpcsPrtTblPrMngMsg   (void* pv, long lV);
long ExecPrtTblCmdPrMng   (void* pv, long lV);
long SetPrtTblSendEct ( void* pv, long lV);
long WaitPrtTblCmdHmEct   (void* pv, long lV);

long SetPrtTblSendReqTrEct(void* pv, long lV);
long AlgPrtTblWriteEct(void* pv, long lV);
long TryPrtTblPrMngAlgWrActivate  (void* pv, long lV);




long ActivatePrtTblPrMng       (void);
long PassPrtTblPrMngRvMsgOrigin(void);






#include    "CmmConst.h"
#endif
