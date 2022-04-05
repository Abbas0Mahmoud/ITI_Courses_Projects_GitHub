/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	TWI Driver                             							  	          */
/*  Project Description    :	TWI Driver                                                 				      */
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

/*_______________________________________________________________________________________*/

/*		                        Self Files Inclusoins							         */
#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"
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
void MTWI_voidMasterInit(u8 Copy_u8SlaveAddress)
{
	/*	Enable Acknowledge	*/
	SET_REG_BIT(TWCR, TWCR_TWEA);
	/*	Set SCL Frequency = 100KHz, CPU Clk = 8MHz, TWPS = 0	*/
	TWBR = 32;
	/*	Clear The Prescaler Bit (TWPS0, TWPS1)	*/
	CLR_REG_BIT(TWSR, TWSR_TWPS0);
	CLR_REG_BIT(TWSR, TWSR_TWPS1);
	/*	Check if the master node will be addressed or not	*/
	/*	Check Copy_u8SlaveAddress with 0 as General Call Addrsss so Master will not respond to Broadcasting from ohter masters	*/
	if(Copy_u8SlaveAddress == 0)
	{
		/*	No Slave Address is assigned to Master	*/
		/*	Do Nothing	*/
	}
	else
	{
		/*	Assing Slave Address to Master in Higher Bits of TWAR	*/
		TWAR = Copy_u8SlaveAddress << 1;
	}
	/*	Enable TWI	*/
	SET_REG_BIT(TWCR, TWCR_TWEN);
}
/*_________________________________________________________________________________________________*/

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
void MTWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	/*	Enable Acknowledge	*/
	SET_REG_BIT(TWCR, TWCR_TWEA);
	/*	Set The Slave Address	*/
	TWAR = Copy_u8SlaveAddress << 1;
	/*	Enable TWI	*/
	SET_REG_BIT(TWCR, TWCR_TWEN);
}
/*_________________________________________________________________________________________________*/

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
TWI_ErrorStatus_t MTWI_ErrorStatusSendStartCondition(void)
{
	TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	/*Set The Start Condition Bit*/
	SET_REG_BIT(TWCR, TWCR_TWSTA);
	/*Clear The Flag*/
	SET_REG_BIT(TWCR, TWCR_TWINT);
	/*Polling (Busy Wait) until the flag is raised again*/
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	/*Check if the Start Condition is Transmitted*/
	if((TWSR & STATUS_CODE_MASK) != START_ACK)
	{
		Local_ErrorStatus = StartConditionError;
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

	Function Parameters Options :
	_____________________________
*/
/* ----------------------------------------------------------------------------------------------- */
TWI_ErrorStatus_t MTWI_ErrorStatusSendRepeatedStartCondition(void)
{
	TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	/*Set The Start Condition Bit*/
	SET_REG_BIT(TWCR, TWCR_TWSTA);
	/*Clear The Flag*/
	SET_REG_BIT(TWCR, TWCR_TWINT);
	/*Polling (Busy Wait) until the flag is raised again*/
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	/*Check if the Start Condition is Transmitted*/
	if((TWSR & STATUS_CODE_MASK) != REP_START_ACK)
	{
		Local_ErrorStatus = RepeatedStartConditionError;
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

	Function Parameters Options :
	_____________________________
*/
/* ----------------------------------------------------------------------------------------------- */
TWI_ErrorStatus_t MTWI_ErrorStatusSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	/*Load The Slave Address To The TWDR Register*/
	TWDR = Copy_u8SlaveAddress << 1;
	/*Clear The Bit 0 For The Write Request*/
	CLR_REG_BIT(TWDR, TWDR_TWD0);
	/*Clear The Start Condition Bit*/
	CLR_REG_BIT(TWCR, TWCR_TWSTA);
	/*Clear The Flag*/
	SET_REG_BIT(TWCR, TWCR_TWINT);
	/*Polling (Busy Wait) until the flag is raised again*/
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	/*Check if the Start Condition is Transmitted*/
	if((TWSR & STATUS_CODE_MASK) != SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrorStatus = SlaveAddressWithWriteError;
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

	Function Parameters Options :
	_____________________________
*/
/* ----------------------------------------------------------------------------------------------- */
TWI_ErrorStatus_t MTWI_ErrorStatusSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	/*Load The Slave Address To The TWDR Register*/
	TWDR = Copy_u8SlaveAddress << 1;
	/*Set The Bit 0 For The Read Request*/
	SET_REG_BIT(TWDR, TWDR_TWD0);
	/*Clear The Start Condition Bit*/
	CLR_REG_BIT(TWCR, TWCR_TWSTA);
	/*Clear The Flag*/
	SET_REG_BIT(TWCR, TWCR_TWINT);
	/*Polling (Busy Wait) until the flag is raised again*/
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	/*Check if the Start Condition is Transmitted*/
	if((TWSR & STATUS_CODE_MASK) != SLAVE_ADD_AND_RD_ACK)
	{
		Local_ErrorStatus = SlaveAddressWithReadError;
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

	Function Parameters Options :
	_____________________________
*/
/* ----------------------------------------------------------------------------------------------- */
TWI_ErrorStatus_t MTWI_ErrorStatusMasterWriteDataByte(u8 Copy_u8Data)
{
	TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	/*Load The Data Into The TWDR Register*/
	TWDR = Copy_u8Data;
	/*Clear The Flag*/
	SET_REG_BIT(TWCR, TWCR_TWINT);
	/*Polling (Busy Wait) until the flag is raised again*/
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	/*Check if the Start Condition is Transmitted*/
	if((TWSR & STATUS_CODE_MASK) != MSTR_WR_BYTE_ACK)
	{
		Local_ErrorStatus = MasterWriteByteError;
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

	Function Parameters Options :
	_____________________________
*/
/* ----------------------------------------------------------------------------------------------- */
TWI_ErrorStatus_t MTWI_ErrorStatusMasterReadDataByte(u8 * Copy_pu8ReceivedData)
{
	TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	/*Clear The Flag, To Make The Slave Send Its Data*/
	SET_REG_BIT(TWCR, TWCR_TWINT);
	/*Polling (Busy Wait) until the flag is raised again*/
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	/*Check if the Start Condition is Transmitted*/
	if((TWSR & STATUS_CODE_MASK) != MSTR_RD_BYTE_WITH_ACK)
	{
		Local_ErrorStatus = MasterReadByteError;
	}
	else
	{
		/*Get The Received Data*/
		*Copy_pu8ReceivedData = TWDR;
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

	Function Parameters Options :
	_____________________________
*/
/* ----------------------------------------------------------------------------------------------- */
TWI_ErrorStatus_t MTWI_ErrorStatusMasterReadDataByteNoAcknowledge(u8 * Copy_pu8ReceivedData)
{
	TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	/*	Disable Acknowledge	*/
	CLR_REG_BIT(TWCR, TWCR_TWEA);
	/*Clear The Flag, To Make The Slave Send Its Data*/
	SET_REG_BIT(TWCR, TWCR_TWINT);
	/*Polling (Busy Wait) until the flag is raised again*/
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	/*Check if the Start Condition is Transmitted*/
	if((TWSR & STATUS_CODE_MASK) != MSTR_RD_BYTE_WITH_NACK)
	{
		Local_ErrorStatus = MasterReadByteNoAcknowledgeError;
	}
	else
	{
		/*Get The Received Data*/
		*Copy_pu8ReceivedData = TWDR;
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

	Function Parameters Options :
	_____________________________
*/
/* ----------------------------------------------------------------------------------------------- */
void MTWI_voidSendStopCondition(void)
{
	/*Set The STOP CONDITION Bit*/
	SET_REG_BIT(TWCR, TWCR_TWSTO);
	/*Clear The Flag, To Make The Slave Send Its Data*/
	SET_REG_BIT(TWCR, TWCR_TWINT);
}
/*_________________________________________________________________________________________________*/
