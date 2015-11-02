## Objectives

To gain more experience working with classes and objects in C++, in this lab you will 
re-architect the vector math library developed in C earlier this semester, only this 
time taking advantage of the encapsulation and abstraction that classes allow for.

In addition to gaining more experience working with and implementing objects, this lab 
will also introduce you to a powerful C++ feature referred to as *operator overloading*.

## Representing `Vector`s in C++

Rather than utilizing structs to represent a vector as we did last time, we instead
write a `Vector` class to encapsulate all the properties we'd expect of a vector:

```c++
class Vector {
public:
	Vector();
	Vector(double, double, double);
	~Vector();
	
	Vector operator+(const Vector&);
	Vector operator-(const Vector&);
	Vector& operator+=(const Vector&);
    Vector& operator-=(const Vector&);
    Vector operator*(double);
​
    double magnitude();
    Vector normalize();
    double dot(const Vector&);
​
    double getX();
    double getY();
​
private:
    double x;
    double y;
};
```
As is common with objects, we partition our class into two sections: `public` and 
`private`. In the `public` section we declare everything that we intend the outside world 
to see including constructors for building new `Vector` instances as well as operations 
on `Vector`s such as `+`, `-`, `*`, `magnitude`, etc. 

The `private` section in this case houses `x` and `y`, which is what we use internally to
represent a `Vector` -- and hence, should not be visible to clients in the outside world. 
You'll note however that we *do* allow clients to access `x` and `y` *indirectly* through 
the public methods `getX()` and `getY()`.

### Operator overloading

To make performing arithmetic computations involving `Vector` objects a little easier and 
more natural looking, we'll *overload* the ordinary infix operators such `+`, `-`, `*`  
(which normally only work on `int`s, `double`s, etc) to also work for our `Vector` 
objects. 

|*a note on operators|
|-------------|
|*In case you're unaware, symbols such as '+', '-', '\', etc are commonly referred to as binary (infix) operators. Infix means the name sits in the middle of the the two (left and right side) arguments.*|


This will allow us to do stuff like the following:
```c++
Vector v1(3, 6);
Vector v2(5, 1);

std::cout << "sum is: " << v1 + v2 << std::endl;
```

##Task: implement `vector.h`

Your job is to write the implementation of the `Vector` class outlined in the previous
section.

## Testing

To compile and test your code type this:

```c++
g++ main.cpp person.cpp -o lab9
```

## Handin

Use the *tar czvf* command to package up all of your `.cpp` and `.h` files and name the 
resulting archive `lab10_handin.tar.gz`. As usual, use [handin](http://handin.cs.clemson.edu/courses) 
website to upload and submit your solution to the lab.

*Note: It's your responsibility to compress the directory and to make sure that the 
command used was correct. We've received a number of labs so far that have been 
incorrectly tarred -- meaning one or more files were unable to be decompressed 
or just came out garbled and un-readable. So check before you submit!*

## Starter kit
Dowload using [this](https://github.com/Welchd1/cpsc210-labs/releases/download/9.0/lab9.tar.gz) link.


