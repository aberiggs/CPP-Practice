#pragma once

class BstNode {
public:
    BstNode(int key);
    void insertKey(int key);
    BstNode* searchKey(int key);
    void printBst() const;  // Inorder Traversal

private:
    int m_key {};
    BstNode* m_left { nullptr };
    BstNode* m_right { nullptr };
};