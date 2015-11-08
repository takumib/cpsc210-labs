## Objectives

The purpose of this lab is to introduce the notion of inheritance. Similar to the 
transition to objects made earlier in the semester, understanding 
when and how to apply inheritance in your programs and design will (hopefully) not only
change the way you think about and structure your programs, but also help make your code
more modular and and easier to understand and maintain in the long run.

In summary, the hope with this lab is to get you to start developing some of the 
following skills:

* understand the notion of a *base class* and *sub class*
* understand how to partition functionality between a shared base class and its 
subclasses
* understand the **protected** and **virtual** keywords

## Inheritance 101

To demonstrate and introduce the notion of inheritance, we'll start by defining a simple
`Shape` class.

```c++
class Shape {
public:
    Shape();
    Shape(double, double);
    double getWidth();
    double getHeight();
    virtual double computeArea() = 0;

    void setWidth(double);
    void setHeight(double);

protected:
    double width;
    double height;
};
```

As specified in the header above, our `Shape`s are (unsurprisingly) defined by a
`width`, `height`, and associated methods for accessing and modifying these variables.

### Virtual methods
The only part of the above header that should look different at this point is the 
inclusion of the `virtual` keyword preceding the `computeArea()` method.


## Do right-triangle

## Testing

To compile and test your code type this:

```c++
g++ main.cpp person.cpp -o lab9
```

## Handin

To hand in your project use the *tar czvf* command to turn in all of your `.cpp` and `.h` files and name the file `lab9_handin.tar.gz`. Use the [handin](http://handin.cs.clemson.edu/courses) website to turn in your lab 9.

## Starter kit
Dowload using [this](https://github.com/Welchd1/cpsc210-labs/releases/download/9.0/lab9.tar.gz) link.
