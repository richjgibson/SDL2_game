#include "Game.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{
    game = new Game();

    game->Init("WORKING_TITLE", 0, 0, 640, 480);

    while (game->gameRunning())
    {
        game->HandleEvents();
        game->Update();
        game->Render();
    }

    game->Quit();

    return 0;
}