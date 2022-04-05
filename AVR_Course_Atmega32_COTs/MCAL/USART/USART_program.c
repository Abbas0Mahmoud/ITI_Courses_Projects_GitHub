/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	USART Driver                             							  	      */
/*  Project Description    :	USART Driver                                                 				  */
/*  Target Controller 	   :	Atmega 32                                               					  */
/*  File Name              :	USART_program.c                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/*		                Library Inclusions								       */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*_____________________________________________________________________________*/

/*		                HAL Layer Inclusion							           */

/*_____________________________________________________________________________*/

/*		                MCAL Layer Inclusion					               */

/*_____________________________________________________________________________*/


/*		                Self Files Inclusoins							       */
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"
/*_____________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Global Declerations       		     		          	  	  	      */
/* ---------------------------------------------------------------------------------------------------------- */

u8 Global_MUSART_u8ReceivedDataAsync = 0;

static void (*Global_pvCallBackFunctionReceive)(void) = NULL;

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Function Prototypes       		     		          	  		      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Function Implementations       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Pre Build Fcuntion To Initiate USART Peripheral
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
void MUSART_voidInit(void)
{
    /* ALL THE FOLLOWING SETTING UCSRB BITS USING FUNCTION */
    u8 Local_u8UCSRCTemp = 0; // used to assign register because it doesn't allow bit access
    SET_REG_BIT(UCSRB,UCSRB_TXEN);
    SET_REG_BIT(UCSRB,UCSRB_RXEN);

    SET_REG_BIT(Local_u8UCSRCTemp,UCSRC_UCSZ0);
    SET_REG_BIT(Local_u8UCSRCTemp,UCSRC_UCSZ1);
    SET_REG_BIT(UCSRB,UCSRB_UCSZ2);

    CLR_REG_BIT(Local_u8UCSRCTemp,UCSRC_USBS);

    CLR_REG_BIT(Local_u8UCSRCTemp,UCSRC_UPM0);
    CLR_REG_BIT(Local_u8UCSRCTemp,UCSRC_UPM1);

    CLR_REG_BIT(Local_u8UCSRCTemp,UCSRC_UMSEL);

    SET_REG_BIT(Local_u8UCSRCTemp,UCSRC_URSEL);

    UCSRC = Local_u8UCSRCTemp;
    /* SET BAUDRATE */
    UBRRL = 51;
    /* CLEAR THE FOLLIWING BIT TO ALLOW WRITING TO THE FOLLOWING REGISTER */
    CLR_REG_BIT(UBRRH,UBRRH_URSEL);
    UBRRH = 0;
}
/*_______________________________________________________________________________________*/

void MUSART_voidBeginUSARTAsync(u8 Copy_u8USARTMode,u32 Copy_u32BaudRateValue)
{
    /* variable to store UCSRC register value before assign it to register */
    u8  Local_u8UCSRCTemp  = 0;
    /* variabele to store UBRR register value */
    u16 Local_u16UBRRValue = 0;
    /* variable to store LSB of UBRR */
    u8  Local_u8UBRRLValue = 0;
    /* variable to store MSB of UBRR */
    u8  Local_u8UBRRHValue = 0;
    /* enable transmitter */
    SET_REG_BIT(UCSRB,UCSRB_TXEN);
    /* enable receiver */
    SET_REG_BIT(UCSRB,UCSRB_RXEN);
    /* set character size to 8 bit */
    SET_REG_BIT(Local_u8UCSRCTemp,UCSRC_UCSZ0);
    SET_REG_BIT(Local_u8UCSRCTemp,UCSRC_UCSZ1);
    CLR_REG_BIT(UCSRB,UCSRB_UCSZ2);
    /* set stop bit to 1 bit */
    CLR_REG_BIT(Local_u8UCSRCTemp,UCSRC_USBS);
    /* disable parity check */
    CLR_REG_BIT(Local_u8UCSRCTemp,UCSRC_UPM0);
    CLR_REG_BIT(Local_u8UCSRCTemp,UCSRC_UPM1);
    /* set mode to Asynchronous Operation */
    CLR_REG_BIT(Local_u8UCSRCTemp,UCSRC_UMSEL);
    /* set this bit to allow writing to UCSRC register */
    SET_REG_BIT(Local_u8UCSRCTemp,UCSRC_URSEL);
    /* setting UCSRC register */
    UCSRC = Local_u8UCSRCTemp;
    switch(Copy_u8USARTMode)
    {
        case USART_ASYNC_NORMAL_MODE:
            /* set normal speed mode */
            CLR_REG_BIT(UCSRA,UCSRA_U2X);
            /* setting baudrate */
            Local_u16UBRRValue = ((((F_OSC/16)/Copy_u32BaudRateValue)) - 1);
            /* checking UBRR value */
            if(Local_u16UBRRValue <= 255)
            {
                Local_u8UBRRLValue = Local_u16UBRRValue;
                UBRRL = Local_u8UBRRLValue;
                /* clear UBRRH_URSE to write to UBRRH */
                CLR_REG_BIT(UBRRH,UBRRH_URSEL);
                UBRRH = Local_u8UBRRHValue;
            }
            else
            {
                Local_u8UBRRLValue = 255;
                UBRRL = Local_u8UBRRLValue;
                Local_u8UBRRHValue = Local_u16UBRRValue - Local_u8UBRRLValue;
                /* clear UBRRH_URSE to write to UBRRH */
                CLR_REG_BIT(UBRRH,UBRRH_URSEL);
                UBRRH = Local_u8UBRRHValue;
            }
        break;
        case USART_ASYNC_DOUBLE_SPEED_MODE:
            /* set double speed mode */
            SET_REG_BIT(UCSRA,UCSRA_U2X);
            /* setting baudrate */
            Local_u16UBRRValue = ((((F_OSC/8)/Copy_u32BaudRateValue)) - 1);
            /* checking UBRR value */
            if(Local_u16UBRRValue <= 255)
            {
                Local_u8UBRRLValue = Local_u16UBRRValue;
                UBRRL = Local_u8UBRRLValue;
                /* clear UBRRH_URSE to write to UBRRH */
                CLR_REG_BIT(UBRRH,UBRRH_URSEL);
                UBRRH = Local_u8UBRRHValue;
            }
            else
            {
                Local_u8UBRRLValue = 255;
                UBRRL = Local_u8UBRRLValue;
                Local_u8UBRRHValue = Local_u16UBRRValue - Local_u8UBRRLValue;
                /* clear UBRRH_URSE to write to UBRRH */
                CLR_REG_BIT(UBRRH,UBRRH_URSEL);
                UBRRH = Local_u8UBRRHValue;
            }
        break;
    }
}
/*_______________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Function to Receive Data and Assign It To Passed Address
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
void MUSART_voidReceiveDataSync(u8 * Copy_pu8ReceivedData)
{
    /* polling until receive buffer is full */
    while(GET_BIT(UCSRA,UCSRA_RXC) == 0);
    /* get received data in UDR register */
    *Copy_pu8ReceivedData = UDR;
}
/*_______________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Function to Receive Data and Return It
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
u8 MUSART_u8ReceiveDataSync(void)
{
    /*      Disable Complete Receive Interrupt      */
    CLR_REG_BIT(UCSRB,UCSRB_RXCIE);
    /* polling until receive buffer is full */
    while(GET_BIT(UCSRA,UCSRA_RXC) == 0);
    /* get received data in UDR register */
    u8 Copy_pu8ReceivedData = UDR;
    return Copy_pu8ReceivedData;
}
/*_______________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	unction To Receive String and Assing It To Passed String Address
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
void MUSART_voidReceiveString1Sync(u8 * Copy_pu8ReceivedData)
{
    u8 Local_u8LoopCounter = 0;
    u8 Local_u8TempData;
    while(((Local_u8TempData = MUSART_u8ReceiveDataSync())  != '.'))
    {
        *(Copy_pu8ReceivedData + Local_u8LoopCounter) = Local_u8TempData;
        Local_u8LoopCounter++;
    }
    *(Copy_pu8ReceivedData + Local_u8LoopCounter) = '\0';
}
/*_______________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Function To Receive String and Assing It To Passed String Address
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
void MUSART_voidReceiveString2Sync(u8 * Copy_pu8ReceivedData)
{
    u8 Local_u8LoopCounter = 0;
    u8 Local_u8TempData;
    while((Local_u8TempData != '.'))
    {
        /* polling until receive buffer is full */
        while(GET_BIT(UCSRA,UCSRA_RXC) == 0);
        /* get received data in UDR register */
        Local_u8TempData = UDR;
        if(Local_u8TempData != '\0')
        {
            *(Copy_pu8ReceivedData + Local_u8LoopCounter) = Local_u8TempData;
            Local_u8LoopCounter++;
        }
    }
    *(Copy_pu8ReceivedData + (Local_u8LoopCounter-1)) = '\0';
}
/*_______________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Function To Receive 1 Byte Data Asynchronous (Interrupt)
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
void MUSART_voidReceiveDataAsync(void)
{
    /*      Enable Complete Receive Interrupt       */
    SET_REG_BIT(UCSRB,UCSRB_RXCIE);
}
/*_______________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Receive Data Interrupt CallBack Function
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
void MUSART_voidSetCallBackReceive(void(*Copy_pvNotificationFunction)(void))
{
    Global_pvCallBackFunctionReceive = Copy_pvNotificationFunction;
}
/*_______________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Interrupt Service Routine Function to Be Executed when
                                    Received Buffer Flag is Raised
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
void __vector_13 (void)     __attribute__((signal));
void __vector_13 (void)
{
    if(Global_pvCallBackFunctionReceive != NULL)
    {
        Global_MUSART_u8ReceivedDataAsync = UDR;
        Global_pvCallBackFunctionReceive();
        SET_REG_BIT(UCSRA,UCSRA_RXC);
    }
    else
    {
        /* Error */
    }
}
/*_______________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Function to Transmit 1 Byte of Data
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
void MUSART_voidTransmittDataSync(u8 Copy_u8Data)
{
    /*      Polling until Transmit Buffer is Ready to receive new data */
    while(GET_BIT(UCSRA,UCSRA_UDRE) == 0);
    /* set transmitted data to UDR register */
    UDR = Copy_u8Data;
    /* polling until transmitted data has been shifted out to the bus */
    while(GET_BIT(UCSRA,UCSRA_TXC) == 0);
}
/*_______________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Function to Set Cursor to New Line
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
void MUSART_voidTransmitSetCursorToNewLine(void)
{
    MUSART_voidTransmittDataSync('\n');
    MUSART_voidTransmittDataSync('\r');
}
/*_______________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Function to Transmit String By Passing String Address
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
void MUSART_voidTransmitStringSync(u8 * Copy_Pu8StringArray)
{
	u8 Local_u8LoopCounter = 0;
	while(*(Copy_Pu8StringArray+Local_u8LoopCounter) != '\0')
	{
		MUSART_voidTransmittDataSync(*(Copy_Pu8StringArray+Local_u8LoopCounter));
		Local_u8LoopCounter++;
	}
}
/*_______________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Function to Transmit String By Passing String Name
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
void MUSART_voidTransmitStringByValueSync(u8 Copy_Pu8StringArray[])
{
    u8 Local_u8LoopCounter = 0;
	while(*(Copy_Pu8StringArray+Local_u8LoopCounter) != '\0')
	{
		MUSART_voidTransmittDataSync(*(Copy_Pu8StringArray+Local_u8LoopCounter));
		Local_u8LoopCounter++;
	}
}
/*_______________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Function to Transmit Number By Passing Number Value
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
void MUSART_voidTransmitNumberSync(u32 Copy_u32SendNumber)
{
    if(Copy_u32SendNumber == 0)
    {
        MUSART_voidTransmittDataSync('0');
    }
    else
    {
        /* variable to store the reversed version of the input version of the given number */
        u32 Local_Copy_u32SendNumber_Reversed = 0;
        /* variable to store the reminder of the modulus operation */
        u8  Local_u8Reminder = 0;
        /* variabel to keep track of number of digits in the given number */
        u8	Local_u8DigitsCounter = 0;
        // Reversing Block
        /*looping through the digits of the given number until number = 0 */
        while(Copy_u32SendNumber != 0)
        {
            /* calculating the modulus reminder of the given number */
            Local_u8Reminder = Copy_u32SendNumber % 10;
            /* checking if the reminder = zero or not to determine the proper equations to apply to the given number */
            if(Local_u8Reminder== 0)
            {
                /* increment digit counter */
                Local_u8DigitsCounter++;
                /* update given number value after extracting a digit (digit is zero) from it */
                Copy_u32SendNumber = Copy_u32SendNumber / 10;
                /* updating the mirror of the given number with the extracted digit */
                Local_Copy_u32SendNumber_Reversed = Local_Copy_u32SendNumber_Reversed * 10;
            }
            else
            {
                /* increment digit counter */
                Local_u8DigitsCounter++;
                /* update given number value after extracting a digit (digit not zero) from it */
                Copy_u32SendNumber = (Copy_u32SendNumber - Local_u8Reminder)/10;
                /* updating the mirror of the given number with the extracted digit */
                Local_Copy_u32SendNumber_Reversed = Local_Copy_u32SendNumber_Reversed * 10 + Local_u8Reminder;
            }
        }
        /* digitcounter will be used as indicator to the numbers that will be sent as through mirroring, */
        /* if the first digit is zero in the given number, it will be stored as 10 in the mirror so      */
        /* as extra digit(1) will be added to mirrored version  so digitcounter keeps track of the given */
        /* number to eleminate(don't send it) extera 1 during sending data      */
        // Sending Data Block
        while(Local_u8DigitsCounter != 0)
        {
            /* calculating the reminder of the mirrored number */
            Local_u8Reminder = Local_Copy_u32SendNumber_Reversed % 10;
            /* checking if th reminder is zero or not (digit = 0 or != 0) */
            if(Local_u8Reminder == 0)
            {
                /* update digit counter */
                Local_u8DigitsCounter--;
                /* sending the extracted digit after converting it ASCII by adding ZERO equivalent ASCII hexadecimal value */
                MUSART_voidTransmittDataSync(Local_u8Reminder + '0');
                /* updating mirrored number value */
                Local_Copy_u32SendNumber_Reversed = Local_Copy_u32SendNumber_Reversed / 10;
            }
            else
            {
                /* update digit counter */
                Local_u8DigitsCounter--;
                /* sending the extracted digit after converting it ASCII by adding ZERO equivalent ASCII hexadecimal value */
                MUSART_voidTransmittDataSync(Local_u8Reminder + '0');
                /* updating mirrored number value */
                Local_Copy_u32SendNumber_Reversed = (Local_Copy_u32SendNumber_Reversed - Local_u8Reminder) / 10;
            }
        }
    }
}
/*_______________________________________________________________________________________*/