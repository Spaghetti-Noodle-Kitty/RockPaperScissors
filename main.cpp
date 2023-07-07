#include "game.h"
#include "printer.h"
#include <iostream>
#include <iomanip>


int main(int argc, char *argv[])
{
    bool isUnfair = false;
    char playerChar;

    Game::gameChoice player;
    Game::gameChoice computer;

    if(argc > 1){isUnfair = true;}

    // G A M E P L A Y
    Printer::printChoices();
    std::cin >> std::setw(1) >> playerChar;
    
    player   = Game::getPlayerChoice(playerChar);
    computer = Game::getComputerChoice(isUnfair, player);

    Printer::printBanner(player, computer);

    Printer::printGameState(
        Game::evaluateWinCondition(player, computer)
    );
    return 0;

}
