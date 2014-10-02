/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

//From a2500 100a, by comparison to ixus140
static long *nrflag = (long*)(0xC144+0x4); // @ 0xffa96f28, 4th arg to  sub_ff9f5f68
#define PAUSE_FOR_FILE_COUNTER 200  // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFF87F1F4 - 0xFF87F484, length=165
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    LDR     R5, =0x38C18 \n"
"    LDR     R7, =0x3228 \n"
"    MOV     R6, #0 \n"

"loc_FF87F204:\n"
"    LDR     R0, [R7, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_003F7418 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF87F230 \n"
"    LDR     R1, =0x475 \n"
"    LDR     R0, =0xFF87ECCC /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_FF87F230:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x22 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF87F44C \n"
"    B       loc_FF87F2CC \n"
"    B       loc_FF87F2E4 \n"
"    B       loc_FF87F2F0 \n"
"    B       loc_FF87F304 \n"
"    B       loc_FF87F2FC \n"
"    B       loc_FF87F310 \n"
"    B       loc_FF87F318 \n"
"    B       loc_FF87F320 \n"
"    B       loc_FF87F32C \n"
"    B       loc_FF87F358 \n"
"    B       loc_FF87F338 \n"
"    B       loc_FF87F344 \n"
"    B       loc_FF87F34C \n"
"    B       loc_FF87F360 \n"
"    B       loc_FF87F368 \n"
"    B       loc_FF87F370 \n"
"    B       loc_FF87F378 \n"
"    B       loc_FF87F380 \n"
"    B       loc_FF87F38C \n"
"    B       loc_FF87F394 \n"
"    B       loc_FF87F39C \n"
"    B       loc_FF87F3A4 \n"
"    B       loc_FF87F3AC \n"
"    B       loc_FF87F3B4 \n"
"    B       loc_FF87F3BC \n"
"    B       loc_FF87F3C4 \n"
"    B       loc_FF87F3CC \n"
"    B       loc_FF87F3D4 \n"
"    B       loc_FF87F3E0 \n"
"    B       loc_FF87F3E8 \n"
"    B       loc_FF87F3F4 \n"
"    B       loc_FF87F42C \n"
"    B       loc_FF87F438 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F2CC:\n"
// "    BL      shooting_expo_iso_override\n"      // To do: Check if this is needed.
"    BL      sub_FF87F9B0 \n"
"    BL      shooting_expo_param_override\n"    // added
"    BL      sub_FF87CEA8 \n"
//To do: Check if this is needed.
//"    MOV     R0, #0\n"                          // added
//"    STR     R0, [R5,#0x28]\n"                  // added, fixes overrides behavior at short shutter press (from S95)
"    LDR     R0, [R5, #0x28] \n"
"    CMP     R0, #0 \n"
"    BLNE    sub_FF977D78_my \n"  // --> Patched. Old value = 0xFF977D78.
"    B       loc_FF87F458 \n"

"loc_FF87F2E4:\n"
"    LDR     R0, [R0, #0x10] \n"
"    BL      sub_FF977BF4_my \n"  // --> Patched. Old value = 0xFF977BF4.
"    B       loc_FF87F458 \n"

"loc_FF87F2F0:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF87FCD8 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F2FC:\n"
"    BL      sub_FF87F624 \n"
"    B       loc_FF87F308 \n"

"loc_FF87F304:\n"
"    BL      sub_FF87F98C \n"

"loc_FF87F308:\n"
"    STR     R6, [R5, #0x28] \n"
"    B       loc_FF87F458 \n"

"loc_FF87F310:\n"
"    BL      sub_FF87F994 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F318:\n"
"    BL      sub_FF87FBB0 \n"
"    B       loc_FF87F330 \n"

"loc_FF87F320:\n"
"    LDR     R0, [R0, #0x10] \n"
"    BL      sub_FF977E08 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F32C:\n"
"    BL      sub_FF87FC44 \n"

"loc_FF87F330:\n"
"    BL      sub_FF87CEA8 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F338:\n"
"    LDR     R0, [R5, #0x58] \n"
"    BL      sub_FF880220 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F344:\n"
"    BL      sub_FF88062C \n"
"    B       loc_FF87F458 \n"

"loc_FF87F34C:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF880690 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F358:\n"
"    BL      sub_FF87F98C \n"
"    B       loc_FF87F458 \n"

"loc_FF87F360:\n"
"    BL      sub_FF97710C \n"
"    B       loc_FF87F458 \n"

"loc_FF87F368:\n"
"    BL      sub_FF977344 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F370:\n"
"    BL      sub_FF977400 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F378:\n"
"    BL      sub_FF9774D4 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F380:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF977734 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F38C:\n"
"    BL      sub_FF977898 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F394:\n"
"    BL      sub_FF97792C \n"
"    B       loc_FF87F458 \n"

"loc_FF87F39C:\n"
"    BL      sub_FF9779D4 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F3A4:\n"
"    BL      sub_FF87FE38 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F3AC:\n"
"    BL      sub_FF87FEA4 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F3B4:\n"
"    BL      sub_FF9775A4 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F3BC:\n"
"    BL      sub_FF9775E4 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F3C4:\n"
"    BL      sub_FF882AA0 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F3CC:\n"
"    BL      sub_FF882B8C \n"
"    B       loc_FF87F458 \n"

"loc_FF87F3D4:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF977AE4 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F3E0:\n"
"    BL      sub_FF977B54 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F3E8:\n"
"    BL      sub_FF882D18 \n"
"    BL      sub_FF882BE4 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F3F4:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF97857C \n"
"    MOV     R0, #1 \n"
"    BL      sub_FF9786A4 \n"
"    LDR     R0, =0x38D18 \n"
"    LDRH    R0, [R0, #0x8C] \n"
"    CMP     R0, #4 \n"
"    LDRNEH  R0, [R5] \n"
"    SUBNE   R1, R0, #0x8000 \n"
"    SUBNES  R1, R1, #0x230 \n"
"    BNE     loc_FF87F458 \n"
"    BL      sub_FF882B8C \n"
"    BL      sub_FF883064 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F42C:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0xD \n"
"    B       loc_FF87F440 \n"

"loc_FF87F438:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0xC \n"

"loc_FF87F440:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF87D714 \n"
"    B       loc_FF87F458 \n"

"loc_FF87F44C:\n"
"    LDR     R1, =0x5DA \n"
"    LDR     R0, =0xFF87ECCC /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF87F458:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R7] \n"
"    BL      sub_003FAD9C /*_SetEventFlag*/ \n"
"    LDR     R4, [SP] \n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x116 \n"
"    LDREQ   R0, =0xFF87ECCC /*'SsShootTask.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    STR     R6, [R4, #8] \n"
"    B       loc_FF87F204 \n"
);
}

/*************************************************************/
//** sub_FF977D78_my @ 0xFF977D78 - 0xFF977E04, length=36
void __attribute__((naked,noinline)) sub_FF977D78_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF87E8E0 \n"
"    MOV     R4, R0 \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF884648 \n"
"    LDR     R6, =0x6FB4 \n"
"    TST     R0, #1 \n"
"    MOV     R5, #1 \n"
"    BNE     loc_FF977E00 \n"
"    BL      sub_FF87F99C \n"
"    BL      sub_FF8809A4 \n"
"    MOV     R1, R4 \n"
"    BL      sub_FF8809FC \n"
"    LDR     R0, =0x10E \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #0x30 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #0x34 \n"
"    MOV     R0, #0x2C \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #8 \n"
"    MOV     R0, #0x3F \n"
"    BL      _SetPropertyCase \n"
"    BL      sub_FF978864 \n"
"    MVN     R1, #0x1000 \n"
"    BL      sub_003FADD0 /*_ClearEventFlag*/ \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFA96E10 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFA97130_my \n"  // --> Patched. Old value = 0xFFA97130.
"    TST     R0, #1 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"

"loc_FF977E00:\n"
"    STR     R5, [R6] \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** sub_FF977BF4_my @ 0xFF977BF4 - 0xFF977D74, length=97
void __attribute__((naked,noinline)) sub_FF977BF4_my() {
asm volatile (
"    STMFD   SP!, {R2-R6,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, =0x6FB4 \n"
"    LDR     R6, =0x38C18 \n"
"    LDR     R0, [R0] \n"
"    MOV     R4, #0 \n"
"    CMP     R0, #0 \n"
"    MOVNE   R4, #0x1D \n"
"    BNE     loc_FF977D58 \n"
"    LDR     R0, [R6, #0x28] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF977D58 \n"
"    BL      sub_FF8809A4 \n"
"    MOV     R1, R5 \n"
"    BL      sub_FF8809FC \n"
"    LDR     R0, =0x10E \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x30 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x34 \n"
"    MOV     R0, #0x2C \n"
"    BL      _SetPropertyCase \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF884648 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF977C68 \n"
"    BL      sub_FF87D584 \n"
"    MOV     R4, #1 \n"

"loc_FF977C68:\n"
"    TST     R4, #1 \n"
"    BNE     loc_FF977D58 \n"
"    BL      sub_FF978864 \n"
"    MVN     R1, #0x1000 \n"
"    BL      sub_003FADD0 /*_ClearEventFlag*/ \n"
"    MOV     R0, R5 \n"
"    BL      sub_FFA96610 \n"
"    TST     R0, #1 \n"
"    MOV     R4, R0 \n"
"    BNE     loc_FF977D58 \n"
"    BL      sub_FF87F99C \n"
"    MOV     R0, R5 \n"
"    BL      sub_FFA96E10 \n"
"    LDR     R0, [R6, #0xA0] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF977D38 \n"
// To do: Check this, there are other paths:
// FF977D38 -> FFA97130
"    LDR     R0, =0x38D18 \n"
"    LDRH    R0, [R0, #0x8A] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R5, #8] \n"
"    CMPNE   R0, #1 \n"
"    BLS     loc_FF977CDC \n"
"    BL      sub_FF978864 \n"
"    MOV     R3, #0xDB \n"
"    STR     R3, [SP] \n"
"    LDR     R2, =0x3A98 \n"
"    LDR     R3, =0xFF977E9C /*'SsCaptureCtrl.c'*/ \n"
"    MOV     R1, #0x1000 \n"
"    BL      sub_FF8848B0 \n"

"loc_FF977CDC:\n"
"    MOV     R2, #4 \n"
"    ADD     R1, SP, #4 \n"
"    MOV     R0, #0x180 \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    MOVNE   R1, #0xDF \n"
"    LDRNE   R0, =0xFF977E9C /*'SsCaptureCtrl.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #4] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF977D18 \n"
"    BL      sub_FF978864 \n"
"    MOV     R1, #0x1000 \n"
"    BL      sub_003FAD9C /*_SetEventFlag*/ \n"
"    B       loc_FF977D38 \n"

"loc_FF977D18:\n"
"    BL      sub_FF978864 \n"
"    MOV     R1, #0x1000 \n"
"    BL      sub_003FADD0 /*_ClearEventFlag*/ \n"
"    LDR     R2, =0xFF977BE0 \n"
"    LDR     R0, [SP, #4] \n"
"    MOV     R3, #0x1000 \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF831E48 /*_SetTimerAfter*/ \n"

"loc_FF977D38:\n"
"    LDR     R0, [R6, #0xAC] \n"
"    CMP     R0, #0 \n"
"    MOV     R0, R5 \n"
"    BEQ     loc_FF977D50 \n"
"    BL      sub_FFA974E0 \n"
"    B       loc_FF977D54 \n"

"loc_FF977D50:\n"
"    BL      sub_FFA97130_my \n"  // --> Patched. Old value = 0xFFA97130.

"loc_FF977D54:\n"
"    BL      capt_seq_hook_raw_here \n"         // added
"    MOV     R4, R0 \n"

"loc_FF977D58:\n"
"    MOV     R2, R5 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF87D714 \n"
"    TST     R4, #1 \n"
"    MOVEQ   R0, #0 \n"
"    STREQ   R0, [R6, #0x28] \n"
"    LDMFD   SP!, {R2-R6,PC} \n"
);
}

/*************************************************************/
//** sub_FFA97130_my @ 0xFFA97130 - 0xFFA971B0, length=33
void __attribute__((naked,noinline)) sub_FFA97130_my() {
asm volatile (
"    STMFD   SP!, {R2-R8,LR} \n"
"    MOV     R4, R0 \n"
"    BL      sub_FFA96D8C \n"
"    BL      sub_FF978358 \n"
"    LDR     R8, =0x38C18 \n"
"    LDR     R0, [R8, #0x180] \n"
"    ADD     R5, R8, #0x100 \n"
"    CMP     R0, #2 \n"
"    BNE     loc_FFA9716C \n"
"    LDRH    R0, [R5, #0x8A] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    MOVLS   R0, #4 \n"
"    BLLS    sub_FF8FC348 \n"

"loc_FFA9716C:\n"
"    LDR     R0, =0x12F \n"
"    MOV     R2, #4 \n"
"    ADD     R1, SP, #4 \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    MOVNE   R1, #0x170 \n"
"    LDRNE   R0, =0xFFA97394 /*'SsStandardCaptureSeq.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #4] \n"
"    AND     R0, R0, #0xFF00 \n"
"    CMP     R0, #0x600 \n"
"    LDRNE   R0, =0xFFA96AC4 \n"
"    LDREQ   R0, =0xFFA970F8 \n"
"    MOVNE   R1, R4 \n"
"    MOVEQ   R1, #0 \n"
"    BL      sub_FF8AEB60 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFA96E98_my \n"  // --> Patched. Old value = 0xFFA96E98.
"    LDR     PC, =0xFFA971B4 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FFA96E98_my @ 0xFFA96E98 - 0xFFA96F30, length=39
void __attribute__((naked,noinline)) sub_FFA96E98_my() {
asm volatile (
"    STMFD   SP!, {R1-R7,LR} \n"
"    LDR     R5, =0x38DE8 \n"
"    LDR     R6, =0x38C18 \n"
"    MOV     R4, R0 \n"
"    LDR     R3, [R5] \n"
"    LDRSH   R2, [R5, #0xC] \n"
"    LDRSH   R1, [R5, #0xE] \n"
"    LDR     R0, [R6, #0x88] \n"
"    BL      sub_FF935D20 \n"
"    MOV     R2, #2 \n"
"    ADD     R1, SP, #8 \n"
"    MOV     R0, #0xFA \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x2E5 \n"
"    LDRNE   R0, =0xFFA96D64 /*'SsCaptureCommon.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDRSH   R0, [R5, #0xC] \n"
"    LDRSH   R1, [SP, #8] \n"
"    BL      sub_FF8F988C \n"
"    LDR     R0, [R6, #0xE4] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, =0x38D18 \n"
"    LDRNEH  R0, [R0, #0x8A] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    BHI     loc_FFA96F30 \n"
"    BL      _GetCCDTemperature \n"
"    LDR     R3, =0xC144 \n"
"    STRH    R0, [R4, #0xA0] \n"
"    SUB     R2, R3, #4 \n"
"    STRD    R2, [SP] \n"
"    MOV     R1, R0 \n"
"    LDRSH   R2, [R5, #0xC] \n"
"    LDRH    R0, [R6, #0x5E] \n"
"    ADD     R3, R3, #4 \n"
"    BL      sub_FF9F5F68 \n"

"loc_FFA96F30:\n"
"    BL      wait_until_remote_button_is_released\n" // added
"    BL      capt_seq_hook_set_nr\n"                 // added
"    LDRH    R0, [R4, #0xA0] \n"
"    LDR     PC, =0xFFA96F34 \n"  // Continue in firmware
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF8BBB70 - 0xFF8BC200, length=421
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    SUB     SP, SP, #0x2C \n"
"    LDR     R6, =0x4110 \n"
"    LDR     R7, =0xBB8 \n"
"    LDR     R4, =0x57FE8 \n"
"    MOV     R0, #0 \n"
"    ADD     R5, SP, #0x1C \n"
"    STR     R0, [SP, #0xC] \n"

"loc_FF8BBB90:\n"
"    LDR     R0, [R6, #0x20] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #0x28 \n"
"    BL      sub_003F7418 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF8BBBDC \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x14 \n"
"    CMPNE   R0, #0x15 \n"
"    CMPNE   R0, #0x16 \n"
"    CMPNE   R0, #0x17 \n"
"    BEQ     loc_FF8BBD3C \n"
"    CMP     R0, #0x2A \n"
"    BEQ     loc_FF8BBCC4 \n"
"    ADD     R1, SP, #0xC \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8BBB20 \n"

"loc_FF8BBBDC:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x30 \n"
"    BNE     loc_FF8BBC08 \n"
"    BL      sub_FF8BD0A4 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #1 \n"
"    BL      sub_003FAD9C /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x2C \n"
"    LDMFD   SP!, {R4-R9,PC} \n"

"loc_FF8BBC08:\n"
"    CMP     R1, #0x2F \n"
"    BNE     loc_FF8BBC24 \n"
"    LDR     R2, [R0, #0x8C]! \n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R0, R1 \n"
"    BLX     R2 \n"
"    B       loc_FF8BC1F8 \n"

"loc_FF8BBC24:\n"
"    CMP     R1, #0x28 \n"
"    BNE     loc_FF8BBC74 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_003FADD0 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF8B71E4 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF96D71C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_003FACDC /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x1664 \n"
"    BNE     loc_FF8BBD30 \n"

"loc_FF8BBC60:\n"
"    LDR     R1, [SP, #0x28] \n"
"    LDR     R0, [R1, #0x90] \n"
"    LDR     R1, [R1, #0x8C] \n"
"    BLX     R1 \n"
"    B       loc_FF8BC1F8 \n"

"loc_FF8BBC74:\n"
"    CMP     R1, #0x29 \n"
"    BNE     loc_FF8BBCBC \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF8BBB20 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_003FADD0 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF8B71F4 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF96D8BC \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_003FACDC /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8BBC60 \n"
"    LDR     R1, =0x166E \n"
"    B       loc_FF8BBD30 \n"

"loc_FF8BBCBC:\n"
"    CMP     R1, #0x2A \n"
"    BNE     loc_FF8BBCD4 \n"

"loc_FF8BBCC4:\n"
"    LDR     R0, [SP, #0x28] \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF8BBB20 \n"
"    B       loc_FF8BBC60 \n"

"loc_FF8BBCD4:\n"
"    CMP     R1, #0x2D \n"
"    BNE     loc_FF8BBCEC \n"
"    BL      sub_FF8A65D8 \n"
"    BL      sub_FF8A7394 \n"
"    BL      sub_FF8A6EA8 \n"
"    B       loc_FF8BBC60 \n"

"loc_FF8BBCEC:\n"
"    CMP     R1, #0x2E \n"
"    BNE     loc_FF8BBD3C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #4 \n"
"    BL      sub_003FADD0 /*_ClearEventFlag*/ \n"
"    LDR     R1, =0xFF8B7214 \n"
"    LDR     R0, =0xFFFFF400 \n"
"    MOV     R2, #4 \n"
"    BL      sub_FF8A6028 \n"
"    BL      sub_FF8A62B8 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #4 \n"
"    BL      sub_003FABF8 /*_WaitForAnyEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8BBC60 \n"
"    LDR     R1, =0x1696 \n"

"loc_FF8BBD30:\n"
"    LDR     R0, =0xFF8B7978 /*'ExpDrv.c'*/ \n"
"    BL      _DebugAssert \n"
"    B       loc_FF8BBC60 \n"

"loc_FF8BBD3C:\n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R8, #1 \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x12 \n"
"    CMPNE   R1, #0x13 \n"
"    BNE     loc_FF8BBDA4 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF8B9F30 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF8BD4C4 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x98] \n"
"    LDR     R3, [R0, #0x94] \n"
"    B       loc_FF8BC0BC \n"

"loc_FF8BBDA4:\n"
"    CMP     R1, #0x14 \n"
"    CMPNE   R1, #0x15 \n"
"    CMPNE   R1, #0x16 \n"
"    CMPNE   R1, #0x17 \n"
"    BNE     loc_FF8BBE5C \n"
"    ADD     R3, SP, #0xC \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF8BA194 \n"
"    CMP     R0, #1 \n"
"    MOV     R9, R0 \n"
"    CMPNE   R9, #5 \n"
"    BNE     loc_FF8BBDF8 \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, R9 \n"
"    LDR     R1, [R0, #0x7C]! \n"
"    LDR     R12, [R0, #0x10]! \n"
"    LDR     R3, [R0, #4] \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    B       loc_FF8BBE30 \n"

"loc_FF8BBDF8:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R9, #2 \n"
"    LDR     R3, [R0, #0x90] \n"
"    CMPNE   R9, #6 \n"
"    BNE     loc_FF8BBE44 \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF8BB794 \n"

"loc_FF8BBE30:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R2, [SP, #0xC] \n"
"    MOV     R1, R9 \n"
"    BL      sub_FF8BBAC0 \n"
"    B       loc_FF8BC0C4 \n"

"loc_FF8BBE44:\n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R12 \n"
"    B       loc_FF8BC0C4 \n"

"loc_FF8BBE5C:\n"
"    CMP     R1, #0x24 \n"
"    CMPNE   R1, #0x25 \n"
"    BNE     loc_FF8BBEA8 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF8B8F04 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF8B9348 \n"
"    B       loc_FF8BC0C4 \n"

"loc_FF8BBEA8:\n"
"    ADD     R1, R0, #4 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x28 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF8BC0AC \n"
"    B       loc_FF8BBF64 \n"
"    B       loc_FF8BBF64 \n"
"    B       loc_FF8BBF6C \n"
"    B       loc_FF8BBF74 \n"
"    B       loc_FF8BBF74 \n"
"    B       loc_FF8BBF74 \n"
"    B       loc_FF8BBF64 \n"
"    B       loc_FF8BBF6C \n"
"    B       loc_FF8BBF74 \n"
"    B       loc_FF8BBF74 \n"
"    B       loc_FF8BBF8C \n"
"    B       loc_FF8BBF8C \n"
"    B       loc_FF8BC098 \n"
"    B       loc_FF8BC0A0 \n"
"    B       loc_FF8BC0A0 \n"
"    B       loc_FF8BC0A0 \n"
"    B       loc_FF8BC0A0 \n"
"    B       loc_FF8BC0A8 \n"
"    B       loc_FF8BC0AC \n"
"    B       loc_FF8BC0AC \n"
"    B       loc_FF8BC0AC \n"
"    B       loc_FF8BC0AC \n"
"    B       loc_FF8BC0AC \n"
"    B       loc_FF8BC0AC \n"
"    B       loc_FF8BBF7C \n"
"    B       loc_FF8BBF84 \n"
"    B       loc_FF8BBF84 \n"
"    B       loc_FF8BBF84 \n"
"    B       loc_FF8BBF98 \n"
"    B       loc_FF8BBF98 \n"
"    B       loc_FF8BBFA0 \n"
"    B       loc_FF8BBFD8 \n"
"    B       loc_FF8BC010 \n"
"    B       loc_FF8BC048 \n"
"    B       loc_FF8BC080 \n"
"    B       loc_FF8BC080 \n"
"    B       loc_FF8BC0AC \n"
"    B       loc_FF8BC0AC \n"
"    B       loc_FF8BC088 \n"
"    B       loc_FF8BC090 \n"

"loc_FF8BBF64:\n"
"    BL      sub_FF8B77F8 \n"
"    B       loc_FF8BC0AC \n"

"loc_FF8BBF6C:\n"
"    BL      sub_FF8B7AB4 \n"
"    B       loc_FF8BC0AC \n"

"loc_FF8BBF74:\n"
"    BL      sub_FF8B7CE0 \n"
"    B       loc_FF8BC0AC \n"

"loc_FF8BBF7C:\n"
"    BL      sub_FF8B800C \n"
"    B       loc_FF8BC0AC \n"

"loc_FF8BBF84:\n"
"    BL      sub_FF8B8228 \n"
"    B       loc_FF8BC0AC \n"

"loc_FF8BBF8C:\n"
"    BL      sub_FF8B85E8_my \n"  // --> Patched. Old value = 0xFF8B85E8.
"    MOV     R8, #0 \n"
"    B       loc_FF8BC0AC \n"

"loc_FF8BBF98:\n"
"    BL      sub_FF8B872C \n"
"    B       loc_FF8BC0AC \n"

"loc_FF8BBFA0:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF8BD148 \n"
"    B       loc_FF8BC0AC \n"

"loc_FF8BBFD8:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF8BD2C0 \n"
"    B       loc_FF8BC0AC \n"

"loc_FF8BC010:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R0, #6] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF8BD378 \n"
"    B       loc_FF8BC0AC \n"

"loc_FF8BC048:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF8BD420 \n"
"    B       loc_FF8BC0AC \n"

"loc_FF8BC080:\n"
"    BL      sub_FF8B8CB4 \n"
"    B       loc_FF8BC0AC \n"

"loc_FF8BC088:\n"
"    BL      sub_FF8B944C \n"
"    B       loc_FF8BC0AC \n"

"loc_FF8BC090:\n"
"    BL      sub_FF8B9734 \n"
"    B       loc_FF8BC0AC \n"

"loc_FF8BC098:\n"
"    BL      sub_FF8B99F8 \n"
"    B       loc_FF8BC0AC \n"

"loc_FF8BC0A0:\n"
"    BL      sub_FF8B9BB8 \n"
"    B       loc_FF8BC0AC \n"

"loc_FF8BC0A8:\n"
"    BL      sub_FF8B9D24 \n"

"loc_FF8BC0AC:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    LDR     R3, [R0, #0x8C] \n"

"loc_FF8BC0BC:\n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"

"loc_FF8BC0C4:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x10 \n"
"    BEQ     loc_FF8BC0FC \n"
"    BGT     loc_FF8BC0EC \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #4 \n"
"    CMPNE   R0, #0xE \n"
"    BNE     loc_FF8BC130 \n"
"    B       loc_FF8BC0FC \n"

"loc_FF8BC0EC:\n"
"    CMP     R0, #0x13 \n"
"    CMPNE   R0, #0x17 \n"
"    CMPNE   R0, #0x1A \n"
"    BNE     loc_FF8BC130 \n"

"loc_FF8BC0FC:\n"
"    LDRSH   R0, [R4] \n"
"    CMN     R0, #0xC00 \n"
"    LDRNESH R1, [R4, #8] \n"
"    CMNNE   R1, #0xC00 \n"
"    STRNEH  R0, [SP, #0x1C] \n"
"    STRNEH  R1, [SP, #0x24] \n"
"    BNE     loc_FF8BC130 \n"
"    ADD     R0, SP, #0x10 \n"
"    BL      sub_FF8BD6D8 \n"
"    LDRH    R0, [SP, #0x10] \n"
"    STRH    R0, [SP, #0x1C] \n"
"    LDRH    R0, [SP, #0x18] \n"
"    STRH    R0, [SP, #0x24] \n"

"loc_FF8BC130:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R8, #1 \n"
"    BNE     loc_FF8BC180 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R0, R0, R1, LSL#2 \n"
"    SUB     R8, R0, #8 \n"
"    LDR     R0, =0x57FE8 \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_003FC550 \n"
"    LDR     R0, =0x57FF4 \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_003FC550 \n"
"    LDR     R0, =0x58000 \n"
"    MOV     R2, #0xC \n"
"    MOV     R1, R8 \n"
"    BL      sub_003FC550 \n"
"    B       loc_FF8BC1F8 \n"

"loc_FF8BC180:\n"
"    LDR     R0, [R0] \n"
"    MOV     R3, #1 \n"
"    CMP     R0, #0xB \n"
"    BNE     loc_FF8BC1C4 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8B75D8 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    B       loc_FF8BC1F4 \n"

"loc_FF8BC1C4:\n"
"    MOV     R2, #1 \n"
"    STRD    R2, [SP] \n"
"    MOV     R3, R2 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, R2 \n"
"    BL      sub_FF8B75D8 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, R3 \n"
"    STR     R3, [SP] \n"
"    STR     R3, [SP, #4] \n"

"loc_FF8BC1F4:\n"
"    BL      sub_FF8B7744 \n"

"loc_FF8BC1F8:\n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF8BD0A4 \n"
"    B       loc_FF8BBB90 \n"
);
}

/*************************************************************/
//** sub_FF8B85E8_my @ 0xFF8B85E8 - 0xFF8B86AC, length=50
void __attribute__((naked,noinline)) sub_FF8B85E8_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x4110 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x3E \n"
"    BL      sub_003FADD0 /*_ClearEventFlag*/ \n"
"    MOV     R2, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    MOV     R3, #1 \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF8B727C \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8B7438 \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF8B7490 \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_FF8B74E8 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF8B7540 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R4] \n"
"    LDR     R8, =0x58000 \n"
"    CMP     R0, #0xB \n"
"    MOVEQ   R6, #0 \n"
"    MOVEQ   R5, R6 \n"
"    BEQ     loc_FF8B8680 \n"
"    CMP     R6, #1 \n"
"    BNE     loc_FF8B8680 \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xFF8B71D4 \n"
"    MOV     R2, #2 \n"
"    BL      sub_FF96D7A0 \n"
"    STRH    R0, [R4, #4] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    B       loc_FF8B8688 \n"

"loc_FF8B8680:\n"
"    LDRH    R0, [R8] \n"
"    STRH    R0, [R4, #4] \n"

"loc_FF8B8688:\n"
"    CMP     R5, #1 \n"
"    LDRNEH  R0, [R8, #8] \n"
"    BNE     loc_FF8B86A4 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    LDR     R1, =0xFF8B7258 \n"
"    MOV     R2, #0x20 \n"
"    BL      sub_FF8BD104 \n"

"loc_FF8B86A4:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8A6324_my \n"  // --> Patched. Old value = 0xFF8A6324.
"    LDR     PC, =0xFF8B86B0 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF8A6324_my @ 0xFF8A6324 - 0xFF8A638C, length=27
void __attribute__((naked,noinline)) sub_FF8A6324_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x3D54 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R0, #1 \n"
"    MOVNE   R1, #0x154 \n"
"    LDRNE   R0, =0xFF8A615C /*'Shutter.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    CMN     R4, #0xC00 \n"
"    LDREQSH R4, [R5, #2] \n"
"    CMN     R4, #0xC00 \n"
"    LDREQ   R1, =0x15A \n"
"    LDREQ   R0, =0xFF8A615C /*'Shutter.c'*/ \n"
"    STRH    R4, [R5, #2] \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    MOV     R4, R0 \n"
//"  BL      _sub_FF8FBADC \n"  // --> Nullsub call removed.
"    MOV     R0, R4 \n"
"    BL      sub_FF902F6C \n"
"    TST     R0, #1 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"
"    LDMFD   SP!, {R4-R6,LR} \n"
"    LDR     R1, =0x15F \n"
"    LDR     R0, =0xFF8A615C /*'Shutter.c'*/ \n"
"    B       _DebugAssert \n"
);
}
