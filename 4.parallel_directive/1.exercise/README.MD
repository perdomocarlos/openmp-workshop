# Parallel Programming With OpenMP (*parallel* directve)

OpenMP allows us to indicate which **regions of the code** we want to parallelize, annotating that sections with directives. the **parallel directive** create a team of threads where each thread execute the code enclosed by the directive.

## Homework

This is the *add code* this code prints sum of to number 50 and 60. Lest check if this code do what we expect.

### Run the *parallel.c* code as follows

```bash
make run 
```
¿What is the output of the program?

### Parallize *parallel.c* code

The objective of this exersice is to paralelize the following region of the *parallel.c* code.

```c
add();
```
Let's put into practice what is learned and parallelize the section of code given. If you need help, click [here](https://github.com/DonAurelio/Parallel-Programming/tree/master/2.OpenMP/parallel_directive)

* After you have parallelized the code, run it and describe what happened to it.

```bash
make run 
```

¿What is the output of the program? ¿Why?