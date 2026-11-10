module;

#include <iostream>
#include <string>

module gamelogic;

namespace PlayerInput {
    void getPlayerName(std::string& playerName) {
        std::cout << "Enter your name: ";
        std::cin >> playerName;
    }
    
    int getNewGuess() {
        int guess;
        std::cout << "Your guess: ";
        std::cin >> guess;
        return guess;
    }

    bool playAgain() {
        char choice;
        std::cout << "Play again? (y/n): ";
        std::cin >> choice;
        return (choice == 'y' || choice == 'Y');
    }
}

namespace Utilities {
    int generateNumber() {
        srand(time(0));
        return rand() % 100 + 1;
    }
}

namespace GameLogic {
    bool checkGuess(const int& guess, const int& secretNumber, const int& attempts) {
        if (guess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
            return false;
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
            return false;
        } else {
            std::cout << "Correct! You got it in " << attempts << " attempts." << std::endl;
            return true;
        }
    }

    void checkAttempts(const int& attempts) {
        if (attempts <= 5) {
            std::cout << "Rating: Excellent!" << std::endl;
        } else if (attempts <= 10) {
            std::cout << "Rating: Good!" << std::endl;
        } else {
            std::cout << "Rating: Keep practicing!" << std::endl;
        }
    }
    
    void displayScore(const int& attempts, const std::string& playerName) {
        std::cout << "Player: " << playerName << std::endl;
        std::cout << "Attempts: " << attempts << std::endl;
        GameLogic::checkAttempts(attempts);
    }

    int runGameLoop() {
        bool won = false;
        int attempts = 0;
        int guess;
        const int secretNumber = Utilities::generateNumber();
        
        std::cout << "\nGuess a number between 1 and 100:" << std::endl;
        while ((!won) && (attempts < 5)) {
            attempts++;
            guess = PlayerInput::getNewGuess();
            won = GameLogic::checkGuess(guess, secretNumber, attempts);
        }
        return attempts;
    }
}
