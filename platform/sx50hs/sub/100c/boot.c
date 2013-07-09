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
//** boot @ 0xFF00000C - 0xFF000184, length=95
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
"    MOV     R0, #0x37 \n"
"    MCR     p15, 0, R0, c6, c2 \n"
"    MOV     R0, #0x40000037 \n"
"    MCR     p15, 0, R0, c6, c3 \n"
"    MOV     R0, #0x80000017 \n"
"    MCR     p15, 0, R0, c6, c4 \n"
"    LDR     R0, =0xFF00002F \n"
"    MCR     p15, 0, R0, c6, c5 \n"
"    LDR     R0, =0xD000002B \n"
"    MCR     p15, 0, R0, c6, c7 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c2, c0 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c2, c0, 1 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c3, c0 \n"
"    LDR     R0, =0x33333330 \n"
"    MCR     p15, 0, R0, c5, c0, 2 \n"
"    LDR     R0, =0x33333330 \n"
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
"    LDR     R0, =0xFF746AC8 \n"
"    LDR     R1, =0x685000 \n"
"    LDR     R3, =0x6946B4 \n"

"loc_FF000144:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF000144 \n"
"    LDR     R0, =0xFF731694 \n"
"    LDR     R1, =0x1900 \n"
"    LDR     R3, =0x16D34 \n"

"loc_FF000160:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF000160 \n"
"    LDR     R1, =0x1B3DD4 \n"
"    MOV     R2, #0 \n"

"loc_FF000178:\n"
"    CMP     R3, R1 \n"
"    STRCC   R2, [R3], #4 \n"
"    BCC     loc_FF000178 \n"
/* Install task hooks via 0x193x is not possible with this new dryos version
   So the below code patches the CreateTask function in RAM to install our
   hook -- ERR99
*/
// Install CreateTask patch
"    LDR     R0, =patch_CreateTask\n"   // Patch data
"    LDM     R0, {R1,R2}\n"             // Get two patch instructions
"    LDR     R0, =hook_CreateTask\n"    // Address to patch
"    STM     R0, {R1,R2}\n"             // Store patch instructions

"    B       sub_FF00038C_my \n"  // --> Patched. Old value = 0xFF00038C.

"patch_CreateTask:\n"
"    LDR     PC, [PC,#-0x4]\n"          // Do jump to absolute address CreateTask_my
"    .long   CreateTask_my\n"
);
}

/*************************************************************/
//** CreateTask_my @ 0x0068AB8C - 0x0068AB90, length=2
void __attribute__((naked,noinline)) CreateTask_my() {
asm volatile (
"    STMFD   SP!, {R0}\n"
//R3 = Pointer to task function to create

/*** INSTALL capt_seq_task() hook ***/
"    LDR     R0, =task_CaptSeq\n"       // DryOS original code function ptr.
"    CMP     R0, R3\n"                  // is the given taskptr equal to our searched function?
"    LDREQ   R3, =capt_seq_task\n"      // if so replace with our task function base ptr.
"    BEQ     exitHook\n"                // below compares not necessary if this check has found something.

/*** INSTALL exp_drv_task() hook ***/
"    LDR     R0, =task_ExpDrv\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =exp_drv_task\n"
"    BEQ     exitHook\n"

/*** INSTALL filewrite() hook ***/
"    LDR     R0, =task_FileWrite\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =filewritetask\n"
"    BEQ     exitHook\n"

/*** INSTALL JogDial() hook ***/
"    LDR     R0, =task_RotaryEncoder\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =JogDial_task_my\n"
"    BEQ     exitHook\n"

/*** INSTALL movie_record_task() hook ***/
"    LDR     R0, =task_MovieRecord\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =movie_record_task\n"
"    BEQ     exitHook\n"

/*** INSTALL init_file_modules_task() hook ***/
"    LDR     R0, =task_InitFileModules\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =init_file_modules_task\n"

"exitHook:\n" 
// restore overwritten registers
"    LDMFD   SP!, {R0}\n"
// Execute overwritten instructions from original code, then jump to firmware
"    STMFD   SP!, {R1-R9,LR} \n"
"    MOV     R4, R0 \n"
"    LDR     PC, =0x0068AB94 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF00038C_my @ 0xFF00038C - 0xFF0003F4, length=27
void __attribute__((naked,noinline)) sub_FF00038C_my() {

    if ( (*(int*)0xC022F48C & 0x800000) )
        *(int*)(0x2E0C+0x8) = 0x200000;     // Playmode "PhySwConfig.c" SX50 FF05CE8C
    else
        *(int*)(0x2E0C+0x8) = 0x100000;     // Shootingmode

asm volatile (
"    LDR     R0, =0xFF000404 \n"
"    MOV     R1, #0 \n"
"    LDR     R3, =0xFF00043C \n"

"loc_FF000398:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF000398 \n"
"    LDR     R0, =0xFF00043C \n"
"    MOV     R1, #0x4B0 \n"
"    LDR     R3, =0xFF000624 \n"

"loc_FF0003B4:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF0003B4 \n"
"    MOV     R0, #0xD2 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    MOV     R0, #0xD3 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    LDR     R0, =0x698 \n"
"    LDR     R2, =0xEEEEEEEE \n"
"    MOV     R3, #0x1000 \n"

"loc_FF0003E8:\n"
"    CMP     R0, R3 \n"
"    STRCC   R2, [R0], #4 \n"
"    BCC     loc_FF0003E8 \n"
"    BL      sub_FF00116C_my \n"  // --> Patched. Old value = 0xFF00116C.
);
}

/*************************************************************/
//** sub_FF00116C_my @ 0xFF00116C - 0xFF001218, length=44
void __attribute__((naked,noinline)) sub_FF00116C_my() {
asm volatile (
"    STR     LR, [SP, #-4]! \n"
"    SUB     SP, SP, #0x74 \n"
"    MOV     R1, #0x74 \n"
"    MOV     R0, SP \n"
"    BL      sub_00690440 \n"
"    MOV     R0, #0x67000 \n"
"    STR     R0, [SP, #4] \n"

#if defined(OPT_CHDK_IN_EXMEM) // use original heap offset if CHDK is loaded in high memory
"    LDR     R0, =0x1B3DD4 \n"
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      // 
#endif

"    LDR     R2, =0x55D440 \n"
"    STR     R0, [SP, #8] \n"
"    SUB     R0, R2, R0 \n"
"    STR     R0, [SP, #0xC] \n"
"    MOV     R0, #0x22 \n"
"    STR     R0, [SP, #0x18] \n"
"    MOV     R0, #0x7C \n"
"    STR     R0, [SP, #0x1C] \n"
"    LDR     R1, =0x565C00 \n"
"    LDR     R0, =0x1CD \n"
"    STR     R1, [SP] \n"
"    STR     R0, [SP, #0x20] \n"
"    MOV     R0, #0x96 \n"
"    STR     R2, [SP, #0x10] \n"
"    STR     R1, [SP, #0x14] \n"
"    STR     R0, [SP, #0x24] \n"
"    STR     R0, [SP, #0x28] \n"
"    MOV     R0, #0x64 \n"
"    STR     R0, [SP, #0x2C] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [SP, #0x30] \n"
"    STR     R0, [SP, #0x34] \n"
"    MOV     R0, #0x10 \n"
"    STR     R0, [SP, #0x5C] \n"
"    MOV     R0, #0x800 \n"
"    STR     R0, [SP, #0x60] \n"
"    MOV     R0, #0xA0 \n"
"    STR     R0, [SP, #0x64] \n"
"    MOV     R0, #0x280 \n"
"    STR     R0, [SP, #0x68] \n"
"    LDR     R1, =sub_FF00421C_my \n"  // --> Patched. Old value = 0xFF00421C.
"    MOV     R2, #0 \n"
"    MOV     R0, SP \n"
"    BL      sub_006867E8 \n"
"    ADD     SP, SP, #0x74 \n"
"    LDR     PC, [SP], #4 \n"
);
}

/*************************************************************/
//** sub_FF00421C_my @ 0xFF00421C - 0xFF004290, length=30
void __attribute__((naked,noinline)) sub_FF00421C_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF000AE8 \n"
"    BL      sub_FF005358 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF004330 \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF003E54 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF004338 \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF004348 \n"
"    BL      sub_FF003F3C \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF004350 \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF004348 \n"
"    BL      sub_FF00295C \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF004364 \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF004CF4 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF004370 \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF00165C \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF00437C \n"
"    BLLT    _err_init_task \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF00AE5C_my \n"  // --> Patched. Old value = 0xFF00AE5C.
);
}

/*************************************************************/
//** sub_FF00AE5C_my @ 0xFF00AE5C - 0xFF00AED4, length=31
void __attribute__((naked,noinline)) sub_FF00AE5C_my() {
asm volatile (
"    STMFD   SP!, {R3,LR} \n"
"    BL      sub_FF022240 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF00AE7C \n"
"    BL      sub_FF01BB6C \n"
"    CMP     R0, #0 \n"
"    MOVNE   R0, #1 \n"
"    BNE     loc_FF00AE80 \n"

"loc_FF00AE7C:\n"
"    MOV     R0, #0 \n"

"loc_FF00AE80:\n"
"    BL      sub_FF01A018_my \n"  // --> Patched. Old value = 0xFF01A018.
"    CMP     R0, #0 \n"
"    BNE     loc_FF00AEA0 \n"
"    BL      sub_FF0193AC \n"
"    LDR     R1, =0x83DC00 \n"
"    MOV     R0, #0x54 \n"
"    BL      sub_FF020808 \n"

"loc_FF00AE9C:\n"
"    B       loc_FF00AE9C \n"

"loc_FF00AEA0:\n"
"    BL      sub_0068C314 \n"
"    LDR     R1, =0x5CE000 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF020604 \n"
"    BL      sub_0068C52C \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =task_Startup_my \n"  // --> Patched. Old value = 0xFF00ADF4.
"    MOV     R2, #0 \n"
"    MOV     R1, #0x19 \n"
"    LDR     R0, =0xFF00AEE4 \n"
"    BL      _CreateTask \n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R3,PC} \n"
);
}

/*************************************************************/
//** sub_FF01A018_my @ 0xFF01A018 - 0xFF01A070, length=23
void __attribute__((naked,noinline)) sub_FF01A018_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    MOV     R6, R0 \n"
//"  BL      _sub_FF05CE84 \n"  // --> Nullsub call removed.
"    MOV     R0, #0x4B \n"
"    BL      sub_FF020818 \n"
"    MOV     R4, #1 \n"
"    BIC     R5, R4, R0 \n"
"    MOV     R0, #0x4C \n"
"    BL      sub_FF020818 \n"
"    CMP     R6, #0 \n"
"    BIC     R4, R4, R0 \n"
"    BEQ     loc_FF01A050 \n"
"    ORRS    R0, R5, R4 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"

"loc_FF01A050:\n"
"    BL      sub_FF022240 \n"
"    MOV     R2, R0 \n"
"    MOV     R3, #0 \n"
"    MOV     R1, R4 \n"
"    MOV     R0, R5 \n"
//"  BL      _sub_FF05CE8C \n"  // disable startup checks
//"  BL      _sub_FF05CE88 \n"  // --> Nullsub call removed.
"    MOV     R0, #1 \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** task_Startup_my @ 0xFF00ADF4 - 0xFF00AE58, length=26
void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF00485C \n"
"    BL      sub_FF01B190 \n"
"    BL      sub_FF0192D0 \n"
//"  BL      _sub_FF05DB40 \n"  // --> Nullsub call removed.
"    BL      sub_FF022474 \n"
//"  BL      _sub_FF02231C \n"  // CheckForDiskBootBinStuff
"    BL      sub_FF0225E0 \n"
"    BL      sub_FF0227AC \n"
//"  BL      _sub_FF0225D4 \n"  // --> Nullsub call removed.
"    BL      sub_FF0224A4 \n"
"    BL      sub_FF020538 \n"
"    BL      sub_FF0227B4 \n"
"    BL      CreateTask_spytask\n" // added
"    BL      taskcreatePhySw_my \n"  // --> Patched. Old value = 0xFF019EC0.
"    BL      sub_FF01DA78 \n"
"    BL      sub_FF0AF590 \n"
"    BL      sub_FF016E50 \n"
"    BL      sub_FF018C38 \n"
"    BL      sub_FF022000 \n"
"    BL      sub_FF019284 \n"
"    BL      sub_FF018BD4 \n"
//"  BL      _sub_FF0225D8 \n"  // --> Nullsub call removed.
"    BL      sub_FF017AFC \n"
"    BL      sub_FF018B98 \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF004998 \n"
);
}

/*************************************************************/
//** taskcreatePhySw_my @ 0xFF019EC0 - 0xFF019F14, length=22
void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    LDR     R4, =0x1D64 \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF019EF4 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =mykbd_task \n"  // --> Patched. Old value = 0xFF019E8C.
"    MOV     R2, #0x2000 \n"  // --> Patched. Old value = 0x800. stack size for new task_PhySw so we don't have to do stack switch
"    MOV     R1, #0x17 \n"
"    LDR     R0, =0xFF01A168 \n"
"    BL      sub_0068AF04 /*_CreateTaskStrictly*/ \n"
"    STR     R0, [R4, #4] \n"

"loc_FF019EF4:\n"
"    BL      sub_FF05DF88 \n"
"    BL      sub_FF09948C \n"
"    BL      sub_FF01BABC \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF019F14 \n"
"    LDR     R1, =0x3AE98 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF0993F8 \n"

"loc_FF019F14:\n"
"    LDMFD   SP!, {R3-R5,PC} \n"
);
}

/*************************************************************/
//** init_file_modules_task @ 0xFF04A93C - 0xFF04A970, length=14
void __attribute__((naked,noinline)) init_file_modules_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF09BA04 \n"
"    LDR     R5, =0x5006 \n"
"    MOVS    R4, R0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, R5 \n"
"    BLNE    _PostLogicalEventToUI \n"
"    BL      sub_FF09BA30 \n"
"    BL      core_spytask_can_start\n"  // CHDK: Set "it's-safe-to-start" flag for spytask
"    CMP     R4, #0 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    MOV     R0, R5 \n"
"    LDMFD   SP!, {R4-R6,LR} \n"
"    MOV     R1, #0 \n"
"    B       _PostLogicalEventToUI \n"
);
}

/*************************************************************/
//** JogDial_task_my @ 0xFF05DC5C - 0xFF05DF84, length=203
void __attribute__((naked,noinline)) JogDial_task_my() {
asm volatile (
"    STMFD   SP!, {R4-R11,LR} \n"
"    SUB     SP, SP, #0x1C \n"
"    BL      sub_FF05DFF4 \n"
"    LDR     R12, =0x2E30 \n"
"    LDR     R6, =0xFF49E790 \n"
"    MOV     R0, #0 \n"
"    ADD     R10, SP, #8 \n"
"    ADD     R9, SP, #0xC \n"

// Save pointer for kbd.c routine
"    LDR     R2, =jog_position \n"
"    STR     R9, [R2] \n"

"loc_FF05DC7C:\n"
"    ADD     R2, SP, #0x14 \n"
"    MOV     R1, #0 \n"
"    ADD     R4, R2, R0, LSL#1 \n"
"    ADD     R3, SP, #0x10 \n"
"    STRH    R1, [R4] \n"
"    ADD     R4, R3, R0, LSL#1 \n"
"    STRH    R1, [R4] \n"
"    STR     R1, [R9, R0, LSL#2] \n"
"    STR     R1, [R10, R0, LSL#2] \n"
"    ADD     R0, R0, #1 \n"
"    CMP     R0, #1 \n"
"    BLT     loc_FF05DC7C \n"

"loc_FF05DCAC:\n"
"    LDR     R0, =0x2E30 \n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R0, #8] \n"
"    MOV     R1, SP \n"
"    BL      sub_0068BDE0 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    LDRNE   R1, =0x20B \n"
"    LDRNE   R0, =0xFF05DF0C \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP] \n"
"    AND     R4, R0, #0xFF \n"
"    AND     R0, R0, #0xFF00 \n"
"    CMP     R0, #0x100 \n"
"    BEQ     loc_FF05DD1C \n"
"    CMP     R0, #0x200 \n"
"    BEQ     loc_FF05DD54 \n"
"    CMP     R0, #0x300 \n"
"    BEQ     loc_FF05DF58 \n"
"    CMP     R0, #0x400 \n"
"    BNE     loc_FF05DCAC \n"
"    CMP     R4, #0 \n"
"    LDRNE   R1, =0x285 \n"
"    LDRNE   R0, =0xFF05DF0C \n"
"    BLNE    _DebugAssert \n"
"    RSB     R0, R4, R4, LSL#3 \n"
"    LDR     R0, [R6, R0, LSL#2] \n"

"loc_FF05DD14:\n"
"    BL      sub_FF05DFD8 \n"
"    B       loc_FF05DCAC \n"

"loc_FF05DD1C:\n"
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
"    LDR     R0, =0x2E3C \n"
"    LDR     R0, [R0, R4, LSL#2] \n"
"    BL      sub_FF020DF4 /*_CancelTimer*/ \n"
"    LDR     R2, =0xFF05DBA8 \n"
"    ORR     R3, R4, #0x200 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, #0x28 \n"
"    BL      sub_FF020D10 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R10, R4, LSL#2] \n"
"    BEQ     loc_FF05DCAC \n"
"    LDR     R1, =0x21D \n"
"    B       loc_FF05DEF8 \n"

"loc_FF05DD54:\n"
"    RSB     R5, R4, R4, LSL#3 \n"
"    LDR     R0, [R6, R5, LSL#2] \n"
"    LDR     R1, =0xC0240000 \n"
"    ADD     R0, R1, R0, LSL#8 \n"
"    LDR     R0, [R0, #0x104] \n"
"    MOV     R1, R0, ASR#16 \n"
"    ADD     R0, SP, #0x14 \n"
"    ADD     R11, R0, R4, LSL#1 \n"
"    ADD     R0, SP, #0x10 \n"
"    ADD     R0, R0, R4, LSL#1 \n"
"    STRH    R1, [R11] \n"
"    STR     R0, [SP, #0x18] \n"
"    LDRSH   R3, [R0] \n"
"    SUB     R2, R1, R3 \n"
"    CMP     R2, #0 \n"
"    BNE     loc_FF05DDD8 \n"
"    LDR     R0, [R9, R4, LSL#2] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF05DEB4 \n"
"    LDR     R7, =0x2E3C \n"
"    LDR     R0, [R7, R4, LSL#2] \n"
"    BL      sub_FF020DF4 /*_CancelTimer*/ \n"
"    LDR     R2, =0xFF05DBB4 \n"
"    ORR     R3, R4, #0x300 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, #0x1F4 \n"
"    BL      sub_FF020D10 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R7, R4, LSL#2] \n"
"    BEQ     loc_FF05DEB4 \n"
"    LDR     R1, =0x236 \n"
"    B       loc_FF05DEAC \n"

"loc_FF05DDD8:\n"
"    MOV     R0, R2 \n"
"    RSBLT   R0, R0, #0 \n"
"    MOVLE   R7, #0 \n"
"    MOVGT   R7, #1 \n"
"    CMP     R0, #0xFF \n"
"    BLS     loc_FF05DE14 \n"
"    LDR     R0, =0x7FFF \n"
"    CMP     R2, #0 \n"
"    SUBLE   R0, R0, R3 \n"
"    ADDLE   R0, R0, R1 \n"
"    SUBGT   R0, R0, R1 \n"
"    ADDGT   R0, R0, R3 \n"
"    MVN     R1, #0x8000 \n"
"    SUB     R0, R0, R1 \n"
"    EOR     R7, R7, #1 \n"

"loc_FF05DE14:\n"
"    STR     R0, [SP, #4] \n"
"    LDR     R0, [R9, R4, LSL#2] \n"
"    CMP     R0, #0 \n"
"    ADDEQ   R0, R6, R5, LSL#2 \n"
"    LDREQ   R0, [R0, #8] \n"
"    BEQ     loc_FF05DE4C \n"
"    ADD     R8, R6, R5, LSL#2 \n"
"    ADD     R1, R8, R7, LSL#2 \n"
"    LDR     R1, [R1, #0x10] \n"
"    CMP     R1, R0 \n"
"    BEQ     loc_FF05DE50 \n"
"    LDR     R0, [R8, #0xC] \n"
"    BL      sub_FF019F18 \n"
"    LDR     R0, [R8, #8] \n"

"loc_FF05DE4C:\n"
"    BL      sub_FF019F18 \n"

"loc_FF05DE50:\n"
"    ADD     R0, R6, R5, LSL#2 \n"
"    ADD     R7, R0, R7, LSL#2 \n"
"    LDR     R0, [R7, #0x10] \n"
"    LDR     R1, [SP, #4] \n"
"    BL      sub_FF019F28 \n"
"    LDR     R0, [R7, #0x10] \n"
"    LDR     R7, =0x2E3C \n"
"    STR     R0, [R9, R4, LSL#2] \n"
"    LDRH    R1, [R11] \n"
"    LDR     R0, [SP, #0x18] \n"
"    STRH    R1, [R0] \n"
"    LDR     R0, [R7, R4, LSL#2] \n"
"    BL      sub_FF020DF4 /*_CancelTimer*/ \n"
"    LDR     R2, =0xFF05DBB4 \n"
"    ORR     R3, R4, #0x300 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, #0x1F4 \n"
"    BL      sub_FF020D10 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R7, R4, LSL#2] \n"
"    BEQ     loc_FF05DEB4 \n"
"    LDR     R1, =0x267 \n"

"loc_FF05DEAC:\n"
"    LDR     R0, =0xFF05DF0C \n"
"    BL      _DebugAssert \n"

"loc_FF05DEB4:\n"
"    ADD     R0, R6, R5, LSL#2 \n"
"    LDR     R0, [R0, #0x18] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF05DF50 \n"
"    LDR     R0, =0x2E30 \n"
"    LDR     R0, [R0, #0x10] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF05DF50 \n"
"    LDR     R2, =0xFF05DBA8 \n"
"    ORR     R3, R4, #0x400 \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF020D10 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R10, R4, LSL#2] \n"
"    BEQ     loc_FF05DCAC \n"
"    LDR     R1, =0x26E \n"

"loc_FF05DEF8:\n"
"    LDR     R0, =0xFF05DF0C \n"
"    BL      _DebugAssert \n"
"    B       loc_FF05DCAC \n"

"loc_FF05DF50:\n"
"    LDR     R0, [R6, R5, LSL#2] \n"
"    B       loc_FF05DD14 \n"

"loc_FF05DF58:\n"
"    LDR     R0, [R9, R4, LSL#2] \n"
"    CMP     R0, #0 \n"
"    MOVEQ   R1, #0x278 \n"
"    LDREQ   R0, =0xFF05DF0C \n"
"    BLEQ    _DebugAssert \n"
"    RSB     R0, R4, R4, LSL#3 \n"
"    ADD     R0, R6, R0, LSL#2 \n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF019F18 \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R9, R4, LSL#2] \n"
"    B       loc_FF05DCAC \n"
);
}
