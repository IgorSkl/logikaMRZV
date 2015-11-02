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
#include "virtualMenu\rangmanagerdef.h"
#include "component\componentdef.h"
#include "logictimers\logictimersdef.h"
#include "virtualMenu\systemmenudef.h"
#include "virtualMenu\repozitdef.h"

#include "logictimers\logictimersfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "virtualMenu\rangmanagerfnc.h"
#include "virtualMenu\repozitfnc.h"

#include "psupervisor\psupervisor.h"

#include "toSpeedOptim.h"

#include "..\bazis.h"

extern ELEMENT_RPZ   rpzCOMPONENT[];//репозитарий
extern ELEMENT_RPZ  rpzCOMPONENT_WL[];
extern COMPONENT_OBJ rpzcomponent_obj;//обект компонента для репозитария
extern UNS_32 ArrayRANGIR[];
extern UNS_32 ArrayWIDELOG[];
extern int  elTrgOldTimer[];
extern int  elTrgOutTimer[];
//лог массив запуска таймеров
extern int  logMassTimer[];

extern int  elTrgOldTimer_WL[];
extern int  elTrgOutTimer_WL[];
//лог массив запуска таймеров
extern int  logMassTimer_WL[];
extern int  timerEnableWL;//разрешение работы таймеров РЛ

//конфигурация
COMPONENT_OBJ        cnfCOMPONENT[MAX_CNFCOMPONENT];
//конфигурация РЛ
COMPONENT_OBJ        cnfCOMPONENT_WL[MAX_WLCOMPONENT];
//теневой массив
IONAMESTATUS_RANGIR  common_shadow[SIZE_RANGIRCMD+SIZE_RANGIRCMD+2];

//текущие уставки супервизора
int    spvUSTAVKI[MAX_SPVUSTAVKI];
//текущие уставки супервизора РЛ
int    spvUSTAVKI_WL[MAX_SPVUSTAVKI_WL];
//temp логика
int   tempLog[MAX_TEMPLOG];
//temp логика РЛ
int   tempLog_WL[MAX_TEMPLOG_WL];
//ENA команды
int   ENAcmd[MAX_ENACMD];
//ENA команды РЛ
int   ENAcmd_WL[MAX_ENACMD_WL];

int  IndexTIMERS;//таймерный индекс
int  IndexIO;//индекс IO
int  IndexUstSPV;//индекс уставок в супервизоре
int  IndexTLog;//индекс temp логики
int  IndexENA;//индекс ENA команд
UNS_32 maskaReleBO;
UNS_32 maskaReleBV;

//неисправность цепей напр 
int  isFAILU_COMMON_MTZ;
int  isFAILU_COMMON_DZ;
int  isFAILU_DZ;
//напр UCM меньше UCM005
//int  isFAILUCM005_COMMON;
//ток ICM  меньше ICM005
//int  isFAILICM005_COMMON;
//допуски ДВ обработки
int  ddv_inc[DV_TOTAL];
int  ddv_fix[DV_TOTAL];

/**********************************************
СУПЕРВИЗОР
Инициализация уставок компонентов из конфиг
total - INITUST_NULLCOMP-ни одного
        INITUST_TOPCOMP-инит верхний комп
**********************************************/
void INITustrangCOMPONENT(short total)
{
  short result = 0;
  short next   = 0;
  short tmp = 0;
  short tmpCntUst = 0;
  cnfCOMPONENT[0].offsetUstMng = 0;//смещение уставок внутри менеджера уст
  IndexUstSPV  = 0;//индекс уставок в супервизоре

  while (cnfCOMPONENT[next].componentEnable)   //все компоненты в конфигурации
  {
    cnfCOMPONENT[next].offsetUstSpv = IndexUstSPV;//смещение уставок супервизора
    switch(total)
    {
    case INITUST_TOPCOMP:   //инит верхний комп
    {
      if(next==0)
      {
        tmpCntUst = cnfCOMPONENT[next].cntUstMng = cnfCOMPONENT[next].initUstMng(1);
        if(tmpCntUst>0)MngUstTopAddUSTAVKI(tmpCntUst);//добавить уставки на вершину mngUst
        MngRangTopAddNameStatusRANGIR(cnfCOMPONENT[next].cntIOCmd, cnfCOMPONENT[next].nameStatusIO);//добавить команды на вершину mngRang
        tmp = cnfCOMPONENT[next].cntTLCmd;
        if(tmp>0)TopAddTEMPLOGIC(tmp);//добавить TL log на вершину tempLog
        tmp = cnfCOMPONENT[next].cntENACmd;
        if(tmp>0)TopAddENACmd(tmp);//добавить ENA на вершину
        for(short i=0; i<UVV_TOTAL; i++)
        {
          MngRangTopAddQuadroRANGIR(&(ArrayRANGIR[i*DQUADRO]), cnfCOMPONENT[next].cntIOCmd);
        }//for
      }//if
      else
        //уставки не инициализировать
        tmpCntUst = cnfCOMPONENT[next].cntUstMng = cnfCOMPONENT[next].initUstMng(0);
    }//case
    break;

//    case  INITUST_NULLCOMP:
      //уставки не инициализировать
  //    tmpCnt = cnfCOMPONENT[next].cntUstMng = cnfCOMPONENT[next].initUstMng(0);
    //  break;

    default:
      //уставки не инициализировать
      tmpCntUst = cnfCOMPONENT[next].cntUstMng = cnfCOMPONENT[next].initUstMng(0);

    }//switch

    result += tmpCntUst;//смещение внутри менеджера уст
    if(cnfCOMPONENT[next+1].componentEnable)
      cnfCOMPONENT[next+1].offsetUstMng = result;//смещение внутри менеджера уст
    next++;
  }//while
}//INITustCOMPONENT(short total)

/**********************************************
СУПЕРВИЗОР
Инициализация уставок компонентов из конфиг РЛ
total - INITUST_NULLCOMP-ни одного
        INITUST_TOPCOMP-инит верхний комп
**********************************************/
void INITustrangCOMPONENT_WL(short total)
{
  short result = 0;
  short next   = 0;
  short tmpCnt = 0;
  cnfCOMPONENT_WL[0].offsetUstMng = 0;//смещение уставок внутри менеджера уст
  IndexUstSPV  = 0;//индекс уставок в супервизоре

  while (cnfCOMPONENT_WL[next].componentEnable)   //все компоненты в конфигурации
  {
    cnfCOMPONENT_WL[next].offsetUstSpv = IndexUstSPV;//смещение уставок супервизора
    switch(total)
    {
    case INITUST_TOPCOMP:   //инит верхний комп
    {
      if(next==0)
      {
        tmpCnt = cnfCOMPONENT_WL[next].cntUstMng = cnfCOMPONENT_WL[next].initUstMng(1);
        if(tmpCnt>0)MngUstTopAddUSTAVKI_WL(tmpCnt);//добавить уставки на вершину mngUst
        //добавить имена команд на вершину 
        MngRangTopAddNameStatusRANGIR_WL(cnfCOMPONENT_WL[next].cntIOCmd, cnfCOMPONENT_WL[next].nameStatusIO);
        tmpCnt = cnfCOMPONENT_WL[next].cntTLCmd;
        if(tmpCnt>0)TopAddTEMPLOGIC_WL(tmpCnt);//добавить TL log на вершину tempLog
        tmpCnt = cnfCOMPONENT_WL[next].cntENACmd;
        if(tmpCnt>0)TopAddENACmd_WL(tmpCnt);//добавить ENA на вершину
        //пересчитать PRM MINUS PLUS
        for(short i=0; i<3*LE_TOTAL; i++)
        {
          //вторая половина 2*DQUADRO от PRM MINUS PLUS
          MngRangTopAddQuadroRANGIR(&(ArrayWIDELOG[i*2*DQUADRO +DQUADRO]), cnfCOMPONENT_WL[next].cntIOCmd);
        }//for
      }//if
      else
        //уставки не инициализировать
        tmpCnt = cnfCOMPONENT_WL[next].cntUstMng = cnfCOMPONENT_WL[next].initUstMng(0);
    }//case
    break;

//    case  INITUST_NULLCOMP:
      //уставки не инициализировать
  //    tmpCnt = cnfCOMPONENT[next].cntUstMng = cnfCOMPONENT[next].initUstMng(0);
    //  break;

    default:
      //уставки не инициализировать
      tmpCnt = cnfCOMPONENT_WL[next].cntUstMng = cnfCOMPONENT_WL[next].initUstMng(0);

    }//switch

    result += tmpCnt;//смещение внутри менеджера уст
    if(cnfCOMPONENT_WL[next+1].componentEnable)
      cnfCOMPONENT_WL[next+1].offsetUstMng = result;//смещение внутри менеджера уст
    next++;
  }//while
}//INITustCOMPONENT_WL(short total)

/**********************************************
СУПЕРВИЗОР
Инициализация IO команд компонентов из конфиг
**********************************************/
void INITIOCmdCOMPONENT()
{
  IndexIO     = 0;//IO индекс
  short tmp = 0;
  while (cnfCOMPONENT[tmp].componentEnable)
  {
    cnfCOMPONENT[tmp].offsetIOCmd = IndexIO;//смещение IO
    cnfCOMPONENT[tmp].cntIOCmd = cnfCOMPONENT[tmp].initIOCmd();//к-во IO
    tmp++;
  }//while
}//INITIOCmdCOMPONENT()

/**********************************************
СУПЕРВИЗОР
Инициализация IO команд компонентов из конфиг РЛ
**********************************************/
void INITIOCmdCOMPONENT_WL()
{
  IndexIO     = 0;//IO индекс
  short tmp = 0;
  while (cnfCOMPONENT_WL[tmp].componentEnable)
  {
    cnfCOMPONENT_WL[tmp].offsetIOCmd = IndexIO;//смещение IO
    cnfCOMPONENT_WL[tmp].cntIOCmd = cnfCOMPONENT_WL[tmp].initIOCmd();//к-во IO
    tmp++;
  }//while
}//INITIOCmdCOMPONENT_WL()

/**********************************************
СУПЕРВИЗОР
Инициализация TL команд компонентов из конфиг
**********************************************/
void INITTLCmdCOMPONENT()
{
  IndexTLog     = 0;//TL индекс
  short tmp = 0;
  while (cnfCOMPONENT[tmp].componentEnable)
  {
    cnfCOMPONENT[tmp].offsetTLCmd = IndexTLog;
    cnfCOMPONENT[tmp].cntTLCmd = cnfCOMPONENT[tmp].initTLCmd();
    tmp++;
  }//while
}//INITTLCmdCOMPONENT()

/**********************************************
СУПЕРВИЗОР
Инициализация TL команд компонентов из конфиг РЛ
**********************************************/
void INITTLCmdCOMPONENT_WL()
{
  IndexTLog     = 0;//TL индекс
  short tmp = 0;
  while (cnfCOMPONENT_WL[tmp].componentEnable)
  {
    cnfCOMPONENT_WL[tmp].offsetTLCmd = IndexTLog;
    cnfCOMPONENT_WL[tmp].cntTLCmd = cnfCOMPONENT_WL[tmp].initTLCmd();
    tmp++;
  }//while
}//INITTLCmdCOMPONENT_WL()

/**********************************************
СУПЕРВИЗОР
Инициализация ENA команд компонентов из конфиг
**********************************************/
void INITENACmdCOMPONENT()
{
  IndexENA  = 0;//ENA индекс
  short tmp = 0;
  while (cnfCOMPONENT[tmp].componentEnable)
  {
    cnfCOMPONENT[tmp].offsetENACmd = IndexENA;
    cnfCOMPONENT[tmp].cntENACmd = cnfCOMPONENT[tmp].initENACmd();
    tmp++;
  }//while
}//INITENACmdCOMPONENT()

/**********************************************
СУПЕРВИЗОР
Инициализация ENA команд компонентов из конфиг РЛ
**********************************************/
void INITENACmdCOMPONENT_WL()
{
  IndexENA  = 0;//ENA индекс
  short tmp = 0;
  while (cnfCOMPONENT_WL[tmp].componentEnable)
  {
    cnfCOMPONENT_WL[tmp].offsetENACmd = IndexENA;
    cnfCOMPONENT_WL[tmp].cntENACmd = cnfCOMPONENT_WL[tmp].initENACmd();
    tmp++;
  }//while
}//INITENACmdCOMPONENT_WL()

/**********************************************
СУПЕРВИЗОР
Подготовка уставок супервизора для комп из конфиг
**********************************************/
void PREPAREustCOMPONENT(short total)
{
  short next = 0;
  setTimerENABLE(0 ,0);//bazisTimerMem[0].ENABLE = 0;//запретить лог таймера
  while (cnfCOMPONENT[next].componentEnable)   //все компоненты в конфигурации
  {
    switch(total)
    {
    case INITUST_ALLCOMP:   //Подготовка уставок все комп
        {
        cnfCOMPONENT[next].prepareUstSpv(next);
        }
        break;

//    case  INITUST_NULLCOMP:
      //уставки не инициализировать
  //    break;
    default:
      ;
    }//switch
    next++;
  }//while

  //переопределить уставки конкр компонента
  if(total>=INITUST_TOPCOMP)
  {
    cnfCOMPONENT[total].prepareUstSpv(total);
    //Инициализация таймеров всех компонентов из конфиг
  }//if

}//PREPAREustCOMPONENT()

/**********************************************
СУПЕРВИЗОР
Подготовка уставок супервизора для комп из конфиг РЛ
**********************************************/
void PREPAREustCOMPONENT_WL(short total)
{
  short next = 0;
  setTimerENABLE_WL(0 ,0);//bazisTimerMem[0].ENABLE = 0;//запретить лог таймера РЛ
  while (cnfCOMPONENT_WL[next].componentEnable)   //все компоненты в конфигурации
  {
    switch(total)
    {
    case INITUST_ALLCOMP:   //Подготовка уставок все комп
        {
        cnfCOMPONENT_WL[next].prepareUstSpv(-next-1);
        }
        break;

//    case  INITUST_NULLCOMP:
      //уставки не инициализировать
  //    break;
    default:
      ;
    }//switch
    next++;
  }//while

  //переопределить уставки конкр компонента
  if(total>=INITUST_TOPCOMP)
  {
    cnfCOMPONENT_WL[total].prepareUstSpv(-total-1);
    //Инициализация таймеров всех компонентов из конфиг
  }//if

}//PREPAREustCOMPONENT_WL()

/**********************************************
СУПЕРВИЗОР
Добавить компонент в конфигурацию
numK - код компонента
**********************************************/
void addCOMPONENT(short numK)
{
//массив клонов - конфигурация
  short rpzOffset = GetOffsetClonRpz(numK);//получить смещение репозитария по коду компонента

  LIGHTISDENIE = 0;//запрещено
  LIGHTISPACKET = 0;//это пакет
//копировать в тень
  memcpy((void*)getShadowBuf(), cnfCOMPONENT, sizeof(COMPONENT_OBJ)*MAX_CNFCOMPONENT);
  //создать новый клон
  char isPacket = rpzCOMPONENT[rpzOffset].load2RPZ(0);//зарегистрировать в репозитарии
  if(isPacket)
  {
    LIGHTISDENIE = 0;//запрещено
    LIGHTISPACKET = 1;//это пакет
    return;// 1;//уйти если пакетная регистрация
  }//if

  //искать в конфигурации клон компонента
  short i=0;
  short numC=0;

  while(cnfCOMPONENT[i].componentEnable) //все клоны из конфиг
  {
    if(cnfCOMPONENT[i].kodC == rpzcomponent_obj.kodC) numC++;
    i++;
  }//while

  if(numC>0 && rpzcomponent_obj.cntClon == 1)
  {
    LIGHTISPACKET = 0;//это пакет
    LIGHTISDENIE = 1;//запрещено
    return;// 1;//разрешен только 1 клон
  }//if
  if(numC>0 && rpzcomponent_obj.cntClon == numC)
  {
    LIGHTISPACKET = 0;//это пакет
    LIGHTISDENIE = 1;//запрещено
    return;//разрешен только numClon клон
  }//if

  memcpy(&(cnfCOMPONENT[0]), &rpzcomponent_obj, sizeof(COMPONENT_OBJ));

//копировать из тени
  memcpy(&(cnfCOMPONENT[1]), (void*)getShadowBuf(), sizeof(COMPONENT_OBJ)*(MAX_CNFCOMPONENT-1));

}//addCOMPONENT

/**********************************************
СУПЕРВИЗОР
Добавить компонент в конфигурацию РЛ
numK - код компонента
**********************************************/
void addCOMPONENT_WL(short numK)
{
//массив клонов - конфигурация
  short rpzOffset = GetOffsetClonRpzWL(numK);//получить смещение репозитария РЛ по коду компонента

  LIGHTISDENIE = 0;//запрещено
  LIGHTISPACKET = 0;//это пакет
//копировать в тень
  memcpy((void*)getShadowBuf(), cnfCOMPONENT_WL, sizeof(COMPONENT_OBJ)*MAX_WLCOMPONENT);
  //создать новый клон
  char isPacket = rpzCOMPONENT_WL[rpzOffset].load2RPZ(0);//зарегистрировать в репозитарии РЛ
  if(isPacket)
  {
    LIGHTISDENIE = 0;//запрещено
    LIGHTISPACKET = 1;//это пакет
    return;// 1;//уйти если пакетная регистрация
  }//if

  //искать в конфигурации клон компонента
  short i=0;
  short numC=0;

  while(cnfCOMPONENT_WL[i].componentEnable) //все клоны из конфиг
  {
    if(cnfCOMPONENT_WL[i].kodC == rpzcomponent_obj.kodC) numC++;
    i++;
  }//while

  if(numC>0 && rpzcomponent_obj.cntClon == 1)
  {
    LIGHTISPACKET = 0;//это пакет
    LIGHTISDENIE = 1;//запрещено
    return;// 1;//разрешен только 1 клон
  }//if
  if(numC>0 && rpzcomponent_obj.cntClon == numC)
  {
    LIGHTISPACKET = 0;//это пакет
    LIGHTISDENIE = 1;//запрещено
    return;//разрешен только numClon клон
  }//if

  memcpy(&(cnfCOMPONENT_WL[0]), &rpzcomponent_obj, sizeof(COMPONENT_OBJ));

//копировать из тени
  memcpy(&(cnfCOMPONENT_WL[1]), (void*)getShadowBuf(), sizeof(COMPONENT_OBJ)*(MAX_WLCOMPONENT-1));

}//addCOMPONENT_WL

/**********************************************
СУПЕРВИЗОР
Инициализировать компонент в конфигурации
total - INITUST_TOPCOMP-только верхний INITUST_ALLCOMP-все
        INITUST_NULLCOMP-ни одного
**********************************************/
void initCOMPONENT(short total)
{
  INITIOCmdCOMPONENT();//СУПЕРВИЗОР Иниц IO команд компонентов из конфиг
  INITTLCmdCOMPONENT();//СУПЕРВИЗОР Иниц TL команд компонентов из конфиг
  INITustrangCOMPONENT(total);//СУПЕРВИЗОР Инициализация mngUst mngRang компонентов из конфиг
  INITENACmdCOMPONENT();//СУПЕРВИЗОР  Инициализация ENA команд компонентов из конфиг
}//initCOMPONENT(short total)

/**********************************************
СУПЕРВИЗОР
Инициализировать компонент в конфигурации РЛ
total - INITUST_TOPCOMP-только верхний INITUST_ALLCOMP-все
        INITUST_NULLCOMP-ни одного
**********************************************/
void initCOMPONENT_WL(short total)
{
  INITIOCmdCOMPONENT_WL();//СУПЕРВИЗОР Иниц IO команд компонентов из конфиг РЛ
  INITTLCmdCOMPONENT_WL();//СУПЕРВИЗОР Иниц TL команд компонентов из конфиг РЛ
  INITustrangCOMPONENT_WL(total);//СУПЕРВИЗОР Инициализация mngUst mngRang компонентов из конфиг РЛ
  INITENACmdCOMPONENT_WL();//СУПЕРВИЗОР  Инициализация ENA команд компонентов из конфиг РЛ
}//initCOMPONENT_WL(short total)

/**********************************************
СУПЕРВИЗОР
удалить cntC клонов начиная с подсвеченного клона
**********************************************/
void deleteCOMPONENT(short cntC)
{
//удалить клон компонента
  short  offsetUstMng = cnfCOMPONENT[LIGHTCLON].offsetUstMng;  //смещение уставок внутри менеджера уставок
  short  offsetRangIO = getOffsetIOCmdCnf(LIGHTCLON);   //смещение команд IO
  short  offsetTL     = getOffsetTLCmdCnf(LIGHTCLON);   //смещение команд TL
  short  offsetENA    = getOffsetENACmdCnf(LIGHTCLON);  //смещение команд ENA
//найти к-во уставок ранж и TL log для удаления
  short  cntUstMng  = 0;
  short  cntRangMng = 0;
  short  cntTL      = 0;
  short  cntENA     = 0;
  for(short i=0; i<cntC; i++)
  {
    cntUstMng  += cnfCOMPONENT[LIGHTCLON+i].cntUstMng;    //количество уставок компонента внутри менеджера уставок
    cntRangMng += cnfCOMPONENT[LIGHTCLON+i].cntIOCmd;     //количество команд IO
    cntTL      += cnfCOMPONENT[LIGHTCLON+i].cntTLCmd;     //количество команд TL
    cntENA     += cnfCOMPONENT[LIGHTCLON+i].cntENACmd;    //количество команд ENA
  }//for

//массив клонов - конфигурация
//копировать в тень
  memcpy((void*)getShadowBuf(), cnfCOMPONENT, sizeof(COMPONENT_OBJ)*MAX_CNFCOMPONENT);
//копировать из тени Begin
  if(LIGHTCLON>0)
    memcpy(cnfCOMPONENT, (void*)getShadowBuf(), sizeof(COMPONENT_OBJ)*(LIGHTCLON));
//копировать из тени End
  memcpy(&(cnfCOMPONENT[LIGHTCLON]),
         &(((COMPONENT_OBJ *)getShadowBuf())[LIGHTCLON+ cntC]),
         sizeof(COMPONENT_OBJ)*(MAX_CNFCOMPONENT-LIGHTCLON- cntC));

  if(cntUstMng>0)MngUstDeleteUSTAVKI(offsetUstMng, cntUstMng);//удалить уставки из mngUst
  MngRangDeleteNameStatusRANGIR(offsetRangIO, cntRangMng);//удалить команды
  if(cntTL>0)DeleteTEMPLOGIC(offsetTL, cntTL);
  if(cntENA>0)DeleteENACmd(offsetENA, cntENA);
  for(short i=0; i<UVV_TOTAL; i++)
  {
    MngRangDeleteQuadroRANGIR(&(ArrayRANGIR[i*DQUADRO]), offsetRangIO, cntRangMng);//удалить команды из Quadro
  }//for

  initCOMPONENT(INITUST_NULLCOMP);//уставки не инициализировать
}//deleteCOMPONENT()

/**********************************************
СУПЕРВИЗОР
удалить из РЛ cntC клонов начиная с подсвеченного клона
**********************************************/
void deleteCOMPONENT_WL(short cntC)
{
//удалить клон компонента
  short  offsetUstMng = cnfCOMPONENT_WL[LIGHTCLON].offsetUstMng;  //смещение уставок внутри менеджера уставок
  short  offsetRangIO = getOffsetIOCmdCnf_WL(LIGHTCLON);   //смещение команд IO
  short  offsetTL     = getOffsetTLCmdCnf_WL(LIGHTCLON);   //смещение команд TL
  short  offsetENA    = getOffsetENACmdCnf_WL(LIGHTCLON);  //смещение команд ENA
//найти к-во уставок ранж и TL log для удаления
  short  cntUstMng  = 0;
  short  cntRangMng = 0;
  short  cntTL      = 0;
  short  cntENA     = 0;
  for(short i=0; i<cntC; i++)
  {
    cntUstMng  += cnfCOMPONENT_WL[LIGHTCLON+i].cntUstMng;    //количество уставок компонента внутри менеджера уставок
    cntRangMng += cnfCOMPONENT_WL[LIGHTCLON+i].cntIOCmd;     //количество команд IO
    cntTL      += cnfCOMPONENT_WL[LIGHTCLON+i].cntTLCmd;     //количество команд TL
    cntENA     += cnfCOMPONENT_WL[LIGHTCLON+i].cntENACmd;    //количество команд ENA
  }//for

//массив клонов - конфигурация
//копировать в тень
  memcpy((void*)getShadowBuf(), cnfCOMPONENT_WL, sizeof(COMPONENT_OBJ)*MAX_WLCOMPONENT);
//копировать из тени Begin
  if(LIGHTCLON>0)
    memcpy(cnfCOMPONENT_WL, (void*)getShadowBuf(), sizeof(COMPONENT_OBJ)*(LIGHTCLON));
//копировать из тени End
  memcpy(&(cnfCOMPONENT_WL[LIGHTCLON]),
         &(((COMPONENT_OBJ *)getShadowBuf())[LIGHTCLON+ cntC]),
         sizeof(COMPONENT_OBJ)*(MAX_WLCOMPONENT-LIGHTCLON- cntC));

  if(cntUstMng>0)MngUstDeleteUSTAVKI_WL(offsetUstMng, cntUstMng);//удалить уставки из mngUst
  MngRangDeleteNameStatusRANGIR_WL(offsetRangIO, cntRangMng);//удалить команды
  if(cntTL>0)DeleteTEMPLOGIC_WL(offsetTL, cntTL);
  if(cntENA>0)DeleteENACmd_WL(offsetENA, cntENA);

  initCOMPONENT_WL(INITUST_NULLCOMP);//уставки не инициализировать
}//deleteCOMPONENT_WL()

void * getShadowBuf()
{
  //адрес теневого массива
  return &(common_shadow[0]);
}//getShadowBuf()

void TopAddTEMPLOGIC(short cntTL)
{
//добавить TL log на вершину tempLog
  //копировать tempLog в тень
  memcpy((void*)getShadowBuf(), tempLog, 4*MAX_TEMPLOG);
  //копировать из тени
  memcpy(&(tempLog[cntTL]), (void*)getShadowBuf(),
         (4*MAX_TEMPLOG-4*cntTL));
  //обнулить
  memset(tempLog, 0, 4*cntTL);
}//TopAddTEMPLOGIC()

void TopAddTEMPLOGIC_WL(short cntTL)
{
//добавить TL log на вершину tempLog_WL
  //копировать tempLog_WL в тень
  memcpy((void*)getShadowBuf(), tempLog_WL, 4*MAX_TEMPLOG_WL);
  //копировать из тени
  memcpy(&(tempLog_WL[cntTL]), (void*)getShadowBuf(),
         (4*MAX_TEMPLOG_WL-4*cntTL));
  //обнулить
  memset(tempLog_WL, 0, 4*cntTL);
}//TopAddTEMPLOGIC_WL()

void TopAddENACmd(short cntENA)
{
//добавить ENA на вершину ENAcmd
  //копировать tempLog в тень
  memcpy((void*)getShadowBuf(), ENAcmd, 4*MAX_ENACMD);
  //копировать из тени
  memcpy(&(ENAcmd[cntENA]), (void*)getShadowBuf(),
         (4*MAX_ENACMD-4*cntENA));
  //обнулить
  memset(ENAcmd, 0, 4*cntENA);
}//TopAddENACmd(short cntENA)

void TopAddENACmd_WL(short cntENA)
{
//добавить ENA на вершину ENAcmd
  //копировать в тень
  memcpy((void*)getShadowBuf(), ENAcmd_WL, 4*MAX_ENACMD_WL);
  //копировать из тени
  memcpy(&(ENAcmd_WL[cntENA]), (void*)getShadowBuf(),
         (4*MAX_ENACMD_WL-4*cntENA));
  //обнулить
  memset(ENAcmd_WL, 0, 4*cntENA);
}//TopAddENACmd_WL(short cntENA)

void DeleteTEMPLOGIC(short offsetTL, short cntTL)
{
//удалить команды TL log
  //копировать широкий ком массив в тень
  memcpy((void*)getShadowBuf(), tempLog, 4*MAX_TEMPLOG);
//копировать из тени Begin
  if(offsetTL>0)
    memcpy(tempLog, (void*)getShadowBuf(), 4*offsetTL);
//копировать из тени End
  memcpy(&(tempLog[offsetTL]),
         &(((char *)getShadowBuf())[4*offsetTL+4*cntTL]),
         (4*MAX_TEMPLOG-4*offsetTL-4*cntTL));
}//DeleteTEMPLOGIC(short offsetTL, short cntTL)

void DeleteTEMPLOGIC_WL(short offsetTL, short cntTL)
{
//удалить команды TL log РЛ
  //копировать широкий ком массив в тень
  memcpy((void*)getShadowBuf(), tempLog_WL, 4*MAX_TEMPLOG_WL);
//копировать из тени Begin
  if(offsetTL>0)
    memcpy(tempLog_WL, (void*)getShadowBuf(), 4*offsetTL);
//копировать из тени End
  memcpy(&(tempLog_WL[offsetTL]),
         &(((char *)getShadowBuf())[4*offsetTL+4*cntTL]),
         (4*MAX_TEMPLOG_WL-4*offsetTL-4*cntTL));
}//DeleteTEMPLOGIC_WL(short offsetTL, short cntTL)

void DeleteENACmd(short offsetENA, short cntENA)
{
//удалить команды ENA cmd
  //копировать ENA cmd в тень
  memcpy((void*)getShadowBuf(), ENAcmd, 4*MAX_ENACMD);
//копировать из тени Begin
  if(offsetENA>0)
    memcpy(ENAcmd, (void*)getShadowBuf(), 4*offsetENA);
//копировать из тени End
  memcpy(&(ENAcmd[offsetENA]),
         &(((char *)getShadowBuf())[4*offsetENA+4*cntENA]),
         (4*MAX_ENACMD-4*offsetENA-4*cntENA));
}//DeleteENACmd(short offsetENA, short cntENA)

void DeleteENACmd_WL(short offsetENA, short cntENA)
{
//удалить команды ENA cmd
  //копировать ENA cmd в тень
  memcpy((void*)getShadowBuf(), ENAcmd_WL, 4*MAX_ENACMD_WL);
//копировать из тени Begin
  if(offsetENA>0)
    memcpy(ENAcmd_WL, (void*)getShadowBuf(), 4*offsetENA);
//копировать из тени End
  memcpy(&(ENAcmd_WL[offsetENA]),
         &(((char *)getShadowBuf())[4*offsetENA+4*cntENA]),
         (4*MAX_ENACMD_WL-4*offsetENA-4*cntENA));
}//DeleteENACmd_WL(short offsetENA, short cntENA)

/**********************************************
СУПЕРВИЗОР
Инициализация таймеров всех компонентов из конфиг
**********************************************/
void INITtimersCOMPONENT()
{
  //запретить лог таймера
  setTimerENABLE(0 ,0);
// clearTimerLogBuffer
  memset(elTrgOldTimer,0,4*MAX_LOGTIMER);//EL триггера
  memset(elTrgOutTimer,0,4*MAX_LOGTIMER);//EL триггера
  memset(logMassTimer, 0,4*MAX_LOGTIMER);//массив запуска

  IndexTIMERS = 0;//таймерный индекс
  short tmp = 0;
  while (cnfCOMPONENT[tmp].componentEnable)
  {
    cnfCOMPONENT[tmp].offsetTimers = IndexTIMERS;
    cnfCOMPONENT[tmp].initTimers(tmp);
    tmp++;
  }//while
  setTimerENABLE(IndexTIMERS ,0);//запр последний таймер
}//INITtimersCOMPONENT()

/**********************************************
СУПЕРВИЗОР
Инициализация таймеров всех компонентов из конфиг РЛ
**********************************************/
void INITtimersCOMPONENT_WL()
{
  setTimerENABLE_WL(0 ,0);
// clearTimerLogBuffer
  memset(elTrgOldTimer_WL,0,4*MAX_LOGTIMER_WL);//EL триггера
  memset(elTrgOutTimer_WL,0,4*MAX_LOGTIMER_WL);//EL триггера
  memset(logMassTimer_WL, 0,4*MAX_LOGTIMER_WL);//массив запуска

  timerEnableWL = 0;//разрешение работы таймеров РЛ
  IndexTIMERS = 0;//таймерный индекс
  short tmp = 0;
  while (cnfCOMPONENT_WL[tmp].componentEnable)
  {
    cnfCOMPONENT_WL[tmp].offsetTimers = IndexTIMERS;
    cnfCOMPONENT_WL[tmp].initTimers(-tmp-1);
    tmp++;
  }//while
  setTimerENABLE_WL(IndexTIMERS ,0);//запр последний таймер
}//INITtimersCOMPONENT()

int getOffsetTimersCnf(int off)
{
//таймера компонента в конфигурации
  return cnfCOMPONENT[off].offsetTimers;   
}//getOffsetTimersCnf(int off)

int getOffsetTimersCnf_WL(int off)
{
//таймера компонента в конфигурации
  return cnfCOMPONENT_WL[-off-1].offsetTimers;   
}//getOffsetTimersCnf(int off)

int getOffsetIOCmdCnf(int off)
{
 //IO команды
 return cnfCOMPONENT[off].offsetIOCmd;   
}//getOffsetIOCmdCnf(int off)

int getOffsetIOCmdCnf_WL(int off)
{
 //IO команды
 return cnfCOMPONENT_WL[off].offsetIOCmd;   
}//getOffsetIOCmdCnf_WL(int off)

int getOffsetENACmdCnf(int off)
{
//ENA команды
  return cnfCOMPONENT[off].offsetENACmd;    
}//getOffsetENACmdCnf(int off)

int getOffsetENACmdCnf_WL(int off)
{
//ENA команды РЛ
  return cnfCOMPONENT_WL[off].offsetENACmd;    
}//getOffsetENACmdCnf_WL(int off)

int getOffsetTLCmdCnf(int off)
{
//TL команды
  return cnfCOMPONENT[off].offsetTLCmd;    
}//getOffsetTLCmdCnf(int off)

int getOffsetTLCmdCnf_WL(int off)
{
//TL команды
  return cnfCOMPONENT_WL[off].offsetTLCmd;    
}//getOffsetTLCmdCnf_WL(int off)

int getOffsetSPVUstCnf(int off)
{
//уставки SPV
  return cnfCOMPONENT[off].offsetUstSpv;    
}//getOffsetSPVUstCnf(int off)
