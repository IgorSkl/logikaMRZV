
int PLogTimerRES(int tNumber, int RES);
int PLogTimer   (int tNumber);
int FLogTimerRES(int tNumber, int RES);
int FLogTimer   (int tNumber);
int ILogTimerRES(int tNumber, int RES);
int ILogTimer   (int tNumber);
int InertLogTimer(int tNumber, int RES);
void initLogTimer(int tNumber);
int OFunctionRES(int tNumber, int cnf, int RES);
int OFunction   (int tNumber, int cnf);
void initTimers();
int getTimerCrr(int numTim);
int getTimerPorog(int numTim);
int getTimerBUSY(int numTim);
int getTimerFINISH(int numTim);
int getTimerENABLE(int numTim);
void setTimerENABLE(int numTim, int ena);
void setTimerPorog(int numTim, int porog);

void initTimers_WL();
int FLogTimer_WL   (int tNumber);
int PLogTimer_WL   (int tNumber);
void setTimerPorog_WL(int numTim, int porog);
int OFunction_WL   (int tNumber, int cnf);
int ILogTimer_WL   (int tNumber);
void setTimerENABLE_WL(int numTim, int ena);
void initLogTimer_WL(int tNumber);
int getTimerCrr_WL(int numTim);
int getTimerPorog_WL(int numTim);
int isTimerDelta(int numTim, int delta);




