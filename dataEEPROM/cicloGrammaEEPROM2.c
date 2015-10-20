
#include "callbackelement\callbackelementdef.h"
#include "callbackelement\ustrangEEPROMdef.h"
#include "dataEEPROM\dataEEPROMdef.h"

#include "callbackelement\callbackelementfnc.h"
#include "dataEEPROM\dataEEPROM.h"

extern int eeprom_status;//статусный регистр EEPROM
extern int alterEEPROM;//байты alter ext устaвок и ранжир EEPROM
extern int maskaAlterEEPROM;//маска для alter ext устaвок и ранжир EEPROM
extern int ratingEEPROM;//кратность чтения EEPROM

int eepromCicling_DEVICE2 = UST_NOWORK;//циклы работы с EEPROM
int missionCicling_DEVICE2;//циклы одинаковых миссий

void cicloGrammaEEPROM_DEVICE2() @ "Fast_function"
{
//доступ к данным EEPROM
//исполнение пошаговых миссий для DEVICE2
  switch(isActivStepElementDEVICE2())//активность пошагового элемента
  {
   case -1:
   {
   //авария EEPROM
   //отказ EEPROM при записи уст
   //установить статус _FAIL
    eeprom_status |= (1<<EEPROM_FAIL);//статусный регистр EEPROM
   } break;
   case 1:
   {
   //миссия закончилась
    switch(eepromCicling_DEVICE2)//циклы работы с EEPROM
    {
    case SAVE_EXT_BUSY://процесс записи ext занят
      eepromCicling_DEVICE2 = stepElementSaveEXTtoEEPROM_DEVICE2(alterEEPROM^EXTALTER_MASKA);//запись ext EEPROM в другой блок
      break;
    case WRITE_EXTALTER_BUSY://процесс записи alter ext занят
      eepromCicling_DEVICE2 = stepElementEXTALTERtoEEPROM_DEVICE2();//запись alter ext EEPROM
      break;
    default:
      ;
    }//switch
  } break;//

//  else
   case 2:
  {
     //миссии не было
    switch(eepromCicling_DEVICE2)//циклы работы с EEPROM
    {
    case SAVE_EXT_COMPLETE: //процесс записи ext завершен
      if(controlSaveExt())//контроль результ записи ext
      {
        //отказ EEPROM при записи ранж
        //установить статус _FAIL
        eeprom_status |= (1<<EEPROM_FAIL);//статусный регистр EEPROM
        return;//контроль результ записи
      }//if
      alterEEPROM ^= EXTALTER_MASKA;//перекл ext на другой блок
      writeEXTALTERtoEEPROM_DEVICE2(alterEEPROM);//записать alter ext в EEPROM
      break;
    case WRITE_EXTALTER_COMPLETE://процесс записи alter ext завершен
      eepromCicling_DEVICE2 = UST_NOWORK;//циклы работы с EEPROM
      if(controlWriteEXTALTER())//контроль результ записи alter ext
      {
        //отказ EEPROM при записи alter
        //установить статус _FAIL
        eeprom_status |= (1<<EEPROM_FAIL);//статусный регистр EEPROM
        return;//контроль результ записи
      }//if
      
      if(ratingEEPROM == 0){ //кратность чтения-записи EEPROM
         //повторное сохранение
         saveEXTtoEEPROM(alterEEPROM^EXTALTER_MASKA);//сохранить ext в EEPROM
         ratingEEPROM++;//кратность чтения-записи EEPROM
      }//if
      else {
      //сбросить статус EXT_BUSY
      eeprom_status &= ~(1<<EEPROMEXT_BUSY);//статусный регистр EEPROM
      eeprom_status &= ~(1<<EEPROMEXT_ATTEMPT);
      //сбросить статус EXT_CRC
      eeprom_status &= ~(1<<EEPROMEXT_CRC);
      ratingEEPROM=0;//кратность чтения-записи EEPROM
      }
      
      break;
    default:
      ;
    }//switch
  } break;//
 }//switch

}//cicloGrammaEEPROM_DEVICE2()

