#include "stubs_asm.h"
#define NULL_SUB 0xFF810AD4

NHSTUB(finish_shutdown,0xFF8301F4) // for shutdown(), last call from task_Bye

// Override stubs_entry.S
NHSTUB(kbd_pwr_on,                      NULL_SUB)
NHSTUB(kbd_pwr_off,                     NULL_SUB)
NHSTUB(MakeDirectory_Fut,             0xff82be34)  //mkdir. This requires #define MKDIR_RETURN_ONE_ON_SUCCESS

// These do not exist
NHSTUB(SetZoomActuatorSpeedPercent,     NULL_SUB)

//NHSTUB(LogCameraEvent,0xff8920b8)

