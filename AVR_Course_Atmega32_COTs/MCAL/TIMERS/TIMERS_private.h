/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	TIMERS Driver                             							  	      */
/*  Project Description    :	TIMERS Driver                                                 				  */
/*  Target Controller 	   :	Atmega 32                                               					  */
/*  File Name              :	TIMERS_private.h                                    						  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                              */
#ifndef     TIMERS_PRIVATE_H
#define 	TIMERS_PRIVATE_H

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Registers Definitions       		     		          	  	              */
/* ---------------------------------------------------------------------------------------------------------- */

/*                           		     TIMER0 Registers Definitions       		     		          	  */

/*		                Timer 0 Register							           */
/*_____________________________________________________________________________*/

#define TCCR0                               *((volatile u8 *)0x53)                      //TCCR0 – Timer/Counter Control Register
#define TCCR0_CS00                          0                                           //Bit 0 - CS00: Clock Select Bit0
#define TCCR0_CS01                          1                                           //Bit 1 - CS00: Clock Select Bit1
#define TCCR0_CS02                          2                                           //Bit 2 - CS00: Clock Select Bit2
#define TCCR0_WGM01                         3                                           //Bit 3 - WGM00 : Waveform Generation Mode Bit1
#define TCCR0_COM00                         4                                           //Bit 4 - COM00 : Compare Match Output Mode Bit0
#define TCCR0_COM01                         5                                           //Bit 5 - COM01 : Compare Match Output Mode Bit1
#define TCCR0_WGM00                         6                                           //Bit 6 - WGM00 : Waveform Generation Mode Bit0
#define TCCR0_FOC0                          7                                           //Bit 7 – FOC0: Force Output Compare

/*_____________________________________________________________________________*/

#define TIMER0_PRESCALER_MASK_VALUE         0b11111000

/*_____________________________________________________________________________*/

#define TCNT0                               *((volatile u8 *)0x52)                      //Timer/Counter Register
#define OCR0                                *((volatile u8 *)0x5C)                      //Output Compare Register

/*_____________________________________________________________________________*/

#define TIMSK                               *((volatile u8 *)0x59)                      //Timer/Counter Interrupt Mask Register
#define TIMSK_TOIE0                         0                                           //Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable
#define TIMSk_OCIE0                         1                                           //Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable

/*_____________________________________________________________________________*/

#define TIFR                                *((volatile u8 *)0x58)                      //Timer/Counter Interrupt Flag Register
#define TIFR_TOV0                           0                                           //Bit 0 – TOV0: Timer/Counter0 Overflow Flag
#define TIFR_OCF0                           1                                           //Bit 1 – OCF0: Output Compare Flag 0

/*_____________________________________________________________________________*/

/*                           		     TIMER1 Registers Definitions       		     		          	  */

/*		                Timer 1 Registers/Bits Definition				       */
/*_____________________________________________________________________________*/

#define TCCR1A                              *((volatile u8 *)0X4F)
#define TCCR1A_WGM10                        0
#define TCCR1A_WGM11                        1
#define TCCR1A_FOC1B                        2
#define TCCR1A_FOC1A                        3
#define TCCR1A_COM1B0                       4
#define TCCR1A_COM1B1                       5
#define TCCR1A_COM1A0                       6
#define TCCR1A_COM1A1                       7

/*_____________________________________________________________________________*/

#define TCCR1B                              *((volatile u8 *)0X4E)
#define TCCR1B_CS10                         0
#define TCCR1B_CS11                         1
#define TCCR1B_CS12                         2
#define TCCR1B_WGM12                        3
#define TCCR1B_WGM13                        4
#define TCCR1B_ICES1                        6
#define TCCR1B_ICNC1                        7

/*_____________________________________________________________________________*/

#define TIMER1_MODE_WGM1110_MASK_VALUE      0b11111100
#define TIMER1_MODE_WGM1312_MASK_VALUE      0b11100111

#define TIMER1_PRESCALER_MASK_VALUE         0b11111000

/*_____________________________________________________________________________*/

#define TCNT1H                              *((volatile u8 *)0X4D)
#define TCNT1L                              *((volatile u8 *)0X4C)
#define TCNT1                               *((volatile u16 *)0X4C)

/*_____________________________________________________________________________*/

#define OCR1AH                              *((volatile u8 *)0X4B)
#define OCR1AL                              *((volatile u8 *)0X4A)
#define OCR1A                               *((volatile u16 *)0X4A)

/*_____________________________________________________________________________*/

#define OCR1BH                              *((volatile u8 *)0X49)
#define OCR1BL                              *((volatile u8 *)0X48)
#define OCR1B                               *((volatile u16 *)0X48)

/*_____________________________________________________________________________*/

#define ICR1H                               *((volatile u8 *)0X47)
#define ICR1L                               *((volatile u8 *)0X46)
#define ICR1                                *((volatile u16 *)0X46)

/*_____________________________________________________________________________*/

#define TIMSK_TOIE1                         2
#define TIMSK_OCIE1B                        3
#define TIMSK_OCIE1A                        4
#define TIMSK_TICIE1                        5

/*_____________________________________________________________________________*/

#define TIFR_TOV1                           2                                           //Bit 2 – TOV1 : Timer/Counter1 Overflow Flag
#define TIFR_OCF1B                          3                                           //Bit 3 – OCF1B:
#define TIFR_OCF1A                          4                                           //Bit 4 – OCF1A:
#define TIFR_ICF1                           5                                           //Bit 5 – ICF1:  Output Compare Flag 0

/*_____________________________________________________________________________*/

/*                           		     TIMER2 Registers Definitions       		     		          	  */

/*		                Timer 2 Registers/Bits Definition				 */
/*_____________________________________________________________________________*/

#define TCCR2                               *((volatile u8 *)0X45)
#define TCCR2_CS20                          0
#define TCCR2_CS21                          1
#define TCCR2_CS22                          2
#define TCCR2_WGM21                         3
#define TCCR2_COM20                         4
#define TCCR2_COM21                         5
#define TCCR2_WGM20                         6
#define TCCR2_FOC2                          7

/*_____________________________________________________________________________*/

#define TIMER2_PRESCALER_MASK_VALUE         0b11111000

/*_____________________________________________________________________________*/

#define TCNT2                               *((volatile u8 *)0X44)

/*_____________________________________________________________________________*/

#define OCR2                                *((volatile u8 *)0X43)

/*_____________________________________________________________________________*/

#define TIMSK_TOIE2                         6
#define TIMSK_OCIE2                         7

/*_____________________________________________________________________________*/

#define TIFR_TOV2                           6                                           //Bit 6 – TOV2:  Timer/Counter2 Overflow Flag
#define TIFR_OCF2                           7                                           //Bit 7 – OCF2:  Output Compare Flag 2

/*_____________________________________________________________________________*/

#define ASSR                                *((volatile u8 *)0X42)
#define ASSR_TCR2UB                         0
#define ASSR_OCR2UB                         1
#define ASSR_TCN2UB                         2
#define ASSR_AS2                            3

/*_____________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */

#define     ENABLE                                                      1
#define     DISBALE                                                     0

#define     TIMER0_OC0_NON_INVERTING_MODE_SET_TOP_CLEAR_COMPARE         2
#define     TIMER0_OC0_INVERTING_MODE_CLEAR_TOP_CLEAR_COMPARE           3

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Global Declerations       		     		          	  	  	      */
/* ---------------------------------------------------------------------------------------------------------- */


/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Prototypes       		     		          	  		      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Implementations       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

#endif