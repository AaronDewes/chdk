#ifndef STDARG_H
#define STDARG_H

// For building Lua
#define va_list __builtin_va_list
#define va_start __builtin_va_start
#define va_arg __builtin_va_arg
#define va_end __builtin_va_end

#endif
