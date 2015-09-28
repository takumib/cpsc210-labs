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
write for this lab.

As always, you can either download your complete lab 6 starter kit on the 
[releases page]() or peruse the default starter files [here]
(https://github.com/Welchd1/cpsc210-labs/tree/master/labs/lab6/src) on GitHub

## Tasks 

This lab is separated into two broad tasks: for the first you'll need to implement 
the doubly linked list defined in `list.h`, after this, you'll implement an iterator for 
said list, capable of accessing, removing, and traversing (both forwards and
backwards) over the elements.

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

/** Deep copies all elements from list 'l' onto an empty list, 'out' */
void list_copy(list* l, list* out);
```


### Testing ... testing

After you get to a point where you've implemented one or two of the above operations 
(say, `list_create()` and `list_append()`), make sure you're in the directory housing
your lab files and type `make`. Assuming no errors, go ahead and type `./lab6` to run 
the provided test driver in `main.c`. 

If all goes well you should see a "passed" next to
each function (indicating that you've passed all test cases for that function):



## Handin

When you're finished, and you are confident your work is *adequately commented* and 
*correct*, go ahead and 'tarify' with the following command:
```
tar cvf lab6_handin.tar list.h list.c iterator.c iterator.h main.c MakeFile
```
and submit the resulting `lab6_handin.tar` to the appropriate bucket on 
[handin](https://handin.cs.clemson.edu/courses/).
