/*
 * boot.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;

// Forward declarations
extern volatile int jogdial_stopped;
void JogDial_task_my(void);

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_RotaryEncoder();
extern void task_MovieRecord();
extern void task_ExpDrv();
extern void task_FileWrite();

void taskHook(context_t **context)
{ 
	task_t *tcb=(task_t*)((char*)context-offsetof(task_t, context));

	// Replace firmware task addresses with ours
	if(tcb->entry == (void*)task_CaptSeq)			tcb->entry = (void*)capt_seq_task; 
	if(tcb->entry == (void*)task_InitFileModules)	tcb->entry = (void*)init_file_modules_task;
	if(tcb->entry == (void*)task_RotaryEncoder)		tcb->entry = (void*)JogDial_task_my;
	if(tcb->entry == (void*)task_MovieRecord)		tcb->entry = (void*)movie_record_task;
	if(tcb->entry == (void*)task_ExpDrv)			tcb->entry = (void*)exp_drv_task;
    if(tcb->entry == (void*)task_FileWrite)         tcb->entry = (void*)filewritetask;
}

/*----------------------------------------------------------------------
	spytask
-----------------------------------------------------------------------*/
void spytask(long ua, long ub, long uc, long ud, long ue, long uf)
{
    core_spytask();
}

/*----------------------------------------------------------------------
	CreateTask_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask()
{
	_CreateTask("SpyTask", 0x19, 0x2000, spytask, 0);
}

///*----------------------------------------------------------------------
// Pointer to stack location where jogdial task records previous and current
// jogdial positions
short *jog_position;

/*----------------------------------------------------------------------
	boot()

	Main entry point for the CHDK code
-----------------------------------------------------------------------*/

/*************************************************************/
//** boot @ 0xFF81000C - 0xFF810160, length=86
void __attribute__((naked,noinline)) boot() {
asm volatile (
"    LDR     R1, =0xC0410000 \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R1] \n"
"    MOV     R1, #0x78 \n"
"    MCR     p15, 0, R1, c1, c0 \n"
"    MOV     R1, #0 \n"
"    MCR     p15, 0, R1, c7, c10, 4 \n"
"    MCR     p15, 0, R1, c7, c5 \n"
"    MCR     p15, 0, R1, c7, c6 \n"
"    MOV     R0, #0x3D \n"
"    MCR     p15, 0, R0, c6, c0 \n"
"    MOV     R0, #0xC000002F \n"
"    MCR     p15, 0, R0, c6, c1 \n"
"    MOV     R0, #0x35 \n"
"    MCR     p15, 0, R0, c6, c2 \n"
"    MOV     R0, #0x40000035 \n"
"    MCR     p15, 0, R0, c6, c3 \n"
"    MOV     R0, #0x80000017 \n"
"    MCR     p15, 0, R0, c6, c4 \n"
"    LDR     R0, =0xFF80002D \n"
"    MCR     p15, 0, R0, c6, c5 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c2, c0 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c2, c0, 1 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c3, c0 \n"
"    LDR     R0, =0x3333330 \n"
"    MCR     p15, 0, R0, c5, c0, 2 \n"
"    LDR     R0, =0x3333330 \n"
"    MCR     p15, 0, R0, c5, c0, 3 \n"
"    MRC     p15, 0, R0, c1, c0 \n"
"    ORR     R0, R0, #0x1000 \n"
"    ORR     R0, R0, #4 \n"
"    ORR     R0, R0, #1 \n"
"    MCR     p15, 0, R0, c1, c0 \n"
"    MOV     R1, #0x80000006 \n"
"    MCR     p15, 0, R1, c9, c1 \n"
"    MOV     R1, #6 \n"
"    MCR     p15, 0, R1, c9, c1, 1 \n"
"    MRC     p15, 0, R1, c1, c0 \n"
"    ORR     R1, R1, #0x50000 \n"
"    MCR     p15, 0, R1, c1, c0 \n"
"    LDR     R2, =0xC0200000 \n"
"    MOV     R1, #1 \n"
"    STR     R1, [R2, #0x10C] \n"
"    MOV     R1, #0xFF \n"
"    STR     R1, [R2, #0xC] \n"
"    STR     R1, [R2, #0x1C] \n"
"    STR     R1, [R2, #0x2C] \n"
"    STR     R1, [R2, #0x3C] \n"
"    STR     R1, [R2, #0x4C] \n"
"    STR     R1, [R2, #0x5C] \n"
"    STR     R1, [R2, #0x6C] \n"
"    STR     R1, [R2, #0x7C] \n"
"    STR     R1, [R2, #0x8C] \n"
"    STR     R1, [R2, #0x9C] \n"
"    STR     R1, [R2, #0xAC] \n"
"    STR     R1, [R2, #0xBC] \n"
"    STR     R1, [R2, #0xCC] \n"
"    STR     R1, [R2, #0xDC] \n"
"    STR     R1, [R2, #0xEC] \n"
"    STR     R1, [R2, #0xFC] \n"
"    LDR     R1, =0xC0400008 \n"
"    LDR     R2, =0x430005 \n"
"    STR     R2, [R1] \n"
"    MOV     R1, #1 \n"
"    LDR     R2, =0xC0243100 \n"
"    STR     R2, [R1] \n"
"    LDR     R2, =0xC0242010 \n"
"    LDR     R1, [R2] \n"
"    ORR     R1, R1, #1 \n"
"    STR     R1, [R2] \n"
"    LDR     R0, =0xFFCB1DB0 \n"
"    LDR     R1, =0x1900 \n"
"    LDR     R3, =0x10798 \n"

"loc_FF81013C:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF81013C \n"
"    LDR     R1, =0x16E820 \n"
"    MOV     R2, #0 \n"

"loc_FF810154:\n"
"    CMP     R3, R1 \n"
"    STRCC   R2, [R3], #4 \n"
"    BCC     loc_FF810154 \n"
"    B       sub_FF810354_my \n"  // --> Patched. Old value = 0xFF810354.
);
}

/*************************************************************/
//** sub_FF810354_my @ 0xFF810354 - 0xFF8103BC, length=27
void __attribute__((naked,noinline)) sub_FF810354_my() {

	//http://chdk.setepontos.com/index.php/topic,4194.0.html
	*(int*)0x1938=(int)taskHook;
	*(int*)0x193C=(int)taskHook;
    
	// replacement of sub_FF864BE0 for correct power-on.
	*(int*)(0x25E0) = (*(int*)0xC0220108)&1 ? 0x100000 : 0x200000; 

asm volatile (
"    LDR     R0, =0xFF8103CC \n"
"    MOV     R1, #0 \n"
"    LDR     R3, =0xFF810404 \n"

"loc_FF810360:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF810360 \n"
"    LDR     R0, =0xFF810404 \n"
"    MOV     R1, #0x4B0 \n"
"    LDR     R3, =0xFF810618 \n"

"loc_FF81037C:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF81037C \n"
"    MOV     R0, #0xD2 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    MOV     R0, #0xD3 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    LDR     R0, =0x6C4 \n"
"    LDR     R2, =0xEEEEEEEE \n"
"    MOV     R3, #0x1000 \n"

"loc_FF8103B0:\n"
"    CMP     R0, R3 \n"
"    STRCC   R2, [R0], #4 \n"
"    BCC     loc_FF8103B0 \n"
"    BL      sub_FF811198_my \n"  // --> Patched. Old value = 0xFF811198.
);
}

/*************************************************************/
//** sub_FF811198_my @ 0xFF811198 - 0xFF8111EC, length=22
void __attribute__((naked,noinline)) sub_FF811198_my() {
asm volatile (
"    STR     LR, [SP, #-4]! \n"
"    SUB     SP, SP, #0x74 \n"
"    MOV     R0, SP \n"
"    MOV     R1, #0x74 \n"
"    BL      sub_FFBB34B0 \n"
"    MOV     R0, #0x53000 \n"
"    STR     R0, [SP, #4] \n"

#if defined(OPT_CHDK_IN_EXMEM) // use original heap offset if CHDK is loaded in high memory
"    LDR     R0, =0x16E820 \n"
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      // 
#endif

"    LDR     R1, =0x379C00 \n"
"    STR     R0, [SP, #8] \n"
"    RSB     R0, R0, #0x1F80 \n"
"    ADD     R0, R0, #0x370000 \n"
"    STR     R0, [SP, #0xC] \n"
"    LDR     R0, =0x371F80 \n"
"    STR     R1, [SP] \n"
"    STRD    R0, [SP, #0x10] \n"
"    MOV     R0, #0x22 \n"
"    STR     R0, [SP, #0x18] \n"
"    MOV     R0, #0x68 \n"
"    STR     R0, [SP, #0x1C] \n"
"    LDR     R0, =0x19B \n"
"    LDR     R1, =sub_FF815EE0_my \n"  // --> Patched. Old value = 0xFF815EE0.
"    LDR     PC, =0xFF8111F0 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF815EE0_my @ 0xFF815EE0 - 0xFF815F54, length=30
void __attribute__((naked,noinline)) sub_FF815EE0_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF810B20 \n"
"    BL      sub_FF81A33C \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF815FF4 \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF815B1C \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF815FFC \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF81600C \n"
"    BL      sub_FF815C04 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF816014 \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF81600C \n"
"    BL      sub_FF813CA4 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF816028 \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF819CC4 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF816034 \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF81167C \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF816040 \n"
"    BLLT    _err_init_task \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       taskcreate_Startup_my \n"  // --> Patched. Old value = 0xFF81FB54.
);
}

/*************************************************************/
//** taskcreate_Startup_my @ 0xFF81FB54 - 0xFF81FBC4, length=29
void __attribute__((naked,noinline)) taskcreate_Startup_my() {
asm volatile (
"    STMFD   SP!, {R3,LR} \n"
//"  BL      _sub_FF864BD8 \n"  // --> Nullsub call removed.
"    BL      sub_FF83C81C \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF81FB98 \n"
"    BL      sub_FF836164 \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF81FB98 \n"
"    BL      sub_FF864B94 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF81FB98 \n"
"    BL      sub_FF833DB8 \n"
"    LDR     R1, =0xC0220000 \n"
"    MOV     R0, #0x44 \n"
"    STR     R0, [R1, #0x1C] \n"
"    BL      sub_FF833FA8 \n"

"loc_FF81FB94:\n"
"    B       loc_FF81FB94 \n"

"loc_FF81FB98:\n"
//"  BL      _sub_FF864BE0 \n"  // See begin of sub_FF810354_my()
//"  BL      _sub_FF864BDC \n"  // --> Nullsub call removed.
"    BL      sub_FF83AA2C \n"
"    MOV     R0, #0x46 \n"
"    BL      _SleepTask \n"
"    LDR     R1, =0x3CE000 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF83AE74 \n"
"    BL      sub_FF83AC20 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =task_Startup_my \n"  // --> Patched. Old value = 0xFF81FAF0.
"    LDR     PC, =0xFF81FBC8 \n"  // Continue in firmware
);
}

/*************************************************************/
//** task_Startup_my @ 0xFF81FAF0 - 0xFF81FB20, length=13
void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF816594 \n"
"    BL      sub_FF835898 \n"
"    BL      sub_FF8339AC \n"
//"  BL      _sub_FF8656BC \n"  // --> Nullsub call removed.
"    BL      sub_FF83CA4C \n"
//"  BL      _sub_FF83C8F4 \n"  // start diskboot.bin
"    BL      sub_FF89C43C \n"
"    BL      sub_FF83247C \n"
"    BL      sub_FF83CA7C \n"
"    BL      sub_FF83A1D0 \n"
"    BL      sub_FF83CBFC \n"

"    BL      CreateTask_spytask\n"  // added

"    BL      taskcreatePhySw_my \n"  // --> Patched. Old value = 0xFF834620.
"    LDR     PC, =0xFF81FB24 \n"  // Continue in firmware
);
}

/*************************************************************/
//** taskcreatePhySw_my @ 0xFF834620 - 0xFF834640, length=9
void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    LDR     R4, =0x1C30 \n"
"    LDR     R0, [R4, #0x10] \n"
"    CMP     R0, #0 \n"
"    BNE     sub_FF834654 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =mykbd_task \n"  // --> Patched. Old value = 0xFF8345EC.
"    MOV     R2, #0x2000 \n"  // --> Patched. Old value = 0x800. stack size for new task_PhySw
"    LDR     PC, =0xFF834644 \n"  // Continue in firmware
);
}

/*************************************************************/
//** init_file_modules_task @ 0xFF89FC7C - 0xFF89FC98, length=8
void __attribute__((naked,noinline)) init_file_modules_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF895DBC \n"
"    LDR     R5, =0x5006 \n"
"    MOVS    R4, R0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, R5 \n"
"    BLNE    _PostLogicalEventToUI \n"
"    BL      sub_FF895DE8_my \n"  // --> Patched. Old value = 0xFF895DE8.
"    BL      core_spytask_can_start\n"  // CHDK: Set "it's-safe-to-start" flag for spytask
"    LDR     PC, =0xFF89FC9C \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF895DE8_my @ 0xFF895DE8 - 0xFF895DF0, length=3
void __attribute__((naked,noinline)) sub_FF895DE8_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    MOV     R0, #3 \n"
"    BL      sub_FF876518_my \n"  // --> Patched. Old value = 0xFF876518.
"    LDR     PC, =0xFF895DF4 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF876518_my @ 0xFF876518 - 0xFF87656C, length=22
void __attribute__((naked,noinline)) sub_FF876518_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    MOV     R8, R0 \n"
"    BL      sub_FF876498 \n"
"    LDR     R1, =0x3A848 \n"
"    MOV     R6, R0 \n"
"    ADD     R4, R1, R0, LSL#7 \n"
"    LDR     R0, [R4, #0x6C] \n"
"    CMP     R0, #4 \n"
"    LDREQ   R1, =0x83F \n"
"    LDREQ   R0, =0xFF875FD8 \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R1, R8 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF875D4C \n"
"    LDR     R0, [R4, #0x38] \n"
"    BL      sub_FF876BBC \n"
"    CMP     R0, #0 \n"
"    STREQ   R0, [R4, #0x6C] \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF875DDC \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF876140_my \n"  // --> Patched. Old value = 0xFF876140.
"    LDR     PC, =0xFF876570 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF876140_my @ 0xFF876140 - 0xFF876168, length=11
void __attribute__((naked,noinline)) sub_FF876140_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, =0x3A848 \n"
"    ADD     R4, R0, R5, LSL#7 \n"
"    LDR     R0, [R4, #0x6C] \n"
"    TST     R0, #2 \n"
"    MOVNE   R0, #1 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    LDR     R0, [R4, #0x38] \n"
"    MOV     R1, R5 \n"
"    BL      sub_FF875E60_my \n"  // --> Patched. Old value = 0xFF875E60.
"    LDR     PC, =0xFF87616C \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF875E60_my @ 0xFF875E60 - 0xFF875FD0, length=93
void __attribute__((naked,noinline)) sub_FF875E60_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R9, R0 \n"
"    LDR     R0, =0x3A848 \n"
"    MOV     R8, #0 \n"
"    ADD     R5, R0, R1, LSL#7 \n"
"    LDR     R0, [R5, #0x3C] \n"
"    MOV     R7, #0 \n"
"    CMP     R0, #7 \n"
"    MOV     R6, #0 \n"
"    ADDLS   PC, PC, R0, LSL#2 \n"
"    B       loc_FF875FB8 \n"
"    B       loc_FF875EC4 \n"
"    B       loc_FF875EAC \n"
"    B       loc_FF875EAC \n"
"    B       loc_FF875EAC \n"
"    B       loc_FF875EAC \n"
"    B       loc_FF875FB0 \n"
"    B       loc_FF875EAC \n"
"    B       loc_FF875EAC \n"

"loc_FF875EAC:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0x200 \n"
"    MOV     R0, #2 \n"
"    BL      sub_FF88FE28 \n"
"    MOVS    R4, R0 \n"
"    BNE     loc_FF875ECC \n"

"loc_FF875EC4:\n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R4-R10,PC} \n"

"loc_FF875ECC:\n"
"    LDR     R12, [R5, #0x50] \n"
"    MOV     R3, R4 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, R9 \n"
"    BLX     R12 \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF875EF8 \n"
"    MOV     R0, #2 \n"
"    BL      sub_FF88FF78 \n"
"    B       loc_FF875EC4 \n"

"loc_FF875EF8:\n"
"    LDR     R1, [R5, #0x64] \n"
"    MOV     R0, R9 \n"
"    BLX     R1 \n"

"    MOV     R1, R4\n"              //  pointer to MBR in R1
"    BL      mbr_read_dryos\n"      //  total sectors count in R0 before and after call

// Start of DataGhost's FAT32 autodetection code
// Policy: If there is a partition which has type W95 FAT32, use the first one of those for image storage
// According to the code below, we can use R1, R2, R3 and R12.
// LR wasn't really used anywhere but for storing a part of the partition signature. This is the only thing
// that won't work with an offset, but since we can load from LR+offset into LR, we can use this to do that :)
"    MOV     R12, R4\n"             // Copy the MBR start address so we have something to work with
"    MOV     LR, R4\n"              // Save old offset for MBR signature
"    MOV     R1, #1\n"              // Note the current partition number
"    B       dg_sd_fat32_enter\n"   // We actually need to check the first partition as well, no increments yet!
"dg_sd_fat32:\n"
"    CMP     R1, #4\n"              // Did we already see the 4th partition?
"    BEQ     dg_sd_fat32_end\n"     // Yes, break. We didn't find anything, so don't change anything.
"    ADD     R12, R12, #0x10\n"     // Second partition
"    ADD     R1, R1, #1\n"          // Second partition for the loop
"dg_sd_fat32_enter:\n"
"    LDRB    R2, [R12, #0x1BE]\n"   // Partition status
"    LDRB    R3, [R12, #0x1C2]\n"   // Partition type (FAT32 = 0xB)
"    CMP     R3, #0xB\n"            // Is this a FAT32 partition?
"    CMPNE   R3, #0xC\n"            // Not 0xB, is it 0xC (FAT32 LBA) then?
"    CMPNE   R3, #0x7\n"            // exFat?
"    BNE     dg_sd_fat32\n"         // No, it isn't. Loop again.
"    CMP     R2, #0x00\n"           // It is, check the validity of the partition type
"    CMPNE   R2, #0x80\n"
"    BNE     dg_sd_fat32\n"         // Invalid, go to next partition
                                    // This partition is valid, it's the first one, bingo!
"    MOV     R4, R12\n"             // Move the new MBR offset for the partition detection.

"dg_sd_fat32_end:\n"
// End of DataGhost's FAT32 autodetection code

"    LDRB    R1, [R4, #0x1C9] \n"
"    LDRB    R3, [R4, #0x1C8] \n"
"    LDRB    R12, [R4, #0x1CC] \n"
"    MOV     R1, R1, LSL#24 \n"
"    ORR     R1, R1, R3, LSL#16 \n"
"    LDRB    R3, [R4, #0x1C7] \n"
"    LDRB    R2, [R4, #0x1BE] \n"
//"  LDRB    LR, [R4, #0x1FF] \n"  // replaced below
"    ORR     R1, R1, R3, LSL#8 \n"
"    LDRB    R3, [R4, #0x1C6] \n"
"    CMP     R2, #0 \n"
"    CMPNE   R2, #0x80 \n"
"    ORR     R1, R1, R3 \n"
"    LDRB    R3, [R4, #0x1CD] \n"
"    MOV     R3, R3, LSL#24 \n"
"    ORR     R3, R3, R12, LSL#16 \n"
"    LDRB    R12, [R4, #0x1CB] \n"
"    ORR     R3, R3, R12, LSL#8 \n"
"    LDRB    R12, [R4, #0x1CA] \n"
"    ORR     R3, R3, R12 \n"
//"  LDRB    R12, [R4, #0x1FE] \n"  // replaced below
"    LDRB    R12, [LR,#0x1FE]\n"    // replace instructions above
"    LDRB    LR, [LR,#0x1FF]\n"     // replace instructions above
"    BNE     loc_FF875F84 \n"
"    CMP     R0, R1 \n"
"    BCC     loc_FF875F84 \n"
"    ADD     R2, R1, R3 \n"
"    CMP     R2, R0 \n"
"    CMPLS   R12, #0x55 \n"
"    CMPEQ   LR, #0xAA \n"
"    MOVEQ   R7, R1 \n"
"    MOVEQ   R6, R3 \n"
"    MOVEQ   R4, #1 \n"
"    BEQ     loc_FF875F88 \n"

"loc_FF875F84:\n"
"    MOV     R4, R8 \n"

"loc_FF875F88:\n"
"    MOV     R0, #2 \n"
"    BL      sub_FF88FF78 \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FF875FC4 \n"
"    LDR     R1, [R5, #0x64] \n"
"    MOV     R7, #0 \n"
"    MOV     R0, R9 \n"
"    BLX     R1 \n"
"    MOV     R6, R0 \n"
"    B       loc_FF875FC4 \n"

"loc_FF875FB0:\n"
"    MOV     R6, #0x40 \n"
"    B       loc_FF875FC4 \n"

"loc_FF875FB8:\n"
"    LDR     R1, =0x597 \n"
"    LDR     R0, =0xFF875FD8 \n"
"    BL      _DebugAssert \n"

"loc_FF875FC4:\n"
"    STR     R7, [R5, #0x44]! \n"
"    STMIB   R5, {R6,R8} \n"
"    MOV     R0, #1 \n"
"    LDMFD   SP!, {R4-R10,PC} \n"
);
}

/*************************************************************/
//** JogDial_task_my @ 0xFF8657EC - 0xFF865B14, length=203
void __attribute__((naked,noinline)) JogDial_task_my() {
asm volatile (
"    STMFD   SP!, {R4-R11,LR} \n"
"    SUB     SP, SP, #0x24 \n"
"    BL      sub_FF865B84 \n"
"    LDR     R1, =0x25E8 \n"
"    LDR     R6, =0xFFBB9764 \n"
"    MOV     R0, #0 \n"
"    ADD     R3, SP, #0x18 \n"

// Save pointer for kbd.c routine
"    LDR     R12, =jog_position \n"
"    STR     R3, [R12] \n"

"    ADD     R12, SP, #0x1C \n"
"    ADD     R10, SP, #8 \n"
"    MOV     R2, #0 \n"
"    ADD     R9, SP, #0x10 \n"

"loc_FF865818:\n"
"    ADD     R12, SP, #0x1C \n"
"    ADD     LR, R12, R0, LSL#1 \n"
"    MOV     R2, #0 \n"
"    ADD     R3, SP, #0x18 \n"
"    STRH    R2, [LR] \n"
"    ADD     LR, R3, R0, LSL#1 \n"
"    STRH    R2, [LR] \n"
"    STR     R2, [R9, R0, LSL#2] \n"
"    STR     R2, [R10, R0, LSL#2] \n"
"    ADD     R0, R0, #1 \n"
"    CMP     R0, #2 \n"
"    BLT     loc_FF865818 \n"

"loc_FF865848:\n"
"    LDR     R0, =0x25E8 \n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R0, #8] \n"
"    MOV     R1, SP \n"
"    BL      sub_FF83A460 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    LDRNE   R1, =0x262 \n"
"    LDRNE   R0, =0xFF865AA8 \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP] \n"
"    AND     R4, R0, #0xFF \n"
"    AND     R0, R0, #0xFF00 \n"
"    CMP     R0, #0x100 \n"
"    BEQ     loc_FF8658B8 \n"
"    CMP     R0, #0x200 \n"
"    BEQ     loc_FF8658F0 \n"
"    CMP     R0, #0x300 \n"
"    BEQ     loc_FF865AE8 \n"
"    CMP     R0, #0x400 \n"
"    BNE     loc_FF865848 \n"
"    CMP     R4, #0 \n"
"    LDRNE   R1, =0x2ED \n"
"    LDRNE   R0, =0xFF865AA8 \n"
"    BLNE    _DebugAssert \n"
"    RSB     R0, R4, R4, LSL#3 \n"
"    LDR     R0, [R6, R0, LSL#2] \n"

"loc_FF8658B0:\n"
"    BL      sub_FF865B68 \n"
"    B       loc_FF865848 \n"

"loc_FF8658B8:\n"
//------------------  added code ---------------------
"labelA:\n"
"    LDR     R0, =jogdial_stopped\n"
"    LDR     R0, [R0]\n"
"    CMP     R0, #1\n"
"    BNE     labelB\n"
"    MOV     R0, #40\n"
"    BL      _SleepTask\n"
"    B       labelA\n"
"labelB:\n"
//------------------  original code ------------------
"    LDR     R7, =0x25F8 \n"
"    LDR     R0, [R7, R4, LSL#2] \n"
"    BL      sub_FF83B3F8 /*_CancelTimer*/ \n"
"    LDR     R2, =0xFF865738 \n"
"    MOV     R1, R2 \n"
"    ORR     R3, R4, #0x200 \n"
"    MOV     R0, #0x28 \n"
"    BL      sub_FF83B314 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R10, R4, LSL#2] \n"
"    BEQ     loc_FF865848 \n"
"    MOV     R1, #0x274 \n"
"    B       loc_FF865A94 \n"

"loc_FF8658F0:\n"
"    RSB     R5, R4, R4, LSL#3 \n"
"    LDR     R0, [R6, R5, LSL#2] \n"
"    LDR     R1, =0xC0240104 \n"
"    LDR     R0, [R1, R0, LSL#8] \n"
"    MOV     R2, R0, ASR#16 \n"
"    ADD     R0, SP, #0x1C \n"
"    ADD     R0, R0, R4, LSL#1 \n"
"    STR     R0, [SP, #0x20] \n"
"    STRH    R2, [R0] \n"
"    ADD     R0, SP, #0x18 \n"
"    ADD     R11, R0, R4, LSL#1 \n"
"    LDRSH   R3, [R11] \n"
"    SUB     R0, R2, R3 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF865970 \n"
"    LDR     R0, [R9, R4, LSL#2] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF865A50 \n"
"    LDR     R7, =0x25F8 \n"
"    LDR     R0, [R7, R4, LSL#2] \n"
"    BL      sub_FF83B3F8 /*_CancelTimer*/ \n"
"    LDR     R2, =0xFF865744 \n"
"    MOV     R1, R2 \n"
"    ORR     R3, R4, #0x300 \n"
"    MOV     R0, #0x1F4 \n"
"    BL      sub_FF83B314 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R7, R4, LSL#2] \n"
"    BEQ     loc_FF865A50 \n"
"    LDR     R1, =0x28D \n"
"    B       loc_FF865A48 \n"

"loc_FF865970:\n"
"    MOV     R1, R0 \n"
"    RSBLT   R0, R0, #0 \n"
"    MOVLE   R7, #0 \n"
"    MOVGT   R7, #1 \n"
"    CMP     R0, #0xFF \n"
"    BLS     loc_FF8659B0 \n"
"    CMP     R1, #0 \n"
"    RSBLE   R0, R3, #0xFF \n"
"    ADDLE   R0, R0, #0x7F00 \n"
"    ADDLE   R0, R0, R2 \n"
"    RSBGT   R0, R2, #0xFF \n"
"    ADDGT   R0, R0, #0x7F00 \n"
"    ADDGT   R0, R0, R3 \n"
"    ADD     R0, R0, #0x8000 \n"
"    ADD     R0, R0, #1 \n"
"    EOR     R7, R7, #1 \n"

"loc_FF8659B0:\n"
"    STR     R0, [SP, #4] \n"
"    LDR     R0, [R9, R4, LSL#2] \n"
"    CMP     R0, #0 \n"
"    ADDEQ   R0, R6, R5, LSL#2 \n"
"    LDREQ   R0, [R0, #8] \n"
"    BEQ     loc_FF8659E8 \n"
"    ADD     R8, R6, R5, LSL#2 \n"
"    ADD     R1, R8, R7, LSL#2 \n"
"    LDR     R1, [R1, #0x10] \n"
"    CMP     R1, R0 \n"
"    BEQ     loc_FF8659EC \n"
"    LDR     R0, [R8, #0xC] \n"
"    BL      sub_FF89BE30 \n"
"    LDR     R0, [R8, #8] \n"

"loc_FF8659E8:\n"
"    BL      sub_FF89BE30 \n"

"loc_FF8659EC:\n"
"    ADD     R0, R6, R5, LSL#2 \n"
"    ADD     R7, R0, R7, LSL#2 \n"
"    LDR     R0, [R7, #0x10] \n"
"    LDR     R1, [SP, #4] \n"
"    BL      sub_FF89BD58 \n"
"    LDR     R0, [R7, #0x10] \n"
"    LDR     R7, =0x25F8 \n"
"    STR     R0, [R9, R4, LSL#2] \n"
"    LDR     R0, [SP, #0x20] \n"
"    LDRH    R0, [R0] \n"
"    STRH    R0, [R11] \n"
"    LDR     R0, [R7, R4, LSL#2] \n"
"    BL      sub_FF83B3F8 /*_CancelTimer*/ \n"
"    LDR     R2, =0xFF865744 \n"
"    MOV     R1, R2 \n"
"    ORR     R3, R4, #0x300 \n"
"    MOV     R0, #0x1F4 \n"
"    BL      sub_FF83B314 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R7, R4, LSL#2] \n"
"    BEQ     loc_FF865A50 \n"
"    LDR     R1, =0x2CF \n"

"loc_FF865A48:\n"
"    LDR     R0, =0xFF865AA8 \n"
"    BL      _DebugAssert \n"

"loc_FF865A50:\n"
"    ADD     R0, R6, R5, LSL#2 \n"
"    LDR     R0, [R0, #0x18] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF865AE0 \n"
"    LDR     R0, =0x25E8 \n"
"    LDR     R0, [R0, #0xC] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF865AE0 \n"
"    LDR     R2, =0xFF865738 \n"
"    MOV     R1, R2 \n"
"    ORR     R3, R4, #0x400 \n"
"    BL      sub_FF83B314 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R10, R4, LSL#2] \n"
"    BEQ     loc_FF865848 \n"
"    LDR     R1, =0x2D6 \n"

"loc_FF865A94:\n"
"    LDR     R0, =0xFF865AA8 \n"
"    BL      _DebugAssert \n"
"    B       loc_FF865848 \n"

"loc_FF865AE0:\n"
"    LDR     R0, [R6, R5, LSL#2] \n"
"    B       loc_FF8658B0 \n"

"loc_FF865AE8:\n"
"    LDR     R0, [R9, R4, LSL#2] \n"
"    CMP     R0, #0 \n"
"    MOVEQ   R1, #0x2E0 \n"
"    LDREQ   R0, =0xFF865AA8 \n"
"    BLEQ    _DebugAssert \n"
"    RSB     R0, R4, R4, LSL#3 \n"
"    ADD     R0, R6, R0, LSL#2 \n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF89BE30 \n"
"    MOV     R2, #0 \n"
"    STR     R2, [R9, R4, LSL#2] \n"
"    B       loc_FF865848 \n"
);
}
