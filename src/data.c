#include "data.h"
#include "stdlib.h"
#include "memory.h"
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
    PRINTF("my_itoa: data = [%ld], quotient = [%ld], remainder = [%ld]\n\n", data, (uint32_t)data/base, data%base);
    uint32_t rem = 0;
    uint32_t quotient = 0;
    uint8_t size = 0;
    ptr = (uint8_t*) malloc(sizeof(uint8_t) *10);
    while(data != 0)
    {
        quotient = data/base;
	rem = data%base;
	data = quotient;
	if( base > 10 && rem > 9)
	{
	    *ptr = (rem + 0x37);
            PRINTF("my_itoa: Greater than base 10 - Value of ptr: [%d]\nremainder = %lu\n", *ptr, rem);
	}
	else
	{
	    *ptr = (rem + 0x30);
	}
        PRINTF("my_itoa: Value of ptr: [%d]\nremainder = %lu\n", *ptr, rem);
        PRINTF("my_itoa: Address of ptr: [%p]\n", ptr);
	ptr++;
	size++;
    }
    ptr = ptr - size; 
    PRINTF("my_itoa: Value of ptr as string: = %s\nsize of ptr = %d\n", ptr, size);
    PRINTF("my_itoa: Address of ptr: [%p]\n", ptr);
    uint8_t *ptrsrc = NULL;
    ptrsrc = my_reverse(ptr, size);
    PRINTF("my_itoa: RETURN Value of ptr as string: = %s\nsize of ptr = %d\n", ptrsrc, size);
    PRINTF("my_itoa: RETURN Address of ptr: [%p]\n", ptrsrc);
    return 0;
}

int32_t my_atoi(uint8_t * pts, uint8_t digits, uint32_t base)
{
   return 0;
}
