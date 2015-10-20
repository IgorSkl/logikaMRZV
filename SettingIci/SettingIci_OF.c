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
#include "OFComponent.c"
//#include "MTZ1Component.c"
//#include "MTZ2Component.c"
//#include "TZNP1Component.c"
//#include "DZ1Component.c"
//#include "DZ2Component.c"

extern char chProtectTableComeIn;
extern char chResultCallGetMeasPrt;
//extern tic long lDemo_IA,lDemo_IB,lDemo_IC;
extern  long lMtz1,lMtz1Tmr,lSt1,lSt2, lst3, lst4;
extern __MEASUREMENT_TO_PROTECTION TestMeasProtection;
extern MaskaOTAPVUROVOFcmd struct_maskaOTAPVUROVOFcmd;//маски для 16 опред функций UROV APV OT

extern MaskaOTcmd struct_maskaOTcmd;//маски для 8 опред триггеров

//int puskOFotZPLUS();//int num);

  puskOFfunction *pntPuskOF;//указатель на ф-цию


void  SettingIci_OF()
{
  memset(&struct_maskaOTAPVUROVOFcmd, 0, sizeof(MaskaOTAPVUROVOFcmd));//стереть старое
  memset(&struct_maskaOTcmd,          0, sizeof(MaskaOTcmd));//стереть старое
/*
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP1OFcmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP2OFcmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP3OFcmdMaska[i]=0;//Очистить

  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP1OF2cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP2OF2cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP3OF2cmdMaska[i]=0;//Очистить

  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP1OF3cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP2OF3cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP3OF3cmdMaska[i]=0;//Очистить

  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP1OF4cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP2OF4cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP3OF4cmdMaska[i]=0;//Очистить

  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP1OF5cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP2OF5cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP3OF5cmdMaska[i]=0;//Очистить

  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP1OF6cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP2OF6cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP3OF6cmdMaska[i]=0;//Очистить

  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP1OF7cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP2OF7cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP3OF7cmdMaska[i]=0;//Очистить

  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP1OF8cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP2OF8cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP3OF8cmdMaska[i]=0;//Очистить

  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP1OF9cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP2OF9cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP3OF9cmdMaska[i]=0;//Очистить

  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP1OF10cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP2OF10cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP3OF10cmdMaska[i]=0;//Очистить

  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP1OF11cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP2OF11cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP3OF11cmdMaska[i]=0;//Очистить

  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP1OF12cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP2OF12cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP3OF12cmdMaska[i]=0;//Очистить

  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP1OF13cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP2OF13cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP3OF13cmdMaska[i]=0;//Очистить

  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP1OF14cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP2OF14cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP3OF14cmdMaska[i]=0;//Очистить

  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP1OF15cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP2OF15cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP3OF15cmdMaska[i]=0;//Очистить

  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP1OF16cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP2OF16cmdMaska[i]=0;//Очистить
  for(int i=0; i<DQUADRO; i++) struct_maskaOTAPVUROVOFcmd.pP3OF16cmdMaska[i]=0;//Очистить
*/

//OFuncDsc   ownrOFunc;  //Опред. функции
//unsigned char uch_ar_type_df[NUM_DEF_FUN];
//Тип Определяемой функции1
//	1- прямая
//	2 - инверсная


//OF1
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_time_delay_df[0];
  SetUstToClon(OF_COMP1,  1, MNGPAUSA_OF1, lMtz1Tmr);//выдержка
//	длительность импульса определяемой функции1
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_duration_df[0];
  SetUstToClon(OF_COMP1,  1, MNGWORK_OF1, lMtz1Tmr);//выдержка OF1

//OF2
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_time_delay_df[1];
  SetUstToClon(OF_COMP1,  1, MNGPAUSA_OF2, lMtz1Tmr);//выдержка
//	длительность импульса определяемой функции1
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_duration_df[1];
  SetUstToClon(OF_COMP1,  1, MNGWORK_OF2, lMtz1Tmr);//выдержка OF2

//OF3
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_time_delay_df[2];
  SetUstToClon(OF_COMP1,  1, MNGPAUSA_OF3, lMtz1Tmr);//выдержка
//	длительность импульса определяемой функции1
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_duration_df[2];
  SetUstToClon(OF_COMP1,  1, MNGWORK_OF3, lMtz1Tmr);//выдержка OF2

//OF4
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_time_delay_df[3];
  SetUstToClon(OF_COMP1,  1, MNGPAUSA_OF4, lMtz1Tmr);//выдержка
//	длительность импульса определяемой функции1
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_duration_df[3];
  SetUstToClon(OF_COMP1,  1, MNGWORK_OF4, lMtz1Tmr);//выдержка OF2

//OF5
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_time_delay_df[4];
  SetUstToClon(OF_COMP1,  1, MNGPAUSA_OF5, lMtz1Tmr);//выдержка
//	длительность импульса определяемой функции1
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_duration_df[4];
  SetUstToClon(OF_COMP1,  1, MNGWORK_OF5, lMtz1Tmr);//выдержка OF2

//OF6
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_time_delay_df[5];
  SetUstToClon(OF_COMP1,  1, MNGPAUSA_OF6, lMtz1Tmr);//выдержка
//	длительность импульса определяемой функции1
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_duration_df[5];
  SetUstToClon(OF_COMP1,  1, MNGWORK_OF6, lMtz1Tmr);//выдержка OF2

//OF7
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_time_delay_df[6];
  SetUstToClon(OF_COMP1,  1, MNGPAUSA_OF7, lMtz1Tmr);//выдержка
//	длительность импульса определяемой функции1
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_duration_df[6];
  SetUstToClon(OF_COMP1,  1, MNGWORK_OF7, lMtz1Tmr);//выдержка OF2

//OF8
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_time_delay_df[7];
  SetUstToClon(OF_COMP1,  1, MNGPAUSA_OF8, lMtz1Tmr);//выдержка
//	длительность импульса определяемой функции1
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_duration_df[7];
  SetUstToClon(OF_COMP1,  1, MNGWORK_OF8, lMtz1Tmr);//выдержка OF2

//OF9
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_time_delay_df[8];
  SetUstToClon(OF_COMP1,  1, MNGPAUSA_OF9, lMtz1Tmr);//выдержка
//	длительность импульса определяемой функции1
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_duration_df[8];
  SetUstToClon(OF_COMP1,  1, MNGWORK_OF9, lMtz1Tmr);//выдержка OF2

//OF10
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_time_delay_df[9];
  SetUstToClon(OF_COMP1,  1, MNGPAUSA_OF10, lMtz1Tmr);//выдержка
//	длительность импульса определяемой функции1
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_duration_df[9];
  SetUstToClon(OF_COMP1,  1, MNGWORK_OF10, lMtz1Tmr);//выдержка OF2

//OF11
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_time_delay_df[10];
  SetUstToClon(OF_COMP1,  1, MNGPAUSA_OF11, lMtz1Tmr);//выдержка
//	длительность импульса определяемой функции1
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_duration_df[10];
  SetUstToClon(OF_COMP1,  1, MNGWORK_OF11, lMtz1Tmr);//выдержка OF2

//OF12
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_time_delay_df[11];
  SetUstToClon(OF_COMP1,  1, MNGPAUSA_OF12, lMtz1Tmr);//выдержка
//	длительность импульса определяемой функции1
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_duration_df[11];
  SetUstToClon(OF_COMP1,  1, MNGWORK_OF12, lMtz1Tmr);//выдержка OF2

//OF13
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_time_delay_df[12];
  SetUstToClon(OF_COMP1,  1, MNGPAUSA_OF13, lMtz1Tmr);//выдержка
//	длительность импульса определяемой функции1
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_duration_df[12];
  SetUstToClon(OF_COMP1,  1, MNGWORK_OF13, lMtz1Tmr);//выдержка OF2

//OF14
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_time_delay_df[13];
  SetUstToClon(OF_COMP1,  1, MNGPAUSA_OF14, lMtz1Tmr);//выдержка
//	длительность импульса определяемой функции1
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_duration_df[13];
  SetUstToClon(OF_COMP1,  1, MNGWORK_OF14, lMtz1Tmr);//выдержка OF2

//OF15
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_time_delay_df[14];
  SetUstToClon(OF_COMP1,  1, MNGPAUSA_OF15, lMtz1Tmr);//выдержка
//	длительность импульса определяемой функции1
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_duration_df[14];
  SetUstToClon(OF_COMP1,  1, MNGWORK_OF15, lMtz1Tmr);//выдержка OF2

//OF16
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_time_delay_df[15];
  SetUstToClon(OF_COMP1,  1, MNGPAUSA_OF16, lMtz1Tmr);//выдержка
//	длительность импульса определяемой функции1
    lMtz1Tmr = brCfgTbl.ownrOFunc.ul_ar_duration_df[15];
  SetUstToClon(OF_COMP1,  1, MNGWORK_OF16, lMtz1Tmr);//выдержка OF2


    int uprOF=0;
    lSt1 = brCfgTbl.ownrOFunc.uch_ar_type_df[0];
//Тип Определяемой функции1
//	1- прямая
//	2 - инверсная
  if(lSt1>0) uprOF |= 1; //Обр
  else  uprOF &= ~1; //Прямая
    lSt1 = brCfgTbl.ownrOFunc.uch_ar_type_df[1];
  if(lSt1>0) uprOF |= 2; //Обр
  else  uprOF &= ~2; //Прямая
    lSt1 = brCfgTbl.ownrOFunc.uch_ar_type_df[2];
  if(lSt1>0) uprOF |= 4; //Обр
  else  uprOF &= ~4; //Прямая
    lSt1 = brCfgTbl.ownrOFunc.uch_ar_type_df[3];
  if(lSt1>0) uprOF |= 8; //Обр
  else  uprOF &= ~8; //Прямая
    lSt1 = brCfgTbl.ownrOFunc.uch_ar_type_df[4];
  if(lSt1>0) uprOF |= 16; //Обр
  else  uprOF &= ~16; //Прямая
    lSt1 = brCfgTbl.ownrOFunc.uch_ar_type_df[5];
  if(lSt1>0) uprOF |= 32; //Обр
  else  uprOF &= ~32; //Прямая
    lSt1 = brCfgTbl.ownrOFunc.uch_ar_type_df[6];
  if(lSt1>0) uprOF |= 64; //Обр
  else  uprOF &= ~64; //Прямая
    lSt1 = brCfgTbl.ownrOFunc.uch_ar_type_df[7];
  if(lSt1>0) uprOF |= 128; //Обр
  else  uprOF &= ~128; //Прямая
    lSt1 = brCfgTbl.ownrOFunc.uch_ar_type_df[8];
  if(lSt1>0) uprOF |= 256; //Обр
  else  uprOF &= ~256; //Прямая
    lSt1 = brCfgTbl.ownrOFunc.uch_ar_type_df[9];
  if(lSt1>0) uprOF |= 512; //Обр
  else  uprOF &= ~512; //Прямая
    lSt1 = brCfgTbl.ownrOFunc.uch_ar_type_df[10];
  if(lSt1>0) uprOF |= 1024; //Обр
  else  uprOF &= ~1024; //Прямая
    lSt1 = brCfgTbl.ownrOFunc.uch_ar_type_df[11];
  if(lSt1>0) uprOF |= 2048; //Обр
  else  uprOF &= ~2048; //Прямая
    lSt1 = brCfgTbl.ownrOFunc.uch_ar_type_df[12];
  if(lSt1>0) uprOF |= 4096; //Обр
  else  uprOF &= ~4096; //Прямая
    lSt1 = brCfgTbl.ownrOFunc.uch_ar_type_df[13];
  if(lSt1>0) uprOF |= 8192; //Обр
  else  uprOF &= ~8192; //Прямая
    lSt1 = brCfgTbl.ownrOFunc.uch_ar_type_df[14];
  if(lSt1>0) uprOF |= 8192*2; //Обр
  else  uprOF &= ~(8192*2); //Прямая
    lSt1 = brCfgTbl.ownrOFunc.uch_ar_type_df[15];
  if(lSt1>0) uprOF |= 8192*4; //Обр
  else  uprOF &= ~(8192*4); //Прямая

   SetUstToClon(OF_COMP1,  1, MNGUPR_OF, uprOF);//устанвка прямая - обратная ОФ

  int FlagMaska = 0;//PLUS
//команды запуска
  for(int numOF=0; numOF<16; numOF++) puskOFModern(FlagMaska, numOF);
  FlagMaska = 1;//MINUS
//инверсные команды запуска
  for(int numOF=0; numOF<16; numOF++) puskOFModern(FlagMaska, numOF);
  FlagMaska = 2;//BLK
//команды блокировки
  for(int numOF=0; numOF<16; numOF++) puskOFModern(FlagMaska, numOF);

  FlagMaska = 0;//PLUS Set
//команды запуска
  for(int numOT=0; numOT<8; numOT++) puskOTModern(FlagMaska, numOT);
  FlagMaska = 1;//PLUS Rst
//команды запуска
  for(int numOT=0; numOT<8; numOT++) puskOTModern(FlagMaska, numOT);
  FlagMaska = 2;//MINUS Set
//инверсные команды запуска
  for(int numOT=0; numOT<8; numOT++) puskOTModern(FlagMaska, numOT);
  FlagMaska = 3;//MINUS Rst
//инверсные команды запуска
  for(int numOT=0; numOT<8; numOT++) puskOTModern(FlagMaska, numOT);

}

void puskOFModern(int FlagMaska, int numOF)
{
  SettingIci_OFDZ(0, FlagMaska, numOF);
  SettingIci_OFMTZ(0, FlagMaska, numOF);
  SettingIci_OFUMM(0, FlagMaska, numOF);
  SettingIci_OFTZNP(0, FlagMaska, numOF);
}//puskOFModern(int FlagMaska, int numOF)

void puskOTModern(int FlagMaska, int numOT)
{
  SettingIci_OFDZ(1, FlagMaska, numOT);
  SettingIci_OFMTZ(1, FlagMaska, numOT);
  SettingIci_OFUMM(1, FlagMaska, numOT);
  SettingIci_OFTZNP(1, FlagMaska, numOT);
}//puskOFModern(int FlagMaska, int numOF)

int puskOFotZPLUS(int numCmd, int numOF)//AMOUNT_BYTE_FOR_OEPRF
{
//Пуск от Защит +
  int rez=0;
    if(brCfgTbl.uc_ar_df1_pl_rank_cfg[(numOF*AMOUNT_BYTE_FOR_OEPRF)+
                                       numCmd/8]&(1<<(numCmd%8))) rez=1;
  return rez;
}//puskOFotZPLUS(int num)

int puskOFotZMINUS(int numCmd, int numOF)
{
//Пуск от Защит -
  int rez=0;
    if(brCfgTbl.uc_ar_df1_mn_rank_cfg[(numOF*AMOUNT_BYTE_FOR_OEPRF)+
                                       numCmd/8]&(1<<(numCmd%8))) rez=1;
  return rez;
}//puskOFotZMINUS(int num)

int puskOFotZBLK(int numCmd, int numOF)
{
//Пуск от Защит -
  int rez=0;
    if(brCfgTbl.uc_ar_df1_blk_rank_cfg[(numOF*AMOUNT_BYTE_FOR_OEPRF)+
                                       numCmd/8]&(1<<(numCmd%8))) rez=1;
  return rez;
}//puskOFotZBLK(int num)

/*
unsigned char uc_ar_trg_setPl_rank_cfg[NUM_TRG*AMOUNT_BYTE_FOR_OEPRF];//
unsigned char uc_ar_trg_setMn_rank_cfg[NUM_TRG*AMOUNT_BYTE_FOR_OEPRF];//

unsigned char uc_ar_trg_rstPl_rank_cfg[NUM_TRG*AMOUNT_BYTE_FOR_OEPRF];//
unsigned char uc_ar_trg_rstMn_rank_cfg[NUM_TRG*AMOUNT_BYTE_FOR_OEPRF];//
*/

int puskSetOTotZPLUS(int numCmd, int numOT)//AMOUNT_BYTE_FOR_OEPRF
{
//Пуск от Защит +
  int rez=0;
    if(brCfgTbl.uc_ar_trg_setPl_rank_cfg[(numOT*AMOUNT_BYTE_FOR_OEPRF)+
                                       numCmd/8]&(1<<(numCmd%8))) rez=1;
  return rez;
}//puskSetOTotZPLUS(int num)

int puskSetOTotZMINUS(int numCmd, int numOT)
{
//Пуск от Защит -
  int rez=0;
    if(brCfgTbl.uc_ar_trg_setMn_rank_cfg[(numOT*AMOUNT_BYTE_FOR_OEPRF)+
                                       numCmd/8]&(1<<(numCmd%8))) rez=1;
  return rez;
}//puskSetOTotZMINUS(int num)

int puskRstOTotZPLUS(int numCmd, int numOT)//AMOUNT_BYTE_FOR_OEPRF
{
//Пуск от Защит +
  int rez=0;
    if(brCfgTbl.uc_ar_trg_rstPl_rank_cfg[(numOT*AMOUNT_BYTE_FOR_OEPRF)+
                                       numCmd/8]&(1<<(numCmd%8))) rez=1;
  return rez;
}//puskSetOTotZPLUS(int num)

int puskRstOTotZMINUS(int numCmd, int numOT)
{
//Пуск от Защит -
  int rez=0;
    if(brCfgTbl.uc_ar_trg_rstMn_rank_cfg[(numOT*AMOUNT_BYTE_FOR_OEPRF)+
                                       numCmd/8]&(1<<(numCmd%8))) rez=1;
  return rez;
}//puskSetOTotZMINUS(int num)
