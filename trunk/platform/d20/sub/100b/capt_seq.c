#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"

static long *nrflag = (long*)(0x9cf4+0x00);  // Found @ ff232ebc & ff232f1c
#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto
#define PAUSE_FOR_FILE_COUNTER 200          //Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"

//** capt_seq_task  @ 0xFF069298

void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
      "STMFD   SP!, {R3-R9,LR}\n"
      "LDR     R4, =0x3979C\n"
      "LDR     R7, =0x2E9C\n"
      "MOV     R6, #0\n"
"loc_FF0692A8:\n"
      "LDR     R0, [R7, #4]\n"
      "MOV     R2, #0\n"
      "MOV     R1, SP\n"
      "BL      sub_00477218\n"
      "TST     R0, #1\n"
      "BEQ     loc_FF0692D4\n"
      "LDR     R1, =0x493\n"
      "LDR     R0, =0xFF068D54\n"
      "BL      _DebugAssert\n"
      "BL      _ExitTask\n"
      "LDMFD   SP!, {R3-R9,PC}\n"
"loc_FF0692D4:\n"
      "LDR     R0, [SP]\n"
      "LDR     R1, [R0]\n"
      "CMP     R1, #0x24\n"
      "ADDCC   PC, PC, R1, LSL #2\n"
      "B       loc_FF069580\n"
      "B       loc_FF069378\n"
      "B       loc_FF069390\n"
      "B       loc_FF069400\n"
      "B       loc_FF069414\n"
      "B       loc_FF06940C\n"
      "B       loc_FF069420\n"
      "B       loc_FF069428\n"
      "B       loc_FF069430\n"
      "B       loc_FF06944C\n"
      "B       loc_FF0694A0\n"
      "B       loc_FF069458\n"
      "B       loc_FF069464\n"
      "B       loc_FF06946C\n"
      "B       loc_FF069488\n"
      "B       loc_FF069490\n"
      "B       loc_FF069498\n"
      "B       loc_FF0694A8\n"
      "B       loc_FF0694B0\n"
      "B       loc_FF0694B8\n"
      "B       loc_FF0694C0\n"
      "B       loc_FF0694C8\n"
      "B       loc_FF0694D0\n"
      "B       loc_FF0694D8\n"
      "B       loc_FF0694E0\n"
      "B       loc_FF0694E8\n"
      "B       loc_FF0694F4\n"
      "B       loc_FF0694FC\n"
      "B       loc_FF069508\n"
      "B       loc_FF069510\n"
      "B       loc_FF069518\n"
      "B       loc_FF069520\n"
      "B       loc_FF069528\n"
      "B       loc_FF069534\n"
      "B       loc_FF06953C\n"
      "B       loc_FF069548\n"
      "B       loc_FF06958C\n"
"loc_FF069378:\n"
      "BL      shooting_expo_iso_override\n"  //patch
      "BL      sub_FF069B54\n"
      "BL      shooting_expo_param_override\n" //patch
      "BL      sub_FF066DD8\n"
//PATCH BEGIN
//      "LDR     R0, [R4, #0x28]\n"
//      "CMP     R0, #0\n"
//      "BLNE    sub_FF1830C0\n"
      "MOV     R0, #0\n"
      "STR     R0, [R4,#0x28]\n"  //fixes overrides  behavior at short shutter press
//PATCH END
      "B       loc_FF06958C\n"
"loc_FF069390:\n"
      "LDR     R5, [R0, #0x10]\n"
      "LDR     R0, [R4, #0x28]\n"
      "CMP     R0, #0\n"
      "BNE     loc_FF0693D8\n"
      "LDR     R0, [R4, #0x94]\n"
      "TST     R0, #0x30\n"
      "BLNE    sub_FF06B524\n"
      "BL      sub_FF06B204\n"
      "MOV     R1, R5\n"
      "BL      sub_FF06B25C\n"
      "LDR     R0, =0x10F\n"
      "MOV     R2, #4\n"
      "ADD     R1, R5, #0x24\n"
      "BL      _SetPropertyCase\n"
      "MOV     R2, #4\n"
      "ADD     R1, R5, #0x28\n"
      "MOV     R0, #0x2C\n"
      "BL      _SetPropertyCase\n"
"loc_FF0693D8:\n"
      "MOV     R0, R5\n"
//PATCH BEGIN
//      "BL      sub_FF18301C\n"  //original
      "BL      sub_FF18301C_my\n" //patched
      "BL     capt_seq_hook_raw_here\n"
//PATCH END
      "MOV     R8, R0\n"
      "MOV     R2, R5\n"
      "MOV     R1, #1\n"
      "BL      sub_FF06736C\n"
      "TST     R8, #1\n"
      "MOVEQ   R0, R5\n"
      "BLEQ    sub_FF182960\n"
      "B       loc_FF06958C\n"
"loc_FF069400:\n"
      "MOV     R0, #1\n"
      "BL      sub_FF069E50\n"
      "B       loc_FF06958C\n"
"loc_FF06940C:\n"
      "BL      sub_FF069760\n"
      "B       loc_FF069418\n"
"loc_FF069414:\n"
      "BL      sub_FF069B34\n"
"loc_FF069418:\n"
      "STR     R6, [R4, #0x28]\n"
      "B       loc_FF06958C\n"
"loc_FF069420:\n"
      "BL      sub_FF069B3C\n"
      "B       loc_FF06958C\n"
"loc_FF069428:\n"
      "BL      sub_FF069D28\n"
      "B       loc_FF069450\n"
"loc_FF069430:\n"
      "LDR     R5, [R0, #0x10]\n"
      "MOV     R0, R5\n"
      "BL      sub_FF18315C\n"
      "MOV     R2, R5\n"
      "MOV     R1, #9\n"
      "BL      sub_FF06736C\n"
      "B       loc_FF06958C\n"
"loc_FF06944C:\n"
      "BL      sub_FF069DB8\n"
"loc_FF069450:\n"
      "BL      sub_FF066DD8\n"
      "B       loc_FF06958C\n"
"loc_FF069458:\n"
      "LDR     R0, [R4, #0x58]\n"
      "BL      sub_FF06A4CC\n"
      "B       loc_FF06958C\n"
"loc_FF069464:\n"
      "BL      sub_FF06A7C0\n"
      "B       loc_FF06958C\n"
"loc_FF06946C:\n"
      "LDRH    R0, [R4]\n"
      "SUB     R1, R0, #0x4200\n"
      "SUBS    R1, R1, #0x39\n"
      "MOVNE   R0, #0\n"
      "MOVEQ   R0, #1\n"
      "BL      sub_FF06A824\n"
      "B       loc_FF06958C\n"
"loc_FF069488:\n"
      "BL      sub_FF06AA10\n"
      "B       loc_FF06958C\n"
"loc_FF069490:\n"
      "BL      sub_FF06AE74\n"
      "B       loc_FF06958C\n"
"loc_FF069498:\n"
      "BL      sub_FF06AF28\n"
      "B       loc_FF06958C\n"
"loc_FF0694A0:\n"
      "BL      sub_FF069B34\n"
      "B       loc_FF06958C\n"
"loc_FF0694A8:\n"
      "BL      sub_FF181C34\n"
      "B       loc_FF06958C\n"
"loc_FF0694B0:\n"
      "BL      sub_FF181E9C\n"
      "B       loc_FF06958C\n"
"loc_FF0694B8:\n"
      "BL      sub_FF181F54\n"
      "B       loc_FF06958C\n"
"loc_FF0694C0:\n"
      "BL      sub_FF182028\n"
      "B       loc_FF06958C\n"
"loc_FF0694C8:\n"
      "MOV     R0, #0\n"
      "B       loc_FF0694EC\n"
"loc_FF0694D0:\n"
      "BL      sub_FF18244C\n"
      "B       loc_FF06958C\n"
"loc_FF0694D8:\n"
      "BL      sub_FF1824E0\n"
      "B       loc_FF06958C\n"
"loc_FF0694E0:\n"
      "BL      sub_FF182598\n"
      "B       loc_FF06958C\n"
"loc_FF0694E8:\n"
      "MOV     R0, #1\n"
"loc_FF0694EC:\n"
      "BL      sub_FF1822DC\n"
      "B       loc_FF06958C\n"
"loc_FF0694F4:\n"
      "BL      sub_FF06A008\n"
      "B       loc_FF06958C\n"
"loc_FF0694FC:\n"
      "BL      sub_FF06A09C\n"
      "BL      sub_FF021F04\n"
      "B       loc_FF06958C\n"
"loc_FF069508:\n"
      "BL      sub_FF1820F8\n"
      "B       loc_FF06958C\n"
"loc_FF069510:\n"
      "BL      sub_FF182160\n"
      "B       loc_FF06958C\n"
"loc_FF069518:\n"
      "BL      sub_FF06C7E0\n"
      "B       loc_FF06958C\n"
"loc_FF069520:\n"
      "BL      sub_FF06C868\n"
      "B       loc_FF06958C\n"
"loc_FF069528:\n"
      "LDR     R0, [R0, #0xC]\n"
      "BL      sub_FF1826B0\n"
      "B       loc_FF06958C\n"
"loc_FF069534:\n"
      "BL      sub_FF182720\n"
      "B       loc_FF06958C\n"
"loc_FF06953C:\n"
      "BL      sub_FF06C8D0\n"
      "BL      sub_FF06C888\n"
      "B       loc_FF06958C\n"
"loc_FF069548:\n"
      "MOV     R0, #1\n"
      "BL      sub_FF183874\n"
      "MOV     R0, #1\n"
      "BL      sub_FF1839A8\n"
      "LDRH    R0, [R4, #0xA4]\n"
      "CMP     R0, #4\n"
      "LDRNEH  R0, [R4]\n"
      "SUBNE   R1, R0, #0x4200\n"
      "SUBNES  R1, R1, #0x2E\n"
      "BNE     loc_FF06958C\n"
      "BL      sub_FF06C868\n"
      "BL      sub_FF06CEB8\n"
      "BL      sub_FF06CCF8\n"
      "B       loc_FF06958C\n"
"loc_FF069580:\n"
      "LDR     R1, =0x5F4\n"
      "LDR     R0, =0xFF068D54\n"
      "BL      _DebugAssert\n"
"loc_FF06958C:\n"
      "LDR     R0, [SP]\n"
      "LDR     R1, [R0, #4]\n"
      "LDR     R0, [R7]\n"
      "BL      sub_0047AC6C\n"
      "LDR     R5, [SP]\n"
      "LDR     R0, [R5, #8]\n"
      "CMP     R0, #0\n"
      "LDREQ   R1, =0x117\n"
      "LDREQ   R0, =0xFF068D54\n"
      "BLEQ    _DebugAssert\n"
      "STR     R6, [R5, #8]\n"
      "B       loc_FF0692A8\n"
	);
}

//** sub_FF18301C_my  @ 0xFF18301C
//CHECK THIS!!!
void __attribute__((naked,noinline)) sub_FF18301C_my(  ) {
asm volatile (
      "STMFD   SP!, {R4-R6,LR}\n"
      "LDR     R5, =0x3979C\n"
      "MOV     R6, R0\n"
      "LDR     R0, [R5, #0x28]\n"
      "MOV     R4, #0\n"
      "CMP     R0, #0\n"
      "BNE     loc_FF18304C\n"
      "MOV     R0, #0xC\n"
      "BL      sub_FF06E680\n"
      "TST     R0, #1\n"
      "MOVNE   R0, #1\n"
      "LDMNEFD SP!, {R4-R6,PC}\n"
"loc_FF18304C:\n"
      "BL      sub_FF069B44\n"
      "LDR     R0, [R5, #0x28]\n"
      "CMP     R0, #0\n"
      "BNE     loc_FF1830A8\n"
      "MOV     R0, R6\n"
      "BL      sub_FF18289C\n"
      "TST     R0, #1\n"
      "LDMNEFD SP!, {R4-R6,PC}\n"
      "MOV     R0, R6\n"
      "BL      sub_FF182C4C\n"
      "BL      sub_FF183640\n"
      "BL      sub_FF0671E8\n"

//This was not tested:
//begin patch
      "BL      wait_until_remote_button_is_released\n"  
      "BL      capt_seq_hook_set_nr\n"      
//end patch

      "MOV     R0, #2\n"
      "BL      sub_FF06FE00\n"
      "LDR     R0, [R5, #0x94]\n"
      "TST     R0, #0x10\n"
      "MOV     R0, R6\n"
      "BEQ     loc_FF18309C\n"
      "BL      sub_FF2EAD40\n"
      "B       loc_FF1830A0\n"
"loc_FF18309C:\n"
      "BL      sub_FF2EA910\n"
"loc_FF1830A0:\n"
      "MOV     R4, R0\n"
      "B       loc_FF1830B8\n"
"loc_FF1830A8:\n"
      "LDR     R0, =0x724C\n"
      "LDR     R0, [R0]\n"
      "CMP     R0, #0\n"
      "MOVNE   R4, #0x1D\n"
"loc_FF1830B8:\n"
      "MOV     R0, R4\n"
      "LDMFD   SP!, {R4-R6,PC}\n"
	);
}


//** exp_drv_task  @ 0xFF0B20B4 

void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
      "STMFD   SP!, {R4-R9,LR}\n"
      "SUB     SP, SP, #0x2C\n"
      "LDR     R6, =0x42E8\n"
      "LDR     R7, =0xBB8\n"
      "LDR     R4, =0x567A0\n"
      "MOV     R0, #0\n"
      "ADD     R5, SP, #0x1C\n"
      "STR     R0, [SP, #0xC]\n"
"loc_FF0B20D4:\n"
      "LDR     R0, [R6, #0x20]\n"
      "MOV     R2, #0\n"
      "ADD     R1, SP, #0x28\n"
      "BL      sub_00477218\n"
      "LDR     R0, [SP, #0xC]\n"
      "CMP     R0, #1\n"
      "BNE     loc_FF0B2120\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R0, [R0]\n"
      "CMP     R0, #0x14\n"
      "CMPNE   R0, #0x15\n"
      "CMPNE   R0, #0x16\n"
      "CMPNE   R0, #0x17\n"
      "BEQ     loc_FF0B2280\n"
      "CMP     R0, #0x2A\n"
      "BEQ     loc_FF0B2208\n"
      "ADD     R1, SP, #0xC\n"
      "MOV     R0, #0\n"
      "BL      sub_FF0B2064\n"
"loc_FF0B2120:\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0]\n"
      "CMP     R1, #0x30\n"
      "BNE     loc_FF0B214C\n"
      "BL      sub_FF0B34B0\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R1, #1\n"
      "BL      sub_0047AC6C\n"
      "BL      _ExitTask\n"
      "ADD     SP, SP, #0x2C\n"
      "LDMFD   SP!, {R4-R9,PC}\n"
"loc_FF0B214C:\n"
      "CMP     R1, #0x2F\n"
      "BNE     loc_FF0B2168\n"
      "LDR     R2, [R0, #0x8C]!\n"
      "LDR     R1, [R0, #4]\n"
      "MOV     R0, R1\n"
      "BLX     R2\n"
      "B       loc_FF0B273C\n"
"loc_FF0B2168:\n"
      "CMP     R1, #0x28\n"
      "BNE     loc_FF0B21B8\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R1, #0x80\n"
      "BL      sub_0047ACA0\n"
      "LDR     R0, =0xFF0ACF98\n"
      "MOV     R1, #0x80\n"
      "BL      sub_FF173A58\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R2, R7\n"
      "MOV     R1, #0x80\n"
      "BL      sub_0047ABAC\n"
      "TST     R0, #1\n"
      "LDRNE   R1, =0x1599\n"
      "BNE     loc_FF0B2274\n"
"loc_FF0B21A4:\n"
      "LDR     R1, [SP, #0x28]\n"
      "LDR     R0, [R1, #0x90]\n"
      "LDR     R1, [R1, #0x8C]\n"
      "BLX     R1\n"
      "B       loc_FF0B273C\n"
"loc_FF0B21B8:\n"
      "CMP     R1, #0x29\n"
      "BNE     loc_FF0B2200\n"
      "ADD     R1, SP, #0xC\n"
      "BL      sub_FF0B2064\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R1, #0x100\n"
      "BL      sub_0047ACA0\n"
      "LDR     R0, =0xFF0ACFA8\n"
      "MOV     R1, #0x100\n"
      "BL      sub_FF173BF8\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R2, R7\n"
      "MOV     R1, #0x100\n"
      "BL      sub_0047ABAC\n"
      "TST     R0, #1\n"
      "BEQ     loc_FF0B21A4\n"
      "LDR     R1, =0x15A3\n"
      "B       loc_FF0B2274\n"
"loc_FF0B2200:\n"
      "CMP     R1, #0x2A\n"
      "BNE     loc_FF0B2218\n"
"loc_FF0B2208:\n"
      "LDR     R0, [SP, #0x28]\n"
      "ADD     R1, SP, #0xC\n"
      "BL      sub_FF0B2064\n"
      "B       loc_FF0B21A4\n"
"loc_FF0B2218:\n"
      "CMP     R1, #0x2D\n"
      "BNE     loc_FF0B2230\n"
      "BL      sub_FF09DAB8\n"
      "BL      sub_FF09E78C\n"
      "BL      sub_FF09E2F8\n"
      "B       loc_FF0B21A4\n"
"loc_FF0B2230:\n"
      "CMP     R1, #0x2E\n"
      "BNE     loc_FF0B2280\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R1, #4\n"
      "BL      sub_0047ACA0\n"
      "LDR     R1, =0xFF0ACFC8\n"
      "LDR     R0, =0xFFFFF400\n"
      "MOV     R2, #4\n"
      "BL      sub_FF09D508\n"
      "BL      sub_FF09D798\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R2, R7\n"
      "MOV     R1, #4\n"
      "BL      sub_0047AAC8\n"
      "TST     R0, #1\n"
      "BEQ     loc_FF0B21A4\n"
      "LDR     R1, =0x15CB\n"
"loc_FF0B2274:\n"
      "LDR     R0, =0xFF0AD7A0\n"
      "BL      _DebugAssert\n"
      "B       loc_FF0B21A4\n"
"loc_FF0B2280:\n"
      "LDR     R0, [SP, #0x28]\n"
      "MOV     R8, #1\n"
      "LDR     R1, [R0]\n"
      "CMP     R1, #0x12\n"
      "CMPNE   R1, #0x13\n"
      "BNE     loc_FF0B22E8\n"
      "LDR     R1, [R0, #0x7C]\n"
      "ADD     R1, R1, R1, LSL #1\n"
      "ADD     R1, R0, R1, LSL #2\n"
      "SUB     R1, R1, #8\n"
      "LDMIA   R1, {R2,R3,R9}\n"
      "STMIA   R5, {R2,R3,R9}\n"
      "BL      sub_FF0B0228\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R3, [R0, #0x8C]\n"
      "LDR     R2, [R0, #0x90]\n"
      "ADD     R0, R0, #4\n"
      "BLX     R3\n"
      "LDR     R0, [SP, #0x28]\n"
      "BL      sub_FF0B38D0\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R2, [R0, #0x98]\n"
      "LDR     R3, [R0, #0x94]\n"
      "B       loc_FF0B2600\n"
"loc_FF0B22E8:\n"
      "CMP     R1, #0x14\n"
      "CMPNE   R1, #0x15\n"
      "CMPNE   R1, #0x16\n"
      "CMPNE   R1, #0x17\n"
      "BNE     loc_FF0B23A0\n"
      "ADD     R3, SP, #0xC\n"
      "MOV     R2, SP\n"
      "ADD     R1, SP, #0x1C\n"
      "BL      sub_FF0B0488\n"
      "CMP     R0, #1\n"
      "MOV     R9, R0\n"
      "CMPNE   R9, #5\n"
      "BNE     loc_FF0B233C\n"
      "LDR     R0, [SP, #0x28]\n"
      "MOV     R2, R9\n"
      "LDR     R1, [R0, #0x7C]!\n"
      "LDR     R12, [R0, #0x10]!\n"
      "LDR     R3, [R0, #4]\n"
      "MOV     R0, SP\n"
      "BLX     R12\n"
      "B       loc_FF0B2374\n"
"loc_FF0B233C:\n"
      "LDR     R0, [SP, #0x28]\n"
      "CMP     R9, #2\n"
      "LDR     R3, [R0, #0x90]\n"
      "CMPNE   R9, #6\n"
      "BNE     loc_FF0B2388\n"
      "LDR     R12, [R0, #0x8C]\n"
      "MOV     R2, R9\n"
      "MOV     R1, #1\n"
      "MOV     R0, SP\n"
      "BLX     R12\n"
      "LDR     R0, [SP, #0x28]\n"
      "MOV     R2, SP\n"
      "ADD     R1, SP, #0x1C\n"
      "BL      sub_FF0B1D3C\n"
"loc_FF0B2374:\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R2, [SP, #0xC]\n"
      "MOV     R1, R9\n"
      "BL      sub_FF0B2004\n"
      "B       loc_FF0B2608\n"
"loc_FF0B2388:\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R12, [R0, #0x8C]\n"
      "MOV     R2, R9\n"
      "ADD     R0, R0, #4\n"
      "BLX     R12\n"
      "B       loc_FF0B2608\n"
"loc_FF0B23A0:\n"
      "CMP     R1, #0x24\n"
      "CMPNE   R1, #0x25\n"
      "BNE     loc_FF0B23EC\n"
      "LDR     R1, [R0, #0x7C]\n"
      "ADD     R1, R1, R1, LSL #1\n"
      "ADD     R1, R0, R1, LSL #2\n"
      "SUB     R1, R1, #8\n"
      "LDMIA   R1, {R2,R3,R9}\n"
      "STMIA   R5, {R2,R3,R9}\n"
      "BL      sub_FF0AEFA8\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R3, [R0, #0x8C]\n"
      "LDR     R2, [R0, #0x90]\n"
      "ADD     R0, R0, #4\n"
      "BLX     R3\n"
      "LDR     R0, [SP, #0x28]\n"
      "BL      sub_FF0AF47C\n"
      "B       loc_FF0B2608\n"
"loc_FF0B23EC:\n"
      "ADD     R1, R0, #4\n"
      "LDMIA   R1, {R2,R3,R9}\n"
      "STMIA   R5, {R2,R3,R9}\n"
      "LDR     R1, [R0]\n"
      "CMP     R1, #0x28\n"
      "ADDCC   PC, PC, R1, LSL #2\n"
      "B       loc_FF0B25F0\n"
      "B       loc_FF0B24A8\n"
      "B       loc_FF0B24A8\n"
      "B       loc_FF0B24B0\n"
      "B       loc_FF0B24B8\n"
      "B       loc_FF0B24B8\n"
      "B       loc_FF0B24B8\n"
      "B       loc_FF0B24A8\n"
      "B       loc_FF0B24B0\n"
      "B       loc_FF0B24B8\n"
      "B       loc_FF0B24B8\n"
      "B       loc_FF0B24D0\n"
      "B       loc_FF0B24D0\n"
      "B       loc_FF0B25DC\n"
      "B       loc_FF0B25E4\n"
      "B       loc_FF0B25E4\n"
      "B       loc_FF0B25E4\n"
      "B       loc_FF0B25E4\n"
      "B       loc_FF0B25EC\n"
      "B       loc_FF0B25F0\n"
      "B       loc_FF0B25F0\n"
      "B       loc_FF0B25F0\n"
      "B       loc_FF0B25F0\n"
      "B       loc_FF0B25F0\n"
      "B       loc_FF0B25F0\n"
      "B       loc_FF0B24C0\n"
      "B       loc_FF0B24C8\n"
      "B       loc_FF0B24C8\n"
      "B       loc_FF0B24C8\n"
      "B       loc_FF0B24DC\n"
      "B       loc_FF0B24DC\n"
      "B       loc_FF0B24E4\n"
      "B       loc_FF0B251C\n"
      "B       loc_FF0B2554\n"
      "B       loc_FF0B258C\n"
      "B       loc_FF0B25C4\n"
      "B       loc_FF0B25C4\n"
      "B       loc_FF0B25F0\n"
      "B       loc_FF0B25F0\n"
      "B       loc_FF0B25CC\n"
      "B       loc_FF0B25D4\n"
"loc_FF0B24A8:\n"
      "BL      sub_FF0AD5D4\n"
      "B       loc_FF0B25F0\n"
"loc_FF0B24B0:\n"
      "BL      sub_FF0AD8CC\n"
      "B       loc_FF0B25F0\n"
"loc_FF0B24B8:\n"
      "BL      sub_FF0ADB34\n"
      "B       loc_FF0B25F0\n"
"loc_FF0B24C0:\n"
      "BL      sub_FF0ADE28\n"
      "B       loc_FF0B25F0\n"
"loc_FF0B24C8:\n"
      "BL      sub_FF0AE040\n"
      "B       loc_FF0B25F0\n"
"loc_FF0B24D0:\n"
//      "BL      sub_FF0AE530\n" //original
      "BL      sub_FF0AE530_my\n"   //patched
      "MOV     R8, #0\n"
      "B       loc_FF0B25F0\n"
"loc_FF0B24DC:\n"
      "BL      sub_FF0AE70C\n"
      "B       loc_FF0B25F0\n"
"loc_FF0B24E4:\n"
      "LDRH    R1, [R0, #4]\n"
      "STRH    R1, [SP, #0x1C]\n"
      "LDRH    R1, [R4, #2]\n"
      "STRH    R1, [SP, #0x1E]\n"
      "LDRH    R1, [R4, #4]\n"
      "STRH    R1, [SP, #0x20]\n"
      "LDRH    R1, [R4, #6]\n"
      "STRH    R1, [SP, #0x22]\n"
      "LDRH    R1, [R0, #0xC]\n"
      "STRH    R1, [SP, #0x24]\n"
      "LDRH    R1, [R4, #0xA]\n"
      "STRH    R1, [SP, #0x26]\n"
      "BL      sub_FF0B3544\n"
      "B       loc_FF0B25F0\n"
"loc_FF0B251C:\n"
      "LDRH    R1, [R0, #4]\n"
      "STRH    R1, [SP, #0x1C]\n"
      "LDRH    R1, [R4, #2]\n"
      "STRH    R1, [SP, #0x1E]\n"
      "LDRH    R1, [R4, #4]\n"
      "STRH    R1, [SP, #0x20]\n"
      "LDRH    R1, [R4, #6]\n"
      "STRH    R1, [SP, #0x22]\n"
      "LDRH    R1, [R4, #8]\n"
      "STRH    R1, [SP, #0x24]\n"
      "LDRH    R1, [R4, #0xA]\n"
      "STRH    R1, [SP, #0x26]\n"
      "BL      sub_FF0B36D0\n"
      "B       loc_FF0B25F0\n"
"loc_FF0B2554:\n"
      "LDRH    R1, [R4]\n"
      "STRH    R1, [SP, #0x1C]\n"
      "LDRH    R1, [R0, #6]\n"
      "STRH    R1, [SP, #0x1E]\n"
      "LDRH    R1, [R4, #4]\n"
      "STRH    R1, [SP, #0x20]\n"
      "LDRH    R1, [R4, #6]\n"
      "STRH    R1, [SP, #0x22]\n"
      "LDRH    R1, [R4, #8]\n"
      "STRH    R1, [SP, #0x24]\n"
      "LDRH    R1, [R4, #0xA]\n"
      "STRH    R1, [SP, #0x26]\n"
      "BL      sub_FF0B3784\n"
      "B       loc_FF0B25F0\n"
"loc_FF0B258C:\n"
      "LDRH    R1, [R4]\n"
      "STRH    R1, [SP, #0x1C]\n"
      "LDRH    R1, [R4, #2]\n"
      "STRH    R1, [SP, #0x1E]\n"
      "LDRH    R1, [R4, #4]\n"
      "STRH    R1, [SP, #0x20]\n"
      "LDRH    R1, [R4, #6]\n"
      "STRH    R1, [SP, #0x22]\n"
      "LDRH    R1, [R0, #0xC]\n"
      "STRH    R1, [SP, #0x24]\n"
      "LDRH    R1, [R4, #0xA]\n"
      "STRH    R1, [SP, #0x26]\n"
      "BL      sub_FF0B382C\n"
      "B       loc_FF0B25F0\n"
"loc_FF0B25C4:\n"
      "BL      sub_FF0AED5C\n"
      "B       loc_FF0B25F0\n"
"loc_FF0B25CC:\n"
      "BL      sub_FF0AF580\n"
      "B       loc_FF0B25F0\n"
"loc_FF0B25D4:\n"
      "BL      sub_FF0AFAD8\n"
      "B       loc_FF0B25F0\n"
"loc_FF0B25DC:\n"
      "BL      sub_FF0AFCFC\n"
      "B       loc_FF0B25F0\n"
"loc_FF0B25E4:\n"
      "BL      sub_FF0AFEB8\n"
      "B       loc_FF0B25F0\n"
"loc_FF0B25EC:\n"
      "BL      sub_FF0B0020\n"
"loc_FF0B25F0:\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R2, [R0, #0x90]\n"
      "LDR     R3, [R0, #0x8C]\n"
"loc_FF0B2600:\n"
      "ADD     R0, R0, #4\n"
      "BLX     R3\n"
"loc_FF0B2608:\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R0, [R0]\n"
      "CMP     R0, #0x10\n"
      "BEQ     loc_FF0B2640\n"
      "BGT     loc_FF0B2630\n"
      "CMP     R0, #1\n"
      "CMPNE   R0, #4\n"
      "CMPNE   R0, #0xE\n"
      "BNE     loc_FF0B2674\n"
      "B       loc_FF0B2640\n"
"loc_FF0B2630:\n"
      "CMP     R0, #0x13\n"
      "CMPNE   R0, #0x17\n"
      "CMPNE   R0, #0x1A\n"
      "BNE     loc_FF0B2674\n"
"loc_FF0B2640:\n"
      "LDRSH   R0, [R4]\n"
      "CMN     R0, #0xC00\n"
      "LDRNESH R1, [R4, #8]\n"
      "CMNNE   R1, #0xC00\n"
      "STRNEH  R0, [SP, #0x1C]\n"
      "STRNEH  R1, [SP, #0x24]\n"
      "BNE     loc_FF0B2674\n"
      "ADD     R0, SP, #0x10\n"
      "BL      sub_FF0B3AE0\n"
      "LDRH    R0, [SP, #0x10]\n"
      "STRH    R0, [SP, #0x1C]\n"
      "LDRH    R0, [SP, #0x18]\n"
      "STRH    R0, [SP, #0x24]\n"
"loc_FF0B2674:\n"
      "LDR     R0, [SP, #0x28]\n"
      "CMP     R8, #1\n"
      "BNE     loc_FF0B26C4\n"
      "LDR     R1, [R0, #0x7C]\n"
      "MOV     R2, #0xC\n"
      "ADD     R1, R1, R1, LSL #1\n"
      "ADD     R0, R0, R1, LSL #2\n"
      "SUB     R8, R0, #8\n"
      "LDR     R0, =0x567A0\n"
      "ADD     R1, SP, #0x1C\n"
      "BL      sub_0047C17C\n"
      "LDR     R0, =0x567AC\n"
      "MOV     R2, #0xC\n"
      "ADD     R1, SP, #0x1C\n"
      "BL      sub_0047C17C\n"
      "LDR     R0, =0x567B8\n"
      "MOV     R2, #0xC\n"
      "MOV     R1, R8\n"
      "BL      sub_0047C17C\n"
      "B       loc_FF0B273C\n"
"loc_FF0B26C4:\n"
      "LDR     R0, [R0]\n"
      "MOV     R3, #1\n"
      "CMP     R0, #0xB\n"
      "BNE     loc_FF0B2708\n"
      "MOV     R2, #0\n"
      "STRD    R2, [SP]\n"
      "MOV     R2, R3\n"
      "MOV     R1, R3\n"
      "MOV     R0, #0\n"
      "BL      sub_FF0AD3B4\n"
      "MOV     R3, #1\n"
      "MOV     R2, #0\n"
      "STRD    R2, [SP]\n"
      "MOV     R2, R3\n"
      "MOV     R1, R3\n"
      "MOV     R0, #0\n"
      "B       loc_FF0B2738\n"
"loc_FF0B2708:\n"
      "MOV     R2, #1\n"
      "STRD    R2, [SP]\n"
      "MOV     R3, R2\n"
      "MOV     R1, R2\n"
      "MOV     R0, R2\n"
      "BL      sub_FF0AD3B4\n"
      "MOV     R3, #1\n"
      "MOV     R2, R3\n"
      "MOV     R1, R3\n"
      "MOV     R0, R3\n"
      "STR     R3, [SP]\n"
      "STR     R3, [SP, #4]\n"
"loc_FF0B2738:\n"
      "BL      sub_FF0AD520\n"
"loc_FF0B273C:\n"
      "LDR     R0, [SP, #0x28]\n"
      "BL      sub_FF0B34B0\n"
      "B       loc_FF0B20D4\n"
	);
}

//** sub_FF0AE530_my  @ 0xFF0AE530

void __attribute__((naked,noinline)) sub_FF0AE530_my() {
asm volatile (
      "STMFD   SP!, {R4-R8,LR}\n"
      "LDR     R7, =0x42E8\n"
      "MOV     R4, R0\n"
      "LDR     R0, [R7, #0x1C]\n"
      "MOV     R1, #0x3E\n"
      "BL      sub_0047ACA0\n"
      "MOV     R2, #0\n"
      "LDRSH   R0, [R4, #4]\n"
      "MOV     R1, R2\n"
      "BL      sub_FF0AD028\n"
      "MOV     R6, R0\n"
      "LDRSH   R0, [R4, #6]\n"
      "BL      sub_FF0AD1CC\n"
      "LDRSH   R0, [R4, #8]\n"
      "BL      sub_FF0AD224\n"
      "LDRSH   R0, [R4, #0xA]\n"
      "BL      sub_FF0AD27C\n"
      "LDRSH   R0, [R4, #0xC]\n"
      "MOV     R1, #0\n"
      "BL      sub_FF0AD2D4\n"
      "MOV     R5, R0\n"
      "LDR     R0, [R4]\n"
      "LDR     R8, =0x567B8\n"
      "CMP     R0, #0xB\n"
      "MOVEQ   R6, #0\n"
      "MOVEQ   R5, R6\n"
      "BEQ     loc_FF0AE5C4\n"
      "CMP     R6, #1\n"
      "BNE     loc_FF0AE5C4\n"
      "LDRSH   R0, [R4, #4]\n"
      "LDR     R1, =0xFF0ACF88\n"
      "MOV     R2, #2\n"
      "BL      sub_FF173ADC\n"
      "STRH    R0, [R4, #4]\n"
      "MOV     R0, #0\n"
      "STR     R0, [R7, #0x28]\n"
      "B       loc_FF0AE5CC\n"
"loc_FF0AE5C4:\n"
      "LDRH    R0, [R8]\n"
      "STRH    R0, [R4, #4]\n"
"loc_FF0AE5CC:\n"
      "CMP     R5, #1\n"
      "LDRNEH  R0, [R8, #8]\n"
      "BNE     loc_FF0AE5E8\n"
      "LDRSH   R0, [R4, #0xC]\n"
      "LDR     R1, =0xFF0AD00C\n"
      "MOV     R2, #0x20\n"
      "BL      sub_FF0B3500\n"
"loc_FF0AE5E8:\n"
      "STRH    R0, [R4, #0xC]\n"
      "LDRSH   R0, [R4, #6]\n"
//      "BL      sub_FF09D804\n"  //original
      "BL      sub_FF09D804_my\n" //patched
      "B       sub_FF0AE5F4 \n" // continue in firmware
	);
}

//** sub_FF09D804_my  @ 0xFF09D804

void __attribute__((naked,noinline)) sub_FF09D804_my(  ) {
asm volatile (
      "STMFD   SP!, {R4-R6,LR}\n"
      "LDR     R5, =0x3F58\n"
      "MOV     R4, R0\n"
      "LDR     R0, [R5, #4]\n"
      "CMP     R0, #1\n"
      "LDRNE   R1, =0x14D\n"
      "LDRNE   R0, =0xFF09D63C\n"
      "BLNE    _DebugAssert\n"
      "CMN     R4, #0xC00\n"
      "LDREQSH R4, [R5, #2]\n"
      "CMN     R4, #0xC00\n"
      "LDREQ   R1, =0x153\n"
      "LDREQ   R0, =0xFF09D63C\n"
      "STRH    R4, [R5, #2]\n"
      "BLEQ    _DebugAssert\n"
      "MOV     R0, R4\n"
//      "BL      _apex2us \n" //original apex2us function
      "BL      apex2us \n"    //patch
      "MOV     R4, R0\n"
      "BL      sub_FF0F01FC\n"
      "MOV     R0, R4\n"
      "BL      sub_FF0FDEEC\n"
      "TST     R0, #1\n"
      "LDMEQFD SP!, {R4-R6,PC}\n"
      "LDMFD   SP!, {R4-R6,LR}\n"
      "MOV     R1, #0x158\n"
      "LDR     R0, =0xFF09D63C\n"
      "B       _DebugAssert\n"
	);
}
