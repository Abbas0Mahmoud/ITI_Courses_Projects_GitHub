/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Documentation        		     		          	  	  			  */
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
#ifndef     DIO_INTERFACE_H
#define 	DIO_INTERFACE_H
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Definitions       		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */

/*          Ports Name Definitions                                                       */
#define     PORTA	            0
#define     PORTB	            1
#define     PORTC	            2
#define     PORTD	            3
/*_______________________________________________________________________________________*/

/*		    Pins Name Definitions                                                        */
#define     PIN0	            0
#define     PIN1	            1
#define     PIN2	            2
#define     PIN3	            3
#define     PIN4	            4
#define     PIN5	            5
#define     PIN6	            6
#define     PIN7	            7
/*_______________________________________________________________________________________*/

/*		    Direction Definitions For Port Pin/Pins		                                 */
#define     INPUT 	            0
#define     OUTPUT              1
#define     INPUT_PULLUP        3
/*_______________________________________________________________________________________*/

/*          Value Definitions For Port Pin/Pins                                          */
#define     HIGH                1
#define     LOW                 0
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Global Declerations       		     		          	  	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Function Prototypes       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
    Function Description        :
	Function Return Type        :
	Function Arguments          :
    Function Arguments Datatype :
	_____________________________
	Function Parameters Options :
	_____________________________

    u8 Copy_u8PortName:
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Name
    Parameter Values :        PORTA - PORTB - PORTC - PORTD

    u8 Copy_u8PinNumber :
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Pin Name
    Parameter Values :        PIN0 - PIN1 - PIN2 - PIN3 - PIN4 - PIN5 - PIN6 - PIN7

    u8 Copy_u8PinDirection:
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Pin Direction
    Parameter Values :        INPUT - OUTPUT - INPUT_PULLUP
*/
/* ----------------------------------------------------------------------------------------------- */
void MDIO_voidSetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinDirection);
/*_________________________________________________________________________________________________*/

/* ----------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
	_____________________________
	Function Parameters Options :
	_____________________________

    u8 Copy_u8PortName:
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Name
    Parameter Values :        PORTA - PORTB - PORTC - PORTD

    u8 Copy_u8PinNumber :
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Pin Name
    Parameter Values :        PIN0 - PIN1 - PIN2 - PIN3 - PIN4 - PIN5 - PIN6 - PIN7

    u8 Copy_u8PinValue:
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Pin Value
    Parameter Values :        HIGH - LOW
*/
/* ----------------------------------------------------------------------------------------------- */
void MDIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);
/*_________________________________________________________________________________________________*/

/* ----------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
	_____________________________
	Function Parameters Options :
	_____________________________

    u8 Copy_u8PortName:
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Name
    Parameter Values :        PORTA - PORTB - PORTC - PORTD

    u8 Copy_u8PinNumber :
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Pin Name
    Parameter Values :        PIN0 - PIN1 - PIN2 - PIN3 - PIN4 - PIN5 - PIN6 - PIN7
*/
/* ----------------------------------------------------------------------------------------------- */
void MDIO_voidTogglePinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber);
/*_________________________________________________________________________________________________*/

/* ----------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
	_____________________________
	Function Parameters Options :
	_____________________________

    u8 Copy_u8PortName:
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Name
    Parameter Values :        PORTA - PORTB - PORTC - PORTD

    u8Copy_u8PortDirection:
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Direction
    Parameter Values :        INPUT - OUTPUT - INPUT_PULLUP
*/
/* ----------------------------------------------------------------------------------------------- */
void MDIO_voidSetPortDirection(u8 Copy_u8PortName,u8 Copy_u8PortDirection);
/*_________________________________________________________________________________________________*/


/* ----------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
	_____________________________
	Function Parameters Options :
	_____________________________

    u8 Copy_u8PortName:
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Name
    Parameter Values :        PORTA - PORTB - PORTC - PORTD

    u8 Copy_u8PortValue:
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Value
    Parameter Values :        HIGH - LOW
*/
/* ----------------------------------------------------------------------------------------------- */
void MDIO_voidSetPortValue(u8 Copy_u8PortName,u8 Copy_u8PortValue);
/*_________________________________________________________________________________________________*/

/* ----------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
	_____________________________
	Function Parameters Options :
	_____________________________

    u8 Copy_u8PortName:
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Name
    Parameter Values :        PORTA - PORTB - PORTC - PORTD

    u8 Copy_u8PortPinsDirection:
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Pins Direction
    Parameter Values :        8 Bits Decimal,Hexadecimal,Binary Value
*/
/* ----------------------------------------------------------------------------------------------- */
void MDIO_voidSetPortSpecificDirection(u8 Copy_u8PortName, u8 Copy_u8PortPinsDirection);
/*_________________________________________________________________________________________________*/

/* ----------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
	_____________________________
	Function Parameters Options :
	_____________________________

    Function Parameters :
    u8 Copy_u8PortName:
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Name
    Parameter Values :        PORTA - PORTB - PORTC - PORTD

    u8 Copy_u8PortPinsValue:
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Pins Value
    Parameter Values :        8 Bits Decimal,Hexadecimal,Binary Value
*/
/* ----------------------------------------------------------------------------------------------- */
void MDIO_voidSetPortSpecificValue(u8 Copy_u8PortName, u8 Copy_u8PortPinsValue);
/*_________________________________________________________________________________________________*/

/* ----------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
	_____________________________
	Function Parameters Options :
	_____________________________

    u8 Copy_u8PortName:
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Name
    Parameter Values :        PORTA - PORTB - PORTC - PORTD

    u8 Copy_u8PinName:
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Pin Value
    Parameter Values :        PIN0 - PIN1 - PIN2 - PIN3 - PIN4 - PIN5 - PIN6 - PIN7
*/
/* ----------------------------------------------------------------------------------------------- */
u8 MDIO_u8GetPinValue(u8 Copy_u8PortName , u8 Copyu8PinName);
/*_________________________________________________________________________________________________*/

/* ----------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
	_____________________________
	Function Parameters Options :
	_____________________________

    u8 Copy_u8PortName:
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Name
    Parameter Values :        PORTA - PORTB - PORTC - PORTD
*/
/* ----------------------------------------------------------------------------------------------- */
u8 MDIO_u8GetPortValue(u8 Copy_u8PortName);
/*_________________________________________________________________________________________________*/

#endif