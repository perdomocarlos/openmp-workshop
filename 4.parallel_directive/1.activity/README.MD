# OpenMP (Routines/Functions)

OpenMP provide to us a number of routines/funtions that allows to:

* Set the number of threads we want to create in a parallel region.

```c
omp_set_num_threads();
```

* Get the number of threads running in a parallel region.

```c
omp_get_num_threads();
```

* Get the ID of each thread in a parallel region.

```c
omp_get_thread_num();
```

* Know if a given región of code is being executed in parallel.

```c
omp_in_parallel();
```

* Among other features. More info please look at the References [here](http://www.openmp.org/wp-content/uploads/OpenMP3.0-SummarySpec.pdf)

## Exercise 1

The purpose of this exercise is to know how to modify the number of threads that will start in a **parallel región**, and know the identifier of each thread executed.

Complete the code *parallel.c* on this folder. The code is marked with number 1 to 5 that describes the sequence of steps that you must follow.

```c
#include <stdlib.h>     /* Standard Library: EXIT_SUCCESS */
#include <stdio.h>      /* Standard I/O Library: printf */
// 1.Import the omp.h funtion library here

int main(void){

    // 2.Call the routine omp_set_num_therads here

    // 3.Create a parallel región here
    // 4.Get thread id (within the parallel región)
    // 5.Print thread id (within the parallel región)

    return EXIT_SUCCESS;
};

```

Complete the code with the following steps (please replace the comments).

1. Import the omp.h funtion library

```c
#include <omp.h>        /* OpenMP library */
```

2. Call the routine omp_set_num_therads

```c
omp_set_num_therads(8);
```

3. Create a parallel region.

```c
#pragma omp parallel
{

}
```

4. Get thread id **within the parallel region**.

```c
int thread_id = omp_get_thread_num();
```

5. Print thread id **within the parallel region**.


```c
printf("Hi i'm thread %d\n",thread_id);
```

Run the code and answer the following questions.

```bash
make run 
```

### Questions

* ¿What is the output of the program? 
* ¿Why?


## Exercise 2

Modify the code inside the parallel region. Insted of each thread print its **id**, print if its **id** is even or odd.

Hints:
* Hint: a number N is even if 2 % N == 0, otherwise it is odd.
* You can use the **if statement**.
