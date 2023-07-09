#include "Game.h"
#include <SDL2/SDL_image.h>
#include <stdio.h>

Game::Game()
{
}

Game::~Game()
{
}

bool Game::Init(const char *title, int xpos, int ypos, int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("SDL could not initialize. SDL error: %s\n", SDL_GetError());
        return false;
    }
    if (NULL == (window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN)))
    {
        printf("Window not created. SDL error: %s\n", SDL_GetError());
        return false;
    }
    if (NULL == (renderer = SDL_CreateRenderer(window, -1, 0)))
    {
        printf("Renderer not created. SDL error: %s\n", SDL_GetError());
        return false;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    playerTex = IMG_LoadTexture(renderer, "assets/dude.png");
    running = true;
    return true;
}

void Game::HandleEvents()
{
    SDL_Event e;
    SDL_PollEvent(&e);
    switch (e.type)
    {
    case SDL_QUIT:
        running = false;
        break;

    default:
        break;
    }
}

void Game::Update()
{
}

void Game::Render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, playerTex, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void Game::Quit()
{
    printf("Cleaning game...\n");
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
