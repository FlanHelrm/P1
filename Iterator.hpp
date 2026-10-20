#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Node.hpp"

class Iterator {
private:
    Node* current;

public:
    Iterator(Node* start);

    bool hasNext() const;
    bool hasPrev() const;
    void next();
    void prev();
    int getValue() const;
    Node* getNode() const;
};

#endif