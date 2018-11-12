/*
 * movie_rec.c - auto-generated by CHDK code_gen.
 */
#include "conf.h"

static int bitrate_multiplier = 4; // unit: factory rate / 4
static int bitrate_changed = 0;
extern int video_target_framesize;
extern int video_target_framesize2;


static int orig_bitrate[2]; // original bitrates, saved at beginning of recording

void change_video_tables(int a, int b) {
    bitrate_multiplier = (a<<2)/b;
    bitrate_changed = 1;
}

// firmware: -12 (best) ... +20 (worst)
void  set_quality(int *x){ // -17 highest; +12 lowest
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

void save_original_bitrates() {
    orig_bitrate[0] = video_target_framesize;
    orig_bitrate[1] = video_target_framesize2;
    bitrate_changed = 1;
}

void modify_bitrate() {
    if (bitrate_changed) {
        bitrate_changed = 0;
        video_target_framesize = (orig_bitrate[0] * bitrate_multiplier) >> 2;
        video_target_framesize2 = (orig_bitrate[1] * bitrate_multiplier) >> 2;
    }
}


/*************************************************************/
//** movie_record_task @ 0xFF21537C - 0xFF215580, length=130
void __attribute__((naked,noinline)) movie_record_task() {
asm volatile (
"    STMFD   SP!, {R2-R10,LR} \n"
"    LDR     R8, =0xFF214F2C \n"
"    LDR     R4, =0xA588 \n"
"    LDR     R9, =0x709 \n"
"    LDR     R10, =0x2710 \n"
"    MVN     R7, #0 \n"
"    MOV     R5, #1 \n"
"    MOV     R6, #0 \n"

"loc_FF21539C:\n"
"    LDR     R0, [R4, #0x30] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_006B849C /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [R4, #0x38] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, [R4, #0x14] \n"
"    CMPNE   R0, #2 \n"
"    LDRNE   R0, [R4, #0x4C] \n"
"    CMPNE   R0, #6 \n"
"    BNE     loc_FF215564 \n"
"    LDR     R0, [SP, #4] \n"
"    LDR     R1, [R0] \n"
"    SUB     R1, R1, #2 \n"
"    CMP     R1, #0x12 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF215564 \n"
"    B       loc_FF215478 \n"
"    B       loc_FF2154A0 \n"
"    B       loc_FF2154B0 \n"
"    B       loc_FF2154B8 \n"
"    B       loc_FF2154C0 \n"
"    B       loc_FF2154DC \n"
"    B       loc_FF2154E4 \n"
"    B       loc_FF2154F0 \n"
"    B       loc_FF2154F8 \n"
"    B       loc_FF215480 \n"
"    B       loc_FF215524 \n"
"    B       loc_FF215550 \n"
"    B       loc_FF215558 \n"
"    B       loc_FF215488 \n"
"    B       loc_FF215564 \n"
"    B       loc_FF215560 \n"
"    B       loc_FF215454 \n"
"    B       loc_FF215428 \n"

"loc_FF215428:\n"
"    STR     R6, [R4, #0x48] \n"
"    STR     R6, [R4, #0x3C] \n"
"    STR     R7, [R4, #0x10C] \n"
"    STRH    R6, [R4, #8] \n"
"    STR     R8, [R4, #0xEC] \n"
"    LDR     R0, [R4, #0x14] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0x14] \n"
"    MOV     R0, #6 \n"
"    STR     R0, [R4, #0x4C] \n"
"    B       loc_FF215470 \n"

"loc_FF215454:\n"
"    STR     R6, [R4, #0x48] \n"
"    STR     R7, [R4, #0x10C] \n"
"    STR     R8, [R4, #0xEC] \n"
"    LDR     R0, [R4, #0x14] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0x14] \n"
"    STR     R5, [R4, #0x4C] \n"

"loc_FF215470:\n"
"    STR     R5, [R4, #0xC] \n"
"    B       loc_FF215564 \n"

"loc_FF215478:\n"
"    BL      sub_FF214B30 \n"
"    BL      save_original_bitrates \n"      // + (executed at recording start)
"    B       loc_FF215564 \n"

"loc_FF215480:\n"
"    LDR     R1, [R4, #0xEC] \n"
"    B       loc_FF2154D4 \n"

"loc_FF215488:\n"
"    LDR     R1, [R0, #0x18] \n"
"    LDR     R2, [R0, #0x28] \n"
"    LDR     R3, [R0, #0x24] \n"
"    LDR     R0, [R0, #4] \n"
"    BL      sub_FF3CF9F0 \n"
"    B       loc_FF215564 \n"

"loc_FF2154A0:\n"
"    LDR     R0, [R4, #0x4C] \n"
"    CMP     R0, #5 \n"
"    STRNE   R5, [R4, #0x3C] \n"
"    B       loc_FF215564 \n"

"loc_FF2154B0:\n"
"    BL      sub_FF2143D0 \n"
"    B       loc_FF215564 \n"

"loc_FF2154B8:\n"
"    BL      sub_FF2142A8 \n"
"    B       loc_FF215564 \n"

"loc_FF2154C0:\n"
"    BL      sub_FF213F5C \n"
"    LDR     R1, [R4, #0xBC] \n"
"    CMP     R1, #0 \n"
"    BEQ     loc_FF215564 \n"
"    LDR     R0, [R4, #0xC0] \n"

"loc_FF2154D4:\n"
"    BLX     R1 \n"
//begin patch (only effective in VGA mode)
"    LDR     R0, =video_compression_rate \n" // +
"    BL      set_quality \n"                 // +
"    BL      modify_bitrate \n"              // + (modifies target bitrate if requested)
//end patch
"    B       loc_FF215564 \n"

"loc_FF2154DC:\n"
"    BL      sub_FF213C98 \n"
"    B       loc_FF215564 \n"

"loc_FF2154E4:\n"
"    LDR     R0, =0xFF213C24 \n"
"    BL      sub_FF3CF6AC \n"
"    B       loc_FF215564 \n"

"loc_FF2154F0:\n"
"    BL      sub_FF2138B0 \n"
"    B       loc_FF215564 \n"

"loc_FF2154F8:\n"
"    LDR     R1, [R4, #0xA4] \n"
"    LDR     R0, =0x49AF430C \n"
"    CMP     R1, #1 \n"
"    LDRNE   R1, =0xFF213850 \n"
"    LDRNE   R0, [R4, #0xA8] \n"
"    BNE     loc_FF21551C \n"
"    BL      sub_FF3D0380 \n"
"    LDR     R1, =0xFF213850 \n"
"    MOV     R0, #0 \n"

"loc_FF21551C:\n"
"    BL      sub_FF3CE96C \n"
"    B       loc_FF215564 \n"

"loc_FF215524:\n"
"    LDR     R0, =0x182CD0 \n"
"    LDR     R0, [R0, #8] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0xFF2137A4 \n"
"    LDRNE   R0, =0xFF21382C \n"
"    MOVNE   R3, #0 \n"
"    MOVNE   R1, R3 \n"
"    BLNE    sub_FF078224 \n"
"    MOV     R0, #3 \n"
"    STR     R0, [R4, #0x4C] \n"
"    B       loc_FF215564 \n"

"loc_FF215550:\n"
"    BL      sub_FF21370C \n"
"    B       loc_FF215564 \n"

"loc_FF215558:\n"
"    BL      sub_FF215F78 \n"
"    B       loc_FF215564 \n"

"loc_FF215560:\n"
"    BL      sub_FF2135E0 \n"

"loc_FF215564:\n"
"    LDR     R1, [SP, #4] \n"
"    LDR     R3, =0xFF213114 /*'MovieRecorder.c'*/ \n"
"    STR     R6, [R1] \n"
"    STR     R9, [SP] \n"
"    LDR     R0, [R4, #0x34] \n"
"    MOV     R2, R10 \n"
"    BL      sub_006B7D38 /*_PostMessageQueueStrictly*/ \n"
"    B       loc_FF21539C \n"
);
}

/*************************************************************/
//** liveimage_task @ 0xFF13499C - 0xFF134A54, length=47
void __attribute__((naked,noinline)) liveimage_task() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    LDR     R4, =0x5FB0 \n"
"    MOV     R5, #0 \n"

"loc_FF1349A8:\n"
"    LDR     R0, [R4, #0xC] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_006B849C /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF1349D8 \n"
"    MOV     R2, #0x78 \n"
"    LDR     R1, =0xFF134BB4 /*'LiveImageTask.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R5,PC} \n"

"loc_FF1349D8:\n"
"    LDR     R1, [SP] \n"
"    LDR     R0, [R1] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF134A20 \n"
"    CMP     R0, #1 \n"
"    MOVEQ   R1, #1 \n"
"    BEQ     loc_FF134A38 \n"
"    CMP     R0, #2 \n"
"    BEQ     loc_FF134A34 \n"
"    CMP     R0, #3 \n"
"    BNE     loc_FF134A44 \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #1 \n"
"    BEQ     loc_FF1349A8 \n"
"    LDR     R0, [R4, #8] \n"
"    BLX     R0 \n"
"    STR     R5, [R4, #8] \n"
"    B       loc_FF1349A8 \n"

"loc_FF134A20:\n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #1 \n"
"    ADDNE   R0, R1, #4 \n"
"    BLNE    sub_FF134C78_my \n"  // --> Patched. Old value = 0xFF134C78.
"    B       loc_FF1349A8 \n"

"loc_FF134A34:\n"
"    MOV     R1, #2 \n"

"loc_FF134A38:\n"
"    LDR     R0, [R4, #0x10] \n"
"    BL      sub_006B8230 /*_SetEventFlag*/ \n"
"    B       loc_FF1349A8 \n"

"loc_FF134A44:\n"
"    MOV     R2, #0x97 \n"
"    LDR     R1, =0xFF134BB4 /*'LiveImageTask.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"
"    B       loc_FF1349A8 \n"
);
}

/*************************************************************/
//** sub_FF134C78_my @ 0xFF134C78 - 0xFF134D28, length=45
void __attribute__((naked,noinline)) sub_FF134C78_my() {
asm volatile (
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x18 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF134D1C \n"
"    B       sub_FF132F10 \n"
"    B       sub_FF133184 \n"
"    B       loc_FF134D1C \n"
"    B       loc_FF134CEC \n"
"    B       sub_FF133B08 \n"
"    B       sub_FF133D04 \n"
"    B       sub_FF1340F0 \n"
"    B       sub_FF132F10 \n"
"    B       sub_FF1338F0 \n"
"    B       loc_FF134D1C \n"
"    B       loc_FF134D1C \n"
"    B       loc_FF134D1C \n"
"    B       loc_FF134CEC \n"
"    B       sub_FF134418 \n"
"    B       sub_FF134418 \n"
"    B       loc_FF134D1C \n"
"    B       sub_FF1337B0 \n"
"    B       loc_FF134D1C \n"
"    B       loc_FF134D1C \n"
"    B       loc_FF134D1C \n"
"    B       loc_FF134D1C \n"
"    B       loc_FF134D1C \n"
"    B       loc_FF134D1C \n"
"    B       sub_FF133060 \n"

"loc_FF134CE8:\n"
"    B       sub_FF133060 \n"

"loc_FF134CEC:\n"
// HD movie codepath
"    LDR     R1, [R0, #0x64] \n"
"    CMP     R1, #1 \n"
"    BNE     sub_FF13354C_my \n"  // --> Patched. Old value = 0xFF13354C.
"    BEQ     sub_FF133368_my \n"  // --> Patched. Old value = 0xFF133368.

"loc_FF134CFC:\n"
"    B       sub_FF133184 \n"

"loc_FF134D00:\n"
"    B       sub_FF133B08 \n"

"loc_FF134D04:\n"
"    B       sub_FF132F10 \n"

"loc_FF134D08:\n"
"    B       sub_FF133D04 \n"

"loc_FF134D0C:\n"
"    B       sub_FF1337B0 \n"

"loc_FF134D10:\n"
"    B       sub_FF1338F0 \n"

"loc_FF134D14:\n"
"    B       sub_FF1340F0 \n"

"loc_FF134D18:\n"
"    B       sub_FF134418 \n"

"loc_FF134D1C:\n"
"    MOV     R2, #0x69 \n"
"    LDR     R1, =0xFF134BB4 /*'LiveImageTask.c'*/ \n"
"    MOV     R0, #0 \n"
"    B       _DebugAssert \n"
);
}

/*************************************************************/
//** sub_FF13354C_my @ 0xFF13354C - 0xFF1337AC, length=153
void __attribute__((naked,noinline)) sub_FF13354C_my() {
asm volatile (
// Need to execute our code after the firmware subroutine
// it's more complicated here than usual
"    PUSH    {LR} \n"                        // +
"    MOV     LR, PC \n"                      // +
"    LDR     PC, =0xFF13354C \n"  // Continue in firmware
"    LDR     R0, =video_compression_rate \n" // +
"    BL      set_quality \n"                 // +
"    BL      modify_bitrate \n"              // + (modifies target bitrate if requested)
"    POP     {PC} \n"                        // +
);
}

/*************************************************************/
//** sub_FF133368_my @ 0xFF133368 - 0xFF133548, length=121
void __attribute__((naked,noinline)) sub_FF133368_my() {
asm volatile (
// Need to execute our code after the firmware subroutine
// it's more complicated here than usual
"    PUSH    {LR} \n"                        // +
"    MOV     LR, PC \n"                      // +
"    LDR     PC, =0xFF133368 \n"  // Continue in firmware
"    LDR     R0, =video_compression_rate \n" // +
"    BL      set_quality \n"                 // +
"    BL      modify_bitrate \n"              // + (modifies target bitrate if requested)
"    POP     {PC} \n"                        // +
);
}