## Objectives

In this lab we're going to exercise our knowledge of singly linked lists by implementing
both a doubly-linked list and an associated iterator.

In working through the implementation of each of these separate structures, you'll gain
not only more experience in working with pointers, but will also be exposed to 

implementation of several non-trivial operations on lists including one for removing 
elements from a list. 

Overall, by the end of this lab
You'll gain not only more experience in working with pointers, but will also be exposed
to several concepts that will remain w dabble in the
implementation of several non-trivial operations including:

you can think of an iterator simply as a means of traversing a container (in our case,
the container is simply a list).

* separating iteration from from list itself by writing an iterator

* author a more robust, effient, and overall more usable list for future labs..

As always, you can either download your complete lab 6 starter kit on the 
[releases page]() or peruse the default starter files [here]() on GitHub

## Tasks 

This lab is separated into two broad tasks: for the first task you'll need to implement 
the doubly linked list defined `list.h`, and for the second task, you'll implement an
iterator for said list, capable of accessing, removing, and traversing (both forwards and
backwards) over the elements of the list.

## Task #1: implement a doubly linked list

The structures we'll use to compose the implementation of our doubly linked list are 
very similar to those we would use for a singly linked list. In fact: they are the same,
with the addition of a `prev` pointer in each node that points backwards previous node 
in the chain.

That is rather than 


### Testing ... testing

After we get to a point where you've implemented one or two operations for the list 
(such as `init()` and `append()` 

## Handin

When you're finished, and you are confident your work is *adequately commented* and 
*correct*, go ahead and 'tarify' with the following command:
```
tar cvf lab6_handin.tar list.h list.c iterator.c iterator.h main.c MakeFile
```
and submit the resulting `lab6_handin.tar` to the appropriate bucket on 
[handin](https://handin.cs.clemson.edu/courses/).
