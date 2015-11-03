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
#include "psuperVisor\psvisor_helpdef.h"
#include "virtualMenu\systemmenudef.h"
#include "virtualMenu\ustmanagerdef.h"

#include "ustrangEEPROMdef.h"

#include "logictimers\logictimersfnc.h"
#include "virtualMenu\systemmenufnc.h"
#include "virtualMenu\rangmanagerfnc.h"
#include "virtualMenu\textstreamfnc.h"
#include "virtualMenu\ustmanagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"

#include "virtualMenu\viewMenuWideLog.h"
#include "virtualMenu\viewMenuCnf.h"
#include "virtualMenu\viewMenuSub.h"

#include "psupervisor\psupervisor.h"

#include "virtualMenu\repozitfnc.h"

#include "toSpeedOptim.h"

#include "..\bazis.h"

#define _HIDE_COMPONENT

#include "APVComponent.c"
#include "UMMComponent.c"
#include "DZ1Component.c"
#include "DZ2Component.c"

#include "MTZ1Component.c"
#include "MTZ2Component.c"

#include "NZOP1Component.c"

#include "OFComponent.c"

#include "PRM1Component.c"

#include "TZNP1Component.c"

#include "UROVComponent.c"

void PrepareResetBV();

extern LineMenuItem sub_menu_main[];
extern LineMenuItem sub_menu_cntr[];
extern char addComp[];
extern LineMenuItem sub_menu_dv[];
extern LineMenuItem sub_menu_rele[];
extern LineMenuItem sub_menu_cdi[];
extern LineMenuItem sub_menu_le[];
extern LineMenuItem sub_menu_cnf[];
extern LineMenuItem sub_menu_widel[];
extern COMPONENT_OBJ  cnfCOMPONENT[];
extern int  spvUSTAVKI[];//текущие уставки супервизора

extern LineMenuItem sub_menu_comp_WL[];

extern int  offsetIOCmdOF;//смещение для IO OF
extern int  offsetIOCmdPF;//смещение для IO PF
extern int  offsetIOCmdOF_loc;//смещение для IO OF
extern int  offsetIOCmdPF_loc;//смещение для IO PF
extern int  offsetUstMngPRM1;//смещение на уставки PRM1

char *bitStringUNI[20];

LineMenuItem sub_menu_cnfwl[MAX_WLCOMPONENT+3] =
{
  { "Конфигурация РЛ", NULL},//title
  { &CONTROL_CNFWL, sub_menu_comp_WL},//control_item, parent
  { addComp, (void *)&RpzComponentWL, typeMenuProg},
  { NULL, NULL}
};

//меню конфигурации
LineMenuItem sub_menu_cnf[MAX_CNFCOMPONENT+3] =
{
  { "Конфигурация", NULL},//title
  { &CONTROL_CNF, sub_menu_main},//control_item, parent
  { addComp, (void *)&RpzComponent, typeMenuProg},
  { NULL, NULL}
};

//дискретный регистратор
LineMenuItem sub_menu_reg[] =
{
  { "Дискретный регистратор", NULL},//title
  { &CONTROL_DIS, sub_menu_main}//control_item, parent
};

//Текущие
LineMenuItem sub_menu_act[] =
{
  { "Текущие", NULL},//title
  { &CONTROL_ACT, sub_menu_main}//control_item, parent
};

//РегистрацияДИС
LineMenuItem sub_menu_rdis[] =
{
  { "РегистрацияДИС", NULL},//title
  { &CONTROL_RDIS, sub_menu_main}//control_item, parent
};

//APV
LineMenuItem sub_menu_apv[] =
{
  { "Пуск АПВ", NULL},//title
  { &CONTROL_APV, sub_menu_main}//control_item, parent
};

LineMenuItem sub_menu_urov[] =
{
  { "Пуск УРОВ", NULL},//title
  { &CONTROL_UROV, sub_menu_main}//control_item, parent
};

LineMenuItem sub_menu_p1of[] =
{
  { "Пуск 1 ОФ", NULL},//title
  { &CONTROL_P1OF, sub_menu_main}//control_item, parent
};

LineMenuItem sub_menu_p2of[] =
{
  { "Пуск 2 ОФ", NULL},//title
  { &CONTROL_P2OF, sub_menu_main}//control_item, parent
};

LineMenuItem sub_menu_p3of[] =
{
  { "Пуск 3 ОФ", NULL},//title
  { &CONTROL_P1OF, sub_menu_main}//control_item, parent
};

char titleRang[10] = "";
//ДВ
LineMenuItem sub_menu_viewDV[] =
{
  { titleRang, NULL},//title
  { &CONTROL_VRNG, sub_menu_dv}//control_item, parent
};

//Rele
LineMenuItem sub_menu_viewRele[] =
{
  { titleRang, NULL},//title
  { &CONTROL_VRNG, sub_menu_rele}//control_item, parent
};

LineMenuItem sub_menu_viewCDI[] =
{
  { titleRang, NULL},//title
  { &CONTROL_VRNG, sub_menu_cdi}//control_item, parent
};

LineMenuItem sub_menu_tmp[] =
{
  { "Сообщение", NULL},//title
  { NULL, NULL},//control_item, parent
};

LineMenuItem sub_menu_dv[] =
{
  { "Дискр Входы", NULL},//title
  { &CONTROL_DV, sub_menu_cntr},//control_item, parent
/*
  { "ДВ1", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ2", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ3", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ4", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ5", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ6", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ7", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ8", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ9", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ10", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ11", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ12", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ13", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ14", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ15", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ16", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ17", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ18", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ19", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ20", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ21", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ22", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ23", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ24", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ25", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ26", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ27", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ28", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ29", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ30", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ31", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ32", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ33", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ34", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ35", sub_menu_viewDV, typeMenuViewRangDV},
  { "ДВ36", sub_menu_viewDV, typeMenuViewRangDV},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_rele[] =
{
  { "Выходы реле", NULL},//title
  { &CONTROL_RELE, sub_menu_cntr},//control_item, parent
/*
  { "Р01", sub_menu_viewRele, typeMenuViewRangRele},
  { "Р02", sub_menu_viewRele, typeMenuViewRangRele},
  { "Р03", sub_menu_viewRele, typeMenuViewRangRele},
  { "Р04", sub_menu_viewRele, typeMenuViewRangRele},
  { "Р05", sub_menu_viewRele, typeMenuViewRangRele},
  { "Р06", sub_menu_viewRele, typeMenuViewRangRele},
  { "Р07", sub_menu_viewRele, typeMenuViewRangRele},
  { "Р08", sub_menu_viewRele, typeMenuViewRangRele},
  { "Р09", sub_menu_viewRele, typeMenuViewRangRele},
  { "Р10", sub_menu_viewRele, typeMenuViewRangRele},
  { "Р11", sub_menu_viewRele, typeMenuViewRangRele},
  { "Р12", sub_menu_viewRele, typeMenuViewRangRele},
  { "Р13", sub_menu_viewRele, typeMenuViewRangRele},
  { "Р14", sub_menu_viewRele, typeMenuViewRangRele},
  { "Р15", sub_menu_viewRele, typeMenuViewRangRele},
  { "Р16", sub_menu_viewRele, typeMenuViewRangRele},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_cdi[] =
{
  { "Светоиндикаторы", NULL},//title
  { &CONTROL_CDI, sub_menu_cntr},//control_item, parent
/*
  { "СДИ01", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "СДИ02", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "СДИ03", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "СДИ04", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "СДИ05", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "СДИ06", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "СДИ07", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "СДИ08", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "СДИ09", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "СДИ10", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "СДИ11", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "СДИ12", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "СДИ13", sub_menu_viewCDI, typeMenuViewRangCDI},
  { "СДИ14", sub_menu_viewCDI, typeMenuViewRangCDI},
*/
  { NULL, NULL}

};

LineMenuItem sub_menu_cntr[] =
{
  { "Настройка", NULL},//title
  { &CONTROL_CNTR, sub_menu_main},//control_item, parent
  { "Дискр входы",     sub_menu_dv,    typeMenuSub},
  { "Выходы реле",     sub_menu_rele,  typeMenuSub},
  { "Светоиндикаторы", sub_menu_cdi,   typeMenuSub},
  { NULL, NULL}

};

//главное меню
LineMenuItem sub_menu_main[] =
{
  { "Главное меню", NULL},//title
  { &CONTROL_MAIN, NULL},//control_item, parent
  { "Настройка",         sub_menu_cntr, typeMenuSub},
  { "Конфигурация",      sub_menu_cnf,  typeMenuCnf},//конфигурация
  { "РегистрацияДИС",    sub_menu_rdis, typeMenuViewRDISMaska},//РегистрацияДИС
  { "Пуск АПВ",          sub_menu_apv,   typeMenuViewAPVMaska},//Пуск АПВ
  { "Пуск УРОВ",         sub_menu_urov,  typeMenuViewUROVMaska},//Пуск УРОВ
  { "P1 ОФ",             sub_menu_p1of,  typeMenuViewP1OFMaska},//маска 1 ОФ
  { "P2 ОФ",             sub_menu_p2of,  typeMenuViewP2OFMaska},//маска 2 ОФ
  { "P3 ОФ",             sub_menu_p3of,  typeMenuViewP3OFMaska},//маска 3 ОФ
  { "Дискр регистратор", sub_menu_reg,  typeMenuReg},//дискр рег
  { "Текущие",           sub_menu_act,  typeMenuViewActual},
  { NULL, NULL}

};

//редактор ранжир
LineMenuItem sub_menu_editrng[] =
{
  { "Редактор ранж", NULL},//title
  { NULL, NULL, typeMenuEditRang}//control_item, parent
};

//редактор расшир логики
LineMenuItem sub_menu_editwl[] =
{
  { "Редактор РЛ", NULL},//title
  { NULL, NULL, typeMenuEditWL}//control_item, parent
};

void ResetSystemMenu()
{
  bitStringUNI[UNIUPR_WKL]    = "ВКЛ";
  bitStringUNI[UNIUPR_OTKL]   = "ОТКЛ";
  bitStringUNI[UNIUPR_WPERED] = "ВПЕРЕД";
  bitStringUNI[UNIUPR_NAZAD]  = "НАЗАД";
  bitStringUNI[UNIUPR_PROSTAJA] = "ПРОСТАЯ";
  bitStringUNI[UNIUPR_NAPRAVL]  = "НАПРАВЛ";
  bitStringUNI[UNIUPR_INVERS]   = "ИНВЕРСНЫЙ";
  bitStringUNI[UNIUPR_PRM]      = "ПРЯМОЙ";
  bitStringUNI[UNIUPR_NORM]     = "НОРМАЛЬНЫЙ";
  bitStringUNI[UNIUPR_TRIG]     = "ТРИГГ";
  bitStringUNI[UNIUPR_OBRAT]    = "ОБРАТНАЯ";
  bitStringUNI[UNIUPR_PRJAM]    = "ПРЯМАЯ";
  bitStringUNI[UNIUPR_ILI]      = "ИЛИ";
  bitStringUNI[UNIUPR_I]        = "И";
  bitStringUNI[UNIUPR_LIN]      = "ЛИНЕЙНЫЕ";
  bitStringUNI[UNIUPR_FAZ]      = "ФАЗНЫЕ";

//сброс системного меню
  ResetConfig();//обнулить конфигурацию

  TxtStreamInit(&CONTROL_MAIN, &KadrMenuFormat_sub, sub_menu_main);//инит control и формир кадра

  CRR_SUBMENU = sub_menu_main;//текущий submenu
  //типажи
  sub_menu_main[SUBDATA].TypesWin = typeMenuSub;

  CRR_TEXTSTREAM = &CONTROL_MAIN;//текущий control

  TxtStreamInit(&CONTROL_CNTR,      &KadrMenuFormat_sub, sub_menu_cntr);//инит control и формир кадра
  TxtStreamInit(&CONTROL_DV,        &KadrMenuFormat_sub, sub_menu_dv);//инит control и формир кадра
  TxtStreamInit(&CONTROL_RELE,      &KadrMenuFormat_sub, sub_menu_rele);//инит control и формир кадра
  TxtStreamInit(&CONTROL_CDI,       &KadrMenuFormat_sub, sub_menu_cdi);//инит control и формир кадра
  TxtStreamInit(&CONTROL_WDL,       &KadrMenuFormat_sub, sub_menu_widel);//инит control и формир кадра

  ViewDiskrMenu(typeMenuSub);//вывести окно отображения

//  CRR_FHOME = &PereinitSub;//указатель на ф-цию HOME
  SelectorFHOME(&PereinitSub);//указатель на ф-цию HOME

  LanderPStr();//размещение указателя строки
  ResetUpDown();//погасить Up Down
  ShowTitleSubmenu_crr();//заголовок текущего Submenu

  AddCompIzRpz(PRM1_COMP1);//добавить компонент из репозитария


 SetCmdToUVV(PRM1_COMP1,  1, IOCMD6_PRM1, RELE2_SM);//отранж TEST PRM1 на P2


  AddCompIzRpz(PF_COMP1);//добавить компонент из репозитария
  AddCompIzRpz(OF_COMP1);//добавить компонент из репозитария
  
  AddCompIzRpz(UMM_COMP1);//добавить компонент из репозитария
  AddCompIzRpz(UROV_COMP1);//добавить компонент из репозитария
  AddCompIzRpz(APV_COMP1);//добавить компонент из репозитария

  AddCompIzRpz(NZOP_COMP1);//добавить компонент из репозитария
  AddCompIzRpz(TZNP_COMP1);//добавить компонент из репозитария
  AddCompIzRpz(DZ_COMP1);//добавить компонент из репозитария
  AddCompIzRpz(MTZ_COMP1);//добавить компонент из репозитария

  AddCompIzRpz(WL_COMP1);//добавить компонент из репозитария

  offsetIOCmdOF = offsetIOCmdOF_loc;//cмещение для IO
  offsetIOCmdPF = offsetIOCmdPF_loc;//смещение для IO

  AddCompIzRpz_WL(OF_COMP1);//добавить компонент из репозитария в РЛ
  AddCompIzRpz_WL(PF_COMP1);//добавить компонент из репозитария в РЛ
  
  PrepareResetBV();//подготовить команды сброса блока включения


  SetCmdToUVV(PRM1_COMP1,  1, IOCMD1_PRM1, DV1_SM);//отранж CMD_POL_VV на ДВ1

//--------MTZ1-------------------
  SetCmdToUVV(MTZ_COMP1,  1, IOCMD6_MTZ1, RELE6_SM);//отранж MTZ1 на P6
  SetCmdToUVV(MTZ_COMP1,  1, IOCMD6_MTZ1, RELE1_SM);//отранж MTZ1 на P6
//----------------------------------------------------------
//--------MTZ2-------------------
  SetCmdToUVV(MTZ_COMP1,  2, IOCMD8_MTZ2to5, RELE6_SM);//отранж MTZ2 на P6
//----------------------------------------------------------
//--------MTZ3-------------------
  SetCmdToUVV(MTZ_COMP1,  3, IOCMD8_MTZ2to5, RELE6_SM);//отранж MTZ3 на P6
//----------------------------------------------------------
//--------MTZ4-------------------
  SetCmdToUVV(MTZ_COMP1,  4, IOCMD8_MTZ2to5, RELE6_SM);//отранж MTZ4 на P6
//----------------------------------------------------------
//--------MTZ5-------------------
  SetCmdToUVV(MTZ_COMP1,  5, IOCMD8_MTZ2to5, RELE6_SM);//отранж MTZ5 на P6
//----------------------------------------------------------

  SetCmdToUVV(MTZ_COMP1,  2, IOCMD3_MTZ2to5, DV3_SM);//отранж Операт ускор MTZ2 на ДВ3
  SetCmdToUVV(MTZ_COMP1,  3, IOCMD3_MTZ2to5, DV3_SM);//отранж Операт ускор MTZ3 на ДВ3
  SetCmdToUVV(MTZ_COMP1,  4, IOCMD3_MTZ2to5, DV3_SM);//отранж Операт ускор MTZ4 на ДВ3
  SetCmdToUVV(MTZ_COMP1,  5, IOCMD3_MTZ2to5, DV3_SM);//отранж Операт ускор MTZ5 на ДВ3

//--------UMM-------------------
        //UMAX1
  SetCmdToUVV(UMM_COMP1,  1, IOCMD6_UMM, RELE6_SM);//отранж HA P6
        //UMAX2
  SetCmdToUVV(UMM_COMP1,  1, IOCMD8_UMM, RELE6_SM);//отранж HA P6
        // UMIN1
  SetCmdToUVV(UMM_COMP1,  1, IOCMD10_UMM, RELE6_SM);//отранж HA P6
        // UMIN2
  SetCmdToUVV(UMM_COMP1,  1, IOCMD12_UMM, RELE6_SM);//отранж HA P6

    //PUSK_UMM1
  SetCmdToUVV(UMM_COMP1,  1, IOCMDPUSK1_UMM, DV1_SM);//отранж Пуск UMIN1 на ДВ1
    //PUSK_UMM2
  SetCmdToUVV(UMM_COMP1,  1, IOCMDPUSK2_UMM, DV1_SM);//отранж Пуск UMIN2 на ДВ1
    //BLOK_UMIN1
  SetCmdToUVV(UMM_COMP1,  1, IOCMD3_UMM, DV2_SM);//отранж Блок UMIN1 на ДВ2
    //BLOK_UMIN2
  SetCmdToUVV(UMM_COMP1,  1, IOCMD4_UMM, DV2_SM);//отранж Блок UMIN2 на ДВ2

//--------DZ-------------------
        //DZ1               //Сраб ДЗ1ОФ
  SetCmdToUVV(DZ_COMP1,  1, IOCMD7_DZ1, RELE6_SM);//отранж HA P6
//  SetCmdToUVV(DZ_COMP1,  4, IOCMD5_DZ2to5MF, RELE1_SM);//отранж 

//--------TZNP-------------------
//Сраб ТЗНП1
//CMD_TZNP1to5
  SetCmdToUVV(TZNP_COMP1,  1, IOCMD5_TZNP1to5, RELE6_SM);//отранж HA P6
//Сраб ТЗНП1 3I0
//CMD_TZNP1to5_3I0
  SetCmdToUVV(TZNP_COMP1,  1, IOCMD7_TZNP1to5, RELE6_SM);//отранж HA P6
//Сраб ТЗНП1 3U0
//CMD_TZNP1to5_3U0
  SetCmdToUVV(TZNP_COMP1,  1, IOCMD9_TZNP1to5, RELE6_SM);//отранж HA P6

//Сраб ТЗНП1
//CMD_TZNP1to5
  SetCmdToUVV(TZNP_COMP1,  2, IOCMD5_TZNP1to5, RELE6_SM);//отранж HA P6
//Сраб ТЗНП1 3I0
//CMD_TZNP1to5_3I0
  SetCmdToUVV(TZNP_COMP1,  2, IOCMD7_TZNP1to5, RELE6_SM);//отранж HA P6
//Сраб ТЗНП1 3U0
//CMD_TZNP1to5_3U0
  SetCmdToUVV(TZNP_COMP1,  2, IOCMD9_TZNP1to5, RELE6_SM);//отранж HA P6

//Сраб ТЗНП1
//CMD_TZNP1to5
  SetCmdToUVV(TZNP_COMP1,  3, IOCMD5_TZNP1to5, RELE6_SM);//отранж HA P6
//Сраб ТЗНП1 3I0
//CMD_TZNP1to5_3I0
  SetCmdToUVV(TZNP_COMP1,  3, IOCMD7_TZNP1to5, RELE6_SM);//отранж HA P6
//Сраб ТЗНП1 3U0
//CMD_TZNP1to5_3U0
  SetCmdToUVV(TZNP_COMP1,  3, IOCMD9_TZNP1to5, RELE6_SM);//отранж HA P6

//Сраб ТЗНП1
//CMD_TZNP1to5
  SetCmdToUVV(TZNP_COMP1,  4, IOCMD5_TZNP1to5, RELE6_SM);//отранж HA P6
//Сраб ТЗНП1 3I0
//CMD_TZNP1to5_3I0
  SetCmdToUVV(TZNP_COMP1,  4, IOCMD7_TZNP1to5, RELE6_SM);//отранж HA P6
//Сраб ТЗНП1 3U0
//CMD_TZNP1to5_3U0
  SetCmdToUVV(TZNP_COMP1,  4, IOCMD9_TZNP1to5, RELE6_SM);//отранж HA P6

//Сраб ТЗНП1
//CMD_TZNP1to5
  SetCmdToUVV(TZNP_COMP1,  5, IOCMD5_TZNP1to5, RELE6_SM);//отранж HA P6
//Сраб ТЗНП1 3I0
//CMD_TZNP1to5_3I0
  SetCmdToUVV(TZNP_COMP1,  5, IOCMD7_TZNP1to5, RELE6_SM);//отранж HA P6
//Сраб ТЗНП1 3U0
//CMD_TZNP1to5_3U0
  SetCmdToUVV(TZNP_COMP1,  5, IOCMD9_TZNP1to5, RELE6_SM);//отранж HA P6

  //BLOK_TZNP1
  SetCmdToUVV(TZNP_COMP1,  1, IOCMD1_TZNP1to5, DV2_SM);//отранж Блок TZNP1 на ДВ2
  SetCmdToUVV(TZNP_COMP1,  1, IOCMD3_TZNP1to5, DV3_SM);//отранж Операт ускор TZNP1 на ДВ3
  SetCmdToUVV(TZNP_COMP1,  1, IOCMD2_TZNP1to5, DV4_SM);//отранж Блок уск ТЗНП1 на ДВ4

  //BLOK_TZNP2
  SetCmdToUVV(TZNP_COMP1,  2, IOCMD1_TZNP1to5, DV2_SM);//отранж Блок TZNP2 на ДВ2
  SetCmdToUVV(TZNP_COMP1,  2, IOCMD3_TZNP1to5, DV3_SM);//отранж Операт ускор TZNP2 на ДВ3
  SetCmdToUVV(TZNP_COMP1,  2, IOCMD2_TZNP1to5, DV4_SM);//отранж Блок уск ТЗНП2 на ДВ4

//--------APV-------------------
      SetCmdToUVV(APV_COMP1,  1, IOCMD2_APV, DV3_SM);//отранж 
//      SetCmdToUVV(APV_COMP1,  1, IOCMD2_APV, RELE1_SM);//отранж 

//APV1
      SetCmdToUVV(APV_COMP1,  1, IOCMD4_APV, RELE2_SM);//отранж 

//--------REG_DIS-------------------
      SetCmdToUVV(APV_COMP1,  1, IOCMD2_APV, REGDIS_SM);//Пуск АПВ от ДВ
extern int alterEEPROM;//x101;//0;//байты alter ext устaвок и ранжир EEPROM

    savePARAMtoEEPROM(alterEEPROM^USTALTER_MASKA);

}//ResetSystemMenu()

int SetUstToClon(short kodC, short numClon, short numUst, int newUst)
{
//новая уставка numUst равна newUst компонента kodC с номером клона numClon
  short idxClon = SearchCnfClonToComponent(kodC, numClon);
  if(idxClon<0) return 1;//клон не найден
 
//записать заданную bazaOffset уставку ust в клон idxC
  int tmp = setClonMngUSTAVKI(idxClon, numUst, newUst);
//    int  ttttttt1 = PrepareENACmd(8, 31);//MNGUPR_DZ2to5);
  if(tmp==ERROR_UST) return ERROR_UST;//ошибка
  //проверка на подготовку таймеров БО БВ
//  if((kodC==PRM1_COMP1)&&((numUst==MNGUST_PRM1_BO)||(numUst==MNGUST_PRM1_BV)))
  //      PrepareBOBVtimer();//подготовить таймера Блок ОТКЛ, Блок ВКЛ
  PREPAREustCOMPONENT(idxClon);//СУПЕРВИЗОР  Подготовка уставок spv компонентов из конфиг
  SaveAsBlokUstavki(0);//сохранить тек уст как блок уставок
  return tmp;//успешно
}//SetUstToClon(short kodC, short numClon, short numUst, int newUst)

void PrepareBOBV()
{
//подготовить Блок ОТКЛ, Блок ВКЛ
extern UNS_32 maskaReleBO, maskaReleBV;
extern int offsetIOCmdPRM1;//смещение для IO PRM1

      maskaReleBO = 0;
      maskaReleBV = 0;
    int i=RELE1_SM;
    for(; i<(RELE1_SM+RELE_TOTAL); i++)
    {
                                   //Работа БО
      if(GetCmdUVVFromClon(PRM1_COMP1, 1, IOCMD4_PRM1, i)) break;
    }//for
  if(!(i==(RELE1_SM+RELE_TOTAL))){//break не было
     maskaReleBO = 1<<(i-RELE1_SM);
  }//if

    i=RELE1_SM;
    for(; i<(RELE1_SM+RELE_TOTAL); i++)
    {
                                   //Работа БB
      if(GetCmdUVVFromClon(PRM1_COMP1, 1, IOCMD5_PRM1, i)) break;
    }//for
  if(!(i==(RELE1_SM+RELE_TOTAL))){//break не было
     maskaReleBV = 1<<(i-RELE1_SM);
  }//if
}//PrepareBOBV()

void PrepareResetBV()
{
//подготовить сигналы сброса Блока Включения
//extern UNS_32 pResetBVcmdMaska[];//определение Сброс Блока Включения
//----------------------------MTZ------------------------------
    SetCmdToUVV(MTZ_COMP1,  1, IOCMD6_MTZ1,    RESETBV_SM);//отранж MTZ1 на APV
    SetCmdToUVV(MTZ_COMP1,  2, IOCMD8_MTZ2to5, RESETBV_SM);//отранж MTZ2 на APV
    SetCmdToUVV(MTZ_COMP1,  3, IOCMD8_MTZ2to5, RESETBV_SM);//отранж MTZ3 на APV
    SetCmdToUVV(MTZ_COMP1,  4, IOCMD8_MTZ2to5, RESETBV_SM);//отранж MTZ4 на APV
    SetCmdToUVV(MTZ_COMP1,  5, IOCMD8_MTZ2to5, RESETBV_SM);//отранж MTZ5 на APV

//----------------------------TZNP------------------------------
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD5_TZNP1to5, RESETBV_SM);//отранж на APV
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD9_TZNP1to5, RESETBV_SM);//отранж на APV
    SetCmdToUVV(TZNP_COMP1,  1, IOCMD7_TZNP1to5, RESETBV_SM);//отранж на APV
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD5_TZNP1to5, RESETBV_SM);//отранж на APV
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD9_TZNP1to5, RESETBV_SM);//отранж на APV
    SetCmdToUVV(TZNP_COMP1,  2, IOCMD7_TZNP1to5, RESETBV_SM);//отранж на APV
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD5_TZNP1to5, RESETBV_SM);//отранж на APV
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD9_TZNP1to5, RESETBV_SM);//отранж на APV
    SetCmdToUVV(TZNP_COMP1,  3, IOCMD7_TZNP1to5, RESETBV_SM);//отранж на APV
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD5_TZNP1to5, RESETBV_SM);//отранж на APV
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD9_TZNP1to5, RESETBV_SM);//отранж на APV
    SetCmdToUVV(TZNP_COMP1,  4, IOCMD7_TZNP1to5, RESETBV_SM);//отранж на APV
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD5_TZNP1to5, RESETBV_SM);//отранж на APV
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD9_TZNP1to5, RESETBV_SM);//отранж на APV
    SetCmdToUVV(TZNP_COMP1,  5, IOCMD7_TZNP1to5, RESETBV_SM);//отранж на APV

//----------------------------DZ------------------------------
             SetCmdToUVV(DZ_COMP1,  1, IOCMD3_DZ1, RESETBV_SM);//отранж на APV
             SetCmdToUVV(DZ_COMP1,  1, IOCMD7_DZ1, RESETBV_SM);//отранж на APV
             SetCmdToUVV(DZ_COMP1,  2, IOCMD5_DZ2to5MF, RESETBV_SM);//отранж на APV
             SetCmdToUVV(DZ_COMP1,  2, IOCMD5_DZ2to5OF, RESETBV_SM);//отранж на APV
             SetCmdToUVV(DZ_COMP1,  3, IOCMD5_DZ2to5MF, RESETBV_SM);//отранж на APV
             SetCmdToUVV(DZ_COMP1,  3, IOCMD5_DZ2to5OF, RESETBV_SM);//отранж на APV
             SetCmdToUVV(DZ_COMP1,  4, IOCMD5_DZ2to5MF, RESETBV_SM);//отранж на APV
             SetCmdToUVV(DZ_COMP1,  4, IOCMD5_DZ2to5OF, RESETBV_SM);//отранж на APV
             SetCmdToUVV(DZ_COMP1,  5, IOCMD5_DZ2to5MF, RESETBV_SM);//отранж на APV
             SetCmdToUVV(DZ_COMP1,  5, IOCMD5_DZ2to5OF, RESETBV_SM);//отранж на APV
  SetCmdToUVV(DZ_COMP1,  1, IOCMD5_DZ1, RESETBV_SM);//отранж на APV
  SetCmdToUVV(DZ_COMP1,  2, IOCMD5_MDZ2to5MF, RESETBV_SM);//отранж на APV
  SetCmdToUVV(DZ_COMP1,  3, IOCMD5_MDZ2to5MF, RESETBV_SM);//отранж на APV
  SetCmdToUVV(DZ_COMP1,  4, IOCMD5_MDZ2to5MF, RESETBV_SM);//отранж на APV
  SetCmdToUVV(DZ_COMP1,  5, IOCMD5_MDZ2to5MF, RESETBV_SM);//отранж на APV
  
//--------------------ZN-------------------------------------
      SetCmdToUVV(UMM_COMP1,  1, IOCMD10_UMM, RESETBV_SM);//отранж 
      SetCmdToUVV(UMM_COMP1,  1, IOCMD12_UMM, RESETBV_SM);//отранж 
      SetCmdToUVV(UMM_COMP1,  1, IOCMD6_UMM, RESETBV_SM);//отранж 
      SetCmdToUVV(UMM_COMP1,  1, IOCMD8_UMM, RESETBV_SM);//отранж 
//--------------------NZOP----------------------------
      SetCmdToUVV(NZOP_COMP1,  1, IOCMD5_NZOP1to2, RESETBV_SM);//отранж 
      SetCmdToUVV(NZOP_COMP1,  2, IOCMD5_NZOP1to2, RESETBV_SM);//отранж 

//UNS_32 pResetBVcmdMaska[DQUADRO];//определение Сброс Блока Включения
}//PrepareResetBV()

