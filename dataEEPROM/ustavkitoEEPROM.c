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
*/

#include "lpc_types.h"

#include <stdio.h>
#include <string.h>

#include "psuperVisor\supermanager.h"

#include "callbackelement\callbackelementdef.h"
#include "callbackelement\ustrangEEPROMdef.h"
#include "dataEEPROM\dataEEPROMdef.h"

#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "callbackelement\callbackelementfnc.h"
#include "callbackelement\missionCollectionEEPROM.h"
#include "psuperVisor\psvisor_helpfnc.h"
#include "dataEEPROM\dataEEPROM.h"

extern CALLBACK_MISSION cb_missionDEVICE1;
extern CALLBACK_MISSION *cb_mission_crrDEVICE1;//текущая миссия
extern short  missionSeparatorDEVICE1;//сепаратор миссии
extern int timing;
extern int timingLoad;
extern int cicling;
extern int  blokUSTAVKI[];
extern UNS_32 ArrayRANGIR[];
extern char  tmp_eeprom[];//MAX_MNGUSTAVKI*4блока *4байта

extern int missionCicling;//циклы одинаковых миссий
extern int eepromCicling;//циклы работы с EEPROM
extern int alterEEPROM;//байты alter ext устaвок и ранжир EEPROM
extern int eeprom_status;//статусный регистр EEPROM

int controlUst;
int breakMass[3] = {100, 200, 300};
int savePARAMtoEEPROM(int alter)
{
//сохранить уставки в EEPROM
  int                      alter_offset_ust = OFF1_B64UST;
  if(alter&USTALTER_MASKA)
    alter_offset_ust = OFF2_B64UST;
  if(missionSeparatorDEVICE1!=CBACK_NOMISSION) return 1;
  //установить статус UST_ATTEMPT
  eeprom_status |= (1<<EEPROMUST_ATTEMPT);//статусный регистр EEPROM
  //циклы работы с уставками
  eepromCicling = SAVE_UST_BUSY;//процесс записи уст занят;
  missionCicling = 0;//циклы одинаковых миссий
  //сформировать миссию записи уставок в EEPROM 1 блок
  Build_cbMission_1BWRITE_MASSIV((char *)blokUSTAVKI, 0, alter_offset_ust);
  return 0;
}//savePARAMtoEEPROM()

int stepElementSaveUSTAVKItoEEPROM(int alter)
{
//исполнение миссий для записи уставок
  int                      alter_offset_ust = OFF1_B64UST;
  if(alter&USTALTER_MASKA)
    alter_offset_ust = OFF2_B64UST;
  int                      alter_offset_rang = OFF1_B64RANG;
  if(alter&USTALTER_MASKA)
    alter_offset_rang = OFF2_B64RANG;
  //сост процесса записи уставок
  int condition = SAVE_UST_BUSY;//процесс записи уст занят
  switch(missionSeparatorDEVICE1)
  {
  case CBACK_MISSION_1BWRITE_MASSIV:
  {
    char *sourceData = (char *)blokUSTAVKI;
    missionSeparatorDEVICE1 = CBACK_NOMISSION;//больше миссий не будет
    if(missionCicling<(MAX_B64UST-1)) //циклы одинаковых миссий
    {
      //сформировать миссию записи уставок в EEPROM 1 блок
      Build_cbMission_1BWRITE_MASSIV(sourceData,
                                     BLOKMISSION_1 +BLOKMISSION_1*missionCicling,
                                     BLOKMISSION_1 +BLOKMISSION_1*missionCicling +alter_offset_ust);
      missionCicling++;//циклы одинаковых миссий
    }///if
    else
    {
      missionCicling = 0;//циклы одинаковых миссий
      //сформировать миссию чтения уставок EEPROM 1 блок
      Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom, alter_offset_ust, 0);
    }
  }
  break;

  case CBACK_MISSION_1BREAD_MASSIV:
  {
    missionSeparatorDEVICE1 = CBACK_NOMISSION;//больше миссий не будет
    if(missionCicling<(MAX_B64UST-1)) //циклы одинаковых миссий
    {
      //сформировать миссию чтения уставок EEPROM 1 блок
      Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling +alter_offset_ust,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling);
      missionCicling++;//циклы одинаковых миссий
    }//if
    else
    {
      missionCicling = 0;//циклы одинаковых миссий
      condition = SAVE_UST_COMPLETE;//процесс записи уст завершен
      //сформировать миссию записи ранж EEPROM 1 блок
      Build_cbMission_1BWRITE_MASSIV((char *)ArrayRANGIR, 0, alter_offset_rang);
    }
  }
  break;

  default:;//NO MORE MISSION
  }//switch

  return  condition;//процесс записи уст
}//stepElementSaveUSTAVKItoEEPROM()

int stepElementReadUSTAVKItoEEPROM(int alter)
{
//исполнение миссий для чтения уставок
  int                      alter_offset_ust = OFF1_B64UST;
  if(alter&USTALTER_MASKA)
    alter_offset_ust = OFF2_B64UST;
  //сост процесса чтения уставок
  int condition = READ_UST_BUSY;//процесс чтения уст занят
  switch(missionSeparatorDEVICE1)
  {
  case CBACK_MISSION_1BREAD_MASSIV:
  {
    missionSeparatorDEVICE1 = CBACK_NOMISSION;//больше миссий не будет
    if(missionCicling<(MAX_B64UST -1)) //циклы одинаковых миссий
    {
      //сформировать миссию записи уставок в EEPROM 1 блок
      Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling +alter_offset_ust,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling);
      missionCicling++;//циклы одинаковых миссий
    }//if
    else
    {
      missionCicling = 0;//циклы одинаковых миссий
      condition = READ_UST_COMPLETE;//процесс чтения уст завершен
    }
  }
  break;

  default:;//NO MORE MISSION
  }//switch

  return  condition;//процесс чтения уст
}//stepElementReadUSTAVKItoEEPROM()

int stepElementRead1USTAVKItoEEPROM(int alter)
{
//исполнение миссий для чтения уставок
  int                      alter_offset_ust = OFF1_B64UST;
  if(alter&USTALTER_MASKA)
    alter_offset_ust = OFF2_B64UST;
//чтение уст EEPROM
  int condition = READ_UST_BUSY;//процесс чтения уст занят
  //сформировать миссию чтения уст  EEPROM 1 блок
  Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom, alter_offset_ust, 0);
  return  condition;//процесс чтения уст
}//stepElementRead1USTAVKItoEEPROM(int alter)

int controlPREPAREust()
{
  controlUst ++;
//подготовка уставок
  if(
    setCRCMassiv((int *)tmp_eeprom, 4*MAX_MNGUSTAVKI)== //CRC для 4 блока уставок
    ((int *)tmp_eeprom)[4*MAX_MNGUSTAVKI]
  ){

    CopyEEPROMtoUstavki(0);//копировать данные из EEPROM в текущие уставки
    AllComponentUstTimers();//Инит таймеров всех комп и подготовка уставок всех комп
    return 0;//нет ошибок
   }//if
  return 1;//ошибка
}//controlPREPAREust()

int controlSaveUst()
{
//контроль результ записи уст
  if(
    setCRCMassiv((int *)tmp_eeprom, 4*MAX_MNGUSTAVKI) == //CRC для 4 блока уставок
    ((int *)tmp_eeprom)[4*MAX_MNGUSTAVKI]  //получить CRC уставок
    //getCRCUstavki()//получить CRC уставок
  ) return 0;
  return 1;//ошибка
}//controlSaveUst()

int breakEEPROM(int alter_offset)
{
//сломать массив в EEPROM
//  int                      alter_offset_ust = OFF1_B64UST;
//  if(alter&USTALTER_MASKA)
//    alter_offset_ust = OFF2_B64UST;
  if(missionSeparatorDEVICE1!=CBACK_NOMISSION) return 1;
  //установить статус UST_ATTEMPT
  eeprom_status |= (1<<EEPROMUST_ATTEMPT);//статусный регистр EEPROM
  //циклы работы с уставками
  eepromCicling = BREAK_BUSY;//процесс записи ломалки занят;
  missionCicling = 0;//циклы одинаковых миссий
  //сформировать миссию записи ломалки  в EEPROM 1 блок
  Build_cbMission_1BWRITE_MASSIV((char *)breakMass, 0, alter_offset);
  return 0;
}//savePARAMtoEEPROM()

