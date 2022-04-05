/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	SCB Driver                             							  	          */
/*  Project Description    :	SCB Driver for STM32F10x Family                             				  */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	SCB_private.h                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                              */
#ifndef SCB_PRIVATE_H_
#define SCB_PRIVATE_H_

/* ---------------------------------------------------------------------------------------------------------- */
/*                           		        Registers Definitions       		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/*      System control block (SCB)      */
/*      Pointer to struct and Initialized to SCB Base Address       */
#define SCB ((volatile SCB_t *)0xE000ED00)
/*      System control block (SCB) Registers Struct     */
typedef struct
{
    /*      CPUID base register (SCB_CPUID)     */
    u32 CPIUD;
    /*      Interrupt control and state register (SCB_ICSR)     */
    u32 ICSR;
    /*      Vector table offset register (SCB_VTOR)     */
    u32 VTOR;
    /*      Application interrupt and reset control register (SCB_AIRCR)        */
    u32 AIRCR;
    /*      System control register (SCB_SCR)       */
    u32 SCR;
    /*      Configuration and control register (SCB_CCR)        */
    u32 CCR;
    /*      System handler priority register 1 (SCB_SHPR1)      */
    u32 SHPR1;
    /*      System handler priority register 2 (SCB_SHPR2)      */
    u32 SHPR2;
    /*      System handler priority register 3 (SCB_SHPR3)      */
    u32 SHPR3;
    /*      System handler control and state register (SCB_SHCSR)       */
    u32 SHCRS;
    /*      Configurable fault status register (SCB_CFSR)       */
    u32 CFSR;
    /*      Hard fault status register (SCB_HFSR)       */
    u32 HFSR;
    /*      Reserved Location in Memory (Gap Between HFSR Address and MMAR Address)     */
    u32 RESERVED;
    /*      Memory management fault address register (SCB_MMFAR)        */
    u32 MMFAR;
    /*      Bus fault address register (SCB_BFAR)       */
    u32 BFAR;
}SCB_t;

/* ---------------------------------------------------------------------------------------------------------- */
/*                           		        Private Definitions       		     		          	  	      */
/* ---------------------------------------------------------------------------------------------------------- */


/*                      	Application interrupt and reset control register (SCB_AIRCR)	     		      */
/* ---------------------------------------------------------------------------------------------------------- */
/*      Register Bits Definition        */
#define VECTRESET_BIT                0
#define VECTCLRACTIVE_BIT            1
#define SYSRESETREQ_BIT              2
#define PRIGROUP_BIT0                8
#define ENDIANESS_BIT                15
#define VECTKEYSTSTAT_BIT0           16
/*      Key Value to Enable Writing to Register     */
#define VECT_KEY_VALUE               0X05FA
/*      NVIC Priority Grouping Bits Mask Value     */
#define GROUP_PRIORITY_BITS_MASK     (~(7<<PRIGROUP_BIT0))

/* ---------------------------------------------------------------------------------------------------------- */
/*                           		     Private Functions Prototypes       		     		          	  */
/* ---------------------------------------------------------------------------------------------------------- */
u8 Global_MSCB_To_MNVIC_u8GroupPolicy = 0;

#endif /* SCB_PRIVATE_H_ */
