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
 * @file   stats.h 
 * @brief  This file contain all the declaration and explanations on the 
 *         functions
 * @author Omri Ben-Shahar
 * @date   21.11.22
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**********************************************************
 * *
 * *	Declaration
 * *
**********************************************************/
/**********************************************************
 * *Function:	 print_statistics
 * *Input:	 Array, size
 * *Output:	 None
 * *Description: This function is need to print all stats
**********************************************************/
void print_statistics(unsigned char* array, unsigned int size);

/**********************************************************
 * *Function:    print_array
 * *Input:       Array,size
 * *Output:      None
 * *Description: This function is print the array
**********************************************************/
void print_array(unsigned char* array, unsigned int size);

/**********************************************************
 * *Function:    find_median
 * *Input:       Array,size
 * *Output:      median
 * *Description: This function is return median array
**********************************************************/
unsigned char find_median(unsigned char* array, unsigned int size);

/**********************************************************
 * *Function:    find_mean
 * *Input:       Array,size
 * *Output:      mean
 * *Description: This function is return mean of array
**********************************************************/
unsigned char find_mean(unsigned char* array, unsigned int size);

/**********************************************************
 * *Function:    find_maximum
 * *Input:       Array,size
 * *Output:      maximum
 * *Description: This function is return maximum of array
**********************************************************/
unsigned char find_maximum(unsigned char* array, unsigned int size);

/**********************************************************
Function:    find_minimum
Input:       Array,size
Output:      minimum
Description: This function is return minimum of array
**********************************************************/
unsigned char find_minimum(unsigned char* array, unsigned int size);

/**********************************************************
Function:    sort_array
Input:       Array,size
Output:      None
Description: This function sory the array from max to min
**********************************************************/
void sort_array(unsigned char* array, unsigned int size);

#endif /* __STATS_H__ */
