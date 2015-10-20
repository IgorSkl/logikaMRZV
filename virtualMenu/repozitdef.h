
typedef struct
{
  short  kodC;           //код компонента
  char   rpzNameComponent[30];        //имя компонента
} NAME_RPZ;

typedef struct
{
  char   componentEnable;//разрешение компонента
  char  (*load2RPZ)(char packet);//загр в репозитарий
  NAME_RPZ  rpzKodName;//имя плюс код
  char   componentPermission;//компонент допущен
} ELEMENT_RPZ;

