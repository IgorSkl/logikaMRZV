#include "lpc_types.h"
/*
#include "lpc_irq_fiq.h"
#include "lpc_arm922t_cp15_driver.h"

#include "lpc32xx_hstimer.h"
#include "lpc32xx_ssp.h"
#include "lpc32xx_gpio.h"

#include "lpc32xx_intc_driver.h"
#include "lpc32xx_clkpwr_driver.h"

#include "arm926ej_cp15_drv.h"
#include "ttbl.h"
*/

#include <stdio.h>
#include <string.h>

#include "psuperVisor\supermanager.h"

//#include "component\componentdef.h"
//#include "callbackelement\callbackelementdef.h"
#include "callbackelement\ustrangEEPROMdef.h"
#include "psuperVisor\psvisor_helpdef.h"
//#include "virtualMenu\wideLogManagerdef.h"
#include "dataEEPROM\dataEEPROMdef.h"
#include "zonaVRT\zonaVRTdef.h"

//#include "callbackelement\callbackelementfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "dataEEPROM\dataEEPROM.h"
#include "SettingIci\SettingIci.h"

//#include "toSpeedOptim.h"
//#include "toSpeedDIS.h"

#include "header.h"
#include "ici_r_ef.h"

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
extern int GlobalLevel_UCM;
extern int GlobalLevel_ULAPV;
extern int GlobalLevel_ICM;
extern int alterEEPROM;//x101;//0;//байты alter ext устaвок и ранжир EEPROM
extern int eeprom_status;//статусный регистр EEPROM

 char chProtectTableComeIn = 0;
 char chResultCallGetMeasPrt = 0;
 long lDemo_IA,lDemo_IB,lDemo_IC;
 long lDemo_UA,lDemo_UB,lDemo_UC;
 long lDemo_ULA,lDemo_ULB,lDemo_ULC;
 long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
 long lDemo_3I0,lDemo_3U0;
//сектора направл МТЗ
 int sectorMTZ_IA_V, sectorMTZ_IA_N;
 int sectorMTZ_IB_V, sectorMTZ_IB_N;
 int sectorMTZ_IC_V, sectorMTZ_IC_N;
//сектор направл ТЗНП
 int sectorTZNP1, sectorTZNP2, sectorTZNP3, sectorTZNP4, sectorTZNP5;
//сектора направл NZOP
 int sectorNZOP1_V, sectorNZOP1_N, sectorNZOP2_V, sectorNZOP2_N;
//комплексные сопротивления OF DZ1
 INT_64 resistance_fA0X1, resistance_fA0Y1;
 INT_64 resistance_fB0X1, resistance_fB0Y1;
 INT_64 resistance_fC0X1, resistance_fC0Y1;
//комплексные сопротивления OF DZ12
 INT_64 resistance_fA0X2, resistance_fA0Y2;
 INT_64 resistance_fB0X2, resistance_fB0Y2;
 INT_64 resistance_fC0X2, resistance_fC0Y2;
//комплексные сопротивления OF DZ3
 INT_64 resistance_fA0X3, resistance_fA0Y3;
 INT_64 resistance_fB0X3, resistance_fB0Y3;
 INT_64 resistance_fC0X3, resistance_fC0Y3;
//комплексные сопротивления OF DZ4
 INT_64 resistance_fA0X4, resistance_fA0Y4;
 INT_64 resistance_fB0X4, resistance_fB0Y4;
 INT_64 resistance_fC0X4, resistance_fC0Y4;
//комплексные сопротивления OF DZ5
 INT_64 resistance_fA0X5, resistance_fA0Y5;
 INT_64 resistance_fB0X5, resistance_fB0Y5;
 INT_64 resistance_fC0X5, resistance_fC0Y5;
//комплексные сопротивления MF DZ
 INT_64 resistance_fAMX, resistance_fAMY;
 INT_64 resistance_fBMX, resistance_fBMY;
 INT_64 resistance_fCMX, resistance_fCMY;

//Синхронизация АПВ 
 int speed_angle_APV;
 int angle_unbalance_APV;
 int voltage_difference_APV;

// INT_64 resistance_fA0X2, resistance_fA0Y2;
// INT_64 resistance_fA0X3, resistance_fA0Y3;
// INT_64 resistance_fA0X4, resistance_fA0Y4;
// INT_64 resistance_fA0X5, resistance_fA0Y5;
__MEASUREMENT_TO_PROTECTION TestMeasProtection;

void dataAccessICI()
{
//доступ к данным ICI

//проверка на новые уставки и загрузка данных измерений
  if (chbrCfgTblState&16)//(1<<BR_CFG_TBL_WR_EPR_BIT))
  {
    chProtectTableComeIn = 1;
    chbrCfgTblState &= 0xEF;//~16);//(1<<BR_CFG_TBL_WR_EPR_BIT);
  //cntToBC++;//к-во обменов с BC
  
    if(!(eeprom_status & (1<<EEPROMUST_BUSY))){
    //если EEPROM не занята  
    SettingIci_Rangir();//ранжирование реле и ДВ

    SettingIci_MTZ();//установки ICI МТЗ 
    SettingIci_UMM();//установки ICI UMM
    SettingIci_DZ1();//установки ICI DZ1
    SettingIci_DZ2to5();//установки ICI DZ2to5
    SettingIci_TZNP();//установки ICI TZNP
    SettingIci_PRM1();//установки ICI PRM1
    SettingIci_NZOP();//установки ICI NZOP
    SettingIci_APV();//установки ICI APV
    SettingIci_UROV();//установки ICI UROV
    SettingIci_OF();//установки ICI OF
    //сохранить уставки и ранж в EEPROM
    savePARAMtoEEPROM(alterEEPROM^USTALTER_MASKA);
    }//if
    
//--------------------------------------------------------------  
  }//if
  chResultCallGetMeasPrt =  GetMeasPrt(&TestMeasProtection); 
  if(chResultCallGetMeasPrt == SUCCESS_EXEC)
  {
    //Data Ready
    lDemo_IA = TestMeasProtection.measurement_bl[INDEX_IA];
    lDemo_IB = TestMeasProtection.measurement_bl[INDEX_IB];
    lDemo_IC = TestMeasProtection.measurement_bl[INDEX_IC];  

    GlobalLevelI_ABC[0]  = lDemo_IA;//фазный ток IA
    GlobalLevelI_ABC[1]  = lDemo_IB;//фазный ток IB
    GlobalLevelI_ABC[2]  = lDemo_IC;//фазный ток IC
    
    //напр фазные
    lDemo_UA = TestMeasProtection.measurement_bl[INDEX_UA];
    lDemo_UB = TestMeasProtection.measurement_bl[INDEX_UB];
    lDemo_UC = TestMeasProtection.measurement_bl[INDEX_UC];  
    GlobalLevelUF_ABC[0]  = lDemo_UA;//напр UA
    GlobalLevelUF_ABC[1]  = lDemo_UB;//напр UB
    GlobalLevelUF_ABC[2]  = lDemo_UC;//напр UC

    //напр линейные
    lDemo_ULA = TestMeasProtection.linear_voltage[0];
    lDemo_ULB = TestMeasProtection.linear_voltage[1];
    lDemo_ULC = TestMeasProtection.linear_voltage[2];  
    GlobalLevelUL_ABC[0]  = lDemo_ULA;//напр UAB
    GlobalLevelUL_ABC[1]  = lDemo_ULB;//напр UBC
    GlobalLevelUL_ABC[2]  = lDemo_ULC;//напр UCA

    //3I0
    lDemo_3I0 = TestMeasProtection.measurement_bl[INDEX_3I0];
    GlobalLevel_3I0 = lDemo_3I0;
    lDemo_3U0 = TestMeasProtection.measurement_bl[INDEX_3U0];
    GlobalLevel_3U0 = lDemo_3U0;
    //I2
    GlobalLevel_ICM = TestMeasProtection.measurement_bl[9];
    GlobalLevel_UCM = TestMeasProtection.measurement_bl[10];
    //ULAPV
    GlobalLevel_ULAPV = TestMeasProtection.measurement_bl[13];

//сектор направл ТЗНП
    sectorTZNP1 = TestMeasProtection.sector_3I0_3U0_1;
    sectorTZNP2 = TestMeasProtection.sector_3I0_3U0_2;
    sectorTZNP3 = TestMeasProtection.sector_3I0_3U0_3;
    sectorTZNP4 = TestMeasProtection.sector_3I0_3U0_4;
    sectorTZNP5 = TestMeasProtection.sector_3I0_3U0_5;
//сектора направл NZOP
   sectorNZOP1_V =0;
   sectorNZOP1_N =0;
  switch(TestMeasProtection.sector_I2_U2_1)
  {
   case 1:
   sectorNZOP1_V =1;
   sectorNZOP1_N =0;
   break;
   case 2:
   sectorNZOP1_V =0;
   sectorNZOP1_N =1;
   break;
   default:;
  }//switch
   sectorNZOP2_V =0;
   sectorNZOP2_N =0;
  switch(TestMeasProtection.sector_I2_U2_2)
  {
   case 1:
   sectorNZOP2_V =1;
   sectorNZOP2_N =0;
   break;
   case 2:
   sectorNZOP2_V =0;
   sectorNZOP2_N =1;
   break;
   default:;
  }//switch

//комплексные сопротивления ДЗ1 OF
 resistance_fA0X1 = (INT_64)ceil(TestMeasProtection.resistance_f[0]*TO_INTEGER64);
 resistance_fA0Y1 = (INT_64)ceil(TestMeasProtection.resistance_f[1]*TO_INTEGER64);
 resistance_fB0X1 = (INT_64)ceil(TestMeasProtection.resistance_f[10]*TO_INTEGER64);
 resistance_fB0Y1 = (INT_64)ceil(TestMeasProtection.resistance_f[11]*TO_INTEGER64);
 resistance_fC0X1 = (INT_64)ceil(TestMeasProtection.resistance_f[20]*TO_INTEGER64);
 resistance_fC0Y1 = (INT_64)ceil(TestMeasProtection.resistance_f[21]*TO_INTEGER64);
//комплексные сопротивления ДЗ2 OF
 resistance_fA0X2 = (INT_64)ceil(TestMeasProtection.resistance_f[2]*TO_INTEGER64);
 resistance_fA0Y2 = (INT_64)ceil(TestMeasProtection.resistance_f[3]*TO_INTEGER64);
 resistance_fB0X2 = (INT_64)ceil(TestMeasProtection.resistance_f[12]*TO_INTEGER64);
 resistance_fB0Y2 = (INT_64)ceil(TestMeasProtection.resistance_f[13]*TO_INTEGER64);
 resistance_fC0X2 = (INT_64)ceil(TestMeasProtection.resistance_f[22]*TO_INTEGER64);
 resistance_fC0Y2 = (INT_64)ceil(TestMeasProtection.resistance_f[23]*TO_INTEGER64);
//комплексные сопротивления ДЗ3 OF
 resistance_fA0X3 = (INT_64)ceil(TestMeasProtection.resistance_f[4]*TO_INTEGER64);
 resistance_fA0Y3 = (INT_64)ceil(TestMeasProtection.resistance_f[5]*TO_INTEGER64);
 resistance_fB0X3 = (INT_64)ceil(TestMeasProtection.resistance_f[14]*TO_INTEGER64);
 resistance_fB0Y3 = (INT_64)ceil(TestMeasProtection.resistance_f[15]*TO_INTEGER64);
 resistance_fC0X3 = (INT_64)ceil(TestMeasProtection.resistance_f[24]*TO_INTEGER64);
 resistance_fC0Y3 = (INT_64)ceil(TestMeasProtection.resistance_f[25]*TO_INTEGER64);
//комплексные сопротивления ДЗ4 OF
 resistance_fA0X4 = (INT_64)ceil(TestMeasProtection.resistance_f[6]*TO_INTEGER64);
 resistance_fA0Y4 = (INT_64)ceil(TestMeasProtection.resistance_f[7]*TO_INTEGER64);
 resistance_fB0X4 = (INT_64)ceil(TestMeasProtection.resistance_f[16]*TO_INTEGER64);
 resistance_fB0Y4 = (INT_64)ceil(TestMeasProtection.resistance_f[17]*TO_INTEGER64);
 resistance_fC0X4 = (INT_64)ceil(TestMeasProtection.resistance_f[26]*TO_INTEGER64);
 resistance_fC0Y4 = (INT_64)ceil(TestMeasProtection.resistance_f[27]*TO_INTEGER64);
//комплексные сопротивления ДЗ4 OF
 resistance_fA0X5 = (INT_64)ceil(TestMeasProtection.resistance_f[8]*TO_INTEGER64);
 resistance_fA0Y5 = (INT_64)ceil(TestMeasProtection.resistance_f[9]*TO_INTEGER64);
 resistance_fB0X5 = (INT_64)ceil(TestMeasProtection.resistance_f[18]*TO_INTEGER64);
 resistance_fB0Y5 = (INT_64)ceil(TestMeasProtection.resistance_f[19]*TO_INTEGER64);
 resistance_fC0X5 = (INT_64)ceil(TestMeasProtection.resistance_f[28]*TO_INTEGER64);
 resistance_fC0Y5 = (INT_64)ceil(TestMeasProtection.resistance_f[29]*TO_INTEGER64);

 //комплексные сопротивления ДЗ MF
 resistance_fAMX = (INT_64)ceil(TestMeasProtection.resistance_m[0]*TO_INTEGER64);
 resistance_fAMY = (INT_64)ceil(TestMeasProtection.resistance_m[1]*TO_INTEGER64);
 resistance_fBMX = (INT_64)ceil(TestMeasProtection.resistance_m[2]*TO_INTEGER64);
 resistance_fBMY = (INT_64)ceil(TestMeasProtection.resistance_m[3]*TO_INTEGER64);
 resistance_fCMX = (INT_64)ceil(TestMeasProtection.resistance_m[4]*TO_INTEGER64);
 resistance_fCMY = (INT_64)ceil(TestMeasProtection.resistance_m[5]*TO_INTEGER64);

//Синхронизация АПВ
 speed_angle_APV        = TestMeasProtection.speed_angle_change;
 angle_unbalance_APV    = TestMeasProtection.angle_unbalance;
 voltage_difference_APV = TestMeasProtection.voltage_difference;

//сектора направл МТЗ
   sectorMTZ_IA_V =0;
   sectorMTZ_IA_N =0;
  switch(TestMeasProtection.sector_IA_UBC_1)
  {
   case 1:
   sectorMTZ_IA_V =1;
   sectorMTZ_IA_N =0;
   break;
   case 2:
   sectorMTZ_IA_V =0;
   sectorMTZ_IA_N =1;
   break;
   default:;
  }//switch
   sectorMTZ_IB_V =0;
   sectorMTZ_IB_N =0;
  switch(TestMeasProtection.sector_IB_UCA_1)
  {
   case 1:
   sectorMTZ_IB_V =1;
   sectorMTZ_IB_N =0;
   break;
   case 2:
   sectorMTZ_IB_V =0;
   sectorMTZ_IB_N =1;
   break;
   default:;
  }//switch
   sectorMTZ_IC_V =0;
   sectorMTZ_IC_N =0;
  switch(TestMeasProtection.sector_IC_UAB_1)
  {
   case 1:
   sectorMTZ_IC_V =1;
   sectorMTZ_IC_N =0;
   break;
   case 2:
   sectorMTZ_IC_V =0;
   sectorMTZ_IC_N =1;
   break;
   default:;
  }//switch

  }//if
  else
  {
    switch(chResultCallGetMeasPrt)
    {
      case ERROR_EXEC:
       chResultCallGetMeasPrt++;//Error when call Function 
        break;
      case START_EXEC:
      case STATE_EXEC:  
       chResultCallGetMeasPrt++;//Data not ready  
       
        break;
      default:
      ;
    }
    
  }
}//dataAccessICI()
