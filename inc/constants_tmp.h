#ifndef __CONSTANTS_TMP_H
#define __CONSTANTS_TMP_H

// TICK_PER_SECOND
#define TICK_SEC_S1_5 (150  * (PER_CLK/(13*1000)))
#define TICK_SEC_S3   (300  * (PER_CLK/(13*1000)))
#define TICK_SEC_1S   (1000 * (PER_CLK/(13*1000)))


#define LED1          (1UL << 1)
#define LED2          (1UL << 14)

#define BUTTON_DLY    5000

#define BAUD          115200

#define TX_BUFFER_SIZE 2000

#endif
