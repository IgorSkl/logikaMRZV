#ifndef __CONSTANTS_MAL_H
#define __CONSTANTS_MAL_H

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif        

#define LED_TEST_BIT        21

#define NUMBER_PERIOD                    50
#define NUMBER_PERIOD_TRANSMIT           10
#define NUMBER_POINT                     40
#define MAIN_FREQUENCY                   50      //Гц
#define MIN_FREQUENCY                    45      //Гц
#define MAX_FREQUENCY                    55      //Гц

#define MIN_TICK_PERIOD                   (PER_CLK/MAX_FREQUENCY - 1)
#define MAX_TICK_PERIOD                   (PER_CLK/MIN_FREQUENCY + 1)

#define BASE_PERIOD_MEAS_SYSTEM_0       (1000000/(NUMBER_POINT*MAIN_FREQUENCY))     //мкс

#define VREF_NORMAL_VALUE_MIN_L2        0x7333
#define VREF_NORMAL_VALUE_MIN_L1        0x7999
#define VREF_NORMAL_VALUE               0x8000
#define VREF_NORMAL_VALUE_MAX_L1        0x8666
#define VREF_NORMAL_VALUE_MAX_L2        0x8CCC

#define VDD_NORMAL_VALUE_MIN_L2         0xBB7F
#define VDD_NORMAL_VALUE_MIN_L1         0xC5EA
#define VDD_NORMAL_VALUE                0xD055
#define VDD_NORMAL_VALUE_MAX_L1         0xDABF
#define VDD_NORMAL_VALUE_MAX_L2         0xE52A


#define TICK_HSTimer_MATCH0_1_2 (BASE_PERIOD_MEAS_SYSTEM_0*(PER_CLK/1000000))

#define MAX_TICK_FOR_START_READING_EEPROM_ERROR (5*PER_CLK) /*це число мало б відповідати періоду в 5*1с = 5c, поки ми не отримали відповіді від EEPROM*/ 

#define NUM_SPI                 2
#define N_SPI_1                   0
#define N_SPI_2                   1

#define NUM_CANALS_ADC          8

#define GPO_1_BIT               (1UL)
#define GPO_1                   _BIT(GPO_1_BIT)
#define GPO_2_BIT               (2UL)
#define GPO_2                   _BIT(GPO_2_BIT)
#define GPO_3_BIT               (3UL)
#define GPO_3                   _BIT(GPO_3_BIT)
#define GPO_4_BIT               (4UL)
#define GPO_4                   _BIT(GPO_4_BIT)

#define ADC1_READ1_BIT          0
#define ADC1_READ1              (1 << ADC1_READ1_BIT)
#define ADC2_READ1_BIT          1
#define ADC2_READ1              (1 << ADC2_READ1_BIT)
#define ADC3_READ1_BIT          2
#define ADC3_READ1              (1 << ADC3_READ1_BIT)

#define ADC1_READING_BIT        (28UL)
#define ADC1_READING            (unsigned int)(1 << ADC1_READING_BIT)

#define ADC2_READING_BIT        (29UL)
#define ADC2_READING            (unsigned int)(1 << ADC2_READING_BIT)

#define ADC3_READING_BIT        (30UL)
#define ADC3_READING            (unsigned int)(1 << ADC3_READING_BIT)

#define ADC4_READING_BIT        (31UL)
#define ADC4_READING            (unsigned int)(1 << ADC4_READING_BIT)

#define NUMBER_VREF_ADC1                2
#define NUMBER_VREF_ADC2                2
#define NUMBER_VREF_ADC3                3

#define ADJUSTMENT_3I0_IA_IB_IC_3U0_UA_UB_UC_ISYN_USYN_UBCTN2  0
#define ADJUSTMENT_ID                   ADJUSTMENT_3I0_IA_IB_IC_3U0_UA_UB_UC_ISYN_USYN_UBCTN2
//#define SPI1_RESYNCHRO_START            0
//#define SPI1_RESYNCHRO_FINISH           1
//#define SPI2_RESYNCHRO_START            2
//#define SPI2_RESYNCHRO_FINISH           3

#define NUMBER_VDD_ADC1                 1
#define NUMBER_VDD_ADC2                 1
#define NUMBER_VDD_ADC3                 1

#define ADC1_3I0_1                      0
#define ADC1_IC                         1
#define ADC1_IB                         2
#define ADC1_IA                         3
#define ADC1_3I0_16                     4
#define ADC1_VREF1                      5
#define ADC1_VREF2                      6
#define ADC1_VDD1                       7

#define ADC2_VREF1                      0
#define ADC2_UA                         1
#define ADC2_UB                         2
#define ADC2_UC                         3
#define ADC2_3U0_1                      4
#define ADC2_3U0_16                     5
#define ADC2_VREF2                      6
#define ADC2_VDD1                       7

#define ADC3_USYN                       0
#define ADC3_ISYN_1                     1
#define ADC3_ISYN_16                    2
#define ADC3_UBC_TN2                    3
#define ADC3_VREF1                      4
#define ADC3_VREF2                      5
#define ADC3_VREF3                      6
#define ADC3_VDD1                       7

#define FURJE_FAPCH_SPI1                _BIT(0)
#define FURJE_FAPCH_SPI2                _BIT(1)
#define INTERGRAL_VALUES                _BIT(2)

/*****************************************/
//Константи для фіксації зміни юстування
/*****************************************/
#define CHANGED_ETAP_NONE               0
#define CHANGED_ETAP_EXECUTION          1
#define CHANGED_ETAP_ENDED              2
/*****************************************/

#define PORIG_FOR_FAPCH_U 10000
#define PORIG_FOR_FAPCH_I 1000

#define SIN_COS_VAGA 7
#define AMPLITUDA_SIN_COS (1<<SIN_COS_VAGA)
#define USTUVANNJA_VAGA 12
#define DEFAULT_USTUVANNJA_VALUE ((1<<USTUVANNJA_VAGA) - 1)

/*****************************************/
//Константи для розширеного масиву миттєвих виборок
/*****************************************/
#define SPI1_INDEX_3I0                       0
#define SPI1_INDEX_IA                        1
#define SPI1_INDEX_IB                        2
#define SPI1_INDEX_IC                        3
#define SPI1_INDEX_3U0                       4
#define SPI1_INDEX_UA                        5
#define SPI1_INDEX_UB                        6
#define SPI1_INDEX_UC                        7

#define SPI2_INDEX_ISYN                      0
#define SPI2_INDEX_USYN                      1
#define SPI2_INDEX_UBC_TN2                   2
/*****************************************/

#define MAX_INDEX_DATA_FOR_OSCYLOGRAPH         10

/*****************************************/
//Константи для фазової корекції між шиною і лінією
/*****************************************/
#define INDEX_PhK_UA                     0
#define INDEX_PhK_UB                     1
#define INDEX_PhK_UC                     2
#define INDEX_PhK_ISYN                   3
#define INDEX_PhK_USYN                   4
/*****************************************/

/*****************************************/
//Константи для обчислення швидкості зміни кута
/*****************************************/
#define NUMBER_FOR_ANGLE_SPEED          5

#define CMD_AS_FIX_Ua_Ub_Uc_BIT         0
#define CMD_AS_FIX_Ua_Ub_Uc             (1 << CMD_AS_FIX_Ua_Ub_Uc_BIT)

#define CMD_AS_FIX_Isyn_Usyn_BIT        1
#define CMD_AS_FIX_Isyn_Usyn            (1 << CMD_AS_FIX_Isyn_Usyn_BIT)

#define CMD_AS_COPY_DATA_BIT            2
#define CMD_AS_COPY_DATA                (1 << CMD_AS_COPY_DATA_BIT)

#define INDEX_AS_UA                     0
#define INDEX_AS_UB                     1
#define INDEX_AS_UC                     2
#define INDEX_AS_ISYN                   3
#define INDEX_AS_USYN                   4

/*****************************************/

/*****************************************/
//Константи для обчислення швидкості зміни опору
/*****************************************/
#define NUMBER_FOR_RESISTOR_SPEED       1

#define CMD_RS_FIX_MEAS_BIT             0
#define CMD_RS_FIX_MEAS                 (1 << CMD_RS_FIX_MEAS_BIT)

#define CMD_RS_COPY_DATA_BIT            1
#define CMD_RS_COPY_DATA                (1 << CMD_RS_COPY_DATA_BIT)

#define INDEX_RS_IA                     0
#define INDEX_RS_IB                     1
#define INDEX_RS_IC                     2
#define INDEX_RS_UA                     3
#define INDEX_RS_UB                     4
#define INDEX_RS_UC                     5
/*****************************************/

#define TASK_500msk_BIT                 0
#define TASK_500mks                     (1 << TASK_500msk_BIT)

#define TASK_ANGLE_SPEED_BIT            1
#define TASK_ANGLE_SPEED                (1 << TASK_ANGLE_SPEED_BIT)

#define TASK_RESISTOR_SPEED_BIT         2
#define TASK_RESISTOR_SPEED             (1 << TASK_RESISTOR_SPEED_BIT)

#define TASK_1s_BIT                     3
#define TASK_1s                         (1 << TASK_1s_BIT)

#define TASK_MAKE_ENERGY_DATA_BIT       4
#define TASK_MAKE_ENERGY_DATA           (1 << TASK_MAKE_ENERGY_DATA_BIT)

#define TASK_CALC_ENERGY_BIT            5
#define TASK_CALC_ENERGY                (1 << TASK_CALC_ENERGY_BIT)

#define TASK_TEST_FLASH_MEMORY_BIT      6
#define TASK_TEST_FLASH_MEMORY          (1 << TASK_TEST_FLASH_MEMORY_BIT)

#define TASK_TEST_SETTINGS_BIT          7
#define TASK_TEST_SETTINGS              (1 << TASK_TEST_SETTINGS_BIT)

#define TASK_TEST_USTUVANNJA_BIT        8
#define TASK_TEST_USTUVANNJA            (1 << TASK_TEST_USTUVANNJA_BIT)

#define TASK_TEST_POWER_BIT             9
#define TASK_TEST_POWER                 (1 << TASK_TEST_POWER_BIT)
/*****************************************/


#define EXTERNAL_SRAM_OK                0x12345678

/*****************************************/
//Версія програмного забезпечення
/*****************************************/
#define VERSIA_PZ                                             1
#define MODYFIKACIA_VERSII_PZ                                 0
/*****************************************/


#endif
