#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <vector>
#include <memory>

class Projectile;

class Player : public Entity {
public:
    Player(float x, float y);
    ~Player();

    void update() override;
    void render() override;
    void handleEvents();

    void shoot(int targetX, int targetY);

    std::vector<std::unique_ptr<Projectile>>& getProjectiles() { return projectiles; }

    int getKills() const { return kills; }
    void addKill() { kills++; }

    int getWave() const { return wave; }
    void setWave(int w) { wave = w; }

    int getAmmo() const { return ammo; }
    void setAmmo(int a) { ammo = a; }

private:
    float speed;
    int kills;
    int wave;
    int ammo;
    int maxAmmo;
    int shootCooldown;
    int currentCooldown;

    std::vector<std::unique_ptr<Projectile>> projectiles;
};

#endif
