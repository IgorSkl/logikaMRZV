
; Implementation of AEABI functions using a partial VFP state (using D0 and D1)

    PUBLIC save_partial_VFP_state
    PUBLIC restore_partial_VFP_state

    SECTION .text:CODE
    ARM
    ; Save D0, D1 and FPSCR in area pointed to by R0
save_partial_VFP_state:
    VMRS     R1,FPSCR
    VSTM     R0,{D0,D1}
    STR      R1,[R0,#16] ; after D0 and D1
    BX       LR

    SECTION .text:CODE
    ARM
    ; Restore D0, D1 and FPSCR from area pointed to by R0
restore_partial_VFP_state:
    LDR      R1,[R0,#16] ; after D0 and D1
    VLDM     R0,{D0,D1}
    VMSR     FPSCR,R1
    BX       LR

    ; AEABI routines using only D0 and D1.
    ;
    ; These are currently the same as those in standard libraries,
    ; but since we rely on only D0 and D1 being used we better
    ; override the standard library.
    ;
    ; You might want to extend this to include all floating point support routines:
    ; Casts:  __aeabi_d2f, __aeabi_d2iz, __aeabi_d2uiz, __aeabi_f2d, __aeabi_f2iz,
    ;         __aeabi_f2uiz, __aeabi_i2d, __aeabi_i2f, __aeabi_ui2d, __aeabi_ui2f
    ; Float:  __aeabi_fadd, __aeabi_cfrcmple, __aeabi_cfcmple, __aeabi_fdiv,
    ;         __aeabi_fmul, __aeabi_frsub, __aeabi_fsub
    ; Double: __aeabi_dadd, __aeabi_cdcmpeq, __aeabi_cdrcmple, __aeabi_cdcmple,
    ;         __aeabi_ddiv, __aeabi_dmul, __aeabi_drsub, __aeabi_dsub

    PUBLIC __aeabi_ui2d
    PUBLIC __aeabi_dmul
    PUBLIC __aeabi_ddiv
    PUBLIC __aeabi_d2f
    PUBLIC __aeabi_i2f
    PUBLIC __aeabi_fmul
    PUBLIC __aeabi_fsub
    PUBLIC __aeabi_fadd
    PUBLIC __aeabi_fdiv
    PUBLIC __aeabi_ui2f
    PUBLIC __aeabi_f2iz
    PUBLIC __aeabi_f2uiz

    SECTION .text:CODE
    ARM
__aeabi_ui2d:
    VMOV     S0, R0
    VCVT.F64.U32 D0, S0
    VMOV     R0, R1, D0
    BX       LR

    SECTION .text:CODE
    ARM
__aeabi_dmul:
    VMOV     D0, R0, R1
    VMOV     D1, R2, R3
    VMUL.F64 D0, D0, D1
    VMOV     R0, R1, D0
    BX       LR

    SECTION .text:CODE
    ARM
__aeabi_ddiv:
    VMOV     D0, R0, R1
    VMOV     D1, R2, R3
    VDIV.F64 D0, D0, D1
    VMOV     R0, R1, D0
    BX       LR

    SECTION .text:CODE
    ARM
__aeabi_d2f:
    VMOV     D0, R0, R1
    VCVT.F32.F64 S0, D0
    VMOV     R0, S0
    BX       LR

    SECTION .text:CODE
    ARM
__aeabi_i2f:
    VMOV     S0, R0
    VCVT.F32.S32 S0, S0
    VMOV     R0, S0
    BX       LR

    SECTION .text:CODE
    ARM
__aeabi_fmul:
    VMOV     S0, R0
    VMOV     S1, R1
    VMUL.F32 S0, S0, S1
    VMOV     R0, S0
    BX       LR

    SECTION .text:CODE
    ARM
__aeabi_fsub:
    VMOV     S0, R0
    VMOV     S1, R1
    VSUB.F32 S0, S0, S1
    VMOV     R0, S0
    BX       LR

    SECTION .text:CODE
    ARM
__aeabi_fadd:
    VMOV     S0, R0
    VMOV     S1, R1
    VADD.F32 S0, S0, S1
    VMOV     R0, S0
    BX       LR

    SECTION .text:CODE
    ARM
__aeabi_fdiv:
    VMOV     S0, R0
    VMOV     S1, R1
    VDIV.F32 S0, S0, S1
    VMOV     R0, S0
    BX       LR

    SECTION .text:CODE
    ARM
__aeabi_ui2f:
    VMOV         S0, R0
    VCVT.F32.U32 S0, S0
    VMOV         R0, S0
    BX           LR

    SECTION .text:CODE
    ARM
__aeabi_f2iz:
    VMOV         S0, R0
    VCVT.S32.F32 S0, S0
    VMOV         R0, S0
    BX           LR

    SECTION .text:CODE
    ARM
__aeabi_f2uiz:
    VMOV         S0, R0
    VCVT.U32.F32 S0, S0
    VMOV         R0, S0
    BX           LR

    END
