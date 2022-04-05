/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	SrvFuncs Driver                             							  	  */
/*  Project Description    :	SrvFuncs Driver                                                 			  */
/*  Target Controller 	   :	                                                           					  */
/*  File Name              :	SrvFuncs_interface.h                                     					  */
/*  Layer           	   :	SRV                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
#ifndef     SRVFUNCS_INTERFACE_H
#define 	SRVFUNCS_INTERFACE_H

/* ---------------------------------------------------------------------------------------------------------- */
/*                           		        Interface Definitions       		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           		    Interface Function Definitions       		     		          	  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                                                Functions ProtoTypes                                       */

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
u8 * SplitNumberIntoDigits(u32 Copy_u32Number, u8 * Copy_pu8NumberinDigits);
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
u32 CombineDigitsIntoNumber(u8 * Copy_pu8NumberDigits,u8 Copy_u8NumberofDigits);
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
s32 _s32Map(s32 Copy_s32InputValueMin,s32 Copy_InputValueMax,s32 Copy_OutputValueMin,s32 Copy_s32OutputValueMax,s32 Copy_InputValue);
/*_______________________________________________________________________________________*/

# endif