#include "include/os-include/print.h"





static char print_buf[128] = {0};


// the three points are Elipsis that means it can accept any kind 
// of data 
void print(const char* data, ...)
{
    va_list args;
    va_start(args, data);
    u32 size = vsprint(print_buf, data, args);
    va_end(args);

    const char* src = print_buf;
    while (size--) {
        //TODO
     // Insert USART output .
    }
}

void print_char(char c)
{
    print("%c", c);
}
