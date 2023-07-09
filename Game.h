#include <SDL2/SDL.h>

class Game
{
private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Texture *playerTex = nullptr;
    bool running;

public:
    Game();
    ~Game();
    bool Init(const char *title, int xpos, int ypos, int width, int height);
    void HandleEvents();
    void Update();
    void Render();
    void Quit();
    bool gameRunning() { return running; }
};