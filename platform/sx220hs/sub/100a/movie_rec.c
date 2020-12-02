/*
 * movie_rec.c - auto-generated by CHDK code_gen.
 */
#include "conf.h"

void change_video_tables(__attribute__ ((unused))int a, __attribute__ ((unused))int b) {}

void  set_quality(int *x){ // -17 highest; +12 lowest
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

/*************************************************************/
//** movie_record_task @ 0xFF1882F0 - 0xFF188468, length=95
void __attribute__((naked,noinline)) movie_record_task() {
asm volatile (
"    STMFD   SP!, {R2-R10,LR} \n"
"    LDR     R6, =0xFF187060 \n"
"    LDR     R7, =0xFF187D48 \n"
"    LDR     R4, =0x8550 \n"
"    LDR     R9, =0x67F \n"
"    LDR     R10, =0x2710 \n"
"    MOV     R8, #1 \n"
"    MOV     R5, #0 \n"

"loc_FF188310:\n"
"    LDR     R0, [R4, #0x24] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF02AD50 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [R4, #0x2C] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, [R4, #0xC] \n"
"    CMPNE   R0, #2 \n"
"    LDRNE   R0, [R4, #0x44] \n"
"    CMPNE   R0, #6 \n"
"    BNE     loc_FF18844C \n"
"    LDR     R0, [SP, #4] \n"
"    LDR     R1, [R0] \n"
"    SUB     R1, R1, #2 \n"
"    CMP     R1, #0xD \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF18844C \n"
"    B       loc_FF1883EC \n"
"    B       loc_FF188410 \n"
"    B       loc_FF188420 \n"
"    B       loc_FF188428 \n"
"    B       loc_FF188430 \n"
"    B       loc_FF188438 \n"
"    B       loc_FF1883F4 \n"
"    B       loc_FF188440 \n"
"    B       loc_FF188400 \n"
"    B       loc_FF18844C \n"
"    B       loc_FF188448 \n"
"    B       loc_FF1883B8 \n"
"    B       loc_FF188388 \n"

"loc_FF188388:\n"
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
"    B       loc_FF1883D8 \n"

"loc_FF1883B8:\n"
"    STR     R5, [R4, #0x40] \n"
"    STR     R5, [R4, #0x30] \n"
"    STR     R6, [R4, #0xD8] \n"
"    STR     R7, [R4, #0xF0] \n"
"    LDR     R0, [R4, #0xC] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0xC] \n"
"    STR     R8, [R4, #0x44] \n"

"loc_FF1883D8:\n"
"    LDR     R2, =0xFF18669C \n"
"    LDR     R1, =0xC2E08 \n"
"    LDR     R0, =0xFF1867B0 \n"
"    BL      sub_FF044E3C \n"
"    B       loc_FF18844C \n"

"loc_FF1883EC:\n"
);
if (conf.ext_video_time == 1)
{
asm volatile (
"    BL      sub_FF18792C_my \n"  // --> Patched. Old value = 0xFF18792C.
);
}
else
{
asm volatile (
"    BL      sub_FF18792C \n"
);
}
asm volatile (
"    B       loc_FF18844C \n"

"loc_FF1883F4:\n"
"    LDR     R1, [R4, #0xF0] \n"
"    BLX     R1 \n"
//begin patch
"    LDR     R0, =video_compression_rate\n" //added
"    BL      set_quality\n"                 //added
//end patch
"    B       loc_FF18844C \n"

"loc_FF188400:\n"
"    LDR     R1, [R0, #0x18] \n"
"    LDR     R0, [R0, #4] \n"
"    BL      sub_FF2FC9F0 \n"
"    B       loc_FF18844C \n"

"loc_FF188410:\n"
"    LDR     R0, [R4, #0x44] \n"
"    CMP     R0, #5 \n"
"    STRNE   R8, [R4, #0x34] \n"
"    B       loc_FF18844C \n"

"loc_FF188420:\n"
"    BL      sub_FF186D3C \n"
"    B       loc_FF18844C \n"

"loc_FF188428:\n"
"    BL      sub_FF186A50 \n"
"    B       loc_FF18844C \n"

"loc_FF188430:\n"
"    BL      sub_FF186808 \n"
"    B       loc_FF18844C \n"

"loc_FF188438:\n"
"    BL      sub_FF186430 \n"
"    B       loc_FF18844C \n"

"loc_FF188440:\n"
"    BL      sub_FF1863B0 \n"
"    B       loc_FF18844C \n"

"loc_FF188448:\n"
"    BL      sub_FF18899C \n"

"loc_FF18844C:\n"
"    LDR     R1, [SP, #4] \n"
"    LDR     R3, =0xFF186114 /*'MovieRecorder.c'*/ \n"
"    STR     R5, [R1] \n"
"    STR     R9, [SP] \n"
"    LDR     R0, [R4, #0x28] \n"
"    MOV     R2, R10 \n"
"    BL      sub_FF02B6C8 /*_PostMessageQueueStrictly*/ \n"
"    B       loc_FF188310 \n"
);
}

/*************************************************************/
//** sub_FF18792C_my @ 0xFF18792C - 0xFF187C0C, length=185
void __attribute__((naked,noinline)) sub_FF18792C_my() {
asm volatile (
"    STMFD   SP!, {R0-R8,LR} \n"
"    LDR     R6, =0x8550 \n"
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
"    BNE     loc_FF187970 \n"
"    LDR     R1, [R6, #0x90] \n"
"    CMP     R1, #0 \n"
"    BNE     loc_FF187980 \n"
"    B       loc_FF187978 \n"

"loc_FF187970:\n"
"    CMP     R1, #3 \n"
"    BNE     loc_FF187980 \n"

"loc_FF187978:\n"
"    STR     R2, [R6, #0x48] \n"
"    B       loc_FF18798C \n"

"loc_FF187980:\n"
"    MOV     R1, #0x3E8 \n"
"    BL      sub_FF3ABAE0 /*__divmod_unsigned_int*/ \n"
"    STR     R0, [R6, #0x48] \n"

"loc_FF18798C:\n"
"    LDR     R4, =0xC2E3C \n"
"    MOV     R7, #2 \n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF1879F4 \n"
"    LDR     R0, [R6, #0x58] \n"
"    MOV     R1, #4 \n"
"    CMP     R0, #0x18 \n"
"    BEQ     loc_FF187B88 \n"
"    BGT     loc_FF1879D0 \n"
"    CMP     R0, #0xA \n"
"    CMPNE   R0, #0xF \n"
"    STREQ   R7, [R4, #0x14] \n"
"    BEQ     loc_FF1879F4 \n"
"    CMP     R0, #0x14 \n"
"    BNE     loc_FF1879E8 \n"
"    B       loc_FF187B88 \n"

"loc_FF1879D0:\n"
"    CMP     R0, #0x1E \n"
"    BEQ     loc_FF187B88 \n"
"    CMP     R0, #0x3C \n"
"    MOVEQ   R0, #8 \n"
"    STREQ   R0, [R4, #0x14] \n"
"    BEQ     loc_FF1879F4 \n"

"loc_FF1879E8:\n"
"    LDR     R1, =0x777 \n"
"    LDR     R0, =0xFF186114 /*'MovieRecorder.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF1879F4:\n"
"    LDR     R2, =0x8552 \n"
"    LDR     R0, [R6, #0xB8] \n"
"    MOV     R3, #2 \n"
"    MOV     R1, #0xAA \n"
"    BL      sub_FF08AD7C \n"
"    LDR     R2, =0x8554 \n"
"    LDR     R0, [R6, #0xB8] \n"
"    MOV     R3, #2 \n"
"    MOV     R1, #0xA9 \n"
"    BL      sub_FF08AD7C \n"
"    LDR     R2, =0x85A0 \n"
"    LDR     R0, [R6, #0xB8] \n"
"    MOV     R3, #4 \n"
"    MOV     R1, #0xA2 \n"
"    BL      sub_FF08AD7C \n"
"    LDR     R2, =0x85A4 \n"
"    LDR     R0, [R6, #0xB8] \n"
"    MOV     R3, #4 \n"
"    MOV     R1, #0xA3 \n"
"    BL      sub_FF08AD7C \n"
"    LDR     R0, [R6, #0x90] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0x8650 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, #0xD \n"
"    BLNE    _exmem_ualloc \n"
"    LDR     R0, [R6, #0x4C] \n"
"    LDR     R5, =0x8650 \n"
"    LDR     R8, =0xC2E24 \n"
"    CMP     R0, #2 \n"
"    CMPNE   R0, #3 \n"
"    BNE     loc_FF187AF0 \n"
"    LDR     R0, [R6, #0x90] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, =0x443FC000 \n"
"    STRNE   R0, [R5] \n"
"    BNE     loc_FF187AF0 \n"
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
"    BL      sub_FF2A8EB8 \n"
"    LDR     R1, [R5] \n"
"    LDR     R0, [R6, #0x9C] \n"
"    ADD     R1, R1, R0, LSL#1 \n"
"    STR     R1, [R5] \n"
"    LDR     R1, [R5, #4] \n"
"    RSB     R0, R0, #0 \n"
"    ADD     R0, R1, R0, LSL#1 \n"
"    STR     R0, [R5, #4] \n"

"loc_FF187AF0:\n"
"    LDR     R3, =0xFF1878F8 \n"
"    LDMIA   R5, {R0,R1} \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =0xC2E3C \n"
"    SUB     R2, R3, #0x18 \n"
"    BL      sub_FF2FB36C_my \n"  // --> Patched. Old value = 0xFF2FB36C.
"    LDR     R3, [R6, #0xB8] \n"
"    STR     R3, [SP] \n"
"    LDR     R0, [R6, #0x90] \n"
"    LDRD    R2, [R6, #0xF8] \n"
"    BL      sub_FF2FB784 \n"
"    LDR     R0, [R6, #0x64] \n"
"    LDR     R3, =0x85D8 \n"
"    AND     R1, R0, #0xFF \n"
"    LDR     R0, [R8] \n"
"    SUB     R2, R3, #4 \n"
"    BL      sub_FF2F9458 \n"
"    LDRH    R0, [R6, #6] \n"
"    CMP     R0, #2 \n"
"    LDREQ   R0, =0xFF1875CC \n"
"    STREQ   R0, [R6, #0xF0] \n"
"    LDR     R0, [R6, #0x90] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0xFF187210 \n"
"    STREQ   R1, [R6, #0xF0] \n"
"    LDR     R2, [R6, #0xC] \n"
"    LDR     R1, =0xFF409E1C \n"
"    CMP     R2, #2 \n"
"    BNE     loc_FF187B90 \n"
"    LDR     R0, [R6, #0x4C] \n"
"    ADD     R0, R1, R0, LSL#3 \n"
"    LDR     R1, [R8, #0xC] \n"
"    LDR     R0, [R0, R1, LSL#2] \n"
"    BL      sub_FF2AEF54 \n"
"    LDR     R0, =0xFF18713C \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF2AF468 \n"
"    B       loc_FF187BCC \n"

"loc_FF187B88:\n"
"    STR     R1, [R4, #0x14] \n"
"    B       loc_FF1879F4 \n"

"loc_FF187B90:\n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF187BAC \n"
"    LDR     R1, [R6, #0x98] \n"
"    MOV     R0, #5 \n"
"    BL      sub_FF2AF47C \n"
"    BL      sub_FF2AF50C \n"
"    B       loc_FF187BCC \n"

"loc_FF187BAC:\n"
"    LDR     R0, [R6, #0x4C] \n"
"    ADD     R0, R1, R0, LSL#3 \n"
"    LDR     R1, [R8, #0xC] \n"
"    LDR     R0, [R0, R1, LSL#2] \n"
"    BL      sub_FF2AD6E4 \n"
"    LDR     R0, =0xFF18713C \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF2ADE30 \n"

"loc_FF187BCC:\n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF187C00 \n"
"    ADD     R0, SP, #0xC \n"
"    BL      sub_FF2FC86C \n"
"    LDR     R1, [R4, #0xC] \n"
"    LDR     R0, [SP, #0xC] \n"
"    BL      sub_FF05BB24 \n"
"    ADD     R0, SP, #0xC \n"
"    BL      sub_FF2FC86C \n"
"    LDR     R1, [R4, #0xC] \n"
"    LDR     R0, [SP, #0xC] \n"
"    BL      sub_FF05BB24 \n"

"loc_FF187C00:\n"
"    LDR     R0, =0xFF1870F4 \n"
"    STR     R7, [R6, #0x44]! \n"
"    STR     R0, [R6, #0x94] \n"
"    LDMFD   SP!, {R0-R8,PC} \n"
);
}

/*************************************************************/
//** sub_FF2FB36C_my @ 0xFF2FB36C - 0xFF2FB728, length=240
void __attribute__((naked,noinline)) sub_FF2FB36C_my() {
asm volatile (
"    STMFD   SP!, {R0-R12,LR} \n"
"    MOV     R9, R0 \n"
"    LDR     R0, [R2, #0x10] \n"
"    LDR     R8, [SP, #0x38] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x32A \n"
"    LDREQ   R0, =0xFF2FA340 /*'MovWriter.c'*/ \n"
"    MOV     R5, #0 \n"
"    MOV     R4, R2 \n"
"    MOV     R10, R3 \n"
"    MOV     R7, R5 \n"
"    BLEQ    _DebugAssert \n"
"    LDR     R6, =0xDD98 \n"
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
"    B       loc_FF2FB458 \n"
"    B       loc_FF2FB40C \n"
"    B       loc_FF2FB3FC \n"
"    B       loc_FF2FB434 \n"
"    B       loc_FF2FB448 \n"
"    B       loc_FF2FB458 \n"
"    B       loc_FF2FB458 \n"
"    B       loc_FF2FB458 \n"
"    B       loc_FF2FB458 \n"
"    B       loc_FF2FB42C \n"
"    B       loc_FF2FB424 \n"
"    B       loc_FF2FB414 \n"

"loc_FF2FB3FC:\n"
"    LDR     R7, =0x5DC0 \n"
"    MOV     R0, #0x18 \n"
"    STR     R7, [R6, #0x12C] \n"
"    B       loc_FF2FB440 \n"

"loc_FF2FB40C:\n"
"    MOV     R7, R0 \n"
"    B       loc_FF2FB418 \n"

"loc_FF2FB414:\n"
"    LDR     R7, =0x5DC \n"

"loc_FF2FB418:\n"
"    STR     R0, [R6, #0x12C] \n"
"    STR     R11, [R6, #0xD8] \n"
"    B       loc_FF2FB464 \n"

"loc_FF2FB424:\n"
"    LDR     R7, =0xBB8 \n"
"    B       loc_FF2FB418 \n"

"loc_FF2FB42C:\n"
"    LDR     R7, =0x1770 \n"
"    B       loc_FF2FB418 \n"

"loc_FF2FB434:\n"
"    LDR     R7, =0x57600000 \n"  // --> Patched. Old value = 0x3A980. 2hrs 240fps
"    STR     R0, [R6, #0x12C] \n"
"    MOV     R0, #0xF0 \n"

"loc_FF2FB440:\n"
"    STR     R0, [R6, #0xD8] \n"
"    B       loc_FF2FB464 \n"

"loc_FF2FB448:\n"
"    STR     R0, [R6, #0x12C] \n"
"    LDR     R7, =0x28800000 \n"  // --> Patched. Old value = 0x1D4C0. 2hrs 120fps
"    MOV     R0, #0x78 \n"
"    B       loc_FF2FB440 \n"

"loc_FF2FB458:\n"
"    LDR     R1, =0x35B \n"
"    LDR     R0, =0xFF2FA340 /*'MovWriter.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF2FB464:\n"
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
"    BEQ     loc_FF2FB4F8 \n"
"    CMP     R0, #0x280 \n"
"    LDREQ   R0, =0x7A760 \n"
"    MOVEQ   R5, #2 \n"
"    STREQ   R0, [R6, #0xAC] \n"
"    BEQ     loc_FF2FB4F8 \n"
"    CMP     R0, #0x500 \n"
"    LDREQ   R0, =0x11DA50 \n"
"    LDR     R1, =0x1C20 \n"  // --> Patched. Old value = 0x707. 2hrs
"    MOVEQ   R5, #4 \n"
"    STREQ   R0, [R6, #0xAC] \n"
"    BEQ     loc_FF2FB4F8 \n"
"    CMP     R0, #0x780 \n"
"    BNE     loc_FF2FB500 \n"
//"  MOV     R0, #0x200000 \n"
"    MOV     R0, #2097152 \n" // 10 mins
"    MOV     R5, #5 \n"
"    STR     R0, [R6, #0xAC] \n"

"loc_FF2FB4F8:\n"
"    STR     R1, [R6, #0x4C] \n"
"    B       loc_FF2FB50C \n"

"loc_FF2FB500:\n"
"    LDR     R1, =0x383 \n"
"    LDR     R0, =0xFF2FA340 /*'MovWriter.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF2FB50C:\n"
"    LDR     R0, [R6, #0x4C] \n"
"    LDR     R1, =0x138D \n"
"    MUL     R0, R7, R0 \n"
"    BL      sub_FF3ABAE0 /*__divmod_unsigned_int*/ \n"
"    ADD     R0, R0, #1 \n"
"    ADD     R0, R0, R0, LSL#2 \n"
"    STR     R0, [R6, #0x48] \n"
"    LDR     R8, [R4, #8] \n"
"    CMP     R8, #2 \n"
"    CMPNE   R8, #3 \n"
"    BNE     loc_FF2FB564 \n"
"    RSB     R0, R7, R7, LSL#4 \n"
"    LDR     R1, =0x3E9 \n"
"    MOV     R0, R0, LSL#1 \n"
"    STR     R11, [R6, #0x4C] \n"
"    BL      sub_FF3ABAE0 /*__divmod_unsigned_int*/ \n"
"    LDR     R1, [R6, #0xE0] \n"
"    MOV     R7, R1 \n"
"    BL      sub_FF3ABAE0 /*__divmod_unsigned_int*/ \n"
"    ADD     R0, R0, #1 \n"
"    MUL     R0, R7, R0 \n"
"    STR     R0, [R6, #0x48] \n"

"loc_FF2FB564:\n"
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
"    BEQ     loc_FF2FB6E4 \n"
"    STR     R2, [R6, #0xFC] \n"
"    LDR     R3, [R6, #0x4C] \n"
"    LDR     R9, =0x119910 \n"
"    ADD     R2, R2, R3, LSL#3 \n"
"    ADD     R2, R2, #0x1F \n"
"    BIC     R2, R2, #0x1F \n"
"    STR     R2, [R6, #0x100] \n"
"    LDR     R3, [R6, #0xAC] \n"
"    LDR     R11, =0xDF18 \n"
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

"loc_FF2FB614:\n"
"    MLA     R0, R2, R7, R8 \n"
"    ADD     R12, R9, R2, LSL#3 \n"
"    ADD     R0, R0, #3 \n"
"    BIC     R0, R0, #3 \n"
"    STR     R0, [R11, R2, LSL#2] \n"
"    MOV     R0, #0 \n"
"    ADD     R6, R10, R2, LSL#3 \n"

"loc_FF2FB630:\n"
"    STR     R3, [R12, R0, LSL#2] \n"
"    STR     R3, [R6, R0, LSL#2] \n"
"    ADD     R0, R0, #1 \n"
"    CMP     R0, #2 \n"
"    BLT     loc_FF2FB630 \n"
"    ADD     R2, R2, #1 \n"
"    CMP     R2, #2 \n"
"    BLT     loc_FF2FB614 \n"
"    LDRH    R3, [R4, #0x14] \n"
"    LDR     R2, [R4, #8] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF0D87FC \n"
"    LDR     R1, =0xDD98 \n"
"    LDR     R2, [R1, #0x94] \n"
"    ADD     R0, R0, R2 \n"
"    STR     R0, [R1, #0x8C] \n"
"    LDMFD   SP!, {R0-R12,PC} \n"

"loc_FF2FB6E4:\n"
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
"    BL      sub_FF0D87FC \n"
"    STR     R0, [R6, #0x8C] \n"
"    LDMFD   SP!, {R0-R12,PC} \n"
);
}
