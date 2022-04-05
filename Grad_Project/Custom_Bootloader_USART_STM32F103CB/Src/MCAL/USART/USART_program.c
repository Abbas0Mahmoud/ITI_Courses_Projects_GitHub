/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	STK Driver                             							  	          */
/*  Project Description    :	STK Driver for STM32F10x Family                             			      */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	STK_program.c                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/*		                        Library Inclusions								         */
#include "../../../Inc/LIB/STD_TYPES.h"
#include "../../../Inc/LIB/BIT_MATH.h"
/*_______________________________________________________________________________________*/

/*		                        HAL Layer Inclusion							             */

/*_______________________________________________________________________________________*/

/*		                        MCAL Layer Inclusion					                 */

/*_______________________________________________________________________________________*/

/*		                        Self Files Inclusions							         */
#include "../../../Inc/MCAL/USART/USART_config.h"
#include "../../../Inc/MCAL/USART/USART_interface.h"
#include "../../../Inc/MCAL/USART/USART_private.h"
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Function Implementations       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
/* ----------------------------------------------------------------------------------------------- */
void MUSART1_voidInit(void)
{
	/*BaudRate*/
	# if UART_BAUDRATE ==9600
		MUSART1 -> BRR = 0x341;
	#elif UART_BAUDRATE ==115200
		MUSART1 -> BRR = 0x45;
	#endif
	/* Enabling Receiver */
	SET_BIT((MUSART1-> CR[0]), CR1_RE);
	/* Enabling Transmitter */
	SET_BIT((MUSART1-> CR[0]), CR1_TE);
	/*UART Enable*/
	SET_BIT(MUSART1->CR[0],CR1_UE);
	/* Clearing status register */
	MUSART1 -> SR = 0;
}
/*_________________________________________________________________________________________________*/

/* ----------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
/* ----------------------------------------------------------------------------------------------- */
void MUSART1_voidTransmit(u8 * Copy_pu8)
{
	u8 i = 0;
	while(*(Copy_pu8 + i) != '\0')
	{
		MUSART1 -> DR = *(Copy_pu8 + i);
		while((GET_BIT((MUSART1 -> SR), 6)) == 0);
		i++;
	}
}
/*_________________________________________________________________________________________________*/

/* ----------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
/* ----------------------------------------------------------------------------------------------- */
void MUSART1_voidTransmit2(u8 * Copy_pu8)
{
	while((GET_BIT((MUSART1 -> SR), 7)) == 0);
	MUSART1 -> DR = *Copy_pu8;
	while((GET_BIT((MUSART1 -> SR), 6)) == 0);
}
/*_________________________________________________________________________________________________*/

/* ----------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
/* ----------------------------------------------------------------------------------------------- */
u8 MUSART1_u8Receive(u8 * Copy_pu8)
{
	u8 Local_u8Flag=0;
	if (GET_BIT((MUSART1 -> SR),SR_RXNE)==1)
	{
		*Copy_pu8 = MUSART1 -> DR;
		Local_u8Flag=1;
	}
	return Local_u8Flag;
}
/*_________________________________________________________________________________________________*/
