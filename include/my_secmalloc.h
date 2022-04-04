#ifndef _SECMALLOC_H
#define _SECMALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

// Define the heap structure
struct  my_heap 
{
    void    *data;
    size_t  size;
    struct  my_heap *prev;
    struct  my_heap *next;
};

struct my_heap *my_heap_list = NULL;

// Declare the functions
void    *my_malloc(size_t size);
void    my_free(void *ptr);
void    *my_calloc(size_t nmemb, size_t size);
void    *my_realloc(void *ptr, size_t size);

struct my_heap find_heap(void *ptr);

#endif
