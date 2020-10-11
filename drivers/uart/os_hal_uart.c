#include "os_hal_uart.h"

/**
 *  @brief  UART Initalization
 */
void Hal_Usart_init()
{
    /*< PA2 = TX | PA3 = RX | Both activated in the GPIO Config Table */
    OS_USART_2->BRR = 139;  /*< 115200 baudrate @ 16MHz */
    OS_USART_2->CR1 |= (1<<3)|(1<<2)|(1<<0); /*< TX/RX/UE Enable */
}

/**
 *  @brief UART PrintChar
 */
void Hal_Usart_PrintChar(uint8_t data)
{
    OS_USART_2->TDR = data;
    while(!(OS_USART_2->ISR & (1<<6)));
}

/**
 *  @brief UART PrintString
 */
void Hal_Usart_PrintStr(char * str)
{
    while(*str)
    {
        Hal_Usart_PrintChar(*str++);
    }
}