## Objectives

In this lab you will extend your knowledge of linked lists by implementing a 
**doubly-linked list** and an associated **iterator**.

In working through the implementation of these separate structures, you'll gain
not only more experience in working with pointers, but will also be exposed to a common
design strategy that separates implementation of a core data structure 
(in our case, a doubly linked list) from the logic driving its traversal. 

In summary, by the end of this lab you will have at your disposal a robust, efficient 
linked list and iterator for use in future labs -- not to mention 
experience in writing increasingly complex functions, such as `remove()` that you'll 
also write for this lab.

As always, you can either download your complete lab 6 starter kit on the 
[releases page](https://github.com/Welchd1/cpsc210-labs/releases) or peruse the default starter files [here]
(https://github.com/Welchd1/cpsc210-labs/tree/master/labs/lab6/src) on GitHub

## Using Tar

Remember when decompressing type:

```
tar xvzf lab6.tar.gz
```

## Tasks 

This lab is separated into two broad tasks: for the first you'll need to implement 
the doubly linked list defined in `list.h`, after this, you'll implement an iterator for 
said list defined in `iterator.h`, capable of accessing, removing, and traversing 
(both forwards and backwards) over the elements. All of your work will be done in either
`list.c` or `iterator.c`. All testing code will be provided.

## Task #1: implement a doubly linked list

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

### A Note about using `malloc()` and `free()`

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
* All of your iterator functions should use just the iterator's current pointer except the iter_remove function which also uses   the list.
* In your list_at_end function, you do not need to return an actual 0, or 1, you can simply return iter->current == NULL. This   will return the correct result on its own.
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
and submit the resulting `lab6_handin.tar` to the appropriate bucket on 
[handin](https://handin.cs.clemson.edu/courses/).
