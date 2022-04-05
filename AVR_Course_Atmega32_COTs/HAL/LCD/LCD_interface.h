/* * * * * * * * * * * * Header Log File * * * * * * * * * * *  * * * * * /
/*_______________________________________________________________________*/
/*  Author          :   Abbas Mahmoud                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*  Project Name    :   Atmega_32 LCD Driver                             */
/*  Controller Name :   Atmega_32                                        */
/*  File Name       :   LCD_interface.h                                  */
/*  Date            :   18 DEC, 2021                                     */
/*  Layer           :   MCAL                                             */
/*  Version         :   V1.0                                             */
/*_______________________________________________________________________*/

/*          HEADER GUARD FILE                                            */
#ifndef     LCD_INTERFACE_H
#define 	LCD_INTERFACE_H


/*                                  Functions ProtoTypes                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

void HLCD_voidInit(void);

void HLCD_voidClearDisplay(void);

void HLCD_voidSendData(u8 Copy_u8Data);

void HLCD_voidGoToXY(u8 Copy_u8XPosition,u8 Copy_u8YPosition);

void HLCD_voidSendCustomPattern(u8 * Copy_Pu8PatternArray,
                                u8 Copy_u8PatternNumber,
                                u8 Copy_u8XPosition,
                                u8 Copy_u8YPosition);

void HLCD_voidSendString(u8 * Copy_Pu8StringArray);

void HLCD_voidSendNumber(u32 Copy_u32SendNumber);

#endif
