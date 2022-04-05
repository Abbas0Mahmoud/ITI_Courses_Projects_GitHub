/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	EXTI Driver                             							  	      */
/*  Project Description    :	EXTI Driver                                                 				  */
/*  Target Controller 	   :	Atmega 32                                               					  */
/*  File Name              :	EXTI_interface.h                                    						  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
/*---------------------------------------------------------------------------------------*/
#ifndef     EXTI_INTERFACE_H
#define     EXTI_INTERFACE_H
/*_______________________________________________________________________________________*/


/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Definitions       		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */

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
void MEXTI_voidInit(void);
/*_______________________________________________________________________________________*/

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

#define     ENABLE                  1
#define     DISABLE                 0

#define     INT0                    0
#define     INT1                    1
#define     INT2                    2

/*_____________________________________________________________________________*/

void MEXTI_voidInterruptControl(u8 Copy_u8InterruptID, u8 Copy_u8InterruptState);
/*_______________________________________________________________________________________*/

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

#define     FAILING_EDGE            0
#define     RISING_EDGE             1
#define     ON_CHANGE               2
#define     LOW_LEVEL               3

/*_______________________________________________________________________________________*/

void MEXTI_voidInterruptSenseSignal(u8 Copy_u8InterruptID, u8 Copy_u8SenseSignal);

/*_______________________________________________________________________________________*/

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

void MEXTI_voidSetINT0CallBack(void(*Copy_pvNotificationFunction)(void));
/*_______________________________________________________________________________________*/

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
void MEXTI_voidSetINT1CallBack(void(*Copy_pvNotificationFunction)(void));
/*_______________________________________________________________________________________*/

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
void MEXTI_voidSetINT2CallBack(void(*Copy_pvNotificationFunction)(void));
/*_______________________________________________________________________________________*/

#endif