/*
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
*/

#include "bazisdef.h"

#include "psuperVisor\supermanager.h"

#include "component\componentdef.h"
#include "psuperVisor\psvisor_helpdef.h"

#include "psuperVisor\psvisor_helpfnc.h"
#include "SettingIci\SettingIci.h"
#include "virtualmenu\systemmenufnc.h"

//#include "toSpeedOptim.h"
//#include "toSpeedDIS.h"

//#include "header.h"
//#include "ici_r_ef.h"

#define _HIDE_COMPONENT
//#include "PRM1Component.c"
#include "DZ1Component.cpp"
/*
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

 float X1OF_DZ1, Y1OF_DZ1, X2OF_DZ1, Y2OF_DZ1;
 float X3OF_DZ1, Y3OF_DZ1, X4OF_DZ1, Y4OF_DZ1;

 float X1MF_DZ1, Y1MF_DZ1, X2MF_DZ1, Y2MF_DZ1;
 float X3MF_DZ1, Y3MF_DZ1, X4MF_DZ1, Y4MF_DZ1;
*/

void  GettingIci_DZ1()
{
 int numBlok=0;
//Ток МТЗ ДЗ1МФ
    int tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGUST_DZ1_MTZ);//уставка MTZ
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1Pickup.Dstp1_Iovp_ov_range;

//-----------OF
//Re1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGUST_DZ1_OX1);//уставка X1OF_DZ1
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P1_R;

//Im1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGUST_DZ1_OY1);//уставка Y1OF_DZ1
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P1_X;

//Re2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGUST_DZ1_OX2);//уставка X2OF_DZ1
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P2_R;
//Im2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGUST_DZ1_OY2);//уставка Y2OF_DZ1
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P2_X;

//Re3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGUST_DZ1_OX3);//уставка X3OF_DZ1
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P3_R;
//Im3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGUST_DZ1_OY3);//уставка Y3OF_DZ1
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P3_X;

//Re4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGUST_DZ1_OX4);//уставка X4OF_DZ1
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P4_R;
//Im4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGUST_DZ1_OY4);//уставка Y4OF_DZ1
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1Pickup.Z_OF_Dstp1_P4_X;

    //-----------MF
//Re1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGUST_DZ1_MX1);//уставка X1MF_DZ1
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P1_R;
//Im1
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGUST_DZ1_MY1);//уставка Y1MF_DZ1
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P1_X;

//Re2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGUST_DZ1_MX2);//уставка X2MF_DZ1
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P2_R;
//Im2
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGUST_DZ1_MY2);//уставка Y2MF_DZ1
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P2_X;

//Re3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGUST_DZ1_MX3);//уставка X3MF_DZ1
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P3_R;
//Im3
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGUST_DZ1_MY3);//уставка Y3MF_DZ1
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P3_X;

//Re4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGUST_DZ1_MX4);//уставка X4MF_DZ1
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P4_R;
//Im4
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGUST_DZ1_MY4);//уставка Y4MF_DZ1
//    lMtz1 = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1Pickup.Z_MF_Dstp1_P4_X;

//DZ1MF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGVID_DZ1MF);//уставка выдержки DZ1MF
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1StageParam.Dstp1_T_MF;

  
//MTZ DZ1MF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGVID_MDZ1MF);//уставка выдержки MTZ DZ1MF
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1StageParam.Dstp1_T_Ocp;


//DZ1OF
    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGVID_DZ1OF);//уставка выдержки DZ1OF
//    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[numBlok].ownrStage1Dstp1StageParam.Dstp1_T_OF;


    tmpUst = GetUstFromImageClon(numBlok, DZ_COMP1,  1, MNGUPR_DZ1);//управление DZ1
/*
//  int uprDZ1=0;
  //меню  Состояние DZ1    
//.	Состояние
//.	1 -вкл
//.	0 - выкл
  int tmp = 0;
  if(tmpUst&1) tmp = 1;
  brCfgTbl.ownrStg1Dstp1Mng.state_dstp1 = tmp;
//    lSt1 = brCfgTbl.ownrStg1Dstp1Mng.state_dstp1;
//  if(lSt1>0) uprDZ1 |= 1; //DZ1 WKL
//  else  uprDZ1 &= ~1; //DZ1 OTKL 
  //меню  Состояние MTZ DZ1    
//.	Состояние
//.	1 -вкл
//.	0 - выкл
  tmp = 0;
  if(tmpUst&1) tmp = 1;
  brCfgTbl.ownrStg1Dstp1Mng.state_ocp_dstp1 = tmp;
//    lSt1 = brCfgTbl.ownrStg1Dstp1Mng.state_ocp_dstp1;
//  if(lSt1>0) uprDZ1 |= 2; //MTZ DZ1 WKL
//  else  uprDZ1 &= ~2; //MTZ DZ1 OTKL 
  
//  SetUstToClon(DZ_COMP1,  1, MNGUPR_DZ1, uprDZ1);//управление DZ1
*/
}//SettingIci_DZ1()

