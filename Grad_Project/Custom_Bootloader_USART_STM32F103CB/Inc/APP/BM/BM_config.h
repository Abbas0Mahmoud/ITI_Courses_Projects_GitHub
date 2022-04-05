/*                              Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author                 :    Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	BM Driver                             							  	      */
/*  Project Description    :	BM Driver for STM32F10x Family                             				  */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	BM_config.h                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*                              Header Guard File                                        */
/*---------------------------------------------------------------------------------------*/
#ifndef BM_CONFIG_H_
#define BM_CONFIG_H_
/*_______________________________________________________________________________________*/

#define SHARED_MEM_FLAGS_PAGE_ADDRESS                        0x08002800U
#define SHARED_MEM_FLAG_ADDRESS_VALUE                        (*(volatile u16 *)SHARED_MEM_FLAGS_PAGE_ADDRESS)

/*      Application Area Start Address      */

#define APP_START_PAGE_BASE_ADDRESS                          0x08002c00U
#define APP_FIRST_LOCATION_VALUE	                         (*(volatile u16 *)APP_START_PAGE_BASE_ADDRESS)
#define APP_RESET_HANDLER_ADDRESS                            (APP_START_PAGE_BASE_ADDRESS +(u32)0x04)



#endif /* BM_CONFIG_H_ */
