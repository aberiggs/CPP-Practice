#include "./Queue.h"
#include <stdexcept>

Queue::Queue() 
    : m_linkedList { LinkedList() } {
}

void Queue::enqueue(int val) {
    m_linkedList.insert(val);
}

int Queue::dequeue() {
    if (m_linkedList.length() <= 0)
        throw std::range_error("dequeue called but queue was empty.");
    int val = { m_linkedList.valAt(0) };
    m_linkedList.deleteAt(0);  
    return val;
}

int Queue::peek() {
    if (m_linkedList.length() <= 0)
        throw std::range_error("peek called but queue was empty.");
    int val = { m_linkedList.valAt(0) };
    return val;
}

bool Queue::empty() {
    return (this->length() == 0 ? true : false);
}

int Queue::length() {
    return (m_linkedList.length());
}