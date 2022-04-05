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
FPECErrorStatus_t MFPEC_FPECErrorStatus_WriteFlash(u32 Copy_pu32FlashAddress,u16 * Copy_pu16Data,u8 Copy_u8DataLength)
{
	/*		Function Local Scope Decleration		*/
	FPECErrorStatus_t Local_ErrorStatus = NoError;
	u8 Local_u8PageNumber;
	u8 Local_u8LoopCounter;
	/*		Waiting until ongoing Operation is Done		*/
	while(FPEC->SR_BITS.BSY == 1);
	/*		Apply Unlock Sequence to Open FPEC Block		*/
	Local_ErrorStatus =  MFPEC_FPECErrorStatusUnlockFlash();
	if(Local_ErrorStatus == NoError)
	{
		/*		Getting Current Page Number of The Given Address	*/
		Local_u8PageNumber = MFPEC_u8GetPageNumber(Copy_pu32FlashAddress);
		for(Local_u8LoopCounter = 0;Local_u8LoopCounter < Copy_u8DataLength;Local_u8LoopCounter++)
		{
			/*		Checking if Address Counter Reached Page End Address		*/
			if(Copy_pu32FlashAddress == ((u32)PAGEOFFSET(Local_u8PageNumber) + PAGE0_END_ADDRESS))
			{
				/*		Updating Page Counter		*/
				Local_u8PageNumber += 1;
				/*		Setting Page Counter to New (Next) Page Base Address		*/
				Copy_pu32FlashAddress = ((u32)PAGEOFFSET(Local_u8PageNumber) + PAGE0_BASE_ADDRESS);
			}
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
			/*		Checking Successful Program Operation		*/
			if(FPEC->SR_BITS.EOP == 1)
			{
				/*		Clear End of Operation Flag		*/
				SET_BIT(FPEC->SR,SR_EOP_BIT);
				/*		Clear Program Operation Bit		*/
				CLR_BIT(FPEC->CR,CR_PG_BIT);
			}
			else
			{
				/*		Checking for Programming Error		*/
				if(FPEC->SR_BITS.PGERR == 1)
				{
					Local_ErrorStatus = FPEC_ProgrammingError;
				}/*		Checking for Write Protection Error		*/
				else if(FPEC->SR_BITS.WRPRTERR == 1)
				{
					Local_ErrorStatus = FPEC_WriteProtectionError;
				}
			}
		}
	}
	return Local_ErrorStatus;
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
FPECErrorStatus_t MFPEC_FPECErrorStatusEraseFlashPageAddress(u32 Copy_u32PageAddress)
{
	/*		Function Local Scope Decleration		*/
	FPECErrorStatus_t Local_ErrorStatus = NoError;
	/*		Waiting until ongoing Operation is Done		*/
	while(FPEC->SR_BITS.BSY == 1);
	/*		Apply Unlock Sequence to Open FPEC Block		*/
	Local_ErrorStatus =  MFPEC_FPECErrorStatusUnlockFlash();
	if(Local_ErrorStatus == NoError)
	{
		/*		Set Page Erase Operation Bit		*/
		SET_BIT(FPEC->CR,CR_PER_BIT);
		/*		Assign Page Base Address to Flash Address Register		*/
		FPEC->AR = (u32)Copy_u32PageAddress;
		/*		Enable Erase Operation		*/
		SET_BIT(FPEC->CR,CR_STRT_BIT);
		/*		Waiting until ongoing Operation is Done		*/
		while(FPEC->SR_BITS.BSY == 1);
		/*		Checking Successful Program Operation		*/
		if(FPEC->SR_BITS.EOP == 1)
		{
			/*		Clear End of Operation Flag		*/
			SET_BIT(FPEC->SR,SR_EOP_BIT);
			/*		Clear Page Erase Operation Bit		*/
			CLR_BIT(FPEC->CR,CR_PER_BIT);
		}
		else
		{
			Local_ErrorStatus = MFPEC_FPECErrorStatusCheckErasedPage(Copy_u32PageAddress);
		}
	}
	return Local_ErrorStatus;
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
FPECErrorStatus_t MFPEC_FPECErrorStatusEraseFlashPageNumber(u8 Copy_u8PageNumber)
{
	/*		Function Local Scope Decleration		*/
	FPECErrorStatus_t Local_ErrorStatus = NoError;
	if((Copy_u8PageNumber >= FIRST_PAGE_INDEX) && (Copy_u8PageNumber < FLASH_MAX_PAGES_NUM))
	{
		/*		Waiting until ongoing Operation is Done		*/
		while(FPEC->SR_BITS.BSY == 1);
		/*		Apply Unlock Sequence to Open FPEC Block		*/
		MFPEC_voidUnlockFlash();
		/*		Set Page Erase Operation Bit		*/
		SET_BIT(FPEC->CR,CR_PER_BIT);
		/*		Assign Page Base Address to Flash Address Register		*/
		FPEC->AR = ((u32)(PAGEOFFSET(Copy_u8PageNumber)) + PAGE0_BASE_ADDRESS);
		/*		Enable Erase Operation		*/
		SET_BIT(FPEC->CR,CR_STRT_BIT);
		/*		Waiting until ongoing Operation is Done		*/
		while(FPEC->SR_BITS.BSY == 1);
		/*		Checking Successful Program Operation		*/
		if(FPEC->SR_BITS.EOP == 1)
		{
			/*		Clear End of Operation Flag		*/
			SET_BIT(FPEC->SR,SR_EOP_BIT);
			/*		Clear Page Erase Operation Bit		*/
			CLR_BIT(FPEC->CR,CR_PER_BIT);
		}
		else
		{
			Local_ErrorStatus = MFPEC_FPECErrorStatusCheckErasedPage(((u32)(PAGEOFFSET(Copy_u8PageNumber)) + PAGE0_BASE_ADDRESS));
		}
	}
	else
	{
		Local_ErrorStatus = OutofRange;
	}
	return Local_ErrorStatus;
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
void MFPEC_voidEraseFlashPagesInRange(u8 Copy_u8StartPageNumber,u8 Copy_u8EndPageNumber)
{
	/*		Function Local Scope Decleration		*/
	FPECErrorStatus_t Local_ErrorStatus = NoError;
	u8 Local_u8LoopCounter;
	/*		Pages Iteration Loop		*/
	for(Local_u8LoopCounter = Copy_u8StartPageNumber;Local_u8LoopCounter <= Copy_u8EndPageNumber;Local_u8LoopCounter++)
	{
		Local_ErrorStatus = MFPEC_FPECErrorStatusEraseFlashPageNumber(Local_u8LoopCounter);
		if(Local_ErrorStatus != NoError)
		{
			break;
		}
	}
	return Local_ErrorStatus;
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

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Implementations       		     		          	  		  */
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
static FPECErrorStatus_t MFPEC_FPECErrorStatusUnlockFlash(void)
{
	/*		Function Local Scope Decleration		*/
	FPECErrorStatus_t Local_ErrorStatus = NoError;
	if(FPEC->CR_BITS.LOCK == 1)
	{
		FPEC->KEYR = KEY1;
		FPEC->KEYR = KEY2;
		if(FPEC->CR_BITS.LOCK == 1)
		{
			// Failed to Unlock FPEC
			Local_ErrorStatus = FPEC_UnlockFailedError;
		}
	}
	//	No Error: FPEC is Unlocked
	return Local_ErrorStatus;
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
static FPECErrorStatus_t MFPEC_FPECErrorStatusCheckErasedPage(u32 Copy_u32ErasedPageAddress)
{
	/*		Function Local Scope Decleration		*/
	FPECErrorStatus_t Local_ErrorStatus = NoError;
	u8 Local_u8LoopCounter;
	for(Local_u8LoopCounter = 0;Local_u8LoopCounter < FLASH_MAX_PAGES_NUM;Local_u8LoopCounter++)
	{
		if((*(volatile u16 *)Copy_u32ErasedPageAddress) != FLASH_EMPTY_ADDRESS_VALUE)
		{
			// return unerased address
			// return error
			Local_ErrorStatus = FPEC_UnerasedPageError;
		}
		Copy_u32ErasedPageAddress += 2;
	}
	return Local_ErrorStatus;
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
static u8 MFPEC_u8GetPageNumber(u32 Copy_u32PageAddress)
{
	/*		Function Local Scope Decleration		*/
	u8 Local_u8LoopCounter;
	for(Local_u8LoopCounter = 0;Local_u8LoopCounter < FLASH_MAX_PAGES_NUM;Local_u8LoopCounter++)
	{
		if(((PAGE0_END_ADDRESS + (u32)PAGEOFFSET(Local_u8LoopCounter)) - Copy_u32PageAddress) < PAGE_SIZE_IN_BYTES)
		{
            break;
		}
	}
	return Local_u8LoopCounter ;
}
/* ________________________________________________________________________________________________ */
