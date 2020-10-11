#include <stdint.h>
#include "include/os-include/stm32regmap.h"
#include "include/os-include/sprint.h"
#include "include/os-include/bit.h"
#include "drivers/gpio/os_hal_gpio.h"
#include "drivers/uart/os_hal_uart.h"

void delay(uint32_t time);
void Init_Sys_Clock(void);
/**
*   @brief basic delay function
*   @param time length of delay
*   @return none
*/
void delay(uint32_t time)
{
    while(time > 0)
    {
        time--;
    }
}

/**
 *  @brief Setting clock to 16 MHz
 *  TODO: Use PLL to get up to 70 MHz
 */
void Init_Sys_Clock(void)
{
  OS_RCC->CR |= (1<<8);
  while(!(OS_RCC->CR & (1<<10)));
  OS_RCC->CFGR &= ~(0x3);
  OS_RCC->CFGR |= (1<<0);
  while(!(OS_RCC->CFGR & (1<<0)));
}

int main(void)
{
  Init_Sys_Clock();

  /*< TODO: Create HAL for RCC */
  OS_RCC->APB1ENR1 |= bit(17); /*< USART2 Clock */ 
  OS_RCC->AHB2ENR |= bit(1)|bit(2)|bit(0); /*< GPIOA, B, C Clock */
  Hal_Gpio_Init();
  Hal_Usart_init(); /*< TODO: Finish UART Hal */

  Hal_Usart_PrintStr("Hello, World!\r\n");
  while(1)
  {
    
    if(Hal_Gpio_Read(GPIO_PORT_B, GPIO_PIN_7|GPIO_PIN_14) && Hal_Gpio_Read(GPIO_PORT_C, GPIO_PIN_7))
    {
      Hal_Gpio_Write(GPIO_PORT_B, GPIO_PIN_7|GPIO_PIN_14, GPIO_STATE_RESET);
      Hal_Gpio_Write(GPIO_PORT_C, GPIO_PIN_7, GPIO_STATE_RESET);
    }
    else
    {
      Hal_Gpio_Write(GPIO_PORT_B, GPIO_PIN_7|GPIO_PIN_14, GPIO_STATE_SET);
      Hal_Gpio_Write(GPIO_PORT_C, GPIO_PIN_7, GPIO_STATE_SET);
    }
    delay(500000);
  }
}