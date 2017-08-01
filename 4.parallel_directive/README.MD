# Parallel Programming With OpenMP (*parallel* directve)

OpenMP allows us to indicate which **regions of the code** we want to parallelize, annotating that sections with directives. the **parallel directive** creates a team of threads, each thread creates a copy of the code enclosed by the directive. Finally that code is executed in parallel by the team of threads.

## Example: 

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

And we want to parallelize this code


```c

int b = 4 + 5;
printf("\nResult %d",b);

```

We need first import the OpenMP function header **omp.h**

```c
#include <stdlib.h>     /* Standard Library: EXIT_SUCCESS */
#include <stdio.h>      /* Standard I/O Library: printf */
#include <omp.h>        /* OpenMP library */

int main(){

    int b = 4 + 5;
    printf("\nResult %d",b);

    return EXIT_SUCCESS;
}
```

Then, enclose the section of code we need to parallelize with the **parallel directive**

```c
#include <stdlib.h>     /* Standard Library: EXIT_SUCCESS */
#include <stdio.h>      /* Standard I/O Library: printf */
#include <omp.h>        /* OpenMP library */

int main(){

    #pragma omp parallel
    {
        int b = 4 + 5;
        printf("\nResult %d",b);
    }

    return EXIT_SUCCESS;
}
```

## Exercise 1

This is the *hello world code* this code prints the word "Hello World !" by terminal. Les't check if this code do what we expect.

Run the *parallel.c* code as follows

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

Then run Run the *parallel.c* code and answer the questions

```bash
make run 
```

### Questions

* ¿How many "Hello World !" were printed in the terminal? 
* ¿Why?