 /* Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file course1.c
 * @brief Test document
 *
 * This file contains the course1 test functions.
 *
 * @author Javier Olivares
 * @date June 4 2019
 *
 */

#include "course1.h"

// This function calls a handful of functions and test you function outputs
int8_t course1(){

    int8_t dummy = 0; 
    int8_t testMemmove1 = 0;
    dummy  = test_memcopy();
    testMemmove1 = test_memmove2();

  return dummy + testMemmove1;
}

// This function will test to atoi and itoa conversions for the user
int8_t test_data1(){
  return 0;
}

// This function will test to atoi and itoa conversions for the user
int8_t test_data2(){

  return 0;
}

// This function will test non-overlapped memmove
int8_t test_memmove1(){
  return 0;
    #define SIZE (5) 
    uint8_t memsrc[SIZE] = {2, 5, 1, 9, 100};
    uint8_t memdst[SIZE];
    uint8_t *ptrdst = NULL;

    ptrdst = my_memcopy( memsrc, memdst, SIZE);
    
    if(ptrdst == NULL)
    {
    	return 0;
    }
    else
	return 1;

}

// This function will test overlapped memmove where there is overlap of the end
// of destination  and start of the source regions
int8_t test_memmove2(){
 
    uint8_t memsrc[16] = "OVERLAPFUN";
    uint8_t *ptrdst = NULL;
    PRINTF("%s\n", memsrc);
    ptrdst = my_memmove( memsrc, memsrc+5, 16);
    
    PRINTF("\nOUT: %s\n", ptrdst);
    if(ptrdst == NULL)
    {
    	return 0;
    }
    else
	return 1;
}

// This function will test overlapped memmove where there is overlap of the 
// start of destination and end of the source regions
int8_t test_memmove3(){

    #define SIZE (5) 
    uint8_t memsrc[SIZE] = {2, 5, 1, 9, 100};
    uint8_t memdst[SIZE];
    uint8_t *ptrdst = NULL;

    ptrdst = my_memcopy( memsrc, memdst, SIZE);
    
    if(ptrdst == NULL)
    {
    	return 0;
    }
    else
	return 1;
}

// This function will test memcopy
int8_t test_memcopy(){
    #define SIZE (5) 
    uint8_t memsrc[SIZE] = {2, 5, 1, 9, 100};
    uint8_t memdst[SIZE];
    uint8_t *ptrdst = NULL;

    ptrdst = my_memcopy( memsrc, memdst, SIZE);
    
    if(ptrdst == NULL)
    {
    	return 0;
    }
    else
	return 1;
}

// This function will test memset and memzero
int8_t test_memeset(){

  return 0;
}

// This function will test reverse
int8_t test_reverse(){

  return 0;
}
