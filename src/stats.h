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
 * @file stats.h 
 * @brief This header file includes declarations and documentation
 * for the functions from the stats.c file
 *
 * This header includes functions that find statistics for the given
 * array and prints the array results or the median, mean, maxiumu,
 * and minimum. The function sort_array Also sorts the array from
 * largest and smallest values.
 *
 * @author Javier Olivares
 * @date 6/2/2018
 *
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Function print_statistics prints statistics of an array
 *
 * Statistics include: minimum, maximum, mean, and median
 *
 * @param median Inputs result of median from given array
 * @param mean Inputs result of mean from given array
 * @param maximum Inputs result of maximum from given array
 * @param minimum Inputs result of minimum from given array
 * @return void type does not require a return
 */
void print_statistics(unsigned char median, unsigned char mean, 
	unsigned char maximum, unsigned char minimum);

/**
* @brief Function print_array prints data array
* 
* Given an array of data and a length the function prints the array
*
* @param stats An unsigned char pointer to an n-element data array
* @param length  An unsigned integer as the size of the array
*
* @return void Does not require a return value
*/

void print_array(unsigned char * stats, unsigned int);

/**
* @brief Function find_median finds median of given statistics
* 
* Given an array of data and a length, returns the median
*
* @param stats An unsigned char pointer to an n-element data array
* @param length  An unsigned integer as the size of the array
*
* @return unsigned char An unsigned char result returns median 
*/
unsigned char find_median(unsigned char * sorted_array, unsigned int);

/**
 * @brief Function find_mean finds mean of given statistics
 * 
 * Given an array of data and a length, returns the mean
 *
 * @param stats A unsigned char pointer to an n-element data array
 * @param length  An unsigned integer as the size of the array
 *
 * @return unsigned char An unsigned char result from the function
 */
unsigned char find_mean(unsigned char * stats, unsigned int length);       

/**
* @brief Function find_maximum finds maximum of given statistics
* 
* Given an array of data and a length, returns the maximum
*
* @param stats A unsigned char pointer to an n-element data
* @param length  An unsigned integer as the size of the array
*
* @return unsigned char An unsigned char result returns maximum value
*/
unsigned char find_maximum(unsigned char * stats, unsigned int length);     

/**
* @brief Function find_minimum finds minimum of given statistics
* 
* Given an array of data and a length, returns the minimum
*
* @param stats An unsigned char pointer to an n-element data array
* @param length  An unsigned integer as the size of the array
*
* @return unsigned char An unsigned char result returns minimum value
*/
unsigned char find_minimum(unsigned char * stats, unsigned int length);

/**
* @brief Function sort_array sorts the array from largest to smallest
* 
* Given an array of data and a length, sorts the array from largest to smallest
* (The zeroth Element should be the largest value, and the last element (n-1)
* should be the smallest value.
*
* @param stats An unsigned char pointer to an n-element data array
* @param length  An unsigned integer as the size of the array
*
* @return unsigned char An unsigned char result returns sorted array
*/
unsigned char * sort_array(unsigned char * stats, unsigned int length);

#endif /* __STATS_H__ */
