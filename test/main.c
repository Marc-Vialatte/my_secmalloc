#include <stdio.h>
#include <stdlib.h>
#include "../include/my_secmalloc.h"
#include "string.h"

int main () 
{
    int i, n;
    int *a, *b;

    printf(" Number of int to allocate: ");
    scanf("%d", &n);

    int *p = (int *)my_malloc(n*sizeof(int));

    if(p == NULL) {
        printf("Memory not available");
        return(0);
    }
    for(i = 0; i < n; i++) {
    //int i = 0;
        printf(" %d -Int to store: ", i);
        scanf("%d", p + i);
    }

    for(i = 0; i < n; i++) {
        printf("- [%d] - ", *(p + i));
    }/*
    for(i = 0; i < n; i++) {
        my_free(*(p+i));
        printf("- [%d] - ", *(p + i));
    }*/
    printf("\n\n");
    printf("Before free[%d] \n\n ", *(p));
    my_free(p);
    if (p == NULL) {
        printf("Memory not available");
    }

    printf("Number of elements to be entered:");
    scanf("%d",&n);

    a = (int*)calloc(n, sizeof(int));
    printf("Enter %d numbers:\n",n);
    for( i=0 ; i < n ; i++ ) {
        scanf("%d",&a[i]);
    }

    b = (int*)my_calloc(n, sizeof(int));
    printf("Enter %d numbers:\n",n);
    for( i=0 ; i < n ; i++ ) {
        scanf("%d",&b[i]);
    }


    printf("The numbers entered are: ");
    for( i=0 ; i < n ; i++ ) {
        printf("%d ",a[i]);
    }
    my_free( a );

    printf("\nThe numbers entered are: ");
    for( i=0 ; i < n ; i++ ) {
        printf("%d ",b[i]);
    }
    my_free( b );


    char *str;

    /* Initial memory allocation */
    str = (char *) my_malloc(15);
    strcpy(str, "\n\ntutorialspoint");
    printf("String = %s,  Address = %u\n", str, str);

    /* Reallocating memory */
    str = (char *) my_realloc(str, 25);
    printf("String = %s,  Address = %u\n", str, str);

    my_free(str);
    
    return(0);
}
