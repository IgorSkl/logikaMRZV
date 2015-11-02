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
#include "SettingIci\SettingIci.h"
#include "virtualmenu\systemmenufnc.h"
#include "virtualMenu\rangmanagerfnc.h"

#include "toSpeedOptim.h"
#include "toSpeedDIS.h"

#include "header.h"
#include "ici_r_ef.h"

#define _HIDE_COMPONENT
#include "APVComponent.c"
#include "MTZ1Component.c"
#include "MTZ2Component.c"
#include "TZNP1Component.c"
#include "DZ1Component.c"
#include "DZ2Component.c"

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

/*
unsigned int   Rclr_U_ov_range1;
//.ПО АПВ 1 Контроль наявності уставка по по напряжению Uн шон 40 140 В шаг 0.01
//.	 уставка по по напряжению
//.	 1 ед = 1 мB
unsigned int   Rclr_U_ov_range2;
//.ПО АПВ 2 контроль відсутності
//.	 уставка по по напряжению 1  - 20 В 
//.	 1 ед = 1 мB
unsigned int   Rclr_U_ov_range3;
//.ПО АПВ 3 уставка по по напряжению Uн шон 40 140 В шаг 0.01
//.	 уставка по по напряжению
//.	 1 ед = 1 мB
unsigned int   Rclr_U_ov_range4;
//.ПО АПВ 4 1  - 20 В 
//.	 
//.	 1 ед = 1 мB

//syncro1
unsigned long Rclr_DeltaU;
//Разница напряжений Шаг 0.01
//1  - 20 В 
//syncro2
unsigned long Rclr_DeltaPhi;
//угол рассогласования
//5 до (+-)50 град Шаг 1 град

//Syncro3
unsigned long Rclr_DeltaPhi_Dt;
//Скорость скольжения
//5 - 30 град\с Шаг 0.01
*/

void  SettingIci_APV()
{
//PO1 APV
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrRclrPickup.Rclr_U_ov_range1;
  SetUstToClon(APV_COMP1,  1, MNGUST_PO1_APV, lMtz1);//уставка
//PO2 APV
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrRclrPickup.Rclr_U_ov_range2;
  SetUstToClon(APV_COMP1,  1, MNGUST_PO2_APV, lMtz1);//уставка
//PO3 APV
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrRclrPickup.Rclr_U_ov_range3;
  SetUstToClon(APV_COMP1,  1, MNGUST_PO3_APV, lMtz1);//уставка
//PO4 APV
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrRclrPickup.Rclr_U_ov_range4;
  SetUstToClon(APV_COMP1,  1, MNGUST_PO4_APV, lMtz1);//уставка

//voltage_different APV
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrRclrPickup.Rclr_DeltaU;
  SetUstToClon(APV_COMP1,  1, MNGUST_POVD_APV, lMtz1);//уставка
//angle_unbalance APV
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrRclrPickup.Rclr_DeltaPhi;
  SetUstToClon(APV_COMP1,  1, MNGUST_POAU_APV, lMtz1);//уставка
//speed_angle APV
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrRclrPickup.Rclr_DeltaPhi_Dt;
  SetUstToClon(APV_COMP1,  1, MNGUST_POSA_APV, lMtz1);//уставка

//Время 1 цикл АПВ tim2
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr1_T;
  SetUstToClon(APV_COMP1,  1, MNGVID1_APV, lMtz1Tmr*10);//уставка выдержки 

//Время 2 цикл АПВ tim3
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr2_T;
  SetUstToClon(APV_COMP1,  1, MNGVID2_APV, lMtz1Tmr*10);//уставка выдержки 

//Время Блокир АПВ tim8
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr2_T_blk;
  SetUstToClon(APV_COMP1,  1, MNGVID3_APV, lMtz1Tmr*10);//уставка выдержки 

//Время Блокир АПВ1 tim7
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr1_T_blk;
  SetUstToClon(APV_COMP1,  1, MNGVID4_APV, lMtz1Tmr*10);//уставка выдержки 

//Время Блокир АПВ от ВВ tim1
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr_T_blk_HSW;
  SetUstToClon(APV_COMP1,  1, MNGVID5_APV, lMtz1Tmr*10);//уставка выдержки 

//Время внеш запрета АПВ tim6
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr_T_forbid;
  SetUstToClon(APV_COMP1,  1, MNGVID6_APV, lMtz1Tmr*10);//уставка выдержки 

//Время ож напр АПВ1 tim9
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr1_T_wait_U;
  SetUstToClon(APV_COMP1,  1, MNGVID7_APV, lMtz1Tmr*10);//уставка выдержки 

//Время ож син  АПВ1 tim10
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr1_T_wait_sycro;
  SetUstToClon(APV_COMP1,  1, MNGVID8_APV, lMtz1Tmr*10);//уставка выдержки 

//Время ож напр АПВ2 tim11
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr2_T_wait_U;
  SetUstToClon(APV_COMP1,  1, MNGVID9_APV, lMtz1Tmr*10);//уставка выдержки 

//Время ож син  АПВ2 tim12
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrRclrStageParam.Rclr2_T_wait_syncro;
  SetUstToClon(APV_COMP1,  1, MNGVID10_APV, lMtz1Tmr*10);//уставка выдержки 

  int uprAPV=0;
  //меню  Состояние APV
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrRclrMng.state_Rclr;
  if(lSt1>0) uprAPV |= 32; //APV WKL
  else  uprAPV &= ~32; //APV OTKL 

  //меню  Состояние APV2
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrRclrMng.state_Rclr2;
  if(lSt1>0) uprAPV |= 64; //APV WKL
  else  uprAPV &= ~64; //APV OTKL 

//Без контроля
    lSt1 = brCfgTbl.ownrRclrMng.select_Mode_Rclr;//Селектор АПВ
  if(lSt1==0) {uprAPV &= ~7;} //uprAPV &= ~2; uprAPV &= ~4;} //APV WKL
//Нет линии есть шина
  if(lSt1==1) {uprAPV |= 1; uprAPV &= ~6;}// uprAPV &= ~4;} //APV WKL
//Есть линия нет шины
  if(lSt1==2) {uprAPV |= 2; uprAPV &= ~5;}// uprAPV &= ~4;} //APV WKL
//Есть линия есть шина Нет синхр
  if(lSt1==3) {uprAPV |= 3; uprAPV &= ~4;} //APV WKL
//Есть линия есть шина Есть синхр
  if(lSt1==4) {uprAPV |= 4; uprAPV &= ~3;}// uprAPV &= ~2;} //APV WKL

//Faza A
    lSt1 = brCfgTbl.ownrRclrMng.selectPhase;//Селектор фазы
  if(lSt1==0) {uprAPV &= ~(8+16);} //APV WKL
//Faza B
    lSt1 = brCfgTbl.ownrRclrMng.selectPhase;//Селектор фазы
  if(lSt1==1) {uprAPV |= 8; uprAPV &= ~(16);} //APV WKL
//Faza C
    lSt1 = brCfgTbl.ownrRclrMng.selectPhase;//Селектор фазы
  if(lSt1==2) {uprAPV |= 16; uprAPV &= ~(8);} //APV WKL
  
  SetUstToClon(APV_COMP1,  1, MNGUPR_APV, uprAPV);//управление APV

 extern UNS_32 pAPVcmdMaska[];//определение ЗапускАПВ

//Пуск APV от Защит
  for(int i=0; i<DQUADRO; i++) pAPVcmdMaska[i]=0;//Очистить
//----------------------------MTZ------------------------------
    lSt1 = puskAPVotZ(MCP1_STP_RCLR_ONB);//Пуск от МТЗ1
  if(lSt1) SetCmdToUVV(MTZ_COMP1,  1, IOCMD6_MTZ1, PUSKAPV_SM);//отранж MTZ1 на APV
    lSt1 = puskAPVotZ(MCP2_STP_RCLR_ONB);//Пуск от МТЗ2
  if(lSt1) SetCmdToUVV(MTZ_COMP1,  2, IOCMD8_MTZ2to5, PUSKAPV_SM);//отранж MTZ2 на APV
    lSt1 = puskAPVotZ(MCP3_STP_RCLR_ONB);//Пуск от МТЗ3
  if(lSt1) SetCmdToUVV(MTZ_COMP1,  3, IOCMD8_MTZ2to5, PUSKAPV_SM);//отранж MTZ3 на APV
    lSt1 = puskAPVotZ(MCP4_STP_RCLR_ONB);//Пуск от МТЗ4
  if(lSt1) SetCmdToUVV(MTZ_COMP1,  4, IOCMD8_MTZ2to5, PUSKAPV_SM);//отранж MTZ4 на APV
    lSt1 = puskAPVotZ(MCP5_STP_RCLR_ONB);//Пуск от МТЗ5
  if(lSt1) SetCmdToUVV(MTZ_COMP1,  5, IOCMD8_MTZ2to5, PUSKAPV_SM);//отранж MTZ5 на APV

//----------------------------TZNP------------------------------
    lSt1 = puskAPVotZ(TZNP1_STP_RCLR_ONB);//Сраб ТЗНП1
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  1, IOCMD5_TZNP1to5, PUSKAPV_SM);//отранж на APV
    lSt1 = puskAPVotZ(TZNP1_3U0_STP_RCLR_ONB);//Сраб ЗНП1(3U0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  1, IOCMD9_TZNP1to5, PUSKAPV_SM);//отранж на APV
    lSt1 = puskAPVotZ(TZNP1_3I0_STP_RCLR_ONB);//Сраб ЗНП1(3I0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  1, IOCMD7_TZNP1to5, PUSKAPV_SM);//отранж на APV
    lSt1 = puskAPVotZ(TZNP2_STP_RCLR_ONB);//Сраб ТЗНП2
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  2, IOCMD5_TZNP1to5, PUSKAPV_SM);//отранж на APV
    lSt1 = puskAPVotZ(TZNP2_3U0_STP_RCLR_ONB);//Сраб ЗНП2(3U0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  2, IOCMD9_TZNP1to5, PUSKAPV_SM);//отранж на APV
    lSt1 = puskAPVotZ(TZNP2_3I0_STP_RCLR_ONB);//Сраб ЗНП2(3I0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  2, IOCMD7_TZNP1to5, PUSKAPV_SM);//отранж на APV
    lSt1 = puskAPVotZ(TZNP3_STP_RCLR_ONB);//Сраб ТЗНП3
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  3, IOCMD5_TZNP1to5, PUSKAPV_SM);//отранж на APV
    lSt1 = puskAPVotZ(TZNP3_3U0_STP_RCLR_ONB);//Сраб ЗНП3(3U0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  3, IOCMD9_TZNP1to5, PUSKAPV_SM);//отранж на APV
    lSt1 = puskAPVotZ(TZNP3_3I0_STP_RCLR_ONB);//Сраб ЗНП3(3I0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  3, IOCMD7_TZNP1to5, PUSKAPV_SM);//отранж на APV
    lSt1 = puskAPVotZ(TZNP4_STP_RCLR_ONB);//Сраб ТЗНП4
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  4, IOCMD5_TZNP1to5, PUSKAPV_SM);//отранж на APV
    lSt1 = puskAPVotZ(TZNP4_3U0_STP_RCLR_ONB);//Сраб ЗНП4(3U0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  4, IOCMD9_TZNP1to5, PUSKAPV_SM);//отранж на APV
    lSt1 = puskAPVotZ(TZNP4_3I0_STP_RCLR_ONB);//Сраб ЗНП4(3I0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  4, IOCMD7_TZNP1to5, PUSKAPV_SM);//отранж на APV
    lSt1 = puskAPVotZ(TZNP5_STP_RCLR_ONB);//Сраб ТЗНП5
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  5, IOCMD5_TZNP1to5, PUSKAPV_SM);//отранж на APV
    lSt1 = puskAPVotZ(TZNP5_3U0_STP_RCLR_ONB);//Сраб ЗНП5(3U0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  5, IOCMD9_TZNP1to5, PUSKAPV_SM);//отранж на APV
    lSt1 = puskAPVotZ(TZNP5_3I0_STP_RCLR_ONB);//Сраб ЗНП5(3I0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  5, IOCMD7_TZNP1to5, PUSKAPV_SM);//отранж на APV

//----------------------------DZ------------------------------
    lSt1 = puskAPVotZ(DSTP1_STP_RCLR_ONB);//Сраб ДТЗ1
  if(lSt1) {
             SetCmdToUVV(DZ_COMP1,  1, IOCMD3_DZ1, PUSKAPV_SM);//отранж на APV
             SetCmdToUVV(DZ_COMP1,  1, IOCMD7_DZ1, PUSKAPV_SM);//отранж на APV
           }//if  
    lSt1 = puskAPVotZ(DSTP2_STP_RCLR_ONB);//Сраб ДТЗ2
  if(lSt1) {
             SetCmdToUVV(DZ_COMP1,  2, IOCMD5_DZ2to5MF, PUSKAPV_SM);//отранж на APV
             SetCmdToUVV(DZ_COMP1,  2, IOCMD5_DZ2to5OF, PUSKAPV_SM);//отранж на APV
           }//if  
    lSt1 = puskAPVotZ(DSTP3_STP_RCLR_ONB);//Сраб ДТЗ3
  if(lSt1) {
             SetCmdToUVV(DZ_COMP1,  3, IOCMD5_DZ2to5MF, PUSKAPV_SM);//отранж на APV
             SetCmdToUVV(DZ_COMP1,  3, IOCMD5_DZ2to5OF, PUSKAPV_SM);//отранж на APV
           }//if  
    lSt1 = puskAPVotZ(DSTP4_STP_RCLR_ONB);//Сраб ДТЗ4
  if(lSt1) {
             SetCmdToUVV(DZ_COMP1,  4, IOCMD5_DZ2to5MF, PUSKAPV_SM);//отранж на APV
             SetCmdToUVV(DZ_COMP1,  4, IOCMD5_DZ2to5OF, PUSKAPV_SM);//отранж на APV
           }//if  
    lSt1 = puskAPVotZ(DSTP5_STP_RCLR_ONB);//Сраб ДТЗ5
  if(lSt1) {
             SetCmdToUVV(DZ_COMP1,  5, IOCMD5_DZ2to5MF, PUSKAPV_SM);//отранж на APV
             SetCmdToUVV(DZ_COMP1,  5, IOCMD5_DZ2to5OF, PUSKAPV_SM);//отранж на APV
           }//if  

    lSt1 = puskAPVotZ(MCP1_DSTP1_STP_RCLR_ONB);//Сраб МТЗ1 ДТЗ1
  if(lSt1) SetCmdToUVV(DZ_COMP1,  1, IOCMD5_DZ1, PUSKAPV_SM);//отранж на APV
    lSt1 = puskAPVotZ(MCP2_DSTP2_STP_RCLR_ONB);//Сраб МТЗ2 ДТЗ2
  if(lSt1) SetCmdToUVV(DZ_COMP1,  2, IOCMD5_MDZ2to5MF, PUSKAPV_SM);//отранж на APV
    lSt1 = puskAPVotZ(MCP3_DSTP3_STP_RCLR_ONB);//Сраб МТЗ3 ДТЗ3
  if(lSt1) SetCmdToUVV(DZ_COMP1,  3, IOCMD5_MDZ2to5MF, PUSKAPV_SM);//отранж на APV
    lSt1 = puskAPVotZ(MCP4_DSTP4_STP_RCLR_ONB);//Сраб МТЗ4 ДТЗ4
  if(lSt1) SetCmdToUVV(DZ_COMP1,  4, IOCMD5_MDZ2to5MF, PUSKAPV_SM);//отранж на APV
    lSt1 = puskAPVotZ(MCP5_DSTP5_STP_RCLR_ONB);//Сраб МТЗ5 ДТЗ5
  if(lSt1) SetCmdToUVV(DZ_COMP1,  5, IOCMD5_MDZ2to5MF, PUSKAPV_SM);//отранж на APV

}//SettingIci_APV()

int puskAPVotZ(int num)
{
//Пуск от Защит
  int rez=0;
    if(brCfgTbl.ownrRclrMng.ar_Rclr_Stp_Cmd_state[num/8]&(1<<(num%8))) rez=1;
  return rez;
}//puskAPVotZ(int num)

/*
DSTP1_STP_RCLR_ONB                       ,//Сраб ДТЗ1
DSTP2_STP_RCLR_ONB                       ,//Сраб ДТЗ2
DSTP3_STP_RCLR_ONB                       ,//Сраб ДТЗ3
DSTP4_STP_RCLR_ONB                       ,//Сраб ДТЗ4
DSTP5_STP_RCLR_ONB                       ,//Сраб ДТЗ5

MCP1_DSTP1_STP_RCLR_ONB                  ,//Сраб МТЗ1 ДТЗ1
MCP2_DSTP2_STP_RCLR_ONB                  ,//Сраб МТЗ2 ДТЗ2
MCP3_DSTP3_STP_RCLR_ONB                  ,//Сраб МТЗ3 ДТЗ3
MCP4_DSTP4_STP_RCLR_ONB                  ,//Сраб МТЗ4 ДТЗ4
MCP5_DSTP5_STP_RCLR_ONB                  ,//Сраб МТЗ5 ДТЗ5

*/