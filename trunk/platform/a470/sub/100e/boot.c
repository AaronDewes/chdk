/*
 * boot.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

const char * const new_sa = &_end;

/* Ours stuff */
extern long wrs_kernel_bss_start;
extern long wrs_kernel_bss_end;

/*----------------------------------------------------------------------
    CreateTask_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask()
{
    _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
}

void taskCreateHook(int *p) {
    p-=16;
    if (p[0]==0xffc488a4)  p[0]=(int)capt_seq_task;
    if (p[0]==0xffc900b8)  p[0]=(int)exp_drv_task;
    if (p[0]==0xffdc0ea8)  p[0]=(int)filewritetask;
    if (p[0]==0xffc5ebf8)  p[0]=(int)init_file_modules_task;
    if (p[0]==0xffc453d8)  p[0]=(int)movie_record_task;
}

void boot()
{
    long *canon_data_src = (void*)0xFFEAB38C; //found with "romdata start" string
    long *canon_data_dst = (void*)0x1900;
    long canon_data_len = 0xEBA8 - 0x1900; // data_end - data_start
    long *canon_bss_start = (void*)0xEBA8; // just after data
    long canon_bss_len = 0xA5718 - 0xEBA8; // found using heapstart

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

   *(int*)0x1930=(int)taskCreateHook;
   *(int*)0x1934=(int)taskCreateHook;

    // jump to init-sequence that follows the data-copy-routine
    asm volatile ("B      sub_FFC001A4_my\n");
};


/*************************************************************/
//** sub_FFC001A4_my @ 0xFFC001A4 - 0xFFC0020C, length=27
void __attribute__((naked,noinline)) sub_FFC001A4_my() {
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
"    BL      sub_FFC00FA0_my \n"  // --> Patched. Old value = 0xFFC00FA0.
);
}

/*************************************************************/
//** sub_FFC00FA0_my @ 0xFFC00FA0 - 0xFFC01040, length=41
void __attribute__((naked,noinline)) sub_FFC00FA0_my() {
asm volatile (
"    STR     LR, [SP, #-4]! \n"
"    SUB     SP, SP, #0x74 \n"
"    MOV     R0, SP \n"
"    MOV     R1, #0x74 \n"
"    BL      sub_FFE4E264 \n"
"    MOV     R0, #0x53000 \n"
"    STR     R0, [SP, #4] \n"

#if defined(CHDK_NOT_IN_CANON_HEAP) // use original heap offset if CHDK is loaded in high memory
"    LDR     R0, =0xA5718 \n"
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      //
#endif

"    LDR     R2, =0x279C00 \n"
"    LDR     R1, =0x272968 \n"
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
"    LDR     R1, =uHwSetup_my \n"  // --> Patched. Old value = 0xFFC04DA4.
"    MOV     R0, SP \n"
"    MOV     R2, #0 \n"
"    BL      sub_FFC02D58 \n"
"    ADD     SP, SP, #0x74 \n"
"    LDR     PC, [SP], #4 \n"
);
}

/*************************************************************/
//** uHwSetup_my @ 0xFFC04DA4 - 0xFFC04E18, length=30
void __attribute__((naked,noinline)) uHwSetup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FFC0094C \n"
"    BL      sub_FFC0972C \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFFC04EB8 /*'dmSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FFC049C8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFFC04EC0 /*'termDriverInit'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFFC04ED0 /*'/_term'*/ \n"
"    BL      sub_FFC04AB4 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFFC04ED8 /*'termDeviceCreate'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFFC04ED0 /*'/_term'*/ \n"
"    BL      sub_FFC03564 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFFC04EEC /*'stdioSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FFC092B4 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFFC04EF8 /*'stdlibSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FFC014B8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFFC04F04 /*'armlib_setup'*/ \n"
"    BLLT    _err_init_task \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       CreateTask_Startup_my \n"  // --> Patched. Old value = 0xFFC0CD84.
);
}

/*************************************************************/
//** CreateTask_Startup_my @ 0xFFC0CD84 - 0xFFC0CDF0, length=28
void __attribute__((naked,noinline)) CreateTask_Startup_my() {
asm volatile (
"    STMFD   SP!, {R3,LR} \n"
//"  BL      _sub_FFC306EC \n"  // --> Nullsub call removed.
"    BL      sub_FFC1978C \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FFC0CDB4 \n"
"    BL      sub_FFC306DC \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FFC0CDB4 \n"
"    LDR     R1, =0xC0220000 \n"
"    MOV     R0, #0x44 \n"
"    STR     R0, [R1, #0xA0] \n"

"loc_FFC0CDB0:\n"
"    B       loc_FFC0CDB0 \n"

"loc_FFC0CDB4:\n"
//"  BL      _sub_FFC306F4 \n"  // --> Nullsub call removed.
//"  BL      _sub_FFC306F0 \n"  // --> Nullsub call removed.
"    BL      sub_FFC17B14 \n"
"    LDR     R1, =0x2CE000 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FFC17D5C \n"
"    BL      sub_FFC17D08 /*_EnableDispatch*/ \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =task_Startup_my \n"  // --> Patched. Old value = 0xFFC0CD28.
"    MOV     R2, #0 \n"
"    MOV     R1, #0x19 \n"
"    LDR     R0, =0xFFC0CDFC /*'Startup'*/ \n"
"    BL      _CreateTask \n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R12,PC} \n"
);
}

/*************************************************************/
//** task_Startup_my @ 0xFFC0CD28 - 0xFFC0CD7C, length=22
void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FFC051BC \n"
"    BL      sub_FFC12B1C \n"
"    BL      sub_FFC0FDFC \n"
//"  BL      _sub_FFC30B5C \n"  // --> Nullsub call removed.
"    BL      sub_FFC19994 \n"
//"  BL      _sub_FFC19854 \n"  // load DISKBOOT.BIN
"    BL      CreateTask_spytask\n" // added
"    BL      sub_FFC5B798 \n"
"    BL      sub_FFC199E4 \n"
"    BL      sub_FFC17054 \n"
"    BL      sub_FFC19B4C \n"
"    BL      taskcreatePhySw_my \n"  // --> Patched. Old value = 0xFFC118D8. Checks buttons and acts accordingly
"    BL      sub_FFC14A18 \n"
"    BL      sub_FFC19B64 \n"
//"  BL      _sub_FFC0FBD8 \n"  // --> Nullsub call removed.
"    BL      sub_FFC10DAC \n"
"    BL      sub_FFC19554 \n"
"    BL      sub_FFC11408 \n"
"    BL      sub_FFC10CAC \n"
"    BL      sub_FFC1A4CC \n"
"    BL      sub_FFC10C68 \n"
"    LDMFD   SP!, {R4,LR} \n"
);
}

/*************************************************************/
//** taskcreatePhySw_my @ 0xFFC118D8 - 0xFFC1191C, length=18
void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    LDR     R4, =0x1BE4 \n"
"    LDR     R0, [R4, #0x10] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FFC1190C \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =mykbd_task \n"  // --> Patched. Old value = 0xFFC118A4.
"    MOV     R2, #0x2000 \n"  // --> Patched. Old value = 0x800. stack size for new task_PhySw so we don't have to do stack switch
"    MOV     R1, #0x17 \n"
"    LDR     R0, =0xFFC11B00 /*'PhySw'*/ \n"
"    BL      sub_FFC0BBB8 /*_CreateTaskStrictly*/ \n"
"    STR     R0, [R4, #0x10] \n"

"loc_FFC1190C:\n"
"    BL      sub_FFC14488 \n"
"    LDR     R1, =0x10088 \n"
"    LDMFD   SP!, {R3-R5,LR} \n"
"    MOV     R0, #0 \n"
"    B       sub_FFC552EC /*_OpLog.Start_FW*/ \n"
);
}

/*************************************************************/
//** init_file_modules_task @ 0xFFC5EBF8 - 0xFFC5EC2C, length=14
void __attribute__((naked,noinline)) init_file_modules_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FFC57794 \n"
"    LDR     R5, =0x5006 \n"
"    MOVS    R4, R0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, R5 \n"
"    BLNE    _PostLogicalEventToUI \n"
"    BL      sub_FFC577C0_my \n"  // --> Patched. Old value = 0xFFC577C0.
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
//** sub_FFC577C0_my @ 0xFFC577C0 - 0xFFC577F8, length=15
void __attribute__((naked,noinline)) sub_FFC577C0_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FFC3C544_my \n"  // --> Patched. Old value = 0xFFC3C544.
"    LDR     R4, =0x55A8 \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FFC577F0 \n"
"    BL      sub_FFC65B88 \n"
"    BL      sub_FFCDC234 \n"
"    BL      sub_FFC65B88 \n"
"    BL      sub_FFC39F34 \n"
"    BL      sub_FFC65B98 \n"
"    BL      sub_FFCDC300 \n"

"loc_FFC577F0:\n"
"    MOV     R0, #1 \n"
"    STR     R0, [R4] \n"
"    LDMFD   SP!, {R4,PC} \n"
);
}

/*************************************************************/
//** sub_FFC3C544_my @ 0xFFC3C544 - 0xFFC3C5DC, length=39
void __attribute__((naked,noinline)) sub_FFC3C544_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    MOV     R6, #0 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FFC3C004 \n"
"    LDR     R4, =0x11168 \n"
"    MOV     R5, #0 \n"
"    LDR     R0, [R4, #0x38] \n"
"    BL      sub_FFC3CA38 \n"
"    CMP     R0, #0 \n"
"    LDREQ   R0, =0x2858 \n"
"    STREQ   R5, [R0, #0x10] \n"
"    STREQ   R5, [R0, #0x14] \n"
"    STREQ   R5, [R0, #0x18] \n"
"    MOV     R0, R6 \n"
"    BL      sub_FFC3C044 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FFC3C380_my \n"  // --> Patched. Old value = 0xFFC3C380.
"    MOV     R5, R0 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FFC3C3EC \n"
"    LDR     R1, [R4, #0x3C] \n"
"    AND     R2, R5, R0 \n"
"    CMP     R1, #0 \n"
"    MOV     R0, #0 \n"
"    MOVEQ   R0, #0x80000001 \n"
"    BEQ     loc_FFC3C5D8 \n"
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

"loc_FFC3C5D8:\n"
"    STR     R0, [R4, #0x40] \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** sub_FFC3C380_my @ 0xFFC3C380 - 0xFFC3C3E8, length=27
void __attribute__((naked,noinline)) sub_FFC3C380_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x2858 \n"
"    MOV     R6, R0 \n"
"    LDR     R0, [R5, #0x14] \n"
"    CMP     R0, #0 \n"
"    MOVNE   R0, #1 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    MOV     R0, #0x17 \n"
"    MUL     R1, R0, R6 \n"
"    LDR     R0, =0x11168 \n"
"    ADD     R4, R0, R1, LSL#2 \n"
"    LDR     R0, [R4, #0x38] \n"
"    MOV     R1, R6 \n"
"    BL      sub_FFC3C110_my \n"  // --> Patched. Old value = 0xFFC3C110.
"    CMP     R0, #0 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"
"    LDR     R0, [R4, #0x38] \n"
"    MOV     R1, R6 \n"
"    BL      sub_FFC3C278 \n"
"    CMP     R0, #0 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"
"    MOV     R0, R6 \n"
"    BL      sub_FFC3BC0C \n"
"    CMP     R0, #0 \n"
"    MOVNE   R1, #1 \n"
"    STRNE   R1, [R5, #0x14] \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** sub_FFC3C110_my @ 0xFFC3C110 - 0xFFC3C274, length=90
void __attribute__((naked,noinline)) sub_FFC3C110_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    MOV     R8, R0 \n"
"    MOV     R0, #0x17 \n"
"    MUL     R1, R0, R1 \n"
"    LDR     R0, =0x11168 \n"
"    MOV     R6, #0 \n"
"    ADD     R7, R0, R1, LSL#2 \n"
"    LDR     R0, [R7, #0x3C] \n"
"    MOV     R5, #0 \n"
"    CMP     R0, #6 \n"
"    ADDLS   PC, PC, R0, LSL#2 \n"
"    B       loc_FFC3C25C \n"
"    B       loc_FFC3C174 \n"
"    B       loc_FFC3C15C \n"
"    B       loc_FFC3C15C \n"
"    B       loc_FFC3C15C \n"
"    B       loc_FFC3C15C \n"
"    B       loc_FFC3C254 \n"
"    B       loc_FFC3C15C \n"

"loc_FFC3C15C:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0x200 \n"
"    MOV     R0, #3 \n"
"    BL      _exmem_ualloc \n"
"    MOVS    R4, R0 \n"
"    BNE     loc_FFC3C17C \n"

"loc_FFC3C174:\n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R4-R8,PC} \n"

"loc_FFC3C17C:\n"
"    LDR     R12, [R7, #0x4C] \n"
"    MOV     R3, R4 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, R8 \n"
"    BLX     R12 \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FFC3C1A8 \n"
"    MOV     R0, #3 \n"
"    BL      _exmem_ufree \n"
"    B       loc_FFC3C174 \n"

"loc_FFC3C1A8:\n"
"    MOV     R0, R8 \n"
"    BL      sub_FFCF8D9C \n"

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
"    BNE     loc_FFC3C230 \n"
"    CMP     R0, R1 \n"
"    BCC     loc_FFC3C230 \n"
"    ADD     R2, R1, R3 \n"
"    CMP     R2, R0 \n"
"    CMPLS   R12, #0x55 \n"
"    CMPEQ   LR, #0xAA \n"
"    MOVEQ   R6, R1 \n"
"    MOVEQ   R5, R3 \n"
"    MOVEQ   R4, #1 \n"

"loc_FFC3C230:\n"
"    MOV     R0, #3 \n"
"    BL      _exmem_ufree \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FFC3C268 \n"
"    MOV     R6, #0 \n"
"    MOV     R0, R8 \n"
"    BL      sub_FFCF8D9C \n"
"    MOV     R5, R0 \n"
"    B       loc_FFC3C268 \n"

"loc_FFC3C254:\n"
"    MOV     R5, #0x40 \n"
"    B       loc_FFC3C268 \n"

"loc_FFC3C25C:\n"
"    MOV     R1, #0x374 \n"
"    LDR     R0, =0xFFC3C104 /*'Mounter.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FFC3C268:\n"
"    STR     R6, [R7, #0x44]! \n"
"    MOV     R0, #1 \n"
"    STR     R5, [R7, #4] \n"
"    LDMFD   SP!, {R4-R8,PC} \n"
);
}
