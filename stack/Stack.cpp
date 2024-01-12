#include "Stack.h"
#include <stdexcept>

Stack::Stack() 
    : m_linkedList { LinkedList() } {
}

void Stack::push(int val) {
    m_linkedList.insert(val, 0);
}

int Stack::pop() {
    if (m_linkedList.length() <= 0) 
        throw std::range_error("pop called but stack was empty.");

    int val { m_linkedList.valAt(0) };
    m_linkedList.deleteAt(0);

    return val;
}

int Stack::peek() {
    if (m_linkedList.length() <= 0) 
        throw std::range_error("peek called but stack was empty.");

    int val { m_linkedList.valAt(0) };
    return val;
}

bool Stack::empty() {
    return (this->length() == 0 ? true : false);
}

int Stack::length() {
    return (m_linkedList.length());
}

