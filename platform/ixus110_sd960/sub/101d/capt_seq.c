#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"

static long *nrflag = (long*)(0x6418-0x08);  // Found @ ff9266dc & ff9266f8

#include "../../../generic/capt_seq.c"


void __attribute__((naked,noinline)) capt_seq_task() { // sub_FF85EAE4
asm volatile (
      "    STMFD   SP!, {R3-R9,LR} \n" 
      "    LDR     R6, =0x298C \n" 
      "    LDR     R4, =0x14FD4 \n" 
      "    MOV     R9, #1 \n" 
      "    MOV     R7, #0 \n" 
"loc_FF85EAF8:\n"
      "    LDR     R0, [R6, #4] \n" 
      "    MOV     R2, #0 \n" 
      "    MOV     R1, SP \n" 
      "    BL      sub_FF826A0C \n" 
      "    TST     R0, #1 \n" 
      "    BEQ     loc_FF85EB24 \n" 
      "    LDR     R1, =0x588 \n" 
      "    LDR     R0, =0xFF85E670 \n" 
      "    BL      _DebugAssert \n" 
      "    BL      _ExitTask \n" 
      "    LDMFD   SP!, {R3-R9,PC} \n" 
"loc_FF85EB24:\n"
      "    LDR     R0, [SP] \n" 
      "    LDR     R1, [R0] \n" 
      "    CMP     R1, #0x1D \n" 
      "    ADDLS   PC, PC, R1, LSL #2 \n" 
      "    B       loc_FF85EDA0 \n" 
      "    B       loc_FF85EBB0 \n" 
      "    B       loc_FF85EC14 \n" 
      "    B       loc_FF85EC50 \n" 
      "    B       loc_FF85EC64 \n" 
      "    B       loc_FF85EC5C \n" 
      "    B       loc_FF85EC6C \n" 
      "    B       loc_FF85EC74 \n" 
      "    B       loc_FF85EC7C \n" 
      "    B       loc_FF85ECD4 \n" 
      "    B       loc_FF85ECFC \n" 
      "    B       loc_FF85ECE0 \n" 
      "    B       loc_FF85ECEC \n" 
      "    B       loc_FF85ECF4 \n" 
      "    B       loc_FF85ED04 \n" 
      "    B       loc_FF85ED0C \n" 
      "    B       loc_FF85ED14 \n" 
      "    B       loc_FF85ED1C \n" 
      "    B       loc_FF85ED24 \n" 
      "    B       loc_FF85ED30 \n" 
      "    B       loc_FF85ED38 \n" 
      "    B       loc_FF85ED40 \n" 
      "    B       loc_FF85ED48 \n" 
      "    B       loc_FF85ED50 \n" 
      "    B       loc_FF85ED5C \n" 
      "    B       loc_FF85ED64 \n" 
      "    B       loc_FF85ED6C \n" 
      "    B       loc_FF85ED74 \n" 
      "    B       loc_FF85ED7C \n" 
      "    B       loc_FF85ED88 \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85EBB0:\n"
      "    BL      sub_FF85F404 \n" 
// taken from d10: only do quick press hack if overrides are active
"                BL      captseq_hack_override_active\n"  // + returns 1 if tv or sv override in effect
"                STR     R0,[SP,#-4]!\n"                  // + push return value
"                BL      shooting_expo_param_override\n"  // +
      "    BL      sub_FF85C938 \n" 
"                LDR     R0,[SP],#4\n"                    // + pop override hack
"                CMP     R0, #1\n"                        // +
"                MOVEQ   R0, #0\n"                        // +
"                STREQ   R0, [R4,#0x24]\n"                // + fixes overrides behavior at short shutter press
"                LDRNE   R0, [R4,#0x24]\n"                // +
"                CMPNE   R0, #0\n"                        // +
//      "    LDR     R0, [R4, #0x24] \n"                  // -
//      "    CMP     R0, #0 \n"                           // -
      "    BEQ     loc_FF85EDAC \n" 
      "    BL      sub_FF85E34C \n" 
      "    MOV     R5, R0 \n" 
      "    LDR     R0, [R4, #0x24] \n" 
      "    CMP     R0, #0 \n" 
      "    BEQ     loc_FF85EBF8 \n" 
      "    MOV     R0, #0xC \n" 
      "    BL      sub_FF863420 \n" 
      "    TST     R0, #1 \n" 
      "    STRNE   R9, [R6, #0x10] \n" 
      "    LDRNE   R0, [R5, #8] \n" 
      "    ORRNE   R0, R0, #0x40000000 \n" 
      "    STRNE   R0, [R5, #8] \n" 
      "    BNE     loc_FF85EDAC \n" 
"loc_FF85EBF8:\n"
      "    MOV     R0, R5 \n" 
      "    BL      sub_FF85E5F0 \n" 
      "    MOV     R0, R5 \n" 
      "    BL      sub_FF926654_my \n" // ->
      "    TST     R0, #1 \n" 
      "    STRNE   R9, [R6, #0x10] \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85EC14:\n"
      "    LDR     R0, [R4, #0x24] \n" 
      "    CMP     R0, #0 \n" 
      "    BNE     loc_FF85EC40 \n" 
      "    MOV     R0, #0xC \n" 
      "    BL      sub_FF863420 \n" 
      "    TST     R0, #1 \n" 
      "    LDRNE   R0, [SP] \n" 
      "    MOVNE   R1, #1 \n" 
      "    LDRNE   R2, [R0, #0xC] \n" 
      "    MOVNE   R0, #1 \n" 
      "    BNE     loc_FF85ECCC \n" 
"loc_FF85EC40:\n"
      "    LDR     R0, [SP] \n" 
      "    BL      sub_FF85EEC4_my \n" // ->
"loc_FF85EC48:\n"
      "    STR     R7, [R4, #0x24] \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85EC50:\n"
      "    MOV     R0, #1 \n" 
      "    BL      sub_FF85F61C \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85EC5C:\n"
      "    BL      sub_FF85F04C \n" 
      "    B       loc_FF85EC48 \n" 
"loc_FF85EC64:\n"
      "    BL      sub_FF85F3E4 \n" 
      "    B       loc_FF85EC48 \n" 
"loc_FF85EC6C:\n"
      "    BL      sub_FF85F3EC \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85EC74:\n"
      "    BL      sub_FF85F53C \n" 
      "    B       loc_FF85ECD8 \n" 
"loc_FF85EC7C:\n"
      "    LDR     R5, [R0, #0xC] \n" 
      "    BL      sub_FF85F3F4 \n" 
      "    MOV     R0, R5 \n" 
      "    BL      sub_FF925634 \n" 
      "    TST     R0, #1 \n" 
      "    MOV     R8, R0 \n" 
      "    BNE     loc_FF85ECBC \n" 
      "    BL      sub_FF86F780 \n" 
      "    STR     R0, [R5, #0x18] \n" 
      "    MOV     R0, R5 \n" 
      "    BL      sub_FF92656C \n" 
      "    MOV     R0, R5 \n" 
      "    BL      sub_FF926970 \n" 
      "    MOV     R8, R0 \n" 
      "    LDR     R0, [R5, #0x18] \n" 
      "    BL      sub_FF86F994 \n" 
"loc_FF85ECBC:\n"
      "    BL      sub_FF85F3E4 \n" 
      "    MOV     R2, R5 \n" 
      "    MOV     R1, #9 \n" 
      "    MOV     R0, R8 \n" 
"loc_FF85ECCC:\n"
      "    BL      sub_FF85CE4C \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ECD4:\n"
      "    BL      sub_FF85F59C \n" 
"loc_FF85ECD8:\n"
      "    BL      sub_FF85C938 \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ECE0:\n"
      "    LDR     R0, [R4, #0x54] \n" 
      "    BL      sub_FF85F9B0 \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ECEC:\n"
      "    BL      sub_FF85FC64 \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ECF4:\n"
      "    BL      sub_FF85FCF8 \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ECFC:\n"
      "    BL      sub_FF85F3E4 \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ED04:\n"
      "    BL      sub_FF925844 \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ED0C:\n"
      "    BL      sub_FF925A2C \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ED14:\n"
      "    BL      sub_FF925ABC \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ED1C:\n"
      "    BL      sub_FF925B70 \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ED24:\n"
      "    MOV     R0, #0 \n" 
      "    BL      sub_FF925D94 \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ED30:\n"
      "    BL      sub_FF925ECC \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ED38:\n"
      "    BL      sub_FF925F5C \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ED40:\n"
      "    BL      sub_FF92601C \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ED48:\n"
      "    BL      sub_FF85F79C \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ED50:\n"
      "    BL      sub_FF85F83C \n" 
      "    BL      sub_FF824A34 \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ED5C:\n"
      "    BL      sub_FF925C2C \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ED64:\n"
      "    BL      sub_FF925C98 \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ED6C:\n"
      "    BL      sub_FF861C30 \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ED74:\n"
      "    BL      sub_FF861C98 \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ED7C:\n"
      "    BL      sub_FF861CF4 \n" 
      "    BL      sub_FF861CB4 \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85ED88:\n"
      "    MOV     R0, #1 \n" 
      "    BL      sub_FF927248 \n" 
      "    LDRH    R0, [R4, #0x98] \n" 
      "    CMP     R0, #4 \n" 
      "    BLNE    sub_FF861F60 \n" 
      "    B       loc_FF85EDAC \n" 
"loc_FF85EDA0:\n"
      "    LDR     R1, =0x6C9 \n" 
      "    LDR     R0, =0xFF85E670 \n" 
      "    BL      _DebugAssert \n" 
"loc_FF85EDAC:\n"
      "    LDR     R0, [SP] \n" 
      "    LDR     R1, [R0, #4] \n" 
      "    LDR     R0, [R6] \n" 
      "    BL      sub_FF867508 \n" 
      "    LDR     R5, [SP] \n" 
      "    LDR     R0, [R5, #8] \n" 
      "    CMP     R0, #0 \n" 
      "    LDREQ   R1, =0x12B \n" 
      "    LDREQ   R0, =0xFF85E670 \n" 
      "    BLEQ    _DebugAssert \n" 
      "    STR     R7, [R5, #8] \n" 
      "    B       loc_FF85EAF8 \n" 
      );
}


void __attribute__((naked,noinline)) sub_FF926654_my(  ) {
asm volatile (
      "    STMFD   SP!, {R0-R8,LR} \n" 
      "    MOV     R4, R0 \n" 
      "    BL      sub_FF9273B8 \n" 
      "    MVN     R1, #0 \n" 
      "    BL      sub_FF86753C \n" 
      "    LDR     R5, =0x6410 \n" 
      "    LDR     R0, [R5, #0xC] \n" 
      "    CMP     R0, #0 \n" 
      "    BNE     loc_FF9266A4 \n" 
      "    MOV     R1, #1 \n" 
      "    MOV     R0, #0 \n" 
      "    BL      sub_FF827254 \n" 
      "    STR     R0, [R5, #0xC] \n" 
      "    MOV     R3, #0 \n" 
      "    STR     R3, [SP] \n" 
      "    LDR     R3, =0xFF92610C \n" 
      "    LDR     R0, =0xFF9268DC \n" 
      "    MOV     R2, #0x400 \n" 
      "    MOV     R1, #0x17 \n" 
      "    BL      sub_FF827220 \n" 
"loc_FF9266A4:\n"
      "    MOV     R2, #4 \n" 
      "    ADD     R1, SP, #8 \n" 
      "    MOV     R0, #0x8A \n" 
      "    BL      sub_FF86F5F0 \n" 
      "    TST     R0, #1 \n" 
      "    LDRNE   R1, =0x3A7 \n" 
      "    LDRNE   R0, =0xFF9263A4 \n" 
      "    BLNE    _DebugAssert \n" 
      "    LDR     R8, =0x15098 \n" 
      "    LDR     R7, =0x14FD4 \n" 
      "    LDRSH   R1, [R8, #0xE] \n" 
      "    LDR     R0, [R7, #0x8C] \n" 
      "    BL      sub_FF8E660C \n" 
      "    BL      sub_FF8470A4 \n" 
      "    LDR     R3, =0x6418 \n" 
      "    STRH    R0, [R4, #0x9C] \n" 
      "    SUB     R2, R3, #4 \n" 
      "    STRD    R2, [SP] \n" 
      "    MOV     R1, R0 \n" 
      "    LDRH    R0, [R7, #0x5C] \n" 
      "    LDRSH   R2, [R8, #0xC] \n" 
      "    SUB     R3, R3, #8 \n" 
      "    BL      sub_FF9289F0 \n" 
"                BL      wait_until_remote_button_is_released\n" // + untested!
"                BL      capt_seq_hook_set_nr\n" // +
      "    LDR PC, =0xff926700\n" // jump back to ROM
    );
}


void __attribute__((naked,noinline)) sub_FF85EEC4_my(  ) {
asm volatile (
      "    STMFD   SP!, {R4-R6,LR} \n" 
      "    LDR     R4, [R0, #0xC] \n" 
      "    LDR     R6, =0x14FD4 \n" 
      "    LDR     R0, [R4, #8] \n" 
      "    MOV     R5, #0 \n" 
      "    ORR     R0, R0, #1 \n" 
      "    STR     R0, [R4, #8] \n" 
      "    LDR     R0, [R6, #0x24] \n" 
      "    CMP     R0, #0 \n" 
      "    MOVEQ   R0, #2 \n" 
      "    BLEQ    sub_FF85A064 \n" 
      "    BL      sub_FF85F3F4 \n" 
      "    LDR     R0, [R6, #0x24] \n" 
      "    CMP     R0, #0 \n" 
      "    BNE     loc_FF85EF74 \n" 
      "    MOV     R0, #0 \n" 
      "    BL      sub_FF927248 \n" 
      "    MOV     R0, R4 \n" 
      "    BL      sub_FF85F744 \n" 
      "    MOV     R0, R4 \n" 
      "    BL      sub_FF925284 \n" 
      "    CMP     R0, #0 \n" 
      "    BEQ     loc_FF85EF44 \n" 
      "    BL      sub_FF927288 \n" 
      "    MOV     R0, R4 \n" 
      "    BL      sub_FF925368 \n" 
      "    TST     R0, #1 \n" 
      "    MOVNE   R2, R4 \n" 
      "    LDMNEFD SP!, {R4-R6,LR} \n" 
      "    MOVNE   R1, #1 \n" 
      "    BNE     sub_FF85CE4C \n" 
      "    B       loc_FF85EF50 \n" 
"loc_FF85EF44:\n"
      "    MOV     R0, R4 \n" 
      "    BL      sub_FF925304 \n" 
      "    BL      sub_FF927288 \n" 
"loc_FF85EF50:\n"
      "    MOV     R0, R4 \n" 
      "    BL      sub_FF85E5F0 \n" 
      "    MOV     R0, R4 \n" 
      "    BL      sub_FF92656C \n" 
      "    BL      sub_FF9270D8 \n" 
      "    MOV     R0, R4 \n" 
      "    BL      sub_FF926654_my \n" // ->
      "    MOV     R5, R0 \n" 
      "    B       loc_FF85EF84 \n" 
"loc_FF85EF74:\n"
      "    LDR     R0, =0x298C \n" 
      "    LDR     R0, [R0, #0x10] \n" 
      "    CMP     R0, #0 \n" 
      "    MOVNE   R5, #0x1D \n" 
"loc_FF85EF84:\n"
"                BL      capt_seq_hook_raw_here\n" // +
      "    BL      sub_FF861C98 \n" 
      "    BL      sub_FF861CE0 \n" 
      "    BL      sub_FF861D20 \n" 
      "    MOV     R2, R4 \n" 
      "    MOV     R1, #1 \n" 
      "    MOV     R0, R5 \n" 
      "    BL      sub_FF85CE4C \n" 
      "    BL      sub_FF926914 \n" 
      "    CMP     R0, #0 \n" 
      "    LDRNE   R0, [R4, #8] \n" 
      "    ORRNE   R0, R0, #0x2000 \n" 
      "    STRNE   R0, [R4, #8] \n" 
      "    LDMFD   SP!, {R4-R6,PC} \n" 
     );
}



void __attribute__((naked,noinline)) exp_drv_task() { //sub_FF89D8CC
asm volatile (
      "    STMFD   SP!, {R4-R8,LR} \n" 
      "    SUB     SP, SP, #0x20 \n" 
      "    LDR     R8, =0xBB8 \n" 
      "    LDR     R7, =0x3F08 \n" 
      "    LDR     R5, =0x19D3C \n" 
      "    MOV     R0, #0 \n" 
      "    ADD     R6, SP, #0x10 \n" 
      "    STR     R0, [SP, #0xC] \n" 
"loc_FF89D8EC:\n"
      "    LDR     R0, [R7, #0x20] \n" 
      "    MOV     R2, #0 \n" 
      "    ADD     R1, SP, #0x1C \n" 
      "    BL      sub_FF826A0C \n" 
      "    LDR     R0, [SP, #0xC] \n" 
      "    CMP     R0, #1 \n" 
      "    BNE     loc_FF89D938 \n" 
      "    LDR     R0, [SP, #0x1C] \n" 
      "    LDR     R0, [R0] \n" 
      "    CMP     R0, #0x13 \n" 
      "    CMPNE   R0, #0x14 \n" 
      "    CMPNE   R0, #0x15 \n" 
      "    CMPNE   R0, #0x16 \n" 
      "    BEQ     loc_FF89DA54 \n" 
      "    CMP     R0, #0x28 \n" 
      "    BEQ     loc_FF89DA2C \n" 
      "    ADD     R1, SP, #0xC \n" 
      "    MOV     R0, #0 \n" 
      "    BL      sub_FF89D87C \n" 
"loc_FF89D938:\n"
      "    LDR     R0, [SP, #0x1C] \n" 
      "    LDR     R1, [R0] \n" 
      "    CMP     R1, #0x2D \n" 
      "    BNE     loc_FF89D968 \n" 
      "    LDR     R0, [SP, #0x1C] \n" 
      "    BL      sub_FF89EB80 \n" 
      "    LDR     R0, [R7, #0x1C] \n" 
      "    MOV     R1, #1 \n" 
      "    BL      sub_FF867508 \n" 
      "    BL      _ExitTask \n" 
      "    ADD     SP, SP, #0x20 \n" 
      "    LDMFD   SP!, {R4-R8,PC} \n" 
"loc_FF89D968:\n"
      "    CMP     R1, #0x2C \n" 
      "    BNE     loc_FF89D984 \n" 
      "    LDR     R2, [R0, #0x88]! \n" 
      "    LDR     R1, [R0, #4] \n" 
      "    MOV     R0, R1 \n" 
      "    BLX     R2 \n" 
      "    B       loc_FF89DE7C \n" 
"loc_FF89D984:\n"
      "    CMP     R1, #0x26 \n" 
      "    BNE     loc_FF89D9D4 \n" 
      "    LDR     R0, [R7, #0x1C] \n" 
      "    MOV     R1, #0x80 \n" 
      "    BL      sub_FF86753C \n" 
      "    LDR     R0, =0xFF89A1EC \n" 
      "    MOV     R1, #0x80 \n" 
      "    BL      sub_FF91A0BC \n" 
      "    LDR     R0, [R7, #0x1C] \n" 
      "    MOV     R2, R8 \n" 
      "    MOV     R1, #0x80 \n" 
      "    BL      sub_FF867448 \n" 
      "    TST     R0, #1 \n" 
      "    LDRNE   R1, =0xDC6 \n" 
      "    BNE     loc_FF89DA18 \n" 
"loc_FF89D9C0:\n"
      "    LDR     R1, [SP, #0x1C] \n" 
      "    LDR     R0, [R1, #0x8C] \n" 
      "    LDR     R1, [R1, #0x88] \n" 
      "    BLX     R1 \n" 
      "    B       loc_FF89DE7C \n" 
"loc_FF89D9D4:\n"
      "    CMP     R1, #0x27 \n" 
      "    BNE     loc_FF89DA24 \n" 
      "    ADD     R1, SP, #0xC \n" 
      "    BL      sub_FF89D87C \n" 
      "    LDR     R0, [R7, #0x1C] \n" 
      "    MOV     R1, #0x100 \n" 
      "    BL      sub_FF86753C \n" 
      "    MOV     R1, #0x100 \n" 
      "    LDR     R0, =0xFF89A1FC \n" 
      "    BL      sub_FF91A344 \n" 
      "    LDR     R0, [R7, #0x1C] \n" 
      "    MOV     R2, R8 \n" 
      "    MOV     R1, #0x100 \n" 
      "    BL      sub_FF867448 \n" 
      "    TST     R0, #1 \n" 
      "    BEQ     loc_FF89D9C0 \n" 
      "    MOV     R1, #0xDD0 \n" 
"loc_FF89DA18:\n"
      "    LDR     R0, =0xFF89A82C \n" 
      "    BL      _DebugAssert \n" 
      "    B       loc_FF89D9C0 \n" 
"loc_FF89DA24:\n"
      "    CMP     R1, #0x28 \n" 
      "    BNE     loc_FF89DA3C \n" 
"loc_FF89DA2C:\n"
      "    LDR     R0, [SP, #0x1C] \n" 
      "    ADD     R1, SP, #0xC \n" 
      "    BL      sub_FF89D87C \n" 
      "    B       loc_FF89D9C0 \n" 
"loc_FF89DA3C:\n"
      "    CMP     R1, #0x2B \n" 
      "    BNE     loc_FF89DA54 \n" 
      "    BL      sub_FF88CDA4 \n" 
      "    BL      sub_FF88DA30 \n" 
      "    BL      sub_FF88D568 \n" 
      "    B       loc_FF89D9C0 \n" 
"loc_FF89DA54:\n"
      "    LDR     R0, [SP, #0x1C] \n" 
      "    MOV     R4, #1 \n" 
      "    LDR     R1, [R0] \n" 
      "    CMP     R1, #0x11 \n" 
      "    CMPNE   R1, #0x12 \n" 
      "    BNE     loc_FF89DAC4 \n" 
      "    LDR     R1, [R0, #0x7C] \n" 
      "    ADD     R1, R1, R1, LSL #1 \n" 
      "    ADD     R1, R0, R1, LSL #2 \n" 
      "    SUB     R1, R1, #8 \n" 
      "    LDMIA   R1, {R2-R4} \n" 
      "    STMIA   R6, {R2-R4} \n" 
      "    BL      sub_FF89C2C4 \n" 
      "    LDR     R0, [SP, #0x1C] \n" 
      "    LDR     R1, [R0, #0x7C] \n" 
      "    LDR     R3, [R0, #0x88] \n" 
      "    LDR     R2, [R0, #0x8C] \n" 
      "    ADD     R0, R0, #4 \n" 
      "    BLX     R3 \n" 
      "    LDR     R0, [SP, #0x1C] \n" 
      "    BL      sub_FF89EF38 \n" 
      "    LDR     R0, [SP, #0x1C] \n" 
      "    LDR     R1, [R0, #0x7C] \n" 
      "    LDR     R3, [R0, #0x90] \n" 
      "    LDR     R2, [R0, #0x94] \n" 
      "    ADD     R0, R0, #4 \n" 
      "    BLX     R3 \n" 
      "    B       loc_FF89DDBC \n" 
"loc_FF89DAC4:\n"
      "    CMP     R1, #0x13 \n" 
      "    CMPNE   R1, #0x14 \n" 
      "    CMPNE   R1, #0x15 \n" 
      "    CMPNE   R1, #0x16 \n" 
      "    BNE     loc_FF89DB7C \n" 
      "    ADD     R3, SP, #0xC \n" 
      "    MOV     R2, SP \n" 
      "    ADD     R1, SP, #0x10 \n" 
      "    BL      sub_FF89C508 \n" 
      "    CMP     R0, #1 \n" 
      "    MOV     R4, R0 \n" 
      "    CMPNE   R4, #5 \n" 
      "    BNE     loc_FF89DB18 \n" 
      "    LDR     R0, [SP, #0x1C] \n" 
      "    MOV     R2, R4 \n" 
      "    LDR     R1, [R0, #0x7C]! \n" 
      "    LDR     R12, [R0, #0xC]! \n" 
      "    LDR     R3, [R0, #4] \n" 
      "    MOV     R0, SP \n" 
      "    BLX     R12 \n" 
      "    B       loc_FF89DB50 \n" 
"loc_FF89DB18:\n"
      "    LDR     R0, [SP, #0x1C] \n" 
      "    CMP     R4, #2 \n" 
      "    LDR     R3, [R0, #0x8C] \n" 
      "    CMPNE   R4, #6 \n" 
      "    BNE     loc_FF89DB64 \n" 
      "    LDR     R12, [R0, #0x88] \n" 
      "    MOV     R0, SP \n" 
      "    MOV     R2, R4 \n" 
      "    MOV     R1, #1 \n" 
      "    BLX     R12 \n" 
      "    LDR     R0, [SP, #0x1C] \n" 
      "    MOV     R2, SP \n" 
      "    ADD     R1, SP, #0x10 \n" 
      "    BL      sub_FF89D564 \n" 
"loc_FF89DB50:\n"
      "    LDR     R0, [SP, #0x1C] \n" 
      "    LDR     R2, [SP, #0xC] \n" 
      "    MOV     R1, R4 \n" 
      "    BL      sub_FF89D81C \n" 
      "    B       loc_FF89DDBC \n" 
"loc_FF89DB64:\n"
      "    LDR     R1, [R0, #0x7C] \n" 
      "    LDR     R12, [R0, #0x88] \n" 
      "    ADD     R0, R0, #4 \n" 
      "    MOV     R2, R4 \n" 
      "    BLX     R12 \n" 
      "    B       loc_FF89DDBC \n" 
"loc_FF89DB7C:\n"
      "    CMP     R1, #0x22 \n" 
      "    CMPNE   R1, #0x23 \n" 
      "    BNE     loc_FF89DBC8 \n" 
      "    LDR     R1, [R0, #0x7C] \n" 
      "    ADD     R1, R1, R1, LSL #1 \n" 
      "    ADD     R1, R0, R1, LSL #2 \n" 
      "    SUB     R1, R1, #8 \n" 
      "    LDMIA   R1, {R2-R4} \n" 
      "    STMIA   R6, {R2-R4} \n" 
      "    BL      sub_FF89B850 \n" 
      "    LDR     R0, [SP, #0x1C] \n" 
      "    LDR     R1, [R0, #0x7C] \n" 
      "    LDR     R3, [R0, #0x88] \n" 
      "    LDR     R2, [R0, #0x8C] \n" 
      "    ADD     R0, R0, #4 \n" 
      "    BLX     R3 \n" 
      "    LDR     R0, [SP, #0x1C] \n" 
      "    BL      sub_FF89BB40 \n" 
      "    B       loc_FF89DDBC \n" 
"loc_FF89DBC8:\n"
      "    ADD     R1, R0, #4 \n" 
      "    LDMIA   R1, {R2,R3,R12} \n" 
      "    STMIA   R6, {R2,R3,R12} \n" 
      "    LDR     R1, [R0] \n" 
      "    CMP     R1, #0x25 \n" 
      "    ADDLS   PC, PC, R1, LSL #2 \n" 
      "    B       loc_FF89DD9C \n" 
      "    B       loc_FF89DC7C \n" 
      "    B       loc_FF89DC7C \n" 
      "    B       loc_FF89DC84 \n" 
      "    B       loc_FF89DC8C \n" 
      "    B       loc_FF89DC8C \n" 
      "    B       loc_FF89DC8C \n" 
      "    B       loc_FF89DC7C \n" 
      "    B       loc_FF89DC84 \n" 
      "    B       loc_FF89DC8C \n" 
      "    B       loc_FF89DC8C \n" 
      "    B       loc_FF89DCA4 \n" 
      "    B       loc_FF89DCA4 \n" 
      "    B       loc_FF89DD90 \n" 
      "    B       loc_FF89DD98 \n" 
      "    B       loc_FF89DD98 \n" 
      "    B       loc_FF89DD98 \n" 
      "    B       loc_FF89DD98 \n" 
      "    B       loc_FF89DD9C \n" 
      "    B       loc_FF89DD9C \n" 
      "    B       loc_FF89DD9C \n" 
      "    B       loc_FF89DD9C \n" 
      "    B       loc_FF89DD9C \n" 
      "    B       loc_FF89DD9C \n" 
      "    B       loc_FF89DC94 \n" 
      "    B       loc_FF89DC9C \n" 
      "    B       loc_FF89DC9C \n" 
      "    B       loc_FF89DCB0 \n" 
      "    B       loc_FF89DCB0 \n" 
      "    B       loc_FF89DCB8 \n" 
      "    B       loc_FF89DCE8 \n" 
      "    B       loc_FF89DD18 \n" 
      "    B       loc_FF89DD48 \n" 
      "    B       loc_FF89DD78 \n" 
      "    B       loc_FF89DD78 \n" 
      "    B       loc_FF89DD9C \n" 
      "    B       loc_FF89DD9C \n" 
      "    B       loc_FF89DD80 \n" 
      "    B       loc_FF89DD88 \n" 
"loc_FF89DC7C:\n"
      "    BL      sub_FF89A6D8 \n" 
      "    B       loc_FF89DD9C \n" 
"loc_FF89DC84:\n"
      "    BL      sub_FF89A94C \n" 
      "    B       loc_FF89DD9C \n" 
"loc_FF89DC8C:\n"
      "    BL      sub_FF89AB50 \n" 
      "    B       loc_FF89DD9C \n" 
"loc_FF89DC94:\n"
      "    BL      sub_FF89ADB8 \n" 
      "    B       loc_FF89DD9C \n" 
"loc_FF89DC9C:\n"
      "    BL      sub_FF89AFAC \n" 
      "    B       loc_FF89DD9C \n" 
"loc_FF89DCA4:\n"
      "    BL      sub_FF89B23C_my \n" // ->
      "    MOV     R4, #0 \n" 
      "    B       loc_FF89DD9C \n" 
"loc_FF89DCB0:\n"
      "    BL      sub_FF89B378 \n" 
      "    B       loc_FF89DD9C \n" 
"loc_FF89DCB8:\n"
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
      "    BL      sub_FF89EBF4 \n" 
      "    B       loc_FF89DD9C \n" 
"loc_FF89DCE8:\n"
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
      "    BL      sub_FF89ED54 \n" 
      "    B       loc_FF89DD9C \n" 
"loc_FF89DD18:\n"
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
      "    BL      sub_FF89EE00 \n" 
      "    B       loc_FF89DD9C \n" 
"loc_FF89DD48:\n"
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
      "    BL      sub_FF89EEA0 \n" 
      "    B       loc_FF89DD9C \n" 
"loc_FF89DD78:\n"
      "    BL      sub_FF89B618 \n" 
      "    B       loc_FF89DD9C \n" 
"loc_FF89DD80:\n"
      "    BL      sub_FF89BC44 \n" 
      "    B       loc_FF89DD9C \n" 
"loc_FF89DD88:\n"
      "    BL      sub_FF89BE7C \n" 
      "    B       loc_FF89DD9C \n" 
"loc_FF89DD90:\n"
      "    BL      sub_FF89BFF4 \n" 
      "    B       loc_FF89DD9C \n" 
"loc_FF89DD98:\n"
      "    BL      sub_FF89C18C \n" 
"loc_FF89DD9C:\n"
      "    LDR     R0, [SP, #0x1C] \n" 
      "    LDR     R1, [R0, #0x7C] \n" 
      "    LDR     R3, [R0, #0x88] \n" 
      "    LDR     R2, [R0, #0x8C] \n" 
      "    ADD     R0, R0, #4 \n" 
      "    BLX     R3 \n" 
      "    CMP     R4, #1 \n" 
      "    BNE     loc_FF89DE04 \n" 
"loc_FF89DDBC:\n"
      "    LDR     R0, [SP, #0x1C] \n" 
      "    MOV     R2, #0xC \n" 
      "    LDR     R1, [R0, #0x7C] \n" 
      "    ADD     R1, R1, R1, LSL #1 \n" 
      "    ADD     R0, R0, R1, LSL #2 \n" 
      "    SUB     R4, R0, #8 \n" 
      "    LDR     R0, =0x19D3C \n" 
      "    ADD     R1, SP, #0x10 \n" 
      "    BL      sub_FFAE9294 \n" 
      "    LDR     R0, =0x19D48 \n" 
      "    MOV     R2, #0xC \n" 
      "    ADD     R1, SP, #0x10 \n" 
      "    BL      sub_FFAE9294 \n" 
      "    LDR     R0, =0x19D54 \n" 
      "    MOV     R2, #0xC \n" 
      "    MOV     R1, R4 \n" 
      "    BL      sub_FFAE9294 \n" 
      "    B       loc_FF89DE7C \n" 
"loc_FF89DE04:\n"
      "    LDR     R0, [SP, #0x1C] \n" 
      "    LDR     R0, [R0] \n" 
      "    CMP     R0, #0xB \n" 
      "    BNE     loc_FF89DE4C \n" 
      "    MOV     R3, #0 \n" 
      "    STR     R3, [SP] \n" 
      "    MOV     R3, #1 \n" 
      "    MOV     R2, #1 \n" 
      "    MOV     R1, #1 \n" 
      "    MOV     R0, #0 \n" 
      "    BL      sub_FF89A4E0 \n" 
      "    MOV     R3, #0 \n" 
      "    STR     R3, [SP] \n" 
      "    MOV     R3, #1 \n" 
      "    MOV     R2, #1 \n" 
      "    MOV     R1, #1 \n" 
      "    MOV     R0, #0 \n" 
      "    B       loc_FF89DE78 \n" 
"loc_FF89DE4C:\n"
      "    MOV     R3, #1 \n" 
      "    MOV     R2, #1 \n" 
      "    MOV     R1, #1 \n" 
      "    MOV     R0, #1 \n" 
      "    STR     R3, [SP] \n" 
      "    BL      sub_FF89A4E0 \n" 
      "    MOV     R3, #1 \n" 
      "    MOV     R2, #1 \n" 
      "    MOV     R1, #1 \n" 
      "    MOV     R0, #1 \n" 
      "    STR     R3, [SP] \n" 
"loc_FF89DE78:\n"
      "    BL      sub_FF89A620 \n" 
"loc_FF89DE7C:\n"
      "    LDR     R0, [SP, #0x1C] \n" 
      "    BL      sub_FF89EB80 \n" 
      "    B       loc_FF89D8EC \n" 
    );
}

void __attribute__((naked,noinline)) sub_FF89B23C_my(  ) {
asm volatile (
      "    STMFD   SP!, {R4-R8,LR} \n" 
      "    LDR     R7, =0x3F08 \n" 
      "    MOV     R4, R0 \n" 
      "    LDR     R0, [R7, #0x1C] \n" 
      "    MOV     R1, #0x3E \n" 
      "    BL      sub_FF86753C \n" 
      "    LDRSH   R0, [R4, #4] \n" 
      "    MOV     R2, #0 \n" 
      "    MOV     R1, #0 \n" 
      "    BL      sub_FF89A270 \n" 
      "    MOV     R6, R0 \n" 
      "    LDRSH   R0, [R4, #6] \n" 
      "    BL      sub_FF89A380 \n" 
      "    LDRSH   R0, [R4, #8] \n" 
      "    BL      sub_FF89A3D8 \n" 
      "    LDRSH   R0, [R4, #0xA] \n" 
      "    BL      sub_FF89A430 \n" 
      "    LDRSH   R0, [R4, #0xC] \n" 
      "    BL      sub_FF89A488 \n" 
      "    MOV     R5, R0 \n" 
      "    LDR     R0, [R4] \n" 
      "    LDR     R8, =0x19D54 \n" 
      "    CMP     R0, #0xB \n" 
      "    MOVEQ   R6, #0 \n" 
      "    MOVEQ   R5, #0 \n" 
      "    BEQ     loc_FF89B2CC \n" 
      "    CMP     R6, #1 \n" 
      "    BNE     loc_FF89B2CC \n" 
      "    LDRSH   R0, [R4, #4] \n" 
      "    LDR     R1, =0xFF89A1DC \n" 
      "    MOV     R2, #2 \n" 
      "    BL      sub_FF91A210 \n" 
      "    STRH    R0, [R4, #4] \n" 
      "    MOV     R0, #0 \n" 
      "    STR     R0, [R7, #0x28] \n" 
      "    B       loc_FF89B2D4 \n" 
"loc_FF89B2CC:\n"
      "    LDRH    R0, [R8] \n" 
      "    STRH    R0, [R4, #4] \n" 
"loc_FF89B2D4:\n"
      "    CMP     R5, #1 \n" 
      "    LDRNEH  R0, [R8, #8] \n" 
      "    BNE     loc_FF89B2F0 \n" 
      "    LDRSH   R0, [R4, #0xC] \n" 
      "    LDR     R1, =0xFF89A260 \n" 
      "    MOV     R2, #0x20 \n" 
      "    BL      sub_FF89EBB0 \n" 
"loc_FF89B2F0:\n"
      "    STRH    R0, [R4, #0xC] \n" 
      "    LDRSH   R0, [R4, #6] \n" 
      "    BL      sub_FF88CB14_my \n" // ->
      "    LDR PC, =0xff89b2fc\n"   // jump back to ROM
/*      "    LDRSH   R0, [R4, #8] \n" 
      "    MOV     R1, #1 \n" 
      "    BL      sub_FF88D260 \n" 
      "    MOV     R1, #0 \n" 
      "    ADD     R0, R4, #8 \n" 
      "    BL      sub_FF88D2E8 \n" 
      "    LDRSH   R0, [R4, #0xE] \n" 
      "    BL      sub_FF895CE0 \n" 
      "    LDR     R4, =0xBB8 \n" 
      "    CMP     R6, #1 \n" 
      "    BNE     loc_FF89B348 \n" 
      "    LDR     R0, [R7, #0x1C] \n" 
      "    MOV     R2, R4 \n" 
      "    MOV     R1, #2 \n" 
      "    BL      sub_FF867448 \n" 
      "    TST     R0, #1 \n" 
      "    LDRNE   R1, =0x583 \n" 
      "    LDRNE   R0, =0xFF89A82C \n" 
      "    BLNE    _DebugAssert \n" 
"loc_FF89B348:\n"
      "    CMP     R5, #1 \n" 
      "    LDMNEFD SP!, {R4-R8,PC} \n" 
      "    LDR     R0, [R7, #0x1C] \n" 
      "    MOV     R2, R4 \n" 
      "    MOV     R1, #0x20 \n" 
      "    BL      sub_FF867448 \n" 
      "    TST     R0, #1 \n" 
      "    LDRNE   R1, =0x588 \n" 
      "    LDRNE   R0, =0xFF89A82C \n" 
      "    LDMNEFD SP!, {R4-R8,LR} \n" 
      "    BNE     _DebugAssert \n" 
      "    LDMFD   SP!, {R4-R8,PC} \n" */
    );
}


void __attribute__((naked,noinline)) sub_FF88CB14_my(  ) {
asm volatile (
      "    STMFD   SP!, {R4-R6,LR} \n" 
      "    LDR     R5, =0x3C04 \n" 
      "    MOV     R4, R0 \n" 
      "    LDR     R0, [R5, #4] \n" 
      "    CMP     R0, #1 \n" 
      "    MOVNE   R1, #0x140 \n" 
      "    LDRNE   R0, =0xFF88C918 \n" 
      "    BLNE    _DebugAssert \n" 
      "    CMN     R4, #0xC00 \n" 
      "    LDREQSH R4, [R5, #2] \n" 
      "    CMN     R4, #0xC00 \n" 
      "    LDREQ   R1, =0x146 \n" 
      "    LDREQ   R0, =0xFF88C918 \n" 
      "    STRH    R4, [R5, #2] \n" 
      "    BLEQ    _DebugAssert \n" 
      "    MOV     R0, R4 \n" 
"                BL      apex2us\n" // +
      "    LDR PC, =0xff88cb64\n"   // jump back to ROM
/*
//      "    BL      sub_FF9BA9D0 \n" // -
//      "    MOV     R4, R0 \n" // useless
//      "    BL      sub_FF8B31B4 \n" // nullsub
//      "    MOV     R0, R4 \n" // useless
      "    BL      sub_FF8B6BC4 \n" 
      "    TST     R0, #1 \n" 
      "    LDRNE   R1, =0x14B \n" 
      "    LDMNEFD SP!, {R4-R6,LR} \n" 
      "    LDRNE   R0, =0xFF88C918 \n" 
      "    BNE     _DebugAssert \n" 
      "    LDMFD   SP!, {R4-R6,PC} \n" */
    );
}

