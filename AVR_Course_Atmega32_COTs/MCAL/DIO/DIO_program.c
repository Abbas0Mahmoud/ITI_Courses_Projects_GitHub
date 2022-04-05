/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	ADC Driver                             							  	          */
/*  Project Description    :	ADC Driver                                                 				      */
/*  Target Controller 	   :	Atmega 32                                               					  */
/*  File Name              :	ADC_interface.h                                    						      */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/*		                        Library Inclusions								         */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*_______________________________________________________________________________________*/

/*		                        HAL Layer Inclusion							             */

/*_______________________________________________________________________________________*/

/*		                        MCAL Layer Inclusion					                 */

/*_______________________________________________________________________________________*/

/*		                Self Files Inclusoins							                 */
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Interface Function Implementations       		     		          */
/* ---------------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
	_____________________________
	Function Parameters Options :
	_____________________________
*/
/* ------------------------------------------------------------------------------------- */
void MDIO_voidSetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinDirection)
{
	if(Copy_u8PinNumber <= PIN7)
	{
		switch(Copy_u8PortName)
		{
			case PORTA:
				switch(Copy_u8PinDirection)
				{
					case INPUT:
						CLR_REG_BIT(DIO_DDRA,Copy_u8PinNumber);
						break;
					case OUTPUT:
						SET_REG_BIT(DIO_DDRA,Copy_u8PinNumber);
						break;
					case INPUT_PULLUP:
						CLR_REG_BIT(DIO_DDRA,Copy_u8PinNumber);
						SET_REG_BIT(DIO_PORTA,Copy_u8PinNumber);
						break;
				}
			break;
			case PORTB:
				switch(Copy_u8PinDirection)
				{
					case INPUT:
						CLR_REG_BIT(DIO_DDRB,Copy_u8PinNumber);
						break;
					case OUTPUT:
						SET_REG_BIT(DIO_DDRB,Copy_u8PinNumber);
						break;
					case INPUT_PULLUP:
						CLR_REG_BIT(DIO_DDRB,Copy_u8PinNumber);
						SET_REG_BIT(DIO_PORTB,Copy_u8PinNumber);
						break;
				}
			break;
			case PORTC:
				switch(Copy_u8PinDirection)
				{
					case INPUT:
						CLR_REG_BIT(DIO_DDRC,Copy_u8PinNumber);
						break;
					case OUTPUT:
						SET_REG_BIT(DIO_DDRC,Copy_u8PinNumber);
						break;
					case INPUT_PULLUP:
						CLR_REG_BIT(DIO_DDRC,Copy_u8PinNumber);
						SET_REG_BIT(DIO_PORTC,Copy_u8PinNumber);
						break;
				}
			break;
			case PORTD:
				switch(Copy_u8PinDirection)
				{
					case INPUT:
						CLR_REG_BIT(DIO_DDRD,Copy_u8PinNumber);
						break;
					case OUTPUT:
						SET_REG_BIT(DIO_DDRD,Copy_u8PinNumber);
						break;
					case INPUT_PULLUP:
						CLR_REG_BIT(DIO_DDRD,Copy_u8PinNumber);
						SET_REG_BIT(DIO_PORTD,Copy_u8PinNumber);
						break;
				}
			break;
			/*		Return Error		*/
		}
	}
	else
	{
		/*		Return Error		*/
	}
}
/*_________________________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
	_____________________________
	Function Parameters Options :
	_____________________________
*/
/* ------------------------------------------------------------------------------------- */
void MDIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
	if(Copy_u8PinNumber <= PIN7)
	{
		switch(Copy_u8PortName)
		{
			case PORTA:
				switch(Copy_u8PinValue)
				{
					case LOW:
						CLR_REG_BIT(DIO_PORTA,Copy_u8PinNumber);
						break;
					case HIGH:
						SET_REG_BIT(DIO_PORTA,Copy_u8PinNumber);
						break;
					/*		Return Error		*/
				}
			break;
			case PORTB:
				switch(Copy_u8PinValue)
				{
					case LOW:
						CLR_REG_BIT(DIO_PORTB,Copy_u8PinNumber);
						break;
					case HIGH:
						SET_REG_BIT(DIO_PORTB,Copy_u8PinNumber);
						break;
					/*		Return Error		*/
				}
			break;
			case PORTC:
				switch(Copy_u8PinValue)
				{
					case LOW:
						CLR_REG_BIT(DIO_PORTC,Copy_u8PinNumber);
						break;
					case HIGH:
						SET_REG_BIT(DIO_PORTC,Copy_u8PinNumber);
						break;
					/*		Return Error		*/
				}
			break;
			case PORTD:
				switch(Copy_u8PinValue)
				{
					case LOW:
						CLR_REG_BIT(DIO_PORTD,Copy_u8PinNumber);
						break;
					case HIGH:
						SET_REG_BIT(DIO_PORTD,Copy_u8PinNumber);
						break;
					/*		Return Error		*/
				}
			break;
			/*		Return Error		*/
		}
	}
	else
	{
		/*		Return Error		*/
	}
}
/*_________________________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
	_____________________________
	Function Parameters Options :
	_____________________________
*/
/* ------------------------------------------------------------------------------------- */
void MDIO_voidTogglePinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
	if(Copy_u8PinNumber <= PIN7)
	{
		switch(Copy_u8PortName)
		{
			case PORTA:
				TOGGLE_BIT(DIO_PORTA,Copy_u8PinNumber);
			break;
			case PORTB:
				TOGGLE_BIT(DIO_PORTB,Copy_u8PinNumber);
			break;
			case PORTC:
				TOGGLE_BIT(DIO_PORTC,Copy_u8PinNumber);
			break;
			case PORTD:
				TOGGLE_BIT(DIO_PORTD,Copy_u8PinNumber);
			break;
			/*		Return Error		*/
		}
	}
	else
	{
		/*		Return Error		*/
	}
}
/*_________________________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
	_____________________________
	Function Parameters Options :
	_____________________________
*/
/* ------------------------------------------------------------------------------------- */
void MDIO_voidSetPortDirection(u8 Copy_u8PortName,u8 Copy_u8PortDirection)
{
	switch(Copy_u8PortName)
	{
		case PORTA:
			switch(Copy_u8PortDirection)
			{
				case INPUT:
					DIO_DDRA = 	ALL_INPUT;
					break;
				case OUTPUT:
					DIO_DDRA = 	ALL_OUTPUT;
					break;
				case INPUT_PULLUP:
					DIO_DDRA  = ALL_INPUT;
					DIO_PORTA = ALL_HIGH;
					break;
				/*		Error		*/
			}
		break;
		case PORTB:
			switch(Copy_u8PortDirection)
			{
				case INPUT:
					DIO_DDRB = 	ALL_INPUT;
					break;
				case OUTPUT:
					DIO_DDRB = 	ALL_OUTPUT;
					break;
				case INPUT_PULLUP:
					DIO_DDRB  = ALL_INPUT;
					DIO_PORTB = ALL_HIGH;
					break;
				/*		Error		*/
			}
		break;
		case PORTC:
			switch(Copy_u8PortDirection)
			{
				case INPUT:
					DIO_DDRC = 	ALL_INPUT;
					break;
				case OUTPUT:
					DIO_DDRC = 	ALL_OUTPUT;
					break;
				case INPUT_PULLUP:
					DIO_DDRC  = ALL_INPUT;
					DIO_PORTC = ALL_HIGH;
					break;
				/*		Error		*/
			}
		break;
		case PORTD:
			switch(Copy_u8PortDirection)
			{
				case INPUT:
					DIO_DDRD = 	ALL_INPUT;
					break;
				case OUTPUT:
					DIO_DDRD = 	ALL_OUTPUT;
					break;
				case INPUT_PULLUP:
					DIO_DDRD  = ALL_INPUT;
					DIO_PORTD = ALL_HIGH;
					break;
				/*		Error		*/
			}
		break;
		/*		Error		*/
	}
}
/*_________________________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
	_____________________________
	Function Parameters Options :
	_____________________________
*/
/* ------------------------------------------------------------------------------------- */
void MDIO_voidSetPortValue(u8 Copy_u8PortName,u8 Copy_u8PortValue)
{
	switch(Copy_u8PortName)
	{
		case PORTA:
			switch(Copy_u8PortValue)
			{
				case LOW:
					DIO_PORTA = ALL_LOW;
					break;
				case HIGH:
					DIO_PORTA = ALL_HIGH;
					break;
				/*		Error		*/
			}
		break;
		case PORTB:
			switch(Copy_u8PortValue)
			{
				case LOW:
					DIO_PORTB = ALL_LOW;
					break;
				case HIGH:
					DIO_PORTC = ALL_HIGH;
					break;
				/*		Error		*/
			}
		break;
		case PORTC:
			switch(Copy_u8PortValue)
			{
				case LOW:
					DIO_PORTC = ALL_LOW;
					break;
				case HIGH:
					DIO_PORTC = ALL_HIGH;
					break;
				/*		Error		*/
			}
		break;
		case PORTD:
			switch(Copy_u8PortValue)
			{
				case LOW:
					DIO_PORTD = ALL_LOW;
					break;
				case HIGH:
					DIO_PORTD = ALL_HIGH;
					break;
				/*		Error		*/
			}
		break;
		/*		Error		*/
	}
}
/*_________________________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
	_____________________________
	Function Parameters Options :
	_____________________________
*/
/* ------------------------------------------------------------------------------------- */
void MDIO_voidSetPortSpecificDirection(u8 Copy_u8PortName, u8 Copy_u8PortPinsDirection)
{
	switch(Copy_u8PortName)
	{
		case PORTA:
			DIO_DDRA = Copy_u8PortPinsDirection;
			break;
		case PORTB:
			DIO_DDRB = Copy_u8PortPinsDirection;
			break;
		case PORTC:
			DIO_DDRC = Copy_u8PortPinsDirection;
			break;
		case PORTD:
			DIO_DDRD = Copy_u8PortPinsDirection;
			break;
		/*		Error		*/
	}
}
/*_________________________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
	_____________________________
	Function Parameters Options :
	_____________________________
*/
/* ------------------------------------------------------------------------------------- */
void MDIO_voidSetPortSpecificValue(u8 Copy_u8PortName, u8 Copy_u8PortPinsValue)
{
	switch(Copy_u8PortName)
	{
		case PORTA:
			DIO_PORTA = Copy_u8PortPinsValue;
			break;
		case PORTB:
			DIO_PORTB = Copy_u8PortPinsValue;
			break;
		case PORTC:
			DIO_PORTC = Copy_u8PortPinsValue;
			break;
		case PORTD:
			DIO_PORTD = Copy_u8PortPinsValue;
			break;
		/*		Error		*/
	}
}
/*_________________________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
	_____________________________
	Function Parameters Options :
	_____________________________
*/
/* ------------------------------------------------------------------------------------- */
u8 MDIO_u8GetPinValue(u8 Copy_u8PortName , u8 Copy_u8PinName)
{
	u8 Local_u8PinValue;
	if(Copy_u8PinName <= PIN7)
	switch(Copy_u8PortName)
	{
		case PORTA:
			Local_u8PinValue = GET_BIT(DIO_PINA,Copy_u8PinName);
			break;
		case PORTB:
			Local_u8PinValue = GET_BIT(DIO_PINB,Copy_u8PinName);
			break;
		case PORTC:
			Local_u8PinValue = GET_BIT(DIO_PINC,Copy_u8PinName);
			break;
		case PORTD:
			Local_u8PinValue = GET_BIT(DIO_PIND,Copy_u8PinName);
			break;
		/*		Error	*/
	}
	else
	{
		/*		Error		*/
	}
	return Local_u8PinValue;
}
/*_________________________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
	_____________________________
	Function Parameters Options :
	_____________________________
*/
/* ------------------------------------------------------------------------------------- */
u8 MDIO_u8GetPortValue(u8 Copy_u8PortName)
{
	u8 Local_u8PortValue;
	switch(Copy_u8PortName)
	{
		case PORTA:
			Local_u8PortValue = DIO_PINA;
			break;
		case PORTB:
			Local_u8PortValue = DIO_PINB;
			break;
		case PORTC:
			Local_u8PortValue = DIO_PINC;
			break;
		case PORTD:
			Local_u8PortValue = DIO_PIND;
			break;
		/*		Error		*/
	}
	return Local_u8PortValue;
}
/*_________________________________________________________________________________________________*/
