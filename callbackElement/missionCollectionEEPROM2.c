
#include "lpc_types.h"

#include <stdio.h>
#include <string.h>

#include "callbackelement\callbackelementdef.h"
#include "callbackelement\ustrangEEPROMdef.h"

#include "callbackelement\callbackelementfnc.h"
#include "callbackelement\missionCollectionEEPROM.h"

extern CALLBACK_MISSION cb_missionDEVICE2;
extern CALLBACK_MISSION *cb_mission_crrDEVICE2;//текущая миссия
extern short  missionSeparatorDEVICE2;//сепаратор миссии

extern int missionCicling;//циклы одинаковых миссий

void Build_cbMission_1BREAD_MASSIV_DEVICE2(char *massiv, int srcB64, int dstB64)
{
//сформировать миссию чтения массива из EEPROM 
int adrSrc = srcB64*64;//адрес чтения
int adrDst = dstB64*64;//адрес в EEPROM
  if(cb_mission_crrDEVICE2->callBackMaxer<0)
  {
    missionSeparatorDEVICE2 = CBACK_MISSION_1BREAD_MASSIV;//номер миссии  EEPROM на 1 блок
    //1 задача
    OrderCallBack(cb_mission_crrDEVICE2, &callBackEEPROM_READ);//заказать новые задачи
    TASKMISSION_DEFINE1 tmDefine1 =
    {
      (void *)adrSrc,   //source
      &(massiv[adrDst]),//dest
      64//к-во
    };
    SetTaskParam1CallBack(cb_mission_crrDEVICE2, &tmDefine1);//параметры
  }//if(cb_mission_crrDEVICE2->callBackMaxer<0)
}//Build_cbMission_1BREAD_MASSIV_DEVICE2(char *massiv, int srcB64, int dstB64)

void Build_cbMission_1BWRITE_MASSIV_DEVICE2(char *massiv, int srcB64, int dstB64)
{
//сформировать миссию записи массива в EEPROM 
int adrSrc = srcB64*64;//адрес источника
int adrDst = dstB64*64;//адрес в EEPROM
  if(cb_mission_crrDEVICE2->callBackMaxer<0)
  {
    missionSeparatorDEVICE2 = CBACK_MISSION_1BWRITE_MASSIV;//номер миссии записи в EEPROM
    //1 задача
    OrderCallBack(cb_mission_crrDEVICE2, &callBackEEPROM_WRITE);//заказать новые задачи
    TASKMISSION_DEFINE1 tmDefine1 =
    {
      &(massiv[adrSrc]), //source
      (void *)adrDst,//dest
      64//к-во
    };
    SetTaskParam1CallBack(cb_mission_crrDEVICE2, &tmDefine1);//параметры

  }//if(cb_mission_crrDEVICE2->callBackMaxer<0)
}//Build_cbMission_1BWRITE_MASSIV_DEVICE2(char *massiv, int srcB64, int dstB64)

void Build_cbMission_WRITE_EXT1MASSIV_DEVICE2(char *massiv, int src, int dst)
{
  //сформировать миссию записи первого массива ext в EEPROM 
int adrSrc = src;//B64*64;//адрес источника
int adrDst = dst;//B64*64;//адрес в EEPROM
  if(cb_mission_crrDEVICE2->callBackMaxer<0)
  {
    missionSeparatorDEVICE2 = CBACK_MISSION_1BWRITE_MASSIV;//номер миссии записи в EEPROM 
    //1 задача
    OrderCallBack(cb_mission_crrDEVICE2, &callBackEEPROM_WRITE);//заказать новые задачи
    TASKMISSION_DEFINE1 tmDefine1 =
    {
      &(massiv[adrSrc]), //source
      (void *)adrDst,//dest
      60//к-во
    };
    SetTaskParam1CallBack(cb_mission_crrDEVICE2, &tmDefine1);//параметры

  }//if(cb_mission_crrDEVICE2->callBackMaxer<0)
}//Build_cbMission_WRITE_EXT1MASSIV_DEVICE2(char *massiv, int src, int dst)

void Build_cbMission_WRITE_EXTALTER_DEVICE2(char *massiv)
{
//сформировать миссию записи байта alter для ext
  if(cb_mission_crrDEVICE2->callBackMaxer<0)
  {
    missionSeparatorDEVICE2 = CBACK_MISSION_WRITE_ALTER;//номер миссии записи в EEPROM на 1 байт
    //1 задача
    OrderCallBack(cb_mission_crrDEVICE2, &callBackEEPROM_WRITE);//заказать новые задачи
    TASKMISSION_DEFINE1 tmDefine1 =
    {
      &(massiv[0]), //source
      (void *)0x0, //adrDst,//dest
      1//к-во
    };
    SetTaskParam1CallBack(cb_mission_crrDEVICE2, &tmDefine1);//параметры

  }//if(cb_mission_crrDEVICE2->callBackMaxer<0)
}//Build_cbMission_WRITE_EXTALTER_DEVICE2(char *massiv)

