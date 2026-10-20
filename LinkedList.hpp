#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Node.hpp"
#include "Iterator.hpp"

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList();
    ~LinkedList();

    void addFront(int val);
    void addBack(int val);
    void addAtIndex(int index, int val);

    void removeFront();
    void removeBack();
    void removeAtIndex(int index);

    void displayForward() const;
    void displayBackward() const;

    void displayNext(Iterator& it) const;
    void displayPrev(Iterator& it) const;

    void clear();
    Iterator getIterator() const;
};

#endif