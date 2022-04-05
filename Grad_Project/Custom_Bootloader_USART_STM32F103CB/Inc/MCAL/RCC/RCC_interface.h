/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                  :   Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	RCC Driver                             							  	          */
/*  Project Description    :	RCC Driver for STM32F10x Family                             				  */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	RCC_interface.h                                    						      */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
/*---------------------------------------------------------------------------------------*/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Preprocessor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Definitions       		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */

/*		                        SYSTEM CLOCK OPTIONS 			                         */
#define RCC_CFGR_SW_HSI_SYSCLK				0
#define RCC_CFGR_SW_HSE_SYSCLK				1
#define RCC_CFGR_SW_PLL_SYSCLK      		2

/*                              CLOCK SOURCE STATUS OPTIONS                              */
#define CLK_SRC_ON                          1
#define CLK_SRC_OFF                         0

/*                              CLOCK SOURCE READY CHECK OPTIONS                         */
#define HSI_CLK_RDY                         0
#define HSE_CLK_RDY                         1
#define PLL_CLK_RDY                         2

/*                              CLOCK SOURCE READY STATUS OPTIONS                        */
#define CLK_READY                           1
#define CLK_NOT_READY                       0

/*                              PLL INPUT CLOCK SOURCE OPTIONS                           */
#define HSI_2_IN_PLL                        0
#define HSE_IN_PLL                          1
#define HSE_2_IN_PLL                        2

/*		                        PLL INPUT CLOCK SOURCE MULTIPLICATION FACTOR OPTIONS 	 */
#define RCC_CFGR_PLLMUL_INCLK_X2			0
#define RCC_CFGR_PLLMUL_INCLK_X3			1
#define RCC_CFGR_PLLMUL_INCLK_X4			2
#define RCC_CFGR_PLLMUL_INCLK_X5			3
#define RCC_CFGR_PLLMUL_INCLK_X6			4
#define RCC_CFGR_PLLMUL_INCLK_X7			5
#define RCC_CFGR_PLLMUL_INCLK_X8			6
#define RCC_CFGR_PLLMUL_INCLK_X9			7
#define RCC_CFGR_PLLMUL_INCLK_X10			8
#define RCC_CFGR_PLLMUL_INCLK_X11			9
#define RCC_CFGR_PLLMUL_INCLK_X12			10
#define RCC_CFGR_PLLMUL_INCLK_X13			11
#define RCC_CFGR_PLLMUL_INCLK_X14			12
#define RCC_CFGR_PLLMUL_INCLK_X15			13
#define RCC_CFGR_PLLMUL_INCLK_X16			14

/*		                        MAIN CLOCK OUTPUT OPTIONS 			                     */
#define RCC_CFGR_MCO_NOCLK					3
#define RCC_CFGR_MCO_SYSCLK					4
#define RCC_CFGR_MCO_HSICLK					5
#define RCC_CFGR_MCO_HSECLK					6
#define RCC_CFGR_MCO_PLLCLK_DIV_2			7

/*                              BUS NAME OPTIONS                                         */
#define AHB_BUS                             0
#define APB1_BUS                            1
#define APB2_BUS                            2

/*		                        AHB BUS PRESCALER OPTIONS 			                     */
#define RCC_CFGR_HPRE_SYSCLK_DIV_1			7
#define RCC_CFGR_HPRE_SYSCLK_DIV_2			8
#define RCC_CFGR_HPRE_SYSCLK_DIV_4			9
#define RCC_CFGR_HPRE_SYSCLK_DIV_8			10
#define RCC_CFGR_HPRE_SYSCLK_DIV_16			11
#define RCC_CFGR_HPRE_SYSCLK_DIV_64			12
#define RCC_CFGR_HPRE_SYSCLK_DIV_128		13
#define RCC_CFGR_HPRE_SYSCLK_DIV_256		14
#define RCC_CFGR_HPRE_SYSCLK_DIV_512		15

/*		                        APB1 BUS PRESCALER OPTIONS 			                     */
#define RCC_CFGR_PPRE1_HCLK_DIV_1			3
#define RCC_CFGR_PPRE1_HCLK_DIV_2			4
#define RCC_CFGR_PPRE1_HCLK_DIV_4			5
#define RCC_CFGR_PPRE1_HCLK_DIV_8			6
#define RCC_CFGR_PPRE1_HCLK_DIV_16			7

/*		                        APB2 BUS PRESCALER OPTIONS 			                     */
#define RCC_CFGR_PPRE2_HCLK_DIV_1			3
#define RCC_CFGR_PPRE2_HCLK_DIV_2			4
#define RCC_CFGR_PPRE2_HCLK_DIV_4   		5
#define RCC_CFGR_PPRE2_HCLK_DIV_8			6
#define RCC_CFGR_PPRE2_HCLK_DIV_16			7

/*		                        ADC PRESCALER OPTIONS 			                         */
#define RCC_CFGR_ADCPRE_PCLK2_DIV_2			0
#define RCC_CFGR_ADCPRE_PCLK2_DIV_4			1
#define RCC_CFGR_ADCPRE_PCLK2_DIV_6			2
#define RCC_CFGR_ADCPRE_PCLK2_DIV_8			3


/*		                        AHB BUS PERIPHERALS CLOCK ENABLE OPTIONS 				 */
#define ETHMACRXEN                          16
#define ETHMACTXEN                          15
#define ETHMACEN                            14
#define OTGFSEN                             12
#define CRCEN                               6
#define FLITFEN                             4
#define SRAMEN                              2
#define DMA2EN                              1
#define DMA1EN                              0

/*		                        APB1 BUS PERIPHERALS CLOCK ENABLE OPTIONS 			     */
#define DACEN                               29
#define PWREN                               28
#define BKPEN                               27
#define CAN2EN                              26
#define CAN1EN                              25
#define I2C2EN                              22
#define I2C1EN                              21
#define UART5EN                             20
#define UART4EN                             19
#define USART3EN                            18
#define UART2EN                             17
#define SPI3EN                              15
#define SPI2EN                              14
#define WWDGEN                              11
#define TIM7EN                              5
#define TIM6EN                              4
#define TIM5EN                              3
#define TIM4EN                              2
#define TIM3EN                              1
#define TIM2EN                              0

/*		                        APB2 BUS PERIPHERALS CLOCK ENABLE OPTIONS 			     */
#define AFIOEN                              0
#define IOPA                                2
#define IOPB                                3
#define IOPC                                4
#define IOPD                                5
#define SPI1EN                              12
#define USARTEN                             14


/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Global Declarations       		     		          	  	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

struct SysClks
{
	u32 SysClk_F;
	u32 AHBClk_F;
	u32 APB1Clk_F;
	u32 APB2Clk_F;
}RCC_Clks;

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Function Prototypes       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
    _____________________________
	Function Parameters Options :
	_____________________________
*/
/* ---------------------------------------------------------------------------------------------------------- */
void MRCC_voidInit(void);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
    _____________________________
	Function Parameters Options :
	_____________________________
*/
/* ---------------------------------------------------------------------------------------------------------- */
void MRCC_voidSelectClkSource(u8 Copy_u8ClkSource);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
    _____________________________
	Function Parameters Options :
	_____________________________
*/
/* ---------------------------------------------------------------------------------------------------------- */
void MRCC_voidSetClkSourceStatus(u8 Copy_u8ClkSource,u8 Copy_u8ClkSourceStatus);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
    _____________________________
	Function Parameters Options :
	_____________________________
*/
/* ---------------------------------------------------------------------------------------------------------- */
u8   MRCC_u8CheckCLKSourceReady(u8 Copy_u8CheckClkSource);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
    _____________________________
	Function Parameters Options :
	_____________________________
*/
/* ---------------------------------------------------------------------------------------------------------- */
void MRCC_voidSetPLLConfiguration(u8 Copy_u8PLLInputSource,u8 Copy_u8PLLMulFactor);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
    _____________________________
	Function Parameters Options :
	_____________________________
*/
/* ---------------------------------------------------------------------------------------------------------- */
void MRCC_voidSetBusesPrescalers(u8 Copy_u8AHBPrescaler,u8 Copy_u8APB1Prescaler,u8 Copy_u8APB2Prescaler);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
    _____________________________
	Function Parameters Options :
	_____________________________
*/
/* ---------------------------------------------------------------------------------------------------------- */
void MRCC_voidSetBusPrescaler(u8 Copy_u8BusName,u8 Copy_BusPrescaler);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
    _____________________________
	Function Parameters Options :
	_____________________________
*/
/* ---------------------------------------------------------------------------------------------------------- */
void MRCC_voidSetPeripheralClkStatus(u8 Copy_u8BusName,u8 Copy_u8Peripheral,u8 Copy_u8ClkStatus);
/*____________________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :
    _____________________________
	Function Parameters Options :
	_____________________________
*/
/* ---------------------------------------------------------------------------------------------------------- */
void MRCC_voidResetPeripheral(u8 Copy_u8BusName,u8 Copy_u8Peripheral);
/*____________________________________________________________________________________________________________*/

#endif /* RCC_INTERFACE_H_ */
