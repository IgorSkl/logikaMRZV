
#include "callbackelement\callbackelementdef.h"
#include "callbackelement\ustrangEEPROMdef.h"
#include "dataEEPROM\dataEEPROMdef.h"

#include "callbackelement\callbackelementfnc.h"
#include "dataEEPROM\dataEEPROM.h"

int eeprom_status;//статусный регистр EEPROM

int missionCicling;//циклы одинаковых миссий
int eepromCicling = UST_NOWORK;//циклы работы с EEPROM
int alterEEPROM = 0;//x101;//0;//байты alter ext устaвок и ранжир EEPROM
int maskaAlterEEPROM = 0;//маска для alter ext устaвок и ранжир EEPROM
int ratingEEPROM = 0;//кратность чтения EEPROM

void dataAccessEEPROM() @ "Fast_function"
{
//доступ к данным EEPROM 
  
  if( !//статусный регистр EEPROM
      //отказ EEPROM
      (eeprom_status & (1<<EEPROM_FAIL)) 
      
     ){
      //EEPROM EXT_BUSY
      if(!(eeprom_status & (1<<EEPROMEXT_BUSY))){
		  //статус UST_ATTEMPT
            if((eeprom_status & (1<<EEPROMUST_ATTEMPT))){//статусный регистр EEPROM
                          eeprom_status |= (1<<EEPROMUST_BUSY);
			  cicloGrammaEEPROM_DEVICE1();//циклограмма EEPROM DEVICE1
			    }//if
			  }//if
      //EEPROM UST_BUSY
      if(!(eeprom_status & (1<<EEPROMUST_BUSY))){
		  //статус EXT_ATTEMPT
            if((eeprom_status & (1<<EEPROMEXT_ATTEMPT))){//статусный регистр EEPROM
                          eeprom_status |= (1<<EEPROMEXT_BUSY);
			  cicloGrammaEEPROM_DEVICE2();//циклограмма EEPROM DEVICE2
			    }//if
			  }//if
      }//if
}//dataAccessEEPROM()

void cicloGrammaEEPROM_DEVICE1()// @ "Fast_function"
{
//доступ к данным EEPROM
//исполнение пошаговых миссий для DEVICE1
  switch(isActivStepElementDEVICE1())//активность пошагового элемента
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
    switch(eepromCicling)//циклы работы с EEPROM
    {
    case BREAK_BUSY://процесс записи ломалки
      eepromCicling = UST_NOWORK;//циклы работы с EEPROM
      eeprom_status &= ~(1<<EEPROMUST_ATTEMPT);
      eeprom_status &= ~(1<<EEPROMUST_BUSY);//статусный регистр EEPROM
    break;

    case SAVE_UST_BUSY://процесс записи уст занят
      eepromCicling = stepElementSaveUSTAVKItoEEPROM(alterEEPROM^USTALTER_MASKA);//запись уст EEPROM в другой блок
      break;
    case SAVE_UST_COMPLETE: //процесс записи уст завершен
      if(controlSaveUst())
      {
        //отказ EEPROM при записи уст
        //установить статус _FAIL
        eeprom_status |= (1<<EEPROM_FAIL);//статусный регистр EEPROM
        eepromCicling = UST_NOWORK;//циклы работы с EEPROM
        return;//контроль результ записи уст
      }//if
    case SAVE_RANG_BUSY://процесс записи ранж занят
    {
      eepromCicling = stepElementSaveRANGtoEEPROM(alterEEPROM^USTALTER_MASKA);//запись ранжир EEPROM
    }
    break;
    case WRITE_USTALTER_BUSY://процесс записи alter уставок и ранж занят
      eepromCicling = stepElementUSTALTERtoEEPROM();//запись alter уставок и ранж EEPROM
      break;

    case READ_ALT_BUSY://процесс чтения alter занят
      alterEEPROM = //байты alter ext устaвок и ранжир EEPROM
        controlPREPAREalter();//подготовка alter
      alterEEPROM ^= maskaAlterEEPROM;//маска для alter ext устaвок и ранжир EEPROM
      eepromCicling = stepElementReadEXTPRItoEEPROM(alterEEPROM);//чтение ext primary EEPROM
      break;
    case READ_EXT_BUSY://процесс чтения ext занят
      eepromCicling = stepElementReadEXTtoEEPROM(alterEEPROM);//чтение ext EEPROM
      break;
    case READ_RANG_BUSY://процесс чтения ранж занят
    {
      eepromCicling = stepElementReadRANGtoEEPROM(alterEEPROM);//чтение ранжир EEPROM
    }
    break;
    case READ_UST_BUSY://процесс чтения уст занят
    {
      eepromCicling = stepElementReadUSTAVKItoEEPROM(alterEEPROM);//чтение уст EEPROM
    }
    break;
    default:
      ;
    }//switch
  } break;

//  else
   case 2:
  {
     //миссии не было
    switch(eepromCicling)//циклы работы с EEPROM
    {
    case READ_EXT_COMPLETE: //процесс чтения ext завершен
    {
      if(controlPREPAREext())//подготовка ext
       {
        //ошибка чтения уставок
        if(ratingEEPROM == 0) //кратность чтения-записи EEPROM
        {
          //повтор чтения ext
          maskaAlterEEPROM |= EXTALTER_MASKA;//маска для alter ext EEPROM
	  //сбросить статус UST_CRC
          eeprom_status &= ~(1<<EEPROMUST_CRC);
          ratingEEPROM++;
          readPARAMfromEEPROM();//повторно читать ext из EEPROM
            return;
        }//if(ratingEEPROM == 0)
        else {
	   //EEPROM ext нет CRC
           eeprom_status |= (1<<EEPROMEXT_CRC);
           ratingEEPROM=0;
           //сбросить статус UST_BUSY
   //        eeprom_status &= ~(1<<EEPROMUST_BUSY);//статусный регистр EEPROM
   //        eeprom_status &= ~(1<<EEPROMUST_ATTEMPT);
            //return;
             }//else
      }//if(controlPREPAREext())
      eepromCicling = stepElementRead1RANGtoEEPROM(alterEEPROM);//чтение ранж EEPROM
    }
    break;

    case READ_RANG_COMPLETE: //процесс чтения ранж завершен
    {
      if(controlPREPARErang())//подготовка ранж
       {
        //ошибка чтения уставок-ранжир
        if(ratingEEPROM == 0) //кратность чтения EEPROM
        {
          //повтор чтения 
          if(eeprom_status & (1<<EEPROMEXT_CRC)){
            //EXT тоже не прочиталось - уйти
	   //EEPROM уст нет CRC
           eeprom_status |= (1<<EEPROMUST_CRC);
           //сбросить статус UST_BUSY
           eeprom_status &= ~(1<<EEPROMUST_BUSY);//статусный регистр EEPROM
           eeprom_status &= ~(1<<EEPROMUST_ATTEMPT);
           ratingEEPROM=0;
            return;
          }//if
          maskaAlterEEPROM |= USTALTER_MASKA;//маска для alter уст ранж EEPROM
	  //сбросить статус UST_CRC
          eeprom_status &= ~(1<<EEPROMUST_CRC);
          ratingEEPROM++;
          readPARAMfromEEPROM();//повторно читать параметры из EEPROM
            return;
        }//if(ratingEEPROM == 0)
        else {
	   //EEPROM уст нет CRC
           eeprom_status |= (1<<EEPROMUST_CRC);
           //сбросить статус UST_BUSY
           eeprom_status &= ~(1<<EEPROMUST_BUSY);//статусный регистр EEPROM
           eeprom_status &= ~(1<<EEPROMUST_ATTEMPT);
           ratingEEPROM=0;
            return;
             }//else
      }//if(controlPREPARErang())
      eepromCicling = stepElementRead1USTAVKItoEEPROM(alterEEPROM);//чтение уст EEPROM
    }
    break;

    case READ_UST_COMPLETE: //процесс чтения уст завершен
    {
      eepromCicling = UST_NOWORK;//циклы работы с EEPROM
      if(controlPREPAREust()) //подготовка уставок
      {
        //ошибка чтения уставок
        if(ratingEEPROM == 0) //кратность чтения EEPROM
        {
          //повтор чтения уставок
          maskaAlterEEPROM |= USTALTER_MASKA;//маска для alter устaвок и ранжир EEPROM
         //сбросить статус UST_CRC
          eeprom_status &= ~(1<<EEPROMUST_CRC);
          ratingEEPROM++;
          readPARAMfromEEPROM();//повторно читать уставки и ранж из EEPROM
            return;
        }//if(ratingEEPROM == 0)
        else {
           ratingEEPROM = 0;
	   //EEPROM уст нет CRC
           eeprom_status |= (1<<EEPROMUST_CRC);
           //сбросить статус UST_BUSY
           eeprom_status &= ~(1<<EEPROMUST_BUSY);//статусный регистр EEPROM
           eeprom_status &= ~(1<<EEPROMUST_ATTEMPT);
           return;
             }//else
      }//if(controlPREPAREust())
      else {
           ratingEEPROM = 0;
           //сбросить статус UST_BUSY
           eeprom_status &= ~(1<<EEPROMUST_BUSY);//статусный регистр EEPROM
	   //сбросить статус UST_CRC
           eeprom_status &= ~(1<<EEPROMUST_CRC);
           eeprom_status &= ~(1<<EEPROMUST_ATTEMPT);
            }//else

    }
    break;

    case SAVE_RANG_COMPLETE: //процесс записи уст ранж завершен
      eepromCicling = UST_NOWORK;//циклы работы с EEPROM
      if(controlSaveRang()) //контроль результ записи ранж
      {
        //отказ EEPROM при записи ранж
        //установить статус _FAIL
        eeprom_status |= (1<<EEPROM_FAIL);//статусный регистр EEPROM
        return;//контроль результ записи
      }//if
      alterEEPROM ^= USTALTER_MASKA;//перекл уст на другой блок
      writeUSTALTERtoEEPROM(alterEEPROM);//записать alter уставок и ранжир в EEPROM
      break;
    case WRITE_USTALTER_COMPLETE://процесс записи alter ext завершен
      eepromCicling = UST_NOWORK;//циклы работы с EEPROM
      if(controlWriteUSTALTER())//контроль результ записи alter уст и ранж
      {
        //отказ EEPROM при записи alter
        //установить статус _FAIL
        eeprom_status |= (1<<EEPROM_FAIL);//статусный регистр EEPROM
        return;//контроль результ записи
      }//if
      if(ratingEEPROM == 0){ //кратность чтения-записи EEPROM
         //повторное сохранение
         savePARAMtoEEPROM(alterEEPROM^USTALTER_MASKA);//сохранить уставки и ранж в EEPROM
         ratingEEPROM++;//кратность чтения-записи EEPROM
      }//if
      else {
      //сбросить статус UST_BUSY
      eeprom_status &= ~(1<<EEPROMUST_BUSY);//статусный регистр EEPROM
      eeprom_status &= ~(1<<EEPROMUST_ATTEMPT);
      //сбросить статус UST_CRC
      eeprom_status &= ~(1<<EEPROMUST_CRC);
      ratingEEPROM=0;//кратность чтения-записи EEPROM
      }
      break;
    default:
      ;
    }//switch
  } break;//
 }//switch
}//cicloGrammaEEPROM()
