/* * * * * * * * * * * * Header Log File * * * * * * * * * * *  * * * * * /
/*_______________________________________________________________________*/
/*  Author          :   Abbas Mahmoud                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*  Project Name    :   Atmega_32 7 Segment Driver                       */
/*  Controller Name :   Atmega_32                                        */
/*  File Name       :   SSEG_program.c                                   */
/*  Date            :   18 DEC, 2021                                     */
/*  Layer           :   MCAL                                             */
/*  Version         :   V1.0                                             */
/*_______________________________________________________________________*/

/*		Library Inclusion			                                     */
#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATH.h"

/*		Lower Layer Inclusions		                                     */
#include "../../MCAL/DIO/DIO_interface.h"

/*		Self Layer Inclusions		                                     */

/*		Self Files Inclusions		                                     */
#include "SSEG_config.h"
#include "SSEG_interface.h"
#include "SSEG_private.h"

/*                                  Functions Implementations                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

void HSSEG_voidInitSEG(void)
{
    switch(SEGMENT_COM)
    {
        case CATHODE:
            MDIO_voidSetPortDirection(SEGMENT_PORT,OUTPUT);
            MDIO_voidSetPortValue(SEGMENT_PORT,LOW);
        break;
        case ANODE:
            MDIO_voidSetPortDirection(SEGMENT_PORT,OUTPUT);
            MDIO_voidSetPortValue(SEGMENT_PORT,HIGH);
        break;
        /*      Error       */
    }
}

void HSSEG_voidTurnLedsOnTest(void)
{
    switch(SEGMENT_COM)
    {
        case CATHODE:
            MDIO_voidSetPortValue(SEGMENT_PORT,HIGH);
        break;
        case ANODE:
            MDIO_voidSetPortValue(SEGMENT_PORT,LOW);
        break;
    }
}

void HSSEG_voidTurnLedsOffTest(void)
{
    switch(SEGMENT_COM)
    {
        case CATHODE:
            MDIO_voidSetPortValue(SEGMENT_PORT,LOW);
        break;
        case ANODE:
            MDIO_voidSetPortValue(SEGMENT_PORT,HIGH);
        break;
    }
}

void HSSEG_voidDisplayNumber(u8 Copy_u8DisplayNumber)
{
    switch(SEGMENT_COM)
    {
        case CATHODE:
            switch(Copy_u8DisplayNumber)
            {
                case ZERO:
				MDIO_voidSetPortSpecificValue(SEGMENT_PORT,ZERO_CONFIG);
				break;
                case ONE:
                    MDIO_voidSetPortSpecificValue(SEGMENT_PORT,ONE_CONFIG);
                break;
                case TWO:
                    MDIO_voidSetPortSpecificValue(SEGMENT_PORT,TWO_CONFIG);
                break;
                case THREE:
                    MDIO_voidSetPortSpecificValue(SEGMENT_PORT,THREE_CONFIG);
                break;
                case FOUR:
                    MDIO_voidSetPortSpecificValue(SEGMENT_PORT,FOUR_CONFIG);
                break;
                case FIVE:
                    MDIO_voidSetPortSpecificValue(SEGMENT_PORT,FIVE_CONFIG);
                break;
                case SIX:
                    MDIO_voidSetPortSpecificValue(SEGMENT_PORT,SIX);
                break;
                case SEVEN:
                    MDIO_voidSetPortSpecificValue(SEGMENT_PORT,SEVEN_CONFIG);
                break;
                case EIGHT:
                    MDIO_voidSetPortSpecificValue(SEGMENT_PORT,EIGHT_CONFIG);
                break;
                case NINE:
                    MDIO_voidSetPortSpecificValue(SEGMENT_PORT,NINE_CONFIG);
                break;
                /*      ERROR       */
            }
        break;
        case ANODE:
        switch(Copy_u8DisplayNumber)
            {
                case ZERO:
				MDIO_voidSetPortSpecificValue(SEGMENT_PORT,(~ZERO_CONFIG));
				break;
                case ONE:
                    MDIO_voidSetPortSpecificValue(SEGMENT_PORT,(~ONE_CONFIG));
                break;
                case TWO:
                    MDIO_voidSetPortSpecificValue(SEGMENT_PORT,(~TWO_CONFIG));
                break;
                case THREE:
                    MDIO_voidSetPortSpecificValue(SEGMENT_PORT,(~THREE_CONFIG));
                break;
                case FOUR:
                    MDIO_voidSetPortSpecificValue(SEGMENT_PORT,(~FOUR_CONFIG));
                break;
                case FIVE:
                    MDIO_voidSetPortSpecificValue(SEGMENT_PORT,(~FIVE_CONFIG));
                break;
                case SIX:
                    MDIO_voidSetPortSpecificValue(SEGMENT_PORT,(~SIX));
                break;
                case SEVEN:
                    MDIO_voidSetPortSpecificValue(SEGMENT_PORT,(~SEVEN_CONFIG));
                break;
                case EIGHT:
                    MDIO_voidSetPortSpecificValue(SEGMENT_PORT,(~EIGHT_CONFIG));
                break;
                case NINE:
                    MDIO_voidSetPortSpecificValue(SEGMENT_PORT,(~NINE_CONFIG));
                break;
                /*      ERROR       */
            }
    }
}
