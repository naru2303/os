#include <stdint.h>
#include "include/stm32l4xx.h"
#include "include/os-include/stm32regmap.h"
#include "include/os-include/sprint.h"
#include "include/os-include/bit.h"
void initPeriph(void);
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
    RCC->AHB2ENR = (1<<1); /*< Enable GPIOB Clock */

    OS_PIOB->MODER = bit(14) ; 
    OS_PIOB->ODR &= ~bit(7)  ; 
   // GPIOB->MODER = (0x01 << 14); /*< Set PB7 as output */
  //  GPIOB->ODR &= ~(1<<7); /*< Set PB7 to 0 */
    while(1)
    {

        delay(500000);
      //  GPIOB->ODR |= (1<<7);
        OS_PIOB->ODR |= bit(7)  ; 
        delay(500000);
        OS_PIOB->ODR &= ~bit(7) ;
        //GPIOB->ODR &= ~(1<<7);
    }
    
}
