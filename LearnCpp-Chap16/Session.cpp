#include "./Session.h"

#include <iostream>

namespace WordList {
    
    std::vector<std::string> words {"mystery", "broccoli", "account", 
                                     "almost", "opinion", "spaghetti", 
                                     "beautiful", "distance", "luggage"};

    std::string_view pickRandomWord() {
        srand(time(0));
        std::size_t wordIndex = rand() % words.size();
        return (words[wordIndex]);
    }
}

Session::Session()
    : m_word{WordList::pickRandomWord()}
    , m_charsGuessed{std::vector<bool>('z'-'a'+1)}
    , m_wrongGuesses{std::vector<char>()} {
}

void Session::inputLetter() {
    std::cout << "Enter your next (lowercase) letter: ";
    
    char input {};
    std::cin >> input;

    if (input < 'a' || input > 'z') {
        std::cout << "That wasn't a valid input. Try again.\n";
        return;
    } else if (m_charsGuessed[input-'a']) {
        std::cout << "You already guessed that. Try again.\n";
        return;
    }

    std::cout << "You entered: " << input << "\n";
    m_charsGuessed[input-'a'] = true;

    for (auto letter : m_word) {
        if (letter == input) {
            std::cout << "Yes, '" << input << "' is in the word.\n";
            return;
        }
    }
    std::cout << "No, '" << input << "' is not in the word.\n";
    m_wrongGuesses.push_back(input);
}

void Session::displayState() {
    std::cout << "The word: ";
    for (auto letter : m_word) {
        if (m_charsGuessed[letter-'a'])
            std::cout << letter;
        else
            std::cout << "_";
    }

    std::cout << "    Wrong guesses: ";

    for (int i = 0; i < (m_wrongGuessCount - static_cast<int>(m_wrongGuesses.size())); ++i) {
        std::cout << "+";
    }

    for (auto letter : m_wrongGuesses) {
        std::cout << letter;
    }

    std::cout << "\n";
}

int Session::attemptsLeft() {
    return m_wrongGuessCount - static_cast<int>(m_wrongGuesses.size()) + 1;
}

bool Session::gameIsWon() {
    for (auto letter : m_word) {
        if (m_charsGuessed[letter - 'a'] != 1) 
            return false;
    }
    
    return true;
}