/*
 * Name:
 * Date:
 * File: list.cpp
 * Description
 */
#include "list.h"

#include <cstring>

/*
 * Default List constructor.
 * Hint: set member variables to NULL.
 */
List::List()
{}

/*
 * Destructor for the List.
 * This has already been implemented.
 */
List::~List()
{
    if(head != NULL) {
        Node* cur = head;
        while(cur != NULL) {
            std::cout << "removing list item" << std::endl;
            Node* tmp = cur->getNext();
            delete cur;
            cur = tmp;
        }
    }
}

/*
 * Add a new Node to the head of the list.
 * Hint: same concept as the C version.
 */
void List::addFirst(void* obj)
{
}

/*
 * Resets the current to the head.
 * Hint: same concept as the C version.
 */
void List::reset()
{
}

/*
 * Retruns the current Node's data.
 */
void* List::getCurItem()
{
    return NULL;
}

/*
 * Returns the head.
 */
Node* List::getHead()
{
    return NULL;
}
