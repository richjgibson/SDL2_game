#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

const char *TITLE{"LazyFoo tutorial 8"};
const int WIDTH{640};
const int HEIGHT{480};

SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;
SDL_Texture *gTexture = NULL;

bool init();
SDL_Texture *loadTexture(std::string pathname);
bool loadMedia();
void quit();

bool init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("SDL could not initialize: %s\n", SDL_GetError());
        return false;
    }
    if (NULL == (gWindow = SDL_CreateWindow(TITLE, 0, 0, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
    {
        printf("Window could not be created: %s\n", SDL_GetError());
        return false;
    }
    if (NULL == (gRenderer = SDL_CreateRenderer(gWindow, -1, 0)))
    {
        printf("Window could not be created: %s\n", SDL_GetError());
        return false;
    }
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 0);
    return true;
}

SDL_Texture *loadTexture(std::string pathname)
{
    SDL_Texture *loadedTexture = NULL;
    if (NULL == (loadedTexture = IMG_LoadTexture(gRenderer, pathname.c_str())))
    {
        printf("Texture could not be loaded: %s\n", SDL_GetError());
        return {};
    }
    return loadedTexture;
}

bool loadMedia()
{
    return true;
}

void quit()
{
    SDL_DestroyTexture(gTexture);
    gTexture = NULL;
    SDL_DestroyRenderer(gRenderer);
    gRenderer = NULL;
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    SDL_Quit();
}

int main(int argc, char *argv[])
{
    if (init())
    {
        if (loadMedia())
        {
            SDL_Rect fillRect{0, 0, 200, 200};
            SDL_Rect drawRect{150, 150, 200, 200};
            SDL_Event e;
            bool running = true;
            while (running)
            {
                if (SDL_PollEvent(&e) > 0)
                {
                    if (e.type == SDL_QUIT)
                    {
                        running = false;
                    }
                    if (e.type == SDL_KEYDOWN)
                    {
                        switch (e.key.keysym.sym)
                        {
                        case SDLK_UP:
                            printf("Keystrokes work!");
                            running = false;
                            break;

                        default:
                            break;
                        }
                    }
                    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 0);
                    SDL_RenderClear(gRenderer);

                    SDL_SetRenderDrawColor(gRenderer, 0, 255, 255, 0);
                    SDL_RenderFillRect(gRenderer, &drawRect);

                    SDL_SetRenderDrawColor(gRenderer, 255, 0, 255, 0);
                    SDL_RenderFillRect(gRenderer, &fillRect);

                    SDL_RenderPresent(gRenderer);
                }
            }
        }
    }
    quit();
    return 0;
}