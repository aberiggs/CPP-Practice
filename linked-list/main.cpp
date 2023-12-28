/* Main file to test the LinkedList class */
#include "./LinkedList.h"
#include <iostream>

int main() {
    LinkedList list; 
  
    // Inserting nodes 
    list.insert(1); 
    list.insert(2); 
    list.insert(3); 
    list.insert(4); 
  
    std::cout << "Elements of the list are: "; 
  
    // Print the list 
    list.print();
    std::cout << "\n";
  
    // Delete node at position 2. 
    list.deleteAt(2); 
  
    std::cout << "Elements of the list are: "; 
    list.print(); 
    std::cout << "\n"; 
    return 0; 
}