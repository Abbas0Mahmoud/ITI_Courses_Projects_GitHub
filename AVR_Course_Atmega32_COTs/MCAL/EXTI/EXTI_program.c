/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	EXTI Driver                             							  	      */
/*  Project Description    :	EXTI Driver                                                 				  */
/*  Target Controller 	   :	Atmega 32                                               					  */
/*  File Name              :	EXTI_program.c                                    						      */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/*		                        Library Inclusions							             */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*_______________________________________________________________________________________*/

/*		                HAL Layer Inclusion							                     */

/*_______________________________________________________________________________________*/

/*		                MCAL Layer Inclusion					                         */

/*_______________________________________________________________________________________*/


/*		                Self Files Inclusoins							                 */
#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Global Declerations       		     		          	  	  	      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Function Prototypes       		     		          	  		      */
/* ---------------------------------------------------------------------------------------------------------- */

static void (*Global_pvINT0CallBackFunction)(void) = NULL;
static void (*Global_pvINT1CallBackFunction)(void) = NULL;
static void (*Global_pvINT2CallBackFunction)(void) = NULL;

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Function Implementations       		     		          	  		  */
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
void MEXTI_voidInit(void)
{
    /*          Initialize INT0 PIN                                          */
    /* Check IF INT0 is Enabled or Disabled */
    #if     EXTI_INT0_ENABLE == ENABLE                      // INT0 is Enabled
        /* Check for Selected Sense Type Mode */
        #if     EXTI_INT0_SENSE_SIGNAL == FAILING_EDGE      // Sense Signal is Failing Edge
            CLR_REG_BIT(MCUCR,MCUCR_ISC00);                 // Clear MCUR_ISC00 Bit
            SET_REG_BIT(MCUCR,MCUCR_ISC01);                 // Set MCUE_ISC01 Bit
        #elif   EXTI_INT0_SENSE_SIGNAL == RISING_EDGE       // Sense Signal is Rising Edge
            SET_REG_BIT(MCUCR,MCUCR_ISC00);                 // Set MCUE_ISC00 Bit
            SET_REG_BIT(MCUCR,MCUCR_ISC01);                 // Set MCUE_ISC01 Bit
        #elif   EXTI_INT0_SENSE_SIGNAL == ON_CHANGE         // Sense Signal is on Change
            SET_REG_BIT(MCUCR,MCUCR_ISC00);                 // Set MCUE_ISC00 Bit
            CLR_REG_BIT(MCUCR,MCUCR_ISC01);                 // Clear MCUE_ISC01 Bit
        #elif   EXTI_INT0_SENSE_SIGNAL == LOW_LEVEL         // Sense Signal is Low Level
            CLR_REG_BIT(MCUCR,MCUCR_ISC00);                 // Clear MCUE_ISC00 Bit
            CLR_REG_BIT(MCUCR,MCUCR_ISC01);                 // Clear MCUE_ISC01 Bit
        #else
            #error   "EXIT_INT0_SENSE_SIGNAL Configuration Error"
        #endif
    SET_REG_BIT(GICR,GICR_INT0);                            // Enable INT0 Interrupt
    #elif     EXTI_INT0_ENABLE == DISABLE                   // INT0 is Disabled
        CLR_REG_BIT(GICR,GICR_INT0);                        // Disable INT0 Interrupt
    #else
        #error "EXTI_INT0_ENABLE Configuration Error"
    #endif
    /*_______________________________________________________________________*/
    /*          Initialize INT1 PIN                                          */
    /* Check IF INT1 is Enabled or Disabled */
    #if     EXTI_INT1_ENABLE == ENABLE                      // INT1 is Enabled
        /* Check for Selected Sense Type Mode */
        #if     EXTI_INT1_SENSE_SIGNAL == FAILING_EDGE      // Sense Signal is Failing Edge
            CLR_REG_BIT(MCUCR,MCUCR_ISC02);                 // Clear MCUR_ISC00 Bit
            SET_REG_BIT(MCUCR,MCUCR_ISC03);                 // Set MCUE_ISC03 Bit
        #elif   EXTI_INT1_SENSE_SIGNAL == RISING_EDGE       // Sense Signal is Rising Edge
            SET_REG_BIT(MCUCR,MCUCR_ISC00);                 // Set MCUE_ISC00 Bit
            SET_REG_BIT(MCUCR,MCUCR_ISC03);                 // Set MCUE_ISC03 Bit
        #elif   EXTI_INT1_SENSE_SIGNAL == ON_CHANGE         // Sense Signal is on Change
            SET_REG_BIT(MCUCR,MCUCR_ISC00);                 // Set MCUE_ISC00 Bit
            CLR_REG_BIT(MCUCR,MCUCR_ISC03);                 // Clear MCUE_ISC03 Bit
        #elif   EXTI_INT1_SENSE_SIGNAL == LOW_LEVEL         // Sense Signal is Low Level
            CLR_REG_BIT(MCUCR,MCUCR_ISC00);                 // Clear MCUE_ISC00 Bit
            CLR_REG_BIT(MCUCR,MCUCR_ISC03);                 // Clear MCUE_ISC03 Bit
        #else
            #error   "EXIT_INT1_SENSE_SIGNAL Configuration Error"
        #endif
    SET_REG_BIT(GICR,GICR_INT1);                            // Enable INT1 Interrupt
    #elif     EXTI_INT1_ENABLE == DISABLE                   // INT1 is Disabled
        CLR_REG_BIT(GICR,GICR_INT1);                        // Disable INT1 Interrupt
    #else
        #error "EXTI_INT1_ENABLE Configuration Error"
    #endif
    /*_______________________________________________________________________*/
    /*          Initialize INT2 PIN                                          */
    /* Check IF INT2 is Enabled or Disabled */
    #if     EXTI_INT2_ENABLE == ENABLE                      // INT2 is Enabled
        /* Check for Selected Sense Type Mode */
        #if     EXTI_INT2_SENSE_SIGNAL == FAILING_EDGE      // Sense Signal is Failing Edge
            CLR_REG_BIT(MCUCSR,MCUCSR_ISC2);                // Clear MCUR_ISC00 Bit
        #elif   EXTI_INT2_SENSE_SIGNAL == RISING_EDGE       // Sense Signal is Rising Edge
            SET_REG_BIT(MCUCSR,MCUCSR_ISC2);                // Set MCUCSR_ISC2 Bit
        #else
            #error   "EXIT_INT2_SENSE_SIGNAL Configuration Error"
        #endif
    SET_REG_BIT(GICR,GICR_INT2);                            // Enable INT2 Interrupt
    #elif     EXTI_INT2_ENABLE == DISABLE                   // INT2 is Disabled
        CLR_REG_BIT(GICR,GICR_INT2);                        // Disable INT2 Interrupt
    #else
        #error "EXTI_INT2_ENABLE Configuration Error"
    #endif
}

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
void MEXTI_voidInterruptControl(u8 Copy_u8InterruptID, u8 Copy_u8InterruptState)
{
    /* Checking Interrupt ID */
    switch(Copy_u8InterruptID)
    {
        case INT0:                                      // INT0 Selected ID
            /* Checking Interrupt State */
            switch (Copy_u8InterruptState)
            {
            case ENABLE:                                // INT0 ENABLE
                SET_REG_BIT(GICR,GICR_INT0);            // Set GICR_INT0 Bit
            break;
            case DISABLE:                               // INT0 DISABLE
                CLR_REG_BIT(GICR,GICR_INT0);            // Clear GICR_INT0 Bit
            break;
            }
        case INT1:                                      // INT1 Selected ID
            /* Checking Interrupt State */
            switch (Copy_u8InterruptState)
            {
            case ENABLE:                                // INT1 ENABLE
                SET_REG_BIT(GICR,GICR_INT1);            // Set GICR_INT0 Bit
            break;
            case DISABLE:                               // INT1 DISABLE
                CLR_REG_BIT(GICR,GICR_INT1);            // Clear GICR_INT0 Bit
            break;
            }
        case INT2:                                      // INT2 Selected ID
            /* Checking Interrupt State */
            switch (Copy_u8InterruptState)
            {
            case ENABLE:                                // INT2 ENABLE
                SET_REG_BIT(GICR,GICR_INT2);            // Set GICR_INT2 Bit
            break;
            case DISABLE:                               // INT2 DISABLE
                CLR_REG_BIT(GICR,GICR_INT2);            // Clear GICR_INT2 Bit
            break;
            }
    }
}

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
void MEXTI_voidInterruptSenseSignal(u8 Copy_u8InterruptID, u8 Copy_u8SenseSignal)
{
    switch (Copy_u8InterruptID)
    {
    case INT0:                                          // INT0 Selected ID
        switch(Copy_u8SenseSignal)
        {
            case LOW_LEVEL:                             // LOW LEVEL Selected Sense Signal
                CLR_REG_BIT(MCUCR, MCUCR_ISC00);        // Clear MCUCR_ISC00 Bit
                CLR_REG_BIT(MCUCR, MCUCR_ISC01);        // Clear MCUCR_ISC01 Bit
            break;
            case ON_CHANGE:                             // ON CHANGE Selected Sense Signal
                SET_REG_BIT(MCUCR, MCUCR_ISC00);        // Set MCUCR_ISC00 Bit
                CLR_REG_BIT(MCUCR, MCUCR_ISC01);        // Clear MCUCR_ISC01 Bit
            break;
            case FAILING_EDGE:                          // FAILING EDGE Selected Sense Signal
                CLR_REG_BIT(MCUCR, MCUCR_ISC00);        // Clear MCUCR_ISC00 Bit
                SET_REG_BIT(MCUCR, MCUCR_ISC01);        // Set MCUCR_ISC00 Bit
            break;
            case RISING_EDGE:                           // RISING EDGE Selected Sese Signal
                SET_REG_BIT(MCUCR, MCUCR_ISC00);        // Set MCUCR_ISC00 Bit
                SET_REG_BIT(MCUCR, MCUCR_ISC01);        // Set MCUCR_ISC01 Bit
            break;
        }
    break;
    case INT1:                                          // INT1 Selected ID
        switch(Copy_u8SenseSignal)
        {
            case LOW_LEVEL:                             // LOW LEVEL Selected Sense Signal
                CLR_REG_BIT(MCUCR, MCUCR_ISC02);        // Clear MCUCR_ISC02 Bit
                CLR_REG_BIT(MCUCR, MCUCR_ISC03);        // Clear MCUCR_ISC03 Bit
            break;
            case ON_CHANGE:                             // ON CHANGE Selected Sense Signal
                SET_REG_BIT(MCUCR, MCUCR_ISC02);        // Set MCUCR_ISC02 Bit
                CLR_REG_BIT(MCUCR, MCUCR_ISC03);        // Clear MCUCR_ISC03 Bit
            break;
            case FAILING_EDGE:                          // FAILING EDGE Selected Sense Signal
                CLR_REG_BIT(MCUCR, MCUCR_ISC02);        // Clear MCUCR_ISC02 Bit
                SET_REG_BIT(MCUCR, MCUCR_ISC03);        // Set MCUCR_ISC03 Bit
            break;
            case RISING_EDGE:                           // RISING EDGE Selected Sese Signal
                SET_REG_BIT(MCUCR, MCUCR_ISC02);        // Set MCUCR_ISC02 Bit
                SET_REG_BIT(MCUCR, MCUCR_ISC03);        // Set MCUCR_ISC03 Bit
            break;
        }
    break;
    case INT2:                                          // INT2 Selected ID
        switch(Copy_u8SenseSignal)
        {
            case FAILING_EDGE:                          // FAILING EDGE Selected Sense Signal
                CLR_REG_BIT(MCUCSR,MCUCSR_ISC2);        // Clear MCUCSR_ISC2 Bit
            break;
            case RISING_EDGE:                           // RISING EDGE Selected Sese Signal
                SET_REG_BIT(MCUCSR,MCUCSR_ISC2);        // Set MCUCSR_ISC2 Bit
            break;
        }
    }
}


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
void MEXTI_voidSetINT0CallBack(void(*Copy_pvNotificationFunction)(void))
{
    Global_pvINT0CallBackFunction = Copy_pvNotificationFunction;
}

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
void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void)
{
    if(Global_pvINT0CallBackFunction != NULL)
    {
        Global_pvINT0CallBackFunction();
    }
    else
    {
        /*Do Nothing*/
    }
}

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
void MEXTI_voidSetINT1CallBack(void(*Copy_pvNotificationFunction)(void))
{
    Global_pvINT1CallBackFunction = Copy_pvNotificationFunction;
}

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
void __vector_2 (void)  __attribute__((signal));
void __vector_2 (void)
{
    if(Global_pvINT1CallBackFunction != NULL)
    {
        Global_pvINT1CallBackFunction();
    }
    else
    {
        /*Do Nothing*/
    }
}

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
void MEXTI_voidSetINT2CallBack(void(*Copy_pvNotificationFunction)(void))
{
    Global_pvINT2CallBackFunction = Copy_pvNotificationFunction;
}





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
void __vector_3 (void)  __attribute__((signal));
void __vector_3 (void)
{
    if(Global_pvINT2CallBackFunction != NULL)
    {
        Global_pvINT2CallBackFunction();
    }
    else
    {
        /*Do Nothing*/
    }
}