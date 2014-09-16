/*
 * filewrite.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_JPEG 3 //filewritetask is prepared for this many chunks
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for DryOS>=r50 generation cameras
 * pdc is always required
 * name is not currently used
 */
typedef struct
{
    int unkn1[5];                                //
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_JPEG];
    char name[32];
} fwt_data_struct;

#include "../../../generic/filewrite.c"

/*************************************************************/
//** filewritetask @ 0xFFDCB5AC - 0xFFDCB68C, length=57
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R5,LR} \n"
"    LDR     R4, =0xAAE4 \n"

"loc_FFDCB5B4:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #8 \n"
"    BL      sub_FFC1764C /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FFDCB5E4 \n"
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #1 \n"
"    BNE     loc_FFDCB5EC \n"
"    LDR     R0, [R4, #8] \n"
"    BL      _GiveSemaphore \n"

"loc_FFDCB5E4:\n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R1-R5,PC} \n"

"loc_FFDCB5EC:\n"
"    SUB     R1, R1, #2 \n"
"    CMP     R1, #5 \n"
"    ADDLS   PC, PC, R1, LSL#2 \n"
"    B       loc_FFDCB5B4 \n"
"    B       loc_FFDCB614 \n"
"    B       loc_FFDCB678 \n"
"    B       loc_FFDCB680 \n"
"    B       loc_FFDCB680 \n"
"    B       loc_FFDCB680 \n"
"    B       loc_FFDCB688 \n"

"loc_FFDCB614:\n"
"    MOV     R0, #0 \n"
"    STR     R0, [SP] \n"

"loc_FFDCB61C:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R1, SP \n"
"    BL      sub_FFC17850 /*_GetNumberOfPostedMessages*/ \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFDCB648 \n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FFC1764C /*_ReceiveMessageQueue*/ \n"
"    B       loc_FFDCB61C \n"

"loc_FFDCB648:\n"
"    LDR     R0, [R4] \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FFDCB66C \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    MVN     R0, #0 \n"
"    STR     R0, [R4] \n"
"    LDR     R0, =0x7ADB0 \n"
"    BL      sub_FFC3DA18 \n"
"    BL      sub_FFC3F2CC \n"

"loc_FFDCB66C:\n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FFDCB5B4 \n"

"loc_FFDCB678:\n"
"    BL      sub_FFDCB84C_my \n"  // --> Patched. Old value = 0xFFDCB84C. Open stage
"    B       loc_FFDCB5B4 \n"

"loc_FFDCB680:\n"
"    BL      sub_FFDCB98C_my \n"  // --> Patched. Old value = 0xFFDCB98C. Write stage
"    B       loc_FFDCB5B4 \n"

"loc_FFDCB688:\n"
"    BL      sub_FFDCBA88_my \n"  // --> Patched. Old value = 0xFFDCBA88. Close stage
"    B       loc_FFDCB5B4 \n"
);
}

/*************************************************************/
//** sub_FFDCB84C_my @ 0xFFDCB84C - 0xFFDCB88C, length=17
void __attribute__((naked,noinline)) sub_FFDCB84C_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    MOV     R4, R0 \n"
"    ADD     R0, R0, #0x2C \n"
"    SUB     SP, SP, #0x38 \n"
"    BL      sub_FFC3DA18 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FFC3F27C \n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      sub_FFC3FB6C \n"
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
"    LDR     PC, =0xFFDCB890 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FFDCB98C_my @ 0xFFDCB98C - 0xFFDCBA84, length=63
void __attribute__((naked,noinline)) sub_FFDCB98C_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #4 \n"
"    LDREQ   R6, [R4, #0x18] \n"
"    LDREQ   R7, [R4, #0x14] \n"
"    BEQ     loc_FFDCB9C8 \n"
"    CMP     R0, #5 \n"
"    LDREQ   R6, [R4, #0x20] \n"
"    LDREQ   R7, [R4, #0x1C] \n"
"    BEQ     loc_FFDCB9C8 \n"
"    CMP     R0, #6 \n"
"    BNE     loc_FFDCB9DC \n"
"    LDR     R6, [R4, #0x28] \n"
"    LDR     R7, [R4, #0x24] \n"

"loc_FFDCB9C8:\n"
"    CMP     R6, #0 \n"
"    BNE     loc_FFDCB9EC \n"

"loc_FFDCB9D0:\n"
"    MOV     R1, R4 \n"
"    MOV     R0, #7 \n"
"    B       loc_FFDCBA80 \n"

"loc_FFDCB9DC:\n"
"    LDR     R1, =0x1E2 \n"
"    LDR     R0, =0xFFDCB96C \n"
"    BL      _DebugAssert \n"
"    B       loc_FFDCB9D0 \n"

"loc_FFDCB9EC:\n"
"    LDR     R9, =0xAAE4 \n"
"    MOV     R5, R6 \n"

"loc_FFDCB9F4:\n"
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
"    BEQ     loc_FFDCBA54 \n"
"    LDR     R0, =0x10B1 \n"
"    BL      sub_FFC5C534 /*_IsControlEventActive_FW*/ \n"
"    LDR     R1, =0x9200005 \n"
"    STR     R1, [R4, #0x10] \n"
"    B       loc_FFDCB9D0 \n"

"loc_FFDCBA54:\n"
"    SUB     R5, R5, R0 \n"
"    CMP     R5, R6 \n"
"    ADD     R7, R7, R0 \n"
"    LDRCS   R1, =0x211 \n"
"    LDRCS   R0, =0xFFDCB96C \n"
"    BLCS    _DebugAssert \n"
"    CMP     R5, #0 \n"
"    BNE     loc_FFDCB9F4 \n"
"    LDR     R0, [R4] \n"
"    MOV     R1, R4 \n"
"    ADD     R0, R0, #1 \n"

"loc_FFDCBA80:\n"
"    LDMFD   SP!, {R4-R10,LR} \n"
"    B       sub_FFDCB504 \n"
);
}

/*************************************************************/
//** sub_FFDCBA88_my @ 0xFFDCBA88 - 0xFFDCBAA4, length=8
void __attribute__((naked,noinline)) sub_FFDCBA88_my() {
asm volatile (
"    STMFD   SP!, {R4,R5,LR} \n"
"    LDR     R5, =0xAAE4 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5] \n"
"    SUB     SP, SP, #0x1C \n"
"    CMN     R0, #1 \n"
"    BEQ     sub_FFDCBABC \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    LDR     PC, =0xFFDCBAA8 \n"  // Continue in firmware
);
}
