
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

#include "bazisdef.h"
#include "psuperVisor\supermanager.h"

#include "psuperVisor\psvisor_helpfnc.h"
#include "virtualMenu\extmanagerfnc.h"

//������ ����������
/*
 ��������� ������� ����������
BYTE  ALTER EXT
BYTE  ALTER UST RANG
BYTE  0
BYTE  0

*/
//���� CRC ��� ext
UNS_32 ArrayEXTENTION[MAX_MNGEXT+1] = {40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56};//������ ����������

void SaveCRCext()
{
//��������� CRC ext
  //���������� alter
  ArrayEXTENTION[MAX_MNGEXT] = setCRCMassiv(&(ArrayEXTENTION[1]), MAX_MNGEXT-1); //CRC ��� ext
}//SaveCRCext()
