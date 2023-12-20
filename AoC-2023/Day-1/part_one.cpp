#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

int getCalibrationValue(std::string_view str);

int main() {
    std::ifstream input { "input.txt" };

    if (!input) {
        std::cout << "Could not open the input file.\n";
        return 1;
    }

    int output { 0 };

    while (input) {
        std::string line {};
        std::getline(input, line);
        output += getCalibrationValue(line);
    }

    std::cout << "The sum of all calibration values is: " << output << "\n";

    return 0;
}

int getCalibrationValue(std::string_view str) {
    // Initialize digit values to invalid values until we find a valid value
    int firstDigit {};
    int lastDigit {};

    for (auto& c : str) {
        // 48 is character code for '0' and 57 is character code for '9' 
        if (c >= 48 && c <= 57) {
            if (!firstDigit) {
                firstDigit = static_cast<int>(c) - 48;
            }
            lastDigit = static_cast<int>(c) - 48;
        }
    }
    return (firstDigit*10 + lastDigit);
}