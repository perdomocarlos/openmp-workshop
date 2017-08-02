# OpenMP *for directve*

The parallel directive allows us to parallelize one or more sections of code, however the threads created with this directive carry out the same tasks (or execute the same code). In practice, the idea of OpenMP seeks to solve a bing problem by dividing it into independent parts, which can be carried out in parallel by several threads.

In some cases it is necessary each thread perform different tasks, for example:

* Each threads perform **different iterations of a for loop**.
* Or they can execute **different sections of code**.

Through the following exercise we will see what the **for** directive does and how it allows us to process the data in a vector in parallel.

## Exercise 1

Complete the code *parallel.c* on this folder. The code is marked with number 1 to 5 that describes the sequence of steps that you must follow.

```c
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
```

Complete the code with the following steps (please replace the comments).

1. Import the omp.h funtion library

```c
#include <omp.h>        /* OpenMP library */
```

2. Parallize this section of code with a **parallel region**

```c
for(int i=0; i<N; ++i){
    // 3.Get thread id (within for)
    // 4.Print thread id and i (within for)
}
```

3. Get thread id (**within for statement**)

```c
int thread_id = omp_get_thread_num();
```

4. Print thread id and i (**within for statement**)

```c
printf("Hi i'm thread %d, i have the %d iteration of the loop",thread_id,i);

```

Run the code and answer the following questions.

```bash
make run 
```

### Questions

* ¿How many threads were executed?
* ¿How many **for** cycle iterations each thread executed?
* Run the code many times ¿What changes do you see in the program output?