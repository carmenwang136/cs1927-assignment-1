//
//  COMP1927 Assignment 1 - Memory Suballocator
//  allocator.c ... implementation
//
//  Created by Liam O'Connor on 18/07/12.
//  Modified by John Shepherd in August 2014
//  Copyright (c) 2012-2014 UNSW. All rights reserved.
//

#include "allocator.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <maths.h> 

#define HEADER_SIZE    sizeof(struct free_list_header)  
#define MAGIC_FREE     0xDEADBEEF
#define MAGIC_ALLOC    0xBEEFDEAD

#define TRUE     1
#define FALSE    0

typedef unsigned char byte;
typedef u_int32_t vlink_t;
typedef u_int32_t vsize_t;
typedef u_int32_t vaddr_t;

typedef struct free_list_header {
   u_int32_t magic;           // ought to contain MAGIC_FREE
   vsize_t size;              // # bytes in this block (including header)
   vlink_t next;              // memory[] index of next free block
   vlink_t prev;              // memory[] index of previous free block
} free_header_t;

// Global data

static byte *memory = NULL;   // pointer to start of suballocator memory
static vaddr_t free_list_ptr; // index in memory[] of first block in free list
static vsize_t memory_size;   // number of bytes malloc'd in memory[]


void sal_init(u_int32_t size) {
// If size is not 0 then enter loop else abort  
  if (size != 0) {

  // If the (complement of size)-1 does not equal/to the size
  // From the fact that only numbers that are a power of two
  // when added 1 to, changes the binary in a way that makes the
  // complement+1 intersection with the number equal to the size
  // e.g 4 in binary is 0100, (~0100)=1011, (~0100)+1=1100, (0100n1100)=0100 which is 4.
  // If untrue then it will need to be bit shifted to the next power of 2
    if (size & (~size + 1) != size) {
      int shift = size;
      shift = log(size)/log(2);
      size = size >> shift;
      shift++;
      size = size << shift; 
      // Size is now a power of two
    } 
    
    memory = malloc(size);

    //add doubly link list pointer stuff here
  
  } else {
    fprintf(stderr, "sal_init: insufficient memory");
    abort();
  }
}

void *sal_malloc(u_int32_t n) {
   // TODO
   return NULL; // temporarily
}

void sal_free(void *object) {
   // TODO
}

void sal_end(void) {
   // TODO
   // free(memory);
   // free the pointers
}

void sal_stats(void) {
   // Optional, but useful
   printf("sal_stats\n");
    // we "use" the global variables here
    // just to keep the compiler quiet
   memory = memory;
   free_list_ptr = free_list_ptr;
   memory_size = memory_size;
}
