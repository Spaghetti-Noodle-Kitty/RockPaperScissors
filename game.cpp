#include "game.h"
#include <random>

// Private variable setup
std::random_device randomDevice;
std::mt19937 randomNumGenerator(randomDevice());

// Exception setup
class invalidGameChoiceException : public std::exception {
    public:
char * what () {
        return const_cast<char*>("invalid choice");
    }
};

// Private methods
int Game::generateRandomNumber(int Min, int Max)
{  
    std::uniform_int_distribution<std::mt19937::result_type> uniDist(Min,Max);
    return uniDist(randomNumGenerator);
}

// Public methods
std::string Game::getHumanReadable(gameChoice gC)
{
    switch (gC)
    {
        case gameChoice::Rock:
            return "Rock";
        case gameChoice::Paper:
            return "Paper";
        case gameChoice::Scissors:
            return "Scissors";
        default:
            throw invalidGameChoiceException();
    }

}

Game::gameChoice Game::getPlayerChoice(char C)
{
    C = std::tolower(C);

    switch (C)
    {
    case 'r':
        return gameChoice::Rock;
    case 'p':
        return gameChoice::Paper;
    case 's':
        return gameChoice::Scissors;
    default:
        throw invalidGameChoiceException();
    }

}

Game::gameChoice Game::getComputerChoice(bool isUnfair, gameChoice Plyr)
{
    int rand = 0;

    if(isUnfair)
    {
        switch (Plyr)
        {
            case gameChoice::Rock:
                return gameChoice::Paper;
            case gameChoice::Paper:
                return gameChoice::Scissors;
            case gameChoice::Scissors:
                return gameChoice::Rock;
            default:
                throw invalidGameChoiceException();
        }
    }
    else
    {
        rand = generateRandomNumber(1,3);

        if(rand==1)
            return gameChoice::Rock;
        else if(rand==2)
            return gameChoice::Paper;
        else if(rand==3)
            return gameChoice::Scissors;
        else
            throw invalidGameChoiceException();
    }
}

Game::gameState Game::evaluateWinCondition(gameChoice Plyr, gameChoice Comp)
{
    if(Plyr == Comp)
        return gameState::Tie;
    else if(Plyr == gameChoice::Rock && Comp == gameChoice::Scissors ||
            Plyr == gameChoice::Paper && Comp == gameChoice::Rock    ||
            Plyr == gameChoice::Scissors && Comp == gameChoice::Paper)
        return gameState::Win;
    else
        return gameState::Loss;
}
