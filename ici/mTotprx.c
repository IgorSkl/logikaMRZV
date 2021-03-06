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
* File Name       : mTotprx.c
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
void ActivateProxyTotMeas(void)
{
	register long i;
	i = ID_TOTAL_MEAS_UNIT;
	LDCIDsc hldLDCI;
    	
	//Emulate Receive Command
	//holderRV10PeriodCTpuUnit.RvCnHldr = 
	//holderRV10PeriodCTpuUnit.arUchRV  =
	
	hldLDCI.uchConMode     = 0; //unsigned char  uchConMode;
	hldLDCI.uchStartSesion = 0; //unsigned char  uchStartSesion;
	hldLDCI.uchTR_C        = 
	  SIZE_TPDU_TOT_MEAS_CNL_HSU2; //unsigned char  uchTR_C;//Size Transmit Data
	hldLDCI.NumComSes      = 0; //unsigned char  NumComSes;
	hldLDCI.IdConObj       = 
	  ID_TOTAL_MEAS_UNIT; //unsigned short IdConObj;
	//char *pSrc,*pDst;
	hldLDCI.pSrc       = (char*) holderRVTotMeasCTpuUnit.arUchRV;  
	//hldLDCI.pDst       =  holderProxyTenPerSamplesUnit.arUchRvParamCmd;
	//Control State Proxy if Now work Dont`t activate
	i = holderProxyTotMeasUnit.hldrAcpuCMUnitState.AppObjConState;
	if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK |STT_STOP_OCS_MSK ))
	return;
	ActivateRVProxyTotMeasCTpuUnit((void*)&hldLDCI,i);
}
//Activator Proxy
long ActivateRVProxyTotMeasCTpuUnit(void* pvLDC, long lID)
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
i = holderProxyTotMeasUnit.hldrAcpuCMUnitState.AppObjConState;
if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK |STT_STOP_OCS_MSK ))
return 0 ;//Error activation
//.pv = (void*)&holderRVSrcSamplesCTpuUnit.arUchRV[0];
pv = (void*)&(holderProxyTotMeasUnit.arUchRvParamCmd);
//.//((RVSrcSamplesCTpuUnitDsc*)pv )->
i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
 lID = 8;//((LDCIDsc*)pvLDC)->uchTR_C;
 pvLDC = (void*)i;
 
  for (i = 0; i < lID; i++)
  {
    ((char*)pv)[i] = ((char*)pvLDC)[i];
  }
  unnV1.uchAr[3] = lID;//Save amount Extract Data
  //Activate Proxy  Execution
  pv = (void*)&(holderProxyTotMeasUnit.hldrAcpuCMUnitState);
  i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
  i |= USING_OCS_MSK|STT_START_OCS_MSK;
  ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = i;
  //((BaseAcpuCMUnitDsc*)pv)->pf_Work         = WorkProxyTotMeas;
  //TestReqTransmitTotMeas++;
  
  //Clear All Ses Data
  i = 0;
  holderRV10PeriodCTpuUnit.RvCnHldr.uchUsedTransport = 0;
  holderRV10PeriodCTpuUnit.RvCnHldr.NumComSes        = 0;
  holderRV10PeriodCTpuUnit.RvCnHldr.ConState         = 0;
  holderRV10PeriodCTpuUnit.RvCnHldr.ulRvCount        = 0;
  holderTR10PeriodCTpuUnit.TrCnHldr.SizeAppObj       = 0;
//.  
//.  //Indicator data Transmit to Application
//.  //holderRVSrcSamplesCTpuUnit. TrCnHldr.pUchRV           = 0;
return lID;//
}
void ActivateServTrApCnTotMeasUnitHSU2(void)
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
//-  }
pv  = (void*)& holderProxyTotMeasUnit;
pch = (char *)((BaseAcpuCMUnitDsc*)pv)->pUchTR;//Base Addr Obj
i = ((BaseAcpuCMUnitDsc*)pv)->ulTrCount;//
j = ((BaseAcpuCMUnitDsc*)pv)->ulTrTotal;
   j -= i;
pch += i;//Addr Of Transmition
  //Reset Connect State
   pv  = (void*)& (holderTRTotMeasCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_HSU2;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_HSU2;// Logic can ctrl
   
   if( j> SIZE_TPDU_TOT_MEAS_CNL_HSU2)
   j = SIZE_TPDU_TOT_MEAS_CNL_HSU2;
   else
   {
	i++;//Debug Code for Logic Error Detection
   }
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = j;//sizeof(SrcSamplesUnitDsc);
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_TOTAL_MEAS_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)pch;
   //(unsigned char*)& holderTRSrcSamplesCTpuUnit.arUchTR;
   
}
void TerminateServiceApCnProxyTotMeas(void)
{
//register void *pv;
//register long i;
  
}
void PrepDecompouseTotMeasUnitHSU2(void)
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
	if(TestReqTransmitTotMeas)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_HSU2;j = SIZE_TPDU_TOT_MEAS_CNL_HSU2>>4;//If Channel full
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (TestReqTransmitTotMeas==START)
			{
				ActivateServTrApCnTotMeasUnitHSU2();
				TestReqTransmitTotMeas = EXEC;
			}
			//ProcessTransmit Obj
			if(TestReqTransmitTotMeas==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRTotMeasCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					TestReqTransmitTotMeas = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<5))//channel Full
				;//TestReqTransmitTotMeas = EXEC;//Activate Channel transmition and Set Zapret vizova ses poka ne otrabotaet chanel transmit LPU

				if (TestReqTransmitTotMeas==TERM)
				{
					//.TerminateServiceApCn((void*)& holderSrcSamplesUnit,ID_SRC_SAMPLES_UNIT);
					TerminateServiceApCnProxyTotMeas();
					TestReqTransmitTotMeas = 0;
				}
			}
		}
		//Try another???
		
	}
	

}
extern char chEndTransmitHSU2;
long InitProxyTotMeas (void* pv, long lV)
{
return 0; 
}
long WorkProxyTotMeas (void* pv, long lV)
{
register long i = 0;
register long j;
    if(lV == STT_START_OCS_ONB)
    {
        //Do SomeSing! for Init
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[0] = 1;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[1] = ACTIVATE_FILL_DATA;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[2] = RECIVE_FILL_DATA;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[3] = ACTIVATE_TRANSMIT_DATA;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[4] = TRANSMIT_FILL_DATA;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[5] = FREE_FILL_DATA;
		i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
		i |= STT_WORK_OCS_MSK;
		((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = i;	
		
		//Now it is all cmd
    	i = ExecCmdProxyTotMeas(pv,ACTIVATE_FILL_DATA);
		
    }
	if(lV == STT_WORK_OCS_ONB)
    {
       
	   i = ((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[0];//Pointer to Active Cmd
	   if (i==0)
	   return lV--;// ! Error
	   if (i<TOTAL_CMD)//Now Treshold for this Executor
	   {
	      j = ((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[i];//Load Command
		  //...((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[0] = 0;
	      lV = ExecCmdProxyTotMeas(pv,j);
		  if (lV==0)//Ok
		  ((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[0] = ++i;
	   }
	   else{
	   ((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[0] = 0;//Terminate Exec
	   }
    }
	if(lV == STT_STOP_OCS_ONB)
    {
        //Do SomeSing! for Init
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[0] = 0;//1;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[1] = 0;//ACTIVATE_FILL_DATA;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[2] = 0;//RECIVE_FILL_DATA;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[3] = 0;//ACTIVATE_TRANSMIT_DATA;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[4] = 0;//TRANSMIT_FILL_DATA;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[5] = 0;//FREE_FILL_DATA;
		i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
		i = 0;//AUX_OCS_MSK;//Reset State
		((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = i;	
		((BaseAcpuCMUnitDsc*)pv)-> ulRvCount  = 0;
		((BaseAcpuCMUnitDsc*)pv)-> ulTrCount  = 0;
		((BaseAcpuCMUnitDsc*)pv)-> ulRvTotal  = 0;
		((BaseAcpuCMUnitDsc*)pv)-> ulTrTotal  = 0;
		((BaseAcpuCMUnitDsc*)pv)-> pUchRV     = 0;
		((BaseAcpuCMUnitDsc*)pv)-> pUchTR     = 0;
		//Now it is all cmd
    	((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[0] = 0;
		((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[1] = 0;
		((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[2] = 0;
		((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[3] = 0;
		
    }

return i;
}
long ResetProxyTotMeas (void* pv, long lV)
{
return 0;
}
//#include "constants.h"
//extern unsigned int volatile command_to_receive_current_data;
//extern int current_data_transmit[NUMBER_CANALS*NUMBER_POINT*NUMBER_PERIOD_TRANSMIT]; 
//#include "libraries.h"
#include "constants.h"
#include "type_definition.h"
extern __TOTAL_MEASUREMENT total_measurement; 

extern int hs2_txsize, hs2_rxsize;
long ExecCmdProxyTotMeas (void* pv, long lV)
{
//register long i;
//register void* pv;
    
	if(lV == ACTIVATE_FILL_DATA)
    {
         lV = ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_WAITING_DATA_SAMPLES];
		 if (lV  == 0)		 
		 {
		    //Set Timer Activity
    		 ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_WAITING_DATA_SAMPLES] = VAL_WAITING_DATA_SAMPLES;
			 if ((command_to_receive_current_data&1)==0)
			 {
			    //command_to_receive_current_data |= 1;//Activation
				((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_WAITING_DATA_SAMPLES] = VAL_WAITING_DATA_SAMPLES;
				return 0;
			 }
			  return 1;
			
		 }
		 else
		 {
		    ;//Wait 
			lV = ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_WAITING_DATA_SAMPLES];
		    lV--; ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_WAITING_DATA_SAMPLES] = lV;
			if (lV ==0)
			{
				return 0;//Error
		    }
			else
			{
			    if (1)//Stub (command_to_receive_current_data&1)==0)
				{
				    ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_WAITING_DATA_SAMPLES] = VAL_WAITING_DATA_SAMPLES;
					//command_to_receive_current_data |= 1;//Activation
				    return 0;  
				}
			    return 1;//Wait
			}
		 }
		
		
    }
	if(lV == RECIVE_FILL_DATA )
    {
         //Load Or Update Transmit Proxy Parameters 
		  lV = ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_WAITING_DATA_SAMPLES];
		  lV--; ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_WAITING_DATA_SAMPLES] = lV;
		  
		 //Control Timer Activity
		if (lV ==0)
		{
			return 0;//Error
		}
		else
		{
		    if (1)//Complete formating Object (command_to_receive_current_data&1)==0)
				{
				    ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_WAITING_DATA_SAMPLES] = 0;
					//;//Dectivation
				    return 0;  
				}
			return 1;	
		
		}

    }
	
	if(lV == ACTIVATE_TRANSMIT_DATA )
    {
         //Load Or Update Transmit Proxy Parameters 
		((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING] = VAL_TRANSMITTING;
		 holderTRTotMeasCTpuUnit.TrCnHldr.SizeAppObj = 0;
		 
		pv  = (void*)& holderProxyTotMeasUnit;
		((BaseAcpuCMUnitDsc*)pv)->pUchTR = (unsigned char *) &total_measurement;//  current_data_transmit;//Base Addr Obj
		((BaseAcpuCMUnitDsc*)pv)->ulTrCount = 0;
		((BaseAcpuCMUnitDsc*)pv)->ulTrTotal = sizeof(total_measurement);//4*(NUMBER_CANALS*NUMBER_POINT*NUMBER_PERIOD_TRANSMIT);
	
		return 0;//Exex Action for Taras Array
    }
	
	if(lV == TRANSMIT_FILL_DATA )
    {
        ;//Add Here
		lV = ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING];
		lV--; ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING] = lV;
		if (lV ==0)
		{
		    //Error
			((BaseAcpuCMUnitDsc*)pv)-> AppObjConState |= STT_STOP_OCS_MSK;
			return 0;//Stop Transmittion
		}
		
		if((TestReqTransmitTotMeas==0)&&(hs2_txsize==0)
		&& hldrHSU2LpduTRUnit.uchLpuHSU2State== 0 ) //&&(chEndTransmitHSU2==0)-Ctrl Transmitting
		{
		    
			//lV =  holderTR10PeriodCTpuUnit.TrCnHldr.SizeAppObj;
			pv  = (void*)& holderProxyTotMeasUnit;
			lV = ((BaseAcpuCMUnitDsc*)pv)->ulTrCount;
			
			if (lV>= (((BaseAcpuCMUnitDsc*)pv)-> ulTrTotal))
			{
				((BaseAcpuCMUnitDsc*)pv)-> AppObjConState |= STT_STOP_OCS_MSK;
				return 0;//Stop Transmittion 
			}
			else 
			{
     			//ID_TEN_PERIOD_SAMPLES_UNIT;
				lV += holderTRTotMeasCTpuUnit.TrCnHldr.SizeAppObj;
				((BaseAcpuCMUnitDsc*)pv)->ulTrCount = lV;
				if (lV>= (((BaseAcpuCMUnitDsc*)pv)-> ulTrTotal))
				return 1;

			}
			 TestReqTransmitTotMeas = START;//Activate Sesion
			 //
			 hldrTpCnState.uchTpState_CNL_HSU2  = 1;//???
			 ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING] = VAL_TRANSMITTING;
			 //hldrTpCnState.PayloadLPDU_HSU2     = 0;//
			 //hldrTpCnState.lCapicity_CNL_HSU2   = SIZE_LPDU_CNL_HSU2
			 //-(SIZE_LPCI_FLD_CNL_HSU2+SIZE_LDC_FLD_CNL_HSU2+SIZE_CS_FLD_CNL_HSU2+SIZE_TOTAL_LDC );
			 //hldrTpCnState.pUchLpuTR_CNL_HSU2   = (unsigned char*)&hldrHSU2LpduTRUnit.arUch[SIZE_LPCI_FLD_CNL_HSU2+SIZE_LDC_FLD_CNL_HSU2+SIZE_TOTAL_LDC];//DemoStr;

			 
			 
			 
			 
		}
		else
		{
		    lV += hs2_txsize;
		}
		
		 
	   
	   	 return 1;//Exex Action for Taras Array
    }
	if(lV == FREE_FILL_DATA)
    {
       pv  = (void*)& holderProxyTotMeasUnit;
		((BaseAcpuCMUnitDsc*)pv)->pUchTR = 0;//Base Addr Obj
		((BaseAcpuCMUnitDsc*)pv)->ulTrCount = 0;
		((BaseAcpuCMUnitDsc*)pv)->ulTrTotal = 0;
		((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = 0;
		lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
		lV |= STT_STOP_OCS_MSK;
		((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = lV;
		//.((ProxyTenPerSamplesUnitDsc*)pv)->arU32LifeCtr[0] = 0;
		//.((ProxyTenPerSamplesUnitDsc*)pv)->arU32LifeCtr[1] = 0;
		//.((ProxyTenPerSamplesUnitDsc*)pv)->arU32LifeCtr[2] = 0;
		//.((ProxyTenPerSamplesUnitDsc*)pv)->arU32LifeCtr[3] = 0;
		//Clear Tran
		TestReqTransmitTotMeas=0;
	
	   return 0;//Exex Action for Taras Array
    }
	
	
return 0;
}







