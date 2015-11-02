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
extern CALLBACK_MISSION *cb_mission_crrDEVICE1;//������� ������
extern short  missionSeparatorDEVICE1;//��������� ������
extern int timing;
extern int timingLoad;
extern int cicling;
extern int  mngUSTAVKI[];
extern UNS_32 ArrayRANGIR[];
extern char  tmp_eeprom[];//MAX_MNGUSTAVKI*4����� *4�����

extern int missionCicling;//����� ���������� ������

int controlRang;

int stepElementSaveRANGtoEEPROM(int alter)
{
//���������� ������ ��� ������ ����
  int                      alter_offset_rang = OFF1_B64RANG;
  if(alter&USTALTER_MASKA)
    alter_offset_rang = OFF2_B64RANG;
  //���� �������� ������ ����
  int condition = SAVE_RANG_BUSY;//������� ������ ���� �����
  switch(missionSeparatorDEVICE1)
  {
  case CBACK_MISSION_1BWRITE_MASSIV:
  {
    char *sourceData = (char *)ArrayRANGIR;
    missionSeparatorDEVICE1 = CBACK_NOMISSION;//������ ������ �� �����
    if(missionCicling<(MAX_B64RANG-1)) //����� ���������� ������
    {
      //������������ ������ ������ ���� � EEPROM 1 ����
      Build_cbMission_1BWRITE_MASSIV(sourceData,
                                     BLOKMISSION_1 +BLOKMISSION_1*missionCicling,
                                     BLOKMISSION_1 +BLOKMISSION_1*missionCicling +alter_offset_rang);
      missionCicling++;//����� ���������� ������
    }//if
    else
    {
      missionCicling = 0;//����� ���������� ������
      //������������ ������ ������ ���� EEPROM 1 ����
      Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom, alter_offset_rang, 0);
    }
  }
  break;

  case CBACK_MISSION_1BREAD_MASSIV:
  {
    missionSeparatorDEVICE1 = CBACK_NOMISSION;//������ ������ �� �����
    if(missionCicling<(MAX_B64RANG-1)) //����� ���������� ������
    {
      //������������ ������ ������ ���� EEPROM 1 ����
      Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling +alter_offset_rang,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling);
      missionCicling++;//����� ���������� ������
    }///if
    else
    {
      missionCicling = 0;//����� ���������� ������
      condition = SAVE_RANG_COMPLETE;//������� ������ ���� ��������
    }
  }
  break;

  default:;//NO MORE MISSION
  }//switch
  return  condition;//������� ������
}//stepElementSaveRANGtoEEPROM(int cntB64, int offB64)

int stepElementReadRANGtoEEPROM(int alter)
{
//���������� ������ ��� ������ ������������
  int                      alter_offset_rang = OFF1_B64RANG;
 // int                      alter_offset_ust = OFF1_B64UST;
  if(alter&USTALTER_MASKA)
    alter_offset_rang = OFF2_B64RANG;
 // if(alter&USTALTER_MASKA)
   // alter_offset_ust = OFF2_B64UST;
  //���� ��������
  int condition = READ_RANG_BUSY;//������� ������ ���� �����
  switch(missionSeparatorDEVICE1)
  {
  case CBACK_MISSION_1BREAD_MASSIV:
  {
    missionSeparatorDEVICE1 = CBACK_NOMISSION;//������ ������ �� �����
    if(missionCicling<(MAX_B64RANG-1)) //����� ���������� ������
    {
      //������������ ������ ������ ������������ � EEPROM 1 ����
      Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling +alter_offset_rang,
                                    BLOKMISSION_1 +BLOKMISSION_1*missionCicling);
      missionCicling++;//����� ���������� ������
    }//if
    else
    {
      missionCicling = 0;//����� ���������� ������
      condition = READ_RANG_COMPLETE;//������� ������ ���� ��������
    }
  }
  break;

  default:;//NO MORE MISSION
  }//switch

  return  condition;//������� ������ ���
}//stepElementReadUSTAVKItoEEPROM()

int stepElementRead1RANGtoEEPROM(int alter)
{
//���������� ������ ��� ������ ����
  int                      alter_offset_rang = OFF1_B64RANG;
  if(alter&USTALTER_MASKA)
    alter_offset_rang = OFF2_B64RANG;
//������ ���� EEPROM
  int condition = READ_RANG_BUSY;//������� ������ ���� �����
  //������������ ������ ������ ����  EEPROM 1 ����
  Build_cbMission_1BREAD_MASSIV((char *)tmp_eeprom, alter_offset_rang, 0);
  return  condition;//������� ������ ����
}//stepElementRead1RANGtoEEPROM(int alter)

int controlPREPARErang()
{
  controlRang ++;
//���������� ����
//    int tt1 = setCRCMassiv((int *)tmp_eeprom, MAX_MNGRANG); //CRC
//    int tt2 = ((int *)tmp_eeprom)[MAX_MNGRANG];
  if(
    setCRCMassiv((int *)tmp_eeprom, MAX_MNGRANG)== //CRC
    ((int *)tmp_eeprom)[MAX_MNGRANG]
  ){
   CopyEEPROMtoRANGIR();//���������� ������ �� EEPROM � ������
   return 0;//��� ������
   }//if
  return 1;//������
}//controlPREPARErang()

int controlSaveRang()
{
//�������� ������� ������ ����
  if(
    setCRCMassiv((int *)tmp_eeprom, MAX_MNGRANG) == //CRC ��� ����
    ((int *)tmp_eeprom)[MAX_MNGRANG]
    //getCRCrang()//�������� CRC
  ) return 0;
  return 1;//������
}//controlSaveRang()
