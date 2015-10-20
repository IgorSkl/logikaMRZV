
#include "lpc_types.h"

#include <stdio.h>
#include <string.h>

#include "callbackelement\callbackelementdef.h"
#include "callbackelement\ustrangEEPROMdef.h"

#include "callbackelement\callbackelementfnc.h"
#include "callbackelement\missionCollectionEEPROM.h"

extern CALLBACK_MISSION cb_missionDEVICE2;
extern CALLBACK_MISSION *cb_mission_crrDEVICE2;//������� ������
extern short  missionSeparatorDEVICE2;//��������� ������

extern int missionCicling;//����� ���������� ������

void Build_cbMission_1BREAD_MASSIV_DEVICE2(char *massiv, int srcB64, int dstB64)
{
//������������ ������ ������ ������� �� EEPROM 
int adrSrc = srcB64*64;//����� ������
int adrDst = dstB64*64;//����� � EEPROM
  if(cb_mission_crrDEVICE2->callBackMaxer<0)
  {
    missionSeparatorDEVICE2 = CBACK_MISSION_1BREAD_MASSIV;//����� ������  EEPROM �� 1 ����
    //1 ������
    OrderCallBack(cb_mission_crrDEVICE2, &callBackEEPROM_READ);//�������� ����� ������
    TASKMISSION_DEFINE1 tmDefine1 =
    {
      (void *)adrSrc,   //source
      &(massiv[adrDst]),//dest
      64//�-��
    };
    SetTaskParam1CallBack(cb_mission_crrDEVICE2, &tmDefine1);//���������
  }//if(cb_mission_crrDEVICE2->callBackMaxer<0)
}//Build_cbMission_1BREAD_MASSIV_DEVICE2(char *massiv, int srcB64, int dstB64)

void Build_cbMission_1BWRITE_MASSIV_DEVICE2(char *massiv, int srcB64, int dstB64)
{
//������������ ������ ������ ������� � EEPROM 
int adrSrc = srcB64*64;//����� ���������
int adrDst = dstB64*64;//����� � EEPROM
  if(cb_mission_crrDEVICE2->callBackMaxer<0)
  {
    missionSeparatorDEVICE2 = CBACK_MISSION_1BWRITE_MASSIV;//����� ������ ������ � EEPROM
    //1 ������
    OrderCallBack(cb_mission_crrDEVICE2, &callBackEEPROM_WRITE);//�������� ����� ������
    TASKMISSION_DEFINE1 tmDefine1 =
    {
      &(massiv[adrSrc]), //source
      (void *)adrDst,//dest
      64//�-��
    };
    SetTaskParam1CallBack(cb_mission_crrDEVICE2, &tmDefine1);//���������

  }//if(cb_mission_crrDEVICE2->callBackMaxer<0)
}//Build_cbMission_1BWRITE_MASSIV_DEVICE2(char *massiv, int srcB64, int dstB64)

void Build_cbMission_WRITE_EXT1MASSIV_DEVICE2(char *massiv, int src, int dst)
{
  //������������ ������ ������ ������� ������� ext � EEPROM 
int adrSrc = src;//B64*64;//����� ���������
int adrDst = dst;//B64*64;//����� � EEPROM
  if(cb_mission_crrDEVICE2->callBackMaxer<0)
  {
    missionSeparatorDEVICE2 = CBACK_MISSION_1BWRITE_MASSIV;//����� ������ ������ � EEPROM 
    //1 ������
    OrderCallBack(cb_mission_crrDEVICE2, &callBackEEPROM_WRITE);//�������� ����� ������
    TASKMISSION_DEFINE1 tmDefine1 =
    {
      &(massiv[adrSrc]), //source
      (void *)adrDst,//dest
      60//�-��
    };
    SetTaskParam1CallBack(cb_mission_crrDEVICE2, &tmDefine1);//���������

  }//if(cb_mission_crrDEVICE2->callBackMaxer<0)
}//Build_cbMission_WRITE_EXT1MASSIV_DEVICE2(char *massiv, int src, int dst)

void Build_cbMission_WRITE_EXTALTER_DEVICE2(char *massiv)
{
//������������ ������ ������ ����� alter ��� ext
  if(cb_mission_crrDEVICE2->callBackMaxer<0)
  {
    missionSeparatorDEVICE2 = CBACK_MISSION_WRITE_ALTER;//����� ������ ������ � EEPROM �� 1 ����
    //1 ������
    OrderCallBack(cb_mission_crrDEVICE2, &callBackEEPROM_WRITE);//�������� ����� ������
    TASKMISSION_DEFINE1 tmDefine1 =
    {
      &(massiv[0]), //source
      (void *)0x0, //adrDst,//dest
      1//�-��
    };
    SetTaskParam1CallBack(cb_mission_crrDEVICE2, &tmDefine1);//���������

  }//if(cb_mission_crrDEVICE2->callBackMaxer<0)
}//Build_cbMission_WRITE_EXTALTER_DEVICE2(char *massiv)

