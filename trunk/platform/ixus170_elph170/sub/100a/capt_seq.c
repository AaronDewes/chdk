/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1 // see stubs_min.S

#define NR_AUTO (0)

//#define PAUSE_FOR_FILE_COUNTER 1000  // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFF88F788 - 0xFF88FA54, length=180
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    LDR     R5, =0x1D6B4 \n"
"    LDR     R7, =0x35C0 \n"
"    MOV     R6, #0 \n"

"loc_FF88F798:\n"
"    LDR     R0, [R7, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_FF829E30 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF88F7C8 \n"
"    LDR     R2, =0x443 \n"
"    LDR     R1, =0xFF88F0FC /*'SsShootTask.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_FF88F7C8:\n"
"    LDR     R0, [SP] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #0x23 \n"
"    CMPNE   R0, #0x19 \n"
"    BLNE    sub_FF99FA5C \n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x25 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF88FA18 \n"
"    B       loc_FF88F888 \n"
"    B       loc_FF88F8A0 \n"
"    B       loc_FF88F8AC \n"
"    B       loc_FF88F8C0 \n"
"    B       loc_FF88F8B8 \n"
"    B       loc_FF88F8CC \n"
"    B       loc_FF88F8D4 \n"
"    B       loc_FF88F8DC \n"
"    B       loc_FF88F8E8 \n"
"    B       loc_FF88F914 \n"
"    B       loc_FF88F8F4 \n"
"    B       loc_FF88F900 \n"
"    B       loc_FF88F908 \n"
"    B       loc_FF88F91C \n"
"    B       loc_FF88F924 \n"
"    B       loc_FF88F92C \n"
"    B       loc_FF88F934 \n"
"    B       loc_FF88F93C \n"
"    B       loc_FF88F948 \n"
"    B       loc_FF88F950 \n"
"    B       loc_FF88F958 \n"
"    B       loc_FF88F960 \n"
"    B       loc_FF88F968 \n"
"    B       loc_FF88F970 \n"
"    B       loc_FF88F978 \n"
"    B       loc_FF88F980 \n"
"    B       loc_FF88F98C \n"
"    B       loc_FF88F994 \n"
"    B       loc_FF88F99C \n"
"    B       loc_FF88F9A4 \n"
"    B       loc_FF88F9AC \n"
"    B       loc_FF88F9B8 \n"
"    B       loc_FF88F9C0 \n"
"    B       loc_FF88F9CC \n"
"    B       loc_FF88F9F8 \n"
"    B       loc_FF88FA04 \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F888:\n"
"    BL      shooting_expo_iso_override\n"      // added
"    BL      sub_FF88FFC4 \n"
"    BL      shooting_expo_param_override\n"    // added
"    BL      sub_FF88CD14 \n"
//To do: Check if this is needed.
//"    MOV     R0, #0\n"                          // added
//"    STR     R0, [R5,#0x28]\n"                  // added, fixes overrides behavior at short shutter press (from S95)
"    LDR     R0, [R5, #0x28] \n"
"    CMP     R0, #0 \n"
"    BLNE    sub_FF99E970_my \n"  // --> Patched. Old value = 0xFF99E970.
"    B       loc_FF88FA28 \n"

"loc_FF88F8A0:\n"
"    LDR     R0, [R0, #0x10] \n"
"    BL      sub_FF99E7A4_my \n"  // --> Patched. Old value = 0xFF99E7A4.
"    B       loc_FF88FA28 \n"

"loc_FF88F8AC:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF89031C \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F8B8:\n"
"    BL      sub_FF88FBFC \n"
"    B       loc_FF88F8C4 \n"

"loc_FF88F8C0:\n"
"    BL      sub_FF88FFA0 \n"

"loc_FF88F8C4:\n"
"    STR     R6, [R5, #0x28] \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F8CC:\n"
"    BL      sub_FF88FFA8 \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F8D4:\n"
"    BL      sub_FF8901E0 \n"
"    B       loc_FF88F8EC \n"

"loc_FF88F8DC:\n"
"    LDR     R0, [R0, #0x10] \n"
"    BL      sub_FF99EA58 \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F8E8:\n"
"    BL      sub_FF890274 \n"

"loc_FF88F8EC:\n"
"    BL      sub_FF88CD14 \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F8F4:\n"
"    LDR     R0, [R5, #0x54] \n"
"    BL      sub_FF8908E0 \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F900:\n"
"    BL      sub_FF890D34 \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F908:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF890D9C \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F914:\n"
"    BL      sub_FF88FFA0 \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F91C:\n"
"    BL      sub_FF99D300 \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F924:\n"
"    BL      sub_FF99D538 \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F92C:\n"
"    BL      sub_FF99D5F4 \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F934:\n"
"    BL      sub_FF99D6CC \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F93C:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF99D934 \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F948:\n"
"    BL      sub_FF99DA94 \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F950:\n"
"    BL      sub_FF896970 \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F958:\n"
"    BL      sub_FF89697C \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F960:\n"
"    BL      sub_FF99DB30 \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F968:\n"
"    BL      sub_FF99DBDC \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F970:\n"
"    BL      sub_FF890464 \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F978:\n"
"    MOV     R0, #0 \n"
"    B       loc_FF88F984 \n"

"loc_FF88F980:\n"
"    LDR     R0, [R0, #0xC] \n"

"loc_FF88F984:\n"
"    BL      sub_FF8904F4 \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F98C:\n"
"    BL      sub_FF99D79C \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F994:\n"
"    BL      sub_FF99D7DC \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F99C:\n"
"    BL      sub_FF893304 \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F9A4:\n"
"    BL      sub_FF8933F4 \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F9AC:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF99DCEC \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F9B8:\n"
"    BL      sub_FF99DD74 \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F9C0:\n"
"    BL      sub_FF893584 \n"
"    BL      sub_FF89344C \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F9CC:\n"
"    BL      sub_FF895620 \n"
"    LDR     R0, =0x1D7B4 \n"
"    LDRH    R0, [R0, #0x9C] \n"
"    CMP     R0, #4 \n"
"    LDRNEH  R0, [R5] \n"
"    SUBNE   R1, R0, #0x8200 \n"
"    SUBNES  R1, R1, #0x36 \n"
"    BNE     loc_FF88FA28 \n"
"    BL      sub_FF8933F4 \n"
"    BL      sub_FF89391C \n"
"    B       loc_FF88FA28 \n"

"loc_FF88F9F8:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0x11 \n"
"    B       loc_FF88FA0C \n"

"loc_FF88FA04:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0x10 \n"

"loc_FF88FA0C:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF88D82C \n"
"    B       loc_FF88FA28 \n"

"loc_FF88FA18:\n"
"    LDR     R2, =0x57B \n"
"    LDR     R1, =0xFF88F0FC /*'SsShootTask.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"

"loc_FF88FA28:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R7] \n"
"    BL      sub_FF829BC4 /*_SetEventFlag*/ \n"
"    LDR     R4, [SP] \n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0xFF88F0FC /*'SsShootTask.c'*/ \n"
"    MOVEQ   R2, #0x124 \n"
"    BLEQ    _DebugAssert \n"
"    STR     R6, [R4, #8] \n"
"    B       loc_FF88F798 \n"
);
}

/*************************************************************/
//** sub_FF99E970_my @ 0xFF99E970 - 0xFF99EA54, length=58
void __attribute__((naked,noinline)) sub_FF99E970_my() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    BL      sub_FF88ED08 \n"
"    MOV     R4, R0 \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF894F40 \n"
"    LDR     R6, =0x7790 \n"
"    TST     R0, #1 \n"
"    MOV     R5, #1 \n"
"    BNE     loc_FF99EA44 \n"
"    BL      sub_FF894F9C \n"
"    TST     R0, #1 \n"
"    BNE     loc_FF99EA44 \n"
"    MOV     R2, #2 \n"
"    MOV     R1, SP \n"
"    ADD     R0, R5, #0x108 \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    ADDNE   R2, R5, #0x174 \n"
"    LDRNE   R1, =0xFF99EAEC /*'SsCaptureCtrl.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    LDRSH   R0, [SP] \n"
"    BL      sub_FF82CB64 \n"
"    BL      sub_FF82C980 \n"
"    CMP     R0, #1 \n"
"    BLS     loc_FF99EA4C \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF82CAD8 \n"
"    BL      sub_FF88FFB0 \n"
"    BL      sub_FF8910E4 \n"
"    MOV     R1, R4 \n"
"    BL      sub_FF891140 \n"
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
"    BL      sub_FF99F248 \n"
"    MVN     R1, #0x1000 \n"
"    BL      sub_FF829C0C /*_ClearEventFlag*/ \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF99E468 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAD1A90_my \n"  // --> Patched. Old value = 0xFFAD1A90.
"    TST     R0, #1 \n"
"    BEQ     loc_FF99EA48 \n"

"loc_FF99EA44:\n"
"    STR     R5, [R6] \n"

"loc_FF99EA48:\n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_FF99EA4C:\n"
"    BL      sub_FF88D60C \n"
"    BL      sub_FF894FF8 \n"
"    LDMFD   SP!, {R3-R7,PC} \n"
);
}

/*************************************************************/
//** sub_FF99E7A4_my @ 0xFF99E7A4 - 0xFF99E96C, length=115
void __attribute__((naked,noinline)) sub_FF99E7A4_my() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    LDR     R7, =0x1D6B4 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R7, #0x28] \n"
"    MOV     R4, #0 \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF99E7F0 \n"
"    LDR     R0, =0x7790 \n"
"    MOV     R2, R5 \n"
"    LDR     R0, [R0] \n"
"    MOV     R1, #2 \n"
"    CMP     R0, #0 \n"
"    MOVNE   R4, #0x1D \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF88D82C \n"
"    MOV     R1, R4 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF99F7E4 \n"
"    B       loc_FF99E964 \n"

"loc_FF99E7F0:\n"
"    BL      sub_FF8910E4 \n"
"    MOV     R1, R5 \n"
"    BL      sub_FF891140 \n"
"    LDR     R0, =0x10E \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x30 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x34 \n"
"    MOV     R0, #0x2C \n"
"    BL      _SetPropertyCase \n"
"    LDR     R0, [R7, #0x104] \n"
"    LDR     R6, =0x1D7B4 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF99E844 \n"
"    LDRH    R0, [R6, #0x9A] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R5, #8] \n"
"    CMPNE   R0, #1 \n"
"    BHI     loc_FF99E874 \n"
"    B       loc_FF99E850 \n"

"loc_FF99E844:\n"
"    LDR     R0, [R5, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF99E874 \n"

"loc_FF99E850:\n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF894F40 \n"
"    TST     R0, #1 \n"
"    BNE     loc_FF99E86C \n"
"    BL      sub_FF894F9C \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF99E874 \n"

"loc_FF99E86C:\n"
"    BL      sub_FF88D60C \n"
"    MOV     R4, #1 \n"

"loc_FF99E874:\n"
"    TST     R4, #1 \n"
"    BNE     loc_FF99E948 \n"
"    LDR     R0, [R7, #0xE4] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF99E8B0 \n"
"    LDRH    R0, [R6, #0x9A] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R5, #8] \n"
"    CMPNE   R0, #1 \n"
"    BHI     loc_FF99E908 \n"
"    LDR     R0, [R7, #0x104] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, [R5, #0xC] \n"
"    CMPNE   R0, #1 \n"
"    BHI     loc_FF99E908 \n"

"loc_FF99E8B0:\n"
"    LDR     R0, =0x109 \n"
"    MOV     R2, #2 \n"
"    MOV     R1, SP \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    MOVNE   R2, #0xCA \n"
"    LDRNE   R1, =0xFF99EAEC /*'SsCaptureCtrl.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    LDRSH   R0, [SP] \n"
"    BL      sub_FF82CB64 \n"
"    BL      sub_FF82C980 \n"
"    CMP     R0, #1 \n"
"    BLS     loc_FF99E8F4 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF82CAD8 \n"
"    B       loc_FF99E908 \n"

"loc_FF99E8F4:\n"
"    BL      sub_FF88D60C \n"
"    BL      sub_FF894FF8 \n"
"    MOV     R4, #1 \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FF99E948 \n"

"loc_FF99E908:\n"
"    BL      sub_FF99F248 \n"
"    MVN     R1, #0x1000 \n"
"    BL      sub_FF829C0C /*_ClearEventFlag*/ \n"
"    MOV     R0, R5 \n"
"    BL      sub_FFAD16E8 \n"
"    TST     R0, #1 \n"
"    MOV     R4, R0 \n"
"    BNE     loc_FF99E948 \n"
"    BL      sub_FF88FFB0 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF99E468 \n"
"    MOV     R0, #2 \n"
"    BL      sub_FF896AFC \n"
"    MOV     R0, R5 \n"
"    BL      sub_FFAD1A90_my \n"  // --> Patched. Old value = 0xFFAD1A90.
"    B       loc_FF99E964 \n"

"loc_FF99E948:\n"
"    MOV     R2, R5 \n"
"    MOV     R1, #2 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF88D82C \n"
"    MOV     R1, R4 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF99F9F8 \n"

"loc_FF99E964:\n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    LDMFD   SP!, {R3-R7,PC} \n"
);
}

/*************************************************************/
//** sub_FFAD1A90_my @ 0xFFAD1A90 - 0xFFAD1D14, length=162
void __attribute__((naked,noinline)) sub_FFAD1A90_my() {
asm volatile (
"    STMFD   SP!, {R2-R10,LR} \n"
"    MOV     R4, R0 \n"
"    BL      sub_FF99E3D0 \n"
"    BL      sub_FF99F0A4 \n"
"    LDR     R7, =0x1D6B4 \n"
"    LDR     R0, [R7, #0x190] \n"
"    CMP     R0, #2 \n"
"    BNE     loc_FFAD1ACC \n"
"    ADD     R0, R7, #0x100 \n"
"    LDRH    R0, [R0, #0x9A] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    MOVLS   R0, #4 \n"
"    BLLS    sub_FF90D5E0 \n"

"loc_FFAD1ACC:\n"
"    LDR     R0, =0x12F \n"
"    MOV     R2, #4 \n"
"    ADD     R1, SP, #4 \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    LDRNE   R2, =0x191 \n"
"    LDRNE   R1, =0xFFAD1D3C /*'SsStandardCaptureSeq.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #4] \n"
"    AND     R0, R0, #0xFF00 \n"
"    CMP     R0, #0x600 \n"
"    LDRNE   R0, =0xFF99E064 \n"
"    LDREQ   R0, =0xFFAD1A0C \n"
"    MOVNE   R1, R4 \n"
"    MOVEQ   R1, #0 \n"
"    BL      sub_FF8CEDF4 \n"
"    LDR     R0, [R7, #0x184] \n"
"    CMP     R0, #0 \n"
"    BLNE    sub_FF99E2BC \n"
"    MOV     R0, #0 \n"
//"  BL      _sub_FF8923B8 \n"  // --> Nullsub call removed.
"    BL      wait_until_remote_button_is_released\n" // added
"    BL      capt_seq_hook_set_nr\n"                 // added
"    MOV     R0, R4 \n"
"    BL      sub_FF99E4F8 \n"
"    LDR     R1, =0xCFFC \n"
"    MOV     R2, #4 \n"
"    MOV     R0, #0x8A \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    LDRNE   R2, =0x1A5 \n"
"    LDRNE   R1, =0xFFAD1D3C /*'SsStandardCaptureSeq.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    BL      sub_FF892574 \n"
"    BL      sub_FF87F6F4 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAD1A10 \n"
"    MOV     R6, R0 \n"
"    LDR     R0, [SP, #4] \n"
"    LDR     R8, =0xCFFC \n"
"    AND     R0, R0, #0xFF00 \n"
"    CMP     R0, #0x600 \n"
"    LDRH    R0, [R4, #0x18] \n"
"    LDRNE   R2, =0xFF99E2A4 \n"
"    LDREQ   R2, =0xFF99E210 \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFAD1B9C \n"
"    CMP     R0, #1 \n"
"    BEQ     loc_FFAD1BC0 \n"
"    CMP     R0, #4 \n"
"    BNE     loc_FFAD1C34 \n"

"loc_FFAD1B9C:\n"
"    STR     R6, [SP] \n"
"    MOV     R3, R2 \n"
"    LDR     R1, [R4, #0x34] \n"
"    LDR     R2, [R8] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF99DE78 \n"
"    MOV     R5, R0 \n"
"    BL      sub_FF8CBCD8 \n"
"    B       loc_FFAD1C48 \n"

"loc_FFAD1BC0:\n"
"    STR     R6, [SP] \n"
"    MOV     R3, R2 \n"
"    LDR     R1, [R4, #0x34] \n"
"    LDR     R2, [R8] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF99DF04 \n"
"    MOV     R5, R0 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, #0x45 \n"
"    BL      sub_FF834034 \n"
"    TST     R5, #1 \n"
"    BNE     loc_FFAD1C48 \n"
"    LDR     R0, =0xFFAD1A0C \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF8CEDF4 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAD1A10 \n"
"    MOV     R6, R0 \n"
"    LDR     R0, [R8] \n"
"    BL      sub_FF99E354 \n"
"    LDR     R1, [R4, #0x34] \n"
"    LDR     R2, [R8] \n"
"    MOV     R3, R6 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF99DF9C \n"
"    MOV     R5, R0 \n"
"    BL      sub_FF99DE00 \n"
"    B       loc_FFAD1C48 \n"

"loc_FFAD1C34:\n"
"    MOV     R2, #0x1D8 \n"
"    LDR     R1, =0xFFAD1D3C /*'SsStandardCaptureSeq.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"
"    MOV     R5, #0x1D \n"

"loc_FFAD1C48:\n"
"    BL      sub_FF87F70C \n"
"    LDR     R8, =0xFFAD1A0C \n"
"    TST     R5, #1 \n"
"    BNE     loc_FFAD1CC8 \n"
"    LDR     R0, [R7, #0x100] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FFAD1C80 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF99FFE8 \n"
"    TST     R0, #1 \n"
"    LDRNE   R2, =0x1FD \n"
"    LDRNE   R1, =0xFFAD1D3C /*'SsStandardCaptureSeq.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    BL      capt_seq_hook_raw_here \n"         // added

"loc_FFAD1C80:\n"
"    MOV     R0, R4 \n"
"    BL      sub_FF99E5E0 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF99E598 \n"
"    CMP     R6, R8 \n"
"    BEQ     loc_FFAD1CC8 \n"
"    BL      sub_FF99F248 \n"
"    LDR     R9, =0x20A \n"
"    LDR     R2, =0x3A98 \n"
"    LDR     R3, =0xFFAD1D3C /*'SsStandardCaptureSeq.c'*/ \n"
"    MOV     R1, #4 \n"
"    STR     R9, [SP] \n"
"    BL      sub_FF895224 \n"
"    CMP     R0, #0 \n"
"    MOVNE   R2, R9 \n"
"    LDRNE   R1, =0xFFAD1D3C /*'SsStandardCaptureSeq.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"

"loc_FFAD1CC8:\n"
"    MOV     R2, R4 \n"
"    MOV     R1, #2 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF88D82C \n"
"    LDR     R0, [R7, #0x28] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFAD1CFC \n"
"    SUBS    R1, R6, R8 \n"
"    MOVNE   R1, #1 \n"
"    MOV     R2, R5 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF99F77C \n"
"    B       loc_FFAD1D10 \n"

"loc_FFAD1CFC:\n"
"    SUBS    R1, R6, R8 \n"
"    MOVNE   R1, #1 \n"
"    MOV     R2, R5 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF99F710 \n"

"loc_FFAD1D10:\n"
"    MOV     R0, R5 \n"
"    LDMFD   SP!, {R2-R10,PC} \n"
"    .ltorg\n"         // added
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF8DD134 - 0xFF8DD7D0, length=424
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    SUB     SP, SP, #0x2C \n"
"    LDR     R6, =0x447C \n"
"    LDR     R7, =0xBB8 \n"
"    LDR     R4, =0x5A4B4 \n"
"    MOV     R0, #0 \n"
"    ADD     R5, SP, #0x1C \n"
"    STR     R0, [SP, #0xC] \n"

"loc_FF8DD154:\n"
"    LDR     R0, [R6, #0x20] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #0x28 \n"
"    BL      sub_FF829E30 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF8DD1A4 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x14 \n"
"    CMPNE   R0, #0x15 \n"
"    CMPNE   R0, #0x16 \n"
"    CMPNE   R0, #0x17 \n"
"    CMPNE   R0, #0x18 \n"
"    BEQ     loc_FF8DD308 \n"
"    CMP     R0, #0x2E \n"
"    BEQ     loc_FF8DD28C \n"
"    ADD     R1, SP, #0xC \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8DD0D4 \n"

"loc_FF8DD1A4:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x34 \n"
"    BNE     loc_FF8DD1D0 \n"
"    BL      sub_FF8DE974 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF829BC4 /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x2C \n"
"    LDMFD   SP!, {R4-R9,PC} \n"

"loc_FF8DD1D0:\n"
"    CMP     R1, #0x33 \n"
"    BNE     loc_FF8DD1EC \n"
"    LDR     R2, [R0, #0xAC]! \n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R0, R1 \n"
"    BLX     R2 \n"
"    B       loc_FF8DD7C8 \n"

"loc_FF8DD1EC:\n"
"    CMP     R1, #0x2C \n"
"    BNE     loc_FF8DD23C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF829C0C /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF8D84D8 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF88799C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF829AF8 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R2, =0x1798 \n"
"    BNE     loc_FF8DD2F8 \n"

"loc_FF8DD228:\n"
"    LDR     R1, [SP, #0x28] \n"
"    LDR     R0, [R1, #0xB0] \n"
"    LDR     R1, [R1, #0xAC] \n"
"    BLX     R1 \n"
"    B       loc_FF8DD7C8 \n"

"loc_FF8DD23C:\n"
"    CMP     R1, #0x2D \n"
"    BNE     loc_FF8DD284 \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF8DD0D4 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF829C0C /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF8D84E8 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF887BB4 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF829AF8 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8DD228 \n"
"    LDR     R2, =0x17A2 \n"
"    B       loc_FF8DD2F8 \n"

"loc_FF8DD284:\n"
"    CMP     R1, #0x2E \n"
"    BNE     loc_FF8DD29C \n"

"loc_FF8DD28C:\n"
"    LDR     R0, [SP, #0x28] \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF8DD0D4 \n"
"    B       loc_FF8DD228 \n"

"loc_FF8DD29C:\n"
"    CMP     R1, #0x31 \n"
"    BNE     loc_FF8DD2B4 \n"
"    BL      sub_FF8C68D4 \n"
"    BL      sub_FF8C774C \n"
"    BL      sub_FF8C722C \n"
"    B       loc_FF8DD228 \n"

"loc_FF8DD2B4:\n"
"    CMP     R1, #0x32 \n"
"    BNE     loc_FF8DD308 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #4 \n"
"    BL      sub_FF829C0C /*_ClearEventFlag*/ \n"
"    LDR     R1, =0xFF8D8508 \n"
"    LDR     R0, =0xFFFFF400 \n"
"    MOV     R2, #4 \n"
"    BL      sub_FF8DE9D8 \n"
"    BL      sub_FF8C6568 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #4 \n"
"    BL      sub_FF829A0C /*_WaitForAnyEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8DD228 \n"
"    LDR     R2, =0x17DA \n"

"loc_FF8DD2F8:\n"
"    LDR     R1, =0xFF8D8CA4 /*'ExpDrv.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"
"    B       loc_FF8DD228 \n"

"loc_FF8DD308:\n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R8, #1 \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x12 \n"
"    CMPNE   R1, #0x13 \n"
"    BNE     loc_FF8DD370 \n"
"    LDR     R1, [R0, #0x94] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF8DB520 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R3, [R0, #0xAC] \n"
"    LDR     R2, [R0, #0xB0] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF8DECC0 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R2, [R0, #0xB8] \n"
"    LDR     R3, [R0, #0xB4] \n"
"    B       loc_FF8DD68C \n"

"loc_FF8DD370:\n"
"    CMP     R1, #0x14 \n"
"    CMPNE   R1, #0x15 \n"
"    CMPNE   R1, #0x16 \n"
"    CMPNE   R1, #0x17 \n"
"    CMPNE   R1, #0x18 \n"
"    BNE     loc_FF8DD41C \n"
"    ADD     R3, SP, #0xC \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF8DB790 \n"
"    CMP     R0, #1 \n"
"    MOV     R9, R0 \n"
"    CMPNE   R9, #5 \n"
"    BNE     loc_FF8DD3C8 \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, R9 \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R12, [R0, #0xAC] \n"
"    LDR     R3, [R0, #0xB0] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R12 \n"
"    B       loc_FF8DD400 \n"

"loc_FF8DD3C8:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R9, #2 \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R12, [R0, #0xAC] \n"
"    LDR     R3, [R0, #0xB0] \n"
"    CMPNE   R9, #6 \n"
"    MOV     R2, R9 \n"
"    ADD     R0, R0, #4 \n"
"    BNE     loc_FF8DD414 \n"
"    BLX     R12 \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF8DCDE0 \n"

"loc_FF8DD400:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R2, [SP, #0xC] \n"
"    MOV     R1, R9 \n"
"    BL      sub_FF8DD064 \n"
"    B       loc_FF8DD694 \n"

"loc_FF8DD414:\n"
"    BLX     R12 \n"
"    B       loc_FF8DD694 \n"

"loc_FF8DD41C:\n"
"    CMP     R1, #0x28 \n"
"    CMPNE   R1, #0x29 \n"
"    BNE     loc_FF8DD468 \n"
"    LDR     R1, [R0, #0x94] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF8DA44C \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R3, [R0, #0xAC] \n"
"    LDR     R2, [R0, #0xB0] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF8DA89C \n"
"    B       loc_FF8DD694 \n"

"loc_FF8DD468:\n"
"    ADD     R1, R0, #4 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x2C \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF8DD67C \n"
"    B       loc_FF8DD534 \n"
"    B       loc_FF8DD534 \n"
"    B       loc_FF8DD53C \n"
"    B       loc_FF8DD544 \n"
"    B       loc_FF8DD544 \n"
"    B       loc_FF8DD544 \n"
"    B       loc_FF8DD534 \n"
"    B       loc_FF8DD53C \n"
"    B       loc_FF8DD544 \n"
"    B       loc_FF8DD544 \n"
"    B       loc_FF8DD55C \n"
"    B       loc_FF8DD55C \n"
"    B       loc_FF8DD668 \n"
"    B       loc_FF8DD670 \n"
"    B       loc_FF8DD670 \n"
"    B       loc_FF8DD670 \n"
"    B       loc_FF8DD670 \n"
"    B       loc_FF8DD678 \n"
"    B       loc_FF8DD67C \n"
"    B       loc_FF8DD67C \n"
"    B       loc_FF8DD67C \n"
"    B       loc_FF8DD67C \n"
"    B       loc_FF8DD67C \n"
"    B       loc_FF8DD67C \n"
"    B       loc_FF8DD67C \n"
"    B       loc_FF8DD54C \n"
"    B       loc_FF8DD554 \n"
"    B       loc_FF8DD554 \n"
"    B       loc_FF8DD554 \n"
"    B       loc_FF8DD568 \n"
"    B       loc_FF8DD568 \n"
"    B       loc_FF8DD568 \n"
"    B       loc_FF8DD570 \n"
"    B       loc_FF8DD5A8 \n"
"    B       loc_FF8DD67C \n"
"    B       loc_FF8DD67C \n"
"    B       loc_FF8DD5E0 \n"
"    B       loc_FF8DD618 \n"
"    B       loc_FF8DD650 \n"
"    B       loc_FF8DD650 \n"
"    B       loc_FF8DD67C \n"
"    B       loc_FF8DD67C \n"
"    B       loc_FF8DD658 \n"
"    B       loc_FF8DD660 \n"

"loc_FF8DD534:\n"
"    BL      sub_FF8D8B24 \n"
"    B       loc_FF8DD67C \n"

"loc_FF8DD53C:\n"
"    BL      sub_FF8D8DF0 \n"
"    B       loc_FF8DD67C \n"

"loc_FF8DD544:\n"
"    BL      sub_FF8D9030 \n"
"    B       loc_FF8DD67C \n"

"loc_FF8DD54C:\n"
"    BL      sub_FF8D9378 \n"
"    B       loc_FF8DD67C \n"

"loc_FF8DD554:\n"
"    BL      sub_FF8D95A8 \n"
"    B       loc_FF8DD67C \n"

"loc_FF8DD55C:\n"
"    BL      sub_FF8D9998_my \n"  // --> Patched. Old value = 0xFF8D9998.
"    MOV     R8, #0 \n"
"    B       loc_FF8DD67C \n"

"loc_FF8DD568:\n"
"    BL      sub_FF8D9B6C \n"
"    B       loc_FF8DD67C \n"

"loc_FF8DD570:\n"
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
"    BL      sub_FF8DA0D4 \n"
"    B       loc_FF8DD67C \n"

"loc_FF8DD5A8:\n"
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
"    BL      sub_FF8DEA38 \n"
"    B       loc_FF8DD67C \n"

"loc_FF8DD5E0:\n"
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
"    BL      sub_FF8DEB6C \n"
"    B       loc_FF8DD67C \n"

"loc_FF8DD618:\n"
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
"    BL      sub_FF8DEC18 \n"
"    B       loc_FF8DD67C \n"

"loc_FF8DD650:\n"
"    BL      sub_FF8DA1E8 \n"
"    B       loc_FF8DD67C \n"

"loc_FF8DD658:\n"
"    BL      sub_FF8DA9B4 \n"
"    B       loc_FF8DD67C \n"

"loc_FF8DD660:\n"
"    BL      sub_FF8DAD4C \n"
"    B       loc_FF8DD67C \n"

"loc_FF8DD668:\n"
"    BL      sub_FF8DAFBC \n"
"    B       loc_FF8DD67C \n"

"loc_FF8DD670:\n"
"    BL      sub_FF8DB188 \n"
"    B       loc_FF8DD67C \n"

"loc_FF8DD678:\n"
"    BL      sub_FF8DB300 \n"

"loc_FF8DD67C:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R2, [R0, #0xB0] \n"
"    LDR     R3, [R0, #0xAC] \n"

"loc_FF8DD68C:\n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"

"loc_FF8DD694:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x10 \n"
"    BEQ     loc_FF8DD6CC \n"
"    BGT     loc_FF8DD6BC \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #4 \n"
"    CMPNE   R0, #0xE \n"
"    BNE     loc_FF8DD700 \n"
"    B       loc_FF8DD6CC \n"

"loc_FF8DD6BC:\n"
"    CMP     R0, #0x13 \n"
"    CMPNE   R0, #0x18 \n"
"    CMPNE   R0, #0x1B \n"
"    BNE     loc_FF8DD700 \n"

"loc_FF8DD6CC:\n"
"    LDRSH   R0, [R4] \n"
"    CMN     R0, #0xC00 \n"
"    LDRNESH R1, [R4, #8] \n"
"    CMNNE   R1, #0xC00 \n"
"    STRNEH  R0, [SP, #0x1C] \n"
"    STRNEH  R1, [SP, #0x24] \n"
"    BNE     loc_FF8DD700 \n"
"    ADD     R0, SP, #0x10 \n"
"    BL      sub_FF8DEEF0 \n"
"    LDRH    R0, [SP, #0x10] \n"
"    STRH    R0, [SP, #0x1C] \n"
"    LDRH    R0, [SP, #0x18] \n"
"    STRH    R0, [SP, #0x24] \n"

"loc_FF8DD700:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R8, #1 \n"
"    BNE     loc_FF8DD750 \n"
"    LDR     R1, [R0, #0x94] \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R0, R0, R1, LSL#2 \n"
"    SUB     R8, R0, #8 \n"
"    LDR     R0, =0x5A4B4 \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_006BA828 \n"
"    LDR     R0, =0x5A4C0 \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_006BA828 \n"
"    LDR     R0, =0x5A4CC \n"
"    MOV     R2, #0xC \n"
"    MOV     R1, R8 \n"
"    BL      sub_006BA828 \n"
"    B       loc_FF8DD7C8 \n"

"loc_FF8DD750:\n"
"    LDR     R0, [R0] \n"
"    MOV     R3, #1 \n"
"    CMP     R0, #0xB \n"
"    BNE     loc_FF8DD794 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8D88F0 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    B       loc_FF8DD7C4 \n"

"loc_FF8DD794:\n"
"    MOV     R2, #1 \n"
"    STRD    R2, [SP] \n"
"    MOV     R3, R2 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, R2 \n"
"    BL      sub_FF8D88F0 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, R3 \n"
"    STR     R3, [SP] \n"
"    STR     R3, [SP, #4] \n"

"loc_FF8DD7C4:\n"
"    BL      sub_FF8D8A6C \n"

"loc_FF8DD7C8:\n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF8DE974 \n"
"    B       loc_FF8DD154 \n"
);
}

/*************************************************************/
//** sub_FF8D9998_my @ 0xFF8D9998 - 0xFF8D9A5C, length=50
void __attribute__((naked,noinline)) sub_FF8D9998_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x447C \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x3E \n"
"    BL      sub_FF829C0C /*_ClearEventFlag*/ \n"
"    MOV     R2, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    MOV     R3, #1 \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF8D8570 \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8D8750 \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF8D87A8 \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_FF8D8800 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF8D8858 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R4] \n"
"    LDR     R8, =0x5A4CC \n"
"    CMP     R0, #0xB \n"
"    MOVEQ   R6, #0 \n"
"    MOVEQ   R5, R6 \n"
"    BEQ     loc_FF8D9A30 \n"
"    CMP     R6, #1 \n"
"    BNE     loc_FF8D9A30 \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xFF8D84C8 \n"
"    MOV     R2, #2 \n"
"    BL      sub_FF887A28 \n"
"    STRH    R0, [R4, #4] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    B       loc_FF8D9A38 \n"

"loc_FF8D9A30:\n"
"    LDRH    R0, [R8] \n"
"    STRH    R0, [R4, #4] \n"

"loc_FF8D9A38:\n"
"    CMP     R5, #1 \n"
"    LDRNEH  R0, [R8, #8] \n"
"    BNE     loc_FF8D9A54 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    LDR     R1, =0xFF8D854C \n"
"    MOV     R2, #0x20 \n"
"    BL      sub_FF8DE9F4 \n"

"loc_FF8D9A54:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8C65E0_my \n"  // --> Patched. Old value = 0xFF8C65E0.
"    LDR     PC, =0xFF8D9A60 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF8C65E0_my @ 0xFF8C65E0 - 0xFF8C6628, length=19
void __attribute__((naked,noinline)) sub_FF8C65E0_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x409C \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R0, #1 \n"
"    LDRNE   R2, =0x16B \n"
"    LDRNE   R1, =0xFF8C6384 /*'Shutter.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    CMN     R4, #0xC00 \n"
"    LDREQSH R4, [R5, #2] \n"
"    CMN     R4, #0xC00 \n"
"    LDREQ   R2, =0x171 \n"
"    LDREQ   R1, =0xFF8C6384 /*'Shutter.c'*/ \n"
"    MOVEQ   R0, #0 \n"
"    STRH    R4, [R5, #2] \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    LDR     PC, =0xFF8C662C \n"  // Continue in firmware
);
}
