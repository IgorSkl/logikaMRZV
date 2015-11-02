

#ifndef _SUPERMANAGER
#define _SUPERMANAGER

//к-во int-регистров в Quadro
#define DQUADRO        10

//определение РегистрацияДИС 
#define REGDIS_SM    -1
//определение ЗапускАПВ 
#define PUSKAPV_SM   -2
//определение ЗапускУРОВ 
#define PUSKUROV_SM  -3
//определение Запуск1ОФ
#define PUSK1OF_SM   -4
//определение Запуск2ОФ
#define PUSK2OF_SM   -5
//определение Запуск3ОФ
#define PUSK3OF_SM   -6
//определение Запуск1ОФ2
#define PUSK1OF2_SM   -7
//определение Запуск2ОФ2
#define PUSK2OF2_SM   -8
//определение Запуск3ОФ2
#define PUSK3OF2_SM   -9
//определение Запуск1ОФ3
#define PUSK1OF3_SM   -10
//определение Запуск2ОФ3
#define PUSK2OF3_SM   -11
//определение Запуск3ОФ3
#define PUSK3OF3_SM   -12
//определение Запуск1ОФ4
#define PUSK1OF4_SM   -13
//определение Запуск2ОФ4
#define PUSK2OF4_SM   -14
//определение Запуск3ОФ4
#define PUSK3OF4_SM   -15
//определение Запуск1ОФ5
#define PUSK1OF5_SM   -16
//определение Запуск2ОФ5
#define PUSK2OF5_SM   -17
//определение Запуск3ОФ5
#define PUSK3OF5_SM   -18
//определение Запуск1ОФ6
#define PUSK1OF6_SM   -19
//определение Запуск2ОФ6
#define PUSK2OF6_SM   -20
//определение Запуск3ОФ6
#define PUSK3OF6_SM   -21
//определение Запуск1ОФ7
#define PUSK1OF7_SM   -22
//определение Запуск2ОФ7
#define PUSK2OF7_SM   -23
//определение Запуск3ОФ7
#define PUSK3OF7_SM   -24
//определение Запуск1ОФ8
#define PUSK1OF8_SM   -25
//определение Запуск2ОФ8
#define PUSK2OF8_SM   -26
//определение Запуск3ОФ8
#define PUSK3OF8_SM   -27
//определение Запуск1ОФ9
#define PUSK1OF9_SM   -28
//определение Запуск2ОФ9
#define PUSK2OF9_SM   -29
//определение Запуск3ОФ9
#define PUSK3OF9_SM   -30
//определение Запуск1ОФ10
#define PUSK1OF10_SM   -31
//определение Запуск2ОФ10
#define PUSK2OF10_SM   -32
//определение Запуск3ОФ10
#define PUSK3OF10_SM   -33
//определение Запуск1ОФ11
#define PUSK1OF11_SM   -34
//определение Запуск2ОФ11
#define PUSK2OF11_SM   -35
//определение Запуск3ОФ11
#define PUSK3OF11_SM   -36
//определение Запуск1ОФ12
#define PUSK1OF12_SM   -37
//определение Запуск2ОФ12
#define PUSK2OF12_SM   -38
//определение Запуск3ОФ12
#define PUSK3OF12_SM   -39
//определение Запуск1ОФ13
#define PUSK1OF13_SM   -40
//определение Запуск2ОФ13
#define PUSK2OF13_SM   -41
//определение Запуск3ОФ13
#define PUSK3OF13_SM   -42
//определение Запуск1ОФ14
#define PUSK1OF14_SM   -43
//определение Запуск2ОФ14
#define PUSK2OF14_SM   -44
//определение Запуск3ОФ14
#define PUSK3OF14_SM   -45
//определение Запуск1ОФ15
#define PUSK1OF15_SM   -46
//определение Запуск2ОФ15
#define PUSK2OF15_SM   -47
//определение Запуск3ОФ15
#define PUSK3OF15_SM   -48
//определение Запуск1ОФ16
#define PUSK1OF16_SM   -49
//определение Запуск2ОФ16
#define PUSK2OF16_SM   -50
//определение Запуск3ОФ16
#define PUSK3OF16_SM   -51

//определение Запуск1ОT1
#define PUSK1OT1_SM   -52
//определение Запуск2ОT1
#define PUSK2OT1_SM   -53
//определение Запуск1ОT1
#define PUSK3OT1_SM   -54
//определение Запуск2ОT1
#define PUSK4OT1_SM   -55

//определение Запуск1ОT2
#define PUSK1OT2_SM   -56
//определение Запуск2ОT2
#define PUSK2OT2_SM   -57
//определение Запуск1ОT2
#define PUSK3OT2_SM   -58
//определение Запуск2ОT2
#define PUSK4OT2_SM   -59

//определение Запуск1ОT3
#define PUSK1OT3_SM   -60
//определение Запуск2ОT3
#define PUSK2OT3_SM   -61
//определение Запуск1ОT3
#define PUSK3OT3_SM   -62
//определение Запуск2ОT3
#define PUSK4OT3_SM   -63

//определение Запуск1ОT4
#define PUSK1OT4_SM   -64
//определение Запуск2ОT4
#define PUSK2OT4_SM   -65
//определение Запуск1ОT4
#define PUSK3OT4_SM   -66
//определение Запуск2ОT4
#define PUSK4OT4_SM   -67

//определение Запуск1ОT5
#define PUSK1OT5_SM   -68
//определение Запуск2ОT5
#define PUSK2OT5_SM   -69
//определение Запуск1ОT5
#define PUSK3OT5_SM   -70
//определение Запуск2ОT5
#define PUSK4OT5_SM   -71

//определение Запуск1ОT6
#define PUSK1OT6_SM   -72
//определение Запуск2ОT6
#define PUSK2OT6_SM   -73
//определение Запуск1ОT6
#define PUSK3OT6_SM   -74
//определение Запуск2ОT6
#define PUSK4OT6_SM   -75

//определение Запуск1ОT7
#define PUSK1OT7_SM   -76
//определение Запуск2ОT7
#define PUSK2OT7_SM   -77
//определение Запуск1ОT7
#define PUSK3OT7_SM   -78
//определение Запуск2ОT7
#define PUSK4OT7_SM   -79

//определение Запуск1ОT8
#define PUSK1OT8_SM   -80
//определение Запуск2ОT8
#define PUSK2OT8_SM   -81
//определение Запуск1ОT8
#define PUSK3OT8_SM   -82
//определение Запуск2ОT8
#define PUSK4OT8_SM   -83

//определение Сброс Блока Включения
#define RESETBV_SM    -84

//определение ДВ в суперменеджере
#define DV1_SM       0
#define DV2_SM       1
#define DV3_SM       2
#define DV4_SM       3
#define DV5_SM       4
#define DV6_SM       5
#define DV7_SM       6
#define DV8_SM       7
#define DV9_SM       8
#define DV10_SM      9
#define DV11_SM      10
#define DV12_SM      11
#define DV13_SM      12
#define DV14_SM      13
#define DV15_SM      14
#define DV16_SM      15
#define DV17_SM      16
#define DV18_SM      17
#define DV19_SM      18
#define DV20_SM      19
#define DV21_SM      20
#define DV22_SM      21
#define DV23_SM      22
#define DV24_SM      23
#define DV25_SM      24
#define DV26_SM      25
#define DV27_SM      26
#define DV28_SM      27
#define DV29_SM      28
#define DV30_SM      29
#define DV31_SM      30
#define DV32_SM      31
#define DV33_SM      32
#define DV34_SM      33
#define DV35_SM      34
#define DV36_SM      35
//к-во ДВ в системе
#define DV_TOTAL       36
//определение РЕЛЕ в суперменеджере
#define RELE1_SM       36
#define RELE2_SM       37
#define RELE3_SM       38
#define RELE4_SM       39
#define RELE5_SM       40
#define RELE6_SM       41
#define RELE7_SM       42
#define RELE8_SM       43
#define RELE9_SM       44
#define RELE10_SM      45
#define RELE11_SM      46
#define RELE12_SM      47
#define RELE13_SM      48
#define RELE14_SM      49
#define RELE15_SM      50
#define RELE16_SM      51
//к-во РЕЛЕ в системе
#define RELE_TOTAL     16
//определение СДИ в суперменеджере
#define CDI1_SM        52
#define CDI2_SM        53
#define CDI3_SM        54
#define CDI4_SM        55
#define CDI5_SM        56
#define CDI6_SM        57
#define CDI7_SM        58
#define CDI8_SM        59
#define CDI9_SM        60
#define CDI10_SM       61
#define CDI11_SM       62
#define CDI12_SM       63
#define CDI13_SM       64
#define CDI14_SM       65
//к-во СДИ в системе
#define CDI_TOTAL      14
//к-во UVV в системе
#define UVV_TOTAL     (DV_TOTAL+RELE_TOTAL+CDI_TOTAL)

//константы инит уставок компонентов
//ни одного компонента
#define INITUST_NULLCOMP  -2
//все компоненты
#define INITUST_ALLCOMP   -1
//только top компонент
#define INITUST_TOPCOMP   0
//>0 конкр компонент

//макс емкость конфигурации, компоненты
#define MAX_CNFCOMPONENT 50
//макс емкость конфигурации РЛ, компоненты
#define MAX_WLCOMPONENT   10
//макс емкость массива уставок супервизора, регистры
#define MAX_SPVUSTAVKI   450
//макс емкость массива уставок РЛ, регистры
#define MAX_SPVUSTAVKI_WL 100
//макс емкость массива уставок менеджера, регистры
#define MAX_MNGUSTAVKI   500
//макс емкость массива ранж менеджера, регистры
#define MAX_MNGRANG      (DQUADRO*UVV_TOTAL)
//макс емкость массива ext менеджера, регистры
#define MAX_MNGEXT       50
//макс емкость массива уставок менеджера РЛ, регистры
#define MAX_MNGUSTAVKI_WL 100
//макс емкость ENA команд
#define MAX_ENACMD     200
//макс емкость ENA команд  РЛ
#define MAX_ENACMD_WL  50
//макс емкость массива локальной логики
#define MAX_TEMPLOG    700
//макс емкость массива локальной логики РЛ
#define MAX_TEMPLOG_WL 100
//размер массива имени iocmd
#define SIZE_NAMEIOCOMMAND 32

//к-во лог элементов
#define LE_TOTAL       64
//максимум Допуск ДВ
#define DDV_MAX        100
//размер ДИС
#define SIZE_DIS       100
//к-во таймеров в системе
#define MAX_LOGTIMER         300
//к-во таймеров в системе РЛ
#define MAX_LOGTIMER_WL      100

//размер массива ранжирования iocmd
#define SIZE_RANGIRCMD 320

#endif // _SUPERMANAGER
