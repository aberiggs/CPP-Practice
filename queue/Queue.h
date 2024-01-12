#pragma once

#include "../linked-list/LinkedList.h"

class Queue {
public:
    Queue();
    void enqueue(int val);
    int dequeue();
    int peek();
    void print();

private:
    LinkedList m_linkedList{};
};