#pragma once
#include "game.h"
#include <string>

class Printer
{
    public:        
        static void printBanner     (Game::gameChoice Player, Game::gameChoice Computer);
        static void printChoices    ();
        static void printGameState  (Game::gameState state);
};