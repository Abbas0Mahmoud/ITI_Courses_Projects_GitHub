/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	EXTI Driver                             							  	      */
/*  Project Description    :	EXTI Driver                                                 				  */
/*  Target Controller 	   :	Atmega 32                                               					  */
/*  File Name              :	EXTI_config.h                                     						      */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
/*---------------------------------------------------------------------------------------*/
#ifndef     EXTI_CONFIG_H
#define     EXTI_CONFIG_H
/*_______________________________________________________________________________________*/

/*          Interrupt Pins Enable / Disable Option Configuration                         */
/*_______________________________________________________________________________________*/
/*
    Options:
                ENABLE          DISABLE
*/

#define     EXTI_INT0_ENABLE            ENABLE
#define     EXTI_INT1_ENABLE            DISABLE
#define     EXTI_INT2_ENABLE            DISABLE

/*_______________________________________________________________________________________*/

/*          Interrupt Pins Sense Signal Type Configuration                               */
/*_______________________________________________________________________________________*/
/*
    Options:
            - FAILING_EDGE
            - RISING_EDGE
            - ON_CHANGE
            - LOW_LEVEL
*/

#define     EXTI_INT0_SENSE_SIGNAL      FAILING_EDGE
#define     EXTI_INT1_SENSE_SIGNAL      FAILING_EDGE
#define     EXTI_INT2_SENSE_SIGNAL      FAILING_EDGE

/*_______________________________________________________________________________________*/

#endif