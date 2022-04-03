#include "my_secmalloc.h"

void    *my_realloc(void *ptr, size_t size)
{
    // Validate input
    if (ptr == NULL) 
    {
        return my_malloc(size);
    }
    if (size == 0) 
    {
        my_free(ptr);
        return NULL;
    }

    // Get the heap
    struct my_heap *heap = ptr - sizeof(struct my_heap);
    // If the size is the same, return the pointer
    if (heap->size >= size) 
    {
        return ptr;
    }
    // Otherwise, allocate a new heap and copy the data
    void *new_ptr = my_malloc(size);
    if (new_ptr == NULL) 
    {
        return NULL;
    }
    memcpy(new_ptr, ptr, heap->size);
    // Free the old heap
    my_free(ptr);

    return new_ptr;
}
