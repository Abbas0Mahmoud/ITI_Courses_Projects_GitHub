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
#include "../../../Inc/LIB/Std_Types.h"
#include "../../../Inc/LIB/BIT_MATH.h"
/*_______________________________________________________________________________________*/

/*		                        HAL Layer Inclusion							             */

/*_______________________________________________________________________________________*/

/*		                        MCAL Layer Inclusion					                 */

/*_______________________________________________________________________________________*/

/*		                        Self Files Inclusions							         */
#include "../../../Inc/MCAL/FPEC/FPEC_config.h"
#include "../../../Inc/MCAL/FPEC/FPEC_interface.h"
#include "../../../Inc/MCAL/FPEC/FPEC_private.h"
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Global Declarations       		     		          	  	  	      */
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
	/*		Function Local Scope Declaration		*/
	FPECErrorStatus_t Local_ErrorStatus;
	static u8 Local_u8PageNumber;
	u8 Local_u8LoopCounter;
	/*		Function Local Scope Initialization		*/
	Local_ErrorStatus = NoError;
	Local_u8PageNumber = 0;
	/*		Checking for Current Address Page Number		*/
	if(MFPEC_u8GetPageNumber(Copy_pu32FlashAddress) != Local_u8PageNumber)
	{
		/*		Updating Page Number with Current Page Address Number		*/
		Local_u8PageNumber = MFPEC_u8GetPageNumber(Copy_pu32FlashAddress);
		/*		Erasing Current Page 		*/
		Local_ErrorStatus = MFPEC_FPECErrorStatusEraseFlashPageNumber(Local_u8PageNumber);
	}
	/*		Checking for ErrorStatus		*/
	if(Local_ErrorStatus == NoError)
	{
		for(Local_u8LoopCounter = 0;Local_u8LoopCounter < Copy_u8DataLength;Local_u8LoopCounter++)
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

			_why volatile :
			_Because Copy_pu32FlashAddress will accessed so many times within each write operation so to prevent,
			_optimizer from moving this value to GPRs
			*/
			*((volatile u16 *)Copy_pu32FlashAddress) = *(Copy_pu16Data+Local_u8LoopCounter);
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
	/*		Function Local Scope Declaration		*/
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
		FPEC->AR = Copy_u32PageAddress;
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
	/*		Checking for Input Page Number In Flash Pages Range		*/
	if((Copy_u8PageNumber >= FIRST_PAGE_INDEX) && (Copy_u8PageNumber < FLASH_MAX_PAGES_NUM))
	{
		/*		Waiting until ongoing Operation is Done		*/
		while(FPEC->SR_BITS.BSY == 1);
		/*		Apply Unlock Sequence to Open FPEC Block		*/
		Local_ErrorStatus =  MFPEC_FPECErrorStatusUnlockFlash();
		if(Local_ErrorStatus == NoError)
		{
			/*		Waiting until ongoing Operation is Done		*/
			while(FPEC->SR_BITS.BSY == 1);
			/*		Apply Unlock Sequence to Open FPEC Block		*/
			//MFPEC_voidUnlockFlash();
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
FPECErrorStatus_t MFPEC_FPECErrorStatusEraseFlashPagesInRange(u8 Copy_u8StartPageNumber,u8 Copy_u8EndPageNumber)
{
	/*		Function Local Scope Declaration		*/
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
static FPECErrorStatus_t  MFPEC_FPECErrorStatusUnlockFlash(void)
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
			Local_ErrorStatus = FPEC_FailedToErasePageError;
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
	/*		Function Local Scope Declaration		*/
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

