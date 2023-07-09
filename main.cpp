#include "Game.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{
    const int FPS = 60;
    const int FRAMEDELAY = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();

    game->Init("WORKING_TITLE", 0, 0, 640, 480);

    while (game->gameRunning())
    {
        frameStart = SDL_GetTicks();

        game->HandleEvents();
        game->Update();
        game->Render();

        frameTime = SDL_GetTicks() - frameStart;

        if (FRAMEDELAY > frameTime)
        {
            SDL_Delay(FRAMEDELAY - frameTime);
        }
    }

    game->Quit();

    return 0;
}