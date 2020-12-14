#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"

static long *nrflag = (long*)(0x88a4+0x00);  // Found @ ff9e4e14 & ff9e4e5c
#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

#define PAUSE_FOR_FILE_COUNTER 250           // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated
#include "../../../generic/capt_seq.c"

//** capt_seq_task  @ 0xFF8712DC 

void __attribute__((naked,noinline)) capt_seq_task(  ) { 
asm volatile (
      "STMFD   SP!, {R3-R9,LR}\n"
      "LDR     R4, =0x36F4C\n"
      "LDR     R7, =0x2B68\n"
      "MOV     R6, #0\n"
"loc_FF8712EC:\n"
      "LDR     R0, [R7, #4]\n"
      "MOV     R2, #0\n"
      "MOV     R1, SP\n"
      "BL      sub_003F7218\n"
      "TST     R0, #1\n"
      "BEQ     loc_FF871318\n"
      "LDR     R1, =0x493\n"
      "LDR     R0, =0xFF870E48\n" // "SsShootTask.c"
      "BL      _DebugAssert \n"
      "BL      _ExitTask \n"
      "LDMFD   SP!, {R3-R9,PC}\n"
"loc_FF871318:\n"
      "LDR     R0, [SP]\n"
      "LDR     R1, [R0]\n"
      "CMP     R1, #0x20\n"
      "ADDCC   PC, PC, R1, LSL #2\n"
      "B       loc_FF871574\n"
      "B       loc_FF8713AC\n"
      "B       loc_FF8713C4\n"
      "B       loc_FF871428\n"
      "B       loc_FF87143C\n"
      "B       loc_FF871434\n"
      "B       loc_FF871448\n"
      "B       loc_FF871450\n"
      "B       loc_FF871458\n"
      "B       loc_FF871474\n"
      "B       loc_FF8714A0\n"
      "B       loc_FF871480\n"
      "B       loc_FF87148C\n"
      "B       loc_FF871494\n"
      "B       loc_FF8714A8\n"
      "B       loc_FF8714B0\n"
      "B       loc_FF8714B8\n"
      "B       loc_FF8714C0\n"
      "B       loc_FF8714C8\n"
      "B       loc_FF8714D4\n"
      "B       loc_FF8714DC\n"
      "B       loc_FF8714E4\n"
      "B       loc_FF8714EC\n"
      "B       loc_FF8714F4\n"
      "B       loc_FF871500\n"
      "B       loc_FF871508\n"
      "B       loc_FF871510\n"
      "B       loc_FF871518\n"
      "B       loc_FF871520\n"
      "B       loc_FF87152C\n"
      "B       loc_FF871534\n"
      "B       loc_FF871540\n"
      "B       loc_FF871580\n"
"loc_FF8713AC:\n"
      "BL		shooting_expo_iso_override\n"       // added
      "BL      sub_FF871AF4\n"
      "BL      shooting_expo_param_override\n"      // added
      "BL      sub_FF86F0E8\n"
//      "LDR     R0, [R4, #0x28]\n"
//      "CMP     R0, #0\n"
//      "BLNE    sub_FF965208\n"  // above 3 lines removed - redundant with added lines below
      "MOV     R0, #0\n"          // patch added
      "STR     R0, [R4,#0x28]\n"  //fixes overrides  behavior at short shutter press
      "B       loc_FF871580\n"
"loc_FF8713C4:\n"
      "LDR     R5, [R0, #0x10]\n"
      "LDR     R0, [R4, #0x28]\n"
      "CMP     R0, #0\n"
      "BNE     loc_FF871400\n"
      "BL      sub_FF872A04\n"
      "MOV     R1, R5\n"
      "BL      sub_FF872A5C\n"
      "LDR     R0, =0x10F\n"
      "MOV     R2, #4\n"
      "ADD     R1, R5, #0x24\n"
      "BL      _SetPropertyCase \n"
      "MOV     R2, #4\n"
      "ADD     R1, R5, #0x28\n"
      "MOV     R0, #0x2C\n"
      "BL      _SetPropertyCase \n"
"loc_FF871400:\n"
      "MOV     R0, R5\n"
//      "BL      sub_FF96516C\n"  //original
      "BL      sub_FF96516C_my\n" //patch
      "BL      capt_seq_hook_raw_here \n" // patch
      "MOV     R8, R0\n"
      "MOV     R2, R5\n"
      "MOV     R1, #1\n"
      "BL      sub_FF86F598\n"
      "TST     R8, #1\n"
      "MOVEQ   R0, R5\n"
      "BLEQ    sub_FF964AE8\n"
      "B       loc_FF871580\n"
"loc_FF871428:\n"
      "MOV     R0, #1\n"
      "BL      sub_FF871DC4\n"
      "B       loc_FF871580\n"
"loc_FF871434:\n"
      "BL      sub_FF871748\n"
      "B       loc_FF871440\n"
"loc_FF87143C:\n"
      "BL      sub_FF871AD4\n"
"loc_FF871440:\n"
      "STR     R6, [R4, #0x28]\n"
      "B       loc_FF871580\n"
"loc_FF871448:\n"
      "BL      sub_FF871ADC\n"
      "B       loc_FF871580\n"
"loc_FF871450:\n"
      "BL      sub_FF871CAC\n"
      "B       loc_FF871478\n"
"loc_FF871458:\n"
      "LDR     R5, [R0, #0x10]\n"
      "MOV     R0, R5\n"
      "BL      sub_FF9652A0\n"
      "MOV     R2, R5\n"
      "MOV     R1, #9\n"
      "BL      sub_FF86F598\n"
      "B       loc_FF871580\n"
"loc_FF871474:\n"
      "BL      sub_FF871D2C\n"
"loc_FF871478:\n"
      "BL      sub_FF86F0E8\n"
      "B       loc_FF871580\n"
"loc_FF871480:\n"
      "LDR     R0, [R4, #0x58]\n"
      "BL      sub_FF8721B4\n"
      "B       loc_FF871580\n"
"loc_FF87148C:\n"
      "BL      sub_FF872574\n"
      "B       loc_FF871580\n"
"loc_FF871494:\n"
      "MOV     R0, #0\n"
      "BL      sub_FF8725D8\n"
      "B       loc_FF871580\n"
"loc_FF8714A0:\n"
      "BL      sub_FF871AD4\n"
      "B       loc_FF871580\n"
"loc_FF8714A8:\n"
      "BL      sub_FF963E94\n"
      "B       loc_FF871580\n"
"loc_FF8714B0:\n"
      "BL      sub_FF9640F4\n"
      "B       loc_FF871580\n"
"loc_FF8714B8:\n"
      "BL      sub_FF9641AC\n"
      "B       loc_FF871580\n"
"loc_FF8714C0:\n"
      "BL      sub_FF964280\n"
      "B       loc_FF871580\n"
"loc_FF8714C8:\n"
      "MOV     R0, #0\n"
      "BL      sub_FF9644E0\n"
      "B       loc_FF871580\n"
"loc_FF8714D4:\n"
      "BL      sub_FF964650\n"
      "B       loc_FF871580\n"
"loc_FF8714DC:\n"
      "BL      sub_FF9646E4\n"
      "B       loc_FF871580\n"
"loc_FF8714E4:\n"
      "BL      sub_FF9647A0\n"
      "B       loc_FF871580\n"
"loc_FF8714EC:\n"
      "BL      sub_FF871F38\n"
      "B       loc_FF871580\n"
"loc_FF8714F4:\n"
      "BL      sub_FF871FBC\n"
      "BL      sub_FF8322AC\n"
      "B       loc_FF871580\n"
"loc_FF871500:\n"
      "BL      sub_FF964350\n"
      "B       loc_FF871580\n"
"loc_FF871508:\n"
      "BL      sub_FF964390\n"
      "B       loc_FF871580\n"
"loc_FF871510:\n"
      "BL      sub_FF873EE0\n"
      "B       loc_FF871580\n"
"loc_FF871518:\n"
      "BL      sub_FF873F54\n"
      "B       loc_FF871580\n"
"loc_FF871520:\n"
      "LDR     R0, [R0, #0xC]\n"
      "BL      sub_FF9648C8\n"
      "B       loc_FF871580\n"
"loc_FF87152C:\n"
      "BL      sub_FF964938\n"
      "B       loc_FF871580\n"
"loc_FF871534:\n"
      "BL      sub_FF873FBC\n"
      "BL      sub_FF873F74\n"
      "B       loc_FF871580\n"
"loc_FF871540:\n"
      "MOV     R0, #1\n"
      "BL      sub_FF9659A0\n"
      "MOV     R0, #1\n"
      "BL      sub_FF965AC8\n"
      "LDRH    R0, [R4, #0x9C]\n"
      "CMP     R0, #4\n"
      "LDRNEH  R0, [R4]\n"
      "SUBNE   R1, R0, #0x8200\n"
      "SUBNES  R1, R1, #0x2E\n"
      "BNE     loc_FF871580\n"
      "BL      sub_FF873F54\n"
      "BL      sub_FF874418\n"
      "B       loc_FF871580\n"
"loc_FF871574:\n"
      "LDR     R1, =0x5F4\n"
      "LDR     R0, =0xFF870E48\n" // "SsShootTask.c"
      "BL      _DebugAssert \n"
"loc_FF871580:\n"
      "LDR     R0, [SP]\n"
      "LDR     R1, [R0, #4]\n"
      "LDR     R0, [R7]\n"
      "BL      sub_003FAC6C\n"
      "LDR     R5, [SP]\n"
      "LDR     R0, [R5, #8]\n"
      "CMP     R0, #0\n"
      "LDREQ   R1, =0x117\n"
      "LDREQ   R0, =0xFF870E48\n" // "SsShootTask.c"
      "BLEQ    _DebugAssert \n"
      "STR     R6, [R5, #8]\n"
      "B       loc_FF8712EC\n"
	);
}


//** sub_FF96516C_my  @ 0xFF96516C

void __attribute__((naked,noinline)) sub_FF96516C_my(  ) {
asm volatile (
      "STMFD   SP!, {R4-R6,LR}\n"
      "LDR     R5, =0x36F4C\n"
      "MOV     R6, R0\n"
      "LDR     R0, [R5, #0x28]\n"
      "MOV     R4, #0\n"
      "CMP     R0, #0\n"
      "BNE     loc_FF96519C\n"
      "MOV     R0, #0xC\n"
      "BL      sub_FF875AB8\n"
      "TST     R0, #1\n"
      "MOVNE   R0, #1\n"
      "LDMNEFD SP!, {R4-R6,PC}\n"
"loc_FF96519C:\n"
      "BL      sub_FF871AE4\n"
      "LDR     R0, [R5, #0x28]\n"
      "CMP     R0, #0\n"
      "BNE     loc_FF9651EC\n"
      "MOV     R0, R6\n"
      "BL      sub_FF964A28\n"
      "TST     R0, #1\n"
      "LDMNEFD SP!, {R4-R6,PC}\n"
      "MOV     R0, R6\n"
      "BL      sub_FF964DBC\n"
      "BL      sub_FF965780\n"
//begin patch
      "BL      wait_until_remote_button_is_released\n"  
      "BL      capt_seq_hook_set_nr\n"      
//end patch
      "MOV     R0, #2\n"
      "BL      sub_FF877218\n"
      "LDR     R0, [R5, #0x8C]\n"
      "TST     R0, #0x10\n"
      "BNE     loc_FF9651FC\n"
      "MOV     R0, R6\n"
      "BL      sub_FFA72FC4\n"
      "MOV     R4, R0\n"
      "B       loc_FF965200\n"
"loc_FF9651EC:\n"
      "LDR     R0, =0x6884\n"
      "LDR     R0, [R0]\n"
      "CMP     R0, #0\n"
      "BEQ     loc_FF965200\n"
"loc_FF9651FC:\n"
      "MOV     R4, #0x1D\n"
"loc_FF965200:\n"
      "MOV     R0, R4\n"
      "LDMFD   SP!, {R4-R6,PC}\n"
	);
}


//** exp_drv_task  @ 0xFF8B0198 

void __attribute__((naked,noinline)) exp_drv_task(  ) { 
asm volatile (
      "STMFD   SP!, {R4-R9,LR}\n"
      "SUB     SP, SP, #0x2C\n"
      "LDR     R6, =0x3DE4\n"
      "LDR     R7, =0xBB8\n"
      "LDR     R4, =0x53EFC\n"
      "MOV     R0, #0\n"
      "ADD     R5, SP, #0x1C\n"
      "STR     R0, [SP, #0xC]\n"
"loc_FF8B01B8:\n"
      "LDR     R0, [R6, #0x20]\n"
      "MOV     R2, #0\n"
      "ADD     R1, SP, #0x28\n"
      "BL      sub_003F7218\n"
      "LDR     R0, [SP, #0xC]\n"
      "CMP     R0, #1\n"
      "BNE     loc_FF8B0204\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R0, [R0]\n"
      "CMP     R0, #0x14\n"
      "CMPNE   R0, #0x15\n"
      "CMPNE   R0, #0x16\n"
      "CMPNE   R0, #0x17\n"
      "BEQ     loc_FF8B0364\n"
      "CMP     R0, #0x2A\n"
      "BEQ     loc_FF8B02EC\n"
      "ADD     R1, SP, #0xC\n"
      "MOV     R0, #0\n"
      "BL      sub_FF8B0148\n"
"loc_FF8B0204:\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0]\n"
      "CMP     R1, #0x30\n"
      "BNE     loc_FF8B0230\n"
      "BL      sub_FF8B1574\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R1, #1\n"
      "BL      sub_003FAC6C\n"
      "BL      _ExitTask \n"
      "ADD     SP, SP, #0x2C\n"
      "LDMFD   SP!, {R4-R9,PC}\n"
"loc_FF8B0230:\n"
      "CMP     R1, #0x2F\n"
      "BNE     loc_FF8B024C\n"
      "LDR     R2, [R0, #0x8C]!\n"
      "LDR     R1, [R0, #4]\n"
      "MOV     R0, R1\n"
      "BLX     R2\n"
      "B       loc_FF8B0820\n"
"loc_FF8B024C:\n"
      "CMP     R1, #0x28\n"
      "BNE     loc_FF8B029C\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R1, #0x80\n"
      "BL      sub_003FACA0\n"
      "LDR     R0, =0xFF8ABAB4\n"
      "MOV     R1, #0x80\n"
      "BL      sub_FF956018\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R2, R7\n"
      "MOV     R1, #0x80\n"
      "BL      sub_003FABAC\n"
      "TST     R0, #1\n"
      "LDRNE   R1, =0x1599\n"
      "BNE     loc_FF8B0358\n"
"loc_FF8B0288:\n"
      "LDR     R1, [SP, #0x28]\n"
      "LDR     R0, [R1, #0x90]\n"
      "LDR     R1, [R1, #0x8C]\n"
      "BLX     R1\n"
      "B       loc_FF8B0820\n"
"loc_FF8B029C:\n"
      "CMP     R1, #0x29\n"
      "BNE     loc_FF8B02E4\n"
      "ADD     R1, SP, #0xC\n"
      "BL      sub_FF8B0148\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R1, #0x100\n"
      "BL      sub_003FACA0\n"
      "LDR     R0, =0xFF8ABAC4\n"
      "MOV     R1, #0x100\n"
      "BL      sub_FF9561B8\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R2, R7\n"
      "MOV     R1, #0x100\n"
      "BL      sub_003FABAC\n"
      "TST     R0, #1\n"
      "BEQ     loc_FF8B0288\n"
      "LDR     R1, =0x15A3\n"
      "B       loc_FF8B0358\n"
"loc_FF8B02E4:\n"
      "CMP     R1, #0x2A\n"
      "BNE     loc_FF8B02FC\n"
"loc_FF8B02EC:\n"
      "LDR     R0, [SP, #0x28]\n"
      "ADD     R1, SP, #0xC\n"
      "BL      sub_FF8B0148\n"
      "B       loc_FF8B0288\n"
"loc_FF8B02FC:\n"
      "CMP     R1, #0x2D\n"
      "BNE     loc_FF8B0314\n"
      "BL      sub_FF89CD70\n"
      "BL      sub_FF89DA58\n"
      "BL      sub_FF89D5C0\n"
      "B       loc_FF8B0288\n"
"loc_FF8B0314:\n"
      "CMP     R1, #0x2E\n"
      "BNE     loc_FF8B0364\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R1, #4\n"
      "BL      sub_003FACA0\n"
      "LDR     R1, =0xFF8ABAE4\n"
      "LDR     R0, =0xFFFFF400\n"
      "MOV     R2, #4\n"
      "BL      sub_FF89C7C0\n"
      "BL      sub_FF89CA50\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R2, R7\n"
      "MOV     R1, #4\n"
      "BL      sub_003FAAC8\n"
      "TST     R0, #1\n"
      "BEQ     loc_FF8B0288\n"
      "LDR     R1, =0x15CB\n"
"loc_FF8B0358:\n"
      "LDR     R0, =0xFF8AC1D8\n"
      "BL      _DebugAssert \n"
      "B       loc_FF8B0288\n"
"loc_FF8B0364:\n"
      "LDR     R0, [SP, #0x28]\n"
      "MOV     R8, #1\n"
      "LDR     R1, [R0]\n"
      "CMP     R1, #0x12\n"
      "CMPNE   R1, #0x13\n"
      "BNE     loc_FF8B03CC\n"
      "LDR     R1, [R0, #0x7C]\n"
      "ADD     R1, R1, R1, LSL #1\n"
      "ADD     R1, R0, R1, LSL #2\n"
      "SUB     R1, R1, #8\n"
      "LDMIA   R1, {R2,R3,R9}\n"
      "STMIA   R5, {R2,R3,R9}\n"
      "BL      sub_FF8AE6EC\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R3, [R0, #0x8C]\n"
      "LDR     R2, [R0, #0x90]\n"
      "ADD     R0, R0, #4\n"
      "BLX     R3\n"
      "LDR     R0, [SP, #0x28]\n"
      "BL      sub_FF8B1978\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R2, [R0, #0x98]\n"
      "LDR     R3, [R0, #0x94]\n"
      "B       loc_FF8B06E4\n"
"loc_FF8B03CC:\n"
      "CMP     R1, #0x14\n"
      "CMPNE   R1, #0x15\n"
      "CMPNE   R1, #0x16\n"
      "CMPNE   R1, #0x17\n"
      "BNE     loc_FF8B0484\n"
      "ADD     R3, SP, #0xC\n"
      "MOV     R2, SP\n"
      "ADD     R1, SP, #0x1C\n"
      "BL      sub_FF8AE94C\n"
      "CMP     R0, #1\n"
      "MOV     R9, R0\n"
      "CMPNE   R9, #5\n"
      "BNE     loc_FF8B0420\n"
      "LDR     R0, [SP, #0x28]\n"
      "MOV     R2, R9\n"
      "LDR     R1, [R0, #0x7C]!\n"
      "LDR     R12, [R0, #0x10]!\n"
      "LDR     R3, [R0, #4]\n"
      "MOV     R0, SP\n"
      "BLX     R12\n"
      "B       loc_FF8B0458\n"
"loc_FF8B0420:\n"
      "LDR     R0, [SP, #0x28]\n"
      "CMP     R9, #2\n"
      "LDR     R3, [R0, #0x90]\n"
      "CMPNE   R9, #6\n"
      "BNE     loc_FF8B046C\n"
      "LDR     R12, [R0, #0x8C]\n"
      "MOV     R2, R9\n"
      "MOV     R1, #1\n"
      "MOV     R0, SP\n"
      "BLX     R12\n"
      "LDR     R0, [SP, #0x28]\n"
      "MOV     R2, SP\n"
      "ADD     R1, SP, #0x1C\n"
      "BL      sub_FF8AFE34\n"
"loc_FF8B0458:\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R2, [SP, #0xC]\n"
      "MOV     R1, R9\n"
      "BL      sub_FF8B0084\n"
      "B       loc_FF8B06EC\n"
"loc_FF8B046C:\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R12, [R0, #0x8C]\n"
      "MOV     R2, R9\n"
      "ADD     R0, R0, #4\n"
      "BLX     R12\n"
      "B       loc_FF8B06EC\n"
"loc_FF8B0484:\n"
      "CMP     R1, #0x24\n"
      "CMPNE   R1, #0x25\n"
      "BNE     loc_FF8B04D0\n"
      "LDR     R1, [R0, #0x7C]\n"
      "ADD     R1, R1, R1, LSL #1\n"
      "ADD     R1, R0, R1, LSL #2\n"
      "SUB     R1, R1, #8\n"
      "LDMIA   R1, {R2,R3,R9}\n"
      "STMIA   R5, {R2,R3,R9}\n"
      "BL      sub_FF8AD6D8\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R3, [R0, #0x8C]\n"
      "LDR     R2, [R0, #0x90]\n"
      "ADD     R0, R0, #4\n"
      "BLX     R3\n"
      "LDR     R0, [SP, #0x28]\n"
      "BL      sub_FF8ADB18\n"
      "B       loc_FF8B06EC\n"
"loc_FF8B04D0:\n"
      "ADD     R1, R0, #4\n"
      "LDMIA   R1, {R2,R3,R9}\n"
      "STMIA   R5, {R2,R3,R9}\n"
      "LDR     R1, [R0]\n"
      "CMP     R1, #0x28\n"
      "ADDCC   PC, PC, R1, LSL #2\n"
      "B       loc_FF8B06D4\n"
      "B       loc_FF8B058C\n"
      "B       loc_FF8B058C\n"
      "B       loc_FF8B0594\n"
      "B       loc_FF8B059C\n"
      "B       loc_FF8B059C\n"
      "B       loc_FF8B059C\n"
      "B       loc_FF8B058C\n"
      "B       loc_FF8B0594\n"
      "B       loc_FF8B059C\n"
      "B       loc_FF8B059C\n"
      "B       loc_FF8B05B4\n"
      "B       loc_FF8B05B4\n"
      "B       loc_FF8B06C0\n"
      "B       loc_FF8B06C8\n"
      "B       loc_FF8B06C8\n"
      "B       loc_FF8B06C8\n"
      "B       loc_FF8B06C8\n"
      "B       loc_FF8B06D0\n"
      "B       loc_FF8B06D4\n"
      "B       loc_FF8B06D4\n"
      "B       loc_FF8B06D4\n"
      "B       loc_FF8B06D4\n"
      "B       loc_FF8B06D4\n"
      "B       loc_FF8B06D4\n"
      "B       loc_FF8B05A4\n"
      "B       loc_FF8B05AC\n"
      "B       loc_FF8B05AC\n"
      "B       loc_FF8B05AC\n"
      "B       loc_FF8B05C0\n"
      "B       loc_FF8B05C0\n"
      "B       loc_FF8B05C8\n"
      "B       loc_FF8B0600\n"
      "B       loc_FF8B0638\n"
      "B       loc_FF8B0670\n"
      "B       loc_FF8B06A8\n"
      "B       loc_FF8B06A8\n"
      "B       loc_FF8B06D4\n"
      "B       loc_FF8B06D4\n"
      "B       loc_FF8B06B0\n"
      "B       loc_FF8B06B8\n"
"loc_FF8B058C:\n"
      "BL      sub_FF8AC05C\n"
      "B       loc_FF8B06D4\n"
"loc_FF8B0594:\n"
      "BL      sub_FF8AC300\n"
      "B       loc_FF8B06D4\n"
"loc_FF8B059C:\n"
      "BL      sub_FF8AC528\n"
      "B       loc_FF8B06D4\n"
"loc_FF8B05A4:\n"
      "BL      sub_FF8AC84C\n"
      "B       loc_FF8B06D4\n"
"loc_FF8B05AC:\n"
      "BL      sub_FF8ACA64\n"
      "B       loc_FF8B06D4\n"
"loc_FF8B05B4:\n"
//      "BL      sub_FF8ACE10\n"  //original
      "BL      sub_FF8ACE10_my\n" //patch
      "MOV     R8, #0\n"
      "B       loc_FF8B06D4\n"
"loc_FF8B05C0:\n"
      "BL      sub_FF8ACF50\n"
      "B       loc_FF8B06D4\n"
"loc_FF8B05C8:\n"
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
      "BL      sub_FF8B1608\n"
      "B       loc_FF8B06D4\n"
"loc_FF8B0600:\n"
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
      "BL      sub_FF8B1778\n"
      "B       loc_FF8B06D4\n"
"loc_FF8B0638:\n"
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
      "BL      sub_FF8B182C\n"
      "B       loc_FF8B06D4\n"
"loc_FF8B0670:\n"
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
      "BL      sub_FF8B18D4\n"
      "B       loc_FF8B06D4\n"
"loc_FF8B06A8:\n"
      "BL      sub_FF8AD48C\n"
      "B       loc_FF8B06D4\n"
"loc_FF8B06B0:\n"
      "BL      sub_FF8ADC1C\n"
      "B       loc_FF8B06D4\n"
"loc_FF8B06B8:\n"
      "BL      sub_FF8ADF00\n"
      "B       loc_FF8B06D4\n"
"loc_FF8B06C0:\n"
      "BL      sub_FF8AE1C0\n"
      "B       loc_FF8B06D4\n"
"loc_FF8B06C8:\n"
      "BL      sub_FF8AE37C\n"
      "B       loc_FF8B06D4\n"
"loc_FF8B06D0:\n"
      "BL      sub_FF8AE4E4\n"
"loc_FF8B06D4:\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R2, [R0, #0x90]\n"
      "LDR     R3, [R0, #0x8C]\n"
"loc_FF8B06E4:\n"
      "ADD     R0, R0, #4\n"
      "BLX     R3\n"
"loc_FF8B06EC:\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R0, [R0]\n"
      "CMP     R0, #0x10\n"
      "BEQ     loc_FF8B0724\n"
      "BGT     loc_FF8B0714\n"
      "CMP     R0, #1\n"
      "CMPNE   R0, #4\n"
      "CMPNE   R0, #0xE\n"
      "BNE     loc_FF8B0758\n"
      "B       loc_FF8B0724\n"
"loc_FF8B0714:\n"
      "CMP     R0, #0x13\n"
      "CMPNE   R0, #0x17\n"
      "CMPNE   R0, #0x1A\n"
      "BNE     loc_FF8B0758\n"
"loc_FF8B0724:\n"
      "LDRSH   R0, [R4]\n"
      "CMN     R0, #0xC00\n"
      "LDRNESH R1, [R4, #8]\n"
      "CMNNE   R1, #0xC00\n"
      "STRNEH  R0, [SP, #0x1C]\n"
      "STRNEH  R1, [SP, #0x24]\n"
      "BNE     loc_FF8B0758\n"
      "ADD     R0, SP, #0x10\n"
      "BL      sub_FF8B1B88\n"
      "LDRH    R0, [SP, #0x10]\n"
      "STRH    R0, [SP, #0x1C]\n"
      "LDRH    R0, [SP, #0x18]\n"
      "STRH    R0, [SP, #0x24]\n"
"loc_FF8B0758:\n"
      "LDR     R0, [SP, #0x28]\n"
      "CMP     R8, #1\n"
      "BNE     loc_FF8B07A8\n"
      "LDR     R1, [R0, #0x7C]\n"
      "MOV     R2, #0xC\n"
      "ADD     R1, R1, R1, LSL #1\n"
      "ADD     R0, R0, R1, LSL #2\n"
      "SUB     R8, R0, #8\n"
      "LDR     R0, =0x53EFC\n"
      "ADD     R1, SP, #0x1C\n"
      "BL      sub_003FC17C\n"
      "LDR     R0, =0x53F08\n"
      "MOV     R2, #0xC\n"
      "ADD     R1, SP, #0x1C\n"
      "BL      sub_003FC17C\n"
      "LDR     R0, =0x53F14\n"
      "MOV     R2, #0xC\n"
      "MOV     R1, R8\n"
      "BL      sub_003FC17C\n"
      "B       loc_FF8B0820\n"
"loc_FF8B07A8:\n"
      "LDR     R0, [R0]\n"
      "MOV     R3, #1\n"
      "CMP     R0, #0xB\n"
      "BNE     loc_FF8B07EC\n"
      "MOV     R2, #0\n"
      "STRD    R2, [SP]\n"
      "MOV     R2, R3\n"
      "MOV     R1, R3\n"
      "MOV     R0, #0\n"
      "BL      sub_FF8ABE3C\n"
      "MOV     R3, #1\n"
      "MOV     R2, #0\n"
      "STRD    R2, [SP]\n"
      "MOV     R2, R3\n"
      "MOV     R1, R3\n"
      "MOV     R0, #0\n"
      "B       loc_FF8B081C\n"
"loc_FF8B07EC:\n"
      "MOV     R2, #1\n"
      "STRD    R2, [SP]\n"
      "MOV     R3, R2\n"
      "MOV     R1, R2\n"
      "MOV     R0, R2\n"
      "BL      sub_FF8ABE3C\n"
      "MOV     R3, #1\n"
      "MOV     R2, R3\n"
      "MOV     R1, R3\n"
      "MOV     R0, R3\n"
      "STR     R3, [SP]\n"
      "STR     R3, [SP, #4]\n"
"loc_FF8B081C:\n"
      "BL      sub_FF8ABFA8\n"
"loc_FF8B0820:\n"
      "LDR     R0, [SP, #0x28]\n"
      "BL      sub_FF8B1574\n"
      "B       loc_FF8B01B8\n"
	);
}


//** sub_FF8ACE10_my  @ 0xFF8ACE10 

void __attribute__((naked,noinline)) sub_FF8ACE10_my(  ) {
asm volatile (
      "STMFD   SP!, {R4-R8,LR}\n"
      "LDR     R7, =0x3DE4\n"
      "MOV     R4, R0\n"
      "LDR     R0, [R7, #0x1C]\n"
      "MOV     R1, #0x3E\n"
      "BL      sub_003FACA0\n"
      "MOV     R2, #0\n"
      "LDRSH   R0, [R4, #4]\n"
      "MOV     R1, R2\n"
      "BL      sub_FF8ABB44\n"
      "MOV     R6, R0\n"
      "LDRSH   R0, [R4, #6]\n"
      "BL      sub_FF8ABC94\n"
      "LDRSH   R0, [R4, #8]\n"
      "BL      sub_FF8ABCEC\n"
      "LDRSH   R0, [R4, #0xA]\n"
      "BL      sub_FF8ABD44\n"
      "LDRSH   R0, [R4, #0xC]\n"
      "MOV     R1, #0\n"
      "BL      sub_FF8ABD9C\n"
      "MOV     R5, R0\n"
      "LDR     R0, [R4]\n"
      "LDR     R8, =0x53F14\n"
      "CMP     R0, #0xB\n"
      "MOVEQ   R6, #0\n"
      "MOVEQ   R5, R6\n"
      "BEQ     loc_FF8ACEA4\n"
      "CMP     R6, #1\n"
      "BNE     loc_FF8ACEA4\n"
      "LDRSH   R0, [R4, #4]\n"
      "LDR     R1, =0xFF8ABAA4\n"
      "MOV     R2, #2\n"
      "BL      sub_FF95609C\n"
      "STRH    R0, [R4, #4]\n"
      "MOV     R0, #0\n"
      "STR     R0, [R7, #0x28]\n"
      "B       loc_FF8ACEAC\n"
"loc_FF8ACEA4:\n"
      "LDRH    R0, [R8]\n"
      "STRH    R0, [R4, #4]\n"
"loc_FF8ACEAC:\n"
      "CMP     R5, #1\n"
      "LDRNEH  R0, [R8, #8]\n"
      "BNE     loc_FF8ACEC8\n"
      "LDRSH   R0, [R4, #0xC]\n"
      "LDR     R1, =0xFF8ABB28\n"
      "MOV     R2, #0x20\n"
      "BL      sub_FF8B15C4\n"
"loc_FF8ACEC8:\n"
      "STRH    R0, [R4, #0xC]\n"
      "LDRSH   R0, [R4, #6]\n"
//      "BL      sub_FF89CABC\n"  //original
      "BL      sub_FF89CABC_my\n" //patch
      "B       sub_FF8ACED4 \n" // continue in firmware
	);
}


//** sub_FF89CABC_my  @ 0xFF89CABC 

void __attribute__((naked,noinline)) sub_FF89CABC_my(  ) { 
asm volatile (
      "STMFD   SP!, {R4-R6,LR}\n"
      "LDR     R5, =0x3A70\n"
      "MOV     R4, R0\n"
      "LDR     R0, [R5, #4]\n"
      "CMP     R0, #1\n"
      "LDRNE   R1, =0x14D\n"
      "LDRNE   R0, =0xFF89C8F4\n"
      "BLNE    _DebugAssert \n"
      "CMN     R4, #0xC00\n"
      "LDREQSH R4, [R5, #2]\n"
      "CMN     R4, #0xC00\n"
      "LDREQ   R1, =0x153\n"
      "LDREQ   R0, =0xFF89C8F4\n"
      "STRH    R4, [R5, #2]\n"
      "BLEQ    _DebugAssert \n"
      "MOV     R0, R4\n"
//      "BL      _apex2us\n"  //original apex2us function
      "BL      apex2us \n"  //patch
      "MOV     R4, R0\n"
      "BL      sub_FF8EABA4\n"
      "MOV     R0, R4\n"
      "BL      sub_FF8F33AC\n"
      "TST     R0, #1\n"
      "LDMEQFD SP!, {R4-R6,PC}\n"
      "LDMFD   SP!, {R4-R6,LR}\n"
      "MOV     R1, #0x158\n"
      "LDR     R0, =0xFF89C8F4\n"
      "B       _DebugAssert \n"
	);
}
