/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  					          */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	EXTI Driver                             							  	      */
/*  Project Description    :	EXTI Driver for STM32F10x Family                             				  */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	EXTI_program.c                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
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

/*		                        Self Files Inclusions							         */
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
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
void MEXTI_voidInit(void)
{
    EXTI->IMR =((EXTI_LIN0_EN  << EXTI0)  |
                (EXTI_LIN1_EN  << EXTI1)  |
                (EXTI_LIN2_EN  << EXTI2)  |
                (EXTI_LIN3_EN  << EXTI3)  |
                (EXTI_LIN4_EN  << EXTI4)  |
                (EXTI_LIN5_EN  << EXTI5)  |
                (EXTI_LIN6_EN  << EXTI6)  |
                (EXTI_LIN7_EN  << EXTI7)  |
                (EXTI_LIN8_EN  << EXTI8)  |
                (EXTI_LIN9_EN  << EXTI9)  |
                (EXTI_LIN10_EN << EXTI10) |
                (EXTI_LIN11_EN << EXTI11) |
                (EXTI_LIN12_EN << EXTI12) |
                (EXTI_LIN13_EN << EXTI13) |
                (EXTI_LIN14_EN << EXTI14) |
                (EXTI_LIN15_EN << EXTI15));
    EXTI->PR = PENDING_FLAGS_RESET_VALUE;
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
void MEXTI_voidEnableLine(EXTI_Line Copy_LineNumber)
{
    if(Copy_LineNumber < NUM_EXTI_LINES)
    {
        SET_BIT(EXTI->IMR,Copy_LineNumber);
    }
    else
    {
        /* Error */
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
void MEXTI_voidDisableLine(EXTI_Line Copy_LineNumber)
{
    if(Copy_LineNumber < NUM_EXTI_LINES)
    {
        CLR_BIT(EXTI->IMR,Copy_LineNumber);
    }
    else
    {
        /* Error */
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
void MEXTI_voidSetLineTrigger(EXTI_Line Copy_LineNumber,EXTI_Trigger Copy_LineTrigger)
{
    if(Copy_LineNumber < NUM_EXTI_LINES)
    {
        if(Copy_LineTrigger < NUM_EXTI_TRIGGER_SIGNSLS)
        {
            switch(Copy_LineTrigger)
            {
                case EXTI_RISING:
                    CLR_BIT(EXTI->FTSR,Copy_LineNumber);
                    SET_BIT(EXTI->RTSR,Copy_LineNumber);
                    break;
                case EXTI_FAILING:
                    CLR_BIT(EXTI->RTSR,Copy_LineNumber);
                    SET_BIT(EXTI->FTSR,Copy_LineNumber);
                    break;
                case EXTI_ON_CHANGE:
                    SET_BIT(EXTI->RTSR,Copy_LineNumber);
                    SET_BIT(EXTI->FTSR,Copy_LineNumber);
                    break;
            }
        }
        else
        {
            /* Error */
        }
    }
    else
    {
        /* Error */
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
void MEXTI_voidSetSWTInterrupt(EXTI_Line Copy_LineNumber)
{
    if(Copy_LineNumber < NUM_EXTI_LINES)
    {
        SET_BIT(EXTI->SWIER,Copy_LineNumber);
    }
    else
    {
        /* Error */
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
void MEXTI_voidClearSWInterrupt(EXTI_Line Copy_LineNumber)
{
    if(Copy_LineNumber < NUM_EXTI_LINES)
    {
        SET_BIT(EXTI->PR,Copy_LineNumber);
    }
    else
    {
        /* Error */
    }
}
/*_________________________________________________________________________________________________*/


void MEXTI_voidSetCallBack(EXTI_Line Copy_LineNumber,void(*Copy_pvFunction)(void))
{
    EXTIn_Handler[Copy_LineNumber] = Copy_pvFunction;
}

void EXTI0_IRQHandler(void)
{
    if(EXTIn_Handler[EXTI0] != NULL)
    {
        EXTIn_Handler[EXTI0]();
    }
    else
    {
        /* Error */
    }
}

void EXTI1_IRQHandler(void)
{
    if(EXTIn_Handler[EXTI1] != NULL)
    {
        EXTIn_Handler[EXTI1]();
    }
    else
    {
        /* Error */
    }
}

void EXTI2_IRQHandler(void)
{
    if(EXTIn_Handler[EXTI2] != NULL)
    {
        EXTIn_Handler[EXTI2]();
    }
    else
    {
        /* Error */
    }
}

void EXTI3_IRQHandler(void)
{
    if(EXTIn_Handler[EXTI3] != NULL)
    {
        EXTIn_Handler[EXTI3]();
    }
    else
    {
        /* Error */
    }
}

void EXTI4_IRQHandler(void)
{
    if(EXTIn_Handler[EXTI4] != NULL)
    {
        EXTIn_Handler[EXTI4]();
    }
    else
    {
        /* Error */
    }
}

void EXTI9_5_IRQHandler(void)
{
    Pending_Flags.PR_Reg_Value = EXTI->PR;
    if(Pending_Flags.PR_Reg_Fields.PR5 == 1)
    {
        EXTIn_Handler[EXTI5]();
    }
    else if (Pending_Flags.PR_Reg_Fields.PR6 == 1)
    {
        EXTIn_Handler[EXTI6]();
    }
    else if (Pending_Flags.PR_Reg_Fields.PR7 == 1)
    {
        EXTIn_Handler[EXTI7]();
    }
    else if (Pending_Flags.PR_Reg_Fields.PR8 == 1)
    {
        EXTIn_Handler[EXTI8]();
    }
    else if (Pending_Flags.PR_Reg_Fields.PR9 == 1)
    {
        EXTIn_Handler[EXTI9]();
    }
    else
    {
        /*  Code  */
    }
}

void EXTI15_10_IRQHandler(void)
{
    Pending_Flags.PR_Reg_Value = EXTI->PR;
    if(Pending_Flags.PR_Reg_Fields.PR10 == 1)
    {
        EXTIn_Handler[EXTI10]();
    }
    else if (Pending_Flags.PR_Reg_Fields.PR11 == 1)
    {
        EXTIn_Handler[EXTI11]();
    }
    else if (Pending_Flags.PR_Reg_Fields.PR12 == 1)
    {
        EXTIn_Handler[EXTI12]();
    }
    else if (Pending_Flags.PR_Reg_Fields.PR13 == 1)
    {
        EXTIn_Handler[EXTI13]();
    }
    else if (Pending_Flags.PR_Reg_Fields.PR14 == 1)
    {
        EXTIn_Handler[EXTI14]();
    }
    else if (Pending_Flags.PR_Reg_Fields.PR15 == 1)
    {
        EXTIn_Handler[EXTI15]();
    }
    else
    {
        /*  Code  */
    }
}
