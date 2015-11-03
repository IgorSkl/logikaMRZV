#include "lpc_types.h"
#include "lpc_irq_fiq.h"
#include "lpc_arm922t_cp15_driver.h"

#include "lpc32xx_hstimer.h"
#include "lpc32xx_ssp.h"
#include "lpc32xx_gpio.h"

#include "lpc32xx_intc_driver.h"
#include "lpc32xx_clkpwr_driver.h"

#include "arm926ej_cp15_drv.h"
#include "ttbl.h"

#include <stdio.h>
#include <string.h>

#include "psuperVisor\supermanager.h"

#include "component\componentdef.h"
#include "psuperVisor\psvisor_helpdef.h"

#include "psuperVisor\psvisor_helpfnc.h"
#include "virtualMenu\rangmanagerfnc.h"
#include "virtualmenu\systemmenufnc.h"
#include "SettingIci\SettingIci.h"

#include "toSpeedOptim.h"
#include "toSpeedDIS.h"

#include "header.h"
#include "ici_r_ef.h"

//#define _HIDE_COMPONENT
//#include "PRM1Component.c"

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

void  SettingIci_Rangir()
{
//установки ICI Ранжирования
   ClearArrayRANGIR();//очистить все ранжир

//-----------MTZ--------------------
   SettingIci_RangirMTZ2DV(DV1_SM);//отранж МТЗ на ДВ1
   SettingIci_RangirMTZ2DV(DV2_SM);//отранж МТЗ на ДВ2
   SettingIci_RangirMTZ2DV(DV3_SM);//отранж МТЗ на ДВ3
   SettingIci_RangirMTZ2DV(DV4_SM);//отранж МТЗ на ДВ4
   SettingIci_RangirMTZ2DV(DV5_SM);//отранж МТЗ на ДВ5
   SettingIci_RangirMTZ2DV(DV6_SM);//отранж МТЗ на ДВ6

   SettingIci_RangirMTZ2Rele(RELE1_SM);//отранж МТЗ на Реле1
   SettingIci_RangirMTZ2Rele(RELE2_SM);//отранж МТЗ на Реле2
   SettingIci_RangirMTZ2Rele(RELE3_SM);//отранж МТЗ на Реле3
   SettingIci_RangirMTZ2Rele(RELE4_SM);//отранж МТЗ на Реле4
   SettingIci_RangirMTZ2Rele(RELE5_SM);//отранж МТЗ на Реле5
   SettingIci_RangirMTZ2Rele(RELE6_SM);//отранж МТЗ на Реле6

   SettingIci_RangirMTZ2Led(CDI1_SM);//отранж МТЗ на СДИ1
   SettingIci_RangirMTZ2Led(CDI2_SM);//отранж МТЗ на СДИ2
   SettingIci_RangirMTZ2Led(CDI3_SM);//отранж МТЗ на СДИ3
   SettingIci_RangirMTZ2Led(CDI4_SM);//отранж МТЗ на СДИ4
   SettingIci_RangirMTZ2Led(CDI5_SM);//отранж МТЗ на СДИ5
   SettingIci_RangirMTZ2Led(CDI6_SM);//отранж МТЗ на СДИ6
   
//  /*

//-----------UMM--------------------
   SettingIci_RangirUMM2DV(DV1_SM);//отранж UMM на ДВ1
   SettingIci_RangirUMM2DV(DV2_SM);//отранж UMM на ДВ2
   SettingIci_RangirUMM2DV(DV3_SM);//отранж UMM на ДВ3
   SettingIci_RangirUMM2DV(DV4_SM);//отранж UMM на ДВ4
   SettingIci_RangirUMM2DV(DV5_SM);//отранж UMM на ДВ5
   SettingIci_RangirUMM2DV(DV6_SM);//отранж UMM на ДВ6

   SettingIci_RangirUMM2Rele(RELE1_SM);//отранж UMM на Реле1
   SettingIci_RangirUMM2Rele(RELE2_SM);//отранж UMM на Реле2
   SettingIci_RangirUMM2Rele(RELE3_SM);//отранж UMM на Реле3
   SettingIci_RangirUMM2Rele(RELE4_SM);//отранж UMM на Реле4
   SettingIci_RangirUMM2Rele(RELE5_SM);//отранж UMM на Реле5
   SettingIci_RangirUMM2Rele(RELE6_SM);//отранж UMM на Реле6

   SettingIci_RangirUMM2Led(CDI1_SM);//отранж UMM на СДИ1
   SettingIci_RangirUMM2Led(CDI2_SM);//отранж UMM на СДИ2
   SettingIci_RangirUMM2Led(CDI3_SM);//отранж UMM на СДИ3
   SettingIci_RangirUMM2Led(CDI4_SM);//отранж UMM на СДИ4
   SettingIci_RangirUMM2Led(CDI5_SM);//отранж UMM на СДИ5
   SettingIci_RangirUMM2Led(CDI6_SM);//отранж UMM на СДИ6
//*/

//-----------TZNP--------------------
   SettingIci_RangirTZNP2DV(DV1_SM);//отранж TZNP на ДВ1
   SettingIci_RangirTZNP2DV(DV2_SM);//отранж TZNP на ДВ2
   SettingIci_RangirTZNP2DV(DV3_SM);//отранж TZNP на ДВ3
   SettingIci_RangirTZNP2DV(DV4_SM);//отранж TZNP на ДВ4
   SettingIci_RangirTZNP2DV(DV5_SM);//отранж TZNP на ДВ5
   SettingIci_RangirTZNP2DV(DV6_SM);//отранж TZNP на ДВ6

   SettingIci_RangirTZNP2Rele(RELE1_SM);//отранж TZNP на Реле1
   SettingIci_RangirTZNP2Rele(RELE2_SM);//отранж TZNP на Реле2
   SettingIci_RangirTZNP2Rele(RELE3_SM);//отранж TZNP на Реле3
   SettingIci_RangirTZNP2Rele(RELE4_SM);//отранж TZNP на Реле4
   SettingIci_RangirTZNP2Rele(RELE5_SM);//отранж TZNP на Реле5
   SettingIci_RangirTZNP2Rele(RELE6_SM);//отранж TZNP на Реле6

//-----------DZ--------------------
   SettingIci_RangirDZToDV(DV1_SM);//отранж DZ на ДВ1
   SettingIci_RangirDZToDV(DV2_SM);//отранж DZ на ДВ2
   SettingIci_RangirDZToDV(DV3_SM);//отранж DZ на ДВ3
   SettingIci_RangirDZToDV(DV4_SM);//отранж DZ на ДВ4
   SettingIci_RangirDZToDV(DV5_SM);//отранж DZ на ДВ5
   SettingIci_RangirDZToDV(DV6_SM);//отранж DZ на ДВ6

   SettingIci_RangirDZToRele(RELE1_SM);//отранж DZ на Реле1
   SettingIci_RangirDZToRele(RELE2_SM);//отранж DZ на Реле2
   SettingIci_RangirDZToRele(RELE3_SM);//отранж DZ на Реле3
   SettingIci_RangirDZToRele(RELE4_SM);//отранж DZ на Реле4
   SettingIci_RangirDZToRele(RELE5_SM);//отранж DZ на Реле5
   SettingIci_RangirDZToRele(RELE6_SM);//отранж DZ на Реле6

//-----------PRM1--------------------
   SettingIci_RangirPRM1ToDV(DV1_SM);//отранж PRM на ДВ1
   SettingIci_RangirPRM1ToDV(DV2_SM);//отранж PRM на ДВ2
   SettingIci_RangirPRM1ToDV(DV3_SM);//отранж PRM на ДВ3
   SettingIci_RangirPRM1ToDV(DV4_SM);//отранж PRM на ДВ4
   SettingIci_RangirPRM1ToDV(DV5_SM);//отранж PRM на ДВ5
   SettingIci_RangirPRM1ToDV(DV6_SM);//отранж PRM на ДВ6

   SettingIci_RangirPRM1ToRele(RELE1_SM);
   SettingIci_RangirPRM1ToRele(RELE2_SM);
   SettingIci_RangirPRM1ToRele(RELE3_SM);
   SettingIci_RangirPRM1ToRele(RELE4_SM);
   SettingIci_RangirPRM1ToRele(RELE5_SM);
   SettingIci_RangirPRM1ToRele(RELE6_SM);

//-----------NZOP--------------------
   SettingIci_RangirNZOPToDV(DV1_SM);//отранж NZOP на ДВ1
   SettingIci_RangirNZOPToDV(DV2_SM);//отранж NZOP на ДВ2
   SettingIci_RangirNZOPToDV(DV3_SM);//отранж NZOP на ДВ3
   SettingIci_RangirNZOPToDV(DV4_SM);//отранж NZOP на ДВ4
   SettingIci_RangirNZOPToDV(DV5_SM);//отранж NZOP на ДВ5
   SettingIci_RangirNZOPToDV(DV6_SM);//отранж NZOP на ДВ6

   SettingIci_RangirNZOPToRele(RELE1_SM);
   SettingIci_RangirNZOPToRele(RELE2_SM);
   SettingIci_RangirNZOPToRele(RELE3_SM);
   SettingIci_RangirNZOPToRele(RELE4_SM);
   SettingIci_RangirNZOPToRele(RELE5_SM);
   SettingIci_RangirNZOPToRele(RELE6_SM);

//-----------APV--------------------
   SettingIci_RangirAPVToDV(DV1_SM);
   SettingIci_RangirAPVToDV(DV2_SM);
   SettingIci_RangirAPVToDV(DV3_SM);
   SettingIci_RangirAPVToDV(DV4_SM);
   SettingIci_RangirAPVToDV(DV5_SM);
   SettingIci_RangirAPVToDV(DV6_SM);
   SettingIci_RangirAPVToDV(DV7_SM);
   SettingIci_RangirAPVToDV(DV8_SM);

   SettingIci_RangirAPVToRele(RELE1_SM);
   SettingIci_RangirAPVToRele(RELE2_SM);
   SettingIci_RangirAPVToRele(RELE3_SM);
   SettingIci_RangirAPVToRele(RELE4_SM);
   SettingIci_RangirAPVToRele(RELE5_SM);
   SettingIci_RangirAPVToRele(RELE6_SM);
//void SettingIci_RangirAPVToLed(int nLed);

//-----------UROV--------------------
   SettingIci_RangirUROVToDV(DV1_SM);
   SettingIci_RangirUROVToDV(DV2_SM);
   SettingIci_RangirUROVToDV(DV3_SM);
   SettingIci_RangirUROVToDV(DV4_SM);
   SettingIci_RangirUROVToDV(DV5_SM);
   SettingIci_RangirUROVToDV(DV6_SM);

   SettingIci_RangirUROVToRele(RELE1_SM);
   SettingIci_RangirUROVToRele(RELE2_SM);
   SettingIci_RangirUROVToRele(RELE3_SM);
   SettingIci_RangirUROVToRele(RELE4_SM);
   SettingIci_RangirUROVToRele(RELE5_SM);
   SettingIci_RangirUROVToRele(RELE6_SM);
//void SettingIci_RangirUROVToLed(int nLed);

//-----------OF--------------------
   SettingIci_RangirOFToDV(DV1_SM);
   SettingIci_RangirOFToDV(DV2_SM);
   SettingIci_RangirOFToDV(DV3_SM);
   SettingIci_RangirOFToDV(DV4_SM);
   SettingIci_RangirOFToDV(DV5_SM);
   SettingIci_RangirOFToDV(DV6_SM);

   SettingIci_RangirOFToRele(RELE1_SM);
   SettingIci_RangirOFToRele(RELE2_SM);
   SettingIci_RangirOFToRele(RELE3_SM);
   SettingIci_RangirOFToRele(RELE4_SM);
   SettingIci_RangirOFToRele(RELE5_SM);
   SettingIci_RangirOFToRele(RELE6_SM);

//-----------OT--------------------
   SettingIci_RangirOTToDV(DV1_SM);//уст сброс триг
   SettingIci_RangirOTToDV(DV2_SM);//уст сброс триг
   SettingIci_RangirOTToDV(DV3_SM);//уст сброс триг
   SettingIci_RangirOTToDV(DV4_SM);//уст сброс триг
   SettingIci_RangirOTToDV(DV5_SM);//уст сброс триг
   SettingIci_RangirOTToDV(DV6_SM);//уст сброс триг

//void SettingIci_RangirOTToRele(int nRele)

   SettingIci_RangirOutOTToRele(RELE1_SM);//Выход триг
   SettingIci_RangirOutOTToRele(RELE2_SM);//Выход триг
   SettingIci_RangirOutOTToRele(RELE3_SM);//Выход триг
   SettingIci_RangirOutOTToRele(RELE4_SM);//Выход триг
   SettingIci_RangirOutOTToRele(RELE5_SM);//Выход триг
   SettingIci_RangirOutOTToRele(RELE6_SM);//Выход триг

  PrepareBOBV();//подготовить Блок ОТКЛ, Блок ВКЛ

}//SettingIci_Rangir()

int isActivCmdDV(int numCmd, int numDV)
{
//проверка активности команды на ДВ
 //найти байт
 int numByte = numCmd/8;
 //найти бит
 int numBit  = numCmd%8;
 int rData = brCfgTbl.uc_ar_di_rank_cfg[numDV*AMOUNT_BYTE_FOR_IEPRF +numByte];
 //найти маску
 int Maska = 1<<numBit;
 //найти активность
 if(rData&Maska) return 1;
 return 0;
}//isActivCmdDV(int numCmd, int numDV)

int isActivCmdRele(int numCmd, int numRele)
{
//проверка активности команды на Реле
 //найти байт
 int numByte = numCmd/8;
 //найти бит
 int numBit  = numCmd%8;
 int rData = brCfgTbl.uc_ar_do_rank_cfg[numRele*AMOUNT_BYTE_FOR_OEPRF +numByte];
 //найти маску
 int Maska = 1<<numBit;
 //найти активность
 if(rData&Maska) return 1;
 return 0;
}//isActivCmdRele(int numCmd, int numRele)

int isActivCmdLed(int numCmd, int numLed)
{
//проверка активности команды на СДИ
 //найти байт
 int numByte = numCmd/8;
 //найти бит
 int numBit  = numCmd%8;
 int rData = brCfgTbl.uc_ar_led_rank_cfg[numLed*AMOUNT_BYTE_FOR_OEPRF +numByte];
 //найти маску
 int Maska = 1<<numBit;
 //найти активность
 if(rData&Maska) return 1;
 return 0;
}//isActivCmdLed(int numCmd, int numLed)
