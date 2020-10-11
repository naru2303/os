#include "os_hal_gpio.h"

/**
 *  @brief Configuartion table with list of all GPIO's to configure
 */
const GpioConfig_t Pins_To_Configure[] = {
    {.Port = GPIO_PORT_B, .Mode = GPIO_MODE_OUTPUT, .Speed = GPIO_SPEED_LOW, .Pupdr = GPIO_PUPDR_PDN, .Pin = GPIO_PIN_7}, /*< Led 2 */
    {.Port = GPIO_PORT_C, .Mode = GPIO_MODE_OUTPUT, .Speed = GPIO_SPEED_LOW, .Pupdr = GPIO_PUPDR_PDN, .Pin = GPIO_PIN_7}, /*< Led 1 */
    {.Port = GPIO_PORT_B, .Mode = GPIO_MODE_OUTPUT, .Speed = GPIO_SPEED_LOW, .Pupdr = GPIO_PUPDR_PDN, .Pin = GPIO_PIN_14} /*< Led 3 */
};

/**
 *  @brief  Configures the given GPIO Config set-up
 *  @param  Pointer to the config set-up struct to configure
 */
void Gpio_Config(const GpioConfig_t * Config)
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

    /*< Clear the ODR bit related to pin */
    GPIO->ODR &= ~(1 << Position);
}

/**
*   @brief Initializes all GPIO's in the Pins_To_Configure table
*/
void Hal_Gpio_Init(void)
{
    uint8_t size = sizeof(Pins_To_Configure)/sizeof(GpioConfig_t);
    for(uint8_t index = 0; index < size; index++)
    {
        Gpio_Config(&Pins_To_Configure[index]);
    }
}

/**
 *  @brief  Sets/Resets the specified Pin or Pins
 *  @param  Port which the pin is located on. GPIO_PORT_A..H
 *  @param  Pin number of the targeted GPIO/GPIOs. GPIO_PIN_0..15
 *  @param  State of pin. GPIO_STATE_SET or GPIO_STATE_RESET
 */
void Hal_Gpio_Write(GpioPortNumber_t Port, GpioPinNumber_t Pin, GpioPinState_t State)
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
GpioPinState_t Hal_Gpio_Read(GpioPortNumber_t Port, GpioPinNumber_t Pin)
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

