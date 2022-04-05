/* * * * * * * * * * * * Header Log File * * * * * * * * * * *  * * * * * /
/*_______________________________________________________________________*/
/*  Author          :   Abbas Mahmoud                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*  Project Name    :   Atmega_32 KEY PAD DRIVER                         */
/*  Controller Name :   Atmega_32                                        */
/*  File Name       :   KPD_program.c                                    */
/*  Date            :   18 DEC, 2021                                     */
/*  Layer           :   MCAL                                             */
/*  Version         :   V1.0                                             */
/*_______________________________________________________________________*/

/*		Library Inclusion											     */
#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATH.h"

/*		Lower Layer Inclusions											 */
#include "../../MCAL/DIO/DIO_interface.h"

/*		Self Layer Inclusions											 */

/*		Self Files Inclusoins										     */
#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"

/*                                  Functions Implementations                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

void HKPD_voidInit(void)
{
    /* Configure THe Direction of COL Pins as INPUT  */
    MDIO_voidSetPinDirection(KPD_PORT,KPD_ROW0_PIN,INPUT_PULLUP);
    MDIO_voidSetPinDirection(KPD_PORT,KPD_ROW1_PIN,INPUT_PULLUP);
    MDIO_voidSetPinDirection(KPD_PORT,KPD_ROW2_PIN,INPUT_PULLUP);
    MDIO_voidSetPinDirection(KPD_PORT,KPD_ROW3_PIN,INPUT_PULLUP);
    
    /* Configure THe Direction of ROW Pins as OUTPUT */
    MDIO_voidSetPinDirection(KPD_PORT,KPD_COL0_PIN,OUTPUT);
    MDIO_voidSetPinDirection(KPD_PORT,KPD_COL1_PIN,OUTPUT);
    MDIO_voidSetPinDirection(KPD_PORT,KPD_COL2_PIN,OUTPUT);
    MDIO_voidSetPinDirection(KPD_PORT,KPD_COL3_PIN,OUTPUT);

    /* Deactivate Column Pins */
    MDIO_voidSetPinValue(KPD_PORT,KPD_COL0_PIN,HIGH);
    MDIO_voidSetPinValue(KPD_PORT,KPD_COL1_PIN,HIGH);
    MDIO_voidSetPinValue(KPD_PORT,KPD_COL2_PIN,HIGH);
    MDIO_voidSetPinValue(KPD_PORT,KPD_COL3_PIN,HIGH);
}

u8 HKPD_u8GetPressedKey(void)
{
    // contains the corresponding value of each element "button" in keypad
    u8 Local_KPDArray[KPD_ROW_NUM][KPD_COL_NUM] = KPD_ARR_VAL;
    // used to toggle column buttons state
    u8 Local_u8KPDColsArray[KPD_COL_NUM] = {KPD_COL0_PIN,KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN};
    // used to toggle row buttons state
    u8 Local_u8KPDRowsArray[KPD_ROW_NUM] = {KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
    // columns loopcounter 
    u8 Local_u8KPDColIndex = 0;
    // rows loopcounter
    u8 Local_u8KPDRowindex = 0;
    // used to check for continuos press
    u8 Local_u8PinState;
    // used to store pressed key value and return it
    u8 Local_u8PressedKey = 0xFF;
    // columns check loop
    for(Local_u8KPDColIndex = 0; Local_u8KPDColIndex < KPD_COL_NUM ; Local_u8KPDColIndex++)
    {
        // activate corresponding column button pin
        MDIO_voidSetPinValue(KPD_PORT,Local_u8KPDColsArray[Local_u8KPDColIndex],LOW);
        // rows check loop
        for(Local_u8KPDRowindex = 0; Local_u8KPDRowindex < KPD_ROW_NUM ; Local_u8KPDRowindex++)
        {
            // getting the corresponding row button and store its value
            Local_u8PinState = MDIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowsArray[Local_u8KPDRowindex]);
            // checking the button state if it's pressed or not
            if(Local_u8PinState == 0)
            {
                // if the button is pressed the value will be stored and returned
                Local_u8PressedKey = Local_KPDArray[Local_u8KPDRowindex][Local_u8KPDColIndex];
                // as long as the button is pressed don't scan the buttons and return the corresponding value to button
                while(Local_u8PinState == 0)
                {
                    Local_u8PinState = MDIO_u8GetPinValue(KPD_PORT, Local_u8KPDRowsArray[Local_u8KPDRowindex]);
                }
                // return the pressed key value
                return Local_u8PressedKey;
            }
        }
        // deactivate corresponding column button pin
        MDIO_voidSetPinValue(KPD_PORT,Local_u8KPDColsArray[Local_u8KPDColIndex],HIGH);
    }
    // return default value if no switch is pressed
    return Local_u8PressedKey;
}