## Objectives

Building on our shape hierarchy built up in previous labs, in this lab we'll conclude the 
semester by taking advantage of inheritance in C++ with the use of pointers.

## Task 1: Adding a `name` descriptor to your `Shape` classes

In this first task, we will be adding the ability to give the subclasses of `Shape` a `name`. 

```c++
class Shape {
public:
    Shape();
    Shape(double, double, const std::string);
    double getWidth();
    double getHeight();
    virtual const std::string& getDescription() = 0;
    virtual double computeArea() = 0;

    void setWidth(double);
    void setHeight(double);

protected:
    double width;
    double height;
};
```

As with the previous lab, we will be working with the `Shape` class. Note, however, that we have added a new virtual method called `getDescription()`, which returns a string. Again, just like with `computeArea()` this method is not implemented in shape and will need to be implemented in each subclass. For Task 1, you will be adding this method to each subclass (`rectangle.h/cpp`, `circle.h/cpp`, `rightTriangle.h/cpp`). The expected string to return will be based on the given shape. For example, a `Rectangle` should return `"Rectangle"`.

## Task 2: Finishing `main.cpp`

In this task, you will learning and understanding how to use `std::vector`. A `vector` in C++ can be thought of simply as a list or array. We have given you starter code that creates a vector of `Shape`'s. You will be adding new shapes to the vector by using the `push_back()` method. Add 10 new shapes to the vector. For example to add a new rectangle it will look something like this:

```c++
shapes.push_back(new Rectangle(3, 4));
```

In addition to this you will be adding code to print out your list of shapes. We will use a for-loop to facilitate this. The code below shows the outline of how your for-loop should look.

```c++
for(int i = 0; i < shapes.size(); i++) {
  // add code here
}
```

To access the elements inside of the vector, you will use the bracket operator `[]`. An example of this will be:

```c++
shapes[i]
```

**Note**: This will return a pointer to a shape. To access properties from the shape you will need to use the `->` operator. E.g:

```c++
shapes[i]->getDescription() // or
shapes[i]->computeArea()
```

Use the output provided to guide you in how your printout should look.

## Testing

To compile and test your code type this:

```c++
g++ -Wall main.cpp shape.cpp rectangle.cpp circle.cpp rightTriangle.cpp -o lab12
./lab12
```

## Handin

To hand in your project use the *tar czvf* command to turn in all of your `.cpp` and `.h` files and name the file `lab12_handin.tar.gz`. Use the [handin](http://handin.cs.clemson.edu/courses) website to turn in your lab 12.

## Starter kit
Download using [this](https://github.com/Welchd1/cpsc210-labs/releases/download/11.0/lab11.tar.gz) link.
