# OpenMP *for* directve

## Objectives

- [x] You will learn how to use the **for** directive to process a vector in parallel.
- [x] You will apply compilation flags to optimize the code
- [x] You will learn when it is convenient to parallelize with **OpenMP** or use the **Compiler Optimization flags**.

## Introdution

Processing large vectors of data is one of the most common tasks in scientific computing. This code is the famous sum of matrices, although not being optimized, it takes few seconds to finish its execution. Let's try to optimize this code to see how far we get.

## Exercise 1

Run the *vector_add.c* code as follows

```bash
make run 
```

### Questions

* How much time it takes to complete?

## Exercise 2

Optimize the code with the GCC/G++ compiler flag -O3. Edith the *Makefile*, add the -O3 to the **CFLAGS** variable.

```basemake
CFLAGS = -std=gnu++11 -O3
```

Run the *vector_add.c* code as follows

```bash
make run 
```
### Questions

* How much time it takes to complete?
* Does the execution time improve?

## Exercise 2

After having executed the *vector_add.c* code sequentially (Exercise 1 and 2), let's try to parallelize the code using the **for** directive.  

1. Add the OpenMP Libary, to enable the OpenMP features in the code.

```c
#include <omp.h>        /* OpenMP funtions header */
```

2. Enclose this section of code in a **parallel region**.

```c
for(int j=0; j<N; ++j) C[j] = A[j] * B[j] + A[j];
```

3. Add the parallel for directive just before **for(int j=0; j<N; ++j)** ... ;

```c
#pragma omp parallel shared(A,B,C)
{
#pragma omp for
for(int j=0; j<N; ++j) C[j] = A[j] * B[j] + A[j] ;
}
```

Add the compilation flag **-fopenmp** to the CFLAGS variable in your *Makefile*. To enable OpenMP in the code.

```basemake
CFLAGS = -std=gnu++11 -O3 -fopenmp
```

* Run the code

```bash
make run 
```

The previous code (3 step), create the parallel región (**parallel** directive),  suggest arrays A, B, and C  will be shared among threads (**shared** clause). Finally suggets each thread will perform a different iteration of the loop (**for** directive). i.e, if for loop has 100 iterations and 2 threads were created, the first thread performs 0 - 49 iterations and the second one the 50 - 99 iterations.

### Questions

* How much time did it take to finish? 
* Did execution time improve?
* Why? **Ask monitor for answers**.



## Exercise 3

Remove the **-O3** optimization flag of the variable **CFLAGS** in your **Makefile**. 

```basemake
CFLAGS = -std=gnu++11 -fopenmp
```

### Questions
* Which optimization works better?
    * The **-O3** Compiler flag only.
    * The **-O3** compiler flag and the **for** directive applied together.
    * The **for** directive only.
    * Why? **Ask monitor for answers**.