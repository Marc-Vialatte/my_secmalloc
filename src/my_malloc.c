#include "../include/my_secmalloc.h"

void    *my_malloc(size_t size) 
{
    // Validate input
    if (size == 0) 
    {
        return NULL;
    }

    // Get the heap
    struct my_heap *heap = mmap(NULL, size + sizeof(struct my_heap), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    // If the heap failed to be created, return NULL
    if (heap == MAP_FAILED) {
        return NULL;
    }

    // Set heap
    heap->size = size;
    heap->next = NULL;
    heap->free = false;
    return heap;
}
