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

/*		                        Self Files Inclusoins							         */
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Global Declerations       		     		          	  	  	      */
/* ---------------------------------------------------------------------------------------------------------- */

u8 MSPI_Global_u8TranceivedData = 0; // Variable to Store Transmitted/Received Data in Interrupt Handling Vector

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Function Prototypes       		     		          	  		      */
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
/* static to restrict the scope to this function */
/* Initialize it to NULL to Prevent Vector Handling Routine from Executing garbage code when nothing is passed to Vector Handling Routine */
static void (*Global_pvCallBackFunction)(void) = NULL; // Global Pointer to Function to Pass Function Name form CallBack Function to Vector Handling Routine

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
void MSPI_voidSetSPISCKValue(u8 Copy_u8SerialClockValue)
{
    switch(Copy_u8SerialClockValue)
    {
        case Fosc_4_CLK:
        SPCR &= SPCR_PRESCALER_MASKING;
        SPCR |= Copy_u8SerialClockValue;
        CLR_REG_BIT(SPSR,SPSR_SPI2X);
        break;
        case Fosc_16_CLK:
        SPCR &= SPCR_PRESCALER_MASKING;
        SPCR |= Copy_u8SerialClockValue;
        CLR_REG_BIT(SPSR,SPSR_SPI2X);
        break;
        case Fosc_64_CLK:
        SPCR &= SPCR_PRESCALER_MASKING;
        SPCR |= Copy_u8SerialClockValue;
        CLR_REG_BIT(SPSR,SPSR_SPI2X);
        break;
        case Fosc_128_CLK:
        SPCR &= SPCR_PRESCALER_MASKING;
        SPCR |= Copy_u8SerialClockValue;
        CLR_REG_BIT(SPSR,SPSR_SPI2X);
        break;
        case Fosc_2_2x_CLK:
        SPCR &= SPCR_PRESCALER_MASKING;
        SPCR |= Copy_u8SerialClockValue;
        SET_REG_BIT(SPSR,SPSR_SPI2X);
        break;
        case Fosc_8_2x_CLK:
        SPCR &= SPCR_PRESCALER_MASKING;
        SPCR |= Copy_u8SerialClockValue;
        SET_REG_BIT(SPSR,SPSR_SPI2X);
        break;
        case Fosc_32_2x_CLK:
        SPCR &= SPCR_PRESCALER_MASKING;
        SPCR |= Copy_u8SerialClockValue;
        SET_REG_BIT(SPSR,SPSR_SPI2X);
        break;
        case Fosc_64_2x_CLK:
        SPCR &= SPCR_PRESCALER_MASKING;
        SPCR |= Copy_u8SerialClockValue;
        SET_REG_BIT(SPSR,SPSR_SPI2X);
        break;
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
void MSPI_voidMasterInit(void)
{
    /* SPCR REGISTER */
    SET_REG_BIT(SPCR,SPCR_MSTR); // Set Master Bit to Initialize Controller as Master
    /* SPCR REGISTER */
    CLR_REG_BIT(SPCR,SPCR_DORD); // Clear Data Order Bit in SPCR to Start Transmitting with MSB Bit
    /* SPCR REGISTER */
    CLR_REG_BIT(SPCR,SPCR_CPOL); // Clear Clock Polarity Bit to Leading Edge as Rising Edge and Trailing Edge as Failing Edge
    /* SPCR REGISTER */
    SET_REG_BIT(SPCR,SPCR_CPHA); // Set Clock Phase Bit  to Setup at Leading Edge and Sample at Trailing Edge
    /* SPCR REGISTER */
    SET_REG_BIT(SPCR,SPCR_SPIE); // Set SPI Interrupt Enable Bit
    /* SPCR REGISTER */
    SET_REG_BIT(SPCR,SPCR_SPE); // Set SPI Enable Bit
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
void MSPI_voidSlaveInit(void)
{
    /* SPCR REGISTER */
    CLR_REG_BIT(SPCR,SPCR_MSTR); // Clear Master Bit to Initialize Controller as Slave
    /* SPCR REGISTER */
    CLR_REG_BIT(SPCR,SPCR_DORD); // Clear Data Order Bit in SPCR to Start Transmitting with MSB Bit
    /* SPCR REGISTER */
    CLR_REG_BIT(SPCR,SPCR_CPOL); // Clear Clock Polarity Bit to Leading Edge as Rising Edge and Trailing Edge as Failing Edge
    /* SPCR REGISTER */
    SET_REG_BIT(SPCR,SPCR_CPHA); // Set Clock Phase Bit  to Setup at Leading Edge and Sample at Trailing Edge
    /* SPCR REGISTER */
    SET_REG_BIT(SPCR,SPCR_SPE); // Set SPI Enable Bit
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
u8 MSPI_u8TranceiveDataSync(u8 Copy_u8Data)
{
    u8 Local_u8GetData; // Variable to Store Data that will be Transmitted
    u8 Local_u8GetSPSR; // variable to Read SPSR Register to Clear SPIF Flag after Polling
    CLR_REG_BIT(SPCR,SPCR_SPIE); // Clear SPIE Bit in SPCR Register to Disbale SPI Interrupt
    SPDR = Copy_u8Data; // Storing Data that will be Transmitted in SPDR Register
    while(GET_BIT(SPSR,SPSR_SPIF) == 0); // Polling until SPI Flag is Raised
    Local_u8GetSPSR = SPSR; // Reading SPSR Register to Clear SPIF Flag
    Local_u8GetData = SPDR; // Storing Received Data in SPDR
    return Local_u8GetData; // return Received  Data in SPDR
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
void MSPI_voidTranceiveDataAsync(u8 Copy_u8Data)
{
    SPDR = Copy_u8Data; // Set Data in SPDR to Be Transmitted
    SET_REG_BIT(SPCR,SPCR_SPIE); // Set SPI Interrupt Enable
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
void MSPI_voidSetCallBack(void(*Copy_pvNotificationFunction)(void)) // Function that Takes Function Name as Argument to Excute The Function When Interrupt Routine is Executed
{
    Global_pvCallBackFunction = Copy_pvNotificationFunction; // Assign Function Name that Passed to CallBack Function to Global Pointer to Function to Excute The Function in Vector Handling Routine
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
/* Creating Vector Handling Routine */
void __vector_12 (void) __attribute__((signal));
void __vector_12 (void)
{
    MSPI_Global_u8TranceivedData = SPDR; // Storing Received Data in SPDR
    if(Global_pvCallBackFunction != NULL) // Checking if any Function is Passed to Vector Handling Routine
    {
        Global_pvCallBackFunction(); // Execute The Passed Function to CallBack
    }
    else
    {
        /*Do Nothing*/
    }
    CLR_REG_BIT(SPCR,SPCR_SPIE); // Clear SPI Interrupt Enable to Receive The Next Interrupt Handling Routine
}