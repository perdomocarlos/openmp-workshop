#include <stdio.h>      /* Standard I/O Library: printf */
#include <stdlib.h>     /* Standard Library: malloc, calloc, free, ralloc */
#include <string.h>     /* String funtions: strcpy*/
// 1.Import the omp.h funtion library here

# define N 10

int main(){

    // 2.Create a parallel región here
    for(int i=0; i<N; ++i){
        // 3.Get thread id (within for)
        // 4.Print thread id and i (within for)
    }

    return EXIT_SUCCESS;
};
