#include <iostream>

#include "./Queue.h"

int main() {
    Queue q {};

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    

    q.dequeue();
    q.dequeue();
    q.enqueue(1);
    q.enqueue(2);


    std::cout << "Peaking at value: " << q.peek() << "\n";

    while (!q.empty())
        std::cout << q.dequeue() << " ";
    std::cout << "\n";

    return 0;
}