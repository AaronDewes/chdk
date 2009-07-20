#include "lolevel.h"
#include "platform.h"
#include "core.h"

static long *nrflag = (long*)0x6208;

#include "../../../generic/capt_seq.c"

void __attribute__((naked,noinline)) sub_FFD53158_my(){
  asm volatile (
                "STMFD   SP!, {R4,LR}\n"
                "BL      sub_FFD52D08\n"
                "LDR     R3, =0x91AA0\n"
                "LDR     R2, [R3,#0x24]\n"
                "CMP     R2, #0\n"
                "MOV     R4, R0\n"
                "MOV     R0, #0xC\n"
                "BEQ     loc_FFD531A0\n"
                "BL      sub_FFD5CA00\n"
                "TST     R0, #1\n"
                "BEQ     loc_FFD531A0\n"
                "LDR     R3, [R4,#8]\n"
                "LDR     R2, =0x61EC\n"
                "ORR     R3, R3, #0x40000000\n"
                "MOV     R1, #1\n"
                "STR     R1, [R2]\n"
                "STR     R3, [R4,#8]\n"
                "LDMFD   SP!, {R4,PC}\n"
"loc_FFD531A0:\n"
                "BL      sub_FFD9385C\n"
                "BL      sub_FFC14FE0\n"
                "STR     R0, [R4,#0x14]\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD56070_my\n"          //------------>
                "BL      capt_seq_hook_raw_here\n"   // +
                "TST     R0, #1\n"
                "LDRNE   R3, =0x61EC\n"
                "MOVNE   R2, #1\n"
                "STRNE   R2, [R3]\n"
                "LDMFD   SP!, {R4,PC}\n"
  );
}

void __attribute__((naked,noinline)) sub_FFD56070_my(long p)
{
    asm volatile (
                "STMFD   SP!, {R4,LR}\n"
                "MOV     R4, R0\n"
                "SUB     SP, SP, #0xC\n"
                "BL      sub_FFD56A2C\n"
                "LDR     R1, =0xFFFFFFFF\n"
                "BL      sub_FFC103A4\n"
                "LDR     R0, =0x122\n"
                "ADD     R1, SP, #0x14-0x10\n"
                "MOV     R2, #4\n"
                "BL      sub_FFC14DE4\n"
                "TST     R0, #1\n"
                "BEQ     loc_FFD560B0\n"
                "LDR     R0, =0xFFD55EEC\n"
                "MOV     R1, #0x1BC\n"
                "BL      sub_FFC03CF8\n"
"loc_FFD560B0:\n"
                "LDR     R3, =0x91AA0\n"
                "LDR     R2, =0x91B60\n"
                "LDR     R0, [R3,#0x80]\n"
                "LDRSH   R1, [R2,#0xE]\n"
                //"BL      nullsub_49\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD55E70\n"
            "BL      wait_until_remote_button_is_released\n"
	    	"BL      capt_seq_hook_set_nr\n"
                "LDR     R3, =0x620C\n"
                "LDR     R0, [R3]\n"

		"B       sub_FFD560D4\n"
    );
}

void __attribute__((naked,noinline)) sub_FFD5307C_my(long p)
{
    asm volatile (
                "STMFD   SP!, {R4,R5,LR}\n"
                "LDR     R3, =0x91AA0\n"
                "LDR     R5, [R0,#0xC]\n"
                "LDR     R1, [R3,#0x24]\n"
                "LDR     R2, [R5,#8]\n"
                "CMP     R1, #0\n"
                "ORR     R2, R2, #1\n"
                "STR     R2, [R5,#8]\n"
                "BNE     loc_FFD530D0\n"
                "MOV     R0, #0xC\n"
                "BL      sub_FFD5CA00\n"
                "TST     R0, #1\n"
                "BEQ     loc_FFD530D0\n"
                "LDR     R3, [R5,#8]\n"
                "MOV     R0, #1\n"
                "ORR     R3, R3, #0x40000000\n"
                "STR     R3, [R5,#8]\n"
"loc_FFD530C0:\n"
                "MOV     R2, R5\n"
                "MOV     R1, #1\n"
                "LDMFD   SP!, {R4,R5,LR}\n"
                "B       sub_FFD518C4\n"
"loc_FFD530D0:\n"
                "LDR     R4, =0x91AA0\n"
                "BL      sub_FFD53B6C\n"
                "LDR     R3, [R4,#0x24]\n"
                "CMP     R3, #0\n"
                "BNE     loc_FFD53118\n"
                "MOV     R0, R5\n"
                "BL      sub_FFD54C10\n"
                "TST     R0, #1\n"
                "BNE     loc_FFD530C0\n"
                "BL      sub_FFD9385C\n"
                "BL      sub_FFC14FE0\n"
                "STR     R0, [R5,#0x14]\n"
                "MOV     R0, R5\n"
                "BL      sub_FFD55F58\n"
                "BL      sub_FFD568B8\n"
                "MOV     R0, R5\n"
                "BL      sub_FFD56070_my\n"
		"BL      capt_seq_hook_raw_here\n"
                "B       loc_FFD5312C\n"
"loc_FFD53118:\n"
                "LDR     R3, =0x61EC\n"
                "LDR     R2, [R3]\n"
                "CMP     R2, #0\n"
                "MOVNE   R0, #0x1D\n"
                "MOVEQ   R0, #0\n"
"loc_FFD5312C:\n"
                "MOV     R1, #1\n"
                "MOV     R2, R5\n"
                "BL      sub_FFD518C4\n"
                "BL      sub_FFD563A4\n"
                "CMP     R0, #0\n"
                "LDRNE   R3, [R5,#8]\n"
                "ORRNE   R3, R3, #0x2000\n"
                "STRNE   R3, [R5,#8]\n"
                "LDMFD   SP!, {R4,R5,PC}\n"


    );
}

void __attribute__((naked,noinline)) capt_seq_task()
{
	asm volatile (
                "STMFD   SP!, {R4,LR}\n"
                "SUB     SP, SP, #4\n"
                "MOV     R4, SP\n"
                "B       loc_FFD536F0\n"
"loc_FFD53564:\n"
                "LDR     R2, [SP,#0xC-0xC]\n"
                "LDR     R3, [R2]\n"
                "MOV     R0, R2\n"
                "CMP     R3, #0x16\n"
                "LDRLS   PC, [PC,R3,LSL#2]\n"
                "B       loc_FFD536C4\n"
                ".long loc_FFD535D8\n"
                ".long loc_FFD535F8\n"
                ".long loc_FFD5360C\n"
                ".long loc_FFD53620\n"
                ".long loc_FFD53618\n"
                ".long loc_FFD53628\n"
                ".long loc_FFD53630\n"
                ".long loc_FFD5363C\n"
                ".long loc_FFD53644\n"
                ".long loc_FFD53650\n"
                ".long loc_FFD53658\n"
                ".long loc_FFD53660\n"
                ".long loc_FFD53668\n"
                ".long loc_FFD53670\n"
                ".long loc_FFD53678\n"
                ".long loc_FFD53684\n"
                ".long loc_FFD5368C\n"
                ".long loc_FFD53694\n"
                ".long loc_FFD5369C\n"
                ".long loc_FFD536A8\n"
                ".long loc_FFD536B4\n"
                ".long loc_FFD536BC\n"
                ".long loc_FFD536D8\n"
"loc_FFD535D8:\n"
                "BL      sub_FFD53B94\n"
                "BL      shooting_expo_param_override\n"  // +
                "BL      sub_FFD51358\n"
                "LDR     R3, =0x91AA0\n"
                "LDR     R2, [R3,#0x24]\n"
                "CMP     R2, #0\n"
                "BEQ     loc_FFD536D4\n"
                "BL      sub_FFD53158_my\n"
                "B       loc_FFD536D4\n"
"loc_FFD535F8:\n"
                "BL      sub_FFD5307C_my\n"
"loc_FFD535FC:\n"
                "LDR     R2, =0x91AA0\n"
                "MOV     R3, #0\n"
                "STR     R3, [R2,#0x24]\n"
                "B       loc_FFD536D4\n"
"loc_FFD5360C:\n"
                "MOV     R0, #1\n"
                "BL      sub_FFD53D84\n"
                "B       loc_FFD536D4\n"
"loc_FFD53618:\n"
                "BL      sub_FFD537E8\n"
                "B       loc_FFD535FC\n"
"loc_FFD53620:\n"
                "BL      sub_FFD53B4C\n"
                "B       loc_FFD535FC\n"
"loc_FFD53628:\n"
                "BL      sub_FFD53B5C\n"
                "B       loc_FFD536D4\n"
"loc_FFD53630:\n"
                "BL      sub_FFD53C7C\n"
                "BL      sub_FFD51358\n"
                "B       loc_FFD536D4\n"
"loc_FFD5363C:\n"
                "BL      sub_FFD53230\n"
                "B       loc_FFD536D4\n"
"loc_FFD53644:\n"
                "BL      sub_FFD53CE4\n"
                "BL      sub_FFD51358\n"
                "B       loc_FFD536D4\n"
"loc_FFD53650:\n"
                "BL      sub_FFD53B4C\n"
                "B       loc_FFD536D4\n"
"loc_FFD53658:\n"
                "BL      sub_FFD5533C\n"
                "B       loc_FFD536D4\n"
"loc_FFD53660:\n"
                "BL      sub_FFD55508\n"
                "B       loc_FFD536D4\n"
"loc_FFD53668:\n"
                "BL      sub_FFD5559C\n"
                "B       loc_FFD536D4\n"
"loc_FFD53670:\n"
                "BL      sub_FFD55638\n"
                "B       loc_FFD536D4\n"
"loc_FFD53678:\n"
                "MOV     R0, #0\n"
                "BL      sub_FFD558A4\n"
                "B       loc_FFD536D4\n"
"loc_FFD53684:\n"
                "BL      sub_FFD55A5C\n"
                "B       loc_FFD536D4\n"
"loc_FFD5368C:\n"
                "BL      sub_FFD55AEC\n"
                "B       loc_FFD536D4\n"
"loc_FFD53694:\n"
                "BL      sub_FFD55BA4\n"
                "B       loc_FFD536D4\n"
"loc_FFD5369C:\n"
                "MOV     R0, #1\n"
                "BL      sub_FFD558A4\n"
                "B       loc_FFD536D4\n"
"loc_FFD536A8:\n"
                "BL      sub_FFD53EA0\n"
                "BL      sub_FFD52FA4\n"
                "B       loc_FFD536D4\n"
"loc_FFD536B4:\n"
                "BL      sub_FFD55778\n"
                "B       loc_FFD536D4\n"
"loc_FFD536BC:\n"
                "BL      sub_FFD557D0\n"
                "B       loc_FFD536D4\n"
"loc_FFD536C4:\n"
                "MOV     R1, #0x4E0\n"
                "LDR     R0, =0xFFD52E00\n"
                "ADD     R1, R1, #9\n"
                "BL      sub_FFC03CF8\n"
"loc_FFD536D4:\n"
                "LDR     R2, [SP,#0xC-0xC]\n"
"loc_FFD536D8:\n"
                "LDR     R3, =0x66DA4\n"
                "LDR     R1, [R2,#4]\n"
                "LDR     R0, [R3]\n"
                "BL      sub_FFC10208\n"
                "LDR     R0, [SP,#0xC-0xC]\n"
                "BL      sub_FFD52E7C\n"
"loc_FFD536F0:\n"
                "LDR     R3, =0x66DA8\n"
                "MOV     R1, R4\n"
                "LDR     R0, [R3]\n"
                "MOV     R2, #0\n"
                "BL      sub_FFC10920\n"
                "TST     R0, #1\n"
                "BEQ     loc_FFD53564\n"
                "MOV     R1, #0x410\n"
                "LDR     R0, =0xFFD52E00\n"
                "ADD     R1, R1, #0xB\n"
                "BL      sub_FFC03CF8\n"
                "BL      sub_FFC11E7C\n"
                "ADD     SP, SP, #4\n"
                "LDMFD   SP!, {R4,PC}\n"
	);
}
/***************************************************************************/

void __attribute__((naked,noinline)) exp_drv_task(){
 asm volatile(
                 "STMFD   SP!, {R4-R8,LR}\n"
                 "SUB     SP, SP, #0x20\n"
                 "ADD     R7, SP, #0x38-0x34\n"
                 "B       loc_FFCFC2B4\n"
 "loc_FFCFBE08:\n"
                 "CMP     R2, #0x22\n"
                 "BNE     loc_FFCFBE20\n"
                 "LDR     R0, [R12,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R12,#0x88]\n"
                 "B       loc_FFCFBE84\n"
 
 "loc_FFCFBE20:\n"
                 "CMP     R2, #0x1D\n"
                 "BNE     loc_FFCFBE34\n"
                 "MOV     R0, R12\n"
                 "BL      sub_FFCFBCC8\n"
                 "B       loc_FFCFBE74\n"
 "loc_FFCFBE34:\n"
                 "CMP     R2, #0x1E\n"
                 "BNE     loc_FFCFBE48\n"
                 "MOV     R0, R12\n"
                 "BL      sub_FFCFBD24\n"
                 "B       loc_FFCFBE74\n"
 "loc_FFCFBE48:\n"
                 "SUB     R3, R2, #0x1F\n"
                 "CMP     R3, #1\n"
                 "BHI     loc_FFCFBE60\n"
                 "MOV     R0, R12\n"
                 "BL      sub_FFCFBD80\n"
                 "B       loc_FFCFBE74\n"
 "loc_FFCFBE60:\n"
                 "CMP     R2, #0x21\n"
                 "BNE     loc_FFCFBE90\n"
                 "BL      sub_FFCA3E74\n"
                 "BL      sub_FFCA6F68\n"
                 "BL      sub_FFCA61A0\n"
 "loc_FFCFBE74:\n"
                 "LDR     R3, [SP,#0x38-0x34]\n"
                 "LDR     R0, [R3,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R3,#0x88]\n"
 "loc_FFCFBE84:\n"
                 "LDR     R0, [SP,#0x38-0x34]\n"
                 "BL      sub_FFCF7874\n"
                 "B       loc_FFCFC2B4\n"
"loc_FFCFBE90:\n"
                 "CMP     R2, #0xD\n"
                 "MOV     R8, #1\n"
                 "BNE     loc_FFCFBF00\n"
                 "LDR     R1, [R12,#0x7C]\n"
                 "ADD     R1, R1, R1,LSL#1\n"
                 "ADD     R1, R12, R1,LSL#2\n"
                 "ADD     R6, SP, #0x38-0x24\n"
                 "SUB     R1, R1, #8\n"
                 "MOV     R2, #0xC\n"
                 "MOV     R0, R6\n"
                 "BL      sub_FFEEB2D0\n"
                 "LDR     R0, [SP,#0x38-0x34]\n"
                 "BL      sub_FFCFA350\n"
                 "LDR     R3, [SP,#0x38-0x34]\n"
                 "LDR     R1, [R3,#0x7C]\n"
                 "LDR     R2, [R3,#0x8C]\n"
                 "ADD     R0, R3, #4\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R3,#0x88]\n"
                 "LDR     R0, [SP,#0x38-0x34]\n"
                 "BL      sub_FFCFA620\n"
                 "LDR     R3, [SP,#0x38-0x34]\n"
                 "ADD     R0, R3, #4\n"
                 "LDR     R1, [R3,#0x7C]\n"
                 "LDR     R2, [R3,#0x94]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R3,#0x90]\n"
                 "B       loc_FFCFC250\n"
"loc_FFCFBF00:\n"
                 "SUB     R3, R2, #0xE\n"
                 "CMP     R3, #1\n"
                 "BHI     loc_FFCFBFBC\n"
                 "ADD     R6, SP, #0x38-0x24\n"
                 "ADD     R5, SP, #0x38-0x30\n"
                 "MOV     R0, R12\n"
                 "MOV     R1, R6\n"
                 "MOV     R2, R5\n"
                 "BL      sub_FFCFA714\n"
                 "MOV     R4, R0\n"
                 "CMP     R4, #5\n"
                 "CMPNE   R4, #1\n"
                 "BNE     loc_FFCFBF54\n"
                 "LDR     R12, [SP,#0x38-0x34]\n"
                 "MOV     R0, R5\n"
                 "LDR     R1, [R12,#0x7C]\n"
                 "MOV     R2, R4\n"
                 "LDR     R3, [R12,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R12,#0x88]\n"
                 "B       loc_FFCFBF8C\n"
 "loc_FFCFBF54:\n"
                 "CMP     R4, #6\n"
                 "CMPNE   R4, #2\n"
                 "BNE     loc_FFCFBF9C\n"
                 "LDR     R12, [SP,#0x38-0x34]\n"
                 "MOV     R0, R5\n"
                 "MOV     R1, R8\n"
                 "MOV     R2, R4\n"
                 "LDR     R3, [R12,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R12,#0x88]\n"
                 "MOV     R1, R6\n"
                 "LDR     R0, [SP,#0x38-0x34]\n"
                 "MOV     R2, R5\n"
                 "BL      sub_FFCFB934\n"
 "loc_FFCFBF8C:\n"
                 "MOV     R1, R4\n"
                 "LDR     R0, [SP,#0x38-0x34]\n"
                 "BL      sub_FFCFBC5C\n"
                 "B       loc_FFCFC250\n"
 "loc_FFCFBF9C:\n"
                 "LDR     R12, [SP,#0x38-0x34]\n"
                 "MOV     R2, R4\n"
                 "ADD     R0, R12, #4\n"
                 "LDR     R1, [R12,#0x7C]\n"
                 "LDR     R3, [R12,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R12,#0x88]\n"
                 "B       loc_FFCFC250\n"
 "loc_FFCFBFBC:\n"
                 "SUB     R3, R2, #0x19\n"
                 "CMP     R3, #1\n"
                 "BHI     loc_FFCFC014\n"
                 "LDR     R1, [R12,#0x7C]\n"
                 "ADD     R1, R1, R1,LSL#1\n"
                 "ADD     R1, R12, R1,LSL#2\n"
                 "ADD     R6, SP, #0x38-0x24\n"
                 "SUB     R1, R1, #8\n"
                 "MOV     R2, #0xC\n"
                 "MOV     R0, R6\n"
                 "BL      sub_FFEEB2D0\n"
                 "LDR     R0, [SP,#0x38-0x34]\n"
                 "BL      sub_FFCF9748\n"
                 "LDR     R3, [SP,#0x38-0x34]\n"
                 "ADD     R0, R3, #4\n"
                 "LDR     R1, [R3,#0x7C]\n"
                 "LDR     R2, [R3,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R3,#0x88]\n"
                 "LDR     R0, [SP,#0x38-0x34]\n"
                 "BL      sub_FFCF9B24\n"
                 "B       loc_FFCFC250\n"
 "loc_FFCFC014:\n"
                 "ADD     R6, SP, #0x38-0x24\n"
                 "ADD     R1, R12, #4\n"
                 "MOV     R2, #0xC\n"
                 "MOV     R0, R6\n"
                 "BL      sub_FFEEB2D0\n"
                 "LDR     R12, [SP,#0x38-0x34]\n"
                 "LDR     R3, [R12]\n"
                 "MOV     R2, R12\n"
                 "CMP     R3, #0x1C\n"
                 "LDRLS   PC, [PC,R3,LSL#2]\n"
                 "B       loc_FFCFC23C\n"
                 ".long loc_FFCFC0B4\n"
                 ".long loc_FFCFC0C0\n"
                 ".long loc_FFCFC0CC\n"
                 ".long loc_FFCFC0CC\n"
                 ".long loc_FFCFC0B4\n"
                 ".long loc_FFCFC0C0\n"
                 ".long loc_FFCFC0CC\n"
                 ".long loc_FFCFC0CC\n"
                 ".long loc_FFCFC0F0\n"
                 ".long loc_FFCFC0F0\n"
                 ".long loc_FFCFC210\n"
                 ".long loc_FFCFC21C\n"
                 ".long loc_FFCFC22C\n"
                 ".long loc_FFCFC23C\n"
                 ".long loc_FFCFC23C\n"
                 ".long loc_FFCFC23C\n"
                 ".long loc_FFCFC0D8\n"
                 ".long loc_FFCFC0E4\n"
                 ".long loc_FFCFC100\n"
                 ".long loc_FFCFC10C\n"
                 ".long loc_FFCFC144\n"
                 ".long loc_FFCFC17C\n"
                 ".long loc_FFCFC1B4\n"
                 ".long loc_FFCFC1EC\n"
                 ".long loc_FFCFC1EC\n"
                 ".long loc_FFCFC23C\n"
                 ".long loc_FFCFC23C\n"
                 ".long loc_FFCFC1F8\n"
                 ".long loc_FFCFC204\n"
 "loc_FFCFC0B4:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFCF8124\n"
                 "B       loc_FFCFC238\n"
 "loc_FFCFC0C0:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFCF83C8\n"
                 "B       loc_FFCFC238\n"
 "loc_FFCFC0CC:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFCF863C\n"
                 "B       loc_FFCFC238\n"
 "loc_FFCFC0D8:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFCF8938\n"
                 "B       loc_FFCFC238\n"
 "loc_FFCFC0E4:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFCF8B9C\n"
                 "B       loc_FFCFC238\n"
 "loc_FFCFC0F0:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFCF8D98_my\n"   //------------->
                 "MOV     R8, #0\n"
                 "B       loc_FFCFC238\n"
 "loc_FFCFC100:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFCF8EF4\n"
                 "B       loc_FFCFC238\n"
 "loc_FFCFC10C:\n"
                 "LDRH    R1, [R2,#4]\n"
                 "LDR     R3, =0x42858\n"
                 "STRH    R1, [SP,#0x38-0x24]\n"
                 "LDRH    R1, [R3,#6]\n"
                 "STRH    R1, [SP,#0x38-0x1E]\n"
                 "LDRH    R1, [R3,#2]\n"
                 "STRH    R1, [SP,#0x38-0x22]\n"
                 "LDRH    R3, [R3,#4]\n"
                 "STRH    R3, [SP,#0x38-0x20]\n"
                 "MOV     R0, R2\n"
                 "LDRH    R2, [R2,#0xC]\n"
                 "STRH    R2, [SP,#0x38-0x1C]\n"
                 "BL      sub_FFCF91F0\n"
                 "B       loc_FFCFC238\n"
 "loc_FFCFC144:\n"
                 "MOV     R0, R2\n"
                 "LDRH    R2, [R2,#4]\n"
                 "LDR     R3, =0x42858\n"
                 "STRH    R2, [SP,#0x38-0x24]\n"
                 "LDRH    R2, [R3,#8]\n"
                 "STRH    R2, [SP,#0x38-0x1C]\n"
                 "LDRH    R1, [R3,#2]\n"
                 "STRH    R1, [SP,#0x38-0x22]\n"
                 "LDRH    R2, [R3,#4]\n"
                 "STRH    R2, [SP,#0x38-0x20]\n"
                 "LDRH    R3, [R3,#6]\n"
                 "STRH    R3, [SP,#0x38-0x1E]\n"
                 "BL      sub_FFCF9318\n"
                 "B       loc_FFCFC238\n"
 "loc_FFCFC17C:\n"
                 "LDR     R3, =0x42858\n"
                 "LDRH    R1, [R3]\n"
                 "STRH    R1, [SP,#0x38-0x24]\n"
                 "MOV     R0, R2\n"
                 "LDRH    R2, [R2,#6]\n"
                 "STRH    R2, [SP,#0x38-0x22]\n"
                 "LDRH    R2, [R3,#8]\n"
                 "STRH    R2, [SP,#0x38-0x1C]\n"
                 "LDRH    R1, [R3,#4]\n"
                 "STRH    R1, [SP,#0x38-0x20]\n"
                 "LDRH    R3, [R3,#6]\n"
                 "STRH    R3, [SP,#0x38-0x1E]\n"
                 "BL      sub_FFCF93DC\n"
                 "B       loc_FFCFC238\n"
 "loc_FFCFC1B4:\n"
                 "LDR     R3, =0x42858\n"
                 "LDRH    R1, [R3,#6]\n"
                 "STRH    R1, [SP,#0x38-0x1E]\n"
                 "LDRH    R1, [R3]\n"
                 "STRH    R1, [SP,#0x38-0x24]\n"
                 "LDRH    R1, [R3,#2]\n"
                 "STRH    R1, [SP,#0x38-0x22]\n"
                 "LDRH    R3, [R3,#4]\n"
                 "STRH    R3, [SP,#0x38-0x20]\n"
                 "MOV     R0, R2\n"
                 "LDRH    R2, [R2,#0xC]\n"
                 "STRH    R2, [SP,#0x38-0x1C]\n"
                 "BL      sub_FFCF9494\n"
                 "B       loc_FFCFC238\n"
 "loc_FFCFC1EC:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFCF9544\n"
                 "B       loc_FFCFC238\n"
 "loc_FFCFC1F8:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFCF9C74\n"
                 "B       loc_FFCFC238\n"
 "loc_FFCFC204:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFCF9E70\n"
                 "B       loc_FFCFC238\n"
 "loc_FFCFC210:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFCFA02C\n"
                 "B       loc_FFCFC238\n"
 "loc_FFCFC21C:\n"
                 "MOV     R0, R2\n"
                 "MOV     R1, #0\n"
                 "BL      sub_FFCFA210\n"
                 "B       loc_FFCFC238\n"
 "loc_FFCFC22C:\n"
                 "MOV     R0, R2\n"
                 "MOV     R1, #1\n"
                 "BL      sub_FFCFA210\n"
 "loc_FFCFC238:\n"
                 "LDR     R12, [SP,#0x38-0x34]\n"
 "loc_FFCFC23C:\n"
                 "ADD     R0, R12, #4\n"
                 "LDR     R1, [R12,#0x7C]\n"
                 "LDR     R2, [R12,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R12,#0x88]\n"
 "loc_FFCFC250:\n"
                 "CMP     R8, #1\n"
                 "BNE     loc_FFCFC278\n"
                 "LDR     R1, [SP,#0x38-0x34]\n"
                 "LDR     R3, [R1,#0x7C]\n"
                 "ADD     R3, R3, R3,LSL#1\n"
                 "ADD     R1, R1, R3,LSL#2\n"
                 "MOV     R0, R6\n"
                 "SUB     R1, R1, #8\n"
                 "BL      sub_FFCF7E88\n"
                 "B       loc_FFCFC2AC\n"
 "loc_FFCFC278:\n"
                 "MOV     R4, #1\n"
                 "MOV     R0, R4\n"
                 "MOV     R1, R4\n"
                 "MOV     R2, R4\n"
                 "MOV     R3, R4\n"
                 "STR     R4, [SP,#0x38-0x38]\n"
                 "BL      sub_FFCF7DDC\n"
                 "MOV     R0, R4\n"
                 "MOV     R1, R0\n"
                 "MOV     R2, R0\n"
                 "MOV     R3, R0\n"
                 "STR     R4, [SP,#0x38-0x38]\n"
                 "BL      sub_FFCF7F60\n"
 "loc_FFCFC2AC:\n"
                 "LDR     R0, [SP,#0x38-0x34]\n"
                 "BL      sub_FFCF7874\n"
 "loc_FFCFC2B4:\n"
                 "LDR     R3, =0x42850\n"
                 "MOV     R2, #0\n"
                 "LDR     R0, [R3]\n"
                 "MOV     R1, R7\n"
                 "BL      sub_FFC10920\n"
                 "LDR     R12, [SP,#0x38-0x34]\n"
                 "LDR     R2, [R12]\n"
                 "CMP     R2, #0x23\n"
                 "BNE     loc_FFCFBE08\n"
                 "MOV     R0, R12\n"
                 "BL      sub_FFCF7874\n"
                 "LDR     R3, =0x4284C\n"
                 "MOV     R1, #1\n"
                 "LDR     R0, [R3]\n"
                 "BL      sub_FFC10208\n"
                 "BL      sub_FFC11E7C\n"
                 //End of function task_ExpDrvTask 
    );
}

void __attribute__((naked,noinline)) sub_FFCF8D98_my() { // ExpDrv_c__2
 asm volatile(
                 "STMFD   SP!, {R4-R6,LR}\n"
                 "LDR     R3, =0x4284C\n"
                 "MOV     R4, R0\n"
                 "MOV     R1, #0x3E\n"
                 "LDR     R0, [R3]\n"
                 "BL      sub_FFC103A4\n"
                 "MOV     R1, #0\n"
                 "LDRSH   R0, [R4,#4]\n"
                 "BL      sub_FFCF79A8\n"
                 "MOV     R6, R0\n"
                 "LDRSH   R0, [R4,#6]\n"
                 "BL      sub_FFCF7B1C\n"
                 "LDRSH   R0, [R4,#8]\n"
                 "BL      sub_FFCF7BB8\n"
                 "LDRSH   R0, [R4,#0xA]\n"
                 "BL      sub_FFCF7C54\n"
                 "LDRSH   R0, [R4,#0xC]\n"
                 "BL      sub_FFCF7CF0\n"
                 "LDR     R3, [R4]\n"
                 "CMP     R3, #9\n"
                 "MOV     R5, R0\n"
                 "MOVEQ   R5, #0\n"
                 "MOVEQ   R6, R5\n"
                 "CMP     R6, #1\n"
                 "BNE     loc_FFCF8E1C\n"
                 "MOV     R2, #2\n"
                 "LDRSH   R0, [R4,#4]\n"
                 "LDR     R1, =0xFFCF78C8\n"
                 "BL      sub_FFE91A68\n"
                 "LDR     R2, =0x4288C\n"
                 "MOV     R3, #0\n"
                 "STR     R3, [R2]\n"
                 "B       loc_FFCF8E20\n"
 "loc_FFCF8E1C:\n"
                 "BL      sub_FFCF7D8C\n"
 "loc_FFCF8E20:\n"
                 "STRH    R0, [R4,#4]\n"
                 "CMP     R5, #1\n"
                 "BNE     loc_FFCF8E40\n"
                 "LDRSH   R0, [R4,#0xC]\n"
                 "LDR     R1, =0xFFCF798C\n"
                 "MOV     R2, #0x20\n"
                 "BL      sub_FFCF80C4\n"
                 "B       loc_FFCF8E44\n"
 "loc_FFCF8E40:\n"
                 "BL      sub_FFCF7DCC\n"
 "loc_FFCF8E44:\n"
                 "STRH    R0, [R4,#0xC]\n"
                 "LDRSH   R0, [R4,#6]\n"
                 "BL      sub_FFCA3AFC_my\n"  //------------>
                 "LDRSH   R0, [R4,#8]\n"
                 "MOV     R1, #1\n"
                 "BL      sub_FFCA5D60\n"
                 "ADD     R0, R4, #8\n"
                 "MOV     R1, #0\n"
                 "BL      sub_FFCA5E20\n"
                 "LDRSH   R0, [R4,#0xE]\n"
                 "BL      sub_FFCE58F4\n"
                 "CMP     R6, #1\n"
                 "BNE     loc_FFCF8EA8\n"
                 "LDR     R3, =0x4284C\n"
                 "MOV     R2, #0xBB0\n"
                 "LDR     R0, [R3]\n"
                 "MOV     R1, #2\n"
                 "ADD     R2, R2, #8\n"
                 "BL      sub_FFC101F8\n"
                 "TST     R0, #1\n"
                 "BEQ     loc_FFCF8EA8\n"
                 "MOV     R1, #0x440\n"
                 "LDR     R0, =0xFFCF7820\n"
                 "ADD     R1, R1, #0xB\n"
                 "BL      sub_FFC03CF8\n"
 "loc_FFCF8EA8:\n"
                 "CMP     R5, #1\n"
                 "LDMNEFD SP!, {R4-R6,PC}\n"
                 "LDR     R3, =0x4284C\n"
                 "MOV     R2, #0xBB0\n"
                 "LDR     R0, [R3]\n"
                 "MOV     R1, #0x20\n"
                 "ADD     R2, R2, #8\n"
                 "BL      sub_FFC101F8\n"
                 "TST     R0, #1\n"
                 "LDMEQFD SP!, {R4-R6,PC}\n"
                 "LDR     R0, =0xFFCF7820\n"
                 "MOV     R1, #0x450\n"
                 "LDMFD   SP!, {R4-R6,LR}\n"
                 "B       sub_FFC03CF8\n"
   );
}


void __attribute__((naked,noinline)) sub_FFCA3AFC_my(){
 asm volatile(
                 "STMFD   SP!, {R4,LR}\n"
                 "LDR     R3, =0x52E4\n"
                 "LDR     R2, [R3]\n"
                 "MOV     R1, #0x150\n"
                 "MOV     R3, R0,LSL#16\n"
                 "CMP     R2, #1\n"
                 "ADD     R1, R1, #1\n"
                 "LDR     R0, =0xFFCA3338\n"
                 "MOV     R4, R3,ASR#16\n"
                 "BEQ     loc_FFCA3B28\n"
                 "BL      sub_FFC03CF8\n"
 "loc_FFCA3B28:\n"
                 "MOV     R1, #0x154\n"
                 "CMN     R4, #0xC00\n"
                 "LDR     R3, =0x3419E\n"
                 "LDR     R0, =0xFFCA3338\n"
                 "ADD     R1, R1, #3\n"
                 "LDREQSH R4, [R3]\n"
                 "LDRNE   R3, =0x3419E\n"
                 "CMN     R4, #0xC00\n"
                 "STRH    R4, [R3]\n"
                 "BNE     loc_FFCA3B54\n"
                 "BL      sub_FFC03CF8\n"
 "loc_FFCA3B54:\n"
                 "MOV     R0, R4\n"
                 "BL      apex2us\n"
                 "MOV     R4, R0\n"
            //   "BL      nullsub_61\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FFCA2EB4\n"
                 "TST     R0, #1\n"
                 "MOV     R1, #0x15C\n"
                 "LDR     R0, =0xFFCA3338\n"
                 "LDMEQFD SP!, {R4,PC}\n"
                 "LDMFD   SP!, {R4,LR}\n"
                 "B       sub_FFC03CF8\n"
 );
}


