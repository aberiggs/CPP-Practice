#include "./BstNode.h"

#include <iostream>

int main() {
    BstNode root { 50 };
    root.insertKey(30);
    root.insertKey(20);
    root.insertKey(40);
    root.insertKey(45);
    root.insertKey(42);
    root.insertKey(64);
    root.insertKey(68);
    root.insertKey(70);
    root.insertKey(60);
    root.insertKey(80);
    root.insertKey(80);  // Attempt to create duplicate

    int key { 6 };
    if (root.searchKey(key) == nullptr)
        std::cout << "Key " << key << " not found\n";
    else
        std::cout << "Key " << key << " found\n";

    key = 70;
    if (root.searchKey(key) == nullptr)
        std::cout << "Key " << key << " not found\n";
    else
        std::cout << "Key " << key << " found\n";
    
    // Assuming all elements are inserted from root, should print in sorted order
    root.printBst();  
    std::cout << "\n";

    return 0;
}