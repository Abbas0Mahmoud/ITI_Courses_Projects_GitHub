/* ---------------------------------------------------------------------------------------------------------- */
/*                           	AdminMode Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	Clinic Management System                             					      */
/*  Project Description    :	                                                             			      */
/*  File Name              :	AdminMode.h                                    							      */
/*  Date                   :  	27 Dec, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
/*---------------------------------------------------------------------------------------*/
#ifndef ADMINMODE_H_
#define ADMINMODE_H_
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	AdminMode Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	AdminMode Definitions       		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	AdminMode Global Declerations       		     		          	  	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	AdminMode Function Prototypes       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------ */
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
/* ------------------------------------------------------------------------------------------------ */
/* ________________________________________________________________________________________________ */

/* ------------------------------------------------------------------------------------------------ */
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
/* ------------------------------------------------------------------------------------------------ */
void ClinicAdmin_voidInitAdminMode(void);
/* ________________________________________________________________________________________________ */

/* ------------------------------------------------------------------------------------------------ */
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
/* ------------------------------------------------------------------------------------------------ */
u8   ClinicAdmin_u8CheckAdminPassword(void);
/* ________________________________________________________________________________________________ */

/* ------------------------------------------------------------------------------------------------ */
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
/* ------------------------------------------------------------------------------------------------ */
void ClinicAdmin_voidPrintAdminOptionsMessage(void);
/* ________________________________________________________________________________________________ */

/* ------------------------------------------------------------------------------------------------ */
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
/* ------------------------------------------------------------------------------------------------ */
u8   ClinicAdmin_u8GetAdminOption(void);
/* ________________________________________________________________________________________________ */

/* ------------------------------------------------------------------------------------------------ */
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
/* ------------------------------------------------------------------------------------------------ */
void ClinicAdmin_voidSetBackWindowOption(void);
/* ________________________________________________________________________________________________ */

/* ------------------------------------------------------------------------------------------------ */
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
/* ------------------------------------------------------------------------------------------------ */
void ClinicAdmin_voidAddPatientRecord(void);
/* ________________________________________________________________________________________________ */

/* ------------------------------------------------------------------------------------------------ */
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
/* ------------------------------------------------------------------------------------------------ */
void ClinicAdmin_voidEditPatientRecord(void);
/* ________________________________________________________________________________________________ */

/* ------------------------------------------------------------------------------------------------ */
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
/* ------------------------------------------------------------------------------------------------ */
void ClinicAdmin_voidReserveSlotwithTheDoctor(void);
/* ________________________________________________________________________________________________ */

/* ------------------------------------------------------------------------------------------------ */
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
/* ------------------------------------------------------------------------------------------------ */
void ClinicAdmin_voidCancelReservation(void);
/* ________________________________________________________________________________________________ */

/* ------------------------------------------------------------------------------------------------ */
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
/* ------------------------------------------------------------------------------------------------ */
u8   ClinicAdmin_u8CheckPatientIDValue(u8 Local_u8PatientID);
/* ________________________________________________________________________________________________ */

/* ------------------------------------------------------------------------------------------------ */
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
/* ------------------------------------------------------------------------------------------------ */
u8   ClinicAdmin_u8CheckEmptySlot(void);
/* ________________________________________________________________________________________________ */

/* ------------------------------------------------------------------------------------------------ */
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
/* ------------------------------------------------------------------------------------------------ */
u8   ClinicAdmin_u8CheckReservationSlotsPatientID(u8 Local_u8PatientID);
/* ________________________________________________________________________________________________ */

#endif /* ADMINMODE_H_ */