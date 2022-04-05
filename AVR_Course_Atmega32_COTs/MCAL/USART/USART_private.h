/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	USART Driver                             							  	      */
/*  Project Description    :	USART Driver                                                 				  */
/*  Target Controller 	   :	Atmega 32                                               					  */
/*  File Name              :	USART_private.h                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*          Header Guard File                                            */
#ifndef     USART_PRIVATE_H
#define 	USART_PRIVATE_H

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Registers Definitions       		     		          	  	              */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*
    USART Control and Status Register A
*/
#define     UCSRA                   *((volatile u8 *)0x2B)
/*
    This bit enables the Multi-processor Communication mode. When the MPCM bit is written to one,
    all the incoming frames received by the USART receiver that do not contain
    address information will be ignored
*/
#define     UCSRA_MPCM              0
/*
    Writing this bit to one will reduce the divisor of the baud rate
    divider from 16 to 8 effectively doubling the transfer rate for asynchronous communication
*/
#define     UCSRA_U2X               1
/*
    This bit is set if the next character in the receive buffer had a Parity Error when received
    and the parity checking was enabled at that point (UPM1 = 1). This bit is valid until the
    receive buffer (UDR) is read. Always set this bit to zero when writing to UCSRA.
*/
#define     UCSRA_PE                2
/*
*/
#define     UCSRA_DOR               3
/*
*/
#define     UCSRA_FE                4
/*
    The UDRE Flag indicates if the transmit buffer (UDR) is ready to receive new data. If
    UDRE is one, the buffer is empty, and therefore ready to be written
*/
#define     UCSRA_UDRE              5
/*
    This flag bit is set when the entire frame in the transmit Shift Register has been shifted
    out and there are no new data currently present in the transmit buffer (UDR). The TXC
    Flag bit is automatically cleared when a transmit complete interrupt is executed, or it can
    be cleared by writing a one to its bit location.
*/
#define     UCSRA_TXC               6
/*
    This flag bit is set when there are unread data in the receive buffer and cleared when the
    receive buffer is empty (i.e., does not contain any unread data).
    If the receiver is disabled, the receive buffer will be flushed and consequently the RXC bit will become zero.
*/
#define     UCSRA_RXC               7

/* ---------------------------------------------------------------------------------------------------------- */

/*
    USART Control and Status Register B
*/
#define     UCSRB                   *((volatile u8 *)0x2A)
/*
    TXB8 is the ninth data bit in the character to be transmitted when operating with serial
    frames with nine data bits. Must be written before writing the low bits to UDR.
*/
#define     UCSRB_TX8               0
/*
    RXB8 is the ninth data bit of the received character when operating with serial frames
    with nine data bits. Must be read before reading the low bits from UDR.
*/
#define     UCSRB_RX8               1
/*
    The UCSZ2 bits combined with the UCSZ1:0 bit in UCSRC sets the number of data bits
    (Character Size) in a frame the receiver and transmitter use.
*/
#define     UCSRB_UCSZ2             2
/*
    Writing this bit to one enables the USART Transmitter.
*/
#define     UCSRB_TXEN              3
/*
    Writing this bit to one enables the USART Receiver.
*/
#define     UCSRB_RXEN              4
/*
    Writing this bit to one enables interrupt on the UDRE Flag.
    A Data Register Empty Interrupt will be generated only if the UDRIE bit is written to one, the Global Interrupt Flag in
    SREG is written to one and the UDRE bit in UCSRA is set.
*/
#define     UCSRB_UDRIE             5
/*
    Writing this bit to one enables interrupt on the TXC Flag. A USART Transmit Complete
    Interrupt will be generated only if the TXCIE bit is written to one, the Global Interrupt
    Flag in SREG is written to one and the TXC bit in UCSRA is set.
*/
#define     UCSRB_TXCIE             6
/*
    Writing this bit to one enables interrupt on the RXC Flag. A USART Receive Complete
    Interrupt will be generated only if the RXCIE bit is written to one, the Global Interrupt
    Flag in SREG is written to one and the RXC bit in UCSRA is set.
*/
#define     UCSRB_RXCIE             7

#define     UCSRC                   *((volatile u8 *)0x40)
#define     UCSRC_UCPOL             0
#define     UCSRC_UCSZ0             1
#define     UCSRC_UCSZ1             2
#define     UCSRC_USBS              3
#define     UCSRC_UPM0              4
#define     UCSRC_UPM1              5
#define     UCSRC_UMSEL             6
#define     UCSRC_URSEL             7

#define     UBRRH                   *((volatile u8 *)0x40)
#define     UBRRH_URSEL             7

#define     UBRRL                   *((volatile u8 *)0x29)

#define     UDR                     *((volatile u8 *)0x2C)

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Global Declerations       		     		          	  	  	      */
/* ---------------------------------------------------------------------------------------------------------- */


/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Prototypes       		     		          	  		      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Implementations       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

#endif