/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                      		Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author         	 		:   Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	RCC Driver                             							  	          */
/*  Project Description    :	RCC Driver for STM32F10x Family                             				  */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	RCC_private.h                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
/*---------------------------------------------------------------------------------------*/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Registers Definitions       		     		          	  	              */
/* ---------------------------------------------------------------------------------------------------------- */

#define	RCC_BASE_ADDRESS			0x40021000
#define	RCC							((volatile RCC_t *) RCC_BASE_ADDRESS)

typedef struct
{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
}RCC_t;

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Registers' Bits and Mask Values Definition       		     		          */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Registers BITs Definition       		     		  						  */
/* ---------------------------------------------------------------------------------------------------------- */

/*		CR (CLOCK CONTROL REGISTER) REGISTER BITS				 				 		 */
/*---------------------------------------------------------------------------------------*/
#define	RCC_CR_HSION_BIT					0
#define	RCC_CR_HSIRDY_BIT					1
#define	RCC_CR_HSEON_BIT					16
#define	RCC_CR_HSERDY_BIT					17
#define	RCC_CR_HSEBYP_BIT					18
#define	RCC_CR_CSSON_BIT					19
#define	RCC_CR_PLLON_BIT					24
#define	RCC_CR_PLLRDY_BIT					25


/*		 CFGR (CLOCK CONFIGURATION REGISTER) REGISTER BITS	 			 				 */
/*---------------------------------------------------------------------------------------*/
#define RCC_CFGR_PLLSRC_BIT					16
#define RCC_CFGR_PLLXTPRE_BIT				17
#define RCC_CFGR_USBPRE_BIT					22


/*		AHBENR (AHB PERIPHERAL CLOCK ENABLE REGISTER) REGISTER BITS	 					 */
/*---------------------------------------------------------------------------------------*/
#define	RCC_AHBENR_DMA1EN_BIT				0
#define	RCC_AHBENR_DMA2EN_BIT				1
#define	RCC_AHBENR_SRAMEN_BIT				2
#define	RCC_AHBENR_FLITFEN_BIT				4
#define	RCC_AHBENR_CRCEN_BIT				5
#define	RCC_AHBENR_FSMCEN_BIT				8
#define	RCC_AHBENR_SDIOEN_BIT				10


/*		APB1ENR (APB1 PERIPHERAL CLOCK ENABLE REGISTER) REGISTER BITS	 				 */
/*---------------------------------------------------------------------------------------*/
#define RCC_APB1ENR_DACEN_BIT      			29
#define RCC_APB1ENR_PWREN_BIT      			28
#define RCC_APB1ENR_BKPEN_BIT      			27
#define RCC_APB1ENR_CAN2EN_BIT     			26
#define RCC_APB1ENR_CAN1EN_BIT     			25
#define RCC_APB1ENR_I2C2EN_BIT     			22
#define RCC_APB1ENR_I2C1EN_BIT     			21
#define RCC_APB1ENR_UART5EN_BIT    			20
#define RCC_APB1ENR_UART4EN_BIT    			19
#define RCC_APB1ENR_USART3EN_BIT   			18
#define RCC_APB1ENR_UART2EN_BIT    			17
#define RCC_APB1ENR_SPI3EN_BIT     			15
#define RCC_APB1ENR_SPI2EN_BIT     			14
#define RCC_APB1ENR_WWDGEN_BIT     			11
#define RCC_APB1ENR_TIM7EN_BIT     			5
#define RCC_APB1ENR_TIM6EN_BIT     			4
#define RCC_APB1ENR_TIM5EN_BIT     			3
#define RCC_APB1ENR_TIM4EN_BIT     			2
#define RCC_APB1ENR_TIM3EN_BIT     			1
#define RCC_APB1ENR_TIM2EN_BIT     			0


/*		APB2ENR (APB2 PERIPHERAL CLOCK ENABLE REGISTER) REGISTER BITS	 				 */
/*---------------------------------------------------------------------------------------*/
#define RCC_APB2ENR_AFIOEN_BIT     			0
#define RCC_APB2ENR_IOPA_BIT       			2
#define RCC_APB2ENR_IOPB_BIT       			3
#define RCC_APB2ENR_IOPC_BIT       			4
#define RCC_APB2ENR_IOPD_BIT       			5
#define RCC_APB2ENR_SPI1EN_BIT     			12
#define RCC_APB2ENR_USARTEN_BIT    			14

/*                              Registers Mask Values Definition       		     		  					  */
/* ---------------------------------------------------------------------------------------------------------- */

/*		CFGR (CLOCK CONFIGURATION REGISTER) MASKING VALUES	 							  */
/*---------------------------------------------------------------------------------------*/
#define RCC_CFGR_SW_BIT0					0
#define RCC_CFGR_SW_MASK					(~(3<<RCC_CFGR_SW_BIT0))

#define RCC_CFGR_BUSES_PRESCALER_MASK       (~(1023<<RCC_CFGR_HPRE_BIT0))

#define RCC_CFGR_HPRE_BIT0     				4
#define RCC_CFGR_HPRE_MASK					(~(15<<RCC_CFGR_HPRE_BIT0))

#define RCC_CFGR_PPRE1_BIT0					8
#define RCC_CFGR_PPRE1_MASK					(~(7<<RCC_CFGR_PPRE1_BIT0))

#define RCC_CFGR_PPRE2_BIT0    				11
#define RCC_CFGR_PPRE2_MASK					(~(7<<RCC_CFGR_PPRE2_BIT0))

#define RCC_CFGR_ADCPRE_BIT0				14
#define RCC_CFGR_ADCPRE_MASK				(~(3<<RCC_CFGR_ADCPRE_BIT0))

#define RCC_CFGR_PULLMUL_BIT0				18
#define RCC_CFGR_PLLMUL_MASK				(~(15<<RCC_CFGR_PULLMUL_BIT0))

#define RCC_CFGR_MCO_BIT0					24
#define RCC_CFGR_MCO_MASK					(~(7<<RCC_CFGR_MCO_BIT0))

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */


#define AHB_CLK_MAX_F			72000000UL
#define	APB1_CLK_MAX_F			36000000UL
#define	APB2_CLK_MAX_F			72000000UL

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Global Declarations       		     		          	  	  	      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Prototypes       		     		          	  		      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------------------------------------- */
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
/* ----------------------------------------------------------------------------------------------------------- */
static void MRCC_voidCheckBusesClockFrequency(u8 Copy_u8AHBPrescaler,u8 Copy_u8APB1Prescaler,u8 Copy_u8APB2Prescaler);



#endif /* RCC_PRIVATE_H_ */
