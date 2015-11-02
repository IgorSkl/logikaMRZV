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
extern CALLBACK_MISSION *cb_mission_crrDEVICE1;//������� ������
extern short  missionSeparatorDEVICE1;//��������� ������
extern int timing;
extern int timingLoad;
extern int cicling;
extern int  blokUSTAVKI[];
extern UNS_32 ArrayRANGIR[];
extern char  tmp_eeprom[];//MAX_MNGUSTAVKI*4����� *4�����

extern int missionCicling;//����� ���������� ������
extern int eepromCicling;//����� ������ � EEPROM
extern int alterEEPROM;//����� alter ext ���a��� � ������ EEPROM
extern int eeprom_status;//��������� ������� EEPROM

int controlUst;
int breakMass[3] = {100, 200, 300};
int savePARAMtoEEPROM(int alter)
{
//��������� ������� � EEPROM
  int                      alter_offset_ust = OFF1_B64UST;
  if(alter&USTALTER_MASKA)
    alter_offset_ust = OFF2_B64UST;
  if(missionSeparatorDEVICE1!=CBACK_NOMISSION) return 1;
  //���������� ������ UST_ATTEMPT
  eeprom_status |= (1<<EEPROMUST_ATTEMPT);//��������� ������� EEPROM
  //����� ������ � ���������
  eepromCicling = SAVE_UST_BUSY;//������� ������ ��� �����;
  missionCicling = 0;//����� ���������� ������
  //������������ ������ ������ ������� � EEPROM 1 ����
  Build_cbMission_1BWRITE_MASSIV((char *)blokUSTAVKI, 0, alter_offset_ust);
  return 0;
}//savePARAMtoEEPROM()

int stepElementSaveUSTAVKItoEEPROM(int alter)
{
//���������� ������ ��� ������ �������
  int                      alter_offset_ust = OFF1_B64UST;
  if(alter&USTALTER_MASKA)
    alter_offset_ust = OFF2_B64UST;
  int                      alter_offset_rang = OFF1_B64RANG;
  if(alter&USTALTER_MASKA)
    alter_offset_rang = OFF2_B64RANG;
  //���� �������� ������ �������
  int condition = SAVE_UST_BUSY;//������� ������ ��� �����
  switch(missionSeparatorDEVICE1)
  {
  case CBACK_MISSION_1BWRITE_MASSIV:
  {
    char *sourceData = (char *)blokUSTAVKI;
    missionSeparatorDEVICE1 = CBACK_NOMISSION;//������ ������ �� �����
    if(missionCicling<(MAX_B64UST-1)) //����� ���������� ������
    {
      //������������ ������ ������ ������� � EEPROM 1 ����
      Build_cbMission_1BWRITE_MASSIV(sourceData,
                                     BLOKMISSION_1 +BLOKMISSION_1*missionCicling,
                                     BLOKMISSION_1 +BLOKMISSION_1*missionCicling +alter_offset_ust);
      missionCicling++;//����� ���������� ������
    }///if
    else
    {
      missionCicling = 0;//����� ���������� ������
      //������������ ������ ������ ������� EEPROM 1 ����
      Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom, alter_offset_ust, 0);
    }
  }
  break;

  case CBACK_MISSION_1BREAD_MASSIV:
  {
    missionSeparatorDEVICE1 = CBACK_NOMISSION;//������ ������ �� �����
    if(missionCicling<(MAX_B64UST-1)) //����� ���������� ������
    {
      //������������ ������ ������ ������� EEPROM 1 ����
      Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling +alter_offset_ust,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling);
      missionCicling++;//����� ���������� ������
    }//if
    else
    {
      missionCicling = 0;//����� ���������� ������
      condition = SAVE_UST_COMPLETE;//������� ������ ��� ��������
      //������������ ������ ������ ���� EEPROM 1 ����
      Build_cbMission_1BWRITE_MASSIV((char *)ArrayRANGIR, 0, alter_offset_rang);
    }
  }
  break;

  default:;//NO MORE MISSION
  }//switch

  return  condition;//������� ������ ���
}//stepElementSaveUSTAVKItoEEPROM()

int stepElementReadUSTAVKItoEEPROM(int alter)
{
//���������� ������ ��� ������ �������
  int                      alter_offset_ust = OFF1_B64UST;
  if(alter&USTALTER_MASKA)
    alter_offset_ust = OFF2_B64UST;
  //���� �������� ������ �������
  int condition = READ_UST_BUSY;//������� ������ ��� �����
  switch(missionSeparatorDEVICE1)
  {
  case CBACK_MISSION_1BREAD_MASSIV:
  {
    missionSeparatorDEVICE1 = CBACK_NOMISSION;//������ ������ �� �����
    if(missionCicling<(MAX_B64UST -1)) //����� ���������� ������
    {
      //������������ ������ ������ ������� � EEPROM 1 ����
      Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling +alter_offset_ust,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling);
      missionCicling++;//����� ���������� ������
    }//if
    else
    {
      missionCicling = 0;//����� ���������� ������
      condition = READ_UST_COMPLETE;//������� ������ ��� ��������
    }
  }
  break;

  default:;//NO MORE MISSION
  }//switch

  return  condition;//������� ������ ���
}//stepElementReadUSTAVKItoEEPROM()

int stepElementRead1USTAVKItoEEPROM(int alter)
{
//���������� ������ ��� ������ �������
  int                      alter_offset_ust = OFF1_B64UST;
  if(alter&USTALTER_MASKA)
    alter_offset_ust = OFF2_B64UST;
//������ ��� EEPROM
  int condition = READ_UST_BUSY;//������� ������ ��� �����
  //������������ ������ ������ ���  EEPROM 1 ����
  Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom, alter_offset_ust, 0);
  return  condition;//������� ������ ���
}//stepElementRead1USTAVKItoEEPROM(int alter)

int controlPREPAREust()
{
  controlUst ++;
//���������� �������
  if(
    setCRCMassiv((int *)tmp_eeprom, 4*MAX_MNGUSTAVKI)== //CRC ��� 4 ����� �������
    ((int *)tmp_eeprom)[4*MAX_MNGUSTAVKI]
  ){

    CopyEEPROMtoUstavki(0);//���������� ������ �� EEPROM � ������� �������
    AllComponentUstTimers();//���� �������� ���� ���� � ���������� ������� ���� ����
    return 0;//��� ������
   }//if
  return 1;//������
}//controlPREPAREust()

int controlSaveUst()
{
//�������� ������� ������ ���
  if(
    setCRCMassiv((int *)tmp_eeprom, 4*MAX_MNGUSTAVKI) == //CRC ��� 4 ����� �������
    ((int *)tmp_eeprom)[4*MAX_MNGUSTAVKI]  //�������� CRC �������
    //getCRCUstavki()//�������� CRC �������
  ) return 0;
  return 1;//������
}//controlSaveUst()

int breakEEPROM(int alter_offset)
{
//������� ������ � EEPROM
//  int                      alter_offset_ust = OFF1_B64UST;
//  if(alter&USTALTER_MASKA)
//    alter_offset_ust = OFF2_B64UST;
  if(missionSeparatorDEVICE1!=CBACK_NOMISSION) return 1;
  //���������� ������ UST_ATTEMPT
  eeprom_status |= (1<<EEPROMUST_ATTEMPT);//��������� ������� EEPROM
  //����� ������ � ���������
  eepromCicling = BREAK_BUSY;//������� ������ ������� �����;
  missionCicling = 0;//����� ���������� ������
  //������������ ������ ������ �������  � EEPROM 1 ����
  Build_cbMission_1BWRITE_MASSIV((char *)breakMass, 0, alter_offset);
  return 0;
}//savePARAMtoEEPROM()

