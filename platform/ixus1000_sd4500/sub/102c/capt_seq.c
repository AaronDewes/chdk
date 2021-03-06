/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1  // see stubs_entry.S
#define NR_AUTO (0)         // have to explictly reset value back to 0 to enable auto

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFF88365C - 0xFF8838CC, length=157
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    LDR     R7, =0x3474 \n"
"    LDR     R4, =0x3C5E4 \n"
"    MOV     R6, #0 \n"

"loc_FF88366C:\n"
"    LDR     R0, [R7, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_FF83AE20 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF883698 \n"
"    LDR     R1, =0x43F \n"
"    LDR     R0, =0xFF8831C8 /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_FF883698:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x1F \n"
"    ADDLS   PC, PC, R1, LSL#2 \n"
"    B       loc_FF883894 \n"
"    B       loc_FF88372C \n"
"    B       loc_FF883744 \n"
"    B       loc_FF88375C \n"
"    B       loc_FF883770 \n"
"    B       loc_FF883768 \n"
"    B       loc_FF88377C \n"
"    B       loc_FF883784 \n"
"    B       loc_FF88378C \n"
"    B       loc_FF883798 \n"
"    B       loc_FF8837C0 \n"
"    B       loc_FF8837A4 \n"
"    B       loc_FF8837B0 \n"
"    B       loc_FF8837B8 \n"
"    B       loc_FF8837C8 \n"
"    B       loc_FF8837D0 \n"
"    B       loc_FF8837D8 \n"
"    B       loc_FF8837E0 \n"
"    B       loc_FF8837E8 \n"
"    B       loc_FF8837F4 \n"
"    B       loc_FF8837FC \n"
"    B       loc_FF883804 \n"
"    B       loc_FF88380C \n"
"    B       loc_FF883814 \n"
"    B       loc_FF883820 \n"
"    B       loc_FF883828 \n"
"    B       loc_FF883830 \n"
"    B       loc_FF883838 \n"
"    B       loc_FF883840 \n"
"    B       loc_FF883848 \n"
"    B       loc_FF883850 \n"
"    B       loc_FF88385C \n"
"    B       loc_FF8838A0 \n"

"loc_FF88372C:\n"
"    BL      shooting_expo_iso_override\n"      // added
"    BL      sub_FF883DB4 \n"
"    BL      shooting_expo_param_override\n"    // added
"    BL      sub_FF880F50 \n"
"    MOV     R0, #0\n"                          // added
"    STR     R0, [R4,#0x24]\n"                  // added, fixes overrides behavior at short shutter press (from S95)
//"  LDR     R0, [R4, #0x24] \n"  // above patch makes these three lines redundant
//"  CMP     R0, #0 \n"
//"  BLNE    _sub_FF98AEA0 \n"
"    B       loc_FF8838A0 \n"

"loc_FF883744:\n"
"    LDRH    R1, [R4] \n"
"    SUB     R12, R1, #0x8200 \n"
"    SUBS    R12, R12, #0x2E \n"
"    LDRNE   R0, [R0, #0xC] \n"
"    BLNE    sub_FF98AC34_my \n"  // --> Patched. Old value = 0xFF98AC34.
"    B       loc_FF8838A0 \n"

"loc_FF88375C:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF884070 \n"
"    B       loc_FF8838A0 \n"

"loc_FF883768:\n"
"    BL      sub_FF883A54 \n"
"    B       loc_FF883774 \n"

"loc_FF883770:\n"
"    BL      sub_FF883D94 \n"

"loc_FF883774:\n"
"    STR     R6, [R4, #0x24] \n"
"    B       loc_FF8838A0 \n"

"loc_FF88377C:\n"
"    BL      sub_FF883D9C \n"
"    B       loc_FF8838A0 \n"

"loc_FF883784:\n"
"    BL      sub_FF883F74 \n"
"    B       loc_FF88379C \n"

"loc_FF88378C:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF98AF00 \n"
"    B       loc_FF8838A0 \n"

"loc_FF883798:\n"
"    BL      sub_FF883FE0 \n"

"loc_FF88379C:\n"
"    BL      sub_FF880F50 \n"
"    B       loc_FF8838A0 \n"

"loc_FF8837A4:\n"
"    LDR     R0, [R4, #0x54] \n"
"    BL      sub_FF8846DC \n"
"    B       loc_FF8838A0 \n"

"loc_FF8837B0:\n"
"    BL      sub_FF884A78 \n"
"    B       loc_FF8838A0 \n"

"loc_FF8837B8:\n"
"    BL      sub_FF884ADC \n"
"    B       loc_FF8838A0 \n"

"loc_FF8837C0:\n"
"    BL      sub_FF883D94 \n"
"    B       loc_FF8838A0 \n"

"loc_FF8837C8:\n"
"    BL      sub_FF98A280 \n"
"    B       loc_FF8838A0 \n"

"loc_FF8837D0:\n"
"    BL      sub_FF98A48C \n"
"    B       loc_FF8838A0 \n"

"loc_FF8837D8:\n"
"    BL      sub_FF98A530 \n"
"    B       loc_FF8838A0 \n"

"loc_FF8837E0:\n"
"    BL      sub_FF98A600 \n"
"    B       loc_FF8838A0 \n"

"loc_FF8837E8:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF98A860 \n"
"    B       loc_FF8838A0 \n"

"loc_FF8837F4:\n"
"    BL      sub_FF98A9BC \n"
"    B       loc_FF8838A0 \n"

"loc_FF8837FC:\n"
"    BL      sub_FF98AA60 \n"
"    B       loc_FF8838A0 \n"

"loc_FF883804:\n"
"    BL      sub_FF98AB40 \n"
"    B       loc_FF8838A0 \n"

"loc_FF88380C:\n"
"    BL      sub_FF884258 \n"
"    B       loc_FF8838A0 \n"

"loc_FF883814:\n"
"    BL      sub_FF884304 \n"
"    BL      sub_FF98BBC0 \n"
"    B       loc_FF8838A0 \n"

"loc_FF883820:\n"
"    BL      sub_FF98A6CC \n"
"    B       loc_FF8838A0 \n"

"loc_FF883828:\n"
"    BL      sub_FF98A734 \n"
"    B       loc_FF8838A0 \n"

"loc_FF883830:\n"
"    BL      sub_FF98BC90 \n"
"    B       loc_FF8838A0 \n"

"loc_FF883838:\n"
"    BL      sub_FF838C50 \n"
"    B       loc_FF8838A0 \n"

"loc_FF883840:\n"
"    BL      sub_FF886E18 \n"
"    B       loc_FF8838A0 \n"

"loc_FF883848:\n"
"    BL      sub_FF886EA0 \n"
"    B       loc_FF8838A0 \n"

"loc_FF883850:\n"
"    BL      sub_FF886EFC \n"
"    BL      sub_FF886EBC \n"
"    B       loc_FF8838A0 \n"

"loc_FF88385C:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF98B6FC \n"
"    MOV     R0, #1 \n"
"    BL      sub_FF98B82C \n"
"    LDRH    R0, [R4, #0x94] \n"
"    CMP     R0, #4 \n"
"    LDRNEH  R0, [R4] \n"
"    SUBNE   R12, R0, #0x8200 \n"
"    SUBNES  R12, R12, #0x2A \n"
"    BNE     loc_FF8838A0 \n"
"    BL      sub_FF886EA0 \n"
"    BL      sub_FF88740C \n"
"    BL      sub_FF88731C \n"
"    B       loc_FF8838A0 \n"

"loc_FF883894:\n"
"    LDR     R1, =0x591 \n"
"    LDR     R0, =0xFF8831C8 /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF8838A0:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R7] \n"
"    BL      sub_FF88DBB8 /*_SetEventFlag*/ \n"
"    LDR     R5, [SP] \n"
"    LDR     R0, [R5, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x115 \n"
"    LDREQ   R0, =0xFF8831C8 /*'SsShootTask.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    STR     R6, [R5, #8] \n"
"    B       loc_FF88366C \n"
);
}

/*************************************************************/
//** sub_FF98AC34_my @ 0xFF98AC34 - 0xFF98AE9C, length=155
void __attribute__((naked,noinline)) sub_FF98AC34_my() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    LDR     R5, =0x3C5E4 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #0x24] \n"
"    LDR     R6, =0x820C \n"
"    CMP     R0, #0 \n"
"    MOV     R7, #0 \n"
"    BNE     loc_FF98ACE0 \n"
"    LDR     R0, [R5, #0xB8] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF98ACBC \n"
"    LDRH    R0, [R5] \n"
"    CMP     R0, R6 \n"
"    LDRNEH  R0, [R5, #0x92] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #0xC] \n"
"    CMPNE   R0, #1 \n"
"    BLS     loc_FF98AC90 \n"
"    BL      sub_FF833020 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF98ACE0 \n"
"    BL      sub_FF8889F8 \n"
"    B       loc_FF98ACCC \n"

"loc_FF98AC90:\n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF888998 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF98ACE0 \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #1 \n"
"    BL      sub_FF881914 \n"
"    BL      sub_FF98B584 \n"
"    BL      sub_FF88163C \n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_FF98ACBC:\n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF888998 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF98ACE0 \n"

"loc_FF98ACCC:\n"
"    MOV     R2, R4 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #1 \n"
"    BL      sub_FF881914 \n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_FF98ACE0:\n"
"    LDR     R0, [R4, #8] \n"
"    ORR     R0, R0, #1 \n"
"    STR     R0, [R4, #8] \n"
"    LDRH    R0, [R5] \n"
"    CMP     R0, R6 \n"
"    BEQ     loc_FF98AD6C \n"
"    LDRH    R0, [R5, #0x92] \n"
"    CMP     R0, #3 \n"
"    BEQ     loc_FF98ADB4 \n"
"    LDR     R0, [R4, #0xC] \n"
"    CMP     R0, #1 \n"
"    BLS     loc_FF98AD78 \n"
"    LDRH    R0, [R5, #0x90] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF98ADB4 \n"
"    LDRH    R0, [R5, #0x8C] \n"
"    CMP     R0, #2 \n"
"    BNE     loc_FF98AD84 \n"
"    BL      sub_FF8843C8 \n"
"    LDRH    R0, [R5] \n"
"    CMP     R0, R6 \n"
"    BEQ     loc_FF98AD6C \n"
"    LDRH    R0, [R5, #0x92] \n"
"    CMP     R0, #3 \n"
"    BEQ     loc_FF98ADB4 \n"
"    LDR     R0, [R4, #0xC] \n"
"    CMP     R0, #1 \n"
"    BLS     loc_FF98AD78 \n"
"    LDRH    R0, [R5, #0x90] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF98ADB4 \n"
"    LDRH    R0, [R5, #0x8C] \n"
"    CMP     R0, #2 \n"
"    BEQ     loc_FF98ADB0 \n"
"    B       loc_FF98AD84 \n"

"loc_FF98AD6C:\n"
"    LDRH    R0, [R5, #0x92] \n"
"    CMP     R0, #3 \n"
"    BEQ     loc_FF98ADB4 \n"

"loc_FF98AD78:\n"
"    LDRH    R0, [R5, #0x90] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF98ADB4 \n"

"loc_FF98AD84:\n"
"    LDRH    R0, [R5, #0x8C] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF98ADB4 \n"
"    LDRH    R0, [R5] \n"
"    CMP     R0, R6 \n"
"    LDRNE   R0, [R4, #0xC] \n"
"    CMPNE   R0, #1 \n"
"    BLS     loc_FF98ADB4 \n"
"    LDR     R0, [R4, #0x10] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF98ADB4 \n"

"loc_FF98ADB0:\n"
"    BL      sub_FF98BCC8 \n"

"loc_FF98ADB4:\n"
"    BL      sub_FF98BC90 \n"
"    BL      sub_FF883DA4 \n"
"    LDR     R0, [R5, #0x24] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF98AE80 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAE2E88 \n"
"    TST     R0, #1 \n"
"    LDMNEFD SP!, {R3-R7,PC} \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAE3324 \n"
"    BL      sub_FF98B4C4 \n"
"    LDR     R0, [R5, #0xB8] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF98AE0C \n"
"    LDRH    R0, [R5] \n"
"    CMP     R0, R6 \n"
"    LDRNEH  R0, [R5, #0x92] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #0xC] \n"
"    CMPNE   R0, #1 \n"
"    BHI     loc_FF98AE14 \n"

"loc_FF98AE0C:\n"
"    MOV     R0, #2 \n"
"    BL      sub_FF87F4D0 \n"
"    BL      wait_until_remote_button_is_released\n"    // added
"    BL      capt_seq_hook_set_nr\n"                    // added

"loc_FF98AE14:\n"
"    LDRH    R0, [R5] \n"
"    SUB     R12, R0, #0x8200 \n"
"    SUBS    R12, R12, #0x2D \n"
"    BNE     loc_FF98AE70 \n"
"    MOV     R5, #1 \n"
"    MOV     R2, #2 \n"
"    ADD     R0, R2, #0x15C \n"
"    MOV     R1, SP \n"
"    STR     R5, [SP] \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    MOVNE   R1, #0xC3 \n"
"    LDRNE   R0, =0xFF98AFC4 /*'SsCaptureSeq.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDRH    R0, [SP] \n"
"    CMP     R0, #1 \n"
"    BLS     loc_FF98AE68 \n"
"    MOV     R0, R4 \n"
"    STR     R5, [R4, #0xE4] \n"
"    BL      sub_FFAE3DE4 \n"
"    B       loc_FF98AE78 \n"

"loc_FF98AE68:\n"
"    MOV     R0, #0 \n"
"    STR     R0, [R4, #0xE4] \n"

"loc_FF98AE70:\n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAE38D4_my \n"  // --> Patched. Old value = 0xFFAE38D4.

"loc_FF98AE78:\n"
"    MOV     R7, R0 \n"
"    B       loc_FF98AE90 \n"

"loc_FF98AE80:\n"
"    LDR     R0, =0x7C94 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0 \n"
"    MOVNE   R7, #0x1D \n"

"loc_FF98AE90:\n"
"    MOV     R1, R7 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAE2FDC \n"
"    LDMFD   SP!, {R3-R7,PC} \n"
);
}

/*************************************************************/
//** sub_FFAE38D4_my @ 0xFFAE38D4 - 0xFFAE3A98, length=114
void __attribute__((naked,noinline)) sub_FFAE38D4_my() {
asm volatile (
"    STMFD   SP!, {R2-R8,LR} \n"
"    MOV     R6, R0 \n"
"    BL      sub_FF98B9F0 \n"
"    MVN     R1, #0 \n"
"    BL      sub_FF88DBEC /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFFAE304C \n"
"    MOV     R1, R6 \n"
"    BL      sub_FF8C25D0 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FFAE2F14 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FFAE340C \n"
"    MOV     R4, R0 \n"
"    LDR     R1, =0xDDB8 \n"
"    MOV     R0, #0x8A \n"
"    MOV     R2, #4 \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x1F6 \n"
"    LDRNE   R0, =0xFFAE3AB8 /*'SsStandardCaptureSeq.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    BL      sub_FF886560 \n"
"    MOV     R0, R4 \n"
"    CMP     R0, #7 \n"
"    MOV     R4, #0 \n"
"    MOV     R5, #3 \n"
"    ADDLS   PC, PC, R0, LSL#2 \n"
"    B       loc_FFAE3A20 \n"
"    B       loc_FFAE3A20 \n"
"    B       loc_FFAE3964 \n"
"    B       loc_FFAE3974 \n"
"    B       loc_FFAE3998 \n"
"    B       loc_FFAE39B4 \n"
"    B       loc_FFAE39D0 \n"
"    B       loc_FFAE39E0 \n"
"    B       loc_FFAE3A00 \n"

"loc_FFAE3964:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF8C2600 \n"
"    STR     R4, [SP, #4] \n"
"    B       loc_FFAE3A10 \n"

"loc_FFAE3974:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF8C2600 \n"
"    MOV     R0, #1 \n"
"    STR     R0, [SP, #4] \n"
"    MOV     R0, R6 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FFAE3BA0 \n"

"loc_FFAE3990:\n"
"    BL      capt_seq_hook_raw_here\n"      // Test this...
"    MOV     R7, R0 \n"
"    B       loc_FFAE3A2C \n"

"loc_FFAE3998:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF8C2600 \n"
"    ADD     R1, SP, #4 \n"
"    MOV     R0, R6 \n"
"    STR     R4, [SP, #4] \n"
"    BL      sub_FFAE3710 \n"
"    B       loc_FFAE3990 \n"

"loc_FFAE39B4:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF8C2600 \n"
"    ADD     R1, SP, #4 \n"
"    MOV     R0, R6 \n"
"    STR     R5, [SP, #4] \n"
"    BL      sub_FFAE3C58 \n"
"    B       loc_FFAE3990 \n"

"loc_FFAE39D0:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF8C2600 \n"
"    STR     R5, [SP, #4] \n"
"    B       loc_FFAE39F0 \n"

"loc_FFAE39E0:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8C2600 \n"
"    MOV     R0, #5 \n"
"    STR     R0, [SP, #4] \n"

"loc_FFAE39F0:\n"
"    ADD     R1, SP, #4 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FFAE3830 \n"
"    B       loc_FFAE3990 \n"

"loc_FFAE3A00:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8C2600 \n"
"    MOV     R0, #4 \n"
"    STR     R0, [SP, #4] \n"

"loc_FFAE3A10:\n"
"    ADD     R1, SP, #4 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FFAE3694 \n"
"    B       loc_FFAE3990 \n"

"loc_FFAE3A20:\n"
"    MOV     R1, #0x22C \n"
"    LDR     R0, =0xFFAE3AB8 /*'SsStandardCaptureSeq.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FFAE3A2C:\n"
"    TST     R7, #1 \n"
"    MOVNE   R0, R7 \n"
"    BNE     loc_FFAE3A98 \n"
"    MOV     R1, #0 \n"
"    LDR     R0, =0xFFAE3604 \n"
"    BL      sub_FF8C25D0 \n"
"    LDR     R0, =0x3C5E4 \n"
"    LDRH    R0, [R0] \n"
"    SUB     R12, R0, #0x8000 \n"
"    SUBS    R12, R12, #0x20C \n"
"    BLEQ    sub_FF8ABA68 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FFAE34B4 \n"
"    BL      sub_FF98B9F0 \n"
"    MOV     R3, #0x244 \n"
"    STR     R3, [SP] \n"
"    LDR     R2, =0x3A98 \n"
"    LDR     R3, =0xFFAE3AB8 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOV     R1, #4 \n"
"    BL      sub_FF888D20 \n"
"    CMP     R0, #0 \n"
"    MOVNE   R1, #0x244 \n"
"    LDRNE   R0, =0xFFAE3AB8 /*'SsStandardCaptureSeq.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDRH    R0, [SP, #4] \n"
"    STRH    R0, [R6, #0x14] \n"
"    MOV     R0, #0 \n"

"loc_FFAE3A98:\n"
"    LDMFD   SP!, {R2-R8,PC} \n"
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF8CCAB4 - 0xFF8CD154, length=425
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    SUB     SP, SP, #0x20 \n"
"    LDR     R8, =0xBB8 \n"
"    LDR     R7, =0x4C6C \n"
"    LDR     R5, =0x58054 \n"
"    MOV     R0, #0 \n"
"    ADD     R6, SP, #0x10 \n"
"    STR     R0, [SP, #0xC] \n"

"loc_FF8CCAD4:\n"
"    LDR     R0, [R7, #0x20] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF83AE20 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF8CCB20 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x14 \n"
"    CMPNE   R0, #0x15 \n"
"    CMPNE   R0, #0x16 \n"
"    CMPNE   R0, #0x17 \n"
"    BEQ     loc_FF8CCC84 \n"
"    CMP     R0, #0x29 \n"
"    BEQ     loc_FF8CCC0C \n"
"    ADD     R1, SP, #0xC \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8CCA64 \n"

"loc_FF8CCB20:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x2F \n"
"    BNE     loc_FF8CCB50 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FF8CDE64 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF88DBB8 /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x20 \n"
"    LDMFD   SP!, {R4-R8,PC} \n"

"loc_FF8CCB50:\n"
"    CMP     R1, #0x2E \n"
"    BNE     loc_FF8CCB6C \n"
"    LDR     R2, [R0, #0x8C]! \n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R0, R1 \n"
"    BLX     R2 \n"
"    B       loc_FF8CD14C \n"

"loc_FF8CCB6C:\n"
"    CMP     R1, #0x27 \n"
"    BNE     loc_FF8CCBBC \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF88DBEC /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF8C8874 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF974480 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R2, R8 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF88DAF8 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x1089 \n"
"    BNE     loc_FF8CCC78 \n"

"loc_FF8CCBA8:\n"
"    LDR     R1, [SP, #0x1C] \n"
"    LDR     R0, [R1, #0x90] \n"
"    LDR     R1, [R1, #0x8C] \n"
"    BLX     R1 \n"
"    B       loc_FF8CD14C \n"

"loc_FF8CCBBC:\n"
"    CMP     R1, #0x28 \n"
"    BNE     loc_FF8CCC04 \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF8CCA64 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF88DBEC /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF8C8884 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF974E30 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R2, R8 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF88DAF8 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8CCBA8 \n"
"    LDR     R1, =0x1093 \n"
"    B       loc_FF8CCC78 \n"

"loc_FF8CCC04:\n"
"    CMP     R1, #0x29 \n"
"    BNE     loc_FF8CCC1C \n"

"loc_FF8CCC0C:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF8CCA64 \n"
"    B       loc_FF8CCBA8 \n"

"loc_FF8CCC1C:\n"
"    CMP     R1, #0x2C \n"
"    BNE     loc_FF8CCC34 \n"
"    BL      sub_FF8BA660 \n"
"    BL      sub_FF8BB27C \n"
"    BL      sub_FF8BADE8 \n"
"    B       loc_FF8CCBA8 \n"

"loc_FF8CCC34:\n"
"    CMP     R1, #0x2D \n"
"    BNE     loc_FF8CCC84 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #4 \n"
"    BL      sub_FF88DBEC /*_ClearEventFlag*/ \n"
"    LDR     R1, =0xFF8C88A4 \n"
"    LDR     R0, =0xFFFFF400 \n"
"    MOV     R2, #4 \n"
"    BL      sub_FF8BA0DC \n"
"    BL      sub_FF8BA364 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R2, R8 \n"
"    MOV     R1, #4 \n"
"    BL      sub_FF88DA14 /*_WaitForAnyEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8CCBA8 \n"
"    LDR     R1, =0x10BB \n"

"loc_FF8CCC78:\n"
"    LDR     R0, =0xFF8C8F74 /*'ExpDrv.c'*/ \n"
"    BL      _DebugAssert \n"
"    B       loc_FF8CCBA8 \n"

"loc_FF8CCC84:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R4, #1 \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x12 \n"
"    CMPNE   R1, #0x13 \n"
"    BNE     loc_FF8CCCF4 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2-R4} \n"
"    STMIA   R6, {R2-R4} \n"
"    BL      sub_FF8CB1EC \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FF8CE26C \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x94] \n"
"    LDR     R2, [R0, #0x98] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    B       loc_FF8CD088 \n"

"loc_FF8CCCF4:\n"
"    CMP     R1, #0x14 \n"
"    CMPNE   R1, #0x15 \n"
"    CMPNE   R1, #0x16 \n"
"    CMPNE   R1, #0x17 \n"
"    BNE     loc_FF8CCDAC \n"
"    ADD     R3, SP, #0xC \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FF8CB458 \n"
"    CMP     R0, #1 \n"
"    MOV     R4, R0 \n"
"    CMPNE   R4, #5 \n"
"    BNE     loc_FF8CCD48 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R2, R4 \n"
"    LDR     R1, [R0, #0x7C]! \n"
"    LDR     R12, [R0, #0x10]! \n"
"    LDR     R3, [R0, #4] \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    B       loc_FF8CCD80 \n"

"loc_FF8CCD48:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    CMP     R4, #2 \n"
"    LDR     R3, [R0, #0x90] \n"
"    CMPNE   R4, #6 \n"
"    BNE     loc_FF8CCD94 \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R0, SP \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #1 \n"
"    BLX     R12 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FF8CC7B0 \n"

"loc_FF8CCD80:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R2, [SP, #0xC] \n"
"    MOV     R1, R4 \n"
"    BL      sub_FF8CCA04 \n"
"    B       loc_FF8CD088 \n"

"loc_FF8CCD94:\n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R12, [R0, #0x8C] \n"
"    ADD     R0, R0, #4 \n"
"    MOV     R2, R4 \n"
"    BLX     R12 \n"
"    B       loc_FF8CD088 \n"

"loc_FF8CCDAC:\n"
"    CMP     R1, #0x23 \n"
"    CMPNE   R1, #0x24 \n"
"    BNE     loc_FF8CCDF8 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2-R4} \n"
"    STMIA   R6, {R2-R4} \n"
"    BL      sub_FF8CA260 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FF8CA6AC \n"
"    B       loc_FF8CD088 \n"

"loc_FF8CCDF8:\n"
"    ADD     R1, R0, #4 \n"
"    LDMIA   R1, {R2,R3,R12} \n"
"    STMIA   R6, {R2,R3,R12} \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x26 \n"
"    ADDLS   PC, PC, R1, LSL#2 \n"
"    B       loc_FF8CD068 \n"
"    B       loc_FF8CCEB0 \n"
"    B       loc_FF8CCEB0 \n"
"    B       loc_FF8CCEB8 \n"
"    B       loc_FF8CCEC0 \n"
"    B       loc_FF8CCEC0 \n"
"    B       loc_FF8CCEC0 \n"
"    B       loc_FF8CCEB0 \n"
"    B       loc_FF8CCEB8 \n"
"    B       loc_FF8CCEC0 \n"
"    B       loc_FF8CCEC0 \n"
"    B       loc_FF8CCED8 \n"
"    B       loc_FF8CCED8 \n"
"    B       loc_FF8CD054 \n"
"    B       loc_FF8CD05C \n"
"    B       loc_FF8CD05C \n"
"    B       loc_FF8CD05C \n"
"    B       loc_FF8CD05C \n"
"    B       loc_FF8CD064 \n"
"    B       loc_FF8CD068 \n"
"    B       loc_FF8CD068 \n"
"    B       loc_FF8CD068 \n"
"    B       loc_FF8CD068 \n"
"    B       loc_FF8CD068 \n"
"    B       loc_FF8CD068 \n"
"    B       loc_FF8CCEC8 \n"
"    B       loc_FF8CCED0 \n"
"    B       loc_FF8CCED0 \n"
"    B       loc_FF8CCEE4 \n"
"    B       loc_FF8CCEE4 \n"
"    B       loc_FF8CCEEC \n"
"    B       loc_FF8CCF24 \n"
"    B       loc_FF8CCFCC \n"
"    B       loc_FF8CD004 \n"
"    B       loc_FF8CD03C \n"
"    B       loc_FF8CD03C \n"
"    B       loc_FF8CD068 \n"
"    B       loc_FF8CD068 \n"
"    B       loc_FF8CD044 \n"
"    B       loc_FF8CD04C \n"

"loc_FF8CCEB0:\n"
"    BL      sub_FF8C8DB4 \n"
"    B       loc_FF8CD068 \n"

"loc_FF8CCEB8:\n"
"    BL      sub_FF8C90A4 \n"
"    B       loc_FF8CD068 \n"

"loc_FF8CCEC0:\n"
"    BL      sub_FF8C930C \n"
"    B       loc_FF8CD068 \n"

"loc_FF8CCEC8:\n"
"    BL      sub_FF8C95C0 \n"
"    B       loc_FF8CD068 \n"

"loc_FF8CCED0:\n"
"    BL      sub_FF8C97D8 \n"
"    B       loc_FF8CD068 \n"

"loc_FF8CCED8:\n"
"    BL      sub_FF8C9AFC_my \n"  // --> Patched. Old value = 0xFF8C9AFC.
"    MOV     R4, #0 \n"
"    B       loc_FF8CD068 \n"

"loc_FF8CCEE4:\n"
"    BL      sub_FF8C9C44 \n"
"    B       loc_FF8CD068 \n"

"loc_FF8CCEEC:\n"
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
"    LDRH    R1, [R5, #0xA] \n"
"    STRH    R1, [SP, #0x1A] \n"
"    BL      sub_FF8CDF64 \n"
"    B       loc_FF8CD068 \n"

"loc_FF8CCF24:\n"
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
"    LDRH    R1, [R5, #0xA] \n"
"    STRH    R1, [SP, #0x1A] \n"
"    BL      sub_FF8CE06C \n"
"    B       loc_FF8CD068 \n"

"loc_FF8CCFCC:\n"
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
"    LDRH    R1, [R5, #0xA] \n"
"    STRH    R1, [SP, #0x1A] \n"
"    BL      sub_FF8CE120 \n"
"    B       loc_FF8CD068 \n"

"loc_FF8CD004:\n"
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
"    LDRH    R1, [R5, #0xA] \n"
"    STRH    R1, [SP, #0x1A] \n"
"    BL      sub_FF8CE1C8 \n"
"    B       loc_FF8CD068 \n"

"loc_FF8CD03C:\n"
"    BL      sub_FF8CA038 \n"
"    B       loc_FF8CD068 \n"

"loc_FF8CD044:\n"
"    BL      sub_FF8CA7B0 \n"
"    B       loc_FF8CD068 \n"

"loc_FF8CD04C:\n"
"    BL      sub_FF8CAA4C \n"
"    B       loc_FF8CD068 \n"

"loc_FF8CD054:\n"
"    BL      sub_FF8CAC2C \n"
"    B       loc_FF8CD068 \n"

"loc_FF8CD05C:\n"
"    BL      sub_FF8CADE8 \n"
"    B       loc_FF8CD068 \n"

"loc_FF8CD064:\n"
"    BL      sub_FF8CAFE4 \n"

"loc_FF8CD068:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    CMP     R4, #1 \n"
"    BNE     loc_FF8CD0D0 \n"

"loc_FF8CD088:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R2, #0xC \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R0, R0, R1, LSL#2 \n"
"    SUB     R4, R0, #8 \n"
"    LDR     R0, =0x58054 \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FFB87404 \n"
"    LDR     R0, =0x58060 \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FFB87404 \n"
"    LDR     R0, =0x5806C \n"
"    MOV     R2, #0xC \n"
"    MOV     R1, R4 \n"
"    BL      sub_FFB87404 \n"
"    B       loc_FF8CD14C \n"

"loc_FF8CD0D0:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R3, #1 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0xB \n"
"    BNE     loc_FF8CD118 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8C8B94 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #0 \n"
"    B       loc_FF8CD148 \n"

"loc_FF8CD118:\n"
"    MOV     R2, #1 \n"
"    STRD    R2, [SP] \n"
"    MOV     R3, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #1 \n"
"    BL      sub_FF8C8B94 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #1 \n"
"    STR     R3, [SP] \n"
"    STR     R3, [SP, #4] \n"

"loc_FF8CD148:\n"
"    BL      sub_FF8C8CFC \n"

"loc_FF8CD14C:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FF8CDE64 \n"
"    B       loc_FF8CCAD4 \n"
);
}

/*************************************************************/
//** sub_FF8C9AFC_my @ 0xFF8C9AFC - 0xFF8C9BC4, length=51
void __attribute__((naked,noinline)) sub_FF8C9AFC_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x4C6C \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x3E \n"
"    BL      sub_FF88DBEC /*_ClearEventFlag*/ \n"
"    LDRSH   R0, [R4, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF8C88F8 \n"
"    MOV     R5, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8C8A08 \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF8C8A60 \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_FF8C8AB8 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF8C8B10 \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #0xE] \n"
"    BL      sub_FF8CDF04 \n"
"    LDR     R0, [R4] \n"
"    LDR     R8, =0x5806C \n"
"    CMP     R0, #0xB \n"
"    MOVEQ   R5, #0 \n"
"    MOVEQ   R6, #0 \n"
"    BEQ     loc_FF8C9B98 \n"
"    CMP     R5, #1 \n"
"    BNE     loc_FF8C9B98 \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xFF8C8864 \n"
"    MOV     R2, #2 \n"
"    BL      sub_FF9747DC \n"
"    STRH    R0, [R4, #4] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    B       loc_FF8C9BA0 \n"

"loc_FF8C9B98:\n"
"    LDRH    R0, [R8] \n"
"    STRH    R0, [R4, #4] \n"

"loc_FF8C9BA0:\n"
"    CMP     R6, #1 \n"
"    LDRNEH  R0, [R8, #8] \n"
"    BNE     loc_FF8C9BBC \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    LDR     R1, =0xFF8C88E8 \n"
"    MOV     R2, #0x20 \n"
"    BL      sub_FF8CDF20 \n"

"loc_FF8C9BBC:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8BA3D0_my \n"  // --> Patched. Old value = 0xFF8BA3D0.
"    LDR     PC, =0xFF8C9BC8 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF8BA3D0_my @ 0xFF8BA3D0 - 0xFF8BA410, length=17
void __attribute__((naked,noinline)) sub_FF8BA3D0_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x4934 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R0, #1 \n"
"    LDRNE   R1, =0x146 \n"
"    LDRNE   R0, =0xFF8BA1D4 /*'Shutter.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    CMN     R4, #0xC00 \n"
"    LDREQSH R4, [R5, #2] \n"
"    CMN     R4, #0xC00 \n"
"    MOVEQ   R1, #0x14C \n"
"    LDREQ   R0, =0xFF8BA1D4 /*'Shutter.c'*/ \n"
"    STRH    R4, [R5, #2] \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    LDR     PC, =0xFF8BA414 \n"  // Continue in firmware
);
}
