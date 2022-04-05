/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Config Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	STK Driver                             							  	          */
/*  Project Description    :	STK Driver for STM32F10x Family                             			      */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	STK_config.h                                    						      */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
/*---------------------------------------------------------------------------------------*/
#ifndef STK_CONFIG_H_
#define STK_CONFIG_H_
/*_______________________________________________________________________________________*/

/*		                        System Timer Interrupt Enable Configuration  			 */
/*---------------------------------------------------------------------------------------*/
/*
    Options:
                ENABLE
                DISABLE
*/
#define STK_ENABLE_INTERRUPT    ENABLE
/*_______________________________________________________________________________________*/

/*                              System Timer Clock Source Configuration                  */
/*---------------------------------------------------------------------------------------*/
/*
    Options:
                CLK_AHB
                CLK_AHB_DIV_8
*/
#define STK_CLK_SOURCE          CLK_AHB_DIV_8
/*_______________________________________________________________________________________*/

#endif /* STK_CONFIG_H_ */
