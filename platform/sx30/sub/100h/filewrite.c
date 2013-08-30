/*
 * filewrite.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_JPEG 7   // filewritetask is prepared for this many chunks
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * pdc is required, everything after that is optional (DryOS < R50)
 * file_offset, full_size, seek_flag only needs to be defined for DryOS>=r50 generation cameras
 */
typedef struct
{
    int unkn1[5];
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_JPEG];
    int unkn2;
    char name[32];
} fwt_data_struct;

#include "../../../generic/filewrite.c"

/*************************************************************/
//** filewritetask @ 0xFFACBD58 - 0xFFACBE34, length=56
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R5,LR} \n"
"    LDR     R4, =0xC950 \n"

"loc_FFACBD60:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #8 \n"
"    BL      sub_FF83A4C8 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    LDRNE   R1, =0x33F \n"
"    LDRNE   R0, =0xFFACBE48 \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #9 \n"
"    ADDLS   PC, PC, R1, LSL#2 \n"
"    B       loc_FFACBD60 \n"
"    B       loc_FFACBE28 \n"
"    B       loc_FFACBE28 \n"
"    B       loc_FFACBE28 \n"
"    B       loc_FFACBE28 \n"
"    B       loc_FFACBE28 \n"
"    B       loc_FFACBE28 \n"
"    B       loc_FFACBE28 \n"
"    B       loc_FFACBE30 \n"
"    B       loc_FFACBDBC \n"
"    B       loc_FFACBE20 \n"

"loc_FFACBDBC:\n"
"    MOV     R0, #0 \n"
"    STR     R0, [SP] \n"

"loc_FFACBDC4:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R1, SP \n"
"    BL      sub_FF83A70C /*_GetNumberOfPostedMessages*/ \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFACBDF0 \n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF83A4C8 /*_ReceiveMessageQueue*/ \n"
"    B       loc_FFACBDC4 \n"

"loc_FFACBDF0:\n"
"    LDR     R0, [R4, #4] \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FFACBE14 \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    MVN     R0, #0 \n"
"    STR     R0, [R4, #4] \n"
"    LDR     R0, =0x110BB0 \n"
"    BL      sub_FF877438 \n"
"    BL      sub_FF875694 \n"

"loc_FFACBE14:\n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FFACBD60 \n"

"loc_FFACBE20:\n"
"    BL      sub_FFACC030_my \n"  // --> Patched. Old value = 0xFFACC030.
"    B       loc_FFACBD60 \n"

"loc_FFACBE28:\n"
"    BL      sub_FFACC170_my \n"  // --> Patched. Old value = 0xFFACC170.
"    B       loc_FFACBD60 \n"

"loc_FFACBE30:\n"
"    BL      sub_FFACBBE4_my \n"  // --> Patched. Old value = 0xFFACBBE4.
"    B       loc_FFACBD60 \n"
);
}

/*************************************************************/
//** sub_FFACC030_my @ 0xFFACC030 - 0xFFACC084, length=22
void __attribute__((naked,noinline)) sub_FFACC030_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    MOV     R4, R0 \n"
"    ADD     R0, R0, #0x50 \n"
"    SUB     SP, SP, #0x38 \n"
"    BL      sub_FF877438 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF87562C \n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      sub_FF810338 \n"
"    LDR     R0, [R4, #0x4C] \n"
"    LDR     R8, =0x1B6 \n"
"    CMP     R0, #1 \n"
"    LDREQ   R0, [R4, #8] \n"
"    ADD     R6, R4, #0x50 \n"
"    ORREQ   R0, R0, #0x8000 \n"
"    STREQ   R0, [R4, #8] \n"
"    LDR     R7, [R4, #8] \n"
"    LDR     R5, [R4, #0xC] \n"
//hook start
"    STMFD   SP!, {R4-R12,LR} \n"
"    MOV     R0, R4 \n"
"    BL      filewrite_main_hook \n"
"    LDMFD   SP!, {R4-R12,LR} \n"
//hook end
"    MOV     R0, R6 \n"
"    MOV     R2, R8 \n"
"    MOV     R1, R7 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    LDR     PC, =0xFFACC088 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FFACC170_my @ 0xFFACC170 - 0xFFACC1F0, length=33
void __attribute__((naked,noinline)) sub_FFACC170_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #6 \n"
"    BHI     loc_FFACC1A4 \n"
"    ADD     R0, R5, R0, LSL#3 \n"
"    LDR     R7, [R0, #0x14]! \n"
"    LDR     R6, [R0, #4] \n"
"    CMP     R6, #0 \n"
"    BNE     loc_FFACC1B4 \n"

"loc_FFACC198:\n"
"    MOV     R1, R5 \n"
"    MOV     R0, #7 \n"
"    B       sub_FFACC248 \n"

"loc_FFACC1A4:\n"
"    LDR     R1, =0x299 \n"
"    LDR     R0, =0xFFACBE48 \n"
"    BL      _DebugAssert \n"
"    B       loc_FFACC198 \n"

"loc_FFACC1B4:\n"
"    LDR     R9, =0xC950 \n"
"    MOV     R4, R6 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R4, #0x1000000 \n"
"    MOVLS   R8, R4 \n"
"    MOVHI   R8, #0x1000000 \n"
"    BIC     R1, R0, #0xFF000000 \n"
"    CMP     R1, #0 \n"
"    BICNE   R0, R0, #0xFF000000 \n"
"    RSBNE   R0, R0, #0x1000000 \n"
"    CMPNE   R8, R0 \n"
"    MOVHI   R8, R0 \n"
"    LDR     R0, [R9, #4] \n"
"    MOV     R2, R8 \n"
"    MOV     R1, R7 \n"
"    BL      fwt_write \n"  // --> Patched. Old value = _Write.
"    LDR     PC, =0xFFACC1F4 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FFACBBE4_my @ 0xFFACBBE4 - 0xFFACBC18, length=14
void __attribute__((naked,noinline)) sub_FFACBBE4_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0xC950 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    SUB     SP, SP, #0x38 \n"
"    CMN     R0, #1 \n"
"    BEQ     sub_FFACBC2C \n"
"    LDR     R1, [R4, #8] \n"
"    LDR     R6, =0x9200003 \n"
"    TST     R1, #0x8000 \n"
"    BEQ     loc_FFACBC18 \n"
"    BL      sub_FF8746D8 \n"
"    B       sub_FFACBC1C \n"

"loc_FFACBC18:\n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    LDR     PC, =0xFFACBC1C \n"  // Continue in firmware
);
}
