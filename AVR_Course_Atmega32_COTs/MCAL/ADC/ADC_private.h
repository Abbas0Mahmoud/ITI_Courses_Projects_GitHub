/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          	   :  	Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	ADC Driver                             							  	          */
/*  Project Description    :	ADC Driver                                                 				      */
/*  Target Controller 	   :	Atmega 32                                               					  */
/*  File Name              :	ADC_private.h                                    						      */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	7 DEC, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
/*---------------------------------------------------------------------------------------*/
#ifndef     ADC_PRIVATE_H
#define 	ADC_PRIVATE_H
/*_______________________________________________________________________________________*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Registers Definitions       		     		          	  	              */
/* ---------------------------------------------------------------------------------------------------------- */

#define     ADMUX                   *((volatile u8 *)0X27)      //ADMUX – ADC Multiplexer Selection Register
#define     ADMUX_MUX0              0                           //Analog Channel and Gain Selection Bit0
#define     ADMUX_MUX1              1                           //Analog Channel and Gain Selection Bit1
#define     ADMUX_MUX2              2                           //Analog Channel and Gain Selection Bit2
#define     ADMUX_MUX3              3                           //Analog Channel and Gain Selection Bit3
#define     ADMUX_MUX4              4                           //Analog Channel and Gain Selection Bit4
#define     ADMUX_ADLAR             5                           //ADC Left Adjust Result
#define     ADMUX_REFS0             6                           //Voltage Reference Selection Bit0
#define     ADMUX_REFS1             7                           //Voltage Reference Selection Bit1

/*_______________________________________________________________________________________*/

#define     ADCSRA                  *((volatile u8 *)0X26)      //ADC Control and Status Register A
#define     ADCSRA_ADPS0            0                           //ADC Prescaler Select Bit0
#define     ADCSRA_ADPS1            1                           //ADC Prescaler Select Bit1
#define     ADCSRA_ADPS2            2                           //ADC Prescaler Select Bit2
#define     ADCSRA_ADIE             3                           //ADC Interrupt Enable
#define     ADCSRA_ADIF             4                           //ADC Interrupt Flag
#define     ADCSRA_ADATE            5                           //ADC Auto Trigger Enable
#define     ADCSRA_ADSC             6                           //ADC Start Conversion
#define     ADCSRA_ADEN             7                           //ADC Enable

/*_______________________________________________________________________________________*/

#define     ADCL                    *((volatile u8 *)0x24)      //The ADC Data Register
#define     ADCH                    *((volatile u8 *)0x25)      //The ADC Data Register
#define     ADC                     *((volatile u16 *)0x24)     //The ADC Data Register

/*_______________________________________________________________________________________*/

#define     SFIOR                   *((volatile u8 *)0x50)      //Special FunctionIO Register
#define     SFIOR_ADTS0             5                           //ADC Auto Trigger Source Bit0
#define     SFIOR_ADTS1             6                           //ADC Auto Trigger Source Bit1
#define     SFIOR_ADTS2             7                           //ADC Auto Trigger Source Bit2

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */

#define     ENABLE                  1
#define     DISABLE                 0

/*_______________________________________________________________________________________*/

#define     AVCC                    0
#define     AREF                    1
#define     INT_256VOLT             2

/*_______________________________________________________________________________________*/

#define     PRESCALER_MASK          0b11111000
#define     DIV_BY_2                0b001
#define     DIV_BY_4                0b010
#define     DIV_BY_8                0b011
#define     DIV_BY_16               0b100
#define     DIV_BY_32               0b101
#define     DIV_BY_64               0b110
#define     DIV_BY_128              0b111

/*_______________________________________________________________________________________*/

#define     CHANNEL_MASK            0b11100000

/*_______________________________________________________________________________________*/

#define     AUTO_TRIGGER_MASK       0b00011111

/*_______________________________________________________________________________________*/

#define ASYNC_SINGLE_CONVERSION     0
#define FREE_RUNNING_CONVERSION     1
/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Global Declerations       		     		          	  	  	      */
/* ---------------------------------------------------------------------------------------------------------- */


/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Prototypes       		     		          	  		      */
/* ---------------------------------------------------------------------------------------------------------- */
void __vector_16 (void)     __attribute__((signal));
/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Implementations       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */


#endif