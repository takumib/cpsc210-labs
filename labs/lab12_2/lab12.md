## Objectives

Today we are going to learn about recursion by implementing a sequence of Fibonacci numbers and computing the power of a number.

## Iterative Functions

Throughout this entire semester, all of our computation has used the iterative. For example:

```c++
int sum(int n) {
  int result = 0;
  for(int i = 0; i < 10; i++) {
    result += i;
  }
}
```

The example above shows the computation of finding the sum of n numbers iteratively. In an iterative version, we step through each solution incrementally, normally using a loop structure such as a for or while loop. Next, we will discuss a recursive version of this.

## Recursive Functions

Another way that we could compute the example above is to use recursion. With recursion, we build up our solution by calling our function repeatedly until we have reached a **base case**:

```c++
int sum(int n) {
  if(n == 0) {
    return n; 
  }

  return n + sum(n-1);
}
```

in this example of our sum function the base case is the **if** condition. Let's look at what is happening in detail to see how this computes the sum from 0..n.

Initially, let's call sum(5). Since n > 0, we go to the return statement:

```c++
return 5 + sum(4)
```

Now, if we enter sum(4), we again skip the if condition and look at the return statement:

```c++
return 4 + sum(3)
```

This continues until we get to sum(0). Now, since n is 0, we simply return n. **Note: at this point we have not yet computed the result, we have been chaining function calls to `sum()`**. When we return from the `sum(0)` function we are in the return statement for `sum(1)` function.

```c++
return 1 + 0 // sum(0) returned 0
```

This continues until we have reached our initial call to `sum()`:

```c++
return 5 + 10 // return from sum(4)
```

## Task 1: Implement the `fib()` function:

The Fibonacci sequence is a famous sequence denoted by:

Fib[0] = 1
Fib[1] = 1
Fib[i] = Fib[i-1] + Fib[i-2] 

your task is to implement the `fib()` function to find the nth Fibonacci number based on the input:

```c++
int fib_iterative(int n);

int fib_recursive(int n);
```

**Note**: Try to think about what the base case(s) might be for the functions first and implement your functions around them.

## Task 2: Implement the `power()` function:

To increase your familiarity with recursive functions, you will now implement an iterative and recursive version of computing the number to a power:

```c++
int pow_iterative(int base, int pow);

int pow_recursive(int base, int pow);
```

## Testing
To test your program, call the functions that you have implemented in the `main.cpp` file. Print out your results for each function.

To compile and run your code type this:

```c++
g++ -Wall main.cpp fib.cpp pow.cpp -o lab12
./lab12
```

## Handin
Along with your `.cpp` and `.h` files submit a `results.txt` file with any similiarities and differences that you notice with the iterative and recursive versions of the Fibonacci and power functions that you have implemented. In addition to this, take note of execution timing and differences in the maximum value you can give for the Fibonacci functions. To observe this try to input increasingly larger values for your `fib_iterative()` and `fib_recursive()` functions until your programs stalls or produces a `Segmentation Fault`.

To hand in your project use the *tar cvf* command to turn in all of your `.cpp`, `.h` and `results.txt` files and name the file `lab12_handin.tar`. Use the [handin](http://handin.cs.clemson.edu/courses) website to turn in your lab 12.

## Starter kit
Download using [this](https://github.com/takumib/cpsc210-labs/releases/download/12.0/lab12.tar) link.
