
//номер пакетного компонента
#define MTZ_PACKET  1
#define DZ_PACKET   2
#define TZNP_PACKET 3
#define NZOP_PACKET 4

//код компонентов
#define MTZ_COMP1   10

#define DZ_COMP1    11

#define TZNP_COMP1  12

#define NZOP_COMP1  13

#define UROV_COMP1   14
#define APV_COMP1    15
#define OF_COMP1     16
#define PRM1_COMP1   17
#define WL_COMP1     18
#define PF_COMP1     19
#define UMM_COMP1    20

typedef struct
{
  void (*twin_different)( );    //ф-я изменения близнецов
}  TWIN_DIFFERENT;//контроль близнецов

typedef struct
{
//имена и статус IO команд
  short  statusIO;
  char   *nameIO;
} IONAMESTATUS_COMPONENT;

typedef struct
{
  char   componentEnable;//разрешение компонента

  short  kodC;           //код компонента
  short  cntClon;   //к-во клонов
  short  numClon;   //номер клона
  short  packet;    //номер пакетного компонента
  short  permanent; //перманентный компонент
  int    workToSignal; //Работа на сигнал

  void  (*logic)(int);//логика компонента
  int   offsetTimers;   //начало таймеров
  void  (*initTimers)(short); //инициал таймеров
  int   offsetUstSpv;   //смещение уставок внутри супервизора
  int   offsetUstMng;   //смещение уставок внутри менеджера уставок
  int   cntUstMng;      //количество уставок компонента внутри менеджера уставок
  void  (*prepareUstSpv)(short);//подготовка уставок
  int   (*initUstMng)(char );    //инициал уставок
  int   offsetIOCmd;    //начало IO команд
  int   cntIOCmd;       //количество IO команд
  int   (*initIOCmd)(); //инициал IO команд
  int   offsetTLCmd;    //начало TL команд
  int   cntTLCmd;       //количество TL команд
  int   (*initTLCmd)(); //инициал TL команд
  int   offsetENACmd;   //начало ENA команд
  int   cntENACmd;      //количество ENA команд
  int   (*initENACmd)(); //инициал ENA команд
  void  (*bo_bvCmd)(int numC, int mode, int nrele); //настройка БО БВ команд
  int   (*codecUst)(char codec, short offset, int ust);   //кодировать-раскодировать уставку
  int   (*isDISactiv)(int); //активность Регистратора ДИС
  void  (*setBOBVtimer)(int); //инициал таймеров БО БВ

  char   nameComponent[30];        //имя компонента
  void  *sub_menu_component;//меню компонента

  TWIN_DIFFERENT *twinControl;//массив контроля близнецов

  IONAMESTATUS_COMPONENT *nameStatusIO; //имена и статус IO команд компонента

} COMPONENT_OBJ;



