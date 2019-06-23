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
    int8_t testMemmove2 = 0;
    int8_t testMemmove3 = 0;
    int8_t testMemset = 0;
    int8_t testReverse = 0;
    int8_t testData1 = 0;
    int8_t testData2 = 0;

    dummy  = test_memcopy();
    testMemmove1 = test_memmove1();
    testMemmove2 = test_memmove2();
    testMemmove3 = test_memmove3();
    testMemset = test_memset();
    testReverse = test_reverse();
    testData1 = test_data1();
    testData2 = test_data2();

  return dummy + testMemmove1 + testMemmove2 + testMemmove3 + testMemset + testReverse + testData1 + testData2;
}

// This function will test to atoi and itoa conversions for the user
int8_t test_data1(){
    int32_t data = 5602;
    uint8_t *ptr = NULL;
    uint8_t length = 0;
    uint32_t base = 5;

    PRINTF("Test data1 my_itoa: \n");
    length = my_itoa( data, ptr, base);
    
    PRINTF("\nSize of string: %d\n", length);
    if(length == 0)
    {
    	return 0;
    }
    else
        return 1;
}

// This function will test to atoi and itoa conversions for the user
int8_t test_data2(){

  return 0;
}

// This function will test non-overlapped memmove
int8_t test_memmove1(){
    
    uint8_t memsrc[16] = "OVERLAPFUN";
    uint8_t *ptrdst = NULL;
    PRINTF("Test memmove1: %s\n", memsrc);
    ptrdst = my_memmove( memsrc, memsrc, 16);
    
    PRINTF("\nmemmove1: %s\n", ptrdst);
    if(ptrdst == NULL)
    {
    	return 0;
    }
    else
        return 1;
}

// This function will test overlapped memmove where there is overlap of the end
// of destination and start of the source regions
int8_t test_memmove2(){
 
    uint8_t memsrc[16] = "OVERLAPFUN";
    uint8_t *ptrdst = NULL;
    PRINTF("Test memmove2:\n%s\n", memsrc);
    ptrdst = my_memmove( memsrc, memsrc+5, 16);
    
    PRINTF("\nmemmove2: %s\n", ptrdst);
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

    uint8_t memsrc[16] = "OVERLAPFUN";
    uint8_t *ptrdst = NULL;
    PRINTF("Test memmove3:\n%s\n", memsrc);
    ptrdst = my_memmove( memsrc+5, memsrc, 16);
    
    PRINTF("\nmemmove3: %s\n", ptrdst);
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
int8_t test_memset(){

    #define MEMSET_SIZE (5) 
    uint8_t memsrc[MEMSET_SIZE] = {2, 5, 1, 9, 100};
    uint8_t value = 90;
    uint8_t *ptrsrc = NULL;
    PRINTF("\nTest memzero: \n\n");

    ptrsrc = my_memzero( memsrc, MEMSET_SIZE);
    PRINTF("Test memzero %p\n", ptrsrc);
    PRINTF("Test memzero Value %d\n", *ptrsrc);
    PRINTF("\nTest memset: \n\n");

    ptrsrc = my_memset( memsrc, MEMSET_SIZE, value);
    PRINTF("Test memset Address %p\n", ptrsrc);
    PRINTF("Test memset Value %d\n", *ptrsrc);
    
    if(ptrsrc == NULL)
    {
    	return 1;
    }
    else
	return 0;
}

// This function will test reverse
int8_t test_reverse(){
    #define MEMREVERSE_SIZE (5) 
    uint8_t memsrc[MEMREVERSE_SIZE] = {2, 5, 1, 9, 100};
    uint8_t *ptrsrc = NULL;
    PRINTF("\nTest memreverse: \n\n");
    PRINTF("Test memreverse INIT Reverse Address =  %p\n", memsrc);

    ptrsrc = my_reverse( memsrc, MEMREVERSE_SIZE);
    PRINTF("Test memreverse Value %d\n", *ptrsrc);
    PRINTF("Test memreverse Full Address %p\n", ptrsrc);
    
    if(ptrsrc == NULL)
    {
    	return 1;
    }
    else
	return 0;

}
