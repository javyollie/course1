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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
  PRINTF("my_memmove:\n\n");
  uint8_t buffer[length];
  uint8_t *buf_ptr = &buffer[0];
  
  for(uint8_t j = 0; j < length; j++)
  {
      //if((uint8_t)(dst-src) >= 0 )
      //{ 
          *buf_ptr = *src; 
          src++;
      //}
     // else
      //{
        //  *buf_ptr = *dst;
	 // dst++;
      //}

      buf_ptr++;
  }
  
  src = src - length;
  buf_ptr = buf_ptr - length;

  for(uint8_t i = 0; i < length; i++)
  {
      if( i >= (uint8_t)(dst-src))
      {
          *dst = *buf_ptr;
          PRINTF("Address of buf[%d] =%p\n", i, buf_ptr);	
          PRINTF("Values of buf[%d] =%d\n\n", i, *(buf_ptr-(uint8_t)(dst-src)) );
          buf_ptr++;
      }
      else if( i >= (uint8_t)(src-dst))
      {
      PRINTF("IN Address of dst[%d] =%p\n", i, dst); 
      length = (src-dst);    
      //buf_ptr++;
	  break;
      }
      else
      {
        *dst = *src;
        src++;
      }

      PRINTF("Address of src[%d] =%p\n", i, src);
      PRINTF("Values of src[%d] =%d\n\n", i, *src);
      PRINTF("SIZE index = [%d]; diff = %ld\n", i, (src - dst));
      
      PRINTF("Address of dst[%d] =%p\n", i, dst); 
      PRINTF("Values of dst[%d] =%d\n\n\n", i, *dst );
      
      dst++; 
  }
  
  dst = dst - length;
  return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length)
{
    PRINTF("my_memcopy:\n");
    PRINTF("Address of src[0] =%p before copy\n", src);	

    PRINTF("Address of dst[0] =%p before copy\n", dst);	
    for(uint8_t i = 0; i < length; i++)
    {
	*dst = *src;
    
        PRINTF("Address of src[%d] =%p\n", i, src);	
	PRINTF("Values of src[%d] =%d\n", i, *src );

	PRINTF("Address of dst[%d] =%p\n", i, dst); 
	PRINTF("Values of dst[%d] =%d\n", i, *dst );

	dst++;
	src++;
    }
    PRINTF("OUT Address of ds =%p\n", dst );
    dst = dst - length;
    PRINTF("OUT Address of ds =%p\n", dst );

    return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
    
    for(uint8_t i = 0; i < length; i++)
    {
	*src = value;
    
        PRINTF("Address of src[%d] =%p\n", i, src);	
	PRINTF("Values of src[%d] =%d\n", i, *src );

	src++;
    }
    PRINTF("out loop Address of src=%p\n", src);	
    
    src = src - length;
    PRINTF("Rtr memset Address of src=%p\n", src);	
    
    return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length)
{
    for(uint8_t i = 0; i < length; i++)
    {
	*src = 0;
        PRINTF("Address of src[%d] =%p\n", i, src);	
	PRINTF("Values of src[%d] =%d\n", i, *src );

	src++;
    }
    PRINTF("out loop Address of src=%p\n", src);	
    src = src - length;
    PRINTF("ret memzero Address of src=%p\n", src);	
    return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length)
{
    PRINTF("my_reverse:\n");
    uint8_t memdst[length];
    uint8_t *dst = NULL;
    PRINTF("Address of dst[0] = 0x%p before reverse\n", dst);	
    PRINTF("Address of src[0] = 0x%p before reverse\n", src);	
    dst = my_memcopy(src, memdst, length);
    PRINTF("Address2 of dst[0] = 0x%p before reverse\n", dst);	
    PRINTF("Address2 of src[0] = 0x%p before reverse\n", src);	
    PRINTF("Values of src =%d\n", *src );
    PRINTF("Values of dst =%d\n", *dst );
    dst = dst+length-1;
    for(uint8_t i = 0; i < length; i++)
    {
	*src = *dst;
    
        PRINTF("my_reverse: Loop Address of src[%d] =%p\n", i, src);	
	PRINTF("my_reverse: Loop Values of src[%d] =%d\n", i, *src );

	PRINTF("Address of dst[%d] =%p\n", i, dst); 
	PRINTF("Values of dst[%d] =%d\n", i, *dst );

	dst--;
	src++;
    }
    PRINTF("OUT Address of src =%p returned\n", src );
    src = src - length;
    PRINTF("OUT Address of src =%p returned\n", src );

    return src;
}

int32_t * reserve_words(size_t length)
{
    return 0;
}

void free_words(int32_t * src)
{

}












