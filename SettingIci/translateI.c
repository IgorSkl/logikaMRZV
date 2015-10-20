
#include "header.h"
#include "ici_r_ef.h"

#include "bazisdef.h"
#include "toSpeedOptim.h"
#include "psuperVisor\supermanager.h"

#define _HIDE_COMPONENT
#include "MTZ1Component.c"
#include "MTZ2Component.c"
#include "DZ1Component.c"
#include "DZ2Component.c"
#include "TZNP1Component.c"
#include "NZOP1Component.c"
#include "UMMComponent.c"

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
UNS_32 buffTrgCmdStateINTERFACE[DQUADRO];//INTERFACE CmdState
UNS_32 buffCmdStateINTERFACE[DQUADRO];//INTERFACE CmdState
UNS_32 buffInStateINTERFACE;//INTERFACE  In
UNS_32 buffOutStateINTERFACE;//INTERFACE Out
UNS_32 buffLedStateINTERFACE;//INTERFACE Led
UNS_32 buffTrgOutStateINTERFACE;//INTERFACE Trg Out
UNS_32 buffTrgLedStateINTERFACE;//INTERFACE Trg Led
UNS_32 buffGruppaUstINTERFACE;//������ �������
int  isTimeSection;//����������� ������ � ������� ��������

void TranslateINTERFACE() @ "Fast_function"
{
//������� ��� ������ RT INTERFACE
int   WideCmdStateINTERFACE[SIZE_RANGIRCMD+3];
//����������������� ������� ��� ������
#include "translateI_MTZ.ci" //MTZ
#include "translateI_DZ.ci" //DZ
#include "translateI_TZNP.ci" //TZNP
#include "translateI_NZOP.ci" //NZOP
#include "translateI_UMM.ci" //UMM

//���������� �������
  for (int i=0; i<DQUADRO; i++)
  {
    UNS_32 tmp = 0;
    for (int b=0; b<32; b++)
    {
      if (WideCmdStateINTERFACE[i*32+b])
      {
        tmp |= 1<<b;
      }
    }//for
    dataCmdStateINTERFACE[i] = tmp;
  }//for
   
  for (int i=0; i<DQUADRO; i++)
  {
     dataTrgCmdStateINTERFACE[i] |= dataCmdStateINTERFACE[i];//INTERFACE Trg CmdState
  }//for

}//void TranslateINTERFACE()

