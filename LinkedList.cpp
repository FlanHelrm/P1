#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::addFront(int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

void LinkedList::addBack(int val) {
    Node* newNode = new Node(val);
    if (!tail) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void LinkedList::addAtIndex(int index, int val) {
    if (index < 0 || index > size) return;
    if (index == 0) { addFront(val); return; }
    if (index == size) { addBack(val); return; }

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    Node* newNode = new Node(val);
    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;

    size++;
}

void LinkedList::removeFront() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete temp;
    size--;
}

void LinkedList::removeBack() {
    if (!tail) return;
    Node* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete temp;
    size--;
}

void LinkedList::removeAtIndex(int index) {
    if (index < 0 || index >= size) return;
    if (index == 0) { removeFront(); return; }
    if (index == size - 1) { removeBack(); return; }

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    size--;
}

void LinkedList::displayForward() const {
    Node* current = head;
    std::cout << "Lista (przód): ";
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

void LinkedList::displayBackward() const {
    Node* current = tail;
    std::cout << "Lista (tył): ";
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << "\n";
}

void LinkedList::displayNext(Iterator& it) const {
    if (it.hasNext()) {
        it.next();
        std::cout << "Nastepny element: " << it.getValue() << "\n";
    } else {
        std::cout << "Brak nastepnego elementu.\n";
    }
}

void LinkedList::displayPrev(Iterator& it) const {
    if (it.hasPrev()) {
        it.prev();
        std::cout << "Poprzedni element: " << it.getValue() << "\n";
    } else {
        std::cout << "Brak poprzedniego elementu.\n";
    }
}

void LinkedList::clear() {
    while (head) {
        removeFront();
    }
}

Iterator LinkedList::getIterator() const {
    return Iterator(head);
}