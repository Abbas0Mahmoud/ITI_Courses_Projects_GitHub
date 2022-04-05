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
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*_______________________________________________________________________________________*/

/*		                        HAL Layer Inclusion							             */

/*_______________________________________________________________________________________*/

/*		                        MCAL Layer Inclusion					                */
#include "../SCB/SCB_interface.h"
/*_______________________________________________________________________________________*/

/*		                        Self Files Inclusions							         */
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"
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
void NVIC_voidSetInterruptGroupSubPriority(u8 Copy_u8InterruptID,u8 Copy_InterruptGroupPriority,u8 Copy_u8InterruptSubPriority)
{
    /*      Variable to Store Interrupt Priority Both Group and Subgroup Before Assign each Group and Subgroup Priorities to Corresponding Variables        */
    u8 Local_u8InterruptPriority = 0;
    /*      Input Validation        */
    if(Copy_u8InterruptID < 60)
    {
        /*      Ckecking which Selected Group and Subgroup Policy is Selected       */
        /*      This Variable is Exported from SCB Module       */
        switch(Global_MSCB_To_MNVIC_u8GroupPolicy)
        {
            /*      16 Groups and 0 Subgroup Policy is Selected     */
            case NVIC_G16S0:
                /*      Input Validation for Group and Subgroup Priority for Input Interrupt ID     */
                if(Copy_InterruptGroupPriority < 16 && Copy_u8InterruptSubPriority == 0)
                {
                    /*      Assign Group Priority to Local_u8InterruptPriority since There is no Subgroup       */
                    Local_u8InterruptPriority = Copy_InterruptGroupPriority;
                    /*      Assign Local_u8InterruptPriority to Corresponding IPR Field of Input Interrupt ID      */
                    NVIC->IPR[Copy_u8InterruptID] = (Local_u8InterruptPriority << 4);
                }
                else
                {
                    /* Error */
                }
            break;
            /*      8 Groups and 2 Subgroup Policy is Selected     */
            case NVIC_G8S2:
                /*      Input Validation for Group and Subgroup Priority for Input Interrupt ID     */
                if(Copy_InterruptGroupPriority < 8 && Copy_u8InterruptSubPriority < 2)
                {
                    /*      Assign Group Priority and Subgroup Priority to Local_u8InterruptPriority    */
                    Local_u8InterruptPriority = (Copy_InterruptGroupPriority << 1) | (Copy_u8InterruptSubPriority);
                    /*      Assign Local_u8InterruptPriority to Corresponding IPR Field of Input Interrupt ID      */
                    NVIC->IPR[Copy_u8InterruptID] = (Local_u8InterruptPriority << 4);
                }
                else
                {
                    /* Error */
                }
            break;
            /*      4 Groups and 4 Subgroup Policy is Selected     */
            case NVIC_G4S4:
                /*      Input Validation for Group and Subgroup Priority for Input Interrupt ID     */
                if(Copy_InterruptGroupPriority < 4 && Copy_u8InterruptSubPriority < 4)
                {
                    /*      Assign Group Priority and Subgroup Priority to Local_u8InterruptPriority    */
                    Local_u8InterruptPriority = (Copy_InterruptGroupPriority << 2) | (Copy_u8InterruptSubPriority);
                    /*      Assign Local_u8InterruptPriority to Corresponding IPR Field of Input Interrupt ID      */
                    NVIC->IPR[Copy_u8InterruptID] = (Local_u8InterruptPriority << 4);
                }
                else
                {
                    /* Error */
                }
            break;
            /*      4 Groups and 4 Subgroup Policy is Selected     */
            case NVIC_G2S8:
                /*      Input Validation for Group and Subgroup Priority for Input Interrupt ID     */
                if(Copy_InterruptGroupPriority < 2 && Copy_u8InterruptSubPriority < 8)
                {
                    /*      Assign Group Priority and Subgroup Priority to Local_u8InterruptPriority    */
                    Local_u8InterruptPriority = (Copy_InterruptGroupPriority << 3) | (Copy_u8InterruptSubPriority);
                    /*      Assign Local_u8InterruptPriority to Corresponding IPR Field of Input Interrupt ID      */
                    NVIC->IPR[Copy_u8InterruptID] = (Local_u8InterruptPriority << 4);
                }
                else
                {
                    /* Error */
                }
            break;
            /*      0 Groups and 16 Subgroups Policy is Selected     */
            case NVIC_G0S16:
                /*      Input Validation for Group and Subgroup Priority for Input Interrupt ID     */
                if(Copy_InterruptGroupPriority == 0 && Copy_u8InterruptSubPriority < 16)
                {
                    /*      Assign Subroup Priority to Local_u8InterruptPriority since There is no Group       */
                    Local_u8InterruptPriority = Copy_u8InterruptSubPriority;
                    /*      Assign Local_u8InterruptPriority to Corresponding IPR Field of Input Interrupt ID      */
                    NVIC->IPR[Copy_u8InterruptID] = (Local_u8InterruptPriority << 4);
                }
                else
                {
                    /* Error */
                }
            break;
        }
    }
    else
    {
        /* Error */
    }
}

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
void MNVIC_voidGetInterruptPriority(u8 Copy_u8InterruptID,u8 * Copy_pu8InterruptGroupPriority,u8 * Copy_pu8InterruptSubPriority)
{
    u8 Local_u8InterruptPriority = 0;
    if(Copy_u8InterruptID < 60)
    {
        switch(Global_MSCB_To_MNVIC_u8GroupPolicy)
        {
            case NVIC_G16S0:
                Local_u8InterruptPriority = NVIC->IPR[Copy_u8InterruptID] >> 4;
                *Copy_pu8InterruptGroupPriority = Local_u8InterruptPriority;
                *Copy_pu8InterruptSubPriority = 0;
            break;
            case NVIC_G8S2:
                Local_u8InterruptPriority = NVIC->IPR[Copy_u8InterruptID] >> 4;
                *Copy_pu8InterruptGroupPriority = Local_u8InterruptPriority >> 1;
                *Copy_pu8InterruptSubPriority = Local_u8InterruptPriority & 0x1;
            break;
            case NVIC_G4S4:
                Local_u8InterruptPriority = NVIC->IPR[Copy_u8InterruptID] >> 4;
                *Copy_pu8InterruptGroupPriority = Local_u8InterruptPriority >> 2;
                *Copy_pu8InterruptSubPriority = Local_u8InterruptPriority & 0x3;
            break;
            case NVIC_G2S8:
                Local_u8InterruptPriority = NVIC->IPR[Copy_u8InterruptID] >> 4;
                *Copy_pu8InterruptGroupPriority = Local_u8InterruptPriority >> 3;
                *Copy_pu8InterruptSubPriority = Local_u8InterruptPriority & 0x7;
            break;
            case NVIC_G0S16:
                Local_u8InterruptPriority = NVIC->IPR[Copy_u8InterruptID] >> 4;
                Copy_pu8InterruptGroupPriority = 0;
                *Copy_pu8InterruptSubPriority = Local_u8InterruptPriority;
            break;
        }
    }
    else
    {
        /* Error */
    }
}
