# OpenMP *sections* directve

## Objectives

- [x] You will learn what the **sections** directive does.
- [x] You will learn how does the **sections** directive work.

## Introdution

OpenMP allows us to indicate which **regions of the code** we want to parallelize, annotating that sections with directives. the **parallel directive** creates a team of threads where each thread execute the code enclosed by the directive. However, each thread creates its own copy of the code enclosed by that directive, finally all threads will do the same thing. In some cases it is necessary each thread perform different tasks, for example:

* Each threads perform **different iterations of a for loop**.
* Or they can execute **different sections of code**.

Sections is another way to divide the work between threads. Unlike **for** directive, the **sections** directive parallelize teh execution of sections of code.

## Question

This code performs an array sum and multiplication. At a glance this code consists of three sections that can be carried out in parallel.

```c
/* Arrays sum */
for(int i = 0; i < N; ++i)
    C[i] = A[i] + B[i];

/* Arrays multiplication */
for(int i = 0; i < N; ++i)
    D[i] = A[i] * B[i];
```

¿Why the **Arrays content initialization** section (depicte below) can't be carried out in parallel with the **Arrays sum** and **Arrays multiplication** sections of code? **Ask the monitor for answer**

```c
/* Arrays content initialization */
for(int i=0; i<N; ++i){
    A[i] = 1.5;
    B[i] = 22.35;
    B[i] = C[i] = 0.0;
}
```

## Exercise 1

Given the structure of the directive **sections**:

```c
 #pragma omp parallel               /* parallel region initialization*/ 
 {                                  /* Start of parallel region */ 

   #pragma omp sections nowait      /* sections initialization */
   {                                /* Start of sections region */

    #pragma omp section
    {
        //Some code ...
    }

    #pragma omp section
    {
        //Other code ...
    }

   }                                /* End of sections region */

}                                   /* End of parallel region */

```

* Import the OpenMP funtion header.
* Create the **parallel regón**
* Apply the **sections** directive to parallelize those sections of code that are parallelizable.
* Print the thread id on each section of code using the funtion **omp_get_thread_num();**

When you have completed the code:

* Add the compilation flag **-fopenmp** to the CFLAGS variable in your *Makefile*. To enable OpenMP in the code.

```basemake
CFLAGS = -std=gnu++11 -O3 -fopenmp
```

* Run the code several times and check which thread runs each section of code.

```bash
make run 
```