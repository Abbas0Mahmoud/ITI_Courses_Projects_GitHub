/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                      		Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          		:   Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	BM Driver                             							  	          */
/*  Project Description    :	BM Driver for STM32F10x Family                             				      */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	BM_private.h                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
/*---------------------------------------------------------------------------------------*/
#ifndef BM_PRIVATE_H_
#define BM_PRIVATE_H_
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */

/*		TimeOut Value Definition		*/
#define BOOT_CHECK_TIME_OUT_IN_SECONDS          15U

/*      Flags Status        */
#define FLAG_ACTIVE          1
#define FLAG_NOT_ACTIVE      0

/*      Check Flags Return Options      */
#define JUMP_TO_BL                    1
#define JUMP_TO_APP                   2

/*		Half Word Empty Flash Location Value		*/
#define FLASH_EMPTY_HALF_WORD_LOCATION_VALUE  	(u16)0xFFFF

/*		BootManager Peripherals Initialization Conditions Definition		*/
#define INIT_IS_SET  			            	1
#define INIT_NOT_SET  		            		(!INIT_IS_SET)
#define USARTSTARTCHARACTER						'C'

typedef void(*CallAPP_t)(void);
/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Global Declarations       		     		          	  	  	      */
/* ---------------------------------------------------------------------------------------------------------- */
static volatile u8 GU8_InitFlag = INIT_NOT_SET;
union
{
    volatile u8 INIT_BM_FLAGS;
    struct
    {
        volatile u8 BootSwitchFlag  	  : 1;
        volatile u8 BootTimeOutFlag 	  : 1;
        volatile u8 BootUARTFlag    	  : 1;
        volatile u8 BootSharedUpdateFlag  : 1;
        volatile u8 BootValidAppFlag   	  : 1;
		volatile u8 BootJumpFlag		  : 2;
        volatile u8 NoJumpFlag        	  : 1;
    };
}BM_FLAGS;
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
static void MBM_voidInit(void);
/*_________________________________________________________________________________________________*/

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
static void MBM_voidUpdateBootSwitchFlag(void);
/*_________________________________________________________________________________________________*/

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
static void MBM_voidUpdateTimeoutFlag(void);
/*_________________________________________________________________________________________________*/

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
static void MBM_voidUpdateSharedupdateFlag(void);
/*_________________________________________________________________________________________________*/

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
static void MBM_voidUpdateBootValidAppFlag(void);
/*_________________________________________________________________________________________________*/

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
static void MBM_voidDeinit(void);
/*_________________________________________________________________________________________________*/

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
static void MBM_voidCheckBootFlags(void);
/*_________________________________________________________________________________________________*/

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
static void MBM_voidJumpToAPP(void);
/*_________________________________________________________________________________________________*/

#endif /* BM_PRIVATE_H_ */
