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
 * @file	course1.h 
 * @brief 	This file is to be used to course 1 final assessment.
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
 * *Description: 	calls some various simple tests
******************************************************************************/
void course1(void);

/******************************************************************************
 * *Function:		test_data1
 * *Input:	 		None
 * *Output:			error
 * *Description: 	function calls the my_itoa and my_atoi functions in Hex
******************************************************************************/
int8_t test_data1();

/******************************************************************************
 * *Function:		test_data2
 * *Input:	 		None
 * *Output:			error
 * *Description: 	function calls the my_itoa and my_atoi functions in Dec
******************************************************************************/
int8_t test_data2();

/******************************************************************************
 * *Function:		test_memmove1
 * *Input:	 		None
 * *Output:			error
 * *Description: 	This function calls the memmove routine with two sets of 
 * *				data that do not over lap in anyway. This function should 	
 * *				print that a move worked correctly for a move from source
 * *				to destination.
******************************************************************************/
int8_t test_memmove1();

/******************************************************************************
 * *Function:		test_memmove2
 * *Input:	 		None
 * *Output:			error
 * *Description: 	This function calls the memmove routine with two sets of 
 * *				data that not over lap. Overlap exists at the start of the 
 * *				destination and the end of the source pointers. This 
 * *				function should print that a move worked correctly for a 
 * *				move from source to destination regardless of overlap.
******************************************************************************/
int8_t test_memmove2();

/******************************************************************************
 * *Function:		test_memmove3
 * *Input:	 		None
 * *Output:			error
 * *Description: 	This function calls the memmove routine with two sets of 
 * *				data that not over lap. Overlap exists at the start of the 
 * *				source and the end of the destination pointers. This 
 * *				function should print that a move worked correctly for a 
 * *				move from source to destination regardless of overlap.
******************************************************************************/
int8_t test_memmove3();

/******************************************************************************
 * *Function:		test_memcopy
 * *Input:	 		None
 * *Output:			error
 * *Description: 	Calls the my_memcopy functions to validate a copy works
 * *				correctly
******************************************************************************/
int8_t test_memcopy();

/******************************************************************************
 * *Function:		test_memset
 * *Input:	 		None
 * *Output:			error
 * *Description: 	Calls the memset and memzero functions. This shoudl zero out
 * *				the bytes from [] to []. This should set the bytes [] to []
 * *				with 0xFF
******************************************************************************/
int8_t test_memset();

/******************************************************************************
 * *Function:		test_reverse
 * *Input:	 		None
 * *Output:			error
 * *Description: 	Calls the my_reverse function to see if a give set of ASCII
 * *				characters will properly reverse
******************************************************************************/
int8_t test_reverse();

#endif /* __COURSE1_H__ */

