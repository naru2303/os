/* Copyright (C) strawberryhacker */

#ifndef SPRINT_H
#define SPRINT_H


#include <stdarg.h>
#include <stddef.h>
#include "include/os-include/os_types.h"
#include "include/os-include/stm32regmap.h"


u32 vsprint(char* buf, const char* data, va_list args);

u32 sprint(char* buf, const char* data, ...);

#endif
