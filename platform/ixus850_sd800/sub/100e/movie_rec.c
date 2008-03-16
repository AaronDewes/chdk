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

// FF98B3AC task_MovieRecord
void __attribute__((naked,noinline)) movie_record_task(){
 asm volatile(
                 "STMFD   SP!, {R4,R5,LR}\n"
                 "SUB     SP, SP, #4\n"
                 "MOV     R5, SP\n"
                 "MOV     R4, #0\n"
 "loc_FF98B3BC:\n"
                 "LDR     R3, =0x8BB14\n"
                 "MOV     R2, #0\n"
                 "LDR     R0, [R3]\n"
                 "MOV     R1, R5\n"
                 "BL      sub_FF98B3CC\n" //ReceiveMessageQueue
                 "LDR     R3, =0x8BBE8\n"
                 "LDR     R2, [R3]\n"
                 "CMP     R2, #0\n"
                 "BNE     loc_FF98B468\n"
                 "LDR     R1, [SP]\n"
                 "LDR     R3, [R1]\n"
                 "SUB     R3, R3, #2\n"
                 "MOV     R0, R1\n"
                 "CMP     R3, #9\n"
                 "LDRLS   PC, [PC,R3,LSL#2]\n"
                 "B       loc_FF98B46C\n"
                 ".long loc_FF98B42C\n" // jump table for switch statement
                 ".long loc_FF98B444\n"
                 ".long loc_FF98B44C\n"
                 ".long loc_FF98B454\n"
                 ".long loc_FF98B434\n"
                 ".long loc_FF98B45C\n"
                 ".long loc_FF98B43C\n"
                 ".long loc_FF98B46C\n"
                 ".long loc_FF98B464\n"
                 ".long loc_FF98B424\n"
"loc_FF98B424:\n"
                 "BL      sub_FF98B4D8\n"
                 "BL      unlock_optical_zoom\n"
                 "B       loc_FF98B468\n"
 "loc_FF98B42C:\n"
                 "BL      sub_FF98B6BC\n"
                 "B       loc_FF98B468\n"
 "loc_FF98B434:\n"
                 "BL      sub_FF98BB60_my\n"  //--------------->
                 "B       loc_FF98B468\n"
 "loc_FF98B43C:\n"
                 "BL      sub_FF98C24C\n"
                 "B       loc_FF98B468\n"
 "loc_FF98B444:\n"
                 "BL      sub_FF98BE30\n"
                 "B       loc_FF98B468\n"
 "loc_FF98B44C:\n"
                 "BL      sub_FF98C3E8\n"
                 "B       loc_FF98B468\n"
 "loc_FF98B454:\n"
                 "BL      sub_FF98C5C4\n"
                 "B       loc_FF98B468\n"
 "loc_FF98B45C:\n"
                 "BL      sub_FF98C2D4\n"
                 "B       loc_FF98B468\n"
 "loc_FF98B464:\n"
                 "BL      sub_FF98BE80\n"
 "loc_FF98B468:\n"
                 "LDR     R1, [SP]\n"
 "loc_FF98B46C:\n"
                 "LDR     R3, =0x8BB18\n"
                 "STR     R4, [R1]\n"
                 "LDR     R0, [R3]\n"
                 "MOV     R2, R4\n"
                 "BL      sub_FF82195C\n" //PostMessageQueue
                 "B       loc_FF98B3BC\n"

 );
}

void __attribute__((naked,noinline)) sub_FF98BB60_my(){
 asm volatile(
                 "STMFD   SP!, {R4-R11,LR}\n"
                 "LDR     R5, =0x8BC00\n"
                 "SUB     SP, SP, #0x34\n"
                 "LDR     R3, [R5]\n"
                 "MOV     R2, #0\n"
                 "CMP     R3, #3\n"
                 "MOV     R4, R0\n"
                 "STR     R2, [SP,#0x24]\n"
                 "STR     R2, [SP,#0x2C]\n"
                 "MOVEQ   R3, #4\n"
                 "STREQ   R3, [R5]\n"
                 "LDR     R3, =0x8BC9C\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R3]\n"
                 "LDR     R2, [R5]\n"
                 "CMP     R2, #4\n"
                 "BNE     loc_FF98BD58\n"
                 "ADD     R0, SP, #0x30\n"
                 "ADD     R1, SP, #0x2C\n"
                 "ADD     R2, SP, #0x28\n"
                 "ADD     R3, SP, #0x24\n"
                 "BL      sub_FF98D584_my\n" // ---------------->
                 "CMP     R0, #0\n"
                 "BNE     loc_FF98BBE8\n"
                 "LDR     R3, =0x8BBF0\n"
                 "LDR     R2, [R3]\n"
                 "CMP     R2, #1\n"
                 "BNE     loc_FF98BBFC\n"
                 "LDR     R2, =0x8BC2C\n"
                 "LDR     R1, =0x8BC04\n"
                 "LDR     R12, [R2]\n"
                 "LDR     R3, [R1]\n"
                 "CMP     R12, R3\n"
                 "BCC     loc_FF98BBFC\n"
 "loc_FF98BBE8:\n"
                 "BL      sub_FF98BDA8\n"
                 "BL      sub_FF98C20C\n"
                 "MOV     R3, #5\n"
                 "STR     R3, [R5]\n"
                 "B       loc_FF98BD58\n"
 "loc_FF98BBFC:\n"
                 "LDR     R8, [SP,#0x2C]\n"
                 "CMP     R8, #0\n"
                 "BEQ     loc_FF98BCD8\n"
                 "LDR     R12, =0x8BC34\n"
                 "LDR     R9, =0x8BC40\n"
                 "LDR     R11, =0x8BBF4\n"
                 "LDR     R7, [R12]\n"
                 "ADD     R5, SP, #0x24\n"
                 "LDMIA   R5, {R5,LR}\n"
                 "LDR     R6, [R9]\n"
                 "MOV     R10, #1\n"
                 "LDMIB   R4, {R0-R2}\n"
                 "LDR     R3, [SP,#0x30]\n"
                 "ADD     R12, SP, #0x20\n"
                 "STR     R10, [R11]\n"
                 "ADD     R4, SP, #0x1C\n"
                 "STMEA   SP, {R8,LR}\n"
                 "STR     R5, [SP,#0x8]\n"
                 "STR     R12, [SP,#0xC]\n"
                 "STR     R7, [SP,#0x10]\n"
                 "STR     R6, [SP,#0x14]\n"
                 "STR     R4, [SP,#0x18]\n"
                 "BL      sub_FF8A6540\n"
                 "LDR     R3, =0x8BB0C\n"
                 "MOV     R1, #0x3E8\n"
                 "LDR     R0, [R3]\n"
                 "BL      sub_FF8220F0\n" // TakeSemaphore
                 "CMP     R0, #9\n"
                 "BNE     loc_FF98BC80\n"
                 "BL      sub_FF98DE14\n"
                 "LDR     R3, =0x8BC00\n"
                 "LDR     R0, =0xFF98BB48\n" // aJpegtimeout_4
                 "B       loc_FF98BC98\n"
 "loc_FF98BC80:\n"
                 "LDR     R4, [SP,#0x1C]\n"
                 "CMP     R4, #0\n"
                 "BEQ     loc_FF98BCA4\n"
                 "BL      sub_FF98DE14\n"
                 "LDR     R3, =0x8BC00\n"
                 "LDR     R0, =0xFF98BB54\n" // aJpegicerror_5
 "loc_FF98BC98:\n"
                 "STR     R10, [R3]\n"
                 "BL      sub_FF9A55F4\n"
                 "B       loc_FF98BD58\n"
 "loc_FF98BCA4:\n"
                 "BL      sub_FF8A669C\n"
                 "LDR     R0, [SP,#0x30]\n"
                 "LDR     R1, [SP,#0x20]\n"
                 "BL      sub_FF98DA6C\n"
                 "LDR     R12, =0x8BC28\n"
                 "LDR     R3, [R12]\n"
                 "ADD     R3, R3, #1\n"
                 "LDR     R0, [SP,#0x20]\n"
                 "MOV     R1, R9\n"
                 "MOV     R2, R4\n"
                 "STR     R3, [R12]\n"
                 "BL      sub_FF98C920_my\n"   //----------------->
                 "B       loc_FF98BCDC\n"
 "loc_FF98BCD8:\n"
                 "LDR     R11, =0x8BBF4\n"
 "loc_FF98BCDC:\n"
                 "LDR     R4, =0x8BC2C\n"
                 "LDR     R2, =0x8BC4C\n"
                 "LDR     R3, [R4]\n"
                 "LDR     R1, [R2]\n"
                 "LDR     R12, =0x8BC48\n"
                 "ADD     R3, R3, #1\n"
                 "MUL     R0, R1, R3\n"
                 "LDR     R1, [R12]\n"
                 "STR     R3, [R4]\n"
                 "BL      sub_FFB553E8\n" // __udivsi3
                 "LDR     R6, =0x8BC44\n"
                 "MOV     R4, R0\n"
                 "BL      sub_FF98DE50\n"
                 "LDR     R3, [R6]\n"
                 "CMP     R3, R4\n"
                 "BNE     loc_FF98BD30\n"
                 "LDR     R5, =0x8BBF8\n"
                 "LDR     R3, [R5]\n"
                 "CMP     R3, #1\n"
                 "BNE     loc_FF98BD50\n"
                 "B       loc_FF98BD34\n"
 "loc_FF98BD30:\n"
                 "LDR     R5, =0x8BBF8\n"
 "loc_FF98BD34:\n"
                 "LDR     R2, =0x8BC80\n"
                 "MOV     R0, R4\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R2]\n"
                 "MOV     R3, #0\n"
                 "STR     R3, [R5]\n"
                 "STR     R4, [R6]\n"
 "loc_FF98BD50:\n"
                 "MOV     R3, #0\n"
                 "STR     R3, [R11]\n"
 "loc_FF98BD58:\n"
                 "ADD     SP, SP, #0x34\n"
                 "LDMFD   SP!, {R4-R11,PC}\n"
 );
}

void __attribute__((naked,noinline)) sub_FF98D584_my(){
 asm volatile(
                 "STMFD   SP!, {R4-R11,LR}\n"
                 "LDR     R4, =0x8BFF8\n"
                 "SUB     SP, SP, #0x18\n"
                 "LDR     R12, [R4]\n"
                 "LDR     R7, =0x8C034\n"
                 "LDR     R4, =0x8C048\n"
                 "LDR     R7, [R7]\n"
                 "LDR     R5, [R4]\n"
                 "LDR     R11, =0x8BF7C\n"
                 "LDR     R4, =0x8BF94\n"
                 "ADD     R12, R12, R12,LSL#2\n"
                 "LDR     R9, =0x8C038\n"
                 "RSB     R12, R12, R12,LSL#4\n"
                 "LDR     R8, [R4]\n"
                 "LDR     R6, [R11]\n"
                 "ADD     LR, R5, R5,LSL#2\n"
                 "STR     R7, [SP]\n"
                 "MOV     R12, R12,LSL#6\n"
                 "LDR     R7, [R9]\n"
                 "ADD     R12, R12, #0x20\n"
                 "RSB     LR, LR, LR,LSL#4\n"
                 "ADD     R6, R6, #1\n"
                 "ADD     LR, R5, LR,LSL#1\n"
                 "MLA     R5, R12, R5, R7\n"
                 "LDR     R12, [SP]\n"
                 "MOV     R4, #0\n"
                 "CMP     R6, R8\n"
                 "STR     R4, [SP,#0x14]\n"
                 "STR     R0, [SP,#0x10]\n"
                 "STR     R1, [SP,#0xC]\n"
                 "STR     R2, [SP,#0x8]\n"
                 "STR     R3, [SP,#0x4]\n"
                 "ADD     R10, R12, LR,LSL#5\n"
                 "STR     R6, [R11]\n"
                 "MOV     R0, #0x80000001\n"
                 "BHI     loc_FF98DA1C\n"
                 "ADD     R0, SP, #14\n"
                 "BL      sub_FF98FBBC\n"
                 "CMP     R0, #0\n"
                 "MOV     R0, #0x80000003\n"
                 "BNE     loc_FF98DA1C\n"
                 "LDR     R0, =0x8BFF8\n"
                 "LDR     R4, [R0]\n"
                 "LDR     R0, [R11]\n"
                 "MOV     R1, R4\n"
                 "BL      __umodsi3\n"
                 "CMP     R0, #1\n"
                 "BNE     loc_FF98D8F0\n"
                 "LDR     R3, =0x8C044\n"
                 "LDR     R2, [R3]\n"
                 "CMP     R2, #0x3F000000\n"
                 "BCS     loc_FF98D668\n"
                 "ADD     R3, R4, R4,LSL#2\n"
                 "LDR     R2, [R5,#0xC]\n"
                 "RSB     R3, R3, R3,LSL#4\n"
                 "CMP     R2, R3,LSL#3\n"
                 "BNE     loc_FF98D74C\n"
 "loc_FF98D668:\n"
                 "LDR     R1, =0x8C048\n"
                 "LDR     R3, [R1]\n"
                 "CMP     R3, #4\n"
                 "MOVGT   R0, #0x80000003\n"
                 "BGT     loc_FF98DA1C\n"
                 "LDR     R3, =0x8BF60\n"
                 "LDR     R4, =0x8C020\n"
                 "LDR     R2, [R3]\n"
                 "LDR     R3, [SP,#0x14]\n"
                 "LDR     R0, [R4]\n"
                 "ADD     R1, R2, R3\n"
                 "CMP     R1, R0\n"
                 "BLS     loc_FF98D6B8\n"
                 "LDR     R2, =0x8C01C\n"
                 "LDR     R3, [R2]\n"
                 "RSB     R1, R0, R1\n"
                 "LDR     R0, =0x8BF60\n"
                 "ADD     R3, R3, R1\n"
                 "STR     R3, [R0]\n"
                 "B       loc_FF98D6C0\n"
 "loc_FF98D6B8:\n"
                 "LDR     R2, =0x8BF60\n"
                 "STR     R1, [R2]\n"
 "loc_FF98D6C0:\n"
                 "BL      sub_FF98F5D8\n"
                 "LDR     R4, =0x8C00A\n"
                 "LDR     LR, =0x8C040\n"
                 "LDR     R2, [SP,#0x14]\n"
                 "LDR     R3, [LR]\n"
                 "LDRH    R1, [R4]\n"
                 "ADD     R2, R3, R2\n"
                 "CMP     R1, #0\n"
                 "STR     R2, [LR]\n"
                 "BEQ     loc_FF98D700\n"
                 "ADD     R10, R10, #0x12C0\n"
                 "ADD     R10, R10, #0x20\n"
                 "MOV     R3, #0\n"
                 "STR     R3, [R10,#0x18]\n"
                 "STR     R2, [R10,#0x14]\n"
                 "STR     R3, [R10,#0xC]\n"
 "loc_FF98D700:\n"
                 "LDR     R2, =0x8BFF8\n"
                 "LDR     R3, [R2]\n"
                 "LDR     R12, =0x8C048\n"
                 "ADD     R3, R3, R3,LSL#2\n"
                 "LDR     R2, [R12]\n"
                 "RSB     R3, R3, R3,LSL#4\n"
                 "LDR     LR, [LR]\n"
                 "ADD     R3, R5, R3,LSL#6\n"
                 "LDR     R0, =0x8C044\n"
                 "ADD     R5, R3, #0x20\n"
                 "MOV     R1, #0\n"
                 "ADD     R2, R2, #1\n"
                 "MOV     R3, #0x18\n"
                 "STR     R3, [R0]\n"
                 "STR     R2, [R12]\n"
                 "STR     LR, [R5,#0x14]\n"
                 "STR     R1, [R5,#0x18]\n"
                 "STR     R1, [R5,#0xC]\n"
                 "B       loc_FF98D750\n"
 "loc_FF98D74C:\n"
                 "LDR     R4, =0x8C00A\n"
 "loc_FF98D750:\n"
                 "LDRH    R3, [R4]\n"
                 "CMP     R3, #0\n"
                 "BEQ     loc_FF98D8EC\n"
                 "LDR     R4, =0x8C020\n"
                 "LDR     R0, =0x8BF60\n"
                 "LDR     R3, [R4]\n"
                 "LDR     R2, [R0]\n"
                 "CMP     R3, R2\n"
                 "LDREQ   R3, =0x8C01C\n"
                 "LDREQ   R4, [R3]\n"
                 "MOVNE   R4, R2\n"
                 "LDR     R3, =0x8BF7C\n"
                 "LDR     R2, =0x8BFF8\n"
                 "LDR     R0, [R3]\n"
                 "LDR     R1, [R2]\n"
                 "BL      __udivsi3\n"
                 "LDR     R1, =0x8BFB4\n"
                 "LDR     R2, =0x8BF68\n"
                 "LDR     R3, [R1]\n"
                 "ADD     R0, R0, #1\n"
                 "AND     R0, R0, #1\n"
                 "STR     R4, [R2,R0,LSL#2]\n"
                 "ADD     R2, R4, R3\n"
                 "LDR     R3, =0x8C020\n"
                 "LDR     R1, [R3]\n"
                 "ADD     R3, R2, #8\n"
                 "CMP     R3, R1\n"
                 "BLS     loc_FF98D7E0\n"
                 "LDR     R3, =0x8C01C\n"
                 "RSB     R1, R1, R2\n"
                 "LDR     R2, [R3]\n"
                 "ADD     R1, R1, #8\n"
                 "LDR     R4, =0x8BF60\n"
                 "ADD     R2, R2, R1\n"
                 "STR     R2, [R4]\n"
                 "B       loc_FF98D7E8\n"
 "loc_FF98D7E0:\n"
                 "LDR     R0, =0x8BF60\n"
                 "STR     R3, [R0]\n"
 "loc_FF98D7E8:\n"
                 "LDR     R3, =0x8BFB4\n"
                 "LDR     R1, =0x8BFC8\n"
                 "LDR     R2, [R3]\n"
                 "LDR     R3, [R1,#4]\n"
                 "ADD     R2, R2, #0x10\n"
                 "MOV     R1, R2\n"
                 "MOV     R2, #0\n"
                 "CMP     R2, R3\n"
                 "BHI     loc_FF98D9E0\n"
                 "BNE     loc_FF98D820\n"
                 "LDR     R4, =0x8BFC8\n"
                 "LDR     R3, [R4]\n"
                 "CMP     R1, R3\n"
                 "BHI     loc_FF98D9E0\n"
 "loc_FF98D820:\n"
                 "LDR     R3, =0x8BFB4\n"
                 "LDR     R0, =0x8BFD0\n"
                 "LDR     R11, [R3]\n"
                 "LDR     LR, =0x8BFC8\n"
                 "LDMIA   R0, {R7,R8}\n"
                 "MOV     R3, R11\n"
                 "MOV     R4, #0\n"
                 "LDMIA   LR, {R5,R6}\n"
                 "ADDS    R7, R7, R3\n"
                 "LDR     R2, =0x8BF7C\n"
                 "LDR     R1, =0x8C044\n"
                 "ADC     R8, R8, R4\n"
                 "SUBS    R5, R5, R3\n"
                 "SBC     R6, R6, R4\n"
                 //"MOVL    R4, 0xFFFFFFFF\n"
                 "MOV     R4,#-1\n"
                 //"MOVL    R3, 0xFFFFFFF0\n"
                 "MOV     R3,#-16\n"
                 "ADDS    R5, R5, R3\n"
                 "LDR     R0, [R1]\n"
                 "LDR     R12, [R2]\n"
                 "MOV     R2, #0\n"
                 "MOV     R1, #0x10\n"
                 "ADC     R6, R6, R4\n"
                 "ADDS    R7, R7, R1\n"
                 "ADC     R8, R8, R2\n"
                 "ADD     R0, R0, R11\n"
                 "LDR     R2, =0x8BFD0\n"
                 "LDR     R3, =0x8C044\n"
                 "ADD     R0, R0, #0x10\n"
                 "CMP     R12, #1\n"
                 "STMIA   LR, {R5,R6}\n"
                 "STR     R0, [R3]\n"
                 "STMIA   R2, {R7,R8}\n"
                 "BEQ     loc_FF98D8F0\n"
                 "LDR     LR, =0x8C040\n"
                 "LDR     R3, [R10,#0x14]\n"
                 "LDR     R1, [LR]\n"
                 "LDR     R12, [R10,#0xC]\n"
                 "RSB     R3, R3, R1\n"
                 "ADD     R3, R3, #8\n"
                 "ADD     R2, R10, #0x20\n"
                 "STR     R3, [R2,R12,LSL#3]\n"
                 "LDR     R0, [R10,#0xC]\n"
                 "ADD     R3, R10, #0x24\n"
                 "STR     R11, [R3,R0,LSL#3]\n"
                 "LDR     R2, [R10,#0xC]\n"
                 "ADD     R1, R1, R11\n"
                 "ADD     R1, R1, #8\n"
                 "ADD     R2, R2, #1\n"
                 "STR     R1, [LR]\n"
                 "STR     R2, [R10,#0xC]\n"
                 "B       loc_FF98D8F0\n"
 "loc_FF98D8EC:\n"
                 "BL      sub_FF98F02C\n"
 "loc_FF98D8F0:\n"
                 "LDR     R4, =0x8BF60\n"
                 "LDR     R2, =0x8C020\n"
                 "LDR     R1, [R4]\n"
                 "LDR     R0, [R2]\n"
                 "ADD     R3, R1, #9\n"
                 "CMP     R3, R0\n"
                 "BLS     loc_FF98D92C\n"
                 "LDR     R2, =0x8C01C\n"
                 "LDR     R3, [R2]\n"
                 "ADD     R3, R3, R1\n"
                 "RSB     R3, R0, R3\n"
                 "LDR     R4, [SP,#0x10]\n"
                 "ADD     R3, R3, #8\n"
                 "STR     R3, [R4]\n"
                 "B       loc_FF98D938\n"
 "loc_FF98D92C:\n"
                 "LDR     R0, [SP,#0x10]\n"
                 "ADD     R3, R1, #8\n"
                 "STR     R3, [R0]\n"
 "loc_FF98D938:\n"
                 "LDR     R1, [SP,#0x10]\n"
                 "LDR     R12, =0x8BFC4\n"
                 "LDR     R3, =0x8C020\n"
                 "LDR     R2, [R1]\n"
                 "LDR     R1, [R12]\n"
                 "LDR     R0, [R3]\n"
                 "ADD     R3, R2, R1\n"
                 "CMP     R3, R0\n"
                 "BLS     loc_FF98D98C\n"
                 "LDR     R4, [SP,#0xC]\n"
                 "RSB     R0, R2, R0\n"
                 "STR     R0, [R4]\n"
                 "LDR     R2, =0x8C01C\n"
                 "LDR     R3, [R12]\n"
                 "LDR     R1, [R2]\n"
                 "RSB     R3, R0, R3\n"
                 "LDR     R0, [SP,#0x8]\n"
                 "STR     R1, [R0]\n"
                 "LDR     R1, [SP,#0x4]\n"
                 "STR     R3, [R1]\n"
                 "B       loc_FF98D9A8\n"
 "loc_FF98D98C:\n"
                 "LDR     R2, [SP,#0xC]\n"
                 "STR     R1, [R2]\n"
                 "LDR     R4, [SP,#0x4]\n"
                 "MOV     R3, #0\n"
                 "STR     R3, [R4]\n"
                 "LDR     R0, [SP,#0x8]\n"
                 "STR     R3, [R0]\n"
 "loc_FF98D9A8:\n"
                 "LDR     R3, =0x8BFC4\n"
                 "LDR     R1, =0x8BFC8\n"
                 "LDR     R2, [R3]\n"
                 "LDR     R3, [R1,#4]\n"
                 "ADD     R2, R2, #0x10\n"
                 "MOV     R1, R2\n"
                 "MOV     R2, #0\n"
                 "CMP     R2, R3\n"
                 "BHI     loc_FF98D9E0\n"
                 "BNE     loc_FF98D9E8\n"
                 "LDR     R4, =0x8BFC8\n"
                 "LDR     R3, [R4]\n"
                 "CMP     R1, R3\n"
                 // "BLS     loc_FF98D9E8\n" // -
                 "B       loc_FF98D9E8\n" // +
 "loc_FF98D9E0:\n"
                 "MOV     R0, #0x80000005\n"
                 "B       loc_FF98DA1C\n"
 "loc_FF98D9E8:\n"
                 "LDR     R3, =0x8BFD0\n"
                 "LDR     R2, =0x8BFC4\n"
                 "LDMIA   R3, {R5,R6}\n"
                 "LDR     R0, [R2]\n"
                 "MOV     R2, #0\n"
                 "MOV     R1, #0x10\n"
                 "ADDS    R3, R5, R0\n"
                 "ADC     R4, R6, #0\n"
                 "ADDS    R3, R3, R1\n"
                 "ADC     R4, R4, R2\n"
                 "CMP     R4, #0\n"
                 "MOV     R0, #0\n"
                 "MOVHI   R0, #0x80000007\n"
 "loc_FF98DA1C:\n"
                 "ADD     SP, SP, #0x18\n"
                 "LDMFD   SP!, {R4-R11,PC}\n"
 );
 }

void __attribute__((naked,noinline)) sub_FF98C920_my(){
 asm volatile(
                 "CMP     R2, #1\n"
                 "STMFD   SP!, {R4-R7,LR}\n"
                 "MOV     R7, R0\n"
                 "MOV     R6, R1\n"
                 "MOVEQ   R3, #0x79\n"
                 "STREQ   R3, [R6]\n"
                 "LDMEQFD SP!, {R4-R7,PC}\n"
                 "LDR     R12, =0x8BCE0\n"
                 "LDR     R0, [R12]\n"
                 "LDR     R3, =0x8BCE8\n"
                 "CMP     R0, #0\n"
                 "LDR     R1, [R3]\n"
                 "BEQ     loc_FF98C968\n"
                 "LDR     R2, =0x8BCEC\n"
                 "LDR     R3, [R2]\n"
                 "CMP     R3, #1\n"
                 "BNE     loc_FF98C97C\n"
                 "B       loc_FF98C96C\n"
 "loc_FF98C968:\n"
                 "LDR     R2, =0x8BCEC\n"
 "loc_FF98C96C:\n"
                 "MOV     R3, #0\n"
                 "STR     R3, [R2]\n"
                 "STR     R7, [R12]\n"
                 "B       loc_FF98CA34\n"
 "loc_FF98C97C:\n"
                 "LDR     R2, =0x8BCE4\n"
                 "LDR     R3, [R2]\n"
                 "LDR     R5, =table1\n"          // + 0xFF98C790
                 "ADD     R3, R3, R3,LSL#1\n"
                 "MOV     LR, R3,LSL#2\n"
                 "LDR     R2, [R5,LR]\n"
                 "LDR     R4, =table2\n"          // + 0xFF98C7B4
                 "RSB     R12, R2, R0\n"
                 "LDR     R3, [R4,LR]\n"
                 "CMP     R12, #0\n"
                 "RSB     R0, R3, R0\n"
                 "BLE     loc_FF98C9E0\n"
                 "ADD     R3, R5, #4\n"
                 "LDR     R2, [R3,LR]\n"
                 "CMP     R2, R12\n"
                 "ADDGE   R1, R1, #1\n"
                 "BGE     loc_FF98C9D4\n"
                 "ADD     R3, R5, #8\n"
                 "LDR     R2, [R3,LR]\n"
                 "CMP     R2, R12\n"
                 "ADDGE   R1, R1, #2\n"
                 "ADDLT   R1, R1, #3\n"
 "loc_FF98C9D4:\n"
            //   "CMP     R1, #0xE\n"     // -
            //   "MOVGE   R1, #0xE\n"     // -

                 "CMP     R1, #0x1A\n"    // +      
                 "MOVGE   R1, #0x1A\n"    // +      

                 "B       loc_FF98CA18\n"
 "loc_FF98C9E0:\n"
                 "CMP     R0, #0\n"
                 "BGE     loc_FF98CA18\n"
                 "ADD     R3, R4, #4\n"
                 "LDR     R2, [R3,LR]\n"
                 "CMP     R2, R0\n"
                 "SUBLE   R1, R1, #1\n"
                 "BLE     loc_FF98CA10\n"
                 "ADD     R3, R4, #8\n"
                 "LDR     R2, [R3,LR]\n"
                 "CMP     R2, R0\n"
                 "SUBLE   R1, R1, #2\n"
                 "SUBGT   R1, R1, #3\n"
 "loc_FF98CA10:\n"
                 "CMP     R1, #0\n"
                 "MOVLT   R1, #0\n"
 "loc_FF98CA18:\n"
                 "LDR     R0, =0x8BCE8\n"
                 "LDR     R3, [R0]\n"
                 "CMP     R1, R3\n"
                 "LDRNE   R2, =0x8BCEC\n"
                 "MOVNE   R3, #1\n"
                 "STRNE   R1, [R0]\n"
                 "STRNE   R3, [R2]\n"
  "loc_FF98CA34:\n"
                 "LDR     R3, =0x8BCE8\n"
                 "LDR     R2, =CompressionRateTable\n"
                 "LDR     R0, [R3]\n"

                 "LDR     LR, [R2,R0,LSL#2]\n"

                 "LDR     R1, =video_mode\n"      // +
                 "LDR     R1, [R1]\n"             // +
                 "LDR     R1, [R1]\n"             // +
                 "CMP     R1, #1\n"               // +
                 "LDREQ   R1, =video_quality\n"   // +     
                 "LDREQ   R1, [R1]\n"             // +     
                 "LDREQ   R3, [R1]\n"             // +     

                 "STR     R7, [R3]\n"
                 "STR     LR, [R6]\n"

                 "LDR     R12, [R1]\n"
                 "LDR     R1, =0x6A58\n" // Video mode - 0=Normal, 1=HiCompressionRate

                 "CMP     R12, #1\n"

                 "MOVEQ   R3, #0xB\n"
                 "STREQ   R3, [R6]\n"
                 "LDMFD   SP!, {R4-R7,PC}\n"
 );
}
