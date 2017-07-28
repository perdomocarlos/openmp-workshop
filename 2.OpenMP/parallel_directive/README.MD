# Parallel Programming With OpenMP (*parallel* directve)

OpenMP allows us to indicate which **regions of the code** we want to parallelize, annotating that section with directives. the **parallel directive** create a team of threads where each thread execute the code enclosed by the directive.

## Exercise 1
This is the *hello world code* this code prints the word "Hello World !" by terminal. Lest check if this code do what we expect.

### Run the *parallel.c* code as follows

```bash
make run 
```
¿How many "Hello World !" were printed in the terminal?

## Exercise 2

The objective of this exersice is to paralelize the following region of the following code.

```c
printf("Hello World !");
```
To achieve this we must perform the following steps.

* Add the OpenMP Libary, to enable the OpenMP features in the code.

```c
#include <stdlib.h>     /* Standard Library: EXIT_SUCCESS */
#include <stdio.h>      /* Standard I/O Library: printf */
```

```c
#include <stdlib.h>     /* Standard Library: EXIT_SUCCESS */
#include <stdio.h>      /* Standard I/O Library: printf */
#include <omp.h>        /* OpenMP library */
```

* Replace this code

```c
printf("Hello World !\n");
```

* for that one

```c
#pragma omp parallel
{ // Start parallel region
printf("Hello World !\n");
} // End parallel region
return EXIT_SUCCESS;
```
* Run the code

```bash
make run 
```

¿How many "Hello World !" were printed in the terminal?


