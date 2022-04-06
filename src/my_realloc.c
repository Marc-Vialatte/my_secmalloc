#include "../include/my_secmalloc.h"

static void    my_memcpy(void *dest, void *src, int size)
{
    char    *ptr_dest;
    char    *ptr_src;
    int     i;

    ptr_dest = (char *)dest;
    ptr_src = (char *)src;
    for (i = 0; i < size; i++)
    {
        ptr_dest[i] = ptr_src[i];
    }
}

void    *my_realloc(void *ptr, size_t size)
{
    FILE* log_file;

    // Validate input
    if (ptr == NULL) 
    {
        log_file = fopen(MSM_OUTPUT, "a");
        fprintf(log_file, "my_realloc: invalid input pointer\n");
        fclose(log_file);

        return my_malloc(size);
    }
    if (size == 0) 
    {
        my_free(ptr);

        log_file = fopen(MSM_OUTPUT, "a");
        fprintf(log_file, "my_realloc: invalid input size\n");
        fclose(log_file);

        return NULL;
    }

    // Get the heap
    struct my_heap *heap = NULL;
    heap = find_heap(ptr);
    
    // If the size is the same, return the pointer
    if (heap->size >= size) 
    {
        log_file = fopen(MSM_OUTPUT, "a");
        fprintf(log_file, "my_realloc: %p %zu\n", ptr, size);
        fclose(log_file);

        return ptr;
    }
    // Otherwise, allocate a new heap and copy the data
    void *new_ptr = my_malloc(size);
    if (new_ptr == NULL) 
    {
        log_file = fopen(MSM_OUTPUT, "a");
        fprintf(log_file, "my_realloc: failed to allocate heap\n");
        fclose(log_file);
        
        return NULL;
    }
    my_memcpy(new_ptr, ptr, heap->size);
    // Free the old heap
    my_free(ptr);

    log_file = fopen(MSM_OUTPUT, "a");
    fprintf(log_file, "my_realloc: %p %zu\n", ptr, size);
    fclose(log_file);

    return new_ptr;
}
