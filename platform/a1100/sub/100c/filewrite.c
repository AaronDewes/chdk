/*
 * filewrite.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_FWT 3 // filewritetask is prepared for this many chunks
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for DryOS>=r50 generation cameras
 * pdc is always required
 * name is not currently used
 */
typedef struct
{
    int unkn1[5];
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_FWT];
    char name[32];
} fwt_data_struct;

#include "../../../generic/filewrite.c"

/*************************************************************/
//** filewritetask @ 0xFFDDB384 - 0xFFDDB464, length=57
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R5,LR} \n"
"    LDR     R4, =0x86EC \n"

"loc_FFDDB38C:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #8 \n"
"    BL      sub_FFC16370 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FFDDB3BC \n"
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #1 \n"
"    BNE     loc_FFDDB3C4 \n"
"    LDR     R0, [R4, #8] \n"
"    BL      _GiveSemaphore \n"

"loc_FFDDB3BC:\n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R1-R5,PC} \n"

"loc_FFDDB3C4:\n"
"    SUB     R1, R1, #2 \n"
"    CMP     R1, #5 \n"
"    ADDLS   PC, PC, R1, LSL#2 \n"
"    B       loc_FFDDB38C \n"
"    B       loc_FFDDB3EC \n"
"    B       loc_FFDDB450 \n"
"    B       loc_FFDDB458 \n"
"    B       loc_FFDDB458 \n"
"    B       loc_FFDDB458 \n"
"    B       loc_FFDDB460 \n"

"loc_FFDDB3EC:\n"
"    MOV     R0, #0 \n"
"    STR     R0, [SP] \n"

"loc_FFDDB3F4:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R1, SP \n"
"    BL      sub_FFC165B4 /*_GetNumberOfPostedMessages*/ \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFDDB420 \n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FFC16370 /*_ReceiveMessageQueue*/ \n"
"    B       loc_FFDDB3F4 \n"

"loc_FFDDB420:\n"
"    LDR     R0, [R4] \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FFDDB444 \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    MVN     R0, #0 \n"
"    STR     R0, [R4] \n"
"    LDR     R0, =0xB7C48 \n"
"    BL      sub_FFC3EE60 \n"
"    BL      sub_FFC3D3EC \n"

"loc_FFDDB444:\n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FFDDB38C \n"

"loc_FFDDB450:\n"
"    BL      sub_FFDDB638_my \n"  // --> Patched. Old value = 0xFFDDB638. Open stage
"    B       loc_FFDDB38C \n"

"loc_FFDDB458:\n"
"    BL      sub_FFDDB784_my \n"  // --> Patched. Old value = 0xFFDDB784. Write stage
"    B       loc_FFDDB38C \n"

"loc_FFDDB460:\n"
"    BL      sub_FFDDB880_my \n"  // --> Patched. Old value = 0xFFDDB880. Close stage
"    B       loc_FFDDB38C \n"
);
}

/*************************************************************/
//** sub_FFDDB638_my @ 0xFFDDB638 - 0xFFDDB678, length=17
void __attribute__((naked,noinline)) sub_FFDDB638_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    MOV     R4, R0 \n"
"    ADD     R0, R0, #0x2C \n"
"    SUB     SP, SP, #0x38 \n"
"    BL      sub_FFC3EE60 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FFC3D39C \n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      sub_FFC3B844 \n"
"    LDR     R7, [R4, #8] \n"
"    LDR     R8, =0x1B6 \n"
"    ADD     R6, R4, #0x2C \n"
"    LDR     R5, [R4, #0xC] \n"
//hook start
"    STMFD SP!, {R4-R12,LR}\n"
"    MOV R0, R4\n"
"    BL filewrite_main_hook\n"
"    LDMFD SP!, {R4-R12,LR}\n"
//hook end
"    MOV     R0, R6 \n"
"    MOV     R1, R7 \n"
"    MOV     R2, R8 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    LDR     PC, =0xFFDDB67C \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FFDDB784_my @ 0xFFDDB784 - 0xFFDDB87C, length=63
void __attribute__((naked,noinline)) sub_FFDDB784_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #4 \n"
"    LDREQ   R6, [R4, #0x18] \n"
"    LDREQ   R7, [R4, #0x14] \n"
"    BEQ     loc_FFDDB7C0 \n"
"    CMP     R0, #5 \n"
"    LDREQ   R6, [R4, #0x20] \n"
"    LDREQ   R7, [R4, #0x1C] \n"
"    BEQ     loc_FFDDB7C0 \n"
"    CMP     R0, #6 \n"
"    BNE     loc_FFDDB7D4 \n"
"    LDR     R6, [R4, #0x28] \n"
"    LDR     R7, [R4, #0x24] \n"

"loc_FFDDB7C0:\n"
"    CMP     R6, #0 \n"
"    BNE     loc_FFDDB7E4 \n"

"loc_FFDDB7C8:\n"
"    MOV     R1, R4 \n"
"    MOV     R0, #7 \n"
"    B       loc_FFDDB878 \n"

"loc_FFDDB7D4:\n"
"    LDR     R1, =0x20D \n"
"    LDR     R0, =0xFFDDB764 /*'dwFWrite.c'*/ \n"
"    BL      _DebugAssert \n"
"    B       loc_FFDDB7C8 \n"

"loc_FFDDB7E4:\n"
"    LDR     R9, =0x86EC \n"
"    MOV     R5, R6 \n"

"loc_FFDDB7EC:\n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R5, #0x1000000 \n"
"    MOVLS   R8, R5 \n"
"    MOVHI   R8, #0x1000000 \n"
"    BIC     R1, R0, #0xFF000000 \n"
"    CMP     R1, #0 \n"
"    BICNE   R0, R0, #0xFF000000 \n"
"    RSBNE   R0, R0, #0x1000000 \n"
"    CMPNE   R8, R0 \n"
"    MOVHI   R8, R0 \n"
"    LDR     R0, [R9] \n"
"    MOV     R2, R8 \n"
"    MOV     R1, R7 \n"
"    BL      fwt_write \n"  // --> Patched. Old value = _Write.
"    LDR     R1, [R4, #4] \n"
"    CMP     R8, R0 \n"
"    ADD     R1, R1, R0 \n"
"    STR     R1, [R4, #4] \n"
"    BEQ     loc_FFDDB84C \n"
"    LDR     R0, =0x10B1 \n"
"    BL      sub_FFC5C9F4 /*_IsControlEventActive_FW*/ \n"
"    LDR     R1, =0x9200005 \n"
"    STR     R1, [R4, #0x10] \n"
"    B       loc_FFDDB7C8 \n"

"loc_FFDDB84C:\n"
"    SUB     R5, R5, R0 \n"
"    CMP     R5, R6 \n"
"    ADD     R7, R7, R0 \n"
"    LDRCS   R0, =0xFFDDB764 /*'dwFWrite.c'*/ \n"
"    MOVCS   R1, #0x23C \n"
"    BLCS    _DebugAssert \n"
"    CMP     R5, #0 \n"
"    BNE     loc_FFDDB7EC \n"
"    LDR     R0, [R4] \n"
"    MOV     R1, R4 \n"
"    ADD     R0, R0, #1 \n"

"loc_FFDDB878:\n"
"    LDMFD   SP!, {R4-R10,LR} \n"
"    B       sub_FFDDB2DC \n"
);
}

/*************************************************************/
//** sub_FFDDB880_my @ 0xFFDDB880 - 0xFFDDB89C, length=8
void __attribute__((naked,noinline)) sub_FFDDB880_my() {
asm volatile (
"    STMFD   SP!, {R4,R5,LR} \n"
"    LDR     R5, =0x86EC \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5] \n"
"    SUB     SP, SP, #0x1C \n"
"    CMN     R0, #1 \n"
"    BEQ     sub_FFDDB8B4 \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    LDR     PC, =0xFFDDB8A0 \n"  // Continue in firmware
);
}
