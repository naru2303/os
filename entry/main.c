#include <stdint.h>
#include "include/os-include/stm32regmap.h"
#include "include/os-include/sprint.h"
#include "include/os-include/bit.h"
#include "drivers/gpio/os_hal_gpio.h"
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
  // Clock for USART2 and GPIOB 
    OS_RCC->APB1ENR1 = bit(17) ; 
    OS_RCC->AHB2ENR = bit(1)|bit(2); 

    //enable tx rx usart 
    OS_USART_2->CR1 = bit(0) | bit(2) | bit(3) ; 
    OS_USART_2->BRR = 36 ; 
    
 //TODO : Finish implementing USART
  Hal_Gpio_Init();
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