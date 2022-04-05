/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	SCB Driver                             							  	          */
/*  Project Description    :	SCB Driver for STM32F10x Family                             				  */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	SCB_config.h                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*		                Library Inclusions								 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*_______________________________________________________________________*/

/*		                HAL Layer Inclusion							     */

/*_______________________________________________________________________*/

/*		                MCAL Layer Inclusion					         */

/*_______________________________________________________________________*/

/*		                Self Files Inclusions							 */
#include "SCB_interface.h"
#include "SCB_private.h"
#include "SCB_config.h"
/*_______________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           		        Program Definitions       		     		          	  	      */
/* ---------------------------------------------------------------------------------------------------------- */
u8 Global_MSCB_To_MNVIC_u8GroupPolicy = 0;
/* ---------------------------------------------------------------------------------------------------------- */
/*                           		        Program Functions       		     		          	  	      */
/* ---------------------------------------------------------------------------------------------------------- */

/*                      	Application interrupt and reset control register (SCB_AIRCR)	     		      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :	MSCB_MNVIC_voidSetNVICGroupPolicy
	Function Return Type        :	void
	Function Description        :	Function to Set Priority Policy(Number of Priority Groups and Sub Groups) for NVIC Module
	Function Arguments          :   Copy_u8GroupPolicy
    Function Arguments Datatype :   (u8 : unsigned char)

	Function Parameters Options :
	_____________________________

    Copy_u8GroupPolicy  :
                            NVIC_G16S0
                            NVIC_G8S2
                            NVIC_G4S4
                            NVIC_G2S8
                            NVIC_G0S16

*/
void MSCB_MNVIC_voidSetNVICGroupPolicy(u8 Copy_u8GroupPolicy)
{
    /*      Input Validation        */
    if((Copy_u8GroupPolicy > 2) && (Copy_u8GroupPolicy < 8))
    {
        /*      Setting AIRCR Register with Key Vector Value to Enable Writing to Register       */
        SCB->AIRCR = (VECT_KEY_VALUE << VECTKEYSTSTAT_BIT0);
        /*      Clear This Bit as It's used for Debugging and Must Kept Zero        */
        CLR_BIT(SCB->AIRCR,VECTRESET_BIT);
        /*      Clear This Bit as It's used for Debugging and Must Kept Zero        */
        CLR_BIT(SCB->AIRCR,VECTCLRACTIVE_BIT);
        /*      Disable System Reset Request        */
        CLR_BIT(SCB->AIRCR,SYSRESETREQ_BIT);
        /*      Masking Priority Group Bits     */
        SCB->AIRCR &= GROUP_PRIORITY_BITS_MASK;
        /*      Setting Priority Group Bits     */
        SCB->AIRCR |=( Copy_u8GroupPolicy <<PRIGROUP_BIT0);
        /*      Assign Selected Group Policy to Global Variable to use It in Another Mdules     */
        Global_MSCB_To_MNVIC_u8GroupPolicy = Copy_u8GroupPolicy;
    }
    else
    {
        /* Error */
    }
}

u8 MSCB_u8GetEndianessState(void)
{
    return GET_BIT(SCB->AIRCR,ENDIANESS_BIT);
}
