#pragma once
#include <string>

class Game
{
    public:
        enum class gameChoice
        {Rock, Paper, Scissors};
        enum class gameState
        {Win, Tie, Loss};

        static gameChoice   getComputerChoice   (bool isUnfair, gameChoice Plyr);
        static gameChoice   getPlayerChoice     (char choiceEquiv);
        static gameState    evaluateWinCondition(gameChoice Plyr, gameChoice Comp);
        static std::string  getHumanReadable    (gameChoice choice);

    private:
        static int          generateRandomNumber(int Min, int Max);

};