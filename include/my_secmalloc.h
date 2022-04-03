#ifndef _SECMALLOC_H
#define _SECMALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <stdbool.h>

// Define the heap structure
struct  my_heap 
{
    struct my_heap *next;
    size_t size;
    bool free;
};

// Declare the functions
void    *my_malloc(size_t size);
void    my_free(void *ptr);
void    *my_calloc(size_t nmemb, size_t size);
void    *my_realloc(void *ptr, size_t size);

#endif
