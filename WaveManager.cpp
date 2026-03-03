#include "WaveManager.h"
#include "Zombie.h"
#include "Player.h"
#include "Projectile.h"
#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

WaveManager::WaveManager(Player* player) 
    : currentWave(1), zombiesRemaining(0), zombiesToSpawn(5), spawnTimer(0), 
      spawnInterval(120), player(player) {
    std::srand(std::time(0));
}

WaveManager::~WaveManager() {}

void WaveManager::update() {
    // Se não houver zumbis na tela e todos os da horda foram spawnados, ir para a próxima wave
    if (zombiesRemaining == 0 && zombiesToSpawn == 0) {
        nextWave();
    }

    // Spawnar zumbis em intervalos
    if (zombiesToSpawn > 0) {
        spawnTimer++;
        if (spawnTimer >= spawnInterval) {
            spawnZombie();
            spawnTimer = 0;
            zombiesToSpawn--;
            zombiesRemaining++;
        }
    }

    // Atualizar zumbis e verificar colisões com projéteis
    for (auto it = zombies.begin(); it != zombies.end();) {
        (*it)->update();

        // Verificar colisões com tiros do player
        for (auto& p : player->getProjectiles()) {
            if (p->isActive()) {
                // Colisão simples por retângulo
                float dx = (*it)->getX() - p->getX();
                float dy = (*it)->getY() - p->getY();
                if (std::abs(dx) < 30 && std::abs(dy) < 30) {
                    (*it)->takeDamage(25); // Dano do tiro
                    p->takeDamage(1); // Desativa o projétil
                }
            }
        }

        if (!(*it)->isActive()) {
            it = zombies.erase(it);
            zombiesRemaining--;
            player->addKill();
        } else {
            ++it;
        }
    }
}

void WaveManager::render() {
    for (auto& z : zombies) {
        z->render();
    }
}

void WaveManager::nextWave() {
    currentWave++;
    player->setWave(currentWave);
    zombiesToSpawn = 5 + (currentWave * 3); // Mais zumbis por horda
    spawnInterval = std::max(30, 120 - (currentWave * 5)); // Spawns mais rápidos
    std::cout << "Wave " << currentWave << " Iniciada!" << std::endl;
}

void WaveManager::spawnZombie() {
    float x, y;
    int side = std::rand() % 4;
    switch (side) {
        case 0: x = -50; y = std::rand() % Game::screenHeight; break; // Esquerda
        case 1: x = Game::screenWidth + 50; y = std::rand() % Game::screenHeight; break; // Direita
        case 2: x = std::rand() % Game::screenWidth; y = -50; break; // Cima
        case 3: x = std::rand() % Game::screenWidth; y = Game::screenHeight + 50; break; // Baixo
    }

    // Dificuldade aumenta com a wave
    int hp = 50 + (currentWave * 10);
    float speed = 1.0f + (currentWave * 0.1f);
    int damage = 5 + (currentWave / 2);

    auto z = std::make_unique<Zombie>(x, y, hp, speed, damage);
    z->setTarget(player);
    zombies.push_back(std::move(z));
}
