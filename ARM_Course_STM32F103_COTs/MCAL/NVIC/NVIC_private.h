/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	GPIO Driver                             							  	      */
/*  Project Description    :	GPIO Driver for STM32F10x Family                             				  */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	GPIO_private.h                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Registers Definition       		     		          	  	                  */
/* ---------------------------------------------------------------------------------------------------------- */

#define NVIC_BASE_ADDRESS       0xE000E100
#define NVIC                    ((volatile NVIC_t *) NVIC_BASE_ADDRESS)

typedef struct
{

    /* struct Registers for 255 NVIC Pins Register */
    /*
    volatile u32 ISER       [32];
    volatile u32 ICER       [32];
    volatile u32 ISPR       [32];
    volatile u32 ICPR       [32];
    volatile u32 IABR       [32];
    volatile u32 Reserved   [32];
    volatile u8 IPR         [128];
    */

    /*      struct Rgisters for M3 Core NVIC Peripheral     */
    /*      Interrupt set-enable registers (NVIC_ISERx)     */
    volatile u32 ISER       [3];
    volatile u32 ISER_Reserved   [29];
    /*      Interrupt clear-enable registers (NVIC_ICERx)       */
    volatile u32 ICER       [3];
    volatile u32 ICER_Reserved   [29];
    /*      Interrupt set-pending registers (NVIC_ISPRx)        */
    volatile u32 ISPR       [3];
    volatile u32 ISPR_Reserved   [29];
    /*      Interrupt clear-pending registers (NVIC_ICPRx)      */
    volatile u32 ICPR       [3];
    volatile u32 ICPR_Reserved   [29];
    /*      Interrupt active bit registers (NVIC_IABRx)     */
    volatile u32 IABR       [3];
    volatile u32 IABR_Reserved   [29];
    volatile u32 Reserved   [32];
    /*       Interrupt priority registers (NVIC_IPRx)       */
    volatile u8 IPR         [80];

}NVIC_t;

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Registers' Bits and Masking Values Definitions        		     		      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Global Declerations       		     		          	  	  	      */
/* ---------------------------------------------------------------------------------------------------------- */

/*      Variable that Holds Selected Group/Sub Priority     */
extern u8 Global_MSCB_To_MNVIC_u8GroupPolicy;

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Prototypes       		     		          	  		      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Implementations       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

#endif /* NVIC_PRIVATE_H_ */
