## Objectives

The purpose of this lab is to introduce the notion of class inheritance. Similar to the 
transition from procedural to object oriented programming we made earlier in the
semester, understanding *when* and *how* to apply inheritance will 
(hopefully) not only influence the way you think about and structure your classes, but 
will also make them more modular and thus easier to maintain in the long run.

With this in mind, the objectives for this lab are as follows:

* understand the notion of a *baseclass* and *subclass*
* understand how to think about and partition methods/functionality between a baseclass 
and an arbitrary number of subclasses
* understand the **protected** and **virtual** keywords -- and how to use them properly

## Inheritance 101

To demonstrate and introduce the notion of inheritance, we'll start by defining a simple
`Shape` class.

```c++
//Shape.h
class Shape {
public:
    Shape();
    Shape(double, double);
    double getWidth();			//implemented in Shape.cpp
    double getHeight();			//implemented in Shape.cpp
    virtual double computeArea() = 0; //implemented in ??

    void setWidth(double);		//implemented in Shape.cpp
    void setHeight(double);		//implemented in Shape.cpp

protected:
    double width;
    double height;
};
```

As specified in the header above, our `Shape`s are (unsurprisingly) defined in terms of
a `width`, `height`, and associated methods for accessing and modifying these variables.

There a several of things worth noting here:

1. **generality:** `Shape` at this point doesn't seem like a terribly descriptive/useful
class.. For instance, what kind of shape are we talking about? Is it a triangle, a 
square, etc? In short, the generality we're seeing (in the name, fields, and methods) is 
indeed an intentional design choice, and we'll soon see how we can 'extend' (or 'refine') 
this general notion of a `Shape` we've laid out to more *specific* shapes with minimal 
code duplication.

2. **virtual methods:** Perhaps the most exotic/new thing about the `Shape` header is 
the inclusion of the `virtual` modifier preceding the `computeArea()` method. 
You can really think of this keyword as a synonym for `abstract`, and it simply 
means that this is a method we are **not** obligated to implement in `Shape.cpp`;
instead, its implementation is left to one of `Shape`s subclasses.

3. **protected members:** Instead of declaring `width` and `height` private, we use a 
different keyword, `protected` to ensure that any subclasses extending `Shape` will be
able to see/access these variables without needing accessor methods such as 
`getWidth()` or `getHeight()`.

### Subclassing `Shape`

Due to the inclusion of the (`virtual`) method,
```c++
virtual double computeArea() = 0
```

you can think of the entire `Shape` class as *abstract* class (a base class) -- meaning we 
can't instantiate it since `computeArea()` will not have an implementation in the 
corresponding `.cpp` file (remember, this is what the `virtual` part does). This means 
that it's time to write a *subclass* of shape -- so let's do a `Rectangle` first:

```c++
//Rectangle.h
class Rectangle : public Shape {
public:
    Rectangle();
    Rectangle(double, double);
    double computeArea();
};
```
you'll notice that instead of just saying 
```c++
class Rectanle { ... };
```
as we would normally do, we instead use the following syntax:
```C++
class Rectangle : public Shape { ... };
```
which indicates that our new class, `Rectangle` *extends* the general, abstract `Shape` 
we defined earlier.

Also of note is the fact that we've dropped the `virtual` modifier from the 
`computeArea()` method prototype, meaning we are now obligated to implement the method as 
part of `Rectangle.cpp`:

```c++
//Rectangle.cpp
Rectangle::Rectangle() :
    Shape()
{}
​
Rectangle::Rectangle(double w, double h) :
    Shape(w, h)
{}
​
double Rectangle::computeArea()
{
    return width * height;
}
```

## So what does all this buy us?

One of the first things that should strike you when looking at `Rectangle.cpp` is how 
little work we had to do in extending `Shape`. The main reason it's so short is the fact 
that most methods such as `getWidth()`, `setWidth()`, etc have already been implemented in
the general `Shape.cpp` context. And, by virtue of the fact that `Rectangle` extends 
`Shape`, such implementations implicitly apply to all `Rectangle`s as well.

Therefore, properties that apply to all conceivable `Shape`s are well suited 
to being declared in `Shape.h` (and perhaps even implemented in `Shape.cpp` if it's
abstract/general enough of a property). For instance, the fact that every conceivable 
`Shape` has some area associated with it, guided our decision to include it in the 
`Shape` header.

In summary, the fact that most functionality lives in `Shape` and only needed to be written
once (and is able to reused by all subclasses) helps make our design and code more modular,
and overall much more maintainable.

## Task: implement a `RightTriangle` subclass

As the section title states, your job for this lab is to extend `Shape` with a 
`RightTriangle` subclass and implement the `computeArea()` method for this shape. To 
help get started, you should refer to full sourcecode for the `Rectangle` subclass 
included in the starter kit.

## Testing

To compile and test your code type this:

```c++
g++ main.cpp person.cpp -o lab9
```

## Handin

To hand in your project use the *tar czvf* command to turn in all of your `.cpp` and `.h` files and name the file `lab9_handin.tar.gz`. Use the [handin](http://handin.cs.clemson.edu/courses) website to turn in your lab 9.

## Starter kit
Dowload using [this](https://github.com/Welchd1/cpsc210-labs/releases/download/9.0/lab9.tar.gz) link.
