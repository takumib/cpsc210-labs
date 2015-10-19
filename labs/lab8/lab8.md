## Objectives

Throughout the semester we've relied on several useful tools such as 
makefiles to ease the development of our programs. 

The objective of this lab is to better understand how some of these tools 
work. To do this we'll demonstrate how to write makefiles of your own and
debug your programs with a combination of print statements and conditional 
compilation. Lab will conclude with a brief tutorial/walkthrough on 
GDB (a dedicated debugging tool). 

This lab will be a guided one. This handout is merely intended to serve as 
summary/reference. 

### Part #1: writing a simple power function

This program consists of two pieces: 
* `my_math.h`: the header file containing the prototype of our `my_pow()` 
function.
* `my_math.c`: the iterative implementation of the function.

### Part #2: compiling with gcc

In this section we will be learning more about the compilation process and
how gcc works. We will be going over how to create object files and how to
link these together to create an executable.

Next, we will introduce the C preprocessor. These are a set of directives
that provide instructions for your C program at compile time. 

### Part #3: debugging with print statements

A perfectly valid technique for figuring out what (or where) your program 
is going wrong is by simply writing print statements in the code. This is 
especially useful for:

* Determining which 'path' execution went down. E.g.: which if-statement 
branch was taken?

```c
if (x < 3) {
	printf("GETS HERE: x must be < 3");
}
```

* Examining values of variables at a given place. Eg.:

```c
int x = 3;
...  // some other computation involving x
if (x < 3) {
	printf("GETS HERE: x must be < 3 specifically, x is: %d", x);
}
```
This way if your program isn't giving the answer you expect, you can 
'sanity check' yourself by making sure execution is even reaching the 
brunt of your logic.

#### Enhancement: condition compilation

The C preprocesser can also be used as a helpful debugging tool for turning
 on (or off) your debugging print statements. That is, rather simply erasing
or commenting out your debug statements when finished, you can simply wrap 
the call. 

The C preprocessor can be more helpful than just for excluding certain 
header files. We can also use the C preprocessor to debug our program by 
providing additional preprocessor commands inside of our program. We can use
this for simple testing, but not recommended as a final solution for handin.

### Part #4: compiling with make

As we have discussed in this lab, gcc is an important tool in compiling our
programs and can be used in several ways to generate an executable. It
becomes cumbersome, however, to compile each source file as our program
grows.

In this section we will discuss the `make` command as we have used in
previous labs. We will go over the basic syntax and create a simple
makefile for the example that we have been working with.

### Part #5: introduction to debugging with GDB

Using `printf()` statements and `#ifdef` blocks may not always be helpful
or provide the information we want. We can use a different debug tool known 
as The GNU Debugger, or GDB. We will use `gdb` with our given example to 
step through our program.

### Part #6: the tar command

The `tar` command is a UNIX command that we have been using to package our 
programs. 

In this section, we will discuss in more detail about the `tar` command and 
what the flags and options that are available.
