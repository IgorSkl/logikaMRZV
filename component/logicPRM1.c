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

extern int GlobalPO1;
extern int GlobalPO2;
extern int GlobalPO3;
extern int GlobalPO4;
extern int GlobalLevelI_ABC[];

extern COMPONENT_OBJ  cnfCOMPONENT[];//конфигурация
extern int  logMassTimer[];
extern int  ENAcmd[];
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern int  WideCmdRTBuffer[];
//неисправность цепей напр
extern int  isFAILU_COMMON_DZ;
extern int  isFAILU_DZ;
extern int GlobalLevel_UCM;
extern int GlobalLevel_ICM;

extern int timing;  
extern int timingLoad;  
extern int cicling;  

extern int zapusk_permanent;//запуск перманентного таймера
extern int zapusk_permanent_old;//запуск перманентного таймера
extern int reset_bv;//сброс блока включения от защит

void  logicPRM1(int idxC) @ "Fast_function"
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

 zapusk_permanent ++;//запуск перманентного таймера
//int zapusk_permanent_old=0;//запуск перманентного таймера
 if(zapusk_permanent>1000) zapusk_permanent =0;

  LSIGNAL_TIMER(TIMER1_PRM1)  = 1;//ОФункция
   // IO_LOGIC(IOCMD1_PRM1);//вход

int tt1 =
  IO_LOGIC(IOCMD6_PRM1) = //выход
//    ObrOFUNCTION(tmpOffsetT + TIMER1_PRM1);
   OFunction(tmpOffsetT + TIMER1_PRM1, 0);

//напр UCM больше 20V
  detectorLevelUP(GlobalLevel_UCM, tmpOffsetUSpv+SPVSRAB_DZ_02UH,
                                   tmpOffsetUSpv+SPVVOZV_DZ_02UH,
                                   tmpOffsetUSpv+SPV_OUT_DZ_02UH);
//(UCM/577)/(ICM/50)>0.2
//500*UCM>2*577*ICM
//  int ttt2 =
  SPV_UST(SPV_DZ_UCMICM) = 2*577*GlobalLevel_ICM;
  //int ttt3 =
//  500*GlobalLevel_UCM;
  detectorLevelUP(500*GlobalLevel_UCM, tmpOffsetUSpv+SPV_DZ_UCMICM,
                                     tmpOffsetUSpv+SPV_DZ_UCMICM,
                                     tmpOffsetUSpv+SPV_OUT_DZ_UCMICM);

  //UI НЦН ДЗ
  LSIGNAL_TIMER(TIMER_UINCNDZ_PRM1) = isFAILU_COMMON_DZ; 
  //05 НЦН ДЗ
  LSIGNAL_TIMER(TIMER_05NCNDZ_PRM1)  = SPV_UST(SPV_OUT_DZ_02UH);
  
//  int ttt1 =
  //UCM НЦН ДЗ
  LSIGNAL_TIMER(TIMER_CMNCNDZ_PRM1) = SPV_UST(SPV_OUT_DZ_UCMICM);

  //неисправность цепей напр
  isFAILU_DZ =
///*
        (
        //UCM НЦН ДЗ
        SPV_UST(SPV_OUT_DZ_UCMICM) &
        //05 НЦН ДЗ
        PLOG_TIMER(TIMER_05NCNDZ_PRM1)
        ) |
//*/
///*
        (
        //UI НЦН ДЗ
        PLOG_TIMER(TIMER_UINCNDZ_PRM1)
         )
         |
//*/
///*
         (
        //UCM НЦН ДЗ
        PLOG_TIMER(TIMER_CMNCNDZ_PRM1)
          ); 
//*/

  isFAILU_DZ &=
        //разрешить неисправность цепей напр DZ
         ENA_LOGIC(ENA_PRM1_FAILU_DZ);
  //CMD_FAULT_U_DZ
  IO_LOGIC(IOCMD2_PRM1) = isFAILU_DZ;

//формирование Привод ВВ
//L1
 //привод ВВ
  LSIGNAL_TIMER(TIMER_PRIVODVV_PRM1) =
        //L1 L2
       //Контроль Вкл         //Контроль Откл
        (IO_LOGIC(IOCMD8_PRM1)  ^ IO_LOGIC(IOCMD9_PRM1))^1;

//L3
   //Привод ВВ
  IO_LOGIC(IOCMD14_PRM1) = 
                  //привод ВВ
        PLOG_TIMER(TIMER_PRIVODVV_PRM1) &
         //Контроль ВВ
         ENA_LOGIC(ENA_PRM1_KONTROLVV);

//   IO_LOGICOUT(offsetIOCmdPRM1 +IOCMD12_PRM1);

  //формирователь блокировки Блока включения
  LSIGNAL_TIMER(TIMER_BLOKIRBLOKVKL_PRM1) = 
         //положение ВВ
	  IO_LOGIC(IOCMD1_PRM1);//CMD_POL_VV

           //сброс блока включения
  SPV_UST(SPV_RESET_BV) = 
          //сброс блока включения от защит
	  reset_bv |
	  //Блокировка включения ВВ
	  IO_LOGIC(IOCMD12_PRM1) |
	  //удленнение блокировки блока включения
	  ILOG_TIMER(TIMER_DELAYBLOKIRBLOKVKL_PRM1) |
          (
	  //формирователь блокировки Блока включения
	  FLOG_TIMER(TIMER_BLOKIRBLOKVKL_PRM1) &
	  //задержка включения ВВ
	  ENA_LOGIC(ENA_PRM1_ZADWKLVV)
          );


		//Вкл ВВ
  LSIGNAL_TIMER(TIMER_VKLVV_PRM1) = IO_LOGIC(IOCMD7_PRM1);
  IO_LOGIC(IOCMD7_PRM1) = FLOG_TIMER(TIMER_VKLVV_PRM1);
		//Откл ВВ
  LSIGNAL_TIMER(TIMER_OTKLVV_PRM1) = IO_LOGIC(IOCMD3_PRM1);
  IO_LOGIC(IOCMD3_PRM1) = FLOG_TIMER(TIMER_OTKLVV_PRM1);

int tt2 = tmpOffsetT + TIMER1_PRM1;

if(tt1){
      int tt0 = timingLoad;  
      int tt1 = timing;  
      int tt2 = cicling;  
    tt1=2;
  }//if


}//logicPRM1(short idxC)
