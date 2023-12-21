#include "../print-array/print_array.h"

#include <iostream>

void mergesort(int* arr,  int size);
void merge(int* arrL, int sizeL, int* arrR, int sizeR);

int main() {

    std::cout << "Enter amount of #'s to sort: ";
    int inputSize { 0 };
    std::cin >> inputSize;

    std::cout << "Enter " << inputSize << " numbers.\n";

    int nums[inputSize] {};

    for (int i = 0; i < inputSize; ++i) {
        std::cin >> nums[i];
    }

    mergesort(nums, inputSize);

    std::cout << "\n";
    printArray(nums, inputSize);   

    return 0;
}

void mergesort(int arr[],  int size) {
    if (size == 1) {
        return;
    }
    mergesort(arr, size/2);
    mergesort(&(arr[size/2]), size-(size/2));
    merge(arr, (size/2), &(arr[size/2]), size-(size/2));
}

void merge(int arrL[], int sizeL, int arrR[], int sizeR) {    
    int temp[sizeL+sizeR] = {};
    int posL { 0 };
    int posR { 0 };
    int posT { 0 };

    while (posT < (sizeL + sizeR)) {
        if (posL < sizeL && posR < sizeR) {
            if (arrL[posL] < arrR[posR]) {
                temp[posT] = arrL[posL];
                ++posT;
                ++posL;
            } else {
                temp[posT] = arrR[posR];
                ++posT;
                ++posR;
            }
        } else if (posL >= sizeL) {
            temp[posT] = arrR[posR];
                ++posT;
                ++posR;
        } else {
            temp[posT] = arrL[posL];
            ++posT;
            ++posL;
        }
    }

    --posT;  // Since we incremented 1 past the end of the array previously
    while (posT >= 0) {
        arrL[posT] = temp[posT];
        --posT;
    }
}