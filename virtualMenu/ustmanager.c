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
#include "component\componentdef.h"
#include "virtualMenu\systemmenudef.h"
#include "virtualMenu\ustmanagerdef.h"

#include "virtualMenu\ustmanagerfnc.h"
#include "psuperVisor\psvisor_helpfnc.h"

#include "psuperVisor\psupervisor.h"

#include "..\bazis.h"

#include "toSpeedOptim.h"

void SaveUprPRM1(short numBit);
void SaveUprMTZ(short ibit);
void SaveUprAPV(short ibit);

extern COMPONENT_OBJ  cnfCOMPONENT[];
extern COMPONENT_OBJ  cnfCOMPONENT_WL[];

//��������� ����� ��� EEPROM 
char  tmp_eeprom[128*64];//MAX_MNGUSTAVKI*4����� *4�����
//4 ����� �������
int  blokUSTAVKI[4*MAX_MNGUSTAVKI+1];//���� CRC ��� EEPROM
//������� �������
int  mngUSTAVKI[MAX_MNGUSTAVKI+3];
//������� ������� ��
int  mngUSTAVKI_WL[MAX_MNGUSTAVKI_WL+3];
int  tmpUSTAVKI[100];

/**********************************************
�������� �������
������� �������
offsetUstMng - �������� �������
cntUstMng - �-�� �������
**********************************************/
void MngUstDeleteUSTAVKI(short offsetUstMng, short cntUstMng)
{
//������� ������� �� mngUst
  //���������� � ����
  memcpy((void*)getShadowBuf(), mngUSTAVKI, 4*MAX_MNGUSTAVKI);
//���������� �� ���� Begin
  if(offsetUstMng>0)
    memcpy(mngUSTAVKI, (void*)getShadowBuf(), 4*offsetUstMng);
//���������� �� ���� End
  memcpy(&(mngUSTAVKI[offsetUstMng]),
         &(((int *)getShadowBuf())[offsetUstMng+cntUstMng]),
         4*(MAX_MNGUSTAVKI-offsetUstMng-cntUstMng));
}//MngUstDeleteUSTAVKI(short offsetUstMng, short cntUstMng)

/**********************************************
�������� �������
������� ������� �� ��
offsetUstMng - �������� �������
cntUstMng - �-�� �������
**********************************************/
void MngUstDeleteUSTAVKI_WL(short offsetUstMng, short cntUstMng)
{
//������� ������� �� mngUst
  //���������� � ����
  memcpy((void*)getShadowBuf(), mngUSTAVKI_WL, 4*MAX_MNGUSTAVKI_WL);
//���������� �� ���� Begin
  if(offsetUstMng>0)
    memcpy(mngUSTAVKI_WL, (void*)getShadowBuf(), 4*offsetUstMng);
//���������� �� ���� End
  memcpy(&(mngUSTAVKI_WL[offsetUstMng]),
         &(((int *)getShadowBuf())[offsetUstMng+cntUstMng]),
         4*(MAX_MNGUSTAVKI_WL-offsetUstMng-cntUstMng));
}//MngUstDeleteUSTAVKI_WL(short offsetUstMng, short cntUstMng)

/**********************************************
�������� �������
�������� �������
cntUstMng - �-�� �������
**********************************************/
void MngUstTopAddUSTAVKI(short cntUstMng)
{
//�������� ������� �� ������� mng
  //���������� � ����
  memcpy((void*)getShadowBuf(), mngUSTAVKI, 4*MAX_MNGUSTAVKI);
  //���������� �� ����
  memcpy(&(mngUSTAVKI[cntUstMng]), (void*)getShadowBuf(), 4*(MAX_MNGUSTAVKI-cntUstMng));
  //����������
  memcpy(mngUSTAVKI, tmpUSTAVKI, 4*cntUstMng);
}//MngUstTopAddUSTAVKI(short cntUstMng)

/**********************************************
�������� �������
�������� ������� ��
cntUstMng - �-�� �������
**********************************************/
void MngUstTopAddUSTAVKI_WL(short cntUstMng)
{
//�������� ������� �� ������� mng WL
  //���������� � ����
  memcpy((void*)getShadowBuf(), mngUSTAVKI_WL, 4*MAX_MNGUSTAVKI_WL);
  //���������� �� ����
  memcpy(&(mngUSTAVKI_WL[cntUstMng]), (void*)getShadowBuf(), 4*(MAX_MNGUSTAVKI_WL-cntUstMng));
  //����������
  memcpy(mngUSTAVKI_WL, tmpUSTAVKI, 4*cntUstMng);
}//MngUstTopAddUSTAVKI_WL(short cntUstMng)

void SetUPR_COMMON1()
{
  /*
//���� ����������
  short ibit = LIGHTLINEMENU;//������ ����
  switch(cnfCOMPONENT[LIGHTCLON].kodC)
  {
  case PRM1_COMP1:
   SaveUprPRM1(ibit);//������������ ���� upr ��� PRM1
  break;

  case MTZ_COMP1:
   SaveUprMTZ(ibit);//������������ ���� upr ��� MTZ
  break;

  case APV_COMP1:
   SaveUprAPV(ibit);//������������ ���� upr ��� APV
  break;

//���������� ���������
  default:
  {
    UNS_32 tmpU = getCurrentMngUSTAVKI();//������� ��� ���
    if(FvmenuDis->UprCheck->Checked)
    {
      NumBitSettingWord(ibit, &tmpU);//��������� ���� �� ��� �������
    }//if(FvmenuDis->UprCheck->Checked)
    else
    {
      NumBitClearingWord(ibit, &tmpU);//����� ���� �� ��� �������
    }
  setCurrentMngUSTAVKI(tmpU);//����� ��� ���
  }//default
  }//switch

  if(LIGHTCLON>=0)
    PREPAREustCOMPONENT(LIGHTCLON);//����������  ���������� ������� spv ����������� �� ������
  else
    PREPAREustCOMPONENT_WL(LIGHTCLON);//����������  ���������� ������� spv ����������� �� ������ ��
*/    
}//SetUPR_COMMON1()

int AssembleUstButton()
{
  /*
//������� �������
  int dig = 0;
  sscanf(FvmenuDis->EditEdit->Text.Trim().c_str(), "%d", &dig);

  int tmp = setCurrentMngUSTAVKI(dig);
  if(tmp<0) return tmp;//������ ������
//  if((kodC==PRM1_COMP1)&&((numUst==MNGUST_PRM1_BO)||(numUst==MNGUST_PRM1_BV)))
  //      PrepareBOBVtimer();//����������� ������� ���� ����, ���� ���
  if(LIGHTCLON>=0)
    PREPAREustCOMPONENT(LIGHTCLON);//����������  ���������� ������� spv ����������� �� ������
  else
    PREPAREustCOMPONENT_WL(LIGHTCLON);//����������  ���������� ������� spv ����������� �� ������ ��
*/  
  return 0;
}//AssembleUstButton()

int setCurrentMngUSTAVKI(int ust)
{
//�������� ������� �������
//codec=0-������������ �������
  int tmp=0;
  if(LIGHTCLON>=0)
  {
    tmp = cnfCOMPONENT[LIGHTCLON].
          codecUst(0, LIGHTMNGUBAZA+ LIGHTMNGUOFFSET, ust);
    if(tmp<0) return tmp;//������
    mngUSTAVKI[getOffsetMngUSTAVKI(LIGHTMNGUOFFSET)] = tmp;//���
  }//if
  else
  {
//���� CLON<0 �� ��� ��
    int tmp = cnfCOMPONENT_WL[-LIGHTCLON-1].
              codecUst(0, LIGHTMNGUBAZA+ LIGHTMNGUOFFSET, ust);
    if(tmp<0) return tmp;//������
    mngUSTAVKI_WL[getOffsetMngUSTAVKI(LIGHTMNGUOFFSET)] = tmp;//���
  }
  return tmp;//�������
}//setCurrentMngUSTAVKI()

int setClonMngUSTAVKI(int idxC, int bazaOffset, int ust)
{
//�������� �������� bazaOffset ������� ust � ���� idxC
//codec=0-������������ �������
  int tmp=0;
  if(LIGHTCLON>=0)
  {
    tmp = cnfCOMPONENT[idxC].//LIGHTCLON].
          codecUst(0, bazaOffset, ust);
    if(tmp==ERROR_UST) return ERROR_UST;//������
    
//    int tttt1 = getClonOffsetMngUSTAVKI(idxC, bazaOffset);
    mngUSTAVKI[getClonOffsetMngUSTAVKI(idxC, bazaOffset)] = tmp;//���
  }//if
  else
  {
//���� CLON<0 �� ��� ��
    int tmp = cnfCOMPONENT_WL[-idxC-1].
              codecUst(0, bazaOffset, ust);
    if(tmp<0) return tmp;//������
    mngUSTAVKI_WL[getClonOffsetMngUSTAVKI(idxC, bazaOffset)] = tmp;//���
  }
  return tmp;//�������
}//setClonMngUSTAVKI(int idxC, int bazaOffset, int ust)

int getUstOffsetMngUSTAVKI(short offset)
{
//���� CLON<0 �� ��� ��
//��������� ��� ������� �� ��������
//codec=1-������������� �������
  if(LIGHTCLON>=0)
    return cnfCOMPONENT[LIGHTCLON].
           codecUst(1, LIGHTMNGUBAZA + LIGHTMNGUOFFSET,
                    mngUSTAVKI[getOffsetMngUSTAVKI(offset)]);
//��
  return cnfCOMPONENT_WL[-LIGHTCLON-1].
         codecUst(1, LIGHTMNGUBAZA + LIGHTMNGUOFFSET,
                  mngUSTAVKI_WL[getOffsetMngUSTAVKI(offset)]);
}//getOffsetMngUSTAVKI(short idx)

UNS_32 getCurrentMngUSTAVKI()
{
//��������� ������� �������
  return getUstOffsetMngUSTAVKI(LIGHTMNGUOFFSET);
}//getCurrentMngUSTAVKI()

short getOffsetMngUSTAVKI(short offset)
{
//��������� ��� �������� �������
//���� CLON<0 �� ��� ��
  if(LIGHTCLON>=0)
    return cnfCOMPONENT[LIGHTCLON].offsetUstMng +
           LIGHTMNGUBAZA + offset;

//int tt1 = -LIGHTCLON-1;
  return cnfCOMPONENT_WL[-LIGHTCLON-1].offsetUstMng +
         LIGHTMNGUBAZA + offset;
}//getOffsetMngUSTAVKI()

short getClonOffsetMngUSTAVKI(short idxC, short offset)
{
//��������� �������� ������� ����� idxC
//���� CLON<0 �� ��� ��
  if(idxC>=0)
    return cnfCOMPONENT[idxC].offsetUstMng +
           //LIGHTMNGUBAZA +
           offset;

  return cnfCOMPONENT_WL[-idxC-1].offsetUstMng +
         //LIGHTMNGUBAZA +
         offset;
}//getClonOffsetMngUSTAVKI(short idxC, short offset)

short getOffsetNativMngUSTAVKI(short idxC, short offsetUpr)
{
//��������� �������� �������
  return cnfCOMPONENT[idxC].offsetUstMng + offsetUpr;
}//getOffsetNativMngUSTAVKI(short offset)

int getNativUstMngUSTAVKI(short idxC, short offset)
{
//��������� ������� �� ������� ����� � ��������
//���� CLON<0 �� ��� ��
//  int ttttttt5 = cnfCOMPONENT[idxC].offsetUstMng + offset;
  if(idxC>=0)
    return  mngUSTAVKI[cnfCOMPONENT[idxC].offsetUstMng + offset];

  return  mngUSTAVKI_WL[cnfCOMPONENT_WL[-idxC-1].offsetUstMng + offset];
}//getNativUstMngUSTAVKI(short idxC, short offset)

int getMngUSTAVKI(short baza, short offset)
{
    return  mngUSTAVKI[baza + offset];
}//getMngUSTAVKI(short baza, short offset)

void CopyMngUstavki(int numBlok)
{
//���������� ��� ������� �� numBlok ����
 memcpy(&(blokUSTAVKI[numBlok*MAX_MNGUSTAVKI]), mngUSTAVKI, 4*MAX_MNGUSTAVKI);
}//CopyMngUstavki(int numBlok)

void CopyEEPROMtoUstavki(int numBlok)
{
//���������� ������ �� EEPROM � ������� �������
extern char  tmp_eeprom[];//MAX_MNGUSTAVKI*4����� *4�����
//numBlok - ����� ����� �������
 memcpy(blokUSTAVKI, tmp_eeprom, 4*(4*MAX_MNGUSTAVKI+1));//��� 4 ������ ������� � CRC
 memcpy(mngUSTAVKI, &(blokUSTAVKI[numBlok*MAX_MNGUSTAVKI]), MAX_MNGUSTAVKI);
}//CopyMngUstavki(int numBlok)

void SaveAsBlokUstavki(int numBlok)
{
//��������� ��� ��� ��� ���� �������
  CopyMngUstavki(numBlok);//���������� ��� ������� �� numBlok
  blokUSTAVKI[4*MAX_MNGUSTAVKI] = setCRCMassiv(blokUSTAVKI, 4*MAX_MNGUSTAVKI); //CRC ��� 4 ������ �������
}//SaveAsBlokUstavki(int numBlok)

int getCRCUstavki()
{
//�������� CRC �������
  return blokUSTAVKI[4*MAX_MNGUSTAVKI]; //CRC ��� 4 ������ �������
}//getCRCUstavki()
