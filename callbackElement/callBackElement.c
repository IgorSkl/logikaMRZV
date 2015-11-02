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
CALLBACK_MISSION *cb_mission_crrDEVICE1;//������� ������ DEVICE1
short  missionSeparatorDEVICE1;//��������� ������ DEVICE1
int missionCiclingCounter1;//�-�� �������� � ������

CALLBACK_MISSION cb_missionDEVICE2;//DEVICE2
CALLBACK_MISSION *cb_mission_crrDEVICE2;//������� ������ DEVICE2
short  missionSeparatorDEVICE2;//��������� ������ DEVICE2
int missionCiclingCounter2;//�-�� �������� � ������

int isActivStepElementDEVICE1() @ "Fast_function"
{
 //���������� ���������� ��������
  if(CallBackElement(cb_mission_crrDEVICE1)>=0){
  //�������� �-�� �������� � ������
    missionCiclingCounter1 ++;//�-�� �������� � ������
    if(missionCiclingCounter1>MAX_CICLMISSION) return -1;//������ ���������� - ������
  }//if
  else{
     missionCiclingCounter1 =0;//�-�� �������� � ������
     if(missionSeparatorDEVICE1!=CBACK_NOMISSION) return 1;//������ �����������
     //������ �� ����
     return 2;
  }//else
  //������ �� �����������
  return 0;
}//isActivStepElementDEVICE1()

int isActivStepElementDEVICE2() @ "Fast_function"
{
 //���������� ���������� ��������
  if(CallBackElement(cb_mission_crrDEVICE2)>=0){
  //�������� �-�� �������� � ������
    missionCiclingCounter2 ++;//�-�� �������� � ������
    if(missionCiclingCounter2>MAX_CICLMISSION) return -1;//������ ���������� - ������
  }//if
  else{
     missionCiclingCounter2 =0;//�-�� �������� � ������
     if(missionSeparatorDEVICE2!=CBACK_NOMISSION) return 1;//������ �����������
     //������ �� ����
     return 2;
  }//else
  //������ �� �����������
  return 0;
}//isActivStepElementDEVICE2()

short CallBackElement(CALLBACK_MISSION *cb_mission) @ "Fast_function"
{
//���������� �������
  if(cb_mission->callBackMaxer<0)  //������������ �������������� ������ ������� ����� ��������
  {
    cb_mission->callBackIndexer=0;//������� ������ ������� ����������� ��������
    return cb_mission->callBackMaxer;//������ ����������� �������� ������
  }//if

  cBackTask *cbTmp;//��������� �� �-��� callBack

  cbTmp = *(cBackTask *)(cb_mission->callBackTask[cb_mission->callBackIndexer].pTask);
  while(cbTmp==NULL) //������ �������� �-��� ����������� ��������
  {
    cb_mission->callBackIndexer++;//������� ������ ������� ����������� ��������
    cbTmp = *(cBackTask *)(cb_mission->callBackTask[cb_mission->callBackIndexer].pTask);
    if(cb_mission->callBackIndexer > cb_mission->callBackMaxer)
    {
      cb_mission->callBackMaxer=-1; //������������ �������������� ������ ������� ����� ��������
      cb_mission->callBackIndexer=0;//������� ������ ������� ����������� ��������
      return cb_mission->callBackMaxer;//������������
    }//if
  }//while

  if(
    cbTmp(&(cb_mission->callBackTask[cb_mission->callBackIndexer]))//���������� �������
    ==0//�������� �������
  )
  {
    cb_mission->callBackTask[cb_mission->callBackIndexer].pTask = NULL;//������ �� ������
    cb_mission->callBackTask[cb_mission->callBackIndexer].callBackStepCntr=0;//������� �����
  }//if
  else
  {
    cb_mission->callBackTask[cb_mission->callBackIndexer].callBackStepCntr++;//�������� �����
    return cb_mission->callBackMaxer;//���� ������� �� ������ �� �������������
  }//else

  cb_mission->callBackIndexer++;//������� ������ ������� ����������� ��������
  return cb_mission->callBackMaxer;
}//CallBackElement()

short OrderCallBack(CALLBACK_MISSION *cb_mission, char (*pfW)(CALLBACKELEMENT_TASK *))
{
//�������� ���������� �������
  if(cb_mission->callBackMaxer==MAX_TASKMISSION-1) return -1;//������������ ������� ����� ��������
  cb_mission->callBackMaxer++;//������������ �������������� ������ ������� ����� ��������
  cb_mission->callBackTask[cb_mission->callBackMaxer].pTask = (void *)pfW;//������ ����������� ��������
  cb_mission->callBackTask[cb_mission->callBackMaxer].callBackStepCntr = 0;//�������� �����
  return cb_mission->callBackMaxer;
}

short SetTaskParam1CallBack(CALLBACK_MISSION *cb_mission, TASKMISSION_DEFINE1 *ptmDefine)
{
//��������� ��������� ������
  cb_mission->callBackTask[cb_mission->callBackMaxer].tmDefine.source = ptmDefine->source;
  cb_mission->callBackTask[cb_mission->callBackMaxer].tmDefine.dest   = ptmDefine->dest;
  cb_mission->callBackTask[cb_mission->callBackMaxer].tmDefine.count  = ptmDefine->count;
  return cb_mission->callBackMaxer;
}//SetTaskParam1CallBack(CALLBACK_MISSION *cb_mission, TASKMISSION_DEFINE1 *ptmDefine)

void initCallBackElement()
{
//���� callBackElement1
  cb_mission_crrDEVICE1 = &cb_missionDEVICE1;//������� ������
  cb_mission_crrDEVICE1->callBackMaxer = -1; //��� ���� ������
  missionSeparatorDEVICE1 = CBACK_NOMISSION;//��������� ������ - ��� ������

//���� callBackElement2
  cb_mission_crrDEVICE2 = &cb_missionDEVICE2;//������� ������
  cb_mission_crrDEVICE2->callBackMaxer = -1; //��� ���� ������
  missionSeparatorDEVICE2 = CBACK_NOMISSION;//��������� ������ - ��� ������
}//initCallBackElement()

