#pragma once

#include "../linked-list/LinkedList.h"

class Stack {
public:
    Stack();
    void push(int val);
    int pop();
    int peek();
    bool empty();
    int length();

private:
    LinkedList m_linkedList{};
};