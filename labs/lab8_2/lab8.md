## Objectives

Earlier this semester we implemented a linked-list and iterator to pass through the list in C. This week, you will be implementing a C++ version a linked-list and iterator. Many of the concepts will be the same but will be restructured to fit into the C++ model and structure of programming.

## Task #1: implement linked list in C++

### The `Node` class

```c++
class Node {
public:
  Node();
  Node(void*);
  ~Node();

  Node* getNext();
  void* getItem();
  void setNext(Node*);

private:
  void* item;
  Node* next;
};
```

Above, the C++ version of the Node class is very similar to the `node` struct that we used in the linked-list lab earlier this semester. Now, we are able to associate methods along with member variables with a Node class.

Note: when we create a new node we can pass the item as a parameter to one of the specialized constructors. 


### The `List` class

```c++
class List {
public:
  List();
  ~List();

  void addFirst(void*);
  void reset();
  void* getCurItem();

private:
  Node* head;
  Node* current;
};
```
Again, the list is very similar to the list struct that we used in the C version of the linked-list.

## Task 2: implement iterator in C++

### The `Iterator` class

```c++
class Iterator {
public:
  Iterator();
  Iterator(List*);
  ~Iterator();

  void advance();
  bool hasNext();
  Node* get();

private:
  List* list;
  Node* current;
};
```

With the new `Iterator` class, we see one particular change to the at end function we saw in the C version of the iterator. We have changed this to the `hasNext()` method here and return a `bool` type. The `bool` type is a C++ type that can give a `true` or `false` value instead of using 0 or 1 that we used previously.

## Handin

When you are finished, tar up your `.c` and `.h` files:

`tar cvf lab8.tar [list your cpp and header files]`

submit your resulting lab8.tar using [handin](https://handin.cs.clemson.edu/courses/).
