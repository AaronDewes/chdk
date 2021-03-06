/*
 * filewrite.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_FWT 7   // filewritetask is prepared for this many chunks
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * pdc is required, everything after that is optional (DryOS < R50)
 * file_offset, full_size, seek_flag only needs to be defined for DryOS>=r50 generation cameras
 */
typedef struct
{
    int unkn1[5];
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_FWT];
    int unkn2;
    char name[32];
} fwt_data_struct;

#include "../../../generic/filewrite.c"

/*************************************************************/
//** filewritetask @ 0xFF2E50B0 - 0xFF2E5190, length=57
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R5,LR} \n"
"    LDR     R5, =0xD1BC \n"

"loc_FF2E50B8:\n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R5, #0x10] \n"
"    ADD     R1, SP, #8 \n"
"    BL      sub_FF02B184 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    MOVNE   R1, #0x348 \n"
"    LDRNE   R0, =0xFF2E51B0 /*'dwFWrite.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0xA \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF2E50B8 \n"
"    B       loc_FF2E5184 \n"
"    B       loc_FF2E5184 \n"
"    B       loc_FF2E5184 \n"
"    B       loc_FF2E5184 \n"
"    B       loc_FF2E5184 \n"
"    B       loc_FF2E5184 \n"
"    B       loc_FF2E5184 \n"
"    B       loc_FF2E518C \n"
"    B       loc_FF2E5114 \n"
"    B       loc_FF2E517C \n"

"loc_FF2E5114:\n"
"    MOV     R0, #0 \n"
"    MOV     R4, R5 \n"
"    STR     R0, [SP] \n"

"loc_FF2E5120:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R1, SP \n"
"    BL      sub_FF02B3C8 /*_GetNumberOfPostedMessages*/ \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF2E514C \n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF02B184 /*_ReceiveMessageQueue*/ \n"
"    B       loc_FF2E5120 \n"

"loc_FF2E514C:\n"
"    LDR     R0, [R4, #4] \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FF2E5170 \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    MVN     R0, #0 \n"
"    STR     R0, [R4, #4] \n"
"    LDR     R0, =0x118B70 \n"
"    BL      sub_FF06C558 \n"
"    BL      sub_FF06A6E8 \n"

"loc_FF2E5170:\n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FF2E50B8 \n"

"loc_FF2E517C:\n"
"    BL      sub_FF2E4DFC_my \n"  // --> Patched. Old value = 0xFF2E4DFC.
"    B       loc_FF2E50B8 \n"

"loc_FF2E5184:\n"
"    BL      sub_FF2E538C_my \n"  // --> Patched. Old value = 0xFF2E538C.
"    B       loc_FF2E50B8 \n"

"loc_FF2E518C:\n"
"    BL      sub_FF2E4F3C_my \n"  // --> Patched. Old value = 0xFF2E4F3C.
"    B       loc_FF2E50B8 \n"
);
}

/*************************************************************/
//** sub_FF2E4DFC_my @ 0xFF2E4DFC - 0xFF2E4E54, length=23
void __attribute__((naked,noinline)) sub_FF2E4DFC_my() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    MOV     R4, R0 \n"
"    SUB     SP, SP, #0x3C \n"
"    ADD     R0, R0, #0x50 \n"
"    BL      sub_FF06C558 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF06A680 \n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      sub_FF00033C \n"
"    LDR     R0, [R4, #0x4C] \n"
"    ADD     R7, R4, #0x50 \n"
"    CMP     R0, #1 \n"
"    LDREQ   R0, [R4, #8] \n"
"    ORREQ   R0, R0, #0x8000 \n"
"    STREQ   R0, [R4, #8] \n"
"    LDR     R5, [R4, #0xC] \n"
"    LDR     R8, [R4, #8] \n"
"    BL      sub_FF192764 \n"
//hook start
"    STMFD   SP!, {R2,R4-R12,LR} \n"
"    MOV     R0, R4 \n"
"    BL      filewrite_main_hook \n"
"    LDMFD   SP!, {R2,R4-R12,LR} \n"
//hook end
"    LDR     R9, =0x1B6 \n"
"    MOV     R1, R8 \n"
"    MOV     R2, R9 \n"
"    MOV     R0, R7 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    LDR     PC, =0xFF2E4E58 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF2E538C_my @ 0xFF2E538C - 0xFF2E540C, length=33
void __attribute__((naked,noinline)) sub_FF2E538C_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #6 \n"
"    BHI     loc_FF2E53B8 \n"
"    ADD     R0, R5, R0, LSL#3 \n"
"    LDR     R8, [R0, #0x14]! \n"
"    LDR     R7, [R0, #4] \n"
"    CMP     R7, #0 \n"
"    BNE     loc_FF2E53D0 \n"
"    B       loc_FF2E53C4 \n"

"loc_FF2E53B8:\n"
"    LDR     R1, =0x2A2 \n"
"    LDR     R0, =0xFF2E51B0 /*'dwFWrite.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF2E53C4:\n"
"    MOV     R1, R5 \n"
"    MOV     R0, #7 \n"
"    B       sub_FF2E5464 \n"

"loc_FF2E53D0:\n"
"    LDR     R9, =0xD1BC \n"
"    MOV     R4, R7 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R4, #0x1000000 \n"
"    MOVLS   R6, R4 \n"
"    MOVHI   R6, #0x1000000 \n"
"    BIC     R1, R0, #0xFF000000 \n"
"    CMP     R1, #0 \n"
"    BICNE   R0, R0, #0xFF000000 \n"
"    RSBNE   R0, R0, #0x1000000 \n"
"    CMPNE   R6, R0 \n"
"    MOVHI   R6, R0 \n"
"    LDR     R0, [R9, #4] \n"
"    MOV     R2, R6 \n"
"    MOV     R1, R8 \n"
"    BL      fwt_write \n"  // --> Patched. Old value = _Write.
"    LDR     PC, =0xFF2E5410 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF2E4F3C_my @ 0xFF2E4F3C - 0xFF2E4F70, length=14
void __attribute__((naked,noinline)) sub_FF2E4F3C_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0xD1BC \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    SUB     SP, SP, #0x38 \n"
"    CMN     R0, #1 \n"
"    BEQ     sub_FF2E4F84 \n"
"    LDR     R1, [R4, #8] \n"
"    LDR     R6, =0x9200003 \n"
"    TST     R1, #0x8000 \n"
"    BEQ     loc_FF2E4F70 \n"
"    BL      sub_FF027568 \n"
"    B       sub_FF2E4F74 \n"

"loc_FF2E4F70:\n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    LDR     PC, =0xFF2E4F74 \n"  // Continue in firmware
);
}
