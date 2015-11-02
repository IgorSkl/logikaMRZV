
//#include <TCHAR.H >

#include <stdio.h>
#include <string.h>

#include "psuperVisor\supermanager.h"

#include "bazisdef.h"
#include "component\componentdef.h"
#include "psuperVisor\psvisor_helpdef.h"
#include "logictimers\logictimersdef.h"

#include "logictimers\logictimersfnc.h"

#include "..\bazis.h"

#include "toSpeedOptim.h"

#define _HIDE_COMPONENT
#include "PRM1Component.c"

extern int GlobalPO1;//телеметрия
extern int GlobalPO2;//телеметрия
extern int GlobalPO3;//телеметрия
extern int GlobalPO4;//телеметрия
extern int GlobalLevelI_ABC[];//действ значения 3 фаз токов
extern int GlobalLevelUL_ABC[];//действ значения 3 фаз напр
extern int GlobalLevelUF_ABC[];//действ значения 3 фаз напр
extern int GlobalLevel_UCM;
extern int GlobalLevel_ICM;

//конфигурация
extern COMPONENT_OBJ        cnfCOMPONENT[];
extern COMPONENT_OBJ        cnfCOMPONENT_WL[];
extern int  timerEnableWL;//разрешение работы таймеров РЛ
//текущие уставки супервизора
extern int    spvUSTAVKI[];
extern UNS_32 pActualCMD[];//текущие
extern int   WideCmdRTBuffer[];
extern int offsetENACmdPRM1;//смещение для ENA PRM1
extern int offsetSPVCmdPRM1;//смещение для SPV PRM1
extern int  ENAcmd[];
extern int ReleTrigger;//тригг реле
extern int CDITrigger;//тригг СДИ
//неисправность цепей напр
extern int  isFAILU_COMMON_MTZ;
extern int  isFAILU_COMMON_DZ;
//все напр меньше U005
//extern int  isFAILU005_COMMON;
//все токи меньше I005
extern int  isFAILI005_COMMON;

//напр UCM меньше UCM005
//extern int  isFAILUCM005_COMMON;
//ток ICM  меньше ICM005
//extern int  isFAILICM005_COMMON;

extern int  ddvIncrementor;//счетчик времени для Допуск ДВ
extern UNS_32 ArrayRANGIR[];

extern UNS_32 rawDVLow;//сырые ДВ
extern UNS_32 rawDVMidd;//сырые ДВ
extern UNS_32 rawDVHi;//сырые ДВ
extern UNS_32 oldDV1,  oldDV2,  oldDV3,  oldDV4,  oldDV5,  oldDV6;
extern UNS_32 oldDV7,  oldDV8,  oldDV9,  oldDV10, oldDV11, oldDV12;//сырые ДВ
extern UNS_32 oldDV13, oldDV14, oldDV15, oldDV16;

extern UNS_32 oldDV17,  oldDV18,  oldDV19,  oldDV20,  oldDV21,  oldDV22;
extern UNS_32 oldDV23,  oldDV24,  oldDV25,  oldDV26,  oldDV27,  oldDV28;//сырые ДВ
extern UNS_32 oldDV29,  oldDV30,  oldDV31,  oldDV32;

extern UNS_32 oldDV33,  oldDV34,  oldDV35,  oldDV36;
extern int acdcDV;//флаг пост перем для ДВ
//допуски ДВ обработки
extern int  ddv_inc[];
extern int  ddv_fix[];


extern UNS_32 pActualCMD[];//текущие
extern BAZIS_TIMER_MEM  bazisTimerMem[];
extern BAZIS_TIMER_MEM  bazisTimerMem_WL[];

extern UNS_32 ArrayWIDELOG[];
extern UNS_32 PlusCircleCmd[];//командный массив плюсовых команд LE
extern UNS_32 InputLECmd[];//входной командный массив LE
extern UNS_32 EXEOutputCmd[];//выходной командный массив компонентов

/**********************************************
СУПЕРВИЗОР
Логика компонентов из конфиг
**********************************************/
void EXElogicCOMPONENT() @ "Fast_function"
{
  short tmp = 0;
  while (cnfCOMPONENT[tmp].componentEnable) {
    cnfCOMPONENT[tmp].logic(tmp);
    tmp++;
  }//while
  bazisTimerMem[0].ENABLE = 1;//разрешить лог таймера
//  globalTimerReset = 0;//глобальный сброс всех таймеров
}//EXElogicCOMPONENT()

/**********************************************
СУПЕРВИЗОР
Логика компонентов из конфиг РЛ
**********************************************/
void EXElogicCOMPONENT_WL() @ "Fast_function"
{
  short tmp = 0;
  while (cnfCOMPONENT_WL[tmp].componentEnable) {
    cnfCOMPONENT_WL[tmp].logic(-tmp-1);
    tmp++;
  }//while
  bazisTimerMem_WL[0].ENABLE = timerEnableWL;//разрешение работы таймеров РЛ
//  globalTimerReset = 0;//глобальный сброс всех таймеров
}//EXElogicCOMPONENT()

/**********************************************
КОМПРЕССОР МАССИВА
pQuadro - указатель на массив Quadro
p128 - указатель на широкий ком массив 
**********************************************/
void CompressorToQuadro(int *p128, UNS_32 *pQuadro) @ "Fast_function"
{
  for (int i=0; i<DQUADRO; i++)
  {
    UNS_32 tmp = 0;
    for (int b=0; b<32; b++)
    {
      if (p128[i*32+b])//!=0)
      {
        tmp |= 1<<b;
      }
    }//for
    pQuadro[i] = tmp;
  }//for
}//CompressorToQuadro(int *p128, UNS_32 *pQuadro)

/**********************************************
КОМПРЕССОР МАССИВА ActualCMD
pActualCMD - указатель на массив текущего Quadro
WideCmdRTBuffer - указатель на широкий ком массив ранжирования 
**********************************************/
void CompressorToActualCMD() @ "Fast_function"
{
  for (int i=0; i<DQUADRO; i++)
  {
    UNS_32 tmp = 0;
    for (int b=0; b<32; b++)
    {
      if (WideCmdRTBuffer[i*32+b])//!=0)
      {
        tmp |= 1<<b;
      }
    }//for
    pActualCMD[i] = tmp;
  }//for
}//CompressorToActualCMD()

/**********************************************
ДЕТЕСТОР УРОВНЯ МЕНЬШЕ
level - входной уровень
uSrab - смещение на уставка сработки
uVozv - смещение на уставка возврата
offset_out   - смещение на старый флаг spv
**********************************************/
void  detectorLevelDOWN(int level, int offset_uSrab, int offset_uVozv, int offset_out) @ "Fast_function"
{
//конфигурация меньше
    if (spvUSTAVKI[offset_out])   //была сработка
    {
      if (level>spvUSTAVKI[offset_uVozv])   //возвр
      {
        spvUSTAVKI[offset_out] = 0;
        return ;
      }//if
    }//if
    else
    {
      if (level<=spvUSTAVKI[offset_uSrab])   //сраб
      {
        spvUSTAVKI[offset_out] = 1;
        return ;
      }//if
    }
}//detectorLevelDOWN(int level, int offset_uSrab, int offset_uVozv, int offset_out)

/**********************************************
ДЕТЕСТОР УРОВНЯ БОЛЬШЕ
level - входной уровень
uSrab - смещение на уставка сработки
uVozv - смещение на уставка возврата
offset_out   - смещение на старый флаг spv
**********************************************/
void  detectorLevelUP(int level, int offset_uSrab, int offset_uVozv, int offset_out) @ "Fast_function"
{
//конфигурация больше
    if (spvUSTAVKI[offset_out])   //была сработка
    {
      if (level<spvUSTAVKI[offset_uVozv])   //возвр
      {
        spvUSTAVKI[offset_out] = 0;
        return ;
      }//if
    }//if
    else
    {
      if (level>=spvUSTAVKI[offset_uSrab])   //сраб
      {
        spvUSTAVKI[offset_out] = 1;
        return ;
      }//if
    }
}//detectorLevelUP(int level, int offset_uSrab, int offset_uVozv, int offset_out)

/**********************************************
ДЕТЕСТОР УРОВНЯ БОЛЬШЕ
level - входной уровень
uSrab - смещение на уставка сработки
uVozv - смещение на уставка возврата
offset_out   - смещение на старый флаг spv
**********************************************/
void  detectorLevelUP3F(int *level, int offset_uSrab, int offset_uVozv, int offset_out) @ "Fast_function"
{
//конфигурация больше
 int tmpSrab = spvUSTAVKI[offset_uSrab];
 int tmpVozv = spvUSTAVKI[offset_uVozv];
 for(int i=0; i<3; i++)
  {
    if (spvUSTAVKI[offset_out+i])   //была сработка
    {
      if (level[i]<tmpVozv)   //возвр
      {
        spvUSTAVKI[offset_out+i] = 0;
        continue;
      }//if
    }//if
    else
    {
      if (level[i]>=tmpSrab)   //сраб
      {
        spvUSTAVKI[offset_out+i] = 1;
        continue;
      }//if
    }
  }//for
}//detectorLevelUP3F(int level, int offset_uSrab, int offset_uVozv, int offset_out)

/**********************************************
ДЕТЕСТОР УРОВНЯ МЕНЬШЕ
level - входной уровень
uSrab - смещение на уставка сработки
uVozv - смещение на уставка возврата
offset_out   - смещение на старый флаг spv
**********************************************/
void  detectorLevelDOWN3F(int *level, int offset_uSrab, int offset_uVozv, int offset_out) @ "Fast_function"
{
//конфигурация меньше
 for(int i=0; i<3; i++)
  {
    if (spvUSTAVKI[offset_out+i])   //была сработка
    {
      if (level[i]>spvUSTAVKI[offset_uVozv])   //возвр
      {
        spvUSTAVKI[offset_out+i] = 0;
        continue;
      }//if
    }//if
    else
    {
      if (level[i]<=spvUSTAVKI[offset_uSrab])   //сраб
      {
        spvUSTAVKI[offset_out+i] = 1;
        continue;
      }//if
    }
  }//for
}//detectorLevelDOWN3F(int level, int offset_uSrab, int offset_uVozv, int offset_out)

//совпадение текущих и маски
int CheckActualCMD(UNS_32 *cmdArr) @ "Fast_function"
{
//сравнить текущие и ком массив УВВ DQUADRO=10
  if((cmdArr[0]&pActualCMD[0]) |//) return 1;
     (cmdArr[1]&pActualCMD[1]) |//return 1;
     (cmdArr[2]&pActualCMD[2]) |//return 1;
     (cmdArr[3]&pActualCMD[3]) |//return 1;
     (cmdArr[4]&pActualCMD[4]) |//return 1;
     (cmdArr[5]&pActualCMD[5]) |//return 1;
     (cmdArr[6]&pActualCMD[6]) |//return 1;
     (cmdArr[7]&pActualCMD[7]) |//return 1;
     (cmdArr[8]&pActualCMD[8]) |//return 1;
     (cmdArr[9]&pActualCMD[9])) return 1;
  return 0;
}//CheckActualCMD(UNS_32 *cmdArr)

//совпадение инверсных текущих и маски
int CheckActualCMDInv(UNS_32 *cmdArr) @ "Fast_function"
{
//сравнить текущие и ком массив УВВ DQUADRO=10
  if((cmdArr[0]&(~pActualCMD[0])) |//) return 1;
     (cmdArr[1]&(~pActualCMD[1])) |//return 1;
     (cmdArr[2]&(~pActualCMD[2])) |//return 1;
     (cmdArr[3]&(~pActualCMD[3])) |//return 1;
     (cmdArr[4]&(~pActualCMD[4])) |//return 1;
     (cmdArr[5]&(~pActualCMD[5])) |//return 1;
     (cmdArr[6]&(~pActualCMD[6])) |//return 1;
     (cmdArr[7]&(~pActualCMD[7])) |//return 1;
     (cmdArr[8]&(~pActualCMD[8])) |//return 1;
     (cmdArr[9]&(~pActualCMD[9]))) return 1;
  return 0;
}//CheckActualCMDInv(UNS_32 *cmdArr)

/**********************************************
ФУНКЦИЯ-РАБОТНИК ДЛЯ БРИГАДИРА
Превратить Quadro в широкий ком массив RT
idx - индекс активного бита
Выход - 0-не покидать бригадира
**********************************************/
int pfWorker5(short idx) @ "Fast_function"
{
  WideCmdRTBuffer[idx] = 1;//широкий ком массив RT
  return 0;
}//pfWorker5(short idx)

void TranslateQuadroToWideRTCmd(UNS_32 *pQuadro) @ "Fast_function"
{
//Превратить Quadro RT в широкий ком массив RT
  //обнулить широкий ком буфер RT
  memset(WideCmdRTBuffer, 0, 4*SIZE_RANGIRCMD);
  MultiBitWorkerHostQuadro(pQuadro, &pfWorker5);
}//TranslateQuadroToWideRTCmd(UNS_32 *pQuadro)

/**********************************************
БИТОВЫЙ БРИГАДИР
pQuadro - указатель на массив INTU[DQUADRO]
pfW - указатель на функцию-работника
функция-работник работает только с глобальной памятью
если функция-работник возвратит 1 то MultiBitWorker завершается
**********************************************/
int MultiBitWorkerHostQuadro(UNS_32 *pQuadro, int (*pfW)(short idx)) @ "Fast_function"
{
  int cntBit=0;//счетчик бит
  for (int i=0; i<DQUADRO; i++)
  {
    if (pQuadro[i]==0)
    {
      cntBit+=32;
      continue;
    }
    else
    {
      for (int b=0; b<32; b++)
      {
        if (pQuadro[i]&(1<<b))
        {
          //если работник вернет 1 то покидаем бригадир
          if ((*pfW)(cntBit)) return 1;
        }
        cntBit++;
      }//for
    }
  }//for
  return 0;
}//MultiBitWorkerHostQuadro(UNS_32 *pQuadro, int (*pfW)(short idx))

/**********************************************
БИТОВЫЙ БРИГАДИР
pQuadro - указатель на массив INTU[2*DQUADRO]
pfW - указатель на функцию-работника
функция-работник работает только с глобальной памятью
если функция-работник возвратит 1 то MultiBitWorker завершается
**********************************************/
int MultiBitWorkerHostQuadroWL(UNS_32 *pQuadro, int (*pfW)(short idx)) @ "Fast_function"
{
  int cntBit=0;//счетчик бит
  for (int i=0; i<2*DQUADRO; i++)
  {
    if (pQuadro[i]==0)
    {
      cntBit+=32;
      continue;
    }
    else
    {
      for (int b=0; b<32; b++)
      {
        if (pQuadro[i]&(1<<b))
        {
          //если работник вернет 1 то покидаем бригадир
          if ((*pfW)(cntBit)) return 1;
        }
        cntBit++;
      }//for
    }
  }//for
  return 0;
}//MultiBitWorkerHostQuadroWL(UNS_32 *pQuadro, int (*pfW)(short idx))

void CommonMeasureLogic() @ "Fast_function"
{
 //общая логика измерений

//все токи меньше 12IH
  detectorLevelDOWN3F(GlobalLevelI_ABC, offsetSPVCmdPRM1+SPVSRAB_12IH,
                                        offsetSPVCmdPRM1+SPVVOZV_12IH,
                                        offsetSPVCmdPRM1+SPV_OUTA_12IH);

 //
 int LocalPO_12IH =   SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTA_12IH) &
                      SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTB_12IH) &
                      SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTC_12IH);

//все напр меньше 02UH
  detectorLevelDOWN3F(GlobalLevelUL_ABC, offsetSPVCmdPRM1+SPVSRAB_02UH,
                                         offsetSPVCmdPRM1+SPVVOZV_02UH,
                                         offsetSPVCmdPRM1+SPV_OUTA_02UH);

 //
 int LocalPO_02UH =   SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTA_02UH) &
                      SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTB_02UH) &
                      SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUTC_02UH);

//  int ttt1 = 
//  LocalPO_12IH;
    //int ttt2 = 
 //LocalPO_02UH;

//неисправность цепей напр 
  isFAILU_COMMON_MTZ = (LocalPO_12IH&LocalPO_02UH) &
                    //разрешить неисправность цепей напр МТЗ
                   ENA_LOGICOUT(offsetENACmdPRM1 +ENA_PRM1_FAILU_MTZ);
  isFAILU_COMMON_DZ = (LocalPO_12IH&LocalPO_02UH);// &
                    //разрешить неисправность цепей напр DZ
//                   ENA_LOGICOUT(offsetENACmdPRM1 +ENA_PRM1_FAILU_DZ);

//все напр меньше 005UH
  detectorLevelDOWN3F(GlobalLevelUL_ABC, offsetSPVCmdPRM1+SPVSRAB_U005,
                                       offsetSPVCmdPRM1+SPVVOZV_U005,
                                       offsetSPVCmdPRM1+SPV_OUTA_U005);

//напр lin меньше 0.25B
  detectorLevelDOWN3F(GlobalLevelUL_ABC, offsetSPVCmdPRM1+SPVSRAB_U025,
                                       offsetSPVCmdPRM1+SPVVOZV_U025,
                                       offsetSPVCmdPRM1+SPV_OUTAL_U025);
//напр faz меньше 0.25B
  detectorLevelDOWN3F(GlobalLevelUF_ABC, offsetSPVCmdPRM1+SPVSRAB_U025,
                                       offsetSPVCmdPRM1+SPVVOZV_U025,
                                       offsetSPVCmdPRM1+SPV_OUTAF_U025);


//напр UCM меньше UCM005
  detectorLevelDOWN(GlobalLevel_UCM, offsetSPVCmdPRM1+SPVSRAB_UCM005,
                                  offsetSPVCmdPRM1+SPVVOZV_UCM005,
                                  offsetSPVCmdPRM1+SPV_OUT_UCM005);

//напр UCM меньше UCM005
//  isFAILUCM005_COMMON = SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUT_UCM005)^1;

//ток ICM меньше ICM005
  detectorLevelDOWN(GlobalLevel_ICM, offsetSPVCmdPRM1+SPVSRAB_ICM005,
                                  offsetSPVCmdPRM1+SPVVOZV_ICM005,
                                  offsetSPVCmdPRM1+SPV_OUT_ICM005);

//ток ICM меньше ICM005
//  isFAILICM005_COMMON = SPV_USTOUT(offsetSPVCmdPRM1+SPV_OUT_ICM005)^1;

}//CommonMeasureLogic();

#define ACTIV_PASSIV_DV(incfix, ust)  if(ddv_inc[incfix]==ROST){\
   int locUst = SPV_USTOUT(offsetSPVCmdPRM1+ ust);\
   if(acdcDV) locUst = 3;\
   int tmp1 = ddvIncrementor - ddv_fix[incfix];\
   if(tmp1<0) tmp1 += (DDV_MAX+1);\
   if(tmp1>locUst)\
                             ddv_inc[incfix] = ACTIV;\
  }\
  if(ddv_inc[incfix]==SPAD){\
   int tmp1 = ddvIncrementor - ddv_fix[incfix];\
   if(tmp1<0) tmp1 += (DDV_MAX+1);\
   if(tmp1>SPV_USTOUT(offsetSPVCmdPRM1+ ust))\
                             ddv_inc[incfix] = PASSIV;\
  }

#define ROST_SPAD_DV(incfix, act, old)  if((act^old)&act) {\
     ddv_fix[incfix] = ddvIncrementor;\
     if(ddv_inc[incfix] == SPAD)\
                             ddv_inc[incfix] = ACTIV;\
     if(ddv_inc[incfix] == PASSIV)\
                             ddv_inc[incfix] = ROST;\
  }\
  if((act^old)&old) {\
     ddv_fix[incfix] = ddvIncrementor;\
     if(ddv_inc[incfix] == ROST)\
                             ddv_inc[incfix] = PASSIV;\
     if(ddv_inc[incfix] == ACTIV)\
                             ddv_inc[incfix] = SPAD;\
  }\
  old = act;

#define OUT_DV(incfix)  if(ddv_inc[incfix] == PASSIV ||\
     ddv_inc[incfix] == ROST\
     )
enum
{
 PASSIV=0,
 ROST,
 ACTIV,
 SPAD
};

int SelectorDVdriverLow() @ "Fast_function"
{
//селекция ДВ активный-неактивный мл 16 DV
  int actDV1=0;  int actDV2=0;  int actDV3=0;  int actDV4=0;  int actDV5=0; int actDV6=0; 
  int actDV7=0;  int actDV8=0;  int actDV9=0;  int actDV10=0; int actDV11=0; 
  int actDV12=0; int actDV13=0; int actDV14=0; int actDV15=0; int actDV16=0;
  if(rawDVLow&1) actDV1 = 1;
  if(rawDVLow&2) actDV2 = 1;
  if(rawDVLow&4) actDV3 = 1;
  if(rawDVLow&8) actDV4 = 1;
  if(rawDVLow&16) actDV5 = 1;
  if(rawDVLow&32) actDV6 = 1;
  if(rawDVLow&64) actDV7 = 1;
  if(rawDVLow&128) actDV8 = 1;
  if(rawDVLow&(128*2))   actDV9 = 1;
  if(rawDVLow&(128*4))   actDV10 = 1;
  if(rawDVLow&(128*8))   actDV11 = 1;
  if(rawDVLow&(128*16))  actDV12 = 1;
  if(rawDVLow&(128*32))  actDV13 = 1;
  if(rawDVLow&(128*64))  actDV14 = 1;
  if(rawDVLow&(128*128)) actDV15 = 1;
  if(rawDVLow&(128*256)) actDV16 = 1;
  
     ROST_SPAD_DV(DV1_SM-DV1_SM, actDV1, oldDV1)
  ACTIV_PASSIV_DV(DV1_SM-DV1_SM, SPV_DDV1_UST)

     ROST_SPAD_DV(DV2_SM-DV1_SM, actDV2, oldDV2)
  ACTIV_PASSIV_DV(DV2_SM-DV1_SM, SPV_DDV2_UST)

     ROST_SPAD_DV(DV3_SM-DV1_SM, actDV3, oldDV3)
  ACTIV_PASSIV_DV(DV3_SM-DV1_SM, SPV_DDV3_UST)

     ROST_SPAD_DV(DV4_SM-DV1_SM, actDV4, oldDV4)
  ACTIV_PASSIV_DV(DV4_SM-DV1_SM, SPV_DDV4_UST)

     ROST_SPAD_DV(DV5_SM-DV1_SM, actDV5, oldDV5)
  ACTIV_PASSIV_DV(DV5_SM-DV1_SM, SPV_DDV5_UST)

     ROST_SPAD_DV(DV6_SM-DV1_SM, actDV6, oldDV6)
  ACTIV_PASSIV_DV(DV6_SM-DV1_SM, SPV_DDV6_UST)

     ROST_SPAD_DV(DV7_SM-DV1_SM, actDV7, oldDV7)
  ACTIV_PASSIV_DV(DV7_SM-DV1_SM, SPV_DDV7_UST)

     ROST_SPAD_DV(DV8_SM-DV1_SM, actDV8, oldDV8)
  ACTIV_PASSIV_DV(DV8_SM-DV1_SM, SPV_DDV8_UST)

     ROST_SPAD_DV(DV9_SM-DV1_SM, actDV9, oldDV9)
  ACTIV_PASSIV_DV(DV9_SM-DV1_SM, SPV_DDV9_UST)

     ROST_SPAD_DV(DV10_SM-DV1_SM, actDV10, oldDV10)
  ACTIV_PASSIV_DV(DV10_SM-DV1_SM, SPV_DDV10_UST)

     ROST_SPAD_DV(DV11_SM-DV1_SM, actDV11, oldDV11)
  ACTIV_PASSIV_DV(DV11_SM-DV1_SM, SPV_DDV11_UST)

     ROST_SPAD_DV(DV12_SM-DV1_SM, actDV12, oldDV12)
  ACTIV_PASSIV_DV(DV12_SM-DV1_SM, SPV_DDV12_UST)

     ROST_SPAD_DV(DV13_SM-DV1_SM, actDV13, oldDV13)
  ACTIV_PASSIV_DV(DV13_SM-DV1_SM, SPV_DDV13_UST)

     ROST_SPAD_DV(DV14_SM-DV1_SM, actDV14, oldDV14)
  ACTIV_PASSIV_DV(DV14_SM-DV1_SM, SPV_DDV14_UST)

     ROST_SPAD_DV(DV15_SM-DV1_SM, actDV15, oldDV15)
  ACTIV_PASSIV_DV(DV15_SM-DV1_SM, SPV_DDV15_UST)

     ROST_SPAD_DV(DV16_SM-DV1_SM, actDV16, oldDV16)
  ACTIV_PASSIV_DV(DV16_SM-DV1_SM, SPV_DDV16_UST)

 int ret = 0;
  OUT_DV(DV1_SM-DV1_SM)ret &= ~1;
  else ret |= 1;

  OUT_DV(DV2_SM-DV1_SM)ret &= ~2;
  else ret |= 2;

  OUT_DV(DV3_SM-DV1_SM)ret &= ~4;
  else ret |= 4;

  OUT_DV(DV4_SM-DV1_SM)ret &= ~8;
  else ret |= 8;

  OUT_DV(DV5_SM-DV1_SM)ret &= ~16;
  else ret |= 16;

  OUT_DV(DV6_SM-DV1_SM)ret &= ~32;
  else ret |= 32;

  OUT_DV(DV7_SM-DV1_SM)ret &= ~64;
  else ret |= 64;

  OUT_DV(DV8_SM-DV1_SM)ret &= ~128;
  else ret |= 128;

  OUT_DV(DV9_SM-DV1_SM)ret &= ~(128*2);
  else ret |= (128*2);

  OUT_DV(DV10_SM-DV1_SM)ret &= ~(128*4);
  else ret |= (128*4);

  OUT_DV(DV11_SM-DV1_SM)ret &= ~(128*8);
  else ret |= (128*8);

  OUT_DV(DV12_SM-DV1_SM)ret &= ~(128*16);
  else ret |= (128*16);

  OUT_DV(DV13_SM-DV1_SM)ret &= ~(128*32);
  else ret |= (128*32);

  OUT_DV(DV14_SM-DV1_SM)ret &= ~(128*64);
  else ret |= (128*64);

  OUT_DV(DV15_SM-DV1_SM)ret &= ~(128*128);
  else ret |= (128*128);

  OUT_DV(DV16_SM-DV1_SM)ret &= ~(128*256);
  else ret |= (128*256);

  return ret;
}//SelectorDVdriverLow()

int SelectorDVdriverMidd() @ "Fast_function"
{
//селекция ДВ активный-неактивный cp 16 DV
  int actDV1=0;  int actDV2=0;  int actDV3=0;  int actDV4=0;  int actDV5=0; int actDV6=0; 
  int actDV7=0;  int actDV8=0;  int actDV9=0;  int actDV10=0; int actDV11=0;
  int actDV12=0; int actDV13=0; int actDV14=0; int actDV15=0; int actDV16=0;
  if(rawDVMidd&1) actDV1 = 1;
  if(rawDVMidd&2) actDV2 = 1;
  if(rawDVMidd&4) actDV3 = 1;
  if(rawDVMidd&8) actDV4 = 1;
  if(rawDVMidd&16) actDV5 = 1;
  if(rawDVMidd&32) actDV6 = 1;
  if(rawDVMidd&64) actDV7 = 1;
  if(rawDVMidd&128) actDV8 = 1;
  if(rawDVMidd&(128*2))   actDV9 = 1;
  if(rawDVMidd&(128*4))   actDV10 = 1;
  if(rawDVMidd&(128*8))   actDV11 = 1;
  if(rawDVMidd&(128*16))  actDV12 = 1;
  if(rawDVMidd&(128*32))  actDV13 = 1;
  if(rawDVMidd&(128*64))  actDV14 = 1;
  if(rawDVMidd&(128*128)) actDV15 = 1;
  if(rawDVMidd&(128*256)) actDV16 = 1;

     ROST_SPAD_DV(DV17_SM-DV1_SM, actDV1, oldDV17)
  ACTIV_PASSIV_DV(DV17_SM-DV1_SM, SPV_DDV17_UST)

     ROST_SPAD_DV(DV18_SM-DV1_SM, actDV2, oldDV18)
  ACTIV_PASSIV_DV(DV18_SM-DV1_SM, SPV_DDV18_UST)

     ROST_SPAD_DV(DV19_SM-DV1_SM, actDV3, oldDV19)
  ACTIV_PASSIV_DV(DV19_SM-DV1_SM, SPV_DDV19_UST)

     ROST_SPAD_DV(DV20_SM-DV1_SM, actDV4, oldDV20)
  ACTIV_PASSIV_DV(DV20_SM-DV1_SM, SPV_DDV20_UST)

     ROST_SPAD_DV(DV21_SM-DV1_SM, actDV5, oldDV21)
  ACTIV_PASSIV_DV(DV21_SM-DV1_SM, SPV_DDV21_UST)

     ROST_SPAD_DV(DV22_SM-DV1_SM, actDV6, oldDV22)
  ACTIV_PASSIV_DV(DV22_SM-DV1_SM, SPV_DDV22_UST)

     ROST_SPAD_DV(DV23_SM-DV1_SM, actDV7, oldDV23)
  ACTIV_PASSIV_DV(DV23_SM-DV1_SM, SPV_DDV23_UST)

     ROST_SPAD_DV(DV24_SM-DV1_SM, actDV8, oldDV24)
  ACTIV_PASSIV_DV(DV24_SM-DV1_SM, SPV_DDV24_UST)

     ROST_SPAD_DV(DV25_SM-DV1_SM, actDV9, oldDV25)
  ACTIV_PASSIV_DV(DV25_SM-DV1_SM, SPV_DDV25_UST)

     ROST_SPAD_DV(DV26_SM-DV1_SM, actDV10, oldDV26)
  ACTIV_PASSIV_DV(DV26_SM-DV1_SM, SPV_DDV26_UST)

     ROST_SPAD_DV(DV27_SM-DV1_SM, actDV11, oldDV27)
  ACTIV_PASSIV_DV(DV27_SM-DV1_SM, SPV_DDV27_UST)

     ROST_SPAD_DV(DV28_SM-DV1_SM, actDV12, oldDV28)
  ACTIV_PASSIV_DV(DV28_SM-DV1_SM, SPV_DDV28_UST)

     ROST_SPAD_DV(DV29_SM-DV1_SM, actDV13, oldDV29)
  ACTIV_PASSIV_DV(DV29_SM-DV1_SM, SPV_DDV29_UST)

     ROST_SPAD_DV(DV30_SM-DV1_SM, actDV14, oldDV30)
  ACTIV_PASSIV_DV(DV30_SM-DV1_SM, SPV_DDV30_UST)

     ROST_SPAD_DV(DV31_SM-DV1_SM, actDV15, oldDV31)
  ACTIV_PASSIV_DV(DV31_SM-DV1_SM, SPV_DDV31_UST)

     ROST_SPAD_DV(DV32_SM-DV1_SM, actDV16, oldDV32)
  ACTIV_PASSIV_DV(DV32_SM-DV1_SM, SPV_DDV32_UST)

 int ret = 0;
  OUT_DV(DV17_SM-DV1_SM)ret &= ~1;
  else ret |= 1;

  OUT_DV(DV18_SM-DV1_SM)ret &= ~2;
  else ret |= 2;

  OUT_DV(DV19_SM-DV1_SM)ret &= ~4;
  else ret |= 4;

  OUT_DV(DV20_SM-DV1_SM)ret &= ~8;
  else ret |= 8;

  OUT_DV(DV21_SM-DV1_SM)ret &= ~16;
  else ret |= 16;

  OUT_DV(DV22_SM-DV1_SM)ret &= ~32;
  else ret |= 32;

  OUT_DV(DV23_SM-DV1_SM)ret &= ~64;
  else ret |= 64;

  OUT_DV(DV24_SM-DV1_SM)ret &= ~128;
  else ret |= 128;

  OUT_DV(DV25_SM-DV1_SM)ret &= ~(128*2);
  else ret |= (128*2);

  OUT_DV(DV26_SM-DV1_SM)ret &= ~(128*4);
  else ret |= (128*4);

  OUT_DV(DV27_SM-DV1_SM)ret &= ~(128*8);
  else ret |= (128*8);

  OUT_DV(DV28_SM-DV1_SM)ret &= ~(128*16);
  else ret |= (128*16);

  OUT_DV(DV29_SM-DV1_SM)ret &= ~(128*32);
  else ret |= (128*32);

  OUT_DV(DV30_SM-DV1_SM)ret &= ~(128*64);
  else ret |= (128*64);

  OUT_DV(DV31_SM-DV1_SM)ret &= ~(128*128);
  else ret |= (128*128);

  OUT_DV(DV32_SM-DV1_SM)ret &= ~(128*256);
  else ret |= (128*256);

  return ret;
}//SelectorDVdriverMidd()

int SelectorDVdriverHi() @ "Fast_function"
{
//селекция ДВ активный-неактивный ct DV
  int actDV1=0;  int actDV2=0;  int actDV3=0;  int actDV4=0;  

  if(rawDVHi&1) actDV1 = 1;
  if(rawDVHi&2) actDV2 = 1;
  if(rawDVHi&4) actDV3 = 1;
  if(rawDVHi&8) actDV4 = 1;

     ROST_SPAD_DV(DV33_SM-DV1_SM, actDV1, oldDV33)
  ACTIV_PASSIV_DV(DV33_SM-DV1_SM, SPV_DDV33_UST)

     ROST_SPAD_DV(DV34_SM-DV1_SM, actDV2, oldDV34)
  ACTIV_PASSIV_DV(DV34_SM-DV1_SM, SPV_DDV34_UST)

     ROST_SPAD_DV(DV35_SM-DV1_SM, actDV3, oldDV35)
  ACTIV_PASSIV_DV(DV35_SM-DV1_SM, SPV_DDV35_UST)

     ROST_SPAD_DV(DV36_SM-DV1_SM, actDV4, oldDV36)
  ACTIV_PASSIV_DV(DV36_SM-DV1_SM, SPV_DDV36_UST)

 int ret = 0;
  OUT_DV(DV33_SM-DV1_SM)ret &= ~1;
  else ret |= 1;

  OUT_DV(DV34_SM-DV1_SM)ret &= ~2;
  else ret |= 2;

  OUT_DV(DV35_SM-DV1_SM)ret &= ~4;
  else ret |= 4;

  OUT_DV(DV36_SM-DV1_SM)ret &= ~8;
  else ret |= 8;

  return ret;
}//SelectorDVdriverHi()

int addCDItrig(int cdi_bdvv1) @ "Fast_function"
{
//добавить триггер
 int trg_maska = cdi_bdvv1;
//уставка НормальныйТриггерный
  trg_maska &= SPV_USTOUT(offsetSPVCmdPRM1+ SPV_UPR_CDI);

  CDITrigger |= trg_maska;//тригг Rele
  cdi_bdvv1  |= CDITrigger;
  return cdi_bdvv1;
}//addCDItrig(int cdi_bdvv1)

int addReleTrig(int rele_bdvv1) @ "Fast_function"
{
//добавить триггер
 int trg_maska = rele_bdvv1;
//уставка НормальныйТриггерный
  trg_maska &= SPV_USTOUT(offsetSPVCmdPRM1+ SPV_UPR_RELE);

 ReleTrigger |= trg_maska;//тригг Rele
  rele_bdvv1  |= ReleTrigger;
  return rele_bdvv1;
}//addReletrig(int cdi_bdvv1)

/**********************************************
МЕНЕДЖЕР РАСШИРЕННОЙ ЛОГИКИ
Логический элемент ИЛИ
**********************************************/
int elementOR(int lgm) @ "Fast_function"
{
//OR
  UNS_32 *cmdTmpPLUS  = &(ArrayWIDELOG[2*DQUADRO*3*lgm +2*DQUADRO+2*DQUADRO]);//командный массив tmpPLUS
  UNS_32 *cmdTmpMINUS = &(ArrayWIDELOG[2*DQUADRO*3*lgm +2*DQUADRO]);//командный массив tmpMINUS
  UNS_32 *cmdTmpPRM   = &(ArrayWIDELOG[2*DQUADRO*3*lgm]);//командный массив tmpPRM
    for (int i=0; i<(2*DQUADRO); i++)
    {
      if ((cmdTmpPRM[i] & InputLECmd[i])!=0 ||//прямые
          (cmdTmpMINUS[i] & (InputLECmd[i] ^ cmdTmpMINUS[i]))!=0 //инверсные
         )
      {
        for (int k=0; k<(2*DQUADRO); k++) PlusCircleCmd[k] |= cmdTmpPLUS[k];//добавить плюсовые
        return 0;
      }//if
    }//for(int i=0; i<8; i++)
    for (int k=0; k<(2*DQUADRO); k++) PlusCircleCmd[k] &= ~cmdTmpPLUS[k];//убрать плюсовые
    return 1;
}//elementOR()

/**********************************************
МЕНЕДЖЕР РАСШИРЕННОЙ ЛОГИКИ
Логический элемент И
**********************************************/
int elementAND(int lgm) @ "Fast_function"
{
//AND
  UNS_32 *cmdTmpPLUS  = &(ArrayWIDELOG[2*DQUADRO*3*lgm +2*DQUADRO+2*DQUADRO]);//командный массив tmpPLUS
  UNS_32 *cmdTmpMINUS = &(ArrayWIDELOG[2*DQUADRO*3*lgm +2*DQUADRO]);//командный массив tmpMINUS
  UNS_32 *cmdTmpPRM   = &(ArrayWIDELOG[2*DQUADRO*3*lgm]);//командный массив tmpPRM
    for (int i=0; i<(2*DQUADRO); i++)
    {
      if ((cmdTmpPRM[i] & (InputLECmd[i] ^ cmdTmpPRM[i]))!=0 || //прямые
          (cmdTmpMINUS[i] & InputLECmd[i])!=0 //инверсные
         )
      {
        for (int k=0; k<(2*DQUADRO); k++) PlusCircleCmd[k] &= ~cmdTmpPLUS[k];//убрать плюсовые
        return 0;
      }//if
    }//for(int i=0; i<8; i++)
    for (int k=0; k<(2*DQUADRO); k++) PlusCircleCmd[k] |= cmdTmpPLUS[k];//добавить плюсовые
        return 1;
}//elementAND()

/**********************************************
МЕНЕДЖЕР РАСШИРЕННОЙ ЛОГИКИ
Логический элемент ИСКЛ ИЛИ
**********************************************/
void elementXOR(int lgm) @ "Fast_function"
{
//XOR
  UNS_32 *cmdTmpPLUS  = &(ArrayWIDELOG[2*DQUADRO*3*lgm +2*DQUADRO+2*DQUADRO]);//командный массив tmpPLUS

   if(elementOR(lgm)) return;//убрать плюсовые если все 0
   if(elementAND(lgm)){
    for (int k=0; k<(2*DQUADRO); k++) PlusCircleCmd[k] &= ~cmdTmpPLUS[k];//убрать плюсовые
    return;
    }//if
    for (int k=0; k<(2*DQUADRO); k++) PlusCircleCmd[k] |= cmdTmpPLUS[k];//добавить плюсовые
}//elementXOR()

void dvUnionMakerLow(UNS_32 selectorDV, UNS_32 *dvUnion) @ "Fast_function"
{
//получить массив dvUnion для мл 16 DV
//сформировать массив  Quadro для DV
 if((selectorDV&1)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV1_SM*DQUADRO+ i];
 }//if

 if((selectorDV&2)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV2_SM*DQUADRO+ i];
 }//if

 if((selectorDV&4)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV3_SM*DQUADRO+ i];
 }//if

 if((selectorDV&8)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV4_SM*DQUADRO+ i];
 }//if

 if((selectorDV&16)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV5_SM*DQUADRO+ i];
 }//if

 if((selectorDV&32)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV6_SM*DQUADRO+ i];
 }//if

 if((selectorDV&64)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV7_SM*DQUADRO+ i];
 }//if

 if((selectorDV&128)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV8_SM*DQUADRO+ i];
 }//if

 if((selectorDV&(128*2))>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV9_SM*DQUADRO+ i];
 }//if

 if((selectorDV&(128*4))>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV10_SM*DQUADRO+ i];
 }//if

 if((selectorDV&(128*8))>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV11_SM*DQUADRO+ i];
 }//if

 if((selectorDV&(128*16))>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV12_SM*DQUADRO+ i];
 }//if

 if((selectorDV&(128*32))>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV13_SM*DQUADRO+ i];
 }//if

 if((selectorDV&(128*64))>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV14_SM*DQUADRO+ i];
 }//if

 if((selectorDV&(128*128))>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV15_SM*DQUADRO+ i];
 }//if

 if((selectorDV&(128*256))>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV16_SM*DQUADRO+ i];
 }//if

}//dvUnionMakerLow(UNS_32 selectorDV, UNS_32 *dvUnion)

void dvUnionMakerMidd(UNS_32 selectorDV, UNS_32 *dvUnion) @ "Fast_function"
{
//получить массив dvUnion для cp 16 DV
//сформировать массив  Quadro для DV
 if((selectorDV&1)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV17_SM*DQUADRO+ i];
 }//if

 if((selectorDV&2)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV18_SM*DQUADRO+ i];
 }//if

 if((selectorDV&4)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV19_SM*DQUADRO+ i];
 }//if

 if((selectorDV&8)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV20_SM*DQUADRO+ i];
 }//if

 if((selectorDV&16)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV21_SM*DQUADRO+ i];
 }//if

 if((selectorDV&32)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV22_SM*DQUADRO+ i];
 }//if

 if((selectorDV&64)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV23_SM*DQUADRO+ i];
 }//if

 if((selectorDV&128)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV24_SM*DQUADRO+ i];
 }//if

 if((selectorDV&(128*2))>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV25_SM*DQUADRO+ i];
 }//if

 if((selectorDV&(128*4))>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV26_SM*DQUADRO+ i];
 }//if

 if((selectorDV&(128*8))>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV27_SM*DQUADRO+ i];
 }//if

 if((selectorDV&(128*16))>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV28_SM*DQUADRO+ i];
 }//if

 if((selectorDV&(128*32))>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV29_SM*DQUADRO+ i];
 }//if

 if((selectorDV&(128*64))>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV30_SM*DQUADRO+ i];
 }//if

 if((selectorDV&(128*128))>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV31_SM*DQUADRO+ i];
 }//if

 if((selectorDV&(128*256))>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV32_SM*DQUADRO+ i];
 }//if

}//dvUnionMakerMidd(UNS_32 selectorDV, UNS_32 *dvUnion)

void dvUnionMakerHi(UNS_32 selectorDV, UNS_32 *dvUnion) @ "Fast_function"
{
//получить массив dvUnion для cp 16 DV
//сформировать массив  Quadro для DV
 if((selectorDV&1)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV33_SM*DQUADRO+ i];
 }//if

 if((selectorDV&2)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV34_SM*DQUADRO+ i];
 }//if

 if((selectorDV&4)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV35_SM*DQUADRO+ i];
 }//if

 if((selectorDV&8)>0){
   for(int i=0; i<DQUADRO; i++) dvUnion[i] |= ArrayRANGIR[DV36_SM*DQUADRO+ i];
 }//if
}//dvUnionMakerHi(UNS_32 selectorDV, UNS_32 *dvUnion)

UNS_32 WorkRangirRele() @ "Fast_function"
{
//исполнить ранжирование реле
  int rele_bdvv1 = 0;//замкнуть реле
//исполнить ранжирование реле
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[RELE1_SM*DQUADRO]))) rele_bdvv1 |= 1;
  else rele_bdvv1 &= ~1;
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[RELE2_SM*DQUADRO]))) rele_bdvv1 |= 2;
  else rele_bdvv1 &= ~2;
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[RELE3_SM*DQUADRO]))) rele_bdvv1 |= 4;
  else rele_bdvv1 &= ~4;
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[RELE4_SM*DQUADRO]))) rele_bdvv1 |= 8;
  else rele_bdvv1 &= ~8;
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[RELE5_SM*DQUADRO]))) rele_bdvv1 |= 16;
  else rele_bdvv1 &= ~16;
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[RELE6_SM*DQUADRO]))) rele_bdvv1 |= 32;
  else rele_bdvv1 &= ~32;
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[RELE7_SM*DQUADRO]))) rele_bdvv1 |= 64;
  else rele_bdvv1 &= ~64;
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[RELE8_SM*DQUADRO]))) rele_bdvv1 |= 128;
  else rele_bdvv1 &= ~128;
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[RELE9_SM*DQUADRO]))) rele_bdvv1 |= (128*2);
  else rele_bdvv1 &= ~(128*2);
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[RELE10_SM*DQUADRO]))) rele_bdvv1 |= (128*4);
  else rele_bdvv1 &= ~(128*4);
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[RELE11_SM*DQUADRO]))) rele_bdvv1 |= (128*8);
  else rele_bdvv1 &= ~(128*8);
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[RELE12_SM*DQUADRO]))) rele_bdvv1 |= (128*16);
  else rele_bdvv1 &= ~(128*16);
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[RELE13_SM*DQUADRO]))) rele_bdvv1 |= (128*32);
  else rele_bdvv1 &= ~(128*32);
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[RELE14_SM*DQUADRO]))) rele_bdvv1 |= (128*64);
  else rele_bdvv1 &= ~(128*64);
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[RELE15_SM*DQUADRO]))) rele_bdvv1 |= (128*128);
  else rele_bdvv1 &= ~(128*128);
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[RELE16_SM*DQUADRO]))) rele_bdvv1 |= (128*256);
  else rele_bdvv1 &= ~(128*256);

  return addReleTrig(rele_bdvv1);//добавить триггер
}//WorkRangirRele()

UNS_32 WorkRangirCDI() @ "Fast_function"
{
//исполнить ранжирование СДИ
  int cdi_bdvv1 = 0;//СДИ
//исполнить ранжирование СДИ
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[CDI1_SM*DQUADRO]))) cdi_bdvv1 |= 1;
  else cdi_bdvv1 &= ~1;
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[CDI2_SM*DQUADRO]))) cdi_bdvv1 |= 2;
  else cdi_bdvv1 &= ~2;
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[CDI3_SM*DQUADRO]))) cdi_bdvv1 |= 4;
  else cdi_bdvv1 &= ~4;
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[CDI4_SM*DQUADRO]))) cdi_bdvv1 |= 8;
  else cdi_bdvv1 &= ~8;
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[CDI5_SM*DQUADRO]))) cdi_bdvv1 |= 16;
  else cdi_bdvv1 &= ~16;
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[CDI6_SM*DQUADRO]))) cdi_bdvv1 |= 32;
  else cdi_bdvv1 &= ~32;
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[CDI7_SM*DQUADRO]))) cdi_bdvv1 |= 64;
  else cdi_bdvv1 &= ~64;
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[CDI8_SM*DQUADRO]))) cdi_bdvv1 |= 128;
  else cdi_bdvv1 &= ~128;
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[CDI9_SM*DQUADRO]))) cdi_bdvv1 |= (128*2);
  else cdi_bdvv1 &= ~(128*2);
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[CDI10_SM*DQUADRO]))) cdi_bdvv1 |= (128*4);
  else cdi_bdvv1 &= ~(128*4);
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[CDI11_SM*DQUADRO]))) cdi_bdvv1 |= (128*8);
  else cdi_bdvv1 &= ~(128*8);
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[CDI12_SM*DQUADRO]))) cdi_bdvv1 |= (128*16);
  else cdi_bdvv1 &= ~(128*16);
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[CDI13_SM*DQUADRO]))) cdi_bdvv1 |= (128*32);
  else cdi_bdvv1 &= ~(128*32);
  if(CheckActualCMD((UNS_32 *)&(ArrayRANGIR[CDI14_SM*DQUADRO]))) cdi_bdvv1 |= (128*64);
  else cdi_bdvv1 &= ~(128*64);

  return addCDItrig(cdi_bdvv1);//добавить триггер
}//WorkRangirCDI()

