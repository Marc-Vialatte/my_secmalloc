#include "../include/my_secmalloc.h"

void    my_free(void *ptr) 
{
    FILE* log_file;

    // Validate input
    if (ptr == NULL) 
    {
        log_file = fopen(MSM_OUTPUT, "a");
        fprintf(log_file, "my_free: invalid pointer\n");
        fclose(log_file);
        
        return;
    }

    // Get the heap
    struct my_heap *heap = NULL;
    heap = find_heap(ptr);
    // If the heap is not found, return
    if (heap == NULL) 
    {
        log_file = fopen(MSM_OUTPUT, "a");
        fprintf(log_file, "my_free: %p not found\n", ptr);
        fclose(log_file);

        return;
    }

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

    munmap(heap, sizeof(struct my_heap));

    log_file = fopen(MSM_OUTPUT, "a");
    fprintf(log_file, "my_free: %p\n", ptr);
    fclose(log_file);
}
