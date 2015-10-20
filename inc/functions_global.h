#ifndef __GLOBAL_FUNCTIONS_H
#define __GLOBAL_FUNCTIONS_H

/* Prototype for external IRQ handler */
void lpc32xx_irq_handler(void);
/* Prototype for external IRQ handler */
void lpc32xx_fiq_handler(void);

int main();
void periodical_operations(void);
void global_vareiables_installation(void);
void start_settings(void);
void test_external_SRAM(void);

void hstimer_user_interrupt(void);

//void Gpi03_handler (void);
//void Gpi02_handler (void);
//void Sic2Handler (void);
//void Uart5Handler (void);

//uart
void uart_init(void);
void hsuart_init(void);
void hsuart_send_data(UNS_8 *data_pointer, int size);
void send_master_request(void);
void send_slave_confirm(void);
void send_master_confirm(void);
INT_32 start_uart_read(UNS_8 *buff, int bytes);
_Bool check_master_request(UNS_8 *ch_data, int size);
_Bool check_slave_confirm(UNS_8 *ch_data, int size);
_Bool check_master_confirm(UNS_8 *ch_data, int size);

#endif

