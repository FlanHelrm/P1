#include "ListFactory.hpp"

LinkedList* ListFactory::createList() {
    return new LinkedList();
}