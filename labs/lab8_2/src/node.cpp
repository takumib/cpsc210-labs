#include "node.h"

Node::Node() :
    item(nullptr),
    next(nullptr)
{}

Node::Node(void* itm) :
    item(itm),
{}

Node::~Node()
{}

Node* Node::getNext()
{
    return next;
}

void* Node::getItem()
{
    return item;
}

void Node::setNext(Node* n)
{
    next = n;
}
