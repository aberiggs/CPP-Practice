#pragma once

#include "../linked-list/LinkedList.h"

class Queue {
public:
    Queue();
    void enqueue(int val);
    int dequeue();
    int peek();
    bool empty();
    int length();

private:
    LinkedList m_linkedList{};
};