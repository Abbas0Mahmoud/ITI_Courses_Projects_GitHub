/* * * * * * * * * * * * Header Log File * * * * * * * * * * *  * * * * * /
/*_______________________________________________________________________*/
/*  Author          :   Abbas Mahmoud                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*  Project Name    :   Atmega_32 KEY PAD DRIVER                         */
/*  Controller Name :   Atmega_32                                        */
/*  File Name       :   KPD_interface.h                                  */
/*  Date            :   18 DEC, 2021                                     */
/*  Layer           :   MCAL                                             */
/*  Version         :   V1.0                                             */
/*_______________________________________________________________________*/

/*          HEADER GUARD FILE                                            */
#ifndef     KPD_INTERFACE_H
#define 	KPD_INTERFACE_H

/*                                  Functions ProtoTypes                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

void HKPD_voidInit(void);
u8 HKPD_u8GetPressedKey(void);

#endif