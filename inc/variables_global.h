#ifndef __GLOBAL_VARIABLES_H
#define __GLOBAL_VARIABLES_H

#ifdef _STATIC_MEMORY_BOOT
__root const unsigned int validation_code_and_memory_width @ "VC_and_MW" = 0x13579BD2;

extern unsigned short const __checksum;
extern unsigned int __checksum_begin;
extern unsigned int __checksum_end;

extern unsigned int __ICFEDIT_region_RAM_code_start__;
#else
extern unsigned int __ICFEDIT_region_RAM_date_start__;
#endif
extern unsigned int __ICFEDIT_region_RAM_date_no_cache_end__;

__no_init unsigned int external_SRAM_OK;

//__TOTAL_DATA_SEND total_data_send;

unsigned int temp = 0;

//INT_32 timerdev;
//
//SPI_CONFIG_T spicfg_1;
//INT_32 spidev_1;
//
//unsigned int counter_tick = 0;
//
unsigned int resurs_diagnostica = 0;
//unsigned int restart_resurs_count = 0;
//unsigned int resurs_temp = 0;
//unsigned int resurs_global = 0;
//unsigned int resurs_global_min = 0xffffffff;
//unsigned int resurs_global_max = 0;
//
////HSUART
//UNS_8 data[4] = {'W', 'O', 'R', 'D'};

#endif
