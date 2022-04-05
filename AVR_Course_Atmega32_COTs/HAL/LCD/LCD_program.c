//* * * * * * * * * * * * Header Log File * * * * * * * * * * *  * * * * */
/*_______________________________________________________________________*/
/*  Author          :   Abbas Mahmoud                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*  Project Name    :   Atmega_32 LCD Driver                             */
/*  Controller Name :   Atmega_32                                        */
/*  File Name       :   LCD_program.c                                    */
/*  Date            :   18 DEC, 2021                                     */
/*  Layer           :   MCAL                                             */
/*  Version         :   V1.0                                             */
/*_______________________________________________________________________*/

/*		Library Inclusion			                                     */
#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATH.h"

#ifndef F_CPU
#define F_CPU 80000000UL
//#include <util/delay.h>
#endif


/*		Lower Layer Inclusions		                                     */
#include "../../MCAL/DIO/DIO_interface.h"

/*		Self Layer Inclusions		                                     */

/*		Self Files Inclusoins		                                     */
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

/*                                  Functions Implementations                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

void HLCD_voidInit(void)
{
    /*Set Data Port To Output Port*/
    MDIO_voidSetPortDirection(LCD_DATA_PORT, OUTPUT);
    /*Set Control Pins To Output Pins*/
    MDIO_voidSetPinDirection(LCD_CTRL_PORT,  LCD_EN_PIN, OUTPUT);
    MDIO_voidSetPinDirection(LCD_CTRL_PORT,  LCD_RW_PIN, OUTPUT);
    MDIO_voidSetPinDirection(LCD_CTRL_PORT,  LCD_RS_PIN, OUTPUT);
    /*Wait for more than 30msec*/
    _delay_ms(40);
    /*Send Function Set Command*/ /* N = 1 -> 2-Lines, F = 0 -> 5x7dots */
    HLCD_voidSendCommand(FUNCTION_SET_INSTRUCTION);
    /*Send Display ON/OFF Control Command*/
    HLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL_INSTRUCTION);
    /*Send Clear Display Command*/
    HLCD_voidSendCommand(CLEAR_DISPLAY_INSTRUCTION);

}

static void HLCD_voidSendCommand(u8 Copy_u8Command)
{
    /*Set RS Pin To Be Low*/
    MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, LOW);
    /*Set RW Pin To Be Low*/
    MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
    /*Set Command On The Data Port*/
    MDIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Command);
    /*Send High Pulse On The Enable Pin*/
    MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
    _delay_ms(2);
    MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
}

void HLCD_voidSendData(u8 Copy_u8Data)
{
    /*Set RS Pin To Be High*/
    MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, HIGH);
    /*Set RW Pin To Be Low*/
    MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
    /*Set Data On The Data Port*/
    MDIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Data);
    /*Send High Pulse On The Enable Pin*/
    MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
    _delay_ms(2);
    MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);

}

void HLCD_voidGoToXY(u8 Copy_u8XPosition, u8 Copy_u8YPosition)
{
    u8 Local_u8PositionAddress;
    /*Get The Position Address*/
    if(Copy_u8XPosition == 0)
    {
        Local_u8PositionAddress = Copy_u8YPosition;
    }
    else if(Copy_u8XPosition == 1)
    {
        Local_u8PositionAddress = Copy_u8YPosition + DDRAM_POSITION_FIXED_ADDRESS;
    }
    else
    {
        /*Return Error*/
        return;
    }
    /* Set The 7th Bit To Be 1*/
    SET_DDRAM_ADDRESS_INSTRUCTION(Local_u8PositionAddress);
    //SET_REG_BIT(Local_u8PositionAddress, 7);
    /* Send The Position Address Command (Set DDRAM Address) */
    HLCD_voidSendCommand(Local_u8PositionAddress);
}

void HLCD_voidClearDisplay(void)
{
    HLCD_voidSendCommand(CLEAR_DISPLAY_INSTRUCTION);
}

void HLCD_voidSendCustomPattern(u8 * Copy_pu8PatternArray,
                                u8 Copy_u8PatternNumber,
                                u8 Copy_u8XPosition,
                                u8 Copy_u8YPosition)
{
    u8 Local_u8CGRAMAddress;
    u8 Local_u8LoopCounter;
    /*Calculate The CGRAM Address = PatternNumber * 8*/
    Local_u8CGRAMAddress = Copy_u8PatternNumber * 8;
    SET_REG_BIT(Local_u8CGRAMAddress, 6);
    CLR_REG_BIT(Local_u8CGRAMAddress, 7);
    /* Send Set CGRAM Address Command */
    HLCD_voidSendCommand(Local_u8CGRAMAddress);
    /*Send The Data Array*/
    for(Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
    {
        /*Send Byte From The Data Array*/
        HLCD_voidSendData(Copy_pu8PatternArray[Local_u8LoopCounter]);
    }
    /*Send The Command To Set DDRAM Address*/
    HLCD_voidGoToXY(Copy_u8XPosition, Copy_u8YPosition);
    /*Display The Saved Pattern*/
    HLCD_voidSendData(Copy_u8PatternNumber);
}

void HLCD_voidSendString(u8 * Copy_Pu8StringArray)
{
	u8 Local_u8LoopCounter = 0;
	while(*(Copy_Pu8StringArray+Local_u8LoopCounter) != '\0')
	{
		HLCD_voidSendData(*(Copy_Pu8StringArray+Local_u8LoopCounter));
		Local_u8LoopCounter++;
	}
}

void HLCD_voidSendNumber(u32 Copy_u32SendNumber)
{
    if(Copy_u32SendNumber == 0)
    {
        HLCD_voidSendData((ZERO_ASCII_VALUE));
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
                HLCD_voidSendData((ZERO_ASCII_VALUE+Local_u8Reminder));
                /* updating mirrored number value */
                Local_Copy_u32SendNumber_Reversed = Local_Copy_u32SendNumber_Reversed / 10;
            }
            else
            {
                /* update digit counter */
                Local_u8DigitsCounter--;
                /* sending the extracted digit after converting it ASCII by adding ZERO equivalent ASCII hexadecimal value */
                HLCD_voidSendData((ZERO_ASCII_VALUE+Local_u8Reminder));
                /* updating mirrored number value */
                Local_Copy_u32SendNumber_Reversed = (Local_Copy_u32SendNumber_Reversed - Local_u8Reminder) / 10;
            }
        }
    }
}