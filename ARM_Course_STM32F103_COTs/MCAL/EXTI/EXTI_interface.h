/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  									  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	EXTI Driver                             							  	      */
/*  Project Description    :	EXTI Driver for STM32F10x Family                             				  */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	EXTI_interface.h                                    						  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Definitions       		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Global Declerations       		     		          	  	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

typedef enum
{
    EXTI0,
    EXTI1,
    EXTI2,
    EXTI3,
    EXTI4,
    EXTI5,
    EXTI6,
    EXTI7,
    EXTI8,
    EXTI9,
    EXTI10,
    EXTI11,
    EXTI12,
    EXTI13,
    EXTI14,
    EXTI15
}EXTI_Line;

typedef enum
{
    EXTI_RISING,
    EXTI_FAILING,
    EXTI_ON_CHANGE,
}EXTI_Trigger;

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Function Prototypes       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

void MEXTI_voidInit(void);
void MEXTI_voidEnableLine(EXTI_Line Copy_LineNumber);
void MEXTI_voidDisableLine(EXTI_Line Copy_LineNumber);
void MEXTI_voidSetLineTrigger(EXTI_Line Copy_LineNumber,EXTI_Trigger Copy_LineTrigger);
void MEXTI_voidSetSWTInterrupt(EXTI_Line Copy_LineNumber);
void MEXTI_voidClearSWInterrupt(EXTI_Line Copy_LineNumber);
void MEXTI_voidSetCallBack(EXTI_Line Copy_LineNumber,void(*Copy_pvFunction)(void));

#endif /* EXTI_INTERFACE_H_ */