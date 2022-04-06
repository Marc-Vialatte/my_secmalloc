#include "../include/my_secmalloc.h"

void *my_malloc(size_t size)
{
    FILE* log_file;

    // Validate input
    if (size == 0) {
        return NULL;
    }
    // Get the heap
    struct my_heap *heap = my_heap_list;

    // If the heap_list is NULL, initialize it
    if (heap == NULL) 
    {
        heap = mmap(NULL, sizeof(struct my_heap), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        if (heap == MAP_FAILED) 
        {
            log_file = fopen(MSM_OUTPUT, "a");
            fprintf(log_file, "my_malloc: could not create heap\n");
            fclose(log_file);

            return NULL;
        }
        void *ptr = mmap(NULL, (size + sizeof(int)), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        if (ptr == MAP_FAILED) 
        {
            log_file = fopen(MSM_OUTPUT, "a");
            fprintf(log_file, "my_malloc: could not allocate memory\n");
            fclose(log_file);
            
            return NULL;
        }
        int *canary_ptr = (int*)((char*)ptr + size);

        heap->data = ptr;
        heap->size =  size;
        heap->prev = NULL;
        heap->next = NULL;
        heap->canary = rand();

        *canary_ptr = heap->canary;

        my_heap_list = heap;

        log_file = fopen(MSM_OUTPUT, "a");
        fprintf(log_file, "my_malloc: %zu %p\n", size, ptr);
        fclose(log_file);

        return ptr;
    }
    //Otherwise just create a new heap
    while (heap->next != NULL)
    {
        heap = heap->next;
    }
    struct my_heap *new_heap = mmap(NULL, sizeof(struct my_heap), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (heap == MAP_FAILED) 
    {
        log_file = fopen(MSM_OUTPUT, "a");
        fprintf(log_file, "my_malloc: could not allocate heap\n");
        fclose(log_file);
        
        return NULL;
    }
    void *ptr = mmap(NULL, (size + 2 * sizeof(int)), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) 
    {
        log_file = fopen(MSM_OUTPUT, "a");
        fprintf(log_file, "my_malloc: could not allocate memory\n");
        fclose(log_file);
        
        return NULL;
    }
    int *canary_ptr = (int*)((char*)ptr + size + sizeof(int));

    new_heap->data = ptr;
    new_heap->size = size;
    new_heap->prev = heap;
    new_heap->next = NULL;
    new_heap->canary = rand();

    *canary_ptr = heap->canary;

    heap->next = new_heap;
    
    log_file = fopen(MSM_OUTPUT, "a");
    fprintf(log_file, "my_malloc: %zu %p\n", size, ptr);
    fclose(log_file);

    return ptr;
}
