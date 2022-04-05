/* * * * * * * * * * * * Header Log File * * * * * * * * * * *  * * * * * /
/*_______________________________________________________________________*/
/*  Author          :   Abbas Mahmoud                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*  Project Name    :   Atmega_32 - STEPPER MOTOR Driver                 */
/*  Controller Name :   Atmega_32                                        */
/*  File Name       :   STPM_config.h                                    */
/*  Date            :   18 DEC, 2021                                     */
/*  Layer           :   MCAL                                             */
/*  Version         :   V1.0                                             */
/*_______________________________________________________________________*/

/*                      Header Guard File                                */
#ifndef     STPM_CONFIG_H
#define 	STPM_CONFIG_H

/*          Stepper Motor Port/Pins Configuration                        */

#define     STPM_PORT                  PORTA

#define     STPM_BLUE_WIRE_PIN         PIN0
#define     STPM_PINK_WIRE_PIN         PIN1
#define     STPM_YELLOW_WIRE_PIN       PIN2
#define     STPM_ORANGE_WIRE_PIN       PIN3

#endif