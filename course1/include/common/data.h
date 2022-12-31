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
 * @file	data.h 
 * @brief	This file contain all the declaration and explanations on the 
 *         	functions
 * @author	Omri Ben-Shahar
 * @date	December 31, 2022
 */
#ifndef __DATA_H__
#define __DATA_H__

/******************************************************************************
 * *
 * *	Declaration
 * *
*****************************************************************************/
/******************************************************************************
 * *Function:		my_itoa
 * *Input:	 		data, pointer, base
 * *Output:	 		string
 * *Description:	convert data from int to ASCII string
*****************************************************************************/
uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base);

/******************************************************************************
 * *Function:		my_atoi
 * *Input:	 		pointer, digits, base
 * *Output:	 		int
 * *Description:	convert data from ASCII string to int
*****************************************************************************/
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
