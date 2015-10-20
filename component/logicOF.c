
#include <stdio.h>
#include <string.h>

#include "psuperVisor\supermanager.h"

#include "bazisdef.h"
#include "component\componentdef.h"
#include "psuperVisor\psvisor_helpdef.h"

#include "logictimers\logictimersmac.h"

#include "logictimers\logictimersfnc.h"

#include "..\bazis.h"

#include "toSpeedOptim.h"

#define _HIDE_COMPONENT
#include "OFComponent.c"

extern int GlobalPO1;
extern int GlobalPO2;
extern int GlobalPO3;
extern int GlobalPO4;
extern int GlobalLevelI_ABC[];

extern COMPONENT_OBJ  cnfCOMPONENT[];//конфигурация
extern int  logMassTimer[];
extern int  ENAcmd[];
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern int   WideCmdRTBuffer[];
extern int   tempLog[];

extern COMPONENT_OBJ  cnfCOMPONENT_WL[];//конфигурация
extern int  logMassTimer_WL[];
extern int  ENAcmd_WL[];
extern int  spvUSTAVKI_WL[];//текущие уставки супервизора
extern int   tempLog_WL[];

extern int offsetIOCmdPRM1;//смещение для IO PRM1

extern int pusk1OF, pusk2OF, pusk3OF;
extern int pusk1OF2, pusk2OF2, pusk3OF2;
extern int pusk1OF3, pusk2OF3, pusk3OF3;
extern int pusk1OF4, pusk2OF4, pusk3OF4;
extern int pusk1OF5, pusk2OF5, pusk3OF5;
extern int pusk1OF6, pusk2OF6, pusk3OF6;
extern int pusk1OF7, pusk2OF7, pusk3OF7;
extern int pusk1OF8, pusk2OF8, pusk3OF8;
extern int pusk1OF9, pusk2OF9, pusk3OF9;
extern int pusk1OF10, pusk2OF10, pusk3OF10;
extern int pusk1OF11, pusk2OF11, pusk3OF11;
extern int pusk1OF12, pusk2OF12, pusk3OF12;
extern int pusk1OF13, pusk2OF13, pusk3OF13;
extern int pusk1OF14, pusk2OF14, pusk3OF14;
extern int pusk1OF15, pusk2OF15, pusk3OF15;
extern int pusk1OF16, pusk2OF16, pusk3OF16;

extern int pusk1OT1, pusk2OT1;
extern int pusk1OT2, pusk2OT2;
extern int pusk1OT3, pusk2OT3;
extern int pusk1OT4, pusk2OT4;
extern int pusk1OT5, pusk2OT5;
extern int pusk1OT6, pusk2OT6;
extern int pusk1OT7, pusk2OT7;
extern int pusk1OT8, pusk2OT8;

extern int pusk1OT1_old, pusk2OT1_old;
extern int pusk1OT2_old, pusk2OT2_old;
extern int pusk1OT3_old, pusk2OT3_old;
extern int pusk1OT4_old, pusk2OT4_old;
extern int pusk1OT5_old, pusk2OT5_old;
extern int pusk1OT6_old, pusk2OT6_old;
extern int pusk1OT7_old, pusk2OT7_old;
extern int pusk1OT8_old, pusk2OT8_old;

extern int rst1OT1, rst2OT1;
extern int rst1OT2, rst2OT2;
extern int rst1OT3, rst2OT3;
extern int rst1OT4, rst2OT4;
extern int rst1OT5, rst2OT5;
extern int rst1OT6, rst2OT6;
extern int rst1OT7, rst2OT7;
extern int rst1OT8, rst2OT8;

extern int rst1OT1_old, rst2OT1_old;
extern int rst1OT2_old, rst2OT2_old;
extern int rst1OT3_old, rst2OT3_old;
extern int rst1OT4_old, rst2OT4_old;
extern int rst1OT5_old, rst2OT5_old;
extern int rst1OT6_old, rst2OT6_old;
extern int rst1OT7_old, rst2OT7_old;
extern int rst1OT8_old, rst2OT8_old;

extern int OTout[];//Выходы OT

void  logicOF(int idxC) @ "Fast_function"
{
//логика компонента
  if(idxC>=0) {
    int tmpOffsetT    =
                cnfCOMPONENT[idxC].offsetTimers;   //таймера компонента в конфигурации
    int tmpOffsetIO   =
                cnfCOMPONENT[idxC].offsetIOCmd;    //IO команды
    int tmpOffsetENA  =
                cnfCOMPONENT[idxC].offsetENACmd;    //ENA команды

//  int tt2 = IO_LOGIC(IOCMD_OF1);

  //int tt1  = IO_LOGIC(IOCMD_IN_OF1);//ОФункция 1

  int tmp1 =  pusk1OF | pusk2OF | IO_LOGIC(IOCMD_IN_OF1);//ОФункция 1
  LSIGNAL_TIMER(TIMERP_OF1)  =  tmp1;
  int tmp2 = OFunction(tmpOffsetT + TIMERP_OF1, ENA_LOGIC(ENA_OF_1));
  IO_LOGIC(IOCMD_OUT_OF1) = tmp2&(~pusk3OF );

  //int tt2  = IO_LOGIC(IOCMD_IN_OF2);//ОФункция 2

  tmp1 =  pusk1OF2 | pusk2OF2 | IO_LOGIC(IOCMD_IN_OF2);//ОФункция 2
  LSIGNAL_TIMER(TIMERP_OF2)  = tmp1;
  tmp2 = OFunction(tmpOffsetT + TIMERP_OF2, ENA_LOGIC(ENA_OF_2));
  IO_LOGIC(IOCMD_OUT_OF2) = tmp2&(~pusk3OF2 );

 // if(tt3==1){
//    tt2=0;
 // }//if
  
  tmp1 =  pusk1OF3 | pusk2OF3 | IO_LOGIC(IOCMD_IN_OF3);//ОФункция 3
  LSIGNAL_TIMER(TIMERP_OF3)  = tmp1;
  tmp2 = OFunction(tmpOffsetT + TIMERP_OF3, ENA_LOGIC(ENA_OF_3));
  IO_LOGIC(IOCMD_OUT_OF3) = tmp2&(~pusk3OF3 );

  tmp1 =  pusk1OF4 | pusk2OF4 | IO_LOGIC(IOCMD_IN_OF4);//ОФункция 4
  LSIGNAL_TIMER(TIMERP_OF4)  = tmp1;
  tmp2 = OFunction(tmpOffsetT + TIMERP_OF4, ENA_LOGIC(ENA_OF_4));
  IO_LOGIC(IOCMD_OUT_OF4) = tmp2&(~pusk3OF4 );

  tmp1 =  pusk1OF5 | pusk2OF5 | IO_LOGIC(IOCMD_IN_OF5);//ОФункция 5
  LSIGNAL_TIMER(TIMERP_OF5)  = tmp1;
  tmp2 = OFunction(tmpOffsetT + TIMERP_OF5, ENA_LOGIC(ENA_OF_5));
  IO_LOGIC(IOCMD_OUT_OF5) = tmp2&(~pusk3OF5 );

  tmp1 =  pusk1OF6 | pusk2OF6 | IO_LOGIC(IOCMD_IN_OF6);//ОФункция 6
  LSIGNAL_TIMER(TIMERP_OF6)  = tmp1;
  tmp2 = OFunction(tmpOffsetT + TIMERP_OF6, ENA_LOGIC(ENA_OF_6));
  IO_LOGIC(IOCMD_OUT_OF6) = tmp2&(~pusk3OF6 );

  tmp1 =  pusk1OF7 | pusk2OF7 | IO_LOGIC(IOCMD_IN_OF7);//ОФункция 7
  LSIGNAL_TIMER(TIMERP_OF7)  = tmp1;
  tmp2 = OFunction(tmpOffsetT + TIMERP_OF7, ENA_LOGIC(ENA_OF_7));
  IO_LOGIC(IOCMD_OUT_OF7) = tmp2&(~pusk3OF7 );

  tmp1 =  pusk1OF8 | pusk2OF8 | IO_LOGIC(IOCMD_IN_OF8);//ОФункция 8
  LSIGNAL_TIMER(TIMERP_OF8)  = tmp1;
  tmp2 = OFunction(tmpOffsetT + TIMERP_OF8, ENA_LOGIC(ENA_OF_8));
  IO_LOGIC(IOCMD_OUT_OF8) = tmp2&(~pusk3OF8 );

  tmp1 =  pusk1OF9 | pusk2OF9 | IO_LOGIC(IOCMD_IN_OF9);//ОФункция 9
  LSIGNAL_TIMER(TIMERP_OF9)  = tmp1;
  tmp2 = OFunction(tmpOffsetT + TIMERP_OF9, ENA_LOGIC(ENA_OF_9));
  IO_LOGIC(IOCMD_OUT_OF9) = tmp2&(~pusk3OF9 );

  tmp1 =  pusk1OF10 | pusk2OF10 | IO_LOGIC(IOCMD_IN_OF10);//ОФункция 10
  LSIGNAL_TIMER(TIMERP_OF10)  = tmp1;
  tmp2 = OFunction(tmpOffsetT + TIMERP_OF10, ENA_LOGIC(ENA_OF_10));
  IO_LOGIC(IOCMD_OUT_OF10) = tmp2&(~pusk3OF10 );

  tmp1 =  pusk1OF11 | pusk2OF11 | IO_LOGIC(IOCMD_IN_OF11);//ОФункция 11
  LSIGNAL_TIMER(TIMERP_OF11)  = tmp1;
  tmp2 = OFunction(tmpOffsetT + TIMERP_OF11, ENA_LOGIC(ENA_OF_11));
  IO_LOGIC(IOCMD_OUT_OF11) = tmp2&(~pusk3OF11 );

  tmp1 =  pusk1OF12 | pusk2OF12 | IO_LOGIC(IOCMD_IN_OF12);//ОФункция 12
  LSIGNAL_TIMER(TIMERP_OF12)  = tmp1;
  tmp2 = OFunction(tmpOffsetT + TIMERP_OF12, ENA_LOGIC(ENA_OF_12));
  IO_LOGIC(IOCMD_OUT_OF12) = tmp2&(~pusk3OF12 );

  tmp1 =  pusk1OF13 | pusk2OF13 |IO_LOGIC(IOCMD_IN_OF13);//ОФункция 13
  LSIGNAL_TIMER(TIMERP_OF13)  = tmp1;
  tmp2 = OFunction(tmpOffsetT + TIMERP_OF13, ENA_LOGIC(ENA_OF_13));
  IO_LOGIC(IOCMD_OUT_OF13) = tmp2&(~pusk3OF13 );

  tmp1 =  pusk1OF14 | pusk2OF14 | IO_LOGIC(IOCMD_IN_OF14);//ОФункция 14
  LSIGNAL_TIMER(TIMERP_OF14)  = tmp1;
  tmp2 = OFunction(tmpOffsetT + TIMERP_OF14, ENA_LOGIC(ENA_OF_14));
  IO_LOGIC(IOCMD_OUT_OF14) = tmp2&(~pusk3OF14 );

  tmp1 =  pusk1OF15 | pusk2OF15 |
          IO_LOGIC(IOCMD_IN_OF15);//ОФункция 15
  LSIGNAL_TIMER(TIMERP_OF15)  = tmp1;
  tmp2 = OFunction(tmpOffsetT + TIMERP_OF15, ENA_LOGIC(ENA_OF_15));
  IO_LOGIC(IOCMD_OUT_OF15) = tmp2&(~pusk3OF15 );

  tmp1 =  pusk1OF16 | pusk2OF16 |
             IO_LOGIC(IOCMD_IN_OF16);//ОФункция 16
  LSIGNAL_TIMER(TIMERP_OF16)  = tmp1;
  tmp2 = OFunction(tmpOffsetT + TIMERP_OF16, ENA_LOGIC(ENA_OF_16));
  IO_LOGIC(IOCMD_OUT_OF16) = tmp2&(~pusk3OF16 );

//определить EL триг по восх фронту
//set- сиг уст; old- память; out- выход
//#define TRGL_EL(set, old, out)  out = ((set ^ old )&set);\
//OT1
int pusk1OT1_trg = 0;
int pusk2OT1_trg = 0;
int rst1OT1_trg = 0;
int rst2OT1_trg = 0;
  TRGL_EL(pusk1OT1, pusk1OT1_old, pusk1OT1_trg)
  TRGL_EL(pusk2OT1, pusk2OT1_old, pusk2OT1_trg)
  TRGL_EL(rst1OT1, rst1OT1_old, rst1OT1_trg)
  TRGL_EL(rst2OT1, rst2OT1_old, rst2OT1_trg)
  if(pusk1OT1_trg | pusk2OT1_trg) OTout[0] = 1;//Выходы OT
  if(rst1OT1_trg  | rst2OT1_trg)  OTout[0] = 0;//Выходы OT
  IO_LOGIC(IOCMD_OUT_OT1) = OTout[0];

//OT2
int pusk1OT2_trg = 0;
int pusk2OT2_trg = 0;
int rst1OT2_trg = 0;
int rst2OT2_trg = 0;
  TRGL_EL(pusk1OT2, pusk1OT2_old, pusk1OT2_trg)
  TRGL_EL(pusk2OT2, pusk2OT2_old, pusk2OT2_trg)
  TRGL_EL(rst1OT2, rst1OT2_old, rst1OT2_trg)
  TRGL_EL(rst2OT2, rst2OT2_old, rst2OT2_trg)
  if(pusk1OT2_trg | pusk2OT2_trg) OTout[1] = 1;//Выходы OT
  if(rst1OT2_trg  | rst2OT2_trg)  OTout[1] = 0;//Выходы OT
  IO_LOGIC(IOCMD_OUT_OT2) = OTout[1];

//OT3
int pusk1OT3_trg = 0;
int pusk2OT3_trg = 0;
int rst1OT3_trg = 0;
int rst2OT3_trg = 0;
  TRGL_EL(pusk1OT3, pusk1OT3_old, pusk1OT3_trg)
  TRGL_EL(pusk2OT3, pusk2OT3_old, pusk2OT3_trg)
  TRGL_EL(rst1OT3, rst1OT3_old, rst1OT3_trg)
  TRGL_EL(rst2OT3, rst2OT3_old, rst2OT3_trg)
  if(pusk1OT3_trg | pusk2OT3_trg) OTout[2] = 1;//Выходы OT
  if(rst1OT3_trg  | rst2OT3_trg)  OTout[2] = 0;//Выходы OT
  IO_LOGIC(IOCMD_OUT_OT3) = OTout[2];

//OT4
int pusk1OT4_trg = 0;
int pusk2OT4_trg = 0;
int rst1OT4_trg = 0;
int rst2OT4_trg = 0;
  TRGL_EL(pusk1OT4, pusk1OT4_old, pusk1OT4_trg)
  TRGL_EL(pusk2OT4, pusk2OT4_old, pusk2OT4_trg)
  TRGL_EL(rst1OT4, rst1OT4_old, rst1OT4_trg)
  TRGL_EL(rst2OT4, rst2OT4_old, rst2OT4_trg)
  if(pusk1OT4_trg | pusk2OT4_trg) OTout[3] = 1;//Выходы OT
  if(rst1OT4_trg  | rst2OT4_trg)  OTout[3] = 0;//Выходы OT
  IO_LOGIC(IOCMD_OUT_OT4) = OTout[3];

//OT5
int pusk1OT5_trg = 0;
int pusk2OT5_trg = 0;
int rst1OT5_trg = 0;
int rst2OT5_trg = 0;
  TRGL_EL(pusk1OT5, pusk1OT5_old, pusk1OT5_trg)
  TRGL_EL(pusk2OT5, pusk2OT5_old, pusk2OT5_trg)
  TRGL_EL(rst1OT5, rst1OT5_old, rst1OT5_trg)
  TRGL_EL(rst2OT5, rst2OT5_old, rst2OT5_trg)
  if(pusk1OT5_trg | pusk2OT5_trg) OTout[4] = 1;//Выходы OT
  if(rst1OT5_trg  | rst2OT5_trg)  OTout[4] = 0;//Выходы OT
  IO_LOGIC(IOCMD_OUT_OT5) = OTout[4];

//OT6
int pusk1OT6_trg = 0;
int pusk2OT6_trg = 0;
int rst1OT6_trg = 0;
int rst2OT6_trg = 0;
  TRGL_EL(pusk1OT6, pusk1OT6_old, pusk1OT6_trg)
  TRGL_EL(pusk2OT6, pusk2OT6_old, pusk2OT6_trg)
  TRGL_EL(rst1OT6, rst1OT4_old, rst1OT6_trg)
  TRGL_EL(rst2OT6, rst2OT4_old, rst2OT6_trg)
  if(pusk1OT6_trg | pusk2OT6_trg) OTout[5] = 1;//Выходы OT
  if(rst1OT6_trg  | rst2OT6_trg)  OTout[5] = 0;//Выходы OT
  IO_LOGIC(IOCMD_OUT_OT6) = OTout[5];

//OT7
int pusk1OT7_trg = 0;
int pusk2OT7_trg = 0;
int rst1OT7_trg = 0;
int rst2OT7_trg = 0;
  TRGL_EL(pusk1OT7, pusk1OT7_old, pusk1OT7_trg)
  TRGL_EL(pusk2OT7, pusk2OT7_old, pusk2OT7_trg)
  TRGL_EL(rst1OT7, rst1OT7_old, rst1OT7_trg)
  TRGL_EL(rst2OT7, rst2OT7_old, rst2OT7_trg)
  if(pusk1OT7_trg | pusk2OT7_trg) OTout[6] = 1;//Выходы OT
  if(rst1OT7_trg  | rst2OT7_trg)  OTout[6] = 0;//Выходы OT
  IO_LOGIC(IOCMD_OUT_OT7) = OTout[6];

//OT8
int pusk1OT8_trg = 0;
int pusk2OT8_trg = 0;
int rst1OT8_trg = 0;
int rst2OT8_trg = 0;
  TRGL_EL(pusk1OT8, pusk1OT8_old, pusk1OT8_trg)
  TRGL_EL(pusk2OT8, pusk2OT8_old, pusk2OT8_trg)
  TRGL_EL(rst1OT8, rst1OT8_old, rst1OT8_trg)
  TRGL_EL(rst2OT8, rst2OT8_old, rst2OT8_trg)
  if(pusk1OT8_trg | pusk2OT8_trg) OTout[7] = 1;//Выходы OT
  if(rst1OT8_trg  | rst2OT8_trg)  OTout[7] = 0;//Выходы OT
  IO_LOGIC(IOCMD_OUT_OT8) = OTout[7];

  }//if(idxC>=0) 
  else{
  //логика РЛ
    int tmpOffsetT    =
                cnfCOMPONENT_WL[-idxC-1].offsetTimers;   //таймера компонента в конфигурации РЛ
    int tmpOffsetIO   =
                cnfCOMPONENT_WL[-idxC-1].offsetIOCmd;    //IO команды
    int tmpOffsetENA  =
                cnfCOMPONENT_WL[-idxC-1].offsetENACmd;    //ENA команды
/*
    int tt2 = IO_LOGIC_WL(IOCMD_OF1);
    
    LSIGNAL_TIMER_WL(TIMERP_OF1)  = IO_LOGIC_WL(IOCMD_OF1);//ОФункция 1
    int tt1 = OFunction_WL(tmpOffsetT + TIMERP_OF1, ENA_LOGIC_WL(ENA_OF_1));
    IO_LOGIC_WL(IOCMD_OF1) = tt1;//OFunction_WL(tmpOffsetT + TIMERP_OF1, ENA_LOGIC_WL(ENA_OF_1));
*/
  LSIGNAL_TIMER_WL(TIMERP_OF1)  = IO_LOGIC_WL(IOCMD_IN_OF1);//ОФункция 1
  IO_LOGIC_WL(IOCMD_OUT_OF1) = OFunction_WL(tmpOffsetT + TIMERP_OF1, ENA_LOGIC_WL(ENA_OF_1));

  LSIGNAL_TIMER_WL(TIMERP_OF2)  = IO_LOGIC_WL(IOCMD_IN_OF2);//ОФункция 2
  IO_LOGIC_WL(IOCMD_OUT_OF2) = OFunction_WL(tmpOffsetT + TIMERP_OF2, ENA_LOGIC_WL(ENA_OF_2));

  LSIGNAL_TIMER_WL(TIMERP_OF3)  = IO_LOGIC_WL(IOCMD_IN_OF3);//ОФункция 3
  IO_LOGIC_WL(IOCMD_OUT_OF3) = OFunction_WL(tmpOffsetT + TIMERP_OF3, ENA_LOGIC_WL(ENA_OF_3));

  LSIGNAL_TIMER_WL(TIMERP_OF4)  = IO_LOGIC_WL(IOCMD_IN_OF4);//ОФункция 4
  IO_LOGIC_WL(IOCMD_OUT_OF4) = OFunction_WL(tmpOffsetT + TIMERP_OF4, ENA_LOGIC_WL(ENA_OF_4));

  LSIGNAL_TIMER_WL(TIMERP_OF5)  = IO_LOGIC_WL(IOCMD_IN_OF5);//ОФункция 5
  IO_LOGIC_WL(IOCMD_OUT_OF5) = OFunction_WL(tmpOffsetT + TIMERP_OF5, ENA_LOGIC_WL(ENA_OF_5));

  LSIGNAL_TIMER_WL(TIMERP_OF6)  = IO_LOGIC_WL(IOCMD_IN_OF6);//ОФункция 6
  IO_LOGIC_WL(IOCMD_OUT_OF6) = OFunction_WL(tmpOffsetT + TIMERP_OF6, ENA_LOGIC_WL(ENA_OF_6));

  LSIGNAL_TIMER_WL(TIMERP_OF7)  = IO_LOGIC_WL(IOCMD_IN_OF7);//ОФункция 7
  IO_LOGIC_WL(IOCMD_OUT_OF7) = OFunction_WL(tmpOffsetT + TIMERP_OF7, ENA_LOGIC_WL(ENA_OF_7));

  LSIGNAL_TIMER_WL(TIMERP_OF8)  = IO_LOGIC_WL(IOCMD_IN_OF8);//ОФункция 8
  IO_LOGIC_WL(IOCMD_OUT_OF8) = OFunction_WL(tmpOffsetT + TIMERP_OF8, ENA_LOGIC_WL(ENA_OF_8));

  LSIGNAL_TIMER_WL(TIMERP_OF9)  = IO_LOGIC_WL(IOCMD_IN_OF9);//ОФункция 9
  IO_LOGIC_WL(IOCMD_OUT_OF9) = OFunction_WL(tmpOffsetT + TIMERP_OF9, ENA_LOGIC_WL(ENA_OF_9));

  LSIGNAL_TIMER_WL(TIMERP_OF10)  = IO_LOGIC_WL(IOCMD_IN_OF10);//ОФункция 10
  IO_LOGIC_WL(IOCMD_OUT_OF10) = OFunction_WL(tmpOffsetT + TIMERP_OF10, ENA_LOGIC_WL(ENA_OF_10));

  LSIGNAL_TIMER_WL(TIMERP_OF11)  = IO_LOGIC_WL(IOCMD_IN_OF11);//ОФункция 11
  IO_LOGIC_WL(IOCMD_OUT_OF11) = OFunction_WL(tmpOffsetT + TIMERP_OF11, ENA_LOGIC_WL(ENA_OF_11));

  LSIGNAL_TIMER_WL(TIMERP_OF12)  = IO_LOGIC_WL(IOCMD_IN_OF12);//ОФункция 12
  IO_LOGIC_WL(IOCMD_OUT_OF12) = OFunction_WL(tmpOffsetT + TIMERP_OF12, ENA_LOGIC_WL(ENA_OF_12));

  LSIGNAL_TIMER_WL(TIMERP_OF13)  = IO_LOGIC_WL(IOCMD_IN_OF13);//ОФункция 13
  IO_LOGIC_WL(IOCMD_OUT_OF13) = OFunction_WL(tmpOffsetT + TIMERP_OF13, ENA_LOGIC_WL(ENA_OF_13));

  LSIGNAL_TIMER_WL(TIMERP_OF14)  = IO_LOGIC_WL(IOCMD_IN_OF14);//ОФункция 14
  IO_LOGIC_WL(IOCMD_OUT_OF14) = OFunction_WL(tmpOffsetT + TIMERP_OF14, ENA_LOGIC_WL(ENA_OF_14));

  LSIGNAL_TIMER_WL(TIMERP_OF15)  = IO_LOGIC_WL(IOCMD_IN_OF15);//ОФункция 15
  IO_LOGIC_WL(IOCMD_OUT_OF15) = OFunction_WL(tmpOffsetT + TIMERP_OF15, ENA_LOGIC_WL(ENA_OF_15));

  LSIGNAL_TIMER_WL(TIMERP_OF16)  = IO_LOGIC_WL(IOCMD_IN_OF16);//ОФункция 16
  IO_LOGIC_WL(IOCMD_OUT_OF16) = OFunction_WL(tmpOffsetT + TIMERP_OF16, ENA_LOGIC_WL(ENA_OF_16));

  }//if

}//logicOF(short idxC)
