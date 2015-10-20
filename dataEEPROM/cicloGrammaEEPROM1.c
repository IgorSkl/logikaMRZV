
#include "callbackelement\callbackelementdef.h"
#include "callbackelement\ustrangEEPROMdef.h"
#include "dataEEPROM\dataEEPROMdef.h"

#include "callbackelement\callbackelementfnc.h"
#include "dataEEPROM\dataEEPROM.h"

int eeprom_status;//��������� ������� EEPROM

int missionCicling;//����� ���������� ������
int eepromCicling = UST_NOWORK;//����� ������ � EEPROM
int alterEEPROM = 0;//x101;//0;//����� alter ext ���a��� � ������ EEPROM
int maskaAlterEEPROM = 0;//����� ��� alter ext ���a��� � ������ EEPROM
int ratingEEPROM = 0;//��������� ������ EEPROM

void dataAccessEEPROM() @ "Fast_function"
{
//������ � ������ EEPROM 
  
  if( !//��������� ������� EEPROM
      //����� EEPROM
      (eeprom_status & (1<<EEPROM_FAIL)) 
      
     ){
      //EEPROM EXT_BUSY
      if(!(eeprom_status & (1<<EEPROMEXT_BUSY))){
		  //������ UST_ATTEMPT
            if((eeprom_status & (1<<EEPROMUST_ATTEMPT))){//��������� ������� EEPROM
                          eeprom_status |= (1<<EEPROMUST_BUSY);
			  cicloGrammaEEPROM_DEVICE1();//����������� EEPROM DEVICE1
			    }//if
			  }//if
      //EEPROM UST_BUSY
      if(!(eeprom_status & (1<<EEPROMUST_BUSY))){
		  //������ EXT_ATTEMPT
            if((eeprom_status & (1<<EEPROMEXT_ATTEMPT))){//��������� ������� EEPROM
                          eeprom_status |= (1<<EEPROMEXT_BUSY);
			  cicloGrammaEEPROM_DEVICE2();//����������� EEPROM DEVICE2
			    }//if
			  }//if
      }//if
}//dataAccessEEPROM()

void cicloGrammaEEPROM_DEVICE1()// @ "Fast_function"
{
//������ � ������ EEPROM
//���������� ��������� ������ ��� DEVICE1
  switch(isActivStepElementDEVICE1())//���������� ���������� ��������
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
    switch(eepromCicling)//����� ������ � EEPROM
    {
    case BREAK_BUSY://������� ������ �������
      eepromCicling = UST_NOWORK;//����� ������ � EEPROM
      eeprom_status &= ~(1<<EEPROMUST_ATTEMPT);
      eeprom_status &= ~(1<<EEPROMUST_BUSY);//��������� ������� EEPROM
    break;

    case SAVE_UST_BUSY://������� ������ ��� �����
      eepromCicling = stepElementSaveUSTAVKItoEEPROM(alterEEPROM^USTALTER_MASKA);//������ ��� EEPROM � ������ ����
      break;
    case SAVE_UST_COMPLETE: //������� ������ ��� ��������
      if(controlSaveUst())
      {
        //����� EEPROM ��� ������ ���
        //���������� ������ _FAIL
        eeprom_status |= (1<<EEPROM_FAIL);//��������� ������� EEPROM
        eepromCicling = UST_NOWORK;//����� ������ � EEPROM
        return;//�������� ������� ������ ���
      }//if
    case SAVE_RANG_BUSY://������� ������ ���� �����
    {
      eepromCicling = stepElementSaveRANGtoEEPROM(alterEEPROM^USTALTER_MASKA);//������ ������ EEPROM
    }
    break;
    case WRITE_USTALTER_BUSY://������� ������ alter ������� � ���� �����
      eepromCicling = stepElementUSTALTERtoEEPROM();//������ alter ������� � ���� EEPROM
      break;

    case READ_ALT_BUSY://������� ������ alter �����
      alterEEPROM = //����� alter ext ���a��� � ������ EEPROM
        controlPREPAREalter();//���������� alter
      alterEEPROM ^= maskaAlterEEPROM;//����� ��� alter ext ���a��� � ������ EEPROM
      eepromCicling = stepElementReadEXTPRItoEEPROM(alterEEPROM);//������ ext primary EEPROM
      break;
    case READ_EXT_BUSY://������� ������ ext �����
      eepromCicling = stepElementReadEXTtoEEPROM(alterEEPROM);//������ ext EEPROM
      break;
    case READ_RANG_BUSY://������� ������ ���� �����
    {
      eepromCicling = stepElementReadRANGtoEEPROM(alterEEPROM);//������ ������ EEPROM
    }
    break;
    case READ_UST_BUSY://������� ������ ��� �����
    {
      eepromCicling = stepElementReadUSTAVKItoEEPROM(alterEEPROM);//������ ��� EEPROM
    }
    break;
    default:
      ;
    }//switch
  } break;

//  else
   case 2:
  {
     //������ �� ����
    switch(eepromCicling)//����� ������ � EEPROM
    {
    case READ_EXT_COMPLETE: //������� ������ ext ��������
    {
      if(controlPREPAREext())//���������� ext
       {
        //������ ������ �������
        if(ratingEEPROM == 0) //��������� ������-������ EEPROM
        {
          //������ ������ ext
          maskaAlterEEPROM |= EXTALTER_MASKA;//����� ��� alter ext EEPROM
	  //�������� ������ UST_CRC
          eeprom_status &= ~(1<<EEPROMUST_CRC);
          ratingEEPROM++;
          readPARAMfromEEPROM();//�������� ������ ext �� EEPROM
            return;
        }//if(ratingEEPROM == 0)
        else {
	   //EEPROM ext ��� CRC
           eeprom_status |= (1<<EEPROMEXT_CRC);
           ratingEEPROM=0;
           //�������� ������ UST_BUSY
   //        eeprom_status &= ~(1<<EEPROMUST_BUSY);//��������� ������� EEPROM
   //        eeprom_status &= ~(1<<EEPROMUST_ATTEMPT);
            //return;
             }//else
      }//if(controlPREPAREext())
      eepromCicling = stepElementRead1RANGtoEEPROM(alterEEPROM);//������ ���� EEPROM
    }
    break;

    case READ_RANG_COMPLETE: //������� ������ ���� ��������
    {
      if(controlPREPARErang())//���������� ����
       {
        //������ ������ �������-������
        if(ratingEEPROM == 0) //��������� ������ EEPROM
        {
          //������ ������ 
          if(eeprom_status & (1<<EEPROMEXT_CRC)){
            //EXT ���� �� ����������� - ����
	   //EEPROM ��� ��� CRC
           eeprom_status |= (1<<EEPROMUST_CRC);
           //�������� ������ UST_BUSY
           eeprom_status &= ~(1<<EEPROMUST_BUSY);//��������� ������� EEPROM
           eeprom_status &= ~(1<<EEPROMUST_ATTEMPT);
           ratingEEPROM=0;
            return;
          }//if
          maskaAlterEEPROM |= USTALTER_MASKA;//����� ��� alter ��� ���� EEPROM
	  //�������� ������ UST_CRC
          eeprom_status &= ~(1<<EEPROMUST_CRC);
          ratingEEPROM++;
          readPARAMfromEEPROM();//�������� ������ ��������� �� EEPROM
            return;
        }//if(ratingEEPROM == 0)
        else {
	   //EEPROM ��� ��� CRC
           eeprom_status |= (1<<EEPROMUST_CRC);
           //�������� ������ UST_BUSY
           eeprom_status &= ~(1<<EEPROMUST_BUSY);//��������� ������� EEPROM
           eeprom_status &= ~(1<<EEPROMUST_ATTEMPT);
           ratingEEPROM=0;
            return;
             }//else
      }//if(controlPREPARErang())
      eepromCicling = stepElementRead1USTAVKItoEEPROM(alterEEPROM);//������ ��� EEPROM
    }
    break;

    case READ_UST_COMPLETE: //������� ������ ��� ��������
    {
      eepromCicling = UST_NOWORK;//����� ������ � EEPROM
      if(controlPREPAREust()) //���������� �������
      {
        //������ ������ �������
        if(ratingEEPROM == 0) //��������� ������ EEPROM
        {
          //������ ������ �������
          maskaAlterEEPROM |= USTALTER_MASKA;//����� ��� alter ���a��� � ������ EEPROM
         //�������� ������ UST_CRC
          eeprom_status &= ~(1<<EEPROMUST_CRC);
          ratingEEPROM++;
          readPARAMfromEEPROM();//�������� ������ ������� � ���� �� EEPROM
            return;
        }//if(ratingEEPROM == 0)
        else {
           ratingEEPROM = 0;
	   //EEPROM ��� ��� CRC
           eeprom_status |= (1<<EEPROMUST_CRC);
           //�������� ������ UST_BUSY
           eeprom_status &= ~(1<<EEPROMUST_BUSY);//��������� ������� EEPROM
           eeprom_status &= ~(1<<EEPROMUST_ATTEMPT);
           return;
             }//else
      }//if(controlPREPAREust())
      else {
           ratingEEPROM = 0;
           //�������� ������ UST_BUSY
           eeprom_status &= ~(1<<EEPROMUST_BUSY);//��������� ������� EEPROM
	   //�������� ������ UST_CRC
           eeprom_status &= ~(1<<EEPROMUST_CRC);
           eeprom_status &= ~(1<<EEPROMUST_ATTEMPT);
            }//else

    }
    break;

    case SAVE_RANG_COMPLETE: //������� ������ ��� ���� ��������
      eepromCicling = UST_NOWORK;//����� ������ � EEPROM
      if(controlSaveRang()) //�������� ������� ������ ����
      {
        //����� EEPROM ��� ������ ����
        //���������� ������ _FAIL
        eeprom_status |= (1<<EEPROM_FAIL);//��������� ������� EEPROM
        return;//�������� ������� ������
      }//if
      alterEEPROM ^= USTALTER_MASKA;//������ ��� �� ������ ����
      writeUSTALTERtoEEPROM(alterEEPROM);//�������� alter ������� � ������ � EEPROM
      break;
    case WRITE_USTALTER_COMPLETE://������� ������ alter ext ��������
      eepromCicling = UST_NOWORK;//����� ������ � EEPROM
      if(controlWriteUSTALTER())//�������� ������� ������ alter ��� � ����
      {
        //����� EEPROM ��� ������ alter
        //���������� ������ _FAIL
        eeprom_status |= (1<<EEPROM_FAIL);//��������� ������� EEPROM
        return;//�������� ������� ������
      }//if
      if(ratingEEPROM == 0){ //��������� ������-������ EEPROM
         //��������� ����������
         savePARAMtoEEPROM(alterEEPROM^USTALTER_MASKA);//��������� ������� � ���� � EEPROM
         ratingEEPROM++;//��������� ������-������ EEPROM
      }//if
      else {
      //�������� ������ UST_BUSY
      eeprom_status &= ~(1<<EEPROMUST_BUSY);//��������� ������� EEPROM
      eeprom_status &= ~(1<<EEPROMUST_ATTEMPT);
      //�������� ������ UST_CRC
      eeprom_status &= ~(1<<EEPROMUST_CRC);
      ratingEEPROM=0;//��������� ������-������ EEPROM
      }
      break;
    default:
      ;
    }//switch
  } break;//
 }//switch
}//cicloGrammaEEPROM()
