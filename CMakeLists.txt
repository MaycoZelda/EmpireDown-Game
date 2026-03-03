cmake_minimum_required(VERSION 3.10)

project(ZombieSurvival2D CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Definir caminhos manualmente
include_directories(
    "C:/SDL2/SDL2-2.32.10/include"
    "C:/SDL2/SDL2_image-2.8.8/include"
    "C:/SDL2/SDL2_ttf-2.24.0/include"
)

link_directories(
    "C:/SDL2/SDL2-2.32.10/lib/x64"
    "C:/SDL2/SDL2_image-2.8.8/lib/x64"
    "C:/SDL2/SDL2_ttf-2.24.0/lib/x64"
)

# Adicionar executável
add_executable(ZombieSurvival2D 
    main.cpp
    Game.cpp
    Player.cpp
    Zombie.cpp
    WaveManager.cpp
)

# Linkar libs manualmente
target_link_libraries(ZombieSurvival2D 
    SDL2
    SDL2main
    SDL2_image
    SDL2_ttf
)
