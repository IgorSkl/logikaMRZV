
#include <stdio.h>
#include <string.h>

#include "psuperVisor\supermanager.h"

#include "bazisdef.h"
#include "component\componentdef.h"
#include "psuperVisor\psvisor_helpdef.h"

#include "logictimers\logictimersmac.h"

#include "logictimers\logictimersfnc.h"

#include "..\bazis.h"

#include "toSpeedOptim.h"

#define _HIDE_COMPONENT
#include "WLComponent.c"

extern int GlobalPO1;
extern int GlobalPO2;
extern int GlobalPO3;
extern int GlobalPO4;
extern int GlobalLevelI_ABC[];

extern COMPONENT_OBJ  cnfCOMPONENT[];//конфигурация
extern int  logMassTimer[];
extern int  ENAcmd[];
extern int  spvUSTAVKI[];//текущие уставки супервизора
extern int   WideCmdRTBuffer[];
extern int   tempLog[];
extern int offsetIOCmdPRM1;//смещение для IO PRM1
//неисправность цепей напр
//extern int  isFAILU_COMMON;
//глобальный сброс всех таймеров
extern int  globalTimerReset;
extern int  isRunWL;//исполнение РЛ
extern UNS_32 pActualCMD[];//текущие

void WideLogLogic() @ "Fast_function"
{
//исполнить логика РЛ
 if(isRunWL) return;
 isRunWL=1;//исполнение РЛ
/*
  for (int lgm=0; lgm<8; lgm++) //перебрать все лог элементы
  {
    executeLgm(lgm);//Исполнить логем
  }//for
*/

}//WideLogLogic()

void logicWL(int idxC) @ "Fast_function"
{
//логика компонента
 isRunWL=0;//исполнение РЛ
}//logicWL(int idxC)
