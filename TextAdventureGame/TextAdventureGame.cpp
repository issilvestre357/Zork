

#include "Game.h"
#include <cstdlib>

int main()
{
    bool restartGame = true;

    while (restartGame)
    {
        std::system("cls");

        Game game;
        restartGame = game.start();
    }

    return 0;
}