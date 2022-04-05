/* ---------------------------------------------------------------------------------------------------------- */
/*                           	main Documentation        		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	Clinic Management System                             					      */
/*  Project Description    :	                                                             			      */
/*  File Name              :	main.c                                    							          */
/*  Date                   :  	27 Dec, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Library Inclusions                                       */
#include <stdio.h>
#include <stdlib.h>
#include "LIB/STD_TYPES.h"
#include "LIB/PATIENT_RECORD.h"
/*_______________________________________________________________________________________*/

/*		                        Self Files Inclusions							         */
#include "LinkedList/LinkedList.h"
#include "AdminMode/AdminMode.h"
#include "PatientMode/PatientMode.h"
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Main Function Prototypes       		     		          	  		          */
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
void Clinic_voidInitMainWindow(void);
/* ________________________________________________________________________________________________ */

s32 main(void)
{
    /* Run The Program MainWindow Function */
    Clinic_voidInitMainWindow();
    return 0;
}

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Main Program Function Implementations       		     		          */
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
void Clinic_voidInitMainWindow(void)
{
    printf("\n/* * * * * * * * * * * Clinic Management System MainWindow * * * * * * * * * * */\n");
    printf("/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */\n\n");
    printf("/* * * * * * * * * * * User Selection Tab * * * * * * * * * * */\n");
    printf("/*____________________________________________________________*/\n\n");
    u8 Local_u8OptionSelect; // variable to get user option incase of locked admin account dur to exceeding password trials
    u8 Local_u8ModeSelect;  // variable to store the selected mode by the user
    Local_u8ModeSelect = 'D'; // initialize the variable to 'D' ak default mode
    printf("\nEnter A for Admin Mode and U for User Mode: "); // asking user to enter mode
    scanf("%c",&Local_u8ModeSelect);    // getting the selected mode from the user
    switch(Local_u8ModeSelect)  // checking the scanned mode from the user
    {
        case 'A':   // admin mode section
            switch(ClinicAdmin_u8CheckAdminPassword())  //function: checking the admin password by calling password checking password
            {
                case 1: // password is correct within permitted trails number
                    ClinicAdmin_voidInitAdminMode();    //function: initiate admin mode
                break;
                case 0: // password trials max number have been reached so admin mode is locked
                    printf("\n***************************************************************\n");
                    printf("\nMessage : Admin Mode is Locked Due to Exceeding Password Trials\n");
                    printf("\n***************************************************************\n\n");
                    printf("/*____________________________________________________________*/\n\n");
                    /* giving user option after locking admin account */
                    printf("Choose one of The Following Options to Procced\n");
                    printf("______________________________________________\n\n");
                    printf("1- Switch to Patient Mode\n");
                    printf("2- Exit The Program\n");
                    printf("______________________________________________\n\n");
                    Local_u8OptionSelect = 0; // initialize variable
                    printf("Enter Your Selection : "); // asking user to enter his option
                    scanf("%d",&Local_u8OptionSelect); // getting user option
                    switch(Local_u8OptionSelect) // checking user option
                    {
                        case 1:
                            ClinicPatient_voidInitPatientMode();    //function: initiate patient mode
                        break;
                        case 2:
                            return;
                        break;
                        default:
                            return;
                        break;
                    }
                    break;
            }
        break;
        case 'U': // patient mode section
            ClinicPatient_voidInitPatientMode();    //function: initiate patient mode
        break;
        default:    // default mode section that print message and initiate the program again
            printf("\n\n****************************************************************\n");
            printf("\nMessage : Wrong Mode Selection The Program will be Initiated Again\n");
            printf("\n******************************************************************s\n\n");
            Clinic_voidInitMainWindow();    //function: initiate the system again
        break;
    }
    printf("/*____________________________________________________________*/\n");
}
/* ________________________________________________________________________________________________ */


