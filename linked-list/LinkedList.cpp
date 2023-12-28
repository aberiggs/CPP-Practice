#include "./LinkedList.h"

#include <iostream>

void LinkedList::insert(int val) {
    Node* newNode = new Node(val);
    if (m_head == nullptr) {
        m_head = newNode;
    } else {
        Node* currentNode { m_head };
        while (currentNode->next() != nullptr) {
            currentNode = currentNode->next();
        }    
        currentNode->setNext(newNode);
    }

    ++m_length;
}

void LinkedList::deleteAt(int pos) {
    if (pos >= m_length || pos < 0) return;

    // If we're deleting the head
    if (pos == 0) {
        Node* newHead { m_head->next() };
        delete m_head;
        m_head = newHead;
    } else {
        Node* currentNode { m_head };
        for (int i = 0; i < pos-1; ++i) {
            currentNode = currentNode->next();
        }

        Node* prevNode { currentNode };
        currentNode = currentNode->next();
        Node* nextNode { currentNode->next() };\
        prevNode->setNext(nextNode);
        delete currentNode;
    }

    --m_length;
}

int LinkedList::length() const { return m_length; }

void LinkedList::print() const {

    std::cout << "[";

    if (m_head != nullptr) {
        Node* currentNode { m_head };
        while (currentNode != nullptr && currentNode->next() != nullptr) {
            std::cout << currentNode->val() << ", ";
            currentNode = currentNode->next();
        }
        std::cout << currentNode->val();
    }
    
    std::cout << "]";
}