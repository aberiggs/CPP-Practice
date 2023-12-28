#pragma once

class Node {
public:
    Node(int val);
    Node* next();
    void setNext(Node* next);
    int val();

private:
    int m_val { 0 };
    Node* m_next {nullptr};
};