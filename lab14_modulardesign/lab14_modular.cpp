#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

import gamelogic;

int main() {
    std::cout << "=== NUMBER GUESSING GAME ===" << std::endl;
    // Initialize variables
    std::string playerName;
    int attempts;
    // Get player name from user:
    PlayerInput::getPlayerName(playerName);
    
    // This can be put in a function
    do {
        // New game: 
        attempts = GameLogic::runGameLoop();
        GameLogic::displayScore(attempts, playerName);
    } while (PlayerInput::playAgain());
    
    std::cout << "Thanks for playing, " << playerName << "!" << std::endl;
    return 0;
}

