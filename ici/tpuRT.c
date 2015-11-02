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
* File Name       : tpuRT.c
* Description     : Functions and Data for Extract from Transport to Applicayion
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  03/10/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/


void* GetAddrObj(long IdObj)
{
register void* pv;

pv = (void*)0;

switch (IdObj)
	{
	case ID_SRC_SAMPLES_UNIT:
		pv  = &holderRVSrcSamplesCTpuUnit;
		break;
	case ID_SRC_APCS_UNIT:
		
		pv  = (void*)0;
		
		break;
	case ID_SRC_TEST1_UNIT:
	    
		pv  = (void*)0;
		
		break;
	case ID_TEN_PERIOD_SAMPLES_UNIT:
	    
		pv  = (void*)0;
		
		break;
	
	default:
	pv = (void*)0;
	}



	return pv;
}

long UpdateRVSrcSamplesCTpuUnit(void* pvLDC, long lID)
{
register long i;//,j;
//register char *pSrc;//,*pDst;
void* pv;
struct 
	{
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


unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
unnV1.uchAr[3] = 0;

pv = (void*)&holderRVSrcSamplesCTpuUnit.arUchRV[0];
//((RVSrcSamplesCTpuUnitDsc*)pv )->
i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
 lID = ((LDCIDsc*)pvLDC)->uchTR_C;
 pvLDC = (void*)i;
  
 
  for (i = 0; i < lID; i++)
  {
    ((char*)pv)[i] = ((char*)pvLDC)[i];
  }
  unnV1.uchAr[3] = lID;//Save amount Extract Data
  //Activate App For
  TestReqReceiveT1++;
  //Clear All Ses Data
  i = 0;
  holderRVSrcSamplesCTpuUnit.RvCnHldr.uchUsedTransport = 0;
  holderRVSrcSamplesCTpuUnit.RvCnHldr.NumComSes        = 0;
  holderRVSrcSamplesCTpuUnit.RvCnHldr.ConState         = 0;
  holderRVSrcSamplesCTpuUnit.RvCnHldr.ulRvCount        = 0;
  //Indicator data Transmit to Application
  //holderRVSrcSamplesCTpuUnit. TrCnHldr.pUchRV           = 0;
return lID;//unnV1.uchAr[3];
}
extern long ActivateRVProxyTenPerSamplesCTpuUnit(void* pvLDC, long lID);
extern long UpdateRVTotMeasRCTpuUnit(void* pvLDC, long lID);
extern long UpdateRVPrTptPrtTbl(void* pvLDC, long lID);
extern long PassPrtTblPrMngRvMsg(void* pvLDC, long lID);
extern long UpdateRVTotFCoilTpuUnit(void* pvLDC, long lID);
extern long UpdateRVTotDateTimeTpuUnit(void* pvLDC, long lID);
extern long UpdateRVTotAtrCmdTpuUnit(void* pvLDC, long lID);
extern long UpdateRVDiagnBrBmTpuUnit(void* pvLDC, long lID);
extern long UpdateRVDiagnBrBsTpuUnit(void* pvLDC, long lID);
extern long UpdateRVAbnNumBrBsTpuUnit(void* pvLDC, long lID);



extern long UpdateRVGoosACTpuUnit(void* pvLDC, long lID);
extern long UpdateRVGoosBCTpuUnit(void* pvLDC, long lID);

void* GetAddrPFL_VL(long IdObj)  @ "Fast_function"
{
//register void* pv;
register PFL_VL pfl_vl;
//pfl_vl = (void*)0;

switch (IdObj)
	{
	case ID_SRC_SAMPLES_UNIT:
		pfl_vl  = UpdateRVSrcSamplesCTpuUnit;
		break;
	case ID_SRC_APCS_UNIT:
		
		//pfl_vl  = (void*)0;
		
		break;
	case ID_SRC_TEST1_UNIT:
	    
		//pfl_vl  = (void*)0;
		
		break;
	case ID_TEN_PERIOD_SAMPLES_UNIT:
	    
		pfl_vl  = ActivateRVProxyTenPerSamplesCTpuUnit;//(void*)0;
		
		break;
	case ID_TOTAL_MEAS_UNIT:
	    
		pfl_vl  = ActivateRVProxyTotMeasCTpuUnit;//(void*)0;
		
		break;
	case ID_TOTAL_MEASR_UNIT:
	    
		pfl_vl  = UpdateRVTotMeasRCTpuUnit;//(void*)0;
		
		break;
		case ID_APCS_UNIT:
	    
		pfl_vl  = (void*)0;//UpdateRVApcsCTpuUnit;//
		
		break;	
		case ID_PRT_PR_MNG:
	    
		pfl_vl  = PassPrtTblPrMngRvMsg;//(void*)0;
		
		break;
	   case ID_PRT_PR_TRANSPORT:
	    
		pfl_vl  = UpdateRVPrTptPrtTbl;//(void*)0;
		
		break;
	   case ID_GOOS_A_UNIT:
	    pfl_vl  = UpdateRVGoosACTpuUnit;//(void*)0;
		
		break;
		case ID_GOOS_B_UNIT:
	    pfl_vl  = UpdateRVGoosBCTpuUnit;//(void*)0;
		
		break;
		case ID_FCOIL_UNIT:
	    pfl_vl  = UpdateRVTotFCoilTpuUnit;//(void*)0;
		
		break;
		case ID_DATE_TIME_UNIT:
	    pfl_vl  = UpdateRVTotDateTimeTpuUnit;//(void*)0;
		
		break;
		case ID_ATR_CMD_UNIT:
	    pfl_vl  = UpdateRVTotAtrCmdTpuUnit;//(void*)0;
		
		break;
	

	
	default:
	pfl_vl = (void*)0;
	}



	return (void*)pfl_vl;
}

long SetFld_TpState_CNL(long lID_Cnl,void* pvStateTpCnDsc,long lV)  @ "Fast_function"
{
switch (lID_Cnl)
	{
	case ID_CNL_TEST1:
		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_1 =   lV;
		break;
	case ID_CNL_HSU7:
		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_HSU7 = lV;
		break;
 	case ID_CNL_HSU2:
 		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_HSU2 = lV;
 		break;
 	case ID_CNL_SPI:
 		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_Spi  = lV;
 		break;
 	case ID_CNL_M2M:
 		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_M2m = lV;
 		break;
		
		

//.	case 6:
//.	
//.		break;
	default:
	lID_Cnl =0;
	}	
return lID_Cnl;
}
long GetFld_TpState_CNL(long lID_Cnl)  @ "Fast_function"
{
register long i;
register void *pv;
pv = (void*)&hldrTpCnState;//StateTpCnDsc
switch (lID_Cnl)
	{
	case ID_CNL_TEST1:
		i = ((StateTpCnDsc*)pv)-> uchTpState_CNL_1;
		break;
	case ID_CNL_HSU7:
		i = ((StateTpCnDsc*)pv)-> uchTpState_CNL_HSU7;
		break;
 	case ID_CNL_HSU2:
 		i = ((StateTpCnDsc*)pv)-> uchTpState_CNL_HSU2;
 		break;
 	case ID_CNL_M2M:
 		i = ((StateTpCnDsc*)pv)-> uchTpState_CNL_M2m;;
 		break;
 	case ID_CNL_SPI:
 		i = ((StateTpCnDsc*)pv)-> uchTpState_CNL_Spi;
 		break;
		
		

//.	case 6:
//.	
//.		break;
	default:
	i = lID_Cnl =0;
	}	
return i;
}

