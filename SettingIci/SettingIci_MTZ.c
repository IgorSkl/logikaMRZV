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
#include "MTZ1Component.c"
#include "MTZ2Component.c"

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

void  SettingIci_MTZ()
{
//установки ICI МТЗ 
//-------------MTZ1-----------------------    
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrOcp1Pickup.mcp1_I_ov_range;
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrOcp1StageParam.mcp1_time_stage;
    
  SetUstToClon(MTZ_COMP1,  1, MNGUST_MTZ1, lMtz1);//уставка МТЗ1 отсечка
  SetUstToClon(MTZ_COMP1,  1, MNGVID_MTZ1, lMtz1Tmr*10);//выдержка МТЗ1 отсечка

//.ПО МТЗПН1
//.	 уставка по току
//.	 1 ед = 1 мA
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrOcp1Pickup.mcp1_IstpU_ov_range;
  SetUstToClon(MTZ_COMP1,  1, MNGUST_MTZ1_PN, lMtz1);//уставка МТЗ1 ПН 
//.ПО U МТЗПН1
//.	 уставка по пуска по напряжению
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrOcp1Pickup.mcp1_Ustp_ov_range;
  SetUstToClon(MTZ_COMP1,  1, MNGUST_MTZ1_UPN, lMtz1);//уставка МТЗ1 ПН 
//.T МТЗПН1
//.	выдержка 1- ступени МТЗ
//.	1 ед =10мсе
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrOcp1StageParam.mcp1_Ustp_time_stage;
  SetUstToClon(MTZ_COMP1,  1, MNGVID_MTZ1_PN, lMtz1Tmr*10);//выдержка МТЗ1 ПН

//.ПО МТЗ1 направл
//.	 уставка по току
//.	 1 ед = 1 мA
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrOcp1Pickup.mcp1_s1_Ias_ov_range;
  SetUstToClon(MTZ_COMP1,  1, MNGUST_MTZ1_V, lMtz1);//уставка МТЗН1 вперед

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrOcp1Pickup.mcp1_s2_Iabk_ov_range;
  SetUstToClon(MTZ_COMP1,  1, MNGUST_MTZ1_N, lMtz1);//уставка МТЗН1 назад
//.	выдержка МТЗ1 вперед
//.	1 ед =10мсе
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrOcp1StageParam.mcp1_s1_time_stage;
  SetUstToClon(MTZ_COMP1,  1, MNGVID_MTZ1_V, lMtz1Tmr*10);//выдержка МТЗ1 вперед
//.	выдержка МТЗ1 назад
//.	1 ед =10мсе
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage1DrOcp1StageParam.mcp1_s2_time_stage;
  SetUstToClon(MTZ_COMP1,  1, MNGVID_MTZ1_N, lMtz1Tmr*10);//выдержка МТЗ1 вперед

  int uprMTZ1=0;
  //меню  Состояние МТЗ1    
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg1DrOcp1Mng.state_mcp1;
  if(lSt1>0) uprMTZ1 |= 4; //МТЗ1 отсечка WKL
  else  uprMTZ1 &= ~4; //МТЗ1 отсечка OTKL 
    //Селектор МТЗ1
//.	Состояние
//.	0 - Простая
//.	1 - Пуск по направленности
//.	2 - Пуск по напряжению
    lSt2 = brCfgTbl.ownrStg1DrOcp1Mng.select_prt_mcp1;  
  if(lSt2==2) uprMTZ1 |= 2; //МТЗ1 ПН WKL
  else  uprMTZ1 &= ~2; //МТЗ1 ПН OTKL 
  if(lSt2==1) uprMTZ1 |= 1; //МТЗ1 направл WKL
  else  uprMTZ1 &= ~1; //МТЗ1 направл OTKL 
    
    //меню  МТЗ1 Напрвление Вперед Состояние 
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lst3 = brCfgTbl.ownrStg1DrOcp1Mng.DirectionStraight_mcp1;
  if(lst3>0) uprMTZ1 |= 8; //МТЗ1 вперед WKL
  else  uprMTZ1 &= ~8; //МТЗ1 вперед OTKL 

    //меню  МТЗ1 Напрвление Назад Состояние 
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lst4 = brCfgTbl.ownrStg1DrOcp1Mng.DirectionBack_mcp1;
  if(lst4>0) uprMTZ1 |= 16; //МТЗ1 назад WKL
  else  uprMTZ1 &= ~16; //МТЗ1 назад OTKL 


  SetUstToClon(MTZ_COMP1,  1, MNGUPR_MTZ1, uprMTZ1);//управление МТЗ1
//    lst2 = brCfgTbl.ownrStg1DrOcp1Mng.select_prt_mcp1;  
  
//-------------MTZ2-----------------------    
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2Pickup.mcp_I_ov_range;
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_time_stage;
  SetUstToClon(MTZ_COMP1,  2, MNGUST_MTZ2to5, lMtz1);//уставка МТЗ2 отсечка
  SetUstToClon(MTZ_COMP1,  2, MNGVID_MTZ2to5, lMtz1Tmr*10);//выдержка МТЗ2 отсечка
  
//.ПО МТЗПН
//.	 уставка по току
//.	 1 ед = 1 мA
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2Pickup.mcp_IstpU_ov_range;
  SetUstToClon(MTZ_COMP1,  2, MNGUST_MTZ2to5_PN, lMtz1);//уставка МТЗ2 ПН
//.ПО U МТЗПН
//.	 уставка по пуска по напряжению
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2Pickup.mcp_Ustp_ov_range;
  SetUstToClon(MTZ_COMP1,  2, MNGUST_MTZ2to5_UPN, lMtz1);//уставка МТЗ2 ПН

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_Ustp_time_stage;
  SetUstToClon(MTZ_COMP1,  2, MNGVID_MTZ2to5_PN, lMtz1Tmr*10);//выдержка МТЗ2 ПН

//.ПО МТЗ2 направл
//.	 уставка по току
//.	 1 ед = 1 мA
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2Pickup.mcp_s1_Ias_ov_range;
  SetUstToClon(MTZ_COMP1,  2, MNGUST_MTZ2to5_V, lMtz1);//уставка МТЗН2 вперед

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2Pickup.mcp_s2_Iabk_ov_range;
  SetUstToClon(MTZ_COMP1,  2, MNGUST_MTZ2to5_N, lMtz1);//уставка МТЗН2 назад
  
//.	выдержка МТЗ2 вперед
//.	1 ед =10мсе
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_s1_time_stage;
  SetUstToClon(MTZ_COMP1,  2, MNGVID_MTZ2to5_V, lMtz1Tmr*10);//выдержка МТЗ2 вперед
//.	выдержка МТЗ2 назад
//.	1 ед =10мсе
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_s2_time_stage;
  SetUstToClon(MTZ_COMP1,  2, MNGVID_MTZ2to5_N, lMtz1Tmr*10);//выдержка МТЗ2 назад
  
//Ускорение
  //- выдержка ускорения МТЗ2 BB
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_time_stage_Aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5, lMtz1Tmr*10);//ускорение МТЗ2 BB
  //- выдержка ускорения МТЗ2 ОУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_OU, lMtz1Tmr*10);//ускорение МТЗ2 ОУ
  //- выдержка ускорения МТЗ2 TУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_TU, lMtz1Tmr*10);//ускорение МТЗ2 TУ
  
//- выдержка ускорения ступени МТЗН2 вперед  
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_s1_T_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_V, lMtz1Tmr*10);//ускорение МТЗН2 вперед
  //- выдержка ускорения МТЗH2 вперед ОУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_s1_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_V_OU, lMtz1Tmr*10);//ускорение МТЗH2 вперед ОУ
  //- выдержка ускорения МТЗH2 вперед TУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_s1_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_V_TU, lMtz1Tmr*10);//ускорение МТЗH2 вперед TУ
  
//- выдержка ускорения ступени МТЗН2 назад
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_s2_T_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_N, lMtz1Tmr*10);//ускорение МТЗН2 назад
  //- выдержка ускорения МТЗH2 назад ОУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_s2_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_N_OU, lMtz1Tmr*10);//ускорение МТЗH2 назад ОУ
  //- выдержка ускорения МТЗH2 назад TУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_s2_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_N_TU, lMtz1Tmr*10);//ускорение МТЗH2 назад TУ
  
//- выдержка ускорения ступени МТЗ2ПН
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_Ustp_T_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_PN, lMtz1Tmr*10);//ускорение МТЗ2ПН
  //- выдержка ускорения МТЗ2ПН ОУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_Ustp_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_PN_OU, lMtz1Tmr*10);//ускорение МТЗ2ПН  ОУ
  //- выдержка ускорения МТЗ2ПН TУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_Ustp_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  2, MNGUSK_MTZ2to5_PN_TU, lMtz1Tmr*10);//ускорение МТЗ2ПН  TУ
  
//- выдержка ввод ускорения МТЗ2
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage2DrOcp2StageParam.mcp_Tau_AcltImp;
  SetUstToClon(MTZ_COMP1,  2, MNGVUSK_MTZ2to5, lMtz1Tmr*10);//ввод ускорения МТЗ2
  
    int uprMTZ2=0;
  //меню  Состояние МТЗ2    
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg2DrOcp2Mng.state_mcp;
  if(lSt1>0) uprMTZ2 |= 4; //МТЗ1  WKL
  else  uprMTZ2 &= ~4; //МТЗ1  OTKL 
    //Селектор МТЗ2
//.	Состояние
//.	0 - Простая
//.	1 - Пуск по направленности
//.	2 - Пуск по напряжению
    lSt2 = brCfgTbl.ownrStg2DrOcp2Mng.select_prt_mcp;  
  if(lSt2==2) uprMTZ2 |= 2; //МТЗ2 ПН WKL
  else  uprMTZ2 &= ~2; //МТЗ2 ПН OTKL 
  if(lSt2==1) uprMTZ2 |= 1; //МТЗ2 направл WKL
  else  uprMTZ2 &= ~1; //МТЗ2 направл OTKL 
    
    //меню  МТЗ2 Напрвление Вперед Состояние 
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lst3 = brCfgTbl.ownrStg2DrOcp2Mng.DirectionStraight_mcp;
  if(lst3>0) uprMTZ2 |= 8; //МТЗ2 вперед WKL
  else  uprMTZ2 &= ~8; //МТЗ2 вперед OTKL 

    //меню  МТЗ2 Напрвление Назад Состояние 
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lst4 = brCfgTbl.ownrStg2DrOcp2Mng.DirectionBack_mcp;
  if(lst4>0) uprMTZ2 |= 16; //МТЗ2 назад WKL
  else  uprMTZ2 &= ~16; //МТЗ2 назад OTKL 

//ускорение МТЗ2 BB
    lSt1 = brCfgTbl.ownrStg2DrOcp2Mng.aclt_mcp_sw;  
  if(lSt1>0) uprMTZ2 |= 32; //уск МТЗ2 BB WKL
  else  uprMTZ2 &= ~32; //уск МТЗ2 BB OTKL 

//ускорение МТЗ2 AU
    lSt1 = brCfgTbl.ownrStg2DrOcp2Mng.state_Auto_aclt_mcp;  
  if(lSt1>0) uprMTZ2 |= 64; //уск МТЗ2 AU WKL
  else  uprMTZ2 &= ~64; //уск МТЗ2 AU OTKL 

//ускорение МТЗ2 TU
    lSt1 = brCfgTbl.ownrStg2DrOcp2Mng.state_Tele_aclt_mcp;  
  if(lSt1>0) uprMTZ2 |= 128; //уск МТЗ2 TU WKL
  else  uprMTZ2 &= ~128; //уск МТЗ2 TU OTKL 
  
  SetUstToClon(MTZ_COMP1,  2, MNGUPR_MTZ2to5, uprMTZ2);//управление МТЗ2 
  
//-------------MTZ3-----------------------    
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2Pickup.mcp_I_ov_range;
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_time_stage;
  SetUstToClon(MTZ_COMP1,  3, MNGUST_MTZ2to5, lMtz1);//уставка МТЗ3 отсечка
  SetUstToClon(MTZ_COMP1,  3, MNGVID_MTZ2to5, lMtz1Tmr*10);//выдержка МТЗ3 отсечка
  
//.ПО МТЗПН
//.	 уставка по току
//.	 1 ед = 1 мA
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2Pickup.mcp_IstpU_ov_range;
  SetUstToClon(MTZ_COMP1,  3, MNGUST_MTZ2to5_PN, lMtz1);//уставка МТЗ3 ПН
//.ПО U МТЗПН
//.	 уставка по пуска по напряжению
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2Pickup.mcp_Ustp_ov_range;
  SetUstToClon(MTZ_COMP1,  3, MNGUST_MTZ2to5_UPN, lMtz1);//уставка МТЗ3 ПН

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_Ustp_time_stage;
  SetUstToClon(MTZ_COMP1,  3, MNGVID_MTZ2to5_PN, lMtz1Tmr*10);//выдержка МТЗ3 ПН

//.ПО МТЗ3 направл
//.	 уставка по току
//.	 1 ед = 1 мA
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2Pickup.mcp_s1_Ias_ov_range;
  SetUstToClon(MTZ_COMP1,  3, MNGUST_MTZ2to5_V, lMtz1);//уставка МТЗН3 вперед

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2Pickup.mcp_s2_Iabk_ov_range;
  SetUstToClon(MTZ_COMP1,  3, MNGUST_MTZ2to5_N, lMtz1);//уставка МТЗН3 назад
  
//.	выдержка МТЗ3 вперед
//.	1 ед =10мсе
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_s1_time_stage;
  SetUstToClon(MTZ_COMP1,  3, MNGVID_MTZ2to5_V, lMtz1Tmr*10);//выдержка МТЗ3 вперед
//.	выдержка МТЗ3 назад
//.	1 ед =10мсе
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_s2_time_stage;
  SetUstToClon(MTZ_COMP1,  3, MNGVID_MTZ2to5_N, lMtz1Tmr*10);//выдержка МТЗ3 назад
  
//Ускорение
  //- выдержка ускорения МТЗ3 BB
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_time_stage_Aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5, lMtz1Tmr*10);//ускорение МТЗ3 BB
  //- выдержка ускорения МТЗ3 ОУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_OU, lMtz1Tmr*10);//ускорение МТЗ3 ОУ
  //- выдержка ускорения МТЗ3 TУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_TU, lMtz1Tmr*10);//ускорение МТЗ3 TУ
  
//- выдержка ускорения ступени МТЗН3 вперед  
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_s1_T_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_V, lMtz1Tmr*10);//ускорение МТЗН3 вперед
  //- выдержка ускорения МТЗH3 вперед ОУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_s1_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_V_OU, lMtz1Tmr*10);//ускорение МТЗH3 вперед ОУ
  //- выдержка ускорения МТЗH3 вперед TУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_s1_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_V_TU, lMtz1Tmr*10);//ускорение МТЗH3 вперед TУ
  
//- выдержка ускорения ступени МТЗН3 назад
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_s2_T_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_N, lMtz1Tmr*10);//ускорение МТЗН3 назад
  //- выдержка ускорения МТЗH3 назад ОУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_s2_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_N_OU, lMtz1Tmr*10);//ускорение МТЗH3 назад ОУ
  //- выдержка ускорения МТЗH3 назад TУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_s2_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_N_TU, lMtz1Tmr*10);//ускорение МТЗH3 назад TУ
  
//- выдержка ускорения ступени МТЗ3ПН
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_Ustp_T_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_PN, lMtz1Tmr*10);//ускорение МТЗ3ПН
  //- выдержка ускорения МТЗ3ПН ОУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_Ustp_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_PN_OU, lMtz1Tmr*10);//ускорение МТЗ3ПН  ОУ
  //- выдержка ускорения МТЗ3ПН TУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_Ustp_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  3, MNGUSK_MTZ2to5_PN_TU, lMtz1Tmr*10);//ускорение МТЗ3ПН  TУ
  
//- выдержка ввод ускорения МТЗ3
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage3DrOcp2StageParam.mcp_Tau_AcltImp;
  SetUstToClon(MTZ_COMP1,  3, MNGVUSK_MTZ2to5, lMtz1Tmr*10);//ввод ускорения МТЗ3
  
    int uprMTZ3=0;
  //меню  Состояние МТЗ3
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg3DrOcp2Mng.state_mcp;
  if(lSt1>0) uprMTZ3 |= 4; //МТЗ3  WKL
  else  uprMTZ3 &= ~4; //МТЗ3  OTKL 
    //Селектор МТЗ3
//.	Состояние
//.	0 - Простая
//.	1 - Пуск по направленности
//.	2 - Пуск по напряжению
    lSt2 = brCfgTbl.ownrStg3DrOcp2Mng.select_prt_mcp;  
  if(lSt2==2) uprMTZ3 |= 2; //МТЗ3 ПН WKL
  else  uprMTZ3 &= ~2; //МТЗ3 ПН OTKL 
  if(lSt2==1) uprMTZ3 |= 1; //МТЗ3 направл WKL
  else  uprMTZ3 &= ~1; //МТЗ3 направл OTKL 
    
    //меню  МТЗ3 Напрвление Вперед Состояние 
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lst3 = brCfgTbl.ownrStg3DrOcp2Mng.DirectionStraight_mcp;
  if(lst3>0) uprMTZ3 |= 8; //МТЗ3 вперед WKL
  else  uprMTZ3 &= ~8; //МТЗ3 вперед OTKL 

    //меню  МТЗ3 Напрвление Назад Состояние 
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lst4 = brCfgTbl.ownrStg3DrOcp2Mng.DirectionBack_mcp;
  if(lst4>0) uprMTZ3 |= 16; //МТЗ3 назад WKL
  else  uprMTZ3 &= ~16; //МТЗ3 назад OTKL 

//ускорение МТЗ3 BB
    lSt1 = brCfgTbl.ownrStg3DrOcp2Mng.aclt_mcp_sw;  
  if(lSt1>0) uprMTZ3 |= 32; //уск МТЗ3 BB WKL
  else  uprMTZ3 &= ~32; //уск МТЗ3 BB OTKL 

//ускорение МТЗ3 AU
    lSt1 = brCfgTbl.ownrStg3DrOcp2Mng.state_Auto_aclt_mcp;  
  if(lSt1>0) uprMTZ3 |= 64; //уск МТЗ3 AU WKL
  else  uprMTZ3 &= ~64; //уск МТЗ3 AU OTKL 

//ускорение МТЗ3 TU
    lSt1 = brCfgTbl.ownrStg3DrOcp2Mng.state_Tele_aclt_mcp;  
  if(lSt1>0) uprMTZ3 |= 128; //уск МТЗ3 TU WKL
  else  uprMTZ3 &= ~128; //уск МТЗ3 TU OTKL 
  
  SetUstToClon(MTZ_COMP1,  3, MNGUPR_MTZ2to5, uprMTZ3);//управление МТЗ3

//-------------MTZ4-----------------------    
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2Pickup.mcp_I_ov_range;
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_time_stage;
  SetUstToClon(MTZ_COMP1,  4, MNGUST_MTZ2to5, lMtz1);//уставка МТЗ4 отсечка
  SetUstToClon(MTZ_COMP1,  4, MNGVID_MTZ2to5, lMtz1Tmr*10);//выдержка МТЗ4 отсечка
  
//.ПО МТЗПН
//.	 уставка по току
//.	 1 ед = 1 мA
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2Pickup.mcp_IstpU_ov_range;
  SetUstToClon(MTZ_COMP1,  4, MNGUST_MTZ2to5_PN, lMtz1);//уставка МТЗ4 ПН
//.ПО U МТЗПН
//.	 уставка по пуска по напряжению
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2Pickup.mcp_Ustp_ov_range;
  SetUstToClon(MTZ_COMP1,  4, MNGUST_MTZ2to5_UPN, lMtz1);//уставка МТЗ4 ПН

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_Ustp_time_stage;
  SetUstToClon(MTZ_COMP1,  4, MNGVID_MTZ2to5_PN, lMtz1Tmr*10);//выдержка МТЗ4 ПН

//.ПО МТЗ3 направл
//.	 уставка по току
//.	 1 ед = 1 мA
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2Pickup.mcp_s1_Ias_ov_range;
  SetUstToClon(MTZ_COMP1,  4, MNGUST_MTZ2to5_V, lMtz1);//уставка МТЗН4 вперед

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2Pickup.mcp_s2_Iabk_ov_range;
  SetUstToClon(MTZ_COMP1,  4, MNGUST_MTZ2to5_N, lMtz1);//уставка МТЗН4 назад
  
//.	выдержка МТЗ4 вперед
//.	1 ед =10мсе
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_s1_time_stage;
  SetUstToClon(MTZ_COMP1,  4, MNGVID_MTZ2to5_V, lMtz1Tmr*10);//выдержка МТЗ4 вперед
//.	выдержка МТЗ4 назад
//.	1 ед =10мсе
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_s2_time_stage;
  SetUstToClon(MTZ_COMP1,  4, MNGVID_MTZ2to5_N, lMtz1Tmr*10);//выдержка МТЗ4 назад
  
//Ускорение
  //- выдержка ускорения МТЗ4 BB
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_time_stage_Aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5, lMtz1Tmr*10);//ускорение МТЗ4 BB
  //- выдержка ускорения МТЗ4 ОУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_OU, lMtz1Tmr*10);//ускорение МТЗ4 ОУ
  //- выдержка ускорения МТЗ4 TУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_TU, lMtz1Tmr*10);//ускорение МТЗ4 TУ
  
//- выдержка ускорения ступени МТЗН4 вперед  
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_s1_T_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_V, lMtz1Tmr*10);//ускорение МТЗН4 вперед
  //- выдержка ускорения МТЗH4 вперед ОУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_s1_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_V_OU, lMtz1Tmr*10);//ускорение МТЗH4 вперед ОУ
  //- выдержка ускорения МТЗH4 вперед TУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_s1_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_V_TU, lMtz1Tmr*10);//ускорение МТЗH4 вперед TУ
  
//- выдержка ускорения ступени МТЗН4 назад
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_s2_T_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_N, lMtz1Tmr*10);//ускорение МТЗН4 назад
  //- выдержка ускорения МТЗH4 назад ОУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_s2_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_N_OU, lMtz1Tmr*10);//ускорение МТЗH4 назад ОУ
  //- выдержка ускорения МТЗH4 назад TУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_s2_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_N_TU, lMtz1Tmr*10);//ускорение МТЗH4 назад TУ
  
//- выдержка ускорения ступени МТЗ4ПН
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_Ustp_T_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_PN, lMtz1Tmr*10);//ускорение МТЗ4ПН
  //- выдержка ускорения МТЗ4ПН ОУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_Ustp_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_PN_OU, lMtz1Tmr*10);//ускорение МТЗ4ПН  ОУ
  //- выдержка ускорения МТЗ4ПН TУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_Ustp_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  4, MNGUSK_MTZ2to5_PN_TU, lMtz1Tmr*10);//ускорение МТЗ4ПН  TУ
  
//- выдержка ввод ускорения МТЗ4
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage4DrOcp2StageParam.mcp_Tau_AcltImp;
  SetUstToClon(MTZ_COMP1,  4, MNGVUSK_MTZ2to5, lMtz1Tmr*10);//ввод ускорения МТЗ4
  
    int uprMTZ4=0;
  //меню  Состояние МТЗ4
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg4DrOcp2Mng.state_mcp;
  if(lSt1>0) uprMTZ4 |= 4; //МТЗ4  WKL
  else  uprMTZ4 &= ~4; //МТЗ4  OTKL 
    //Селектор МТЗ4
//.	Состояние
//.	0 - Простая
//.	1 - Пуск по направленности
//.	2 - Пуск по напряжению
    lSt2 = brCfgTbl.ownrStg4DrOcp2Mng.select_prt_mcp;  
  if(lSt2==2) uprMTZ4 |= 2; //МТЗ4 ПН WKL
  else  uprMTZ4 &= ~2; //МТЗ4 ПН OTKL 
  if(lSt2==1) uprMTZ4 |= 1; //МТЗ4 направл WKL
  else  uprMTZ4 &= ~1; //МТЗ4 направл OTKL 
    
    //меню  МТЗ4 Напрвление Вперед Состояние 
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lst3 = brCfgTbl.ownrStg4DrOcp2Mng.DirectionStraight_mcp;
  if(lst3>0) uprMTZ4 |= 8; //МТЗ4 вперед WKL
  else  uprMTZ4 &= ~8; //МТЗ4 вперед OTKL 

    //меню  МТЗ4 Напрвление Назад Состояние 
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lst4 = brCfgTbl.ownrStg4DrOcp2Mng.DirectionBack_mcp;
  if(lst4>0) uprMTZ4 |= 16; //МТЗ3 назад WKL
  else  uprMTZ4 &= ~16; //МТЗ3 назад OTKL 

//ускорение МТЗ4 BB
    lSt1 = brCfgTbl.ownrStg4DrOcp2Mng.aclt_mcp_sw;  
  if(lSt1>0) uprMTZ4 |= 32; //уск МТЗ4 BB WKL
  else  uprMTZ4 &= ~32; //уск МТЗ4 BB OTKL 

//ускорение МТЗ4 AU
    lSt1 = brCfgTbl.ownrStg4DrOcp2Mng.state_Auto_aclt_mcp;  
  if(lSt1>0) uprMTZ4 |= 64; //уск МТЗ4 AU WKL
  else  uprMTZ4 &= ~64; //уск МТЗ4 AU OTKL 

//ускорение МТЗ4 TU
    lSt1 = brCfgTbl.ownrStg4DrOcp2Mng.state_Tele_aclt_mcp;  
  if(lSt1>0) uprMTZ4 |= 128; //уск МТЗ4 TU WKL
  else  uprMTZ4 &= ~128; //уск МТЗ4 TU OTKL 
  
  SetUstToClon(MTZ_COMP1,  4, MNGUPR_MTZ2to5, uprMTZ4);//управление МТЗ4

//-------------MTZ5-----------------------    
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2Pickup.mcp_I_ov_range;
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_time_stage;
  SetUstToClon(MTZ_COMP1,  5, MNGUST_MTZ2to5, lMtz1);//уставка МТЗ5 отсечка
  SetUstToClon(MTZ_COMP1,  5, MNGVID_MTZ2to5, lMtz1Tmr*10);//выдержка МТЗ5 отсечка
  
//.ПО МТЗПН
//.	 уставка по току
//.	 1 ед = 1 мA
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2Pickup.mcp_IstpU_ov_range;
  SetUstToClon(MTZ_COMP1,  5, MNGUST_MTZ2to5_PN, lMtz1);//уставка МТЗ5 ПН
//.ПО U МТЗПН
//.	 уставка по пуска по напряжению
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2Pickup.mcp_Ustp_ov_range;
  SetUstToClon(MTZ_COMP1,  5, MNGUST_MTZ2to5_UPN, lMtz1);//уставка МТЗ5 ПН

    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_Ustp_time_stage;
  SetUstToClon(MTZ_COMP1,  5, MNGVID_MTZ2to5_PN, lMtz1Tmr*10);//выдержка МТЗ5 ПН

//.ПО МТЗ5 направл
//.	 уставка по току
//.	 1 ед = 1 мA
    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2Pickup.mcp_s1_Ias_ov_range;
  SetUstToClon(MTZ_COMP1,  5, MNGUST_MTZ2to5_V, lMtz1);//уставка МТЗН5 вперед

    lMtz1 = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2Pickup.mcp_s2_Iabk_ov_range;
  SetUstToClon(MTZ_COMP1,  5, MNGUST_MTZ2to5_N, lMtz1);//уставка МТЗН5 назад
  
//.	выдержка МТЗ5 вперед
//.	1 ед =10мсе
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_s1_time_stage;
  SetUstToClon(MTZ_COMP1,  5, MNGVID_MTZ2to5_V, lMtz1Tmr*10);//выдержка МТЗ5 вперед
//.	выдержка МТЗ5 назад
//.	1 ед =10мсе
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_s2_time_stage;
  SetUstToClon(MTZ_COMP1,  5, MNGVID_MTZ2to5_N, lMtz1Tmr*10);//выдержка МТЗ5 назад
  
//Ускорение
  //- выдержка ускорения МТЗ5 BB
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_time_stage_Aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5, lMtz1Tmr*10);//ускорение МТЗ5 BB
  //- выдержка ускорения МТЗ4 ОУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_OU, lMtz1Tmr*10);//ускорение МТЗ5 ОУ
  //- выдержка ускорения МТЗ5 TУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_TU, lMtz1Tmr*10);//ускорение МТЗ5 TУ
  
//- выдержка ускорения ступени МТЗН5 вперед  
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_s1_T_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_V, lMtz1Tmr*10);//ускорение МТЗН5 вперед
  //- выдержка ускорения МТЗH5 вперед ОУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_s1_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_V_OU, lMtz1Tmr*10);//ускорение МТЗH5 вперед ОУ
  //- выдержка ускорения МТЗH5 вперед TУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_s1_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_V_TU, lMtz1Tmr*10);//ускорение МТЗH5 вперед TУ
  
//- выдержка ускорения ступени МТЗН5 назад
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_s2_T_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_N, lMtz1Tmr*10);//ускорение МТЗН5 назад
  //- выдержка ускорения МТЗH5 назад ОУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_s2_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_N_OU, lMtz1Tmr*10);//ускорение МТЗH5 назад ОУ
  //- выдержка ускорения МТЗH5 назад TУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_s2_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_N_TU, lMtz1Tmr*10);//ускорение МТЗH5 назад TУ
  
//- выдержка ускорения ступени МТЗ5ПН
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_Ustp_T_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_PN, lMtz1Tmr*10);//ускорение МТЗ5ПН
  //- выдержка ускорения МТЗ5ПН ОУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_Ustp_T_op_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_PN_OU, lMtz1Tmr*10);//ускорение МТЗ5ПН  ОУ
  //- выдержка ускорения МТЗ5ПН TУ
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_Ustp_T_tele_aclt;
  SetUstToClon(MTZ_COMP1,  5, MNGUSK_MTZ2to5_PN_TU, lMtz1Tmr*10);//ускорение МТЗ5ПН  TУ
  
//- выдержка ввод ускорения МТЗ5
    lMtz1Tmr = brCfgTbl.arPckpStpmStngStore[0].ownrStage5DrOcp2StageParam.mcp_Tau_AcltImp;
  SetUstToClon(MTZ_COMP1,  5, MNGVUSK_MTZ2to5, lMtz1Tmr*10);//ввод ускорения МТЗ5
  
    int uprMTZ5=0;
  //меню  Состояние МТЗ5
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lSt1 = brCfgTbl.ownrStg5DrOcp2Mng.state_mcp;
  if(lSt1>0) uprMTZ5 |= 4; //МТЗ5  WKL
  else  uprMTZ5 &= ~4; //МТЗ5  OTKL 
    //Селектор МТЗ5
//.	Состояние
//.	0 - Простая
//.	1 - Пуск по направленности
//.	2 - Пуск по напряжению
    lSt2 = brCfgTbl.ownrStg5DrOcp2Mng.select_prt_mcp;  
  if(lSt2==2) uprMTZ5 |= 2; //МТЗ5 ПН WKL
  else  uprMTZ5 &= ~2; //МТЗ5 ПН OTKL 
  if(lSt2==1) uprMTZ5 |= 1; //МТЗ5 направл WKL
  else  uprMTZ5 &= ~1; //МТЗ5 направл OTKL 
    
    //меню  МТЗ5 Напрвление Вперед Состояние 
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lst3 = brCfgTbl.ownrStg5DrOcp2Mng.DirectionStraight_mcp;
  if(lst3>0) uprMTZ5 |= 8; //МТЗ5 вперед WKL
  else  uprMTZ5 &= ~8; //МТЗ5 вперед OTKL 

    //меню  МТЗ5 Напрвление Назад Состояние 
//.	Состояние
//.	1 -вкл
//.	0 - выкл
    lst4 = brCfgTbl.ownrStg5DrOcp2Mng.DirectionBack_mcp;
  if(lst4>0) uprMTZ5 |= 16; //МТЗ5 назад WKL
  else  uprMTZ5 &= ~16; //МТЗ5 назад OTKL 

//ускорение МТЗ5 BB
    lSt1 = brCfgTbl.ownrStg5DrOcp2Mng.aclt_mcp_sw;  
  if(lSt1>0) uprMTZ5 |= 32; //уск МТЗ5 BB WKL
  else  uprMTZ5 &= ~32; //уск МТЗ5 BB OTKL 

//ускорение МТЗ5 AU
    lSt1 = brCfgTbl.ownrStg5DrOcp2Mng.state_Auto_aclt_mcp;  
  if(lSt1>0) uprMTZ5 |= 64; //уск МТЗ5 AU WKL
  else  uprMTZ5 &= ~64; //уск МТЗ5 AU OTKL 

//ускорение МТЗ5 TU
    lSt1 = brCfgTbl.ownrStg5DrOcp2Mng.state_Tele_aclt_mcp;  
  if(lSt1>0) uprMTZ5 |= 128; //уск МТЗ5 TU WKL
  else  uprMTZ5 &= ~128; //уск МТЗ5 TU OTKL 
  
  SetUstToClon(MTZ_COMP1,  5, MNGUPR_MTZ2to5, uprMTZ5);//управление МТЗ5
/*  
  int uprPRM1 = 0;
    lSt1 = brCfgTbl.state_FaultU_Ocp;//Неиспр цепей напр
  if(lSt1>0) uprPRM1 |= 1; // WKL
  else  uprPRM1 &= ~1; // OTKL 
  
  SetUstToClon(PRM1_COMP1,  1, MNGUPR_PRM1, uprPRM1);//управление PRM1
*/
}//SettingIci_MTZ()
