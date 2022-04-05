/* * * * * * * * * * * * Header Log File * * * * * * * * * * *  * * * * * /
/*_______________________________________________________________________*/
/*  Author          :   Abbas Mahmoud                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*  Project Name    :   Atmega_32 - STEPPER MOTOR Driver                 */
/*  Controller Name :   Atmega_32                                        */
/*  File Name       :   STPM_private.h                                   */
/*  Date            :   18 DEC, 2021                                     */
/*  Layer           :   MCAL                                             */
/*  Version         :   V1.0                                             */
/*_______________________________________________________________________*/

/*                      Header Guard File                                */
#ifndef     STPM_PRIVATE_H
#define 	STPM_PRIVATE_H

/*          Stepper Motor Parameters                                     */
#define     FIELD_FREQUENCY                 100 
#define     FIELD_IGNITION_DELAY            (1/FIELD_FREQUENCY)
#define     STRIDE_ANGLE                    5.625
#define     SPEED_VARIATION_FACTOR          64
#define     HALF_STEP_ANGLE                 (STRIDE_ANGLE/SPEED_VARIATION_FACTOR)
#define     FULL_STEP_ANGLE                 (HALF_STEP_ANGLE*2)
#define     ONE_STEP_ANGLE                  FULL_STEP_ANGLE
#define     FULL_ROTATION_ANGLE             360
#define     FULL_ROTATION_STEPS             FULL_ROTATION_ANGLE/ONE_STEP_ANGLE
#define     LOOP_BLOCKS_DERATING_FACTOR     4
#define     FULL_ROTATION_STEPS_DERATED_1   (FULL_ROTATION_STEPS/LOOP_BLOCKS_DERATING_FACTOR)


#endif