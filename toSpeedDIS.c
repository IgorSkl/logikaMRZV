
//#include <TCHAR.H >

#include <stdio.h>
#include <string.h>

#include "psuperVisor\supermanager.h"

#include "bazisdef.h"
#include "component\componentdef.h"

#include "logictimers\logictimersmac.h"

#include "logictimers\logictimersfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\rangmanagerfnc.h"
#include "virtualMenu\textstreamfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"

#include "virtualMenu\repozitfnc.h"

#include "SettingIci\SettingIci.h"

#include "..\bazis.h"

#include "toSpeedOptim.h"
#include "toSpeedDIS.h"

#define _HIDE_COMPONENT
#include "PRM1Component.c"

extern int offsetTimersPRM1;//смещение на таймерный индекс
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  logMassTimer[];
extern UNS_32 pActualCMD[];//текущие

UNS_32 pUROVcmdMaska[DQUADRO];//определение ЗапускУРОВ
UNS_32 pAPVcmdMaska[DQUADRO];//определение ЗапускАПВ
//UNS_32 pAPVcmdActual[DQUADRO];//ЗапускАПВ Actual
//UNS_32 pUROVcmdActual[DQUADRO];//ЗапускУРОВ Actual
//UNS_32 pAPVcmdOld[DQUADRO];//ЗапускАПВ Old
//UNS_32 pUROVcmdOld[DQUADRO];//ЗапускУРОВ Old
 MaskaOTAPVUROVOFcmd struct_maskaOTAPVUROVOFcmd;//маски для 16 опред функций
 MaskaOTcmd struct_maskaOTcmd;//маски для 8 опред триггер
UNS_32 pResetBVcmdMaska[DQUADRO];//определение Сброс Блока Включения

//----------------------------------------
int reset_bv;//сброс блока включения

int puskAPV, puskUROV, pusk1OF, pusk2OF, pusk3OF;
int pusk1OF2, pusk2OF2, pusk3OF2;
int pusk1OF3, pusk2OF3, pusk3OF3;
int pusk1OF4, pusk2OF4, pusk3OF4;
int pusk1OF5, pusk2OF5, pusk3OF5;
int pusk1OF6, pusk2OF6, pusk3OF6;
int pusk1OF7, pusk2OF7, pusk3OF7;
int pusk1OF8, pusk2OF8, pusk3OF8;
int pusk1OF9, pusk2OF9, pusk3OF9;
int pusk1OF10, pusk2OF10, pusk3OF10;
int pusk1OF11, pusk2OF11, pusk3OF11;
int pusk1OF12, pusk2OF12, pusk3OF12;
int pusk1OF13, pusk2OF13, pusk3OF13;
int pusk1OF14, pusk2OF14, pusk3OF14;
int pusk1OF15, pusk2OF15, pusk3OF15;
int pusk1OF16, pusk2OF16, pusk3OF16;

int pusk1OT1, pusk2OT1;
int pusk1OT2, pusk2OT2;
int pusk1OT3, pusk2OT3;
int pusk1OT4, pusk2OT4;
int pusk1OT5, pusk2OT5;
int pusk1OT6, pusk2OT6;
int pusk1OT7, pusk2OT7;
int pusk1OT8, pusk2OT8;

/*
int pusk1OT1_old, pusk2OT1_old;
int pusk1OT2_old, pusk2OT2_old;
int pusk1OT3_old, pusk2OT3_old;
int pusk1OT4_old, pusk2OT4_old;
int pusk1OT5_old, pusk2OT5_old;
int pusk1OT6_old, pusk2OT6_old;
int pusk1OT7_old, pusk2OT7_old;
int pusk1OT8_old, pusk2OT8_old;
*/

int rst1OT1, rst2OT1;
int rst1OT2, rst2OT2;
int rst1OT3, rst2OT3;
int rst1OT4, rst2OT4;
int rst1OT5, rst2OT5;
int rst1OT6, rst2OT6;
int rst1OT7, rst2OT7;
int rst1OT8, rst2OT8;

/*
int rst1OT1_old, rst2OT1_old;
int rst1OT2_old, rst2OT2_old;
int rst1OT3_old, rst2OT3_old;
int rst1OT4_old, rst2OT4_old;
int rst1OT5_old, rst2OT5_old;
int rst1OT6_old, rst2OT6_old;
int rst1OT7_old, rst2OT7_old;
int rst1OT8_old, rst2OT8_old;

int setOT1DV_old;
int setOT2DV_old;
int setOT3DV_old;
int setOT4DV_old;
int setOT5DV_old;
int setOT6DV_old;
int setOT7DV_old;
int setOT8DV_old;

int resOT1DV_old;
int resOT2DV_old;
int resOT3DV_old;
int resOT4DV_old;
int resOT5DV_old;
int resOT6DV_old;
int resOT7DV_old;
int resOT8DV_old;
*/

int OTout[8];//Выходы OT

UNS_32 pRDIScmdMaska[DQUADRO];//РегистрацияДИС
UNS_32 pRDIScmdActual[DQUADRO];//РегистрацияДИС AND Текущие
UNS_32 pRDIScmdOld[DQUADRO];//РегистрацияДИС AND Текущие old
UNS_32 oldDIS[DQUADRO];
UNS_32 act_oldDIS[DQUADRO];

int activityDISold=0;//TRG DIS
int activitySEAMold=0;//TRG SEAM
REGISTRATOR_DIS registrator_dis;//массив ДИС
/*
void pullReleBO() @ "Fast_function"
{
//тянуть реле на БО
extern UNS_32 rele_bdvv1;//селекция реле
extern UNS_32 rele_bdbo_old;//селекция реле
extern UNS_32 maskaReleBO;

 int tmpOffsetT = offsetTimersPRM1;//смещение на таймерный индекс PRM1

 //нисходящий фронт
  int focusReleBO =(
    (rele_bdvv1^rele_bdbo_old)&rele_bdbo_old//селекция реле
     )&maskaReleBO;
  rele_bdbo_old = rele_bdvv1;

 int tmp=0;
 if(focusReleBO){
   tmp = 1;
 }//if

 LSIGNAL_TIMER(TIMER_RELEBO) = tmp;//таймер БО
 int timlog = FLOG_TIMER(TIMER_RELEBO);
 if(timlog){
  //таймер активный - тянуть
  rele_bdvv1 |= maskaReleBO;
 }//if
}//pullReleBO()
*/

//int IVV_maxMonitoring;//сбор данных макс сраб по I для ВВ

//int Cnt_VV_OTKL;//к-во отключений ВВ
//int resurs_vymykacha;//остаток отключений ВВ

void pullReleBO() @ "Fast_function"
{
//тянуть реле на БО
  static int isTimerBO_old;
extern UNS_32 rele_bdvv1;//селекция реле
extern UNS_32 maskaReleBO;

static UNS_32 rele_bdbo_old;//селекция реле
static int IA_maxMonitoring;//сбор данных макс сраб по IA
static int IVV_maxMonitoring;//сбор данных макс сраб по I для ВВ

static int IVV_maxFix;//фиксация данных макс сраб по I для ВВ
static int Cnt_VV_OTKL;//к-во отключений ВВ
static int resurs_vymykacha;//остаток отключений ВВ
extern int GlobalLevelI_ABC[];//уровни фазных токов Фурье

 int tmpOffsetT = offsetTimersPRM1;//смещение на таймерный индекс PRM1

 int isTimerBO =0;
 //нисходящий фронт
 int tmp1=0;
 if(rele_bdvv1&maskaReleBO){//focusReleBO){
   tmp1 = 1;
 }//if
 int focusReleBO = (tmp1^rele_bdbo_old)&rele_bdbo_old;
  rele_bdbo_old = tmp1;


 LSIGNAL_TIMER(TIMER_RELEBO) = focusReleBO;//tmp;//таймер БО
  isTimerBO = FLOG_TIMER(TIMER_RELEBO);
 if(isTimerBO){
  //таймер активный - тянуть
  rele_bdvv1 |= maskaReleBO;
 }//if
//формируем сигнал сброса Блока Включения
/*
//выдержка формирователя удлинения блокировки Блока включения
  setTimerPorog(tmpOffsetT+ TIMER_DELAYBLOKIRBLOKVKL_PRM1,
*/
  //выдержка удлиннения блокировки Блока включения
  LSIGNAL_TIMER(TIMER_DELAYBLOKIRBLOKVKL_PRM1) = isTimerBO;

 //int isBOactiv = getTimerBUSY(tmpOffsetT+TIMER_RELEBO);//есть активность BO
 //восходящий фронт
 int BO_activ_UP = (
    (isTimerBO_old^isTimerBO) & isTimerBO);

 //нисходящий фронт
 int BO_activ_DOWN = (
    (isTimerBO_old^isTimerBO) & isTimerBO_old);
 isTimerBO_old = isTimerBO;

  if(BO_activ_UP){
   //мониторить максим ток отключения
   if(IVV_maxMonitoring<GlobalLevelI_ABC[0]) IVV_maxMonitoring=GlobalLevelI_ABC[0];//уровни фазных токов Фурье
   if(IVV_maxMonitoring<GlobalLevelI_ABC[1]) IVV_maxMonitoring=GlobalLevelI_ABC[1];//уровни фазных токов Фурье
   if(IVV_maxMonitoring<GlobalLevelI_ABC[2]) IVV_maxMonitoring=GlobalLevelI_ABC[2];//уровни фазных токов Фурье
   }

  if(BO_activ_DOWN){
   //фиксация максим ток отключения
    Cnt_VV_OTKL ++;//к-во отключений ВВ
   //применение формулы
//   Wag_Koef_ResursVV(IVV_maxMonitoring);
   resurs_vymykacha -= Wag_Koef_ResursVV(IVV_maxMonitoring);//остаток отключений ВВ
   if(resurs_vymykacha<0) resurs_vymykacha = 0;

    IVV_maxMonitoring = 0;//сбор данных макс сраб по I для ВВ
   }

}//pullReleBO()


void pullReleBV() @ "Fast_function"
{
//тянуть реле на БB
extern UNS_32 rele_bdvv1;//селекция реле
extern UNS_32 rele_bdbv_old;//селекция реле
extern UNS_32 maskaReleBO, maskaReleBV;

 int tmpOffsetT = offsetTimersPRM1;//смещение на таймерный индекс PRM1

 //восходящий фронт
/*
  int focusReleBV =(
    (rele_bdvv1^rele_bdbv_old)&rele_bdvv1//селекция реле
     )&maskaReleBV;
  rele_bdbv_old = rele_bdvv1;

 int tmp=0;
 if(focusReleBV){
   tmp = 1;
 }//if
*/

 //восходящий фронт
 int tmp1=0;
 if(rele_bdvv1&maskaReleBV){//focusReleBO){
   tmp1 = 1;
 }//if

 LSIGNAL_TIMER(TIMER_RELEBV) = tmp1;//таймер БB
 int timlog = FLOG_TIMER(TIMER_RELEBV);
 if(timlog){
  //таймер активный - тянуть
  rele_bdvv1 |= maskaReleBV;
 }//if
}//pullReleBV()

void PuskAPV_UROV_OFWorking() @ "Fast_function"
{
reset_bv = 0;//сброс блока включения от защит
//пуск АПВ УРОВ ОФ
 puskAPV = puskUROV = pusk1OF = pusk2OF = pusk3OF = 0;
pusk1OF2 = pusk2OF2 = pusk3OF2 = 0;
pusk1OF3 = pusk2OF3 = pusk3OF3 = 0;
pusk1OF4 = pusk2OF4 = pusk3OF4 = 0;
pusk1OF5 = pusk2OF5 = pusk3OF5 = 0;
pusk1OF6 = pusk2OF6 = pusk3OF6 = 0;
pusk1OF7 = pusk2OF7 = pusk3OF7 = 0;
pusk1OF8 = pusk2OF8 = pusk3OF8 = 0;
pusk1OF9 = pusk2OF9 = pusk3OF9 = 0;
pusk1OF10 = pusk2OF10 = pusk3OF10 = 0;
pusk1OF11 = pusk2OF11 = pusk3OF11 = 0;
pusk1OF12 = pusk2OF12 = pusk3OF12 = 0;
pusk1OF13 = pusk2OF13 = pusk3OF13 = 0;
pusk1OF14 = pusk2OF14 = pusk3OF14 = 0;
pusk1OF15 = pusk2OF15 = pusk3OF15 = 0;
pusk1OF16 = pusk2OF16 = pusk3OF16 = 0;

pusk1OT1  = pusk2OT1 = 0;//set PLUS MINUS
rst1OT1  = rst2OT1 = 0;//rst PLUS MINUS

pusk1OT2  = pusk2OT2 = 0;//set PLUS MINUS
rst1OT2  = rst2OT2 = 0;//rst PLUS MINUS
pusk1OT3  = pusk2OT3 = 0;//set PLUS MINUS
rst1OT3  = rst2OT3 = 0;//rst PLUS MINUS
pusk1OT4  = pusk2OT4 = 0;//set PLUS MINUS
rst1OT4  = rst2OT4 = 0;//rst PLUS MINUS
pusk1OT5  = pusk2OT5 = 0;//set PLUS MINUS
rst1OT5  = rst2OT5 = 0;//rst PLUS MINUS
pusk1OT6  = pusk2OT6 = 0;//set PLUS MINUS
rst1OT6  = rst2OT6 = 0;//rst PLUS MINUS
pusk1OT7  = pusk2OT7 = 0;//set PLUS MINUS
rst1OT7  = rst2OT7 = 0;//rst PLUS MINUS
pusk1OT8  = pusk2OT8 = 0;//set PLUS MINUS8
rst1OT8  = rst2OT8 = 0;//rst PLUS MINUS

   if(CheckActualCMD(pAPVcmdMaska))reset_bv = 0;//сброс блока включения от защит

 //ЗапускАПВ big EL
// if(MakeAPVcmdPusk())
   if(CheckActualCMD(pAPVcmdMaska)) puskAPV = 1;
 //ЗапускУРОВ big EL
   if(CheckActualCMD(pUROVcmdMaska)) puskUROV = 1;

 //Запуск1ОФ
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OFcmdMaska))  pusk1OF  = 1;
 //Запуск2ОФ
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OFcmdMaska))  pusk2OF  = 1;
 //Запуск3ОФ
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OFcmdMaska))  pusk3OF  = 1;

 //Запуск1ОФ2
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF2cmdMaska))  pusk1OF2  = 1;
 //Запуск2ОФ2
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF2cmdMaska))  pusk2OF2  = 1;
 //Запуск3ОФ2
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF2cmdMaska))  pusk3OF2  = 1;

 //Запуск1ОФ3
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF3cmdMaska))  pusk1OF3  = 1;
 //Запуск2ОФ3
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF3cmdMaska))  pusk2OF3  = 1;
 //Запуск3ОФ3
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF3cmdMaska))  pusk3OF3  = 1;

 //Запуск1ОФ4
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF4cmdMaska))  pusk1OF4  = 1;
 //Запуск2ОФ4
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF4cmdMaska))  pusk2OF4  = 1;
 //Запуск3ОФ4
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF4cmdMaska))  pusk3OF4  = 1;

 //Запуск1ОФ5
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF5cmdMaska))  pusk1OF5  = 1;
 //Запуск2ОФ5
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF5cmdMaska))  pusk2OF5  = 1;
 //Запуск3ОФ5
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF5cmdMaska))  pusk3OF5  = 1;

 //Запуск1ОФ6
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF6cmdMaska))  pusk1OF6  = 1;
 //Запуск2ОФ6
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF6cmdMaska))  pusk2OF6  = 1;
 //Запуск3ОФ6
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF6cmdMaska))  pusk3OF6  = 1;

 //Запуск1ОФ7
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF7cmdMaska))  pusk1OF7  = 1;
 //Запуск2ОФ7
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF7cmdMaska))  pusk2OF7  = 1;
 //Запуск3ОФ7
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF7cmdMaska))  pusk3OF7  = 1;

 //Запуск1ОФ8
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF8cmdMaska))  pusk1OF8  = 1;
 //Запуск2ОФ8
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF8cmdMaska))  pusk2OF8  = 1;
 //Запуск3ОФ8
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF8cmdMaska))  pusk3OF8  = 1;

 //Запуск1ОФ9
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF9cmdMaska))  pusk1OF9  = 1;
 //Запуск2ОФ9
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF9cmdMaska))  pusk2OF9  = 1;
 //Запуск3ОФ9
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF9cmdMaska))  pusk3OF9  = 1;

 //Запуск1ОФ10
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF10cmdMaska))  pusk1OF10  = 1;
 //Запуск2ОФ10
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF10cmdMaska))  pusk2OF10  = 1;
 //Запуск3ОФ10
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF10cmdMaska))  pusk3OF10  = 1;

 //Запуск1ОФ11
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF11cmdMaska))  pusk1OF11  = 1;
 //Запуск2ОФ11
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF11cmdMaska))  pusk2OF11  = 1;
 //Запуск3ОФ11
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF11cmdMaska))  pusk3OF11  = 1;

 //Запуск1ОФ12
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF12cmdMaska))  pusk1OF12  = 1;
 //Запуск2ОФ12
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF12cmdMaska))  pusk2OF12  = 1;
 //Запуск3ОФ12
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF12cmdMaska))  pusk3OF12  = 1;

 //Запуск1ОФ13
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF13cmdMaska))  pusk1OF13  = 1;
 //Запуск2ОФ13
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF13cmdMaska))  pusk2OF13  = 1;
 //Запуск3ОФ13
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF13cmdMaska))  pusk3OF13  = 1;

 //Запуск1ОФ14
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF14cmdMaska))  pusk1OF14  = 1;
 //Запуск2ОФ14
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF14cmdMaska))  pusk2OF14  = 1;
 //Запуск3ОФ14
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF14cmdMaska))  pusk3OF14  = 1;

 //Запуск1ОФ15
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF15cmdMaska))  pusk1OF15  = 1;
 //Запуск2ОФ15
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF15cmdMaska))  pusk2OF15  = 1;
 //Запуск3ОФ15
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF15cmdMaska))  pusk3OF15  = 1;

 //Запуск1ОФ16
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP1OF16cmdMaska))  pusk1OF16  = 1;
 //Запуск2ОФ16
 if(CheckActualCMDInv(struct_maskaOTAPVUROVOFcmd.pP2OF16cmdMaska))  pusk2OF16  = 1;
 //Запуск3ОФ16
 if(CheckActualCMD(struct_maskaOTAPVUROVOFcmd.pP3OF16cmdMaska))  pusk3OF16  = 1;
//------------OT---------------
 //Запуск1SetOT1
 if(CheckActualCMD(struct_maskaOTcmd.pP1OT1cmdMaska))  pusk1OT1  = 1;//set PLUS
 //Запуск2SetOT1
 if(CheckActualCMD(struct_maskaOTcmd.pP2OT1cmdMaska))  rst1OT1  = 1;//res PLUS
 //Запуск3SetOT1
 if(CheckActualCMDInv(struct_maskaOTcmd.pP3OT1cmdMaska))  pusk2OT1  = 1;//set MINUS
 //Запуск4SetOT1
 if(CheckActualCMDInv(struct_maskaOTcmd.pP4OT1cmdMaska))  rst2OT1  = 1;//res MINUS

 //Запуск1SetOT2
 if(CheckActualCMD(struct_maskaOTcmd.pP1OT2cmdMaska))  pusk1OT2  = 1;//set PLUS
 //Запуск2SetOT2
 if(CheckActualCMD(struct_maskaOTcmd.pP2OT2cmdMaska))  rst1OT2  = 1;//res PLUS
 //Запуск3SetOT2
 if(CheckActualCMDInv(struct_maskaOTcmd.pP3OT2cmdMaska))  pusk2OT2  = 1;//set MINUS
 //Запуск4SetOT2
 if(CheckActualCMDInv(struct_maskaOTcmd.pP4OT2cmdMaska))  rst2OT2  = 1;//res MINUS

  //Запуск1SetOT3
 if(CheckActualCMD(struct_maskaOTcmd.pP1OT3cmdMaska))  pusk1OT3  = 1;//set PLUS
 //Запуск2SetOT3
 if(CheckActualCMD(struct_maskaOTcmd.pP2OT3cmdMaska))  rst1OT3  = 1;//res PLUS
 //Запуск3SetOT3
 if(CheckActualCMDInv(struct_maskaOTcmd.pP3OT3cmdMaska))  pusk2OT3  = 1;//set MINUS
 //Запуск4SetOT1
 if(CheckActualCMDInv(struct_maskaOTcmd.pP4OT3cmdMaska))  rst2OT3  = 1;//res MINUS

  //Запуск1SetOT4
 if(CheckActualCMD(struct_maskaOTcmd.pP1OT4cmdMaska))  pusk1OT4  = 1;//set PLUS
 //Запуск2SetOT4
 if(CheckActualCMD(struct_maskaOTcmd.pP2OT4cmdMaska))  rst1OT4  = 1;//res PLUS
 //Запуск3SetOT4
 if(CheckActualCMDInv(struct_maskaOTcmd.pP3OT4cmdMaska))  pusk2OT4  = 1;//set MINUS
 //Запуск4SetOT4
 if(CheckActualCMDInv(struct_maskaOTcmd.pP4OT4cmdMaska))  rst2OT4  = 1;//res MINUS

 //Запуск1SetOT5
 if(CheckActualCMD(struct_maskaOTcmd.pP1OT5cmdMaska))  pusk1OT5  = 1;//set PLUS
 //Запуск2SetOT5
 if(CheckActualCMD(struct_maskaOTcmd.pP2OT5cmdMaska))  rst1OT5  = 1;//res PLUS
 //Запуск3SetOT5
 if(CheckActualCMDInv(struct_maskaOTcmd.pP3OT5cmdMaska))  pusk2OT5  = 1;//set MINUS
 //Запуск4SetOT5
 if(CheckActualCMDInv(struct_maskaOTcmd.pP4OT5cmdMaska))  rst2OT5  = 1;//res MINUS

 //Запуск1SetOT6
 if(CheckActualCMD(struct_maskaOTcmd.pP1OT6cmdMaska))  pusk1OT6  = 1;//set PLUS
 //Запуск2SetOT6
 if(CheckActualCMD(struct_maskaOTcmd.pP2OT6cmdMaska))  rst1OT6  = 1;//res PLUS
 //Запуск3SetOT6
 if(CheckActualCMDInv(struct_maskaOTcmd.pP3OT6cmdMaska))  pusk2OT6  = 1;//set MINUS
 //Запуск4SetOT6
 if(CheckActualCMDInv(struct_maskaOTcmd.pP4OT6cmdMaska))  rst2OT6  = 1;//res MINUS
 
  //Запуск1SetOT7
 if(CheckActualCMD(struct_maskaOTcmd.pP1OT7cmdMaska))  pusk1OT7  = 1;//set PLUS
 //Запуск2SetOT7
 if(CheckActualCMD(struct_maskaOTcmd.pP2OT7cmdMaska))  rst1OT7  = 1;//res PLUS
 //Запуск3SetOT7
 if(CheckActualCMDInv(struct_maskaOTcmd.pP3OT7cmdMaska))  pusk2OT7  = 1;//set MINUS
 //Запуск4SetOT7
 if(CheckActualCMDInv(struct_maskaOTcmd.pP4OT7cmdMaska))  rst2OT7  = 1;//res MINUS

  //Запуск1SetOT8
 if(CheckActualCMD(struct_maskaOTcmd.pP1OT8cmdMaska))  pusk1OT8  = 1;//set PLUS
 //Запуск2SetOT8
 if(CheckActualCMD(struct_maskaOTcmd.pP2OT8cmdMaska))  rst1OT8  = 1;//res PLUS
 //Запуск3SetOT8
 if(CheckActualCMDInv(struct_maskaOTcmd.pP3OT8cmdMaska))  pusk2OT8  = 1;//set MINUS
 //Запуск4SetOT8
 if(CheckActualCMDInv(struct_maskaOTcmd.pP4OT8cmdMaska))  rst2OT8  = 1;//res MINUS

}//PuskAPV_UROV_OFWorking()

void DiskretRegWorking() @ "Fast_function"
{
//работа дискр регистратора
 int tmpOffsetT = offsetTimersPRM1;//смещение на таймерный индекс PRM1
 LSIGNAL_TIMER(TIMERDIS_PRM1) = 0;//таймер ДИС
 //запускающий сигнал для миним таймер DIS
 LSIGNAL_TIMER(TIMER_MINDIS_PRM1) = 0;//миним таймер DIS
 int isDISbusy = getTimerBUSY(tmpOffsetT+TIMERDIS_PRM1);//есть активность DIS

 if(MakeRDIScmdPusk()){//проверить РегистрацияДИС на запускbig EL
   if(isDISbusy);//есть активность DIS
   else {
          //запускающий сигнал для миним таймер DIS
          LSIGNAL_TIMER(TIMER_MINDIS_PRM1) = 1;//миним таймер DIS
          StartDiscretReg();//процедура старта Рег ДИС
         }
   //запускающий сигнал для таймера num
   LSIGNAL_TIMER(TIMERDIS_PRM1) = 1;//запустить таймер ДИС
 }//if(MakeRDIScmdActual())
   else {
   //нет активности DIS
    memcpy(act_oldDIS, pActualCMD, 4*DQUADRO);//запомнить текущие
   }
   int activityDISact = isActivityDIS();//проверка таймерной активности ДИС
   //EL TRG down front
   int activityDIStrg = (activityDISact^activityDISold)&activityDISold;
   activityDISold = activityDISact;
   LSIGNAL_TIMER(TIMER_SEAM_PRM1) = activityDIStrg;//таймер сшивки SEAM
   int activitySEAMact = FLOG_TIMER(TIMER_SEAM_PRM1);//таймер сшивки SEAM
   //EL TRG down front
   int activitySEAMtrg = (activitySEAMact^activitySEAMold)&activitySEAMold;
   activitySEAMold = activitySEAMact;
   int activitySEAMstop = (activityDISact^1) & activitySEAMtrg;
   if(registrator_dis.title_dis.len_dis>(SIZE_DIS-2)) activitySEAMstop = 1;//принуд стоп
//таймер формирователь со сбросом - по восх фронту
   FLOG_TIMERRES(TIMERDIS_PRM1, activitySEAMstop);
//таймер формирователь по восх фронту
   FLOG_TIMER(TIMER_MINDIS_PRM1);//миним таймер DIS

   if(getTimerBUSY(tmpOffsetT+TIMERDIS_PRM1)){//bazisTimerMem[tmpOffsetT+TIMERDIS_PRM1].BUSY){//есть активность DIS
     //сравнить текущие и старые
     if(memcmp(oldDIS, pActualCMD, 4*DQUADRO)){
      //есть различия
      registrator_dis.bodyDIS[registrator_dis.title_dis.len_dis].reltime =
             //относит время
             getTimerCrr(tmpOffsetT+TIMERDIS_PRM1);
             //bazisTimerMem[tmpOffsetT+TIMERDIS_PRM1].crrCNT;
      memcpy(registrator_dis.bodyDIS[registrator_dis.title_dis.len_dis].pActualCMD, 
                pActualCMD, 4*DQUADRO);//копировать текущие
      registrator_dis.title_dis.len_dis++;//размер массив ДИС
     }//if(memcmp(oldDIS, pActualCMD, 4*DQUADRO))
     memcpy(oldDIS, pActualCMD, 4*DQUADRO);//запомнить текущие
   }//if(isDISbusy)

}//DiskretRegWorking()

int isActivityDIS() @ "Fast_function"
{
//проверка активности ДИС
  int tmp = 0;
  while (cnfCOMPONENT[tmp].componentEnable)
  {
    if(cnfCOMPONENT[tmp].isDISactiv(tmp)) return 1;
    tmp++;
  }//while
  return 0;
}//isActivityDIS()

void StartDiscretReg() @ "Fast_function"
{
//процедура старта Рег ДИС
 registrator_dis.title_dis.len_dis=0;//длина масс ДИС
 memcpy(registrator_dis.title_dis.oldDIS, act_oldDIS, 4*DQUADRO);//перекопировать текущие
 memset(oldDIS, 0, 4*DQUADRO);//обнулить

 registrator_dis.title_dis.title_year = 1;
 registrator_dis.title_dis.title_mon  = 1;
 registrator_dis.title_dis.title_date = 1;
 registrator_dis.title_dis.title_hour = 1;
 registrator_dis.title_dis.title_min  = 1;
 registrator_dis.title_dis.title_sec  = 1;

}//StartDiscretReg()

int MakeRDIScmdPusk()  @ "Fast_function"
{
//проверить РегистрацияДИС на запуск
  UNS_32 tmpM[DQUADRO];
  UNS_32 tmpI=0;
  for(int i=0; i<DQUADRO; i++) 
          pRDIScmdActual[i]=pRDIScmdMaska[i]&pActualCMD[i];//РегистрацияДИС AND Текущие
  //Большой EL
  for(int i=0; i<DQUADRO; i++) 
          tmpM[i]=(pRDIScmdActual[i]^pRDIScmdOld[i])&pRDIScmdActual[i];
  for(int i=0; i<DQUADRO; i++) 
          pRDIScmdOld[i]=pRDIScmdActual[i];

  for(int i=0; i<DQUADRO; i++) 
          tmpI|=tmpM[i];
  return tmpI;
}//MakeRDIScmdPusk
/*
int MakeAPVcmdPusk() @ "Fast_function"
{
//проверить APV на запуск
  UNS_32 tmpM[DQUADRO];
  UNS_32 tmpI=0;
  for(int i=0; i<DQUADRO; i++) 
          pAPVcmdActual[i]=pAPVcmdMaska[i]&pActualCMD[i];//РегистрацияДИС AND Текущие
  //Большой EL инверсный
  for(int i=0; i<DQUADRO; i++) 
          tmpM[i]=(pAPVcmdActual[i]^pAPVcmdOld[i])&pAPVcmdOld[i];
  for(int i=0; i<DQUADRO; i++) 
          pAPVcmdOld[i]=pAPVcmdActual[i];

  for(int i=0; i<DQUADRO; i++) 
          tmpI|=tmpM[i];
  return tmpI;
}//MakeAPVcmdPusk

int MakeUROVcmdPusk() @ "Fast_function"
{
//проверить UROV на запуск
  UNS_32 tmpM[DQUADRO];
  UNS_32 tmpI=0;
  for(int i=0; i<DQUADRO; i++) 
          pUROVcmdActual[i]=pUROVcmdMaska[i]&pActualCMD[i];//РегистрацияДИС AND Текущие
  //Большой EL
  for(int i=0; i<DQUADRO; i++) 
          tmpM[i]=(pUROVcmdActual[i]^pUROVcmdOld[i])&pUROVcmdActual[i];
  for(int i=0; i<DQUADRO; i++) 
          pUROVcmdOld[i]=pUROVcmdActual[i];

  for(int i=0; i<DQUADRO; i++) 
          tmpI|=tmpM[i];
  return tmpI;
}//MakeUROVcmdPusk
*/
