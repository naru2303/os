#include <stdint.h>

#define SRAM_START  0x20000000UL /*< Page 76 of RM */
#define SRAM_SIZE   (320 * 1024) /*< RAM size is 320kb */
#define SRAM_END    ((SRAM_START) + (SRAM_SIZE))

#define STACK_START SRAM_END

extern uint32_t _etext, _sdata, _edata, _sbss, _ebss;


void Reset_Handler(void);

/*< All handlers below are set to go to the Default_Handler(alias) and set to 
*   a weak attribute so these can be overwritten if needed */
void NMI_Handler                    (void) __attribute__ ((weak, alias("Default_Handler"))); 
void HardFault_Handler              (void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler              (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler               (void) __attribute__ ((weak, alias("Default_Handler"))); 
void UsageFault_Handler             (void) __attribute__ ((weak, alias("Default_Handler"))); 
void SVCall_Handler                 (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DebugMon_Handler               (void) __attribute__ ((weak, alias("Default_Handler"))); 
void PendSV_Handler                 (void) __attribute__ ((weak, alias("Default_Handler"))); 
void SysTick_Handler                (void) __attribute__ ((weak, alias("Default_Handler"))); 
void WWDG_IRQHandler                (void) __attribute__ ((weak, alias("Default_Handler"))); 
void PVD_PVM_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler"))); 
void TAMP_STAMP_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler"))); 
void RTC_WKUP_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void FLASH_IRQHandler               (void) __attribute__ ((weak, alias("Default_Handler"))); 
void RCC_IRQHandler                 (void) __attribute__ ((weak, alias("Default_Handler"))); 
void EXTI0_IRQHandler               (void) __attribute__ ((weak, alias("Default_Handler"))); 
void EXTI1_IRQHandler               (void) __attribute__ ((weak, alias("Default_Handler"))); 
void EXTI2_IRQHandler               (void) __attribute__ ((weak, alias("Default_Handler"))); 
void EXTI3_IRQHandler               (void) __attribute__ ((weak, alias("Default_Handler"))); 
void EXTI4_IRQHandler               (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DMA1_CH1_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DMA1_CH2_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DMA1_CH3_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DMA1_CH4_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DMA1_CH5_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DMA1_CH6_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DMA1_CH7_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void ADC1_2_IRQHandler              (void) __attribute__ ((weak, alias("Default_Handler"))); 
void CAN1_TX_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler"))); 
void CAN1_RX0_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void CAN1_RX1_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void CAN1_SCE_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void EXTI9_5_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler"))); 
void TIM1_BRK_TIM15_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler"))); 
void TIM1_UP_TIM16_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler"))); 
void TIM1_TRG_COM_TIM17_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler"))); 
void TIM1_CC_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler"))); 
void TIM2_IRQHandler                (void) __attribute__ ((weak, alias("Default_Handler"))); 
void TIM3_IRQHandler                (void) __attribute__ ((weak, alias("Default_Handler"))); 
void TIM4_IRQHandler                (void) __attribute__ ((weak, alias("Default_Handler"))); 
void I2C1_EV_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler"))); 
void I2C1_ER_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler"))); 
void I2C2_EV_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler"))); 
void I2C2_ER_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler"))); 
void SPI1_IRQHandler                (void) __attribute__ ((weak, alias("Default_Handler"))); 
void SPI2_IRQHandler                (void) __attribute__ ((weak, alias("Default_Handler"))); 
void USART1_IRQHandler              (void) __attribute__ ((weak, alias("Default_Handler"))); 
void USART2_IRQHandler              (void) __attribute__ ((weak, alias("Default_Handler"))); 
void USART3_IRQHandler              (void) __attribute__ ((weak, alias("Default_Handler"))); 
void EXTI15_10_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler"))); 
void RTC_ALARM_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DFSDM1_FLT3_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler"))); 
void TIM8_BRK_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void TIM8_UP_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler"))); 
void TIM8_TRG_COM_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler"))); 
void TIM8_CC_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler"))); 
void ADC3_IRQHandler                (void) __attribute__ ((weak, alias("Default_Handler"))); 
void FMC_IRQHandler                 (void) __attribute__ ((weak, alias("Default_Handler"))); 
void SDMMC1_IRQHandler              (void) __attribute__ ((weak, alias("Default_Handler"))); 
void TIM5_IRQHandler                (void) __attribute__ ((weak, alias("Default_Handler"))); 
void SPI3_IRQHandler                (void) __attribute__ ((weak, alias("Default_Handler"))); 
void USART4_IRQHandler              (void) __attribute__ ((weak, alias("Default_Handler"))); 
void USART5_IRQHandler              (void) __attribute__ ((weak, alias("Default_Handler"))); 
void TIM6_DACUNDER_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler"))); 
void TIM7_IRQHandler                (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DMA2_CH1_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DMA2_CH2_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DMA2_CH3_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DMA2_CH4_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DMA2_CH5_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DFSDM1_FLT0_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DFSDM1_FLT1_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DFSDM1_FLT2_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler"))); 
void COMP_IRQHandler                (void) __attribute__ ((weak, alias("Default_Handler"))); 
void LPTIM1_IRQHandler              (void) __attribute__ ((weak, alias("Default_Handler"))); 
void LPTIM2_IRQHandler              (void) __attribute__ ((weak, alias("Default_Handler"))); 
void OTG_FS_IRQHandler              (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DMA2_CH6_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DMA2_CH7_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void LPUART1_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler"))); 
void QUADSPI_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler"))); 
void I2C3_EV_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler"))); 
void I2C3_ER_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler"))); 
void SAI1_IRQHandler                (void) __attribute__ ((weak, alias("Default_Handler"))); 
void SAI2_IRQHandler                (void) __attribute__ ((weak, alias("Default_Handler"))); 
void SWPMI1_IRQHandler              (void) __attribute__ ((weak, alias("Default_Handler"))); 
void TSC_IRQHandler                 (void) __attribute__ ((weak, alias("Default_Handler"))); 
void LCD_IRQHandler                 (void) __attribute__ ((weak, alias("Default_Handler"))); 
void AES_IRQHandler                 (void) __attribute__ ((weak, alias("Default_Handler"))); 
void RNG_IRQHandler                 (void) __attribute__ ((weak, alias("Default_Handler"))); 
void FPU_IRQHandler                 (void) __attribute__ ((weak, alias("Default_Handler"))); 
void CRS_IRQHandler                 (void) __attribute__ ((weak, alias("Default_Handler"))); 
void I2C4_EV_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler"))); 
void I2C4_ER_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DCMI_IRQHandler                (void) __attribute__ ((weak, alias("Default_Handler"))); 
void CAN2_TX_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler"))); 
void CAN2_RX0_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void CAN2_RX1_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void CAN2_SCE_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler"))); 
void DMA2D_IRQHandler               (void) __attribute__ ((weak, alias("Default_Handler"))); 

uint32_t vectors[] __attribute__((section(".isr_vector"))) = {
    (uint32_t)STACK_START,                      /*< 0x000 */
    (uint32_t)&Reset_Handler,                   /*< 0x004 */
    (uint32_t)&NMI_Handler,                     /*< 0x008 */
    (uint32_t)&HardFault_Handler,               /*< 0x00C */
    (uint32_t)&MemManage_Handler,               /*< 0x010 */
    (uint32_t)&BusFault_Handler,                /*< 0x014 */
    (uint32_t)&UsageFault_Handler,              /*< 0x018 */
    (uint32_t)0,                                /*< 0x01C */
    (uint32_t)0,                                /*< 0x020 */
    (uint32_t)0,                                /*< 0x024 */
    (uint32_t)0,                                /*< 0x028 */
    (uint32_t)&SVCall_Handler ,                 /*< 0x02C */
    (uint32_t)&DebugMon_Handler,                /*< 0x030 */
    (uint32_t)0,                                /*< 0x034 */
    (uint32_t)&PendSV_Handler,                  /*< 0x038 */
    (uint32_t)&SysTick_Handler,                 /*< 0x03C */
    (uint32_t)&WWDG_IRQHandler,                 /*< 0x040 */
    (uint32_t)&PVD_PVM_IRQHandler,              /*< 0x044 */
    (uint32_t)&TAMP_STAMP_IRQHandler,           /*< 0x048 */
    (uint32_t)&RTC_WKUP_IRQHandler,             /*< 0x04C */
    (uint32_t)&FLASH_IRQHandler,                /*< 0x050 */
    (uint32_t)&RCC_IRQHandler,                  /*< 0x054 */
    (uint32_t)&EXTI0_IRQHandler,                /*< 0x058 */
    (uint32_t)&EXTI1_IRQHandler,                /*< 0x05C */
    (uint32_t)&EXTI2_IRQHandler,                /*< 0x060 */
    (uint32_t)&EXTI3_IRQHandler,                /*< 0x064 */
    (uint32_t)&EXTI4_IRQHandler,                /*< 0x068 */
    (uint32_t)&DMA1_CH1_IRQHandler,             /*< 0x06C */
    (uint32_t)&DMA1_CH2_IRQHandler,             /*< 0x070 */
    (uint32_t)&DMA1_CH3_IRQHandler,             /*< 0x074 */
    (uint32_t)&DMA1_CH4_IRQHandler,             /*< 0x078 */
    (uint32_t)&DMA1_CH5_IRQHandler,             /*< 0x07C */
    (uint32_t)&DMA1_CH6_IRQHandler,             /*< 0x080 */
    (uint32_t)&DMA1_CH7_IRQHandler,             /*< 0x084 */
    (uint32_t)&ADC1_2_IRQHandler,               /*< 0x088 */
    (uint32_t)&CAN1_TX_IRQHandler,              /*< 0x08C */
    (uint32_t)&CAN1_RX0_IRQHandler,             /*< 0x090 */
    (uint32_t)&CAN1_RX1_IRQHandler,             /*< 0x094 */
    (uint32_t)&CAN1_SCE_IRQHandler,             /*< 0x098 */
    (uint32_t)&EXTI9_5_IRQHandler,              /*< 0x09C */
    (uint32_t)&TIM1_BRK_TIM15_IRQHandler,       /*< 0x0A0 */
    (uint32_t)&TIM1_UP_TIM16_IRQHandler,        /*< 0x0A4 */
    (uint32_t)&TIM1_TRG_COM_TIM17_IRQHandler,   /*< 0x0A8 */
    (uint32_t)&TIM1_CC_IRQHandler,              /*< 0x0AC */
    (uint32_t)&TIM2_IRQHandler,                 /*< 0x0B0 */
    (uint32_t)&TIM3_IRQHandler,                 /*< 0x0B4 */
    (uint32_t)&TIM4_IRQHandler,                 /*< 0x0B8 */
    (uint32_t)&I2C1_EV_IRQHandler,              /*< 0x0BC */
    (uint32_t)&I2C1_ER_IRQHandler,              /*< 0x0C0 */
    (uint32_t)&I2C2_EV_IRQHandler,              /*< 0x0C4 */
    (uint32_t)&I2C2_ER_IRQHandler,              /*< 0x0C8 */
    (uint32_t)&SPI1_IRQHandler,                 /*< 0x0CC */
    (uint32_t)&SPI2_IRQHandler,                 /*< 0x0D0 */
    (uint32_t)&USART1_IRQHandler,               /*< 0x0D4 */
    (uint32_t)&USART2_IRQHandler,               /*< 0x0D8 */
    (uint32_t)&USART3_IRQHandler,               /*< 0x0DC */
    (uint32_t)&EXTI15_10_IRQHandler,            /*< 0x0E0 */
    (uint32_t)&RTC_ALARM_IRQHandler,            /*< 0x0E4 */
    (uint32_t)&DFSDM1_FLT3_IRQHandler,          /*< 0x0E8 */
    (uint32_t)&TIM8_BRK_IRQHandler,             /*< 0x0EC */
    (uint32_t)&TIM8_UP_IRQHandler,              /*< 0x0F0 */
    (uint32_t)&TIM8_TRG_COM_IRQHandler,         /*< 0x0F4 */
    (uint32_t)&TIM8_CC_IRQHandler,              /*< 0x0F8 */
    (uint32_t)&ADC3_IRQHandler,                 /*< 0x0FC */
    (uint32_t)&FMC_IRQHandler,                  /*< 0x100 */
    (uint32_t)&SDMMC1_IRQHandler,               /*< 0x104 */
    (uint32_t)&TIM5_IRQHandler,                 /*< 0x108 */
    (uint32_t)&SPI3_IRQHandler,                 /*< 0x10C */
    (uint32_t)&USART4_IRQHandler,               /*< 0x110 */
    (uint32_t)&USART5_IRQHandler,               /*< 0x114 */
    (uint32_t)&TIM6_DACUNDER_IRQHandler,        /*< 0x128 */
    (uint32_t)&TIM7_IRQHandler,                 /*< 0x11C */
    (uint32_t)&DMA2_CH1_IRQHandler,             /*< 0x120 */
    (uint32_t)&DMA2_CH2_IRQHandler,             /*< 0x124 */
    (uint32_t)&DMA2_CH3_IRQHandler,             /*< 0x128 */
    (uint32_t)&DMA2_CH4_IRQHandler,             /*< 0x12C */
    (uint32_t)&DMA2_CH5_IRQHandler,             /*< 0x130 */
    (uint32_t)&DFSDM1_FLT0_IRQHandler,          /*< 0x134 */
    (uint32_t)&DFSDM1_FLT1_IRQHandler,          /*< 0x138 */
    (uint32_t)&DFSDM1_FLT2_IRQHandler,          /*< 0x13C */
    (uint32_t)&COMP_IRQHandler,                 /*< 0x140 */
    (uint32_t)&LPTIM1_IRQHandler,               /*< 0x144 */
    (uint32_t)&LPTIM2_IRQHandler,               /*< 0x148 */
    (uint32_t)&OTG_FS_IRQHandler,               /*< 0x14C */
    (uint32_t)&DMA2_CH6_IRQHandler,             /*< 0x150 */
    (uint32_t)&DMA2_CH7_IRQHandler,             /*< 0x154 */
    (uint32_t)&LPUART1_IRQHandler,              /*< 0x158 */
    (uint32_t)&QUADSPI_IRQHandler,              /*< 0x15C */
    (uint32_t)&I2C3_EV_IRQHandler,              /*< 0x160 */
    (uint32_t)&I2C3_ER_IRQHandler,              /*< 0x164 */
    (uint32_t)&SAI1_IRQHandler,                 /*< 0x168 */
    (uint32_t)&SAI2_IRQHandler,                 /*< 0x16C */
    (uint32_t)&SWPMI1_IRQHandler,               /*< 0x170 */
    (uint32_t)&TSC_IRQHandler,                  /*< 0x174 */
    (uint32_t)&LCD_IRQHandler,                  /*< 0x178 */
    (uint32_t)&AES_IRQHandler,                  /*< 0x17C */
    (uint32_t)&RNG_IRQHandler,                  /*< 0x180 */
    (uint32_t)&FPU_IRQHandler,                  /*< 0x184 */
    (uint32_t)&CRS_IRQHandler,                  /*< 0x188 */
    (uint32_t)&I2C4_EV_IRQHandler,              /*< 0x18C */
    (uint32_t)&I2C4_ER_IRQHandler,              /*< 0x190 */
    (uint32_t)&DCMI_IRQHandler,                 /*< 0x194 */
    (uint32_t)&CAN2_TX_IRQHandler,              /*< 0x198 */
    (uint32_t)&CAN2_RX0_IRQHandler,             /*< 0x19C */
    (uint32_t)&CAN2_RX1_IRQHandler,             /*< 0x1A0 */
    (uint32_t)&CAN2_SCE_IRQHandler,             /*< 0x1A4 */
    (uint32_t)&DMA2D_IRQHandler,                /*< 0x1A8 */
};


void Reset_Handler(void)
{
    uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata; /*< Length of data section */
    uint8_t *pDst = (uint8_t*)&_sdata; /*< SRAM */
    uint8_t *pSrc = (uint8_t*)&_etext; /*< Flash */
    uint32_t i;
    for(i = 0; i < size; i++)
    {
        *pDst++ = *pSrc++; /*< Copy over Flash to SRAM */
    }

    size = (uint32_t)&_ebss - (uint32_t)&_sbss; /*< Length of bss section */
    pDst = (uint8_t*)&_sbss; 
    for(i = 0; i < size; i++)
    {
        *pDst++ = 0; /*< Set bss section to NULL */
    }

    main();
}

void Default_Handler(void)
{
    /*< Let program hang if fault occured */
    while(1);
}