/* * * * * * * * * * * * Header Log File * * * * * * * * * * *  * * * * * /
/*_______________________________________________________________________*/
/*  Author          :   Abbas Mahmoud                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*  Project Name    :   Atmega_32 7 Segment Driver                       */
/*  Controller Name :   Atmega_32                                        */
/*  File Name       :   SSEG_config.h                                    */
/*  Date            :   18 DEC, 2021                                     */
/*  Layer           :   MCAL                                             */
/*  Version         :   V1.0                                             */
/*_______________________________________________________________________*/

/*                      Header Guard File                                */
#ifndef     SSEG_CONFIG_H
#define 	SSEG_CONFIG_H

/*          7-Segment Common Mode Configuration (CATHODE/ANODE)          */
#define     SEGMENT_COM              CATHODE
/*          7-Segment PORT Configuration                                 */
#define     SEGMENT_PORT             PORTA

/*          Numbers Configuration Definition		                                    */
/*          CONFIG oF SEG LEDS ->      dot  - g  - f  - e  - d  - c  - b  - a 		    */
/*          CONFIG oF SEG PORT ->      D7   - D6 - D5 - D4 - D3 - D2 - D1 - D0		    */
/*          ZERO_CONFIG                                                                 */
#define     ZERO_CONFIG              0b00111111
/*          ONE_CONFIG                                                                  */
#define     ONE_CONFIG               0b00000110                                     
/*          TWO_CONFIG                                                                  */
#define     TWO_CONFIG               0b01011011                                     
/*          THREE_CONFIG                                                                */
#define     THREE_CONFIG             0b01001111                                     
/*          FOUR_CONFIG                                                                 */
#define     FOUR_CONFIG              0b01100110                                     
/*          FIVE_CONFIG                                                                 */
#define     FIVE_CONFIG              0b01101101                                     
/*          SIX_CONFIG                                                                  */
#define     SIX_CONFIG               0b01111101                                     
/*          SEVEN_CONFIG                                                                */
#define     SEVEN_CONFIG             0b00000111                                     
/*          EIGHT_CONFIG                                                                */
#define     EIGHT_CONFIG             0b01111111                                     
/*          NINE_CONFIG                                                                 */
#define     NINE_CONFIG              0b01101111

#endif
