#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>

class Entity {
public:
    Entity(float x, float y, int width, int height, int hp) 
        : x(x), y(y), width(width), height(height), hp(hp), maxHp(hp), active(true) {}
    virtual ~Entity() {}

    virtual void update() = 0;
    virtual void render() = 0;

    float getX() const { return x; }
    float getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int getHP() const { return hp; }
    bool isActive() const { return active; }

    void takeDamage(int amount) {
        hp -= amount;
        if (hp <= 0) {
            hp = 0;
            active = false;
        }
    }

protected:
    float x, y;
    int width, height;
    int hp, maxHp;
    bool active;
};

#endif
