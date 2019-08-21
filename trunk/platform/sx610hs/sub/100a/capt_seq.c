/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1 // see stubs_min.S
#define NR_AUTO (0)        // have to explictly reset value back to 0 to enable auto
#define PAUSE_FOR_FILE_COUNTER 350  // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFF0998E8 - 0xFF099BD8, length=189
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    LDR     R5, =0x26894 \n"
"    LDR     R7, =0x3AD0 \n"
"    MOV     R6, #0 \n"

"loc_FF0998F8:\n"
"    LDR     R0, [R7, #8] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_006B8490 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF099928 \n"
"    LDR     R2, =0x455 \n"
"    LDR     R1, =0xFF0991F0 /*'SsShootTask.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_FF099928:\n"
"    LDR     R0, [SP] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #0x25 \n"
"    CMPNE   R0, #0x1C \n"
"    BLNE    sub_FF2200A0 \n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x27 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF099B9C \n"
"    B       loc_FF0999F0 \n"
"    B       loc_FF099A0C \n"
"    B       loc_FF099A18 \n"
"    B       loc_FF099A2C \n"
"    B       loc_FF099A24 \n"
"    B       loc_FF099A3C \n"
"    B       loc_FF099A44 \n"
"    B       loc_FF099A4C \n"
"    B       loc_FF099A58 \n"
"    B       loc_FF099A9C \n"
"    B       loc_FF099A64 \n"
"    B       loc_FF099A70 \n"
"    B       loc_FF099A78 \n"
"    B       loc_FF099A84 \n"
"    B       loc_FF099A8C \n"
"    B       loc_FF099A94 \n"
"    B       loc_FF099AA8 \n"
"    B       loc_FF099AB0 \n"
"    B       loc_FF099AB8 \n"
"    B       loc_FF099AC0 \n"
"    B       loc_FF099AC8 \n"
"    B       loc_FF099AD4 \n"
"    B       loc_FF099ADC \n"
"    B       loc_FF099AE4 \n"
"    B       loc_FF099AEC \n"
"    B       loc_FF099AF4 \n"
"    B       loc_FF099AFC \n"
"    B       loc_FF099B04 \n"
"    B       loc_FF099B0C \n"
"    B       loc_FF099B18 \n"
"    B       loc_FF099B20 \n"
"    B       loc_FF099B28 \n"
"    B       loc_FF099B30 \n"
"    B       loc_FF099B38 \n"
"    B       loc_FF099B44 \n"
"    B       loc_FF099B4C \n"
"    B       loc_FF099B7C \n"
"    B       loc_FF099B88 \n"
"    B       loc_FF099BAC \n"

"loc_FF0999F0:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF09A1D8 \n"
"    BL      shooting_expo_param_override\n"    // added
"    BL      sub_FF096C0C \n"
//To do: Check if this is needed.
//"    MOV     R0, #0\n"                          // added
//"    STR     R0, [R5,#0x28]\n"                  // added, fixes overrides behavior at short shutter press (from S95)
"    LDR     R0, [R5, #0x28] \n"
"    CMP     R0, #0 \n"
"    BLNE    sub_FF21EFC4_my \n"  // --> Patched. Old value = 0xFF21EFC4.
"    B       loc_FF099BAC \n"

"loc_FF099A0C:\n"
"    LDR     R0, [R0, #0x10] \n"
"    BL      sub_FF21EDC4_my \n"  // --> Patched. Old value = 0xFF21EDC4.
"    B       loc_FF099BAC \n"

"loc_FF099A18:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF09A538 \n"
"    B       loc_FF099BAC \n"

"loc_FF099A24:\n"
"    BL      sub_FF099DA8 \n"
"    B       loc_FF099A34 \n"

"loc_FF099A2C:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF09A1AC \n"

"loc_FF099A34:\n"
"    STR     R6, [R5, #0x28] \n"
"    B       loc_FF099BAC \n"

"loc_FF099A3C:\n"
"    BL      sub_FF09A1B8 \n"
"    B       loc_FF099BAC \n"

"loc_FF099A44:\n"
"    BL      sub_FF09A400 \n"
"    B       loc_FF099A5C \n"

"loc_FF099A4C:\n"
"    LDR     R0, [R0, #0x10] \n"
"    BL      sub_FF21F0A0 \n"
"    B       loc_FF099BAC \n"

"loc_FF099A58:\n"
"    BL      sub_FF09A488 \n"

"loc_FF099A5C:\n"
"    BL      sub_FF096C0C \n"
"    B       loc_FF099BAC \n"

"loc_FF099A64:\n"
"    LDR     R0, [R5, #0x54] \n"
"    BL      sub_FF09ACA8 \n"
"    B       loc_FF099BAC \n"

"loc_FF099A70:\n"
"    BL      sub_FF09B004 \n"
"    B       loc_FF099BAC \n"

"loc_FF099A78:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF09B06C \n"
"    B       loc_FF099BAC \n"

"loc_FF099A84:\n"
"    BL      sub_FF09B220 \n"
"    B       loc_FF099BAC \n"

"loc_FF099A8C:\n"
"    BL      sub_FF09B738 \n"
"    B       loc_FF099BAC \n"

"loc_FF099A94:\n"
"    BL      sub_FF09B820 \n"
"    B       loc_FF099BAC \n"

"loc_FF099A9C:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF09A1AC \n"
"    B       loc_FF099BAC \n"

"loc_FF099AA8:\n"
"    BL      sub_FF21D374 \n"
"    B       loc_FF099BAC \n"

"loc_FF099AB0:\n"
"    BL      sub_FF21D5D0 \n"
"    B       loc_FF099BAC \n"

"loc_FF099AB8:\n"
"    BL      sub_FF21D694 \n"
"    B       loc_FF099BAC \n"

"loc_FF099AC0:\n"
"    BL      sub_FF21D780 \n"
"    B       loc_FF099BAC \n"

"loc_FF099AC8:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF21DA68 \n"
"    B       loc_FF099BAC \n"

"loc_FF099AD4:\n"
"    BL      sub_FF21DBE4 \n"
"    B       loc_FF099BAC \n"

"loc_FF099ADC:\n"
"    BL      sub_FF0A2160 \n"
"    B       loc_FF099BAC \n"

"loc_FF099AE4:\n"
"    BL      sub_FF0A216C \n"
"    B       loc_FF099BAC \n"

"loc_FF099AEC:\n"
"    BL      sub_FF21DC88 \n"
"    B       loc_FF099BAC \n"

"loc_FF099AF4:\n"
"    BL      sub_FF21DD38 \n"
"    B       loc_FF099BAC \n"

"loc_FF099AFC:\n"
"    BL      sub_FF09A668 \n"
"    B       loc_FF099BAC \n"

"loc_FF099B04:\n"
"    MOV     R0, #0 \n"
"    B       loc_FF099B10 \n"

"loc_FF099B0C:\n"
"    LDR     R0, [R0, #0xC] \n"

"loc_FF099B10:\n"
"    BL      sub_FF09A6F8 \n"
"    B       loc_FF099BAC \n"

"loc_FF099B18:\n"
"    BL      sub_FF21D934 \n"
"    B       loc_FF099BAC \n"

"loc_FF099B20:\n"
"    BL      sub_FF21D9C8 \n"
"    B       loc_FF099BAC \n"

"loc_FF099B28:\n"
"    BL      sub_FF09E3A0 \n"
"    B       loc_FF099BAC \n"

"loc_FF099B30:\n"
"    BL      sub_FF09E4E8 \n"
"    B       loc_FF099BAC \n"

"loc_FF099B38:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF21DE5C \n"
"    B       loc_FF099BAC \n"

"loc_FF099B44:\n"
"    BL      sub_FF21DEEC \n"
"    B       loc_FF099BAC \n"

"loc_FF099B4C:\n"
"    BL      sub_FF0A0D44 \n"
"    LDR     R0, =0x26994 \n"
"    LDRH    R0, [R0, #0x9C] \n"
"    CMP     R0, #4 \n"
"    LDRNEH  R0, [R5] \n"
"    SUBNE   R1, R0, #0x8200 \n"
"    SUBNES  R1, R1, #0x36 \n"
"    BNE     loc_FF099BAC \n"
"    BL      sub_FF09E4E8 \n"
"    BL      sub_FF09EBCC \n"
"    BL      sub_FF09EA28 \n"
"    B       loc_FF099BAC \n"

"loc_FF099B7C:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0x11 \n"
"    B       loc_FF099B90 \n"

"loc_FF099B88:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0x10 \n"

"loc_FF099B90:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF097828 \n"
"    B       loc_FF099BAC \n"

"loc_FF099B9C:\n"
"    LDR     R2, =0x585 \n"
"    LDR     R1, =0xFF0991F0 /*'SsShootTask.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"

"loc_FF099BAC:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R7, #4] \n"
"    BL      sub_006B8224 /*_SetEventFlag*/ \n"
"    LDR     R4, [SP] \n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R2, =0x12B \n"
"    LDREQ   R1, =0xFF0991F0 /*'SsShootTask.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    STR     R6, [R4, #8] \n"
"    B       loc_FF0998F8 \n"
);
}

/*************************************************************/
//** sub_FF21EFC4_my @ 0xFF21EFC4 - 0xFF21F09C, length=55
void __attribute__((naked,noinline)) sub_FF21EFC4_my() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    BL      sub_FF098DFC \n"
"    MOV     R4, R0 \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF0A06A8 \n"
"    LDR     R6, =0xAC08 \n"
"    TST     R0, #1 \n"
"    MOV     R5, #1 \n"
"    BNE     loc_FF21F08C \n"
"    MOV     R2, #2 \n"
"    MOV     R1, SP \n"
"    MOV     R0, #0x110 \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    ADDNE   R2, R5, #0x17C \n"
"    LDRNE   R1, =0xFF21F134 /*'SsCaptureCtrl.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    LDRSH   R0, [SP] \n"
"    BL      sub_FF02AC30 \n"
"    BL      sub_FF02AA4C \n"
"    CMP     R0, #1 \n"
"    BLS     loc_FF21F094 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF02ABA4 \n"
"    BL      sub_FF09A1C4 \n"
"    BL      sub_FF09BC74 \n"
"    MOV     R1, R4 \n"
"    BL      sub_FF09BCD0 \n"
"    LDR     R0, =0x116 \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #0x30 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #0x34 \n"
"    MOV     R0, #0x30 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #8 \n"
"    MOV     R0, #0x44 \n"
"    BL      _SetPropertyCase \n"
"    BL      sub_FF21F8B8 \n"
"    MVN     R1, #0x1000 \n"
"    BL      sub_006B826C /*_ClearEventFlag*/ \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF21E9D8 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF3C416C_my \n"  // --> Patched. Old value = 0xFF3C416C.
"    TST     R0, #1 \n"
"    BEQ     loc_FF21F090 \n"

"loc_FF21F08C:\n"
"    STR     R5, [R6] \n"

"loc_FF21F090:\n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_FF21F094:\n"
"    BL      sub_FF097534 \n"
"    BL      sub_FF0A0710 \n"
"    LDMFD   SP!, {R3-R7,PC} \n"
);
}

/*************************************************************/
//** sub_FF21EDC4_my @ 0xFF21EDC4 - 0xFF21EFC0, length=128
void __attribute__((naked,noinline)) sub_FF21EDC4_my() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    LDR     R7, =0x26894 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R7, #0x28] \n"
"    MOV     R4, #0 \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF21EE10 \n"
"    LDR     R0, =0xAC08 \n"
"    MOV     R2, R5 \n"
"    LDR     R0, [R0] \n"
"    MOV     R1, #2 \n"
"    CMP     R0, #0 \n"
"    MOVNE   R4, #0x1D \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF097828 \n"
"    MOV     R1, R4 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF21FE28 \n"
"    B       loc_FF21EFB8 \n"

"loc_FF21EE10:\n"
"    BL      sub_FF09BC74 \n"
"    MOV     R1, R5 \n"
"    BL      sub_FF09BCD0 \n"
"    LDR     R0, =0x116 \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x30 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x34 \n"
"    MOV     R0, #0x30 \n"
"    BL      _SetPropertyCase \n"
"    LDR     R0, [R7, #0x104] \n"
"    LDR     R6, =0x26994 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF21EE64 \n"
"    LDRH    R0, [R6, #0x9A] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R5, #8] \n"
"    CMPNE   R0, #1 \n"
"    BHI     loc_FF21EE88 \n"
"    B       loc_FF21EE70 \n"

"loc_FF21EE64:\n"
"    LDR     R0, [R5, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF21EE88 \n"

"loc_FF21EE70:\n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF0A06A8 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF21EE88 \n"
"    BL      sub_FF097534 \n"
"    MOV     R4, #1 \n"

"loc_FF21EE88:\n"
"    TST     R4, #1 \n"
"    BNE     loc_FF21EF9C \n"
"    LDR     R0, [R7, #0xE4] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF21EEC4 \n"
"    LDRH    R0, [R6, #0x9A] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R5, #8] \n"
"    CMPNE   R0, #1 \n"
"    BHI     loc_FF21EF1C \n"
"    LDR     R0, [R7, #0x104] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, [R5, #0xC] \n"
"    CMPNE   R0, #1 \n"
"    BHI     loc_FF21EF1C \n"

"loc_FF21EEC4:\n"
"    MOV     R2, #2 \n"
"    MOV     R1, SP \n"
"    MOV     R0, #0x110 \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    MOVNE   R2, #0xCD \n"
"    LDRNE   R1, =0xFF21F134 /*'SsCaptureCtrl.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    LDRSH   R0, [SP] \n"
"    BL      sub_FF02AC30 \n"
"    BL      sub_FF02AA4C \n"
"    CMP     R0, #1 \n"
"    BLS     loc_FF21EF08 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF02ABA4 \n"
"    B       loc_FF21EF1C \n"

"loc_FF21EF08:\n"
"    BL      sub_FF097534 \n"
"    BL      sub_FF0A0710 \n"
"    MOV     R4, #1 \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FF21EF9C \n"

"loc_FF21EF1C:\n"
"    MOV     R4, #0 \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FF21EF9C \n"
"    BL      sub_FF21F8B8 \n"
"    MVN     R1, #0x1000 \n"
"    BL      sub_006B826C /*_ClearEventFlag*/ \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF3C3DF0 \n"
"    TST     R0, #1 \n"
"    MOV     R4, R0 \n"
"    BNE     loc_FF21EF9C \n"
"    BL      sub_FF09A1C4 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF21E9D8 \n"
"    LDR     R0, [R7, #0x128] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF21EF74 \n"
"    LDRH    R0, [R6, #0x9A] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R5, #8] \n"
"    CMPNE   R0, #1 \n"
"    BHI     loc_FF21EF7C \n"

"loc_FF21EF74:\n"
"    MOV     R0, #2 \n"
"    BL      sub_FF0A22FC \n"

"loc_FF21EF7C:\n"
"    LDR     R0, [R7, #0xAC] \n"
"    CMP     R0, #0 \n"
"    MOV     R0, R5 \n"
"    BEQ     loc_FF21EF94 \n"
"    BL      sub_FF3C4614 \n"
"    B       loc_FF21EFB8 \n"

"loc_FF21EF94:\n"
"    BL      sub_FF3C416C_my \n"  // --> Patched. Old value = 0xFF3C416C.
"    B       loc_FF21EFB8 \n"

"loc_FF21EF9C:\n"
"    MOV     R2, R5 \n"
"    MOV     R1, #2 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF097828 \n"
"    MOV     R1, R4 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF22003C \n"

"loc_FF21EFB8:\n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    LDMFD   SP!, {R3-R7,PC} \n"
);
}

/*************************************************************/
//** sub_FF3C416C_my @ 0xFF3C416C - 0xFF3C4498, length=204
void __attribute__((naked,noinline)) sub_FF3C416C_my() {
asm volatile (
"    STMFD   SP!, {R1-R9,LR} \n"
"    LDR     R7, =0x26894 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x164] \n"
"    ADD     R5, R7, #0x100 \n"
"    CMP     R0, #0 \n"
"    LDRNEH  R0, [R5, #0x9A] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    BHI     loc_FF3C41A4 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF21E940 \n"
"    BL      sub_FF21F71C \n"

"loc_FF3C41A4:\n"
"    LDR     R0, [R7, #0x190] \n"
"    CMP     R0, #2 \n"
"    BNE     loc_FF3C41C8 \n"
"    LDRH    R0, [R5, #0x9A] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    MOVLS   R0, #4 \n"
"    BLLS    sub_FF138C2C \n"

"loc_FF3C41C8:\n"
"    LDR     R0, =0x137 \n"
"    MOV     R2, #4 \n"
"    ADD     R1, SP, #8 \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    MOVNE   R2, #0x150 \n"
"    LDRNE   R1, =0xFF3C4450 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #8] \n"
"    AND     R0, R0, #0xFF00 \n"
"    CMP     R0, #0x600 \n"
"    LDRNE   R0, =0xFF21E4DC \n"
"    LDREQ   R0, =0xFF3C411C \n"
"    MOVNE   R1, R4 \n"
"    MOVEQ   R1, #0 \n"
"    BL      sub_FF0E4774 \n"
"    MOV     R2, #2 \n"
"    ADD     R1, SP, #4 \n"
"    ADD     R0, R2, #0x110 \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    LDRNE   R2, =0x159 \n"
"    LDRNE   R1, =0xFF3C4450 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [R7, #0x184] \n"
"    CMP     R0, #0 \n"
"    BLNE    sub_FF21E82C \n"
"    MOV     R0, #0 \n"
//"  BL      _sub_FF09D1CC \n"  // --> Nullsub call removed.
"    BL      wait_until_remote_button_is_released\n" // added
"    BL      capt_seq_hook_set_nr\n"                 // added
"    MOV     R0, R4 \n"
"    BL      sub_FF21EAFC \n"
"    LDR     R1, =0x10C90 \n"
"    MOV     R2, #4 \n"
"    MOV     R0, #0x90 \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    LDRNE   R2, =0x16E \n"
"    LDRNE   R1, =0xFF3C4450 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    BL      sub_FF09D390 \n"
"    BL      sub_FF08A460 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF3C4120 \n"
"    MOV     R6, R0 \n"
"    LDR     R0, [SP, #8] \n"
"    LDR     R8, =0x10C90 \n"
"    AND     R0, R0, #0xFF00 \n"
"    CMP     R0, #0x600 \n"
"    LDRH    R0, [R4, #0x18] \n"
"    LDRNE   R2, =0xFF21E804 \n"
"    LDREQ   R2, =0xFF21E7E4 \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF3C42BC \n"
"    CMP     R0, #1 \n"
"    BEQ     loc_FF3C42E0 \n"
"    CMP     R0, #4 \n"
"    BNE     loc_FF3C4354 \n"

"loc_FF3C42BC:\n"
"    STR     R6, [SP] \n"
"    MOV     R3, R2 \n"
"    LDR     R1, [R4, #0x34] \n"
"    LDR     R2, [R8] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF21E1F0 \n"
"    MOV     R5, R0 \n"
"    BL      sub_FF0E09F0 \n"
"    B       loc_FF3C4368 \n"

"loc_FF3C42E0:\n"
"    STR     R6, [SP] \n"
"    MOV     R3, R2 \n"
"    LDR     R1, [R4, #0x34] \n"
"    LDR     R2, [R8] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF21E298 \n"
"    MOV     R5, R0 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, #0x45 \n"
"    BL      sub_FF032E50 \n"
"    TST     R5, #1 \n"
"    BNE     loc_FF3C4368 \n"
"    LDR     R0, =0xFF3C411C \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF0E4774 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF3C4120 \n"
"    MOV     R6, R0 \n"
"    LDR     R0, [R8] \n"
"    BL      sub_FF21E8C4 \n"
"    LDR     R1, [R4, #0x34] \n"
"    LDR     R2, [R8] \n"
"    MOV     R3, R6 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF21E34C \n"
"    MOV     R5, R0 \n"
"    BL      sub_FF21E178 \n"
"    B       loc_FF3C4368 \n"

"loc_FF3C4354:\n"
"    LDR     R2, =0x1A7 \n"
"    LDR     R1, =0xFF3C4450 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"
"    MOV     R5, #0x1D \n"

"loc_FF3C4368:\n"
"    BL      sub_FF08A478 \n"
"    LDR     R8, =0xFF3C411C \n"
"    TST     R5, #1 \n"
"    BNE     loc_FF3C43E8 \n"
"    LDR     R0, [R7, #0x100] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF3C43A0 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF2206AC \n"
"    TST     R0, #1 \n"
"    MOVNE   R2, #0x1C8 \n"
"    LDRNE   R1, =0xFF3C4450 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    BL      capt_seq_hook_raw_here \n"         // added

"loc_FF3C43A0:\n"
"    MOV     R0, R4 \n"
"    BL      sub_FF21EBCC \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF21EB84 \n"
"    CMP     R6, R8 \n"
"    BEQ     loc_FF3C43E8 \n"
"    BL      sub_FF21F8B8 \n"
"    LDR     R9, =0x1D5 \n"
"    LDR     R2, =0x3A98 \n"
"    LDR     R3, =0xFF3C4450 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOV     R1, #4 \n"
"    STR     R9, [SP] \n"
"    BL      sub_FF0A094C \n"
"    CMP     R0, #0 \n"
"    MOVNE   R2, R9 \n"
"    LDRNE   R1, =0xFF3C4450 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"

"loc_FF3C43E8:\n"
"    MOV     R2, R4 \n"
"    MOV     R1, #2 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF097828 \n"
"    LDR     R0, [R7, #0x28] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF3C441C \n"
"    SUBS    R1, R6, R8 \n"
"    MOVNE   R1, #1 \n"
"    MOV     R2, R5 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF21FDC0 \n"
"    B       loc_FF3C4430 \n"

"loc_FF3C441C:\n"
"    SUBS    R1, R6, R8 \n"
"    MOVNE   R1, #1 \n"
"    MOV     R2, R5 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF21FD54 \n"

"loc_FF3C4430:\n"
"    MOV     R0, R5 \n"
"    LDMFD   SP!, {R1-R9,PC} \n"
"    .ltorg\n"         // added
);
}