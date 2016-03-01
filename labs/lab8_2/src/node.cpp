/*
 * Name:
 * Date:
 * File: node.cpp
 * Description:
 */
#include "node.h"

#include <cstring>

/*
 * Default Node constructor.
 * Hint: the member variables need to be initialized to NULL.
 */
Node::Node()
{}

/*
 * Specialized constructor.
 * Hint: still need to initialize member variables, but one of them
 *       will be set to the constructor argument.
 */
Node::Node(void* itm)
{}

/*
 * Node Destructor
 */
Node::~Node()
{
    // left blank intentionally.
}

/*
 * Returns the next node.
 */
Node* Node::getNext()
{
    return NULL;
}

/*
 * Returns the Node's item.
 */
void* Node::getItem()
{
    return NULL;
}

/*
 * Sets the Node's next variable.
 */
void Node::setNext(Node* n)
{
}
