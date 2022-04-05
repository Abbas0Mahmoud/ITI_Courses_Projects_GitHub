/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	RELAY Driver                             							  	      */
/*  Project Description    :	RELAY Driver                                                 				  */
/*  Target Controller 	   :	Atmega 32                                               					  */
/*  File Name              :	RELAY_program.c                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*		Library Inclusion			                                     */
#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATH.h"

/*		Lower Layer Inclusions		                                     */
#include "../../MCAL/DIO/DIO_interface.h"

/*		Self Layer Inclusions		                                     */

/*		Self Files Inclusions		                                     */
#include "RELAY_config.h"
#include "RELAY_interface.h"
#include "RELAY_private.h"

/*                                  Functions Implementations                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

void HRLY_voidInitRelayPin(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
    MDIO_voidSetPinDirection(Copy_u8PortName,Copy_u8PinNumber,OUTPUT);
    MDIO_voidSetPinValue(Copy_u8PortName,Copy_u8PinNumber,LOW);
}

void HRLY_voidTurnRelayOn(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
    MDIO_voidSetPinValue(Copy_u8PortName,Copy_u8PinNumber,HIGH);
}

void HRLY_voidTurnRelayOff(u8 Copy_u8PortName, u8 Copy_u8PinNumber )
{
    MDIO_voidSetPinValue(Copy_u8PortName,Copy_u8PinNumber,LOW);
}

/*                           H-Bridge Functions Implementations                             */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */
u8 Global_u8RelayPortName;
u8 Global_u8Rly1PinNumber;
u8 Global_u8Rly2PinNumber;

void HRLY_voidInitRelayHBridge(u8 Copy_u8PortName,u8 Copy_u8Rly1PinNumber,u8 Copy_u8Rly2PinNumber)
{
    Global_u8RelayPortName =  Copy_u8PortName;
    Global_u8Rly1PinNumber = Copy_u8Rly1PinNumber;
    Global_u8Rly2PinNumber = Copy_u8Rly2PinNumber;
    MDIO_voidSetPinDirection(Copy_u8PortName,Copy_u8Rly1PinNumber,OUTPUT);
    MDIO_voidSetPinValue(Copy_u8PortName,Copy_u8Rly1PinNumber,LOW);
    MDIO_voidSetPinDirection(Copy_u8PortName,Copy_u8Rly2PinNumber,OUTPUT);
    MDIO_voidSetPinValue(Copy_u8PortName,Copy_u8Rly2PinNumber,LOW);
}

void HRLY_voidSetRelayHBridgeForward(void)
{
    MDIO_voidSetPinValue(Global_u8RelayPortName,Global_u8Rly2PinNumber,LOW);
    MDIO_voidSetPinValue(Global_u8RelayPortName,Global_u8Rly1PinNumber,HIGH);
}

void HRLY_voidSeRelaytHBridgeBackward(void)
{
    MDIO_voidSetPinValue(Global_u8RelayPortName,Global_u8Rly1PinNumber,LOW);
    MDIO_voidSetPinValue(Global_u8RelayPortName,Global_u8Rly2PinNumber,HIGH);
}

void HRLY_voidSetRelayHBridgeBrake(void)
{
    MDIO_voidSetPinValue(Global_u8RelayPortName,Global_u8Rly1PinNumber,LOW);
    MDIO_voidSetPinValue(Global_u8RelayPortName,Global_u8Rly2PinNumber,LOW);
}