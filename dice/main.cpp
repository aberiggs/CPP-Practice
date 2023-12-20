#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <time.h> 

int rollDice(int sides);
void printHistogram(int data[], int minRoll, int maxRoll, int rolls);

int main() {
    std::cout << "Welcome to dice simulator.\nPlease enter the number of sides for your dice: ";
    int sides { 0 };
    std::cin >> sides;

    std::cout << "How many dice to roll at once: ";
    int numDice { 0 };
    std::cin >> numDice; 

    std::cout << "How many times would you like to roll: ";
    int rolls { 0 };
    std::cin >> rolls;

    std::srand(std::time(0));  // Seed rand
    int* data = new int[numDice*sides];

    for (int i = 0; i < rolls; ++i) {
        int total { 0 }; 
        for (int j = 0; j < numDice; ++j) {
            total += rollDice(sides);
        }
        data[total-1] += 1;
    }

    printHistogram(data, numDice, numDice*sides, rolls);

    return 0;
}

int rollDice(int sides) {
    int rollResult { (std::rand() % sides) + 1 };
    return rollResult;
}

void printHistogram(int data[], int minRoll, int maxRoll, int rolls) {
    std::cout << "\n";
    int histogramBarAmount {30};

    for (int i = minRoll-1; i < maxRoll; ++i) {
        std::cout << std::setw(4) << i+1;
        std::cout << " | ";

        double rollPercentage { static_cast<double>(data[i]) / rolls };
        int lineLength { static_cast<int>(rollPercentage * histogramBarAmount) };
        for (int j = 0; j < lineLength; ++j) {
            std::cout << "#";
        }
        std::cout << "# ~ " << rollPercentage*100 << "%\n";
    }

    std::cout << "\n";
}