# OpenMP *for* directve

## Objectives

- [x] You will learn how to use the **for** directive to process a matrix in parallel.
- [x] You will learn how threads divide the matrix processing.

## Introdution

The parallel directive allows us to parallelize one or more sections of code, however the threads created with this directive carry out the same tasks (or execute the same code). In practice, the idea of OpenMP seeks to solve a bing problem by dividing it into independent parts, which can be carried out in parallel by several threads.

In some cases it is necessary each thread perform different tasks, for example:

* Each threads perform **different iterations of a for loop**.
* Or they can execute **different sections of code**.

Through the following exercise we will see what the **for** directive does and how it allows us to process the data in matrices in parallel.

## Exercise 1

Complete the code *for.c* on this folder. The code is marked with number 1 to 6 that describes the sequence of steps that you must follow.

```c
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
```

Complete the code with the following steps (please replace the comments).

1. Import the omp.h funtions header

```c
#include <omp.h>        /* OpenMP funtions header */
```

2. Parallize this section of code with a **parallel region**

```c
for(int i=0; i<N; ++i){
    for(int j=0; j<N; ++j){
        // 4.Get thread id (within inner for)
        // 5.Print thread id, i and j (within inner for)
    }
}
```
3. Place the *for* directive just above outer for(....){...}

```c
#pragma omp for
for(...){
 ...
}
```

4. Get thread id (**within for statement**)

```c
int thread_id = omp_get_thread_num();
```

5. Print thread id, i and j (**within for statement**)

```c
printf("Hi i'm thread %d, i'm working on %d,%d\n",thread_id,i,j);

```

Add the compilation flag **-fopenmp** to the CFLAGS variable in your *Makefile*. To enable OpenMP in the code.

```basemake
CFLAGS = -std=gnu++11 -O3 -fopenmp
```

Run the code and answer the following questions.

```bash
make run 
```

### Questions

* How many threads were executed?
* Which rows does each thread process?
* Run the code many times, What changes do you see in the program output?
