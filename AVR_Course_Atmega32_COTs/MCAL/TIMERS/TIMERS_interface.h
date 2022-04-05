/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	TIMERS Driver                             							  	      */
/*  Project Description    :	TIMERS Driver                                                 				  */
/*  Target Controller 	   :	Atmega 32                                               					  */
/*  File Name              :	TIMERS_interface.h                                    						  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                              */
#ifndef     TIMERS_INTERFACE_H
#define 	TIMERS_INTERFACE_H

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Definitions       		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Global Declerations       		     		          	  	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Interface Function Prototypes       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                                      		TIMER0 FUNCTIONS                                              */
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
void MTIMERS_voidInitTimer0(void);
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
void MTIMERS_voidTimer0Disable(void);
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

    Copy_u8Timer0Mode :
                            TIMER0_MODE_NORMAL
                            TIMER0_MODE_PWM
                            TIMER0_MODE_CTC
                            TIMER0_MODE_FAST_PWM
*/
/* ----------------------------------------------------------------------------------------------- */
#define     TIMER0_MODE_NORMAL                                               0
#define     TIMER0_MODE_PWM                                                  1
#define     TIMER0_MODE_CTC                                                  2
#define     TIMER0_MODE_FAST_PWM                                             3

void MTIMERS_voidSetTimer0Mode(u8 Copy_u8Timer0Mode);
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

    Copy_u8Timer0Prescaler :
                                TIMER0_CLKIO_1_PRESCALER
                                TIMER0_CLKIO_8_PRESCALER
                                TIMER0_CLKIO_64_PRESCALER
                                TIMER0_CLKIO_256_PRESCALER
                                TIMER0_CLKIO_1024_PRESCALER
                                TIMER0_EXTERNAL_SOURCE_FAILING_EDGE
                                TIMER0_EXTERNAL_SOURCE_RISING_EDGE
*/
/* ----------------------------------------------------------------------------------------------- */
#define     TIMER0_CLKIO_1_PRESCALER                                    1
#define     TIMER0_CLKIO_8_PRESCALER                                    2
#define     TIMER0_CLKIO_64_PRESCALER                                   3
#define     TIMER0_CLKIO_256_PRESCALER                                  4
#define     TIMER0_CLKIO_1024_PRESCALER                                 5
#define     TIMER0_EXTERNAL_SOURCE_FAILING_EDGE                         6
#define     TIMER0_EXTERNAL_SOURCE_RISING_EDGE                          7
void MTIMERS_voidSetTimer0Prescaler(u8 Copy_u8Timer0Prescaler);
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
void MTIMERS_voidTimer0OVFSetPreloadValue(u8 Copy_u8PreloadValue);
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
void MTIMERS_voidTimer0OVFSetCallBack(void(*Copy_pvCallBackFunction)(void));
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
void MTIMERS_voidTimer0CTCSetCompareMatchValue(u8 Copy_u8CompareMatchValue);
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
u32  MTIMERS_voidTimer0CTCStartMillis(void);
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
void MTIMERS_voidTimer0CTCSetBusyWait_ms(u32 Copy_u32MilliSeconds);
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
void MTIMERS_voidTimer0CTCSetBusyWait_us(u32 Copy_u32MicroSeconds);
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
#define     TIMER0_OC0_MODE_NORMAL                                           0
#define     TIMER0_OC0_MODE_TOGGLE                                           1
#define     TIMER0_OC0_MODE_CLEAR                                            2
#define     TIMER0_OC0_MODE_SET                                              3
void MTIMERS_voidTimer0SetOC0PinModeinCTCMode(u8 Copy_u8OC0PinMode);
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
void MTIMERS_voidTimer0CTCSetCallBack(void(*Copy_pvCallBackFunction)(void));
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
#define     TIMER0_SET_FAST_PWM_NON_INVERTING_MODE                      0
#define     TIMER0_SET_FAST_PWM_INVERTING_MODE                          1
void MTIMERS_voidTimer0SetFastPWMCompareOutputMode(u8 Copy_u8CompareOutputMode);
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
#define     TIMER0_SET_FAST_PWM_FREQ_31_25_KHZ                          1
#define     TIMER0_SET_FAST_PWM_FREQ_3_91_KHZ                           2
#define     TIMER0_SET_FAST_PWM_FREQ_488_HZ                             3
#define     TIMER0_SET_FAST_PWM_FREQ_122_HZ                             4
#define     TIMER0_SET_FAST_PWM_FREQ_30_5_HZ                            5
void MTIMERS_voidTimer0SetFastPWMFrequency(u8 Copy_u8Frequency);
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
void MTIMERS_voidTimer0SetFastPWMModePWMValue(u8 Copy_u8PWMValue);
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
#define     TIMER0_SET_PWM_NON_INVERTING_MODE                           0
#define     TIMER0_SET_PWM_INVERTING_MODE                               1
void MTIMERS_voidTimer0SetPWMCompareOutputMode(u8 Copy_u8CompareOutputMode);
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
#define     TIMER0_SET_PWM_FREQ_15_69_KHZ                               1
#define     TIMER0_SET_PWM_FREQ_1_96_KHZ                                2
#define     TIMER0_SET_PWM_FREQ_245_HZ                                  3
#define     TIMER0_SET_PWM_FREQ_61_27_HZ                                4
#define     TIMER0_SET_PWM_FREQ_15_32_HZ                                5
void MTIMERS_voidTimer0SetPWMFrequency(u8 Copy_u8Frequency);
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
void MTIMERS_voidTimer0SetPWMModePWMValue(u8 Copy_u8PWMValue);
/*_________________________________________________________________________________________________*/


/*                                              TIMER1 FUNCTIONS                                              */

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
void MTIMERS_voidTimer1Disable(void);
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
#define TIMER1_NORMAL               0
#define TIMER1_PWM_PC_8_BIT         1
#define TIMER1_PWM_PC_9_BIT         2
#define TIMER1_PWM_PC_10_BIT        3
#define TIMER1_CTC_OCR1A            4
#define TIMER1_FAST_PWM_8_BIT       5
#define TIMER1_FAST_PWM_9_BIT       6
#define TIMER1_FAST_PWM_10_BIT      7
#define TIMER1_PWM_PFC_ICR1         8
#define TIMER1_PWM_PFC_OCR1A        9
#define TIMER1_PWM_PC_ICR1          10
#define TIMER1_PWM_PC_OCR1A         11
#define TIMER1_CTC_ICR1             12
#define TIMER1_FAST_PWM_ICR1        14
#define TIMER1_FAST_PWM_OCR1A       15

void MTIMERS_voidSetTimer1Mode(u8 Copy_Timer1Mode);
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
#define     TIMER1_CLKIO_1_PRESCALER                                    1
#define     TIMER1_CLKIO_8_PRESCALER                                    2
#define     TIMER1_CLKIO_64_PRESCALER                                   3
#define     TIMER1_CLKIO_256_PRESCALER                                  4
#define     TIMER1_CLKIO_1024_PRESCALER                                 5
#define     TIMER1_EXTERNAL_SOURCE_FAILING_EDGE                         6
#define     TIMER1_EXTERNAL_SOURCE_RISING_EDGE                          7

void MTIMERS_voidSetTimer1Prescaler(u8 Copy_u8Timer1Prescaler);
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
#define     TIMER1_SET_FAST_PWM_NON_INVERTING_MODE      0
#define     TIMER1_SET_FAST_PWM_INVERTING_MODE          1
void MTIMERS_voidTimer1SetFastPWMChannel1ACompareOutputMode(u8 Copy_u8CompareOutputMode);
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
void MTIMERS_voidTimer1SetFastPWMChannel1BCompareOutputMode(u8 Copy_u8CompareOutputMode);
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
void MTIMERS_voidSetTimer1Channel1ACompareMatchValue(u16 Copy_u16CompareMatchValue);
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
void MTIMERS_voidSetTimer1Channel1BCompareMatchValue(u16 Copy_u16CompareMatchValue);
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
void MTIMERS_voidTimer1SetTopValue(u16 Copy_u16TopValue);
/*_________________________________________________________________________________________________*/


/*                                              TIMER2 FUNCTIONS                                              */

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
void MTIMERS_voidTimer2Disable(void);
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
#define     TIMER2_MODE_NORMAL          0
#define     TIMER2_MODE_PWM             1
#define     TIMER2_MODE_CTC             2
#define     TIMER2_MODE_FAST_PWM        3
void MTIMERS_voidTimer2SetMode(u8 Copy_u8Timer2Mode);
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
#define     TIMER2_PRESCALER_CLKIO_1            1
#define     TIMER2_PRESCALER_CLKIO_8            2
#define     TIMER2_PRESCALER_CLKIO_32           3
#define     TIMER2_PRESCALER_CLKIO_64           4
#define     TIMER2_PRESCALER_CLKIO_128          5
#define     TIMER2_PRESCALER_CLKIO_256          6
#define     TIMER2_PRESCALER_CLKIO_1024         7
void MTIMERS_voidTimer2SetPrescaler(u8 Copy_u8Timer2Prescaler);
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
void MTIMERS_voidTimer2OVFSetPreloadValue(u8 Copy_u8PreloadValue);
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
void MTIMERS_voidTimer2OVFSetCallBack(void (*Copy_pvCallBackFunction)(void));
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
void MTIMERS_voidTimer2CTCSetCompareMatchValue(u8 Copy_u8CompareMatchValue);
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
void MTIMERS_voidTimer2CTCSetBusyWait_ms(u32 Copy_u32MilliSeconds);
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
void MTIMERS_voidTimer2CTCSetBusyWait_us(u32 Copy_u32MicroSeconds);
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
#define     TIMER2_OC2_MODE_NORMAL          0
#define     TIMER2_OC2_MODE_TOGGLE          1
#define     TIMER2_OC2_MODE_CLEAR           2
#define     TIMER2_OC2_MODE_SET             3
void MTIMERS_voidTimer2SetOC0PinModeinCTCMode(u8 Copy_u8OC0State);
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
void MTIMERS_voidTimer2CTCSetCallBack(void (*Copy_pvCallBackFunction)(void));
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
#define TIMER2_SET_FAST_PWM_NON_INVERTING_MODE          0
#define TIMER2_SET_FAST_PWM_INVERTING_MODE              1
void MTIMERS_voidTimer2SetFastPWMCompareOutputMode(u8 Copy_u8CompareOutputMode);
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
#define TIMER2_SET_FAST_PWM_FREQ_31_25_KHZ          1
#define TIMER2_SET_FAST_PWM_FREQ_3_91_KHZ           2
#define TIMER2_SET_FAST_PWM_FREQ_976_56_HZ          3
#define TIMER2_SET_FAST_PWM_FREQ_488_25_HZ          4
#define TIMER2_SET_FAST_PWM_FREQ_244_14_HZ          5
#define TIMER2_SET_FAST_PWM_FREQ_122_1_HZ           6
#define TIMER2_SET_FAST_PWM_FREQ_30_52_HZ           7
void MTIMERS_voidTimer2SetFastPWMFrequency(u8 Copy_u8Frequency);
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
void MTIMERS_voidTimer2SetFastPWMModePWMValue(u8 Copy_u8PWMValue);
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
#define     TIMER2_SET_PWM_NON_INVERTING_MODE       0
#define     TIMER2_SET_PWM_INVERTING_MODE           1
void MTIMERS_voidTimer2SetPWMCompareOutputMode(u8 Copy_u8CompareOutputMode);
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
#define TIMER2_SET_PWM_FREQ_15_69_KHZ          1
#define TIMER2_SET_PWM_FREQ_1_96_KHZ           2
#define TIMER2_SET_PWM_FREQ_490_19_HZ          3
#define TIMER2_SET_PWM_FREQ_245_08_HZ          4
#define TIMER2_SET_PWM_FREQ_122_55_HZ          5
#define TIMER2_SET_PWM_FREQ_61_29_HZ           6
#define TIMER2_SET_PWM_FREQ_15_32_HZ           7
void MTIMERS_voidTimer2SetPWMFrequency(u8 Copy_u8Frequency);
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
void MTIMERS_voidTimer2SetPWMModePWMValue(u8 Copy_u8PWMValue);
/*_________________________________________________________________________________________________*/


#endif