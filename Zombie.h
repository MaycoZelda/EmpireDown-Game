#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Entity.h"

class Player;

class Zombie : public Entity {
public:
    Zombie(float x, float y, int hp, float speed, int damage);
    ~Zombie();

    void update() override;
    void render() override;
    
    void setTarget(Player* p) { target = p; }
    int getDamage() const { return damage; }

private:
    float speed;
    int damage;
    Player* target;
};

#endif
