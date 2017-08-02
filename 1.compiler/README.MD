# GCC/G++ Compiler Optimizations

## Objectives

- [x] You will learn what the compiler does.
- [x] How to use the compiler to optimize the code.

## Introdution

The compiler tries to minimize certain attributes of a computer program in order to increase efficiency and performance. Compiler optimizations are applied through a sequence of optimization transformations and algorithms to produce another program semantically equivalent but optimized [1](https://en.wikipedia.org/wiki/Optimizing_compiler). In general these optimizations allow:

* Determine whether there is parallelism at the instruction level.
* Determine whether vectorization is possible.
* Reorder variables to recude Main Memory accesses.
* Delete the calculation of variables that do not affect the status of the program.

### Enable Optimizations

The following flags are really shorthand; they combine a number of specific techniques into a single option.

* -O0 for fast compilation without optimization (default).
* -O1 for limited optimization that does not increase code size; not inlining.
* -O2 for moderate optimization including vectorization.
* -O3 for aggressive optimization, resulting in longer compile time, more trading of space for speed. **This may change code semantics and, occasionally, results**. It also enables the optimizations present in -O2.

More details can be given [here](https://cvw.cac.cornell.edu/codeopt/compilerOptions)

## Exercise 1

Run the application *vector_add.c*.

```bash
make run 
```
you would get something like:

|N|Estado|T.Real(sg)|T.Usuario(sg)|T.Kernel(sg)|%CPU| Memoria(KB)|
|---|---|---|---|---|---|---|
|100000000|**Ok**|**1.58**|1.01|0.56|99%|2344564|

- N, is the size of the vector in the code.
- Estado, indicated whether the program output is correct.
- T. Real(sg), is the time taken by the program to finish. T.Real = T.Usuario + T.Kernel
- %CPU, the percentage of CPU used by the program
- Memoria (KB), amount of memory used by the program in KiloBytes.

For this example we will focus on the execution time and the correctness of the output.

## Exercise 2

The compilation and execution of the program is controlled by the file *Makefile*. Edit the *Makefile* and change the variable **CFLAGS** as follows.

Add the compiler optimzation -O1 and -fopt-info-all (to get a feedback about the compiler optimizations performed).

```basemake
CFLAGS = -std=gnu++11 -O1 -fopt-info-all
```
Run the application *vector_add.c* as follows, and check the excution time and program correctness.

```bash
make run 
```

## Exersice 3

Now do the same Exercise 2 but this time with the optimization flags -O2 and -O3. 


## Questions

* What happend with the execution time? 
* Which option works best? 
* Is the answer correct in each case?.
* Check the file *Optimizations.txt* an look at all the work the compiler does 
