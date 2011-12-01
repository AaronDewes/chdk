#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"


extern long link_bss_start;
extern long link_bss_end;
extern void boot();


void startup()
{

	long *bss = &link_bss_start;
	long *ptr;

	// sanity check
	if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)){
		started();
		shutdown();
	}

	// initialize .bss senment
	while (bss<&link_bss_end)
		*bss++ = 0;

	boot();
}

// Focus length table in firmware @0xfffea288
#define NUM_FL 60		// 0 - 59, entries in firmware (3 words each entry, first is FL)
extern int focus_len_table[NUM_FL*3];


// Focal length range is 4.3 - 21.5 mm, 24 - 120 in 35-mm equivalent.
// So, CF_EFL = 21.5/4.3*10000=50000 or 120/24*10000=50000
// divide by 10 to avoid overflow in get_effective_focal_length()
#define CF_EFL  5000
const int zoom_points = 60;

int get_effective_focal_length(int zp) {
	return (CF_EFL*get_focal_length(zp))/1000;
}

int get_focal_length(int zp) {
	if (zp < 0) zp = 0;
	else if (zp >= NUM_FL) zp = NUM_FL-1;
	return focus_len_table[zp*3];
	
}

int get_zoom_x(int zp) {
	return get_focal_length(zp)*10/focus_len_table[0];
}


long get_vbatt_min()
{
	return 3280;  // min observed was 3.408, then it died
}

long get_vbatt_max()
{
	return 4057;  // fresh from change (actual was 4.127)
}
