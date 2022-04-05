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
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*_______________________________________________________________________________________*/

/*		                        HAL Layer Inclusion							             */

/*_______________________________________________________________________________________*/

/*		                        MCAL Layer Inclusion					                 */

/*_______________________________________________________________________________________*/

/*		                        Self Files Inclusions							         */
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Global Declerations       		     		          	  	  	      */
/* ---------------------------------------------------------------------------------------------------------- */

u8 Global_u8SingleFlag = 0;

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Function Prototypes       		     		          	  		      */
/* ---------------------------------------------------------------------------------------------------------- */

static void (*MSTK_Handler)(void) = NULL;

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
void MSTK_voidInit(void)
{
    /*      SET SYSTICK TIMER INTERRUPT ENABLE STATE        */
    #if STK_ENABLE_INTERRUPT == ENABLE
        SET_BIT(STK->CTRL,STK_CTRL_TICKINT_BIT);
    #elif
        CLR_BIT(STK->CTRL,STK_CTRL_TICKINT_BIT);
    #else
            #error " System Timer Interrupt Enable Configuration Error "
    #endif
    /*      SET SYSTICK CLOCK SOURCE      */
    #if STK_CLK_SOURCE == CLK_AHB
        SET_BIT(STK->CTRL,STK_CTRL_CLKSOURCE_BIT);
    #elif STK_CLK_SOURCE == CLK_AHB_DIV_2
        CLR_BIT(STK->CTRL,STK_CTRL_CLKSOURCE_BIT);
    #else
        #error "System Timer Clock Source Configuration Error "
    #endif
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
void MSTK_voidSetBusyWait_Ticks(u32 Copy_u32TicksCount)
{
    /*      ClearCTRL_COUNTFLAG_BIT By Writing Value to VAL Register      */
    STK->VAL = 0X00000000;
    /*      Assign Ticks Count to Load Register     */
    STK->LOAD = Copy_u32TicksCount;
    /*      Enable SysTick Timer        */
    SET_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);
    /*      Polling until Timer Reaches Ticks Count in Load Register        */
    while(GET_BIT(STK->CTRL,STK_CTRL_COUNTFLAG_BIT) == 0);
    /*      ClearCTRL_COUNTFLAG_BIT By Writing Value to VAL Register      */
    STK->VAL = 0X00000000;
    /*      Stop Timer      */
    CLR_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);
    /*      To Prevent Timer From Starting Next Time       */
    /*      The Function Called unless There is Value in Load Register      */
    STK->LOAD = 0X00000000;
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
void MSTK_voidSetInterval_Single(u32 Copy_u32TicksCount,void(*Copy_pvFunction)(void))
{
    /*      Set CallBack Function        */
    MSTK_Handler = Copy_pvFunction;
    /*      ClearCTRL_COUNTFLAG_BIT By Writing Value to VAL Register      */
    STK->VAL = 0X00000000;
    /*      Assign Ticks Count to Load Register     */
    STK->LOAD = Copy_u32TicksCount;
    /*      Enable SysTick Timer        */
    SET_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);
    /*      Enable SysTick Timer Interrupt      */
    SET_BIT(STK->CTRL,STK_CTRL_TICKINT_BIT);
    /*      Set SingleFlag      */
    Global_u8SingleFlag = 1;
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
void MSTK_voidSetInterval_Periodic(u32 Copy_u32TicksCount,void(*Copy_pvFunction)(void))
{
    /*      Set CallBack Function        */
    MSTK_Handler = Copy_pvFunction;
    /*      ClearCTRL_COUNTFLAG_BIT By Writing Value to VAL Register      */
    STK->VAL = 0X00000000;
    /*      Assign Ticks Count to Load Register     */
    STK->LOAD = Copy_u32TicksCount;
    /*      Enable SysTick Timer        */
    SET_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);
    /*      Enable SysTick Timer Interrupt      */
    SET_BIT(STK->CTRL,STK_CTRL_TICKINT_BIT);
    /*      Set SingleFlag      */
    Global_u8SingleFlag = 0;
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
void MSTK_voidStopTimer(void)
{
    /*      Disable SysTick Timer       */
    CLR_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);
    /*      Clear Load Register To Ensure When Timer is Enabled     */
    /*      It will Start Only If a Value is Passed To Load Register        */
    STK->LOAD = 0X00000000;
    /*      ClearCTRL_COUNTFLAG_BIT By Writing Value to VAL Register      */
    STK->VAL = 0X00000000;
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
u32  MSTK_u32GetRemainingTime(void)
{
    /*      Return VAL Register Value as Represents The Remaining Ticks to Reach 0      */
    return (STK->VAL);
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
u32  MSTK_u32GetElapsedTime(void)
{
    /*      Return LOAD - VAL Value as Represents The Time Elapsed From Starting at LOAd Value until Now        */
    return ((STK->LOAD) - (STK->VAL));
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
void MSTK_voidEnableInterrupt(void)
{
    /*      Enable SysTick Interrupt        */
    SET_BIT(STK->CTRL,STK_CTRL_TICKINT_BIT);
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
void MSTK_voidDisableInterrupt(void)
{
    /*      Disable SysTick Interrupt       */
    CLR_BIT(STK->CTRL,STK_CTRL_TICKINT_BIT);
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
void MSTK_voidSetCallBack(void(*Copy_pvFunction)(void))
{
    Copy_pvFunction = MSTK_Handler;
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
/*      Note : Without IRQ Because It's Core Peripheral     */
void SysTick_Handler(void)
{
    if(MSTK_Handler != NULL)
    {
        /*      Check if CallBack Function is From Single or Periodic Mode      */
        if(Global_u8SingleFlag)
        {
            /*      CallBack Fuction is From Single     */
            /*      Disable SysTick Timer       */
            CLR_BIT(STK->CTRL,STK_CTRL_ENABLE_BIT);
            /*      To Prevent Timer From Starting Next Time       */
            /*      The Function Called unless There is Value in Load Register      */
            STK->LOAD = 0X00000000;
            /*      Clear SingleFlag        */
            Global_u8SingleFlag = 0;
        }
        /*      Execute CallBack Function       */
        MSTK_Handler();
        /*      ClearCTRL_COUNTFLAG_BIT By Writing Value to VAL Register      */
        STK->VAL = 0X00000000;
    }
}
/*_________________________________________________________________________________________________*/
