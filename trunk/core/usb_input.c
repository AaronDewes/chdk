/*===================================================================================================================================================

	USB Remote : Input Device Driver Modules

		-	device driver modules are responsible for monitoring the state of USB power and translating
			that into a "virtual switch" state
		-	the "virtual switch" state is monitored by the current control logic module for processing - there is no response expected back from the module
		-	the active device driver module is selected from a menu entry in the USB Remote menu
		-	to add a device driver, create a new function here, add name string to gui_USB_switch_types[]
			in gui.c and add ptr below to structure (*usb_driver[10])()

  ===================================================================================================================================================*/

#include "kbd.h"
#include "stdlib.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "conf.h"
#include "camera.h"
#include "usb_remote.h"

/*===================================================================================================
    Variables
  ===================================================================================================*/

extern int usb_remote_active ;
extern int virtual_remote_pulse_count ;
extern int virtual_remote_pulse_width ;
extern int stime_stamp ;
extern int sync_counter;
extern int usb_sync_wait ;

extern enum SWITCH_TYPE	 switch_type ;
extern enum CONTROL_MODULE  control_module  ;
extern enum VIRTUAL_REMOTE_STATE  virtual_remote_state;
extern enum DRIVER_STATE  driver_state;
extern enum LOGIC_MODULE_STATE logic_module_state ;
extern enum USB_STATE  usb_state ;
extern enum CAMERA_MODE  camera_mode ;


/*===================================================================================================
	Debug and error handling
  ===================================================================================================*/

#ifdef USB_REMOTE_DEBUGGING

extern int debug_errors[] ;
extern void debug_error(int ) ;

#else

extern void debug_error(int ) ;

#endif



/*---------------------------------------------------------------------------------------------------
	Device Driver :  "one press" switch
		-  goes to HALF_PRESS when USB power applied and then pulses FULL_PRESS when USB power removed
  ---------------------------------------------------------------------------------------------------*/
void usb_one_press_switch(int usb_state)
{
	static int time_stamp = 0 ;
	int current_time ;

	current_time = get_tick_count();

	switch( driver_state )
	{
		case SW_RESET :
			virtual_remote_state = REMOTE_RELEASE ;
			driver_state = SW_IDLE ;
			break ;

		case SW_IDLE :
			virtual_remote_state = REMOTE_RELEASE ;
			if ( usb_state == USB_POWER_ON )
			{
				driver_state = SW_POWER_CONNECT ;
				time_stamp = current_time ;
			}
			break ;

		case SW_POWER_CONNECT :
			if ( usb_state == USB_POWER_ON )
			{
				if ( current_time - time_stamp > DEBOUNCE_TIME )   // debounce
				{
					driver_state = SW_POWER_ON ;
					virtual_remote_state = REMOTE_HALF_PRESS ;
					time_stamp = current_time ;
				}
			}
			else
			{
				driver_state = SW_IDLE ;
			}
			break ;

		case SW_POWER_ON :
			if ( usb_state == USB_POWER_ON )
			{
				if ( current_time - time_stamp > MAX_PULSE_TIME )		// timeout ?
				{
					virtual_remote_state =  REMOTE_RELEASE ;			// clear shutter but hang here until usb power goes away
				}
			}
			else
			{
				if ( current_time - time_stamp > DEBOUNCE_TIME ) // debounce
				{
					driver_state = SW_POWER_DISCONNECT ;
					virtual_remote_state = REMOTE_FULL_PRESS ;
					time_stamp = current_time ;
				}
			}
			break ;

		case SW_POWER_DISCONNECT :
			if ( current_time - time_stamp > FULL_PRESS_PULSE_TIME )
			{
				driver_state = SW_IDLE ;
				virtual_remote_state = REMOTE_RELEASE ;
			}
			break ;

		default :
			debug_error(INVALID_STATE) ;
			break ;

	}

};


/*---------------------------------------------------------------------------------------------------
	Device Driver :  "two press" switch
	-  goes to HALF_PRESS when USB power applied and then FULL_PRESS if USB power removed and quickly reapplied
  ---------------------------------------------------------------------------------------------------*/

void usb_two_press_switch(int usb_state)
{
	static int time_stamp = 0 ;
	int current_time ;

	current_time = get_tick_count() ;

	switch( driver_state )
	{
		case SW_RESET :
			virtual_remote_state = REMOTE_RELEASE ;
			driver_state = SW_IDLE ;
			break ;

		case SW_IDLE :
			if ( usb_state == USB_POWER_ON )
			{
				driver_state = SW_POWER_CONNECT ;
				time_stamp = current_time ;
			}
			break ;

		case SW_POWER_CONNECT :
			if ( usb_state == USB_POWER_ON )
			{
				if ( current_time - time_stamp > DEBOUNCE_TIME )   // debounce
				{
					driver_state = SW_POWER_ON ;
					virtual_remote_state = REMOTE_HALF_PRESS ;
					time_stamp = current_time ;
				}
			}
			else
			{
				driver_state = SW_IDLE ;
			}
			break ;

		case SW_POWER_ON :
			if ( usb_state == USB_POWER_OFF )
			{
				if ( current_time - time_stamp > DEBOUNCE_TIME ) // debounce
				{
					driver_state = SW_POWER_DISCONNECT ;
					time_stamp = current_time ;
				}
			}
			break ;

		case SW_POWER_DISCONNECT :
			if ( usb_state == USB_POWER_ON )
			{
				if ( current_time - time_stamp > DEBOUNCE_TIME )   // debounce
				{
					driver_state = SW_FULL_PRESS_ACTIVE;
					virtual_remote_state = REMOTE_FULL_PRESS ;
					time_stamp = current_time ;
				}
			}
			else
			{
				if ( current_time - time_stamp > MAX_FULL_PRESS_DELAY )	// timeout if no second press
				{
					virtual_remote_state =  REMOTE_RELEASE ;
					driver_state = SW_IDLE ;
				}
			}
			break ;


		case SW_FULL_PRESS_ACTIVE :
			if ( usb_state == USB_POWER_OFF )
			{
				virtual_remote_state = REMOTE_RELEASE ;
				driver_state = SW_IDLE ;
			}
			break ;

		default :
			debug_error(INVALID_STATE) ;
			break ;

	}

} ;
/*---------------------------------------------------------------------------------------------------
	Device Driver :   Ricoh CA-1 switch
		- measures USB pulse widths to detect RICOH CA-1 half press, full press and cancel sequences
		  and sets virtual switch state appropriately
  ---------------------------------------------------------------------------------------------------*/

void usb_ricoh_ca1_switch(int usb_state)
{
	static int time_stamp = 0 ;
	int current_time ;

	current_time = get_tick_count() ;

	switch( driver_state )
	{
		case SW_RESET :
			virtual_remote_state = REMOTE_RELEASE ;
			driver_state = SW_IDLE ;
			break ;

		case SW_IDLE :								// wait for USB power to be applied
			virtual_remote_state = REMOTE_RELEASE ;
			if ( usb_state == USB_POWER_ON )
			{
				driver_state = SW_POWER_CONNECT ;
				time_stamp = current_time ;
			}
			break ;

		case SW_POWER_CONNECT :					// wait for USB power to be removed and then test for half press pulse width
			if ( usb_state == USB_POWER_OFF )
			{
				if (( current_time - time_stamp > CA1_MIN_HALFPRESS_TIME )  && ( current_time - time_stamp < CA1_MAX_HALFPRESS_TIME )  )
				{
					driver_state = SW_SHORT_PRESS ;
					time_stamp = current_time ;
				}
				else
				{
					driver_state = SW_IDLE ;
				}
			}
			break ;

		case SW_SHORT_PRESS :						// wait for USB power to be applied	again (cancel pulse) else that was a valid half press
			if ( usb_state == USB_POWER_ON )
			{
				driver_state = SW_CANCEL_PULSE ;
				time_stamp = current_time ;
			}
			else
			{
				if ( current_time - time_stamp > CA1_MAX_HALFPRESS_TIME )
				{
					driver_state = SW_HALF_PRESS ;
					virtual_remote_state = REMOTE_HALF_PRESS ;
				}
			}
			break ;

		case SW_CANCEL_PULSE :					// absorb the 2nd cancel pulse - wait for USB power to go away
			if ( usb_state == USB_POWER_OFF )
			{
				driver_state = SW_IDLE ;
			}
			break ;

		case SW_HALF_PRESS :						// wait for USB power to be applied	again (full press or cancel pulse or timeout)
			if ( usb_state == USB_POWER_ON )
			{
				driver_state = SW_FULL_PRESS ;
				time_stamp = current_time ;
			}
			else
			{
				if ( current_time - time_stamp > CA1_FULL_WAIT_PRESS_TIMEOUT )	driver_state = SW_IDLE ;
			}
			break ;

		case SW_FULL_PRESS :					// check pulse width when USB power removed - detect CA-1 full press 150 mSec pulse
			if ( usb_state == USB_POWER_OFF )
			{
				if (( current_time - time_stamp > CA1_MIN_FULLPRESS_TIME )  && ( current_time - time_stamp < CA1_MAX_FULLPRESS_TIME ) )
				{
					driver_state = SW_FULL_PRESS_RESET ;
					virtual_remote_state = REMOTE_FULL_PRESS ;
					time_stamp = current_time ;
				}
				else	// short pulse seen ?
				{
					if (( current_time - time_stamp > CA1_MIN_HALFPRESS_TIME )  && ( current_time - time_stamp < CA1_MAX_HALFPRESS_TIME )  )
					{
						driver_state = SW_SHORT_PRESS ;
						time_stamp = current_time ;
					}
					else driver_state = SW_IDLE ;
				}
			}
			break ;

		case SW_FULL_PRESS_RESET :					// reset full press active after a delay
			if ( current_time - time_stamp > FULL_PRESS_PULSE_TIME )
			{
				virtual_remote_state = REMOTE_RELEASE ;
				driver_state = SW_IDLE ;
			}
			break ;

		default :
			debug_error(INVALID_STATE) ;
			break ;

	}

} ;

/*---------------------------------------------------------------------------------------------------
	Device Driver : pulse width modulation device
		- gets the width of USB power pulses
		- does not set virtual switch states
		- hand shake mechanism with control modules is simply them clearing the report pulse width value
		- might be useful for gentles modules or some custom microcontroller device
  ---------------------------------------------------------------------------------------------------*/
void usb_pwm_device(int usb_state)
{
	int pw ;

	switch( driver_state )
	{
		case SW_RESET :
			virtual_remote_state = REMOTE_RESET ;
			driver_state = SW_IDLE ;
			break ;

		case SW_IDLE :
			pw = get_usb_power(2) ;
			if ( pw != 0) virtual_remote_pulse_width  = pw ;
			break ;

		default :
			debug_error(INVALID_STATE) ;
			break ;
	}
} ;

/*---------------------------------------------------------------------------------------------------
	Device Driver :  pulse counting device
		- counts USB pulses (off-on-off)
		- ignores short pulses less that 100 mSec ( CA-1 reset and half shoot pulses )
		- does not set virtual switch states
		- hand shake mechanism with control modules is simply them clearing the report pulse width value
		- might be useful for gentles modules or some custom microcontroller device
  ---------------------------------------------------------------------------------------------------*/
void usb_pulse_count_device(int usb_state)
{
	int pc ;

	switch( driver_state )
	{
		case SW_RESET :
			virtual_remote_state = REMOTE_RESET ;
			driver_state = SW_IDLE ;
			break ;

		case SW_IDLE :
			pc = get_usb_power(3) ;
			if ( pc != 0) virtual_remote_pulse_count  = pc ;
			break ;

		default :
			debug_error(INVALID_STATE) ;
			break ;
	}

} ;

 /*===================================================================================================

    Input Driver Jump Table

   ===================================================================================================*/


void usb_null_driver(int i) { return ; } ;

void (*usb_driver[NUM_USB_INPUT_DRV])(int) = 					 // jump table for input drivers - must match gui_USB_switch_types[] in gui.c
	{
			usb_null_driver ,
			usb_one_press_switch ,
			usb_two_press_switch ,
			usb_ricoh_ca1_switch ,
			usb_pwm_device ,
			usb_pulse_count_device ,
			usb_null_driver ,
			usb_null_driver ,
			usb_null_driver ,
			usb_null_driver
	};
