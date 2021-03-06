/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Main Program Documentation        		     		          	  	  		  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	*                             							  	                  */
/*  Project Description    :	* for STM32F10x Family                             				              */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	main.c                                    							          */
/*  Layer           	   :	*                                             							      */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Main Program Preprocessor Directives        		     		          	  */
/* ---------------------------------------------------------------------------------------------------------- */

/*		                        Library Inclusions								         */
#include "../Inc/LIB/STD_TYPES.h"
/*_______________________________________________________________________________________*/

/*		                        HAL Layer Inclusion							             */

/*_______________________________________________________________________________________*/

/*		                        MCAL Layer Inclusion					                 */

/*_______________________________________________________________________________________*/

/*		                        Self Files Inclusions							         */
#include "../Inc/APP/BM/BM_interface.h"
#include "../Inc/MCAL/USARt/USART_interface.h"
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Main Program Definitions       		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Main Program Global Decelerations       		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Main Program Function Prototypes       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Main Program Function        		     		          	  		          */
/* ---------------------------------------------------------------------------------------------------------- */
s32 main(void)
{
    /*                                  System Setup Code Block                              */
    /*---------------------------------------------------------------------------------------*/

    /*_______________________________________________________________________________________*/
    while(1)
    {
        /*                                System SuperLoop Code Block                            */
        /*---------------------------------------------------------------------------------------*/
    	MBM_voidMainFunction();
    }
    return 0;
}

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Main Program Function Implementations       		     		          	  */
/* ---------------------------------------------------------------------------------------------------------- */
