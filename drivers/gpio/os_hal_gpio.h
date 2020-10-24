#ifndef OS_HAL_GPIO_H
#define OS_HAL_GPIO_H
#include "include/os-include/stm32regmap.h"

typedef enum
{
    GPIO_SPEED_LOW, /**<TODO: What do these speeds translate to in HZ */
    GPIO_SPEED_MEDIUM, 
    GPIO_SPEED_HIGH,
    GPIO_SPEED_VERYHIGH
}GpioPinSpeed_t;

typedef enum
{
    GPIO_MODE_INPUT,    /*< Input mode */
    GPIO_MODE_OUTPUT,   /*< General purpose output mode */
    GPIO_MODE_AF,       /*< Alternate function mode */
    GPIO_MODE_ANALOG    /*< Analog mode (reset state) */
}GpioPinMode_t;

typedef enum
{
    GPIO_AF_0,
    GPIO_AF_1,
    GPIO_AF_2,
    GPIO_AF_3,
    GPIO_AF_4,
    GPIO_AF_5,
    GPIO_AF_6,
    GPIO_AF_7,
    GPIO_AF_8,
    GPIO_AF_9,
    GPIO_AF_10,
    GPIO_AF_11,
    GPIO_AF_12,
    GPIO_AF_13,
    GPIO_AF_14,
    GPIO_AF_15,
    NONE
}GpioAF_t;

typedef enum
{
    GPIO_PIN_0 = (1<<0),  /*< 0x0000 0000 */
    GPIO_PIN_1 = (1<<1),  /*< 0x0000 0001 */
    GPIO_PIN_2 = (1<<2),  /*< 0x0000 0002 */
    GPIO_PIN_3 = (1<<3),  /*< 0x0000 0003 */
    GPIO_PIN_4 = (1<<4),  /*< 0x0000 0004 */
    GPIO_PIN_5 = (1<<5),  /*< 0x0000 0005 */
    GPIO_PIN_6 = (1<<6),  /*< 0x0000 0006 */
    GPIO_PIN_7 = (1<<7),  /*< 0x0000 0007 */
    GPIO_PIN_8 = (1<<8),  /*< 0x0000 0008 */
    GPIO_PIN_9 = (1<<9),  /*< 0x0000 0009 */
    GPIO_PIN_10 = (1<<10), /*< 0x0000 000A */
    GPIO_PIN_11 = (1<<11), /*< 0x0000 000B */
    GPIO_PIN_12 = (1<<12), /*< 0x0000 000C */
    GPIO_PIN_13 = (1<<13), /*< 0x0000 000D */
    GPIO_PIN_14 = (1<<14), /*< 0x0000 000E */
    GPIO_PIN_15 = (1<<15), /*< 0x0000 000F */
}GpioPinNumber_t;

typedef enum
{
    GPIO_PORT_A = PIOA_BASE, /*< 0x4800 0000 */
    GPIO_PORT_B = PIOB_BASE, /*< 0x4800 0400 */
    GPIO_PORT_C = PIOC_BASE, /*< 0x4800 0800 */
    GPIO_PORT_D = PIOD_BASE, /*< 0x4800 0C00 */
    GPIO_PORT_E = PIOE_BASE, /*< 0x4800 1000 */
    GPIO_PORT_F = PIOF_BASE, /*< 0x4800 1400 */
    GPIO_PORT_G = PIOG_BASE, /*< 0x4800 1800 */
    GPIO_PORT_H = PIOH_BASE, /*< 0x4800 1C00 */
    
}GpioPortNumber_t;

typedef enum
{
    GPIO_PUPDR_NONE, /*< No pull-up, pull-down */
    GPIO_PUPDR_PUP,  /*< Pull-up */
    GPIO_PUPDR_PDN   /*< Pull-down */
}GpioPinPupdr_t;

typedef enum
{
    GPIO_STATE_RESET,
    GPIO_STATE_SET
}GpioPinState_t;


typedef struct
{
    GpioPortNumber_t    Port;
    GpioPinNumber_t     Pin;
    GpioPinMode_t       Mode;
    GpioAF_t            AF;
    GpioPinSpeed_t      Speed;
    GpioPinPupdr_t      Pupdr;
}GpioConfig_t;

/*< Function prototypes */
void os_gpio_config(const GpioConfig_t * Config);
void os_gpio_init(void);
void os_gpio_write(GpioPortNumber_t Port, GpioPinNumber_t Pin, GpioPinState_t State);
GpioPinState_t os_gpio_read(GpioPortNumber_t Port, GpioPinNumber_t);

#endif /**< OS_HAL_GPIO_H */