/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  									  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	RCC Driver                             							  	          */
/*  Project Description    :	RCC Driver for STM32F10x Family                             				  */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	RCC_program.c                                    							  */
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

/*		                        MCAL Layer Inclusion					                 */

/*_______________________________________________________________________________________*/

/*		                        Self Files Inclusions							         */
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Function Implementations       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

void MRCC_voidInit(void)
{
    /*      Variable to Store Clock Source Status       */
    u8 Local_u8ClkStatus = CLK_NOT_READY;
    /*      HSI Clock Source is Selected        */
    #if SYSTEM_CLK_SOURCE == RCC_CFGR_SW_HSI_SYSCLK
        /*      Enable HSI      */
        MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_HSI_SYSCLK,CLK_SRC_ON);
        /*      Get HSI Clock Status        */
        Local_u8ClkStatus = MRCC_u8CheckCLKSourceReady(HSI_CLK_RDY);
        /*      Check HSI Status Ready or Not       */
        if(Local_u8ClkStatus  == CLK_READY)
        {
            /*      Setting Buses Prescalers        */
            MRCC_voidSetBusesPrescalers(AHB_PRESCALER,APB1_PRESCALER,APB2_PRESCALER);
            /*      Selecting HSI as System Clock Source        */
            MRCC_voidSelectClkSource(RCC_CFGR_SW_HSI_SYSCLK);
            /*     Disable HSE Clock Source     */
            MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_HSE_SYSCLK,CLK_SRC_OFF);
            /*      Disable PLL Clock Source        */
            MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_PLL_SYSCLK,CLK_SRC_OFF);
        }
        else
        {
            /*  Error   */
        }
    /*      HSE Clock Source is Selected        */
    #elif SYSTEM_CLK_SOURCE == RCC_CFGR_SW_HSE_SYSCLK
        /*      Enable HSE      */
        MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_HSE_SYSCLK,CLK_SRC_ON);
        /*      Get HSE Clock Status        */
        Local_u8ClkStatus = MRCC_u8CheckCLKSourceReady(HSE_CLK_RDY);
        /*      Check HSE Status Ready or Not       */
        if(Local_u8ClkStatus == CLK_READY)
        {
            /*      Setting Buses Prescalers        */
            MRCC_voidSetBusesPrescalers(AHB_PRESCALER,APB1_PRESCALER,APB2_PRESCALER);
            /*      Selecting HSE as System Clock Source        */
            MRCC_voidSelectClkSource(RCC_CFGR_SW_HSE_SYSCLK);
            /*      Disable HSI Clock Source        */
            MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_HSI_SYSCLK,CLK_SRC_OFF);
            /*      Disable PLL Clock Source        */
            MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_PLL_SYSCLK,CLK_SRC_OFF);
        }
        else
        {
            /*  Error   */
        }
    /*      PLL Clock Source is Selected        */
    #elif SYSTEM_CLK_SOURCE == RCC_CFGR_SW_PLL_SYSCLK
        /*      HSI Clock Divided by 2 Is Selected as PLL Input Clock Source        */
        #if PLL_INPUT_SOURCE == HSI_2_IN_PLL
            /*      Enable HSI Clock Source     */
            MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_HSI_SYSCLK,CLK_SRC_ON);
            /*      Get HSI Clock Status        */
            Local_u8ClkStatus = MRCC_u8CheckCLKSourceReady(HSI_CLK_RDY);
            /*      Check HSI Status Ready or Not       */
            if(Local_u8ClkStatus == CLK_READY)
            {
                /*      Select HSI System Clock Source      */
                MRCC_voidSelectClkSource(RCC_CFGR_SW_HSI_SYSCLK);
                /*      Disable HSE Clock Source        */
                MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_HSE_SYSCLK,CLK_SRC_OFF);
                /*      Disable PLL Clock Source        */
                MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_PLL_SYSCLK,CLK_SRC_OFF);
                /*      Checking if PLL Configurations are Within constrains        */
                if((((HSI_CLK_F/2)*(PLL_MULTIPLICATION_FACTOR+2)) <= PLL_CLK_F_MAX))
                {
                    /*      Setting PLL Source and Multiplication Factor        */
                    MRCC_voidSetPLLConfiguration(PLL_INPUT_SOURCE,PLL_MULTIPLICATION_FACTOR);
                    /*      Setting Buses Prescaler     */
                    MRCC_voidSetBusesPrescalers(AHB_PRESCALER,APB1_PRESCALER,APB2_PRESCALER);
                    /*      Enable PLL      */
                    MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_PLL_SYSCLK,CLK_SRC_ON);
                    /*      Get PLL Clock Status        */
                    Local_u8ClkStatus = MRCC_u8CheckCLKSourceReady(PLL_CLK_RDY);
                    /*      Check PLL Status Ready or Not       */
                    if(Local_u8ClkStatus == CLK_READY)
                    {
                        /*      Set PLL as System Clock Source      */
                        MRCC_voidSelectClkSource(RCC_CFGR_SW_PLL_SYSCLK);
                        /*      Disable HSE     */
                        MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_HSE_SYSCLK,CLK_SRC_OFF);
                    }
                    else
                    {
                        /*  Error   */
                    }
                }
                else
                {
                    /*  Error   */
                }
            }
            else
            {
                /*  Error   */
            }
        /*      HSE Is Selected as PLL Input Clock Source      */
        #elif   PLL_INPUT_SOURCE == HSE_IN_PLL
            /*      Enable HSE Clock Source     */
            MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_HSE_SYSCLK,CLK_SRC_ON);
            /*      Get HSE Clock Source Status     */
            Local_u8ClkStatus = MRCC_u8CheckCLKSourceReady(HSE_CLK_RDY);
            /*      Check HSE Ready or Not Status       */
            if(Local_u8ClkStatus == CLK_READY)
            {
                /*      Set HSE System Clock Source     */
                MRCC_voidSelectClkSource(RCC_CFGR_SW_HSE_SYSCLK);
                /*      Disable HSI Clock Source        */
                MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_HSI_SYSCLK,CLK_SRC_OFF);
                /*      Disable PLL Clock Source        */
                MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_PLL_SYSCLK,CLK_SRC_OFF);
                /*      Checking if PLL Configurations are Within constrains        */
                if((((HSE_CLK_F)*(PLL_MULTIPLICATION_FACTOR+2)) <= PLL_CLK_F_MAX))
                {
                    /*      Setting PLL Source and Multiplication Factor        */
                    MRCC_voidSetPLLConfiguration(PLL_INPUT_SOURCE,PLL_MULTIPLICATION_FACTOR);
                    /*      Setting Buses Prescaler     */
                    MRCC_voidSetBusesPrescalers(AHB_PRESCALER,APB1_PRESCALER,APB2_PRESCALER);
                    /*      Enable PLL      */
                    MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_PLL_SYSCLK,CLK_SRC_ON);
                    /*      Get PLL Clock Status        */
                    Local_u8ClkStatus = MRCC_u8CheckCLKSourceReady(PLL_CLK_RDY);
                    /*      Check PLL Status Ready or Not       */
                    if(Local_u8ClkStatus == CLK_READY)
                    {
                        /*      Set PLL as System Clock Source      */
                        MRCC_voidSelectClkSource(RCC_CFGR_SW_PLL_SYSCLK);
                        /*      Disable HSI     */
                        MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_HSI_SYSCLK,CLK_SRC_OFF);
                    }
                    else
                    {
                        /*  Error   */
                    }
                }
                else
                {
                    /*  Error   */
                }
            }
            else
            {
                /*  Error   */
            }
        /*      HSE Divided By 2 Is Selected as PLL Input Clock Source      */
        #elif   PLL_INPUT_SOURCE == HSE_2_IN_PLL
            /*      Enable HSE Clock Source     */
            MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_HSE_SYSCLK,CLK_SRC_ON);
            /*      Get HSE Clock Source Status     */
            Local_u8ClkStatus = MRCC_u8CheckCLKSourceReady(HSE_CLK_RDY);
            /*      Check HSE Ready or Not Status       */
            if(Local_u8ClkStatus == CLK_READY)
            {
                /*      Set HSE System Clock Source     */
                MRCC_voidSelectClkSource(RCC_CFGR_SW_HSE_SYSCLK);
                /*      Disable HSI Clock Source        */
                MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_HSI_SYSCLK,CLK_SRC_OFF);
                /*      Disable PLL Clock Source        */
                MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_PLL_SYSCLK,CLK_SRC_OFF);
                /*      Checking if PLL Configurations are Within constrains        */
                if((((HSE_CLK_F/2)*(PLL_MULTIPLICATION_FACTOR+2)) <= PLL_CLK_F_MAX))
                {
                    /*      Setting PLL Source and Multiplication Factor        */
                    MRCC_voidSetPLLConfiguration(PLL_INPUT_SOURCE,PLL_MULTIPLICATION_FACTOR);
                    /*      Setting Buses Prescaler     */
                    MRCC_voidSetBusesPrescalers(AHB_PRESCALER,APB1_PRESCALER,APB2_PRESCALER);
                    /*      Enable PLL      */
                    MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_PLL_SYSCLK,CLK_SRC_ON);
                    /*      Get PLL Clock Status        */
                    Local_u8ClkStatus = MRCC_u8CheckCLKSourceReady(PLL_CLK_RDY);
                    /*      Check PLL Status Ready or Not       */
                    if(Local_u8ClkStatus == CLK_READY)
                    {
                        /*      Set PLL as System Clock Source      */
                        MRCC_voidSelectClkSource(RCC_CFGR_SW_PLL_SYSCLK);
                        /*      Disable HSI     */
                        MRCC_voidSetClkSourceStatus(RCC_CFGR_SW_HSI_SYSCLK,CLK_SRC_OFF);
                    }
                    else
                    {
                        /*  Error   */
                    }
                }
            }
            else
            {
                /*  Error   */
            }
        #else
            #error  "PLL Clock Source Configuration Error"
        #endif
    #else
        #error  "Clock Source Configuration Error"
    #endif
}

/* ----------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :   Function to Set Which Clock Source to be used
                                    by using System Clock Switch Bits in CFGR Register
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
void MRCC_voidSelectClkSource(u8 Copy_u8ClkSource)
{
    switch(Copy_u8ClkSource)
    {
        /*      HSI is Selected as System Clock     */
        case RCC_CFGR_SW_HSI_SYSCLK:
            /*      Masking System Clock Switch Bits in CFGR Register       */
            RCC->CFGR &= RCC_CFGR_SW_MASK;
            /*      Setting System Clock Bits to Select HSI     */
            RCC->CFGR |= RCC_CFGR_SW_HSI_SYSCLK;
        break;
        /*      HSE is Selected as System Clock     */
        case RCC_CFGR_SW_HSE_SYSCLK:
            /*      Masking System Clock Switch Bits in CFGR Register       */
            RCC->CFGR &= RCC_CFGR_SW_MASK;
            /*      Setting System Clock Bits to Select HSE     */
            RCC->CFGR |= RCC_CFGR_SW_HSE_SYSCLK;
        break;
        /*      PLL is Selected as System Clock     */
        case RCC_CFGR_SW_PLL_SYSCLK:
            /*      Masking System Clock Switch Bits in CFGR Register       */
            RCC->CFGR &= RCC_CFGR_SW_MASK;
            /*      Setting System Clock Bits to Select HSE     */
            RCC->CFGR |= RCC_CFGR_SW_PLL_SYSCLK;
        break;
    }
}

/* ----------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :   Function to Enable or Disable Selected Clock Source
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
void MRCC_voidSetClkSourceStatus(u8 Copy_u8ClkSource,u8 Copy_u8ClkSourceStatus)
{
    switch(Copy_u8ClkSource)
    {
        /*      HSI is Selected      */
        case RCC_CFGR_SW_HSI_SYSCLK:
            switch(Copy_u8ClkSourceStatus)
            {
                case CLK_SRC_OFF:
                    /*      Disable HSI by Clearing HSION Bit in CR Register        */
                    CLR_BIT(RCC->CR,RCC_CR_HSION_BIT);
                break;
                case CLK_SRC_ON:
                    /*      Enable HSI by Setting HSION Bit in CR Register      */
                    SET_BIT(RCC->CR,RCC_CR_HSION_BIT);
                break;
            }
        break;
        /*      HSE is Selected      */
        case RCC_CFGR_SW_HSE_SYSCLK:
            switch(Copy_u8ClkSourceStatus)
            {
                case CLK_SRC_OFF:
                    /*      Disable HSE by Clearing HSEON Bit in CR Register        */
                    CLR_BIT(RCC->CR,RCC_CR_HSEON_BIT);
                break;
                case CLK_SRC_ON:
                    /*      Enable HSE by Setting HSEON Bit in CR Register      */
                    SET_BIT(RCC->CR,RCC_CR_HSEON_BIT);
                break;
            }
        break;
        /*      PLL is Selected      */
        case RCC_CFGR_SW_PLL_SYSCLK:
            switch(Copy_u8ClkSourceStatus)
            {
                case CLK_SRC_OFF:
                    /*      Disable PLL by Clearing PLLON Bit in CR Register        */
                    CLR_BIT(RCC->CR,RCC_CR_PLLON_BIT);
                break;
                case CLK_SRC_ON:
                    /*      Enable PLL by Setting PLLON Bit in CR Register      */
                    SET_BIT(RCC->CR,RCC_CR_PLLON_BIT);
                break;
            }
        break;
    }
}

/* ----------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :   Function to Return Clock Source Status Whether Ready or Not after Turning ON
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
u8 MRCC_u8CheckCLKSourceReady(u8 Copy_u8CheckClkSource)
{
    /*      Variable to Store Clock Source Status       */
    /*      Initialize Variable to Predefined Variable as Clock ready       */
    u8 Local_u8ClkStatus = CLK_READY;
    /*      Variable to Store TimeOut Value while waiting to Clock Source to Get Ready      */
    u32 Local_u32TimeOut = 0;
    switch(Copy_u8CheckClkSource)
    {
        /*      Checking for HSI Clock Source is Ready or Not       */
        case HSI_CLK_RDY:
            /*      Looping until Clock Source is Ready or TimeOut is Reached       */
            while(GET_BIT(RCC->CR,RCC_CR_HSIRDY_BIT) == CLK_NOT_READY)
            {
                /*      Updating TimeOut        */
                Local_u32TimeOut++;
                /*      Checking if Predefined TimeOut Value is Reached     */
                if(Local_u32TimeOut == CLK_READY_TIME_OUT)
                {
                    /*      Setting Clock Source Status Not Ready after Clock Ready TimeOut is Reached      */
                    Local_u8ClkStatus = CLK_NOT_READY;
                    break;
                }
            }
        break;
        /*      Checking for HSE Clock Source is Ready or Not       */
        case HSE_CLK_RDY:
            /*      Looping until Clock Source is Ready or TimeOut is Reached       */
            while(GET_BIT(RCC->CR,RCC_CR_HSERDY_BIT) == CLK_NOT_READY)
            {
                /*      Updating TimeOut        */
                Local_u32TimeOut++;
                /*      Checking if Predefined TimeOut Value is Reached     */
                if(Local_u32TimeOut == CLK_READY_TIME_OUT)
                {
                    /*      Setting Clock Source Status Not Ready after Clock Ready TimeOut is Reached      */
                    Local_u8ClkStatus = CLK_NOT_READY;
                    break;
                }
            }
        break;
        /*      Checking for PLL Clock Source is Ready or Not       */
        case PLL_CLK_RDY:
            /*      Looping until Clock Source is Ready or TimeOut is Reached       */
            while(GET_BIT(RCC->CR,RCC_CR_PLLRDY_BIT) == CLK_NOT_READY)
            {
                /*      Updating TimeOut        */
                Local_u32TimeOut++;
                /*      Checking if Predefined TimeOut Value is Reached     */
                if(Local_u32TimeOut == CLK_READY_TIME_OUT)
                {
                    /*      Setting Clock Source Status Not Ready after Clock Ready TimeOut is Reached      */
                    Local_u8ClkStatus = CLK_NOT_READY;
                    break;
                }
            }
        break;
    }
    /*      return Clock Source Status      */
    return Local_u8ClkStatus;
}
/* __________________________________________________________________________________________________________ */

/* ----------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :   Function to Set Up PLL Configuration :
                                    PLL Input Source and PLL Multiplier Factor
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
void MRCC_voidSetPLLConfiguration(u8 Copy_u8PLLInputSource,u8 Copy_u8PLLMulFactor)
{
    /*      Masking PLL Multiplier  Factor Bits in CFGR Register        */
    RCC->CFGR &= RCC_CFGR_PLLMUL_MASK;
    /*      Checking for PLL Input Source       */
    switch(Copy_u8PLLInputSource)
    {
        /*      HSI Divided by 2 as PLL Input Source     */
        case HSI_2_IN_PLL:
            /*      Clear PLL Entry Clock Source Bit in CFGR Register       */
            /*      To Select HSI Divied by 2 as Input Source      */
            CLR_BIT(RCC->CFGR,RCC_CFGR_PLLSRC_BIT);
            /*      Assign PLL Multiplication Factor to Corresponding Bits in CFGR Register     */
            RCC->CFGR |= Copy_u8PLLMulFactor;
        break;
        /*      HSE as PLL Input Source     */
        case HSE_IN_PLL:
            /*      Set PLL Entry Clock Source Bit in CFGR Register       */
            /*      To Select HSE as Input Source      */
            SET_BIT(RCC->CFGR,RCC_CFGR_PLLSRC_BIT);
            /*      Clear Divider Bit for HSE       */
            CLR_BIT(RCC->CFGR,RCC_CFGR_PLLXTPRE_BIT);
            /*      Assign PLL Multiplication Factor to Corresponding Bits in CFGR Register     */
            RCC->CFGR |= Copy_u8PLLMulFactor;
        break;
        /*      HSE Divided by 2 as PLL Input Source        */
        case HSE_2_IN_PLL:
            /*      Set PLL Entry Clock Source Bit in CFGR Register       */
            /*      To Select HSE as Input Source      */
            SET_BIT(RCC->CFGR,RCC_CFGR_PLLSRC_BIT);
            /*      Set Divider Bit for HSE       */
            SET_BIT(RCC->CFGR,RCC_CFGR_PLLXTPRE_BIT);
            /*      Assign PLL Multiplication Factor to Corresponding Bits in CFGR Register     */
            RCC->CFGR |= Copy_u8PLLMulFactor;
        break;
    }
}
/* __________________________________________________________________________________________________________ */

/* ----------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :   Function to Set Buses Prescaler by Passing Required Each Bus Prescaler
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
void MRCC_voidSetBusesPrescalers(u8 Copy_u8AHBPrescaler,u8 Copy_u8APB1Prescaler,u8 Copy_u8APB2Prescaler)
{
    /*      Masking Buses Prescalers Bits all at once       */
    RCC->CFGR &= RCC_CFGR_BUSES_PRESCALER_MASK;
    /*      Assing Each Bus Prescaler Bits with Coressponding Prescaler Value       */
    RCC->CFGR |=    (((Copy_u8AHBPrescaler << RCC_CFGR_HPRE_BIT0)|
                    (Copy_u8APB1Prescaler << RCC_CFGR_PPRE1_BIT0)|
                    (Copy_u8APB2Prescaler << RCC_CFGR_PPRE2_BIT0)) << RCC_CFGR_HPRE_BIT0);
}
/* __________________________________________________________________________________________________________ */

/* ----------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :   Function to Set Bus Prescaler
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
void MRCC_voidSetBusPrescaler(u8 Copy_u8BusName,u8 Copy_BusPrescaler)
{
    /*      Checking Bus Name       */
    switch(Copy_u8BusName)
    {
        /*      AHB Bus is Selected     */
        case AHB_BUS:
            /*      Masking AHB Bus Prescaler Bits      */
            RCC->CFGR &= RCC_CFGR_HPRE_MASK;
            /*      Setting AHB Bus Prescaler Bits      */
            RCC->CFGR |= (Copy_BusPrescaler << RCC_CFGR_HPRE_BIT0);
        break;
        /*      APB1 Bus is Selected        */
        case APB1_BUS:
            /*      Masking APB1 Bus Prescaler Bits      */
            RCC->CFGR &= RCC_CFGR_PPRE1_MASK;
            /*      Setting APB1 Bus Prescaler Bits      */
            RCC->CFGR |= (Copy_BusPrescaler << RCC_CFGR_PPRE1_BIT0);
        break;
            /*      APB2 Bus is Selected        */
        case APB2_BUS:
            /*      Masking APB2 Bus Prescaler Bits      */
            RCC->CFGR &= RCC_CFGR_PPRE2_MASK;
            /*      Setting APB2 Bus Prescaler Bits      */
            RCC->CFGR |= (Copy_BusPrescaler << RCC_CFGR_PPRE2_BIT0);
        break;
    }
}
/* __________________________________________________________________________________________________________ */

/* ----------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :   Function to Enable Clock Source for Given Peripheral connected to Bus
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
/* ----------------------------------------------------------------------------------------------------------- */
void MRCC_voidSetPeripheralClkStatus(u8 Copy_u8BusName,u8 Copy_u8Peripheral,u8 Copy_u8ClkStatus)
{
    /*      Checking Bus Name       */
    switch(Copy_u8BusName)
    {
        /*      Peripheral is Connected to AHB Bus      */
        case AHB_BUS:
            /*      Checking Clock Status       */
            switch (Copy_u8ClkStatus)
            {
                case CLK_SRC_OFF:
                    /*      Disable Peripheral Clock Bit in AHBENR Register     */
                    CLR_BIT(RCC->AHBENR,Copy_u8Peripheral);
                break;
                case CLK_SRC_ON:
                    /*      Enable Peripheral Clock Bit in AHBENR Register      */
                    SET_BIT(RCC->AHBENR,Copy_u8Peripheral);
                break;
            }
        break;
        /*      Peripheral is Connected to APB1 Bus      */
        case APB1_BUS:
            /*      Checking Clock Status       */
            switch (Copy_u8ClkStatus)
            {
                case CLK_SRC_OFF:
                    /*      Disable Peripheral Clock Bit in APB1ENR Register     */
                    CLR_BIT(RCC->APB1ENR,Copy_u8Peripheral);
                break;
                case CLK_SRC_ON:
                    /*      Enable Peripheral Clock Bit in APB2ENR Register      */
                    SET_BIT(RCC->APB1ENR,Copy_u8Peripheral);
                break;
            }
        break;
        /*      Peripheral is Connected to APB2 Bus      */
        case APB2_BUS:
            /*      Checking Clock Status       */
            switch (Copy_u8ClkStatus)
            {
                case CLK_SRC_OFF:
                    /*      Disable Peripheral Clock Bit in APB2ENR Register     */
                    CLR_BIT(RCC->APB2ENR,Copy_u8Peripheral);
                break;
                case CLK_SRC_ON:
                    /*      Enable Peripheral Clock Bit in APB2ENR Register      */
                    SET_BIT(RCC->APB2ENR,Copy_u8Peripheral);
                break;
            }
        break;
    }
}
/* __________________________________________________________________________________________________________ */
