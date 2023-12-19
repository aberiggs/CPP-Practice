#include <iostream>

int iterativeFactorial(int n);
int recursiveFactorial(int n);

int main() {
    std::cout << "Welcome to factorial finder. Please choose your n value: ";

    int nVal {0};
    std::cin >> nVal;

    int (*factorialFinder)(int);
    factorialFinder = recursiveFactorial;

    std::cout << "Result: " << factorialFinder(nVal) << "\n";

    return 0;
}

int iterativeFactorial(int n) {
    int res {1};

    while (n > 0) {
        res *= n;
        --n;
    }

    return res;
}

int recursiveFactorial(int n) {
    if (n < 1) {
        return 1;
    }

    return n * recursiveFactorial(n-1);
}