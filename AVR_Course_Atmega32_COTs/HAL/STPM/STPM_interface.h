/* * * * * * * * * * * * Header Log File * * * * * * * * * * *  * * * * * /
/*_______________________________________________________________________*/
/*  Author          :   Abbas Mahmoud                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*  Project Name    :   Atmega_32 - STEPPER MOTOR Driver                 */
/*  Controller Name :   Atmega_32                                        */
/*  File Name       :   STPM_interface.h                                 */
/*  Date            :   18 DEC, 2021                                     */
/*  Layer           :   MCAL                                             */
/*  Version         :   V1.0                                             */
/*_______________________________________________________________________*/

/*                      Header Guard File                                */
#ifndef     STPM_INTERFACE_H
#define 	STPM_INERFACE_H

/*          DIRECTION COMMADS                                            */
#define     STPM_CW     0
#define     STPM_CCW    1

/*                                  Functions ProtoTypes                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

void HSTPM_voidInitSTPM();

void HSTPM_voidSetDirectionAngle(u8 Copy_u8Direction,u16 Copy_u8Angle);

#endif