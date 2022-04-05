/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  						      */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	FPEC Driver                             							  	      */
/*  Project Description    :	FPEC Driver for STM32F10x Family                             				  */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	FPEC_program.c                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Preprocessor Directives        		     		          	  	      */
/* ---------------------------------------------------------------------------------------------------------- */

/*		                        Library Inclusions								         */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*_______________________________________________________________________________________*/

/*		                        HAL Layer Inclusion							             */

/*_______________________________________________________________________________________*/

/*		                        MCAL Layer Inclusion					                 */

/*_______________________________________________________________________________________*/

/*		                        Self Files Inclusions							         */
#include "FPEC_config.h"
#include "FPEC_interface.h"
#include "FPEC_private.h"
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Global Declerations       		     		          	  	  	      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Function Implementations       		     		          	  		  */
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
static void MFPEC_voidUnlockFlash(void)
{
	if(FPEC->CR_BITS.LOCK == 1)
	{
		FPEC->KEYR = KEY1;
		FPEC->KEYR = KEY2;
	}
}
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
void MFPEC_voidWriteFlash(u32 Copy_pu32FlashAddress,u16 * Copy_pu16Data,u8 Copy_u8DataLength)
{
	/*		Function Local Scope Decleration		*/
	u8 Local_u8LoopCounter;
	/*		Waiting until ongoing Operation is Done		*/
	while(FPEC->SR_BITS.BSY == 1);
	/*		Apply Unlock Sequence to Open FPEC Block		*/
	MFPEC_voidUnlockFlash();
	for(Local_u8LoopCounter = 0;Local_u8LoopCounter <= Copy_u8DataLength;Local_u8LoopCounter++)
	{
		/*		Set Program Operation Bit		*/
		SET_BIT(FPEC->CR,CR_PG_BIT);
		/*
		Hints:
		_The main Flash memory can be programmed 16 bits at a time
		_The program operation is started when the CPU writes a half-word,
		into a main Flash memory address with the PG bit of the FLASH_CR register set,
		Explanation with Page0 :
		_Page 0 Start Address :0x0800 0000 - Page0 End Address :0x0800 03FF / This Gives 1Kbyte (1024 Byte) of Space
		_Desired Address is Assigned to Pointer that pointes to u16 (16 Bits) data(2 Byte Step / Half Word),
		with that half word access write at time is accomplished

		_*((volatile u16 *)Copy_pu32FlashAddress) = Copy_pu16Data[Local_u8LoopCounter];
		_This Expands to :
		_ volatile u16 * pointer = Copy_pu32FlashAddress;
		_*pointer = Copy_pu16Data[Local_u8LoopCounter];

		_why voatile :
		_Because Copy_pu32FlashAddress will accessed so many times within each write operation so to prevent,
		_optimizer from moving this value to GPRs
		 */
		*((volatile u16 *)Copy_pu32FlashAddress) = Copy_pu16Data[Local_u8LoopCounter];
		/*
		_Increment with 2 Because writing operation occurs at 2Bytes at a time so,
		_Copy_pu32FlashAddress should be updated to point to the byte following the updated 2bytes
		*/
		Copy_pu32FlashAddress += 2;
		/*		Waiting until ongoing Operation is Done		*/
		while(FPEC->SR_BITS.BSY == 1);
		/*		Clear End of Operation Flag		*/
		SET_BIT(FPEC->SR,SR_EOP_BIT);
		/*		Clear Program Operation Bit		*/
		CLR_BIT(FPEC->CR,CR_PG_BIT);
	}
}
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
void MFPEC_voidEraseFlashPageByAddress(u32 * Copy_pu32PageAddress)
{
	/*		Waiting until ongoing Operation is Done		*/
	while(FPEC->SR_BITS.BSY == 1);
	/*		Apply Unlock Sequence to Open FPEC Block		*/
	MFPEC_voidUnlockFlash();
	/*		Set Page Erase Operation Bit		*/
	SET_BIT(FPEC->CR,CR_PER_BIT);
	/*		Assign Page Base Address to Flash Address Register		*/
	FPEC->AR = (u32)Copy_pu32PageAddress;
	/*		Enable Erase Operation		*/
	SET_BIT(FPEC->CR,CR_STRT_BIT);
	/*		Waiting until ongoing Operation is Done		*/
	while(FPEC->SR_BITS.BSY == 1);
	/*		Clear End of Operation Flag		*/
	SET_BIT(FPEC->SR,SR_EOP_BIT);
	/*		Clear Page Erase Operation Bit		*/
	CLR_BIT(FPEC->CR,CR_PER_BIT);
}
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
void MFPEC_voidEraseFlashPageByNumber(u8 Copy_u8PageNumber)
{
	if(Copy_u8PageNumber < FLASH_MAX_PAGES_NUM)
	{
		/*		Waiting until ongoing Operation is Done		*/
		while(FPEC->SR_BITS.BSY == 1);
		/*		Apply Unlock Sequence to Open FPEC Block		*/
		MFPEC_voidUnlockFlash();
		/*		Set Page Erase Operation Bit		*/
		SET_BIT(FPEC->CR,CR_PER_BIT);
		/*		Assign Page Base Address to Flash Address Register		*/
		FPEC->AR = (u32)(PAGEOFFSET(Copy_u8PageNumber)) + PAGE0_BASE_ADDRESS;
		/*		Enable Erase Operation		*/
		SET_BIT(FPEC->CR,CR_STRT_BIT);
		/*		Waiting until ongoing Operation is Done		*/
		while(FPEC->SR_BITS.BSY == 1);
		/*		Clear End of Operation Flag		*/
		SET_BIT(FPEC->SR,SR_EOP_BIT);
		/*		Clear Page Erase Operation Bit		*/
		CLR_BIT(FPEC->CR,CR_PER_BIT);
	}
	else
	{
		/*	Error	*/
	}
}
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
void MFPEC_voidEraseFlashPagesInRange(u8 Copy_u8StartPage,u8 Copy_u8EndPage)
{
	/*		Function Local Scope Decleration		*/
	u8 Local_u8LoopCounter;
	/*		Waiting until ongoing Operation is Done		*/
	while(FPEC->SR_BITS.BSY == 1);
	/*		Apply Unlock Sequence to Open FPEC Block		*/
	MFPEC_voidUnlockFlash();
	/*		Set Page Erase Operation Bit		*/
	SET_BIT(FPEC->CR,CR_PER_BIT);
	/*		Pages Iteration Loop		*/
	for(Local_u8LoopCounter = Copy_u8StartPage;Local_u8LoopCounter <= Copy_u8EndPage;Local_u8LoopCounter++)
	{
		/*		Assign Page Base Address to Flash Address Register		*/
		FPEC->AR = (u32)(PAGEOFFSET(Local_u8LoopCounter)) + PAGE0_BASE_ADDRESS;
		/*		Enable Erase Operation		*/
		SET_BIT(FPEC->CR,CR_STRT_BIT);
		/*		Waiting until ongoing Operation is Done		*/
		while(FPEC->SR_BITS.BSY == 1);
		/*		Clear End of Operation Flag		*/
		SET_BIT(FPEC->SR,SR_EOP_BIT);
	}
	/*		Clear Page Erase Operation Bit		*/
		CLR_BIT(FPEC->CR,CR_PER_BIT);
}
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
void MFPEC_voidEraseFlash()
{
	MFPEC_voidReadFlashLock();
	while(FPEC->SR_BITS.BSY == 1);
	SET_BIT(FPEC->CR,CR_MER_BIT);
	SET_BIT(FPEC->CR,CR_STRT_BIT);
	while(FPEC->SR_BITS.BSY == 1);
}
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
/* ________________________________________________________________________________________________ */
