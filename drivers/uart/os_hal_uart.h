#ifndef OS_HAL_UART_H
#define OS_HAL_UART_H
#include "include/os-include/stm32regmap.h"
/**
 *  TODO: Add more functionality....
 */

typedef enum
{
    USART1  = USART1_BASE,
    USART2  = USART2_BASE,
    USART3  = USART3_BASE,
    UART4   = UART4_BASE,
    UART5   = UART5_BASE,
    LPUART1 = LPUART1_BASE
}UsartNumber_t;

void Hal_Usart_init();
void Hal_Usart_PrintChar(uint8_t data);
void Hal_Usart_PrintStr(char * str);

#endif /*< OS_HAL_UART_H */