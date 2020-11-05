#ifndef OS_HAL_UART_H
#define OS_HAL_UART_H
#include "include/os-include/stm32regmap.h"
#include "include/os-include/cfg.h"
/**
 *  TODO: Add more functionality....
 */

// TODO: Add error Handler .

/**
 *  TODO: Include LIN MODE or MODBUS maybe ... ? 
 */ 
/**
 *  TODO: Follow the Instructions .
 *  Programmable data order with MSB-first or LSB-first shifting
 *  Programmable data word length (7, 8 or 9 bits)
 *  Configurable stop bits (1 or 2 stop bits)
 *  */
// Transmit register -> TDR 
// Receive register -> RDR 
// Status regiser -> ISR 
// Baudrate register -> BRR 

/*

Character transmission procedure
1. Program the M bits in USART_CR1 to define the word length.
2. Select the desired baud rate using the USART_BRR register.
3. Program the number of stop bits in USART_CR2.
4. Enable the USART by writing the UE bit in USART_CR1 register to 1.
5. Select DMA enable (DMAT) in USART_CR3 if multibuffer communication is to take
place. Configure the DMA register as explained in multibuffer communication.
6. Set the TE bit in USART_CR1 to send an idle frame as first transmission.
7. Write the data to send in the USART_TDR register (this clears the TXE bit). Repeat this
for each data to be transmitted in case of single buffer.
8. After writing the last data into the USART_TDR register, wait until TC=1. This indicates
that the transmission of the last frame is complete. This is required for instance when
the USART is disabled or enters the Halt mode to avoid corrupting the last
transmission.

*/

/* 
This bit, with bit 12 (M0), determines the word length. It is set or cleared by software.
M[1:0] = 00: 1 Start bit, 8 data bits, n stop bits
M[1:0] = 01: 1 Start bit, 9 data bits, n stop bits
M[1:0] = 10: 1 Start bit, 7 data bits, n stop bits
This bit can only be written when the USART is
*/ 


// if the CR1 changes the bit lenght the MAXSIZE must change too .
// possibilities :  9 10 11 


// CR1 setting can be only be done when UE is set to 0 



// Word lenght 

#define MIN_BIT_DATA_LENGTH 0x00  // 8 bit with start and stop bit>10
#define AVG_BIT_DATA_LENGTH 0x10 // 7 bit with start and stop bit>9 
#define MAX_BIT_DATA_LENGTH 0x01 // 9 bit with start and stop bit>11


#define MAXSIZE_USART_FRAME_MODE_MIN 9
#define MAXSIZE_USART_FRAME_MODE_AVG 10 
#define MAXSIZE_USART_FRAME_MODE_MAX 11 



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

typedef struct {
    usart_rx_t rx_state ;
    usart_tx_t tx_state ; 
    usart_state_t usart_state; 
}usart_state_wrapper_t ;

#if !defined(EVEN_PARITY) 
#define EVEN_PARITY (1U)
#endif 



#if !defined(ODD_PARITY) 
#define ODD_PARITY (0U)
#endif 


#if defined(SIMPLEX_MODE)
#define SIMPLEX_MODE FALSE                
#endif


// Case Half Duplex 
/* 
Single-wire Half-duplex mode is selected by setting the HDSEL bit in the USART_CR3
register. In this mode, the following bits must be kept cleared:
• LINEN and CLKEN bits in the USART_CR2 register,
• SCEN and IREN bits in the USART_CR3 register.
The USART can be configured to follow a Single-wire Half

*/
#if defined(HALF_DUPLEX_MODE)
#define HALF_DUPLEX_MODE  TRUE         
#endif 

//redifinition error , maybe adapt it to the cfg.h in another way.
#if defined(FULL_DUPLEX_MODE) 
#define FULL_DUPLEX_MODE  TRUE
#endif

#if defined(SYNCRHONOUS_MODE)
#define SYNCHRONOUS_NODE TRUE 
#endif


//TODO : Implement DMA Registers .
#if defined(USE_USART_DMA_MODE) 
#define USE_USART_DMA_MODE TRUE 
#endif

    
#define USART1 OS_USART_1 
#define USART2 OS_USART_2 
#define USART3 OS_USART_3 
#define UART4 OS_UART_4 
#define UART5 OS_UART_5 
#define LPUART1 OS_LPUART_1 

#if (FULL_DUPLEX_MODE == TRUE) 
//TODO:Add Functions and include USART State 
//including Errorhandling .
void os_init_usart_config(void) ;
void os_init_usart(u32 baudrate )  ;
void os_send_frame(u8* data , usart_state_wrapper_t * state ) ;
u8 os_receive_frame(usart_state_wrapper_t * state); 
void os_init_print_char(u8 data);
void os_init_print_string(char * str);

#endif





#endif /*< OS_HAL_UART_H */