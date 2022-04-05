/* ---------------------------------------------------------------------------------------------------------- */
/*                           	LinkedList Program Documentation        		     		          	  	  	  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	Clinic Management System                             					      */
/*  Project Description    :	                                                             			      */
/*  File Name              :	LinkedList.c                                    							      */
/*  Date                   :  	27 Dec, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	LinkedList Program Preprocessor Directives        		     		          */
/* ---------------------------------------------------------------------------------------------------------- */

/*		                        Library Inclusions								         */
#include "../LIB/STD_TYPES.h"
#include "../LIB/PATIENT_RECORD.h"
/*_______________________________________________________________________________________*/

/*		                        Self Files Inclusions							         */
#include "LinkedList.h"
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	LinkedList Program Definitions       		     		          	  	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	LinkedList Program Global Decelerations       		     		          	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	LinkedList Program Function Prototypes       		     		          	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	LinkedList Program Function Implementations       		     		          */
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
/* search nodes (patients profile) for duplicate id */
/* this function will be used when adding new patient record */
u8 LinkedList_u8SearchNodeDuplicateID(u8 SearchNodeData)
{
    PatientNode * Local_pstructCurrentNode; // creating pointer to struct variable to loopthrough nodes with it
    Local_pstructCurrentNode = Global_pstructHeaPointer; // initialize loopcounter value to headpointer value(address of the first node)
    while((Local_pstructCurrentNode -> PointerToTheNextPatientNode)!= NULL) // looping until the node before last to avoid checking the newest node
    {
        if(Local_pstructCurrentNode -> Patient_ID == SearchNodeData) // checking if current node id equals the newest node id
        {
            return 1; // return 1 if existed
        }
        Local_pstructCurrentNode = Local_pstructCurrentNode -> PointerToTheNextPatientNode; // updarting loopcounter with the address of the next node
    }
    return 0; // return 0 if not existed
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
/* search node (patients profile) for duplicate id or the patient id exits in the system */
u8 LinkedList_u8SearchNodeID(u8 SearchNodeData)
{
    PatientNode * Local_pstructCurrentNode; // creating pointer to struct variable to loopthrough nodes with it
    Local_pstructCurrentNode = Global_pstructHeaPointer; // initialize loopcounter value to headpointer value(address of the first node)
    while(Local_pstructCurrentNode != NULL) // looping until the last node
    {
        if(Local_pstructCurrentNode -> Patient_ID == SearchNodeData) // checking if current node id equals the given patient id
        {
            Global_pstructHoldNodeAddress = Local_pstructCurrentNode; // updating Global_pstructHoldNodeAddress with the address of the current node to access this profile out side this scope
            return 1; // return 1 if patient profile does exist
        }
        Local_pstructCurrentNode = Local_pstructCurrentNode -> PointerToTheNextPatientNode; // update loopcounter
    }
    return 0; // return 0 if patient profile doesn't exist
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
/* printing patient profile by passing patient profile address */
void LinkedList_voidPrintNodeData(PatientNode * Local_pstructCurrentNode)
{
    if(Local_pstructCurrentNode == NULL) // checking if patients list is empty
    {
        printf("**********************************************\n");
        printf("Message : There are No Patients Profile\n");
        printf("**********************************************\n");
        printf("\n/*____________________________________________________________*/\n\n");
    }
    else
    {
        /* printing patient data preview of the given patient id */
        printf("\n\nPatient Data Preview\n");
        printf("__________________________\n");
        printf("Patient Name is : %s\n",Local_pstructCurrentNode -> Patient_Name);
        printf("Patient Age is : %d\n",Local_pstructCurrentNode -> Patient_Age);
        printf("patient Gender is : %s\n",Local_pstructCurrentNode -> Patient_Gender);
        printf("Patient ID is : %d\n",Local_pstructCurrentNode -> Patient_ID);
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
/* printing all patients profile list this ax extra option to the admin */
void LinkedList_voidPrintAllNodesData(void)
{
    printf("\n/* * * * * Print All Patients Profile Reservation Tab * * * * * * */\n");
    printf("/*____________________________________________________________*/\n\n");
    PatientNode * Local_pstructCurrentNode; // creating pointer to struct variable to loopthrough nodes with it
    Local_pstructCurrentNode = Global_pstructHeaPointer; // initialize loopcounter value to headpointer value(address of the first node)
    if(Local_pstructCurrentNode == NULL) // checking if patients list is empty
    {
        printf("**********************************************\n");
        printf("Message : There are No Patients Profile\n");
        printf("**********************************************\n");
        printf("\n/*____________________________________________________________*/\n\n");
        return;
    }
    //printf("Printing All Patients Profiles\n");
    while(Local_pstructCurrentNode != NULL) // looping until final node
    {
        /* printing patients profile list */
        printf("Printing Patient Profile with ID : %d\n",Local_pstructCurrentNode -> Patient_ID);
        printf("**************************************************\n");
        printf("Patient Name is : %s\n",Local_pstructCurrentNode -> Patient_Name);
        printf("Patient Age is : %d\n",Local_pstructCurrentNode -> Patient_Age);
        printf("patient Gender is : %s\n",Local_pstructCurrentNode -> Patient_Gender);
        printf("Patient ID is : %d\n",Local_pstructCurrentNode -> Patient_ID);
        printf("**************************************************\n\n");
        Local_pstructCurrentNode = Local_pstructCurrentNode -> PointerToTheNextPatientNode;
    }
    //printf("All Patients Profiles are Printed\n");
}
/* ________________________________________________________________________________________________ */
