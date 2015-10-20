

typedef struct
{
  INT_32 *pntInputSignal;//указат на вх сигнал

  INT_32 ENABLE;
  INT_32 RESET;
  INT_32 BUSY;
  INT_32 FINISCH;

  INT_32 porogCNT;       //пороговое значение
  INT_32 crrCNT;         //текущее значение
} BAZIS_TIMER_MEM;




