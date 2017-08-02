#include <stdlib.h>     /* Standard Library: EXIT_SUCCESS */
#include <stdio.h>      /* Standard I/O Library: printf */
#include <omp.h>        /* OpenMP funtions header: omp_set_num_threads, omp_get_thread_num */


int main(void){

    /* A variable shared by all threads */
    int shared_variable = 35;
    /* A varable private for each therad */
    int private_variable = 60;

    /* Setting the number of thread that will run in the parallel region */
    omp_set_num_threads(4);
    
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        private_variable = private_variable + thread_id;
        
        printf("Hi i'm thread %d, my private_variable value is %d, the shared_variable value is %d\n", 
            thread_id, private_variable, shared_variable);

    }

    return EXIT_SUCCESS;
};