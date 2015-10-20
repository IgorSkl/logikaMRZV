
#include "bazisdef.h"
#include "component\componentdef.h"
#include "psuperVisor\psvisor_helpdef.h"

#include "logictimers\logictimersmac.h"

#include "logictimers\logictimersfnc.h"

#include "..\bazis.h"

#include "toSpeedOptim.h"

#define _HIDE_COMPONENT
#include "PRM1Component.c"
#include "APVComponent.c"

extern int GlobalPO1;
extern int GlobalPO2;
extern int GlobalPO3;
extern int GlobalPO4;
extern int GlobalLevelUF_ABC[];
extern int GlobalLevelUL_ABC[];
extern int GlobalLevel_ULAPV;

extern COMPONENT_OBJ  cnfCOMPONENT[];//конфигурация
extern int  logMassTimer[];
extern int  ENAcmd[];
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern int   WideCmdRTBuffer[];
extern int   tempLog[];
extern int offsetIOCmdPRM1;//смещение для IO PRM1
//глобальный сброс всех таймеров
extern int  globalTimerReset;
extern int puskAPV;
//Синхронизация АПВ
extern int speed_angle_APV;
extern int angle_unbalance_APV;
extern int voltage_difference_APV;


void  logicAPV(int idxC) @ "Fast_function"
{
  //return;//123456
  
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

  //БЕЗ КОНТРОЛЯ
  int ENA_BK = (ENA_LOGIC(ENA_APV_HALF1)|
                ENA_LOGIC(ENA_APV_HALF2)|
                ENA_LOGIC(ENA_APV_HALF3)
               )^1;
  //НЕТ ЛИНИИ ЕСТЬ ШИНА
  int ENA_OL_NC = ((ENA_LOGIC(ENA_APV_HALF1)^1)|
                    ENA_LOGIC(ENA_APV_HALF2)|
                    ENA_LOGIC(ENA_APV_HALF3)
                  )^1;
  //ЕСТЬ ЛИНИЯ НЕТ ШИНЫ
  int ENA_NL_OC = ( ENA_LOGIC(ENA_APV_HALF1)|
                   (ENA_LOGIC(ENA_APV_HALF2)^1)|
                    ENA_LOGIC(ENA_APV_HALF3)
                  )^1;
  //ЕСТЬ ЛИНИЯ ЕСТЬ ШИНА НЕТ СИН
  int ENA_NL_NC_BS = ((ENA_LOGIC(ENA_APV_HALF1)^1)|
                      (ENA_LOGIC(ENA_APV_HALF2)^1)|
                       ENA_LOGIC(ENA_APV_HALF3)
                     )^1;
  //ЕСТЬ ЛИНИЯ ЕСТЬ ШИНА ЕСТЬ СИН
  int ENA_NL_NC_NS = ( ENA_LOGIC(ENA_APV_HALF1)|
                       ENA_LOGIC(ENA_APV_HALF2)|
                      (ENA_LOGIC(ENA_APV_HALF3)^1)
                     )^1;


  //Faza A
  int ENA_FA = (ENA_LOGIC(ENA_APV_HALF4)|
                ENA_LOGIC(ENA_APV_HALF5)
               )^1;
  //Faza B
  int ENA_FB = ((ENA_LOGIC(ENA_APV_HALF4)^1)|
                 ENA_LOGIC(ENA_APV_HALF5)
                  )^1;
  //Faza C
  int ENA_FC = ( ENA_LOGIC(ENA_APV_HALF4)|
                (ENA_LOGIC(ENA_APV_HALF5)^1)
                  )^1;

  detectorLevelUP3F(GlobalLevelUF_ABC,
                                     tmpOffsetUSpv+SPVSRABUST_PO1_APV,
                                     tmpOffsetUSpv+SPVVOZVUST_PO1_APV,
                                     tmpOffsetUSpv+SPV_OUT1A_APV);

  detectorLevelDOWN3F(GlobalLevelUF_ABC,
                                     tmpOffsetUSpv+SPVSRABUST_PO2_APV,
                                     tmpOffsetUSpv+SPVVOZVUST_PO2_APV,
                                     tmpOffsetUSpv+SPV_OUT2A_APV);

  detectorLevelUP(GlobalLevel_ULAPV,
                                     tmpOffsetUSpv+SPVSRABUST_PO3_APV,
                                     tmpOffsetUSpv+SPVVOZVUST_PO3_APV,
                                     tmpOffsetUSpv+SPV_OUT3_APV);

  detectorLevelDOWN(GlobalLevel_ULAPV,
                                     tmpOffsetUSpv+SPVSRABUST_PO4_APV,
                                     tmpOffsetUSpv+SPVVOZVUST_PO4_APV,
                                     tmpOffsetUSpv+SPV_OUT4_APV);

 int LocalPO1_APV = SPV_UST(SPV_OUT1A_APV) &
                    SPV_UST(SPV_OUT1B_APV) &
                    SPV_UST(SPV_OUT1C_APV);

 //  int tt1= SPV_UST(SPV_OUT1A_APV);
//   int tt2= SPV_UST(SPV_OUT1B_APV);
  // int tt3= SPV_UST(SPV_OUT1C_APV);

 int LocalPO2_APV = SPV_UST(SPV_OUT2A_APV) &
                    SPV_UST(SPV_OUT2B_APV) &
                    SPV_UST(SPV_OUT2C_APV);

 int LocalPO3_APV = SPV_UST(SPV_OUT3_APV);
 int LocalPO4_APV = SPV_UST(SPV_OUT4_APV);

//Синхронизация АПВ 
if(voltage_difference_APV<0) voltage_difference_APV = -voltage_difference_APV;
  detectorLevelDOWN(voltage_difference_APV,
                                     tmpOffsetUSpv+SPVSRABUST_POVD_APV,
                                     tmpOffsetUSpv+SPVVOZVUST_POVD_APV,
                                     tmpOffsetUSpv+SPV_OUT_POVD_APV);

//   int tt1 = SPV_UST(SPVSRABUST_POVD_APV);
//   int tt2 = SPV_UST(SPVVOZVUST_POVD_APV);
//   int tt3 = SPV_UST(SPV_OUT_POVD_APV);

//angle_unbalance
if(angle_unbalance_APV<0) angle_unbalance_APV = -angle_unbalance_APV;
  detectorLevelDOWN(angle_unbalance_APV,
                                     tmpOffsetUSpv+SPVSRABUST_POAU_APV,
                                     tmpOffsetUSpv+SPVVOZVUST_POAU_APV,
                                     tmpOffsetUSpv+SPV_OUT_POAU_APV);

//speed_angle
  detectorLevelDOWN(speed_angle_APV,
                                     tmpOffsetUSpv+SPVSRABUST_POSA_APV,
                                     tmpOffsetUSpv+SPVVOZVUST_POSA_APV,
                                     tmpOffsetUSpv+SPV_OUT_POSA_APV);

  //int tt1 = SPV_UST(SPVSRABUST_POAU_APV);
 // int tt2 = SPV_UST(SPVVOZVUST_POAU_APV);
 // int tt4 = SPV_UST(SPV_OUT_POAU_APV);
 // int tt5 = SPV_UST(SPV_OUT_POVD_APV);
  
 int LocalSYNCHR_APV = SPV_UST(SPV_OUT_POVD_APV) &
                       SPV_UST(SPV_OUT_POAU_APV) ;
  //                     SPV_UST(SPV_OUT_POSA_APV);

 //  int tt3 = SPV_UST(SPVVOZVUST_POSA_APV);

//  int tt1 = IO_LOGIC(IOCMD2_APV);
 // if(tt1){
  //  tt1=0;
 // }
//  int tt1 = ENA_LOGIC(ENA_APV_1);
//  int tt2 = ENA_LOGIC(ENA_APV_2);

#include "inc_apv2.ci"
#include "inc_apv1.ci"
#include "inc_apv3_1.ci"
#include "inc_apv3_2.ci"

//  int tt1 = IO_LOGIC(IOCMD2_APV);
//  if(tt1){
//    tt1=0;
//  }
  
//   tt1 = IO_LOGIC(IOCMD4_APV);
//  if(tt1){
//    tt1=0;
//  }
  
  //L13
  //BVCMD_APV1
  TL_LOGIC(TLCMD11_APV) =
       tmp1 |
       tmp2 |
       tmp3 |
       tmp4 |
       tmp5;

#include "inc_apv4_1.ci"
#include "inc_apv4_2.ci"

  //L13
  //BVCMD_APV2
  TL_LOGIC(TLCMD12_APV) =
       tmp1 |
       tmp2 |
       tmp3 |
       tmp4 |
       tmp5;

}//logicAPV(short idxC)

