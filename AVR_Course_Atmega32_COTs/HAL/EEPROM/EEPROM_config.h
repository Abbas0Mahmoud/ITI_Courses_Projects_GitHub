/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	EEPROM Driver                             							  	      */
/*  Project Description    :	EEPROM Driver                                                 				  */
/*  Target Controller 	   :	Atmega 32                                               					  */
/*  File Name              :	EEPROM_config.h                                     						  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
/*---------------------------------------------------------------------------------------*/
#ifndef EEPROM_CONFIG_H
#define EEPROM_CONFIG_H
/*_______________________________________________________________________________________*/

/*
    OPTIONS:
                EEPROM_1K
                EEPROM_2K
                EEPROM_4K
                EEPROM_8K
                EEPROM_16K
*/
#define     EEPROM_SIZE             EEPROM_8K

/*
    OPTIONS:
                LOW
                HIGH
*/
#define 	A0_CONNECTION			LOW
#define 	A1_CONNECTION			LOW
#define 	A2_CONNECTION			LOW

#endif