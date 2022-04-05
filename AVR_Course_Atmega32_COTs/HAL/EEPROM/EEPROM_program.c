/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	EEPROM Driver                             							  	      */
/*  Project Description    :	EEPROM Driver                                                 				  */
/*  Target Controller 	   :	Atmega 32                                               					  */
/*  File Name              :	ADC_program.c                                    						      */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/*		                        Library Inclusions								         */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*_______________________________________________________________________________________*/

/*		                        HAL Layer Inclusion							             */

/*_______________________________________________________________________________________*/

/*		                        MCAL Layer Inclusion					                 */
#include "../../MCAL/TWI/TWI_interface.h"
/*_______________________________________________________________________________________*/

/*		                        Self Files Inclusoins							         */
#include "EEPROM_config.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"
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

	Function Parameters Options :
	_____________________________
*/
/* ----------------------------------------------------------------------------------------------- */

/*_________________________________________________________________________________________________*/

void HEEPROM_voidWriteData(u16 Copy_u16Location, u8 Copy_u8Data)
{
	u8 Local_u8AddressPacket = 0;
	if(Copy_u16Location <= 1023)
	{
		Local_u8AddressPacket =	 EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) | (u8)(Copy_u16Location >> 8);
		/*2K
			Local_u8AddressPacket =	 EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) |
			(A1_CONNECTION << 1) | (A0_CONNECTION);
		*/
		/*Send Start Condition*/
		MTWI_ErrorStatusSendStartCondition();
		/*Send Slave Address With Write Request*/
		MTWI_ErrorStatusSendSlaveAddressWithWrite(Local_u8AddressPacket);
		/*Send The Rest Of Byte Address*/
		MTWI_ErrorStatusMasterWriteDataByte((u8)Copy_u16Location);
		/*Send The Data Byte*/
		MTWI_ErrorStatusMasterWriteDataByte(Copy_u8Data);
		/*Send Stop Condition*/
		MTWI_voidSendStopCondition();
		_delay_ms(10);
	}
}

void HEEPROM_voidWriteData_V2(u16 Copy_u16Location, u8 Copy_u8Data)
{
	u8 Local_u8AddressPacket = 0;
	if(Copy_u16Location < EEPROM_LOCATIONS)
	{
		#if EEPROM_SIZE ==  EEPROM_1K
    		Local_u8AddressPacket =	 EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) |
			(A1_CONNECTION << 1) | (A0_CONNECTION);
		#elif   EEPROM_SIZE ==  EEPROM_2K
			Local_u8AddressPacket =	 EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) |
			(A1_CONNECTION << 1) | (A0_CONNECTION);
		#elif   EEPROM_SIZE ==  EEPROM_4K
			Local_u8AddressPacket =	 EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) |
			(A1_CONNECTION << 1) | (u8)(Copy_u16Location >> 8);
		#elif   EEPROM_SIZE ==  EEPROM_8K
			Local_u8AddressPacket =	 EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) | (u8)(Copy_u16Location >> 8);
		#elif   EEPROM_SIZE ==  EEPROM_16K
			Local_u8AddressPacket =	 EEPROM_FIXED_ADDRESS | (u8)(Copy_u16Location >> 8);
		#else
			#error  "EEPROM SIZE CONFIGURATION ERROR"
		#endif
		/*Send Start Condition*/
		MTWI_ErrorStatusSendStartCondition();
		/*Send Slave Address With Write Request*/
		MTWI_ErrorStatusSendSlaveAddressWithWrite(Local_u8AddressPacket);
		/*Send The Rest Of Byte Address*/
		MTWI_ErrorStatusMasterWriteDataByte((u8)Copy_u16Location);
		/*Send The Data Byte*/
		MTWI_ErrorStatusMasterWriteDataByte(Copy_u8Data);
		/*Send Stop Condition*/
		MTWI_voidSendStopCondition();
		_delay_ms(10);
	}
}

/*_________________________________________________________________________________________________*/

void HEEPROM_voidReadData(u16 Copy_u16Location, u8 * Copy_pu8ReceivedData)
{
	u8 Local_u8AddressPacket = 0;
	if(Copy_u16Location <= 1023)
	{
		Local_u8AddressPacket =	 EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) | (u8)(Copy_u16Location >> 8);
		/*2K
			Local_u8AddressPacket =	 EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) |
			(A1_CONNECTION << 1) | (A0_CONNECTION);
		*/

		/*Send Start Condition*/
		MTWI_ErrorStatusSendStartCondition();
		/*Send Slave Address With Write Request*/
		MTWI_ErrorStatusSendSlaveAddressWithWrite(Local_u8AddressPacket);
		/*Send The Rest Of Byte Address*/
		MTWI_ErrorStatusMasterWriteDataByte((u8)Copy_u16Location);
		/*Send Repeated Start Condition*/
		MTWI_ErrorStatusSendRepeatedStartCondition();
		/*Send The Slave Address With Read Request*/
		MTWI_ErrorStatusSendSlaveAddressWithRead(Local_u8AddressPacket);
		/*Get The Data From The Memory*/
		MTWI_ErrorStatusMasterReadDataByte(Copy_pu8ReceivedData);
		/*Send Stop Condition*/
		MTWI_voidSendStopCondition();
	}
}

void HEEPROM_voidReadData_V2(u16 Copy_u16Location, u8 * Copy_pu8ReceivedData)
{
	u8 Local_u8AddressPacket = 0;
	if(Copy_u16Location < EEPROM_LOCATIONS)
	{
		#if EEPROM_SIZE ==  EEPROM_1K
    		Local_u8AddressPacket =	 EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) |
			(A1_CONNECTION << 1) | (A0_CONNECTION);
		#elif   EEPROM_SIZE ==  EEPROM_2K
			Local_u8AddressPacket =	 EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) |
			(A1_CONNECTION << 1) | (A0_CONNECTION);
		#elif   EEPROM_SIZE ==  EEPROM_4K
			Local_u8AddressPacket =	 EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) |
			(A1_CONNECTION << 1) | (u8)(Copy_u16Location >> 8);
		#elif   EEPROM_SIZE ==  EEPROM_8K
			Local_u8AddressPacket =	 EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) | (u8)(Copy_u16Location >> 8);
		#elif   EEPROM_SIZE ==  EEPROM_16K
			Local_u8AddressPacket =	 EEPROM_FIXED_ADDRESS | (u8)(Copy_u16Location >> 8);
		#else
			#error  "EEPROM SIZE CONFIGURATION ERROR"
		#endif
		/*Send Start Condition*/
		MTWI_ErrorStatusSendStartCondition();
		/*Send Slave Address With Write Request*/
		MTWI_ErrorStatusSendSlaveAddressWithWrite(Local_u8AddressPacket);
		/*Send The Rest Of Byte Address*/
		MTWI_ErrorStatusMasterWriteDataByte((u8)Copy_u16Location);
		/*Send Repeated Start Condition*/
		MTWI_ErrorStatusSendRepeatedStartCondition();
		/*Send The Slave Address With Read Request*/
		MTWI_ErrorStatusSendSlaveAddressWithRead(Local_u8AddressPacket);
		/*Get The Data From The Memory*/
		MTWI_ErrorStatusMasterReadDataByte(Copy_pu8ReceivedData);
		/*Send Stop Condition*/
		MTWI_voidSendStopCondition();
	}
}


