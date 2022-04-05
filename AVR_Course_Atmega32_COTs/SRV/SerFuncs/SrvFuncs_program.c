/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	SrvFuncs Driver                             							  	  */
/*  Project Description    :	SrvFuncs Driver                                                 			  */
/*  Target Controller 	   :	                                               					              */
/*  File Name              :	SrvFuncs_program.c                                     					      */
/*  Layer           	   :	SRV                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*		                        Library Inclusions								         */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*_______________________________________________________________________________________*/

/*		                        Self Files Inclusoins							         */
#include "SrvFuncs_config.h"
#include "SrvFuncs_interface.h"
#include "SrvFuncs_private.h"
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           		          Program Macros       		     		          	  	          */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           		     Program Objects Definition       		     		          	      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           		     Program Functions Prototype       		     		          	      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           		   Program Functions Implementation       		     		          	  */
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
u8 * SplitNumberIntoDigits(u32 Copy_u32Number,u8 * Copy_pu8NumberinDigits)
{
    u8 Local_u8DigitsIndex = 0;
    u8 Local_u8Reminder = 0;
    if(Copy_u32Number == 0)
    {
        Copy_pu8NumberinDigits[Local_u8DigitsIndex] = 0;
    }
    else
    {
        while(Copy_u32Number != 0)
        {
            Local_u8Reminder = Copy_u32Number % 10;
            if(Local_u8Reminder == 0)
            {
                Copy_pu8NumberinDigits[Local_u8DigitsIndex++] = Local_u8Reminder;
                Copy_u32Number = Copy_u32Number / 10;
            }
            else
            {
                Copy_pu8NumberinDigits[Local_u8DigitsIndex++] = Local_u8Reminder;
                Copy_u32Number = (Copy_u32Number - Local_u8Reminder) / 10;
            }
        }
    }
    return Copy_pu8NumberinDigits;
}

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
u32 CombineDigitsIntoNumber(u8 * Copy_pu8NumberDigits,u8 Copy_u8NumberofDigits)
{
    u32 Local_u8LastNumberIndex = 0;
    u32 Local_u8Number = 0;
    u8 Local_u8LoopCounter = 0;
    for(Local_u8LoopCounter = 0;Local_u8LoopCounter < Copy_u8NumberofDigits;Local_u8LoopCounter++)
    {
        if(Local_u8LoopCounter == 0)
        {
            Local_u8LastNumberIndex = 1;
        }
        else
        {
            Local_u8LastNumberIndex *= 10;
        }
    }
    for(Local_u8LoopCounter = 0;Local_u8LoopCounter < Copy_u8NumberofDigits;Local_u8LoopCounter++)
    {
        Local_u8Number += *(Copy_pu8NumberDigits + Local_u8LoopCounter) * Local_u8LastNumberIndex;
        Local_u8LastNumberIndex = Local_u8LastNumberIndex / 10;
    }
    return Local_u8Number;
}

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
s32 _s32Map(s32 Copy_s32InputValueMin,s32 Copy_s32InputValueMax,s32 Copy_s32OutputValueMin,s32 Copy_s32OutputValueMax,s32 Copy_s32InputValue)
{
    f32 Local_s32Slope = 0;
    Local_s32Slope = (Copy_s32OutputValueMax - Copy_s32OutputValueMin)/((f32)(Copy_s32InputValueMax - Copy_s32InputValueMin));
    s32 Local_s32OutputValue = 0;
    Local_s32OutputValue = ((Local_s32Slope*(Copy_s32InputValue - Copy_s32InputValueMin))+Copy_s32OutputValueMin);
    return Local_s32OutputValue;
}