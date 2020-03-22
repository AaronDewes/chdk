#include "conf.h"

int *video_quality = &conf.video_quality;
int *video_mode    = &conf.video_mode;

long def_table1[9]={0x2000,0x38D,0x788,0x5800,0x9C5,0x14B8,0x10000,0x1C6A,0x3C45};
long def_table2[9]={0x1CCD,-0x2E1,-0x579,0x4F33,-0x7EB,-0xF0C,0xE666,-0x170A,-0x2BC6};

long table1[9], table2[9];

void change_video_tables(int a, int b){
 int i;
 for (i=0;i<9;i++) {table1[i]=(def_table1[i]*a)/b; table2[i]=(def_table2[i]*a)/b;}
}

long CompressionRateTable[]={0x60, 0x5D, 0x5A, 0x57, 0x54, 0x51, 0x4D, 0x48, 0x42, 0x3B, 0x32, 0x29, 0x22, 0x1D, 0x17, 0x14, 0x10, 0xE, 0xB, 9, 7, 6, 5, 4, 3, 2, 1};


void __attribute__((naked,noinline)) movie_record_task(){ // sub_FF949728
asm volatile (
      "    STMFD   SP!, {R4,LR} \n" 
      "    SUB     SP, SP, #4 \n" 
      "    MOV     R4, SP \n" 
      "    B       loc_FF9497E8 \n" 
"loc_FF949738:\n"
      "    LDR     R3, =0x740C0 \n" 
      "    LDR     R2, [R3] \n" 
      "    CMP     R2, #0 \n" 
      "    BNE     loc_FF9497D4 \n" 
      "    SUB     R3, R12, #1 \n" 
      "    CMP     R3, #0xA \n" 
      "    LDRLS   PC, [PC, R3, LSL #2] \n" 
      "    B       loc_FF9497D4 \n" 
      "    .long   loc_FF949784 \n" 
      "    .long   loc_FF94978C \n" 
      "    .long   loc_FF9497A4 \n" 
      "    .long   loc_FF9497AC \n" 
      "    .long   loc_FF9497B4 \n" 
      "    .long   loc_FF949794 \n" 
      "    .long   loc_FF9497BC \n" 
      "    .long   loc_FF94979C \n" 
      "    .long   loc_FF9497D4 \n" 
      "    .long   loc_FF9497CC \n" 
      "    .long   loc_FF9497C4 \n" 
"loc_FF949784:\n"
      "    BL      sub_FF949868 \n" 
      "    B       loc_FF9497D0 \n" 
"loc_FF94978C:\n"
      "    BL      unlock_optical_zoom\n" // +
      "    BL      sub_FF949A9C \n" 
      "    B       loc_FF9497D0 \n" 
"loc_FF949794:\n"
      "    BL      sub_FF949F54_my \n" // ->
      "    B       loc_FF9497D0 \n" 
"loc_FF94979C:\n"
      "    BL      sub_FF94A3A8 \n" 
      "    B       loc_FF9497D0 \n" 
"loc_FF9497A4:\n"
      "    BL      sub_FF94A1CC \n" 
      "    B       loc_FF9497D0 \n" 
"loc_FF9497AC:\n"
      "    BL      sub_FF94A5B4 \n" 
      "    B       loc_FF9497D0 \n" 
"loc_FF9497B4:\n"
      "    BL      sub_FF94A7CC \n" 
      "    B       loc_FF9497D0 \n" 
"loc_FF9497BC:\n"
      "    BL      sub_FF94A468 \n" 
      "    B       loc_FF9497D0 \n" 
"loc_FF9497C4:\n"
      "    BL      sub_FF94A548 \n" 
      "    B       loc_FF9497D0 \n" 
"loc_FF9497CC:\n"
      "    BL      sub_FF94A21C \n" 
"loc_FF9497D0:\n"
      "    LDR     R1, [SP] \n" 
"loc_FF9497D4:\n"
      "    LDR     R3, =0x73FF0 \n" 
      "    MOV     R2, #0 \n" 
      "    STR     R2, [R1] \n" 
      "    LDR     R0, [R3] \n" 
      "    BL      sub_FF8207A4 \n" 
"loc_FF9497E8:\n"
      "    LDR     R3, =0x73FEC \n" 
      "    MOV     R1, R4 \n" 
      "    LDR     R0, [R3] \n" 
      "    MOV     R2, #0 \n" 
      "    BL      sub_FF82038C \n" 
      "    LDR     R0, [SP] \n" 
      "    LDR     R12, [R0] \n" 
      "    CMP     R12, #0xC \n" 
      "    MOV     R1, R0 \n" 
      "    BNE     loc_FF949738 \n" 
      "    LDR     R3, =0x73FE4 \n" 
      "    LDR     R0, [R3] \n" 
      "    BL      sub_FF821160 \n" 
      "    BL      sub_FF821928 \n" 
      "    ADD     SP, SP, #4 \n" 
      "    LDMFD   SP!, {R4,PC} \n" 
    );
}


void __attribute__((naked,noinline)) sub_FF949F54_my(  ) {
asm volatile (
      "    STMFD   SP!, {R4-R11,LR} \n" 
      "    LDR     R5, =0x740DC \n" 
      "    SUB     SP, SP, #0x34 \n" 
      "    LDR     R3, [R5] \n" 
      "    CMP     R3, #3 \n" 
      "    MOV     R4, R0 \n" 
      "    MOVEQ   R3, #4 \n" 
      "    STREQ   R3, [R5] \n" 
      "    LDR     R3, =0x74184 \n" 
      "    MOV     LR, PC \n" 
      "    LDR     PC, [R3] \n" 
      "    LDR     R2, [R5] \n" 
      "    CMP     R2, #4 \n" 
      "    BNE     loc_FF94A100 \n" 
      "    ADD     R0, SP, #0x30 \n" 
      "    ADD     R1, SP, #0x2C \n" 
      "    ADD     R2, SP, #0x28 \n" 
      "    ADD     R3, SP, #0x24 \n" 
      "    BL      sub_FF94B7D4_my \n" // ->
      "    CMP     R0, #0 \n"
      "    BNE     loc_FF949FD0 \n" 
      "    LDR     R3, =0x740C8 \n" 
      "    LDR     R2, [R3] \n" 
      "    CMP     R2, #1 \n" 
      "    BNE     loc_FF949FE4 \n" 
      "    LDR     R2, =0x74118 \n" 
      "    LDR     R1, =0x740F0 \n" 
      "    LDR     R12, [R2] \n" 
      "    LDR     R3, [R1] \n" 
      "    CMP     R12, R3 \n" 
      "    BCC     loc_FF949FE4 \n" 
"loc_FF949FD0:\n"
      "    BL      sub_FF94A144 \n" 
      "    BL      sub_FF94A378 \n" 
      "    MOV     R3, #5 \n" 
      "    STR     R3, [R5] \n" 
      "    B       loc_FF94A100 \n" 
"loc_FF949FE4:\n"
      "    LDR     R12, =0x74120 \n" 
      "    LDR     R11, =0x7412C \n" 
      "    LDMIB   R4, {R0-R2} \n" 
      "    LDR     R10, [R12] \n" 
      "    LDR     R7, [R11] \n" 
      "    LDR     R4, [SP, #0x2C] \n" 
      "    LDR     R5, [SP, #0x28] \n" 
      "    LDR     R6, [SP, #0x24] \n" 
      "    LDR     R8, =0x740CC \n" 
      "    LDR     R3, [SP, #0x30] \n" 
      "    ADD     R12, SP, #0x20 \n" 
      "    ADD     LR, SP, #0x1C \n" 
      "    MOV     R9, #1 \n" 
      "    STMEA   SP, {R4-R6,R12} \n" 
      "    STR     R10, [SP, #0x10] \n" 
      "    STR     R7, [SP, #0x14] \n" 
      "    STR     LR, [SP, #0x18] \n" 
      "    STR     R9, [R8] \n" 
      "    BL      sub_FF897928 \n" 
      "    LDR     R3, =0x73FE4 \n" 
      "    MOV     R1, #0x3E8 \n" 
      "    LDR     R0, [R3] \n" 
      "    BL      sub_FF820F78 \n" 
      "    CMP     R0, #9 \n" 
      "    BNE     loc_FF94A058 \n" 
      "    BL      sub_FF94BF94 \n" 
      "    LDR     R3, =0x740DC \n" 
      "    LDR     R0, =0xFF949F3C \n" 
      "    B       loc_FF94A070 \n" 
"loc_FF94A058:\n"
      "    LDR     R5, [SP, #0x1C] \n" 
      "    CMP     R5, #0 \n" 
      "    BEQ     loc_FF94A07C \n" 
      "    BL      sub_FF94BF94 \n" 
      "    LDR     R3, =0x740DC \n" 
      "    LDR     R0, =0xFF949F48 \n" 
"loc_FF94A070:\n"
      "    STR     R9, [R3] \n" 
      "    BL      sub_FF95FD28 \n" 
      "    B       loc_FF94A100 \n" 
"loc_FF94A07C:\n"
      "    BL      sub_FF897A8C \n" 
      "    LDR     R0, [SP, #0x30] \n" 
      "    LDR     R1, [SP, #0x20] \n" 
      "    BL      sub_FF94BCB8 \n" 
      "    LDR     R4, =0x74118 \n" 
      "    LDR     R3, [R4] \n" 
      "    ADD     R3, R3, #1 \n" 
      "    LDR     R0, [SP, #0x20] \n" 
      "    MOV     R1, R11 \n" 
      "    STR     R3, [R4] \n" 
      "    MOV     R2, R5 \n" 
      "    BL      sub_FF94AB9C_my \n" // ->
      "    LDR     R3, =0x74104 \n" 
      "    LDR     R4, [R4] \n" 
      "    LDR     R1, [R3] \n" 
      "    MOV     R0, R4 \n" 
      "    BL      sub_FFAF891C \n" 
      "    CMP     R0, #0 \n" 
      "    BEQ     loc_FF94A0DC \n" 
      "    LDR     R6, =0x740D0 \n" 
      "    LDR     R3, [R6] \n" 
      "    CMP     R3, #1 \n" 
      "    BNE     loc_FF94A0F4 \n" 
      "    B       loc_FF94A0E0 \n" 
"loc_FF94A0DC:\n"
      "    LDR     R6, =0x740D0 \n" 
"loc_FF94A0E0:\n"
      "    MOV     R0, R4 \n" 
      "    LDR     R3, =0x74160 \n" 
      "    MOV     LR, PC \n" 
      "    LDR     PC, [R3] \n" 
      "    STR     R5, [R6] \n" 
"loc_FF94A0F4:\n"
      "    LDR     R2, =0x740CC \n" 
      "    MOV     R3, #0 \n" 
      "    STR     R3, [R2] \n" 
"loc_FF94A100:\n"
      "    ADD     SP, SP, #0x34 \n" 
      "    LDMFD   SP!, {R4-R11,PC} \n" 
    );
}


void __attribute__((naked,noinline)) sub_FF94B7D4_my(  ) {
asm volatile (
      "    STMFD   SP!, {R4-R11,LR} \n" 
      "    LDR     R5, =0x7442C \n" 
      "    SUB     SP, SP, #0x14 \n" 
      "    LDR     LR, [R5] \n" 
      "    LDR     R12, =0x74444 \n" 
      "    ADD     LR, LR, #1 \n" 
      "    LDR     R4, [R12] \n" 
      "    STR     LR, [R5] \n" 
      "    LDR     R12, =0x744C0 \n" 
      "    STR     R0, [SP, #0x10] \n" 
      "    STR     R1, [SP, #0xC] \n" 
      "    STR     R2, [SP, #8] \n" 
      "    STR     R3, [SP, #4] \n" 
      "    CMP     LR, R4 \n" 
      "    LDR     R11, [R12] \n" 
      "    MOVHI   R0, #0x80000001 \n" 
      "    BHI     loc_FF94BC6C \n" 
      "    LDR     R3, =0x744A8 \n" 
      "    MOV     R0, LR \n" 
      "    LDR     R1, [R3] \n" 
      "    BL      sub_FFAF891C \n" 
      "    CMP     R0, #1 \n" 
      "    BNE     loc_FF94B9F4 \n" 
      "    LDR     R0, =0x744C8 \n" 
      "    LDR     R1, =0x74418 \n" 
      "    LDR     R3, [R0] \n" 
      "    LDR     R2, [R1] \n" 
      "    CMP     R3, R2 \n" 
      "    LDREQ   R3, =0x744C4 \n" 
      "    LDREQ   R5, [R3] \n" 
      "    MOVNE   R5, R2 \n" 
      "    LDR     R3, =0x7442C \n" 
      "    LDR     R2, =0x744A8 \n" 
      "    LDR     R0, [R3] \n" 
      "    LDR     R1, [R2] \n" 
      "    BL      sub_FFAF828C \n" 
      "    LDR     R3, =0x74420 \n" 
      "    ADD     R0, R0, #1 \n" 
      "    AND     R0, R0, #1 \n" 
      "    STR     R5, [R3, R0, LSL #2] \n" 
      "    LDR     R3, =0x74414 \n" 
      "    LDR     R2, [R3] \n" 
      "    CMP     R5, R2 \n" 
      "    BHI     loc_FF94B8A4 \n" 
      "    LDR     R4, =0x74464 \n" 
      "    LDR     R3, [R4] \n" 
      "    ADD     R3, R5, R3 \n" 
      "    ADD     R3, R3, #8 \n" 
      "    CMP     R2, R3 \n" 
      "    BCS     loc_FF94B8A8 \n" 
"loc_FF94B89C:\n"
      "    MOV     R0, #0x80000003 \n" 
      "    B       loc_FF94BC6C \n" 
"loc_FF94B8A4:\n"
      "    LDR     R4, =0x74464 \n" 
"loc_FF94B8A8:\n"
      "    LDR     R3, [R4] \n" 
      "    LDR     R2, =0x744C8 \n" 
      "    ADD     R1, R5, R3 \n" 
      "    LDR     R3, [R2] \n" 
      "    ADD     R2, R1, #8 \n" 
      "    CMP     R2, R3 \n" 
      "    BLS     loc_FF94B8F4 \n" 
      "    LDR     R2, =0x744C4 \n" 
      "    LDR     R0, =0x74414 \n" 
      "    RSB     R3, R3, R1 \n" 
      "    LDR     R1, [R2] \n" 
      "    ADD     R3, R3, #8 \n" 
      "    LDR     R2, [R0] \n" 
      "    ADD     R1, R1, R3 \n" 
      "    CMP     R2, R1 \n" 
      "    BCC     loc_FF94B89C \n" 
      "    LDR     R3, =0x74418 \n" 
      "    STR     R1, [R3] \n" 
      "    B       loc_FF94B8FC \n" 
"loc_FF94B8F4:\n"
      "    LDR     R3, =0x74418 \n" 
      "    STR     R2, [R3] \n" 
"loc_FF94B8FC:\n"
      "    LDR     R3, [R4] \n" 
      "    LDR     R12, =0x74478 \n" 
      "    ADD     R3, R3, #0x18 \n" 
      "    LDR     R2, [R12, #4] \n" 
      "    MOV     R0, R3 \n" 
      "    MOV     R1, #0 \n" 
      "    CMP     R1, R2 \n" 
      "    BHI     loc_FF94BB40 \n" 
      "    BNE     loc_FF94B92C \n" 
      "    LDR     R3, [R12] \n" 
      "    CMP     R0, R3 \n" 
      "    BHI     loc_FF94BB40 \n" 
"loc_FF94B92C:\n"
      "    LDR     R4, [R4] \n" 
      "    LDR     LR, =0x74480 \n" 
      "    STR     R4, [SP] \n" 
      "    LDR     R12, =0x74478 \n" 
      "    LDR     R3, =0x7442C \n" 
      "    LDMIA   LR, {R7,R8} \n" 
      "    LDMIA   R12, {R5,R6} \n" 
      "    LDR     R10, [R3] \n" 
      "    LDR     R2, =0x744A8 \n" 
      "    MOV     R3, R4 \n" 
      "    MOV     R4, #0 \n" 
      "    ADDS    R7, R7, R3 \n" 
      "    ADC     R8, R8, R4 \n" 
      "    LDR     R9, [R2] \n" 
      "    SUBS    R5, R5, R3 \n" 
      "    SBC     R6, R6, R4 \n" 
      "    MVN     R2, #0 \n" 
      "    MVN     R1, #0x17 \n" 
      "    ADDS    R5, R5, R1 \n" 
      "    MOV     R4, #0 \n" 
      "    MOV     R3, #0x18 \n" 
      "    ADC     R6, R6, R2 \n" 
      "    ADDS    R7, R7, R3 \n" 
      "    ADC     R8, R8, R4 \n" 
      "    STMIA   R12, {R5,R6} \n" 
      "    SUB     R0, R10, #1 \n" 
      "    MOV     R1, R9 \n" 
      "    STMIA   LR, {R7,R8} \n" 
      "    BL      sub_FFAF828C \n" 
      "    CMP     R10, #1 \n" 
      "    MLA     R0, R9, R0, R0 \n" 
      "    BEQ     loc_FF94B9F4 \n" 
      "    SUB     R3, R0, #1 \n" 
      "    MOV     R3, R3, LSL #4 \n" 
      "    ADD     R4, R11, #0x10 \n" 
      "    ADD     R5, R11, #0x14 \n" 
      "    LDR     R1, [R5, R3] \n" 
      "    LDR     R2, [R4, R3] \n" 
      "    LDR     LR, =0x62773130 \n" 
      "    ADD     R2, R2, R1 \n" 
      "    MOV     R3, R0, LSL #4 \n" 
      "    ADD     R2, R2, #8 \n" 
      "    MOV     R0, #0 \n" 
      "    ADD     R12, R11, #0xC \n" 
      "    ADD     R1, R11, #8 \n" 
      "    STR     LR, [R1, R3] \n" 
      "    STR     R0, [R12, R3] \n" 
      "    STR     R2, [R4, R3] \n" 
      "    LDR     R0, [SP] \n" 
      "    STR     R0, [R5, R3] \n" 
"loc_FF94B9F4:\n"
      "    LDR     R2, =0x74418 \n" 
      "    LDR     R3, =0x744C8 \n" 
      "    LDR     R1, [R2] \n" 
      "    LDR     R0, [R3] \n" 
      "    ADD     R3, R1, #9 \n" 
      "    CMP     R3, R0 \n" 
      "    BLS     loc_FF94BA30 \n" 
      "    LDR     R2, =0x744C4 \n" 
      "    LDR     R3, [R2] \n" 
      "    ADD     R3, R3, R1 \n" 
      "    RSB     R3, R0, R3 \n" 
      "    LDR     R0, [SP, #0x10] \n" 
      "    ADD     R3, R3, #8 \n" 
      "    STR     R3, [R0] \n" 
      "    B       loc_FF94BA3C \n" 
"loc_FF94BA30:\n"
      "    ADD     R3, R1, #8 \n" 
      "    LDR     R1, [SP, #0x10] \n" 
      "    STR     R3, [R1] \n" 
"loc_FF94BA3C:\n"
      "    LDR     R2, [SP, #0x10] \n" 
      "    LDR     R1, =0x74474 \n" 
      "    LDR     R3, =0x744C8 \n" 
      "    LDR     R12, [R2] \n" 
      "    LDR     R2, [R1] \n" 
      "    LDR     R0, [R3] \n" 
      "    ADD     R3, R12, R2 \n" 
      "    CMP     R3, R0 \n" 
      "    BLS     loc_FF94BA90 \n" 
      "    LDR     R2, [SP, #0xC] \n" 
      "    RSB     R0, R12, R0 \n" 
      "    STR     R0, [R2] \n" 
      "    LDR     R2, =0x744C4 \n" 
      "    LDR     R3, [R1] \n" 
      "    LDR     R1, [R2] \n" 
      "    RSB     R3, R0, R3 \n" 
      "    LDR     R0, [SP, #8] \n" 
      "    STR     R1, [R0] \n" 
      "    LDR     R1, [SP, #4] \n" 
      "    STR     R3, [R1] \n" 
      "    B       loc_FF94BAAC \n" 
"loc_FF94BA90:\n"
      "    LDR     R0, [SP, #0xC] \n" 
      "    STR     R2, [R0] \n" 
      "    LDR     R1, [SP, #4] \n" 
      "    MOV     R3, #0 \n" 
      "    STR     R3, [R1] \n" 
      "    LDR     R2, [SP, #8] \n" 
      "    STR     R3, [R2] \n" 
"loc_FF94BAAC:\n"
      "    LDR     R0, =0x74418 \n" 
      "    LDR     R1, =0x74414 \n" 
      "    LDR     R3, [R0] \n" 
      "    LDR     R2, [R1] \n" 
      "    CMP     R3, R2 \n" 
      "    BHI     loc_FF94BAD8 \n" 
      "    LDR     R0, [SP, #0xC] \n" 
      "    LDR     R3, [R0] \n" 
      "    ADD     R3, R12, R3 \n" 
      "    CMP     R2, R3 \n" 
      "    BCC     loc_FF94B89C \n" 
"loc_FF94BAD8:\n"
      "    LDR     R1, [SP, #8] \n" 
      "    LDR     R2, [R1] \n" 
      "    CMP     R2, #0 \n" 
      "    BEQ     loc_FF94BB0C \n" 
      "    LDR     R3, =0x74414 \n" 
      "    LDR     R1, [R3] \n" 
      "    CMP     R2, R1 \n" 
      "    BHI     loc_FF94BB0C \n" 
      "    LDR     R0, [SP, #4] \n" 
      "    LDR     R3, [R0] \n" 
      "    ADD     R3, R2, R3 \n" 
      "    CMP     R1, R3 \n" 
      "    BCC     loc_FF94B89C \n" 
"loc_FF94BB0C:\n"
      "    LDR     R3, =0x74474 \n" 
      "    LDR     R0, =0x74478 \n" 
      "    LDR     R2, [R3] \n" 
      "    LDR     R3, [R0, #4] \n" 
      "    ADD     R2, R2, #0x18 \n" 
      "    MOV     R1, R2 \n" 
      "    MOV     R2, #0 \n" 
      "    CMP     R2, R3 \n" 
      "    BHI     loc_FF94BB40 \n" 
      "    BNE     loc_FF94BB48 \n" 
      "    LDR     R3, [R0] \n" 
      "    CMP     R1, R3 \n" 
      "    BLS     loc_FF94BB48 \n" 
"loc_FF94BB40:\n"
      "    MOV     R0, #0x80000005 \n" 
      "    B       loc_FF94BC6C \n" 
"loc_FF94BB48:\n"
      "    LDR     R1, =0x7445C \n" 
      "    LDR     R0, =0x744A8 \n" 
      "    LDR     R3, [R1] \n" 
      "    LDR     R2, [R0] \n" 
      "    ADD     R3, R3, R2, LSL #4 \n" 
      "    ADD     R3, R3, R3, LSL #2 \n" 
      "    LDR     R12, =0x74478 \n" 
      "    MOV     R3, R3, LSL #1 \n" 
      "    ADD     R3, R3, #0xA0 \n" 
      "    LDR     R2, [R12, #4] \n" 
      "    MOV     R0, R3 \n" 
      "    MOV     R1, #0 \n" 
      "    CMP     R1, R2 \n" 
      "    BHI     loc_FF94BB90 \n" 
      "    BNE     loc_FF94BBB4 \n" 
      "    LDR     R3, [R12] \n" 
      "    CMP     R0, R3 \n" 
      "    BLS     loc_FF94BBB4 \n" 
"loc_FF94BB90:\n"
      "    LDR     R4, =0x74490 \n" 
      "    LDR     R1, [R4] \n" 
      "    CMP     R1, #0 \n" 
      "    BNE     loc_FF94BBB4 \n" 
      "    MOV     R0, #0x3140 \n" 
      "    ADD     R0, R0, #8 \n" 
      "    BL      sub_FF963F80 \n" 
      "    MOV     R3, #1 \n" 
      "    STR     R3, [R4] \n" 
"loc_FF94BBB4:\n"
      "    LDR     R1, =0x7445C \n" 
      "    LDR     R0, =0x744A8 \n" 
      "    LDR     R2, [R1] \n" 
      "    LDR     R3, [R0] \n" 
      "    LDR     R0, =0x74480 \n" 
      "    ADD     R2, R2, R3, LSL #4 \n" 
      "    MVN     R3, #0x9F \n" 
      "    ADD     R2, R2, R2, LSL #2 \n" 
      "    ADD     R3, R3, #0x40000000 \n" 
      "    SUB     R3, R3, R2, LSL #1 \n" 
      "    LDR     R1, [R0, #4] \n" 
      "    MOV     R4, R3 \n" 
      "    MOV     R5, #0 \n" 
      "    CMP     R1, R5 \n" 
      "    BHI     loc_FF94BC00 \n" 
      "    BNE     loc_FF94BC24 \n" 
      "    LDR     R3, [R0] \n" 
      "    CMP     R3, R4 \n" 
      "    BLS     loc_FF94BC24 \n" 
"loc_FF94BC00:\n"
      "    LDR     R4, =0x74490 \n" 
      "    LDR     R1, [R4] \n" 
      "    CMP     R1, #0 \n" 
      "    BNE     loc_FF94BC24 \n" 
      "    MOV     R0, #0x3140 \n" 
      "    ADD     R0, R0, #8 \n" 
      "    BL      sub_FF963F80 \n" 
      "    MOV     R3, #1 \n" 
      "    STR     R3, [R4] \n" 
"loc_FF94BC24:\n"
      "    LDR     R3, =0x74480 \n" 
      "    LDR     R12, =0x74474 \n" 
      "    LDMIA   R3, {R1,R2} \n" 
      "    LDR     R0, [R12] \n" 
      "    MOV     R4, #0 \n" 
      "    MOV     R3, #0x18 \n" 
      "    ADDS    R1, R1, R0 \n" 
      "    ADC     R2, R2, #0 \n" 
      "    ADDS    R1, R1, R3 \n" 
      "    ADC     R2, R2, R4 \n" 
      "    CMP     R2, #0 \n" 
      "    BHI     loc_FF94BC60 \n" 
      "    BNE     loc_FF94BC68 \n" 
      "    CMP     R1, #0x40000000 \n" 
//      "    BLS     loc_FF94BC68 \n" // -
      "    B       loc_FF94BC68 \n" // + (no filesize limit)
"loc_FF94BC60:\n"
      "    MOV     R0, #0x80000007 \n" 
      "    B       loc_FF94BC6C \n" 
"loc_FF94BC68:\n"
      "    MOV     R0, #0 \n" 
"loc_FF94BC6C:\n"
      "    ADD     SP, SP, #0x14 \n" 
      "    LDMFD   SP!, {R4-R11,PC} \n" 
    );
}


void __attribute__((naked,noinline)) sub_FF94AB9C_my(  ) {
asm volatile (
      "    CMP     R2, #1 \n" 
      "    STMFD   SP!, {R4-R7,LR} \n" 
      "    MOV     R7, R0 \n" 
      "    MOV     R6, R1 \n" 
      "    MOVEQ   R3, #0x79 \n" 
      "    STREQ   R3, [R6] \n" 
      "    LDMEQFD SP!, {R4-R7,PC} \n" 
      "    LDR     R12, =0x74190 \n" 
      "    LDR     R0, [R12] \n" 
      "    LDR     R3, =0x74198 \n" 
      "    CMP     R0, #0 \n" 
      "    LDR     R1, [R3] \n" 
      "    BEQ     loc_FF94ABE4 \n" 
      "    LDR     R2, =0x7419C \n" 
      "    LDR     R3, [R2] \n" 
      "    CMP     R3, #1 \n" 
      "    BNE     loc_FF94ABF8 \n" 
      "    B       loc_FF94ABE8 \n" 
"loc_FF94ABE4:\n"
      "    LDR     R2, =0x7419C \n" 
"loc_FF94ABE8:\n"
      "    MOV     R3, #0 \n" 
      "    STR     R3, [R2] \n" 
      "    STR     R7, [R12] \n" 
      "    B       loc_FF94ACAC \n" 
"loc_FF94ABF8:\n"
      "    LDR     R3, =0x74194 \n" 
      "    LDR     R2, [R3] \n" 
      "    LDR     R5, =table1\n" // was 0xFF94AA04
      "    MOV     LR, R2, LSL #2 \n" 
      "    LDR     R3, [R5, LR] \n" 
      "    LDR     R4, =table2\n" // was 0xFF94AA40
      "    RSB     R12, R3, R0 \n" 
      "    LDR     R2, [R4, LR] \n" 
      "    CMP     R12, #0 \n" 
      "    RSB     R0, R2, R0 \n" 
      "    BLE     loc_FF94AC58 \n" 
      "    ADD     R3, R5, #0x14 \n" 
      "    LDR     R2, [R3, LR] \n" 
      "    CMP     R2, R12 \n" 
      "    ADDGE   R1, R1, #1 \n" 
      "    BGE     loc_FF94AC4C \n" 
      "    ADD     R3, R5, #0x28 \n" 
      "    LDR     R2, [R3, LR] \n" 
      "    CMP     R2, R12 \n" 
      "    ADDGE   R1, R1, #2 \n" 
      "    ADDLT   R1, R1, #3 \n" 
"loc_FF94AC4C:\n"
      "    CMP     R1, #0x1a\n"      // was 0xE
      "    MOVGE   R1, #0x1a\n"      // was 0xE
      "    B       loc_FF94AC90 \n" 
"loc_FF94AC58:\n"
      "    CMP     R0, #0 \n" 
      "    BGE     loc_FF94AC90 \n" 
      "    ADD     R3, R4, #0x14 \n" 
      "    LDR     R2, [R3, LR] \n" 
      "    CMP     R2, R0 \n" 
      "    SUBLE   R1, R1, #1 \n" 
      "    BLE     loc_FF94AC88 \n" 
      "    ADD     R3, R4, #0x28 \n" 
      "    LDR     R2, [R3, LR] \n" 
      "    CMP     R2, R0 \n" 
      "    SUBLE   R1, R1, #2 \n" 
      "    SUBGT   R1, R1, #3 \n" 
"loc_FF94AC88:\n"
      "    CMP     R1, #0 \n" 
      "    MOVLT   R1, #0 \n" 
"loc_FF94AC90:\n"
      "    LDR     R0, =0x74198 \n" 
      "    LDR     R3, [R0] \n" 
      "    CMP     R1, R3 \n" 
      "    LDRNE   R2, =0x7419C \n" 
      "    MOVNE   R3, #1 \n" 
      "    STRNE   R1, [R0] \n" 
      "    STRNE   R3, [R2] \n" 
"loc_FF94ACAC:\n"
      "    LDR     R3, =0x74198 \n" 
      "    LDR     R1, =video_mode\n"           // was 0x6D74
      "    LDR     R0, [R3] \n" 
      "    LDR     R2, =CompressionRateTable\n" // was 0xFF94A9C8
      "    LDR     R12, [R1] \n" 
      "    LDR     R12, [R12]\n"                // +
      "    LDR     LR, [R2, R0, LSL #2] \n" 
      "    LDR     R3, =0x74190 \n" 
      "    CMP     R12, #1 \n" 
      "    STR     R7, [R3] \n" 
      "    STR     LR, [R6] \n" 
//      "    MOVEQ   R3, #0xB \n"               // -
      "    LDREQ   R3, =video_quality\n"        // +
      "    LDREQ   R3, [R3]\n"                  // +
      "    LDREQ   R3, [R3]\n"                  // +
      "    STREQ   R3, [R6] \n" 
      "    LDMFD   SP!, {R4-R7,PC} \n" 
    );
}