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

/*          					Header Guard File                                        */
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */


/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Definitions       		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */

#define NONE_GROUP_PRIORITY         0
#define NONE_SUB_GROUP_PRIORITY     0

#define INT_GROUP_PRIORITY_0        0
#define INT_GROUP_PRIORITY_1        1
#define INT_GROUP_PRIORITY_2        2
#define INT_GROUP_PRIORITY_3        3
#define INT_GROUP_PRIORITY_4        4
#define INT_GROUP_PRIORITY_5        5
#define INT_GROUP_PRIORITY_6        6
#define INT_GROUP_PRIORITY_7        7
#define INT_GROUP_PRIORITY_8        8
#define INT_GROUP_PRIORITY_9        9
#define INT_GROUP_PRIORITY_10       10
#define INT_GROUP_PRIORITY_11       11
#define INT_GROUP_PRIORITY_12       12
#define INT_GROUP_PRIORITY_13       13
#define INT_GROUP_PRIORITY_14       14
#define INT_GROUP_PRIORITY_15       15

#define INT_SUB_GROUP_PRIORITY_0    0
#define INT_SUB_GROUP_PRIORITY_1    1
#define INT_SUB_GROUP_PRIORITY_2    2
#define INT_SUB_GROUP_PRIORITY_3    3
#define INT_SUB_GROUP_PRIORITY_4    4
#define INT_SUB_GROUP_PRIORITY_5    5
#define INT_SUB_GROUP_PRIORITY_6    6
#define INT_SUB_GROUP_PRIORITY_7    7
#define INT_SUB_GROUP_PRIORITY_8    8
#define INT_SUB_GROUP_PRIORITY_9    9
#define INT_SUB_GROUP_PRIORITY_10   10
#define INT_SUB_GROUP_PRIORITY_11   11
#define INT_SUB_GROUP_PRIORITY_12   12
#define INT_SUB_GROUP_PRIORITY_13   13
#define INT_SUB_GROUP_PRIORITY_14   14
#define INT_SUB_GROUP_PRIORITY_15   15

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Global Declerations       		     		          	  	  	  */
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
void NVIC_voidSetInterruptGroupSubPriority(u8 Copy_u8InterruptID,u8 Copy_InterruptGroupPriority,u8 Copy_u8InterruptSubPriority);
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
void MNVIC_voidGetInterruptPriority(u8 Copy_u8InterruptID,u8 * Copy_pu8InterruptGroupPriority,u8 * Copy_pu8InterruptSubPriority);
/*_________________________________________________________________________________________________*/


#endif /* NVIC_INTERFACE_H_ */