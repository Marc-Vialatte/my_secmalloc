#include <stdio.h>
#include <stdlib.h>
#include "../include/my_secmalloc.h"
#include <string.h>

int main () 
{
    // Malloc
    int *ptr = my_malloc(sizeof(int));
    *ptr = 2600;
    printf("my_malloc: %d\n", *ptr);
    my_free(ptr);
    printf("my_malloc: %p\n", (void*)ptr);
    
    // Calloc
    int *ptr2 = my_calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        ptr2[i] = i;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("my_calloc %i: %d\n", i, ptr2[i]);
    }
    my_free(ptr2);

    // Realloc
    int *ptr3 = my_malloc(sizeof(int));
    *ptr3 = 2600;
    printf("my_malloc: %d\n", *ptr3);
    ptr3 = my_realloc(ptr3, sizeof(int) * 2);
    *(ptr3 + 1) = 2600;
    printf("my_realloc: %d %d\n", *ptr3, *(ptr3 + 1));
    my_free(ptr3);

    return 0;
}
