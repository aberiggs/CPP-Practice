#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

int getCalibrationValue(std::string_view str);
int getNumAtStringStart(std::string_view str, int pos);

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

    for (int i = 0; i < str.length(); ++i) {
        auto& c  = str[i];
        // 48 is character code for '0' and 57 is character code for '9' 
        if (c >= 48 && c <= 57) {
            if (!firstDigit) {
                firstDigit = static_cast<int>(c) - 48;
            }
            lastDigit = static_cast<int>(c) - 48;
        } else {
            int numFromString { getNumAtStringStart(str, i) };
            if (numFromString != 0) {
                if (!firstDigit) {
                    firstDigit = numFromString;
                }
                lastDigit = numFromString;
            }
        }
    }
    return (firstDigit*10 + lastDigit);
}

int getNumAtStringStart(std::string_view str, int pos) {
    if (str.compare(pos, 3, "one") == 0)
        return 1;
    else if (str.compare(pos, 3, "two" ) == 0)
        return 2;
    else if (str.compare(pos, 5, "three" ) == 0)
        return 3;
    else if (str.compare(pos, 4, "four" ) == 0)
        return 4;
    else if (str.compare(pos, 4, "five" ) == 0)
        return 5;
    else if (str.compare(pos, 3, "six" ) == 0)
        return 6;
    else if (str.compare(pos, 5, "seven" ) == 0)
        return 7;
    else if (str.compare(pos, 5, "eight" ) == 0)
        return 8;
    else if (str.compare(pos, 4, "nine" ) == 0)
        return 9;

    return 0;
}