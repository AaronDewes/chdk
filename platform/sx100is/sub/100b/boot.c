/*
 * boot.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

const char * const new_sa = &_end;

void JogDial_task_my(void);

/*----------------------------------------------------------------------
    CreateTask_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask()
{
    _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
}

void taskCreateHook(int *p) {
    p-=16;
    if (p[0]==(int)0xffc4e2ac)  p[0]=(int)capt_seq_task;
    if (p[0]==(int)0xffc98ee4)  p[0]=(int)exp_drv_task;
    if (p[0]==(int)0xffc4ae14)  p[0]=(int)movie_record_task;
    if (p[0]==(int)0xffdda764)  p[0]=(int)filewritetask;
    if (p[0]==(int)0xffc63558)  p[0]=(int)init_file_modules_task;
    if (p[0]==(int)0xffc37ff8)  p[0]=(int)JogDial_task_my;
}

void boot()
{
    long *canon_data_src = (void*)0xFFEBE418; 
    long *canon_data_dst = (void*)0x1900;
    long canon_data_len = 0xf6c4 - 0x1900;		// data_end - data_start
    long *canon_bss_start = (void*)0xf6c4;		// just after data
    long canon_bss_len = 0x9F498 - 0xf6c4;
    

    long i;


    // Enable CPU caches and MPU
    asm volatile (
    "MRC     p15, 0, R0,c1,c0\n"
    "ORR     R0, R0, #0x1000\n"
    "ORR     R0, R0, #4\n"
    "ORR     R0, R0, #1\n"
    "MCR     p15, 0, R0,c1,c0\n"
    :::"r0");

    for(i=0;i<canon_data_len/4;i++)
    canon_data_dst[i]=canon_data_src[i];

    for(i=0;i<canon_bss_len/4;i++)
    canon_bss_start[i]=0;

    // jump to init-sequence that follows the data-copy-routine
    asm volatile ("B      sub_FFC001A4_my\n");
};


/*************************************************************/
//** sub_FFC001A4_my @ 0xFFC001A4 - 0xFFC0020C, length=27
void __attribute__((naked,noinline)) sub_FFC001A4_my() {
    //http://chdk.setepontos.com/index.php/topic,4194.0.html
    *(int*)0x1930=(int)taskCreateHook;
    *(int*)0x1934=(int)taskCreateHook;

    // replacement of sub_FFC377B0 for correct power-on.
    //(short press = playback mode, long press = record mode)
    *(int*)(0x2574+0x4)= (*(int*)0xC02200B8) & 1 ? 0x100000 : 0x200000;
    
asm volatile (
"    LDR     R0, =0xFFC0021C \n"
"    MOV     R1, #0 \n"
"    LDR     R3, =0xFFC00254 \n"

"loc_FFC001B0:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FFC001B0 \n"
"    LDR     R0, =0xFFC00254 \n"
"    MOV     R1, #0x4B0 \n"
"    LDR     R3, =0xFFC00468 \n"

"loc_FFC001CC:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FFC001CC \n"
"    MOV     R0, #0xD2 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    MOV     R0, #0xD3 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    LDR     R0, =0x6C4 \n"
"    LDR     R2, =0xEEEEEEEE \n"
"    MOV     R3, #0x1000 \n"

"loc_FFC00200:\n"
"    CMP     R0, R3 \n"
"    STRCC   R2, [R0], #4 \n"
"    BCC     loc_FFC00200 \n"
"    BL      sub_FFC00FB8_my \n"  // --> Patched. Old value = 0xFFC00FB8.
);
}

/*************************************************************/
//** sub_FFC00FB8_my @ 0xFFC00FB8 - 0xFFC01058, length=41
void __attribute__((naked,noinline)) sub_FFC00FB8_my() {
asm volatile (
"    STR     LR, [SP, #-4]! \n"
"    SUB     SP, SP, #0x74 \n"
"    MOV     R0, SP \n"
"    MOV     R1, #0x74 \n"
"    BL      sub_FFE56D34 \n"
"    MOV     R0, #0x53000 \n"
"    STR     R0, [SP, #4] \n"

#if defined(CHDK_NOT_IN_CANON_HEAP) // use original heap offset if CHDK is loaded in high memory
"    LDR     R0, =0x9F498 \n"
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      //
#endif

"    LDR     R2, =0x2ABC00 \n"
"    LDR     R1, =0x2A4968 \n"
"    STR     R0, [SP, #8] \n"
"    SUB     R0, R1, R0 \n"
"    ADD     R3, SP, #0xC \n"
"    STR     R2, [SP] \n"
"    STMIA   R3, {R0-R2} \n"
"    MOV     R0, #0x22 \n"
"    STR     R0, [SP, #0x18] \n"
"    MOV     R0, #0x68 \n"
"    STR     R0, [SP, #0x1C] \n"
"    LDR     R0, =0x19B \n"
"    MOV     R1, #0x64 \n"
"    STRD    R0, [SP, #0x20] \n"
"    MOV     R0, #0x78 \n"
"    STRD    R0, [SP, #0x28] \n"
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
"    LDR     R1, =uHwSetup_my \n"  // --> Patched. Old value = 0xFFC04DBC.
"    MOV     R0, SP \n"
"    MOV     R2, #0 \n"
"    BL      sub_FFC02D70 \n"
"    ADD     SP, SP, #0x74 \n"
"    LDR     PC, [SP], #4 \n"
);
}

/*************************************************************/
//** uHwSetup_my @ 0xFFC04DBC - 0xFFC04E30, length=30
void __attribute__((naked,noinline)) uHwSetup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FFC0095C \n"
"    BL      sub_FFC09A10 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFFC04ED0 /*'dmSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FFC049E0 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFFC04ED8 /*'termDriverInit'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFFC04EE8 /*'/_term'*/ \n"
"    BL      sub_FFC04ACC \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFFC04EF0 /*'termDeviceCreate'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFFC04EE8 /*'/_term'*/ \n"
"    BL      sub_FFC0357C \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFFC04F04 /*'stdioSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FFC09598 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFFC04F10 /*'stdlibSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FFC014D0 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFFC04F1C /*'armlib_setup'*/ \n"
"    BLLT    _err_init_task \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       CreateTask_Startup_my \n"  // --> Patched. Old value = 0xFFC0DCD4.
);
}

/*************************************************************/
//** CreateTask_Startup_my @ 0xFFC0DCD4 - 0xFFC0DD44, length=29
void __attribute__((naked,noinline)) CreateTask_Startup_my() {
asm volatile (
"    STMFD   SP!, {R3,LR} \n"
//"  BL      _sub_FFC12E30 \n"  // --> Nullsub call removed.
"    BL      sub_FFC1BFA4 \n"
"    CMP     R0, #0 \n"
"    LDREQ   R2, =0xC0220000 \n"
"    LDREQ   R0, [R2, #0xB8] \n"
"    LDREQ   R1, [R2, #0xDC] \n"
"    ORREQ   R0, R0, R1 \n"
"    TSTEQ   R0, #1 \n"
"    BNE     loc_FFC0DD08 \n"
"    MOV     R0, #0x44 \n"
"    STR     R0, [R2, #0x4C] \n"

"loc_FFC0DD04:\n"
"    B       loc_FFC0DD04 \n"

"loc_FFC0DD08:\n"
//"  BL      _sub_FFC377B0 \n"  // Removed for correct power-on
//"  BL      _sub_FFC12E34 \n"  // --> Nullsub call removed.
"    BL      sub_FFC19B30 \n"
"    MOV     R1, #0x300000 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FFC19D78 \n"
"    BL      sub_FFC19D24 /*_EnableDispatch*/ \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =task_Startup_my \n"  // --> Patched. Old value = 0xFFC0DC78.
"    MOV     R2, #0 \n"
"    MOV     R1, #0x19 \n"
"    LDR     R0, =0xFFC0DD4C /*'Startup'*/ \n"
"    BL      _CreateTask \n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R12,PC} \n"
);
}

/*************************************************************/
//** task_Startup_my @ 0xFFC0DC78 - 0xFFC0DCD0, length=23
void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FFC051CC \n"
"    BL      sub_FFC13FC8 \n"
"    BL      sub_FFC10EC8 \n"
//"  BL      _sub_FFC37F3C \n"  // --> Nullsub call removed.
"    BL      sub_FFC1C184 \n"
//"  BL      _sub_FFC1C06C \n"  // load DISKBOOT.BIN
"    BL      CreateTask_spytask\n" // added
"    BL      sub_FFC5F934 \n"
"    BL      sub_FFC1C1D4 \n"
"    BL      sub_FFC19074 \n"
"    BL      sub_FFC1C350 \n"
"    BL      taskcreatePhySw_my \n"  // --> Patched. Old value = 0xFFC12DD0. Checks buttons and acts accordingly
"    BL      sub_FFC15CAC \n"
"    BL      sub_FFC1C368 \n"
//"  BL      _sub_FFC10BBC \n"  // --> Nullsub call removed.
"    BL      sub_FFC12160 \n"
"    BL      sub_FFC1BD50 \n"
"    BL      sub_FFC128FC \n"
"    BL      sub_FFC1206C \n"
"    BL      sub_FFC1CDE0 \n"
"    BL      sub_FFC12028 \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FFC05088 \n"
);
}

/*************************************************************/
//** taskcreatePhySw_my @ 0xFFC12DD0 - 0xFFC12E08, length=15
void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    LDR     R4, =0x1C98 \n"
"    LDR     R0, [R4, #0x10] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FFC12E04 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =mykbd_task \n"  // --> Patched. Old value = 0xFFC12D9C.
"    MOV     R2, #0x2000 \n"  // --> Patched. Old value = 0x800. stack size for new task_PhySw so we don't have to do stack switch
"    MOV     R1, #0x17 \n"
"    LDR     R0, =0xFFC12FC8 /*'PhySw'*/ \n"
"    BL      sub_FFC0BE90 /*_CreateTaskStrictly*/ \n"
"    STR     R0, [R4, #0x10] \n"

"loc_FFC12E04:\n"
"    LDMFD   SP!, {R3-R5,LR} \n"
"    B       _taskcreate_jogDial \n"
);
}

/*************************************************************/
//** init_file_modules_task @ 0xFFC63558 - 0xFFC6358C, length=14
void __attribute__((naked,noinline)) init_file_modules_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FFC5C51C \n"
"    LDR     R5, =0x5006 \n"
"    MOVS    R4, R0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, R5 \n"
"    BLNE    _PostLogicalEventToUI \n"
"    BL      sub_FFC5C548_my \n"  // --> Patched. Old value = 0xFFC5C548.
"    BL      core_spytask_can_start\n"  // CHDK: Set "it's-safe-to-start" flag for spytask
"    CMP     R4, #0 \n"
"    MOVEQ   R0, R5 \n"
"    LDMEQFD SP!, {R4-R6,LR} \n"
"    MOVEQ   R1, #0 \n"
"    BEQ     _PostLogicalEventToUI \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** sub_FFC5C548_my @ 0xFFC5C548 - 0xFFC5C580, length=15
void __attribute__((naked,noinline)) sub_FFC5C548_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FFC40274_my \n"  // --> Patched. Old value = 0xFFC40274.
"    LDR     R4, =0x5908 \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FFC5C578 \n"
"    BL      sub_FFC6BB2C \n"
"    BL      sub_FFCE6CF0 \n"
"    BL      sub_FFC6BB2C \n"
"    BL      sub_FFCF07D0 \n"
"    BL      sub_FFC6BB3C \n"
"    BL      sub_FFCE6D90 \n"

"loc_FFC5C578:\n"
"    MOV     R0, #1 \n"
"    STR     R0, [R4] \n"
"    LDMFD   SP!, {R4,PC} \n"
);
}

/*************************************************************/
//** sub_FFC40274_my @ 0xFFC40274 - 0xFFC4030C, length=39
void __attribute__((naked,noinline)) sub_FFC40274_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    MOV     R6, #0 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FFC3FE44 \n"
"    LDR     R4, =0x11DE0 \n"
"    MOV     R5, #0 \n"
"    LDR     R0, [R4, #0x38] \n"
"    BL      sub_FFC4080C \n"
"    CMP     R0, #0 \n"
"    LDREQ   R0, =0x2BB4 \n"
"    STREQ   R5, [R0, #0xC] \n"
"    STREQ   R5, [R0, #0x10] \n"
"    STREQ   R5, [R0, #0x14] \n"
"    MOV     R0, R6 \n"
"    BL      sub_FFC3FE84 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FFC400B0_my \n"  // --> Patched. Old value = 0xFFC400B0.
"    MOV     R5, R0 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FFC4011C \n"
"    LDR     R1, [R4, #0x3C] \n"
"    AND     R2, R5, R0 \n"
"    CMP     R1, #0 \n"
"    MOV     R0, #0 \n"
"    MOVEQ   R0, #0x80000001 \n"
"    BEQ     loc_FFC40308 \n"
"    LDR     R3, [R4, #0x2C] \n"
"    CMP     R3, #2 \n"
"    MOVEQ   R0, #4 \n"
"    CMP     R1, #5 \n"
"    ORRNE   R0, R0, #1 \n"
"    BICEQ   R0, R0, #1 \n"
"    CMP     R2, #0 \n"
"    BICEQ   R0, R0, #2 \n"
"    ORREQ   R0, R0, #0x80000000 \n"
"    BICNE   R0, R0, #0x80000000 \n"
"    ORRNE   R0, R0, #2 \n"

"loc_FFC40308:\n"
"    STR     R0, [R4, #0x40] \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** sub_FFC400B0_my @ 0xFFC400B0 - 0xFFC40118, length=27
void __attribute__((naked,noinline)) sub_FFC400B0_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x2BB4 \n"
"    MOV     R6, R0 \n"
"    LDR     R0, [R5, #0x10] \n"
"    CMP     R0, #0 \n"
"    MOVNE   R0, #1 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    MOV     R0, #0x17 \n"
"    MUL     R1, R0, R6 \n"
"    LDR     R0, =0x11DE0 \n"
"    ADD     R4, R0, R1, LSL#2 \n"
"    LDR     R0, [R4, #0x38] \n"
"    MOV     R1, R6 \n"
"    BL      sub_FFC3FF48_my \n"  // --> Patched. Old value = 0xFFC3FF48.
"    CMP     R0, #0 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"
"    LDR     R0, [R4, #0x38] \n"
"    MOV     R1, R6 \n"
"    BL      sub_FFC40924 \n"
"    CMP     R0, #0 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"
"    MOV     R0, R6 \n"
"    BL      sub_FFC3FA64 \n"
"    CMP     R0, #0 \n"
"    MOVNE   R1, #1 \n"
"    STRNE   R1, [R5, #0x10] \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** sub_FFC3FF48_my @ 0xFFC3FF48 - 0xFFC400AC, length=90
void __attribute__((naked,noinline)) sub_FFC3FF48_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    MOV     R8, R0 \n"
"    MOV     R0, #0x17 \n"
"    MUL     R1, R0, R1 \n"
"    LDR     R0, =0x11DE0 \n"
"    MOV     R6, #0 \n"
"    ADD     R7, R0, R1, LSL#2 \n"
"    LDR     R0, [R7, #0x3C] \n"
"    MOV     R5, #0 \n"
"    CMP     R0, #6 \n"
"    ADDLS   PC, PC, R0, LSL#2 \n"
"    B       loc_FFC40094 \n"
"    B       loc_FFC3FFAC \n"
"    B       loc_FFC3FF94 \n"
"    B       loc_FFC3FF94 \n"
"    B       loc_FFC3FF94 \n"
"    B       loc_FFC3FF94 \n"
"    B       loc_FFC4008C \n"
"    B       loc_FFC3FF94 \n"

"loc_FFC3FF94:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0x200 \n"
"    MOV     R0, #3 \n"
"    BL      _exmem_ualloc \n"
"    MOVS    R4, R0 \n"
"    BNE     loc_FFC3FFB4 \n"

"loc_FFC3FFAC:\n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R4-R8,PC} \n"

"loc_FFC3FFB4:\n"
"    LDR     R12, [R7, #0x4C] \n"
"    MOV     R3, R4 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, R8 \n"
"    BLX     R12 \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FFC3FFE0 \n"
"    MOV     R0, #3 \n"
"    BL      _exmem_ufree \n"
"    B       loc_FFC3FFAC \n"

"loc_FFC3FFE0:\n"
"    MOV     R0, R8 \n"
"    BL      sub_FFCFF884 \n"

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
//"  LDRB    LR, [R4, #0x1FF] \n"
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
//"  LDRB    R12, [R4, #0x1FE] \n"  // Replaced, see below
//mod start
"    LDRB    R12, [LR,#0x1FE]\n"           // New! First MBR signature byte (0x55)
"    LDRB    LR, [LR,#0x1FF]\n"            //      Last MBR signature byte (0xAA)
//mod end
"    MOV     R4, #0 \n"
"    BNE     loc_FFC40068 \n"
"    CMP     R0, R1 \n"
"    BCC     loc_FFC40068 \n"
"    ADD     R2, R1, R3 \n"
"    CMP     R2, R0 \n"
"    CMPLS   R12, #0x55 \n"
"    CMPEQ   LR, #0xAA \n"
"    MOVEQ   R6, R1 \n"
"    MOVEQ   R5, R3 \n"
"    MOVEQ   R4, #1 \n"

"loc_FFC40068:\n"
"    MOV     R0, #3 \n"
"    BL      _exmem_ufree \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FFC400A0 \n"
"    MOV     R6, #0 \n"
"    MOV     R0, R8 \n"
"    BL      sub_FFCFF884 \n"
"    MOV     R5, R0 \n"
"    B       loc_FFC400A0 \n"

"loc_FFC4008C:\n"
"    MOV     R5, #0x40 \n"
"    B       loc_FFC400A0 \n"

"loc_FFC40094:\n"
"    LDR     R1, =0x365 \n"
"    LDR     R0, =0xFFC3FF3C /*'Mounter.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FFC400A0:\n"
"    STR     R6, [R7, #0x44]! \n"
"    MOV     R0, #1 \n"
"    STR     R5, [R7, #4] \n"
"    LDMFD   SP!, {R4-R8,PC} \n"
);
}

/*************************************************************/
//** JogDial_task_my @ 0xFFC37FF8 - 0xFFC380F0, length=63
void __attribute__((naked,noinline)) JogDial_task_my() {
asm volatile (
"    STMFD   SP!, {R3-R11,LR} \n"
"    BL      sub_FFC38274 \n"
"    LDR     R11, =0x80000B01 \n"
"    LDR     R8, =0xFFE5FA70 \n"
"    LDR     R7, =0xC0240000 \n"
"    LDR     R6, =0x2590 \n"
"    MOV     R9, #1 \n"
"    MOV     R10, #0 \n"

"loc_FFC38018:\n"
"    LDR     R3, =0x191 \n"
"    LDR     R0, [R6, #0x10] \n"
"    LDR     R2, =0xFFC38244 /*'JogDial.c'*/ \n"
"    MOV     R1, #0 \n"
"    BL      sub_FFC0BF78 /*_TakeSemaphoreStrictly*/ \n"
"    MOV     R0, #0x28 \n"
"    BL      _SleepTask \n"
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
"    LDR     R0, [R7, #0x304] \n"
"    MOV     R0, R0, ASR#16 \n"
"    STRH    R0, [R6] \n"
"    LDRSH   R2, [R6, #2] \n"
"    SUB     R1, R0, R2 \n"
"    CMP     R1, #0 \n"
"    BEQ     loc_FFC380DC \n"
"    MOV     R5, R1 \n"
"    RSBLT   R5, R5, #0 \n"
"    MOVLE   R4, #0 \n"
"    MOVGT   R4, #1 \n"
"    CMP     R5, #0xFF \n"
"    BLS     loc_FFC38090 \n"
"    CMP     R1, #0 \n"
"    RSBLE   R1, R2, #0xFF \n"
"    ADDLE   R1, R1, #0x7F00 \n"
"    ADDLE   R0, R1, R0 \n"
"    RSBGT   R0, R0, #0xFF \n"
"    ADDGT   R0, R0, #0x7F00 \n"
"    ADDGT   R0, R0, R2 \n"
"    ADD     R5, R0, #0x8000 \n"
"    ADD     R5, R5, #1 \n"
"    EOR     R4, R4, #1 \n"

"loc_FFC38090:\n"
"    LDR     R0, [R6, #0x18] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFC380D4 \n"
"    LDR     R0, [R6, #0x20] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFC380BC \n"
"    LDR     R1, [R8, R4, LSL#2] \n"
"    CMP     R1, R0 \n"
"    BEQ     loc_FFC380C4 \n"
"    LDR     R0, =0xB01 \n"
"    BL      sub_FFC5F3D4 \n"

"loc_FFC380BC:\n"
"    MOV     R0, R11 \n"
"    BL      sub_FFC5F3D4 \n"

"loc_FFC380C4:\n"
"    LDR     R0, [R8, R4, LSL#2] \n"
"    MOV     R1, R5 \n"
"    STR     R0, [R6, #0x20] \n"
"    BL      sub_FFC5F330 \n"

"loc_FFC380D4:\n"
"    LDRH    R0, [R6] \n"
"    STRH    R0, [R6, #2] \n"

"loc_FFC380DC:\n"
"    STR     R10, [R7, #0x300] \n"
"    STR     R9, [R7, #0x308] \n"
"    LDR     R0, [R6, #0x14] \n"
"    CMP     R0, #0 \n"
"    BLNE    _SleepTask \n"
"    B       loc_FFC38018 \n"
);
}
