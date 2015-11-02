
#include <stdio.h>
#include <string.h>
#include "bazisdef.h"
#include "component\componentdef.h"
#include "psuperVisor\psvisor_helpdef.h"

#include "logictimers\logictimersmac.h"

#include "logictimers\logictimersfnc.h"

#include "..\bazis.h"

#include "zonaVRT\zonaVRTdef.h"
#include "zonaVRT\zonaVRTfnc.h"

#include "toSpeedOptim.h"

#define _HIDE_COMPONENT
#include "PRM1Component.c"
#include "DZ2Component.c"

extern int GlobalPO1;
extern int GlobalPO2;
extern int GlobalPO3;
extern int GlobalPO4;

extern COMPONENT_OBJ  cnfCOMPONENT[];//конфигурация
extern int  logMassTimer[];
extern int  ENAcmd[];
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern int   WideCmdRTBuffer[];
extern int   tempLog[];
extern int offsetIOCmdPRM1;//смещение для IO PRM1
extern int offsetSPVCmdPRM1;//смещение для SPV PRM1
extern int GlobalLevelI_ABC[];
extern int  isFAILU_DZ;

extern INT_64 koordXZ_64;//=353534;//125001;//160697;//250000;
extern INT_64 koordYZ_64;//=421325;//216507;//191512;//0;
//комплексные сопротивления
extern INT_64 resistance_fA0X2, resistance_fA0Y2;
extern INT_64 resistance_fB0X2, resistance_fB0Y2;
extern INT_64 resistance_fC0X2, resistance_fC0Y2;

extern INT_64 resistance_fA0X3, resistance_fA0Y3;
extern INT_64 resistance_fB0X3, resistance_fB0Y3;
extern INT_64 resistance_fC0X3, resistance_fC0Y3;

extern INT_64 resistance_fA0X4, resistance_fA0Y4;
extern INT_64 resistance_fB0X4, resistance_fB0Y4;
extern INT_64 resistance_fC0X4, resistance_fC0Y4;

extern INT_64 resistance_fA0X5, resistance_fA0Y5;
extern INT_64 resistance_fB0X5, resistance_fB0Y5;
extern INT_64 resistance_fC0X5, resistance_fC0Y5;

extern INT_64 resistance_fAMX, resistance_fAMY;
extern INT_64 resistance_fBMX, resistance_fBMY;
extern INT_64 resistance_fCMX, resistance_fCMY;
extern int isValidZonaDZ2OF;//флаг валидности зоны
extern int isValidZonaDZ2MF;//флаг валидности зоны
extern int isValidZonaDZ3OF;//флаг валидности зоны
extern int isValidZonaDZ3MF;//флаг валидности зоны
extern int isValidZonaDZ4OF;//флаг валидности зоны
extern int isValidZonaDZ4MF;//флаг валидности зоны
extern int isValidZonaDZ5OF;//флаг валидности зоны
extern int isValidZonaDZ5MF;//флаг валидности зоны
extern int isTriangleZonaBD[];//зона ДЗ треугольник-четырехугольник
/*
extern int locPO_DZ2MF;
extern int locPO_DZ2OF;
extern int locPO_DZ3MF;
extern int locPO_DZ3OF;
extern int locPO_DZ4MF;
extern int locPO_DZ4OF;
extern int locPO_DZ5MF;
extern int locPO_DZ5OF;
*/

void  logicDZ2to5(int idxC) @ "Fast_function"
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
//    int tttttttt6 =  cnfCOMPONENT[idxC].numClon;
    int numClonDZ = (cnfCOMPONENT[idxC].numClon)-1;
   // int tttttttt6 =  cnfCOMPONENT[idxC].numClon;    
    //int numClonDZ =    //номер клона
      //            tttttttt6-1;
                //(cnfCOMPONENT[idxC].numClon)-1;    
   
 // /int numberClon =    //номер клона
   //             cnfCOMPONENT[idxC].numClon;//)-1;    
    
 //if(numC!=2) return;//только для ДЗ3
//токи
  detectorLevelUP3F(GlobalLevelI_ABC,
                                     tmpOffsetUSpv+SPVSRAB_DZ2to5_MTZ,
                                     tmpOffsetUSpv+SPVVOZV_DZ2to5_MTZ,
                                     tmpOffsetUSpv+SPV_OUTA_DZ2to5_MTZ);

  int isz_separatorA = 0;
  int isz_separatorB = 0;
  int isz_separatorC = 0;
  INT_64 meassAXZ = 0, meassAYZ = 0;
  INT_64 meassBXZ = 0, meassBYZ = 0;
  INT_64 meassCXZ = 0, meassCYZ = 0;
  switch(numClonDZ){
    case 1:
      isz_separatorA = ISZ_DZ2OFA;
      isz_separatorB = ISZ_DZ2OFB;
      isz_separatorC = ISZ_DZ2OFC;
      meassAXZ = resistance_fA0X2; meassAYZ = resistance_fA0Y2;
      meassBXZ = resistance_fB0X2; meassBYZ = resistance_fB0Y2;
      meassCXZ = resistance_fC0X2; meassCYZ = resistance_fC0Y2;
    break;
    case 2:
      isz_separatorA = ISZ_DZ3OFA;
      isz_separatorB = ISZ_DZ3OFB;
      isz_separatorC = ISZ_DZ3OFC;
      meassAXZ = resistance_fA0X3; meassAYZ = resistance_fA0Y3;
      meassBXZ = resistance_fB0X3; meassBYZ = resistance_fB0Y3;
      meassCXZ = resistance_fC0X3; meassCYZ = resistance_fC0Y3;
    break;
    case 3:
      isz_separatorA = ISZ_DZ4OFA;
      isz_separatorB = ISZ_DZ4OFB;
      isz_separatorC = ISZ_DZ4OFC;
      meassAXZ = resistance_fA0X4; meassAYZ = resistance_fA0Y4;
      meassBXZ = resistance_fB0X4; meassBYZ = resistance_fB0Y4;
      meassCXZ = resistance_fC0X4; meassCYZ = resistance_fC0Y4;
    break;
    case 4:
      isz_separatorA = ISZ_DZ5OFA;
      isz_separatorB = ISZ_DZ5OFB;
      isz_separatorC = ISZ_DZ5OFC;
      meassAXZ = resistance_fA0X5; meassAYZ = resistance_fA0Y5;
      meassBXZ = resistance_fB0X5; meassBYZ = resistance_fB0Y5;
      meassCXZ = resistance_fC0X5; meassCYZ = resistance_fC0Y5;
    break;
  }//switch
//попадание Z в зону  
int LocalPO_DZ2to5OF = 0;
if(isTriangleZonaBD[numClonDZ*2]){
//треугольник
  koordXZ_64=meassAXZ; koordYZ_64=meassAYZ;
int LocalPO_DZ2to5OFA = isViewZTrianMethod_64VRT(numClonDZ*2, isz_separatorA);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTA_I005)^1);
  //koordXZ_64=resistance_fB0X1; koordYZ_64=resistance_fB0Y1;
  koordXZ_64=meassBXZ; koordYZ_64=meassBYZ;
int LocalPO_DZ2to5OFB = isViewZTrianMethod_64VRT(numClonDZ*2, isz_separatorB);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTB_I005)^1);
  //koordXZ_64=resistance_fC0X1; koordYZ_64=resistance_fC0Y1;
  koordXZ_64=meassCXZ; koordYZ_64=meassCYZ;
int LocalPO_DZ2to5OFC = isViewZTrianMethod_64VRT(numClonDZ*2, isz_separatorC);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTC_I005)^1);
    LocalPO_DZ2to5OF = LocalPO_DZ2to5OFA | LocalPO_DZ2to5OFB | LocalPO_DZ2to5OFC;
     }//if(isTriangleZonaBD[numClonDZ*2])
else {
  koordXZ_64=meassAXZ; koordYZ_64=meassAYZ;
int LocalPO_DZ2to5OFA = isViewZMethod_64VRT(numClonDZ*2, isz_separatorA);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTA_I005)^1);
  //koordXZ_64=resistance_fB0X1; koordYZ_64=resistance_fB0Y1;
  koordXZ_64=meassBXZ; koordYZ_64=meassBYZ;
int LocalPO_DZ2to5OFB = isViewZMethod_64VRT(numClonDZ*2, isz_separatorB);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTB_I005)^1);
  //koordXZ_64=resistance_fC0X1; koordYZ_64=resistance_fC0Y1;
  koordXZ_64=meassCXZ; koordYZ_64=meassCYZ;
int LocalPO_DZ2to5OFC = isViewZMethod_64VRT(numClonDZ*2, isz_separatorC);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTC_I005)^1);
    LocalPO_DZ2to5OF = LocalPO_DZ2to5OFA | LocalPO_DZ2to5OFB | LocalPO_DZ2to5OFC;
    }//else

//------------MF
  isz_separatorA = 0;
  isz_separatorB = 0;
  isz_separatorC = 0;
  switch(numClonDZ){
    case 1:
      isz_separatorA = ISZ_DZ2MFA;
      isz_separatorB = ISZ_DZ2MFB;
      isz_separatorC = ISZ_DZ2MFC;
    break;
    case 2:
      isz_separatorA = ISZ_DZ3MFA;
      isz_separatorB = ISZ_DZ3MFB;
      isz_separatorC = ISZ_DZ3MFC;
    break;
    case 3:
      isz_separatorA = ISZ_DZ4MFA;
      isz_separatorB = ISZ_DZ4MFB;
      isz_separatorC = ISZ_DZ4MFC;
    break;
    case 4:
      isz_separatorA = ISZ_DZ5MFA;
      isz_separatorB = ISZ_DZ5MFB;
      isz_separatorC = ISZ_DZ5MFC;
    break;
  }//switch
//попадание Z в зону  
int LocalPO_DZ2to5MF = 0;
if(isTriangleZonaBD[numClonDZ*2 +1]){
//треугольник
  koordXZ_64=resistance_fAMX; koordYZ_64=resistance_fAMY;
int LocalPO_DZ2to5MFA = isViewZTrianMethod_64VRT( 1+ numClonDZ*2, isz_separatorA);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTA_I005)^1);
  koordXZ_64=resistance_fBMX; koordYZ_64=resistance_fBMY;
int LocalPO_DZ2to5MFB = isViewZTrianMethod_64VRT( 1+ numClonDZ*2, isz_separatorB);// &
  //        (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTB_I005)^1);
  koordXZ_64=resistance_fCMX; koordYZ_64=resistance_fCMY;
int LocalPO_DZ2to5MFC = isViewZTrianMethod_64VRT( 1+ numClonDZ*2, isz_separatorC);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTC_I005)^1);

    LocalPO_DZ2to5MF = LocalPO_DZ2to5MFA | LocalPO_DZ2to5MFB | LocalPO_DZ2to5MFC;
  }//if(isTriangleZonaBD[numClonDZ*2] +1)
else {
  koordXZ_64=resistance_fAMX; koordYZ_64=resistance_fAMY;
int LocalPO_DZ2to5MFA = isViewZMethod_64VRT( 1+ numClonDZ*2, isz_separatorA);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTA_I005)^1);
  koordXZ_64=resistance_fBMX; koordYZ_64=resistance_fBMY;
int LocalPO_DZ2to5MFB = isViewZMethod_64VRT( 1+ numClonDZ*2, isz_separatorB);// &
  //        (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTB_I005)^1);
  koordXZ_64=resistance_fCMX; koordYZ_64=resistance_fCMY;
int LocalPO_DZ2to5MFC = isViewZMethod_64VRT( 1+ numClonDZ*2, isz_separatorC);// &
//          (SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTC_I005)^1);

    LocalPO_DZ2to5MF = LocalPO_DZ2to5MFA | LocalPO_DZ2to5MFB | LocalPO_DZ2to5MFC;
 }//else

//    isValidZonaDZ5OF = isNewZonaMethodVRT(getOffsetSPVUstCnf(idxC), (numClonDZlon-1)*2);//флаг валидности зоны
   switch(numClonDZ){
    case 1:
      if(isValidZonaDZ2OF) LocalPO_DZ2to5OF=0;//флаг валидности зоны
      if(isValidZonaDZ2MF) LocalPO_DZ2to5MF=0;//флаг валидности зоны
    break;
    case 2:
      if(isValidZonaDZ3OF) LocalPO_DZ2to5OF=0;//флаг валидности зоны
      if(isValidZonaDZ3MF) LocalPO_DZ2to5MF=0;//флаг валидности зоны
    break;
    case 3:
      if(isValidZonaDZ4OF) LocalPO_DZ2to5OF=0;//флаг валидности зоны
      if(isValidZonaDZ4MF) LocalPO_DZ2to5MF=0;//флаг валидности зоны
    break;
    case 4:
      if(isValidZonaDZ5OF) LocalPO_DZ2to5OF=0;//флаг валидности зоны
      if(isValidZonaDZ5MF) LocalPO_DZ2to5MF=0;//флаг валидности зоны
    break;
  }//switch
  
  int LocalPO_MDZ2to5MF = //LocalPO_DZ2to5MF & (
                                              SPV_UST(SPV_OUTA_DZ2to5_MTZ) |
                                              SPV_UST(SPV_OUTB_DZ2to5_MTZ) |
                                              SPV_UST(SPV_OUTC_DZ2to5_MTZ) ;
                            //                  );

 #include "inc_uskdz2mf.ci"
#include "inc_uskdz2of.ci"
#include "inc_uskmdz2mf.ci"

  //*******DZ2********
  int commonDZ2 = 
    //CMD1_DZ2
    (IO_LOGIC(IOCMD1_DZ2to5)^1) &
    ENA_LOGIC(ENA_DZ2to5_1);// ENA_DZ2;

  if(numClonDZ=2) {//for DZ3
int tt1 = TL_LOGIC(TLCMDOUTNCN_DZ2to5MF);
int tt2 = isFAILU_DZ;
int tt5 = (IO_LOGIC(IOCMD1_DZ2to5)^1);
int tt3 = isFAILU_DZ;
int tt6 = ENA_LOGIC(ENA_DZ2to5_1);// ENA_DZ2;


    int tmpOffsetENA_test  =
                cnfCOMPONENT[idxC].offsetENACmd;    //ENA команды

int tt4 = isFAILU_DZ;


           }//if

  //L1
  int locPO_DZ2to5MF = 
        commonDZ2 &
        //ПО ДЗ2
        (GlobalPO1 | LocalPO_DZ2to5MF) &
        //ELOUTTRG_NCN_DZ2to5MF
        (TL_LOGIC(TLCMDOUTNCN_DZ2to5MF)^1);

      //L2 DZ2
  int locPO_MDZ2MF = 
        commonDZ2 &
        //ENA_MDZ2to5MF
        ENA_LOGIC(ENA_DZ2to5_2) &
        //ПО МТЗ ДЗ2МФ
        (GlobalPO2 | LocalPO_MDZ2to5MF) &
        //ELOUTTRG_NCN_MDZ2to5MF
        TL_LOGIC(TLCMDOUTNCN_MDZ2to5MF) &
        ((
  //DZ2to5_PO3
  TL_LOGIC(TLCMD30_DZ2to5OF) |
  //DZ2to5_PO1
  TL_LOGIC(TLCMD30_DZ2to5MF) 
        )^1);

  //L3
  int locPO_DZ2to5OF = 
          commonDZ2 &
          //ПО ДЗ2ОФ
          (GlobalPO3 | LocalPO_DZ2to5OF) &
          //ELOUTTRG_NCN_MDZ2to5OF
          (TL_LOGIC(TLCMDOUTNCN_DZ2to5OF)^1);

//триг по восх фронту
//TRG_FRONT(set, clr, old, out)
//          //DZ2_PO1                ELOLDTRG_NCN_DZ2to5MF  ELOUTTRG_NCN_DZ2to5MF
  TRG_FRONT(locPO_DZ2to5MF, isFAILU_DZ, TLCMDOLDNCN_DZ2to5MF,  TLCMDOUTNCN_DZ2to5MF)
//триг по восх фронту
//TRG_FRONT(set, clr, old, out)
//          //DZ2_PO3                 ELOLDTRG_NCN_DZ2to5OF  ELOUTTRG_NCN_DZ2to5OF
  TRG_FRONT(locPO_DZ2to5OF, isFAILU_DZ, TLCMDOLDNCN_DZ2to5OF,  TLCMDOUTNCN_DZ2to5OF)
//триг по восх MMF
//TRG_MMF(set, clr, old, out)
//                    //DZ2_PO2      ELOLDTRG_NCN_MDZ2to5MF  ELOUTTRG_NCN_MDZ2to5MF
  TRG_MMF(isFAILU_DZ, locPO_MDZ2MF,  TLCMDOLDNCN_MDZ2to5MF,  TLCMDOUTNCN_MDZ2to5MF)

  //Сраб ПО ДЗ2МФ
  locPO_DZ2to5MF &=
        //ELOUTTRG_NCN_DZ2to5MF
        (TL_LOGIC(TLCMDOUTNCN_DZ2to5MF)^1);

  //Сраб ПО ДЗ2ОФ
  locPO_DZ2to5OF &=
        //ELOUTTRG_NCN_DZ2to5OF
        (TL_LOGIC(TLCMDOUTNCN_DZ2to5OF)^1);
  
  //Сраб ПО МТЗ ДЗ2МФ
  locPO_MDZ2MF &=
        //ELOUTTRG_NCN_MDZ2to5MF
        TL_LOGIC(TLCMDOUTNCN_MDZ2to5MF);

//гасим МФ и ОФ если активный МТЗ МФ
  //Сраб ПО ДЗ2МФ
  locPO_DZ2to5MF &=
      //Сраб ПО МТЗ ДЗ2МФ
      (locPO_MDZ2MF^1);

  //Сраб ПО ДЗ2ОФ
  locPO_DZ2to5OF &=
      //Сраб МТЗ ДЗ2МФ
      (locPO_MDZ2MF^1);

//  int max_tmp = 
  //DZ2to5_PO1
  TL_LOGIC(TLCMD30_DZ2to5MF) =
  //Сраб ПО ДЗ2МФ
  IO_LOGIC(IOCMD4_DZ2to5MF) =
    locPO_DZ2to5MF;
//    if(max_tmp) flag_max_monitoring |= MAXMONITORING_COLLECT;//макс параметры сработки

  //L7
  //DZ2_TIM1
  LSIGNAL_TIMER(TIMER1_DZ2to5)  = 
    //RES_DZ2MF
    TL_LOGIC(TLCMD1_DZ2to5MF) &
    locPO_DZ2to5MF;

  //дельта таймера 
  TL_LOGIC(TL10_DZ2TO5MF) = IS_TIMER_DELTA12(TIMER1_DZ2to5)^1;   

  //L10
  int tmp = 
           LSIGNAL_TIMER(TIMER_BODZ2to5MF)  =
              //DZ2MF_USKOR
              TL_LOGIC(TLCMD27_DZ2to5MF) |
              //DZ2_TIM1
              PLOG_TIMER(TIMER1_DZ2to5); 

  //Сраб ДЗ2МФ
  IO_LOGIC(IOCMD5_DZ2to5MF) =
    ILOG_TIMER(TIMER_BODZ2to5MF)|tmp;//DZ2_TIM1
//    if(max_tmp) flag_max_monitoring |= MAXMONITORING_FIX;//макс параметры сработки

//   max_tmp =
    //DZ2to5_PO2
   TL_LOGIC(TLCMD30_MDZ2to5MF) =
  //Сраб ПО МТЗ ДЗ2МФ
  IO_LOGIC(IOCMD4_MDZ2to5MF) =
    locPO_MDZ2MF;
  //  if(max_tmp) flag_max_monitoring |= MAXMONITORING_COLLECT;//макс параметры сработки

  //L8
  LSIGNAL_TIMER(TIMER2_DZ2to5)  = //DZ2_TIM2
    //RES_MDZ2MF
    TL_LOGIC(TLCMD1_MDZ2to5MF) &
    locPO_MDZ2MF;

  //дельта таймера
  TL_LOGIC(TL10_MDZ2TO5MF) = IS_TIMER_DELTA12(TIMER2_DZ2to5)^1;

  //L11
  tmp =
  LSIGNAL_TIMER(TIMER_BOMDZ2to5MF)  =
          //MDZ2MF_USKOR
          TL_LOGIC(TLCMD27_MDZ2to5MF) |
          //DZ2_TIM2
          PLOG_TIMER(TIMER2_DZ2to5); 

  //Сраб MTZ ДЗ2МФ
  IO_LOGIC(IOCMD5_MDZ2to5MF) =
    ILOG_TIMER(TIMER_BOMDZ2to5MF)|tmp;//DZ2_TIM2
//    if(max_tmp) flag_max_monitoring |= MAXMONITORING_FIX;//макс параметры сработки

  //DZ2to5_PO3
  TL_LOGIC(TLCMD30_DZ2to5OF) =
  //Сраб ПО ДЗ2ОФ
  IO_LOGIC(IOCMD4_DZ2to5OF) =
    locPO_DZ2to5OF;

  //L9
  LSIGNAL_TIMER(TIMER3_DZ2to5)  = //DZ2_TIM3
    //RES_DZ2OF
    TL_LOGIC(TLCMD1_DZ2to5OF) &
    locPO_DZ2to5OF;

  //дельта таймера 
  TL_LOGIC(TL10_DZ2TO5OF) = IS_TIMER_DELTA12(TIMER3_DZ2to5)^1;   

  //L12
  tmp =
  LSIGNAL_TIMER(TIMER_BODZ2to5OF)  =
          //DZ2OF_USKOR
          TL_LOGIC(TLCMD27_DZ2to5OF) | 
          //DZ2_TIM3
          PLOG_TIMER(TIMER3_DZ2to5); 

  //Сраб ДЗ2OФ
  IO_LOGIC(IOCMD5_DZ2to5OF) =
    ILOG_TIMER(TIMER_BODZ2to5OF)|tmp;//DZ2_TIM3
/*
  switch(numClonDZ){
    case 1:
      locPO_DZ2MF = locPO_DZ2to5MF;
      locPO_DZ2OF = locPO_DZ2to5OF;
    break;
    case 2:
      locPO_DZ3MF = locPO_DZ2to5MF;
      locPO_DZ3OF = locPO_DZ2to5OF;
    break;
    case 3:
      locPO_DZ4MF = locPO_DZ2to5MF;
      locPO_DZ4OF = locPO_DZ2to5OF;
    break;
    case 4:
      locPO_DZ5MF = locPO_DZ2to5MF;
      locPO_DZ5OF = locPO_DZ2to5OF;
    break;
  }//switch
*/

}//logicDZ2(short idxC)


