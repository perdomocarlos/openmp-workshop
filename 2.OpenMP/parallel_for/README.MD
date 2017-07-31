# Parallel Programming With OpenMP (*for* directve)

OpenMP allows us to indicate which **regions of the code** we want to parallelize, annotating that sections with directives. the **parallel directive** create a team of threads where each thread execute the code enclosed by the directive. However, each thread creates its own copy of the code enclosed by the **parallel directive**, finally all therad do the same thing. In some cases it is necessary that each therad perform different tasks, for example:

* That threads perform **different iterations of a for loop**.
* Or that they can execute **diferent sections of code**.

## Exercise 1

This code performs the following operation between arrays: **C = A * B + A**. Lest check if this code do what we expect.

### Run the *vector_add.c* code as follows

```bash
make run 
```
¿How much time it takes to complete?

## Exercise 2

After having executed the *vector_add.c* code sequentially (Exercise 1), let's try to parallelize the code using the **for directive**.  

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
/* Add and multiplication C = A * B + A */
for(int j=0; j<N; ++j) C[j] = A[j] * B[j] + A[j] ;
```

* for that one

```c
#pragma omp parallel shared(A,B,C)
{
#pragma omp for
for(int j=0; j<N; ++j) C[j] = A[j] * B[j] + A[j] ;
}
```
The previous code, create the parallel región (*parallel directive*),  suggest arrays A, B, and C  will be shared among threads (*shared clause*). Finally suggets each thread will perform a different iteration, i.e, if for loop has 100 iterations and 2 threads were created, the first thread performs 0 - 49 iterations and the second one the 50 - 99 iterations.

* Run the code

```bash
make run 
```

¿How much time it takes to complete? ¿Did execution time improve? ¿Why? **Ask the monitor for answeres**.