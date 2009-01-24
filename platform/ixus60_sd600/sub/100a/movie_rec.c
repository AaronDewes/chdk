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

void __attribute__((naked,noinline)) movie_record_task(){
 asm volatile(
                "STMFD   SP!, {R4,LR}\n"
                "SUB     SP, SP, #4\n"
                "MOV     R4, SP\n"
                "B       loc_FF954A7C\n"
"loc_FF9549D8:\n"
                "LDR     R3, =0x6EB28\n"
                "LDR     R2, [R3]\n"
                "CMP     R2, #0\n"
                "BNE     loc_FF954A68\n"
                "SUB     R3, R12, #2\n"
                "CMP     R3, #9\n"
                "LDRLS   PC, [PC,R3,LSL#2]\n"
                "B       loc_FF954A68\n"
                ".long loc_FF954A28\n"
                ".long loc_FF954A40\n"
                ".long loc_FF954A48\n"
                ".long loc_FF954A50\n"
                ".long loc_FF954A30\n"
                ".long loc_FF954A58\n"
                ".long loc_FF954A38\n"
                ".long loc_FF954A68\n"
                ".long loc_FF954A60\n"
                ".long loc_FF954A20\n"
"loc_FF954A20:\n"
                "BL      sub_FF954B14\n"
                "B       loc_FF954A64\n"
"loc_FF954A28:\n"
                "BL      unlock_optical_zoom\n" // +
                "BL      sub_FF954CC8\n"
                "B       loc_FF954A64\n"
"loc_FF954A30:\n"
                "BL      sub_FF95509C_my\n"  //---------->
                "B       loc_FF954A64\n"
"loc_FF954A38:\n"
                "BL      sub_FF9554D0\n"
                "B       loc_FF954A64\n"
"loc_FF954A40:\n"
                "BL      sub_FF955334\n"
                "B       loc_FF954A64\n"
"loc_FF954A48:\n"
                "BL      sub_FF955640\n"
                "B       loc_FF954A64\n"
"loc_FF954A50:\n"
                "BL      sub_FF955804\n"
                "B       loc_FF954A64\n"
"loc_FF954A58:\n"
                "BL      sub_FF955558\n"
                "B       loc_FF954A64\n"
"loc_FF954A60:\n"
                "BL      sub_FF955384\n"
"loc_FF954A64:\n"
                "LDR     R1, [SP]\n"
"loc_FF954A68:\n"
                "LDR     R3, =0x6EA5C\n"
                "MOV     R2, #0\n"
                "STR     R2, [R1]\n"
                "LDR     R0, [R3]\n"
                "BL      sub_FF820814\n"
"loc_FF954A7C:\n"
                "LDR     R3, =0x6EA58\n"
                "MOV     R1, R4\n"
                "LDR     R0, [R3]\n"
                "MOV     R2, #0\n"
                "BL      sub_FF8203FC\n"
                "LDR     R0, [SP]\n"
                "LDR     R12, [R0]\n"
                "CMP     R12, #0xC\n"
                "MOV     R1, R0\n"
                "BNE     loc_FF9549D8\n"
                "LDR     R3, =0x6EA54\n"
                "LDR     R0, [R3]\n"
                "BL      sub_FF821190\n"
                "BL      sub_FF821958\n"
                "ADD     SP, SP, #4\n"
                "LDMFD   SP!, {R4,PC}\n"
 );
}

void __attribute__((naked,noinline)) sub_FF95509C_my(){
 asm volatile(
                "STMFD   SP!, {R4-R11,LR}\n"
                "LDR     R5, =0x6EB44\n"
                "SUB     SP, SP, #0x34\n"
                "LDR     R3, [R5]\n"
                "CMP     R3, #3\n"
                "MOV     R4, R0\n"
                "MOVEQ   R3, #4\n"
                "STREQ   R3, [R5]\n"
                "LDR     R3, =0x6EBF4\n"
                "MOV     LR, PC\n"
                "LDR     PC, [R3]\n"
                "LDR     R2, [R5]\n"
                "CMP     R2, #4\n"
                "BNE     loc_FF955260\n"
                "ADD     R0, SP, #0x30\n"
                "ADD     R1, SP, #0x2C\n"
                "ADD     R2, SP, #0x28\n"
                "ADD     R3, SP, #0x24\n"
                "BL      sub_FF956770_my\n"  //---------->
                "CMP     R0, #0\n"
                "BNE     loc_FF955118\n"
                "LDR     R3, =0x6EB30\n"
                "LDR     R2, [R3]\n"
                "CMP     R2, #1\n"
                "BNE     loc_FF95512C\n"
                "LDR     R2, =0x6EB88\n"
                "LDR     R1, =0x6EB5C\n"
                "LDR     R12, [R2]\n"
                "LDR     R3, [R1]\n"
                "CMP     R12, R3\n"
                "BCC     loc_FF95512C\n"
"loc_FF955118:\n"
                "BL      sub_FF9552AC\n"
                "BL      sub_FF9554AC\n"
                "MOV     R3, #5\n"
                "STR     R3, [R5]\n"
                "B       loc_FF955260\n"
"loc_FF95512C:\n"
                "LDR     R12, =0x6EB90\n"
                "LDR     R11, =0x6EB9C\n"
                "LDMIB   R4, {R0-R2}\n"
                "LDR     R10, [R12]\n"
                "LDR     R7, [R11]\n"
                "LDR     R4, [SP,#0x2C]\n"
                "LDR     R5, [SP,#0x28]\n"
                "LDR     R6, [SP,#0x24]\n"
                "LDR     R8, =0x6EB34\n"
                "LDR     R3, [SP,#0x30]\n"
                "ADD     R12, SP, #0x20\n"
                "ADD     LR, SP, #0x1C\n"
                "MOV     R9, #1\n"
                "STMEA   SP, {R4-R6,R12}\n"
                "STR     R10, [SP,#0x10]\n"
                "STR     R7, [SP,#0x14]\n"
                "STR     LR, [SP,#0x18]\n"
                "STR     R9, [R8]\n"
                "BL      sub_FF89665C\n"
                "LDR     R3, =0x6EA4C\n"
                "MOV     R1, #0x3E8\n"
                "LDR     R0, [R3]\n"
                "BL      sub_FF820FA8\n"
                "CMP     R0, #9\n"
                "BNE     loc_FF9551A0\n"
                "BL      sub_FF956F80\n"
                "LDR     R3, =0x6EB44\n"
                "LDR     R0, =0xFF955084\n"
                "B       loc_FF9551B8\n"
"loc_FF9551A0:\n"
                "LDR     R5, [SP,#0x1C]\n"
                "CMP     R5, #0\n"
                "BEQ     loc_FF9551C4\n"
                "BL      sub_FF956F80\n"
                "LDR     R3, =0x6EB44\n"
                "LDR     R0, =0xFF955090\n"
"loc_FF9551B8:\n"
                "STR     R9, [R3]\n"
                "BL      sub_FF969EB0\n"
                "B       loc_FF955260\n"
"loc_FF9551C4:\n"
                "BL      sub_FF8967C8\n"
                "LDR     R0, [SP,#0x30]\n"
                "LDR     R1, [SP,#0x20]\n"
                "BL      sub_FF956CA4\n"
                "LDR     R4, =0x6EB88\n"
                "LDR     R3, [R4]\n"
                "ADD     R3, R3, #1\n"
                "LDR     R0, [SP,#0x20]\n"
                "MOV     R1, R11\n"
                "STR     R3, [R4]\n"
                "MOV     R2, R5\n"
                "BL      sub_FF955B60_my\n" //-------->
                "LDR     R3, =0x6EBA8\n"
                "LDR     R1, [R4]\n"
                "LDR     R2, [R3]\n"
                "LDR     R12, =0x6EBA4\n"
                "MUL     R0, R2, R1\n"
                "LDR     R1, [R12]\n"
                "BL      sub_FFAFF5B0\n"
                "LDR     R7, =0x6EBA0\n"
                "LDR     R3, [R7]\n"
                "MOV     R4, R0\n"
                "CMP     R3, R4\n"
                "BNE     loc_FF955238\n"
                "LDR     R6, =0x6EB38\n"
                "LDR     R3, [R6]\n"
                "CMP     R3, #1\n"
                "BNE     loc_FF955254\n"
                "B       loc_FF95523C\n"
"loc_FF955238:\n"
                "LDR     R6, =0x6EB38\n"
"loc_FF95523C:\n"
                "LDR     R3, =0x6EBD8\n"
                "MOV     R0, R4\n"
                "MOV     LR, PC\n"
                "LDR     PC, [R3]\n"
                "STR     R5, [R6]\n"
                "STR     R4, [R7]\n"
"loc_FF955254:\n"
                "LDR     R2, =0x6EB34\n"
                "MOV     R3, #0\n"
                "STR     R3, [R2]\n"
"loc_FF955260:\n"
                "ADD     SP, SP, #0x34\n"
                "LDMFD   SP!, {R4-R11,PC}\n"
 );
}


void __attribute__((naked,noinline)) sub_FF956770_my(){
 asm volatile(
                "STMFD   SP!, {R4-R11,LR}\n"
                "LDR     R5, =0x6EE9C\n"
                "SUB     SP, SP, #0x14\n"
                "LDR     LR, [R5]\n"
                "LDR     R12, =0x6EEB4\n"
                "ADD     LR, LR, #1\n"
                "LDR     R4, [R12]\n"
                "STR     LR, [R5]\n"
                "LDR     R12, =0x6EF34\n"
                "STR     R0, [SP,#0x10]\n"
                "STR     R1, [SP,#0xC]\n"
                "STR     R2, [SP,#8]\n"
                "STR     R3, [SP,#4]\n"
                "CMP     LR, R4\n"
                "LDR     R11, [R12]\n"
                "MOVHI   R0, #0x80000001\n"
                "BHI     loc_FF956C58\n"
                "LDR     R3, =0x6EF18\n"
                "MOV     R0, LR\n"
                "LDR     R1, [R3]\n"
                "BL      sub_FFAFFC40\n"
                "CMP     R0, #1\n"
                "BNE     loc_FF956990\n"
                "LDR     R0, =0x6EF3C\n"
                "LDR     R1, =0x6EE88\n"
                "LDR     R3, [R0]\n"
                "LDR     R2, [R1]\n"
                "CMP     R3, R2\n"
                "LDREQ   R3, =0x6EF38\n"
                "LDREQ   R5, [R3]\n"
                "MOVNE   R5, R2\n"
                "LDR     R3, =0x6EE9C\n"
                "LDR     R2, =0x6EF18\n"
                "LDR     R0, [R3]\n"
                "LDR     R1, [R2]\n"
                "BL      sub_FFAFF5B0\n"
                "LDR     R3, =0x6EE90\n"
                "ADD     R0, R0, #1\n"
                "AND     R0, R0, #1\n"
                "STR     R5, [R3,R0,LSL#2]\n"
                "LDR     R3, =0x6EE84\n"
                "LDR     R2, [R3]\n"
                "CMP     R5, R2\n"
                "BHI     loc_FF956840\n"
                "LDR     R4, =0x6EED4\n"
                "LDR     R3, [R4]\n"
                "ADD     R3, R5, R3\n"
                "ADD     R3, R3, #8\n"
                "CMP     R2, R3\n"
                "BCS     loc_FF956844\n"
"loc_FF956838:\n"
                "MOV     R0, #0x80000003\n"
                "B       loc_FF956C58\n"
"loc_FF956840:\n"
                "LDR     R4, =0x6EED4\n"
"loc_FF956844:\n"
                "LDR     R3, [R4]\n"
                "LDR     R2, =0x6EF3C\n"
                "ADD     R1, R5, R3\n"
                "LDR     R3, [R2]\n"
                "ADD     R2, R1, #8\n"
                "CMP     R2, R3\n"
                "BLS     loc_FF956890\n"
                "LDR     R2, =0x6EF38\n"
                "LDR     R0, =0x6EE84\n"
                "RSB     R3, R3, R1\n"
                "LDR     R1, [R2]\n"
                "ADD     R3, R3, #8\n"
                "LDR     R2, [R0]\n"
                "ADD     R1, R1, R3\n"
                "CMP     R2, R1\n"
                "BCC     loc_FF956838\n"
                "LDR     R3, =0x6EE88\n"
                "STR     R1, [R3]\n"
                "B       loc_FF956898\n"
"loc_FF956890:\n"
                "LDR     R3, =0x6EE88\n"
                "STR     R2, [R3]\n"
"loc_FF956898:\n"
                "LDR     R3, [R4]\n"
                "LDR     R12, =0x6EEE8\n"
                "ADD     R3, R3, #0x18\n"
                "LDR     R2, [R12,#4]\n"
                "MOV     R0, R3\n"
                "MOV     R1, #0\n"
                "CMP     R1, R2\n"
                "BHI     loc_FF956ADC\n"
                "BNE     loc_FF9568C8\n"
                "LDR     R3, [R12]\n"
                "CMP     R0, R3\n"
                "BHI     loc_FF956ADC\n"
"loc_FF9568C8:\n"
                "LDR     R4, [R4]\n"
                "LDR     LR, =0x6EEF0\n"
                "STR     R4, [SP]\n"
                "LDR     R12, =0x6EEE8\n"
                "LDR     R3, =0x6EE9C\n"
                "LDMIA   LR, {R7,R8}\n"
                "LDMIA   R12, {R5,R6}\n"
                "LDR     R10, [R3]\n"
                "LDR     R2, =0x6EF18\n"
                "MOV     R3, R4\n"
                "MOV     R4, #0\n"
                "ADDS    R7, R7, R3\n"
                "ADC     R8, R8, R4\n"
                "LDR     R9, [R2]\n"
                "SUBS    R5, R5, R3\n"
                "SBC     R6, R6, R4\n"
                "MVN     R2, #0\n"
                "MVN     R1, #0x17\n"
                "ADDS    R5, R5, R1\n"
                "MOV     R4, #0\n"
                "MOV     R3, #0x18\n"
                "ADC     R6, R6, R2\n"
                "ADDS    R7, R7, R3\n"
                "ADC     R8, R8, R4\n"
                "STMIA   R12, {R5,R6}\n"
                "SUB     R0, R10, #1\n"
                "MOV     R1, R9\n"
                "STMIA   LR, {R7,R8}\n"
                "BL      sub_FFAFF5B0\n"
                "CMP     R10, #1\n"
                "MLA     R0, R9, R0, R0\n"
                "BEQ     loc_FF956990\n"
                "SUB     R3, R0, #1\n"
                "MOV     R3, R3,LSL#4\n"
                "ADD     R4, R11, #0x10\n"
                "ADD     R5, R11, #0x14\n"
                "LDR     R1, [R5,R3]\n"
                "LDR     R2, [R4,R3]\n"
                "LDR     LR, =0x62773130\n"
                "ADD     R2, R2, R1\n"
                "MOV     R3, R0,LSL#4\n"
                "ADD     R2, R2, #8\n"
                "MOV     R0, #0\n"
                "ADD     R12, R11, #0xC\n"
                "ADD     R1, R11, #8\n"
                "STR     LR, [R1,R3]\n"
                "STR     R0, [R12,R3]\n"
                "STR     R2, [R4,R3]\n"
                "LDR     R0, [SP]\n"
                "STR     R0, [R5,R3]\n"
"loc_FF956990:\n"
                "LDR     R2, =0x6EE88\n"
                "LDR     R3, =0x6EF3C\n"
                "LDR     R1, [R2]\n"
                "LDR     R0, [R3]\n"
                "ADD     R3, R1, #9\n"
                "CMP     R3, R0\n"
                "BLS     loc_FF9569CC\n"
                "LDR     R2, =0x6EF38\n"
                "LDR     R3, [R2]\n"
                "ADD     R3, R3, R1\n"
                "RSB     R3, R0, R3\n"
                "LDR     R0, [SP,#0x10]\n"
                "ADD     R3, R3, #8\n"
                "STR     R3, [R0]\n"
                "B       loc_FF9569D8\n"
"loc_FF9569CC:\n"
                "ADD     R3, R1, #8\n"
                "LDR     R1, [SP,#0x10]\n"
                "STR     R3, [R1]\n"
"loc_FF9569D8:\n"
                "LDR     R2, [SP,#0x10]\n"
                "LDR     R1, =0x6EEE4\n"
                "LDR     R3, =0x6EF3C\n"
                "LDR     R12, [R2]\n"
                "LDR     R2, [R1]\n"
                "LDR     R0, [R3]\n"
                "ADD     R3, R12, R2\n"
                "CMP     R3, R0\n"
                "BLS     loc_FF956A2C\n"
                "LDR     R2, [SP,#0xC]\n"
                "RSB     R0, R12, R0\n"
                "STR     R0, [R2]\n"
                "LDR     R2, =0x6EF38\n"
                "LDR     R3, [R1]\n"
                "LDR     R1, [R2]\n"
                "RSB     R3, R0, R3\n"
                "LDR     R0, [SP,#8]\n"
                "STR     R1, [R0]\n"
                "LDR     R1, [SP,#4]\n"
                "STR     R3, [R1]\n"
                "B       loc_FF956A48\n"
"loc_FF956A2C:\n"
                "LDR     R0, [SP,#0xC]\n"
                "STR     R2, [R0]\n"
                "LDR     R1, [SP,#4]\n"
                "MOV     R3, #0\n"
                "STR     R3, [R1]\n"
                "LDR     R2, [SP,#8]\n"
                "STR     R3, [R2]\n"
"loc_FF956A48:\n"
                "LDR     R0, =0x6EE88\n"
                "LDR     R1, =0x6EE84\n"
                "LDR     R3, [R0]\n"
                "LDR     R2, [R1]\n"
                "CMP     R3, R2\n"
                "BHI     loc_FF956A74\n"
                "LDR     R0, [SP,#0xC]\n"
                "LDR     R3, [R0]\n"
                "ADD     R3, R12, R3\n"
                "CMP     R2, R3\n"
                "BCC     loc_FF956838\n"
"loc_FF956A74:\n"
                "LDR     R1, [SP,#8]\n"
                "LDR     R2, [R1]\n"
                "CMP     R2, #0\n"
                "BEQ     loc_FF956AA8\n"
                "LDR     R3, =0x6EE84\n"
                "LDR     R1, [R3]\n"
                "CMP     R2, R1\n"
                "BHI     loc_FF956AA8\n"
                "LDR     R0, [SP,#4]\n"
                "LDR     R3, [R0]\n"
                "ADD     R3, R2, R3\n"
                "CMP     R1, R3\n"
                "BCC     loc_FF956838\n"
"loc_FF956AA8:\n"
                "LDR     R3, =0x6EEE4\n"
                "LDR     R0, =0x6EEE8\n"
                "LDR     R2, [R3]\n"
                "LDR     R3, [R0,#4]\n"
                "ADD     R2, R2, #0x18\n"
                "MOV     R1, R2\n"
                "MOV     R2, #0\n"
                "CMP     R2, R3\n"
                "BHI     loc_FF956ADC\n"
                "BNE     loc_FF956AE4\n"
                "LDR     R3, [R0]\n"
                "CMP     R1, R3\n"
                "BLS     loc_FF956AE4\n"
"loc_FF956ADC:\n"
                "MOV     R0, #0x80000005\n"
                "B       loc_FF956C58\n"
"loc_FF956AE4:\n"
                "LDR     R1, =0x6EECC\n"
                "LDR     R0, =0x6EF18\n"
                "LDR     R3, [R1]\n"
                "LDR     R2, [R0]\n"
                "ADD     R3, R3, R2,LSL#4\n"
                "ADD     R3, R3, R3,LSL#2\n"
                "LDR     R12, =0x6EEE8\n"
                "MOV     R3, R3,LSL#1\n"
                "ADD     R3, R3, #0xA0\n"
                "LDR     R2, [R12,#4]\n"
                "MOV     R0, R3\n"
                "MOV     R1, #0\n"
                "CMP     R1, R2\n"
                "BHI     loc_FF956B2C\n"
                "BNE     loc_FF956B50\n"
                "LDR     R3, [R12]\n"
                "CMP     R0, R3\n"
                "BLS     loc_FF956B50\n"
"loc_FF956B2C:\n"
                "LDR     R4, =0x6EF00\n"
                "LDR     R1, [R4]\n"
                "CMP     R1, #0\n"
                "BNE     loc_FF956B50\n"
                "MOV     R0, #0x3140\n"
                "ADD     R0, R0, #8\n"
                "BL      sub_FF96E3EC\n"
                "MOV     R3, #1\n"
                "STR     R3, [R4]\n"
"loc_FF956B50:\n"
                "LDR     R1, =0x6EECC\n"
                "LDR     R0, =0x6EF18\n"
                "LDR     R2, [R1]\n"
                "LDR     R3, [R0]\n"
                "LDR     R0, =0x6EEF0\n"
                "ADD     R2, R2, R3,LSL#4\n"
                "MVN     R3, #0x9F\n"
                "ADD     R2, R2, R2,LSL#2\n"
                "ADD     R3, R3, #0x40000000\n"
                "SUB     R3, R3, R2,LSL#1\n"
                "LDR     R1, [R0,#4]\n"
                "MOV     R4, R3\n"
                "MOV     R5, #0\n"
                "CMP     R1, R5\n"
                "BHI     loc_FF956B9C\n"
                "BNE     loc_FF956BC0\n"
                "LDR     R3, [R0]\n"
                "CMP     R3, R4\n"
                "BLS     loc_FF956BC0\n"
"loc_FF956B9C:\n"
                "LDR     R4, =0x6EF00\n"
                "LDR     R1, [R4]\n"
                "CMP     R1, #0\n"
                "BNE     loc_FF956BC0\n"
                "MOV     R0, #0x3140\n"
                "ADD     R0, R0, #8\n"
                "BL      sub_FF96E3EC\n"
                "MOV     R3, #1\n"
                "STR     R3, [R4]\n"
"loc_FF956BC0:\n"
                "LDR     R3, =0x6EF18\n"
                "LDR     R0, =0x6EEB4\n"
                "LDR     R2, [R3]\n"
                "LDR     R12, =0x6EE9C\n"
                "LDR     R1, [R0]\n"
                "ADD     R3, R2, R2,LSL#2\n"
                "ADD     R2, R2, R3,LSL#1\n"
                "LDR     R0, [R12]\n"
                "RSB     R1, R2, R1\n"
                "CMP     R0, R1\n"
                "BLS     loc_FF956C10\n"
                "LDR     R4, =0x6EF00\n"
                "LDR     R1, [R4]\n"
                "CMP     R1, #0\n"
                "BNE     loc_FF956C10\n"
                "MOV     R0, #0x3140\n"
                "ADD     R0, R0, #8\n"
                "BL      sub_FF96E3EC\n"
                "MOV     R3, #1\n"
                "STR     R3, [R4]\n"
"loc_FF956C10:\n"
                "LDR     R3, =0x6EEF0\n"
                "LDR     R12, =0x6EEE4\n"
                "LDMIA   R3, {R1,R2}\n"
                "LDR     R0, [R12]\n"
                "MOV     R4, #0\n"
                "MOV     R3, #0x18\n"
                "ADDS    R1, R1, R0\n"
                "ADC     R2, R2, #0\n"
                "ADDS    R1, R1, R3\n"
                "ADC     R2, R2, R4\n"
                "CMP     R2, #0\n"
                "BHI     loc_FF956C4C\n"
                "BNE     loc_FF956C54\n"
                "CMP     R1, #0x40000000\n"
          //    "BLS     loc_FF956C54\n"    //-
                "B       loc_FF956C54\n"    //+
"loc_FF956C4C:\n"
                "MOV     R0, #0x80000007\n"
                "B       loc_FF956C58\n"
"loc_FF956C54:\n"
                "MOV     R0, #0\n"
"loc_FF956C58:\n"
                "ADD     SP, SP, #0x14\n"
                "LDMFD   SP!, {R4-R11,PC}\n"
 );
}


void __attribute__((naked,noinline)) sub_FF955B60_my(){
 asm volatile(
                "CMP     R2, #1\n"
                "STMFD   SP!, {R4-R7,LR}\n"
                "MOV     R7, R0\n"
                "MOV     R6, R1\n"
                "MOVEQ   R3, #0x79\n"
                "STREQ   R3, [R6]\n"
                "LDMEQFD SP!, {R4-R7,PC}\n"
                "LDR     R12, =0x6EC00\n"
                "LDR     R0, [R12]\n"
                "LDR     R3, =0x6EC08\n"
                "CMP     R0, #0\n"
                "LDR     R1, [R3]\n"
                "BEQ     loc_FF955BA8\n"
                "LDR     R2, =0x6EC0C\n"
                "LDR     R3, [R2]\n"
                "CMP     R3, #1\n"
                "BNE     loc_FF955BBC\n"
                "B       loc_FF955BAC\n"
"loc_FF955BA8:\n"
                "LDR     R2, =0x6EC0C\n"
"loc_FF955BAC:\n"
                "MOV     R3, #0\n"
                "STR     R3, [R2]\n"
                "STR     R7, [R12]\n"
                "B       loc_FF955C74\n"
"loc_FF955BBC:\n"
                "LDR     R2, =0x6EC04\n"
                "LDR     R3, [R2]\n"
                "LDR     R5, =table1\n"          //*
                "ADD     R3, R3, R3,LSL#1\n"
                "MOV     LR, R3,LSL#2\n"
                "LDR     R2, [R5,LR]\n"
                "LDR     R4, =table2\n"          //*
                "RSB     R12, R2, R0\n"
                "LDR     R3, [R4,LR]\n"
                "CMP     R12, #0\n"
                "RSB     R0, R3, R0\n"
                "BLE     loc_FF955C20\n"
                "ADD     R3, R5, #4\n"
                "LDR     R2, [R3,LR]\n"
                "CMP     R2, R12\n"
                "ADDGE   R1, R1, #1\n"
                "BGE     loc_FF955C14\n"
                "ADD     R3, R5, #8\n"
                "LDR     R2, [R3,LR]\n"
                "CMP     R2, R12\n"
                "ADDGE   R1, R1, #2\n"
                "ADDLT   R1, R1, #3\n"
"loc_FF955C14:\n"
             // "CMP     R1, #0xE\n"       //-
             // "MOVGE   R1, #0xE\n"       //-
                "CMP     R1, #0x1A\n"      //+      
                "MOVGE   R1, #0x1A\n"      //+      
                "B       loc_FF955C58\n"
"loc_FF955C20:\n"
                "CMP     R0, #0\n"
                "BGE     loc_FF955C58\n"
                "ADD     R3, R4, #4\n"
                "LDR     R2, [R3,LR]\n"
                "CMP     R2, R0\n"
                "SUBLE   R1, R1, #1\n"
                "BLE     loc_FF955C50\n"
                "ADD     R3, R4, #8\n"
                "LDR     R2, [R3,LR]\n"
                "CMP     R2, R0\n"
                "SUBLE   R1, R1, #2\n"
                "SUBGT   R1, R1, #3\n"
"loc_FF955C50:\n"
                "CMP     R1, #0\n"
                "MOVLT   R1, #0\n"
"loc_FF955C58:\n"
                "LDR     R0, =0x6EC08\n"
                "LDR     R3, [R0]\n"
                "CMP     R1, R3\n"
                "LDRNE   R2, =0x6EC0C\n"
                "MOVNE   R3, #1\n"
                "STRNE   R1, [R0]\n"
                "STRNE   R3, [R2]\n"
"loc_FF955C74:\n"
                "LDR     R3, =0x6EC08\n"
           //   "LDR     R1, =0x6134\n"  //-
                "LDR     R1, =video_mode\n"  //+
                "LDR     R0, [R3]\n"
                "LDR     R2, =CompressionRateTable\n"   //*
                "LDR     R12, [R1]\n"
                "LDR     R12, [R12]\n"                  //+
                "LDR     LR, [R2,R0,LSL#2]\n"
                "LDR     R3, =0x6EC00\n"
                "CMP     R12, #1\n"
                "STR     R7, [R3]\n"
                "STR     LR, [R6]\n"
           //   "MOVEQ   R3, #0xB\n"   //-
                "LDREQ   R3, =video_quality\n"   //+     
                "LDREQ   R3, [R3]\n"   //+     
                "LDREQ   R3, [R3]\n"   //+     
                "STREQ   R3, [R6]\n"
                "LDMFD   SP!, {R4-R7,PC}\n"
 );
}
