#include "conf.h"

void change_video_tables(__attribute__ ((unused))int a, __attribute__ ((unused))int b) {}


void  set_quality(int *x){ // -17 highest; +12 lowest
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}


void __attribute__((naked,noinline)) movie_record_task(){ 
 asm volatile(
                 "STMFD   SP!, {R2-R8,LR}\n"
                 "LDR     R8, =0x3F5\n"
                 "LDR     R7, =0x2710\n"
                 "LDR     R4, =0x53F8\n"
                 "MOV     R6, #0\n"
                 "MOV     R5, #1\n"
 "loc_FF8645A4:\n"
                 "LDR     R0, [R4,#0x18]\n"
                 "MOV     R2, #0\n"
                 "ADD     R1, SP, #4\n"
                 "BL      sub_FF8274FC\n"
                 "LDR     R2, =0xFF862E3C\n"
                 "LDR     R0, [R4,#0xB0]\n"
                 "MOV     R3, R8\n"
                 "MOV     R1, R7\n"
                 "BL      sub_FF827DF8\n"
                 "LDR     R0, [R4,#0x20]\n"
                 "CMP     R0, #0\n"
                 "BNE     loc_FF8646A4\n"
                 "LDR     R0, [SP,#4]\n"
                 "LDR     R1, [R0]\n"
                 "SUB     R1, R1, #2\n"
                 "CMP     R1, #0xB\n"
                 "ADDLS   PC, PC, R1,LSL#2\n"
                 "B       loc_FF8646A4\n"
 "loc_FF8645EC:\n"
                 "B       loc_FF86464C\n"
 "loc_FF8645F0:\n"
                 "B       loc_FF864664\n"
 "loc_FF8645F4:\n"
                 "B       loc_FF864674\n"
 "loc_FF8645F8:\n"
                 "B       loc_FF86467C\n"
 "loc_FF8645FC:\n"
                 "B       loc_FF864654\n"
 "loc_FF864600:\n"
                 "B       loc_FF864684\n"
 "loc_FF864604:\n"
                 "B       loc_FF86465C\n"
 "loc_FF864608:\n"
                 "B       loc_FF8646A4\n"
 "loc_FF86460C:\n"
                 "B       loc_FF864694\n"
 "loc_FF864610:\n"
                 "B       loc_FF86469C\n"
 "loc_FF864614:\n"
                 "B       loc_FF86468C\n"
 "loc_FF864618:\n"
                 "B       loc_FF86461C\n"
 "loc_FF86461C:\n"
                 "LDR     R0, =0xFF864234\n"
                 "STR     R6, [R4,#0x34]\n"
                 "STR     R0, [R4,#0x9C]\n"
                 "LDR     R0, =0xFF863350\n"
                 "LDR     R2, =0xFF863354\n"
                 "STR     R0, [R4,#0xA0]\n"
                 "LDR     R0, =0xFF863464\n"
                 "LDR     R1, =0x1BA0C\n"
                 "STR     R6, [R4,#0x24]\n"
                 "BL      sub_FF83C1F4\n"
                 "STR     R5, [R4,#0x38]\n"
                 "B       loc_FF8646A4\n"
 "loc_FF86464C:\n"
                 "BL      sub_FF86435C\n"
                 "B       loc_FF8646A4\n"
 "loc_FF864654:\n"
                 "BL      sub_FF863E8C_my\n"  //--------------->
                 "B       loc_FF8646A4\n"
 "loc_FF86465C:\n"
                 "BL      sub_FF864A20\n"
                 "B       loc_FF8646A4\n"
 "loc_FF864664:\n"
                 "LDR     R0, [R4,#0x38]\n"
                 "CMP     R0, #5\n"
                 "STRNE   R5, [R4,#0x28]\n"
                 "B       loc_FF8646A4\n"
 "loc_FF864674:\n"
                 "BL      sub_FF863BD4\n"
                 "B       loc_FF8646A4\n"
 "loc_FF86467C:\n"
                 "BL      sub_FF8638C8\n"
                 "B       loc_FF8646A4\n"
 "loc_FF864684:\n"
                 "BL      sub_FF8632DC\n"
                 "B       loc_FF8646A4\n"
 "loc_FF86468C:\n"
                 "BL      sub_FF864988\n"
                 "B       loc_FF8646A4\n"
 "loc_FF864694:\n"
                 "BL      sub_FF86483C\n"
                 "B       loc_FF8646A4\n"
 "loc_FF86469C:\n"
                 "BL      sub_FF8637B8\n"
                 "STR     R5, [R4,#0xD8]\n"
 "loc_FF8646A4:\n"
                 "LDR     R1, [SP,#4]\n"
                 "MOV     R3, #0x430\n"
                 "STR     R6, [R1]\n"
                 "STR     R3, [SP]\n"
                 "LDR     R3, =0xFF862E3C\n"
                 "MOV     R2, R7\n"
                 "LDR     R0, [R4,#0x1C]\n"
                 "BL      sub_FF827E50\n"
                 "LDR     R0, [R4,#0xB0]\n"
                 "BL      sub_FF8279E8\n"
                 "B       loc_FF8645A4\n"
 );
}


void __attribute__((naked,noinline)) sub_FF863E8C_my(){ 
 asm volatile(
                 "STMFD   SP!, {R4-R8,LR}\n"
                 "SUB     SP, SP, #0x48\n"
                 "MOV     R7, #0\n"
                 "LDR     R6, =0x53F8\n"
                 "MOV     R4, R0\n"
                 "STR     R7, [SP,#0x38]\n"
                 "STR     R7, [SP,#0x30]\n"
                 "LDR     R0, [R6,#0x38]\n"
                 "CMP     R0, #3\n"
                 "MOVEQ   R0, #4\n"
                 "STREQ   R0, [R6,#0x38]\n"
                 "LDR     R0, [R6,#0x9C]\n"
                 "BLX     R0\n"
                 "LDR     R0, [R6,#0x38]\n"
                 "CMP     R0, #4\n"
                 "BNE     loc_FF863F90\n"
                 "ADD     R3, SP, #0x30\n"
                 "ADD     R2, SP, #0x34\n"
                 "ADD     R1, SP, #0x38\n"
                 "ADD     R0, SP, #0x3C\n"
                 "BL      sub_FF9462C4\n"
                 "CMP     R0, #0\n"
                 "MOV     R5, #1\n"
                 "BNE     loc_FF863F08\n"
                 "LDR     R1, [R6,#0x28]\n"
                 "CMP     R1, #1\n"
                 "BNE     loc_FF863FA4\n"
                 "LDR     R1, [R6,#0x4C]\n"
                 "LDR     R2, [R6,#0x3C]\n"
                 "CMP     R1, R2\n"
                 "BCC     loc_FF863FA4\n"
 "loc_FF863F08:\n"
                 "BL      sub_FF8634A4\n"
                 "BL      sub_FF864828\n"
                 "LDR     R0, [R4,#0x14]\n"
                 "LDR     R1, [R4,#0x18]\n"
                 "ADD     R3, SP, #0x40\n"
                 "MVN     R2, #1\n"
                 "ADD     R7, SP, #0x18\n"
                 "STMIA   R7, {R0-R3}\n"
                 "LDR     R2, [R6,#0x64]\n"
                 "LDR     R3, [R6,#0x68]\n"
                 "MOV     R0, #0\n"
                 "ADD     R1, SP, #0x44\n"
                 "ADD     R7, SP, #8\n"
                 "STMIA   R7, {R0-R3}\n"
                 "MOV     R3, #0\n"
                 "MOV     R2, #0x40\n"
                 "STRD    R2, [SP]\n"
                 "LDMIB   R4, {R0,R1}\n"
                 "LDR     R3, =0x1BA98\n"
                 "MOV     R2, R8\n"
                 "BL      sub_FF8FF5B8\n"
                 "LDR     R0, [R6,#0x10]\n"
                 "MOV     R1, #0x3E8\n"
                 "BL      sub_FF827918\n"
                 "CMP     R0, #9\n"
                 "BEQ     loc_FF864028\n"
                 "LDR     R0, [SP,#0x40]\n"
                 "CMP     R0, #0\n"
                 "BNE     loc_FF864044\n"
                 "MOV     R0, #1\n"
                 "BL      sub_FF8FF660\n"
                 "BL      sub_FF8FF69C\n"
                 "MOV     R0, #5\n"
                 "STR     R0, [R6,#0x38]\n"
 "loc_FF863F90:\n"
                 "ADD     SP, SP, #0x48\n"
                 "LDMFD   SP!, {R4-R8,PC}\n"
 "loc_FF863F98:\n"
                 "BL      sub_FF88120C\n"
                 "MOV     R0, #1\n"
                 "B       loc_FF8640F4\n"
 "loc_FF863FA4:\n"
                 "LDR     R12, [SP,#0x38]\n"
                 "CMP     R12, #0\n"
                 "BEQ     loc_FF8641DC\n"
                 "STR     R5, [R6,#0x2C]\n"
                 "LDR     R0, [R6,#0x4C]\n"
                 "LDR     R8, [R4,#0xC]\n"
                 "CMP     R0, #0\n"
                 "LDRNE   LR, [SP,#0x3C]\n"
                 "BNE     loc_FF864070\n"
                 "LDR     R0, [R4,#0x14]\n"
                 "LDR     R1, [R4,#0x18]\n"
                 "ADD     R3, SP, #0x40\n"
                 "MVN     R2, #0\n"
                 "ADD     LR, SP, #0x18\n"
                 "STMIA   LR, {R0-R3}\n"
                 "LDR     R0, [SP,#0x30]\n"
                 "LDR     R2, [R6,#0x64]\n"
                 "LDR     R3, [R6,#0x68]\n"
                 "ADD     R1, SP, #0x44\n"
                 "ADD     LR, SP, #8\n"
                 "STMIA   LR, {R0-R3}\n"
                 "LDR     R3, [SP,#0x34]\n"
                 "STR     R12, [SP]\n"
                 "STR     R3, [SP,#4]\n"
                 "LDMIB   R4, {R0,R1}\n"
                 "LDR     R3, [SP,#0x3C]\n"
                 "MOV     R2, R8\n"
                 "BL      sub_FF8FF5B8\n"
                 "LDR     R0, [R6,#0x10]\n"
                 "MOV     R1, #0x3E8\n"
                 "BL      sub_FF827918\n"
                 "CMP     R0, #9\n"
                 "BNE     loc_FF864038\n"
 "loc_FF864028:\n"
                 "BL      sub_FF946790\n"
                 "MOV     R0, #0x90000\n"
                 "STR     R5, [R6,#0x38]\n"
                 "B       loc_FF863F98\n"
 "loc_FF864038:\n"
                 "LDR     R0, [SP,#0x40]\n"
                 "CMP     R0, #0\n"
                 "BEQ     loc_FF864054\n"
 "loc_FF864044:\n"
                 "BL      sub_FF946790\n"
                 "MOV     R0, #0xA0000\n"
                 "STR     R5, [R6,#0x38]\n"
                 "B       loc_FF863F98\n"
 "loc_FF864054:\n"
                 "MOV     R0, #1\n"
                 "BL      sub_FF8FF660\n"
                 "LDR     R0, [SP,#0x44]\n"
                 "LDR     R1, [SP,#0x3C]\n"
                 "ADD     LR, R1, R0\n"
                 "LDR     R1, [SP,#0x38]\n"
                 "SUB     R12, R1, R0\n"
 "loc_FF864070:\n"
                 "LDR     R2, [R6,#0x48]\n"
                 "LDR     R0, [R4,#0x14]\n"
                 "LDR     R1, [R4,#0x18]\n"
                 "ADD     R3, SP, #0x40\n"
                 "STR     R1, [SP,#0x1C]\n"
                 "STR     R0, [SP,#0x18]\n"
                 "STR     R3, [SP,#0x24]\n"
                 "STR     R2, [SP,#0x20]\n"
                 "LDR     R2, [R6,#0x64]\n"
                 "LDR     R3, [R6,#0x68]\n"
                 "ADD     R1, SP, #0x44\n"
                 "STR     R1, [SP,#0xC]\n"
                 "STR     R3, [SP,#0x14]\n"
                 "LDR     R3, [SP,#0x34]\n"
                 "LDR     R0, [SP,#0x30]\n"
                 "STR     R2, [SP,#0x10]\n"
                 "STR     R3, [SP,#4]\n"
                 "STR     R12, [SP]\n"
                 "STR     R0, [SP,#8]\n"
                 "LDMIB   R4, {R0,R1}\n"
                 "MOV     R3, LR\n"
                 "MOV     R2, R8\n"
                 "BL      sub_FF8FF5B8\n"
                 "LDR     R0, [R6,#0x10]\n"
                 "MOV     R1, #0x3E8\n"
                 "BL      sub_FF827918\n"
                 "CMP     R0, #9\n"
                 "BNE     loc_FF8640FC\n"
                 "BL      sub_FF946790\n"
                 "MOV     R0, #0x90000\n"
                 "STR     R5, [R6,#0x38]\n"
                 "BL      sub_FF88120C\n"
                 "MOV     R0, #0\n"
 "loc_FF8640F4:\n"
                 "BL      sub_FF8FF660\n"
                 "B       loc_FF863F90\n"
 "loc_FF8640FC:\n"
                 "LDR     R0, [SP,#0x40]\n"
                 "CMP     R0, #0\n"
                 "BEQ     loc_FF86411C\n"
                 "BL      sub_FF946790\n"
                 "MOV     R0, #0xA0000\n"
                 "STR     R5, [R6,#0x38]\n"
                 "BL      sub_FF88120C\n"
                 "B       loc_FF863F90\n"
 "loc_FF86411C:\n"
                 "MOV     R0, #0\n"
                 "BL      sub_FF8FF660\n"
                 "LDR     R0, [R6,#0xD8]\n"
                 "CMP     R0, #1\n"
                 "BNE     loc_FF8641AC\n"
                 "LDR     R0, [R6,#0x48]\n"
                 "MOV     R1, #0xF\n"
                 "BL      sub_FFB02524\n"
                 "MOVS    R4, R1\n"
                 "STREQ   R7, [R6,#0xD8]\n"
                 "BEQ     loc_FF8641AC\n"
                 "LDR     R5, [SP,#0x3C]\n"
                 "MOV     R2, #4\n"
                 "ADD     R0, SP, #0x2C\n"
                 "ADD     R1, R5, #4\n"
                 "BL      sub_FFB00004\n"
                 "LDR     R0, [SP,#0x2C]\n"
                 "MOV     R1, R0,LSR#24\n"
                 "AND     R2, R0, #0xFF0000\n"
                 "ORR     R1, R1, R2,LSR#8\n"
                 "AND     R2, R0, #0xFF00\n"
                 "ORR     R1, R1, R2,LSL#8\n"
                 "ORR     R0, R1, R0,LSL#24\n"
                 "BIC     R0, R0, #0x1E000\n"
                 "ORR     R0, R0, R4,LSL#13\n"
                 "MOV     R1, R0,LSR#24\n"
                 "AND     R2, R0, #0xFF0000\n"
                 "ORR     R1, R1, R2,LSR#8\n"
                 "AND     R2, R0, #0xFF00\n"
                 "ORR     R1, R1, R2,LSL#8\n"
                 "ORR     R0, R1, R0,LSL#24\n"
                 "STR     R0, [SP,#0x2C]\n"
                 "ADD     R0, R5, #4\n"
                 "ADD     R1, SP, #0x2C\n"
                 "MOV     R2, #4\n"
                 "BL      sub_FFB00004\n"
 "loc_FF8641AC:\n"
                 "LDR     R0, [SP,#0x3C]\n"
                 "LDR     R1, [SP,#0x44]\n"
                 "BL      sub_FF9464EC\n"
                 "LDR     R0, [R6,#0x48]\n"
                 "LDR     R3, =0x5460\n"    // ->----
                 "ADD     R1, R0, #1\n"     //       |
                 "STR     R1, [R6,#0x48]\n" //       |
                 "STR     R3, [SP]\n"       //       |
                 "LDR     R0, [SP,#0x44]\n" //       |
                 "SUB     R3, R3, #4\n"     // ->----|
                 "MOV     R2, #0xF\n"       //       |
                 "BL      sub_FF9446E8\n"   //       |
                                            //       |
                 "LDR     R0, =0x5460-4\n"  // -<----     // +
                 "BL      set_quality\n"                  // +


 "loc_FF8641DC:\n"
                 "LDR     R0, [R6,#0x4C]\n"
                 "ADD     R0, R0, #1\n"
                 "STR     R0, [R6,#0x4C]\n"
                 "LDR     R1, [R6,#0x74]\n"
                 "MUL     R0, R1, R0\n"
                 "LDR     R1, [R6,#0x70]\n"
                 "BL      sub_FFB02524\n"
                 "MOV     R4, R0\n"
                 "BL      sub_FF9467C8\n"
                 "LDR     R1, [R6,#0x6C]\n"
                 "CMP     R1, R4\n"
                 "BNE     loc_FF864218\n"
                 "LDR     R0, [R6,#0x30]\n"
                 "CMP     R0, #1\n"
                 "BNE     loc_FF86422C\n"
 "loc_FF864218:\n"
                 "LDR     R1, [R6,#0x80]\n"
                 "MOV     R0, R4\n"
                 "BLX     R1\n"
                 "STR     R4, [R6,#0x6C]\n"
                 "STR     R7, [R6,#0x30]\n"
 "loc_FF86422C:\n"
                 "STR     R7, [R6,#0x2C]\n"
                 "B       loc_FF863F90\n"

 );
}

