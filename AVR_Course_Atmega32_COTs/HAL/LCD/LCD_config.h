/* * * * * * * * * * * * Header Log File * * * * * * * * * * *  * * * * * /
/*_______________________________________________________________________*/
/*  Author          :   Abbas Mahmoud                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*  Project Name    :   Atmega_32 LCD Driver                             */
/*  Controller Name :   Atmega_32                                        */
/*  File Name       :   LCD_config.h                                     */
/*  Date            :   18 DEC, 2021                                     */
/*  Layer           :   MCAL                                             */
/*  Version         :   V1.0                                             */
/*_______________________________________________________________________*/

/*          HEADER GUARD FILE                                            */
#ifndef     LCD_CONFIG_H
#define 	LCD_CONFIG_H

/*          LCD DATA PINS PORT                                           */
#define     LCD_DATA_PORT       PORTA

/*          LCD CONTROL PINS PORT                                        */
#define     LCD_CTRL_PORT       PORTB

/*          LCD CONTROL PINS                                             */
#define     LCD_EN_PIN          PIN0
#define     LCD_RW_PIN          PIN1
#define     LCD_RS_PIN          PIN2

/*          FUNCTION SET CONFIGURATION                                   */
/*          LINE DISPLAY CONFIGURATION                                   */
/*          0 : SINGLE LINE DISPLAY                                      */
/*          1 : DOUBLE LINE DISPLAY (DEFAULT)                            */
#define     LCD_LINE_DISPLAY    1

/*          CHARACTER FONT CONFIGURATION                                 */
/*          0 : 5 X 7 DOT CHARACTER FONT (DEFAULT)                       */
/*          1 : 5 X 11 DOT CHARACTER FONT                                */
#define     LCD_FONT_CHARACTER  0

/*          DISPLAY ON/OFF CONTROL CONFIGURATION                         */
/*          DISPLAY ON/OFF CONFIGURATION                                 */
/*          0 : DISPLAY OFF                                              */
/*          1 : DISPLAY ON (DEFAULT)                                     */
#define     DISPLAY_ON_OFF      1

/*          CURSOR ON/OFF CONFIGURATION                                  */
/*          0 : CURSOR OFF                                               */
/*          1 : CURSOR ON (DEFAULT)                                      */
#define     CURSOR_ON_OFF       1

/*          CURSOR BLINK ON/OFF CONFIGURATION                            */
/*          0 : CURSOR BLINK OFF                                         */
/*          1 : CURSOR BLINK ON (DEFAULT)                                */
#define     CURSOR_BLINK_ON_OFF 1

#endif