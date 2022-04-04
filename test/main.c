#include <stdio.h>
#include <stdlib.h>
#include "../include/my_secmalloc.h"

int main () 
{
    // allocating memory to p
    int* p = my_malloc(8*sizeof(int));
     
    *p = 100;
     
    // deallocated the space allocated to p
    my_free(p);
     
    return 0;
}