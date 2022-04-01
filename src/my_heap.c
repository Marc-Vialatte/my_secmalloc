#include "../include/my_secmalloc.h"

struct  my_heap
{
    struct  my_heap *previous;
    struct  my_heap *next;
    size_t  size;
    void* data;
};

