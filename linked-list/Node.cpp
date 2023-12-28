#include "Node.h"

Node::Node(int val) 
    : m_val { val }
    , m_next { nullptr } {
}

Node* Node::next() { return m_next; }

void Node::setNext(Node* next) { m_next = next; }

int Node::val() { return m_val; }