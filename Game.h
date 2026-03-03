#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <vector>
#include <memory>

class Player;
class Zombie;
class WaveManager;

class Game {
public:
    Game();
    ~Game();

    bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; }

    static SDL_Renderer* renderer;
    static int screenWidth;
    static int screenHeight;

private:
    bool isRunning;
    SDL_Window* window;
    
    std::unique_ptr<Player> player;
    std::unique_ptr<WaveManager> waveManager;
};

#endif
