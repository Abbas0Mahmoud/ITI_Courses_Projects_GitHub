/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	NVIC Driver                             							  	      */
/*  Project Description    :	NVIC Driver for STM32F10x Family                             				  */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	NVIC_program.c                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Preprocessor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/*		                        Library Inclusions								         */
#include "../../../Inc/LIB/Std_Types.h"
#include "../../../Inc/LIB/BIT_MATH.h"
/*_______________________________________________________________________________________*/

/*		                        HAL Layer Inclusion							             */

/*_______________________________________________________________________________________*/

/*		                        MCAL Layer Inclusion					                */

/*_______________________________________________________________________________________*/

/*		                        Self Files Inclusions							         */
#include "../../../Inc/MCAL/NVIC/NVIC_interface.h"
#include "../../../Inc/MCAL/NVIC/NVIC_private.h"
#include "../../../Inc/MCAL/NVIC/NVIC_config.h"
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Function Implementations       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
void MNVIC_voidSetInterruptEnable(u8 Copy_u8InterruptID)
{
    /*      Input Validation        */
    if(Copy_u8InterruptID < 60)
    {
        /*      Setting Corresponding Enable Bit of Interrupt ID in ISER Register       */
        NVIC->ISER[Copy_u8InterruptID/32] = (1 << (Copy_u8InterruptID%32));
    }
    else
    {
        /* Error */
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

	Function Parameters Options :
	_____________________________
*/
void MNVIC_voidClearInterruptEnable(u8 Copy_u8InterruptID)
{
    if(Copy_u8InterruptID < 60)
    {
        /*      Setting Corresponding Disable Bit of Interrupt ID in ICER Register       */
        NVIC->ICER[Copy_u8InterruptID/32] = (1 << (Copy_u8InterruptID%32));
    }
    else
    {
        /* Error */
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

	Function Parameters Options :
	_____________________________
*/
void MNVIC_voidSetInterruptPendingFlag(u8 Copy_u8InterruptID)
{
    if(Copy_u8InterruptID < 60)
    {
        /*      Setting Corresponding Enable Bit of Interrupt ID in ISPR Register       */
        NVIC->ISPR[Copy_u8InterruptID/32] = (1 << (Copy_u8InterruptID%32));
    }
    else
    {
        /* Error */
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

	Function Parameters Options :
	_____________________________
*/
void MNVIC_voidClearInterruptPendingFlag(u8 Copy_u8InterruptID)
{
    if(Copy_u8InterruptID < 60)
    {
        /*      Setting Corresponding Disable Bit of Interrupt ID in ICPR Register       */
        NVIC->ICPR[Copy_u8InterruptID/32] = (1 << (Copy_u8InterruptID%32));
    }
    else
    {
        /* Error */
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

	Function Parameters Options :
	_____________________________
*/
void MNVIC_voidClearAllinterruptPendingFlags(void)
{
    u8 Local_u8LoopCounter;
    for(Local_u8LoopCounter = 0;Local_u8LoopCounter < 60;Local_u8LoopCounter++)
    {
        MNVIC_voidClearInterruptPendingFlag(Local_u8LoopCounter);
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

	Function Parameters Options :
	_____________________________
*/
u8 MNVIC_u8GetInterruptPendingFlag(u8 Copy_u8InterruptID)
{
    if(Copy_u8InterruptID < 60)
    {
        /*      Getting Corresponding Enable Bit of Interrupt ID in ISPR Register       */
        return GET_BIT(NVIC->ISPR[Copy_u8InterruptID/32],(Copy_u8InterruptID % 32));
    }
    else
    {
        /* Error */
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

	Function Parameters Options :
	_____________________________
*/
u8 MNVIC_u8GetInterruptActiveBit(u8 Copy_u8InterruptID)
{
    if(Copy_u8InterruptID < 60)
    {
        /*      Getting Corresponding Enable Bit of Interrupt ID in IABR Register       */
        return GET_BIT(NVIC->IABR[Copy_u8InterruptID/32],(1 << (Copy_u8InterruptID%32)));
    }
    else
    {
        /* Error */
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

	Function Parameters Options :
	_____________________________
*/
void MNVIC_voidSetInterruptPriority(u8 Copy_u8InterruptID,u8 Copy_u8InterruptPriority)
{
    if(Copy_u8InterruptID < 60 && Copy_u8InterruptPriority < 16)
    {
        /*      Setting Corresponding Priority Field of Interrupt ID in IPR Register       */
        NVIC->IPR[Copy_u8InterruptID] = (Copy_u8InterruptPriority << 4);
    }
    else
    {
        /* Error */
    }
}
/*_________________________________________________________________________________________________*/
