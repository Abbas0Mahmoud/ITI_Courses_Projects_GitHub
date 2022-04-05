/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                      		Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	BM Driver                             							  	          */
/*  Project Description    :	BM Driver for STM32F10x Family                             				      */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	BM_program.c                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Preprocessor Directives        		     		          	  	      */
/* ---------------------------------------------------------------------------------------------------------- */

/*		                		Library Inclusions								 	     */
#include "../../../Inc/LIB/STD_TYPES.h"
#include "../../../Inc/LIB/BIT_MATH.h"
#include "../../../Inc/LIB/ERROR_STATUS.h"
/*_______________________________________________________________________________________*/

/*		                		HAL Layer Inclusion							     		 */

/*_______________________________________________________________________________________*/

/*		                		MCAL Layer Inclusion					         		 */
#include "../../../Inc/MCAL/FPEC/FPEC_interface.h"
#include "../../../Inc/MCAL/USART/USART_interface.h"
/*_______________________________________________________________________________________*/

/*		                		Self Files Inclusions							 		 */
#include "../../../Inc/APP/BL/BL_config.h"
#include "../../../Inc/APP/BL/BL_interface.h"
#include "../../../Inc/APP/BL/BL_private.h"
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Function Implementations       		     		          	  		  */
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
void BL_voidMainFunction(void)
{
    u8 Localarr_u8HexRecord[50] = {0};
    u16 Localarr_u16HexDataRecord[20] = {0};
    u8 Local_u8HexRecordType = 0;
    u32 Local_u32HexAppStartAddress = 0;
    u8 Local_u8HexRecordCharacterCount = 0;
    while(1)
    {
        BL_voidReceiveHexRecord(&Localarr_u8HexRecord);
        BL_ErrorStatusDecodeHexRecord(&Localarr_u8HexRecord);
        BL_voidGetRecordType(&Localarr_u8HexRecord,&Local_u8HexRecordType);
        if(Local_u8HexRecordType != END_OF_FILE_RECORD)
        {
            switch(Local_u8HexRecordType)
            {
                case DATA_RECOED:
                    BL_voidGetAddressLowDigits(&Localarr_u8HexRecord,&Local_u32HexAppStartAddress);
                    BL_voidGetCharacterCount(&Localarr_u8HexRecord,&Local_u8HexRecordCharacterCount);
                    BL_voidGetDataRecord(&Localarr_u8HexRecord,&Localarr_u8HexRecord,&Local_u8HexRecordCharacterCount);
                    MFPEC_FPECErrorStatus_WriteFlash(Local_u32HexAppStartAddress,Localarr_u16HexDataRecord,Local_u8HexRecordCharacterCount);
                    BL_voidConfirmReceivedHexRecord();
                break;
                case END_OF_FILE_RECORD:
                break;
                case EXTENDED_LINEAR_ADDRESS_RECORD:
                    BL_voidGetAddressHighDigits(&Localarr_u8HexRecord,&Local_u32HexAppStartAddress);
                break;
                case START_LINEAR_ADDRESS_RECORD:
                break;
            }
        }
        else
        {
            break;
        }
    }
}
/*_________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Private Function Implementations       		     		          	  */
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
static void BL_voidReceiveHexRecord(u8 * Copy_pu8Array)
{
    /*      Function Local Scope Declaration        */
    u8 * Local_pu8Temp = NULL;
    u8 Local_u8Counter = 0;
    while(1)
    {
        while(MUSART1_u8Receive(Local_pu8Temp) == 0);
        if(*Local_pu8Temp != '\n')
        {
            *(Copy_pu8Array + Local_u8Counter) = *Local_pu8Temp;
            Local_u8Counter++;
        }
        else
        {
            break;
        }
    }
}
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
static void BL_voidConfirmReceivedHexRecord(void)
{
    u8 * Local_pu8 = "OK";
    MUSART1_voidTransmit(Local_pu8);
}
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
static ErrorStatus_t BL_ErrorStatusDecodeHexDigit(u8 Copy_u8ASCIIValue,u8 * Copy_pu8HexValue)
{
    ErrorStatus_t Local_ErrorStatus = NoError;
    if(Copy_u8ASCIIValue >= _0_ASCII && Copy_u8ASCIIValue <= _9_ASCII)
    {
        *Copy_pu8HexValue = Copy_u8ASCIIValue - _0_ASCII_DECIMAL;
    }
    else if(Copy_u8ASCIIValue >= _A_ASCII && Copy_u8ASCIIValue <= _F_ASCII)
    {
        *Copy_pu8HexValue = Copy_u8ASCIIValue - _10_ASCII_DECIMAL;
    }
    else
    {
        Local_ErrorStatus = OutofRange;
    }
    return Local_ErrorStatus;
}
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
static ErrorStatus_t BL_ErrorStatusDecodeHexRecord(u8 * Copy_pu8Array)
{
    ErrorStatus_t Local_ErrorStatus = NoError;
    u8 Local_u8loopCounter;
    for(Local_u8loopCounter = 0;Local_u8loopCounter < (sizeof(Copy_pu8Array)/sizeof(Copy_pu8Array[0]));Local_u8loopCounter++)
    {
        if((*(Copy_pu8Array + Local_u8loopCounter)) >= _0_ASCII && (*(Copy_pu8Array + Local_u8loopCounter)) <= _9_ASCII)
        {
            *(Copy_pu8Array + Local_u8loopCounter) = *(Copy_pu8Array + Local_u8loopCounter) - _0_ASCII_DECIMAL;
        }
        else if((*(Copy_pu8Array + Local_u8loopCounter)) >= _A_ASCII && (*(Copy_pu8Array + Local_u8loopCounter)) <= _F_ASCII)
        {
            *(Copy_pu8Array + Local_u8loopCounter) = *(Copy_pu8Array + Local_u8loopCounter) - _10_ASCII_DECIMAL;
        }
        else
        {
            Local_ErrorStatus = OutofRange;
            break;
        }
    }
    return Local_ErrorStatus;
}
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
static void BL_voidGetRecordType(u8 * Copy_pu8Array,u8 * Copy_pu8RecordType)
{
    *Copy_pu8RecordType = 0x00;
    *Copy_pu8RecordType |= ((Copy_pu8Array[RECORDTYPE_MSBDIGIT_INDEX] << 4) | Copy_pu8Array[RECORDTYPE_LSBDIGIT_INDEX]);
}
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
static void BL_voidGetAddressHighDigits(u8 * Copy_pu8Array,u32 * Copy_u32Address)
{
    *Copy_u32Address = 0;
    *Copy_u32Address |= (((Copy_pu8Array[9]) << 28) |
                        ((Copy_pu8Array[10]) << 24) |
                        ((Copy_pu8Array[11]) << 20) |
                        ((Copy_pu8Array[12]) << 16));
}
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
static void BL_voidGetAddressLowDigits(u8 * Copy_pu8Array,u32 * Copy_u32Address)
{
    *Copy_u32Address |= (((Copy_pu8Array[3]) << 12) |
                        ((Copy_pu8Array[4]) << 8)   |
                        ((Copy_pu8Array[5]) << 4)   |
                        ((Copy_pu8Array[6]) << 0));
}
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
static void BL_voidGetCharacterCount(u8 * Copy_pu8Array,u8 * Copy_u8CharacterCount)
{
    *Copy_u8CharacterCount = 0;
    *Copy_u8CharacterCount |= ((Copy_pu8Array[1] << 4) | Copy_pu8Array[2]);
}
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
static void BL_voidGetDataRecord(const u8 * Copy_pu8arr,u16 * Copy_pu16arr,const u8 * Copy_pu8var)
{
    u8 Local_u8LoopCounter = 0;
    for(Local_u8LoopCounter = 0;Local_u8LoopCounter <= (*Copy_pu8var/2);Local_u8LoopCounter++)
    {
        Copy_pu16arr[Local_u8LoopCounter] = Copy_pu8arr[9 + (Local_u8LoopCounter * 4)]  << 12|
                                            Copy_pu8arr[10+ (Local_u8LoopCounter * 4)] << 8 |
                                            Copy_pu8arr[11+ (Local_u8LoopCounter * 4)] << 4 |
                                            Copy_pu8arr[12+ (Local_u8LoopCounter * 4)] << 0 ;
    }
}
/*_________________________________________________________________________________________________*/
