
#include "callbackelement\callbackelementdef.h"
#include "callbackelement\ustrangEEPROMdef.h"
#include "dataEEPROM\dataEEPROMdef.h"

#include "callbackelement\callbackelementfnc.h"
#include "dataEEPROM\dataEEPROM.h"

extern int eeprom_status;//��������� ������� EEPROM
extern int alterEEPROM;//����� alter ext ���a��� � ������ EEPROM
extern int maskaAlterEEPROM;//����� ��� alter ext ���a��� � ������ EEPROM
extern int ratingEEPROM;//��������� ������ EEPROM

int eepromCicling_DEVICE2 = UST_NOWORK;//����� ������ � EEPROM
int missionCicling_DEVICE2;//����� ���������� ������

void cicloGrammaEEPROM_DEVICE2() @ "Fast_function"
{
//������ � ������ EEPROM
//���������� ��������� ������ ��� DEVICE2
  switch(isActivStepElementDEVICE2())//���������� ���������� ��������
  {
   case -1:
   {
   //������ EEPROM
   //����� EEPROM ��� ������ ���
   //���������� ������ _FAIL
    eeprom_status |= (1<<EEPROM_FAIL);//��������� ������� EEPROM
   } break;
   case 1:
   {
   //������ �����������
    switch(eepromCicling_DEVICE2)//����� ������ � EEPROM
    {
    case SAVE_EXT_BUSY://������� ������ ext �����
      eepromCicling_DEVICE2 = stepElementSaveEXTtoEEPROM_DEVICE2(alterEEPROM^EXTALTER_MASKA);//������ ext EEPROM � ������ ����
      break;
    case WRITE_EXTALTER_BUSY://������� ������ alter ext �����
      eepromCicling_DEVICE2 = stepElementEXTALTERtoEEPROM_DEVICE2();//������ alter ext EEPROM
      break;
    default:
      ;
    }//switch
  } break;//

//  else
   case 2:
  {
     //������ �� ����
    switch(eepromCicling_DEVICE2)//����� ������ � EEPROM
    {
    case SAVE_EXT_COMPLETE: //������� ������ ext ��������
      if(controlSaveExt())//�������� ������� ������ ext
      {
        //����� EEPROM ��� ������ ����
        //���������� ������ _FAIL
        eeprom_status |= (1<<EEPROM_FAIL);//��������� ������� EEPROM
        return;//�������� ������� ������
      }//if
      alterEEPROM ^= EXTALTER_MASKA;//������ ext �� ������ ����
      writeEXTALTERtoEEPROM_DEVICE2(alterEEPROM);//�������� alter ext � EEPROM
      break;
    case WRITE_EXTALTER_COMPLETE://������� ������ alter ext ��������
      eepromCicling_DEVICE2 = UST_NOWORK;//����� ������ � EEPROM
      if(controlWriteEXTALTER())//�������� ������� ������ alter ext
      {
        //����� EEPROM ��� ������ alter
        //���������� ������ _FAIL
        eeprom_status |= (1<<EEPROM_FAIL);//��������� ������� EEPROM
        return;//�������� ������� ������
      }//if
      
      if(ratingEEPROM == 0){ //��������� ������-������ EEPROM
         //��������� ����������
         saveEXTtoEEPROM(alterEEPROM^EXTALTER_MASKA);//��������� ext � EEPROM
         ratingEEPROM++;//��������� ������-������ EEPROM
      }//if
      else {
      //�������� ������ EXT_BUSY
      eeprom_status &= ~(1<<EEPROMEXT_BUSY);//��������� ������� EEPROM
      eeprom_status &= ~(1<<EEPROMEXT_ATTEMPT);
      //�������� ������ EXT_CRC
      eeprom_status &= ~(1<<EEPROMEXT_CRC);
      ratingEEPROM=0;//��������� ������-������ EEPROM
      }
      
      break;
    default:
      ;
    }//switch
  } break;//
 }//switch

}//cicloGrammaEEPROM_DEVICE2()

