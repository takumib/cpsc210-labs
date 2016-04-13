/*
 * Name:
 * Date:
 * File: list.cpp
 * Description
 */
#include "list.h"

#include <cstring>
#include <iostream>
#include <string>

/*
 * Default List constructor.
 * Hint: set member variables to NULL.
 */
template<typename T>
List<T>::List()
{
    head = NULL;
    current = NULL;
}

/*
 * Destructor for the List.
 * This has already been implemented.
 */
template<typename T>
List<T>::~List()
{
    if(head != NULL) {
        Node<T>* cur = head;
        while(cur != NULL) {
            std::cout << "removing list item" << std::endl;
            Node<T>* tmp = cur->getNext();
            delete cur;
            cur = tmp;
        }
    }
}

/*
 * Add a new Node to the head of the list.
 * Hint: same concept as the C version.
 */
template<typename T>
void List<T>::addFirst(T obj)
{
    Node<T>* n = new Node<T>(obj);
    n->setNext(head);
    head = n;
    current = n;
}

/*
 * Resets the current to the head.
 * Hint: same concept as the C version.
 */
template<typename T>
void List<T>::reset()
{
    this->current = this->head;
}

/*
 * Retruns the current Node's data.
 */
template<typename T>
T List<T>::getCurItem()
{
    return current->getItem();
}

/*
 * Returns the head.
 */
template<typename T>
Node<T>* List<T>::getHead()
{
    return head;
}

template class List<int>;
