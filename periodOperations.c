
#include "lpc_types.h"

#include <stdio.h>
#include <string.h>

#include "psuperVisor\supermanager.h"

#include "component\componentdef.h"
#include "callbackelement\callbackelementdef.h"
#include "psuperVisor\psvisor_helpdef.h"
#include "virtualMenu\wideLogManagerdef.h"
//#include "zonaVRT\zonaVRTdef.h"

#include "callbackelement\callbackelementfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"
#include "virtualMenu\systemmenufnc.h"

#include "toSpeedOptim.h"
#include "toSpeedDIS.h"

#include "periodOperations.h"

#include "header.h"
#include "ici_r_ef.h"

#define _HIDE_COMPONENT
#include "PRM1Component.c"

#include "APVComponent.c"
#include "DZ1Component.c"
#include "DZ2Component.c"

#include "MTZ1Component.c"
#include "MTZ2Component.c"

#include "NZOP1Component.c"

extern CALLBACK_MISSION cb_missionDEVICE1;
extern CALLBACK_MISSION *cb_mission_crrDEVICE1;//текущая миссия
extern short  missionSeparatorDEVICE1;//сепаратор миссии
extern int    WideCmdBuffer[];//широкий ком массив
extern UNS_32 pActualCMD[];//текущие
extern UNS_32 ArrayRANGIR[];
extern int  spvUSTAVKI[];//текущие уставки супервизора

//глобальный сброс всех таймеров
extern int  globalTimerReset;
extern int ReleTrigger;//тригг реле
extern int CDITrigger;//тригг СДИ
extern int offsetSPVCmdPRM1;//смещение для SPV PRM1
extern int    TypLE[];
extern UNS_32 *WideLogActual;//командный массив расшир логики
extern UNS_32 PlusCircleCmd[];//командный массив плюсовых команд LE
extern UNS_32 InputLECmd[];//входной командный массив LE
extern UNS_32 EXEOutputCmd[];//выходной командный массив компонентов
extern int    isTimeSection;//критическая секция с двойным доступом

extern UNS_32 dataCmdStateINTERFACE[];//INTERFACE CmdState
extern UNS_32 dataTrgCmdStateINTERFACE[];//INTERFACE Trg CmdState
extern UNS_32 buffTrgCmdStateINTERFACE[];//INTERFACE CmdState
extern UNS_32 buffCmdStateINTERFACE[];//INTERFACE CmdState
extern UNS_32 buffInStateINTERFACE;//INTERFACE  In
extern UNS_32 buffOutStateINTERFACE;//INTERFACE Out
extern UNS_32 buffLedStateINTERFACE;//INTERFACE Led
extern UNS_32 buffTrgOutStateINTERFACE;//INTERFACE Trg Out
extern UNS_32 buffTrgLedStateINTERFACE;//INTERFACE Trg Led
extern UNS_32 buffGruppaUstINTERFACE;//группа уставок
extern UNS_32 GruppaUst;//группа уставок

//флаги уставок
//extern char chbrCfgTblState;

typedef struct
{
  volatile UNS_8 bdvv_unisost1;  //0 рег сост БДВВ1
  volatile UNS_8 bdvv_in1;       //1 рег входов БДВВ1
  volatile UNS_8 bdvv_out1;      //2 рег выходов БДВВ1
  volatile UNS_8 bdvv_outsost1;  //3 рег сост выходов БДВВ1
  volatile UNS_8 bdvv_outena1;   //4 разрешение выходов БДВВ1
  volatile UNS_8 bdvv_rezerv1;   //5 резерв
  volatile UNS_8 bdvv_rezerv2;   //6 резерв
  volatile UNS_8 bdvv_rezerv3;   //7 резерв
  volatile UNS_8 bdvv_unisost2;  //8 рег сост БДВВ2
  volatile UNS_8 bdvv_in2;       //9 рег входов БДВВ2
  volatile UNS_8 bdvv_out2;      //A рег выходов БДВВ2
  volatile UNS_8 bdvv_outsost2;  //B рег сост выходов БДВВ2
  volatile UNS_8 bdvv_outena2;   //C разрешение выходов БДВВ2
} BDVV_REGS_T;

typedef struct
{
  volatile UNS_8 bdvv_unisost_new;  //0 рег сост БДВВ _new
  volatile UNS_8 bdvv_in_new;       //1 рег входов БДВВ _new
  volatile UNS_8 bdvv_out_new;      //2 рег выходов БДВВ _new
  volatile UNS_8 bdvv_outsost_new;  //3 рег сост выходов БДВВ _new
  volatile UNS_8 bdvv_outena_new;   //4 разрешение выходов БДВВ _new
} BDVVNEW_REGS_T;

typedef struct
{
  volatile UNS_8 bdv_unisost;  //0 рег сост БД
  volatile UNS_8 bdv_in1;          //1 рег входов БДВ
  volatile UNS_8 bdv_in2;          //2 рег входов БДВ
} BDV_REGS_T;

#define BDVV_BASE  0xE3000000
#define BDVV_PNT ((BDVV_REGS_T *)(BDVV_BASE))
#define BDV_BASE  0xE3000010
#define BDV_PNT ((BDV_REGS_T *)(BDV_BASE))
#define BDVVNEW_BASE  0xE3000020
#define BDVVNEW_PNT ((BDVVNEW_REGS_T *)(BDVVNEW_BASE))


//UNS_8 arrayEEPROM[100];//массив EEPROM для чтения
extern int timing;  
extern int timingLoad;  
extern int cicling;  

extern int trigReg;//заполнить дискр рег

extern int IndexTIMERS;
extern int IndexTLog;
extern int IndexIO;
extern int IndexENA;
extern int IndexUstSPV;//индекс уставок в супервизоре
extern int GlobalLevelI_ABC[];//уровни фазных токов Фурье
extern int GlobalLevelUL_ABC[];//уровни напр лин
extern int GlobalLevelUF_ABC[];//уровни напр фаз
extern int GlobalLevel_3I0;
extern int GlobalLevel_3U0;
extern UNS_32 rawDVLow;//сырые ДВ

int indexLgm=0;//индекс исполняемого ЛЭ
int isRunWL=1;//исполнение РЛ

UNS_32 rele_bdvv1;//селекция реле
UNS_32 cdi_bdvv1;//селекция CDI

UNS_32 selectorDVLow;//селекция ДВ активный-неактивный для мл 16 DV
UNS_32 selectorDVMidd;//селекция ДВ активный-неактивный для cp 16 DV
UNS_32 selectorDVHi;//селекция ДВ активный-неактивный для ct 16 DV

#include "ici_r_ef.h"

int flag_max_monitoring;//макс параметры сработки
int IA_maxMonitoring;//сбор данных макс сраб по IA
int IB_maxMonitoring;//сбор данных макс сраб по IB
int IC_maxMonitoring;//сбор данных макс сраб по IC

int IA_maxFix;//фиксация данных макс сраб по IA
int IB_maxFix;//фиксация данных макс сраб по IB
int IC_maxFix;//фиксация данных макс сраб по IC

int cntToBC=0;//обмен с BC
void periodical_operations(void)
{
 UNS_32 dvUnion[DQUADRO];//DV
 UNS_32 tmpUnion[2*DQUADRO];//временное
 UNS_32 tmpUnion2[2*DQUADRO];//временное


 switch(trigReg)//заполнить регистратор
 {
  case 1: DiskrRegList();//первые 50 строк дискр регистратора
  break;

  case 2: ActualRegList();//первые 50 строк текущих
  break;

  case 3: ActualDVList();//первые 50 строк текущих DV
  break;

  case 4: ActualReleList();//первые 50 строк текущих Реле
  break;

  default:;
 }//switch
  trigReg  = 0;//заполнить регистратор


 #define TEST_PIN_1          0

        UNS_32 set = 0, clr = 0, maska = P3_STATE_GPO(TEST_PIN_1);
        if ((GPIO->p3_outp_state & maska) != 0) clr = maska; 
        else set = maska;
        gpio_set_gpo_state(set, clr);

  JLINKDCC_Process();
  
//операции реального времени
  Scan_Ici_Event_Req(); //межпроцессорный обмен
  Scan_Ici_Entry_Data();//межпроцессорный обмен

  flag_max_monitoring = 0;//макс параметры сработки

  dataAccessICI();//доступ к данным ICI

  UNS_8 test1 = BDVV_PNT->bdvv_unisost1;  //0 рег сост БДВВ1
//  BDVV_PNT->bdvv_outena1 = 0xA5;   //4 разрешение выходов БДВВ1
//  BDVV_PNT->bdvv_out1    = 0xff;      //2 рег выходов БДВВ1
  UNS_8 test2 = BDVV_PNT->bdvv_outsost1;  //3 рег сост выходов БДВВ1
  UNS_8 test3 = BDVV_PNT->bdvv_in1;       //1 рег входов БДВВ1

    UNS_8 test1_v = BDV_PNT->bdv_unisost;  //0 рег сост БДВ
  UNS_8 test3_v = BDV_PNT->bdv_in1;       //1 рег входов БДВ
  UNS_8 test4_v = BDV_PNT->bdv_in2;       //1 рег входов БДВ

  UNS_8 test1_new = BDVVNEW_PNT->bdvv_unisost_new;  //0 рег сост БДВВ _new
//  BDVVNEW_PNT->bdvv_outena_new = 0xA5;   //4 разрешение выходов БДВВ _new
//  BDVVNEW_PNT->bdvv_out_new    = 0xff;      //2 рег выходов БДВВ _new
  UNS_8 test2_new = BDVVNEW_PNT->bdvv_outsost_new;  //3 рег сост выходов БДВВ _new
  UNS_8 test3_new = BDVVNEW_PNT->bdvv_in_new;       //1 рег входов БДВВ _new
  
 rawDVLow = test3_new;

 //BDV_PNT->bdv_unisost = 0x00;  //0 рег сост БДВ

//операции раз в оборот
 memset(dvUnion, 0, 4*DQUADRO);//обнулить DV

  isTimeSection = 1;//критическая секция с двойным доступом
  selectorDVLow = SelectorDVdriverLow();//селекция ДВ активный-неактивный для мл 16 DV
  //уставка ДВ -ПрямойИнверсный
  UNS_32 upr_dvLow  =   SPV_USTOUT(offsetSPVCmdPRM1+ SPV_UPR_DVLOW);
  selectorDVLow ^= upr_dvLow;
  dvUnionMakerLow(selectorDVLow, dvUnion);//получить массив dvUnion для мл 16 DV

  selectorDVMidd = SelectorDVdriverMidd();//селекция ДВ активный-неактивный для cp 16 DV
  //уставка ДВ -ПрямойИнверсный
  UNS_32 upr_dvMidd =   SPV_USTOUT(offsetSPVCmdPRM1+ SPV_UPR_DVMIDD);
  selectorDVMidd ^= upr_dvMidd;
  dvUnionMakerMidd(selectorDVMidd, dvUnion);//получить массив dvUnion для cp 16 DV

  selectorDVHi = SelectorDVdriverHi();//селекция ДВ активный-неактивный для ct DV
  UNS_32 upr_dvHi   =   SPV_USTOUT(offsetSPVCmdPRM1+ SPV_UPR_DVHI);
  selectorDVHi ^= upr_dvHi;
  dvUnionMakerHi(selectorDVHi, dvUnion);//получить массив dvUnion для ct  DV
  isTimeSection = 0;//критическая секция с двойным доступом
  buffInStateINTERFACE = selectorDVLow + selectorDVMidd*65536;
/*
  FDVForm1->VisualDVdriver(selectorDVHi);//визуализация ДВ активный-неактивный

 if(DV1Box->Checked)
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV1_SM*DQUADRO+ i];
 if(DV2Box->Checked)
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV2_SM*DQUADRO+ i];
 if(DV3Box->Checked)
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV3_SM*DQUADRO+ i];
 if(DV4Box->Checked)
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV4_SM*DQUADRO+ i];
 if(DV5Box->Checked)
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV5_SM*DQUADRO+ i];
*/

 //общая логика измерений
 CommonMeasureLogic();

  if(TypLE[indexLgm]==0){
           indexLgm=0;//индекс исполняемого ЛЭ
           }//if

//получить входные для ЛЭ
 for (int i=0; i<2*DQUADRO; i++) InputLECmd[i] = PlusCircleCmd[i] | EXEOutputCmd[i] | dvUnion[i];

//исполнить массив ЛЭ 
  switch(TypLE[indexLgm])//индекс исполняемого ЛЭ
  {
   case typeLE_OR:{
     elementOR(indexLgm);//OR
     }
   break;
   case typeLE_AND:
     elementAND(indexLgm);//AND
   break;
   case typeLE_XOR:
     elementXOR(indexLgm);//XOR
   break;
   default:;

  }//switch

  indexLgm++;//индекс исполняемого ЛЭ
  if(indexLgm==LE_TOTAL) indexLgm=0;


 //сформировать текущие(первую половину) как выход схемы ЛЭ и ДВ
 for (int i=0; i<DQUADRO; i++) pActualCMD[i] = PlusCircleCmd[i] | dvUnion[i];
 //спрятать текущие pActualCMD (первую половину)
 memcpy(tmpUnion, pActualCMD, 4*DQUADRO);

//Превратить ком массив(первую половину) в широкий ком массив RT
 TranslateQuadroToWideRTCmd(pActualCMD);

 EXElogicCOMPONENT();//СУПЕРВИЗОР Логика компонентов из конфиг

 memset(pActualCMD, 0, 4*DQUADRO);//обнулить текущие (первую половину)
 CompressorToActualCMD();//получить текущие (первую половину) из WideCmdRTBuffer

 //получить новые cmd от компонентов(первую половину)
 for (int i=0; i<DQUADRO; i++) EXEOutputCmd[i] = pActualCMD[i] & ~tmpUnion[i];

//---------КОМПОНЕНТЫ РЛ--------------------------
 //спрятать текущие pActualCMD (первую половину)
 memcpy(tmpUnion2, pActualCMD, 4*DQUADRO);
///*
 //сформировать текущие(первую половину) как выход схемы ЛЭ(вторая половина)
 memcpy(pActualCMD, PlusCircleCmd, 2* 4*DQUADRO);
// for (int i=0; i<DQUADRO; i++) pActualCMD[i +DQUADRO] = PlusCircleCmd[i +DQUADRO];
 //спрятать текущие pActualCMD (вторую половину)
 memcpy(tmpUnion, WideLogActual, 4*DQUADRO);

 //спрятать текущие pActualCMD (вторую половину)
// memcpy(tmpUnion, WideLogActual, 4*DQUADRO);
//Превратить текущие(вторая половина) в широкий ком массив RT
 TranslateQuadroToWideRTCmd(WideLogActual);

 EXElogicCOMPONENT_WL();//СУПЕРВИЗОР Логика компонентов из конфиг РЛ

 memset(pActualCMD, 0, 4*DQUADRO);//обнулить текущие (первую половину)
 CompressorToActualCMD();//получить текущие из WideCmdRTBuffer

 //получить новые cmd от компонентов(вторую половину)
 for (int i=0; i<DQUADRO; i++) EXEOutputCmd[i +DQUADRO] = pActualCMD[i] & ~tmpUnion[i];
//*/
 //восстановить pActualCMD (первую половину)
 memcpy(pActualCMD, tmpUnion2, 4*DQUADRO);
//-------------------------------------------------------------------------------------

 globalTimerReset = 0;//глобальный сброс всех таймеров
 DiskretRegWorking();//работа дискр регистратора
 PuskAPV_UROV_OFWorking();//пуск АПВ УРОВ ОФ

 isTimeSection = 1;//критическая секция с двойным доступом
 TranslateINTERFACE();//перетранслировать широкий ком массив

//исполнить ранжирование реле
  rele_bdvv1 = WorkRangirRele();
  if((rele_bdvv1&0x40)!=0){
    int tt1=0;
  }//if
//исполнить ранжирование СДИ
  cdi_bdvv1 = WorkRangirCDI();
  isTimeSection = 0;//критическая секция с двойным доступом

  buffOutStateINTERFACE = rele_bdvv1;//INTERFACE Out
  buffLedStateINTERFACE = cdi_bdvv1;//INTERFACE Led
  buffTrgOutStateINTERFACE = ReleTrigger;//INTERFACE Trg Out
  buffTrgLedStateINTERFACE = CDITrigger;//INTERFACE Trg Led
  buffGruppaUstINTERFACE = GruppaUst;//группа уставок
  memcpy(buffCmdStateINTERFACE, dataCmdStateINTERFACE, 4*DQUADRO);//INTERFACE CmdState
  memcpy(buffTrgCmdStateINTERFACE, dataTrgCmdStateINTERFACE, 4*DQUADRO);//INTERFACE Trg CmdState

  BDVV_PNT->bdvv_outena1 = 0xA5;   //4 разрешение выходов БДВВ1
//  BDVV_PNT->bdvv_out1    = 0x00;//rele_bdvv1;//0xff;      //2 рег выходов БДВВ1
  
  BDVVNEW_PNT->bdvv_outena_new = 0xA5;   //4 разрешение выходов БДВВ1
  BDVVNEW_PNT->bdvv_out_new    = rele_bdvv1;      //2 рег выходов БДВВ1
  
//  dataAccessEEPROM();//доступ к данным EEPROM 
 
 cicling ++;  
 
 if(cicling==100000){
      int tt0 = timingLoad;  
      int tt1 = timing;  
      int tt2 = cicling;  
      
      int tt3 = IndexTIMERS;
      int tt4 = IndexTLog;
      int tt5 = IndexIO;
      int tt6 = IndexENA;
      int tt7 = IndexUstSPV;//индекс уставок в супервизоре
          tt7 = IndexUstSPV;//индекс уставок в супервизоре
      
 }//if
 

 if(flag_max_monitoring==0)//макс параметры сработки
 {
   //нет ни сбора данных ни фиксации
   IA_maxMonitoring = 0;//сбор данных макс сраб по IA
   IB_maxMonitoring = 0;//сбор данных макс сраб по IB
   IC_maxMonitoring = 0;//сбор данных макс сраб по IC

   IA_maxFix = 0;//фиксация данных макс сраб по IA
   IB_maxFix = 0;//фиксация данных макс сраб по IB
   IC_maxFix = 0;//фиксация данных макс сраб по IC
 }//if(flag_max_monitoring==0)//макс параметры сработки
//  case MAXMONITORING_COLLECT:
 if(flag_max_monitoring&MAXMONITORING_COLLECT){//макс параметры сработки
  //сбор данных макс параметров
   }//if(flag_max_monitoring&MAXMONITORING_COLLECT){//макс параметры сработки
//  case MAXMONITORING_FIX:

 if(flag_max_monitoring&MAXMONITORING_FIX){//макс параметры сработки
  //фиксация данных макс параметров
  //применение формулы
  }//if(flag_max_monitoring&MAXMONITORING_FIX){//макс параметры сработки
 
 
}//periodical_operations(void)
