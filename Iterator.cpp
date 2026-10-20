#include "Iterator.hpp"

Iterator::Iterator(Node* start) : current(start) {}

bool Iterator::hasNext() const {
    return current != nullptr && current->next != nullptr;
}

bool Iterator::hasPrev() const {
    return current != nullptr && current->prev != nullptr;
}

void Iterator::next() {
    if (current) current = current->next;
}

void Iterator::prev() {
    if (current) current = current->prev;
}

int Iterator::getValue() const {
    return current ? current->data : -1;
}

Node* Iterator::getNode() const {
    return current;
}