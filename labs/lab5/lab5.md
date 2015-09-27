## Objectives

In this lab you will be writing a bare-bones implementation of a singly linked list. 
When you're done with this lab, you should understand and be able to employ 
"void" pointers in your code, gain some familiarity with developing type-general, linked
data-structures, and work more effectively with pointers in general.

### Housekeeping
You can download your complete lab 5 starter kit on the 
[releases page](https://github.com/Welchd1/cpsc210-labs/releases) or peruse the default 
[lab sources](https://github.com/Welchd1/cpsc210-labs/tree/master/labs/lab5/src) here on 
Github*

*Please remember to practice good organization when downloading your files, i.e.:

* First, create a lab 5 directory under your class directory (should be something like cpsc210).
* Then type: `wget https://github.com/Welchd1/cpsc210-labs/releases/download/5.0.0/lab5.zip `
* After this decompress the tar, `unzip lab5.zip`
* Then remove the zip file: `rm lab5.zip`

These instructions should be pretty much routine to you at this point, and as such, will disappear from future lab handouts.

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

### List functions

Here are prototypes for the list functions that you are expected to implement. Each is 
preceded by an *informal* specification that describes at a high level what the function 
is supposed to accomplish.

```c
/** Creates and returns a 'new' list controller object. To implement this correctly,
 *  you're going to need to understand how to allocate memory in C using the malloc 
 *  ('M'emory'ALLOC'cation) function.
 */
list_t *init();

/** Given an existing (possibly empty) 'list' and a pointer to a piece of 'data', 
 *  this method creates a new node whose data field points to the 'data' parameter, 
 *  and whose 'next' field points to the existing head node; if the list is empty 
 *  (i.e.: head == null), assign head to your new node and set next to null. This
 *  function should also make 'current' point to the new node (i.e.: the new 'head').
 */
void prepend(list_t *list, void *data);

/** Sets the current position pointer of 'list' to point at the head. */
void reset(list_t *list);

/** Returns a pointer to the data field of the node pointed to by 'current' (remember:
 *  'current' is a field in 'list') and advances the 'current' pointer to the next 
 *  node.
 */
void *getnext(list_t *list);
```

### Testing

Assuming you are in the directory housing your code, to run all you need to do is type 
`make` followed by `./lab5` to execute the `listtest` driver. Also, typing `make clean` 
will freshen your current working directory by deleting any gcc-generated `*.o` 
files, etc.

The [listtest.c]
(https://github.com/Welchd1/cpsc210-labs/blob/master/labs/lab5/src/listtest.c) driver 
provided currently only prints the contents of `num_list`. Your job is to extend the 
existing tests so that it prints out both the contents of `fruit_list` and `car_list`. 

Iterate and use your `next()` method to access to the contents of the lists,
formatting your output like so:
            
```c
num_list: 25, 20, 15, 10, 5,
fruit_list: banana, peach, orange, apple,
car_list: [Toyota Camry 2010], [Honda Accord 2010], [Ford Mustang 2009],
```

## Hints

* When implementing `init()` remember to initialize `current` and `head` 
fields to `NULL`. If you don't do this, asking if some field of your list `== NULL` will 
likely not work (in all likelihood you'll get a segmentation fault).

* There are two cases to deal with in the implemention of `prepend()`: one in which the
list you're appending to is empty (how do we detect this?), and the more general case 
when the list already contains one or more elements.

* When you `prepend()` an element to your list, head should be reassigned to point at 
the newly appended element, *and current should also be re-assigned to the 
head with it*.

* When printing the contents of your lists in `listtest.c`, *do not* make the condition
of your while loop `while (next(list1) != NULL) {..}`. Why? Think about what `getnext()` 
is actually doing to the list, and you should realize why you don't want to call this as 
within your loop condition check.

## Handin

When you're finished, and you are confident your work is *adequately commented* and 
*correct*, go ahead and 'tarify' with the following command:
```
tar cvf lab5_handin.tar list.h list.c listtest.c MakeFile
```
and submit the resulting `lab5_handin.tar` to the appropriate bucket on 
[handin](https://handin.cs.clemson.edu/courses/).
