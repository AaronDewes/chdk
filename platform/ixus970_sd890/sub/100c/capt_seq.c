/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1          // see stubs_entry.S

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFF85E03C - 0xFF85E2D4, length=167
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R9,LR} \n"
"    LDR     R6, =0x19EBC \n"
"    LDR     R5, =0x54E0 \n"
"    MOV     R9, #1 \n"
"    MOV     R7, #0 \n"

"loc_FF85E050:\n"
"    LDR     R0, [R5, #0xC] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_FF827D90 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF85E07C \n"
"    LDR     R1, =0x48E \n"
"    LDR     R0, =0xFF85DD14 \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R9,PC} \n"

"loc_FF85E07C:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x1B \n"
"    ADDLS   PC, PC, R1, LSL#2 \n"
"    B       loc_FF85E29C \n"
"    B       loc_FF85E100 \n"
"    B       loc_FF85E168 \n"
"    B       loc_FF85E170 \n"
"    B       loc_FF85E188 \n"
"    B       loc_FF85E17C \n"
"    B       loc_FF85E190 \n"
"    B       loc_FF85E198 \n"
"    B       loc_FF85E1A0 \n"
"    B       loc_FF85E1F8 \n"
"    B       loc_FF85E204 \n"
"    B       loc_FF85E20C \n"
"    B       loc_FF85E214 \n"
"    B       loc_FF85E21C \n"
"    B       loc_FF85E224 \n"
"    B       loc_FF85E22C \n"
"    B       loc_FF85E234 \n"
"    B       loc_FF85E23C \n"
"    B       loc_FF85E248 \n"
"    B       loc_FF85E250 \n"
"    B       loc_FF85E258 \n"
"    B       loc_FF85E260 \n"
"    B       loc_FF85E26C \n"
"    B       loc_FF85E274 \n"
"    B       loc_FF85E27C \n"
"    B       loc_FF85E284 \n"
"    B       loc_FF85E28C \n"
"    B       loc_FF85E294 \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E100:\n"
"    BL      sub_FF93C448 \n"
"    BL      shooting_expo_param_override\n"      // added
"    BL      sub_FF85C1C4 \n"
"    LDR     R0, [R6, #0x24] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF85E2A8 \n"
"    BL      sub_FF85D9E4 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R6, #0x24] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF85E148 \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF8610AC \n"
"    TST     R0, #1 \n"
"    STRNE   R9, [R5, #4] \n"
"    LDRNE   R0, [R4, #8] \n"
"    ORRNE   R0, R0, #0x40000000 \n"
"    STRNE   R0, [R4, #8] \n"
"    BNE     loc_FF85E2A8 \n"

"loc_FF85E148:\n"
"    BL      sub_FF95DEA0 \n"
"    BL      sub_FF86D198 \n"
"    STR     R0, [R4, #0x14] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF93DB30_my \n"  // --> Patched. Old value = 0xFF93DB30.
"    BL      capt_seq_hook_raw_here \n"         // added
"    TST     R0, #1 \n"
"    STRNE   R9, [R5, #4] \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E168:\n"
"    BL      sub_FF85E3C0_my \n"  // --> Patched. Old value = 0xFF85E3C0.
"    B       loc_FF85E180 \n"

"loc_FF85E170:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF93C5F0 \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E17C:\n"
"    BL      sub_FF93C0E0 \n"

"loc_FF85E180:\n"
"    STR     R7, [R6, #0x24] \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E188:\n"
"    BL      sub_FF93C414 \n"
"    B       loc_FF85E180 \n"

"loc_FF85E190:\n"
"    BL      sub_FF93C41C \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E198:\n"
"    BL      sub_FF93C510 \n"
"    B       loc_FF85E1FC \n"

"loc_FF85E1A0:\n"
"    LDR     R4, [R0, #0xC] \n"
"    BL      sub_FF93C424 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF93CC38 \n"
"    TST     R0, #1 \n"
"    MOV     R8, R0 \n"
"    BNE     loc_FF85E1E0 \n"
"    BL      sub_FF86D198 \n"
"    STR     R0, [R4, #0x14] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF93DA48 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF93DF9C \n"
"    MOV     R8, R0 \n"
"    LDR     R0, [R4, #0x14] \n"
"    BL      sub_FF86D3A4 \n"

"loc_FF85E1E0:\n"
"    BL      sub_FF93C414 \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #9 \n"
"    MOV     R0, R8 \n"
"    BL      sub_FF85C718 \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E1F8:\n"
"    BL      sub_FF93C570 \n"

"loc_FF85E1FC:\n"
"    BL      sub_FF85C1C4 \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E204:\n"
"    BL      sub_FF93C414 \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E20C:\n"
"    BL      sub_FF93CEA4 \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E214:\n"
"    BL      sub_FF93D08C \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E21C:\n"
"    BL      sub_FF93D11C \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E224:\n"
"    BL      sub_FF93D1D0 \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E22C:\n"
"    BL      sub_FF93D3C8 \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E234:\n"
"    BL      sub_FF93D418 \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E23C:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF93D49C \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E248:\n"
"    BL      sub_FF93D5EC \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E250:\n"
"    BL      sub_FF93D680 \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E258:\n"
"    BL      sub_FF93D748 \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E260:\n"
"    BL      sub_FF93C714 \n"
"    BL      sub_FF824C38 \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E26C:\n"
"    BL      sub_FF93D28C \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E274:\n"
"    BL      sub_FF93D2F8 \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E27C:\n"
"    BL      sub_FF93F558 \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E284:\n"
"    BL      sub_FF93F574 \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E28C:\n"
"    BL      sub_FF93F584 \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E294:\n"
"    BL      sub_FF93F5B0 \n"
"    B       loc_FF85E2A8 \n"

"loc_FF85E29C:\n"
"    LDR     R1, =0x58E \n"
"    LDR     R0, =0xFF85DD14 \n"
"    BL      _DebugAssert \n"

"loc_FF85E2A8:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R5, #8] \n"
"    BL      sub_FF827B0C /*_SetEventFlag*/ \n"
"    LDR     R4, [SP] \n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x10D \n"
"    LDREQ   R0, =0xFF85DD14 \n"
"    BLEQ    _DebugAssert \n"
"    STR     R7, [R4, #8] \n"
"    B       loc_FF85E050 \n"
);
}

/*************************************************************/
//** sub_FF93DB30_my @ 0xFF93DB30 - 0xFF93DBA0, length=29
void __attribute__((naked,noinline)) sub_FF93DB30_my() {
asm volatile (
"    STMFD   SP!, {R0-R10,LR} \n"
"    MOV     R6, #0 \n"
"    MOV     R4, R0 \n"
"    BL      sub_FF93E698 \n"
"    MVN     R1, #0 \n"
"    BL      sub_FF827B40 /*_ClearEventFlag*/ \n"
"    MOV     R2, #4 \n"
"    ADD     R1, SP, #8 \n"
"    MOV     R0, #0x8A \n"
"    BL      _PT_SetPropertyCaseString \n"
"    TST     R0, #1 \n"
"    MOVNE   R1, #0x218 \n"
"    LDRNE   R0, =0xFF93DD04 \n"
"    BLNE    _DebugAssert \n"
"    LDR     R8, =0x19F70 \n"
"    LDR     R5, =0x19EBC \n"
"    LDRSH   R1, [R8, #0xE] \n"
"    LDR     R0, [R5, #0x7C] \n"
"    BL      sub_FF9F4744 \n"
"    BL      _GetCCDTemperature \n"
"    LDR     R2, =0x91A8 \n"
"    ADD     R3, R4, #0x8C \n"
"    STRH    R0, [R4, #0x88] \n"
"    STRD    R2, [SP] \n"
"    MOV     R1, R0 \n"
"    LDRH    R0, [R5, #0x54] \n"
"    LDRSH   R2, [R8, #0xC] \n"
"    LDR     R3, =0x91A4 \n"
"    BL      sub_FF93EB8C \n"
"    BL      wait_until_remote_button_is_released\n" // added
"    BL      capt_seq_hook_set_nr\n"                 // added
"    LDR     PC, =0xFF93DBA4 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF85E3C0_my @ 0xFF85E3C0 - 0xFF85E434, length=30
void __attribute__((naked,noinline)) sub_FF85E3C0_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R4, [R0, #0xC] \n"
"    LDR     R6, =0x19EBC \n"
"    LDR     R0, [R4, #8] \n"
"    MOV     R5, #0 \n"
"    ORR     R0, R0, #1 \n"
"    STR     R0, [R4, #8] \n"
"    LDR     R0, [R6, #0x24] \n"
"    CMP     R0, #0 \n"
"    MOVEQ   R0, #2 \n"
"    BLEQ    sub_FF858330 \n"
"    BL      sub_FF93C424 \n"
"    LDR     R0, [R6, #0x24] \n"
"    CMP     R0, #0 \n"
"    BNE     sub_FF85E440 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF93C8B8 \n"
"    TST     R0, #1 \n"
"    MOVNE   R2, R4 \n"
"    LDMNEFD SP!, {R4-R6,LR} \n"
"    MOVNE   R1, #1 \n"
"    BNE     sub_FF85C718 \n"
"    BL      sub_FF95DEA0 \n"
"    BL      sub_FF86D198 \n"
"    STR     R0, [R4, #0x14] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF93DA48 \n"
"    BL      sub_FF93E520 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF93DB30 \n"
"    BL      capt_seq_hook_raw_here \n"         // added
"    LDR     PC, =0xFF85E438 \n"  // Continue in firmware
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF8B6864 - 0xFF8B6E58, length=382
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    SUB     SP, SP, #0x20 \n"
"    LDR     R8, =0xBB8 \n"
"    LDR     R7, =0x6E30 \n"
"    LDR     R5, =0x3E198 \n"
"    MOV     R0, #0 \n"
"    ADD     R6, SP, #0x10 \n"
"    STR     R0, [SP, #0xC] \n"

"loc_FF8B6884:\n"
"    LDR     R0, [R7, #0x20] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF827D90 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF8B68CC \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x13 \n"
"    CMPNE   R0, #0x14 \n"
"    CMPNE   R0, #0x15 \n"
"    BEQ     loc_FF8B69E8 \n"
"    CMP     R0, #0x27 \n"
"    BEQ     loc_FF8B69C0 \n"
"    ADD     R1, SP, #0xC \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8B6814 \n"

"loc_FF8B68CC:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x2C \n"
"    BNE     loc_FF8B68FC \n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FF8B7AD0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF827B0C /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x20 \n"
"    LDMFD   SP!, {R4-R8,PC} \n"

"loc_FF8B68FC:\n"
"    CMP     R1, #0x2B \n"
"    BNE     loc_FF8B6918 \n"
"    LDR     R2, [R0, #0x88]! \n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R0, R1 \n"
"    BLX     R2 \n"
"    B       loc_FF8B6E50 \n"

"loc_FF8B6918:\n"
"    CMP     R1, #0x25 \n"
"    BNE     loc_FF8B6968 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF827B40 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF8B329C \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF92F844 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R2, R8 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF827A44 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0xD1B \n"
"    BNE     loc_FF8B69AC \n"

"loc_FF8B6954:\n"
"    LDR     R1, [SP, #0x1C] \n"
"    LDR     R0, [R1, #0x8C] \n"
"    LDR     R1, [R1, #0x88] \n"
"    BLX     R1 \n"
"    B       loc_FF8B6E50 \n"

"loc_FF8B6968:\n"
"    CMP     R1, #0x26 \n"
"    BNE     loc_FF8B69B8 \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF8B6814 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF827B40 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF8B32AC \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF92FACC \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R2, R8 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF827A44 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8B6954 \n"
"    LDR     R1, =0xD25 \n"

"loc_FF8B69AC:\n"
"    LDR     R0, =0xFF8B399C \n"
"    BL      _DebugAssert \n"
"    B       loc_FF8B6954 \n"

"loc_FF8B69B8:\n"
"    CMP     R1, #0x27 \n"
"    BNE     loc_FF8B69D0 \n"

"loc_FF8B69C0:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF8B6814 \n"
"    B       loc_FF8B6954 \n"

"loc_FF8B69D0:\n"
"    CMP     R1, #0x2A \n"
"    BNE     loc_FF8B69E8 \n"
"    BL      sub_FF895C1C \n"
"    BL      sub_FF8969E8 \n"
"    BL      sub_FF89646C \n"
"    B       loc_FF8B6954 \n"

"loc_FF8B69E8:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R4, #1 \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x11 \n"
"    CMPNE   R1, #0x12 \n"
"    BNE     loc_FF8B6A58 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2-R4} \n"
"    STMIA   R6, {R2-R4} \n"
"    BL      sub_FF8B5328 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x88] \n"
"    LDR     R2, [R0, #0x8C] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FF8B7EA4 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x90] \n"
"    LDR     R2, [R0, #0x94] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    B       loc_FF8B6D90 \n"

"loc_FF8B6A58:\n"
"    CMP     R1, #0x13 \n"
"    CMPNE   R1, #0x14 \n"
"    CMPNE   R1, #0x15 \n"
"    BNE     loc_FF8B6B0C \n"
"    ADD     R3, SP, #0xC \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FF8B5570 \n"
"    CMP     R0, #1 \n"
"    MOV     R4, R0 \n"
"    CMPNE   R4, #5 \n"
"    BNE     loc_FF8B6AA8 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R2, R4 \n"
"    LDR     R1, [R0, #0x7C]! \n"
"    LDR     R12, [R0, #0xC]! \n"
"    LDR     R3, [R0, #4] \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    B       loc_FF8B6AE0 \n"

"loc_FF8B6AA8:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    CMP     R4, #2 \n"
"    LDR     R3, [R0, #0x8C] \n"
"    CMPNE   R4, #6 \n"
"    BNE     loc_FF8B6AF4 \n"
"    LDR     R12, [R0, #0x88] \n"
"    MOV     R0, SP \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #1 \n"
"    BLX     R12 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FF8B6528 \n"

"loc_FF8B6AE0:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R2, [SP, #0xC] \n"
"    MOV     R1, R4 \n"
"    BL      sub_FF8B67B4 \n"
"    B       loc_FF8B6D90 \n"

"loc_FF8B6AF4:\n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R12, [R0, #0x88] \n"
"    ADD     R0, R0, #4 \n"
"    MOV     R2, R4 \n"
"    BLX     R12 \n"
"    B       loc_FF8B6D90 \n"

"loc_FF8B6B0C:\n"
"    CMP     R1, #0x21 \n"
"    CMPNE   R1, #0x22 \n"
"    BNE     loc_FF8B6B58 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2-R4} \n"
"    STMIA   R6, {R2-R4} \n"
"    BL      sub_FF8B48B4 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x88] \n"
"    LDR     R2, [R0, #0x8C] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FF8B4BA4 \n"
"    B       loc_FF8B6D90 \n"

"loc_FF8B6B58:\n"
"    ADD     R1, R0, #4 \n"
"    LDMIA   R1, {R2,R3,R12} \n"
"    STMIA   R6, {R2,R3,R12} \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x24 \n"
"    ADDLS   PC, PC, R1, LSL#2 \n"
"    B       loc_FF8B6D70 \n"
"    B       loc_FF8B6C08 \n"
"    B       loc_FF8B6C08 \n"
"    B       loc_FF8B6C58 \n"
"    B       loc_FF8B6C60 \n"
"    B       loc_FF8B6C60 \n"
"    B       loc_FF8B6C60 \n"
"    B       loc_FF8B6C08 \n"
"    B       loc_FF8B6C58 \n"
"    B       loc_FF8B6C60 \n"
"    B       loc_FF8B6C60 \n"
"    B       loc_FF8B6C78 \n"
"    B       loc_FF8B6C78 \n"
"    B       loc_FF8B6D64 \n"
"    B       loc_FF8B6D6C \n"
"    B       loc_FF8B6D6C \n"
"    B       loc_FF8B6D6C \n"
"    B       loc_FF8B6D6C \n"
"    B       loc_FF8B6D70 \n"
"    B       loc_FF8B6D70 \n"
"    B       loc_FF8B6D70 \n"
"    B       loc_FF8B6D70 \n"
"    B       loc_FF8B6D70 \n"
"    B       loc_FF8B6C68 \n"
"    B       loc_FF8B6C70 \n"
"    B       loc_FF8B6C70 \n"
"    B       loc_FF8B6C84 \n"
"    B       loc_FF8B6C84 \n"
"    B       loc_FF8B6C8C \n"
"    B       loc_FF8B6CBC \n"
"    B       loc_FF8B6CEC \n"
"    B       loc_FF8B6D1C \n"
"    B       loc_FF8B6D4C \n"
"    B       loc_FF8B6D4C \n"
"    B       loc_FF8B6D70 \n"
"    B       loc_FF8B6D70 \n"
"    B       loc_FF8B6D54 \n"
"    B       loc_FF8B6D5C \n"

"loc_FF8B6C08:\n"
"    BL      sub_FF8B3784 \n"
"    B       loc_FF8B6D70 \n"

"loc_FF8B6C58:\n"
"    BL      sub_FF8B3A14 \n"
"    B       loc_FF8B6D70 \n"

"loc_FF8B6C60:\n"
"    BL      sub_FF8B3C18 \n"
"    B       loc_FF8B6D70 \n"

"loc_FF8B6C68:\n"
"    BL      sub_FF8B3E80 \n"
"    B       loc_FF8B6D70 \n"

"loc_FF8B6C70:\n"
"    BL      sub_FF8B4074 \n"
"    B       loc_FF8B6D70 \n"

"loc_FF8B6C78:\n"
"    BL      sub_FF8B42DC_my \n"  // --> Patched. Old value = 0xFF8B42DC.
"    MOV     R4, #0 \n"
"    B       loc_FF8B6D70 \n"

"loc_FF8B6C84:\n"
"    BL      sub_FF8B4418 \n"
"    B       loc_FF8B6D70 \n"

"loc_FF8B6C8C:\n"
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
"    BL      sub_FF8B7B44 \n"
"    B       loc_FF8B6D70 \n"

"loc_FF8B6CBC:\n"
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
"    BL      sub_FF8B7CC0 \n"
"    B       loc_FF8B6D70 \n"

"loc_FF8B6CEC:\n"
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
"    BL      sub_FF8B7D6C \n"
"    B       loc_FF8B6D70 \n"

"loc_FF8B6D1C:\n"
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
"    BL      sub_FF8B7E0C \n"
"    B       loc_FF8B6D70 \n"

"loc_FF8B6D4C:\n"
"    BL      sub_FF8B468C \n"
"    B       loc_FF8B6D70 \n"

"loc_FF8B6D54:\n"
"    BL      sub_FF8B4CA8 \n"
"    B       loc_FF8B6D70 \n"

"loc_FF8B6D5C:\n"
"    BL      sub_FF8B4EE0 \n"
"    B       loc_FF8B6D70 \n"

"loc_FF8B6D64:\n"
"    BL      sub_FF8B5058 \n"
"    B       loc_FF8B6D70 \n"

"loc_FF8B6D6C:\n"
"    BL      sub_FF8B51F0 \n"

"loc_FF8B6D70:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x88] \n"
"    LDR     R2, [R0, #0x8C] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    CMP     R4, #1 \n"
"    BNE     loc_FF8B6DD8 \n"

"loc_FF8B6D90:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R2, #0xC \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R0, R0, R1, LSL#2 \n"
"    SUB     R4, R0, #8 \n"
"    LDR     R0, =0x3E198 \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FFAAD774 \n"
"    LDR     R0, =0x3E1A4 \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FFAAD774 \n"
"    LDR     R0, =0x3E1B0 \n"
"    MOV     R2, #0xC \n"
"    MOV     R1, R4 \n"
"    BL      sub_FFAAD774 \n"
"    B       loc_FF8B6E50 \n"

"loc_FF8B6DD8:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0xB \n"
"    BNE     loc_FF8B6E20 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8B358C \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #0 \n"
"    B       loc_FF8B6E4C \n"

"loc_FF8B6E20:\n"
"    MOV     R3, #1 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #1 \n"
"    STR     R3, [SP] \n"
"    BL      sub_FF8B358C \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #1 \n"
"    STR     R3, [SP] \n"

"loc_FF8B6E4C:\n"
"    BL      sub_FF8B36CC \n"

"loc_FF8B6E50:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FF8B7AD0 \n"
"    B       loc_FF8B6884 \n"
);
}

/*************************************************************/
//** sub_FF8B42DC_my @ 0xFF8B42DC - 0xFF8B4398, length=48
void __attribute__((naked,noinline)) sub_FF8B42DC_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x6E30 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x3E \n"
"    BL      sub_FF827B40 /*_ClearEventFlag*/ \n"
"    LDRSH   R0, [R4, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF8B3320 \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8B342C \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF8B3484 \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_FF8B34DC \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    BL      sub_FF8B3534 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R4] \n"
"    LDR     R8, =0x3E1B0 \n"
"    CMP     R0, #0xB \n"
"    MOVEQ   R6, #0 \n"
"    MOVEQ   R5, #0 \n"
"    BEQ     loc_FF8B436C \n"
"    CMP     R6, #1 \n"
"    BNE     loc_FF8B436C \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xFF8B328C \n"
"    MOV     R2, #2 \n"
"    BL      sub_FF92F998 \n"
"    STRH    R0, [R4, #4] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    B       loc_FF8B4374 \n"

"loc_FF8B436C:\n"
"    LDRH    R0, [R8] \n"
"    STRH    R0, [R4, #4] \n"

"loc_FF8B4374:\n"
"    CMP     R5, #1 \n"
"    LDRNEH  R0, [R8, #8] \n"
"    BNE     loc_FF8B4390 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    MOV     R2, #0x20 \n"
"    LDR     R1, =0xFF8B3310 \n"
"    BL      sub_FF8B7B00 \n"

"loc_FF8B4390:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF895968_my \n"  // --> Patched. Old value = 0xFF895968.
"    LDR     PC, =0xFF8B439C \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF895968_my @ 0xFF895968 - 0xFF8959D0, length=27
void __attribute__((naked,noinline)) sub_FF895968_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x68EC \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R0, #1 \n"
"    LDRNE   R1, =0x16D \n"
"    LDRNE   R0, =0xFF895700 \n"
"    BLNE    _DebugAssert \n"
"    CMN     R4, #0xC00 \n"
"    LDREQSH R4, [R5, #2] \n"
"    CMN     R4, #0xC00 \n"
"    LDREQ   R1, =0x173 \n"
"    LDREQ   R0, =0xFF895700 \n"
"    STRH    R4, [R5, #2] \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    MOV     R4, R0 \n"
//"  BL      _sub_FF8C53CC \n"  // --> Nullsub call removed.
"    MOV     R0, R4 \n"
"    BL      sub_FF8C98BC \n"
"    TST     R0, #1 \n"
"    LDMNEFD SP!, {R4-R6,LR} \n"
"    MOVNE   R1, #0x178 \n"
"    LDRNE   R0, =0xFF895700 \n"
"    BNE     _DebugAssert \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}
