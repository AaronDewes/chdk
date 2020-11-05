/*
 * boot.c - auto-generated by CHDK code_gen.
 */
// Powershot N
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_MovieRecord();
extern void task_ExpDrv();
extern void task_FileWrite();
extern void task_TouchPanel();

/*----------------------------------------------------------------------
    Blink - flash power LED a couple of times
-----------------------------------------------------------------------*/
void pause()
{
 int i ;
 for (i=0; i<1000000; i++) { asm volatile ("nop\n"); }
}

void led_on() { *(int*)0xc022c30c = ( (*(int*)0xc022c30c) & 0xffffffcf ) | 0x20; }

void led_off() { *(int*)0xc022c30c = (*(int*)0xc022c30c) & 0xffffffcf; }

void blink() {
   int i ;
   for (i=1 ; i < 6 ; i++)
   {
      led_on() ;
      pause() ;
      led_off() ;
      pause() ;
   }
}

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
//** boot @ 0xFF00000C - 0xFF000178, length=92
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
"    LDR     R2, =0xC0242010 \n"
"    LDR     R1, [R2] \n"
"    ORR     R1, R1, #1 \n"
"    STR     R1, [R2] \n"
"    LDR     R0, =0xFF8E9E9C \n"
"    LDR     R1, =0x685000 \n"
"    LDR     R3, =0x6B081C \n"

"loc_FF000138:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF000138 \n"
"    LDR     R0, =0xFF8D0134 \n"
"    LDR     R1, =0x1900 \n"
"    LDR     R3, =0x1B668 \n"

"loc_FF000154:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF000154 \n"
"    LDR     R1, =0x2F8B2C \n"
"    MOV     R2, #0 \n"

"loc_FF00016C:\n"
"    CMP     R3, R1 \n"
"    STRCC   R2, [R3], #4 \n"
"    BCC     loc_FF00016C \n"
"  BL    blink \n"

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

/*** INSTALL movie_record_task() hook ***/
//"    LDR     R0, =task_MovieRecord\n"
//"    CMP     R0, R3\n"
//"    LDREQ   R3, =movie_record_task\n"
//"    BEQ     exitHook\n"

/*** INSTALL init_file_modules_task() hook ***/
"    LDR     R0, =task_InitFileModules\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =init_file_modules_task\n"

/*** INSTALL touch_task() hook ***/
"    LDR     R0, =task_TouchPanel\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =task_TouchPanel_my\n"

"exitHook:\n"                     // restore overwritten registers
"    LDMFD   SP!, {R0}\n"         // Execute overwritten instructions from original code, then jump to firmware
"    STMFD   SP!, {R1-R9,LR} \n"
"    MOV     R4, R0 \n"
"    LDR     PC, =0x0068AB94 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF00038C_my @ 0xFF00038C - 0xFF0003F4, length=27
void __attribute__((naked,noinline)) sub_FF00038C_my() {

   // Replacement of sub_ for correct power-on.
   // (enables short press = playback mode, long press = record mode)
   //   1) sub_FF0320E8 -> sub_FF093058 -> sub_FF090770  (sub_FF0320E8 passes 0x14, 0x50, 0x51, 0x15 for play/shoot/wifi/usb ?) 
   //      table @ 0xFF5BD7E0 + 0x14*8 =  0xFF5BD880    ->  table entry =  0xC022F488 , 0x00000001
   //   2) pointer from sub_FF0320E8 -> sub_FF092958 =  0x2FD4 & buttons = play:0x01000000 & wifi:0x00200000 shooting:0x004000000 

    if ((*(int*) 0xC022F488) & 1)       // shooting or playback ? 
        *(int*)(0x2FD4) = 0x01000000;   // playback mode
    else
        *(int*)(0x2FD4) = 0x00400000;   // shooting mode

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
"    MOV     R1, #0x1B0 \n"
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
"    LDR     R0, =0x398 \n"
"    LDR     R2, =0xEEEEEEEE \n"
"    MOV     R3, #0x1000 \n"

"loc_FF0003E8:\n"
"    CMP     R0, R3 \n"
"    STRCC   R2, [R0], #4 \n"
"    BCC     loc_FF0003E8 \n"
"    BL      sub_FF00110C_my \n"  // --> Patched. Old value = 0xFF00110C.
);
}

/*************************************************************/
//** sub_FF00110C_my @ 0xFF00110C - 0xFF0011C0, length=46
void __attribute__((naked,noinline)) sub_FF00110C_my() {
asm volatile (
"    STR     LR, [SP, #-4]! \n"
"    SUB     SP, SP, #0x74 \n"
"    MOV     R1, #0x74 \n"
"    MOV     R0, SP \n"
"    BL      sub_006A93A4 \n"
"    MOV     R0, #0x83000 \n"
"    STR     R0, [SP, #4] \n"

#if defined(CHDK_NOT_IN_CANON_HEAP) // use original heap offset if CHDK is loaded in high memory
"    LDR     R0, =0x2F8B2C \n"
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      //
#endif

"    LDR     R2, =0x53F15C \n"
"    STR     R0, [SP, #8] \n"
"    SUB     R0, R2, R0 \n"
"    STR     R0, [SP, #0xC] \n"
"    MOV     R0, #0x22 \n"
"    STR     R0, [SP, #0x18] \n"
"    MOV     R0, #0x98 \n"
"    STR     R0, [SP, #0x1C] \n"
"    LDR     R0, =0x1E2 \n"
"    LDR     R1, =0x549C00 \n"
"    STR     R2, [SP, #0x10] \n"
"    STR     R0, [SP, #0x20] \n"
"    MOV     R0, #0xF6 \n"
"    STR     R1, [SP] \n"
"    STR     R1, [SP, #0x14] \n"
"    STR     R0, [SP, #0x24] \n"
"    MOV     R0, #0xB6 \n"
"    STR     R0, [SP, #0x28] \n"
"    MOV     R0, #0x85 \n"
"    STR     R0, [SP, #0x2C] \n"
"    MOV     R0, #0x40 \n"
"    STR     R0, [SP, #0x30] \n"
"    MOV     R0, #4 \n"
"    STR     R0, [SP, #0x34] \n"
"    MOV     R0, #0x10 \n"
"    STR     R0, [SP, #0x5C] \n"
"    MOV     R0, #0x800 \n"
"    STR     R0, [SP, #0x60] \n"
"    MOV     R0, #0xA0 \n"
"    STR     R0, [SP, #0x64] \n"
"    MOV     R0, #0x280 \n"
"    STR     R0, [SP, #0x68] \n"
"    LDR     R1, =sub_FF00420C_my \n"  // --> Patched. Old value = 0xFF00420C.
"    MOV     R2, #0 \n"
"    MOV     R0, SP \n"
"    BL      sub_006867E8 \n"
"    ADD     SP, SP, #0x74 \n"
"    LDR     PC, [SP], #4 \n"
);
}

/*************************************************************/
//** sub_FF00420C_my @ 0xFF00420C - 0xFF004280, length=30
void __attribute__((naked,noinline)) sub_FF00420C_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF000AE8 \n"
"    BL      sub_FF00539C \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF00434C /*'dmSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF003E44 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF004354 /*'termDriverInit'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF004364 /*'/_term'*/ \n"
"    BL      sub_FF003F2C \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF00436C /*'termDeviceCreate'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF004364 /*'/_term'*/ \n"
"    BL      sub_FF00294C \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF004380 /*'stdioSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF004D38 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF00438C /*'stdlibSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF001604 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF004398 /*'armlib_setup'*/ \n"
"    BLLT    _err_init_task \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF00B24C_my \n"  // --> Patched. Old value = 0xFF00B24C.
);
}

/*************************************************************/
//** sub_FF00B24C_my @ 0xFF00B24C - 0xFF00B2BC, length=29
void __attribute__((naked,noinline)) sub_FF00B24C_my() {
asm volatile (
"    STMFD   SP!, {R3,LR} \n"
"    BL      sub_FF038018 \n"
"    BL      sub_FF03961C \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF00B270 \n"
"    BL      sub_FF034274 /*_IsNormalCameraMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    MOVNE   R0, #1 \n"
"    BNE     loc_FF00B274 \n"

"loc_FF00B270:\n"
"    MOV     R0, #0 \n"

"loc_FF00B274:\n"
"    BL      sub_FF0320E8_my \n"  // --> Patched. Old value = 0xFF0320E8.
"    CMP     R0, #0 \n"
"    BNE     loc_FF00B288 \n"
"    BL      sub_FF0318D4 \n"

"loc_FF00B284:\n"
"    B       loc_FF00B284 \n"

"loc_FF00B288:\n"
"    BL      sub_0068C318 \n"
"    LDR     R1, =0x5CE000 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF039B68 \n"
"    BL      sub_0068C530 /*_EnableDispatch*/ \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =task_Startup_my \n"  // --> Patched. Old value = 0xFF00B1E4.
"    MOV     R2, #0 \n"
"    MOV     R1, #0x19 \n"
"    LDR     R0, =0xFF00B2C8 /*'Startup'*/ \n"
"    BL      _CreateTask \n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R3,PC} \n"
);
}

/*************************************************************/
//** sub_FF0320E8_my @ 0xFF0320E8 - 0xFF032168, length=33
void __attribute__((naked,noinline)) sub_FF0320E8_my() {
asm volatile (
"    STMFD   SP!, {R2-R8,LR} \n"
"    MOV     R8, R0 \n"
//"  BL      _sub_FF092950 \n"  // --> Nullsub call removed.
"    MOV     R0, #0x14 \n"
"    BL      sub_FF090770 \n"
"    MOV     R4, #1 \n"
"    BIC     R5, R4, R0 \n"
"    MOV     R0, #0x50 \n"
"    BL      sub_FF090770 \n"
"    BIC     R6, R4, R0 \n"
"    MOV     R0, #0x51 \n"
"    BL      sub_FF090770 \n"
"    BIC     R7, R4, R0 \n"
"    MOV     R0, #0x15 \n"
"    BL      sub_FF090770 \n"
"    CMP     R8, #0 \n"
"    BIC     R4, R4, R0 \n"
"    BEQ     loc_FF032140 \n"
"    ORR     R0, R5, R6 \n"
"    ORR     R0, R0, R7 \n"
"    ORRS    R0, R0, R4 \n"
"    BEQ     loc_FF032168 \n"

"loc_FF032140:\n"
"    BL      sub_FF03961C \n"
"    MOV     R2, R0 \n"
"    MOV     R3, #0 \n"
"    MOV     R1, R6 \n"
"    MOV     R0, R5 \n"
"    STR     R4, [SP, #4] \n"
"    STR     R7, [SP] \n"
//"  BL      _sub_FF092958 \n"  // Disable StartUpChecks
//"  BL      _sub_FF092954 \n"  // --> Nullsub call removed.
"    MOV     R0, #1 \n"

"loc_FF032168:\n"
"    LDMFD   SP!, {R2-R8,PC} \n"
);
}

/*************************************************************/
//** task_Startup_my @ 0xFF00B1E4 - 0xFF00B248, length=26
void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF0048A4 \n"
"    BL      sub_FF033304 \n"
"    BL      sub_FF03185C \n"
//"  BL      _sub_FF093060 \n"  // --> Nullsub call removed.
"    BL      sub_FF03988C \n"
//"  BL      _sub_FF039714 \n"  // load DISKBOOT.BIN
"    BL      sub_FF039A04 \n"
"    BL      sub_FF03A1DC \n"
"    BL      _SetZoomActuatorSpeedPercent \n"
"    BL      sub_FF0398C8 \n"
"    BL      sub_FF037F50 \n"
"    BL      sub_FF03A1E4 \n"
"    BL      CreateTask_spytask\n" // added
"    BL      taskcreatePhySw_my \n"  // --> Patched. Old value = 0xFF031F94.
"    BL      sub_FF036108 \n"
"    BL      sub_FF0DFF70 \n"
"    BL      sub_FF02F374 \n"
"    BL      sub_FF0311BC \n"
"    BL      sub_FF039448 \n"
"    BL      sub_FF031810 \n"
"    BL      sub_FF031158 \n"
//"  BL      _sub_FF0399FC \n"  // --> Nullsub call removed.
"    BL      sub_FF02FF50 \n"
"    BL      sub_FF03111C \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF0049E0 \n"
);
}

/*************************************************************/
//** taskcreatePhySw_my @ 0xFF031F94 - 0xFF031FE4, length=21
void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    LDR     R4, =0x1E28 \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF031FC8 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =mykbd_task \n"  // --> Patched. Old value = 0xFF031F60.
"    MOV     R2, #0x2000 \n"  // --> Patched. Old value = 0x800. stack size for new task_PhySw so we don't have to do stack switch
"    MOV     R1, #0x17 \n"
"    LDR     R0, =0xFF032260 /*'PhySw'*/ \n"
"    BL      sub_0068AF04 /*_CreateTaskStrictly*/ \n"
"    STR     R0, [R4, #4] \n"

"loc_FF031FC8:\n"
"    BL      sub_FF0CA8F4 \n"
"    BL      sub_FF0341C4 /*_IsFactoryMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF031FE4 \n"
"    LDR     R1, =0x40B70 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF0CA860 /*_OpLog.Start_FW*/ \n"

"loc_FF031FE4:\n"
"    LDMFD   SP!, {R3-R5,PC} \n"
);
}

/*************************************************************/
//** init_file_modules_task @ 0xFF0834F8 - 0xFF08352C, length=14
void __attribute__((naked,noinline)) init_file_modules_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF0CD1D8 \n"
"    LDR     R5, =0x5006 \n"
"    MOVS    R4, R0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, R5 \n"
"    BLNE    _PostLogicalEventToUI \n"
"    BL      sub_FF0CD20C \n"
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
//** task_TouchPanel_my @ 0xFF0974A4 - 0xFF0979D4, length=333
void __attribute__((naked,noinline)) task_TouchPanel_my() {
asm volatile (
"    STMFD   SP!, {R3-R9,LR} \n"
"    MOV     R0, #0 \n"
"    MOV     R5, R0 \n"
"    STR     R0, [SP] \n"
"    LDR     R1, =0x93D800 \n"
"    MOV     R6, #1 \n"
"    MOV     R0, #0x20 \n"
"    BL      sub_FF0907B8 \n"
"    LDR     R0, =0x61A8 \n"
"    BL      sub_FF095FB0 \n"
"    LDR     R1, =0xC0221000 \n"
"    MOV     R0, #0x21 \n"
"    STR     R0, [R1, #0x314] \n"
"    MOV     R0, #0x1C \n"
"    SUB     R1, R1, #0x1E000 \n"
"    STR     R0, [R1, #0x40] \n"
"    MOV     R3, #0 \n"
"    LDR     R2, =0xFF0960F0 \n"
"    MOV     R1, #0x55 \n"
"    MOV     R0, R3 \n"
"    BL      sub_0068A848 /*_RegisterInterruptHandler*/ \n"
"    LDR     R8, =0xF3FCF5 \n"
"    LDR     R4, =0x31E4 \n"
"    MOV     R7, #7 \n"

"loc_FF097504:\n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, R8 \n"
"    BL      sub_0068B9B0 /*_WaitForAnyEventFlag*/ \n"
"    CMP     R0, #0 \n"
"    LDRNE   R1, =0xA01 \n"
"    LDRNE   R0, =0xFF096194 /*'TouchPanelDriver_TMA340.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, SP \n"
"    BL      sub_0068BBC0 /*_GetEventFlagValue*/ \n"
"    CMP     R0, #0 \n"
"    LDRNE   R1, =0xA15 \n"
"    LDRNE   R0, =0xFF096194 /*'TouchPanelDriver_TMA340.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    BL      sub_FF098108 \n"
"    LDR     R0, [R4, #0x10] \n"
"    CMP     R0, #7 \n"
"    BEQ     loc_FF097558 \n"
"    BL      _CancelHPTimer \n"
"    STR     R7, [R4, #0x10] \n"

"loc_FF097558:\n"
"    LDR     R0, [SP] \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF097584 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #5 \n"
"    BL      sub_0068BB88 /*_ClearEventFlag*/ \n"
"    STR     R7, [R4, #0x14] \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x80000000 \n"
"    BL      sub_0068BB54 /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"

"loc_FF097584:\n"
"    LDR     R0, [SP] \n"
"    TST     R0, #0x400 \n"
"    BEQ     loc_FF0975D8 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x400 \n"
"    BL      sub_0068BB88 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF5BDE6C \n"
"    LDR     R0, [R0] \n"
"    BL      sub_FF0981D0 \n"
"    BL      sub_FF098108 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x14 \n"
"    BL      sub_0068BB88 /*_ClearEventFlag*/ \n"
"    BL      sub_FF096944 \n"
"    CMP     R0, #0 \n"
"    BLNE    sub_FF098310 \n"
"    BL      sub_FF09666C \n"
"    STR     R0, [R4, #0x44] \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x40000000 \n"
"    BL      sub_0068BB54 /*_SetEventFlag*/ \n"

"loc_FF0975D8:\n"
"    LDR     R0, [SP] \n"
"    TST     R0, #0x800 \n"
"    BEQ     loc_FF097604 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x800 \n"
"    BL      sub_0068BB88 /*_ClearEventFlag*/ \n"
"    BL      sub_FF09666C \n"
"    STR     R0, [R4, #0x44] \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x40000000 \n"
"    BL      sub_0068BB54 /*_SetEventFlag*/ \n"

"loc_FF097604:\n"
"    LDR     R0, [SP] \n"
"    TST     R0, #0x20 \n"
"    BEQ     loc_FF097634 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x20 \n"
"    BL      sub_0068BB88 /*_ClearEventFlag*/ \n"
"    LDR     R1, [R4, #0x48] \n"
"    MOV     R0, #3 \n"
"    BL      sub_FF097414 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x40000000 \n"
"    BL      sub_0068BB54 /*_SetEventFlag*/ \n"

"loc_FF097634:\n"
"    LDR     R0, [SP] \n"
"    TST     R0, #0x40 \n"
"    BEQ     loc_FF097664 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x40 \n"
"    BL      sub_0068BB88 /*_ClearEventFlag*/ \n"
"    LDR     R1, [R4, #0x48] \n"
"    MOV     R0, #5 \n"
"    BL      sub_FF097414 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x40000000 \n"
"    BL      sub_0068BB54 /*_SetEventFlag*/ \n"

"loc_FF097664:\n"
"    LDR     R0, [SP] \n"
"    TST     R0, #0x80 \n"
"    BEQ     loc_FF097694 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_0068BB88 /*_ClearEventFlag*/ \n"
"    LDR     R1, [R4, #0x48] \n"
"    MOV     R0, #6 \n"
"    BL      sub_FF097414 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x40000000 \n"
"    BL      sub_0068BB54 /*_SetEventFlag*/ \n"

"loc_FF097694:\n"
"    LDR     R0, [SP] \n"
"    TST     R0, #0x100000 \n"
"    BEQ     loc_FF0976C4 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x100000 \n"
"    BL      sub_0068BB88 /*_ClearEventFlag*/ \n"
"    MOV     R1, #0 \n"
"    MOV     R0, #7 \n"
"    BL      sub_FF097414 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x40000000 \n"
"    BL      sub_0068BB54 /*_SetEventFlag*/ \n"

"loc_FF0976C4:\n"
"    LDR     R0, [SP] \n"
"    TST     R0, #0x200000 \n"
"    BEQ     loc_FF0976F4 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x200000 \n"
"    BL      sub_0068BB88 /*_ClearEventFlag*/ \n"
"    MOV     R1, #0 \n"
"    MOV     R0, #8 \n"
"    BL      sub_FF097414 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x40000000 \n"
"    BL      sub_0068BB54 /*_SetEventFlag*/ \n"

"loc_FF0976F4:\n"
"    LDR     R0, [SP] \n"
"    TST     R0, #0x400000 \n"
"    BEQ     loc_FF097774 \n"
"    MOV     R1, #0x400000 \n"
"    B       loc_FF097754 \n"

// ask the assembler to put literals here - just like the original code does
// - needed when there are lot of functions dissassembled

" .ltorg \n"

"loc_FF097754:\n"
"    LDR     R0, [R4, #0x3C] \n"
"    BL      sub_0068BB88 /*_ClearEventFlag*/ \n"
"    MOV     R1, #0 \n"
"    MOV     R0, #9 \n"
"    BL      sub_FF097414 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x40000000 \n"
"    BL      sub_0068BB54 /*_SetEventFlag*/ \n"

"loc_FF097774:\n"
"    LDR     R0, [SP] \n"
"    TST     R0, #0x800000 \n"
"    BEQ     loc_FF0977A4 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x800000 \n"
"    BL      sub_0068BB88 /*_ClearEventFlag*/ \n"
"    MOV     R1, #0 \n"
"    MOV     R0, #0xA \n"
"    BL      sub_FF097414 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x40000000 \n"
"    BL      sub_0068BB54 /*_SetEventFlag*/ \n"

"loc_FF0977A4:\n"
"    LDR     R0, [SP] \n"
"    TST     R0, #0x14 \n"
"    BEQ     loc_FF097820 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x14 \n"
"    BL      sub_0068BB88 /*_ClearEventFlag*/ \n"
"    LDR     R0, [R4, #0x1C] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF0977D8 \n"
"    BL      sub_FF096944 \n"
"    CMP     R0, #0 \n"
"    BLNE    sub_FF098310 \n"
"    B       loc_FF097820 \n"

"loc_FF0977D8:\n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF097814 \n"
"    LDR     R0, [SP] \n"
"    LDRB    R1, [R4] \n"
"    AND     R0, R0, #0x10 \n"
"    ORRS    R0, R0, R1 \n"
"    BLNE    sub_FF096A18_my \n"  // --> Patched. Old value = 0xFF096A18. ref 1 - calls on each touch
"    LDRB    R0, [R4] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF097820 \n"
"    CMP     R5, #0 \n"
"    BEQ     loc_FF097820 \n"
"    BL      sub_FF0968F0 \n"
"    MOV     R5, #0 \n"
"    B       loc_FF097820 \n"

"loc_FF097814:\n"
"    LDR     R0, =0xFF096194 /*'TouchPanelDriver_TMA340.c'*/ \n"
"    MOV     R1, #0xA90 \n"
"    BL      _DebugAssert \n"

"loc_FF097820:\n"
"    LDR     R0, [SP] \n"
"    TST     R0, #0x1000 \n"
"    BEQ     loc_FF097854 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x1000 \n"
"    BL      sub_0068BB88 /*_ClearEventFlag*/ \n"
"    LDRB    R0, [R4] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R0, [R4, #0x1C] \n"
"    CMPEQ   R0, #1 \n"
"    MOVNE   R5, #1 \n"
"    BNE     loc_FF097854 \n"
"    BL      sub_FF0968F0 \n"

"loc_FF097854:\n"
"    LDR     R0, [SP] \n"
"    TST     R0, #0x2000 \n"
"    BEQ     loc_FF097874 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x2000 \n"
"    BL      sub_0068BB88 /*_ClearEventFlag*/ \n"
"    LDR     R0, [R4, #0x30] \n"
"    BL      sub_FF1C3AE0 \n"

"loc_FF097874:\n"
"    LDR     R0, [SP] \n"
"    TST     R0, #0x4000 \n"
"    BEQ     loc_FF0978B8 \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x4000 \n"
"    BL      sub_0068BB88 /*_ClearEventFlag*/ \n"
"    LDR     R0, [R4, #0x1C] \n"
"    CMP     R0, #1 \n"
"    LDRNE   R1, =0xAA9 \n"
"    LDRNE   R0, =0xFF096194 /*'TouchPanelDriver_TMA340.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    MOV     R6, #1 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF09687C \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x40000000 \n"
"    BL      sub_0068BB54 /*_SetEventFlag*/ \n"

"loc_FF0978B8:\n"
"    LDR     R0, [SP] \n"
"    TST     R0, #0x8000 \n"
"    BEQ     loc_FF0978FC \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x8000 \n"
"    BL      sub_0068BB88 /*_ClearEventFlag*/ \n"
"    LDR     R0, [R4, #0x1C] \n"
"    CMP     R0, #1 \n"
"    LDRNE   R1, =0xAB4 \n"
"    LDRNE   R0, =0xFF096194 /*'TouchPanelDriver_TMA340.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    MOV     R6, #0 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF09687C \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x40000000 \n"
"    BL      sub_0068BB54 /*_SetEventFlag*/ \n"

"loc_FF0978FC:\n"
"    LDR     R0, [SP] \n"
"    TST     R0, #0x10000 \n"
"    BEQ     loc_FF09793C \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x10000 \n"
"    BL      sub_0068BB88 /*_ClearEventFlag*/ \n"
"    LDR     R0, [R4, #0x1C] \n"
"    CMP     R0, #1 \n"
"    LDRNE   R1, =0xABF \n"
"    LDRNE   R0, =0xFF096194 /*'TouchPanelDriver_TMA340.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    MOV     R0, #7 \n"
"    BL      sub_FF09820C \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x40000000 \n"
"    BL      sub_0068BB54 /*_SetEventFlag*/ \n"

"loc_FF09793C:\n"
"    LDR     R0, [SP] \n"
"    TST     R0, #0x20000 \n"
"    BEQ     loc_FF09797C \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x20000 \n"
"    BL      sub_0068BB88 /*_ClearEventFlag*/ \n"
"    LDR     R0, [R4, #0x1C] \n"
"    CMP     R0, #1 \n"
"    LDRNE   R1, =0xAC7 \n"
"    LDRNE   R0, =0xFF096194 /*'TouchPanelDriver_TMA340.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF09820C \n"
"    LDR     R0, [R4, #0x3C] \n"
"    MOV     R1, #0x40000000 \n"
"    BL      sub_0068BB54 /*_SetEventFlag*/ \n"

"loc_FF09797C:\n"
"    LDR     R0, [R4, #0x1C] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF0979D0 \n"
"    LDRB    R0, [R4] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF0979A0 \n"
"    LDR     R0, =0x4E20 \n"
"    BL      sub_FF098084 \n"
"    B       loc_FF097504 \n"

"loc_FF0979A0:\n"
"    LDR     R0, [R4, #0x24] \n"
"    CMP     R0, #0xF \n"
"    BLE     loc_FF0979BC \n"
"    CMP     R6, #0 \n"
"    MOVNE   R0, #1 \n"
"    BLNE    sub_FF09687C \n"
"    B       loc_FF0979D0 \n"

"loc_FF0979BC:\n"
"    LDR     R0, =0x7A120 \n"
"    BL      sub_FF098084 \n"
"    LDR     R0, [R4, #0x24] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0x24] \n"

"loc_FF0979D0:\n"
"    BL      sub_FF0980F4 \n"
"    B       loc_FF097504 \n"
);
}

/*************************************************************/
//** sub_FF096A18_my @ 0xFF096A18 - 0xFF096D08, length=189
void __attribute__((naked,noinline)) sub_FF096A18_my() {
asm volatile (
"    STMFD   SP!, {R4-R11,LR} \n"
"    LDR     R7, =0xA0EF4 \n"
"    SUB     SP, SP, #0x34 \n"
"    MOV     R0, #0 \n"
"    STRH    R0, [R7] \n"
"    STRH    R0, [R7, #2] \n"
"    ADD     R1, SP, #0x10 \n"
"    STRH    R0, [R7, #4] \n"
"    BL      sub_FF09833C \n"
"    TST     R0, #1 \n"
"    BNE     loc_FF096D04 \n"
"    LDRB    R0, [SP, #0x13] \n"
"    TST     R0, #0x70 \n"
"    LDRNE   R1, =0x5D7 \n"
"    LDRNE   R0, =0xFF096194 /*'TouchPanelDriver_TMA340.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDRB    R0, [SP, #0x13] \n"
"    TST     R0, #4 \n"
"    MOVNE   R0, #0 \n"
"    BLNE    sub_FF09687C \n"
"    LDRB    R0, [SP, #0x12] \n"
"    TST     R0, #0x20 \n"
"    BEQ     loc_FF096A9C \n"
"    ADD     R1, SP, #0x10 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF09833C \n"
"    TST     R0, #1 \n"
"    BNE     loc_FF096D04 \n"
"    LDRB    R0, [SP, #0x13] \n"
"    TST     R0, #0x70 \n"
"    LDRNE   R1, =0x5EE \n"
"    LDRNE   R0, =0xFF096194 /*'TouchPanelDriver_TMA340.c'*/ \n"
"    BLNE    _DebugAssert \n"

"loc_FF096A9C:\n"
"    LDRB    R1, [SP, #0x12] \n"
"    LDRB    R0, [SP, #0x11] \n"
"    AND     R10, R1, #0xC0 \n"
"    LDR     R1, =0x31E4 \n"
"    AND     R5, R0, #0xF \n"
"    LDR     R1, [R1, #0x20] \n"
"    CMP     R1, R10 \n"
"    BNE     loc_FF096AD4 \n"
"    CMP     R5, #0 \n"
"    BEQ     loc_FF096ADC \n"
"    LDR     R1, =0x31E4 \n"
"    LDR     R1, [R1, #0x28] \n"
"    CMP     R1, #0 \n"
"    BEQ     loc_FF096D04 \n"

"loc_FF096AD4:\n"
"    CMP     R5, #0xF \n"
"    BEQ     loc_FF096D04 \n"

"loc_FF096ADC:\n"
"    MOV     R0, R0, LSL#25 \n"
"    MOVS    R0, R0, LSR#29 \n"
"    BNE     loc_FF096D04 \n"
"    CMP     R5, #0 \n"
"    STRH    R0, [R7] \n"
"    BEQ     loc_FF096CE4 \n"
"    LDRB    R0, [SP, #0x26] \n"
"    LDRB    R1, [SP, #0x1B] \n"
"    LDR     R9, =0x31E4 \n"
"    MOV     R4, #0 \n"
"    ORR     R0, R0, R1, LSL#8 \n"
"    MOV     R11, #1 \n"
"    STR     R0, [SP, #0x30] \n"

"loc_FF096B10:\n"
"    CMP     R4, R5 \n"
"    BGE     loc_FF096BDC \n"
"    CMP     R4, #0 \n"
"    LDREQB  R0, [SP, #0x17] \n"
"    LDREQB  R1, [SP, #0x10] \n"
"    ORREQ   R8, R0, R1, LSL#8 \n"
"    LDREQB  R0, [SP, #0x15] \n"
"    LDREQB  R1, [SP, #0x16] \n"
"    BEQ     loc_FF096B78 \n"
"    CMP     R4, #1 \n"
"    LDREQB  R0, [SP, #0x19] \n"
"    LDREQB  R1, [SP, #0x1A] \n"
"    ORREQ   R8, R0, R1, LSL#8 \n"
"    LDREQB  R0, [SP, #0x1F] \n"
"    LDREQB  R1, [SP, #0x18] \n"
"    BEQ     loc_FF096B78 \n"
"    CMP     R4, #2 \n"
"    LDRNEB  R0, [SP, #0x24] \n"
"    LDRNEB  R1, [SP, #0x25] \n"
"    LDREQB  R0, [SP, #0x22] \n"
"    LDREQB  R1, [SP, #0x23] \n"
"    ORR     R8, R0, R1, LSL#8 \n"
"    LDRNEB  R0, [SP, #0x29] \n"
"    LDRNEB  R1, [SP, #0x2A] \n"
"    LDREQB  R0, [SP, #0x20] \n"
"    LDREQB  R1, [SP, #0x21] \n"

"loc_FF096B78:\n"
"    ORR     R6, R0, R1, LSL#8 \n"
"    LDR     R1, [SP, #0x30] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF09823C \n"
"    STR     R0, [SP, #0x2C] \n"
"    MOV     R0, R6, LSL#16 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, R0, ASR#16 \n"
"    STMEA   SP, {R0,R1,R8} \n"
"    MOV     R3, R8, LSL#16 \n"
"    LDR     R2, [SP, #0x2C] \n"
"    MOV     R3, R3, ASR#16 \n"
"    MOV     R0, R4 \n"
"    STR     R6, [SP, #0xC] \n"
"    BL      sub_FF096010 \n"
"    LDRH    R0, [R7, #2] \n"
"    ADD     R4, R4, #1 \n"
"    ADD     R0, R0, #1 \n"

// blocking this causes touch task to process touches but not share with the UI - MAGIC
"  push   {r1} \n"
"  ldr    r1,=kbd_blocked \n"
"  ldr    r1,[r1] \n"
"  cmp    r1,#0 \n"
"  movne  r0,#0 \n"
"  pop    {R1} \n"

"    STRH    R0, [R7, #2] \n"
"    LDR     R0, [SP, #0x2C] \n"
"    LDRH    R1, [R9, #2] \n"
"    ORR     R0, R1, R11, LSL R0 \n"
"    CMP     R4, #2 \n"
"    STRH    R0, [R9, #2] \n"
"    BLT     loc_FF096B10 \n"

"loc_FF096BDC:\n"
"    LDR     R0, =0x31E4 \n"
"    MOV     R9, #0 \n"
"    LDRB    R8, [R0] \n"
"    LDRH    R0, [R0, #4] \n"
"    MOV     R6, R9 \n"
"    STR     R0, [SP, #0xC] \n"

"loc_FF096BF4:\n"
"    CMP     R6, R8 \n"
"    BGE     loc_FF096C50 \n"
"    LDR     R1, [SP, #0xC] \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF09823C \n"
"    MOV     R11, R0 \n"
"    MOV     R4, #0 \n"

"loc_FF096C10:\n"
"    CMP     R4, R5 \n"
"    BGE     loc_FF096C44 \n"
"    LDR     R1, [SP, #0x30] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF09823C \n"
"    CMP     R11, R0 \n"
"    MOVEQ   R0, #1 \n"
"    ORREQ   R0, R9, R0, LSL R6 \n"
"    ANDEQ   R9, R0, #0xFF \n"
"    BEQ     loc_FF096C44 \n"
"    ADD     R4, R4, #1 \n"
"    CMP     R4, #2 \n"
"    BLT     loc_FF096C10 \n"

"loc_FF096C44:\n"
"    ADD     R6, R6, #1 \n"
"    CMP     R6, #2 \n"
"    BLT     loc_FF096BF4 \n"

"loc_FF096C50:\n"
"    LDR     R6, =0x31E4 \n"
"    MOV     R4, #0 \n"

"loc_FF096C58:\n"
"    LDRB    R0, [R6] \n"
"    CMP     R4, R0 \n"
"    BGE     loc_FF096CBC \n"
"    MOV     R8, #1 \n"
"    TST     R9, R8, LSL R4 \n"
"    BNE     loc_FF096CBC \n"
"    LDRH    R1, [R6, #4] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF09823C \n"
"    MOV     R3, #0 \n"
"    MOV     R11, R0 \n"
"    STR     R3, [SP] \n"
"    STR     R3, [SP, #4] \n"
"    STR     R3, [SP, #8] \n"
"    STR     R3, [SP, #0xC] \n"
"    LDRH    R0, [R7, #4] \n"
"    MOV     R2, R11 \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF096010 \n"
"    LDRH    R0, [R7, #4] \n"
"    ADD     R0, R0, #1 \n"
"    STRH    R0, [R7, #4] \n"
"    LDRH    R1, [R6, #2] \n"
"    BIC     R0, R1, R8, LSL R11 \n"
"    STRH    R0, [R6, #2] \n"

"loc_FF096CBC:\n"
"    ADD     R4, R4, #1 \n"
"    CMP     R4, #2 \n"
"    BLT     loc_FF096C58 \n"
"    LDR     R0, [SP, #0x30] \n"
"    STRH    R0, [R6, #4] \n"
"    STRB    R5, [R6] \n"
"    MOV     R0, #0 \n"
"    STR     R10, [R6, #0x20]! \n"
"    STR     R0, [R6, #4] \n"
"    B       loc_FF096CE8 \n"

"loc_FF096CE4:\n"
"    BL      sub_FF098278 \n"

"loc_FF096CE8:\n"
"    LDR     R0, =0x31E4 \n"
"    LDR     R0, [R0, #0x28] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, =0xA0EF4 \n"
"    BLNE    sub_FF1C28A4 \n"
"    LDR     R0, =0xA0EF4 \n"
"    BL      sub_FF1C3A90 \n"

"loc_FF096D04:\n"
"    ADD     SP, SP, #0x34 \n"
"    LDMFD   SP!, {R4-R11,PC} \n"
);
}
