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

#include "component\componentdef.h"
#include "callbackelement\callbackelementdef.h"
#include "callbackelement\ustrangEEPROMdef.h"
#include "psuperVisor\psvisor_helpdef.h"
#include "virtualMenu\wideLogManagerdef.h"

#include "virtualMenu\rangmanagerfnc.h"
#include "callbackelement\callbackelementfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "callbackelement\missionCollectionEEPROM.h"
#include "dataEEPROM\dataEEPROM.h"

extern CALLBACK_MISSION cb_missionDEVICE1;
extern CALLBACK_MISSION *cb_mission_crrDEVICE1;//текущая миссия
extern short  missionSeparatorDEVICE1;//сепаратор миссии
extern int timing;
extern int timingLoad;
extern int cicling;
extern int  mngUSTAVKI[];
extern UNS_32 ArrayRANGIR[];
extern char  tmp_eeprom[];//MAX_MNGUSTAVKI*4блока *4байта

extern int missionCicling;//циклы одинаковых миссий

int controlRang;

int stepElementSaveRANGtoEEPROM(int alter)
{
//исполнение миссий для записи ранж
  int                      alter_offset_rang = OFF1_B64RANG;
  if(alter&USTALTER_MASKA)
    alter_offset_rang = OFF2_B64RANG;
  //сост процесса записи ранж
  int condition = SAVE_RANG_BUSY;//процесс записи ранж занят
  switch(missionSeparatorDEVICE1)
  {
  case CBACK_MISSION_1BWRITE_MASSIV:
  {
    char *sourceData = (char *)ArrayRANGIR;
    missionSeparatorDEVICE1 = CBACK_NOMISSION;//больше миссий не будет
    if(missionCicling<(MAX_B64RANG-1)) //циклы одинаковых миссий
    {
      //сформировать миссию записи ранж в EEPROM 1 блок
      Build_cbMission_1BWRITE_MASSIV(sourceData,
                                     BLOKMISSION_1 +BLOKMISSION_1*missionCicling,
                                     BLOKMISSION_1 +BLOKMISSION_1*missionCicling +alter_offset_rang);
      missionCicling++;//циклы одинаковых миссий
    }//if
    else
    {
      missionCicling = 0;//циклы одинаковых миссий
      //сформировать миссию чтения ранж EEPROM 1 блок
      Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom, alter_offset_rang, 0);
    }
  }
  break;

  case CBACK_MISSION_1BREAD_MASSIV:
  {
    missionSeparatorDEVICE1 = CBACK_NOMISSION;//больше миссий не будет
    if(missionCicling<(MAX_B64RANG-1)) //циклы одинаковых миссий
    {
      //сформировать миссию чтения ранж EEPROM 1 блок
      Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling +alter_offset_rang,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling);
      missionCicling++;//циклы одинаковых миссий
    }///if
    else
    {
      missionCicling = 0;//циклы одинаковых миссий
      condition = SAVE_RANG_COMPLETE;//процесс записи ранж завершен
    }
  }
  break;

  default:;//NO MORE MISSION
  }//switch
  return  condition;//процесс записи
}//stepElementSaveRANGtoEEPROM(int cntB64, int offB64)

int stepElementReadRANGtoEEPROM(int alter)
{
//исполнение миссий для чтения ранжирования
  int                      alter_offset_rang = OFF1_B64RANG;
 // int                      alter_offset_ust = OFF1_B64UST;
  if(alter&USTALTER_MASKA)
    alter_offset_rang = OFF2_B64RANG;
 // if(alter&USTALTER_MASKA)
   // alter_offset_ust = OFF2_B64UST;
  //сост процесса
  int condition = READ_RANG_BUSY;//процесс чтения ранж занят
  switch(missionSeparatorDEVICE1)
  {
  case CBACK_MISSION_1BREAD_MASSIV:
  {
    missionSeparatorDEVICE1 = CBACK_NOMISSION;//больше миссий не будет
    if(missionCicling<(MAX_B64RANG-1)) //циклы одинаковых миссий
    {
      //сформировать миссию чтения ранжирования в EEPROM 1 блок
      Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling +alter_offset_rang,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling);
      missionCicling++;//циклы одинаковых миссий
    }//if
    else
    {
      missionCicling = 0;//циклы одинаковых миссий
      condition = READ_RANG_COMPLETE;//процесс чтения ранж завершен
    }
  }
  break;

  default:;//NO MORE MISSION
  }//switch

  return  condition;//процесс чтения уст
}//stepElementReadUSTAVKItoEEPROM()

int stepElementRead1RANGtoEEPROM(int alter)
{
//исполнение миссий для чтения ранж
  int                      alter_offset_rang = OFF1_B64RANG;
  if(alter&USTALTER_MASKA)
    alter_offset_rang = OFF2_B64RANG;
//чтение ранж EEPROM
  int condition = READ_RANG_BUSY;//процесс чтения ранж занят
  //сформировать миссию чтения ранж  EEPROM 1 блок
  Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom, alter_offset_rang, 0);
  return  condition;//процесс чтения ранж
}//stepElementRead1RANGtoEEPROM(int alter)

int controlPREPARErang()
{
  controlRang ++;
//подготовка ранж
//    int tt1 = setCRCMassiv((int *)tmp_eeprom, MAX_MNGRANG); //CRC
//    int tt2 = ((int *)tmp_eeprom)[MAX_MNGRANG];
  if(
    setCRCMassiv((int *)tmp_eeprom, MAX_MNGRANG)== //CRC
    ((int *)tmp_eeprom)[MAX_MNGRANG]
  ){
   CopyEEPROMtoRANGIR();//копировать данные из EEPROM в ранжир
   return 0;//нет ошибок
   }//if
  return 1;//ошибка
}//controlPREPARErang()

int controlSaveRang()
{
//контроль результ записи ранж
  if(
    setCRCMassiv((int *)tmp_eeprom, MAX_MNGRANG) == //CRC для ранж
    ((int *)tmp_eeprom)[MAX_MNGRANG]
    //getCRCrang()//получить CRC
  ) return 0;
  return 1;//ошибка
}//controlSaveRang()
