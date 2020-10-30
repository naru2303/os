#ifndef OS_HAL_RCC_H
#define OS_HAL_RCC_H
#define OS_SYSTEM_CLOCK_HZ 16000000

#include "include/os-include/stm32regmap.h"

typedef enum
{
    /*< AHB1ENR Peripherals */
    AHB1ENR_DMA1    = (1<<0),
    AHB1ENR_DMA2    = (1<<1),
    AHB1ENR_FLASH   = (1<<8),
    AHB1ENR_CRC     = (1<<12),
    AHB1ENR_TSC     = (1<<16),
    AHB1ENR_DMA2D   = (1<<17),

    /*< AHB2ENR1 Peripherals */
    AHB2ENR1_GPIOA  = (1<<0),
    AHB2ENR1_GPIOB  = (1<<1),
    AHB2ENR1_GPIOC  = (1<<2),
    AHB2ENR1_GPIOD  = (1<<3),
    AHB2ENR1_GPIOE  = (1<<4),
    AHB2ENR1_GPIOF  = (1<<5),
    AHB2ENR1_GPIOG  = (1<<6),
    AHB2ENR1_GPIOH  = (1<<7),
    AHB2ENR1_GPIOI  = (1<<8),
    AHB2ENR1_OTGFS  = (1<<12),
    AHB2ENR1_ADC    = (1<<13),
    AHB2ENR1_DCMI   = (1<<14),
    AHB2ENR1_AES    = (1<<16),
    AHB2ENR1_HASH   = (1<<17),
    AHB2ENR1_RNG    = (1<<18),

    /*< AHB3ENR Peripherals */
    AHB3ENR_FMC     = (1<<0),
    AHB3ENR_QSPI    = (1<<8),

    /*< APB1ENR1 Peripherals */
    APB1ENR1_TIM2   = (1<<0),
    APB1ENR1_TIM3   = (1<<1),
    APB1ENR1_TIM4   = (1<<2),
    APB1ENR1_TIM5   = (1<<3),
    APB1ENR1_TIM6   = (1<<4),
    APB1ENR1_TIM7   = (1<<5),
    APB1ENR1_LCD    = (1<<9),
    APB1ENR1_RTCAPB = (1<<10),
    APB1ENR1_WWDG   = (1<<11),
    APB1ENR1_SPI2   = (1<<14),
    APB1ENR1_SPI3   = (1<<15),
    APB1ENR1_USART2 = (1<<17),
    APB1ENR1_USART3 = (1<<18),
    APB1ENR1_UART4  = (1<<19),
    APB1ENR1_UART5  = (1<<20),
    APB1ENR1_I2C1   = (1<<21),
    APB1ENR1_I2C2   = (1<<22),
    APB1ENR1_I2C3   = (1<<23),
    APB1ENR1_CRS    = (1<<24),
    APB1ENR1_CAN1   = (1<<25),
    APB1ENR1_CAN2   = (1<<26),
    APB1ENR1_PWR    = (1<<28),
    APB1ENR1_DAC1   = (1<<29),
    APB1ENR1_OPAMP  = (1<<30),
    APB1ENR1_LPTIM1 = (1<<31),
    
    /*< APB1ENR2 Peripherals */
    APB1ENR2_LPUART1 = (1<<0),
    APB1ENR2_I2C4    = (1<<1),
    APB1ENR2_SWPMI1  = (1<<2),
    APB1ENR2_LPTIM2  = (1<<5),
    

}RccPeripherals_t;

typedef enum
{
    AHB1ENR,
    AHB2ENR,
    AHB3ENR,
    APB1ENR1,
    APB1ENR2,
    APB2ENR
}RccRegisters_t;

typedef struct
{
    RccRegisters_t Register;
    RccPeripherals_t Peripherals;
}RccRegConfig_t;


os_state_t init_sys_clock_hsi(void);
os_state_t init_sys_clock_hse(u8 mul, u8 div);
os_state_t os_clocks_init(void);
os_state_t RCC_AHB1ENR_ENABLE(uint32_t Peripherals);
os_state_t RCC_AHB2ENR_ENABLE(uint32_t Peripherals);
os_state_t RCC_AHB3ENR_ENABLE(uint32_t Peripherals);
os_state_t RCC_APB1ENR1_ENABLE(uint32_t Peripherals);
os_state_t RCC_APB1ENR2_ENABLE(uint32_t Peripherals);
os_state_t RCC_APB2ENR_ENABLE(uint32_t Peripherals);
#endif /*< OS_HAL_RCC_H */