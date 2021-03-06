/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                      		Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          		:   Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	BL Driver                             							  	          */
/*  Project Description    :	BL Driver for STM32F10x Family                             				      */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	BL_private.h                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
/*---------------------------------------------------------------------------------------*/
#ifndef APP_BL_BL_PRIVATE_H_
#define APP_BL_BL_PRIVATE_H_
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */
#define _0_ASCII            '0'
#define _9_ASCII            '9'
#define _A_ASCII            'A'
#define _F_ASCII            'F'
#define _0_ASCII_DECIMAL    48
#define _10_ASCII_DECIMAL   55

#define RECORDTYPE_MSBDIGIT_INDEX       7
#define RECORDTYPE_LSBDIGIT_INDEX       8

#define DATA_RECOED                         0x00
#define END_OF_FILE_RECORD                  0x01
#define EXTENDED_SEGMENT_ADDRESS_RECORD     0x02
#define EXTENDED_LINEAR_ADDRESS_RECORD      0x04
#define START_LINEAR_ADDRESS_RECORD         0x05
/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Global Declarations       		     		          	  	  	      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Prototypes       		     		          	  		      */
/* ---------------------------------------------------------------------------------------------------------- */

#endif /* APP_BL_BL_PRIVATE_H_ */
