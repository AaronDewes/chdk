/*
 * filewrite.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_FWT 7 // filewritetask is prepared for this many chunks
                              // Found in sub_FF339D5C (1.00a) --> "CMP     R0, #6" and
                              // corresponds to filewritetask() jump table entries 0-6
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for DryOS>=r50 generation cameras
 * pdc is always required
 * name is not currently used
 */
typedef struct
{
    int unkn1;
    int file_offset;
    int full_size;
    int unkn2, unkn3;
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_FWT];
    int seek_flag;      // offset from start 0x4c = 76 bytes = 19 words
    int unkn4, unkn5;
    char name[32];      // offset from start 0x58 = 88 bytes = 22 words
} fwt_data_struct;
// seek_flag is different:
// seek state is activated (from state 0xc, open) when
// (word at 0x4c) AND 0x40
// OR
// write offset is not 0
#define FWT_MUSTSEEK    0x40   // value of the masked seek_flag indicating seek is required
#define FWT_SEEKMASK    0x40   // masks out unneeded bits of seek_flag

#include "../../../generic/filewrite.c"

/*************************************************************/
//** filewritetask @ 0xFF3B6654 - 0xFF3B67F4, length=105
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R7,LR} \n"
"    LDR     R5, =0x106E0 \n"
"    MOV     R6, #0 \n"

"loc_FF3B6660:\n"
"    LDR     R0, [R5, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #8 \n"
"    BL      sub_0068BDE4 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    LDRNE   R1, =0x3EF \n"
"    LDRNE   R0, =0xFF3B6820 /*'dwFWrite.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0xD \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF3B6660 \n"
"    B       loc_FF3B67E8 \n"
"    B       loc_FF3B67E8 \n"
"    B       loc_FF3B67E8 \n"
"    B       loc_FF3B67E8 \n"
"    B       loc_FF3B67E8 \n"
"    B       loc_FF3B67E8 \n"
"    B       loc_FF3B67E8 \n"
"    B       loc_FF3B67F0 \n"
"    B       loc_FF3B66C8 \n"
"    B       loc_FF3B6764 \n"
"    B       loc_FF3B6794 \n"
"    B       loc_FF3B6730 \n"
"    B       loc_FF3B675C \n"

"loc_FF3B66C8:\n"
"    MOV     R4, R5 \n"
"    STR     R6, [SP] \n"

"loc_FF3B66D0:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R1, SP \n"
"    BL      sub_0068C028 /*_GetNumberOfPostedMessages*/ \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF3B66FC \n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_0068BDE4 /*_ReceiveMessageQueue*/ \n"
"    B       loc_FF3B66D0 \n"

"loc_FF3B66FC:\n"
"    LDR     R0, [R4, #4] \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FF3B6724 \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    MVN     R0, #0 \n"
"    STR     R0, [R4, #4] \n"
"    LDR     R0, =0x1C32B8 \n"
"    BL      sub_FF0AB4F8 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF0A941C \n"

"loc_FF3B6724:\n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FF3B6660 \n"

"loc_FF3B6730:\n"
"    MOV     R4, R0 \n"
"    ADD     R0, R0, #0x58 \n"
"    BL      sub_FF0AB4F8 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF0A92E0 \n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      sub_FF0A81BC \n"
"    ADD     R0, R4, #0x58 \n"

//mod start
"    LDR R3, =ignore_current_write\n" // !!
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_A\n" // skip creating directory
//mod end
"    BL      sub_FF0357D0 \n"
"    ADD     R0, R4, #0x58 \n"
"    B       loc_FF3B67C8 \n"

"loc_FF3B675C:\n"
"    BL      sub_FF3B6340_my \n"  // --> Patched. Old value = 0xFF3B6340. Open stage
"    B       loc_FF3B6660 \n"

"loc_FF3B6764:\n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    MOV     R2, #0 \n"
"    BL      fwt_lseek \n"  // --> Patched. Old value = _lseek.
"    CMN     R0, #1 \n"
"    LDREQ   R0, =0x9200013 \n"
"    MOVEQ   R1, R4 \n"
"    STREQ   R0, [R4, #0x10] \n"
"    MOVEQ   R0, #7 \n"
"    BLEQ    sub_FF3B6280 \n"
"    B       loc_FF3B6660 \n"

"loc_FF3B6794:\n"
"    MOV     R4, R0 \n"
"    LDRSB   R0, [R0, #0x58] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF3B6660 \n"
"    STRB    R0, [SP, #4] \n"
"    ADD     R0, R4, #0x58 \n"
"    STRB    R6, [SP, #5] \n"
"    BL      sub_FF0AB4F8 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF0A92E0 \n"

//mod start
"    LDR R3, =ignore_current_write\n" // !!
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_B\n" // skip flushing the cache
//mod end

"    ADD     R0, SP, #4 \n"
"    BL      sub_FF0A81D4 \n"
"loc_B:\n"
"    ADD     R0, R4, #0x58 \n"

"loc_FF3B67C8:\n"
"loc_A:\n"
"    BL      sub_FF0AB4F8 \n"
"    LDR     R1, [R5, #0x18] \n"
"    BL      sub_FF0A941C \n"
"    LDR     R1, [R5, #0x14] \n"
"    CMP     R1, #0 \n"
"    LDRNE   R0, [R4, #0x10] \n"
"    BLXNE   R1 \n"
"    B       loc_FF3B6660 \n"

"loc_FF3B67E8:\n"
"    BL      sub_FF3B6A00_my \n"  // --> Patched. Old value = 0xFF3B6A00. Write stage
"    B       loc_FF3B6660 \n"

"loc_FF3B67F0:\n"
"    BL      sub_FF3B64CC_my \n"  // --> Patched. Old value = 0xFF3B64CC. Close stage
"    B       loc_FF3B6660 \n"
);
}

/*************************************************************/
//** sub_FF3B6340_my @ 0xFF3B6340 - 0xFF3B64C8, length=99
void __attribute__((naked,noinline)) sub_FF3B6340_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    MOV     R4, R0 \n"
//hook placed here to avoid conditional branch a few instructions below (watch out for registers!)
//"  MOV   R0, R4\n"      //data block start, commented out as R0 is already holding what we need
"    BL filewrite_main_hook\n"
"    MOV     R0, R4\n"      //restore register(s)
//hook end
"    LDR     R0, [R0, #0x4C] \n"
"    SUB     SP, SP, #0x38 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF3B649C \n"
"    ADD     R0, R4, #0x58 \n"
"    BL      sub_FF0AB4F8 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF0A92E0 \n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      sub_FF0A81BC \n"
"    LDR     R0, [R4, #0x4C] \n"
"    LDR     R5, =0x301 \n"
"    TST     R0, #0x10 \n"
"    MOVNE   R5, #9 \n"
"    BNE     loc_FF3B638C \n"
"    TST     R0, #0x40 \n"
"    MOVNE   R5, #1 \n"

"loc_FF3B638C:\n"
"    TST     R0, #0x20 \n"
"    BNE     loc_FF3B63A0 \n"
"    LDR     R0, [R4, #0x54] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF3B63A4 \n"

"loc_FF3B63A0:\n"
"    ORR     R5, R5, #0x8000 \n"

"loc_FF3B63A4:\n"
"    LDR     R8, =0x1B6 \n"
"    ADD     R7, R4, #0x58 \n"
"    LDR     R6, [R4, #0xC] \n"
"    MOV     R2, R8 \n"
"    MOV     R1, R5 \n"
"    MOV     R0, R7 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    CMN     R0, #1 \n"
"    BNE     loc_FF3B6424 \n"
"    MOV     R0, R7 \n"
"    BL      sub_FF0357D0 \n"
"    MOV     R2, #0xF \n"
"    MOV     R1, R7 \n"
"    MOV     R0, SP \n"
"    BL      sub_006A90D8 \n"
"    MOV     R0, #0 \n"
"    LDR     R1, =0x41FF \n"
"    STRB    R0, [SP, #0xF] \n"
"    STR     R1, [SP, #0x20] \n"
"    MOV     R1, #0x10 \n"
"    STR     R0, [SP, #0x28] \n"
"    STR     R1, [SP, #0x24] \n"
"    ADD     R1, SP, #0x20 \n"
"    MOV     R0, SP \n"
"    STR     R6, [SP, #0x2C] \n"
"    STR     R6, [SP, #0x30] \n"
"    STR     R6, [SP, #0x34] \n"
"    BL      sub_FF0A8C5C \n"
"    MOV     R2, R8 \n"
"    MOV     R1, R5 \n"
"    MOV     R0, R7 \n"
"    BL      _Open \n"

"loc_FF3B6424:\n"
"    LDR     R6, =0x106E0 \n"
"    CMN     R0, #1 \n"
"    MOV     R5, R0 \n"
"    STR     R0, [R6, #4] \n"
"    BNE     loc_FF3B6464 \n"
"    ADD     R0, R4, #0x58 \n"
"    BL      sub_FF0AB4F8 \n"
"    LDR     R1, [R6, #0x18] \n"
"    BL      sub_FF0A941C \n"
"    LDR     R1, [R6, #0x14] \n"
"    CMP     R1, #0 \n"
"    BEQ     loc_FF3B64C4 \n"
"    ADD     SP, SP, #0x38 \n"
"    LDMFD   SP!, {R4-R8,LR} \n"
"    LDR     R0, =0x9200001 \n"
"    BX      R1 \n"

"loc_FF3B6464:\n"
"    LDR     R0, =0x1C32B8 \n"
"    MOV     R2, #0x20 \n"
"    ADD     R1, R4, #0x58 \n"
"    BL      sub_006A92C0 \n"

//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_C\n" // jump over the next block
//mod end

"    LDR     R0, [R4, #0x4C] \n"
"    TST     R0, #0x80 \n"
"    BEQ     loc_FF3B649C \n"
"    LDR     R1, [R4, #8] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF0354A0 \n"
"    CMP     R0, #0 \n"
"    MOVEQ   R1, R4 \n"
"    MOVEQ   R0, #7 \n"
"    BEQ     loc_FF3B64C0 \n"

"loc_FF3B649C:\n"
"loc_C:\n"
"    LDR     R0, [R4, #0x4C] \n"
"    TST     R0, #0x40 \n"
"    LDREQ   R0, [R4, #4] \n"
"    CMPEQ   R0, #0 \n"
"    MOVNE   R1, R4 \n"
"    MOVNE   R0, #9 \n"
"    BLNE    sub_FF3B6280 \n"
"    MOV     R1, R4 \n"
"    MOV     R0, #0 \n"

"loc_FF3B64C0:\n"
"    BL      sub_FF3B6280 \n"

"loc_FF3B64C4:\n"
"    ADD     SP, SP, #0x38 \n"
"    LDMFD   SP!, {R4-R8,PC} \n"
);
}

/*************************************************************/
//** sub_FF3B6A00_my @ 0xFF3B6A00 - 0xFF3B6ADC, length=56
void __attribute__((naked,noinline)) sub_FF3B6A00_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #6 \n"
"    BHI     loc_FF3B6A2C \n"
"    ADD     R0, R5, R0, LSL#3 \n"
"    LDR     R8, [R0, #0x14]! \n"
"    LDR     R7, [R0, #4] \n"
"    CMP     R7, #0 \n"
"    BNE     loc_FF3B6A44 \n"
"    B       loc_FF3B6A38 \n"

"loc_FF3B6A2C:\n"
"    MOV     R1, #0x344 \n"
"    LDR     R0, =0xFF3B6820 /*'dwFWrite.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF3B6A38:\n"
"    MOV     R1, R5 \n"
"    MOV     R0, #7 \n"
"    B       loc_FF3B6AD8 \n"

"loc_FF3B6A44:\n"
"    LDR     R9, =0x106E0 \n"
"    MOV     R4, R7 \n"

"loc_FF3B6A4C:\n"
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
"    BEQ     loc_FF3B6AAC \n"
"    CMN     R0, #1 \n"
"    LDRNE   R0, =0x9200015 \n"
"    LDREQ   R0, =0x9200005 \n"
"    STR     R0, [R5, #0x10] \n"
"    B       loc_FF3B6A38 \n"

"loc_FF3B6AAC:\n"
"    SUB     R4, R4, R0 \n"
"    CMP     R4, R7 \n"
"    LDRCS   R1, =0x36F \n"
"    ADD     R8, R8, R0 \n"
"    LDRCS   R0, =0xFF3B6820 /*'dwFWrite.c'*/ \n"
"    BLCS    _DebugAssert \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FF3B6A4C \n"
"    LDR     R0, [R5] \n"
"    MOV     R1, R5 \n"
"    ADD     R0, R0, #1 \n"

"loc_FF3B6AD8:\n"
"    LDMFD   SP!, {R4-R10,LR} \n"
"    B       sub_FF3B6280 \n"
"    .ltorg\n" //+
);
}

/*************************************************************/
//** sub_FF3B64CC_my @ 0xFF3B64CC - 0xFF3B650C, length=17
void __attribute__((naked,noinline)) sub_FF3B64CC_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R0, #0x4C] \n"
"    LDR     R5, =0x106E0 \n"
"    TST     R0, #2 \n"
"    SUB     SP, SP, #0x38 \n"
"    BEQ     sub_FF3B6634 \n"
"    LDR     R0, [R5, #4] \n"
"    CMN     R0, #1 \n"
"    BEQ     sub_FF3B6520 \n"
"    LDR     R1, [R4, #0x54] \n"
"    LDR     R6, =0x9200003 \n"
"    CMP     R1, #1 \n"
"    BNE     loc_FF3B650C \n"
//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_D\n" // jump over the next block
//mod end

"    BL      sub_FF0351F4 \n"
"    B       sub_FF3B6510 \n"

"loc_FF3B650C:\n"
"loc_D:\n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    LDR     PC, =0xFF3B6510 \n"  // Continue in firmware
);
}
