/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	RELAY Driver                             							  	      */
/*  Project Description    :	RELAY Driver                                                 				  */
/*  Target Controller 	   :	Atmega 32                                               					  */
/*  File Name              :	RELAY_interface.h                                    						  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                      Header Guard File                                */
#ifndef     RELAY_INTERAFCE_H
#define 	RELAY_INTERFACE_H

void HRLY_voidInitRelayPin(u8 Copy_u8PortName, u8 Copy_u8PinNumber);

void HRLY_voidTurnRelayOn(u8 Copy_u8PortName, u8 Copy_u8PinNumber);

void HRLY_voidTurnRelayOff(u8 Copy_u8PortName, u8 Copy_u8PinNumber );

void HRLY_voidInitRelayHBridge(u8 Copy_u8PortName,u8 Copy_u8Rly1PinNumber,u8 Copy_u8Rly2PinNumber);

void HRLY_voidSetRelayHBridgeForward(void);

void HRLY_voidSeRelaytHBridgeBackward(void);

void HRLY_voidSetRelayHBridgeBrake(void);

#endif