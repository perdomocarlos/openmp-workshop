#include <stdio.h>      /* Standard I/O Library: printf */
#include <stdlib.h>     /* Standard Library: malloc, calloc, free, ralloc */
#include <string.h>     /* String funtions: strcpy*/
// 1.Import the omp.h funtion library here

/* Array size */
#define N 99000000

/* Creating an alias for  unsigned long int datatype */
typedef unsigned long int long_int;

int main(){

    /*  Memory initialization for arrays A, B, C */
    long_int * A = (long_int *) malloc( N * sizeof(long_int) );
    long_int * B = (long_int *) malloc( N * sizeof(long_int) );
    long_int * C = (long_int *) malloc( N * sizeof(long_int) );

    /* Arrays content initialization */
    for(int i=0; i<N; ++i) A[i] = B[i] = C[i] = 1;

    // 2. Enclose the following section of code in a parallel region
    // i. add the parallel for directive just before for(int j=0; j<N; ++j)...;
    for(int j=0; j<N; ++j) C[j] = A[j] * B[j] + A[j] ;
    
    /* Answere validation */
    char validation[10];
    strcpy(validation,"Ok");
    for(int k=0; k<N; ++k) 
        if (C[k] != 2) strcpy(validation,"Fail");

    printf ( "\t%d \t\t %s \t\t ", N, validation );

    /* Releasing memory */
    free(A);
    free(B);
    free(C);

    return EXIT_SUCCESS;
}