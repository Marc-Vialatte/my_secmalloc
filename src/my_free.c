#include "my_secmalloc.h"

void    my_free(void *ptr) 
{
    // Validate input
    if (ptr == NULL) 
    {
        return;
    }

    // Get the heap
    struct my_heap *heap = ptr - sizeof(struct my_heap);
    // If the heap is already free, return
    if (heap->free) {
        return;
    }
    // Otherwise, unmap the heap
    munmap(heap, heap->size + sizeof(struct my_heap));
}
