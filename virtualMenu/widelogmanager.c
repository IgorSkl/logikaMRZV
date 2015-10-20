/*
#include <vcl.h>
#include <strstrea.h>
#include <math.h>
#include <mem.h>
#include <fstream.h>
#include <strstrea.h>
#include <iomanip.h>
#pragma hdrstop
*/
#include <stdio.h>
#include <string.h>

#include "psuperVisor\supermanager.h"

#include "bazisdef.h"
#include "component\componentdef.h"
#include "virtualMenu\widelogmanagerdef.h"
#include "virtualMenu\systemmenudef.h"

#include "virtualMenu\rangmanagerfnc.h"
#include "virtualMenu\widelogmanagerfnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"

#include "psuperVisor\psupervisor.h"
#include "virtualMenu\viewMenuCnf.h"

#include "toSpeedOptim.h"

extern UNS_32 pActualCMD[];//текущие плюс расшир логика
extern UNS_32 ArrayRANGIR[];

//массив расширенной логики
/*
 Структура массива расширенной логики
LE1
DblOctatPRM
DblOctatMINUS
DblOctatPLUS

LE2
DblOctatPRM
DblOctatMINUS
DblOctatPLUS
..........
*/
//первые DQUADRO для компонентов конфиг, а вторые DQUADRO для компонентов РЛ
UNS_32 ArrayWIDELOG[3*2*DQUADRO*LE_TOTAL];
//тип лог элемента
//0-ОТКЛ
//1-ИЛИ
//2-И
//3-ИСКЛ ИЛИ
int    TypLE[LE_TOTAL];
UNS_32 PlusCircleCmd[2*DQUADRO];//командный массив плюсовых команд LE
UNS_32 InputLECmd[2*DQUADRO];//входной командный массив LE
UNS_32 EXEOutputCmd[2*DQUADRO];//выходной командный массив компонентов
UNS_32 *WideLogActual;//текущий командный массив расшир логики

/**********************************************
МЕНЕДЖЕР РАСШИРЕННОЙ ЛОГИКИ
Подготовить ArrayWIDELOG к редактированию
**********************************************/
void MngWideLogPrepareArrayWIDELOGtoEdit()
{
  //копировать в тень
  memcpy((void*)getShadowBuf(), ArrayWIDELOG, sizeof(ArrayWIDELOG));
}//MngWideLogPrepareArrayWIDELOGtoEdit()

/**********************************************
МЕНЕДЖЕР РАСШИРЕННОЙ ЛОГИКИ
Получить адр ArrayWIDELOG заданной LE для редактирования прямых
**********************************************/
UNS_32 * MngWLGetLEWLtoEdit_PRM(int numLE)
{
  return  &(((UNS_32 *)getShadowBuf())[2*DQUADRO*(numLE*3 +0)]);
}//MngWLGetLEWLtoEdit_PRM(int numLE)

/**********************************************
МЕНЕДЖЕР РАСШИРЕННОЙ ЛОГИКИ
Закончить редактировать ArrayWIDELOG
**********************************************/
void MngWLEndingEditArrayWIDELOG()
{
  //копировать из тени
  memcpy(ArrayWIDELOG, (void*)getShadowBuf(), sizeof(ArrayWIDELOG));
}//

short SetCmdToLE(short kodC, short numClon, short numIO, short numLE, short typesCmd)
{
//отранж команду numIO компонента kodC с номером клона numClon на numLE со знаком typesCmd
  short idxClon = SearchCnfClonToComponent(kodC, numClon);
  if(idxClon<0)return 1;//клон не найден
  short idxCmd = getOffsetIOCmdCnf(idxClon) + numIO;//индекс команды

  MngWideLogPrepareArrayWIDELOGtoEdit();//Подготовить ArrayWIDELOG к редактированию

  short isConflict = SetLEToClon(idxCmd, numLE, typesCmd);
  MngWLEndingEditArrayWIDELOG();//Закончить редактировать ArrayWIDELOG
  return isConflict;
}//SetCmdToClonLE(short kodC, short numClon, short numIO, short numLE, short typesCmd)

short SetCmdToLE_WL(short kodC, short numClon, short numIO, short numLE, short typesCmd)
{
//отранж команду из конф РЛ numIO компонента kodC с номером клона numClon на numLE со знаком typesCmd
  short idxClon = SearchCnfClonToComponent_WL(kodC, numClon);
  if(idxClon<0)return 1;//клон не найден
  short idxCmd = getOffsetIOCmdCnf_WL(idxClon) + numIO;//индекс команды РЛ

  MngWideLogPrepareArrayWIDELOGtoEdit();//Подготовить ArrayWIDELOG к редактированию

  short isConflict = SetLEToClon(idxCmd +SIZE_RANGIRCMD, numLE, typesCmd);
  MngWLEndingEditArrayWIDELOG();//Закончить редактировать ArrayWIDELOG
  return isConflict;
}//SetCmdToLE_WL(short kodC, short numClon, short numIO, short numLE, short typesCmd)

short SetLEToClon(int idxCmd, int numLE, int typesCmd)
{
//установить команду на LE
  short isConflict = 0;//проверить маску
  UNS_32 *prm =  MngWLGetLEWLtoEdit_PRM(numLE);//массив LE
  //откл команда
  NumBitClearingQuadro(idxCmd,
                       prm
                      ); //сброс бита по его индексу
  NumBitClearingQuadro(idxCmd,
                       &(prm[DQUADRO*2])//инверс
                      ); //сброс бита по его индексу
  NumBitClearingQuadro(idxCmd,
                       &(prm[DQUADRO*2+DQUADRO*2])//плюс
                      ); //сброс бита по его индексу

  switch(typesCmd)
  {
  case typeCmd_PRM:
    NumBitSettingQuadro(idxCmd,
                        prm
                       ); //уст бита по его индексу
    break;

  case typeCmd_MINUS:
    NumBitSettingQuadro(idxCmd,
                        &(prm[DQUADRO*2])//инверс
                       ); //уст бита по его индексу
    break;

  case typeCmd_PLUS:{
    NumBitSettingQuadro(idxCmd,
                        &(prm[DQUADRO*2+DQUADRO*2])//плюс
                       ); //уст бита по его индексу
    UNS_32 *pplus = &(prm[DQUADRO*2+DQUADRO*2]);
    //наложить маски выходов других LE
    for(int i=0; i<LE_TOTAL; i++){
     if(i==numLE) continue;//текущий LE не учитывать
     UNS_32 *prmLE =  MngWLGetLEWLtoEdit_PRM(i);//массив LE
     UNS_32 *pplusLE = &(prmLE[DQUADRO*2+DQUADRO*2]);
     for(int k=0; k<DQUADRO*2; k++) {
          if(pplus[k] & pplusLE[k]) isConflict = 1;//есть конфликт
          }//for
     for(int k=0; k<DQUADRO*2; k++) pplus[k] &= ~pplusLE[k];//наложить маску LE
     }//for
      //наложить маски DV
      for(int i=0; i<DV_TOTAL; i++){
       UNS_32 *pDV = //MngRangGetPointerUVVRANGIRtoEdit(DV1_SM +i);
          &ArrayRANGIR[(DV1_SM +i)*DQUADRO];
       for(int k=0; k<DQUADRO; k++) pplus[k] &= ~pDV[k];//наложить маску DV
     }//for
    }//case
    break;
  default:
    ;
  }//switch

  return isConflict;//проверить маску 
}//SetLEToClon(int idxCmd, UNS_32 *prm, int typesCmd)

short ApplyDVMask(int numUVV)
{
//наложить маску на DV
 short isConflict = 0;
    //уйти если не ДВ
    if(!((LIGHTRANGUVV>=DV1_SM) && (LIGHTRANGUVV<(DV1_SM+DV_TOTAL)))) return 0;

//Получить адр конкр DV
     UNS_32 *pDV = MngRangGetPointerUVVRANGIRtoEdit(numUVV);

    //наложить маску
    for(int i=0; i<LE_TOTAL; i++){
     //плюсовые LE
     UNS_32 *pplusLE = &ArrayWIDELOG[2*DQUADRO*i*3 +DQUADRO*2+DQUADRO*2];
     for(int k=0; k<DQUADRO; k++) {
          if(pDV[k] & pplusLE[k]) isConflict = 1;//проверить маску 
          }//for
     for(int k=0; k<DQUADRO; k++) pDV[k] &= ~pplusLE[k];//наложить маску 
     }//for
  return isConflict;
}//ApplyDVMask(int numUVV)

short ApplyDVMaskToRead(int numUVV)
{
//наложить маску на DV
 short isConflict = 0;
    //уйти если не ДВ
//   if(!((LIGHTRANGUVV>=DV1_SM) && (LIGHTRANGUVV<(DV1_SM+DV_TOTAL)))) return 0;
   if(!((numUVV>=DV1_SM) && (numUVV<(DV1_SM+DV_TOTAL)))) return isConflict;

//Получить адр конкр DV
     UNS_32 *pDV = MngRangGetPointerUVVRANGIRtoRead(numUVV);

    //наложить маску
    for(int i=0; i<LE_TOTAL; i++){
     //плюсовые LE
     UNS_32 *pplusLE = &ArrayWIDELOG[2*DQUADRO*i*3 +DQUADRO*2+DQUADRO*2];
     for(int k=0; k<DQUADRO; k++) {
          if(pDV[k] & pplusLE[k]) isConflict = 1;//проверить маску 
          }//for
     for(int k=0; k<DQUADRO; k++) pDV[k] &= ~pplusLE[k];//наложить маску 
     }//for
  return isConflict;
}//ApplyDVMaskToRead(int numUVV)

void SetTypLE(short numLE, short typesLE)
{
//задать тип лог элемента
  TypLE[numLE] = typesLE;
}//SetTypLE(short numLE, short typesLE)

void ClearTypesLE()
{
//отключить все лог элементы
  memset(TypLE, typeLE_DIS, sizeof(TypLE));
}//ClearTypesLE()

void ClearWIDELOG()
{
//очистить всю РЛ
  memset(ArrayWIDELOG, 0, sizeof(ArrayWIDELOG));
}//ClearWIDELOG()
