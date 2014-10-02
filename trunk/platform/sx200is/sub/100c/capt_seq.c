/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1          // see stubs_entry.S

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFF86327C - 0xFF863594, length=199
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R9,LR} \n"
"    LDR     R6, =0x2B78 \n"
"    LDR     R4, =0x15448 \n"
"    MOV     R9, #1 \n"
"    MOV     R7, #0 \n"

"loc_FF863290:\n"
"    LDR     R0, [R6, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_FF826D3C /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8632BC \n"
"    LDR     R1, =0x588 \n"
"    LDR     R0, =0xFF862AEC /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R9,PC} \n"

"loc_FF8632BC:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x20 \n"
"    ADDLS   PC, PC, R1, LSL#2 \n"
"    B       loc_FF86355C \n"
"    B       loc_FF863354 \n"
"    B       loc_FF8633B8 \n"
"    B       loc_FF8633F4 \n"
"    B       loc_FF863408 \n"
"    B       loc_FF863400 \n"
"    B       loc_FF863410 \n"
"    B       loc_FF863418 \n"
"    B       loc_FF863420 \n"
"    B       loc_FF863478 \n"
"    B       loc_FF8634A0 \n"
"    B       loc_FF863484 \n"
"    B       loc_FF863490 \n"
"    B       loc_FF863498 \n"
"    B       loc_FF8634A8 \n"
"    B       loc_FF8634B0 \n"
"    B       loc_FF8634B8 \n"
"    B       loc_FF8634C0 \n"
"    B       loc_FF8634C8 \n"
"    B       loc_FF8634D0 \n"
"    B       loc_FF8634D8 \n"
"    B       loc_FF8634E0 \n"
"    B       loc_FF8634E8 \n"
"    B       loc_FF8634F4 \n"
"    B       loc_FF8634FC \n"
"    B       loc_FF863508 \n"
"    B       loc_FF863510 \n"
"    B       loc_FF863518 \n"
"    B       loc_FF863520 \n"
"    B       loc_FF863528 \n"
"    B       loc_FF863530 \n"
"    B       loc_FF863538 \n"
"    B       loc_FF863544 \n"
"    B       loc_FF863568 \n"

"loc_FF863354:\n"
"    BL      sub_FF863B6C \n"
"    BL      shooting_expo_param_override\n"              // +
"    BL      sub_FF860CF4 \n"
// copied over from SX10 don't know if we need it yet
//  this code added to avoid some incorrect behavior if overrides are used.
//  but it can cause some unexpected side effects. In this case, remove this code!
"    MOV     R0, #0\n"
"    STR     R0, [R4,#0x24]\n"  // fixes overrides  behavior at short shutter press
//  end of my code
"    LDR     R0, [R4, #0x24] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF863568 \n"
"    BL      sub_FF8627C0 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R4, #0x24] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF86339C \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF867F58 \n"
"    TST     R0, #1 \n"
"    STRNE   R9, [R6, #0x10] \n"
"    LDRNE   R0, [R5, #8] \n"
"    ORRNE   R0, R0, #0x40000000 \n"
"    STRNE   R0, [R5, #8] \n"
"    BNE     loc_FF863568 \n"

"loc_FF86339C:\n"
"    MOV     R0, R5 \n"
"    BL      sub_FF862BA0 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF93D388_my \n"  // --> Patched. Old value = 0xFF93D388.
"    BL      capt_seq_hook_raw_here\n"                    // +
"    TST     R0, #1 \n"
"    STRNE   R9, [R6, #0x10] \n"
"    B       loc_FF863568 \n"

"loc_FF8633B8:\n"
"    LDR     R0, [R4, #0x24] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF8633E4 \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF867F58 \n"
"    TST     R0, #1 \n"
"    LDRNE   R0, [SP] \n"
"    MOVNE   R1, #1 \n"
"    LDRNE   R2, [R0, #0xC] \n"
"    MOVNE   R0, #1 \n"
"    BNE     loc_FF863470 \n"

"loc_FF8633E4:\n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF862C18_my \n"  // --> Patched. Old value = 0xFF862C18.

"loc_FF8633EC:\n"
"    STR     R7, [R4, #0x24] \n"
"    B       loc_FF863568 \n"

"loc_FF8633F4:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF863D84 \n"
"    B       loc_FF863568 \n"

"loc_FF863400:\n"
"    BL      sub_FF863824 \n"
"    B       loc_FF8633EC \n"

"loc_FF863408:\n"
"    BL      sub_FF863B4C \n"
"    B       loc_FF8633EC \n"

"loc_FF863410:\n"
"    BL      sub_FF863B54 \n"
"    B       loc_FF863568 \n"

"loc_FF863418:\n"
"    BL      sub_FF863CA4 \n"
"    B       loc_FF86347C \n"

"loc_FF863420:\n"
"    LDR     R5, [R0, #0xC] \n"
"    BL      sub_FF863B5C \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF93C2B8 \n"
"    TST     R0, #1 \n"
"    MOV     R8, R0 \n"
"    BNE     loc_FF863460 \n"
"    BL      sub_FF874478 \n"
"    STR     R0, [R5, #0x18] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF93D2A0 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF93D690 \n"
"    MOV     R8, R0 \n"
"    LDR     R0, [R5, #0x18] \n"
"    BL      sub_FF87468C \n"

"loc_FF863460:\n"
"    BL      sub_FF863B4C \n"
"    MOV     R2, R5 \n"
"    MOV     R1, #9 \n"
"    MOV     R0, R8 \n"

"loc_FF863470:\n"
"    BL      sub_FF86125C \n"
"    B       loc_FF863568 \n"

"loc_FF863478:\n"
"    BL      sub_FF863D04 \n"

"loc_FF86347C:\n"
"    BL      sub_FF860CF4 \n"
"    B       loc_FF863568 \n"

"loc_FF863484:\n"
"    LDR     R0, [R4, #0x54] \n"
"    BL      sub_FF864324 \n"
"    B       loc_FF863568 \n"

"loc_FF863490:\n"
"    BL      sub_FF8645D8 \n"
"    B       loc_FF863568 \n"

"loc_FF863498:\n"
"    BL      sub_FF86466C \n"
"    B       loc_FF863568 \n"

"loc_FF8634A0:\n"
"    BL      sub_FF863B4C \n"
"    B       loc_FF863568 \n"

"loc_FF8634A8:\n"
"    BL      sub_FF93C4CC \n"
"    B       loc_FF863568 \n"

"loc_FF8634B0:\n"
"    BL      sub_FF93C6B4 \n"
"    B       loc_FF863568 \n"

"loc_FF8634B8:\n"
"    BL      sub_FF93C744 \n"
"    B       loc_FF863568 \n"

"loc_FF8634C0:\n"
"    BL      sub_FF93C7F8 \n"
"    B       loc_FF863568 \n"

"loc_FF8634C8:\n"
"    MOV     R0, #0 \n"
"    B       loc_FF8634EC \n"

"loc_FF8634D0:\n"
"    BL      sub_FF93CC04 \n"
"    B       loc_FF863568 \n"

"loc_FF8634D8:\n"
"    BL      sub_FF93CC94 \n"
"    B       loc_FF863568 \n"

"loc_FF8634E0:\n"
"    BL      sub_FF93CD54 \n"
"    B       loc_FF863568 \n"

"loc_FF8634E8:\n"
"    MOV     R0, #1 \n"

"loc_FF8634EC:\n"
"    BL      sub_FF93CACC \n"
"    B       loc_FF863568 \n"

"loc_FF8634F4:\n"
"    BL      sub_FF863F50 \n"
"    B       loc_FF863568 \n"

"loc_FF8634FC:\n"
"    BL      sub_FF863FF0 \n"
"    BL      sub_FF863690 \n"
"    B       loc_FF863568 \n"

"loc_FF863508:\n"
"    BL      sub_FF93C948 \n"
"    B       loc_FF863568 \n"

"loc_FF863510:\n"
"    BL      sub_FF93CA14 \n"
"    B       loc_FF863568 \n"

"loc_FF863518:\n"
"    BL      sub_FF862A78 \n"
"    B       loc_FF863568 \n"

"loc_FF863520:\n"
"    BL      sub_FF824A80 \n"
"    B       loc_FF863568 \n"

"loc_FF863528:\n"
"    BL      sub_FF8665C0 \n"
"    B       loc_FF863568 \n"

"loc_FF863530:\n"
"    BL      sub_FF866628 \n"
"    B       loc_FF863568 \n"

"loc_FF863538:\n"
"    BL      sub_FF866684 \n"
"    BL      sub_FF866644 \n"
"    B       loc_FF863568 \n"

"loc_FF863544:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF93DF70 \n"
"    LDRH    R0, [R4, #0x98] \n"
"    CMP     R0, #4 \n"
"    BLNE    sub_FF8668F0 \n"
"    B       loc_FF863568 \n"

"loc_FF86355C:\n"
"    LDR     R1, =0x6C9 \n"
"    LDR     R0, =0xFF862AEC /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF863568:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R6] \n"
"    BL      sub_FF86C1DC /*_SetEventFlag*/ \n"
"    LDR     R5, [SP] \n"
"    LDR     R0, [R5, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x12B \n"
"    LDREQ   R0, =0xFF862AEC /*'SsShootTask.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    STR     R7, [R5, #8] \n"
"    B       loc_FF863290 \n"
);
}

/*************************************************************/
//** sub_FF862C18_my @ 0xFF862C18 - 0xFF862E18, length=129
void __attribute__((naked,noinline)) sub_FF862C18_my() {
asm volatile (
"    STMFD   SP!, {R3-R9,LR} \n"
"    LDR     R4, [R0, #0xC] \n"
"    LDR     R5, =0x15448 \n"
"    LDR     R0, [R4, #8] \n"
"    LDR     R6, =0x420A \n"
"    ORR     R0, R0, #1 \n"
"    STR     R0, [R4, #8] \n"
"    LDRH    R0, [R5] \n"
"    LDR     R8, =0x2B78 \n"
"    MOV     R7, #0 \n"
"    CMP     R0, R6 \n"
"    BEQ     loc_FF862CBC \n"
"    LDRH    R0, [R5, #0x96] \n"
"    CMP     R0, #3 \n"
"    BEQ     loc_FF862D1C \n"
"    LDR     R0, [R4, #0xC] \n"
"    CMP     R0, #1 \n"
"    BLS     loc_FF862CC8 \n"
"    LDRH    R0, [R5, #0x94] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF862D1C \n"
"    LDRH    R0, [R5, #0x90] \n"
"    CMP     R0, #2 \n"
"    BNE     loc_FF862CD4 \n"
"    BL      sub_FF8640A0 \n"
"    LDRH    R0, [R5] \n"
"    CMP     R0, R6 \n"
"    BEQ     loc_FF862CBC \n"
"    LDRH    R0, [R5, #0x96] \n"
"    CMP     R0, #3 \n"
"    BEQ     loc_FF862D1C \n"
"    LDR     R0, [R4, #0xC] \n"
"    CMP     R0, #1 \n"
"    BLS     loc_FF862CC8 \n"
"    LDRH    R0, [R5, #0x94] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF862D1C \n"
"    LDRH    R0, [R5, #0x90] \n"
"    CMP     R0, #2 \n"
"    BEQ     loc_FF862D00 \n"
"    B       loc_FF862CD4 \n"

"loc_FF862CBC:\n"
"    LDRH    R0, [R5, #0x96] \n"
"    CMP     R0, #3 \n"
"    BEQ     loc_FF862D1C \n"

"loc_FF862CC8:\n"
"    LDRH    R0, [R5, #0x94] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF862D1C \n"

"loc_FF862CD4:\n"
"    LDRH    R0, [R5, #0x90] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF862D1C \n"
"    LDRH    R0, [R5] \n"
"    CMP     R0, R6 \n"
"    LDRNE   R0, [R4, #0xC] \n"
"    CMPNE   R0, #1 \n"
"    BLS     loc_FF862D1C \n"
"    LDR     R0, [R4, #0x10] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF862D1C \n"

"loc_FF862D00:\n"
"    LDR     R3, =0x262 \n"
"    LDR     R2, =0xEA60 \n"
"    STR     R3, [SP] \n"
"    LDR     R0, [R8] \n"
"    LDR     R3, =0xFF862AEC /*'SsShootTask.c'*/ \n"
"    MOV     R1, #0x40000000 \n"
"    BL      sub_FF8682D4 \n"

"loc_FF862D1C:\n"
"    BL      sub_FF862A78 \n"
"    LDR     R0, [R5, #0x24] \n"
"    CMP     R0, #0 \n"
"    MOVEQ   R0, #2 \n"
"    BLEQ    sub_FF85E564 \n"
"    BL      sub_FF863B5C \n"
"    LDR     R0, [R5, #0x24] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF862DB4 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF93DF70 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF863ECC \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF93BEA8 \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF862D84 \n"
"    BL      sub_FF93DFB0 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF93BFEC \n"
"    TST     R0, #1 \n"
"    MOVNE   R2, R4 \n"
"    LDMNEFD SP!, {R3-R9,LR} \n"
"    MOVNE   R1, #1 \n"
"    BNE     sub_FF86125C \n"
"    B       loc_FF862D90 \n"

"loc_FF862D84:\n"
"    MOV     R0, R4 \n"
"    BL      sub_FF93BF58 \n"
"    BL      sub_FF93DFB0 \n"

"loc_FF862D90:\n"
"    MOV     R0, R4 \n"
"    BL      sub_FF862BA0 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF93D2A0 \n"
"    BL      sub_FF93DE00 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF93D388_my \n"  // --> Patched. Old value = 0xFF93D388.
"    MOV     R7, R0 \n"
"    BL      capt_seq_hook_raw_here\n"                   // +
"    B       loc_FF862DC0 \n"

"loc_FF862DB4:\n"
"    LDR     R0, [R8, #0x10] \n"
"    CMP     R0, #0 \n"
"    MOVNE   R7, #0x1D \n"

"loc_FF862DC0:\n"
"    BL      sub_FF866628 \n"
"    BL      sub_FF866670 \n"
"    BL      sub_FF8666B0 \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, R7 \n"
"    BL      sub_FF86125C \n"
"    BL      sub_FF93D634 \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, [R4, #8] \n"
"    ORRNE   R0, R0, #0x2000 \n"
"    STRNE   R0, [R4, #8] \n"
"    LDRH    R0, [R5, #0x96] \n"
"    CMP     R0, #3 \n"
"    BEQ     loc_FF862E18 \n"
"    LDRH    R0, [R5, #0x94] \n"
"    CMP     R0, #0 \n"
"    LDREQH  R0, [R5, #0x90] \n"
"    CMPEQ   R0, #2 \n"
"    MOVEQ   R0, R4 \n"
"    LDMEQFD SP!, {R3-R9,LR} \n"
"    BEQ     sub_FF8640F4 \n"

"loc_FF862E18:\n"
"    LDMFD   SP!, {R3-R9,PC} \n"
);
}

/*************************************************************/
//** sub_FF93D388_my @ 0xFF93D388 - 0xFF93D430, length=43
void __attribute__((naked,noinline)) sub_FF93D388_my() {
asm volatile (
"    STMFD   SP!, {R0-R8,LR} \n"
"    MOV     R4, R0 \n"
"    BL      sub_FF93E0E0 \n"
"    MVN     R1, #0 \n"
"    BL      sub_FF86C210 /*_ClearEventFlag*/ \n"
"    LDR     R5, =0x6AD8 \n"
"    LDR     R0, [R5, #0xC] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF93D3D8 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF827584 /*_CreateMessageQueueStrictly*/ \n"
"    STR     R0, [R5, #0xC] \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =0xFF93CE44 \n"
"    LDR     R0, =0xFF93D608 /*'ShutterSoundTask'*/ \n"  // ShutterSoundTask
"    MOV     R2, #0x400 \n"
"    MOV     R1, #0x17 \n"
"    BL      sub_FF827550 /*_CreateTaskStrictly*/ \n"

"loc_FF93D3D8:\n"
"    MOV     R2, #4 \n"
"    ADD     R1, SP, #8 \n"
"    MOV     R0, #0x8A \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x3AE \n"
"    LDRNE   R0, =0xFF93D0DC /*'SsCaptureSeq.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDR     R8, =0x1550C \n"
"    LDR     R7, =0x15448 \n"
"    LDRSH   R1, [R8, #0xE] \n"
"    LDR     R0, [R7, #0x8C] \n"
"    BL      sub_FFA2AC8C \n"
"    BL      _GetCCDTemperature \n"
"    LDR     R3, =0x6AE0 \n"
"    STRH    R0, [R4, #0x9C] \n"
"    SUB     R2, R3, #4 \n"
"    STRD    R2, [SP] \n"
"    MOV     R1, R0 \n"
"    LDRH    R0, [R7, #0x5C] \n"
"    LDRSH   R2, [R8, #0xC] \n"
"    SUB     R3, R3, #8 \n"
"    BL      sub_FF93F718 \n"
"    BL      wait_until_remote_button_is_released\n"     // +
"    BL      capt_seq_hook_set_nr\n"                     // +
"    LDR     PC, =0xFF93D434 \n"  // Continue in firmware
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF8A2214 - 0xFF8A27CC, length=367
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    SUB     SP, SP, #0x20 \n"
"    LDR     R8, =0xBB8 \n"
"    LDR     R7, =0x41F4 \n"
"    LDR     R5, =0x1A1B0 \n"
"    MOV     R0, #0 \n"
"    ADD     R6, SP, #0x10 \n"
"    STR     R0, [SP, #0xC] \n"

"loc_FF8A2234:\n"
"    LDR     R0, [R7, #0x20] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF826D3C /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF8A2280 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x13 \n"
"    CMPNE   R0, #0x14 \n"
"    CMPNE   R0, #0x15 \n"
"    CMPNE   R0, #0x16 \n"
"    BEQ     loc_FF8A239C \n"
"    CMP     R0, #0x28 \n"
"    BEQ     loc_FF8A2374 \n"
"    ADD     R1, SP, #0xC \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8A21C4 \n"

"loc_FF8A2280:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x2D \n"
"    BNE     loc_FF8A22B0 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FF8A34C8 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF86C1DC /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x20 \n"
"    LDMFD   SP!, {R4-R8,PC} \n"

"loc_FF8A22B0:\n"
"    CMP     R1, #0x2C \n"
"    BNE     loc_FF8A22CC \n"
"    LDR     R2, [R0, #0x88]! \n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R0, R1 \n"
"    BLX     R2 \n"
"    B       loc_FF8A27C4 \n"

"loc_FF8A22CC:\n"
"    CMP     R1, #0x26 \n"
"    BNE     loc_FF8A231C \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF86C210 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF89EAF4 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF93051C \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R2, R8 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF86C11C /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0xDD2 \n"
"    BNE     loc_FF8A2360 \n"

"loc_FF8A2308:\n"
"    LDR     R1, [SP, #0x1C] \n"
"    LDR     R0, [R1, #0x8C] \n"
"    LDR     R1, [R1, #0x88] \n"
"    BLX     R1 \n"
"    B       loc_FF8A27C4 \n"

"loc_FF8A231C:\n"
"    CMP     R1, #0x27 \n"
"    BNE     loc_FF8A236C \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF8A21C4 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF86C210 /*_ClearEventFlag*/ \n"
"    MOV     R1, #0x100 \n"
"    LDR     R0, =0xFF89EB04 \n"
"    BL      sub_FF930E88 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R2, R8 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF86C11C /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8A2308 \n"
"    LDR     R1, =0xDDC \n"

"loc_FF8A2360:\n"
"    LDR     R0, =0xFF89F134 /*'ExpDrv.c'*/ \n"
"    BL      _DebugAssert \n"
"    B       loc_FF8A2308 \n"

"loc_FF8A236C:\n"
"    CMP     R1, #0x28 \n"
"    BNE     loc_FF8A2384 \n"

"loc_FF8A2374:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF8A21C4 \n"
"    B       loc_FF8A2308 \n"

"loc_FF8A2384:\n"
"    CMP     R1, #0x2B \n"
"    BNE     loc_FF8A239C \n"
"    BL      sub_FF8916AC \n"
"    BL      sub_FF892338 \n"
"    BL      sub_FF891E70 \n"
"    B       loc_FF8A2308 \n"

"loc_FF8A239C:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R4, #1 \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x11 \n"
"    CMPNE   R1, #0x12 \n"
"    BNE     loc_FF8A240C \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2-R4} \n"
"    STMIA   R6, {R2-R4} \n"
"    BL      sub_FF8A0BF4 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x88] \n"
"    LDR     R2, [R0, #0x8C] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FF8A387C \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x90] \n"
"    LDR     R2, [R0, #0x94] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    B       loc_FF8A2704 \n"

"loc_FF8A240C:\n"
"    CMP     R1, #0x13 \n"
"    CMPNE   R1, #0x14 \n"
"    CMPNE   R1, #0x15 \n"
"    CMPNE   R1, #0x16 \n"
"    BNE     loc_FF8A24C4 \n"
"    ADD     R3, SP, #0xC \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FF8A0E38 \n"
"    CMP     R0, #1 \n"
"    MOV     R4, R0 \n"
"    CMPNE   R4, #5 \n"
"    BNE     loc_FF8A2460 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R2, R4 \n"
"    LDR     R1, [R0, #0x7C]! \n"
"    LDR     R12, [R0, #0xC]! \n"
"    LDR     R3, [R0, #4] \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    B       loc_FF8A2498 \n"

"loc_FF8A2460:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    CMP     R4, #2 \n"
"    LDR     R3, [R0, #0x8C] \n"
"    CMPNE   R4, #6 \n"
"    BNE     loc_FF8A24AC \n"
"    LDR     R12, [R0, #0x88] \n"
"    MOV     R0, SP \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #1 \n"
"    BLX     R12 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FF8A1ED8 \n"

"loc_FF8A2498:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R2, [SP, #0xC] \n"
"    MOV     R1, R4 \n"
"    BL      sub_FF8A2164 \n"
"    B       loc_FF8A2704 \n"

"loc_FF8A24AC:\n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R12, [R0, #0x88] \n"
"    ADD     R0, R0, #4 \n"
"    MOV     R2, R4 \n"
"    BLX     R12 \n"
"    B       loc_FF8A2704 \n"

"loc_FF8A24C4:\n"
"    CMP     R1, #0x22 \n"
"    CMPNE   R1, #0x23 \n"
"    BNE     loc_FF8A2510 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2-R4} \n"
"    STMIA   R6, {R2-R4} \n"
"    BL      sub_FF8A0174 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x88] \n"
"    LDR     R2, [R0, #0x8C] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FF8A0470 \n"
"    B       loc_FF8A2704 \n"

"loc_FF8A2510:\n"
"    ADD     R1, R0, #4 \n"
"    LDMIA   R1, {R2,R3,R12} \n"
"    STMIA   R6, {R2,R3,R12} \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x25 \n"
"    ADDLS   PC, PC, R1, LSL#2 \n"
"    B       loc_FF8A26E4 \n"
"    B       loc_FF8A25C4 \n"
"    B       loc_FF8A25C4 \n"
"    B       loc_FF8A25CC \n"
"    B       loc_FF8A25D4 \n"
"    B       loc_FF8A25D4 \n"
"    B       loc_FF8A25D4 \n"
"    B       loc_FF8A25C4 \n"
"    B       loc_FF8A25CC \n"
"    B       loc_FF8A25D4 \n"
"    B       loc_FF8A25D4 \n"
"    B       loc_FF8A25EC \n"
"    B       loc_FF8A25EC \n"
"    B       loc_FF8A26D8 \n"
"    B       loc_FF8A26E0 \n"
"    B       loc_FF8A26E0 \n"
"    B       loc_FF8A26E0 \n"
"    B       loc_FF8A26E0 \n"
"    B       loc_FF8A26E4 \n"
"    B       loc_FF8A26E4 \n"
"    B       loc_FF8A26E4 \n"
"    B       loc_FF8A26E4 \n"
"    B       loc_FF8A26E4 \n"
"    B       loc_FF8A26E4 \n"
"    B       loc_FF8A25DC \n"
"    B       loc_FF8A25E4 \n"
"    B       loc_FF8A25E4 \n"
"    B       loc_FF8A25F8 \n"
"    B       loc_FF8A25F8 \n"
"    B       loc_FF8A2600 \n"
"    B       loc_FF8A2630 \n"
"    B       loc_FF8A2660 \n"
"    B       loc_FF8A2690 \n"
"    B       loc_FF8A26C0 \n"
"    B       loc_FF8A26C0 \n"
"    B       loc_FF8A26E4 \n"
"    B       loc_FF8A26E4 \n"
"    B       loc_FF8A26C8 \n"
"    B       loc_FF8A26D0 \n"

"loc_FF8A25C4:\n"
"    BL      sub_FF89EFE0 \n"
"    B       loc_FF8A26E4 \n"

"loc_FF8A25CC:\n"
"    BL      sub_FF89F254 \n"
"    B       loc_FF8A26E4 \n"

"loc_FF8A25D4:\n"
"    BL      sub_FF89F458 \n"
"    B       loc_FF8A26E4 \n"

"loc_FF8A25DC:\n"
"    BL      sub_FF89F6C0 \n"
"    B       loc_FF8A26E4 \n"

"loc_FF8A25E4:\n"
"    BL      sub_FF89F8B4 \n"
"    B       loc_FF8A26E4 \n"

"loc_FF8A25EC:\n"
"    BL      sub_FF89FB44_my \n"  // --> Patched. Old value = 0xFF89FB44.
"    MOV     R4, #0 \n"
"    B       loc_FF8A26E4 \n"

"loc_FF8A25F8:\n"
"    BL      sub_FF89FC80 \n"
"    B       loc_FF8A26E4 \n"

"loc_FF8A2600:\n"
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
"    BL      sub_FF8A353C \n"
"    B       loc_FF8A26E4 \n"

"loc_FF8A2630:\n"
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
"    BL      sub_FF8A3698 \n"
"    B       loc_FF8A26E4 \n"

"loc_FF8A2660:\n"
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
"    BL      sub_FF8A3744 \n"
"    B       loc_FF8A26E4 \n"

"loc_FF8A2690:\n"
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
"    BL      sub_FF8A37E4 \n"
"    B       loc_FF8A26E4 \n"

"loc_FF8A26C0:\n"
"    BL      sub_FF89FF20 \n"
"    B       loc_FF8A26E4 \n"

"loc_FF8A26C8:\n"
"    BL      sub_FF8A0574 \n"
"    B       loc_FF8A26E4 \n"

"loc_FF8A26D0:\n"
"    BL      sub_FF8A07AC \n"
"    B       loc_FF8A26E4 \n"

"loc_FF8A26D8:\n"
"    BL      sub_FF8A0924 \n"
"    B       loc_FF8A26E4 \n"

"loc_FF8A26E0:\n"
"    BL      sub_FF8A0ABC \n"

"loc_FF8A26E4:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x88] \n"
"    LDR     R2, [R0, #0x8C] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    CMP     R4, #1 \n"
"    BNE     loc_FF8A274C \n"

"loc_FF8A2704:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    MOV     R2, #0xC \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R0, R0, R1, LSL#2 \n"
"    SUB     R4, R0, #8 \n"
"    LDR     R0, =0x1A1B0 \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FFAF8AE0 \n"
"    LDR     R0, =0x1A1BC \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, SP, #0x10 \n"
"    BL      sub_FFAF8AE0 \n"
"    LDR     R0, =0x1A1C8 \n"
"    MOV     R2, #0xC \n"
"    MOV     R1, R4 \n"
"    BL      sub_FFAF8AE0 \n"
"    B       loc_FF8A27C4 \n"

"loc_FF8A274C:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0xB \n"
"    BNE     loc_FF8A2794 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF89EDE8 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #0 \n"
"    B       loc_FF8A27C0 \n"

"loc_FF8A2794:\n"
"    MOV     R3, #1 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #1 \n"
"    STR     R3, [SP] \n"
"    BL      sub_FF89EDE8 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, #1 \n"
"    STR     R3, [SP] \n"

"loc_FF8A27C0:\n"
"    BL      sub_FF89EF28 \n"

"loc_FF8A27C4:\n"
"    LDR     R0, [SP, #0x1C] \n"
"    BL      sub_FF8A34C8 \n"
"    B       loc_FF8A2234 \n"
);
}

/*************************************************************/
//** sub_FF89FB44_my @ 0xFF89FB44 - 0xFF89FC7C, length=79
void __attribute__((naked,noinline)) sub_FF89FB44_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x41F4 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x3E \n"
"    BL      sub_FF86C210 /*_ClearEventFlag*/ \n"
"    LDRSH   R0, [R4, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF89EB78 \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF89EC88 \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF89ECE0 \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_FF89ED38 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    BL      sub_FF89ED90 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R4] \n"
"    LDR     R8, =0x1A1C8 \n"
"    CMP     R0, #0xB \n"
"    MOVEQ   R6, #0 \n"
"    MOVEQ   R5, #0 \n"
"    BEQ     loc_FF89FBD4 \n"
"    CMP     R6, #1 \n"
"    BNE     loc_FF89FBD4 \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xFF89EAE4 \n"
"    MOV     R2, #2 \n"
"    BL      sub_FF930844 \n"
"    STRH    R0, [R4, #4] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    B       loc_FF89FBDC \n"

"loc_FF89FBD4:\n"
"    LDRH    R0, [R8] \n"
"    STRH    R0, [R4, #4] \n"

"loc_FF89FBDC:\n"
"    CMP     R5, #1 \n"
"    LDRNEH  R0, [R8, #8] \n"
"    BNE     loc_FF89FBF8 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    LDR     R1, =0xFF89EB68 \n"
"    MOV     R2, #0x20 \n"
"    BL      sub_FF8A34F8 \n"

"loc_FF89FBF8:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF89141C_my \n"  // --> Patched. Old value = 0xFF89141C.
"    LDRSH   R0, [R4, #8] \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF891B68 \n"
"    MOV     R1, #0 \n"
"    ADD     R0, R4, #8 \n"
"    BL      sub_FF891BF0 \n"
"    LDRSH   R0, [R4, #0xE] \n"
"    BL      sub_FF89A5E8 \n"
"    LDR     R4, =0xBB8 \n"
"    CMP     R6, #1 \n"
"    BNE     loc_FF89FC50 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #2 \n"
"    BL      sub_FF86C11C /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x583 \n"
"    LDRNE   R0, =0xFF89F134 /*'ExpDrv.c'*/ \n"
"    BLNE    _DebugAssert \n"

"loc_FF89FC50:\n"
"    CMP     R5, #1 \n"
"    LDMNEFD SP!, {R4-R8,PC} \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #0x20 \n"
"    BL      sub_FF86C11C /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x588 \n"
"    LDRNE   R0, =0xFF89F134 /*'ExpDrv.c'*/ \n"
"    LDMNEFD SP!, {R4-R8,LR} \n"
"    BNE     _DebugAssert \n"
"    LDMFD   SP!, {R4-R8,PC} \n"
);
}

/*************************************************************/
//** sub_FF89141C_my @ 0xFF89141C - 0xFF891484, length=27
void __attribute__((naked,noinline)) sub_FF89141C_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x3EF0 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R0, #1 \n"
"    MOVNE   R1, #0x140 \n"
"    LDRNE   R0, =0xFF891220 /*'Shutter.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    CMN     R4, #0xC00 \n"
"    LDREQSH R4, [R5, #2] \n"
"    CMN     R4, #0xC00 \n"
"    LDREQ   R1, =0x146 \n"
"    LDREQ   R0, =0xFF891220 /*'Shutter.c'*/ \n"
"    STRH    R4, [R5, #2] \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    MOV     R4, R0 \n"
//"  BL      _sub_FF8C73DC \n"  // --> Nullsub call removed.
"    MOV     R0, R4 \n"
"    BL      sub_FF8CF0B8 \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x14B \n"
"    LDMNEFD SP!, {R4-R6,LR} \n"
"    LDRNE   R0, =0xFF891220 /*'Shutter.c'*/ \n"
"    BNE     _DebugAssert \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}
