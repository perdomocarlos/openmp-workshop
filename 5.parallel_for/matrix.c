#include <stdio.h>      /* Standard I/O Library: printf */
#include <stdlib.h>     /* Standard Library: malloc, calloc, free, ralloc */
#include <string.h>     /* String funtions: strcpy*/

# define N 9000         /* A, B and C rows and cols */

/* Creating an alias for unsigned long int datatype */
typedef unsigned long int long_int;

int main(int argc, char *argv[]){

    /* Reserving space in memory for matrices rows  */
    long_int ** A = (long_int **) malloc( N * sizeof(long_int *) );
    long_int ** B = (long_int **) malloc( N * sizeof(long_int *) );
    long_int ** C = (long_int **) malloc( N * sizeof(long_int *) );

    /* Reserving space in memory for matrices cols  */
    for(int i=0; i<N; ++i){
        A[i] = (long_int *) malloc( N * sizeof(long_int *) );
        B[i] = (long_int *) malloc( N * sizeof(long_int *) );
        C[i] = (long_int *) malloc( N * sizeof(long_int *) );
    }

    /* Initializing matrices */
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            A[i][j] = 1;
            B[i][j] = 2;
            C[i][j] = 0;           
        }
    }

    /* Matrices Sum C = A + B */
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    /* Checking the answere */
    char validation[10];
    strcpy(validation,"Ok");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if( C[i][j] != 3) strcpy(validation, "Fail");
        }
    }

    printf ( "\t%d \t\t\t %s \t\t ", N, validation );

    /* Releasing Main Memory */
    for(int i=0; i<N; ++i){
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }

    free(A);
    free(B);
    free(C);

    /* Return success status  */
    return EXIT_SUCCESS;
};
