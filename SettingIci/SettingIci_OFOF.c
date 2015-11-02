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

#define _HIDE_COMPONENT
#include "OFComponent.c"

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

void SettingIci_OFOF(int typFUNC, int FlagMaska, int numOF)
{
//������ OF �� ����
//int numRele = nRele - RELE1_SM;//����������
//  int typRang
puskOFfunction *pntPuskOF;

  int typRang = PUSK1OF_SM;
  if(typFUNC==0){//OF
  typRang = typRang - numOF*3 - FlagMaska;

  switch(FlagMaska){
   case 0://PLUS
    pntPuskOF = &puskOFotZPLUS;
   break;
   case 1://MINUS
    pntPuskOF = &puskOFotZMINUS;
   break;
   case 2://BLK
    pntPuskOF = &puskOFotZBLK;
   break;
  }//switch
  }//if(typFUNC==0)
  if(typFUNC==1){//OT
  typRang = PUSK1OT1_SM;
  typRang = typRang - numOF*4 - FlagMaska;

  switch(FlagMaska){
   case 0://PLUS Set
    pntPuskOF = &puskSetOTotZPLUS;
   break;
   case 1://PLUS Rst
    pntPuskOF = &puskRstOTotZPLUS;
   break;
   case 2://MINUS Set
    pntPuskOF = &puskSetOTotZMINUS;
   break;
   case 3://MINUS Rst
    pntPuskOF = &puskRstOTotZMINUS;
   break;
  }//switch
  }//if(typFUNC==0)

//����� ��_01  
  lSt1 = pntPuskOF(EDF01_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF1, typRang);//������ � OF OT
//����� ��_02
  lSt1 = pntPuskOF(EDF02_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF2, typRang);//������ � OF OT
//����� ��_03  
  lSt1 = pntPuskOF(EDF03_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF3, typRang);//������ � OF OT
//����� ��_04  
  lSt1 = pntPuskOF(EDF04_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF4, typRang);//������ � OF OT
//����� ��_05  
  lSt1 = pntPuskOF(EDF05_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF5, typRang);//������ � OF OT

//����� ��_06
  lSt1 = pntPuskOF(EDF06_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF6, typRang);//������ � OF OT
//����� ��_07  
  lSt1 = pntPuskOF(EDF07_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF7, typRang);//������ � OF OT
//����� ��_08  
  lSt1 = pntPuskOF(EDF08_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF8, typRang);//������ � OF OT
//����� ��_09  
  lSt1 = pntPuskOF(EDF09_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF9, typRang);//������ � OF OT
//����� ��_10  
  lSt1 = pntPuskOF(EDF10_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF10, typRang);//������ � OF OT
//����� ��_11  
  lSt1 = pntPuskOF(EDF11_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF11, typRang);//������ � OF OT
//����� ��_12  
  lSt1 = pntPuskOF(EDF12_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF12, typRang);//������ � OF OT
//����� ��_13  
  lSt1 = pntPuskOF(EDF13_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF13, typRang);//������ � OF OT
//����� ��_14  
  lSt1 = pntPuskOF(EDF14_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF14, typRang);//������ � OF OT
//����� ��_15  
  lSt1 = pntPuskOF(EDF15_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF15, typRang);//������ � OF OT
//����� ��_16  
  lSt1 = pntPuskOF(EDF16_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OF16, typRang);//������ � OF OT
//------------OT-------------------

//����� OT1
  lSt1 = pntPuskOF(OUT_OT1_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT1, typRang);//������ � OF OT
//����� OT2
  lSt1 = pntPuskOF(OUT_OT2_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT2, typRang);//������ � OF OT
//����� OT3
  lSt1 = pntPuskOF(OUT_OT3_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT3, typRang);//������ � OF OT
//����� OT4
  lSt1 = pntPuskOF(OUT_OT4_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT4, typRang);//������ � OF OT
//����� OT5
  lSt1 = pntPuskOF(OUT_OT5_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT5, typRang);//������ � OF OT
//����� OT6
  lSt1 = pntPuskOF(OUT_OT6_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT6, typRang);//������ � OF OT
//����� OT7
  lSt1 = pntPuskOF(OUT_OT7_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT7, typRang);//������ � OF OT
//����� OT8
  lSt1 = pntPuskOF(OUT_OT8_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(OF_COMP1,  1, IOCMD_OUT_OT8, typRang);//������ � OF OT

}//SettingIci_OFOF(int typFUNC, int FlagMaska, int numOF)

/*
EDF01_OEPRF_ONB                      ,//����� ��_01  
EDF02_OEPRF_ONB                      ,//����� ��_02
EDF03_OEPRF_ONB                      ,//����� ��_03
EDF04_OEPRF_ONB                      ,//����� ��_04
EDF05_OEPRF_ONB                      ,//����� ��_05
EDF06_OEPRF_ONB                      ,//����� ��_06
EDF07_OEPRF_ONB                      ,//����� ��_07
EDF08_OEPRF_ONB                      ,//����� ��_08
EDF09_OEPRF_ONB                      ,//����� ��_09
EDF10_OEPRF_ONB                      ,//����� ��_10  
EDF11_OEPRF_ONB                      ,//����� ��_11
EDF12_OEPRF_ONB                      ,//����� ��_12
EDF13_OEPRF_ONB                      ,//����� ��_13
EDF14_OEPRF_ONB                      ,//����� ��_14
EDF15_OEPRF_ONB                      ,//����� ��_15
EDF16_OEPRF_ONB                      ,//����� ��_16


OUT_OT1_OEPRF_ONB                    ,//����� ��1
OUT_OT2_OEPRF_ONB                    ,//����� ��2
OUT_OT3_OEPRF_ONB                    ,//����� ��3
OUT_OT4_OEPRF_ONB                    ,//����� ��4
OUT_OT5_OEPRF_ONB                    ,//����� ��5
OUT_OT6_OEPRF_ONB                    ,//����� ��6
OUT_OT7_OEPRF_ONB                    ,//����� ��7
OUT_OT8_OEPRF_ONB                    ,//����� ��8 
*/

