/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	TIMERS Driver                             							  	      */
/*  Project Description    :	TIMERS Driver                                                 				  */
/*  Target Controller 	   :	Atmega 32                                               					  */
/*  File Name              :	TIMERS_program.c                                    						  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/*		                        Library Inclusions							             */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*_______________________________________________________________________________________*/

/*		                HAL Layer Inclusion							                     */

/*_______________________________________________________________________________________*/

/*		                MCAL Layer Inclusion					                         */

/*_______________________________________________________________________________________*/

/*		                Self Files Inclusoins							                 */
#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Global Declerations       		     		          	  	  	      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Function Prototypes       		     		          	  		      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Program Function Implementations       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                                            TIMER0 FUNCTIONS                                                */
/* ---------------------------------------------------------------------------------------------------------- */

/*                                   TIMER0 POST BUILD FUNCTIONS                                              */
/* ---------------------------------------------------------------------------------------------------------- */

/*                                  TIMER0 CONFIGURATION FUNCTIONS                                            */

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
/* ------------------------------------------------------------------------------------- */
void MTIMERS_voidTimer0Disable(void)
{
    TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
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
/* ------------------------------------------------------------------------------------- */
void MTIMERS_voidTimer0SetMode(u8 Copy_u8Timer0Mode)
{
    switch (Copy_u8Timer0Mode)
    {
        case TIMER0_MODE_NORMAL:
            CLR_REG_BIT(TCCR0, TCCR0_WGM00);
            CLR_REG_BIT(TCCR0, TCCR0_WGM01);
        break;

        case TIMER0_MODE_PWM:
            SET_REG_BIT(TCCR0, TCCR0_WGM00);
            CLR_REG_BIT(TCCR0, TCCR0_WGM01);
        break;

        case TIMER0_MODE_CTC:
            CLR_REG_BIT(TCCR0, TCCR0_WGM00);
            SET_REG_BIT(TCCR0, TCCR0_WGM01);
        break;

        case TIMER0_MODE_FAST_PWM:
            SET_REG_BIT(TCCR0, TCCR0_WGM00);
            SET_REG_BIT(TCCR0, TCCR0_WGM01);
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
/* ------------------------------------------------------------------------------------- */
void MTIMERS_voidTimer0SetPrescaler(u8 Copy_u8Timer0Prescaler)
{
    switch (Copy_u8Timer0Prescaler)
    {
        case TIMER0_CLKIO_1_PRESCALER:
            TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
            TCCR0 |= TIMER0_CLKIO_1_PRESCALER;
        break;

        case TIMER0_CLKIO_8_PRESCALER:
            TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
            TCCR0 |= TIMER0_CLKIO_8_PRESCALER;
        break;

        case TIMER0_CLKIO_64_PRESCALER:
            TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
            TCCR0 |= TIMER0_CLKIO_64_PRESCALER;
        break;

        case TIMER0_CLKIO_256_PRESCALER:
            TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
            TCCR0 |= TIMER0_CLKIO_256_PRESCALER;
        break;

        case TIMER0_CLKIO_1024_PRESCALER:
            TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
            TCCR0 |= TIMER0_CLKIO_1024_PRESCALER;
        break;

        case TIMER0_EXTERNAL_SOURCE_FAILING_EDGE:
            TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
            TCCR0 |= TIMER0_EXTERNAL_SOURCE_FAILING_EDGE;
        break;

        case TIMER0_EXTERNAL_SOURCE_RISING_EDGE:
            TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
            TCCR0 |= TIMER0_EXTERNAL_SOURCE_RISING_EDGE;
        break;
    }
}


/*                                        Timer0 OVERFLOW MODE FUNCTIONS                                      */
/*------------------------------------------------------------------------------------------------------------*/

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
/* ------------------------------------------------------------------------------------- */
void MTIMERS_voidTimer0OVFSetPreloadValue(u8 Copy_u8PreloadValue)
{
    TCNT0 = Copy_u8PreloadValue;
}

void MTIMERS_voidTimer0OVFInterruptEnable(u8 Copy_u8State)
{
    switch(Copy_u8State)
    {
        case ENABLE:
            SET_REG_BIT(TIMSK,TIMSK_TOIE0);
        break;
        case DISBALE:
            CLR_REG_BIT(TIMSK,TIMSK_TOIE0);
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
/* ------------------------------------------------------------------------------------- */
static void (*Global_pvTimer0OVFCallBack)(void) = NULL;

void MTIMERS_voidTimer0OVFSetCallBack(void (*Copy_pvCallBackFunction)(void))
{
    Global_pvTimer0OVFCallBack = Copy_pvCallBackFunction;
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
/* ------------------------------------------------------------------------------------- */
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
    if (Global_pvTimer0OVFCallBack != NULL)
    {
        Global_pvTimer0OVFCallBack();
    }
    else
    {
    }
}


/*                                Timer0 CLEAR ON COMPARE MODE FUNCTIONS                                      */
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
/* ------------------------------------------------------------------------------------- */
void MTIMERS_voidTimer0CTCSetCompareMatchValue(u8 Copy_u8CompareMatchValue)
{
    OCR0 = Copy_u8CompareMatchValue;
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
/* ------------------------------------------------------------------------------------- */
u32  MTIMERS_voidTimer0CTCStartMillis(void)
{
    /* SET TIMER0 IN CTC MODE */
    CLR_REG_BIT(TCCR0, TCCR0_WGM00);
    SET_REG_BIT(TCCR0, TCCR0_WGM01);
    /*SET PRESCALER TO 64*/
    TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
    TCCR0 |= TIMER0_CLKIO_64_PRESCALER;
    /*DISABLE TIMER0 CTC INTERRUPT*/
    CLR_REG_BIT(TIMSK, TIMSk_OCIE0);
    /* CLEAR COMPARE MATCH FLAG */
    SET_REG_BIT(TIFR, TIFR_OCF0);
    /*SET OCR0 VALUE TO 1*/
    OCR0 = 125; // COMPARE MATCH VALUE
    static u32 Local_u32TickCount = 0;
    if (GET_BIT(TIFR, TIFR_OCF0) == 1)
    {
        if(Local_u32TickCount >= 65535)
        {
            Local_u32TickCount = 0;
        }
        else
        {
            Local_u32TickCount++;
        }
    }
    SET_REG_BIT(TIFR, TIFR_OCF0);
    return Local_u32TickCount;
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
/* ------------------------------------------------------------------------------------- */
void MTIMERS_voidTimer0CTCSetBusyWait_ms(u32 Copy_u32MilliSeconds)
{
    /* SET TIMER0 IN CTC MODE */
    CLR_REG_BIT(TCCR0, TCCR0_WGM00);
    SET_REG_BIT(TCCR0, TCCR0_WGM01);
    /*SET PRESCALER TO 64*/
    TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
    TCCR0 |= TIMER0_CLKIO_64_PRESCALER;
    /*DISABLE TIMER0 CTC INTERRUPT*/
    CLR_REG_BIT(TIMSK, TIMSk_OCIE0);
    /* CLEAR COMPARE MATCH FLAG */
    SET_REG_BIT(TIFR, TIFR_OCF0);
    /*SET OCR0 VALUE TO 1*/
    OCR0 = 125; // COMPARE MATCH VALUE
    u32 Local_u32TickCount = 0;
    while (Local_u32TickCount < Copy_u32MilliSeconds)
    {
        if (GET_BIT(TIFR, TIFR_OCF0) == 1)
        {
            Local_u32TickCount++;
            SET_REG_BIT(TIFR, TIFR_OCF0);
        }
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
/* ------------------------------------------------------------------------------------- */
void MTIMERS_voidTimer0CTCSetBusyWait_us(u32 Copy_u32MicroSeconds)
{
    /* SET TIMER0 IN CTC MODE */
    CLR_REG_BIT(TCCR0, TCCR0_WGM00);
    SET_REG_BIT(TCCR0, TCCR0_WGM01);
    /*SET PRESCALER TO 8*/
    TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
    TCCR0 |= TIMER0_CLKIO_64_PRESCALER;
    /* CLEAR COMPARE MATCH FLAG */
    SET_REG_BIT(TIFR, TIFR_OCF0);
    /*DISABLE TIMER0 CTC INTERRUPT*/
    CLR_REG_BIT(TIMSK, TIMSk_OCIE0);
    /*SET OCR0 VALUE TO 1*/
    OCR0 = 1; // COMPARE MATCH VALUE
    u32 Local_u32TickCount = 0;
    while (Local_u32TickCount < Copy_u32MicroSeconds)
    {
        if (GET_BIT(TIFR, TIFR_OCF0) == 1)
        {
            Local_u32TickCount++;
            SET_REG_BIT(TIFR, TIFR_OCF0);
        }
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
/* ------------------------------------------------------------------------------------- */
void MTIMERS_voidTimer0SetOC0PinModeinCTCMode(u8 Copy_u8OC0PinMode)
{
    switch (Copy_u8OC0PinMode)
    {
    case TIMER0_OC0_MODE_NORMAL:
        CLR_REG_BIT(TCCR0, TCCR0_COM00);
        CLR_REG_BIT(TCCR0, TCCR0_COM01);
        break;
    case TIMER0_OC0_MODE_TOGGLE:
        SET_REG_BIT(TCCR0, TCCR0_COM00);
        CLR_REG_BIT(TCCR0, TCCR0_COM01);
        break;
    case TIMER0_OC0_MODE_CLEAR:
        CLR_REG_BIT(TCCR0, TCCR0_COM00);
        SET_REG_BIT(TCCR0, TCCR0_COM01);
        break;
    case TIMER0_OC0_MODE_SET:
        SET_REG_BIT(TCCR0, TCCR0_COM00);
        SET_REG_BIT(TCCR0, TCCR0_COM01);
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
/* ------------------------------------------------------------------------------------- */
static void (*Global_pvTimer0CTCCallBack)(void) = NULL;

void MTIMERS_voidTimer0CTCSetCallBack(void (*Copy_pvCallBackFunction)(void))
{
    Global_pvTimer0CTCCallBack = Copy_pvCallBackFunction;
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
/* ------------------------------------------------------------------------------------- */
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
    if (Global_pvTimer0CTCCallBack != NULL)
    {
        Global_pvTimer0CTCCallBack();
    }
    else
    {
    }
}

/*                                    Timer0 FAST PWM MODE FUNCTIONS                                          */
/*------------------------------------------------------------------------------------------------------------*/

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
/* ------------------------------------------------------------------------------------- */
void MTIMERS_voidTimer0SetFastPWMCompareOutputMode(u8 Copy_u8CompareOutputMode)
{
    switch (Copy_u8CompareOutputMode)
    {
    case TIMER0_SET_FAST_PWM_NON_INVERTING_MODE:
        CLR_REG_BIT(TCCR0, TCCR0_COM00);
        SET_REG_BIT(TCCR0, TCCR0_COM01);
        break;

    case TIMER0_SET_FAST_PWM_INVERTING_MODE:
        SET_REG_BIT(TCCR0, TCCR0_COM00);
        SET_REG_BIT(TCCR0, TCCR0_COM01);
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
/* ------------------------------------------------------------------------------------- */
void MTIMERS_voidTimer0SetFastPWMFrequency(u8 Copy_u8Frequency)
{
    switch (Copy_u8Frequency)
    {
    case TIMER0_SET_FAST_PWM_FREQ_31_25_KHZ:
        TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
        TCCR0 |= TIMER0_SET_FAST_PWM_FREQ_31_25_KHZ;
        break;

    case TIMER0_SET_FAST_PWM_FREQ_3_91_KHZ:
        TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
        TCCR0 |= TIMER0_SET_FAST_PWM_FREQ_3_91_KHZ;
        break;

    case TIMER0_SET_FAST_PWM_FREQ_488_HZ:
        TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
        TCCR0 |= TIMER0_SET_FAST_PWM_FREQ_488_HZ;
        break;

    case TIMER0_SET_FAST_PWM_FREQ_122_HZ:
        TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
        TCCR0 |= TIMER0_SET_FAST_PWM_FREQ_122_HZ;
        break;

    case TIMER0_SET_FAST_PWM_FREQ_30_5_HZ:
        TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
        TCCR0 |= TIMER0_SET_FAST_PWM_FREQ_30_5_HZ;
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
/* ------------------------------------------------------------------------------------- */
void MTIMERS_voidTimer0SetFastPWMModePWMValue(u8 Copy_u8PWMValue)
{
    OCR0 = Copy_u8PWMValue;
}


/*                                  Timer0 PHASE CORRECT MODE FUNCTIONS                                       */
/*------------------------------------------------------------------------------------------------------------*/

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
/* ------------------------------------------------------------------------------------- */
void MTIMERS_voidTimer0SetPWMCompareOutputMode(u8 Copy_u8CompareOutputMode)
{
    switch (Copy_u8CompareOutputMode)
    {
    case TIMER0_SET_PWM_NON_INVERTING_MODE:
        CLR_REG_BIT(TCCR0, TCCR0_COM00);
        SET_REG_BIT(TCCR0, TCCR0_COM01);
        break;

    case TIMER0_SET_PWM_INVERTING_MODE:
        SET_REG_BIT(TCCR0, TCCR0_COM00);
        SET_REG_BIT(TCCR0, TCCR0_COM01);
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
/* ------------------------------------------------------------------------------------- */
void MTIMERS_voidTimer0SetPWMFrequency(u8 Copy_u8Frequency)
{
    switch (Copy_u8Frequency)
    {
    case TIMER0_SET_PWM_FREQ_15_69_KHZ:
        TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
        TCCR0 |= TIMER0_SET_PWM_FREQ_15_69_KHZ;
        break;

    case TIMER0_SET_PWM_FREQ_1_96_KHZ:
        TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
        TCCR0 |= TIMER0_SET_PWM_FREQ_1_96_KHZ;
        break;

    case TIMER0_SET_PWM_FREQ_245_HZ:
        TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
        TCCR0 |= TIMER0_SET_PWM_FREQ_245_HZ;
        break;

    case TIMER0_SET_PWM_FREQ_61_27_HZ:
        TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
        TCCR0 |= TIMER0_SET_PWM_FREQ_61_27_HZ;
        break;

    case TIMER0_SET_PWM_FREQ_15_32_HZ:
        TCCR0 &= TIMER0_PRESCALER_MASK_VALUE;
        TCCR0 |= TIMER0_SET_PWM_FREQ_15_32_HZ;
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
/* ------------------------------------------------------------------------------------- */
void MTIMERS_voidTimer0SetPWMModePWMValue(u8 Copy_u8PWMValue)
{
    OCR0 = Copy_u8PWMValue;
}

/* ---------------------------------------------------------------------------------------------------------- */
/*                                              TIMER1 FUNCTIONS                                              */
/* ---------------------------------------------------------------------------------------------------------- */

/*                                      TIMER1 POST BUILD FUNCTIONS                                           */
/* ---------------------------------------------------------------------------------------------------------- */

/*                                      TIMER1 CONFIGURATION FUNCTIONS                                        */

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
/* ------------------------------------------------------------------------------------- */
void MTIMERS_voidTimer1Disable(void)
{
    TCCR1B &= TIMER1_PRESCALER_MASK_VALUE;
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
/* ------------------------------------------------------------------------------------- */
void MTIMERS_voidSetTimer1Mode(u8 Copy_Timer1Mode)
{
    switch (Copy_Timer1Mode)
    {
    case TIMER1_NORMAL:
        TCCR1A &= TIMER1_MODE_WGM1110_MASK_VALUE;
        TCCR1A |= (TIMER1_NORMAL&0b0011);
        TCCR1B &= TIMER1_MODE_WGM1312_MASK_VALUE;
        TCCR1B |= ((TIMER1_NORMAL&0b0011) << 3);
        break;
    case TIMER1_PWM_PC_8_BIT:
        TCCR1A &= TIMER1_MODE_WGM1110_MASK_VALUE;
        TCCR1A |= (TIMER1_PWM_PC_8_BIT&0b0011);
        TCCR1B &= TIMER1_MODE_WGM1312_MASK_VALUE;
        TCCR1B |= ((TIMER1_PWM_PC_8_BIT&0b0011) << 3);
        break;
    case TIMER1_PWM_PC_9_BIT:
        TCCR1A &= TIMER1_MODE_WGM1110_MASK_VALUE;
        TCCR1A |= (TIMER1_PWM_PC_9_BIT&0b0011);
        TCCR1B &= TIMER1_MODE_WGM1312_MASK_VALUE;
        TCCR1B |= ((TIMER1_PWM_PC_9_BIT&0b0011) << 3);
        break;
    case TIMER1_PWM_PC_10_BIT:
        TCCR1A &= TIMER1_MODE_WGM1110_MASK_VALUE;
        TCCR1A |= (TIMER1_PWM_PC_10_BIT&0b0011);
        TCCR1B &= TIMER1_MODE_WGM1312_MASK_VALUE;
        TCCR1B |= ((TIMER1_PWM_PC_10_BIT&0b0011) << 3);
        break;
    case TIMER1_CTC_OCR1A:
        TCCR1A &= TIMER1_MODE_WGM1110_MASK_VALUE;
        TCCR1A |= (TIMER1_CTC_OCR1A&0b0011);
        TCCR1B &= TIMER1_MODE_WGM1312_MASK_VALUE;
        TCCR1B |= ((TIMER1_CTC_OCR1A&0b0011) << 3);
        break;
    case TIMER1_FAST_PWM_8_BIT:
        TCCR1A &= TIMER1_MODE_WGM1110_MASK_VALUE;
        TCCR1A |= (TIMER1_FAST_PWM_8_BIT&0b0011);
        TCCR1B &= TIMER1_MODE_WGM1312_MASK_VALUE;
        TCCR1B |= ((TIMER1_FAST_PWM_8_BIT&0b0011) << 3);
        break;
    case TIMER1_FAST_PWM_9_BIT:
        TCCR1A &= TIMER1_MODE_WGM1110_MASK_VALUE;
        TCCR1A |= (TIMER1_FAST_PWM_9_BIT&0b0011);
        TCCR1B &= TIMER1_MODE_WGM1312_MASK_VALUE;
        TCCR1B |= ((TIMER1_FAST_PWM_9_BIT&0b0011) << 3);
        break;
    case TIMER1_FAST_PWM_10_BIT:
        TCCR1A &= TIMER1_MODE_WGM1110_MASK_VALUE;
        TCCR1A |= (TIMER1_FAST_PWM_10_BIT&0b0011);
        TCCR1B &= TIMER1_MODE_WGM1312_MASK_VALUE;
        TCCR1B |= ((TIMER1_FAST_PWM_10_BIT&0b0011) << 3);
        break;
    case TIMER1_PWM_PFC_ICR1:
        TCCR1A &= TIMER1_MODE_WGM1110_MASK_VALUE;
        TCCR1A |= (TIMER1_PWM_PFC_ICR1&0b0011);
        TCCR1B &= TIMER1_MODE_WGM1312_MASK_VALUE;
        TCCR1B |= ((TIMER1_PWM_PFC_ICR1&0b0011) << 3);
        break;
    case TIMER1_PWM_PFC_OCR1A:
        TCCR1A &= TIMER1_MODE_WGM1110_MASK_VALUE;
        TCCR1A |= (TIMER1_PWM_PFC_OCR1A&0b0011);
        TCCR1B &= TIMER1_MODE_WGM1312_MASK_VALUE;
        TCCR1B |= ((TIMER1_PWM_PFC_OCR1A&0b0011) << 3);
        break;
    case TIMER1_PWM_PC_ICR1:
        TCCR1A &= TIMER1_MODE_WGM1110_MASK_VALUE;
        TCCR1A |= (TIMER1_PWM_PC_ICR1&0b0011);
        TCCR1B &= TIMER1_MODE_WGM1312_MASK_VALUE;
        TCCR1B |= ((TIMER1_PWM_PC_ICR1&0b0011) << 3);
        break;
    case TIMER1_PWM_PC_OCR1A:
        TCCR1A &= TIMER1_MODE_WGM1110_MASK_VALUE;
        TCCR1A |= (TIMER1_PWM_PC_OCR1A&0b0011);
        TCCR1B &= TIMER1_MODE_WGM1312_MASK_VALUE;
        TCCR1B |= ((TIMER1_PWM_PC_OCR1A&0b0011) << 3);
        break;
    case TIMER1_CTC_ICR1:
        TCCR1A &= TIMER1_MODE_WGM1110_MASK_VALUE;
        TCCR1A |= (TIMER1_CTC_ICR1&0b0011);
        TCCR1B &= TIMER1_MODE_WGM1312_MASK_VALUE;
        TCCR1B |= ((TIMER1_CTC_ICR1&0b0011) << 3);
        break;
    case TIMER1_FAST_PWM_ICR1:
        TCCR1A &= TIMER1_MODE_WGM1110_MASK_VALUE;
        TCCR1A |= (TIMER1_FAST_PWM_ICR1&0b0011);
        TCCR1B &= TIMER1_MODE_WGM1312_MASK_VALUE;
        TCCR1B |= ((TIMER1_FAST_PWM_ICR1&0b0011) << 3);
        break;
    case TIMER1_FAST_PWM_OCR1A:
        TCCR1A &= TIMER1_MODE_WGM1110_MASK_VALUE;
        TCCR1A |= (TIMER1_FAST_PWM_OCR1A&0b0011);
        TCCR1B &= TIMER1_MODE_WGM1312_MASK_VALUE;
        TCCR1B |= ((TIMER1_FAST_PWM_OCR1A&0b0011) << 3);
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
/* ------------------------------------------------------------------------------------- */
void MTIMERS_voidSetTimer1Prescaler(u8 Copy_u8Timer1Prescaler)
{
    switch (Copy_u8Timer1Prescaler)
    {
    case TIMER1_CLKIO_1_PRESCALER:
        TCCR1B &= TIMER1_PRESCALER_MASK_VALUE;
        TCCR1B |= TIMER1_CLKIO_1_PRESCALER;
        break;

    case TIMER1_CLKIO_8_PRESCALER:
        TCCR1B &= TIMER1_PRESCALER_MASK_VALUE;
        TCCR1B |= TIMER1_CLKIO_8_PRESCALER;
        break;

    case TIMER1_CLKIO_64_PRESCALER:
        TCCR1B &= TIMER1_PRESCALER_MASK_VALUE;
        TCCR1B |= TIMER1_CLKIO_64_PRESCALER;
        break;

    case TIMER1_CLKIO_256_PRESCALER:
        TCCR1B &= TIMER1_PRESCALER_MASK_VALUE;
        TCCR1B |= TIMER1_CLKIO_256_PRESCALER;
        break;

    case TIMER1_CLKIO_1024_PRESCALER:
        TCCR1B &= TIMER1_PRESCALER_MASK_VALUE;
        TCCR1B |= TIMER1_CLKIO_1024_PRESCALER;
        break;

    case TIMER1_EXTERNAL_SOURCE_FAILING_EDGE:
        TCCR1B &= TIMER1_PRESCALER_MASK_VALUE;
        TCCR1B |= TIMER1_EXTERNAL_SOURCE_FAILING_EDGE;
        break;

    case TIMER1_EXTERNAL_SOURCE_RISING_EDGE:
        TCCR1B &= TIMER1_PRESCALER_MASK_VALUE;
        TCCR1B |= TIMER1_EXTERNAL_SOURCE_RISING_EDGE;
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
/* ------------------------------------------------------------------------------------- */
void MTIMERS_voidTimer1OVFSetPreloadValue(u16 Copy_u16PreloadValue)
{
    TCNT1 = Copy_u16PreloadValue;
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
/* ------------------------------------------------------------------------------------- */
void MTIMERS_voidTimer1OVFInterruptEnable(u8 Copy_u8State)
{
    switch(Copy_u8State)
    {
        case ENABLE:
            SET_REG_BIT(TIMSK,TIMSK_TOIE1);
        break;
        case DISBALE:
            CLR_REG_BIT(TIMSK,TIMSK_TOIE1);
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
static void (*Global_pvTimer1OVFCallBack)(void) = NULL;

void MTIMERS_voidTimer1OVFSetCallBack(void (*Copy_pvCallBackFunction)(void))
{
    Global_pvTimer1OVFCallBack = Copy_pvCallBackFunction;
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
/* ------------------------------------------------------------------------------------- */
void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
    if (Global_pvTimer1OVFCallBack != NULL)
    {
        Global_pvTimer1OVFCallBack();
    }
    else
    {
    }
}

#define TIMER1_CHANNEL_1A       0
#define TIMER1_CHANNEL_1B       1

#define COM_NON_INVERTING_MODE      0
#define COM_INVERTING_MODE          1
void MTIMERS_voidTimer1SetCompareOutputMode(u8 Copy_u8ChannelNumber,u8 Copy_u8CompareOutputMode)
{
    switch(Copy_u8ChannelNumber)
    {
        case TIMER1_CHANNEL_1A:
            switch(Copy_u8CompareOutputMode)
            {
                case COM_NON_INVERTING_MODE:
                    CLR_REG_BIT(TCCR1A, TCCR1A_COM1A0);
                    SET_REG_BIT(TCCR1A, TCCR1A_COM1A1);
                break;
                case COM_INVERTING_MODE:
                    SET_REG_BIT(TCCR1A, TCCR1A_COM1A0);
                    SET_REG_BIT(TCCR1A, TCCR1A_COM1A1);
                break;
            }
        break;
        case TIMER1_CHANNEL_1B:
            switch(Copy_u8CompareOutputMode)
                {
                    case COM_NON_INVERTING_MODE:
                        CLR_REG_BIT(TCCR1A, TCCR1A_COM1B0);
                        SET_REG_BIT(TCCR1A, TCCR1A_COM1B1);
                    break;
                    case COM_INVERTING_MODE:
                        SET_REG_BIT(TCCR1A, TCCR1A_COM1B0);
                        SET_REG_BIT(TCCR1A, TCCR1A_COM1B1);
                    break;
                }
        break;
    }
}

void MTIMERS_voidTimer1SetCompareMatchValue(u8 Copy_u8ChannelNumber, u16 Copy_u16CompareMatchValue)
{
    switch(Copy_u8ChannelNumber)
    {
        case TIMER1_CHANNEL_1A:
            OCR1A = Copy_u16CompareMatchValue;
        break;
        case TIMER1_CHANNEL_1B:
            OCR1B = Copy_u16CompareMatchValue;
        break;
    }
}

void MTIMERS_voidTimer1SetCTCInterruptState(u8 Copy_u8ChannelNumber, u8 Copy_u8interruptState)
{
    switch(Copy_u8ChannelNumber)
    {
        case TIMER1_CHANNEL_1A:
            switch(Copy_u8interruptState)
            {
                case ENABLE:
                    SET_REG_BIT(TIMSK,TIMSK_OCIE1A);
                break;
                case DISBALE:
                    CLR_REG_BIT(TIMSK,TIMSK_OCIE1A);
                break;
            }
        break;
        case TIMER1_CHANNEL_1B:
            switch(Copy_u8interruptState)
            {
                case ENABLE:
                    SET_REG_BIT(TIMSK,TIMSK_OCIE1B);
                break;
                case DISBALE:
                    CLR_REG_BIT(TIMSK,TIMSK_OCIE1B);
                break;
            }
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
void MTIMERS_voidTimer1SetTopValue(u16 Copy_u16TopValue)
{
    ICR1 = Copy_u16TopValue;
}

/*
void MTIMERS_voidICUSetSenseSignal(u8 Copy_u8Signal)
{
    switch(Copy_u8Signal)
    {
        case FAILING_EDGE:
            CLR_REG_BIT(TCCR1B,TCCR1B_ICES1);
        break;
        case RISING_EDGE:
            SET_REG_BIT(TCCR1B,TCCR1B_ICES1);
        break;
    }
}

void MTIMERS_u16GetICR(void)
{
    return ICR1;
}

void MTIMERS_voidICUInterruptState(u8 Copy_u8InterruptState)
{
    switch(Copy_u8InterruptState)
    {
        case ENABLE:
            SET_REG_BIT(TIMSK,TIMSK_TICIE1);
        break;
        case DISABLE:
            CLR_REG_BIT(TIMSK,TIMSK_TICIE1);
        break;
    }
}

static void (*ICU_pvCallBackFunction)(void) = NULL;
void MTIMERS_voidICUSetCallBackFunction(void(*Copy_pvCallBackFunction)(void))
{
    ICU_pvCallBackFunction = Copy_pvCallBackFunction;
}

void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
    if(ICU_pvCallBackFunction != NULL)
    {
        ICU_pvCallBackFunction();
    }
    else
    {

    }
}
*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                                              TIMER2 FUNCTIONS                                              */
/* ---------------------------------------------------------------------------------------------------------- */

/*                                         TIMER2 POST BUILD FUNCTIONS                                        */
/* ---------------------------------------------------------------------------------------------------------- */

/*                                        TIMER2 CONFIGURATION FUNCTIONS                                      */

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
void MTIMERS_voidTimer2Disable(void)
{
    TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
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
void MTIMERS_voidTimer2SetMode(u8 Copy_u8Timer2Mode)
{
    switch (Copy_u8Timer2Mode)
    {
    case TIMER2_MODE_NORMAL:
        CLR_REG_BIT(TCCR2, TCCR2_WGM20);
        CLR_REG_BIT(TCCR2, TCCR2_WGM21);
        break;

    case TIMER2_MODE_PWM:
        SET_REG_BIT(TCCR2, TCCR2_WGM20);
        CLR_REG_BIT(TCCR2, TCCR2_WGM21);
        break;

    case TIMER2_MODE_CTC:
        CLR_REG_BIT(TCCR2, TCCR2_WGM20);
        SET_REG_BIT(TCCR2, TCCR2_WGM21);
        break;

    case TIMER2_MODE_FAST_PWM:
        SET_REG_BIT(TCCR2, TCCR2_WGM20);
        SET_REG_BIT(TCCR2, TCCR2_WGM21);
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
void MTIMERS_voidTimer2SetPrescaler(u8 Copy_u8Timer2Prescaler)
{
    switch (Copy_u8Timer2Prescaler)
    {
    case TIMER2_PRESCALER_CLKIO_1:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_PRESCALER_CLKIO_1;
        break;

    case TIMER2_PRESCALER_CLKIO_8:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_PRESCALER_CLKIO_8;
        break;

    case TIMER2_PRESCALER_CLKIO_32:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_PRESCALER_CLKIO_32;
        break;

    case TIMER2_PRESCALER_CLKIO_64:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_PRESCALER_CLKIO_64;
        break;

    case TIMER2_PRESCALER_CLKIO_128:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_PRESCALER_CLKIO_128;
        break;

    case TIMER2_PRESCALER_CLKIO_256:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_PRESCALER_CLKIO_256;
        break;

    case TIMER2_PRESCALER_CLKIO_1024:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_PRESCALER_CLKIO_1024;
        break;
    }
}

/*_______________________________________________________________________*/


/*                                        Timer2 OVERFLOW MODE FUNCTIONS                                      */


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
void MTIMERS_voidTimer2OVFSetPreloadValue(u8 Copy_u8PreloadValue)
{
    TCNT2 = Copy_u8PreloadValue;
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
static void (*Global_pvTimer2OVFCallBack)(void) = NULL;

void MTIMERS_voidTimer2OVFSetCallBack(void (*Copy_pvCallBackFunction)(void))
{
    Global_pvTimer2OVFCallBack = Copy_pvCallBackFunction;
}

void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
    if (Global_pvTimer2OVFCallBack != NULL)
    {
        Global_pvTimer2OVFCallBack();
    }
    else
    {
    }
}


/*                                Timer2 CLEAR ON COMPARE MODE FUNCTIONS                                      */

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
void MTIMERS_voidTimer2CTCSetCompareMatchValue(u8 Copy_u8CompareMatchValue)
{
    OCR2 = Copy_u8CompareMatchValue;
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
void MTIMERS_voidTimer2CTCSetBusyWait_ms(u32 Copy_u32MilliSeconds)
{
    /* SET TIMER2 IN CTC MODE */
    CLR_REG_BIT(TCCR2, TCCR2_WGM20);
    SET_REG_BIT(TCCR2, TCCR2_WGM21);
    /*SET PRESCALER TO 64*/
    TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
    TCCR2 |= TIMER2_PRESCALER_CLKIO_64;
    /*DISABLE TIMER2 CTC INTERRUPT*/
    CLR_REG_BIT(TIMSK, TIMSK_OCIE2);
    /* CLEAR COMPARE MATCH FLAG */
    SET_REG_BIT(TIFR, TIFR_OCF2);
    /*SET OCR0 VALUE TO 1*/
    OCR2 = 125; // COMPARE MATCH VALUE
    u32 Local_u32TickCount = 0;
    while (Local_u32TickCount < Copy_u32MilliSeconds)
    {
        if (GET_BIT(TIFR, TIFR_OCF2) == 1)
        {
            Local_u32TickCount++;
            SET_REG_BIT(TIFR, TIFR_OCF2);
        }
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
void MTIMERS_voidTimer2CTCSetBusyWait_us(u32 Copy_u32MicroSeconds)
{
    /* SET TIMER2 IN CTC MODE */
    CLR_REG_BIT(TCCR2, TCCR2_WGM20);
    SET_REG_BIT(TCCR2, TCCR2_WGM21);
    /*SET PRESCALER TO 8*/
    TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
    TCCR2 |= TIMER2_PRESCALER_CLKIO_64;
    /* CLEAR COMPARE MATCH FLAG */
    SET_REG_BIT(TIFR, TIFR_OCF2);
    /*DISABLE TIMER2 CTC INTERRUPT*/
    CLR_REG_BIT(TIMSK, TIMSK_OCIE2);
    /*SET OCR0 VALUE TO 1*/
    OCR0 = 1; // COMPARE MATCH VALUE
    u32 Local_u32TickCount = 0;
    while (Local_u32TickCount < Copy_u32MicroSeconds)
    {
        if (GET_BIT(TIFR, TIFR_OCF2) == 1)
        {
            Local_u32TickCount++;
            SET_REG_BIT(TIFR, TIFR_OCF2);
        }
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
void MTIMERS_voidTimer2SetOC0PinModeinCTCMode(u8 Copy_u8OC0State)
{
    switch (Copy_u8OC0State)
    {
    case TIMER2_OC2_MODE_NORMAL:
        CLR_REG_BIT(TCCR2, TCCR2_COM20);
        CLR_REG_BIT(TCCR2, TCCR2_COM21);
        break;
    case TIMER2_OC2_MODE_TOGGLE:
        SET_REG_BIT(TCCR2, TCCR2_COM20);
        CLR_REG_BIT(TCCR2, TCCR2_COM21);
        break;
    case TIMER2_OC2_MODE_CLEAR:
        CLR_REG_BIT(TCCR2, TCCR2_COM20);
        SET_REG_BIT(TCCR2, TCCR2_COM21);
        break;
    case TIMER2_OC2_MODE_SET:
        SET_REG_BIT(TCCR2, TCCR2_COM20);
        SET_REG_BIT(TCCR2, TCCR2_COM21);
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
static void (*Global_pvTimer2CTCCallBack)(void) = NULL;

void MTIMERS_voidTimer2CTCSetCallBack(void (*Copy_pvCallBackFunction)(void))
{
    Global_pvTimer2CTCCallBack = Copy_pvCallBackFunction;
}

void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
    if (Global_pvTimer2CTCCallBack != NULL)
    {
        Global_pvTimer2CTCCallBack();
    }
    else
    {
    }
}


/*                                    Timer2 FAST PWM MODE FUNCTIONS                                          */

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
void MTIMERS_voidTimer2SetFastPWMCompareOutputMode(u8 Copy_u8CompareOutputMode)
{
    switch (Copy_u8CompareOutputMode)
    {
    case TIMER2_SET_FAST_PWM_NON_INVERTING_MODE:
        CLR_REG_BIT(TCCR2, TCCR2_COM20);
        SET_REG_BIT(TCCR2, TCCR2_COM21);
        break;

    case TIMER2_SET_FAST_PWM_INVERTING_MODE:
        SET_REG_BIT(TCCR2, TCCR2_COM20);
        SET_REG_BIT(TCCR2, TCCR2_COM21);
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
void MTIMERS_voidTimer2SetFastPWMFrequency(u8 Copy_u8Frequency)
{
    switch (Copy_u8Frequency)
    {
    case TIMER2_SET_FAST_PWM_FREQ_31_25_KHZ:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_SET_FAST_PWM_FREQ_31_25_KHZ;
        break;

    case TIMER2_SET_FAST_PWM_FREQ_3_91_KHZ:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_SET_FAST_PWM_FREQ_3_91_KHZ;
        break;

    case TIMER2_SET_FAST_PWM_FREQ_488_25_HZ:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_SET_FAST_PWM_FREQ_488_25_HZ;
        break;

    case TIMER2_SET_FAST_PWM_FREQ_244_14_HZ:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_SET_FAST_PWM_FREQ_244_14_HZ;
        break;

    case TIMER2_SET_FAST_PWM_FREQ_122_1_HZ:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_SET_FAST_PWM_FREQ_122_1_HZ;
        break;

    case TIMER2_SET_FAST_PWM_FREQ_30_52_HZ:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_SET_FAST_PWM_FREQ_30_52_HZ;
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
void MTIMERS_voidTimer2SetFastPWMModePWMValue(u8 Copy_u8PWMValue)
{
    OCR2 = Copy_u8PWMValue;
}

/*                                  Timer2 PHASE CORRECT MODE FUNCTIONS                                       */

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
void MTIMERS_voidTimer2SetPWMCompareOutputMode(u8 Copy_u8CompareOutputMode)
{
    switch (Copy_u8CompareOutputMode)
    {
    case TIMER2_SET_PWM_NON_INVERTING_MODE:
        CLR_REG_BIT(TCCR2, TCCR2_COM20);
        SET_REG_BIT(TCCR2, TCCR2_COM21);
        break;

    case TIMER2_SET_PWM_INVERTING_MODE:
        SET_REG_BIT(TCCR2, TCCR2_COM20);
        SET_REG_BIT(TCCR2, TCCR2_COM21);
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
#define TIMER2_SET_PWM_FREQ_15_69_KHZ          1
#define TIMER2_SET_PWM_FREQ_1_96_KHZ           2
#define TIMER2_SET_PWM_FREQ_490_19_HZ          3
#define TIMER2_SET_PWM_FREQ_245_08_HZ          4
#define TIMER2_SET_PWM_FREQ_122_55_HZ          5
#define TIMER2_SET_PWM_FREQ_61_29_HZ           6
#define TIMER2_SET_PWM_FREQ_15_32_HZ           7

void MTIMERS_voidTimer2SetPWMFrequency(u8 Copy_u8Frequency)
{
    switch (Copy_u8Frequency)
    {
    case TIMER2_SET_PWM_FREQ_15_69_KHZ:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_SET_PWM_FREQ_15_69_KHZ;
        break;

    case TIMER2_SET_PWM_FREQ_1_96_KHZ:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_SET_PWM_FREQ_1_96_KHZ;
        break;

    case TIMER2_SET_PWM_FREQ_490_19_HZ:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_SET_PWM_FREQ_490_19_HZ;
        break;

    case TIMER2_SET_PWM_FREQ_245_08_HZ:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_SET_PWM_FREQ_245_08_HZ;
        break;

    case TIMER2_SET_PWM_FREQ_122_55_HZ:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_SET_PWM_FREQ_122_55_HZ;
        break;

    case TIMER2_SET_PWM_FREQ_61_29_HZ:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_SET_PWM_FREQ_61_29_HZ;
        break;

    case TIMER2_SET_PWM_FREQ_15_32_HZ:
        TCCR2 &= TIMER2_PRESCALER_MASK_VALUE;
        TCCR2 |= TIMER2_SET_PWM_FREQ_15_32_HZ;
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
void MTIMERS_voidTimer2SetPWMModePWMValue(u8 Copy_u8PWMValue)
{
    OCR2 = Copy_u8PWMValue;
}

