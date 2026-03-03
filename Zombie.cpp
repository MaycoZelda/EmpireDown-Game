#include "Zombie.h"
#include "Player.h"
#include "Game.h"
#include <cmath>

Zombie::Zombie(float x, float y, int hp, float speed, int damage) 
    : Entity(x, y, 40, 40, hp), speed(speed), damage(damage), target(nullptr) {}

Zombie::~Zombie() {}

void Zombie::update() {
    if (target) {
        float dx = target->getX() - x;
        float dy = target->getY() - y;
        float dist = std::sqrt(dx * dx + dy * dy);

        if (dist > 5.0f) {
            x += (dx / dist) * speed;
            y += (dy / dist) * speed;
        }

        // Dano ao jogador se encostar
        if (dist < 30.0f) {
            target->takeDamage(damage);
        }
    }
}

void Zombie::render() {
    SDL_Rect rect = { (int)x, (int)y, width, height };
    SDL_SetRenderDrawColor(Game::renderer, 0, 255, 0, 255); // Verde
    SDL_RenderFillRect(Game::renderer, &rect);
}
