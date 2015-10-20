
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
#include "MTZ2Component.c"

extern int GlobalPO1;//телеметрия
extern int GlobalPO2;//телеметрия
extern int GlobalPO3;//телеметрия
extern int GlobalPO4;//телеметрия
extern int GlobalLevelI_ABC[];//действ значения 3 фаз токов
extern int GlobalLevelUL_ABC[];//действ значения 3 фаз напр
//сектора направл МТЗ
extern int sectorMTZ_IA_V, sectorMTZ_IA_N;
extern int sectorMTZ_IB_V, sectorMTZ_IB_N;
extern int sectorMTZ_IC_V, sectorMTZ_IC_N;

extern COMPONENT_OBJ  cnfCOMPONENT[];//конфигурация
extern int  logMassTimer[];
extern int  ENAcmd[];
extern int offsetIOCmdPRM1;//смещение для IO PRM1
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern int   WideCmdRTBuffer[];
extern int   tempLog[];
//неисправность цепей напр 
extern int  isFAILU_COMMON_MTZ;
extern int offsetSPVCmdPRM1;//смещение для SPV PRM1

void  logicMTZ2to5(int idxC) @ "Fast_function"
{
//логика компонента

  int tmpOffsetT    =
    cnfCOMPONENT[idxC].offsetTimers;   //таймера компонента в конфигурации
  int tmpOffsetIO   =
    cnfCOMPONENT[idxC].offsetIOCmd;    //IO команды
  int tmpOffsetENA  =
    cnfCOMPONENT[idxC].offsetENACmd;   //ENA команды
  int tmpOffsetTL   =
    cnfCOMPONENT[idxC].offsetTLCmd;    //TL команды
  int tmpOffsetUSpv =
    cnfCOMPONENT[idxC].offsetUstSpv;    //уставки SPV


  detectorLevelUP3F(GlobalLevelI_ABC, tmpOffsetUSpv+SPVSRABUST_MTZ2to5,
                                      tmpOffsetUSpv+SPVVOZVUST_MTZ2to5,
                                      tmpOffsetUSpv+SPV_OUTA_MTZ2to5);

 //локальное ПО канала MTZ2to5
 int LocalPO_MTZ2to5 = SPV_UST(SPV_OUTA_MTZ2to5) |
                       SPV_UST(SPV_OUTB_MTZ2to5) |
                       SPV_UST(SPV_OUTC_MTZ2to5);

//неисправность цепей напр 

  detectorLevelUP3F(GlobalLevelI_ABC, tmpOffsetUSpv+SPVSRABUST_MTZ2to5_V,
                                      tmpOffsetUSpv+SPVVOZVUST_MTZ2to5_V,
                                      tmpOffsetUSpv+SPV_OUTA_MTZ2to5_V);

 //локальное ПО канала MTZ2to5_V
 int LocalPO_MTZ2to5_V = (
	                 (sectorMTZ_IA_V & 
                          SPV_UST(SPV_OUTA_MTZ2to5_V) &
                          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTA_U005)^1)
                          ) |
	                 (sectorMTZ_IB_V &
                          SPV_UST(SPV_OUTB_MTZ2to5_V) &
                          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTB_U005)^1)
                          )|
	                 (sectorMTZ_IC_V &
                          SPV_UST(SPV_OUTC_MTZ2to5_V) &
                          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTC_U005)^1)
                          )
                          );


  detectorLevelUP3F(GlobalLevelI_ABC, tmpOffsetUSpv+SPVSRABUST_MTZ2to5_N,
                                      tmpOffsetUSpv+SPVVOZVUST_MTZ2to5_N,
                                      tmpOffsetUSpv+SPV_OUTA_MTZ2to5_N);

 //локальное ПО канала MTZ2to5_N
 int LocalPO_MTZ2to5_N = (
	                 (sectorMTZ_IA_N & 
                          SPV_UST(SPV_OUTA_MTZ2to5_N) &
                          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTA_U005)^1)
                          ) |
	                 (sectorMTZ_IB_N &
                          SPV_UST(SPV_OUTB_MTZ2to5_N) &
                          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTB_U005)^1)
                          )|
	                 (sectorMTZ_IC_N &
                          SPV_UST(SPV_OUTC_MTZ2to5_N) &
                          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTC_U005)^1)
                          )
                          );

//MTZ2to5PN
//токи
  detectorLevelUP3F(GlobalLevelI_ABC, 
                                     tmpOffsetUSpv+SPVSRABUST_MTZ2to5_PN,
                                     tmpOffsetUSpv+SPVVOZVUST_MTZ2to5_PN,
                                     tmpOffsetUSpv+SPV_OUTA_MTZ2to5_PN);


//напряж
  detectorLevelDOWN3F(GlobalLevelUL_ABC,
                                     tmpOffsetUSpv+SPVSRABUST_MTZ2to5_UPN,
                                     tmpOffsetUSpv+SPVVOZVUST_MTZ2to5_UPN,
                                     tmpOffsetUSpv+SPV_OUTA_MTZ2to5_UPN);


//если одно из напряжений UA UB UC больше уставки то MTZ2to5_PN запрещается
 int LocalPO_MTZ2to5_PN = (
                          (SPV_UST(SPV_OUTA_MTZ2to5_PN) &
                           SPV_UST(SPV_OUTA_MTZ2to5_UPN)) |
                          (SPV_UST(SPV_OUTB_MTZ2to5_PN) &
                           SPV_UST(SPV_OUTB_MTZ2to5_UPN)) |
                          (SPV_UST(SPV_OUTC_MTZ2to5_PN) &
                           SPV_UST(SPV_OUTC_MTZ2to5_UPN))
                          );

#include "inc_uskmtz2.ci"
#include "inc_uskmtz2_v.ci"
#include "inc_uskmtz2_n.ci"
#include "inc_uskmtz2_pn.ci"


  //*******MTZ2********
  int commonMTZ2to5 =
    //CMD_MTZ2to5
    (IO_LOGIC(IOCMD1_MTZ2to5)^1) &
    ENA_LOGIC(ENA1_MTZ2to5);

   int locPO_MTZ2to5 = 
        commonMTZ2to5 &
        //ПО МТЗ2
        (GlobalPO1 | LocalPO_MTZ2to5)&
        //MTZ2to5_PROSTAJA
        (((ENA_LOGIC(ENA_MTZ2to5_HALF1) |
          ENA_LOGIC(ENA_MTZ2to5_HALF2))^1) |
                 //разрешить если все UL меньше 005
                  (
                     SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTA_U005) &
                     SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTB_U005) &
                     SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTC_U005)
                   ) |
                 //разрешить если НЦН
        //ELOUTTRG_NCN_MTZ2to5
        TL_LOGIC(TLCMDOUTNCN_MTZ2to5)
                  );

   int locPO_MTZ2to5_V = 
        commonMTZ2to5 &
        //ПО МТЗ2 ВПД
        (GlobalPO2 | LocalPO_MTZ2to5_V)&
        //MTZ2to5_NAPRAVL
        ENA_LOGIC(ENA_MTZ2to5_HALF1) &
        //MTZ2to5 WPERED
        ENA_LOGIC(ENA2_MTZ2to5) &
        //ELOUTTRG_NCN_MTZ2to5
        (TL_LOGIC(TLCMDOUTNCN_MTZ2to5)^1);

   int locPO_MTZ2to5_N = 
        commonMTZ2to5 &
        //ПО МТЗ2 НЗД
        (GlobalPO3 | LocalPO_MTZ2to5_N)&
        //MTZ1_NAPRAVL
        ENA_LOGIC(ENA_MTZ2to5_HALF1) &
        //MTZ1 NAZAD
        ENA_LOGIC(ENA3_MTZ2to5) &
        //ELOUTTRG_NCN_MTZ2to5
        (TL_LOGIC(TLCMDOUTNCN_MTZ2to5)^1);

   int locPO_MTZ2to5_PN = 
        commonMTZ2to5 &
        //ПО МТЗ2 ПН
        (GlobalPO4 | LocalPO_MTZ2to5_PN)&
        //MTZ2to5_PUSKN
        ENA_LOGIC(ENA_MTZ2to5_HALF2) &
        //ELOUTTRG_NCN_MTZ2to5
        (TL_LOGIC(TLCMDOUTNCN_MTZ2to5)^1);

 tmp1 =
    locPO_MTZ2to5_V  |
    locPO_MTZ2to5_N  |
    locPO_MTZ2to5_PN; 

//триг по восх фронту
//TRG_FRONT(set, clr, old, out)
//                                    ELOLDTRG_NCN_MTZ2to5  ELOUTTRG_NCN_MTZ2to5
  TRG_FRONT(tmp1, isFAILU_COMMON_MTZ, TLCMDOLDNCN_MTZ2to5, TLCMDOUTNCN_MTZ2to5)

  locPO_MTZ2to5_V &=
        //ELOUTTRG_NCN_MTZ2to5
        (TL_LOGIC(TLCMDOUTNCN_MTZ2to5)^1);

  locPO_MTZ2to5_N &=
        //ELOUTTRG_NCN_MTZ2to5
        (TL_LOGIC(TLCMDOUTNCN_MTZ2to5)^1);

  locPO_MTZ2to5_PN &=
        //ELOUTTRG_NCN_MTZ2to5
        (TL_LOGIC(TLCMDOUTNCN_MTZ2to5)^1);

   tmp1 =
    //L1
    //MTZ2to5_PO1
    TL_LOGIC(TLCMD5_MTZ2to5) =
      //Сраб ПО МТЗ2
      //CMD_MTZ2to5_PO1
      IO_LOGIC(IOCMD4_MTZ2to5) =
      locPO_MTZ2to5;

  //L5
//  int tmp =
     //MTZ2to5_TIM1
  LSIGNAL_TIMER(TIMER1_MTZ2to5)  = 
    //RES_MTZ2to5
    TL_LOGIC(TLCMD1_MTZ2to5) & tmp1;

  //дельта таймера MTZ2to5_TIM1
  TL_LOGIC(TL10_MTZ2TO5) = IS_TIMER_DELTA12(TIMER1_MTZ2to5)^1;   

  tmp2 =
    //L2
    //MTZ2to5_PO2
    TL_LOGIC(TLCMD6_MTZ2to5) =
      //Сраб ПО МТЗ2 ВПД
      //CMD_MTZ2to5_PO2
      IO_LOGIC(IOCMD5_MTZ2to5) =
      locPO_MTZ2to5_V;

  //L6
  //tmp =
  //MTZ2to5_TIM2
  LSIGNAL_TIMER(TIMER2_MTZ2to5)  =
    //RES_MTZ2to5_V
    TL_LOGIC(TLCMD2_MTZ2to5) & tmp2;

  //проверка таймера MTZ2to5_TIM2
  TL_LOGIC(TL10_MTZ2TO5_V) = IS_TIMER_DELTA12(TIMER2_MTZ2to5)^1;   

  int tmp3 =
    //L3
    //MTZ2to5_PO3
    TL_LOGIC(TLCMD7_MTZ2to5) =
      //Сраб ПО МТЗ2 НЗД
      //CMD_MTZ2to5_PO3
      IO_LOGIC(IOCMD6_MTZ2to5) =
      locPO_MTZ2to5_N;

  //tmp =
  //MTZ2to5_TIM3
  LSIGNAL_TIMER(TIMER3_MTZ2to5)  =
    //RES_MTZ2to5_N
    TL_LOGIC(TLCMD3_MTZ2to5) & tmp3;//L7

  //проверка таймера MTZ2to5_TIM3
  TL_LOGIC(TL10_MTZ2TO5_N) = IS_TIMER_DELTA12(TIMER3_MTZ2to5)^1;   

  tmp4 =
    //L4
    //MTZ2to5_PO4
    TL_LOGIC(TLCMD8_MTZ2to5) =
      //Сраб ПО МТЗ2 ПН
      //CMD_MTZ2to5_PO4
      IO_LOGIC(IOCMD7_MTZ2to5) =
      locPO_MTZ2to5_PN;

  //tmp =
  //MTZ2to5_TIM4
  LSIGNAL_TIMER(TIMER4_MTZ2to5)  =
    //RES_MTZ2to5_PN
    TL_LOGIC(TLCMD4_MTZ2to5) & tmp4;//L8

  //проверка таймера MTZ2to5_TIM4
  TL_LOGIC(TL10_MTZ2TO5_PN) = IS_TIMER_DELTA12(TIMER4_MTZ2to5)^1;   

  //L9
  tmp1 = 
         PLOG_TIMER(TIMER1_MTZ2to5)| //MTZ2to5_TIM1
         PLOG_TIMER(TIMER2_MTZ2to5)| //MTZ2to5_TIM2
         PLOG_TIMER(TIMER3_MTZ2to5)| //MTZ2to5_TIM3
         PLOG_TIMER(TIMER4_MTZ2to5); //MTZ2to5_TIM4

  //L10
  int tmp = LSIGNAL_TIMER(TIMER_BO_MTZ2to5)  =
              //MTZ2to5_USKOR
              TL_LOGIC(TLCMD15_MTZ2to5) |
              //MTZ2to5_V_USKOR
              TL_LOGIC(TLCMD15_MTZ2to5_V) |
              //MTZ2to5_N_USKOR
              TL_LOGIC(TLCMD15_MTZ2to5_N) |
              //MTZ2to5_PN_USKOR
              TL_LOGIC(TLCMD15_MTZ2to5_PN) |
              tmp1;

  //Сраб МТЗ2
  //CMD_MTZ2to5
  IO_LOGIC(IOCMD8_MTZ2to5) =
    ILOG_TIMER(TIMER_BO_MTZ2to5)|tmp;

}//logicMTZ2to5(short idxC)
