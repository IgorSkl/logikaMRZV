

//����������� ������ ��� ������� num
#define LSIGNAL_TIMER(num)   (logMassTimer[tmpOffsetT +num])
//������ ����� - �� ������
#define PLOG_TIMER(num)      PLogTimer(tmpOffsetT +num)
//�������� ������ �������
#define IS_TIMER_DELTA3(num)   isTimerDelta(tmpOffsetT +num, 2)
#define IS_TIMER_DELTA6(num)   isTimerDelta(tmpOffsetT +num, 4)
#define IS_TIMER_DELTA9(num)   isTimerDelta(tmpOffsetT +num, 6)
#define IS_TIMER_DELTA12(num)  isTimerDelta(tmpOffsetT +num, 8)
//������ ������������� - �� ���� ������
#define FLOG_TIMER(num)      FLogTimer(tmpOffsetT +num)
//������ ������������� �� ������� - �� ���� ������
#define FLOG_TIMERRES(num, res)   FLogTimerRES(tmpOffsetT +num, res)
#define ILOG_TIMERRES(num, res)   ILogTimerRES(tmpOffsetT +num, res)
//������ ������������� - �� ���� ������
#define ILOG_TIMER(num)      ILogTimer(tmpOffsetT +num)

//�������� �������� num/num+1 ��� ������
#define ObrOFUNCTION(num)    OFunction(tmpOffsetT +num, 1)

//������ �������� num/num+1 ��� ������
#define PrmOFUNCTION(num)    OFunction(tmpOffsetT +num, 0)


//����������� ������ ��� ������� num
#define LSIGNAL_TIMER_WL(num)   (logMassTimer_WL[tmpOffsetT +num])
//������ ����� - �� ������
#define PLOG_TIMER_WL(num)      PLogTimer_WL(tmpOffsetT +num)
//������ ������������� - �� ���� ������
#define FLOG_TIMER_WL(num)      FLogTimer_WL(tmpOffsetT +num)
//������ ������������� �� ������� - �� ���� ������
#define FLOG_TIMERRES_WL(num, res)   FLogTimerRES_WL(tmpOffsetT +num, res)
//������ ������������� - �� ���� ������
#define ILOG_TIMER_WL(num)      ILogTimer_WL(tmpOffsetT +num)

//�������� �������� num/num+1 ��� ������
#define ObrOFUNCTION_WL(num)    OFunction_WL(tmpOffsetT +num, 1)

//������ �������� num/num+1 ��� ������
#define PrmOFUNCTION_WL(num)    OFunction_WL(tmpOffsetT +num, 0)


