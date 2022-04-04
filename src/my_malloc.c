#include "../include/my_secmalloc.h"

void *my_malloc(size_t size)
{
    // Validate input
    if (size == 0) {
        return NULL;
    }
    // Get the heap
    struct my_heap *heap = my_heap_list;

    // If the heap_list is NULL, initialize it
    if (heap == NULL) 
    {
        void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        if (ptr == MAP_FAILED) 
        {
            return NULL;
        }
        heap->data = ptr;
        heap->size = size;
        heap->prev = NULL;
        heap->next = NULL;
        my_heap_list = heap;
        return ptr;
    }
    //Otherwise just create a new heap
    while (heap->next != NULL)
    {
        heap = heap->next;
    }
    struct my_heap *new_heap = NULL;
    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) 
    {
        return NULL;
    }
    new_heap->data = ptr;
    new_heap->size = size;
    new_heap->prev = heap;
    new_heap->next = NULL;
    heap->next = new_heap;
    
    return ptr;
}
