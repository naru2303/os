
#ifndef STM32REGMAP_H 
#define STM32REGMAP_H

#include "include/os-include/os_types.h"

#define _rw volatile 
#define _w volatile 
#define _r volatile const
#define F_CPU (16000000UL)





typedef struct{ 
_rw u32 CR ; 
_rw u32 ICSCR ; 
_rw u32 CFGR ; 
_rw u32 PLLCFGR ;
_rw u32 PLLSAI1CFGR ;
_rw u32 PLLSAI2CFGR ; 
_rw u32 CIER ; 
_rw u32 CIFR ;
_rw u32 CICR ;
u32 reserved0 ; 
_rw u32 AHB1RSTR ;
_rw u32 AHB2RSTR ;
_rw u32 AHB3RSTR ;
u32 reserved1 ; 
_rw u32 APB1RSTR1  ;
_rw u32 APB1RSTR2 ; 
_rw u32 APB2RSTR ; 
u32 reserved2 ; 
_rw u32 AHB1ENR ;
_rw u32 AHB2ENR ; 
_rw u32 AHB3ENR ;
u32 reserved3 ; 
_rw u32 APB1ENR1 ; 
_rw u32 APB1ENR2 ; 
_rw u32 APB2ENR ;
u32 reserved4 ; 
_rw u32 AHB1SMENR ; 
_rw u32 AHB2SMENR ;
_rw u32 AHB3SMENR ; 
u32 reserved5  ;
_rw u32 APB1SMENR1 ; 
_rw u32 APB1SMENR2 ; 
_rw u32 APB2SMENR ; 
u32 reserved6 ; 
_rw u32 CCIPR ; 
u32 reserved7 ; 
_rw u32 BDCR ;
_rw u32 CSR ;
_r u32 CRRCR ; 
_rw u32 CCIPR2 ; 
}rcc_t  ; 


#define OS_RCC ((rcc_t*) 0x40021000UL)






typedef struct{ 

_rw u32 MODER ; 
_rw u32 OTYPER ; 
_rw u32 OSPEEDR ; 
_rw u32 PUPDR ; 
_r u32 IDR ; 
_rw u32 ODR ; 
_w u32 BSRR ; 
_rw u32 LCKK ; 
_rw u32 AFR[2] ; 
_w u32 BRR ; 
_rw u32 ASCR ; 
}gpio_t; 

#define PIOA_BASE 0x48000000UL
#define PIOB_BASE 0x48000400UL
#define PIOC_BASE 0x48000800UL
#define PIOD_BASE 0x48000C00UL
#define PIOE_BASE 0x48001000UL
#define PIOF_BASE 0x48001400UL
#define PIOG_BASE 0x48001800UL
#define PIOH_BASE 0x48001C00UL

#define OS_PIOA ((gpio_t*) PIOA_BASE) 
#define OS_PIOB ((gpio_t*) PIOB_BASE)
#define OS_PIOC ((gpio_t*) PIOC_BASE) 
#define OS_PIOD ((gpio_t*) PIOD_BASE)
#define OS_PIOE ((gpio_t*) PIOE_BASE) 
#define OS_PIOF ((gpio_t*) PIOF_BASE)
#define OS_PIOG ((gpio_t*) PIOG_BASE) 
#define OS_PIOH ((gpio_t*) PIOH_BASE) 


typedef struct {
  _rw u32 CR1 ; /*< 00 */ 
  _rw u32 CR2 ; /*< 04 */
  _rw u32 CR3 ; /*< 08 */
  _rw u32 BRR ; /*< 0C */
  _rw u16 GTPR ; /*< 10 */
  u16 reserved2 ;  // 0x12 
  _rw u32 RTOR ; /*< 14 */
  _rw u16 RQR ; /*< 18 */
  u16 reserved3 ;  //0x1A
  _rw u32 ISR  ; /*< 1C */
  _rw u32 ICR ;  /*< 20 */
  _r u16 RDR ;  /*< 24 */
  u16 reserved4 ;  //0x26
  _rw u32 TDR ;  /*< 28 */
  u16 reserved5  ; // 0x2A 2C
}usart_t ; 
 
/*< TODO: Update Memory Addresses */
#define USART1_BASE             0x40013800             
#define USART2_BASE             0x40004400
#define USART3_BASE             0x40008000
#define UART4_BASE              0x40004C00
#define UART5_BASE              0x40005000
#define LPUART1_BASE           0x40008000

#define OS_USART_1 ((usart_t*)  USART1_BASE) 
#define OS_USART_2 ((usart_t*)  USART2_BASE)
#define OS_USART_3 ((usart_t*)  USART3_BASE) 
#define OS_UART_4 ((usart_t*)   UART4_BASE)
#define OS_UART_5 ((usart_t*)   UART5_BASE)
#define OS_LPUART_1 ((usart_t*) LPUART1_BASE)





//TODO Add all other regs .




#endif
