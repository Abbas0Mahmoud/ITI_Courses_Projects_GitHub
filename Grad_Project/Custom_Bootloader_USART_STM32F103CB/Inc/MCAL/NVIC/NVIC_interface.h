/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                      		Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	GPIO Driver                             							  	      */
/*  Project Description    :	GPIO Driver for STM32F10x Family                             				  */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	GPIO_interface.h                                  							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
/*---------------------------------------------------------------------------------------*/
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Definitions       		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */

/*		Interrupt ID's Options		*/
#define	NVIC_INTID_WWDG							0
#define	NVIC_INTID_PVD							1
#define	NVIC_INTID_TAMPER						2
#define	NVIC_INTID_RTC							3
#define	NVIC_INTID_FLASH						4
#define	NVIC_INTID_RCC							5
#define	NVIC_INTID_EXTI0						6
#define	NVIC_INTID_EXTI1						7
#define	NVIC_INTID_EXTI2						8
#define	NVIC_INTID_EXTI3						9
#define	NVIC_INTID_EXTI4						10
#define	NVIC_INTID_DMA1_Channel1				11
#define	NVIC_INTID_DMA1_Channel2				12
#define	NVIC_INTID_DMA1_Channel3				13
#define NVIC_INTID_DMA1_Channel4				14
#define NVIC_INTID_DMA1_Channel5				15
#define NVIC_INTID_DMA1_Channel6				16
#define NVIC_INTID_DMA1_Channel7				17
#define NVIC_INTID_ADC1_2						18
#define NVIC_INTID_USB_HP_CAN_TX				19
#define NVIC_INTID_USB_LP_CAN_RX0				20
#define NVIC_INTID_CAN_RX1						21
#define NVIC_INTID_CAN_SCE						22
#define NVIC_INTID_EXTI9_5						23
#define NVIC_INTID_TIM1_BRK						24
#define NVIC_INTID_TIM1_UP						25
#define NVIC_INTID_TIM1_TRG_COM					26
#define NVIC_INTID_TIM1_CC						27
#define NVIC_INTID_TIM2							28
#define NVIC_INTID_TIM3							29
#define NVIC_INTID_TIM4							30
#define NVIC_INTID_I2C1_EV						31
#define NVIC_INTID_I2C1_ER						32
#define NVIC_INTID_I2C2_EV						33
#define NVIC_INTID_I2C2_ER						34
#define NVIC_INTID_SPI1							35
#define NVIC_INTID_SPI2							36
#define NVIC_INTID_USART1						37
#define NVIC_INTID_USART2						38
#define NVIC_INTID_USART3						39
#define NVIC_INTID_EXTI15_10					40
#define NVIC_INTID_RTCAlarm						41
#define NVIC_INTID_USBWakeup					42
#define NVIC_INTID_TIM8_BRK						43
#define NVIC_INTID_TIM8_UP						44
#define NVIC_INTID_TIM8_TRG_COM					45
#define NVIC_INTID_TIM8_CC						46
#define NVIC_INTID_ADC3							47
#define NVIC_INTID_FSMC							48
#define NVIC_INTID_SDIO							49
#define NVIC_INTID_TIM5							50
#define NVIC_INTID_SPI3							51
#define NVIC_INTID_UART4						52
#define NVIC_INTID_UART5						53
#define NVIC_INTID_TIM6							54
#define NVIC_INTID_TIM7							55
#define NVIC_INTID_DMA2_Channel1				56
#define NVIC_INTID_DMA2_Channel2				57
#define NVIC_INTID_DMA2_Channel3				58
#define NVIC_INTID_DMA2_Channel4_5				59
/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Global Declarations       		     		          	  	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Function Prototypes       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
void MNVIC_voidSetInterruptEnable(u8 Copy_u8InterruptID);
/*_________________________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
void MNVIC_voidClearInterruptEnable(u8 Copy_u8InterruptID);
/*_________________________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
void MNVIC_voidSetInterruptPendingFlag(u8 Copy_u8InterruptID);
/*_________________________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
void MNVIC_voidClearAllinterruptPendingFlags(void);
/*_________________________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
void MNVIC_voidClearInterruptPendingFlag(u8 Copy_u8InterruptID);
/*_________________________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
u8 MNVIC_u8GetInterruptPendingFlag(u8 Copy_u8InterruptID);
/*_________________________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
u8 MNVIC_u8GetInterruptActiveBit(u8 Copy_u8InterruptID);
/*_________________________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________
*/
void MNVIC_voidSetInterruptPriority(u8 Copy_u8InterruptID,u8 Copy_u8InterruptPriority);
/*_________________________________________________________________________________________________*/

#endif /* NVIC_INTERFACE_H_ */
