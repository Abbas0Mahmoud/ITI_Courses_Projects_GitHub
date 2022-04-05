/*                      		Header Log File                                  						      */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	GPIO Driver                             							  	      */
/*  Project Description    :	GPIO Driver for STM32F10x Family                             				  */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	GPIO_interface.h                                    						  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
/*---------------------------------------------------------------------------------------*/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Definitions       		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */

/*			GPIO PORT OPTIONS											       */
#define     GPIO_PORTA                                     0
#define     GPIO_PORTB                                     1
#define     GPIO_PORTC                                     2

/*			GPIO PIN OPTIONS												   */
#define     GPIO_PIN0                                      0
#define     GPIO_PIN1                                      1
#define     GPIO_PIN2                                      2
#define     GPIO_PIN3                                      3
#define     GPIO_PIN4                                      4
#define     GPIO_PIN5                                      5
#define     GPIO_PIN6                                      6
#define     GPIO_PIN7                                      7
#define     GPIO_PIN8                                      8
#define     GPIO_PIN9                                      9
#define     GPIO_PIN10                                     10
#define     GPIO_PIN11                                     11
#define     GPIO_PIN12                                     12
#define     GPIO_PIN13                                     13
#define     GPIO_PIN14                                     14
#define     GPIO_PIN15                                     15

/*			GPIO MODE OPTIONS												   */
#define     GPIO_INPUT_MODE                                0
#define     GPIO_OUTPUT_MODE_10_MHZ                        1
#define     GPIO_OUTPUT_MODE_2_MHZ                         2
#define     GPIO_OUTPUT_MODE_50_MHZ                        3

/*			GPIO INPUT MODE CONFIGURATION OPTIONS							   */
#define     GPIO_INPUT_MODE_CNF_ANALOG                     0
#define     GPIO_INPUT_MODE_CNF_FLOATING                   1
#define     GPIO_INPUT_MODE_CNF_PULL_UP_DOWN               2

/*			GPIO OUTPUT MODE CONFIGURATION OPTIONS							   */
#define     GPIO_OUTPUT_MODE_CNF_GP_PUSH_PULL              0
#define     GPIO_OUTPUT_MODE_CNF_GP_OPEN_DRAIN             1
#define     GPIO_OUTPUT_MODE_CNF_AF_PUSH_PULL              2
#define     GPIO_OUTPUT_MODE_CNF_AF_OPEN_DRAIN             3

/*			GPIO INPUT MODE PULL_UP_DOWN CONFIGURATION OPTIONS				   */
#define     GPIO_INPUT_MODE_CNF_PULL_UP                    0
#define     GPIO_INPUT_MODE_CNF_PULL_DOWN                  1

/*			GPIO OUTPUT MODE STATE OPTIONS									   */
#define     GPIO_LOW                                       0
#define     GPIO_HIGH                                      1



/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Global Declerations       		     		          	  	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Function Prototypes       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                           Functions To Manipulate Port Pins Individually       		     		         */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		    :
	Function Return Type    :
	Function Description    :
	Function Input Datatype :

	Function Parameters Options :
	_____________________________

	u8 Copy_u8PortName :
							GPIO_PORTA
							GPIO_PORTB
							GPIO_PORTC

	u8 Copy_u8PinNumber :
							GPIO_PIN0 - GPIO_PIN1 - GPIO_PIN2 - GPIO_PIN3 - GPIO_PIN4 - GPIO_PIN5 - GPIO_PIN6 - GPIO_PIN7
                            GPIO_PIN8 - GPIO_PIN9 - GPIO_PIN10 - GPIO_PIN11 - GPIO_PIN12 - GPIO_PIN13 - GPIO_PIN14 - GPIO_PIN15

	u8 Copy_u8PinMode :
							GPIO_INPUT_MODE
							GPIO_OUTPUT_MODE_10_MHZ
							GPIO_OUTPUT_MODE_2_MHZ
							GPIO_OUTPUT_MODE_50_MHZ

	u8 Copy_u8PinCNF :
							GPIO_INPUT_MODE_CNF_ANALOG
							GPIO_INPUT_MODE_CNF_FLOATING
							GPIO_INPUT_MODE_CNF_PULL_UP_DOWN
							GPIO_OUTPUT_MODE_CNF_GP_PUSH_PULL
							GPIO_OUTPUT_MODE_CNF_GP_OPEN_DRAIN
							GPIO_OUTPUT_MODE_CNF_AF_PUSH_PULL
							GPIO_OUTPUT_MODE_CNF_AF_OPEN_DRAIN

*/
/* ---------------------------------------------------------------------------------------------------------- */
void MGPIO_voidSetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode, u8 Copy_u8PinCNF);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		 :
	Function Return Type :
	Function Description :

	Function Parameters Options :
	_____________________________

	u8 Copy_u8PortName :
							GPIO_PORTA
							GPIO_PORTB
							GPIO_PORTC

	u8 Copy_u8PinNumber :
							GPIO_PIN0 - GPIO_PIN1 - GPIO_PIN2 - GPIO_PIN3 - GPIO_PIN4 - GPIO_PIN5 - GPIO_PIN6 - GPIO_PIN7
                            GPIO_PIN8 - GPIO_PIN9 - GPIO_PIN10 - GPIO_PIN11 - GPIO_PIN12 - GPIO_PIN13 - GPIO_PIN14 - GPIO_PIN15

	u8 Copy_u8PinCNF :
							GPIO_INPUT_MODE_CNF_PULL_UP
							GPIO_INPUT_MODE_CNF_PULL_DOWN
*/
/* ---------------------------------------------------------------------------------------------------------- */
void MGPIO_voidSetPinInputPullUpDown(u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_u8PinCFN);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		    :
	Function Return Type    :
	Function Description    :
	Function Input Datatype :

	Function Parameters Options :
	_____________________________

	u8 Copy_u8PortName :
							GPIO_PORTA
							GPIO_PORTB
							GPIO_PORTC

	u8 Copy_u8PinNumber :
							GPIO_PIN0 - GPIO_PIN1 - GPIO_PIN2 - GPIO_PIN3 - GPIO_PIN4 - GPIO_PIN5 - GPIO_PIN6 - GPIO_PIN7
                            GPIO_PIN8 - GPIO_PIN9 - GPIO_PIN10 - GPIO_PIN11 - GPIO_PIN12 - GPIO_PIN13 - GPIO_PIN14 - GPIO_PIN15
	u8 Copy_u8PinValue :
							GPIO_LOW
							GPIO_HIGH

*/
/* ---------------------------------------------------------------------------------------------------------- */
void MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		    :
	Function Return Type    :
	Function Description    :
	Function Input Datatype :

	Function Parameters Options :
	_____________________________

	u8 Copy_u8PortName :
							GPIO_PORTA
							GPIO_PORTB
							GPIO_PORTC

	u8 Copy_u8PinNumber :
							GPIO_PIN0 - GPIO_PIN1 - GPIO_PIN2 - GPIO_PIN3 - GPIO_PIN4 - GPIO_PIN5 - GPIO_PIN6 - GPIO_PIN7
                            GPIO_PIN8 - GPIO_PIN9 - GPIO_PIN10 - GPIO_PIN11 - GPIO_PIN12 - GPIO_PIN13 - GPIO_PIN14 - GPIO_PIN15

	u8 Copy_u8PinValue :
							GPIO_LOW
							GPIO_HIGH
*/
/* ---------------------------------------------------------------------------------------------------------- */
void MGPIO_voidSetPinValueAtomic(u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_u8PinValue);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		    :
	Function Return Type    :
	Function Description    :
	Function Input Datatype :

	Function Parameters Options :
	_____________________________

	u8 Copy_u8PortName :
							GPIO_PORTA
							GPIO_PORTB
							GPIO_PORTC

	u8 Copy_u8PinNumber :
							GPIO_PIN0 - GPIO_PIN1 - GPIO_PIN2 - GPIO_PIN3 - GPIO_PIN4 - GPIO_PIN5 - GPIO_PIN6 - GPIO_PIN7
                            GPIO_PIN8 - GPIO_PIN9 - GPIO_PIN10 - GPIO_PIN11 - GPIO_PIN12 - GPIO_PIN13 - GPIO_PIN14 - GPIO_PIN15
*/
/* ---------------------------------------------------------------------------------------------------------- */
u8 MGPIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		    :
	Function Return Type    :
	Function Description    :
	Function Input Datatype :

	Function Parameters Options :
	_____________________________

	u8 Copy_u8PortName :
							GPIO_PORTA
							GPIO_PORTB
							GPIO_PORTC

	u8 Copy_u8PinNumber :
							GPIO_PIN0 - GPIO_PIN1 - GPIO_PIN2 - GPIO_PIN3 - GPIO_PIN4 - GPIO_PIN5 - GPIO_PIN6 - GPIO_PIN7
                            GPIO_PIN8 - GPIO_PIN9 - GPIO_PIN10 - GPIO_PIN11 - GPIO_PIN12 - GPIO_PIN13 - GPIO_PIN14 - GPIO_PIN15
*/
/* ---------------------------------------------------------------------------------------------------------- */
u8 MGPIO_u8LockPinConfiguration(u8 Copy_u8PortName,u8 Copy_u8PinNumber);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		    :
	Function Return Type    :
	Function Description    :
	Function Input Datatype :

	Function Parameters Options :
	_____________________________

	u8 Copy_u8PortName :
							GPIO_PORTA - GPIO_PORTB - GPIO_PORTC

	u8 Copy_u8PinNumber :
							GPIO_PIN0 - GPIO_PIN1 - GPIO_PIN2 - GPIO_PIN3 - GPIO_PIN4 - GPIO_PIN5 - GPIO_PIN6 - GPIO_PIN7
                            GPIO_PIN8 - GPIO_PIN9 - GPIO_PIN10 - GPIO_PIN11 - GPIO_PIN12 - GPIO_PIN13 - GPIO_PIN14 - GPIO_PIN15

	u8 Copy_u8PinMode :
							GPIO_INPUT_MODE
							GPIO_OUTPUT_MODE_10_MHZ
							GPIO_OUTPUT_MODE_2_MHZ
							GPIO_OUTPUT_MODE_50_MHZ

	u8 Copy_u8PinCNF :
							GPIO_INPUT_MODE_CNF_ANALOG
							GPIO_INPUT_MODE_CNF_FLOATING
							GPIO_INPUT_MODE_CNF_PULL_UP_DOWN
							GPIO_OUTPUT_MODE_CNF_GP_PUSH_PULL
							GPIO_OUTPUT_MODE_CNF_GP_OPEN_DRAIN
							GPIO_OUTPUT_MODE_CNF_AF_PUSH_PULL
							GPIO_OUTPUT_MODE_CNF_AF_OPEN_DRAIN

*/
/* ---------------------------------------------------------------------------------------------------------- */
void MGPIO_voidSetPinDirectionInRange(u8 Copy_u8PortName, u8 Copy_u8StartPin, u8 Copy_u8EndPin, u8 Copy_u8PinMode, u8 Copy_u8PinCNF);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		 :
	Function Return Type :
	Function Description :

	Function Parameters Options :
	_____________________________

	u8 Copy_u8PortName :
							GPIO_PORTA - GPIO_PORTB - GPIO_PORTC

	u8 Copy_u8PinNumber :
							GPIO_PIN0 - GPIO_PIN1 - GPIO_PIN2 - GPIO_PIN3 - GPIO_PIN4 - GPIO_PIN5 - GPIO_PIN6 - GPIO_PIN7
                            GPIO_PIN8 - GPIO_PIN9 - GPIO_PIN10 - GPIO_PIN11 - GPIO_PIN12 - GPIO_PIN13 - GPIO_PIN14 - GPIO_PIN15

	u8 Copy_u8PinCNF :
							GPIO_INPUT_MODE_CNF_PULL_UP
							GPIO_INPUT_MODE_CNF_PULL_DOWN
*/
/* ---------------------------------------------------------------------------------------------------------- */
void MGPIO_voidSetPinInputPullUpDownInRange(u8 Copy_u8PortName,u8 Copy_u8StartPin,u8 Copy_u8EndPin,u8 Copy_u8PinCFN);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		    :
	Function Return Type    :
	Function Description    :
	Function Input Datatype :

	Function Parameters Options :
	_____________________________

	u8 Copy_u8PortName :
							GPIO_PORTA - GPIO_PORTB - GPIO_PORTC

	u8 Copy_u8PinNumber :
							GPIO_PIN0 - GPIO_PIN1 - GPIO_PIN2 - GPIO_PIN3 - GPIO_PIN4 - GPIO_PIN5 - GPIO_PIN6 - GPIO_PIN7
                            GPIO_PIN8 - GPIO_PIN9 - GPIO_PIN10 - GPIO_PIN11 - GPIO_PIN12 - GPIO_PIN13 - GPIO_PIN14 - GPIO_PIN15

	u8 Copy_u8PinValue :
							GPIO_LOW
							GPIO_HIGH

*/
/* ---------------------------------------------------------------------------------------------------------- */
void MGPIO_voidSetPinValueInRange(u8 Copy_u8PortName,u8 Copy_u8StartPin,u8 Copy_u8EndPin,u8 Copy_u8PinValue);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		    :
	Function Return Type    :
	Function Description    :
	Function Input Datatype :

	Function Parameters Options :
	_____________________________

	u8 Copy_u8PortName :
							GPIO_PORTA - GPIO_PORTB - GPIO_PORTC

	u8 Copy_u8PinNumber :
							GPIO_PIN0 - GPIO_PIN1 - GPIO_PIN2 - GPIO_PIN3 - GPIO_PIN4 - GPIO_PIN5 - GPIO_PIN6 - GPIO_PIN7
                            GPIO_PIN8 - GPIO_PIN9 - GPIO_PIN10 - GPIO_PIN11 - GPIO_PIN12 - GPIO_PIN13 - GPIO_PIN14 - GPIO_PIN15

	u8 Copy_u8PinValue :
							GPIO_LOW
							GPIO_HIGH
*/
/* ---------------------------------------------------------------------------------------------------------- */
void MGPIO_voidSetAtomicValueAtomicInRange(u8 Copy_u8PortName,u8 Copy_u8StartPin,u8 Copy_u8EndPin,u8 Copy_u8PinValue);
/*____________________________________________________________________________________________________________*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                   		         Functions To Manipulate All PORT       		     		             */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		    :
	Function Return Type    :
	Function Description    :
	Function Input Datatype :

	Function Parameters Options :
	_____________________________

	u8 Copy_u8PortName :
							GPIO_PORTA
							GPIO_PORTB
							GPIO_PORTC

	u8 Copy_u8PortMode :
							GPIO_INPUT_MODE
							GPIO_OUTPUT_MODE_10_MHZ
							GPIO_OUTPUT_MODE_2_MHZ
							GPIO_OUTPUT_MODE_50_MHZ

	u8 Copy_u8PortCFN :
							GPIO_INPUT_MODE_CNF_ANALOG
							GPIO_INPUT_MODE_CNF_FLOATING
							GPIO_INPUT_MODE_CNF_PULL_UP_DOWN
							GPIO_OUTPUT_MODE_CNF_GP_PUSH_PULL
							GPIO_OUTPUT_MODE_CNF_GP_OPEN_DRAIN
							GPIO_OUTPUT_MODE_CNF_AF_PUSH_PULL
							GPIO_OUTPUT_MODE_CNF_AF_OPEN_DRAIN
*/
/* ---------------------------------------------------------------------------------------------------------- */
void MGPIO_voidSetPortDirection(u8 Copy_u8PortName,u8 Copy_u8PortMode,u8 Copy_u8PortCFN);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		    :
	Function Return Type    :
	Function Description    :
	Function Input Datatype :

	Function Parameters Options :
	_____________________________

	u8 Copy_u8PortName :
							GPIO_PORTA
							GPIO_PORTB

	u8 Copy_u8PortMode :
							8 Bit Value IN Range of (0,255)

	u8 Copy_u8PortCFN :
							8 Bit Value IN Range of (0,255)
*/
/* ---------------------------------------------------------------------------------------------------------- */
void MGPIO_voidSetPortLowPinsSpecificDirection(u8 Copy_u8PortName,u32 Copy_u8PinsSpecificMode,u32 Copy_u8PinsSpecificCFN);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		    :
	Function Return Type    :
	Function Description    :
	Function Input Datatype :

	Function Parameters Options :
	_____________________________

	u8 Copy_u8PortName :
							GPIO_PORTA
							GPIO_PORTB

	u8 Copy_u8PortMode :
							8 Bit Value IN Range of (0,0xFF)

	u8 Copy_u8PortCFN :
							8 Bit Value IN Range of (0,0xFF)
*/
/* ---------------------------------------------------------------------------------------------------------- */
void MGPIO_voidSetPortHighPinsSpecificDirection(u8 Copy_u8PortName,u32 Copy_u8PinsSpecificMode,u32 Copy_u8PinsSpecificCFN);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		    :
	Function Return Type    :
	Function Description    :
	Function Input Datatype :

	Function Parameters Options :
	_____________________________

	u8 Copy_u8PortName :
							GPIO_PORTA
							GPIO_PORTB

	u8 Copy_u8PortCFN :
							ALL_GPIO_INPUT_MODE_CNF_PULL_UP
							ALL_GPIO_INPUT_MODE_CNF_PULL_DOWN
*/
/* ---------------------------------------------------------------------------------------------------------- */
void MGPIO_voidSetPortInputPullUpDown(u8 Copy_u8PortName,u8 Copy_u8PortCFN);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		    :
	Function Return Type    :
	Function Description    :
	Function Input Datatype :

	Function Parameters Options :
	_____________________________

	u8 Copy_u8PortName :
							GPIO_PORTA
							GPIO_PORTB

	u8 Copy_u8PortValue :
							ALL_GPIO_LOW
							ALL_GPIO_HIGH
*/
/* ---------------------------------------------------------------------------------------------------------- */
void MGPIO_voidSetPortValue(u8 Copy_u8PortName,u8 Copy_u8PortValue);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		    :
	Function Return Type    :
	Function Description    :
	Function Input Datatype :

	Function Parameters Options :
	_____________________________

	u8 Copy_u8PortName :
							GPIO_PORTA
							GPIO_PORTB

	u8 Copy_u8PortValue :
							ALL_GPIO_LOW
							ALL_GPIO_HIGH
*/
/* ---------------------------------------------------------------------------------------------------------- */
void MGPIO_voidSetPortValueAtomic(u8 Copy_u8PortName,u8 Copy_u8PortValue);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		    :
	Function Return Type    :
	Function Description    :
	Function Input Datatype :

	Function Parameters Options :
	_____________________________

	u8 Copy_u8PortName :
							GPIO_PORTA
							GPIO_PORTB

	u32 Copy_u32PortValue :
							16 Bit Value IN Range of (0x0000,0xFFFF)
*/
/* ---------------------------------------------------------------------------------------------------------- */
void MGPIO_voidSetPortSpecificValue(u8 Copy_u8PortName,u32 Copy_u32PortValue);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		    :
	Function Return Type    :
	Function Description    :
	Function Input Datatype :

	Function Parameters Options :
	_____________________________

	u8 Copy_u8PortName :
							GPIO_PORTA
							GPIO_PORTB
*/
/* ---------------------------------------------------------------------------------------------------------- */
u32 MGPIO_u32GetPortValue(u8 Copy_u8PortName);
/*____________________________________________________________________________________________________________*/

#endif /* GPIO_INTERFACE_H_ */
