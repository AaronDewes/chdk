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
//** filewritetask @ 0xFF2E4F2C - 0xFF2E500C, length=57
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R5,LR} \n"
"    LDR     R5, =0xD1BC \n"

"loc_FF2E4F34:\n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R5, #0x10] \n"
"    ADD     R1, SP, #8 \n"
"    BL      sub_FF02B17C /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    MOVNE   R1, #0x348 \n"
"    LDRNE   R0, =0xFF2E502C /*'dwFWrite.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0xA \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF2E4F34 \n"
"    B       loc_FF2E5000 \n"
"    B       loc_FF2E5000 \n"
"    B       loc_FF2E5000 \n"
"    B       loc_FF2E5000 \n"
"    B       loc_FF2E5000 \n"
"    B       loc_FF2E5000 \n"
"    B       loc_FF2E5000 \n"
"    B       loc_FF2E5008 \n"
"    B       loc_FF2E4F90 \n"
"    B       loc_FF2E4FF8 \n"

"loc_FF2E4F90:\n"
"    MOV     R0, #0 \n"
"    MOV     R4, R5 \n"
"    STR     R0, [SP] \n"

"loc_FF2E4F9C:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R1, SP \n"
"    BL      sub_FF02B3C0 /*_GetNumberOfPostedMessages*/ \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF2E4FC8 \n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF02B17C /*_ReceiveMessageQueue*/ \n"
"    B       loc_FF2E4F9C \n"

"loc_FF2E4FC8:\n"
"    LDR     R0, [R4, #4] \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FF2E4FEC \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    MVN     R0, #0 \n"
"    STR     R0, [R4, #4] \n"
"    LDR     R0, =0x118B70 \n"
"    BL      sub_FF06C4A8 \n"
"    BL      sub_FF06A6CC \n"

"loc_FF2E4FEC:\n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FF2E4F34 \n"

"loc_FF2E4FF8:\n"
"    BL      sub_FF2E4C78_my \n"  // --> Patched. Old value = 0xFF2E4C78.
"    B       loc_FF2E4F34 \n"

"loc_FF2E5000:\n"
"    BL      sub_FF2E520C_my \n"  // --> Patched. Old value = 0xFF2E520C.
"    B       loc_FF2E4F34 \n"

"loc_FF2E5008:\n"
"    BL      sub_FF2E4DB8_my \n"  // --> Patched. Old value = 0xFF2E4DB8.
"    B       loc_FF2E4F34 \n"
);
}

/*************************************************************/
//** sub_FF2E4C78_my @ 0xFF2E4C78 - 0xFF2E4CD0, length=23
void __attribute__((naked,noinline)) sub_FF2E4C78_my() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    MOV     R4, R0 \n"
"    SUB     SP, SP, #0x3C \n"
"    ADD     R0, R0, #0x50 \n"
"    BL      sub_FF06C4A8 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF06A664 \n"
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
"    BL      sub_FF1925A8 \n"
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
"    LDR     PC, =0xFF2E4CD4 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF2E520C_my @ 0xFF2E520C - 0xFF2E528C, length=33
void __attribute__((naked,noinline)) sub_FF2E520C_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #6 \n"
"    BHI     loc_FF2E5238 \n"
"    ADD     R0, R5, R0, LSL#3 \n"
"    LDR     R8, [R0, #0x14]! \n"
"    LDR     R7, [R0, #4] \n"
"    CMP     R7, #0 \n"
"    BNE     loc_FF2E5250 \n"
"    B       loc_FF2E5244 \n"

"loc_FF2E5238:\n"
"    LDR     R1, =0x2A2 \n"
"    LDR     R0, =0xFF2E502C /*'dwFWrite.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF2E5244:\n"
"    MOV     R1, R5 \n"
"    MOV     R0, #7 \n"
"    B       sub_FF2E52E4 \n"

"loc_FF2E5250:\n"
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
"    LDR     PC, =0xFF2E5290 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF2E4DB8_my @ 0xFF2E4DB8 - 0xFF2E4DEC, length=14
void __attribute__((naked,noinline)) sub_FF2E4DB8_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0xD1BC \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    SUB     SP, SP, #0x38 \n"
"    CMN     R0, #1 \n"
"    BEQ     sub_FF2E4E00 \n"
"    LDR     R1, [R4, #8] \n"
"    LDR     R6, =0x9200003 \n"
"    TST     R1, #0x8000 \n"
"    BEQ     loc_FF2E4DEC \n"
"    BL      sub_FF02750C \n"
"    B       sub_FF2E4DF0 \n"

"loc_FF2E4DEC:\n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    LDR     PC, =0xFF2E4DF0 \n"  // Continue in firmware
);
}
