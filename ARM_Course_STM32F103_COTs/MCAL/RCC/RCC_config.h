/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Config Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  									  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	RCC Driver                             							  	          */
/*  Project Description    :	RCC Driver for STM32F10x Family                             				  */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	RCC_config.h                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_
/*_______________________________________________________________________________________*/

/*		                        CLOCK READY TIMEOUT CONFIGURATION  			             */
/*---------------------------------------------------------------------------------------*/
#define CLK_READY_TIME_OUT              50000
/*_______________________________________________________________________________________*/


/*		                        HSI CLOCK FREQUENCY CONFIGURATION 			             */
/*---------------------------------------------------------------------------------------*/
#define HSI_CLK_F                       8000000UL
/*_______________________________________________________________________________________*/

/*		                        HSE CLOCK FREQUENCY CONFIGURATION 			             */
/*---------------------------------------------------------------------------------------*/
#define HSE_CLK_F                       16000000UL
/*_______________________________________________________________________________________*/

/*		                        PLL CLOCK MAXIMUM FREQUENCY CONFIGURATION 			     */
/*---------------------------------------------------------------------------------------*/
#define PLL_CLK_F_MAX                   72000000UL
/*_______________________________________________________________________________________*/

/*		                        SYSTEM CLOCK SOURCE CONFIGURATION 			             */
/*---------------------------------------------------------------------------------------*/
/*
    Options:
                RCC_CFGR_SW_HSI_SYSCLK
                RCC_CFGR_SW_HSE_SYSCLK
                RCC_CFGR_SW_PLL_SYSCLK
*/
#define SYSTEM_CLK_SOURCE               RCC_CFGR_SW_HSE_SYSCLK
/*_______________________________________________________________________________________*/

/*		                        PLL INPUT SOURCE CONFIGURATION 			                 */
/*---------------------------------------------------------------------------------------*/
/*
    Options:
                HSI_2_IN_PLL
                HSE_IN_PLL
                HSE_2_IN_PLL
*/
#define PLL_INPUT_SOURCE                HSI_2_IN_PLL
/*_______________________________________________________________________________________*/

/*		                        PLL MULTIPLICATION FACTOR CONFIGURATION 			     */
/*---------------------------------------------------------------------------------------*/
/*
    Options:
                RCC_CFGR_PLLMUL_INCLK_X2
                RCC_CFGR_PLLMUL_INCLK_X3
                RCC_CFGR_PLLMUL_INCLK_X4
                RCC_CFGR_PLLMUL_INCLK_X5
                RCC_CFGR_PLLMUL_INCLK_X6
                RCC_CFGR_PLLMUL_INCLK_X7
                RCC_CFGR_PLLMUL_INCLK_X8
                RCC_CFGR_PLLMUL_INCLK_X9
                RCC_CFGR_PLLMUL_INCLK_X10
                RCC_CFGR_PLLMUL_INCLK_X11
                RCC_CFGR_PLLMUL_INCLK_X12
                RCC_CFGR_PLLMUL_INCLK_X13
                RCC_CFGR_PLLMUL_INCLK_X14
                RCC_CFGR_PLLMUL_INCLK_X15
                RCC_CFGR_PLLMUL_INCLK_X16
*/
#define PLL_MULTIPLICATION_FACTOR       RCC_CFGR_PLLMUL_INCLK_X7
/*_______________________________________________________________________________________*/

/*		                        AHB BUS PRESCALER CONFIGURATION 			             */
/*---------------------------------------------------------------------------------------*/
/*
    Options:
                RCC_CFGR_HPRE_SYSCLK_DIV_1
                RCC_CFGR_HPRE_SYSCLK_DIV_2
                RCC_CFGR_HPRE_SYSCLK_DIV_4
                RCC_CFGR_HPRE_SYSCLK_DIV_8
                RCC_CFGR_HPRE_SYSCLK_DIV_16
                RCC_CFGR_HPRE_SYSCLK_DIV_64
                RCC_CFGR_HPRE_SYSCLK_DIV_128
                RCC_CFGR_HPRE_SYSCLK_DIV_256
                RCC_CFGR_HPRE_SYSCLK_DIV_512
*/
#define AHB_PRESCALER                   RCC_CFGR_HPRE_SYSCLK_DIV_1
/*_______________________________________________________________________________________*/

/*		                        APB1 BUS PRESCALER CONFIGURATION 			             */
/*---------------------------------------------------------------------------------------*/
/*
    Options:
                RCC_CFGR_PPRE1_HCLK_DIV_1
                RCC_CFGR_PPRE1_HCLK_DIV_2
                RCC_CFGR_PPRE1_HCLK_DIV_4
                RCC_CFGR_PPRE1_HCLK_DIV_8
                RCC_CFGR_PPRE1_HCLK_DIV_16
*/
#define APB1_PRESCALER                  RCC_CFGR_PPRE1_HCLK_DIV_2
/*_______________________________________________________________________________________*/

/*		                        APB2 BUS PRESCALER CONFIGURATION 			             */
/*---------------------------------------------------------------------------------------*/
/*
    Options:
                RCC_CFGR_PPRE2_HCLK_DIV_1
                RCC_CFGR_PPRE2_HCLK_DIV_2
                RCC_CFGR_PPRE2_HCLK_DIV_4
                RCC_CFGR_PPRE2_HCLK_DIV_8
                RCC_CFGR_PPRE2_HCLK_DIV_16
*/
#define APB2_PRESCALER                  RCC_CFGR_PPRE2_HCLK_DIV_1
/*_______________________________________________________________________________________*/

#endif /* RCC_CONFIG_H_ */
