#include <stdio.h>
#include <string.h>

#include "bazisdef.h"
#include "getINTERFACE.h"

extern int  isTimeSection;//критическая секция с двойным доступом
extern UNS_32 selectorDVLow;//селекция ДВ активный-неактивный для мл 16 DV
extern UNS_32 selectorDVMidd;//селекция ДВ активный-неактивный для cp 16 DV
extern UNS_32 rele_bdvv1;//селекция реле
extern UNS_32 cdi_bdvv1;//селекция CDI
extern UNS_32 buffInStateINTERFACE;//INTERFACE  In
extern UNS_32 buffOutStateINTERFACE;//INTERFACE Out
extern UNS_32 buffLedStateINTERFACE;//INTERFACE Led
extern UNS_32 buffTrgOutStateINTERFACE;//INTERFACE Trg Out
extern UNS_32 buffTrgLedStateINTERFACE;//INTERFACE Trg Led
extern int ReleTrigger;//тригг реле
extern int CDITrigger;//тригг СДИ
extern UNS_32 buffGruppaUstINTERFACE;//группа уставок
extern UNS_32 GruppaUst;//группа уставок
//ком массив RT INTERFACE
extern UNS_32 buffCmdStateINTERFACE[];//INTERFACE CmdState
extern UNS_32 dataCmdStateINTERFACE[];//INTERFACE CmdState
extern UNS_32 dataTrgCmdStateINTERFACE[];//INTERFACE CmdState
extern UNS_32 buffTrgCmdStateINTERFACE[];//INTERFACE CmdState

long GetCmdState(void *pData) @ "Fast_function"
{
 if(isTimeSection)//критическая секция с двойным доступом
	  memcpy(pData, (void*)buffCmdStateINTERFACE, 24);
 else     memcpy(pData, (void*)dataCmdStateINTERFACE, 24);
  return 3;
}//GetCmdState(void *pData)

long GetTrgCmdState(void *pData) @ "Fast_function"
{
 if(isTimeSection)//критическая секция с двойным доступом
	  memcpy(pData, (void*)buffTrgCmdStateINTERFACE, 24);
 else     memcpy(pData, (void*)dataTrgCmdStateINTERFACE, 24);
  return 3;
}//GetTrgCmdState(void *pData)

long GetInState(void *pvIn) @ "Fast_function"
{
 if(isTimeSection)//критическая секция с двойным доступом
	  memcpy(pvIn, (void*)&buffInStateINTERFACE, 4);
 else {
         UNS_32 dataInStateINTERFACE = selectorDVLow + selectorDVMidd*65536;
	  memcpy(pvIn, (void*)&dataInStateINTERFACE, 4);
      }
  return 3;
}//GetInState(void *pvIn)

long GetOutState(void *pvOut) @ "Fast_function"
{
 if(isTimeSection)//критическая секция с двойным доступом
	  memcpy(pvOut, (void*)&buffOutStateINTERFACE, 4);
 else {
	  memcpy(pvOut, (void*)&rele_bdvv1, 4);
      }
  return 3;
}//GetOutState(void *pvOut)

long GetLedState(void *pvLed) @ "Fast_function"
{
 if(isTimeSection)//критическая секция с двойным доступом
	  memcpy(pvLed, (void*)&buffLedStateINTERFACE, 4);
 else {
	  memcpy(pvLed, (void*)&cdi_bdvv1, 4);
      }
  return 3;
}//GetLedState(void *pvLed)

long GetTrgOutState(void *pvOut) @ "Fast_function"
{
 if(isTimeSection)//критическая секция с двойным доступом
	  memcpy(pvOut, (void*)&buffTrgOutStateINTERFACE, 4);
 else {
	  memcpy(pvOut, (void*)&ReleTrigger, 4);
      }
  return 3;
}//GetTrgOutState(void *pvOut)

long GetTrgLedState(void *pvLed) @ "Fast_function"
{
 if(isTimeSection)//критическая секция с двойным доступом
	  memcpy(pvLed, (void*)&buffTrgLedStateINTERFACE, 4);
 else {
	  memcpy(pvLed, (void*)&CDITrigger, 4);
      }
  return 3;
}//GetTrgLedState(void *pvLed)
long GetCurrSelectorPckpStpmStore(void *pvGust) @ "Fast_function"
{
//~~~     функция  чтения                                                      ~~~~~
//~~~     текущей группы уставок                                               ~~~~~
 if(isTimeSection)//критическая секция с двойным доступом
	  memcpy(pvGust, (void*)&buffGruppaUstINTERFACE, 1);
 else {
	  memcpy(pvGust, (void*)&GruppaUst, 1);
      }
  return 3;
}
