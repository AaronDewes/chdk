/*
 * Copyright (c) 2006, Adam Dunkels
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the author nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#if DEBUG
#define DEBUG_PRINTF(...)  printf(__VA_ARGS__)
#else
#define DEBUG_PRINTF(...)
#endif

#ifdef UBASIC_TEST
#include "../../include/ubasic.h"
#include "../../include/platform.h"
#include "../../include/script.h"
#include "../../include/shot_histogram.h"
#include "../../include/levent.h"
#include "../../include/console.h"
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <io.h>
#include <stdlib.h> /* rand,srand */
#include "camera_functions.h"
#else
#include "ubasic.h"
#include "platform.h"
#include "script.h"
#include "camera.h"
#include "shot_histogram.h"
#include "stdlib.h"
#include "levent.h"
#include "console.h"
#include "../../core/modules.h"
#endif
#include "../../core/action_stack.h"
#include "tokenizer.h"

#include "../../include/conf.h"

#define INCLUDE_OLD_GET__SYNTAX

#ifdef DEBUG
#include <stdio.h>
#endif

static char const *program_ptr;
#define MAX_STRINGLEN 40
static char string[MAX_STRINGLEN];

#define MAX_GOSUB_STACK_DEPTH 10
static short gosub_stack[MAX_GOSUB_STACK_DEPTH];
static int gosub_stack_ptr;

#define MAX_IF_STACK_DEPTH 4
static short if_stack[MAX_IF_STACK_DEPTH];
static int if_stack_ptr;

struct select_state {
  int select_value;
  short case_run;
};
#define MAX_SELECT_STACK_DEPTH 4
static struct select_state select_stack[MAX_SELECT_STACK_DEPTH];
static int select_stack_ptr;

#define MAX_WHILE_STACK_DEPTH 4
static short while_stack[MAX_WHILE_STACK_DEPTH];
static int while_stack_ptr;

#define MAX_DO_STACK_DEPTH 4
static short do_stack[MAX_DO_STACK_DEPTH];
static int do_stack_ptr;

struct for_state {
  short line_after_for;
  short for_variable;
  int to;
  int step;
};
#define MAX_FOR_STACK_DEPTH 4
static struct for_state for_stack[MAX_FOR_STACK_DEPTH];
static int for_stack_ptr;

#define MAX_VARNUM 52
static int variables[MAX_VARNUM];

static int ended;

static int ubasic_md_ret_var_num;

static int expr(void);
static void line_statement(void);
static void statement(void);
static int relation(void);

/*
ubasic scheduling controls
ubasic returns control to kbd_task as soon as either of the following is is exceeded
defaults is 1 ubasic line per kbd_task cycle, mimicing old behavior
*/
#define YIELD_MAX_LINES_DEFAULT 1
#define YIELD_MAX_MS_DEFAULT 10
// maximum number lines before yielding (labels, blank lines and REMs excluded)
static unsigned yield_max_lines;
// maximum number of ticks before yielding
static unsigned yield_max_ms;
// set flag to immediately transfer execution flow to main CHDK to process external action
// TODO a better approach to this might be to check if AS_RUN is on top of the action_stack
static int flag_yield;

int ubasic_error;
const char *ubasic_errstrings[UBASIC_E_ENDMARK] =
{
    "No err",
    "Parse err",
    "Unk stmt",
    "Unk key",
    "Unk label",
    "gosub: Stack ful",
    "bad return",
    "if: Stack ful",
    "bad endif",
    "select: Stack ful",
    "bad end_select",
    "for: Stack ful",
    "bad next",
    "do: Stack ful",
    "bad until",
    "while: Stack ful",
    "bad wend",
    "Unk err"
};

/*---------------------------------------------------------------------------*/
int
ubasic_linenumber()
{
  return tokenizer_line_number();
}

/*---------------------------------------------------------------------------*/
void
ubasic_init(const char *program)
{
  program_ptr = program;
  flag_yield = 0;
  for_stack_ptr = gosub_stack_ptr = while_stack_ptr = do_stack_ptr = if_stack_ptr = select_stack_ptr = 0;
  tokenizer_init(program);
  ended = 0;
  ubasic_error = UBASIC_E_NONE;
  yield_max_lines = YIELD_MAX_LINES_DEFAULT;
  yield_max_ms = YIELD_MAX_MS_DEFAULT;
}
/*---------------------------------------------------------------------------*/
// read a key name and return key id, 
// set error and return 0 if key invalid
static int ubasic_get_key_arg() {
  int k;
  tokenizer_string(string, sizeof(string));
  tokenizer_next();
  k = script_keyid_by_name(string);
  if (k <= 0)
    ubasic_error = UBASIC_E_UNK_KEY;
  return k;
}
/*---------------------------------------------------------------------------*/
static void
accept(int token)
{
  if(token != tokenizer_token()) {
    DEBUG_PRINTF("Token not what was expected (expected %d, got %d)\n",
		 token, tokenizer_token());
    tokenizer_error_print();
     tokenizer_next();
     ended = 1;
     ubasic_error = UBASIC_E_PARSE;
     return;
  }
  DEBUG_PRINTF("Expected %d, got it\n", token);
  tokenizer_next();
}
/*---------------------------------------------------------------------------*/
static void
accept_cr()
{
    while(tokenizer_token() != TOKENIZER_CR &&
	    tokenizer_token() != TOKENIZER_ENDOFINPUT)
      tokenizer_next();
    accept(TOKENIZER_CR);
}
/*---------------------------------------------------------------------------*/
static int
varfactor(void)
{
  int r;
  DEBUG_PRINTF("varfactor: obtaining %d from variable %d\n", variables[tokenizer_variable_num()], tokenizer_variable_num());
  r = ubasic_get_variable(tokenizer_variable_num());
  accept(TOKENIZER_VARIABLE);
  return r;
}
/*---------------------------------------------------------------------------*/
static int
factor(void)
{
  int r = 0;
  tConfigVal configVal;

  DEBUG_PRINTF("factor: token %d\n", tokenizer_token());
  switch(tokenizer_token()) {
  case TOKENIZER_NUMBER:
    r = tokenizer_num();
    DEBUG_PRINTF("factor: number %d\n", r);
    accept(TOKENIZER_NUMBER);
    break;
  case TOKENIZER_LEFTPAREN:
    accept(TOKENIZER_LEFTPAREN);
    r = relation();
    accept(TOKENIZER_RIGHTPAREN);
    break;
  case TOKENIZER_PLUS:
    accept(TOKENIZER_PLUS);
    r = factor();
    break;
  case TOKENIZER_MINUS:
    accept(TOKENIZER_MINUS);
    r = - factor();
    break;
  case TOKENIZER_LNOT:
    accept(TOKENIZER_LNOT);
    r = ! relation();
    break;
  case TOKENIZER_GET_VBATT:
    accept(TOKENIZER_GET_VBATT);
    r = (unsigned short) stat_get_vbatt();
    break;
 case TOKENIZER_GET_DAY_SECONDS:
    accept(TOKENIZER_GET_DAY_SECONDS);
    r = shooting_get_day_seconds();
    break;
 case TOKENIZER_GET_TICK_COUNT:
    accept(TOKENIZER_GET_TICK_COUNT);
    r = shooting_get_tick_count();
   break;
 case TOKENIZER_GET_MODE:
    accept(TOKENIZER_GET_MODE);
    int m=mode_get()&MODE_SHOOTING_MASK;
    int mode_video=MODE_IS_VIDEO(m);
    if ((mode_get()&MODE_MASK) != MODE_PLAY) r = 0;
    if ((mode_get()&MODE_MASK) == MODE_PLAY) r = 1;
    if (((mode_get()&MODE_MASK) != MODE_PLAY) && mode_video) r = 2;
   break;
 case TOKENIZER_GET_RAW_NR:
    accept(TOKENIZER_GET_RAW_NR);
    r = camera_get_nr();
    break;
 case TOKENIZER_IS_KEY:
    accept(TOKENIZER_IS_KEY);
    r = script_key_is_clicked(ubasic_get_key_arg());
    break;
case TOKENIZER_SCRIPT_AUTOSTARTED:
    accept(TOKENIZER_SCRIPT_AUTOSTARTED);
    r = camera_get_script_autostart();
    break;
case TOKENIZER_GET_SCRIPT_AUTOSTART:
    accept(TOKENIZER_GET_SCRIPT_AUTOSTART);
#ifdef UBASIC_TEST
	r = 0;
#else
    r = conf.script_startup;
#endif
    break;
case TOKENIZER_GET_USB_POWER:
    accept(TOKENIZER_GET_USB_POWER);
	int usbpwr = 0 ;
	if (tokenizer_token() != TOKENIZER_CR &&
        tokenizer_token() != TOKENIZER_ELSE ) {
        usbpwr = expr();
    }
    r = get_usb_power(usbpwr);
    break;
case TOKENIZER_GET_EXP_COUNT:
    accept(TOKENIZER_GET_EXP_COUNT);
    r = get_exposure_counter();
    break;
case TOKENIZER_IS_PRESSED:
    accept(TOKENIZER_IS_PRESSED);
    r = script_key_is_pressed(ubasic_get_key_arg());
    break;
  case TOKENIZER_RANDOM:
    accept(TOKENIZER_RANDOM);
    int min = expr();
    int max = expr();
    // shouldn't srand every time...
    srand((int)shooting_get_bv96()+(unsigned short)stat_get_vbatt()+get_tick_count());
    // wtf
    action_push_delay(rand()%10);
    flag_yield=1;
    r = min + rand()%(max-min+1);
  break;
  case TOKENIZER_GET_MOVIE_STATUS:
    accept(TOKENIZER_GET_MOVIE_STATUS);
    r = movie_status;
   break;
  case TOKENIZER_GET_PLATFORM_ID:
    accept(TOKENIZER_GET_PLATFORM_ID);
    r = PLATFORMID;
   break;
  case TOKENIZER_GET_DRIVE_MODE:
    accept(TOKENIZER_GET_DRIVE_MODE);
    r = shooting_get_drive_mode();
   break;
  case TOKENIZER_GET_FOCUS_MODE:
    accept(TOKENIZER_GET_FOCUS_MODE);
    r = shooting_get_focus_mode();
   break;
 	case TOKENIZER_GET_DISPLAY_MODE:
    accept(TOKENIZER_GET_DISPLAY_MODE);
    r = shooting_get_display_mode();
   break;
  case TOKENIZER_GET_FLASH_MODE:
    accept(TOKENIZER_GET_FLASH_MODE);
    r = shooting_get_flash_mode();
   break;
  case TOKENIZER_GET_SHOOTING:
    accept(TOKENIZER_GET_SHOOTING);
    r = shooting_in_progress();
   break;
  case TOKENIZER_GET_FLASH_READY:
    accept(TOKENIZER_GET_FLASH_READY);
    r = shooting_is_flash();
   break;
  case TOKENIZER_GET_IS_MODE:
    accept(TOKENIZER_GET_IS_MODE);
    r = shooting_get_is_mode();
   break;
  case TOKENIZER_GET_EV:
    accept(TOKENIZER_GET_EV);
    r = shooting_get_ev_correction1();
   break;
  case TOKENIZER_GET_RESOLUTION:
    accept(TOKENIZER_GET_RESOLUTION);
    r = shooting_get_resolution();
   break;
  case TOKENIZER_GET_QUALITY:
    accept(TOKENIZER_GET_QUALITY);
    r = shooting_get_prop(PROPCASE_QUALITY);
   break;
  case TOKENIZER_GET_ORIENTATION_SENSOR:
    accept(TOKENIZER_GET_ORIENTATION_SENSOR);
    r = shooting_get_prop(PROPCASE_ORIENTATION_SENSOR);
   break;
  case TOKENIZER_GET_ZOOM_STEPS:
    accept(TOKENIZER_GET_ZOOM_STEPS);
    r = zoom_points;
   break;
  case TOKENIZER_GET_ND_PRESENT:
    accept(TOKENIZER_GET_ND_PRESENT);
    #if !CAM_HAS_ND_FILTER
    r = 0;
    #endif
    #if CAM_HAS_ND_FILTER && !CAM_HAS_IRIS_DIAPHRAGM
    r = 1;
    #endif
    #if CAM_HAS_ND_FILTER && CAM_HAS_IRIS_DIAPHRAGM
    r = 2;
    #endif
   break;
  case TOKENIZER_GET_PROPSET:
    accept(TOKENIZER_GET_PROPSET);
    r = CAM_PROPSET;
   break;
  case TOKENIZER_GET_TV96:
    accept(TOKENIZER_GET_TV96);
    r = shooting_get_tv96();
    break;
  case TOKENIZER_GET_USER_TV96:
    accept(TOKENIZER_GET_USER_TV96);
    r = shooting_get_user_tv96();
    break;
  case TOKENIZER_GET_USER_TV_ID:
    accept(TOKENIZER_GET_USER_TV_ID);
    r = shooting_get_user_tv_id();
    break;
  case TOKENIZER_GET_AV96:
    accept(TOKENIZER_GET_AV96);
    r = shooting_get_av96();
    break;
  case TOKENIZER_GET_USER_AV96:
    accept(TOKENIZER_GET_USER_AV96);
    r = shooting_get_user_av96();
    break;
  case TOKENIZER_GET_USER_AV_ID:
    accept(TOKENIZER_GET_USER_AV_ID);
    r = shooting_get_user_av_id();
    break;
  case TOKENIZER_GET_ZOOM:
    accept(TOKENIZER_GET_ZOOM);
    r = shooting_get_zoom();
    break;
  case TOKENIZER_GET_FOCUS:
    accept(TOKENIZER_GET_FOCUS);
    r = shooting_get_subject_distance();
    break;
  case TOKENIZER_GET_NEAR_LIMIT:
    accept(TOKENIZER_GET_NEAR_LIMIT);
    r = shooting_get_near_limit_of_acceptable_sharpness();
    break;
  case TOKENIZER_GET_FAR_LIMIT:
    accept(TOKENIZER_GET_FAR_LIMIT);
    r = shooting_get_far_limit_of_acceptable_sharpness();
    break;
   case TOKENIZER_GET_DOF:
    accept(TOKENIZER_GET_DOF);
    r = shooting_get_depth_of_field();
    break;
  case TOKENIZER_GET_HYPERFOCAL_DIST:
    accept(TOKENIZER_GET_HYPERFOCAL_DIST);
    r = shooting_get_hyperfocal_distance();
    break;
  case TOKENIZER_GET_ISO_MARKET:
    accept(TOKENIZER_GET_ISO_MARKET);
    r = (int)shooting_get_iso_market();
    break;
  case TOKENIZER_GET_ISO_REAL:
    accept(TOKENIZER_GET_ISO_REAL);
    r = (int)shooting_get_iso_real();
    break;
  case TOKENIZER_GET_BV96:
    accept(TOKENIZER_GET_BV96);
    r = (int)shooting_get_bv96();
    break;
  case TOKENIZER_GET_SV96:
    accept(TOKENIZER_GET_SV96);
    r = (int)shooting_get_sv96();
    break;
  case TOKENIZER_GET_ISO_MODE:
    accept(TOKENIZER_GET_ISO_MODE);
    r = shooting_get_iso_mode();
    break;
  case TOKENIZER_GET_DISK_SIZE:
    accept(TOKENIZER_GET_DISK_SIZE);
    r = GetTotalCardSpaceKb();
    break;
  case TOKENIZER_GET_FREE_DISK_SPACE:
    accept(TOKENIZER_GET_FREE_DISK_SPACE);
    r = GetFreeCardSpaceKb();
    break;

  case TOKENIZER_GET_JPG_COUNT:
    accept(TOKENIZER_GET_JPG_COUNT);
    r = GetJpgCount();
    break;
  case TOKENIZER_GET_VIDEO_BUTTON:
    accept(TOKENIZER_GET_VIDEO_BUTTON);
    #if CAM_HAS_VIDEO_BUTTON
    r = 1;
    #else
    r = 0;
    #endif
    break;
  case TOKENIZER_GET_RAW_COUNT:
    accept(TOKENIZER_GET_RAW_COUNT);
    r = GetRawCount();
    break;
  case TOKENIZER_GET_PROP:
    accept(TOKENIZER_GET_PROP);
    int var = expr();
    r = shooting_get_prop(var);
    break;
  case TOKENIZER_GET_HISTO_RANGE:
    accept(TOKENIZER_GET_HISTO_RANGE);
    int from = expr();
    int to = expr();
    if (shot_histogram_isenabled()) r = (unsigned short)shot_histogram_get_range(from, to);
    else r = -1;
    break;
  case TOKENIZER_GET_TEMPERATURE:
    accept(TOKENIZER_GET_TEMPERATURE);
    int temp = expr();
    switch (temp)
    {
    	case 0:
    		r = get_optical_temp();
    		break;
     	case 1:
    		r = get_ccd_temp();
    		break;
    	case 2:
    		r = get_battery_temp();
    		break;
		default: // do something sane if given a bad index
			r = 0;
  }
    break;
  case TOKENIZER_GET_TIME: {
      accept(TOKENIZER_GET_TIME);
      int tmode = expr();
      static struct tm *ttm;
      ttm = get_localtime();
      if (tmode==0) r = ttm->tm_sec;
      else if (tmode==1) r = ttm->tm_min;
      else if (tmode==2) r = ttm->tm_hour;
      else if (tmode==3) r = ttm->tm_mday;
      else if (tmode==4) r = ttm->tm_mon+1;
      else if (tmode==5) r = 1900+ttm->tm_year;
      break;
 }
 case TOKENIZER_GET_RAW:
    accept(TOKENIZER_GET_RAW);
#ifdef UBASIC_TEST
	r = 1;
#else
    r = conf.save_raw;
#endif
    break;
 // get CHDK capture mode value, or 0 if in playback or unknown (broken modemap)
 // NOTE: different from get_mode, since this returns the actual value
 case TOKENIZER_GET_CAPTURE_MODE:
    accept(TOKENIZER_GET_CAPTURE_MODE);
    r = mode_get();
    if ( (r&MODE_MASK) == MODE_REC)
        r &= MODE_SHOOTING_MASK;
    else
        r = 0;
    break;
 // check if CHDK capture mode exists in modemap of this camera
 case TOKENIZER_IS_CAPTURE_MODE_VALID: {
    accept(TOKENIZER_IS_CAPTURE_MODE_VALID);
    int modenum = expr();
    if (shooting_mode_chdk2canon(modenum) == -1)
        r = 0;
    else
        r = 1;
    break;
case TOKENIZER_GET_CONFIG_VALUE:
    accept(TOKENIZER_GET_CONFIG_VALUE);
    int var1 = expr();
    int var2 = expr();
    if( conf_getValue(var1, &configVal) == CONF_VALUE) r = configVal.numb; else r = var2;
    break;
  }
  default:
    r = varfactor();
    break;
  }
  return r;
}
/*---------------------------------------------------------------------------*/
static int
term(void)
{
  int f1, f2;
  int op;

  f1 = factor();
  op = tokenizer_token();
  DEBUG_PRINTF("term: token %d\n", op);
  while(op == TOKENIZER_ASTR ||
	op == TOKENIZER_SLASH ||
	op == TOKENIZER_LT ||
	op == TOKENIZER_GT ||
	op == TOKENIZER_GE ||
	op == TOKENIZER_LE ||
	op == TOKENIZER_NE ||
	op == TOKENIZER_EQ ||
	op == TOKENIZER_XOR ||
        op == TOKENIZER_OR ||
	op == TOKENIZER_MOD) {
    tokenizer_next();
    f2 = factor();
    DEBUG_PRINTF("term: %d %d %d\n", f1, op, f2);
    switch(op) {
    case TOKENIZER_ASTR:
      f1 = f1 * f2;
      break;
    case TOKENIZER_SLASH:
      f1 = f1 / f2;
      break;
    case TOKENIZER_MOD:
      f1 = f1 % f2;
      break;
    case TOKENIZER_LT:
      f1 = f1 < f2;
      break;
    case TOKENIZER_GT:
      f1 = f1 > f2;
      break;
    case TOKENIZER_EQ:
      f1 = f1 == f2;
      break;
    case TOKENIZER_NE:
      f1 = f1 != f2;
      break;
    case TOKENIZER_LE:
      f1 = f1 <= f2;
      break;
    case TOKENIZER_GE:
      f1 = f1 >= f2;
      break;
    case TOKENIZER_OR:
      f1 = f1 | f2;
      break;
    case TOKENIZER_XOR:
      f1 = f1 ^ f2;
      break;
    }
    op = tokenizer_token();
  }
  DEBUG_PRINTF("term: %d\n", f1);
  return f1;
}
/*---------------------------------------------------------------------------*/
static int
expr(void)
{
  int t1, t2;
  int op;

  t1 = term();
  op = tokenizer_token();
  DEBUG_PRINTF("expr: token %d\n", op);
  while(op == TOKENIZER_PLUS ||
	op == TOKENIZER_MINUS ||
	op == TOKENIZER_AND ||
        op == TOKENIZER_LOR ||
	op == TOKENIZER_XOR) {
    tokenizer_next();
    t2 = term();
    DEBUG_PRINTF("expr: %d %d %d\n", t1, op, t2);
    switch(op) {
    case TOKENIZER_PLUS:
      t1 = t1 + t2;
      break;
    case TOKENIZER_MINUS:
      t1 = t1 - t2;
      break;
    case TOKENIZER_AND:
      t1 = t1 & t2;
      break;
    case TOKENIZER_LOR:
      t1 = t1 || t2;
      break;
    }
    op = tokenizer_token();
  }
  DEBUG_PRINTF("expr: %d\n", t1);
  return t1;
}
/*---------------------------------------------------------------------------*/
static int
relation(void)
{
  int r1, r2;
  int op;

  r1 = expr();
  op = tokenizer_token();
  DEBUG_PRINTF("relation: token %d\n", op);
  while(op == TOKENIZER_LAND) {
    tokenizer_next();
    r2 = expr();
    DEBUG_PRINTF("relation: %d %d %d\n", r1, op, r2);
    switch(op) {
    case TOKENIZER_LAND:
      r1 = r1 && r2;
      break;
    }
    op = tokenizer_token();
  }
  return r1;
}

#if 0
/*---------------------------------------------------------------------------*/
static void
jump_linenum(int linenum)
{
  tokenizer_init(program_ptr);
  while(tokenizer_num() != linenum) {
    do {
      do {
	tokenizer_next();
      } while(tokenizer_token() != TOKENIZER_CR &&
	      tokenizer_token() != TOKENIZER_ENDOFINPUT);
      if(tokenizer_token() == TOKENIZER_CR) {
	tokenizer_next();
      }
    } while(tokenizer_token() != TOKENIZER_NUMBER);
    DEBUG_PRINTF("jump_linenum: Found line %d\n", tokenizer_num());
  }
}
#endif

/*---------------------------------------------------------------------------*/
static void
jump_line(int linenum)
{
  tokenizer_init(program_ptr);
  while(tokenizer_line_number() != linenum) {
    tokenizer_next();
  }
  /* swallow the CR that would be read next */
  accept(TOKENIZER_CR);

}
/*---------------------------------------------------------------------------*/
// TODO: error handling?
int
jump_label(char * label)
{
  char currLabel[MAX_STRINGLEN];
  tokenizer_init(program_ptr);
  currLabel[0] = 0;
  while(tokenizer_token() != TOKENIZER_ENDOFINPUT) {
    tokenizer_next();
    if (tokenizer_token() == TOKENIZER_LABEL) {
      tokenizer_label(currLabel, sizeof(currLabel));
      tokenizer_next();
      if(strcmp(label, currLabel) == 0) {
        accept(TOKENIZER_CR);
        DEBUG_PRINTF("jump_linenum: Found line %d\n", tokenizer_line_number());
        break;
      }
    }
  }
  if (tokenizer_token() == TOKENIZER_ENDOFINPUT) {
    if (state_kbd_script_run == 1) {
      DEBUG_PRINTF("Label %s not found", label);
      ubasic_error = UBASIC_E_UNK_LABEL;
    }
      return 0;
  } else {
      return 1;
  }
}
/*---------------------------------------------------------------------------*/
static void
goto_statement(void)
{
  accept(TOKENIZER_GOTO);
  if(tokenizer_token() == TOKENIZER_STRING) {
    tokenizer_string(string, sizeof(string));
    tokenizer_next();
    jump_label(string);
  } else {
    DEBUG_PRINTF("ubasic.c: goto_statement(): no label specified\n");
    ended = 1;
    ubasic_error = UBASIC_E_UNK_LABEL;
  }
}
/*---------------------------------------------------------------------------*/
static void
print_statement(void)
{
  static char buf[128];

  buf[0]=0;
  accept(TOKENIZER_PRINT);
  do {
    DEBUG_PRINTF("Print loop\n");
    if(tokenizer_token() == TOKENIZER_STRING) {
      tokenizer_string(string, sizeof(string));
      sprintf(buf+strlen(buf), "%s", string);
      tokenizer_next();
    } else if(tokenizer_token() == TOKENIZER_COMMA) {
      strcat(buf, " ");
      tokenizer_next();
    } else if(tokenizer_token() == TOKENIZER_SEMICOLON) {
      tokenizer_next();
    } else {
      sprintf(buf+strlen(buf), "%d", expr());
    }
  } while(tokenizer_token() != TOKENIZER_CR && tokenizer_token() != TOKENIZER_ENDOFINPUT && tokenizer_token() != TOKENIZER_ELSE);
  script_console_add_line(buf);
  DEBUG_PRINTF("End of print\n");
  accept_cr();
}
/*---------------------------------------------------------------------------*/
/* IF-STATEMENT                                                              */

static void
endif_statement(void)
{
  if(if_stack_ptr > 0) {
    accept(TOKENIZER_ENDIF);
    accept(TOKENIZER_CR);
    if_stack_ptr--;
  } else {
    DEBUG_PRINTF("ubasic.c: endif_statement(): endif without if-statement\n");
    ended = 1;
    ubasic_error = UBASIC_E_UNMATCHED_IF;
  }
}
/*---------------------------------------------------------------------------*/
static void
if_statement(void)
{
  int r, else_cntr,endif_cntr,f_nt,f_sl;

  accept(TOKENIZER_IF);
  DEBUG_PRINTF("if_statement: get_relation\n");
  r = relation();
  DEBUG_PRINTF("if_statement: relation %d\n", r);
  accept(TOKENIZER_THEN);
  if (ended) {
    return;
  }

  if (tokenizer_token() == TOKENIZER_CR) {
    // CR after then -> multiline IF-Statement
    if(if_stack_ptr < MAX_IF_STACK_DEPTH) {
      if_stack[if_stack_ptr] = r;
      if_stack_ptr++;
    } else {
      DEBUG_PRINTF("if_statement: IF-stack depth exceeded\n");
      ended = 1;
      ubasic_error = UBASIC_E_IF_STACK_EXHAUSTED;
      return;
    }
    DEBUG_PRINTF("if_statement: stack_ptr %d\n", if_stack_ptr);
    accept(TOKENIZER_CR);
    if(r) {
      DEBUG_PRINTF("if_statement: result true\n");
      return;
    }else {
      DEBUG_PRINTF("if_statement: result false\n");

      else_cntr=endif_cntr=0; // number of else/endif possible in current nesting
      f_nt=f_sl=0; // f_nt nested then ?, f_fs flag single line

      while(((tokenizer_token() != TOKENIZER_ELSE &&  tokenizer_token() != TOKENIZER_ENDIF)
           || else_cntr || endif_cntr) && tokenizer_token() != TOKENIZER_ENDOFINPUT){
        f_nt=0;
        // nested if
        if( tokenizer_token() == TOKENIZER_IF) {
          else_cntr+=1;
          endif_cntr+=1;
          f_sl=0;
          DEBUG_PRINTF("IF: line %d, token %d, else %d, end %d\n", tokenizer_line_number(),tokenizer_token(),else_cntr,endif_cntr);
        }
        if( tokenizer_token() == TOKENIZER_THEN) {
          f_nt=1;
          tokenizer_next();
          DEBUG_PRINTF("THEN: line %d, token %d, else %d, end %d\n", tokenizer_line_number(),tokenizer_token(),else_cntr,endif_cntr);
          if (tokenizer_token() != TOKENIZER_CR) {
            f_sl=1;
          }
          DEBUG_PRINTF("THEN_SL: line %d, token %d, else %d, end %d\n", tokenizer_line_number(),tokenizer_token(),else_cntr,endif_cntr);
        }
        if(tokenizer_token() == TOKENIZER_ELSE) {
          else_cntr--;
          DEBUG_PRINTF("ELSE: line %d, token %d, else %d, end %d\n", tokenizer_line_number(),tokenizer_token(),else_cntr,endif_cntr);
          if (else_cntr<0) {
            DEBUG_PRINTF("ubasic.c: if_statement(): else without if-statement\n");
            ended = 1;
            ubasic_error = UBASIC_E_UNMATCHED_IF;
            return;
          }
        }
        if(!f_sl && (tokenizer_token() == TOKENIZER_ENDIF)) {
          endif_cntr--;
          if (endif_cntr != else_cntr)
            else_cntr--;
          DEBUG_PRINTF("ENDIF: line %d, token %d, else %d, end %d\n", tokenizer_line_number(),tokenizer_token(),else_cntr,endif_cntr);
        } else {
          if (f_sl && (tokenizer_token() == TOKENIZER_CR))  {
            f_sl=0;
            endif_cntr--;
            if (endif_cntr != else_cntr)
              else_cntr--;
            DEBUG_PRINTF("ENDIF_SL: line %d, token %d, else %d, end %d\n", tokenizer_line_number(),tokenizer_token(),else_cntr,endif_cntr);
          } else {
            if (tokenizer_token()==TOKENIZER_ENDIF){
              DEBUG_PRINTF("ubasic.c: if_statement(): endif in singleline if-statement\n");
              ended = 1;
              ubasic_error = UBASIC_E_PARSE;
              return;
            }
          }
        }
        if (!f_nt) {
          tokenizer_next();
        }
      }
      if(tokenizer_token() == TOKENIZER_ELSE) {
        return;
      }
    }
    endif_statement();
  }else {
  // Singleline IF-Statement
    if(r) {
      statement();
    } else {
      do {
        tokenizer_next();
      } while(tokenizer_token() != TOKENIZER_ELSE &&
        tokenizer_token() != TOKENIZER_CR &&
        tokenizer_token() != TOKENIZER_ENDOFINPUT);
      if(tokenizer_token() == TOKENIZER_ELSE) {
        accept(TOKENIZER_ELSE);
        statement();
      } else {
        accept(TOKENIZER_CR);
      }
    }
  }
}
/*---------------------------------------------------------------------------*/
static void
else_statement(void)
{
  int r=0, endif_cntr, f_nt;

  accept(TOKENIZER_ELSE);
  if(if_stack_ptr > 0) {
    r = if_stack[if_stack_ptr-1];
  }
  else{
    DEBUG_PRINTF("ubasic.c: else_statement(): else without if-statement\n");
    ended = 1;
    ubasic_error = UBASIC_E_PARSE;
    return;
  }
  DEBUG_PRINTF("else_statement: relation %d\n", r);

  if (tokenizer_token() == TOKENIZER_CR) {
    accept(TOKENIZER_CR);
    if(!r) {
      DEBUG_PRINTF("else_statement: result true\n");
      return;
    } else {
      DEBUG_PRINTF("else_statement: result false\n");
      endif_cntr=0;
      while(((tokenizer_token() != TOKENIZER_ENDIF )
           || endif_cntr) && tokenizer_token() != TOKENIZER_ENDOFINPUT){
        f_nt=0;
        if( tokenizer_token() == TOKENIZER_IF) {
          endif_cntr+=1;
        }
        if( tokenizer_token() == TOKENIZER_THEN) {
          tokenizer_next();
          // then followed by CR -> multi line
          if (tokenizer_token() == TOKENIZER_CR) {
            f_nt=1;
          } else { // single line
            endif_cntr--;
            while(tokenizer_token() != TOKENIZER_ENDIF && tokenizer_token() != TOKENIZER_CR
                 && tokenizer_token() != TOKENIZER_ENDOFINPUT){
              tokenizer_next();
            }
            if (tokenizer_token()==TOKENIZER_ENDIF){
              DEBUG_PRINTF("ubasic.c: else_statement(): endif in singleline if-statement\n");
              ended = 1;
              ubasic_error = UBASIC_E_PARSE;
              return;
            }
          }
        }
        if( tokenizer_token() == TOKENIZER_ENDIF)  {
          endif_cntr--;
        }
        if (!f_nt) {
          tokenizer_next();
        }
      }
    }
    endif_statement();
  }else{
    DEBUG_PRINTF("ubasic.c: else_statement(): CR after ELSE expected\n");
    ended = 1;
    ubasic_error = UBASIC_E_PARSE;
  }
}
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* SELECT-STATEMENT                                                          */

static void
dec_select_stack(void)
{
  if(select_stack_ptr > 0) {
      select_stack_ptr--;
  } else {
    DEBUG_PRINTF("select_statement: SELECT-Stack fail\n");
    ended = 1;
    ubasic_error = UBASIC_E_UNMATCHED_END_SELECT;
  }
}
/*---------------------------------------------------------------------------*/
static void
end_select_statement(void)
{
  if(select_stack_ptr > 0) {
    accept(TOKENIZER_END_SELECT);
    accept(TOKENIZER_CR);
    dec_select_stack();
  } else {
    DEBUG_PRINTF("ubasic.c: end_select_statement(): end_select without select-statement\n");
    ended = 1;
    ubasic_error = UBASIC_E_UNMATCHED_END_SELECT;
  }
}
/*---------------------------------------------------------------------------*/
static void
case_statement(void)
{
  int select_value, case_value_1, case_value_2, case_value_eq;
  short case_run, case_goto = 0, case_gosub = 0;
  int cur_ln, gosub_ln = 0;

  accept(TOKENIZER_CASE);
  if(select_stack_ptr > 0) {
    select_value = select_stack[select_stack_ptr - 1].select_value;
    case_run = select_stack[select_stack_ptr - 1].case_run;

    if (!case_run) {
      case_value_1 = expr();
      case_value_eq = (select_value == case_value_1);
      if (case_value_eq) { DEBUG_PRINTF("case_statement: case_value_eq %d, case_value %d\n", case_value_eq, case_value_1); }

      if(tokenizer_token() == TOKENIZER_TO) {
        accept(TOKENIZER_TO);
        case_value_2 = expr();
        if (case_value_1 < case_value_2) {
          case_value_eq = ((select_value >= case_value_1) && (select_value <= case_value_2));
          DEBUG_PRINTF("case_statement: case_value %d to %d\n", case_value_1, case_value_2);
        } else {
          case_value_eq = ((select_value >= case_value_2) && (select_value <= case_value_1));
          DEBUG_PRINTF("case_statement: case_value %d to %d\n", case_value_2, case_value_1);
        }
      } else if (tokenizer_token() == TOKENIZER_COMMA) {
        do {
          accept(TOKENIZER_COMMA);
          if (case_value_eq) {
            case_value_2 = expr();
          } else {
            case_value_1 = expr();
            case_value_eq = (select_value == case_value_1);
          }
        } while (tokenizer_token() == TOKENIZER_COMMA);
        DEBUG_PRINTF("case_statement: case_value_eq %d, case_value_comma %d\n", case_value_eq, case_value_1);
      }

      accept(TOKENIZER_SEMICOLON);
      if (case_value_eq) {
        case_goto = (tokenizer_token() == TOKENIZER_GOTO);
        case_gosub = (tokenizer_token() == TOKENIZER_GOSUB);
//GOSUB - save curr linenumber
        cur_ln = tokenizer_line_number();
//GOSUB
        statement();
//GOSUB  - save new linenumber, reset to curr linenumber
      if (case_gosub) {
        gosub_ln = tokenizer_line_number();
        jump_line(cur_ln+1);
        DEBUG_PRINTF("case_statement: GOSUB: toLN=%d, nextLN=%d\n", gosub_ln, cur_ln+1);
      }
//GOSUB
        DEBUG_PRINTF("case_statement: case execute\n");
        case_run = 1;
        select_stack[select_stack_ptr - 1].case_run = case_run;
      } else {
        DEBUG_PRINTF("case_statement: case jump; case_run: %d\n", case_run);
        accept_cr();
      }
    } else {accept_cr();}
//REM
    while ((tokenizer_token() == TOKENIZER_REM) && (!case_goto)) {statement();}
//REM
    if (case_goto) { dec_select_stack(); } else {
      if ((tokenizer_token() != TOKENIZER_CASE) && (tokenizer_token() != TOKENIZER_CASE_ELSE) &&
         (tokenizer_token() != TOKENIZER_END_SELECT)) {
         DEBUG_PRINTF("ubasic.c: select_statement(): don't found case, case_else or end_select\n");
         ended = 1;
         ubasic_error = UBASIC_E_PARSE;
      } else {
//GOSUB test for end_select and set to gosub-linenumber
        if (tokenizer_token() == TOKENIZER_END_SELECT) { end_select_statement(); }
        if (case_gosub) {
          gosub_stack[gosub_stack_ptr-1] = tokenizer_line_number();
          jump_line(gosub_ln);
          DEBUG_PRINTF("end_select_statement: GOSUB: returnLN=%d\n", gosub_stack[gosub_stack_ptr-1]);
        }
      }
//GOSUB
    }
  } else {
    DEBUG_PRINTF("case_statement: SELECT-Stack fail\n");
    ended = 1;
    ubasic_error = UBASIC_E_UNMATCHED_END_SELECT;
  }
}
/*---------------------------------------------------------------------------*/
static void
case_else_statement(void)
{
  short case_goto = 0, case_gosub = 0;
  int cur_ln, gosub_ln = 0;

  accept(TOKENIZER_CASE_ELSE);
  if(select_stack_ptr > 0) {
    if (!select_stack[select_stack_ptr - 1].case_run) {
      case_goto = (tokenizer_token() == TOKENIZER_GOTO);
      case_gosub = (tokenizer_token() == TOKENIZER_GOSUB);
//GOSUB - save curr linenumber
      cur_ln = tokenizer_line_number();
//GOSUB
      statement();
//GOSUB  - save new linenumber, reset to curr linenumber
      if (case_gosub) {
        gosub_ln = tokenizer_line_number();
        jump_line(cur_ln+1);
        DEBUG_PRINTF("case_else_statement: GOSUB: toLN=%d, nextLN=%d\n", gosub_ln, cur_ln+1);
      }
//GOSUB
      DEBUG_PRINTF("case_else_statement: case_else execute\n");
    } else {
      DEBUG_PRINTF("case_else_statement: case_else jump; case_run: %d\n", select_stack[select_stack_ptr - 1].case_run);
      accept_cr();
    }
//REM
    while ((tokenizer_token() == TOKENIZER_REM) && (!case_goto)) {statement();}
//REM
    if (case_goto) { dec_select_stack(); } else {
//GOSUB test for end_select and set to gosub-linenumber
      if (tokenizer_token() != TOKENIZER_END_SELECT) {
        DEBUG_PRINTF("ubasic.c: select_statement(): don't found end_select\n");
        ended = 1;
        ubasic_error = UBASIC_E_PARSE;
      } else {
          end_select_statement();
        if (case_gosub) {
          gosub_stack[gosub_stack_ptr-1] = tokenizer_line_number();
          jump_line(gosub_ln);
          DEBUG_PRINTF("end_select_statement: GOSUB: returnLN=%d\n", gosub_stack[gosub_stack_ptr-1]);
        }
      }
//GOSUB
    }
  } else {
    DEBUG_PRINTF("case_else_statement: SELECT-Stack fault\n");
    ended = 1;
    ubasic_error = UBASIC_E_UNMATCHED_END_SELECT;
  }
}
/*---------------------------------------------------------------------------*/
static void
select_statement(void)
{

  int select_value;

  accept(TOKENIZER_SELECT);
  select_value = expr();
  accept(TOKENIZER_CR);
//REM
    while (tokenizer_token() == TOKENIZER_REM) {statement();}
//REM

  if(select_stack_ptr < MAX_SELECT_STACK_DEPTH) {
    select_stack[select_stack_ptr].select_value = select_value;
    select_stack[select_stack_ptr].case_run = 0;
    DEBUG_PRINTF("select_statement: new select, value %d\n",select_stack[select_stack_ptr].select_value);
    select_stack_ptr++;
    if (tokenizer_token() != TOKENIZER_CASE) {
      DEBUG_PRINTF("ubasic.c: select_statement(): don't found case-statement\n");
      ended = 1;
      ubasic_error = UBASIC_E_PARSE;
    }
    else { case_statement(); }
  } else {
    DEBUG_PRINTF("select_statement: SELECT-stack depth exceeded\n");
    ended = 1;
    ubasic_error = UBASIC_E_SELECT_STACK_EXHAUSTED;
  }
}
/* SELECT-STATEMENT END                                                      */
/*---------------------------------------------------------------------------*/
static void
let_statement(void)
{

  int var;

  var = tokenizer_variable_num();

  accept(TOKENIZER_VARIABLE);
  accept(TOKENIZER_EQ);
  ubasic_set_variable(var, expr());
  DEBUG_PRINTF("let_statement: assign %d to %d\n", variables[var], var);
  accept_cr();
}
/*---------------------------------------------------------------------------*/
static void
rem_statement(void)
{
  accept(TOKENIZER_REM);
  DEBUG_PRINTF("rem_statement\n");
  accept(TOKENIZER_CR);
}
/*---------------------------------------------------------------------------*/
static void
cls_statement(void)
{
  accept(TOKENIZER_CLS);
  console_clear();
  DEBUG_PRINTF("cls_statement\n");
  accept(TOKENIZER_CR);
}
/*---------------------------------------------------------------------------*/
static void
gosub_statement(void)
{
  accept(TOKENIZER_GOSUB);
  if(tokenizer_token() == TOKENIZER_STRING) {
    tokenizer_string(string, sizeof(string));
    do {
    tokenizer_next();
    } while(tokenizer_token() != TOKENIZER_CR);
    accept(TOKENIZER_CR);
    if(gosub_stack_ptr < MAX_GOSUB_STACK_DEPTH) {
/*    tokenizer_line_number_inc();*/
      gosub_stack[gosub_stack_ptr] = tokenizer_line_number();
      gosub_stack_ptr++;
      jump_label(string);
    } else {
      DEBUG_PRINTF("gosub_statement: gosub stack exhausted\n");
      ended = 1;
      ubasic_error = UBASIC_E_GOSUB_STACK_EXHAUSTED;
    }
  } else {
    DEBUG_PRINTF("ubasic.c: goto_statement(): no label specified\n");
    ended = 1;
    ubasic_error = UBASIC_E_UNK_LABEL;
  }
}
/*---------------------------------------------------------------------------*/
static void
return_statement(void)
{
  accept(TOKENIZER_RETURN);
  if(gosub_stack_ptr > 0) {
    gosub_stack_ptr--;
    jump_line(gosub_stack[gosub_stack_ptr]);
  } else {
    DEBUG_PRINTF("return_statement: non-matching return\n");
    ended = 1;
    ubasic_error = UBASIC_E_UNMATCHED_RETURN;
  }
}
/*---------------------------------------------------------------------------*/
static void
next_statement(void)
{
  int var, value;

  accept(TOKENIZER_NEXT);
  var = tokenizer_variable_num();
  accept(TOKENIZER_VARIABLE);
  if(for_stack_ptr > 0 &&
     var == for_stack[for_stack_ptr - 1].for_variable) {
    value = ubasic_get_variable(var) + for_stack[for_stack_ptr - 1].step;
    ubasic_set_variable(var, value);

    if(((for_stack[for_stack_ptr - 1].step > 0) && (value <= for_stack[for_stack_ptr - 1].to)) ||
       ((for_stack[for_stack_ptr - 1].step < 0) && (value >= for_stack[for_stack_ptr - 1].to)))
        jump_line(for_stack[for_stack_ptr - 1].line_after_for);
    else {
      for_stack_ptr--;
      accept(TOKENIZER_CR);
    }
  } else {
    DEBUG_PRINTF("next_statement: non-matching next (expected %d, found %d)\n", for_stack[for_stack_ptr - 1].for_variable, var);
    ended = 1;
    ubasic_error = UBASIC_E_UNMATCHED_NEXT;
  }

}
/*---------------------------------------------------------------------------*/
static void
for_statement(void)
{
  int for_variable, to, step;

  accept(TOKENIZER_FOR);
  for_variable = tokenizer_variable_num();
  accept(TOKENIZER_VARIABLE);
  accept(TOKENIZER_EQ);
  ubasic_set_variable(for_variable, expr());
  accept(TOKENIZER_TO);
  to = expr();
  step = 1;
  if (tokenizer_token() != TOKENIZER_CR) {
	  accept(TOKENIZER_STEP);
	  step = expr();
  }
  accept(TOKENIZER_CR);

  if(for_stack_ptr < MAX_FOR_STACK_DEPTH) {
    for_stack[for_stack_ptr].line_after_for = tokenizer_line_number();
    for_stack[for_stack_ptr].for_variable = for_variable;
    for_stack[for_stack_ptr].to = to;
    for_stack[for_stack_ptr].step = step;
    DEBUG_PRINTF("for_statement: new for, var %d to %d\n",
		 for_stack[for_stack_ptr].for_variable,
		 for_stack[for_stack_ptr].to);

    for_stack_ptr++;
  } else {
    DEBUG_PRINTF("for_statement: for stack depth exceeded\n");
    ended = 1;
    ubasic_error = UBASIC_E_FOR_STACK_EXHAUSTED;
  }
}
/*---------------------------------------------------------------------------*/
static void
do_statement(void)
{
  accept(TOKENIZER_DO);
  accept(TOKENIZER_CR);
  if(do_stack_ptr < MAX_DO_STACK_DEPTH) {
     do_stack[do_stack_ptr] = tokenizer_line_number();
     do_stack_ptr++;
  } else {
    DEBUG_PRINTF("do_statement: do stack depth exceeded\n");
    ended = 1;
    ubasic_error = UBASIC_E_DO_STACK_EXHAUSTED;
  }
}
/*---------------------------------------------------------------------------*/
static void
until_statement(void)
{
  int r;

  accept(TOKENIZER_UNTIL);
  r = relation();
  if(do_stack_ptr > 0) {
    if(!r) {
      jump_line(do_stack[do_stack_ptr-1]);
    } else {
      do_stack_ptr--;
  	  accept_cr();
    }
  } else {
    DEBUG_PRINTF("until_statement: unmatched until\n");
    ended = 1;
    ubasic_error = UBASIC_E_UNMATCHED_UNTIL;
  }
}
/*---------------------------------------------------------------------------*/
static void
while_statement(void)
{
  int r, while_cntr;

  accept(TOKENIZER_WHILE);
  if(while_stack_ptr < MAX_WHILE_STACK_DEPTH) {
    if ((while_stack_ptr == 0)||((while_stack_ptr > 0) && (while_stack[while_stack_ptr-1] != tokenizer_line_number()))){
      while_stack[while_stack_ptr] = tokenizer_line_number();
      while_stack_ptr++;
    }
  } else {
    DEBUG_PRINTF("while_statement: while stack depth exceeded\n");
    ended = 1;
    ubasic_error = UBASIC_E_WHILE_STACK_EXHAUSTED;
    return;
  }

  r = relation();
  if(while_stack_ptr > 0) {
    if(!r) {
    	while_cntr=0;
      while((tokenizer_token() != TOKENIZER_WEND  || while_cntr ) &&
	      tokenizer_token() != TOKENIZER_ENDOFINPUT){
	      if (tokenizer_token() == TOKENIZER_WHILE) while_cntr+=1;
	      if (tokenizer_token() == TOKENIZER_WEND) while_cntr-=1;
	      tokenizer_next();
	    }
      while_stack_ptr--;

      accept(TOKENIZER_WEND);
      accept(TOKENIZER_CR);
    } else {
  	  accept_cr();
    }
  } else {
    DEBUG_PRINTF("while_statement: unmatched wend\n");
    ended = 1;
    ubasic_error = UBASIC_E_UNMATCHED_WEND;
  }
}
/*---------------------------------------------------------------------------*/
static void
wend_statement(void)
{
  accept(TOKENIZER_WEND);
  if(while_stack_ptr > 0) {
    jump_line(while_stack[while_stack_ptr-1]);
  } else {
    DEBUG_PRINTF("wend_statement: unmatched wend\n");
    ended = 1;
    ubasic_error = UBASIC_E_UNMATCHED_WEND;
  }
}
/*---------------------------------------------------------------------------*/
static void
end_statement(void)
{
  accept(TOKENIZER_END);
  ended = 1;
}
/*---------------------------------------------------------------------------*/
static void
click_statement(void)
{
  int k;
  accept(TOKENIZER_CLICK);
  k = ubasic_get_key_arg();
  if (k > 0) {
    action_push_click(k);
    flag_yield=1;
  }

  DEBUG_PRINTF("End of click\n");
  accept_cr();
}
/*---------------------------------------------------------------------------*/
static void
press_statement(void)
{
  int k;
  accept(TOKENIZER_PRESS);
  k = ubasic_get_key_arg();
  if (k > 0) {
    action_push_press(k);
    flag_yield=1;
  }
  DEBUG_PRINTF("End of press\n");
  accept_cr();
}
/*---------------------------------------------------------------------------*/
static void
release_statement(void)
{
  int k;
  accept(TOKENIZER_RELEASE);
  k = ubasic_get_key_arg();
  if (k > 0) {
    action_push_release(k);
    flag_yield=1;
  }
  DEBUG_PRINTF("End of release\n");
  accept_cr();
}
/*---------------------------------------------------------------------------*/
static void
sleep_statement(void)
{
  int val;
  accept(TOKENIZER_SLEEP);
  val = expr();
  action_push_delay(val);
  flag_yield=1;
  DEBUG_PRINTF("End of sleep\n");
  accept_cr();
}
/*---------------------------------------------------------------------------*/
static void
shoot_statement(void)
{
  accept(TOKENIZER_SHOOT);
  action_push(AS_SHOOT);
  flag_yield=1;
  DEBUG_PRINTF("End of shoot\n");
  accept_cr();
}
/*---------------------------------------------------------------------------*/
static void set_console_layout(void)
{
  int x1,y1,x2,y2;
  accept(TOKENIZER_SET_CONSOLE_LAYOUT);
  x1 = expr();
  y1 = expr();
  x2 = expr();
  y2 = expr();
  console_set_layout(x1,y1,x2,y2);
  accept_cr();
}
/*---------------------------------------------------------------------------*/
static void set_console_autoredraw(void)
{
  accept(TOKENIZER_SET_CONSOLE_AUTOREDRAW);
  console_set_autoredraw(expr());
  accept_cr();
}
/*---------------------------------------------------------------------------*/
static void console_redraw_statement(void)
{
  accept(TOKENIZER_CONSOLE_REDRAW);
  console_redraw();
  accept_cr();
}
/*---------------------------------------------------------------------------*/

#ifdef INCLUDE_OLD_GET__SYNTAX

// Call 'func' to get a CHDK short value and store in named parameter
static void get_short_var_statement(int token, short (*func)(void))
{
    int var;
    accept(token);
    var = tokenizer_variable_num();
    accept(TOKENIZER_VARIABLE);
    ubasic_set_variable(var, func());
    accept_cr();
}

// Call 'func' to get a CHDK int value and store in named parameter
static void get_int_var_statement(int token, int (*func)(void))
{
    int var;
    accept(token);
    var = tokenizer_variable_num();
    accept(TOKENIZER_VARIABLE);
    ubasic_set_variable(var, func());
    accept_cr();
}

static void get_prop_statement()
{
    int var, var1;
    accept(TOKENIZER_GET_PROP);
    var = expr();
    var1 = tokenizer_variable_num();
    accept(TOKENIZER_VARIABLE);
    ubasic_set_variable(var1, shooting_get_prop(var));

    accept_cr();
}

#endif

// Call CHDK function 'func' with one int parameter
static void one_int_param_function(int token, void (*func)(int))
{
    accept(token);
    func(expr());
    accept_cr();
}

// Call CHDK function 'func' with one short parameter
static void one_short_param_function(int token, void (*func)(short))
{
    accept(token);
    func(expr());
    accept_cr();
}

// Call CHDK function 'func' with one int parameter plus a second value 'p2'
static void one_int_param_plus_const_function(int token, void (*func)(int,short), short p2)
{
    accept(token);
    func(expr(),p2);
    accept_cr();
}

// Call CHDK function 'func' with one short parameter plus a second value 'p2'
static void one_short_param_plus_const_function(int token, void (*func)(short,short), short p2)
{
    accept(token);
    func(expr(),p2);
    accept_cr();
}

/*---------------------------------------------------------------------------*/


static void set_ev_statement()
 	{
 	    int to;
 	    accept(TOKENIZER_SET_EV);
 	    to = expr();
 	        shooting_set_prop(PROPCASE_EV_CORRECTION_1, to);
 	        shooting_set_prop(PROPCASE_EV_CORRECTION_2, to);
 	    accept_cr();
 	}

static void set_movie_status_statement()
{
    int to;
    accept(TOKENIZER_SET_MOVIE_STATUS);
    to = expr();
if (to==1) {
	if (movie_status == 4) {
	movie_status = 1;
}}
if (to==2) {
	if (movie_status == 1) {
	movie_status = 4;
}
}
if (to==3) {
	if (movie_status == 1 || 4) {
	movie_status = 5;
}}


    accept_cr();
}

// Set the property 'prop' value from the next expression
static void set_propcase_statement(int token, int prop)
{
    accept(token);
	shooting_set_prop(prop, expr());
    accept_cr();
}


static void set_focus_statement()
{
    int to;
    accept(TOKENIZER_SET_FOCUS);
    to = expr();
    int m=mode_get()&MODE_SHOOTING_MASK;
	int mode_video=MODE_IS_VIDEO(m);
#if CAM_HAS_MANUAL_FOCUS
    if (shooting_get_focus_mode() || (mode_video)) shooting_set_focus(to, SET_NOW);
    else shooting_set_focus(to, SET_LATER);
#else
    if (mode_video) shooting_set_focus(to, SET_NOW);
    else shooting_set_focus(to, SET_LATER);
#endif
    accept_cr();
}

static void set_led_statement()
{
    int to, to1, to2;
    accept(TOKENIZER_SET_LED);
    to = expr();
    to1 = expr();
	to2 = 200;
	if (tokenizer_token() != TOKENIZER_CR && tokenizer_token() != TOKENIZER_ELSE ) {
		to2 = expr();
    }
	camera_set_led(to, to1, to2);
    accept_cr();
}

static void set_prop_statement()
{
    int to, to1;
    accept(TOKENIZER_SET_PROP);
    to = expr();
    to1 = expr();
	shooting_set_prop(to, to1);
    accept_cr();
}

/*---------------------------------------------------------------------------*/

static void set_autostart_statement()
{
    int to;
    accept(TOKENIZER_SET_SCRIPT_AUTOSTART);
    to = expr();
#ifndef UBASIC_TEST
	if (to >= 0 && to <= 2) conf.script_startup=to;
	conf_save();
#endif
    accept_cr();
}

static void set_capture_mode_canon_statement()
{
    int to;
    accept(TOKENIZER_SET_CAPTURE_MODE_CANON);
    to = expr();
    // if the value as negative, assume it is a mistakenly sign extended PROPCASE_SHOOTING_MODE value
    if( to < 0)
        to &= 0xFFFF;
    shooting_set_mode_canon(to);
    accept_cr();
}

static void reboot_statement() {
    accept(TOKENIZER_REBOOT);
    if(tokenizer_token() == TOKENIZER_STRING) {
      tokenizer_string(string, sizeof(string));
      tokenizer_next();
	  reboot(string);
	} else {
	  reboot(NULL);
	}
}

static void set_config_value_statement()
{
    int id, value;
    tConfigVal configVal = {0,0,0,0};
    
    accept(TOKENIZER_SET_CONFIG_VALUE);
    id = expr();
    value = expr();
    if( conf_getValue(id, &configVal) == CONF_VALUE ) {
        configVal.numb = value;
        configVal.isNumb = 1;
        conf_setValue(id, configVal);
    }
    accept_cr();
}

static void set_yield_statement()
{
    accept(TOKENIZER_SET_YIELD);
    int val = expr();
    yield_max_lines = val?val:YIELD_MAX_LINES_DEFAULT;
    val = expr();
    yield_max_ms = val?val:YIELD_MAX_MS_DEFAULT;
    accept_cr();
}

/*---------------------------------------------------------------------------*/

static void wait_click_statement()
{
    int timeout=0;
    accept(TOKENIZER_WAIT_CLICK);
    if (tokenizer_token() != TOKENIZER_CR &&
        tokenizer_token() != TOKENIZER_ELSE ) {
        timeout = expr();
    }
    action_wait_for_click(timeout);
    flag_yield=1;
    accept_cr();
}

static void is_key_statement(void)
{
    int var;
    accept(TOKENIZER_IS_KEY);
    var = tokenizer_variable_num();
    accept(TOKENIZER_VARIABLE);
    ubasic_set_variable(var, script_key_is_clicked(ubasic_get_key_arg()));
    DEBUG_PRINTF("End of is_key\n");
    accept_cr();
}

static void get_config_value_statement()
{
    int var, var1, var2;
    tConfigVal configVal;
    accept(TOKENIZER_GET_CONFIG_VALUE);
    var = expr();
    var1 = expr();
    var2 = tokenizer_variable_num();
    accept(TOKENIZER_VARIABLE);
    if( conf_getValue(var, &configVal) == CONF_VALUE ) {
        ubasic_set_variable(var2, configVal.numb);
    } else {
        ubasic_set_variable(var2, var1);
    }
    accept_cr();
}
static void on_off_statement(int token, void (*on)(void), void (*off)(void))
{
  accept(token);
  if (expr() > 0) on();
  else off();
  accept_cr();
}


static void shutdown_statement(void){
  accept(TOKENIZER_SHUT_DOWN);
  camera_shutdown_in_a_second();
  accept_cr();
}

/*---------------------------------------------------------------------------*/

static void md_get_cell_diff_statement()
{
    int var, col, row;
    accept(TOKENIZER_MD_GET_CELL_DIFF);

		col=expr();tokenizer_next();

		row=expr();tokenizer_next();

    var = tokenizer_variable_num();
    accept(TOKENIZER_VARIABLE);

    if (module_mdetect_load())
        ubasic_set_variable(var, libmotiondetect->md_get_cell_diff(col,row));
    else
        ubasic_set_variable(var, 0);
    accept_cr();
}

static void md_detect_motion_statement()
{

 int columns;
 int rows;
 int pixel_measure_mode;
 int detection_timeout;
 int measure_interval;
 int threshold;
 int draw_grid=0;
 int clipping_region_mode=0;
 int clipping_region_row1=0;
 int clipping_region_column1=0;
 int clipping_region_row2=0;
 int clipping_region_column2=0;
 int parameters=0;
 int pixels_step=1;
 int msecs_before_trigger=0;

 //static char buf[128];

    accept(TOKENIZER_MD_DETECT_MOTION);

//		sprintf(buf,"token: %d",tokenizer_token()); script_console_add_line(buf);
		columns=expr();tokenizer_next();

//		sprintf(buf,"tk: %d",tokenizer_token()); script_console_add_line(buf);
		rows=expr();tokenizer_next();

//		sprintf(buf,"tk %d",tokenizer_token()); script_console_add_line(buf);
		pixel_measure_mode=expr();tokenizer_next();

		detection_timeout=expr();tokenizer_next();

//		printf("token: %d",tokenizer_token());
		measure_interval=expr();tokenizer_next();

//		printf("token: %d",tokenizer_token());
		threshold=expr();tokenizer_next();

//		printf("token: %d",tokenizer_token());
		draw_grid=expr();tokenizer_next();

//		printf("token: %d",tokenizer_token());
        ubasic_md_ret_var_num = tokenizer_variable_num();

//		printf("%d,%d,%d,%d",columns,rows,pixel_measure_mode, detection_timeout);

    accept(TOKENIZER_VARIABLE);


    if (tokenizer_token() != TOKENIZER_CR && tokenizer_token() != TOKENIZER_ELSE) {
			// eat COMA
//			tokenizer_next();
		}



    if (tokenizer_token() != TOKENIZER_CR && tokenizer_token() != TOKENIZER_ELSE) {
				tokenizer_next();
        clipping_region_mode = expr();
    }
    if (tokenizer_token() != TOKENIZER_CR && tokenizer_token() != TOKENIZER_ELSE ) {
				tokenizer_next();
        clipping_region_column1 = expr();
    }
    if (tokenizer_token() != TOKENIZER_CR && tokenizer_token() != TOKENIZER_ELSE ) {
				tokenizer_next();
        clipping_region_row1 = expr();
    }
    if (tokenizer_token() != TOKENIZER_CR && tokenizer_token() != TOKENIZER_ELSE ) {
				tokenizer_next();
        clipping_region_column2 = expr();
    }
    if (tokenizer_token() != TOKENIZER_CR && tokenizer_token() != TOKENIZER_ELSE ) {
				tokenizer_next();
        clipping_region_row2 = expr();
    }
    if (tokenizer_token() != TOKENIZER_CR && tokenizer_token() != TOKENIZER_ELSE ) {
				tokenizer_next();
        parameters = expr();
    }
    if (tokenizer_token() != TOKENIZER_CR && tokenizer_token() != TOKENIZER_ELSE ) {
				tokenizer_next();
        pixels_step = expr();
    }

    if (tokenizer_token() != TOKENIZER_CR && tokenizer_token() != TOKENIZER_ELSE ) {
				tokenizer_next();
        msecs_before_trigger = expr();
    }


    accept_cr();

//		sprintf(buf,"[%dx%d] md:%d tmout:%d", columns, rows, pixel_measure_mode, detection_timeout);
//		script_console_add_line(buf);

//		sprintf(buf,"int:%d trsh:%d g:%d vr:%d", measure_interval, threshold, draw_grid, ret_var_num);
//		script_console_add_line(buf);

//		sprintf(buf,"clip %d [%d,%d][%d,%d]", clipping_region_mode, clipping_region_column1, clipping_region_row1, clipping_region_column2,clipping_region_row2);
//		script_console_add_line(buf);

    if (module_mdetect_load())
        libmotiondetect->md_init_motion_detector(
			columns, rows, pixel_measure_mode, detection_timeout,
			measure_interval, threshold, draw_grid,
			clipping_region_mode,
			clipping_region_column1, clipping_region_row1,
			clipping_region_column2, clipping_region_row2,
			parameters, pixels_step, msecs_before_trigger
    	);
    flag_yield=1;
}

/*---------------------------------------------------------------------------*/

static void
statement(void)
{
  ubasic_token token;

  token = tokenizer_token();

  switch(token) {
  // aflock
  case TOKENIZER_SET_AFLOCK:
      on_off_statement(token, DoAFLock, UnlockAF);
      break;

  case TOKENIZER_PRINT_SCREEN:
      one_int_param_function(token, script_print_screen_statement);
      break;
  case TOKENIZER_PRINT:
      print_statement();
      break;

  case TOKENIZER_SLEEP:
      sleep_statement();
      break;
  case TOKENIZER_CLICK:
      click_statement();
      break;
  case TOKENIZER_PRESS:
      press_statement();
      break;
  case TOKENIZER_RELEASE:
      release_statement();
      break;
  case TOKENIZER_SHOOT:
      shoot_statement();
      break;

#ifdef INCLUDE_OLD_GET__SYNTAX
  case TOKENIZER_GET_TV96:
      get_short_var_statement(token, shooting_get_tv96);
      break;
  case TOKENIZER_GET_USER_TV96:
      get_short_var_statement(token, shooting_get_user_tv96);
      break;
  case TOKENIZER_GET_USER_TV_ID:
      get_int_var_statement(token, shooting_get_user_tv_id);
      break;
  case TOKENIZER_GET_AV96:
      get_short_var_statement(token, shooting_get_av96);
      break;
  case TOKENIZER_GET_USER_AV96:
      get_short_var_statement(token, shooting_get_user_av96);
      break;
  case TOKENIZER_GET_USER_AV_ID:
      get_int_var_statement(token, shooting_get_user_av_id);
      break;
  case TOKENIZER_GET_ZOOM:
      get_int_var_statement(token, shooting_get_zoom);
      break;
  case TOKENIZER_GET_FOCUS:
      get_int_var_statement(token, shooting_get_subject_distance);
      break;
  case TOKENIZER_GET_NEAR_LIMIT:
      get_int_var_statement(token, shooting_get_near_limit_of_acceptable_sharpness);
      break;
  case TOKENIZER_GET_FAR_LIMIT:
      get_int_var_statement(token, shooting_get_far_limit_of_acceptable_sharpness);
      break;
  case TOKENIZER_GET_DOF:
      get_int_var_statement(token, shooting_get_depth_of_field);
      break;
  case TOKENIZER_GET_HYPERFOCAL_DIST:
      get_int_var_statement(token, shooting_get_hyperfocal_distance);
      break;
  case TOKENIZER_GET_ISO_MARKET:
      get_short_var_statement(token, shooting_get_iso_market);
      break;
  case TOKENIZER_GET_ISO_REAL:
      get_short_var_statement(token, shooting_get_iso_real);
      break;
  case TOKENIZER_GET_BV96:
      get_short_var_statement(token, shooting_get_bv96);
      break;
  case TOKENIZER_GET_SV96:
      get_short_var_statement(token, shooting_get_sv96);
      break;
  case TOKENIZER_GET_ISO_MODE:
      get_int_var_statement(token, shooting_get_iso_mode);
      break;
  case TOKENIZER_GET_VBATT:
      get_int_var_statement(token, (int (*)(void))stat_get_vbatt);
      break;
  case TOKENIZER_GET_DISK_SIZE:
      get_int_var_statement(token, (int (*)(void))GetTotalCardSpaceKb);
      break;
  case TOKENIZER_GET_FREE_DISK_SPACE:
      get_int_var_statement(token, (int (*)(void))GetFreeCardSpaceKb);
      break;
  case TOKENIZER_GET_JPG_COUNT:
      get_int_var_statement(token, (int (*)(void))GetJpgCount);
      break;
  case TOKENIZER_GET_RAW_COUNT:
      get_int_var_statement(token, (int (*)(void))GetRawCount);
      break;
  case TOKENIZER_GET_PROP:
      get_prop_statement();
      break;
#endif

  case TOKENIZER_SET_TV96_DIRECT:
      one_short_param_plus_const_function(token, shooting_set_tv96_direct, SET_LATER);
      break;
  case TOKENIZER_SET_TV96:
      one_short_param_plus_const_function(token, shooting_set_tv96, SET_LATER);
      break;
  case TOKENIZER_PLAY_SOUND:
      one_int_param_function(token, (void (*)(int))play_sound);
      break;
  case TOKENIZER_SET_SHUTTER_SPEED:
      one_int_param_plus_const_function(token, shooting_set_shutter_speed_ubasic, SET_LATER);
      break;
  case TOKENIZER_SET_USER_TV96:
      one_short_param_function(token, shooting_set_user_tv96);
      break;
  case TOKENIZER_SET_USER_TV_BY_ID:
      one_int_param_function(token, shooting_set_user_tv_by_id);
      break;
  case TOKENIZER_SET_USER_TV_BY_ID_REL:
      one_int_param_function(token, shooting_set_user_tv_by_id_rel);
      break;
  case TOKENIZER_SET_AV96_DIRECT:
      one_short_param_plus_const_function(token, shooting_set_av96_direct, SET_LATER);
      break;
  case TOKENIZER_SET_AV96:
      one_short_param_plus_const_function(token, shooting_set_av96, SET_LATER);
      break;

  case TOKENIZER_SET_USER_AV96:
      one_short_param_function(token, shooting_set_user_av96);
      break;
  case TOKENIZER_SET_USER_AV_BY_ID:
      one_int_param_function(token, shooting_set_user_av_by_id);
      break;
  case TOKENIZER_SET_USER_AV_BY_ID_REL:
      one_int_param_function(token, shooting_set_user_av_by_id_rel);
      break;

  case TOKENIZER_SET_ND_FILTER:
      one_short_param_plus_const_function(token, shooting_set_nd_filter_state, SET_LATER);
      break;

  case TOKENIZER_SET_ZOOM:
      one_int_param_function(token, shooting_set_zoom);
      break;
  case TOKENIZER_SET_ZOOM_REL:
      one_int_param_function(token, shooting_set_zoom_rel);
      break;
  case TOKENIZER_SET_ZOOM_SPEED:
      one_int_param_function(token, shooting_set_zoom_speed);
      break;

  case TOKENIZER_SET_FOCUS:
      set_focus_statement();
      break;

  //ARM Begin
  /*
  case TOKENIZER_SET_ISO_MARKET:
      one_int_param_function(token, shooting_set_iso_market);
      break;
  case TOKENIZER_SET_ISO_DL_F_B:
      one_int_param_function(token, shooting_set_iso_real_delta_from_base);
      break;
  */
  //ARM End

  case TOKENIZER_SET_ISO_REAL:
      one_short_param_plus_const_function(token, shooting_set_iso_real, SET_LATER);
      break;
  case TOKENIZER_SET_SV96:
      one_short_param_plus_const_function(token, shooting_set_sv96, SET_LATER);
      break;

  case TOKENIZER_SET_ISO_MODE:
      one_int_param_function(token, shooting_set_iso_mode);
      break;

  case TOKENIZER_SET_PROP:
      set_prop_statement();
      break;
  case TOKENIZER_SET_LED:
      set_led_statement();
      break;

  case TOKENIZER_SET_EV:
      set_ev_statement();
      break;

  case TOKENIZER_SET_MOVIE_STATUS:
      set_movie_status_statement();
      break;
  case TOKENIZER_SET_RESOLUTION:
      set_propcase_statement(token, PROPCASE_RESOLUTION);
      break;
  case TOKENIZER_SET_QUALITY:
      set_propcase_statement(token, PROPCASE_QUALITY);
      break;

  case TOKENIZER_WAIT_CLICK:
      wait_click_statement();
      break;
  case TOKENIZER_IS_KEY:
      is_key_statement();
      break;

  case TOKENIZER_WHEEL_LEFT:
      accept(token);
#ifdef CAM_HAS_JOGDIAL
      JogDial_CCW();
#endif
      accept_cr();
      break;
  case TOKENIZER_WHEEL_RIGHT:
      accept(token);
#ifdef CAM_HAS_JOGDIAL
      JogDial_CW();
#endif
      accept_cr();
      break;

  case TOKENIZER_IF:
      if_statement();
      break;
  case TOKENIZER_ELSE:
      else_statement();
      break;
  case TOKENIZER_ENDIF:
      endif_statement();
      break;
  case TOKENIZER_SELECT:
      select_statement();
      break;
  case TOKENIZER_CASE:
      case_statement();
      break;
  case TOKENIZER_CASE_ELSE:
      case_else_statement();
      break;
  case TOKENIZER_GOTO:
      goto_statement();
      break;
  case TOKENIZER_GOSUB:
      gosub_statement();
      break;
  case TOKENIZER_RETURN:
      return_statement();
      break;
  case TOKENIZER_FOR:
      for_statement();
      break;
  case TOKENIZER_NEXT:
      next_statement();
      break;
  case TOKENIZER_DO:
      do_statement();
      break;
  case TOKENIZER_UNTIL:
      until_statement();
      break;
  case TOKENIZER_WHILE:
      while_statement();
      break;
  case TOKENIZER_WEND:
      wend_statement();
      break;
  case TOKENIZER_END:
      end_statement();
      break;
  case TOKENIZER_LET:
      accept(TOKENIZER_LET);
      /* Fall through. */
  case TOKENIZER_VARIABLE:
      let_statement();
      break;
  case TOKENIZER_REM:
      rem_statement();
      break;
  case TOKENIZER_CLS:
      cls_statement();
      break;
  case TOKENIZER_SET_RAW:
      one_int_param_function(token, camera_set_raw);
      break;
  case TOKENIZER_SET_RAW_NR:
      one_int_param_function(token, camera_set_nr);
      break;
  case TOKENIZER_SET_SCRIPT_AUTOSTART:
      set_autostart_statement();
      break;
  case TOKENIZER_EXIT_ALT:
      one_int_param_function(token, exit_alt);
      break;
  case TOKENIZER_SHUT_DOWN:
      shutdown_statement();
      break;
  case TOKENIZER_SET_BACKLIGHT:
      on_off_statement(token, TurnOnBackLight, TurnOffBackLight);
      break;

      // >> mx3 . motion detector
  case   TOKENIZER_MD_DETECT_MOTION:
      md_detect_motion_statement();
      break;
  case  TOKENIZER_MD_GET_CELL_DIFF:
      md_get_cell_diff_statement();
      break;
      // << mx3 . motion_detector

  case TOKENIZER_SHOT_HISTO_ENABLE:
      one_int_param_function(token, (void (*)(int))shot_histogram_set);
      break;

  case TOKENIZER_SET_RECORD:
      on_off_statement(token, levent_set_record, levent_set_play);
      break;

  case TOKENIZER_SET_CAPTURE_MODE:
      one_int_param_function(token, (void (*)(int))shooting_set_mode_chdk);
      break;

  case TOKENIZER_SET_CAPTURE_MODE_CANON:
      set_capture_mode_canon_statement();
      break;
  case TOKENIZER_SET_CONSOLE_LAYOUT:
      set_console_layout();
      break;
  case TOKENIZER_SET_CONSOLE_AUTOREDRAW:
      set_console_autoredraw();
      break;
  case TOKENIZER_CONSOLE_REDRAW:
      console_redraw_statement();
      break;
  case TOKENIZER_REBOOT:
      reboot_statement();
      break;

 case TOKENIZER_GET_CONFIG_VALUE:
    get_config_value_statement();

    break;

  case TOKENIZER_SET_CONFIG_VALUE:
    set_config_value_statement();
    break;
  case TOKENIZER_SET_YIELD:
    set_yield_statement();
    break;

  default:
      DEBUG_PRINTF("ubasic.c: statement(): not implemented %d\n", token);
      ended = 1;
      ubasic_error = UBASIC_E_UNK_STATEMENT;
  }
}
/*---------------------------------------------------------------------------*/
static void
line_statement(void)
{
  /* line numbers have been removed */
  DEBUG_PRINTF("----------- Line number %d ---------\n", tokenizer_line_number());
  /*    current_linenum = tokenizer_num();*/
#if 0
  if (tokenizer_token() == TOKENIZER_LABEL) {
#ifdef DEBUG
      tokenizer_label(string, sizeof(string));
      DEBUG_PRINTF("line_statement: label: %s\n", string );
#endif
      accept(TOKENIZER_LABEL);
      accept(TOKENIZER_CR);
      return;
  }
#endif
  /* reyalp - eat up to 100 labels or rems at a time so they don't cost 10ms each */
  int count = 100;
  do {
    int r=tokenizer_token();
    if ( r == TOKENIZER_LABEL ) {
      /* hit limit and we are on a label, return */
      if( count == 1 )
        return;
#ifdef DEBUG
      tokenizer_label(string, sizeof(string));
      DEBUG_PRINTF("line_statement: label: %s\n", string );
#endif
      accept(TOKENIZER_LABEL);
      accept(TOKENIZER_CR);
    }
    else if ( r == TOKENIZER_REM ) {
      rem_statement();
    }
    else {
      break;
    }
  } while(--count);
  statement();
  return;
}

/*---------------------------------------------------------------------------*/
void
ubasic_run(void)
{
 unsigned start_tick = get_tick_count();
 unsigned lines = 0;
 flag_yield = 0;

 do
 {
  if( ubasic_finished() ) {
    DEBUG_PRINTF("uBASIC program finished\n");
    return;
  }

  line_statement();

  // Return control to CHDK only if external processing required  
  if ( flag_yield )
    return;

  lines++;
 } while (lines < yield_max_lines && get_tick_count() - start_tick < yield_max_ms);
}
/*---------------------------------------------------------------------------*/
int
ubasic_finished(void)
{
  return ended || tokenizer_finished();
}
/*---------------------------------------------------------------------------*/
void
ubasic_set_variable(int varnum, int value)
{
  if(varnum >= 0 && varnum < MAX_VARNUM) {
    variables[varnum] = value;
  }
}
/*---------------------------------------------------------------------------*/
int
ubasic_get_variable(int varnum)
{
  if(varnum >= 0 && varnum < MAX_VARNUM) {
    return variables[varnum];
  }
  return 0;
}
/*---------------------------------------------------------------------------*/
void
ubasic_end() {
}
/*---------------------------------------------------------------------------*/

void ubasic_set_md_ret(int md_ret)
{
    ubasic_set_variable(ubasic_md_ret_var_num, md_ret);
}
