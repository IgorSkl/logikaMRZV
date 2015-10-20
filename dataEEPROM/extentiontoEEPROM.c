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

#include "callbackelement\missionCollectionEEPROM.h"
#include "dataEEPROM\dataEEPROM.h"
#include "psuperVisor\psvisor_helpfnc.h"

extern CALLBACK_MISSION cb_missionDEVICE1;
extern CALLBACK_MISSION *cb_mission_crrDEVICE1;//текущая миссия
extern short  missionSeparatorDEVICE1;//сепаратор миссии
extern int timing;
extern int timingLoad;
extern int cicling;
extern UNS_32 ArrayEXTENTION[];//массив расширения
extern char  tmp_eeprom[];//MAX_MNGUSTAVKI*4блока *4байта

extern short  missionSeparatorDEVICE2;//сепаратор миссии DEVICE2
extern int eepromCicling;//циклы работы
extern int missionCicling;//циклы одинаковых миссий
extern int missionCicling_DEVICE2;//циклы одинаковых миссий
extern int eepromCicling_DEVICE2;//циклы работы
extern int eeprom_status;//статусный регистр EEPROM
extern int alterEEPROM;//байты alter ext устaвок и ранжир EEPROM

int controlExt;

int saveEXTtoEEPROM(int alter)
{
//сохранить ext в EEPROM
  int                      alter_offset_ext = OFF1_B64EXT;
  if(alter&EXTALTER_MASKA)
    alter_offset_ext = OFF2_B64EXT;
  if(missionSeparatorDEVICE2!=CBACK_NOMISSION) return 1;
  //установить статус EXT_ATTEMPT
  eeprom_status |= (1<<EEPROMEXT_ATTEMPT);//статусный регистр EEPROM
  //циклы работы с ext
  eepromCicling_DEVICE2 = SAVE_EXT_BUSY;//процесс записи ext занят;
  missionCicling_DEVICE2 = 0;//циклы одинаковых миссий
  //сформировать миссию записи первого массива ext в EEPROM
  Build_cbMission_WRITE_EXT1MASSIV_DEVICE2((char *)ArrayEXTENTION, 4, 4 +alter_offset_ext*64);
  return 0;
}//saveEXTtoEEPROM()

int stepElementSaveEXTtoEEPROM_DEVICE2(int alter)
{
//исполнение миссий для записи ext
  int                      alter_offset_ext = OFF1_B64EXT;
  if(alter&EXTALTER_MASKA)
    alter_offset_ext = OFF2_B64EXT;
  //сост процесса записи уставок
  int condition = SAVE_EXT_BUSY;//процесс записи ext занят
  switch(missionSeparatorDEVICE2)
  {
  case CBACK_MISSION_1BWRITE_MASSIV:
  {
    char *sourceData = (char *)ArrayEXTENTION;
    missionSeparatorDEVICE2 = CBACK_NOMISSION;//больше миссий не будет
    if(missionCicling_DEVICE2<(MAX_B64EXT-1)) //циклы одинаковых миссий
    {
      //сформировать миссию записи ext в EEPROM 1 блок
      Build_cbMission_1BWRITE_MASSIV_DEVICE2(sourceData,
                                     BLOKMISSION_1 +BLOKMISSION_1*missionCicling_DEVICE2,
                                     BLOKMISSION_1 +BLOKMISSION_1*missionCicling_DEVICE2 +alter_offset_ext);
      missionCicling_DEVICE2++;//циклы одинаковых миссий
    }///if
    else
    {
      missionCicling_DEVICE2 = 0;//циклы одинаковых миссий
      //сформировать миссию чтения ext EEPROM 1 блок
      Build_cbMission_1BREAD_MASSIV_DEVICE2((char *)tmp_eeprom, alter_offset_ext, 0);
    }
  }
  break;

  case CBACK_MISSION_1BREAD_MASSIV:
  {
    missionSeparatorDEVICE2 = CBACK_NOMISSION;//больше миссий не будет
    if(missionCicling_DEVICE2<(MAX_B64EXT-1)) //циклы одинаковых миссий
    {
      //сформировать миссию чтения ext в EEPROM 1 блок
      Build_cbMission_1BREAD_MASSIV_DEVICE2((char *)tmp_eeprom,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling_DEVICE2 +alter_offset_ext,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling_DEVICE2);
      missionCicling_DEVICE2++;//циклы одинаковых миссий
    }//if
    else
    {
      missionCicling_DEVICE2 = 0;//циклы одинаковых миссий
      condition = SAVE_EXT_COMPLETE;//процесс записи ext завершен
    }
  }
  break;

  default:;//NO MORE MISSION
  }//switch
  return  condition;//процесс записи ext
}//stepElementSaveEXTtoEEPROM_DEVICE2()

int writeEXTALTERtoEEPROM_DEVICE2(int alter)
{
//записать alter ext в EEPROM
  if(missionSeparatorDEVICE2!=CBACK_NOMISSION) return 1;
  eepromCicling_DEVICE2 = WRITE_EXTALTER_BUSY;//процесс записи alter занят
  missionCicling_DEVICE2 = 0;//циклы одинаковых миссий
  //сформировать миссию записи alter ext в EEPROM
  ((char *)ArrayEXTENTION)[0] = alter;
  Build_cbMission_WRITE_EXTALTER_DEVICE2((char *)ArrayEXTENTION);
  return 0;
}//writeEXTALTERtoEEPROM_DEVICE2(int alter)

int stepElementEXTALTERtoEEPROM_DEVICE2()
{
//запись alter ext EEPROM
//исполнение миссий для записи alter ext
  //сост процесса записи
  int condition = WRITE_EXTALTER_BUSY;//процесс записи alter занят
  switch(missionSeparatorDEVICE2)
  {
  case CBACK_MISSION_WRITE_ALTER:
  {
    missionSeparatorDEVICE2 = CBACK_NOMISSION;//больше миссий не будет
    //сформировать миссию чтения alter в EEPROM 1 блок
    Build_cbMission_1BREAD_MASSIV_DEVICE2((char *)tmp_eeprom, 0, 0);
  }
  break;

  case CBACK_MISSION_1BREAD_MASSIV:
  {
    missionSeparatorDEVICE2 = CBACK_NOMISSION;//больше миссий не будет
    missionCicling_DEVICE2 = 0;//циклы одинаковых миссий
    condition = WRITE_EXTALTER_COMPLETE;//процесс записи alter завершен
  }
  break;
  default:;//NO MORE MISSION
  }//switch
  return  condition;//процесс записи alter
}//stepElementEXTALTERtoEEPROM_DEVICE2()

int readPARAMfromEEPROM()
{
//читать ext из EEPROM
  if(missionSeparatorDEVICE1!=CBACK_NOMISSION) return 1;
  //установить статус UST_BUSY
  //установить статус UST_ATTEMPT
  eeprom_status |= (1<<EEPROMUST_ATTEMPT);//статусный регистр EEPROM
  eepromCicling = READ_ALT_BUSY;//процесс чтения alter занят
  missionCicling = 0;//циклы одинаковых миссий
  //сформировать миссию чтения alter в EEPROM 1 блок
  Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom, 0, 0);
  return 0;
}//readPARAMfromEEPROM()

int writeUSTALTERtoEEPROM(int alter)
{
//записать alter уставок и ранжир в EEPROM
  if(missionSeparatorDEVICE1!=CBACK_NOMISSION) return 1;
  eepromCicling = WRITE_USTALTER_BUSY;//процесс записи alter занят
  missionCicling = 0;//циклы одинаковых миссий
  //сформировать миссию записи alter ext в EEPROM
  ((char *)ArrayEXTENTION)[1] = (alter>>8);
  Build_cbMission_WRITE_USTALTER((char *)ArrayEXTENTION);
  return 0;
}//writeEXTALTERtoEEPROM(int alter)

int stepElementUSTALTERtoEEPROM()
{
//запись alter уставок и ранж EEPROM
//исполнение миссий для записи alter уставок и ранж
  //сост процесса записи
  int condition = WRITE_USTALTER_BUSY;//процесс записи alter занят
  switch(missionSeparatorDEVICE1)
  {
  case CBACK_MISSION_WRITE_ALTER:
  {
    missionSeparatorDEVICE1 = CBACK_NOMISSION;//больше миссий не будет
    //сформировать миссию чтения alter в EEPROM 1 блок
    Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom, 0, 0);
  }
  break;

  case CBACK_MISSION_1BREAD_MASSIV:
  {
    missionSeparatorDEVICE1 = CBACK_NOMISSION;//больше миссий не будет
    missionCicling = 0;//циклы одинаковых миссий
    condition = WRITE_USTALTER_COMPLETE;//процесс записи alter завершен
  }
  break;
  default:;//NO MORE MISSION
  }//switch
  return  condition;//процесс записи alter
}//stepElementUSTALTERtoEEPROM()

int stepElementReadEXTPRItoEEPROM(int alter)
{
//читать ext primary из EEPROM
  int                      alter_offset_ext = OFF1_B64EXT;
  if(alter&EXTALTER_MASKA) alter_offset_ext = OFF2_B64EXT;
  eepromCicling = READ_EXT_BUSY;//процесс чтения alter занят
  missionCicling = 0;//циклы одинаковых миссий
  //сформировать миссию чтения ext в EEPROM 1 блок
  Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom, alter_offset_ext, 0);
  return eepromCicling;
}//readPARAMfromEEPROM()

int stepElementReadEXTtoEEPROM(int alter)
{
//исполнение миссий для чтения ext
  int                      alter_offset_ext = OFF1_B64EXT;
  if(alter&EXTALTER_MASKA)
    alter_offset_ext = OFF2_B64EXT;
  //сост процесса
  int condition = READ_EXT_BUSY;//процесс чтения ext занят
  switch(missionSeparatorDEVICE1)
  {
  case CBACK_MISSION_1BREAD_MASSIV:
  {
    missionSeparatorDEVICE1 = CBACK_NOMISSION;//больше миссий не будет
    if(missionCicling<(MAX_B64EXT-1)) //циклы одинаковых миссий
    {
      //сформировать миссию чтения ext EEPROM 1 блок
      Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling +alter_offset_ext,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling);
      missionCicling++;//циклы одинаковых миссий
    }//if
    else
    {
      missionCicling = 0;//циклы одинаковых миссий
      condition = READ_EXT_COMPLETE;//процесс чтения ext завершен
    }
  }
  break;

  default:;//NO MORE MISSION
  }//switch

  return  condition;//процесс чтения уст
}//stepElementReadEXTtoEEPROM()

int controlPREPAREext()
{
  controlExt++;
//подготовка ext
  if(
    setCRCMassiv(&(((int *)tmp_eeprom)[1]), MAX_MNGEXT-1)==//CRC для ext
    ((int *)tmp_eeprom)[MAX_MNGEXT]
  ) return 0;//нет ошибок
  return 1;//ошибка
}//controlPREPAREext()

int controlPREPAREalter()
{
//подготовка alter ext уст и ранж
  ArrayEXTENTION[0] = ((int *)tmp_eeprom)[0];//массив расширения
  return ArrayEXTENTION[0]&0xffff;
}//controlPREPAREalter()

int controlWriteEXTALTER()
{
//контроль результ записи alter ext
 int alt1 = (alterEEPROM&EXTALTER_MASKA);
 int alt2 = (((int *)tmp_eeprom)[0])&EXTALTER_MASKA;
  if(alt1==alt2) return 0;//нет ошибок
  //ошибка
  return 1;
}//controlWriteEXTALTER()

int controlWriteUSTALTER()
{
//контроль результ записи alter ext
 int alt1 = (alterEEPROM&USTALTER_MASKA);
 int alt2 = (((int *)tmp_eeprom)[0])&USTALTER_MASKA;
  if(alt1==alt2) return 0;//нет ошибок
  //ошибка
  return 1;
}//controlWriteUSTALTER()

int controlSaveExt()
{
//контроль результ записи ext
  if(
    //пропустить alter
    setCRCMassiv(&(((int *)tmp_eeprom)[1]), MAX_MNGEXT-1) == //CRC для ext
    ((int *)tmp_eeprom)[MAX_MNGEXT]
  ) return 0;
  return 1;//ошибка
}//controlSaveExt()
