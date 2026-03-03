#include "Game.h"
#include "Player.h"
#include "WaveManager.h"
#include <iostream>

SDL_Renderer* Game::renderer = nullptr;
int Game::screenWidth = 0;
int Game::screenHeight = 0;

Game::Game() : isRunning(false), window(nullptr) {}

Game::~Game() {
    clean();
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialized!..." << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            std::cout << "Renderer created!" << std::endl;
        }

        isRunning = true;
        screenWidth = width;
        screenHeight = height;
    } else {
        isRunning = false;
        return false;
    }

    player = std::make_unique<Player>(width / 2, height / 2);
    waveManager = std::make_unique<WaveManager>(player.get());

    return true;
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    if (player && player->isActive()) {
        player->update();
        waveManager->update();
    } else {
        // Game Over
        isRunning = false;
        std::cout << "Game Over! Kills: " << player->getKills() << " Wave: " << player->getWave() << std::endl;
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255); // Fundo escuro
    SDL_RenderClear(renderer);
    
    if (player) {
        player->render();
        
        // Render HUD (Vida e Munição)
        // Barra de Vida
        SDL_Rect healthBg = { 20, 20, 200, 20 };
        SDL_SetRenderDrawColor(renderer, 50, 0, 0, 255);
        SDL_RenderFillRect(renderer, &healthBg);

        float healthPercent = (float)player->getHP() / 100.0f;
        SDL_Rect healthBar = { 20, 20, (int)(200 * healthPercent), 20 };
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &healthBar);

        // Barra de Munição
        SDL_Rect ammoBg = { 20, 50, 200, 10 };
        SDL_SetRenderDrawColor(renderer, 50, 50, 0, 255);
        SDL_RenderFillRect(renderer, &ammoBg);

        float ammoPercent = (float)player->getAmmo() / 30.0f; // Ajustar conforme arma
        SDL_Rect ammoBar = { 20, 50, (int)(200 * ammoPercent), 10 };
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_RenderFillRect(renderer, &ammoBar);
    }
    
    if (waveManager) {
        waveManager->render();
    }
    
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}
