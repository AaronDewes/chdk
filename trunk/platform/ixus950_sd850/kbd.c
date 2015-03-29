#include "lolevel.h"
#include "platform.h"
#include "keyboard.h"
#include "kbd_common.h"

long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

/********* KeyMap verified for ixus950_sd850, the same as in ixus70_sd1000 **********/
KeyMap keymap[] = {
    /* tiny bug: key order matters. see kbd_get_pressed_key()
     * for example
     */
    {2, KEY_UP	, 0x00000010 },
    {2, KEY_DOWN	, 0x00000040 },
    {2, KEY_LEFT	, 0x00000080 },
    {2, KEY_RIGHT	, 0x00000020 },
    {2, KEY_SET	, 0x00000100 },
    {1, KEY_SHOOT_FULL, 0xC0000000 },
    {1, KEY_SHOOT_FULL_ONLY, 0x80000000 },
    {1, KEY_SHOOT_HALF, 0x40000000 },
    {2, KEY_ZOOM_IN	, 0x00000004 },
    {2, KEY_ZOOM_OUT, 0x00000008 },
    {2, KEY_MENU	, 0x00000200 },
    {2, KEY_DISPLAY	, 0x00000400 },
    {2, KEY_PRINT	, 0x00000800 },
    {0, 0, 0 }
};


#define NEW_SS (0x2000)

int get_usb_bit() 
{
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return(( usb_physw[USB_IDX] & USB_MASK)==USB_MASK);
}

static char kbd_stack[NEW_SS];

long __attribute__((naked)) wrap_kbd_p1_f();


static void __attribute__((noinline)) mykbd_task_proceed()
{
    while (physw_run){
        _SleepTask(10);

        if (wrap_kbd_p1_f() == 1){ // autorepeat ?
            _kbd_p2_f();
        }
    }
}

void __attribute__((naked,noinline)) mykbd_task()
{
    /* WARNING
     * Stack pointer manipulation performed here!
     * This means (but not limited to):
     *	function arguments destroyed;
     *	function CAN NOT return properly;
     *	MUST NOT call or use stack variables before stack
     *	is setup properly;
     *
     */

    register int i;
    register long *newstack;

    newstack = (void*)kbd_stack;	// #define NEW_SS (0x2000), kbd_stack[NEW_SS] above

    for (i=0;i<NEW_SS/4;i++)
	newstack[i]=0xdededede;

    asm volatile (
	"MOV	SP, %0"
	:: "r"(((char*)newstack)+NEW_SS)
	: "memory"
    );

    mykbd_task_proceed();

    /* function can be modified to restore SP here...
     */

    _ExitTask();
}


long __attribute__((naked,noinline)) wrap_kbd_p1_f()	// original kbd_p1_f is sub_FFA3711C
{

    asm volatile(
                "STMFD   SP!, {R4-R7,LR}\n"
                "SUB     SP, SP, #0xC\n"
                "BL      my_kbd_read_keys\n"	// original sub_FFA371E8
                "B      _kbd_p1_f_cont\n"	// kbd_p1_f_cont at FFA37128
    );
    return 0; // shut up the compiler
}


void my_kbd_read_keys()
{
    static int handle_taskTouchW = 0, isRunning_taskTouchW = 1;
    if (handle_taskTouchW == 0) {
        handle_taskTouchW = _taskNameToId("tTouchW");
    }

    _kbd_pwr_on();
    kbd_fetch_data(kbd_new_state);
    
    // TODO TouchW logic equivalent to jogdial
    if(kbd_update_key_state() == 0) {
        if (!isRunning_taskTouchW) {
            _taskResume(handle_taskTouchW);
            isRunning_taskTouchW = 1;
        }
    } else {
        if (isRunning_taskTouchW && !camera_info.state.state_kbd_script_run) {
            _taskSuspend(handle_taskTouchW);
            isRunning_taskTouchW = 0;
        } else if (!isRunning_taskTouchW && camera_info.state.state_kbd_script_run) {
            _taskResume(handle_taskTouchW);
            isRunning_taskTouchW = 1;
        }
    }

    _kbd_read_keys_r2(physw_status);

    kbd_update_physw_bits();

    _kbd_pwr_off();
}

void kbd_fetch_data(long *dst)
{
    volatile long *mmio0 = (void*)0xc0220200;
    volatile long *mmio1 = (void*)0xc0220204;
    volatile long *mmio2 = (void*)0xc0220208;

    dst[0] = *mmio0;
    dst[1] = *mmio1;
    dst[2] = *mmio2 & 0xffff;
}
