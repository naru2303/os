#include "os_hal_uart.h"




/**
 *  @brief  UART Initalization
 */
void os_init_usart(u32 baudrate)
{
    /*< PA2 = TX | PA3 = RX | Both activated in the GPIO Config Table */
    OS_USART_2->BRR = (u32) ((F_CPU/baudrate)+1);  /*< 115200 baudrate @ 16MHz */
    OS_USART_2->CR1 |= (1<<3)|(1<<2)|(1<<0); /*< TX/RX/UE Enable */
}

/**
 *  @brief UART PrintChar
 */
void os_init_print_char(uint8_t data)
{
    OS_USART_2->TDR = data;
    while(!(OS_USART_2->ISR & (1<<6)));
}

/**
 *  @brief UART PrintString
 */
void os_init_print_string(char * str)
{
    while(*str)
    {
        os_init_print_char(*str++);
    }
}