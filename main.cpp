#include <iostream>
#include "ListFactory.hpp"

int main() {
    LinkedList* list = ListFactory::createList();

    list->addFront(10);
    list->addBack(20);
    list->addBack(30);
    list->addAtIndex(1, 15);

    list->displayForward();
    list->displayBackward();

    Iterator it = list->getIterator();
    std::cout << "Pierwszy element: " << it.getValue() << "\n";
    list->displayNext(it);
    list->displayNext(it);
    list->displayPrev(it);

    list->removeAtIndex(1);
    list->displayForward();

    list->removeFront();
    list->removeBack();
    list->displayForward();

    list->clear();
    list->displayForward();

    delete list;
    return 0;
}