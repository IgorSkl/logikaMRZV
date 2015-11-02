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

#include "toSpeedOptim.h"
#include "toSpeedDIS.h"

#include "header.h"
#include "ici_r_ef.h"

#define _HIDE_COMPONENT
#include "DZ2Component.c"

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

/*
 float X1OF_DZ2, Y1OF_DZ2, X2OF_DZ2, Y2OF_DZ2;
 float X3OF_DZ2, Y3OF_DZ2, X4OF_DZ2, Y4OF_DZ2;
 float X1MF_DZ2, Y1MF_DZ2, X2MF_DZ2, Y2MF_DZ2;
 float X3MF_DZ2, Y3MF_DZ2, X4MF_DZ2, Y4MF_DZ2;

 float X1OF_DZ3, Y1OF_DZ3, X2OF_DZ3, Y2OF_DZ3;
 float X3OF_DZ3, Y3OF_DZ3, X4OF_DZ3, Y4OF_DZ3;
 float X1MF_DZ3, Y1MF_DZ3, X2MF_DZ3, Y2MF_DZ3;
 float X3MF_DZ3, Y3MF_DZ3, X4MF_DZ3, Y4MF_DZ3;
                                             
 float X1OF_DZ4, Y1OF_DZ4, X2OF_DZ4, Y2OF_DZ4;
 float X3OF_DZ4, Y3OF_DZ4, X4OF_DZ4, Y4OF_DZ4;
 float X1MF_DZ4, Y1MF_DZ4, X2MF_DZ4, Y2MF_DZ4;
 float X3MF_DZ4, Y3MF_DZ4, X4MF_DZ4, Y4MF_DZ4;

 float X1OF_DZ5, Y1OF_DZ5, X2OF_DZ5, Y2OF_DZ5;
 float X3OF_DZ5, Y3OF_DZ5, X4OF_DZ5, Y4OF_DZ5;
 float X1MF_DZ5, Y1MF_DZ5, X2MF_DZ5, Y2MF_DZ5;
 float X3MF_DZ5, Y3MF_DZ5, X4MF_DZ5, Y4MF_DZ5;
*/

void  SettingIci_DZ2to5()
{
//установки ICI DZ2to5
//  float diskr = 0.001;
//-----------DZ2------------------------------------  
//Ток МТЗ ДЗ2МФ
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2Pickup.Dstp2_Iovp_ov_range;
    SetUstToClon(DZ_COMP1,  2, MNGUST_DZ2to5_MTZ, lMtz1);//уставка MTZ
//-----------OF
//Re1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P1_R;
//    X1OF_DZ2 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  2, MNGUST_DZ2to5_OX1, lMtz1);//уставка X1OF_DZ2
//Im1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P1_X;
//    Y1OF_DZ2 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  2, MNGUST_DZ2to5_OY1, lMtz1);//уставка Y1OF_DZ2

//Re2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P2_R;
//    X2OF_DZ2 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  2, MNGUST_DZ2to5_OX2, lMtz1);//уставка X2OF_DZ2
//Im2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P2_X;
//    Y2OF_DZ2 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  2, MNGUST_DZ2to5_OY2, lMtz1);//уставка Y2OF_DZ2

//Re3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P3_R;
//    X3OF_DZ2 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  2, MNGUST_DZ2to5_OX3, lMtz1);//уставка X3OF_DZ2
//Im3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P3_X;
//    Y3OF_DZ2 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  2, MNGUST_DZ2to5_OY3, lMtz1);//уставка Y3OF_DZ2

//Re4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P4_R;
//    X4OF_DZ2 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  2, MNGUST_DZ2to5_OX4, lMtz1);//уставка X4OF_DZ2
//Im4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2Pickup.Z_OF_Dstp2_P4_X;
//    Y4OF_DZ2 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  2, MNGUST_DZ2to5_OY4, lMtz1);//уставка Y4OF_DZ2

//-----------MF
//Re1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P1_R;
//    X1MF_DZ2 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  2, MNGUST_DZ2to5_MX1, lMtz1);//уставка X1MF_DZ2
//Im1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P1_X;
//    Y1MF_DZ2 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  2, MNGUST_DZ2to5_MY1, lMtz1);//уставка Y1MF_DZ2

//Re2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P2_R;
//    X2MF_DZ2 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  2, MNGUST_DZ2to5_MX2, lMtz1);//уставка X2MF_DZ2
//Im2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P2_X;
//    Y2MF_DZ2 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  2, MNGUST_DZ2to5_MY2, lMtz1);//уставка Y2MF_DZ2

//Re3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P3_R;
//    X3MF_DZ2 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  2, MNGUST_DZ2to5_MX3, lMtz1);//уставка X3MF_DZ2
//Im3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P3_X;
//    Y3MF_DZ2 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  2, MNGUST_DZ2to5_MY3, lMtz1);//уставка Y3MF_DZ2

//Re4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P4_R;
//    X4MF_DZ2 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  2, MNGUST_DZ2to5_MX4, lMtz1);//уставка X4MF_DZ2
//Im4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2Pickup.Z_MF_Dstp2_P4_X;
//    Y4MF_DZ2 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  2, MNGUST_DZ2to5_MY4, lMtz1);//уставка Y4MF_DZ2
    
//DZ2MF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2StageParam.Dstp2_MF_T;

  SetUstToClon(DZ_COMP1,  2, MNGVID_DZ2to5MF, lMtz1Tmr*10);//уставка выдержки DZ2MF
  
//MTZ DZ2MF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2StageParam.Dstp2_Ocp_T;

  SetUstToClon(DZ_COMP1,  2, MNGVID_MDZ2to5MF, lMtz1Tmr*10);//уставка выдержки MTZ DZ2MF

//DZ2OF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2StageParam.Dstp2_OF_T;

  SetUstToClon(DZ_COMP1,  2, MNGVID_DZ2to5OF, lMtz1Tmr*10);//уставка выдержки MTZ DZ2OF
  
//ускорение  
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2StageParam.Dstp2_HWS_Tau_Aclt;

  SetUstToClon(DZ_COMP1,  2, MNGVUSK_DZ2to5MF, lMtz1Tmr*10);//уставка ввод ускор ДЗ2 МФ
  
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;

  SetUstToClon(DZ_COMP1,  2, MNGVUSK_MDZ2to5MF, lMtz1Tmr*10);//уставка ввод ускор MTZ ДЗ2 МФ

   //DZ2MF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2StageParam.Dstp2_MF_T_aclt;

  SetUstToClon(DZ_COMP1,  2, MNGUSK_DZ2to5MF_VV, lMtz1Tmr*10);//уставка ускор ДЗ2 МФ BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2StageParam.Dstp2_MF_T_op_aclt;

  SetUstToClon(DZ_COMP1,  2, MNGUSK_DZ2to5MF_OU, lMtz1Tmr*10);//уставка ускор ДЗ2 МФ OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2StageParam.Dstp2_MF_T_tele_aclt;

  SetUstToClon(DZ_COMP1,  2, MNGUSK_DZ2to5MF_TU, lMtz1Tmr*10);//уставка ускор ДЗ2 МФ TU

   //MTZ DZ2MF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2StageParam.Dstp2_Ocp_T_aclt;

  SetUstToClon(DZ_COMP1,  2, MNGUSK_MDZ2to5MF_VV, lMtz1Tmr*10);//уставка ускор MTZ ДЗ2 МФ BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2StageParam.Dstp2_Ocp_T_op_aclt;

  SetUstToClon(DZ_COMP1,  2, MNGUSK_MDZ2to5MF_OU, lMtz1Tmr*10);//уставка ускор MTZ ДЗ2 МФ OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;

  SetUstToClon(DZ_COMP1,  2, MNGUSK_MDZ2to5MF_TU, lMtz1Tmr*10);//уставка ускор MTZ ДЗ2 МФ TU

   //DZ2OF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2StageParam.Dstp2_OF_T_aclt;

  SetUstToClon(DZ_COMP1,  2, MNGUSK_DZ2to5OF_VV, lMtz1Tmr*10);//уставка ускор ДЗ2 OФ BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2StageParam.Dstp2_OF_T_op_aclt;

  SetUstToClon(DZ_COMP1,  2, MNGUSK_DZ2to5OF_OU, lMtz1Tmr*10);//уставка ускор ДЗ2 OФ OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2Dstp2StageParam.Dstp2_OF_T_tele_aclt;

  SetUstToClon(DZ_COMP1,  2, MNGUSK_DZ2to5OF_TU, lMtz1Tmr*10);//уставка ускор ДЗ2 OФ TU

  int uprDZ2=0;
  //меню  Состояние DZ2    
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg2Dstp2Mng.state_dstp2;
  if(lSt1>0) uprDZ2 |= 1; //DZ2 WKL
  else  uprDZ2 &= ~1; //DZ2 OTKL 
  //меню   MTZ DZ2
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg2Dstp2Mng.state_ocp_dstp2;
  if(lSt1>0) uprDZ2 |= 2; //MTZ DZ2 WKL
  else  uprDZ2 &= ~2; //MTZ DZ2 OTKL 
  //меню   ускор ВВ DZ2
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg2Dstp2Mng.state_aclt_dstp2_hws;
  if(lSt1>0) uprDZ2 |= 4; //ускор BB DZ2 WKL
  else  uprDZ2 &= ~4; //ускор BB DZ2 OTKL 
  //меню   ускор AU DZ2
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg2Dstp2Mng.state_Auto_aclt_dstp2;
  if(lSt1>0) uprDZ2 |= 8; //ускор AU DZ2 WKL
  else  uprDZ2 &= ~8; //ускор AU DZ2 OTKL 
  //меню   ускор TU DZ2
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg2Dstp2Mng.state_Tele_aclt_dstp2;
  if(lSt1>0) uprDZ2 |= 16; //ускор TU DZ2 WKL
  else  uprDZ2 &= ~16; //ускор TU DZ2 OTKL 
  
  SetUstToClon(DZ_COMP1,  2, MNGUPR_DZ2to5, uprDZ2);//управление DZ2

//-----------DZ3------------------------------------  
//Ток МТЗ ДЗ3МФ
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2Pickup.Dstp2_Iovp_ov_range;
    SetUstToClon(DZ_COMP1,  3, MNGUST_DZ2to5_MTZ, lMtz1);//уставка MTZ
//-----------OF
//Re1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P1_R;
//    X1OF_DZ3 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  3, MNGUST_DZ2to5_OX1, lMtz1);//уставка X1OF_DZ3
//Im1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P1_X;
//    Y1OF_DZ3 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  3, MNGUST_DZ2to5_OY1, lMtz1);//уставка Y1OF_DZ3

//Re2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P2_R;
//    X2OF_DZ3 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  3, MNGUST_DZ2to5_OX2, lMtz1);//уставка X2OF_DZ3
//Im2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P2_X;
//    Y2OF_DZ3 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  3, MNGUST_DZ2to5_OY2, lMtz1);//уставка Y2OF_DZ3

//Re3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P3_R;
//    X3OF_DZ3 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  3, MNGUST_DZ2to5_OX3, lMtz1);//уставка X3OF_DZ3
//Im3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P3_X;
//    Y3OF_DZ3 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  3, MNGUST_DZ2to5_OY3, lMtz1);//уставка Y3OF_DZ3

//Re4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P4_R;
//    X4OF_DZ3 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  3, MNGUST_DZ2to5_OX4, lMtz1);//уставка X4OF_DZ3
//Im4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2Pickup.Z_OF_Dstp2_P4_X;
//    Y4OF_DZ3 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  3, MNGUST_DZ2to5_OY4, lMtz1);//уставка Y4OF_DZ3

    //-----------MF
//Re1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P1_R;
//    X1MF_DZ3 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  3, MNGUST_DZ2to5_MX1, lMtz1);//уставка X1MF_DZ3
//Im1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P1_X;
//    Y1MF_DZ3 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  3, MNGUST_DZ2to5_MY1, lMtz1);//уставка Y1MF_DZ3

//Re2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P2_R;
//    X2MF_DZ3 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  3, MNGUST_DZ2to5_MX2, lMtz1);//уставка X2MF_DZ3
//Im2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P2_X;
//    Y2MF_DZ3 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  3, MNGUST_DZ2to5_MY2, lMtz1);//уставка Y2MF_DZ3

//Re3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P3_R;
//    X3MF_DZ3 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  3, MNGUST_DZ2to5_MX3, lMtz1);//уставка X3MF_DZ3
//Im3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P3_X;
//    Y3MF_DZ3 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  3, MNGUST_DZ2to5_MY3, lMtz1);//уставка Y3MF_DZ3

//Re4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P4_R;
//    X4MF_DZ3 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  3, MNGUST_DZ2to5_MX4, lMtz1);//уставка X4MF_DZ3
//Im4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2Pickup.Z_MF_Dstp2_P4_X;
//    Y4MF_DZ3 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  3, MNGUST_DZ2to5_MY4, lMtz1);//уставка Y4MF_DZ3

//DZ3MF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2StageParam.Dstp2_MF_T;

  SetUstToClon(DZ_COMP1,  3, MNGVID_DZ2to5MF, lMtz1Tmr*10);//уставка выдержки DZ3MF
  
//MTZ DZ3MF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2StageParam.Dstp2_Ocp_T;

  SetUstToClon(DZ_COMP1,  3, MNGVID_MDZ2to5MF, lMtz1Tmr*10);//уставка выдержки MTZ DZ3MF

//DZ3OF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2StageParam.Dstp2_OF_T;

  SetUstToClon(DZ_COMP1,  3, MNGVID_DZ2to5OF, lMtz1Tmr*10);//уставка выдержки MTZ DZ3OF
  
//ускорение  
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2StageParam.Dstp2_HWS_Tau_Aclt;

  SetUstToClon(DZ_COMP1,  3, MNGVUSK_DZ2to5MF, lMtz1Tmr*10);//уставка ввод ускор ДЗ3 МФ
  
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;

  SetUstToClon(DZ_COMP1,  3, MNGVUSK_MDZ2to5MF, lMtz1Tmr*10);//уставка ввод ускор MTZ ДЗ3 МФ

   //DZ3MF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2StageParam.Dstp2_MF_T_aclt;

  SetUstToClon(DZ_COMP1,  3, MNGUSK_DZ2to5MF_VV, lMtz1Tmr*10);//уставка ускор ДЗ3 МФ BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2StageParam.Dstp2_MF_T_op_aclt;

  SetUstToClon(DZ_COMP1,  3, MNGUSK_DZ2to5MF_OU, lMtz1Tmr*10);//уставка ускор ДЗ3 МФ OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2StageParam.Dstp2_MF_T_tele_aclt;

  SetUstToClon(DZ_COMP1,  3, MNGUSK_DZ2to5MF_TU, lMtz1Tmr*10);//уставка ускор ДЗ3 МФ TU

   //MTZ DZ3MF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2StageParam.Dstp2_Ocp_T_aclt;

  SetUstToClon(DZ_COMP1,  3, MNGUSK_MDZ2to5MF_VV, lMtz1Tmr*10);//уставка ускор MTZ ДЗ3 МФ BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2StageParam.Dstp2_Ocp_T_op_aclt;

  SetUstToClon(DZ_COMP1,  3, MNGUSK_MDZ2to5MF_OU, lMtz1Tmr*10);//уставка ускор MTZ ДЗ3 МФ OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;

  SetUstToClon(DZ_COMP1,  3, MNGUSK_MDZ2to5MF_TU, lMtz1Tmr*10);//уставка ускор MTZ ДЗ3 МФ TU

   //DZ3OF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2StageParam.Dstp2_OF_T_aclt;

  SetUstToClon(DZ_COMP1,  3, MNGUSK_DZ2to5OF_VV, lMtz1Tmr*10);//уставка ускор ДЗ3 OФ BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2StageParam.Dstp2_OF_T_op_aclt;

  SetUstToClon(DZ_COMP1,  3, MNGUSK_DZ2to5OF_OU, lMtz1Tmr*10);//уставка ускор ДЗ3 OФ OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3Dstp2StageParam.Dstp2_OF_T_tele_aclt;

  SetUstToClon(DZ_COMP1,  3, MNGUSK_DZ2to5OF_TU, lMtz1Tmr*10);//уставка ускор ДЗ3 OФ TU

  int uprDZ3=0;
  //меню  Состояние DZ3
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg3Dstp2Mng.state_dstp2;
  if(lSt1>0) uprDZ3 |= 1; //DZ3 WKL
  else  uprDZ3 &= ~1; //DZ3 OTKL 
  //меню   MTZ DZ3
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg3Dstp2Mng.state_ocp_dstp2;
  if(lSt1>0) uprDZ3 |= 2; //MTZ DZ3 WKL
  else  uprDZ3 &= ~2; //MTZ DZ3 OTKL 
  //меню   ускор ВВ DZ3
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg3Dstp2Mng.state_aclt_dstp2_hws;
  if(lSt1>0) uprDZ3 |= 4; //ускор BB DZ3 WKL
  else  uprDZ3 &= ~4; //ускор BB DZ3 OTKL 
  //меню   ускор AU DZ3
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg3Dstp2Mng.state_Auto_aclt_dstp2;
  if(lSt1>0) uprDZ3 |= 8; //ускор AU DZ3 WKL
  else  uprDZ3 &= ~8; //ускор AU DZ3 OTKL 
  //меню   ускор TU DZ3
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg3Dstp2Mng.state_Tele_aclt_dstp2;
  if(lSt1>0) uprDZ3 |= 16; //ускор TU DZ3 WKL
  else  uprDZ3 &= ~16; //ускор TU DZ3 OTKL 
  
  SetUstToClon(DZ_COMP1,  3, MNGUPR_DZ2to5, uprDZ3);//управление DZ3
//  int ttttttt3 = getNativUstMngUSTAVKI(8, 31);//fsetUpr);
    int  global_enaDZ3 = PrepareENACmd(8, 31);//MNGUPR_DZ2to5);

//-----------DZ4------------------------------------  
//Ток МТЗ ДЗ4МФ
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2Pickup.Dstp2_Iovp_ov_range;
    SetUstToClon(DZ_COMP1,  4, MNGUST_DZ2to5_MTZ, lMtz1);//уставка MTZ
//-----------OF
//Re1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P1_R;
//    X1OF_DZ4 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  4, MNGUST_DZ2to5_OX1, lMtz1);//уставка X1OF_DZ4
//Im1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P1_X;
//    Y1OF_DZ4 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  4, MNGUST_DZ2to5_OY1, lMtz1);//уставка Y1OF_DZ4

//Re2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P2_R;
//    X2OF_DZ4 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  4, MNGUST_DZ2to5_OX2, lMtz1);//уставка X2OF_DZ4
//Im2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P2_X;
//    Y2OF_DZ4 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  4, MNGUST_DZ2to5_OY2, lMtz1);//уставка Y2OF_DZ4

//Re3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P3_R;
//    X3OF_DZ4 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  4, MNGUST_DZ2to5_OX3, lMtz1);//уставка X3OF_DZ4
//Im3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P3_X;
//    Y3OF_DZ4 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  4, MNGUST_DZ2to5_OY3, lMtz1);//уставка Y3OF_DZ4

//Re4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P4_R;
//    X4OF_DZ4 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  4, MNGUST_DZ2to5_OX4, lMtz1);//уставка X4OF_DZ4
//Im4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2Pickup.Z_OF_Dstp2_P4_X;
//    Y4OF_DZ4 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  4, MNGUST_DZ2to5_OY4, lMtz1);//уставка Y4OF_DZ4

//-----------MF
//Re1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P1_R;
//    X1MF_DZ4 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  4, MNGUST_DZ2to5_MX1, lMtz1);//уставка X1MF_DZ4
//Im1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P1_X;
//    Y1MF_DZ4 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  4, MNGUST_DZ2to5_MY1, lMtz1);//уставка Y1MF_DZ4

//Re2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P2_R;
//    X2MF_DZ4 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  4, MNGUST_DZ2to5_MX2, lMtz1);//уставка X2MF_DZ4
//Im2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P2_X;
//    Y2MF_DZ4 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  4, MNGUST_DZ2to5_MY2, lMtz1);//уставка Y2MF_DZ4

//Re3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P3_R;
//    X3MF_DZ4 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  4, MNGUST_DZ2to5_MX3, lMtz1);//уставка X3MF_DZ4
//Im3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P3_X;
//    Y3MF_DZ4 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  4, MNGUST_DZ2to5_MY3, lMtz1);//уставка Y3MF_DZ4

//Re4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P4_R;
//    X4MF_DZ4 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  4, MNGUST_DZ2to5_MX4, lMtz1);//уставка X4MF_DZ4
//Im4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2Pickup.Z_MF_Dstp2_P4_X;
//    Y4MF_DZ4 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  4, MNGUST_DZ2to5_MY4, lMtz1);//уставка Y4MF_DZ4
    
//DZ4MF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2StageParam.Dstp2_MF_T;

  SetUstToClon(DZ_COMP1,  4, MNGVID_DZ2to5MF, lMtz1Tmr*10);//уставка выдержки DZ4MF
  
//MTZ DZ4MF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2StageParam.Dstp2_Ocp_T;

  SetUstToClon(DZ_COMP1,  4, MNGVID_MDZ2to5MF, lMtz1Tmr*10);//уставка выдержки MTZ DZ4MF

//DZ4OF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2StageParam.Dstp2_OF_T;

  SetUstToClon(DZ_COMP1,  4, MNGVID_DZ2to5OF, lMtz1Tmr*10);//уставка выдержки MTZ DZ4OF
  
//ускорение  
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2StageParam.Dstp2_HWS_Tau_Aclt;

  SetUstToClon(DZ_COMP1,  4, MNGVUSK_DZ2to5MF, lMtz1Tmr*10);//уставка ввод ускор ДЗ4 МФ
  
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;

  SetUstToClon(DZ_COMP1,  4, MNGVUSK_MDZ2to5MF, lMtz1Tmr*10);//уставка ввод ускор MTZ ДЗ4 МФ

   //DZ4MF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2StageParam.Dstp2_MF_T_aclt;

  SetUstToClon(DZ_COMP1,  4, MNGUSK_DZ2to5MF_VV, lMtz1Tmr*10);//уставка ускор ДЗ4 МФ BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2StageParam.Dstp2_MF_T_op_aclt;

  SetUstToClon(DZ_COMP1,  4, MNGUSK_DZ2to5MF_OU, lMtz1Tmr*10);//уставка ускор ДЗ4 МФ OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2StageParam.Dstp2_MF_T_tele_aclt;

  SetUstToClon(DZ_COMP1,  4, MNGUSK_DZ2to5MF_TU, lMtz1Tmr*10);//уставка ускор ДЗ4 МФ TU

   //MTZ DZ4MF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2StageParam.Dstp2_Ocp_T_aclt;

  SetUstToClon(DZ_COMP1,  4, MNGUSK_MDZ2to5MF_VV, lMtz1Tmr*10);//уставка ускор MTZ ДЗ4 МФ BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2StageParam.Dstp2_Ocp_T_op_aclt;

  SetUstToClon(DZ_COMP1,  4, MNGUSK_MDZ2to5MF_OU, lMtz1Tmr*10);//уставка ускор MTZ ДЗ4 МФ OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;

  SetUstToClon(DZ_COMP1,  4, MNGUSK_MDZ2to5MF_TU, lMtz1Tmr*10);//уставка ускор MTZ ДЗ4 МФ TU

   //DZ4OF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2StageParam.Dstp2_OF_T_aclt;

  SetUstToClon(DZ_COMP1,  4, MNGUSK_DZ2to5OF_VV, lMtz1Tmr*10);//уставка ускор ДЗ4 OФ BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2StageParam.Dstp2_OF_T_op_aclt;

  SetUstToClon(DZ_COMP1,  4, MNGUSK_DZ2to5OF_OU, lMtz1Tmr*10);//уставка ускор ДЗ4 OФ OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4Dstp2StageParam.Dstp2_OF_T_tele_aclt;

  SetUstToClon(DZ_COMP1,  4, MNGUSK_DZ2to5OF_TU, lMtz1Tmr*10);//уставка ускор ДЗ4 OФ TU

  int uprDZ4=0;
  //меню  Состояние DZ4
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg4Dstp2Mng.state_dstp2;
  if(lSt1>0) uprDZ4 |= 1; //DZ4 WKL
  else  uprDZ4 &= ~1; //DZ4 OTKL 
  //меню   MTZ DZ4
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg4Dstp2Mng.state_ocp_dstp2;
  if(lSt1>0) uprDZ4 |= 2; //MTZ DZ4 WKL
  else  uprDZ4 &= ~2; //MTZ DZ4 OTKL 
  //меню   ускор ВВ DZ4
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg4Dstp2Mng.state_aclt_dstp2_hws;
  if(lSt1>0) uprDZ4 |= 4; //ускор BB DZ4 WKL
  else  uprDZ4 &= ~4; //ускор BB DZ4 OTKL 
  //меню   ускор AU DZ4
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg4Dstp2Mng.state_Auto_aclt_dstp2;
  if(lSt1>0) uprDZ4 |= 8; //ускор AU DZ4 WKL
  else  uprDZ4 &= ~8; //ускор AU DZ4 OTKL 
  //меню   ускор TU DZ4
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg4Dstp2Mng.state_Tele_aclt_dstp2;
  if(lSt1>0) uprDZ4 |= 16; //ускор TU DZ4 WKL
  else  uprDZ4 &= ~16; //ускор TU DZ4 OTKL 
  
  SetUstToClon(DZ_COMP1,  4, MNGUPR_DZ2to5, uprDZ4);//управление DZ4
  
//-----------DZ5------------------------------------  
//Ток МТЗ ДЗ5МФ
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2Pickup.Dstp2_Iovp_ov_range;
    SetUstToClon(DZ_COMP1,  5, MNGUST_DZ2to5_MTZ, lMtz1);//уставка MTZ
//-----------OF
//Re1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P1_R;
//    X1OF_DZ5 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  5, MNGUST_DZ2to5_OX1, lMtz1);//уставка X1OF_DZ5
//Im1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P1_X;
//    Y1OF_DZ5 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  5, MNGUST_DZ2to5_OY1, lMtz1);//уставка Y1OF_DZ5

//Re2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P2_R;
//    X2OF_DZ5 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  5, MNGUST_DZ2to5_OX2, lMtz1);//уставка X2OF_DZ5
//Im2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P2_X;
//    Y2OF_DZ5 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  5, MNGUST_DZ2to5_OY2, lMtz1);//уставка Y2OF_DZ5

//Re3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P3_R;
//    X3OF_DZ5 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  5, MNGUST_DZ2to5_OX3, lMtz1);//уставка X3OF_DZ5
//Im3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P3_X;
//    Y3OF_DZ5 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  5, MNGUST_DZ2to5_OY3, lMtz1);//уставка Y3OF_DZ5

//Re4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P4_R;
//    X4OF_DZ5 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  5, MNGUST_DZ2to5_OX4, lMtz1);//уставка X4OF_DZ5
//Im4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2Pickup.Z_OF_Dstp2_P4_X;
//    Y4OF_DZ5 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  5, MNGUST_DZ2to5_OY4, lMtz1);//уставка Y4OF_DZ5

    //-----------MF
//Re1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P1_R;
//    X1MF_DZ5 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  5, MNGUST_DZ2to5_MX1, lMtz1);//уставка X1MF_DZ5
//Im1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P1_X;
//    Y1MF_DZ5 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  5, MNGUST_DZ2to5_MY1, lMtz1);//уставка Y1MF_DZ5

//Re2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P2_R;
//    X2MF_DZ5 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  5, MNGUST_DZ2to5_MX2, lMtz1);//уставка X2MF_DZ5
//Im2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P2_X;
//    Y2MF_DZ5 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  5, MNGUST_DZ2to5_MY2, lMtz1);//уставка Y2MF_DZ5

//Re3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P3_R;
//    X3MF_DZ5 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  5, MNGUST_DZ2to5_MX3, lMtz1);//уставка X3MF_DZ5
//Im3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P3_X;
//    Y3MF_DZ5 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  5, MNGUST_DZ2to5_MY3, lMtz1);//уставка Y3MF_DZ5

//Re4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P4_R;
//    X4MF_DZ5 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  5, MNGUST_DZ2to5_MX4, lMtz1);//уставка X4MF_DZ5
//Im4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2Pickup.Z_MF_Dstp2_P4_X;
//    Y4MF_DZ5 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  5, MNGUST_DZ2to5_MY4, lMtz1);//уставка Y4MF_DZ5

//DZ5MF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2StageParam.Dstp2_MF_T;

  SetUstToClon(DZ_COMP1,  5, MNGVID_DZ2to5MF, lMtz1Tmr*10);//уставка выдержки DZ5MF
  
//MTZ DZ5MF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2StageParam.Dstp2_Ocp_T;

  SetUstToClon(DZ_COMP1,  5, MNGVID_MDZ2to5MF, lMtz1Tmr*10);//уставка выдержки MTZ DZ5MF

//DZ5OF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2StageParam.Dstp2_OF_T;

  SetUstToClon(DZ_COMP1,  5, MNGVID_DZ2to5OF, lMtz1Tmr*10);//уставка выдержки MTZ DZ5OF
  
//ускорение  
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2StageParam.Dstp2_HWS_Tau_Aclt;

  SetUstToClon(DZ_COMP1,  5, MNGVUSK_DZ2to5MF, lMtz1Tmr*10);//уставка ввод ускор ДЗ5 МФ
  
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2StageParam.Dstp2_Ocp_HWS_Tau_Aclt;

  SetUstToClon(DZ_COMP1,  5, MNGVUSK_MDZ2to5MF, lMtz1Tmr*10);//уставка ввод ускор MTZ ДЗ5 МФ

   //DZ5MF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2StageParam.Dstp2_MF_T_aclt;

  SetUstToClon(DZ_COMP1,  5, MNGUSK_DZ2to5MF_VV, lMtz1Tmr*10);//уставка ускор ДЗ5 МФ BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2StageParam.Dstp2_MF_T_op_aclt;

  SetUstToClon(DZ_COMP1,  5, MNGUSK_DZ2to5MF_OU, lMtz1Tmr*10);//уставка ускор ДЗ5 МФ OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2StageParam.Dstp2_MF_T_tele_aclt;

  SetUstToClon(DZ_COMP1,  5, MNGUSK_DZ2to5MF_TU, lMtz1Tmr*10);//уставка ускор ДЗ5 МФ TU

   //MTZ DZ5MF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2StageParam.Dstp2_Ocp_T_aclt;

  SetUstToClon(DZ_COMP1,  5, MNGUSK_MDZ2to5MF_VV, lMtz1Tmr*10);//уставка ускор MTZ ДЗ5 МФ BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2StageParam.Dstp2_Ocp_T_op_aclt;

  SetUstToClon(DZ_COMP1,  5, MNGUSK_MDZ2to5MF_OU, lMtz1Tmr*10);//уставка ускор MTZ ДЗ5 МФ OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2StageParam.Dstp2_Ocp_T_tele_aclt;

  SetUstToClon(DZ_COMP1,  5, MNGUSK_MDZ2to5MF_TU, lMtz1Tmr*10);//уставка ускор MTZ ДЗ5 МФ TU

   //DZ5OF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2StageParam.Dstp2_OF_T_aclt;

  SetUstToClon(DZ_COMP1,  5, MNGUSK_DZ2to5OF_VV, lMtz1Tmr*10);//уставка ускор ДЗ5 OФ BB

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2StageParam.Dstp2_OF_T_op_aclt;

  SetUstToClon(DZ_COMP1,  5, MNGUSK_DZ2to5OF_OU, lMtz1Tmr*10);//уставка ускор ДЗ5 OФ OU

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5Dstp2StageParam.Dstp2_OF_T_tele_aclt;

  SetUstToClon(DZ_COMP1,  5, MNGUSK_DZ2to5OF_TU, lMtz1Tmr*10);//уставка ускор ДЗ5 OФ TU

  int uprDZ5=0;
  //меню  Состояние DZ5
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg5Dstp2Mng.state_dstp2;
  if(lSt1>0) uprDZ5 |= 1; //DZ5 WKL
  else  uprDZ5 &= ~1; //DZ5 OTKL 
  //меню   MTZ DZ5
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg5Dstp2Mng.state_ocp_dstp2;
  if(lSt1>0) uprDZ5 |= 2; //MTZ DZ5 WKL
  else  uprDZ5 &= ~2; //MTZ DZ5 OTKL 
  //меню   ускор ВВ DZ5
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg5Dstp2Mng.state_aclt_dstp2_hws;
  if(lSt1>0) uprDZ5 |= 4; //ускор BB DZ5 WKL
  else  uprDZ5 &= ~4; //ускор BB DZ5 OTKL 
  //меню   ускор AU DZ5
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg5Dstp2Mng.state_Auto_aclt_dstp2;
  if(lSt1>0) uprDZ5 |= 8; //ускор AU DZ5 WKL
  else  uprDZ5 &= ~8; //ускор AU DZ5 OTKL 
  //меню   ускор TU DZ5
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg5Dstp2Mng.state_Tele_aclt_dstp2;
  if(lSt1>0) uprDZ5 |= 16; //ускор TU DZ5 WKL
  else  uprDZ5 &= ~16; //ускор TU DZ5 OTKL 
  
  SetUstToClon(DZ_COMP1,  5, MNGUPR_DZ2to5, uprDZ5);//управление DZ5
//*/  
}//SettingIci_DZ2to5()

