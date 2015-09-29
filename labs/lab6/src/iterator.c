/*
 * Author:
 * Last Edited: September 28, 2015
 * File: iterator.c
 * Description: 
 */
#include "iterator.h"

#include <stdlib.h>

/*
 * function: iter_create(list*)
 * description:
 * return: new iterator
 */
iterator* iter_create(list* l)
{
    return NULL;
}

/*
 * function: iter_advance(iterator*)
 * description:
 */
void iter_advance(iterator* iter)
{
}

/*
 * function: iter_get(iterator*)
 * description:
 * return: the current node.
 */
node* iter_get(iterator* iter)
{
    return NULL;
}

/*
 * function: iter_next(iterator*)
 * description:
 * return: the current node's data before advancing the list.
 */
void* iter_next(iterator* iter)
{
    return NULL;
}

/*
 * function: iter_prev(iterator*)
 * description:
 * return: the current node's data before moving to previous node.
 */
void* iter_prev(iterator* iter)
{
    return NULL;
}

/*
 * function: iter_at_end(iterator*)
 * description:
 * return: 1 if iterator's current is NULL, 0 otherwise.
 */
int iter_at_end(iterator* iter)
{
    return 0;
}

/*
 * function: iter_remove(iterator*)
 * function:
 */
void iter_remove(iterator* iter)
{
}
