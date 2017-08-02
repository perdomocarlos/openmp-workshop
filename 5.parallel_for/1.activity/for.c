#include <stdio.h>      /* Standard I/O Library: printf */
#include <stdlib.h>     /* Standard Library: malloc, calloc, free, ralloc */
#include <string.h>     /* String funtions: strcpy*/
// 1.Import the omp.h funtion library here

# define N 10

int main(){

    // 2.Create a parallel región here
    // 3.Place the *for* directive just above outer for(....){...}
    for(int i=0; i<N; ++i){
        // 6.Place the *for* directive just above inner for(....){...}
        for(int j=0; j<N; ++j){
            // 4.Get thread id (within inner for)
            // 5.Print thread id, i and j (within inner for)
        }
    }

    return EXIT_SUCCESS;
};
