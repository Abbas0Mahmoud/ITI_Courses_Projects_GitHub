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
#include "../../../Inc/LIB/Std_Types.h"
#include "../../../Inc/LIB/BIT_MATH.h"
/*_______________________________________________________________________________________*/

/*		                		HAL Layer Inclusion							     		 */

/*_______________________________________________________________________________________*/

/*		                		MCAL Layer Inclusion					         		 */
#include "../../../Inc/MCAL/RCC/RCC_interface.h"
#include "../../../Inc/MCAL/STK/STK_interface.h"
#include "../../../Inc/MCAL/GPIO/GPIO_interface.h"
#include "../../../Inc/MCAL/EXTI/EXTI_interface.h"
#include "../../../Inc/MCAL/NVIC/NVIC_interface.h"
#include "../../../Inc/MCAL/USARt/USART_interface.h"
#include "../../../Inc/APP/BL/BL_interface.h"
/*_______________________________________________________________________________________*/

/*		                		Self Files Inclusions							 		 */
#include "../../../Inc/APP/BM/BM_interface.h"
#include "../../../Inc/APP/BM/BM_private.h"
#include "../../../Inc/APP/BM/BM_config.h"
#include "../../../Inc/APP/BM/SCB_private.h"
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
void MBM_voidMainFunction(void)
{
	/*		Check for BootManager Peripheral Initialization		*/
	if(INIT_NOT_SET==GU8_InitFlag)
	{
		/*		Initialize BootManager Peripherals		*/
		MBM_voidInit();
		/*		Set Initialization Flag		*/
		GU8_InitFlag=INIT_IS_SET;
	}

	if(INIT_IS_SET==GU8_InitFlag)
	{
		/*      Checking on Jump Flags to Determine whether to Jump to BootLoader or To APP     */
		if(BM_FLAGS.NoJumpFlag == FLAG_NOT_ACTIVE)
		{
			/*		Check on Booting Flags		*/
			MBM_voidCheckBootFlags();
		}

		/*		BootLoader Block		*/
		if(JUMP_TO_BL==BM_FLAGS.BootJumpFlag)
		{
			if(BM_FLAGS.NoJumpFlag == FLAG_ACTIVE)
			{
				MGPIO_voidSetPortSpecificValue(GPIO_PORTC,7);
			}
			/*		Jump to BootLoader		*/
			BL_voidMainFunction();
			/*		Set Jump Flag to App		*/
			BM_FLAGS.BootJumpFlag=JUMP_TO_APP;
		}

		/*		Application Block		*/
		if(JUMP_TO_APP==BM_FLAGS.BootJumpFlag)
		{
			/*      Before Jump Invocations     */
			/*----------------------------------*/
			/*      De-Init Any Used Module     */
			MBM_voidDeinit();
			/*      Disable Interrupts and Clear all Pending Flags      */
			MNVIC_voidClearAllinterruptPendingFlags();
			/*      Jump to APP Instruction        */
			MBM_voidJumpToAPP();
		}
		else
		{
			/* Do Nothing */
		}
	}

}
/*_________________________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           		Private Program Function Implementations       		     		          */
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
static void MBM_voidInit(void)
{
    /*      Initialize RCC Peripheral       */
    MRCC_voidInit();
    /*      Enable Peripherals Clock        */
    MRCC_voidSetPeripheralClkStatus(APB2_BUS,IOPA,CLK_SRC_ON);
    //MRCC_voidSetPeripheralClkStatus(APB2_BUS,AFIOEN,CLK_SRC_ON);
    MRCC_voidSetPeripheralClkStatus(APB1_BUS,UART2EN, CLK_SRC_ON);
	MRCC_voidSetPeripheralClkStatus(APB2_BUS,IOPC,CLK_SRC_ON);
    /*      Initialize SysTick Timer        */
    MSTK_voidInit();
    /*		Initialize USART		*/
    MUSART1_voidInit();
    /*		Initialize UART RX/TX		*/
    /*		TX PIN		*/
	MGPIO_voidSetPinDirection(GPIO_PORTA,GPIO_PIN2,GPIO_OUTPUT_MODE_2_MHZ, GPIO_OUTPUT_MODE_CNF_AF_PUSH_PULL);
	/*		RX PIN		*/
	MGPIO_voidSetPinDirection(GPIO_PORTA,GPIO_PIN3,GPIO_INPUT_MODE,GPIO_INPUT_MODE_CNF_FLOATING);
    /*      Set GPIO Configurations     */
    /*      Set Boot Switch Pin     */
    MGPIO_voidSetPinDirection(GPIO_PORTA,GPIO_PIN0,GPIO_INPUT_MODE,GPIO_INPUT_MODE_CNF_PULL_UP_DOWN);
    MGPIO_voidSetPinInputPullUpDown(GPIO_PORTA,GPIO_PIN0,GPIO_INPUT_MODE_CNF_PULL_UP);
    /*      Set Led Pins        */
    MGPIO_voidSetPinDirection(GPIO_PORTC,GPIO_PIN13,GPIO_OUTPUT_MODE_2_MHZ,GPIO_OUTPUT_MODE_CNF_GP_PUSH_PULL);
    MGPIO_voidSetPinDirection(GPIO_PORTC,GPIO_PIN14,GPIO_OUTPUT_MODE_2_MHZ,GPIO_OUTPUT_MODE_CNF_GP_PUSH_PULL);
    MGPIO_voidSetPinDirection(GPIO_PORTC,GPIO_PIN15,GPIO_OUTPUT_MODE_2_MHZ,GPIO_OUTPUT_MODE_CNF_GP_PUSH_PULL);
    MGPIO_voidSetPortSpecificValue(GPIO_PORTC,0);
    /*      Initialize EXTI Peripheral      */
    MEXTI_voidSetCallBack(EXTI0,&MBM_voidUpdateBootSwitchFlag);
    MEXTI_voidEnableLine(EXTI0);
    MEXTI_voidSetLineTrigger(EXTI0,EXTI_FAILING);
    /*      Initialize BootManager Flags        */
    BM_FLAGS.INIT_BM_FLAGS = 0x00;
    /*      Initialize NVIC Peripheral      */
    MNVIC_voidSetInterruptEnable(NVIC_INTID_EXTI0);
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
void MBM_voidUpdateBootSwitchFlag(void)
{
    BM_FLAGS.BootSwitchFlag = FLAG_ACTIVE;
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
void MBM_voidUpdateTimeoutFlag(void)
{
    BM_FLAGS.BootTimeOutFlag = FLAG_ACTIVE;
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
static void MBM_voidUpdateSharedupdateFlag(void)
{
	if(SHARED_MEM_FLAG_ADDRESS_VALUE != FLASH_EMPTY_HALF_WORD_LOCATION_VALUE)
	{
		BM_FLAGS.BootSharedUpdateFlag = FLAG_ACTIVE;
	}
	else
	{
		BM_FLAGS.BootSharedUpdateFlag = FLAG_NOT_ACTIVE;
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
static void MBM_voidUpdateBootValidAppFlag(void)
{
	if(APP_FIRST_LOCATION_VALUE != FLASH_EMPTY_HALF_WORD_LOCATION_VALUE)
	{
		BM_FLAGS.BootValidAppFlag = FLAG_ACTIVE;
	}
	else
	{
		BM_FLAGS.BootValidAppFlag = FLAG_NOT_ACTIVE;
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
static void MBM_voidDeinit(void)
{
    /*      Disable Peripherals Clock        */
    MRCC_voidResetPeripheral(APB2_BUS,IOPA);
    MRCC_voidResetPeripheral(APB2_BUS,IOPC);
    MRCC_voidResetPeripheral(APB2_BUS,AFIOEN);
    /*      Stop SysTick Timer        */
    MSTK_voidStopTimer();
	/*      De-Initialize EXTI Peripheral      */
	MEXTI_voidDisableLine(EXTI0);
    /*      De-Initialize NVIC Peripheral      */
	MNVIC_voidClearInterruptEnable(NVIC_INTID_EXTI0);
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
static void MBM_voidCheckBootFlags(void)
{
    /*      Function Local Scope Declaration        */
	u8 Local_u8UARTStartCharacter = 0;
	/*		Updating Flash Flags Value		*/
	MBM_voidUpdateSharedupdateFlag();
	MBM_voidUpdateBootValidAppFlag();
	if(BM_FLAGS.BootSharedUpdateFlag == FLAG_ACTIVE)
	{
		BM_FLAGS.BootJumpFlag = JUMP_TO_BL;
	}
	else if(BM_FLAGS.BootValidAppFlag == FLAG_NOT_ACTIVE)
	{
		BM_FLAGS.BootJumpFlag = JUMP_TO_BL;
		BM_FLAGS.NoJumpFlag = FLAG_ACTIVE;
	}
	else
	{
        /*      Enable SysTick Timer and Set TimeOut        */
        MSTK_voidSetInterval_Single(MSTK_u32ConvertTimetoTickCount(BOOT_CHECK_TIME_OUT_IN_SECONDS,S),&MBM_voidUpdateTimeoutFlag);
        /*      Looping on Flags until TimeOut Flag is Raised By SysTick Timer      */
        while (BM_FLAGS.BootTimeOutFlag == FLAG_NOT_ACTIVE)
        {
            /*                  Checking Jump Flags Block                */
            /*---------------------------------------------------------- */
        	if(MUSART1_u8Receive(&Local_u8UARTStartCharacter))
        	{
        	    if(Local_u8UARTStartCharacter == USARTSTARTCHARACTER)
        		{
        			BM_FLAGS.BootUARTFlag = FLAG_ACTIVE;
        			break;
        		}
        		else
        		{
        			/* Do Nothing */
        		}
        	}
            /*      Checking on BootSwitch Flag     */
            if(BM_FLAGS.BootSwitchFlag == FLAG_ACTIVE)
            {
                /*      Disable SysTick Timer       */
                MSTK_voidStopTimer();
                /*      Return Jump To Bootloader Flag      */
                BM_FLAGS.BootJumpFlag = JUMP_TO_BL;
                break;
            }/*     Checking on BootUART Flag (Raised by UART if any Data Received During TimeOut Period)      */
            else if(BM_FLAGS.BootUARTFlag == FLAG_ACTIVE)
            {
                /*      Disable SysTick Timer       */
                MSTK_voidStopTimer();
                /*      Retrun Jump To Bootloader Flag      */
                BM_FLAGS.BootJumpFlag = JUMP_TO_BL;
                break;
            }
        }
        if(BM_FLAGS.BootValidAppFlag == FLAG_ACTIVE)
        {
        	BM_FLAGS.BootJumpFlag = JUMP_TO_APP;
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
static void MBM_voidJumpToAPP(void)
{
	/*		Offest IVT of App		*/
	SCB->VTOR = APP_START_PAGE_BASE_ADDRESS;
	/*		Define Pointer to Function		*/
	CallAPP_t APP_Call =NULL;
	/*		Set Pointer to Function to Point to Reset Handler of App		*/
	APP_Call = (*(CallAPP_t*)APP_RESET_HANDLER_ADDRESS);
	/*		Jump to App		*/
	APP_Call();
}
/*_________________________________________________________________________________________________*/
