/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	ADC Driver                             							  	          */
/*  Project Description    :	ADC Driver                                                 				      */
/*  Target Controller 	   :	Atmega 32                                               					  */
/*  File Name              :	ADC_interface.h                                    						      */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
/*---------------------------------------------------------------------------------------*/
#ifndef     ADC_INTERFACE_H
#define 	ADC_INTERFACE_H
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Definitions       		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                          ADC Auto Trigger Source Options                           	 */
#define     FREE_RUNNING_MODE                   0
#define     ANALOG_COMPARATOR                   1
#define     EXTERNAL_INTERRUPT_REQUEST0         2
#define     TIMER_COUNTER0_COMPARE_MATCH        3
#define     TIMER_COUNTER0_OVERFLOW             4
#define     TIMER_COUNTER1_COMPARE_MATCH_B      5
#define     TIMER_COUNTER1_OVERFLOW             6
#define     TIMER_COUNTER1_CAPTURE_EVENT        7
/*_______________________________________________________________________________________*/

/*                          ADC Channel Options                                          */
#define     ADC_CHANNEL0                        0
#define     ADC_CHANNEL1                        1
#define     ADC_CHANNEL2                        2
#define     ADC_CHANNEL3                        3
#define     ADC_CHANNEL4                        4
#define     ADC_CHANNEL5                        5
#define     ADC_CHANNEL6                        6
#define     ADC_CHANNEL7                        7
/*_______________________________________________________________________________________*/

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

void MADC_voidInit(void);
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

u16 MADC_u16StartConversionSync(u8 Copy_u8ChannelNumber);
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

u8 MADC_u8StartConversionSync(u8 Copy_u8ChannelNumber);
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

void MADC_voidStartConversionAsync(u8 Copy_u8ChannelNumber);
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

void MADC_voidStartFreeRunningConversion(u8 Copy_u8StartChannel,u8 Copy_u8EndChannel);
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

void MADC_voidSetCallBack(void(*Copy_pvNotificationFunction)(void));
/*_______________________________________________________________________________________*/


#endif