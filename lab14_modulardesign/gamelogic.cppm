module;

#include <string>

export module gamelogic;

namespace PlayerInput {
    export void getPlayerName(std::string& playerName);
    export bool playAgain();
}

namespace GameLogic {
    export void displayScore(const int& attempts, const std::string& playerName);
    export int runGameLoop();
}
