#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define RAWDATA_AVAILABLE (1)
#define RAWDATA_SAVED (2)

#define NR_ON (2)
#define NR_OFF (1)

static long raw_save_stage;

void capt_seq_hook_raw_here()
{
    raw_save_stage = RAWDATA_AVAILABLE;
    core_rawdata_available();
    while (raw_save_stage != RAWDATA_SAVED){
	_SleepTask(10);
    }
}

void hook_raw_save_complete()
{
    raw_save_stage = RAWDATA_SAVED;
}


void capt_seq_hook_set_nr()
{
    long *nrflag = (long*)0xCF74;

    switch (core_get_noise_reduction_value()){
    case NOISE_REDUCTION_AUTO_CANON:
	// leave it alone
	break;
    case NOISE_REDUCTION_OFF:
	*nrflag = 1;
	break;
    case NOISE_REDUCTION_ON:
	*nrflag = 2;
	break;
    };
}

void __attribute__((naked,noinline)) sub_FFB0D858_my(long p)
{
    asm volatile (
                
							"STMFD   SP!, {R4,LR}\n"
							"MOV     R4, R0\n"
							"SUB     SP, SP, #0xC\n"
							"BL      sub_FFB0E2C8\n"
							"MVN     R1, #0\n"
							"BL      sub_FFB1EA38\n"	// ClearEventFlag
							"MOV     R0, #0x8A\n"
							"ADD     R1, SP, #4\n"
							"MOV     R2, #4\n"
							"BL      sub_FF81BCAC\n"
							"TST     R0, #1\n"
							"BEQ     loc_FFB0D898\n"
							"MOV     R1, #0x1D0\n"
							"LDR     R0, =0xFFB0D6DC\n"	// aSscaptureseq_c
							"ADD     R1, R1, #2\n"
							"BL      sub_FFB2C0C4\n"		// DebugAssert
"loc_FFB0D898:\n"
							"LDR     R3, =0xBE160\n"
							"LDR     R2, =0xBE220\n"
							"LDR     R0, [R3,#0x7C]\n"
							"LDRSH   R1, [R2,#0xE]\n"
							"BL      sub_FFA44D6C\n"
							"MOV     R0, R4\n"
							"BL      sub_FFB0D660\n"
							"BL      capt_seq_hook_set_nr\n"  // +							
							"LDR     R3, =0xCF78\n"
							"LDR     R0, [R3]\n"
							"B       sub_FFB0D8BC\n"
    );
}

void __attribute__((naked,noinline)) sub_FFB0A680_my(long p)
{
    asm volatile (
                    
							"STMFD   SP!, {R4,R5,LR}\n"
							"LDR     R3, =0xBE160\n"
							"LDR     R5, [R0,#0xC]\n"
							"LDR     R1, [R3,#0x24]\n"
							"LDR     R2, [R5,#8]\n"
							"CMP     R1, #0\n"
							"ORR     R2, R2, #1\n"
							"STR     R2, [R5,#8]\n"
							"BNE     loc_FFB0A6D4\n"
							"MOV     R0, #0xC\n"
							"BL      sub_FFB14BD0\n"
							"TST     R0, #1\n"
							"BEQ     loc_FFB0A6D4\n"
							"LDR     R3, [R5,#8]\n"
							"MOV     R0, #1\n"
							"ORR     R3, R3, #0x40000000\n"
							"STR     R3, [R5,#8]\n"
"loc_FFB0A6C4:\n"
							"MOV     R2, R5\n"
							"MOV     R1, #1\n"
							"LDMFD   SP!, {R4,R5,LR}\n"
							"B       sub_FFB08E28\n"
"loc_FFB0A6D4:\n"
							"LDR     R4, =0xBE160\n"
							"BL      sub_FFB0B178\n"		// Set_CMD25Write_62
							"LDR     R3, [R4,#0x24]\n"
							"CMP     R3, #0\n"
							"BNE     loc_FFB0A71C\n"
							"MOV     R0, R5\n"
							"BL      sub_FFB0C35C\n"
							"TST     R0, #1\n"
							"BNE     loc_FFB0A6C4\n"
							"BL      sub_FF82668C\n"
							"BL      sub_FF81BEA8\n"
							"STR     R0, [R5,#0x14]\n"
							"MOV     R0, R5\n"
							"BL      sub_FFB0D740\n"
							"BL      sub_FFB0E134\n"
							"MOV     R0, R5\n"
							"BL      sub_FFB0D858_my\n"	  //------------>
              "BL      capt_seq_hook_raw_here\n"  // +							
							"B       loc_FFB0A730\n"
"loc_FFB0A71C:\n"
							"LDR     R3, =0xCF60\n"
							"LDR     R2, [R3]\n"
							"CMP     R2, #0\n"
							"MOVNE   R0, #0x1D\n"
							"MOVEQ   R0, #0\n"
"loc_FFB0A730:\n"
							"MOV     R1, #1\n"
							"MOV     R2, R5\n"
							"BL      sub_FFB08E28\n"
							"BL      sub_FFB0DBD4\n"
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
							"B       loc_FFB0ACB8\n"
"loc_FFB0AB3C:\n"
							"LDR     R2, [SP]\n"		// ,#0xC+var_C
							"LDR     R3, [R2]\n"
							"MOV     R0, R2\n"
							"CMP     R3, #0x15\n"
							"LDRLS   PC, [PC,R3,LSL#2]\n"
							"B       loc_FFB0AC8C\n"
							".long 	 loc_FFB0ABAC\n"
							".long 	 loc_FFB0ABCC\n"
							".long 	 loc_FFB0ABE0\n"
							".long 	 loc_FFB0ABF4\n"
							".long 	 loc_FFB0ABEC\n"
							".long 	 loc_FFB0ABFC\n"
							".long 	 loc_FFB0AC04\n"
							".long 	 loc_FFB0AC10\n"
							".long 	 loc_FFB0AC18\n"
							".long 	 loc_FFB0AC24\n"
							".long 	 loc_FFB0AC2C\n"
							".long 	 loc_FFB0AC34\n"
							".long 	 loc_FFB0AC3C\n"
							".long 	 loc_FFB0AC44\n"
							".long 	 loc_FFB0AC4C\n"
							".long 	 loc_FFB0AC58\n"
							".long 	 loc_FFB0AC60\n"
							".long 	 loc_FFB0AC68\n"
							".long 	 loc_FFB0AC70\n"
							".long 	 loc_FFB0AC7C\n"
							".long 	 loc_FFB0AC84\n"
							".long 	 loc_FFB0ACA0\n"
"loc_FFB0ABAC:\n"
							"BL      sub_FFB0B1A0\n"
              "BL      shooting_expo_param_override\n" // +														
							"BL      sub_FFB088B0\n"
							"LDR     R3, =0xBE160\n"
							"LDR     R2, [R3,#0x24]\n"
							"CMP     R2, #0\n"
							"BEQ     loc_FFB0AC9C\n"
							"BL      sub_FFB0A75C\n"
							"B       loc_FFB0AC9C\n"
"loc_FFB0ABCC:\n"
							"BL      sub_FFB0A680_my\n"	//------------>
"loc_FFB0ABD0:\n"
							"LDR     R2, =0xBE160\n"
							"MOV     R3, #0\n"
							"STR     R3, [R2,#0x24]\n"
							"B       loc_FFB0AC9C\n"
"loc_FFB0ABE0:\n"
							"MOV     R0, #1\n"
							"BL      sub_FFB0B3C0\n"
							"B       loc_FFB0AC9C\n"
"loc_FFB0ABEC:\n"
							"BL      sub_FFB0ADA0\n"
							"B       loc_FFB0ABD0\n"
"loc_FFB0ABF4:\n"
							"BL      sub_FFB0B158\n"	// BackLightDrv_LcdBackLightOff_15
							"B       loc_FFB0ABD0\n"
"loc_FFB0ABFC:\n"
							"BL      sub_FFB0B168\n"
							"B       loc_FFB0AC9C\n"
"loc_FFB0AC04:\n"
							"BL      sub_FFB0B2B8\n"
							"BL      sub_FFB088B0\n"
							"B       loc_FFB0AC9C\n"
"loc_FFB0AC10:\n"
							"BL      sub_FFB0A838\n"
							"B       loc_FFB0AC9C\n"
"loc_FFB0AC18:\n"
							"BL      sub_FFB0B328\n"
							"BL      sub_FFB088B0\n"
							"B       loc_FFB0AC9C\n"
"loc_FFB0AC24:\n"
							"BL      sub_FFB0B158\n"	// BackLightDrv_LcdBackLightOff_15
							"B       loc_FFB0AC9C\n"
"loc_FFB0AC2C:\n"
							"BL      sub_FFB0CA90\n"
							"B       loc_FFB0AC9C\n"
"loc_FFB0AC34:\n"
							"BL      sub_FFB0CC64\n"
							"B       loc_FFB0AC9C\n"
"loc_FFB0AC3C:\n"
							"BL      sub_FFB0CCF8\n"
							"B       loc_FFB0AC9C\n"
"loc_FFB0AC44:\n"
							"BL      sub_FFB0CDF4\n"
							"B       loc_FFB0AC9C\n"
"loc_FFB0AC4C:\n"
							"MOV     R0, #0\n"
							"BL      sub_FFB0D060\n"
							"B       loc_FFB0AC9C\n"
"loc_FFB0AC58:\n"
							"BL      sub_FFB0D234\n"
							"B       loc_FFB0AC9C\n"
"loc_FFB0AC60:\n"
							"BL      sub_FFB0D2D0\n"
							"B       loc_FFB0AC9C\n"
"loc_FFB0AC68:\n"
							"BL      sub_FFB0D390\n"
							"B       loc_FFB0AC9C\n"
"loc_FFB0AC70:\n"
							"BL      sub_FFB0B514\n"
							"BL      sub_FFB0A5A4\n"
							"B       loc_FFB0AC9C\n"
"loc_FFB0AC7C:\n"
							"BL      sub_FFB0CF34\n"
							"B       loc_FFB0AC9C\n"
"loc_FFB0AC84:\n"
							"BL      sub_FFB0CF90\n"
							"B       loc_FFB0AC9C\n"
"loc_FFB0AC8C:\n"
							"MOV     R1, #0x4C0\n"
							"LDR     R0, =0xFFB0A400\n"		// aSsshoottask_c
							"ADD     R1, R1, #0xE\n"
							"BL      sub_FFB2C0C4\n"		// DebugAssert
"loc_FFB0AC9C:\n"
							"LDR     R2, [SP]\n"		// ,#0xC+var_C
"loc_FFB0ACA0:\n"
							"LDR     R3, =0x97A30\n"
							"LDR     R1, [R2,#4]\n"
							"LDR     R0, [R3]\n"
							"BL      sub_FFB1E89C\n"		// SetEventFlag
							"LDR     R0, [SP]\n"		// ,#0xC+var_C
							"BL      sub_FFB0A480\n"
"loc_FFB0ACB8:\n"
							"LDR     R3, =0x97A34\n"
							"MOV     R1, R4\n"
							"LDR     R0, [R3]\n"
							"MOV     R2, #0\n"
							"BL      sub_FFB1EFB4\n"		// ReceiveMessageQueue
							"TST     R0, #1\n"
							"BEQ     loc_FFB0AB3C\n"
							"LDR     R0, =0xFFB0A400\n"		// aSsshoottask_c
							"MOV     R1, #0x400\n"
							"BL      sub_FFB2C0C4\n"		// DebugAssert
							"BL      sub_FFB20578\n"
							"ADD     SP, SP, #4\n"
							"LDMFD   SP!, {R4,PC}\n"
	);
}

