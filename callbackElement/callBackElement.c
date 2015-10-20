/*
#include <vcl.h>
#include <strstrea.h>
#include <math.h>
#include <mem.h>
#include <fstream.h>
#include <strstrea.h>
#include <iomanip.h>
#pragma hdrstop

#include "textstream.h"
#include "vmenuDis.h"
#include "component.h"
*/
#include "lpc_types.h"

#include <stdio.h>
#include <string.h>

#include "callbackelement\callbackelementdef.h"
#include "callbackelement\callbackelementfnc.h"


CALLBACK_MISSION cb_missionDEVICE1;//DEVICE1
CALLBACK_MISSION *cb_mission_crrDEVICE1;//текущая миссия DEVICE1
short  missionSeparatorDEVICE1;//сепаратор миссии DEVICE1
int missionCiclingCounter1;//к-во оборотов в миссии

CALLBACK_MISSION cb_missionDEVICE2;//DEVICE2
CALLBACK_MISSION *cb_mission_crrDEVICE2;//текущая миссия DEVICE2
short  missionSeparatorDEVICE2;//сепаратор миссии DEVICE2
int missionCiclingCounter2;//к-во оборотов в миссии

int isActivStepElementDEVICE1() @ "Fast_function"
{
 //активность пошагового элемента
  if(CallBackElement(cb_mission_crrDEVICE1)>=0){
  //проверка к-ва оборотов в миссии
    missionCiclingCounter1 ++;//к-во оборотов в миссии
    if(missionCiclingCounter1>MAX_CICLMISSION) return -1;//миссия затянулась - авария
  }//if
  else{
     missionCiclingCounter1 =0;//к-во оборотов в миссии
     if(missionSeparatorDEVICE1!=CBACK_NOMISSION) return 1;//миссия закончилась
     //миссии не было
     return 2;
  }//else
  //миссия не закончилась
  return 0;
}//isActivStepElementDEVICE1()

int isActivStepElementDEVICE2() @ "Fast_function"
{
 //активность пошагового элемента
  if(CallBackElement(cb_mission_crrDEVICE2)>=0){
  //проверка к-ва оборотов в миссии
    missionCiclingCounter2 ++;//к-во оборотов в миссии
    if(missionCiclingCounter2>MAX_CICLMISSION) return -1;//миссия затянулась - авария
  }//if
  else{
     missionCiclingCounter2 =0;//к-во оборотов в миссии
     if(missionSeparatorDEVICE2!=CBACK_NOMISSION) return 1;//миссия закончилась
     //миссии не было
     return 2;
  }//else
  //миссия не закончилась
  return 0;
}//isActivStepElementDEVICE2()

short CallBackElement(CALLBACK_MISSION *cb_mission) @ "Fast_function"
{
//возвратный элемент
  if(cb_mission->callBackMaxer<0)  //максимальный действительный индекс массива возвр перехода
  {
    cb_mission->callBackIndexer=0;//текущий индекс массива возвратного перехода
    return cb_mission->callBackMaxer;//массив возвратного перехода пустой
  }//if

  cBackTask *cbTmp;//указатель на ф-цию callBack

  cbTmp = *(cBackTask *)(cb_mission->callBackTask[cb_mission->callBackIndexer].pTask);
  while(cbTmp==NULL) //искать действит ф-цию возвратного перехода
  {
    cb_mission->callBackIndexer++;//текущий индекс массива возвратного перехода
    cbTmp = *(cBackTask *)(cb_mission->callBackTask[cb_mission->callBackIndexer].pTask);
    if(cb_mission->callBackIndexer > cb_mission->callBackMaxer)
    {
      cb_mission->callBackMaxer=-1; //максимальный действительный индекс массива возвр перехода
      cb_mission->callBackIndexer=0;//текущий индекс массива возвратного перехода
      return cb_mission->callBackMaxer;//переполнение
    }//if
  }//while

  if(
    cbTmp(&(cb_mission->callBackTask[cb_mission->callBackIndexer]))//возвратный переход
    ==0//успешный переход
  )
  {
    cb_mission->callBackTask[cb_mission->callBackIndexer].pTask = NULL;//указат на задачу
    cb_mission->callBackTask[cb_mission->callBackIndexer].callBackStepCntr=0;//счетчик шагов
  }//if
  else
  {
    cb_mission->callBackTask[cb_mission->callBackIndexer].callBackStepCntr++;//счетчики шагов
    return cb_mission->callBackMaxer;//если неудача то задачи не переключаются
  }//else

  cb_mission->callBackIndexer++;//текущий индекс массива возвратного перехода
  return cb_mission->callBackMaxer;
}//CallBackElement()

short OrderCallBack(CALLBACK_MISSION *cb_mission, char (*pfW)(CALLBACKELEMENT_TASK *))
{
//заказать возвратный переход
  if(cb_mission->callBackMaxer==MAX_TASKMISSION-1) return -1;//переполнение массива возвр перехода
  cb_mission->callBackMaxer++;//максимальный действительный индекс массива возвр перехода
  cb_mission->callBackTask[cb_mission->callBackMaxer].pTask = (void *)pfW;//массив возвратного перехода
  cb_mission->callBackTask[cb_mission->callBackMaxer].callBackStepCntr = 0;//счетчики шагов
  return cb_mission->callBackMaxer;
}

short SetTaskParam1CallBack(CALLBACK_MISSION *cb_mission, TASKMISSION_DEFINE1 *ptmDefine)
{
//параметры отдельной задачи
  cb_mission->callBackTask[cb_mission->callBackMaxer].tmDefine.source = ptmDefine->source;
  cb_mission->callBackTask[cb_mission->callBackMaxer].tmDefine.dest   = ptmDefine->dest;
  cb_mission->callBackTask[cb_mission->callBackMaxer].tmDefine.count  = ptmDefine->count;
  return cb_mission->callBackMaxer;
}//SetTaskParam1CallBack(CALLBACK_MISSION *cb_mission, TASKMISSION_DEFINE1 *ptmDefine)

void initCallBackElement()
{
//инит callBackElement1
  cb_mission_crrDEVICE1 = &cb_missionDEVICE1;//текущая миссия
  cb_mission_crrDEVICE1->callBackMaxer = -1; //исх сост миссии
  missionSeparatorDEVICE1 = CBACK_NOMISSION;//сепаратор миссии - нет миссии

//инит callBackElement2
  cb_mission_crrDEVICE2 = &cb_missionDEVICE2;//текущая миссия
  cb_mission_crrDEVICE2->callBackMaxer = -1; //исх сост миссии
  missionSeparatorDEVICE2 = CBACK_NOMISSION;//сепаратор миссии - нет миссии
}//initCallBackElement()

