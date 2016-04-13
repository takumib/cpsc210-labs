## Objectives

Today, we are going to look at another feature that `C++` provides to enhance code reuse and reduce repeating code with similar functionality. Template programming adds the ability to provide a single generic implementation of the code for numerous data types.

## Templates

As stated above, using templates with classes allows a programmer to provide a single implementation that applies to many data types. Let's look at the new syntax added to our Linked List example.

## `node.h`

```c++
template<typename T>
class Node {
public:
    Node();
    Node(T);
    ~Node();

    Node* getNext();
    T getItem();
    void setNext(Node*);

private:
    T item;
    Node* next;
};
```

As you can see above, we have not changed many lines of code and added a `template<typename T>` above the class declaration. This defines a new template for us to use where we create a generic type `T`. The term `T` can be thought of as a placeholder that will be replaced at a later point in time. We have also replaced `void*` with `T` where we will use this new type that we have introduced.

## `node.cpp`


```c++
template<typename T>
Node<T>::Node()
{
    next = NULL;
}

template<typename T>
Node<T>::Node(T itm)
{
    next = NULL;
    item = itm;
}

template<typename T>
Node<T>::~Node()
{
    // left blank intentionally.
}

template<typename T>
Node<T>* Node<T>::getNext()
{
    return next;
}

template<typename T>
T Node<T>::getItem()
{
    return item;
}

template<typename T>
void Node<T>::setNext(Node<T>* n)
{
    next = n;
}

template class Node<int>;
```

In the `node.cpp` file, we have now added `template<typename T>` to each method implementation. We have also added `<T>` to our class resolution operator `Node<T>`. This allows us to use the new type `T` in our implementation. Also, now note that we have added a new line to the bottom of the `cpp` file `template class Node<int>`. Since we are using generic types, `C++` does not now how to instantiate the template unless we explicitly instantiate the template. Here, we are saying that the template type should accept `int` types and further meaning that a `Node` will be able to store integers.

**Note**: The same idea follows with the `List` and `Iterator` classes. Examine these classes as well to get a better understanding of how this works.

## Task: Extend the `List`, `Iterator`, and `Node`

Your task is to add code to the `list.cpp`, `iterator.cpp`, and `node.cpp` so that it can handle `std::string` and `float` types. Then, in the `main.cpp` file, fill in the arrays `str` and `num2` with elements of your choosing. Once you have done this, create a new list and iterator for your arrays and add the items and iterate through the list just as in the example provided.

To compile and run your code type this:

```c++
make
./lab13
```

## Handin 

To hand in your project use the *tar cvf* command to turn in all of your `.cpp`, `.h` files and name the file `lab13_handin.tar`. Use the [handin](http://handin.cs.clemson.edu/courses) website to turn in your lab 12.

## Starter kit

