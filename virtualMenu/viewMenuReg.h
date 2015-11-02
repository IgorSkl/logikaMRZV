
short  KadrMenuFormat_reg(void *workCntr);//(WorkControl *workCntr);
void KadrMaker(short idx, void *workCntr, UNS_32 *integE);//(short idx, WorkControl *workCntr, UNS_32 *integE);
char KadrFinder(UNS_32 *pQuadro,
                void (*pKadrMaker)(short , void *,//WorkControl *,
                                           UNS_32 *),
                void *workCntr,//WorkControl *workCntr,
                UNS_32 *integerE
               );
void OpenMenuReg();
void PereinitReg(short flg);

