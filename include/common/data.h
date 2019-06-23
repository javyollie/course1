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
 * @file data.h
 * @brief This file should be some very basic data manipulation.
 *
 * Integer-to-ASCII needs to convert data from a standard integer type into an
 * ASCII string.
 *
 * ASCII-to-Integer needs to convert data back from an ASCII represented string
 * into an integer type.
 *
 * @author Javier Olivares
 * @date June 2 2019
 *
 */
#ifndef __DATA_H__
#define __DATA_H__
#include "platform.h"
/**
 * @brief Integer-to-ASCII needs to convert data from a standard integer type into an
 * ASCII string.
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param data - # to be convertet is passed as a signed 32-bit integer 
 * @param ptr - copied char string passed in a ptr
 * @param base - base 2 to 16 specifies the integer value of base to convert to
 *
 * @return uint8_t - length of converted data (including negative sign and null)
 */

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
 * @brief ASCII-to-Integer needs to convert data back from an ASCII represented 
 * string into an integer type.
 *
 * @param ptr - copied char string passed in a ptr
 * @param digits - # of digits in your character set
 * @param base - base 2 to 16 specifies the integer value of base to convert to
 *
 * @return uint8_t - length of converted data (including negative sign and null)
 */

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
