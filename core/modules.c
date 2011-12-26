/*
 *   CHDK-FLAT Module System.  
 *
 *   (c)2011 Sergey Taranenko aka tsvstar
 *
 *   Specific "shortcuts", dynamic libraries binding
 */

#include "modules.h"
#include "module_load.h"
#include "camera.h"
#include "stdlib.h"
#include "conf.h"
#include "gui_draw.h"
#include "dng.h"

/************* DYNAMIC LIBRARY RAWOPERATION ******/

int (*raw_merge_start)(int action);
void (*raw_merge_add_file)(const char * filename);
void (*raw_merge_end)(void);
int (*raw_subtract)(const char *from, const char *sub, const char *dest); 

#if CAM_SENSOR_BITS_PER_PIXEL==10
#define MODULE_NAME_RAWOP "_rawop10.flt"
#elif CAM_SENSOR_BITS_PER_PIXEL==12
#define MODULE_NAME_RAWOP "_rawop12.flt"
#else 
 #error define set_raw_pixel for sensor bit depth
#endif

// This is to minimize sharing sym to use this lib in other modules
struct librawop_sym librawop;

static int bind_module_rawop( void** export_list )
{
	  // Unbind
	if ( !export_list ) {
		librawop.raw_merge_start =0;
		librawop.raw_merge_add_file =0;
		librawop.raw_merge_end =0;
		librawop.raw_subtract =0;
    	return 0;
  	}

	// Bind
	if ( (unsigned int)export_list[0] != EXPORTLIST_MAGIC_NUMBER )
	     return 1;
  	if ( (unsigned int)export_list[1] <6 )
    	 return 1;

	librawop.raw_merge_start = export_list[2];
	librawop.raw_merge_add_file = export_list[3];
	librawop.raw_merge_end = export_list[4];
	librawop.raw_subtract = export_list[5];
	return 0;
}

void module_rawop_unload()
{
	if (librawop.raw_merge_start==0)
    	return;

	module_unload(MODULE_NAME_RAWOP);  
}


// Return: 0-fail, otherwise - bind list
struct librawop_sym* module_rawop_load()
{
  static int module_idx=-1;

  if (librawop.raw_merge_start)
     return &librawop;

  module_idx=module_load(MODULE_NAME_RAWOP, bind_module_rawop );
  if ( module_idx<0 ) {
	 module_unload(MODULE_NAME_RAWOP);  
  }


  return (librawop.raw_merge_start)?&librawop:0 ;
}



/************* DYNAMIC LIBRARY EDGE OVERLAY ******/

#define MODULE_NAME_EDGEOVR "edgeovr.flt"

void (*edge_overlay)();
void (*save_edge_overlay)(void);
void (*load_edge_overlay)( const char* );

static int bind_module_edgeovr( void** export_list )
{
	  // Unbind
	if ( !export_list ) {
		edge_overlay =0;
		save_edge_overlay =0;
		load_edge_overlay =0;
    	return 0;
  	}

	// Bind
	if ( (unsigned int)export_list[0] != EXPORTLIST_MAGIC_NUMBER )
	     return 1;
  	if ( (unsigned int)export_list[1] <5 )
    	 return 1;

	edge_overlay = export_list[2];
	save_edge_overlay = export_list[3];
	load_edge_overlay = export_list[4];
	return 0;
}

// Return: 0-fail, 1-ok
int module_edgeovr_load()
{
  if (edge_overlay)
     return 1;

  // This flag is because edgeovr called each tick
  //   If module loading failed, then do not try to load it until reboot
  //    (otherwise we will try to load module each tick)
  static int flag_load_fail = 0;
  static int module_idx=-1;

  if ( flag_load_fail==0 )
  {
    module_idx=module_load(MODULE_NAME_EDGEOVR, bind_module_edgeovr );
	if ( module_idx<0 ) {
		flag_load_fail = 1;
		module_unload(MODULE_NAME_EDGEOVR);  
	}
	else {
		// This library never unloaded once it is loaded
		// Reason - it should keep its data during whole session
	 	module_set_flags(module_idx, MODULE_FLAG_DISABLE_AUTOUNLOAD);
	}
  }

  return (edge_overlay==0)?0:1;
}



/************* DYNAMIC LIBRARY CURVES ******/

#define MODULE_NAME_CURVES "curves.flt"

void (*curve_set_mode)();
void (*curve_init_mode)();
void (*curve_apply)();


static int bind_module_curves( void** export_list )
{
	  // Unbind
	if ( !export_list ) {
		curve_set_mode =0;
		curve_init_mode =0;
		curve_apply =0;
    	return 0;
  	}

	// Bind
	if ( (unsigned int)export_list[0] != EXPORTLIST_MAGIC_NUMBER )
	     return 1;
  	if ( (unsigned int)export_list[1] <5 )
    	 return 1;

	curve_set_mode = export_list[2];
	curve_init_mode = export_list[3];
	curve_apply = export_list[4];
	return 0;
}

// Return: 0-fail, 1-ok
int module_curves_load()
{

  if (curve_apply)
     return 1;

  static int module_idx=-1;

  module_idx=module_load(MODULE_NAME_CURVES, bind_module_curves );
  if ( module_idx<0 )
		module_unload(MODULE_NAME_CURVES);  
  else {
	// This library never unloaded once it is loaded
	// Reason - changing mode mode from LUA stored inside module only
	module_set_flags(module_idx, MODULE_FLAG_DISABLE_AUTOUNLOAD);

	// Initialize - in module
	// curve_init_mode();
  }

  return (curve_apply==0)?0:1;
}


/************* MODULE PALETTE ******/

void module_palette_run(int mode, color st_color, void (*on_select)(color clr))
{
	unsigned int argv[] = {	mode,
							(unsigned int)st_color,
							(unsigned int)on_select };
    module_run("palette.flt", 0, sizeof(argv)/sizeof(argv[0]), argv,  UNLOAD_IF_ERR);
}


/************* MODULE MPOPUP ******/

void module_mpopup_init(struct mpopup_item* popup_actions, const unsigned int flags, void (*on_select)(unsigned int actn), int mode)
{
	unsigned int argv[] = {	(unsigned int)popup_actions,
							(unsigned int)flags,
							(unsigned int)on_select,
							(unsigned int)mode,
							 };
    module_run("mpopup.flt", 0, sizeof(argv)/sizeof(argv[0]), argv,  UNLOAD_IF_ERR);
}


/************* MODULE FSELECT ******/

void module_fselect_init_w_mode(int title, const char* prev_dir, const char* default_dir, void (*on_select)(const char *fn), unsigned int key_redraw_mode)
{
	unsigned int argv[] = {	title,
							(unsigned int)prev_dir,
							(unsigned int)default_dir,
							(unsigned int)on_select,
							(unsigned int)key_redraw_mode,
							 };
    module_run("fselect.flt", 0,  sizeof(argv)/sizeof(argv[0]), argv, UNLOAD_IF_ERR);
}

void module_fselect_init(int title, const char* prev_dir, const char* default_dir, void (*on_select)(const char *fn))
{
	module_fselect_init_w_mode(title, prev_dir, default_dir, on_select, 0/*key_redraw_mode*/);
}



/************* MODULE DNG ******/

#define MODULE_NAME_DNG "_dng.flt"

// This is to keep module in memory while it required by anyone
static int module_dng_semaphore;

struct libdng_sym libdng;

#if DNG_SUPPORT
static int bind_module_dng( void** export_list )
{
	  // Unbind
	if ( !export_list ) {
		memset(&libdng, 0, sizeof(libdng));
    	return 0;
  	}

	// Bind
	if ( (unsigned int)export_list[0] != EXPORTLIST_MAGIC_NUMBER )
	     return 1;
  	if ( (unsigned int)export_list[1] < 9 )
    	 return 1;

	libdng.size = ((int)export_list[1])-2;
	libdng.create_badpixel_bin=export_list[2];
	libdng.raw_init_badpixel_bin=export_list[3];
	libdng.capture_data_for_exif=export_list[4];
	libdng.load_bad_pixels_list_b=export_list[5];
	libdng.badpixel_list_loaded_b=export_list[6];

	libdng.convert_dng_to_chdk_raw=export_list[7];
	libdng.write_dng=export_list[8];
	return 0;
}
#endif

void module_dng_unload(int owner)
{
#if DNG_SUPPORT
	if (libdng.create_badpixel_bin==0)
    	return;

  	module_dng_semaphore&=~owner;
	if (module_dng_semaphore)
		return;

	module_unload(MODULE_NAME_DNG);  
#endif
}


// Return: 0-fail, otherwise - bind list
struct libdng_sym* module_dng_load(int owner)
{
#if DNG_SUPPORT
  static int module_idx=-1;

  module_dng_semaphore|=owner;
  if (libdng.create_badpixel_bin)
     return &libdng;

  module_idx=module_load(MODULE_NAME_DNG, bind_module_dng );
  if ( module_idx<0 ) {
	 module_unload(MODULE_NAME_DNG);  
  	 module_dng_semaphore=0;
  }
  else {
	 // This module could be unloaded only manualy (because store badpixel)
	 module_set_flags(module_idx, MODULE_FLAG_DISABLE_AUTOUNLOAD);
  }

  return (libdng.create_badpixel_bin)?&libdng:0 ;
#else
  return 0;
#endif
}

// Make convertion or check operation exsitsing
// Parameter: fn = filename or 0 to just check is operation possible
// Return: 0-fail, 1-ok
//--------------------------------------------------------
int module_convert_dng_to_chdk_raw(char* fn)
{
#if DNG_SUPPORT
	if ( fn==0 )
		return module_check_is_exist(MODULE_NAME_DNG);
	if ( !module_dng_load(LIBDNG_OWNED_BY_CONVERT) )
		return 0;
	libdng.convert_dng_to_chdk_raw(fn);
	module_dng_unload(LIBDNG_OWNED_BY_CONVERT);
	return 1;
#else
	return 0;
#endif
}
