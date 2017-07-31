#include <stdio.h>      /* Standard I/O Library: printf */
#include <stdlib.h>     /* Standard Library: malloc, calloc, free, ralloc */
#include <string.h>     /* String funtions: strcpy*/

#define N 100000000

int main(){
    unsigned long int * A = (unsigned long int *) malloc( N * sizeof(unsigned long int) );
    unsigned long int * B = (unsigned long int *) malloc( N * sizeof(unsigned long int) );
    unsigned long int * C = (unsigned long int *) malloc( N * sizeof(unsigned long int) );

    for(int i=0; i<N; ++i) A[i] = B[i] = C[i] = 1;
    for(int j=0; j<N; ++j) C[j] = A[j] * B[j] + A[j] ;

    char validation[10];
    strcpy(validation,"Ok");
    for(int k=0; k<N; ++k) 
        if (C[k] != 2) strcpy(validation,"Fail");

    printf ( "\t%d \t\t %s \t\t ", N, validation );

    free(A);
    free(B);
    free(C);

    return EXIT_SUCCESS;
}