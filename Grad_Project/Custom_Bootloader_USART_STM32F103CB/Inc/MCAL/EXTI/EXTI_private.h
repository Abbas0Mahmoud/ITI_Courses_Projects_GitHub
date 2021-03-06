/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  									  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	EXTI Driver                             							  	      */
/*  Project Description    :	EXTI Driver for STM32F10x Family                             				  */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	EXTI_private.h                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Registers Definitions       		     		          	  	              */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Registers BITs Definition       		     		  						  */
/* ---------------------------------------------------------------------------------------------------------- */

#define EXTI_BASE_ADDRESS       0x40010400
#define EXTI                    ((volatile EXTI_t *)EXTI_BASE_ADDRESS)

typedef struct
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    //volatile u32 PR;

    union
    {
        volatile u32 PR;
        struct
        {
            volatile u32 PR0 :1;
            volatile u32 PR1 :1;
            volatile u32 PR2 :1;
            volatile u32 PR3 :1;
            volatile u32 PR4 :1;
            volatile u32 PR5 :1;
            volatile u32 PR6 :1;
            volatile u32 PR7 :1;
            volatile u32 PR8 :1;
            volatile u32 PR9 :1;
            volatile u32 PR10:1;
            volatile u32 PR11:1;
            volatile u32 PR12:1;
            volatile u32 PR13:1;
            volatile u32 PR14:1;
            volatile u32 PR15:1;
            volatile u32 PR16:1;
            volatile u32 PR17:1;
            volatile u32 PR18:1;
            volatile u32 PR19:1;
            volatile u32 Reserved:12;
        }PR_BITS;
    };

}EXTI_t;

/* ---------------------------------------------------------------------------------------------------------- */
/*								Registers' Bits and Masking Values Definitions							  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Pending Register (PR)       		     		  					          */
/* ---------------------------------------------------------------------------------------------------------- */

#define PENDING_FLAGS_RESET_VALUE   0xffffffff

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */

#define ENABLE                      1
#define DISABLE                     0

#define NUM_EXTI_TRIGGER_SIGNSLS    3
#define NUM_EXTI_LINES              16

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Global Declarations       		     		          	  	  	      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Prototypes       		     		          	  		      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------------------------- */
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
/* ----------------------------------------------------------------------------------------------- */
static void (*EXTIn_Handler[NUM_EXTI_LINES])(void) = {NULL};
/*_________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Implementations       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

#endif /* EXTI_PRIVATE_H_ */
