#pragma once

#include <string>
#include <time.h>
#include <vector>

class Session {
public:
    Session();
    void inputLetter(); // Accept a letter of input from the user. Do basic input validation to filter out non-letters or extraneous input.
    void displayState(); // Display the basic state of the game, where the word is displayed as underscores.
    int attemptsLeft();
    bool gameIsWon();


private:
    const int m_wrongGuessCount = 6;   

    std::string_view m_word;
    std::vector<bool> m_charsGuessed;
    std::vector<char> m_wrongGuesses;
};