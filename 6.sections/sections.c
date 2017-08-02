#include <stdio.h>      /* Standard I/O Library: printf */
#include <stdlib.h>     /* Standard Library: malloc, calloc, free, ralloc */
#include <string.h>     /* String funtions: strcpy*/

/* Array size */
#define N 9900000

int main(){

    /*  Memory initialization for arrays A, B, C */
    double * A = (double *) malloc( N * sizeof(double) );
    double * B = (double *) malloc( N * sizeof(double) );
    double * C = (double *) malloc( N * sizeof(double) );
    double * D = (double *) malloc( N * sizeof(double) );

    /* Arrays content initialization */
    for(int i=0; i<N; ++i){
        A[i] = 1.5;
        B[i] = 22.35;
        B[i] = C[i] = 0.0;
    }

    /* Arrays sum */
    for(int i = 0; i < N; ++i)
        C[i] = A[i] + B[i];

    /* Arrays multiplication */
    for(int i = 0; i < N; ++i)
        D[i] = A[i] * B[i];

    /* Releasing memory */
    free(A);
    free(B);
    free(C);
    free(D);

    return EXIT_SUCCESS;
}