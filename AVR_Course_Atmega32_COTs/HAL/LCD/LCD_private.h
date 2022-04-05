//* * * * * * * * * * * * Header Log File * * * * * * * * * * *  * * * * */
/*_______________________________________________________________________*/
/*  Author          :   Abbas Mahmoud                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*  Project Name    :   Atmega_32 LCD Driver                             */
/*  Controller Name :   Atmega_32                                        */
/*  File Name       :   LCD_private.h                                    */
/*  Date            :   18 DEC, 2021                                     */
/*  Layer           :   MCAL                                             */
/*  Version         :   V1.0                                             */
/*_______________________________________________________________________*/

/*          HEADER GUARD FILE                                            */
#ifndef     LCD_PRIVATE_H
#define 	LCD_PRIVATE_H

/*          FUNCTION SET INSTRUCTION                                     */
#define     FUNCTION_SET_INSTRUCTION                                      (0x30)|(LCD_LINE_DISPLAY<<3)|(LCD_FONT_CHARACTER<<2)   

/*          DISPLAY ON/OFF CONTROL INSTRUCTION                           */
#define     DISPLAY_ON_OFF_CONTROL_INSTRUCTION                            (0X08)|(DISPLAY_ON_OFF<<2)|(CURSOR_ON_OFF<<1)|(CURSOR_BLINK_ON_OFF) 

/*          CLEAR DISPLAY INSTRUCTION                                    */
#define     CLEAR_DISPLAY_INSTRUCTION                                     0X01

/*          SET DDRAM ADDRESS INSTRUCTION                                */
#define     SET_DDRAM_ADDRESS_INSTRUCTION(POSITION_ADDRESS)               POSITION_ADDRESS |= (1 << 7)

#define     DDRAM_POSITION_FIXED_ADDRESS                                  0x40

/*          HLCD_voidSendNumber Parameters                               */
#define     ZERO_ASCII_VALUE                                              0X30

/*                          Private Functions ProtoTypes                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */
static void HLCD_voidSendCommand(u8 Copy_u8Command);

#endif