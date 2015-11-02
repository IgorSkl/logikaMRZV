

#include <stdio.h>
#include <string.h>

#include "bazisdef.h"
#include "component\componentdef.h"
#include "psuperVisor\psvisor_helpdef.h"

#include "logictimers\logictimersmac.h"

#include "logictimers\logictimersfnc.h"

#include "..\bazis.h"

#include "toSpeedOptim.h"

#define _HIDE_COMPONENT
#include "PRM1Component.c"
#include "TZNP1Component.c"

extern int GlobalPO1;
extern int GlobalPO2;
extern int GlobalPO3;
extern int GlobalPO4;
//extern int GlobalLevelI_ABC[];
extern int GlobalLevel_3I0;
extern int GlobalLevel_3U0;

extern COMPONENT_OBJ  cnfCOMPONENT[];//конфигурация
extern int  logMassTimer[];
extern int  ENAcmd[];
extern int   WideCmdRTBuffer[];
extern int   tempLog[];
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern int offsetIOCmdPRM1;//смещение для IO PRM1

//сектора направл TZNP
extern int sectorTZNP1, sectorTZNP2, sectorTZNP3, sectorTZNP4, sectorTZNP5;

void  logicTZNP1to5(int idxC) @ "Fast_function"
{
//логика компонента

    int tmpOffsetT    =
                cnfCOMPONENT[idxC].offsetTimers;   //таймера компонента в конфигурации
    int tmpOffsetIO   =
                cnfCOMPONENT[idxC].offsetIOCmd;    //IO команды
    int tmpOffsetENA  =
                cnfCOMPONENT[idxC].offsetENACmd;    //ENA команды
    int tmpOffsetUSpv =
                cnfCOMPONENT[idxC].offsetUstSpv;    //уставки SPV
    int tmpOffsetTL   =
                cnfCOMPONENT[idxC].offsetTLCmd;    //TL команды

  int numClon =    //номер клона
                cnfCOMPONENT[idxC].numClon;    

//сектора направл TZNP
 int sectorTZNP =0;
 switch(numClon)
	{
	 case 1: 
               sectorTZNP =sectorTZNP1;
               break;
	 case 2: 
               sectorTZNP =sectorTZNP2;
               break;
	 case 3: sectorTZNP =sectorTZNP3;break;
	 case 4: sectorTZNP =sectorTZNP4;break;
	 case 5: sectorTZNP =sectorTZNP5;break;
	default:;
	}//switch

 if(ENA_LOGIC(ENA4_TZNP1to5)==0 && sectorTZNP==1) sectorTZNP=0;
 if(ENA_LOGIC(ENA4_TZNP1to5)==0 && sectorTZNP==2) sectorTZNP=1;

 if(ENA_LOGIC(ENA4_TZNP1to5)==1 && sectorTZNP==1) sectorTZNP=1;
 if(ENA_LOGIC(ENA4_TZNP1to5)==1 && sectorTZNP==2) sectorTZNP=0;

  detectorLevelUP(GlobalLevel_3I0,
                                     tmpOffsetUSpv+SPVSRABUST_TZNP1to5_3I0,
                                     tmpOffsetUSpv+SPVVOZVUST_TZNP1to5_3I0,
                                     tmpOffsetUSpv+SPV_OUT3I0_TZNP1to5);

   
  detectorLevelUP(GlobalLevel_3U0,
                                     tmpOffsetUSpv+SPVSRABUST_TZNP1to5_3U0,
                                     tmpOffsetUSpv+SPVVOZVUST_TZNP1to5_3U0,
                                     tmpOffsetUSpv+SPV_OUT3U0_TZNP1to5);

  
 int LocalPO_3I0 = SPV_UST(SPV_OUT3I0_TZNP1to5);
 int LocalPO_3U0 = SPV_UST(SPV_OUT3U0_TZNP1to5);
 int LocalPO_3I03U0 = 
                   SPV_UST(SPV_OUT3U0_TZNP1to5) &
                   SPV_UST(SPV_OUT3I0_TZNP1to5) &
		//сектора направл TZNP
		sectorTZNP;

#include "inc_usktznp1.ci"
#include "inc_usktznp1_3i0.ci"

  //*******TZNP1********
  int commonTZNP1to5 =
    //CMD_TZNP1to5
    (IO_LOGIC(IOCMD1_TZNP1to5)^1);
//    ENA_LOGIC(ENA1_MTZ2to5);


    //L1
  tmp1 =
    //TZNP1to5_PO1
    TL_LOGIC(TLCMD1_TZNP1to5) =
      //Сраб ПО ТЗНП1
      //CMD_TZNP1to5_PO1
      IO_LOGIC(IOCMD4_TZNP1to5) =
        commonTZNP1to5 &
        //ПО ТЗНП1
        (GlobalPO1 | LocalPO_3I03U0) &
        //ENA_TZNP1to5
        ENA_LOGIC(ENA1_TZNP1to5);


  //L4
  //TZNP1to5_TIM1
  LSIGNAL_TIMER(TIMER1_TZNP1to5)  = 
    //RES_TZNP1to5
    TL_LOGIC(TLCMD6_TZNP1to5) &
    tmp1;

  //дельта таймера TZNP1to5_TIM1
  TL_LOGIC(TL10_TZNP1TO5) = IS_TIMER_DELTA12(TIMER1_TZNP1to5)^1;

    //L2
  tmp2 =
    //TZNP1to5_PO2
    TL_LOGIC(TLCMD2_TZNP1to5) =
      //Сраб ПО ТЗНП1 3I0
      //CMD_TZNP1to5_PO2
      IO_LOGIC(IOCMD6_TZNP1to5) =
        commonTZNP1to5 &
        //ПО ТЗНП1 3I0
        (GlobalPO2 | LocalPO_3I0) &
        //TZNP1to5_3I0
        ENA_LOGIC(ENA2_TZNP1to5);

  //L5
  //TZNP1to5_TIM2
  LSIGNAL_TIMER(TIMER2_TZNP1to5)  =
    //RES_TZNP1to5_3I0
    TL_LOGIC(TLCMD6_TZNP1to5_3I0) &
    tmp2;

  //дельта таймера TZNP1to5_TIM1
  TL_LOGIC(TL10_TZNP1TO5_3I0) = IS_TIMER_DELTA12(TIMER2_TZNP1to5)^1;

    //L3
    //TZNP1to5_PO3
    TL_LOGIC(TLCMD3_TZNP1to5) =
    //TZNP1to5_TIM3
    LSIGNAL_TIMER(TIMER3_TZNP1to5)  =
      //Сраб ПО ТЗНП1 3U0
      //CMD_TZNP1to5_PO3
      IO_LOGIC(IOCMD8_TZNP1to5) =
        commonTZNP1to5 &
        //ПО ТЗНП1 3U0
        (GlobalPO3 | LocalPO_3U0) &
        //TZNP1to5 3U0
        ENA_LOGIC(ENA3_TZNP1to5);

  //L6
  int tmp = LSIGNAL_TIMER(TIMER_BO_TZNP1to5)  =
              //TZNP1to5_USKOR
              TL_LOGIC(TLCMD4_TZNP1to5) |
              //TZNP1to5_TIM1
              PLOG_TIMER(TIMER1_TZNP1to5);
  
  //Сраб ТЗНП1
  //CMD_TZNP1to5
  IO_LOGIC(IOCMD5_TZNP1to5) =
    ILOG_TIMER(TIMER_BO_TZNP1to5)|tmp;

  //L7
  tmp = LSIGNAL_TIMER(TIMER_BO_TZNP1to5_3I0)  =
              //TZNP1to5_3I0_USKOR
              TL_LOGIC(TLCMD4_TZNP1to5_3I0) |
              //TZNP1to5_TIM2
              PLOG_TIMER(TIMER2_TZNP1to5);

  //Сраб ТЗНП1 3I0
  //CMD_TZNP1to5_3I0
  IO_LOGIC(IOCMD7_TZNP1to5) =
    ILOG_TIMER(TIMER_BO_TZNP1to5_3I0)|tmp;

  tmp = LSIGNAL_TIMER(TIMER_BO_TZNP1to5_3U0)  =
              //TZNP1to5_TIM3
              PLOG_TIMER(TIMER3_TZNP1to5);

  //Сраб ТЗНП1 3U0
  //CMD_TZNP1to5_3U0
  IO_LOGIC(IOCMD9_TZNP1to5) =
    ILOG_TIMER(TIMER_BO_TZNP1to5_3U0)|tmp;

}//logicTZNP1to5(short idxC)

