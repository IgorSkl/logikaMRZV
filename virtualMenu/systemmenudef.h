
#include "virtualMenu\textstreamdef.h"

//к-во строчек в меню
#define SIZE_PAGE_VIEW 4
//индекс данных в sub_menu
#define SUBDATA 1
//текущий текстовый поток
#define PNTCRR_TEXTSTREAM ((StreamControl *)menu_context.controlStruct_crr)
#define CRR_TEXTSTREAM    menu_context.controlStruct_crr
//текущее субменю
#define CRR_SUBMENU          menu_context.lsubmenu_crr
#define PNTCRR_SUBMENU(idx)  ((LineMenuItem *)menu_context.lsubmenu_crr)[idx]
//ф-ция HOME
#define CRR_FHOME            menu_context.pFncGlobal
//ф-ция PassUst
#define CRR_FPASSWORD        menu_context.pFPassWord
//контроль меню компонента
#define CONTROL1_COMP        menu_context.controlStruct_c1
#define CONTROL2_COMP        menu_context.controlStruct_c2
#define CONTROLWL_COMP       menu_context.controlStruct_WL
//контроль главное меню
#define CONTROL_MAIN         menu_context.controlStruct_main
//контроль конфигурация
#define CONTROL_CNF          menu_context.controlStruct_cnf
//контроль конфигурация РЛ
#define CONTROL_CNFWL        menu_context.controlStruct_cnfwl
//контроль настройка
#define CONTROL_CNTR         menu_context.controlStruct_cntr
//контроль DV
#define CONTROL_DV           menu_context.controlStruct_viewDV
//контроль RELE
#define CONTROL_RELE         menu_context.controlStruct_viewRele
//контроль CDI
#define CONTROL_CDI          menu_context.controlStruct_viewCDI
//контроль расш лог
#define CONTROL_WDL          menu_context.controlStruct_widel
//контроль для массива строк
#define CONTROL_STR          menu_context.controlStruct_str
#define PNTCONTROL_STR       ((StreamControl *)&(menu_context.controlStruct_str))

//контроль текущие
#define CONTROL_ACT          menu_context.controlStruct_tmp1
//контроль регистрация ДИС
#define CONTROL_RDIS         menu_context.controlStruct_tmp1
//контроль APV
#define CONTROL_APV          menu_context.controlStruct_tmp1
//контроль UROV
#define CONTROL_UROV         menu_context.controlStruct_tmp1
//контроль P1OF
#define CONTROL_P1OF         menu_context.controlStruct_tmp1
//контроль P2OF
#define CONTROL_P2OF         menu_context.controlStruct_tmp1
//контроль P3OF
#define CONTROL_P3OF         menu_context.controlStruct_tmp1
//контроль дискр регистратор
#define CONTROL_DIS          menu_context.controlStruct_tmp1
//контроль уставок ДВ
#define CONTROL_UDV          menu_context.controlStruct_tmp1
//контроль уставок реле
#define CONTROL_URELE        menu_context.controlStruct_tmp1
//контроль уставок СДИ
#define CONTROL_UCDI         menu_context.controlStruct_tmp1
//контроль просмотр ранжир
#define CONTROL_VRNG         menu_context.controlStruct_tmp1
//контроль Репозитария
#define CONTROL_RPZ          menu_context.controlStruct_tmp1

//контроль редакт РЛ
#define CONTROL_EWL          menu_context.controlStruct_tmp2
//контроль УВВ
#define CONTROL_UVV          menu_context.controlStruct_tmp2

//контроль тип ЛЭ
#define CONTROL_TLE          menu_context.controlStruct_tmp3
//контроль редакт ранж
#define CONTROL_ERNG         menu_context.controlStruct_tmp3

//текущий клон
#define LIGHTCLON            menu_context.light1
//тек база менеджера уставок
#define LIGHTMNGUBAZA        menu_context.light2
//тек смещение менеджера уставок
#define LIGHTMNGUOFFSET      menu_context.light3
//текущая линия меню
#define LIGHTLINEMENU        menu_context.light4
//номер УВВ ранжир
#define LIGHTRANGUVV         menu_context.light5
//текущий пакет
#define LIGHTISPACKET        menu_context.isPacket
//запрещено
#define LIGHTISDENIE         menu_context.isDenie

typedef struct//управл структура menu
{
 void *Line1;
 void *Line2;
 short TypesWin;//типажи
}LineMenuItem;

enum TypesEnum//типажи
{
 typeMenuSub = 5,
 typeMenuViewRangDV,
 typeMenuViewRangRele,
 typeMenuViewRangCDI,
 typeMenuViewActual,
 typeMenuViewActualDV,
 typeMenuViewActualRele,
 typeMenuViewRDISMaska,
 typeMenuViewAPVMaska,
 typeMenuViewUROVMaska,
 typeMenuViewP1OFMaska,
 typeMenuViewP2OFMaska,
 typeMenuViewP3OFMaska,
 typeMenuEditRang,
 typeMenuEditWL,

 typeMenuViewLE,

 typeMenuList,
 typeMenuCnf,
 typeMenuCnfWL,
 typeMenuReg,
 typeMenuProg
};

typedef struct
{
  char Win[4][32];//массив строк окна 
} WIN_STRUCT;

typedef struct
{
//для просмотра строк
  WIN_STRUCT stringWin;//массив строк окна
  WIN_STRUCT stringWinOld;//массив строк окна старый
} VIEW_STRUCT;

typedef struct
{
  short light1;//подсветка 1
  short light2;//подсветка 2
  short light3;//подсветка 3
  short light4;//подсветка 4
  short light5;//подсветка 5
  char  isPacket;//текущий пакет
  char  isDenie;//запрещено

  void *controlStruct_crr;//управл структура для TextStream текущая
  void *lsubmenu_crr;//текущий submenu
  void  (*pFncGlobal)(short);//ф-ция HOME
  void  (*pFPassWord)();//ф-ция PassWord
//  void  (*pFPassWord1)(void *);//ф-ция PassWord

  StreamControl controlStruct_main;//главное меню
  StreamControl controlStruct_cnf;//конфигурация
  StreamControl controlStruct_cnfwl;//конфигурация РЛ
  StreamControl controlStruct_cntr;//настройка
  StreamControl controlStruct_viewDV;//ранжир ДВ
  StreamControl controlStruct_viewRele;//ранжир Реле
  StreamControl controlStruct_viewCDI;//ранжир СДИ
  StreamControl controlStruct_widel;//ранжир Расш лог
  StreamControl controlStruct_str;//для массива строк
  StreamControl controlStruct_c1;//компонент 1
  StreamControl controlStruct_c2;//компонент 2
  StreamControl controlStruct_WL;//РЛ

  StreamControl controlStruct_tmp1;
  StreamControl controlStruct_tmp2;
  StreamControl controlStruct_tmp3;

} MENU_CONTEXT;

extern MENU_CONTEXT menu_context;


