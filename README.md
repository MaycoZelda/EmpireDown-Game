# Mata Mata Survival 2D

## Visão Geral
Meu primeiro jogo simples foi desenvolvido com bastante apoio de ferramentas de IA, combinando aprendizado e modificaçoes manuais. Ainda há muito a ser feito, mas cada etapa representa um avanço importante nesse processo. ainda nao é um jogo de zumbiu precisa dos modelos bot,armar,fundo... Esta bem cru.

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
- Visual Studio 2022.

## 📥 Instalação e Configuração do Ambiente

### 1. Baixar SDL2 e extensões
- Baixe os pacotes de desenvolvimento do **SDL2**, **SDL2_image** e **SDL2_ttf** (versões usadas neste projeto: 2.32.10, 2.8.8 e 2.24.0).
- Extraia cada pacote em uma pasta dentro de `C:\SDL2\`, por exemplo:
    C:\SDL2\SDL2-2.32.10
    C:\SDL2\SDL2_image-2.8.8
    C:\SDL2\SDL2_ttf-2.24.0

Cada pasta deve conter:
- `include\` → cabeçalhos (`SDL.h`, `SDL_image.h`, `SDL_ttf.h`)
- `lib\x64\` → bibliotecas (`.lib`) e DLLs necessárias.

---

### 2. Configurar o projeto com CMake
1. Crie uma pasta de build:
 ```powershell
 mkdir build
 cd build
```
 2. gere a solucao
    ```
    cmake .. -G "Visual Studio 18 2026" -A x64
  3. Abra o arquivo ZombieSurvival2D.slnx no Visual Studio.
     
### 3. Compilar
No Visual Studio, selecione Debug x64 ou Release x64.

Compile o projeto normalmente.

### 4. Copiar as DLLs para execução
  Para rodar o jogo sem erro de “DLL missing”, copie para pasta release e debug:
    
    SDL2.dll

    SDL2_image.dll

    SDL2_ttf.dll
    
  <img width="812" height="625" alt="scrrenshot" src="https://github.com/user-attachments/assets/58285a30-b486-49af-93a0-ef2f42ab3b57" />

  <img width="801" height="627" alt="screenshot2" src="https://github.com/user-attachments/assets/06692ff8-856d-4a2c-b637-2debceb15b4b" />

 

