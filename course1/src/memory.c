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
/*
 * @file	data.c 
 * @brief	Abstraction of memory read and write operations
 * 			This implementation file provides an abstraction of reading and
 * 			writing to memory via function calls. There is also a globally
 * 			allocated buffer array used for manipulation.
 * @author	Omri Ben-Shahar
 * @date	December 31, 2022
 */


/******************************************************************************
 * *
 * *	Includes
 * *
******************************************************************************/
#include "../include/common/memory.h"
#include <stdlib.h>
#include <stdint.h>
/******************************************************************************
 * *
 * *	Functions
 * *
*****************************************************************************/
void set_value(char * ptr, unsigned int index, char value)
{
  ptr[index] = value;
}


void clear_value(char * ptr, unsigned int index)
{
  set_value(ptr, index, 0);
}


char get_value(char * ptr, unsigned int index)
{
  return ptr[index];
}


void set_all(char * ptr, char value, unsigned int size)
{
	unsigned int i;
	for(i = 0; i < size; i++)
	{
    	set_value(ptr, i, value);
  	}
}


void clear_all(char * ptr, unsigned int size)
{
  set_all(ptr, 0, size);
}


uint8_t* my_memmove(uint8_t *src, uint8_t *dst, size_t length)
{
	uint8_t source[length];
  	uint8_t *srccpy = source;

  	for (int i = 0; i < length; i++) 
	{
   		*srccpy = *src;
    	src++;
    	srccpy++;
  	}
  
	srccpy = source;

  	for (int j = 0; j < length; j++) 
	{
    	*dst = *srccpy;
    	dst++;
    	srccpy++;
  	}
 	return ((uint8_t *) dst - length);
}


uint8_t* my_memcopy(uint8_t *src, uint8_t *dst, size_t length)
{
	for (int byte = 0; byte < length; byte++)
	{
		*(dst + byte) = *(src + byte);
	}
	return (uint8_t *)dst;
}


uint8_t* my_memset(uint8_t *src, size_t length, uint8_t value)
{
	for (int byte = 0; byte < length; byte++)
	{
		*(src + byte) = value;
	}
	return (uint8_t *)src;
}


uint8_t* my_memzero(uint8_t *src, size_t length)
{
	for (int byte = 0; byte < length; byte++)
	{
		*(src + byte) = 0;
	}
	return (uint8_t *)src;
}


uint8_t* my_reverse(uint8_t *src, size_t length)
{
	uint8_t middle = length / 2;
	uint8_t temp;

	for (int byte = 0; byte < middle; byte++)
	{
		temp = *(src + byte);
		*(src + byte) = *(src + length - byte - 1);
		*(src + length - byte - 1) = temp;	
	}
	return (uint8_t *)src;
}


int32_t* reserve_words(size_t length)
{
	int32_t *mem;

	mem = (int32_t*)malloc(length * sizeof(int32_t));
	if (!mem)
	{
		return NULL;
	}
	return (int32_t *)mem;
}


void free_words(int32_t *src)
{
	free(src);
}
