/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	FPEC Driver                             							  	      */
/*  Project Description    :	FPEC Driver for STM32F10x Family                             				  */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	FPEC_private.h                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
/*---------------------------------------------------------------------------------------*/
#ifndef FPEC_PRIVATE_H_
#define FPEC_PRIVATE_H_
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Registers Definitions       		     		          	  	              */
/* ---------------------------------------------------------------------------------------------------------- */

/*      Flash Memory Interface Base Address     */
#define FPEC_BASE_ADDRESS       0x40022000
/*      Pointer to struct (FPEC Regiters Bank)       */
#define FPEC                    ((volatile FPEC_t *)FPEC_BASE_ADDRESS)
/*      FPEC struct Registers Bank      */
typedef struct
{
    /*      Flash access control register (FLASH_ACR)       */
    union
    {
        volatile u32 ACR;
        struct
        {
            volatile u32 LATENCY         : 3;
            volatile u32 HLFCYA          : 1;
            volatile u32 PRFTBE          : 1;
            volatile u32 PPRFTBS         : 1;
            volatile u32 RESERVED_B6_B31 : 26;
        }ACR_BITS;
    };
    /*      FPEC key register (FLASH_KEYR)      */
    volatile u32 KEYR;
    /*      Flash OPTKEY register (FLASH_OPTKEYR)       */
    volatile u32 OPTKEYR;
    /*      Flash status register (FLASH_SR)        */
    union
    {
        volatile u32 SR;
        struct
        {
            volatile u32 BSY             : 1;
            volatile u32 RESERVED_B1     : 1;
            volatile u32 PGERR           : 1;
            volatile u32 RESERVED_B3     : 1;
            volatile u32 WRPRTERR        : 1;
            volatile u32 EOP             : 1;
            volatile u32 RESERVED_B6_B31 : 26;
        }SR_BITS;
    };
    /*      Flash control register (FLASH_CR)       */
    union
    {
        volatile u32 CR;
        struct FPEC_private
        {
            volatile u32 PG               : 1;
            volatile u32 PER              : 1;
            volatile u32 MER              : 1;
            volatile u32 RESERVED_B3      : 1;
            volatile u32 OPTPG            : 1;
            volatile u32 OPTER            : 1;
            volatile u32 STRT             : 1;
            volatile u32 LOCK             : 1;
            volatile u32 RESERVED_B8      : 1;
            volatile u32 OPTWRE           : 1;
            volatile u32 EPRIE            : 1;
            volatile u32 RESERVED_B11     : 1;
            volatile u32 EOPIE            : 1;
            volatile u32 RESERVED_B13_B31 : 19;
        }CR_BITS;
    };
    /*      Flash address register (FLASH_AR)       */
    volatile u32 AR;
    /*      Reserved Register Address       */
    volatile u32 Reserved;
    /*      Option byte register (FLASH_OBR)        */
    volatile u32 OBR;
    /*      Write protection register (FLASH_WRPR)      */
    volatile u32 WRPR;
}FPEC_t;

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Register's Bits & Masking Values Definition       		     		          */
/* ---------------------------------------------------------------------------------------------------------- */

/*      Control Register Bits Definition        */
#define CR_PG_BIT                   0
#define CR_PER_BIT                  1
#define CR_MER_BIT                  2
#define CR_STRT_BIT                 6

/*      Status Register Bits Definition     */
#define SR_EOP_BIT                  5

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */

/*      ENABLE / DISABLE Configuration Definitions      */
#define ENABLE                      1
#define DISABLE                     0

/*      Flash Latency Configuration Defnitions      */
#define ZERO_WAIT_STATE             0
#define ONE_WAIT_STATE              1
#define TWO_WAIT_STATE              2

/*      Unlock Sequence keys Definitions        */
#define KEY1                        0x45670123U
#define KEY2                        0xCDEF89ABU

/*      Flash Empty Half Word Value     */
#define FLASH_EMPTY_ADDRESS_VALUE	0xFFFF

/*      Erase Page by Number Private Definitions       */
#define PAGE0_BASE_ADDRESS			0x08000000U
#define PAGE0_END_ADDRESS           0x080003FFU
#define PAGE_SIZE_IN_BYTES			1024
#define FLASH_MAX_PAGES_NUM			128
#define FIRST_PAGE_INDEX            0

/*      Macro Function to Calculate Required Page Number Offset from Page 0 Base Address        */
#define PAGEOFFSET(PAGE_NUM)		(PAGE_NUM*PAGE_SIZE_IN_BYTES)

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Global Declerations       		     		          	  	  	      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Prototypes       		     		          	  		      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------------------ */
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
/* ------------------------------------------------------------------------------------------------ */

/* ________________________________________________________________________________________________ */

/* ------------------------------------------------------------------------------------------------ */
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
/* ------------------------------------------------------------------------------------------------ */
static FPECErrorStatus_t MFPEC_FPECErrorStatusUnlockFlash(void);
/* ________________________________________________________________________________________________ */

/* ------------------------------------------------------------------------------------------------ */
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
/* ------------------------------------------------------------------------------------------------ */
static FPECErrorStatus_t MFPEC_FPECErrorStatusCheckErasedPage(u32 Copy_u32ErasedPageAddress);
/* ________________________________________________________________________________________________ */

/* ------------------------------------------------------------------------------------------------ */
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
/* ------------------------------------------------------------------------------------------------ */
static u8 MFPEC_u8GetPageNumber(u32 Copy_u32PageAddress);
/* ________________________________________________________________________________________________ */

#endif /* FPEC_PRIVATE_H_ */
