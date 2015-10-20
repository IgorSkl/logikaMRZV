
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
#include "NZOP1Component.c"

extern int GlobalPO1;
extern int GlobalPO2;
extern int GlobalPO3;
extern int GlobalPO4;

extern int GlobalLevel_UCM;
extern int GlobalLevel_ICM;

extern COMPONENT_OBJ  cnfCOMPONENT[];//конфигурация
extern int  logMassTimer[];
extern int  ENAcmd[];
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern int   WideCmdRTBuffer[];
extern int   tempLog[];
//сектора направл NZOP
extern int sectorNZOP1_V, sectorNZOP1_N, sectorNZOP2_V, sectorNZOP2_N;
extern int offsetSPVCmdPRM1;//смещение для SPV PRM1

//напр UCM меньше UCM005
//extern int  isFAILUCM005_COMMON;
//ток ICM  меньше ICM005
//extern int  isFAILICM005_COMMON;

void  logicNZOP1to2(int idxC) @ "Fast_function"
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

  int numC =    //номер клона
                cnfCOMPONENT[idxC].numClon-1;    

  detectorLevelUP(GlobalLevel_ICM,
                                     tmpOffsetUSpv+SPVSRABUST_ICM_NZOP1to2,
                                     tmpOffsetUSpv+SPVVOZVUST_ICM_NZOP1to2,
                                     tmpOffsetUSpv+SPV_OUT_ICM_NZOP1to2);
  detectorLevelUP(GlobalLevel_ICM,
                                     tmpOffsetUSpv+SPVSRABUST_ICM_NZOP1to2_V,
                                     tmpOffsetUSpv+SPVVOZVUST_ICM_NZOP1to2_V,
                                     tmpOffsetUSpv+SPV_OUT_ICM_NZOP1to2_V);
  detectorLevelUP(GlobalLevel_ICM,
                                     tmpOffsetUSpv+SPVSRABUST_ICM_NZOP1to2_N,
                                     tmpOffsetUSpv+SPVVOZVUST_ICM_NZOP1to2_N,
                                     tmpOffsetUSpv+SPV_OUT_ICM_NZOP1to2_N);

  detectorLevelUP(GlobalLevel_UCM,
                                     tmpOffsetUSpv+SPVSRABUST_UCM_NZOP1to2,
                                     tmpOffsetUSpv+SPVVOZVUST_UCM_NZOP1to2,
                                     tmpOffsetUSpv+SPV_OUT_UCM_NZOP1to2);
  detectorLevelUP(GlobalLevel_UCM,
                                     tmpOffsetUSpv+SPVSRABUST_UCM_NZOP1to2_V,
                                     tmpOffsetUSpv+SPVVOZVUST_UCM_NZOP1to2_V,
                                     tmpOffsetUSpv+SPV_OUT_UCM_NZOP1to2_V);
  detectorLevelUP(GlobalLevel_UCM,
                                     tmpOffsetUSpv+SPVSRABUST_UCM_NZOP1to2_N,
                                     tmpOffsetUSpv+SPVVOZVUST_UCM_NZOP1to2_N,
                                     tmpOffsetUSpv+SPV_OUT_UCM_NZOP1to2_N);

 int LocalPO_NZOP1to2 = SPV_UST(SPV_OUT_UCM_NZOP1to2) &
                        SPV_UST(SPV_OUT_ICM_NZOP1to2) & 
		//Простая\Направл NZOP
                (ENA_LOGIC(ENA_NZOP1to2_1)^1);

 int tmp_blok =               (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUT_UCM005)^1) &
                              (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUT_ICM005)^1);
 int LocalSector_NZOP1_V     = sectorNZOP1_V &
                               tmp_blok;
 int LocalSector_NZOP1_N     = sectorNZOP1_N &
                               tmp_blok;
 int LocalSector_NZOP2_V     = sectorNZOP2_V &
                               tmp_blok;
 int LocalSector_NZOP2_N     = sectorNZOP2_N &
                               tmp_blok;
 int LocalSector_V=0;
 int LocalSector_N=0;
  switch(numC){
    case 0:
     LocalSector_V= LocalSector_NZOP1_V;
     LocalSector_N= LocalSector_NZOP1_N;
    break;
    case 1:
     LocalSector_V= LocalSector_NZOP2_V;
     LocalSector_N= LocalSector_NZOP2_N;
    break;
  }//switch


 int LocalPO_NZOP1to2_V = SPV_UST(SPV_OUT_UCM_NZOP1to2_V) &
                          SPV_UST(SPV_OUT_ICM_NZOP1to2_V) &
                LocalSector_V &
		//Простая\Направл NZOP
                ENA_LOGIC(ENA_NZOP1to2_1) &
		//Вперед\Назад
		ENA_LOGIC(ENA_NZOP1to2_3);

 int LocalPO_NZOP1to2_N = SPV_UST(SPV_OUT_UCM_NZOP1to2_N) &
                          SPV_UST(SPV_OUT_ICM_NZOP1to2_N) &
                LocalSector_N &
		//Простая\Направл NZOP
                ENA_LOGIC(ENA_NZOP1to2_1) &
		//Вперед\Назад
		(ENA_LOGIC(ENA_NZOP1to2_3)^1);

    //*******NZOP1********
    int commonNZOP1 = 
                     //CMD1_NZOP1
                     (IO_LOGIC(IOCMD1_NZOP1to2)^1) &
                     ENA_LOGIC(ENA_NZOP1to2_2);// ENA_NZOP1;
                     
    //Сектор НЗОП1 ВПД
    IO_LOGIC(IOCMD6_NZOP1to2) =
                  commonNZOP1 &
                  LocalSector_V;
   //Сектор НЗОП1 НЗД
    IO_LOGIC(IOCMD7_NZOP1to2) = 
                  commonNZOP1 &
                  LocalSector_N;

//int tt1 =
    //L1 NZOP1
    LSIGNAL_TIMER(TIMER1_NZOP1to2)  = //NZOP1_TIM1
    //Сраб ПО НЗОП1
    IO_LOGIC(IOCMD2_NZOP1to2) =
                 commonNZOP1 &
                 //ПО НЗОП1
                 (GlobalPO1 | LocalPO_NZOP1to2) &
                 //NZOP1_PROSTAJA
                 (ENA_LOGIC(ENA_NZOP1to2_1)^1);

    //L2 NZOP1_V
    LSIGNAL_TIMER(TIMER2_NZOP1to2)  = //NZOP1_TIM2
    //NZOP1to2_PO2
  //  TL_LOGIC(TLCMD2_NZOP1to2) = 
    //Сраб ПО НЗОП1 ВПД
    IO_LOGIC(IOCMD3_NZOP1to2) =
                 commonNZOP1 &
                 //ПО НЗОП1 ВПД
                 (GlobalPO2 | LocalPO_NZOP1to2_V);// &
                 //NZOP1_NAPRAVL
//                 ENA_LOGIC(ENA_NZOP1to2_1);// &
                 //NZOP1 WPERED
//                 (ENA_LOGIC(ENA_NZOP1to2_3)^1);

    //L3 НЗОП1_N
    LSIGNAL_TIMER(TIMER3_NZOP1to2)  = //NZOP1_TIM3
    //NZOP1to2_PO3
//    TL_LOGIC(TLCMD3_NZOP1to2) = 
    //Сраб ПО НЗОП1 НЗД
    IO_LOGIC(IOCMD4_NZOP1to2) =
                 commonNZOP1 &
                 //ПО НЗОП2 НЗД
                 (GlobalPO3 | LocalPO_NZOP1to2_N);// & 
                 //NZOP1_NAPRAVL
//                 ENA_LOGIC(ENA_NZOP1to2_1);// &
                 //NZOP1 NAZAD
//                 ENA_LOGIC(ENA_NZOP1to2_3);

 int tmp = //L4
    LSIGNAL_TIMER(TIMER_BO_NZOP1to2)  = 
            PLOG_TIMER(TIMER1_NZOP1to2)| //NZOP1_TIM1
            PLOG_TIMER(TIMER2_NZOP1to2)| //NZOP1_TIM2
            PLOG_TIMER(TIMER3_NZOP1to2); //NZOP1_TIM3

    //Сраб НЗОП1
    IO_LOGIC(IOCMD5_NZOP1to2) =
          ILOG_TIMER(TIMER_BO_NZOP1to2)|tmp;
}//logicNZOP1to2(short idxC)


