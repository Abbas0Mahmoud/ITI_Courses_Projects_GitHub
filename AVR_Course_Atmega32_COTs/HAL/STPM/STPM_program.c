/* * * * * * * * * * * * Header Log File * * * * * * * * * * *  * * * * * /
/*_______________________________________________________________________*/
/*  Author          :   Abbas Mahmoud                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*  Project Name    :   Atmega_32- STEPPER MOTOR Driver                  */
/*  Controller Name :   Atmega_32                                        */
/*  File Name       :   STPM_program.c                                   */
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

/*		Self Files Inclusions		                                     */
#include "STPM_config.h"
#include "STPM_interface.h"
#include "STPM_private.h"

/*                                  Functions Implementations                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

void HSTPM_voidInitSTPM()
{
    /* SET PORT PINS DIRECTION AS OUTPUT */
    MDIO_voidSetPinDirection(STPM_PORT,STPM_BLUE_WIRE_PIN,OUTPUT);
    MDIO_voidSetPinDirection(STPM_PORT,STPM_PINK_WIRE_PIN,OUTPUT);
    MDIO_voidSetPinDirection(STPM_PORT,STPM_YELLOW_WIRE_PIN,OUTPUT);
    MDIO_voidSetPinDirection(STPM_PORT,STPM_ORANGE_WIRE_PIN,OUTPUT);

    /* SET PORT PINS AS HIGH IN INITIAL CONDITION AS ACTIVE CONDITION IS LOW WITH ULN2003 DRIVER */
    MDIO_voidSetPinValue(STPM_PORT,STPM_BLUE_WIRE_PIN,HIGH);
    MDIO_voidSetPinValue(STPM_PORT,STPM_PINK_WIRE_PIN,HIGH);
    MDIO_voidSetPinValue(STPM_PORT,STPM_YELLOW_WIRE_PIN,HIGH);
    MDIO_voidSetPinValue(STPM_PORT,STPM_ORANGE_WIRE_PIN,HIGH);
}

void HSTPM_voidSetDirectionAngle(u8 Copy_u8Direction,u16 Copy_u8Angle)
{
    u16 Local_u8LoopCounterSteps = 0;
    Local_u8LoopCounterSteps = (FULL_ROTATION_STEPS_DERATED_1*(Copy_u8Angle/FULL_ROTATION_ANGLE));
    u16 Local_u8AngleLoopCounter = 0;
    switch(Copy_u8Direction)
    {
        case STPM_CW:
            for(Local_u8AngleLoopCounter = 0; Local_u8LoopCounterSteps <= Local_u8LoopCounterSteps; Local_u8AngleLoopCounter++)
            {
                MDIO_voidSetPinValue(STPM_PORT,STPM_BLUE_WIRE_PIN,LOW);
                MDIO_voidSetPinValue(STPM_PORT,STPM_PINK_WIRE_PIN,HIGH);
                MDIO_voidSetPinValue(STPM_PORT,STPM_YELLOW_WIRE_PIN,HIGH);
                MDIO_voidSetPinValue(STPM_PORT,STPM_ORANGE_WIRE_PIN,HIGH);
                _delay_ms(FIELD_IGNITION_DELAY);
                MDIO_voidSetPinValue(STPM_PORT,STPM_BLUE_WIRE_PIN,HIGH);
                MDIO_voidSetPinValue(STPM_PORT,STPM_PINK_WIRE_PIN,LOW);
                MDIO_voidSetPinValue(STPM_PORT,STPM_YELLOW_WIRE_PIN,HIGH);
                MDIO_voidSetPinValue(STPM_PORT,STPM_ORANGE_WIRE_PIN,HIGH);
                _delay_ms(FIELD_IGNITION_DELAY);
                MDIO_voidSetPinValue(STPM_PORT,STPM_BLUE_WIRE_PIN,HIGH);
                MDIO_voidSetPinValue(STPM_PORT,STPM_PINK_WIRE_PIN,HIGH);
                MDIO_voidSetPinValue(STPM_PORT,STPM_YELLOW_WIRE_PIN,LOW);
                MDIO_voidSetPinValue(STPM_PORT,STPM_ORANGE_WIRE_PIN,HIGH);
                _delay_ms(FIELD_IGNITION_DELAY);
                MDIO_voidSetPinValue(STPM_PORT,STPM_BLUE_WIRE_PIN,HIGH);
                MDIO_voidSetPinValue(STPM_PORT,STPM_PINK_WIRE_PIN,HIGH);
                MDIO_voidSetPinValue(STPM_PORT,STPM_YELLOW_WIRE_PIN,HIGH);
                MDIO_voidSetPinValue(STPM_PORT,STPM_ORANGE_WIRE_PIN,LOW);
                _delay_ms(FIELD_IGNITION_DELAY);
            }
        break;
        case STPM_CCW:
            for(Local_u8AngleLoopCounter = 0; Local_u8LoopCounterSteps <= Local_u8LoopCounterSteps; Local_u8AngleLoopCounter++)
            {
                MDIO_voidSetPinValue(STPM_PORT,STPM_BLUE_WIRE_PIN,HIGH);
                MDIO_voidSetPinValue(STPM_PORT,STPM_PINK_WIRE_PIN,HIGH);
                MDIO_voidSetPinValue(STPM_PORT,STPM_YELLOW_WIRE_PIN,HIGH);
                MDIO_voidSetPinValue(STPM_PORT,STPM_ORANGE_WIRE_PIN,LOW);
                _delay_ms(FIELD_IGNITION_DELAY);
                MDIO_voidSetPinValue(STPM_PORT,STPM_BLUE_WIRE_PIN,HIGH);
                MDIO_voidSetPinValue(STPM_PORT,STPM_PINK_WIRE_PIN,HIGH);
                MDIO_voidSetPinValue(STPM_PORT,STPM_YELLOW_WIRE_PIN,LOW);
                MDIO_voidSetPinValue(STPM_PORT,STPM_ORANGE_WIRE_PIN,HIGH);
                _delay_ms(FIELD_IGNITION_DELAY);
                MDIO_voidSetPinValue(STPM_PORT,STPM_BLUE_WIRE_PIN,HIGH);
                MDIO_voidSetPinValue(STPM_PORT,STPM_PINK_WIRE_PIN,LOW);
                MDIO_voidSetPinValue(STPM_PORT,STPM_YELLOW_WIRE_PIN,HIGH);
                MDIO_voidSetPinValue(STPM_PORT,STPM_ORANGE_WIRE_PIN,HIGH);
                _delay_ms(FIELD_IGNITION_DELAY);
                MDIO_voidSetPinValue(STPM_PORT,STPM_BLUE_WIRE_PIN,LOW);
                MDIO_voidSetPinValue(STPM_PORT,STPM_PINK_WIRE_PIN,HIGH);
                MDIO_voidSetPinValue(STPM_PORT,STPM_YELLOW_WIRE_PIN,HIGH);
                MDIO_voidSetPinValue(STPM_PORT,STPM_ORANGE_WIRE_PIN,HIGH);
                _delay_ms(FIELD_IGNITION_DELAY);
            }
        break;
        /*      Error       */
    }
}