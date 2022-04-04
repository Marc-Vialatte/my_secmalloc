#include "../include/my_secmalloc.h"

void    my_free(void *ptr) 
{
    // Validate input
    if (ptr == NULL) 
    {
        return;
    }

    // Get the heap
    struct my_heap *heap = NULL;
    *heap = find_heap(ptr);
    munmap(ptr, heap->size);

    // If the heap is the only one in the list, set the list to NULL
    if (heap->prev == NULL && heap->next == NULL) 
    {
        my_heap_list = NULL;
    }
    // If the heap is the first one in the list, set the list to the next heap
    else if (heap->prev == NULL) 
    {
        my_heap_list = heap->next;
        my_heap_list->prev = NULL;
    }
    // If the heap is the last one in the list, set the previous heap to NULL
    else if (heap->next == NULL) 
    {
        heap->prev->next = NULL;
    }
    // Otherwise, set the previous and next heap to each other
    else 
    {
        heap->prev->next = heap->next;
        heap->next->prev = heap->prev;
    }
}
