/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file	stats.h 
 * @brief 	This file contain all the declaration and explanations on the 
 *        	functions
 * @author	Omri Ben-Shahar
 * @date  	December 31, 2022
 *
 */
#ifndef __COURSE1_H__
#define __COURSE1_H__

/******************************************************************************
 * *
 * *	Includes
 * *
******************************************************************************/
#include <stdint.h>


/******************************************************************************
 * *
 * *	Defines
 * *
******************************************************************************/
#define DATA_SET_SIZE_W 	(10)
#define MEM_SET_SIZE_B  	(32)
#define MEM_SET_SIZE_W  	(8)
#define MEM_ZERO_LENGTH 	(16)

#define TEST_MEMMOVE_LENGTH (16)
#define TEST_ERROR          (1)
#define TEST_NO_ERROR       (0)
#define TESTCOUNT           (8)

/******************************************************************************
 * *
 * *	Declaration
 * *
******************************************************************************/
/******************************************************************************
 * *Function:		course1
 * *Input:	 		None
 * *Output:			None
 * *Description: 	This function is need to print all stats
******************************************************************************/
void course1(void);

/******************************************************************************
 * *Function:		course1
 * *Input:	 		None
 * *Output:			None
 * *Description: 	This function is need to print all stats
******************************************************************************/
int8_t test_data1();

/******************************************************************************
 * *Function:		course1
 * *Input:	 		None
 * *Output:			None
 * *Description: 	This function is need to print all stats
******************************************************************************/
int8_t test_data2();

/******************************************************************************
 * *Function:		course1
 * *Input:	 		None
 * *Output:			None
 * *Description: 	This function is need to print all stats
******************************************************************************/
int8_t test_memmove1();

/******************************************************************************
 * *Function:		course1
 * *Input:	 		None
 * *Output:			None
 * *Description: 	This function is need to print all stats
******************************************************************************/
int8_t test_memmove2();

/******************************************************************************
 * *Function:		course1
 * *Input:	 		None
 * *Output:			None
 * *Description: 	This function is need to print all stats
******************************************************************************/
int8_t test_memmove3();

/******************************************************************************
 * *Function:		course1
 * *Input:	 		None
 * *Output:			None
 * *Description: 	This function is need to print all stats
******************************************************************************/
int8_t test_memcopy();

/******************************************************************************
 * *Function:		course1
 * *Input:	 		None
 * *Output:			None
 * *Description: 	This function is need to print all stats
******************************************************************************/
int8_t test_memset();

/******************************************************************************
 * *Function:		course1
 * *Input:	 		None
 * *Output:			None
 * *Description: 	This function is need to print all stats
******************************************************************************/
int8_t test_reverse();

#endif /* __COURSE1_H__ */

