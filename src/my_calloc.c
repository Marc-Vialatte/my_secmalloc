#include "my_secmalloc.h"

void    *my_calloc(size_t nmemb, size_t size) 
{
    // Validate input
    if (nmemb == 0 || size == 0) {
        return NULL;
    }
    // Get the size
    size_t total_size = nmemb * size;
    // Allocate the heap
    void *ptr = my_malloc(total_size);
    // If the heap failed to be created, return NULL
    if (ptr == NULL) 
    {
        return NULL;
    }
    // Otherwise, set the heap to 0
    memset(ptr, 0, total_size);

    return ptr;
}
