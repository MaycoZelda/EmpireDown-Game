#include "Player.h"
#include "Game.h"
#include "Projectile.h"
#include <cmath>
#include <algorithm>


Player::Player(float x, float y) 
    : Entity(x, y, 40, 40, 100), speed(4.0f), kills(0), wave(1), ammo(30), maxAmmo(30), 
      shootCooldown(15), currentCooldown(0) {}

Player::~Player() {}

void Player::update() {
    // Progressão de Armas Baseada na Wave
    if (wave >= 10) {
        shootCooldown = 5; // Metralhadora pesada
        maxAmmo = 100;
    } else if (wave >= 5) {
        shootCooldown = 10; // Rifle de assalto
        maxAmmo = 50;
    } else {
        shootCooldown = 15; // Pistola padrão
        maxAmmo = 30;
    }

    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_W]) y -= speed;
    if (state[SDL_SCANCODE_S]) y += speed;
    if (state[SDL_SCANCODE_A]) x -= speed;
    if (state[SDL_SCANCODE_D]) x += speed;

    // Limites da tela
    x = std::max(0.0f, std::min(x, (float)Game::screenWidth - width));
    y = std::max(0.0f, std::min(y, (float)Game::screenHeight - height));

    if (currentCooldown > 0) currentCooldown--;

    // Tiro automático se o mouse estiver pressionado
    int mx, my;
    Uint32 buttons = SDL_GetMouseState(&mx, &my);
    if ((buttons & SDL_BUTTON(SDL_BUTTON_LEFT)) && currentCooldown == 0 && ammo > 0) {
        shoot(mx, my);
        currentCooldown = shootCooldown;
        ammo--;
    }

    // Recarregar se pressionar R
    if (state[SDL_SCANCODE_R] && ammo < maxAmmo) {
        ammo = maxAmmo; // Recarga instantânea por enquanto
    }

    // Atualizar projéteis
    for (auto it = projectiles.begin(); it != projectiles.end();) {
        (*it)->update();
        if (!(*it)->isActive()) {
            it = projectiles.erase(it);
        } else {
            ++it;
        }
    }
}

void Player::render() {
    SDL_Rect rect = { (int)x, (int)y, width, height };
    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 255, 255); // Azul
    SDL_RenderFillRect(Game::renderer, &rect);

    for (auto& p : projectiles) {
        p->render();
    }
}

void Player::shoot(int targetX, int targetY) {
    projectiles.push_back(std::make_unique<Projectile>(x + width / 2, y + height / 2, targetX, targetY, 8.0f, 25));
}
