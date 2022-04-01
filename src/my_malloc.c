#include "../include/my_secmalloc.h"

void    *my_malloc(size_t size)
{
    void* ptr = NULL;

    if (size != 0)
    {
        //TODO: create a new allocation with mmap
        //TODO: create and add this new heap to the heap chain list    
    }

    return ptr;
}
