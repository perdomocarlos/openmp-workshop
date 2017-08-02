# Introduction to OpenMP - Workshop

The aim of this introductory workshop is to introduce the OpenMP library available in the GNU compiler to apply parallelism in our C/C++ applications. This workshop covers:

* Compiler optimization options -O1, -O2 and -O3.
* **parallel** directive
* **for** directive
* **sections** directive

## Methodology

This workshop is guided by a presentation. During the presentation is required to make changes to the code present in this repository. In addition, questions are suggested to discuss during the talk.

## Conclusions

* To get advange of the computational power available on parallel computer it is neccesary the parallel programming.

* Use of compiler flags is also an alternative to optimize the code runtime.

* Some applications only need compile optimizations to improve their runtime. As is the case in section 5.parallel_for - 2.activity (vectors addition).

* Other applications work well with compile optimizations and OpenMP parallelism, as is the case in section 3.solution (matrix multiplication).

## References

**[OpenMP 3.0 Summary](http://www.openmp.org/wp-content/uploads/OpenMP3.0-SummarySpec.pdf)**

[OpenMP - Lawrence Livermore National Laboratory](https://computing.llnl.gov/tutorials/openMP/)

[Compiler Options - Cornell University](https://cvw.cac.cornell.edu/codeopt/compilerOptions)

[Vectorization - Cornell University](https://cvw.cac.cornell.edu/vector/)

[Linux User's Manual Time](http://man7.org/linux/man-pages/man1/time.1.html) 
