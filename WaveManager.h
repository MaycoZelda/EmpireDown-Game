#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

#include <vector>
#include <memory>

class Zombie;
class Player;

class WaveManager {
public:
    WaveManager(Player* player);
    ~WaveManager();

    void update();
    void render();

    int getCurrentWave() const { return currentWave; }
    void nextWave();

private:
    void spawnZombie();

    int currentWave;
    int zombiesRemaining;
    int zombiesToSpawn;
    int spawnTimer;
    int spawnInterval;

    Player* player;
    std::vector<std::unique_ptr<Zombie>> zombies;
};

#endif
