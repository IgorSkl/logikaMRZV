/* Prototype for external IRQ handler */
extern void lpc32xx_irq_handler(void);
/* Prototype for external FIQ handler */
extern void lpc32xx_fiq_handler(void);

extern void save_partial_VFP_state(struct partial_VFP_state_t*);
extern void restore_partial_VFP_state(struct partial_VFP_state_t*);

extern int main();
extern void periodical_operations(void);
extern void global_vareiables_installation(void);
extern void start_settings(void);
extern void test_external_SRAM(void);

extern void hstimer_user_interrupt(void);

//extern void Gpi03_handler (void);
//extern void Gpi02_handler (void);
//extern void Sic2Handler (void);
//extern void Uart5Handler (void);

//uart
extern void uart_init(void);
extern void hsuart_init(void);
extern void hsuart_send_data(UNS_8 *data_pointer, int size);
extern void send_master_request(void);
extern void send_slave_confirm(void);
extern void send_master_confirm(void);
extern INT_32 start_uart_read(UNS_8 *buff, int bytes);
extern _Bool check_master_request(UNS_8 *ch_data, int size);
extern _Bool check_slave_confirm(UNS_8 *ch_data, int size);
extern _Bool check_master_confirm(UNS_8 *ch_data, int size);

