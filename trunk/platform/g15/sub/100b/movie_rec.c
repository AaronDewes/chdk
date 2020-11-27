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
//** movie_record_task @ 0xFF1DF2B0 - 0xFF1DF474, length=114
void __attribute__((naked,noinline)) movie_record_task() {
asm volatile (
"    STMFD   SP!, {R2-R10,LR} \n"
"    LDR     R8, =sub_FF1DEEE0_my \n"  // --> Patched. Old value = 0xFF1DEEE0.
"    LDR     R4, =0x9408 \n"
"    LDR     R9, =0x65B \n"
"    LDR     R10, =0x2710 \n"
"    MVN     R7, #0 \n"
"    MOV     R5, #1 \n"
"    MOV     R6, #0 \n"

"loc_FF1DF2D0:\n"
"    LDR     R0, [R4, #0x28] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_0068BDE0 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [R4, #0x30] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, [R4, #0x10] \n"
"    CMPNE   R0, #2 \n"
"    LDRNE   R0, [R4, #0x44] \n"
"    CMPNE   R0, #6 \n"
"    BNE     loc_FF1DF458 \n"
"    LDR     R0, [SP, #4] \n"
"    LDR     R1, [R0] \n"
"    SUB     R1, R1, #2 \n"
"    CMP     R1, #0xF \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF1DF458 \n"
"    B       loc_FF1DF3A0 \n"
"    B       loc_FF1DF3C4 \n"
"    B       loc_FF1DF3D4 \n"
"    B       loc_FF1DF3DC \n"
"    B       loc_FF1DF3E4 \n"
"    B       loc_FF1DF3EC \n"
"    B       loc_FF1DF3A8 \n"
"    B       loc_FF1DF418 \n"
"    B       loc_FF1DF444 \n"
"    B       loc_FF1DF44C \n"
"    B       loc_FF1DF3B4 \n"
"    B       loc_FF1DF458 \n"
"    B       loc_FF1DF454 \n"
"    B       loc_FF1DF37C \n"
"    B       loc_FF1DF350 \n"

"loc_FF1DF350:\n"
"    STR     R6, [R4, #0x40] \n"
"    STR     R6, [R4, #0x34] \n"
"    STR     R7, [R4, #0xE4] \n"
"    STRH    R6, [R4, #6] \n"
"    STR     R8, [R4, #0xCC] \n"
"    LDR     R0, [R4, #0x10] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0x10] \n"
"    MOV     R0, #6 \n"
"    STR     R0, [R4, #0x44] \n"
"    B       loc_FF1DF398 \n"

"loc_FF1DF37C:\n"
"    STR     R6, [R4, #0x40] \n"
"    STR     R7, [R4, #0xE4] \n"
"    STR     R8, [R4, #0xCC] \n"
"    LDR     R0, [R4, #0x10] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0x10] \n"
"    STR     R5, [R4, #0x44] \n"

"loc_FF1DF398:\n"
"    STR     R5, [R4, #8] \n"
"    B       loc_FF1DF458 \n"

"loc_FF1DF3A0:\n"
);
if (conf.ext_video_time == 1)
{
asm volatile (
"    BL      sub_FF1DEB44_my \n"  // --> Patched. Old value = 0xFF1DEB44.
);
}
else
{
asm volatile (
"    BL      sub_FF1DEB44 \n"
);
}
asm volatile (
"    B       loc_FF1DF458 \n"

"loc_FF1DF3A8:\n"
"    LDR     R1, [R4, #0xCC] \n"
"    BLX     R1 \n"
//begin patch
"    LDR     R0, =video_compression_rate\n" //added
"    BL      set_quality\n"                 //added
//end patch
"    B       loc_FF1DF458 \n"

"loc_FF1DF3B4:\n"
"    LDR     R1, [R0, #0x18] \n"
"    LDR     R0, [R0, #4] \n"
"    BL      sub_FF38677C \n"
"    B       loc_FF1DF458 \n"

"loc_FF1DF3C4:\n"
"    LDR     R0, [R4, #0x44] \n"
"    CMP     R0, #5 \n"
"    STRNE   R5, [R4, #0x34] \n"
"    B       loc_FF1DF458 \n"

"loc_FF1DF3D4:\n"
"    BL      sub_FF1DE09C \n"
"    B       loc_FF1DF458 \n"

"loc_FF1DF3DC:\n"
"    BL      sub_FF1DDF84 \n"
"    B       loc_FF1DF458 \n"

"loc_FF1DF3E4:\n"
"    BL      sub_FF1DDC3C \n"
"    B       loc_FF1DF458 \n"

"loc_FF1DF3EC:\n"
"    LDR     R1, [R4, #0x94] \n"
"    LDR     R0, =0x4840F640 \n"
"    CMP     R1, #0 \n"
"    LDREQ   R1, =0xFF1DDC00 \n"
"    LDREQ   R0, [R4, #0x98] \n"
"    BEQ     loc_FF1DF410 \n"
"    BL      sub_FF387438 \n"
"    LDR     R1, =0xFF1DDC00 \n"
"    MOV     R0, #0 \n"

"loc_FF1DF410:\n"
"    BL      sub_FF3858DC \n"
"    B       loc_FF1DF458 \n"

"loc_FF1DF418:\n"
"    LDR     R0, =0xDF4FC \n"
"    LDR     R0, [R0, #8] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0xFF1DDB88 \n"
"    LDRNE   R0, =0xFF1DDBDC \n"
"    MOVNE   R3, #0 \n"
"    MOVNE   R1, R3 \n"
"    BLNE    sub_FF0616E0 \n"
"    MOV     R0, #3 \n"
"    STR     R0, [R4, #0x44] \n"
"    B       loc_FF1DF458 \n"

"loc_FF1DF444:\n"
"    BL      sub_FF1DDB08 \n"
"    B       loc_FF1DF458 \n"

"loc_FF1DF44C:\n"
"    BL      sub_FF1DFEAC \n"
"    B       loc_FF1DF458 \n"

"loc_FF1DF454:\n"
"    BL      sub_FF1DFDCC \n"

"loc_FF1DF458:\n"
"    LDR     R1, [SP, #4] \n"
"    LDR     R3, =0xFF1DD7A0 /*'MovieRecorder.c'*/ \n"
"    STR     R6, [R1] \n"
"    STR     R9, [SP] \n"
"    LDR     R0, [R4, #0x2C] \n"
"    MOV     R2, R10 \n"
"    BL      sub_0068B044 /*_PostMessageQueueStrictly*/ \n"
"    B       loc_FF1DF2D0 \n"
);
}

/*************************************************************/
//** sub_FF1DEB44_my @ 0xFF1DEB44 - 0xFF1DEE74, length=205
void __attribute__((naked,noinline)) sub_FF1DEB44_my() {
asm volatile (
"    STMFD   SP!, {R0-R10,LR} \n"
"    LDR     R6, =0x9408 \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R6, #0x34] \n"
"    STR     R0, [R6, #0x38] \n"
"    MOV     R0, R6 \n"
"    LDR     R4, [R0, #0x58] \n"
"    LDRH    R1, [R6, #6] \n"
"    MOV     R0, #0x3E8 \n"
"    MUL     R0, R4, R0 \n"
"    LDR     R8, =0xFFF00 \n"
"    CMP     R1, #0 \n"
"    MOV     R2, #1 \n"
"    BNE     loc_FF1DEB8C \n"
"    LDR     R1, [R6, #0x80] \n"
"    CMP     R1, #0 \n"
"    BNE     loc_FF1DEB9C \n"
"    B       loc_FF1DEB94 \n"

"loc_FF1DEB8C:\n"
"    CMP     R1, #3 \n"
"    BNE     loc_FF1DEB9C \n"

"loc_FF1DEB94:\n"
"    STR     R2, [R6, #0x48] \n"
"    B       loc_FF1DEBA8 \n"

"loc_FF1DEB9C:\n"
"    MOV     R1, #0x3E8 \n"
"    BL      sub_0069092C /*__divmod_unsigned_int*/ \n"
"    STR     R0, [R6, #0x48] \n"

"loc_FF1DEBA8:\n"
"    LDR     R5, =0xDF4FC \n"
"    MOV     R7, #2 \n"
"    LDR     R0, [R5, #8] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF1DEC14 \n"
"    CMP     R4, #0x18 \n"
"    MOV     R0, #4 \n"
"    BEQ     loc_FF1DEC00 \n"
"    BGT     loc_FF1DEBE8 \n"
"    CMP     R4, #0xA \n"
"    CMPNE   R4, #0xF \n"
"    STREQ   R7, [R5, #0x14] \n"
"    BEQ     loc_FF1DEC14 \n"
"    CMP     R4, #0x14 \n"
"    BNE     loc_FF1DEC08 \n"
"    B       loc_FF1DEC00 \n"

"loc_FF1DEBE8:\n"
"    CMP     R4, #0x19 \n"
"    CMPNE   R4, #0x1E \n"
"    BEQ     loc_FF1DEC00 \n"
"    CMP     R4, #0x3C \n"
"    BNE     loc_FF1DEC08 \n"
"    MOV     R0, #8 \n"

"loc_FF1DEC00:\n"
"    STR     R0, [R5, #0x14] \n"
"    B       loc_FF1DEC14 \n"

"loc_FF1DEC08:\n"
"    LDR     R1, =0x74C \n"
"    LDR     R0, =0xFF1DD7A0 /*'MovieRecorder.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF1DEC14:\n"
"    LDR     R0, [R6, #0x64] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF1DEC2C \n"
"    BL      sub_FF338178 \n"
"    LDR     R0, =0xDF514 \n"
"    BL      sub_FF381C04 \n"

"loc_FF1DEC2C:\n"
"    LDR     R2, =0x940A \n"
"    LDR     R0, [R6, #0xA4] \n"
"    MOV     R3, #2 \n"
"    MOV     R1, #0xAA \n"
"    BL      sub_FF099B28 \n"
"    LDR     R2, =0x940C \n"
"    LDR     R0, [R6, #0xA4] \n"
"    MOV     R3, #2 \n"
"    MOV     R1, #0xA9 \n"
"    BL      sub_FF099B28 \n"
"    LDR     R2, =0x9458 \n"
"    LDR     R0, [R6, #0xA4] \n"
"    MOV     R3, #4 \n"
"    MOV     R1, #0xA2 \n"
"    BL      sub_FF099B28 \n"
"    LDR     R2, =0x945C \n"
"    LDR     R0, [R6, #0xA4] \n"
"    MOV     R3, #4 \n"
"    MOV     R1, #0xA3 \n"
"    BL      sub_FF099B28 \n"
"    LDR     R0, [R6, #0x80] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0x9500 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, #0xF \n"
"    BLNE    _exmem_ualloc \n"
"    LDR     R0, [R6, #0x4C] \n"
"    LDR     R4, =0x9500 \n"
"    LDR     R9, =0xDF4E4 \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #2 \n"
"    BNE     loc_FF1DED60 \n"
"    LDR     R0, [R6, #0x80] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, =0x483FC000 \n"
"    STRNE   R0, [R4] \n"
"    BNE     loc_FF1DED60 \n"
"    LDR     R1, =0x484B4600 \n"
"    LDR     R0, =0x3870600 \n"
"    STR     R1, [R4] \n"
"    STR     R0, [R4, #4] \n"
"    LDMIA   R9, {R0,R2} \n"
"    MUL     R0, R2, R0 \n"
"    MOV     R3, R0, LSL#1 \n"
"    CMP     R3, R8 \n"
"    STR     R3, [R6, #0x8C] \n"
"    MOVCC   R2, #0 \n"
"    STR     R1, [R6, #0x90] \n"
"    BCC     loc_FF1DED28 \n"
"    MOV     R2, #0 \n"
"    STMEA   SP, {R1,R2,R8} \n"
"    MOV     R3, R2 \n"
"    MOV     R2, #9 \n"
"    MOV     R1, #5 \n"
"    MOV     R0, #0x16 \n"
"    BL      sub_FF330B18 \n"
"    LDR     R0, [R6, #0x8C] \n"
"    MOV     R2, #0 \n"
"    SUB     R3, R0, #0xF0000 \n"
"    LDR     R0, [R6, #0x90] \n"
"    SUB     R3, R3, #0xFF00 \n"
"    ADD     R1, R0, #0xF0000 \n"
"    ADD     R1, R1, #0xFF00 \n"

"loc_FF1DED28:\n"
"    STMEA   SP, {R1-R3} \n"
"    MOV     R3, #0 \n"
"    MOV     R2, #9 \n"
"    MOV     R1, #5 \n"
"    MOV     R0, #0x16 \n"
"    BL      sub_FF330B18 \n"
"    LDR     R1, [R4] \n"
"    LDR     R0, [R6, #0x8C] \n"
"    ADD     R1, R1, R0, LSL#1 \n"
"    STR     R1, [R4] \n"
"    LDR     R1, [R4, #4] \n"
"    RSB     R0, R0, #0 \n"
"    ADD     R0, R1, R0, LSL#1 \n"
"    STR     R0, [R4, #4] \n"

"loc_FF1DED60:\n"
"    LDR     R2, =0xDF4FC \n"
"    LDR     R3, =0xFF1DEB10 \n"
"    LDR     R0, [R4, #4] \n"
"    LDR     R1, [R4] \n"
"    STRD    R2, [SP] \n"
"    SUB     R3, R2, #0x18 \n"
"    MOV     R2, R0 \n"
"    LDR     R0, [R6, #0x80] \n"
"    BL      sub_FF384C8C_my \n"  // --> Patched. Old value = 0xFF384C8C.
"    LDRD    R0, [R6, #0xF0] \n"
"    LDR     R2, [R6, #0xA4] \n"
"    BL      sub_FF3852C4 \n"
"    LDR     R3, =0x9480 \n"
"    STR     R3, [SP] \n"
"    LDR     R0, [R6, #0x64] \n"
"    LDR     R1, [R9, #8] \n"
"    AND     R2, R0, #0xFF \n"
"    LDR     R0, [R9] \n"
"    SUB     R3, R3, #4 \n"
"    BL      sub_FF381760 \n"
"    LDRH    R0, [R6, #6] \n"
"    CMP     R0, #2 \n"
"    LDREQ   R0, =0xFF1DE810 \n"
"    STREQ   R0, [R6, #0xCC] \n"
"    LDR     R0, [R6, #0x80] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0xFF1DE3CC \n"
"    STREQ   R1, [R6, #0xCC] \n"
"    LDR     R2, [R6, #0x10] \n"
"    LDR     R1, =0xFF615220 \n"
"    CMP     R2, #2 \n"
"    BNE     loc_FF1DEE04 \n"
"    LDR     R0, [R6, #0x4C] \n"
"    ADD     R0, R1, R0, LSL#3 \n"
"    LDR     R1, [R9, #0xC] \n"
"    LDR     R0, [R0, R1, LSL#2] \n"
"    BL      sub_FF336F04 \n"
"    LDR     R0, =0xFF1DE384 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF337490 \n"
"    B       loc_FF1DEE3C \n"

"loc_FF1DEE04:\n"
"    CMP     R0, #0 \n"
"    LDR     R0, [R6, #0x4C] \n"
"    ADD     R0, R1, R0, LSL#3 \n"
"    LDR     R1, [R9, #0xC] \n"
"    LDR     R0, [R0, R1, LSL#2] \n"
"    BNE     loc_FF1DEE2C \n"
"    LDR     R1, [R6, #0x88] \n"
"    BL      sub_FF337570 \n"
"    BL      sub_FF3375F4 \n"
"    B       loc_FF1DEE3C \n"

"loc_FF1DEE2C:\n"
"    BL      sub_FF3350F0 \n"
"    LDR     R0, =0xFF1DE378 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF335900 \n"

"loc_FF1DEE3C:\n"
"    LDR     R0, [R5, #8] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF1DEE70 \n"
"    ADD     R0, SP, #0xC \n"
"    BL      sub_FF3864E4 \n"
"    LDR     R1, [R5, #0xC] \n"
"    LDR     R0, [SP, #0xC] \n"
"    BL      sub_FF06194C \n"
"    ADD     R0, SP, #0xC \n"
"    BL      sub_FF3864E4 \n"
"    LDR     R1, [R5, #0xC] \n"
"    LDR     R0, [SP, #0xC] \n"
"    BL      sub_FF06194C \n"

"loc_FF1DEE70:\n"
"    STR     R7, [R6, #0x44] \n"
"    LDMFD   SP!, {R0-R10,PC} \n"
);
}

/*************************************************************/
//** sub_FF384C8C_my @ 0xFF384C8C - 0xFF384FF8, length=220
void __attribute__((naked,noinline)) sub_FF384C8C_my() {
asm volatile (
"    STMFD   SP!, {R0-R11,LR} \n"
"    MOV     R9, R0 \n"
"    LDR     R0, [R3, #0x10] \n"
"    SUB     SP, SP, #4 \n"
"    CMP     R0, #0 \n"
"    LDR     R7, [SP, #0x38] \n"
"    LDREQ   R1, =0x3B7 \n"
"    LDREQ   R0, =0xFF382270 /*'MovWriter.c'*/ \n"
"    MOV     R6, #0 \n"
"    MOV     R4, R3 \n"
"    MOV     R5, R6 \n"
"    BLEQ    _DebugAssert \n"
"    LDR     R8, =0x11950 \n"
"    CMP     R9, #0 \n"
"    MOV     R11, #0 \n"
"    STR     R9, [R8, #0xA0] \n"
"    MOVEQ   R0, #1 \n"
"    STRNE   R11, [R8, #0xE8] \n"
"    STREQ   R0, [R8, #0xE8] \n"
"    LDR     R0, [R4] \n"
"    LDR     R3, =0x61A8 \n"
"    STR     R0, [R8, #0xF0] \n"
"    LDR     R0, [R4, #4] \n"
"    LDR     R1, =0x7530 \n"
"    STR     R0, [R8, #0xF4] \n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0x18 \n"
"    STR     R0, [R8, #0x100] \n"
"    LDR     R9, [R4, #8] \n"
"    LDR     R0, =0x3E9 \n"
"    CMP     R9, #0xF \n"
"    MOV     R12, #0x3E8 \n"
"    MOV     R10, #0x1E \n"
"    ADDCC   PC, PC, R9, LSL#2 \n"
"    B       loc_FF384DE4 \n"
"    B       loc_FF384D6C \n"
"    B       loc_FF384D64 \n"
"    B       loc_FF384D54 \n"
"    B       loc_FF384DC0 \n"
"    B       loc_FF384DD0 \n"
"    B       loc_FF384DE4 \n"
"    B       loc_FF384DE4 \n"
"    B       loc_FF384DE4 \n"
"    B       loc_FF384DE4 \n"
"    B       loc_FF384D8C \n"
"    B       loc_FF384D84 \n"
"    B       loc_FF384D7C \n"
"    B       loc_FF384DB8 \n"
"    B       loc_FF384DB0 \n"
"    B       loc_FF384D9C \n"

"loc_FF384D54:\n"
"    LDR     R5, =0x5DC0 \n"
"    STR     R2, [R8, #0xF8] \n"
"    STR     R5, [R8, #0x154] \n"
"    B       loc_FF384D74 \n"

"loc_FF384D64:\n"
"    MOV     R5, R3 \n"
"    B       loc_FF384DA0 \n"

"loc_FF384D6C:\n"
"    MOV     R5, R1 \n"
"    B       loc_FF384D90 \n"

"loc_FF384D74:\n"
"    STR     R0, [R8, #0x158] \n"
"    B       loc_FF384DF0 \n"

"loc_FF384D7C:\n"
"    LDR     R5, =0x5DC \n"
"    B       loc_FF384D90 \n"

"loc_FF384D84:\n"
"    LDR     R5, =0xBB8 \n"
"    B       loc_FF384D90 \n"

"loc_FF384D8C:\n"
"    LDR     R5, =0x1770 \n"

"loc_FF384D90:\n"
"    STR     R1, [R8, #0x154] \n"
"    STR     R10, [R8, #0xF8] \n"
"    B       loc_FF384D74 \n"

"loc_FF384D9C:\n"
"    LDR     R5, =0x4E2 \n"

"loc_FF384DA0:\n"
"    STR     R2, [R8, #0xF8] \n"
"    STR     R3, [R8, #0x154] \n"
"    STR     R12, [R8, #0x158] \n"
"    B       loc_FF384DF0 \n"

"loc_FF384DB0:\n"
"    LDR     R5, =0x9C4 \n"
"    B       loc_FF384DA0 \n"

"loc_FF384DB8:\n"
"    LDR     R5, =0x1388 \n"
"    B       loc_FF384DA0 \n"

"loc_FF384DC0:\n"
"    STR     R1, [R8, #0x154] \n"
"    LDR     R5, =0x57600000 \n"  // --> Patched. Old value = 0x3A980. 2hrs
"    MOV     R1, #0xF0 \n"
"    B       loc_FF384DDC \n"

"loc_FF384DD0:\n"
"    LDR     R5, =0x28800000 \n"  // --> Patched. Old value = 0x1D4C0. 2hrs
"    STR     R1, [R8, #0x154] \n"
"    MOV     R1, #0x78 \n"

"loc_FF384DDC:\n"
"    STR     R1, [R8, #0xF8] \n"
"    B       loc_FF384D74 \n"

"loc_FF384DE4:\n"
"    LDR     R1, =0x411 \n"
"    LDR     R0, =0xFF382270 /*'MovWriter.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF384DF0:\n"
"    LDR     R0, [R8, #0xF8] \n"
"    LDR     R1, =0x1C20 \n"  // --> Patched. Old value = 0xE0F. 2hrs
"    MOV     R0, R0, LSR#1 \n"
"    STR     R0, [R8, #0xFC] \n"
"    LDR     R0, [R7] \n"
"    STR     R0, [R8, #0x104] \n"
"    LDRH    R0, [R7, #0x10] \n"
"    STR     R0, [R8, #0x108] \n"
"    LDR     R0, [R7, #4] \n"
"    STRH    R0, [R8, #2] \n"
"    LDR     R0, [R7, #8] \n"
"    STRH    R0, [R8, #4] \n"
"    LDR     R0, [R7, #0x14] \n"
"    STR     R0, [R8, #0x10C] \n"
"    LDR     R0, [SP, #0x3C] \n"
"    STR     R0, [R8, #0x150] \n"
"    LDR     R0, [R8, #0xF0] \n"
"    CMP     R0, #0x140 \n"
"    MOVEQ   R0, #0x20000 \n"
"    MOVEQ   R6, #1 \n"
"    STREQ   R0, [R8, #0xC4] \n"
"    BEQ     loc_FF384E88 \n"
"    CMP     R0, #0x280 \n"
"    LDREQ   R0, =0x7A760 \n"
"    MOVEQ   R6, #2 \n"
"    STREQ   R0, [R8, #0xC4] \n"
"    BEQ     loc_FF384E88 \n"
"    CMP     R0, #0x500 \n"
"    LDREQ   R0, =0x11DA50 \n"
"    LDR     R1, =0x1C20 \n"  // --> Patched. Old value = 0x707. 2hrs
"    MOVEQ   R6, #4 \n"
"    STREQ   R0, [R8, #0xC4] \n"
"    BEQ     loc_FF384E88 \n"
"    CMP     R0, #0x780 \n"
"    BNE     loc_FF384E90 \n"
//"  MOV     R0, #0x200000 \n"
"    MOV     R0, #2097152 \n" // 10 mins
"    MOV     R6, #5 \n"
"    STR     R0, [R8, #0xC4] \n"

"loc_FF384E88:\n"
"    STR     R1, [R8, #0x58] \n"
"    B       loc_FF384E9C \n"

"loc_FF384E90:\n"
"    LDR     R1, =0x439 \n"
"    LDR     R0, =0xFF382270 /*'MovWriter.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF384E9C:\n"
"    LDR     R9, [R4, #8] \n"
"    CMP     R9, #0xB \n"
"    CMPNE   R9, #0xA \n"
"    CMPNE   R9, #9 \n"
"    BNE     loc_FF384ED0 \n"
"    LDR     R0, [R8, #0xF0] \n"
"    CMP     R0, #0x500 \n"
"    BNE     loc_FF384ED0 \n"
"    LDR     R0, [R8, #0x58] \n"
"    LDR     R1, [R8, #0x158] \n"
"    MUL     R0, R5, R0 \n"
"    BL      sub_0069092C /*__divmod_unsigned_int*/ \n"
"    B       loc_FF384EF0 \n"

"loc_FF384ED0:\n"
"    LDR     R0, [R8, #0x58] \n"
"    LDR     R1, [R8, #0x158] \n"
"    MUL     R0, R5, R0 \n"
"    BL      sub_0069092C /*__divmod_unsigned_int*/ \n"
"    MOV     R1, #5 \n"
"    BL      sub_0069092C /*__divmod_unsigned_int*/ \n"
"    ADD     R0, R0, #1 \n"
"    ADD     R0, R0, R0, LSL#2 \n"

"loc_FF384EF0:\n"
"    CMP     R9, #0xB \n"
"    CMPNE   R9, #0xA \n"
"    CMPNE   R9, #9 \n"
"    STR     R0, [R8, #0x54] \n"
"    BNE     loc_FF384F18 \n"
"    LDR     R1, [R8, #0x158] \n"
"    MUL     R0, R1, R0 \n"
"    MOV     R1, R5 \n"
"    BL      sub_0069092C /*__divmod_unsigned_int*/ \n"
"    STR     R0, [R8, #0x58] \n"

"loc_FF384F18:\n"
"    CMP     R9, #3 \n"
"    CMPNE   R9, #4 \n"
"    BNE     loc_FF384F50 \n"
"    RSB     R0, R5, R5, LSL#4 \n"
"    STR     R10, [R8, #0x58] \n"
"    LDR     R1, [R8, #0x158] \n"
"    MOV     R0, R0, LSL#1 \n"
"    BL      sub_0069092C /*__divmod_unsigned_int*/ \n"
"    LDR     R1, [R8, #0x100] \n"
"    MOV     R10, R1 \n"
"    BL      sub_0069092C /*__divmod_unsigned_int*/ \n"
"    ADD     R0, R0, #1 \n"
"    MUL     R0, R10, R0 \n"
"    STR     R0, [R8, #0x54] \n"

"loc_FF384F50:\n"
"    ADD     R0, R5, R5, LSL#8 \n"
"    LDR     R1, [R8, #0x158] \n"
"    RSB     R0, R0, R0, LSL#3 \n"
"    BL      sub_0069092C /*__divmod_unsigned_int*/ \n"
"    STR     R0, [R8, #0x88] \n"
"    LDR     R0, [R4, #0xC] \n"
"    CMP     R0, #0 \n"
"    MOVNE   R0, #1 \n"
"    STR     R0, [SP] \n"
"    LDR     R5, [R7, #0xC] \n"
"    MOV     R0, R5, LSR#1 \n"
"    STR     R5, [R8, #0xAC] \n"
"    STR     R0, [R8, #0xB0] \n"
"    LDR     R0, [SP, #8] \n"
"    ADD     R0, R0, #3 \n"
"    BIC     R1, R0, #3 \n"
"    STR     R1, [R8, #0x114] \n"
"    LDR     R0, [R8, #0x54] \n"
"    MOV     R0, R0, LSL#2 \n"
"    ADD     R1, R1, R0 \n"
"    STR     R1, [R8, #0x118] \n"
"    LDRH    R7, [R8, #4] \n"
"    LDR     R2, [SP, #0xC] \n"
"    LDR     R3, [SP, #8] \n"
"    CMP     R7, #0 \n"
"    ADD     R10, R3, R2 \n"
"    BEQ     sub_FF38521C \n"
"    ADD     R9, R1, R0 \n"
"    STR     R9, [R8, #0x11C] \n"
"    LDR     R1, [R8, #0xFC] \n"
"    BL      sub_0069092C /*__divmod_unsigned_int*/ \n"
"    ADD     R0, R0, R9 \n"
"    ADD     R0, R0, #0x1F \n"
"    BIC     R0, R0, #0x1F \n"
"    STR     R0, [R8, #0x120] \n"
"    LDR     R1, [R8, #0xE8] \n"
"    CMP     R1, #0 \n"
"    BEQ     sub_FF3850B0 \n"
"    LDR     R2, [R8, #0xC4] \n"
"    ADD     R0, R0, R2 \n"
"    STR     R0, [R8, #0x2C] \n"
"    ADD     R0, R0, #0x20 \n"
"    B       sub_FF385078 \n"
);
}

/*************************************************************/
//** sub_FF1DEEE0_my @ 0xFF1DEEE0 - 0xFF1DF2AC, length=244
void __attribute__((naked,noinline)) sub_FF1DEEE0_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    SUB     SP, SP, #0x48 \n"
"    MOV     R8, #0 \n"
"    LDR     R5, =0x9408 \n"
"    STR     R8, [SP, #0x38] \n"
"    STR     R8, [SP, #0x30] \n"
"    STR     R8, [R5, #0xC4] \n"
"    LDR     R1, [R5, #0x44] \n"
"    MOV     R4, R0 \n"
"    CMP     R1, #3 \n"
"    MOV     R6, R8 \n"
"    MOV     R7, #1 \n"
"    BNE     loc_FF1DEF38 \n"
"    LDR     R0, [R5, #0xE4] \n"
"    LDR     R1, [R5, #0xE8] \n"
"    CMP     R0, R1 \n"
"    BNE     loc_FF1DF058 \n"
"    MOV     R0, #4 \n"
"    STR     R0, [R5, #0x44] \n"
"    MVN     R0, #0 \n"
"    STR     R0, [R5, #0xE4] \n"
"    B       loc_FF1DEF40 \n"

"loc_FF1DEF38:\n"
"    CMP     R1, #4 \n"
"    BNE     loc_FF1DF058 \n"

"loc_FF1DEF40:\n"
"    LDRH    R0, [R5, #6] \n"
"    CMP     R0, #3 \n"
"    BNE     loc_FF1DEF78 \n"
"    LDR     R0, [R5, #0xC8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x86B \n"
"    LDREQ   R0, =0xFF1DD7A0 /*'MovieRecorder.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    LDR     R0, [R5, #0x6C] \n"
"    LDR     R1, [R5, #0xC8] \n"
"    BL      sub_0069092C /*__divmod_unsigned_int*/ \n"
"    CMP     R1, #0 \n"
"    MOVNE   R7, #0 \n"
"    BNE     loc_FF1DEF94 \n"

"loc_FF1DEF78:\n"
"    ADD     R3, SP, #0x30 \n"
"    ADD     R2, SP, #0x34 \n"
"    ADD     R1, SP, #0x38 \n"
"    ADD     R0, SP, #0x3C \n"
"    BL      sub_FF386938 \n"
"    MOVS    R8, R0 \n"
"    BNE     loc_FF1DEFB0 \n"

"loc_FF1DEF94:\n"
"    LDR     R0, [R5, #0x34] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF1DF060 \n"
"    LDR     R0, [R5, #0x6C] \n"
"    LDR     R1, [R5, #0x48] \n"
"    CMP     R0, R1 \n"
"    BCC     loc_FF1DF060 \n"

"loc_FF1DEFB0:\n"
"    MOV     R0, R8 \n"
"    BL      sub_FF1DE390 \n"
"    BL      sub_FF1DFEAC \n"
"    LDR     R2, [R5, #0x64] \n"
"    ADD     R3, SP, #0x40 \n"
"    MVN     R1, #1 \n"
"    MOV     R0, #0 \n"
"    ADD     R7, SP, #0x1C \n"
"    STMIA   R7, {R0-R3} \n"
"    LDR     R3, [R4, #0x1C] \n"
"    LDR     R1, [R5, #0x74] \n"
"    LDR     R2, [R5, #0x78] \n"
"    ADD     R0, SP, #0x44 \n"
"    ADD     R4, SP, #0xC \n"
"    STMIA   R4, {R0-R3} \n"
"    MOV     R3, #0 \n"
"    MOV     R1, #0x40 \n"
"    STMEA   SP, {R1,R3} \n"
"    MOV     R2, #0 \n"
"    STR     R3, [SP, #8] \n"
"    LDR     R3, =0xDF574 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, R2 \n"
"    BL      sub_FF335784 \n"
"    LDR     R0, [R5, #0x1C] \n"
"    LDR     R1, [R5, #0x60] \n"
"    BL      _TakeSemaphore \n"
"    CMP     R0, #9 \n"
"    BNE     loc_FF1DF02C \n"

"loc_FF1DF024:\n"
"    MOV     R1, #1 \n"
"    B       loc_FF1DF180 \n"

"loc_FF1DF02C:\n"
"    LDR     R0, [SP, #0x40] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF1DF040 \n"

"loc_FF1DF038:\n"
"    MOV     R1, #1 \n"
"    B       loc_FF1DF198 \n"

"loc_FF1DF040:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF335830 \n"
"    BL      sub_FF3358DC \n"
"    MOV     R0, #5 \n"
"    STR     R6, [R5, #0x34]! \n"
"    STR     R0, [R5, #0x10] \n"

"loc_FF1DF058:\n"
"    ADD     SP, SP, #0x48 \n"
"    LDMFD   SP!, {R4-R8,PC} \n"

"loc_FF1DF060:\n"
"    CMP     R7, #1 \n"
"    BNE     loc_FF1DF224 \n"
"    MOV     R0, #1 \n"
"    STR     R0, [R5, #0x38] \n"
"    LDR     R0, [R5, #0x6C] \n"
"    LDR     R8, [R4, #0xC] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R7, [SP, #0x38] \n"
"    LDRNE   R12, [SP, #0x3C] \n"
"    BNE     loc_FF1DF118 \n"
"    LDR     R0, [R4, #0x20] \n"
"    LDR     R2, [R5, #0x64] \n"
"    ADD     R3, SP, #0x40 \n"
"    MVN     R1, #0 \n"
"    ADD     R7, SP, #0x1C \n"
"    STMIA   R7, {R0-R3} \n"
"    LDR     R3, [R4, #0x1C] \n"
"    LDR     R1, [R5, #0x74] \n"
"    LDR     R2, [R5, #0x78] \n"
"    ADD     R0, SP, #0x44 \n"
"    ADD     R7, SP, #0xC \n"
"    STMIA   R7, {R0-R3} \n"
"    LDR     R1, [SP, #0x34] \n"
"    LDR     R2, [SP, #0x38] \n"
"    LDR     R3, [SP, #0x30] \n"
"    STMFA   SP, {R1,R3} \n"
"    STR     R2, [SP] \n"
"    LDMIB   R4, {R0,R1} \n"
"    LDR     R3, [SP, #0x3C] \n"
"    MOV     R2, R8 \n"
"    BL      sub_FF335784 \n"
"    LDR     R0, [R5, #0x1C] \n"
"    LDR     R1, [R5, #0x60] \n"
"    BL      _TakeSemaphore \n"
"    CMP     R0, #9 \n"
"    BEQ     loc_FF1DF024 \n"
"    LDR     R0, [SP, #0x40] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF1DF038 \n"
"    MOV     R0, #1 \n"
"    BL      sub_FF335830 \n"
"    LDR     R0, [SP, #0x44] \n"
"    LDR     R1, [SP, #0x3C] \n"
"    ADD     R12, R1, R0 \n"
"    LDR     R1, [SP, #0x38] \n"
"    SUB     R7, R1, R0 \n"

"loc_FF1DF118:\n"
"    LDR     R0, [R4, #0x20] \n"
"    LDR     R1, [R5, #0x68] \n"
"    LDR     R2, [R5, #0x64] \n"
"    ADD     R3, SP, #0x40 \n"
"    ADD     LR, SP, #0x1C \n"
"    STMIA   LR, {R0-R3} \n"
"    LDR     R3, [R4, #0x1C] \n"
"    LDR     R1, [R5, #0x74] \n"
"    LDR     R2, [R5, #0x78] \n"
"    ADD     R0, SP, #0x44 \n"
"    ADD     LR, SP, #0xC \n"
"    STMIA   LR, {R0-R3} \n"
"    LDR     R2, [SP, #0x34] \n"
"    LDR     R3, [SP, #0x30] \n"
"    STMFA   SP, {R2,R3} \n"
"    STR     R7, [SP] \n"
"    LDMIB   R4, {R0,R1} \n"
"    MOV     R3, R12 \n"
"    MOV     R2, R8 \n"
"    BL      sub_FF335784 \n"
"    LDR     R0, [R5, #0x1C] \n"
"    LDR     R1, [R5, #0x60] \n"
"    BL      _TakeSemaphore \n"
"    CMP     R0, #9 \n"
"    BNE     loc_FF1DF188 \n"
"    MOV     R1, #0 \n"

"loc_FF1DF180:\n"
"    MOV     R0, #0x90000 \n"
"    B       loc_FF1DF19C \n"

"loc_FF1DF188:\n"
"    LDR     R0, [SP, #0x40] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF1DF1A4 \n"
"    MOV     R1, #0 \n"

"loc_FF1DF198:\n"
"    MOV     R0, #0xA0000 \n"

"loc_FF1DF19C:\n"
"    BL      sub_FF1DE784 \n"
"    B       loc_FF1DF058 \n"

"loc_FF1DF1A4:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF335830 \n"
"    LDR     R0, [SP, #0x3C] \n"
"    LDR     R1, [SP, #0x44] \n"
"    BL      sub_FF386BB0 \n"
"    LDR     R0, [R5, #0x68] \n"
"    LDR     R3, =0x9480 \n"
"    ADD     R1, R0, #1 \n"
"    STR     R1, [R5, #0x68] \n"
"    LDR     R0, [SP, #0x44] \n"
"    SUB     R2, R3, #4 \n"
"    BL      sub_FF38191C \n"
//begin patch
"    LDR     R0, =video_compression_rate\n" //added
"    BL      set_quality\n"                 //added
//end patch
"    LDR     R0, [R5, #0x64] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF1DF230 \n"
"    ADD     R0, SP, #0x2C \n"
"    BL      sub_FF18F680 \n"
"    LDR     R1, =0xDF4E4 \n"
"    LDR     R0, [R1, #4] \n"
"    LDR     R1, [R1] \n"
"    SUB     R2, R0, #0x400 \n"
"    SUBS    R2, R2, #0x38 \n"
"    ADDEQ   R0, R0, #8 \n"
"    MOV     R1, R1, LSR#4 \n"
"    MOV     R0, R0, LSR#4 \n"
"    MUL     R1, R0, R1 \n"
"    LDR     R0, [SP, #0x2C] \n"
"    BL      sub_0069092C /*__divmod_unsigned_int*/ \n"
"    LDR     R1, =0xDF514 \n"
"    STR     R0, [SP, #0x2C] \n"
"    BL      sub_FF381C58 \n"
"    B       loc_FF1DF230 \n"

"loc_FF1DF224:\n"
"    LDRH    R0, [R5, #6] \n"
"    CMP     R0, #3 \n"
"    BNE     loc_FF1DF058 \n"

"loc_FF1DF230:\n"
"    LDR     R0, [R5, #0x6C] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R5, #0x6C] \n"
"    LDRH    R1, [R5, #6] \n"
"    CMP     R1, #3 \n"
"    LDRNE   R1, [R5, #0x54] \n"
"    MULNE   R0, R1, R0 \n"
"    LDRNE   R1, [R5, #0x50] \n"
"    BNE     loc_FF1DF270 \n"
"    LDR     R1, [R5, #0x58] \n"
"    CMP     R1, #0x19 \n"
"    LDRNE   R1, =0x3E9 \n"
"    MOVEQ   R1, #0x3E8 \n"
"    MUL     R0, R1, R0 \n"
"    LDRNE   R1, =0x1770 \n"
"    LDREQ   R1, =0x1388 \n"

"loc_FF1DF270:\n"
"    BL      sub_0069092C /*__divmod_unsigned_int*/ \n"
"    MOV     R4, R0 \n"
"    BL      sub_FF38726C \n"
"    LDR     R0, [R5, #0x7C] \n"
"    CMP     R0, R4 \n"
"    BNE     loc_FF1DF294 \n"
"    LDR     R0, [R5, #0x3C] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF1DF2A8 \n"

"loc_FF1DF294:\n"
"    LDR     R1, [R5, #0xA8] \n"
"    MOV     R0, R4 \n"
"    BLX     R1 \n"
"    STR     R4, [R5, #0x7C] \n"
"    STR     R6, [R5, #0x3C] \n"

"loc_FF1DF2A8:\n"
"    STR     R6, [R5, #0x38] \n"
"    B       loc_FF1DF058 \n"
);
}
