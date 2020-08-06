/*
 * UART.h
 *
 * Created: 8/1/2020 5:29:53 AM
 *  Author: Khaledseif166
 */ 


#ifndef UART_H_
#define UART_H_

#include "DIO.h"

#define F_CPU          8000000
#define baud_rate      9600
#define Speed          16


/******************************************************** Control status register A configration bits  **********************************************/

#define MPCM_DISAPLE         0
#define MPCM_ENABLE          1


#define U2X_NORMAL           0
#define U2X_DOUPLE           1


#define PE_DISABLE           0
#define PE_ENABLE            1

#define DOR_DISABLE          0
#define DOR_ENABLE           1

#define FE_DISABLE           0
#define FE_ENABLE            1

/******************************************************** Control status register B configration bits  **********************************************/
     
#define TXB8_DISABLE         0
#define TXB8_ENABLE          1

#define RXB8_DISABLE         0
#define RXB8_ENABLE          1   	 

#define TXEN_DISABLE         0
#define TXEN_ENABLE          1


#define RXEN_DISABLE         0
#define RXEN_ENABLE          1

#define UDRIE_DISABLE        0
#define UDRIE_ENABLE         1

#define TXCIE_DISABLE        0
#define TXCIE_ENABLE         1

#define RXCIE_DISABLE        0
#define RXCIE_ENABLE         1

//this bit work only if Synchronous mode selected
#define UCPOL_RISING        0        //Generate a pulses only at rising Edges
#define UCPOL_FALLING       1        //Generate a pulses only at falling edges 

//UCSZ Data bits Setting

#define UCSZ_5BITS    0 
#define UCSZ_6BITS    1
#define UCSZ_7BITS    2 
#define UCSZ_8BITS    3 
#define UCSZ_RES1     4 
#define UCSZ_RES2     5 
#define UCSZ_RES3     6 
#define UCSZ_9BITS    7 

//Stop bits select

#define USBS_1BIT    0
#define USBS_2BIT    1

//Parity mode selection

#define UPM_DISABLE  0
#define UPM_RESEVED  1
#define UPM_EVEN     2
#define UPM_ODD      3

//USART mode selection bit

#define UMSEL_ASYNCH    0
#define UMSEL_SYNCH     1


//URSEL: Register select

#define URSEL_UBRRH     0
#define URSEL_UCSRC     1

/*****************************************************       Function prototypes     *****************************************************************/

void USART_INIT(void);
void USART_TX_CHAR(uint8 data);
void USART_TX_STRING(uint8 *str);
uint8 USART_RX_CHAR(void);
uint8 USART_RX_STRING(void);


/*****************************************************        USART CONFIGRATION      *******************************************************************/

#define Mode_select               UMSEL_ASYNCH
#define Reg_select                URSEL_UCSRC
#define PARITY_mode               UPM_DISABLE
#define stop_bits_num             USBS_1BIT 
#define Data_bits_num             UCSZ_8BITS
#define Transmitter_status        TXEN_ENABLE
#define Recevier_status           RXEN_ENABLE
#define TX_9bit_status            TXB8_DISABLE
#define RX_9bit_status            RXB8_DISABLE
#define RX_interrupt_status       RXCIE_ENABLE
#define TX_interrupt_status       TXCIE_DISABLE
#define FE_status                 FE_DISABLE
#define DOR_STATUS                DOR_DISABLE
#define parity_status             PE_DISABLE
#define Speed_status              U2X_NORMAL
#define MPCM_status               MPCM_DISAPLE

#endif /* UART_H_ */