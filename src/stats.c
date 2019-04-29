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
 * @file Stats.c
 *
 * @brief This file is an example .c file for the Embedded Systems
 * Specialization Course from the University of Colorado brought to you by 
 * Coursera.
 *
 * <This file will be peer reviewed>
 *
 *
 *
 *
 * @author Javier Olivares
 *
 * @date 6/3/2018
 *
 */


#include <stdlib.h>
#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

// Function declarations
void print_statistics(unsigned char median, unsigned char mean,
	       	unsigned char maximum, unsigned char minimum);

void print_array(unsigned char * stats, unsigned int length);      

unsigned char find_mean(unsigned char * stats, unsigned int length);       

unsigned char find_maximum(unsigned char * stats, unsigned int length); 

unsigned char find_minimum(unsigned char * stats, unsigned int length);

unsigned char find_median(unsigned char * stats, unsigned int length);       

unsigned char * sort_array(unsigned char * stats, unsigned int length);       

void main() {
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  /*Variable Declarations*/

 unsigned char mean;
 unsigned char maximum;
 unsigned char minimum;
 unsigned char median;
 unsigned char * sorted_array;
 
 /* Statistics and Printing Functions */
 print_array(test, SIZE);
 mean = find_mean(test, SIZE);
 maximum = find_maximum(test, SIZE);
 minimum = find_minimum(test, SIZE);
 sorted_array = sort_array(test, SIZE);

 median = find_median(sorted_array, SIZE);

 print_statistics(median, mean, maximum, minimum);
 
}

// A function that prints the statistics of an array including min, max, mean
// median.
void print_statistics(unsigned char median, unsigned char mean, unsigned char maximum, unsigned char minimum){

  printf("\n\nThe following statistics were found for the given array: \n\n");                                      
// unsigned char * sorted = sort_stats;
  printf("Mean: %d\n", mean);
  printf("Median: %d\n", median);
  printf("Meaximum: %d\n", maximum);
  printf("Minimum: %d\n", minimum);

}

// Given an array of data and a length, prints the array to the screen
void print_array(unsigned char * stats, unsigned int length){

 int i = 0;
 printf("\nThis application performs statistical analytics on a dataset.\n\n"); 
 printf("The following data array will be processed for statistical analysis:\n\n");

 for(i = 0; i < length; i++){
 	printf("%d ", stats[i]);
 }

}

// Given an array of data and a length, returns the median value
unsigned char find_median(unsigned char * stats, unsigned int length){
 unsigned char med_array = length/2;
 unsigned char median;
 
 // Returns the median of a dataset with and even # of values
 return median = (stats[med_array - 1] + stats[length - med_array])/2;  
}

// Given an array of data and a length, returns the mean 
unsigned char find_mean(unsigned char * stats, unsigned int length){
 int i;
 unsigned int mean = 0;

 for(i=0; i < length; i++){
 	mean = mean + stats[i]; // Sums data in array
 }

 mean = mean/length;		// Mean calculated by dividing sum with size of data

 return mean;
}

// Given an array of data and a length, returns the maximum
unsigned char find_maximum(unsigned char * stats, unsigned int length){
 unsigned char i;
 unsigned char maximum = stats[0];
 for(i = 0; i < length; i ++){
	 if(stats[i] > maximum){	// Checks each index of array and finds max
	  maximum = stats[i];
	 }
 }

 return maximum;
}

// Given an array of data and a legth, returns the minimum
unsigned char find_minimum(unsigned char * stats, unsigned int length){

 unsigned char i;
 unsigned char minimum = stats[0];
 for(i = 0; i < length; i ++){
	 if(stats[i] < minimum){	// Checks each index of array and finds min
	  minimum = stats[i];
	 }
 }

 return minimum;

}

// Given an array of data and a length, sorts the array from largest
// to smallest.(The zeroth Element should be the largest value, and
// the last element(n-1)  should be the smallest value.)
unsigned char * sort_array(unsigned char * stats, unsigned int length){
 unsigned char i;
 unsigned char j;
 unsigned char k;
 unsigned char sort_large = stats[0];
 static unsigned char * sort_stats;	// Declared static to pass sorted array to find median
 
 // Added stdlib.h library to use malloc function
 // length is read as a variable length; cannot have variable length array with static
 // malloc allocates block of memory on the heap which allows a dynamic array
 sort_stats = malloc(length * sizeof(unsigned char));	

 printf("\n\nSorted data array from largest to smallest (utilized to find median): \n\n");

 for(j = 0; j < length; j++){
  k = 0;
  sort_large = 0;  
	 for(i = j; i < length; i++){		// i follows j to not override previously stored 
	 					// values
		 if(stats[i] > sort_large){	// Checks each index for largest value 
	 	 	sort_large = stats[i];	// Stores index value and index to be copied 
	 		k = i;
		 }
	 }

 sort_stats[j] = sort_large;			// Copies largest value to sorted array
 stats[k] = stats[j];				// Swaps values of original index with largest index
						// to be compared later
	 printf("%d ", sort_stats[j]);

 }
 return sort_stats;
}
