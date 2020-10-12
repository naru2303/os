#include <stdint.h>
#include "include/os-include/stm32regmap.h"
#include "include/os-include/sprint.h"
#include "include/os-include/bit.h"
#include "drivers/gpio/os_hal_gpio.h"
#include "drivers/uart/os_hal_uart.h"
#include "drivers/clk/os_hal_rcc.h"

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

int main(void)
{
  Hal_Clocks_Init();/*< Enable all clocks */
  Hal_Gpio_Init();  /*< Activate all GPIOs used */
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