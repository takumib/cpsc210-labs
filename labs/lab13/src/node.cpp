/*
 * Name:
 * Date:
 * File: node.cpp
 * Description:
 */
#include "node.h"

#include <cstring>
#include <string>

/*
 * Default Node constructor.
 * Hint: the member variables need to be initialized to NULL.
 */
template<typename T>
Node<T>::Node()
{
    next = NULL;
}

/*
 * Specialized constructor.
 * Hint: still need to initialize member variables, but one of them
 *       will be set to the constructor argument.
 */
template<typename T>
Node<T>::Node(T itm)
{
    next = NULL;
    item = itm;
}

/*
 * Node Destructor
 */
template<typename T>
Node<T>::~Node()
{
    // left blank intentionally.
}

/*
 * Returns the next node.
 */
template<typename T>
Node<T>* Node<T>::getNext()
{
    return next;
}

/*
 * Returns the Node's item.
 */
template<typename T>
T Node<T>::getItem()
{
    return item;
}

/*
 * Sets the Node's next variable.
 */
template<typename T>
void Node<T>::setNext(Node<T>* n)
{
    next = n;
}

template class Node<int>;
