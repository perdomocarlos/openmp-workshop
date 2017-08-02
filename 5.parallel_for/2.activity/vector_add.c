#include <stdio.h>      /* Standard I/O Library: printf */
#include <stdlib.h>     /* Standard Library: malloc, calloc, free, ralloc */
#include <string.h>     /* String funtions: strcpy*/
// 1.Import the omp.h funtion library here

/* Array size */
#define N 99999999

/* Creating an alias for  unsigned long int datatype */
typedef unsigned long int long_int;

int main(){

    /* Requesting dynamic memory for space to allocate A,B,C 
    arrays are created commonly like A[N], B[N], C[N]. However
    when N is too large it is neccesary to create them in the way
    described as follows.
    */
    long_int * A = (long_int *) malloc( N * sizeof(long_int) );
    long_int * B = (long_int *) malloc( N * sizeof(long_int) );
    long_int * C = (long_int *) malloc( N * sizeof(long_int) );

    /* Arrays content initialization */
    for(int i=0; i<N; ++i) A[i] = B[i] = C[i] = 1;

    /* Arrays sum C = A + B */
    for(int j=0; j<N; ++j) C[j] = A[j] + B[j];
    
    /* Answere validation */
    char validation[10];
    strcpy(validation,"Ok");
    for(int k=0; k<N; ++k) 
        if (C[k] != 2) strcpy(validation,"Fail");

    printf ( "\t%d \t\t %s \t\t ", N, validation );

    /* When we request dynamic memory for large arrays
    it is neccesary to release it before the application finish.
    If you do not do this, the memory will be occupied with the data
    of the arrays A, B and C regardless of whether the program is 
    finished. */
    free(A);
    free(B);
    free(C);

    return EXIT_SUCCESS;
}