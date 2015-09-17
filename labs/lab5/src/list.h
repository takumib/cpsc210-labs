/** list.h -- cpsc 2101 lab 5 */
#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/** list node  */
typedef struct node {
   struct node *next;						// pointer to the next node
   void *data;								// the data stored at this node
} node_t;

/** list controller */
typedef struct list {
   node_t *current;							// current list position 
   node_t *head;							// the head (start) of our list
} list_t;

/** some function prototypes */
list_t *init();						// create and initialize list object
void prepend(list_t *list, void *data); 	// add data to the end of the list
void reset(list_t *list);              		// reset position pointer
void *next(list_t *list);           		// get the next node from the list

#endif