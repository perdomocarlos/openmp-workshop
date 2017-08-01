# Parallel Programming With OpenMP (*for* directve)

OpenMP allows us to indicate which **regions of the code** we want to parallelize, annotating that sections with directives. the **parallel directive** creates a team of threads where each thread execute the code enclosed by the directive. However, each thread creates its own copy of the code enclosed by that directive, finally all threads will do the same thing. In some cases it is necessary each thread perform different tasks, for example:

* Each threads perform **different iterations of a for loop**.
* Or they can execute **different sections of code**.

## Exercise 1

This code performs the following operation between arrays: **C = A * B + A**. Les't check if this code do what we expect.

Run the *vector_add.c* code as follows

```bash
make run 
```

### Questions

* ¿How much time it takes to complete?

## Exercise 2

After having executed the *vector_add.c* code sequentially (Exercise 1), let's try to parallelize the code using the **for directive**.  

1. Add the OpenMP Libary, to enable the OpenMP features in the code.

```c
#include <omp.h>        /* OpenMP library */
```

2. Enclose this section of code in a **parallel region**.
	1. add the parallel for directive just before for(int j=0; j<N; ++j) ... ;

```c
for(int j=0; j<N; ++j) C[j] = A[j] * B[j] + A[j];
```

```c
#pragma omp parallel shared(A,B,C)
{
#pragma omp for
for(int j=0; j<N; ++j) C[j] = A[j] * B[j] + A[j] ;
}
```

* Run the code

```bash
make run 
```

The previous code, create the parallel región (**parallel** directive),  suggest arrays A, B, and C  will be shared among threads (**shared** clause). Finally suggets each thread will perform a different iteration of the loop (**for** directive). i.e, if for loop has 100 iterations and 2 threads were created, the first thread performs 0 - 49 iterations and the second one the 50 - 99 iterations.

### Questions

* ¿How much time did it take to finish? 
* ¿Did execution time improve? 
* ¿Why? 

**Ask monitor for answers**.