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
* File Name       : cy7.h
* Description     : Interface for the cy7.c on CY7C024BV-20AXI
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  05/03/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef  cy7_h
#define  cy7_h


#define SIZE_LPDU_CNL_CY7  640



#define ADR_FULLWORD_SEMAFOR_BM_1           (0xE2000010)

#define ADR_FULLWORD_SEMAFOR_BM_2            (ADR_FULLWORD_SEMAFOR_BM_1       +4)
#define ADR_FULLWORD_SEMAFOR_BR_1            (ADR_FULLWORD_SEMAFOR_BM_2       +4) 
#define ADR_FULLWORD_SEMAFOR_BR_2            (ADR_FULLWORD_SEMAFOR_BR_1       +4)





#define ADR_AR_BM            (ADR_FULLWORD_SEMAFOR_BR_2        +4)
#define ADR_AR_BR            (ADR_AR_BM                        +SIZE_LPDU_CNL_CY7)
 
#define ADR_END_DATA         ( ADR_AR_BR                       +SIZE_LPDU_CNL_CY7)


extern long ram_semafor_bm_1;
extern long ram_semafor_bm_2;
extern long cy7_semafor_br_1;
extern long cy7_semafor_br_2;

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

extern long outCY7(unsigned char *dat,  int bytes);
extern long inCY7 (unsigned char *buff, int bytes);
extern void CY7_send_cb(void);
extern  long DetectorActivity(void);
extern  long DetectorActivityV1(void);

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
extern long DmaMemCopy(long lDst, long lSrc,long lAmt)   @ "Fast_function_no_cache";

//extern 
//extern 



#endif /* cy7_h */