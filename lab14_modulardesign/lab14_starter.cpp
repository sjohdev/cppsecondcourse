#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

// Unorganized code - needs refactoring!
// All logic is packed into main and global functions

int secretNumber;
int attempts;
std::string playerName;

void generateNumber() {
    srand(time(0));
    secretNumber = rand() % 100 + 1;
}

void getPlayerName() {
    std::cout << "Enter your name: ";
    std::cin >> playerName;
}

bool checkGuess(int guess) {
    attempts++;
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

void displayScore() {
    std::cout << "Player: " << playerName << std::endl;
    std::cout << "Attempts: " << attempts << std::endl;
    if (attempts <= 5) {
        std::cout << "Rating: Excellent!" << std::endl;
    } else if (attempts <= 10) {
        std::cout << "Rating: Good!" << std::endl;
    } else {
        std::cout << "Rating: Keep practicing!" << std::endl;
    }
}

bool playAgain() {
    char choice;
    std::cout << "Play again? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main() {
    std::cout << "=== NUMBER GUESSING GAME ===" << std::endl;
    getPlayerName();
    
    // This can 
    do {
        // the initialization of variables can be put in a function
        generateNumber();
        attempts = 0;
        int guess;
        bool won = false;
        
        std::cout << "\nGuess a number between 1 and 100:" << std::endl;
        
        while (!won) {
            std::cout << "Your guess: ";
            std::cin >> guess;
            won = checkGuess(guess);
        }
        
        displayScore();
        
    } while (playAgain());
    
    std::cout << "Thanks for playing, " << playerName << "!" << std::endl;
    return 0;
}

