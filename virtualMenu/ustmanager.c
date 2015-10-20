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

#include "psuperVisor\supermanager.h"

#include "bazisdef.h"
#include "component\componentdef.h"
#include "virtualMenu\systemmenudef.h"
#include "virtualMenu\ustmanagerdef.h"

#include "virtualMenu\ustmanagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"

#include "psuperVisor\psupervisor.h"

#include "..\bazis.h"

#include "toSpeedOptim.h"

void SaveUprPRM1(short numBit);
void SaveUprMTZ(short ibit);
void SaveUprAPV(short ibit);

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern COMPONENT_OBJ  cnfCOMPONENT_WL[];

//временный буфер для EEPROM 
char  tmp_eeprom[128*64];//MAX_MNGUSTAVKI*4блока *4байта
//4 блока уставок
int  blokUSTAVKI[4*MAX_MNGUSTAVKI+1];//плюс CRC для EEPROM
//текущие уставки
int  mngUSTAVKI[MAX_MNGUSTAVKI+3];
//текущие уставки РЛ
int  mngUSTAVKI_WL[MAX_MNGUSTAVKI_WL+3];
int  tmpUSTAVKI[100];

/**********************************************
МЕНЕДЖЕР УСТАВОК
Удалить уставки
offsetUstMng - смещение уставки
cntUstMng - к-во уставок
**********************************************/
void MngUstDeleteUSTAVKI(short offsetUstMng, short cntUstMng)
{
//удалить уставки из mngUst
  //копировать в тень
  memcpy((void*)getShadowBuf(), mngUSTAVKI, 4*MAX_MNGUSTAVKI);
//копировать из тени Begin
  if(offsetUstMng>0)
    memcpy(mngUSTAVKI, (void*)getShadowBuf(), 4*offsetUstMng);
//копировать из тени End
  memcpy(&(mngUSTAVKI[offsetUstMng]),
         &(((int *)getShadowBuf())[offsetUstMng+cntUstMng]),
         4*(MAX_MNGUSTAVKI-offsetUstMng-cntUstMng));
}//MngUstDeleteUSTAVKI(short offsetUstMng, short cntUstMng)

/**********************************************
МЕНЕДЖЕР УСТАВОК
Удалить уставки из РЛ
offsetUstMng - смещение уставки
cntUstMng - к-во уставок
**********************************************/
void MngUstDeleteUSTAVKI_WL(short offsetUstMng, short cntUstMng)
{
//удалить уставки из mngUst
  //копировать в тень
  memcpy((void*)getShadowBuf(), mngUSTAVKI_WL, 4*MAX_MNGUSTAVKI_WL);
//копировать из тени Begin
  if(offsetUstMng>0)
    memcpy(mngUSTAVKI_WL, (void*)getShadowBuf(), 4*offsetUstMng);
//копировать из тени End
  memcpy(&(mngUSTAVKI_WL[offsetUstMng]),
         &(((int *)getShadowBuf())[offsetUstMng+cntUstMng]),
         4*(MAX_MNGUSTAVKI_WL-offsetUstMng-cntUstMng));
}//MngUstDeleteUSTAVKI_WL(short offsetUstMng, short cntUstMng)

/**********************************************
МЕНЕДЖЕР УСТАВОК
Добавить уставки
cntUstMng - к-во уставок
**********************************************/
void MngUstTopAddUSTAVKI(short cntUstMng)
{
//добавить уставки на вершину mng
  //копировать в тень
  memcpy((void*)getShadowBuf(), mngUSTAVKI, 4*MAX_MNGUSTAVKI);
  //копировать из тени
  memcpy(&(mngUSTAVKI[cntUstMng]), (void*)getShadowBuf(), 4*(MAX_MNGUSTAVKI-cntUstMng));
  //копировать
  memcpy(mngUSTAVKI, tmpUSTAVKI, 4*cntUstMng);
}//MngUstTopAddUSTAVKI(short cntUstMng)

/**********************************************
МЕНЕДЖЕР УСТАВОК
Добавить уставки РЛ
cntUstMng - к-во уставок
**********************************************/
void MngUstTopAddUSTAVKI_WL(short cntUstMng)
{
//добавить уставки на вершину mng WL
  //копировать в тень
  memcpy((void*)getShadowBuf(), mngUSTAVKI_WL, 4*MAX_MNGUSTAVKI_WL);
  //копировать из тени
  memcpy(&(mngUSTAVKI_WL[cntUstMng]), (void*)getShadowBuf(), 4*(MAX_MNGUSTAVKI_WL-cntUstMng));
  //копировать
  memcpy(mngUSTAVKI_WL, tmpUSTAVKI, 4*cntUstMng);
}//MngUstTopAddUSTAVKI_WL(short cntUstMng)

void SetUPR_COMMON1()
{
  /*
//сохр управление
  short ibit = LIGHTLINEMENU;//индекс бита
  switch(cnfCOMPONENT[LIGHTCLON].kodC)
  {
  case PRM1_COMP1:
   SaveUprPRM1(ibit);//персональное сохр upr для PRM1
  break;

  case MTZ_COMP1:
   SaveUprMTZ(ibit);//персональное сохр upr для MTZ
  break;

  case APV_COMP1:
   SaveUprAPV(ibit);//персональное сохр upr для APV
  break;

//управление остальные
  default:
  {
    UNS_32 tmpU = getCurrentMngUSTAVKI();//текущая уст упр
    if(FvmenuDis->UprCheck->Checked)
    {
      NumBitSettingWord(ibit, &tmpU);//установка бита по его индексу
    }//if(FvmenuDis->UprCheck->Checked)
    else
    {
      NumBitClearingWord(ibit, &tmpU);//сброс бита по его индексу
    }
  setCurrentMngUSTAVKI(tmpU);//новая уст упр
  }//default
  }//switch

  if(LIGHTCLON>=0)
    PREPAREustCOMPONENT(LIGHTCLON);//СУПЕРВИЗОР  Подготовка уставок spv компонентов из конфиг
  else
    PREPAREustCOMPONENT_WL(LIGHTCLON);//СУПЕРВИЗОР  Подготовка уставок spv компонентов из конфиг РЛ
*/    
}//SetUPR_COMMON1()

int AssembleUstButton()
{
  /*
//собрать уставку
  int dig = 0;
  sscanf(FvmenuDis->EditEdit->Text.Trim().c_str(), "%d", &dig);

  int tmp = setCurrentMngUSTAVKI(dig);
  if(tmp<0) return tmp;//ошибка сборки
//  if((kodC==PRM1_COMP1)&&((numUst==MNGUST_PRM1_BO)||(numUst==MNGUST_PRM1_BV)))
  //      PrepareBOBVtimer();//подготовить таймера Блок ОТКЛ, Блок ВКЛ
  if(LIGHTCLON>=0)
    PREPAREustCOMPONENT(LIGHTCLON);//СУПЕРВИЗОР  Подготовка уставок spv компонентов из конфиг
  else
    PREPAREustCOMPONENT_WL(LIGHTCLON);//СУПЕРВИЗОР  Подготовка уставок spv компонентов из конфиг РЛ
*/  
  return 0;
}//AssembleUstButton()

int setCurrentMngUSTAVKI(int ust)
{
//записать текущую уставку
//codec=0-закодировать уставку
  int tmp=0;
  if(LIGHTCLON>=0)
  {
    tmp = cnfCOMPONENT[LIGHTCLON].
          codecUst(0, LIGHTMNGUBAZA+ LIGHTMNGUOFFSET, ust);
    if(tmp<0) return tmp;//ошибка
    mngUSTAVKI[getOffsetMngUSTAVKI(LIGHTMNGUOFFSET)] = tmp;//уст
  }//if
  else
  {
//если CLON<0 то это РЛ
    int tmp = cnfCOMPONENT_WL[-LIGHTCLON-1].
              codecUst(0, LIGHTMNGUBAZA+ LIGHTMNGUOFFSET, ust);
    if(tmp<0) return tmp;//ошибка
    mngUSTAVKI_WL[getOffsetMngUSTAVKI(LIGHTMNGUOFFSET)] = tmp;//уст
  }
  return tmp;//успешно
}//setCurrentMngUSTAVKI()

int setClonMngUSTAVKI(int idxC, int bazaOffset, int ust)
{
//записать заданную bazaOffset уставку ust в клон idxC
//codec=0-закодировать уставку
  int tmp=0;
  if(LIGHTCLON>=0)
  {
    tmp = cnfCOMPONENT[idxC].//LIGHTCLON].
          codecUst(0, bazaOffset, ust);
    if(tmp==ERROR_UST) return ERROR_UST;//ошибка
    
//    int tttt1 = getClonOffsetMngUSTAVKI(idxC, bazaOffset);
    mngUSTAVKI[getClonOffsetMngUSTAVKI(idxC, bazaOffset)] = tmp;//уст
  }//if
  else
  {
//если CLON<0 то это РЛ
    int tmp = cnfCOMPONENT_WL[-idxC-1].
              codecUst(0, bazaOffset, ust);
    if(tmp<0) return tmp;//ошибка
    mngUSTAVKI_WL[getClonOffsetMngUSTAVKI(idxC, bazaOffset)] = tmp;//уст
  }
  return tmp;//успешно
}//setClonMngUSTAVKI(int idxC, int bazaOffset, int ust)

int getUstOffsetMngUSTAVKI(short offset)
{
//если CLON<0 то это РЛ
//прочитать тек уставку по смещению
//codec=1-раскодировать уставку
  if(LIGHTCLON>=0)
    return cnfCOMPONENT[LIGHTCLON].
           codecUst(1, LIGHTMNGUBAZA + LIGHTMNGUOFFSET,
                    mngUSTAVKI[getOffsetMngUSTAVKI(offset)]);
//РЛ
  return cnfCOMPONENT_WL[-LIGHTCLON-1].
         codecUst(1, LIGHTMNGUBAZA + LIGHTMNGUOFFSET,
                  mngUSTAVKI_WL[getOffsetMngUSTAVKI(offset)]);
}//getOffsetMngUSTAVKI(short idx)

UNS_32 getCurrentMngUSTAVKI()
{
//прочитать текущую уставку
  return getUstOffsetMngUSTAVKI(LIGHTMNGUOFFSET);
}//getCurrentMngUSTAVKI()

short getOffsetMngUSTAVKI(short offset)
{
//прочитать тек смещение уставки
//если CLON<0 то это РЛ
  if(LIGHTCLON>=0)
    return cnfCOMPONENT[LIGHTCLON].offsetUstMng +
           LIGHTMNGUBAZA + offset;

//int tt1 = -LIGHTCLON-1;
  return cnfCOMPONENT_WL[-LIGHTCLON-1].offsetUstMng +
         LIGHTMNGUBAZA + offset;
}//getOffsetMngUSTAVKI()

short getClonOffsetMngUSTAVKI(short idxC, short offset)
{
//прочитать смещение уставки клона idxC
//если CLON<0 то это РЛ
  if(idxC>=0)
    return cnfCOMPONENT[idxC].offsetUstMng +
           //LIGHTMNGUBAZA +
           offset;

  return cnfCOMPONENT_WL[-idxC-1].offsetUstMng +
         //LIGHTMNGUBAZA +
         offset;
}//getClonOffsetMngUSTAVKI(short idxC, short offset)

short getOffsetNativMngUSTAVKI(short idxC, short offsetUpr)
{
//прочитать смещение уставки
  return cnfCOMPONENT[idxC].offsetUstMng + offsetUpr;
}//getOffsetNativMngUSTAVKI(short offset)

int getNativUstMngUSTAVKI(short idxC, short offset)
{
//прочитать уставку по индексу клона и смещению
//если CLON<0 то это РЛ
//  int ttttttt5 = cnfCOMPONENT[idxC].offsetUstMng + offset;
  if(idxC>=0)
    return  mngUSTAVKI[cnfCOMPONENT[idxC].offsetUstMng + offset];

  return  mngUSTAVKI_WL[cnfCOMPONENT_WL[-idxC-1].offsetUstMng + offset];
}//getNativUstMngUSTAVKI(short idxC, short offset)

int getMngUSTAVKI(short baza, short offset)
{
    return  mngUSTAVKI[baza + offset];
}//getMngUSTAVKI(short baza, short offset)

void CopyMngUstavki(int numBlok)
{
//копировать тек уставки на numBlok блок
 memcpy(&(blokUSTAVKI[numBlok*MAX_MNGUSTAVKI]), mngUSTAVKI, 4*MAX_MNGUSTAVKI);
}//CopyMngUstavki(int numBlok)

void CopyEEPROMtoUstavki(int numBlok)
{
//копировать данные из EEPROM в текущие уставки
extern char  tmp_eeprom[];//MAX_MNGUSTAVKI*4блока *4байта
//numBlok - номер блока уставок
 memcpy(blokUSTAVKI, tmp_eeprom, 4*(4*MAX_MNGUSTAVKI+1));//для 4 блоков уставок и CRC
 memcpy(mngUSTAVKI, &(blokUSTAVKI[numBlok*MAX_MNGUSTAVKI]), MAX_MNGUSTAVKI);
}//CopyMngUstavki(int numBlok)

void SaveAsBlokUstavki(int numBlok)
{
//сохранить тек уст как блок уставок
  CopyMngUstavki(numBlok);//копировать тек уставки на numBlok
  blokUSTAVKI[4*MAX_MNGUSTAVKI] = setCRCMassiv(blokUSTAVKI, 4*MAX_MNGUSTAVKI); //CRC для 4 блоков уставок
}//SaveAsBlokUstavki(int numBlok)

int getCRCUstavki()
{
//получить CRC уставок
  return blokUSTAVKI[4*MAX_MNGUSTAVKI]; //CRC для 4 блоков уставок
}//getCRCUstavki()
