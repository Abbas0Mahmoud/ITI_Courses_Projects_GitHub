/* * * * * * * * * * * * Header Log File * * * * * * * * * * *  * * * * * /
/*_______________________________________________________________________*/
/*  Author          :   Abbas Mahmoud                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*  Project Name    :   Atmega_32- BJT Transistor Driver                 */
/*  Controller Name :   Atmega_32                                        */
/*  File Name       :   BJTT_interafce.h                                 */
/*  Date            :   18 DEC, 2021                                     */
/*  Layer           :   MCAL                                             */
/*  Version         :   V1.0                                             */
/*_______________________________________________________________________*/

/*          Header Guard File                                            */
#ifndef     BJTT_INTERFACE_H
#define 	BJTT_INTERFACE_H

/*                                  Functions ProtoTypes                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

void HBJTT_voidInitBJTNPNPin(u8 Copy_u8PortName,u8 Copy_u8PinNumber);

void HBJTT_voidTurnBJTNPNOn(u8 Copy_u8PortName, u8 Copy_PinNumber);

void HBJTT_voidTurnBJTNPNOff(u8 Copy_u8PortName, u8 Copy_PinNumber);

void HBJTT_voidInitBJTPNPPin(u8 Copy_u8PortName,u8 Copy_u8PinNumber);

void HBJTT_voidTurnBJTPNPOn(u8 Copy_u8PortName, u8 Copy_PinNumber);

void HBJTT_voidTurnBJTPNPOff(u8 Copy_u8PortName, u8 Copy_PinNumber);

void HBJTT_voidInitBJTNPNHBridge(u8 Copy_u8PortName,u8 Copy_u8T1PinNumber,u8 Copy_u8T2PinNumber,u8 Copy_u8T3PinNumber,u8 Copy_u8T4PinNumber);

void HBJTT_voidSetBJTTNPNHBridgeForward(void);

void HBJTT_voidSetBJTTNPNHBridgeBackward(void);

void HBJTT_voidSetBJTTNPNHbridgeBrake(void);

#endif