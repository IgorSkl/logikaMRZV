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
//Iclude "SettingIci\SettingIci.h"

#include "toSpeedOptim.h"
#include "toSpeedDIS.h"

#include "header.h"
#include "ici_r_ef.h"

#define _HIDE_COMPONENT
#include "UROVComponent.c"
#include "MTZ1Component.c"
#include "MTZ2Component.c"
#include "TZNP1Component.c"
#include "DZ1Component.c"
#include "DZ2Component.c"
#include "UMMcomponent.c"
#include "NZOP1component.c"

extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;

void  SettingIci_UROV()
{
//уставки UROV
     lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrBrfPickup.ov_range_Urov;
     SetUstToClon(UROV_COMP1,  1, MNGUST_UROV, lMtz1);//уставка по току

//выдержки UROV
     lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrBrfStageParam.time_stage_Urov1;//Выдержка 1 Ступени УРОВ
  SetUstToClon(UROV_COMP1,  1, MNGVID_UROV1, lMtz1Tmr*10);//выдержкa UROV1
     lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrBrfStageParam.time_stage_Urov2;//Выдержка 2 Ступени УРОВ
  SetUstToClon(UROV_COMP1,  1, MNGVID_UROV2, lMtz1Tmr*10);//выдержкa UROV2

//управление УРОВ
  int uprUROV = 0;
     lSt1 = brCfgTbl.ownrBrfMng.state_Urov;//Состояние УРОВ
  if(lSt1>0) uprUROV |= 1; // WKL
  else  uprUROV &= ~1; // OTKL 
  SetUstToClon(UROV_COMP1,  1, MNGUPR_UROV, uprUROV);//управление UROV

 extern UNS_32 pUROVcmdMaska[];//определение Запуск UROV

//Пуск UROV от Защит
  for(int i=0; i<DQUADRO; i++) pUROVcmdMaska[i]=0;//Очистить
//----------------------------UMM------------------------------
/*
UMAX1_STP_BRF_ONB                    ,//Сраб UMAX1
UMAX2_STP_BRF_ONB                    ,//Сраб UMAX2
UMIN1_STP_BRF_ONB                    ,//Сраб Umin1
UMIN2_STP_BRF_ONB                    ,//Сраб Umin2 
*/
    lSt1 = puskUROVotZ(UMAX1_STP_BRF_ONB);//Сраб UMAX1
  if(lSt1) SetCmdToUVV(UMM_COMP1,  1, IOCMD6_UMM, PUSKUROV_SM);//отранж UMAX1 на UROV
    lSt1 = puskUROVotZ(UMAX2_STP_BRF_ONB);//Сраб UMAX2
  if(lSt1) SetCmdToUVV(UMM_COMP1,  1, IOCMD8_UMM, PUSKUROV_SM);//отранж UMAX2 на UROV
    lSt1 = puskUROVotZ(UMIN1_STP_BRF_ONB);//Сраб UMIN1
  if(lSt1) SetCmdToUVV(UMM_COMP1,  1, IOCMD10_UMM, PUSKUROV_SM);//отранж UMIN1 на UROV
    lSt1 = puskUROVotZ(UMIN2_STP_BRF_ONB);//Сраб UMIN2
  if(lSt1) SetCmdToUVV(UMM_COMP1,  1, IOCMD12_UMM, PUSKUROV_SM);//отранж UMIN2 на UROV

//----------------------------NZOP------------------------------
    lSt1 = puskUROVotZ(ZOP1_STP_BRF_ONB);//Пуск от NZOP1
  if(lSt1) SetCmdToUVV(NZOP_COMP1,  1, IOCMD5_NZOP1to2, PUSKUROV_SM);//отранж ZOP1 на UROV
    lSt1 = puskUROVotZ(ZOP2_STP_BRF_ONB);//Пуск от NZOP2
  if(lSt1) SetCmdToUVV(NZOP_COMP1,  2, IOCMD5_NZOP1to2, PUSKUROV_SM);//отранж ZOP2 на UROV

//----------------------------MTZ------------------------------
    lSt1 = puskUROVotZ(MCP1_STP_BRF_ONB);//Пуск от МТЗ1
  if(lSt1) SetCmdToUVV(MTZ_COMP1,  1, IOCMD6_MTZ1, PUSKUROV_SM);//отранж MTZ1 на UROV
    lSt1 = puskUROVotZ(MCP2_STP_BRF_ONB);//Пуск от МТЗ2
  if(lSt1) SetCmdToUVV(MTZ_COMP1,  2, IOCMD8_MTZ2to5, PUSKUROV_SM);//отранж MTZ2 на UROV
    lSt1 = puskUROVotZ(MCP3_STP_BRF_ONB);//Пуск от МТЗ3
  if(lSt1) SetCmdToUVV(MTZ_COMP1,  3, IOCMD8_MTZ2to5, PUSKUROV_SM);//отранж MTZ3 на UROV
    lSt1 = puskUROVotZ(MCP4_STP_BRF_ONB);//Пуск от МТЗ4
  if(lSt1) SetCmdToUVV(MTZ_COMP1,  4, IOCMD8_MTZ2to5, PUSKUROV_SM);//отранж MTZ4 на UROV
    lSt1 = puskUROVotZ(MCP5_STP_BRF_ONB);//Пуск от МТЗ5
  if(lSt1) SetCmdToUVV(MTZ_COMP1,  5, IOCMD8_MTZ2to5, PUSKUROV_SM);//отранж MTZ5 на UROV

//----------------------------TZNP------------------------------
    lSt1 = puskUROVotZ(TZNP1_STP_BRF_ONB);//Сраб ТЗНП1
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  1, IOCMD5_TZNP1to5, PUSKUROV_SM);//отранж на UROV
    lSt1 = puskUROVotZ(TZNP1_3U0_STP_BRF_ONB);//Сраб ЗНП1(3U0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  1, IOCMD9_TZNP1to5, PUSKUROV_SM);//отранж на UROV
    lSt1 = puskUROVotZ(TZNP1_3I0_STP_BRF_ONB);//Сраб ЗНП1(3I0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  1, IOCMD7_TZNP1to5, PUSKUROV_SM);//отранж на UROV
    lSt1 = puskUROVotZ(TZNP2_STP_BRF_ONB);//Сраб ТЗНП2
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  2, IOCMD5_TZNP1to5, PUSKUROV_SM);//отранж на UROV
    lSt1 = puskUROVotZ(TZNP2_3U0_STP_BRF_ONB);//Сраб ЗНП2(3U0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  2, IOCMD9_TZNP1to5, PUSKUROV_SM);//отранж на UROV
    lSt1 = puskUROVotZ(TZNP2_3I0_STP_BRF_ONB);//Сраб ЗНП2(3I0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  2, IOCMD7_TZNP1to5, PUSKUROV_SM);//отранж на UROV
    lSt1 = puskUROVotZ(TZNP3_STP_BRF_ONB);//Сраб ТЗНП3
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  3, IOCMD5_TZNP1to5, PUSKUROV_SM);//отранж на UROV
    lSt1 = puskUROVotZ(TZNP3_3U0_STP_BRF_ONB);//Сраб ЗНП3(3U0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  3, IOCMD9_TZNP1to5, PUSKUROV_SM);//отранж на UROV
    lSt1 = puskUROVotZ(TZNP3_3I0_STP_BRF_ONB);//Сраб ЗНП3(3I0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  3, IOCMD7_TZNP1to5, PUSKUROV_SM);//отранж на UROV
    lSt1 = puskUROVotZ(TZNP4_STP_BRF_ONB);//Сраб ТЗНП4
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  4, IOCMD5_TZNP1to5, PUSKUROV_SM);//отранж на UROV
    lSt1 = puskUROVotZ(TZNP4_3U0_STP_BRF_ONB);//Сраб ЗНП4(3U0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  4, IOCMD9_TZNP1to5, PUSKUROV_SM);//отранж на UROV
    lSt1 = puskUROVotZ(TZNP4_3I0_STP_BRF_ONB);//Сраб ЗНП4(3I0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  4, IOCMD7_TZNP1to5, PUSKUROV_SM);//отранж на UROV
    lSt1 = puskUROVotZ(TZNP5_STP_BRF_ONB);//Сраб ТЗНП5
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  5, IOCMD5_TZNP1to5, PUSKUROV_SM);//отранж на UROV
    lSt1 = puskUROVotZ(TZNP5_3U0_STP_BRF_ONB);//Сраб ЗНП5(3U0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  5, IOCMD9_TZNP1to5, PUSKUROV_SM);//отранж на UROV
    lSt1 = puskUROVotZ(TZNP5_3I0_STP_BRF_ONB);//Сраб ЗНП5(3I0)
  if(lSt1) SetCmdToUVV(TZNP_COMP1,  5, IOCMD7_TZNP1to5, PUSKUROV_SM);//отранж на UROV

//----------------------------UMM------------------------------
    lSt1 = puskUROVotZ(UMAX1_STP_BRF_ONB);//Сраб UMAX1
  if(lSt1) SetCmdToUVV(UMM_COMP1,  1, IOCMD6_UMM, PUSKUROV_SM);//отранж на UROV
//UMAX1_STP_BRF_ONB                    ,//Сраб UMAX1
    lSt1 = puskUROVotZ(UMAX2_STP_BRF_ONB);//Сраб UMAX2
  if(lSt1) SetCmdToUVV(UMM_COMP1,  1, IOCMD8_UMM, PUSKUROV_SM);//отранж на UROV
//UMAX2_STP_BRF_ONB                    ,//Сраб UMAX2
    lSt1 = puskUROVotZ(UMIN1_STP_BRF_ONB);//Сраб UMIN1
  if(lSt1) SetCmdToUVV(UMM_COMP1,  1, IOCMD10_UMM, PUSKUROV_SM);//отранж на UROV
//UMIN1_STP_BRF_ONB                    ,//Сраб Umin1
    lSt1 = puskUROVotZ(UMIN2_STP_BRF_ONB);//Сраб UMAX1
  if(lSt1) SetCmdToUVV(UMM_COMP1,  1, IOCMD12_UMM, PUSKUROV_SM);//отранж на UROV
//UMIN2_STP_BRF_ONB                    ,//Сраб Umin2 

//----------------------------DZ------------------------------
    lSt1 = puskUROVotZ(DSTP1_STP_BRF_ONB);//Сраб ДТЗ1
  if(lSt1) {
             SetCmdToUVV(DZ_COMP1,  1, IOCMD3_DZ1, PUSKUROV_SM);//отранж на UROV
             SetCmdToUVV(DZ_COMP1,  1, IOCMD7_DZ1, PUSKUROV_SM);//отранж на UROV
           }//if  
    lSt1 = puskUROVotZ(DSTP2_STP_BRF_ONB);//Сраб ДТЗ2
  if(lSt1) {
             SetCmdToUVV(DZ_COMP1,  2, IOCMD5_DZ2to5MF, PUSKUROV_SM);//отранж на UROV
             SetCmdToUVV(DZ_COMP1,  2, IOCMD5_DZ2to5OF, PUSKUROV_SM);//отранж на UROV
           }//if  
    lSt1 = puskUROVotZ(DSTP3_STP_BRF_ONB);//Сраб ДТЗ3
  if(lSt1) {
             SetCmdToUVV(DZ_COMP1,  3, IOCMD5_DZ2to5MF, PUSKUROV_SM);//отранж на UROV
             SetCmdToUVV(DZ_COMP1,  3, IOCMD5_DZ2to5OF, PUSKUROV_SM);//отранж на UROV
           }//if  
    lSt1 = puskUROVotZ(DSTP4_STP_BRF_ONB);//Сраб ДТЗ4
  if(lSt1) {
             SetCmdToUVV(DZ_COMP1,  4, IOCMD5_DZ2to5MF, PUSKUROV_SM);//отранж на UROV
             SetCmdToUVV(DZ_COMP1,  4, IOCMD5_DZ2to5OF, PUSKUROV_SM);//отранж на UROV
           }//if  
    lSt1 = puskUROVotZ(DSTP5_STP_BRF_ONB);//Сраб ДТЗ5
  if(lSt1) {
             SetCmdToUVV(DZ_COMP1,  5, IOCMD5_DZ2to5MF, PUSKUROV_SM);//отранж на UROV
             SetCmdToUVV(DZ_COMP1,  5, IOCMD5_DZ2to5OF, PUSKUROV_SM);//отранж на UROV
           }//if  

    lSt1 = puskUROVotZ(MCP1_DSTP1_STP_BRF_ONB);//Сраб МТЗ1 ДТЗ1
  if(lSt1) SetCmdToUVV(DZ_COMP1,  1, IOCMD5_DZ1, PUSKUROV_SM);//отранж на UROV
    lSt1 = puskUROVotZ(MCP2_DSTP2_STP_BRF_ONB);//Сраб МТЗ2 ДТЗ2
  if(lSt1) SetCmdToUVV(DZ_COMP1,  2, IOCMD5_MDZ2to5MF, PUSKUROV_SM);//отранж на UROV
    lSt1 = puskUROVotZ(MCP3_DSTP3_STP_BRF_ONB);//Сраб МТЗ3 ДТЗ3
  if(lSt1) SetCmdToUVV(DZ_COMP1,  3, IOCMD5_MDZ2to5MF, PUSKUROV_SM);//отранж на UROV
    lSt1 = puskUROVotZ(MCP4_DSTP4_STP_BRF_ONB);//Сраб МТЗ4 ДТЗ4
  if(lSt1) SetCmdToUVV(DZ_COMP1,  4, IOCMD5_MDZ2to5MF, PUSKUROV_SM);//отранж на UROV
    lSt1 = puskUROVotZ(MCP5_DSTP5_STP_BRF_ONB);//Сраб МТЗ5 ДТЗ5
  if(lSt1) SetCmdToUVV(DZ_COMP1,  5, IOCMD5_MDZ2to5MF, PUSKUROV_SM);//отранж на UROV

}//SettingIci_UROV()

int puskUROVotZ(int num)
{
//Пуск UROV от Защит
  int rez=0;
    if(brCfgTbl.ownrBrfMng.ar_Brf_Stp_Cmd_state[num/8]&(1<<(num%8))) rez=1;
  return rez;
}//puskUROVotZ(int num)
