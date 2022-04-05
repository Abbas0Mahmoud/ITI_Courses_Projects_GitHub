/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	SPI Driver                             							  	          */
/*  Project Description    :	SPI Driver                                                 				      */
/*  Target Controller 	   :	Atmega 32                                               					  */
/*  File Name              :	SPI_interface.h                                    						      */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
#ifndef     SPI_PRIVATE_H
#define 	SPI_PRIVATE_H

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Registers Definitions       		     		          	  	              */
/* ---------------------------------------------------------------------------------------------------------- */


#define     SPCR                            *((volatile u8 *)0X2D)                       // SPI Control Register
#define     SPCR_SPR0                       0                                            // Bit 0 - SPR0: SPI Clock Rate Select 0
#define     SPCR_SPR1                       1                                            // Bit 1 - SPR0: SPI Clock Rate Select 1
#define     SPCR_CPHA                       2                                            // Bit 2 – CPHA: Clock Phase
#define     SPCR_CPOL                       3                                            // Bit 3 – CPOL: Clock Polarity
#define     SPCR_MSTR                       4                                            // Bit 4 – MSTR: Master/Slave Select
#define     SPCR_DORD                       5                                            // Bit 5 – DORD: Data Order
#define     SPCR_SPE                        6                                            // Bit 6 – SPE: SPI Enabl
#define     SPCR_SPIE                       7                                            // Bit 7 – SPIE: SPI Interrupt Enable

/*_______________________________________________________________________________________*/

#define     SPSR                            *((volatile u8 *)0X2E)                       // SPI Status Register
#define     SPSR_SPI2X                      0                                            // Bit 0 – SPI2X: Double SPI Speed Bit
#define     SPSR_WCOL                       6                                            // Bit 6 – WCOL: Write COLlision Flag
#define     SPSR_SPIF                       7                                            // Bit 7 – SPIF: SPI Interrupt Flag

/*_______________________________________________________________________________________*/

#define     SPDR                            *((volatile u8 *)0X2F)                       // SPI Data Register – SPDR

/*_______________________________________________________________________________________*/

#define     SPCR_PRESCALER_MASKING          0b11111100                                   // SPI Clock Setting Bits Masking Value

/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Global Declerations       		     		          	  	  	      */
/* ---------------------------------------------------------------------------------------------------------- */


/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Prototypes       		     		          	  		      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Implementations       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

#endif