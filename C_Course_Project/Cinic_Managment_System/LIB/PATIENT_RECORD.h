/* ---------------------------------------------------------------------------------------------------------- */
/*                           	PatientRecord Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	Clinic Management System                             					      */
/*  Project Description    :	                                                             			      */
/*  File Name              :	PatientRecord.h                                    							      */
/*  Date                   :  	27 Dec, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
/*---------------------------------------------------------------------------------------*/
#ifndef PATIENT_RECORD_H_
#define PATIENT_RECORD_H_
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	PatientRecord Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */
#include "STD_TYPES.h"
/* ---------------------------------------------------------------------------------------------------------- */
/*                           	PatientRecord Definitions       		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */

/* struct datatype to store patient profile data */
typedef struct
{
    u8 Patient_Name[255];                               // array of characters to store patient name
    u8 Patient_Age;                                     // variable to store patient age
    u8 Patient_Gender[12];                              // array of characters to store patient gender
    u8 Patient_ID;                                      // variable to store patient id
    PatientNode * PointerToTheNextPatientNode;   // pointer to struct to point to the address of the next node
}PatientNode;

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	PatientRecord Global Declerations       		     		          	  	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

PatientNode * Global_pstructHeaPointer = NULL;   // pointer to struct to point to the address of the first node
PatientNode * Global_pstructHoldNodeAddress = NULL;  // pointer to stuct to hold the address of any required node from any function

/* 2d array to store reservation slots status and patient id */
u8 Global_u8ReservationSlotsStatusID[5][2]={{'E',0},
                                            {'E',0},
                                            {'E',0},
                                            {'E',0},
                                            {'E',0}};
u8 Global_u8ReservationSlotsStatusIDRowsIndex = 5;  // 2d array row index
u8 Global_u8u8ReservationSlotsStatusIDColumnsIndex = 2; // 2d array column index
u8 Global_u8ReservationSlotStatusIndex = 0; // 2d array slot status element index
u8 Global_u8ReservationSlotIDIndex = 1; // 2d array slot id element index

#endif /* PATIENT_RECORD_H_ */