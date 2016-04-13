#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {
public:
    Node();
    Node(T);
    ~Node();

    Node* getNext();
    T getItem();
    void setNext(Node*);

private:
    T item;
    Node* next;
};

#endif
