/* * * * * * * * * * * * Header Log File * * * * * * * * * * *  * * * * * /
/*_______________________________________________________________________*/
/*  Author          :   Abbas Mahmoud                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*  Project Name    :   Clinic Management System                         */
/*  File Name       :   main.c                                           */
/*  Date            :   27 DEC, 2021                                     */
/*  Version         :   V1.0                                             */
/*_______________________________________________________________________*/

/*                      Library Inclusions                               */
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
/*_______________________________________________________________________*/

/* struct datatype to store patient profile data */
struct PatientNode
{
    u8 Patient_Name[255];                               // array of characters to store patient name
    u8 Patient_Age;                                     // variable to store patient age
    u8 Patient_Gender[12];                              // array of characters to store patient gender
    u8 Patient_ID;                                      // variable to store patient id
    struct PatientNode * PointerToTheNextPatientNode;   // pointer to struct to point to the address of the next node
};

struct PatientNode * Global_pstructHeaPointer = NULL;   // pointer to struct to point to the address of the first node
struct PatientNode * Global_pstructHoldNodeAddress = NULL;  // pointer to stuct to hold the address of any required node from any function

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

/*_______________________________________________________________________*/

/*                                  Functions ProtoTypes                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */
/*_______________________________________________________________________*/
/*                      Initiate Main Window Mode Function              */
void Clinic_voidInitMainWindow(void);
/*_______________________________________________________________________*/
/*                      Admin Mode Functions                             */
/*                      Initiate Admin Mode Function                     */
void ClinicAdmin_voidInitAdminMode(void);
/*           Auxillary Functions to Initiate Admin Mode Function         */
u8   ClinicAdmin_u8CheckAdminPassword(void);
void ClinicAdmin_voidPrintAdminOptionsMessage(void);
u8   ClinicAdmin_u8GetAdminOption(void);
void ClinicAdmin_voidSetBackWindowOption(void);
/*                      Admin Mode Main Functions                        */
/*                      Main Function 1                                  */
void ClinicAdmin_voidAddPatientRecord(void);
/*                      Main Function 2                                  */
void ClinicAdmin_voidEditPatientRecord(void);
/*                      Main Function 3                                  */
void ClinicAdmin_voidReserveSlotwithTheDoctor(void);
/*                      Main Function 4                                  */
void ClinicAdmin_voidCancelReservation(void);
/*                      Auxillary Functions Function 4                   */
u8   ClinicAdmin_u8CheckPatientIDValue(u8 Local_u8PatientID);
u8   ClinicAdmin_u8CheckEmptySlot(void);
u8   ClinicAdmin_u8CheckReservationSlotsPatientID(u8 Local_u8PatientID);
/*_______________________________________________________________________*/
/*                      Patient Mode Functions                           */
/*                      Initiate Patient Mode Function                   */
void ClinicPatient_voidInitPatientMode(void);
/*           Auxillary Functions to Initiate Patient Mode Function       */
void ClinicPatient_voidPrintPatientOptionsMessage(void);
u8   ClinicPatient_u8GetPatientOption(void);
void ClinicPatient_voidSetBackWindowOption(void);
/*                      Patient Mode Main Functions                      */
/*                      Main Function 1                                  */
void ClinicPatient_voidViewPatientRecord(void);
/*                      Main Function 1                                  */
void ClinicPatient_voidViewTodayReservations(void);
/*_______________________________________________________________________*/
/*                      Linked List Functions                            */
u8   LinkedList_u8SearchNodeDuplicateID(u8 SearchNodeData);
u8   LinkedList_u8SearchNodeID(u8 SearchNodeData);
void LinkedList_voidPrintNodeData(struct PatientNode * Local_pstructCurrentNode);
void LinkedList_voidPrintAllNodesData(void);
/*_______________________________________________________________________*/

s32 main(void)
{
    /* Run The Program MainWindow Function */
    Clinic_voidInitMainWindow();
    return 0;
}

/*                                                              Functions Implementations                                                                             */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                  Admin Mode Initiate Function                           */
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
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                              Admin Mode Main Functions                                                                             */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void ClinicAdmin_voidInitAdminMode(void)
{
    printf("/*____________________________________________________________*/\n");
    ClinicAdmin_voidPrintAdminOptionsMessage(); // function: printing options message to admin in admin options window
    switch(ClinicAdmin_u8GetAdminOption())  // function: checking admin selected option
    {
        case 1:
            ClinicAdmin_voidAddPatientRecord(); // function: add patient record and get patient data by the admin
        break;

        case 2:
            ClinicAdmin_voidEditPatientRecord();//function: edit patient record by the admin
        break;

        case 3:
            ClinicAdmin_voidReserveSlotwithTheDoctor(); // function: reserve slot with the doctor by the admin
        break;

        case 4:
            ClinicAdmin_voidCancelReservation();    //function: cancel reservation by the admin
        break;

        case 5:
            LinkedList_voidPrintAllNodesData(); // function: print all patients profile data mode is selected
            ClinicAdmin_voidSetBackWindowOption();  // function: print go back options menu to the admin
        break;

        default:
        ClinicAdmin_voidInitAdminMode();    // initiate admin mode again in default mode
        break;
    }
}
/*_______________________________________________________________________*/
u8 ClinicAdmin_u8CheckAdminPassword(void)
{

    printf("\n/* * * * * * * * * * * * Admin User Login Tab * * * * * * * * */\n");
    printf("/*____________________________________________________________*/\n\n");
    u8  Local_AdminPasswordTrials = 3; // variable to store max allowed password trials
    u16 Local_AdminPasswordInput= 0; // variable to store input password from the user
    //u16 Local_AdminPasswordCheck = 1234; // pre-configured password by the admin
    static u8 Local_PasswordLoopCounter = 1; // loop counter for password trials loop
    /* getting password from the user as long as trials max number is less than 3*/
    while(Local_PasswordLoopCounter <= 3)
    {
        printf("Enter Password (Trial = %d) : ",Local_PasswordLoopCounter); // asking the user to enter the password
        scanf("%d",&Local_AdminPasswordInput); // getting the password from the user
        //printf("You Entered : %d\n",Local_AdminPasswordInput); // debug line
        if((Local_AdminPasswordInput == 1234) && (Local_PasswordLoopCounter <= 3)) // checking input password and password input trials
        {
            Local_PasswordLoopCounter = 1; // reset password trials number to 1 as variable is defined to static
            printf("\n/*____________________________________________________________*/\n\n");
            return 1; // return 1 in case of correct password within allowed password trials number
        }
        Local_PasswordLoopCounter++; // update password trials number
    }
    if(Local_PasswordLoopCounter > 3) // checking for input password trials number
    {
        return 0; // return 0 in case of exceeding allowed input password trials number
    }
}
/*_______________________________________________________________________*/
void ClinicAdmin_voidPrintAdminOptionsMessage(void)
{
    printf("\n/* * * * * * * * * * * * * Admin Options Menu Window * * * * * * * * * * * * * */\n");
    printf("/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */\n\n");
    printf("Select One Of The Following Options :\n");
    printf("_____________________________________\n");
    printf("1- Add New Patient Record\n");
    printf("2- Edit Patient Record\n");
    printf("3- Reserve a Slot with The Doctor\n");
    printf("4- Cancel Reservation\n");
    printf("5- Print All Patients Profile\n");
    printf("\n/*____________________________________________________________*/\n\n");
}
/*_______________________________________________________________________*/
u8 ClinicAdmin_u8GetAdminOption(void)
{
    printf("/* * * * * * * * * Admin Option Selection Tab * * * * * * * * */\n");
    printf("/*____________________________________________________________*/\n\n");
    u8 Local_OptionIndex; // variable to store admin selected option index
    printf("Enter Option Index : "); // asking the user to input option index
    scanf("%d",&Local_OptionIndex); // getting selected option index from the user
    printf("\n/*____________________________________________________________*/\n");
    return Local_OptionIndex; // return admin selected option index
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* add patient record function implementation */
void ClinicAdmin_voidAddPatientRecord(void)
{
    printf("\n/* * * * * * * * * Add New Patient Record Tab * * * * * * * * */\n");
    printf("/*____________________________________________________________*/\n\n");
    /* creating new node for new patient profile with size of struct PatientNode datatype */
    struct PatientNode * NewPatient = (struct PatientNode*)malloc(sizeof(struct PatientNode));
    if(Global_pstructHeaPointer == NULL) // checking if patients profile list is emtpy or not
    {
        /* adding patient data to patient profile */
        Global_pstructHeaPointer = NewPatient; // assign new node address to headpointer
        NewPatient -> PointerToTheNextPatientNode = NULL; // assign new node pointer to the next node to null as it's mow the last and only node in linkedlist

        printf("Enter Patient Data\n");
        printf("__________________\n\n");
        printf("Patient Name :"); // asking the admin to enter patient name
        scanf("%s",& NewPatient -> Patient_Name); // getting patient name from the admin
        printf("\nPatient Age :");  // asking the admin to enter patient age
        scanf("%d",&NewPatient -> Patient_Age); // getting patient age from the admin
        printf("\nPatient Gender :");   // asking the admin to enter patient gender
        scanf("%s",&NewPatient -> Patient_Gender); // getting patinet gender from the admin

        u8 Local_u8IDCheckValueFlag = 0;  // variable to store status flag if id value equals 0
        while(Local_u8IDCheckValueFlag == 0) // loop until id check value flag isn't 0
        {
            printf("\nPatient ID :"); // asking the admin to enter patient id
            scanf("%d",&NewPatient -> Patient_ID); // getting patient id form the admin
            Local_u8IDCheckValueFlag = ClinicAdmin_u8CheckPatientIDValue(NewPatient -> Patient_ID); // passing patient id to ClinicAdmin_u8CheckPatientIDValue and update Local_u8IDCheckValueFlag
            if(Local_u8IDCheckValueFlag == 0) // checking Local_u8IDCheckValueFlag as patient id can't be equal 0 and print error message
            {
                printf("**********************************\n");
                printf("Message : Patient ID Can't Be Zero\n");
                printf("**********************************\n");
            }
        }

        /*printing patient profile data preview*/
        printf("\n\nPatient Data Preview\n");
        printf("____________________\n");
        printf("\nPatient Name is : %s\n",NewPatient -> Patient_Name);
        printf("Patient Age is : %d\n",NewPatient -> Patient_Age);
        printf("patient Gender is : %s\n",NewPatient -> Patient_Gender);
        printf("Patient ID is : %d\n",NewPatient -> Patient_ID);
        printf("\n/*____________________________________________________________*/\n\n");
    }
    else
    {
        /* creating pointer to struct variable as loopcounter to get to the last patient profile(node) */
        struct PatientNode * Local_pstructCurrentNode = Global_pstructHeaPointer;
        /* looping until the last patient profile (node) */
        while(Local_pstructCurrentNode -> PointerToTheNextPatientNode != NULL)
        {
            Local_pstructCurrentNode = Local_pstructCurrentNode -> PointerToTheNextPatientNode; // Local_pstructCurrentNode value
        }
        /* last profile is reached */
        Local_pstructCurrentNode -> PointerToTheNextPatientNode = NewPatient; // assign Local_pstructCurrentNode pointer to the next node (patient profile) to new node (patient profile) address
        NewPatient -> PointerToTheNextPatientNode = NULL; // assign new node (patient profile) to null as it's now the last node (patient profile)

        printf("Enter Patient Data\n");
        printf("__________________\n\n");
        printf("Patient Name :"); // asking the admin to enter patient name
        scanf("%s",& NewPatient -> Patient_Name); // getting patient name from the admin
        printf("\nPatient Age :");  // asking the admin to enter patient age
        scanf("%d",&NewPatient -> Patient_Age); // getting patient age from the admin
        printf("\nPatient Gender :");   // asking the admin to enter patient gender
        scanf("%s",&NewPatient -> Patient_Gender); // getting patinet gender from the admin

        u8 Local_u8IDCheckValueFlag = 0; // variable to store status flag if id value equals 0
        u8 Local_u8IDSearchFlag = 1;// variable to store status flag if the id exists in the system or not
        while(Local_u8IDSearchFlag != 0) // loop until the admin assign unique id to new patient profile
        {
            printf("\nPatient ID :"); // asking the admin to enter patient id
            scanf("%d",&NewPatient -> Patient_ID); // getting patient id from the admin
            Local_u8IDCheckValueFlag = ClinicAdmin_u8CheckPatientIDValue(NewPatient -> Patient_ID); // passing patient id to ClinicAdmin_u8CheckPatientIDValue and update Local_u8IDCheckValueFlag
            if(Local_u8IDCheckValueFlag == 1)
            {
                Local_u8IDSearchFlag = LinkedList_u8SearchNodeDuplicateID(NewPatient -> Patient_ID); // updating Local_u8IDSearchFlag by checking if the entered id is unique or not
                if(Local_u8IDSearchFlag != 0) // checking if id does already exist in the system
                {
                    printf("*******************************\n");
                    printf("Message : ID is already Existed\n");
                    printf("*******************************\n");
                }
            }
            else
            {
                printf("**********************************\n");
                printf("Message : Patient ID Can't Be Zero\n");
                printf("**********************************\n");
            }
        }

        /* printing patient data preview after addind patient record */
        printf("\n\nPatient Data Preview\n");
        printf("__________________________\n");
        printf("\nPatient Name is : %s\n",NewPatient -> Patient_Name);
        printf("Patient Age is : %d\n",NewPatient -> Patient_Age);
        printf("patient Gender is : %s\n",NewPatient -> Patient_Gender);
        printf("Patient ID is : %d\n",NewPatient -> Patient_ID);
        printf("\n/*____________________________________________________________*/\n\n");
    }
    /* checking if the admin wants to perform more operations */
    ClinicAdmin_voidSetBackWindowOption();
}
/*_______________________________________________________________________*/
/* check entered patient id value function implementation */
u8 ClinicAdmin_u8CheckPatientIDValue(u8 Local_u8PatientID)
{
    if(Local_u8PatientID > 0 ) // checking the passed id value with zero
    {
        return 1; // return 1 if true (id >0)
    }
    else
    {
        return 0;   // return 0 if false
    }
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* edit patient record option function implementation */
void ClinicAdmin_voidEditPatientRecord(void)
{
    printf("\n/* * * * * * * * * Edit Patient Record Tab * * * * * * * * * */\n");
    printf("/*____________________________________________________________*/\n\n");
    u8 Local_u8IDSearchFlag; // variable to store status flag if the id exists in the system or not
    u8 Local_u8IDCheckValueFlag; // variable to store status flag if id value equals 0
    u8 Local_u8PatientDataEdit; // variable to store the index of patient data that the admin wants to edit
    u8 Local_u8PatientIDEdit; // variable to store the patient profile id that the admin wants to edit
    printf("Enter Patient Profile ID to Edit : "); // askinf the admin to enter patient id
    scanf("%d",&Local_u8PatientIDEdit); // getting patient id form the admin
    printf("\n/*____________________________________________________________*/\n\n");
    if(Global_pstructHeaPointer == NULL) // checking if patients profile list us empty or not
    {
        printf("**********************************\n");
        printf("Message : Patients Record is Empty\n");
        printf("**********************************\n");
        printf("\n/*____________________________________________________________*/\n\n");
        ClinicAdmin_voidSetBackWindowOption(); // checking if the admin wants to perform more operations
    }
    else
    {
        Local_u8IDSearchFlag = LinkedList_u8SearchNodeID(Local_u8PatientIDEdit); // updating Local_u8IDSearchFlag by searching the entered patient id in patients profile list
        /* the value of Global_pstructHoldNodeAddress will be updated with the corresponding node address to the entered patient id */
        /* Global_pstructHoldNodeAddress will be used to access patient profile data */
        if(Local_u8IDSearchFlag == 1) // checking if the patient id exists in the system
        {
            /* printing preview of patient profile */
            printf("Patient Data Preview\n");
            printf("____________________\n\n");
            printf("Patient Name is : %s\n",Global_pstructHoldNodeAddress -> Patient_Name);
            printf("Patient Age is : %d\n",Global_pstructHoldNodeAddress -> Patient_Age);
            printf("patient Gender is : %s\n",Global_pstructHoldNodeAddress -> Patient_Gender);
            printf("Patient ID is : %d\n",Global_pstructHoldNodeAddress -> Patient_ID);
            /* printing list of options to the admin to choose which part of patient proflie to be editted */
            printf("\n/*____________________________________________________________*/\n\n");
            printf("Enter one of The Following Options to Proceed\n");
            printf("1- Edit Patient Name\n");
            printf("2- Edit Patient Age\n");
            printf("3- Edit Patient Gender\n");
            printf("4- Edit Patient ID\n");
            printf("5- Edit Patient Full Profile\n");
            printf("\n/*____________________________________________________________*/\n\n");
            printf("Enter Your Option : "); // asking the admin to enter the selected option
            scanf("%d",&Local_u8PatientDataEdit); // getting admin option
            printf("\n/*____________________________________________________________*/\n");
            switch(Local_u8PatientDataEdit) // checking admin selected option
            {
                case 1: // patient name option is selected
                    printf("\n/*____________________________________________________________*/\n");
                    printf("\nEnter Patient New Name :"); // asking the admin to enter patient new name
                    scanf("%s",&Global_pstructHoldNodeAddress -> Patient_Name); // getting pateint new name
                    printf("\n/*____________________________________________________________*/\n\n");
                    /* printing patient profile after editting*/
                    printf("Patient Data Preview\n");
                    printf("____________________\n\n");
                    printf("Patient Name is : %s\n",Global_pstructHoldNodeAddress -> Patient_Name);
                    printf("Patient Age is : %d\n",Global_pstructHoldNodeAddress -> Patient_Age);
                    printf("patient Gender is : %s\n",Global_pstructHoldNodeAddress -> Patient_Gender);
                    printf("Patient ID is : %d\n",Global_pstructHoldNodeAddress -> Patient_ID);
                    printf("\n/*____________________________________________________________*/\n\n");
                    ClinicAdmin_voidSetBackWindowOption(); // checking if the admin wants to perform more operations
                break;

                case 2: // patient age option is selected
                    printf("\n/*____________________________________________________________*/\n");
                    printf("\nEnter Patient New Age :"); // asking the admin to enter patient new age
                    scanf("%d",&Global_pstructHoldNodeAddress -> Patient_Age); // getting pateint new age from the admin
                    printf("\n/*____________________________________________________________*/\n\n");
                    /* printing patient profile after editting*/
                    printf("Patient Data Preview\n");
                    printf("____________________\n\n");
                    printf("Patient Name is : %s\n",Global_pstructHoldNodeAddress -> Patient_Name);
                    printf("Patient Age is : %d\n",Global_pstructHoldNodeAddress -> Patient_Age);
                    printf("patient Gender is : %s\n",Global_pstructHoldNodeAddress -> Patient_Gender);
                    printf("Patient ID is : %d\n",Global_pstructHoldNodeAddress -> Patient_ID);
                    printf("\n/*____________________________________________________________*/\n\n");
                    ClinicAdmin_voidSetBackWindowOption(); // checking if the admin wants to perform more operations
                break;

                case 3:// patient gender option is selected
                    printf("\n/*____________________________________________________________*/\n");
                    printf("\nEnter Patient New Gender :"); // asking the admin to enter patient new gender
                    scanf("%s",&Global_pstructHoldNodeAddress -> Patient_Gender); // getting pateint new gender from the admin
                    printf("\n/*____________________________________________________________*/\n\n");
                    /* printing patient profile after editting*/
                    printf("Patient Data Preview\n");
                    printf("____________________\n\n");
                    printf("Patient Name is : %s\n",Global_pstructHoldNodeAddress -> Patient_Name);
                    printf("Patient Age is : %d\n",Global_pstructHoldNodeAddress -> Patient_Age);
                    printf("patient Gender is : %s\n",Global_pstructHoldNodeAddress -> Patient_Gender);
                    printf("Patient ID is : %d\n",Global_pstructHoldNodeAddress -> Patient_ID);
                    printf("\n/*____________________________________________________________*/\n\n");
                    ClinicAdmin_voidSetBackWindowOption(); // checking if the admin wants to perform more operations
                break;

                case 4: // patient id option is selected
                    printf("\n/*____________________________________________________________*/\n");
                    Local_u8IDCheckValueFlag = 0; // variable to store status flag if id value equals 0
                    Local_u8IDSearchFlag = 1; // variable to store status flag if the id exists in the system or not
                    while(Local_u8IDSearchFlag != 0) // looping until the new patient id is unique
                    {
                        printf("\nEnter Patient ID :"); // asking the admin to enter patient id
                        scanf("%d",&Global_pstructHoldNodeAddress -> Patient_ID); // getting new patient id from the user
                        Local_u8IDCheckValueFlag = ClinicAdmin_u8CheckPatientIDValue(Global_pstructHoldNodeAddress -> Patient_ID); // checking if the new id equals zero or not and updating Local_u8IDCheckValueFlag
                        if(Local_u8IDCheckValueFlag == 1) // checking if id not equals zero status flag = 1
                        {
                            Local_u8IDSearchFlag = LinkedList_u8SearchNodeDuplicateID(Global_pstructHoldNodeAddress -> Patient_ID); // checking if new patient id is unique and update status flag
                            if(Local_u8IDSearchFlag != 0) // checking if id is unique or  not
                            {
                                printf("*******************************\n");
                                printf("Message : ID is already Existed\n");
                                printf("*******************************\n");
                            }
                        }
                        else
                        {
                            printf("*********************************************\n");
                            printf("Message : Patient ID Can't Be Zero\n");
                            printf("*********************************************\n");
                        }
                    }
                    printf("\n/*____________________________________________________________*/\n\n");
                    /* printing patient profile after editting*/
                    printf("Patient Data Preview\n");
                    printf("____________________\n\n");
                    printf("Patient Name is : %s\n",Global_pstructHoldNodeAddress -> Patient_Name);
                    printf("Patient Age is : %d\n",Global_pstructHoldNodeAddress -> Patient_Age);
                    printf("patient Gender is : %s\n",Global_pstructHoldNodeAddress -> Patient_Gender);
                    printf("Patient ID is : %d\n",Global_pstructHoldNodeAddress -> Patient_ID);
                    printf("\n/*____________________________________________________________*/\n\n");
                    ClinicAdmin_voidSetBackWindowOption(); // checking if the admin wants to perform more operations
                break;

                case 5: // Patient Full Profile option is selected
                    printf("\n/*____________________________________________________________*/\n\n");
                    /* getting patient new data from the admin similar to adding patient profile */
                    printf("Enter Patient Data\n");
                    printf("__________________\n");
                    printf("\nEnter Patient Name :");
                    scanf("%s",&Global_pstructHoldNodeAddress -> Patient_Name);
                    printf("\nEnter Patient Age :");
                    scanf("%d",&Global_pstructHoldNodeAddress -> Patient_Age);
                    printf("\nEnter Patient Gender :");
                    scanf("%s",&Global_pstructHoldNodeAddress -> Patient_Gender);
                    Local_u8IDCheckValueFlag = 0; // variable to store status flag if id value equals 0
                    Local_u8IDSearchFlag = 1; // variable to store status flag if the id exists in the system or not
                    while(Local_u8IDSearchFlag != 0) // looping until the new patient id is unique
                    {
                        printf("\nEnter Patient ID :"); // asking the admin to enter patient id
                        scanf("%d",&Global_pstructHoldNodeAddress -> Patient_ID); // getting new patient id from the user
                        Local_u8IDCheckValueFlag = ClinicAdmin_u8CheckPatientIDValue(Global_pstructHoldNodeAddress -> Patient_ID); // checking if the new id equals zero or not and updating Local_u8IDCheckValueFlag
                        if(Local_u8IDCheckValueFlag == 1) // checking if id not equals zero status flag = 1
                        {
                            Local_u8IDSearchFlag = LinkedList_u8SearchNodeDuplicateID(Global_pstructHoldNodeAddress -> Patient_ID); // checking if new patient id is unique and update status flag
                            if(Local_u8IDSearchFlag != 0) // checking if id is unique or  not
                            {
                                printf("*******************************\n");
                                printf("Message : ID is already Existed\n");
                                printf("*******************************\n");
                            }
                        }
                        else
                        {
                            printf("*********************************************\n");
                            printf("Message : Patient ID Can't Be Zero\n");
                            printf("*********************************************\n");
                        }
                    }
                    /* printing patient profile after editting*/
                    printf("\n\nPatient Data Preview\n");
                    printf("__________________________\n");
                    printf("\nPatient Name is : %s\n",Global_pstructHoldNodeAddress -> Patient_Name);
                    printf("Patient Age is : %d\n",Global_pstructHoldNodeAddress -> Patient_Age);
                    printf("patient Gender is : %s\n",Global_pstructHoldNodeAddress -> Patient_Gender);
                    printf("Patient ID is : %d\n",Global_pstructHoldNodeAddress -> Patient_ID);
                    ClinicAdmin_voidSetBackWindowOption(); // checking if the admin wants to perform more operations
                break;

                default:
                    printf("*********************************************\n");
                    printf("Message : Invalid Option \n");
                    printf("*********************************************\n");
                    printf("\n/*____________________________________________________________*/\n\n");
                    ClinicAdmin_voidSetBackWindowOption(); // checking if the admin wants to perform more operations
                break;
            }
        }
        else
        {
            printf("*********************************************\n");
            printf("Message : ID Does Not Exist \n");
            printf("*********************************************\n");
            printf("\n/*____________________________________________________________*/\n\n");
            ClinicAdmin_voidSetBackWindowOption(); // checking if the admin wants to perform more operations
        }
    }
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* reserve slot with the doctor option function implementation */
void ClinicAdmin_voidReserveSlotwithTheDoctor(void)
{
    printf("\n/* * * * * * Reserve Slot with The Doctor Tab * * * * * * * */\n");
    printf("/*____________________________________________________________*/\n\n");
    u8 Local_u8ReservationEmptySlotFlag = 0; // variable to store empty slot checking status flag
    Local_u8ReservationEmptySlotFlag = ClinicAdmin_u8CheckEmptySlot(); // checking and printing empty slots and updating status flag
    /* note : static here isn't logical but i added it because after getting the id value and store in the variable it becomes zero at certain part of code */
    static u8 Local_u8ReserveSlotPatientID; // variable to hold patient id for reservation
    Local_u8ReserveSlotPatientID = 0; // initializing the variable
    u8 Local_u8IDSearchFlag = 0; // variable to store status flag if the id exists in the system or not
    u8 Local_u8IDReserveFlag = 0; // variable to store id reservation status flag/empty slot index
    u8 Local_u8ReserveSlotSelect = 0; // variable to store selected slot index

    if(Local_u8ReservationEmptySlotFlag) // checking if there is an empty slot
    {
        printf("Enter Patient ID: "); // asking the admin to enter patient id to reserve a slot
        scanf("%d",&Local_u8ReserveSlotPatientID); // getting patient id form the admin
        Local_u8IDSearchFlag = LinkedList_u8SearchNodeID(Local_u8ReserveSlotPatientID); // checking if there patient profile with this id and update status flag
        if(Local_u8IDSearchFlag == 1) // checking if the id in the system or not
        {
            Local_u8IDReserveFlag = ClinicAdmin_u8CheckReservationSlotsPatientID(Local_u8ReserveSlotPatientID); // checking if id already has reservation and update status flag
            if(Local_u8IDReserveFlag == 255) // checking for id reservation
            {
                printf("Enter One of The Available Slots Number to Reserve it for a Patient: "); // asking the admin to enter index of an empty slot
                scanf("%d",&Local_u8ReserveSlotSelect); // getting empty slot index
                printf("\n/*____________________________________________________________*/\n\n");
                switch(Local_u8ReserveSlotSelect) // checking for slot index
                {
                    case 1: // slot 1 is selected
                        Global_u8ReservationSlotsStatusID[0][Global_u8ReservationSlotStatusIndex] = 'R'; // updating slot status to be reserved
                        Global_u8ReservationSlotsStatusID[0][Global_u8ReservationSlotIDIndex] = Local_u8ReserveSlotPatientID; // assign patient id to the slot
                    break;

                    case 2: // slot 2 is selected
                        Global_u8ReservationSlotsStatusID[1][Global_u8ReservationSlotStatusIndex] = 'R'; // updating slot status to be reserved
                        Global_u8ReservationSlotsStatusID[1][Global_u8ReservationSlotIDIndex] = Local_u8ReserveSlotPatientID; // assign patient id to the slot
                    break;

                    case 3: // slot 3 is selected
                        Global_u8ReservationSlotsStatusID[2][Global_u8ReservationSlotStatusIndex] = 'R'; // updating slot status to be reserved
                        Global_u8ReservationSlotsStatusID[2][Global_u8ReservationSlotIDIndex] = Local_u8ReserveSlotPatientID; // assign patient id to the slot
                    break;

                    case 4: // slot 4 is selected
                        Global_u8ReservationSlotsStatusID[3][Global_u8ReservationSlotStatusIndex] = 'R'; // updating slot status to be reserved
                        Global_u8ReservationSlotsStatusID[3][Global_u8ReservationSlotIDIndex] = Local_u8ReserveSlotPatientID; // assign patient id to the slot
                    break;

                    case 5: // slot 5 is selected
                        Global_u8ReservationSlotsStatusID[4][Global_u8ReservationSlotStatusIndex] = 'R'; // updating slot status to be reserved
                        Global_u8ReservationSlotsStatusID[4][Global_u8ReservationSlotIDIndex] = Local_u8ReserveSlotPatientID; // assign patient id to the slot
                    break;

                    default:
                        printf("******************************\n");
                        printf("Message : Invalid Slot Number \n");
                        printf("******************************\n");
                        printf("\n/*____________________________________________________________*/\n\n");
                    break;
                }
            }
            else
            {
                printf("**********************************************\n");
                printf("Message : Patient ID already Has a Reservation \n");
                printf("***********************************************\n");
                printf("\n/*____________________________________________________________*/\n\n");
            }
        }
        else
        {
            printf("*******************************************\n");
            printf("Message : No Patient Profile with Given ID \n");
            printf("*******************************************\n");
            printf("\n/*____________________________________________________________*/\n\n");
        }
    }
    else
    {
        printf("*********************************\n");
        printf("Message : No Slots are avialbale \n");
        printf("*********************************\n");
        printf("\n/*____________________________________________________________*/\n\n");
    }
    ClinicAdmin_voidSetBackWindowOption(); // checking if the admin wants to perform more operations
}
/*_______________________________________________________________________*/
/* checking and printing empty slots function implementation */
u8 ClinicAdmin_u8CheckEmptySlot(void)
    {
        u8 Local_u8EmptySlotFlag = 0; // variable to keep track of empty slots status
        if(Global_u8ReservationSlotsStatusID[0][Global_u8ReservationSlotStatusIndex] == 'E') // checking if slot status is reserved or empty
        {
            printf("1- Slot1: 2pm     to  2:30pm\n"); // printing slot label
            Local_u8EmptySlotFlag = 1; // updating status flag
        }
        if(Global_u8ReservationSlotsStatusID[1][Global_u8ReservationSlotStatusIndex] == 'E') // checking if slot status is reserved or empty
        {
            printf("2- Slot2: 2:30pm  to  3pm\n"); // printing slot label
            Local_u8EmptySlotFlag = 1; // updating status flag
        }
        if(Global_u8ReservationSlotsStatusID[2][Global_u8ReservationSlotStatusIndex] == 'E') // checking if slot status is reserved or empty
        {
            printf("3- Slot3: 3pm     to  3:30pm\n"); // printing slot label
            Local_u8EmptySlotFlag = 1; // updating status flag
        }
        if(Global_u8ReservationSlotsStatusID[3][Global_u8ReservationSlotStatusIndex] == 'E') // checking if slot status is reserved or empty
        {
            printf("4- Slot4: 4pm     to  4:30pm\n"); // printing slot label
            Local_u8EmptySlotFlag = 1; // updating status flag
        }
        if(Global_u8ReservationSlotsStatusID[4][Global_u8ReservationSlotStatusIndex] == 'E') // checking if slot status is reserved or empty
        {
            printf("5- Slot5: 4:30pm  to  5pm\n"); // printing slot label
            Local_u8EmptySlotFlag = 1; // updating status flag
        }
        else
        {
            Local_u8EmptySlotFlag = 0; // updating status flag
            return Local_u8EmptySlotFlag; // return status flag
        }
        return Local_u8EmptySlotFlag; // return status flag
    }
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* cancel reservation option function implementation */
void ClinicAdmin_voidCancelReservation(void)
{
    printf("\n/* * * * * * * * * Cancel Reservation Tab * * * * * * * * * */\n");
    printf("/*____________________________________________________________*/\n\n");
    u8 Local_u8PatientIDCheck = 0; // variable to store patient id
    printf("Enter Patient ID to Cancel Reservation : "); // asking admin to enter patient id
    scanf("%d",&Local_u8PatientIDCheck);// getting patient id from the admin
    printf("\n/*____________________________________________________________*/\n\n");
    u8 Local_u8PatientIDSlotIndex= ClinicAdmin_u8CheckReservationSlotsPatientID(Local_u8PatientIDCheck); // checking if id already has reservation and update status flag
    if(Local_u8PatientIDSlotIndex != 255) // if id has reservation
    {
        Global_u8ReservationSlotsStatusID[Local_u8PatientIDSlotIndex][Global_u8ReservationSlotIDIndex] = 0; // clear slot id reservation
        Global_u8ReservationSlotsStatusID[Local_u8PatientIDSlotIndex][Global_u8ReservationSlotStatusIndex] = 'E'; // set slot status to empty
    }
    else
    {
        printf("**********************************************\n");
        printf("Message : There is No Reservation with This ID\n");
        printf("**********************************************\n");
        printf("\n/*____________________________________________________________*/\n\n");
    }
    ClinicAdmin_voidSetBackWindowOption(); // checking if the admin wants to perform more operations
}
/*_______________________________________________________________________*/
/* check if patient id has reservation function implementation */
u8 ClinicAdmin_u8CheckReservationSlotsPatientID(u8 Local_u8PatientID)
{
    u8 Local_u8PatientIDReservationSlotIndex = 0; // variable to return patient id reserved slot index
    u8 Local_u8LoopCounter = 0; // loopcounter to loop through all slots
    u8 Local_u8IDNotFoundFlag = 255; // default value to be returned when id has no reservation
    while(Local_u8LoopCounter <= Global_u8ReservationSlotsStatusIDRowsIndex) // looping as long as loopcounter is <= number of slots
    {
        if(Local_u8PatientID == Global_u8ReservationSlotsStatusID[Local_u8LoopCounter][1]) // checking if patient id equals slot reserved id
        {
            Local_u8PatientIDReservationSlotIndex = Local_u8LoopCounter; // assign loopcounter to slot index
            return Local_u8PatientIDReservationSlotIndex; // return slot index
        }
        Local_u8LoopCounter++;
    }
    return Local_u8IDNotFoundFlag; // return not found flag
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* get back window option to admin function implementation */
void ClinicAdmin_voidSetBackWindowOption(void)
{
    printf("/* * * * * * * * Set Back Window Option Tab * * * * * * * * * */\n");
    printf("/*____________________________________________________________*/\n\n");
    u8 Local_u8SelectWindow = 0; // variable to store admin selected option
    /* printing list of options that are provided to the admin */
    printf("Enter one of The Following Options to Proceed\n");
    printf("1- Go to Admin Option Window\n");
    printf("2- Go to Patient Option Window\n");
    printf("3- Exit The Program\n");
    printf("/*____________________________________________________________*/\n\n");
    printf("Enter Your Option : "); // asking the admin his option
    scanf("%d",&Local_u8SelectWindow); // getting admin selection
    printf("/*____________________________________________________________*/\n\n");
    switch(Local_u8SelectWindow) // checking the admin selection
    {
        case 1:
            ClinicAdmin_voidInitAdminMode(); // sending admin back to admin options window
        break;
        case 2:
            ClinicPatient_voidInitPatientMode(); // sending admin to patient option window
        break;
        case 3:
            return; // terminate the program
        break;
        default:
            return; // terminate the program
        break;
    }
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                              Patient Mode Main Functions                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
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
/*_______________________________________________________________________*/
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
/*_______________________________________________________________________*/
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
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
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
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
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
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
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
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                              Linked List Auxillary Functions                                                                       */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* search nodes (patients profile) for duplicate id */
/* this function will be used when adding new patient record */
u8 LinkedList_u8SearchNodeDuplicateID(u8 SearchNodeData)
{
    struct PatientNode * Local_pstructCurrentNode; // creating pointer to struct variable to loopthrough nodes with it
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
/*_______________________________________________________________________*/
/* search node (patients profile) for duplicate id or the patient id exits in the system */
u8 LinkedList_u8SearchNodeID(u8 SearchNodeData)
{
    struct PatientNode * Local_pstructCurrentNode; // creating pointer to struct variable to loopthrough nodes with it
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
/*_______________________________________________________________________*/
/* printing patient profile by passing patient profile address */
void LinkedList_voidPrintNodeData(struct PatientNode * Local_pstructCurrentNode)
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
/*_______________________________________________________________________*/
/* printing all patients profile list this ax extra option to the admin */
void LinkedList_voidPrintAllNodesData(void)
{
    printf("\n/* * * * * Print All Patients Profile Reservation Tab * * * * * * */\n");
    printf("/*____________________________________________________________*/\n\n");
    struct PatientNode * Local_pstructCurrentNode; // creating pointer to struct variable to loopthrough nodes with it
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
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */