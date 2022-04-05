/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	DIO Driver                             							  	          */
/*  Project Description    :	DIO Driver                                                 				      */
/*  Target Controller 	   :	Atmega 32                                               					  */
/*  File Name              :	DIO_interface.h                                    						      */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
/*---------------------------------------------------------------------------------------*/
#ifndef     DIO_PRIVATE_H
#define 	DIO_PRIVATE_H
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Registers Definitions       		     		          	  	              */
/* ---------------------------------------------------------------------------------------------------------- */

/*                      PORTA Registers                                                  */
#define			DIO_DDRA				*((volatile u8 *)0x3A)
#define			DIO_PORTA				*((volatile u8 *)0x3B)
#define			DIO_PINA				*((volatile u8 *)0x39)
/*_______________________________________________________________________________________*/

/*                      PORTB Registers                                                  */
#define			DIO_DDRB			    *((volatile u8 *)0x37)
#define			DIO_PORTB				*((volatile u8 *)0x38)
#define			DIO_PINB				*((volatile u8 *)0x36)
/*_______________________________________________________________________________________*/

/*                      PORTC Registers                                                  */
#define			DIO_DDRC				*((volatile u8 *)0x34)
#define			DIO_PORTC				*((volatile u8 *)0x35)
#define			DIO_PINC				*((volatile u8 *)0x33)
/*_______________________________________________________________________________________*/

/*                      PORTD Registers                                                  */
#define			DIO_DDRD				*((volatile u8 *)0x31)
#define			DIO_PORTD				*((volatile u8 *)0x32)
#define			DIO_PIND				*((volatile u8 *)0x30)
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */

/*THE FOLLOWING DEFINITIONS ARE USED INTERNALLY TO SET ALL PORT REGISTER                 */
/*                      PORT SET DIRECTION                                               */
#define         ALL_INPUT               0x00
#define         ALL_OUTPUT              0xFF
/*_______________________________________________________________________________________*/

/*                      PORT SET VALUE                                                   */
#define         ALL_LOW                 0x00
#define         ALL_HIGH                0xFF
/*_______________________________________________________________________________________*/

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