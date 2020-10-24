#include "os_hal_gpio.h"

/**
 *  @brief Configuartion table with list of all GPIO's to configure
 */
const GpioConfig_t Pins_To_Configure[] = {
    {.Port = GPIO_PORT_B, .Pin = GPIO_PIN_7, .Mode = GPIO_MODE_OUTPUT, .AF = NONE, .Speed = GPIO_SPEED_LOW, .Pupdr = GPIO_PUPDR_PDN}, /*< Led 2 */
    {.Port = GPIO_PORT_C, .Pin = GPIO_PIN_7, .Mode = GPIO_MODE_OUTPUT, .AF = NONE, .Speed = GPIO_SPEED_LOW, .Pupdr = GPIO_PUPDR_PDN}, /*< Led 1 */
    {.Port = GPIO_PORT_B, .Pin = GPIO_PIN_14, .Mode = GPIO_MODE_OUTPUT, .AF = NONE, .Speed = GPIO_SPEED_LOW, .Pupdr = GPIO_PUPDR_PDN},/*< Led 3 */
    {.Port = GPIO_PORT_A, .Pin = GPIO_PIN_2, .Mode = GPIO_MODE_AF, .AF = GPIO_AF_7, .Speed = GPIO_SPEED_HIGH, .Pupdr = GPIO_PUPDR_NONE}, /*< Usart 2 TX */
    {.Port = GPIO_PORT_A, .Pin = GPIO_PIN_3, .Mode = GPIO_MODE_AF, .AF = GPIO_AF_7, .Speed = GPIO_SPEED_VERYHIGH, .Pupdr = GPIO_PUPDR_NONE}  /*< Usart 2 RX */
};

/**
 *  @brief  Configures the given GPIO Config set-up
 *  @param  Pointer to the config set-up struct to configure
 */
void os_gpio_config(const GpioConfig_t * Config)
{
    gpio_t * GPIO = (gpio_t*)Config->Port;
    uint32_t Position = 0;
    uint32_t Pin = Config->Pin;

    /*< Get Pin Bit Position */
    while(Pin > 1)
    {
        Pin /= 2;
        Position++;
    }

    /*< Clear mode register then set it */
    GPIO->MODER &= ~(0x3 << Position*2); /*< Clear 2 mode bits */
    GPIO->MODER |= (Config-> Mode << Position*2); /*< Set Mode */

    /*< Clear speed register then set it */
    GPIO->OSPEEDR &= ~(0x3 << (Position*2)); /*< Clear 2 speed bits */
    GPIO->OSPEEDR |= (Config->Speed << (Position*2)); /*< Set speed */

    /*< Clear Pupdr register then set it */
    GPIO->PUPDR &= ~(0x3 << (Position*2)); /*< Clear 2 pupdr bits */
    GPIO->PUPDR |= (Config->Pupdr << (Position*2)); /*< Set Pull up/Pulldown */

    /*< Set Alternate Function Mapping */
    if(Config->AF != NONE)
    {
        if(Position <= 7)
        {
            GPIO->AFR[0] |= (Config->AF << Position*4);
        }
        else
        {
            GPIO->AFR[1] |= (Config->AF << (Position-8)*4);
        }
    }

    /*< Clear the ODR bit related to pin */
    GPIO->ODR &= ~(1 << Position);
}

/**
*   @brief Initializes all GPIO's in the Pins_To_Configure table
*/
void os_gpio_init(void)
{
    uint8_t size = sizeof(Pins_To_Configure)/sizeof(GpioConfig_t);
    for(uint8_t index = 0; index < size; index++)
    {
        os_gpio_config(&Pins_To_Configure[index]);
    }
}

/**
 *  @brief  Sets/Resets the specified Pin or Pins
 *  @param  Port which the pin is located on. GPIO_PORT_A..H
 *  @param  Pin number of the targeted GPIO/GPIOs. GPIO_PIN_0..15
 *  @param  State of pin. GPIO_STATE_SET or GPIO_STATE_RESET
 */
void os_gpio_write(GpioPortNumber_t Port, GpioPinNumber_t Pin, GpioPinState_t State)
{
    gpio_t * GPIO = (gpio_t*)Port;
    if(State == GPIO_STATE_SET)
    {
        GPIO->ODR |= Pin;
    }
    else
    {
        GPIO->ODR &= ~Pin;
    }
}

/**
 *  @brief  Read state of specified pin
 *  @param  Port where pin is located
 *  @param  Pin number of desired GPIO
 *  
 *  @return GPIO_STATE_SET if 1, GPIO_STATE_RESET if 0
 */
GpioPinState_t os_gpio_read(GpioPortNumber_t Port, GpioPinNumber_t Pin)
{
    gpio_t * GPIO = (gpio_t*)Port;
    GpioPinState_t State;
    if(GPIO->ODR & Pin)
    {
        State = GPIO_STATE_SET;
    }
    else
    {
        State = GPIO_STATE_RESET;
    }
    
    return State;
}

