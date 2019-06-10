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
 * @file course1.h
 * @brief This file contains a handful of functions to test your code for the final
 * assessment to the Embedded Specialization Course.
 *
 * @author Javier Olivares
 * @date June 2 2019
 *
 */
#ifndef __COURSE1_H__
#define __COURSE1_H__

/**
 * @brief Test your function outputs
 *
 * For this function you will need to call a handful of functions and test your
 * function outputs. You only need to call each of the following functions
 * once. These include test_data1(), test_data2(), test_memmove1(),
 * test_memmove2(), test_memmove3(), test_memcopy(), test_memset(),and test_reverse().
 *
 * @return int8_t
 */
__int8_t course1();

/**
 * @brief Test atoi and itoa conversions
 *
 * @return int8_t
 */
__int8_t test_data1();

/**
 * @brief Test itoi and atoi conversions
 *
 * @return int8_t
 */
__int8_t test_data2();

/**
 * @brief Test non-overlapped memmove
 *
 * @return int8_t
 */
__int8_t test_memmove1();

/**
 * @brief Test overlapped memmove end of destination and start of source
 *
 * Tests overlapped memmove where there is overlap of the end of destination and
 * start of the source regions
 *
 * @return int8_t
 */
__int8_t test_memmove2();

/**
 * @brief Test overlapped memmove start of destination and end of source
 *
 * Tests overlapped memmove where there is overlap of the start of destination and
 * end of the source regions
 *
 * @return int8_t
 */
__int8_t test_memmove3();

/**
 * @brief Test memcopy
 *
 * @return int8_t
 */
__int8_t test_memcopy();

/**
 * @brief Test memset and memzero
 *
 * @return int8_t
 */
__int8_t test_memset();

/**
 * @brief Test reverse
 *
 * @return int8_t
 */
__int8_t test_reverse();

#endif /* __COURSE1_H__ */

















