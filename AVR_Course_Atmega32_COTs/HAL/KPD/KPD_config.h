/* * * * * * * * * * * * Header Log File * * * * * * * * * * *  * * * * * /
/*_______________________________________________________________________*/
/*  Author          :   Abbas Mahmoud                                    */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*  Project Name    :   Atmega_32 KEY PAD DRIVER                         */
/*  Controller Name :   Atmega_32                                        */
/*  File Name       :   KPD_config.h                                     */
/*  Date            :   18 DEC, 2021                                     */
/*  Layer           :   MCAL                                             */
/*  Version         :   V1.0                                             */
/*_______________________________________________________________________*/

/*          HEADER GUARD FILE                                            */
#ifndef     KPD_CONFIG_H
#define 	KPD_CONFIG_H

/*          KEY PAD PORT CONFIGURATION                                   */
#define     KPD_PORT            PORTA

/*          ROW PINS CONFIGURATION                                       */
#define     KPD_ROW0_PIN        PIN0
#define     KPD_ROW1_PIN        PIN1
#define     KPD_ROW2_PIN        PIN2
#define     KPD_ROW3_PIN        PIN3

/*          COLUMN PINS CONFIGURATION                                    */
#define     KPD_COL0_PIN        PIN4
#define     KPD_COL1_PIN        PIN5
#define     KPD_COL2_PIN        PIN6
#define     KPD_COL3_PIN        PIN7

/*          ROWS NUMBER CONFIGURATION                                   */
#define     KPD_COL_NUM         4

/*          COLUMNS NUMBER CONFIGURATION                                */
#define     KPD_ROW_NUM         4

/*          KEY PAD BUTTONS MAPPING CONFIGURATION                       */
#define     KPD_ARR_VAL         {{'1','2','3','+'},{'4','5','6','-'},{'7','8','9','*'},{'#','0','=','/'}}

#endif