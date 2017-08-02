# OpenMP (Clauses)

## Objectives

- [x] You will learn what is a clause in OpenMP.
- [x] You will learn which clauses the **parallel** directive supports.
- [x] You will learn to use the clauses **private** and **firstprivate**.
- [x] You will learn what the clauses **private** and **firstprivate** do.

## Introdution

Clauses are words that accompany a directive. They allow to modify **the access to the data within the parallel region** and the behavior of the parallel region. Each directive supports a particular set of clauses.

For example, the parallel directive support the following clauses

* if
* **private**
* shared
* default
* **firstprivate**
* reduction
* copyin
* num_threads

Then the parallel directive might look like this

```c
#pragma omp parallel if(...)
```

or


```c
#pragma omp parallel private(...)
```

or 


```c
#pragma omp parallel if(...) private(...) shared(...) .....
```

For this introductory workshop do not care about all this clauses, in the following activities we will discover what **private** and **fisrtprivate** really do over the data in the *parallel.c* code. A better explanation of the other directives can be found [here](https://computing.llnl.gov/tutorials/openMP/#Clauses).

## Exercise 1

* Open the file *parallel.c* and try to figure out what the code does.

* Add the compilation flag **-fopenmp** to the CFLAGS variable in your *Makefile*. To enable OpenMP in the code.

```basemake
CFLAGS = -std=gnu++11 -O3 -fopenmp
```
* Then run the code and check the code is working as you expect. **Hint: run the code many times**. 

```bash
make run 
```

### Questions

* Is the answer correct?
* Does the answer change every run?
* Should the answer change?

## Exercise 2

Add the clause **private** to the parallel región as follows

```c
#pragma omp parallel private(private_variable)

```

Run the code many times and check the code is working as you expect. **Hint: run the code many times**. 

```bash
make run 
```

### Questions

* Is the answer correct?
* Does the answer change every run?
* Should the answer change?
* What does the **private** clause do?

## Exercise 3

Change the clause **private** with the clause **firstprivate** in the parallel región as follows

```c
#pragma omp parallel firstprivate(private_variable)

```

Run the code many times and check the code is working as you expect. **Hint: run the code many times**. 

```bash
make run 
```

### Questions

* Is the answer correct?
* Does the answer change every run?
* Should the answer change?
* What does the **firstprivate** clause do?