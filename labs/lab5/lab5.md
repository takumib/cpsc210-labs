## Some objectives for today's lab

In this lab you will be writing a bare-bones implementation of a singly linked list. 
When you're done with this lab, you should be able to understand and be able to employ 
"void" pointers in your code, gain some familiarity with developing type-general 
data-structures, and work more effectively with pointers in general.

You can find your starter kit [here]().

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
In [list.h]() we provide two structures that give us everything we need to implement the 
list data structure we want. 

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
such a node; `null` otherwise.
* a void pointer called `data` that points to an arbitrarily-typed object
(could be a number, string, vector, tree, etc)

Given our definition of `node_t`, pictorially, a list of integers such as `[5, 2, 7]` 
would internally look something like:

![nodes](https://github.com/Welchd1/cpsc210-labs/blob/master/labs/lab5/node_diag1.png)

#### `list_t`

The second, and final piece of our implementation puzzle is `list_t`:
```c
typedef struct list {
   node_t *current;		// current list position 
   node_t *head;		// the head (starting node) of our list
} node_t;
```

You can think of `list_t` as the manager, or controller, of an entire list. The `list_t`
controller keeps track of two important pieces of information:
* a `current` position pointer that points to *one* particular `node_t`
within the list -- which one? -- we'll get to that when we look at the functions.
* a `head` pointer which always points to the `node_t` at the start of the list (e.g.: the **head** of the list);
if the list is empty, `head` points to `null`.

So in terms of our previous `[5, 2, 7]` a `list_t` adds the following to our 
illustration:


Whereas a list typically has many node_t s, 
