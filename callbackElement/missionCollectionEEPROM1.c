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

#include "callbackelement\callbackelementdef.h"
#include "callbackelement\ustrangEEPROMdef.h"

#include "callbackelement\callbackelementfnc.h"
#include "callbackelement\missionCollectionEEPROM.h"

extern   HSTIMER_REGS_T *hst_regptr;  // Pointer to HSTIMER registers
extern   SSP_REGS_T     *ssp1_regptr; // Pointer to SSP1 registers
extern   GPIO_REGS_T    *gpio_regptr; // Pointer to GPIO registers
extern CALLBACK_MISSION cb_missionDEVICE1;
extern CALLBACK_MISSION *cb_mission_crrDEVICE1;//текущая миссия
extern short  missionSeparatorDEVICE1;//сепаратор миссии

void Build_cbMission_1BREAD_MASSIV(char *massiv, int srcB64, int dstB64)
{
//сформировать миссию чтения массива из EEPROM 
int adrSrc = srcB64*64;//адрес чтения
int adrDst = dstB64*64;//адрес в EEPROM
  if(cb_mission_crrDEVICE1->callBackMaxer<0)
  {
    missionSeparatorDEVICE1 = CBACK_MISSION_1BREAD_MASSIV;//номер миссии  EEPROM на 1 блок
    //1 задача
    OrderCallBack(cb_mission_crrDEVICE1, &callBackEEPROM_READ);//заказать новые задачи
    TASKMISSION_DEFINE1 tmDefine1 =
    {
      (void *)adrSrc,   //source
      &(massiv[adrDst]),//dest
      64//к-во
    };
    SetTaskParam1CallBack(cb_mission_crrDEVICE1, &tmDefine1);//параметры
  }//if(cb_mission_crrDEVICE1->callBackMaxer<0)
}//Build_cbMission_8BREAD_MASSIV()

void Build_cbMission_1BWRITE_MASSIV(char *massiv, int srcB64, int dstB64)
{
//сформировать миссию записи массива в EEPROM 
int adrSrc = srcB64*64;//адрес источника
int adrDst = dstB64*64;//адрес в EEPROM
  if(cb_mission_crrDEVICE1->callBackMaxer<0)
  {
    missionSeparatorDEVICE1 = CBACK_MISSION_1BWRITE_MASSIV;//номер миссии записи в EEPROM
    //1 задача
    OrderCallBack(cb_mission_crrDEVICE1, &callBackEEPROM_WRITE);//заказать новые задачи
    TASKMISSION_DEFINE1 tmDefine1 =
    {
      &(massiv[adrSrc]), //source
      (void *)adrDst,//dest
      64//к-во
    };
    SetTaskParam1CallBack(cb_mission_crrDEVICE1, &tmDefine1);//параметры

  }//if(cb_mission_crrDEVICE1->callBackMaxer<0)
}//Build_cbMission_1BWRITE_MASSIV(char *massiv, int srcB64, int dstB64)

void Build_cbMission_WRITE_USTALTER(char *massiv)//, int srcB64, int dstB64)
{
//сформировать миссию записи байта alter для уставок и ранжир
  if(cb_mission_crrDEVICE1->callBackMaxer<0)
  {
    missionSeparatorDEVICE1 = CBACK_MISSION_WRITE_ALTER;//номер миссии записи в EEPROM на 1 байт
    //1 задача
    OrderCallBack(cb_mission_crrDEVICE1, &callBackEEPROM_WRITE);//заказать новые задачи
    TASKMISSION_DEFINE1 tmDefine1 =
    {
      &(massiv[1]), //source
      (void *)0x1, //adrDst,//dest
      1//к-во
    };
    SetTaskParam1CallBack(cb_mission_crrDEVICE1, &tmDefine1);//параметры

  }//if(cb_mission_crrDEVICE1->callBackMaxer<0)
}//Build_cbMission_WRITE_USTALTER(char *massiv)

void FullStepWorkEEPROM(UNS_8 *data, short cntBytesArgument)
//cntBytesArgument - к-во байт в аргументе
{
//полный шаг работы EEPROM
  gpio_regptr->p3_outp_clr = P3_STATE_GPIO(4);//cs EEPROM enable
  HalfStepWorkEEPROM_Middle(data, cntBytesArgument);//шаг работы EEPROM
  gpio_regptr->p3_outp_set = P3_STATE_GPIO(4);//cs EEPROM disable
}//FullStepWorkEEPROM(UNS_8 *data, short cntBytesArgument)

void HalfStepWorkEEPROM_Middle(UNS_8 *data, short cntBytesArgument)
//cntBytesArgument - к-во байт в аргументе
{
//шаг работы EEPROM
  short n_fifo;
  short idx;
  short bytes;
//transmit data
  n_fifo = cntBytesArgument;
  idx=0;
//заполняем FIFO
  while ((n_fifo > 0) &&
         ((ssp1_regptr->sr & SSP_SR_TNF) != 0))
  {
    ssp1_regptr->data = (UNS_32) data[idx];
    n_fifo--;
    idx++;
  }//while
//ждем пока трансляция не закончится
  while (((ssp1_regptr->sr & SSP_SR_BSY) != 0)) {}

//ждем принятые байты и записываем их в data
//read data
  bytes = 0;
  idx=0;
  while (bytes < cntBytesArgument)
  {
    while (((ssp1_regptr->sr & SSP_SR_RNE) != 0))
    {
      data[idx] = (UNS_8) ssp1_regptr->data;//tmp1;
      idx++;
    }//while
    bytes++;
  }//while
}//void HalfStepWorkEEPROM_Middle(UNS_8 *data, short cntBytesArgument)

void HalfStepWorkEEPROM_Begin(UNS_8 *data, short cntBytesArgument)
//cntBytesArgument - к-во байт в аргументе
{
//полу шаг работы EEPROM - начало
  gpio_regptr->p3_outp_clr = P3_STATE_GPIO(4);//cs EEPROM enable
  HalfStepWorkEEPROM_Middle(data, cntBytesArgument);//шаг работы EEPROM
}//HalfStepWorkEEPROM_Begin(UNS_8 *data, short cntBytesArgument)

void HalfStepWorkEEPROM_Ending()
{
//полу шаг работы EEPROM - закончить
  gpio_regptr->p3_outp_set = P3_STATE_GPIO(4);//cs EEPROM disable
}//HalfStepWorkEEPROM_Ending()

char callBackEEPROM_READ(CALLBACKELEMENT_TASK *cbt)
{
//TASK READ ARRAY
  union
  {
    void *p;
    short s;
  } pnt;
  UNS_8 data[5];
  short cntBytesArgument = 0;//к-во байт аргумента команды
  short addrEEPROM;//адрес EEPROM
  short idx = 1;

  pnt.p  = cbt->tmDefine.source;//адрес EEPROM
  addrEEPROM = pnt.s;//адрес EEPROM
  data [0] = 3;//op_cod
  data [1] = (addrEEPROM >> 8) & 0xFF;
  data [2] = (addrEEPROM >> 0) & 0xFF;
  data [3] = 0xFF;
  cntBytesArgument = 4;//к-во байт аргумента команды
  HalfStepWorkEEPROM_Begin(data, cntBytesArgument);//начало работы EEPROM

  cbt->tmDefine.count--;
  if(cbt->tmDefine.count>=0)
    ((UNS_8*)cbt->tmDefine.dest)[0] = data[3];

  while(cbt->tmDefine.count>0)
  {
    cntBytesArgument = 4;//к-во байт аргумента команды
    HalfStepWorkEEPROM_Middle(data, cntBytesArgument);//средина работы EEPROM

    cbt->tmDefine.count -= 4;
    if(cbt->tmDefine.count>=0)
    {
      ((UNS_8*)cbt->tmDefine.dest)[idx++] = data[0];
      ((UNS_8*)cbt->tmDefine.dest)[idx++] = data[1];
      ((UNS_8*)cbt->tmDefine.dest)[idx++] = data[2];
      ((UNS_8*)cbt->tmDefine.dest)[idx++] = data[3];
    }//if
    else
    {
      short max=cbt->tmDefine.count+4;
      for(short i=0; i<max; i++)
        ((UNS_8*)cbt->tmDefine.dest)[idx++] = data[i];
      HalfStepWorkEEPROM_Ending();//закончить работу EEPROM
      return 0;//покинуть CallBackElement
    }//else
  }//while(cbt->tmDefine.count>0)

  HalfStepWorkEEPROM_Ending();//закончить работу EEPROM

  return 0;//покинуть CallBackElement
}//callBackEEPROM_READ(CALLBACKELEMENT_TASK *cbt)

char callBackEEPROM_WRITE(CALLBACKELEMENT_TASK *cbt)
{
//TASK WRITE ARRAY
  union
  {
    void *p;
    short s;
  } pnt;
  UNS_8 data[5];
  short cntBytesArgument = 0;//к-во байт аргумента команды
  short addrEEPROM;//адрес EEPROM
  UNS_8 data8EEPROM;//данные EEPROM
  short idx = 1;

  switch(cbt->callBackStepCntr)
  {
  case TASK_STEP0:
  {
//Set Write Enable Latch
    data[0] = 6;//op_cod
    cntBytesArgument = 1;//к-во байт аргумента команды
    FullStepWorkEEPROM(data, cntBytesArgument);//полный шаг работы EEPROM

//READ STATUS REGISTER
    data[0] = 5;//op_cod
    data[1] = 0xFF;
    cntBytesArgument = 2;//к-во байт аргумента команды
    FullStepWorkEEPROM(data, cntBytesArgument);//полный шаг работы EEPROM
    
    if(data[1]!=2){
      //отказ EEPROM
      cbt->callBackStepCntr--;
      return 1;//остаться в CallBackElement
    }//if

//WRITE ARRAY
    cbt->tmDefine.count--;

    UNS_8 *source  = (UNS_8 *)cbt->tmDefine.source;//адрес массива

    pnt.p  = cbt->tmDefine.dest;//адрес EEPROM
    addrEEPROM = pnt.s;//адрес EEPROM
    if(cbt->tmDefine.count>=0)
    {
      data8EEPROM = source[0];//данные EEPROM
      data [0] = 2;//op_cod
      data [1] = (addrEEPROM >> 8) & 0xFF;
      data [2] = (addrEEPROM >> 0) & 0xFF;
      data [3] = data8EEPROM;
      cntBytesArgument = 4;//к-во байт аргумента команды
      HalfStepWorkEEPROM_Begin(data, cntBytesArgument);//начало работы EEPROM
    }//if

    while(cbt->tmDefine.count>0)
    {
      cbt->tmDefine.count -= 4;
      if(cbt->tmDefine.count>=0)
      {
        data[0] = source[idx++];
        data[1] = source[idx++];
        data[2] = source[idx++];
        data[3] = source[idx++];
        cntBytesArgument = 4;//к-во байт аргумента команды
        HalfStepWorkEEPROM_Middle(data, cntBytesArgument);//средина работы EEPROM
      }//if
      else
      {
        short max=cbt->tmDefine.count+4;
        for(short i=0; i<max; i++)
        {
          data[i] = source[idx++];//0x66;
        }//for
        cntBytesArgument = max;//к-во байт аргумента команды
        HalfStepWorkEEPROM_Middle(data, cntBytesArgument);//средина работы EEPROM
      }//else
    }//while(cbt->tmDefine.count>0)
    HalfStepWorkEEPROM_Ending();//закончить работу EEPROM
  }
  break;

  default:
  {
//READ STATUS REGISTER
    data[0] = 5;//op_cod
    data[1] = 0xFF;
    cntBytesArgument = 2;//к-во байт аргумента команды
    FullStepWorkEEPROM(data, cntBytesArgument);//полный шаг работы EEPROM
    if((data[1]&1)==0)
      return 0;//покинуть CallBackElement
  };
  }//switch

  return 1;//остаться в CallBackElement
}//
