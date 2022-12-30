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
 * @file    stats.c 
 * @brief   This file have functions that can analyze an array of data items 
 *          and report analytics
 * @author  Omri Ben-Shahar
 * @date    21.11.22
 *
 */


/**********************************************************
 * *
 * *	Includes
 * *
**********************************************************/
#include <stdio.h>
#include "stats.h"

/**********************************************************
 * *
 * *	Defines
 * *
**********************************************************/
/* Size of the Data Set */
#define SIZE (40)

/**********************************************************
 * *
 * *	Functions
 * *
**********************************************************/
void main() 
{
 	 unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              	     114, 88,   45,  76, 123,  87,  25,  23,
                              	     200, 122, 150, 90,   92,  87, 177, 244,
                             	     201,   6,  12,  60,   8,   2,   5,  67,
                                       7,  87, 250, 230,  99,   3, 100,  90};

	sort_array(test, SIZE);	
	print_array(test, SIZE);
	print_statistics(test, SIZE);

}


void print_statistics(unsigned char* array, unsigned int size)
{
	printf("This is the minimum of the array: %u\n", find_minimum(array, size));
	printf("This is the maximum of the array: %u\n", find_maximum(array, size));
	printf("This is the mean of the array: %u\n", find_mean(array, size));
	printf("This is the median of the array: %u\n", find_median(array, size));
}


void print_array(unsigned char* array, unsigned int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%u ", array[i]);
	}
	printf("\n");
}


unsigned char find_median(unsigned char* array, unsigned int size)
{
	sort_array(array, size);
	if (size % 2 != 0)
	{
		return array[size/2];
	}
	return (array[(size-1)/2]+array[size/2])/2;
}


unsigned char find_mean(unsigned char* array, unsigned int size)
{
	unsigned int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += (unsigned int)array[i];
	}
	return (unsigned char) (sum /size);
}


unsigned char find_maximum(unsigned char* array, unsigned int size)
{
	unsigned char max = array[0];
	for (unsigned int i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
}


unsigned char find_minimum(unsigned char* array, unsigned int size)
{
	unsigned char min = array[0];
        
	for (unsigned int i = 1; i < size; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
 	}
        return min;
}


void sort_array(unsigned char* array, unsigned int size)
{
	unsigned char temp;

	for (unsigned int i = 0; i < (size - 1); i++)
	{
		for (unsigned int j = i + 1; j < size; j++)
		{
			if (array[i] < array[j])
			{
				temp =  array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}
