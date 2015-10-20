

//запускающий сигнал для таймера num
#define LSIGNAL_TIMER(num)   (logMassTimer[tmpOffsetT +num])
//таймер паузы - по уровню
#define PLOG_TIMER(num)      PLogTimer(tmpOffsetT +num)
//проверка дельты таймера
#define IS_TIMER_DELTA3(num)   isTimerDelta(tmpOffsetT +num, 2)
#define IS_TIMER_DELTA6(num)   isTimerDelta(tmpOffsetT +num, 4)
#define IS_TIMER_DELTA9(num)   isTimerDelta(tmpOffsetT +num, 6)
#define IS_TIMER_DELTA12(num)  isTimerDelta(tmpOffsetT +num, 8)
//таймер формирователь - по восх фронту
#define FLOG_TIMER(num)      FLogTimer(tmpOffsetT +num)
//таймер формирователь со сбросом - по восх фронту
#define FLOG_TIMERRES(num, res)   FLogTimerRES(tmpOffsetT +num, res)
#define ILOG_TIMERRES(num, res)   ILogTimerRES(tmpOffsetT +num, res)
//таймер формирователь - по нисх фронту
#define ILOG_TIMER(num)      ILogTimer(tmpOffsetT +num)

//обратная Офункция num/num+1 без сброса
#define ObrOFUNCTION(num)    OFunction(tmpOffsetT +num, 1)

//прямая Офункция num/num+1 без сброса
#define PrmOFUNCTION(num)    OFunction(tmpOffsetT +num, 0)


//запускающий сигнал для таймера num
#define LSIGNAL_TIMER_WL(num)   (logMassTimer_WL[tmpOffsetT +num])
//таймер паузы - по уровню
#define PLOG_TIMER_WL(num)      PLogTimer_WL(tmpOffsetT +num)
//таймер формирователь - по восх фронту
#define FLOG_TIMER_WL(num)      FLogTimer_WL(tmpOffsetT +num)
//таймер формирователь со сбросом - по восх фронту
#define FLOG_TIMERRES_WL(num, res)   FLogTimerRES_WL(tmpOffsetT +num, res)
//таймер формирователь - по нисх фронту
#define ILOG_TIMER_WL(num)      ILogTimer_WL(tmpOffsetT +num)

//обратная Офункция num/num+1 без сброса
#define ObrOFUNCTION_WL(num)    OFunction_WL(tmpOffsetT +num, 1)

//прямая Офункция num/num+1 без сброса
#define PrmOFUNCTION_WL(num)    OFunction_WL(tmpOffsetT +num, 0)


