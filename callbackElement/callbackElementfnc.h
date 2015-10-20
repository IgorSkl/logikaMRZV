

short CallBackElement(CALLBACK_MISSION *);
short OrderCallBack(CALLBACK_MISSION *, cBackTask *cbTmp);
short SetTaskParam1CallBack(CALLBACK_MISSION *, TASKMISSION_DEFINE1 *ptmDefine);

char callBackEEPROM_READ(CALLBACKELEMENT_TASK *);
char callBackEEPROM_WRITE(CALLBACKELEMENT_TASK *);
void initCallBackElement();
int  isActivStepElementDEVICE1();
int  isActivStepElementDEVICE2();





