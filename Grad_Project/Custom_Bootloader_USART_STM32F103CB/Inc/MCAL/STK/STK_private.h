/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	STK Driver                             							  	          */
/*  Project Description    :	STK Driver for STM32F10x Family                             			      */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	STK_private.h                                    						      */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
/*---------------------------------------------------------------------------------------*/
#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Preprocessor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Registers Definitions       		     		          	  	              */
/* ---------------------------------------------------------------------------------------------------------- */

#define STK_BASE_ADDRESS        (0xE000E010)

#define STK                     ((volatile STK_t *)STK_BASE_ADDRESS)

typedef struct
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;
}STK_t;

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Registers' Bits and Mask Values Definition       		     		          */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Registers BITs Definition       		     		  						  */
/* ---------------------------------------------------------------------------------------------------------- */

/*      CTRL (SysTick Control and Status Register) Register Bits                         */
#define STK_CTRL_COUNTFLAG_BIT      16
#define STK_CTRL_CLKSOURCE_BIT      2
#define STK_CTRL_TICKINT_BIT        1
#define STK_CTRL_ENABLE_BIT         0

/*      CALIB (SysTick calibration value register ) Register Bits                        */
#define STK_CALIB_NOREF_BIT         31
#define STK_CALIB_SKEW_BIT          30

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */

/*      Status Options                                                                   */
#define ENABLE                      1
#define DISABLE                     0

/*      System Timer Clock Source Options                                                */
#define CLK_AHB                     0
#define CLK_AHB_DIV_8               1

/*      System Timer Clock Frequency and Tick Time                                       */
/*      Set SysTick Clock Frequency      */
#if STK_CLK_SOURCE == CLK_AHB
    #define STK_CLK_F       RCC_Clks.AHBClk_F
#elif STK_CLK_SOURCE == CLK_AHB_DIV_8
    #define STK_CLK_F      (RCC_Clks.AHBClk_F/8)
#endif
/*      Set SysTick Tick Time in uS     */
#define STK_TICkTIME_US     ((1/((f64)STK_CLK_F))*(1000000))
/*      Set SysTick Tick Time in mS     */
#define STK_TICKTIME_MS     (((f64)STK_TICkTIME_US)/1000)
/*      Set SysTick Tick Time in S     */
#define STK_TICKTIME_S     (((f64)STK_TICKTIME_MS)/1000)

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Global Declarations       		     		          	  	  	      */
/* ---------------------------------------------------------------------------------------------------------- */

u8 Global_u8SingleFlag = 0;

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Prototypes       		     		          	  		      */
/* ---------------------------------------------------------------------------------------------------------- */

static void (*MSTK_Handler)(void) = NULL;

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Implementations       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */


#endif /* STK_PRIVATE_H_ */
