/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	ADC Driver                             							  	          */
/*  Project Description    :	ADC Driver                                                 				      */
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
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Global Declerations       		     		          	  	  	      */
/* ---------------------------------------------------------------------------------------------------------- */

volatile u16 Global_MADC_u16ADCDigitalReading = 0;
volatile u16 Global_MADC_u16ArrayADCDigitalReading[8] = {0};
u8 Global_u8StartChannel;
u8 Global_u8EndChannel;

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Function Prototypes       		     		          	  		      */
/* ---------------------------------------------------------------------------------------------------------- */

static void (*Global_pvCallBackFunction)(void) = NULL;

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Function Implementations       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
void MADC_voidInit(void)
{
    /*      Check to Enable or Disable ADC Peripheral       */
    #if     ADC_ENABLE      ==  ENABLE
        /*      Selecting Reference Voltage     */
        #if     ADC_REF_SELECTION       ==  AVCC
            SET_REG_BIT(ADMUX,ADMUX_REFS0);
            CLR_REG_BIT(ADMUX,ADMUX_REFS1);
        #elif   ADC_REF_SELECTION       ==  AREF
            CLR_REG_BIT(ADMUX,ADMUX_REFS0);
            CLR_REG_BIT(ADMUX,ADMUX_REFS1);
        #elif   ADC_REF_SELECTION       ==  INT_256VOLT
            CLR_REG_BIT(ADMUX,ADMUX_REFS0);
            SET_REG_BIT(ADMUX,ADMUX_REFS1);
        #else
            #error  "error"
        #endif
        /*      Setting ADC Prescaler       */
        ADCSRA &= PRESCALER_MASK;
        ADCSRA |= ADC_PRESCALER_VALUE;
        /*      Enable ADC Peripheral       */
        SET_REG_BIT(ADCSRA,ADCSRA_ADEN);
    #elif   ADC_ENABLE      ==  DISABLE
        /*      Disable ADC Peripheral      */
        CLR_REG_BIT(ADCSRA,ADCSRA_ADEN);
    #else
        #error "error"
    #endif
}

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
u16 MADC_u16StartConversionSync(u8 Copy_u8ChannelNumber)
{
    /*      Masking Channel Selection Bits      */
    ADMUX &= CHANNEL_MASK;
    /*      Setting Channel Selection Bits with Given channel Number        */
    ADMUX |= Copy_u8ChannelNumber;
    /*      Enable ADC Conversion       */
    SET_REG_BIT(ADCSRA,ADCSRA_ADSC);
    /*      Disable ADC Interrupt       */
    CLR_REG_BIT(ADCSRA,ADCSRA_ADIE);
    /*      Polling until Conversion is Finished and Conversion Flag is Raised      */
    while(GET_BIT(ADCSRA,ADCSRA_ADIF) == 0);
    /*      Clear Interrupt Flag for Next Conversion        */
    SET_REG_BIT(ADCSRA,ADCSRA_ADIF);
    return ADC;
}

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
u8 MADC_u8StartConversionSync(u8 Copy_u8ChannelNumber)
{
    /*      Masking Channel Selection Bits      */
    ADMUX &= CHANNEL_MASK;
    /*      Setting Channel Selection Bits with Given channel Number        */
    ADMUX |= Copy_u8ChannelNumber;
    /*      Enable ADC Conversion       */
    SET_REG_BIT(ADCSRA,ADCSRA_ADSC);
    /*      Disable ADC Interrupt       */
    CLR_REG_BIT(ADCSRA,ADCSRA_ADIE);
    /*      Polling until Conversion is Finished and Conversion Flag is Raised      */
    while(GET_BIT(ADCSRA,ADCSRA_ADIF) == 0);
    /*      Clear Interrupt Flag for Next Conversion        */
    SET_REG_BIT(ADCSRA,ADCSRA_ADIF);
    /*      Enable Left Adjustment to Omit Lower Bits(B0,B1)        */
    SET_REG_BIT(ADMUX,ADMUX_ADLAR);
    return ADCH;
}

f32 MADC_f32ConvertDigitalToAnalog_8BitRes(u8 Copy_u8ADCDigitalValue)
{
    return ((Copy_u8ADCDigitalValue / (f32)255) * ADC_REF_SELECTION);
}

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
void MADC_voidStartConversionAsync(u8 Copy_u8ChannelNumber)
{
    /*      Masking Channel Selection Bits      */
    ADMUX &= CHANNEL_MASK;
    /*      Setting Channel Selection Bits with Given channel Number        */
    ADMUX |= Copy_u8ChannelNumber;
    /*      Enable ADC Conversion       */
    SET_REG_BIT(ADCSRA,ADCSRA_ADSC);
    /*      Enable ADC Interrupt        */
    SET_REG_BIT(ADCSRA,ADCSRA_ADIE);
}

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
void MADC_voidStartFreeRunningConversion(u8 Copy_u8StartChannel,u8 Copy_u8EndChannel)
{
    Global_u8StartChannel = Copy_u8StartChannel;
    Global_u8EndChannel = Copy_u8EndChannel;
    /*      Set Auto Trigger Source to Free Running     */
    SFIOR &= AUTO_TRIGGER_MASK;
    SFIOR |= (FREE_RUNNING_MODE << 5);
    /*      Set ADC Data Register To Right Adjustment       */
    CLR_REG_BIT(ADMUX,ADMUX_ADLAR);
    /*      Enable Auto Trigger Mode        */
    SET_REG_BIT(ADCSRA,ADCSRA_ADATE);
    /*      Masking Channel Selection Bits      */
    ADMUX &= CHANNEL_MASK;
    /*      Setting Channel Selection Bits with Given channel Number        */
    ADMUX |= Copy_u8StartChannel;
    /*      Start ADC Conversion        */
    SET_REG_BIT(ADCSRA,ADCSRA_ADSC);
    /*      Enable ADC Interrupt        */
    SET_REG_BIT(ADCSRA,ADCSRA_ADIE);
}

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
void MADC_voidStartAutoTriggerConversion(u8 Copy_u8AutoTriggerSource,u8 Copy_u8ChannelNumber)
{
    switch(Copy_u8AutoTriggerSource)
    {
        case ANALOG_COMPARATOR:
        break;
        case EXTERNAL_INTERRUPT_REQUEST0:
            /*set channel number*/
            ADMUX &= CHANNEL_MASK;
            ADMUX |= Copy_u8ChannelNumber;
            /*set auto trigger source*/
            SFIOR &= AUTO_TRIGGER_MASK;
            SFIOR |= (EXTERNAL_INTERRUPT_REQUEST0 << 5);
            /*right adjust result*/
            CLR_REG_BIT(ADMUX,ADMUX_ADLAR);
            /*enable auto trigger*/
            SET_REG_BIT(ADCSRA,ADCSRA_ADATE);
            /*start cinversion*/
            //SET_REG_BIT(ADCSRA,ADCSRA_ADSC);
            /* adc enable interrupt*/
            SET_REG_BIT(ADCSRA,ADCSRA_ADIE);
        break;
        case TIMER_COUNTER0_COMPARE_MATCH:
        break;
        case TIMER_COUNTER0_OVERFLOW:
        break;
        case TIMER_COUNTER1_COMPARE_MATCH_B:
        break;
        case TIMER_COUNTER1_OVERFLOW:
        break;
        case TIMER_COUNTER1_CAPTURE_EVENT:
        break;
    }
}


/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/
void MADC_voidSetCallBack(void(*Copy_pvNotificationFunction)(void))
{
    Global_pvCallBackFunction = Copy_pvNotificationFunction;
}

/* ------------------------------------------------------------------------------------- */
/*
	Function Name 		        :
	Function Return Type        :
	Function Description        :
	Function Arguments          :
    Function Arguments Datatype :

	Function Parameters Options :
	_____________________________

*/

void __vector_16 (void)
{
    #if ADC_ISR_CONFIG == ASYNC_SINGLE_CONVERSION
        if(Global_pvCallBackFunction != NULL)
        {
            Global_MADC_u16ADCDigitalReading = ADC;
            Global_pvCallBackFunction();
            CLR_REG_BIT(ADCSRA,ADCSRA_ADIF);
        }
        else
        {
            /*Do Nothing*/
        }
    #elif ADC_ISR_CONFIG == FREE_RUNNING_CONVERSION
        static u8 Local_u8ChannelCounter = 0;
        Local_u8ChannelCounter = Global_u8StartChannel;
        if(Local_u8ChannelCounter > Global_u8EndChannel)
        {
            Local_u8ChannelCounter = Global_u8StartChannel;
            Global_MADC_u16ArrayADCDigitalReading[Local_u8ChannelCounter] = ADC;
        }
        else
        {
            Global_MADC_u16ArrayADCDigitalReading[Local_u8ChannelCounter] = ADC;
        }
        if(Global_pvCallBackFunction != NULL)
        {
            Global_pvCallBackFunction();
        }
        Local_u8ChannelCounter++;
        ADMUX &= CHANNEL_MASK;
        ADMUX |= Local_u8ChannelCounter;
        CLR_REG_BIT(ADCSRA,ADCSRA_ADIE);
    #else
        #error "ADC ISR Configuration Error "
    #endif
}
