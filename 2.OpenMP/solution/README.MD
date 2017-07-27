# Parallel Programming Approach

Parallel computing allow to divide a great tasks in subtasks that in consequense can be performed in parallel.

## Example
This code is the matrix multiplication code, given in a sequential approach. The objective of this example is to parallelize it with OpenMP as follows and anwere the quetions ¿How many cores this *matrixmult.c* takes to perform its calculation? ¿Is there paralelism?.

### Edit the file *matrixmult.c*

* Add the OpenMP Libary 

```c
#include <stdio.h>      /* Standard I/O Library: printf */
#include <stdlib.h>     /* Standard Library: malloc, calloc, free, ralloc */
#include <string.h>     /* String funtions: strcpy*/
```

```c
#include <stdio.h>      /* Standard I/O Library: printf */
#include <stdlib.h>     /* Standard Library: malloc, calloc, free, ralloc */
#include <string.h>     /* String funtions: strcpy*/
#include <omp.h>		/* OpenMP library */
```

* Replace this code

```c
/* C = A x B */
for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        for(int k=0;k<N;k++){
            C[i][j] += A[i][k] * B[k][j];
        }
    }
}
```

* for that one

```c
/* C = A x B */
#pragma omp parallel shared(A,B,C)
{
	#pragma omp for 
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
} 
```

Run the following command in one **Terminal**

```bash
htop 
```

Then, run the *matrixmult.c* code in another *Terminal* as follows, and quickly check the **htop command Terminal**

```bash
make run 
```
