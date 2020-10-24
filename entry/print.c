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

    const u8* start = (const u8*) print_buf;
    while (size--) {
        //TODO
         while(!(OS_USART_2->ISR & (1<<6)));
         OS_USART_2->TDR = *start;
         start++ ; 
     // Insert USART output .
    }
}
