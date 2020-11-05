#include "os_hal_uart.h"









/**
 *  @brief  UART Initalization
 */

void usart_state_init(usart_state_wrapper_t * state) {
    state->rx_state = OS_USART_RX_IDLE ; 
    state->tx_state = OS_USART_TX_IDLE ; 
    state->usart_state = OS_USART_STATE_UINIT ; 
 }


void os_init_usart_config(){



 }

 //TODO: Implement state machine 
void os_init_usart(u32 baudrate) 
{
    //state->usart_state = OS_USART_STATE_START ; 
    /*< PA2 = TX | PA3 = RX | Both activated in the GPIO Config Table */
    OS_USART_2->BRR = (u32) ((F_CPU/baudrate)+1);  /*< 115200 baudrate @ 16MHz */
    OS_USART_2->CR1 |= (1<<3)|(1<<2)|(1<<0); /*< TX/RX/UE Enable */
}

/**
 *  @brief UART PrintChar
 */
void os_init_print_char(u8 data)
{
    OS_USART_2->TDR = data;
    while(!(OS_USART_2->ISR & (1<<6)));
}

/**
 *  @brief UART PrintString
 */
void os_init_print_string(char * str)
{
    while(*str)
    {
        os_init_print_char(*str++);
    }
}

/**
 *  @brief os_usart_receive : receives data and returns an u8
 */

u8 os_receive_frame(usart_state_wrapper_t * state) { 
u8 ret = 0 ; 
//TODO : switch state over the CR1->M1 Register to check with the 
// datalenght
   
   while(USART1->ISR & (1<<5)) ; 
state->tx_state = OS_USART_TX_ACTIVE ; 
   for(i8 i = 0 ; i < MAXSIZE_USART_FRAME_MODE_MAX ; ++i) {
       ret = USART1->RDR;
   }
 if(ret < 0) { 
     state->usart_state  = OS_USART_STATE_STOP ; 
     return OS_USART_ERROR_DATA_BITS ; 
 }
 state->tx_state = OS_USART_TX_COMPLETE ; 
 _nop() ; 
 _nop() ; 
 _nop() ; 
 _nop() ; 

 state->tx_state = OS_USART_TX_IDLE ; 

return ret ; 

}

//void os_send_frame(u8* data , usart_state_wrapper_t * state) { 

   //TODO : switch state over the CR1->M1 Register to check with the 
// datalenght

//}