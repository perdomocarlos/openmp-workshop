# Compiler Optimizations

The compiler tries to minimize certain attributes of a computer program in order to increase efficiency and performance. Compiler optimizations are applied through a sequence of optimization transformations and algorithms to produce another program semantically equivalent but optimized [1](https://en.wikipedia.org/wiki/Optimizing_compiler). In general these optimizations allow:

* Determine whether there is parallelism at the instruction level.
* Determine whether vectorization is possible.
* Reorder variables to recude Main Memory access.
* Delete the calculation of variables that do not affect the status of the program.

## Enable Optimizations

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

Change the variable **CFLAGS** in you *Makefile* as follows.

```basemake
CFLAGS = -std=gnu++11
```
Add the compiler optimzation -O1 and -fopt-info-all (to get a info about the compiler optimizations performed).

```basemake
CFLAGS = -std=gnu++11 -O1 -fopt-info-all
```
Run the application *vector_add.c* as follows, an check the excution time and program correctness.

```bash
make run 
```

Now do the same Exercise 2 but this time with the optimization flags -O2 and -O3. ¿What happend with the run time? ¿Which option works best? ¿Is the answere correct in each case?.

