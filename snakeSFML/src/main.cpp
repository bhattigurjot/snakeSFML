// #include <iostream>
#include "Game.h"

int main()
{
    Game game;
    while(game.IsGameRunning())
    {
        game.HandleInput();
        game.Update();
        game.Render();
    }
    // std::cout << "Press ENTER to continue.." << std::endl;
    // std::cin.ignore();
    return 0;
}