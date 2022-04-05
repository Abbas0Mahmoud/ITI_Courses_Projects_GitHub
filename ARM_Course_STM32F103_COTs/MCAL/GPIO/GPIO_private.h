/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Documentation        		     		          	  	  			  */
/* ---------------------------------------------------------------------------------------------------------- */
/*                      		Header Log File                                  							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Author          		:   Abbas Mahmoud                                    							  */
/* ---------------------------------------------------------------------------------------------------------- */
/*  Project Name           :	GPIO Driver                             							  	      */
/*  Project Description    :	GPIO Driver for STM32F10x Family                             				  */
/*  Target Controller 	   :	STM32F10x Family                                        					  */
/*  File Name              :	GPIO_private.h                                    							  */
/*  Layer           	   :	MCAL                                             							  */
/*  Date                   :  	20 JAN, 2021                                      							  */
/*  Version         	   :  	V1.0                                             							  */
/* ---------------------------------------------------------------------------------------------------------- */

/*          Header Guard File                                            */
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Preprocrsseor Directives        		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Registers Definitions       		     		          	  	              */
/* ---------------------------------------------------------------------------------------------------------- */

/*                           		      GPIO Registers Definitions       		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* Define PortA,B,C GPIO Register Base Addresses and Cast Them using struct Datatype */
/* GPIO Registers Addresses are stored in RAM Sequently so GPIO PortA is struct and GPIO PortA Registers are struct members */
/* GPIO Registers are pre-stored struct in RAM so we need something to access the struct */
/* creating struct datatype with members GPIO Registers each member size equals register size */
/* define GPIOA,GPIOB,GPIOC which are pointers */
/* casting base addresses of each GPIO Port Registers with created strcut datatype to initialize */
/* each pointer to struct to point at corresponding GPIO Port Register struct */
#define GPIOA ((volatile GPIOx_t *)0x40010800)
#define GPIOB ((volatile GPIOx_t *)0x40010C00)
#define GPIOC ((volatile GPIOx_t *)0x40011000)

/* struct Data Type that contains GPIO Port Registers to Access Them Sequently */
/* Port A GPIO Port Boundary Addresses are : 0x4001 0800 - 0x4001 0BFF */
/* Port B GPIO Port Boundary Addresses are : 0x4001 0C00 - 0x4001 0FFF */
/* Port C GPIO Port Boundary Addresses are : 0x4001 1000 - 0x4001 13FF */
typedef struct
{
	/*
		Port Configuration Register Low (Read/Write Memory)
		Port Pins Mode/Config Register for Pins Pin0->Pin7
		Each Pins Has 4 Bits, Lower Bits for Mode (Input/Output) - Higher Bits for Config within Selected Mode
	*/
	volatile u32 CRL;
	/*
		Port Configuration Register High (Read/Write Memory)
		Port Pins Mode/Config Register for Pins Pin0->Pin7
		Each Pins Has 4 Bits, Lower Bits for Mode (Input/Output) - Higher Bits for Config within Selected Mode
	*/
	volatile u32 CRH;
	/*
		Port Input Data Register (Read Only Memory)
		The Lower 16 Bits are dedicated for Each Port Pin to Store Pin Status (High,Low)
		The Higher 16 Bits are Reserved
		This Register is Accessed in WordMode only (Word Size = Register Width or Address Bus Width)
	*/
	volatile u32 IDR;
	/*
		Port Output Data Register (Read/Write Memory)
		The Lower 16 Bits are Dedicated for Each Port Pin to Set Pin Status (High,Low)
		The Higher 16 Bits are Reserved
		This Register is Accessed in WordMode only (Word Size = Register Width or Address Bus Width)
	*/
	volatile u32 ODR;
	/*
		Port Bit Set/Reset Register
		This Regiter Gives Alternative Solution to ODR Register as It Allows Pin Bit Access unlike ODR WordMode Only
		The Lower 16 Bits are Used to Set Port Pins (High) by Writing 1 to Desired Port Pin
		The Higher 16 Bits are Used to Reset Port Pins (Low) by Writing 1 to Desired Port Pin
	*/
	volatile u32 BSRR;
	/*
		Port Bit Reset Register
		This register is a Replacement for The Higher Bits of BSRR
		The Lower 16 Bits are Used to Set Port Pins (Low) by Writing 1 to Desired Port Pin
		The Higher Bits are Reserved
	*/
	volatile u32 BRR;
	/*
		Port Configuration Lock Register
		This Register is used to Lock Port Pin Mode/Config Bits so They won't Change after Setting Them
		The Lower 16 Bits are used to Lock Desired Port Pin Config by writing 1 to This Bit
		Bit 16 is used to Enable Writing to Port Pin Lock Bit Then Load The Lower Bits With Desired Value for Each Pin
		Then by Following Sequence to Enable and Lock Register after Writing to It
	*/
	volatile u32 LCKR;
} GPIOx_t;

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Definitions       		     		          	  	  			      */
/* ---------------------------------------------------------------------------------------------------------- */

/*                           		      GPIO Registers Definitions       		     		          	  	  */
/* ---------------------------------------------------------------------------------------------------------- */

/* GPIO Direction Reset Value to Mask Mode and Config Bits for Each Pin */
/* Equivalent Value to 15 is 1111 as Each Pin has 4 bits , 2 bits for mode and 2 bits for config */
#define GPIO_DIRECTION_RESET_MASK 15

/*
typedef u8 ErrorStatus;
#define OK_STATUS 			0
#define NOT_OK_STATUS 		1
#define OUT_OF_RANGE_STATUS 2
*/

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Global Declerations       		     		          	  	  	      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Prototypes       		     		          	  		      */
/* ---------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------------- */
/*                           	Private Function Implementations       		     		          	  		  */
/* ---------------------------------------------------------------------------------------------------------- */

#endif /* GPIO_PRIVATE_H_ */