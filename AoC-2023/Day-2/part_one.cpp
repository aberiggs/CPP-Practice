#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

bool impossibleInLine(std::string& line);
bool impossibleInSection(std::string& section);


int main() {
    std::string filename { "input.txt" };
    std::ifstream input { filename };

    if (!input) {
        std::cout << "File '" << filename << "' failed to open.\n";
        return 1;
    }

    int idSum {};
    int gameNum { 1 };
    while (input) {
        std::string line {};
        std::getline(input, line);

        if (line.length() > 0 && !impossibleInLine(line))
            idSum += gameNum;

        ++gameNum;
    }

    std::cout << "Sum of all IDs of possible games: " << idSum << "\n"; 

    return 0;
}

bool impossibleInLine(std::string& line) {
    int startPos { static_cast<int>(line.find(":")) };
    int endPos { static_cast<int>(std::min(line.find(","), line.find(";"))) };
    
    while (startPos < line.length()) {
        std::string section { line.substr(startPos+2, endPos-startPos) };
        if (impossibleInSection(section)) 
            return true;

        startPos = endPos;
        endPos = std::min(line.find(",", endPos+1), line.find(";", endPos+1));
    }

    return false;
}

bool impossibleInSection(std::string& section) {
    int redMax { 12 };
    int greenMax { 13 };
    int blueMax { 14 };
    int val { std::stoi(section) };

    if ((section.find("red") != std::string::npos) && (val > redMax))
        return true;
    else if ((section.find("green") != std::string::npos) && (val > greenMax))
        return true;
    else if ((section.find("blue") != std::string::npos) && (val > blueMax))
        return true;


    return false;
}

