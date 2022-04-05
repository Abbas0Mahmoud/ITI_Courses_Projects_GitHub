/* * * * * * * * * * * * Header Log File * * * * * * * * * * *  * * * * * /
/*_______________________________________________________________________*/
/*  Author          :   Abbas Mahmoud                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*  Project Name    :   Atmega_32 - RELAY Driver                         */
/*  Controller Name :   Atmega_32                                        */
/*  File Name       :   RELAY_program.c                                  */
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
#include "OPTCPLR_config.h"
#include "OPTCPLR_interface.h"
#include "OPTCPLR_private.h"

/*                                  Functions Implementations                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

void HOPTCPLR_voidInitOPTCPLRPin(u8 Copy_u8PortName,u8 Copy_u8PinNumber)
{
    MDIO_voidSetPinDirection(Copy_u8PortName,Copy_u8PinNumber,OUTPUT);
    MDIO_voidSetPinValue(Copy_u8PortName,Copy_u8PinNumber,LOW);
}

void HOPTCPLR_voidTurnOPTCPLROn(u8 Copy_u8PortName,u8 Copy_u8PinNumber)
{
    MDIO_voidSetPinValue(Copy_u8PortName,Copy_u8PinNumber,HIGH);
}

void HOPTCPLR_voidTurnOPTCPLROff(u8 Copy_u8PortName,u8 Copy_u8PinNumber)
{
    MDIO_voidSetPinValue(Copy_u8PortName,Copy_u8PinNumber,LOW);
}