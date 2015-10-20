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
extern CALLBACK_MISSION *cb_mission_crrDEVICE1;//������� ������
extern short  missionSeparatorDEVICE1;//��������� ������
extern int timing;
extern int timingLoad;
extern int cicling;
extern UNS_32 ArrayEXTENTION[];//������ ����������
extern char  tmp_eeprom[];//MAX_MNGUSTAVKI*4����� *4�����

extern short  missionSeparatorDEVICE2;//��������� ������ DEVICE2
extern int eepromCicling;//����� ������
extern int missionCicling;//����� ���������� ������
extern int missionCicling_DEVICE2;//����� ���������� ������
extern int eepromCicling_DEVICE2;//����� ������
extern int eeprom_status;//��������� ������� EEPROM
extern int alterEEPROM;//����� alter ext ���a��� � ������ EEPROM

int controlExt;

int saveEXTtoEEPROM(int alter)
{
//��������� ext � EEPROM
  int                      alter_offset_ext = OFF1_B64EXT;
  if(alter&EXTALTER_MASKA)
    alter_offset_ext = OFF2_B64EXT;
  if(missionSeparatorDEVICE2!=CBACK_NOMISSION) return 1;
  //���������� ������ EXT_ATTEMPT
  eeprom_status |= (1<<EEPROMEXT_ATTEMPT);//��������� ������� EEPROM
  //����� ������ � ext
  eepromCicling_DEVICE2 = SAVE_EXT_BUSY;//������� ������ ext �����;
  missionCicling_DEVICE2 = 0;//����� ���������� ������
  //������������ ������ ������ ������� ������� ext � EEPROM
  Build_cbMission_WRITE_EXT1MASSIV_DEVICE2((char *)ArrayEXTENTION, 4, 4 +alter_offset_ext*64);
  return 0;
}//saveEXTtoEEPROM()

int stepElementSaveEXTtoEEPROM_DEVICE2(int alter)
{
//���������� ������ ��� ������ ext
  int                      alter_offset_ext = OFF1_B64EXT;
  if(alter&EXTALTER_MASKA)
    alter_offset_ext = OFF2_B64EXT;
  //���� �������� ������ �������
  int condition = SAVE_EXT_BUSY;//������� ������ ext �����
  switch(missionSeparatorDEVICE2)
  {
  case CBACK_MISSION_1BWRITE_MASSIV:
  {
    char *sourceData = (char *)ArrayEXTENTION;
    missionSeparatorDEVICE2 = CBACK_NOMISSION;//������ ������ �� �����
    if(missionCicling_DEVICE2<(MAX_B64EXT-1)) //����� ���������� ������
    {
      //������������ ������ ������ ext � EEPROM 1 ����
      Build_cbMission_1BWRITE_MASSIV_DEVICE2(sourceData,
                                     BLOKMISSION_1 +BLOKMISSION_1*missionCicling_DEVICE2,
                                     BLOKMISSION_1 +BLOKMISSION_1*missionCicling_DEVICE2 +alter_offset_ext);
      missionCicling_DEVICE2++;//����� ���������� ������
    }///if
    else
    {
      missionCicling_DEVICE2 = 0;//����� ���������� ������
      //������������ ������ ������ ext EEPROM 1 ����
      Build_cbMission_1BREAD_MASSIV_DEVICE2((char *)tmp_eeprom, alter_offset_ext, 0);
    }
  }
  break;

  case CBACK_MISSION_1BREAD_MASSIV:
  {
    missionSeparatorDEVICE2 = CBACK_NOMISSION;//������ ������ �� �����
    if(missionCicling_DEVICE2<(MAX_B64EXT-1)) //����� ���������� ������
    {
      //������������ ������ ������ ext � EEPROM 1 ����
      Build_cbMission_1BREAD_MASSIV_DEVICE2((char *)tmp_eeprom,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling_DEVICE2 +alter_offset_ext,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling_DEVICE2);
      missionCicling_DEVICE2++;//����� ���������� ������
    }//if
    else
    {
      missionCicling_DEVICE2 = 0;//����� ���������� ������
      condition = SAVE_EXT_COMPLETE;//������� ������ ext ��������
    }
  }
  break;

  default:;//NO MORE MISSION
  }//switch
  return  condition;//������� ������ ext
}//stepElementSaveEXTtoEEPROM_DEVICE2()

int writeEXTALTERtoEEPROM_DEVICE2(int alter)
{
//�������� alter ext � EEPROM
  if(missionSeparatorDEVICE2!=CBACK_NOMISSION) return 1;
  eepromCicling_DEVICE2 = WRITE_EXTALTER_BUSY;//������� ������ alter �����
  missionCicling_DEVICE2 = 0;//����� ���������� ������
  //������������ ������ ������ alter ext � EEPROM
  ((char *)ArrayEXTENTION)[0] = alter;
  Build_cbMission_WRITE_EXTALTER_DEVICE2((char *)ArrayEXTENTION);
  return 0;
}//writeEXTALTERtoEEPROM_DEVICE2(int alter)

int stepElementEXTALTERtoEEPROM_DEVICE2()
{
//������ alter ext EEPROM
//���������� ������ ��� ������ alter ext
  //���� �������� ������
  int condition = WRITE_EXTALTER_BUSY;//������� ������ alter �����
  switch(missionSeparatorDEVICE2)
  {
  case CBACK_MISSION_WRITE_ALTER:
  {
    missionSeparatorDEVICE2 = CBACK_NOMISSION;//������ ������ �� �����
    //������������ ������ ������ alter � EEPROM 1 ����
    Build_cbMission_1BREAD_MASSIV_DEVICE2((char *)tmp_eeprom, 0, 0);
  }
  break;

  case CBACK_MISSION_1BREAD_MASSIV:
  {
    missionSeparatorDEVICE2 = CBACK_NOMISSION;//������ ������ �� �����
    missionCicling_DEVICE2 = 0;//����� ���������� ������
    condition = WRITE_EXTALTER_COMPLETE;//������� ������ alter ��������
  }
  break;
  default:;//NO MORE MISSION
  }//switch
  return  condition;//������� ������ alter
}//stepElementEXTALTERtoEEPROM_DEVICE2()

int readPARAMfromEEPROM()
{
//������ ext �� EEPROM
  if(missionSeparatorDEVICE1!=CBACK_NOMISSION) return 1;
  //���������� ������ UST_BUSY
  //���������� ������ UST_ATTEMPT
  eeprom_status |= (1<<EEPROMUST_ATTEMPT);//��������� ������� EEPROM
  eepromCicling = READ_ALT_BUSY;//������� ������ alter �����
  missionCicling = 0;//����� ���������� ������
  //������������ ������ ������ alter � EEPROM 1 ����
  Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom, 0, 0);
  return 0;
}//readPARAMfromEEPROM()

int writeUSTALTERtoEEPROM(int alter)
{
//�������� alter ������� � ������ � EEPROM
  if(missionSeparatorDEVICE1!=CBACK_NOMISSION) return 1;
  eepromCicling = WRITE_USTALTER_BUSY;//������� ������ alter �����
  missionCicling = 0;//����� ���������� ������
  //������������ ������ ������ alter ext � EEPROM
  ((char *)ArrayEXTENTION)[1] = (alter>>8);
  Build_cbMission_WRITE_USTALTER((char *)ArrayEXTENTION);
  return 0;
}//writeEXTALTERtoEEPROM(int alter)

int stepElementUSTALTERtoEEPROM()
{
//������ alter ������� � ���� EEPROM
//���������� ������ ��� ������ alter ������� � ����
  //���� �������� ������
  int condition = WRITE_USTALTER_BUSY;//������� ������ alter �����
  switch(missionSeparatorDEVICE1)
  {
  case CBACK_MISSION_WRITE_ALTER:
  {
    missionSeparatorDEVICE1 = CBACK_NOMISSION;//������ ������ �� �����
    //������������ ������ ������ alter � EEPROM 1 ����
    Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom, 0, 0);
  }
  break;

  case CBACK_MISSION_1BREAD_MASSIV:
  {
    missionSeparatorDEVICE1 = CBACK_NOMISSION;//������ ������ �� �����
    missionCicling = 0;//����� ���������� ������
    condition = WRITE_USTALTER_COMPLETE;//������� ������ alter ��������
  }
  break;
  default:;//NO MORE MISSION
  }//switch
  return  condition;//������� ������ alter
}//stepElementUSTALTERtoEEPROM()

int stepElementReadEXTPRItoEEPROM(int alter)
{
//������ ext primary �� EEPROM
  int                      alter_offset_ext = OFF1_B64EXT;
  if(alter&EXTALTER_MASKA) alter_offset_ext = OFF2_B64EXT;
  eepromCicling = READ_EXT_BUSY;//������� ������ alter �����
  missionCicling = 0;//����� ���������� ������
  //������������ ������ ������ ext � EEPROM 1 ����
  Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom, alter_offset_ext, 0);
  return eepromCicling;
}//readPARAMfromEEPROM()

int stepElementReadEXTtoEEPROM(int alter)
{
//���������� ������ ��� ������ ext
  int                      alter_offset_ext = OFF1_B64EXT;
  if(alter&EXTALTER_MASKA)
    alter_offset_ext = OFF2_B64EXT;
  //���� ��������
  int condition = READ_EXT_BUSY;//������� ������ ext �����
  switch(missionSeparatorDEVICE1)
  {
  case CBACK_MISSION_1BREAD_MASSIV:
  {
    missionSeparatorDEVICE1 = CBACK_NOMISSION;//������ ������ �� �����
    if(missionCicling<(MAX_B64EXT-1)) //����� ���������� ������
    {
      //������������ ������ ������ ext EEPROM 1 ����
      Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling +alter_offset_ext,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling);
      missionCicling++;//����� ���������� ������
    }//if
    else
    {
      missionCicling = 0;//����� ���������� ������
      condition = READ_EXT_COMPLETE;//������� ������ ext ��������
    }
  }
  break;

  default:;//NO MORE MISSION
  }//switch

  return  condition;//������� ������ ���
}//stepElementReadEXTtoEEPROM()

int controlPREPAREext()
{
  controlExt++;
//���������� ext
  if(
    setCRCMassiv(&(((int *)tmp_eeprom)[1]), MAX_MNGEXT-1)==//CRC ��� ext
    ((int *)tmp_eeprom)[MAX_MNGEXT]
  ) return 0;//��� ������
  return 1;//������
}//controlPREPAREext()

int controlPREPAREalter()
{
//���������� alter ext ��� � ����
  ArrayEXTENTION[0] = ((int *)tmp_eeprom)[0];//������ ����������
  return ArrayEXTENTION[0]&0xffff;
}//controlPREPAREalter()

int controlWriteEXTALTER()
{
//�������� ������� ������ alter ext
 int alt1 = (alterEEPROM&EXTALTER_MASKA);
 int alt2 = (((int *)tmp_eeprom)[0])&EXTALTER_MASKA;
  if(alt1==alt2) return 0;//��� ������
  //������
  return 1;
}//controlWriteEXTALTER()

int controlWriteUSTALTER()
{
//�������� ������� ������ alter ext
 int alt1 = (alterEEPROM&USTALTER_MASKA);
 int alt2 = (((int *)tmp_eeprom)[0])&USTALTER_MASKA;
  if(alt1==alt2) return 0;//��� ������
  //������
  return 1;
}//controlWriteUSTALTER()

int controlSaveExt()
{
//�������� ������� ������ ext
  if(
    //���������� alter
    setCRCMassiv(&(((int *)tmp_eeprom)[1]), MAX_MNGEXT-1) == //CRC ��� ext
    ((int *)tmp_eeprom)[MAX_MNGEXT]
  ) return 0;
  return 1;//������
}//controlSaveExt()
