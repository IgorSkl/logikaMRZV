#ifndef _TEXTSTREAM
#define _TEXTSTREAM

#define WORKLOC_USER1   streamCntr->workCntr.ShortElement[0]
#define WORKLOC_CNTR1   streamCntr->workCntr.ShortElement[1]
#define WORKGLOB_CNTR1  streamCntr->workCntr.ShortElement[2]
#define WORKGLOB_MAX1   streamCntr->workCntr.ShortElement[3]
#define WORKKADR_EKR1   streamCntr->workCntr.ShortElement[4]
#define WORKKADR_CLK1   streamCntr->workCntr.ShortElement[5]
#define WORKMAKER_VBR1  streamCntr->workCntr.ShortElement[6]
#define WORKGLOB_OLD1   streamCntr->workCntr.ShortElement[7]
#define WORKCNTR_KADR1  streamCntr->workCntr.ShortElement[8]

#define CNTRLOC_USER1   workCntr->ShortElement[0]
#define CNTRLOC_CNTR1   workCntr->ShortElement[1]
#define CNTRGLOB_CNTR1  workCntr->ShortElement[2]

#define COMPARE_COUNTER if( CNTRLOC_CNTR1++==CNTRGLOB_CNTR1)
#define RESET_COUNTER   CNTRLOC_CNTR1=0

//#define UNS_32    unsigned int

typedef struct
{
  char TwoString[2][50];
}WorkVariantChar;

typedef struct
{
 short  ShortElement[9];
 void   *twoString;
 void   *userPoint;
}WorkControl;

typedef struct//управл структура текстового потока
{
 WorkControl workCntr;
 short  (*pKadrFormat)(void *);//(WorkControl *);//указатель на форм кадра
 short  PntStringViewer;//указател строки
 short  topStrPnt;//индекс верх элем
 short  StpStringViewer;//stp указател строки
}StreamControl;

#endif 

