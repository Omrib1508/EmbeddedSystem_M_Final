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
 * @file	memory.h 
 * @brief	Abstraction of memory read and write operations. This header file  
 *			provides an abstraction of reading and writing to memory via
 *			function calls.
 * @author	Omri Ben-Shahar
 * @date	December 31, 2022
 *
 */

#ifndef __MEMORY_H__
#define __MEMORY_H__
/******************************************************************************
 * *
 * *	Includes
 * *
******************************************************************************/
#include <stdlib.h>
#include <stdint.h>

/******************************************************************************
 * *
 * *	Declaration
 * *
******************************************************************************/
/******************************************************************************
 * *Function:		set_value
 * *Input:	 		array_ptr, index, value
 * *Output:			None
 * *Description: 	Sets a value of a data array
******************************************************************************/
void set_value(char* ptr, unsigned int index, char value);

/******************************************************************************
 * *Function:		set_value
 * *Input:	 		array_ptr, index
 * *Output:			None
 * *Description: 	Clear a value of a data array 
******************************************************************************/
void clear_value(char* ptr, unsigned int index);

/******************************************************************************
 * *Function:		get_value
 * *Input:	 		array_ptr, index
 * *Output:			value
 * *Description: 	Returns a value of a data array 
******************************************************************************/
char get_value(char* ptr, unsigned int index);

/******************************************************************************
 * *Function:		set_all
 * *Input:	 		array_ptr, value, array_size
 * *Output:			None
 * *Description: 	Sets data array elements to a value 
******************************************************************************/
void set_all(char* ptr, char value, unsigned int size);

/******************************************************************************
 * *Function:		clear_all
 * *Input:	 		array_ptr, array_size
 * *Output:			None
 * *Description: 	Clears elements in a data array 
******************************************************************************/
void clear_all(char* ptr, unsigned int size);

/******************************************************************************
 * *Function:		my_memmove
 * *Input:	 		src_ptr, dst_ptr, length
 * *Output:			dst_ptr
 * *Description: 	Move from the source location to the destination 
******************************************************************************/
uint8_t* my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/******************************************************************************
 * *Function:		my_memcopy
 * *Input:	 		src_ptr, dst_ptr, length
 * *Output:			dst_ptr
 * *Description: 	Copy from the source location to the destination 
******************************************************************************/
uint8_t* my_memcopy(uint8_t *src, uint8_t *dst, size_t length);

/******************************************************************************
 * *Function:		my_memset
 * *Input:	 		src_ptr, length, value
 * *Output:			src_ptr
 * *Description: 	Set all locations of that memory to a given value
******************************************************************************/
uint8_t* my_memset(uint8_t *src, size_t length, uint8_t value);

/******************************************************************************
 * *Function:		my_memzero
 * *Input:	 		src_ptr, length, value
 * *Output:			src_ptr
 * *Description: 	Zero out all of the memory 
******************************************************************************/
uint8_t* my_memzero(uint8_t *src, size_t length);

/******************************************************************************
 * *Function:		my_reverse
 * *Input:	 		src_ptr, length, value
 * *Output:			src_ptr
 * *Description: 	Reverse the order of all of the bytes 
******************************************************************************/
uint8_t* my_reverse(uint8_t *src, size_t length);

/******************************************************************************
 * *Function:		reserve_words
 * *Input:	 		length
 * *Output:			mem_ptr
 * *Description: 	Take number of words to allocate in dynamic memory
******************************************************************************/
int32_t* reserve_words(size_t length);

/******************************************************************************
 * *Function:		free_words
 * *Input:	 		src_ptr
 * *Output:			None
 * *Description: 	free a dynamic memory allocation
******************************************************************************/
void free_words(int32_t *src);

#endif /* __MEMORY_H__ */
