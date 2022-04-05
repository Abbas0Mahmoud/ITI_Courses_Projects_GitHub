/* * * * * * * * * * * * Header Log File * * * * * * * * * * *  * * * * * /
/*_______________________________________________________________________*/
/*  Author          :   Abbas Mahmoud                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*  Project Name    :   Atmega_32 7 Segment Driver                       */
/*  Controller Name :   Atmega_32                                        */
/*  File Name       :   SSEG_interafce.h                                 */
/*  Date            :   18 DEC, 2021                                     */
/*  Layer           :   MCAL                                             */
/*  Version         :   V1.0                                             */
/*_______________________________________________________________________*/

/*          Header Guard File                                            */
#ifndef     SSEG_INTERFACE_H
#define 	SSEG_INTERFACE_H

/*          Numbers Definition                                           */
#define     ZERO                0
#define     ONE                 1
#define     TWO                 2
#define     THREE               3
#define     FOUR                4
#define     FIVE                5
#define     SIX                 6
#define     SEVEN               7
#define     EIGHT               8
#define     NINE                9
#define     DOT                 10

/*                                  Functions ProtoTypes                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

void HSSEG_voidInitSEG(void);
/*
    Function Name :                 HSSEG_voidInitSEG
    Function Return Type:           void
    Function Description :          Initialize 7-Segment Common Mode and PORT
    Function Parameters :           void
*/

void HSSEG_voidTurnLedsOnTest(void);
/*
    Function Name :                 HSSEG_voidTurnLedsOnTest
    Function Return Type:           void
    Function Description :          Turns all Leds of 7-Segment on
    Function Parameters :           void
*/

void HSSEG_voidTurnLedsOffTest(void);
/*
    Function Name :                 HSSEG_voidTurnLedsOffTest
    Function Return Type:           void
    Function Description :          Turns all Leds of 7-Segment off
    Function Parameters :           void
*/

void HSSEG_voidDisplayNumber(u8 Copy_u8DisplayNumber);
/*
    Function Name :                 HSSEG_voidDisplayNumber
    Function Return Type:           void
    Function Description :          Initialize 7-Segment Common Mode and PORT
    Function Parameters :

    u8 Copy_u8DisplayNumber:
    Parameter DataType :      u8 "unsigned char"
    Parameter Pass Type :     Pass by Value
    Parameter Description:    Port Name
    Parameter Values :        ZERO - ONE - TWO - THREE - FOUR - FIVE - SIX - SEVEN - EIGHT - NINE - DOT
*/

#endif
