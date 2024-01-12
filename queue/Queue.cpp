#include "./Queue.h"

Queue::Queue() 
    : m_linkedList { LinkedList() } {
}

void Queue::enqueue(int val) {
    m_linkedList.insert(val);
}

int Queue::dequeue() {
    int val = { m_linkedList.valAt(0) };
    m_linkedList.deleteAt(0);
    return val;
}

int Queue::peek() {
    int val = { m_linkedList.valAt(0) };
    return val;
}

void Queue::print() {
    m_linkedList.print();
}