#include "lolevel.h"
#include "platform.h"
#include "core.h"

/*
#include "asmsafe.h"
*/

void __attribute__((naked,noinline)) _MoveFocusLensToDistance(short* a) //sub_FFD2A438
{
 (void)a;
 asm volatile (
"                STMFD   SP!, {R4,R5,LR}\n"
"                LDR     R5, =0xC0D8\n"
"                LDR     R4, [R0]\n"
"                MOV     R1, #1\n"
"                LDR     R0, [R5]\n"
"                BL      sub_FFC10974\n"
"                MOV     R0, R4\n"
"                LDR     R1, =0xFFE2DFD0\n"
"                MOV     R2, #0\n"
"                BL      sub_FFE2E338_my\n"
"                LDR     R0, [R5]\n"
"                MOV     R1, #1\n"
"                MOV     R2, #0\n"
"                LDMFD   SP!, {R4,R5,LR}\n"
"                B       sub_FFC107B8\n"
 );
}

void __attribute__((naked,noinline)) sub_FFE2E338_my()
{
 asm volatile (
"                STMFD   SP!, {R4-R6,LR}\n"
"                MOV     R5, R1\n"
"                MOV     R6, R2\n"
"                MOV     R4, R0\n"
"                BL      sub_FFE21424\n"
"                MOV     R1, R0,LSL#16\n"
"                MOV     R1, R1,LSR#16\n"
"                MOV     R0, R4\n"
"                MOV     R2, R5\n"
"                MOV     R3, R6\n"
"                LDMFD   SP!, {R4-R6,LR}\n"
"                B       sub_FFE2E368_my\n"
 );
}



void __attribute__((naked,noinline)) sub_FFE2E368_my()
{
 asm volatile (
"                STMFD   SP!, {R4,R5,LR}\n"
"                SUB     SP, SP, #0xC\n"
"                LDRH    R12, [SP,#0x18-0x12]\n"
"                ORR     R12, R12, R1,LSL#16\n"
"                SUBS    LR, R2, #0\n"
"                MOV     R0, R0,LSL#16\n"
"                MOV     R12, R12,ROR#16\n"
"                MOV     R2, #0\n"
"                STR     R12, [SP,#4]\n"
"                STR     R2, [SP,#0x18-0x10]\n"
"                MOV     R1, R3\n"
"                MOV     R4, R0,ASR#16\n"
"                ADD     R5, SP, #0x18-0x14\n"
"                LDRNE   R3, =0xC0DC\n"
"                STRNE   LR, [R3]\n"
"                LDREQ   R2, =0xFFE2DF98\n"
"                LDREQ   R3, =0xC0DC\n"
"                STREQ   R2, [R3]\n"
"                MOVS    R3, R4,LSL#16\n"
"                LDR     R3, =0xC0E0\n"
"                STR     R1, [R3]\n"
"                MOVEQ   R4, #0xFFFFFFFF\n"
"                BL      sub_FFE20E50\n"
"                LDR     R12, =0xC0E4\n"
"                MOV     R1, R4,LSL#16\n"
"                STR     R0, [R12]\n"
"                MOV     R1, R1,LSR#16\n"
"                LDR     R2, =0xFFE2DF9C\n"
/*
"LDR R3, =0x1850\n" //debug
"STR R5, [R3]\n" //debug
*/
"                MOV     R3, #0\n"
"                STR     R5, [SP,#0x18-0x18]\n"
"                BL      sub_FFE210DC_my\n"
"                ADD     SP, SP, #0xC\n"
"                LDMFD   SP!, {R4,R5,PC}\n"
 );
}

void __attribute__((naked,noinline)) sub_FFE210DC_my()
{
 asm volatile (
"                STMFD   SP!, {R4-R8,LR}\n"
"                LDR     R12, =0x80598\n"
"                SUB     SP, SP, #4\n"
"                LDR     LR, [R12]\n"
"                MOV     R1, R1,LSL#16\n"
"                CMP     LR, #1\n"
"                MOV     R4, R0\n"
"                MOV     R5, R2\n"
"                MOV     R8, R3\n"
"                MOV     R6, R1,ASR#16\n"
"                LDR     R7, [SP,#0x1C]\n"
"                BNE     loc_FFE21124\n"
"                CMP     R5, #0\n"
"                BEQ     loc_FFE21280\n"
"                MOV     R0, R8\n"
"                MOV     LR, PC\n"
"                MOV     PC, R5\n"
"                B       loc_FFE21280\n"
"loc_FFE21124:\n"
"                LDR     R3, =0xBACC\n"
"                LDR     R2, [R3]\n"
"                CMP     R2, #0\n"
"                BNE     loc_FFE21140\n"
"                LDR     R0, =0xffe20ed8\n"
"                MOV     R1, #0xC8\n"
"                BL      sub_FFC03B58\n"
"loc_FFE21140:\n"
"                MOV     R0, R4\n"
"                BL      sub_FFE224CC\n"
"                CMP     R0, #0\n"
"                BNE     loc_FFE2115C\n"
"                LDR     R0, =0xffe20ed8\n"
"                MOV     R1, #0xC9\n"
"                BL      sub_FFC03B58\n"
"loc_FFE2115C:\n"
"                CMP     R7, #0\n"
"                BNE     loc_FFE21170\n"
"                LDR     R0, =0xffe20ed8\n"
"                MOV     R1, #0xCA\n"
"                BL      sub_FFC03B58\n"
"loc_FFE21170:\n"
"                LDR     R3, =0xBAD0\n"
"                LDR     R2, [R3]\n"
"                CMP     R2, #0\n"
"                BEQ     loc_FFE211A0\n"
"                BL      sub_FFE1BA1C\n"
"                LDRH    R3, [R7]\n" //we get 0xd16 here on the first call (after switchover from af mode) when no zoom was used
"                MOV     R0, R0,LSL#16\n"
"                CMP     R3, R0,LSR#16\n" //while it should be <=0x9c4
/*
"LDR R1, =0x1850\n" //debug
"STR R3, [R1, #4]\n" //debug
"STR R0, [R1, #8]\n" //debug
"STR R7, [R1, #0xc]\n" //debug
*/
"                B       loc_FFE211A0\n" //originally BLS
"                LDR     R0, =0xffe20ed8\n"
"                MOV     R1, #0xCC\n"
"                BL      sub_FFC03B58\n"
"loc_FFE211A0:\n"
"                LDR     R3, =0x805B0\n"
"                MOV     R1, #0\n"
"                LDR     R0, [R3]\n"
"                BL      sub_FFC11B80\n"
"                BL      sub_FFE1DF60\n"
"                CMP     R0, #0\n"
"                BNE     loc_FFE211C8\n"
"                LDR     R0, =0xffe20ed8\n"
"                MOV     R1, #0xCF\n"
"                BL      sub_FFC03B58\n"
"loc_FFE211C8:\n"
"                MOV     R1, SP\n"
"                ADD     R0, SP, #0x1C-0x1A\n"
"                MOV     R2, #0\n"
"                BL      sub_FFE11984\n"
"                MOV     R0, R0,LSL#16\n"
"                MOV     R4, R0,LSR#16\n"
"                MOV     R1, R4\n"
"                LDRSH   R0, [SP,#0x1C-0x1A]\n"
"                LDRH    R2, [SP,#0x1C-0x1C]\n"
"                BL      sub_FFE23B2C\n"
"                MOV     R3, R6,LSL#16\n"
"                MOV     R0, R0,LSL#16\n"
"                MOV     R1, R3,LSR#16\n"
"                MOV     R0, R0,LSR#16\n"
"                CMP     R1, R0\n"
"                MOVCS   R0, R1\n"
"                MOV     R2, R4\n"
"                LDRSH   R1, [SP,#0x1C-0x1A]\n"
"                LDRH    R3, [SP,#0x1C-0x1C]\n"
"                BL      sub_FFE23818\n"
"                MOV     R0, R0,LSL#16\n"
"                MOV     R6, R0,ASR#16\n"
"                LDR     R12, =0x8059C\n"
"                LDR     R4, [R12]\n"
"                LDR     LR, =0x80594\n"
"                LDR     R2, =0x80590\n"
"                MOV     R3, #1\n"
"                ADD     R4, R4, #1\n"
"                MOV     R1, R8\n"
"                STR     R3, [R2]\n"
"                MOV     R0, R5\n"
"                STR     R3, [LR]\n"
"                STR     R4, [R12]\n"
"                BL      sub_FFE224E8\n"
"                LDR     R5, =0x805A0\n"
"                LDR     R2, =0x805B0\n"
"                LDR     R3, =0xFFE22594\n"
"                LDR     R0, [R2]\n"
"                STR     R3, [R5]\n"
"                BL      sub_FFC11D68\n"
"                BL      sub_FFC8C260\n"
"                MOV     R0, R6\n"
"                LDR     R1, [R5]\n"
"                MOV     R2, R4\n"
"                MOV     R3, R7\n"
"                BL      sub_FFE1DC38\n"
"loc_FFE21280:\n"
"                ADD     SP, SP, #4\n"
"                LDMFD   SP!, {R4-R8,PC}\n"
 );
}
