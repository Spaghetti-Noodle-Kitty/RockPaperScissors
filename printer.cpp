#include "printer.h"
#include <iostream>

// Private variables
std::string colorRed = "\033[31m";
std::string colorGrn = "\033[32m";
std::string colorBlu = "\033[36m";
std::string colorYlw = "\033[33m";
std::string colorPrp = "\033[35m";
std::string colorRes = "\033[0m";


// Public methods
void Printer::printBanner(Game::gameChoice Player, Game::gameChoice Computer)
{
    std::cout << "You chose [" << colorBlu << Game::getHumanReadable(Player) << colorRes << "]\r\n";
    std::cout << "PC chose  [" << colorPrp << Game::getHumanReadable(Computer) << colorRes << "]\r\n\r\n";
}

void Printer::printChoices()
{
    std::cout << colorBlu << "Choose:\r\n[R]ock\r\n[P]aper\r\n[S]cissors\r\n" << colorRes << ">";
}

void Printer::printGameState(Game::gameState gS)
{
    if(gS == Game::gameState::Win)
        std::cout << colorGrn << "!! You win\r\n\r\n" << colorRes << std::endl;
    else if (gS == Game::gameState::Tie)
        std::cout << colorYlw << "!! You tied\r\n\r\n" << colorRes << std::endl;
    else if (gS == Game::gameState::Loss)
        std::cout << colorRed << "!! You lost\r\n\r\n" << colorRes << std::endl;

}