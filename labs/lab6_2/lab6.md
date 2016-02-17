## Objectives

In this lab you will be implementing a **linked list** and an associated **iterator**.

In working through the implementation of these separate structures, you'll gain
not only more experience in working with pointers, but will also be exposed to a common
design strategy that separates implementation of a core data structure 
(in our case, a linked list) from the logic driving its traversal. 

In summary, by the end of this lab you will have at your disposal a robust, efficient 
linked list and iterator for use in future labs -- not to mention 
experience in writing increasingly complex functions.

As always, you can either download your complete lab 6 starter kit on the 
[releases page](https://github.com/Welchd1/cpsc210-labs/releases/download/6.0/lab6.tar.gz) or peruse the default starter files [here]
(https://github.com/Welchd1/cpsc210-labs/tree/master/labs/lab6/src) on GitHub. (here's the command for decompressing the tar file: `tar xvzf lab6.tar.gz`)

## Background: void pointers and type casting

A *void pointer* can be used to hold the address of an arbitrary data type. By way of 
example, consider the following code:

```c
int x;
float y;

// declare a struct capable of being referenced as s_type 
(this is what the 'typedef' part does)
typedef struct s {  
   int f1;
   int f2;
} s_type;

s_type s1, *sp;
void *p;
```

The void pointer `p` can be set to point to any of the objects above, E.g:. `p = &x`, 
`p = &y`, `p = &s1`, etc. You can also write `p = sp` or `sp = p` without any problem 
(since both `p` and `sp` are of type pointer: they just happen to be pointing to 
different types of objects). However, we run into trouble when I attempt to use `p` to 
access a field. For example, if I write `x = *p` I get the following (helpful?) message 
from the compiler that reads something like:
```
warning: dereferencing 'void *' pointer ... error: void value not ignored as it ought to be
```

There are two ways to avoid this:

1. **type casting**: I can tell the compiler the type of the data that `p` is pointing to:
    ```c
    x = *(int *)p;
    ```
The code above is telling the compiler to treat `p` as a pointer to something of type 
`int`, and then copy the integer contents it is pointing to into `x`.

2.  **extra pointers**: The alternative is to simply define another pointer:

    ```c
    int *q;
    ...
    q = p;
    x = *q;
    ```
Personally I find that defining a few extra pointers results in more readable code, and 
will likely be less error-prone (but either approach gets the job done -- 
so it's up to you).

### An additional example

Here's another example using the above structure. Assume we want to set the `f2` field 
in `s1` to an integer (say, 6), and suppose that `p` points to `s1`. At this point, based 
on the two approaches discussed above, we could write either:
```c
((stype *)p)->f1 = 6;   // approach #1
```
or alteratively
```c
sp = p;                // approach #2
sp->f1 = 6;
```

##Task: list implementation

In class [you've already seen]
(http://people.cs.clemson.edu/~rlowe/cs2100/notes/linked-list.pdf) the implementation of 
a relatively simple linked-list data structure. For this lab you're going to alter what 
was discussed in two key respects, **so pay attention**:

* objects of *arbitrary* type can now be stored in the list:
  meaning when you're done, your list should be able to store `float`s, `char`s, or even 
  the `vector_t` objects you've all come to know and love from previous labs, etc.
* new additions to a list, rather than being appended to the **tail** (end), should 
instead be added to the **head** (front) of the list.

### Key structures
In [list.h](https://github.com/Welchd1/cpsc210-labs/blob/master/labs/lab5/src/list.h) we 
provide two structures that give us everything we need to implement the desired list data 
structure. 

#### `node_t`
The first of these is `node_t`:
```c
typedef struct node {
   struct node *next;	// pointer to the next node
   void *data;			// the data pointed-to-by/stored at this node
} node_t;
```
Think of a `node_t` as one link in a chain of *n* nodes that form the backbone of
our list. This particular struct consists of two fields: 
* a `next` pointer that points to the next `node_t` in the 'chain' if there is indeed 
such a node; `null` otherwise
* a void pointer called `data` that points to an arbitrarily-typed object
(could be a number, string, vector, tree, etc)

Given our definition of `node_t`, pictorially, a list of integers such as `[5, 2, 7]` 
would internally look something like:

![nodes](https://github.com/Welchd1/cpsc210-labs/blob/master/labs/lab5/figures/node_diag1.png)

#### `list_t`

The second, and final piece of our implementation puzzle is `list_t`:
```c
typedef struct list {
   node_t *current;		// current list position 
   node_t *head;		// the head (starting node) of our list
} list_t;
```

You can think of `list_t` as the manager, or controller, of an entire list. The `list_t`
controller keeps track of two important pieces of information:
* a `current` position pointer that points to *one* particular `node_t`
within the list -- which one? -- we'll get to that when we look at the functions.
* a `head` pointer which always points to the `node_t` at the start of the list (e.g.: the **head** of the list);
if the list is empty, `head` points to `null`.

So in terms of our previous `[5, 2, 7]` example, `list_t` adds the following to 
our illustration:

![list manager](https://github.com/Welchd1/cpsc210-labs/blob/master/labs/lab5/figures/node_diag2.png)

## Tasks 

This lab is separated into two broad tasks: for the first you'll need to implement 
the linked list defined in `list.h`, after this, you'll implement an iterator for 
said list defined in `iterator.h`, capable of accessing and traversing over the elements. 
All of your work will be done in either `list.c` or `iterator.c`. All testing code will be provided.

## Task #1: implement a linked list

The structures we'll use in the implementation of our doubly linked list are 
very similar to those we would use for a singly linked list.

### `node` type
Here's our basic `node` structure:

```c
typedef struct node_t {
	struct node_t *next;
	struct node_t *prev;
	void *data;
} node;
```

Each `node` in our list maintains a pointer to its `next` sibling as well as its
previous (`prev`), as illustrated below:

![dlink](https://github.com/Welchd1/cpsc210-labs/blob/master/labs/lab6/figures/dlink_diag1.png)

### `list` type

And here's our basic `list` controller struct:
```c
typedef struct list_t {
    node* head;
    node* tail;
} list;
```

Conceptually, the list controller shown above adds the following bits to our picture:

![dlink](https://github.com/Welchd1/cpsc210-labs/blob/master/labs/lab6/figures/dlink_diag2.png)

As shown, the `list` object merely maintains a pointer to the `head` (first) and `tail` 
(last) nodes of our list. If our list is only one link long, then `head == tail`, meaning 
both point to the same `node`.

### Linked list functions

```c
/** Returns a new list with fields initialized to null. */
list* list_create();

/** Adds a new node containing 'item' onto the end of list 'l'. */
void list_append(list* l, void* item);

/** Removes the last node from a non-empty list 'l' */
void list_remove_last(list* l);

/** Removes the first node from a non-empty list 'l' */
void list_remove_first(list* l);
```
## Task #2: implement an iterator

An iterator is what will allow us to traverse, access, and mutate the interior nodes of 
a linked list. 

### `iterator` type

```c
typedef struct iterator_t {
    list* l;
    node* current;
} iterator;
```

The iterator for our list will be represented by a basic structure that pairs an instance
of our linked list, `l`, and a `current` node pointer.


### Iterator functions

```c
/** Returns a new iterator and initializes it. */
iterator* iter_create(list* l);

/** advances the iterator by a single node. */
void iter_advance(iterator* iter);

/** advances the iterator by a single node and returns the data of the node associated before it was advanced */
void* iter_next(iterator* iter);

/** advances the iterator back by a single node and returns the data of the node associated before it was moved back */
void* iter_prev(iterator* iter);

/** returns 1 if iter's current pointer is NULL, 0 otherwise. */
int iter_at_end(iterator* iter);

/** returns the current node */
node* iter_get(iterator* iter);

/** removes the current node in the iterator from a nom-empty list. */
void iter_remove(iterator* iter);
```

### A note about using `malloc()` and `free()`

When using malloc remember the following syntax:

```c
 /** replace list with the type that you are actually trying to malloc.*/
 list* l = (list*)malloc(sizeof(list));
```

The function `free()` is the accompanying function to `malloc()` that frees up your data.
When using `free()`, you will only need to call this in your remove functions in `list.c` or `iterator.c`:

```c
node* n = (node*)malloc(sizeof(node));
.
. /** These will be in separate functions. */
.
free(n);
n = NULL;
```

Note that we do not try to dereference the pointer. When we use free we simply pass the variable name to free.

### Testing

After you get to a point where you've implemented several functions for your linked list,
(say, `list_create()` and `list_append()`), make sure you're in the directory housing
your lab files and type `make`. Assuming no errors, go ahead and type `make test` to run 
the provided test driver in `test.c`:

![testing1](https://github.com/Welchd1/cpsc210-labs/blob/master/labs/lab6/figures/test_output.png)

If all goes well you should see a "passed" appear in green next to each test,
meaning you can be *reasonably* sure that your implementation is working as expected.

### Running

If all of your tests have passed and do not get any segmentation faults,
you can run the main program that prints out the lists by typing `make`,
then typing `make run`, which will run the code from `main.c`.
The output should look similar to the figure shown below:

![run](https://github.com/Welchd1/cpsc210-labs/blob/master/labs/lab6/figures/run_output.png)

### Hints

* Some of the functions you will implement can be copied from last week such as creating your list and nodes.
* All of your iterator functions should use just the iterator's current pointer except the `iter_remove()` function which also uses the list.
* In your `list_at_end()` function, you do not need to return an actual `0`, or `1`, you can simply return `iter->current == null`. This   will return the correct result on its own.
* Whenever you change modify the list inside `list.c` or `iterator.c`, make sure that you think about what your previous and     next pointers should point to, as well as if head and tail should change.
* Think about the corner cases: am I at the end of the list or beginning of the list? Is there only a single item in the list?
* When you use `free()`, also set anything pointing to the thing that you free'd to `NULL`.
* Remember to draw out your nodes and links if you get stuck.

## Handin

When you're finished, and you are confident your work is *adequately commented* and 
*correct*, go ahead and 'tarify' with the following command:
```
make handin
```
and submit the resulting `lab6_handin.tar.gz` to the appropriate bucket on 
[handin](https://handin.cs.clemson.edu/courses/).
