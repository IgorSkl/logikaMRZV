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
#include "TZNP1Component.c"

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;

void  SettingIci_OFTZNP(int typFUNC, int FlagMaska, int numOF)
{
//������ ��� �� ����
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

//���� ���� ����1
  lSt1 = pntPuskOF(BLOCK_TZNP1_DI_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  1, IOCMD1_TZNP1to5, typRang);//������ � OF OT
//���� ��� ����1
// if(isActivCmdDV(, numRele))//�������� ���������� ������� �� ��
//      SetCmdToUVV(TZNP_COMP1,  1, IOCMD2_TZNP1to5, nRele);//������
//���� ��� ����1
  lSt1 = pntPuskOF(ACCLT_TZNP1_DI_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  1, IOCMD3_TZNP1to5, typRang);//������ � OF OT
//���� �� ����1
  lSt1 = pntPuskOF(STPDEV_TZNP1_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  1, IOCMD4_TZNP1to5, typRang);//������ � OF OT
//���� ����1
  lSt1 = pntPuskOF(TZNP1_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  1, IOCMD5_TZNP1to5, typRang);//������ � OF OT
//���� �� ����1 3I0
  lSt1 = pntPuskOF(STPDEV_TZNP1_3I0_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  1, IOCMD6_TZNP1to5, typRang);//������ � OF OT
//���� ����1 3I0
  lSt1 = pntPuskOF(TZNP1_3I0_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  1, IOCMD7_TZNP1to5, typRang);//������ � OF OT
//���� �� ����1 3U0
  lSt1 = pntPuskOF(STPDEV_TZNP1_3U0_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  1, IOCMD8_TZNP1to5, typRang);//������ � OF OT
//���� ����1 3U0
  lSt1 = pntPuskOF(TZNP1__3U0_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  1, IOCMD9_TZNP1to5, typRang);//������ � OF OT

//���� ���� ����2
  lSt1 = pntPuskOF(BLOCK_TZNP2_DI_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  2, IOCMD1_TZNP1to5, typRang);//������ � OF OT
//���� ��� ����2
// if(isActivCmdDV(, numRele))//�������� ���������� ������� �� ��
//      SetCmdToUVV(TZNP_COMP1,  2, IOCMD2_TZNP1to5, nRele);//������
//���� ��� ����2
  lSt1 = pntPuskOF(ACCLT_TZNP2_DI_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  2, IOCMD3_TZNP1to5, typRang);//������ � OF OT
//���� �� ����2
  lSt1 = pntPuskOF(STPDEV_TZNP2_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  2, IOCMD4_TZNP1to5, typRang);//������ � OF OT
//���� ����2
  lSt1 = pntPuskOF(TZNP2_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  2, IOCMD5_TZNP1to5, typRang);//������ � OF OT
//���� �� ����2 3I0
  lSt1 = pntPuskOF(STPDEV_TZNP2_3I0_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  2, IOCMD6_TZNP1to5, typRang);//������ � OF OT
//���� ����2 3I0
  lSt1 = pntPuskOF(TZNP2_3I0_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  2, IOCMD7_TZNP1to5, typRang);//������ � OF OT
//���� �� ����2 3U0
  lSt1 = pntPuskOF(STPDEV_TZNP2_3U0_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  2, IOCMD8_TZNP1to5, typRang);//������ � OF OT
//���� ����2 3U0
  lSt1 = pntPuskOF(TZNP2_3U0_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  2, IOCMD9_TZNP1to5, typRang);//������ � OF OT

//���� ���� ����3
  lSt1 = pntPuskOF(BLOCK_TZNP3_DI_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  3, IOCMD1_TZNP1to5, typRang);//������ � OF OT
//���� ��� ����3
// if(isActivCmdDV(, numRele))//�������� ���������� ������� �� ��
//      SetCmdToUVV(TZNP_COMP1,  3, IOCMD2_TZNP1to5, nRele);//������
//���� ��� ����3
  lSt1 = pntPuskOF(ACCLT_TZNP3_DI_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  3, IOCMD3_TZNP1to5, typRang);//������ � OF OT
//���� �� ����3
  lSt1 = pntPuskOF(STPDEV_TZNP3_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  3, IOCMD4_TZNP1to5, typRang);//������ � OF OT
//���� ����3
  lSt1 = pntPuskOF(TZNP3_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  3, IOCMD5_TZNP1to5, typRang);//������ � OF OT
//���� �� ����3 3I0
  lSt1 = pntPuskOF(STPDEV_TZNP3_3I0_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  3, IOCMD6_TZNP1to5, typRang);//������ � OF OT
//���� ����3 3I0
  lSt1 = pntPuskOF(TZNP3_3I0_OEPRF_ONB, numOF);
   if(lSt1) SetCmdToUVV(TZNP_COMP1,  3, IOCMD7_TZNP1to5, typRang);//������ � OF OT
//���� �� ����3 3U0
  lSt1 = pntPuskOF(STPDEV_TZNP3_3U0_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  3, IOCMD8_TZNP1to5, typRang);//������ � OF OT
//���� ����3 3U0
  lSt1 = pntPuskOF(TZNP3_3U0_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  3, IOCMD9_TZNP1to5, typRang);//������ � OF OT

//���� ���� ����4
  lSt1 = pntPuskOF(BLOCK_TZNP4_DI_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  4, IOCMD1_TZNP1to5, typRang);//������ � OF OT
//���� ��� ����4
// if(isActivCmdDV(, numRele))//�������� ���������� ������� �� ��
//      SetCmdToUVV(TZNP_COMP1,  4, IOCMD2_TZNP1to5, nRele);//������
//���� ��� ����4
  lSt1 = pntPuskOF(ACCLT_TZNP4_DI_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  4, IOCMD3_TZNP1to5, typRang);//������ � OF OT
//���� �� ����4
  lSt1 = pntPuskOF(STPDEV_TZNP4_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  4, IOCMD4_TZNP1to5, typRang);//������ � OF OT
//���� ����4
  lSt1 = pntPuskOF(TZNP4_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  4, IOCMD5_TZNP1to5, typRang);//������ � OF OT
//���� �� ����4 3I0
  lSt1 = pntPuskOF(STPDEV_TZNP4_3I0_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  4, IOCMD6_TZNP1to5, typRang);//������ � OF OT
//���� ����4 3I0
  lSt1 = pntPuskOF(TZNP4_3I0_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  4, IOCMD7_TZNP1to5, typRang);//������ � OF OT
//���� �� ����4 3U0
  lSt1 = pntPuskOF(STPDEV_TZNP4_3U0_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  4, IOCMD8_TZNP1to5, typRang);//������ � OF OT
//���� ����4 3U0
  lSt1 = pntPuskOF(TZNP4_3U0_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  4, IOCMD9_TZNP1to5, typRang);//������ � OF OT

//���� ���� ����5
  lSt1 = pntPuskOF(BLOCK_TZNP5_DI_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  5, IOCMD1_TZNP1to5, typRang);//������ � OF OT
//���� ��� ����5
// if(isActivCmdDV(, numRele))//�������� ���������� ������� �� ��
//      SetCmdToUVV(TZNP_COMP1,  5, IOCMD2_TZNP1to5, nRele);//������
//���� ��� ����5
  lSt1 = pntPuskOF(ACCLT_TZNP5_DI_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  5, IOCMD3_TZNP1to5, typRang);//������ � OF OT
//���� �� ����5
  lSt1 = pntPuskOF(STPDEV_TZNP5_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  5, IOCMD4_TZNP1to5, typRang);//������ � OF OT
//���� ����5
  lSt1 = pntPuskOF(TZNP5_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  5, IOCMD5_TZNP1to5, typRang);//������ � OF OT
//���� �� ����5 3I0
  lSt1 = pntPuskOF(STPDEV_TZNP5_3I0_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  5, IOCMD6_TZNP1to5, typRang);//������ � OF OT
//���� ����5 3I0
  lSt1 = pntPuskOF(TZNP5_3I0_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  5, IOCMD7_TZNP1to5, typRang);//������ � OF OT
//���� �� ����5 3U0
  lSt1 = pntPuskOF(STPDEV_TZNP5_3U0_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  5, IOCMD8_TZNP1to5, typRang);//������ � OF OT
//���� ����5 3U0
  lSt1 = pntPuskOF(TZNP5_3U0_OEPRF_ONB, numOF);
  if(lSt1)  SetCmdToUVV(TZNP_COMP1,  5, IOCMD9_TZNP1to5, typRang);//������ � OF OT
}// SettingIci_RangirTZNP2Rele(int nRele)

