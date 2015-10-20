
//номер миссии
#define CBACK_NOMISSION -1
#define CBACK_MISSION1   0
#define CBACK_MISSION2   1
#define CBACK_MISSION3   2
#define CBACK_MISSION4   3

#define CBACK_MISSION_1BWRITE_MASSIV 7
#define CBACK_MISSION_1BREAD_MASSIV  8
#define CBACK_MISSION_WRITE_ALTER    9

#define TASK_STEP0  0
#define TASK_STEP1  1
#define TASK_STEP2  2
#define TASK_STEP3  3
#define TASK_STEP4  4
#define TASK_STEP5  5
#define TASK_STEP6  6

//к-во блоков по 64 в миссии
#define BLOKMISSION_1    1
//макс к-во задач в миссии
#define MAX_TASKMISSION  2
//макс к-во циклов для мисии
#define MAX_CICLMISSION  10

typedef struct {//параметры отдельной задачи
  void *source;//массив - источник
  void *dest;//массив - приемник
  short count;//к-во
} TASKMISSION_DEFINE1;

typedef struct {
  void *source;
  void *dest;
  short count;
} TASKMISSION_DEFINE;

typedef struct {
	void *pTask;//указат на ф-ции задач
	int   callBackStepCntr;//счетчики шагов
        TASKMISSION_DEFINE tmDefine;//параметры отдельной задачи 
} CALLBACKELEMENT_TASK;

typedef struct {
        CALLBACKELEMENT_TASK callBackTask[MAX_TASKMISSION];//массив задач
	short callBackMaxer;   //максимальный действительный индекс массива возвр перехода
	short callBackIndexer; //текущий индекс массива возвратного перехода
} CALLBACK_MISSION;

typedef char (cBackTask(CALLBACKELEMENT_TASK *));//указатель на ф-цию callBack






