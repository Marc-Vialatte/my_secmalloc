#include "../include/my_secmalloc.h"

struct my_heap find_heap(void *ptr)
{
    struct my_heap *heap = my_heap_list;
    while (heap != NULL)
    {
        if (heap->data == ptr)
        {
            return *heap;
        }
        heap = heap->next;
    }
    return *heap;
}
