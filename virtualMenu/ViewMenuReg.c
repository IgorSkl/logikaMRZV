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
#include "virtualMenu\systemmenudef.h"
#include "component\componentdef.h"
#include "virtualMenu\rangmanagerdef.h"

#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "virtualMenu\rangmanagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"

#include "virtualMenu\viewMenuSub.h"
#include "virtualMenu\viewMenuRang.h"
#include "virtualMenu\viewMenuReg.h"
#include "virtualMenu\viewMenuWideLog.h"
#include "virtualMenu\viewMenuTip.h"

#include "..\bazis.h"

#include "toSpeedOptim.h"
#include "toSpeedDIS.h"

extern REGISTRATOR_DIS registrator_dis;//массив ДИС
//массив имен и статуса ранжирования плюс имена расширенной логики
extern IONAMESTATUS_RANGIR  nameStatusRANGIR[];

void PereinitReg(short flg);

short  KadrMenuFormat_reg(void *pstr)
{
 WorkControl *workCntr = (WorkControl *)pstr;
//формирователь кадра
  ELEMENT_DIS tmpDStr;

  UNS_32 tmpTmp[DQUADRO];//промежуточные
  UNS_32 cmdTmpOld[DQUADRO];//текущие old

  UNS_32 IntElement[DQUADRO];

  RESET_COUNTER;//сброс счетчиков
  //сформировать old
  memcpy(cmdTmpOld, registrator_dis.title_dis.oldDIS, 4*DQUADRO);

  int len_dis = registrator_dis.title_dis.len_dis;//длина масс ДИС
  if(len_dis==0)//длина масс ДИС
                 return -1;
  for(int i=0; i<len_dis; i++){
    memcpy((char*)&tmpDStr, (char*)&(registrator_dis.bodyDIS[i]), sizeof(ELEMENT_DIS));//прочитать запись
    memcpy(IntElement, tmpDStr.pActualCMD, 4*DQUADRO);//скопировать текущие

    CNTRLOC_USER1 = tmpDStr.reltime;//время
    for(int i=0; i<DQUADRO; i++) tmpTmp[i] = IntElement[i]^cmdTmpOld[i];//сформировать промежуточные

    if(KadrFinder(tmpTmp, &KadrMaker,
                  workCntr,
                  IntElement
                 )) break;//кадр сформирован

    memcpy(cmdTmpOld, tmpDStr.pActualCMD, 4*DQUADRO);//скопировать текущие

  }//for

  return 1;
}//KadrFormat(WorkControl *workCntr)

/**********************************************
ФУНКЦИЯ-РАБОТНИК ДЛЯ БРИГАДИРА
Активизация байта команды по номеру
idx - индекс активного бита
Выход - 0-не покидать бригадира
**********************************************/
void KadrMaker(short idx, void *pstr, UNS_32 *integE)
{
  char locTxt[100];

 WorkControl *workCntr = (WorkControl *)pstr;
  sprintf(locTxt, "// %dмс ", CNTRLOC_USER1);//время
  char tmpOst = idx%32;//остаток индекс бита в слове
  if((  integE[(idx - tmpOst)/32] & (1<<tmpOst))!=0)
  {
    strcat(locTxt, "+++Пришел");//первая строка
    strcpy((char *)workCntr->twoString, locTxt);
  }//if
  else
  {
    strcat(locTxt, "---Ушел");//первая строка
    strcpy((char *)workCntr->twoString, locTxt);
  }

  strcpy((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, 
         "\\\\");//вторая строка
  strcat((char *)workCntr->twoString + sizeof(WorkVariantChar)/2, 
//locTxt
         nameStatusRANGIR[idx].nameIORang
        );

  return ;//покинуть бригадир

}//KadrMaker()

/**********************************************
БИТОВЫЙ БРИГАДИР ДЛЯ ДИСКР РЕГИСТРАТОРА
pQuadro - указатель на массив INTU[4]
pfW - указатель на функцию-работника
функция-работник работает только с глобальной памятью
если функция-работник возвратит 1 то MultiBitWorker завершается
**********************************************/
char KadrFinder(UNS_32 *pQuadro,
                void (*pKadrMaker)(short , void *, UNS_32 *),
                void *pstr,
                UNS_32 *integerE
               )
{
  short cntBit=0;//счетчик бит
 WorkControl *workCntr = (WorkControl *)pstr;
  for (char i=0; i<DQUADRO; i++)
  {
    if (pQuadro[i]==0)
    {
      cntBit+=32;
      continue;
    }//if (pQuadro[i]==0)
    else
    {
      for (char b=0; b<32; b++)
      {
        if (pQuadro[i]&(1<<b))
        {
          //есть единица
          COMPARE_COUNTER //сравнить счетчики кадров
          { (*pKadrMaker)(cntBit, workCntr, integerE); return 1; }//покинуть бригадир
        }//if (pQuadro[i]&(1<<b))
        cntBit++;
      }//for
    }
  }//for
  return 0;
}//KadrFinder()

void OpenMenuReg()
{
//открыть меню reg
  TxtStreamCorrect(CRR_TEXTSTREAM);//коррекция текущий control
//  CRR_TEXTSTREAM = &CONTROL_DIS;//текущий control
  SelectorTEXTCONTROL(&CONTROL_DIS);//установить текущую ссылку на текстовый поток
  PereinitReg(1);//ф-ция переинит reg

//  CRR_FHOME = &PereinitReg;//указатель на ф-цию HOME
  SelectorFHOME(&PereinitReg);//указатель на ф-цию HOME
}//OpenMenuReg()

void PereinitReg(short flg)
{
//ф-ция переинит reg
  TxtStreamInit(CRR_TEXTSTREAM, &KadrMenuFormat_reg, NULL);//инит управл структ и формир кадра
  if(flg==1)
    ViewDiskrMenu(typeMenuReg);//вывести окно отображения
}//PereinitReg()

