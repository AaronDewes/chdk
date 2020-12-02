/*
 * movie_rec.c - auto-generated by CHDK code_gen.
 */
#include "conf.h"

void change_video_tables(__attribute__ ((unused))int a, __attribute__ ((unused))int b) {}

void  set_quality(int *x){ // -17 highest; +12 lowest
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

/*************************************************************/
//** movie_record_task @ 0xF8235E0C - 0xF8235FD0, length=114
void __attribute__((naked,noinline)) movie_record_task() {
asm volatile (
"    STMFD   SP!, {R2-R10,LR} \n"
"    LDR     R8, =sub_F8235A3C_my \n"  // --> Patched. Old value = 0xF8235A3C.
"    LDR     R4, =0x9C78 \n"
"    LDR     R9, =0x65B \n"
"    LDR     R10, =0x2710 \n"
"    MVN     R7, #0 \n"
"    MOV     R5, #1 \n"
"    MOV     R6, #0 \n"

"loc_F8235E2C:\n"
"    LDR     R0, [R4, #0x28] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_0068F164 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [R4, #0x30] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, [R4, #0x10] \n"
"    CMPNE   R0, #2 \n"
"    LDRNE   R0, [R4, #0x44] \n"
"    CMPNE   R0, #6 \n"
"    BNE     loc_F8235FB4 \n"
"    LDR     R0, [SP, #4] \n"
"    LDR     R1, [R0] \n"
"    SUB     R1, R1, #2 \n"
"    CMP     R1, #0xF \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_F8235FB4 \n"
"    B       loc_F8235EFC \n"
"    B       loc_F8235F20 \n"
"    B       loc_F8235F30 \n"
"    B       loc_F8235F38 \n"
"    B       loc_F8235F40 \n"
"    B       loc_F8235F48 \n"
"    B       loc_F8235F04 \n"
"    B       loc_F8235F74 \n"
"    B       loc_F8235FA0 \n"
"    B       loc_F8235FA8 \n"
"    B       loc_F8235F10 \n"
"    B       loc_F8235FB4 \n"
"    B       loc_F8235FB0 \n"
"    B       loc_F8235ED8 \n"
"    B       loc_F8235EAC \n"

"loc_F8235EAC:\n"
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
"    B       loc_F8235EF4 \n"

"loc_F8235ED8:\n"
"    STR     R6, [R4, #0x40] \n"
"    STR     R7, [R4, #0xE4] \n"
"    STR     R8, [R4, #0xCC] \n"
"    LDR     R0, [R4, #0x10] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0x10] \n"
"    STR     R5, [R4, #0x44] \n"

"loc_F8235EF4:\n"
"    STR     R5, [R4, #8] \n"
"    B       loc_F8235FB4 \n"

"loc_F8235EFC:\n"
);
if (conf.ext_video_time == 1)
{
asm volatile (
"    BL      sub_F82356A0_my \n"  // --> Patched. Old value = 0xF82356A0.
);
}
else
{
asm volatile (
"    BL      sub_F82356A0 \n"
);
}
asm volatile (
"    B       loc_F8235FB4 \n"

"loc_F8235F04:\n"
"    LDR     R1, [R4, #0xCC] \n"
"    BLX     R1 \n"
//begin patch
"    LDR     R0, =video_compression_rate\n" //added
"    BL      set_quality\n"                 //added
//end patch
"    B       loc_F8235FB4 \n"

"loc_F8235F10:\n"
"    LDR     R1, [R0, #0x18] \n"
"    LDR     R0, [R0, #4] \n"
"    BL      sub_F8432BC4 \n"
"    B       loc_F8235FB4 \n"

"loc_F8235F20:\n"
"    LDR     R0, [R4, #0x44] \n"
"    CMP     R0, #5 \n"
"    STRNE   R5, [R4, #0x34] \n"
"    B       loc_F8235FB4 \n"

"loc_F8235F30:\n"
"    BL      sub_F8234BF8 \n"
"    B       loc_F8235FB4 \n"

"loc_F8235F38:\n"
"    BL      sub_F8234AE0 \n"
"    B       loc_F8235FB4 \n"

"loc_F8235F40:\n"
"    BL      sub_F8234798 \n"
"    B       loc_F8235FB4 \n"

"loc_F8235F48:\n"
"    LDR     R1, [R4, #0x94] \n"
"    LDR     R0, =0x4840F640 \n"
"    CMP     R1, #0 \n"
"    LDREQ   R1, =0xF823475C \n"
"    LDREQ   R0, [R4, #0x98] \n"
"    BEQ     loc_F8235F6C \n"
"    BL      sub_F8433880 \n"
"    LDR     R1, =0xF823475C \n"
"    MOV     R0, #0 \n"

"loc_F8235F6C:\n"
"    BL      sub_F8431D24 \n"
"    B       loc_F8235FB4 \n"

"loc_F8235F74:\n"
"    LDR     R0, =0x141774 \n"
"    LDR     R0, [R0, #8] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0xF82346E4 \n"
"    LDRNE   R0, =0xF8234738 \n"
"    MOVNE   R3, #0 \n"
"    MOVNE   R1, R3 \n"
"    BLNE    sub_F807E8E4 \n"
"    MOV     R0, #3 \n"
"    STR     R0, [R4, #0x44] \n"
"    B       loc_F8235FB4 \n"

"loc_F8235FA0:\n"
"    BL      sub_F8234664 \n"
"    B       loc_F8235FB4 \n"

"loc_F8235FA8:\n"
"    BL      sub_F8236A08 \n"
"    B       loc_F8235FB4 \n"

"loc_F8235FB0:\n"
"    BL      sub_F8236928 \n"

"loc_F8235FB4:\n"
"    LDR     R1, [SP, #4] \n"
"    LDR     R3, =0xF82342FC /*'MovieRecorder.c'*/ \n"
"    STR     R6, [R1] \n"
"    STR     R9, [SP] \n"
"    LDR     R0, [R4, #0x2C] \n"
"    MOV     R2, R10 \n"
"    BL      sub_0068B044 /*_PostMessageQueueStrictly*/ \n"
"    B       loc_F8235E2C \n"
);
}

/*************************************************************/
//** sub_F82356A0_my @ 0xF82356A0 - 0xF82359D0, length=205
void __attribute__((naked,noinline)) sub_F82356A0_my() {
asm volatile (
"    STMFD   SP!, {R0-R10,LR} \n"
"    LDR     R6, =0x9C78 \n"
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
"    BNE     loc_F82356E8 \n"
"    LDR     R1, [R6, #0x80] \n"
"    CMP     R1, #0 \n"
"    BNE     loc_F82356F8 \n"
"    B       loc_F82356F0 \n"

"loc_F82356E8:\n"
"    CMP     R1, #3 \n"
"    BNE     loc_F82356F8 \n"

"loc_F82356F0:\n"
"    STR     R2, [R6, #0x48] \n"
"    B       loc_F8235704 \n"

"loc_F82356F8:\n"
"    MOV     R1, #0x3E8 \n"
"    BL      sub_006ACF94 \n"
"    STR     R0, [R6, #0x48] \n"

"loc_F8235704:\n"
"    LDR     R5, =0x141774 \n"
"    MOV     R7, #2 \n"
"    LDR     R0, [R5, #8] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_F8235770 \n"
"    CMP     R4, #0x18 \n"
"    MOV     R0, #4 \n"
"    BEQ     loc_F823575C \n"
"    BGT     loc_F8235744 \n"
"    CMP     R4, #0xA \n"
"    CMPNE   R4, #0xF \n"
"    STREQ   R7, [R5, #0x14] \n"
"    BEQ     loc_F8235770 \n"
"    CMP     R4, #0x14 \n"
"    BNE     loc_F8235764 \n"
"    B       loc_F823575C \n"

"loc_F8235744:\n"
"    CMP     R4, #0x19 \n"
"    CMPNE   R4, #0x1E \n"
"    BEQ     loc_F823575C \n"
"    CMP     R4, #0x3C \n"
"    BNE     loc_F8235764 \n"
"    MOV     R0, #8 \n"

"loc_F823575C:\n"
"    STR     R0, [R5, #0x14] \n"
"    B       loc_F8235770 \n"

"loc_F8235764:\n"
"    LDR     R1, =0x74C \n"
"    LDR     R0, =0xF82342FC /*'MovieRecorder.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_F8235770:\n"
"    LDR     R0, [R6, #0x64] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_F8235788 \n"
"    BL      sub_F83DC768 \n"
"    LDR     R0, =0x14178C \n"
"    BL      sub_F842E04C \n"

"loc_F8235788:\n"
"    LDR     R2, =0x9C7A \n"
"    LDR     R0, [R6, #0xA4] \n"
"    MOV     R3, #2 \n"
"    MOV     R1, #0xAA \n"
"    BL      sub_F80D7178 \n"
"    LDR     R2, =0x9C7C \n"
"    LDR     R0, [R6, #0xA4] \n"
"    MOV     R3, #2 \n"
"    MOV     R1, #0xA9 \n"
"    BL      sub_F80D7178 \n"
"    LDR     R2, =0x9CC8 \n"
"    LDR     R0, [R6, #0xA4] \n"
"    MOV     R3, #4 \n"
"    MOV     R1, #0xA2 \n"
"    BL      sub_F80D7178 \n"
"    LDR     R2, =0x9CCC \n"
"    LDR     R0, [R6, #0xA4] \n"
"    MOV     R3, #4 \n"
"    MOV     R1, #0xA3 \n"
"    BL      sub_F80D7178 \n"
"    LDR     R0, [R6, #0x80] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0x9D70 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, #0xF \n"
"    BLNE    _exmem_ualloc \n"
"    LDR     R0, [R6, #0x4C] \n"
"    LDR     R4, =0x9D70 \n"
"    LDR     R9, =0x14175C \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #2 \n"
"    BNE     loc_F82358BC \n"
"    LDR     R0, [R6, #0x80] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, =0x483FC000 \n"
"    STRNE   R0, [R4] \n"
"    BNE     loc_F82358BC \n"
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
"    BCC     loc_F8235884 \n"
"    MOV     R2, #0 \n"
"    STMEA   SP, {R1,R2,R8} \n"
"    MOV     R3, R2 \n"
"    MOV     R2, #9 \n"
"    MOV     R1, #5 \n"
"    MOV     R0, #0x16 \n"
"    BL      sub_F83D5108 \n"
"    LDR     R0, [R6, #0x8C] \n"
"    MOV     R2, #0 \n"
"    SUB     R3, R0, #0xF0000 \n"
"    LDR     R0, [R6, #0x90] \n"
"    SUB     R3, R3, #0xFF00 \n"
"    ADD     R1, R0, #0xF0000 \n"
"    ADD     R1, R1, #0xFF00 \n"

"loc_F8235884:\n"
"    STMEA   SP, {R1-R3} \n"
"    MOV     R3, #0 \n"
"    MOV     R2, #9 \n"
"    MOV     R1, #5 \n"
"    MOV     R0, #0x16 \n"
"    BL      sub_F83D5108 \n"
"    LDR     R1, [R4] \n"
"    LDR     R0, [R6, #0x8C] \n"
"    ADD     R1, R1, R0, LSL#1 \n"
"    STR     R1, [R4] \n"
"    LDR     R1, [R4, #4] \n"
"    RSB     R0, R0, #0 \n"
"    ADD     R0, R1, R0, LSL#1 \n"
"    STR     R0, [R4, #4] \n"

"loc_F82358BC:\n"
"    LDR     R2, =0x141774 \n"
"    LDR     R3, =0xF823566C \n"
"    LDR     R0, [R4, #4] \n"
"    LDR     R1, [R4] \n"
"    STRD    R2, [SP] \n"
"    SUB     R3, R2, #0x18 \n"
"    MOV     R2, R0 \n"
"    LDR     R0, [R6, #0x80] \n"
"    BL      sub_F84310D4_my \n"  // --> Patched. Old value = 0xF84310D4.
"    LDRD    R0, [R6, #0xF0] \n"
"    LDR     R2, [R6, #0xA4] \n"
"    BL      sub_F843170C \n"
"    LDR     R3, =0x9CF0 \n"
"    STR     R3, [SP] \n"
"    LDR     R0, [R6, #0x64] \n"
"    LDR     R1, [R9, #8] \n"
"    AND     R2, R0, #0xFF \n"
"    LDR     R0, [R9] \n"
"    SUB     R3, R3, #4 \n"
"    BL      sub_F842DBA8 \n"
"    LDRH    R0, [R6, #6] \n"
"    CMP     R0, #2 \n"
"    LDREQ   R0, =0xF823536C \n"
"    STREQ   R0, [R6, #0xCC] \n"
"    LDR     R0, [R6, #0x80] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0xF8234F28 \n"
"    STREQ   R1, [R6, #0xCC] \n"
"    LDR     R2, [R6, #0x10] \n"
"    LDR     R1, =0xF87C29F4 \n"
"    CMP     R2, #2 \n"
"    BNE     loc_F8235960 \n"
"    LDR     R0, [R6, #0x4C] \n"
"    ADD     R0, R1, R0, LSL#3 \n"
"    LDR     R1, [R9, #0xC] \n"
"    LDR     R0, [R0, R1, LSL#2] \n"
"    BL      sub_F83DB4F4 \n"
"    LDR     R0, =0xF8234EE0 \n"
"    MOV     R1, #0 \n"
"    BL      sub_F83DBA80 \n"
"    B       loc_F8235998 \n"

"loc_F8235960:\n"
"    CMP     R0, #0 \n"
"    LDR     R0, [R6, #0x4C] \n"
"    ADD     R0, R1, R0, LSL#3 \n"
"    LDR     R1, [R9, #0xC] \n"
"    LDR     R0, [R0, R1, LSL#2] \n"
"    BNE     loc_F8235988 \n"
"    LDR     R1, [R6, #0x88] \n"
"    BL      sub_F83DBB60 \n"
"    BL      sub_F83DBBE4 \n"
"    B       loc_F8235998 \n"

"loc_F8235988:\n"
"    BL      sub_F83D96E0 \n"
"    LDR     R0, =0xF8234ED4 \n"
"    MOV     R1, #0 \n"
"    BL      sub_F83D9EF0 \n"

"loc_F8235998:\n"
"    LDR     R0, [R5, #8] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_F82359CC \n"
"    ADD     R0, SP, #0xC \n"
"    BL      sub_F843292C \n"
"    LDR     R1, [R5, #0xC] \n"
"    LDR     R0, [SP, #0xC] \n"
"    BL      sub_F807EB50 \n"
"    ADD     R0, SP, #0xC \n"
"    BL      sub_F843292C \n"
"    LDR     R1, [R5, #0xC] \n"
"    LDR     R0, [SP, #0xC] \n"
"    BL      sub_F807EB50 \n"

"loc_F82359CC:\n"
"    STR     R7, [R6, #0x44] \n"
"    LDMFD   SP!, {R0-R10,PC} \n"
);
}

/*************************************************************/
//** sub_F84310D4_my @ 0xF84310D4 - 0xF8431440, length=220
void __attribute__((naked,noinline)) sub_F84310D4_my() {
asm volatile (
"    STMFD   SP!, {R0-R11,LR} \n"
"    MOV     R9, R0 \n"
"    LDR     R0, [R3, #0x10] \n"
"    SUB     SP, SP, #4 \n"
"    CMP     R0, #0 \n"
"    LDR     R7, [SP, #0x38] \n"
"    LDREQ   R1, =0x3B7 \n"
"    LDREQ   R0, =0xF842E6B8 /*'MovWriter.c'*/ \n"
"    MOV     R6, #0 \n"
"    MOV     R4, R3 \n"
"    MOV     R5, R6 \n"
"    BLEQ    _DebugAssert \n"
"    LDR     R8, =0x13220 \n"
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
"    B       loc_F843122C \n"
"    B       loc_F84311B4 \n"
"    B       loc_F84311AC \n"
"    B       loc_F843119C \n"
"    B       loc_F8431208 \n"
"    B       loc_F8431218 \n"
"    B       loc_F843122C \n"
"    B       loc_F843122C \n"
"    B       loc_F843122C \n"
"    B       loc_F843122C \n"
"    B       loc_F84311D4 \n"
"    B       loc_F84311CC \n"
"    B       loc_F84311C4 \n"
"    B       loc_F8431200 \n"
"    B       loc_F84311F8 \n"
"    B       loc_F84311E4 \n"

"loc_F843119C:\n"
"    LDR     R5, =0x5DC0 \n"
"    STR     R2, [R8, #0xF8] \n"
"    STR     R5, [R8, #0x154] \n"
"    B       loc_F84311BC \n"

"loc_F84311AC:\n"
"    MOV     R5, R3 \n"
"    B       loc_F84311E8 \n"

"loc_F84311B4:\n"
"    MOV     R5, R1 \n"
"    B       loc_F84311D8 \n"

"loc_F84311BC:\n"
"    STR     R0, [R8, #0x158] \n"
"    B       loc_F8431238 \n"

"loc_F84311C4:\n"
"    LDR     R5, =0x5DC \n"
"    B       loc_F84311D8 \n"

"loc_F84311CC:\n"
"    LDR     R5, =0xBB8 \n"
"    B       loc_F84311D8 \n"

"loc_F84311D4:\n"
"    LDR     R5, =0x1770 \n"

"loc_F84311D8:\n"
"    STR     R1, [R8, #0x154] \n"
"    STR     R10, [R8, #0xF8] \n"
"    B       loc_F84311BC \n"

"loc_F84311E4:\n"
"    LDR     R5, =0x4E2 \n"

"loc_F84311E8:\n"
"    STR     R2, [R8, #0xF8] \n"
"    STR     R3, [R8, #0x154] \n"
"    STR     R12, [R8, #0x158] \n"
"    B       loc_F8431238 \n"

"loc_F84311F8:\n"
"    LDR     R5, =0x9C4 \n"
"    B       loc_F84311E8 \n"

"loc_F8431200:\n"
"    LDR     R5, =0x1388 \n"
"    B       loc_F84311E8 \n"

"loc_F8431208:\n"
"    STR     R1, [R8, #0x154] \n"
"    LDR     R5, =0x57600000 \n"  // --> Patched. Old value = 0x3A980. 2hrs
"    MOV     R1, #0xF0 \n"
"    B       loc_F8431224 \n"

"loc_F8431218:\n"
"    LDR     R5, =0x28800000 \n"  // --> Patched. Old value = 0x1D4C0. 2hrs
"    STR     R1, [R8, #0x154] \n"
"    MOV     R1, #0x78 \n"

"loc_F8431224:\n"
"    STR     R1, [R8, #0xF8] \n"
"    B       loc_F84311BC \n"

"loc_F843122C:\n"
"    LDR     R1, =0x411 \n"
"    LDR     R0, =0xF842E6B8 /*'MovWriter.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_F8431238:\n"
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
"    BEQ     loc_F84312D0 \n"
"    CMP     R0, #0x280 \n"
"    LDREQ   R0, =0x7A760 \n"
"    MOVEQ   R6, #2 \n"
"    STREQ   R0, [R8, #0xC4] \n"
"    BEQ     loc_F84312D0 \n"
"    CMP     R0, #0x500 \n"
"    LDREQ   R0, =0x11DA50 \n"
"    LDR     R1, =0x1C20 \n"  // --> Patched. Old value = 0x707. 2hrs
"    MOVEQ   R6, #4 \n"
"    STREQ   R0, [R8, #0xC4] \n"
"    BEQ     loc_F84312D0 \n"
"    CMP     R0, #0x780 \n"
"    BNE     loc_F84312D8 \n"
//"  MOV     R0, #0x200000 \n"
"    MOV     R0, #2097152 \n" // 10 mins
"    MOV     R6, #5 \n"
"    STR     R0, [R8, #0xC4] \n"

"loc_F84312D0:\n"
"    STR     R1, [R8, #0x58] \n"
"    B       loc_F84312E4 \n"

"loc_F84312D8:\n"
"    LDR     R1, =0x439 \n"
"    LDR     R0, =0xF842E6B8 /*'MovWriter.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_F84312E4:\n"
"    LDR     R9, [R4, #8] \n"
"    CMP     R9, #0xB \n"
"    CMPNE   R9, #0xA \n"
"    CMPNE   R9, #9 \n"
"    BNE     loc_F8431318 \n"
"    LDR     R0, [R8, #0xF0] \n"
"    CMP     R0, #0x500 \n"
"    BNE     loc_F8431318 \n"
"    LDR     R0, [R8, #0x58] \n"
"    LDR     R1, [R8, #0x158] \n"
"    MUL     R0, R5, R0 \n"
"    BL      sub_006ACF94 \n"
"    B       loc_F8431338 \n"

"loc_F8431318:\n"
"    LDR     R0, [R8, #0x58] \n"
"    LDR     R1, [R8, #0x158] \n"
"    MUL     R0, R5, R0 \n"
"    BL      sub_006ACF94 \n"
"    MOV     R1, #5 \n"
"    BL      sub_006ACF94 \n"
"    ADD     R0, R0, #1 \n"
"    ADD     R0, R0, R0, LSL#2 \n"

"loc_F8431338:\n"
"    CMP     R9, #0xB \n"
"    CMPNE   R9, #0xA \n"
"    CMPNE   R9, #9 \n"
"    STR     R0, [R8, #0x54] \n"
"    BNE     loc_F8431360 \n"
"    LDR     R1, [R8, #0x158] \n"
"    MUL     R0, R1, R0 \n"
"    MOV     R1, R5 \n"
"    BL      sub_006ACF94 \n"
"    STR     R0, [R8, #0x58] \n"

"loc_F8431360:\n"
"    CMP     R9, #3 \n"
"    CMPNE   R9, #4 \n"
"    BNE     loc_F8431398 \n"
"    RSB     R0, R5, R5, LSL#4 \n"
"    STR     R10, [R8, #0x58] \n"
"    LDR     R1, [R8, #0x158] \n"
"    MOV     R0, R0, LSL#1 \n"
"    BL      sub_006ACF94 \n"
"    LDR     R1, [R8, #0x100] \n"
"    MOV     R10, R1 \n"
"    BL      sub_006ACF94 \n"
"    ADD     R0, R0, #1 \n"
"    MUL     R0, R10, R0 \n"
"    STR     R0, [R8, #0x54] \n"

"loc_F8431398:\n"
"    ADD     R0, R5, R5, LSL#8 \n"
"    LDR     R1, [R8, #0x158] \n"
"    RSB     R0, R0, R0, LSL#3 \n"
"    BL      sub_006ACF94 \n"
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
"    BEQ     sub_F8431664 \n"
"    ADD     R9, R1, R0 \n"
"    STR     R9, [R8, #0x11C] \n"
"    LDR     R1, [R8, #0xFC] \n"
"    BL      sub_006ACF94 \n"
"    ADD     R0, R0, R9 \n"
"    ADD     R0, R0, #0x1F \n"
"    BIC     R0, R0, #0x1F \n"
"    STR     R0, [R8, #0x120] \n"
"    LDR     R1, [R8, #0xE8] \n"
"    CMP     R1, #0 \n"
"    BEQ     sub_F84314F8 \n"
"    LDR     R2, [R8, #0xC4] \n"
"    ADD     R0, R0, R2 \n"
"    STR     R0, [R8, #0x2C] \n"
"    ADD     R0, R0, #0x20 \n"
"    B       sub_F84314C0 \n"
);
}

/*************************************************************/
//** sub_F8235A3C_my @ 0xF8235A3C - 0xF8235E08, length=244
void __attribute__((naked,noinline)) sub_F8235A3C_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    SUB     SP, SP, #0x48 \n"
"    MOV     R8, #0 \n"
"    LDR     R5, =0x9C78 \n"
"    STR     R8, [SP, #0x38] \n"
"    STR     R8, [SP, #0x30] \n"
"    STR     R8, [R5, #0xC4] \n"
"    LDR     R1, [R5, #0x44] \n"
"    MOV     R4, R0 \n"
"    CMP     R1, #3 \n"
"    MOV     R6, R8 \n"
"    MOV     R7, #1 \n"
"    BNE     loc_F8235A94 \n"
"    LDR     R0, [R5, #0xE4] \n"
"    LDR     R1, [R5, #0xE8] \n"
"    CMP     R0, R1 \n"
"    BNE     loc_F8235BB4 \n"
"    MOV     R0, #4 \n"
"    STR     R0, [R5, #0x44] \n"
"    MVN     R0, #0 \n"
"    STR     R0, [R5, #0xE4] \n"
"    B       loc_F8235A9C \n"

"loc_F8235A94:\n"
"    CMP     R1, #4 \n"
"    BNE     loc_F8235BB4 \n"

"loc_F8235A9C:\n"
"    LDRH    R0, [R5, #6] \n"
"    CMP     R0, #3 \n"
"    BNE     loc_F8235AD4 \n"
"    LDR     R0, [R5, #0xC8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x86B \n"
"    LDREQ   R0, =0xF82342FC /*'MovieRecorder.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    LDR     R0, [R5, #0x6C] \n"
"    LDR     R1, [R5, #0xC8] \n"
"    BL      sub_006ACF94 \n"
"    CMP     R1, #0 \n"
"    MOVNE   R7, #0 \n"
"    BNE     loc_F8235AF0 \n"

"loc_F8235AD4:\n"
"    ADD     R3, SP, #0x30 \n"
"    ADD     R2, SP, #0x34 \n"
"    ADD     R1, SP, #0x38 \n"
"    ADD     R0, SP, #0x3C \n"
"    BL      sub_F8432D80 \n"
"    MOVS    R8, R0 \n"
"    BNE     loc_F8235B0C \n"

"loc_F8235AF0:\n"
"    LDR     R0, [R5, #0x34] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_F8235BBC \n"
"    LDR     R0, [R5, #0x6C] \n"
"    LDR     R1, [R5, #0x48] \n"
"    CMP     R0, R1 \n"
"    BCC     loc_F8235BBC \n"

"loc_F8235B0C:\n"
"    MOV     R0, R8 \n"
"    BL      sub_F8234EEC \n"
"    BL      sub_F8236A08 \n"
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
"    LDR     R3, =0x1417EC \n"
"    MOV     R1, R2 \n"
"    MOV     R0, R2 \n"
"    BL      sub_F83D9D74 \n"
"    LDR     R0, [R5, #0x1C] \n"
"    LDR     R1, [R5, #0x60] \n"
"    BL      _TakeSemaphore \n"
"    CMP     R0, #9 \n"
"    BNE     loc_F8235B88 \n"

"loc_F8235B80:\n"
"    MOV     R1, #1 \n"
"    B       loc_F8235CDC \n"

"loc_F8235B88:\n"
"    LDR     R0, [SP, #0x40] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_F8235B9C \n"

"loc_F8235B94:\n"
"    MOV     R1, #1 \n"
"    B       loc_F8235CF4 \n"

"loc_F8235B9C:\n"
"    MOV     R0, #1 \n"
"    BL      sub_F83D9E20 \n"
"    BL      sub_F83D9ECC \n"
"    MOV     R0, #5 \n"
"    STR     R6, [R5, #0x34]! \n"
"    STR     R0, [R5, #0x10] \n"

"loc_F8235BB4:\n"
"    ADD     SP, SP, #0x48 \n"
"    LDMFD   SP!, {R4-R8,PC} \n"

"loc_F8235BBC:\n"
"    CMP     R7, #1 \n"
"    BNE     loc_F8235D80 \n"
"    MOV     R0, #1 \n"
"    STR     R0, [R5, #0x38] \n"
"    LDR     R0, [R5, #0x6C] \n"
"    LDR     R8, [R4, #0xC] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R7, [SP, #0x38] \n"
"    LDRNE   R12, [SP, #0x3C] \n"
"    BNE     loc_F8235C74 \n"
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
"    BL      sub_F83D9D74 \n"
"    LDR     R0, [R5, #0x1C] \n"
"    LDR     R1, [R5, #0x60] \n"
"    BL      _TakeSemaphore \n"
"    CMP     R0, #9 \n"
"    BEQ     loc_F8235B80 \n"
"    LDR     R0, [SP, #0x40] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_F8235B94 \n"
"    MOV     R0, #1 \n"
"    BL      sub_F83D9E20 \n"
"    LDR     R0, [SP, #0x44] \n"
"    LDR     R1, [SP, #0x3C] \n"
"    ADD     R12, R1, R0 \n"
"    LDR     R1, [SP, #0x38] \n"
"    SUB     R7, R1, R0 \n"

"loc_F8235C74:\n"
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
"    BL      sub_F83D9D74 \n"
"    LDR     R0, [R5, #0x1C] \n"
"    LDR     R1, [R5, #0x60] \n"
"    BL      _TakeSemaphore \n"
"    CMP     R0, #9 \n"
"    BNE     loc_F8235CE4 \n"
"    MOV     R1, #0 \n"

"loc_F8235CDC:\n"
"    MOV     R0, #0x90000 \n"
"    B       loc_F8235CF8 \n"

"loc_F8235CE4:\n"
"    LDR     R0, [SP, #0x40] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_F8235D00 \n"
"    MOV     R1, #0 \n"

"loc_F8235CF4:\n"
"    MOV     R0, #0xA0000 \n"

"loc_F8235CF8:\n"
"    BL      sub_F82352E0 \n"
"    B       loc_F8235BB4 \n"

"loc_F8235D00:\n"
"    MOV     R0, #0 \n"
"    BL      sub_F83D9E20 \n"
"    LDR     R0, [SP, #0x3C] \n"
"    LDR     R1, [SP, #0x44] \n"
"    BL      sub_F8432FF8 \n"
"    LDR     R0, [R5, #0x68] \n"
"    LDR     R3, =0x9CF0 \n"
"    ADD     R1, R0, #1 \n"
"    STR     R1, [R5, #0x68] \n"
"    LDR     R0, [SP, #0x44] \n"
"    SUB     R2, R3, #4 \n"
"    BL      sub_F842DD64 \n"
//begin patch
"    LDR     R0, =video_compression_rate\n" //added
"    BL      set_quality\n"                 //added
//end patch
"    LDR     R0, [R5, #0x64] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_F8235D8C \n"
"    ADD     R0, SP, #0x2C \n"
"    BL      sub_F81E5934 \n"
"    LDR     R1, =0x14175C \n"
"    LDR     R0, [R1, #4] \n"
"    LDR     R1, [R1] \n"
"    SUB     R2, R0, #0x400 \n"
"    SUBS    R2, R2, #0x38 \n"
"    ADDEQ   R0, R0, #8 \n"
"    MOV     R1, R1, LSR#4 \n"
"    MOV     R0, R0, LSR#4 \n"
"    MUL     R1, R0, R1 \n"
"    LDR     R0, [SP, #0x2C] \n"
"    BL      sub_006ACF94 \n"
"    LDR     R1, =0x14178C \n"
"    STR     R0, [SP, #0x2C] \n"
"    BL      sub_F842E0A0 \n"
"    B       loc_F8235D8C \n"

"loc_F8235D80:\n"
"    LDRH    R0, [R5, #6] \n"
"    CMP     R0, #3 \n"
"    BNE     loc_F8235BB4 \n"

"loc_F8235D8C:\n"
"    LDR     R0, [R5, #0x6C] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R5, #0x6C] \n"
"    LDRH    R1, [R5, #6] \n"
"    CMP     R1, #3 \n"
"    LDRNE   R1, [R5, #0x54] \n"
"    MULNE   R0, R1, R0 \n"
"    LDRNE   R1, [R5, #0x50] \n"
"    BNE     loc_F8235DCC \n"
"    LDR     R1, [R5, #0x58] \n"
"    CMP     R1, #0x19 \n"
"    LDRNE   R1, =0x3E9 \n"
"    MOVEQ   R1, #0x3E8 \n"
"    MUL     R0, R1, R0 \n"
"    LDRNE   R1, =0x1770 \n"
"    LDREQ   R1, =0x1388 \n"

"loc_F8235DCC:\n"
"    BL      sub_006ACF94 \n"
"    MOV     R4, R0 \n"
"    BL      sub_F84336B4 \n"
"    LDR     R0, [R5, #0x7C] \n"
"    CMP     R0, R4 \n"
"    BNE     loc_F8235DF0 \n"
"    LDR     R0, [R5, #0x3C] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_F8235E04 \n"

"loc_F8235DF0:\n"
"    LDR     R1, [R5, #0xA8] \n"
"    MOV     R0, R4 \n"
"    BLX     R1 \n"
"    STR     R4, [R5, #0x7C] \n"
"    STR     R6, [R5, #0x3C] \n"

"loc_F8235E04:\n"
"    STR     R6, [R5, #0x38] \n"
"    B       loc_F8235BB4 \n"
);
}
