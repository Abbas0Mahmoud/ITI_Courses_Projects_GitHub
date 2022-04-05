/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	SCB Driver                             							  	          */
/*  Project Description    :	SCB Driver for STM32F10x Family                             				  */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	SCB_interface.h                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                              */
#ifndef SCB_INTERFACE_H_
#define SCB_INTERFACE_H_

/* ---------------------------------------------------------------------------------------------------------- */
/*                           		        Interface Definitions       		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                      	Application interrupt and reset control register (SCB_AIRCR)	     		      */
/* ---------------------------------------------------------------------------------------------------------- */

/*      GROUP POLICY OPTIONS FOR NVIC GROUPING AND SUBGROUPING      */
/*      NVIC - G16S0 : 16 Groups , 0 Subgroups       */
#define NVIC_G16S0      3
/*      NVIC - G8S2  : 8 Groups ,  2 Subgroups       */
#define NVIC_G8S2       4
/*      NVIC - G4S4  : 4 Groups ,  4 Subgroups       */
#define NVIC_G4S4       5
/*      NVIC - G2S8  : 2 Groups ,  8 Subgroups       */
#define NVIC_G2S8       6
/*      NVIC - G0S16 : 0 Groups ,  16 Subgroups      */
#define NVIC_G0S16      7
/* ---------------------------------------------------------------------------------------------------------- */
/*                           		    Interface Function Definitions       		     		          	  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                      	Application interrupt and reset control register (SCB_AIRCR)	     		      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :	MSCB_MNVIC_voidSetNVICGroupPolicy
	Function Return Type        :	void
	Function Description        :	Function to Set Priority Policy(Number of Priority Groups and Sub Groups) for NVIC Module
	Function Arguments          :   Copy_u8GroupPolicy
    Function Arguments Datatype :   (u8 : unsigned char)

	Function Parameters Options :
	_____________________________

    Copy_u8GroupPolicy  :
                            NVIC_G16S0
                            NVIC_G8S2
                            NVIC_G4S4
                            NVIC_G2S8
                            NVIC_G0S16

*/
void MSCB_MNVIC_voidSetNVICGroupPolicy(u8 Copy_u8GroupPolicy);
/*_______________________________________________________________________________________*/

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :   MSCB_u8GetEndianessState
	Function Return Type        :   u8
	Function Description        :   Returns Endianess Bit Value
	Function Arguments          :   void
    Function Arguments Datatype :   void

	Function Parameters Options :
	_____________________________

*/
u8 MSCB_u8GetEndianessState(void);
/*_______________________________________________________________________________________*/


#endif /* SCB_INTERFACE_H_ */