#include <stdio.h>
#include <stdlib.h>
#include "../include/my_secmalloc.h"

int main() {
    int n;
    printf("1 - Iteration nb: ");
    scanf("%d", &n);

    int *p = (int *)my_malloc(n*sizeof(int));
    if(p == NULL) {
        printf("Memory not available");
        return(0);
    }
    for(int i = 0; i < n; i++) {
    int i = 0;
        printf("2 -Enter Number: ");
        scanf("%d", p + i);
    }

    for(int i = 0; i < n; i++) {
        printf("allocation of: %d \n", *(p + i));
        return(0);
    }
    return(0);
}
