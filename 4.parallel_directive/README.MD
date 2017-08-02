# OpenMP *parallel* directve

## Objectives

- [x] You will learn how to parallelize a sequential code with parallel threads.
- [x] You will learn what the **parallel** directive does.

## Introdution

OpenMP allows us to indicate which **regions of the code** we want to parallelize, annotating that sections with directives. The **parallel** directive creates a team of threads. Each thread creates a copy of the code enclosed by that directive. Finally that code is executed in parallel by the team of threads.

## How to parallelize a sequential code?

If we have the following code

```c
#include <stdlib.h>     /* Standard Library: EXIT_SUCCESS */
#include <stdio.h>      /* Standard I/O Library: printf */

int main(){

    int b = 4 + 5;
    printf("\nResult %d",b);

    return EXIT_SUCCESS;
}
```

And we want to parallelize this section


```c

int b = 4 + 5;
printf("\nResult %d",b);

```

We need, first import the OpenMP functions header **omp.h**

```c
#include <stdlib.h>     /* Standard Library: EXIT_SUCCESS */
#include <stdio.h>      /* Standard I/O Library: printf */
#include <omp.h>        /* OpenMP funtions header */

int main(){

    int b = 4 + 5;
    printf("\nResult %d",b);

    return EXIT_SUCCESS;
}
```

Then, enclose the section of code we need to parallelize with the **parallel** directive

```c
#include <stdlib.h>     /* Standard Library: EXIT_SUCCESS */
#include <stdio.h>      /* Standard I/O Library: printf */
#include <omp.h>        /* OpenMP funtions header */

int main(){

    #pragma omp parallel
    {
        int b = 4 + 5;
        printf("\nResult %d",b);
    }

    return EXIT_SUCCESS;
}
```

Finally the work is done !!, you have parallelized the code.

## Exercise 1

This is the *hello world code* this code prints the word "Hello World !" by terminal. Les't check if this code do what we expect.

Run the *parallel.c* code as follows and answer the questiosn below.

```bash
make run 
```
### Questions 

* ¿How many "Hello World !" were printed in the terminal?

## Exercise 2

Paralelize the following region of the *parallel.c* code.

```c
printf("Hello World !");
```

Add the compilation flag **-fopenmp** to the CFLAGS variable in your *Makefile*. To enable OpenMP in the code.

```basemake
CFLAGS = -std=gnu++11 -O3 -fopenmp
```

Then run Run the *parallel.c* code and answer the questions.

```bash
make run 
```

### Questions

* How many "Hello World !" were printed in the terminal? 
* Why?
* Are all threads running the same code?


Do the activities 1 and 2 of this section to learn more about the **parallel** directive.