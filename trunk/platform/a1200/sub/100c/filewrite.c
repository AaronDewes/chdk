/*
 * filewrite.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_FWT 7 // filewritetask is prepared for this many chunks
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
    int unkn6;
    char name[32];
} fwt_data_struct;

#include "../../../generic/filewrite.c"

/*************************************************************/
//** filewritetask @ 0xFFA892F0 - 0xFFA893D0, length=57
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R5,LR} \n"
"    LDR     R5, =0xA9C8 \n"

"loc_FFA892F8:\n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R5, #0x10] \n"
"    ADD     R1, SP, #8 \n"
"    BL      sub_FF8397A4 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    LDRNE   R1, =0x33F \n"
"    LDRNE   R0, =0xFFA893E4 /*'dwFWrite.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0xA \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FFA892F8 \n"
"    B       loc_FFA893C4 \n"
"    B       loc_FFA893C4 \n"
"    B       loc_FFA893C4 \n"
"    B       loc_FFA893C4 \n"
"    B       loc_FFA893C4 \n"
"    B       loc_FFA893C4 \n"
"    B       loc_FFA893C4 \n"
"    B       loc_FFA893CC \n"
"    B       loc_FFA89354 \n"
"    B       loc_FFA893BC \n"

"loc_FFA89354:\n"
"    MOV     R0, #0 \n"
"    MOV     R4, R5 \n"
"    STR     R0, [SP] \n"

"loc_FFA89360:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R1, SP \n"
"    BL      sub_FF8399E8 /*_GetNumberOfPostedMessages*/ \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFA8938C \n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF8397A4 /*_ReceiveMessageQueue*/ \n"
"    B       loc_FFA89360 \n"

"loc_FFA8938C:\n"
"    LDR     R0, [R4, #4] \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FFA893B0 \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    MVN     R0, #0 \n"
"    STR     R0, [R4, #4] \n"
"    LDR     R0, =0xF83A8 \n"
"    BL      sub_FF86F498 \n"
"    BL      sub_FF86D6C4 \n"

"loc_FFA893B0:\n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FFA892F8 \n"

"loc_FFA893BC:\n"
"    BL      sub_FFA895CC_my \n"  // --> Patched. Old value = 0xFFA895CC. Open stage
"    B       loc_FFA892F8 \n"

"loc_FFA893C4:\n"
"    BL      sub_FFA89714_my \n"  // --> Patched. Old value = 0xFFA89714. Write stage
"    B       loc_FFA892F8 \n"

"loc_FFA893CC:\n"
"    BL      sub_FFA8917C_my \n"  // --> Patched. Old value = 0xFFA8917C. Close stage
"    B       loc_FFA892F8 \n"
);
}

/*************************************************************/
//** sub_FFA895CC_my @ 0xFFA895CC - 0xFFA89620, length=22
void __attribute__((naked,noinline)) sub_FFA895CC_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    MOV     R4, R0 \n"
"    SUB     SP, SP, #0x38 \n"
"    ADD     R0, R0, #0x50 \n"
"    BL      sub_FF86F498 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF86D65C \n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      sub_FF81033C \n"
"    LDR     R0, [R4, #0x4C] \n"
"    LDR     R8, =0x1B6 \n"
"    CMP     R0, #1 \n"
"    LDREQ   R0, [R4, #8] \n"
"    ADD     R6, R4, #0x50 \n"
"    ORREQ   R0, R0, #0x8000 \n"
"    STREQ   R0, [R4, #8] \n"
//hook start
"    STMFD SP!, {R4-R12,LR}\n"
"    MOV R0, R4\n"
"    BL filewrite_main_hook\n"
"    LDMFD SP!, {R4-R12,LR}\n"
//hook end
"    LDR     R7, [R4, #8] \n"
"    LDR     R5, [R4, #0xC] \n"
"    MOV     R2, R8 \n"
"    MOV     R1, R7 \n"
"    MOV     R0, R6 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    LDR     PC, =0xFFA89624 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FFA89714_my @ 0xFFA89714 - 0xFFA8981C, length=67
void __attribute__((naked,noinline)) sub_FFA89714_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #6 \n"
"    BHI     loc_FFA89740 \n"
"    ADD     R0, R5, R0, LSL#3 \n"
"    LDR     R8, [R0, #0x14]! \n"
"    LDR     R7, [R0, #4] \n"
"    CMP     R7, #0 \n"
"    BNE     loc_FFA89758 \n"
"    B       loc_FFA8974C \n"

"loc_FFA89740:\n"
"    LDR     R1, =0x299 \n"
"    LDR     R0, =0xFFA893E4 /*'dwFWrite.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FFA8974C:\n"
"    MOV     R1, R5 \n"
"    MOV     R0, #7 \n"
"    B       loc_FFA897EC \n"

"loc_FFA89758:\n"
"    LDR     R9, =0xA9C8 \n"
"    MOV     R4, R7 \n"

"loc_FFA89760:\n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R4, #0x1000000 \n"
"    MOVLS   R6, R4 \n"
"    MOVHI   R6, #0x1000000 \n"
"    BIC     R1, R0, #0xFF000000 \n"
"    CMP     R1, #0 \n"
"    BICNE   R0, R0, #0xFF000000 \n"
"    RSBNE   R0, R0, #0x1000000 \n"
"    CMPNE   R6, R0 \n"
"    MOVHI   R6, R0 \n"
"    LDR     R0, [R9, #4] \n"
"    MOV     R2, R6 \n"
"    MOV     R1, R8 \n"
"    BL      fwt_write \n"  // --> Patched. Old value = _Write.
"    LDR     R1, [R5, #4] \n"
"    CMP     R6, R0 \n"
"    ADD     R1, R1, R0 \n"
"    STR     R1, [R5, #4] \n"
"    BEQ     loc_FFA897C0 \n"
"    CMN     R0, #1 \n"
"    LDRNE   R0, =0x9200015 \n"
"    LDREQ   R0, =0x9200005 \n"
"    STR     R0, [R5, #0x10] \n"
"    B       loc_FFA8974C \n"

"loc_FFA897C0:\n"
"    SUB     R4, R4, R0 \n"
"    CMP     R4, R7 \n"
"    ADD     R8, R8, R0 \n"
"    MOVCS   R1, #0x2C4 \n"
"    LDRCS   R0, =0xFFA893E4 /*'dwFWrite.c'*/ \n"
"    BLCS    _DebugAssert \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FFA89760 \n"
"    LDR     R0, [R5] \n"
"    MOV     R1, R5 \n"
"    ADD     R0, R0, #1 \n"

"loc_FFA897EC:\n"
"    LDMFD   SP!, {R4-R10,LR} \n"
"    B       sub_FFA890CC \n"
);
}

/*************************************************************/
//** sub_FFA8917C_my @ 0xFFA8917C - 0xFFA891B0, length=14
void __attribute__((naked,noinline)) sub_FFA8917C_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0xA9C8 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    SUB     SP, SP, #0x38 \n"
"    CMN     R0, #1 \n"
"    BEQ     sub_FFA891C4 \n"
"    LDR     R1, [R4, #8] \n"
"    LDR     R6, =0x9200003 \n"
"    TST     R1, #0x8000 \n"
"    BEQ     loc_FFA891B0 \n"
//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_D\n" // jump over the next block
//mod end
"    BL      sub_FF836AE4 \n"
"    B       sub_FFA891B4 \n"

"loc_FFA891B0:\n"
"loc_D:\n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    LDR     PC, =0xFFA891B4 \n"  // Continue in firmware
);
}
