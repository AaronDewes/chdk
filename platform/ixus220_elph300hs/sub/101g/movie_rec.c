/*
 * movie_rec.c - auto-generated by CHDK code_gen.
 */
#include "conf.h"

void change_video_tables(int a, int b){
}

void  set_quality(int *x){ // -17 highest; +12 lowest
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

/*************************************************************/
//** movie_record_task @ 0xFF985E5C - 0xFF985FD4, length=95
void __attribute__((naked,noinline)) movie_record_task() {
asm volatile (
"    STMFD   SP!, {R2-R10,LR} \n"
"    LDR     R6, =0xFF984BCC \n"
"    LDR     R7, =0xFF9858B4 \n"
"    LDR     R4, =0x6D88 \n"
"    LDR     R9, =0x67F \n"
"    LDR     R10, =0x2710 \n"
"    MOV     R8, #1 \n"
"    MOV     R5, #0 \n"

"loc_FF985E7C:\n"
"    LDR     R0, [R4, #0x24] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF83B5B4 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [R4, #0x2C] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, [R4, #0xC] \n"
"    CMPNE   R0, #2 \n"
"    LDRNE   R0, [R4, #0x44] \n"
"    CMPNE   R0, #6 \n"
"    BNE     loc_FF985FB8 \n"
"    LDR     R0, [SP, #4] \n"
"    LDR     R1, [R0] \n"
"    SUB     R1, R1, #2 \n"
"    CMP     R1, #0xD \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF985FB8 \n"
"    B       loc_FF985F58 \n"
"    B       loc_FF985F7C \n"
"    B       loc_FF985F8C \n"
"    B       loc_FF985F94 \n"
"    B       loc_FF985F9C \n"
"    B       loc_FF985FA4 \n"
"    B       loc_FF985F60 \n"
"    B       loc_FF985FAC \n"
"    B       loc_FF985F6C \n"
"    B       loc_FF985FB8 \n"
"    B       loc_FF985FB4 \n"
"    B       loc_FF985F24 \n"
"    B       loc_FF985EF4 \n"

"loc_FF985EF4:\n"
"    STR     R5, [R4, #0x40] \n"
"    STR     R5, [R4, #0x30] \n"
"    STR     R5, [R4, #0x34] \n"
"    STRH    R5, [R4, #6] \n"
"    STR     R6, [R4, #0xD8] \n"
"    STR     R7, [R4, #0xF0] \n"
"    LDR     R0, [R4, #0xC] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0xC] \n"
"    MOV     R0, #6 \n"
"    STR     R0, [R4, #0x44] \n"
"    B       loc_FF985F44 \n"

"loc_FF985F24:\n"
"    STR     R5, [R4, #0x40] \n"
"    STR     R5, [R4, #0x30] \n"
"    STR     R6, [R4, #0xD8] \n"
"    STR     R7, [R4, #0xF0] \n"
"    LDR     R0, [R4, #0xC] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0xC] \n"
"    STR     R8, [R4, #0x44] \n"

"loc_FF985F44:\n"
"    LDR     R2, =0xFF984214 \n"
"    LDR     R1, =0xB2228 \n"
"    LDR     R0, =0xFF984328 \n"
"    BL      sub_FF855290 \n"
"    B       loc_FF985FB8 \n"

"loc_FF985F58:\n"
);
if (conf.ext_video_time == 1)
{
asm volatile (
"    BL      sub_FF985498_my \n"  // --> Patched. Old value = 0xFF985498.
);
}
else
{
asm volatile (
"    BL      sub_FF985498 \n"
);
}
asm volatile (
"    B       loc_FF985FB8 \n"

"loc_FF985F60:\n"
"    LDR     R1, [R4, #0xF0] \n"
"    BLX     R1 \n"
//begin patch
"    LDR     R0, =video_compression_rate\n" //added
"    BL      set_quality\n"                 //added
//end patch
"    B       loc_FF985FB8 \n"

"loc_FF985F6C:\n"
"    LDR     R1, [R0, #0x18] \n"
"    LDR     R0, [R0, #4] \n"
"    BL      sub_FFAE8128 \n"
"    B       loc_FF985FB8 \n"

"loc_FF985F7C:\n"
"    LDR     R0, [R4, #0x44] \n"
"    CMP     R0, #5 \n"
"    STRNE   R8, [R4, #0x34] \n"
"    B       loc_FF985FB8 \n"

"loc_FF985F8C:\n"
"    BL      sub_FF9848A8 \n"
"    B       loc_FF985FB8 \n"

"loc_FF985F94:\n"
"    BL      sub_FF9845C8 \n"
"    B       loc_FF985FB8 \n"

"loc_FF985F9C:\n"
"    BL      sub_FF984380 \n"
"    B       loc_FF985FB8 \n"

"loc_FF985FA4:\n"
"    BL      sub_FF983FA8 \n"
"    B       loc_FF985FB8 \n"

"loc_FF985FAC:\n"
"    BL      sub_FF983F28 \n"
"    B       loc_FF985FB8 \n"

"loc_FF985FB4:\n"
"    BL      sub_FF986508 \n"

"loc_FF985FB8:\n"
"    LDR     R1, [SP, #4] \n"
"    LDR     R3, =0xFF983CA4 /*'MovieRecorder.c'*/ \n"
"    STR     R5, [R1] \n"
"    STR     R9, [SP] \n"
"    LDR     R0, [R4, #0x28] \n"
"    MOV     R2, R10 \n"
"    BL      sub_FF83BF2C /*_PostMessageQueueStrictly*/ \n"
"    B       loc_FF985E7C \n"
);
}

/*************************************************************/
//** sub_FF985498_my @ 0xFF985498 - 0xFF985778, length=185
void __attribute__((naked,noinline)) sub_FF985498_my() {
asm volatile (
"    STMFD   SP!, {R0-R8,LR} \n"
"    LDR     R6, =0x6D88 \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R6, #0x34] \n"
"    STR     R0, [R6, #0x38] \n"
"    MOV     R0, R6 \n"
"    LDR     R0, [R0, #0x5C] \n"
"    LDRH    R1, [R6, #6] \n"
"    MOV     R3, #0x3E8 \n"
"    MUL     R0, R3, R0 \n"
"    CMP     R1, #0 \n"
"    MOV     R2, #1 \n"
"    BNE     loc_FF9854DC \n"
"    LDR     R1, [R6, #0x90] \n"
"    CMP     R1, #0 \n"
"    BNE     loc_FF9854EC \n"
"    B       loc_FF9854E4 \n"

"loc_FF9854DC:\n"
"    CMP     R1, #3 \n"
"    BNE     loc_FF9854EC \n"

"loc_FF9854E4:\n"
"    STR     R2, [R6, #0x48] \n"
"    B       loc_FF9854F8 \n"

"loc_FF9854EC:\n"
"    MOV     R1, #0x3E8 \n"
"    BL      sub_FFB9C8C4 /*__divmod_unsigned_int*/ \n"
"    STR     R0, [R6, #0x48] \n"

"loc_FF9854F8:\n"
"    LDR     R4, =0xB225C \n"
"    MOV     R7, #2 \n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF985560 \n"
"    LDR     R0, [R6, #0x58] \n"
"    MOV     R1, #4 \n"
"    CMP     R0, #0x18 \n"
"    BEQ     loc_FF9856F4 \n"
"    BGT     loc_FF98553C \n"
"    CMP     R0, #0xA \n"
"    CMPNE   R0, #0xF \n"
"    STREQ   R7, [R4, #0x14] \n"
"    BEQ     loc_FF985560 \n"
"    CMP     R0, #0x14 \n"
"    BNE     loc_FF985554 \n"
"    B       loc_FF9856F4 \n"

"loc_FF98553C:\n"
"    CMP     R0, #0x1E \n"
"    BEQ     loc_FF9856F4 \n"
"    CMP     R0, #0x3C \n"
"    MOVEQ   R0, #8 \n"
"    STREQ   R0, [R4, #0x14] \n"
"    BEQ     loc_FF985560 \n"

"loc_FF985554:\n"
"    LDR     R1, =0x777 \n"
"    LDR     R0, =0xFF983CA4 /*'MovieRecorder.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF985560:\n"
"    LDR     R2, =0x6D8A \n"
"    LDR     R0, [R6, #0xB8] \n"
"    MOV     R3, #2 \n"
"    MOV     R1, #0xAA \n"
"    BL      sub_FF896298 \n"
"    LDR     R2, =0x6D8C \n"
"    LDR     R0, [R6, #0xB8] \n"
"    MOV     R3, #2 \n"
"    MOV     R1, #0xA9 \n"
"    BL      sub_FF896298 \n"
"    LDR     R2, =0x6DD8 \n"
"    LDR     R0, [R6, #0xB8] \n"
"    MOV     R3, #4 \n"
"    MOV     R1, #0xA2 \n"
"    BL      sub_FF896298 \n"
"    LDR     R2, =0x6DDC \n"
"    LDR     R0, [R6, #0xB8] \n"
"    MOV     R3, #4 \n"
"    MOV     R1, #0xA3 \n"
"    BL      sub_FF896298 \n"
"    LDR     R0, [R6, #0x90] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0x6E88 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, #0xD \n"
"    BLNE    sub_FF8907A4 /*_exmem_ualloc*/ \n"
"    LDR     R0, [R6, #0x4C] \n"
"    LDR     R5, =0x6E88 \n"
"    LDR     R8, =0xB2244 \n"
"    CMP     R0, #2 \n"
"    CMPNE   R0, #3 \n"
"    BNE     loc_FF98565C \n"
"    LDR     R0, [R6, #0x90] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, =0x443FC000 \n"
"    STRNE   R0, [R5] \n"
"    BNE     loc_FF98565C \n"
"    LDR     R0, =0x460B8600 \n"
"    LDR     R1, =0x10959E0 \n"
"    STR     R0, [R5] \n"
"    STR     R1, [R5, #4] \n"
"    LDMIA   R8, {R1,R2} \n"
"    STR     R0, [R6, #0xA0] \n"
"    MUL     R1, R2, R1 \n"
"    MOV     R2, #0 \n"
"    MOV     R3, R1, LSL#1 \n"
"    ADD     R1, R0, R3 \n"
"    STR     R3, [R6, #0x9C] \n"
"    STR     R1, [R6, #0xA4] \n"
"    STMEA   SP, {R1-R3} \n"
"    MOV     R3, R2 \n"
"    MOV     R2, #9 \n"
"    MOV     R1, #5 \n"
"    MOV     R0, #0x10 \n"
"    BL      sub_FFA9A59C \n"
"    LDR     R1, [R5] \n"
"    LDR     R0, [R6, #0x9C] \n"
"    ADD     R1, R1, R0, LSL#1 \n"
"    STR     R1, [R5] \n"
"    LDR     R1, [R5, #4] \n"
"    RSB     R0, R0, #0 \n"
"    ADD     R0, R1, R0, LSL#1 \n"
"    STR     R0, [R5, #4] \n"

"loc_FF98565C:\n"
"    LDR     R3, =0xFF985464 \n"
"    LDMIA   R5, {R0,R1} \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =0xB225C \n"
"    SUB     R2, R3, #0x18 \n"
"    BL      sub_FFAE6A8C_my \n"  // --> Patched. Old value = 0xFFAE6A8C.
"    LDR     R3, [R6, #0xB8] \n"
"    STR     R3, [SP] \n"
"    LDR     R0, [R6, #0x90] \n"
"    LDRD    R2, [R6, #0xF8] \n"
"    BL      sub_FFAE6EA0 \n"
"    LDR     R0, [R6, #0x64] \n"
"    LDR     R3, =0x6E10 \n"
"    AND     R1, R0, #0xFF \n"
"    LDR     R0, [R8] \n"
"    SUB     R2, R3, #4 \n"
"    BL      sub_FFAE4C08 \n"
"    LDRH    R0, [R6, #6] \n"
"    CMP     R0, #2 \n"
"    LDREQ   R0, =0xFF985138 \n"
"    STREQ   R0, [R6, #0xF0] \n"
"    LDR     R0, [R6, #0x90] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0xFF984D7C \n"
"    STREQ   R1, [R6, #0xF0] \n"
"    LDR     R2, [R6, #0xC] \n"
"    LDR     R1, =0xFFBE039C \n"
"    CMP     R2, #2 \n"
"    BNE     loc_FF9856FC \n"
"    LDR     R0, [R6, #0x4C] \n"
"    ADD     R0, R1, R0, LSL#3 \n"
"    LDR     R1, [R8, #0xC] \n"
"    LDR     R0, [R0, R1, LSL#2] \n"
"    BL      sub_FFAA0638 \n"
"    LDR     R0, =0xFF984CA8 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FFAA0B4C \n"
"    B       loc_FF985738 \n"

"loc_FF9856F4:\n"
"    STR     R1, [R4, #0x14] \n"
"    B       loc_FF985560 \n"

"loc_FF9856FC:\n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF985718 \n"
"    LDR     R1, [R6, #0x98] \n"
"    MOV     R0, #5 \n"
"    BL      sub_FFAA0B60 \n"
"    BL      sub_FFAA0BF0 \n"
"    B       loc_FF985738 \n"

"loc_FF985718:\n"
"    LDR     R0, [R6, #0x4C] \n"
"    ADD     R0, R1, R0, LSL#3 \n"
"    LDR     R1, [R8, #0xC] \n"
"    LDR     R0, [R0, R1, LSL#2] \n"
"    BL      sub_FFA9EDC8 \n"
"    LDR     R0, =0xFF984CA8 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FFA9F514 \n"

"loc_FF985738:\n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF98576C \n"
"    ADD     R0, SP, #0xC \n"
"    BL      sub_FFAE7FA4 \n"
"    LDR     R1, [R4, #0xC] \n"
"    LDR     R0, [SP, #0xC] \n"
"    BL      sub_FF8678CC \n"
"    ADD     R0, SP, #0xC \n"
"    BL      sub_FFAE7FA4 \n"
"    LDR     R1, [R4, #0xC] \n"
"    LDR     R0, [SP, #0xC] \n"
"    BL      sub_FF8678CC \n"

"loc_FF98576C:\n"
"    LDR     R0, =0xFF984C60 \n"
"    STR     R7, [R6, #0x44]! \n"
"    STR     R0, [R6, #0x94] \n"
"    LDMFD   SP!, {R0-R8,PC} \n"
);
}

/*************************************************************/
//** sub_FFAE6A8C_my @ 0xFFAE6A8C - 0xFFAE6E44, length=239
void __attribute__((naked,noinline)) sub_FFAE6A8C_my() {
asm volatile (
"    STMFD   SP!, {R0-R12,LR} \n"
"    MOV     R9, R0 \n"
"    LDR     R0, [R2, #0x10] \n"
"    LDR     R8, [SP, #0x38] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x32A \n"
"    LDREQ   R0, =0xFFAE5A68 /*'MovWriter.c'*/ \n"
"    MOV     R5, #0 \n"
"    MOV     R4, R2 \n"
"    MOV     R10, R3 \n"
"    MOV     R7, R5 \n"
"    BLEQ    _DebugAssert \n"
"    LDR     R6, =0xC718 \n"
"    LDR     R0, [R4] \n"
"    MOV     R11, #0x1E \n"
"    STR     R0, [R6, #0xD0] \n"
"    LDR     R0, [R4, #4] \n"
"    STR     R0, [R6, #0xD4] \n"
"    LDR     R0, [R4, #0x10] \n"
"    STR     R0, [R6, #0xE0] \n"
"    LDR     R1, [R4, #8] \n"
"    LDR     R0, =0x7530 \n"
"    CMP     R1, #0xB \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FFAE6B78 \n"
"    B       loc_FFAE6B2C \n"
"    B       loc_FFAE6B1C \n"
"    B       loc_FFAE6B54 \n"
"    B       loc_FFAE6B68 \n"
"    B       loc_FFAE6B78 \n"
"    B       loc_FFAE6B78 \n"
"    B       loc_FFAE6B78 \n"
"    B       loc_FFAE6B78 \n"
"    B       loc_FFAE6B4C \n"
"    B       loc_FFAE6B44 \n"
"    B       loc_FFAE6B34 \n"

"loc_FFAE6B1C:\n"
"    LDR     R7, =0x5DC0 \n"
"    MOV     R0, #0x18 \n"
"    STR     R7, [R6, #0x12C] \n"
"    B       loc_FFAE6B60 \n"

"loc_FFAE6B2C:\n"
"    MOV     R7, R0 \n"
"    B       loc_FFAE6B38 \n"

"loc_FFAE6B34:\n"
"    LDR     R7, =0x5DC \n"

"loc_FFAE6B38:\n"
"    STR     R0, [R6, #0x12C] \n"
"    STR     R11, [R6, #0xD8] \n"
"    B       loc_FFAE6B84 \n"

"loc_FFAE6B44:\n"
"    LDR     R7, =0xBB8 \n"
"    B       loc_FFAE6B38 \n"

"loc_FFAE6B4C:\n"
"    LDR     R7, =0x1770 \n"
"    B       loc_FFAE6B38 \n"

"loc_FFAE6B54:\n"
"    LDR     R7, =0x57600000 \n"  // --> Patched. Old value = 0x3A980. 2hrs 240fps
"    STR     R0, [R6, #0x12C] \n"
"    MOV     R0, #0xF0 \n"

"loc_FFAE6B60:\n"
"    STR     R0, [R6, #0xD8] \n"
"    B       loc_FFAE6B84 \n"

"loc_FFAE6B68:\n"
"    STR     R0, [R6, #0x12C] \n"
"    LDR     R7, =0x28800000 \n"  // --> Patched. Old value = 0x1D4C0. 2hrs 120fps
"    MOV     R0, #0x78 \n"
"    B       loc_FFAE6B60 \n"

"loc_FFAE6B78:\n"
"    LDR     R1, =0x35B \n"
"    LDR     R0, =0xFFAE5A68 /*'MovWriter.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FFAE6B84:\n"
"    LDR     R0, [R6, #0xD8] \n"
"    LDR     R1, =0x1C20 \n"  // --> Patched. Old value = 0xE0F. 2hrs
"    MOV     R0, R0, LSR#1 \n"
"    STR     R0, [R6, #0xDC] \n"
"    LDR     R0, [R10] \n"
"    STR     R0, [R6, #0xE4] \n"
"    LDRH    R0, [R10, #0x10] \n"
"    STR     R0, [R6, #0xE8] \n"
"    LDR     R0, [R10, #4] \n"
"    STRH    R0, [R6, #2] \n"
"    LDR     R0, [R10, #8] \n"
"    STRH    R0, [R6, #4] \n"
"    LDR     R0, [R10, #0x14] \n"
"    STR     R0, [R6, #0xEC] \n"
"    STR     R8, [R6, #0x128] \n"
"    LDR     R0, [R6, #0xD0] \n"
"    CMP     R0, #0x140 \n"
"    MOVEQ   R0, #0x20000 \n"
"    MOVEQ   R5, #1 \n"
"    STREQ   R0, [R6, #0xAC] \n"
"    BEQ     loc_FFAE6C18 \n"
"    CMP     R0, #0x280 \n"
"    LDREQ   R0, =0x7A760 \n"
"    MOVEQ   R5, #2 \n"
"    STREQ   R0, [R6, #0xAC] \n"
"    BEQ     loc_FFAE6C18 \n"
"    CMP     R0, #0x500 \n"
"    LDREQ   R0, =0x11DA50 \n"
"    LDR     R1, =0x1C20 \n"  // --> Patched. Old value = 0x257. 2hrs
"    MOVEQ   R5, #4 \n"
"    STREQ   R0, [R6, #0xAC] \n"
"    BEQ     loc_FFAE6C18 \n"
"    CMP     R0, #0x780 \n"
"    BNE     loc_FFAE6C20 \n"
"    MOV     R0, #0x200000 \n"
"    MOV     R5, #5 \n"
"    STR     R0, [R6, #0xAC] \n"

"loc_FFAE6C18:\n"
"    STR     R1, [R6, #0x4C] \n"
"    B       loc_FFAE6C2C \n"

"loc_FFAE6C20:\n"
"    LDR     R1, =0x383 \n"
"    LDR     R0, =0xFFAE5A68 /*'MovWriter.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FFAE6C2C:\n"
"    LDR     R0, [R6, #0x4C] \n"
"    LDR     R1, =0x138D \n"
"    MUL     R0, R7, R0 \n"
"    BL      sub_FFB9C8C4 /*__divmod_unsigned_int*/ \n"
"    ADD     R0, R0, #1 \n"
"    ADD     R0, R0, R0, LSL#2 \n"
"    STR     R0, [R6, #0x48] \n"
"    LDR     R8, [R4, #8] \n"
"    CMP     R8, #2 \n"
"    CMPNE   R8, #3 \n"
"    BNE     loc_FFAE6C84 \n"
"    RSB     R0, R7, R7, LSL#4 \n"
"    LDR     R1, =0x3E9 \n"
"    MOV     R0, R0, LSL#1 \n"
"    STR     R11, [R6, #0x4C] \n"
"    BL      sub_FFB9C8C4 /*__divmod_unsigned_int*/ \n"
"    LDR     R1, [R6, #0xE0] \n"
"    MOV     R7, R1 \n"
"    BL      sub_FFB9C8C4 /*__divmod_unsigned_int*/ \n"
"    ADD     R0, R0, #1 \n"
"    MUL     R0, R7, R0 \n"
"    STR     R0, [R6, #0x48] \n"

"loc_FFAE6C84:\n"
"    LDR     R0, [R4, #0xC] \n"
"    LDR     R7, [R10, #0xC] \n"
"    MOVS    R1, R0 \n"
"    MOV     R0, R7, LSR#1 \n"
"    STR     R7, [R6, #0x94] \n"
"    STR     R0, [R6, #0x98] \n"
"    ADD     R0, R9, #3 \n"
"    BIC     R0, R0, #3 \n"
"    STR     R0, [R6, #0xF4] \n"
"    LDR     R2, [R6, #0x48] \n"
"    MOVNE   R1, #1 \n"
"    MOV     R2, R2, LSL#2 \n"
"    ADD     R3, R0, R2 \n"
"    STR     R3, [R6, #0xF8] \n"
"    LDRH    R12, [R6, #4] \n"
"    LDR     R0, [SP, #4] \n"
"    ADD     R2, R2, R3 \n"
"    CMP     R12, #0 \n"
"    ADD     R0, R0, R9 \n"
"    BEQ     loc_FFAE6E00 \n"
"    STR     R2, [R6, #0xFC] \n"
"    LDR     R3, [R6, #0x4C] \n"
"    LDR     R9, =0x1090D8 \n"
"    ADD     R2, R2, R3, LSL#3 \n"
"    ADD     R2, R2, #0x1F \n"
"    BIC     R2, R2, #0x1F \n"
"    STR     R2, [R6, #0x100] \n"
"    LDR     R3, [R6, #0xAC] \n"
"    LDR     R11, =0xC898 \n"
"    ADD     R2, R2, R3 \n"
"    ADD     R3, R2, #0x100000 \n"
"    STR     R2, [R6, #0x78] \n"
"    SUB     R0, R0, R3 \n"
"    RSB     R2, R7, #0 \n"
"    ADD     R0, R0, R2, LSL#1 \n"
"    MOV     R0, R0, LSR#15 \n"
"    MOV     R0, R0, LSL#15 \n"
"    STR     R3, [R6, #0x104] \n"
"    ADD     R8, R3, R0 \n"
"    STR     R0, [R6, #0x110] \n"
"    STR     R8, [R6, #0x108] \n"
"    MOV     R2, #0 \n"
"    ADD     R10, R9, #0x10 \n"
"    STR     R8, [R6, #0x10C] \n"

"loc_FFAE6D34:\n"
"    MLA     R0, R2, R7, R8 \n"
"    ADD     R12, R9, R2, LSL#3 \n"
"    ADD     R0, R0, #3 \n"
"    BIC     R0, R0, #3 \n"
"    STR     R0, [R11, R2, LSL#2] \n"
"    MOV     R0, #0 \n"
"    ADD     R6, R10, R2, LSL#3 \n"

"loc_FFAE6D50:\n"
"    STR     R3, [R12, R0, LSL#2] \n"
"    STR     R3, [R6, R0, LSL#2] \n"
"    ADD     R0, R0, #1 \n"
"    CMP     R0, #2 \n"
"    BLT     loc_FFAE6D50 \n"
"    ADD     R2, R2, #1 \n"
"    CMP     R2, #2 \n"
"    BLT     loc_FFAE6D34 \n"
"    LDRH    R3, [R4, #0x14] \n"
"    LDR     R2, [R4, #8] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF8E06B4 \n"
"    LDR     R1, =0xC718 \n"
"    LDR     R2, [R1, #0x94] \n"
"    ADD     R0, R0, R2 \n"
"    STR     R0, [R1, #0x8C] \n"
"    LDMFD   SP!, {R0-R12,PC} \n"

"loc_FFAE6E00:\n"
"    ADD     R2, R2, #0x1F \n"
"    BIC     R2, R2, #0x1F \n"
"    STR     R2, [R6, #0x100] \n"
"    LDR     R3, [R6, #0xAC] \n"
"    ADD     R2, R2, R3 \n"
"    SUB     R0, R0, R2 \n"
"    MOV     R0, R0, LSR#15 \n"
"    MOV     R0, R0, LSL#15 \n"
"    STR     R2, [R6, #0x104] \n"
"    STR     R0, [R6, #0x110] \n"
"    ADD     R0, R0, R2 \n"
"    STR     R0, [R6, #0x108] \n"
"    LDRH    R3, [R4, #0x14] \n"
"    MOV     R2, R8 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF8E06B4 \n"
"    STR     R0, [R6, #0x8C] \n"
"    LDMFD   SP!, {R0-R12,PC} \n"
);
}
