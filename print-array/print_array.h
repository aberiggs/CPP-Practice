#ifndef PRINT_ARRAY_H
#define PRINT_ARRAY_H

#include <iostream>

template <typename T>
void printArray(T arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

#endif