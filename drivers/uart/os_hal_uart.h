#ifndef OS_HAL_UART_H
#define OS_HAL_UART_H
#include "include/os-include/stm32regmap.h"
/**
 *  TODO: Add more functionality....
 */

// TODO: Add error Handler .

#define MAXSIZE_USART_FRAME 10




//ERROR COMMUNICATION 
#define OS_USART_ERROR_MODE -1 
#define OS_USART_ERROR_BAUDRATE -2 
#define OS_USART_ERROR_DATA_BITS -3 
#define OS_USART_ERROR_PARITY -4 
#define OS_USART_ERROR_STOP_BITS -5 
#define OS_USART_ERROR_FLOW_CONTROL -6
#define OS_USART_ERROR_CPOL -7 
#define OS_USART_ERROR_CPHA -8 


// EVENT ERROR 
#define OS_USART_EVENT_ERROR_TX_UNDERFLOW (1U)
#define OS_USART_EVENT_ERROR_RX_OVERFOW (1U<<1)
#define OS_USART_EVENT_ERROR_RX_TIMEOUT (1U<<2)
#define OS_USART_EVENT_ERROR_RX_BREAK (1U<<3)
#define OS_USART_EVENT_ERROR_RX_PARITY_ERROR (1U<<4)
#define OS_USART_EVENT_ERROR_RX_FRAMING_ERROR (1U<<5)







#define OS_USART_TX_UNDERFLOW 0x05 
#define OS_USART_RX OVERFLOW 0x06 



typedef enum {
    OS_USART_STATE_START = 0 ,
    OS_USART_STATE_STOP  , 
    OS_USART_STATE_UINIT
}usart_state_t ;




typedef enum { 
OS_USART_RX_IDLE = 0,
OS_USART_RX_ACTIVE, 
OS_USART_RX_COMPLETE 
}usart_rx_t ;



typedef enum { 
OS_USART_TX_IDLE = 0 ,
OS_USART_TX_ACTIVE,
OS_USART_TX_COMPLETE
}usart_tx_t;



#if !defined(EVEN_PARITY) 
#define EVEN_PARITY (1U)
#endif 



#if !defined(ODD_PARITY) 
#define ODD_PARITY (0U)
#endif 


#if !defined(SIMPLEX_MODE)
#define SIMPLEX_MODE                
#endif

#if !defined(HALF_DUPLEX_MODE)
#define HALF_DUPLEX_MODE           
#endif 

#if !defined(FULL_DUPLEX_MODE) 
#define FULL_DUPLEX_MODE
#endif

    
#define    USART1   USART1_BASE
#define    USART2   USART2_BASE
#define    USART3   USART3_BASE
#define    UART4    UART4_BASE
#define    UART5    UART5_BASE
#define    LPUART1  LPUART1_BASE

void os_init_usart_config() ;
void os_init_usart(u32 baudrate) ; 
void os_send_frame(u8* data) ;
void os_receive_frame(u8* data); 
void os_init_print_char(u8 data);
void os_init_print_string(char * str);

#endif /*< OS_HAL_UART_H */