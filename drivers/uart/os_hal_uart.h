#ifndef OS_HAL_UART_H
#define OS_HAL_UART_H
#include "include/os-include/stm32regmap.h"
/**
 *  TODO: Add more functionality....
 */
void Hal_Usart_init();
void Hal_Usart_PrintChar(uint8_t data);
void Hal_Usart_PrintStr(char * str);

#endif /*< OS_HAL_UART_H */