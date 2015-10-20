/*

#include <vcl.h>
#include <strstrea.h>
#include <math.h>
#include <mem.h>
#include <fstream.h>
#include <strstrea.h>
#include <iomanip.h>
#pragma hdrstop

#include "vmenuDis.h"
*/

#include <stdio.h>
#include <string.h>

#include "bazisdef.h"
#include "psuperVisor\supermanager.h"
#include "virtualMenu\systemmenudef.h"
#include "component\componentdef.h"
#include "virtualMenu\rangmanagerdef.h"

#include "logictimers\logictimersfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\rangmanagerfnc.h"
#include "virtualMenu\wideLogManagerfnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"

#include "SettingIci\SettingIci.h"

#include "virtualMenu\viewMenuCnf.h"
#include "psuperVisor\psupervisor.h"

#include "toSpeedOptim.h"

extern MaskaOTAPVUROVOFcmd struct_maskaOTAPVUROVOFcmd;//маски для 16 опред функций UROV APV OT
extern MaskaOTcmd struct_maskaOTcmd;

extern UNS_32 pAPVcmdMaska[];//определение ЗапускАПВ 
extern UNS_32 pUROVcmdMaska[];//определение ЗапускУРОВ 


extern UNS_32 pRDIScmdMaska[];//РегистрацияДИС
extern COMPONENT_OBJ  cnfCOMPONENT[];//конфигурация

//массив ранжирования
/*
 Структура массива ранжирования
DV1   ... DV_TOTAL
RELE1 ... RELE_TOTAL
CDI1  ... CDI_TOTAL
*/
UNS_32 ArrayRANGIR[MAX_MNGRANG+1];//плюс CRC для EEPROM

//массив имен и статуса ранжирования плюс имена расширенной логики
IONAMESTATUS_RANGIR  nameStatusRANGIR[SIZE_RANGIRCMD+SIZE_RANGIRCMD+3];
//широкий ком массив плюс расшир логики
int   WideCmdBuffer[SIZE_RANGIRCMD+SIZE_RANGIRCMD+3];

//широкий ком массив RT
int   WideCmdRTBuffer[SIZE_RANGIRCMD+3];
//широкий ком массив RT INTERFACE
int   WideCmdINTERFACE_RTBuffer[SIZE_RANGIRCMD+3];

UNS_32 pActualCMD[2*DQUADRO];//текущие плюс расшир логика

UNS_32 pActualCMD_INTERFACE[DQUADRO];//текущие INTERFACE

/**********************************************
МЕНЕДЖЕР РАНЖИРОВАНИЯ
Удалить команды из Quadro
offsetRangMng - смещение команд
cntRangMng - к-во команд
**********************************************/
void MngRangDeleteQuadroRANGIR(UNS_32 *pQuadro, short offsetRangMng, short cntRangMng)
{
//удалить команды
  TranslateQuadroToWideCmd(pQuadro);//Превратить Quadro в широкий ком массив
  //копировать широкий ком массив в тень
  memcpy((void*)getShadowBuf(), WideCmdBuffer, 4*SIZE_RANGIRCMD);
//копировать из тени Begin
  if(offsetRangMng>0)
    memcpy(WideCmdBuffer, (void*)getShadowBuf(), 4*offsetRangMng);
//копировать из тени End
  memcpy(&(WideCmdBuffer[offsetRangMng]),
         &(((char *)getShadowBuf())[4*offsetRangMng+4*cntRangMng]),
         (4*SIZE_RANGIRCMD-4*offsetRangMng-4*cntRangMng));
  //обнулить широкий ком буфер
  memset(&(WideCmdBuffer[SIZE_RANGIRCMD-cntRangMng]), 0, 4*cntRangMng);
  CompressorToQuadro(WideCmdBuffer, pQuadro);//КОМПРЕССОР МАССИВА

}//MngRangDeleteQuadroRANGIR(short offsetRangMng, short cntRangMng)

/**********************************************
МЕНЕДЖЕР РАНЖИРОВАНИЯ
Добавить команды в Quadro
cntRangMng - к-во команд
**********************************************/
void MngRangTopAddQuadroRANGIR(UNS_32 *pQuadro, short cntRangMng)
{
//добавить команды на вершину Quadro
  TranslateQuadroToWideCmd(pQuadro);//Превратить Quadro в широкий ком массив
  //копировать широкий ком массив в тень
  memcpy((void*)getShadowBuf(), WideCmdBuffer, 4*SIZE_RANGIRCMD);
  //копировать из тени
  memcpy(&(WideCmdBuffer[cntRangMng]), (void*)getShadowBuf(),
         (4*SIZE_RANGIRCMD-4*cntRangMng));
  //обнулить широкий ком буфер
  memset(WideCmdBuffer, 0, 4*cntRangMng);
  CompressorToQuadro(WideCmdBuffer, pQuadro);//КОМПРЕССОР МАССИВА
}//MngRangTopAddRANGIR(short cntRangMng)

/**********************************************
МЕНЕДЖЕР РАНЖИРОВАНИЯ
Получить адр ArrayRANGIR конкр УВВ для редактирования
**********************************************/
UNS_32 * MngRangGetPointerUVVRANGIRtoEdit(int numUVV)
{
  if(numUVV<0) return (UNS_32 *)getShadowBuf();
  
  return  &(((UNS_32 *)getShadowBuf())[
              numUVV*DQUADRO]);
}//MngRangGetPointerUVVRANGIRtoEdit(int numUVV)

/**********************************************
МЕНЕДЖЕР РАНЖИРОВАНИЯ
Подготовить ArrayRANGIR к редактированию
**********************************************/
void MngRangPrepareArrayRANGIRtoEdit(int numUVV)
{
  switch(numUVV)
  {
   case REGDIS_SM: //регистраторДИС
    //копировать в тень
    memcpy((void*)getShadowBuf(), pRDIScmdMaska, DQUADRO*4);
    return;
   case PUSKAPV_SM://определение ЗапускАПВ 
    memcpy((void*)getShadowBuf(), pAPVcmdMaska, DQUADRO*4);
    return;
   case PUSKUROV_SM://определение ЗапускУРОВ
    memcpy((void*)getShadowBuf(), pUROVcmdMaska, DQUADRO*4);
    return;
/*
   case PUSK1OF_SM://определение Запуск1ОФ
    memcpy((void*)getShadowBuf(), pP1OFcmdMaska, DQUADRO*4);
    return;
   case PUSK2OF_SM://определение Запуск2ОФ
    memcpy((void*)getShadowBuf(), pP2OFcmdMaska, DQUADRO*4);
    return;
   case PUSK3OF_SM://определение Запуск3ОФ
    memcpy((void*)getShadowBuf(), pP3OFcmdMaska, DQUADRO*4);
    return;
*/
  }//switch
  //копировать в тень
  memcpy((void*)getShadowBuf(), ArrayRANGIR, MAX_MNGRANG*4);
}//

/**********************************************
МЕНЕДЖЕР РАНЖИРОВАНИЯ
Закончить редактировать ArrayRANGIR
**********************************************/
void MngRangEndingEditArrayRANGIR(int numUVV)
{
  switch(numUVV)
  {
   case REGDIS_SM: //регистраторДИС
    //копировать из тени
    memcpy(pRDIScmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return;
   case PUSKAPV_SM://определение ЗапускАПВ 
    memcpy(pAPVcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return;
   case PUSKUROV_SM://определение ЗапускУРОВ
    memcpy(pUROVcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return;
/*
   case PUSK1OF_SM://определение Запуск1ОФ
    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return;
   case PUSK2OF_SM://определение Запуск2ОФ
    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return;
   case PUSK3OF_SM://определение Запуск3ОФ
    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return;
*/
  }//switch

  //копировать из тени
  memcpy(ArrayRANGIR, (void*)getShadowBuf(), MAX_MNGRANG*4);
}//

/**********************************************
МЕНЕДЖЕР РАНЖИРОВАНИЯ
Удалить команды из nameStatus
offsetRangMng - смещение команд
cntRangMng - к-во команд
**********************************************/
void MngRangDeleteNameStatusRANGIR(short offsetRangMng, short cntRangMng)
{
//удалить команды
  //копировать в тень
  memcpy((void*)getShadowBuf(), nameStatusRANGIR, sizeof(IONAMESTATUS_RANGIR)*SIZE_RANGIRCMD);
//копировать из тени Begin
  if(offsetRangMng>0)
    memcpy(nameStatusRANGIR, (void*)getShadowBuf(), sizeof(IONAMESTATUS_RANGIR)*offsetRangMng);
//копировать из тени End
  memcpy(&(nameStatusRANGIR[offsetRangMng]),
         &(((IONAMESTATUS_RANGIR *)getShadowBuf())[offsetRangMng+cntRangMng]),
         sizeof(IONAMESTATUS_RANGIR)*(SIZE_RANGIRCMD-offsetRangMng-cntRangMng));
}//MngRangDeleteNameStatusRANGIR(short offsetRangMng, short cntRangMng)

/**********************************************
МЕНЕДЖЕР РАНЖИРОВАНИЯ РЛ
Удалить команды из nameStatus
offsetRangMng - смещение команд
cntRangMng - к-во команд
**********************************************/
void MngRangDeleteNameStatusRANGIR_WL(short offsetRangMng, short cntRangMng)
{
//удалить команды
  //копировать в тень
  memcpy((void*)getShadowBuf(), &(nameStatusRANGIR[SIZE_RANGIRCMD]), sizeof(IONAMESTATUS_RANGIR)*SIZE_RANGIRCMD);
//копировать из тени Begin
  if(offsetRangMng>0)
    memcpy(&(nameStatusRANGIR[SIZE_RANGIRCMD]), (void*)getShadowBuf(), sizeof(IONAMESTATUS_RANGIR)*offsetRangMng);
//копировать из тени End
  memcpy(&(nameStatusRANGIR[offsetRangMng +SIZE_RANGIRCMD]),
         &(((IONAMESTATUS_RANGIR *)getShadowBuf())[offsetRangMng+cntRangMng]),
         sizeof(IONAMESTATUS_RANGIR)*(SIZE_RANGIRCMD-offsetRangMng-cntRangMng));
}//MngRangDeleteNameStatusRANGIR_WL(short offsetRangMng, short cntRangMng)

/**********************************************
МЕНЕДЖЕР РАНЖИРОВАНИЯ
Добавить имена команд
cntRangMng - к-во команд
**********************************************/
void MngRangTopAddNameStatusRANGIR(short cntRangMng, void *ionsComp)
{
//добавить команды на вершину mngRang
  //копировать в тень
  memcpy((void*)getShadowBuf(), nameStatusRANGIR, sizeof(IONAMESTATUS_RANGIR)*SIZE_RANGIRCMD);
  //копировать из тени
  memcpy(&(nameStatusRANGIR[cntRangMng]), (void*)getShadowBuf(),
         sizeof(IONAMESTATUS_RANGIR)*(SIZE_RANGIRCMD-cntRangMng));
  //копировать
  for(short i=0; i<cntRangMng; i++)
  {
    //копировать статус
    nameStatusRANGIR[i].statusIO = ((IONAMESTATUS_COMPONENT *)ionsComp)[i].statusIO;
    //ограничить длину имени команды
    if(strlen(((IONAMESTATUS_COMPONENT *)ionsComp)[i].nameIO)>SIZE_NAMEIOCOMMAND)
                ((IONAMESTATUS_COMPONENT *)ionsComp)[i].nameIO[SIZE_NAMEIOCOMMAND-2] = 0;
    //копировать имя команды
    strcpy(nameStatusRANGIR[i].nameIORang, ((IONAMESTATUS_COMPONENT *)ionsComp)[i].nameIO);
  }//for
}//MngRangTopAddNameStatusRANGIR(short cntRangMng, void *ionsComp)

/**********************************************
МЕНЕДЖЕР РАНЖИРОВАНИЯ
Добавить имена команд РЛ
cntRangMng - к-во команд
**********************************************/
void MngRangTopAddNameStatusRANGIR_WL(short cntRangMng, void *ionsComp)
{
//добавить имена команд на вершину
  //копировать в тень
  memcpy((void*)getShadowBuf(), &(nameStatusRANGIR[SIZE_RANGIRCMD]), sizeof(IONAMESTATUS_RANGIR)*SIZE_RANGIRCMD);
  //копировать из тени
  memcpy(&(nameStatusRANGIR[cntRangMng +SIZE_RANGIRCMD]), (void*)getShadowBuf(),
         sizeof(IONAMESTATUS_RANGIR)*(SIZE_RANGIRCMD-cntRangMng));
  //копировать
  for(short i=0; i<cntRangMng; i++)
  {
    nameStatusRANGIR[i +SIZE_RANGIRCMD].statusIO = ((IONAMESTATUS_COMPONENT *)ionsComp)[i].statusIO;
    //добавить префикс
    strcpy(nameStatusRANGIR[i +SIZE_RANGIRCMD].nameIORang, "РЛ:");
    strcat(nameStatusRANGIR[i +SIZE_RANGIRCMD].nameIORang, ((IONAMESTATUS_COMPONENT *)ionsComp)[i].nameIO);
  }//for
}//MngRangTopAddNameStatusRANGIR_WL(short cntRangMng, void *ionsComp)

short SetCmdToUVV(short kodC, short numClon, short numIO, short numUVV)
{
//отранж команду numIO компонента kodC с номером клона numClon на numUVV
  short idxClon = SearchCnfClonToComponent(kodC, numClon);
  if(idxClon<0)return 1;//клон не найден
  int cntIO = cnfCOMPONENT[idxClon].cntIOCmd;    //к-во IO команд
  if(numIO<0) return 1;//команда меньше 0
  if(numIO>=cntIO) return 1;//команда за диапазоном
  short idxCmd = getOffsetIOCmdCnf(idxClon) + numIO;//индекс команды

  short conflict = SetUVVToClon(idxCmd, numUVV);
  SaveCRCrang();//сохранить CRC ранжир
  PrepareBOBV();//подготовить Блок ОТКЛ, Блок ВКЛ
  return conflict;
}//SetCmdToUVV(short kodC, short numClon, short numIO, short numUVV)
/*
void ClrCmdToClon(short kodC, short numClon, short numIO, short numUVV)
{
//Убрать команду numIO компонента kodC с номером клона numClon на numUVV
  short idxClon = SearchCnfClonToComponent(kodC, numClon);
  if(idxClon<0)return;//клон не найден
  short idxCmd = getOffsetIOCmdCnf(idxClon) + numIO;//индекс команды

  ClrUVVToClon(idxCmd, numUVV);
}//ClrCmdToClon(short kodC, short numClon, short numIO, short numUVV)
*/

/*
void ClrUVVToClon(int idxCmd, int numUVV)
{
  MngRangPrepareArrayRANGIRtoEdit(numUVV);//Подготовить ArrayRANGIR к редактированию

  NumBitClearingQuadro(idxCmd,
                       MngRangGetPointerUVVRANGIRtoEdit(numUVV)
                      ); //сброс бита по его индексу

  MngRangEndingEditArrayRANGIR(numUVV);//Закончить редактировать ArrayRANGIR
}//ClrUVVToClon(idxCmd, numUVV)
*/

short SetUVVToClon(int idxCmd, int numUVV)
{
//  MngRangPrepareArrayRANGIRtoEdit(numUVV);//Подготовить ArrayRANGIR к редактированию

  NumBitSettingQuadro(idxCmd,
                      MngRangGetPointerUVVRANGIRtoRead(numUVV)
                     ); //установка бита по его индексу
  short isConflict = ApplyDVMaskToRead(numUVV);//наложить маску на DV

//  MngRangEndingEditArrayRANGIR(numUVV);//Закончить редактировать ArrayRANGIR
  return isConflict;//успешность операции размещения
}//SetUVVToClon(idxCmd, numUVV)

void ClearArrayRANGIR()
{
//очистить все ранжирование
  memset(ArrayRANGIR, 0, MAX_MNGRANG*4);
}//ClearArrayRANGIR()

void SaveCRCrang()
{
//сохранить CRC ранжир
  ArrayRANGIR[MAX_MNGRANG] = setCRCMassiv((int *)ArrayRANGIR, MAX_MNGRANG); //CRC для ранж
}//SaveCRCrang()

int getCRCrang()
{
//получить CRC ранж
  return ArrayRANGIR[MAX_MNGRANG]; //CRC для ранж
}//getCRCrang()

//extern MaskaOTAPVUROVOFcmd struct_maskaOTAPVUROVOFcmd;//маски для 16 опред функций UROV APV OT

/**********************************************
МЕНЕДЖЕР РАНЖИРОВАНИЯ
Получить адр ArrayRANGIR конкр УВВ для чтения
**********************************************/
UNS_32 * MngRangGetPointerUVVRANGIRtoRead(int numUVV)
{
  switch(numUVV)
  {
   case REGDIS_SM: //регистраторДИС
//    pRDIScmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return pRDIScmdMaska;
   case PUSKAPV_SM://определение ЗапускАПВ 
//    memcpy(pAPVcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return pAPVcmdMaska;
   case PUSKUROV_SM://определение ЗапускУРОВ
//    memcpy(pUROVcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return pUROVcmdMaska;

   case PUSK1OF_SM://определение Запуск1ОФ
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OFcmdMaska;
   case PUSK2OF_SM://определение Запуск2ОФ
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OFcmdMaska;
   case PUSK3OF_SM://определение Запуск3ОФ
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OFcmdMaska;

   case PUSK1OF2_SM://определение Запуск1ОФ
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF2cmdMaska;
   case PUSK2OF2_SM://определение Запуск2ОФ
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF2cmdMaska;
   case PUSK3OF2_SM://определение Запуск3ОФ
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF2cmdMaska;

   case PUSK1OF3_SM://определение Запуск1ОФ
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF3cmdMaska;
   case PUSK2OF3_SM://определение Запуск2ОФ
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF3cmdMaska;
   case PUSK3OF3_SM://определение Запуск3ОФ
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF3cmdMaska;

   case PUSK1OF4_SM://определение Запуск1ОФ
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF4cmdMaska;
   case PUSK2OF4_SM://определение Запуск2ОФ
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF4cmdMaska;
   case PUSK3OF4_SM://определение Запуск3ОФ
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF4cmdMaska;

   case PUSK1OF5_SM://определение Запуск1ОФ
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF5cmdMaska;
   case PUSK2OF5_SM://определение Запуск2ОФ
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF5cmdMaska;
   case PUSK3OF5_SM://определение Запуск3ОФ
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF5cmdMaska;

   case PUSK1OF6_SM://определение Запуск1ОФ
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF6cmdMaska;
   case PUSK2OF6_SM://определение Запуск2ОФ
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF6cmdMaska;
   case PUSK3OF6_SM://определение Запуск3ОФ
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF6cmdMaska;

   case PUSK1OF7_SM://определение Запуск1ОФ
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF7cmdMaska;
   case PUSK2OF7_SM://определение Запуск2ОФ
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF7cmdMaska;
   case PUSK3OF7_SM://определение Запуск3ОФ
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF7cmdMaska;

   case PUSK1OF8_SM://определение Запуск1ОФ
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF8cmdMaska;
   case PUSK2OF8_SM://определение Запуск2ОФ
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF8cmdMaska;
   case PUSK3OF8_SM://определение Запуск3ОФ
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF8cmdMaska;

   case PUSK1OF9_SM://определение Запуск1ОФ
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF9cmdMaska;
   case PUSK2OF9_SM://определение Запуск2ОФ
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF9cmdMaska;
   case PUSK3OF9_SM://определение Запуск3ОФ
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF9cmdMaska;

   case PUSK1OF10_SM://определение Запуск1ОФ
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF10cmdMaska;
   case PUSK2OF10_SM://определение Запуск2ОФ
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF10cmdMaska;
   case PUSK3OF10_SM://определение Запуск3ОФ
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF10cmdMaska;

   case PUSK1OF11_SM://определение Запуск1ОФ
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF11cmdMaska;
   case PUSK2OF11_SM://определение Запуск2ОФ
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF11cmdMaska;
   case PUSK3OF11_SM://определение Запуск3ОФ
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF11cmdMaska;

   case PUSK1OF12_SM://определение Запуск1ОФ
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF12cmdMaska;
   case PUSK2OF12_SM://определение Запуск2ОФ
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF12cmdMaska;
   case PUSK3OF12_SM://определение Запуск3ОФ
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF12cmdMaska;

   case PUSK1OF13_SM://определение Запуск1ОФ
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF13cmdMaska;
   case PUSK2OF13_SM://определение Запуск2ОФ
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF13cmdMaska;
   case PUSK3OF13_SM://определение Запуск3ОФ
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF13cmdMaska;

   case PUSK1OF14_SM://определение Запуск1ОФ
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF14cmdMaska;
   case PUSK2OF14_SM://определение Запуск2ОФ
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF14cmdMaska;
   case PUSK3OF14_SM://определение Запуск3ОФ
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF14cmdMaska;

   case PUSK1OF15_SM://определение Запуск1ОФ
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF15cmdMaska;
   case PUSK2OF15_SM://определение Запуск2ОФ
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF15cmdMaska;
   case PUSK3OF15_SM://определение Запуск3ОФ
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF15cmdMaska;

   case PUSK1OF16_SM://определение Запуск1ОФ
//    memcpy(pP1OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP1OF16cmdMaska;
   case PUSK2OF16_SM://определение Запуск2ОФ
//    memcpy(pP2OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP2OF16cmdMaska;
   case PUSK3OF16_SM://определение Запуск3ОФ
//    memcpy(pP3OFcmdMaska, (void*)getShadowBuf(), DQUADRO*4);
    return struct_maskaOTAPVUROVOFcmd.pP3OF16cmdMaska;

   case PUSK1OT1_SM://определение Запуск1ОT1
    return struct_maskaOTcmd.pP1OT1cmdMaska;
   case PUSK2OT1_SM://определение Запуск2ОT1
    return struct_maskaOTcmd.pP2OT1cmdMaska;
   case PUSK3OT1_SM://определение Запуск2ОT1
    return struct_maskaOTcmd.pP3OT1cmdMaska;
   case PUSK4OT1_SM://определение Запуск2ОT1
    return struct_maskaOTcmd.pP4OT1cmdMaska;

   case PUSK1OT2_SM://определение Запуск1ОT2
    return struct_maskaOTcmd.pP1OT2cmdMaska;
   case PUSK2OT2_SM://определение Запуск2ОT2
    return struct_maskaOTcmd.pP2OT2cmdMaska;
   case PUSK3OT2_SM://определение Запуск2ОT2
    return struct_maskaOTcmd.pP3OT2cmdMaska;
   case PUSK4OT2_SM://определение Запуск2ОT2
    return struct_maskaOTcmd.pP4OT2cmdMaska;

   case PUSK1OT3_SM://определение Запуск1ОT3
    return struct_maskaOTcmd.pP1OT3cmdMaska;
   case PUSK2OT3_SM://определение Запуск2ОT3
    return struct_maskaOTcmd.pP2OT3cmdMaska;
   case PUSK3OT3_SM://определение Запуск2ОT3
    return struct_maskaOTcmd.pP3OT3cmdMaska;
   case PUSK4OT3_SM://определение Запуск2ОT3
    return struct_maskaOTcmd.pP4OT3cmdMaska;

   case PUSK1OT4_SM://определение Запуск1ОT4
    return struct_maskaOTcmd.pP1OT4cmdMaska;
   case PUSK2OT4_SM://определение Запуск2ОT4
    return struct_maskaOTcmd.pP2OT4cmdMaska;
   case PUSK3OT4_SM://определение Запуск2ОT4
    return struct_maskaOTcmd.pP3OT4cmdMaska;
   case PUSK4OT4_SM://определение Запуск2ОT4
    return struct_maskaOTcmd.pP4OT4cmdMaska;

   case PUSK1OT5_SM://определение Запуск1ОT5
    return struct_maskaOTcmd.pP1OT5cmdMaska;
   case PUSK2OT5_SM://определение Запуск2ОT5
    return struct_maskaOTcmd.pP2OT5cmdMaska;
   case PUSK3OT5_SM://определение Запуск2ОT5
    return struct_maskaOTcmd.pP3OT5cmdMaska;
   case PUSK4OT5_SM://определение Запуск2ОT5
    return struct_maskaOTcmd.pP4OT5cmdMaska;

   case PUSK1OT6_SM://определение Запуск1ОT6
    return struct_maskaOTcmd.pP1OT6cmdMaska;
   case PUSK2OT6_SM://определение Запуск2ОT6
    return struct_maskaOTcmd.pP2OT6cmdMaska;
   case PUSK3OT6_SM://определение Запуск2ОT6
    return struct_maskaOTcmd.pP3OT6cmdMaska;
   case PUSK4OT6_SM://определение Запуск2ОT6
    return struct_maskaOTcmd.pP4OT6cmdMaska;

   case PUSK1OT7_SM://определение Запуск1ОT7
    return struct_maskaOTcmd.pP1OT7cmdMaska;
   case PUSK2OT7_SM://определение Запуск2ОT7
    return struct_maskaOTcmd.pP2OT7cmdMaska;
   case PUSK3OT7_SM://определение Запуск2ОT7
    return struct_maskaOTcmd.pP3OT7cmdMaska;
   case PUSK4OT7_SM://определение Запуск2ОT7
    return struct_maskaOTcmd.pP4OT7cmdMaska;

   case PUSK1OT8_SM://определение Запуск1ОT8
    return struct_maskaOTcmd.pP1OT8cmdMaska;
   case PUSK2OT8_SM://определение Запуск2ОT8
    return struct_maskaOTcmd.pP2OT8cmdMaska;
   case PUSK3OT8_SM://определение Запуск2ОT8
    return struct_maskaOTcmd.pP3OT8cmdMaska;
   case PUSK4OT8_SM://определение Запуск2ОT8
    return struct_maskaOTcmd.pP4OT8cmdMaska;

  }//switch

  return  &(((UNS_32 *)ArrayRANGIR)[numUVV*DQUADRO]);
}//MngRangGetPointerUVVRANGIRtoRead(int numUVV)

int GetCmdUVVFromClon(short kodC, short numClon, short numIO, short numUVV)
{
//Проверить команду numIO компонента kodC с номером клона numClon на numUVV
  short idxClon = SearchCnfClonToComponent(kodC, numClon);
  if(idxClon<0)return -1;//клон не найден
  short idxCmd = getOffsetIOCmdCnf(idxClon) + numIO;//индекс команды

  return  NumBitCheckQuadro(idxCmd,
                               MngRangGetPointerUVVRANGIRtoRead(numUVV)
                              ); //установка бита по его индексу
}//SetUVVToClon(idxCmd, numUVV)

void CopyEEPROMtoRANGIR()
{
//копировать данные из EEPROM в ранжир
extern char  tmp_eeprom[];//MAX_MNGUSTAVKI*4блока *4байта
 memcpy(ArrayRANGIR, tmp_eeprom, 4*(MAX_MNGRANG+1));//для ранжир и CRC
}//CopyMngUstavki(int numBlok)

/*
char ChkUVVToClon(int idxCmd, int numUVV)
{
  MngRangPrepareArrayRANGIRtoEdit(numUVV);//Подготовить ArrayRANGIR к редактированию

  char tmp = NumBitCheckQuadro(idxCmd,
                               MngRangGetPointerUVVRANGIRtoEdit(numUVV)
                              ); //установка бита по его индексу

  MngRangEndingEditArrayRANGIR(numUVV);//Закончить редактировать ArrayRANGIR
  return tmp;
}//ChkUVVToClon(short idxCmd, short numUVV)
*/
/*
char ChkCmdToClon(short kodC, short numClon, short numIO, short numUVV)
{
//Проверить команду numIO компонента kodC с номером клона numClon на numUVV
  short idxClon = SearchCnfClonToComponent(kodC, numClon);
  if(idxClon<0)return -1;//клон не найден
  short idxCmd = getOffsetIOCmdCnf(idxClon) + numIO;//индекс команды

  return ChkUVVToClon(idxCmd, numUVV);
}//ClrCmdToClon(short kodC, short numClon, short numIO, short numUVV)
*/
