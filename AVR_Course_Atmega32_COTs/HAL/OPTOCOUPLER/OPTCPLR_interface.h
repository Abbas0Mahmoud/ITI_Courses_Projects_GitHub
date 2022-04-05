/* * * * * * * * * * * * Header Log File * * * * * * * * * * *  * * * * * /
/*_______________________________________________________________________*/
/*  Author          :   Abbas Mahmoud                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*  Project Name    :   Atmega_32 - RELAY Driver                         */
/*  Controller Name :   Atmega_32                                        */
/*  File Name       :   RELAY_config.h                                   */
/*  Date            :   18 DEC, 2021                                     */
/*  Layer           :   MCAL                                             */
/*  Version         :   V1.0                                             */
/*_______________________________________________________________________*/

/*                      Header Guard File                                */
#ifndef     OPTCPLR_INTERFACE_H
#define 	OPTCPLR_INTERFACE_H

void HOPTCPLR_voidInitOPTCPLRPin(u8 Copy_u8PortName,u8 Copy_u8PinNumber);

void HOPTCPLR_voidTurnOPTCPLROn(u8 Copy_u8PortName,u8 Copy_u8PinNumber);

void HOPTCPLR_voidTurnOPTCPLROff(u8 Copy_u8PortName,u8 Copy_u8PinNumber);

#endif