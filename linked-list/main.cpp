/* Main file to test the LinkedList class */
#include "./LinkedList.h"
#include <iostream>

int main() {
    LinkedList list; 
  
    // Inserting nodes 
    list.insert(1); 
    list.insert(2); 
    list.insert(3,0); 
    list.insert(4,2); 
  
    std::cout << "Elements of the list are: "; 
  
    // Print the list 
    list.print();
    std::cout << "\n";
  
    // Delete node at position 2. 
    list.deleteAt(2); 
  
    std::cout << "Elements of the list are: "; 
    list.print(); 
    std::cout << "\n"; 

    std::cout << "Element at index 1 is: " << list.valAt(1) << "\n";
    return 0; 
}