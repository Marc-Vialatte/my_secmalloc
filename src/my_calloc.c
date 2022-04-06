#include "../include/my_secmalloc.h"

static void *my_memset(void *ptr, int value, size_t len)
{
    unsigned int    i;

    for (i = 0; i < len; i++)
    {
        ((char *)ptr)[i] = value;
    }
    return (ptr);
}

void    *my_calloc(size_t nmemb, size_t size) 
{
    FILE* log_file;

    // Validate input
    if (nmemb == 0 || size == 0) 
    {
        log_file = fopen(MSM_OUTPUT, "a");
        fprintf(log_file, "my_calloc: invalid input\n");
        fclose(log_file);

        return NULL;
    }
    // Get the size
    size_t total_size = nmemb * size;
    // Allocate the heap
    void *ptr = my_malloc(total_size);
    // If the heap failed to be created, return NULL
    if (ptr == NULL) 
    {
        log_file = fopen(MSM_OUTPUT, "a");
        fprintf(log_file, "my_calloc: failed to allocate heap\n");
        fclose(log_file);
        
        return NULL;
    }
    // Otherwise, set the heap to 0
    my_memset(ptr, 0, total_size);

    log_file = fopen(MSM_OUTPUT, "a");
    fprintf(log_file, "my_calloc: %zu %zu %p\n", nmemb, size, ptr);
    fclose(log_file);

    return ptr;
}
