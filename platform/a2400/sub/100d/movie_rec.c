#include "conf.h"

void change_video_tables(__attribute__ ((unused))int a, __attribute__ ((unused))int b){}

void  set_quality(int *x){ // -17 highest; +12 lowest
    if (conf.video_mode) 
        *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

//** movie_record_task  @ 0xFF95F834 

void __attribute__((naked,noinline)) movie_record_task(  ) { 
asm volatile (
      "STMFD   SP!, {R2-R10,LR}\n"
      "LDR     R6, =0xFF95ECCC\n"
      "LDR     R7, =0xFF95F1F8\n" //This function was used to take values for set_quality -->
      "LDR     R4, =0x6418\n"
      "LDR     R9, =0x69B\n"
      "LDR     R10, =0x2710\n"
      "MOV     R8, #1\n"
      "MOV     R5, #0\n"
"loc_FF95F854:\n"
      "LDR     R0, [R4, #0x24]\n"
      "MOV     R2, #0\n"
      "ADD     R1, SP, #4\n"
      "BL      sub_003F7218\n"
      "LDR     R0, [R4, #0x2C]\n"
      "CMP     R0, #0\n"
      "LDRNE   R0, [R4, #0xC]\n"
      "CMPNE   R0, #2\n"
      "LDRNE   R0, [R4, #0x44]\n"
      "CMPNE   R0, #6\n"
      "BNE     loc_FF95F978\n"
      "LDR     R0, [SP, #4]\n"
      "LDR     R1, [R0]\n"
      "SUB     R1, R1, #2\n"
      "CMP     R1, #0xB\n"
      "ADDCC   PC, PC, R1, LSL #2\n"
      "B       loc_FF95F978\n"
      "B       loc_FF95F928\n" //(01)
      "B       loc_FF95F94C\n" //(02)
      "B       loc_FF95F95C\n" //(03)
      "B       loc_FF95F964\n" //(04)
      "B       loc_FF95F930\n" //(05)
      "B       loc_FF95F96C\n" //(06)
      "B       loc_FF95F93C\n" //(07)
      "B       loc_FF95F978\n" //(08)
      "B       loc_FF95F974\n" //(09)
      "B       loc_FF95F8F4\n" //(10)
      "B       loc_FF95F8C4\n" //(11)
"loc_FF95F8C4:\n" //Jump Table entry 11
      "STR     R5, [R4, #0x40]\n"
      "STR     R5, [R4, #0x30]\n"
      "STR     R5, [R4, #0x34]\n"
      "STRH    R5, [R4, #6]\n"
      "STR     R6, [R4, #0xB4]\n"
      "STR     R7, [R4, #0xD0]\n"
      "LDR     R0, [R4, #0xC]\n"
      "ADD     R0, R0, #1\n"
      "STR     R0, [R4, #0xC]\n"
      "MOV     R0, #6\n"
      "STR     R0, [R4, #0x44]\n"
      "B       loc_FF95F914\n"
"loc_FF95F8F4:\n" //Jump Table entry 10
      "STR     R5, [R4, #0x40]\n"
      "STR     R5, [R4, #0x30]\n"
      "STR     R6, [R4, #0xB4]\n"
      "STR     R7, [R4, #0xD0]\n"
      "LDR     R0, [R4, #0xC]\n"
      "ADD     R0, R0, #1\n"
      "STR     R0, [R4, #0xC]\n"
      "STR     R8, [R4, #0x44]\n"
"loc_FF95F914:\n"
      "LDR     R2, =0xFF95E42C\n"
      "LDR     R1, =0xAB25C\n"
      "LDR     R0, =0xFF95E540\n"
      "BL      sub_FF84AF90\n"
      "B       loc_FF95F978\n"
"loc_FF95F928:\n" //Jump Table entry 01
      "BL      unlock_optical_zoom \n" //added
      "BL      sub_FF95EE2C\n"
      "B       loc_FF95F978\n"
"loc_FF95F930:\n"  //Jump Table entry 05
      "LDR     R1, [R4, #0xD0]\n"
      "BLX     R1\n"
//begin patch
      "LDR	   R0, =0x649C \n"		// added, 0x64A0-0x4 taken from  ""loc_FF95F71C:" see commented function below.
      "BL      set_quality \n"		// added
      "BL      mute_on_zoom\n"      // added
//end patch 
      "B       loc_FF95F978\n"
"loc_FF95F93C:\n"  //Jump Table entry 07
      "LDR     R1, [R0, #0x18]\n"
      "LDR     R0, [R0, #4]\n"
      "BL      sub_FFA6DB7C\n"
      "B       loc_FF95F978\n"
"loc_FF95F94C:\n"  //Jump Table entry 02
      "LDR     R0, [R4, #0x44]\n"
      "CMP     R0, #5\n"
      "STRNE   R8, [R4, #0x34]\n"
      "B       loc_FF95F978\n"
"loc_FF95F95C:\n"  //Jump Table entry 03
      "BL      sub_FF95E92C\n"
      "B       loc_FF95F978\n"
"loc_FF95F964:\n"  //Jump Table entry 04
      "BL      sub_FF95E58C\n"
      "B       loc_FF95F978\n"
"loc_FF95F96C:\n"  //Jump Table entry 06
      "BL      sub_FF95E3B8\n"
      "B       loc_FF95F978\n"
"loc_FF95F974:\n"  //Jump Table entry 09
      "BL      sub_FF95FE50\n"
"loc_FF95F978:\n"
      "LDR     R1, [SP, #4]\n"
      "LDR     R3, =0xFF95E118\n"
      "STR     R5, [R1]\n"
      "STR     R9, [SP]\n"
      "LDR     R0, [R4, #0x28]\n"
      "MOV     R2, R10\n"
      "BL      sub_003F7B90\n"
      "B       loc_FF95F854\n"
	);
}

//This function was used to take values for set_quality
//** sub_FF95F1F8_my  @ 0xFF95F1F8
/*
void __attribute__((naked,noinline)) sub_FF95F1F8_my(  ) {
asm volatile (
      "STMFD   SP!, {R4-R11,LR}\n"
      "SUB     SP, SP, #0x64\n"
      "MOV     R9, #0\n"
      "LDR     R6, =0x6418\n"
      "STR     R9, [SP, #0x54]\n"
      "STR     R9, [SP, #0x4C]\n"
      "STR     R9, [R6, #0xB8]\n"
      "STR     R9, [R6, #0xBC]\n"
      "STR     R9, [R6, #0xC0]\n"
      "STR     R9, [R6, #0xC4]\n"
      "MOV     R4, R0\n"
      "STR     R9, [R6, #0xC8]\n"
      "LDR     R0, [R6, #0x44]\n"
      "MOV     R11, #4\n"
      "CMP     R0, #3\n"
      "STREQ   R11, [R6, #0x44]\n"
      "LDR     R0, [R6, #0xB4]\n"
      "MOV     R8, R9\n"
      "MOV     R5, #1\n"
      "MOV     R7, R9\n"
      "BLX     R0\n"
      "LDR     R0, [R6, #0x44]\n"
      "CMP     R0, #6\n"
      "BEQ     loc_FF95F26C\n"
      "LDR     R1, [R6, #0xC]\n"
      "CMP     R1, #2\n"
      "BNE     loc_FF95F294\n"
      "CMP     R0, #5\n"
      "BEQ     loc_FF95F2A4\n"
"loc_FF95F26C:\n"
      "LDR     R2, =0xFF95F0CC\n"
      "LDR     R1, =0xFF95F130\n"
      "LDR     R0, =0xFF95F194\n"
      "MOV     R7, #1\n"
      "ADD     R3, SP, #0x30\n"
      "BL      sub_FF84BAD8\n"
      "LDR     R0, [R6, #0x44]\n"
      "CMP     R0, #4\n"
      "MOVNE   R5, #0\n"
      "B       loc_FF95F2B4\n"
"loc_FF95F294:\n"
      "CMP     R0, #4\n"
      "BEQ     loc_FF95F2B4\n"
      "CMP     R1, #2\n"
      "BNE     loc_FF95F2AC\n"
"loc_FF95F2A4:\n"
      "MOV     R0, #0\n"
      "BL      sub_FF84BB44\n"
"loc_FF95F2AC:\n"
      "ADD     SP, SP, #0x64\n"
      "LDMFD   SP!, {R4-R11,PC}\n"
"loc_FF95F2B4:\n"
      "LDRH    R0, [R6, #6]\n"
      "CMP     R0, #3\n"
      "BNE     loc_FF95F2E8\n"
      "LDR     R0, [R6, #0xCC]\n"
      "CMP     R0, #0\n"
      "LDREQ   R1, =0x8E8\n"
      "LDREQ   R0, =0xFF95E118\n"
      "BLEQ    _DebugAssert \n"
      "LDR     R0, [R6, #0x6C]\n"
      "LDR     R1, [R6, #0xCC]\n"
      "BL      sub_003FC934\n"
      "CMP     R1, #0\n"
      "MOVNE   R5, #0\n"
"loc_FF95F2E8:\n"
      "LDR     R0, [R6, #0x44]\n"
      "CMP     R0, #6\n"
      "CMPNE   R0, #1\n"
      "CMPNE   R0, #3\n"
      "BNE     loc_FF95F32C\n"
      "CMP     R7, #1\n"
      "CMPEQ   R5, #0\n"
      "BNE     loc_FF95F32C\n"
      "BL      sub_FF84BAFC\n"
      "LDR     R0, [R6, #0x18]\n"
      "MOV     R1, #0x3E8\n"
      "BL      _TakeSemaphore \n"
      "CMP     R0, #9\n"
      "BNE     loc_FF95F798\n"
      "MOV     R0, #0x90000\n"
      "BL      sub_FF835FBC\n"
      "B       loc_FF95F2AC\n"
"loc_FF95F32C:\n"
      "CMP     R5, #1\n"
      "MOV     R10, #1\n"
      "BNE     loc_FF95F354\n"
      "ADD     R3, SP, #0x4C\n"
      "ADD     R2, SP, #0x50\n"
      "ADD     R1, SP, #0x54\n"
      "ADD     R0, SP, #0x58\n"
      "BL      sub_FFA6DC54\n"
      "MOVS    R9, R0\n"
      "BNE     loc_FF95F370\n"
"loc_FF95F354:\n"
      "LDR     R0, [R6, #0x34]\n"
      "CMP     R0, #1\n"
      "BNE     loc_FF95F4EC\n"
      "LDR     R0, [R6, #0x6C]\n"
      "LDR     R1, [R6, #0x48]\n"
      "CMP     R0, R1\n"
      "BCC     loc_FF95F4EC\n"
"loc_FF95F370:\n"
      "CMP     R9, #0x80000001\n"
      "STREQ   R11, [R6, #0x70]\n"
      "BEQ     loc_FF95F3A8\n"
      "CMP     R9, #0x80000003\n"
      "STREQ   R10, [R6, #0x70]\n"
      "BEQ     loc_FF95F3A8\n"
      "CMP     R9, #0x80000005\n"
      "MOVEQ   R0, #2\n"
      "BEQ     loc_FF95F3A4\n"
      "CMP     R9, #0x80000007\n"
      "STRNE   R8, [R6, #0x70]\n"
      "BNE     loc_FF95F3A8\n"
      "MOV     R0, #3\n"
"loc_FF95F3A4:\n"
      "STR     R0, [R6, #0x70]\n"
"loc_FF95F3A8:\n"
      "LDR     R0, [R6, #0xC]\n"
      "CMP     R0, #2\n"
      "BNE     loc_FF95F40C\n"
      "LDR     R0, =0xFF95F0C0\n"
      "MOV     R1, #0\n"
      "BL      sub_FFA39450\n"
      "LDR     R1, [R6, #0x64]\n"
      "LDR     R2, =0xAB2A8\n"
      "ADD     R3, SP, #0x5C\n"
      "ADD     R0, SP, #0x30\n"
      "STRD    R0, [SP, #0x10]\n"
      "STRD    R2, [SP, #0x18]\n"
      "LDR     R1, [R6, #0x84]\n"
      "LDR     R2, [R6, #0x88]\n"
      "MVN     R3, #1\n"
      "ADD     R0, SP, #0x60\n"
      "STMEA   SP, {R0-R3}\n"
      "MOV     R3, #0\n"
      "LDR     R0, =0xAB308\n"
      "MOV     R2, R3\n"
      "MOV     R1, #0x40\n"
      "BL      sub_FFA393A4\n"
      "B       loc_FF95F464\n"
"loc_FF95F404:\n"
      "MOV     R1, #1\n"
      "B       loc_FF95F6DC\n"
"loc_FF95F40C:\n"
      "BL      sub_FF95FF20\n"
      "LDR     R2, [R6, #0x64]\n"
      "ADD     R3, SP, #0x5C\n"
      "MVN     R1, #1\n"
      "MOV     R0, #0\n"
      "ADD     R5, SP, #0x1C\n"
      "STMIA   R5, {R0-R3}\n"
      "LDR     R3, [R4, #0x1C]\n"
      "LDR     R1, [R6, #0x84]\n"
      "LDR     R2, [R6, #0x88]\n"
      "ADD     R0, SP, #0x60\n"
      "ADD     R4, SP, #0xC\n"
      "STMIA   R4, {R0-R3}\n"
      "MOV     R3, #0\n"
      "MOV     R1, #0x40\n"
      "STMEA   SP, {R1,R3}\n"
      "MOV     R2, #0\n"
      "STR     R3, [SP, #8]\n"
      "LDR     R3, =0xAB308\n"
      "MOV     R1, R2\n"
      "MOV     R0, R2\n"
      "BL      sub_FFA38094\n"
"loc_FF95F464:\n"
      "LDR     R0, [R6, #0x18]\n"
      "LDR     R1, [R6, #0x60]\n"
      "BL      _TakeSemaphore \n"
      "CMP     R0, #9\n"
      "BEQ     loc_FF95F404\n"
      "LDR     R0, [SP, #0x5C]\n"
      "CMP     R0, #0\n"
      "BEQ     loc_FF95F48C\n"
"loc_FF95F484:\n"
      "MOV     R1, #1\n"
      "B       loc_FF95F6F4\n"
"loc_FF95F48C:\n"
      "LDR     R0, [R6, #0xC]\n"
      "MOV     R4, #5\n"
      "CMP     R0, #2\n"
      "MOV     R0, #1\n"
      "BNE     loc_FF95F4D8\n"
      "BL      sub_FFA39418\n"
      "BL      sub_FFA39434\n"
      "BL      sub_FF84BB20\n"
      "MOV     R0, #0\n"
      "BL      sub_FF84BB44\n"
      "BL      sub_FF84BB74\n"
      "STR     R4, [R6, #0x44]\n"
      "LDR     R0, [R6, #0x64]\n"
      "CMP     R0, #1\n"
      "BLEQ    sub_FFA39474\n"
      "BL      sub_FF95FF20\n"
      "BL      sub_FF84BBD0\n"
      "STR     R10, [R6, #0x44]\n"
      "B       loc_FF95F4E4\n"
"loc_FF95F4D8:\n"
      "BL      sub_FFA38140\n"
      "BL      sub_FFA38188\n"
      "STR     R4, [R6, #0x44]\n"
"loc_FF95F4E4:\n"
      "STR     R8, [R6, #0x34]\n"
      "B       loc_FF95F2AC\n"
"loc_FF95F4EC:\n"
      "CMP     R5, #1\n"
      "BNE     loc_FF95F790\n"
      "STR     R10, [R6, #0x38]\n"
      "LDR     R0, [R6, #0x6C]\n"
      "LDR     R11, [R4, #0xC]\n"
      "CMP     R0, #0\n"
      "LDRNE   R9, [SP, #0x58]\n"
      "LDRNE   R10, [SP, #0x54]\n"
      "BNE     loc_FF95F614\n"
      "LDR     R0, [R6, #0xC]\n"
      "CMP     R0, #2\n"
      "BNE     loc_FF95F56C\n"
      "LDR     R0, =0xFF95F0C0\n"
      "MOV     R1, #0\n"
      "BL      sub_FFA39450\n"
      "LDR     R1, [R6, #0x64]\n"
      "LDR     R2, =0xAB2A8\n"
      "ADD     R3, SP, #0x5C\n"
      "ADD     R0, SP, #0x30\n"
      "STRD    R0, [SP, #0x10]\n"
      "STRD    R2, [SP, #0x18]\n"
      "LDR     R1, [R6, #0x84]\n"
      "LDR     R2, [R6, #0x88]\n"
      "MVN     R3, #0\n"
      "ADD     R0, SP, #0x60\n"
      "STMEA   SP, {R0-R3}\n"
      "LDR     R0, [SP, #0x58]\n"
      "LDR     R1, [SP, #0x54]\n"
      "LDR     R2, [SP, #0x50]\n"
      "LDR     R3, [SP, #0x4C]\n"
      "BL      sub_FFA393A4\n"
      "B       loc_FF95F5C0\n"
"loc_FF95F56C:\n"
      "LDR     R0, [R4, #0x20]\n"
      "LDR     R2, [R6, #0x64]\n"
      "ADD     R3, SP, #0x5C\n"
      "MVN     R1, #0\n"
      "ADD     R9, SP, #0x1C\n"
      "STMIA   R9, {R0-R3}\n"
      "LDR     R3, [R4, #0x1C]\n"
      "LDR     R1, [R6, #0x84]\n"
      "LDR     R2, [R6, #0x88]\n"
      "ADD     R0, SP, #0x60\n"
      "ADD     R9, SP, #0xC\n"
      "STMIA   R9, {R0-R3}\n"
      "LDR     R1, [SP, #0x50]\n"
      "LDR     R2, [SP, #0x54]\n"
      "LDR     R3, [SP, #0x4C]\n"
      "STMFA   SP, {R1,R3}\n"
      "STR     R2, [SP]\n"
      "LDMIB   R4, {R0,R1}\n"
      "LDR     R3, [SP, #0x58]\n"
      "MOV     R2, R11\n"
      "BL      sub_FFA38094\n"
"loc_FF95F5C0:\n"
      "LDR     R0, [R6, #0x18]\n"
      "LDR     R1, [R6, #0x60]\n"
      "BL      _TakeSemaphore \n"
      "CMP     R0, #9\n"
      "BEQ     loc_FF95F404\n"
      "LDR     R0, [SP, #0x5C]\n"
      "CMP     R0, #0\n"
      "BNE     loc_FF95F484\n"
      "LDR     R0, [R6, #0xC]\n"
      "CMP     R0, #2\n"
      "MOV     R0, #1\n"
      "BNE     loc_FF95F5F8\n"
      "BL      sub_FFA39418\n"
      "B       loc_FF95F5FC\n"
"loc_FF95F5F8:\n"
      "BL      sub_FFA38140\n"
"loc_FF95F5FC:\n"
      "STR     R8, [R6, #0xC4]\n"
      "LDR     R0, [SP, #0x60]\n"
      "LDR     R1, [SP, #0x58]\n"
      "ADD     R9, R1, R0\n"
      "LDR     R1, [SP, #0x54]\n"
      "SUB     R10, R1, R0\n"
"loc_FF95F614:\n"
      "LDR     R0, [R6, #0xC]\n"
      "CMP     R0, #2\n"
      "BNE     loc_FF95F674\n"
      "LDR     R0, =0xFF95EDA8\n"
      "MOV     R1, #0\n"
      "BL      sub_FFA39450\n"
      "LDR     R1, [R6, #0x64]\n"
      "LDR     R2, =0xAB2A8\n"
      "ADD     R0, SP, #0x30\n"
      "ADD     R3, SP, #0x5C\n"
      "STRD    R0, [SP, #0x10]\n"
      "STRD    R2, [SP, #0x18]\n"
      "LDR     R1, [R6, #0x84]\n"
      "LDR     R2, [R6, #0x88]\n"
      "LDR     R3, [R6, #0x68]\n"
      "ADD     R0, SP, #0x60\n"
      "STMEA   SP, {R0-R3}\n"
      "LDR     R2, [SP, #0x50]\n"
      "LDR     R3, [SP, #0x4C]\n"
      "MOV     R1, R10\n"
      "MOV     R0, R9\n"
      "BL      sub_FFA393A4\n"
      "BL      sub_FF84BAFC\n"
      "B       loc_FF95F6C4\n"
"loc_FF95F674:\n"
      "LDR     R0, [R4, #0x20]\n"
      "LDR     R1, [R6, #0x68]\n"
      "LDR     R2, [R6, #0x64]\n"
      "ADD     R3, SP, #0x5C\n"
      "ADD     R12, SP, #0x1C\n"
      "STMIA   R12, {R0-R3}\n"
      "LDR     R3, [R4, #0x1C]\n"
      "LDR     R1, [R6, #0x84]\n"
      "LDR     R2, [R6, #0x88]\n"
      "ADD     R0, SP, #0x60\n"
      "ADD     R12, SP, #0xC\n"
      "STMIA   R12, {R0-R3}\n"
      "LDR     R2, [SP, #0x50]\n"
      "LDR     R3, [SP, #0x4C]\n"
      "STMFA   SP, {R2,R3}\n"
      "STR     R10, [SP]\n"
      "LDMIB   R4, {R0,R1}\n"
      "MOV     R3, R9\n"
      "MOV     R2, R11\n"
      "BL      sub_FFA38094\n"
"loc_FF95F6C4:\n"
      "LDR     R0, [R6, #0x18]\n"
      "LDR     R1, [R6, #0x60]\n"
      "BL      _TakeSemaphore \n"
      "CMP     R0, #9\n"
      "BNE     loc_FF95F6E4\n"
      "MOV     R1, #0\n"
"loc_FF95F6DC:\n"
      "MOV     R0, #0x90000\n"
      "B       loc_FF95F6F8\n"
"loc_FF95F6E4:\n"
      "LDR     R0, [SP, #0x5C]\n"
      "CMP     R0, #0\n"
      "BEQ     loc_FF95F700\n"
      "MOV     R1, #0\n"
"loc_FF95F6F4:\n"
      "MOV     R0, #0xA0000\n"
"loc_FF95F6F8:\n"
      "BL      sub_FF95F050\n"
      "B       loc_FF95F2AC\n"
"loc_FF95F700:\n"
      "LDR     R0, [R6, #0xC]\n"
      "CMP     R0, #2\n"
      "MOV     R0, #0\n"
      "BNE     loc_FF95F718\n"
      "BL      sub_FFA39418\n"
      "B       loc_FF95F71C\n"
"loc_FF95F718:\n"
      "BL      sub_FFA38140\n"
"loc_FF95F71C:\n"
      "LDR     R0, [SP, #0x58]\n"
      "LDR     R1, [SP, #0x60]\n"
      "BL      sub_FFA6DE7C\n"
      "LDR     R0, [R6, #0x68]\n"
      "LDR     R3, =0x64A0\n"        // <- 0x64A0
      "ADD     R1, R0, #1\n"
      "STR     R1, [R6, #0x68]\n"
      "LDR     R0, [SP, #0x60]\n"
      "SUB     R2, R3, #4\n"         // <- -4
      "BL      sub_FFA6B6F0\n"
#if 0
      "LDR	   R0, =0x649C \n"		// added, 0x64A0-0x4
      "BL      set_quality \n"		// added
#endif
      "LDR     R0, [R6, #0x64]\n"
      "CMP     R0, #1\n"
      "BNE     loc_FF95F790\n"
      "ADD     R0, SP, #0x48\n"
      "BL      sub_FFA394D4\n"
      "LDR     R1, =0xAB278\n"
      "LDR     R0, [R1, #4]\n"
      "LDR     R1, [R1]\n"
      "SUB     R2, R0, #0x400\n"
      "SUBS    R2, R2, #0x38\n"
      "ADDEQ   R0, R0, #8\n"
      "MOV     R1, R1, LSR #4\n"
      "MOV     R0, R0, LSR #4\n"
      "MUL     R1, R0, R1\n"
      "LDR     R0, [SP, #0x48]\n"
      "BL      sub_003FC934\n"
      "LDR     R1, =0xAB2A8\n"
      "STR     R0, [SP, #0x48]\n"
      "BL      sub_FFA6BA20\n"
"loc_FF95F790:\n"
      "CMP     R7, #1\n"
      "BNE     loc_FF95F7A4\n"
"loc_FF95F798:\n"
      "BL      sub_FF84BB20\n"
      "MOV     R0, #1\n"
      "BL      sub_FF84BB44\n"
"loc_FF95F7A4:\n"
      "CMP     R5, #1\n"
      "LDRNEH  R0, [R6, #6]\n"
      "CMPNE   R0, #3\n"
      "BNE     loc_FF95F2AC\n"
      "LDR     R0, [R6, #0x6C]\n"
      "ADD     R0, R0, #1\n"
      "STR     R0, [R6, #0x6C]\n"
      "LDRH    R1, [R6, #6]\n"
      "CMP     R1, #3\n"
      "LDRNE   R1, [R6, #0x54]\n"
      "MULNE   R0, R1, R0\n"
      "LDRNE   R1, [R6, #0x50]\n"
      "BNE     loc_FF95F7F4\n"
      "LDR     R1, [R6, #0x58]\n"
      "CMP     R1, #0x19\n"
      "LDRNE   R1, =0x3E9\n"
      "MOVEQ   R1, #0x3E8\n"
      "MUL     R0, R1, R0\n"
      "LDRNE   R1, =0x1770\n"
      "LDREQ   R1, =0x1388\n"
"loc_FF95F7F4:\n"
      "BL      sub_003FC934\n"
      "MOV     R4, R0\n"
      "BL      sub_FFA6E210\n"
      "LDR     R0, [R6, #0x8C]\n"
      "CMP     R0, R4\n"
      "BNE     loc_FF95F818\n"
      "LDR     R0, [R6, #0x3C]\n"
      "CMP     R0, #1\n"
      "BNE     loc_FF95F82C\n"
"loc_FF95F818:\n"
      "LDR     R1, [R6, #0x98]\n"
      "MOV     R0, R4\n"
      "BLX     R1\n"
      "STR     R4, [R6, #0x8C]\n"
      "STR     R8, [R6, #0x3C]\n"
"loc_FF95F82C:\n"
      "STR     R8, [R6, #0x38]\n"
      "B       loc_FF95F2AC\n"
	);
}
*/
