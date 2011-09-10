#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "stdlib.h"

static long *nrflag = (long*)(0x8A64 + 0x8 );  // 0x8A64 (  @FF195C0C ) + 8 (@FF195C48)
#define NR_AUTO (0)							// have to explictly reset value back to 0 to enable auto
#define PAUSE_FOR_FILE_COUNTER 100          // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated
#include "../../../generic/capt_seq.c"

//SX230 @FF078BF0 
void __attribute__((naked,noinline)) capt_seq_task() {
 asm volatile (
//"sub_FF078BF0\n"
					 
		"STMFD	SP!, {R3-R9,LR}\n"
		"LDR	R5, =0x3EFA4\n"
		"LDR	R7, =0x3EF4\n"
		"MOV	R6, #0\n"
"loc_FF078C00:\n"
		"LDR	R0, [R7,#4]\n"
		"MOV	R2, #0\n"
		"MOV	R1, SP\n"
		"BL		sub_FF02B184\n"
		"TST	R0, #1\n"
		"BEQ	loc_FF078C2C\n"
		"LDR	R1, =0x47A\n"
		"LDR	R0, =0xFF07861C\n"		//"SsShootTask.c"
		"BL		sub_FF00EC88\n"			//assert
		"BL		sub_FF00EC40\n"			//ExitTask
		"LDMFD	SP!, {R3-R9,PC}\n"
"loc_FF078C2C:\n"
		"LDR	R0, [SP]\n"
		"LDR	R1, [R0]\n"
		"CMP	R1, #0x27\n"
		"ADDCC	PC, PC,	R1,LSL#2\n"
		"B	loc_FF078EAC\n"
"loc_FF078C40:\n"
		"B	loc_FF078CDC\n"
"loc_FF078C44:\n"
		"B	loc_FF078CF4\n"
"loc_FF078C48:\n"
		"B	loc_FF078D2C\n"
"loc_FF078C4C:\n"
		"B	loc_FF078D40\n"
"loc_FF078C50:\n"
		"B	loc_FF078D38\n"
"loc_FF078C54:\n"
		"B	loc_FF078D4C\n"
"loc_FF078C58:\n"
		"B	loc_FF078D54\n"
"loc_FF078C5C:\n"
		"B	loc_FF078D5C\n"
"loc_FF078C60:\n"
		"B	loc_FF078D78\n"
"loc_FF078C64:\n"
		"B	loc_FF078DB8\n"
"loc_FF078C68:\n"
		"B	loc_FF078D84\n"
"loc_FF078C6C:\n"
		"B	loc_FF078D90\n"
"loc_FF078C70:\n"
		"B	loc_FF078D98\n"
"loc_FF078C74:\n"
		"B	loc_FF078DA0\n"
"loc_FF078C78:\n"
		"B	loc_FF078DA8\n"
"loc_FF078C7C:\n"
		"B	loc_FF078DB0\n"
"loc_FF078C80:\n"
		"B	loc_FF078DC0\n"
"loc_FF078C84:\n"
		"B	loc_FF078DC8\n"
"loc_FF078C88:\n"
		"B	loc_FF078DD0\n"
"loc_FF078C8C:\n"
		"B	loc_FF078DD8\n"
"loc_FF078C90:\n"
		"B	loc_FF078DE0\n"
"loc_FF078C94:\n"
		"B	loc_FF078DE8\n"
"loc_FF078C98:\n"
		"B	loc_FF078DF0\n"
"loc_FF078C9C:\n"
		"B	loc_FF078DF8\n"
"loc_FF078CA0:\n"
		"B	loc_FF078E00\n"
"loc_FF078CA4:\n"
		"B	loc_FF078E08\n"
"loc_FF078CA8:\n"
		"B	loc_FF078E14\n"
"loc_FF078CAC:\n"
		"B	loc_FF078E1C\n"
"loc_FF078CB0:\n"
		"B	loc_FF078E28\n"
"loc_FF078CB4:\n"
		"B	loc_FF078E30\n"
"loc_FF078CB8:\n"
		"B	loc_FF078E38\n"
"loc_FF078CBC:\n"
		"B	loc_FF078E40\n"
"loc_FF078CC0:\n"
		"B	loc_FF078E48\n"
"loc_FF078CC4:\n"
		"B	loc_FF078E50\n"
"loc_FF078CC8:\n"
		"B	loc_FF078E58\n"
"loc_FF078CCC:\n"
		"B	loc_FF078E60\n"
"loc_FF078CD0:\n"
		"B	loc_FF078E68\n"
"loc_FF078CD4:\n"
		"B	loc_FF078E74\n"
"loc_FF078CD8:\n"
		"B	loc_FF078EB8\n"
"loc_FF078CDC:\n"

			"BL      shooting_expo_iso_override\n"
			"BL		 sub_FF0794CC\n"

//SX230 PATCH BEGIN
//Commented area copied from sx210
// TESTING DOSNT DO BAD NEITHER GOOD  LIKE IN SD1200 but seems to dont work too!!!
/*
"    STMFD   SP!, {R1-R12,LR}\n"
"    BL      captseq_hack_override_active\n" // returns 1 if tv or sv override in effect
"    LDMFD   SP!, {R1-R12,LR}\n"
"    STR     R0,[SP,#-4]!\n" // push return value
"    BL      shooting_expo_param_override\n" // saves all regs

"                BL      sub_FF87C4C0\n"

"    LDR     R0,[SP],#4\n" // pop override hack
"    CMP     R0, #1\n"
"    MOVEQ   R0, #0\n"
"    STREQ   R0, [R4,#0x24]\n"  // fixes overrides behavior at short shutter press
*/	
				 "BL      shooting_expo_param_override\n"  // + patched        
//PATCH END		
				 "BL	sub_FF07618C\n"
//PATCH BEGIN
 //  copied over from SX10 don't know if we need it yet
 //  this code added to avoid some incorrect behavior if overrides are used.
 //  but it can cause some unexpected side effects. In this case, remove this code!
/*		"LDR	R0, [R5,#0x28]\n"
		"CMP	R0, #0\n"
		"BLNE	sub_FF19309C\n"
*/
		"MOV     R0, #0\n"
        "STR     R0, [R5,#0x28]\n"  // fixes overrides  behavior at short shutter press
 //PATCH END
		"B	loc_FF078EB8\n"			
"loc_FF078CF4:\n"
		"LDR	R8, [R0,#0xC]\n"
		"MOV	R0, R8\n"
//PATCH BEGIN
//		"BL		sub_FF192E78\n"
		"BL		sub_FF192E78_my\n"
		"BL     capt_seq_hook_raw_here\n"      // + sx220 this works
//PATCH END
		"MOV	R4, R0\n"
		"MOV	R2, R8\n"
		"MOV	R1, #1\n"
		"BL		sub_FF076C14\n"
		"TST	R4, #1\n"
		"BNE	loc_FF078D24\n"
		"MOV	R0, R8\n"
		"BL		sub_FF192864\n"
		"B		loc_FF078EB8\n"
"loc_FF078D24:\n"
		"BL	sub_FF192834\n"
		"B	loc_FF078EB8\n"
"loc_FF078D2C:\n"
		"MOV	R0, #1\n"
		"BL	sub_FF0797AC\n"
		"B	loc_FF078EB8\n"
"loc_FF078D38:\n"
		"BL	sub_FF079108\n"
		"B	loc_FF078D44\n"
"loc_FF078D40:\n"
		"BL	sub_FF0794AC\n"
"loc_FF078D44:\n"
		"STR	R6, [R5,#0x28]\n"
		"B	loc_FF078EB8\n"
// last call after shot, also called switching from play->shoot
"loc_FF078D4C:\n"
		"BL	sub_FF0794B4\n"
		"B	loc_FF078EB8\n"
"loc_FF078D54:\n"
		"BL	sub_FF0796A0\n"
		"B	loc_FF078D7C\n"
"loc_FF078D5C:\n"
		"LDR	R4, [R0,#0xC]\n"
		"MOV	R0, R4\n"
		"BL		sub_FF1930F0\n"
		"MOV	R2, R4\n"
		"MOV	R1, #9\n"
		"BL		sub_FF076C14\n"
		"B		loc_FF078EB8\n"
"loc_FF078D78:\n"					
		"BL	sub_FF079714\n"
"loc_FF078D7C:\n"
		"BL	sub_FF07618C\n"
		"B	loc_FF078EB8\n"
"loc_FF078D84:\n"
		"LDR	R0, [R5,#0x58]\n"
		"BL	sub_FF07A034\n"
		"B	loc_FF078EB8\n"
"loc_FF078D90:\n"
		"BL	sub_FF07A304\n"
		"B	loc_FF078EB8\n"
"loc_FF078D98:\n"
		"BL	sub_FF07A368\n"
		"B	loc_FF078EB8\n"
"loc_FF078DA0:\n"
		"BL	sub_FF07A55C\n"
		"B	loc_FF078EB8\n"
"loc_FF078DA8:\n"
		"BL	sub_FF07A9AC\n"
		"B	loc_FF078EB8\n"
"loc_FF078DB0:\n"
		"BL	sub_FF07AA5C\n"
		"B	loc_FF078EB8\n"
"loc_FF078DB8:\n"
		"BL	sub_FF0794AC\n"
		"B	loc_FF078EB8\n"
"loc_FF078DC0:\n"
		"BL	sub_FF191970\n"
		"B	loc_FF078EB8\n"
"loc_FF078DC8:\n"
		"BL	sub_FF191B84\n"
		"B	loc_FF078EB8\n"
"loc_FF078DD0:\n"
		"BL	sub_FF191C1C\n"
		"B	loc_FF078EB8\n"
"loc_FF078DD8:\n"
		"BL	sub_FF191D08\n"
		"B	loc_FF078EB8\n"
"loc_FF078DE0:\n"
		"BL	sub_FF191DD8\n"
		"B	loc_FF078EB8\n"
"loc_FF078DE8:\n"
		"MOV	R0, #0\n"
		"B	loc_FF078E0C\n"
"loc_FF078DF0:\n"
		"BL	sub_FF192260\n"
		"B	loc_FF078EB8\n"
"loc_FF078DF8:\n"
		"BL	sub_FF1922F8\n"
		"B	loc_FF078EB8\n"
"loc_FF078E00:\n"
		"BL	sub_FF1923D8\n"
		"B	loc_FF078EB8\n"
"loc_FF078E08:\n"
		"MOV	R0, #1\n"
"loc_FF078E0C:\n"
		"BL	sub_FF1920F8\n"
		"B	loc_FF078EB8\n"
"loc_FF078E14:\n"
		"BL	sub_FF0799D8\n"
		"B	loc_FF078EB8\n"
"loc_FF078E1C:\n"
		"BL	sub_FF079A18\n"
		"BL	sub_FF193DA4\n"
		"B	loc_FF078EB8\n"
"loc_FF078E28:\n"
		"BL	sub_FF191F5C\n"
		"B	loc_FF078EB8\n"
"loc_FF078E30:\n"
		"BL	sub_FF192028\n"
		"B	loc_FF078EB8\n"
"loc_FF078E38:\n"
		"BL	sub_FF193E70\n"
		"B	loc_FF078EB8\n"
"loc_FF078E40:\n"
		"BL	sub_FF0282DC\n"
		"B	loc_FF078EB8\n"
"loc_FF078E48:\n"	
		"BL	sub_FF07CEA4\n"
		"B	loc_FF078EB8\n"
"loc_FF078E50:\n"
		"BL	sub_FF07CF28\n"
		"B	loc_FF078EB8\n"
"loc_FF078E58:\n"
		"BL	sub_FF192510\n"
		"B	loc_FF078EB8\n"
"loc_FF078E60:\n"
		"BL	sub_FF192574\n"
		"B	loc_FF078EB8\n"
"loc_FF078E68:\n"
		"BL	sub_FF07CF84\n"
		"BL	sub_FF07CF44\n"
		"B	loc_FF078EB8\n"
"loc_FF078E74:\n"
		"MOV	R0, #1\n"
		"BL		sub_FF1938E4\n"
		"MOV	R0, #1\n"
		"BL		sub_FF193A18\n"
		"LDRH	R0, [R5,#0xA0]\n"
		"CMP	R0, #4\n"
		"LDRNEH	R0, [R5]\n"
		"SUBNE	R1, R0,	#0x4200\n"
		"SUBNES	R1, R1,	#0x2A\n"
		"BNE	loc_FF078EB8\n"
		"BL		sub_FF07CF28\n"
		"BL		sub_FF07D56C\n"
		"BL		sub_FF07D3A8\n"
		"B		loc_FF078EB8\n"
"loc_FF078EAC:\n"
		"LDR	R1, =0x5DB\n"
		"LDR	R0, =0xFF07861C\n"	//"SsShootTask.c"
		"BL		sub_FF00EC88\n"		//Assert
"loc_FF078EB8:\n"
		"LDR	R0, [SP]\n"
		"LDR	R1, [R0,#4]\n"
		"LDR	R0, [R7]\n"
		"BL		sub_FF083C90\n"
		"LDR	R4, [SP]\n"
		"LDR	R0, [R4,#8]\n"
		"CMP	R0, #0\n"
		"LDREQ	R0, =0xFF07861C\n"	//"SsShootTask.c"
		"MOVEQ	R1, #0x118\n"
		"BLEQ	sub_FF00EC88\n"		//Assert
		"STR	R6, [R4,#8]\n"
		"B		loc_FF078C00\n"
 //  End of function sub_FF078BF0
	);
	
}		

//SX230 @FF192E78
void __attribute__((naked,noinline)) sub_FF192E78_my()
{
	asm volatile(
	//"//sub_FF192E78				\n"// "CODE XREF: sub_FF078BF0+10Cp\n"
		"STMFD	SP!, {R3-R7,LR}\n"
		"LDR	R5, =0x3EFA4\n"
		"MOV	R4, R0\n"
		"LDR	R0, [R5,#0x28]\n"
		"LDR	R6, =0x420C\n"
		"CMP	R0, #0\n"
		"MOV	R7, #0\n"
		"BNE	loc_FF192F08\n"
		"LDR	R0, [R5,#0xC4]\n"
		"CMP	R0, #1\n"
		"BNE	loc_FF192EF0\n"
		"LDRH	R0, [R5]\n"
		"CMP	R0, R6\n"
		"LDRNEH	R0, [R5,#0x9E]\n"
		"CMPNE	R0, #3\n"
		"LDRNE	R0, [R4,#8]\n"
		"CMPNE	R0, #1\n"
		"BLS	loc_FF192ED4\n"
		"BL	sub_FF022D98\n"
		"TST	R0, #1\n"
		"BEQ	loc_FF192F08\n"
		"BL	sub_FF07ECD8\n"
		"B	loc_FF192F00\n"
"loc_FF192ED4:\n"
		"MOV	R0, #0xC\n"
		"BL	sub_FF07EC78\n"
		"TST	R0, #1\n"
		"BEQ	loc_FF192F08\n"
		"BL	sub_FF193760\n"
		"BL	sub_FF0768E4\n"
		"B	loc_FF192F00\n"
"loc_FF192EF0:			\n"
		"MOV	R0, #0xC\n"
		"BL	sub_FF07EC78\n"
		"TST	R0, #1\n"
		"BEQ	loc_FF192F08\n"
"loc_FF192F00:\n"
		"MOV	R0, #1\n"
		"LDMFD	SP!, {R3-R7,PC}\n"
"loc_FF192F08:\n"
		"LDRH	R0, [R5]\n"
		"CMP	R0, R6\n"
		"LDRNEH	R0, [R5,#0x9E]\n"
		"CMPNE	R0, #3\n"
		"LDRNE	R0, [R4,#8]\n"
		"CMPNE	R0, #1\n"
		"BLS	loc_FF192F38\n"
		"LDRH	R0, [R5,#0x9C]\n"
		"CMP	R0, #0\n"
		"LDREQH	R0, [R5,#0x98]\n"
		"CMPEQ	R0, #2\n"
		"BLEQ	sub_FF079AE4\n"
"loc_FF192F38:\n"
		"LDRH	R1, [R5]\n"
		"LDRH	R0, [R5,#0x9E]\n"
		"CMP	R1, R6\n"
		"BEQ	loc_FF192F78\n"
		"CMP	R0, #3\n"
		"BEQ	loc_FF192FB8\n"
		"LDR	R0, [R4,#8]\n"
		"CMP	R0, #1\n"
		"BLS	loc_FF192F80\n"
		"LDRH	R0, [R5,#0x9C]\n"
		"CMP	R0, #0\n"
		"BNE	loc_FF192FB8\n"
		"LDRH	R0, [R5,#0x98]\n"
		"CMP	R0, #2\n"
		"BEQ	loc_FF192FB4\n"
		"B	loc_FF192F8C\n"
"loc_FF192F78:\n"
		"CMP	R0, #3\n"
		"BEQ	loc_FF192FB8\n"
"loc_FF192F80:\n"
		"LDRH	R0, [R5,#0x9C]\n"
		"CMP	R0, #0\n"
		"BNE	loc_FF192FB8\n"
"loc_FF192F8C:\n"
		"LDRH	R0, [R5,#0x98]\n"
		"CMP	R0, #1\n"
		"BNE	loc_FF192FB8\n"
		"CMP	R1, R6\n"
		"LDRNE	R0, [R4,#8]\n"
		"CMPNE	R0, #1\n"
		"BLS	loc_FF192FB8\n"
		"LDR	R0, [R4,#0xC]\n"
		"CMP	R0, #1\n"
		"BNE	loc_FF192FB8\n"
"loc_FF192FB4:\n"
		"BL	sub_FF193EA8\n"
"loc_FF192FB8:\n"
		"BL	sub_FF193E70\n"
		"BL	sub_FF0794BC\n"
		"LDR	R0, [R5,#0x28]\n"
		"CMP	R0, #0\n"
		"BNE	loc_FF193084\n"
		"MOV	R0, R4\n"
		"BL	sub_FF1926EC\n"
		"TST	R0, #1\n"
		"LDMNEFD	SP!, {R3-R7,PC}\n"
		"MOV	R0, R4\n"
		"BL	sub_FF192B50\n"		//loc to sub
		"BL	sub_FF1936A4\n"
		"LDR	R0, [R5,#0xC4]\n"
		"CMP	R0, #1\n"
		"BNE	loc_FF193010\n"
		"LDRH	R0, [R5]\n"
		"CMP	R0, R6\n"
		"LDRNEH	R0, [R5,#0x9E]\n"
		"CMPNE	R0, #3\n"
		"LDRNE	R0, [R4,#8]\n"
		"CMPNE	R0, #1\n"
		"BHI	loc_FF193018\n"
"loc_FF193010:				\n"
		"MOV	R0, #2\n"
		"BL		sub_FF0805B4\n"
//PATCH BEGIN
		"BL      wait_until_remote_button_is_released\n"
		"BL      capt_seq_hook_set_nr\n"				
//PATCH END
"loc_FF193018:				\n"
		"LDRH	R0, [R5]\n"
		"SUB	R1, R0,	#0x4200\n"
		"SUBS	R1, R1,	#0x2D\n"
		"BNE	loc_FF193074\n"
		"MOV	R5, #1\n"
		"MOV	R2, #2\n"
		"MOV	R1, SP\n"
		"ADD	R0, R2,	#0x15C\n"
		"STR	R5, [SP]\n"
		"BL		sub_FF08BF50\n"
		"TST	R0, #1\n"
		"MOVNE	R1, #0xBC\n"
		"LDRNE	R0, =0xFF1931A0	\n"//" \n"""SsCaptureSeq.c\n"
		"BLNE	sub_FF00EC88		\n"// "assert\n"
		"LDRH	R0, [SP]\n"
		"CMP	R0, #1\n"
		"BLS	loc_FF19306C\n"
		"MOV	R0, R4\n"
		"STR	R5, [R4,#0xE4]\n"
		"BL		sub_FF3100F4\n"
		"B		loc_FF19307C\n"
"loc_FF19306C:\n"
		"MOV	R0, #0\n"
		"STR	R0, [R4,#0xE4]\n"
"loc_FF193074:\n"
		"MOV	R0, R4\n"
		"BL		sub_FF30FD34\n"
"loc_FF19307C:\n"
		"MOV	R7, R0\n"
		"B	loc_FF193094\n"
"loc_FF193084:\n"
		"LDR	R0, =0x8A08\n"
		"LDR	R0, [R0]\n"
		"CMP	R0, #0\n"
		"MOVNE	R7, #0x1D\n"
"loc_FF193094:				\n"
		"MOV	R0, R7\n"
		"LDMFD	SP!, {R3-R7,PC}\n"
// "End of function sub_FF192E78\n"
	);
	
}

////SX230 @FF0C5E98
void __attribute__((naked,noinline)) exp_drv_task(){
	asm volatile(
//"sub_FF0C5E98\n"
		"STMFD	SP!, {R4-R9,LR}\n"
		"SUB	SP, SP,	#0x24\n"
		"LDR	R6, =0x5838\n"
		"LDR	R7, =0xBB8\n"
		"LDR	R4, =0x5AA3C\n"
		"MOV	R0, #0\n"
		"ADD	R5, SP,	#0x14\n"
		"STR	R0, [SP,#0x10]\n"
"loc_FF0C5EB8:				\n"
		"LDR	R0, [R6,#0x20]\n"
		"MOV	R2, #0\n"
		"ADD	R1, SP,	#0x20\n"
		"BL	sub_FF02B184\n"
		"LDR	R0, [SP,#0x10]\n"
		"CMP	R0, #1\n"
		"BNE	loc_FF0C5F04\n"
		"LDR	R0, [SP,#0x20]\n"
		"LDR	R0, [R0]\n"
		"CMP	R0, #0x14\n"
		"CMPNE	R0, #0x15\n"
		"CMPNE	R0, #0x16\n"
		"CMPNE	R0, #0x17\n"
		"BEQ	loc_FF0C6064\n"
		"CMP	R0, #0x29\n"
		"BEQ	loc_FF0C5FEC\n"
		"ADD	R1, SP,	#0x10\n"
		"MOV	R0, #0\n"
		"BL	sub_FF0C5E48\n"
"loc_FF0C5F04:\n"
		"LDR	R0, [SP,#0x20]\n"
		"LDR	R1, [R0]\n"
		"CMP	R1, #0x2F\n"
		"BNE	loc_FF0C5F30\n"
		"BL	sub_FF0C72C4\n"
		"LDR	R0, [R6,#0x1C]\n"
		"MOV	R1, #1\n"
		"BL		sub_FF083C90\n"
		"BL		sub_FF00EC40\n"	//ExitTask
		"ADD	SP, SP,	#0x24\n"
		"LDMFD	SP!, {R4-R9,PC}\n"
"loc_FF0C5F30:\n"
		"CMP	R1, #0x2E\n"
		"BNE	loc_FF0C5F4C\n"
		"LDR	R2, [R0,#0x8C]!\n"
		"LDR	R1, [R0,#4]\n"
		"MOV	R0, R1\n"
		"BLX	R2\n"
		"B	loc_FF0C64F4\n"
"loc_FF0C5F4C:\n"
		"CMP	R1, #0x27\n"
		"BNE	loc_FF0C5F9C\n"
		"LDR	R0, [R6,#0x1C]\n"
		"MOV	R1, #0x80\n"
		"BL	sub_FF083CC4\n"
		"LDR	R0, =0xFF0C111C\n"
		"MOV	R1, #0x80\n"
		"BL	sub_FF183924\n"
		"LDR	R0, [R6,#0x1C]\n"
		"MOV	R2, R7\n"
		"MOV	R1, #0x80\n"
		"BL	sub_FF083BD0\n"
		"TST	R0, #1\n"
		"LDRNE	R1, =0x1756\n"
		"BNE	loc_FF0C6058\n"
"loc_FF0C5F88:\n"
		"LDR	R1, [SP,#0x20]\n"
		"LDR	R0, [R1,#0x90]\n"
		"LDR	R1, [R1,#0x8C]\n"
		"BLX	R1\n"
		"B	loc_FF0C64F4\n"
"loc_FF0C5F9C:				\n"
		"CMP	R1, #0x28\n"
		"BNE	loc_FF0C5FE4\n"
		"ADD	R1, SP,	#0x10\n"
		"BL	sub_FF0C5E48\n"
		"LDR	R0, [R6,#0x1C]\n"
		"MOV	R1, #0x100\n"
		"BL	sub_FF083CC4\n"
		"LDR	R0, =0xFF0C112C\n"
		"MOV	R1, #0x100\n"
		"BL	sub_FF18424C\n"
		"LDR	R0, [R6,#0x1C]\n"
		"MOV	R2, R7\n"
		"MOV	R1, #0x100\n"
		"BL	sub_FF083BD0\n"
		"TST	R0, #1\n"
		"BEQ	loc_FF0C5F88\n"
		"LDR	R1, =0x1760\n"
		"B	loc_FF0C6058\n"
"loc_FF0C5FE4:\n"
		"CMP	R1, #0x29\n"
		"BNE	loc_FF0C5FFC\n"
"loc_FF0C5FEC:\n"
		"LDR	R0, [SP,#0x20]\n"
		"ADD	R1, SP,	#0x10\n"
		"BL	sub_FF0C5E48\n"
		"B	loc_FF0C5F88\n"
"loc_FF0C5FFC:\n"
		"CMP	R1, #0x2C\n"
		"BNE	loc_FF0C6014\n"
		"BL	sub_FF0B2A5C\n"
		"BL	sub_FF0B36CC\n"
		"BL	sub_FF0B3244\n"
		"B	loc_FF0C5F88\n"
"loc_FF0C6014:\n"
		"CMP	R1, #0x2D\n"
		"BNE	loc_FF0C6064\n"
		"LDR	R0, [R6,#0x1C]\n"
		"MOV	R1, #4\n"
		"BL	sub_FF083CC4\n"
		"LDR	R1, =0xFF0C114C\n"
		"LDR	R0, =0xFFFFF400\n"
		"MOV	R2, #4\n"
		"BL	sub_FF0B24D0\n"
		"BL	sub_FF0B2760\n"
		"LDR	R0, [R6,#0x1C]\n"
		"MOV	R2, R7\n"
		"MOV	R1, #4\n"
		"BL	sub_FF083AEC\n"
		"TST	R0, #1\n"
		"BEQ	loc_FF0C5F88\n"
		"LDR	R1, =0x1788\n"
"loc_FF0C6058:\n"
		"LDR	R0, =0xFF0C18EC\n"
		"BL		sub_FF00EC88\n"
		"B	loc_FF0C5F88\n"
"loc_FF0C6064:\n"
		"LDR	R0, [SP,#0x20]\n"
		"MOV	R8, #1\n"
		"LDR	R1, [R0]\n"
		"CMP	R1, #0x12\n"
		"CMPNE	R1, #0x13\n"
		"BNE	loc_FF0C60CC\n"
		"LDR	R1, [R0,#0x7C]\n"
		"ADD	R1, R1,	R1,LSL#1\n"
		"ADD	R1, R0,	R1,LSL#2\n"
		"SUB	R1, R1,	#8\n"
		"LDMIA	R1, {R2,R3,R9}\n"
		"STMIA	R5, {R2,R3,R9}\n"
		"BL	sub_FF0C41A0\n"
		"LDR	R0, [SP,#0x20]\n"
		"LDR	R1, [R0,#0x7C]\n"
		"LDR	R3, [R0,#0x8C]\n"
		"LDR	R2, [R0,#0x90]\n"
		"ADD	R0, R0,	#4\n"
		"BLX	R3\n"
		"LDR	R0, [SP,#0x20]\n"
		"BL	sub_FF0C76D8\n"
		"LDR	R0, [SP,#0x20]\n"
		"LDR	R1, [R0,#0x7C]\n"
		"LDR	R2, [R0,#0x98]\n"
		"LDR	R3, [R0,#0x94]\n"
		"B	loc_FF0C63E0\n"
"loc_FF0C60CC:\n"
		"CMP	R1, #0x14\n"
		"CMPNE	R1, #0x15\n"
		"CMPNE	R1, #0x16\n"
		"CMPNE	R1, #0x17\n"
		"BNE	loc_FF0C6184\n"
		"ADD	R3, SP,	#0x10\n"
		"ADD	R2, SP,	#4\n"
		"ADD	R1, SP,	#0x14\n"
		"BL		sub_FF0C4408\n"
		"CMP	R0, #1\n"
		"MOV	R9, R0\n"
		"CMPNE	R9, #5\n"
		"BNE	loc_FF0C6120\n"
		"LDR	R0, [SP,#0x20]\n"
		"MOV	R2, R9\n"
		"LDR	R1, [R0,#0x7C]!\n"
		"LDR	R12, [R0,#0x10]!\n"
		"LDR	R3, [R0,#4]\n"
		"ADD	R0, SP,	#4\n"
		"BLX	R12\n"
		"B		loc_FF0C6158\n"
"loc_FF0C6120:\n"
		"LDR	R0, [SP,#0x20]\n"
		"CMP	R9, #2\n"
		"LDR	R3, [R0,#0x90]\n"
		"CMPNE	R9, #6\n"
		"BNE	loc_FF0C616C\n"
		"LDR	R12, [R0,#0x8C]\n"
		"MOV	R2, R9\n"
		"MOV	R1, #1\n"
		"ADD	R0, SP,	#4\n"
		"BLX	R12\n"
		"LDR	R0, [SP,#0x20]\n"
		"ADD	R2, SP,	#4\n"
		"ADD	R1, SP,	#0x14\n"
		"BL	sub_FF0C5B94\n"
"loc_FF0C6158:\n"
		"LDR	R0, [SP,#0x20]\n"
		"LDR	R2, [SP,#0x10]\n"
		"MOV	R1, R9\n"
		"BL	sub_FF0C5DE8\n"
		"B	loc_FF0C63E8\n"
"loc_FF0C616C:\n"
		"LDR	R1, [R0,#0x7C]\n"
		"LDR	R12, [R0,#0x8C]\n"
		"MOV	R2, R9\n"
		"ADD	R0, R0,	#4\n"
		"BLX	R12\n"
		"B	loc_FF0C63E8\n"
"loc_FF0C6184:\n"
		"CMP	R1, #0x23\n"
		"CMPNE	R1, #0x24\n"
		"BNE	loc_FF0C61D0\n"
		"LDR	R1, [R0,#0x7C]\n"
		"ADD	R1, R1,	R1,LSL#1\n"
		"ADD	R1, R0,	R1,LSL#2\n"
		"SUB	R1, R1,	#8\n"
		"LDMIA	R1, {R2,R3,R9}\n"
		"STMIA	R5, {R2,R3,R9}\n"
		"BL	sub_FF0C2F90\n"
		"LDR	R0, [SP,#0x20]\n"
		"LDR	R1, [R0,#0x7C]\n"
		"LDR	R3, [R0,#0x8C]\n"
		"LDR	R2, [R0,#0x90]\n"
		"ADD	R0, R0,	#4\n"
		"BLX	R3\n"
		"LDR	R0, [SP,#0x20]\n"
		"BL	sub_FF0C347C\n"
		"B	loc_FF0C63E8\n"
"loc_FF0C61D0:\n"
		"ADD	R1, R0,	#4\n"
		"LDMIA	R1, {R2,R3,R9}\n"
		"STMIA	R5, {R2,R3,R9}\n"
		"LDR	R1, [R0]\n"
		"CMP	R1, #0x27\n"
		"ADDCC	PC, PC,	R1,LSL#2\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C61EC:\n"
		"B	loc_FF0C6288\n"
"loc_FF0C61F0:\n"
		"B	loc_FF0C6288\n"
"loc_FF0C61F4:\n"
		"B	loc_FF0C6290\n"
"loc_FF0C61F8:\n"
		"B	loc_FF0C6298\n"
"loc_FF0C61FC:\n"
		"B	loc_FF0C6298\n"
"loc_FF0C6200:\n"
		"B	loc_FF0C6298\n"
"loc_FF0C6204:\n"
		"B	loc_FF0C6288\n"
"loc_FF0C6208:\n"
		"B	loc_FF0C6290\n"
"loc_FF0C620C:\n"
		"B	loc_FF0C6298\n"
"loc_FF0C6210:\n"
		"B	loc_FF0C6298\n"
"loc_FF0C6214:\n"
		"B	loc_FF0C62B0\n"
"loc_FF0C6218:\n"
		"B	loc_FF0C62B0\n"
"loc_FF0C621C:\n"
		"B	loc_FF0C63BC\n"
"loc_FF0C6220:\n"
		"B	loc_FF0C63C4\n"
"loc_FF0C6224:\n"
		"B	loc_FF0C63C4\n"
"loc_FF0C6228:\n"
		"B	loc_FF0C63C4\n"
"loc_FF0C622C:\n"
		"B	loc_FF0C63C4\n"
"loc_FF0C6230:\n"
		"B	loc_FF0C63CC\n"
"loc_FF0C6234:\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C6238:\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C623C:\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C6240:\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C6244:\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C6248:\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C624C:\n"
		"B	loc_FF0C62A0\n"
"loc_FF0C6250:\n"
		"B	loc_FF0C62A8\n"
"loc_FF0C6254:\n"
		"B	loc_FF0C62A8\n"
"loc_FF0C6258:\n"
		"B	loc_FF0C62BC\n"
"loc_FF0C625C:\n"
		"B	loc_FF0C62BC\n"
"loc_FF0C6260:\n"
		"B	loc_FF0C62C4\n"
"loc_FF0C6264:\n"
		"B	loc_FF0C62FC\n"
"loc_FF0C6268:\n"
		"B	loc_FF0C6334\n"
"loc_FF0C626C:\n"
		"B	loc_FF0C636C\n"
"loc_FF0C6270:\n"
		"B	loc_FF0C63A4\n"
"loc_FF0C6274:\n"
		"B	loc_FF0C63A4\n"
"loc_FF0C6278:\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C627C:\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C6280:\n"
		"B	loc_FF0C63AC\n"
"loc_FF0C6284:\n"
		"B	loc_FF0C63B4\n"
"loc_FF0C6288:\n"
		"BL	sub_FF0C1718\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C6290:\n"
		"BL	sub_FF0C1A18\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C6298:\n"
		"BL	sub_FF0C1C80\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C62A0:\n"
		"BL	sub_FF0C1F34\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C62A8:\n"
		"BL	sub_FF0C214C\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C62B0:\n"
//PATCH BEGIN
//		"BL	sub_FF0C2608\n"
		"BL	sub_FF0C2608_my\n"
//PATCH END
		"MOV	R8, #0\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C62BC:\n"
		"BL	sub_FF0C27EC\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C62C4:\n"
		"LDRH	R1, [R0,#4]\n"
		"STRH	R1, [SP,#0x14]\n"
		"LDRH	R1, [R4,#2]\n"
		"STRH	R1, [SP,#0x16]\n"
		"LDRH	R1, [R4,#4]\n"
		"STRH	R1, [SP,#0x18]\n"
		"LDRH	R1, [R4,#6]\n"
		"STRH	R1, [SP,#0x1A]\n"
		"LDRH	R1, [R0,#0xC]\n"
		"STRH	R1, [SP,#0x1C]\n"
		"LDRH	R1, [R4,#0xA]\n"
		"STRH	R1, [SP,#0x1E]\n"
		"BL	sub_FF0C7358\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C62FC:\n"
		"LDRH	R1, [R0,#4]\n"
		"STRH	R1, [SP,#0x14]\n"
		"LDRH	R1, [R4,#2]\n"
		"STRH	R1, [SP,#0x16]\n"
		"LDRH	R1, [R4,#4]\n"
		"STRH	R1, [SP,#0x18]\n"
		"LDRH	R1, [R4,#6]\n"
		"STRH	R1, [SP,#0x1A]\n"
		"LDRH	R1, [R4,#8]\n"
		"STRH	R1, [SP,#0x1C]\n"
		"LDRH	R1, [R4,#0xA]\n"
		"STRH	R1, [SP,#0x1E]\n"
		"BL	sub_FF0C74D8\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C6334:\n"
		"LDRH	R1, [R4]\n"
		"STRH	R1, [SP,#0x14]\n"
		"LDRH	R1, [R0,#6]\n"
		"STRH	R1, [SP,#0x16]\n"
		"LDRH	R1, [R4,#4]\n"
		"STRH	R1, [SP,#0x18]\n"
		"LDRH	R1, [R4,#6]\n"
		"STRH	R1, [SP,#0x1A]\n"
		"LDRH	R1, [R4,#8]\n"
		"STRH	R1, [SP,#0x1C]\n"
		"LDRH	R1, [R4,#0xA]\n"
		"STRH	R1, [SP,#0x1E]\n"
		"BL	sub_FF0C758C\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C636C:\n"
		"LDRH	R1, [R4]\n"
		"STRH	R1, [SP,#0x14]\n"
		"LDRH	R1, [R4,#2]\n"
		"STRH	R1, [SP,#0x16]\n"
		"LDRH	R1, [R4,#4]\n"
		"STRH	R1, [SP,#0x18]\n"
		"LDRH	R1, [R4,#6]\n"
		"STRH	R1, [SP,#0x1A]\n"
		"LDRH	R1, [R0,#0xC]\n"
		"STRH	R1, [SP,#0x1C]\n"
		"LDRH	R1, [R4,#0xA]\n"
		"STRH	R1, [SP,#0x1E]\n"
		"BL	sub_FF0C7634\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C63A4:\n"
		"BL	sub_FF0C2D68\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C63AC:\n"
		"BL	sub_FF0C3580\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C63B4:\n"
		"BL	sub_FF0C3A8C\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C63BC:\n"
		"BL	sub_FF0C3C6C\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C63C4:\n"
		"BL	sub_FF0C3E28\n"
		"B	loc_FF0C63D0\n"
"loc_FF0C63CC:\n"
		"BL	sub_FF0C3F98\n"
"loc_FF0C63D0:\n"
		"LDR	R0, [SP,#0x20]\n"
		"LDR	R1, [R0,#0x7C]\n"
		"LDR	R2, [R0,#0x90]\n"
		"LDR	R3, [R0,#0x8C]\n"
"loc_FF0C63E0:\n"
		"ADD	R0, R0,	#4\n"
		"BLX	R3\n"
"loc_FF0C63E8:\n"
		"LDR	R1, [SP,#0x20]\n"
		"LDR	R0, [R1]\n"
		"CMP	R0, #0x10\n"
		"BEQ	loc_FF0C6420\n"
		"BGT	loc_FF0C6410\n"
		"CMP	R0, #1\n"
		"CMPNE	R0, #4\n"
		"CMPNE	R0, #0xE\n"
		"BNE	loc_FF0C6430\n"
		"B	loc_FF0C6420\n"
"loc_FF0C6410:\n"
		"CMP	R0, #0x13\n"
		"CMPNE	R0, #0x17\n"
		"CMPNE	R0, #0x1A\n"
		"BNE	loc_FF0C6430\n"
"loc_FF0C6420:\n"
		"LDRH	R0, [R4]\n"
		"STRH	R0, [SP,#0x14]\n"
		"LDRH	R0, [R4,#8]\n"
		"STRH	R0, [SP,#0x1C]\n"
"loc_FF0C6430:\n"
		"CMP	R8, #1\n"
		"BNE	loc_FF0C647C\n"
		"LDR	R0, [R1,#0x7C]\n"
		"MOV	R2, #0xC\n"
		"ADD	R0, R0,	R0,LSL#1\n"
		"ADD	R0, R1,	R0,LSL#2\n"
		"SUB	R8, R0,	#8\n"
		"LDR	R0, =0x5AA3C\n"
		"ADD	R1, SP,	#0x14\n"
		"BL	sub_FF3B5DDC\n"
		"LDR	R0, =0x5AA48\n"
		"MOV	R2, #0xC\n"
		"ADD	R1, SP,	#0x14\n"
		"BL	sub_FF3B5DDC\n"
		"LDR	R0, =0x5AA54\n"
		"MOV	R2, #0xC\n"
		"MOV	R1, R8\n"
		"BL	sub_FF3B5DDC\n"
		"B	loc_FF0C64F4\n"
"loc_FF0C647C:\n"
		"LDR	R0, [R1]\n"
		"MOV	R3, #1\n"
		"CMP	R0, #0xB\n"
		"BNE	loc_FF0C64C0\n"
		"MOV	R2, #0\n"
		"STRD	R2, [SP]\n"
		"MOV	R2, R3\n"
		"MOV	R1, R3\n"
		"MOV	R0, #0\n"
		"BL	sub_FF0C14EC\n"
		"MOV	R3, #1\n"
		"MOV	R2, #0\n"
		"STRD	R2, [SP]\n"
		"MOV	R2, R3\n"
		"MOV	R1, R3\n"
		"MOV	R0, #0\n"
		"B	loc_FF0C64F0\n"
"loc_FF0C64C0:\n"
		"MOV	R2, #1\n"
		"STRD	R2, [SP]\n"
		"MOV	R3, R2\n"
		"MOV	R1, R2\n"
		"MOV	R0, R2\n"
		"BL	sub_FF0C14EC\n"
		"MOV	R3, #1\n"
		"MOV	R2, R3\n"
		"MOV	R1, R3\n"
		"MOV	R0, R3\n"
		"STR	R3, [SP]\n"
		"STR	R3, [SP,#4]\n"
"loc_FF0C64F0:\n"
		"BL	sub_FF0C1664\n"
"loc_FF0C64F4:\n"
		"LDR	R0, [SP,#0x20]\n"
		"BL	sub_FF0C72C4\n"
		"B	loc_FF0C5EB8\n"
// "End of function sub_FF0C5E98\n"
	);
}

//SX230 @FF0C2608
void __attribute__((naked,noinline)) sub_FF0C2608_my(){
	asm volatile(
	// "sub_FF0C2608\n"
		"STMFD	SP!, {R4-R8,LR}\n"
		"LDR	R7, =0x5838\n"
		"MOV	R4, R0\n"
		"LDR	R0, [R7,#0x1C]\n"
		"MOV	R1, #0x3E\n"
		"BL		sub_FF083CC4\n"
		"MOV	R2, #0\n"
		"LDRSH	R0, [R4,#4]\n"
		"MOV	R1, R2\n"
		"BL	sub_FF0C11AC\n"
		"MOV	R5, R0\n"
		"LDRSH	R0, [R4,#6]\n"
		"BL	sub_FF0C12FC\n"
		"LDRSH	R0, [R4,#8]\n"
		"BL	sub_FF0C1354\n"
		"LDRSH	R0, [R4,#0xA]\n"
		"BL	sub_FF0C13AC\n"
		"LDRSH	R0, [R4,#0xC]\n"
		"MOV	R1, #0\n"
		"BL	sub_FF0C1404\n"
		"MOV	R6, R0\n"
		"LDRSH	R0, [R4,#0xE]\n"
		"BL	sub_FF0C72F4\n"
		"LDR	R0, [R4]\n"
		"LDR	R8, =0x5AA54\n"
		"CMP	R0, #0xB\n"
		"MOVEQ	R5, #0\n"
		"MOVEQ	R6, R5\n"
		"BEQ	loc_FF0C26A4\n"
		"CMP	R5, #1\n"
		"BNE	loc_FF0C26A4\n"
		"LDRSH	R0, [R4,#4]\n"
		"LDR	R1, =0xFF0C110C\n"
		"MOV	R2, #2\n"
		"BL	sub_FF183BFC\n"
		"STRH	R0, [R4,#4]\n"
		"MOV	R0, #0\n"
		"STR	R0, [R7,#0x28]\n"
		"B	loc_FF0C26AC\n"
"loc_FF0C26A4:\n"
		"LDRH	R0, [R8]\n"
		"STRH	R0, [R4,#4]\n"
"loc_FF0C26AC:\n"
		"CMP	R6, #1\n"
		"LDRNEH	R0, [R8,#8]\n"
		"BNE	loc_FF0C26C8\n"
		"LDRSH	R0, [R4,#0xC]\n"
		"LDR	R1, =0xFF0C1190\n"
		"MOV	R2, #0x20\n"
		"BL		sub_FF0C7314\n"
"loc_FF0C26C8:\n"
		"STRH	R0, [R4,#0xC]\n"
		"LDRSH	R0, [R4,#6]\n"
//PATCH BEGIN
//		"BL		sub_FF0B27CC\n"
		"BL		sub_FF0B27CC_my\n"		
//PATCH END
		"LDRSH	R0, [R4,#8]\n"
		"MOV	R1, #1\n"
		"BL		sub_FF0B2F84\n"
		"MOV	R1, #0\n"
		"ADD	R0, R4,	#8\n"
		"BL		sub_FF0B300C\n"
		"LDRSH	R0, [R4,#0xE]\n"
		"BL		sub_FF0BBF9C\n"
		"LDR	R4, =0xBB8\n"
		"CMP	R5, #1\n"
		"BNE	loc_FF0C2720\n"
		"LDR	R0, [R7,#0x1C]\n"
		"MOV	R2, R4\n"
		"MOV	R1, #2\n"
		"BL		sub_FF083BD0\n"
		"TST	R0, #1\n"
		"LDRNE	R1, =0x7E3\n"
		"LDRNE	R0, =0xFF0C18EC	\n"//" \n"""ExpDrv.c\n""
		"BLNE	sub_FF00EC88\n"	//assert
"loc_FF0C2720:\n"
		"CMP	R6, #1\n"
		"LDMNEFD	SP!, {R4-R8,PC}\n"
		"LDR	R0, [R7,#0x1C]\n"
		"MOV	R2, R4\n"
		"MOV	R1, #0x20\n"
		"BL		sub_FF083BD0\n"
		"TST	R0, #1\n"
		"LDMEQFD	SP!, {R4-R8,PC}\n"
		"LDMFD	SP!, {R4-R8,LR}\n"
		"LDR	R1, =0x7E8\n"
		"LDR	R0, =0xFF0C18EC	\n"//" \n"""ExpDrv.c\n""
		"B		sub_FF00EC88\n"	//assert
// "End of function sub_FF0C2608\n"	
	);
}
	
//SX230 @FF0B27CC
void __attribute__((naked,noinline)) sub_FF0B27CC_my(){
	asm volatile(
//"sub_FF0B27CC\n"
		"STMFD	SP!, {R4-R6,LR}\n"
		"LDR	R5, =0x54E0\n"
		"MOV	R4, R0\n"
		"LDR	R0, [R5,#4]\n"
		"CMP	R0, #1\n"
		"LDRNE	R1, =0x146\n"
		"LDRNE	R0, =0xFF0B2604	\n" // "Shutter.c"
		"BLNE	sub_FF00EC88\n"		//ASSERT
		"CMN	R4, #0xC00\n"
		"LDREQSH	R4, [R5,#2]\n"
		"CMN	R4, #0xC00\n"
		"MOVEQ	R1, #0x14C\n"
		"LDREQ	R0, =0xFF0B2604	\n" //"Shutter.c"
		"STRH	R4, [R5,#2]\n"
		"BLEQ	sub_FF00EC88\n"		//ASSERT
		"MOV	R0, R4\n"
//PATCH BEGIN		
//		"BL		sub_FF24DFD0\n"
		"BL     apex2us\n"
//PATCH END
		"MOV	R4, R0\n"
		"BL		sub_FF106D88\n" // nullsub_19
		"MOV	R0, R4\n"
		"BL		sub_FF114DBC\n"
		"TST	R0, #1\n"
		"LDMEQFD	SP!, {R4-R6,PC}\n"
		"LDMFD	SP!, {R4-R6,LR}\n"
		"LDR	R1, =0x151\n"
		"LDR	R0, =0xFF0B2604	\n"//  "Shutter.c"
		"B		sub_FF00EC88\n"		//ASSERT
// "End of function sub_FF0B27CC\n"
	);
}