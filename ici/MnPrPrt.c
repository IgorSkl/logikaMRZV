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
* File Name       : MnPrPrt.c
* Description     : Functions and Data for Manage All operations with Settings
                    BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  04/01/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#include    "MnPrPrt.h"


//  CmmMsgDsc hldCmmMsg;
//  char chUsehldCmmMsgRV = 0;
//  CmmMsgDsc hldCmmMsgRV,hldCmmMsgTR;






char chUsehldPrtTblCmmMsgRV = 0;

CmmMsgDsc hldPrtTblCmmMsgRV,hldPrtTblCmmMsgTR;






extern char chStateArPrtTblData ;
extern int TestReqTransmitArPrtTbl;
extern int TestReqReceiveArPrtTbl;


long lSizeOf_PrtTbl = sizeof(holderPrtTbl); 
PrtTblHldDsc holderPrtTbl = {
{"Prt Tbl HR Processor"}
};

PrtTblStateDsc testPrtTblState = {
sizeof(PrtTblHldDsc),
(void*)&holderPrtTbl
};



int  ReqTransmitPrtTblPrMng;
int  ReqReceivePrtTblPrMng;



long ActivatePrtTblPrMng(void)
{
	register long i;
	void* pv;
	i = ID_PRT_PR_MNG;
	
	i = hldPrMngPrtTbl.shPrMngConState;
	if(i&(PM_STT_START_OCS_MSK|PM_STT_WORK_OCS_MSK|PM_STT_STOP_OCS_MSK))
	return 0;
	 pv = (void*)&hldPrMngPrtTbl;
	i =  ((ProxyMangerStateDsc*)pv)-> shPrMngConState;
	 i |= (PM_STT_USING_OCS_MSK)|(PM_STT_START_OCS_MSK);
	((ProxyMangerStateDsc*)pv)-> shPrMngConState = i;
	hldrTRPrtTblPrMngCTpuUnit.TrCnHldr.SizeAppObj = 0;//???
	(((ProxyMangerStateDsc*)pv)->ulLifeCtrEct) = (unsigned long)(-1);
	
//
//  ((BaseAcpuCMUnitDsc*)pv)-> pUchRV = (unsigned char*)&holderSettings.UNSettings.chArSettings[0];//
//

	//Set Transport
	return i;
}	
long WorkPrtTblPrMng (void* pv, long lV)//State control & Definions
{
register long i = 0;
//register long j;
    if(lV == PM_STT_START_OCS_ONB)
    {
       
		i = ((ProxyMangerStateDsc*)pv)-> shPrMngConState;
		i |= PM_STT_WORK_OCS_MSK;
		((ProxyMangerStateDsc*)pv)-> shPrMngConState = i;
		//Now it is all cmd
    	//i = ExecCmdProxySettings(pv,ACTIVATE_FILL_DATA);
		(((ProxyMangerStateDsc*)pv)->ulLifeCtrEct) = (-1);
    }
	if(lV == PM_STT_WORK_OCS_ONB)
    {
       

		i =  ExecPrtTblCmdPrMng (pv,lV);// i = ExecTargetProxyManager(pv,lV);ExecCmdPrtTblPrTpt

    }
	if(lV == PM_STT_STOP_OCS_ONB)
    {
        //Do SomeSing! for Init

		//i = 0;//AUX_OCS_MSK;//Reset State
		((ProxyMangerStateDsc*)pv)->arUchStateCmd[0] = 0;	
		((ProxyMangerStateDsc*)pv)->arUchStateCmd[1] = 0;
		((ProxyMangerStateDsc*)pv)->arUchStateCmd[2] = 0;
		((ProxyMangerStateDsc*)pv)->arUchStateCmd[3] = 0;
		((ProxyMangerStateDsc*)pv)->arUchCounterChangeStateCmd[0] = 0;
		((ProxyMangerStateDsc*)pv)->arUchCounterChangeStateCmd[1] = 0;
		((ProxyMangerStateDsc*)pv)->arUchCounterChangeStateCmd[2] = 0;
		//Now it is all cmd
    	//((ProxyTransportStateDsc*)pv)->arU32LifeCtr[0] = 0;
		//((ProxyTransportStateDsc*)pv)->arU32LifeCtr[1] = 0;
		//((ProxyTransportStateDsc*)pv)->arU32LifeCtr[2] = 0;
		//((ProxyTransportStateDsc*)pv)->arU32LifeCtr[3] = 0;
		i = ((ProxyMangerStateDsc*)pv)-> shPrMngConState;
		i = 0;
		((ProxyMangerStateDsc*)pv)-> shPrMngConState = i;
		((ProxyMangerStateDsc*)pv)-> chCmdReq =((ProxyMangerStateDsc*)pv)-> chCmdAnswer =((ProxyMangerStateDsc*)pv)-> ulStateProxyManger = i;
    }

return i;
}
//
 int  ReqTransmitPrtTblPrMng;
 int  ReqReceivePrtTblPrMng;
#define ID_PRT_PR_MNG 0X15
ProxyMangerStateDsc  hldPrMngPrtTbl = {
ID_PRT_PR_MNG,
0,
WorkPrtTblPrMng,ExecPrtTblCmdPrMng,
{0,0,0,0,0,0,0,0, 0,0 }, 
{0,0,0,0,0,0,0,0, 0,0 },
0,0,0
};
//Settings Input Param
ObjParamDsc hldTestPrtTblParam = {
0x200,//sizeof(holderPrtTbl),
(void*)&holderPrtTbl
};


extern  int AppReqTransmitTotVerInfoBrBs;


extern  long Eval_CS(char* pCh, long iLength );
extern volatile  int spi1_txsize, spi1_rxsize;
//extern int txsize_U2;
long ExecCmdPrtTblPrTpt (void* pv, long lV)
{
register long i,j;
register char *pch;
struct 
	{
		char chRetCode;//,
		unsigned short ushSizePacket;//
		
	} sLV;
	sLV.chRetCode = 0;
if(lV == EXEC_RECIVE_FILL_DATA)
    {
		lV = ((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA];
		lV--; ((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = lV;
		if (lV ==0)
		{
			((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[2] = ERR_TRANSPORT_WAITING_DATA;
			//Try Reset Whith Error Proxy Obj
			return 0;//Error
		}
		//else
		//{
		//    return 1;
		//}
		//
if(ReqReceivePrtTblPrTpt==0 ) return 1;
ReqReceivePrtTblPrTpt--;
        sLV.chRetCode = 0;
		pch = (char *)&(hldrRVPrtTblTransportCTpuUnit.RvCnHldr);//holderRVSettingsCTpuUnit);//?
		sLV.ushSizePacket = ((RVBaseCTpuUnitDsc*)pch)->ulRvCount;pch = (char *)&(hldrRVPrtTblTransportCTpuUnit.arUchRV); //RvCnHldr.pUchRV);
		 j = ((BaseAcpuCMUnitDsc*)pv)->ulRvCount;//
		j += sLV.ushSizePacket;
		if ((unsigned long)j<(((BaseAcpuCMUnitDsc*)pv)->ulRvTotal))
		{
			j = sLV.ushSizePacket;
			sLV.chRetCode = 1;
		}
		else
		{
			if ( j ==(((BaseAcpuCMUnitDsc*)pv)->ulRvTotal)   )
			{
				//(((BaseAcpuCMUnitDsc*)pv)->ulRvCount)		    
				j = sLV.ushSizePacket;
				
				sLV.chRetCode = 2;
			}
			else
			{
				//It is a error -- Bad assembly array !!
				// You must signal that Assembly Bad!
				j = 0;
				sLV.chRetCode = 0;
				
			}
			
		}
		i = (long) ((BaseAcpuCMUnitDsc*)pv)->pUchRV;
		 //i = (long) &holderTotMeas.UNTotMeas.chArTotMeas[0];
		i+= (long) ((BaseAcpuCMUnitDsc*)pv)->ulRvCount;//sLV.uVl;
		lV = i;
	
		for (i = 0; i < j; i++)
		{
			((char*)lV)[i] = pch[i];
		}
		
		switch (sLV.chRetCode )
		{
		case 1:
			i= (long) ((BaseAcpuCMUnitDsc*)pv)->ulRvCount;
			i += j;
			((BaseAcpuCMUnitDsc*)pv)->ulRvCount = i;
			if (j)
				  #ifdef _STATIC_MEMORY_BOOT 
				  ((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = VAL_TRANSPORT_WAIT>>1;
				  #else
				  ((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = VAL_TRANSPORT_WAIT<<1;
				  #endif
			//((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = VAL_TRANSPORT_WAIT<<1;
			break;
		case 2://
			i= (long) ((BaseAcpuCMUnitDsc*)pv)->ulRvCount;
			i += j;
			((BaseAcpuCMUnitDsc*)pv)->ulRvCount = i;
			//Signal of the End Conection 
			((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = 1;
			//Call function That Set apropriate data
			((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[2] = 1;//??? OK
			//Signal of the End Conection 
			sLV.chRetCode = 0;
			pch = (char *)&(holderPrtTbl);
			lV = Eval_CS((char*)pch,
			sizeof(PrtTblHldDsc)-sizeof(((PrtTblHldDsc*)pch)->lCheckSum));
			if( lV != (((PrtTblHldDsc*)pch)->lCheckSum) )
			{
				((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[2] = ERR_OBJECT_CHECK_SUM;
			}
			else
			{
				lV = TryPrtTblPrMngAlgWrActivate(pv,sLV.chRetCode);
				if(lV)
				((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[2] = 1;
				else
				((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[2] = ERR_STT_EXEC_PRT_TBL_PR_MNG;//ERR_STT_EXEC_YUST_PR_MNG;
			}
		
		
			break;
			
		case 0://
		
			//Signal of the End Conection 
			((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = 1;
			//Call function That fix Error state Proxy and array Data
			((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[2] = ERR_OBJECT_RECEIVE_SIZE;
			break;
		default:
			;
		}
		
		
		return sLV.chRetCode;
		
		
    }
	if(lV == EXEC_TRANSMIT_FILL_DATA )
    {
        lV = ((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING];
		lV--; ((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING] = lV;
		if (lV ==0)
		{
		    ((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[1] = ERR_TRANSPORT_WAITING_DATA;
			//Error
			((BaseAcpuCMUnitDsc*)pv)-> AppObjConState |= STT_STOP_OCS_MSK;
			return 0;//Stop Transmittion
		}
 		//else
 		//{
 		//    //Control Transmitting
 		//	return 1;
 		//
 		//	
 		//}
		pch = (char *)&hldrTRPrtTblTransportCTpuUnit.TrCnHldr;
		if(
				//ReqTransmitPrtTblPrTpt(((TRBaseCTpuUnitDsc*)pch)->ulTrCount  == ((TRBaseCTpuUnitDsc*)pch)->SizeAppObj) //Transmition through Phys canel
				(hldrSpiLpduTRUnit.uchLpuSpiState== 0)//Data out from Link Leyer
		)
		{
			//pv  = (void*)& holderProxyTotMeasUnit;
			lV = ((BaseAcpuCMUnitDsc*)pv)->ulTrCount;
			if ((unsigned long)lV>= (((BaseAcpuCMUnitDsc*)pv)-> ulTrTotal))
			{
				((ProxyTransportStateDsc*)pv)->  arUchResultExecCmd[1] = 1;//
				((BaseAcpuCMUnitDsc*)pv)-> AppObjConState |= STT_STOP_OCS_MSK;((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING] = 2;
			  ((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING] = 2;// IIII	
			  if(AppReqTransmitTotVerInfoBrBs == 0) 
				AppReqTransmitTotVerInfoBrBs = 1;
				return 0;//Stop Transmittion 
			}
			else 
			{
     			//ID_TEN_PERIOD_SAMPLES_UNIT;
				sLV.ushSizePacket = ((TRBaseCTpuUnitDsc*)pch)->SizeAppObj;
				lV += ((TRBaseCTpuUnitDsc*)pch)->SizeAppObj;//hldrTRPrtTblTransportCTpuUnit.TrCnHldr.SizeAppObj;
				((BaseAcpuCMUnitDsc*)pv)->ulTrCount = lV;
				((TRBaseCTpuUnitDsc*)pch)->SizeAppObj = 0;//hldrTRPrtTblTransportCTpuUnit.TrCnHldr.SizeAppObj  = 0;//Is really need?
				if ((unsigned long)lV>= (((BaseAcpuCMUnitDsc*)pv)-> ulTrTotal))
				return 1;

			}
			i = 0;
			if( ((BaseAcpuCMUnitDsc*)pv)->ulTrCount == 0 )
			i++;//First Packet
			if(
			sLV.ushSizePacket && (((TRBaseCTpuUnitDsc*)pch)->pUchTR==0)//
			)
			i++;
			
			if (i)
			{ ReqTransmitPrtTblPrTpt = START;//Activate Sesion
			 if(hldrTpCnState.uchTpState_CNL_Spi==0)
			 hldrTpCnState.uchTpState_CNL_Spi  = 1;//Select Channel This is only for speed up activating Transmittion???
			 ((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING] = VAL_TRANSPORT_TRANSMIT;
			}
		
		}
		return 1;
    }

	if(lV == EXEC_FREE_FILL_DATA)
    {
       
//. 	   pv  = (void*)& holderProxySettingsUnit;
//.	   //Control Correctnes Receive Data
//.	   //compare Total &  actual Receive data
//.	   if ( (((RVBaseCTpuUnitDsc*)pv)->ulRvCount) ==(((BaseAcpuCMUnitDsc*)pv)->ulRvTotal)   )
//.	   chStateArSettingsData = SUCCESS_EXEC;
//.	   else 
//.	   chStateArSettingsData = ERROR_EXEC;
//.	   
//.		((BaseAcpuCMUnitDsc*)pv)->pUchTR = 0;//Base Addr Obj
//.		((BaseAcpuCMUnitDsc*)pv)->ulTrCount = 0;
//.		((BaseAcpuCMUnitDsc*)pv)->ulTrTotal = 0;
//.		//,((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = 0;
 		lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
 		lV |= STT_STOP_OCS_MSK; 
 		((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = lV;
//.		((ProxyTransportStateDsc*)pv)->arU32LifeCtr[0] = 0;
//.		((ProxyTransportStateDsc*)pv)->arU32LifeCtr[1] = 0;
//.		((ProxyTransportStateDsc*)pv)->arU32LifeCtr[2] = 0;
//.		((ProxyTransportStateDsc*)pv)->arU32LifeCtr[3] = 0;
//.		//Clear Tran
//.		TestReqTransmitSettings=0;

//Master Must Set Flags and Call Init Proxy Transport
//Muster Must then peridicaly look state Proxy Transport
//detect Ok,errorrs then clear  Proxy Transport State	

	   return 0;//Exex Action for Taras Array
    }
	return sLV.chRetCode;
} 
long WorkPrtTblPrTpt (void* pv, long lV)
{
register long i = 0;
register long j;
PFL_VL pfl_vl;
if(lV == STT_START_OCS_ONB)
    {
        ((ProxyTransportStateDsc*)pv)->arUchResultExecCmd[1] = 0;
		((ProxyTransportStateDsc*)pv)->arUchResultExecCmd[2] = 0;
		//ResetProxyTransport(pv, lV); or Clr State CMD + Res + TMRS
		//Do SomeSing! for Init
		((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0] = j =0;
		((ProxyTransportStateDsc*)pv)-> arUchExecCmd[1] = EXEC_TRANSMIT_FILL_DATA;
		((ProxyTransportStateDsc*)pv)-> arUchExecCmd[2] = EXEC_RECIVE_FILL_DATA  ;
		((ProxyTransportStateDsc*)pv)-> arUchExecCmd[3] = EXEC_FREE_FILL_DATA    ;
		j = SelectorCmd(pv);//What Exec Next	
		
		((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0] = j;//Selector Cmd

		i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
		i |= STT_WORK_OCS_MSK;
		((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = i;	
		
		//Now it is all cmd
    	//i = ExecCmdProxyTransport(pv,ACTIVATE_TRANSMIT_RQ_DATA);
		//((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0] = 2;
	
		//return i;
    }
	if(lV == STT_WORK_OCS_ONB)
    {
       
	   i = ((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0];//Pointer to Active Cmd
	   if (i==0)
	   return lV--;// ! Error
	   if (i<EXEC_TOTAL_CMD)//Now Treshold for this Executor
	   {
	      j = ((ProxyTransportStateDsc*)pv)-> arUchExecCmd[i];//Load Command
		  
		 
		  //lV = ExecCmdProxyTransport(pv,j);
		   pfl_vl = ((BaseAcpuCMUnitDsc*)pv)-> pf_ExecCmd;i = (long)pfl_vl;
		   if (i)
		   lV = pfl_vl(pv,j);
		  if (lV==0)//Ok
		  {
			//Look you have right for stop exec all Cmd
			j = SelectorCmd(pv);
			((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0] = j;//++i;
		  }
	   }
	   else{
	   ((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0] = 0;//Terminate Exec
	   }
	   //return i;
    }
	if(lV == STT_STOP_OCS_ONB)
    {
        //Do SomeSing! for Init
		//((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0] = 0;//1;
		//((ProxyTransportStateDsc*)pv)-> arUchExecCmd[1] = 0;//
		//((ProxyTransportStateDsc*)pv)-> arUchExecCmd[2] = 0;//
		//((ProxyTransportStateDsc*)pv)-> arUchExecCmd[3] = 0;//
		//
		i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
		
		i &= USING_OCS_MSK;//??? Wait Reset from Maneger AUX_OCS_MSK;//Reset State
		//Manager must detect result Execution have error or OK what type Error of transport
		((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = i;	
		 ((BaseAcpuCMUnitDsc*)pv)-> ulRvCount  = 0;
		 ((BaseAcpuCMUnitDsc*)pv)-> ulTrCount  = 0;
		 ((BaseAcpuCMUnitDsc*)pv)-> ulRvTotal  = 0;
		 ((BaseAcpuCMUnitDsc*)pv)-> ulTrTotal  = 0;
		 ((BaseAcpuCMUnitDsc*)pv)-> pUchRV     = 0;
		 ((BaseAcpuCMUnitDsc*)pv)-> pUchTR     = 0;
		//Now it is all cmd
    	
		
    }

return i;

}
long InitProxyTransport (void* pv, long lV)
{
return 0; 
}
long ResetProxyTransport (void* pv, long lV)
{
((BaseAcpuCMUnitDsc*)pv)->ulRvCount = 0;
    ((BaseAcpuCMUnitDsc*)pv)->ulTrCount = 0;
    ((BaseAcpuCMUnitDsc*)pv)->ulRvTotal = 0;
    ((BaseAcpuCMUnitDsc*)pv)->ulTrTotal = 0;
    ((BaseAcpuCMUnitDsc*)pv)->pUchRV    = (unsigned char*)0;
    ((BaseAcpuCMUnitDsc*)pv)->pUchTR    = (unsigned char*)0;
	for (lV = 0; lV < 4; lV++)
	{
		((ProxyTransportStateDsc*)pv)->arUchExecCmd      [lV] = 0;
		((ProxyTransportStateDsc*)pv)->arU32LifeCtr      [lV] = 0;
		((ProxyTransportStateDsc*)pv)->arUchResultExecCmd[lV] = 0;
	}
	((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = 0;
	return 0;
}



#define ID_PRT_PR_TRANSPORT 0X16
ProxyTransportStateDsc hldPrTrptPrtTbl = {
ID_PRT_PR_TRANSPORT,
0,0,0,0,0,
(unsigned char*)0,(unsigned char*)0,
//(PFL_VL)0,(PFL_VL)0,(PFL_VL)0,(PFL_VL)0
//InitProxyTransport,ResetProxyTransport,WorkProxyTransport,ExecCmdProxyTransport,
InitProxyTransport,ResetProxyTransport,WorkPrtTblPrTpt,ExecCmdPrtTblPrTpt,


// arUchExecCmd[4] = {
                   {0,0,0,0}, {0,0,0,0}, {0,0,0,0}
//{0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0 }
};
int  ReqTransmitPrtTblPrTpt;
int  ReqReceivePrtTblPrTpt;



void ActivateServTrApCnPrtTblTptUnitSpi(void)
{

register long i,j;
register char *pch;
register void* pv;
//-//Copy
//-  pch = (char *)&(holderTRSrcSamplesCTpuUnit.arUchTR);
//-  pv  = (void*)& holderSrcSamplesUnit;
//-  j = sizeof(SrcSamplesUnitDsc);
//-  for (i = 0; i < j; i++)
//-  {
//-    pch[i] = ((char*)pv)[i];
//-  }hldTestSettigsParam.p_ObjEntity
pv  = (void*)&hldPrTrptPrtTbl.hldrAcpuCMUnitState;//& holderProxySettingsUnit;
//testSettigsState
pch = (char *)((BaseAcpuCMUnitDsc*)pv)->pUchTR;//Base Addr Obj
i = ((BaseAcpuCMUnitDsc*)pv)->ulTrCount;//
j = ((BaseAcpuCMUnitDsc*)pv)->ulTrTotal;
   j -= i;
pch += i;//Addr Of Transmition
  //Reset Connect State
   pv  = (void*)& (hldrTRPrtTblTransportCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_SPI;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_SPI;// Logic can ctrl
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf    = SIZE_TPDU_TRANSPORT_PRT_CNL_SPI;
   if( j> SIZE_TPDU_TRANSPORT_PRT_CNL_SPI)
   j = (SIZE_TPDU_TRANSPORT_PRT_CNL_SPI)-4;
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = j;//
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_PRT_PR_TRANSPORT;//
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)pch;
   //(unsigned char*)& holderTRSrcSamplesCTpuUnit.arUchTR;
   
}
void TerminateServiceApCnPrPrtTblTpt(void)
{
//register void *pv;
//register long i;
  //pv  = (void*)& (holderTR10PeriodCTpuUnit.TrCnHldr);
  //((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)0;
  hldrTRPrtTblTransportCTpuUnit.TrCnHldr.pUchTR = (unsigned char*)0;
  //holderTR10PeriodCTpuUnit.TrCnHldr.SizeAppObj = 
}
void PrepDecompousePrtTblTptUnitSpi(void)
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
	if(ReqTransmitPrtTblPrTpt)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_Spi;j = SIZE_TPDU_TRANSPORT_PRT_CNL_SPI;//>>2;//If Channel full
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (ReqTransmitPrtTblPrTpt==START)
			{
				ActivateServTrApCnPrtTblTptUnitSpi();
				ReqTransmitPrtTblPrTpt = EXEC;
			}
			//ProcessTransmit Obj
			if(ReqTransmitPrtTblPrTpt==EXEC)
			{
				i = ServiceTRApCn2((void*)&hldrTRPrtTblTransportCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					ReqTransmitPrtTblPrTpt = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<7))//channel Full
				ReqTransmitPrtTblPrTpt = EXEC;//Activate Channel transmition and Set Zapret vizova ses poka ne otrabotaet chanel transmit LPU

				if (ReqTransmitPrtTblPrTpt==TERM)
				{
					//.TerminateServiceApCn((void*)& holderSrcSamplesUnit,ID_SRC_SAMPLES_UNIT);
					TerminateServiceApCnPrPrtTblTpt();
					ReqTransmitPrtTblPrTpt = 0;
				}
			}
		}
		//Try another???
		
	}
	

}

void ActivateServTrApCnPrtTblPrMngSpi(void)
{

register long i,j;
register char *pch;
register void* pv;

pv = (void*)&hldPrtTblCmmMsgTR;j = 0;
i =  ((CmmMsgDsc*)pv)->UNNHdrMsg.uchAr[0];

//Detect Type Msg
	switch (i)
 	{
 	
	case CMD_REQ_REMOUT_RST         :

	case CMM_GET_YUST_OBJ_FROM_HM : //
	pch = (char *)&(hldrTRPrtTblPrMngCTpuUnit.arUchTR);
	 pch[0] = i;
 	break;
 	//case 2:
 	//    pDst = (char*)&(((TRStateLpuU2Dsc*)pv)->arUch[j+1]);
 	//	*((short*)pDst) = ((TRStateLpuU2Dsc*)pv)->ushSizeLDC;
 	//	j = 2;
 	//	break;
 	
 	default:
 	i++;
 	} 

	if(j)//Copy if really need transmit Obj
	{
		//Copy
		pch = (char *)&(hldrTRPrtTblPrMngCTpuUnit.arUchTR);
		pv  = ((CmmMsgDsc*)pv)->p_ObjEntity; //(void*)& holderSrcSamplesUnit;
		j = ((CmmMsgDsc*)pv)->size_Obj;//sizeof(SrcSamplesUnitDsc);
		for (i = 0; i < j; i++)
		{
			pch[i] = ((char*)pv)[i];
		}
	}
	else j = 1;//One Byte


  //Reset Connect State
   pv  = (void*)& ( hldrTRPrtTblPrMngCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_SPI;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_SPI;// Logic can ctrl
   //j = //Size Msg
   if( j> SIZE_TPDU_PRT_PR_MNG_CNL_SPI)
   j = SIZE_TPDU_PRT_PR_MNG_CNL_SPI;//Don`t Send Very Big Msg
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = j;//
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf    = SIZE_TPDU_PRT_PR_MNG_CNL_SPI;
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_PRT_PR_MNG;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)pch;
   //(unsigned char*)& holderTRSrcSamplesCTpuUnit.arUchTR;
  
   
   
}
void TerminateServiceApCnPrtTblPrMng(void)
{
//register void *pv;
//register long i;

  hldrTRPrtTblPrMngCTpuUnit.TrCnHldr.pUchTR = (unsigned char*)0;
  hldrTpCnState.uchTpState_CNL_HSU2 += 2;//For Debug Pupouses only 

}
void PrepDecompousePrtTblPrMngSpi(void)
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
	if(ReqTransmitPrtTblPrMng)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_Spi;j = SIZE_TPDU_PRT_PR_MNG_CNL_SPI;//If Channel full
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (ReqTransmitPrtTblPrMng==START)
			{
				ActivateServTrApCnPrtTblPrMngSpi();
				ReqTransmitPrtTblPrMng = EXEC;
			}
			//ProcessTransmit Obj
			if(ReqTransmitPrtTblPrMng==EXEC)
			{
				i = ServiceTRApCn2((void*)&hldrTRPrtTblPrMngCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					ReqTransmitPrtTblPrMng = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<7))//channel Full
				ReqTransmitPrtTblPrMng = EXEC;//Activate Channel transmition and Set Zapret vizova ses poka ne otrabotaet chanel transmit LPU

				if (ReqTransmitPrtTblPrMng==TERM)
				{
					//.TerminateServiceApCn((void*)& holderSrcSamplesUnit,ID_SRC_SAMPLES_UNIT);
					TerminateServiceApCnPrtTblPrMng();
					ReqTransmitPrtTblPrMng = 0;
				}
			}
		}
		//Try another???
		
	}
	

}


long PassPrtTblPrMngRvMsgOrigin(void);
long PassPrtTblPrMngRvMsg(void* pvLDC, long lID)
{
register long i;
register void* pv;	
//pv  = (void*)hldrRVStngPrMngCTpuUnit.RvCnHldr;	
//pch = (char *)&( hldrRVStngPrMngCTpuUnit.arUchRV);	
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	hldrRVPrtTblPrMngCTpuUnit.RvCnHldr.ulRvCount  = lID;
	//lID = 3?;
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	pvLDC = (void*)i;
	pv  = (void*)& ( hldrRVPrtTblPrMngCTpuUnit.arUchRV);
	
	for (i = 0; i < lID; i++)
	{
		((char*)pv)[i] = ((char*)pvLDC)[i];
	}
	
	return PassPrtTblPrMngRvMsgOrigin();
}
long PassPrtTblPrMngRvMsgOrigin(void)
{
register long i,j;
register char *pch;
register void* pv;
struct 
	{
		//short         shCountCmd;  
		unsigned char uChIdxByte ;
		unsigned char uChIdxBit ;
		//short shErr;
		//char ch1,ch2,ch3,ch4;
		void *pvPrMng,*pvCmmMsg;

		
	} sLV;
	sLV.pvPrMng  = (void*)& hldPrMngPrtTbl;
	sLV.pvCmmMsg = (void*)& hldrRVPrtTblPrMngCTpuUnit;
	sLV.uChIdxBit = 0;sLV.uChIdxByte = 0;
	//Detect connection State
	pv = sLV.pvPrMng;
	i = ((ProxyMangerStateDsc*)pv)-> shPrMngConState;
	//j = ((i&PM_STT_WORK_OCS_MSK)== 0 )&& (i&(PM_STT_START_OCS_MSK));
	//j = (i&(PM_STT_WORK_OCS_MSK));
	//j |= (i&(PM_STT_START_OCS_MSK));
	//if (j)
	//sLV.uChIdxBit =  PM_STT_START_OCS_ONB;
	j =  (i&(PM_STT_WORK_OCS_MSK)) && ((i&( PM_STT_STOP_OCS_MSK ))==0);
	if (j)
	sLV.uChIdxBit =  PM_STT_WORK_OCS_ONB;
	
	j = (i&(PM_STT_STOP_OCS_MSK));
	if (j)
	sLV.uChIdxBit =  PM_STT_STOP_OCS_ONB;
	
	j = (i&(PM_STT_USING_OCS_MSK)); 
	if (j==0)
	 sLV.uChIdxBit =  PM_STT_START_OCS_ONB;//Activation 

	switch (sLV.uChIdxBit)
 	{
		case  PM_STT_WORK_OCS_ONB:
			sLV.uChIdxByte ++;//	 pch[0] = i;
		break;
		case  PM_STT_STOP_OCS_ONB:
		;//	 Do nothing Now
		break;
		case  PM_STT_START_OCS_ONB:
			//First Init Proxy
			j = i&(PM_STT_START_OCS_MSK|PM_STT_WORK_OCS_MSK|PM_STT_STOP_OCS_MSK);
			if(j==0)
			{
				i =  ((ProxyMangerStateDsc*)pv)-> shPrMngConState;
				i |= (PM_STT_USING_OCS_MSK)|(PM_STT_START_OCS_MSK);
				((ProxyMangerStateDsc*)pv)-> shPrMngConState = i;
			
			}
			sLV.uChIdxByte++;		
		;//	 pch[0] = i;
		break;
		 	
 	default:
	;
	}	
	//
	if (sLV.uChIdxByte)
	{
	
		//Put Msg
		if( chUsehldPrtTblCmmMsgRV == 0)
		{
			
			pv  = (void*)& hldrRVPrtTblPrMngCTpuUnit.RvCnHldr;
			j = ((RVBaseCTpuUnitDsc*)pv)-> ulRvCount;//Size of Message
			
			pv  = (void*)& hldPrtTblCmmMsgRV.UNNHdrMsg;//Prepea for hundling 
			 pch = (char *)&( hldrRVPrtTblPrMngCTpuUnit.arUchRV);
			 ((char*)pv)[0] = CMM_GET_PRT_TBL_OBJ_FROM_HR;
			for (i = 0; i < j; i++)
			{
				((char*)pv)[i] = pch[i];
			}
			//?? What about size_Obj *p_ObjEntity ???
		}
		else
		{
			//.!! Here Poit Fix a lose data 
		
		}
	}
	hldrRVPrtTblPrMngCTpuUnit.RvCnHldr.ulRvCount = 0;//
	
//ExitPassSettingsPrMngRvMsgOrigin:
return sLV.uChIdxByte;
}


















#define RV_CMD_DIS_MSK    (1<<0)





//Function for Modification Proxy state & exec

long TryPrtTblSetSendEct  (void* pv, long lV)
{
//Simply Control Is Transmition Work?
return   ECT_SEND_REQ_TR_PRT_TBL_FROM_HR;//ECT_SEND_REQ_TR_YUST_FROM_HM;//ECT_SEND_YUST_FROM_HM;
//And Other Param Allowed or Not allowed Transmittion

}
//extern unsigned int ustuvannja [NUMBER_CANALS];
extern unsigned int PrtTbl[SIZE_PRT>>2];//
long TryPrtTblActivateExch  (void* pv, long lV)
{
register long i;//,j;
register char *pSrc,*pDst;
struct 
	{
		void  *pOriginPrMng;//, *pOriginTpCn;

	} sLV;
//1)Detect Is able Transport for Transmit Data
sLV.pOriginPrMng = pv;
pv = (void*)& hldPrTrptPrtTbl;pSrc = (char *)&brCfgTbl;//PrtTbl[0];//ustuvannja[0];
lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
if (lV&(STT_STOP_OCS_MSK))
	{
		lV = 0;
		goto RetTryActivateExchPrtTbl;
	}
	if(lV&(RV_MODE_OCS_MSK))//In Receive State now
	{
		lV = 0;
		goto RetTryActivateExchPrtTbl;
	}
//2)Create Req for Taras System 
//current_settings_DBG = current_settings ;
lV = sizeof(brCfgTbl);//PrtTbl);//ustuvannja
pDst =(void*) &holderPrtTbl.UNPrtTbl.lArPrt[0];//~pDst =(void*) &holderPrtTbl.UNPrtTbl.PrtTbl[0];
for (i = 0; i < lV ; i++ )
{
	pDst[i] = pSrc[i];
       // pDst[i++] = i&0xff;
       // pDst[i] = i>>8;
}
//3)Wait Answer Error Or Ok
//4)If error Send Error
//5)Then Send Last Copy
//5)If Ok Send Ok Msg???
testPrtTblState.size_PrtTbl    = sizeof(PrtTblHldDsc);//SIZE_PRT;
testPrtTblState.p_PrtTbl = (void*)&holderPrtTbl;
lV =  Eval_CS((char*)&holderPrtTbl,
			sizeof(PrtTblHldDsc)-sizeof( holderPrtTbl.lCheckSum) );	
	holderPrtTbl.lCheckSum = lV;
//6)Activate Transport Work
 //lV = ActivateTrStngPrTpt((void*)&testSettigsState,0);
  lV =  ActivatePrtTblTrPrTpt((void*)&testPrtTblState,0);
  
//7)Set state control Transmition Data

//8)If End Destroy Transport Destroy Self
if (lV )
{
pv = sLV.pOriginPrMng;
lV = ECT_SEND_PRT_TBL_FROM_HR; //ECT_SEND_YUST_FROM_HM;
i = (((ProxyMangerStateDsc*)pv)->ulLifeCtrEct);
i &=  0x3ffff; (((ProxyMangerStateDsc*)pv)->ulLifeCtrEct) = i;
}


RetTryActivateExchPrtTbl:
return  lV; 
}
// long SetSendStngEct(void* pv, long lV)
// {
// // Insert Activation Function
// 	return lV;
// }
long CtrlSendPrtTblEct(void* pv, long lV)
{
struct 
	{
		short  shVl;
		char   chRes;
		//void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		//PFL_VL pfl_vl;
		void *pvPrMng,*pvTransport;
	} sLV;
union 
	{
		unsigned char   uchAr [4];//Bit Field
		unsigned short  ushAr [2];//Task & Phase
		unsigned long   ulVal;
	}UNNlV;
	UNNlV.ulVal = 0;
	sLV.pvPrMng = pv; sLV.pvTransport = (void*)&hldPrTrptPrtTbl;
	

	if(
	hldPrTrptPrtTbl.arUchResultExecCmd[1] >0
	
	)
	{
		
		UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
		UNNlV.uchAr[3] = ECT_WAIT_CMD_HM;
		lV = UNNlV.uchAr[0];
		lV &= ~(RV_CMD_DIS_MSK);
		UNNlV.uchAr[0] = lV;
		(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal;
		(((ProxyMangerStateDsc*)pv)->ulLifeCtrEct) = 0xf;//Stop Proxy
		lV  = ResetProxyTransport(sLV.pvTransport,lV);
		
		lV  = UNNlV.ulVal;
	
	}

	return lV;
}


/*
long SetYustSendEct(void* pv, long lV)
{
union 
	{
		unsigned char   uchAr [4];//Bit Field
		unsigned short  ushAr [2];//Task & Phase
		unsigned long   ulVal;
	}UNNlV;
UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
if ((UNNlV.uchAr[3] == ECT_WAIT_CMD_HS)
|| UNNlV.uchAr[3] == 0
)//Control Posibility for change state
{
//SendPrMngMsg
		//pv = (void*)&hldCmmMsg;
		//((CmmMsgDsc*)pv)->
		hldYustCmmMsgRV.UNNHdrMsg.uchAr[0] = CMM_GET_YUST_OBJ_FROM_HS;//CMM_TR_COBJ_HM_TO_HS;//
		
		//Activate Queue
		if(ReqTransmitYustPrMng<EXEC)
		ReqTransmitYustPrMng = START;//Control you Permit Activate 
		
		UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
		UNNlV.uchAr[3] = ECT_CREATE_CMM_TR_COBJ_HM_TO_HS;
		//lV = UNNlV.uchAr[0];
		//lV = ~(RV_CMD_DIS_MSK);
		//UNNlV.uchAr[0] = lV;
		(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal;
}

	return UNNlV.uchAr[3];
}
*/
//////////////////////////////////////////////////////////////////
long DpcsPrtTblPrMngMsg   (void* pv, long lV)
{
struct 
	{
		char  chNeedClrMsg;
		short shV;
		//long lV;
		//void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		
	} sLV;
union 
	{
		unsigned char   uchAr [4];//Bit Field
		unsigned short  ushAr [2];//Task & Phase
		unsigned long   ulVal;
	}UNNlV;
	UNNlV.ulVal = 0;	
sLV.chNeedClrMsg = sLV.shV =  0;
UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);

	switch (lV)//Detect posibility ;//	 pch[0] = i;
 	{

		case  CMM_GET_PRT_TBL_OBJ_FROM_HR:  //CMM_GET_STNG_OBJ_FROM_HM: Stub Now CMM_GET_YUST_OBJ_FROM_HM 
		if(chbrCfgTblState&(1<<BR_CFG_TBL_USED_BIT))//Be Carefull !!!
		;
		else{
			sLV.chNeedClrMsg++;//In this place hundlers for analise posibility Exec Cmd
			lV =  TryPrtTblActivateExch(pv,sLV.shV); // TrySetSendStngEct  Activate Transport from 
			if(lV)
			UNNlV.uchAr[3] = lV;
			}
		break;

		

 	default:
	;
	}
	//Change Stste
	if ( lV )
	{
		//if (lV != UNNlV.uchAr[3])
		if ((((ProxyMangerStateDsc*)pv)->ulStateProxyManger) != UNNlV.uchAr[3])
		(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal;
	}
			
	if(sLV.chNeedClrMsg)
	hldPrtTblCmmMsgRV.UNNHdrMsg. ulAr  [0] = 0;//Need Clear Receive Msg
return UNNlV.ulVal;


}




#define RV_CMD_DIS_MSK    (1<<0)
//
long ExecPrtTblCmdPrMng  (void* pv, long lV)
{
//register long j;
struct 
	{
		short  shVl;
		char   chRes;
		//void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		//PFL_VL pfl_vl;
		//void *pvPrMng,*pvCmmMsg;
	} sLV;
union 
	{
		unsigned char   uchAr [4];//Bit Field
		unsigned short  ushAr [2];//Task & Phase
		unsigned long   ulVal;
	}UNNlV;
	UNNlV.ulVal = 0; sLV.shVl = 0;sLV.chRes = 0;
	
//Dec Life Counter
//Control Self LifeTimer
UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulLifeCtrEct);
	if (UNNlV.ulVal != 0)
	//if(sLV.UNNlV.ulVal != 0)// UNNlV.ulVal; UNNlV.ulVal = lPhsLifeCtr;
	{
		if(UNNlV.uchAr[3] < 0xff)
		UNNlV.ulVal--;//Ok Can Wait
		(((ProxyMangerStateDsc*)pv)->ulLifeCtrEct) = UNNlV.ulVal;
	}
	else
	{
		;//Time Out
		lV = ((ProxyMangerStateDsc*)pv)-> shPrMngConState;
		lV |= (PM_STT_STOP_OCS_MSK | PM_STT_ERROR_OCS_MSK);
		((ProxyMangerStateDsc*)pv)-> shPrMngConState = lV;
		UNNlV.ulVal = ((ProxyMangerStateDsc*)pv)-> ulStateProxyManger;
		UNNlV.uchAr[1] = ERR__TIMEOUT__TGT_T1_PHS2;//???
		((ProxyMangerStateDsc*)pv)-> ulStateProxyManger = UNNlV.ulVal;
		goto RetStateProxyManger; 
	}	




lV = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
	if ( (chUsehldPrtTblCmmMsgRV==0) && ((lV&RV_CMD_DIS_MSK)== 0) )
	{
		sLV.shVl =  hldPrtTblCmmMsgRV.UNNHdrMsg.uchAr[0];//CmmMsgDsc
		if(sLV.shVl !=0)//Hndl Inp Msg
		{
			UNNlV.ulVal = DpcsPrtTblPrMngMsg(pv,sLV.shVl);//Desigion Point Change State
			 //;
			if (UNNlV.ulVal != lV)//(((ProxyMangerStateDsc*)pv)->ulStateProxyManger)
			{
							
				sLV.chRes = UNNlV.uchAr[3];//Fix Change State
			}
		
		}

		
	}
	//else
	//{
	//	goto RetStateProxyManger;//Busy Input Msg
	//	
	//}
	UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
	switch (UNNlV.uchAr[3])
 	{
		case  ECT_WAIT_CMD_HM: // ECT  Execute
			//Call Hundler
			 WaitPrtTblCmdHmEct(pv,sLV.shVl);
		break;
		case  ECT_WRITE_COBJ_OOBJ_HM:
		     AlgPrtTblWriteEct(pv,sLV.shVl);
		break;
		//case  ECT_CMP_COBJ_OOBJ_HM:  // Diagnostic Result 
		//	//First Init Proxy       //
		//			
		//;//	
		//break;
		//.case  ECT_SEND_STNG_FROM_HM:  // Diagnostic Result
		//.	//First Init Proxy
		//.	lV = SetSendStngEct(pv,0);//Activate Transport	
		//.	UNNlV.uchAr[3] = ECT_WAIT_CMD_HS;
		//.	lV = UNNlV.uchAr[0];
		//.	lV = ~(RV_CMD_DIS_MSK);
		//.	UNNlV.uchAr[0] = lV;
		//.	(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal;
		//.
		break;
		case  ECT_SEND_PRT_TBL_FROM_HR: //.ECT_SEND_YUST_FROM_HM:
		case  ECT_SEND_REQ_TR_PRT_TBL_FROM_HR: //.ECT_SEND_REQ_TR_YUST_FROM_HM: //You must be sure that req hundled
			lV = CtrlSendPrtTblEct(pv,0);//
		break;



		 	
 	default:
		 UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger) ;
	UNNlV.uchAr[3] = ECT_WAIT_CMD_HM;//ECT_WAIT_CMD_HM;//???
	(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal;
	}
	
RetStateProxyManger:

	return  sLV.chRes;
}

long  WaitPrtTblCmdHmEct (void* pv, long lV)
{
// Insert Wait Phase May be remake
	return lV;
}
//long SetYustSendStngEct(void* pv, long lV)
//{
//// Insert Activation Function
//	return lV;
//}


/*

//Function for Modification Proxy state & exec

long TryPrtTblSetSendEct  (void* pv, long lV)
{
//Simply Control Is Transmition Work?
return   ECT_SEND_YUST_FROM_HS;
//And Other Param Allowed or Not allowed Transmittion

}
long SetPrtTblSendEct(void* pv, long lV)
{
union 
	{
		unsigned char   uchAr [4];//Bit Field
		unsigned short  ushAr [2];//Task & Phase
		unsigned long   ulVal;
	}UNNlV;
UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
if ((UNNlV.uchAr[3] == ECT_WAIT_CMD_HS)
|| UNNlV.uchAr[3] == 0
)//Control Posibility for change state
{
//SendPrMngMsg
		//pv = (void*)&hldCmmMsg;
		//((CmmMsgDsc*)pv)->
		hldPrtTblCmmMsgTR.UNNHdrMsg.uchAr[0] = CMM_GET_YUST_OBJ_FROM_HM;//CMM_TR_COBJ_HM_TO_HS;//
		
		//Activate Queue
		if(ReqTransmitPrtTblPrMng<EXEC)
		ReqTransmitPrtTblPrMng = START;//Control you Permit Activate 
		
		UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
		UNNlV.uchAr[3] = ECT_SEND_REQ_TR_YUST_FROM_HS;
		//lV = UNNlV.uchAr[0];
		//lV = ~(RV_CMD_DIS_MSK);
		//UNNlV.uchAr[0] = lV;
		(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal;
}

	return UNNlV.uchAr[3];
}

//////////////////////////////////////////////////////////////////
long DpcsPrtTblPrMngMsg   (void* pv, long lV)
{
struct 
	{
		char  chNeedClrMsg;
		short shV;
		//long lV;
		//void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		
	} sLV;
union 
	{
		unsigned char   uchAr [4];//Bit Field
		unsigned short  ushAr [2];//Task & Phase
		unsigned long   ulVal;
	}UNNlV;
	UNNlV.ulVal = 0;	
sLV.chNeedClrMsg = sLV.shV =  0;
UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);

	switch (lV)//Detect posibility ;//	 pch[0] = i;
 	{

		case  CMM_GET_YUST_OBJ_FROM_HM :  //CMM_GET_STNG_OBJ_FROM_HM: Stub Now
			sLV.chNeedClrMsg++;//In this place hundlers for analise posibility Exec Cmd
			lV =  TryPrtTblSetSendEct(pv,sLV.shV); //   Activate Transport from 
			// UNNlV.uchAr[3] = lV;
		break;
		//case  CMM_TR_COBJ_HM_TO_HS: //ECT_SEND_REQ_TR_STNG_FROM_HS  :  //ECT_REQ_ACTIVATE_RV
		////case  ECT_CREATE_CMM_TR_COBJ_HM_TO_HS:
		//	sLV.chNeedClrMsg++;//In this place hundlers for analise posibility Exec Cmd
		//	lV =   SetSendReqTrStngEct(pv,sLV.shV); //  Activate Transport from 
		//	// UNNlV.uchAr[3] = lV;
		//break;
		
		

 	default:
	;
	}
	//Change Stste
	if ( lV )
	{
		if (lV != UNNlV.uchAr[3])
		(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal;
	}
			
	if(sLV.chNeedClrMsg)
	hldPrtTblCmmMsgRV.UNNHdrMsg. ulAr  [0] = 0;//Need Clear Receive Msg
return UNNlV.ulVal;


}




#define RV_CMD_DIS_MSK    (1<<0)
//
long ExecPrtTblCmdPrMng  (void* pv, long lV)
{
//register long j;
struct 
	{
		short  shVl;
		char   chRes;
		//void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		//PFL_VL pfl_vl;
		//void *pvPrMng,*pvCmmMsg;
	} sLV;
union 
	{
		unsigned char   uchAr [4];//Bit Field
		unsigned short  ushAr [2];//Task & Phase
		unsigned long   ulVal;
	}UNNlV;
	UNNlV.ulVal = 0; sLV.shVl = 0;sLV.chRes = 0;
	
//Dec Life Counter
//Control Self LifeTimer
UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulLifeCtrEct);
	if (UNNlV.ulVal != 0)
	//if(sLV.UNNlV.ulVal != 0)// UNNlV.ulVal; UNNlV.ulVal = lPhsLifeCtr;
	{
		if(UNNlV.uchAr[3] < 0xff)
		UNNlV.ulVal--;//Ok Can Wait
		(((ProxyMangerStateDsc*)pv)->ulLifeCtrEct) = UNNlV.ulVal;
	}
	else
	{
		;//Time Out
		lV = ((ProxyMangerStateDsc*)pv)-> shPrMngConState;
		lV |= (PM_STT_STOP_OCS_MSK | PM_STT_ERROR_OCS_MSK);
		((ProxyMangerStateDsc*)pv)-> shPrMngConState = lV;
		UNNlV.ulVal = ((ProxyMangerStateDsc*)pv)-> ulStateProxyManger;
		UNNlV.uchAr[1] = ERR__TIMEOUT__TGT_T1_PHS2;//???
		((ProxyMangerStateDsc*)pv)-> ulStateProxyManger = UNNlV.ulVal;
		goto RetStateProxyManger; 
	}	




lV = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
	if ( (chUsehldPrtTblCmmMsgRV==0) && ((lV&RV_CMD_DIS_MSK)== 0) )
	{
		sLV.shVl =  hldPrtTblCmmMsgRV.UNNHdrMsg.uchAr[0];//CmmMsgDsc
		if(sLV.shVl !=0)//Hndl Inp Msg
		{
			UNNlV.ulVal = DpcsPrtTblPrMngMsg(pv,sLV.shVl);//Desigion Point Change State
			 //;
			if (UNNlV.ulVal != lV)//(((ProxyMangerStateDsc*)pv)->ulStateProxyManger)
			{
							
				sLV.chRes = UNNlV.uchAr[3];//Fix Change State
			}
		
		}

		
	}
	//else
	//{
	//	goto RetStateProxyManger;//Busy Input Msg
	//	
	//}
	UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
	switch (UNNlV.uchAr[3])
 	{
		case  ECT_WAIT_CMD_HS: // ECT  Execute
			//Call Hundler
			 WaitPrtTblCmdHmEct(pv,sLV.shVl);
		break;
		//case  ECT_WRITE_COBJ_OOBJ_HM:
		//;//	 Do nothing Now
		//break;
		//case  ECT_CMP_COBJ_OOBJ_HM:  // Diagnostic Result 
		//	//First Init Proxy       //
		//			
		//;//	
		//break;
		//.case  ECT_SEND_STNG_FROM_HM:  // Diagnostic Result
		//.	//First Init Proxy
		//.	lV = SetSendStngEct(pv,0);//Activate Transport	
		//.	UNNlV.uchAr[3] = ECT_WAIT_CMD_HS;
		//.	lV = UNNlV.uchAr[0];
		//.	lV = ~(RV_CMD_DIS_MSK);
		//.	UNNlV.uchAr[0] = lV;
		//.	(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal;
		//.
		break;
		case  ECT_SEND_REQ_TR_YUST_FROM_HS: //You must be sure that req hundled
			 sLV.shVl = hldrTRPrtTblPrMngCTpuUnit.TrCnHldr.SizeAppObj;
			if ((ReqTransmitPrtTblPrMng<EXEC) && sLV.shVl)//Succesful Send ReqTransmitSettingsPrMng
			{
				hldrTRPrtTblPrMngCTpuUnit.TrCnHldr.SizeAppObj  = 0;//Clear Size Msg
				lV = ActivatePrtTblRvPrTpt((void*)&testPrtTblState,0); 
				UNNlV.uchAr[3] = ECT_WAIT_CMD_HS;
				lV = UNNlV.uchAr[0];
				lV = ~(RV_CMD_DIS_MSK);
				UNNlV.uchAr[0] = lV;
				(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal; 
				UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulLifeCtrEct);
				UNNlV.ushAr[1] = 0x1;(((ProxyMangerStateDsc*)pv)->ulLifeCtrEct) = UNNlV.ulVal;
		    }
		break;



		 	
 	default:
		 UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger) ;
	UNNlV.uchAr[3] = ECT_WAIT_CMD_HS;//ECT_WAIT_CMD_HM;//???
	(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal;
	}
	
RetStateProxyManger:

	return  sLV.chRes;
}

long  WaitPrtTblCmdHmEct (void* pv, long lV)
{
// Insert Wait Phase May be remake
	return lV;
}
//long SetPrtTblSendStngEct(void* pv, long lV)
//{
//// Insert Activation Function
//	return lV;
//}


*/












long ActivatePrtTblRvPrTpt(void* pObjParam, long lV)
{
//register long i;//,j;
//register char *pSrc;//,*pDst;
register void* pv;


//Detect State Proxy Transport
	pv = (void*)& hldPrTrptPrtTbl;
	;
	//Detect Self
	;
	//If Possible change State
	;
	//Look Transport
	pv  = (void*)& hldPrTrptPrtTbl.hldrAcpuCMUnitState;
	//BaseAcpuCMUnitDsc hldrAcpuCMUnitState
	lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//sLV.UNNlV.ushAr[0] = lV;//
	
	//STT_WORK_OCS_MSK |TR_MODE_OCS_MSK; Look this maybe you must exlude start when transmit state
	//i = lV;
	//Ignore Command
	if (lV&(STT_STOP_OCS_MSK))
	{
		lV = 0;
		goto RetActivateRvPrtTblPrTpt;
	}
	if(lV&(RV_MODE_OCS_MSK))//In Receive State now
	{
		lV = 0;
		goto RetActivateRvPrtTblPrTpt;
	}

	//lV = (i&(STT_WORK_OCS_MSK)) && ((i&( STT_STOP_OCS_MSK ))==0);<- Look Maybe already work?
	 lV |= USING_OCS_MSK|STT_START_OCS_MSK|RV_MODE_OCS_MSK;
 	((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = lV;
	 
	//hldrRVPrtTblTransportCTpuUnit.TrCnHldr.SizeAppObj       = 0;//??
	((BaseAcpuCMUnitDsc*)pv)->pUchRV = (unsigned char *)
	((ObjParamDsc*)pObjParam)-> p_ObjEntity ;// 
	((BaseAcpuCMUnitDsc*)pv)->ulRvCount = 0;
	((BaseAcpuCMUnitDsc*)pv)->ulRvTotal = 
	(((ObjParamDsc*)pObjParam)->size_Obj) ;//sizeof(total_measurement);//
	((ProxyTransportStateDsc*)pv)->arUchResultExecCmd[1] = 0;
    ((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = VAL_TRANSPORT_WAIT;
//

//hldrTRPrtTblPrMngCTpuUnit.TrCnHldr.SizeAppObj = 0;

RetActivateRvPrtTblPrTpt:

return lV;//

}
long ActivatePrtTblTrPrTpt(void* pObjParam, long lV)
{
//register long i;//,j;
//register char *pSrc;//,*pDst;
register void* pv;


//Detect State Proxy Transport
	pv = (void*)& hldPrTrptPrtTbl;
	;
	//Detect Self
	;
	//If Possible change State
	;
	//Look Transport
	pv  = (void*)& hldPrTrptPrtTbl.hldrAcpuCMUnitState;
	//BaseAcpuCMUnitDsc hldrAcpuCMUnitState
	lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//sLV.UNNlV.ushAr[0] = lV;//
	
	//STT_WORK_OCS_MSK |TR_MODE_OCS_MSK; Look this maybe you must exlude start when transmit state
	//i = lV;
	//Ignore Command
	if (lV&(STT_STOP_OCS_MSK))
	{
		lV = 0;
		goto RetActivateTrPrtTblPrTpt;
	}
	
	if(lV&(TR_MODE_OCS_MSK))//In Receive State now
	{
		lV = 0;
		goto RetActivateTrPrtTblPrTpt;
	}	
	//lV = (i&(STT_WORK_OCS_MSK)) && ((i&( STT_STOP_OCS_MSK ))==0);<- Look Maybe already work?
	 lV |= USING_OCS_MSK|STT_START_OCS_MSK|TR_MODE_OCS_MSK;
 	((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = lV;
	
	//hldrRVPrtTblTransportCTpuUnit.TrCnHldr.SizeAppObj       = 0;//??
	((BaseAcpuCMUnitDsc*)pv)->pUchTR = (unsigned char *)
	((ObjParamDsc*)pObjParam)-> p_ObjEntity ;// 
	((BaseAcpuCMUnitDsc*)pv)->ulTrCount = 0;
	((BaseAcpuCMUnitDsc*)pv)->ulTrTotal = //16*SIZE_TPDU_TRANSPORT_PRT_CNL_SPI;
	((ObjParamDsc*)pObjParam)->size_Obj ;//sizeof(total_measurement);//

//((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING] = (-1);

hldrTRPrtTblTransportCTpuUnit.TrCnHldr.SizeAppObj  = 0;
RetActivateTrPrtTblPrTpt:

return lV;//

}


long UpdateRVPrTptPrtTbl1(void* pvLDC, long lID)
{
register long i;//,j;
register char *pSrc;//,*pDst;
void* pv;


if ( (((LDCIDsc*)pvLDC)-> uchConMode)== 0)
{
	pv  = (void*)&hldrRVPrtTblTransportCTpuUnit.arUchRV;
	pSrc = (char *) (((LDCIDsc*)pvLDC)-> pSrc);
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	//MoveData: 
	for (i = 0; i < lID; i++)
	{
	  ((char*)pv)[i] = pSrc[i]; //((char*)pvLDC)[i];
	}
	//Activate For Proxy Msg
	//ReqReceive ++;ReqReceiveAr++; //?????
	//Clear All Ses Data
	hldrRVPrtTblTransportCTpuUnit.RvCnHldr.uchUsedTransport = 0;
	hldrRVPrtTblTransportCTpuUnit.RvCnHldr.NumComSes        = 0;
	hldrRVPrtTblTransportCTpuUnit.RvCnHldr.ConState         = 0;
	hldrRVPrtTblTransportCTpuUnit.RvCnHldr.ulRvCount        = lID;ReqReceivePrtTblPrTpt++;

}
else
{
	//-Analize Sesion state Etc.
	pv  = (void*)&hldrRVPrtTblTransportCTpuUnit.RvCnHldr;
	if ( ((LDCIDsc*)pvLDC)-> uchStartSesion == 1)
	{
		((RVBaseCTpuUnitDsc*)pv)->NumComSes = (((LDCIDsc*)pvLDC)-> uchConMode);//unnV1.uchAr[2];
		((RVBaseCTpuUnitDsc*)pv)->pUchRV = (unsigned char*)&hldrRVPrtTblTransportCTpuUnit.arUchRV; 
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = 0;
	}
	
	i = ((RVBaseCTpuUnitDsc*)pv)->NumComSes == ((LDCIDsc*)pvLDC)->NumComSes;
		if (i)
		{
			//;
			pSrc = (char *) (((LDCIDsc*)pvLDC)-> pSrc);//i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
			lID = ((LDCIDsc*)pvLDC)->uchTR_C;
			//pvLDC = (void*)i;
			i = (long)&hldrRVPrtTblTransportCTpuUnit.arUchRV;
			i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
			pv  = (void*)i;
			for (i = 0; i < lID; i++)
			{
			((char*)pv)[i] =  pSrc[i]; //((char*)pvLDC)[i];
			}
			
			
		}
		else
		{
			;//Error Sesion
			pv  = (void*)&hldrRVPrtTblTransportCTpuUnit.RvCnHldr;
			((RVBaseCTpuUnitDsc*)pv)->uchUsedTransport = 0;
			((RVBaseCTpuUnitDsc*)pv)->NumComSes        = 0;
			((RVBaseCTpuUnitDsc*)pv)->ConState         = 0;
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount        = 0;
			ReqReceivePrtTblPrTpt = 0;
		}
	

}

//Try activate Proxy Transport if not activated
i = ActivatePrtTblRvPrTpt((void*)&testPrtTblState ,0);
//.  
//.  //Indicator data Transmit to Application
//.  //holderRVSrcSamplesCTpuUnit. TrCnHldr.pUchRV           = 0;

return lID;//

}



/*
long GetPrtTblTbl(void)
{
register void* pv;
register long lV;
lV = 0;
//Detect State Proxy Transport
	pv = (void*)& hldPrTrptPrtTbl;
	//Look Transport
	pv  = (void*)& hldPrTrptPrtTbl.hldrAcpuCMUnitState;
	//BaseAcpuCMUnitDsc hldrAcpuCMUnitState
	lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//i = lV;
	//Ignore Command
	if (lV&(STT_STOP_OCS_MSK))
	{
		lV = 0;
		goto RetPtGetPrtTblTbl;
	}
	if(lV&(RV_MODE_OCS_MSK))//In Receive State now
	{
		lV = 0;
		goto RetPtGetPrtTblTbl;
	}
//Prepea Transport
//Control State transport

//Activate Proxy
    lV = ActivatePrtTblPrMng();
pv = (void*)&hldPrMngPrtTbl;
//Put Request in queue
if (lV)
// hldCmmMsgRV.UNNHdrMsg.uchAr[0] = ECT_REQ_ACTIVATE_RV;
 lV =  SetPrtTblSendEct(pv,ECT_CREATE_CMM_TR_COBJ_HM_TO_HS);
//Control Ok or Error
//Call Func Control State PrMng + Pr Tpt
//Return Val 1-OK 2-Error 0- No Data
//
RetPtGetPrtTblTbl:
 return lV;
}
*/

long SendPrtTblTbl(void)
{
register void* pv;
register long lV;
lV = 0;
//Detect State Proxy Transport
	pv = (void*)& hldPrTrptPrtTbl;
	//Look Transport
	pv  = (void*)& hldPrTrptPrtTbl.hldrAcpuCMUnitState;
	//BaseAcpuCMUnitDsc hldrAcpuCMUnitState
	lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//i = lV;
	//Ignore Command
	if (lV&(STT_STOP_OCS_MSK))
	{
		lV = 0;
		goto RetPtSendPrtTblTbl;
	}
	if(lV&(RV_MODE_OCS_MSK))//In Receive State now
	{
		lV = 0;
		goto RetPtSendPrtTblTbl;
	}
//Prepea Transport
//Control State transport
//ActivateTransmitStngObj();
 lV =  ActivatePrtTblTrPrTpt((void*)&testPrtTblState,0);


RetPtSendPrtTblTbl:
 return lV;

}



void ResetAlgYustWrEctDsc(void *pv)
{
	((AlgPrtTblWrEctDsc*)pv)->chIdxCmd              = 0; 
	((AlgPrtTblWrEctDsc*)pv)->chLastCmd             = 0;
	((AlgPrtTblWrEctDsc*)pv)->arUchExecCmd[0]       = 0;
	((AlgPrtTblWrEctDsc*)pv)->arUchExecCmd[1]       = 0;
	((AlgPrtTblWrEctDsc*)pv)->arUchResultExecCmd[0] = 0;
	((AlgPrtTblWrEctDsc*)pv)->arUchResultExecCmd[1] = 0;
}


long TryPrtTblPrMngAlgWrActivate  (void* pv, long lV)
{
union 
	{
		unsigned char   uchAr [4];//Bit Field
		unsigned short  ushAr [2];//Task & Phase
		unsigned long   ulVal;
	}UNNlV;
	UNNlV.ulVal = 0;
lV =  ActivatePrtTblPrMng();//
//if (lV==0)
//goto ExitTryYustPrMngAlgWrActivate;

 pv = (void*)&hldPrMngPrtTbl;
 lV = ((ProxyMangerStateDsc*)pv)->shPrMngConState;
	if(lV&(PM_STT_START_OCS_MSK|PM_STT_WORK_OCS_MSK|PM_STT_STOP_OCS_MSK))
	;
	else
		{
			lV = 0;
			goto ExitTryPrtTblPrMngAlgWrActivate;
		}	
UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
if ((UNNlV.uchAr[3] == ECT_WAIT_CMD_HM)
|| UNNlV.uchAr[3] == 0
)
{
	//pv = (void*)&hldPrMngYust;
	UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
	UNNlV.uchAr[3] = ECT_WRITE_COBJ_OOBJ_HM;
	lV = UNNlV.uchAr[0];
	lV |= (RV_CMD_DIS_MSK);
	UNNlV.uchAr[0] = lV;
	(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal;
	//(((ProxyMangerStateDsc*)pv)->ulLifeCtrEct) = 0xf;//Stop Proxy
	

}
ExitTryPrtTblPrMngAlgWrActivate:
return lV;
}

//extern volatile unsigned int changed_ustuvannja; 

void ResetAlgPrtTblWrEctDsc(void *pv)
{
	((AlgPrtTblWrEctDsc*)pv)->chIdxCmd              = 0; 
	((AlgPrtTblWrEctDsc*)pv)->chLastCmd             = 0;
	((AlgPrtTblWrEctDsc*)pv)->arUchExecCmd[0]       = 0;
	((AlgPrtTblWrEctDsc*)pv)->arUchExecCmd[1]       = 0;
	((AlgPrtTblWrEctDsc*)pv)->arUchResultExecCmd[0] = 0;
	((AlgPrtTblWrEctDsc*)pv)->arUchResultExecCmd[1] = 0;
}

long AlgPrtTblWriteEct(void* pv, long lV)
{
register char *pSrc,*pDst;
long i;
__istate_t s;
struct 
	{
		short  shVl;
		char   chRes;
		//void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		//PFL_VL pfl_vl;
		void *pvPrMng;//,*pvTransport;
	} sLV;
union 
	{
		unsigned char   uchAr [4];//Bit Field
		unsigned short  ushAr [2];//Task & Phase
		unsigned long   ulVal;
	}UNNlV;
	UNNlV.ulVal = 0;
	sLV.pvPrMng = pv;
	sLV.chRes = hldrAlgPrtTblWrEct.chIdxCmd;
UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);

	switch (sLV.chRes )
	{
		case 0://
				//changed_ustuvannja = CHANGED_ETAP_EXECUTION;
				//EnterCritical
				s = __get_interrupt_state();
				__disable_interrupt();
				if( chbrCfgTblState&(1<<BR_CFG_TBL_USED_BIT) )
				{
					 sLV.chRes = 0;
				}
				else
				{
					chbrCfgTblState |=(1<<BR_CFG_TBL_USED_BIT);
					 sLV.chRes = 1;
				}	
				//Exit Critical  
				__set_interrupt_state(s);
				 
				
			break;
		case 1:
			lV = sizeof(CfgTblDsc);//PrtTbl);//ustuvannja
			pSrc = (char *) &holderPrtTbl.UNPrtTbl.lArPrt[0];//&holderYust.UNYust.ustuvannja_BS[0];
			pDst = (char *) &brCfgTbl;// PrtTbl[0];//&ustuvannja[0];	
			for (i = 0; i < lV ; i++ )
			{
				pDst[i] = pSrc[i];
			}
			//Enter Critical
			s = __get_interrupt_state();
				__disable_interrupt();
			chbrCfgTblState &= ~(1<<BR_CFG_TBL_USED_BIT);
			//Exit Critical
			chbrCfgTblState |= (1<<BR_CFG_TBL_WR_EPR_BIT);
			__set_interrupt_state(s);
			 sLV.chRes = 2;
			break;
		case 2://
			  if (chbrCfgTblState&(1<<BR_CFG_TBL_WR_EPR_BIT))
			  sLV.chRes = 2;
			  else
			  {
			  chbrCfgTblState &= ~(1<<BR_CFG_TBL_ICI_MF_BIT);
			   //changed_ustuvannja  = CHANGED_ETAP_ENDED;
			   sLV.chRes = 3;
			   }
			break;
		case 3://
			//._SET_BIT(control_i2c_taskes, TASK_START_WRITE_USTUVANNJA_EEPROM_BIT);
			ResetAlgPrtTblWrEctDsc(&hldrAlgPrtTblWrEct);
			UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
			UNNlV.uchAr[3] = ECT_WAIT_CMD_HM;
			lV = UNNlV.uchAr[0];
			lV &= ~(RV_CMD_DIS_MSK);
			UNNlV.uchAr[0] = lV;
			(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal;
			(((ProxyMangerStateDsc*)pv)->ulLifeCtrEct) = 0xf;//Stop Proxy
			//lV  = ResetProxyTransport(sLV.pvTransport,lV);???
			sLV.chRes = 0;
		
		break;	
		default:
			ResetAlgPrtTblWrEctDsc(&hldrAlgPrtTblWrEct);sLV.chRes = 0;
	}

	{
		hldrAlgPrtTblWrEct.chIdxCmd = sLV.chRes;
		//UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
	}
	

	return UNNlV.uchAr[3];
}


long SelectorCmd(void* pv)
{
register long i = 0;
register long j;
union 
	{
		unsigned char   uchAr [4];//Bit Field
		unsigned short  ushAr [2];//Task & Phase
		unsigned long   ulVal;
	}UNNlV;
	UNNlV.ulVal = 0;
       //Do SomeSing! for Init
	//.((ProxySettingsUnitDsc*)pv)-> arUchExecCmd[0] = j =0;
	//.((ProxySettingsUnitDsc*)pv)-> arUchExecCmd[1] = EXEC_TRANSMIT_FILL_DATA;
	//.((ProxySettingsUnitDsc*)pv)-> arUchExecCmd[2] = EXEC_RECIVE_FILL_DATA  ;
	//.((ProxySettingsUnitDsc*)pv)-> arUchExecCmd[3] = EXEC_FREE_FILL_DATA    ;
	UNNlV.uchAr[0] = j  = ((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0];//Previous State
	UNNlV.uchAr[1] = ((ProxyTransportStateDsc*)pv)-> arUchExecCmd[j];//Detect type Command
	i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//UNNlV.uchAr[2] = ((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[j];//State command
	if ( (i&(TR_MODE_OCS_MSK)) 
	&& (((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[1]== 0)
	)//Ok
	{
		UNNlV.uchAr[3] = 1;//Index EXEC_TRANSMIT_FILL_DATA;
		//  j = TR_MODE_OCS_ONB;//
		if (UNNlV.uchAr[1]!=EXEC_TRANSMIT_FILL_DATA)
		{
			//Get Priority
			goto FixCmd;
		}	
	}
	//You could be insert in this place something for analises errors etc.
	//and change path of executing	
	
	if ( (i&(RV_MODE_OCS_MSK))
	&&(((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[2]== 0)
	)//Ok
	{
		UNNlV.uchAr[3] = 2;//Index EXEC_RECIVE_FILL_DATA;
		//  j = TR_MODE_OCS_ONB;//
		if (UNNlV.uchAr[1]!=EXEC_RECIVE_FILL_DATA)
		{
			//Get Priority
			goto FixCmd;
		}	   
	  
	 }
	if(UNNlV.uchAr[3]==0) 
	{
	//Need Termination Proxy i.e. All Cmd Executed
		if (((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[3]== 0)
		{
			UNNlV.uchAr[3] = 3;//EXEC_FREE_FILL_DATA
		}
		else
		{
			;//Detect Error
		}
	}
	 
FixCmd:
	 
	return UNNlV.uchAr[3];//Index Load Cmd
}


long MoveCTputoAppObj(void *pBaseAcpuCM, void *pRVBaseCTpu);
long UpdateRVPrTptPrtTbl(void* pvLDC, long lID)
{
register long i;//,j;
register char *pSrc;//,*pDst;
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
RVBaseCTpuUnitDsc locRVBaseCTpuUnit;	 	
		
		
sLV.pOriginLDC = pvLDC;
 sLV.chNeedClrSesData = 0;unnV1.ulVal = 0;
if (ReqReceivePrtTblPrTpt>=1)//This part of code need as as previous buf need iteretivly  move to proxy
{
locRVBaseCTpuUnit = hldrRVPrtTblTransportCTpuUnit.RvCnHldr;
locRVBaseCTpuUnit.pUchRV = (hldrRVPrtTblTransportCTpuUnit.arUchRV);//Buffer Addr
i = MoveCTputoAppObj((void*)&hldPrTrptPrtTbl.hldrAcpuCMUnitState,
(void*)&locRVBaseCTpuUnit);
//if i == 0 //Error Fix!
ReqReceivePrtTblPrTpt = 0;//Now i think another number  is error
}
	//Move Buff to Obj
if ( (((LDCIDsc*)pvLDC)-> uchConMode)== 0)
{
	i = (((LDCIDsc*)pvLDC)->uchTR_C);//+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
	if( i<= (long)(SIZE_TPDU_TRANSPORT_PRT_CNL_SPI))
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	else
	lID = (SIZE_TPDU_TRANSPORT_PRT_CNL_SPI);
	unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	pvLDC = (void*)i;//Src Pointer
	
	//pv  = (void*)&hldrAcpuCMUnitState.hldrAcpuCMUnitState;
	
	pv  = (void*)&hldrRVPrtTblTransportCTpuUnit.arUchRV;
	//pSrc = (char *) (((LDCIDsc*)pvLDC)-> pSrc);
	//lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	//MoveData: 
	for (i = 0; i < lID; i++)
	{
	  ((char*)pv)[i] = ((char*)pvLDC)[i];
	}
	//Activate For Proxy Msg
	//ReqReceive ++;ReqReceiveAr++; //?????
	//Clear All Ses Data
	hldrRVPrtTblTransportCTpuUnit.RvCnHldr.uchUsedTransport = 0;
	hldrRVPrtTblTransportCTpuUnit.RvCnHldr.NumComSes        = 0;
	hldrRVPrtTblTransportCTpuUnit.RvCnHldr.ConState         = 0;
	hldrRVPrtTblTransportCTpuUnit.RvCnHldr.ulRvCount        = lID;ReqReceivePrtTblPrTpt++;

}
else
{
	//-Analize Sesion state Etc.
	pv  = (void*)&hldrRVPrtTblTransportCTpuUnit.RvCnHldr;
	if ( ((LDCIDsc*)pvLDC)-> uchStartSesion == 1)
	{
		unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
		unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
		unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
		unnV1.uchAr[3] = 0;
		((RVBaseCTpuUnitDsc*)pv)->NumComSes = (unnV1.uchAr[2])>>4;//
		//((RVBaseCTpuUnitDsc*)pv)->pUchRV = (unsigned char*)&hldrRVPrtTblTransportCTpuUnit.arUchRV; 
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = 0;
		((RVBaseCTpuUnitDsc*)pv)->ConState =((LDCIDsc*)pvLDC)-> uchConMode;//Fix Connection
		//field ((RVBaseCTpuUnitDsc*)pv)->ConState param )-> uchConMode first i Decide use in
		//This function when size receve(transmit obj) not defined use param uchConMode
		//When session continue always 1 when stoped must be 0. 
		//You should change in future ServiceTRApCn2 function for markinga Last Packet
		//in session 
		//param )-> uchConMode == 0 must terminate receve proc in any case
		
	}
	unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
	i = (((LDCIDsc*)pvLDC)->NumComSes)>>4;
	if (i== (((RVBaseCTpuUnitDsc*)pv)->NumComSes) )
	{
		i = (((LDCIDsc*)pvLDC)->uchTR_C)+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
		if( i<= (long)(SIZE_TPDU_TRANSPORT_PRT_CNL_SPI))
		lID = ((LDCIDsc*)pvLDC)->uchTR_C;
		else
		lID = (SIZE_TPDU_TRANSPORT_PRT_CNL_SPI) - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
		unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
		i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
			
		pvLDC = (void*)i;
		i = (long)&hldrRVPrtTblTransportCTpuUnit.arUchRV;
		i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
		pv  = (void*)i;
		for (i = 0; i < lID; i++)
		{
			((char*)pv)[i] = ((char*)pvLDC)[i];
		}
		//Update Rv
		pv  = (void*)&hldrRVPrtTblTransportCTpuUnit.RvCnHldr;
		//lID = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount+unnV1.uchAr[3];//Is good desigion
		lID += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = lID;
		unnV1.uchAr[2] = 0;
		if  (lID >= (long)(SIZE_TPDU_TRANSPORT_PRT_CNL_SPI))
		unnV1.uchAr[2] |= 1;//Fix Stop Connection
		if(unnV1.uchAr[0]== 0 && ((RVBaseCTpuUnitDsc*)pv)->ConState == 1) //Fix Reset Connection
		unnV1.uchAr[2] |= 2;//Fix Stop Connection
		if ( unnV1.uchAr[2]	)
		{
			
			if ((lID == (long)(SIZE_TPDU_TRANSPORT_PRT_CNL_SPI))
			||(unnV1.uchAr[2]&2))//Command Reset Connection
			{
				//Activate App Func
				ReqReceivePrtTblPrTpt++;
				
			
			}
			else
			{
			
			}
			 sLV.chNeedClrSesData++;
		
		}
	
	}
	else
	{
		;//Error Session
		 sLV.chNeedClrSesData++;
	
	
	
	}
	if(sLV.chNeedClrSesData)
	{
		pv  = (void*)&hldrRVPrtTblTransportCTpuUnit.RvCnHldr;
		((RVBaseCTpuUnitDsc*)pv)->uchUsedTransport = 0;
			((RVBaseCTpuUnitDsc*)pv)->NumComSes        = 0;
			((RVBaseCTpuUnitDsc*)pv)->ConState         = 0;
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount        = 0;
		ReqReceivePrtTblPrTpt = 0;	
	
	}

	

}

//Try activate Proxy Transport if not activated
i = ActivatePrtTblRvPrTpt((void*)&testPrtTblState ,0);
//.  
//.  //Indicator data Transmit to Application
//.  //holderRVSrcSamplesCTpuUnit. TrCnHldr.pUchRV           = 0;

return lID;//

}

long MoveCTputoAppObj(void *pBaseAcpuCM, void *pRVBaseCTpu)
{
register long i,j;
//register char *pch;
struct 
	{
		char chRetCode;//,
		unsigned short ushSizePacket;//
		void *pOriginBaseAcpuCM;
	} sLV;
sLV.chRetCode = 0;sLV.ushSizePacket = 0;
sLV.pOriginBaseAcpuCM = pBaseAcpuCM;
sLV.ushSizePacket = ((RVBaseCTpuUnitDsc*)pRVBaseCTpu)->ulRvCount;
//pch = (char *)&(hldrRVPrtTblTransportCTpuUnit.arUchRV);
    j = ((BaseAcpuCMUnitDsc*)pBaseAcpuCM)->ulRvCount;//
	j += sLV.ushSizePacket;
	if ((unsigned long)j<(((BaseAcpuCMUnitDsc*)pBaseAcpuCM)->ulRvTotal))
	{
		j = sLV.ushSizePacket;
		sLV.chRetCode = 1;

	}
	else
	{
		if ( j ==(((BaseAcpuCMUnitDsc*)pBaseAcpuCM)->ulRvTotal)   )
		{
			//(((BaseAcpuCMUnitDsc*)pv)->ulRvCount)		    
			//j = sLV.ushSizePacket; //In this function it is erroneus situation
			j = 0;
			sLV.chRetCode = 2;
			sLV.ushSizePacket = j;
		}
		else
		{
			//It is a error -- Bad assembly array !!
			// You must signal that Assembly Bad!
			j = 0;
			sLV.chRetCode = 0;
			sLV.ushSizePacket = j;
		}
		
	}
	i = (long) ((BaseAcpuCMUnitDsc*)pBaseAcpuCM)->pUchRV;
	 
	i+= (long) ((BaseAcpuCMUnitDsc*)pBaseAcpuCM)->ulRvCount;//sLV.uVl;
	pBaseAcpuCM = (void*)i;
	i = (long) (((RVBaseCTpuUnitDsc*)pRVBaseCTpu)->pUchRV);
	pRVBaseCTpu  = (void*)i;
	for (i = 0; i < j; i++)
	{
		((char*)pBaseAcpuCM)[i] = ((char*)pRVBaseCTpu)[i];
	}
	if(j)
	{
		pBaseAcpuCM = sLV.pOriginBaseAcpuCM ;
		i= (long) ((BaseAcpuCMUnitDsc*)pBaseAcpuCM)->ulRvCount;
		i += j;
		((BaseAcpuCMUnitDsc*)pBaseAcpuCM)->ulRvCount = i;
	}	
return sLV.ushSizePacket;//Size 
}

/*
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---
extern char  ReqGetPrtTblBM(long lActivation, void* pPrtTblStateDsc);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~     функция запроса на получение  юстировочных чисел  с BM            ~~~~~
//~~~                                                                          ~~~~~
//~~~                                                                          ~~~~~
//~~~    Возвращаемое значение                                                 ~~~~~
//~~~    1 - команда начала выполняться                                        ~~~~~
//~~~    2 - системы защит и автоматики находится в состоянии выполнении запроса ~~~
//~~~    3 - команда выполнена успешно                                         ~~~~~
//~~~    4 - возникла  ошибка при старте, передаче,                            ~~~~~
//~~~     или данные недостоверны                                              ~~~~~
 
//``````````````````````````````````````````````````````````````````````````````````
//~~~ pPrtTblStateDsc  - По данному адресу в случае успеха будет помещен указатель
//~~~   на структуру _ описыввающую                          ~~~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                                          ~~~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                       ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//==================================================================================
//Body func                                      
//==================================================================================
char   ReqGetPrtTblBM(long lActivation, void* pPrtTblStateDsc)
{
    register long i;
	register long j;
	if (lActivation>1 && lActivation<0) 
	return ERROR_EXEC;
	if (pPrtTblStateDsc == 0) 
	return ERROR_EXEC;
	
	if (lActivation == 1)
	{
		j = 0;
		//Control State Proxy Mng
		i = hldPrMngPrtTbl.shPrMngConState;
		if(i&(PM_STT_START_OCS_MSK|PM_STT_WORK_OCS_MSK|PM_STT_STOP_OCS_MSK))
		{
			i = hldPrMngPrtTbl.ulStateProxyManger; i >>= 24;
			if( (i == 0) || (i == ECT_SEND_YUST_FROM_HS) )//Phase where data not send from HS
			j++;//State Exec
		}
		//Control State transport
		//i = hldPrTrptPrtTbl.hldrAcpuCMUnitState.AppObjConState;//Is it Work???
		//if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK  ))
		i = hldPrTrptPrtTbl.arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA];
		if(i>10)
	    {
			((PrtTblStateDsc*)pPrtTblStateDsc)-> size_PrtTbl      = 0;
			((PrtTblStateDsc*)pPrtTblStateDsc)-> p_PrtTbl = (void*)0;
			j++;
			
		}
		if(j)
		i = STATE_EXEC;
		else
		{
		    //((PrtTblStateDsc*)pPrtTblStateDsc)-> size_ustuvannja_BS      = 0;
			//((PrtTblStateDsc*)pPrtTblStateDsc)-> p_ustuvannja_BS = (long*)0;
			//.holderProxyPrtTblUnit.hldObjParam.size_Obj = ((PrtTblStateDsc*)pPrtTblStateDsc)-> size_ustuvannja_BS; 
			//.holderProxyPrtTblUnit.hldObjParam.p_ObjEntity = 
			//.((PrtTblStateDsc*)pPrtTblStateDsc)-> p_ustuvannja_BS;
			testPrtTblState.size_PrtTbl = ((PrtTblStateDsc*)pPrtTblStateDsc)-> size_PrtTbl;
			testPrtTblState.p_PrtTbl    = ((PrtTblStateDsc*)pPrtTblStateDsc)-> p_PrtTbl;
			i =  GetPrtTblTbl();//ActivateProxyPrtTbl();
			if (i)
			i = START_EXEC;
			else
			i  = ERROR_EXEC;
			
		}

	}
	else
	{
		// i = hldPrTrptPrtTbl.hldrAcpuCMUnitState.AppObjConState;
		//if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK |STT_STOP_OCS_MSK ))//RV_MODE_OCS_MSK
		i = hldPrTrptPrtTbl.arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA];
		if(i>10)
	    {
			//((ArTenPerStateDsc*)pArDataDsc)-> sizeAr      = 0;
			//((ArTenPerStateDsc*)pArDataDsc)-> pTenPerData = 0;
			
			i = STATE_EXEC;
		}
		else
		{
		    
			((PrtTblStateDsc*)pPrtTblStateDsc)-> size_PrtTbl      = //lSizeOf_PrtTbl;
			testPrtTblState.size_PrtTbl;
			((PrtTblStateDsc*)pPrtTblStateDsc)-> p_PrtTbl = 
			//(long*)&holderPrtTbl.UNPrtTbl.chArPrtTbl[0];
			testPrtTblState.p_PrtTbl;
			i  = ERROR_EXEC;
			//if (chStateAr10PerData != SUCCESS_EXEC)
			//i = chStateArPrtTblData;
			if( (hldPrTrptPrtTbl. arUchResultExecCmd[2] >0)
				&&(hldPrTrptPrtTbl. arUchResultExecCmd[2]<0x80)
			)
			{
				i =  SUCCESS_EXEC;
			}
			
		}
	
	}
	
	
	return i;

}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""



//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---
extern char  ReqSendPrtTblBM(long lActivation, void* pPrtTblStateDsc);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~     функция запроса на отправку  юстировочных чисел на  BM            ~~~~~
//~~~                                                                        ~~~~~
//~~~                                                                          ~~~~~
//~~~    Возвращаемое значение                                                 ~~~~~
//~~~    1 - команда начала выполняться                                        ~~~~~
//~~~    2 - системы защит и автоматики находится в состоянии выполнении запроса ~~~
//~~~    3 - команда выполнена успешно                                         ~~~~~
//~~~    4 - возникла  ошибка при старте, передаче,                            ~~~~~
//~~~     или данные недостоверны                                              ~~~~~
 
//``````````````````````````````````````````````````````````````````````````````````
//~~~ pPrtTblStateDsc  - По данному адресу в случае успеха будет помещен указатель
//~~~   на структуру _total_measurement описыввающую                          ~~~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                                          ~~~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                       ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//==================================================================================
//Body func                                      
//==================================================================================
char   ReqSendPrtTblBM(long lActivation, void* pPrtTblStateDsc)
{
    register long i;
	
	if (lActivation>1 && lActivation<0) 
	return ERROR_EXEC;
	if (pPrtTblStateDsc == 0) 
	return ERROR_EXEC;
	
	if (lActivation == 1)
	{
		i = hldPrTrptPrtTbl.hldrAcpuCMUnitState.AppObjConState;//Is it Work???
		if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK  ))
	    {
			((PrtTblStateDsc*)pPrtTblStateDsc)-> size_PrtTbl      = 0;
			((PrtTblStateDsc*)pPrtTblStateDsc)-> p_PrtTbl = (void*)0;
			
			i = STATE_EXEC;
		}
		else
		{
		    //((PrtTblStateDsc*)pPrtTblStateDsc)-> size_ustuvannja_BS      = 0;
			//((PrtTblStateDsc*)pPrtTblStateDsc)-> p_ustuvannja_BS = (long*)0;
			//.holderProxyPrtTblUnit.hldObjParam.size_Obj = ((PrtTblStateDsc*)pPrtTblStateDsc)-> size_ustuvannja_BS; 
			//.holderProxyPrtTblUnit.hldObjParam.p_ObjEntity = 
			//.((PrtTblStateDsc*)pPrtTblStateDsc)-> p_ustuvannja_BS;
			testPrtTblState.size_PrtTbl = ((PrtTblStateDsc*)pPrtTblStateDsc)-> size_PrtTbl;
			testPrtTblState.p_PrtTbl    = ((PrtTblStateDsc*)pPrtTblStateDsc)-> p_PrtTbl ;
			i =  SendPrtTblTbl();//ActivateProxyPrtTbl();
			if (i)
			i = START_EXEC;
			else
			i  = ERROR_EXEC;
			
		}

	}
	else
	{
		 i = hldPrTrptPrtTbl.hldrAcpuCMUnitState.AppObjConState;
		if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK |STT_STOP_OCS_MSK ))//RV_MODE_OCS_MSK
	    {
			//((ArTenPerStateDsc*)pArDataDsc)-> sizeAr      = 0;
			//((ArTenPerStateDsc*)pArDataDsc)-> pTenPerData = 0;
			
			i = STATE_EXEC;
		}
		else
		{
		    
			((PrtTblStateDsc*)pPrtTblStateDsc)-> size_PrtTbl      = //lSizeOf_PrtTbl;
			testPrtTblState.size_PrtTbl;
			((PrtTblStateDsc*)pPrtTblStateDsc)-> p_PrtTbl = 
			//(long*)&holderPrtTbl.UNPrtTbl.chArPrtTbl[0];
			testPrtTblState.p_PrtTbl;
			i  = ERROR_EXEC;
			//if (chStateAr10PerData != SUCCESS_EXEC)
			//i = chStateArPrtTblData;
			if( (hldPrTrptPrtTbl. arUchResultExecCmd[1] >0)
				&&(hldPrTrptPrtTbl. arUchResultExecCmd[1]<0x80)
			)
			{
				i =  SUCCESS_EXEC;
			}
			
		}
	
	}
	
	
	return i;

}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

static char chStateExecReqGetPrtTbl= 0;
long ReqGetPrtTblBMExample(void)  
{
	register long i=0;
	PrtTblStateDsc locPrtTblState;
if ( chStateExecReqGetPrtTbl== 0)
	{
		locPrtTblState.size_PrtTbl = testPrtTblState.size_PrtTbl;
		locPrtTblState. p_PrtTbl   = testPrtTblState.p_PrtTbl  ;
		i =   ReqGetPrtTblBM(1,&locPrtTblState);//
		if (i != ERROR_EXEC)
		{
			chStateExecReqGetPrtTbl= 1;//Start Execution
		}
		else chStateExecReqGetPrtTbl= 0;
	}
	if (chStateExecReqGetPrtTbl== 1 )
	{
		i =   ReqGetPrtTblBM(0,&locPrtTblState);//ReqGetSettingsBM
		switch(i)
		{
			case SUCCESS_EXEC:
			chStateExecReqGetPrtTbl= SUCCESS_EXEC;
			break;
			case ERROR_EXEC:
			i =   ReqGetPrtTblBM(1,&locPrtTblState);
			if (i== ERROR_EXEC)
			chStateExecReqGetPrtTbl= 0;
			else
			chStateExecReqGetPrtTbl= 1;
			break;
			
			default:
			;
		
		}
		
	
	}
	if (chStateExecReqGetPrtTbl== SUCCESS_EXEC)
	{
		;//See data
	}


return chStateExecReqGetPrtTbl;

}

static char chStateReqSendPrtTbl= 0;
long ReqSendPrtTblBMExample(void)  
{
	register long i=0;
	PrtTblStateDsc locPrtTblState;
if ( chStateReqSendPrtTbl== 0)
	{
		locPrtTblState.size_PrtTbl = testPrtTblState.size_PrtTbl;
		locPrtTblState. p_PrtTbl   = testPrtTblState.p_PrtTbl;   
		i =   ReqSendPrtTblBM(1,&locPrtTblState);//ReqGetSettingsBM
		if (i != ERROR_EXEC)
		{
			chStateReqSendPrtTbl= 1;//Start Execution
		}
		else chStateReqSendPrtTbl= 0;
	}
	if (chStateReqSendPrtTbl== 1 )
	{
		i =   ReqSendPrtTblBM(0,&locPrtTblState);//ReqGetSettingsBM
		switch(i)
		{
			case SUCCESS_EXEC:
			chStateReqSendPrtTbl= SUCCESS_EXEC;
			break;
			case ERROR_EXEC:
			i =   ReqSendPrtTblBM(1,&locPrtTblState);
			if (i== ERROR_EXEC)
			chStateReqSendPrtTbl= 0;
			else
			chStateReqSendPrtTbl= 1;
			break;
			
			default:
			;
		
		}
		
	
	}
	if (chStateReqSendPrtTbl== SUCCESS_EXEC)
	{
		;//See data
	}



	return chStateReqSendPrtTbl;


}
*/



unsigned int PrtTbl[SIZE_PRT>>2];//























