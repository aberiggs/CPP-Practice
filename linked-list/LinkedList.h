#pragma once

#include "./Node.h"

class LinkedList {
public:
    LinkedList() = default;
    void insert(int val);
    void insert(int val, int pos);
    void deleteAt(int pos);  // Note: 0 Indexed
    int valAt(int pos);  // Note: 0 Indexed
    int length() const;
    void print() const;

private:
    Node* m_head { nullptr };
    int m_length { 0 };
};