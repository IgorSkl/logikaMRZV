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
//#include "PRM1Component.c"
#include "DZ1Component.c"

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

//координаты вершин зоны сработки
extern float X1;
extern float Y1;

extern float X2;
extern float Y2;

extern float X3;
extern float Y3;

extern float X4;
extern float Y4;

/*
 float X1OF_DZ1, Y1OF_DZ1, X2OF_DZ1, Y2OF_DZ1;
 float X3OF_DZ1, Y3OF_DZ1, X4OF_DZ1, Y4OF_DZ1;

 float X1MF_DZ1, Y1MF_DZ1, X2MF_DZ1, Y2MF_DZ1;
 float X3MF_DZ1, Y3MF_DZ1, X4MF_DZ1, Y4MF_DZ1;
*/

void  SettingIci_DZ1()
{
//float diskr = 0.001;
//Ток МТЗ ДЗ1МФ
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1Pickup.Dstp1_Iovp_ov_range;
    SetUstToClon(DZ_COMP1,  1, MNGUST_DZ1_MTZ, lMtz1);//уставка MTZ

//-----------OF
//Re1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P1_R;
//    X1OF_DZ1 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  1, MNGUST_DZ1_OX1, lMtz1);//уставка X1OF_DZ1

//Im1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P1_X;
//    Y1OF_DZ1 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  1, MNGUST_DZ1_OY1, lMtz1);//уставка Y1OF_DZ1

//Re2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P2_R;
//    X2OF_DZ1 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  1, MNGUST_DZ1_OX2, lMtz1);//уставка X2OF_DZ1
//Im2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P2_X;
//    Y2OF_DZ1 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  1, MNGUST_DZ1_OY2, lMtz1);//уставка Y2OF_DZ1

//Re3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P3_R;
//    X3OF_DZ1 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  1, MNGUST_DZ1_OX3, lMtz1);//уставка X3OF_DZ1
//Im3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P3_X;
//    Y3OF_DZ1 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  1, MNGUST_DZ1_OY3, lMtz1);//уставка Y3OF_DZ1

//Re4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P4_R;
//    X4OF_DZ1 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  1, MNGUST_DZ1_OX4, lMtz1);//уставка X4OF_DZ1
//Im4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P4_X;
//    Y4OF_DZ1 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  1, MNGUST_DZ1_OY4, lMtz1);//уставка Y4OF_DZ1

    //-----------MF
//Re1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P1_R;
//    X1MF_DZ1 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  1, MNGUST_DZ1_MX1, lMtz1);//уставка X1MF_DZ1
//Im1
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P1_X;
//    Y1MF_DZ1 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  1, MNGUST_DZ1_MY1, lMtz1);//уставка Y1MF_DZ1

//Re2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P2_R;
//    X2MF_DZ1 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  1, MNGUST_DZ1_MX2, lMtz1);//уставка X2MF_DZ1
//Im2
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P2_X;
//    Y2MF_DZ1 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  1, MNGUST_DZ1_MY2, lMtz1);//уставка Y2MF_DZ1

//Re3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P3_R;
//    X3MF_DZ1 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  1, MNGUST_DZ1_MX3, lMtz1);//уставка X3MF_DZ1
//Im3
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P3_X;
//    Y3MF_DZ1 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  1, MNGUST_DZ1_MY3, lMtz1);//уставка Y3MF_DZ1

//Re4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P4_R;
//    X4MF_DZ1 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  1, MNGUST_DZ1_MX4, lMtz1);//уставка X4MF_DZ1
//Im4
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P4_X;
//    Y4MF_DZ1 = ((float)lMtz1)*diskr;
    SetUstToClon(DZ_COMP1,  1, MNGUST_DZ1_MY4, lMtz1);//уставка Y4MF_DZ1

//DZ1MF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1StageParam.Dstp1_T_MF;

  SetUstToClon(DZ_COMP1,  1, MNGVID_DZ1MF, lMtz1Tmr*10);//уставка выдержки DZ1MF
  
//MTZ DZ1MF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1StageParam.Dstp1_T_Ocp;

  SetUstToClon(DZ_COMP1,  1, MNGVID_MDZ1MF, lMtz1Tmr*10);//уставка выдержки MTZ DZ1MF

//DZ1OF
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1Dstp1StageParam.Dstp1_T_OF;

  SetUstToClon(DZ_COMP1,  1, MNGVID_DZ1OF, lMtz1Tmr*10);//уставка выдержки DZ1OF

  int uprDZ1=0;
  //меню  Состояние DZ1    
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg1Dstp1Mng.state_dstp1;
  if(lSt1>0) uprDZ1 |= 1; //DZ1 WKL
  else  uprDZ1 &= ~1; //DZ1 OTKL 
  //меню  Состояние MTZ DZ1    
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg1Dstp1Mng.state_ocp_dstp1;
  if(lSt1>0) uprDZ1 |= 2; //MTZ DZ1 WKL
  else  uprDZ1 &= ~2; //MTZ DZ1 OTKL 
  
  SetUstToClon(DZ_COMP1,  1, MNGUPR_DZ1, uprDZ1);//управление DZ1

}//SettingIci_DZ1()

