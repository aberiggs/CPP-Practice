#include "../print-array/print_array.h"

#include <iostream>
#include <string>

void bubbleSort(int* arr, int size);
 
int main() {

    std::cout << "Enter amount of #'s to sort: ";
    int inputSize {0};
    std::cin >> inputSize;

    std::cout << "Enter " << inputSize << " numbers.\n";

    int* nums = new int[inputSize];

    for (int i = 0; i < inputSize; ++i) {
        std::cin >> nums[i];
    }

    std::cout << "\n";

    bubbleSort(nums, inputSize);

    printArray(nums, inputSize);   

    return 0;
}

void bubbleSort(int* arr, int size) {
    // Could exit early in best case, but won't worry about that right now
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size-1; ++j) {
            if (arr[j] > arr[j+1]) {
                int temp {arr[j]};
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

    }
}


