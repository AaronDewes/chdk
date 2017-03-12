#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"

static long *nrflag = (long*)0x7910;

#include "../../../generic/capt_seq.c"

void __attribute__((naked,noinline)) hangdebug() {
	debug_led(1);
	while(1);
}

void __attribute__((naked,noinline)) blinko(void) {
	int i;
	//while(1) {
		*((volatile int *) 0xC02200B6) = 0x46; // Turn on LED
		for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }

		*((volatile int *) 0xC02200B6) = 0x44; // Turn off LED
		for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }

		*((volatile int *) 0xC02200B6) = 0x46; // Turn on LED
		for (i=0; i<0x200000; i++) { asm volatile ( "nop\n" ); }

		*((volatile int *) 0xC02200B6) = 0x44; // Turn off LED
		for (i=0; i<0x900000; i++) { asm volatile ( "nop\n" ); }
	//}
}

void __attribute__((naked,noinline)) capt_seq_task() {

 asm volatile (

"STMFD SP!, {R3-R9,LR}\n"
"LDR R6, =0x2D50\n"
"LDR R4, =0x3894C\n"
"MOV R9, #1\n"
"MOV R7, #0\n"

"loc_FF87CDA4:\n"
	"LDR R0, [R6,#4]\n"
	"MOV R2, #0\n"
	"MOV R1, SP\n"
	"BL sub_FF838318\n"
	"TST R0, #1\n"
	"BEQ loc_FF87CDD0\n"
	"LDR R1, =0x5B4\n"
	"LDR R0, =0xFF87C568\n"
	"BL sub_FF81E88C\n"
	"BL sub_FF81E844\n"
	"LDMFD SP!, {R3-R9,PC}\n"


"loc_FF87CDD0:\n"
	"LDR R0, [SP]\n" // change here
	"LDR R1, [R0]\n"
	"CMP R1, #0x22\n"
	"ADDLS   PC, PC, R1,LSL#2\n" // change here
	"B loc_FF87D0D4\n"

"loc_FF87CDE4: B  loc_FF87CE70\n"
"loc_FF87CDE8: B  loc_FF87CEDC\n"
"loc_FF87CDEC: B  loc_FF87CF18\n"
"loc_FF87CDF0: B  loc_FF87CF38\n"
"loc_FF87CDF4: B  loc_FF87CF30\n"
"loc_FF87CDF8: B  loc_FF87CF40\n"
"loc_FF87CDFC: B  loc_FF87CF48\n"
"loc_FF87CE00: B  loc_FF87CF50\n"
"loc_FF87CE04: B  loc_FF87CFA8\n"
"loc_FF87CE08: B  loc_FF87CFD0\n"
"loc_FF87CE0C: B  loc_FF87CFB4\n"
"loc_FF87CE10: B  loc_FF87CFC0\n"
"loc_FF87CE14: B  loc_FF87CFC8\n"
"loc_FF87CE18: B  loc_FF87CFD8\n"
"loc_FF87CE1C: B  loc_FF87CFE0\n"
"loc_FF87CE20: B  loc_FF87CFE8\n"
"loc_FF87CE24: B  loc_FF87CFF0\n"
"loc_FF87CE28: B  loc_FF87CFF8\n"
"loc_FF87CE2C: B  loc_FF87D000\n"
"loc_FF87CE30: B  loc_FF87D008\n"
"loc_FF87CE34: B  loc_FF87D010\n"
"loc_FF87CE38: B  loc_FF87D018\n"
"loc_FF87CE3C: B  loc_FF87D020\n"
"loc_FF87CE40: B  loc_FF87D02C\n"
"loc_FF87CE44: B  loc_FF87D034\n"
"loc_FF87CE48: B  loc_FF87D040\n"
"loc_FF87CE4C: B  loc_FF87D048\n"
"loc_FF87CE50: B  loc_FF87D078\n"
"loc_FF87CE54: B  loc_FF87D080\n"
"loc_FF87CE58: B  loc_FF87D088\n"
"loc_FF87CE5C: B  loc_FF87D090\n"
"loc_FF87CE60: B  loc_FF87D098\n"
"loc_FF87CE64: B  loc_FF87D0A0\n"
"loc_FF87CE68: B  loc_FF87D0AC\n"
"loc_FF87CE6C: B  loc_FF87D0E0\n"

"loc_FF87CE70:\n"
	"BL sub_FF87D6F8\n"
					"BL      shooting_expo_param_override\n"  // +
	"BL sub_FF87A530\n"
 //  this code added to avoid some incorrect behavior if overrides are used.
 //  but it can cause some unexpected side effects. In this case, remove this code!
					"MOV     R0, #0\n"
					"STR     R0, [R4,#0x24]\n"  // fixes overrides  behavior at short shutter press
 //  end of my code
	"LDR R0, [R4,#0x24]\n"
	"CMP R0, #0\n"
	"BEQ loc_FF87D0E0\n"
	"BL sub_FF87C240\n"
	"MOV R5, R0\n"
	"LDR R0, [R4,#0x24]\n"
	"CMP R0, #0\n"
	"BEQ loc_FF87CEB8\n"
	"MOV R0, #0xC\n"
	"BL sub_FF8821A4\n"
	"TST R0, #1\n"
	"STRNE R9, [R6,#0x10]\n"
	"LDRNE R0, [R5,#8]\n"
	"ORRNE R0, R0, #0x40000000\n" //
	"STRNE R0, [R5,#8]\n"
	"BNE loc_FF87D0E0\n"
"loc_FF87CEB8:\n"
	"MOV R0, R5\n"
	"BL sub_FF961C84\n"
	"MOV R0, R5\n"
	"BL sub_FF87C620\n"
	"MOV R0, R5\n"
					"BL sub_FF962520_my\n"
					//"BL sub_FF962364\n" // was sub_FF962364_my
					"BL capt_seq_hook_raw_here\n"      // +
	"TST R0, #1\n"
	"STRNE R9, [R6,#0x10]\n"
	"B loc_FF87D0E0\n"
"loc_FF87CEDC:\n"
	"LDR R0, [R4,#0x24]\n"
	"CMP R0, #0\n"
	"BNE loc_FF87CF08\n"
	"MOV R0, #0xC\n"
	"BL sub_FF8821A4\n"
	"TST R0, #1\n"
	"LDRNE	R0, [SP]\n"
	"MOVNE R1, #1\n"
	"LDRNE R2, [R0,#0xC]\n"
	"MOVNE R0, #1\n"
	"BNE loc_FF87CFA0\n"
"loc_FF87CF08:\n"
	"LDR	R0, [SP]\n"
//	"BL	sub_FF87C648\n"
					"BL	sub_FF87C698_my\n"
"loc_FF87CF10:\n"
		"STR	R7, [R4,#0x24]\n"
		"B	loc_FF87D0E0\n"
"loc_FF87CF18:\n"
		"MOV	R0, #1\n"
		"BL	sub_FF87D9A8\n"
		"LDR	R0, [R4,#0xC]\n"
		"CMP	R0, #0\n"
		"BLNE	sub_FF87E494\n"
		"B	loc_FF87D0E0\n"
"loc_FF87CF30:\n"
		"BL	sub_FF87D3A8\n"
		"B	loc_FF87CF10\n"
"loc_FF87CF38:\n"
		"BL	sub_FF87D6D8\n"
		"B	loc_FF87CF10\n"
"loc_FF87CF40:\n"
		"BL	sub_FF87D6E0\n"
		"B	loc_FF87D0E0\n"
"loc_FF87CF48:\n"
		"BL	sub_FF87D898\n"
		"B	loc_FF87CFAC\n"
"loc_FF87CF50:\n"
		"LDR	R5, [R0,#0xC]\n"
		"BL	sub_FF87D6E8\n"
		"MOV	R0, R5\n"
		"BL	sub_FF960CC8\n"
		"TST	R0, #1\n"
		"MOV	R8, R0\n"
		"BNE	loc_FF87CF90\n"
		"BL	sub_FF88F4BC\n"
		"STR	R0, [R5,#0x18]\n"
		"MOV	R0, R5\n"
		"BL	sub_FF962438\n"
		"MOV	R0, R5\n"
		"BL	sub_FF962830\n"
		"MOV	R8, R0\n"
		"LDR	R0, [R5,#0x18]\n"
		"BL	sub_FF88F6C0\n"
"loc_FF87CF90:\n"
		"BL	sub_FF87D6D8\n"
		"MOV	R2, R5\n"
		"MOV	R1, #9\n"
		"MOV	R0, R8\n"
"loc_FF87CFA0:\n"
		"BL	sub_FF87AAC4\n"
		"B	loc_FF87D0E0\n"
"loc_FF87CFA8:\n"
		"BL	sub_FF87D928\n"
"loc_FF87CFAC:\n"
		"BL	sub_FF87A530\n"
		"B	loc_FF87D0E0\n"
"loc_FF87CFB4:\n"
		"LDR	R0, [R4,#0x54]\n"
		"BL	sub_FF87DFAC\n"
		"B	loc_FF87D0E0\n"
"loc_FF87CFC0:\n"
		"BL	sub_FF87E254\n"
		"B	loc_FF87D0E0\n"
"loc_FF87CFC8:\n"
		"BL	sub_FF87E2E4\n"
		"B	loc_FF87D0E0\n"
"loc_FF87CFD0:\n"
		"BL	sub_FF87D6D8\n"
		"B	loc_FF87D0E0\n"
"loc_FF87CFD8:\n"
		"BL	sub_FF960EF4\n"
		"B	loc_FF87D0E0\n"
"loc_FF87CFE0:\n"
		"BL	sub_FF96114C\n"
		"B	loc_FF87D0E0\n"
"loc_FF87CFE8:\n"
		"BL	sub_FF9611EC\n"
		"B	loc_FF87D0E0\n"
"loc_FF87CFF0:\n"
		"BL	sub_FF961320\n"
		"B	loc_FF87D0E0\n"
"loc_FF87CFF8:\n"
		"BL	sub_FF9613F0\n"
		"B	loc_FF87D0E0\n"
"loc_FF87D000:\n"
		"MOV	R0, #0\n"
		"B	loc_FF87D024\n"
"loc_FF87D008:\n"
		"BL	sub_FF9619C8\n"
		"B	loc_FF87D0E0\n"
"loc_FF87D010:\n"
		"BL	sub_FF961A58\n"
		"B	loc_FF87D0E0\n"
"loc_FF87D018:\n"
		"BL	sub_FF961B18\n"
		"B	loc_FF87D0E0\n"
"loc_FF87D020:\n"
		"MOV	R0, #1\n"
"loc_FF87D024:\n"
		"BL	sub_FF961888\n"
		"B	loc_FF87D0E0\n"
"loc_FF87D02C:\n"
		"BL	sub_FF87DBC4\n"
		"B	loc_FF87D0E0\n"
"loc_FF87D034:\n"
		"BL	sub_FF87DC64\n"
		"BL	sub_FF87D208\n"
		"B	loc_FF87D0E0\n"
"loc_FF87D040:\n"
		"BL	sub_FF9616B0\n"
		"B	loc_FF87D0E0\n"
"loc_FF87D048:\n"
		"MOV	R2, #2\n"
		"ADD	R1, R4,	#0x6A\n"
		"MOV	R0, #0x6F\n"
		"BL	sub_FF88F32C\n"
		"TST	R0, #1\n"
		"LDRNE	R1, =0x6AB\n"
		"LDRNE	R0, =0xFF87C568\n"
		"BLNE	sub_FF81E88C\n"
		"LDRH	R0, [R4,#0x6A]\n"
		"CMP	R0, #1\n"
		"BLEQ	sub_FF9616A4\n"
		"B	loc_FF87D0E0\n"
"loc_FF87D078:\n"
		"BL	sub_FF9617DC\n"
		"B	loc_FF87D0E0\n"
"loc_FF87D080:\n"
		"BL	sub_FF87C4F8\n"
		"B	loc_FF87D0E0\n"
"loc_FF87D088:\n"
		"BL	sub_FF835E64\n"
		"B	loc_FF87D0E0\n"
"loc_FF87D090:\n"
		"BL	sub_FF8805D4\n"
		"B	loc_FF87D0E0\n"
"loc_FF87D098:\n"
		"BL	sub_FF88063C\n"
		"B	loc_FF87D0E0\n"
"loc_FF87D0A0:\n"
		"BL	sub_FF880698\n"
		"BL	sub_FF880658\n"
		"B	loc_FF87D0E0\n"
"loc_FF87D0AC:\n"
		"MOV	R0, #1\n"
		"BL	sub_FF963078\n"
		"MOV	R0, #1\n"
		"BL	sub_FF963188\n"
		"LDRH	R0, [R4,#0xA8]\n"
		"CMP	R0, #4\n"
		"BNE	loc_FF87D0E0\n"
		"BL	sub_FF88063C\n"
		"BL	sub_FF880A84\n"
		"B	loc_FF87D0E0\n"
"loc_FF87D0D4:\n"
		"LDR	R1, =0x709\n"
		"LDR	R0, =0xFF87C568\n"
		"BL	sub_FF81E88C\n"
"loc_FF87D0E0:\n"
		"LDR	R0, [SP]\n"
		"LDR	R1, [R0,#4]\n"
		"LDR	R0, [R6]\n"
		"BL	sub_FF88717C\n"
		"LDR	R5, [SP]\n"
		"LDR	R0, [R5,#8]\n"
		"CMP	R0, #0\n"
		"LDREQ	R1, =0x132\n"
		"LDREQ	R0, =0xFF87C568\n"
		"BLEQ	sub_FF81E88C\n"
		"STR	R7, [R5,#8]\n"
		"B	loc_FF87CDA4\n"

// End of function capt_seq_task
 );
} 


// correct upto here


void __attribute__((naked,noinline)) sub_FF962520_my(){

 asm volatile(
		"STMFD	SP!, {R0-R8,LR}\n"
		"MOV	R4, R0\n"
		//"BL	sub_FF9631B8\n" - WTF?
		"BL	sub_FF963374\n"
		"LDR	R1, =0xFFFFFFFF\n"  // "MVN	R1, #0\n"
		"BL	sub_FF8871B0\n"
		"LDR	R5, =0x7910\n"
		"LDR	R0, [R5,#0xC]\n"
		"CMP	R0, #0\n"
		"BNE	loc_FF962570\n"
		"MOV	R1, #1\n"
		"MOV	R0, #0\n"
		"BL	sub_FF838B60\n"
		"STR	R0, [R5,#0xC]\n"
		"MOV	R3, #0\n"
		"STR	R3, [SP]\n"  // STR     R3, [SP,#0x28+var_28]
		"LDR	R3, =0xFF961EAC\n"
		"LDR	R0, =0xFF962798\n" // prev LDR
		"MOV	R2, #0x400\n"
		"MOV	R1, #0x17\n"
		"BL	sub_FF838B2C\n"
"loc_FF962570:\n" //				; CODE XREF: _sub_FF962390__SsCaptureSeq.c__0+20j\n" get here
		"MOV	R2, #4\n"
		"ADD	R1, SP,	#8\n"
		"MOV	R0, #0x8A\n"
		"BL	sub_FF88F32C\n"
		"TST	R0, #1\n"
		"LDRNE	R1, =0x3C5\n"
		"LDRNE	R0, =0xFF962144\n"
		"BLNE	sub_FF81E88C\n"
		"LDR	R8, =0x38A20\n"
		"LDR	R7, =0x3894C\n"
		"LDRSH	R1, [R8,#0xE]\n"
		"LDR	R0, [R7,#0x9C]\n"
		"BL	sub_FF925290\n"
		"BL	sub_FF8626D0\n"
		"LDR	R3, =0x7918\n"
		"STRH	R0, [R4,#0xA4]\n"
		"SUB	R2, R3,	#4\n"
		"STRD	R2, [SP]\n" // this ok? STRD    R2, [SP,#0x28+var_28]
		"MOV	R1, R0\n"
		"LDRH	R0, [R7,#0x64]\n"
		"LDRSH	R2, [R8,#0xC]\n"
		"SUB	R3, R3,	#8\n"
		"BL	sub_FF9649D8\n"
                 "BL      wait_until_remote_button_is_released\n"
                 "BL      capt_seq_hook_set_nr\n"                     // +
                 "B       sub_FF9625CC\n"                             // continue function in firmware
//		"LDR	R0, [R4,#0x1C]\n"
//		"CMP	R0, #0\n" // get here!
//		"MOVNE	R0, #1\n"
//		"STRNE	R0, [R5]\n"
//		"LDR	R0, [R5,#4]\n"
//		"BL	sub_FF92551C\n"
//		"LDR	R0, [R5,#8]\n"
//		"BL	sub_FF8C842C\n"
//		"MOV	R0, #1\n"
//		"BL	sub_FF8C8438\n" // BX LR
//		"LDR	R0, =0xFF961F1C\n"
//		"MOV	R1, R4\n"
//		"BL	sub_FF8C8408\n"
//		"LDR	R0, [R5]\n"
//		"CMP	R0, #5\n" // get here!
//		"ADDLS	PC, PC,	R0,LSL#2\n" // badly wrong setting pc here
//                "BL     wait_until_remote_button_is_released\n"
//                "BL     capt_seq_hook_set_nr\n"                     // +
//		"B	sub_FF9626D8\n"                             // continue function in firmware , loc -> sub
 );

}





void __attribute__((naked,noinline)) sub_FF87C698_my(){
 asm volatile(
		"STMFD	SP!, {R3-R9,LR}\n"
		"LDR	R4, [R0,#0xC]\n"
		"LDR	R5, =0x3894C\n"
		"LDR	R0, [R4,#8]\n"
		"LDR	R6, =0x820A\n"
		"ORR	R0, R0,	#1\n"
		"STR	R0, [R4,#8]\n"
		"LDRH	R0, [R5]\n"
		"LDR	R8, =0x2D50\n"
		"MOV	R7, #0\n"
		"CMP	R0, R6\n"
		"BEQ	loc_FF87C73C\n"
		"LDRH	R0, [R5,#0xA6]\n"
		"CMP	R0, #3\n"
		"BEQ	loc_FF87C79C\n" //
		"LDR	R0, [R4,#0xC]\n"
		"CMP	R0, #1\n"
		"BLS	loc_FF87C748\n"
		"LDRH	R0, [R5,#0xA4]\n"
		"CMP	R0, #0\n"
		"BNE	loc_FF87C79C\n"
		"LDRH	R0, [R5,#0xA0]\n"
		"CMP	R0, #2\n"
		"BNE	loc_FF87C754\n"
		"BL	sub_FF87DD14\n"
		"LDRH	R0, [R5]\n"
		"CMP	R0, R6\n"
		"BEQ	loc_FF87C73C\n"
		"LDRH	R0, [R5,#0xA6]\n"
		"CMP	R0, #3\n"
		"BEQ	loc_FF87C79C\n"
		"LDR	R0, [R4,#0xC]\n"
		"CMP	R0, #1\n"
		"BLS	loc_FF87C748\n"
		"LDRH	R0, [R5,#0xA4]\n"
		"CMP	R0, #0\n"
		"BNE	loc_FF87C79C\n"
		"LDRH	R0, [R5,#0xA0]\n"
		"CMP	R0, #2\n"
		"BEQ	loc_FF87C780\n"
		"B	loc_FF87C754\n"
"loc_FF87C73C:\n" //				; CODE XREF: sub_FF87C648+2Cj\n"
		"LDRH	R0, [R5,#0xA6]\n"
		"CMP	R0, #3\n"
		"BEQ	loc_FF87C79C\n"
"loc_FF87C748:\n" //				; CODE XREF: sub_FF87C648+44j\n"
		"LDRH	R0, [R5,#0xA4]\n"
		"CMP	R0, #0\n"
		"BNE	loc_FF87C79C\n"
"loc_FF87C754:\n" //				; CODE XREF: sub_FF87C648+5Cj\n"
		"LDRH	R0, [R5,#0xA0]\n"
		"CMP	R0, #1\n"
		"BNE	loc_FF87C79C\n"
		"LDRH	R0, [R5]\n"
		"CMP	R0, R6\n"
		"LDRNE	R0, [R4,#0xC]\n"
		"CMPNE	R0, #1\n"
		"BLS	loc_FF87C79C\n"
		"LDR	R0, [R4,#0x10]\n"
		"CMP	R0, #1\n"
		"BNE	loc_FF87C79C\n"
"loc_FF87C780:\n" //				; CODE XREF: sub_FF87C648+9Cj\n"
		"LDR	R3, =0x269\n"
		"LDR	R2, =0xEA60\n"
		"STR	R3, [SP]\n"
		"LDR	R0, [R8]\n"
		"LDR	R3, =0xFF87C568\n" // copied from above ; "SsShootTask.c"\n" // adr
		"MOV	R1, #0x40000000\n"
		"BL	sub_FF882524\n"
"loc_FF87C79C:\n" //				; CODE XREF: sub_FF87C648+38j\n"
		"BL	sub_FF87C4F8\n"
		"LDR	R0, [R5,#0x24]\n"
		"CMP	R0, #0\n"
		"MOVEQ	R0, #2\n"
		"BLEQ	sub_FF8761A4\n"
		"BL	sub_FF87D6E8\n"
		"LDR	R0, [R5,#0x24]\n"
		"CMP	R0, #0\n"
		"BNE	loc_FF87C868\n"
		"MOV	R0, #0\n"
		"BL	sub_FF963078\n"
		"MOV	R0, #0\n"
		"BL	sub_FF963188\n"
		"MOV	R0, R4\n"
		"BL	sub_FF961C84\n"
		"MOV	R0, R4\n"
		"BL	sub_FF87DB40\n"
		"MOV	R0, R4\n"
		"BL	sub_FF96087C\n"
		"CMP	R0, #0\n"
		"BEQ	loc_FF87C81C\n" //changed
		"BL	sub_FF9630B8\n"
		"BL	sub_FF9631CC\n"
		"BL	sub_FF96321C\n"
		"MOV	R0, R4\n"
		"BL	sub_FF9609F4\n"
		"TST	R0, #1\n"
		"MOVNE	R2, R4\n"
		"LDMNEFD	SP!, {R3-R9,LR}\n"
		"MOVNE	R1, #1\n"
		"BNE	sub_FF87AAC4\n"
		"B	loc_FF87C844\n"
"loc_FF87C81C:\n" //				; CODE XREF: sub_FF87C648+154j\n"
		"LDR	R0, [R5,#0xC]\n"
		"CMP	R0, #0\n"
		"BEQ	loc_FF87C830\n"
		"BL	sub_FF87E418\n"
		"BL	sub_FF877A74\n"
"loc_FF87C830:\n" //				; CODE XREF: sub_FF87C648+18Cj\n"
		"MOV	R0, R4\n"
		"BL	sub_FF960960\n"
		"BL	sub_FF9630B8\n" //changed
		"BL	sub_FF9631CC\n" // changed
		"BL	sub_FF96321C\n" // changed
"loc_FF87C844:\n" //				; CODE XREF: sub_FF87C648+180j\n"
		"MOV	R0, R4\n"
		"BL	sub_FF87C620\n"
		"MOV	R0, R4\n"
		"BL	sub_FF962438\n" //changed
		"BL	sub_FF962EB0\n" // changed
		"MOV	R0, R4\n"
					"BL	sub_FF962520_my\n" //changed
		"MOV	R7, R0\n"
					"BL      capt_seq_hook_raw_here\n"      // +
		"B	loc_FF87C874\n"
"loc_FF87C868:\n" //				; CODE XREF: sub_FF87C648+124j\n"
		"LDR	R0, [R8,#0x10]\n"
		"CMP	R0, #0\n"
		"MOVNE	R7, #0x1D\n"
"loc_FF87C874:\n" //				; CODE XREF: sub_FF87C648+1CCj\n"
		"BL	sub_FF88063C\n"
		"BL	sub_FF880684\n"
		"BL	sub_FF8806C4\n"
		"MOV	R2, R4\n"
		"MOV	R1, #1\n"
		"MOV	R0, R7\n"
		"BL	sub_FF87AAC4\n"
		"BL	sub_FF9627D4\n" //changed
		"CMP	R0, #0\n"
		"LDRNE	R0, [R4,#8]\n"
		"ORRNE	R0, R0,	#0x2000\n"
		"STRNE	R0, [R4,#8]\n"
		"LDR	R0, [R4,#0x1C]\n"
		"CMP	R0, #0\n"
		"BLNE	sub_FF877A8C\n"
		"LDRH	R0, [R5,#0xA6]\n"
		"CMP	R0, #3\n"
		"BEQ	LOCRET_FF87C8D8\n"
		"LDRH	R0, [R5,#0xA4]\n"
		"CMP	R0, #0\n"
		"LDREQH	R0, [R5,#0xA0]\n"
		"CMPEQ	R0, #2\n"
		"MOVEQ	R0, R4\n"
		"LDMEQFD	SP!, {R3-R9,LR}\n"
		"BEQ	sub_FF87DD68\n"
"LOCRET_FF87C8D8:\n" //				; CODE XREF: sub_FF87C648+220j\n"
		"LDMFD	SP!, {R3-R9,PC}\n"

 );
}




/*************************************************************/
void __attribute__((naked,noinline)) exp_drv_task(){

//blinko();

 asm volatile(
		"STMFD	SP!, {R4-R8,LR}\n"
		"SUB	SP, SP,	#0x20\n"
		"LDR	R8, =0xBB8\n"
		"LDR	R7, =0x4658\n"
		"LDR	R5, =0x3D90C\n"
		"MOV	R0, #0\n"
		"ADD	R6, SP,	#0x10\n"
		"STR	R0, [SP,#0xC]\n"
"loc_FF8C14A0:\n" //				; CODE XREF: task_ExpDrvTask+5B8j\n"
		"LDR	R0, [R7,#0x20]\n"
		"MOV	R2, #0\n"
		"ADD	R1, SP,	#0x1C\n"
		"BL	sub_FF838318\n"
		"LDR	R0, [SP,#0xC]\n"
		"CMP	R0, #1\n"
		"BNE	loc_FF8C14EC\n"
		"LDR	R0, [SP,#0x1C]\n"
		"LDR	R0, [R0]\n"
		"CMP	R0, #0x13\n"
		"CMPNE	R0, #0x14\n"
		"CMPNE	R0, #0x15\n"
		"CMPNE	R0, #0x16\n"
		"BEQ	loc_FF8C1608\n"
		"CMP	R0, #0x28\n"
		"BEQ	loc_FF8C15E0\n"
		"ADD	R1, SP,	#0xC\n"
		"MOV	R0, #0\n"
		"BL	sub_FF8C1430\n"
"loc_FF8C14EC:\n" //				; CODE XREF: task_ExpDrvTask+38j\n"
		"LDR	R0, [SP,#0x1C]\n"
		"LDR	R1, [R0]\n"
		"CMP	R1, #0x2D\n"
		"BNE	loc_FF8C151C\n"
		"LDR	R0, [SP,#0x1C]\n"
		"BL	sub_FF8C26E8\n"
		"LDR	R0, [R7,#0x1C]\n"
		"MOV	R1, #1\n"
		"BL	sub_FF88717C\n"
		"BL	sub_FF81E844\n"
		"ADD	SP, SP,	#0x20\n"
		"LDMFD	SP!, {R4-R8,PC}\n"
"loc_FF8C151C:\n" //				; CODE XREF: task_ExpDrvTask+78j\n"
		"CMP	R1, #0x2C\n"
		"BNE	loc_FF8C1538\n"
		"LDR	R2, [R0,#0x8C]!\n"
		"LDR	R1, [R0,#4]\n"
		"MOV	R0, R1\n"
		"BLX	R2\n"
		"B	loc_FF8C1A30\n"
"loc_FF8C1538:\n" //				; CODE XREF: task_ExpDrvTask+A0j\n"
		"CMP	R1, #0x26\n"
		"BNE	loc_FF8C1588\n"
		"LDR	R0, [R7,#0x1C]\n"
		"MOV	R1, #0x80\n"
		"BL	sub_FF8871B0\n"
		"LDR	R0, =0xFF8BDBBC\n"
		"MOV	R1, #0x80\n"
		"BL	sub_FF9518AC\n"
		"LDR	R0, [R7,#0x1C]\n"
		"MOV	R2, R8\n"
		"MOV	R1, #0x80\n"
		"BL	sub_FF8870BC\n"
		"TST	R0, #1\n"
		"LDRNE	R1, =0xE54\n"
		"BNE	loc_FF8C15CC\n"
"loc_FF8C1574:\n" //				; CODE XREF: task_ExpDrvTask+144j\n"
		"LDR	R1, [SP,#0x1C]\n"
		"LDR	R0, [R1,#0x90]\n"
		"LDR	R1, [R1,#0x8C]\n"
		"BLX	R1\n"
		"B	loc_FF8C1A30\n"
"loc_FF8C1588:\n" //				; CODE XREF: task_ExpDrvTask+BCj\n"
		"CMP	R1, #0x27\n"
		"BNE	loc_FF8C15D8\n"
		"ADD	R1, SP,	#0xC\n"
		"BL	sub_FF8C1430\n"
		"LDR	R0, [R7,#0x1C]\n"
		"MOV	R1, #0x100\n"
		"BL	sub_FF8871B0\n"
		"LDR	R0, =0xFF8BDBCC\n"
		"MOV	R1, #0x100\n"
		"BL	sub_FF952238\n"
		"LDR	R0, [R7,#0x1C]\n"
		"MOV	R2, R8\n"
		"MOV	R1, #0x100\n"
		"BL	sub_FF8870BC\n"
		"TST	R0, #1\n"
		"BEQ	loc_FF8C1574\n"
		"LDR	R1, =0xE5E\n"
"loc_FF8C15CC:\n" //				; CODE XREF: task_ExpDrvTask+F0j\n"
		"LDR	R0, =0xFF8BE1E0\n"
		"BL	sub_FF81E88C\n"
		"B	loc_FF8C1574\n"
"loc_FF8C15D8:\n" //				; CODE XREF: task_ExpDrvTask+10Cj\n"
		"CMP	R1, #0x28\n"
		"BNE	loc_FF8C15F0\n"
"loc_FF8C15E0:\n" //				; CODE XREF: task_ExpDrvTask+5Cj\n"
		"LDR	R0, [SP,#0x1C]\n"
		"ADD	R1, SP,	#0xC\n"
		"BL	sub_FF8C1430\n"
		"B	loc_FF8C1574\n"
"loc_FF8C15F0:\n" //				; CODE XREF: task_ExpDrvTask+15Cj\n"
		"CMP	R1, #0x2B\n"
		"BNE	loc_FF8C1608\n"
		"BL	sub_FF8B180C\n"
		"BL	sub_FF8B2430\n"
		"BL	sub_FF8B1F84\n"
		"B	loc_FF8C1574\n"
"loc_FF8C1608:\n" //				; CODE XREF: task_ExpDrvTask+54j\n"
		"LDR	R0, [SP,#0x1C]\n"
		"MOV	R4, #1\n"
		"LDR	R1, [R0]\n"
		"CMP	R1, #0x11\n"
		"CMPNE	R1, #0x12\n"
		"BNE	loc_FF8C1678\n"
		"LDR	R1, [R0,#0x7C]\n"
		"ADD	R1, R1,	R1,LSL#1\n"
		"ADD	R1, R0,	R1,LSL#2\n"
		"SUB	R1, R1,	#8\n"
		"LDMIA	R1, {R2-R4}\n"
		"STMIA	R6, {R2-R4}\n"
		"BL	sub_FF8BFD98\n" // loc -> sub
		"LDR	R0, [SP,#0x1C]\n"
		"LDR	R1, [R0,#0x7C]\n"
		"LDR	R3, [R0,#0x8C]\n"
		"LDR	R2, [R0,#0x90]\n"
		"ADD	R0, R0,	#4\n"
		"BLX	R3\n"
		"LDR	R0, [SP,#0x1C]\n"
		"BL	sub_FF8C2AAC\n"
		"LDR	R0, [SP,#0x1C]\n"
		"LDR	R1, [R0,#0x7C]\n"
		"LDR	R3, [R0,#0x94]\n"
		"LDR	R2, [R0,#0x98]\n"
		"ADD	R0, R0,	#4\n"
		"BLX	R3\n"
		"B	loc_FF8C1970\n"
"loc_FF8C1678:\n" //				; CODE XREF: task_ExpDrvTask+19Cj\n"
		"CMP	R1, #0x13\n"
		"CMPNE	R1, #0x14\n"
		"CMPNE	R1, #0x15\n"
		"CMPNE	R1, #0x16\n"
		"BNE	loc_FF8C1730\n"
		"ADD	R3, SP,	#0xC\n"
		"MOV	R2, SP\n"
		"ADD	R1, SP,	#0x10\n"
		"BL	sub_FF8C0080\n"
		"CMP	R0, #1\n"
		"MOV	R4, R0\n"
		"CMPNE	R4, #5\n"
		"BNE	loc_FF8C16CC\n"
		"LDR	R0, [SP,#0x1C]\n"
		"MOV	R2, R4\n"
		"LDR	R1, [R0,#0x7C]!\n"
		"LDR	R12, [R0,#0x10]!\n"
		"LDR	R3, [R0,#4]\n"
		"MOV	R0, SP\n"
		"BLX	R12\n"
		"B	loc_FF8C1704\n"
"loc_FF8C16CC:\n" //				; CODE XREF: task_ExpDrvTask+228j\n"
		"LDR	R0, [SP,#0x1C]\n"
		"CMP	R4, #2\n"
		"LDR	R3, [R0,#0x90]\n"
		"CMPNE	R4, #6\n"
		"BNE	loc_FF8C1718\n"
		"LDR	R12, [R0,#0x8C]\n"
		"MOV	R0, SP\n"
		"MOV	R2, R4\n"
		"MOV	R1, #1\n"
		"BLX	R12\n"
		"LDR	R0, [SP,#0x1C]\n"
		"MOV	R2, SP\n"
		"ADD	R1, SP,	#0x10\n"
		"BL	sub_FF8C1138\n"
"loc_FF8C1704:\n" //				; CODE XREF: task_ExpDrvTask+248j\n"
		"LDR	R0, [SP,#0x1C]\n"
		"LDR	R2, [SP,#0xC]\n"
		"MOV	R1, R4\n"
		"BL	sub_FF8C13D0\n"
		"B	loc_FF8C1970\n"
"loc_FF8C1718:\n" //				; CODE XREF: task_ExpDrvTask+25Cj\n"
		"LDR	R1, [R0,#0x7C]\n"
		"LDR	R12, [R0,#0x8C]\n"
		"ADD	R0, R0,	#4\n"
		"MOV	R2, R4\n"
		"BLX	R12\n"
		"B	loc_FF8C1970\n"
"loc_FF8C1730:\n" //				; CODE XREF: task_ExpDrvTask+208j\n"
		"CMP	R1, #0x22\n"
		"CMPNE	R1, #0x23\n"
		"BNE	loc_FF8C177C\n"
		"LDR	R1, [R0,#0x7C]\n"
		"ADD	R1, R1,	R1,LSL#1\n"
		"ADD	R1, R0,	R1,LSL#2\n"
		"SUB	R1, R1,	#8\n"
		"LDMIA	R1, {R2-R4}\n"
		"STMIA	R6, {R2-R4}\n"
		"BL	sub_FF8BF2DC\n"
		"LDR	R0, [SP,#0x1C]\n"
		"LDR	R1, [R0,#0x7C]\n"
		"LDR	R3, [R0,#0x8C]\n"
		"LDR	R2, [R0,#0x90]\n"
		"ADD	R0, R0,	#4\n"
		"BLX	R3\n"
		"LDR	R0, [SP,#0x1C]\n"
		"BL	sub_FF8BF5DC\n"
		"B	loc_FF8C1970\n"
"loc_FF8C177C:\n" //				; CODE XREF: task_ExpDrvTask+2B8j\n"
		"ADD	R1, R0,	#4\n"
		"LDMIA	R1, {R2,R3,R12}\n"
		"STMIA	R6, {R2,R3,R12}\n"
		"LDR	R1, [R0]\n"
		"CMP	R1, #0x25\n"
		"ADDLS	PC, PC,	R1,LSL#2\n"
		"B	loc_FF8C1950\n" 


"loc_FF8C1798:\n"
"B	loc_FF8C1830\n"
"loc_FF8C179C:\n"
"B	loc_FF8C1830\n"
"loc_FF8C17A0:\n"
"B	loc_FF8C1838\n"
"loc_FF8C17A4:\n"
"B	loc_FF8C1840\n"
"loc_FF8C17A8:\n"
"B	loc_FF8C1840\n"
"loc_FF8C17AC:\n"
"B	loc_FF8C1840\n"
"loc_FF8C17B0:\n"
"B	loc_FF8C1830\n"
"loc_FF8C17B4:\n"
"B	loc_FF8C1838\n"
"loc_FF8C17B8:\n"
"B	loc_FF8C1840\n"
"loc_FF8C17BC:\n"
"B	loc_FF8C1840\n"
"loc_FF8C17C0:\n"
"B	loc_FF8C1858\n"
"loc_FF8C17C4:\n"
"B	loc_FF8C1858\n"
"loc_FF8C17C8:\n"
"B	loc_FF8C1944\n"
"loc_FF8C17CC:\n"
"B	loc_FF8C194C\n"
"loc_FF8C17D0:\n"
"B	loc_FF8C194C\n"
"loc_FF8C17D4:\n"
"B	loc_FF8C194C\n"
"loc_FF8C17D8:\n"
"B	loc_FF8C194C\n"
"loc_FF8C17DC:\n"
"B	loc_FF8C1950\n"
"loc_FF8C17E0:\n"
"B	loc_FF8C1950\n"
"loc_FF8C17E4:\n"
"B	loc_FF8C1950\n"
"loc_FF8C17E8:\n"
"B	loc_FF8C1950\n"
"loc_FF8C17EC:\n"
"B	loc_FF8C1950\n"
"loc_FF8C17F0:\n"
"B	loc_FF8C1950\n"
"loc_FF8C17F4:\n"
"B	loc_FF8C1848\n"
"loc_FF8C17F8:\n"
"B	loc_FF8C1850\n"
"loc_FF8C17FC:\n"
"B	loc_FF8C1850\n"
"loc_FF8C1800:\n"
"B	loc_FF8C1864\n"
"loc_FF8C1804:\n"
"B	loc_FF8C1864\n"
"loc_FF8C1808:\n"
"B	loc_FF8C186C\n"
"loc_FF8C180C:\n"
"B	loc_FF8C189C\n"
"loc_FF8C1810:\n"
"B	loc_FF8C18CC\n"
"loc_FF8C1814:\n"
"B	loc_FF8C18FC\n"
"loc_FF8C1818:\n"
"B	loc_FF8C192C\n"
"loc_FF8C181C:\n"
"B	loc_FF8C192C\n"
"loc_FF8C1820:\n"
"B	loc_FF8C1950\n"
"loc_FF8C1824:\n"
"B	loc_FF8C1950\n"
"loc_FF8C1828:\n"
"B	loc_FF8C1934\n"
"loc_FF8C182C:\n"
"B	loc_FF8C193C\n"


"loc_FF8C1830:\n" //				; CODE XREF: task_ExpDrvTask+310j\n"
		"BL	sub_FF8BE0D4\n"
		"B	loc_FF8C1950\n"
"loc_FF8C1838:\n" //				; CODE XREF: task_ExpDrvTask+310j\n"
		"BL	sub_FF8BE35C\n"
		"B	loc_FF8C1950\n"
"loc_FF8C1840:\n" //				; CODE XREF: task_ExpDrvTask+310j\n"
		"BL	sub_FF8BE564\n"
		"B	loc_FF8C1950\n"
"loc_FF8C1848:\n" //				; CODE XREF: task_ExpDrvTask+310j\n"
		"BL	sub_FF8BE7DC\n"
		"B	loc_FF8C1950\n"
"loc_FF8C1850:\n" //				; CODE XREF: task_ExpDrvTask+310j\n"
		"BL	sub_FF8BE9D4\n"
		"B	loc_FF8C1950\n"
"loc_FF8C1858:\n" //				; CODE XREF: task_ExpDrvTask+310j\n"
//		"BL	sub_FF8BEC90\n"
		"BL	sub_FF8BEC90_my\n" // ---->
		"MOV	R4, #0\n"
		"B	loc_FF8C1950\n"
"loc_FF8C1864:\n" //				; CODE XREF: task_ExpDrvTask+310j\n"
		"BL	sub_FF8BEDD0\n"
		"B	loc_FF8C1950\n"
"loc_FF8C186C:\n" //				; CODE XREF: task_ExpDrvTask+310j\n"
		"LDRH	R1, [R0,#4]\n"
		"STRH	R1, [SP,#0x10]\n"
		"LDRH	R1, [R5,#2]\n"
		"STRH	R1, [SP,#0x12]\n"
		"LDRH	R1, [R5,#4]\n"
		"STRH	R1, [SP,#0x14]\n"
		"LDRH	R1, [R5,#6]\n"
		"STRH	R1, [SP,#0x16]\n"
		"LDRH	R1, [R0,#0xC]\n"
		"STRH	R1, [SP,#0x18]\n"
		"BL	sub_FF8C275C\n"
		"B	loc_FF8C1950\n"
"loc_FF8C189C:\n" //				; CODE XREF: task_ExpDrvTask+310j\n"
		"LDRH	R1, [R0,#4]\n"
		"STRH	R1, [SP,#0x10]\n"
		"LDRH	R1, [R5,#2]\n"
		"STRH	R1, [SP,#0x12]\n"
		"LDRH	R1, [R5,#4]\n"
		"STRH	R1, [SP,#0x14]\n"
		"LDRH	R1, [R5,#6]\n"
		"STRH	R1, [SP,#0x16]\n"
		"LDRH	R1, [R5,#8]\n"
		"STRH	R1, [SP,#0x18]\n"
		"BL	sub_FF8C28C4\n"
		"B	loc_FF8C1950\n"
"loc_FF8C18CC:\n" //				; CODE XREF: task_ExpDrvTask+310j\n"
		"LDRH	R1, [R5]\n"
		"STRH	R1, [SP,#0x10]\n"
		"LDRH	R1, [R0,#6]\n"
		"STRH	R1, [SP,#0x12]\n"
		"LDRH	R1, [R5,#4]\n"
		"STRH	R1, [SP,#0x14]\n"
		"LDRH	R1, [R5,#6]\n"
		"STRH	R1, [SP,#0x16]\n"
		"LDRH	R1, [R5,#8]\n"
		"STRH	R1, [SP,#0x18]\n"
		"BL	sub_FF8C2970\n"
		"B	loc_FF8C1950\n"
"loc_FF8C18FC:\n" //				; CODE XREF: task_ExpDrvTask+310j\n"
		"LDRH	R1, [R5]\n"
		"STRH	R1, [SP,#0x10]\n"
		"LDRH	R1, [R5,#2]\n"
		"STRH	R1, [SP,#0x12]\n"
		"LDRH	R1, [R5,#4]\n"
		"STRH	R1, [SP,#0x14]\n"
		"LDRH	R1, [R5,#6]\n"
		"STRH	R1, [SP,#0x16]\n"
		"LDRH	R1, [R0,#0xC]\n"
		"STRH	R1, [SP,#0x18]\n"
		"BL	sub_FF8C2A10\n"
		"B	loc_FF8C1950\n"
"loc_FF8C192C:\n" //				; CODE XREF: task_ExpDrvTask+310j\n"
		"BL	sub_FF8BF118\n"
		"B	loc_FF8C1950\n"
"loc_FF8C1934:\n" //				; CODE XREF: task_ExpDrvTask+310j\n"
		"BL	sub_FF8BF6E0\n"
		"B	loc_FF8C1950\n"
"loc_FF8C193C:\n" //				; CODE XREF: task_ExpDrvTask+310j\n"
		"BL	sub_FF8BF91C\n"
		"B	loc_FF8C1950\n"
"loc_FF8C1944:\n" //				; CODE XREF: task_ExpDrvTask+310j\n"
		"BL	sub_FF8BFA98\n"
		"B	loc_FF8C1950\n"
"loc_FF8C194C:\n" //				; CODE XREF: task_ExpDrvTask+310j\n"
		"BL	sub_FF8BFC34\n"
"loc_FF8C1950:\n" //				; CODE XREF: task_ExpDrvTask+310j\n"
		"LDR	R0, [SP,#0x1C]\n"
		"LDR	R1, [R0,#0x7C]\n"
		"LDR	R3, [R0,#0x8C]\n"
		"LDR	R2, [R0,#0x90]\n"
		"ADD	R0, R0,	#4\n"
		"BLX	R3\n"
		"CMP	R4, #1\n"
		"BNE	loc_FF8C19B8\n"
"loc_FF8C1970:\n" //				; CODE XREF: task_ExpDrvTask+1F4j\n"
		"LDR	R0, [SP,#0x1C]\n"
		"MOV	R2, #0xC\n"
		"LDR	R1, [R0,#0x7C]\n"
		"ADD	R1, R1,	R1,LSL#1\n"
		"ADD	R0, R0,	R1,LSL#2\n"
		"SUB	R4, R0,	#8\n"
		"LDR	R0, =0x3D90C\n" // changed from 3D8EC
		"ADD	R1, SP,	#0x10\n"
		"BL	sub_FFB36870\n"
		"LDR	R0, =0x3D918\n" // changed from 3D8F8
		"MOV	R2, #0xC\n"
		"ADD	R1, SP,	#0x10\n"
		"BL	sub_FFB36870\n"
		"LDR	R0, =0x3D924\n" // changed from 3D904
		"MOV	R2, #0xC\n"
		"MOV	R1, R4\n"
		"BL	sub_FFB36870\n"
		"B	loc_FF8C1A30\n"
"loc_FF8C19B8:\n" //				; CODE XREF: task_ExpDrvTask+4ECj\n"
		"LDR	R0, [SP,#0x1C]\n"
		"LDR	R0, [R0]\n"
		"CMP	R0, #0xB\n"
		"BNE	loc_FF8C1A00\n"
		"MOV	R3, #0\n"
		"STR	R3, [SP]\n"
		"MOV	R3, #1\n"
		"MOV	R2, #1\n"
		"MOV	R1, #1\n"
		"MOV	R0, #0\n"
		"BL	sub_FF8BDEDC\n"
		"MOV	R3, #0\n"
		"STR	R3, [SP]\n"
		"MOV	R3, #1\n"
		"MOV	R2, #1\n"
		"MOV	R1, #1\n"
		"MOV	R0, #0\n"
		"B	loc_FF8C1A2C\n"
"loc_FF8C1A00:\n" //				; CODE XREF: task_ExpDrvTask+544j\n"
		"MOV	R3, #1\n"
		"MOV	R2, #1\n"
		"MOV	R1, #1\n"
		"MOV	R0, #1\n"
		"STR	R3, [SP]\n"
		"BL	sub_FF8BDEDC\n"
		"MOV	R3, #1\n"
		"MOV	R2, #1\n"
		"MOV	R1, #1\n"
		"MOV	R0, #1\n"
		"STR	R3, [SP]\n"
"loc_FF8C1A2C:\n" //				; CODE XREF: task_ExpDrvTask+57Cj\n"
		"BL	sub_FF8BE01C\n"
"loc_FF8C1A30:\n" //				; CODE XREF: task_ExpDrvTask+B4j\n"
		"LDR	R0, [SP,#0x1C]\n"
		"BL	sub_FF8C26E8\n"
		"B	loc_FF8C14A0\n"
//; End of function task_ExpDrvTask\n"

 );
}


void __attribute__((naked,noinline)) sub_FF8BEC90_my(){

 asm volatile(
		"STMFD	SP!, {R4-R8,LR}\n"
		"LDR	R7, =0x4658\n"
		"MOV	R4, R0\n"
		"LDR	R0, [R7,#0x1C]\n"
		"MOV	R1, #0x3E\n"
		"BL	sub_FF8871B0\n"
		"LDRSH	R0, [R4,#4]\n"
		"MOV	R2, #0\n"
		"MOV	R1, #0\n"
		"BL	sub_FF8BDC40\n"
		"MOV	R6, R0\n"
		"LDRSH	R0, [R4,#6]\n"
		"BL	sub_FF8BDD50\n"
		"LDRSH	R0, [R4,#8]\n"
		"BL	sub_FF8BDDA8\n"
		"LDRSH	R0, [R4,#0xA]\n"
		"BL	sub_FF8BDE00\n"
		"LDRSH	R0, [R4,#0xC]\n"
		"MOV	R1, #0\n"
		"BL	sub_FF8BDE58\n"
		"MOV	R5, R0\n"
		"LDR	R0, [R4]\n"
		"LDR	R8, =0x3D924\n" // changed from 3D904
		"CMP	R0, #0xB\n"
		"MOVEQ	R6, #0\n"
		"MOVEQ	R5, #0\n"
		"BEQ	loc_FF8BED24\n"
		"CMP	R6, #1\n"
		"BNE	loc_FF8BED24\n"
		"LDRSH	R0, [R4,#4]\n"
		"LDR	R1, =0xFF8BDBAC\n"
		"MOV	R2, #2\n"
		"BL	sub_FF951BF4\n"
		"STRH	R0, [R4,#4]\n"
		"MOV	R0, #0\n"
		"STR	R0, [R7,#0x28]\n"
		"B	loc_FF8BED2C\n" 

"loc_FF8BED24:\n" //				; CODE XREF: _sub_FF8BEC50__ExpDrv.c__2+68j\n"
		"LDRH	R0, [R8]\n"
		"STRH	R0, [R4,#4]\n"
"loc_FF8BED2C:\n" //				; CODE XREF: _sub_FF8BEC50__ExpDrv.c__2+90j\n"
		"CMP	R5, #1\n"
		"LDRNEH	R0, [R8,#8]\n"
		"BNE	loc_FF8BED48\n"
		"LDRSH	R0, [R4,#0xC]\n"
		"LDR	R1, =0xFF8BDC30\n"
		"MOV	R2, #0x20\n"
		"BL	sub_FF8C2718\n"
"loc_FF8BED48:\n" //				; CODE XREF: _sub_FF8BEC50__ExpDrv.c__2+A4j\n"
		"STRH	R0, [R4,#0xC]\n"
		"LDRSH	R0, [R4,#6]\n"
		"BL	sub_FF8B157C_my\n"
		"LDRSH	R0, [R4,#8]\n"
		"MOV	R1, #1\n"
		"BL	sub_FF8B1CCC\n"
		"MOV	R1, #0\n"
		"ADD	R0, R4,	#8\n"
		"BL	sub_FF8B1D54\n"
		"LDRSH	R0, [R4,#0xE]\n"
		"BL	sub_FF8B96F8\n"
		"LDR	R4, =0xBB8\n"
		"CMP	R6, #1\n"
		"BNE	loc_FF8BEDA0\n"
		"LDR	R0, [R7,#0x1C]\n"
		"MOV	R2, R4\n"
		"MOV	R1, #2\n"
		"BL	sub_FF8870BC\n"
		"TST	R0, #1\n"
		"SUBNE	R1, R4,	#0x620\n"
		"LDRNE	R0, =0xFF8BE230\n"
		"BLNE	sub_FF81E88C\n"
"loc_FF8BEDA0:\n" //				; CODE XREF: _sub_FF8BEC50__ExpDrv.c__2+ECj\n"
		"CMP	R5, #1\n"
		"LDMNEFD	SP!, {R4-R8,PC}\n"
		"LDR	R0, [R7,#0x1C]\n"
		"MOV	R2, R4\n"
		"MOV	R1, #0x20\n"
		"BL	sub_FF8870BC\n"
		"TST	R0, #1\n"
		"LDRNE	R1, =0x59D\n"
		"LDRNE	R0, =0xFF8BE230\n"
		"LDMNEFD	SP!, {R4-R8,LR}\n"
		"BNE	sub_FF81E88C\n"
		"LDMFD	SP!, {R4-R8,PC}\n"
//; End of function _sub_FF8BEC50__ExpDrv.c__2\n" 
 );
}

void __attribute__((naked,noinline)) sub_FF8B157C_my(){

 asm volatile(
		"STMFD	SP!, {R4-R6,LR}\n"
		"LDR	R5, =0x4370\n"
		"MOV	R4, R0\n"
		"LDR	R0, [R5,#4]\n"
		"CMP	R0, #1\n"
		"LDRNE	R1, =0x146\n"
		"LDRNE	R0, =0xFF8B1380\n"
		"BLNE	sub_FF81E88C\n"
		"CMN	R4, #0xC00\n"
		"LDREQSH	R4, [R5,#2]\n"
		"CMN	R4, #0xC00\n"
		"MOVEQ	R1, #0x14C\n"
		"LDREQ	R0, =0xFF8B1380\n"
		"STRH	R4, [R5,#2]\n"
		"BLEQ	sub_FF81E88C\n"
		"MOV	R0, R4\n"
//		"BL	sub_FFA080B8\n"
		"BL	apex2us\n"
		"MOV	R4, R0\n"
//		"BL	nullsub_59\n"
		"MOV	R0, R4\n"
		"BL	sub_FF8F3358\n"
		"TST	R0, #1\n"
		"LDRNE	R1, =0x151\n"
		"LDMNEFD	SP!, {R4-R6,LR}\n"
		"LDRNE	R0, =0xFF8B1380\n"
		"BNE	sub_FF81E88C\n"
		"LDMFD	SP!, {R4-R6,PC}\n" 
// End of function sub_FF89D14C
 );
}