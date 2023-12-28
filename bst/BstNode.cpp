#include "./BstNode.h"
#include <iostream>

BstNode::BstNode(int key)
    : m_key { key }
    , m_left { nullptr }
    , m_right { nullptr } {
}

void BstNode::insertKey(int key) {
    BstNode* newBstNode = new BstNode(key);
    BstNode* currentBstNode { this };
    
    while (true) {
        if (currentBstNode->m_key > key) {
            // Go left - new key is lesser
            if (currentBstNode->m_left == nullptr) {
                // Insert leaf Bstnode
                currentBstNode->m_left = newBstNode;
                break;
            }
            currentBstNode = currentBstNode->m_left;
        } else if (currentBstNode->m_key < key) {
            // Go right - new key is greater
            if (currentBstNode->m_right == nullptr) {
                // Insert leaf Bstnode
                currentBstNode->m_right = newBstNode;
                break;
            }
            currentBstNode = currentBstNode->m_right;
        } else {
            // Duplicated keys
            break;
        }
    }
}

BstNode* BstNode::searchKey(int key) {
    BstNode* currentBstNode { this };
    while (currentBstNode != nullptr) {
        if (currentBstNode->m_key > key) {
            // Go left - search key is lesser
            currentBstNode = currentBstNode->m_left;
        } else if (currentBstNode->m_key < key) {
            // Go right - search key is greater
            currentBstNode = currentBstNode->m_right;
        } else {
            // Found key
            return currentBstNode;
        }
    }
    return nullptr;
}
        
void BstNode::printBst() const {
    if (m_left != nullptr) {
        m_left->printBst();
    }

    std::cout << m_key << " ";

    if (m_right != nullptr) {
        m_right->printBst();
    }
}