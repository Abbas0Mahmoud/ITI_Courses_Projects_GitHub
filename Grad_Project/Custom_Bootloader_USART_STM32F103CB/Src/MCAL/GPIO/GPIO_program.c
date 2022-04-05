/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                      		Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	GPIO Driver                             							  	      */
/*  Project Description    :	GPIO Driver for STM32F10x Family                             				  */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	GPIO_program.c                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */


/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Preprocessor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/*		                		Library Inclusions								 	     */
#include "../../../Inc/LIB/Std_Types.h"
#include "../../../Inc/LIB/BIT_MATH.h"
/*_______________________________________________________________________________________*/

/*		                		HAL Layer Inclusion							     		 */

/*_______________________________________________________________________________________*/

/*		                		MCAL Layer Inclusion					         		 */

/*_______________________________________________________________________________________*/

/*		                		Self Files Inclusions							 		 */
#include "../../../Inc/MCAL/GPIO/GPIO_interface.h"
#include "../../../Inc/MCAL/GPIO/GPIO_private.h"
#include "../../../Inc/MCAL/GPIO/GPIO_config.h"
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Function Implementations       		     		          	  		  */
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
void MGPIO_voidSetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode, u8 Copy_u8PinCNF)
{
	/*		Checking PortName Options		*/
	switch (Copy_u8PortName)
	{
		case GPIO_PORTA:
			/* checking if pin number is in lower pins or higher pins */
			if (Copy_u8PinNumber <= GPIO_PIN7)
			{
				/* masking corresponding mode and config bits to pin number in configuration control register */
				/* mask value is 15(1111) shift left by pin number multiplied by 4 to align mask value to pin bits*/
				/* negate the result to put 0000 in pin mode and config bits */
				GPIOA->CRL &= ~(GPIO_DIRECTION_RESET_MASK << (Copy_u8PinNumber * 4));
				/* setting pin mode bits by shiftting pinmode value by pin number multiplied by 4 */
				/* setting pin config bits by shiftting pincfn value by pin number multiplied by 4 then add 2 to just set config bits */
				/* setting configuration register low with the result pin mode and config bits value */
				GPIOA->CRL |= ((Copy_u8PinMode << (Copy_u8PinNumber * 4)) |
								((Copy_u8PinCNF << ((Copy_u8PinNumber * 4) + 2))));
			}
			else
			{
				/* subtract 8 from pinnumber to apply the same steps as CRL */
				Copy_u8PinNumber -= 8;
				GPIOA->CRH &= ~(GPIO_DIRECTION_RESET_MASK << (Copy_u8PinNumber * 4));
				GPIOA->CRH |= ((Copy_u8PinMode << (Copy_u8PinNumber * 4)) |
								((Copy_u8PinCNF << ((Copy_u8PinNumber * 4) + 2))));
			}
			break;
		case GPIO_PORTB:
			if (Copy_u8PinNumber <= GPIO_PIN7)
			{
				GPIOB->CRL &= ~(GPIO_DIRECTION_RESET_MASK << (Copy_u8PinNumber * 4));
				GPIOB->CRL |= ((Copy_u8PinMode << (Copy_u8PinNumber * 4)) |
								((Copy_u8PinCNF << ((Copy_u8PinNumber * 4) + 2))));
			}
			else
			{
				Copy_u8PinNumber -= 8;
				GPIOB->CRH &= ~(GPIO_DIRECTION_RESET_MASK << (Copy_u8PinNumber * 4));
				GPIOB->CRH |= ((Copy_u8PinMode << (Copy_u8PinNumber * 4)) |
								((Copy_u8PinCNF << ((Copy_u8PinNumber * 4) + 2))));
			}
			break;
		case GPIO_PORTC:
			/* input validation on pinnumber as port c pins 13,14,15 are only the configurable pins */
			if (Copy_u8PinNumber >= GPIO_PIN13)
			{
				Copy_u8PinNumber -= 8;
				GPIOC->CRH &= ~(GPIO_DIRECTION_RESET_MASK << (Copy_u8PinNumber * 4));
				GPIOC->CRH |= ((Copy_u8PinMode << (Copy_u8PinNumber * 4)) |
								((Copy_u8PinCNF << ((Copy_u8PinNumber * 4) + 2))));
			}
			else
			{
				/*
					Do No Thing
				*/
			}
			break;
		}
}
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
void MGPIO_voidSetPinDirectionInRange(u8 Copy_u8PortName, u8 Copy_u8StartPin, u8 Copy_u8EndPin, u8 Copy_u8PinMode, u8 Copy_u8PinCNF)
{
	/*		Function Variables Definitions		*/
	u8 Local_u8LoopCounter;
	u8 Local_u8PinNumber;
	/*		Checking PortName Options		*/
	switch (Copy_u8PortName)
	{
		case GPIO_PORTA:
			for(Local_u8LoopCounter = Copy_u8StartPin ; Local_u8LoopCounter <= Copy_u8EndPin ; Local_u8LoopCounter++)
			{
				Local_u8PinNumber = Local_u8LoopCounter;
				/* checking if pin number is in lower pins or higher pins */
				if (Local_u8PinNumber <= GPIO_PIN7)
				{
					/* masking corresponding mode and config bits to pin number in configuration control register */
					/* mask value is 15(1111) shift left by pin number multiplied by 4 to align mask value to pin bits*/
					/* negate the result to put 0000 in pin mode and config bits */
					GPIOA->CRL &= ~(GPIO_DIRECTION_RESET_MASK << (Local_u8PinNumber * 4));
					/* setting pin mode bits by shiftting pinmode value by pin number multiplied by 4 */
					/* setting pin config bits by shiftting pincfn value by pin number multiplied by 4 then add 2 to just set config bits */
					/* setting configuration register low with the result pin mode and config bits value */
					GPIOA->CRL |= ((Copy_u8PinMode << (Local_u8PinNumber * 4)) |
									((Copy_u8PinCNF << ((Local_u8PinNumber * 4) + 2))));
				}
				else
				{
					/* subtract 8 from pinnumber to apply the same steps as CRL */
					Local_u8PinNumber -= 8;
					GPIOA->CRH &= ~(GPIO_DIRECTION_RESET_MASK << (Local_u8PinNumber * 4));
					GPIOA->CRH |= ((Copy_u8PinMode << (Local_u8PinNumber * 4)) |
									((Copy_u8PinCNF << ((Local_u8PinNumber * 4) + 2))));
				}
			}
		break;

		case GPIO_PORTB:
			for(Local_u8LoopCounter = Copy_u8StartPin ; Local_u8LoopCounter <= Copy_u8EndPin ; Local_u8LoopCounter++)
			{
				Local_u8PinNumber = Local_u8LoopCounter;
				if (Local_u8PinNumber <= GPIO_PIN7)
				{
					GPIOB->CRL &= ~(GPIO_DIRECTION_RESET_MASK << (Local_u8PinNumber * 4));
					GPIOB->CRL |= ((Copy_u8PinMode << (Local_u8PinNumber * 4)) |
									((Copy_u8PinCNF << ((Local_u8PinNumber * 4) + 2))));
				}
				else
				{
					Local_u8PinNumber -= 8;
					GPIOB->CRH &= ~(GPIO_DIRECTION_RESET_MASK << (Local_u8PinNumber * 4));
					GPIOB->CRH |= ((Copy_u8PinMode << (Local_u8PinNumber * 4)) |
									((Copy_u8PinCNF << ((Local_u8PinNumber * 4) + 2))));
				}
			}
		break;

		case GPIO_PORTC:
			/* input validation on pinnumber as port c pins 13,14,15 are only the configurable pins */
			if ((Copy_u8StartPin >= GPIO_PIN13) && (Copy_u8EndPin <= GPIO_PIN15))
			{
				for(Local_u8LoopCounter = Copy_u8StartPin ; Local_u8LoopCounter <= Copy_u8EndPin ; Local_u8LoopCounter++)
				{
					Local_u8PinNumber = Local_u8LoopCounter;
					Local_u8PinNumber -= 8;
					GPIOC->CRH &= ~(GPIO_DIRECTION_RESET_MASK << (Local_u8PinNumber * 4));
					GPIOC->CRH |= ((Copy_u8PinMode << (Local_u8PinNumber * 4)) |
									((Copy_u8PinCNF << ((Local_u8PinNumber * 4) + 2))));
				}
			}
			else
			{
				/*
					Do No Thing
				*/
			}
		break;
		}
}
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
void MGPIO_voidSetPinInputPullUpDown(u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_u8PinCFN)
{
	switch (Copy_u8PortName)
	{
		case GPIO_PORTA:
			switch (Copy_u8PinCFN)
			{
				case GPIO_INPUT_MODE_CNF_PULL_DOWN:
					CLR_BIT(GPIOA->ODR, Copy_u8PinNumber);
					break;
				case GPIO_INPUT_MODE_CNF_PULL_UP:
					SET_BIT(GPIOA->ODR, Copy_u8PinNumber);
					break;
			}
		break;

		case GPIO_PORTB:
			switch (Copy_u8PinCFN)
			{
				case GPIO_INPUT_MODE_CNF_PULL_DOWN:
					CLR_BIT(GPIOB->ODR, Copy_u8PinNumber);
					break;
				case GPIO_INPUT_MODE_CNF_PULL_UP:
					SET_BIT(GPIOB->ODR, Copy_u8PinNumber);
					break;
			}
		break;

		case GPIO_PORTC:
			if (Copy_u8PinNumber >= GPIO_PIN13)
			{
				switch (Copy_u8PinCFN)
				{
					case GPIO_INPUT_MODE_CNF_PULL_DOWN:
						CLR_BIT(GPIOC->ODR, Copy_u8PinNumber);
						break;
					case GPIO_INPUT_MODE_CNF_PULL_UP:
						SET_BIT(GPIOC->ODR, Copy_u8PinNumber);
						break;
				}
			}
			else
			{
				/*
					Do No Thing
				*/
			}
		break;
	}
}
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
void MGPIO_voidSetPinInputPullUpDownInRange(u8 Copy_u8PortName,u8 Copy_u8StartPin,u8 Copy_u8EndPin,u8 Copy_u8PinCFN)
{
	/*		Function Variables Definitions		*/
	u8 Local_u8LoopCounter;
	u8 Local_u8PinNumber;
	switch (Copy_u8PortName)
	{
		case GPIO_PORTA:
			for(Local_u8LoopCounter = Copy_u8StartPin ; Local_u8LoopCounter <= Copy_u8EndPin ; Local_u8LoopCounter++)
				{
					Local_u8PinNumber = Local_u8LoopCounter;
					switch (Copy_u8PinCFN)
					{
						case GPIO_INPUT_MODE_CNF_PULL_DOWN:
							CLR_BIT(GPIOA->ODR, Local_u8PinNumber);
							break;
						case GPIO_INPUT_MODE_CNF_PULL_UP:
							SET_BIT(GPIOA->ODR, Local_u8PinNumber);
							break;
					}
				}
		break;

		case GPIO_PORTB:
			for(Local_u8LoopCounter = Copy_u8StartPin ; Local_u8LoopCounter <= Copy_u8EndPin ; Local_u8LoopCounter++)
			{
				Local_u8PinNumber = Local_u8LoopCounter;
				switch (Copy_u8PinCFN)
				{
					case GPIO_INPUT_MODE_CNF_PULL_DOWN:
						CLR_BIT(GPIOB->ODR, Local_u8PinNumber);
						break;
					case GPIO_INPUT_MODE_CNF_PULL_UP:
						SET_BIT(GPIOB->ODR, Local_u8PinNumber);
						break;
				}
			}
		break;

		case GPIO_PORTC:
			for(Local_u8LoopCounter = Copy_u8StartPin ; Local_u8LoopCounter <= Copy_u8EndPin ; Local_u8LoopCounter++)
			{
				Local_u8PinNumber = Local_u8LoopCounter;
				if ((Copy_u8StartPin >= GPIO_PIN13) && (Copy_u8EndPin <= GPIO_PIN15))
				{
					switch (Copy_u8PinCFN)
					{
						case GPIO_INPUT_MODE_CNF_PULL_DOWN:
							CLR_BIT(GPIOC->ODR, Local_u8PinNumber);
							break;
						case GPIO_INPUT_MODE_CNF_PULL_UP:
							SET_BIT(GPIOC->ODR, Local_u8PinNumber);
							break;
					}
				}
				else
				{
					/*
						Do No Thing
					*/
				}
			}
		break;
	}
}
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
void MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
	switch (Copy_u8PortName)
	{
		case GPIO_PORTA:
			switch (Copy_u8PinValue)
			{
				case GPIO_LOW:
					CLR_BIT(GPIOA->ODR, Copy_u8PinNumber);
				break;
				case GPIO_HIGH:
					SET_BIT(GPIOA->ODR, Copy_u8PinNumber);
				break;
			}
		break;

		case GPIO_PORTB:
			switch (Copy_u8PinValue)
			{
				case GPIO_LOW:
					CLR_BIT(GPIOB->ODR, Copy_u8PinNumber);
				break;
				case GPIO_HIGH:
					SET_BIT(GPIOB->ODR, Copy_u8PinNumber);
				break;
			}
		break;

		case GPIO_PORTC:
			if (Copy_u8PinNumber >= GPIO_PIN13)
			{
				switch (Copy_u8PinValue)
				{
					case GPIO_LOW:
						CLR_BIT(GPIOC->ODR, Copy_u8PinNumber);
					break;
					case GPIO_HIGH:
						SET_BIT(GPIOC->ODR, Copy_u8PinNumber);
					break;
				}
			}
			else
			{
				/*
					Do No Thing
				*/
			}
		break;
	}
}
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
void MGPIO_voidSetPinValueInRange(u8 Copy_u8PortName,u8 Copy_u8StartPin,u8 Copy_u8EndPin,u8 Copy_u8PinValue)
{
	/*		Function Variables Definitions		*/
	u8 Local_u8LoopCounter;
	u8 Local_u8PinNumber;
	switch (Copy_u8PortName)
	{
		case GPIO_PORTA:
			for(Local_u8LoopCounter = Copy_u8StartPin ; Local_u8LoopCounter <= Copy_u8EndPin ; Local_u8LoopCounter++)
			{
				Local_u8PinNumber = Local_u8LoopCounter;
				switch (Copy_u8PinValue)
				{
					case GPIO_LOW:
						CLR_BIT(GPIOA->ODR, Local_u8PinNumber);
					break;
					case GPIO_HIGH:
						SET_BIT(GPIOA->ODR, Local_u8PinNumber);
					break;
				}
			}
		break;

		case GPIO_PORTB:
			for(Local_u8LoopCounter = Copy_u8StartPin ; Local_u8LoopCounter <= Copy_u8EndPin ; Local_u8LoopCounter++)
				{
					Local_u8PinNumber = Local_u8LoopCounter;
					switch (Copy_u8PinValue)
					{
						case GPIO_LOW:
							CLR_BIT(GPIOB->ODR, Local_u8PinNumber);
						break;
						case GPIO_HIGH:
							SET_BIT(GPIOB->ODR, Local_u8PinNumber);
						break;
					}
				}
		break;

		case GPIO_PORTC:
			for(Local_u8LoopCounter = Copy_u8StartPin ; Local_u8LoopCounter <= Copy_u8EndPin ; Local_u8LoopCounter++)
				{
					Local_u8PinNumber = Local_u8LoopCounter;
					if (Local_u8PinNumber >= GPIO_PIN13)
					{
						switch (Copy_u8PinValue)
						{
							case GPIO_LOW:
								CLR_BIT(GPIOC->ODR, Local_u8PinNumber);
							break;
							case GPIO_HIGH:
								SET_BIT(GPIOC->ODR, Local_u8PinNumber);
							break;
						}
					}
					else
					{
						/*
							Do No Thing
						*/
					}
				}
		break;
	}
}
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
void MGPIO_voidSetPinValueAtomic(u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_u8PinValue)
{
	switch (Copy_u8PortName)
	{
		case GPIO_PORTA:
			switch (Copy_u8PinValue)
			{
			case GPIO_LOW:
				GPIOA->BRR  = (1<<Copy_u8PinNumber);
				break;
			case GPIO_HIGH:
				GPIOA->BSRR = (1<<Copy_u8PinNumber);
				break;
			}
			break;
		case GPIO_PORTB:
			switch (Copy_u8PinValue)
			{
			case GPIO_LOW:
				GPIOB->BRR = (1<<Copy_u8PinNumber);
				break;
			case GPIO_HIGH:
				GPIOB->BSRR =  (1<<Copy_u8PinNumber);
				break;
			}
			break;
		case GPIO_PORTC:
			if (Copy_u8PinNumber >= GPIO_PIN13)
			{
				switch (Copy_u8PinValue)
				{
				case GPIO_LOW:
					GPIOC->BRR = (1<<Copy_u8PinNumber);
					break;
				case GPIO_HIGH:
					GPIOC->BSRR =  (1<<Copy_u8PinNumber);
					break;
				}
			}
			else
			{
				/*
					Do No Thing
				*/
			}
			break;
	}
}
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
void MGPIO_voidSetAtomicValueAtomicInRange(u8 Copy_u8PortName,u8 Copy_u8StartPin,u8 Copy_u8EndPin,u8 Copy_u8PinValue)
{
	/*		Function Variables Definitions		*/
	u8 Local_u8LoopCounter;
	u8 Local_u8PinNumber;
	switch (Copy_u8PortName)
	{
		case GPIO_PORTA:
			for(Local_u8LoopCounter = Copy_u8StartPin ; Local_u8LoopCounter <= Copy_u8EndPin ; Local_u8LoopCounter++)
			{
				Local_u8PinNumber = Local_u8LoopCounter;
				switch (Copy_u8PinValue)
				{
				case GPIO_LOW:
					GPIOA->BRR  = (1<<Local_u8PinNumber);
					break;
				case GPIO_HIGH:
					GPIOA->BSRR = (1<<Local_u8PinNumber);
					break;
				}
			}
		break;
		case GPIO_PORTB:
			for(Local_u8LoopCounter = Copy_u8StartPin ; Local_u8LoopCounter <= Copy_u8EndPin ; Local_u8LoopCounter++)
				{
					Local_u8PinNumber = Local_u8LoopCounter;
					switch (Copy_u8PinValue)
					{
					case GPIO_LOW:
						GPIOB->BRR = (1<<Local_u8PinNumber);
						break;
					case GPIO_HIGH:
						GPIOB->BSRR =  (1<<Local_u8PinNumber);
						break;
					}
				}
		break;
		case GPIO_PORTC:
			for(Local_u8LoopCounter = Copy_u8StartPin ; Local_u8LoopCounter <= Copy_u8EndPin ; Local_u8LoopCounter++)
				{
					Local_u8PinNumber = Local_u8LoopCounter;
					if (Local_u8PinNumber >= GPIO_PIN13)
					{
						switch (Copy_u8PinValue)
						{
						case GPIO_LOW:
							GPIOC->BRR = (1<<Local_u8PinNumber);
							break;
						case GPIO_HIGH:
							GPIOC->BSRR =  (1<<Local_u8PinNumber);
							break;
						}
					}
					else
					{
						/*
							Do No Thing
						*/
					}
				}
			break;
	}
}
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
void MGPIO_voidTogglePinValue(u8 Copy_u8PortName,u8 Copy_u8PinNumber)
{
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			TOGGLE_BIT(GPIOA->ODR,Copy_u8PinNumber);
		break;
		case GPIO_PORTB:
			TOGGLE_BIT(GPIOB->ODR,Copy_u8PinNumber);
		break;
		case GPIO_PORTC:
			if (Copy_u8PinNumber >= GPIO_PIN13)
			{
				TOGGLE_BIT(GPIOC->ODR,Copy_u8PinNumber);
			}
			else
			{
				/* Error */
			}
		break;
	}
}
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
*/
/* ---------------------------------------------------------------------------------------------------------- */
u8 MGPIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
	u8 Local_u8PinValue;
	switch (Copy_u8PortName)
	{
		case GPIO_PORTA:
			Local_u8PinValue = GET_BIT(GPIOA->IDR, Copy_u8PinNumber);
		break;
		case GPIO_PORTB:
			Local_u8PinValue = GET_BIT(GPIOB->IDR, Copy_u8PinNumber);
		break;
		case GPIO_PORTC:
			if (Copy_u8PinNumber >= GPIO_PIN13)
			{
				Local_u8PinValue = GET_BIT(GPIOC->IDR, Copy_u8PinNumber);
			}
			else
			{
				/*
					Do No Thing
				*/
			}
		break;
	}
	return Local_u8PinValue;
}
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
*/
/* ---------------------------------------------------------------------------------------------------------- */
u8 MGPIO_u8LockPinConfiguration(u8 Copy_u8PortName,u8 Copy_u8PinNumber)
{
	volatile u8 Local_u8PinLockStatus;
	volatile u32 Local_LCKRRegister = 0;
	switch (Copy_u8PortName)
	{
		case GPIO_PORTA:

			Local_LCKRRegister = ((1<<16) | (1<<Copy_u8PinNumber));
			GPIOA->LCKR = Local_LCKRRegister;
			Local_LCKRRegister = ((Local_LCKRRegister & (0<<16)) | (1<<Copy_u8PinNumber));
			GPIOA->LCKR = Local_LCKRRegister;
			Local_LCKRRegister = ((1<<16) | (1<<Copy_u8PinNumber));
			GPIOA->LCKR = Local_LCKRRegister;
			Local_LCKRRegister = GPIOA->LCKR;
			Local_u8PinLockStatus = GET_BIT(Local_LCKRRegister,16);
			Local_u8PinLockStatus = GET_BIT(Local_LCKRRegister,16);
			/*
			CLR_BIT(GPIOA->LCKR,16);
			SET_BIT(GPIOA->LCKR,Copy_u8PinNumber);
			SET_BIT(GPIOA->LCKR,16);
			CLR_BIT(GPIOA->LCKR,16);
			SET_BIT(GPIOA->LCKR,16);
			Local_u8PinLockStatus = GET_BIT(GPIOA->LCKR,16);
			Local_u8PinLockStatus = GET_BIT(GPIOA->LCKR,16);
			*/
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB->LCKR,16);
			SET_BIT(GPIOB->LCKR,Copy_u8PinNumber);
			SET_BIT(GPIOB->LCKR,16);
			CLR_BIT(GPIOB->LCKR,16);
			SET_BIT(GPIOB->LCKR,16);
			Local_u8PinLockStatus = GET_BIT(GPIOB->LCKR,16);
			Local_u8PinLockStatus = GET_BIT(GPIOB->LCKR,16);
			break;
		case GPIO_PORTC:
			if (Copy_u8PinNumber >= GPIO_PIN13)
			{
				CLR_BIT(GPIOC->LCKR,16);
				SET_BIT(GPIOC->LCKR,Copy_u8PinNumber);
				SET_BIT(GPIOC->LCKR,16);
				CLR_BIT(GPIOC->LCKR,16);
				SET_BIT(GPIOC->LCKR,16);
				Local_u8PinLockStatus = GET_BIT(GPIOC->LCKR,16);
				Local_u8PinLockStatus = GET_BIT(GPIOC->LCKR,16);
			}
			else
			{
				/*
					Do No Thing
				*/
			}
			break;
	}
	return Local_u8PinLockStatus;
}
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
void MGPIO_voidSetPortDirection(u8 Copy_u8PortName,u8 Copy_u8PortMode,u8 Copy_u8PortCFN)
{
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			for(u8 Local_u8LoopCounter = 0;Local_u8LoopCounter <= GPIO_PIN15;Local_u8LoopCounter++)
			{
				/* checking if pin number is in lower pins or higher pins */
				if (Local_u8LoopCounter <= GPIO_PIN7)
				{
					GPIOA->CRL &= ~(GPIO_DIRECTION_RESET_MASK << (Local_u8LoopCounter * 4));
					GPIOA->CRL |= ((Copy_u8PortMode << (Local_u8LoopCounter * 4)) |
									((Copy_u8PortCFN << ((Local_u8LoopCounter * 4) + 2))));
				}
				else
				{
					/* subtract 8 from pinnumber to apply the same steps as CRL */
					Local_u8LoopCounter -= 8;
					GPIOA->CRH &= ~(GPIO_DIRECTION_RESET_MASK << (Local_u8LoopCounter * 4));
					GPIOA->CRH |= ((Copy_u8PortMode << (Local_u8LoopCounter * 4)) |
									((Copy_u8PortCFN << ((Local_u8LoopCounter * 4) + 2))));
				}
			}
		break;
		case GPIO_PORTB:
			for(u8 Local_u8LoopCounter = 0;Local_u8LoopCounter <= GPIO_PIN15;Local_u8LoopCounter++)
			{
				if (Local_u8LoopCounter <= GPIO_PIN7)
				{
					GPIOB->CRL &= ~(GPIO_DIRECTION_RESET_MASK << (Local_u8LoopCounter * 4));
					GPIOB->CRL |= ((Copy_u8PortMode << (Local_u8LoopCounter * 4)) |
									((Copy_u8PortCFN << ((Local_u8LoopCounter * 4) + 2))));
				}
				else
				{
					Local_u8LoopCounter -= 8;
					GPIOB->CRH &= ~(GPIO_DIRECTION_RESET_MASK << (Local_u8LoopCounter * 4));
					GPIOB->CRH |= ((Copy_u8PortMode << (Local_u8LoopCounter * 4)) |
									((Copy_u8PortCFN << ((Local_u8LoopCounter * 4) + 2))));
				}
			}
		break;
		case GPIO_PORTC:
			for(u8 Local_u8LoopCounter = GPIO_PIN13;Local_u8LoopCounter <= GPIO_PIN15;Local_u8LoopCounter++)
			{
				Local_u8LoopCounter -= 8;
				GPIOC->CRH &= ~(GPIO_DIRECTION_RESET_MASK << (Local_u8LoopCounter * 4));
				GPIOC->CRH |= ((Copy_u8PortMode << (Local_u8LoopCounter * 4)) |
								((Copy_u8PortCFN << ((Local_u8LoopCounter * 4) + 2))));
			}
		break;
	}
}
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
void MGPIO_voidSetPortLowPinsSpecificDirection(u8 Copy_u8PortName,u32 Copy_u8PinsSpecificMode,u32 Copy_u8PinsSpecificCFN)
{
	if(Copy_u8PortName <= GPIO_PORTC)
	{
		switch(Copy_u8PortName)
		{
			case GPIO_PORTA:
				GPIOA->CRL = Copy_u8PinsSpecificMode | Copy_u8PinsSpecificCFN;
			break;
			case GPIO_PORTB:
				GPIOB->CRL = Copy_u8PinsSpecificMode | Copy_u8PinsSpecificCFN;
			break;
		}
	}
	else
	{
		/* Error */
	}
}
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
void MGPIO_voidSetPortHighPinsSpecificDirection(u8 Copy_u8PortName,u32 Copy_u8PinsSpecificMode,u32 Copy_u8PinsSpecificCFN)
{
	if(Copy_u8PortName <= GPIO_PORTC)
	{
		switch(Copy_u8PortName)
		{
			case GPIO_PORTA:
				GPIOA->CRH = Copy_u8PinsSpecificMode | Copy_u8PinsSpecificCFN;
			break;
			case GPIO_PORTB:
				GPIOB->CRH = Copy_u8PinsSpecificMode | Copy_u8PinsSpecificCFN;
			break;
		}
	}
	else
	{
		/* Error */
	}
}
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
void MGPIO_voidSetPortInputPullUpDown(u8 Copy_u8PortName,u8 Copy_u8PortCFN)
{
	if(Copy_u8PortName < GPIO_PORTC)
	{
		switch(Copy_u8PortName)
		{
			case GPIO_PORTA:
				GPIOA->ODR = Copy_u8PortCFN;
			break;
			case GPIO_PORTB:
				GPIOB->ODR = Copy_u8PortCFN;
			break;
		}
	}
	else
	{
		/* Error */
	}
}
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
void MGPIO_voidSetPortValue(u8 Copy_u8PortName,u8 Copy_u8PortValue)
{
	if(Copy_u8PortName < GPIO_PORTC)
	{
		switch(Copy_u8PortName)
		{
			case GPIO_PORTA:
				GPIOA->ODR = Copy_u8PortValue;
			break;
			case GPIO_PORTB:
				GPIOB->ODR = Copy_u8PortValue;
			break;
		}
	}
	else
	{
		/* Error */
	}
}
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
void MGPIO_voidSetPortValueAtomic(u8 Copy_u8PortName,u8 Copy_u8PortValue)
{
	if(Copy_u8PortName < GPIO_PORTC)
	{
		switch(Copy_u8PortName)
		{
			case GPIO_PORTA:
				switch(Copy_u8PortValue)
				{
					case GPIO_HIGH:
						GPIOA->BSRR = ALL_GPIO_HIGH;
					break;
					case GPIO_LOW:
						GPIOA->BRR = ALL_GPIO_HIGH;
					break;
				}
			break;
			case GPIO_PORTB:
				switch(Copy_u8PortValue)
				{
					case GPIO_HIGH:
						GPIOB->BSRR = ALL_GPIO_HIGH;
					break;
					case GPIO_LOW:
						GPIOB->BRR = ALL_GPIO_HIGH;
					break;
				}
			break;
		}
	}
	else
	{
		/* Error */
	}
}
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
void MGPIO_voidSetPortSpecificValue(u8 Copy_u8PortName,u32 Copy_u32PortValue)
{
	if(Copy_u8PortName <= GPIO_PORTC)
	{
		switch(Copy_u8PortName)
		{
			case GPIO_PORTA:
			GPIOA->ODR = Copy_u32PortValue;
			break;
			case GPIO_PORTB:
			GPIOB->ODR = Copy_u32PortValue;
			break;
			case GPIO_PORTC:
			GPIOC->ODR &= 0xFFFF1FFF;
			GPIOC->ODR |= Copy_u32PortValue << 13;
			break;
		}
	}
	else
	{
		/* Error */
	}
}
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
u32 MGPIO_u32GetPortValue(u8 Copy_u8PortName)
{
	u32 Local_u32PortValue = 0;
	if(Copy_u8PortName < GPIO_PORTC)
	{
		switch(Copy_u8PortName)
		{
			case GPIO_PORTA:
				Local_u32PortValue = GPIOA->IDR;
			break;
			case GPIO_PORTB:
				Local_u32PortValue = GPIOB->IDR;
			break;
		}
	}
	else
	{
		/* Error */
	}
	return Local_u32PortValue;
}
/*____________________________________________________________________________________________________________*/


