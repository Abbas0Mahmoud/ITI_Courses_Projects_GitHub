/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	SPI Driver                             							  	          */
/*  Project Description    :	SPI Driver                                                 				      */
/*  Target Controller 	   :	Atmega 32                                               					  */
/*  File Name              :	SPI_interface.h                                    						      */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
#ifndef     SPI_INTERFACE_H
#define 	SPI_INTERFACE_H

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
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
void MSPI_voidMasterInit(void);
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
void MSPI_voidSlaveInit(void);

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
#define     Fosc_4_CLK                  0
#define     Fosc_16_CLK                 1
#define     Fosc_64_CLK                 2
#define     Fosc_128_CLK                3
#define     Fosc_2_2x_CLK               4
#define     Fosc_8_2x_CLK               5
#define     Fosc_32_2x_CLK              6
#define     Fosc_64_2x_CLK              7

/*_______________________________________________________________________*/

void MSPI_voidSetSPISCKValue(u8 Copy_u8SerialClockValue);

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
u8   MSPI_u8TranceiveDataSync(u8 Copy_u8Data);

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
void MSPI_voidTranceiveDataAsync(u8 Copy_u8Data);

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
void MSPI_voidSetCallBack(void(*Copy_pvNotificationFunction)(void));

/*_______________________________________________________________________________________*/

#endif