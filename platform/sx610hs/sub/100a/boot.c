/*
 * boot.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;

/*----------------------------------------------------------------------
    CreateTask_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask()
{
    _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
}

/*----------------------------------------------------------------------
    boot()

    Main entry point for the CHDK code
-----------------------------------------------------------------------*/


/*************************************************************/
//** boot @ 0xFF02000C - 0xFF02017C, length=93
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
"    MOV     R0, #0x39 \n"
"    MCR     p15, 0, R0, c6, c2 \n"
"    MOV     R0, #0x40000039 \n"
"    MCR     p15, 0, R0, c6, c3 \n"
"    MOV     R0, #0x80000017 \n"
"    MCR     p15, 0, R0, c6, c4 \n"
"    LDR     R0, =0xFF00002F \n"
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
"    MVN     R1, #0 \n"
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
"    LDR     R0, =0xFF864FF4 \n"
"    LDR     R1, =0x6B1000 \n"
"    LDR     R3, =0x6E2D2A \n"

"loc_FF02013C:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF02013C \n"
"    LDR     R0, =0xFF84DE10 \n"
"    LDR     R1, =0x1900 \n"
"    LDR     R3, =0x18AE4 \n"

"loc_FF020158:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF020158 \n"
"    LDR     R1, =0x2CE584 \n"
"    MOV     R2, #0 \n"

"loc_FF020170:\n"
"    CMP     R3, R1 \n"
"    STRCC   R2, [R3], #4 \n"
"    BCC     loc_FF020170 \n"
/* Install task hooks via 0x193x is not possible with this new dryos version
   So the below code patches the CreateTask function in RAM to install our
   hook -- ERR99
*/
// Install CreateTask patch
"    LDR     R0, =patch_CreateTask\n"   // Patch data
"    LDM     R0, {R1,R2}\n"             // Get two patch instructions
"    LDR     R0, =hook_CreateTask\n"    // Address to patch
"    STM     R0, {R1,R2}\n"             // Store patch instructions

"    B       sub_FF0203C4_my \n"  // --> Patched. Old value = 0xFF0203C4.

"patch_CreateTask:\n"
"    LDR     PC, [PC,#-0x4]\n"          // Do jump to absolute address CreateTask_my
"    .long   CreateTask_my\n"
);
}

/*************************************************************/
//** CreateTask_my @ 0x006B5658 - 0x006B565C, length=2
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
//"    LDR     R0, =task_ExpDrv\n"
//"    CMP     R0, R3\n"
//"    LDREQ   R3, =exp_drv_task\n"
//"    BEQ     exitHook\n"

/*** INSTALL filewrite() hook ***/
#ifdef CAM_HAS_FILEWRITETASK_HOOK
"    LDR     R0, =task_FileWrite\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =filewritetask\n"
"    BEQ     exitHook\n"
#endif
/*** INSTALL movie_record_task() hook ***/
//"    LDR     R0, =task_MovieRecord\n"
//"    CMP     R0, R3\n"
//"    LDREQ   R3, =movie_record_task\n"
//"    BEQ     exitHook\n"

/*** INSTALL liveimage_task() hook ***/
//"    LDR     R0, =task_LiveImageTask\n"
//"    CMP     R0, R3\n"
//"    LDREQ   R3, =liveimage_task\n"
//"    BEQ     exitHook\n"

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
"    LDR     PC, =0x006B5660 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF0203C4_my @ 0xFF0203C4 - 0xFF02042C, length=27
void __attribute__((naked,noinline)) sub_FF0203C4_my() {

   // Replacement of sub_ for correct power-on.
   // (short press = playback mode, long press = record mode)
   // value and pointer fromsub_FF074124 sx610hs_100a 
   *(int*)(0x2e70+0x4) = (*(int*)0xC022F484)&0x100000 ? 0x80000 : 0x40000;

asm volatile (
"    LDR     R0, =0xFF02043C \n"
"    MOV     R1, #0 \n"
"    LDR     R3, =0xFF020474 \n"

"loc_FF0203D0:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF0203D0 \n"
"    LDR     R0, =0xFF020474 \n"
"    MOV     R1, #0x1C0 \n"
"    LDR     R3, =0xFF02065C \n"

"loc_FF0203EC:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF0203EC \n"
"    MOV     R0, #0xD2 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    MOV     R0, #0xD3 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    LDR     R0, =0x3A8 \n"
"    LDR     R2, =0xEEEEEEEE \n"
"    MOV     R3, #0x1000 \n"

"loc_FF020420:\n"
"    CMP     R0, R3 \n"
"    STRCC   R2, [R0], #4 \n"
"    BCC     loc_FF020420 \n"
"    B       sub_FF0228D4_my \n"  // --> Patched. Old value = 0xFF0228D4.
);
}

/*************************************************************/
//** sub_FF0228D4_my @ 0xFF0228D4 - 0xFF0229E0, length=68
void __attribute__((naked,noinline)) sub_FF0228D4_my() {
asm volatile (
"    LDR     R1, =0x1A5C \n"
"    STR     LR, [SP, #-4]! \n"
"    SUB     SP, SP, #0x7C \n"
"    MOV     R0, #0x80000 \n"
"    STR     R0, [R1] \n"
"    LDR     R0, =0x40DEBEE0 \n"
"    LDR     R1, =0x1A60 \n"
"    STR     R0, [R1] \n"
"    LDR     R1, =0x1A64 \n"
"    ADD     R0, R0, #0x2000 \n"
"    STR     R0, [R1] \n"
"    MOV     R1, #0x78 \n"
"    ADD     R0, SP, #4 \n"
"    BL      sub_006DACDC \n"
"    MOV     R0, #0xA0000 \n"
"    STR     R0, [SP, #8] \n"

#if defined(CHDK_NOT_IN_CANON_HEAP) // use original heap offset if CHDK is loaded in high memory
"    LDR     R0, =0x2CE584 \n"
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      //
#endif

"    LDR     R2, =0x56346C \n"
"    STR     R0, [SP, #0xC] \n"
"    SUB     R0, R2, R0 \n"
"    STR     R0, [SP, #0x10] \n"
"    MOV     R0, #0x22 \n"
"    STR     R0, [SP, #0x1C] \n"
"    MOV     R0, #0x98 \n"
"    STR     R0, [SP, #0x20] \n"
"    MOV     R0, #0x1E8 \n"
"    STR     R2, [SP, #0x14] \n"
"    STR     R0, [SP, #0x24] \n"
"    LDR     R1, =0x56E000 \n"
"    MOV     R0, #0xFA \n"
"    STR     R0, [SP, #0x28] \n"
"    MOV     R0, #0xB6 \n"
"    STR     R1, [SP, #4] \n"
"    STR     R0, [SP, #0x2C] \n"
"    MOV     R0, #0x85 \n"
"    STR     R0, [SP, #0x30] \n"
"    MOV     R0, #0x40 \n"
"    STR     R0, [SP, #0x34] \n"
"    MOV     R0, #4 \n"
"    STR     R0, [SP, #0x38] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [SP, #0x3C] \n"
"    MOV     R0, #0x10 \n"
"    STR     R0, [SP, #0x60] \n"
"    MOV     R0, #0x1000 \n"
"    STR     R0, [SP, #0x64] \n"
"    MOV     R0, #0x100 \n"
"    STR     R0, [SP, #0x68] \n"
"    MOV     R0, #0x2000 \n"
"    STR     R1, [SP, #0x18] \n"
"    STR     R0, [SP, #0x6C] \n"
"    LDR     R1, =sub_FF024704_my \n"  // --> Patched. Old value = 0xFF024704.
"    MOV     R2, #0 \n"
"    ADD     R0, SP, #4 \n"
"    BL      sub_006B1BC8 \n"
"    ADD     SP, SP, #0x7C \n"
"    LDR     PC, [SP], #4 \n"
);
}

/*************************************************************/
//** sub_FF024704_my @ 0xFF024704 - 0xFF02479C, length=39
void __attribute__((naked,noinline)) sub_FF024704_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    LDR     R4, =0xFF0247C0 /*'/_term'*/ \n"
"    BL      sub_FF020858 \n"
"    LDR     R1, =0x1A5C \n"
"    LDR     R0, =0x19F0 \n"
"    LDR     R1, [R1] \n"
"    LDR     R0, [R0] \n"
"    ADD     R1, R1, #0x10 \n"
"    CMP     R0, R1 \n"
"    LDRCC   R0, =0xFF0247D0 /*'USER_MEM size checking'*/ \n"
"    BLCC    _err_init_task \n"
"    BL      sub_FF0234E0 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF0247E8 /*'dmSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF0224E8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF0247F0 /*'termDriverInit'*/ \n"
"    BLLT    _err_init_task \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF0225C8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF024800 /*'termDeviceCreate'*/ \n"
"    BLLT    _err_init_task \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF022100 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF024814 /*'stdioSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF024D70 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF024820 /*'stdlibSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF0210A8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF02482C /*'extlib_setup'*/ \n"
"    BLLT    _err_init_task \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF027AA0_my \n"  // --> Patched. Old value = 0xFF027AA0.
);
}

/*************************************************************/
//** sub_FF027AA0_my @ 0xFF027AA0 - 0xFF027AF0, length=21
void __attribute__((naked,noinline)) sub_FF027AA0_my() {
asm volatile (
"    STMFD   SP!, {R3,LR} \n"
"    BL      sub_FF0337E4 \n"
"    BL      sub_FF02D04C /*_IsNormalCameraMode_FW*/ \n"
//"  BL      _sub_FF02BA64 \n"  // See: http://chdk.setepontos.com/index.php?topic=12321.msg121619#msg121619
//"  CMP     R0, #0 \n"
//"  BNE     loc_FF027AC0 \n"
//"  BL      _sub_FF02B210 \n"

"loc_FF027ABC:\n"
//"  B       loc_FF027ABC \n"

"loc_FF027AC0:\n"
"    BL      sub_006B8A84 \n"
"    LDR     R1, =0x60E000 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF037A44 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =task_Startup_my \n"  // --> Patched. Old value = 0xFF027A38.
"    MOV     R2, #0 \n"
"    MOV     R1, #0x19 \n"
"    LDR     R0, =0xFF027AFC /*'Startup'*/ \n"
"    BL      _CreateTask \n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R3,PC} \n"
);
}

/*************************************************************/
//** task_Startup_my @ 0xFF027A38 - 0xFF027A9C, length=26
void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF022C84 \n"
"    BL      sub_FF02BF30 \n"
"    BL      sub_FF02B1BC \n"
//"  BL      _sub_FF074A64 \n"  // --> Nullsub call removed.
"    BL      sub_FF0377F0 \n"
//"  BL      _sub_FF0376B0 \n"  // load DISKBOOT.BIN
"    BL      sub_FF037954 \n"
"    BL      sub_FF037B18 \n"
//"  BL      _sub_FF037948 \n"  // --> Nullsub call removed.
"    BL      sub_FF03782C \n"
"    BL      sub_FF03371C \n"
"    BL      sub_FF037B20 \n"
"    BL      CreateTask_spytask\n" // added
"    BL      taskcreatePhySw_my \n"  // --> Patched. Old value = 0xFF02B910.
"    BL      init_required_fw_features\n" // added
"    BL      sub_FF0313A4 \n"
"    BL      sub_FF0C30C8 \n"
"    BL      sub_FF028E70 \n"
"    BL      sub_FF02AD18 \n"
"    BL      sub_FF0373C4 \n"
"    BL      sub_FF02B170 \n"
"    BL      sub_FF02ACAC \n"
//"  BL      _sub_FF03794C \n"  // --> Nullsub call removed.
"    BL      sub_FF029CBC \n"
"    BL      sub_FF02AC68 \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF022DD4 \n"
);
}

/*************************************************************/
//** taskcreatePhySw_my @ 0xFF02B910 - 0xFF02B954, length=18
void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    BL      sub_FF036630 \n"
"    BL      sub_FF02CF84 /*_IsFactoryMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    BLEQ    sub_FF036598 /*_OpLog.Start_FW*/ \n"
"    LDR     R4, =0x1C9C \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF02B954 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =mykbd_task \n"  // --> Patched. Old value = 0xFF02B8DC.
"    MOV     R2, #0x2000 \n"  // --> Patched. Old value = 0x800. stack size for new task_PhySw so we don't have to do stack switch
"    MOV     R1, #0x17 \n"
"    LDR     R0, =0xFF02BC04 /*'PhySw'*/ \n"
"    BL      sub_006B7BD4 /*_CreateTaskStrictly*/ \n"
"    STR     R0, [R4, #4] \n"

"loc_FF02B954:\n"
"    LDMFD   SP!, {R3-R5,PC} \n"
);
}
// Workaround for cards becoming read-only in camera when diskboot'ing to playback mode.
// The following flag is checked by the function that calls WriteSDCard (sub_FF02FFC0)_sx610_100a
// See sx530 porting thread for related discussions. https://chdk.setepontos.com/index.php?topic=12418
void fix_writable_media_flag() {
    *(int*)0x1d68 = 1;
}

/*************************************************************/
//** init_file_modules_task @ 0xFF0602C0 - 0xFF0602F4, length=14
void __attribute__((naked,noinline)) init_file_modules_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF0AD0F8 \n"
"    LDR     R5, =0x5006 \n"
"    MOVS    R4, R0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, R5 \n"
"    BLNE    _PostLogicalEventToUI \n"
"    BL      sub_FF0AD128 \n"
"    BL      fix_writable_media_flag\n" // SD card startup fix
"    BL      core_spytask_can_start\n"  // CHDK: Set "it's-safe-to-start" flag for spytask
"    CMP     R4, #0 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    MOV     R0, R5 \n"
"    LDMFD   SP!, {R4-R6,LR} \n"
"    MOV     R1, #0 \n"
"    B       _PostLogicalEventToUI \n"
);
}
/*
    *** TEMPORARY workaround ***
    Init stuff to avoid asserts on cameras running DryOS r54+
    Execute this only once
 */
void init_required_fw_features(void) {
    extern void _init_focus_eventflag();
    extern void _init_nd_eventflag();
    extern void _init_nd_semaphore();
    //extern void _init_zoom_semaphore(); // for MoveZoomLensWithPoint

    _init_focus_eventflag();
    _init_nd_eventflag();
    _init_nd_semaphore();
}

