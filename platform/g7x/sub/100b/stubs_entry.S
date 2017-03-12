// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Main firmware start: 0xfc020000
//   DRYOS R55 (DRYOS version 2.3, release #0055+p6)
//   Firmware Ver GM1.00B   // Found @ 0xfc1591f8, "GM1.00B" @ 0xfc159205

// Values for makefile.inc
//   PLATFORMOSVER = 55
//   MEMISOSTART = 0x36a354
//   MEMBASEADDR = 0x8000
//   ARAM_HEAP_START = 0x006ce000 #  Found @0xfc101938
//   ARAM_HEAP_SIZE = 0x00022000 #  Found @0xfc101912

// Detected address ranges:
// ROM      0xfc000000 - 0xfe000000 (33554432 bytes)
// RAM code 0x010e1000 - 0x0110dc1c copied from 0xfcd67020 ( 183324 bytes)
// RAM data 0x00008000 - 0x000352b8 copied from 0xfcd39d68 ( 185016 bytes)

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xfc0ef0fc

// physw_event_table 0xfc613700 Found @0xfc075c9a
// Values below go in 'platform_kbd.h':
//#define SD_READONLY_FLAG    0x20000000 // Found @0xfc6137e0, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x10000000 // Found @0xfc613820, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xfc613818, levent 0x205
//#define BATTCOVER_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
// WARNING: Values only verified on sx280hs (R52) and g7x (R55p6) errors likely on other cams!
//KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x00040001 }, // Found @0xfc613700, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00040000 }, // Found @0xfc613778, levent 0x00
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000001 }, // Found @0xfc613700, levent 0x01
//    { 0, KEY_ZOOM_OUT        ,0x00000002 }, // Found @0xfc613708, levent 0x04
//    { 0, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xfc613710, levent 0x03
//    { 0, KEY_VIDEO           ,0x00000008 }, // Found @0xfc613718, levent 0x02
//    { 0, KEY_MENU            ,0x00000010 }, // Found @0xfc613720, levent 0x14
//    { 0, KEY_UP              ,0x00000020 }, // Found @0xfc613728, levent 0x06
//    { 0, KEY_DOWN            ,0x00000040 }, // Found @0xfc613730, levent 0x07
//    { 0, KEY_RIGHT           ,0x00000080 }, // Found @0xfc613738, levent 0x09
//    { 0, KEY_LEFT            ,0x00000100 }, // Found @0xfc613740, levent 0x08
//    { 0, KEY_SET             ,0x00000200 }, // Found @0xfc613748, levent 0x0a
//    { 0, KEY_PLAYBACK        ,0x00000800 }, // Found @0xfc613758, levent 0x101
//    { 0, KEY_POWER           ,0x00020000 }, // Found @0xfc613770, levent 0x100
//    { 0, 0, 0 }
//};

// canon_mode_list 0xfc94b3f8 Found @0xfc118650
// Check modemap values from 'platform/CAMERA/shooting.c':
// 33297  0x8211 In firmware but not in current modemap
//  4172  0x104c In firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(ctypes                            ,0xfc5bd388)
DEF(physw_run                         ,0x000082c8) // Found @0xfc0780c2
DEF(physw_sleep_delay                 ,0x000082d0) // (0x82c8+0x8) Found @0xfc0780c6
DEF(physw_status                      ,0x00036c10) // Found @0xfc0783fe
DEF(fileio_semaphore                  ,0x000139b8) // Found @0xfc073b86
DEF(levent_table                      ,0xfc6deb24) // Found @0xfc0d09b4
DEF(FlashParamsTable                  ,0xfc94b75c) // Found @0xfc118664
DEF(playrec_mode                      ,0x0000bec4) // (0xbec0+0x4) Found @0xfc2f77f6
DEF(jpeg_count_str                    ,0x0015d630) // Found @0xfc103a94
DEF(zoom_busy                         ,0x00013e18) // (0x13df8+0x20) Found @0xfc1dac7e
DEF(focus_busy                        ,0x00013bb0) // (0x13ba8+0x8) Found @0xfc31ef22
DEF_CONST(uiprop_count                      ,0x000000c7) // Found @0xfc0af556

//NHSTUB(Feof_Fut                             ,0x00000000) //  0        *** != 0xfc325d2d
//NHSTUB(Fflush_Fut                           ,0x00000000) //  0        *** != 0xfc325d55
//NHSTUB(GetDrive_TotalClusters               ,0x00000000) //  0        *** != 0xfc357be3
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0x00000000) //  0        *** != 0xfc31fe09
//NHSTUB(GetImageFolder                       ,0x00000000) //  0        *** != 0xfc320ecb
//NHSTUB(MakeSDCardBootable                   ,0x00000000) //  0        *** != 0xfc357f71
//NHSTUB(RenameFile_Fut                       ,0x00000000) //  0        *** != 0xfc325add
//NHSTUB(SetFileAttributes                    ,0x00000000) //  0        *** != 0xfc358325
//NHSTUB(SetFileTimeStamp                     ,0x00000000) //  0        *** != 0xfc3582dd
//NHSTUB(apex2us                              ,0x00000000) //  0        *** != 0xfc382693
//NHSTUB(displaybusyonscreen                  ,0x00000000) //  0        *** != 0xfc345879
//NHSTUB(undisplaybusyonscreen                ,0x00000000) //  0        *** != 0xfc345911
//NHSTUB(CancelHPTimer                        ,0x00000000) //  0        *** != 0xfc158e25

NHSTUB(AllocateUncacheableMemory              ,0xfc0ef0cd) //  0
NHSTUB(Close                                  ,0xfc358091) //  0
NHSTUB(CreateTask                             ,0x010e5089) //  0
NHSTUB(DebugAssert                            ,0x010e5cb9) //  0
NHSTUB(DeleteDirectory_Fut                    ,0xfc325b89) //  0
NHSTUB(DeleteFile_Fut                         ,0xfc325b3f) //  0
NHSTUB(DoAELock                               ,0xfc283955) //  0
NHSTUB(DoAFLock                               ,0xfc2835bb) //  0
//NHSTUB(EnterToCompensationEVF               ,0x00000000) //  0            == 0x00000000
NHSTUB2(ExecuteEventProcedure                  ,0xfc326071) //  0
//NHSTUB(ExitFromCompensationEVF              ,0x00000000) //  0            == 0x00000000
NHSTUB(ExitTask                               ,0x010e526b) //  0
//NHSTUB(ExpCtrlTool_StartContiAE             ,0x00000000) //  0            == 0x00000000
//NHSTUB(ExpCtrlTool_StopContiAE              ,0x00000000) //  0            == 0x00000000
NHSTUB(Fclose_Fut                             ,0xfc325beb) //  0
NHSTUB(Fgets_Fut                              ,0xfc325cc9) //  0
NHSTUB(Fopen_Fut                              ,0xfc325bc3) //  0
NHSTUB(Fread_Fut                              ,0xfc325c5d) //  0
NHSTUB(FreeUncacheableMemory                  ,0xfc0ef0f9) //  0
NHSTUB(Fseek_Fut                              ,0xfc325cfb) //  0
NHSTUB(Fwrite_Fut                             ,0xfc325c93) //  0
NHSTUB(GetBatteryTemperature                  ,0xfc1403f9) //  0
NHSTUB(GetCCDTemperature                      ,0xfc14039d) //  0
NHSTUB(GetCurrentAvValue                      ,0xfc14816d) //  0
NHSTUB(GetDrive_ClusterSize                   ,0xfc357703) //  0
NHSTUB(GetDrive_FreeClusters                  ,0xfc357c07) //  0
NHSTUB(GetFocusLensSubjectDistance            ,0xfc31fb0f) //  0
NHSTUB(GetKbdState                            ,0xfc075d95) //  0
NHSTUB(GetMemInfo                             ,0xfc455ed1) //  0
NHSTUB(GetOpticalTemperature                  ,0xfc140453) //  0
NHSTUB(GetParameterData                       ,0xfc0afe85) //  0
NHSTUB(GetPropertyCase                        ,0xfc34a783) //  0
NHSTUB(GetSystemTime                          ,0xfc3d88b5) //  0
NHSTUB(GetVRAMHPixelsSize                     ,0xfc13bef1) //  0
NHSTUB(GetVRAMVPixelsSize                     ,0xfc13bef9) //  0
NHSTUB(GetZoomLensCurrentPoint                ,0xfc1daec9) //  0
NHSTUB(GetZoomLensCurrentPosition             ,0xfc1dae5d) //  0
NHSTUB(GiveSemaphore                          ,0x010e5ad1) //  0
NHSTUB(IsStrobeChargeCompleted                ,0xfc1862a5) //  0
NHSTUB(LEDDrive                               ,0xfc1e23a1) //  0
NHSTUB(LocalTime                              ,0x010e61cd) //  0
NHSTUB(LockMainPower                          ,0xfc15941f) //  0
NHSTUB(MakeDirectory_Fut                      ,0xfc35837b) //  0
NHSTUB(MoveFocusLensToDistance                ,0xfc4f39b9) //  0
NHSTUB(MoveIrisWithAv                         ,0xfc3d1af9) //  0
NHSTUB(MoveZoomLensWithPoint                  ,0xfc3d2495) //  0
NHSTUB(Open                                   ,0xfc35800d) //  0
NHSTUB(PB2Rec                                 ,0xfc0deac5) //  0
NHSTUB(PT_MoveDigitalZoomToWide               ,0xfc282fdf) //  0
NHSTUB(PT_MoveOpticalZoomAt                   ,0xfc1e32d5) //  0
NHSTUB(PT_PlaySound                           ,0xfc359819) //  0
NHSTUB(PostLogicalEventForNotPowerType        ,0xfc3594d5) //  0
NHSTUB(PostLogicalEventToUI                   ,0xfc359501) //  0
NHSTUB(PutInNdFilter                          ,0xfc4f3ca9) //  0
NHSTUB(PutOutNdFilter                         ,0xfc4f3ccf) //  0
NHSTUB(Read                                   ,0xfc134541) //  0
NHSTUB(ReadFastDir                            ,0xfc1184e9) //  0
NHSTUB(Rec2PB                                 ,0xfc0deb09) //  0
//NHSTUB(RefreshPhysicalScreen                ,0x00000000) //  0            == 0x00000000
//NHSTUB(Restart                              ,0x00000000) //  0            == 0x00000000
NHSTUB(ScreenLock                             ,0xfc361fcf) //  0
NHSTUB(ScreenUnlock                           ,0xfc36200d) //  0
NHSTUB(SetAE_ShutterSpeed                     ,0xfc4f02e1) //  0
NHSTUB(SetAutoShutdownTime                    ,0xfc15946b) //  0
NHSTUB(SetCurrentCaptureModeType              ,0xfc331c13) //  0
NHSTUB(SetLogicalEventActive                  ,0xfc34b72b) //  0
//NHSTUB(SetParameterData                     ,0x00000000) //  0            == 0x00000000
NHSTUB(SetPropertyCase                        ,0xfc34a64f) //  0
NHSTUB(SetScriptMode                          ,0xfc34b763) //  0
NHSTUB(SleepTask                              ,0x010e4ff1) //  0
NHSTUB(TakeSemaphore                          ,0x010e5a59) //  0
NHSTUB(TurnOffBackLight                       ,0xfc32a833) //  0
NHSTUB(TurnOnBackLight                        ,0xfc32a7f5) //  0
NHSTUB(TurnOnDisplay                          ,0xfc0cd291) //  0
NHSTUB(TurnOffDisplay                         ,0xfc0cd2a3) //  0
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xfc1f6e87) //  0
NHSTUB(UnlockAE                               ,0xfc283973) //  0
NHSTUB(UnlockAF                               ,0xfc2835eb) //  0
NHSTUB(UnlockMainPower                        ,0xfc1593bb) //  0
//NHSTUB(UnsetZoomForMovie                    ,0x00000000) //  0            == 0x00000000
NHSTUB(VbattGet                               ,0xfc134e01) //  0
NHSTUB(Write                                  ,0xfc3580c9) //  0
//NHSTUB(WriteSDCard                          ,0x00000000) //  0            == 0x00000000
NHSTUB(_log                                   ,0x01109310) //  0
NHSTUB(_log10                                 ,0x01109830) //  0
NHSTUB(_pow                                   ,0x01109998) //  0
NHSTUB(_sqrt                                  ,0x0110ba18) //  0
NHSTUB(add_ptp_handler                        ,0xfc0f38b7) //  0
NHSTUB(close                                  ,0xfc13443b) //  0
NHSTUB(exmem_alloc                            ,0xfc079dbb) //  0
NHSTUB(exmem_free                             ,0xfc079dfb) //  0
NHSTUB(free                                   ,0xfc3623fb) //  0
NHSTUB(kbd_p1_f                               ,0xfc0783f7) //  0
NHSTUB(kbd_p1_f_cont                          ,0xfc0783ff) //  0
NHSTUB(kbd_p2_f                               ,0xfc077e8d) //  0
NHSTUB(kbd_read_keys                          ,0xfc0783c1) //  0
NHSTUB(kbd_read_keys_r2                       ,0xfc075c97) //  0
NHSTUB(lseek                                  ,0xfc3581ed) //  0
NHSTUB(malloc                                 ,0xfc3623c5) //  0
NHSTUB(memcmp                                 ,0xfc36257d) //  0
NHSTUB(memcpy                                 ,0xfc0e7d41) //  0
NHSTUB(memset                                 ,0xfc1096fd) //  0
NHSTUB(mktime_ext                             ,0xfc457749) //  0
NHSTUB(open                                   ,0xfc1343cb) //  0
NHSTUB(OpenFastDir                            ,0xfc118449) //  0
NHSTUB(closedir                               ,0xfc118411) //  0
NHSTUB(get_fstype                             ,0xfc35769d) //  0
NHSTUB(qsort                                  ,0xfc248dcd) //  0
NHSTUB(rand                                   ,0xfc161a83) //  0
//NHSTUB(reboot_fw_update                     ,0x00000000) //  0            == 0x00000000
NHSTUB(set_control_event                      ,0xfc34b4a5) //  0
NHSTUB(srand                                  ,0xfc161a7d) //  0
NHSTUB(stat                                   ,0xfc358225) //  0
NHSTUB(strcat                                 ,0xfc36242d) //  0
NHSTUB(strchr                                 ,0xfc161af5) //  0
NHSTUB(strcmp                                 ,0xfc3624f9) //  0
NHSTUB(strcpy                                 ,0xfc3624d5) //  0
NHSTUB(strftime                               ,0xfc1614f5) //  0
NHSTUB(strlen                                 ,0xfc362557) //  0
NHSTUB(strncmp                                ,0xfc161acb) //  0
NHSTUB(strncpy                                ,0xfc36244f) //  0
NHSTUB(strrchr                                ,0xfc0e7dd5) //  0
NHSTUB(strtol                                 ,0xfc161a6f) //  0
NHSTUB(strtolx                                ,0xfc16192d) //  0
   DEF(task_CaptSeq                           ,0xfc1501d9) //  0
   DEF(task_DvlpSeqTask                       ,0xfc1e6837) //  0
   DEF(task_ExpDrv                            ,0xfc2a575d) //  0
   DEF(task_FileWrite                         ,0xfc06b31d) //  0
   DEF(task_InitFileModules                   ,0xfc0c22d1) //  0
   DEF(task_MovieRecord                       ,0xfc14cd13) //  0
   DEF(task_PhySw                             ,0xfc0780c1) //  0
   DEF(task_TouchPanel                        ,0xfc0e2223) //  0
   DEF(hook_CreateTask                        ,0x010e5088) //  0
NHSTUB(time                                   ,0x010e5e9b) //  0
NHSTUB(vsprintf                               ,0xfc0c38cf) //  0
NHSTUB(EngDrvRead                             ,0xfc360b31) //  0
NHSTUB(PTM_GetCurrentItem                     ,0xfc34b2ab) //  0
NHSTUB(DisableISDriveError                    ,0xfc3d2a39) //  0
NHSTUB(SetHPTimerAfterNow                     ,0xfc158d8d) //  0
NHSTUB(PT_MFOn                                ,0xfc2849e5) //  0
NHSTUB(PT_MFOff                               ,0xfc284a19) //  0
NHSTUB(GetAdChValue                           ,0xfc0e103b) //  0