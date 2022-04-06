#include <stdio.h>
#include <stdlib.h>
#include "../include/my_secmalloc.h"
#include "string.h"

int main () 
{
    int *ptr = my_malloc(sizeof(int));
    *ptr = 2600;
    printf("%d\n", *ptr);
    my_free(ptr);
    
    return 0;
}
