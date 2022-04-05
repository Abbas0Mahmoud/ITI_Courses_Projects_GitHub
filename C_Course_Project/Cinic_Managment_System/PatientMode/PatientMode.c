/* ---------------------------------------------------------------------------------------------------------- */
/*                           	PatientMode Program Documentation        		     		          	  	  	  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	Clinic Management System                             					      */
/*  Project Description    :	                                                             			      */
/*  File Name              :	PatientMode.c                                    							      */
/*  Date                   :  	27 Dec, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	PatientMode Program Preprocessor Directives        		     		          */
/* ---------------------------------------------------------------------------------------------------------- */

/*		                        Library Inclusions								         */
#include "../LIB/STD_TYPES.h"
#include "../LIB/PATIENT_RECORD.h"
/*_______________________________________________________________________________________*/

/*		                        Self Files Inclusions							         */
#include "PatientMode/PatientMode.h"
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	PatientMode Program Definitions       		     		          	  	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	PatientMode Program Global Decelerations       		     		          	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	PatientMode Program Function Prototypes       		     		          	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	PatientMode Program Function Implementations       		     		          */
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
void ClinicPatient_voidInitPatientMode(void)
{
    printf("\n/*____________________________________________________________*/\n\n");
    ClinicPatient_voidPrintPatientOptionsMessage(); // function: printing options message to patient in patient options window
    switch(ClinicPatient_u8GetPatientOption())
    {
        case 1:
            ClinicPatient_voidViewPatientRecord(); // function : view patient record tab
        break;
        case 2:
            ClinicPatient_voidViewTodayReservations(); // function : view today reservation tab
        break;
        default:
        break;
    }
}
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
void ClinicPatient_voidPrintPatientOptionsMessage(void)
{
    printf("\n/* * * * * * * * * * * * * Patient Options Menu Window * * * * * * * * * * * * */\n");
    printf("/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */\n\n");
    printf("Select One Of The Following Options :\n");
    printf("_____________________________________\n");
    printf("1- View Patient Record\n");
    printf("2- View Today Reservations\n");
    printf("\n/*____________________________________________________________*/\n\n");
}
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
u8 ClinicPatient_u8GetPatientOption(void)
{
    printf("/* * * * * * * * * Patient Option Selection Tab * * * * * * * */\n");
    printf("/*____________________________________________________________*/\n\n");
    u8 Local_OptionIndex; // variable to store patient selected option index
    printf("Enter Option Index : "); // asking the user to input option index
    scanf("%d",&Local_OptionIndex); // getting selected option index from the user
    printf("\n/*____________________________________________________________*/\n");
    return Local_OptionIndex; // return patient selected option index
}
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
/* view patient record option fuction implementation */
void ClinicPatient_voidViewPatientRecord(void)
{
    printf("\n/* * * * * * * * * View Patient Record Tab * * * * * * * * * */\n");
    printf("/*____________________________________________________________*/\n\n");
    u8 Local_u8PatientID = 0; // variable to store patient id
    printf("Enter Patient ID: "); // asking the patient to enter id
    scanf("%d",&Local_u8PatientID); // getting patient id
    printf("\n/*____________________________________________________________*/\n\n");
    u8 Local_u8IDSearchFlag = LinkedList_u8SearchNodeID(Local_u8PatientID); // checking if there patient profile with this id and update status flag
    if(Local_u8IDSearchFlag == 1) // checking if status flag is true - there is patient profile with this id
    {
        /* Global_pstructHoldNodeAddress now holds the patient profile id form LinkedList_u8SearchNodeID() function */
        LinkedList_voidPrintNodeData(Global_pstructHoldNodeAddress); // printing patient profile data by passing patient profile address
        /* printing patient reservation if existed */
        if(Global_u8ReservationSlotsStatusID[0][Global_u8ReservationSlotIDIndex] == Local_u8PatientID) // checking if patient id has reservation
        {
            printf("\nYour Have Reservation at :\n");
            printf("__________________________\n\n");
            printf("Time : 2pm to 2:30pm\n"); // printing slot label
        }
        if(Global_u8ReservationSlotsStatusID[1][Global_u8ReservationSlotIDIndex] == Local_u8PatientID) // checking if patient id has reservation
        {
            printf("\nYour Have Reservation at :\n");
            printf("__________________________\n\n");
            printf("Time : 2:30pm to 3pm\n"); // printing slot label
        }
        if(Global_u8ReservationSlotsStatusID[2][Global_u8ReservationSlotIDIndex] == Local_u8PatientID) // checking if patient id has reservation
        {
            printf("\nYour Have Reservation at :\n");
            printf("__________________________\n\n");
            printf("Time : 3pm to 3:30pm\n"); // printing slot label
        }
        if(Global_u8ReservationSlotsStatusID[3][Global_u8ReservationSlotIDIndex] == Local_u8PatientID) // checking if patient id has reservation
        {
            printf("\nYour Have Reservation at :\n");
            printf("__________________________\n\n");
            printf("Time : 4pm to 4:30pm\n"); // printing slot label
        }
        if(Global_u8ReservationSlotsStatusID[4][Global_u8ReservationSlotIDIndex] == Local_u8PatientID) // checking if patient id has reservation
        {
            printf("\nYour Have Reservation at :\n");
            printf("__________________________\n\n");
            printf("Time : 4:30pm to 5pm\n"); // printing slot label
        }
    }
    else
    {
        printf("****************************\n");
        printf("Message : ID Does Not Exist \n");
        printf("****************************\n");
        printf("\n/*____________________________________________________________*/\n\n");
    }
    printf("\n/*____________________________________________________________*/\n\n");
    ClinicPatient_voidSetBackWindowOption(); // checking if the patient wants to perform more operations
}
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
/* view today reservation option fuction implementation */
void ClinicPatient_voidViewTodayReservations(void)
{
    /* printing today reservation */
    printf("\n/* * * * * * * * View Today Reservations Tab * * * * * * * * */\n");
    printf("/*____________________________________________________________*/\n\n");
    printf("Slot Index - Slot Name -   Slot Time  - Slot Status - Patient ID\n");
    printf("1-           Slot1      2pm to 2:30pm   %c            %d\n",Global_u8ReservationSlotsStatusID[0][Global_u8ReservationSlotStatusIndex],
                                                                        Global_u8ReservationSlotsStatusID[0][Global_u8ReservationSlotIDIndex]);
    printf("2-           Slot1      2:30pm to 3pm   %c            %d\n",Global_u8ReservationSlotsStatusID[1][Global_u8ReservationSlotStatusIndex],
                                                                        Global_u8ReservationSlotsStatusID[1][Global_u8ReservationSlotIDIndex]);
    printf("3-           Slot1      3pm to 3:30pm   %c            %d\n",Global_u8ReservationSlotsStatusID[2][Global_u8ReservationSlotStatusIndex],
                                                                        Global_u8ReservationSlotsStatusID[2][Global_u8ReservationSlotIDIndex]);
    printf("4-           Slot1      4pm to 4:30pm   %c            %d\n",Global_u8ReservationSlotsStatusID[3][Global_u8ReservationSlotStatusIndex],
                                                                        Global_u8ReservationSlotsStatusID[3][Global_u8ReservationSlotIDIndex]);
    printf("5-           Slot1      5pm to 5:30pm   %c            %d\n",Global_u8ReservationSlotsStatusID[4][Global_u8ReservationSlotStatusIndex],
                                                                        Global_u8ReservationSlotsStatusID[4][Global_u8ReservationSlotIDIndex]);
    printf("/*____________________________________________________________*/\n\n");
    ClinicPatient_voidSetBackWindowOption(); // checking if the patient wants to perform more operations
}
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
void ClinicPatient_voidSetBackWindowOption(void)
{
    printf("/* * * * * * * * Set Back Window Option Tab * * * * * * * * * */\n");
    printf("/*____________________________________________________________*/\n\n");
    u8 Local_u8SelectWindow = 0; // variable to store admin selected option
    /* printing list of options that are provided to the patient */
    printf("Enter one of The Following Options to Proceed\n");
    printf("_____________________________________________\n");
    printf("1- Go to View Patient Record Window\n");
    printf("2- Go to View Today Reservations Window\n");
    printf("3- Exit The Program\n");
    printf("\n/*____________________________________________________________*/\n\n");
    printf("Enter Your Option : "); // asking the patient his option
    scanf("%d",&Local_u8SelectWindow); // getting patient selection
    printf("\n/*____________________________________________________________*/\n\n");
    switch(Local_u8SelectWindow) // checking the admin selection
    {
        case 1:
            ClinicPatient_voidViewPatientRecord(); // sending patient to view record tab
        break;
        case 2:
            ClinicPatient_voidViewTodayReservations(); // sending patient to view today reservation
        break;
        case 3:
            return; // terminate the program
        break;
        default:
            return; // terminate the program
        break;
    }
}
/* ________________________________________________________________________________________________ */
