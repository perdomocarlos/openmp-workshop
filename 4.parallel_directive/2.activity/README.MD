# OpenMP parallel directive (Clauses)

An OpenMP directve follows the format depicted below. 

```c
#pragma omp directive-name [clause,...]
```

Up to this point we know how the **parallel directive** works, however, this directive has a set of clauses that allows to modify the behavior of the data in the parallel region. The parallel directive suppor the following clauses.

* if
* **private**
* shared
* default
* **firstprivate**
* reduction
* copyin

Do not care about all this directives, for the following activities we will discover what **private** and **fisrtprivate** really do over the data in the *parallel.c* code. A better explanation of the other directives can be found [here](https://computing.llnl.gov/tutorials/openMP/#Clauses).

## Actvity 1

* Open the file *parallel.c* and try to figure out what the code does. 
* Then run the code and check the code is working as you expect. **Hint: run the code many times**. 

```bash
make run 
```

### Questions

* ¿Is the answer correct?
* ¿Does the answer change every run?
* ¿Should the answer change?

## Activity 2

Add the clause **private** to the parallel región as follows

```c
#pragma omp parallel private(private_variable)

```

Run the code many times and check the code is working as you expect. **Hint: run the code many times**. 

```bash
make run 
```

### Questions

* ¿Is the answer correct?
* ¿Does the answer change every run?
* ¿Should the answer change?

## Activity 3

Change the clause **private** with the clause **firstprivate** in the parallel región as follows

```c
#pragma omp parallel firstprivate(private_variable)

```

Run the code many times and check the code is working as you expect. **Hint: run the code many times**. 

```bash
make run 
```

### Questions

* ¿Is the answer correct?
* ¿Does the answer change every run?
* ¿Should the answer change?