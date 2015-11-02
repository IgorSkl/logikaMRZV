
void  TxtStreamInit(void *, short  (*pKadrFormat)(void *), void *userPoint);
short TxtStreamIteratorBegin(void *twoString, void *);
short TxtStreamIteratorMidle(void *);
void  TxtStreamIteratorEnd(void *);
short  TxtStreamUpButtonPrepare(void *);
short  TxtStreamDownButtonPrepare(void *);
short  TxtStreamPgDownButtonPrepare(void *);
short  TxtStreamPgUpButtonPrepare(void *);
void   TxtStreamCorrect(void *streamCntr);
short TxtStreamMaxKadr(void *streamCntr);
short TxtStreamIdxKadr(void *streamCntr);
void TxtStreamReset(void *streamCntr);
void TxtStreamSetEnd(void *streamCntr, short size_page);
void TxtStreamSetIdxKadr(void *streamCntr, short kadr);

