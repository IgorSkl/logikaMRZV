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
* File Name       : lpu.c
* Description     : Functions and Data for Link Leyer
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  10/09/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#include    "ApCn.h"
#include    "CTpu.h"
#include    "lpu.h"

#include "hu7lI.h"
#include "cy7.h"
#include <intrinsics.h>
#include <string.h>
#include "../LIB/CDL_AV0/csps/lpc32xx/include/lpc32xx_gpio_driver.h"

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
TRStateLpuCn1Dsc holderCn1LpduUnit;
RVStateLpuCn1Dsc hldrCn1LpduUnit;
 
TRStateLpuHSU7Dsc hldrHSU7LpduTRUnit;
TRStateLpuHSU1Dsc hldrHSU1LpduTRUnit;
TRStateLpuHSU2Dsc hldrHSU2LpduTRUnit;
TRStateLpuM2mDsc   hldrM2mLpduTRUnit;
TRStateLpuSpiDsc  hldrSpiLpduTRUnit;


RVStateLpuU3Dsc   hldrU3LpduUnit;
RVStateLpuHSU7Dsc hldrHSU7LpduUnit;
RVStateLpuHSU1Dsc hldrHSU1LpduUnit;
RVStateLpuHSU2Dsc hldrHSU2LpduUnit;
RVStateLpuM2mDsc   hldrM2mLpduUnit;
RVStateLpuSpiDsc  hldrSpiLpduUnit;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
unsigned long ulCtrTrLpduSpi = 0;














//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
//typedef struct tag_
//{
	//.union {
    //.
	//.		unsigned char      arUch[8];//0  input Data  field
	//.		unsigned short     arUsh[4 ];//01 Key1 field
	//.		unsigned long int  arUl [2 ];//02 Key2 field 
	//.}UNFKeyField;//UNF-Union Field Bit - Total 64 bit
    //.
	//.union {
	//.		unsigned long ulReserv;  //0x Reserv fiel for future
	//.		
	//.}UNFReserv;//
	
//}StateLpuCn2Dsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

void ProcessReceiveLpdu(void)
{
register long i,j;
register char *pDst;
register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		unsigned char uChIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
		
		
	} sLV;
 pv  = (void*)&holderCn1LpduUnit;

i = hldrCn1LpduUnit.uchLpuCn1State = ((TRStateLpuCn1Dsc*)pv)->uchLpuCn1State;
if (i==0) return;
hldrCn1LpduUnit.uchCI          = ((TRStateLpuCn1Dsc*)pv)->uchCI;
hldrCn1LpduUnit.ushSizeLDC     = ((TRStateLpuCn1Dsc*)pv)->ushSizeLDC;
hldrCn1LpduUnit.lCs            = ((TRStateLpuCn1Dsc*)pv)->lCs;

((TRStateLpuCn1Dsc*)pv)->uchCI = 0;
((TRStateLpuCn1Dsc*)pv)->uchLpuCn1State = 0;
j = sLV.ushSizeLDC = ((TRStateLpuCn1Dsc*)pv)->lCapicity;
((TRStateLpuCn1Dsc*)pv)->lCapicity = 0;

pDst = (char*)& (hldrCn1LpduUnit.arUch[0]); 
for (i = 0; i< j; i++)
pDst[i] = ((TRStateLpuCn1Dsc*)pv)->arUch[i]; 


}
void ProcessTransmitLpdu(void)
{
register long i,j;
register char *pSrc;//,*pDst;
register void* pv;
 pv  = (void*)&holderCn1LpduUnit;
  pSrc = (char*)&hldrTpCnState;
j =  ((StateTpLpuDsc*)pSrc)->uchTpState_CNL_1;//
 if (j==0) return;
((TRStateLpuCn1Dsc*)pv)->uchCI = HDR_MODE_CNL_1;
((TRStateLpuCn1Dsc*)pv)->uchLpuCn1State = 1;


i = ((StateTpLpuDsc*)pSrc)->PayloadLPDU_CNL_1
 - ((StateTpLpuDsc*)pSrc)->lCapicity_CNL_1;
 ((TRStateLpuCn1Dsc*)pv)->lCapicity = i;
 
((StateTpLpuDsc*)pSrc)->lCapicity_CNL_1 =((StateTpLpuDsc*)pSrc)->PayloadLPDU_CNL_1;

}

long Eval_CS(char* pCh, long iLength )  @ "Fast_function"
{
//register long lCs;
register long i,n;
n = 1;
for (i = 0; i < iLength; i++)
{
	n +=  pCh[i];
}
n &= 0xff;

return n;
}

void ProcessReceiveLpdu_(void)
{
register long i,j;
register char *pDst;
register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		unsigned char uChIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
		
		
	} sLV;
 pv  = (void*)&holderCn1LpduUnit;

i = hldrCn1LpduUnit.uchLpuCn1State = ((TRStateLpuCn1Dsc*)pv)->uchLpuCn1State;
if (i==0) return;
hldrCn1LpduUnit.uchCI          = ((TRStateLpuCn1Dsc*)pv)->uchCI;
hldrCn1LpduUnit.ushSizeLDC     = ((TRStateLpuCn1Dsc*)pv)->ushSizeLDC;
hldrCn1LpduUnit.lCs            = ((TRStateLpuCn1Dsc*)pv)->lCs;

((TRStateLpuCn1Dsc*)pv)->uchCI = 0;
((TRStateLpuCn1Dsc*)pv)->uchLpuCn1State = 0;
j = sLV.ushSizeLDC = ((TRStateLpuCn1Dsc*)pv)->lCapicity;
((TRStateLpuCn1Dsc*)pv)->lCapicity = 0;

pDst = (char*)& (hldrCn1LpduUnit.arUch[0]); 
for (i = 0; i< j; i++)
pDst[i] = ((TRStateLpuCn1Dsc*)pv)->arUch[i]; 


}


void ProcessReceiveLpduU3(void)
{
register long i,j;
//register char *pDst;
register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		unsigned char uChIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
		
		
	} sLV;
 pv  = (void*)&hldrU3LpduUnit;

//.i = hldrCn1LpduUnit.uchLpuCn1State = ((TRStateLpuCn1Dsc*)pv)->uchLpuCn1State;
i= ((RVStateLpuU3Dsc*)pv)->uchLpuU3State;//hldrU3LpduUnit. uchLpuU3State
if (i==0) return;
//.hldrCn1LpduUnit.uchCI          = ((TRStateLpuCn1Dsc*)pv)->uchCI;
//.hldrCn1LpduUnit.ushSizeLDC     = ((TRStateLpuCn1Dsc*)pv)->ushSizeLDC;
//.hldrCn1LpduUnit.lCs            = ((TRStateLpuCn1Dsc*)pv)->lCs;
//long inU3(UNS_8 *buff, int bytes); (unsigned char*)
//---j = (long)(((RVStateLpuU3Dsc*)pv)->arUch[0]);
j = inU3(&(((RVStateLpuU3Dsc*)pv)->arUch[0]),SIZE_LPDU_CNL_U3);
sLV.ushSizeLDC = j;
//Clear LL Message income frome hardware 
if ((j ==0) || (j!=SIZE_LPDU_CNL_U3) ) goto f_exit;


//Check CS
i = Eval_CS((char*)&(((RVStateLpuU3Dsc*)pv)->arUch[0]),j);
if (i!=(((RVStateLpuU3Dsc*)pv)->arUch[j])) goto f_exit;
//Check CFI 
if((((RVStateLpuU3Dsc*)pv)->arUch[0])!=(HDR_MODE_CNL_1)) goto f_exit;

//long inU7(UNS_8 *buff, int bytes);
//-dbg  ((TRStateLpuCn1Dsc*)pv)->uchCI = 0;
//-dbg  ((TRStateLpuCn1Dsc*)pv)->uchLpuCn1State = 0;
//-dbg  j = sLV.ushSizeLDC = ((TRStateLpuCn1Dsc*)pv)->lCapicity;
//-dbg  ((TRStateLpuCn1Dsc*)pv)->lCapicity = 0;


//-dbg pDst = (char*)& (hldrCn1LpduUnit.arUch[0]); 
//-dbg for (i = 0; i< j; i++)
//-dbg pDst[i] = ((TRStateLpuCn1Dsc*)pv)->arUch[i]; 

//Activate Next Leyer.

f_exit:
return;
}

extern long hs_uart_recover(long);
extern int hs7_rxsize;
extern long hs7uartdev;
void ProcessReceiveLpduHSU7(void)
{
register long i,j;
register char *pDst;
register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		char PacketGood,PacketBad;
		
		unsigned char uChIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
		
		
	} sLV;
	sLV.PacketGood = 0;sLV.PacketBad = 0;
	sLV.uChIdxByte = sLV.ushSizeLDC = 0;
 pv  = (void*)&hldrHSU7LpduUnit;//holderCn1LpduUnit;
pDst = (char*)&hldrHSU7LpduUnit.arUch[0];//( ((RVStateLpuHSU7Dsc *)pv)->arUch[0]  );
sLV.ushSizeLDC = j = hs7_rxsize; 

//i = hs_uart_recover(hs7uartdev);

if (j<SIZE_LPDU_CNL_HSU7) 
{
	sLV.uChIdxByte = inU7((unsigned char*)pDst,j);
}
else 
	{
		i = sLV.ushSizeLDC;
		
		do
		{
			i = hs7_rxsize;
			if (i > SIZE_LPDU_CNL_HSU7)
			{
				i-= SIZE_LPDU_CNL_HSU7;
				j = SIZE_LPDU_CNL_HSU7;
			}	
			else 
				j = i;
			sLV.uChIdxByte = inU7((unsigned char*)pDst,j);	
		}
		while(hs7_rxsize);
	
	}
//1<<24;


 
((RVStateLpuHSU7Dsc *)pv)->uchCI = i= pDst[0];
if (i != HDR_MODE_CNL_1)
	sLV.PacketBad++;
else
	sLV.PacketGood++;

i = pDst[1];

if (i>SIZE_LPDU_CNL_HSU7)
sLV.PacketBad++;
else
sLV.PacketGood++;

sLV.ushSizeLDC = ((RVStateLpuHSU7Dsc *)pv)->ushSizeLDC = i;
 ((RVStateLpuHSU7Dsc *)pv)->ushSizeLDC = i;
j = Eval_CS(pDst,i+(SIZE_LPCI_FLD_CNL_HSU7)); 
if (j!=pDst[i+(SIZE_LPCI_FLD_CNL_HSU7)])
{
sLV.PacketBad++;
}
else
sLV.PacketGood++;

((RVStateLpuHSU7Dsc *)pv)->lCs = j; 

if (sLV.PacketBad)
{
	((RVStateLpuHSU7Dsc *)pv)->lCapicity   = 0;
	((RVStateLpuHSU7Dsc *)pv)->uchCI       = 0;
	((RVStateLpuHSU7Dsc *)pv)->ushSizeLDC  = 0;
	((RVStateLpuHSU7Dsc *)pv)->lCs         = 0;
	
	((RVStateLpuHSU7Dsc *)pv)->uchLpuHSU7State = 0;
	return;
}
if (sLV.PacketGood)
{
	((RVStateLpuHSU7Dsc *)pv)->lCapicity   = 0;
	((RVStateLpuHSU7Dsc *)pv)->uchCI       = 0;
	((RVStateLpuHSU7Dsc *)pv)->ushSizeLDC  = 0;
	((RVStateLpuHSU7Dsc *)pv)->lCs         = 0;	
;//Ativate Next Leyer
	((RVStateLpuHSU7Dsc *)pv)->uchLpuHSU7State = 1;
//...Now Use as Channel Identification	
	//((RVStateLpuHSU7Dsc *)pv)->uchCI       = ID_CNL_HSU7;

}


}

void ProcessTransmitLpduHSU7(void)
{
register long i,j;
register char *pSrc,*pDst;
register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		unsigned short uShIdxByte ;
		//unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
	} sLV;
static char arCh[20] = {
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,//0x45,0x45,0x45,0x45,
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45 //0x45,0x45,0x45,0x45,

};
 pv  = (void*)&hldrHSU7LpduTRUnit;
  pSrc = (char*)&hldrTpCnState;


//Start for Activating of Lpdu Units 
j =  ((StateTpCnDsc*)pSrc)->uchTpState_CNL_HSU7;//
 if (j==0) return;
 
 
((TRStateLpuHSU7Dsc*)pv)->uchCI = HDR_MODE_CNL_1;//HDR_MODE_CNL_1;
((TRStateLpuHSU7Dsc*)pv)->uchLpuHSU7State = 1;


i = ((StateTpCnDsc*)pSrc)->PayloadLPDU_HSU7
+(SIZE_LDC_FLD_CNL_HSU7)+(SIZE_TOTAL_LDC);
// - ((StateTpCnDsc*)pSrc)->lCapicity_CNL_HSU7;
 //.i = 20;
 ((TRStateLpuHSU7Dsc*)pv)->lCapicity = i;//Real Size Pacet
 
//.((StateTpCnDsc*)pSrc)->lCapicity_CNL_HSU7 =((StateTpCnDsc*)pSrc)->PayloadLPDU_HSU7;

//Create Pacet
((TRStateLpuHSU7Dsc*)pv)->uchCI = (HDR_MODE_CNL_1);
((TRStateLpuHSU7Dsc*)pv)->ushSizeLDC = ((TRStateLpuHSU7Dsc*)pv)->lCapicity;

j = 0;
(((TRStateLpuHSU7Dsc*)pv)->arUch[0]) = ((TRStateLpuHSU7Dsc*)pv)->uchCI;
i = ((TRStateLpuHSU7Dsc*)pv)->uchCI;
i &= 0xf;
i>>=1;
switch (i)
	{
	case 0:
		j = 0;
		break;
	case 1:
		
		(((TRStateLpuHSU7Dsc*)pv)->arUch[j+1]) = ((TRStateLpuHSU7Dsc*)pv)->ushSizeLDC;
		j = 1;
		break;
	case 2:
	    pDst = (char*)&(((TRStateLpuHSU7Dsc*)pv)->arUch[j+1]);
		*((short*)pDst) = ((TRStateLpuHSU7Dsc*)pv)->ushSizeLDC;
		j = 2;
		break;
	
	default:
	j=1;
	} 


sLV.uShIdxByte = j;
///////////////////PUT TOT LDC FIELD////////////////////
pDst = (char*)&(((TRStateLpuHSU7Dsc*)pv)->arUch[j+1]);
*(pDst) = ((StateTpCnDsc*)pSrc)->chTotalLDC_CNL_HSU7;
////////////////////////////////////////////////////////
pSrc = (char*)&arCh[0];//Tempor Data !!!
pDst = (char*) &(((TRStateLpuHSU7Dsc*)pv)->arUch[j+1]); 

//sLV.uShIdxByte += SIZE_TOTAL_LDC;

j = ((TRStateLpuHSU7Dsc*)pv)->ushSizeLDC;
sLV.uShIdxByte += j; 
//for (i = 0; i< j; i++)
//pDst[i]  = pSrc[i];


//Check CS
i = Eval_CS((char*)&(((RVStateLpuU3Dsc*)pv)->arUch[0]),sLV.uShIdxByte);
((TRStateLpuHSU7Dsc*)pv)-> lCs =  i;
j = sLV.uShIdxByte;
//Move Data to transmit
(((TRStateLpuHSU7Dsc*)pv)->arUch[j]) = i;
j = outU7((unsigned char *)&(((TRStateLpuHSU7Dsc*)pv)->arUch[0]),(int)j+2);

Rst_LpduHSU7_TpCnState();
}
void ProcessTransmitLpduHSU2(void)
{
register long i,j;
register char *pSrc,*pDst;
register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		unsigned short uShIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
	} sLV;
static char arCh[20] = {
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,//0x45,0x45,0x45,0x45,
0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45 //0x45,0x45,0x45,0x45,

};
 pv  = (void*)&hldrHSU2LpduTRUnit;
  pSrc = (char*)&hldrTpCnState;

j =   ((TRStateLpuHSU2Dsc*)pv)->uchLpuHSU2State ;
if (j!=0) return;
//Start for Activating of Lpdu Units 
j =  ((StateTpCnDsc*)pSrc)->uchTpState_CNL_HSU2;//
 if (j==0) return;
 
 
((TRStateLpuHSU2Dsc*)pv)->uchCI = HDR_MODE_CNL_1;//HDR_MODE_CNL_1;
((TRStateLpuHSU2Dsc*)pv)->uchLpuHSU2State = 1;


i = ((StateTpCnDsc*)pSrc)->PayloadLPDU_HSU2
+(SIZE_LDC_FLD_CNL_HSU2)+(SIZE_TOTAL_LDC);
// - ((StateTpCnDsc*)pSrc)->lCapicity_CNL_HSU7;
 sLV.ushSizeLDC = i;
 ((TRStateLpuHSU2Dsc*)pv)->lCapicity = i+(SIZE_LPCI_FLD_CNL_HSU2);//Real Size Pacet
 
//.((StateTpCnDsc*)pSrc)->lCapicity_CNL_HSU7 =((StateTpCnDsc*)pSrc)->PayloadLPDU_HSU7;

//Create Pacet
((TRStateLpuHSU2Dsc*)pv)->uchCI = (HDR_MODE_CNL_1);
((TRStateLpuHSU2Dsc*)pv)->ushSizeLDC = i;//((TRStateLpuHSU2Dsc*)pv)->lCapicity;

j = 0;
(((TRStateLpuHSU2Dsc*)pv)->arUch[0]) = ((TRStateLpuHSU2Dsc*)pv)->uchCI;
i = ((TRStateLpuHSU2Dsc*)pv)->uchCI;
i &= 0xf;
i>>=1;
switch (i)
	{
	case 0:
		j = 0;
		break;
	case 1:
		
		(((TRStateLpuHSU2Dsc*)pv)->arUch[j+1]) = ((TRStateLpuHSU2Dsc*)pv)->ushSizeLDC;
		j = 1;
		break;
	case 2:
	    pDst = (char*)&(((TRStateLpuHSU2Dsc*)pv)->arUch[j+1]);
		*((short*)pDst) = ((TRStateLpuHSU2Dsc*)pv)->ushSizeLDC;
		j = 2;
		break;
	
	default:
	j=1;
	} 


sLV.uShIdxByte = j;
///////////////////PUT TOT LDC FIELD////////////////////
pDst = (char*)&(((TRStateLpuHSU2Dsc*)pv)->arUch[j+1]);
*(pDst) = ((StateTpCnDsc*)pSrc)->chTotalLDC_CNL_HSU2;
////////////////////////////////////////////////////////
pSrc = (char*)&arCh[0];//Tempor Data !!!
pDst = (char*) &(((TRStateLpuHSU2Dsc*)pv)->arUch[j+1]);

//sLV.uShIdxByte += SIZE FIELD _TOTAL_LDC; .iNCLUDED IN ushSizeLDC

j = ((TRStateLpuHSU2Dsc*)pv)->ushSizeLDC;
sLV.uShIdxByte += sLV.ushSizeLDC;//j; 
//for (i = 0; i< j; i++)
//pDst[i]  = pSrc[i];


//Check CS
i = Eval_CS((char*)&(((RVStateLpuU3Dsc*)pv)->arUch[0]),sLV.uShIdxByte);
((TRStateLpuHSU2Dsc*)pv)-> lCs =  i;
j = sLV.uShIdxByte;
//Move Data to transmit
(((TRStateLpuHSU2Dsc*)pv)->arUch[j]) = i;
j = outU2((unsigned char *)&(((TRStateLpuHSU2Dsc*)pv)->arUch[0]),(int)j+(SIZE_CS_FLD_CNL_HSU2));

Rst_LpduHSU2_TpCnState();
}
void ProcessTransmitLpduM2m(void)  @ "Fast_function"
{
register long i,j;
register char *pSrc,*pDst;
register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		unsigned short uShIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
	} sLV;
union 
	{
		unsigned char   uchAr [4];
		unsigned short  ushAr [2];
        unsigned long   ulVal;
	}unnV1;
 pv  = (void*)&hldrM2mLpduTRUnit;
  pSrc = (char*)&hldrTpCnState;

j =   ((TRStateLpuM2mDsc*)pv)->uchLpuM2mState ;
if (j!=0) return;
//Start for Activating of Lpdu Units 
j =  ((StateTpCnDsc*)pSrc)->uchTpState_CNL_M2m;//
 if (j==0) return;
 
 
((TRStateLpuM2mDsc*)pv)->uchCI = HDR_MODE_CNL_M2M;//HDR_MODE_CNL_1;
((TRStateLpuM2mDsc*)pv)->uchLpuM2mState = 1;


i = ((StateTpCnDsc*)pSrc)->PayloadLPDU_M2m
+(SIZE_LDC_FLD_CNL_M2M)+(SIZE_TOTAL_LDC);
// - ((StateTpCnDsc*)pSrc)->lCapicity_CNL_HSU7;
 sLV.ushSizeLDC = i;
 ((TRStateLpuM2mDsc*)pv)->lCapicity = i+(SIZE_LPCI_FLD_CNL_M2M);//Real Size Pacet
 
//.((StateTpCnDsc*)pSrc)->lCapicity_CNL_HSU7 =((StateTpCnDsc*)pSrc)->PayloadLPDU_HSU7;

//Create Pacet
((TRStateLpuM2mDsc*)pv)->uchCI = (HDR_MODE_CNL_M2M);
((TRStateLpuM2mDsc*)pv)->ushSizeLDC = i;//((TRStateLpuM2mDsc*)pv)->lCapicity;

j = 0;
(((TRStateLpuM2mDsc*)pv)->arUch[0]) = ((TRStateLpuM2mDsc*)pv)->uchCI;
i = ((TRStateLpuM2mDsc*)pv)->uchCI;
i &= 0xf;
i>>=1;
switch (i)
	{
	case 0:
		j = 0;
		break;
	case 1:
		
		(((TRStateLpuM2mDsc*)pv)->arUch[j+1]) = ((TRStateLpuM2mDsc*)pv)->ushSizeLDC;
		j = 1;
		break;
	case 2:
	    pDst = (char*)&(((TRStateLpuM2mDsc*)pv)->arUch[j+1]);
		unnV1.ushAr[0] = ((TRStateLpuM2mDsc*)pv)->ushSizeLDC;
		//*((short*)pDst) = 
		pDst[0] = unnV1.uchAr[0];
		pDst[1] = unnV1.uchAr[1];
		j = 2;
		break;
	
	default:
	j=1;
	} 


sLV.uShIdxByte = j;
///////////////////PUT TOT LDC FIELD////////////////////
pDst = (char*)&(((TRStateLpuM2mDsc*)pv)->arUch[j+1]);
*(pDst) = ((StateTpCnDsc*)pSrc)->chTotalLDC_CNL_M2m;
////////////////////////////////////////////////////////
//....pSrc = (char*)&arCh[0];//Tempor Data !!!
pDst = (char*) &(((TRStateLpuM2mDsc*)pv)->arUch[j+1]);

//sLV.uShIdxByte += SIZE FIELD _TOTAL_LDC; .iNCLUDED IN ushSizeLDC

j = ((TRStateLpuM2mDsc*)pv)->ushSizeLDC;
sLV.uShIdxByte += sLV.ushSizeLDC;//j; 
//for (i = 0; i< j; i++)
//pDst[i]  = pSrc[i];


//Check CS
i = Eval_CS((char*)&(((RVStateLpuU3Dsc*)pv)->arUch[0]),((TRStateLpuM2mDsc*)pv)->lCapicity);
((TRStateLpuM2mDsc*)pv)-> lCs =  i;
j = sLV.uShIdxByte;
j = ((TRStateLpuM2mDsc*)pv)->lCapicity;
//Move Data to transmit
(((TRStateLpuM2mDsc*)pv)->arUch[j]) = i;
//j = outCY7((unsigned char *)&(((TRStateLpuM2mDsc*)pv)->arUch[0]),(int)j+(SIZE_CS_FLD_CNL_M2M));
//hldrM2mLpduTRUnit.uchLpuM2mState = 0;
Rst_LpduM2m_TpCnState();
}

static char chMakeSpiExch = 0; long lTmrEnblTrSpi = 0; long lCtrSuccExch = 0;
void Rst_LpduSpi_TpCnState(void)
{
//.hldrHSU7LpduTRUnit <- Insert Setup In Pararm
//.hldrTpCnState      <- Insert Setup In Pararm
//---Update this var after the end of transmition+ timeOut 
hldrTpCnState.uchTpState_CNL_Spi  = 0;
//----------------------------------------------------------
hldrTpCnState.PayloadLPDU_Spi     = //SIZE_LPDU_CNL_HSU7
0;//(SIZE_LPCI_FLD_CNL_HSU7+SIZE_LDC_FLD_CNL_HSU7);
hldrTpCnState.lCapicity_CNL_Spi   = SIZE_LPDU_CNL_SPI
-(SIZE_LPCI_FLD_CNL_SPI+SIZE_LDC_FLD_CNL_SPI+SIZE_CS_FLD_CNL_SPI+SIZE_TOTAL_LDC +SIZE_URGENT_DATA_BR_TO_BS);
hldrTpCnState.pUchLpuTR_CNL_Spi   = (unsigned char*)
&hldrSpiLpduTRUnit.arUch[SIZE_LPCI_FLD_CNL_SPI+SIZE_LDC_FLD_CNL_SPI+SIZE_TOTAL_LDC];//DemoStr;
hldrTpCnState.chTotalLDC_CNL_Spi = 0;

//---Update this var after the end of transmition+ timeOut 
//hldrHSU2LpduTRUnit.uchLpuHSU2State = 0;
//-----------------------------------------------------------
//	unsigned char      arUch[SIZE_LPDU_CNL_HSU7];//0   Data  field

	
hldrSpiLpduTRUnit.lCapicity  = 0;//
hldrSpiLpduTRUnit.uchCI      = 0;
hldrSpiLpduTRUnit.ushSizeLDC = 0;
hldrSpiLpduTRUnit.lCs        = 0;




}

extern  long lSsp0HdwState ;

void ProcessTransmitLpduSpi(void)  @ "Fast_function"
{
register long i,j;
register char *pSrc,*pDst;
register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		unsigned short uShIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
	} sLV;
union 
	{
		unsigned char   uchAr [4];
		unsigned short  ushAr [2];
        unsigned long   ulVal;
	}unnV1;
 pv  = (void*)&hldrSpiLpduTRUnit;
  pSrc = (char*)&hldrTpCnState;

//Control state Connect   
j = lSsp0HdwState & 4;  //
if (j == 0) 
return;
  
j =   ((TRStateLpuSpiDsc*)pv)->uchLpuSpiState ;
if (j!=0) return;
//Start for Activating of Lpdu Units 
j =  ((StateTpCnDsc*)pSrc)->uchTpState_CNL_Spi;//
 if (j==0) return;

if (chMakeSpiExch)
 return;

	if (lTmrEnblTrSpi)
	{
		lTmrEnblTrSpi--;
		return;
	}
	else
	{
		
		lTmrEnblTrSpi = 3;//0x11;//0x80;//0x100;

	}
  
((TRStateLpuSpiDsc*)pv)->uchCI = HDR_MODE_CNL_SPI;//HDR_MODE_CNL_1;
((TRStateLpuSpiDsc*)pv)->uchLpuSpiState = 1;


i = ((StateTpCnDsc*)pSrc)->PayloadLPDU_Spi
+(SIZE_LDC_FLD_CNL_SPI)+(SIZE_TOTAL_LDC);
unnV1.ushAr[1] = i + (SIZE_LPCI_FLD_CNL_SPI);//Offset Urgent Data
i +=(SIZE_URGENT_DATA_BR_TO_BS);
// - ((StateTpCnDsc*)pSrc)->lCapicity_CNL_HSU7;
 sLV.ushSizeLDC = i;
 ((TRStateLpuSpiDsc*)pv)->lCapicity = i+(SIZE_LPCI_FLD_CNL_SPI);//Real Size Pacet
 
//.((StateTpCnDsc*)pSrc)->lCapicity_CNL_HSU7 =((StateTpCnDsc*)pSrc)->PayloadLPDU_HSU7;

//Create Pacet
((TRStateLpuSpiDsc*)pv)->uchCI = (HDR_MODE_CNL_SPI);
((TRStateLpuSpiDsc*)pv)->ushSizeLDC = i;//((TRStateLpuSpiDsc*)pv)->lCapicity;

j = 0;
(((TRStateLpuSpiDsc*)pv)->arUch[0]) = ((TRStateLpuSpiDsc*)pv)->uchCI;
i = ((TRStateLpuSpiDsc*)pv)->uchCI;
i &= 0xf;
i>>=1;
switch (i)
	{
	case 0:
		j = 0;
		break;
	case 1:
		
		(((TRStateLpuSpiDsc*)pv)->arUch[j+1]) = ((TRStateLpuSpiDsc*)pv)->ushSizeLDC;
		j = 1;
		break;
	case 2:
	    pDst = (char*)&(((TRStateLpuSpiDsc*)pv)->arUch[j+1]);
		unnV1.ushAr[0] = ((TRStateLpuSpiDsc*)pv)->ushSizeLDC;
		//*((short*)pDst) = 
		pDst[0] = unnV1.uchAr[0];
		pDst[1] = unnV1.uchAr[1];
		j = 2;
		break;
	
	default:
	j=1;
	} 


sLV.uShIdxByte = j;
///////////////////PUT TOT LDC FIELD////////////////////
pDst = (char*)&(((TRStateLpuSpiDsc*)pv)->arUch[j+1]);
*(pDst) = ((StateTpCnDsc*)pSrc)->chTotalLDC_CNL_Spi;
////////////////////////////////////////////////////////
//....pSrc = (char*)&arCh[0];//Tempor Data !!!
pDst = (char*) &(((TRStateLpuSpiDsc*)pv)->arUch[j+1]);

//sLV.uShIdxByte += SIZE FIELD _TOTAL_LDC; .iNCLUDED IN ushSizeLDC

j = ((TRStateLpuSpiDsc*)pv)->ushSizeLDC;
sLV.uShIdxByte += sLV.ushSizeLDC;//j; 
//for (i = 0; i< j; i++)
//pDst[i]  = pSrc[i];
pDst = (char*) &(((TRStateLpuSpiDsc*)pv)->arUch[0]);
pDst += unnV1.ushAr[1];
InsertUrgBr2Bs((void*)pDst);

//Check CS
i = Eval_CS((char*)&(((TRStateLpuSpiDsc*)pv)->arUch[0]),((TRStateLpuSpiDsc*)pv)->lCapicity);// sLV.uShIdxByte);
((TRStateLpuSpiDsc*)pv)-> lCs =  i;
j = sLV.uShIdxByte;
j = ((TRStateLpuSpiDsc*)pv)->lCapicity;
//Move Data to transmit
(((TRStateLpuSpiDsc*)pv)->arUch[j]) = i;// --- Check Sum ---
//..j = outSPI1((unsigned char *)&(((TRStateLpuSpiDsc*)pv)->arUch[0]),SIZE_LPDU_CNL_SPI);//(int)j+(SIZE_CS_FLD_CNL_SPI)
//j = outSPIDma((unsigned char *)&(((TRStateLpuSpiDsc*)pv)->arUch[0]),SIZE_LPDU_CNL_SPI);//(int)j+(SIZE_CS_FLD_CNL_SPI)
j = OutSPIDma((unsigned char *)&(((TRStateLpuSpiDsc*)pv)->arUch[0]),SIZE_LPDU_CNL_SPI);//(int)j+(SIZE_CS_FLD_CNL_SPI)

chMakeSpiExch++;
//Rst_LpduSpi_TpCnState();
}

extern char *DemoStr; 
void TestSetup_LpduHSU7_ForTransmit(void)
{
//.hldrHSU7LpduTRUnit <- Insert Setup In Pararm
//.hldrTpCnState      <- Insert Setup In Pararm
 
hldrTpCnState.uchTpState_CNL_HSU7  = 1;
hldrTpCnState.PayloadLPDU_HSU7     = SIZE_LPDU_CNL_HSU7;
hldrTpCnState.lCapicity_CNL_HSU7   = SIZE_LPDU_CNL_HSU7 - 8;//Now sizeof str
hldrTpCnState.pUchLpuTR_CNL_HSU7   = (unsigned char*)DemoStr;
hldrTpCnState.chTotalLDC_CNL_HSU7 = 0;



hldrHSU7LpduTRUnit.uchLpuHSU7State = 0;
//	unsigned char      arUch[SIZE_LPDU_CNL_HSU7];//0   Data  field

	
hldrHSU7LpduTRUnit.lCapicity  = 0;//
hldrHSU7LpduTRUnit.uchCI      = 0;
hldrHSU7LpduTRUnit.ushSizeLDC = 0;
hldrHSU7LpduTRUnit.lCs        = 0;





}
extern long hs_uart_recover(long);
extern int hs2_rxsize;
extern long hs2uartdev;
void ProcessReceiveLpduHSU2(void)
{
    register long i,j;
    register char *pDst;
    register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		char PacketGood,PacketBad;
		
		unsigned char uChIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
		
		
	} sLV;
	sLV.PacketGood = 0;sLV.PacketBad = 0;
	sLV.uChIdxByte = sLV.ushSizeLDC = 0;
 pv  = (void*)&hldrHSU2LpduUnit;//holderCn1LpduUnit;
pDst = (char*)&hldrHSU2LpduUnit.arUch[0];//( ((RVStateLpuHSU7Dsc *)pv)->arUch[0]  );
sLV.ushSizeLDC = j = hs2_rxsize; 

//i = hs_uart_recover(hs7uartdev);

if (j<SIZE_LPDU_CNL_HSU2) 
{
	sLV.uChIdxByte = inU2((unsigned char*)pDst,j);
}
else 
	{
		i = sLV.ushSizeLDC;
		
		do
		{
			i = hs2_rxsize;
			if (i > SIZE_LPDU_CNL_HSU2)
			{
				i-= SIZE_LPDU_CNL_HSU2;
				j = SIZE_LPDU_CNL_HSU2;
			}	
			else 
				j = i;
			sLV.uChIdxByte = inU2((unsigned char*)pDst,j);	
		}
		while(hs2_rxsize);
	
	}
//1<<24;


 
((RVStateLpuHSU2Dsc *)pv)->uchCI = i= pDst[0];
if (i != HDR_MODE_CNL_1)
	sLV.PacketBad++;
else
	sLV.PacketGood++;

i = pDst[1];

if (i>SIZE_LPDU_CNL_HSU2)
sLV.PacketBad++;
else
sLV.PacketGood++;

sLV.ushSizeLDC = ((RVStateLpuHSU2Dsc *)pv)->ushSizeLDC = i;
 ((RVStateLpuHSU2Dsc *)pv)->ushSizeLDC = i;
j = Eval_CS(pDst,i+(SIZE_LPCI_FLD_CNL_HSU2)); 
if (j!=pDst[i+(SIZE_LPCI_FLD_CNL_HSU2)])
{
sLV.PacketBad++;
}
else
sLV.PacketGood++;

((RVStateLpuHSU2Dsc *)pv)->lCs = j; 

if (sLV.PacketBad)
{
	((RVStateLpuHSU2Dsc *)pv)->lCapicity   = 0;
	((RVStateLpuHSU2Dsc *)pv)->uchCI       = 0;
	((RVStateLpuHSU2Dsc *)pv)->ushSizeLDC  = 0;
	((RVStateLpuHSU2Dsc *)pv)->lCs         = 0;
	
	((RVStateLpuHSU2Dsc *)pv)->uchLpuHSU2State = 0;
	return;
}
if (sLV.PacketGood)
{
	((RVStateLpuHSU2Dsc *)pv)->lCapicity   = 0;
	((RVStateLpuHSU2Dsc *)pv)->uchCI       = 0;
	((RVStateLpuHSU2Dsc *)pv)->ushSizeLDC  = 0;
	((RVStateLpuHSU2Dsc *)pv)->lCs         = 0;	
;//Ativate Next Leyer
	((RVStateLpuHSU2Dsc *)pv)->uchLpuHSU2State = 1;
//...Now Use as Channel Identification	
	//((RVStateLpuHSU7Dsc *)pv)->uchCI       = ID_CNL_HSU7;

}


}
void Rst_LpduHSU7_TpCnState(void)
{
//.hldrHSU7LpduTRUnit <- Insert Setup In Pararm
//.hldrTpCnState      <- Insert Setup In Pararm
 
hldrTpCnState.uchTpState_CNL_HSU7  = 1;
hldrTpCnState.PayloadLPDU_HSU7     = //SIZE_LPDU_CNL_HSU7
0;//(SIZE_LPCI_FLD_CNL_HSU7+SIZE_LDC_FLD_CNL_HSU7);
hldrTpCnState.lCapicity_CNL_HSU7   = SIZE_LPDU_CNL_HSU7// - 8;//Now sizeof str
-(SIZE_LPCI_FLD_CNL_HSU7+SIZE_LDC_FLD_CNL_HSU7+SIZE_CS_FLD_CNL_HSU7+SIZE_TOTAL_LDC );
hldrTpCnState.pUchLpuTR_CNL_HSU7   = (unsigned char*)
&hldrHSU7LpduTRUnit.arUch[SIZE_LPCI_FLD_CNL_HSU7+SIZE_LDC_FLD_CNL_HSU7+SIZE_TOTAL_LDC];//DemoStr;
hldrTpCnState.chTotalLDC_CNL_HSU7 = 0;


hldrHSU7LpduTRUnit.uchLpuHSU7State = 0;
//	unsigned char      arUch[SIZE_LPDU_CNL_HSU7];//0   Data  field

	
hldrHSU7LpduTRUnit.lCapicity  = 0;//
hldrHSU7LpduTRUnit.uchCI      = 0;
hldrHSU7LpduTRUnit.ushSizeLDC = 0;
hldrHSU7LpduTRUnit.lCs        = 0;




}
void Rst_LpduHSU2_TpCnState(void)
{
//.hldrHSU7LpduTRUnit <- Insert Setup In Pararm
//.hldrTpCnState      <- Insert Setup In Pararm
//---Update this var after the end of transmition+ timeOut 
hldrTpCnState.uchTpState_CNL_HSU2  = 0;
//----------------------------------------------------------
hldrTpCnState.PayloadLPDU_HSU2     = //SIZE_LPDU_CNL_HSU7
0;//(SIZE_LPCI_FLD_CNL_HSU7+SIZE_LDC_FLD_CNL_HSU7);
hldrTpCnState.lCapicity_CNL_HSU2   = SIZE_LPDU_CNL_HSU2// - 8;//Now sizeof str
-(SIZE_LPCI_FLD_CNL_HSU2+SIZE_LDC_FLD_CNL_HSU2+SIZE_CS_FLD_CNL_HSU2+SIZE_TOTAL_LDC );
hldrTpCnState.pUchLpuTR_CNL_HSU2   = (unsigned char*)
&hldrHSU2LpduTRUnit.arUch[SIZE_LPCI_FLD_CNL_HSU2+SIZE_LDC_FLD_CNL_HSU2+SIZE_TOTAL_LDC];//DemoStr;
hldrTpCnState.chTotalLDC_CNL_HSU2 = 0;

//---Update this var after the end of transmition+ timeOut 
//hldrHSU2LpduTRUnit.uchLpuHSU2State = 0;
//-----------------------------------------------------------
//	unsigned char      arUch[SIZE_LPDU_CNL_HSU7];//0   Data  field

	
hldrHSU2LpduTRUnit.lCapicity  = 0;//
hldrHSU2LpduTRUnit.uchCI      = 0;
hldrHSU2LpduTRUnit.ushSizeLDC = 0;
hldrHSU2LpduTRUnit.lCs        = 0;




}

void Rst_LpduM2m_TpCnState(void)  @ "Fast_function"
{
//.hldrHSU7LpduTRUnit <- Insert Setup In Pararm
//.hldrTpCnState      <- Insert Setup In Pararm
//---Update this var after the end of transmition+ timeOut 
hldrTpCnState.uchTpState_CNL_M2m  = 0;
//----------------------------------------------------------
hldrTpCnState.PayloadLPDU_M2m     = //SIZE_LPDU_CNL_HSU7
0;//(SIZE_LPCI_FLD_CNL_HSU7+SIZE_LDC_FLD_CNL_HSU7);
hldrTpCnState.lCapicity_CNL_M2m   = SIZE_LPDU_CNL_M2M
-(SIZE_LPCI_FLD_CNL_M2M+SIZE_LDC_FLD_CNL_M2M+SIZE_CS_FLD_CNL_M2M+SIZE_TOTAL_LDC );
hldrTpCnState.pUchLpuTR_CNL_M2m   = (unsigned char*)
&hldrM2mLpduTRUnit.arUch[SIZE_LPCI_FLD_CNL_M2M+SIZE_LDC_FLD_CNL_M2M+SIZE_TOTAL_LDC];//DemoStr;
hldrTpCnState.chTotalLDC_CNL_M2m = 0;

//---Update this var after the end of transmition+ timeOut 
//hldrHSU2LpduTRUnit.uchLpuHSU2State = 0;
//-----------------------------------------------------------
//	unsigned char      arUch[SIZE_LPDU_CNL_HSU7];//0   Data  field

	
//hldrM2mLpduTRUnit.lCapicity  = 0;//
hldrM2mLpduTRUnit.uchCI      = 0;
hldrM2mLpduTRUnit.ushSizeLDC = 0;
hldrM2mLpduTRUnit.lCs        = 0;




}
extern long Cy7_rxsize;
void ProcessReceiveLpduCY7(void)  @ "Fast_function"
{
    register long i,j;
    register char *pDst;
    register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		char PacketGood,PacketBad;
		
		unsigned char uChIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
		
	} sLV;
	sLV.PacketGood = 0;sLV.PacketBad = 0;
	sLV.uChIdxByte = sLV.ushSizeLDC = 0;
 pv  = (void*)&hldrM2mLpduUnit;//hldrHSU2LpduUnit;//
pDst = (char*)&hldrM2mLpduUnit.arUch[0];//
sLV.ushSizeLDC = j = Cy7_rxsize; 

if (j<SIZE_LPDU_CNL_M2M) 
{
	sLV.uChIdxByte = inCY7((unsigned char*)pDst,j);
}
else 
	{
		i = sLV.ushSizeLDC;
		
		do
		{
			i = Cy7_rxsize;
			if (i > SIZE_LPDU_CNL_M2M)
			{
				i-= SIZE_LPDU_CNL_M2M;
				j = SIZE_LPDU_CNL_M2M;
			}	
			else 
				j = i;
			sLV.uChIdxByte = inCY7((unsigned char*)pDst,j);	
		}
		while(Cy7_rxsize);
	
	} 
 
 
((RVStateLpuM2mDsc *)pv)->uchCI = i= pDst[0];
if (i != HDR_MODE_CNL_M2M)
	sLV.PacketBad++;
else
	sLV.PacketGood++;

i = pDst[2];
i <<= 8;
i|= pDst[1];

if (i>SIZE_LPDU_CNL_M2M)
sLV.PacketBad++;
else
sLV.PacketGood++;

sLV.ushSizeLDC = ((RVStateLpuM2mDsc *)pv)->ushSizeLDC = i;
// ((RVStateLpuHSU2Dsc *)pv)->ushSizeLDC = i;
j = Eval_CS(pDst,i+(SIZE_LPCI_FLD_CNL_M2M)); 
if (j!=pDst[i+(SIZE_LPCI_FLD_CNL_M2M)])
{
sLV.PacketBad++;
}
else
sLV.PacketGood++;

((RVStateLpuM2mDsc *)pv)->lCs = j; 

if (sLV.PacketBad)
{
	((RVStateLpuM2mDsc *)pv)->lCapicity   = 0;
	((RVStateLpuM2mDsc *)pv)->uchCI       = 0;
	((RVStateLpuM2mDsc *)pv)->ushSizeLDC  = 0;
	((RVStateLpuM2mDsc *)pv)->lCs         = 0;
	
	((RVStateLpuM2mDsc *)pv)->uchLpuM2mState = 0;
	return;
}
if (sLV.PacketGood)
{
	((RVStateLpuM2mDsc *)pv)->lCapicity   = 0;
	((RVStateLpuM2mDsc *)pv)->uchCI       = 0;
	((RVStateLpuM2mDsc *)pv)->ushSizeLDC  = 0;
	((RVStateLpuM2mDsc *)pv)->lCs         = 0;	
;//Ativate Next Leyer
	((RVStateLpuM2mDsc *)pv)->uchLpuM2mState = 1;
//...Now Use as Channel Identification	
	//((RVStateLpuHSU7Dsc *)pv)->uchCI       = ID_CNL_HSU7;

}







}

unsigned long uiAmtSpiGoodRvPacket = 0; 
unsigned long uiAmtSpiBadRvPacket = 0;
extern  long lSsp0HdwState ;
static char chTotalBadPacketCtr = 0;
extern volatile  int  spi1_rxsize;//spi1_txsize,
void ProcessReceiveLpduSpi(void)  @ "Fast_function"
{
    register long i,j;
    register char *pDst;
    register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		char PacketGood,PacketBad;
		
		unsigned short ushIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
		
	} sLV;
	sLV.PacketGood = 0;sLV.PacketBad = 0;
	sLV.ushIdxByte = sLV.ushSizeLDC = 0;
 pv  = (void*)&hldrSpiLpduUnit;//hldrHSU2LpduUnit;//
pDst = (char*)&hldrSpiLpduUnit.arUch[0];//
sLV.ushSizeLDC = j = spi1_rxsize;//Cy7_rxsize; SIZE_LPDU_CNL_SPI

if (j<SIZE_LPDU_CNL_SPI) 
{
	sLV.ushIdxByte = InSPIDma((unsigned char*)pDst,j);//inSPI1((unsigned char*)pDst,j);
}
else 
	{
		i = sLV.ushSizeLDC;
		
		do
		{
			i = spi1_rxsize;//Cy7_rxsize;
			if (i > SIZE_LPDU_CNL_SPI)
			{
				i-= SIZE_LPDU_CNL_SPI;
				j = SIZE_LPDU_CNL_SPI;
			}	
			else 
				j = i;
			sLV.ushIdxByte = InSPIDma((unsigned char*)pDst,j);//inSPI1((unsigned char*)pDst,j);	
		}
		while(spi1_rxsize);//Total erroneus algorithm for hundling SPI data
	
	} 
 
 
((RVStateLpuSpiDsc *)pv)->uchCI = i= pDst[0];
if (i != HDR_MODE_CNL_SPI)
	sLV.PacketBad++;
else
	sLV.PacketGood++;

i = pDst[2];
i <<= 8;
i|= pDst[1];

if (i>SIZE_LPDU_CNL_SPI)
sLV.PacketBad++;
else
sLV.PacketGood++;

sLV.ushSizeLDC = ((RVStateLpuSpiDsc *)pv)->ushSizeLDC = i;
// ((RVStateLpuHSU2Dsc *)pv)->ushSizeLDC = i;
j = Eval_CS(pDst,i+(SIZE_LPCI_FLD_CNL_SPI)); 
if (j!=pDst[i+(SIZE_LPCI_FLD_CNL_SPI)])
{
sLV.PacketBad++;
}
else
sLV.PacketGood++;

((RVStateLpuSpiDsc *)pv)->lCs = j; 

if (sLV.PacketBad)
{
	((RVStateLpuSpiDsc *)pv)->lCapicity   = 0;
	((RVStateLpuSpiDsc *)pv)->uchCI       = 0;
	((RVStateLpuSpiDsc *)pv)->ushSizeLDC  = 0;
	((RVStateLpuSpiDsc *)pv)->lCs         = 0;
	
	uiAmtSpiBadRvPacket++;
	((RVStateLpuSpiDsc *)pv)->uchLpuSpiState = 0;
	if(sLV.PacketBad >= 2)//Need Use 2 not 3
	chTotalBadPacketCtr++;
	if (chTotalBadPacketCtr > 3)//..if (chTotalBadPacketCtr > 203)
	{
		//ReInit Spi Channel
		chTotalBadPacketCtr = 0;//~..lSsp0HdwState = 0;Spi0_Rst();
		lTmrEnblTrSpi = 22;//Make Pause For Resyncro
		uiAmtSpiGoodRvPacket = uiAmtSpiBadRvPacket = 0;
		//sLV.PacketGood = 0;
		//while(sLV.ushIdxByte)
		//{
		//	sLV.PacketGood = 50;
		//	while(sLV.PacketGood--);
		//	sLV.ushIdxByte--;
		//}
	}
	
	goto ExitProcessReceiveLpduSpi;//return;
}
if (sLV.PacketGood)
{
	((RVStateLpuSpiDsc *)pv)->lCapicity   = 0;
	((RVStateLpuSpiDsc *)pv)->uchCI       = 0;
	((RVStateLpuSpiDsc *)pv)->ushSizeLDC  = 0;
	((RVStateLpuSpiDsc *)pv)->lCs         = 0;	
;//Ativate Next Leyer
	((RVStateLpuSpiDsc *)pv)->uchLpuSpiState = 1;
//...Now Use as Channel Identification	
	//((RVStateLpuHSU7Dsc *)pv)->uchCI       = ID_CNL_HSU7;
	chTotalBadPacketCtr = 0;
	
	if (lCtrSuccExch < 0xf00000)
	lCtrSuccExch++;
	else
	lCtrSuccExch--;
	
	uiAmtSpiGoodRvPacket++;


}
ExitProcessReceiveLpduSpi:
	if (chMakeSpiExch)
	{
		chMakeSpiExch = 0;
		Rst_LpduSpi_TpCnState();
		GPIO->p3_outp_clr = ((1<<7));GPIO->p3_outp_clr = (1<<23);
		//Control HandShaking State
		if( (GPIO->p3_inp_state) & (1<<16))
		;
		else
		;
		if( (GPIO->p3_inp_state) & (1<<17))
		;
		else
		;
		
		
	}


}

extern  long lSsp0HdwState ;

void ProcessTransmitStubSeqSpi(void)  @ "Fast_function"
{
register long i,j;
register char *pSrc,*pDst;
register void* pv;
//.struct 
//.	{
//.		//unsigned char uchTR_C;
//.		unsigned short uShIdxByte ;
//.		unsigned short ushSizeLDC;
//.		//unsigned char *pUchRV;
//.	} sLV;
union 
	{
		unsigned char   uchAr [4];
		unsigned short  ushAr [2];
        unsigned long   ulVal;
	}unnV1;
//Control state Connect   
j = lSsp0HdwState & 4;  //
if (j == 0) 
return;
 pv  = (void*)&hldrSpiLpduTRUnit;
  pSrc = (char*)&hldrTpCnState;
//Start for Activating of Lpdu Units 
j =  ((StateTpCnDsc*)pSrc)->uchTpState_CNL_Spi;//
 if (j!=0)
 return;

j =   ((TRStateLpuSpiDsc*)pv)->uchLpuSpiState ;
if (j!=0)
 return;//Transmittion Active

if (chMakeSpiExch)
 return;

	if (lTmrEnblTrSpi)
	{
		lTmrEnblTrSpi--;
		return;
	}
	else
	{
		
		lTmrEnblTrSpi = 3;//0x12;//0x80;//0x100;

	}
 
((TRStateLpuSpiDsc*)pv)->uchCI = HDR_MODE_CNL_SPI;//HDR_MODE_CNL_1;
((TRStateLpuSpiDsc*)pv)->uchLpuSpiState = 1;


i = 0//((StateTpCnDsc*)pSrc)->PayloadLPDU_Spi
+(SIZE_LDC_FLD_CNL_SPI)+(SIZE_TOTAL_LDC)+(SIZE_URGENT_DATA_BR_TO_BS);
// 
//. sLV.ushSizeLDC = i;
 ((TRStateLpuSpiDsc*)pv)->lCapicity = i+(SIZE_LPCI_FLD_CNL_SPI);//Real Size Pacet
 


//Create Pacet
((TRStateLpuSpiDsc*)pv)->uchCI = (HDR_MODE_CNL_SPI);
((TRStateLpuSpiDsc*)pv)->ushSizeLDC = i;//((TRStateLpuSpiDsc*)pv)->lCapicity;

j = 0;
(((TRStateLpuSpiDsc*)pv)->arUch[0]) = ((TRStateLpuSpiDsc*)pv)->uchCI;
i = ((TRStateLpuSpiDsc*)pv)->uchCI;
i &= 0xf;
i>>=1;
switch (i)
	{
	case 0:
		j = 0;
		break;
	case 1:
		
		(((TRStateLpuSpiDsc*)pv)->arUch[j+1]) = ((TRStateLpuSpiDsc*)pv)->ushSizeLDC;
		j = 1;
		break;
	case 2:
	    pDst = (char*)&(((TRStateLpuSpiDsc*)pv)->arUch[j+1]);
		unnV1.ushAr[0] = ((TRStateLpuSpiDsc*)pv)->ushSizeLDC;
		//*((short*)pDst) = 
		pDst[0] = unnV1.uchAr[0];
		pDst[1] = unnV1.uchAr[1];
		j = 2;
		break;
	
	default:
	j=1;
	} 
///////////////////PUT TOT LDC FIELD////////////////////
pDst = (char*)&(((TRStateLpuSpiDsc*)pv)->arUch[j+1]);
*(pDst) = 0;//((StateTpCnDsc*)pSrc)->chTotalLDC_CNL_Spi;
////////////////////////////////////////////////////////
//pDst = (char*)&(((TRStateLpuSpiDsc*)pv)->arUch[0]); <-- Test Code for Generation Num Seq in Buff
//for( i = 5; i<(510>>1); i++)
//*((short*)pDst +i) = i+213;    
	

	

//Check CS
i = Eval_CS((char*)&(((TRStateLpuSpiDsc*)pv)->arUch[0]),((TRStateLpuSpiDsc*)pv)->lCapicity);// sLV.uShIdxByte);
((TRStateLpuSpiDsc*)pv)-> lCs =  i;

j = ((TRStateLpuSpiDsc*)pv)->lCapicity;
//Move Data to transmit
(((TRStateLpuSpiDsc*)pv)->arUch[j]) = i;
//j = outSPI1((unsigned char *)&(((TRStateLpuSpiDsc*)pv)->arUch[0]),SIZE_LPDU_CNL_SPI);//(int)j+(SIZE_CS_FLD_CNL_SPI)
j = OutSPIDma((unsigned char *)&(((TRStateLpuSpiDsc*)pv)->arUch[0]),SIZE_LPDU_CNL_SPI);//(int)j+(SIZE_CS_FLD_CNL_SPI)
//j = outSPI1((unsigned char *)&(((TRStateLpuSpiDsc*)pv)->arUch[0]),SIZE_LPDU_CNL_SPI);//(int)j+(SIZE_CS_FLD_CNL_SPI)
chMakeSpiExch++;
//Rst_LpduSpi_TpCnState();
}


void ProcessReceiveLpduCY7V1(void)  @ "Fast_function"
{
    register long i,j;
    register char *pDst;
    register void* pv;
struct 
	{
		//unsigned char uchTR_C;
		char PacketGood,PacketBad;
		
		unsigned char uChIdxByte ;
		unsigned short ushSizeLDC;
		//unsigned char *pUchRV;
		
	} sLV;
	sLV.PacketGood = 0;sLV.PacketBad = 0;
	sLV.uChIdxByte = sLV.ushSizeLDC = 0;
 pv  = (void*)&hldrM2mLpduUnit;//hldrHSU2LpduUnit;//
pDst = (char*)&hldrM2mLpduUnit.arUch[0];//


 
((RVStateLpuM2mDsc *)pv)->uchCI = i= pDst[0];
if (i != HDR_MODE_CNL_M2M)
	sLV.PacketBad++;
else
	sLV.PacketGood++;

i = pDst[2];
i <<= 8;
i|= pDst[1];

if (i>SIZE_LPDU_CNL_M2M)
sLV.PacketBad++;
else
sLV.PacketGood++;

sLV.ushSizeLDC = ((RVStateLpuM2mDsc *)pv)->ushSizeLDC = i;
// ((RVStateLpuHSU2Dsc *)pv)->ushSizeLDC = i;
j = Eval_CS(pDst,i+(SIZE_LPCI_FLD_CNL_M2M)); 
if (j!=pDst[i+(SIZE_LPCI_FLD_CNL_M2M)])
{
sLV.PacketBad++;
}
else
sLV.PacketGood++;

((RVStateLpuM2mDsc *)pv)->lCs = j; 

if (sLV.PacketBad)
{
	((RVStateLpuM2mDsc *)pv)->lCapicity   = 0;
	((RVStateLpuM2mDsc *)pv)->uchCI       = 0;
	((RVStateLpuM2mDsc *)pv)->ushSizeLDC  = 0;
	((RVStateLpuM2mDsc *)pv)->lCs         = 0;
	
	((RVStateLpuM2mDsc *)pv)->uchLpuM2mState = 0;
	return;
}
if (sLV.PacketGood)
{
	((RVStateLpuM2mDsc *)pv)->lCapicity   = 0;
	((RVStateLpuM2mDsc *)pv)->uchCI       = 0;
	((RVStateLpuM2mDsc *)pv)->ushSizeLDC  = 0;
	((RVStateLpuM2mDsc *)pv)->lCs         = 0;	
;//Ativate Next Leyer
	((RVStateLpuM2mDsc *)pv)->uchLpuM2mState = 1;
//...Now Use as Channel Identification	
	//((RVStateLpuHSU7Dsc *)pv)->uchCI       = ID_CNL_HSU7;

}







}

extern long UpdateLgrBuf(void );




long lIdxBuf = 0;
long lSamplesNum = 0;
long lBackSamplesNum = 0;
char chSelectorCurrBuff = 0;//Select Active Buf


#define AMOUNT_SAMPLES_IN_BUF 50


void InsertUrgBr2Bs(void* pv)
{
register long i,j;
register char *pSrc,*pDst;
union 
	{
		unsigned char   uchAr [4];
		unsigned short  ushAr [2];
        unsigned long   ulVal;
	}unnV1;
UrgentDataBrDsc hldrTestData = {
	{
		//{
			0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,
			0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46, 
			0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46, 
			0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46, 
			0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46, 
			0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46 
		//}
		,
		//{
			0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41, 
			0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41 
		//}
		,
		//{
			1,2,3,4
		//}
	}
};

// memcpy((void*)&hldrM2mLpduUnit.arUch[0],(const void*)ADR_AR_BM,SIZE_LPDU_CNL_CY7 );//ReadData	
	// memcpy(pv,(const void*) &hldrTestData,SIZE_URGENT_DATA_BR_TO_BS);//ReadData
	 
	i = UpdateLgrBuf();
	// *
	unnV1.ulVal = ulCtrTrLpduSpi;
	pSrc = &(((UrgentDataBrDsc*)pv)->UN_UrgentDataBR.sBrWrp.chArCtrLinkTr[0]);
	
	// chArCtrLinkTr[
	 pSrc[0] = unnV1. uchAr [0];
	 pSrc[1] = unnV1. uchAr [1];
	 pSrc[2] = unnV1. uchAr [2];
	 pSrc[3] = unnV1. uchAr [3];
	//Put ArAnlg
	//^i = l_IdxAWthCmdBufGet;
	pSrc =  &hldrTestData.UN_UrgentDataBR.sBrWrp.chArAnlg[0];//^&arAnallogWthCmdBuf_L[0];
	//^pSrc += i;
	
	pDst = &(((UrgentDataBrDsc*)pv)->UN_UrgentDataBR.sBrWrp.chArAnlg[0]);
	 memcpy(pDst,(const void*) pSrc,SIZE_ANALOG_DATA);
	//Put ArCmd
	pDst = &(((UrgentDataBrDsc*)pv)->UN_UrgentDataBR.sBrWrp.chArCmd[0]);
	pSrc = &hldrTestData.UN_UrgentDataBR.sBrWrp.chArCmd[0];//+= SIZE_ANALOG_DATA;
	memcpy(pDst,(const void*) pSrc,SIZE_COMMAND_DATA);
	//Put Wrp 
	pDst = &(((UrgentDataBrDsc*)pv)->UN_UrgentDataBR.sBrWrp.chArWrp[0]);
	//pSrc += SIZE_COMMAND_DATA;
	unnV1.ulVal = l_time_lable;
	 pDst[0] = unnV1. uchAr [0];//pSrc [0];//SIZE_WRP_LOG_DATA
	 pDst[1] = unnV1. uchAr [1];//pSrc [1];
	 pDst[2] = unnV1. uchAr [2];//pSrc [2];
	 pDst[3] = unnV1. uchAr [3];//pSrc [3];
	 
	pDst = &(((UrgentDataBrDsc*)pv)->UN_UrgentDataBR.sBrWrp.chAbnNum[0]); 
	unnV1.ulVal =  l_Abs_Numerator_Br;
	 pDst[0] = unnV1. uchAr [0];//pSrc [0];//SIZE_WRP_LOG_DATA
	 pDst[1] = unnV1. uchAr [1];//pSrc [1];
	 pDst[2] = unnV1. uchAr [2];//pSrc [2];
	 pDst[3] = unnV1. uchAr [3];//pSrc [3];
	// * /
}


//////////////////////////////////////////////////////////////////////////////////////////
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---
extern long UpdateLgrBuf(void );
                                        //unsigned short* p_out_param);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~     функция обоновления данных объединенного регистратора                ~~~~~
//~~~                                                                          ~~~~~
//~~~     возврат 3 - команда выполнена успешно                                ~~~~~
//~~~     возврат 4 - возникла  ошибка                                         ~~~~~
//~~~     6-32 24*8   -192 bita                                               ~~~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~   p_in_param должен указывать на область памяти команд 24  байта         ~~~~~
//~~~    //значения младших бит должны располагаться по мл. адресам памяти     ~~~~~
//~~~       p_in_param+0 -> 0-7;                                               ~~~~~
//~~~   	p_in_param+1 -> 8-15;                                              ~~~~~
/*
//Fragment Logger Function
#ifndef SIZE_ANALOG_DATA
#define SIZE_ANALOG_DATA    0x1

#ifndef SIZE_COMMAND_DATA
#define SIZE_COMMAND_DATA   0x1
*/
#define AMOUNT_RECORDS_ANALOG_WITH_CMD 10
long l_Abs_Numerator_Br = 0;
long l_IdxAWthCmdBufGet = 0;
long l_time_lable = 0;
long l_IdxAWthCmdBuf = 0;
long  arAnallogWthCmdBuf_L[((SIZE_ANALOG_DATA + SIZE_COMMAND_DATA)*(AMOUNT_RECORDS_ANALOG_WITH_CMD))];

long UpdateLgrBuf(void )
{
struct 
	{
		//short         shCountCmd;  
		unsigned char uChIdxByte ;
		unsigned char uChIdxBit ;
		//-short shVal;
		unsigned short ushBeg,ushEnd;
		
	} sLV;
union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;
		
	l_IdxAWthCmdBufGet = l_IdxAWthCmdBuf;//Fill
/*		  
GetAnalogDataState((arAnallogWthCmdBuf_L +  l_IdxAWthCmdBuf));
  l_IdxAWthCmdBuf += SIZE_ANALOG_DATA;
GetCmdState ((arAnallogWthCmdBuf_L +  l_IdxAWthCmdBuf));  
  l_IdxAWthCmdBuf += SIZE_COMMAND_DATA;
  arAnallogWthCmdBuf_L[l_IdxAWthCmdBuf++] = l_time_lable;
  
*/
  
  if (l_IdxAWthCmdBuf >= ((SIZE_ANALOG_DATA + SIZE_COMMAND_DATA)*(AMOUNT_RECORDS_ANALOG_WITH_CMD)) )
  l_IdxAWthCmdBuf = 0;
  
  if(l_time_lable < 0x7fffffff) l_time_lable++;
  else 
	l_time_lable = 0;
  if(l_Abs_Numerator_Br < 0x7fffffff) l_Abs_Numerator_Br++;
  else 
	l_Abs_Numerator_Br = 0;

	return 0;
}
//-----------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
short shCtrTrLpduSpiTeleMechs = 0;



#include    "Tlmc.h"
#include    "var_r_apcs_ici.h"
//////////////////////////////////////////////////////////////////////////////////////////
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---
extern void ProcessLLEvt (void);
                                        
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~                 ~~~~~
//~~~                ~~~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~      ~~~~~
//~~~      ~~~~~

void ProcessLLEvt (void)
{
	register long lrVar;

	//if( IciCopy_ulCtrTrLpduSpi!=ulCtrTrLpduSpi )
	{
	
	
		//Timer for Activate Telemechs
		lrVar = shCtrTrLpduSpiTeleMechs;//*( (U8*)(pU8+OFF_BYTE_10_MS_CNTR ));
		lrVar++;
	
		if ( (lrVar) >= 5 )//5
		{
			shCtrTrLpduSpiTeleMechs = 0;//*( (U8*)(pU8+OFF_BYTE_10_MS_CNTR )) = 0;
			if((AppReqTransmitTeleMechs == 0) || (AppReqTransmitTeleMechs >= TERM) )
			AppReqTransmitTeleMechs = START;//Process 5  LL Events();
			//Get TeleDataFrom APCS
			GetInState    (&(holderTeleMechs.UNTeleMechs.sBrTeleMechsTeleInfoWrp.chArIn    [0]) );
			GetOutState   (&(holderTeleMechs.UNTeleMechs.sBrTeleMechsTeleInfoWrp.chArOut   [0]) );
			GetTrgOutState(&(holderTeleMechs.UNTeleMechs.sBrTeleMechsTeleInfoWrp.chArOutTrg[0]) );
			GetLedState   (&(holderTeleMechs.UNTeleMechs.sBrTeleMechsTeleInfoWrp.chArLed   [0]) );
			GetTrgLedState(&(holderTeleMechs.UNTeleMechs.sBrTeleMechsTeleInfoWrp.chArLedTrg[0]) );
			//^^holderTeleMechs.UNTeleMechs.sBrTeleMechsTeleInfoWrp.chArIn    [0] = 0x1;
			//^^holderTeleMechs.UNTeleMechs.sBrTeleMechsTeleInfoWrp.chArOut   [0] = 0x2;
			//^^holderTeleMechs.UNTeleMechs.sBrTeleMechsTeleInfoWrp.chArOutTrg[0] = 0x3;
			//^^holderTeleMechs.UNTeleMechs.sBrTeleMechsTeleInfoWrp.chArLed   [0] = 0x4;
			//^^holderTeleMechs.UNTeleMechs.sBrTeleMechsTeleInfoWrp.chArLedTrg[0] = 0x5;
			
			
		}
		else
			shCtrTrLpduSpiTeleMechs = lrVar;//*( (U8*)(pU8+OFF_BYTE_10_MS_CNTR ))= lrVar;
			
			
			
	}
	
//



}

//-----------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""













/* EOF */

