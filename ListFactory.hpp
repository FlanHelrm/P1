#ifndef LISTFACTORY_HPP
#define LISTFACTORY_HPP

#include "LinkedList.hpp"

class ListFactory {
public:
    static LinkedList* createList();
};

#endif