/*
 * movie_rec.c - auto-generated by CHDK code_gen.
 */
#include "conf.h"

int *video_quality = &conf.video_quality;
int *video_mode    = &conf.video_mode;

long def_table[24]={0x2000, 0x38D, 0x788, 0x5800, 0x9C5, 0x14B8, 0x10000, 0x1C6A, 0x3C45, 0x8000, 0xE35, 0x1E23,
           0x1CCD, -0x2E1, -0x579, 0x4F33, -0x7EB, -0xF0C, 0xE666, -0x170A, -0x2BC6, 0x7333, -0xB85, -0x15E3};

long table[24];

void change_video_tables(int a, int b){
 int i;
 for (i=0;i<24;i++) table[i]=(def_table[i]*a)/b;
}

long CompressionRateTable[]={0x60, 0x5D, 0x5A, 0x57, 0x54, 0x51, 0x4D, 0x48, 0x42, 0x3B, 0x32, 0x29, 0x22, 0x1D, 0x17, 0x14, 0x10, 0xE, 0xB, 9, 7, 6, 5, 4, 3, 2, 1};

/*************************************************************/
//** movie_record_task @ 0xFFD0C848 - 0xFFD0C94C, length=66
void __attribute__((naked,noinline)) movie_record_task() {
asm volatile (
"    STMFD   SP!, {R2-R8,LR} \n"
"    LDR     R8, =0x346 \n"
"    LDR     R7, =0x2710 \n"
"    LDR     R4, =0x5438 \n"
"    MOV     R6, #0 \n"
"    MOV     R5, #1 \n"

"loc_FFD0C860:\n"
"    LDR     R0, [R4, #0x18] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FFC28AA4 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [R4, #0x20] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FFD0C930 \n"
"    LDR     R0, [SP, #4] \n"
"    LDR     R1, [R0] \n"
"    SUB     R1, R1, #2 \n"
"    CMP     R1, #9 \n"
"    ADDLS   PC, PC, R1, LSL#2 \n"
"    B       loc_FFD0C930 \n"
"    B       loc_FFD0C8E4 \n"
"    B       loc_FFD0C904 \n"
"    B       loc_FFD0C914 \n"
"    B       loc_FFD0C91C \n"
"    B       loc_FFD0C8EC \n"
"    B       loc_FFD0C924 \n"
"    B       loc_FFD0C8F4 \n"
"    B       loc_FFD0C930 \n"
"    B       loc_FFD0C92C \n"
"    B       loc_FFD0C8BC \n"

"loc_FFD0C8BC:\n"
"    LDR     R0, =0xFFD0C554 \n"
"    STR     R6, [R4, #0x34] \n"
"    STR     R0, [R4, #0xA8] \n"
"    LDR     R0, =0xFFD0BFE4 \n"
"    LDR     R2, =0xFFD0BF00 \n"
"    LDR     R1, =0x6FA40 \n"
"    STR     R6, [R4, #0x24] \n"
"    BL      sub_FFCB6370 \n"
"    STR     R5, [R4, #0x38] \n"
"    B       loc_FFD0C930 \n"

"loc_FFD0C8E4:\n"
"    BL      unlock_optical_zoom\n" // added
"    BL      sub_FFD0C64C \n"
"    B       loc_FFD0C930 \n"

"loc_FFD0C8EC:\n"
"    BL      sub_FFD0C354_my \n"  // --> Patched. Old value = 0xFFD0C354.
"    B       loc_FFD0C930 \n"

"loc_FFD0C8F4:\n"
"    LDR     R1, [R0, #0x10] \n"
"    LDR     R0, [R0, #4] \n"
"    BL      sub_FFDF5F28 \n"
"    B       loc_FFD0C930 \n"

"loc_FFD0C904:\n"
"    LDR     R0, [R4, #0x38] \n"
"    CMP     R0, #5 \n"
"    STRNE   R5, [R4, #0x28] \n"
"    B       loc_FFD0C930 \n"

"loc_FFD0C914:\n"
"    BL      sub_FFD0C16C \n"
"    B       loc_FFD0C930 \n"

"loc_FFD0C91C:\n"
"    BL      sub_FFD0C030 \n"
"    B       loc_FFD0C930 \n"

"loc_FFD0C924:\n"
"    BL      sub_FFD0BE8C \n"
"    B       loc_FFD0C930 \n"

"loc_FFD0C92C:\n"
"    BL      sub_FFD0CA98 \n"

"loc_FFD0C930:\n"
"    LDR     R1, [SP, #4] \n"
"    LDR     R3, =0xFFD0BD1C \n"
"    STR     R6, [R1] \n"
"    STR     R8, [SP] \n"
"    LDR     R0, [R4, #0x1C] \n"
"    MOV     R2, R7 \n"
"    BL      sub_FFC0F5C0 /*_PostMessageQueueStrictly*/ \n"
"    B       loc_FFD0C860 \n"
);
}

/*************************************************************/
//** sub_FFD0C354_my @ 0xFFD0C354 - 0xFFD0C554, length=129
void __attribute__((naked,noinline)) sub_FFD0C354_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    SUB     SP, SP, #0x40 \n"
"    MOV     R6, #0 \n"
"    LDR     R5, =0x5438 \n"
"    MOV     R4, R0 \n"
"    STR     R6, [SP, #0x30] \n"
"    STR     R6, [SP, #0x28] \n"
"    LDR     R0, [R5, #0x38] \n"
"    MOV     R8, #4 \n"
"    CMP     R0, #3 \n"
"    STREQ   R8, [R5, #0x38] \n"
"    LDR     R0, [R5, #0xA8] \n"
"    BLX     R0 \n"
"    LDR     R0, [R5, #0x38] \n"
"    CMP     R0, #4 \n"
"    BNE     loc_FFD0C42C \n"
"    ADD     R3, SP, #0x28 \n"
"    ADD     R2, SP, #0x2C \n"
"    ADD     R1, SP, #0x30 \n"
"    ADD     R0, SP, #0x34 \n"
"    BL      sub_FFDF60BC \n"
"    CMP     R0, #0 \n"
"    MOV     R7, #1 \n"
"    BNE     loc_FFD0C3D0 \n"
"    LDR     R1, [R5, #0x28] \n"
"    CMP     R1, #1 \n"
"    BNE     loc_FFD0C434 \n"
"    LDR     R1, [R5, #0x60] \n"
"    LDR     R2, [R5, #0x3C] \n"
"    CMP     R1, R2 \n"
"    BCC     loc_FFD0C434 \n"

"loc_FFD0C3D0:\n"
"    CMP     R0, #0x80000001 \n"
"    STREQ   R8, [R5, #0x64] \n"
"    BEQ     loc_FFD0C408 \n"
"    CMP     R0, #0x80000003 \n"
"    STREQ   R7, [R5, #0x64] \n"
"    BEQ     loc_FFD0C408 \n"
"    CMP     R0, #0x80000005 \n"
"    MOVEQ   R0, #2 \n"
"    BEQ     loc_FFD0C404 \n"
"    CMP     R0, #0x80000007 \n"
"    STRNE   R6, [R5, #0x64] \n"
"    BNE     loc_FFD0C408 \n"
"    MOV     R0, #3 \n"

"loc_FFD0C404:\n"
"    STR     R0, [R5, #0x64] \n"

"loc_FFD0C408:\n"
"    LDR     R0, =0x6FA70 \n"
"    LDR     R0, [R0, #8] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFD0C420 \n"
"    BL      sub_FFC445CC \n"
"    B       loc_FFD0C424 \n"

"loc_FFD0C420:\n"
"    BL      sub_FFD0BE8C \n"

"loc_FFD0C424:\n"
"    MOV     R0, #5 \n"
"    STR     R0, [R5, #0x38] \n"

"loc_FFD0C42C:\n"
"    ADD     SP, SP, #0x40 \n"
"    LDMFD   SP!, {R4-R8,PC} \n"

"loc_FFD0C434:\n"
"    LDR     LR, [SP, #0x30] \n"
"    CMP     LR, #0 \n"
"    BEQ     loc_FFD0C4FC \n"
"    STR     R7, [R5, #0x2C] \n"
"    LDR     R0, [R5, #0x7C] \n"
"    LDR     R1, [R4, #0x14] \n"
"    LDR     R2, [R4, #0x18] \n"
"    LDR     R12, [R4, #0xC] \n"
"    ADD     R3, SP, #0x38 \n"
"    ADD     R8, SP, #0x14 \n"
"    STMIA   R8, {R0-R3} \n"
"    LDR     R3, [R5, #0x68] \n"
"    ADD     R2, SP, #0x3C \n"
"    ADD     R8, SP, #8 \n"
"    LDRD    R0, [SP, #0x28] \n"
"    STMIA   R8, {R0,R2,R3} \n"
"    STR     R1, [SP, #4] \n"
"    STR     LR, [SP] \n"
"    LDMIB   R4, {R0,R1} \n"
"    LDR     R3, [SP, #0x34] \n"
"    MOV     R2, R12 \n"
"    BL      sub_FFDCB750 \n"
"    LDR     R0, [R5, #0x10] \n"
"    LDR     R1, [R5, #0x58] \n"
"    BL      _TakeSemaphore \n"
"    CMP     R0, #9 \n"
"    BNE     loc_FFD0C4B0 \n"
"    BL      sub_FFDF66A8 \n"
"    MOV     R0, #0x90000 \n"
"    STR     R7, [R5, #0x38] \n"
"    B       loc_FFD0C4C8 \n"

"loc_FFD0C4B0:\n"
"    LDR     R0, [SP, #0x38] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFD0C4D0 \n"
"    BL      sub_FFDF66A8 \n"
"    MOV     R0, #0xA0000 \n"
"    STR     R7, [R5, #0x38] \n"

"loc_FFD0C4C8:\n"
"    BL      sub_FFC6CFCC /*_HardwareDefect_FW*/ \n"
"    B       loc_FFD0C42C \n"

"loc_FFD0C4D0:\n"
"    BL      sub_FFDCB814 \n"
"    LDR     R0, [SP, #0x34] \n"
"    LDR     R1, [SP, #0x3C] \n"
"    BL      sub_FFDF6450 \n"
"    LDR     R0, [R5, #0x5C] \n"
"    LDR     R1, =0x54B4 \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R5, #0x5C] \n"
"    LDR     R0, [SP, #0x3C] \n"
"    MOV     R2, #0 \n"
"    BL      sub_FFDF4274_my \n"  // --> Patched. Old value = 0xFFDF4274.

"loc_FFD0C4FC:\n"
"    LDR     R0, [R5, #0x60] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R5, #0x60] \n"
"    LDR     R1, [R5, #0x4C] \n"
"    MUL     R0, R1, R0 \n"
"    LDR     R1, [R5, #0x48] \n"
"    BL      sub_FFE7FAAC /*__divmod_unsigned_int*/ \n"
"    MOV     R4, R0 \n"
"    BL      sub_FFDF66E0 \n"
"    LDR     R1, [R5, #0x80] \n"
"    CMP     R1, R4 \n"
"    BNE     loc_FFD0C538 \n"
"    LDR     R0, [R5, #0x30] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FFD0C54C \n"

"loc_FFD0C538:\n"
"    LDR     R1, [R5, #0x8C] \n"
"    MOV     R0, R4 \n"
"    BLX     R1 \n"
"    STR     R4, [R5, #0x80] \n"
"    STR     R6, [R5, #0x30] \n"

"loc_FFD0C54C:\n"
"    STR     R6, [R5, #0x2C] \n"
"    B       loc_FFD0C42C \n"
"    BX      LR \n"
);
}

/*************************************************************/
//** sub_FFDF4274_my @ 0xFFDF4274 - 0xFFDF4354, length=57
void __attribute__((naked,noinline)) sub_FFDF4274_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R4, =0x88A0 \n"
"    LDR     LR, [R4] \n"
"    LDR     R2, [R4, #8] \n"
"    CMP     LR, #0 \n"
"    LDRNE   R3, [R4, #0xC] \n"
"    MOV     R5, R2 \n"
"    CMPNE   R3, #1 \n"
"    MOVEQ   R2, #0 \n"
"    STREQ   R0, [R4] \n"
"    STREQ   R2, [R4, #0xC] \n"
"    BEQ     loc_FFDF4340 \n"
"    LDR     R3, [R4, #4] \n"
//"  LDR     R7, =0xFFEBE3A4 \n"
"    LDR     R7, =table\n"
"    ADD     R12, R3, R3, LSL#1 \n"
"    LDR     R3, [R7, R12, LSL#2] \n"
"    ADD     R6, R7, #0x30 \n"
"    LDR     R8, [R6, R12, LSL#2] \n"
"    SUB     R3, LR, R3 \n"
"    CMP     R3, #0 \n"
"    SUB     LR, LR, R8 \n"
"    BLE     loc_FFDF42FC \n"
"    ADD     R12, R7, R12, LSL#2 \n"
"    LDR     LR, [R12, #4] \n"
"    CMP     LR, R3 \n"
"    ADDGE   R2, R2, #1 \n"
"    BGE     loc_FFDF42F0 \n"
"    LDR     R12, [R12, #8] \n"
"    CMP     R12, R3 \n"
"    ADDLT   R2, R2, #3 \n"
"    ADDGE   R2, R2, #2 \n"

"loc_FFDF42F0:\n"
"    CMP     R2, #0x1A \n"  // --> Patched. Old value = 0x17.
"    MOVGE   R2, #0x19 \n"  // --> Patched. Old value = 0x16.
"    B       loc_FFDF4330 \n"

"loc_FFDF42FC:\n"
"    CMP     LR, #0 \n"
"    BGE     loc_FFDF4330 \n"
"    ADD     R3, R6, R12, LSL#2 \n"
"    LDR     R12, [R3, #4] \n"
"    CMP     R12, LR \n"
"    SUBLE   R2, R2, #1 \n"
"    BLE     loc_FFDF4328 \n"
"    LDR     R3, [R3, #8] \n"
"    CMP     R3, LR \n"
"    SUBGT   R2, R2, #3 \n"
"    SUBLE   R2, R2, #2 \n"

"loc_FFDF4328:\n"
"    CMP     R2, #0 \n"
"    MOVLT   R2, #0 \n"

"loc_FFDF4330:\n"
"    CMP     R2, R5 \n"
"    STRNE   R2, [R4, #8] \n"
"    MOVNE   R2, #1 \n"
"    STRNE   R2, [R4, #0xC] \n"

"loc_FFDF4340:\n"
//"  LDR     R2, =0xFFEBE348 \n"  // Replaced by next instruction
"    LDR     R2, =CompressionRateTable\n"
"    LDR     R3, [R4, #8] \n"
"    LDR     R2, [R2, R3, LSL#2] \n"

"    LDR     R3, =video_mode\n"         // +
"    LDR     R3, [R3]\n"                // +
"    LDR     R3, [R3]\n"                // +
"    CMP     R3, #1\n"                  // +
"    LDREQ   R3, =video_quality\n"      // +
"    LDREQ   R3, [R3]\n"                // +
"    LDREQ   R2, [R3]\n"                // +

"    STR     R2, [R1] \n"
"    STR     R0, [R4] \n"
"    BL      mute_on_zoom\n"            // +
"    LDMFD   SP!, {R4-R8,PC} \n"
);
}
