#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

int getMinRequiredCubes(const std::string& line, std::string_view color);


int main() {
    std::string filename { "input.txt" };
    std::ifstream input { filename };

    if (!input) {
        std::cout << "File '" << filename << "' failed to open.\n";
        return 1;
    }

    int powerSum {};
    while (input) {
        std::string line {};
        std::getline(input, line);

        if (line.length() > 0)
            powerSum += (getMinRequiredCubes(line, "red") 
                         * getMinRequiredCubes(line, "green") 
                         * getMinRequiredCubes(line, "blue"));
    }

    std::cout << "Sum of power of min sets: " << powerSum << "\n"; 

    return 0;
}

int getMinRequiredCubes(const std::string& line, std::string_view color) {
    int minSetVal {};
    int startPos { static_cast<int>(line.find(":")) };
    int endPos { static_cast<int>(std::min(line.find(","), line.find(";"))) };

    while (startPos < line.length()) {
        std::string section { line.substr(startPos+2, endPos-startPos) };
        if (section.find(color) != std::string::npos) {
            if (!minSetVal)
                minSetVal = std::stoi(section);
            else
                minSetVal = std::max(minSetVal, std::stoi(section));
        }
        startPos = endPos;
        endPos = std::min(line.find(",", endPos+1), line.find(";", endPos+1));
    }

    return minSetVal;
}

