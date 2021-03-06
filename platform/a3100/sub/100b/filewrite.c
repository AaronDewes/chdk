/*
 * filewrite.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_FWT 4 // filewritetask is prepared for this many chunks
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for DryOS>=r50 generation cameras
 * cameras with possible multipass JPEG writes need oflags
 * pdc is always required
 * name is not currently used
 */
typedef struct
{
    int unkn1[2];
    int oflags;
    int unkn2[2];
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_FWT];
    int unkn6;
    char name[32];
} fwt_data_struct;

#include "../../../generic/filewrite.c"

/*************************************************************/
//** filewritetask @ 0xFFA27CD4 - 0xFFA27DB8, length=58
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R5,LR} \n"
"    LDR     R4, =0x90E0 \n"

"loc_FFA27CDC:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #8 \n"
"    BL      sub_FF838F6C /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FFA27D0C \n"
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #1 \n"
"    BNE     loc_FFA27D14 \n"
"    LDR     R0, [R4, #8] \n"
"    BL      _GiveSemaphore \n"

"loc_FFA27D0C:\n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R1-R5,PC} \n"

"loc_FFA27D14:\n"
"    SUB     R1, R1, #2 \n"
"    CMP     R1, #6 \n"
"    ADDLS   PC, PC, R1, LSL#2 \n"
"    B       loc_FFA27CDC \n"
"    B       loc_FFA27D40 \n"
"    B       loc_FFA27DA4 \n"
"    B       loc_FFA27DAC \n"
"    B       loc_FFA27DAC \n"
"    B       loc_FFA27DAC \n"
"    B       loc_FFA27DAC \n"
"    B       loc_FFA27DB4 \n"

"loc_FFA27D40:\n"
"    MOV     R0, #0 \n"
"    STR     R0, [SP] \n"

"loc_FFA27D48:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R1, SP \n"
"    BL      sub_FF8391B0 /*_GetNumberOfPostedMessages*/ \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFA27D74 \n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF838F6C /*_ReceiveMessageQueue*/ \n"
"    B       loc_FFA27D48 \n"

"loc_FFA27D74:\n"
"    LDR     R0, [R4] \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FFA27D98 \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    MVN     R0, #0 \n"
"    STR     R0, [R4] \n"
"    LDR     R0, =0xDC30C \n"
"    BL      sub_FF86331C \n"
"    BL      sub_FF8615B8 \n"

"loc_FFA27D98:\n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FFA27CDC \n"

"loc_FFA27DA4:\n"
"    BL      sub_FFA27FC4_my \n"  // --> Patched. Old value = 0xFFA27FC4. Open stage
"    B       loc_FFA27CDC \n"

"loc_FFA27DAC:\n"
"    BL      sub_FFA280F8_my \n"  // --> Patched. Old value = 0xFFA280F8. Write stage
"    B       loc_FFA27CDC \n"

"loc_FFA27DB4:\n"
"    BL      sub_FFA27B60_my \n"  // --> Patched. Old value = 0xFFA27B60. Close stage
"    B       loc_FFA27CDC \n"
);
}

/*************************************************************/
//** sub_FFA27FC4_my @ 0xFFA27FC4 - 0xFFA28004, length=17
void __attribute__((naked,noinline)) sub_FFA27FC4_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    MOV     R4, R0 \n"
"    ADD     R0, R0, #0x38 \n"
"    SUB     SP, SP, #0x38 \n"
"    BL      sub_FF86331C \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF861568 \n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      sub_FF81033C \n"
"    LDR     R7, [R4, #8] \n"
"    LDR     R8, =0x1B6 \n"
"    ADD     R6, R4, #0x38 \n"
"    LDR     R5, [R4, #0xC] \n"
//hook start
// "    STMFD SP!, {R4-R12,LR}\n"
"    MOV R0, R4\n"
"    BL filewrite_main_hook\n"
// "    LDMFD SP!, {R4-R12,LR}\n"
//hook end
"    MOV     R0, R6 \n"
"    MOV     R1, R7 \n"
"    MOV     R2, R8 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    LDR     PC, =0xFFA28008 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FFA280F8_my @ 0xFFA280F8 - 0xFFA28200, length=67
void __attribute__((naked,noinline)) sub_FFA280F8_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #4 \n"
"    LDREQ   R6, [R4, #0x18] \n"
"    LDREQ   R7, [R4, #0x14] \n"
"    BEQ     loc_FFA28144 \n"
"    CMP     R0, #5 \n"
"    LDREQ   R6, [R4, #0x20] \n"
"    LDREQ   R7, [R4, #0x1C] \n"
"    BEQ     loc_FFA28144 \n"
"    CMP     R0, #6 \n"
"    LDREQ   R6, [R4, #0x28] \n"
"    LDREQ   R7, [R4, #0x24] \n"
"    BEQ     loc_FFA28144 \n"
"    CMP     R0, #7 \n"
"    BNE     loc_FFA28158 \n"
"    LDR     R6, [R4, #0x30] \n"
"    LDR     R7, [R4, #0x2C] \n"

"loc_FFA28144:\n"
"    CMP     R6, #0 \n"
"    BNE     loc_FFA28168 \n"

"loc_FFA2814C:\n"
"    MOV     R1, R4 \n"
"    MOV     R0, #8 \n"
"    B       loc_FFA281FC \n"

"loc_FFA28158:\n"
"    LDR     R1, =0x29F \n"
"    LDR     R0, =0xFFA27DCC /*'dwFWrite.c'*/ \n"
"    BL      _DebugAssert \n"
"    B       loc_FFA2814C \n"

"loc_FFA28168:\n"
"    LDR     R9, =0x90E0 \n"
"    MOV     R5, R6 \n"

"loc_FFA28170:\n"
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
"    BEQ     loc_FFA281D0 \n"
"    CMN     R0, #1 \n"
"    LDRNE   R0, =0x9200015 \n"
"    LDREQ   R0, =0x9200005 \n"
"    STR     R0, [R4, #0x10] \n"
"    B       loc_FFA2814C \n"

"loc_FFA281D0:\n"
"    SUB     R5, R5, R0 \n"
"    CMP     R5, R6 \n"
"    ADD     R7, R7, R0 \n"
"    LDRCS   R0, =0xFFA27DCC /*'dwFWrite.c'*/ \n"
"    LDRCS   R1, =0x2CA \n"
"    BLCS    _DebugAssert \n"
"    CMP     R5, #0 \n"
"    BNE     loc_FFA28170 \n"
"    LDR     R0, [R4] \n"
"    MOV     R1, R4 \n"
"    ADD     R0, R0, #1 \n"

"loc_FFA281FC:\n"
"    LDMFD   SP!, {R4-R10,LR} \n"
"    B       sub_FFA27AA0 \n"
);
}

/*************************************************************/
//** sub_FFA27B60_my @ 0xFFA27B60 - 0xFFA27B94, length=14
void __attribute__((naked,noinline)) sub_FFA27B60_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x90E0 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5] \n"
"    SUB     SP, SP, #0x38 \n"
"    CMN     R0, #1 \n"
"    BEQ     sub_FFA27BA8 \n"
"    LDR     R1, [R4, #8] \n"
"    LDR     R6, =0x9200003 \n"
"    TST     R1, #0x8000 \n"
"    BEQ     loc_FFA27B94 \n"
//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_D\n" // jump over the next block
//mod end

"    BL      sub_FF860614 \n"
"    B       sub_FFA27B98 \n"

"loc_FFA27B94:\n"
"loc_D:\n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    LDR     PC, =0xFFA27B98 \n"  // Continue in firmware
);
}
