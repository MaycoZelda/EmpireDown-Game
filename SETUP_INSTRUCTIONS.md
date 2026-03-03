# Instruções de Configuração e Execução do Jogo Zombie Survival 2D

Este documento detalha os passos necessários para configurar o ambiente de desenvolvimento, compilar e executar o jogo Zombie Survival 2D no Visual Studio no Windows.

## Pré-requisitos

Antes de começar, certifique-se de ter os seguintes softwares instalados:

1.  **Visual Studio 2022 (ou superior)**: A edição Community é gratuita e pode ser baixada do site oficial da Microsoft. Certifique-se de instalar os componentes de "Desenvolvimento para desktop com C++".
2.  **CMake**: Uma ferramenta de código aberto para gerenciar o processo de construção de software de forma independente de plataforma. Baixe e instale a versão mais recente do [site oficial do CMake](https://cmake.org/download/).
3.  **SDL2 Development Libraries**: As bibliotecas de desenvolvimento do SDL2 para Visual C++. Você precisará do SDL2, SDL2_image e SDL2_ttf.

## Instalação do SDL2

Siga os passos abaixo para instalar as bibliotecas SDL2:

1.  **Baixe as bibliotecas**: Acesse o [site oficial do SDL](https://www.libsdl.org/download-2.0.php) e baixe os seguintes pacotes para **Visual C++**:
    *   `SDL2-devel-2.x.x-vc.zip` (Runtime Libraries)
    *   `SDL2_image-devel-2.x.x-vc.zip` (SDL_image)
    *   `SDL2_ttf-devel-2.x.x-vc.zip` (SDL_ttf)

2.  **Extraia os arquivos**: Crie uma pasta no seu disco rígido, por exemplo, `C:\SDL2`. Extraia o conteúdo de cada arquivo `.zip` baixado para dentro desta pasta. Você deve ter uma estrutura similar a:
    ```
    C:\SDL2\
    ├── SDL2-2.x.x\
    │   ├── include\
    │   └── lib\
    ├── SDL2_image-2.x.x\
    │   ├── include\
    │   └── lib\
    └── SDL2_ttf-2.x.x\
        ├── include\
        └── lib\
    ```

3.  **Configure a variável de ambiente `SDL2DIR`**: Esta variável é crucial para que o CMake encontre as bibliotecas SDL2. Defina `SDL2DIR` para o diretório base onde você extraiu o SDL2 (e.g., `C:\SDL2`).
    *   No Windows, pesquise por "Variáveis de Ambiente" no menu Iniciar.
    *   Clique em "Editar as variáveis de ambiente do sistema".
    *   Na janela "Propriedades do Sistema", clique em "Variáveis de Ambiente...".
    *   Na seção "Variáveis do sistema", clique em "Nova...".
    *   Para "Nome da variável", digite `SDL2DIR`.
    *   Para "Valor da variável", digite o caminho para a sua pasta SDL2 (e.g., `C:\SDL2`).
    *   Clique em OK em todas as janelas para salvar as alterações.

## Gerando o Projeto Visual Studio com CMake

1.  **Abra o Prompt de Comando ou PowerShell**: Navegue até o diretório raiz do projeto `zombie_game` que você baixou.

2.  **Crie um diretório de build**: É uma boa prática compilar fora da árvore de código-fonte.
    ```bash
    mkdir build
    cd build
    ```

3.  **Execute o CMake**: O CMake irá ler o arquivo `CMakeLists.txt` e gerar os arquivos de projeto do Visual Studio.
    ```bash
    cmake .. -G "Visual Studio 17 2022" -A x64
    ```
    *   `..`: Indica que o `CMakeLists.txt` está no diretório pai.
    *   `-G "Visual Studio 17 2022"`: Especifica o gerador para Visual Studio 2022. Se você estiver usando uma versão diferente, ajuste o número (e.g., `Visual Studio 16 2019`).
    *   `-A x64`: Especifica a arquitetura da plataforma (64-bit).

    Se o CMake for executado com sucesso, ele criará um arquivo de solução (`.sln`) e outros arquivos de projeto dentro do diretório `build`.

## Compilando e Executando no Visual Studio

1.  **Abra a Solução**: No diretório `build`, localize e abra o arquivo `ZombieSurvival2D.sln` com o Visual Studio.

2.  **Configure a Plataforma**: No Visual Studio, certifique-se de que a plataforma de solução esteja definida para `x64` (ou a que você usou no CMake).

3.  **Copie as DLLs do SDL2**: Para que o executável do jogo funcione, as DLLs do SDL2 precisam estar acessíveis. Copie os arquivos `.dll` das pastas `C:\SDL2\SDL2-2.x.x\lib\x64`, `C:\SDL2\SDL2_image-2.x.x\lib\x64` e `C:\SDL2\SDL2_ttf-2.x.x\lib\x64` (ou `x86` se você estiver compilando para 32-bit) para o diretório onde o executável do seu jogo será gerado (geralmente `build\Debug` ou `build\Release`).

4.  **Compile o Projeto**: No Visual Studio, vá em `Compilar > Compilar Solução` (ou pressione `Ctrl+Shift+B`).

5.  **Execute o Jogo**: Após a compilação bem-sucedida, você pode executar o jogo indo em `Depurar > Iniciar Depuração` (ou pressionando `F5`).

Agora você deve ver a janela do jogo 2D com o jogador azul, zumbis verdes e a barra de vida/munição no canto superior esquerdo. Use `W, A, S, D` para mover e o botão esquerdo do mouse para atirar. Pressione `R` para recarregar.
