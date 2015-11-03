
#include "header.h"
#include "ici_r_ef.h"

#include "bazisdef.h"
#include "toSpeedOptim.h"
#include "psuperVisor\supermanager.h"

#define _HIDE_COMPONENT
#include "MTZ1Component.c"
#include "MTZ2Component.c"

extern int  offsetIOCmdAPV;//смещение для IO APV
extern int  offsetIOCmdDZ1;//смещение для IO DZ1
extern int  offsetIOCmdDZ5;//смещение для IO DZ5
extern int  offsetIOCmdMTZ1;//смещение для IO MTZ1
extern int  offsetIOCmdMTZ5;//смещение для IO MTZ5
extern int  offsetIOCmdNZOP2;//смещение для IO NZOP2
extern int  offsetIOCmdOF;//смещение для IO OF
extern int  offsetIOCmdPF;//смещение для IO PF
extern int  offsetIOCmdOF_loc;//смещение для IO OF
extern int  offsetIOCmdPF_loc;//смещение для IO PF
extern int  offsetIOCmdPRM1;//смещение для IO PRM1
extern int  offsetIOCmdTZNP5;//смещение для IO TZNP5
extern int  offsetIOCmdUMM;//смещение для IO UMM
extern int  offsetIOCmdUROV;//смещение для IO UROV
extern int  offsetIOCmdWL;//смещение для IO WL
//широкий ком массив RT 
extern int   WideCmdRTBuffer[];

//ком массив RT INTERFACE
UNS_32 dataCmdStateINTERFACE[DQUADRO];//INTERFACE CmdState
UNS_32 dataTrgCmdStateINTERFACE[DQUADRO];//INTERFACE Trg CmdState

void TranslateINTERFACE() @ "Fast_function"
{
//широкий ком массив RT INTERFACE
int   WideCmdStateINTERFACE[SIZE_RANGIRCMD+3];
//перетранслировать широкий ком массив
/*
int tt1 = offsetIOCmdAPV;//смещение для IO APV
int tt2 = offsetIOCmdDZ1;//смещение для IO DZ1
int tt3 = offsetIOCmdDZ5;//смещение для IO DZ5
int tt4 = offsetIOCmdMTZ1;//смещение для IO MTZ1
int tt5 = offsetIOCmdMTZ5;//смещение для IO MTZ5
int tt6 = offsetIOCmdNZOP2;//смещение для IO NZOP2
int tt7 = offsetIOCmdOF;//смещение для IO OF
int tt8 = offsetIOCmdPF;//смещение для IO PF
int tt9 = offsetIOCmdPRM1;//смещение для IO PRM1
int tt10 = offsetIOCmdTZNP5;//смещение для IO TZNP5
int tt11 = offsetIOCmdUMM;//смещение для IO UMM
int tt12 = offsetIOCmdUROV;//смещение для IO UROV
int tt13 = offsetIOCmdWL;//смещение для IO WL
*/

//трансляция МТЗ1-------------------------------------------
// Блокировка МТЗ1
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[BLOCK_MCP1_DI_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ1 +
			//Стат блок МТЗ1
			 IOCMD1_MTZ1 
			 ];

// Блокировка МТЗ2
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[BLOCK_MCP2_DI_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*3 +
                         IOCMD1_MTZ2to5
                         ];

// Блокировка МТЗ3
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[BLOCK_MCP3_DI_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*2 +
                         IOCMD1_MTZ2to5
                         ];

// Блокировка МТЗ4
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[BLOCK_MCP4_DI_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*1 +
                         IOCMD1_MTZ2to5
                         ];

// Блокировка МТЗ5
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[BLOCK_MCP5_DI_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 +
                           IOCMD_MTZ2to5_TOTAL*0 +
                         IOCMD1_MTZ2to5
                         ];

//Оперативное ускорение МТЗ2
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[ACCLT_MCP2_DI_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*3 +
                           IOCMD3_MTZ2to5
                         ];

//Оперативное ускорение МТЗ3
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[ACCLT_MCP3_DI_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*2 +
                           IOCMD3_MTZ2to5
                         ];

//Оперативное ускорение МТЗ4
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[ACCLT_MCP4_DI_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*1 +
                           IOCMD3_MTZ2to5
                         ];

//Оперативное ускорение МТЗ5
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[ACCLT_MCP5_DI_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 +
                           IOCMD_MTZ2to5_TOTAL*0 +
                           IOCMD3_MTZ2to5
                         ];


// ПО МТЗ1
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP1_BORING_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ1 +
                           IOCMD2_MTZ1
                         ];

// ПО МТЗ1 ВПД
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP1_STAIGHT_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ1 +
                           IOCMD3_MTZ1
                         ];

// ПО МТЗ1 НЗД
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP1_BACK_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ1 +
                           IOCMD4_MTZ1
                         ];

// ПО МТЗ1 ПН
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP1_VLT_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ1 +
                           IOCMD5_MTZ1
                         ];

// сраб МТЗ1
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[MCP1_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ1 +
                           IOCMD6_MTZ1
                         ];


// ПО МТЗ2
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP2_BORING_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*3 +
                           IOCMD4_MTZ2to5
                         ];

// ПО МТЗ2 ВПД
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP2_STAIGHT_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*3 +
                           IOCMD5_MTZ2to5
                         ];

// ПО МТЗ2 НЗД
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP2_BACK_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*3 +
                           IOCMD6_MTZ2to5
                         ];

// ПО МТЗ2 ПН
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP2_VLT_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*3 +
                           IOCMD7_MTZ2to5
                         ];

// сраб МТЗ2
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[MCP2_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*3 +
                           IOCMD8_MTZ2to5
                         ];

// ПО МТЗ3
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP3_BORING_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*2 +
                           IOCMD4_MTZ2to5
                         ];

// ПО МТЗ3 ВПД
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP3_STAIGHT_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*2 +
                           IOCMD5_MTZ2to5
                         ];

// ПО МТЗ3 НЗД
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP3_BACK_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*2 +
                           IOCMD6_MTZ2to5
                         ];

// ПО МТЗ3 ПН
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP3_VLT_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*2 +
                           IOCMD7_MTZ2to5
                         ];

// сраб МТЗ3
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[MCP3_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*2 +
                           IOCMD8_MTZ2to5
                         ];

// ПО МТЗ4
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP4_BORING_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*1 +
                           IOCMD4_MTZ2to5
                         ];

// ПО МТЗ4 ВПД
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP4_STAIGHT_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*1 +
                           IOCMD5_MTZ2to5
                         ];

// ПО МТЗ4 НЗД
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP4_BACK_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*1 +
                           IOCMD6_MTZ2to5
                         ];

// ПО МТЗ4 ПН
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP4_VLT_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*1 +
                           IOCMD7_MTZ2to5
                         ];

// сраб МТЗ4
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[MCP4_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*1 +
                           IOCMD8_MTZ2to5
                         ];

// ПО МТЗ5
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP5_BORING_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 +
                           IOCMD_MTZ2to5_TOTAL*0 +
                           IOCMD4_MTZ2to5
                         ];

// ПО МТЗ5 ВПД
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP5_STAIGHT_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 +
                           IOCMD_MTZ2to5_TOTAL*0 +
                           IOCMD5_MTZ2to5
                         ];

// ПО МТЗ5 НЗД
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP5_BACK_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 +
                           IOCMD_MTZ2to5_TOTAL*0 +
                           IOCMD6_MTZ2to5
                         ];

// ПО МТЗ5 ПН
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP5_VLT_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 +
                           IOCMD_MTZ2to5_TOTAL*0 +
                           IOCMD7_MTZ2to5
                         ];

// сраб МТЗ5
   //широкий ком массив RT INTERFACE
   WideCmdStateINTERFACE[MCP5_OEPRF_ONB] =
	   //широкий ком массив RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 +
                           IOCMD_MTZ2to5_TOTAL*0 +
                           IOCMD6_MTZ2to5
                         ];


//  CompressorToINTERFACE();//КОМПРЕССОР МАССИВА
   /*
  for (int i=0; i<DQUADRO; i++)
  {
     dataTrgCmdStateINTERFACE[i] |= dataCmdStateINTERFACE[i];//INTERFACE Trg CmdState
  }//for
*/
}//void TranslateINTERFACE()

/**********************************************
КОМПРЕССОР МАССИВА
dataCmdStateINTERFACE - указатель на массив  Quadro
WideCmdStateINTERFACE - указатель на широкий ком массив INTERFACE
**********************************************/
/*
void CompressorToINTERFACE() @ "Fast_function"
{
  for (int i=0; i<DQUADRO; i++)
  {
    UNS_32 tmp = 0;
    for (int b=0; b<32; b++)
    {
      if (WideCmdStateINTERFACE[i*32+b])//!=0)
      {
        tmp |= 1<<b;
      }
    }//for
    dataCmdStateINTERFACE[i] = tmp;
  }//for
}//CompressorToINTERFACE()
*/
