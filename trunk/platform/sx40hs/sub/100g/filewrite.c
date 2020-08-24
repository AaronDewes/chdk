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
//** filewritetask @ 0xFF337504 - 0xFF3375E8, length=58
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R5,LR} \n"
"    LDR     R5, =0xF12C \n"

"loc_FF33750C:\n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R5, #0x10] \n"
"    ADD     R1, SP, #8 \n"
"    BL      sub_FF02B0F4 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    LDRNE   R1, =0x33E \n"
"    LDRNE   R0, =0xFF3375F8 /*'dwFWrite.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0xA \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF33750C \n"
"    B       loc_FF3375DC \n"
"    B       loc_FF3375DC \n"
"    B       loc_FF3375DC \n"
"    B       loc_FF3375DC \n"
"    B       loc_FF3375DC \n"
"    B       loc_FF3375DC \n"
"    B       loc_FF3375DC \n"
"    B       loc_FF3375E4 \n"
"    B       loc_FF337568 \n"
"    B       loc_FF3375D4 \n"

"loc_FF337568:\n"
"    MOV     R0, #0 \n"
"    MOV     R4, R5 \n"
"    STR     R0, [SP] \n"

"loc_FF337574:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R1, SP \n"
"    BL      sub_FF02B338 /*_GetNumberOfPostedMessages*/ \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF3375A0 \n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF02B0F4 /*_ReceiveMessageQueue*/ \n"
"    B       loc_FF337574 \n"

"loc_FF3375A0:\n"
"    LDR     R0, [R4, #4] \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FF3375C8 \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    MVN     R0, #0 \n"
"    STR     R0, [R4, #4] \n"
"    LDR     R0, =0x173944 \n"
"    BL      sub_FF06A7D8 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF068A54 \n"

"loc_FF3375C8:\n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FF33750C \n"

"loc_FF3375D4:\n"
"    BL      sub_FF3377E8_my \n"  // --> Patched. Old value = 0xFF3377E8.
"    B       loc_FF33750C \n"

"loc_FF3375DC:\n"
"    BL      sub_FF337944_my \n"  // --> Patched. Old value = 0xFF337944.
"    B       loc_FF33750C \n"

"loc_FF3375E4:\n"
"    BL      sub_FF337398_my \n"  // --> Patched. Old value = 0xFF337398.
"    B       loc_FF33750C \n"
);
}

/*************************************************************/
//** sub_FF3377E8_my @ 0xFF3377E8 - 0xFF3378B4, length=52
void __attribute__((naked,noinline)) sub_FF3377E8_my() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    MOV     R4, R0 \n"
"    SUB     SP, SP, #0x3C \n"
"    ADD     R0, R0, #0x50 \n"
"    BL      sub_FF06A7D8 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF068918 \n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      sub_FF000348 \n"
"    LDR     R0, [R4, #0x4C] \n"
"    ADD     R7, R4, #0x50 \n"
"    CMP     R0, #1 \n"
"    LDREQ   R0, [R4, #8] \n"
"    ORREQ   R0, R0, #0x8000 \n"
"    STREQ   R0, [R4, #8] \n"
"    LDR     R5, [R4, #0xC] \n"
"    LDR     R8, [R4, #8] \n"
"    BL      sub_FF1D4D6C \n"
//hook start
"    STMFD   SP!, {R4-R12,LR} \n"
"    MOV     R0, R4 \n"
"    BL      filewrite_main_hook \n"
"    LDMFD   SP!, {R4-R12,LR} \n"
//hook end
"    LDR     R9, =0x1B6 \n"
"    MOV     R1, R8 \n"
"    MOV     R2, R9 \n"
"    MOV     R0, R7 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    MOV     R6, R0 \n"
"    BL      sub_FF1D4DBC \n"
"    CMN     R6, #1 \n"
"    MOVNE   R5, R6 \n"
"    BNE     sub_FF3378C0 \n"
"    BL      sub_FF1D4D6C \n"
"    MOV     R0, R7 \n"
"    BL      sub_FF027C70 \n"
"    MOV     R2, #0xF \n"
"    MOV     R1, R7 \n"
"    ADD     R0, SP, #4 \n"
"    BL      sub_FF42FA90 \n"
"    MOV     R0, #0 \n"
"    LDR     R1, =0x41FF \n"
"    STRB    R0, [SP, #0x13] \n"
"    STR     R1, [SP, #0x24] \n"
"    MOV     R1, #0x10 \n"
"    STR     R0, [SP, #0x2C] \n"
"    STR     R1, [SP, #0x28] \n"
"    ADD     R1, SP, #0x24 \n"
"    ADD     R0, SP, #4 \n"
"    STR     R5, [SP, #0x30] \n"
"    STR     R5, [SP, #0x34] \n"
"    STR     R5, [SP, #0x38] \n"
"    BL      sub_FF06828C \n"
"    MOV     R2, R9 \n"
"    MOV     R1, R8 \n"
"    MOV     R0, R7 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    LDR     PC, =0xFF3378B8 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF337944_my @ 0xFF337944 - 0xFF337A0C, length=51
void __attribute__((naked,noinline)) sub_FF337944_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #6 \n"
"    BHI     loc_FF337970 \n"
"    ADD     R0, R5, R0, LSL#3 \n"
"    LDR     R8, [R0, #0x14]! \n"
"    LDR     R7, [R0, #4] \n"
"    CMP     R7, #0 \n"
"    BNE     loc_FF337988 \n"
"    B       loc_FF33797C \n"

"loc_FF337970:\n"
"    LDR     R1, =0x29E \n"
"    LDR     R0, =0xFF3375F8 /*'dwFWrite.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF33797C:\n"
"    MOV     R1, R5 \n"
"    MOV     R0, #7 \n"
"    B       sub_FF337A1C \n"

"loc_FF337988:\n"
"    LDR     R9, =0xF12C \n"
"    MOV     R4, R7 \n"

"loc_FF337990:\n"
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
"    LDR     R1, [R5, #4] \n"
"    CMP     R6, R0 \n"
"    ADD     R1, R1, R0 \n"
"    STR     R1, [R5, #4] \n"
"    BEQ     loc_FF3379F0 \n"
"    CMN     R0, #1 \n"
"    LDRNE   R0, =0x9200015 \n"
"    LDREQ   R0, =0x9200005 \n"
"    STR     R0, [R5, #0x10] \n"
"    B       loc_FF33797C \n"

"loc_FF3379F0:\n"
"    SUB     R4, R4, R0 \n"
"    CMP     R4, R7 \n"
"    ADD     R8, R8, R0 \n"
"    LDRCS   R1, =0x2C9 \n"
"    LDRCS   R0, =0xFF3375F8 /*'dwFWrite.c'*/ \n"
"    BLCS    _DebugAssert \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FF337990 \n"
"    LDR     PC, =0xFF337A10 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF337398_my @ 0xFF337398 - 0xFF3373CC, length=14
void __attribute__((naked,noinline)) sub_FF337398_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0xF12C \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    SUB     SP, SP, #0x38 \n"
"    CMN     R0, #1 \n"
"    BEQ     sub_FF3373E0 \n"
"    LDR     R1, [R4, #8] \n"
"    LDR     R6, =0x9200003 \n"
"    TST     R1, #0x8000 \n"
"    BEQ     loc_FF3373CC \n"
//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_D\n" // jump over the next block
//mod end
"    BL      sub_FF027694 \n"
"    B       sub_FF3373D0 \n"

"loc_FF3373CC:\n"
"loc_D:\n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    LDR     PC, =0xFF3373D0 \n"  // Continue in firmware
);
}
