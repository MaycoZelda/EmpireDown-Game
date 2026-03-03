# Zombie Survival 2D (Estilo CoD Zombies)

## Visão Geral
Um jogo de sobrevivência contra hordas de zumbis em 2D, escrito em C++ usando a biblioteca SDL2. O jogo aumenta a dificuldade a cada horda, com mais zumbis e inimigos mais resistentes, enquanto o jogador desbloqueia novas armas.

## Estrutura do Projeto
- `main.cpp`: Ponto de entrada.
- `Game.h / Game.cpp`: Loop principal, renderização e eventos.
- `Player.h / Player.cpp`: Classe do jogador.
- `Zombie.h / Zombie.cpp`: Classe dos inimigos.
- `Weapon.h / Weapon.cpp`: Sistema de armas e projéteis.
- `WaveManager.h / WaveManager.cpp`: Lógica das hordas.
- `UI.h / UI.cpp`: Interface do usuário.

## Tecnologias
- C++17 ou superior.
- SDL2 (Core, Image, TTF).
- Visual Studio 2022 (recomendado).
