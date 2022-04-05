/* * * * * * * * * * * * Header Log File * * * * * * * * * * *  * * * * * /
/*_______________________________________________________________________*/
/*  Author          :   Abbas Mahmoud                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*  Project Name    :   Atmega_32- BJT Transistor Driver                 */
/*  Controller Name :   Atmega_32                                        */
/*  File Name       :   BJTT_program.c                                   */
/*  Date            :   18 DEC, 2021                                     */
/*  Layer           :   MCAL                                             */
/*  Version         :   V1.0                                             */
/*_______________________________________________________________________*/

/*		Library Inclusion			                                     */
#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATH.h"

/*		Lower Layer Inclusions		                                     */
#include "../../MCAL/DIO/DIO_interface.h"

/*		Self Layer Inclusions		                                     */

/*		Self Files Inclusions		                                     */
#include "BJTT_config.h"
#include "BJTT_interface.h"
#include "BJTT_private.h"

/*                                  Functions Implementations                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

void HBJTT_voidInitBJTNPNPin(u8 Copy_u8PortName,u8 Copy_u8PinNumber)
{
    MDIO_voidSetPinDirection(Copy_u8PortName,Copy_u8PinNumber,OUTPUT);
    MDIO_voidSetPinValue(Copy_u8PortName,Copy_u8PinNumber,LOW);
}

void HBJTT_voidTurnBJTNPNOn(u8 Copy_u8PortName, u8 Copy_PinNumber)
{
    MDIO_voidSetPinValue(Copy_u8PortName,Copy_PinNumber,HIGH);
}

void HBJTT_voidTurnBJTNPNOff(u8 Copy_u8PortName, u8 Copy_PinNumber)
{
    MDIO_voidSetPinValue(Copy_u8PortName,Copy_PinNumber,LOW);
}

void HBJTT_voidInitBJTPNPPin(u8 Copy_u8PortName,u8 Copy_u8PinNumber)
{
    MDIO_voidSetPinDirection(Copy_u8PortName,Copy_u8PinNumber,OUTPUT);
    MDIO_voidSetPinValue(Copy_u8PortName,Copy_u8PinNumber,HIGH);
}

void HBJTT_voidTurnBJTPNPOn(u8 Copy_u8PortName, u8 Copy_PinNumber)
{
    MDIO_voidSetPinValue(Copy_u8PortName,Copy_PinNumber,LOW);
}

void HBJTT_voidTurnBJTPNPOff(u8 Copy_u8PortName, u8 Copy_PinNumber)
{
    MDIO_voidSetPinValue(Copy_u8PortName,Copy_PinNumber,HIGH);
}

/*                           H-Bridge Functions Implementations                             */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */
u8 Global_u8BJTTHBridgePortName;
u8 Global_u8BJTTHBridgeT1;
u8 Global_u8BJTTHBridgeT2;
u8 Global_u8BJTTHBridgeT3;
u8 Global_u8BJTTHBridgeT4;

void HBJTT_voidInitBJTNPNHBridge(u8 Copy_u8PortName,u8 Copy_u8T1PinNumber,u8 Copy_u8T2PinNumber,u8 Copy_u8T3PinNumber,u8 Copy_u8T4PinNumber)
{
    Global_u8BJTTHBridgePortName = Copy_u8PortName;
    Global_u8BJTTHBridgeT1 = Copy_u8T1PinNumber;
    Global_u8BJTTHBridgeT2 = Copy_u8T2PinNumber;
    Global_u8BJTTHBridgeT3 = Copy_u8T3PinNumber;
    Global_u8BJTTHBridgeT4 = Copy_u8T4PinNumber;

    MDIO_voidSetPinDirection(Copy_u8PortName,Copy_u8T1PinNumber,OUTPUT);
    MDIO_voidSetPinDirection(Copy_u8PortName,Copy_u8T2PinNumber,OUTPUT);
    MDIO_voidSetPinDirection(Copy_u8PortName,Copy_u8T3PinNumber,OUTPUT);
    MDIO_voidSetPinDirection(Copy_u8PortName,Copy_u8T4PinNumber,OUTPUT);

    MDIO_voidSetPinValue(Copy_u8PortName,Copy_u8T1PinNumber,LOW);
    MDIO_voidSetPinValue(Copy_u8PortName,Copy_u8T2PinNumber,LOW);
    MDIO_voidSetPinValue(Copy_u8PortName,Copy_u8T3PinNumber,LOW);
    MDIO_voidSetPinValue(Copy_u8PortName,Copy_u8T4PinNumber,LOW);
}

void HBJTT_voidSetBJTTNPNHBridgeForward(void)
{
    MDIO_voidSetPinValue(Global_u8BJTTHBridgePortName,Global_u8BJTTHBridgeT3,LOW);
    MDIO_voidSetPinValue(Global_u8BJTTHBridgePortName,Global_u8BJTTHBridgeT4,LOW);
    MDIO_voidSetPinValue(Global_u8BJTTHBridgePortName,Global_u8BJTTHBridgeT1,HIGH);
    MDIO_voidSetPinValue(Global_u8BJTTHBridgePortName,Global_u8BJTTHBridgeT2,HIGH);
}

void HBJTT_voidSetBJTTNPNHBridgeBackward(void)
{
    MDIO_voidSetPinValue(Global_u8BJTTHBridgePortName,Global_u8BJTTHBridgeT1,LOW);
    MDIO_voidSetPinValue(Global_u8BJTTHBridgePortName,Global_u8BJTTHBridgeT2,LOW);
    MDIO_voidSetPinValue(Global_u8BJTTHBridgePortName,Global_u8BJTTHBridgeT3,HIGH);
    MDIO_voidSetPinValue(Global_u8BJTTHBridgePortName,Global_u8BJTTHBridgeT4,HIGH);
}

void HBJTT_voidSetBJTTNPNHbridgeBrake(void)
{
    MDIO_voidSetPinValue(Global_u8BJTTHBridgePortName,Global_u8BJTTHBridgeT1,LOW);
    MDIO_voidSetPinValue(Global_u8BJTTHBridgePortName,Global_u8BJTTHBridgeT3,LOW);
    MDIO_voidSetPinValue(Global_u8BJTTHBridgePortName,Global_u8BJTTHBridgeT2,HIGH);
    MDIO_voidSetPinValue(Global_u8BJTTHBridgePortName,Global_u8BJTTHBridgeT4,HIGH);
}