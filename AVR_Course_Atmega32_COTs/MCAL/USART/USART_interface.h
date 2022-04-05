/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	USART Driver                             							  	      */
/*  Project Description    :	USART Driver                                                 				  */
/*  Target Controller 	   :	Atmega 32                                               					  */
/*  File Name              :	USART_interface.h                                    						  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*          Header Guard File                                            */
#ifndef     USART_INTERFACE_H
#define 	USART_INTERFACE_H


/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

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
	Function Description        :	Pre Build Fcuntion To Initiate USART Peripheral
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
void MUSART_voidInit(void);
/*_______________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Post Build Fcuntion To Initiate USART Peripheral
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/

#define     USART_ASYNC_NORMAL_MODE           0
#define     USART_ASYNC_DOUBLE_SPEED_MODE     1
void MUSART_voidBeginUSARTAsync(u8 Copy_u8USARTMode,u32 Copy_u32BaudRateValue);
/*_______________________________________________________________________________________*/


/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Function to Transmit 1 Byte of Data
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/

void MUSART_voidTransmittDataSync(u8 Copy_u8Data);
/*_______________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Function to Set Cursor to New Line
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/

void MUSART_voidTransmitSetCursorToNewLine(void);
/*_______________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Function to Transmit String By Passing String Address
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/

void MUSART_voidTransmitStringSync(u8 * Copy_Pu8StringArray);
/*_______________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Function to Transmit String By Passing String Name
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/

void MUSART_voidTransmitStringByValueSync(u8 Copy_Pu8StringArray[]);
/*_______________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Function to Transmit Number By Passing Number Value
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/

void MUSART_voidTransmitNumberSync(u32 Copy_u32SendNumber);
/*_______________________________________________________________________________________*/


/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Function to Receive Data and Assign It To Passed Address
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/

void MUSART_voidReceiveDataSync(u8 * Copy_pu8ReceivedData);
/*_______________________________________________________________________________________*/


/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Function to Receive Data and Return It
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/

u8 MUSART_u8ReceiveDataSync(void);
/*_______________________________________________________________________________________*/


/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	unction To Receive String and Assing It To Passed String Address
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/

void MUSART_voidReceiveString1Sync(u8 * Copy_pu8ReceivedData);
/*_______________________________________________________________________________________*/


/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :	Function To Receive String and Assing It To Passed String Address
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/

void MUSART_voidReceiveString2Sync(u8 * Copy_pu8ReceivedData);
/*_______________________________________________________________________________________*/


#endif