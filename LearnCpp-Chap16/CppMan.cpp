/* Version of Hang Man created with C++ */
#include "Session.h"

#include <iostream>
#include <string>


int main() {
    std::cout << "Welcome to C++man!\n";
    std::cout << "To win: guess the word. To lose: run out of pluses.\n";

    while (true) {
        Session session{};
        while (session.attemptsLeft() > 0 && !session.gameIsWon()) {
            session.displayState();
            session.inputLetter();
            std::cout << "\n";
        }

        if (session.gameIsWon()) {
            std::cout << "Congratulations, you win!\n";
        } else {
            std::cout << "You have lost...\n";
        }
        
        std::string playAgainResponse{};
        while (playAgainResponse != "y" && playAgainResponse != "n") {
            std::cout << "Would you like to play again? (y/n): ";
            std::cin >> playAgainResponse;
        }

        if (playAgainResponse == "n")
            break;
        std::cout << "\n\n";
    }
    return 0;
}