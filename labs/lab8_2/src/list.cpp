#include "list.h"

List::List() :
    head(nullptr),
    current(nullptr)
{}

List::~List()
{}

void List::addFirst(void* obj)
{
    Node* n = new Node(obj);

    n->setNext(head);
    head = n;
    current = n;
}

void List::reset()
{
    current = head;
}

void* List::getCurItem()
{
    return current->getItem();
}
