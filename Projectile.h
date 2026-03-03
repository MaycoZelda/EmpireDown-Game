#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Entity.h"
#include "Game.h"
#include <cmath>

class Projectile : public Entity {
public:
    Projectile(float x, float y, float targetX, float targetY, float speed, int damage)
        : Entity(x, y, 10, 10, 1), damage(damage) {
        float dx = targetX - x;
        float dy = targetY - y;
        float dist = std::sqrt(dx * dx + dy * dy);
        vx = (dx / dist) * speed;
        vy = (dy / dist) * speed;
    }

    void update() override {
        x += vx;
        y += vy;
        // Se sair da tela, desativar
        if (x < 0 || x > Game::screenWidth || y < 0 || y > Game::screenHeight) {
            active = false;
        }
    }

    void render() override {
        SDL_Rect rect = { (int)x, (int)y, width, height };
        SDL_SetRenderDrawColor(Game::renderer, 255, 255, 0, 255); // Amarelo
        SDL_RenderFillRect(Game::renderer, &rect);
    }

    int getDamage() const { return damage; }

private:
    float vx, vy;
    int damage;
};

#endif
