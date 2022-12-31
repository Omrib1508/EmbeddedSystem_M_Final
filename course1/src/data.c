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
 * @file	data.c 
 * @brief	This file have functions that manipulate data with operations
 * @author  Omri Ben-Shahar
 * @date    December 31, 2022
 */


/******************************************************************************
 * *
 * *	Includes
 * *
******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

#include "../include/commom/memory.h"
#include "../include/commom/data.h"
#include "../include/commom/platform.h"

/******************************************************************************
 * *
 * *	Functions
 * *
*****************************************************************************/
uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base)
{
	bool isNegative 		= false;
	uint8_t digitsCounter 	= 0;
	uint8_t remainder		= 0;

	if (data == 0)
	{
		*(ptr) = '0';
		*(ptr + 1) = '\0';
		retrurn 0;
	
	if (data < 0)
	{
		isNegative = true;
		data *= -1;	
	}

	while (data != 0)
	{
		remainder = data % base;
		*(ptr + digitsCounter) = (remainder > 9) ? ((remainder - 10) + 'a') : (remainder + '0');
		data /= base;
		digitsCounter++; 
	}
	if(isNegative = true)
	{
		*(ptr + digitsCounter) = '-';
		digitsCounter++;
	}
	*(ptr + digitsCounter + 1) = '\0';

	my_reverse(ptr, digitsCounter);
	return digitsCounter;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	bool isNegative 	= false;	
	int32_t num 		= 0;

	if (*ptr == '-')
	{
		isNegative = true;
		ptr++;
		digits--;	
	}
	
	for (int i = 0; i < (digits - 1); i++)
	{
		num = num * base + *(ptr) - '0';
		ptr++;
	}

	if(isNegative = true)
	{
		num *= -1;
	}
	return num;
}
