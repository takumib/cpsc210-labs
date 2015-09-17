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

In [list.h]() we provide two structures for you to work with 
-- which, when taken together -- form the foundation of all we need to arrive at our 
final list. The first of these structures is:
```c
typedef struct node
{
   struct node *next;	// pointer to the next node
   void *data;		// the data stored at this node
} node_t;
```
Think of a `node_t` as one link in a 'chain' of *n* nodes that form our list. The struct
defines two fields: 
* a `next` pointer that points to the next `node_t` in the 'chain' if there is such 
a node; `null` otherwise.
* a void pointer that points to a arbitrarily typed piece of data 
(could be number, string, etc)

By way of illustration, consider the a list of `int`s such as `[5, 2, 7]`. Given our
definition of `node_t`, this list internally would look something like:

