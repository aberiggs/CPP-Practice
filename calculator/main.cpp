#include <iostream>
#include <string>

double getDouble();
std::string getOperator();

int main() {
    std::cout << "Enter operation as such: <number> <operator> <number>\n";

    double numOne {getDouble()};
    std::string op {getOperator()};
    double numTwo {getDouble()};

    if (op == "+") {
        std::cout << numOne << op << numTwo << "=" << numOne+numTwo << "\n";
    } else if (op == "-") {
        std::cout << numOne << op << numTwo << "=" << numOne-numTwo << "\n";
    } else {
        std::cout << "Invalid operator!\n";
    }

    return 0;    
}

double getDouble() {
    double num {0.0};
    std::cin >> num;
    return num;
}

std::string getOperator() {
    std::string str {""};
    std::cin >> str;
    return str;
}