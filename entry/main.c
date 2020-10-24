#include <stdint.h>
#include "include/os-include/stm32regmap.h"
#include "include/os-include/sprint.h"
#include "include/os-include/bit.h"
#include "drivers/gpio/os_hal_gpio.h"
#include "drivers/uart/os_hal_uart.h"
#include "drivers/clk/os_hal_rcc.h"
#include "include/os-include/print.h"


void delay(uint32_t time);

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
  os_clocks_init();/*< Enable all clocks */
  os_gpio_init();  /*< Activate all GPIOs used */
  os_init_usart(115200) ; 
  OS_PIOA->AFR[0]  |= (7<<12) | (7<<8) ; // still no response from putty ..
  

  //print("Hello,World!\r\n") ; 
os_init_print_string("Hello, World!\r\n");
  while(1)
  {
    
    if(os_gpio_read(GPIO_PORT_B, GPIO_PIN_7|GPIO_PIN_14) && os_gpio_read(GPIO_PORT_C, GPIO_PIN_7))
    {
      os_gpio_write(GPIO_PORT_B, GPIO_PIN_7|GPIO_PIN_14, GPIO_STATE_RESET);
      os_gpio_write(GPIO_PORT_C, GPIO_PIN_7, GPIO_STATE_RESET);
    }
    else
    {
      os_gpio_write(GPIO_PORT_B, GPIO_PIN_7|GPIO_PIN_14, GPIO_STATE_SET);
      os_gpio_write(GPIO_PORT_C, GPIO_PIN_7, GPIO_STATE_SET);
    }
    delay(500000);
  }
}
