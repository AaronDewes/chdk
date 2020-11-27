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
//** movie_record_task @ 0xFF0813C0 - 0xFF0815C4, length=130
void __attribute__((naked,noinline)) movie_record_task() {
asm volatile (
"    STMFD   SP!, {R2-R12,LR} \n"
"    LDR     R11, =0x619 \n"
"    LDR     R8, =0xFF080EFC \n"
"    LDR     R9, =0xFF080EF8 \n"
"    LDR     R4, =0x38B0 \n"
"    LDR     R10, =0x2710 \n"
"    MVN     R7, #0 \n"
"    MOV     R5, #1 \n"
"    MOV     R6, #0 \n"

"loc_FF0813E4:\n"
"    LDR     R0, [R4, #0x28] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_0068BDE0 /*_ReceiveMessageQueue*/ \n"
"    LDR     R2, =0xFF07E60C /*'MovieRecorder.c'*/ \n"
"    LDR     R0, [R4, #0x118] \n"
"    MOV     R3, R11 \n"
"    MOV     R1, R10 \n"
"    BL      sub_0068AFEC /*_TakeSemaphoreStrictly*/ \n"
"    LDR     R0, [R4, #0x30] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, [R4, #0x10] \n"
"    CMPNE   R0, #2 \n"
"    LDRNE   R0, [R4, #0x44] \n"
"    CMPNE   R0, #6 \n"
"    BNE     loc_FF08159C \n"
"    LDR     R0, [SP, #4] \n"
"    LDR     R1, [R0] \n"
"    SUB     R1, R1, #2 \n"
"    CMP     R1, #0x11 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF08159C \n"
"    B       loc_FF0814D8 \n"
"    B       loc_FF0814F4 \n"
"    B       loc_FF081504 \n"
"    B       loc_FF08150C \n"
"    B       loc_FF081514 \n"
"    B       loc_FF08151C \n"
"    B       loc_FF0814E0 \n"
"    B       loc_FF081548 \n"
"    B       loc_FF081574 \n"
"    B       loc_FF08157C \n"
"    B       loc_FF0814EC \n"
"    B       loc_FF08159C \n"
"    B       loc_FF08158C \n"
"    B       loc_FF081594 \n"
"    B       loc_FF081584 \n"
"    B       loc_FF0814B0 \n"
"    B       loc_FF081480 \n"

"loc_FF081480:\n"
"    STR     R6, [R4, #0x40] \n"
"    STR     R6, [R4, #0x34] \n"
"    STR     R7, [R4, #0x148] \n"
"    STRH    R6, [R4, #6] \n"
"    STR     R8, [R4, #0xCC] \n"
"    STR     R9, [R4, #0xE4] \n"
"    LDR     R0, [R4, #0x10] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0x10] \n"
"    MOV     R0, #6 \n"
"    STR     R0, [R4, #0x44] \n"
"    B       loc_FF0814D0 \n"

"loc_FF0814B0:\n"
"    STR     R6, [R4, #0x40] \n"
"    STR     R7, [R4, #0x148] \n"
"    STR     R8, [R4, #0xCC] \n"
"    STR     R9, [R4, #0xE4] \n"
"    LDR     R0, [R4, #0x10] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0x10] \n"
"    STR     R5, [R4, #0x44] \n"

"loc_FF0814D0:\n"
"    STR     R5, [R4, #8] \n"
"    B       loc_FF08159C \n"

"loc_FF0814D8:\n"
);
if (conf.ext_video_time == 1)
{
asm volatile (
"    BL      sub_FF080B4C_my \n"  // --> Patched. Old value = 0xFF080B4C.
);
}
else
{
asm volatile (
"    BL      sub_FF080B4C \n"
);
}
asm volatile (
"    B       loc_FF08159C \n"

"loc_FF0814E0:\n"
"    LDR     R1, [R4, #0xCC] \n"
"    BLX     R1 \n"
//begin patch
"    LDR     R0, =video_compression_rate\n" //added
"    BL      set_quality\n"                 //added
//end patch
"    B       loc_FF08159C \n"

"loc_FF0814EC:\n"
"    BL      sub_FF082120 \n"
"    B       loc_FF08159C \n"

"loc_FF0814F4:\n"
"    LDR     R0, [R4, #0x44] \n"
"    CMP     R0, #5 \n"
"    STRNE   R5, [R4, #0x34] \n"
"    B       loc_FF08159C \n"

"loc_FF081504:\n"
"    BL      sub_FF080178 \n"
"    B       loc_FF08159C \n"

"loc_FF08150C:\n"
"    BL      sub_FF080060 \n"
"    B       loc_FF08159C \n"

"loc_FF081514:\n"
"    BL      sub_FF07FD44 \n"
"    B       loc_FF08159C \n"

"loc_FF08151C:\n"
"    LDR     R1, [R4, #0x94] \n"
"    LDR     R0, =0x4840F640 \n"
"    CMP     R1, #0 \n"
"    LDREQ   R1, =0xFF07FD08 \n"
"    LDREQ   R0, [R4, #0x98] \n"
"    BEQ     loc_FF081540 \n"
"    BL      sub_FF1EF8E0 \n"
"    LDR     R1, =0xFF07FD08 \n"
"    MOV     R0, #0 \n"

"loc_FF081540:\n"
"    BL      sub_FF1EDD5C \n"
"    B       loc_FF08159C \n"

"loc_FF081548:\n"
"    LDR     R0, =0x43964 \n"
"    LDR     R0, [R0, #8] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0xFF07FC60 \n"
"    LDRNE   R0, =0xFF07FCE4 \n"
"    MOVNE   R3, #0 \n"
"    MOVNE   R1, R3 \n"
"    BLNE    sub_FF060640 \n"
"    MOV     R0, #3 \n"
"    STR     R0, [R4, #0x44] \n"
"    B       loc_FF08159C \n"

"loc_FF081574:\n"
"    BL      sub_FF07ED64 \n"
"    B       loc_FF08159C \n"

"loc_FF08157C:\n"
"    BL      sub_FF08202C \n"
"    B       loc_FF08159C \n"

"loc_FF081584:\n"
"    BL      sub_FF082040 \n"
"    B       loc_FF08159C \n"

"loc_FF08158C:\n"
"    BL      sub_FF07FA5C \n"
"    B       loc_FF08159C \n"

"loc_FF081594:\n"
"    BL      sub_FF07F8DC \n"
"    STR     R5, [R4, #0x144] \n"

"loc_FF08159C:\n"
"    LDR     R1, [SP, #4] \n"
"    LDR     R3, =0x65B \n"
"    STR     R6, [R1] \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =0xFF07E60C /*'MovieRecorder.c'*/ \n"
"    LDR     R0, [R4, #0x2C] \n"
"    MOV     R2, R10 \n"
"    BL      sub_0068B044 /*_PostMessageQueueStrictly*/ \n"
"    LDR     R0, [R4, #0x118] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FF0813E4 \n"
);
}

/*************************************************************/
//** sub_FF080B4C_my @ 0xFF080B4C - 0xFF080EF4, length=235
void __attribute__((naked,noinline)) sub_FF080B4C_my() {
asm volatile (
"    STMFD   SP!, {R0-R10,LR} \n"
"    LDR     R6, =0x38B0 \n"
"    MOV     R9, #0 \n"
"    STR     R9, [R6, #0x34] \n"
"    STR     R9, [R6, #0x38] \n"
"    MOV     R0, R6 \n"
"    LDR     R4, [R0, #0x58] \n"
"    LDRH    R1, [R6, #6] \n"
"    MOV     R0, #0x3E8 \n"
"    MUL     R0, R4, R0 \n"
"    LDR     R8, =0xFFF00 \n"
"    CMP     R1, #0 \n"
"    MOV     R2, #1 \n"
"    BNE     loc_FF080B94 \n"
"    LDR     R1, [R6, #0x80] \n"
"    CMP     R1, #0 \n"
"    BNE     loc_FF080BA4 \n"
"    B       loc_FF080B9C \n"

"loc_FF080B94:\n"
"    CMP     R1, #3 \n"
"    BNE     loc_FF080BA4 \n"

"loc_FF080B9C:\n"
"    STR     R2, [R6, #0x48] \n"
"    B       loc_FF080BB0 \n"

"loc_FF080BA4:\n"
"    MOV     R1, #0x3E8 \n"
"    BL      sub_0069092C /*__divmod_unsigned_int*/ \n"
"    STR     R0, [R6, #0x48] \n"

"loc_FF080BB0:\n"
"    LDR     R5, =0x43964 \n"
"    MOV     R7, #2 \n"
"    LDR     R0, [R5, #8] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF080C1C \n"
"    CMP     R4, #0x18 \n"
"    MOV     R0, #4 \n"
"    BEQ     loc_FF080C08 \n"
"    BGT     loc_FF080BF0 \n"
"    CMP     R4, #0xA \n"
"    CMPNE   R4, #0xF \n"
"    STREQ   R7, [R5, #0x14] \n"
"    BEQ     loc_FF080C1C \n"
"    CMP     R4, #0x14 \n"
"    BNE     loc_FF080C10 \n"
"    B       loc_FF080C08 \n"

"loc_FF080BF0:\n"
"    CMP     R4, #0x19 \n"
"    CMPNE   R4, #0x1E \n"
"    BEQ     loc_FF080C08 \n"
"    CMP     R4, #0x3C \n"
"    BNE     loc_FF080C10 \n"
"    MOV     R0, #8 \n"

"loc_FF080C08:\n"
"    STR     R0, [R5, #0x14] \n"
"    B       loc_FF080C1C \n"

"loc_FF080C10:\n"
"    LDR     R1, =0x74C \n"
"    LDR     R0, =0xFF07E60C /*'MovieRecorder.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF080C1C:\n"
"    LDR     R0, [R6, #0x64] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF080C34 \n"
"    BL      sub_FF196354 \n"
"    LDR     R0, =0x4397C \n"
"    BL      sub_FF1EA054 \n"

"loc_FF080C34:\n"
"    LDR     R2, =0x38B2 \n"
"    LDR     R0, [R6, #0xA4] \n"
"    MOV     R3, #2 \n"
"    MOV     R1, #0xAA \n"
"    BL      sub_FF09B5F8 \n"
"    LDR     R2, =0x38B4 \n"
"    LDR     R0, [R6, #0xA4] \n"
"    MOV     R3, #2 \n"
"    MOV     R1, #0xA9 \n"
"    BL      sub_FF09B5F8 \n"
"    LDR     R2, =0x3900 \n"
"    LDR     R0, [R6, #0xA4] \n"
"    MOV     R3, #4 \n"
"    MOV     R1, #0xA2 \n"
"    BL      sub_FF09B5F8 \n"
"    LDR     R2, =0x3904 \n"
"    LDR     R0, [R6, #0xA4] \n"
"    MOV     R3, #4 \n"
"    MOV     R1, #0xA3 \n"
"    BL      sub_FF09B5F8 \n"
"    LDR     R0, [R6, #0x80] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0x3A10 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, #0xF \n"
"    BLNE    _exmem_ualloc \n"
"    LDR     R0, [R6, #0x4C] \n"
"    LDR     R4, =0x3A10 \n"
"    LDR     R10, =0x4394C \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #2 \n"
"    BNE     loc_FF080D68 \n"
"    LDR     R0, [R6, #0x80] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, =0x4A280A60 \n"
"    STRNE   R0, [R4] \n"
"    BNE     loc_FF080D80 \n"
"    LDR     R1, =0x484B4600 \n"
"    LDR     R0, =0x3870600 \n"
"    STR     R1, [R4] \n"
"    STR     R0, [R4, #4] \n"
"    LDMIA   R10, {R0,R2} \n"
"    MUL     R0, R2, R0 \n"
"    MOV     R3, R0, LSL#1 \n"
"    CMP     R3, R8 \n"
"    STR     R3, [R6, #0x8C] \n"
"    MOVCC   R2, #0 \n"
"    STR     R1, [R6, #0x90] \n"
"    BCC     loc_FF080D30 \n"
"    MOV     R2, #0 \n"
"    STMEA   SP, {R1,R2,R8} \n"
"    MOV     R3, R2 \n"
"    MOV     R2, #9 \n"
"    MOV     R1, #5 \n"
"    MOV     R0, #0x16 \n"
"    BL      sub_FF18E540 \n"
"    LDR     R0, [R6, #0x8C] \n"
"    MOV     R2, #0 \n"
"    SUB     R3, R0, #0xF0000 \n"
"    LDR     R0, [R6, #0x90] \n"
"    SUB     R3, R3, #0xFF00 \n"
"    ADD     R1, R0, #0xF0000 \n"
"    ADD     R1, R1, #0xFF00 \n"

"loc_FF080D30:\n"
"    STMEA   SP, {R1-R3} \n"
"    MOV     R3, #0 \n"
"    MOV     R2, #9 \n"
"    MOV     R1, #5 \n"
"    MOV     R0, #0x16 \n"
"    BL      sub_FF18E540 \n"
"    LDR     R1, [R4] \n"
"    LDR     R0, [R6, #0x8C] \n"
"    ADD     R1, R1, R0, LSL#1 \n"
"    STR     R1, [R4] \n"
"    LDR     R1, [R4, #4] \n"
"    RSB     R0, R0, #0 \n"
"    ADD     R0, R1, R0, LSL#1 \n"
"    STR     R0, [R4, #4] \n"

"loc_FF080D68:\n"
"    LDR     R0, [R6, #0x80] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R0, [R4, #4] \n"
"    LDREQ   R1, [R4] \n"
"    BEQ     loc_FF080DE4 \n"
"    LDR     R0, [R4] \n"

"loc_FF080D80:\n"
"    STR     R0, [R6, #0x12C] \n"
"    ADD     R0, R0, #0x800000 \n"
"    ADD     R0, R0, #0x19C00 \n"
"    STR     R0, [R6, #0x134] \n"
"    ADD     R0, R0, #0x3FC000 \n"
"    STR     R0, [R6, #0x124] \n"
"    LDRH    R0, [R6, #6] \n"
"    CMP     R0, #0 \n"
"    STRNE   R9, [R6, #0x128] \n"
"    BNE     loc_FF080DB4 \n"
"    LDR     R1, =0x39D8 \n"
"    LDR     R0, [R5] \n"
"    BL      sub_FF1F0194 \n"

"loc_FF080DB4:\n"
"    LDR     R0, [R6, #0x128] \n"
"    LDR     R1, [R6, #0x124] \n"
"    LDR     R2, =0x20F000 \n"
"    ADD     R1, R1, R0 \n"
"    STR     R1, [R6, #0xEC] \n"
"    ADD     R1, R1, R2 \n"
"    ADD     R0, R0, R2 \n"
"    STR     R2, [R6, #0xF0] \n"
"    LDR     R2, [R4, #4] \n"
"    SUB     R0, R2, R0 \n"
"    SUB     R0, R0, #0xC00000 \n"
"    SUB     R0, R0, #0x15C00 \n"

"loc_FF080DE4:\n"
"    LDR     R2, =0x43964 \n"
"    LDR     R3, =0xFF080B18 \n"
"    STRD    R2, [SP] \n"
"    SUB     R3, R2, #0x18 \n"
"    MOV     R2, R0 \n"
"    LDR     R0, [R6, #0x80] \n"
"    BL      sub_FF1ED108_my \n"  // --> Patched. Old value = 0xFF1ED108.
"    LDR     R0, [R6, #0x158] \n"
"    LDR     R1, [R6, #0x15C] \n"
"    LDR     R2, [R6, #0xA4] \n"
"    BL      sub_FF1ED744 \n"
"    LDR     R3, =0x3928 \n"
"    STR     R3, [SP] \n"
"    LDR     R0, [R6, #0x64] \n"
"    LDR     R1, [R10, #8] \n"
"    AND     R2, R0, #0xFF \n"
"    LDR     R0, [R10] \n"
"    SUB     R3, R3, #4 \n"
"    BL      sub_FF1E9BB0 \n"
"    LDRH    R0, [R6, #6] \n"
"    CMP     R0, #2 \n"
"    LDREQ   R0, =0xFF080818 \n"
"    STREQ   R0, [R6, #0xCC] \n"
"    LDR     R0, [R6, #0x80] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0xFF080460 \n"
"    STREQ   R1, [R6, #0xCC] \n"
"    LDR     R2, [R6, #0x10] \n"
"    LDR     R1, =0xFF49F090 \n"
"    CMP     R2, #2 \n"
"    BNE     loc_FF080E84 \n"
"    LDR     R0, [R6, #0x4C] \n"
"    ADD     R0, R1, R0, LSL#3 \n"
"    LDR     R1, [R10, #0xC] \n"
"    LDR     R0, [R0, R1, LSL#2] \n"
"    BL      sub_FF1940F0 \n"
"    LDR     R0, =0xFF080454 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF19467C \n"
"    B       loc_FF080EBC \n"

"loc_FF080E84:\n"
"    CMP     R0, #0 \n"
"    LDR     R0, [R6, #0x4C] \n"
"    ADD     R0, R1, R0, LSL#3 \n"
"    LDR     R1, [R10, #0xC] \n"
"    LDR     R0, [R0, R1, LSL#2] \n"
"    BNE     loc_FF080EAC \n"
"    LDR     R1, [R6, #0x88] \n"
"    BL      sub_FF19475C \n"
"    BL      sub_FF1947E0 \n"
"    B       loc_FF080EBC \n"

"loc_FF080EAC:\n"
"    BL      sub_FF192290 \n"
"    LDR     R0, =0xFF07EED0 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF192AEC \n"

"loc_FF080EBC:\n"
"    LDR     R0, [R5, #8] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF080EF0 \n"
"    ADD     R0, SP, #0xC \n"
"    BL      sub_FF1EE988 \n"
"    LDR     R1, [R5, #0xC] \n"
"    LDR     R0, [SP, #0xC] \n"
"    BL      sub_FF0608AC \n"
"    ADD     R0, SP, #0xC \n"
"    BL      sub_FF1EE988 \n"
"    LDR     R1, [R5, #0xC] \n"
"    LDR     R0, [SP, #0xC] \n"
"    BL      sub_FF0608AC \n"

"loc_FF080EF0:\n"
"    STR     R7, [R6, #0x44] \n"
"    LDMFD   SP!, {R0-R10,PC} \n"
);
}

/*************************************************************/
//** sub_FF1ED108_my @ 0xFF1ED108 - 0xFF1ED46C, length=218
void __attribute__((naked,noinline)) sub_FF1ED108_my() {
asm volatile (
"    STMFD   SP!, {R0-R11,LR} \n"
"    MOV     R9, R0 \n"
"    LDR     R0, [R3, #0x10] \n"
"    SUB     SP, SP, #4 \n"
"    CMP     R0, #0 \n"
"    LDR     R7, [SP, #0x38] \n"
"    LDREQ   R1, =0x3B7 \n"
"    LDREQ   R0, =0xFF1EA6C0 /*'MovWriter.c'*/ \n"
"    MOV     R6, #0 \n"
"    MOV     R4, R3 \n"
"    MOV     R5, R6 \n"
"    BLEQ    _DebugAssert \n"
"    LDR     R8, =0x9B38 \n"
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
"    B       loc_FF1ED260 \n"
"    B       loc_FF1ED1E8 \n"
"    B       loc_FF1ED1E0 \n"
"    B       loc_FF1ED1D0 \n"
"    B       loc_FF1ED23C \n"
"    B       loc_FF1ED24C \n"
"    B       loc_FF1ED260 \n"
"    B       loc_FF1ED260 \n"
"    B       loc_FF1ED260 \n"
"    B       loc_FF1ED260 \n"
"    B       loc_FF1ED208 \n"
"    B       loc_FF1ED200 \n"
"    B       loc_FF1ED1F8 \n"
"    B       loc_FF1ED234 \n"
"    B       loc_FF1ED22C \n"
"    B       loc_FF1ED218 \n"

"loc_FF1ED1D0:\n"
"    LDR     R5, =0x5DC0 \n"
"    STR     R2, [R8, #0xF8] \n"
"    STR     R5, [R8, #0x154] \n"
"    B       loc_FF1ED1F0 \n"

"loc_FF1ED1E0:\n"
"    MOV     R5, R3 \n"
"    B       loc_FF1ED21C \n"

"loc_FF1ED1E8:\n"
"    MOV     R5, R1 \n"
"    B       loc_FF1ED20C \n"

"loc_FF1ED1F0:\n"
"    STR     R0, [R8, #0x158] \n"
"    B       loc_FF1ED26C \n"

"loc_FF1ED1F8:\n"
"    LDR     R5, =0x5DC \n"
"    B       loc_FF1ED20C \n"

"loc_FF1ED200:\n"
"    LDR     R5, =0xBB8 \n"
"    B       loc_FF1ED20C \n"

"loc_FF1ED208:\n"
"    LDR     R5, =0x1770 \n"

"loc_FF1ED20C:\n"
"    STR     R1, [R8, #0x154] \n"
"    STR     R10, [R8, #0xF8] \n"
"    B       loc_FF1ED1F0 \n"

"loc_FF1ED218:\n"
"    LDR     R5, =0x4E2 \n"

"loc_FF1ED21C:\n"
"    STR     R2, [R8, #0xF8] \n"
"    STR     R3, [R8, #0x154] \n"
"    STR     R12, [R8, #0x158] \n"
"    B       loc_FF1ED26C \n"

"loc_FF1ED22C:\n"
"    LDR     R5, =0x9C4 \n"
"    B       loc_FF1ED21C \n"

"loc_FF1ED234:\n"
"    LDR     R5, =0x1388 \n"
"    B       loc_FF1ED21C \n"

"loc_FF1ED23C:\n"
"    STR     R1, [R8, #0x154] \n"
"    LDR     R5, =0x57600000 \n"  // --> Patched. Old value = 0x3A980. 2hrs
"    MOV     R1, #0xF0 \n"
"    B       loc_FF1ED258 \n"

"loc_FF1ED24C:\n"
"    LDR     R5, =0x28800000 \n"  // --> Patched. Old value = 0x1D4C0. 2hrs
"    STR     R1, [R8, #0x154] \n"
"    MOV     R1, #0x78 \n"

"loc_FF1ED258:\n"
"    STR     R1, [R8, #0xF8] \n"
"    B       loc_FF1ED1F0 \n"

"loc_FF1ED260:\n"
"    LDR     R1, =0x411 \n"
"    LDR     R0, =0xFF1EA6C0 /*'MovWriter.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF1ED26C:\n"
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
"    BEQ     loc_FF1ED304 \n"
"    CMP     R0, #0x280 \n"
"    LDREQ   R0, =0x7A760 \n"
"    MOVEQ   R6, #2 \n"
"    STREQ   R0, [R8, #0xC4] \n"
"    BEQ     loc_FF1ED304 \n"
"    CMP     R0, #0x500 \n"
"    LDREQ   R0, =0x11DA50 \n"
"    LDR     R1, =0x1C20 \n"  // --> Patched. Old value = 0x707. 2hrs
"    MOVEQ   R6, #4 \n"
"    STREQ   R0, [R8, #0xC4] \n"
"    BEQ     loc_FF1ED304 \n"
"    CMP     R0, #0x780 \n"
"    BNE     loc_FF1ED30C \n"
//"  MOV     R0, #0x200000 \n"
"    MOV     R0, #2097152 \n" // 10 mins
"    MOV     R6, #5 \n"
"    STR     R0, [R8, #0xC4] \n"

"loc_FF1ED304:\n"
"    STR     R1, [R8, #0x58] \n"
"    B       loc_FF1ED318 \n"

"loc_FF1ED30C:\n"
"    LDR     R1, =0x439 \n"
"    LDR     R0, =0xFF1EA6C0 /*'MovWriter.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF1ED318:\n"
"    LDR     R9, [R4, #8] \n"
"    CMP     R9, #0xB \n"
"    CMPNE   R9, #0xA \n"
"    CMPNE   R9, #9 \n"
"    BNE     loc_FF1ED34C \n"
"    LDR     R0, [R8, #0xF0] \n"
"    CMP     R0, #0x500 \n"
"    BNE     loc_FF1ED34C \n"
"    LDR     R0, [R8, #0x58] \n"
"    LDR     R1, [R8, #0x158] \n"
"    MUL     R0, R5, R0 \n"
"    BL      sub_0069092C /*__divmod_unsigned_int*/ \n"
"    B       loc_FF1ED36C \n"

"loc_FF1ED34C:\n"
"    LDR     R0, [R8, #0x58] \n"
"    LDR     R1, [R8, #0x158] \n"
"    MUL     R0, R5, R0 \n"
"    BL      sub_0069092C /*__divmod_unsigned_int*/ \n"
"    MOV     R1, #5 \n"
"    BL      sub_0069092C /*__divmod_unsigned_int*/ \n"
"    ADD     R0, R0, #1 \n"
"    ADD     R0, R0, R0, LSL#2 \n"

"loc_FF1ED36C:\n"
"    CMP     R9, #0xB \n"
"    CMPNE   R9, #0xA \n"
"    CMPNE   R9, #9 \n"
"    STR     R0, [R8, #0x54] \n"
"    BNE     loc_FF1ED394 \n"
"    LDR     R1, [R8, #0x158] \n"
"    MUL     R0, R1, R0 \n"
"    MOV     R1, R5 \n"
"    BL      sub_0069092C /*__divmod_unsigned_int*/ \n"
"    STR     R0, [R8, #0x58] \n"

"loc_FF1ED394:\n"
"    CMP     R9, #3 \n"
"    CMPNE   R9, #4 \n"
"    BNE     loc_FF1ED3CC \n"
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

"loc_FF1ED3CC:\n"
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
"    BEQ     sub_FF1ED69C \n"
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
"    BEQ     sub_FF1ED530 \n"
"    LDR     R2, [R8, #0xC4] \n"
"    ADD     R0, R0, R2 \n"
"    B       sub_FF1ED4F0 \n"
);
}
