MODE_MSK DEFINE 0x1F            ; Bit mask for mode bits in CPSR
USR_MODE DEFINE 0x10            ; User mode
FIQ_MODE DEFINE 0x11            ; Fast Interrupt Request mode
IRQ_MODE DEFINE 0x12            ; Interrupt Request mode
SVC_MODE DEFINE 0x13            ; Supervisor mode
ABT_MODE DEFINE 0x17            ; Abort mode
UND_MODE DEFINE 0x1B            ; Undefined Instruction mode
SYS_MODE DEFINE 0x1F            ; System mode

#define I_BIT            0x80
#define F_BIT            0x40

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; $Id: lpc32xx_vectors.s 30870 2009-07-05 10:16:16Z anderslu $
; 
; Project: LPC32xx interrupt and exception vectors
;
; Description:
;     Interrupt and exception handler vector layout used by the
;     interrupt driver, exception functions, and startup code. This
;     block is placed at the start of the ARM memory region at address
;     0x00000000 or 0xFFFF0000 (if high vectors are enabled).
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 ; Software that is described herein is for illustrative purposes only  
 ; which provides customers with programming information regarding the  
 ; products. This software is supplied "AS IS" without any warranties.  
 ; NXP Semiconductors assumes no responsibility or liability for the 
 ; use of the software, conveys no license or title under any patent, 
 ; copyright, or mask work right to the product. NXP Semiconductors 
 ; reserves the right to make changes in the software without 
 ; notification. NXP Semiconductors also make no representation or 
 ; warranty that such application will be suitable for the specified 
 ; use without further testing or modification. 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    MODULE ?lpc32xx_vectors
    
    PUBLIC lpc32xx_reset_vector
    PUBLIC vec_reset_handler
    PUBLIC vec_undefined_handler
    PUBLIC vec_swi_handler
    PUBLIC vec_prefetch_handler
    PUBLIC vec_abort_handler
    PUBLIC vec_irq_handler
    PUBLIC vec_fiq_handler
    
    PUBLIC lpc32xx_irq_handler
    PUBLIC lpc32xx_fiq_handler
    EXTERN irq_func_ptrs
    

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Function: Basic interrupt and exception jump block
;
; Purpose: Block that defines the interrupt and exception jump points
;
; Description:
;     On a bootable image that is being built, this area should be
;     linked to address 0x00000000. This area may be used with the
;     interrupt and exception drivers when installing handlers and
;     routers. For each interrupt and exception that gets routed
;     here, the indirect PC value of the handler function is loaded
;     to jump to that function.
;
; Parameters: NA
;
; Outputs; NA
;
; Returns: NA
;
; Notes: NA
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

  SECTION .text:CODE:ROOT(2)
  ARM
        
lpc32xx_reset_vector
    LDR  pc, [pc, #24]          ; Get address of Reset handler
    LDR  pc, [pc, #24]          ; Get address of Undefined handler
    LDR  pc, [pc, #24]          ; Get address of SWI handler
    LDR  pc, [pc, #24]          ; Get address of Prefetch handler
    LDR  pc, [pc, #24]          ; Get address of Abort handler
    NOP                         ; Reserved
    LDR  pc, [pc, #20]          ; Get address of IRQ handler
    LDR  pc, [pc, #20]          ; Get address of FIQ handler

vec_reset_handler
    DCD  lpc32xx_reset_handler

vec_undefined_handler
    DCD  lpc32xx_undefined_handler

vec_swi_handler
    DCD  lpc32xx_swi_handler

vec_prefetch_handler
    DCD  lpc32xx_prefetch_handler

vec_abort_handler
    DCD  lpc32xx_abort_handler

vec_irq_handler
    DCD  lpc32xx_irq_handler

vec_fiq_handler
    DCD  lpc32xx_fiq_handler

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
; Function: lpc32xx_reset_handler
;
; Purpose:
;   Default reset handler
; 
; Processing:
;   Loop forever
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes:
;     The board startup code does not use this handler! However, when
;     the interrupt and exception table is installed, the reset handler
;     will be updated to this handler.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
lpc32xx_reset_handler
    B    lpc32xx_reset_handler

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
; Function: lpc32xx_undefined_handler
;
; Purpose:
;   Handle the undefined exception
; 
; Processing:
;   Loop forever
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes: None
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
lpc32xx_undefined_handler
    B    lpc32xx_undefined_handler

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
; Function: lpc32xx_swi_handler
;
; Purpose:
;   Handle the software interrupt
; 
; Processing:
;   Loop forever
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes: None
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
lpc32xx_swi_handler
    B    lpc32xx_swi_handler

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
; Function: lpc32xx_prefetch_handler
;
; Purpose:
;   Handle the prefetch abort exception
; 
; Processing:
;   Loop forever
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes: None
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
lpc32xx_prefetch_handler
    B    lpc32xx_prefetch_handler

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
; Function: lpc32xx_abort_handler
;
; Purpose:
;   Handle the abort exception
; 
; Processing:
;   Loop forever
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes: None
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
lpc32xx_abort_handler
    B    lpc32xx_abort_handler

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Function: lpc32xx_irq_handler
;
; Purpose:
;   Handle the IRQ interrupt
; 
; Processing:
;   Loop forever
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes: None
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
lpc32xx_irq_handler
    SUB lr, lr, #4                 ; Get return address 
    STMFD sp!, {lr}                ; Save registers 

        MRS     lr, SPSR
        STMFD   sp!, {lr}

        MSR     CPSR_c, #SYS_MODE | I_BIT
        STMFD   sp!, {r0-r12, lr}
        
//        VMRS    R0, FPSCR
//        STMFD   sp!,{R0}
//        BIC     R0,R0,#0x70000
//        VMSR    FPSCR,R0
//        VSTMDB  sp!,{D0-D7}

    LDR    r6, =0xFFFFFFFF

; Read the MIC interrupt status registers 
    LDR    r2, =MIC_BASE_ADDR
    LDR    r3, [r2, #IRQ_STATUS_OFF]
    AND    r3, r3, #0x3FFFFFFC ; Mask off subFIQ bits
    LDR    r5, [r2, #ITR_OFF]
    EOR    r5, r5, r6 ;інвертуємо біт, щоб 1 відповідав за IRQ а 0 - FIQ
    AND    r3, r3, r5 ; Визначаємо біти, які відповідають за IRQ
    MOV    r4, #0

    ; If there the MIC IRQ status is 0, then there are no MIC
    ; interrupts pending. That means, go service SIC1 interrupts
    ; instead. 
service_mic_irq
    CMP    r3, #0                  
    BNE    int_found_irq 
    ; The interrupt was not from MIC
service_sic1_irq
    ; Read the SIC1 interrupt status registers 
    LDR    r2, =SIC1_BASE_ADDR     
    LDR    r3, [r2, #IRQ_STATUS_OFF]
    LDR    r5, [r2, #ITR_OFF]
    EOR    r5, r5, r6 ;інвертуємо біт, щоб 1 відповідав за IRQ а 0 - FIQ
    AND    r3, r3, r5 ; Визначаємо біти, які відповідають за IRQ
    MOV    r4, #32

    ; If there the SIC1 IRQ status is 0, then there are no SIC1
    ; interrupts pending. That means, go service SIC2 interrupts
    ; instead. 
    CMP    r3, #0                  
    BNE    int_found_irq 
    ; The interrupt was not from SIC1

service_sic2_irq
    ; Read the SIC2 interrupt status registers 
    LDR    r2, =SIC2_BASE_ADDR     
    LDR    r3, [r2, #IRQ_STATUS_OFF]
    LDR    r5, [r2, #ITR_OFF]
    EOR    r5, r5, r6 ;інвертуємо біт, щоб 1 відповідав за IRQ а 0 - FIQ
    AND    r3, r3, r5 ; Визначаємо біти, які відповідають за IRQ
    MOV    r4, #64
    CMP    r3, #0                  
    BNE    int_found_irq 

    BEQ    int_exit_irq 
    ; The interrupt was not from SIC2

int_found_irq
    CLZ    r1, r3
    RSB    r1, r1, #31
    ADD    r1, r1, r4
    LDR    r0, =irq_func_ptrs    ; Get address of jump table 
    ADD    r0, r0, r1, LSL #2    ; Add by interrupt offset 
    LDR    r0, [r0]              ; Get handler address 
    CMP    r0, #0                ; Is handler address NULL? 
    BEQ    int_exit_irq          ; If null, the exit 
    MOV    lr, pc                ; Will return to int_exit 
    BX     r0                    ; Jump to handler 

int_exit_irq
        
//        VLDM   sp!, {D0-D7}
//        LDMIA   sp!, {R0}
//        VMSR     FPSCR,R0

        LDMIA   sp!, {r0-r12, lr}
        MSR     CPSR_c, #IRQ_MODE | I_BIT

        LDMIA   sp!, {lr}
        MSR     SPSR_cxsf, lr
        
    LDMFD  sp!, {pc}^    ; Restore registers and exit 

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
; Function: lpc32xx_fiq_handler
;
; Purpose:
;   Handle the FIQ interrupt
; 
; Processing:
;   Loop forever
;
; Parameters: None
;
; Outputs:  None
;
; Returns: Nothing
;
; Notes: None
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
lpc32xx_fiq_handler
    SUB lr, lr, #4                 ; Get return address 
    STMFD sp!, {lr}                ; Save registers 

        MRS     lr, SPSR
        STMFD   sp!, {lr}

        MSR     CPSR_c, #SYS_MODE | I_BIT | F_BIT
        STMFD   sp!, {r0-r12, lr}
        
//        VMRS    R0, FPSCR
//        STMFD   sp!,{R0}
//        BIC     R0,R0,#0x70000
//        VMSR    FPSCR,R0
//        VSTMDB  sp!,{D0-D7}

; Read the MIC interrupt status registers 
    LDR    r2, =MIC_BASE_ADDR
    LDR    r3, [r2, #IRQ_STATUS_OFF]
    AND    r3, r3, #0xFFFFFFFC ; Mask off subIRQ bits
    LDR    r5, [r2, #ITR_OFF]
    AND    r3, r3, r5 ; Визначаємо біти, які відповідають за FIQ
    MOV    r4, #0

    ; If there the MIC FIQ status is 0, then there are no MIC
    ; interrupts pending. That means, go service SIC1 interrupts
    ; instead. 
service_mic_fiq
    CMP    r3, #0                  
    BNE    int_found_fiq 
    ; The interrupt was not from MIC
service_sic1_fiq
    ; Read the SIC1 interrupt status registers 
    LDR    r2, =SIC1_BASE_ADDR     
    LDR    r3, [r2, #IRQ_STATUS_OFF]
    LDR    r5, [r2, #ITR_OFF]
    AND    r3, r3, r5 ; Визначаємо біти, які відповідають за FIQ
    MOV    r4, #32

    ; If there the SIC1 FIQ status is 0, then there are no SIC1
    ; interrupts pending. That means, go service SIC2 interrupts
    ; instead. 
    CMP    r3, #0                  
    BNE    int_found_fiq 
    ; The interrupt was not from SIC1

service_sic2_fiq
    ; Read the SIC2 interrupt status registers 
    LDR    r2, =SIC2_BASE_ADDR     
    LDR    r3, [r2, #IRQ_STATUS_OFF]
    LDR    r5, [r2, #ITR_OFF]
    AND    r3, r3, r5 ; Визначаємо біти, які відповідають за IRQ
    MOV    r4, #64
    CMP    r3, #0                  
    BNE    int_found_fiq 

    BEQ    int_exit_fiq 
    ; The interrupt was not from SIC2

int_found_fiq
    CLZ    r1, r3
    RSB    r1, r1, #31
    ADD    r1, r1, r4
    LDR    r0, =irq_func_ptrs    ; Get address of jump table 
    ADD    r0, r0, r1, LSL #2    ; Add by interrupt offset 
    LDR    r0, [r0]              ; Get handler address 
    CMP    r0, #0                ; Is handler address NULL? 
    BEQ    int_exit_fiq              ; If null, the exit 
    MOV    lr, pc                ; Will return to int_exit_fiq 
    BX     r0                    ; Jump to handler 

int_exit_fiq
        
//        VLDM   sp!, {D0-D7}
//        LDMIA   sp!, {R0}
//        VMSR     FPSCR,R0

        LDMIA   sp!, {r0-r12, lr}
        MSR     CPSR_c, #FIQ_MODE | I_BIT | F_BIT

        LDMIA   sp!, {lr}
        MSR     SPSR_cxsf, lr
        
    LDMFD  sp!, {pc}^    ; Restore registers and exit 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

MIC_BASE_ADDR  EQU 0x40008000 ; Base address of MIC
SIC1_BASE_ADDR EQU 0x4000C000 ; Base address of SIC1
SIC2_BASE_ADDR EQU 0x40010000 ; Base address of SIC2
IRQ_STATUS_OFF EQU 0x08       ; Offset to IRQ status 
ITR_OFF        EQU 0x14       ; Зміщення до регістру  ITR

    END
