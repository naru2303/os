#include "os_hal_rcc.h"

/**
 *  @brief Configuration table with all clocks to be enabled
 */
const RccRegConfig_t Registers_To_Configure[] = {
    {.Register = AHB2ENR, .Peripherals = (AHB2ENR1_GPIOA|AHB2ENR1_GPIOB|AHB2ENR1_GPIOC)},
    {.Register = APB1ENR1, .Peripherals = APB1ENR1_USART2}
};

/**
 *  @brief Enable peripheral clocks on AHB1ENR bus
 */
void RCC_AHB1ENR_ENABLE(uint32_t Peripherals)
{
    //TODO include error code 
    OS_RCC->AHB1ENR |= Peripherals;

}

/**
 *  @brief Enable periheral clocks on AHB2ENR bus
 */
void RCC_AHB2ENR_ENABLE(uint32_t Peripherals)
{
    OS_RCC->AHB2ENR |= Peripherals;

}

/**
 *  @brief Enable periheral clocks on AHB3ENR bus
 */
void RCC_AHB3ENR_ENABLE(uint32_t Peripherals)
{
    OS_RCC->AHB3ENR |= Peripherals;
   
}

/**
 *  @brief Enable periheral clocks on AHB1ENR1 bus
 */
void RCC_APB1ENR1_ENABLE(uint32_t Peripherals)
{
    OS_RCC->APB1ENR1 |= Peripherals;
 
}

/**
 *  @brief Enable periheral clocks on AHB1ENR2 bus
 */
void RCC_APB1ENR2_ENABLE(uint32_t Peripherals)
{
    OS_RCC->APB1ENR2 |= Peripherals;

}

/**
 *  @brief Enable periheral clocks on APB2ENR bus
 */
void RCC_APB2ENR_ENABLE(uint32_t Peripherals)
{
    OS_RCC->APB2ENR |= Peripherals;

}

/**
 *  @brief Setting system clock to 16 MHz HSI
 *  @TODO: Use PLL to get up to 70 MHz
 */
void init_sys_clock_hsi(void)
{
    OS_RCC->CR |= (1<<8); /*< Enable 16 MHz HSI */
    while(!(OS_RCC->CR & 1<<10)); /*< Wait for HSI to be ready */
    _nop();
    OS_RCC->CFGR &= ~(0x3); /*< Clear system clock switch bits */
    OS_RCC->CFGR |= (1<<0); /*< Set system clock to 16 MHz HSI */
    while(!(OS_RCC->CFGR & (1<<0))); /*< Wait for 16 MHz to be selected */
    _nop(); 

}

void init_sys_clock_hse(u8 mul , u8 div){ 
    OS_RCC->CR |= (1<<16) ; 
    while(!(OS_RCC->CR & 1<<17)); 
    _nop(); 
    OS_RCC->PLLCFGR |= (1<<0) | (1<<1);
    OS_RCC->PLLCFGR |= (1<<24);
    OS_RCC->PLLCFGR |= ((mul & 0x7F) << 14) ; 
    //TODO programm gettick and finish hse.
    


}


/**
 *  @brief Initializes all clocks in the Registers_To_Configure array
 */
void os_clocks_init(void)
{
    init_sys_clock_hsi();
    uint8_t size = sizeof(Registers_To_Configure)/sizeof(RccRegConfig_t);
    for(uint8_t i = 0; i < size; i++)
    {
        switch(Registers_To_Configure[i].Register)
        {
            case AHB1ENR:
                RCC_AHB1ENR_ENABLE(Registers_To_Configure[i].Peripherals);
                break;
            case AHB2ENR:
                RCC_AHB2ENR_ENABLE(Registers_To_Configure[i].Peripherals);
                break;
            case AHB3ENR:
                RCC_AHB3ENR_ENABLE(Registers_To_Configure[i].Peripherals);
                break;
            case APB1ENR1:
                RCC_APB1ENR1_ENABLE(Registers_To_Configure[i].Peripherals);
                break;
            case APB1ENR2:
                RCC_APB1ENR1_ENABLE(Registers_To_Configure[i].Peripherals);
                break;
            case APB2ENR:
                RCC_APB2ENR_ENABLE(Registers_To_Configure[i].Peripherals);
                break;
            default: 
       
                break;
        }
    }

    
}