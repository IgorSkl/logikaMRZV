
#include "header.h"
#include "ici_r_ef.h"

#include "bazisdef.h"
#include "toSpeedOptim.h"
#include "psuperVisor\supermanager.h"

#define _HIDE_COMPONENT
#include "MTZ1Component.c"
#include "MTZ2Component.c"

extern int  offsetIOCmdAPV;//�������� ��� IO APV
extern int  offsetIOCmdDZ1;//�������� ��� IO DZ1
extern int  offsetIOCmdDZ5;//�������� ��� IO DZ5
extern int  offsetIOCmdMTZ1;//�������� ��� IO MTZ1
extern int  offsetIOCmdMTZ5;//�������� ��� IO MTZ5
extern int  offsetIOCmdNZOP2;//�������� ��� IO NZOP2
extern int  offsetIOCmdOF;//�������� ��� IO OF
extern int  offsetIOCmdPF;//�������� ��� IO PF
extern int  offsetIOCmdOF_loc;//�������� ��� IO OF
extern int  offsetIOCmdPF_loc;//�������� ��� IO PF
extern int  offsetIOCmdPRM1;//�������� ��� IO PRM1
extern int  offsetIOCmdTZNP5;//�������� ��� IO TZNP5
extern int  offsetIOCmdUMM;//�������� ��� IO UMM
extern int  offsetIOCmdUROV;//�������� ��� IO UROV
extern int  offsetIOCmdWL;//�������� ��� IO WL
//������� ��� ������ RT 
extern int   WideCmdRTBuffer[];

//��� ������ RT INTERFACE
UNS_32 dataCmdStateINTERFACE[DQUADRO];//INTERFACE CmdState
UNS_32 dataTrgCmdStateINTERFACE[DQUADRO];//INTERFACE Trg CmdState

void TranslateINTERFACE() @ "Fast_function"
{
//������� ��� ������ RT INTERFACE
int   WideCmdStateINTERFACE[SIZE_RANGIRCMD+3];
//����������������� ������� ��� ������
/*
int tt1 = offsetIOCmdAPV;//�������� ��� IO APV
int tt2 = offsetIOCmdDZ1;//�������� ��� IO DZ1
int tt3 = offsetIOCmdDZ5;//�������� ��� IO DZ5
int tt4 = offsetIOCmdMTZ1;//�������� ��� IO MTZ1
int tt5 = offsetIOCmdMTZ5;//�������� ��� IO MTZ5
int tt6 = offsetIOCmdNZOP2;//�������� ��� IO NZOP2
int tt7 = offsetIOCmdOF;//�������� ��� IO OF
int tt8 = offsetIOCmdPF;//�������� ��� IO PF
int tt9 = offsetIOCmdPRM1;//�������� ��� IO PRM1
int tt10 = offsetIOCmdTZNP5;//�������� ��� IO TZNP5
int tt11 = offsetIOCmdUMM;//�������� ��� IO UMM
int tt12 = offsetIOCmdUROV;//�������� ��� IO UROV
int tt13 = offsetIOCmdWL;//�������� ��� IO WL
*/

//���������� ���1-------------------------------------------
// ���������� ���1
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[BLOCK_MCP1_DI_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ1 +
			//���� ���� ���1
			 IOCMD1_MTZ1 
			 ];

// ���������� ���2
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[BLOCK_MCP2_DI_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*3 +
                         IOCMD1_MTZ2to5
                         ];

// ���������� ���3
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[BLOCK_MCP3_DI_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*2 +
                         IOCMD1_MTZ2to5
                         ];

// ���������� ���4
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[BLOCK_MCP4_DI_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*1 +
                         IOCMD1_MTZ2to5
                         ];

// ���������� ���5
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[BLOCK_MCP5_DI_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 +
                           IOCMD_MTZ2to5_TOTAL*0 +
                         IOCMD1_MTZ2to5
                         ];

//����������� ��������� ���2
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[ACCLT_MCP2_DI_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*3 +
                           IOCMD3_MTZ2to5
                         ];

//����������� ��������� ���3
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[ACCLT_MCP3_DI_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*2 +
                           IOCMD3_MTZ2to5
                         ];

//����������� ��������� ���4
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[ACCLT_MCP4_DI_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*1 +
                           IOCMD3_MTZ2to5
                         ];

//����������� ��������� ���5
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[ACCLT_MCP5_DI_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 +
                           IOCMD_MTZ2to5_TOTAL*0 +
                           IOCMD3_MTZ2to5
                         ];


// �� ���1
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP1_BORING_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ1 +
                           IOCMD2_MTZ1
                         ];

// �� ���1 ���
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP1_STAIGHT_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ1 +
                           IOCMD3_MTZ1
                         ];

// �� ���1 ���
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP1_BACK_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ1 +
                           IOCMD4_MTZ1
                         ];

// �� ���1 ��
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP1_VLT_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ1 +
                           IOCMD5_MTZ1
                         ];

// ���� ���1
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[MCP1_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ1 +
                           IOCMD6_MTZ1
                         ];


// �� ���2
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP2_BORING_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*3 +
                           IOCMD4_MTZ2to5
                         ];

// �� ���2 ���
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP2_STAIGHT_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*3 +
                           IOCMD5_MTZ2to5
                         ];

// �� ���2 ���
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP2_BACK_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*3 +
                           IOCMD6_MTZ2to5
                         ];

// �� ���2 ��
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP2_VLT_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*3 +
                           IOCMD7_MTZ2to5
                         ];

// ���� ���2
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[MCP2_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*3 +
                           IOCMD8_MTZ2to5
                         ];

// �� ���3
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP3_BORING_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*2 +
                           IOCMD4_MTZ2to5
                         ];

// �� ���3 ���
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP3_STAIGHT_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*2 +
                           IOCMD5_MTZ2to5
                         ];

// �� ���3 ���
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP3_BACK_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*2 +
                           IOCMD6_MTZ2to5
                         ];

// �� ���3 ��
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP3_VLT_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*2 +
                           IOCMD7_MTZ2to5
                         ];

// ���� ���3
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[MCP3_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*2 +
                           IOCMD8_MTZ2to5
                         ];

// �� ���4
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP4_BORING_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*1 +
                           IOCMD4_MTZ2to5
                         ];

// �� ���4 ���
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP4_STAIGHT_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*1 +
                           IOCMD5_MTZ2to5
                         ];

// �� ���4 ���
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP4_BACK_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*1 +
                           IOCMD6_MTZ2to5
                         ];

// �� ���4 ��
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP4_VLT_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*1 +
                           IOCMD7_MTZ2to5
                         ];

// ���� ���4
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[MCP4_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 -
                           IOCMD_MTZ2to5_TOTAL*1 +
                           IOCMD8_MTZ2to5
                         ];

// �� ���5
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP5_BORING_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 +
                           IOCMD_MTZ2to5_TOTAL*0 +
                           IOCMD4_MTZ2to5
                         ];

// �� ���5 ���
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP5_STAIGHT_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 +
                           IOCMD_MTZ2to5_TOTAL*0 +
                           IOCMD5_MTZ2to5
                         ];

// �� ���5 ���
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP5_BACK_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 +
                           IOCMD_MTZ2to5_TOTAL*0 +
                           IOCMD6_MTZ2to5
                         ];

// �� ���5 ��
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[STPDEV_MCP5_VLT_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 +
                           IOCMD_MTZ2to5_TOTAL*0 +
                           IOCMD7_MTZ2to5
                         ];

// ���� ���5
   //������� ��� ������ RT INTERFACE
   WideCmdStateINTERFACE[MCP5_OEPRF_ONB] =
	   //������� ��� ������ RT 
	   WideCmdRTBuffer[offsetIOCmdMTZ5 +
                           IOCMD_MTZ2to5_TOTAL*0 +
                           IOCMD6_MTZ2to5
                         ];


//  CompressorToINTERFACE();//���������� �������
   /*
  for (int i=0; i<DQUADRO; i++)
  {
     dataTrgCmdStateINTERFACE[i] |= dataCmdStateINTERFACE[i];//INTERFACE Trg CmdState
  }//for
*/
}//void TranslateINTERFACE()

/**********************************************
���������� �������
dataCmdStateINTERFACE - ��������� �� ������  Quadro
WideCmdStateINTERFACE - ��������� �� ������� ��� ������ INTERFACE
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
