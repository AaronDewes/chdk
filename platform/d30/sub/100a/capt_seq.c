/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1          // see stubs_entry.S
#define NR_AUTO (0)                 // have to explictly reset value back to 0 to enable auto
#define PAUSE_FOR_FILE_COUNTER 200  // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"


/*************************************************************/
//** capt_seq_task @ 0xFF069390 - 0xFF0696B0, length=201
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R9,LR} \n"
"    LDR     R4, =0x397BC \n"
"    LDR     R7, =0x2EA4 \n"
"    MOV     R6, #0 \n"

"loc_FF0693A0:\n"
"    LDR     R0, [R7, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_00477218 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF0693CC \n"
"    LDR     R1, =0x493 \n"
"    LDR     R0, =0xFF068E4C /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R9,PC} \n"

"loc_FF0693CC:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x24 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF069678 \n"
"    B       loc_FF069470 \n"
"    B       loc_FF069488 \n"
"    B       loc_FF0694F8 \n"
"    B       loc_FF06950C \n"
"    B       loc_FF069504 \n"
"    B       loc_FF069518 \n"
"    B       loc_FF069520 \n"
"    B       loc_FF069528 \n"
"    B       loc_FF069544 \n"
"    B       loc_FF069598 \n"
"    B       loc_FF069550 \n"
"    B       loc_FF06955C \n"
"    B       loc_FF069564 \n"
"    B       loc_FF069580 \n"
"    B       loc_FF069588 \n"
"    B       loc_FF069590 \n"
"    B       loc_FF0695A0 \n"
"    B       loc_FF0695A8 \n"
"    B       loc_FF0695B0 \n"
"    B       loc_FF0695B8 \n"
"    B       loc_FF0695C0 \n"
"    B       loc_FF0695C8 \n"
"    B       loc_FF0695D0 \n"
"    B       loc_FF0695D8 \n"
"    B       loc_FF0695E0 \n"
"    B       loc_FF0695EC \n"
"    B       loc_FF0695F4 \n"
"    B       loc_FF069600 \n"
"    B       loc_FF069608 \n"
"    B       loc_FF069610 \n"
"    B       loc_FF069618 \n"
"    B       loc_FF069620 \n"
"    B       loc_FF06962C \n"
"    B       loc_FF069634 \n"
"    B       loc_FF069640 \n"
"    B       loc_FF069684 \n"

"loc_FF069470:\n"
"    BL      shooting_expo_iso_override\n"      // added
"    BL      sub_FF069C4C \n"
"    BL      shooting_expo_param_override\n"    // added
"    BL      sub_FF066ED0 \n"
"    MOV     R0, #0\n"                          // added
"    STR     R0, [R4,#0x28]\n"                  // added, fixes overrides behavior at short shutter press (from S95)
//"  LDR     R0, [R4, #0x28] \n"  // above patch makes these three lines redundant
//"  CMP     R0, #0 \n"
//"  BLNE    _sub_FF1833F8 \n"
"    B       loc_FF069684 \n"

"loc_FF069488:\n"
"    LDR     R5, [R0, #0x10] \n"
"    LDR     R0, [R4, #0x28] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF0694D0 \n"
"    LDR     R0, [R4, #0x94] \n"
"    TST     R0, #0x30 \n"
"    BLNE    sub_FF06B61C \n"
"    BL      sub_FF06B2FC \n"
"    MOV     R1, R5 \n"
"    BL      sub_FF06B354 \n"
"    LDR     R0, =0x10F \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x24 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x28 \n"
"    MOV     R0, #0x2C \n"
"    BL      _SetPropertyCase \n"

"loc_FF0694D0:\n"
"    MOV     R0, R5 \n"
"    BL      sub_FF183354_my \n"  // --> Patched. Old value = 0xFF183354.
"    BL      capt_seq_hook_raw_here\n"      // added
"    MOV     R8, R0 \n"
"    MOV     R2, R5 \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF067464 \n"
"    TST     R8, #1 \n"
"    MOVEQ   R0, R5 \n"
"    BLEQ    sub_FF182C98 \n"
"    B       loc_FF069684 \n"

"loc_FF0694F8:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF069F48 \n"
"    B       loc_FF069684 \n"

"loc_FF069504:\n"
"    BL      sub_FF069858 \n"
"    B       loc_FF069510 \n"

"loc_FF06950C:\n"
"    BL      sub_FF069C2C \n"

"loc_FF069510:\n"
"    STR     R6, [R4, #0x28] \n"
"    B       loc_FF069684 \n"

"loc_FF069518:\n"
"    BL      sub_FF069C34 \n"
"    B       loc_FF069684 \n"

"loc_FF069520:\n"
"    BL      sub_FF069E20 \n"
"    B       loc_FF069548 \n"

"loc_FF069528:\n"
"    LDR     R5, [R0, #0x10] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF183494 \n"
"    MOV     R2, R5 \n"
"    MOV     R1, #9 \n"
"    BL      sub_FF067464 \n"
"    B       loc_FF069684 \n"

"loc_FF069544:\n"
"    BL      sub_FF069EB0 \n"

"loc_FF069548:\n"
"    BL      sub_FF066ED0 \n"
"    B       loc_FF069684 \n"

"loc_FF069550:\n"
"    LDR     R0, [R4, #0x58] \n"
"    BL      sub_FF06A5C4 \n"
"    B       loc_FF069684 \n"

"loc_FF06955C:\n"
"    BL      sub_FF06A8B8 \n"
"    B       loc_FF069684 \n"

"loc_FF069564:\n"
"    LDRH    R0, [R4] \n"
"    SUB     R1, R0, #0x4200 \n"
"    SUBS    R1, R1, #0x39 \n"
"    MOVNE   R0, #0 \n"
"    MOVEQ   R0, #1 \n"
"    BL      sub_FF06A91C \n"
"    B       loc_FF069684 \n"

"loc_FF069580:\n"
"    BL      sub_FF06AB08 \n"
"    B       loc_FF069684 \n"

"loc_FF069588:\n"
"    BL      sub_FF06AF6C \n"
"    B       loc_FF069684 \n"

"loc_FF069590:\n"
"    BL      sub_FF06B020 \n"
"    B       loc_FF069684 \n"

"loc_FF069598:\n"
"    BL      sub_FF069C2C \n"
"    B       loc_FF069684 \n"

"loc_FF0695A0:\n"
"    BL      sub_FF181F6C \n"
"    B       loc_FF069684 \n"

"loc_FF0695A8:\n"
"    BL      sub_FF1821D4 \n"
"    B       loc_FF069684 \n"

"loc_FF0695B0:\n"
"    BL      sub_FF18228C \n"
"    B       loc_FF069684 \n"

"loc_FF0695B8:\n"
"    BL      sub_FF182360 \n"
"    B       loc_FF069684 \n"

"loc_FF0695C0:\n"
"    MOV     R0, #0 \n"
"    B       loc_FF0695E4 \n"

"loc_FF0695C8:\n"
"    BL      sub_FF182784 \n"
"    B       loc_FF069684 \n"

"loc_FF0695D0:\n"
"    BL      sub_FF182818 \n"
"    B       loc_FF069684 \n"

"loc_FF0695D8:\n"
"    BL      sub_FF1828D0 \n"
"    B       loc_FF069684 \n"

"loc_FF0695E0:\n"
"    MOV     R0, #1 \n"

"loc_FF0695E4:\n"
"    BL      sub_FF182614 \n"
"    B       loc_FF069684 \n"

"loc_FF0695EC:\n"
"    BL      sub_FF06A100 \n"
"    B       loc_FF069684 \n"

"loc_FF0695F4:\n"
"    BL      sub_FF06A194 \n"
"    BL      sub_FF021F04 \n"
"    B       loc_FF069684 \n"

"loc_FF069600:\n"
"    BL      sub_FF182430 \n"
"    B       loc_FF069684 \n"

"loc_FF069608:\n"
"    BL      sub_FF182498 \n"
"    B       loc_FF069684 \n"

"loc_FF069610:\n"
"    BL      sub_FF06C8D8 \n"
"    B       loc_FF069684 \n"

"loc_FF069618:\n"
"    BL      sub_FF06C960 \n"
"    B       loc_FF069684 \n"

"loc_FF069620:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF1829E8 \n"
"    B       loc_FF069684 \n"

"loc_FF06962C:\n"
"    BL      sub_FF182A58 \n"
"    B       loc_FF069684 \n"

"loc_FF069634:\n"
"    BL      sub_FF06C9C8 \n"
"    BL      sub_FF06C980 \n"
"    B       loc_FF069684 \n"

"loc_FF069640:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF183BAC \n"
"    MOV     R0, #1 \n"
"    BL      sub_FF183CE0 \n"
"    LDRH    R0, [R4, #0xA4] \n"
"    CMP     R0, #4 \n"
"    LDRNEH  R0, [R4] \n"
"    SUBNE   R1, R0, #0x4200 \n"
"    SUBNES  R1, R1, #0x2E \n"
"    BNE     loc_FF069684 \n"
"    BL      sub_FF06C960 \n"
"    BL      sub_FF06CFB0 \n"
"    BL      sub_FF06CDF0 \n"
"    B       loc_FF069684 \n"

"loc_FF069678:\n"
"    LDR     R1, =0x5F4 \n"
"    LDR     R0, =0xFF068E4C /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF069684:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R7] \n"
"    BL      sub_0047AC6C /*_SetEventFlag*/ \n"
"    LDR     R5, [SP] \n"
"    LDR     R0, [R5, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x117 \n"
"    LDREQ   R0, =0xFF068E4C /*'SsShootTask.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    STR     R6, [R5, #8] \n"
"    B       loc_FF0693A0 \n"
);
}

/*************************************************************/
//** sub_FF183354_my @ 0xFF183354 - 0xFF1833F4, length=41
void __attribute__((naked,noinline)) sub_FF183354_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x397BC \n"
"    MOV     R6, R0 \n"
"    LDR     R0, [R5, #0x28] \n"
"    MOV     R4, #0 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF183384 \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF06E778 \n"
"    TST     R0, #1 \n"
"    MOVNE   R0, #1 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"

"loc_FF183384:\n"
"    BL      sub_FF069C3C \n"
"    LDR     R0, [R5, #0x28] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF1833E0 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF182BD4 \n"
"    TST     R0, #1 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF182F84 \n"
"    BL      sub_FF183978 \n"
"    BL      sub_FF0672E0 \n"
"    BL      wait_until_remote_button_is_released\n"    // added
"    BL      capt_seq_hook_set_nr\n"                    // added
"    MOV     R0, #2 \n"
"    BL      sub_FF06FEF8 \n"
"    LDR     R0, [R5, #0x94] \n"
"    TST     R0, #0x10 \n"
"    MOV     R0, R6 \n"
"    BEQ     loc_FF1833D4 \n"
"    BL      sub_FF2EB4C4 \n"
"    B       loc_FF1833D8 \n"

"loc_FF1833D4:\n"
"    BL      sub_FF2EB094 \n"

"loc_FF1833D8:\n"
"    MOV     R4, R0 \n"
"    B       loc_FF1833F0 \n"

"loc_FF1833E0:\n"
"    LDR     R0, =0x7254 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0 \n"
"    MOVNE   R4, #0x1D \n"

"loc_FF1833F0:\n"
"    MOV     R0, R4 \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF0B2264 - 0xFF0B28F4, length=421
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    SUB     SP, SP, #0x2C \n"
"    LDR     R6, =0x42F0 \n"
"    LDR     R7, =0xBB8 \n"
"    LDR     R4, =0x567C0 \n"
"    MOV     R0, #0 \n"
"    ADD     R5, SP, #0x1C \n"
"    STR     R0, [SP, #0xC] \n"

"loc_FF0B2284:\n"
"    LDR     R0, [R6, #0x20] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #0x28 \n"
"    BL      sub_00477218 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF0B22D0 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x14 \n"
"    CMPNE   R0, #0x15 \n"
"    CMPNE   R0, #0x16 \n"
"    CMPNE   R0, #0x17 \n"
"    BEQ     loc_FF0B2430 \n"
"    CMP     R0, #0x2A \n"
"    BEQ     loc_FF0B23B8 \n"
"    ADD     R1, SP, #0xC \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF0B2214 \n"

"loc_FF0B22D0:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x30 \n"
"    BNE     loc_FF0B22FC \n"
"    BL      sub_FF0B3660 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #1 \n"
"    BL      sub_0047AC6C /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x2C \n"
"    LDMFD   SP!, {R4-R9,PC} \n"

"loc_FF0B22FC:\n"
"    CMP     R1, #0x2F \n"
"    BNE     loc_FF0B2318 \n"
"    LDR     R2, [R0, #0x8C]! \n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R0, R1 \n"
"    BLX     R2 \n"
"    B       loc_FF0B28EC \n"

"loc_FF0B2318:\n"
"    CMP     R1, #0x28 \n"
"    BNE     loc_FF0B2368 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_0047ACA0 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF0AD148 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF173D90 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_0047ABAC /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x1599 \n"
"    BNE     loc_FF0B2424 \n"

"loc_FF0B2354:\n"
"    LDR     R1, [SP, #0x28] \n"
"    LDR     R0, [R1, #0x90] \n"
"    LDR     R1, [R1, #0x8C] \n"
"    BLX     R1 \n"
"    B       loc_FF0B28EC \n"

"loc_FF0B2368:\n"
"    CMP     R1, #0x29 \n"
"    BNE     loc_FF0B23B0 \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF0B2214 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_0047ACA0 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF0AD158 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF173F30 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_0047ABAC /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF0B2354 \n"
"    LDR     R1, =0x15A3 \n"
"    B       loc_FF0B2424 \n"

"loc_FF0B23B0:\n"
"    CMP     R1, #0x2A \n"
"    BNE     loc_FF0B23C8 \n"

"loc_FF0B23B8:\n"
"    LDR     R0, [SP, #0x28] \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF0B2214 \n"
"    B       loc_FF0B2354 \n"

"loc_FF0B23C8:\n"
"    CMP     R1, #0x2D \n"
"    BNE     loc_FF0B23E0 \n"
"    BL      sub_FF09DC68 \n"
"    BL      sub_FF09E93C \n"
"    BL      sub_FF09E4A8 \n"
"    B       loc_FF0B2354 \n"

"loc_FF0B23E0:\n"
"    CMP     R1, #0x2E \n"
"    BNE     loc_FF0B2430 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #4 \n"
"    BL      sub_0047ACA0 /*_ClearEventFlag*/ \n"
"    LDR     R1, =0xFF0AD178 \n"
"    LDR     R0, =0xFFFFF400 \n"
"    MOV     R2, #4 \n"
"    BL      sub_FF09D6B8 \n"
"    BL      sub_FF09D948 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #4 \n"
"    BL      sub_0047AAC8 /*_WaitForAnyEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF0B2354 \n"
"    LDR     R1, =0x15CB \n"

"loc_FF0B2424:\n"
"    LDR     R0, =0xFF0AD950 /*'ExpDrv.c'*/ \n"
"    BL      _DebugAssert \n"
"    B       loc_FF0B2354 \n"

"loc_FF0B2430:\n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R8, #1 \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x12 \n"
"    CMPNE   R1, #0x13 \n"
"    BNE     loc_FF0B2498 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF0B03D8 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF0B3A80 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x98] \n"
"    LDR     R3, [R0, #0x94] \n"
"    B       loc_FF0B27B0 \n"

"loc_FF0B2498:\n"
"    CMP     R1, #0x14 \n"
"    CMPNE   R1, #0x15 \n"
"    CMPNE   R1, #0x16 \n"
"    CMPNE   R1, #0x17 \n"
"    BNE     loc_FF0B2550 \n"
"    ADD     R3, SP, #0xC \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF0B0638 \n"
"    CMP     R0, #1 \n"
"    MOV     R9, R0 \n"
"    CMPNE   R9, #5 \n"
"    BNE     loc_FF0B24EC \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, R9 \n"
"    LDR     R1, [R0, #0x7C]! \n"
"    LDR     R12, [R0, #0x10]! \n"
"    LDR     R3, [R0, #4] \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    B       loc_FF0B2524 \n"

"loc_FF0B24EC:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R9, #2 \n"
"    LDR     R3, [R0, #0x90] \n"
"    CMPNE   R9, #6 \n"
"    BNE     loc_FF0B2538 \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF0B1EEC \n"

"loc_FF0B2524:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R2, [SP, #0xC] \n"
"    MOV     R1, R9 \n"
"    BL      sub_FF0B21B4 \n"
"    B       loc_FF0B27B8 \n"

"loc_FF0B2538:\n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R12 \n"
"    B       loc_FF0B27B8 \n"

"loc_FF0B2550:\n"
"    CMP     R1, #0x24 \n"
"    CMPNE   R1, #0x25 \n"
"    BNE     loc_FF0B259C \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF0AF158 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF0AF62C \n"
"    B       loc_FF0B27B8 \n"

"loc_FF0B259C:\n"
"    ADD     R1, R0, #4 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x28 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF0B27A0 \n"
"    B       loc_FF0B2658 \n"
"    B       loc_FF0B2658 \n"
"    B       loc_FF0B2660 \n"
"    B       loc_FF0B2668 \n"
"    B       loc_FF0B2668 \n"
"    B       loc_FF0B2668 \n"
"    B       loc_FF0B2658 \n"
"    B       loc_FF0B2660 \n"
"    B       loc_FF0B2668 \n"
"    B       loc_FF0B2668 \n"
"    B       loc_FF0B2680 \n"
"    B       loc_FF0B2680 \n"
"    B       loc_FF0B278C \n"
"    B       loc_FF0B2794 \n"
"    B       loc_FF0B2794 \n"
"    B       loc_FF0B2794 \n"
"    B       loc_FF0B2794 \n"
"    B       loc_FF0B279C \n"
"    B       loc_FF0B27A0 \n"
"    B       loc_FF0B27A0 \n"
"    B       loc_FF0B27A0 \n"
"    B       loc_FF0B27A0 \n"
"    B       loc_FF0B27A0 \n"
"    B       loc_FF0B27A0 \n"
"    B       loc_FF0B2670 \n"
"    B       loc_FF0B2678 \n"
"    B       loc_FF0B2678 \n"
"    B       loc_FF0B2678 \n"
"    B       loc_FF0B268C \n"
"    B       loc_FF0B268C \n"
"    B       loc_FF0B2694 \n"
"    B       loc_FF0B26CC \n"
"    B       loc_FF0B2704 \n"
"    B       loc_FF0B273C \n"
"    B       loc_FF0B2774 \n"
"    B       loc_FF0B2774 \n"
"    B       loc_FF0B27A0 \n"
"    B       loc_FF0B27A0 \n"
"    B       loc_FF0B277C \n"
"    B       loc_FF0B2784 \n"

"loc_FF0B2658:\n"
"    BL      sub_FF0AD784 \n"
"    B       loc_FF0B27A0 \n"

"loc_FF0B2660:\n"
"    BL      sub_FF0ADA7C \n"
"    B       loc_FF0B27A0 \n"

"loc_FF0B2668:\n"
"    BL      sub_FF0ADCE4 \n"
"    B       loc_FF0B27A0 \n"

"loc_FF0B2670:\n"
"    BL      sub_FF0ADFD8 \n"
"    B       loc_FF0B27A0 \n"

"loc_FF0B2678:\n"
"    BL      sub_FF0AE1F0 \n"
"    B       loc_FF0B27A0 \n"

"loc_FF0B2680:\n"
"    BL      sub_FF0AE6E0_my \n"  // --> Patched. Old value = 0xFF0AE6E0.
"    MOV     R8, #0 \n"
"    B       loc_FF0B27A0 \n"

"loc_FF0B268C:\n"
"    BL      sub_FF0AE8BC \n"
"    B       loc_FF0B27A0 \n"

"loc_FF0B2694:\n"
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
"    BL      sub_FF0B36F4 \n"
"    B       loc_FF0B27A0 \n"

"loc_FF0B26CC:\n"
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
"    BL      sub_FF0B3880 \n"
"    B       loc_FF0B27A0 \n"

"loc_FF0B2704:\n"
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
"    BL      sub_FF0B3934 \n"
"    B       loc_FF0B27A0 \n"

"loc_FF0B273C:\n"
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
"    BL      sub_FF0B39DC \n"
"    B       loc_FF0B27A0 \n"

"loc_FF0B2774:\n"
"    BL      sub_FF0AEF0C \n"
"    B       loc_FF0B27A0 \n"

"loc_FF0B277C:\n"
"    BL      sub_FF0AF730 \n"
"    B       loc_FF0B27A0 \n"

"loc_FF0B2784:\n"
"    BL      sub_FF0AFC88 \n"
"    B       loc_FF0B27A0 \n"

"loc_FF0B278C:\n"
"    BL      sub_FF0AFEAC \n"
"    B       loc_FF0B27A0 \n"

"loc_FF0B2794:\n"
"    BL      sub_FF0B0068 \n"
"    B       loc_FF0B27A0 \n"

"loc_FF0B279C:\n"
"    BL      sub_FF0B01D0 \n"

"loc_FF0B27A0:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    LDR     R3, [R0, #0x8C] \n"

"loc_FF0B27B0:\n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"

"loc_FF0B27B8:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x10 \n"
"    BEQ     loc_FF0B27F0 \n"
"    BGT     loc_FF0B27E0 \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #4 \n"
"    CMPNE   R0, #0xE \n"
"    BNE     loc_FF0B2824 \n"
"    B       loc_FF0B27F0 \n"

"loc_FF0B27E0:\n"
"    CMP     R0, #0x13 \n"
"    CMPNE   R0, #0x17 \n"
"    CMPNE   R0, #0x1A \n"
"    BNE     loc_FF0B2824 \n"

"loc_FF0B27F0:\n"
"    LDRSH   R0, [R4] \n"
"    CMN     R0, #0xC00 \n"
"    LDRNESH R1, [R4, #8] \n"
"    CMNNE   R1, #0xC00 \n"
"    STRNEH  R0, [SP, #0x1C] \n"
"    STRNEH  R1, [SP, #0x24] \n"
"    BNE     loc_FF0B2824 \n"
"    ADD     R0, SP, #0x10 \n"
"    BL      sub_FF0B3C90 \n"
"    LDRH    R0, [SP, #0x10] \n"
"    STRH    R0, [SP, #0x1C] \n"
"    LDRH    R0, [SP, #0x18] \n"
"    STRH    R0, [SP, #0x24] \n"

"loc_FF0B2824:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R8, #1 \n"
"    BNE     loc_FF0B2874 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R0, R0, R1, LSL#2 \n"
"    SUB     R8, R0, #8 \n"
"    LDR     R0, =0x567C0 \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_0047C17C \n"
"    LDR     R0, =0x567CC \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_0047C17C \n"
"    LDR     R0, =0x567D8 \n"
"    MOV     R2, #0xC \n"
"    MOV     R1, R8 \n"
"    BL      sub_0047C17C \n"
"    B       loc_FF0B28EC \n"

"loc_FF0B2874:\n"
"    LDR     R0, [R0] \n"
"    MOV     R3, #1 \n"
"    CMP     R0, #0xB \n"
"    BNE     loc_FF0B28B8 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF0AD564 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    B       loc_FF0B28E8 \n"

"loc_FF0B28B8:\n"
"    MOV     R2, #1 \n"
"    STRD    R2, [SP] \n"
"    MOV     R3, R2 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, R2 \n"
"    BL      sub_FF0AD564 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, R3 \n"
"    STR     R3, [SP] \n"
"    STR     R3, [SP, #4] \n"

"loc_FF0B28E8:\n"
"    BL      sub_FF0AD6D0 \n"

"loc_FF0B28EC:\n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF0B3660 \n"
"    B       loc_FF0B2284 \n"
);
}

/*************************************************************/
//** sub_FF0AE6E0_my @ 0xFF0AE6E0 - 0xFF0AE7A0, length=49
void __attribute__((naked,noinline)) sub_FF0AE6E0_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x42F0 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x3E \n"
"    BL      sub_0047ACA0 /*_ClearEventFlag*/ \n"
"    MOV     R2, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF0AD1D8 \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF0AD37C \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF0AD3D4 \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_FF0AD42C \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF0AD484 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R4] \n"
"    LDR     R8, =0x567D8 \n"
"    CMP     R0, #0xB \n"
"    MOVEQ   R6, #0 \n"
"    MOVEQ   R5, R6 \n"
"    BEQ     loc_FF0AE774 \n"
"    CMP     R6, #1 \n"
"    BNE     loc_FF0AE774 \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xFF0AD138 \n"
"    MOV     R2, #2 \n"
"    BL      sub_FF173E14 \n"
"    STRH    R0, [R4, #4] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    B       loc_FF0AE77C \n"

"loc_FF0AE774:\n"
"    LDRH    R0, [R8] \n"
"    STRH    R0, [R4, #4] \n"

"loc_FF0AE77C:\n"
"    CMP     R5, #1 \n"
"    LDRNEH  R0, [R8, #8] \n"
"    BNE     loc_FF0AE798 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    LDR     R1, =0xFF0AD1BC \n"
"    MOV     R2, #0x20 \n"
"    BL      sub_FF0B36B0 \n"

"loc_FF0AE798:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF09D9B4_my \n"  // --> Patched. Old value = 0xFF09D9B4.
"    LDR     PC, =0xFF0AE7A4 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF09D9B4_my @ 0xFF09D9B4 - 0xFF09D9F4, length=17
void __attribute__((naked,noinline)) sub_FF09D9B4_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x3F60 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R0, #1 \n"
"    LDRNE   R1, =0x14D \n"
"    LDRNE   R0, =0xFF09D7EC /*'Shutter.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    CMN     R4, #0xC00 \n"
"    LDREQSH R4, [R5, #2] \n"
"    CMN     R4, #0xC00 \n"
"    LDREQ   R1, =0x153 \n"
"    LDREQ   R0, =0xFF09D7EC /*'Shutter.c'*/ \n"
"    STRH    R4, [R5, #2] \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    LDR     PC, =0xFF09D9F8 \n"  // Continue in firmware
);
}
