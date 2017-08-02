# Sequential Programming Approach

## Objectives

- [x] You will see how a sequential program actually runs on a computer.
- [x] And how many cores does it use.

## Introdution

Not too many years ago, single instructions were how we delivered work to computers. Since then, computers have become more and more powerful and more efficient at performing the work that makes running our programs possible. Today’s computers can do many things at one (or very efficiently make us believe so). When we package our work according to the traditional, serial notion of a program, we’re asking the computer to execute it close to the humble performance of a computer of yesterday. If all of our programs run like this, we’re very likely not using our computer to its fullest capabilities. -  *Nichols, Bradford, Dick Buttlar, and Jacqueline Farrell. Pthreads programming: A POSIX standard for better multiprocessing. " O'Reilly Media, Inc." 1996*

Today the sequential programming approach to which we are accustomed represents a barrier to the scientfic world by preventing scientist form carrying out detailed experiments of a given phenomenon due to the lack of computational power.

## Example 1

This code performs the matrix multiplication, given in a sequential approach. Let's perform the following experiment and answer the quetions below.

Run the following command in one **Terminal**

```bash
htop 
```

Then, run the *matrixmult.c* code in another *Terminal* as follows, and quickly check the **htop command Terminal**

```bash
make run 
```

## Questions

* How many cores this *matrixmult.c* takes to perform its calculation? 
* Is there paralelism?
* How long does the program take to finish?