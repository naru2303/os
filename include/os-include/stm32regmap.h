
#ifndef STM32REGMAP_H 
#define STM32REGMAP_H

#include "include/os-include/os_types.h"

#define _rw volatile 
#define _w volatile 
#define _r volatile const


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

#define GPIOA ((gpio_t*) 0x48000000) 
#define GPIOB ((gpio_t*) 0x48000400)
#define GPIOC ((gpio_t*) 0x48000800) 
#define GPIOD ((gpio_t*) 0x48000C00)
#define GPIOE ((gpio_t*) 0x48001000) 
#define GPIOF ((gpio_t*) 0x48001400)
#define GPIOG ((gpio_t*) 0x48001800) 
#define GPIOH ((gpio_t*) 0x48001C00) 


typedef struct {
  _rw u32 CR1 ; 
  _rw u32 CR2 ; 
  _rw u32 CR3 ; 
  _rw u32 BRR ; 
  _rw u16 GTPR ; 
  u16 reserved2 ;  // 0x12 
  _rw u32 RTOR ; 
  _rw u16 RQR ;
  u16 reserved3 ;  //0x1A
  _rw u32 ISR  ;
  _rw u32 ICR ; 
  _r u16 RDR ; 
  u16 reserved4 ;  //0x26
  _rw u32 TDR ; 
  u16 reserved5  ; // 0x2A
}usart_t ; 
 





#endif