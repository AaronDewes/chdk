/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1          // see stubs_entry.S

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFF85F074 - 0xFF85F368, length=190
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R9,LR} \n"
"    LDR     R6, =0x2994 \n"
"    LDR     R4, =0x15140 \n"
"    MOV     R9, #1 \n"
"    MOV     R7, #0 \n"

"loc_FF85F088:\n"
"    LDR     R0, [R6, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_FF8269D4 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF85F0B4 \n"
"    LDR     R1, =0x588 \n"
"    LDR     R0, =0xFF85EC00 /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R9,PC} \n"

"loc_FF85F0B4:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x1D \n"
"    ADDLS   PC, PC, R1, LSL#2 \n"
"    B       loc_FF85F330 \n"
"    B       loc_FF85F140 \n"
"    B       loc_FF85F1A4 \n"
"    B       loc_FF85F1E0 \n"
"    B       loc_FF85F1F4 \n"
"    B       loc_FF85F1EC \n"
"    B       loc_FF85F1FC \n"
"    B       loc_FF85F204 \n"
"    B       loc_FF85F20C \n"
"    B       loc_FF85F264 \n"
"    B       loc_FF85F28C \n"
"    B       loc_FF85F270 \n"
"    B       loc_FF85F27C \n"
"    B       loc_FF85F284 \n"
"    B       loc_FF85F294 \n"
"    B       loc_FF85F29C \n"
"    B       loc_FF85F2A4 \n"
"    B       loc_FF85F2AC \n"
"    B       loc_FF85F2B4 \n"
"    B       loc_FF85F2C0 \n"
"    B       loc_FF85F2C8 \n"
"    B       loc_FF85F2D0 \n"
"    B       loc_FF85F2D8 \n"
"    B       loc_FF85F2E0 \n"
"    B       loc_FF85F2EC \n"
"    B       loc_FF85F2F4 \n"
"    B       loc_FF85F2FC \n"
"    B       loc_FF85F304 \n"
"    B       loc_FF85F30C \n"
"    B       loc_FF85F318 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F140:\n"
"    BL      sub_FF85F9A8 \n"

// only do quick press hack if overrides are active
"    BL      captseq_hack_override_active\n" // returns 1 if tv or sv override in effect
"    STR     R0,[SP,#-4]!\n" // push return value
"    BL      shooting_expo_param_override\n"      // added

"    BL      sub_FF85CEB0 \n"

"    LDR     R0, [SP], #4\n" // pop override hack
"    CMP     R0, #1\n"     // +
"    MOVEQ   R0, #0\n"     // +
"    STREQ   R0, [R4, #0x24]\n"  // fixes overrides behavior at short shutter press
"    LDRNE   R0, [R4, #0x24]\n" // modified NE
"    CMPNE   R0, #0\n"         // modified NE

//"  LDR     R0, [R4, #0x24] \n"  // above patch makes these lines redundant
//"  CMP     R0, #0 \n"
"    BEQ     loc_FF85F33C \n"
"    BL      sub_FF85E8DC \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R4, #0x24] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF85F188 \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF863AA0 \n"
"    TST     R0, #1 \n"
"    STRNE   R9, [R6, #0x10] \n"
"    LDRNE   R0, [R5, #8] \n"
"    ORRNE   R0, R0, #0x40000000 \n"
"    STRNE   R0, [R5, #8] \n"
"    BNE     loc_FF85F33C \n"

"loc_FF85F188:\n"
"    MOV     R0, R5 \n"
"    BL      sub_FF85EB80 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF926024_my \n"  // --> Patched. Old value = 0xFF926024.
"    TST     R0, #1 \n"
"    STRNE   R9, [R6, #0x10] \n"
"    B       loc_FF85F33C \n"

"loc_FF85F1A4:\n"
"    LDR     R0, [R4, #0x24] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF85F1D0 \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF863AA0 \n"
"    TST     R0, #1 \n"
"    LDRNE   R0, [SP] \n"
"    MOVNE   R1, #1 \n"
"    LDRNE   R2, [R0, #0xC] \n"
"    MOVNE   R0, #1 \n"
"    BNE     loc_FF85F25C \n"

"loc_FF85F1D0:\n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF85F454_my \n"  // --> Patched. Old value = 0xFF85F454.

"loc_FF85F1D8:\n"
"    STR     R7, [R4, #0x24] \n"
"    B       loc_FF85F33C \n"

"loc_FF85F1E0:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF85FBC0 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F1EC:\n"
"    BL      sub_FF85F5F0 \n"
"    B       loc_FF85F1D8 \n"

"loc_FF85F1F4:\n"
"    BL      sub_FF85F988 \n"
"    B       loc_FF85F1D8 \n"

"loc_FF85F1FC:\n"
"    BL      sub_FF85F990 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F204:\n"
"    BL      sub_FF85FAE0 \n"
"    B       loc_FF85F268 \n"

"loc_FF85F20C:\n"
"    LDR     R5, [R0, #0xC] \n"
"    BL      sub_FF85F998 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF924FEC \n"
"    TST     R0, #1 \n"
"    MOV     R8, R0 \n"
"    BNE     loc_FF85F24C \n"
"    BL      sub_FF86FE34 \n"
"    STR     R0, [R5, #0x18] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF925F3C \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF92642C \n"
"    MOV     R8, R0 \n"
"    LDR     R0, [R5, #0x18] \n"
"    BL      sub_FF870048 \n"

"loc_FF85F24C:\n"
"    BL      sub_FF85F988 \n"
"    MOV     R2, R5 \n"
"    MOV     R1, #9 \n"
"    MOV     R0, R8 \n"

"loc_FF85F25C:\n"
"    BL      sub_FF85D3DC \n"
"    B       loc_FF85F33C \n"

"loc_FF85F264:\n"
"    BL      sub_FF85FB40 \n"

"loc_FF85F268:\n"
"    BL      sub_FF85CEB0 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F270:\n"
"    LDR     R0, [R4, #0x54] \n"
"    BL      sub_FF85FF54 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F27C:\n"
"    BL      sub_FF8601FC \n"
"    B       loc_FF85F33C \n"

"loc_FF85F284:\n"
"    BL      sub_FF860290 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F28C:\n"
"    BL      sub_FF85F988 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F294:\n"
"    BL      sub_FF9251FC \n"
"    B       loc_FF85F33C \n"

"loc_FF85F29C:\n"
"    BL      sub_FF9253E4 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F2A4:\n"
"    BL      sub_FF925474 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F2AC:\n"
"    BL      sub_FF925528 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F2B4:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF92574C \n"
"    B       loc_FF85F33C \n"

"loc_FF85F2C0:\n"
"    BL      sub_FF925884 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F2C8:\n"
"    BL      sub_FF925914 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F2D0:\n"
"    BL      sub_FF9259D4 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F2D8:\n"
"    BL      sub_FF85FD40 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F2E0:\n"
"    BL      sub_FF85FDE0 \n"
"    BL      sub_FF8249F8 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F2EC:\n"
"    BL      sub_FF9255E4 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F2F4:\n"
"    BL      sub_FF925650 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F2FC:\n"
"    BL      sub_FF8621F0 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F304:\n"
"    BL      sub_FF862258 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F30C:\n"
"    BL      sub_FF8622B4 \n"
"    BL      sub_FF862274 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F318:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF926D10 \n"
"    LDRH    R0, [R4, #0x98] \n"
"    CMP     R0, #4 \n"
"    BLNE    sub_FF862520 \n"
"    B       loc_FF85F33C \n"

"loc_FF85F330:\n"
"    LDR     R1, =0x6C9 \n"
"    LDR     R0, =0xFF85EC00 /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF85F33C:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R6] \n"
"    BL      sub_FF867B98 /*_SetEventFlag*/ \n"
"    LDR     R5, [SP] \n"
"    LDR     R0, [R5, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x12B \n"
"    LDREQ   R0, =0xFF85EC00 /*'SsShootTask.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    STR     R7, [R5, #8] \n"
"    B       loc_FF85F088 \n"
);
}

/*************************************************************/
//** sub_FF926024_my @ 0xFF926024 - 0xFF9260CC, length=43
void __attribute__((naked,noinline)) sub_FF926024_my() {
asm volatile (
"    STMFD   SP!, {R0-R10,LR} \n"
"    MOV     R4, R0 \n"
"    BL      sub_FF926E80 \n"
"    MVN     R1, #0 \n"
"    BL      sub_FF867BCC /*_ClearEventFlag*/ \n"
"    LDR     R5, =0x6518 \n"
"    LDR     R0, [R5, #0x10] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF926074 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF82721C /*_CreateMessageQueueStrictly*/ \n"
"    STR     R0, [R5, #0x10] \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =0xFF925AC4 \n"
"    LDR     R0, =0xFF926374 /*'ShutterSoundTask'*/ \n"
"    MOV     R2, #0x400 \n"
"    MOV     R1, #0x17 \n"
"    BL      sub_FF8271E8 /*_CreateTaskStrictly*/ \n"

"loc_FF926074:\n"
"    MOV     R2, #4 \n"
"    ADD     R1, SP, #8 \n"
"    MOV     R0, #0x8A \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x3AE \n"
"    LDRNE   R0, =0xFF925D64 /*'SsCaptureSeq.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDR     R8, =0x15204 \n"
"    LDR     R7, =0x15140 \n"
"    LDRSH   R1, [R8, #0xE] \n"
"    LDR     R0, [R7, #0x8C] \n"
"    BL      sub_FF8E7114 \n"
"    BL      _GetCCDTemperature \n"
"    LDR     R3, =0x6520 \n"
"    STRH    R0, [R4, #0x9C] \n"
"    SUB     R2, R3, #4 \n"
"    STRD    R2, [SP] \n"
"    MOV     R1, R0 \n"
"    LDRH    R0, [R7, #0x5C] \n"
"    LDRSH   R2, [R8, #0xC] \n"
"    SUB     R3, R3, #8 \n"
"    BL      sub_FF928494 \n"
"    BL      wait_until_remote_button_is_released\n" // added
"    BL      capt_seq_hook_set_nr\n"                 // added
"    LDR     PC, =0xFF9260D0 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF85F454_my @ 0xFF85F454 - 0xFF85F558, length=66
void __attribute__((naked,noinline)) sub_FF85F454_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R4, [R0, #0xC] \n"
"    LDR     R6, =0x15140 \n"
"    LDR     R0, [R4, #8] \n"
"    MOV     R5, #0 \n"
"    ORR     R0, R0, #1 \n"
"    STR     R0, [R4, #8] \n"
"    LDR     R0, [R6, #0x24] \n"
"    CMP     R0, #0 \n"
"    MOVEQ   R0, #2 \n"
"    BLEQ    sub_FF85A5F8 \n"
"    BL      sub_FF85F998 \n"
"    LDR     R0, [R6, #0x24] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF85F518 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF926D10 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF85FCE8 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF924C3C \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF85F4D4 \n"
"    BL      sub_FF926D50 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF924D20 \n"
"    TST     R0, #1 \n"
"    MOVNE   R2, R4 \n"
"    LDMNEFD SP!, {R4-R6,LR} \n"
"    MOVNE   R1, #1 \n"
"    BNE     sub_FF85D3DC \n"
"    B       loc_FF85F4E0 \n"

"loc_FF85F4D4:\n"
"    MOV     R0, R4 \n"
"    BL      sub_FF924CBC \n"
"    BL      sub_FF926D50 \n"

"loc_FF85F4E0:\n"
"    MOV     R0, R4 \n"
"    BL      sub_FF85EB80 \n"
"    LDRH    R0, [R6] \n"
"    SUB     R12, R0, #0x8200 \n"
"    SUBS    R12, R12, #0xF \n"
"    LDREQ   R0, [R4, #0x18] \n"
"    BLEQ    sub_FF85A0DC \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF925F3C \n"
"    BL      sub_FF926BA0 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF926024_my \n"  // --> Patched. Old value = 0xFF926024.
"    MOV     R5, R0 \n"
"    B       loc_FF85F528 \n"

"loc_FF85F518:\n"
"    LDR     R0, =0x2994 \n"
"    LDR     R0, [R0, #0x10] \n"
"    CMP     R0, #0 \n"
"    MOVNE   R5, #0x1D \n"

"loc_FF85F528:\n"
"    BL      capt_seq_hook_raw_here\n"               // added
"    BL      sub_FF862258 \n"
"    BL      sub_FF8622A0 \n"
"    BL      sub_FF8622E0 \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF85D3DC \n"
"    BL      sub_FF9263D0 \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, [R4, #8] \n"
"    ORRNE   R0, R0, #0x2000 \n"
"    STRNE   R0, [R4, #8] \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF89DF1C - 0xFF89E4D4, length=367
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    SUB     SP, SP, #0x20 \n"
"    LDR     R8, =0xBB8 \n"
"    LDR     R7, =0x3FE8 \n"
"    LDR     R5, =0x19EA8 \n"
"    MOV     R0, #0 \n"
"    ADD     R6, SP, #0x10 \n"
"    STR     R0, [SP, #0xC] \n"

"loc_FF89DF3C:\n"
"    LDR     R0, [R7, #0x20] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF8269D4 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF89DF88 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x13 \n"
"    CMPNE   R0, #0x14 \n"
"    CMPNE   R0, #0x15 \n"
"    CMPNE   R0, #0x16 \n"
"    BEQ     loc_FF89E0A4 \n"
"    CMP     R0, #0x28 \n"
"    BEQ     loc_FF89E07C \n"
"    ADD     R1, SP, #0xC \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF89DECC \n"

"loc_FF89DF88:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x2D \n"
"    BNE     loc_FF89DFB8 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FF89F1D4 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF867B98 /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x20 \n"
"    LDMFD   SP!, {R4-R8,PC} \n"

"loc_FF89DFB8:\n"
"    CMP     R1, #0x2C \n"
"    BNE     loc_FF89DFD4 \n"
"    LDR     R2, [R0, #0x88]! \n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R0, R1 \n"
"    BLX     R2 \n"
"    B       loc_FF89E4CC \n"

"loc_FF89DFD4:\n"
"    CMP     R1, #0x26 \n"
"    BNE     loc_FF89E024 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF867BCC /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF89A830 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF919994 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R2, R8 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF867AD8 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0xDD2 \n"
"    BNE     loc_FF89E068 \n"

"loc_FF89E010:\n"
"    LDR     R1, [SP, #0x1C] \n"
"    LDR     R0, [R1, #0x8C] \n"
"    LDR     R1, [R1, #0x88] \n"
"    BLX     R1 \n"
"    B       loc_FF89E4CC \n"

"loc_FF89E024:\n"
"    CMP     R1, #0x27 \n"
"    BNE     loc_FF89E074 \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF89DECC \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF867BCC /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF89A840 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF919C1C \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R2, R8 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF867AD8 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF89E010 \n"
"    LDR     R1, =0xDDC \n"

"loc_FF89E068:\n"
"    LDR     R0, =0xFF89AE70 /*'ExpDrv.c'*/ \n"
"    BL      _DebugAssert \n"
"    B       loc_FF89E010 \n"

"loc_FF89E074:\n"
"    CMP     R1, #0x28 \n"
"    BNE     loc_FF89E08C \n"

"loc_FF89E07C:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF89DECC \n"
"    B       loc_FF89E010 \n"

"loc_FF89E08C:\n"
"    CMP     R1, #0x2B \n"
"    BNE     loc_FF89E0A4 \n"
"    BL      sub_FF88D3E8 \n"
"    BL      sub_FF88E074 \n"
"    BL      sub_FF88DBAC \n"
"    B       loc_FF89E010 \n"

"loc_FF89E0A4:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R4, #1 \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x11 \n"
"    CMPNE   R1, #0x12 \n"
"    BNE     loc_FF89E114 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2-R4} \n"
"    STMIA   R6, {R2-R4} \n"
"    BL      sub_FF89C908 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x88] \n"
"    LDR     R2, [R0, #0x8C] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FF89F58C \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x90] \n"
"    LDR     R2, [R0, #0x94] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    B       loc_FF89E40C \n"

"loc_FF89E114:\n"
"    CMP     R1, #0x13 \n"
"    CMPNE   R1, #0x14 \n"
"    CMPNE   R1, #0x15 \n"
"    CMPNE   R1, #0x16 \n"
"    BNE     loc_FF89E1CC \n"
"    ADD     R3, SP, #0xC \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FF89CB4C \n"
"    CMP     R0, #1 \n"
"    MOV     R4, R0 \n"
"    CMPNE   R4, #5 \n"
"    BNE     loc_FF89E168 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R2, R4 \n"
"    LDR     R1, [R0, #0x7C]! \n"
"    LDR     R12, [R0, #0xC]! \n"
"    LDR     R3, [R0, #4] \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    B       loc_FF89E1A0 \n"

"loc_FF89E168:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    CMP     R4, #2 \n"
"    LDR     R3, [R0, #0x8C] \n"
"    CMPNE   R4, #6 \n"
"    BNE     loc_FF89E1B4 \n"
"    LDR     R12, [R0, #0x88] \n"
"    MOV     R0, SP \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #1 \n"
"    BLX     R12 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FF89DBA8 \n"

"loc_FF89E1A0:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R2, [SP, #0xC] \n"
"    MOV     R1, R4 \n"
"    BL      sub_FF89DE6C \n"
"    B       loc_FF89E40C \n"

"loc_FF89E1B4:\n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R12, [R0, #0x88] \n"
"    ADD     R0, R0, #4 \n"
"    MOV     R2, R4 \n"
"    BLX     R12 \n"
"    B       loc_FF89E40C \n"

"loc_FF89E1CC:\n"
"    CMP     R1, #0x22 \n"
"    CMPNE   R1, #0x23 \n"
"    BNE     loc_FF89E218 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2-R4} \n"
"    STMIA   R6, {R2-R4} \n"
"    BL      sub_FF89BE94 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x88] \n"
"    LDR     R2, [R0, #0x8C] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FF89C184 \n"
"    B       loc_FF89E40C \n"

"loc_FF89E218:\n"
"    ADD     R1, R0, #4 \n"
"    LDMIA   R1, {R2,R3,R12} \n"
"    STMIA   R6, {R2,R3,R12} \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x25 \n"
"    ADDLS   PC, PC, R1, LSL#2 \n"
"    B       loc_FF89E3EC \n"
"    B       loc_FF89E2CC \n"
"    B       loc_FF89E2CC \n"
"    B       loc_FF89E2D4 \n"
"    B       loc_FF89E2DC \n"
"    B       loc_FF89E2DC \n"
"    B       loc_FF89E2DC \n"
"    B       loc_FF89E2CC \n"
"    B       loc_FF89E2D4 \n"
"    B       loc_FF89E2DC \n"
"    B       loc_FF89E2DC \n"
"    B       loc_FF89E2F4 \n"
"    B       loc_FF89E2F4 \n"
"    B       loc_FF89E3E0 \n"
"    B       loc_FF89E3E8 \n"
"    B       loc_FF89E3E8 \n"
"    B       loc_FF89E3E8 \n"
"    B       loc_FF89E3E8 \n"
"    B       loc_FF89E3EC \n"
"    B       loc_FF89E3EC \n"
"    B       loc_FF89E3EC \n"
"    B       loc_FF89E3EC \n"
"    B       loc_FF89E3EC \n"
"    B       loc_FF89E3EC \n"
"    B       loc_FF89E2E4 \n"
"    B       loc_FF89E2EC \n"
"    B       loc_FF89E2EC \n"
"    B       loc_FF89E300 \n"
"    B       loc_FF89E300 \n"
"    B       loc_FF89E308 \n"
"    B       loc_FF89E338 \n"
"    B       loc_FF89E368 \n"
"    B       loc_FF89E398 \n"
"    B       loc_FF89E3C8 \n"
"    B       loc_FF89E3C8 \n"
"    B       loc_FF89E3EC \n"
"    B       loc_FF89E3EC \n"
"    B       loc_FF89E3D0 \n"
"    B       loc_FF89E3D8 \n"

"loc_FF89E2CC:\n"
"    BL      sub_FF89AD1C \n"
"    B       loc_FF89E3EC \n"

"loc_FF89E2D4:\n"
"    BL      sub_FF89AF90 \n"
"    B       loc_FF89E3EC \n"

"loc_FF89E2DC:\n"
"    BL      sub_FF89B194 \n"
"    B       loc_FF89E3EC \n"

"loc_FF89E2E4:\n"
"    BL      sub_FF89B3FC \n"
"    B       loc_FF89E3EC \n"

"loc_FF89E2EC:\n"
"    BL      sub_FF89B5F0 \n"
"    B       loc_FF89E3EC \n"

"loc_FF89E2F4:\n"
"    BL      sub_FF89B880_my \n"  // --> Patched. Old value = 0xFF89B880.
"    MOV     R4, #0 \n"
"    B       loc_FF89E3EC \n"

"loc_FF89E300:\n"
"    BL      sub_FF89B9BC \n"
"    B       loc_FF89E3EC \n"

"loc_FF89E308:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x10] \n"
"    LDRH    R1, [R5, #2] \n"
"    STRH    R1, [SP, #0x12] \n"
"    LDRH    R1, [R5, #4] \n"
"    STRH    R1, [SP, #0x14] \n"
"    LDRH    R1, [R5, #6] \n"
"    STRH    R1, [SP, #0x16] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x18] \n"
"    BL      sub_FF89F248 \n"
"    B       loc_FF89E3EC \n"

"loc_FF89E338:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x10] \n"
"    LDRH    R1, [R5, #2] \n"
"    STRH    R1, [SP, #0x12] \n"
"    LDRH    R1, [R5, #4] \n"
"    STRH    R1, [SP, #0x14] \n"
"    LDRH    R1, [R5, #6] \n"
"    STRH    R1, [SP, #0x16] \n"
"    LDRH    R1, [R5, #8] \n"
"    STRH    R1, [SP, #0x18] \n"
"    BL      sub_FF89F3A8 \n"
"    B       loc_FF89E3EC \n"

"loc_FF89E368:\n"
"    LDRH    R1, [R5] \n"
"    STRH    R1, [SP, #0x10] \n"
"    LDRH    R1, [R0, #6] \n"
"    STRH    R1, [SP, #0x12] \n"
"    LDRH    R1, [R5, #4] \n"
"    STRH    R1, [SP, #0x14] \n"
"    LDRH    R1, [R5, #6] \n"
"    STRH    R1, [SP, #0x16] \n"
"    LDRH    R1, [R5, #8] \n"
"    STRH    R1, [SP, #0x18] \n"
"    BL      sub_FF89F454 \n"
"    B       loc_FF89E3EC \n"

"loc_FF89E398:\n"
"    LDRH    R1, [R5] \n"
"    STRH    R1, [SP, #0x10] \n"
"    LDRH    R1, [R5, #2] \n"
"    STRH    R1, [SP, #0x12] \n"
"    LDRH    R1, [R5, #4] \n"
"    STRH    R1, [SP, #0x14] \n"
"    LDRH    R1, [R5, #6] \n"
"    STRH    R1, [SP, #0x16] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x18] \n"
"    BL      sub_FF89F4F4 \n"
"    B       loc_FF89E3EC \n"

"loc_FF89E3C8:\n"
"    BL      sub_FF89BC5C \n"
"    B       loc_FF89E3EC \n"

"loc_FF89E3D0:\n"
"    BL      sub_FF89C288 \n"
"    B       loc_FF89E3EC \n"

"loc_FF89E3D8:\n"
"    BL      sub_FF89C4C0 \n"
"    B       loc_FF89E3EC \n"

"loc_FF89E3E0:\n"
"    BL      sub_FF89C638 \n"
"    B       loc_FF89E3EC \n"

"loc_FF89E3E8:\n"
"    BL      sub_FF89C7D0 \n"

"loc_FF89E3EC:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x88] \n"
"    LDR     R2, [R0, #0x8C] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    CMP     R4, #1 \n"
"    BNE     loc_FF89E454 \n"

"loc_FF89E40C:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R2, #0xC \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R0, R0, R1, LSL#2 \n"
"    SUB     R4, R0, #8 \n"
"    LDR     R0, =0x19EA8 \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FFAEBA48 \n"
"    LDR     R0, =0x19EB4 \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FFAEBA48 \n"
"    LDR     R0, =0x19EC0 \n"
"    MOV     R2, #0xC \n"
"    MOV     R1, R4 \n"
"    BL      sub_FFAEBA48 \n"
"    B       loc_FF89E4CC \n"

"loc_FF89E454:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0xB \n"
"    BNE     loc_FF89E49C \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF89AB24 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #0 \n"
"    B       loc_FF89E4C8 \n"

"loc_FF89E49C:\n"
"    MOV     R3, #1 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #1 \n"
"    STR     R3, [SP] \n"
"    BL      sub_FF89AB24 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #1 \n"
"    STR     R3, [SP] \n"

"loc_FF89E4C8:\n"
"    BL      sub_FF89AC64 \n"

"loc_FF89E4CC:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FF89F1D4 \n"
"    B       loc_FF89DF3C \n"
);
}

/*************************************************************/
//** sub_FF89B880_my @ 0xFF89B880 - 0xFF89B93C, length=48
void __attribute__((naked,noinline)) sub_FF89B880_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x3FE8 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x3E \n"
"    BL      sub_FF867BCC /*_ClearEventFlag*/ \n"
"    LDRSH   R0, [R4, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF89A8B4 \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF89A9C4 \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF89AA1C \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_FF89AA74 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    BL      sub_FF89AACC \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R4] \n"
"    LDR     R8, =0x19EC0 \n"
"    CMP     R0, #0xB \n"
"    MOVEQ   R6, #0 \n"
"    MOVEQ   R5, #0 \n"
"    BEQ     loc_FF89B910 \n"
"    CMP     R6, #1 \n"
"    BNE     loc_FF89B910 \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xFF89A820 \n"
"    MOV     R2, #2 \n"
"    BL      sub_FF919AE8 \n"
"    STRH    R0, [R4, #4] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    B       loc_FF89B918 \n"

"loc_FF89B910:\n"
"    LDRH    R0, [R8] \n"
"    STRH    R0, [R4, #4] \n"

"loc_FF89B918:\n"
"    CMP     R5, #1 \n"
"    LDRNEH  R0, [R8, #8] \n"
"    BNE     loc_FF89B934 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    LDR     R1, =0xFF89A8A4 \n"
"    MOV     R2, #0x20 \n"
"    BL      sub_FF89F204 \n"

"loc_FF89B934:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF88D158_my \n"  // --> Patched. Old value = 0xFF88D158.
"    LDR     PC, =0xFF89B940 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF88D158_my @ 0xFF88D158 - 0xFF88D1C0, length=27
void __attribute__((naked,noinline)) sub_FF88D158_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x3CE4 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R0, #1 \n"
"    MOVNE   R1, #0x140 \n"
"    LDRNE   R0, =0xFF88CF5C /*'Shutter.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    CMN     R4, #0xC00 \n"
"    LDREQSH R4, [R5, #2] \n"
"    CMN     R4, #0xC00 \n"
"    LDREQ   R1, =0x146 \n"
"    LDREQ   R0, =0xFF88CF5C /*'Shutter.c'*/ \n"
"    STRH    R4, [R5, #2] \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    MOV     R4, R0 \n"
//"  BL      _sub_FF8B374C \n"  // --> Nullsub call removed.
"    MOV     R0, R4 \n"
"    BL      sub_FF8B7BFC \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x14B \n"
"    LDMNEFD SP!, {R4-R6,LR} \n"
"    LDRNE   R0, =0xFF88CF5C /*'Shutter.c'*/ \n"
"    BNE     _DebugAssert \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}