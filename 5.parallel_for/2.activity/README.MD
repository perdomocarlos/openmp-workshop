# OpenMP *for directve*

The parallel directive allows us to parallelize one or more sections of code, however the threads created with this directive carry out the same tasks (or execute the same code). In practice, the idea of OpenMP seeks to solve a bing problem by dividing it into independent parts, which can be carried out in parallel by several threads.

In some cases it is necessary each thread perform different tasks, for example:

* Each threads perform **different iterations of a for loop**.
* Or they can execute **different sections of code**.

Through the following exercise we will see what the **for** directive does and how it allows us to process the data in a vector in parallel.

## Exercise 1

This code performs the matrix sum C = A + B. Les't check if this code do what we expect.

### Run the *matrix.c* code as follows

```bash
make run
```
¿How much time it takes to complete?

## Exercise 2

After having executed the *matrix.c* code sequentially (Exercise 1), let's try to parallelize the code using the **for directive**.  

* Add the OpenMP Libary, to enable the OpenMP features in the code.

```c
#include <stdio.h>      /* Standard I/O Library: printf */
#include <stdlib.h>     /* Standard Library: malloc, calloc, free, ralloc */
#include <string.h>     /* String funtions: strcpy*/
```

```c
#include <stdio.h>      /* Standard I/O Library: printf */
#include <stdlib.h>     /* Standard Library: malloc, calloc, free, ralloc */
#include <string.h>     /* String funtions: strcpy*/
#include <omp.h>        /* OpenMP library */
```

* Replace this code

```c
for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        C[i][j] = A[i][j] + B[i][j];
    }
}
```

* for that one

```c
#pragma omp parallel shared(A,B,C)
{
    #pragma omp for
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
```

* Run the code

```bash
make run 
```

The previous code, create the parallel región (**parallel** directive),  suggest arrays A, B, and C  will be shared among threads (**shared** clause). Finally suggets each thread will perform a different iteration of the loop (**for** directive). i.e, if for loop has 100 iterations and 2 threads were created, the first thread performs 0 - 49 iterations and the second one the 50 - 99 iterations.

¿How much time did it take to finish? ¿Did execution time improve? ¿Why? **Ask monitor for answers**.

## Exercise 3

In the previous code, we place the directive **#pragma omp for** just in the first loop.  What would happend if intead of  of placing it there, we place it in the internal loop.

* Add the OpenMP Libary, to enable the OpenMP features in the code.

* Replace this code

```c
#pragma omp parallel shared(A,B,C)
{
    #pragma omp for
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
```

* for that one

```c
#pragma omp parallel shared(A,B,C)
{
for(int i=0;i<N;i++){
    #pragma omp for
    for(int j=0;j<N;j++){
        C[i][j] = A[i][j] + B[i][j];
    }
}
}
```

* Run the code

```bash
make run 
```

¿How much time did it take to finish? ¿Did execution time improve? ¿Why? ¿What is the difference with the code in Exersice 2?**Ask monitor for answers**.